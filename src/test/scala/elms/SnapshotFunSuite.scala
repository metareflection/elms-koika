// shamelessly copy-pasted from elms test suite

package elms.koika.test

import java.io._
import java.nio.file.{Files, Paths}
import org.scalatest.funsuite.AnyFunSuite

// `snapshot` and not `check`, so that [KoikaSuite.check] is the only `check` a
// suite can call. Sharing the name, a call that forgot the verdict resolved
// here instead and wrote a `.check.scala` that read like a test.
trait SnapshotFunSuite extends AnyFunSuite {
  // global override to accept all diffs
  val overwriteCheckFiles = false

  val under: String

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

  def snapshot(
      label: String,
      actual: String,
      ext: String = "scala",
      accept: Boolean = false,
      root: String
  ) = {
    val filePrefix = root + under + label
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
