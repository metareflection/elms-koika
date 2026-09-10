package elms.test

import org.scalatest.funsuite.AnyFunSuite

import foresight.eqsat.EClassCall

import elms.prelude.{_, given}
import elms.core.Name
import elms.core.Op.*
import elms.core.tree.*
import elms.pipeline.eqsat.*

import Pattern.{Var => PVar, Node => PNode}

class EqsatSuite extends AnyFunSuite {
  private def emptyGraph = new EGraph()

  private def v(name: String): Term = V(Name.from(name))

  private def extracted(g: EGraph, cls: EClassCall): Term = g.extract(cls)
    .getOrElse(fail("nothing extracted"))

  // `playground.scala`'s worked example: `y + (x + -y)`, and the rules that take
  // it down to `x`. These keep the free associativity and commutativity that
  // `Rules.default` deliberately drops, which is what makes this the set that can
  // run away.
  private val addcomm = Rule.equivalence(
    PNode(Plus, Vector(PVar("x"), PVar("y"))),
    PNode(Plus, Vector(PVar("y"), PVar("x")))
  )
  private val addassoc = Rule.equivalence(
    PNode(Plus, Vector(PVar("x"), PNode(Plus, Vector(PVar("y"), PVar("z"))))),
    PNode(Plus, Vector(PNode(Plus, Vector(PVar("x"), PVar("y"))), PVar("z")))
  )
  private val subnegate = Rule.equivalence(
    PNode(Plus, Vector(PVar("x"), PNode(Negate, Vector(PVar("y"))))),
    PNode(Minus, Vector(PVar("x"), PVar("y")))
  )
  private val subself = Rule
    .rewrite(PNode(Minus, Vector(PVar("x"), PVar("x"))), PNode(Const(0), Vector()))
  private val addzero = Rule
    .rewrite(PNode(Plus, Vector(PVar("x"), PNode(Const(0), Vector()))), PVar("x"))

  private val playground =
    Ruleset(Seq(addcomm, addassoc, subnegate, subself, addzero))

  test("structurally equal nodes hashcons to one class") {
    val g = emptyGraph
    val x = g.addNamedVar("x")
    val y = g.addNamedVar("y")

    assert(g.sameClass(g.addNamedVar("x"), x))
    assert(!g.sameClass(x, y))
    assert(g.sameClass(g.addNode(Plus, Seq(x, y)), g.addNode(Plus, Seq(x, y))))
    assert(!g.sameClass(g.addNode(Plus, Seq(x, y)), g.addNode(Plus, Seq(y, x))))
    assert(!g.sameClass(g.addNode(Plus, Seq(x, y)), g.addNode(Minus, Seq(x, y))))
  }

  test("a union closes congruence through nested nodes") {
    val g = emptyGraph
    val a = g.addNamedVar("a")
    val b = g.addNamedVar("b")

    def wrap(depth: Int, cls: EClassCall): EClassCall =
      if depth == 0 then cls else wrap(depth - 1, g.addNode(Negate, Seq(cls)))

    val nesteda = wrap(3, a)
    val nestedb = wrap(3, b)
    assert(!g.sameClass(nesteda, nestedb))

    g.union(a, b)
    assert(g.sameClass(nesteda, nestedb))
  }

  test("pattern variables bind in the order they appear") {
    val g = new EGraph(Ruleset(Seq(subnegate)))
    val x = g.addNamedVar("x")
    val y = g.addNamedVar("y")
    val term = g.addNode(Plus, Seq(x, g.addNode(Negate, Seq(y))))

    g.saturate()
    assert(extracted(g, term) == E(Minus, Seq(v("x"), v("y"))))
  }

  test("a repeated pattern variable only matches equal classes") {
    val g = new EGraph(Ruleset(Seq(subself)))
    val x = g.addNamedVar("x")
    val y = g.addNamedVar("y")
    val same = g.addNode(Minus, Seq(x, x))
    val different = g.addNode(Minus, Seq(x, y))

    g.saturate()
    assert(extracted(g, same) == E(Const(0), Seq()))
    assert(extracted(g, different) == E(Minus, Seq(v("x"), v("y"))))
  }

  test("extraction picks the smallest term in a class") {
    val g = emptyGraph
    val x = g.addNamedVar("x")
    val y = g.addNamedVar("y")

    val small = g.addNode(Plus, Seq(x, y))
    val big = g
      .addNode(Plus, Seq(x, g.addNode(Plus, Seq(y, g.addNode(Negate, Seq(x))))))

    g.union(big, small)
    assert(extracted(g, big) == E(Plus, Seq(v("x"), v("y"))))
  }

  test("a union refreshes extraction in the classes above it") {
    val g = new EGraph()
    val x = g.addNamedVar("x")
    val one = g.addNode(Const(1), Seq())
    val inner = g.addNode(Plus, Seq(one, one))
    val term = g.addNode(Plus, Seq(x, inner))

    g.union(inner, g.addNode(Const(2), Seq()))
    assert(extracted(g, term) == E(Plus, Seq(v("x"), E(Const(2), Seq()))))
  }

