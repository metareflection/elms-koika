// verify: leak (CBMC should report VERIFICATION FAILED) [unwind 129]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24
#define PHT_ENTRIES 128
#define HISTORY_BITS 4

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

struct StateG {
  int regs[32];
  int mem[64];
  int saved_regs[32];
  int reg_ready[32];
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int pht[128];
  int timer;
};

struct StateG * slot_12(struct StateG * v573);
struct StateG * slot_14(struct StateG * v985);
struct StateG * slot_5(struct StateG * v89);
struct StateG * slot_2(struct StateG * v28);
struct StateG * slot_7(struct StateG * v113);
struct StateG * slot_3(struct StateG * v41);
struct StateG * snippet(struct StateG * v0);
struct StateG * slot_10(struct StateG * v545);
struct StateG * slot_1(struct StateG * v15);
struct StateG * slot_8(struct StateG * v130);
struct StateG * slot_4(struct StateG * v61);
struct StateG * slot_13(struct StateG * v784);
struct StateG * slot_9(struct StateG * v341);
struct StateG * slot_11(struct StateG * v559);
struct StateG * slot_0(struct StateG * v2);
struct StateG * slot_12(struct StateG * v573) {
  int * v574 = v573->saved_regs;
  int * v575 = v573->regs;
  int v576 = v575[12];
  v574[12] = v576;
  int v578 = v573->timer;
  int v692 = v578 + 1;
  v573->timer = v692;
  int * v580 = v573->regs;
  int v581 = v580[11];
  int * v582 = v573->cache_tags;
  int v696 = (((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1)) & 1) * 2;
  int v583 = v582[v696];
  int v697 = ((((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1)) & 1) * 2) + 1;
  int v584 = v582[v697];
  int v698 = 4 + ((((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1)) & 3) * 2);
  int v585 = v582[v698];
  int v699 = (4 + ((((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v586 = v582[v699];
  int v587 = v573->timer;
  int v700 = v587 + ((100 ^ (((~(((v585 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))) | (-(v585 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))))) >> 31)) | (~(((v586 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))) | (-(v586 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v583 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))) | (-(v583 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))))) >> 31)) | (~(((v584 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))) | (-(v584 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v585 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))) | (-(v585 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))))) >> 31)) | (~(((v586 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))) | (-(v586 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))))) >> 31))) & 104)))));
  v573->timer = v700;
  int * v589 = v573->cache_vals;
  bool v701 = !(((~(((v583 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))) | (-(v583 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))))) >> 31)) | (~(((v584 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))) | (-(v584 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))))) >> 31))) == 0);
  int v682;
  if (v701) {
    int * v590 = v573->cache_age;
    int v703 = ((((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1)) & 1) * 2) + ((~(((v584 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))) | (-(v584 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))))) >> 31)) & 1);
    int v591 = v590[v703];
    int v592 = v590[v696];
    int v704 = v592 + ((int)((unsigned int)(v592 - v591) >> 31));
    v590[v696] = v704;
    int * v594 = v573->cache_age;
    int v595 = v594[v697];
    int v706 = v595 + ((int)((unsigned int)(v595 - v591) >> 31));
    v594[v697] = v706;
    int * v597 = v573->cache_age;
    v597[v703] = 0;
    v682 = v703;
  } else {
    int * v600 = v573->cache_age;
    int v710 = (((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1)) & 1) * 2;
    int v601 = v600[v710];
    int * v602 = v573->cache_tags;
    int v603 = v602[v710];
    int v604 = v600[v697];
    int v605 = v602[v697];
    bool v712 = !(((~(((v585 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))) | (-(v585 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))))) >> 31)) | (~(((v586 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))) | (-(v586 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))))) >> 31))) == 0);
    int v659;
    if (v712) {
      int * v606 = v573->cache_age;
      int v714 = (4 + ((((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1)) & 3) * 2)) + ((~(((v586 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))) | (-(v586 ^ ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1))))) >> 31)) & 1);
      int v607 = v606[v714];
      int v608 = v606[v698];
      int v715 = v608 + ((int)((unsigned int)(v608 - v607) >> 31));
      v606[v698] = v715;
      int * v610 = v573->cache_age;
      int v611 = v610[v699];
      int v717 = v611 + ((int)((unsigned int)(v611 - v607) >> 31));
      v610[v699] = v717;
      int * v613 = v573->cache_age;
      v613[v714] = 0;
      v659 = v714;
    } else {
      int * v616 = v573->cache_age;
      int v721 = 4 + ((((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1)) & 3) * 2);
      int v617 = v616[v721];
      int * v618 = v573->cache_tags;
      int v619 = v618[v721];
      int v620 = v616[v699];
      int v621 = v618[v699];
      int * v622 = v573->cache_dirty;
      int v724 = (4 + ((((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1)) & 3) * 2)) + ((((v617 + ((~(((v619 ^ -1) | (-(v619 ^ -1))) >> 31)) & 2)) - (v620 + ((~(((v621 ^ -1) | (-(v621 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v623 = v622[v724];
      bool v725 = !(v623 == 0);
      if (v725) {
        int * v624 = v573->cache_tags;
        int v625 = v624[v724];
        int * v626 = v573->cache_vals;
        int v728 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1)) & 3) * 2)) + ((((v617 + ((~(((v619 ^ -1) | (-(v619 ^ -1))) >> 31)) & 2)) - (v620 + ((~(((v621 ^ -1) | (-(v621 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v627 = v626[v728];
        int v729 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1)) & 3) * 2)) + ((((v617 + ((~(((v619 ^ -1) | (-(v619 ^ -1))) >> 31)) & 2)) - (v620 + ((~(((v621 ^ -1) | (-(v621 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v628 = v626[v729];
        int * v629 = v573->mem;
        int v731 = v625 * 2;
        v629[v731] = v627;
        int * v631 = v573->mem;
        int v734 = (v625 * 2) + 1;
        v631[v734] = v628;
        ;
      } else {
        ;
      }
      int * v636 = v573->mem;
      int v739 = ((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1)) * 2;
      int v637 = v636[v739];
      int v740 = (((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1)) * 2) + 1;
      int v638 = v636[v740];
      int * v639 = v573->cache_vals;
      int v742 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1)) & 3) * 2)) + ((((v617 + ((~(((v619 ^ -1) | (-(v619 ^ -1))) >> 31)) & 2)) - (v620 + ((~(((v621 ^ -1) | (-(v621 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v639[v742] = v637;
      int * v641 = v573->cache_vals;
      int v745 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1)) & 3) * 2)) + ((((v617 + ((~(((v619 ^ -1) | (-(v619 ^ -1))) >> 31)) & 2)) - (v620 + ((~(((v621 ^ -1) | (-(v621 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v641[v745] = v638;
      int * v643 = v573->cache_tags;
      int v748 = (int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1);
      v643[v724] = v748;
      int * v645 = v573->cache_dirty;
      v645[v724] = 0;
      int * v647 = v573->cache_age;
      v647[v724] = 1;
      int * v649 = v573->cache_age;
      int v650 = v649[v724];
      int v651 = v649[v698];
      int v754 = v651 + ((int)((unsigned int)(v651 - v650) >> 31));
      v649[v698] = v754;
      int * v653 = v573->cache_age;
      int v654 = v653[v699];
      int v756 = v654 + ((int)((unsigned int)(v654 - v650) >> 31));
      v653[v699] = v756;
      int * v656 = v573->cache_age;
      v656[v724] = 0;
      v659 = v724;
    }
    int * v660 = v573->cache_vals;
    int v759 = v659 * 2;
    int v661 = v660[v759];
    int v760 = (v659 * 2) + 1;
    int v662 = v660[v760];
    int v761 = (((((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1)) & 1) * 2) + ((((v601 + ((~(((v603 ^ -1) | (-(v603 ^ -1))) >> 31)) & 2)) - (v604 + ((~(((v605 ^ -1) | (-(v605 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v660[v761] = v661;
    int * v664 = v573->cache_vals;
    int v764 = ((((((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1)) & 1) * 2) + ((((v601 + ((~(((v603 ^ -1) | (-(v603 ^ -1))) >> 31)) & 2)) - (v604 + ((~(((v605 ^ -1) | (-(v605 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v664[v764] = v662;
    int * v666 = v573->cache_tags;
    int v767 = ((((int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1)) & 1) * 2) + ((((v601 + ((~(((v603 ^ -1) | (-(v603 ^ -1))) >> 31)) & 2)) - (v604 + ((~(((v605 ^ -1) | (-(v605 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v768 = (int)((unsigned int)((int)((unsigned int)v581 >> 2)) >> 1);
    v666[v767] = v768;
    int * v668 = v573->cache_dirty;
    v668[v767] = 0;
    int * v670 = v573->cache_age;
    v670[v767] = 1;
    int * v672 = v573->cache_age;
    int v673 = v672[v767];
    int v674 = v672[v696];
    int v774 = v674 + ((int)((unsigned int)(v674 - v673) >> 31));
    v672[v696] = v774;
    int * v676 = v573->cache_age;
    int v677 = v676[v697];
    int v776 = v677 + ((int)((unsigned int)(v677 - v673) >> 31));
    v676[v697] = v776;
    int * v679 = v573->cache_age;
    v679[v767] = 0;
    v682 = v767;
  }
  int v779 = (v682 * 2) + (((int)((unsigned int)v581 >> 2)) & 1);
  int v683 = v589[v779];
  int * v684 = v573->regs;
  v684[12] = v683;
  struct StateG * v686 = slot_14(v573);
  return v686;
}

struct StateG * slot_14(struct StateG * v985) {
  int * v986 = v985->regs;
  int v987 = v986[10];
  int v988 = v986[15];
  bool v1014 = v987 >= v988;
  struct StateG * v1009;
  if (v1014) {
    int * v989 = v985->pht;
    v989[0] = 1;
    int v991 = v985->timer;
    int v1018 = v991 + 15;
    v985->timer = v1018;
    int * v993 = v985->saved_regs;
    int v994 = v993[5];
    int * v995 = v985->regs;
    v995[5] = v994;
    int * v997 = v985->saved_regs;
    int v998 = v997[11];
    int * v999 = v985->regs;
    v999[11] = v998;
    int * v1001 = v985->saved_regs;
    int v1002 = v1001[12];
    int * v1003 = v985->regs;
    v1003[12] = v1002;
    v1009 = v985;
  } else {
    int * v1006 = v985->pht;
    v1006[0] = 0;
    v1009 = v985;
  }
  return v1009;
}

struct StateG * slot_5(struct StateG * v89) {
  int * v90 = v89->saved_regs;
  int * v91 = v89->regs;
  int v92 = v91[5];
  v90[5] = v92;
  int v94 = v89->timer;
  int v106 = v94 + 1;
  v89->timer = v106;
  int * v96 = v89->regs;
  int v97 = v96[13];
  int v98 = v96[10];
  int v110 = v97 + v98;
  v96[5] = v110;
  struct StateG * v100 = slot_8(v89);
  return v100;
}

struct StateG * slot_2(struct StateG * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[15] = 80;
  struct StateG * v33 = slot_3(v28);
  return v33;
}

struct StateG * slot_7(struct StateG * v113) {
  int v114 = v113->timer;
  int v122 = v114 + 1;
  v113->timer = v122;
  int * v116 = v113->regs;
  int v117 = v116[13];
  int v118 = v116[10];
  int v127 = v117 + v118;
  v116[5] = v127;
  struct StateG * v120 = slot_9(v113);
  return v120;
}

struct StateG * slot_3(struct StateG * v41) {
  int v42 = v41->timer;
  int v52 = v42 + 1;
  v41->timer = v52;
  int * v44 = v41->pht;
  int v45 = v44[0];
  bool v55 = !(v45 == 0);
  struct StateG * v50;
  if (v55) {
    struct StateG * v46 = slot_4(v41);
    v50 = v46;
  } else {
    struct StateG * v48 = slot_5(v41);
    v50 = v48;
  }
  return v50;
}

struct StateG * snippet(struct StateG * v0) {
  struct StateG * v1 = slot_0(v0);
  return v1;
}

struct StateG * slot_10(struct StateG * v545) {
  int v546 = v545->timer;
  int v553 = v546 + 1;
  v545->timer = v553;
  int * v548 = v545->regs;
  int v549 = v548[11];
  int v556 = v549 << 2;
  v548[11] = v556;
  struct StateG * v551 = slot_12(v545);
  return v551;
}

struct StateG * slot_1(struct StateG * v15) {
  int v16 = v15->timer;
  int v22 = v16 + 1;
  v15->timer = v22;
  int * v18 = v15->regs;
  v18[10] = 80;
  struct StateG * v20 = slot_2(v15);
  return v20;
}

struct StateG * slot_8(struct StateG * v130) {
  int * v131 = v130->saved_regs;
  int * v132 = v130->regs;
  int v133 = v132[11];
  v131[11] = v133;
  int v135 = v130->timer;
  int v249 = v135 + 1;
  v130->timer = v249;
  int * v137 = v130->regs;
  int v138 = v137[5];
  int * v139 = v130->cache_tags;
  int v253 = (((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1)) & 1) * 2;
  int v140 = v139[v253];
  int v254 = ((((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1)) & 1) * 2) + 1;
  int v141 = v139[v254];
  int v255 = 4 + ((((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1)) & 3) * 2);
  int v142 = v139[v255];
  int v256 = (4 + ((((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v143 = v139[v256];
  int v144 = v130->timer;
  int v257 = v144 + ((100 ^ (((~(((v142 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))) | (-(v142 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))))) >> 31)) | (~(((v143 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))) | (-(v143 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v140 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))) | (-(v140 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))))) >> 31)) | (~(((v141 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))) | (-(v141 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v142 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))) | (-(v142 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))))) >> 31)) | (~(((v143 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))) | (-(v143 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))))) >> 31))) & 104)))));
  v130->timer = v257;
  int * v146 = v130->cache_vals;
  bool v258 = !(((~(((v140 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))) | (-(v140 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))))) >> 31)) | (~(((v141 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))) | (-(v141 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))))) >> 31))) == 0);
  int v239;
  if (v258) {
    int * v147 = v130->cache_age;
    int v260 = ((((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1)) & 1) * 2) + ((~(((v141 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))) | (-(v141 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))))) >> 31)) & 1);
    int v148 = v147[v260];
    int v149 = v147[v253];
    int v261 = v149 + ((int)((unsigned int)(v149 - v148) >> 31));
    v147[v253] = v261;
    int * v151 = v130->cache_age;
    int v152 = v151[v254];
    int v263 = v152 + ((int)((unsigned int)(v152 - v148) >> 31));
    v151[v254] = v263;
    int * v154 = v130->cache_age;
    v154[v260] = 0;
    v239 = v260;
  } else {
    int * v157 = v130->cache_age;
    int v267 = (((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1)) & 1) * 2;
    int v158 = v157[v267];
    int * v159 = v130->cache_tags;
    int v160 = v159[v267];
    int v161 = v157[v254];
    int v162 = v159[v254];
    bool v269 = !(((~(((v142 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))) | (-(v142 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))))) >> 31)) | (~(((v143 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))) | (-(v143 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))))) >> 31))) == 0);
    int v216;
    if (v269) {
      int * v163 = v130->cache_age;
      int v271 = (4 + ((((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1)) & 3) * 2)) + ((~(((v143 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))) | (-(v143 ^ ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1))))) >> 31)) & 1);
      int v164 = v163[v271];
      int v165 = v163[v255];
      int v272 = v165 + ((int)((unsigned int)(v165 - v164) >> 31));
      v163[v255] = v272;
      int * v167 = v130->cache_age;
      int v168 = v167[v256];
      int v274 = v168 + ((int)((unsigned int)(v168 - v164) >> 31));
      v167[v256] = v274;
      int * v170 = v130->cache_age;
      v170[v271] = 0;
      v216 = v271;
    } else {
      int * v173 = v130->cache_age;
      int v278 = 4 + ((((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1)) & 3) * 2);
      int v174 = v173[v278];
      int * v175 = v130->cache_tags;
      int v176 = v175[v278];
      int v177 = v173[v256];
      int v178 = v175[v256];
      int * v179 = v130->cache_dirty;
      int v281 = (4 + ((((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1)) & 3) * 2)) + ((((v174 + ((~(((v176 ^ -1) | (-(v176 ^ -1))) >> 31)) & 2)) - (v177 + ((~(((v178 ^ -1) | (-(v178 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v180 = v179[v281];
      bool v282 = !(v180 == 0);
      if (v282) {
        int * v181 = v130->cache_tags;
        int v182 = v181[v281];
        int * v183 = v130->cache_vals;
        int v285 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1)) & 3) * 2)) + ((((v174 + ((~(((v176 ^ -1) | (-(v176 ^ -1))) >> 31)) & 2)) - (v177 + ((~(((v178 ^ -1) | (-(v178 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v184 = v183[v285];
        int v286 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1)) & 3) * 2)) + ((((v174 + ((~(((v176 ^ -1) | (-(v176 ^ -1))) >> 31)) & 2)) - (v177 + ((~(((v178 ^ -1) | (-(v178 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v185 = v183[v286];
        int * v186 = v130->mem;
        int v288 = v182 * 2;
        v186[v288] = v184;
        int * v188 = v130->mem;
        int v291 = (v182 * 2) + 1;
        v188[v291] = v185;
        ;
      } else {
        ;
      }
      int * v193 = v130->mem;
      int v296 = ((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1)) * 2;
      int v194 = v193[v296];
      int v297 = (((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1)) * 2) + 1;
      int v195 = v193[v297];
      int * v196 = v130->cache_vals;
      int v299 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1)) & 3) * 2)) + ((((v174 + ((~(((v176 ^ -1) | (-(v176 ^ -1))) >> 31)) & 2)) - (v177 + ((~(((v178 ^ -1) | (-(v178 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v196[v299] = v194;
      int * v198 = v130->cache_vals;
      int v302 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1)) & 3) * 2)) + ((((v174 + ((~(((v176 ^ -1) | (-(v176 ^ -1))) >> 31)) & 2)) - (v177 + ((~(((v178 ^ -1) | (-(v178 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v198[v302] = v195;
      int * v200 = v130->cache_tags;
      int v305 = (int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1);
      v200[v281] = v305;
      int * v202 = v130->cache_dirty;
      v202[v281] = 0;
      int * v204 = v130->cache_age;
      v204[v281] = 1;
      int * v206 = v130->cache_age;
      int v207 = v206[v281];
      int v208 = v206[v255];
      int v311 = v208 + ((int)((unsigned int)(v208 - v207) >> 31));
      v206[v255] = v311;
      int * v210 = v130->cache_age;
      int v211 = v210[v256];
      int v313 = v211 + ((int)((unsigned int)(v211 - v207) >> 31));
      v210[v256] = v313;
      int * v213 = v130->cache_age;
      v213[v281] = 0;
      v216 = v281;
    }
    int * v217 = v130->cache_vals;
    int v316 = v216 * 2;
    int v218 = v217[v316];
    int v317 = (v216 * 2) + 1;
    int v219 = v217[v317];
    int v318 = (((((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1)) & 1) * 2) + ((((v158 + ((~(((v160 ^ -1) | (-(v160 ^ -1))) >> 31)) & 2)) - (v161 + ((~(((v162 ^ -1) | (-(v162 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v217[v318] = v218;
    int * v221 = v130->cache_vals;
    int v321 = ((((((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1)) & 1) * 2) + ((((v158 + ((~(((v160 ^ -1) | (-(v160 ^ -1))) >> 31)) & 2)) - (v161 + ((~(((v162 ^ -1) | (-(v162 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v221[v321] = v219;
    int * v223 = v130->cache_tags;
    int v324 = ((((int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1)) & 1) * 2) + ((((v158 + ((~(((v160 ^ -1) | (-(v160 ^ -1))) >> 31)) & 2)) - (v161 + ((~(((v162 ^ -1) | (-(v162 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v325 = (int)((unsigned int)((int)((unsigned int)v138 >> 2)) >> 1);
    v223[v324] = v325;
    int * v225 = v130->cache_dirty;
    v225[v324] = 0;
    int * v227 = v130->cache_age;
    v227[v324] = 1;
    int * v229 = v130->cache_age;
    int v230 = v229[v324];
    int v231 = v229[v253];
    int v331 = v231 + ((int)((unsigned int)(v231 - v230) >> 31));
    v229[v253] = v331;
    int * v233 = v130->cache_age;
    int v234 = v233[v254];
    int v333 = v234 + ((int)((unsigned int)(v234 - v230) >> 31));
    v233[v254] = v333;
    int * v236 = v130->cache_age;
    v236[v324] = 0;
    v239 = v324;
  }
  int v336 = (v239 * 2) + (((int)((unsigned int)v138 >> 2)) & 1);
  int v240 = v146[v336];
  int * v241 = v130->regs;
  v241[11] = v240;
  struct StateG * v243 = slot_10(v130);
  return v243;
}

struct StateG * slot_4(struct StateG * v61) {
  int * v62 = v61->regs;
  int v63 = v62[10];
  int v64 = v62[15];
  bool v79 = v63 >= v64;
  struct StateG * v74;
  if (v79) {
    int * v65 = v61->pht;
    v65[0] = 1;
    v74 = v61;
  } else {
    int * v68 = v61->pht;
    v68[0] = 0;
    int v70 = v61->timer;
    int v85 = v70 + 15;
    v61->timer = v85;
    struct StateG * v72 = slot_7(v61);
    v74 = v72;
  }
  return v74;
}

struct StateG * slot_13(struct StateG * v784) {
  int v785 = v784->timer;
  int v894 = v785 + 1;
  v784->timer = v894;
  int * v787 = v784->regs;
  int v788 = v787[11];
  int * v789 = v784->cache_tags;
  int v898 = (((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1)) & 1) * 2;
  int v790 = v789[v898];
  int v899 = ((((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1)) & 1) * 2) + 1;
  int v791 = v789[v899];
  int v900 = 4 + ((((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1)) & 3) * 2);
  int v792 = v789[v900];
  int v901 = (4 + ((((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v793 = v789[v901];
  int v794 = v784->timer;
  int v902 = v794 + ((100 ^ (((~(((v792 ^ ((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1))) | (-(v792 ^ ((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1))))) >> 31)) | (~(((v793 ^ ((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1))) | (-(v793 ^ ((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v790 ^ ((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1))) | (-(v790 ^ ((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1))))) >> 31)) | (~(((v791 ^ ((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1))) | (-(v791 ^ ((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v792 ^ ((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1))) | (-(v792 ^ ((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1))))) >> 31)) | (~(((v793 ^ ((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1))) | (-(v793 ^ ((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1))))) >> 31))) & 104)))));
  v784->timer = v902;
  int * v796 = v784->cache_vals;
  bool v903 = !(((~(((v790 ^ ((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1))) | (-(v790 ^ ((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1))))) >> 31)) | (~(((v791 ^ ((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1))) | (-(v791 ^ ((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1))))) >> 31))) == 0);
  int v889;
  if (v903) {
    int * v797 = v784->cache_age;
    int v905 = ((((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1)) & 1) * 2) + ((~(((v791 ^ ((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1))) | (-(v791 ^ ((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1))))) >> 31)) & 1);
    int v798 = v797[v905];
    int v799 = v797[v898];
    int v906 = v799 + ((int)((unsigned int)(v799 - v798) >> 31));
    v797[v898] = v906;
    int * v801 = v784->cache_age;
    int v802 = v801[v899];
    int v908 = v802 + ((int)((unsigned int)(v802 - v798) >> 31));
    v801[v899] = v908;
    int * v804 = v784->cache_age;
    v804[v905] = 0;
    v889 = v905;
  } else {
    int * v807 = v784->cache_age;
    int v912 = (((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1)) & 1) * 2;
    int v808 = v807[v912];
    int * v809 = v784->cache_tags;
    int v810 = v809[v912];
    int v811 = v807[v899];
    int v812 = v809[v899];
    bool v914 = !(((~(((v792 ^ ((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1))) | (-(v792 ^ ((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1))))) >> 31)) | (~(((v793 ^ ((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1))) | (-(v793 ^ ((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1))))) >> 31))) == 0);
    int v866;
    if (v914) {
      int * v813 = v784->cache_age;
      int v916 = (4 + ((((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1)) & 3) * 2)) + ((~(((v793 ^ ((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1))) | (-(v793 ^ ((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1))))) >> 31)) & 1);
      int v814 = v813[v916];
      int v815 = v813[v900];
      int v917 = v815 + ((int)((unsigned int)(v815 - v814) >> 31));
      v813[v900] = v917;
      int * v817 = v784->cache_age;
      int v818 = v817[v901];
      int v919 = v818 + ((int)((unsigned int)(v818 - v814) >> 31));
      v817[v901] = v919;
      int * v820 = v784->cache_age;
      v820[v916] = 0;
      v866 = v916;
    } else {
      int * v823 = v784->cache_age;
      int v923 = 4 + ((((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1)) & 3) * 2);
      int v824 = v823[v923];
      int * v825 = v784->cache_tags;
      int v826 = v825[v923];
      int v827 = v823[v901];
      int v828 = v825[v901];
      int * v829 = v784->cache_dirty;
      int v926 = (4 + ((((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1)) & 3) * 2)) + ((((v824 + ((~(((v826 ^ -1) | (-(v826 ^ -1))) >> 31)) & 2)) - (v827 + ((~(((v828 ^ -1) | (-(v828 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v830 = v829[v926];
      bool v927 = !(v830 == 0);
      if (v927) {
        int * v831 = v784->cache_tags;
        int v832 = v831[v926];
        int * v833 = v784->cache_vals;
        int v930 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1)) & 3) * 2)) + ((((v824 + ((~(((v826 ^ -1) | (-(v826 ^ -1))) >> 31)) & 2)) - (v827 + ((~(((v828 ^ -1) | (-(v828 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v834 = v833[v930];
        int v931 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1)) & 3) * 2)) + ((((v824 + ((~(((v826 ^ -1) | (-(v826 ^ -1))) >> 31)) & 2)) - (v827 + ((~(((v828 ^ -1) | (-(v828 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v835 = v833[v931];
        int * v836 = v784->mem;
        int v933 = v832 * 2;
        v836[v933] = v834;
        int * v838 = v784->mem;
        int v936 = (v832 * 2) + 1;
        v838[v936] = v835;
        ;
      } else {
        ;
      }
      int * v843 = v784->mem;
      int v941 = ((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1)) * 2;
      int v844 = v843[v941];
      int v942 = (((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1)) * 2) + 1;
      int v845 = v843[v942];
      int * v846 = v784->cache_vals;
      int v944 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1)) & 3) * 2)) + ((((v824 + ((~(((v826 ^ -1) | (-(v826 ^ -1))) >> 31)) & 2)) - (v827 + ((~(((v828 ^ -1) | (-(v828 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v846[v944] = v844;
      int * v848 = v784->cache_vals;
      int v947 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1)) & 3) * 2)) + ((((v824 + ((~(((v826 ^ -1) | (-(v826 ^ -1))) >> 31)) & 2)) - (v827 + ((~(((v828 ^ -1) | (-(v828 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v848[v947] = v845;
      int * v850 = v784->cache_tags;
      int v950 = (int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1);
      v850[v926] = v950;
      int * v852 = v784->cache_dirty;
      v852[v926] = 0;
      int * v854 = v784->cache_age;
      v854[v926] = 1;
      int * v856 = v784->cache_age;
      int v857 = v856[v926];
      int v858 = v856[v900];
      int v956 = v858 + ((int)((unsigned int)(v858 - v857) >> 31));
      v856[v900] = v956;
      int * v860 = v784->cache_age;
      int v861 = v860[v901];
      int v958 = v861 + ((int)((unsigned int)(v861 - v857) >> 31));
      v860[v901] = v958;
      int * v863 = v784->cache_age;
      v863[v926] = 0;
      v866 = v926;
    }
    int * v867 = v784->cache_vals;
    int v961 = v866 * 2;
    int v868 = v867[v961];
    int v962 = (v866 * 2) + 1;
    int v869 = v867[v962];
    int v963 = (((((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1)) & 1) * 2) + ((((v808 + ((~(((v810 ^ -1) | (-(v810 ^ -1))) >> 31)) & 2)) - (v811 + ((~(((v812 ^ -1) | (-(v812 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v867[v963] = v868;
    int * v871 = v784->cache_vals;
    int v966 = ((((((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1)) & 1) * 2) + ((((v808 + ((~(((v810 ^ -1) | (-(v810 ^ -1))) >> 31)) & 2)) - (v811 + ((~(((v812 ^ -1) | (-(v812 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v871[v966] = v869;
    int * v873 = v784->cache_tags;
    int v969 = ((((int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1)) & 1) * 2) + ((((v808 + ((~(((v810 ^ -1) | (-(v810 ^ -1))) >> 31)) & 2)) - (v811 + ((~(((v812 ^ -1) | (-(v812 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v970 = (int)((unsigned int)((int)((unsigned int)v788 >> 2)) >> 1);
    v873[v969] = v970;
    int * v875 = v784->cache_dirty;
    v875[v969] = 0;
    int * v877 = v784->cache_age;
    v877[v969] = 1;
    int * v879 = v784->cache_age;
    int v880 = v879[v969];
    int v881 = v879[v898];
    int v976 = v881 + ((int)((unsigned int)(v881 - v880) >> 31));
    v879[v898] = v976;
    int * v883 = v784->cache_age;
    int v884 = v883[v899];
    int v978 = v884 + ((int)((unsigned int)(v884 - v880) >> 31));
    v883[v899] = v978;
    int * v886 = v784->cache_age;
    v886[v969] = 0;
    v889 = v969;
  }
  int v981 = (v889 * 2) + (((int)((unsigned int)v788 >> 2)) & 1);
  int v890 = v796[v981];
  int * v891 = v784->regs;
  v891[12] = v890;
  return v784;
}

struct StateG * slot_9(struct StateG * v341) {
  int v342 = v341->timer;
  int v452 = v342 + 1;
  v341->timer = v452;
  int * v344 = v341->regs;
  int v345 = v344[5];
  int * v346 = v341->cache_tags;
  int v456 = (((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1)) & 1) * 2;
  int v347 = v346[v456];
  int v457 = ((((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1)) & 1) * 2) + 1;
  int v348 = v346[v457];
  int v458 = 4 + ((((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1)) & 3) * 2);
  int v349 = v346[v458];
  int v459 = (4 + ((((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v350 = v346[v459];
  int v351 = v341->timer;
  int v460 = v351 + ((100 ^ (((~(((v349 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))) | (-(v349 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))))) >> 31)) | (~(((v350 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))) | (-(v350 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v347 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))) | (-(v347 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))))) >> 31)) | (~(((v348 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))) | (-(v348 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v349 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))) | (-(v349 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))))) >> 31)) | (~(((v350 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))) | (-(v350 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))))) >> 31))) & 104)))));
  v341->timer = v460;
  int * v353 = v341->cache_vals;
  bool v461 = !(((~(((v347 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))) | (-(v347 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))))) >> 31)) | (~(((v348 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))) | (-(v348 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))))) >> 31))) == 0);
  int v446;
  if (v461) {
    int * v354 = v341->cache_age;
    int v463 = ((((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1)) & 1) * 2) + ((~(((v348 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))) | (-(v348 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))))) >> 31)) & 1);
    int v355 = v354[v463];
    int v356 = v354[v456];
    int v464 = v356 + ((int)((unsigned int)(v356 - v355) >> 31));
    v354[v456] = v464;
    int * v358 = v341->cache_age;
    int v359 = v358[v457];
    int v466 = v359 + ((int)((unsigned int)(v359 - v355) >> 31));
    v358[v457] = v466;
    int * v361 = v341->cache_age;
    v361[v463] = 0;
    v446 = v463;
  } else {
    int * v364 = v341->cache_age;
    int v470 = (((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1)) & 1) * 2;
    int v365 = v364[v470];
    int * v366 = v341->cache_tags;
    int v367 = v366[v470];
    int v368 = v364[v457];
    int v369 = v366[v457];
    bool v472 = !(((~(((v349 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))) | (-(v349 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))))) >> 31)) | (~(((v350 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))) | (-(v350 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))))) >> 31))) == 0);
    int v423;
    if (v472) {
      int * v370 = v341->cache_age;
      int v474 = (4 + ((((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1)) & 3) * 2)) + ((~(((v350 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))) | (-(v350 ^ ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1))))) >> 31)) & 1);
      int v371 = v370[v474];
      int v372 = v370[v458];
      int v475 = v372 + ((int)((unsigned int)(v372 - v371) >> 31));
      v370[v458] = v475;
      int * v374 = v341->cache_age;
      int v375 = v374[v459];
      int v477 = v375 + ((int)((unsigned int)(v375 - v371) >> 31));
      v374[v459] = v477;
      int * v377 = v341->cache_age;
      v377[v474] = 0;
      v423 = v474;
    } else {
      int * v380 = v341->cache_age;
      int v481 = 4 + ((((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1)) & 3) * 2);
      int v381 = v380[v481];
      int * v382 = v341->cache_tags;
      int v383 = v382[v481];
      int v384 = v380[v459];
      int v385 = v382[v459];
      int * v386 = v341->cache_dirty;
      int v484 = (4 + ((((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1)) & 3) * 2)) + ((((v381 + ((~(((v383 ^ -1) | (-(v383 ^ -1))) >> 31)) & 2)) - (v384 + ((~(((v385 ^ -1) | (-(v385 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v387 = v386[v484];
      bool v485 = !(v387 == 0);
      if (v485) {
        int * v388 = v341->cache_tags;
        int v389 = v388[v484];
        int * v390 = v341->cache_vals;
        int v488 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1)) & 3) * 2)) + ((((v381 + ((~(((v383 ^ -1) | (-(v383 ^ -1))) >> 31)) & 2)) - (v384 + ((~(((v385 ^ -1) | (-(v385 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v391 = v390[v488];
        int v489 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1)) & 3) * 2)) + ((((v381 + ((~(((v383 ^ -1) | (-(v383 ^ -1))) >> 31)) & 2)) - (v384 + ((~(((v385 ^ -1) | (-(v385 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v392 = v390[v489];
        int * v393 = v341->mem;
        int v491 = v389 * 2;
        v393[v491] = v391;
        int * v395 = v341->mem;
        int v494 = (v389 * 2) + 1;
        v395[v494] = v392;
        ;
      } else {
        ;
      }
      int * v400 = v341->mem;
      int v499 = ((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1)) * 2;
      int v401 = v400[v499];
      int v500 = (((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1)) * 2) + 1;
      int v402 = v400[v500];
      int * v403 = v341->cache_vals;
      int v502 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1)) & 3) * 2)) + ((((v381 + ((~(((v383 ^ -1) | (-(v383 ^ -1))) >> 31)) & 2)) - (v384 + ((~(((v385 ^ -1) | (-(v385 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v403[v502] = v401;
      int * v405 = v341->cache_vals;
      int v505 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1)) & 3) * 2)) + ((((v381 + ((~(((v383 ^ -1) | (-(v383 ^ -1))) >> 31)) & 2)) - (v384 + ((~(((v385 ^ -1) | (-(v385 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v405[v505] = v402;
      int * v407 = v341->cache_tags;
      int v508 = (int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1);
      v407[v484] = v508;
      int * v409 = v341->cache_dirty;
      v409[v484] = 0;
      int * v411 = v341->cache_age;
      v411[v484] = 1;
      int * v413 = v341->cache_age;
      int v414 = v413[v484];
      int v415 = v413[v458];
      int v514 = v415 + ((int)((unsigned int)(v415 - v414) >> 31));
      v413[v458] = v514;
      int * v417 = v341->cache_age;
      int v418 = v417[v459];
      int v516 = v418 + ((int)((unsigned int)(v418 - v414) >> 31));
      v417[v459] = v516;
      int * v420 = v341->cache_age;
      v420[v484] = 0;
      v423 = v484;
    }
    int * v424 = v341->cache_vals;
    int v519 = v423 * 2;
    int v425 = v424[v519];
    int v520 = (v423 * 2) + 1;
    int v426 = v424[v520];
    int v521 = (((((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1)) & 1) * 2) + ((((v365 + ((~(((v367 ^ -1) | (-(v367 ^ -1))) >> 31)) & 2)) - (v368 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v424[v521] = v425;
    int * v428 = v341->cache_vals;
    int v524 = ((((((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1)) & 1) * 2) + ((((v365 + ((~(((v367 ^ -1) | (-(v367 ^ -1))) >> 31)) & 2)) - (v368 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v428[v524] = v426;
    int * v430 = v341->cache_tags;
    int v527 = ((((int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1)) & 1) * 2) + ((((v365 + ((~(((v367 ^ -1) | (-(v367 ^ -1))) >> 31)) & 2)) - (v368 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v528 = (int)((unsigned int)((int)((unsigned int)v345 >> 2)) >> 1);
    v430[v527] = v528;
    int * v432 = v341->cache_dirty;
    v432[v527] = 0;
    int * v434 = v341->cache_age;
    v434[v527] = 1;
    int * v436 = v341->cache_age;
    int v437 = v436[v527];
    int v438 = v436[v456];
    int v534 = v438 + ((int)((unsigned int)(v438 - v437) >> 31));
    v436[v456] = v534;
    int * v440 = v341->cache_age;
    int v441 = v440[v457];
    int v536 = v441 + ((int)((unsigned int)(v441 - v437) >> 31));
    v440[v457] = v536;
    int * v443 = v341->cache_age;
    v443[v527] = 0;
    v446 = v527;
  }
  int v539 = (v446 * 2) + (((int)((unsigned int)v345 >> 2)) & 1);
  int v447 = v353[v539];
  int * v448 = v341->regs;
  v448[11] = v447;
  struct StateG * v450 = slot_11(v341);
  return v450;
}

struct StateG * slot_11(struct StateG * v559) {
  int v560 = v559->timer;
  int v567 = v560 + 1;
  v559->timer = v567;
  int * v562 = v559->regs;
  int v563 = v562[11];
  int v570 = v563 << 2;
  v562[11] = v570;
  struct StateG * v565 = slot_13(v559);
  return v565;
}

struct StateG * slot_0(struct StateG * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[13] = 0;
  struct StateG * v7 = slot_1(v2);
  return v7;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateG *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
    s->saved_regs[i] = 0;
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
  for (int i=0; i<PHT_ENTRIES; i++) {
    s->pht[i] = 0;
  }
}

int main(int argc, char* argv[]) {
  struct StateG s1, s2;
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
  struct StateG *s1_ = snippet(&s1);
  struct StateG *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}