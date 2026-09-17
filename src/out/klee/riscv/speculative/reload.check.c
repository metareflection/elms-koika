// verify: leak (KLEE should report a failing assertion) [budget 1200s]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef KLEE
#include <assert.h>
#include <klee/klee.h>
#define koika_assert(b, s) klee_assert(b)
#define koika_assume(b) klee_assume(b)
#define koika_draw(x) klee_make_symbolic(&(x), sizeof(x), #x)
#else
#define koika_assert(b, s) 0
#define koika_assume(b) 0
#define koika_draw(x) ((x) = 0)
#endif
int bounded(int low, int high) {
  int x;
  koika_draw(x);
  koika_assume(low <= x && x <= high);
  return x;
}

/*****************************************
Emitting C Generated Code
*******************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v617);
struct StateT * slot_9(struct StateT * v625);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_3(struct StateT * v41);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v22 = v16 + 1;
  v15->timer = v22;
  int * v18 = v15->regs;
  v18[10] = 80;
  struct StateT * v20 = slot_2(v15);
  return v20;
}

struct StateT * slot_8(struct StateT * v617) {
  int v618 = v617->timer;
  int v622 = v618 + 1;
  v617->timer = v622;
  struct StateT * v620 = slot_9(v617);
  return v620;
}

struct StateT * slot_9(struct StateT * v625) {
  int v626 = v625->timer;
  int v756 = v626 + 1;
  v625->timer = v756;
  int * v628 = v625->cache_tags;
  int v629 = v628[0];
  int * v630 = v625->cache_tags;
  int v631 = v630[1];
  int * v632 = v625->cache_tags;
  int v633 = v632[4];
  int * v634 = v625->cache_tags;
  int v635 = v634[5];
  int v636 = v625->timer;
  int v765 = v636 + ((100 ^ (((~((v633 | (-v633)) >> 31)) | (~((v635 | (-v635)) >> 31))) & 104)) ^ (((~((v629 | (-v629)) >> 31)) | (~((v631 | (-v631)) >> 31))) & (1 ^ (100 ^ (((~((v633 | (-v633)) >> 31)) | (~((v635 | (-v635)) >> 31))) & 104)))));
  v625->timer = v765;
  int * v638 = v625->cache_vals;
  bool v766 = !(((~((v629 | (-v629)) >> 31)) | (~((v631 | (-v631)) >> 31))) == 0);
  int v751;
  if (v766) {
    int * v639 = v625->cache_age;
    int v768 = (~((v631 | (-v631)) >> 31)) & 1;
    int v640 = v639[v768];
    int * v641 = v625->cache_age;
    int v642 = v641[0];
    int * v643 = v625->cache_age;
    int v771 = v642 + ((int)((unsigned int)(v642 - v640) >> 31));
    v643[0] = v771;
    int * v645 = v625->cache_age;
    int v646 = v645[1];
    int * v647 = v625->cache_age;
    int v774 = v646 + ((int)((unsigned int)(v646 - v640) >> 31));
    v647[1] = v774;
    int * v649 = v625->cache_age;
    v649[v768] = 0;
    v751 = v768;
  } else {
    int * v652 = v625->cache_age;
    int v653 = v652[0];
    int * v654 = v625->cache_tags;
    int v655 = v654[0];
    int * v656 = v625->cache_age;
    int v657 = v656[1];
    int * v658 = v625->cache_tags;
    int v659 = v658[1];
    bool v780 = !(((~((v633 | (-v633)) >> 31)) | (~((v635 | (-v635)) >> 31))) == 0);
    int v723;
    if (v780) {
      int * v660 = v625->cache_age;
      int v782 = 4 + ((~((v635 | (-v635)) >> 31)) & 1);
      int v661 = v660[v782];
      int * v662 = v625->cache_age;
      int v663 = v662[4];
      int * v664 = v625->cache_age;
      int v785 = v663 + ((int)((unsigned int)(v663 - v661) >> 31));
      v664[4] = v785;
      int * v666 = v625->cache_age;
      int v667 = v666[5];
      int * v668 = v625->cache_age;
      int v788 = v667 + ((int)((unsigned int)(v667 - v661) >> 31));
      v668[5] = v788;
      int * v670 = v625->cache_age;
      v670[v782] = 0;
      v723 = v782;
    } else {
      int * v673 = v625->cache_age;
      int v674 = v673[4];
      int * v675 = v625->cache_tags;
      int v676 = v675[4];
      int * v677 = v625->cache_age;
      int v678 = v677[5];
      int * v679 = v625->cache_tags;
      int v680 = v679[5];
      int * v681 = v625->cache_dirty;
      int v795 = 4 + ((((v674 + ((~(((v676 ^ -1) | (-(v676 ^ -1))) >> 31)) & 2)) - (v678 + ((~(((v680 ^ -1) | (-(v680 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v682 = v681[v795];
      bool v796 = !(v682 == 0);
      if (v796) {
        int * v683 = v625->cache_tags;
        int v684 = v683[v795];
        int * v685 = v625->cache_vals;
        int v799 = (4 + ((((v674 + ((~(((v676 ^ -1) | (-(v676 ^ -1))) >> 31)) & 2)) - (v678 + ((~(((v680 ^ -1) | (-(v680 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v686 = v685[v799];
        int * v687 = v625->cache_vals;
        int v801 = ((4 + ((((v674 + ((~(((v676 ^ -1) | (-(v676 ^ -1))) >> 31)) & 2)) - (v678 + ((~(((v680 ^ -1) | (-(v680 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v688 = v687[v801];
        int * v689 = v625->mem;
        int v803 = v684 * 2;
        v689[v803] = v686;
        int * v691 = v625->mem;
        int v806 = (v684 * 2) + 1;
        v691[v806] = v688;
        ;
      } else {
        ;
      }
      int * v696 = v625->mem;
      int v697 = v696[0];
      int * v698 = v625->mem;
      int v699 = v698[1];
      int * v700 = v625->cache_vals;
      int v813 = (4 + ((((v674 + ((~(((v676 ^ -1) | (-(v676 ^ -1))) >> 31)) & 2)) - (v678 + ((~(((v680 ^ -1) | (-(v680 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v700[v813] = v697;
      int * v702 = v625->cache_vals;
      int v816 = ((4 + ((((v674 + ((~(((v676 ^ -1) | (-(v676 ^ -1))) >> 31)) & 2)) - (v678 + ((~(((v680 ^ -1) | (-(v680 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v702[v816] = v699;
      int * v704 = v625->cache_tags;
      v704[v795] = 0;
      int * v706 = v625->cache_dirty;
      v706[v795] = 0;
      int * v708 = v625->cache_age;
      v708[v795] = 1;
      int * v710 = v625->cache_age;
      int v711 = v710[v795];
      int * v712 = v625->cache_age;
      int v713 = v712[4];
      int * v714 = v625->cache_age;
      int v824 = v713 + ((int)((unsigned int)(v713 - v711) >> 31));
      v714[4] = v824;
      int * v716 = v625->cache_age;
      int v717 = v716[5];
      int * v718 = v625->cache_age;
      int v827 = v717 + ((int)((unsigned int)(v717 - v711) >> 31));
      v718[5] = v827;
      int * v720 = v625->cache_age;
      v720[v795] = 0;
      v723 = v795;
    }
    int * v724 = v625->cache_vals;
    int v830 = v723 * 2;
    int v725 = v724[v830];
    int * v726 = v625->cache_vals;
    int v832 = (v723 * 2) + 1;
    int v727 = v726[v832];
    int * v728 = v625->cache_vals;
    int v834 = ((((v653 + ((~(((v655 ^ -1) | (-(v655 ^ -1))) >> 31)) & 2)) - (v657 + ((~(((v659 ^ -1) | (-(v659 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v728[v834] = v725;
    int * v730 = v625->cache_vals;
    int v837 = (((((v653 + ((~(((v655 ^ -1) | (-(v655 ^ -1))) >> 31)) & 2)) - (v657 + ((~(((v659 ^ -1) | (-(v659 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v730[v837] = v727;
    int * v732 = v625->cache_tags;
    int v840 = (((v653 + ((~(((v655 ^ -1) | (-(v655 ^ -1))) >> 31)) & 2)) - (v657 + ((~(((v659 ^ -1) | (-(v659 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v732[v840] = 0;
    int * v734 = v625->cache_dirty;
    v734[v840] = 0;
    int * v736 = v625->cache_age;
    v736[v840] = 1;
    int * v738 = v625->cache_age;
    int v739 = v738[v840];
    int * v740 = v625->cache_age;
    int v741 = v740[0];
    int * v742 = v625->cache_age;
    int v846 = v741 + ((int)((unsigned int)(v741 - v739) >> 31));
    v742[0] = v846;
    int * v744 = v625->cache_age;
    int v745 = v744[1];
    int * v746 = v625->cache_age;
    int v849 = v745 + ((int)((unsigned int)(v745 - v739) >> 31));
    v746[1] = v849;
    int * v748 = v625->cache_age;
    v748[v840] = 0;
    v751 = v840;
  }
  int v852 = v751 * 2;
  int v752 = v638[v852];
  int * v753 = v625->regs;
  v753[14] = v752;
  return v625;
}

struct StateT * slot_2(struct StateT * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[15] = 80;
  struct StateT * v33 = slot_3(v28);
  return v33;
}

struct StateT * slot_3(struct StateT * v41) {
  int * v42 = v41->saved_regs;
  int * v43 = v41->regs;
  int v44 = v43[5];
  v42[5] = v44;
  int v46 = v41->timer;
  int v357 = v46 + 1;
  v41->timer = v357;
  int * v48 = v41->regs;
  int v49 = v48[13];
  int * v50 = v41->regs;
  int v51 = v50[10];
  int * v52 = v41->regs;
  int v363 = v49 + v51;
  v52[5] = v363;
  int * v54 = v41->saved_regs;
  int * v55 = v41->regs;
  int v56 = v55[11];
  v54[11] = v56;
  int v58 = v41->timer;
  int v368 = v58 + 1;
  v41->timer = v368;
  int * v60 = v41->regs;
  int v61 = v60[5];
  int * v62 = v41->cache_tags;
  int v371 = (((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 1) * 2;
  int v63 = v62[v371];
  int * v64 = v41->cache_tags;
  int v373 = ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 1) * 2) + 1;
  int v65 = v64[v373];
  int * v66 = v41->cache_tags;
  int v375 = 4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2);
  int v67 = v66[v375];
  int * v68 = v41->cache_tags;
  int v377 = (4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v69 = v68[v377];
  int v70 = v41->timer;
  int v378 = v70 + ((100 ^ (((~(((v67 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v67 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31)) | (~(((v69 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v69 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v63 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v63 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31)) | (~(((v65 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v65 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v67 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v67 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31)) | (~(((v69 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v69 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31))) & 104)))));
  v41->timer = v378;
  int * v72 = v41->cache_vals;
  bool v379 = !(((~(((v63 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v63 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31)) | (~(((v65 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v65 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31))) == 0);
  int v185;
  if (v379) {
    int * v73 = v41->cache_age;
    int v381 = ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 1) * 2) + ((~(((v65 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v65 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31)) & 1);
    int v74 = v73[v381];
    int * v75 = v41->cache_age;
    int v76 = v75[v371];
    int * v77 = v41->cache_age;
    int v384 = v76 + ((int)((unsigned int)(v76 - v74) >> 31));
    v77[v371] = v384;
    int * v79 = v41->cache_age;
    int v80 = v79[v373];
    int * v81 = v41->cache_age;
    int v387 = v80 + ((int)((unsigned int)(v80 - v74) >> 31));
    v81[v373] = v387;
    int * v83 = v41->cache_age;
    v83[v381] = 0;
    v185 = v381;
  } else {
    int * v86 = v41->cache_age;
    int v391 = (((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 1) * 2;
    int v87 = v86[v391];
    int * v88 = v41->cache_tags;
    int v89 = v88[v391];
    int * v90 = v41->cache_age;
    int v91 = v90[v373];
    int * v92 = v41->cache_tags;
    int v93 = v92[v373];
    bool v395 = !(((~(((v67 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v67 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31)) | (~(((v69 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v69 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31))) == 0);
    int v157;
    if (v395) {
      int * v94 = v41->cache_age;
      int v397 = (4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2)) + ((~(((v69 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))) | (-(v69 ^ ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1))))) >> 31)) & 1);
      int v95 = v94[v397];
      int * v96 = v41->cache_age;
      int v97 = v96[v375];
      int * v98 = v41->cache_age;
      int v400 = v97 + ((int)((unsigned int)(v97 - v95) >> 31));
      v98[v375] = v400;
      int * v100 = v41->cache_age;
      int v101 = v100[v377];
      int * v102 = v41->cache_age;
      int v403 = v101 + ((int)((unsigned int)(v101 - v95) >> 31));
      v102[v377] = v403;
      int * v104 = v41->cache_age;
      v104[v397] = 0;
      v157 = v397;
    } else {
      int * v107 = v41->cache_age;
      int v407 = 4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2);
      int v108 = v107[v407];
      int * v109 = v41->cache_tags;
      int v110 = v109[v407];
      int * v111 = v41->cache_age;
      int v112 = v111[v377];
      int * v113 = v41->cache_tags;
      int v114 = v113[v377];
      int * v115 = v41->cache_dirty;
      int v412 = (4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2)) + ((((v108 + ((~(((v110 ^ -1) | (-(v110 ^ -1))) >> 31)) & 2)) - (v112 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v116 = v115[v412];
      bool v413 = !(v116 == 0);
      if (v413) {
        int * v117 = v41->cache_tags;
        int v118 = v117[v412];
        int * v119 = v41->cache_vals;
        int v416 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2)) + ((((v108 + ((~(((v110 ^ -1) | (-(v110 ^ -1))) >> 31)) & 2)) - (v112 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v120 = v119[v416];
        int * v121 = v41->cache_vals;
        int v418 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2)) + ((((v108 + ((~(((v110 ^ -1) | (-(v110 ^ -1))) >> 31)) & 2)) - (v112 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v122 = v121[v418];
        int * v123 = v41->mem;
        int v420 = v118 * 2;
        v123[v420] = v120;
        int * v125 = v41->mem;
        int v423 = (v118 * 2) + 1;
        v125[v423] = v122;
        ;
      } else {
        ;
      }
      int * v130 = v41->mem;
      int v428 = ((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) * 2;
      int v131 = v130[v428];
      int * v132 = v41->mem;
      int v430 = (((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) * 2) + 1;
      int v133 = v132[v430];
      int * v134 = v41->cache_vals;
      int v432 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2)) + ((((v108 + ((~(((v110 ^ -1) | (-(v110 ^ -1))) >> 31)) & 2)) - (v112 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v134[v432] = v131;
      int * v136 = v41->cache_vals;
      int v435 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 3) * 2)) + ((((v108 + ((~(((v110 ^ -1) | (-(v110 ^ -1))) >> 31)) & 2)) - (v112 + ((~(((v114 ^ -1) | (-(v114 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v136[v435] = v133;
      int * v138 = v41->cache_tags;
      int v438 = (int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1);
      v138[v412] = v438;
      int * v140 = v41->cache_dirty;
      v140[v412] = 0;
      int * v142 = v41->cache_age;
      v142[v412] = 1;
      int * v144 = v41->cache_age;
      int v145 = v144[v412];
      int * v146 = v41->cache_age;
      int v147 = v146[v375];
      int * v148 = v41->cache_age;
      int v446 = v147 + ((int)((unsigned int)(v147 - v145) >> 31));
      v148[v375] = v446;
      int * v150 = v41->cache_age;
      int v151 = v150[v377];
      int * v152 = v41->cache_age;
      int v449 = v151 + ((int)((unsigned int)(v151 - v145) >> 31));
      v152[v377] = v449;
      int * v154 = v41->cache_age;
      v154[v412] = 0;
      v157 = v412;
    }
    int * v158 = v41->cache_vals;
    int v452 = v157 * 2;
    int v159 = v158[v452];
    int * v160 = v41->cache_vals;
    int v454 = (v157 * 2) + 1;
    int v161 = v160[v454];
    int * v162 = v41->cache_vals;
    int v456 = (((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 1) * 2) + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v91 + ((~(((v93 ^ -1) | (-(v93 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v162[v456] = v159;
    int * v164 = v41->cache_vals;
    int v459 = ((((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 1) * 2) + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v91 + ((~(((v93 ^ -1) | (-(v93 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v164[v459] = v161;
    int * v166 = v41->cache_tags;
    int v462 = ((((int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1)) & 1) * 2) + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v91 + ((~(((v93 ^ -1) | (-(v93 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v463 = (int)((unsigned int)((int)((unsigned int)v61 >> 2)) >> 1);
    v166[v462] = v463;
    int * v168 = v41->cache_dirty;
    v168[v462] = 0;
    int * v170 = v41->cache_age;
    v170[v462] = 1;
    int * v172 = v41->cache_age;
    int v173 = v172[v462];
    int * v174 = v41->cache_age;
    int v175 = v174[v371];
    int * v176 = v41->cache_age;
    int v471 = v175 + ((int)((unsigned int)(v175 - v173) >> 31));
    v176[v371] = v471;
    int * v178 = v41->cache_age;
    int v179 = v178[v373];
    int * v180 = v41->cache_age;
    int v474 = v179 + ((int)((unsigned int)(v179 - v173) >> 31));
    v180[v373] = v474;
    int * v182 = v41->cache_age;
    v182[v462] = 0;
    v185 = v462;
  }
  int v477 = (v185 * 2) + (((int)((unsigned int)v61 >> 2)) & 1);
  int v186 = v72[v477];
  int * v187 = v41->regs;
  v187[11] = v186;
  int v189 = v41->timer;
  int v480 = v189 + 1;
  v41->timer = v480;
  int * v191 = v41->regs;
  int v192 = v191[11];
  int * v193 = v41->regs;
  int v483 = v192 << 2;
  v193[11] = v483;
  int * v195 = v41->saved_regs;
  int * v196 = v41->regs;
  int v197 = v196[12];
  v195[12] = v197;
  int v199 = v41->timer;
  int v488 = v199 + 1;
  v41->timer = v488;
  int * v201 = v41->regs;
  int v202 = v201[11];
  int * v203 = v41->cache_tags;
  int v491 = (((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1)) & 1) * 2;
  int v204 = v203[v491];
  int * v205 = v41->cache_tags;
  int v493 = ((((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1)) & 1) * 2) + 1;
  int v206 = v205[v493];
  int * v207 = v41->cache_tags;
  int v495 = 4 + ((((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1)) & 3) * 2);
  int v208 = v207[v495];
  int * v209 = v41->cache_tags;
  int v497 = (4 + ((((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v210 = v209[v497];
  int v211 = v41->timer;
  int v498 = v211 + ((100 ^ (((~(((v208 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))) | (-(v208 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))))) >> 31)) | (~(((v210 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))) | (-(v210 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v204 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))) | (-(v204 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))))) >> 31)) | (~(((v206 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))) | (-(v206 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v208 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))) | (-(v208 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))))) >> 31)) | (~(((v210 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))) | (-(v210 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))))) >> 31))) & 104)))));
  v41->timer = v498;
  int * v213 = v41->cache_vals;
  bool v499 = !(((~(((v204 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))) | (-(v204 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))))) >> 31)) | (~(((v206 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))) | (-(v206 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))))) >> 31))) == 0);
  int v326;
  if (v499) {
    int * v214 = v41->cache_age;
    int v501 = ((((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1)) & 1) * 2) + ((~(((v206 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))) | (-(v206 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))))) >> 31)) & 1);
    int v215 = v214[v501];
    int * v216 = v41->cache_age;
    int v217 = v216[v491];
    int * v218 = v41->cache_age;
    int v504 = v217 + ((int)((unsigned int)(v217 - v215) >> 31));
    v218[v491] = v504;
    int * v220 = v41->cache_age;
    int v221 = v220[v493];
    int * v222 = v41->cache_age;
    int v507 = v221 + ((int)((unsigned int)(v221 - v215) >> 31));
    v222[v493] = v507;
    int * v224 = v41->cache_age;
    v224[v501] = 0;
    v326 = v501;
  } else {
    int * v227 = v41->cache_age;
    int v511 = (((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1)) & 1) * 2;
    int v228 = v227[v511];
    int * v229 = v41->cache_tags;
    int v230 = v229[v511];
    int * v231 = v41->cache_age;
    int v232 = v231[v493];
    int * v233 = v41->cache_tags;
    int v234 = v233[v493];
    bool v515 = !(((~(((v208 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))) | (-(v208 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))))) >> 31)) | (~(((v210 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))) | (-(v210 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))))) >> 31))) == 0);
    int v298;
    if (v515) {
      int * v235 = v41->cache_age;
      int v517 = (4 + ((((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1)) & 3) * 2)) + ((~(((v210 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))) | (-(v210 ^ ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1))))) >> 31)) & 1);
      int v236 = v235[v517];
      int * v237 = v41->cache_age;
      int v238 = v237[v495];
      int * v239 = v41->cache_age;
      int v520 = v238 + ((int)((unsigned int)(v238 - v236) >> 31));
      v239[v495] = v520;
      int * v241 = v41->cache_age;
      int v242 = v241[v497];
      int * v243 = v41->cache_age;
      int v523 = v242 + ((int)((unsigned int)(v242 - v236) >> 31));
      v243[v497] = v523;
      int * v245 = v41->cache_age;
      v245[v517] = 0;
      v298 = v517;
    } else {
      int * v248 = v41->cache_age;
      int v527 = 4 + ((((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1)) & 3) * 2);
      int v249 = v248[v527];
      int * v250 = v41->cache_tags;
      int v251 = v250[v527];
      int * v252 = v41->cache_age;
      int v253 = v252[v497];
      int * v254 = v41->cache_tags;
      int v255 = v254[v497];
      int * v256 = v41->cache_dirty;
      int v532 = (4 + ((((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1)) & 3) * 2)) + ((((v249 + ((~(((v251 ^ -1) | (-(v251 ^ -1))) >> 31)) & 2)) - (v253 + ((~(((v255 ^ -1) | (-(v255 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v257 = v256[v532];
      bool v533 = !(v257 == 0);
      if (v533) {
        int * v258 = v41->cache_tags;
        int v259 = v258[v532];
        int * v260 = v41->cache_vals;
        int v536 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1)) & 3) * 2)) + ((((v249 + ((~(((v251 ^ -1) | (-(v251 ^ -1))) >> 31)) & 2)) - (v253 + ((~(((v255 ^ -1) | (-(v255 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v261 = v260[v536];
        int * v262 = v41->cache_vals;
        int v538 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1)) & 3) * 2)) + ((((v249 + ((~(((v251 ^ -1) | (-(v251 ^ -1))) >> 31)) & 2)) - (v253 + ((~(((v255 ^ -1) | (-(v255 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v263 = v262[v538];
        int * v264 = v41->mem;
        int v540 = v259 * 2;
        v264[v540] = v261;
        int * v266 = v41->mem;
        int v543 = (v259 * 2) + 1;
        v266[v543] = v263;
        ;
      } else {
        ;
      }
      int * v271 = v41->mem;
      int v548 = ((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1)) * 2;
      int v272 = v271[v548];
      int * v273 = v41->mem;
      int v550 = (((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1)) * 2) + 1;
      int v274 = v273[v550];
      int * v275 = v41->cache_vals;
      int v552 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1)) & 3) * 2)) + ((((v249 + ((~(((v251 ^ -1) | (-(v251 ^ -1))) >> 31)) & 2)) - (v253 + ((~(((v255 ^ -1) | (-(v255 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v275[v552] = v272;
      int * v277 = v41->cache_vals;
      int v555 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1)) & 3) * 2)) + ((((v249 + ((~(((v251 ^ -1) | (-(v251 ^ -1))) >> 31)) & 2)) - (v253 + ((~(((v255 ^ -1) | (-(v255 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v277[v555] = v274;
      int * v279 = v41->cache_tags;
      int v558 = (int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1);
      v279[v532] = v558;
      int * v281 = v41->cache_dirty;
      v281[v532] = 0;
      int * v283 = v41->cache_age;
      v283[v532] = 1;
      int * v285 = v41->cache_age;
      int v286 = v285[v532];
      int * v287 = v41->cache_age;
      int v288 = v287[v495];
      int * v289 = v41->cache_age;
      int v566 = v288 + ((int)((unsigned int)(v288 - v286) >> 31));
      v289[v495] = v566;
      int * v291 = v41->cache_age;
      int v292 = v291[v497];
      int * v293 = v41->cache_age;
      int v569 = v292 + ((int)((unsigned int)(v292 - v286) >> 31));
      v293[v497] = v569;
      int * v295 = v41->cache_age;
      v295[v532] = 0;
      v298 = v532;
    }
    int * v299 = v41->cache_vals;
    int v572 = v298 * 2;
    int v300 = v299[v572];
    int * v301 = v41->cache_vals;
    int v574 = (v298 * 2) + 1;
    int v302 = v301[v574];
    int * v303 = v41->cache_vals;
    int v576 = (((((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1)) & 1) * 2) + ((((v228 + ((~(((v230 ^ -1) | (-(v230 ^ -1))) >> 31)) & 2)) - (v232 + ((~(((v234 ^ -1) | (-(v234 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v303[v576] = v300;
    int * v305 = v41->cache_vals;
    int v579 = ((((((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1)) & 1) * 2) + ((((v228 + ((~(((v230 ^ -1) | (-(v230 ^ -1))) >> 31)) & 2)) - (v232 + ((~(((v234 ^ -1) | (-(v234 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v305[v579] = v302;
    int * v307 = v41->cache_tags;
    int v582 = ((((int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1)) & 1) * 2) + ((((v228 + ((~(((v230 ^ -1) | (-(v230 ^ -1))) >> 31)) & 2)) - (v232 + ((~(((v234 ^ -1) | (-(v234 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v583 = (int)((unsigned int)((int)((unsigned int)v202 >> 2)) >> 1);
    v307[v582] = v583;
    int * v309 = v41->cache_dirty;
    v309[v582] = 0;
    int * v311 = v41->cache_age;
    v311[v582] = 1;
    int * v313 = v41->cache_age;
    int v314 = v313[v582];
    int * v315 = v41->cache_age;
    int v316 = v315[v491];
    int * v317 = v41->cache_age;
    int v591 = v316 + ((int)((unsigned int)(v316 - v314) >> 31));
    v317[v491] = v591;
    int * v319 = v41->cache_age;
    int v320 = v319[v493];
    int * v321 = v41->cache_age;
    int v594 = v320 + ((int)((unsigned int)(v320 - v314) >> 31));
    v321[v493] = v594;
    int * v323 = v41->cache_age;
    v323[v582] = 0;
    v326 = v582;
  }
  int v597 = (v326 * 2) + (((int)((unsigned int)v202 >> 2)) & 1);
  int v327 = v213[v597];
  int * v328 = v41->regs;
  v328[12] = v327;
  int * v330 = v41->regs;
  int v331 = v330[10];
  int * v332 = v41->regs;
  int v333 = v332[15];
  bool v603 = v331 >= v333;
  if (v603) {
    int v334 = v41->timer;
    int v604 = v334 + 15;
    v41->timer = v604;
    int * v336 = v41->saved_regs;
    int v337 = v336[5];
    int * v338 = v41->regs;
    v338[5] = v337;
    int * v340 = v41->saved_regs;
    int v341 = v340[11];
    int * v342 = v41->regs;
    v342[11] = v341;
    int * v344 = v41->saved_regs;
    int v345 = v344[12];
    int * v346 = v41->regs;
    v346[12] = v345;
    struct StateT * v348 = slot_8(v41);
    ;
  } else {
    ;
  }
  return v41;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[13] = 0;
  struct StateT * v7 = slot_1(v2);
  return v7;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
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
    s1.mem[SECRET_OFFSET+i] = bounded(0, 20);
    s2.mem[SECRET_OFFSET+i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}