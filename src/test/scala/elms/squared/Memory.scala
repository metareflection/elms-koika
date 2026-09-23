package elms.koika.test.squared

import elms.prelude.given
import elms.core.macros.virtualize

import elms.koika.test.common.{Geometry, Level}

// A register file and a memory with no cache in front of either.
@virtualize
trait Flat extends Machine {
  override def get_reg(h: Half, i: Rep[Int]): Rep[Int] = h.regs(i)
  override def set_reg(h: Half, i: Rep[Int], v: Rep[Int]): Rep[Unit] = h.regs(i) = v

  override def get_mem(h: Half, i: Rep[Int]): Rep[Int] = h.mem(i)
  override def set_mem(h: Half, i: Rep[Int], v: Rep[Int]): Rep[Unit] = h.mem(i) = v
}

// A set-associative, LRU, line-granular cache hierarchy in front of memory.
//
// The same model as [elms.koika.test.common.Cached], transcribed against one
// run's [Half] instead of against a whole state, and that file is where the
// argument for the shape lives. What has to stay true is that the two agree:
// every verdict this tower produces is checked against the one the other
// produces for the same demo, so a divergence shows up as a disagreeing pair.
//
// The three knobs do not cost the same. Sets are free, because the set index
// is a [Rep] and `cache_tags(base + set * ways + w)` is one symbolic subscript
// however many there are. Ways are nearly free, because [eqMask] turns a tag
// comparison into arithmetic and the matching way falls out of an `or`, so W
// ways is W expressions and still two arms. Levels cost one arm apiece.
//
// An entry holds a line rather than a word, which is the point: a lookup table
// that fits inside one line is one probe, and "the table fits in a line" is
// the argument real constant-time code actually makes.
@virtualize
trait Cached extends Flat {
  def geometry: Geometry

  // What a line costs when no level has it.
  def memCost: Int = 100

  private def lineWords: Int = geometry.lineWords
  private def levels: Vector[Level] = geometry.levels

  // -1 when the two are equal and 0 otherwise, out of a sign bit rather than
  // out of a comparison. `d | -d` has its top bit set for every d but zero, so
  // this is equality with no branch in it, which is what lets a way count grow
  // without the residue forking per way.
  private def eqMask(a: Rep[Int], b: Rep[Int]): Rep[Int] = {
    val d = a ^ b
    ~((d | (unit(0) - d)) >> unit(31))
  }

  // [t] where [m] is all ones, [f] where it is zero.
  private def pick(m: Rep[Int], t: Rep[Int], f: Rep[Int]): Rep[Int] = f ^ (m & (t ^ f))

  // Where [line] would live at [level], and whether it is there.
  //
  // [hit] is a mask and not a [Rep[Boolean]] on purpose: the caller both tests
  // it and selects a latency with it, and a mask does the second without a
  // second comparison.
  private case class Probe(level: Int, set: Rep[Int], hit: Rep[Int], entry: Rep[Int])

  // One symbolic array read per way, which is the whole budget. The tag stored
  // is the line number itself, so an empty frame's -1 fails the comparison on
  // its own and there is no valid bit to read alongside it.
  private def probe(h: Half, level: Int, line: Rep[Int]): Probe = {
    val g = levels(level)
    val set = line & unit(g.sets - 1)
    val base = unit(geometry.base(level)) + set * unit(g.ways)

    // Accumulated in ordinary Scala vars, which is safe here and nowhere near
    // a virtualized `if`: these are straight-line expressions, so what the var
    // names at the end is the whole chain rather than whichever arm was staged
    // last.
    var hit: Rep[Int] = unit(0)
    var way: Rep[Int] = unit(0)
    for (w <- 0 until g.ways) {
      val m = eqMask(h.cache_tags(base + unit(w)), line)
      hit = hit | m
      way = way | (m & unit(w))
    }
    Probe(level, set, hit, base + way)
  }

  // Exact LRU. Age 0 is the most recent, and everything younger than the entry
  // just touched ages by one, which over [ways] entries keeps the ages a
  // permutation of `0 until ways`. The comparison is the sign bit of a
  // subtraction rather than an `if`, for the reason [eqMask] is.
  private def touch(h: Half, level: Int, set: Rep[Int], entry: Rep[Int]): Rep[Unit] = {
    val g = levels(level)
    val base = unit(geometry.base(level)) + set * unit(g.ways)
    val was = h.cache_age(entry)
    for (w <- 0 until g.ways) {
      val e = base + unit(w)
      val a = h.cache_age(e)
      h.cache_age(e) = a + ((a - was) >>> unit(31))
    }
    h.cache_age(entry) = unit(0)
  }

  // The entry a fill would take: the oldest, and an invalid one ahead of any
  // valid one. An invalid entry is given an age of [ways], which is one past
  // anything a valid entry can hold, so "prefer invalid" needs no test of its
  // own.
  private def victim(h: Half, level: Int, set: Rep[Int]): Rep[Int] = {
    val g = levels(level)
    val base = unit(geometry.base(level)) + set * unit(g.ways)
    // `-1 & ways` is `ways`, so an empty frame reads one older than the oldest
    // live one without a test of its own.
    def age(e: Rep[Int]): Rep[Int] =
      h.cache_age(e) + (eqMask(h.cache_tags(e), unit(-1)) & unit(g.ways))

    var bestWay: Rep[Int] = unit(0)
    var bestAge: Rep[Int] = age(base)
    for (w <- 1 until g.ways) {
      val a = age(base + unit(w))
      val older = (bestAge - a) >> unit(31)
      bestWay = pick(older, unit(w), bestWay)
      bestAge = pick(older, a, bestAge)
    }
    base + bestWay
  }

