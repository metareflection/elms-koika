// verify: leak (CBMC should report VERIFICATION FAILED) [unwind 65]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef CBMC
int nondet_uint();
#define koika_assert(b, s) __CPROVER_assert(b, s)
#define koika_assume(b) __CPROVER_assume(b)
#define koika_draw(x) ((x) = nondet_uint())
#define koika_secret(x) ((void)0)
#else
#define koika_assert(b, s) 0
#define koika_assume(b) 0
#define koika_draw(x) ((x) = 0)
#define koika_secret(x) ((void)0)
#endif
int bounded(int low, int high) {
  int x;
  koika_draw(x);
  koika_assume(low <= x && x <= high);
  return x;
}
// Same draw as `bounded`, said of the secret, so a backend that tracks
// where the secret goes has somewhere to start. Self-composition already
// encodes the split by drawing these twice, which is why the mark is
// nothing under a checker that reads the two runs exactly.
int secret(int low, int high) {
  int x = bounded(low, high);
  koika_secret(x);
  return x;
}

/*****************************************
Emitting C Generated Code
*******************************************/

#include <stdbool.h>

struct StateT2 {
  struct StateT * a;
  struct StateT * b;
};

struct StateT {
  int regs[32];
  int mem[64];
  int saved_regs[32];
  int reg_ready[32];
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int timer;
};

void lockstep_assert(bool);
void lockstep_assume(bool);

struct StateT2 * slot_12(struct StateT2 * v550_p);
struct StateT2 * slot_14(struct StateT2 * v76_p);
struct StateT2 * slot_6(struct StateT2 * v103_p);
struct StateT2 * slot_5(struct StateT2 * v86_p);
struct StateT2 * slot_2(struct StateT2 * v28_p);
struct StateT2 * slot_7(struct StateT2 * v307_p);
struct StateT2 * slot_3(struct StateT2 * v41_p);
struct StateT2 * snippet(struct StateT2 * v0_p);
struct StateT2 * slot_10(struct StateT2 * v563_p);
struct StateT2 * slot_1(struct StateT2 * v15_p);
struct StateT2 * slot_8(struct StateT2 * v324_p);
struct StateT2 * slot_4(struct StateT2 * v54_p);
struct StateT2 * slot_13(struct StateT2 * v577_p);
struct StateT2 * slot_9(struct StateT2 * v528_p);
struct StateT2 * slot_11(struct StateT2 * v582_p);
struct StateT2 * slot_0(struct StateT2 * v2_p);
struct StateT2 * slot_12(struct StateT2 * v550_p) {
  lockstep_assert(((v550_p->a)->timer) == ((v550_p->b)->timer));
  lockstep_assume(((v550_p->a)->timer) == ((v550_p->b)->timer));
  int v551_a = (v550_p->a)->timer;
  int v551_b = (v550_p->b)->timer;
  int v557_a = v551_a + 1;
  int v557_b = v551_b + 1;
  (v550_p->a)->timer = v557_a;
  (v550_p->b)->timer = v557_b;
  int * v553_a = (v550_p->a)->regs;
  int * v553_b = (v550_p->b)->regs;
  v553_a[10] = 0;
  v553_b[10] = 0;
  struct StateT2 * v555_p = slot_13(v550_p);
  return v555_p;
}

struct StateT2 * slot_14(struct StateT2 * v76_p) {
  lockstep_assert(((v76_p->a)->timer) == ((v76_p->b)->timer));
  lockstep_assume(((v76_p->a)->timer) == ((v76_p->b)->timer));
  int v77_a = (v76_p->a)->timer;
  int v77_b = (v76_p->b)->timer;
  int v82_a = v77_a + 1;
  int v82_b = v77_b + 1;
  (v76_p->a)->timer = v82_a;
  (v76_p->b)->timer = v82_b;
  int * v79_a = (v76_p->a)->regs;
  int * v79_b = (v76_p->b)->regs;
  v79_a[10] = 1;
  v79_b[10] = 1;
  return v76_p;
}

