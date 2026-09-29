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
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_8(struct StateT * v541);
struct StateT * slot_6(struct StateT * v305);
struct StateT * slot_5(struct StateT * v90);
struct StateT * slot_4(struct StateT * v58);
struct StateT * slot_2(struct StateT * v34);
struct StateT * slot_7(struct StateT * v326);
struct StateT * slot_3(struct StateT * v50);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v768 = v1->timer;
  int * v769 = v1->reg_ready;
  int v770 = v769[0];
  int v901 = v770 + ((v768 - v770) & (~((v768 - v770) >> 31)));
  v1->timer = v901;
  int v772 = v1->timer;
  int * v773 = v1->reg_ready;
  int v774 = v773[1];
  int v904 = v774 + ((v772 - v774) & (~((v772 - v774) >> 31)));
  v1->timer = v904;
  int v776 = v1->timer;
  int * v777 = v1->reg_ready;
  int v778 = v777[2];
  int v907 = v778 + ((v776 - v778) & (~((v776 - v778) >> 31)));
  v1->timer = v907;
  int v780 = v1->timer;
  int * v781 = v1->reg_ready;
  int v782 = v781[3];
  int v910 = v782 + ((v780 - v782) & (~((v780 - v782) >> 31)));
  v1->timer = v910;
  int v784 = v1->timer;
  int * v785 = v1->reg_ready;
  int v786 = v785[4];
  int v913 = v786 + ((v784 - v786) & (~((v784 - v786) >> 31)));
  v1->timer = v913;
  int v788 = v1->timer;
  int * v789 = v1->reg_ready;
  int v790 = v789[5];
  int v916 = v790 + ((v788 - v790) & (~((v788 - v790) >> 31)));
  v1->timer = v916;
  int v792 = v1->timer;
  int * v793 = v1->reg_ready;
  int v794 = v793[6];
  int v919 = v794 + ((v792 - v794) & (~((v792 - v794) >> 31)));
  v1->timer = v919;
  int v796 = v1->timer;
  int * v797 = v1->reg_ready;
  int v798 = v797[7];
  int v922 = v798 + ((v796 - v798) & (~((v796 - v798) >> 31)));
  v1->timer = v922;
  int v800 = v1->timer;
  int * v801 = v1->reg_ready;
  int v802 = v801[8];
  int v925 = v802 + ((v800 - v802) & (~((v800 - v802) >> 31)));
  v1->timer = v925;
  int v804 = v1->timer;
  int * v805 = v1->reg_ready;
  int v806 = v805[9];
  int v928 = v806 + ((v804 - v806) & (~((v804 - v806) >> 31)));
  v1->timer = v928;
  int v808 = v1->timer;
  int * v809 = v1->reg_ready;
  int v810 = v809[10];
  int v931 = v810 + ((v808 - v810) & (~((v808 - v810) >> 31)));
  v1->timer = v931;
  int v812 = v1->timer;
  int * v813 = v1->reg_ready;
  int v814 = v813[11];
  int v934 = v814 + ((v812 - v814) & (~((v812 - v814) >> 31)));
  v1->timer = v934;
  int v816 = v1->timer;
  int * v817 = v1->reg_ready;
  int v818 = v817[12];
  int v937 = v818 + ((v816 - v818) & (~((v816 - v818) >> 31)));
  v1->timer = v937;
  int v820 = v1->timer;
  int * v821 = v1->reg_ready;
  int v822 = v821[13];
  int v940 = v822 + ((v820 - v822) & (~((v820 - v822) >> 31)));
  v1->timer = v940;
  int v824 = v1->timer;
  int * v825 = v1->reg_ready;
  int v826 = v825[14];
  int v943 = v826 + ((v824 - v826) & (~((v824 - v826) >> 31)));
  v1->timer = v943;
  int v828 = v1->timer;
  int * v829 = v1->reg_ready;
  int v830 = v829[15];
  int v946 = v830 + ((v828 - v830) & (~((v828 - v830) >> 31)));
  v1->timer = v946;
  int v832 = v1->timer;
  int * v833 = v1->reg_ready;
  int v834 = v833[16];
  int v949 = v834 + ((v832 - v834) & (~((v832 - v834) >> 31)));
  v1->timer = v949;
  int v836 = v1->timer;
  int * v837 = v1->reg_ready;
  int v838 = v837[17];
  int v952 = v838 + ((v836 - v838) & (~((v836 - v838) >> 31)));
  v1->timer = v952;
  int v840 = v1->timer;
  int * v841 = v1->reg_ready;
  int v842 = v841[18];
  int v955 = v842 + ((v840 - v842) & (~((v840 - v842) >> 31)));
  v1->timer = v955;
  int v844 = v1->timer;
  int * v845 = v1->reg_ready;
  int v846 = v845[19];
  int v958 = v846 + ((v844 - v846) & (~((v844 - v846) >> 31)));
  v1->timer = v958;
  int v848 = v1->timer;
  int * v849 = v1->reg_ready;
  int v850 = v849[20];
  int v961 = v850 + ((v848 - v850) & (~((v848 - v850) >> 31)));
  v1->timer = v961;
  int v852 = v1->timer;
  int * v853 = v1->reg_ready;
  int v854 = v853[21];
  int v964 = v854 + ((v852 - v854) & (~((v852 - v854) >> 31)));
  v1->timer = v964;
  int v856 = v1->timer;
  int * v857 = v1->reg_ready;
  int v858 = v857[22];
  int v967 = v858 + ((v856 - v858) & (~((v856 - v858) >> 31)));
  v1->timer = v967;
  int v860 = v1->timer;
  int * v861 = v1->reg_ready;
  int v862 = v861[23];
  int v970 = v862 + ((v860 - v862) & (~((v860 - v862) >> 31)));
  v1->timer = v970;
  int v864 = v1->timer;
  int * v865 = v1->reg_ready;
  int v866 = v865[24];
  int v973 = v866 + ((v864 - v866) & (~((v864 - v866) >> 31)));
  v1->timer = v973;
  int v868 = v1->timer;
  int * v869 = v1->reg_ready;
  int v870 = v869[25];
  int v976 = v870 + ((v868 - v870) & (~((v868 - v870) >> 31)));
  v1->timer = v976;
  int v872 = v1->timer;
  int * v873 = v1->reg_ready;
  int v874 = v873[26];
  int v979 = v874 + ((v872 - v874) & (~((v872 - v874) >> 31)));
  v1->timer = v979;
  int v876 = v1->timer;
  int * v877 = v1->reg_ready;
  int v878 = v877[27];
  int v982 = v878 + ((v876 - v878) & (~((v876 - v878) >> 31)));
  v1->timer = v982;
  int v880 = v1->timer;
  int * v881 = v1->reg_ready;
  int v882 = v881[28];
  int v985 = v882 + ((v880 - v882) & (~((v880 - v882) >> 31)));
  v1->timer = v985;
  int v884 = v1->timer;
  int * v885 = v1->reg_ready;
  int v886 = v885[29];
  int v988 = v886 + ((v884 - v886) & (~((v884 - v886) >> 31)));
  v1->timer = v988;
  int v888 = v1->timer;
  int * v889 = v1->reg_ready;
  int v890 = v889[30];
  int v991 = v890 + ((v888 - v890) & (~((v888 - v890) >> 31)));
  v1->timer = v991;
  int v892 = v1->timer;
  int * v893 = v1->reg_ready;
  int v894 = v893[31];
  int v994 = v894 + ((v892 - v894) & (~((v892 - v894) >> 31)));
  v1->timer = v994;
  return v1;
}

