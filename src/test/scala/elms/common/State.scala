package elms.koika.test.common

import elms.prelude.*
import elms.prelude.given
import elms.core.StructManifest

case class StateT(
    regs: Array[Int],
    mem: Array[Int],
    saved_regs: Array[Int],
    cache_keys: Array[Int],
    cache_vals: Array[Int],
    timer: Int
) derives StructManifest

trait StateTOps extends DslOps {
  extension (st: Rep[StateT])
    def regs: Rep[Array[Int]] = st.get("regs").asInstanceOf[Rep[Array[Int]]]
    def mem: Rep[Array[Int]] = st.get("mem").asInstanceOf[Rep[Array[Int]]]
    def saved_regs: Rep[Array[Int]] = st.get("saved_regs").asInstanceOf[Rep[Array[Int]]]
    def cache_keys: Rep[Array[Int]] = st.get("cache_keys").asInstanceOf[Rep[Array[Int]]]
    def cache_vals: Rep[Array[Int]] = st.get("cache_vals").asInstanceOf[Rep[Array[Int]]]
    def timer: Rep[Int] = st.get("timer").asInstanceOf[Rep[Int]]

    def mem_=(v: Rep[Array[Int]]): Rep[Unit] = st.set("mem", v)
    def saved_regs_=(v: Rep[Array[Int]]): Rep[Unit] = st.set("saved_regs", v)
    def cache_keys_=(v: Rep[Array[Int]]): Rep[Unit] = st.set("cache_keys", v)
    def cache_vals_=(v: Rep[Array[Int]]): Rep[Unit] = st.set("cache_vals", v)
    def timer_=(v: Rep[Int]): Rep[Unit] = st.set("timer", v)
}
