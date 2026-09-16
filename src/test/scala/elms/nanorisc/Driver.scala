package elms.koika.test.nanorisc

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.common.GenericKoikaDriver

// The NanoRisc machine: 8 registers, 64 words of memory, and the cache
// [Geometry.default] describes, whose two levels come to 12 line frames of 24
// words between them. Named here so that the three suites that build on it
// cannot disagree about any of them, the way they would spelling the numbers
// out apiece.
trait NanoRiscDriver extends GenericKoikaDriver[8, 64, 24, 12] with Exec