  test("saturation rewrites y + (x + -y) down to x") {
    val g = new EGraph(playground)
    val x = g.addNamedVar("x")
    val y = g.addNamedVar("y")
    val root = g
      .addNode(Plus, Seq(y, g.addNode(Plus, Seq(x, g.addNode(Negate, Seq(y))))))

    g.saturate()
    assert(extracted(g, root) == v("x"))

    // Commutativity and associativity together never run out of matches, so this
    // is the guard on backing rules off. Backed off it settles at 449 nodes;
    // applying every match every iteration takes it to 16927 and trips the cap.
    assert(g.nodeCount < 1000, s"saturation ran away: ${g.nodeCount} nodes")
  }

  test("constants fold with no rules in play") {
    val g = new EGraph()
    val sum = g
      .addNode(Plus, Seq(g.addNode(Const(2), Seq()), g.addNode(Const(3), Seq())))

    g.saturate()
    assert(extracted(g, sum) == E(Const(5), Seq()))
  }

  test("folding reaches through the algebraic rules") {
    val g = new EGraph(Rules.default)
    val x = g.addNamedVar("x")
    val one = g.addNode(Const(1), Seq())
    val term = g.addNode(Plus, Seq(g.addNode(Plus, Seq(x, one)), one))

    // `Ruleset.collectConstants` moves the two literals next to each other, and
    // only then is there a `1 + 1` for the analysis to fold.
    g.saturate()
    assert(extracted(g, term) == E(Plus, Seq(v("x"), E(Const(2), Seq()))))
  }

  test("bitwise identities collapse") {
    val g = new EGraph(Rules.default)
    val x = g.addNamedVar("x")
    val allOnes = g.addNode(Const(-1), Seq())

    val self = g.addNode(BitAnd, Seq(x, x))
    val saturated = g.addNode(BitOr, Seq(x, allOnes))
    val complement = g.addNode(BitXor, Seq(x, allOnes))
    val twice = g.addNode(BitNot, Seq(g.addNode(BitNot, Seq(x))))

    g.saturate()
    assert(extracted(g, self) == v("x"))
    assert(extracted(g, saturated) == E(Const(-1), Seq()))
    assert(extracted(g, complement) == E(BitNot, Seq(v("x"))))
    assert(extracted(g, twice) == v("x"))
  }

  test("bitwise constants fold") {
    val g = new EGraph()
    val mask = g
      .addNode(BitOr, Seq(g.addNode(Const(0xf0), Seq()), g.addNode(Const(0x0f), Seq())))
    val shifted = g.addNode(Shl, Seq(mask, g.addNode(Const(4), Seq())))

    g.saturate()
    assert(extracted(g, shifted) == E(Const(0xff0), Seq()))
  }

  // Scala masks a shift count to five bits and C leaves it undefined past the
  // width, so `ConstantAnalysis` declines the fold rather than pick a side.
  test("an out-of-range shift count does not fold") {
    val g = new EGraph(Rules.default)
    val term = g
      .addNode(Shl, Seq(g.addNode(Const(1), Seq()), g.addNode(Const(32), Seq())))

    g.saturate()
    assert(extracted(g, term) == E(Shl, Seq(E(Const(1), Seq()), E(Const(32), Seq()))))
  }

  test("eager boolean identities collapse") {
    val g = new EGraph(Rules.default)
    val b = g.addNamedVar("b")
    val tru = g.addNode(Const(true), Seq())

    val self = g.addNode(StrictAnd, Seq(b, b))
    val saturated = g.addNode(StrictOr, Seq(b, tru))
    val cleared = g.addNode(Xor, Seq(b, b))
    val negated = g.addNode(Xor, Seq(b, tru))
    val twice = g.addNode(Not, Seq(g.addNode(Not, Seq(b))))

    g.saturate()
    assert(extracted(g, self) == v("b"))
    assert(extracted(g, saturated) == E(Const(true), Seq()))
    assert(extracted(g, cleared) == E(Const(false), Seq()))
    assert(extracted(g, negated) == E(Not, Seq(v("b"))))
    assert(extracted(g, twice) == v("b"))
  }

  test("boolean constants fold") {
    val g = new EGraph()
    val term = g.addNode(
      Xor,
      Seq(
        g.addNode(StrictAnd, Seq(g.addNode(Const(true), Seq()), g.addNode(Const(false), Seq()))),
        g.addNode(Const(true), Seq())
      )
    )

    g.saturate()
    assert(extracted(g, term) == E(Const(true), Seq()))
  }

  test("saturation reaches a fixpoint under rules that could loop") {
    val g = new EGraph(Ruleset(Seq(addcomm, addassoc)))
    val x = g.addNamedVar("x")
    val y = g.addNamedVar("y")
    val z = g.addNamedVar("z")
    val root = g.addNode(Plus, Seq(x, g.addNode(Plus, Seq(y, z))))

    g.saturate()

    // Commutativity and associativity are both equivalences, so every
    // re-bracketing of `x + y + z` has to land in the root's class.
    val reassociated = g.addNode(Plus, Seq(g.addNode(Plus, Seq(z, y)), x))
    assert(g.sameClass(root, reassociated))
  }
}
