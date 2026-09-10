package elms.koika.test.riscv

object RiscVDemos {
  import RiscV.*
  import RiscV.Instr.*

  val x0: Reg = Reg(0)
  val x5: Reg = Reg(5)
  val x6: Reg = Reg(6)
  val x7: Reg = Reg(7)
  val x8: Reg = Reg(8)
  val x9: Reg = Reg(9)
  val x10: Reg = Reg(10)
  val x11: Reg = Reg(11)
  val x12: Reg = Reg(12)
  val x13: Reg = Reg(13)
  val x14: Reg = Reg(14)
  val x15: Reg = Reg(15)
  val x16: Reg = Reg(16)

  private def li(rd: Reg, v: Int): Instr = OpImm(AluOp.Add, rd, x0, Imm(v))
  private def addi(rd: Reg, rs1: Reg, v: Int): Instr = OpImm(AluOp.Add, rd, rs1, Imm(v))
  private def add(rd: Reg, rs1: Reg, rs2: Reg): Instr = Op(AluOp.Add, rd, rs1, rs2)
  private def lw(rd: Reg, rs1: Reg, off: Int): Instr = Load(Width.W, rd, rs1, Imm(off))
  private def j(off: Int): Instr = Jal(x0, Imm(off))

  /* 0   beq   x10, x0, done      # +16
   * 1   lw    x11, 0(x10)
   * 2   slli  x11, x11, 2
   * 3   lw    x12, 16(x11)
   * 4 done:
   *
   * The minimal branch-then-dependent-loads program, and the RISC-V twin of
   * NanoRisc's `spec_small`. The `beq` is shorter than `B(Eq, r0, Imm(0))` had
   * to be, because x0 being hardwired zero is exactly what that spelled out.
   *
   * The `slli` is the byte-addressing tax. `mem` is word-indexed, so a secret
   * used directly as a byte address only reaches word `secret >> 2` and can
   * never collide with the word the first load already pulled in. Scaling it
   * first is what real Spectre gadgets do with the cache line size, and it is
   * what makes the second probe land in the same range as the first.
   *
   * Naive: CBMC passes (fail to detect)
   * Cache/Speculative: CBMC fails (leak detected)
   */
  def spec_small: Vector[Instr] =
    Vector(
      Branch(Cmp.Eq, x10, x0, Imm(16)),
      lw(x11, x10, 0),
      OpImm(AluOp.Sll, x11, x11, Imm(2)),
      lw(x12, x11, 16)
    )

  /* 0   addi  x13, x0, 0        # base
   * 1   addi  x10, x0, SECRET   # index, out of bounds
   * 2   addi  x15, x0, SECRET   # bound
   * 3   bge   x10, x15, done    # +20, and it is taken
   * 4   add   x5,  x13, x10
   * 5   lw    x11, 0(x5)        # speculative secret load
   * 6   slli  x11, x11, 2
   * 7   lw    x12, 0(x11)       # secret-dependent address, the channel
   * 8 done:
   *
   * SPECTRE vulnerability.
   *
   * Two instructions here that the NanoRisc version does not need, and both are
   * the ISA rather than the demo. RV32I has no register-plus-register
   * addressing, so the address wants an `add`; and `mem` is word-indexed, so
   * the secret wants scaling before it can be used as one. Both sit inside the
   * speculation window, which is why [Exec.speculable] admits ALU ops.
   *
   * Naive/Cache: CBMC passes (fail to detect)
   * Speculative: CBMC fails (leak detected)
   */
  def build_spectre_demo(secret_offset_bytes: Int): Vector[Instr] =
    Vector(
      li(x13, 0),
      li(x10, secret_offset_bytes),
      li(x15, secret_offset_bytes),
      Branch(Cmp.Ge, x10, x15, Imm(20)),
      add(x5, x13, x10),
      lw(x11, x5, 0),
      OpImm(AluOp.Sll, x11, x11, Imm(2)),
      lw(x12, x11, 0)
    )

