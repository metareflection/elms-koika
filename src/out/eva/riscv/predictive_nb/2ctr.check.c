// verify: leak (Eva should report untainted_timer: unknown) [unroll 65]
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
struct StateT * slot_1(struct StateT * v10);
struct StateT * slot_4(struct StateT * v461);
struct StateT * slot_2(struct StateT * v225);
struct StateT * slot_3(struct StateT * v246);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v680 = v1->timer;
  int * v681 = v1->reg_ready;
  int v682 = v681[0];
  int v813 = v682 + ((v680 - v682) & (~((v680 - v682) >> 31)));
  v1->timer = v813;
  int v684 = v1->timer;
  int * v685 = v1->reg_ready;
  int v686 = v685[1];
  int v816 = v686 + ((v684 - v686) & (~((v684 - v686) >> 31)));
  v1->timer = v816;
  int v688 = v1->timer;
  int * v689 = v1->reg_ready;
  int v690 = v689[2];
  int v819 = v690 + ((v688 - v690) & (~((v688 - v690) >> 31)));
  v1->timer = v819;
  int v692 = v1->timer;
  int * v693 = v1->reg_ready;
  int v694 = v693[3];
  int v822 = v694 + ((v692 - v694) & (~((v692 - v694) >> 31)));
  v1->timer = v822;
  int v696 = v1->timer;
  int * v697 = v1->reg_ready;
  int v698 = v697[4];
  int v825 = v698 + ((v696 - v698) & (~((v696 - v698) >> 31)));
  v1->timer = v825;
  int v700 = v1->timer;
  int * v701 = v1->reg_ready;
  int v702 = v701[5];
  int v828 = v702 + ((v700 - v702) & (~((v700 - v702) >> 31)));
  v1->timer = v828;
  int v704 = v1->timer;
  int * v705 = v1->reg_ready;
  int v706 = v705[6];
  int v831 = v706 + ((v704 - v706) & (~((v704 - v706) >> 31)));
  v1->timer = v831;
  int v708 = v1->timer;
  int * v709 = v1->reg_ready;
  int v710 = v709[7];
  int v834 = v710 + ((v708 - v710) & (~((v708 - v710) >> 31)));
  v1->timer = v834;
  int v712 = v1->timer;
  int * v713 = v1->reg_ready;
  int v714 = v713[8];
  int v837 = v714 + ((v712 - v714) & (~((v712 - v714) >> 31)));
  v1->timer = v837;
  int v716 = v1->timer;
  int * v717 = v1->reg_ready;
  int v718 = v717[9];
  int v840 = v718 + ((v716 - v718) & (~((v716 - v718) >> 31)));
  v1->timer = v840;
  int v720 = v1->timer;
  int * v721 = v1->reg_ready;
  int v722 = v721[10];
  int v843 = v722 + ((v720 - v722) & (~((v720 - v722) >> 31)));
  v1->timer = v843;
  int v724 = v1->timer;
  int * v725 = v1->reg_ready;
  int v726 = v725[11];
  int v846 = v726 + ((v724 - v726) & (~((v724 - v726) >> 31)));
  v1->timer = v846;
  int v728 = v1->timer;
  int * v729 = v1->reg_ready;
  int v730 = v729[12];
  int v849 = v730 + ((v728 - v730) & (~((v728 - v730) >> 31)));
  v1->timer = v849;
  int v732 = v1->timer;
  int * v733 = v1->reg_ready;
  int v734 = v733[13];
  int v852 = v734 + ((v732 - v734) & (~((v732 - v734) >> 31)));
  v1->timer = v852;
  int v736 = v1->timer;
  int * v737 = v1->reg_ready;
  int v738 = v737[14];
  int v855 = v738 + ((v736 - v738) & (~((v736 - v738) >> 31)));
  v1->timer = v855;
  int v740 = v1->timer;
  int * v741 = v1->reg_ready;
  int v742 = v741[15];
  int v858 = v742 + ((v740 - v742) & (~((v740 - v742) >> 31)));
  v1->timer = v858;
  int v744 = v1->timer;
  int * v745 = v1->reg_ready;
  int v746 = v745[16];
  int v861 = v746 + ((v744 - v746) & (~((v744 - v746) >> 31)));
  v1->timer = v861;
  int v748 = v1->timer;
  int * v749 = v1->reg_ready;
  int v750 = v749[17];
  int v864 = v750 + ((v748 - v750) & (~((v748 - v750) >> 31)));
  v1->timer = v864;
  int v752 = v1->timer;
  int * v753 = v1->reg_ready;
  int v754 = v753[18];
  int v867 = v754 + ((v752 - v754) & (~((v752 - v754) >> 31)));
  v1->timer = v867;
  int v756 = v1->timer;
  int * v757 = v1->reg_ready;
  int v758 = v757[19];
  int v870 = v758 + ((v756 - v758) & (~((v756 - v758) >> 31)));
  v1->timer = v870;
  int v760 = v1->timer;
  int * v761 = v1->reg_ready;
  int v762 = v761[20];
  int v873 = v762 + ((v760 - v762) & (~((v760 - v762) >> 31)));
  v1->timer = v873;
  int v764 = v1->timer;
  int * v765 = v1->reg_ready;
  int v766 = v765[21];
  int v876 = v766 + ((v764 - v766) & (~((v764 - v766) >> 31)));
  v1->timer = v876;
  int v768 = v1->timer;
  int * v769 = v1->reg_ready;
  int v770 = v769[22];
  int v879 = v770 + ((v768 - v770) & (~((v768 - v770) >> 31)));
  v1->timer = v879;
  int v772 = v1->timer;
  int * v773 = v1->reg_ready;
  int v774 = v773[23];
  int v882 = v774 + ((v772 - v774) & (~((v772 - v774) >> 31)));
  v1->timer = v882;
  int v776 = v1->timer;
  int * v777 = v1->reg_ready;
  int v778 = v777[24];
  int v885 = v778 + ((v776 - v778) & (~((v776 - v778) >> 31)));
  v1->timer = v885;
  int v780 = v1->timer;
  int * v781 = v1->reg_ready;
  int v782 = v781[25];
  int v888 = v782 + ((v780 - v782) & (~((v780 - v782) >> 31)));
  v1->timer = v888;
  int v784 = v1->timer;
  int * v785 = v1->reg_ready;
  int v786 = v785[26];
  int v891 = v786 + ((v784 - v786) & (~((v784 - v786) >> 31)));
  v1->timer = v891;
  int v788 = v1->timer;
  int * v789 = v1->reg_ready;
  int v790 = v789[27];
  int v894 = v790 + ((v788 - v790) & (~((v788 - v790) >> 31)));
  v1->timer = v894;
  int v792 = v1->timer;
  int * v793 = v1->reg_ready;
  int v794 = v793[28];
  int v897 = v794 + ((v792 - v794) & (~((v792 - v794) >> 31)));
  v1->timer = v897;
  int v796 = v1->timer;
  int * v797 = v1->reg_ready;
  int v798 = v797[29];
  int v900 = v798 + ((v796 - v798) & (~((v796 - v798) >> 31)));
  v1->timer = v900;
  int v800 = v1->timer;
  int * v801 = v1->reg_ready;
  int v802 = v801[30];
  int v903 = v802 + ((v800 - v802) & (~((v800 - v802) >> 31)));
  v1->timer = v903;
  int v804 = v1->timer;
  int * v805 = v1->reg_ready;
  int v806 = v805[31];
  int v906 = v806 + ((v804 - v806) & (~((v804 - v806) >> 31)));
  v1->timer = v906;
  return v1;
}

