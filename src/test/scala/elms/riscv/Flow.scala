package elms.koika.test.riscv

import scala.collection.mutable

import RiscV.*

// Where control can go, read off `prog` and nothing else.
//
// One question is asked here and it is [Returns.shareable]'s: may a callee be
// emitted as one function that really returns, for a model that carries a
// branch predictor's history at staging time?
//
// A shared function has one exit, and what the history reads there depends on
// which path through it ran. So the caller resumes with the history it had
// before the call, and that is wrong whenever anything downstream reads a
// branch the callee wrote. It is wrong in the direction that matters: two runs
// whose histories had come apart inside the callee are handed back the same
// one, so the difference the secret made is gone and the residue comes out
// clean. `retrain.s` is that program.
//
// It is only wrong when something reads what the callee wrote, which is what
// [historySafe] decides. A callee whose branches nothing downstream reaches
// again leaves a history nobody consults, and sharing it loses nothing.
object Flow {
  // Where [pc] can go inside its own function, and the call it makes on the
  // way. A `ret` goes nowhere: this walk stops at the function's edge and the
  // caller's continuation is a separate question.
  private def next(prog: Vector[Instr], pc: Int): (List[Int], Option[Int]) =
    prog(pc) match {
      case Instr.Ret                  => (Nil, None)
      case Instr.Jal(_, off)          => (List(pc + off.i / 4), None)
      case Instr.Branch(_, _, _, off) => (List(pc + 1, pc + off.i / 4), None)
      case Instr.Call(_, target)      => (List(pc + 1), Some(target))
      case _                          => (List(pc + 1), None)
    }

  // Whether a call can run at all once the walk starts at [from].
  //
  // [retAssert] is declared on the strength of this. An object holding nine
  // functions has calls in it that the leaf being entered cannot reach, and
  // declaring the helper anyway puts a `bool` in a residue that has no other
  // boolean in it and so never included <stdbool.h>. `fe_tobytes` is 666
  // instructions with no branch and no call, and it would not parse.
  def callsFrom(prog: Vector[Instr], from: Int): Boolean = {
    val seen = mutable.Set[Int]()
    val todo = mutable.Stack(from)
    while (todo.nonEmpty) {
      val pc = todo.pop()
      if (pc >= 0 && pc < prog.length && seen.add(pc)) {
        prog(pc) match {
          case Instr.Call(_, _) => return true
          case _                => ()
        }
        val (succ, called) = next(prog, pc)
        succ.foreach(todo.push)
        called.foreach(todo.push)
      }
    }
    false
  }

  // Branch pcs that can run between arriving at [from] and the function
  // holding it returning. Descends into calls, because a callee's branches are
  // written by the call as surely as by the caller, and stops at a `ret`.
  def trains(prog: Vector[Instr], from: Int): Set[Int] = {
    val seen = mutable.Set[Int]()
    val todo = mutable.Stack(from)
    val out = mutable.Set[Int]()
    while (todo.nonEmpty) {
      val pc = todo.pop()
      if (pc >= 0 && pc < prog.length && seen.add(pc)) {
        prog(pc) match {
          case Instr.Branch(_, _, _, _) => out += pc
          case _                        => ()
        }
        val (succ, called) = next(prog, pc)
        succ.foreach(todo.push)
        called.foreach(todo.push)
      }
    }
    out.toSet
  }

  // Branch pcs anything can reach once some call has returned.
  //
  // Program-wide and not per site, because where control goes after the caller
  // itself returns is not something one call site can see. Every instruction
  // one past a call is somewhere a return lands, so the union over those is
  // the continuation of every call in the program at once. Coarse, and coarse
  // in the safe direction: a branch this leaves out is one no return can reach.
  def consultedAfterAnyCall(prog: Vector[Instr]): Set[Int] =
    prog.indices.foldLeft(Set.empty[Int]) { (acc, pc) =>
      prog(pc) match {
        case Instr.Call(_, _) => acc ++ trains(prog, pc + 1)
        case _                => acc
      }
    }

  // The same question as [trains] and [consultedAfterAnyCall] together, asked
  // of a pc that knows which calls are still in flight.
  //
  // Those two are separate because [trains] stops at a `ret`, having no idea
  // where it goes, and [consultedAfterAnyCall] then answers "anywhere a call
  // returns to" for the whole program at once. The union is added to every
  // pc's key, so an object with calls keys every slot on every branch it has,
  // including branches that have already run and that nothing will read again.
  // `crypto_poly1305` is 609 instructions with six call sites, and its median
  // pc keys on all thirteen of its branches: 2^13 against 1792 slots.
  //
  // Given [stack], a `ret` has exactly one successor and the walk follows it.
  // A pc late in the program then reaches the few branches genuinely ahead of
  // it rather than all of them, which is what the liveness restriction was for.
  //
  // [None] when the walk needs a stack deeper than [maxDepth], which is the
  // recursion guard: a self-recursive program grows one without bound, and
  // every frame is a distinct state. The caller falls back to the conservative
  // pair, so a program this cannot answer about is slower to stage and not
  // wrong. A fixed point over the return edges would replace the guard.
  def trainsUnder(
      prog: Vector[Instr],
      from: Int,
      stack: List[Int],
      maxDepth: Int
  ): Option[Set[Int]] = {
    val seen = mutable.Set[(Int, List[Int])]()
    val todo = mutable.Stack((from, stack))
    val out = mutable.Set[Int]()
    while (todo.nonEmpty) {
      val (pc, st) = todo.pop()
      if (pc >= 0 && pc < prog.length && seen.add((pc, st))) {
        prog(pc) match {
          case Instr.Branch(_, _, _, _) => out += pc
          case _                        => ()
        }
        prog(pc) match {
          // The one edge the stack buys. An empty stack is the entry
          // returning, which ends the program rather than going anywhere.
          case Instr.Ret =>
            st match {
              case r :: rest => todo.push((r, rest))
              case Nil       => ()
            }
          // Into the callee, carrying where it comes back to. `pc + 1` is not
          // pushed here: it is reached through the callee's `ret`, which is
          // the whole point.
          case Instr.Call(_, target) =>
            if (st.length >= maxDepth) { return None }
            todo.push((target, (pc + 1) :: st))
          case Instr.Jal(_, off) => todo.push((pc + off.i / 4, st))
          case Instr.Branch(_, _, _, off) =>
            todo.push((pc + 1, st))
            todo.push((pc + off.i / 4, st))
          case _ => todo.push((pc + 1, st))
        }
      }
    }
    Some(out.toSet)
  }

  // Whether a call to [target] may be shared by a model that specializes on
  // the predictor's history. True when the branches the call can write are
  // ones nothing downstream of any return reads back.
  def historySafe(prog: Vector[Instr], target: Int, consulted: Set[Int]): Boolean =
    trains(prog, target).intersect(consulted).isEmpty
}