  /* 0    addi  x12, x0, 0        # guess base
   * 1    addi  x13, x0, SECRET   # secret base
   * 2    addi  x14, x0, 0        # i, in bytes
   * 3    addi  x15, x0, SIZE     # size, in bytes
   * 4  loop: bge x14, x15, right # +40
   * 5    add   x5,  x12, x14
   * 6    lw    x10, 0(x5)
   * 7    add   x6,  x13, x14
   * 8    lw    x11, 0(x6)
   * 9    bne   x10, x11, wrong   # +12
   * 10   addi  x14, x14, 4
   * 11   jal   x0,  loop         # -28
   * 12 wrong: addi x10, x0, 0
   * 13   jal   x0,  done         # +8
   * 14 right: addi x10, x0, 1
   * 15 done:
   *
   * Standard short-circuiting password-checker loop, leaks whether some prefix
   * of the guess is correct. The counter steps by 4, because addresses are
   * bytes.
   *
   * The leak here is in the control flow rather than in the speculation, so
   * every driver sees it.
   *
   * All drivers should detect a timing leak (CBMC should fail).
   */
  def build_shortcircuit_demo(secret_offset_bytes: Int, password_size_bytes: Int): Vector[Instr] =
    Vector(
      li(x12, 0),
      li(x13, secret_offset_bytes),
      li(x14, 0),
      li(x15, password_size_bytes),
      Branch(Cmp.Ge, x14, x15, Imm(40)),
      add(x5, x12, x14),
      lw(x10, x5, 0),
      add(x6, x13, x14),
      lw(x11, x6, 0),
      Branch(Cmp.Ne, x10, x11, Imm(12)),
      addi(x14, x14, 4),
      j(-28),
      li(x10, 0),
      j(8),
      li(x10, 1)
    )

  /* 0    addi  x12, x0, 0        # guess base
   * 1    addi  x13, x0, SECRET   # secret base
   * 2    addi  x14, x0, 0        # i, in bytes
   * 3    addi  x15, x0, SIZE     # size, in bytes
   * 4    addi  x5,  x0, 0        # acc
   * 5  loop: bge x14, x15, done  # +36
   * 6    add   x6,  x12, x14
   * 7    lw    x7,  0(x6)
   * 8    add   x8,  x13, x14
   * 9    lw    x9,  0(x8)
   * 10   xor   x16, x7, x9
   * 11   or    x5,  x5, x16
   * 12   addi  x14, x14, 4
   * 13   jal   x0,  loop         # -32
   * 14 done: sltiu x11, x5, 1
   *
   * The positive control the suite lacks: a branchless comparison that
   * accumulates `xor` into an `or` and turns the result into a bit with
   * `sltiu`. Every iteration runs, the trip count is public, and no address
   * depends on a secret value.
   *
   * The accumulator is x16 and not x10 on purpose. `initialize_input` writes
   * the attacker-controlled value into regs[10], which the two SPECTRE demos do
   * read, and reusing it here as scratch would read as though it mattered.
   *
   * All drivers should pass (no leak). If the speculative driver fails here it
   * is a finding about the model rather than about the demo.
   */
  def build_constant_time_demo(secret_offset_bytes: Int, password_size_bytes: Int): Vector[Instr] =
    Vector(
      li(x12, 0),
      li(x13, secret_offset_bytes),
      li(x14, 0),
      li(x15, password_size_bytes),
      li(x5, 0),
      Branch(Cmp.Ge, x14, x15, Imm(36)),
      add(x6, x12, x14),
      lw(x7, x6, 0),
      add(x8, x13, x14),
      lw(x9, x8, 0),
      Op(AluOp.Xor, x16, x7, x9),
      Op(AluOp.Or, x5, x5, x16),
      addi(x14, x14, 4),
      j(-32),
      OpImm(AluOp.Sltu, x11, x5, Imm(1))
    )
}
