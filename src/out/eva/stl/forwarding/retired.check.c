// verify: leak widened (the program is clean; Eva cannot prove it) [unroll 65]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef EVA
#include "__fc_builtin.h"
/*@ assigns *p \from \nothing;
    taints *p; */
void koika_mark(int *p);
#define koika_assert(b, s) ((void)0)
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

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v17);
struct StateT * slot_8(struct StateT * v559);
struct StateT * slot_2(struct StateT * v31);
struct StateT * slot_7(struct StateT * v355);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v17) {
  int v18 = v17->timer;
  int v25 = v18 + 1;
  v17->timer = v25;
  int * v20 = v17->regs;
  int v21 = v20[6];
  int v28 = v21 + 80;
  v20[6] = v28;
  struct StateT * v23 = slot_2(v17);
  return v23;
}

struct StateT * slot_8(struct StateT * v559) {
  int v560 = v559->timer;
  int v669 = v560 + 1;
  v559->timer = v669;
  int * v562 = v559->regs;
  int v563 = v562[11];
  int * v564 = v559->cache_tags;
  int v673 = (((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1)) & 1) * 2;
  int v565 = v564[v673];
  int v674 = ((((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1)) & 1) * 2) + 1;
  int v566 = v564[v674];
  int v675 = 4 + ((((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1)) & 3) * 2);
  int v567 = v564[v675];
  int v676 = (4 + ((((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v568 = v564[v676];
  int v569 = v559->timer;
  int v677 = v569 + ((100 ^ (((~(((v567 ^ ((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1))) | (-(v567 ^ ((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1))))) >> 31)) | (~(((v568 ^ ((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1))) | (-(v568 ^ ((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v565 ^ ((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1))) | (-(v565 ^ ((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1))))) >> 31)) | (~(((v566 ^ ((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1))) | (-(v566 ^ ((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v567 ^ ((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1))) | (-(v567 ^ ((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1))))) >> 31)) | (~(((v568 ^ ((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1))) | (-(v568 ^ ((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1))))) >> 31))) & 104)))));
  v559->timer = v677;
  int * v571 = v559->cache_vals;
  bool v678 = !(((~(((v565 ^ ((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1))) | (-(v565 ^ ((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1))))) >> 31)) | (~(((v566 ^ ((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1))) | (-(v566 ^ ((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1))))) >> 31))) == 0);
  int v664;
  if (v678) {
    int * v572 = v559->cache_age;
    int v680 = ((((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1)) & 1) * 2) + ((~(((v566 ^ ((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1))) | (-(v566 ^ ((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1))))) >> 31)) & 1);
    int v573 = v572[v680];
    int v574 = v572[v673];
    int v681 = v574 + ((int)((unsigned int)(v574 - v573) >> 31));
    v572[v673] = v681;
    int * v576 = v559->cache_age;
    int v577 = v576[v674];
    int v683 = v577 + ((int)((unsigned int)(v577 - v573) >> 31));
    v576[v674] = v683;
    int * v579 = v559->cache_age;
    v579[v680] = 0;
    v664 = v680;
  } else {
    int * v582 = v559->cache_age;
    int v687 = (((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1)) & 1) * 2;
    int v583 = v582[v687];
    int * v584 = v559->cache_tags;
    int v585 = v584[v687];
    int v586 = v582[v674];
    int v587 = v584[v674];
    bool v689 = !(((~(((v567 ^ ((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1))) | (-(v567 ^ ((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1))))) >> 31)) | (~(((v568 ^ ((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1))) | (-(v568 ^ ((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1))))) >> 31))) == 0);
    int v641;
    if (v689) {
      int * v588 = v559->cache_age;
      int v691 = (4 + ((((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1)) & 3) * 2)) + ((~(((v568 ^ ((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1))) | (-(v568 ^ ((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1))))) >> 31)) & 1);
      int v589 = v588[v691];
      int v590 = v588[v675];
      int v692 = v590 + ((int)((unsigned int)(v590 - v589) >> 31));
      v588[v675] = v692;
      int * v592 = v559->cache_age;
      int v593 = v592[v676];
      int v694 = v593 + ((int)((unsigned int)(v593 - v589) >> 31));
      v592[v676] = v694;
      int * v595 = v559->cache_age;
      v595[v691] = 0;
      v641 = v691;
    } else {
      int * v598 = v559->cache_age;
      int v698 = 4 + ((((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1)) & 3) * 2);
      int v599 = v598[v698];
      int * v600 = v559->cache_tags;
      int v601 = v600[v698];
      int v602 = v598[v676];
      int v603 = v600[v676];
      int * v604 = v559->cache_dirty;
      int v701 = (4 + ((((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1)) & 3) * 2)) + ((((v599 + ((~(((v601 ^ -1) | (-(v601 ^ -1))) >> 31)) & 2)) - (v602 + ((~(((v603 ^ -1) | (-(v603 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v605 = v604[v701];
      bool v702 = !(v605 == 0);
      if (v702) {
        int * v606 = v559->cache_tags;
        int v607 = v606[v701];
        int * v608 = v559->cache_vals;
        int v705 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1)) & 3) * 2)) + ((((v599 + ((~(((v601 ^ -1) | (-(v601 ^ -1))) >> 31)) & 2)) - (v602 + ((~(((v603 ^ -1) | (-(v603 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v609 = v608[v705];
        int v706 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1)) & 3) * 2)) + ((((v599 + ((~(((v601 ^ -1) | (-(v601 ^ -1))) >> 31)) & 2)) - (v602 + ((~(((v603 ^ -1) | (-(v603 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v610 = v608[v706];
        int * v611 = v559->mem;
        int v708 = v607 * 2;
        v611[v708] = v609;
        int * v613 = v559->mem;
        int v711 = (v607 * 2) + 1;
        v613[v711] = v610;
        ;
      } else {
        ;
      }
      int * v618 = v559->mem;
      int v716 = ((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1)) * 2;
      int v619 = v618[v716];
      int v717 = (((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1)) * 2) + 1;
      int v620 = v618[v717];
      int * v621 = v559->cache_vals;
      int v719 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1)) & 3) * 2)) + ((((v599 + ((~(((v601 ^ -1) | (-(v601 ^ -1))) >> 31)) & 2)) - (v602 + ((~(((v603 ^ -1) | (-(v603 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v621[v719] = v619;
      int * v623 = v559->cache_vals;
      int v722 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1)) & 3) * 2)) + ((((v599 + ((~(((v601 ^ -1) | (-(v601 ^ -1))) >> 31)) & 2)) - (v602 + ((~(((v603 ^ -1) | (-(v603 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v623[v722] = v620;
      int * v625 = v559->cache_tags;
      int v725 = (int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1);
      v625[v701] = v725;
      int * v627 = v559->cache_dirty;
      v627[v701] = 0;
      int * v629 = v559->cache_age;
      v629[v701] = 1;
      int * v631 = v559->cache_age;
      int v632 = v631[v701];
      int v633 = v631[v675];
      int v731 = v633 + ((int)((unsigned int)(v633 - v632) >> 31));
      v631[v675] = v731;
      int * v635 = v559->cache_age;
      int v636 = v635[v676];
      int v733 = v636 + ((int)((unsigned int)(v636 - v632) >> 31));
      v635[v676] = v733;
      int * v638 = v559->cache_age;
      v638[v701] = 0;
      v641 = v701;
    }
    int * v642 = v559->cache_vals;
    int v736 = v641 * 2;
    int v643 = v642[v736];
    int v737 = (v641 * 2) + 1;
    int v644 = v642[v737];
    int v738 = (((((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1)) & 1) * 2) + ((((v583 + ((~(((v585 ^ -1) | (-(v585 ^ -1))) >> 31)) & 2)) - (v586 + ((~(((v587 ^ -1) | (-(v587 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v642[v738] = v643;
    int * v646 = v559->cache_vals;
    int v741 = ((((((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1)) & 1) * 2) + ((((v583 + ((~(((v585 ^ -1) | (-(v585 ^ -1))) >> 31)) & 2)) - (v586 + ((~(((v587 ^ -1) | (-(v587 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v646[v741] = v644;
    int * v648 = v559->cache_tags;
    int v744 = ((((int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1)) & 1) * 2) + ((((v583 + ((~(((v585 ^ -1) | (-(v585 ^ -1))) >> 31)) & 2)) - (v586 + ((~(((v587 ^ -1) | (-(v587 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v745 = (int)((unsigned int)((int)((unsigned int)v563 >> 2)) >> 1);
    v648[v744] = v745;
    int * v650 = v559->cache_dirty;
    v650[v744] = 0;
    int * v652 = v559->cache_age;
    v652[v744] = 1;
    int * v654 = v559->cache_age;
    int v655 = v654[v744];
    int v656 = v654[v673];
    int v751 = v656 + ((int)((unsigned int)(v656 - v655) >> 31));
    v654[v673] = v751;
    int * v658 = v559->cache_age;
    int v659 = v658[v674];
    int v753 = v659 + ((int)((unsigned int)(v659 - v655) >> 31));
    v658[v674] = v753;
    int * v661 = v559->cache_age;
    v661[v744] = 0;
    v664 = v744;
  }
  int v756 = (v664 * 2) + (((int)((unsigned int)v563 >> 2)) & 1);
  int v665 = v571[v756];
  int * v666 = v559->regs;
  v666[12] = v665;
  return v559;
}

struct StateT * slot_2(struct StateT * v31) {
  int v32 = v31->timer;
  int v212 = v32 + 1;
  v31->timer = v212;
  int * v34 = v31->regs;
  int v35 = v34[6];
  int * v36 = v31->saved_regs;
  int v37 = v34[0];
  v36[0] = v37;
  int v39 = v31->timer;
  int v218 = v39 + 1;
  v31->timer = v218;
  int v41 = v31->timer;
  int v219 = v41 + 1;
  v31->timer = v219;
  int v43 = v31->timer;
  int v220 = v43 + 1;
  v31->timer = v220;
  int v45 = v31->timer;
  int v221 = v45 + 1;
  v31->timer = v221;
  int * v47 = v31->cache_tags;
  int v223 = (((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 1) * 2;
  int v48 = v47[v223];
  int v224 = ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 1) * 2) + 1;
  int v49 = v47[v224];
  int v225 = 4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2);
  int v50 = v47[v225];
  int v226 = (4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v51 = v47[v226];
  int v52 = v31->timer;
  int v227 = v52 + ((100 ^ (((~(((v50 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v50 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31)) | (~(((v51 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v51 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v48 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v48 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31)) | (~(((v49 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v49 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v50 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v50 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31)) | (~(((v51 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v51 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31))) & 104)))));
  v31->timer = v227;
  bool v228 = !(((~(((v48 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v48 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31)) | (~(((v49 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v49 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31))) == 0);
  int v146;
  if (v228) {
    int * v54 = v31->cache_age;
    int v230 = ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 1) * 2) + ((~(((v49 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v49 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31)) & 1);
    int v55 = v54[v230];
    int v56 = v54[v223];
    int v231 = v56 + ((int)((unsigned int)(v56 - v55) >> 31));
    v54[v223] = v231;
    int * v58 = v31->cache_age;
    int v59 = v58[v224];
    int v233 = v59 + ((int)((unsigned int)(v59 - v55) >> 31));
    v58[v224] = v233;
    int * v61 = v31->cache_age;
    v61[v230] = 0;
    v146 = v230;
  } else {
    int * v64 = v31->cache_age;
    int v236 = (((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 1) * 2;
    int v65 = v64[v236];
    int * v66 = v31->cache_tags;
    int v67 = v66[v236];
    int v68 = v64[v224];
    int v69 = v66[v224];
    bool v238 = !(((~(((v50 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v50 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31)) | (~(((v51 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v51 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31))) == 0);
    int v123;
    if (v238) {
      int * v70 = v31->cache_age;
      int v240 = (4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((~(((v51 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v51 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31)) & 1);
      int v71 = v70[v240];
      int v72 = v70[v225];
      int v241 = v72 + ((int)((unsigned int)(v72 - v71) >> 31));
      v70[v225] = v241;
      int * v74 = v31->cache_age;
      int v75 = v74[v226];
      int v243 = v75 + ((int)((unsigned int)(v75 - v71) >> 31));
      v74[v226] = v243;
      int * v77 = v31->cache_age;
      v77[v240] = 0;
      v123 = v240;
    } else {
      int * v80 = v31->cache_age;
      int v246 = 4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2);
      int v81 = v80[v246];
      int * v82 = v31->cache_tags;
      int v83 = v82[v246];
      int v84 = v80[v226];
      int v85 = v82[v226];
      int * v86 = v31->cache_dirty;
      int v249 = (4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v81 + ((~(((v83 ^ -1) | (-(v83 ^ -1))) >> 31)) & 2)) - (v84 + ((~(((v85 ^ -1) | (-(v85 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v87 = v86[v249];
      bool v250 = !(v87 == 0);
      if (v250) {
        int * v88 = v31->cache_tags;
        int v89 = v88[v249];
        int * v90 = v31->cache_vals;
        int v253 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v81 + ((~(((v83 ^ -1) | (-(v83 ^ -1))) >> 31)) & 2)) - (v84 + ((~(((v85 ^ -1) | (-(v85 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v91 = v90[v253];
        int v254 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v81 + ((~(((v83 ^ -1) | (-(v83 ^ -1))) >> 31)) & 2)) - (v84 + ((~(((v85 ^ -1) | (-(v85 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v92 = v90[v254];
        int * v93 = v31->mem;
        int v256 = v89 * 2;
        v93[v256] = v91;
        int * v95 = v31->mem;
        int v259 = (v89 * 2) + 1;
        v95[v259] = v92;
        ;
      } else {
        ;
      }
      int * v100 = v31->mem;
      int v264 = ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) * 2;
      int v101 = v100[v264];
      int v265 = (((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) * 2) + 1;
      int v102 = v100[v265];
      int * v103 = v31->cache_vals;
      int v267 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v81 + ((~(((v83 ^ -1) | (-(v83 ^ -1))) >> 31)) & 2)) - (v84 + ((~(((v85 ^ -1) | (-(v85 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v103[v267] = v101;
      int * v105 = v31->cache_vals;
      int v270 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v81 + ((~(((v83 ^ -1) | (-(v83 ^ -1))) >> 31)) & 2)) - (v84 + ((~(((v85 ^ -1) | (-(v85 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v105[v270] = v102;
      int * v107 = v31->cache_tags;
      int v273 = (int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1);
      v107[v249] = v273;
      int * v109 = v31->cache_dirty;
      v109[v249] = 0;
      int * v111 = v31->cache_age;
      v111[v249] = 1;
      int * v113 = v31->cache_age;
      int v114 = v113[v249];
      int v115 = v113[v225];
      int v278 = v115 + ((int)((unsigned int)(v115 - v114) >> 31));
      v113[v225] = v278;
      int * v117 = v31->cache_age;
      int v118 = v117[v226];
      int v280 = v118 + ((int)((unsigned int)(v118 - v114) >> 31));
      v117[v226] = v280;
      int * v120 = v31->cache_age;
      v120[v249] = 0;
      v123 = v249;
    }
    int * v124 = v31->cache_vals;
    int v283 = v123 * 2;
    int v125 = v124[v283];
    int v284 = (v123 * 2) + 1;
    int v126 = v124[v284];
    int v285 = (((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 1) * 2) + ((((v65 + ((~(((v67 ^ -1) | (-(v67 ^ -1))) >> 31)) & 2)) - (v68 + ((~(((v69 ^ -1) | (-(v69 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v124[v285] = v125;
    int * v128 = v31->cache_vals;
    int v288 = ((((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 1) * 2) + ((((v65 + ((~(((v67 ^ -1) | (-(v67 ^ -1))) >> 31)) & 2)) - (v68 + ((~(((v69 ^ -1) | (-(v69 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v128[v288] = v126;
    int * v130 = v31->cache_tags;
    int v291 = ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 1) * 2) + ((((v65 + ((~(((v67 ^ -1) | (-(v67 ^ -1))) >> 31)) & 2)) - (v68 + ((~(((v69 ^ -1) | (-(v69 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v292 = (int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1);
    v130[v291] = v292;
    int * v132 = v31->cache_dirty;
    v132[v291] = 0;
    int * v134 = v31->cache_age;
    v134[v291] = 1;
    int * v136 = v31->cache_age;
    int v137 = v136[v291];
    int v138 = v136[v223];
    int v297 = v138 + ((int)((unsigned int)(v138 - v137) >> 31));
    v136[v223] = v297;
    int * v140 = v31->cache_age;
    int v141 = v140[v224];
    int v299 = v141 + ((int)((unsigned int)(v141 - v137) >> 31));
    v140[v224] = v299;
    int * v143 = v31->cache_age;
    v143[v291] = 0;
    v146 = v291;
  }
  int * v147 = v31->cache_vals;
  int v302 = (v146 * 2) + (((int)((unsigned int)v35 >> 2)) & 1);
  v147[v302] = 0;
  int * v149 = v31->cache_tags;
  int v150 = v149[v225];
  int v151 = v149[v226];
  bool v304 = !(((~(((v150 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v150 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31)) | (~(((v151 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v151 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31))) == 0);
  int v205;
  if (v304) {
    int * v152 = v31->cache_age;
    int v306 = (4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((~(((v151 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v151 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31)) & 1);
    int v153 = v152[v306];
    int v154 = v152[v225];
    int v307 = v154 + ((int)((unsigned int)(v154 - v153) >> 31));
    v152[v225] = v307;
    int * v156 = v31->cache_age;
    int v157 = v156[v226];
    int v309 = v157 + ((int)((unsigned int)(v157 - v153) >> 31));
    v156[v226] = v309;
    int * v159 = v31->cache_age;
    v159[v306] = 0;
    v205 = v306;
  } else {
    int * v162 = v31->cache_age;
    int v312 = 4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2);
    int v163 = v162[v312];
    int * v164 = v31->cache_tags;
    int v165 = v164[v312];
    int v166 = v162[v226];
    int v167 = v164[v226];
    int * v168 = v31->cache_dirty;
    int v315 = (4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v163 + ((~(((v165 ^ -1) | (-(v165 ^ -1))) >> 31)) & 2)) - (v166 + ((~(((v167 ^ -1) | (-(v167 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v169 = v168[v315];
    bool v316 = !(v169 == 0);
    if (v316) {
      int * v170 = v31->cache_tags;
      int v171 = v170[v315];
      int * v172 = v31->cache_vals;
      int v319 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v163 + ((~(((v165 ^ -1) | (-(v165 ^ -1))) >> 31)) & 2)) - (v166 + ((~(((v167 ^ -1) | (-(v167 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v173 = v172[v319];
      int v320 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v163 + ((~(((v165 ^ -1) | (-(v165 ^ -1))) >> 31)) & 2)) - (v166 + ((~(((v167 ^ -1) | (-(v167 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v174 = v172[v320];
      int * v175 = v31->mem;
      int v322 = v171 * 2;
      v175[v322] = v173;
      int * v177 = v31->mem;
      int v325 = (v171 * 2) + 1;
      v177[v325] = v174;
      ;
    } else {
      ;
    }
    int * v182 = v31->mem;
    int v330 = ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) * 2;
    int v183 = v182[v330];
    int v331 = (((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) * 2) + 1;
    int v184 = v182[v331];
    int * v185 = v31->cache_vals;
    int v333 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v163 + ((~(((v165 ^ -1) | (-(v165 ^ -1))) >> 31)) & 2)) - (v166 + ((~(((v167 ^ -1) | (-(v167 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v185[v333] = v183;
    int * v187 = v31->cache_vals;
    int v336 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v163 + ((~(((v165 ^ -1) | (-(v165 ^ -1))) >> 31)) & 2)) - (v166 + ((~(((v167 ^ -1) | (-(v167 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v187[v336] = v184;
    int * v189 = v31->cache_tags;
    int v339 = (int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1);
    v189[v315] = v339;
    int * v191 = v31->cache_dirty;
    v191[v315] = 0;
    int * v193 = v31->cache_age;
    v193[v315] = 1;
    int * v195 = v31->cache_age;
    int v196 = v195[v315];
    int v197 = v195[v225];
    int v344 = v197 + ((int)((unsigned int)(v197 - v196) >> 31));
    v195[v225] = v344;
    int * v199 = v31->cache_age;
    int v200 = v199[v226];
    int v346 = v200 + ((int)((unsigned int)(v200 - v196) >> 31));
    v199[v226] = v346;
    int * v202 = v31->cache_age;
    v202[v315] = 0;
    v205 = v315;
  }
  int * v206 = v31->cache_vals;
  int v349 = (v205 * 2) + (((int)((unsigned int)v35 >> 2)) & 1);
  v206[v349] = 0;
  int * v208 = v31->cache_dirty;
  v208[v205] = 1;
  struct StateT * v210 = slot_7(v31);
  return v210;
}

struct StateT * slot_7(struct StateT * v355) {
  int v356 = v355->timer;
  int v466 = v356 + 1;
  v355->timer = v466;
  int * v358 = v355->regs;
  int v359 = v358[6];
  int * v360 = v355->cache_tags;
  int v470 = (((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1)) & 1) * 2;
  int v361 = v360[v470];
  int v471 = ((((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1)) & 1) * 2) + 1;
  int v362 = v360[v471];
  int v472 = 4 + ((((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1)) & 3) * 2);
  int v363 = v360[v472];
  int v473 = (4 + ((((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v364 = v360[v473];
  int v365 = v355->timer;
  int v474 = v365 + ((100 ^ (((~(((v363 ^ ((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1))) | (-(v363 ^ ((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1))))) >> 31)) | (~(((v364 ^ ((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1))) | (-(v364 ^ ((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v361 ^ ((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1))) | (-(v361 ^ ((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1))))) >> 31)) | (~(((v362 ^ ((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1))) | (-(v362 ^ ((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v363 ^ ((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1))) | (-(v363 ^ ((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1))))) >> 31)) | (~(((v364 ^ ((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1))) | (-(v364 ^ ((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1))))) >> 31))) & 104)))));
  v355->timer = v474;
  int * v367 = v355->cache_vals;
  bool v475 = !(((~(((v361 ^ ((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1))) | (-(v361 ^ ((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1))))) >> 31)) | (~(((v362 ^ ((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1))) | (-(v362 ^ ((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1))))) >> 31))) == 0);
  int v460;
  if (v475) {
    int * v368 = v355->cache_age;
    int v477 = ((((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1)) & 1) * 2) + ((~(((v362 ^ ((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1))) | (-(v362 ^ ((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1))))) >> 31)) & 1);
    int v369 = v368[v477];
    int v370 = v368[v470];
    int v478 = v370 + ((int)((unsigned int)(v370 - v369) >> 31));
    v368[v470] = v478;
    int * v372 = v355->cache_age;
    int v373 = v372[v471];
    int v480 = v373 + ((int)((unsigned int)(v373 - v369) >> 31));
    v372[v471] = v480;
    int * v375 = v355->cache_age;
    v375[v477] = 0;
    v460 = v477;
  } else {
    int * v378 = v355->cache_age;
    int v484 = (((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1)) & 1) * 2;
    int v379 = v378[v484];
    int * v380 = v355->cache_tags;
    int v381 = v380[v484];
    int v382 = v378[v471];
    int v383 = v380[v471];
    bool v486 = !(((~(((v363 ^ ((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1))) | (-(v363 ^ ((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1))))) >> 31)) | (~(((v364 ^ ((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1))) | (-(v364 ^ ((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1))))) >> 31))) == 0);
    int v437;
    if (v486) {
      int * v384 = v355->cache_age;
      int v488 = (4 + ((((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1)) & 3) * 2)) + ((~(((v364 ^ ((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1))) | (-(v364 ^ ((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1))))) >> 31)) & 1);
      int v385 = v384[v488];
      int v386 = v384[v472];
      int v489 = v386 + ((int)((unsigned int)(v386 - v385) >> 31));
      v384[v472] = v489;
      int * v388 = v355->cache_age;
      int v389 = v388[v473];
      int v491 = v389 + ((int)((unsigned int)(v389 - v385) >> 31));
      v388[v473] = v491;
      int * v391 = v355->cache_age;
      v391[v488] = 0;
      v437 = v488;
    } else {
      int * v394 = v355->cache_age;
      int v495 = 4 + ((((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1)) & 3) * 2);
      int v395 = v394[v495];
      int * v396 = v355->cache_tags;
      int v397 = v396[v495];
      int v398 = v394[v473];
      int v399 = v396[v473];
      int * v400 = v355->cache_dirty;
      int v498 = (4 + ((((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1)) & 3) * 2)) + ((((v395 + ((~(((v397 ^ -1) | (-(v397 ^ -1))) >> 31)) & 2)) - (v398 + ((~(((v399 ^ -1) | (-(v399 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v401 = v400[v498];
      bool v499 = !(v401 == 0);
      if (v499) {
        int * v402 = v355->cache_tags;
        int v403 = v402[v498];
        int * v404 = v355->cache_vals;
        int v502 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1)) & 3) * 2)) + ((((v395 + ((~(((v397 ^ -1) | (-(v397 ^ -1))) >> 31)) & 2)) - (v398 + ((~(((v399 ^ -1) | (-(v399 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v405 = v404[v502];
        int v503 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1)) & 3) * 2)) + ((((v395 + ((~(((v397 ^ -1) | (-(v397 ^ -1))) >> 31)) & 2)) - (v398 + ((~(((v399 ^ -1) | (-(v399 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v406 = v404[v503];
        int * v407 = v355->mem;
        int v505 = v403 * 2;
        v407[v505] = v405;
        int * v409 = v355->mem;
        int v508 = (v403 * 2) + 1;
        v409[v508] = v406;
        ;
      } else {
        ;
      }
      int * v414 = v355->mem;
      int v513 = ((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1)) * 2;
      int v415 = v414[v513];
      int v514 = (((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1)) * 2) + 1;
      int v416 = v414[v514];
      int * v417 = v355->cache_vals;
      int v516 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1)) & 3) * 2)) + ((((v395 + ((~(((v397 ^ -1) | (-(v397 ^ -1))) >> 31)) & 2)) - (v398 + ((~(((v399 ^ -1) | (-(v399 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v417[v516] = v415;
      int * v419 = v355->cache_vals;
      int v519 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1)) & 3) * 2)) + ((((v395 + ((~(((v397 ^ -1) | (-(v397 ^ -1))) >> 31)) & 2)) - (v398 + ((~(((v399 ^ -1) | (-(v399 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v419[v519] = v416;
      int * v421 = v355->cache_tags;
      int v522 = (int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1);
      v421[v498] = v522;
      int * v423 = v355->cache_dirty;
      v423[v498] = 0;
      int * v425 = v355->cache_age;
      v425[v498] = 1;
      int * v427 = v355->cache_age;
      int v428 = v427[v498];
      int v429 = v427[v472];
      int v528 = v429 + ((int)((unsigned int)(v429 - v428) >> 31));
      v427[v472] = v528;
      int * v431 = v355->cache_age;
      int v432 = v431[v473];
      int v530 = v432 + ((int)((unsigned int)(v432 - v428) >> 31));
      v431[v473] = v530;
      int * v434 = v355->cache_age;
      v434[v498] = 0;
      v437 = v498;
    }
    int * v438 = v355->cache_vals;
    int v533 = v437 * 2;
    int v439 = v438[v533];
    int v534 = (v437 * 2) + 1;
    int v440 = v438[v534];
    int v535 = (((((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1)) & 1) * 2) + ((((v379 + ((~(((v381 ^ -1) | (-(v381 ^ -1))) >> 31)) & 2)) - (v382 + ((~(((v383 ^ -1) | (-(v383 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v438[v535] = v439;
    int * v442 = v355->cache_vals;
    int v538 = ((((((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1)) & 1) * 2) + ((((v379 + ((~(((v381 ^ -1) | (-(v381 ^ -1))) >> 31)) & 2)) - (v382 + ((~(((v383 ^ -1) | (-(v383 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v442[v538] = v440;
    int * v444 = v355->cache_tags;
    int v541 = ((((int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1)) & 1) * 2) + ((((v379 + ((~(((v381 ^ -1) | (-(v381 ^ -1))) >> 31)) & 2)) - (v382 + ((~(((v383 ^ -1) | (-(v383 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v542 = (int)((unsigned int)((int)((unsigned int)v359 >> 2)) >> 1);
    v444[v541] = v542;
    int * v446 = v355->cache_dirty;
    v446[v541] = 0;
    int * v448 = v355->cache_age;
    v448[v541] = 1;
    int * v450 = v355->cache_age;
    int v451 = v450[v541];
    int v452 = v450[v470];
    int v548 = v452 + ((int)((unsigned int)(v452 - v451) >> 31));
    v450[v470] = v548;
    int * v454 = v355->cache_age;
    int v455 = v454[v471];
    int v550 = v455 + ((int)((unsigned int)(v455 - v451) >> 31));
    v454[v471] = v550;
    int * v457 = v355->cache_age;
    v457[v541] = 0;
    v460 = v541;
  }
  int v553 = (v460 * 2) + (((int)((unsigned int)v359 >> 2)) & 1);
  int v461 = v367[v553];
  int * v462 = v355->regs;
  v462[11] = v461;
  struct StateT * v464 = slot_8(v355);
  return v464;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v10 = v3 + 1;
  v2->timer = v10;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int v14 = v6 & 28;
  v5[6] = v14;
  struct StateT * v8 = slot_1(v2);
  return v8;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
    s->saved_regs[i] = 0;
    s->reg_ready[i] = 0;
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
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}