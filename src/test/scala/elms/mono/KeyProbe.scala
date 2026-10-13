package elms.koika.test.mono

import org.scalatest.funsuite.AnyFunSuite

import scala.collection.mutable

import elms.koika.test.riscv.{Flow, RiscV, elf}

// What a [Predictive] slot key carries, per object, and why calls decide it.
//
// [Exec.liveBranchesAt] is `Flow.trains(prog, pc) ++ consulted`, and
// `consulted` is one set for the whole program: the union, over every call
// site, of the branches reachable once it returns. A call-free object has an
// empty one, so a key holds only what is still ahead of that pc and the median
// pc carries far less than the worst. An object with calls adds the same set
// everywhere.
//
// `crypto_poly1305` has six call sites and thirteen branches, and `consulted`
// is all thirteen, so its median pc keys on the whole program's history. That
// is 2^13 against 1792 slots, which is why no [Predictive] cell exists for it
// and why `poly.scala` reaches for a bounded register instead.
//
// Not a cell: it reports rather than asserting, because the numbers are a
// property of objects the tree does not otherwise promise anything about.
class KeyProbe extends AnyFunSuite {
  // Old: `trains(pc) ++ consultedAfterAnyCall`, where the second term is one
  // set for the whole program and goes into every key.
  // New: [Flow.trainsUnder], walked over the (pc, stack) pairs the staging
  // actually reaches from the entry, so a `ret` follows one edge.
  private def report(name: String, path: String, entry: String = ""): Unit = {
    if (!java.nio.file.Files.exists(java.nio.file.Path.of(path))) {
      info(f"$name%-18s not built")
      return
    }
    val img = elf.Elf.load(path)
    val prog = img.prog
    val from = if (entry.isEmpty) 0 else img.entries(entry)
    val consulted = Flow.consultedAfterAnyCall(prog)

    // Every (pc, stack) the walk from [from] can be at, which is what a slot
    // key ranges over.
    val seen = mutable.Set[(Int, List[Int])]()
    val todo = mutable.Stack((from, List.empty[Int]))
    while (todo.nonEmpty) {
      val (pc, st) = todo.pop()
      if (pc >= 0 && pc < prog.length && st.length <= 32 && seen.add((pc, st))) {
        prog(pc) match {
          case RiscV.Instr.Ret => st match {
              case r :: rest => todo.push((r, rest))
              case Nil       => ()
            }
          case RiscV.Instr.Call(_, t)          => todo.push((t, (pc + 1) :: st))
          case RiscV.Instr.Jal(_, off)         => todo.push((pc + off.i / 4, st))
          case RiscV.Instr.Branch(_, _, _, off) =>
            todo.push((pc + 1, st)); todo.push((pc + off.i / 4, st))
          case _ => todo.push((pc + 1, st))
        }
      }
    }

    val oldKeys = prog.indices.map(pc => (Flow.trains(prog, pc) ++ consulted).size)
    val newKeys = seen.toSeq.map { case (pc, st) =>
      Flow.trainsUnder(prog, pc, st, 32).map(_.size).getOrElse(oldKeys(pc))
    }.sorted
    val calls = prog.count { case RiscV.Instr.Call(_, _) => true; case _ => false }
    val brs = prog.count { case RiscV.Instr.Branch(_, _, _, _) => true; case _ => false }
    info(f"$name%-18s calls=$calls%-2d br=$brs%-3d | old max=${oldKeys.max}%-3d " +
      f"med=${oldKeys.sorted.apply(oldKeys.size / 2)}%-3d | new max=${newKeys.max}%-3d " +
      f"med=${newKeys(newKeys.size / 2)}%-3d states=${seen.size}%d")
  }

  test("what a predictive slot key carries") {
    report("poly1305", "src/test/mono/poly.o", "crypto_poly1305")
    report("ccopy/unrolled", "src/test/mono/unrolled.o")
    report("hsalsa20", "src/test/fact/hsalsa20.o")
    report("fscalar_product", "src/test/fact/fscalar_product.o")
    report("salsa20", "src/test/fact/salsa20.o")
  }
}
