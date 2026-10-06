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

struct StateT * slot_12(struct StateT * v647);
struct StateT * slot_6(struct StateT * v90);
struct StateT * slot_16(struct StateT * v949);
struct StateT * slot_23(struct StateT * v1491);
struct StateT * slot_5(struct StateT * v82);
struct StateT * slot_2(struct StateT * v34);
struct StateT * slot_7(struct StateT * v122);
struct StateT * slot_21(struct StateT * v1244);
struct StateT * slot_3(struct StateT * v50);
struct StateT * slot_10(struct StateT * v584);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_13(struct StateT * v901);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v928);
struct StateT * slot_20(struct StateT * v1212);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_4(struct StateT * v66);
struct StateT * slot_12(struct StateT * v647) {
  int * v648 = v647->regs;
  int v649 = v648[14];
  int v650 = v648[15];
  bool v782 = v649 >= v650;
  struct StateT * v777;
  if (v782) {
    int v651 = v647->timer;
    int v783 = v651 + 15;
    v647->timer = v783;
    int * v653 = v647->saved_regs;
    int v654 = v653[6];
    int * v655 = v647->regs;
    v655[6] = v654;
    int * v657 = v647->saved_regs;
    int v658 = v657[7];
    int * v659 = v647->regs;
    v659[7] = v658;
    int * v661 = v647->saved_regs;
    int v662 = v661[8];
    int * v663 = v647->regs;
    v663[8] = v662;
    int * v665 = v647->saved_regs;
    int v666 = v665[9];
    int * v667 = v647->regs;
    v667[9] = v666;
    int * v669 = v647->saved_regs;
    int v670 = v669[16];
    int * v671 = v647->regs;
    v671[16] = v670;
    int * v673 = v647->saved_regs;
    int v674 = v673[5];
    int * v675 = v647->regs;
    v675[5] = v674;
    int * v677 = v647->reg_ready;
    int v678 = v647->timer;
    v677[0] = v678;
    int * v680 = v647->reg_ready;
    int v681 = v647->timer;
    v680[1] = v681;
    int * v683 = v647->reg_ready;
    int v684 = v647->timer;
    v683[2] = v684;
    int * v686 = v647->reg_ready;
    int v687 = v647->timer;
    v686[3] = v687;
    int * v689 = v647->reg_ready;
    int v690 = v647->timer;
    v689[4] = v690;
    int * v692 = v647->reg_ready;
    int v693 = v647->timer;
    v692[5] = v693;
    int * v695 = v647->reg_ready;
    int v696 = v647->timer;
    v695[6] = v696;
    int * v698 = v647->reg_ready;
    int v699 = v647->timer;
    v698[7] = v699;
    int * v701 = v647->reg_ready;
    int v702 = v647->timer;
    v701[8] = v702;
    int * v704 = v647->reg_ready;
    int v705 = v647->timer;
    v704[9] = v705;
    int * v707 = v647->reg_ready;
    int v708 = v647->timer;
    v707[10] = v708;
    int * v710 = v647->reg_ready;
    int v711 = v647->timer;
    v710[11] = v711;
    int * v713 = v647->reg_ready;
    int v714 = v647->timer;
    v713[12] = v714;
    int * v716 = v647->reg_ready;
    int v717 = v647->timer;
    v716[13] = v717;
    int * v719 = v647->reg_ready;
    int v720 = v647->timer;
    v719[14] = v720;
    int * v722 = v647->reg_ready;
    int v723 = v647->timer;
    v722[15] = v723;
    int * v725 = v647->reg_ready;
    int v726 = v647->timer;
    v725[16] = v726;
    int * v728 = v647->reg_ready;
    int v729 = v647->timer;
    v728[17] = v729;
    int * v731 = v647->reg_ready;
    int v732 = v647->timer;
    v731[18] = v732;
    int * v734 = v647->reg_ready;
    int v735 = v647->timer;
    v734[19] = v735;
    int * v737 = v647->reg_ready;
    int v738 = v647->timer;
    v737[20] = v738;
    int * v740 = v647->reg_ready;
    int v741 = v647->timer;
    v740[21] = v741;
    int * v743 = v647->reg_ready;
    int v744 = v647->timer;
    v743[22] = v744;
    int * v746 = v647->reg_ready;
    int v747 = v647->timer;
    v746[23] = v747;
    int * v749 = v647->reg_ready;
    int v750 = v647->timer;
    v749[24] = v750;
    int * v752 = v647->reg_ready;
    int v753 = v647->timer;
    v752[25] = v753;
    int * v755 = v647->reg_ready;
    int v756 = v647->timer;
    v755[26] = v756;
    int * v758 = v647->reg_ready;
    int v759 = v647->timer;
    v758[27] = v759;
    int * v761 = v647->reg_ready;
    int v762 = v647->timer;
    v761[28] = v762;
    int * v764 = v647->reg_ready;
    int v765 = v647->timer;
    v764[29] = v765;
    int * v767 = v647->reg_ready;
    int v768 = v647->timer;
    v767[30] = v768;
    int * v770 = v647->reg_ready;
    int v771 = v647->timer;
    v770[31] = v771;
    struct StateT * v773 = slot_13(v647);
    v777 = v773;
  } else {
    struct StateT * v775 = slot_14(v647);
    v777 = v775;
  }
  return v777;
}

