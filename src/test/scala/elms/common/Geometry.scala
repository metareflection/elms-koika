package elms.koika.test.common

// One level of a cache hierarchy, and the shape of the whole thing.
//
// Everything here is an ordinary Scala `Int`, which is what makes a way
// comparison unroll at staging time while the set index stays a [Rep]. That
// split is the whole reason the residue does not grow with the number of sets:
// `cache_tags(base + set * ways + w)` is a symbolic subscript into inline
// storage, which is what `mem` already is.
case class Level(name: String, sets: Int, ways: Int, hitCost: Int) {
  require(sets > 0 && (sets & (sets - 1)) == 0, s"$name: $sets sets is not a power of two")
  require(ways > 0, s"$name: $ways ways")

  // Line frames at this level. One entry of every metadata array apiece, and
  // [Geometry.lineWords] words of `cache_vals`.
  val entries: Int = sets * ways
}

// [lineWords] is shared by every level, so a line maps one-to-one all the way
// down and a fill is one line read rather than a word read apiece.
case class Geometry(lineWords: Int, levels: Vector[Level]) {
  require(
    lineWords > 0 && (lineWords & (lineWords - 1)) == 0,
    s"$lineWords words per line is not a power of two"
  )
  require(levels.nonEmpty, "a hierarchy with no levels is [Direct]")

  val lineBits: Int = Integer.numberOfTrailingZeros(lineWords)

  // Where each level's slice of the metadata arrays starts. Levels share one
  // pair of arrays rather than taking a type parameter apiece, which is what
  // keeps [StateT] at four lengths however many levels there are.
  val base: Vector[Int] = levels.map(_.entries).scanLeft(0)(_ + _)

  val entries: Int = base.last
  val words: Int = entries * lineWords

  // Whether a store stops at [level]. Every level above the last takes the
  // write and passes it down as well, so a line is never dirty anywhere but
  // the bottom. That is not a tidiness point: an eviction write-back is the
  // one thing that would mutate the level below in the middle of an access,
  // and a level that cannot be dirty cannot do it.
  def writeBack(level: Int): Boolean = level == levels.length - 1

  def describe: String =
    levels
      .map(l => s"${l.name} ${l.sets}x${l.ways}x$lineWords@${l.hitCost}")
      .mkString(", ")
}

object Geometry {
  // Twelve line frames over the thirty-two lines of a 64-word `mem`, which is
  // the same scaling [Forwarding.forwardBits] does and for the same reason: two
  // bits of page offset over an address space is a curiosity, and over `mem` it
  // is exact. Small enough that an eviction set is four instructions, and large
  // enough that a demo is not one long miss. Grow the cache much past this and
  // the miss tier stops firing at all, which is the failure mode to watch for
  // rather than anything the tests would report.
  //
  // Three tiers and not two. [Forwarding.forwardCost] is 1 and so is an L1 hit,
  // which leaves those two arms indistinguishable in the timer; a level in
  // between is what gives a counterexample somewhere else to land.
  val default: Geometry = Geometry(
    lineWords = 2,
    levels = Vector(
      Level("L1", sets = 2, ways = 2, hitCost = 1),
      Level("L2", sets = 4, ways = 2, hitCost = 12)
    )
  )
}
