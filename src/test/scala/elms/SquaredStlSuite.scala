package elms.koika.test

import elms.prelude.*
import elms.prelude.given

import elms.koika.test.common.Init
import elms.koika.test.squared.{
  Forwarding,
  NonBlocking,
  Predictive,
  PredictiveNonBlocking,
  Static
}
import elms.koika.test.riscv.{SquaredRiscVDriver, Stl}

// The five Spectre-STL shapes answered by the squared interpreter, where
// [elms.koika.test.riscv.Stl] answers them by self-composition. A verdict here
// matching the one next door is what keeps the two towers from drifting, and
// here every row does: the five programs have no branch in them, so
// `Squared.agree` never gets to ask its second question and the two
// constructions are deciding exactly the same thing.
//
// `balanced` is where that stops being true for the main suite, and [SquaredSuite]
// is where it is written down. Nothing in this file touches it.
//
// Five models and not seven. The two the squared tower does not carry here are
// the two with nothing to say: a machine with no cache cannot see an address,
// and a machine with a cache and no queue is the `static` column these rows
// already have.
//
// A file of its own rather than rows in [SquaredSuite], so that both halves of
// the family sit behind `--corpus` together. Twenty-five files here against
// thirty-five next door, and a default run of all three `verify` scripts covers
// neither. The reason is volume: CBMC and Eva answer the sixty in under a
// minute between them, and not one of them is a verdict the tree cannot already
// state.
//
// KLEE is the one that costs, and it costs less here than it does next door,
// which is the opposite of what the residue sizes say. `forwarding/stale_ptr`,
// `stale_mask` and `stale_index` stop at their witness in 125, 112 and 209
// seconds squared, where single-tower `stale_ptr` and `stale_index` find
// nothing inside 360. [Stl.klee] takes the tower for that reason.
//
// Labels carry the model, so a residue lands beside its twin's path with
// `squared/` on the front, the way [SquaredSuite]'s do.
@virtualize
class SquaredStlSuite extends KoikaSuite {
  val under = "squared/stl/"

  trait StaticDriver extends SquaredRiscVDriver[64] with Static {
    override val init = Init.speculative(stateT)
  }

  trait PredictiveDriver extends SquaredRiscVDriver[64] with Predictive {
    override val init = Init.speculative(stateT)
  }

  trait ForwardingDriver extends SquaredRiscVDriver[64] with Forwarding {
    override val init = Init.forwarding(stateT)
  }

  trait NonBlockingDriver extends SquaredRiscVDriver[64] with NonBlocking {
    override val init = Init.nonblocking(stateT)
  }

  trait PredNbDriver extends SquaredRiscVDriver[64] with PredictiveNonBlocking {
    override val init = Init.all(stateT)
  }

  for ((name, expect) <- Stl.all) {
    test(s"squared stl static $name") {
      val snippet = new StaticDriver { override val prog = demo(name) }
      val says = expect.static
      check(s"static/$name", snippet, says, eva = Stl.eva(name, says, cached = true))
    }

    test(s"squared stl predictive $name") {
      val snippet = new PredictiveDriver { override val prog = demo(name) }
      val says = expect.predictive
      check(s"predictive/$name", snippet, says, eva = Stl.eva(name, says, cached = true))
    }

    // The column the five were ported for, and the only one that answers
    // anything but `clean`.
    test(s"squared stl forwarding $name") {
      val snippet = new ForwardingDriver { override val prog = demo(name) }
      val says = expect.forwarding
      check(
        s"forwarding/$name",
        snippet,
        says,
        klee = Stl.klee(name, squared = true),
        eva = Stl.eva(name, says, cached = true)
      )
    }

    test(s"squared stl nonblocking $name") {
      val snippet = new NonBlockingDriver { override val prog = demo(name) }
      val says = expect.nonblocking
      check(s"nonblocking/$name", snippet, says, eva = Stl.eva(name, says, cached = true))
    }

    test(s"squared stl predictive_nb $name") {
      val snippet = new PredNbDriver { override val prog = demo(name) }
      val says = expect.predictive_nb
      check(s"predictive_nb/$name", snippet, says, eva = Stl.eva(name, says, cached = true))
    }
  }
}
