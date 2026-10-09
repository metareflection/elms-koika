// verify: clean (CBMC should report VERIFICATION SUCCESSFUL) [unwind 65]
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
struct StateT * slot_4(struct StateT * v546);
struct StateT * slot_2(struct StateT * v31);
struct StateT * slot_3(struct StateT * v342);
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

struct StateT * slot_4(struct StateT * v546) {
  int v547 = v546->timer;
  int v656 = v547 + 1;
  v546->timer = v656;
  int * v549 = v546->regs;
  int v550 = v549[11];
  int * v551 = v546->cache_tags;
  int v660 = (((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1)) & 1) * 2;
  int v552 = v551[v660];
  int v661 = ((((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1)) & 1) * 2) + 1;
  int v553 = v551[v661];
  int v662 = 4 + ((((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1)) & 3) * 2);
  int v554 = v551[v662];
  int v663 = (4 + ((((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v555 = v551[v663];
  int v556 = v546->timer;
  int v664 = v556 + ((100 ^ (((~(((v554 ^ ((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1))) | (-(v554 ^ ((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1))))) >> 31)) | (~(((v555 ^ ((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1))) | (-(v555 ^ ((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v552 ^ ((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1))) | (-(v552 ^ ((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1))))) >> 31)) | (~(((v553 ^ ((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1))) | (-(v553 ^ ((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v554 ^ ((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1))) | (-(v554 ^ ((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1))))) >> 31)) | (~(((v555 ^ ((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1))) | (-(v555 ^ ((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1))))) >> 31))) & 104)))));
  v546->timer = v664;
  int * v558 = v546->cache_vals;
  bool v665 = !(((~(((v552 ^ ((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1))) | (-(v552 ^ ((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1))))) >> 31)) | (~(((v553 ^ ((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1))) | (-(v553 ^ ((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1))))) >> 31))) == 0);
  int v651;
  if (v665) {
    int * v559 = v546->cache_age;
    int v667 = ((((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1)) & 1) * 2) + ((~(((v553 ^ ((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1))) | (-(v553 ^ ((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1))))) >> 31)) & 1);
    int v560 = v559[v667];
    int v561 = v559[v660];
    int v668 = v561 + ((int)((unsigned int)(v561 - v560) >> 31));
    v559[v660] = v668;
    int * v563 = v546->cache_age;
    int v564 = v563[v661];
    int v670 = v564 + ((int)((unsigned int)(v564 - v560) >> 31));
    v563[v661] = v670;
    int * v566 = v546->cache_age;
    v566[v667] = 0;
    v651 = v667;
  } else {
    int * v569 = v546->cache_age;
    int v674 = (((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1)) & 1) * 2;
    int v570 = v569[v674];
    int * v571 = v546->cache_tags;
    int v572 = v571[v674];
    int v573 = v569[v661];
    int v574 = v571[v661];
    bool v676 = !(((~(((v554 ^ ((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1))) | (-(v554 ^ ((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1))))) >> 31)) | (~(((v555 ^ ((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1))) | (-(v555 ^ ((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1))))) >> 31))) == 0);
    int v628;
    if (v676) {
      int * v575 = v546->cache_age;
      int v678 = (4 + ((((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1)) & 3) * 2)) + ((~(((v555 ^ ((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1))) | (-(v555 ^ ((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1))))) >> 31)) & 1);
      int v576 = v575[v678];
      int v577 = v575[v662];
      int v679 = v577 + ((int)((unsigned int)(v577 - v576) >> 31));
      v575[v662] = v679;
      int * v579 = v546->cache_age;
      int v580 = v579[v663];
      int v681 = v580 + ((int)((unsigned int)(v580 - v576) >> 31));
      v579[v663] = v681;
      int * v582 = v546->cache_age;
      v582[v678] = 0;
      v628 = v678;
    } else {
      int * v585 = v546->cache_age;
      int v685 = 4 + ((((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1)) & 3) * 2);
      int v586 = v585[v685];
      int * v587 = v546->cache_tags;
      int v588 = v587[v685];
      int v589 = v585[v663];
      int v590 = v587[v663];
      int * v591 = v546->cache_dirty;
      int v688 = (4 + ((((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1)) & 3) * 2)) + ((((v586 + ((~(((v588 ^ -1) | (-(v588 ^ -1))) >> 31)) & 2)) - (v589 + ((~(((v590 ^ -1) | (-(v590 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v592 = v591[v688];
      bool v689 = !(v592 == 0);
      if (v689) {
        int * v593 = v546->cache_tags;
        int v594 = v593[v688];
        int * v595 = v546->cache_vals;
        int v692 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1)) & 3) * 2)) + ((((v586 + ((~(((v588 ^ -1) | (-(v588 ^ -1))) >> 31)) & 2)) - (v589 + ((~(((v590 ^ -1) | (-(v590 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v596 = v595[v692];
        int v693 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1)) & 3) * 2)) + ((((v586 + ((~(((v588 ^ -1) | (-(v588 ^ -1))) >> 31)) & 2)) - (v589 + ((~(((v590 ^ -1) | (-(v590 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v597 = v595[v693];
        int * v598 = v546->mem;
        int v695 = v594 * 2;
        v598[v695] = v596;
        int * v600 = v546->mem;
        int v698 = (v594 * 2) + 1;
        v600[v698] = v597;
        ;
      } else {
        ;
      }
      int * v605 = v546->mem;
      int v703 = ((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1)) * 2;
      int v606 = v605[v703];
      int v704 = (((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1)) * 2) + 1;
      int v607 = v605[v704];
      int * v608 = v546->cache_vals;
      int v706 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1)) & 3) * 2)) + ((((v586 + ((~(((v588 ^ -1) | (-(v588 ^ -1))) >> 31)) & 2)) - (v589 + ((~(((v590 ^ -1) | (-(v590 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v608[v706] = v606;
      int * v610 = v546->cache_vals;
      int v709 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1)) & 3) * 2)) + ((((v586 + ((~(((v588 ^ -1) | (-(v588 ^ -1))) >> 31)) & 2)) - (v589 + ((~(((v590 ^ -1) | (-(v590 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v610[v709] = v607;
      int * v612 = v546->cache_tags;
      int v712 = (int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1);
      v612[v688] = v712;
      int * v614 = v546->cache_dirty;
      v614[v688] = 0;
      int * v616 = v546->cache_age;
      v616[v688] = 1;
      int * v618 = v546->cache_age;
      int v619 = v618[v688];
      int v620 = v618[v662];
      int v718 = v620 + ((int)((unsigned int)(v620 - v619) >> 31));
      v618[v662] = v718;
      int * v622 = v546->cache_age;
      int v623 = v622[v663];
      int v720 = v623 + ((int)((unsigned int)(v623 - v619) >> 31));
      v622[v663] = v720;
      int * v625 = v546->cache_age;
      v625[v688] = 0;
      v628 = v688;
    }
    int * v629 = v546->cache_vals;
    int v723 = v628 * 2;
    int v630 = v629[v723];
    int v724 = (v628 * 2) + 1;
    int v631 = v629[v724];
    int v725 = (((((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1)) & 1) * 2) + ((((v570 + ((~(((v572 ^ -1) | (-(v572 ^ -1))) >> 31)) & 2)) - (v573 + ((~(((v574 ^ -1) | (-(v574 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v629[v725] = v630;
    int * v633 = v546->cache_vals;
    int v728 = ((((((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1)) & 1) * 2) + ((((v570 + ((~(((v572 ^ -1) | (-(v572 ^ -1))) >> 31)) & 2)) - (v573 + ((~(((v574 ^ -1) | (-(v574 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v633[v728] = v631;
    int * v635 = v546->cache_tags;
    int v731 = ((((int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1)) & 1) * 2) + ((((v570 + ((~(((v572 ^ -1) | (-(v572 ^ -1))) >> 31)) & 2)) - (v573 + ((~(((v574 ^ -1) | (-(v574 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v732 = (int)((unsigned int)((int)((unsigned int)v550 >> 2)) >> 1);
    v635[v731] = v732;
    int * v637 = v546->cache_dirty;
    v637[v731] = 0;
    int * v639 = v546->cache_age;
    v639[v731] = 1;
    int * v641 = v546->cache_age;
    int v642 = v641[v731];
    int v643 = v641[v660];
    int v738 = v643 + ((int)((unsigned int)(v643 - v642) >> 31));
    v641[v660] = v738;
    int * v645 = v546->cache_age;
    int v646 = v645[v661];
    int v740 = v646 + ((int)((unsigned int)(v646 - v642) >> 31));
    v645[v661] = v740;
    int * v648 = v546->cache_age;
    v648[v731] = 0;
    v651 = v731;
  }
  int v743 = (v651 * 2) + (((int)((unsigned int)v550 >> 2)) & 1);
  int v652 = v558[v743];
  int * v653 = v546->regs;
  v653[12] = v652;
  return v546;
}

struct StateT * slot_2(struct StateT * v31) {
  int v32 = v31->timer;
  int v201 = v32 + 1;
  v31->timer = v201;
  int * v34 = v31->regs;
  int v35 = v34[6];
  int * v36 = v31->cache_tags;
  int v205 = (((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 1) * 2;
  int v37 = v36[v205];
  int v206 = ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 1) * 2) + 1;
  int v38 = v36[v206];
  int v207 = 4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2);
  int v39 = v36[v207];
  int v208 = (4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v40 = v36[v208];
  int v41 = v31->timer;
  int v209 = v41 + ((100 ^ (((~(((v39 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v39 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31)) | (~(((v40 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v40 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v37 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v37 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31)) | (~(((v38 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v38 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v39 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v39 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31)) | (~(((v40 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v40 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31))) & 104)))));
  v31->timer = v209;
  bool v210 = !(((~(((v37 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v37 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31)) | (~(((v38 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v38 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31))) == 0);
  int v135;
  if (v210) {
    int * v43 = v31->cache_age;
    int v212 = ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 1) * 2) + ((~(((v38 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v38 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31)) & 1);
    int v44 = v43[v212];
    int v45 = v43[v205];
    int v213 = v45 + ((int)((unsigned int)(v45 - v44) >> 31));
    v43[v205] = v213;
    int * v47 = v31->cache_age;
    int v48 = v47[v206];
    int v215 = v48 + ((int)((unsigned int)(v48 - v44) >> 31));
    v47[v206] = v215;
    int * v50 = v31->cache_age;
    v50[v212] = 0;
    v135 = v212;
  } else {
    int * v53 = v31->cache_age;
    int v219 = (((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 1) * 2;
    int v54 = v53[v219];
    int * v55 = v31->cache_tags;
    int v56 = v55[v219];
    int v57 = v53[v206];
    int v58 = v55[v206];
    bool v221 = !(((~(((v39 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v39 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31)) | (~(((v40 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v40 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31))) == 0);
    int v112;
    if (v221) {
      int * v59 = v31->cache_age;
      int v223 = (4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((~(((v40 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v40 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31)) & 1);
      int v60 = v59[v223];
      int v61 = v59[v207];
      int v224 = v61 + ((int)((unsigned int)(v61 - v60) >> 31));
      v59[v207] = v224;
      int * v63 = v31->cache_age;
      int v64 = v63[v208];
      int v226 = v64 + ((int)((unsigned int)(v64 - v60) >> 31));
      v63[v208] = v226;
      int * v66 = v31->cache_age;
      v66[v223] = 0;
      v112 = v223;
    } else {
      int * v69 = v31->cache_age;
      int v230 = 4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2);
      int v70 = v69[v230];
      int * v71 = v31->cache_tags;
      int v72 = v71[v230];
      int v73 = v69[v208];
      int v74 = v71[v208];
      int * v75 = v31->cache_dirty;
      int v233 = (4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2)) - (v73 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v76 = v75[v233];
      bool v234 = !(v76 == 0);
      if (v234) {
        int * v77 = v31->cache_tags;
        int v78 = v77[v233];
        int * v79 = v31->cache_vals;
        int v237 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2)) - (v73 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v80 = v79[v237];
        int v238 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2)) - (v73 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v81 = v79[v238];
        int * v82 = v31->mem;
        int v240 = v78 * 2;
        v82[v240] = v80;
        int * v84 = v31->mem;
        int v243 = (v78 * 2) + 1;
        v84[v243] = v81;
        ;
      } else {
        ;
      }
      int * v89 = v31->mem;
      int v248 = ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) * 2;
      int v90 = v89[v248];
      int v249 = (((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) * 2) + 1;
      int v91 = v89[v249];
      int * v92 = v31->cache_vals;
      int v251 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2)) - (v73 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v92[v251] = v90;
      int * v94 = v31->cache_vals;
      int v254 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2)) - (v73 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v94[v254] = v91;
      int * v96 = v31->cache_tags;
      int v257 = (int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1);
      v96[v233] = v257;
      int * v98 = v31->cache_dirty;
      v98[v233] = 0;
      int * v100 = v31->cache_age;
      v100[v233] = 1;
      int * v102 = v31->cache_age;
      int v103 = v102[v233];
      int v104 = v102[v207];
      int v263 = v104 + ((int)((unsigned int)(v104 - v103) >> 31));
      v102[v207] = v263;
      int * v106 = v31->cache_age;
      int v107 = v106[v208];
      int v265 = v107 + ((int)((unsigned int)(v107 - v103) >> 31));
      v106[v208] = v265;
      int * v109 = v31->cache_age;
      v109[v233] = 0;
      v112 = v233;
    }
    int * v113 = v31->cache_vals;
    int v268 = v112 * 2;
    int v114 = v113[v268];
    int v269 = (v112 * 2) + 1;
    int v115 = v113[v269];
    int v270 = (((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 1) * 2) + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v113[v270] = v114;
    int * v117 = v31->cache_vals;
    int v273 = ((((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 1) * 2) + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v117[v273] = v115;
    int * v119 = v31->cache_tags;
    int v276 = ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 1) * 2) + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v277 = (int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1);
    v119[v276] = v277;
    int * v121 = v31->cache_dirty;
    v121[v276] = 0;
    int * v123 = v31->cache_age;
    v123[v276] = 1;
    int * v125 = v31->cache_age;
    int v126 = v125[v276];
    int v127 = v125[v205];
    int v283 = v127 + ((int)((unsigned int)(v127 - v126) >> 31));
    v125[v205] = v283;
    int * v129 = v31->cache_age;
    int v130 = v129[v206];
    int v285 = v130 + ((int)((unsigned int)(v130 - v126) >> 31));
    v129[v206] = v285;
    int * v132 = v31->cache_age;
    v132[v276] = 0;
    v135 = v276;
  }
  int * v136 = v31->cache_vals;
  int v288 = (v135 * 2) + (((int)((unsigned int)v35 >> 2)) & 1);
  v136[v288] = 0;
  int * v138 = v31->cache_tags;
  int v139 = v138[v207];
  int v140 = v138[v208];
  bool v291 = !(((~(((v139 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v139 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31)) | (~(((v140 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v140 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31))) == 0);
  int v194;
  if (v291) {
    int * v141 = v31->cache_age;
    int v293 = (4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((~(((v140 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))) | (-(v140 ^ ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1))))) >> 31)) & 1);
    int v142 = v141[v293];
    int v143 = v141[v207];
    int v294 = v143 + ((int)((unsigned int)(v143 - v142) >> 31));
    v141[v207] = v294;
    int * v145 = v31->cache_age;
    int v146 = v145[v208];
    int v296 = v146 + ((int)((unsigned int)(v146 - v142) >> 31));
    v145[v208] = v296;
    int * v148 = v31->cache_age;
    v148[v293] = 0;
    v194 = v293;
  } else {
    int * v151 = v31->cache_age;
    int v299 = 4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2);
    int v152 = v151[v299];
    int * v153 = v31->cache_tags;
    int v154 = v153[v299];
    int v155 = v151[v208];
    int v156 = v153[v208];
    int * v157 = v31->cache_dirty;
    int v302 = (4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v152 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2)) - (v155 + ((~(((v156 ^ -1) | (-(v156 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v158 = v157[v302];
    bool v303 = !(v158 == 0);
    if (v303) {
      int * v159 = v31->cache_tags;
      int v160 = v159[v302];
      int * v161 = v31->cache_vals;
      int v306 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v152 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2)) - (v155 + ((~(((v156 ^ -1) | (-(v156 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v162 = v161[v306];
      int v307 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v152 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2)) - (v155 + ((~(((v156 ^ -1) | (-(v156 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v163 = v161[v307];
      int * v164 = v31->mem;
      int v309 = v160 * 2;
      v164[v309] = v162;
      int * v166 = v31->mem;
      int v312 = (v160 * 2) + 1;
      v166[v312] = v163;
      ;
    } else {
      ;
    }
    int * v171 = v31->mem;
    int v317 = ((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) * 2;
    int v172 = v171[v317];
    int v318 = (((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) * 2) + 1;
    int v173 = v171[v318];
    int * v174 = v31->cache_vals;
    int v320 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v152 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2)) - (v155 + ((~(((v156 ^ -1) | (-(v156 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v174[v320] = v172;
    int * v176 = v31->cache_vals;
    int v323 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1)) & 3) * 2)) + ((((v152 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2)) - (v155 + ((~(((v156 ^ -1) | (-(v156 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v176[v323] = v173;
    int * v178 = v31->cache_tags;
    int v326 = (int)((unsigned int)((int)((unsigned int)v35 >> 2)) >> 1);
    v178[v302] = v326;
    int * v180 = v31->cache_dirty;
    v180[v302] = 0;
    int * v182 = v31->cache_age;
    v182[v302] = 1;
    int * v184 = v31->cache_age;
    int v185 = v184[v302];
    int v186 = v184[v207];
    int v331 = v186 + ((int)((unsigned int)(v186 - v185) >> 31));
    v184[v207] = v331;
    int * v188 = v31->cache_age;
    int v189 = v188[v208];
    int v333 = v189 + ((int)((unsigned int)(v189 - v185) >> 31));
    v188[v208] = v333;
    int * v191 = v31->cache_age;
    v191[v302] = 0;
    v194 = v302;
  }
  int * v195 = v31->cache_vals;
  int v336 = (v194 * 2) + (((int)((unsigned int)v35 >> 2)) & 1);
  v195[v336] = 0;
  int * v197 = v31->cache_dirty;
  v197[v194] = 1;
  struct StateT * v199 = slot_3(v31);
  return v199;
}

struct StateT * slot_3(struct StateT * v342) {
  int v343 = v342->timer;
  int v453 = v343 + 1;
  v342->timer = v453;
  int * v345 = v342->regs;
  int v346 = v345[6];
  int * v347 = v342->cache_tags;
  int v457 = (((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1)) & 1) * 2;
  int v348 = v347[v457];
  int v458 = ((((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1)) & 1) * 2) + 1;
  int v349 = v347[v458];
  int v459 = 4 + ((((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1)) & 3) * 2);
  int v350 = v347[v459];
  int v460 = (4 + ((((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v351 = v347[v460];
  int v352 = v342->timer;
  int v461 = v352 + ((100 ^ (((~(((v350 ^ ((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1))) | (-(v350 ^ ((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1))))) >> 31)) | (~(((v351 ^ ((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1))) | (-(v351 ^ ((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v348 ^ ((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1))) | (-(v348 ^ ((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1))))) >> 31)) | (~(((v349 ^ ((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1))) | (-(v349 ^ ((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v350 ^ ((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1))) | (-(v350 ^ ((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1))))) >> 31)) | (~(((v351 ^ ((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1))) | (-(v351 ^ ((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1))))) >> 31))) & 104)))));
  v342->timer = v461;
  int * v354 = v342->cache_vals;
  bool v462 = !(((~(((v348 ^ ((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1))) | (-(v348 ^ ((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1))))) >> 31)) | (~(((v349 ^ ((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1))) | (-(v349 ^ ((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1))))) >> 31))) == 0);
  int v447;
  if (v462) {
    int * v355 = v342->cache_age;
    int v464 = ((((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1)) & 1) * 2) + ((~(((v349 ^ ((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1))) | (-(v349 ^ ((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1))))) >> 31)) & 1);
    int v356 = v355[v464];
    int v357 = v355[v457];
    int v465 = v357 + ((int)((unsigned int)(v357 - v356) >> 31));
    v355[v457] = v465;
    int * v359 = v342->cache_age;
    int v360 = v359[v458];
    int v467 = v360 + ((int)((unsigned int)(v360 - v356) >> 31));
    v359[v458] = v467;
    int * v362 = v342->cache_age;
    v362[v464] = 0;
    v447 = v464;
  } else {
    int * v365 = v342->cache_age;
    int v471 = (((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1)) & 1) * 2;
    int v366 = v365[v471];
    int * v367 = v342->cache_tags;
    int v368 = v367[v471];
    int v369 = v365[v458];
    int v370 = v367[v458];
    bool v473 = !(((~(((v350 ^ ((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1))) | (-(v350 ^ ((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1))))) >> 31)) | (~(((v351 ^ ((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1))) | (-(v351 ^ ((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1))))) >> 31))) == 0);
    int v424;
    if (v473) {
      int * v371 = v342->cache_age;
      int v475 = (4 + ((((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1)) & 3) * 2)) + ((~(((v351 ^ ((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1))) | (-(v351 ^ ((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1))))) >> 31)) & 1);
      int v372 = v371[v475];
      int v373 = v371[v459];
      int v476 = v373 + ((int)((unsigned int)(v373 - v372) >> 31));
      v371[v459] = v476;
      int * v375 = v342->cache_age;
      int v376 = v375[v460];
      int v478 = v376 + ((int)((unsigned int)(v376 - v372) >> 31));
      v375[v460] = v478;
      int * v378 = v342->cache_age;
      v378[v475] = 0;
      v424 = v475;
    } else {
      int * v381 = v342->cache_age;
      int v482 = 4 + ((((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1)) & 3) * 2);
      int v382 = v381[v482];
      int * v383 = v342->cache_tags;
      int v384 = v383[v482];
      int v385 = v381[v460];
      int v386 = v383[v460];
      int * v387 = v342->cache_dirty;
      int v485 = (4 + ((((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1)) & 3) * 2)) + ((((v382 + ((~(((v384 ^ -1) | (-(v384 ^ -1))) >> 31)) & 2)) - (v385 + ((~(((v386 ^ -1) | (-(v386 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v388 = v387[v485];
      bool v486 = !(v388 == 0);
      if (v486) {
        int * v389 = v342->cache_tags;
        int v390 = v389[v485];
        int * v391 = v342->cache_vals;
        int v489 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1)) & 3) * 2)) + ((((v382 + ((~(((v384 ^ -1) | (-(v384 ^ -1))) >> 31)) & 2)) - (v385 + ((~(((v386 ^ -1) | (-(v386 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v392 = v391[v489];
        int v490 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1)) & 3) * 2)) + ((((v382 + ((~(((v384 ^ -1) | (-(v384 ^ -1))) >> 31)) & 2)) - (v385 + ((~(((v386 ^ -1) | (-(v386 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v393 = v391[v490];
        int * v394 = v342->mem;
        int v492 = v390 * 2;
        v394[v492] = v392;
        int * v396 = v342->mem;
        int v495 = (v390 * 2) + 1;
        v396[v495] = v393;
        ;
      } else {
        ;
      }
      int * v401 = v342->mem;
      int v500 = ((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1)) * 2;
      int v402 = v401[v500];
      int v501 = (((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1)) * 2) + 1;
      int v403 = v401[v501];
      int * v404 = v342->cache_vals;
      int v503 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1)) & 3) * 2)) + ((((v382 + ((~(((v384 ^ -1) | (-(v384 ^ -1))) >> 31)) & 2)) - (v385 + ((~(((v386 ^ -1) | (-(v386 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v404[v503] = v402;
      int * v406 = v342->cache_vals;
      int v506 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1)) & 3) * 2)) + ((((v382 + ((~(((v384 ^ -1) | (-(v384 ^ -1))) >> 31)) & 2)) - (v385 + ((~(((v386 ^ -1) | (-(v386 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v406[v506] = v403;
      int * v408 = v342->cache_tags;
      int v509 = (int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1);
      v408[v485] = v509;
      int * v410 = v342->cache_dirty;
      v410[v485] = 0;
      int * v412 = v342->cache_age;
      v412[v485] = 1;
      int * v414 = v342->cache_age;
      int v415 = v414[v485];
      int v416 = v414[v459];
      int v515 = v416 + ((int)((unsigned int)(v416 - v415) >> 31));
      v414[v459] = v515;
      int * v418 = v342->cache_age;
      int v419 = v418[v460];
      int v517 = v419 + ((int)((unsigned int)(v419 - v415) >> 31));
      v418[v460] = v517;
      int * v421 = v342->cache_age;
      v421[v485] = 0;
      v424 = v485;
    }
    int * v425 = v342->cache_vals;
    int v520 = v424 * 2;
    int v426 = v425[v520];
    int v521 = (v424 * 2) + 1;
    int v427 = v425[v521];
    int v522 = (((((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1)) & 1) * 2) + ((((v366 + ((~(((v368 ^ -1) | (-(v368 ^ -1))) >> 31)) & 2)) - (v369 + ((~(((v370 ^ -1) | (-(v370 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v425[v522] = v426;
    int * v429 = v342->cache_vals;
    int v525 = ((((((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1)) & 1) * 2) + ((((v366 + ((~(((v368 ^ -1) | (-(v368 ^ -1))) >> 31)) & 2)) - (v369 + ((~(((v370 ^ -1) | (-(v370 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v429[v525] = v427;
    int * v431 = v342->cache_tags;
    int v528 = ((((int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1)) & 1) * 2) + ((((v366 + ((~(((v368 ^ -1) | (-(v368 ^ -1))) >> 31)) & 2)) - (v369 + ((~(((v370 ^ -1) | (-(v370 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v529 = (int)((unsigned int)((int)((unsigned int)v346 >> 2)) >> 1);
    v431[v528] = v529;
    int * v433 = v342->cache_dirty;
    v433[v528] = 0;
    int * v435 = v342->cache_age;
    v435[v528] = 1;
    int * v437 = v342->cache_age;
    int v438 = v437[v528];
    int v439 = v437[v457];
    int v535 = v439 + ((int)((unsigned int)(v439 - v438) >> 31));
    v437[v457] = v535;
    int * v441 = v342->cache_age;
    int v442 = v441[v458];
    int v537 = v442 + ((int)((unsigned int)(v442 - v438) >> 31));
    v441[v458] = v537;
    int * v444 = v342->cache_age;
    v444[v528] = 0;
    v447 = v528;
  }
  int v540 = (v447 * 2) + (((int)((unsigned int)v346 >> 2)) & 1);
  int v448 = v354[v540];
  int * v449 = v342->regs;
  v449[11] = v448;
  struct StateT * v451 = slot_4(v342);
  return v451;
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