struct StateT * slot_6(struct StateT * v90) {
  int * v91 = v90->saved_regs;
  int * v92 = v90->regs;
  int v93 = v92[6];
  v91[6] = v93;
  int v95 = v90->timer;
  int v112 = v95 + 1;
  v90->timer = v112;
  int * v97 = v90->reg_ready;
  int v98 = v97[12];
  int * v99 = v90->regs;
  int v100 = v99[12];
  int v101 = v97[14];
  int v102 = v99[14];
  int v117 = (v101 + (((v98 + ((v95 - v98) & (~((v95 - v98) >> 31)))) - v101) & (~(((v98 + ((v95 - v98) & (~((v95 - v98) >> 31)))) - v101) >> 31)))) + 1;
  v97[6] = v117;
  int * v104 = v90->regs;
  int v119 = v100 + v102;
  v104[6] = v119;
  struct StateT * v106 = slot_7(v90);
  return v106;
}

struct StateT * slot_16(struct StateT * v949) {
  int v950 = v949->timer;
  int v954 = v950 + 1;
  v949->timer = v954;
  struct StateT * v952 = slot_5(v949);
  return v952;
}

struct StateT * slot_23(struct StateT * v1491) {
  int * v1492 = v1491->saved_regs;
  int * v1493 = v1491->regs;
  int v1494 = v1493[5];
  v1492[5] = v1494;
  int v1496 = v1491->timer;
  int v1513 = v1496 + 1;
  v1491->timer = v1513;
  int * v1498 = v1491->reg_ready;
  int v1499 = v1498[5];
  int * v1500 = v1491->regs;
  int v1501 = v1500[5];
  int v1502 = v1498[16];
  int v1503 = v1500[16];
  int v1517 = (v1502 + (((v1499 + ((v1496 - v1499) & (~((v1496 - v1499) >> 31)))) - v1502) & (~(((v1499 + ((v1496 - v1499) & (~((v1496 - v1499) >> 31)))) - v1502) >> 31)))) + 1;
  v1498[5] = v1517;
  int * v1505 = v1491->regs;
  int v1519 = v1501 | v1503;
  v1505[5] = v1519;
  struct StateT * v1507 = slot_12(v1491);
  return v1507;
}

struct StateT * slot_5(struct StateT * v82) {
  int v83 = v82->timer;
  int v87 = v83 + 1;
  v82->timer = v87;
  struct StateT * v85 = slot_6(v82);
  return v85;
}

struct StateT * slot_2(struct StateT * v34) {
  int v35 = v34->timer;
  int v43 = v35 + 1;
  v34->timer = v43;
  int * v37 = v34->reg_ready;
  v37[14] = v43;
  int * v39 = v34->regs;
  v39[14] = 0;
  struct StateT * v41 = slot_3(v34);
  return v41;
}

