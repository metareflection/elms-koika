package elms.koika.test.common

import scala.collection.immutable.VectorMap

import elms.core.{Name, Op, STRUCT, StructRepr, Type, UNIT}
import elms.core.tree.{E, Function, Let, Note, Program, Term, V, View}

// The same product the squared interpreter builds, built the other way: by
// rewriting a residue after staging rather than by interpreting the program
// over a pair of states in the first place. Superseded, and kept because a
// second construction of the same thing is worth having on the day the two
// disagree. `sbt testFull` still stages it, and `verify --full` is what checks
// what it staged.
//
// Which branches to fuse is decided here by whether one happens to contain a
// slot call, and that is the difference worth knowing about. It is a proxy for
// "is this control flow" rather than the thing itself, and the interpreter
// says which it means instead of guessing.
//
// The residue run against two states at once, over one copy of the control
// flow, with the timers compared on entry to every slot.
//
// Self-composition emits the residue twice and compares the timers at the end,
// so a solver has to rule out every pair of paths. Here the paths are shared
// and each comparison is also an assumption, which is where the win is: a pair
// that has already drifted leaves the search instead of being enumerated and
// rejected.
//
// What that is worth depends entirely on how much of the bill the solver is
// holding, and it grows with the path space. Against the two-entry cache this
// predates, `branchy` at eighteen probes was 30.1s against 149.9s. Against the
// one in the tree now it is 1.47s against 1.31s at the four probes `branchy`
// ships, which is the wrong way round; the README has the rest of that story.
//
// It also has a precondition that is easy to lose: the two runs' addresses have
// to be provably equal. `Cached` writes a dirty line back at an index nobody
// knows, so anything reached through `mem` is a word nothing can prove the two
// runs still agree on, and an assumption about the timer buys nothing when the
// next address might differ. `branchy.s` keeps its indices in registers for
// exactly this reason, and an earlier draft that kept them in memory ran slower
// under this pass than under self-composition.
//
// Two levels make that precondition strictly easier rather than harder, which
// is worth knowing because the write is wider now: an eviction moves a whole
// line, but most evictions stop at L2 and never reach `mem` at all.
//
// The other cost is that a drift which later cancels out is reported as a leak.
// That used to be arithmetically out of reach, because every timer increment in
// a residue was `timer + <literal>`. A hierarchy charges `timer + <expression>`,
// since which level answered is a runtime fact, so cancellation is now a thing
// the pass could in principle report. Nothing in `src/out` does it.
object Lockstep {
  private val halves = Vector("a", "b")

  // Two [state]s, by pointer. `CCodegen` renders a `STRUCT` member as
  // `struct StateT *` and reaches every member with `->`, so `p->a->regs` is
  // what the backend already emits for a chain of two of these and the field
  // names on the far side never have to change.
  //
  // By pointer and not by value, so `main` can hand over the two states each
  // model's own `init` has already filled in.
  def pair(state: StructRepr): StructRepr = new StructRepr {
    val name: String = state.name + "2"
    val members: Map[String, Type] =
      halves.map(h => (h, STRUCT(state): Type)).to(VectorMap)
  }

  // [clock] is the member the two runs are compared on, and [prefix] is the one
  // `CCodegen` renders a generated name with. Nothing the pass emits is a
  // generated name, so [prefix] only decides how readable the output is.
  def run(state: StructRepr, clock: String = "timer", prefix: String = "v")(
      prog: Program
  ): Program = {
    val pass = Pass(state, clock, prefix)
    Program(prog.functions.map((n, f) => (n, pass.function(f))), prog.staticData)
  }

  // What one of the original program's names became. A slot call is the one
  // thing the two runs share, so its result is [Both]; everything else is a
  // value that each run has its own copy of.
  private enum Sided {
    case Both(t: Term)
    case Split(a: Term, b: Term)
  }

  private class Pass(state: StructRepr, clock: String, prefix: String) {
    import Sided.*

    val paired: StructRepr = pair(state)

    private type Env = Map[Name, Sided]

    private var checks = 0

    // Unit-typed, so `CCodegen` declares no variable for it and the name never
    // reaches the output. It still has to be distinct from every other binding.
    private def anon(): Name = { checks += 1; Name.from(s"_chk$checks") }

    private def renamed(n: Name, i: Int): Name =
      Name.from(n.render(prefix) + "_" + halves(i))
    private def shared(n: Name): Name = Name.from(n.render(prefix) + "_p")

    // The [i] half of the pair [s] points at.
    private def half(s: Term, i: Int): Term =
      E(Op.StructGet(paired, halves(i)), Seq(s))

    private def sideOf(s: Sided, i: Int): Term = s match {
      case Both(t)     => t
      case Split(a, b) => if (i == 0) a else b
    }

    private def bothOf(s: Sided): Term = s match {
      case Both(t) => t
      case Split(a, b) =>
        sys.error(s"lockstep: a slot call was handed a value that is not shared: $a")
    }

    private def retype(ty: Type): Type = ty match {
      case STRUCT(r) if r.name == state.name => STRUCT(paired)
      case _                                 => ty
    }

    private def hasApp(t: Term): Boolean = t match {
      case E(Op.App, _)   => true
      case E(_, cs)       => cs.exists(hasApp)
      case Let(_, e1, e2, _) => hasApp(e1) || hasApp(e2)
      case _              => false
    }

