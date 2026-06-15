package elms.koika.test

import elms.prelude.*
import elms.prelude.given

abstract class KoikaSuite extends SnapshotFunSuite {
  override def check(
      label: String,
      actual: String,
      ext: String = "c",
      accept: Boolean = false
  ) = super.check(label, actual, ext, accept)
}