  private def word(entry: Rep[Int], offset: Rep[Int]): Rep[Int] =
    entry * unit(lineWords) + offset

  private def readEntry(h: Half, entry: Rep[Int]): Vector[Rep[Int]] =
    (0 until lineWords).toVector.map(i => h.cache_vals(word(entry, unit(i))))

  private def writeEntry(h: Half, entry: Rep[Int], ws: Vector[Rep[Int]]): Rep[Unit] = {
    ws.zipWithIndex.foreach((x, i) => h.cache_vals(word(entry, unit(i))) = x)
    unit(())
  }

  private def readMemLine(h: Half, line: Rep[Int]): Vector[Rep[Int]] =
    (0 until lineWords).toVector.map(i => h.mem(line * unit(lineWords) + unit(i)))

  private def writeMemLine(h: Half, line: Rep[Int], ws: Vector[Rep[Int]]): Rep[Unit] = {
    ws.zipWithIndex.foreach((x, i) => h.mem(line * unit(lineWords) + unit(i)) = x)
    unit(())
  }

  // [line] present at [level], and its entry.
  //
  // [ps] is the probe each level was seen in before anything moved. A level
  // whose entry is [None] is probed again here, which is what a second visit to
  // a level in one access needs: the first visit may have installed the line,
  // and a mask read before that would describe the wrong state.
  private def bring(
      h: Half,
      level: Int,
      line: Rep[Int],
      ps: Vector[Option[Probe]]
  ): Rep[Int] = {
    val p = ps(level).getOrElse(probe(h, level, line))
    if (p.hit !== unit(0)) {
      touch(h, level, p.set, p.entry)
      p.entry
    } else {
      val e = victim(h, level, p.set)

      // Only the bottom level is ever dirty, so this is one `if` in one place
      // rather than one per level. See [Geometry.writeBack]: a level that can
      // be dirty is a level whose eviction mutates the one below it, in the
      // middle of an access that has already read that level's tags.
      //
      // Dirty implies live, so there is no emptiness test here either: a frame
      // is only ever dirtied by a store to a line it is holding, and a fill
      // clears the bit before anything can write to that frame again. The tag
      // is the line, so the write-back needs no arithmetic to find its address.
      if (geometry.writeBack(level)) {
        if (h.cache_dirty(e) !== unit(0)) {
          writeMemLine(h, h.cache_tags(e), readEntry(h, e))
        }
      }

      writeEntry(h, e, fill(h, level + 1, line, ps))
      h.cache_tags(e) = line
      h.cache_dirty(e) = unit(0)

      // Oldest first, and only then touched. [touch] ages what is younger than
      // the entry it is given, so handing it one that still reads 0 from a
      // cold start would age nothing and leave two frames tied at 0 with no
      // way to tell which to evict next. In the steady state the victim is
      // already the oldest and this writes what was there.
      h.cache_age(e) = unit(levels(level).ways - 1)
      touch(h, level, p.set, e)
      e
    }
  }

  // A whole line out of [level], which is memory once the hierarchy runs out.
  // Line-granular and not word-granular, which is what real hardware does and
  // is also what keeps a fill from forking once per word.
  private def fill(
      h: Half,
      level: Int,
      line: Rep[Int],
      ps: Vector[Option[Probe]]
  ): Vector[Rep[Int]] =
    if (level == levels.length) { readMemLine(h, line) }
    else { readEntry(h, bring(h, level, line, ps)) }

  // One word, written at [level] and at every level below it. The bottom takes
  // the write and marks the line dirty; everything above takes it and passes
  // it on, which is what [Geometry.writeBack] means by write-through.
  private def store(
      h: Half,
      level: Int,
      line: Rep[Int],
      offset: Rep[Int],
      v: Rep[Int],
      ps: Vector[Option[Probe]]
  ): Rep[Unit] =
    if (level == levels.length) { h.mem(line * unit(lineWords) + offset) = v }
    else {
      val e = bring(h, level, line, ps)
      h.cache_vals(word(e, offset)) = v
      if (geometry.writeBack(level)) { h.cache_dirty(e) = unit(1) }
      // Everything below has been visited already: this level's fill went
      // through all of them. So the write down re-probes rather than trusting
      // a mask that predates its own fill.
      else { store(h, level + 1, line, offset, v, ps.map(_ => None)) }
    }

  // What the access costs, read off the state it arrived in and before any of
  // it moves. Selected arithmetically rather than charged inside the arms, so
  // that the number exists as a value in its own right.
  private def latency(ps: Vector[Probe]): Rep[Int] =
    ps.foldRight(unit(memCost))((p, below) => pick(p.hit, unit(levels(p.level).hitCost), below))

  def runCache(h: Half, addr: Rep[Int], v: Option[Rep[Int]]): Rep[Int] = {
    val offset = addr & unit(lineWords - 1)
    val line = addr >>> unit(lineBits)

    // One probe per level, shared by the latency and by the data path. Both
    // want the state the access arrived in, and a symbolic tag read is the
    // most expensive thing in here: doing it twice was most of the formula.
    val ps = levels.indices.toVector.map(probe(h, _, line))
    val some = ps.map(Some(_))
    spend(h, latency(ps))
    v match {
      case Some(x) => { store(h, 0, line, offset, x, some); x }
      case None    => h.cache_vals(word(bring(h, 0, line, some), offset))
    }
  }

  private def lineBits: Int = geometry.lineBits

  override def get_mem(h: Half, addr: Rep[Int]): Rep[Int] = runCache(h, addr, None)

  override def set_mem(h: Half, addr: Rep[Int], v: Rep[Int]): Rep[Unit] = {
    runCache(h, addr, Some(v))
    unit(())
  }
}
