package elms.koika.test.mono

import org.scalatest.funsuite.AnyFunSuite

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
  private def report(name: String, path: String): Unit = {
    if (!java.nio.file.Files.exists(java.nio.file.Path.of(path))) {
      info(f"$name%-18s not built")
      return
    }
    val prog = elf.Elf.load(path).prog
    val consulted = Flow.consultedAfterAnyCall(prog)
    val live = prog.indices.map(pc => (Flow.trains(prog, pc) ++ consulted).size)
    val calls = prog.count { case RiscV.Instr.Call(_, _) => true; case _ => false }
    val brs = prog.count { case RiscV.Instr.Branch(_, _, _, _) => true; case _ => false }
    info(f"$name%-18s calls=$calls%-3d branches=$brs%-3d consulted=${consulted.size}%-3d " +
      f"maxKey=${live.max}%-3d medianKey=${live.sorted.apply(live.size / 2)}%-3d")
  }

  test("what a predictive slot key carries") {
    report("poly1305", "src/test/mono/poly.o")
    report("ccopy/unrolled", "src/test/mono/unrolled.o")
    report("hsalsa20", "src/test/fact/hsalsa20.o")
    report("fscalar_product", "src/test/fact/fscalar_product.o")
    report("salsa20", "src/test/fact/salsa20.o")
  }
}
