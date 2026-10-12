package elms.koika.test.squared

import elms.prelude.given
import elms.core.macros.virtualize

import elms.koika.test.riscv.{Flow, Multiplier, RiscV}
import RiscV.*

// RV32I and RV32M's multiplies, over a pair of runs.
//
// Every rule reads the same: the effects go through [each], because they are
// each run's own, and where control goes next is shared. The branch is the
// only rule that has to reconcile the two, and [agree] is what does it.
//
// The single-run halves below are a transcription of
// [elms.koika.test.riscv.Exec], which is where the ISA arguments live.
@virtualize
trait Exec extends Squared with Multiplier {
  // Computed once per driver rather than per call site: it is a fact about
  // `prog` and every call asks the same question of it.
  private lazy val consulted: Set[Int] = Flow.consultedAfterAnyCall(prog)

  override def shareable(target: Int): Boolean =
    !carriesHistory || Flow.historySafe(prog, target, consulted)

  // A conditional direct branch: what it tests, and where it goes. Static,
  // because the operands are register names and the target is an offset.
  type Cond = (Cmp, Reg, Reg)

  // A byte offset lands on an instruction index, and a misaligned one is a bug
  // in the demo rather than something the generated C should have to check.
  private def target(pc: Int, offset: Imm): Int = {
    require(offset.i % 4 == 0, s"misaligned branch offset ${offset.i} at pc $pc")
    pc + offset.i / 4
  }

  // The condition [i] tests and the index it jumps to, for a conditional
  // direct branch and nothing else. Whether to speculate past one is
  // [Speculative]'s call, and only it knows why the answer has to be
  // "forwards only".
  def branch(pc: Int, i: Instr): Option[(Cond, Int)] = i match {
    case Instr.Branch(cmp, rs1, rs2, off) => Some(((cmp, rs1, rs2), target(pc, off)))
    case _                                => None
  }

  // [Some(rd)] when [i] may run speculatively and writing [rd] is its only
  // effect a rollback would have to undo.
  //
  // Wider than it looks like it should be, and it has to be. RV32I has no
  // register-plus-register addressing and no scaled index, so the arithmetic
  // that turns a secret into a cache index is its own instruction; refusing
  // to speculate it would close the window before the gadget ran. Stores are
  // absent on purpose, since [rollback] restores registers and nothing else.
  def speculable(i: Instr): Option[Reg] = i match {
    case Instr.Load(_, rd, _, _)  => Some(rd)
    case Instr.Op(_, rd, _, _)    => Some(rd)
    case Instr.Mul(_, rd, _, _)   => Some(rd)
    case Instr.OpImm(_, rd, _, _) => Some(rd)
    case Instr.Lui(rd, _)         => Some(rd)
    case Instr.Auipc(rd, _)       => Some(rd)
    case _                        => None
  }

  // Whether [i] writes memory. [Forwarding] needs it in order to know where a
  // store window opens, and nothing else asks.
  def isStore(i: Instr): Boolean = i match {
    case Instr.Store(_, _, _, _) => true
    case _                       => false
  }

  private def flip(x: Rep[Int]): Rep[Int] = x ^ unit(Int.MinValue)

  // [c]'s truth in one run, with [of] supplying each operand. The reader is
  // what lets [Predictive] resolve a branch against the values that were in
  // the file when it was staged; everywhere else passes `readReg(h, _)`.
  def evalCond(of: Reg => Rep[Int], c: Cond): Rep[Boolean] = {
    val (cmp, rs1, rs2) = c
    val a = of(rs1)
    val b = of(rs2)
    cmp match {
      case Cmp.Eq => a === b
      case Cmp.Ne => a !== b
      case Cmp.Lt => a < b
      case Cmp.Ge => a >= b
      // Unsigned compare with no unsigned type: flipping the sign bit of both
      // sides turns the unsigned order into the signed one.
      case Cmp.Ltu => flip(a) < flip(b)
      case Cmp.Geu => flip(a) >= flip(b)
    }
  }

  // x0 is hardwired, and register names are static, so both halves of that
  // resolve before anything runs: reading it is the literal 0, and writing it
  // emits nothing at all.
  def readReg(h: Half, rs: Reg): Rep[Int] = rs match {
    case RiscV.Reg(0) => unit(0)
    case _            => get_reg(h, unit(rs.i))
  }

  private def write(h: Half, rd: Reg, v: Rep[Int]): Rep[Unit] = rd match {
    case RiscV.Reg(0) => unit(())
    case _            => set_reg(h, unit(rd.i), v)
  }

  // [get_mem] and [set_mem] are word-indexed, and [Cached] splits a word index
  // again into the line holding it and the word within. RISC-V addresses are
  // bytes, so the first split happens here: the word holding one, and the byte
  // within that.
  private def wordOf(addr: Rep[Int]): Rep[Int] = addr >>> unit(2)
  private def shiftOf(addr: Rep[Int]): Rep[Int] = (addr & unit(3)) << unit(3)

  // `SLL` and friends use only the low five bits of the shift amount. C leaves
  // a shift of 32 or more undefined, so the mask is both the ISA's semantics
  // and what makes the two backends agree.
  private def alu(op: AluOp, a: Rep[Int], b: Rep[Int]): Rep[Int] = op match {
    case AluOp.Add  => a + b
    case AluOp.Sub  => a - b
    case AluOp.Sll  => a << (b & unit(31))
    case AluOp.Srl  => a >>> (b & unit(31))
    case AluOp.Sra  => a >> (b & unit(31))
    case AluOp.And  => a & b
    case AluOp.Or   => a | b
    case AluOp.Xor  => a ^ b
    case AluOp.Slt  => if (a < b) { unit(1) } else { unit(0) }
    case AluOp.Sltu => if (flip(a) < flip(b)) { unit(1) } else { unit(0) }
  }