struct StateT * slot_1(struct StateT * v18) {
  int v19 = v18->timer;
  int v27 = v19 + 1;
  v18->timer = v27;
  int * v21 = v18->reg_ready;
  v21[10] = v27;
  int * v23 = v18->regs;
  v23[10] = 80;
  struct StateT * v25 = slot_2(v18);
  return v25;
}

struct StateT * slot_8(struct StateT * v541) {
  int * v542 = v541->regs;
  int v543 = v542[10];
  int v544 = v542[15];
  bool v662 = v543 >= v544;
  struct StateT * v657;
  if (v662) {
    int v545 = v541->timer;
    int v663 = v545 + 15;
    v541->timer = v663;
    int * v547 = v541->saved_regs;
    int v548 = v547[5];
    int * v549 = v541->regs;
    v549[5] = v548;
    int * v551 = v541->saved_regs;
    int v552 = v551[11];
    int * v553 = v541->regs;
    v553[11] = v552;
    int * v555 = v541->saved_regs;
    int v556 = v555[12];
    int * v557 = v541->regs;
    v557[12] = v556;
    int * v559 = v541->reg_ready;
    int v560 = v541->timer;
    v559[0] = v560;
    int * v562 = v541->reg_ready;
    int v563 = v541->timer;
    v562[1] = v563;
    int * v565 = v541->reg_ready;
    int v566 = v541->timer;
    v565[2] = v566;
    int * v568 = v541->reg_ready;
    int v569 = v541->timer;
    v568[3] = v569;
    int * v571 = v541->reg_ready;
    int v572 = v541->timer;
    v571[4] = v572;
    int * v574 = v541->reg_ready;
    int v575 = v541->timer;
    v574[5] = v575;
    int * v577 = v541->reg_ready;
    int v578 = v541->timer;
    v577[6] = v578;
    int * v580 = v541->reg_ready;
    int v581 = v541->timer;
    v580[7] = v581;
    int * v583 = v541->reg_ready;
    int v584 = v541->timer;
    v583[8] = v584;
    int * v586 = v541->reg_ready;
    int v587 = v541->timer;
    v586[9] = v587;
    int * v589 = v541->reg_ready;
    int v590 = v541->timer;
    v589[10] = v590;
    int * v592 = v541->reg_ready;
    int v593 = v541->timer;
    v592[11] = v593;
    int * v595 = v541->reg_ready;
    int v596 = v541->timer;
    v595[12] = v596;
    int * v598 = v541->reg_ready;
    int v599 = v541->timer;
    v598[13] = v599;
    int * v601 = v541->reg_ready;
    int v602 = v541->timer;
    v601[14] = v602;
    int * v604 = v541->reg_ready;
    int v605 = v541->timer;
    v604[15] = v605;
    int * v607 = v541->reg_ready;
    int v608 = v541->timer;
    v607[16] = v608;
    int * v610 = v541->reg_ready;
    int v611 = v541->timer;
    v610[17] = v611;
    int * v613 = v541->reg_ready;
    int v614 = v541->timer;
    v613[18] = v614;
    int * v616 = v541->reg_ready;
    int v617 = v541->timer;
    v616[19] = v617;
    int * v619 = v541->reg_ready;
    int v620 = v541->timer;
    v619[20] = v620;
    int * v622 = v541->reg_ready;
    int v623 = v541->timer;
    v622[21] = v623;
    int * v625 = v541->reg_ready;
    int v626 = v541->timer;
    v625[22] = v626;
    int * v628 = v541->reg_ready;
    int v629 = v541->timer;
    v628[23] = v629;
    int * v631 = v541->reg_ready;
    int v632 = v541->timer;
    v631[24] = v632;
    int * v634 = v541->reg_ready;
    int v635 = v541->timer;
    v634[25] = v635;
    int * v637 = v541->reg_ready;
    int v638 = v541->timer;
    v637[26] = v638;
    int * v640 = v541->reg_ready;
    int v641 = v541->timer;
    v640[27] = v641;
    int * v643 = v541->reg_ready;
    int v644 = v541->timer;
    v643[28] = v644;
    int * v646 = v541->reg_ready;
    int v647 = v541->timer;
    v646[29] = v647;
    int * v649 = v541->reg_ready;
    int v650 = v541->timer;
    v649[30] = v650;
    int * v652 = v541->reg_ready;
    int v653 = v541->timer;
    v652[31] = v653;
    v657 = v541;
  } else {
    v657 = v541;
  }
  return v657;
}

