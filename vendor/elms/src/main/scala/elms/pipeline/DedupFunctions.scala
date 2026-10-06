package elms.pipeline

import scala.collection.mutable

import elms.core.{Name, Op}
import elms.core.tree.*

// Merges top-level functions that came out the same.
//
// `Driver.makeFun` keys its memo on the serialized closure, and every closure
// instance serializes differently, so it only ever matches when the very same
// object is re-entered. That is the recursive case and nothing else: two
// `fun(twice)` calls in one body are two eta-expansions at two source sites,
// which is two lambda classes and two keys, so the same helper gets staged
// twice under two names.
//
// Comparing what came out instead catches those, and catches two spellings
// that happened to build the same body as well.
object DedupFunctions {
  def run(prog: Program): Program =
    Program(settle(prog.functions), prog.staticData)

  // One merge can make two other functions equal, because a caller's body is
  // only equal to its twin's once the two names they call have become one. So
  // keep merging until a round finds nothing.
  private def settle(fns: Seq[(Name, Function)]): Seq[(Name, Function)] =
    merge(fns) match {
      case Some(next) => settle(next)
      case None       => fns
    }

  private def merge(fns: Seq[(Name, Function)]): Option[Seq[(Name, Function)]] = {
    val seen = mutable.Map[Function, Name]()
    val alias = mutable.Map[Name, Name]()

    fns.foreach { (name, f) =>
      val shape = canonical(name, f)
      seen.get(shape) match {
        case Some(rep) => alias(name) = rep
        case None      => seen(shape) = name
      }
    }

    if alias.isEmpty then None
    else Some(
      fns.filterNot { (name, _) => alias.contains(name) }
        .map { (name, f) => (name, rename(f, alias.toMap)) }
    )
  }

  // Bound names replaced by their position, so two functions that differ only
  // in which numbers the counter handed out compare equal.
  //
  // The function's own name is free in its body, so it is bound here too.
  // Without that a recursive function and a copy of it would differ in exactly
  // one place: the name each one calls.
  private def canonical(self: Name, f: Function): Function = {
    var next = 0
    def fresh(): Name = {
      val n = Name.from(next)
      next += 1
      n
    }

    def notes(ns: Seq[Note], env: Map[Name, Name]): Seq[Note] =
      ns.map { n => n.copy(args = n.args.map(go(_, env))) }

    def fn(g: Function, env: Map[Name, Name]): Function = {
      val args = g.args.map { (_, ty) => (fresh(), ty) }
      val inner = env ++ g.args.map(_._1).zip(args.map(_._1))
      Function(args, g.outty, go(g.body, inner), notes(g.notes, inner))
    }

    // A name this walk did not bind is a reference out of the function, to
    // another top-level function or to static data, and has to stay as it is.
    def go(t: Term, env: Map[Name, Name]): Term = t match {
      case V(name)     => V(env.getOrElse(name, name))
      case g: Function => fn(g, env)

      // A note sits beside the binding rather than inside it, so its arguments
      // are read in the enclosing scope.
      case Let(x, e1, e2, ns) => {
        val bound = go(e1, env)
        val beside = notes(ns, env)
        val y = fresh()
        Let(y, bound, go(e2, env + (x -> y)), beside)
      }

      case E(Op.RangeForEach(x), Seq(st, end, body)) => {
        val from = go(st, env)
        val to = go(end, env)
        val y = fresh()
        E(Op.RangeForEach(y), Seq(from, to, go(body, env + (x -> y))))
      }

      case E(op, children) => E(op, children.map(go(_, env)))
    }

    fn(f, Map(self -> fresh()))
  }

  private def rename(f: Function, alias: Map[Name, Name]): Function = {
    def notes(ns: Seq[Note]): Seq[Note] = ns.map { n => n.copy(args = n.args.map(go)) }

    def go(t: Term): Term = t match {
      case V(name)            => V(alias.getOrElse(name, name))
      case Let(x, e1, e2, ns) => Let(x, go(e1), go(e2), notes(ns))
      case E(op, children)    => E(op, children.map(go))
      case g: Function        => Function(g.args, g.outty, go(g.body), notes(g.notes))
    }

    Function(f.args, f.outty, go(f.body), notes(f.notes))
  }
}
