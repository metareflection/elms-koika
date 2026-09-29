// verify: clean (Eva should report untainted: Valid) [unroll 65]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef EVA
#include "__fc_builtin.h"
/*@ requires untainted: !\tainted(b);
    assigns \nothing; */
void koika_check(int b);
/*@ assigns *p \from \nothing;
    taints *p; */
void koika_mark(int *p);
#define koika_assert(b, s) koika_check(b)
#define koika_assume(b) do { if (!(b)) Frama_C_abort(); } while (0)
#define koika_draw(x) ((x) = Frama_C_interval(-2147483647-1, 2147483647))
#define koika_secret(x) koika_mark(&(x))
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

struct StateT2 * slot_12(struct StateT2 * v584_p);
struct StateT2 * slot_14(struct StateT2 * v89_p);
struct StateT2 * slot_6(struct StateT2 * v109_p);
struct StateT2 * slot_5(struct StateT2 * v67_p);
struct StateT2 * slot_2(struct StateT2 * v28_p);
struct StateT2 * slot_7(struct StateT2 * v126_p);
struct StateT2 * slot_3(struct StateT2 * v41_p);
struct StateT2 * snippet(struct StateT2 * v0_p);
struct StateT2 * slot_10(struct StateT2 * v551_p);
struct StateT2 * slot_1(struct StateT2 * v15_p);
struct StateT2 * slot_8(struct StateT2 * v330_p);
struct StateT2 * slot_4(struct StateT2 * v54_p);
struct StateT2 * slot_13(struct StateT2 * v598_p);
struct StateT2 * slot_9(struct StateT2 * v347_p);
struct StateT2 * slot_11(struct StateT2 * v568_p);
struct StateT2 * slot_0(struct StateT2 * v2_p);
struct StateT2 * slot_12(struct StateT2 * v584_p) {
  lockstep_assert(((v584_p->a)->timer) == ((v584_p->b)->timer));
  lockstep_assume(((v584_p->a)->timer) == ((v584_p->b)->timer));
  int v585_a = (v584_p->a)->timer;
  int v585_b = (v584_p->b)->timer;
  int v592_a = v585_a + 1;
  int v592_b = v585_b + 1;
  (v584_p->a)->timer = v592_a;
  (v584_p->b)->timer = v592_b;
  int * v587_a = (v584_p->a)->regs;
  int * v587_b = (v584_p->b)->regs;
  int v588_a = v587_a[14];
  int v588_b = v587_b[14];
  int v595_a = v588_a + 4;
  int v595_b = v588_b + 4;
  v587_a[14] = v595_a;
  v587_b[14] = v595_b;
  struct StateT2 * v590_p = slot_13(v584_p);
  return v590_p;
}

struct StateT2 * slot_14(struct StateT2 * v89_p) {
  lockstep_assert(((v89_p->a)->timer) == ((v89_p->b)->timer));
  lockstep_assume(((v89_p->a)->timer) == ((v89_p->b)->timer));
  int v90_a = (v89_p->a)->timer;
  int v90_b = (v89_p->b)->timer;
  int v100_a = v90_a + 1;
  int v100_b = v90_b + 1;
  (v89_p->a)->timer = v100_a;
  (v89_p->b)->timer = v100_b;
  int * v92_a = (v89_p->a)->regs;
  int * v92_b = (v89_p->b)->regs;
  int v93_a = v92_a[5];
  int v93_b = v92_b[5];
  bool v103_a = (v93_a ^ -2147483648) < -2147483647;
  bool v103_b = (v93_b ^ -2147483648) < -2147483647;
  int v96_a;
  if (v103_a) {
    v96_a = 1;
  } else {
    v96_a = 0;
  }
  int v96_b;
  if (v103_b) {
    v96_b = 1;
  } else {
    v96_b = 0;
  }
  int * v97_a = (v89_p->a)->regs;
  int * v97_b = (v89_p->b)->regs;
  v97_a[11] = v96_a;
  v97_b[11] = v96_b;
  return v89_p;
}

struct StateT2 * slot_6(struct StateT2 * v109_p) {
  lockstep_assert(((v109_p->a)->timer) == ((v109_p->b)->timer));
  lockstep_assume(((v109_p->a)->timer) == ((v109_p->b)->timer));
  int v110_a = (v109_p->a)->timer;
  int v110_b = (v109_p->b)->timer;
  int v118_a = v110_a + 1;
  int v118_b = v110_b + 1;
  (v109_p->a)->timer = v118_a;
  (v109_p->b)->timer = v118_b;
  int * v112_a = (v109_p->a)->regs;
  int * v112_b = (v109_p->b)->regs;
  int v113_a = v112_a[12];
  int v113_b = v112_b[12];
  int v114_a = v112_a[14];
  int v114_b = v112_b[14];
  int v123_a = v113_a + v114_a;
  int v123_b = v113_b + v114_b;
  v112_a[6] = v123_a;
  v112_b[6] = v123_b;
  struct StateT2 * v116_p = slot_7(v109_p);
  return v116_p;
}

