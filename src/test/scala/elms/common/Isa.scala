package elms.koika.test.common

import elms.prelude.*
import elms.prelude.given

// What the tower has to ask of an instruction, and nothing more. [Reg] is
// static because register names come out of [prog], which is known at staging
// time; only their contents are [Rep].
trait Isa extends StateTOps {
  type Instr
  type Reg
  type Cond

  def get_reg(s: Rep[State], i: Rep[Int]): Rep[Int]
  def set_reg(s: Rep[State], i: Rep[Int], v: Rep[Int]): Rep[Unit]

  // Word-indexed, not byte-addressed. [Cached] keys its LRU on whatever comes
  // through here and writes back with `s.mem(key)`, so an ISA with byte
  // addresses converts in [step] and one cache entry stays one word.
  def get_mem(s: Rep[State], i: Rep[Int]): Rep[Int]
  def set_mem(s: Rep[State], i: Rep[Int], v: Rep[Int]): Rep[Unit]

  def regIndex(r: Reg): Int

  // A conditional direct branch: its condition, and the absolute index into
  // [prog] that it targets. [pc] is supplied because most ISAs encode the
  // target relative to it. [None] for unconditional jumps, for computed jumps,
  // and for anything that is not a branch.
  //
  // Whether to speculate past it is not this method's call. [Speculative]
  // decides that, and only it knows why the answer has to be "forwards only".
  def branch(pc: Int, i: Instr): Option[(Cond, Int)]

  // [Some(rd)] when [i] may run speculatively and writing [rd] is its only
  // effect that rollback would have to undo.
  //
  // Stores must answer [None]. [rollback] restores registers and nothing else,
  // so a speculative store is never taken back. The cache side effect is the
  // exception on purpose, since it is the channel the whole model exists to
  // expose.
  def speculable(i: Instr): Option[Reg]

  // Every register [c] depends on. Over-approximating is safe; missing one
  // silently corrupts branch resolution, because [evalCond] runs against the
  // live register file at the join point rather than at the branch.
  def reads(c: Cond): Set[Reg]
  def evalCond(s: Rep[State], c: Cond): Rep[Boolean]

  // Non-speculative semantics for one instruction. Recurses through
  // [Common.call], never through [step].
  def step(pc: Int, s: Rep[State]): Rep[State]
}
