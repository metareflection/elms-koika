package elms.test

import java.net.URLClassLoader
import java.nio.file.Files
import scala.jdk.CollectionConverters.*

import elms.prelude.*
import elms.prelude.given
import elms.core.Type
import elms.codegen.ScalaCodegen
import elms.codegen.Config

abstract class DslDriver[A: Typable, B: Typable]
    extends OptimizingSnippetDriver[A, B] with DslOps

// Compiles the generated C and runs it, so a test can check what a program
// does and not only what it says. A snapshot cannot tell `strncmp(s, p, ...)`
// from `strncmp(p, s, ...)`, and neither can a reader.
//
// `None` when no C compiler is installed. The rest of the suite needs none, so
// a test that wants one cancels rather than fails.
object CRunner {
  private lazy val cc: Option[String] = Seq("cc", "gcc", "clang").find { c =>
    try new ProcessBuilder(c, "--version").redirectErrorStream(true).start()
        .waitFor() == 0
    catch { case _: java.io.IOException => false }
  }

  private def read(p: Process): String = {
    val out = new String(p.getInputStream.readAllBytes, "utf-8")
    (p.waitFor(), out)._2
  }

  // `main` is the caller the test writes, since `code` only ever defines
  // `snippet`.
  def run(code: String, main: String): Option[String] = cc.map { compiler =>
    val dir = Files.createTempDirectory("elms-c")

    // `#include "elms_lib.h"` looks next to the generated file, so that is
    // where the vendored copy goes. Reading it off the classpath is also the
    // only thing that checks it ships as a resource at all.
    val lib = getClass.getResourceAsStream("/elms_lib.h")
    Files.write(dir.resolve("elms_lib.h"), lib.readAllBytes)
    lib.close()

    Files.writeString(dir.resolve("snippet.c"), code)
    Files.writeString(dir.resolve("main.c"), main)

    val exe = dir.resolve("run")
    val build = new ProcessBuilder(
      compiler, "-std=c11", "-Wall", "-Wextra", "snippet.c", "main.c",
      "-o", exe.toString
    ).directory(dir.toFile).redirectErrorStream(true).start()
    val log = read(build)
    if build.exitValue() != 0 then
      throw new RuntimeException(s"generated C did not compile:\n$log\n--\n$code")

    val proc = new ProcessBuilder(exe.toString).directory(dir.toFile)
      .redirectErrorStream(true).start()
    val out = read(proc)
    if proc.exitValue() != 0 then
      throw new RuntimeException(s"generated program exited ${proc.exitValue()}:\n$out")

    out
  }
}

// A C driver whose backend the test names, for the cases that vary
// `CCodegen.Options`. The snapshot drivers build their own and have no reason
// to.
abstract class TunedDriver[A: Typable, B: Typable](
    override val codegen: elms.codegen.CCodegen
) extends SimpleSnippetDriver[A, B] with DslOps

trait EvalScalaSnippet[A: Typable, B: Typable] extends SnippetDriver[A, B] {
  val prefix: String
  val name: String

  /** Imports the generated compilation unit needs (e.g. a custom result type
    * that the snippet constructs and names). Rendered as `import <i>` lines. */
  protected def imports: Seq[String] = Seq()

  /** Renderings for types beyond the built-ins, so a driver can teach the
    * codegen how to print a custom `Type` (e.g. `DFAStateT`). */
  protected def extraRenderType: PartialFunction[Type, String] = PartialFunction.empty

  protected def scalacOptions: Seq[String] = Seq()

  // baseIndentLevel = 2 keeps the body nested inside `object $name { ... }`.
  override val codegen =
    new ScalaCodegen(Config.scalaDefault.copy(baseIndentLevel = 2)) {
      override protected def renderType(ty: Type): String =
        extraRenderType.applyOrElse(ty, (t: Type) => super.renderType(t))
    }

  final case class CompiledDir(outDir: java.nio.file.Path) {
    def loadClass(name: String): Class[?] = {
      val loader =
        new URLClassLoader(
          Array(outDir.toUri.toURL),
          this.getClass.getClassLoader
        )

      loader.loadClass(name)
    }
  }

  private def compileScala(sources: (String, String)*): CompiledDir = {
    val root = Files.createTempDirectory(prefix)
    val srcDir = root.resolve("src")
    val outDir = root.resolve("out")

    Files.createDirectories(srcDir)
    Files.createDirectories(outDir)

    val sourceFiles =
      sources.map { case (name, content) =>
        val file = srcDir.resolve(name)
        Files.createDirectories(file.getParent)
        Files.writeString(file, content)
        file
      }

    val cp = sys.props("generated.test.classpath")

    val args =
      scalacOptions ++
        Seq("-classpath", cp, "-d", outDir.toString) ++
        sourceFiles.map(_.toString)

    val reporter = dotty.tools.dotc.Main.process(args.toArray)
    if reporter.hasErrors then
      throw new RuntimeException(s"failed to compile generated snippet `$name`")

    CompiledDir(outDir)
  }

  override def code = {
    val importLines =
      if imports.isEmpty then "" else imports.map(i => s"import $i\n").mkString
    importLines + s"object $name {\n  " + super.code + "\n}"
  }

  lazy val compiled: Class[?] = compileScala(s"$name.scala" -> code).loadClass(s"$name$$")

  // Look the method up by name: `classOf[Unit]` is `void`, but the compiled
  // parameter is `scala.runtime.BoxedUnit`, so `getMethod` by class would miss.
  private lazy val snippetMethod: java.lang.reflect.Method =
    compiled.getMethods
      .find(_.getName == "snippet")
      .getOrElse(throw new NoSuchMethodException(s"snippet in object $name"))

  def eval(input: A): B = {
    val obj = compiled.getField("MODULE$").get(null)
    snippetMethod.invoke(obj, input.asInstanceOf[AnyRef]).asInstanceOf[B]
  }
}
