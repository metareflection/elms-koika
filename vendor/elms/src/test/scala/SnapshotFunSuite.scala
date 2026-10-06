package elms.test

import java.io._
import java.nio.file.{Files, Paths}
import org.scalatest.funsuite.AnyFunSuite

trait SnapshotFunSuite extends AnyFunSuite {
  // global override to accept all diffs
  val overwriteCheckFiles = false

  val prefix = "src/out/"
  val under: String

  try {
    val fullPrefix = this.prefix + this.under
    val i = fullPrefix.lastIndexOf('/')
    if (i != -1) then {
      val path = Paths.get(fullPrefix.substring(0, i))
      Files.createDirectories(path)
    }
  } catch { case e: IOException => () }

  def readFile(name: String): String = {
    try {
      val buf = new Array[Byte](new File(name).length().toInt)
      val fis = new java.io.FileInputStream(name)
      fis.read(buf)
      fis.close()
      new String(buf)
    } catch { case e: IOException => "" }
  }

  def writeFile(name: String, content: String) = {
    val lastSlash = name.lastIndexOf('/')
    if (lastSlash != -1) then {
      Files.createDirectories(Paths.get(name.substring(0, lastSlash)))
    }
    val out = new java.io.PrintWriter(new File(name))
    out.write(content)
    out.close()
  }

  // A snapshot only photographs where a comment landed. This checks it, so that
  // a later `accept = true` cannot re-bless a comment that has drifted.
  //
  // `next` is matched anywhere in the following line, because the Scala backend
  // binds a statement to a name and the C one does not. It is still exactly one
  // line that has to carry it.
  def assertCommentAgainst(code: String, comment: String, next: String): Unit = {
    val lines = code.linesIterator.toVector
    val i = lines.indexWhere(_.contains(comment))

    assert(i >= 0, s"no line carrying `$comment` in:\n$code")
    assert(i + 1 < lines.length, s"`$comment` is the last line in:\n$code")
    assert(
      lines(i + 1).contains(next),
      s"`$comment` is followed by `${lines(i + 1)}` rather than `$next` in:\n$code"
    )
  }

  def check(
      label: String,
      actual: String,
      ext: String = "scala",
      accept: Boolean = false
  ) = {
    val filePrefix = prefix + under + label
    val checkName = filePrefix + ".check." + ext
    val actualName = filePrefix + ".actual." + ext

    val expected = readFile(checkName)

    if expected != actual then {
      if accept || overwriteCheckFiles then {
        println(s"overwriting snapshot at `$checkName`")
        writeFile(checkName, actual)
      } else {
        writeFile(actualName, actual)
        assert(expected == actual)
      }
    }

    // If we get this far, the test passed. Remove any malingering .actual files.
    val f = new File(actualName)
    if f.exists then f.delete
  }
}
