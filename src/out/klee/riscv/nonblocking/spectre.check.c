// verify: clean (KLEE should report no failing assertion) [budget 1200s]
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
struct StateT * slot_1(struct StateT * v20);
struct StateT * slot_6(struct StateT * v371);
struct StateT * slot_5(struct StateT * v116);
struct StateT * slot_4(struct StateT * v84);
struct StateT * slot_2(struct StateT * v38);
struct StateT * slot_7(struct StateT * v395);
struct StateT * slot_3(struct StateT * v56);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v647 = v1->timer;
  int * v648 = v1->reg_ready;
  int v649 = v648[0];
  int v780 = v649 + ((v647 - v649) & (~((v647 - v649) >> 31)));
  v1->timer = v780;
  int v651 = v1->timer;
  int * v652 = v1->reg_ready;
  int v653 = v652[1];
  int v783 = v653 + ((v651 - v653) & (~((v651 - v653) >> 31)));
  v1->timer = v783;
  int v655 = v1->timer;
  int * v656 = v1->reg_ready;
  int v657 = v656[2];
  int v786 = v657 + ((v655 - v657) & (~((v655 - v657) >> 31)));
  v1->timer = v786;
  int v659 = v1->timer;
  int * v660 = v1->reg_ready;
  int v661 = v660[3];
  int v789 = v661 + ((v659 - v661) & (~((v659 - v661) >> 31)));
  v1->timer = v789;
  int v663 = v1->timer;
  int * v664 = v1->reg_ready;
  int v665 = v664[4];
  int v792 = v665 + ((v663 - v665) & (~((v663 - v665) >> 31)));
  v1->timer = v792;
  int v667 = v1->timer;
  int * v668 = v1->reg_ready;
  int v669 = v668[5];
  int v795 = v669 + ((v667 - v669) & (~((v667 - v669) >> 31)));
  v1->timer = v795;
  int v671 = v1->timer;
  int * v672 = v1->reg_ready;
  int v673 = v672[6];
  int v798 = v673 + ((v671 - v673) & (~((v671 - v673) >> 31)));
  v1->timer = v798;
  int v675 = v1->timer;
  int * v676 = v1->reg_ready;
  int v677 = v676[7];
  int v801 = v677 + ((v675 - v677) & (~((v675 - v677) >> 31)));
  v1->timer = v801;
  int v679 = v1->timer;
  int * v680 = v1->reg_ready;
  int v681 = v680[8];
  int v804 = v681 + ((v679 - v681) & (~((v679 - v681) >> 31)));
  v1->timer = v804;
  int v683 = v1->timer;
  int * v684 = v1->reg_ready;
  int v685 = v684[9];
  int v807 = v685 + ((v683 - v685) & (~((v683 - v685) >> 31)));
  v1->timer = v807;
  int v687 = v1->timer;
  int * v688 = v1->reg_ready;
  int v689 = v688[10];
  int v810 = v689 + ((v687 - v689) & (~((v687 - v689) >> 31)));
  v1->timer = v810;
  int v691 = v1->timer;
  int * v692 = v1->reg_ready;
  int v693 = v692[11];
  int v813 = v693 + ((v691 - v693) & (~((v691 - v693) >> 31)));
  v1->timer = v813;
  int v695 = v1->timer;
  int * v696 = v1->reg_ready;
  int v697 = v696[12];
  int v816 = v697 + ((v695 - v697) & (~((v695 - v697) >> 31)));
  v1->timer = v816;
  int v699 = v1->timer;
  int * v700 = v1->reg_ready;
  int v701 = v700[13];
  int v819 = v701 + ((v699 - v701) & (~((v699 - v701) >> 31)));
  v1->timer = v819;
  int v703 = v1->timer;
  int * v704 = v1->reg_ready;
  int v705 = v704[14];
  int v822 = v705 + ((v703 - v705) & (~((v703 - v705) >> 31)));
  v1->timer = v822;
  int v707 = v1->timer;
  int * v708 = v1->reg_ready;
  int v709 = v708[15];
  int v825 = v709 + ((v707 - v709) & (~((v707 - v709) >> 31)));
  v1->timer = v825;
  int v711 = v1->timer;
  int * v712 = v1->reg_ready;
  int v713 = v712[16];
  int v828 = v713 + ((v711 - v713) & (~((v711 - v713) >> 31)));
  v1->timer = v828;
  int v715 = v1->timer;
  int * v716 = v1->reg_ready;
  int v717 = v716[17];
  int v831 = v717 + ((v715 - v717) & (~((v715 - v717) >> 31)));
  v1->timer = v831;
  int v719 = v1->timer;
  int * v720 = v1->reg_ready;
  int v721 = v720[18];
  int v834 = v721 + ((v719 - v721) & (~((v719 - v721) >> 31)));
  v1->timer = v834;
  int v723 = v1->timer;
  int * v724 = v1->reg_ready;
  int v725 = v724[19];
  int v837 = v725 + ((v723 - v725) & (~((v723 - v725) >> 31)));
  v1->timer = v837;
  int v727 = v1->timer;
  int * v728 = v1->reg_ready;
  int v729 = v728[20];
  int v840 = v729 + ((v727 - v729) & (~((v727 - v729) >> 31)));
  v1->timer = v840;
  int v731 = v1->timer;
  int * v732 = v1->reg_ready;
  int v733 = v732[21];
  int v843 = v733 + ((v731 - v733) & (~((v731 - v733) >> 31)));
  v1->timer = v843;
  int v735 = v1->timer;
  int * v736 = v1->reg_ready;
  int v737 = v736[22];
  int v846 = v737 + ((v735 - v737) & (~((v735 - v737) >> 31)));
  v1->timer = v846;
  int v739 = v1->timer;
  int * v740 = v1->reg_ready;
  int v741 = v740[23];
  int v849 = v741 + ((v739 - v741) & (~((v739 - v741) >> 31)));
  v1->timer = v849;
  int v743 = v1->timer;
  int * v744 = v1->reg_ready;
  int v745 = v744[24];
  int v852 = v745 + ((v743 - v745) & (~((v743 - v745) >> 31)));
  v1->timer = v852;
  int v747 = v1->timer;
  int * v748 = v1->reg_ready;
  int v749 = v748[25];
  int v855 = v749 + ((v747 - v749) & (~((v747 - v749) >> 31)));
  v1->timer = v855;
  int v751 = v1->timer;
  int * v752 = v1->reg_ready;
  int v753 = v752[26];
  int v858 = v753 + ((v751 - v753) & (~((v751 - v753) >> 31)));
  v1->timer = v858;
  int v755 = v1->timer;
  int * v756 = v1->reg_ready;
  int v757 = v756[27];
  int v861 = v757 + ((v755 - v757) & (~((v755 - v757) >> 31)));
  v1->timer = v861;
  int v759 = v1->timer;
  int * v760 = v1->reg_ready;
  int v761 = v760[28];
  int v864 = v761 + ((v759 - v761) & (~((v759 - v761) >> 31)));
  v1->timer = v864;
  int v763 = v1->timer;
  int * v764 = v1->reg_ready;
  int v765 = v764[29];
  int v867 = v765 + ((v763 - v765) & (~((v763 - v765) >> 31)));
  v1->timer = v867;
  int v767 = v1->timer;
  int * v768 = v1->reg_ready;
  int v769 = v768[30];
  int v870 = v769 + ((v767 - v769) & (~((v767 - v769) >> 31)));
  v1->timer = v870;
  int v771 = v1->timer;
  int * v772 = v1->reg_ready;
  int v773 = v772[31];
  int v873 = v773 + ((v771 - v773) & (~((v771 - v773) >> 31)));
  v1->timer = v873;
  return v1;
}

