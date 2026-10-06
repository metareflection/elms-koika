package elms.helpers

import elms.core.{Driver, Typable}
import elms.core.tree as ast
import elms.pipeline, pipeline.simple
import elms.pipeline.eqsat, eqsat.Ruleset
import elms.pipeline.Propagate
import elms.codegen.{Backend, ScalaCodegen}
import elms.util.Plumbing.*
import elms.util.SourceContext
import elms.runtime.LMSUnsupportedException

abstract class SnippetDriver[A: Typable, B: Typable] extends Driver {
  val codegen: Backend

  def snippet(x: Rep[A]): Rep[B]

  // The only place that holds both a `Driver` and a `Backend`, so the only
  // place the two can be compared. Refusing here rather than in the backend is
  // what buys the source location: by the time a `Function` term reaches
  // `CCodegen` the line that wrote it is gone and only `Fresh(2)` is left.
  override def lam[X: Typable, Y: Typable](f: Rep[X] => Rep[Y])(using
      ctx: SourceContext
  ): Rep[X => Y] =
    if codegen.supportsLambdas then super.lam(f)
    else throw LMSUnsupportedException(
      s"${ctx.render(2)}: `lam` has no representation in this backend; give " +
        "the function a name with `fun` so it becomes a top-level function"
    )

  def code: String = {
    fun[A, B]("snippet") { x => snippet(x) }
    codegen.render(extract())
  }
}

abstract class SimpleSnippetDriver[A: Typable, B: Typable] extends SnippetDriver[A, B] {
  override val builder = pipeline.simple.Builder()
  override val codegen = ScalaCodegen()
}

abstract class OptimizingSnippetDriver[A: Typable, B: Typable](
    rules: Ruleset = eqsat.Rules.default
) extends SnippetDriver[A, B] {
  override val builder = eqsat.Builder(eqsat.Builder.Config(rules))
  override val codegen = ScalaCodegen()

  override def extract(): ast.Program = {
    val prog = super.extract()
    ast.Program(
      prog.functions.map(_.mapRight(_.map(Propagate.run))),
      prog.staticData
    )
  }
}