struct StateT * slot_1(struct StateT * v10) {
  int * v11 = v10->saved_regs;
  int * v12 = v10->regs;
  int v13 = v12[11];
  v11[11] = v13;
  int v15 = v10->timer;
  int v131 = v15 + 1;
  v10->timer = v131;
  int * v17 = v10->reg_ready;
  int v18 = v17[10];
  int * v19 = v10->regs;
  int v20 = v19[10];
  int * v21 = v10->cache_tags;
  int v136 = (((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1)) & 1) * 2;
  int v22 = v21[v136];
  int v137 = ((((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1)) & 1) * 2) + 1;
  int v23 = v21[v137];
  int v138 = 4 + ((((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1)) & 3) * 2);
  int v24 = v21[v138];
  int v139 = (4 + ((((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v25 = v21[v139];
  int * v26 = v10->cache_vals;
  bool v140 = !(((~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1))))) >> 31)) | (~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1))))) >> 31))) == 0);
  int v119;
  if (v140) {
    int * v27 = v10->cache_age;
    int v142 = ((((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1)) & 1) * 2) + ((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1))))) >> 31)) & 1);
    int v28 = v27[v142];
    int v29 = v27[v136];
    int v143 = v29 + ((int)((unsigned int)(v29 - v28) >> 31));
    v27[v136] = v143;
    int * v31 = v10->cache_age;
    int v32 = v31[v137];
    int v145 = v32 + ((int)((unsigned int)(v32 - v28) >> 31));
    v31[v137] = v145;
    int * v34 = v10->cache_age;
    v34[v142] = 0;
    v119 = v142;
  } else {
    int * v37 = v10->cache_age;
    int v149 = (((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1)) & 1) * 2;
    int v38 = v37[v149];
    int * v39 = v10->cache_tags;
    int v40 = v39[v149];
    int v41 = v37[v137];
    int v42 = v39[v137];
    bool v151 = !(((~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1))))) >> 31)) | (~(((v25 ^ ((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1))) | (-(v25 ^ ((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1))))) >> 31))) == 0);
    int v96;
    if (v151) {
      int * v43 = v10->cache_age;
      int v153 = (4 + ((((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1)) & 3) * 2)) + ((~(((v25 ^ ((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1))) | (-(v25 ^ ((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1))))) >> 31)) & 1);
      int v44 = v43[v153];
      int v45 = v43[v138];
      int v154 = v45 + ((int)((unsigned int)(v45 - v44) >> 31));
      v43[v138] = v154;
      int * v47 = v10->cache_age;
      int v48 = v47[v139];
      int v156 = v48 + ((int)((unsigned int)(v48 - v44) >> 31));
      v47[v139] = v156;
      int * v50 = v10->cache_age;
      v50[v153] = 0;
      v96 = v153;
    } else {
      int * v53 = v10->cache_age;
      int v160 = 4 + ((((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1)) & 3) * 2);
      int v54 = v53[v160];
      int * v55 = v10->cache_tags;
      int v56 = v55[v160];
      int v57 = v53[v139];
      int v58 = v55[v139];
      int * v59 = v10->cache_dirty;
      int v163 = (4 + ((((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1)) & 3) * 2)) + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v60 = v59[v163];
      bool v164 = !(v60 == 0);
      if (v164) {
        int * v61 = v10->cache_tags;
        int v62 = v61[v163];
        int * v63 = v10->cache_vals;
        int v167 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1)) & 3) * 2)) + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v64 = v63[v167];
        int v168 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1)) & 3) * 2)) + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v65 = v63[v168];
        int * v66 = v10->mem;
        int v170 = v62 * 2;
        v66[v170] = v64;
        int * v68 = v10->mem;
        int v173 = (v62 * 2) + 1;
        v68[v173] = v65;
        ;
      } else {
        ;
      }
      int * v73 = v10->mem;
      int v178 = ((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1)) * 2;
      int v74 = v73[v178];
      int v179 = (((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1)) * 2) + 1;
      int v75 = v73[v179];
      int * v76 = v10->cache_vals;
      int v181 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1)) & 3) * 2)) + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v76[v181] = v74;
      int * v78 = v10->cache_vals;
      int v184 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1)) & 3) * 2)) + ((((v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2)) - (v57 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v78[v184] = v75;
      int * v80 = v10->cache_tags;
      int v187 = (int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1);
      v80[v163] = v187;
      int * v82 = v10->cache_dirty;
      v82[v163] = 0;
      int * v84 = v10->cache_age;
      v84[v163] = 1;
      int * v86 = v10->cache_age;
      int v87 = v86[v163];
      int v88 = v86[v138];
      int v193 = v88 + ((int)((unsigned int)(v88 - v87) >> 31));
      v86[v138] = v193;
      int * v90 = v10->cache_age;
      int v91 = v90[v139];
      int v195 = v91 + ((int)((unsigned int)(v91 - v87) >> 31));
      v90[v139] = v195;
      int * v93 = v10->cache_age;
      v93[v163] = 0;
      v96 = v163;
    }
    int * v97 = v10->cache_vals;
    int v198 = v96 * 2;
    int v98 = v97[v198];
    int v199 = (v96 * 2) + 1;
    int v99 = v97[v199];
    int v200 = (((((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1)) & 1) * 2) + ((((v38 + ((~(((v40 ^ -1) | (-(v40 ^ -1))) >> 31)) & 2)) - (v41 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v97[v200] = v98;
    int * v101 = v10->cache_vals;
    int v203 = ((((((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1)) & 1) * 2) + ((((v38 + ((~(((v40 ^ -1) | (-(v40 ^ -1))) >> 31)) & 2)) - (v41 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v101[v203] = v99;
    int * v103 = v10->cache_tags;
    int v206 = ((((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1)) & 1) * 2) + ((((v38 + ((~(((v40 ^ -1) | (-(v40 ^ -1))) >> 31)) & 2)) - (v41 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v207 = (int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1);
    v103[v206] = v207;
    int * v105 = v10->cache_dirty;
    v105[v206] = 0;
    int * v107 = v10->cache_age;
    v107[v206] = 1;
    int * v109 = v10->cache_age;
    int v110 = v109[v206];
    int v111 = v109[v136];
    int v213 = v111 + ((int)((unsigned int)(v111 - v110) >> 31));
    v109[v136] = v213;
    int * v113 = v10->cache_age;
    int v114 = v113[v137];
    int v215 = v114 + ((int)((unsigned int)(v114 - v110) >> 31));
    v113[v137] = v215;
    int * v116 = v10->cache_age;
    v116[v206] = 0;
    v119 = v206;
  }
  int v218 = (v119 * 2) + (((int)((unsigned int)v20 >> 2)) & 1);
  int v120 = v26[v218];
  int * v121 = v10->reg_ready;
  int v220 = ((v18 + ((v15 - v18) & (~((v15 - v18) >> 31)))) + 1) + ((100 ^ (((~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1))))) >> 31)) | (~(((v25 ^ ((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1))) | (-(v25 ^ ((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1))))) >> 31)) | (~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1))))) >> 31)) | (~(((v25 ^ ((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1))) | (-(v25 ^ ((int)((unsigned int)((int)((unsigned int)v20 >> 2)) >> 1))))) >> 31))) & 104)))));
  v121[11] = v220;
  int * v123 = v10->regs;
  v123[11] = v120;
  struct StateT * v125 = slot_2(v10);
  return v125;
}

struct StateT * slot_4(struct StateT * v461) {
  int * v462 = v461->regs;
  int v463 = v462[10];
  bool v576 = v463 == 0;
  struct StateT * v572;
  if (v576) {
    int v464 = v461->timer;
    int v577 = v464 + 15;
    v461->timer = v577;
    int * v466 = v461->saved_regs;
    int v467 = v466[11];
    int * v468 = v461->regs;
    v468[11] = v467;
    int * v470 = v461->saved_regs;
    int v471 = v470[12];
    int * v472 = v461->regs;
    v472[12] = v471;
    int * v474 = v461->reg_ready;
    int v475 = v461->timer;
    v474[0] = v475;
    int * v477 = v461->reg_ready;
    int v478 = v461->timer;
    v477[1] = v478;
    int * v480 = v461->reg_ready;
    int v481 = v461->timer;
    v480[2] = v481;
    int * v483 = v461->reg_ready;
    int v484 = v461->timer;
    v483[3] = v484;
    int * v486 = v461->reg_ready;
    int v487 = v461->timer;
    v486[4] = v487;
    int * v489 = v461->reg_ready;
    int v490 = v461->timer;
    v489[5] = v490;
    int * v492 = v461->reg_ready;
    int v493 = v461->timer;
    v492[6] = v493;
    int * v495 = v461->reg_ready;
    int v496 = v461->timer;
    v495[7] = v496;
    int * v498 = v461->reg_ready;
    int v499 = v461->timer;
    v498[8] = v499;
    int * v501 = v461->reg_ready;
    int v502 = v461->timer;
    v501[9] = v502;
    int * v504 = v461->reg_ready;
    int v505 = v461->timer;
    v504[10] = v505;
    int * v507 = v461->reg_ready;
    int v508 = v461->timer;
    v507[11] = v508;
    int * v510 = v461->reg_ready;
    int v511 = v461->timer;
    v510[12] = v511;
    int * v513 = v461->reg_ready;
    int v514 = v461->timer;
    v513[13] = v514;
    int * v516 = v461->reg_ready;
    int v517 = v461->timer;
    v516[14] = v517;
    int * v519 = v461->reg_ready;
    int v520 = v461->timer;
    v519[15] = v520;
    int * v522 = v461->reg_ready;
    int v523 = v461->timer;
    v522[16] = v523;
    int * v525 = v461->reg_ready;
    int v526 = v461->timer;
    v525[17] = v526;
    int * v528 = v461->reg_ready;
    int v529 = v461->timer;
    v528[18] = v529;
    int * v531 = v461->reg_ready;
    int v532 = v461->timer;
    v531[19] = v532;
    int * v534 = v461->reg_ready;
    int v535 = v461->timer;
    v534[20] = v535;
    int * v537 = v461->reg_ready;
    int v538 = v461->timer;
    v537[21] = v538;
    int * v540 = v461->reg_ready;
    int v541 = v461->timer;
    v540[22] = v541;
    int * v543 = v461->reg_ready;
    int v544 = v461->timer;
    v543[23] = v544;
    int * v546 = v461->reg_ready;
    int v547 = v461->timer;
    v546[24] = v547;
    int * v549 = v461->reg_ready;
    int v550 = v461->timer;
    v549[25] = v550;
    int * v552 = v461->reg_ready;
    int v553 = v461->timer;
    v552[26] = v553;
    int * v555 = v461->reg_ready;
    int v556 = v461->timer;
    v555[27] = v556;
    int * v558 = v461->reg_ready;
    int v559 = v461->timer;
    v558[28] = v559;
    int * v561 = v461->reg_ready;
    int v562 = v461->timer;
    v561[29] = v562;
    int * v564 = v461->reg_ready;
    int v565 = v461->timer;
    v564[30] = v565;
    int * v567 = v461->reg_ready;
    int v568 = v461->timer;
    v567[31] = v568;
    v572 = v461;
  } else {
    v572 = v461;
  }
  return v572;
}

struct StateT * slot_2(struct StateT * v225) {
  int v226 = v225->timer;
  int v237 = v226 + 1;
  v225->timer = v237;
  int * v228 = v225->reg_ready;
  int v229 = v228[11];
  int * v230 = v225->regs;
  int v231 = v230[11];
  int v241 = (v229 + ((v226 - v229) & (~((v226 - v229) >> 31)))) + 1;
  v228[11] = v241;
  int * v233 = v225->regs;
  int v243 = v231 << 2;
  v233[11] = v243;
  struct StateT * v235 = slot_3(v225);
  return v235;
}

struct StateT * slot_3(struct StateT * v246) {
  int * v247 = v246->saved_regs;
  int * v248 = v246->regs;
  int v249 = v248[12];
  v247[12] = v249;
  int v251 = v246->timer;
  int v367 = v251 + 1;
  v246->timer = v367;
  int * v253 = v246->reg_ready;
  int v254 = v253[11];
  int * v255 = v246->regs;
  int v256 = v255[11];
  int * v257 = v246->cache_tags;
  int v372 = (((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1)) & 1) * 2;
  int v258 = v257[v372];
  int v373 = ((((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v259 = v257[v373];
  int v374 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1)) & 3) * 2);
  int v260 = v257[v374];
  int v375 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v261 = v257[v375];
  int * v262 = v246->cache_vals;
  bool v376 = !(((~(((v258 ^ ((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1))) | (-(v258 ^ ((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v259 ^ ((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1))) | (-(v259 ^ ((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v355;
  if (v376) {
    int * v263 = v246->cache_age;
    int v378 = ((((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v259 ^ ((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1))) | (-(v259 ^ ((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v264 = v263[v378];
    int v265 = v263[v372];
    int v379 = v265 + ((int)((unsigned int)(v265 - v264) >> 31));
    v263[v372] = v379;
    int * v267 = v246->cache_age;
    int v268 = v267[v373];
    int v381 = v268 + ((int)((unsigned int)(v268 - v264) >> 31));
    v267[v373] = v381;
    int * v270 = v246->cache_age;
    v270[v378] = 0;
    v355 = v378;
  } else {
    int * v273 = v246->cache_age;
    int v385 = (((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1)) & 1) * 2;
    int v274 = v273[v385];
    int * v275 = v246->cache_tags;
    int v276 = v275[v385];
    int v277 = v273[v373];
    int v278 = v275[v373];
    bool v387 = !(((~(((v260 ^ ((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1))) | (-(v260 ^ ((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v261 ^ ((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1))) | (-(v261 ^ ((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v332;
    if (v387) {
      int * v279 = v246->cache_age;
      int v389 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v261 ^ ((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1))) | (-(v261 ^ ((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v280 = v279[v389];
      int v281 = v279[v374];
      int v390 = v281 + ((int)((unsigned int)(v281 - v280) >> 31));
      v279[v374] = v390;
      int * v283 = v246->cache_age;
      int v284 = v283[v375];
      int v392 = v284 + ((int)((unsigned int)(v284 - v280) >> 31));
      v283[v375] = v392;
      int * v286 = v246->cache_age;
      v286[v389] = 0;
      v332 = v389;
    } else {
      int * v289 = v246->cache_age;
      int v396 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1)) & 3) * 2);
      int v290 = v289[v396];
      int * v291 = v246->cache_tags;
      int v292 = v291[v396];
      int v293 = v289[v375];
      int v294 = v291[v375];
      int * v295 = v246->cache_dirty;
      int v399 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v290 + ((~(((v292 ^ -1) | (-(v292 ^ -1))) >> 31)) & 2)) - (v293 + ((~(((v294 ^ -1) | (-(v294 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v296 = v295[v399];
      bool v400 = !(v296 == 0);
      if (v400) {
        int * v297 = v246->cache_tags;
        int v298 = v297[v399];
        int * v299 = v246->cache_vals;
        int v403 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v290 + ((~(((v292 ^ -1) | (-(v292 ^ -1))) >> 31)) & 2)) - (v293 + ((~(((v294 ^ -1) | (-(v294 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v300 = v299[v403];
        int v404 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v290 + ((~(((v292 ^ -1) | (-(v292 ^ -1))) >> 31)) & 2)) - (v293 + ((~(((v294 ^ -1) | (-(v294 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v301 = v299[v404];
        int * v302 = v246->mem;
        int v406 = v298 * 2;
        v302[v406] = v300;
        int * v304 = v246->mem;
        int v409 = (v298 * 2) + 1;
        v304[v409] = v301;
        ;
      } else {
        ;
      }
      int * v309 = v246->mem;
      int v414 = ((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1)) * 2;
      int v310 = v309[v414];
      int v415 = (((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1)) * 2) + 1;
      int v311 = v309[v415];
      int * v312 = v246->cache_vals;
      int v417 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v290 + ((~(((v292 ^ -1) | (-(v292 ^ -1))) >> 31)) & 2)) - (v293 + ((~(((v294 ^ -1) | (-(v294 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v312[v417] = v310;
      int * v314 = v246->cache_vals;
      int v420 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v290 + ((~(((v292 ^ -1) | (-(v292 ^ -1))) >> 31)) & 2)) - (v293 + ((~(((v294 ^ -1) | (-(v294 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v314[v420] = v311;
      int * v316 = v246->cache_tags;
      int v423 = (int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1);
      v316[v399] = v423;
      int * v318 = v246->cache_dirty;
      v318[v399] = 0;
      int * v320 = v246->cache_age;
      v320[v399] = 1;
      int * v322 = v246->cache_age;
      int v323 = v322[v399];
      int v324 = v322[v374];
      int v429 = v324 + ((int)((unsigned int)(v324 - v323) >> 31));
      v322[v374] = v429;
      int * v326 = v246->cache_age;
      int v327 = v326[v375];
      int v431 = v327 + ((int)((unsigned int)(v327 - v323) >> 31));
      v326[v375] = v431;
      int * v329 = v246->cache_age;
      v329[v399] = 0;
      v332 = v399;
    }
    int * v333 = v246->cache_vals;
    int v434 = v332 * 2;
    int v334 = v333[v434];
    int v435 = (v332 * 2) + 1;
    int v335 = v333[v435];
    int v436 = (((((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v274 + ((~(((v276 ^ -1) | (-(v276 ^ -1))) >> 31)) & 2)) - (v277 + ((~(((v278 ^ -1) | (-(v278 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v333[v436] = v334;
    int * v337 = v246->cache_vals;
    int v439 = ((((((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v274 + ((~(((v276 ^ -1) | (-(v276 ^ -1))) >> 31)) & 2)) - (v277 + ((~(((v278 ^ -1) | (-(v278 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v337[v439] = v335;
    int * v339 = v246->cache_tags;
    int v442 = ((((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v274 + ((~(((v276 ^ -1) | (-(v276 ^ -1))) >> 31)) & 2)) - (v277 + ((~(((v278 ^ -1) | (-(v278 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v443 = (int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1);
    v339[v442] = v443;
    int * v341 = v246->cache_dirty;
    v341[v442] = 0;
    int * v343 = v246->cache_age;
    v343[v442] = 1;
    int * v345 = v246->cache_age;
    int v346 = v345[v442];
    int v347 = v345[v372];
    int v449 = v347 + ((int)((unsigned int)(v347 - v346) >> 31));
    v345[v372] = v449;
    int * v349 = v246->cache_age;
    int v350 = v349[v373];
    int v451 = v350 + ((int)((unsigned int)(v350 - v346) >> 31));
    v349[v373] = v451;
    int * v352 = v246->cache_age;
    v352[v442] = 0;
    v355 = v442;
  }
  int v454 = (v355 * 2) + (((int)((unsigned int)(v256 + 16) >> 2)) & 1);
  int v356 = v262[v454];
  int * v357 = v246->reg_ready;
  int v456 = ((v254 + ((v251 - v254) & (~((v251 - v254) >> 31)))) + 1) + ((100 ^ (((~(((v260 ^ ((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1))) | (-(v260 ^ ((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v261 ^ ((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1))) | (-(v261 ^ ((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v258 ^ ((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1))) | (-(v258 ^ ((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v259 ^ ((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1))) | (-(v259 ^ ((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v260 ^ ((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1))) | (-(v260 ^ ((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v261 ^ ((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1))) | (-(v261 ^ ((int)((unsigned int)((int)((unsigned int)(v256 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v357[12] = v456;
  int * v359 = v246->regs;
  v359[12] = v356;
  struct StateT * v361 = slot_4(v246);
  return v361;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v7 = v3 + 1;
  v2->timer = v7;
  struct StateT * v5 = slot_1(v2);
  return v5;
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