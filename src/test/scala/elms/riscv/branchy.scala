package elms.koika.test.riscv

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.{KoikaSuite, Verdict}
import elms.koika.test.common.Reach
import elms.koika.test.common.{Cached, Predictive, Speculative}

// `branchy.s`'s own driver. At file scope because it has its own memory: the
// walk indexes `mem` with five bits, so the array has to be exactly 32 words
// and every other RISC-V demo runs on 30.
//
// One `init` for all four models, rather than the three the other suites spell
// out between them. This demo exists to be measured, and which fields a model
// leaves untouched is not what is being measured.
trait BranchyDriver extends RiscVDriver[32] {
  override val prog = demo("branchy")

  override val init = s"""void init(struct $stateT *s) {
       |  for (int i=0; i<NUM_REGS; i++) {
       |    s->regs[i] = 0;
       |    s->saved_regs[i] = 0;
       |  }
       |  s->timer = 0;
       |  for (int i=0; i<MEM_SIZE; i++) {
       |    s->mem[i] = 0;
       |  }
       |  for (int i=0; i<CACHE_LRU_SIZE; i++) {
       |    s->cache_keys[i] = -1;
       |    s->cache_vals[i] = -1;
       |  }
       |}""".stripMargin

  // The registers `branchy.s` shifts its indices out of, collected from the
  // program rather than written down a second time. Adding one to the walk is
  // then an edit to the assembly and nothing else.
  def indexRegs: Seq[Int] = prog.collect {
    case RiscV.Instr.OpImm(RiscV.AluOp.Srl, _, rs1, _) => rs1.i
  }.distinct.sorted

  // Drawn once and written into both states. The addresses the walk visits are
  // unknown, which is what gives a checker something to do, and provably equal
  // between the runs, which is what makes the answer clean. `branchy.s` says
  // why they cannot live in `mem`.
  override lazy val initialize_input: String = {
    require(indexRegs.nonEmpty, "branchy.s has no `srli`, so nothing would vary")
    val draws = indexRegs.map(r => s"""  int i$r = bounded(0, 1073741823);
       |  s1.regs[$r] = i$r;
       |  s2.regs[$r] = i$r;""".stripMargin)
    s"""
       |  // the indices, public: one draw into both states
       |${draws.mkString("\n")}""".stripMargin
  }
}

@virtualize
class RiscVBranchyTests extends KoikaSuite {
  // Labels carry the model and `under` carries none, so the snapshots land
  // beside the other demos of the same model rather than in a directory of
  // their own.
  val under = "riscv/"

  // Every model but [naive] puts a cache in front of the twelve probes, and
  // `runCache` forks three ways per load, so KLEE walks (3^12 + 1) / 2 paths
  // and does not arrive. CBMC answers all four in under eight seconds.
  test("riscv naive branchy") {
    val snippet = new BranchyDriver {}
    check("naive/branchy", snippet, Verdict.Clean)
  }

  test("riscv cache branchy") {
    val snippet = new BranchyDriver with Cached {}
    check("cache/branchy", snippet, Verdict.Clean, klee = Reach.LikelyTimeout)
  }

  test("riscv spec branchy") {
    val snippet = new BranchyDriver with Speculative {}
    check("speculative/branchy", snippet, Verdict.Clean, klee = Reach.LikelyTimeout)
  }

  test("riscv predictive branchy") {
    val snippet = new BranchyDriver with Predictive {}
    check("predictive/branchy", snippet, Verdict.Clean, klee = Reach.LikelyTimeout)
  }
}
