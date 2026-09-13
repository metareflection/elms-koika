package elms.koika.test.nanorisc

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.common.GenericKoikaDriver

// The NanoRisc machine: 8 registers, 30 words of memory, 10 cache lines. Named
// here so that the three suites that build on it cannot disagree about any of
// the three, the way they would spelling the numbers out apiece.
trait NanoRiscDriver extends GenericKoikaDriver[8, 30, 10] with Exec