struct StateT2 * slot_5(struct StateT2 * v67_p) {
  lockstep_assert(((v67_p->a)->timer) == ((v67_p->b)->timer));
  lockstep_assume(((v67_p->a)->timer) == ((v67_p->b)->timer));
  int v68_a = (v67_p->a)->timer;
  int v68_b = (v67_p->b)->timer;
  int v79_a = v68_a + 1;
  int v79_b = v68_b + 1;
  (v67_p->a)->timer = v79_a;
  (v67_p->b)->timer = v79_b;
  int * v70_a = (v67_p->a)->regs;
  int * v70_b = (v67_p->b)->regs;
  int v71_a = v70_a[14];
  int v71_b = v70_b[14];
  int v72_a = v70_a[15];
  int v72_b = v70_b[15];
  bool v83_a = v71_a >= v72_a;
  bool v83_b = v71_b >= v72_b;
  lockstep_assert(v83_a == v83_b);
  lockstep_assume(v83_a == v83_b);
  struct StateT2 * v77_p;
  if (v83_a) {
    struct StateT2 * v73_p = slot_14(v67_p);
    v77_p = v73_p;
  } else {
    struct StateT2 * v75_p = slot_6(v67_p);
    v77_p = v75_p;
  }
  return v77_p;
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

struct StateT2 * slot_7(struct StateT2 * v126_p) {
  lockstep_assert(((v126_p->a)->timer) == ((v126_p->b)->timer));
  lockstep_assume(((v126_p->a)->timer) == ((v126_p->b)->timer));
  int v127_a = (v126_p->a)->timer;
  int v127_b = (v126_p->b)->timer;
  int v237_a = v127_a + 1;
  int v237_b = v127_b + 1;
  (v126_p->a)->timer = v237_a;
  (v126_p->b)->timer = v237_b;
  int * v129_a = (v126_p->a)->regs;
  int * v129_b = (v126_p->b)->regs;
  int v130_a = v129_a[6];
  int v130_b = v129_b[6];
  int * v131_a = (v126_p->a)->cache_tags;
  int * v131_b = (v126_p->b)->cache_tags;
  int v241_a = (((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1)) & 1) * 2;
  int v241_b = (((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1)) & 1) * 2;
  int v132_a = v131_a[v241_a];
  int v132_b = v131_b[v241_b];
  int v242_a = ((((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1)) & 1) * 2) + 1;
  int v242_b = ((((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1)) & 1) * 2) + 1;
  int v133_a = v131_a[v242_a];
  int v133_b = v131_b[v242_b];
  int v243_a = 4 + ((((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1)) & 3) * 2);
  int v243_b = 4 + ((((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1)) & 3) * 2);
  int v134_a = v131_a[v243_a];
  int v134_b = v131_b[v243_b];
  int v244_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1)) & 3) * 2)) + 1;
  int v244_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1)) & 3) * 2)) + 1;
  int v135_a = v131_a[v244_a];
  int v135_b = v131_b[v244_b];
  int v136_a = (v126_p->a)->timer;
  int v136_b = (v126_p->b)->timer;
  int v245_a = v136_a + ((100 ^ (((~(((v134_a ^ ((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1))) | (-(v134_a ^ ((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1))))) >> 31)) | (~(((v135_a ^ ((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1))) | (-(v135_a ^ ((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v132_a ^ ((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1))) | (-(v132_a ^ ((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1))))) >> 31)) | (~(((v133_a ^ ((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1))) | (-(v133_a ^ ((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v134_a ^ ((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1))) | (-(v134_a ^ ((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1))))) >> 31)) | (~(((v135_a ^ ((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1))) | (-(v135_a ^ ((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1))))) >> 31))) & 104)))));
  int v245_b = v136_b + ((100 ^ (((~(((v134_b ^ ((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1))) | (-(v134_b ^ ((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1))))) >> 31)) | (~(((v135_b ^ ((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1))) | (-(v135_b ^ ((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v132_b ^ ((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1))) | (-(v132_b ^ ((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1))))) >> 31)) | (~(((v133_b ^ ((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1))) | (-(v133_b ^ ((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v134_b ^ ((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1))) | (-(v134_b ^ ((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1))))) >> 31)) | (~(((v135_b ^ ((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1))) | (-(v135_b ^ ((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1))))) >> 31))) & 104)))));
  (v126_p->a)->timer = v245_a;
  (v126_p->b)->timer = v245_b;
  int * v138_a = (v126_p->a)->cache_vals;
  int * v138_b = (v126_p->b)->cache_vals;
  bool v246_a = !(((~(((v132_a ^ ((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1))) | (-(v132_a ^ ((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1))))) >> 31)) | (~(((v133_a ^ ((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1))) | (-(v133_a ^ ((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1))))) >> 31))) == 0);
  bool v246_b = !(((~(((v132_b ^ ((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1))) | (-(v132_b ^ ((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1))))) >> 31)) | (~(((v133_b ^ ((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1))) | (-(v133_b ^ ((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1))))) >> 31))) == 0);
  int v231_a;
  if (v246_a) {
    int * v139_a = (v126_p->a)->cache_age;
    int v248_a = ((((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1)) & 1) * 2) + ((~(((v133_a ^ ((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1))) | (-(v133_a ^ ((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1))))) >> 31)) & 1);
    int v140_a = v139_a[v248_a];
    int v141_a = v139_a[v241_a];
    int v249_a = v141_a + ((int)((unsigned int)(v141_a - v140_a) >> 31));
    v139_a[v241_a] = v249_a;
    int * v143_a = (v126_p->a)->cache_age;
    int v144_a = v143_a[v242_a];
    int v251_a = v144_a + ((int)((unsigned int)(v144_a - v140_a) >> 31));
    v143_a[v242_a] = v251_a;
    int * v146_a = (v126_p->a)->cache_age;
    v146_a[v248_a] = 0;
    v231_a = v248_a;
  } else {
    int * v149_a = (v126_p->a)->cache_age;
    int v255_a = (((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1)) & 1) * 2;
    int v150_a = v149_a[v255_a];
    int * v151_a = (v126_p->a)->cache_tags;
    int v152_a = v151_a[v255_a];
    int v153_a = v149_a[v242_a];
    int v154_a = v151_a[v242_a];
    bool v257_a = !(((~(((v134_a ^ ((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1))) | (-(v134_a ^ ((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1))))) >> 31)) | (~(((v135_a ^ ((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1))) | (-(v135_a ^ ((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1))))) >> 31))) == 0);
    int v208_a;
    if (v257_a) {
      int * v155_a = (v126_p->a)->cache_age;
      int v259_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1)) & 3) * 2)) + ((~(((v135_a ^ ((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1))) | (-(v135_a ^ ((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1))))) >> 31)) & 1);
      int v156_a = v155_a[v259_a];
      int v157_a = v155_a[v243_a];
      int v260_a = v157_a + ((int)((unsigned int)(v157_a - v156_a) >> 31));
      v155_a[v243_a] = v260_a;
      int * v159_a = (v126_p->a)->cache_age;
      int v160_a = v159_a[v244_a];
      int v262_a = v160_a + ((int)((unsigned int)(v160_a - v156_a) >> 31));
      v159_a[v244_a] = v262_a;
      int * v162_a = (v126_p->a)->cache_age;
      v162_a[v259_a] = 0;
      v208_a = v259_a;
    } else {
      int * v165_a = (v126_p->a)->cache_age;
      int v266_a = 4 + ((((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1)) & 3) * 2);
      int v166_a = v165_a[v266_a];
      int * v167_a = (v126_p->a)->cache_tags;
      int v168_a = v167_a[v266_a];
      int v169_a = v165_a[v244_a];
      int v170_a = v167_a[v244_a];
      int * v171_a = (v126_p->a)->cache_dirty;
      int v269_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1)) & 3) * 2)) + ((((v166_a + ((~(((v168_a ^ -1) | (-(v168_a ^ -1))) >> 31)) & 2)) - (v169_a + ((~(((v170_a ^ -1) | (-(v170_a ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v172_a = v171_a[v269_a];
      bool v270_a = !(v172_a == 0);
      if (v270_a) {
        int * v173_a = (v126_p->a)->cache_tags;
        int v174_a = v173_a[v269_a];
        int * v175_a = (v126_p->a)->cache_vals;
        int v273_a = ((4 + ((((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1)) & 3) * 2)) + ((((v166_a + ((~(((v168_a ^ -1) | (-(v168_a ^ -1))) >> 31)) & 2)) - (v169_a + ((~(((v170_a ^ -1) | (-(v170_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v176_a = v175_a[v273_a];
        int v274_a = (((4 + ((((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1)) & 3) * 2)) + ((((v166_a + ((~(((v168_a ^ -1) | (-(v168_a ^ -1))) >> 31)) & 2)) - (v169_a + ((~(((v170_a ^ -1) | (-(v170_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v177_a = v175_a[v274_a];
        int * v178_a = (v126_p->a)->mem;
        int v276_a = v174_a * 2;
        v178_a[v276_a] = v176_a;
        int * v180_a = (v126_p->a)->mem;
        int v279_a = (v174_a * 2) + 1;
        v180_a[v279_a] = v177_a;
        ;
      } else {
        ;
      }
      int * v185_a = (v126_p->a)->mem;
      int v284_a = ((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1)) * 2;
      int v186_a = v185_a[v284_a];
      int v285_a = (((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1)) * 2) + 1;
      int v187_a = v185_a[v285_a];
      int * v188_a = (v126_p->a)->cache_vals;
      int v287_a = ((4 + ((((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1)) & 3) * 2)) + ((((v166_a + ((~(((v168_a ^ -1) | (-(v168_a ^ -1))) >> 31)) & 2)) - (v169_a + ((~(((v170_a ^ -1) | (-(v170_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v188_a[v287_a] = v186_a;
      int * v190_a = (v126_p->a)->cache_vals;
      int v290_a = (((4 + ((((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1)) & 3) * 2)) + ((((v166_a + ((~(((v168_a ^ -1) | (-(v168_a ^ -1))) >> 31)) & 2)) - (v169_a + ((~(((v170_a ^ -1) | (-(v170_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v190_a[v290_a] = v187_a;
      int * v192_a = (v126_p->a)->cache_tags;
      int v293_a = (int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1);
      v192_a[v269_a] = v293_a;
      int * v194_a = (v126_p->a)->cache_dirty;
      v194_a[v269_a] = 0;
      int * v196_a = (v126_p->a)->cache_age;
      v196_a[v269_a] = 1;
      int * v198_a = (v126_p->a)->cache_age;
      int v199_a = v198_a[v269_a];
      int v200_a = v198_a[v243_a];
      int v299_a = v200_a + ((int)((unsigned int)(v200_a - v199_a) >> 31));
      v198_a[v243_a] = v299_a;
      int * v202_a = (v126_p->a)->cache_age;
      int v203_a = v202_a[v244_a];
      int v301_a = v203_a + ((int)((unsigned int)(v203_a - v199_a) >> 31));
      v202_a[v244_a] = v301_a;
      int * v205_a = (v126_p->a)->cache_age;
      v205_a[v269_a] = 0;
      v208_a = v269_a;
    }
    int * v209_a = (v126_p->a)->cache_vals;
    int v304_a = v208_a * 2;
    int v210_a = v209_a[v304_a];
    int v305_a = (v208_a * 2) + 1;
    int v211_a = v209_a[v305_a];
    int v306_a = (((((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1)) & 1) * 2) + ((((v150_a + ((~(((v152_a ^ -1) | (-(v152_a ^ -1))) >> 31)) & 2)) - (v153_a + ((~(((v154_a ^ -1) | (-(v154_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v209_a[v306_a] = v210_a;
    int * v213_a = (v126_p->a)->cache_vals;
    int v309_a = ((((((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1)) & 1) * 2) + ((((v150_a + ((~(((v152_a ^ -1) | (-(v152_a ^ -1))) >> 31)) & 2)) - (v153_a + ((~(((v154_a ^ -1) | (-(v154_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v213_a[v309_a] = v211_a;
    int * v215_a = (v126_p->a)->cache_tags;
    int v312_a = ((((int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1)) & 1) * 2) + ((((v150_a + ((~(((v152_a ^ -1) | (-(v152_a ^ -1))) >> 31)) & 2)) - (v153_a + ((~(((v154_a ^ -1) | (-(v154_a ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v313_a = (int)((unsigned int)((int)((unsigned int)v130_a >> 2)) >> 1);
    v215_a[v312_a] = v313_a;
    int * v217_a = (v126_p->a)->cache_dirty;
    v217_a[v312_a] = 0;
    int * v219_a = (v126_p->a)->cache_age;
    v219_a[v312_a] = 1;
    int * v221_a = (v126_p->a)->cache_age;
    int v222_a = v221_a[v312_a];
    int v223_a = v221_a[v241_a];
    int v319_a = v223_a + ((int)((unsigned int)(v223_a - v222_a) >> 31));
    v221_a[v241_a] = v319_a;
    int * v225_a = (v126_p->a)->cache_age;
    int v226_a = v225_a[v242_a];
    int v321_a = v226_a + ((int)((unsigned int)(v226_a - v222_a) >> 31));
    v225_a[v242_a] = v321_a;
    int * v228_a = (v126_p->a)->cache_age;
    v228_a[v312_a] = 0;
    v231_a = v312_a;
  }
  int v231_b;
  if (v246_b) {
    int * v139_b = (v126_p->b)->cache_age;
    int v248_b = ((((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1)) & 1) * 2) + ((~(((v133_b ^ ((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1))) | (-(v133_b ^ ((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1))))) >> 31)) & 1);
    int v140_b = v139_b[v248_b];
    int v141_b = v139_b[v241_b];
    int v249_b = v141_b + ((int)((unsigned int)(v141_b - v140_b) >> 31));
    v139_b[v241_b] = v249_b;
    int * v143_b = (v126_p->b)->cache_age;
    int v144_b = v143_b[v242_b];
    int v251_b = v144_b + ((int)((unsigned int)(v144_b - v140_b) >> 31));
    v143_b[v242_b] = v251_b;
    int * v146_b = (v126_p->b)->cache_age;
    v146_b[v248_b] = 0;
    v231_b = v248_b;
  } else {
    int * v149_b = (v126_p->b)->cache_age;
    int v255_b = (((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1)) & 1) * 2;
    int v150_b = v149_b[v255_b];
    int * v151_b = (v126_p->b)->cache_tags;
    int v152_b = v151_b[v255_b];
    int v153_b = v149_b[v242_b];
    int v154_b = v151_b[v242_b];
    bool v257_b = !(((~(((v134_b ^ ((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1))) | (-(v134_b ^ ((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1))))) >> 31)) | (~(((v135_b ^ ((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1))) | (-(v135_b ^ ((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1))))) >> 31))) == 0);
    int v208_b;
    if (v257_b) {
      int * v155_b = (v126_p->b)->cache_age;
      int v259_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1)) & 3) * 2)) + ((~(((v135_b ^ ((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1))) | (-(v135_b ^ ((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1))))) >> 31)) & 1);
      int v156_b = v155_b[v259_b];
      int v157_b = v155_b[v243_b];
      int v260_b = v157_b + ((int)((unsigned int)(v157_b - v156_b) >> 31));
      v155_b[v243_b] = v260_b;
      int * v159_b = (v126_p->b)->cache_age;
      int v160_b = v159_b[v244_b];
      int v262_b = v160_b + ((int)((unsigned int)(v160_b - v156_b) >> 31));
      v159_b[v244_b] = v262_b;
      int * v162_b = (v126_p->b)->cache_age;
      v162_b[v259_b] = 0;
      v208_b = v259_b;
    } else {
      int * v165_b = (v126_p->b)->cache_age;
      int v266_b = 4 + ((((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1)) & 3) * 2);
      int v166_b = v165_b[v266_b];
      int * v167_b = (v126_p->b)->cache_tags;
      int v168_b = v167_b[v266_b];
      int v169_b = v165_b[v244_b];
      int v170_b = v167_b[v244_b];
      int * v171_b = (v126_p->b)->cache_dirty;
      int v269_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1)) & 3) * 2)) + ((((v166_b + ((~(((v168_b ^ -1) | (-(v168_b ^ -1))) >> 31)) & 2)) - (v169_b + ((~(((v170_b ^ -1) | (-(v170_b ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v172_b = v171_b[v269_b];
      bool v270_b = !(v172_b == 0);
      if (v270_b) {
        int * v173_b = (v126_p->b)->cache_tags;
        int v174_b = v173_b[v269_b];
        int * v175_b = (v126_p->b)->cache_vals;
        int v273_b = ((4 + ((((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1)) & 3) * 2)) + ((((v166_b + ((~(((v168_b ^ -1) | (-(v168_b ^ -1))) >> 31)) & 2)) - (v169_b + ((~(((v170_b ^ -1) | (-(v170_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v176_b = v175_b[v273_b];
        int v274_b = (((4 + ((((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1)) & 3) * 2)) + ((((v166_b + ((~(((v168_b ^ -1) | (-(v168_b ^ -1))) >> 31)) & 2)) - (v169_b + ((~(((v170_b ^ -1) | (-(v170_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v177_b = v175_b[v274_b];
        int * v178_b = (v126_p->b)->mem;
        int v276_b = v174_b * 2;
        v178_b[v276_b] = v176_b;
        int * v180_b = (v126_p->b)->mem;
        int v279_b = (v174_b * 2) + 1;
        v180_b[v279_b] = v177_b;
        ;
      } else {
        ;
      }
      int * v185_b = (v126_p->b)->mem;
      int v284_b = ((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1)) * 2;
      int v186_b = v185_b[v284_b];
      int v285_b = (((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1)) * 2) + 1;
      int v187_b = v185_b[v285_b];
      int * v188_b = (v126_p->b)->cache_vals;
      int v287_b = ((4 + ((((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1)) & 3) * 2)) + ((((v166_b + ((~(((v168_b ^ -1) | (-(v168_b ^ -1))) >> 31)) & 2)) - (v169_b + ((~(((v170_b ^ -1) | (-(v170_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v188_b[v287_b] = v186_b;
      int * v190_b = (v126_p->b)->cache_vals;
      int v290_b = (((4 + ((((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1)) & 3) * 2)) + ((((v166_b + ((~(((v168_b ^ -1) | (-(v168_b ^ -1))) >> 31)) & 2)) - (v169_b + ((~(((v170_b ^ -1) | (-(v170_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v190_b[v290_b] = v187_b;
      int * v192_b = (v126_p->b)->cache_tags;
      int v293_b = (int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1);
      v192_b[v269_b] = v293_b;
      int * v194_b = (v126_p->b)->cache_dirty;
      v194_b[v269_b] = 0;
      int * v196_b = (v126_p->b)->cache_age;
      v196_b[v269_b] = 1;
      int * v198_b = (v126_p->b)->cache_age;
      int v199_b = v198_b[v269_b];
      int v200_b = v198_b[v243_b];
      int v299_b = v200_b + ((int)((unsigned int)(v200_b - v199_b) >> 31));
      v198_b[v243_b] = v299_b;
      int * v202_b = (v126_p->b)->cache_age;
      int v203_b = v202_b[v244_b];
      int v301_b = v203_b + ((int)((unsigned int)(v203_b - v199_b) >> 31));
      v202_b[v244_b] = v301_b;
      int * v205_b = (v126_p->b)->cache_age;
      v205_b[v269_b] = 0;
      v208_b = v269_b;
    }
    int * v209_b = (v126_p->b)->cache_vals;
    int v304_b = v208_b * 2;
    int v210_b = v209_b[v304_b];
    int v305_b = (v208_b * 2) + 1;
    int v211_b = v209_b[v305_b];
    int v306_b = (((((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1)) & 1) * 2) + ((((v150_b + ((~(((v152_b ^ -1) | (-(v152_b ^ -1))) >> 31)) & 2)) - (v153_b + ((~(((v154_b ^ -1) | (-(v154_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v209_b[v306_b] = v210_b;
    int * v213_b = (v126_p->b)->cache_vals;
    int v309_b = ((((((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1)) & 1) * 2) + ((((v150_b + ((~(((v152_b ^ -1) | (-(v152_b ^ -1))) >> 31)) & 2)) - (v153_b + ((~(((v154_b ^ -1) | (-(v154_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v213_b[v309_b] = v211_b;
    int * v215_b = (v126_p->b)->cache_tags;
    int v312_b = ((((int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1)) & 1) * 2) + ((((v150_b + ((~(((v152_b ^ -1) | (-(v152_b ^ -1))) >> 31)) & 2)) - (v153_b + ((~(((v154_b ^ -1) | (-(v154_b ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v313_b = (int)((unsigned int)((int)((unsigned int)v130_b >> 2)) >> 1);
    v215_b[v312_b] = v313_b;
    int * v217_b = (v126_p->b)->cache_dirty;
    v217_b[v312_b] = 0;
    int * v219_b = (v126_p->b)->cache_age;
    v219_b[v312_b] = 1;
    int * v221_b = (v126_p->b)->cache_age;
    int v222_b = v221_b[v312_b];
    int v223_b = v221_b[v241_b];
    int v319_b = v223_b + ((int)((unsigned int)(v223_b - v222_b) >> 31));
    v221_b[v241_b] = v319_b;
    int * v225_b = (v126_p->b)->cache_age;
    int v226_b = v225_b[v242_b];
    int v321_b = v226_b + ((int)((unsigned int)(v226_b - v222_b) >> 31));
    v225_b[v242_b] = v321_b;
    int * v228_b = (v126_p->b)->cache_age;
    v228_b[v312_b] = 0;
    v231_b = v312_b;
  }
  int v324_a = (v231_a * 2) + (((int)((unsigned int)v130_a >> 2)) & 1);
  int v324_b = (v231_b * 2) + (((int)((unsigned int)v130_b >> 2)) & 1);
  int v232_a = v138_a[v324_a];
  int v232_b = v138_b[v324_b];
  int * v233_a = (v126_p->a)->regs;
  int * v233_b = (v126_p->b)->regs;
  v233_a[7] = v232_a;
  v233_b[7] = v232_b;
  struct StateT2 * v235_p = slot_8(v126_p);
  return v235_p;
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

struct StateT2 * slot_10(struct StateT2 * v551_p) {
  lockstep_assert(((v551_p->a)->timer) == ((v551_p->b)->timer));
  lockstep_assume(((v551_p->a)->timer) == ((v551_p->b)->timer));
  int v552_a = (v551_p->a)->timer;
  int v552_b = (v551_p->b)->timer;
  int v560_a = v552_a + 1;
  int v560_b = v552_b + 1;
  (v551_p->a)->timer = v560_a;
  (v551_p->b)->timer = v560_b;
  int * v554_a = (v551_p->a)->regs;
  int * v554_b = (v551_p->b)->regs;
  int v555_a = v554_a[7];
  int v555_b = v554_b[7];
  int v556_a = v554_a[9];
  int v556_b = v554_b[9];
  int v565_a = v555_a ^ v556_a;
  int v565_b = v555_b ^ v556_b;
  v554_a[16] = v565_a;
  v554_b[16] = v565_b;
  struct StateT2 * v558_p = slot_11(v551_p);
  return v558_p;
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

struct StateT2 * slot_8(struct StateT2 * v330_p) {
  lockstep_assert(((v330_p->a)->timer) == ((v330_p->b)->timer));
  lockstep_assume(((v330_p->a)->timer) == ((v330_p->b)->timer));
  int v331_a = (v330_p->a)->timer;
  int v331_b = (v330_p->b)->timer;
  int v339_a = v331_a + 1;
  int v339_b = v331_b + 1;
  (v330_p->a)->timer = v339_a;
  (v330_p->b)->timer = v339_b;
  int * v333_a = (v330_p->a)->regs;
  int * v333_b = (v330_p->b)->regs;
  int v334_a = v333_a[13];
  int v334_b = v333_b[13];
  int v335_a = v333_a[14];
  int v335_b = v333_b[14];
  int v344_a = v334_a + v335_a;
  int v344_b = v334_b + v335_b;
  v333_a[8] = v344_a;
  v333_b[8] = v344_b;
  struct StateT2 * v337_p = slot_9(v330_p);
  return v337_p;
}

struct StateT2 * slot_4(struct StateT2 * v54_p) {
  lockstep_assert(((v54_p->a)->timer) == ((v54_p->b)->timer));
  lockstep_assume(((v54_p->a)->timer) == ((v54_p->b)->timer));
  int v55_a = (v54_p->a)->timer;
  int v55_b = (v54_p->b)->timer;
  int v61_a = v55_a + 1;
  int v61_b = v55_b + 1;
  (v54_p->a)->timer = v61_a;
  (v54_p->b)->timer = v61_b;
  int * v57_a = (v54_p->a)->regs;
  int * v57_b = (v54_p->b)->regs;
  v57_a[5] = 0;
  v57_b[5] = 0;
  struct StateT2 * v59_p = slot_5(v54_p);
  return v59_p;
}

struct StateT2 * slot_13(struct StateT2 * v598_p) {
  lockstep_assert(((v598_p->a)->timer) == ((v598_p->b)->timer));
  lockstep_assume(((v598_p->a)->timer) == ((v598_p->b)->timer));
  int v599_a = (v598_p->a)->timer;
  int v599_b = (v598_p->b)->timer;
  int v603_a = v599_a + 1;
  int v603_b = v599_b + 1;
  (v598_p->a)->timer = v603_a;
  (v598_p->b)->timer = v603_b;
  struct StateT2 * v601_p = slot_5(v598_p);
  return v601_p;
}

struct StateT2 * slot_9(struct StateT2 * v347_p) {
  lockstep_assert(((v347_p->a)->timer) == ((v347_p->b)->timer));
  lockstep_assume(((v347_p->a)->timer) == ((v347_p->b)->timer));
  int v348_a = (v347_p->a)->timer;
  int v348_b = (v347_p->b)->timer;
  int v458_a = v348_a + 1;
  int v458_b = v348_b + 1;
  (v347_p->a)->timer = v458_a;
  (v347_p->b)->timer = v458_b;
  int * v350_a = (v347_p->a)->regs;
  int * v350_b = (v347_p->b)->regs;
  int v351_a = v350_a[8];
  int v351_b = v350_b[8];
  int * v352_a = (v347_p->a)->cache_tags;
  int * v352_b = (v347_p->b)->cache_tags;
  int v462_a = (((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1)) & 1) * 2;
  int v462_b = (((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1)) & 1) * 2;
  int v353_a = v352_a[v462_a];
  int v353_b = v352_b[v462_b];
  int v463_a = ((((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1)) & 1) * 2) + 1;
  int v463_b = ((((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1)) & 1) * 2) + 1;
  int v354_a = v352_a[v463_a];
  int v354_b = v352_b[v463_b];
  int v464_a = 4 + ((((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1)) & 3) * 2);
  int v464_b = 4 + ((((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1)) & 3) * 2);
  int v355_a = v352_a[v464_a];
  int v355_b = v352_b[v464_b];
  int v465_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1)) & 3) * 2)) + 1;
  int v465_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1)) & 3) * 2)) + 1;
  int v356_a = v352_a[v465_a];
  int v356_b = v352_b[v465_b];
  int v357_a = (v347_p->a)->timer;
  int v357_b = (v347_p->b)->timer;
  int v466_a = v357_a + ((100 ^ (((~(((v355_a ^ ((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1))) | (-(v355_a ^ ((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1))))) >> 31)) | (~(((v356_a ^ ((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1))) | (-(v356_a ^ ((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v353_a ^ ((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1))) | (-(v353_a ^ ((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1))))) >> 31)) | (~(((v354_a ^ ((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1))) | (-(v354_a ^ ((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v355_a ^ ((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1))) | (-(v355_a ^ ((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1))))) >> 31)) | (~(((v356_a ^ ((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1))) | (-(v356_a ^ ((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1))))) >> 31))) & 104)))));
  int v466_b = v357_b + ((100 ^ (((~(((v355_b ^ ((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1))) | (-(v355_b ^ ((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1))))) >> 31)) | (~(((v356_b ^ ((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1))) | (-(v356_b ^ ((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v353_b ^ ((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1))) | (-(v353_b ^ ((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1))))) >> 31)) | (~(((v354_b ^ ((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1))) | (-(v354_b ^ ((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v355_b ^ ((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1))) | (-(v355_b ^ ((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1))))) >> 31)) | (~(((v356_b ^ ((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1))) | (-(v356_b ^ ((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1))))) >> 31))) & 104)))));
  (v347_p->a)->timer = v466_a;
  (v347_p->b)->timer = v466_b;
  int * v359_a = (v347_p->a)->cache_vals;
  int * v359_b = (v347_p->b)->cache_vals;
  bool v467_a = !(((~(((v353_a ^ ((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1))) | (-(v353_a ^ ((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1))))) >> 31)) | (~(((v354_a ^ ((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1))) | (-(v354_a ^ ((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1))))) >> 31))) == 0);
  bool v467_b = !(((~(((v353_b ^ ((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1))) | (-(v353_b ^ ((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1))))) >> 31)) | (~(((v354_b ^ ((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1))) | (-(v354_b ^ ((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1))))) >> 31))) == 0);
  int v452_a;
  if (v467_a) {
    int * v360_a = (v347_p->a)->cache_age;
    int v469_a = ((((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1)) & 1) * 2) + ((~(((v354_a ^ ((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1))) | (-(v354_a ^ ((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1))))) >> 31)) & 1);
    int v361_a = v360_a[v469_a];
    int v362_a = v360_a[v462_a];
    int v470_a = v362_a + ((int)((unsigned int)(v362_a - v361_a) >> 31));
    v360_a[v462_a] = v470_a;
    int * v364_a = (v347_p->a)->cache_age;
    int v365_a = v364_a[v463_a];
    int v472_a = v365_a + ((int)((unsigned int)(v365_a - v361_a) >> 31));
    v364_a[v463_a] = v472_a;
    int * v367_a = (v347_p->a)->cache_age;
    v367_a[v469_a] = 0;
    v452_a = v469_a;
  } else {
    int * v370_a = (v347_p->a)->cache_age;
    int v476_a = (((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1)) & 1) * 2;
    int v371_a = v370_a[v476_a];
    int * v372_a = (v347_p->a)->cache_tags;
    int v373_a = v372_a[v476_a];
    int v374_a = v370_a[v463_a];
    int v375_a = v372_a[v463_a];
    bool v478_a = !(((~(((v355_a ^ ((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1))) | (-(v355_a ^ ((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1))))) >> 31)) | (~(((v356_a ^ ((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1))) | (-(v356_a ^ ((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1))))) >> 31))) == 0);
    int v429_a;
    if (v478_a) {
      int * v376_a = (v347_p->a)->cache_age;
      int v480_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1)) & 3) * 2)) + ((~(((v356_a ^ ((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1))) | (-(v356_a ^ ((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1))))) >> 31)) & 1);
      int v377_a = v376_a[v480_a];
      int v378_a = v376_a[v464_a];
      int v481_a = v378_a + ((int)((unsigned int)(v378_a - v377_a) >> 31));
      v376_a[v464_a] = v481_a;
      int * v380_a = (v347_p->a)->cache_age;
      int v381_a = v380_a[v465_a];
      int v483_a = v381_a + ((int)((unsigned int)(v381_a - v377_a) >> 31));
      v380_a[v465_a] = v483_a;
      int * v383_a = (v347_p->a)->cache_age;
      v383_a[v480_a] = 0;
      v429_a = v480_a;
    } else {
      int * v386_a = (v347_p->a)->cache_age;
      int v487_a = 4 + ((((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1)) & 3) * 2);
      int v387_a = v386_a[v487_a];
      int * v388_a = (v347_p->a)->cache_tags;
      int v389_a = v388_a[v487_a];
      int v390_a = v386_a[v465_a];
      int v391_a = v388_a[v465_a];
      int * v392_a = (v347_p->a)->cache_dirty;
      int v490_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1)) & 3) * 2)) + ((((v387_a + ((~(((v389_a ^ -1) | (-(v389_a ^ -1))) >> 31)) & 2)) - (v390_a + ((~(((v391_a ^ -1) | (-(v391_a ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v393_a = v392_a[v490_a];
      bool v491_a = !(v393_a == 0);
      if (v491_a) {
        int * v394_a = (v347_p->a)->cache_tags;
        int v395_a = v394_a[v490_a];
        int * v396_a = (v347_p->a)->cache_vals;
        int v494_a = ((4 + ((((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1)) & 3) * 2)) + ((((v387_a + ((~(((v389_a ^ -1) | (-(v389_a ^ -1))) >> 31)) & 2)) - (v390_a + ((~(((v391_a ^ -1) | (-(v391_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v397_a = v396_a[v494_a];
        int v495_a = (((4 + ((((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1)) & 3) * 2)) + ((((v387_a + ((~(((v389_a ^ -1) | (-(v389_a ^ -1))) >> 31)) & 2)) - (v390_a + ((~(((v391_a ^ -1) | (-(v391_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v398_a = v396_a[v495_a];
        int * v399_a = (v347_p->a)->mem;
        int v497_a = v395_a * 2;
        v399_a[v497_a] = v397_a;
        int * v401_a = (v347_p->a)->mem;
        int v500_a = (v395_a * 2) + 1;
        v401_a[v500_a] = v398_a;
        ;
      } else {
        ;
      }
      int * v406_a = (v347_p->a)->mem;
      int v505_a = ((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1)) * 2;
      int v407_a = v406_a[v505_a];
      int v506_a = (((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1)) * 2) + 1;
      int v408_a = v406_a[v506_a];
      int * v409_a = (v347_p->a)->cache_vals;
      int v508_a = ((4 + ((((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1)) & 3) * 2)) + ((((v387_a + ((~(((v389_a ^ -1) | (-(v389_a ^ -1))) >> 31)) & 2)) - (v390_a + ((~(((v391_a ^ -1) | (-(v391_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v409_a[v508_a] = v407_a;
      int * v411_a = (v347_p->a)->cache_vals;
      int v511_a = (((4 + ((((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1)) & 3) * 2)) + ((((v387_a + ((~(((v389_a ^ -1) | (-(v389_a ^ -1))) >> 31)) & 2)) - (v390_a + ((~(((v391_a ^ -1) | (-(v391_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v411_a[v511_a] = v408_a;
      int * v413_a = (v347_p->a)->cache_tags;
      int v514_a = (int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1);
      v413_a[v490_a] = v514_a;
      int * v415_a = (v347_p->a)->cache_dirty;
      v415_a[v490_a] = 0;
      int * v417_a = (v347_p->a)->cache_age;
      v417_a[v490_a] = 1;
      int * v419_a = (v347_p->a)->cache_age;
      int v420_a = v419_a[v490_a];
      int v421_a = v419_a[v464_a];
      int v520_a = v421_a + ((int)((unsigned int)(v421_a - v420_a) >> 31));
      v419_a[v464_a] = v520_a;
      int * v423_a = (v347_p->a)->cache_age;
      int v424_a = v423_a[v465_a];
      int v522_a = v424_a + ((int)((unsigned int)(v424_a - v420_a) >> 31));
      v423_a[v465_a] = v522_a;
      int * v426_a = (v347_p->a)->cache_age;
      v426_a[v490_a] = 0;
      v429_a = v490_a;
    }
    int * v430_a = (v347_p->a)->cache_vals;
    int v525_a = v429_a * 2;
    int v431_a = v430_a[v525_a];
    int v526_a = (v429_a * 2) + 1;
    int v432_a = v430_a[v526_a];
    int v527_a = (((((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1)) & 1) * 2) + ((((v371_a + ((~(((v373_a ^ -1) | (-(v373_a ^ -1))) >> 31)) & 2)) - (v374_a + ((~(((v375_a ^ -1) | (-(v375_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v430_a[v527_a] = v431_a;
    int * v434_a = (v347_p->a)->cache_vals;
    int v530_a = ((((((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1)) & 1) * 2) + ((((v371_a + ((~(((v373_a ^ -1) | (-(v373_a ^ -1))) >> 31)) & 2)) - (v374_a + ((~(((v375_a ^ -1) | (-(v375_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v434_a[v530_a] = v432_a;
    int * v436_a = (v347_p->a)->cache_tags;
    int v533_a = ((((int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1)) & 1) * 2) + ((((v371_a + ((~(((v373_a ^ -1) | (-(v373_a ^ -1))) >> 31)) & 2)) - (v374_a + ((~(((v375_a ^ -1) | (-(v375_a ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v534_a = (int)((unsigned int)((int)((unsigned int)v351_a >> 2)) >> 1);
    v436_a[v533_a] = v534_a;
    int * v438_a = (v347_p->a)->cache_dirty;
    v438_a[v533_a] = 0;
    int * v440_a = (v347_p->a)->cache_age;
    v440_a[v533_a] = 1;
    int * v442_a = (v347_p->a)->cache_age;
    int v443_a = v442_a[v533_a];
    int v444_a = v442_a[v462_a];
    int v540_a = v444_a + ((int)((unsigned int)(v444_a - v443_a) >> 31));
    v442_a[v462_a] = v540_a;
    int * v446_a = (v347_p->a)->cache_age;
    int v447_a = v446_a[v463_a];
    int v542_a = v447_a + ((int)((unsigned int)(v447_a - v443_a) >> 31));
    v446_a[v463_a] = v542_a;
    int * v449_a = (v347_p->a)->cache_age;
    v449_a[v533_a] = 0;
    v452_a = v533_a;
  }
  int v452_b;
  if (v467_b) {
    int * v360_b = (v347_p->b)->cache_age;
    int v469_b = ((((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1)) & 1) * 2) + ((~(((v354_b ^ ((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1))) | (-(v354_b ^ ((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1))))) >> 31)) & 1);
    int v361_b = v360_b[v469_b];
    int v362_b = v360_b[v462_b];
    int v470_b = v362_b + ((int)((unsigned int)(v362_b - v361_b) >> 31));
    v360_b[v462_b] = v470_b;
    int * v364_b = (v347_p->b)->cache_age;
    int v365_b = v364_b[v463_b];
    int v472_b = v365_b + ((int)((unsigned int)(v365_b - v361_b) >> 31));
    v364_b[v463_b] = v472_b;
    int * v367_b = (v347_p->b)->cache_age;
    v367_b[v469_b] = 0;
    v452_b = v469_b;
  } else {
    int * v370_b = (v347_p->b)->cache_age;
    int v476_b = (((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1)) & 1) * 2;
    int v371_b = v370_b[v476_b];
    int * v372_b = (v347_p->b)->cache_tags;
    int v373_b = v372_b[v476_b];
    int v374_b = v370_b[v463_b];
    int v375_b = v372_b[v463_b];
    bool v478_b = !(((~(((v355_b ^ ((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1))) | (-(v355_b ^ ((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1))))) >> 31)) | (~(((v356_b ^ ((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1))) | (-(v356_b ^ ((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1))))) >> 31))) == 0);
    int v429_b;
    if (v478_b) {
      int * v376_b = (v347_p->b)->cache_age;
      int v480_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1)) & 3) * 2)) + ((~(((v356_b ^ ((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1))) | (-(v356_b ^ ((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1))))) >> 31)) & 1);
      int v377_b = v376_b[v480_b];
      int v378_b = v376_b[v464_b];
      int v481_b = v378_b + ((int)((unsigned int)(v378_b - v377_b) >> 31));
      v376_b[v464_b] = v481_b;
      int * v380_b = (v347_p->b)->cache_age;
      int v381_b = v380_b[v465_b];
      int v483_b = v381_b + ((int)((unsigned int)(v381_b - v377_b) >> 31));
      v380_b[v465_b] = v483_b;
      int * v383_b = (v347_p->b)->cache_age;
      v383_b[v480_b] = 0;
      v429_b = v480_b;
    } else {
      int * v386_b = (v347_p->b)->cache_age;
      int v487_b = 4 + ((((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1)) & 3) * 2);
      int v387_b = v386_b[v487_b];
      int * v388_b = (v347_p->b)->cache_tags;
      int v389_b = v388_b[v487_b];
      int v390_b = v386_b[v465_b];
      int v391_b = v388_b[v465_b];
      int * v392_b = (v347_p->b)->cache_dirty;
      int v490_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1)) & 3) * 2)) + ((((v387_b + ((~(((v389_b ^ -1) | (-(v389_b ^ -1))) >> 31)) & 2)) - (v390_b + ((~(((v391_b ^ -1) | (-(v391_b ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v393_b = v392_b[v490_b];
      bool v491_b = !(v393_b == 0);
      if (v491_b) {
        int * v394_b = (v347_p->b)->cache_tags;
        int v395_b = v394_b[v490_b];
        int * v396_b = (v347_p->b)->cache_vals;
        int v494_b = ((4 + ((((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1)) & 3) * 2)) + ((((v387_b + ((~(((v389_b ^ -1) | (-(v389_b ^ -1))) >> 31)) & 2)) - (v390_b + ((~(((v391_b ^ -1) | (-(v391_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v397_b = v396_b[v494_b];
        int v495_b = (((4 + ((((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1)) & 3) * 2)) + ((((v387_b + ((~(((v389_b ^ -1) | (-(v389_b ^ -1))) >> 31)) & 2)) - (v390_b + ((~(((v391_b ^ -1) | (-(v391_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v398_b = v396_b[v495_b];
        int * v399_b = (v347_p->b)->mem;
        int v497_b = v395_b * 2;
        v399_b[v497_b] = v397_b;
        int * v401_b = (v347_p->b)->mem;
        int v500_b = (v395_b * 2) + 1;
        v401_b[v500_b] = v398_b;
        ;
      } else {
        ;
      }
      int * v406_b = (v347_p->b)->mem;
      int v505_b = ((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1)) * 2;
      int v407_b = v406_b[v505_b];
      int v506_b = (((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1)) * 2) + 1;
      int v408_b = v406_b[v506_b];
      int * v409_b = (v347_p->b)->cache_vals;
      int v508_b = ((4 + ((((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1)) & 3) * 2)) + ((((v387_b + ((~(((v389_b ^ -1) | (-(v389_b ^ -1))) >> 31)) & 2)) - (v390_b + ((~(((v391_b ^ -1) | (-(v391_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v409_b[v508_b] = v407_b;
      int * v411_b = (v347_p->b)->cache_vals;
      int v511_b = (((4 + ((((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1)) & 3) * 2)) + ((((v387_b + ((~(((v389_b ^ -1) | (-(v389_b ^ -1))) >> 31)) & 2)) - (v390_b + ((~(((v391_b ^ -1) | (-(v391_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v411_b[v511_b] = v408_b;
      int * v413_b = (v347_p->b)->cache_tags;
      int v514_b = (int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1);
      v413_b[v490_b] = v514_b;
      int * v415_b = (v347_p->b)->cache_dirty;
      v415_b[v490_b] = 0;
      int * v417_b = (v347_p->b)->cache_age;
      v417_b[v490_b] = 1;
      int * v419_b = (v347_p->b)->cache_age;
      int v420_b = v419_b[v490_b];
      int v421_b = v419_b[v464_b];
      int v520_b = v421_b + ((int)((unsigned int)(v421_b - v420_b) >> 31));
      v419_b[v464_b] = v520_b;
      int * v423_b = (v347_p->b)->cache_age;
      int v424_b = v423_b[v465_b];
      int v522_b = v424_b + ((int)((unsigned int)(v424_b - v420_b) >> 31));
      v423_b[v465_b] = v522_b;
      int * v426_b = (v347_p->b)->cache_age;
      v426_b[v490_b] = 0;
      v429_b = v490_b;
    }
    int * v430_b = (v347_p->b)->cache_vals;
    int v525_b = v429_b * 2;
    int v431_b = v430_b[v525_b];
    int v526_b = (v429_b * 2) + 1;
    int v432_b = v430_b[v526_b];
    int v527_b = (((((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1)) & 1) * 2) + ((((v371_b + ((~(((v373_b ^ -1) | (-(v373_b ^ -1))) >> 31)) & 2)) - (v374_b + ((~(((v375_b ^ -1) | (-(v375_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v430_b[v527_b] = v431_b;
    int * v434_b = (v347_p->b)->cache_vals;
    int v530_b = ((((((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1)) & 1) * 2) + ((((v371_b + ((~(((v373_b ^ -1) | (-(v373_b ^ -1))) >> 31)) & 2)) - (v374_b + ((~(((v375_b ^ -1) | (-(v375_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v434_b[v530_b] = v432_b;
    int * v436_b = (v347_p->b)->cache_tags;
    int v533_b = ((((int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1)) & 1) * 2) + ((((v371_b + ((~(((v373_b ^ -1) | (-(v373_b ^ -1))) >> 31)) & 2)) - (v374_b + ((~(((v375_b ^ -1) | (-(v375_b ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v534_b = (int)((unsigned int)((int)((unsigned int)v351_b >> 2)) >> 1);
    v436_b[v533_b] = v534_b;
    int * v438_b = (v347_p->b)->cache_dirty;
    v438_b[v533_b] = 0;
    int * v440_b = (v347_p->b)->cache_age;
    v440_b[v533_b] = 1;
    int * v442_b = (v347_p->b)->cache_age;
    int v443_b = v442_b[v533_b];
    int v444_b = v442_b[v462_b];
    int v540_b = v444_b + ((int)((unsigned int)(v444_b - v443_b) >> 31));
    v442_b[v462_b] = v540_b;
    int * v446_b = (v347_p->b)->cache_age;
    int v447_b = v446_b[v463_b];
    int v542_b = v447_b + ((int)((unsigned int)(v447_b - v443_b) >> 31));
    v446_b[v463_b] = v542_b;
    int * v449_b = (v347_p->b)->cache_age;
    v449_b[v533_b] = 0;
    v452_b = v533_b;
  }
  int v545_a = (v452_a * 2) + (((int)((unsigned int)v351_a >> 2)) & 1);
  int v545_b = (v452_b * 2) + (((int)((unsigned int)v351_b >> 2)) & 1);
  int v453_a = v359_a[v545_a];
  int v453_b = v359_b[v545_b];
  int * v454_a = (v347_p->a)->regs;
  int * v454_b = (v347_p->b)->regs;
  v454_a[9] = v453_a;
  v454_b[9] = v453_b;
  struct StateT2 * v456_p = slot_10(v347_p);
  return v456_p;
}

struct StateT2 * slot_11(struct StateT2 * v568_p) {
  lockstep_assert(((v568_p->a)->timer) == ((v568_p->b)->timer));
  lockstep_assume(((v568_p->a)->timer) == ((v568_p->b)->timer));
  int v569_a = (v568_p->a)->timer;
  int v569_b = (v568_p->b)->timer;
  int v577_a = v569_a + 1;
  int v577_b = v569_b + 1;
  (v568_p->a)->timer = v577_a;
  (v568_p->b)->timer = v577_b;
  int * v571_a = (v568_p->a)->regs;
  int * v571_b = (v568_p->b)->regs;
  int v572_a = v571_a[5];
  int v572_b = v571_b[5];
  int v573_a = v571_a[16];
  int v573_b = v571_b[16];
  int v581_a = v572_a | v573_a;
  int v581_b = v572_b | v573_b;
  v571_a[5] = v581_a;
  v571_b[5] = v581_b;
  struct StateT2 * v575_p = slot_12(v568_p);
  return v575_p;
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
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}