    private def assertAndAssume(cond: Term)(rest: Term): Term =
      Let(anon(), E(Op.Custom("lockstep_assert", UNIT), Seq(cond)),
        Let(anon(), E(Op.Custom("lockstep_assume", UNIT), Seq(cond)), rest, Seq()),
        Seq())

    private def clocksAgree(s: Term): Term = View.Equals(
      E(Op.StructGet(state, clock), Seq(half(s, 0))),
      E(Op.StructGet(state, clock), Seq(half(s, 1)))
    ).into

    // [t] with every name replaced by its [i] side. A field of [state] keeps
    // its name and gains a hop: whatever named the state now names the pair, so
    // the read goes through the half that belongs to this side.
    //
    // `StructSet` carries no repr, so this cannot check which struct is being
    // written. The residue has one, and a driver that grows a second has to
    // revisit this.
    private def project(env: Env, i: Int)(t: Term): Term = t match {
      case V(n) => env.get(n).map(sideOf(_, i)).getOrElse(V(n))

      case Let(x, e1, e2, notes) => {
        val y = renamed(x, i)
        Let(
          y,
          project(env, i)(e1),
          project(env + (x -> Split(V(y), V(y))), i)(e2),
          sided(env, i)(notes)
        )
      }

      case E(Op.StructGet(r, f), Seq(s)) if r.name == state.name =>
        E(Op.StructGet(state, f), Seq(half(project(env, i)(s), i)))

      case E(Op.StructSet(f), Seq(s, v)) =>
        E(Op.StructSet(f), Seq(half(project(env, i)(s), i), project(env, i)(v)))

      case E(Op.App, _) =>
        sys.error(s"lockstep: a slot call reached the per-side rewrite: $t")

      case E(op, cs) => E(op, cs.map(project(env, i)))

      case f: Function => sys.error(s"lockstep: nested function: $f")
    }

    // A note says something about the binding it rides on, so it goes wherever
    // that binding goes and names the same side of the pair.
    private def sided(env: Env, i: Int)(notes: Seq[Note]): Seq[Note] =
      notes.map(n => n.copy(args = n.args.map(project(env, i))))

    // [t] is a let-chain. [k] finishes the output once the chain's result is
    // known, which is what lets a binding emit two [Let]s where the original
    // had one.
    private def rewrite(env: Env)(t: Term)(k: Sided => Term): Term = t match {
      case Let(x, e1, e2, notes) if hasApp(e1) => {
        val y = shared(x)
        val next = rewrite(env + (x -> Both(V(y))))(e2)(k)
        // The binding is shared, so what is written about it has to be too. A
        // note naming a value the two runs disagree on fails here the same way
        // the call's own arguments do, and for the same reason.
        val kept = notes.map(n => n.copy(args = n.args.map(a => bothOf(atom(env)(a)))))
        e1 match {
          case E(Op.App, f +: args) =>
            Let(y, E(Op.App, f +: args.map(a => bothOf(atom(env)(a)))), next, kept)

          // A branch. Fusing it is only sound while the two runs agree on where
          // to go, which is what the assertion is for: this is the one place a
          // control-flow divergence has to be caught rather than left to the
          // timer.
          case E(Op.IfThenElse, Seq(c, th, el)) => {
            val ca = project(env, 0)(c)
            val cb = project(env, 1)(c)
            assertAndAssume(View.Equals(ca, cb).into) {
              Let(y, E(Op.IfThenElse, Seq(ca, arm(env)(th), arm(env)(el))), next, kept)
            }
          }

          case _ => sys.error(s"lockstep: a slot call in a shape nobody expected: $e1")
        }
      }

      case Let(x, e1, e2, notes) => {
        val (a, b) = (renamed(x, 0), renamed(x, 1))
        Let(a, project(env, 0)(e1),
          Let(b, project(env, 1)(e1),
            rewrite(env + (x -> Split(V(a), V(b))))(e2)(k),
            sided(env, 1)(notes)),
          sided(env, 0)(notes))
      }

      case other => k(atom(env)(other))
    }

    private def arm(env: Env)(t: Term): Term = rewrite(env)(t)(bothOf)

    // A chain's result, which is a name or a term with no binding left in it.
    private def atom(env: Env)(t: Term): Sided = t match {
      case V(n) => env.getOrElse(n, Both(V(n)))
      case _    => Split(project(env, 0)(t), project(env, 1)(t))
    }

    // The residue's slots take the state and nothing else, which is what makes
    // the one shared argument below sound. A second parameter would need its
    // own answer about whether the two runs agree on it, so it is rejected
    // here rather than guessed at.
    def function(f: Function): Function = {
      val (name, inty) = f.args match {
        case Seq(one) => one
        case other    => sys.error(s"lockstep: a slot taking ${other.length} arguments")
      }
      if f.notes.nonEmpty then
        sys.error("lockstep: a slot contract, which names a state that is now a pair")
      val arg = shared(name)
      val env: Env = Map(name -> Both(V(arg)))
      Function(
        Seq(arg -> retype(inty)),
        retype(f.outty),
        assertAndAssume(clocksAgree(V(arg)))(rewrite(env)(f.body)(bothOf)),
        Seq()
      )
    }
  }
}