  // Unaligned `LW`/`LH` are unsupported: the demos are aligned, and asserting
  // alignment in the generated C would add checker noise to every load.
  private def loadValue(h: Half, w: Width, addr: Rep[Int]): Rep[Int] = {
    val word = get_mem(h, wordOf(addr))
    w match {
      case Width.W  => word
      case Width.Bu => (word >>> shiftOf(addr)) & unit(0xff)
      case Width.Hu => (word >>> shiftOf(addr)) & unit(0xffff)
      case Width.B  => (word << (unit(24) - shiftOf(addr))) >> unit(24)
      case Width.H  => (word << (unit(16) - shiftOf(addr))) >> unit(16)
    }
  }

  // `SB` and `SH` are read-modify-write, so they cost two cache probes. That
  // is what a write-allocate cache really does.
  private def storeValue(h: Half, w: Width, addr: Rep[Int], v: Rep[Int]): Rep[Unit] =
    w match {
      case Width.W => set_mem(h, wordOf(addr), v)
      case _ => {
        val mask = w match {
          case Width.H | Width.Hu => unit(0xffff)
          case _                  => unit(0xff)
        }
        val sh = shiftOf(addr)
        val old = get_mem(h, wordOf(addr))
        set_mem(h, wordOf(addr), (old & ~(mask << sh)) | ((v & mask) << sh))
      }
    }

  // `pc < prog.length` and not [Squared.live], which takes a slot number. The
  // two are the same number until [Predictive] hands out its own numbering,
  // and then they are not: this asked `live` whether slot 14 existed when
  // what it meant was whether the program had a fourteenth instruction.
  override def step(pc: Int, s: Pair): Pair =
    if (pc < prog.length) {
      each(s)(tick)
      prog(pc) match {
        case Instr.Op(op, rd, rs1, rs2) => {
          each(s)(h => write(h, rd, alu(op, readReg(h, rs1), readReg(h, rs2))))
          call(pc + 1, s)
        }
        case Instr.Mul(op, rd, rs1, rs2) => {
          each(s)(h => write(h, rd, mulOp(op, readReg(h, rs1), readReg(h, rs2))))
          call(pc + 1, s)
        }
        case Instr.OpImm(op, rd, rs1, imm) => {
          each(s)(h => write(h, rd, alu(op, readReg(h, rs1), unit(imm.i))))
          call(pc + 1, s)
        }
        case Instr.Lui(rd, imm) => {
          each(s)(h => write(h, rd, unit(imm.i << 12)))
          call(pc + 1, s)
        }
        case Instr.Auipc(rd, imm) => {
          each(s)(h => write(h, rd, unit(4 * pc + (imm.i << 12))))
          call(pc + 1, s)
        }
        case Instr.Jal(rd, off) => {
          each(s)(h => write(h, rd, unit(4 * (pc + 1))))
          call(target(pc, off), s)
        }
        case Instr.Branch(cmp, rs1, rs2, off) =>
          agree(each(s)(h => evalCond(readReg(h, _), (cmp, rs1, rs2)))) {
            call(target(pc, off), s)
          } {
            call(pc + 1, s)
          }
        case Instr.Load(w, rd, rs1, imm) => {
          each(s)(h => write(h, rd, loadValue(h, w, readReg(h, rs1) + unit(imm.i))))
          call(pc + 1, s)
        }
        case Instr.Store(w, rs2, rs1, imm) => {
          each(s)(h => storeValue(h, w, readReg(h, rs1) + unit(imm.i), readReg(h, rs2)))
          call(pc + 1, s)
        }
        // The link register really is written, in each run, so a callee that
        // spills `ra` and reloads it spills the right value. Where control
        // comes back to is the static stack's business and not this
        // register's.
        case Instr.Call(rd, target) => {
          each(s)(h => write(h, rd, unit(4 * (pc + 1))))
          if (inlineCalls || !shareable(target)) {
            withStack(deepen(pc, pc + 1)) { call(target, s) }
          } else {
            // A real call, so the callee is a function this one returns from
            // rather than a continuation it hands control to. Both runs come
            // back through the one emitted call, which is what keeps the
            // clocks comparable on the way out of it.
            val back = withStack(Nil) { call(target, s) }
            each(back)(h => returnsTo(untimed { readReg(h, RiscV.Reg(1)) }, pc + 1))
            call(pc + 1, back)
          }
        }
        // An unconditional jump, like [Jal], except that the target is a
        // prediction and has to be checked. Each run's `ra` is checked against
        // the same constant, so the two runs going the same way is a
        // consequence of the two assertions rather than a third claim:
        // [sameWay] has nothing left to reconcile here. A program that reaches
        // this having overwritten `ra` is the ret2spec shape, and the
        // assertions are where it shows up.
        //
        // With a real return there is no prediction left to check here, so the
        // obligation moves to the call site: the callee's residue function
        // returns exactly where its `ret` ran, so `ra` on the way out is the
        // value that `ret` read.
        case Instr.Ret => retstack match {
          case r :: rest => {
            each(s)(h => returnsTo(readReg(h, RiscV.Reg(1)), r))
            withStack(rest) { call(r, s) }
          }
          // Nothing to return through. A callee's own `ret` under a tower that
          // shares, and a leaf's under one that inlines; the jump past the end
          // is kept for the latter because [Predictive.slot] interns what it is
          // asked for and every slot number after it would move.
          case Nil => if (inlineCalls) { call(prog.length, s) } else { s }
        }
      }
    } else { s }
}
