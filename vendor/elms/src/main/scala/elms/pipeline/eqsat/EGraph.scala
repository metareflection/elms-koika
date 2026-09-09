package elms.pipeline.eqsat

import foresight.eqsat.{EClassCall, EClassRef, ENode, Tree}
import foresight.eqsat.extraction.ExtractionAnalysis
import foresight.eqsat.mutable
import foresight.eqsat.parallel.ParallelMap
import foresight.eqsat.rewriting.patterns.PatternMatch
import foresight.eqsat.saturation.{BackoffRuleApplication, Strategy}

import elms.core.{Name, Op}
import elms.core.tree as ast
import elms.runtime.Log
import elms.util.CountOrInf, CountOrInf.*

import instances.given

class EGraph(
    val rules: Ruleset = Ruleset(Seq()),
    val cfg: EGraph.Config = EGraph.Config()
) {
  import EGraph.*

  private val graph: Graph = mutable.EGraphWithMetadata(mutable.EGraph.empty[ElmsNode])
  graph.addAnalysis(smallest)
  graph.addAnalysis(ConstantAnalysis)

  def addNode(op: Op.Pure, children: Seq[EClassCall]): EClassCall =
    graph.add(ENode.unslotted(ElmsNode.Pure(op), children))

  def addNamedVar(name: Name): EClassCall =
    graph.add(ENode.unslotted(ElmsNode.Var(name), Seq()))
  def addNamedVar(name: String): EClassCall = addNamedVar(Name.from(name))

  def union(a: EClassCall, b: EClassCall): Unit = { graph.unionMany(Seq((a, b))) }

  def sameClass(a: EClassCall, b: EClassCall): Boolean = graph.areSame(a, b)

  def nodeCount: Int = graph.nodeCount

  // An `EClassCall` is a call, not an id: the same class reached through two slot
  // maps gives two unequal calls, and any call held across a union is stale.
  // Anything keyed on class identity keys on this.
  def ref(cls: EClassCall): EClassRef = graph.canonicalize(cls).ref
  def canonical(cls: EClassCall): EClassCall = graph.canonicalize(cls)

  // A lookup rather than a fixpoint: `ExtractionAnalysis` keeps the best tree per
  // class up to date as metadata.
  def extract(cls: EClassCall): Option[ast.Term] =
    if !graph.contains(cls.ref) then None
    else Some(toTerm(extractor(graph.canonicalize(cls), graph)))

  def saturate(): Unit = { strategy(graph, ParallelMap.sequential) }

  def debugDump(): Unit =
    for cls <- graph.classes do {
      Log.debug(s"$cls: ")
      for node <- graph.nodes(graph.canonicalize(cls)) do Log.debug(s"  $node")
    }

  private def toTerm(t: Tree[ElmsNode]): ast.Term = t.nodeType match {
    case ElmsNode.Var(name) => ast.V(name)
    case ElmsNode.Pure(op)  => ast.E(op, t.args.map(toTerm))
  }

  private val strategy: Strategy[Graph, ?] = {
    val limit = cfg.maxIterations match {
      case Infinity => None
      case Count(n) => Some(n)
    }

    // Folding is part of the engine rather than something a caller opts into: it
    // is what makes the pattern rules fire on computed results.
    val all = Ruleset.constantFold +: rules.compiled

    // Backoff, not maximal application. Associativity and commutativity together
    // never stop finding matches, so applying every match every iteration grows
    // the graph without bound long after the useful rewrites have all fired.
    val base = BackoffRuleApplication.mutable[ElmsNode, Graph, PatternMatch[ElmsNode]](
      all,
      cfg.matchLimit,
      cfg.banLength
    )

    capped(base).withIterationLimit(limit).repeatUntilStable
  }

  // Foresight has no node cap, so this is where `Config.nodeCap` becomes a
  // stopping condition. `None` reads as "nothing changed", which is what makes
  // `repeatUntilStable` give up.
  private def capped[D](inner: Strategy[Graph, D]): Strategy[Graph, D] =
    new Strategy[Graph, D] {
      def initialData: D = inner.initialData

      def apply(g: Graph, data: D, par: ParallelMap): (Option[Graph], D) =
        if g.nodeCount >= cfg.nodeCap then {
          Log.warning(
            "size of equality graph exceeded during saturation, terminating early"
          )
          (None, data)
        }
        else inner(g, data, par)
    }
}

object EGraph {
  type Graph = mutable.EGraphWithMetadata[ElmsNode, mutable.EGraph[ElmsNode]]

  // `Term.size` exactly, which is what keeps stage-2 output byte-identical.
  private val smallest = ExtractionAnalysis.smallest[ElmsNode]
  private val extractor = smallest.extractor[mutable.EGraph[ElmsNode]]

  case class Config(
      maxIterations: CountOrInf = 100,
      nodeCap: CountOrInf = 10000,
      // Matches a rule may apply before it is banned, and for how many iterations.
      // Both double each time a banned rule comes back, so a rule that keeps
      // exploding is scheduled less and less often.
      matchLimit: Int = 1000,
      banLength: Int = 5
  )
}
