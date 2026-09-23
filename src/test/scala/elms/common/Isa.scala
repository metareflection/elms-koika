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

  // Word-indexed, not byte-addressed. [Cached] splits whatever comes through
  // here into a line and a word within it, so an ISA with byte addresses
  // converts in [step] and the cache never sees a byte offset.
  def get_mem(s: Rep[State], i: Rep[Int]): Rep[Int]
  def set_mem(s: Rep[State], i: Rep[Int], v: Rep[Int]): Rep[Unit]

  def regIndex(r: Reg): Int

  // A conditional direct branch: its condition, and the absolute index into
  // [prog] that it targets. [pc] is supplied because most ISAs encode the
  // target relative to it. [None] for unconditional jumps, for computed jumps,
  // and for anything that is not a branch.
  //
  // Whether to speculate past it is not this method's call, and no model in the
  // tower needs the answer restricted: [Predictive] emits a window as functions
  // rather than inlining one, so a backward target terminates.
  def branch(pc: Int, i: Instr): Option[(Cond, Int)]

  // [Some(rd)] when [i] may run speculatively and writing [rd] is its only
  // effect that rollback would have to undo.
  //
  // Stores must answer [None]. A squash restores registers and nothing else, so
  // a store that ran inside a branch window would never be taken back, and
  // answering [None] is what closes the window before one can. The cache side
  // effect is the exception on purpose, since it is the channel the whole model
  // exists to expose.
  //
  // [Forwarding] is where a store does run speculatively, and it gets there
  // through [isStore] and a queue rather than through here.
  def speculable(i: Instr): Option[Reg]

  // Whether [i] writes memory. [Forwarding] needs it in order to know where a
  // store window opens, and nothing else asks.
  //
  // Abstract rather than defaulted to `false`, because the default is a model
  // that stages, verifies, and silently never speculates about a store.
  def isStore(i: Instr): Boolean

  // Every register [c] depends on. Over-approximating is safe; missing one
  // silently corrupts branch resolution, because [evalCond] runs against the
  // live register file at the join point rather than at the branch.
  def reads(c: Cond): Set[Reg]
  def evalCond(s: Rep[State], c: Cond): Rep[Boolean]

  // Non-speculative semantics for one instruction. Recurses through
  // [Common.call], never through [step].
  def step(pc: Int, s: Rep[State]): Rep[State]
}