struct StateT2 * slot_6(struct StateT2 * v103_p) {
  lockstep_assert(((v103_p->a)->timer) == ((v103_p->b)->timer));
  lockstep_assume(((v103_p->a)->timer) == ((v103_p->b)->timer));
  int v104_a = (v103_p->a)->timer;
  int v104_b = (v103_p->b)->timer;
  int v214_a = v104_a + 1;
  int v214_b = v104_b + 1;
  (v103_p->a)->timer = v214_a;
  (v103_p->b)->timer = v214_b;
  int * v106_a = (v103_p->a)->regs;
  int * v106_b = (v103_p->b)->regs;
  int v107_a = v106_a[5];
  int v107_b = v106_b[5];
  int * v108_a = (v103_p->a)->cache_tags;
  int * v108_b = (v103_p->b)->cache_tags;
  int v218_a = (((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1)) & 1) * 2;
  int v218_b = (((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1)) & 1) * 2;
  int v109_a = v108_a[v218_a];
  int v109_b = v108_b[v218_b];
  int v219_a = ((((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1)) & 1) * 2) + 1;
  int v219_b = ((((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1)) & 1) * 2) + 1;
  int v110_a = v108_a[v219_a];
  int v110_b = v108_b[v219_b];
  int v220_a = 4 + ((((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1)) & 3) * 2);
  int v220_b = 4 + ((((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1)) & 3) * 2);
  int v111_a = v108_a[v220_a];
  int v111_b = v108_b[v220_b];
  int v221_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1)) & 3) * 2)) + 1;
  int v221_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1)) & 3) * 2)) + 1;
  int v112_a = v108_a[v221_a];
  int v112_b = v108_b[v221_b];
  int v113_a = (v103_p->a)->timer;
  int v113_b = (v103_p->b)->timer;
  int v222_a = v113_a + ((100 ^ (((~(((v111_a ^ ((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1))) | (-(v111_a ^ ((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1))))) >> 31)) | (~(((v112_a ^ ((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1))) | (-(v112_a ^ ((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v109_a ^ ((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1))) | (-(v109_a ^ ((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1))))) >> 31)) | (~(((v110_a ^ ((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1))) | (-(v110_a ^ ((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v111_a ^ ((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1))) | (-(v111_a ^ ((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1))))) >> 31)) | (~(((v112_a ^ ((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1))) | (-(v112_a ^ ((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1))))) >> 31))) & 104)))));
  int v222_b = v113_b + ((100 ^ (((~(((v111_b ^ ((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1))) | (-(v111_b ^ ((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1))))) >> 31)) | (~(((v112_b ^ ((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1))) | (-(v112_b ^ ((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v109_b ^ ((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1))) | (-(v109_b ^ ((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1))))) >> 31)) | (~(((v110_b ^ ((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1))) | (-(v110_b ^ ((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v111_b ^ ((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1))) | (-(v111_b ^ ((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1))))) >> 31)) | (~(((v112_b ^ ((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1))) | (-(v112_b ^ ((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1))))) >> 31))) & 104)))));
  (v103_p->a)->timer = v222_a;
  (v103_p->b)->timer = v222_b;
  int * v115_a = (v103_p->a)->cache_vals;
  int * v115_b = (v103_p->b)->cache_vals;
  bool v223_a = !(((~(((v109_a ^ ((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1))) | (-(v109_a ^ ((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1))))) >> 31)) | (~(((v110_a ^ ((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1))) | (-(v110_a ^ ((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1))))) >> 31))) == 0);
  bool v223_b = !(((~(((v109_b ^ ((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1))) | (-(v109_b ^ ((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1))))) >> 31)) | (~(((v110_b ^ ((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1))) | (-(v110_b ^ ((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1))))) >> 31))) == 0);
  int v208_a;
  if (v223_a) {
    int * v116_a = (v103_p->a)->cache_age;
    int v225_a = ((((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1)) & 1) * 2) + ((~(((v110_a ^ ((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1))) | (-(v110_a ^ ((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1))))) >> 31)) & 1);
    int v117_a = v116_a[v225_a];
    int v118_a = v116_a[v218_a];
    int v226_a = v118_a + ((int)((unsigned int)(v118_a - v117_a) >> 31));
    v116_a[v218_a] = v226_a;
    int * v120_a = (v103_p->a)->cache_age;
    int v121_a = v120_a[v219_a];
    int v228_a = v121_a + ((int)((unsigned int)(v121_a - v117_a) >> 31));
    v120_a[v219_a] = v228_a;
    int * v123_a = (v103_p->a)->cache_age;
    v123_a[v225_a] = 0;
    v208_a = v225_a;
  } else {
    int * v126_a = (v103_p->a)->cache_age;
    int v232_a = (((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1)) & 1) * 2;
    int v127_a = v126_a[v232_a];
    int * v128_a = (v103_p->a)->cache_tags;
    int v129_a = v128_a[v232_a];
    int v130_a = v126_a[v219_a];
    int v131_a = v128_a[v219_a];
    bool v234_a = !(((~(((v111_a ^ ((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1))) | (-(v111_a ^ ((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1))))) >> 31)) | (~(((v112_a ^ ((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1))) | (-(v112_a ^ ((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1))))) >> 31))) == 0);
    int v185_a;
    if (v234_a) {
      int * v132_a = (v103_p->a)->cache_age;
      int v236_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1)) & 3) * 2)) + ((~(((v112_a ^ ((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1))) | (-(v112_a ^ ((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1))))) >> 31)) & 1);
      int v133_a = v132_a[v236_a];
      int v134_a = v132_a[v220_a];
      int v237_a = v134_a + ((int)((unsigned int)(v134_a - v133_a) >> 31));
      v132_a[v220_a] = v237_a;
      int * v136_a = (v103_p->a)->cache_age;
      int v137_a = v136_a[v221_a];
      int v239_a = v137_a + ((int)((unsigned int)(v137_a - v133_a) >> 31));
      v136_a[v221_a] = v239_a;
      int * v139_a = (v103_p->a)->cache_age;
      v139_a[v236_a] = 0;
      v185_a = v236_a;
    } else {
      int * v142_a = (v103_p->a)->cache_age;
      int v243_a = 4 + ((((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1)) & 3) * 2);
      int v143_a = v142_a[v243_a];
      int * v144_a = (v103_p->a)->cache_tags;
      int v145_a = v144_a[v243_a];
      int v146_a = v142_a[v221_a];
      int v147_a = v144_a[v221_a];
      int * v148_a = (v103_p->a)->cache_dirty;
      int v246_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1)) & 3) * 2)) + ((((v143_a + ((~(((v145_a ^ -1) | (-(v145_a ^ -1))) >> 31)) & 2)) - (v146_a + ((~(((v147_a ^ -1) | (-(v147_a ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v149_a = v148_a[v246_a];
      bool v247_a = !(v149_a == 0);
      if (v247_a) {
        int * v150_a = (v103_p->a)->cache_tags;
        int v151_a = v150_a[v246_a];
        int * v152_a = (v103_p->a)->cache_vals;
        int v250_a = ((4 + ((((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1)) & 3) * 2)) + ((((v143_a + ((~(((v145_a ^ -1) | (-(v145_a ^ -1))) >> 31)) & 2)) - (v146_a + ((~(((v147_a ^ -1) | (-(v147_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v153_a = v152_a[v250_a];
        int v251_a = (((4 + ((((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1)) & 3) * 2)) + ((((v143_a + ((~(((v145_a ^ -1) | (-(v145_a ^ -1))) >> 31)) & 2)) - (v146_a + ((~(((v147_a ^ -1) | (-(v147_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v154_a = v152_a[v251_a];
        int * v155_a = (v103_p->a)->mem;
        int v253_a = v151_a * 2;
        v155_a[v253_a] = v153_a;
        int * v157_a = (v103_p->a)->mem;
        int v256_a = (v151_a * 2) + 1;
        v157_a[v256_a] = v154_a;
        ;
      } else {
        ;
      }
      int * v162_a = (v103_p->a)->mem;
      int v261_a = ((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1)) * 2;
      int v163_a = v162_a[v261_a];
      int v262_a = (((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1)) * 2) + 1;
      int v164_a = v162_a[v262_a];
      int * v165_a = (v103_p->a)->cache_vals;
      int v264_a = ((4 + ((((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1)) & 3) * 2)) + ((((v143_a + ((~(((v145_a ^ -1) | (-(v145_a ^ -1))) >> 31)) & 2)) - (v146_a + ((~(((v147_a ^ -1) | (-(v147_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v165_a[v264_a] = v163_a;
      int * v167_a = (v103_p->a)->cache_vals;
      int v267_a = (((4 + ((((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1)) & 3) * 2)) + ((((v143_a + ((~(((v145_a ^ -1) | (-(v145_a ^ -1))) >> 31)) & 2)) - (v146_a + ((~(((v147_a ^ -1) | (-(v147_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v167_a[v267_a] = v164_a;
      int * v169_a = (v103_p->a)->cache_tags;
      int v270_a = (int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1);
      v169_a[v246_a] = v270_a;
      int * v171_a = (v103_p->a)->cache_dirty;
      v171_a[v246_a] = 0;
      int * v173_a = (v103_p->a)->cache_age;
      v173_a[v246_a] = 1;
      int * v175_a = (v103_p->a)->cache_age;
      int v176_a = v175_a[v246_a];
      int v177_a = v175_a[v220_a];
      int v276_a = v177_a + ((int)((unsigned int)(v177_a - v176_a) >> 31));
      v175_a[v220_a] = v276_a;
      int * v179_a = (v103_p->a)->cache_age;
      int v180_a = v179_a[v221_a];
      int v278_a = v180_a + ((int)((unsigned int)(v180_a - v176_a) >> 31));
      v179_a[v221_a] = v278_a;
      int * v182_a = (v103_p->a)->cache_age;
      v182_a[v246_a] = 0;
      v185_a = v246_a;
    }
    int * v186_a = (v103_p->a)->cache_vals;
    int v281_a = v185_a * 2;
    int v187_a = v186_a[v281_a];
    int v282_a = (v185_a * 2) + 1;
    int v188_a = v186_a[v282_a];
    int v283_a = (((((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1)) & 1) * 2) + ((((v127_a + ((~(((v129_a ^ -1) | (-(v129_a ^ -1))) >> 31)) & 2)) - (v130_a + ((~(((v131_a ^ -1) | (-(v131_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v186_a[v283_a] = v187_a;
    int * v190_a = (v103_p->a)->cache_vals;
    int v286_a = ((((((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1)) & 1) * 2) + ((((v127_a + ((~(((v129_a ^ -1) | (-(v129_a ^ -1))) >> 31)) & 2)) - (v130_a + ((~(((v131_a ^ -1) | (-(v131_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v190_a[v286_a] = v188_a;
    int * v192_a = (v103_p->a)->cache_tags;
    int v289_a = ((((int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1)) & 1) * 2) + ((((v127_a + ((~(((v129_a ^ -1) | (-(v129_a ^ -1))) >> 31)) & 2)) - (v130_a + ((~(((v131_a ^ -1) | (-(v131_a ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v290_a = (int)((unsigned int)((int)((unsigned int)v107_a >> 2)) >> 1);
    v192_a[v289_a] = v290_a;
    int * v194_a = (v103_p->a)->cache_dirty;
    v194_a[v289_a] = 0;
    int * v196_a = (v103_p->a)->cache_age;
    v196_a[v289_a] = 1;
    int * v198_a = (v103_p->a)->cache_age;
    int v199_a = v198_a[v289_a];
    int v200_a = v198_a[v218_a];
    int v296_a = v200_a + ((int)((unsigned int)(v200_a - v199_a) >> 31));
    v198_a[v218_a] = v296_a;
    int * v202_a = (v103_p->a)->cache_age;
    int v203_a = v202_a[v219_a];
    int v298_a = v203_a + ((int)((unsigned int)(v203_a - v199_a) >> 31));
    v202_a[v219_a] = v298_a;
    int * v205_a = (v103_p->a)->cache_age;
    v205_a[v289_a] = 0;
    v208_a = v289_a;
  }
  int v208_b;
  if (v223_b) {
    int * v116_b = (v103_p->b)->cache_age;
    int v225_b = ((((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1)) & 1) * 2) + ((~(((v110_b ^ ((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1))) | (-(v110_b ^ ((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1))))) >> 31)) & 1);
    int v117_b = v116_b[v225_b];
    int v118_b = v116_b[v218_b];
    int v226_b = v118_b + ((int)((unsigned int)(v118_b - v117_b) >> 31));
    v116_b[v218_b] = v226_b;
    int * v120_b = (v103_p->b)->cache_age;
    int v121_b = v120_b[v219_b];
    int v228_b = v121_b + ((int)((unsigned int)(v121_b - v117_b) >> 31));
    v120_b[v219_b] = v228_b;
    int * v123_b = (v103_p->b)->cache_age;
    v123_b[v225_b] = 0;
    v208_b = v225_b;
  } else {
    int * v126_b = (v103_p->b)->cache_age;
    int v232_b = (((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1)) & 1) * 2;
    int v127_b = v126_b[v232_b];
    int * v128_b = (v103_p->b)->cache_tags;
    int v129_b = v128_b[v232_b];
    int v130_b = v126_b[v219_b];
    int v131_b = v128_b[v219_b];
    bool v234_b = !(((~(((v111_b ^ ((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1))) | (-(v111_b ^ ((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1))))) >> 31)) | (~(((v112_b ^ ((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1))) | (-(v112_b ^ ((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1))))) >> 31))) == 0);
    int v185_b;
    if (v234_b) {
      int * v132_b = (v103_p->b)->cache_age;
      int v236_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1)) & 3) * 2)) + ((~(((v112_b ^ ((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1))) | (-(v112_b ^ ((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1))))) >> 31)) & 1);
      int v133_b = v132_b[v236_b];
      int v134_b = v132_b[v220_b];
      int v237_b = v134_b + ((int)((unsigned int)(v134_b - v133_b) >> 31));
      v132_b[v220_b] = v237_b;
      int * v136_b = (v103_p->b)->cache_age;
      int v137_b = v136_b[v221_b];
      int v239_b = v137_b + ((int)((unsigned int)(v137_b - v133_b) >> 31));
      v136_b[v221_b] = v239_b;
      int * v139_b = (v103_p->b)->cache_age;
      v139_b[v236_b] = 0;
      v185_b = v236_b;
    } else {
      int * v142_b = (v103_p->b)->cache_age;
      int v243_b = 4 + ((((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1)) & 3) * 2);
      int v143_b = v142_b[v243_b];
      int * v144_b = (v103_p->b)->cache_tags;
      int v145_b = v144_b[v243_b];
      int v146_b = v142_b[v221_b];
      int v147_b = v144_b[v221_b];
      int * v148_b = (v103_p->b)->cache_dirty;
      int v246_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1)) & 3) * 2)) + ((((v143_b + ((~(((v145_b ^ -1) | (-(v145_b ^ -1))) >> 31)) & 2)) - (v146_b + ((~(((v147_b ^ -1) | (-(v147_b ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v149_b = v148_b[v246_b];
      bool v247_b = !(v149_b == 0);
      if (v247_b) {
        int * v150_b = (v103_p->b)->cache_tags;
        int v151_b = v150_b[v246_b];
        int * v152_b = (v103_p->b)->cache_vals;
        int v250_b = ((4 + ((((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1)) & 3) * 2)) + ((((v143_b + ((~(((v145_b ^ -1) | (-(v145_b ^ -1))) >> 31)) & 2)) - (v146_b + ((~(((v147_b ^ -1) | (-(v147_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v153_b = v152_b[v250_b];
        int v251_b = (((4 + ((((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1)) & 3) * 2)) + ((((v143_b + ((~(((v145_b ^ -1) | (-(v145_b ^ -1))) >> 31)) & 2)) - (v146_b + ((~(((v147_b ^ -1) | (-(v147_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v154_b = v152_b[v251_b];
        int * v155_b = (v103_p->b)->mem;
        int v253_b = v151_b * 2;
        v155_b[v253_b] = v153_b;
        int * v157_b = (v103_p->b)->mem;
        int v256_b = (v151_b * 2) + 1;
        v157_b[v256_b] = v154_b;
        ;
      } else {
        ;
      }
      int * v162_b = (v103_p->b)->mem;
      int v261_b = ((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1)) * 2;
      int v163_b = v162_b[v261_b];
      int v262_b = (((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1)) * 2) + 1;
      int v164_b = v162_b[v262_b];
      int * v165_b = (v103_p->b)->cache_vals;
      int v264_b = ((4 + ((((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1)) & 3) * 2)) + ((((v143_b + ((~(((v145_b ^ -1) | (-(v145_b ^ -1))) >> 31)) & 2)) - (v146_b + ((~(((v147_b ^ -1) | (-(v147_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v165_b[v264_b] = v163_b;
      int * v167_b = (v103_p->b)->cache_vals;
      int v267_b = (((4 + ((((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1)) & 3) * 2)) + ((((v143_b + ((~(((v145_b ^ -1) | (-(v145_b ^ -1))) >> 31)) & 2)) - (v146_b + ((~(((v147_b ^ -1) | (-(v147_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v167_b[v267_b] = v164_b;
      int * v169_b = (v103_p->b)->cache_tags;
      int v270_b = (int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1);
      v169_b[v246_b] = v270_b;
      int * v171_b = (v103_p->b)->cache_dirty;
      v171_b[v246_b] = 0;
      int * v173_b = (v103_p->b)->cache_age;
      v173_b[v246_b] = 1;
      int * v175_b = (v103_p->b)->cache_age;
      int v176_b = v175_b[v246_b];
      int v177_b = v175_b[v220_b];
      int v276_b = v177_b + ((int)((unsigned int)(v177_b - v176_b) >> 31));
      v175_b[v220_b] = v276_b;
      int * v179_b = (v103_p->b)->cache_age;
      int v180_b = v179_b[v221_b];
      int v278_b = v180_b + ((int)((unsigned int)(v180_b - v176_b) >> 31));
      v179_b[v221_b] = v278_b;
      int * v182_b = (v103_p->b)->cache_age;
      v182_b[v246_b] = 0;
      v185_b = v246_b;
    }
    int * v186_b = (v103_p->b)->cache_vals;
    int v281_b = v185_b * 2;
    int v187_b = v186_b[v281_b];
    int v282_b = (v185_b * 2) + 1;
    int v188_b = v186_b[v282_b];
    int v283_b = (((((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1)) & 1) * 2) + ((((v127_b + ((~(((v129_b ^ -1) | (-(v129_b ^ -1))) >> 31)) & 2)) - (v130_b + ((~(((v131_b ^ -1) | (-(v131_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v186_b[v283_b] = v187_b;
    int * v190_b = (v103_p->b)->cache_vals;
    int v286_b = ((((((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1)) & 1) * 2) + ((((v127_b + ((~(((v129_b ^ -1) | (-(v129_b ^ -1))) >> 31)) & 2)) - (v130_b + ((~(((v131_b ^ -1) | (-(v131_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v190_b[v286_b] = v188_b;
    int * v192_b = (v103_p->b)->cache_tags;
    int v289_b = ((((int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1)) & 1) * 2) + ((((v127_b + ((~(((v129_b ^ -1) | (-(v129_b ^ -1))) >> 31)) & 2)) - (v130_b + ((~(((v131_b ^ -1) | (-(v131_b ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v290_b = (int)((unsigned int)((int)((unsigned int)v107_b >> 2)) >> 1);
    v192_b[v289_b] = v290_b;
    int * v194_b = (v103_p->b)->cache_dirty;
    v194_b[v289_b] = 0;
    int * v196_b = (v103_p->b)->cache_age;
    v196_b[v289_b] = 1;
    int * v198_b = (v103_p->b)->cache_age;
    int v199_b = v198_b[v289_b];
    int v200_b = v198_b[v218_b];
    int v296_b = v200_b + ((int)((unsigned int)(v200_b - v199_b) >> 31));
    v198_b[v218_b] = v296_b;
    int * v202_b = (v103_p->b)->cache_age;
    int v203_b = v202_b[v219_b];
    int v298_b = v203_b + ((int)((unsigned int)(v203_b - v199_b) >> 31));
    v202_b[v219_b] = v298_b;
    int * v205_b = (v103_p->b)->cache_age;
    v205_b[v289_b] = 0;
    v208_b = v289_b;
  }
  int v301_a = (v208_a * 2) + (((int)((unsigned int)v107_a >> 2)) & 1);
  int v301_b = (v208_b * 2) + (((int)((unsigned int)v107_b >> 2)) & 1);
  int v209_a = v115_a[v301_a];
  int v209_b = v115_b[v301_b];
  int * v210_a = (v103_p->a)->regs;
  int * v210_b = (v103_p->b)->regs;
  v210_a[10] = v209_a;
  v210_b[10] = v209_b;
  struct StateT2 * v212_p = slot_7(v103_p);
  return v212_p;
}

struct StateT2 * slot_5(struct StateT2 * v86_p) {
  lockstep_assert(((v86_p->a)->timer) == ((v86_p->b)->timer));
  lockstep_assume(((v86_p->a)->timer) == ((v86_p->b)->timer));
  int v87_a = (v86_p->a)->timer;
  int v87_b = (v86_p->b)->timer;
  int v95_a = v87_a + 1;
  int v95_b = v87_b + 1;
  (v86_p->a)->timer = v95_a;
  (v86_p->b)->timer = v95_b;
  int * v89_a = (v86_p->a)->regs;
  int * v89_b = (v86_p->b)->regs;
  int v90_a = v89_a[12];
  int v90_b = v89_b[12];
  int v91_a = v89_a[14];
  int v91_b = v89_b[14];
  int v100_a = v90_a + v91_a;
  int v100_b = v90_b + v91_b;
  v89_a[5] = v100_a;
  v89_b[5] = v100_b;
  struct StateT2 * v93_p = slot_6(v86_p);
  return v93_p;
}

struct StateT2 * slot_2(struct StateT2 * v28_p) {
  lockstep_assert(((v28_p->a)->timer) == ((v28_p->b)->timer));
  lockstep_assume(((v28_p->a)->timer) == ((v28_p->b)->timer));
  int v29_a = (v28_p->a)->timer;
  int v29_b = (v28_p->b)->timer;
  int v35_a = v29_a + 1;
  int v35_b = v29_b + 1;
  (v28_p->a)->timer = v35_a;
  (v28_p->b)->timer = v35_b;
  int * v31_a = (v28_p->a)->regs;
  int * v31_b = (v28_p->b)->regs;
  v31_a[14] = 0;
  v31_b[14] = 0;
  struct StateT2 * v33_p = slot_3(v28_p);
  return v33_p;
}

struct StateT2 * slot_7(struct StateT2 * v307_p) {
  lockstep_assert(((v307_p->a)->timer) == ((v307_p->b)->timer));
  lockstep_assume(((v307_p->a)->timer) == ((v307_p->b)->timer));
  int v308_a = (v307_p->a)->timer;
  int v308_b = (v307_p->b)->timer;
  int v316_a = v308_a + 1;
  int v316_b = v308_b + 1;
  (v307_p->a)->timer = v316_a;
  (v307_p->b)->timer = v316_b;
  int * v310_a = (v307_p->a)->regs;
  int * v310_b = (v307_p->b)->regs;
  int v311_a = v310_a[13];
  int v311_b = v310_b[13];
  int v312_a = v310_a[14];
  int v312_b = v310_b[14];
  int v321_a = v311_a + v312_a;
  int v321_b = v311_b + v312_b;
  v310_a[6] = v321_a;
  v310_b[6] = v321_b;
  struct StateT2 * v314_p = slot_8(v307_p);
  return v314_p;
}

struct StateT2 * slot_3(struct StateT2 * v41_p) {
  lockstep_assert(((v41_p->a)->timer) == ((v41_p->b)->timer));
  lockstep_assume(((v41_p->a)->timer) == ((v41_p->b)->timer));
  int v42_a = (v41_p->a)->timer;
  int v42_b = (v41_p->b)->timer;
  int v48_a = v42_a + 1;
  int v48_b = v42_b + 1;
  (v41_p->a)->timer = v48_a;
  (v41_p->b)->timer = v48_b;
  int * v44_a = (v41_p->a)->regs;
  int * v44_b = (v41_p->b)->regs;
  v44_a[15] = 16;
  v44_b[15] = 16;
  struct StateT2 * v46_p = slot_4(v41_p);
  return v46_p;
}

struct StateT2 * snippet(struct StateT2 * v0_p) {
  lockstep_assert(((v0_p->a)->timer) == ((v0_p->b)->timer));
  lockstep_assume(((v0_p->a)->timer) == ((v0_p->b)->timer));
  struct StateT2 * v1_p = slot_0(v0_p);
  return v1_p;
}

struct StateT2 * slot_10(struct StateT2 * v563_p) {
  lockstep_assert(((v563_p->a)->timer) == ((v563_p->b)->timer));
  lockstep_assume(((v563_p->a)->timer) == ((v563_p->b)->timer));
  int v564_a = (v563_p->a)->timer;
  int v564_b = (v563_p->b)->timer;
  int v571_a = v564_a + 1;
  int v571_b = v564_b + 1;
  (v563_p->a)->timer = v571_a;
  (v563_p->b)->timer = v571_b;
  int * v566_a = (v563_p->a)->regs;
  int * v566_b = (v563_p->b)->regs;
  int v567_a = v566_a[14];
  int v567_b = v566_b[14];
  int v574_a = v567_a + 4;
  int v574_b = v567_b + 4;
  v566_a[14] = v574_a;
  v566_b[14] = v574_b;
  struct StateT2 * v569_p = slot_11(v563_p);
  return v569_p;
}

struct StateT2 * slot_1(struct StateT2 * v15_p) {
  lockstep_assert(((v15_p->a)->timer) == ((v15_p->b)->timer));
  lockstep_assume(((v15_p->a)->timer) == ((v15_p->b)->timer));
  int v16_a = (v15_p->a)->timer;
  int v16_b = (v15_p->b)->timer;
  int v22_a = v16_a + 1;
  int v22_b = v16_b + 1;
  (v15_p->a)->timer = v22_a;
  (v15_p->b)->timer = v22_b;
  int * v18_a = (v15_p->a)->regs;
  int * v18_b = (v15_p->b)->regs;
  v18_a[13] = 80;
  v18_b[13] = 80;
  struct StateT2 * v20_p = slot_2(v15_p);
  return v20_p;
}

struct StateT2 * slot_8(struct StateT2 * v324_p) {
  lockstep_assert(((v324_p->a)->timer) == ((v324_p->b)->timer));
  lockstep_assume(((v324_p->a)->timer) == ((v324_p->b)->timer));
  int v325_a = (v324_p->a)->timer;
  int v325_b = (v324_p->b)->timer;
  int v435_a = v325_a + 1;
  int v435_b = v325_b + 1;
  (v324_p->a)->timer = v435_a;
  (v324_p->b)->timer = v435_b;
  int * v327_a = (v324_p->a)->regs;
  int * v327_b = (v324_p->b)->regs;
  int v328_a = v327_a[6];
  int v328_b = v327_b[6];
  int * v329_a = (v324_p->a)->cache_tags;
  int * v329_b = (v324_p->b)->cache_tags;
  int v439_a = (((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1)) & 1) * 2;
  int v439_b = (((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1)) & 1) * 2;
  int v330_a = v329_a[v439_a];
  int v330_b = v329_b[v439_b];
  int v440_a = ((((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1)) & 1) * 2) + 1;
  int v440_b = ((((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1)) & 1) * 2) + 1;
  int v331_a = v329_a[v440_a];
  int v331_b = v329_b[v440_b];
  int v441_a = 4 + ((((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1)) & 3) * 2);
  int v441_b = 4 + ((((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1)) & 3) * 2);
  int v332_a = v329_a[v441_a];
  int v332_b = v329_b[v441_b];
  int v442_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1)) & 3) * 2)) + 1;
  int v442_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1)) & 3) * 2)) + 1;
  int v333_a = v329_a[v442_a];
  int v333_b = v329_b[v442_b];
  int v334_a = (v324_p->a)->timer;
  int v334_b = (v324_p->b)->timer;
  int v443_a = v334_a + ((100 ^ (((~(((v332_a ^ ((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1))) | (-(v332_a ^ ((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1))))) >> 31)) | (~(((v333_a ^ ((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1))) | (-(v333_a ^ ((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v330_a ^ ((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1))) | (-(v330_a ^ ((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1))))) >> 31)) | (~(((v331_a ^ ((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1))) | (-(v331_a ^ ((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v332_a ^ ((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1))) | (-(v332_a ^ ((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1))))) >> 31)) | (~(((v333_a ^ ((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1))) | (-(v333_a ^ ((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1))))) >> 31))) & 104)))));
  int v443_b = v334_b + ((100 ^ (((~(((v332_b ^ ((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1))) | (-(v332_b ^ ((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1))))) >> 31)) | (~(((v333_b ^ ((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1))) | (-(v333_b ^ ((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v330_b ^ ((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1))) | (-(v330_b ^ ((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1))))) >> 31)) | (~(((v331_b ^ ((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1))) | (-(v331_b ^ ((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v332_b ^ ((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1))) | (-(v332_b ^ ((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1))))) >> 31)) | (~(((v333_b ^ ((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1))) | (-(v333_b ^ ((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1))))) >> 31))) & 104)))));
  (v324_p->a)->timer = v443_a;
  (v324_p->b)->timer = v443_b;
  int * v336_a = (v324_p->a)->cache_vals;
  int * v336_b = (v324_p->b)->cache_vals;
  bool v444_a = !(((~(((v330_a ^ ((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1))) | (-(v330_a ^ ((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1))))) >> 31)) | (~(((v331_a ^ ((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1))) | (-(v331_a ^ ((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1))))) >> 31))) == 0);
  bool v444_b = !(((~(((v330_b ^ ((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1))) | (-(v330_b ^ ((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1))))) >> 31)) | (~(((v331_b ^ ((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1))) | (-(v331_b ^ ((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1))))) >> 31))) == 0);
  int v429_a;
  if (v444_a) {
    int * v337_a = (v324_p->a)->cache_age;
    int v446_a = ((((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1)) & 1) * 2) + ((~(((v331_a ^ ((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1))) | (-(v331_a ^ ((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1))))) >> 31)) & 1);
    int v338_a = v337_a[v446_a];
    int v339_a = v337_a[v439_a];
    int v447_a = v339_a + ((int)((unsigned int)(v339_a - v338_a) >> 31));
    v337_a[v439_a] = v447_a;
    int * v341_a = (v324_p->a)->cache_age;
    int v342_a = v341_a[v440_a];
    int v449_a = v342_a + ((int)((unsigned int)(v342_a - v338_a) >> 31));
    v341_a[v440_a] = v449_a;
    int * v344_a = (v324_p->a)->cache_age;
    v344_a[v446_a] = 0;
    v429_a = v446_a;
  } else {
    int * v347_a = (v324_p->a)->cache_age;
    int v453_a = (((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1)) & 1) * 2;
    int v348_a = v347_a[v453_a];
    int * v349_a = (v324_p->a)->cache_tags;
    int v350_a = v349_a[v453_a];
    int v351_a = v347_a[v440_a];
    int v352_a = v349_a[v440_a];
    bool v455_a = !(((~(((v332_a ^ ((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1))) | (-(v332_a ^ ((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1))))) >> 31)) | (~(((v333_a ^ ((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1))) | (-(v333_a ^ ((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1))))) >> 31))) == 0);
    int v406_a;
    if (v455_a) {
      int * v353_a = (v324_p->a)->cache_age;
      int v457_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1)) & 3) * 2)) + ((~(((v333_a ^ ((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1))) | (-(v333_a ^ ((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1))))) >> 31)) & 1);
      int v354_a = v353_a[v457_a];
      int v355_a = v353_a[v441_a];
      int v458_a = v355_a + ((int)((unsigned int)(v355_a - v354_a) >> 31));
      v353_a[v441_a] = v458_a;
      int * v357_a = (v324_p->a)->cache_age;
      int v358_a = v357_a[v442_a];
      int v460_a = v358_a + ((int)((unsigned int)(v358_a - v354_a) >> 31));
      v357_a[v442_a] = v460_a;
      int * v360_a = (v324_p->a)->cache_age;
      v360_a[v457_a] = 0;
      v406_a = v457_a;
    } else {
      int * v363_a = (v324_p->a)->cache_age;
      int v464_a = 4 + ((((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1)) & 3) * 2);
      int v364_a = v363_a[v464_a];
      int * v365_a = (v324_p->a)->cache_tags;
      int v366_a = v365_a[v464_a];
      int v367_a = v363_a[v442_a];
      int v368_a = v365_a[v442_a];
      int * v369_a = (v324_p->a)->cache_dirty;
      int v467_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1)) & 3) * 2)) + ((((v364_a + ((~(((v366_a ^ -1) | (-(v366_a ^ -1))) >> 31)) & 2)) - (v367_a + ((~(((v368_a ^ -1) | (-(v368_a ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v370_a = v369_a[v467_a];
      bool v468_a = !(v370_a == 0);
      if (v468_a) {
        int * v371_a = (v324_p->a)->cache_tags;
        int v372_a = v371_a[v467_a];
        int * v373_a = (v324_p->a)->cache_vals;
        int v471_a = ((4 + ((((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1)) & 3) * 2)) + ((((v364_a + ((~(((v366_a ^ -1) | (-(v366_a ^ -1))) >> 31)) & 2)) - (v367_a + ((~(((v368_a ^ -1) | (-(v368_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v374_a = v373_a[v471_a];
        int v472_a = (((4 + ((((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1)) & 3) * 2)) + ((((v364_a + ((~(((v366_a ^ -1) | (-(v366_a ^ -1))) >> 31)) & 2)) - (v367_a + ((~(((v368_a ^ -1) | (-(v368_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v375_a = v373_a[v472_a];
        int * v376_a = (v324_p->a)->mem;
        int v474_a = v372_a * 2;
        v376_a[v474_a] = v374_a;
        int * v378_a = (v324_p->a)->mem;
        int v477_a = (v372_a * 2) + 1;
        v378_a[v477_a] = v375_a;
        ;
      } else {
        ;
      }
      int * v383_a = (v324_p->a)->mem;
      int v482_a = ((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1)) * 2;
      int v384_a = v383_a[v482_a];
      int v483_a = (((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1)) * 2) + 1;
      int v385_a = v383_a[v483_a];
      int * v386_a = (v324_p->a)->cache_vals;
      int v485_a = ((4 + ((((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1)) & 3) * 2)) + ((((v364_a + ((~(((v366_a ^ -1) | (-(v366_a ^ -1))) >> 31)) & 2)) - (v367_a + ((~(((v368_a ^ -1) | (-(v368_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v386_a[v485_a] = v384_a;
      int * v388_a = (v324_p->a)->cache_vals;
      int v488_a = (((4 + ((((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1)) & 3) * 2)) + ((((v364_a + ((~(((v366_a ^ -1) | (-(v366_a ^ -1))) >> 31)) & 2)) - (v367_a + ((~(((v368_a ^ -1) | (-(v368_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v388_a[v488_a] = v385_a;
      int * v390_a = (v324_p->a)->cache_tags;
      int v491_a = (int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1);
      v390_a[v467_a] = v491_a;
      int * v392_a = (v324_p->a)->cache_dirty;
      v392_a[v467_a] = 0;
      int * v394_a = (v324_p->a)->cache_age;
      v394_a[v467_a] = 1;
      int * v396_a = (v324_p->a)->cache_age;
      int v397_a = v396_a[v467_a];
      int v398_a = v396_a[v441_a];
      int v497_a = v398_a + ((int)((unsigned int)(v398_a - v397_a) >> 31));
      v396_a[v441_a] = v497_a;
      int * v400_a = (v324_p->a)->cache_age;
      int v401_a = v400_a[v442_a];
      int v499_a = v401_a + ((int)((unsigned int)(v401_a - v397_a) >> 31));
      v400_a[v442_a] = v499_a;
      int * v403_a = (v324_p->a)->cache_age;
      v403_a[v467_a] = 0;
      v406_a = v467_a;
    }
    int * v407_a = (v324_p->a)->cache_vals;
    int v502_a = v406_a * 2;
    int v408_a = v407_a[v502_a];
    int v503_a = (v406_a * 2) + 1;
    int v409_a = v407_a[v503_a];
    int v504_a = (((((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1)) & 1) * 2) + ((((v348_a + ((~(((v350_a ^ -1) | (-(v350_a ^ -1))) >> 31)) & 2)) - (v351_a + ((~(((v352_a ^ -1) | (-(v352_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v407_a[v504_a] = v408_a;
    int * v411_a = (v324_p->a)->cache_vals;
    int v507_a = ((((((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1)) & 1) * 2) + ((((v348_a + ((~(((v350_a ^ -1) | (-(v350_a ^ -1))) >> 31)) & 2)) - (v351_a + ((~(((v352_a ^ -1) | (-(v352_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v411_a[v507_a] = v409_a;
    int * v413_a = (v324_p->a)->cache_tags;
    int v510_a = ((((int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1)) & 1) * 2) + ((((v348_a + ((~(((v350_a ^ -1) | (-(v350_a ^ -1))) >> 31)) & 2)) - (v351_a + ((~(((v352_a ^ -1) | (-(v352_a ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v511_a = (int)((unsigned int)((int)((unsigned int)v328_a >> 2)) >> 1);
    v413_a[v510_a] = v511_a;
    int * v415_a = (v324_p->a)->cache_dirty;
    v415_a[v510_a] = 0;
    int * v417_a = (v324_p->a)->cache_age;
    v417_a[v510_a] = 1;
    int * v419_a = (v324_p->a)->cache_age;
    int v420_a = v419_a[v510_a];
    int v421_a = v419_a[v439_a];
    int v517_a = v421_a + ((int)((unsigned int)(v421_a - v420_a) >> 31));
    v419_a[v439_a] = v517_a;
    int * v423_a = (v324_p->a)->cache_age;
    int v424_a = v423_a[v440_a];
    int v519_a = v424_a + ((int)((unsigned int)(v424_a - v420_a) >> 31));
    v423_a[v440_a] = v519_a;
    int * v426_a = (v324_p->a)->cache_age;
    v426_a[v510_a] = 0;
    v429_a = v510_a;
  }
  int v429_b;
  if (v444_b) {
    int * v337_b = (v324_p->b)->cache_age;
    int v446_b = ((((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1)) & 1) * 2) + ((~(((v331_b ^ ((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1))) | (-(v331_b ^ ((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1))))) >> 31)) & 1);
    int v338_b = v337_b[v446_b];
    int v339_b = v337_b[v439_b];
    int v447_b = v339_b + ((int)((unsigned int)(v339_b - v338_b) >> 31));
    v337_b[v439_b] = v447_b;
    int * v341_b = (v324_p->b)->cache_age;
    int v342_b = v341_b[v440_b];
    int v449_b = v342_b + ((int)((unsigned int)(v342_b - v338_b) >> 31));
    v341_b[v440_b] = v449_b;
    int * v344_b = (v324_p->b)->cache_age;
    v344_b[v446_b] = 0;
    v429_b = v446_b;
  } else {
    int * v347_b = (v324_p->b)->cache_age;
    int v453_b = (((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1)) & 1) * 2;
    int v348_b = v347_b[v453_b];
    int * v349_b = (v324_p->b)->cache_tags;
    int v350_b = v349_b[v453_b];
    int v351_b = v347_b[v440_b];
    int v352_b = v349_b[v440_b];
    bool v455_b = !(((~(((v332_b ^ ((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1))) | (-(v332_b ^ ((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1))))) >> 31)) | (~(((v333_b ^ ((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1))) | (-(v333_b ^ ((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1))))) >> 31))) == 0);
    int v406_b;
    if (v455_b) {
      int * v353_b = (v324_p->b)->cache_age;
      int v457_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1)) & 3) * 2)) + ((~(((v333_b ^ ((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1))) | (-(v333_b ^ ((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1))))) >> 31)) & 1);
      int v354_b = v353_b[v457_b];
      int v355_b = v353_b[v441_b];
      int v458_b = v355_b + ((int)((unsigned int)(v355_b - v354_b) >> 31));
      v353_b[v441_b] = v458_b;
      int * v357_b = (v324_p->b)->cache_age;
      int v358_b = v357_b[v442_b];
      int v460_b = v358_b + ((int)((unsigned int)(v358_b - v354_b) >> 31));
      v357_b[v442_b] = v460_b;
      int * v360_b = (v324_p->b)->cache_age;
      v360_b[v457_b] = 0;
      v406_b = v457_b;
    } else {
      int * v363_b = (v324_p->b)->cache_age;
      int v464_b = 4 + ((((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1)) & 3) * 2);
      int v364_b = v363_b[v464_b];
      int * v365_b = (v324_p->b)->cache_tags;
      int v366_b = v365_b[v464_b];
      int v367_b = v363_b[v442_b];
      int v368_b = v365_b[v442_b];
      int * v369_b = (v324_p->b)->cache_dirty;
      int v467_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1)) & 3) * 2)) + ((((v364_b + ((~(((v366_b ^ -1) | (-(v366_b ^ -1))) >> 31)) & 2)) - (v367_b + ((~(((v368_b ^ -1) | (-(v368_b ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v370_b = v369_b[v467_b];
      bool v468_b = !(v370_b == 0);
      if (v468_b) {
        int * v371_b = (v324_p->b)->cache_tags;
        int v372_b = v371_b[v467_b];
        int * v373_b = (v324_p->b)->cache_vals;
        int v471_b = ((4 + ((((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1)) & 3) * 2)) + ((((v364_b + ((~(((v366_b ^ -1) | (-(v366_b ^ -1))) >> 31)) & 2)) - (v367_b + ((~(((v368_b ^ -1) | (-(v368_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v374_b = v373_b[v471_b];
        int v472_b = (((4 + ((((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1)) & 3) * 2)) + ((((v364_b + ((~(((v366_b ^ -1) | (-(v366_b ^ -1))) >> 31)) & 2)) - (v367_b + ((~(((v368_b ^ -1) | (-(v368_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v375_b = v373_b[v472_b];
        int * v376_b = (v324_p->b)->mem;
        int v474_b = v372_b * 2;
        v376_b[v474_b] = v374_b;
        int * v378_b = (v324_p->b)->mem;
        int v477_b = (v372_b * 2) + 1;
        v378_b[v477_b] = v375_b;
        ;
      } else {
        ;
      }
      int * v383_b = (v324_p->b)->mem;
      int v482_b = ((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1)) * 2;
      int v384_b = v383_b[v482_b];
      int v483_b = (((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1)) * 2) + 1;
      int v385_b = v383_b[v483_b];
      int * v386_b = (v324_p->b)->cache_vals;
      int v485_b = ((4 + ((((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1)) & 3) * 2)) + ((((v364_b + ((~(((v366_b ^ -1) | (-(v366_b ^ -1))) >> 31)) & 2)) - (v367_b + ((~(((v368_b ^ -1) | (-(v368_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v386_b[v485_b] = v384_b;
      int * v388_b = (v324_p->b)->cache_vals;
      int v488_b = (((4 + ((((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1)) & 3) * 2)) + ((((v364_b + ((~(((v366_b ^ -1) | (-(v366_b ^ -1))) >> 31)) & 2)) - (v367_b + ((~(((v368_b ^ -1) | (-(v368_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v388_b[v488_b] = v385_b;
      int * v390_b = (v324_p->b)->cache_tags;
      int v491_b = (int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1);
      v390_b[v467_b] = v491_b;
      int * v392_b = (v324_p->b)->cache_dirty;
      v392_b[v467_b] = 0;
      int * v394_b = (v324_p->b)->cache_age;
      v394_b[v467_b] = 1;
      int * v396_b = (v324_p->b)->cache_age;
      int v397_b = v396_b[v467_b];
      int v398_b = v396_b[v441_b];
      int v497_b = v398_b + ((int)((unsigned int)(v398_b - v397_b) >> 31));
      v396_b[v441_b] = v497_b;
      int * v400_b = (v324_p->b)->cache_age;
      int v401_b = v400_b[v442_b];
      int v499_b = v401_b + ((int)((unsigned int)(v401_b - v397_b) >> 31));
      v400_b[v442_b] = v499_b;
      int * v403_b = (v324_p->b)->cache_age;
      v403_b[v467_b] = 0;
      v406_b = v467_b;
    }
    int * v407_b = (v324_p->b)->cache_vals;
    int v502_b = v406_b * 2;
    int v408_b = v407_b[v502_b];
    int v503_b = (v406_b * 2) + 1;
    int v409_b = v407_b[v503_b];
    int v504_b = (((((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1)) & 1) * 2) + ((((v348_b + ((~(((v350_b ^ -1) | (-(v350_b ^ -1))) >> 31)) & 2)) - (v351_b + ((~(((v352_b ^ -1) | (-(v352_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v407_b[v504_b] = v408_b;
    int * v411_b = (v324_p->b)->cache_vals;
    int v507_b = ((((((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1)) & 1) * 2) + ((((v348_b + ((~(((v350_b ^ -1) | (-(v350_b ^ -1))) >> 31)) & 2)) - (v351_b + ((~(((v352_b ^ -1) | (-(v352_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v411_b[v507_b] = v409_b;
    int * v413_b = (v324_p->b)->cache_tags;
    int v510_b = ((((int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1)) & 1) * 2) + ((((v348_b + ((~(((v350_b ^ -1) | (-(v350_b ^ -1))) >> 31)) & 2)) - (v351_b + ((~(((v352_b ^ -1) | (-(v352_b ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v511_b = (int)((unsigned int)((int)((unsigned int)v328_b >> 2)) >> 1);
    v413_b[v510_b] = v511_b;
    int * v415_b = (v324_p->b)->cache_dirty;
    v415_b[v510_b] = 0;
    int * v417_b = (v324_p->b)->cache_age;
    v417_b[v510_b] = 1;
    int * v419_b = (v324_p->b)->cache_age;
    int v420_b = v419_b[v510_b];
    int v421_b = v419_b[v439_b];
    int v517_b = v421_b + ((int)((unsigned int)(v421_b - v420_b) >> 31));
    v419_b[v439_b] = v517_b;
    int * v423_b = (v324_p->b)->cache_age;
    int v424_b = v423_b[v440_b];
    int v519_b = v424_b + ((int)((unsigned int)(v424_b - v420_b) >> 31));
    v423_b[v440_b] = v519_b;
    int * v426_b = (v324_p->b)->cache_age;
    v426_b[v510_b] = 0;
    v429_b = v510_b;
  }
  int v522_a = (v429_a * 2) + (((int)((unsigned int)v328_a >> 2)) & 1);
  int v522_b = (v429_b * 2) + (((int)((unsigned int)v328_b >> 2)) & 1);
  int v430_a = v336_a[v522_a];
  int v430_b = v336_b[v522_b];
  int * v431_a = (v324_p->a)->regs;
  int * v431_b = (v324_p->b)->regs;
  v431_a[11] = v430_a;
  v431_b[11] = v430_b;
  struct StateT2 * v433_p = slot_9(v324_p);
  return v433_p;
}

struct StateT2 * slot_4(struct StateT2 * v54_p) {
  lockstep_assert(((v54_p->a)->timer) == ((v54_p->b)->timer));
  lockstep_assume(((v54_p->a)->timer) == ((v54_p->b)->timer));
  int v55_a = (v54_p->a)->timer;
  int v55_b = (v54_p->b)->timer;
  int v66_a = v55_a + 1;
  int v66_b = v55_b + 1;
  (v54_p->a)->timer = v66_a;
  (v54_p->b)->timer = v66_b;
  int * v57_a = (v54_p->a)->regs;
  int * v57_b = (v54_p->b)->regs;
  int v58_a = v57_a[14];
  int v58_b = v57_b[14];
  int v59_a = v57_a[15];
  int v59_b = v57_b[15];
  bool v70_a = v58_a >= v59_a;
  bool v70_b = v58_b >= v59_b;
  lockstep_assert(v70_a == v70_b);
  lockstep_assume(v70_a == v70_b);
  struct StateT2 * v64_p;
  if (v70_a) {
    struct StateT2 * v60_p = slot_14(v54_p);
    v64_p = v60_p;
  } else {
    struct StateT2 * v62_p = slot_5(v54_p);
    v64_p = v62_p;
  }
  return v64_p;
}

struct StateT2 * slot_13(struct StateT2 * v577_p) {
  lockstep_assert(((v577_p->a)->timer) == ((v577_p->b)->timer));
  lockstep_assume(((v577_p->a)->timer) == ((v577_p->b)->timer));
  int v578_a = (v577_p->a)->timer;
  int v578_b = (v577_p->b)->timer;
  int v581_a = v578_a + 1;
  int v581_b = v578_b + 1;
  (v577_p->a)->timer = v581_a;
  (v577_p->b)->timer = v581_b;
  return v577_p;
}

struct StateT2 * slot_9(struct StateT2 * v528_p) {
  lockstep_assert(((v528_p->a)->timer) == ((v528_p->b)->timer));
  lockstep_assume(((v528_p->a)->timer) == ((v528_p->b)->timer));
  int v529_a = (v528_p->a)->timer;
  int v529_b = (v528_p->b)->timer;
  int v540_a = v529_a + 1;
  int v540_b = v529_b + 1;
  (v528_p->a)->timer = v540_a;
  (v528_p->b)->timer = v540_b;
  int * v531_a = (v528_p->a)->regs;
  int * v531_b = (v528_p->b)->regs;
  int v532_a = v531_a[10];
  int v532_b = v531_b[10];
  int v533_a = v531_a[11];
  int v533_b = v531_b[11];
  bool v544_a = !(v532_a == v533_a);
  bool v544_b = !(v532_b == v533_b);
  lockstep_assert(v544_a == v544_b);
  lockstep_assume(v544_a == v544_b);
  struct StateT2 * v538_p;
  if (v544_a) {
    struct StateT2 * v534_p = slot_12(v528_p);
    v538_p = v534_p;
  } else {
    struct StateT2 * v536_p = slot_10(v528_p);
    v538_p = v536_p;
  }
  return v538_p;
}

struct StateT2 * slot_11(struct StateT2 * v582_p) {
  lockstep_assert(((v582_p->a)->timer) == ((v582_p->b)->timer));
  lockstep_assume(((v582_p->a)->timer) == ((v582_p->b)->timer));
  int v583_a = (v582_p->a)->timer;
  int v583_b = (v582_p->b)->timer;
  int v587_a = v583_a + 1;
  int v587_b = v583_b + 1;
  (v582_p->a)->timer = v587_a;
  (v582_p->b)->timer = v587_b;
  struct StateT2 * v585_p = slot_4(v582_p);
  return v585_p;
}

struct StateT2 * slot_0(struct StateT2 * v2_p) {
  lockstep_assert(((v2_p->a)->timer) == ((v2_p->b)->timer));
  lockstep_assume(((v2_p->a)->timer) == ((v2_p->b)->timer));
  int v3_a = (v2_p->a)->timer;
  int v3_b = (v2_p->b)->timer;
  int v9_a = v3_a + 1;
  int v9_b = v3_b + 1;
  (v2_p->a)->timer = v9_a;
  (v2_p->b)->timer = v9_b;
  int * v5_a = (v2_p->a)->regs;
  int * v5_b = (v2_p->b)->regs;
  v5_a[12] = 0;
  v5_b[12] = 0;
  struct StateT2 * v7_p = slot_1(v2_p);
  return v7_p;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
  }
  s->timer = 0;
  for (int i=0; i<MEM_SIZE; i++) {
    s->mem[i] = 0;
  }
  for (int i=0; i<CACHE_ENTRIES; i++) {
    s->cache_tags[i] = -1;
    s->cache_dirty[i] = 0;
    s->cache_age[i] = 0;
  }
  for (int i=0; i<CACHE_WORDS; i++) {
    s->cache_vals[i] = 0;
  }
}

void lockstep_assert(bool c) { koika_assert(c, "lockstep drift"); }
void lockstep_assume(bool c) { koika_assume(c); }

int main(int argc, char* argv[]) {
  struct StateT s1, s2;
  init(&s1);
  init(&s2);
  
  int x = bounded(0, 80);
  s1.regs[10] = x;
  s2.regs[10] = x;
  
  // initialize secret
  for (int i=0; i<SECRET_SIZE; i++) {
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateT2 p = { .a = &s1, .b = &s2 };
  struct StateT2 *p_ = snippet(&p);
  //@ assert untainted_timer: !\tainted(p_->a->timer==p_->b->timer);
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}