struct StateT * slot_1(struct StateT * v20) {
  int v21 = v20->timer;
  int v22 = v20->timer;
  int v30 = v22 + 1;
  v20->timer = v30;
  int * v24 = v20->reg_ready;
  int v33 = v21 + 1;
  v24[10] = v33;
  int * v26 = v20->regs;
  v26[10] = 80;
  struct StateT * v28 = slot_2(v20);
  return v28;
}

struct StateT * slot_6(struct StateT * v371) {
  int v372 = v371->timer;
  int v373 = v371->timer;
  int v385 = v373 + 1;
  v371->timer = v385;
  int * v375 = v371->reg_ready;
  int v376 = v375[11];
  int * v377 = v371->regs;
  int v378 = v377[11];
  int * v379 = v371->reg_ready;
  int v390 = (v376 + ((v372 - v376) & (~((v372 - v376) >> 31)))) + 1;
  v379[11] = v390;
  int * v381 = v371->regs;
  int v392 = v378 << 2;
  v381[11] = v392;
  struct StateT * v383 = slot_7(v371);
  return v383;
}

struct StateT * slot_5(struct StateT * v116) {
  int v117 = v116->timer;
  int v118 = v116->timer;
  int v253 = v118 + 1;
  v116->timer = v253;
  int * v120 = v116->reg_ready;
  int v121 = v120[5];
  int * v122 = v116->regs;
  int v123 = v122[5];
  int * v124 = v116->cache_tags;
  int v258 = (((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 1) * 2;
  int v125 = v124[v258];
  int * v126 = v116->cache_tags;
  int v260 = ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 1) * 2) + 1;
  int v127 = v126[v260];
  int * v128 = v116->cache_tags;
  int v262 = 4 + ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 3) * 2);
  int v129 = v128[v262];
  int * v130 = v116->cache_tags;
  int v264 = (4 + ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v131 = v130[v264];
  int * v132 = v116->cache_vals;
  bool v265 = !(((~(((v125 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v125 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31)) | (~(((v127 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v127 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31))) == 0);
  int v245;
  if (v265) {
    int * v133 = v116->cache_age;
    int v267 = ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 1) * 2) + ((~(((v127 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v127 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31)) & 1);
    int v134 = v133[v267];
    int * v135 = v116->cache_age;
    int v136 = v135[v258];
    int * v137 = v116->cache_age;
    int v270 = v136 + ((int)((unsigned int)(v136 - v134) >> 31));
    v137[v258] = v270;
    int * v139 = v116->cache_age;
    int v140 = v139[v260];
    int * v141 = v116->cache_age;
    int v273 = v140 + ((int)((unsigned int)(v140 - v134) >> 31));
    v141[v260] = v273;
    int * v143 = v116->cache_age;
    v143[v267] = 0;
    v245 = v267;
  } else {
    int * v146 = v116->cache_age;
    int v277 = (((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 1) * 2;
    int v147 = v146[v277];
    int * v148 = v116->cache_tags;
    int v149 = v148[v277];
    int * v150 = v116->cache_age;
    int v151 = v150[v260];
    int * v152 = v116->cache_tags;
    int v153 = v152[v260];
    bool v281 = !(((~(((v129 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v129 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31)) | (~(((v131 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v131 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31))) == 0);
    int v217;
    if (v281) {
      int * v154 = v116->cache_age;
      int v283 = (4 + ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 3) * 2)) + ((~(((v131 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v131 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31)) & 1);
      int v155 = v154[v283];
      int * v156 = v116->cache_age;
      int v157 = v156[v262];
      int * v158 = v116->cache_age;
      int v286 = v157 + ((int)((unsigned int)(v157 - v155) >> 31));
      v158[v262] = v286;
      int * v160 = v116->cache_age;
      int v161 = v160[v264];
      int * v162 = v116->cache_age;
      int v289 = v161 + ((int)((unsigned int)(v161 - v155) >> 31));
      v162[v264] = v289;
      int * v164 = v116->cache_age;
      v164[v283] = 0;
      v217 = v283;
    } else {
      int * v167 = v116->cache_age;
      int v293 = 4 + ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 3) * 2);
      int v168 = v167[v293];
      int * v169 = v116->cache_tags;
      int v170 = v169[v293];
      int * v171 = v116->cache_age;
      int v172 = v171[v264];
      int * v173 = v116->cache_tags;
      int v174 = v173[v264];
      int * v175 = v116->cache_dirty;
      int v298 = (4 + ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 3) * 2)) + ((((v168 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2)) - (v172 + ((~(((v174 ^ -1) | (-(v174 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v176 = v175[v298];
      bool v299 = !(v176 == 0);
      if (v299) {
        int * v177 = v116->cache_tags;
        int v178 = v177[v298];
        int * v179 = v116->cache_vals;
        int v302 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 3) * 2)) + ((((v168 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2)) - (v172 + ((~(((v174 ^ -1) | (-(v174 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v180 = v179[v302];
        int * v181 = v116->cache_vals;
        int v304 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 3) * 2)) + ((((v168 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2)) - (v172 + ((~(((v174 ^ -1) | (-(v174 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v182 = v181[v304];
        int * v183 = v116->mem;
        int v306 = v178 * 2;
        v183[v306] = v180;
        int * v185 = v116->mem;
        int v309 = (v178 * 2) + 1;
        v185[v309] = v182;
        ;
      } else {
        ;
      }
      int * v190 = v116->mem;
      int v314 = ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) * 2;
      int v191 = v190[v314];
      int * v192 = v116->mem;
      int v316 = (((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) * 2) + 1;
      int v193 = v192[v316];
      int * v194 = v116->cache_vals;
      int v318 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 3) * 2)) + ((((v168 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2)) - (v172 + ((~(((v174 ^ -1) | (-(v174 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v194[v318] = v191;
      int * v196 = v116->cache_vals;
      int v321 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 3) * 2)) + ((((v168 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2)) - (v172 + ((~(((v174 ^ -1) | (-(v174 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v196[v321] = v193;
      int * v198 = v116->cache_tags;
      int v324 = (int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1);
      v198[v298] = v324;
      int * v200 = v116->cache_dirty;
      v200[v298] = 0;
      int * v202 = v116->cache_age;
      v202[v298] = 1;
      int * v204 = v116->cache_age;
      int v205 = v204[v298];
      int * v206 = v116->cache_age;
      int v207 = v206[v262];
      int * v208 = v116->cache_age;
      int v332 = v207 + ((int)((unsigned int)(v207 - v205) >> 31));
      v208[v262] = v332;
      int * v210 = v116->cache_age;
      int v211 = v210[v264];
      int * v212 = v116->cache_age;
      int v335 = v211 + ((int)((unsigned int)(v211 - v205) >> 31));
      v212[v264] = v335;
      int * v214 = v116->cache_age;
      v214[v298] = 0;
      v217 = v298;
    }
    int * v218 = v116->cache_vals;
    int v338 = v217 * 2;
    int v219 = v218[v338];
    int * v220 = v116->cache_vals;
    int v340 = (v217 * 2) + 1;
    int v221 = v220[v340];
    int * v222 = v116->cache_vals;
    int v342 = (((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 1) * 2) + ((((v147 + ((~(((v149 ^ -1) | (-(v149 ^ -1))) >> 31)) & 2)) - (v151 + ((~(((v153 ^ -1) | (-(v153 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v222[v342] = v219;
    int * v224 = v116->cache_vals;
    int v345 = ((((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 1) * 2) + ((((v147 + ((~(((v149 ^ -1) | (-(v149 ^ -1))) >> 31)) & 2)) - (v151 + ((~(((v153 ^ -1) | (-(v153 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v224[v345] = v221;
    int * v226 = v116->cache_tags;
    int v348 = ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 1) * 2) + ((((v147 + ((~(((v149 ^ -1) | (-(v149 ^ -1))) >> 31)) & 2)) - (v151 + ((~(((v153 ^ -1) | (-(v153 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v349 = (int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1);
    v226[v348] = v349;
    int * v228 = v116->cache_dirty;
    v228[v348] = 0;
    int * v230 = v116->cache_age;
    v230[v348] = 1;
    int * v232 = v116->cache_age;
    int v233 = v232[v348];
    int * v234 = v116->cache_age;
    int v235 = v234[v258];
    int * v236 = v116->cache_age;
    int v357 = v235 + ((int)((unsigned int)(v235 - v233) >> 31));
    v236[v258] = v357;
    int * v238 = v116->cache_age;
    int v239 = v238[v260];
    int * v240 = v116->cache_age;
    int v360 = v239 + ((int)((unsigned int)(v239 - v233) >> 31));
    v240[v260] = v360;
    int * v242 = v116->cache_age;
    v242[v348] = 0;
    v245 = v348;
  }
  int v363 = (v245 * 2) + (((int)((unsigned int)v123 >> 2)) & 1);
  int v246 = v132[v363];
  int * v247 = v116->reg_ready;
  int v366 = ((v121 + ((v117 - v121) & (~((v117 - v121) >> 31)))) + 1) + ((100 ^ (((~(((v129 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v129 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31)) | (~(((v131 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v131 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v125 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v125 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31)) | (~(((v127 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v127 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v129 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v129 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31)) | (~(((v131 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v131 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31))) & 104)))));
  v247[11] = v366;
  int * v249 = v116->regs;
  v249[11] = v246;
  struct StateT * v251 = slot_6(v116);
  return v251;
}

struct StateT * slot_4(struct StateT * v84) {
  int v85 = v84->timer;
  int v86 = v84->timer;
  int v102 = v86 + 1;
  v84->timer = v102;
  int * v88 = v84->reg_ready;
  int v89 = v88[13];
  int * v90 = v84->regs;
  int v91 = v90[13];
  int * v92 = v84->reg_ready;
  int v93 = v92[10];
  int * v94 = v84->regs;
  int v95 = v94[10];
  int * v96 = v84->reg_ready;
  int v111 = (v93 + (((v89 + ((v85 - v89) & (~((v85 - v89) >> 31)))) - v93) & (~(((v89 + ((v85 - v89) & (~((v85 - v89) >> 31)))) - v93) >> 31)))) + 1;
  v96[5] = v111;
  int * v98 = v84->regs;
  int v113 = v91 + v95;
  v98[5] = v113;
  struct StateT * v100 = slot_5(v84);
  return v100;
}

struct StateT * slot_2(struct StateT * v38) {
  int v39 = v38->timer;
  int v40 = v38->timer;
  int v48 = v40 + 1;
  v38->timer = v48;
  int * v42 = v38->reg_ready;
  int v51 = v39 + 1;
  v42[15] = v51;
  int * v44 = v38->regs;
  v44[15] = 80;
  struct StateT * v46 = slot_3(v38);
  return v46;
}

struct StateT * slot_7(struct StateT * v395) {
  int v396 = v395->timer;
  int v397 = v395->timer;
  int v531 = v397 + 1;
  v395->timer = v531;
  int * v399 = v395->reg_ready;
  int v400 = v399[11];
  int * v401 = v395->regs;
  int v402 = v401[11];
  int * v403 = v395->cache_tags;
  int v536 = (((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1)) & 1) * 2;
  int v404 = v403[v536];
  int * v405 = v395->cache_tags;
  int v538 = ((((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1)) & 1) * 2) + 1;
  int v406 = v405[v538];
  int * v407 = v395->cache_tags;
  int v540 = 4 + ((((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1)) & 3) * 2);
  int v408 = v407[v540];
  int * v409 = v395->cache_tags;
  int v542 = (4 + ((((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v410 = v409[v542];
  int * v411 = v395->cache_vals;
  bool v543 = !(((~(((v404 ^ ((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1))) | (-(v404 ^ ((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1))))) >> 31)) | (~(((v406 ^ ((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1))) | (-(v406 ^ ((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1))))) >> 31))) == 0);
  int v524;
  if (v543) {
    int * v412 = v395->cache_age;
    int v545 = ((((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1)) & 1) * 2) + ((~(((v406 ^ ((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1))) | (-(v406 ^ ((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1))))) >> 31)) & 1);
    int v413 = v412[v545];
    int * v414 = v395->cache_age;
    int v415 = v414[v536];
    int * v416 = v395->cache_age;
    int v548 = v415 + ((int)((unsigned int)(v415 - v413) >> 31));
    v416[v536] = v548;
    int * v418 = v395->cache_age;
    int v419 = v418[v538];
    int * v420 = v395->cache_age;
    int v551 = v419 + ((int)((unsigned int)(v419 - v413) >> 31));
    v420[v538] = v551;
    int * v422 = v395->cache_age;
    v422[v545] = 0;
    v524 = v545;
  } else {
    int * v425 = v395->cache_age;
    int v555 = (((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1)) & 1) * 2;
    int v426 = v425[v555];
    int * v427 = v395->cache_tags;
    int v428 = v427[v555];
    int * v429 = v395->cache_age;
    int v430 = v429[v538];
    int * v431 = v395->cache_tags;
    int v432 = v431[v538];
    bool v559 = !(((~(((v408 ^ ((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1))) | (-(v408 ^ ((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1))))) >> 31)) | (~(((v410 ^ ((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1))) | (-(v410 ^ ((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1))))) >> 31))) == 0);
    int v496;
    if (v559) {
      int * v433 = v395->cache_age;
      int v561 = (4 + ((((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1)) & 3) * 2)) + ((~(((v410 ^ ((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1))) | (-(v410 ^ ((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1))))) >> 31)) & 1);
      int v434 = v433[v561];
      int * v435 = v395->cache_age;
      int v436 = v435[v540];
      int * v437 = v395->cache_age;
      int v564 = v436 + ((int)((unsigned int)(v436 - v434) >> 31));
      v437[v540] = v564;
      int * v439 = v395->cache_age;
      int v440 = v439[v542];
      int * v441 = v395->cache_age;
      int v567 = v440 + ((int)((unsigned int)(v440 - v434) >> 31));
      v441[v542] = v567;
      int * v443 = v395->cache_age;
      v443[v561] = 0;
      v496 = v561;
    } else {
      int * v446 = v395->cache_age;
      int v571 = 4 + ((((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1)) & 3) * 2);
      int v447 = v446[v571];
      int * v448 = v395->cache_tags;
      int v449 = v448[v571];
      int * v450 = v395->cache_age;
      int v451 = v450[v542];
      int * v452 = v395->cache_tags;
      int v453 = v452[v542];
      int * v454 = v395->cache_dirty;
      int v576 = (4 + ((((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1)) & 3) * 2)) + ((((v447 + ((~(((v449 ^ -1) | (-(v449 ^ -1))) >> 31)) & 2)) - (v451 + ((~(((v453 ^ -1) | (-(v453 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v455 = v454[v576];
      bool v577 = !(v455 == 0);
      if (v577) {
        int * v456 = v395->cache_tags;
        int v457 = v456[v576];
        int * v458 = v395->cache_vals;
        int v580 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1)) & 3) * 2)) + ((((v447 + ((~(((v449 ^ -1) | (-(v449 ^ -1))) >> 31)) & 2)) - (v451 + ((~(((v453 ^ -1) | (-(v453 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v459 = v458[v580];
        int * v460 = v395->cache_vals;
        int v582 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1)) & 3) * 2)) + ((((v447 + ((~(((v449 ^ -1) | (-(v449 ^ -1))) >> 31)) & 2)) - (v451 + ((~(((v453 ^ -1) | (-(v453 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v461 = v460[v582];
        int * v462 = v395->mem;
        int v584 = v457 * 2;
        v462[v584] = v459;
        int * v464 = v395->mem;
        int v587 = (v457 * 2) + 1;
        v464[v587] = v461;
        ;
      } else {
        ;
      }
      int * v469 = v395->mem;
      int v592 = ((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1)) * 2;
      int v470 = v469[v592];
      int * v471 = v395->mem;
      int v594 = (((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1)) * 2) + 1;
      int v472 = v471[v594];
      int * v473 = v395->cache_vals;
      int v596 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1)) & 3) * 2)) + ((((v447 + ((~(((v449 ^ -1) | (-(v449 ^ -1))) >> 31)) & 2)) - (v451 + ((~(((v453 ^ -1) | (-(v453 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v473[v596] = v470;
      int * v475 = v395->cache_vals;
      int v599 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1)) & 3) * 2)) + ((((v447 + ((~(((v449 ^ -1) | (-(v449 ^ -1))) >> 31)) & 2)) - (v451 + ((~(((v453 ^ -1) | (-(v453 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v475[v599] = v472;
      int * v477 = v395->cache_tags;
      int v602 = (int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1);
      v477[v576] = v602;
      int * v479 = v395->cache_dirty;
      v479[v576] = 0;
      int * v481 = v395->cache_age;
      v481[v576] = 1;
      int * v483 = v395->cache_age;
      int v484 = v483[v576];
      int * v485 = v395->cache_age;
      int v486 = v485[v540];
      int * v487 = v395->cache_age;
      int v610 = v486 + ((int)((unsigned int)(v486 - v484) >> 31));
      v487[v540] = v610;
      int * v489 = v395->cache_age;
      int v490 = v489[v542];
      int * v491 = v395->cache_age;
      int v613 = v490 + ((int)((unsigned int)(v490 - v484) >> 31));
      v491[v542] = v613;
      int * v493 = v395->cache_age;
      v493[v576] = 0;
      v496 = v576;
    }
    int * v497 = v395->cache_vals;
    int v616 = v496 * 2;
    int v498 = v497[v616];
    int * v499 = v395->cache_vals;
    int v618 = (v496 * 2) + 1;
    int v500 = v499[v618];
    int * v501 = v395->cache_vals;
    int v620 = (((((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1)) & 1) * 2) + ((((v426 + ((~(((v428 ^ -1) | (-(v428 ^ -1))) >> 31)) & 2)) - (v430 + ((~(((v432 ^ -1) | (-(v432 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v501[v620] = v498;
    int * v503 = v395->cache_vals;
    int v623 = ((((((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1)) & 1) * 2) + ((((v426 + ((~(((v428 ^ -1) | (-(v428 ^ -1))) >> 31)) & 2)) - (v430 + ((~(((v432 ^ -1) | (-(v432 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v503[v623] = v500;
    int * v505 = v395->cache_tags;
    int v626 = ((((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1)) & 1) * 2) + ((((v426 + ((~(((v428 ^ -1) | (-(v428 ^ -1))) >> 31)) & 2)) - (v430 + ((~(((v432 ^ -1) | (-(v432 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v627 = (int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1);
    v505[v626] = v627;
    int * v507 = v395->cache_dirty;
    v507[v626] = 0;
    int * v509 = v395->cache_age;
    v509[v626] = 1;
    int * v511 = v395->cache_age;
    int v512 = v511[v626];
    int * v513 = v395->cache_age;
    int v514 = v513[v536];
    int * v515 = v395->cache_age;
    int v635 = v514 + ((int)((unsigned int)(v514 - v512) >> 31));
    v515[v536] = v635;
    int * v517 = v395->cache_age;
    int v518 = v517[v538];
    int * v519 = v395->cache_age;
    int v638 = v518 + ((int)((unsigned int)(v518 - v512) >> 31));
    v519[v538] = v638;
    int * v521 = v395->cache_age;
    v521[v626] = 0;
    v524 = v626;
  }
  int v641 = (v524 * 2) + (((int)((unsigned int)v402 >> 2)) & 1);
  int v525 = v411[v641];
  int * v526 = v395->reg_ready;
  int v644 = ((v400 + ((v396 - v400) & (~((v396 - v400) >> 31)))) + 1) + ((100 ^ (((~(((v408 ^ ((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1))) | (-(v408 ^ ((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1))))) >> 31)) | (~(((v410 ^ ((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1))) | (-(v410 ^ ((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v404 ^ ((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1))) | (-(v404 ^ ((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1))))) >> 31)) | (~(((v406 ^ ((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1))) | (-(v406 ^ ((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v408 ^ ((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1))) | (-(v408 ^ ((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1))))) >> 31)) | (~(((v410 ^ ((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1))) | (-(v410 ^ ((int)((unsigned int)((int)((unsigned int)v402 >> 2)) >> 1))))) >> 31))) & 104)))));
  v526[12] = v644;
  int * v528 = v395->regs;
  v528[12] = v525;
  return v395;
}

struct StateT * slot_3(struct StateT * v56) {
  int v57 = v56->timer;
  int v58 = v56->timer;
  int v73 = v58 + 1;
  v56->timer = v73;
  int * v60 = v56->reg_ready;
  int v61 = v60[10];
  int * v62 = v56->regs;
  int v63 = v62[10];
  int * v64 = v56->reg_ready;
  int v65 = v64[15];
  int * v66 = v56->regs;
  int v67 = v66[15];
  bool v80 = v63 >= v67;
  struct StateT * v71;
  if (v80) {
    v71 = v56;
  } else {
    struct StateT * v69 = slot_4(v56);
    v71 = v69;
  }
  return v71;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v4 = v2->timer;
  int v12 = v4 + 1;
  v2->timer = v12;
  int * v6 = v2->reg_ready;
  int v15 = v3 + 1;
  v6[13] = v15;
  int * v8 = v2->regs;
  v8[13] = 0;
  struct StateT * v10 = slot_1(v2);
  return v10;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
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
    s1.mem[SECRET_OFFSET+i] = bounded(0, 20);
    s2.mem[SECRET_OFFSET+i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}