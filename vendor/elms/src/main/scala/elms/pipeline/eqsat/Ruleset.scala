package elms.pipeline.eqsat

import scala.collection.mutable

import foresight.eqsat.{EClassCall, MixedTree}
import foresight.eqsat.readonly
import foresight.eqsat.rewriting
import foresight.eqsat.rewriting.patterns.{Pattern as FPattern, PatternMatch}

import elms.core.Op
import elms.core.instances.given

enum Pattern {
  case Var(name: String)
  case Node(op: Op.Pure, children: Vector[Pattern])
}

object Pattern {
  def render(p: Pattern): String = p match {
    case Var(name)               => s"?$name"
    case Node(op, Vector())      => op.toString
    case Node(op, children)      => s"$op(${children.map(render).mkString(", ")})"
  }
}

abstract class Rule private (
    val lhs: Pattern,
    val rhs: Pattern,
    val symmetric: Boolean
) {
  private[eqsat] def compile: Seq[Ruleset.Compiled] =
    if symmetric then Seq(Rule.directed(lhs, rhs), Rule.directed(rhs, lhs))
    else Seq(Rule.directed(lhs, rhs))
}

object Rule {
  private case class Rewrite(lhsp: Pattern, rhsp: Pattern)
      extends Rule(lhsp, rhsp, false)
  private case class Equivalence(lhsp: Pattern, rhsp: Pattern)
      extends Rule(lhsp, rhsp, true)

  def rewrite(lhs: Pattern, rhs: Pattern): Rule = Rewrite(lhs, rhs)
  def equivalence(lhs: Pattern, rhs: Pattern): Rule = Equivalence(lhs, rhs)

  // ELMS names its pattern variables with strings and foresight with identity, so
  // one `FPattern.Var` per name per rule. The left side is compiled first: every
  // name the right side mentions has to have been bound there.
  private def directed(lhs: Pattern, rhs: Pattern): Ruleset.Compiled = {
    val vars = mutable.Map.empty[String, FPattern.Var]

    def go(p: Pattern): MixedTree[ElmsNode, FPattern.Var] = p match {
      case Pattern.Var(name) => MixedTree
          .Atom(vars.getOrElseUpdate(name, FPattern.Var.fresh()))
      case Pattern.Node(op, children) =>
        MixedTree.unslotted(ElmsNode.Pure(op), children.map(go))
    }

    val searcher = go(lhs)
    val bound = vars.keySet.toSet
    val applier = go(rhs)

    require(
      vars.keySet.subsetOf(bound),
      s"unbound pattern variables in ${Pattern.render(rhs)}: " +
        (vars.keySet -- bound).mkString(", ")
    )

    rewriting.Rule(
      s"${Pattern.render(lhs)} => ${Pattern.render(rhs)}",
      searcher.toSearcher[Ruleset.Graph],
      applier.toApplier[Ruleset.Graph]
    )
  }
}

object Ruleset {
  // Rules are written against the plainest graph type that supports them, and
  // `Rewrite` is contravariant in it, so they still apply to the mutable graph
  // `EGraph` actually holds. Metadata is in the bound because constant folding
  // reads `ConstantAnalysis` off the graph it is matching against.
  type Graph = readonly.EGraphWithMetadata[ElmsNode, readonly.EGraph[ElmsNode]]
  type Compiled = rewriting.Rule[ElmsNode, PatternMatch[ElmsNode], Graph]

  // Not expressible in `Pattern`: the replacement is computed, not matched. Every
  // class the analysis has a value for gets that value as a member, which is what
  // lets the rest of the rules fire on folded results.
  val constantFold: Compiled = {
    val x = FPattern.Var.fresh()
    val atom = MixedTree.Atom[ElmsNode, FPattern.Var](x)

    rewriting.Rule(
      "constant-fold",
      atom.toSearcher[Graph].flatMap { (subst, egraph) =>
        ConstantAnalysis.get(egraph)(subst(x), egraph).toSeq.map { c =>
          val folded = MixedTree
            .unslotted[ElmsNode, EClassCall](ElmsNode.Pure(c), Seq())
          subst.bind(x, folded)
        }
      },
      atom.toApplier[Graph]
    )
  }

  private def isConstant(
      m: PatternMatch[ElmsNode],
      v: FPattern.Var,
      egraph: Graph
  ): Boolean = ConstantAnalysis.get(egraph)(m(v), egraph).isDefined

  /** `(a op c1) op c2  ->  a op (c1 op c2)`, only where both `c`s are constants.
    *
    * Dragging constants next to each other so `constantFold` can collapse them is
    * the one thing free associativity was buying. Spelling out just that case
    * costs a rule per shape and never manufactures an e-class the way the general
    * rule does.
    */
  def collectConstants(op: Op.Pure): Seq[Compiled] = {
    val a = MixedTree.Atom[ElmsNode, FPattern.Var](FPattern.Var.fresh())
    val c1 = FPattern.Var.fresh()
    val c2 = FPattern.Var.fresh()

    def node(
        l: MixedTree[ElmsNode, FPattern.Var],
        r: MixedTree[ElmsNode, FPattern.Var]
    ) = MixedTree.unslotted(ElmsNode.Pure(op), Seq(l, r))

    val pair = node(MixedTree.Atom(c1), MixedTree.Atom(c2))

    def rule(
        name: String,
        lhs: MixedTree[ElmsNode, FPattern.Var],
        rhs: MixedTree[ElmsNode, FPattern.Var]
    ) = rewriting.Rule(
      name,
      lhs.toSearcher[Graph]
        .filter((m, g) => isConstant(m, c1, g) && isConstant(m, c2, g)),
      rhs.toApplier[Graph]
    )

    Seq(
      // `(a op c1) op c2  ->  a op (c1 op c2)`. `a` stays on the left, because
      // without commutativity whichever side the applier picks is the only side
      // extraction will ever see.
      rule(
        s"collect-constants-after($op)",
        node(node(a, MixedTree.Atom(c1)), MixedTree.Atom(c2)),
        node(a, pair)
      ),
      // `(c1 op a) op c2  ->  (c1 op c2) op a`
      rule(
        s"collect-constants-before($op)",
        node(node(MixedTree.Atom(c1), a), MixedTree.Atom(c2)),
        node(pair, a)
      )
    )
  }
}

class Ruleset(ruleDecls: Seq[Rule], extra: Seq[Ruleset.Compiled] = Seq()) {
  // Names encode the rewrite, so this is the old dedup by `Set[Expansion]` and it
  // also satisfies foresight's requirement that rule names be unique.
  val compiled: Seq[Ruleset.Compiled] =
    (ruleDecls.flatMap(_.compile) ++ extra).distinctBy(_.name)
}