struct StateT * slot_7(struct StateT * v122) {
  int * v123 = v122->saved_regs;
  int * v124 = v122->regs;
  int v125 = v124[7];
  v123[7] = v125;
  int v127 = v122->timer;
  int v243 = v127 + 1;
  v122->timer = v243;
  int * v129 = v122->reg_ready;
  int v130 = v129[6];
  int * v131 = v122->regs;
  int v132 = v131[6];
  int * v133 = v122->cache_tags;
  int v248 = (((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 1) * 2;
  int v134 = v133[v248];
  int v249 = ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 1) * 2) + 1;
  int v135 = v133[v249];
  int v250 = 4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2);
  int v136 = v133[v250];
  int v251 = (4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v137 = v133[v251];
  int * v138 = v122->cache_vals;
  bool v252 = !(((~(((v134 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v134 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31)) | (~(((v135 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v135 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31))) == 0);
  int v231;
  if (v252) {
    int * v139 = v122->cache_age;
    int v254 = ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 1) * 2) + ((~(((v135 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v135 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31)) & 1);
    int v140 = v139[v254];
    int v141 = v139[v248];
    int v255 = v141 + ((int)((unsigned int)(v141 - v140) >> 31));
    v139[v248] = v255;
    int * v143 = v122->cache_age;
    int v144 = v143[v249];
    int v257 = v144 + ((int)((unsigned int)(v144 - v140) >> 31));
    v143[v249] = v257;
    int * v146 = v122->cache_age;
    v146[v254] = 0;
    v231 = v254;
  } else {
    int * v149 = v122->cache_age;
    int v261 = (((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 1) * 2;
    int v150 = v149[v261];
    int * v151 = v122->cache_tags;
    int v152 = v151[v261];
    int v153 = v149[v249];
    int v154 = v151[v249];
    bool v263 = !(((~(((v136 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v136 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31)) | (~(((v137 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v137 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31))) == 0);
    int v208;
    if (v263) {
      int * v155 = v122->cache_age;
      int v265 = (4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2)) + ((~(((v137 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v137 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31)) & 1);
      int v156 = v155[v265];
      int v157 = v155[v250];
      int v266 = v157 + ((int)((unsigned int)(v157 - v156) >> 31));
      v155[v250] = v266;
      int * v159 = v122->cache_age;
      int v160 = v159[v251];
      int v268 = v160 + ((int)((unsigned int)(v160 - v156) >> 31));
      v159[v251] = v268;
      int * v162 = v122->cache_age;
      v162[v265] = 0;
      v208 = v265;
    } else {
      int * v165 = v122->cache_age;
      int v272 = 4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2);
      int v166 = v165[v272];
      int * v167 = v122->cache_tags;
      int v168 = v167[v272];
      int v169 = v165[v251];
      int v170 = v167[v251];
      int * v171 = v122->cache_dirty;
      int v275 = (4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2)) + ((((v166 + ((~(((v168 ^ -1) | (-(v168 ^ -1))) >> 31)) & 2)) - (v169 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v172 = v171[v275];
      bool v276 = !(v172 == 0);
      if (v276) {
        int * v173 = v122->cache_tags;
        int v174 = v173[v275];
        int * v175 = v122->cache_vals;
        int v279 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2)) + ((((v166 + ((~(((v168 ^ -1) | (-(v168 ^ -1))) >> 31)) & 2)) - (v169 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v176 = v175[v279];
        int v280 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2)) + ((((v166 + ((~(((v168 ^ -1) | (-(v168 ^ -1))) >> 31)) & 2)) - (v169 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v177 = v175[v280];
        int * v178 = v122->mem;
        int v282 = v174 * 2;
        v178[v282] = v176;
        int * v180 = v122->mem;
        int v285 = (v174 * 2) + 1;
        v180[v285] = v177;
        ;
      } else {
        ;
      }
      int * v185 = v122->mem;
      int v290 = ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) * 2;
      int v186 = v185[v290];
      int v291 = (((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) * 2) + 1;
      int v187 = v185[v291];
      int * v188 = v122->cache_vals;
      int v293 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2)) + ((((v166 + ((~(((v168 ^ -1) | (-(v168 ^ -1))) >> 31)) & 2)) - (v169 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v188[v293] = v186;
      int * v190 = v122->cache_vals;
      int v296 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2)) + ((((v166 + ((~(((v168 ^ -1) | (-(v168 ^ -1))) >> 31)) & 2)) - (v169 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v190[v296] = v187;
      int * v192 = v122->cache_tags;
      int v299 = (int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1);
      v192[v275] = v299;
      int * v194 = v122->cache_dirty;
      v194[v275] = 0;
      int * v196 = v122->cache_age;
      v196[v275] = 1;
      int * v198 = v122->cache_age;
      int v199 = v198[v275];
      int v200 = v198[v250];
      int v305 = v200 + ((int)((unsigned int)(v200 - v199) >> 31));
      v198[v250] = v305;
      int * v202 = v122->cache_age;
      int v203 = v202[v251];
      int v307 = v203 + ((int)((unsigned int)(v203 - v199) >> 31));
      v202[v251] = v307;
      int * v205 = v122->cache_age;
      v205[v275] = 0;
      v208 = v275;
    }
    int * v209 = v122->cache_vals;
    int v310 = v208 * 2;
    int v210 = v209[v310];
    int v311 = (v208 * 2) + 1;
    int v211 = v209[v311];
    int v312 = (((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 1) * 2) + ((((v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2)) - (v153 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v209[v312] = v210;
    int * v213 = v122->cache_vals;
    int v315 = ((((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 1) * 2) + ((((v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2)) - (v153 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v213[v315] = v211;
    int * v215 = v122->cache_tags;
    int v318 = ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 1) * 2) + ((((v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2)) - (v153 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v319 = (int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1);
    v215[v318] = v319;
    int * v217 = v122->cache_dirty;
    v217[v318] = 0;
    int * v219 = v122->cache_age;
    v219[v318] = 1;
    int * v221 = v122->cache_age;
    int v222 = v221[v318];
    int v223 = v221[v248];
    int v325 = v223 + ((int)((unsigned int)(v223 - v222) >> 31));
    v221[v248] = v325;
    int * v225 = v122->cache_age;
    int v226 = v225[v249];
    int v327 = v226 + ((int)((unsigned int)(v226 - v222) >> 31));
    v225[v249] = v327;
    int * v228 = v122->cache_age;
    v228[v318] = 0;
    v231 = v318;
  }
  int v330 = (v231 * 2) + (((int)((unsigned int)v132 >> 2)) & 1);
  int v232 = v138[v330];
  int * v233 = v122->reg_ready;
  int v332 = ((v130 + ((v127 - v130) & (~((v127 - v130) >> 31)))) + 1) + ((100 ^ (((~(((v136 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v136 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31)) | (~(((v137 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v137 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v134 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v134 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31)) | (~(((v135 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v135 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v136 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v136 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31)) | (~(((v137 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v137 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31))) & 104)))));
  v233[7] = v332;
  int * v235 = v122->regs;
  v235[7] = v232;
  struct StateT * v237 = slot_20(v122);
  return v237;
}

struct StateT * slot_21(struct StateT * v1244) {
  int * v1245 = v1244->saved_regs;
  int * v1246 = v1244->regs;
  int v1247 = v1246[9];
  v1245[9] = v1247;
  int v1249 = v1244->timer;
  int v1365 = v1249 + 1;
  v1244->timer = v1365;
  int * v1251 = v1244->reg_ready;
  int v1252 = v1251[8];
  int * v1253 = v1244->regs;
  int v1254 = v1253[8];
  int * v1255 = v1244->cache_tags;
  int v1370 = (((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1)) & 1) * 2;
  int v1256 = v1255[v1370];
  int v1371 = ((((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1257 = v1255[v1371];
  int v1372 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1)) & 3) * 2);
  int v1258 = v1255[v1372];
  int v1373 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1259 = v1255[v1373];
  int * v1260 = v1244->cache_vals;
  bool v1374 = !(((~(((v1256 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))) | (-(v1256 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))))) >> 31)) | (~(((v1257 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))) | (-(v1257 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))))) >> 31))) == 0);
  int v1353;
  if (v1374) {
    int * v1261 = v1244->cache_age;
    int v1376 = ((((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1)) & 1) * 2) + ((~(((v1257 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))) | (-(v1257 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))))) >> 31)) & 1);
    int v1262 = v1261[v1376];
    int v1263 = v1261[v1370];
    int v1377 = v1263 + ((int)((unsigned int)(v1263 - v1262) >> 31));
    v1261[v1370] = v1377;
    int * v1265 = v1244->cache_age;
    int v1266 = v1265[v1371];
    int v1379 = v1266 + ((int)((unsigned int)(v1266 - v1262) >> 31));
    v1265[v1371] = v1379;
    int * v1268 = v1244->cache_age;
    v1268[v1376] = 0;
    v1353 = v1376;
  } else {
    int * v1271 = v1244->cache_age;
    int v1383 = (((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1)) & 1) * 2;
    int v1272 = v1271[v1383];
    int * v1273 = v1244->cache_tags;
    int v1274 = v1273[v1383];
    int v1275 = v1271[v1371];
    int v1276 = v1273[v1371];
    bool v1385 = !(((~(((v1258 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))) | (-(v1258 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))))) >> 31)) | (~(((v1259 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))) | (-(v1259 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))))) >> 31))) == 0);
    int v1330;
    if (v1385) {
      int * v1277 = v1244->cache_age;
      int v1387 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1259 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))) | (-(v1259 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))))) >> 31)) & 1);
      int v1278 = v1277[v1387];
      int v1279 = v1277[v1372];
      int v1388 = v1279 + ((int)((unsigned int)(v1279 - v1278) >> 31));
      v1277[v1372] = v1388;
      int * v1281 = v1244->cache_age;
      int v1282 = v1281[v1373];
      int v1390 = v1282 + ((int)((unsigned int)(v1282 - v1278) >> 31));
      v1281[v1373] = v1390;
      int * v1284 = v1244->cache_age;
      v1284[v1387] = 0;
      v1330 = v1387;
    } else {
      int * v1287 = v1244->cache_age;
      int v1394 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1)) & 3) * 2);
      int v1288 = v1287[v1394];
      int * v1289 = v1244->cache_tags;
      int v1290 = v1289[v1394];
      int v1291 = v1287[v1373];
      int v1292 = v1289[v1373];
      int * v1293 = v1244->cache_dirty;
      int v1397 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1)) & 3) * 2)) + ((((v1288 + ((~(((v1290 ^ -1) | (-(v1290 ^ -1))) >> 31)) & 2)) - (v1291 + ((~(((v1292 ^ -1) | (-(v1292 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1294 = v1293[v1397];
      bool v1398 = !(v1294 == 0);
      if (v1398) {
        int * v1295 = v1244->cache_tags;
        int v1296 = v1295[v1397];
        int * v1297 = v1244->cache_vals;
        int v1401 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1)) & 3) * 2)) + ((((v1288 + ((~(((v1290 ^ -1) | (-(v1290 ^ -1))) >> 31)) & 2)) - (v1291 + ((~(((v1292 ^ -1) | (-(v1292 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1298 = v1297[v1401];
        int v1402 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1)) & 3) * 2)) + ((((v1288 + ((~(((v1290 ^ -1) | (-(v1290 ^ -1))) >> 31)) & 2)) - (v1291 + ((~(((v1292 ^ -1) | (-(v1292 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1299 = v1297[v1402];
        int * v1300 = v1244->mem;
        int v1404 = v1296 * 2;
        v1300[v1404] = v1298;
        int * v1302 = v1244->mem;
        int v1407 = (v1296 * 2) + 1;
        v1302[v1407] = v1299;
        ;
      } else {
        ;
      }
      int * v1307 = v1244->mem;
      int v1412 = ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1)) * 2;
      int v1308 = v1307[v1412];
      int v1413 = (((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1)) * 2) + 1;
      int v1309 = v1307[v1413];
      int * v1310 = v1244->cache_vals;
      int v1415 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1)) & 3) * 2)) + ((((v1288 + ((~(((v1290 ^ -1) | (-(v1290 ^ -1))) >> 31)) & 2)) - (v1291 + ((~(((v1292 ^ -1) | (-(v1292 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1310[v1415] = v1308;
      int * v1312 = v1244->cache_vals;
      int v1418 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1)) & 3) * 2)) + ((((v1288 + ((~(((v1290 ^ -1) | (-(v1290 ^ -1))) >> 31)) & 2)) - (v1291 + ((~(((v1292 ^ -1) | (-(v1292 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1312[v1418] = v1309;
      int * v1314 = v1244->cache_tags;
      int v1421 = (int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1);
      v1314[v1397] = v1421;
      int * v1316 = v1244->cache_dirty;
      v1316[v1397] = 0;
      int * v1318 = v1244->cache_age;
      v1318[v1397] = 1;
      int * v1320 = v1244->cache_age;
      int v1321 = v1320[v1397];
      int v1322 = v1320[v1372];
      int v1427 = v1322 + ((int)((unsigned int)(v1322 - v1321) >> 31));
      v1320[v1372] = v1427;
      int * v1324 = v1244->cache_age;
      int v1325 = v1324[v1373];
      int v1429 = v1325 + ((int)((unsigned int)(v1325 - v1321) >> 31));
      v1324[v1373] = v1429;
      int * v1327 = v1244->cache_age;
      v1327[v1397] = 0;
      v1330 = v1397;
    }
    int * v1331 = v1244->cache_vals;
    int v1432 = v1330 * 2;
    int v1332 = v1331[v1432];
    int v1433 = (v1330 * 2) + 1;
    int v1333 = v1331[v1433];
    int v1434 = (((((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1)) & 1) * 2) + ((((v1272 + ((~(((v1274 ^ -1) | (-(v1274 ^ -1))) >> 31)) & 2)) - (v1275 + ((~(((v1276 ^ -1) | (-(v1276 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1331[v1434] = v1332;
    int * v1335 = v1244->cache_vals;
    int v1437 = ((((((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1)) & 1) * 2) + ((((v1272 + ((~(((v1274 ^ -1) | (-(v1274 ^ -1))) >> 31)) & 2)) - (v1275 + ((~(((v1276 ^ -1) | (-(v1276 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1335[v1437] = v1333;
    int * v1337 = v1244->cache_tags;
    int v1440 = ((((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1)) & 1) * 2) + ((((v1272 + ((~(((v1274 ^ -1) | (-(v1274 ^ -1))) >> 31)) & 2)) - (v1275 + ((~(((v1276 ^ -1) | (-(v1276 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1441 = (int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1);
    v1337[v1440] = v1441;
    int * v1339 = v1244->cache_dirty;
    v1339[v1440] = 0;
    int * v1341 = v1244->cache_age;
    v1341[v1440] = 1;
    int * v1343 = v1244->cache_age;
    int v1344 = v1343[v1440];
    int v1345 = v1343[v1370];
    int v1447 = v1345 + ((int)((unsigned int)(v1345 - v1344) >> 31));
    v1343[v1370] = v1447;
    int * v1347 = v1244->cache_age;
    int v1348 = v1347[v1371];
    int v1449 = v1348 + ((int)((unsigned int)(v1348 - v1344) >> 31));
    v1347[v1371] = v1449;
    int * v1350 = v1244->cache_age;
    v1350[v1440] = 0;
    v1353 = v1440;
  }
  int v1452 = (v1353 * 2) + (((int)((unsigned int)v1254 >> 2)) & 1);
  int v1354 = v1260[v1452];
  int * v1355 = v1244->reg_ready;
  int v1454 = ((v1252 + ((v1249 - v1252) & (~((v1249 - v1252) >> 31)))) + 1) + ((100 ^ (((~(((v1258 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))) | (-(v1258 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))))) >> 31)) | (~(((v1259 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))) | (-(v1259 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1256 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))) | (-(v1256 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))))) >> 31)) | (~(((v1257 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))) | (-(v1257 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1258 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))) | (-(v1258 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))))) >> 31)) | (~(((v1259 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))) | (-(v1259 ^ ((int)((unsigned int)((int)((unsigned int)v1254 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1355[9] = v1454;
  int * v1357 = v1244->regs;
  v1357[9] = v1354;
  struct StateT * v1359 = slot_10(v1244);
  return v1359;
}

struct StateT * slot_3(struct StateT * v50) {
  int v51 = v50->timer;
  int v59 = v51 + 1;
  v50->timer = v59;
  int * v53 = v50->reg_ready;
  v53[15] = v59;
  int * v55 = v50->regs;
  v55[15] = 16;
  struct StateT * v57 = slot_4(v50);
  return v57;
}

struct StateT * slot_10(struct StateT * v584) {
  int * v585 = v584->saved_regs;
  int * v586 = v584->regs;
  int v587 = v586[16];
  v585[16] = v587;
  int v589 = v584->timer;
  int v606 = v589 + 1;
  v584->timer = v606;
  int * v591 = v584->reg_ready;
  int v592 = v591[7];
  int * v593 = v584->regs;
  int v594 = v593[7];
  int v595 = v591[9];
  int v596 = v593[9];
  int v611 = (v595 + (((v592 + ((v589 - v592) & (~((v589 - v592) >> 31)))) - v595) & (~(((v592 + ((v589 - v592) & (~((v589 - v592) >> 31)))) - v595) >> 31)))) + 1;
  v591[16] = v611;
  int * v598 = v584->regs;
  int v613 = v594 ^ v596;
  v598[16] = v613;
  struct StateT * v600 = slot_23(v584);
  return v600;
}

struct StateT * slot_1(struct StateT * v18) {
  int v19 = v18->timer;
  int v27 = v19 + 1;
  v18->timer = v27;
  int * v21 = v18->reg_ready;
  v21[13] = v27;
  int * v23 = v18->regs;
  v23[13] = 80;
  struct StateT * v25 = slot_2(v18);
  return v25;
}

struct StateT * slot_13(struct StateT * v901) {
  int v902 = v901->timer;
  int v916 = v902 + 1;
  v901->timer = v916;
  int * v904 = v901->reg_ready;
  int v905 = v904[5];
  int * v906 = v901->regs;
  int v907 = v906[5];
  bool v920 = (v907 ^ -2147483648) < -2147483647;
  int v910;
  if (v920) {
    v910 = 1;
  } else {
    v910 = 0;
  }
  int * v911 = v901->reg_ready;
  int v925 = (v905 + ((v902 - v905) & (~((v902 - v905) >> 31)))) + 1;
  v911[11] = v925;
  int * v913 = v901->regs;
  v913[11] = v910;
  return v901;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->reg_ready;
  v5[12] = v11;
  int * v7 = v2->regs;
  v7[12] = 0;
  struct StateT * v9 = slot_1(v2);
  return v9;
}

struct StateT * slot_14(struct StateT * v928) {
  int v929 = v928->timer;
  int v940 = v929 + 1;
  v928->timer = v940;
  int * v931 = v928->reg_ready;
  int v932 = v931[14];
  int * v933 = v928->regs;
  int v934 = v933[14];
  int v944 = (v932 + ((v929 - v932) & (~((v929 - v932) >> 31)))) + 1;
  v931[14] = v944;
  int * v936 = v928->regs;
  int v946 = v934 + 4;
  v936[14] = v946;
  struct StateT * v938 = slot_16(v928);
  return v938;
}

struct StateT * slot_20(struct StateT * v1212) {
  int * v1213 = v1212->saved_regs;
  int * v1214 = v1212->regs;
  int v1215 = v1214[8];
  v1213[8] = v1215;
  int v1217 = v1212->timer;
  int v1234 = v1217 + 1;
  v1212->timer = v1234;
  int * v1219 = v1212->reg_ready;
  int v1220 = v1219[13];
  int * v1221 = v1212->regs;
  int v1222 = v1221[13];
  int v1223 = v1219[14];
  int v1224 = v1221[14];
  int v1239 = (v1223 + (((v1220 + ((v1217 - v1220) & (~((v1217 - v1220) >> 31)))) - v1223) & (~(((v1220 + ((v1217 - v1220) & (~((v1217 - v1220) >> 31)))) - v1223) >> 31)))) + 1;
  v1219[8] = v1239;
  int * v1226 = v1212->regs;
  int v1241 = v1222 + v1224;
  v1226[8] = v1241;
  struct StateT * v1228 = slot_21(v1212);
  return v1228;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v1776 = v1->timer;
  int * v1777 = v1->reg_ready;
  int v1778 = v1777[0];
  int v1909 = v1778 + ((v1776 - v1778) & (~((v1776 - v1778) >> 31)));
  v1->timer = v1909;
  int v1780 = v1->timer;
  int * v1781 = v1->reg_ready;
  int v1782 = v1781[1];
  int v1912 = v1782 + ((v1780 - v1782) & (~((v1780 - v1782) >> 31)));
  v1->timer = v1912;
  int v1784 = v1->timer;
  int * v1785 = v1->reg_ready;
  int v1786 = v1785[2];
  int v1915 = v1786 + ((v1784 - v1786) & (~((v1784 - v1786) >> 31)));
  v1->timer = v1915;
  int v1788 = v1->timer;
  int * v1789 = v1->reg_ready;
  int v1790 = v1789[3];
  int v1918 = v1790 + ((v1788 - v1790) & (~((v1788 - v1790) >> 31)));
  v1->timer = v1918;
  int v1792 = v1->timer;
  int * v1793 = v1->reg_ready;
  int v1794 = v1793[4];
  int v1921 = v1794 + ((v1792 - v1794) & (~((v1792 - v1794) >> 31)));
  v1->timer = v1921;
  int v1796 = v1->timer;
  int * v1797 = v1->reg_ready;
  int v1798 = v1797[5];
  int v1924 = v1798 + ((v1796 - v1798) & (~((v1796 - v1798) >> 31)));
  v1->timer = v1924;
  int v1800 = v1->timer;
  int * v1801 = v1->reg_ready;
  int v1802 = v1801[6];
  int v1927 = v1802 + ((v1800 - v1802) & (~((v1800 - v1802) >> 31)));
  v1->timer = v1927;
  int v1804 = v1->timer;
  int * v1805 = v1->reg_ready;
  int v1806 = v1805[7];
  int v1930 = v1806 + ((v1804 - v1806) & (~((v1804 - v1806) >> 31)));
  v1->timer = v1930;
  int v1808 = v1->timer;
  int * v1809 = v1->reg_ready;
  int v1810 = v1809[8];
  int v1933 = v1810 + ((v1808 - v1810) & (~((v1808 - v1810) >> 31)));
  v1->timer = v1933;
  int v1812 = v1->timer;
  int * v1813 = v1->reg_ready;
  int v1814 = v1813[9];
  int v1936 = v1814 + ((v1812 - v1814) & (~((v1812 - v1814) >> 31)));
  v1->timer = v1936;
  int v1816 = v1->timer;
  int * v1817 = v1->reg_ready;
  int v1818 = v1817[10];
  int v1939 = v1818 + ((v1816 - v1818) & (~((v1816 - v1818) >> 31)));
  v1->timer = v1939;
  int v1820 = v1->timer;
  int * v1821 = v1->reg_ready;
  int v1822 = v1821[11];
  int v1942 = v1822 + ((v1820 - v1822) & (~((v1820 - v1822) >> 31)));
  v1->timer = v1942;
  int v1824 = v1->timer;
  int * v1825 = v1->reg_ready;
  int v1826 = v1825[12];
  int v1945 = v1826 + ((v1824 - v1826) & (~((v1824 - v1826) >> 31)));
  v1->timer = v1945;
  int v1828 = v1->timer;
  int * v1829 = v1->reg_ready;
  int v1830 = v1829[13];
  int v1948 = v1830 + ((v1828 - v1830) & (~((v1828 - v1830) >> 31)));
  v1->timer = v1948;
  int v1832 = v1->timer;
  int * v1833 = v1->reg_ready;
  int v1834 = v1833[14];
  int v1951 = v1834 + ((v1832 - v1834) & (~((v1832 - v1834) >> 31)));
  v1->timer = v1951;
  int v1836 = v1->timer;
  int * v1837 = v1->reg_ready;
  int v1838 = v1837[15];
  int v1954 = v1838 + ((v1836 - v1838) & (~((v1836 - v1838) >> 31)));
  v1->timer = v1954;
  int v1840 = v1->timer;
  int * v1841 = v1->reg_ready;
  int v1842 = v1841[16];
  int v1957 = v1842 + ((v1840 - v1842) & (~((v1840 - v1842) >> 31)));
  v1->timer = v1957;
  int v1844 = v1->timer;
  int * v1845 = v1->reg_ready;
  int v1846 = v1845[17];
  int v1960 = v1846 + ((v1844 - v1846) & (~((v1844 - v1846) >> 31)));
  v1->timer = v1960;
  int v1848 = v1->timer;
  int * v1849 = v1->reg_ready;
  int v1850 = v1849[18];
  int v1963 = v1850 + ((v1848 - v1850) & (~((v1848 - v1850) >> 31)));
  v1->timer = v1963;
  int v1852 = v1->timer;
  int * v1853 = v1->reg_ready;
  int v1854 = v1853[19];
  int v1966 = v1854 + ((v1852 - v1854) & (~((v1852 - v1854) >> 31)));
  v1->timer = v1966;
  int v1856 = v1->timer;
  int * v1857 = v1->reg_ready;
  int v1858 = v1857[20];
  int v1969 = v1858 + ((v1856 - v1858) & (~((v1856 - v1858) >> 31)));
  v1->timer = v1969;
  int v1860 = v1->timer;
  int * v1861 = v1->reg_ready;
  int v1862 = v1861[21];
  int v1972 = v1862 + ((v1860 - v1862) & (~((v1860 - v1862) >> 31)));
  v1->timer = v1972;
  int v1864 = v1->timer;
  int * v1865 = v1->reg_ready;
  int v1866 = v1865[22];
  int v1975 = v1866 + ((v1864 - v1866) & (~((v1864 - v1866) >> 31)));
  v1->timer = v1975;
  int v1868 = v1->timer;
  int * v1869 = v1->reg_ready;
  int v1870 = v1869[23];
  int v1978 = v1870 + ((v1868 - v1870) & (~((v1868 - v1870) >> 31)));
  v1->timer = v1978;
  int v1872 = v1->timer;
  int * v1873 = v1->reg_ready;
  int v1874 = v1873[24];
  int v1981 = v1874 + ((v1872 - v1874) & (~((v1872 - v1874) >> 31)));
  v1->timer = v1981;
  int v1876 = v1->timer;
  int * v1877 = v1->reg_ready;
  int v1878 = v1877[25];
  int v1984 = v1878 + ((v1876 - v1878) & (~((v1876 - v1878) >> 31)));
  v1->timer = v1984;
  int v1880 = v1->timer;
  int * v1881 = v1->reg_ready;
  int v1882 = v1881[26];
  int v1987 = v1882 + ((v1880 - v1882) & (~((v1880 - v1882) >> 31)));
  v1->timer = v1987;
  int v1884 = v1->timer;
  int * v1885 = v1->reg_ready;
  int v1886 = v1885[27];
  int v1990 = v1886 + ((v1884 - v1886) & (~((v1884 - v1886) >> 31)));
  v1->timer = v1990;
  int v1888 = v1->timer;
  int * v1889 = v1->reg_ready;
  int v1890 = v1889[28];
  int v1993 = v1890 + ((v1888 - v1890) & (~((v1888 - v1890) >> 31)));
  v1->timer = v1993;
  int v1892 = v1->timer;
  int * v1893 = v1->reg_ready;
  int v1894 = v1893[29];
  int v1996 = v1894 + ((v1892 - v1894) & (~((v1892 - v1894) >> 31)));
  v1->timer = v1996;
  int v1896 = v1->timer;
  int * v1897 = v1->reg_ready;
  int v1898 = v1897[30];
  int v1999 = v1898 + ((v1896 - v1898) & (~((v1896 - v1898) >> 31)));
  v1->timer = v1999;
  int v1900 = v1->timer;
  int * v1901 = v1->reg_ready;
  int v1902 = v1901[31];
  int v2002 = v1902 + ((v1900 - v1902) & (~((v1900 - v1902) >> 31)));
  v1->timer = v2002;
  return v1;
}

struct StateT * slot_4(struct StateT * v66) {
  int v67 = v66->timer;
  int v75 = v67 + 1;
  v66->timer = v75;
  int * v69 = v66->reg_ready;
  v69[5] = v75;
  int * v71 = v66->regs;
  v71[5] = 0;
  struct StateT * v73 = slot_5(v66);
  return v73;
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