struct StateT * slot_6(struct StateT * v305) {
  int v306 = v305->timer;
  int v317 = v306 + 1;
  v305->timer = v317;
  int * v308 = v305->reg_ready;
  int v309 = v308[11];
  int * v310 = v305->regs;
  int v311 = v310[11];
  int v321 = (v309 + ((v306 - v309) & (~((v306 - v309) >> 31)))) + 1;
  v308[11] = v321;
  int * v313 = v305->regs;
  int v323 = v311 << 2;
  v313[11] = v323;
  struct StateT * v315 = slot_7(v305);
  return v315;
}

struct StateT * slot_5(struct StateT * v90) {
  int * v91 = v90->saved_regs;
  int * v92 = v90->regs;
  int v93 = v92[11];
  v91[11] = v93;
  int v95 = v90->timer;
  int v211 = v95 + 1;
  v90->timer = v211;
  int * v97 = v90->reg_ready;
  int v98 = v97[5];
  int * v99 = v90->regs;
  int v100 = v99[5];
  int * v101 = v90->cache_tags;
  int v216 = (((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 1) * 2;
  int v102 = v101[v216];
  int v217 = ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 1) * 2) + 1;
  int v103 = v101[v217];
  int v218 = 4 + ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 3) * 2);
  int v104 = v101[v218];
  int v219 = (4 + ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v105 = v101[v219];
  int * v106 = v90->cache_vals;
  bool v220 = !(((~(((v102 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v102 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31)) | (~(((v103 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v103 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31))) == 0);
  int v199;
  if (v220) {
    int * v107 = v90->cache_age;
    int v222 = ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 1) * 2) + ((~(((v103 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v103 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31)) & 1);
    int v108 = v107[v222];
    int v109 = v107[v216];
    int v223 = v109 + ((int)((unsigned int)(v109 - v108) >> 31));
    v107[v216] = v223;
    int * v111 = v90->cache_age;
    int v112 = v111[v217];
    int v225 = v112 + ((int)((unsigned int)(v112 - v108) >> 31));
    v111[v217] = v225;
    int * v114 = v90->cache_age;
    v114[v222] = 0;
    v199 = v222;
  } else {
    int * v117 = v90->cache_age;
    int v229 = (((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 1) * 2;
    int v118 = v117[v229];
    int * v119 = v90->cache_tags;
    int v120 = v119[v229];
    int v121 = v117[v217];
    int v122 = v119[v217];
    bool v231 = !(((~(((v104 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v104 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31)) | (~(((v105 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v105 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31))) == 0);
    int v176;
    if (v231) {
      int * v123 = v90->cache_age;
      int v233 = (4 + ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 3) * 2)) + ((~(((v105 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v105 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31)) & 1);
      int v124 = v123[v233];
      int v125 = v123[v218];
      int v234 = v125 + ((int)((unsigned int)(v125 - v124) >> 31));
      v123[v218] = v234;
      int * v127 = v90->cache_age;
      int v128 = v127[v219];
      int v236 = v128 + ((int)((unsigned int)(v128 - v124) >> 31));
      v127[v219] = v236;
      int * v130 = v90->cache_age;
      v130[v233] = 0;
      v176 = v233;
    } else {
      int * v133 = v90->cache_age;
      int v240 = 4 + ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 3) * 2);
      int v134 = v133[v240];
      int * v135 = v90->cache_tags;
      int v136 = v135[v240];
      int v137 = v133[v219];
      int v138 = v135[v219];
      int * v139 = v90->cache_dirty;
      int v243 = (4 + ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 3) * 2)) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v137 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v140 = v139[v243];
      bool v244 = !(v140 == 0);
      if (v244) {
        int * v141 = v90->cache_tags;
        int v142 = v141[v243];
        int * v143 = v90->cache_vals;
        int v247 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 3) * 2)) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v137 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v144 = v143[v247];
        int v248 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 3) * 2)) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v137 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v145 = v143[v248];
        int * v146 = v90->mem;
        int v250 = v142 * 2;
        v146[v250] = v144;
        int * v148 = v90->mem;
        int v253 = (v142 * 2) + 1;
        v148[v253] = v145;
        ;
      } else {
        ;
      }
      int * v153 = v90->mem;
      int v258 = ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) * 2;
      int v154 = v153[v258];
      int v259 = (((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) * 2) + 1;
      int v155 = v153[v259];
      int * v156 = v90->cache_vals;
      int v261 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 3) * 2)) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v137 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v156[v261] = v154;
      int * v158 = v90->cache_vals;
      int v264 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 3) * 2)) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v137 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v158[v264] = v155;
      int * v160 = v90->cache_tags;
      int v267 = (int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1);
      v160[v243] = v267;
      int * v162 = v90->cache_dirty;
      v162[v243] = 0;
      int * v164 = v90->cache_age;
      v164[v243] = 1;
      int * v166 = v90->cache_age;
      int v167 = v166[v243];
      int v168 = v166[v218];
      int v273 = v168 + ((int)((unsigned int)(v168 - v167) >> 31));
      v166[v218] = v273;
      int * v170 = v90->cache_age;
      int v171 = v170[v219];
      int v275 = v171 + ((int)((unsigned int)(v171 - v167) >> 31));
      v170[v219] = v275;
      int * v173 = v90->cache_age;
      v173[v243] = 0;
      v176 = v243;
    }
    int * v177 = v90->cache_vals;
    int v278 = v176 * 2;
    int v178 = v177[v278];
    int v279 = (v176 * 2) + 1;
    int v179 = v177[v279];
    int v280 = (((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 1) * 2) + ((((v118 + ((~(((v120 ^ -1) | (-(v120 ^ -1))) >> 31)) & 2)) - (v121 + ((~(((v122 ^ -1) | (-(v122 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v177[v280] = v178;
    int * v181 = v90->cache_vals;
    int v283 = ((((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 1) * 2) + ((((v118 + ((~(((v120 ^ -1) | (-(v120 ^ -1))) >> 31)) & 2)) - (v121 + ((~(((v122 ^ -1) | (-(v122 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v181[v283] = v179;
    int * v183 = v90->cache_tags;
    int v286 = ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 1) * 2) + ((((v118 + ((~(((v120 ^ -1) | (-(v120 ^ -1))) >> 31)) & 2)) - (v121 + ((~(((v122 ^ -1) | (-(v122 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v287 = (int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1);
    v183[v286] = v287;
    int * v185 = v90->cache_dirty;
    v185[v286] = 0;
    int * v187 = v90->cache_age;
    v187[v286] = 1;
    int * v189 = v90->cache_age;
    int v190 = v189[v286];
    int v191 = v189[v216];
    int v293 = v191 + ((int)((unsigned int)(v191 - v190) >> 31));
    v189[v216] = v293;
    int * v193 = v90->cache_age;
    int v194 = v193[v217];
    int v295 = v194 + ((int)((unsigned int)(v194 - v190) >> 31));
    v193[v217] = v295;
    int * v196 = v90->cache_age;
    v196[v286] = 0;
    v199 = v286;
  }
  int v298 = (v199 * 2) + (((int)((unsigned int)v100 >> 2)) & 1);
  int v200 = v106[v298];
  int * v201 = v90->reg_ready;
  int v300 = ((v98 + ((v95 - v98) & (~((v95 - v98) >> 31)))) + 1) + ((100 ^ (((~(((v104 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v104 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31)) | (~(((v105 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v105 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v102 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v102 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31)) | (~(((v103 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v103 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v104 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v104 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31)) | (~(((v105 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v105 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31))) & 104)))));
  v201[11] = v300;
  int * v203 = v90->regs;
  v203[11] = v200;
  struct StateT * v205 = slot_6(v90);
  return v205;
}

struct StateT * slot_4(struct StateT * v58) {
  int * v59 = v58->saved_regs;
  int * v60 = v58->regs;
  int v61 = v60[5];
  v59[5] = v61;
  int v63 = v58->timer;
  int v80 = v63 + 1;
  v58->timer = v80;
  int * v65 = v58->reg_ready;
  int v66 = v65[13];
  int * v67 = v58->regs;
  int v68 = v67[13];
  int v69 = v65[10];
  int v70 = v67[10];
  int v85 = (v69 + (((v66 + ((v63 - v66) & (~((v63 - v66) >> 31)))) - v69) & (~(((v66 + ((v63 - v66) & (~((v63 - v66) >> 31)))) - v69) >> 31)))) + 1;
  v65[5] = v85;
  int * v72 = v58->regs;
  int v87 = v68 + v70;
  v72[5] = v87;
  struct StateT * v74 = slot_5(v58);
  return v74;
}

struct StateT * slot_2(struct StateT * v34) {
  int v35 = v34->timer;
  int v43 = v35 + 1;
  v34->timer = v43;
  int * v37 = v34->reg_ready;
  v37[15] = v43;
  int * v39 = v34->regs;
  v39[15] = 80;
  struct StateT * v41 = slot_3(v34);
  return v41;
}

struct StateT * slot_7(struct StateT * v326) {
  int * v327 = v326->saved_regs;
  int * v328 = v326->regs;
  int v329 = v328[12];
  v327[12] = v329;
  int v331 = v326->timer;
  int v447 = v331 + 1;
  v326->timer = v447;
  int * v333 = v326->reg_ready;
  int v334 = v333[11];
  int * v335 = v326->regs;
  int v336 = v335[11];
  int * v337 = v326->cache_tags;
  int v452 = (((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 1) * 2;
  int v338 = v337[v452];
  int v453 = ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 1) * 2) + 1;
  int v339 = v337[v453];
  int v454 = 4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2);
  int v340 = v337[v454];
  int v455 = (4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v341 = v337[v455];
  int * v342 = v326->cache_vals;
  bool v456 = !(((~(((v338 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v338 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31)) | (~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31))) == 0);
  int v435;
  if (v456) {
    int * v343 = v326->cache_age;
    int v458 = ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 1) * 2) + ((~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31)) & 1);
    int v344 = v343[v458];
    int v345 = v343[v452];
    int v459 = v345 + ((int)((unsigned int)(v345 - v344) >> 31));
    v343[v452] = v459;
    int * v347 = v326->cache_age;
    int v348 = v347[v453];
    int v461 = v348 + ((int)((unsigned int)(v348 - v344) >> 31));
    v347[v453] = v461;
    int * v350 = v326->cache_age;
    v350[v458] = 0;
    v435 = v458;
  } else {
    int * v353 = v326->cache_age;
    int v465 = (((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 1) * 2;
    int v354 = v353[v465];
    int * v355 = v326->cache_tags;
    int v356 = v355[v465];
    int v357 = v353[v453];
    int v358 = v355[v453];
    bool v467 = !(((~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31)) | (~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31))) == 0);
    int v412;
    if (v467) {
      int * v359 = v326->cache_age;
      int v469 = (4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2)) + ((~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31)) & 1);
      int v360 = v359[v469];
      int v361 = v359[v454];
      int v470 = v361 + ((int)((unsigned int)(v361 - v360) >> 31));
      v359[v454] = v470;
      int * v363 = v326->cache_age;
      int v364 = v363[v455];
      int v472 = v364 + ((int)((unsigned int)(v364 - v360) >> 31));
      v363[v455] = v472;
      int * v366 = v326->cache_age;
      v366[v469] = 0;
      v412 = v469;
    } else {
      int * v369 = v326->cache_age;
      int v476 = 4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2);
      int v370 = v369[v476];
      int * v371 = v326->cache_tags;
      int v372 = v371[v476];
      int v373 = v369[v455];
      int v374 = v371[v455];
      int * v375 = v326->cache_dirty;
      int v479 = (4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2)) + ((((v370 + ((~(((v372 ^ -1) | (-(v372 ^ -1))) >> 31)) & 2)) - (v373 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v376 = v375[v479];
      bool v480 = !(v376 == 0);
      if (v480) {
        int * v377 = v326->cache_tags;
        int v378 = v377[v479];
        int * v379 = v326->cache_vals;
        int v483 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2)) + ((((v370 + ((~(((v372 ^ -1) | (-(v372 ^ -1))) >> 31)) & 2)) - (v373 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v380 = v379[v483];
        int v484 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2)) + ((((v370 + ((~(((v372 ^ -1) | (-(v372 ^ -1))) >> 31)) & 2)) - (v373 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v381 = v379[v484];
        int * v382 = v326->mem;
        int v486 = v378 * 2;
        v382[v486] = v380;
        int * v384 = v326->mem;
        int v489 = (v378 * 2) + 1;
        v384[v489] = v381;
        ;
      } else {
        ;
      }
      int * v389 = v326->mem;
      int v494 = ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) * 2;
      int v390 = v389[v494];
      int v495 = (((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) * 2) + 1;
      int v391 = v389[v495];
      int * v392 = v326->cache_vals;
      int v497 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2)) + ((((v370 + ((~(((v372 ^ -1) | (-(v372 ^ -1))) >> 31)) & 2)) - (v373 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v392[v497] = v390;
      int * v394 = v326->cache_vals;
      int v500 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2)) + ((((v370 + ((~(((v372 ^ -1) | (-(v372 ^ -1))) >> 31)) & 2)) - (v373 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v394[v500] = v391;
      int * v396 = v326->cache_tags;
      int v503 = (int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1);
      v396[v479] = v503;
      int * v398 = v326->cache_dirty;
      v398[v479] = 0;
      int * v400 = v326->cache_age;
      v400[v479] = 1;
      int * v402 = v326->cache_age;
      int v403 = v402[v479];
      int v404 = v402[v454];
      int v509 = v404 + ((int)((unsigned int)(v404 - v403) >> 31));
      v402[v454] = v509;
      int * v406 = v326->cache_age;
      int v407 = v406[v455];
      int v511 = v407 + ((int)((unsigned int)(v407 - v403) >> 31));
      v406[v455] = v511;
      int * v409 = v326->cache_age;
      v409[v479] = 0;
      v412 = v479;
    }
    int * v413 = v326->cache_vals;
    int v514 = v412 * 2;
    int v414 = v413[v514];
    int v515 = (v412 * 2) + 1;
    int v415 = v413[v515];
    int v516 = (((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 1) * 2) + ((((v354 + ((~(((v356 ^ -1) | (-(v356 ^ -1))) >> 31)) & 2)) - (v357 + ((~(((v358 ^ -1) | (-(v358 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v413[v516] = v414;
    int * v417 = v326->cache_vals;
    int v519 = ((((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 1) * 2) + ((((v354 + ((~(((v356 ^ -1) | (-(v356 ^ -1))) >> 31)) & 2)) - (v357 + ((~(((v358 ^ -1) | (-(v358 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v417[v519] = v415;
    int * v419 = v326->cache_tags;
    int v522 = ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 1) * 2) + ((((v354 + ((~(((v356 ^ -1) | (-(v356 ^ -1))) >> 31)) & 2)) - (v357 + ((~(((v358 ^ -1) | (-(v358 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v523 = (int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1);
    v419[v522] = v523;
    int * v421 = v326->cache_dirty;
    v421[v522] = 0;
    int * v423 = v326->cache_age;
    v423[v522] = 1;
    int * v425 = v326->cache_age;
    int v426 = v425[v522];
    int v427 = v425[v452];
    int v529 = v427 + ((int)((unsigned int)(v427 - v426) >> 31));
    v425[v452] = v529;
    int * v429 = v326->cache_age;
    int v430 = v429[v453];
    int v531 = v430 + ((int)((unsigned int)(v430 - v426) >> 31));
    v429[v453] = v531;
    int * v432 = v326->cache_age;
    v432[v522] = 0;
    v435 = v522;
  }
  int v534 = (v435 * 2) + (((int)((unsigned int)v336 >> 2)) & 1);
  int v436 = v342[v534];
  int * v437 = v326->reg_ready;
  int v536 = ((v334 + ((v331 - v334) & (~((v331 - v334) >> 31)))) + 1) + ((100 ^ (((~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31)) | (~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v338 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v338 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31)) | (~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31)) | (~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31))) & 104)))));
  v437[12] = v536;
  int * v439 = v326->regs;
  v439[12] = v436;
  struct StateT * v441 = slot_8(v326);
  return v441;
}

struct StateT * slot_3(struct StateT * v50) {
  int v51 = v50->timer;
  int v55 = v51 + 1;
  v50->timer = v55;
  struct StateT * v53 = slot_4(v50);
  return v53;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->reg_ready;
  v5[13] = v11;
  int * v7 = v2->regs;
  v7[13] = 0;
  struct StateT * v9 = slot_1(v2);
  return v9;
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
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}