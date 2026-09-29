// verify: leak (Eva should report untainted: unknown) [unroll 65]
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

struct StateT * slot_12(struct StateT * v597);
struct StateT * slot_14(struct StateT * v92);
struct StateT * slot_6(struct StateT * v130);
struct StateT * slot_5(struct StateT * v105);
struct StateT * slot_2(struct StateT * v34);
struct StateT * slot_7(struct StateT * v338);
struct StateT * slot_3(struct StateT * v50);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v613);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_8(struct StateT * v363);
struct StateT * slot_4(struct StateT * v66);
struct StateT * slot_13(struct StateT * v634);
struct StateT * slot_9(struct StateT * v571);
struct StateT * slot_11(struct StateT * v639);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v597) {
  int v598 = v597->timer;
  int v606 = v598 + 1;
  v597->timer = v606;
  int * v600 = v597->reg_ready;
  v600[10] = v606;
  int * v602 = v597->regs;
  v602[10] = 0;
  struct StateT * v604 = slot_13(v597);
  return v604;
}

struct StateT * slot_14(struct StateT * v92) {
  int v93 = v92->timer;
  int v100 = v93 + 1;
  v92->timer = v100;
  int * v95 = v92->reg_ready;
  v95[10] = v100;
  int * v97 = v92->regs;
  v97[10] = 1;
  return v92;
}

struct StateT * slot_6(struct StateT * v130) {
  int v131 = v130->timer;
  int v243 = v131 + 1;
  v130->timer = v243;
  int * v133 = v130->reg_ready;
  int v134 = v133[5];
  int * v135 = v130->regs;
  int v136 = v135[5];
  int * v137 = v130->cache_tags;
  int v248 = (((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1)) & 1) * 2;
  int v138 = v137[v248];
  int v249 = ((((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1)) & 1) * 2) + 1;
  int v139 = v137[v249];
  int v250 = 4 + ((((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1)) & 3) * 2);
  int v140 = v137[v250];
  int v251 = (4 + ((((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v141 = v137[v251];
  int * v142 = v130->cache_vals;
  bool v252 = !(((~(((v138 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))) | (-(v138 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))))) >> 31)) | (~(((v139 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))) | (-(v139 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))))) >> 31))) == 0);
  int v235;
  if (v252) {
    int * v143 = v130->cache_age;
    int v254 = ((((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1)) & 1) * 2) + ((~(((v139 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))) | (-(v139 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))))) >> 31)) & 1);
    int v144 = v143[v254];
    int v145 = v143[v248];
    int v255 = v145 + ((int)((unsigned int)(v145 - v144) >> 31));
    v143[v248] = v255;
    int * v147 = v130->cache_age;
    int v148 = v147[v249];
    int v257 = v148 + ((int)((unsigned int)(v148 - v144) >> 31));
    v147[v249] = v257;
    int * v150 = v130->cache_age;
    v150[v254] = 0;
    v235 = v254;
  } else {
    int * v153 = v130->cache_age;
    int v261 = (((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1)) & 1) * 2;
    int v154 = v153[v261];
    int * v155 = v130->cache_tags;
    int v156 = v155[v261];
    int v157 = v153[v249];
    int v158 = v155[v249];
    bool v263 = !(((~(((v140 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))) | (-(v140 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))))) >> 31)) | (~(((v141 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))) | (-(v141 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))))) >> 31))) == 0);
    int v212;
    if (v263) {
      int * v159 = v130->cache_age;
      int v265 = (4 + ((((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1)) & 3) * 2)) + ((~(((v141 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))) | (-(v141 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))))) >> 31)) & 1);
      int v160 = v159[v265];
      int v161 = v159[v250];
      int v266 = v161 + ((int)((unsigned int)(v161 - v160) >> 31));
      v159[v250] = v266;
      int * v163 = v130->cache_age;
      int v164 = v163[v251];
      int v268 = v164 + ((int)((unsigned int)(v164 - v160) >> 31));
      v163[v251] = v268;
      int * v166 = v130->cache_age;
      v166[v265] = 0;
      v212 = v265;
    } else {
      int * v169 = v130->cache_age;
      int v272 = 4 + ((((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1)) & 3) * 2);
      int v170 = v169[v272];
      int * v171 = v130->cache_tags;
      int v172 = v171[v272];
      int v173 = v169[v251];
      int v174 = v171[v251];
      int * v175 = v130->cache_dirty;
      int v275 = (4 + ((((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1)) & 3) * 2)) + ((((v170 + ((~(((v172 ^ -1) | (-(v172 ^ -1))) >> 31)) & 2)) - (v173 + ((~(((v174 ^ -1) | (-(v174 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v176 = v175[v275];
      bool v276 = !(v176 == 0);
      if (v276) {
        int * v177 = v130->cache_tags;
        int v178 = v177[v275];
        int * v179 = v130->cache_vals;
        int v279 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1)) & 3) * 2)) + ((((v170 + ((~(((v172 ^ -1) | (-(v172 ^ -1))) >> 31)) & 2)) - (v173 + ((~(((v174 ^ -1) | (-(v174 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v180 = v179[v279];
        int v280 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1)) & 3) * 2)) + ((((v170 + ((~(((v172 ^ -1) | (-(v172 ^ -1))) >> 31)) & 2)) - (v173 + ((~(((v174 ^ -1) | (-(v174 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v181 = v179[v280];
        int * v182 = v130->mem;
        int v282 = v178 * 2;
        v182[v282] = v180;
        int * v184 = v130->mem;
        int v285 = (v178 * 2) + 1;
        v184[v285] = v181;
        ;
      } else {
        ;
      }
      int * v189 = v130->mem;
      int v290 = ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1)) * 2;
      int v190 = v189[v290];
      int v291 = (((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1)) * 2) + 1;
      int v191 = v189[v291];
      int * v192 = v130->cache_vals;
      int v293 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1)) & 3) * 2)) + ((((v170 + ((~(((v172 ^ -1) | (-(v172 ^ -1))) >> 31)) & 2)) - (v173 + ((~(((v174 ^ -1) | (-(v174 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v192[v293] = v190;
      int * v194 = v130->cache_vals;
      int v296 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1)) & 3) * 2)) + ((((v170 + ((~(((v172 ^ -1) | (-(v172 ^ -1))) >> 31)) & 2)) - (v173 + ((~(((v174 ^ -1) | (-(v174 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v194[v296] = v191;
      int * v196 = v130->cache_tags;
      int v299 = (int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1);
      v196[v275] = v299;
      int * v198 = v130->cache_dirty;
      v198[v275] = 0;
      int * v200 = v130->cache_age;
      v200[v275] = 1;
      int * v202 = v130->cache_age;
      int v203 = v202[v275];
      int v204 = v202[v250];
      int v305 = v204 + ((int)((unsigned int)(v204 - v203) >> 31));
      v202[v250] = v305;
      int * v206 = v130->cache_age;
      int v207 = v206[v251];
      int v307 = v207 + ((int)((unsigned int)(v207 - v203) >> 31));
      v206[v251] = v307;
      int * v209 = v130->cache_age;
      v209[v275] = 0;
      v212 = v275;
    }
    int * v213 = v130->cache_vals;
    int v310 = v212 * 2;
    int v214 = v213[v310];
    int v311 = (v212 * 2) + 1;
    int v215 = v213[v311];
    int v312 = (((((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1)) & 1) * 2) + ((((v154 + ((~(((v156 ^ -1) | (-(v156 ^ -1))) >> 31)) & 2)) - (v157 + ((~(((v158 ^ -1) | (-(v158 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v213[v312] = v214;
    int * v217 = v130->cache_vals;
    int v315 = ((((((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1)) & 1) * 2) + ((((v154 + ((~(((v156 ^ -1) | (-(v156 ^ -1))) >> 31)) & 2)) - (v157 + ((~(((v158 ^ -1) | (-(v158 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v217[v315] = v215;
    int * v219 = v130->cache_tags;
    int v318 = ((((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1)) & 1) * 2) + ((((v154 + ((~(((v156 ^ -1) | (-(v156 ^ -1))) >> 31)) & 2)) - (v157 + ((~(((v158 ^ -1) | (-(v158 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v319 = (int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1);
    v219[v318] = v319;
    int * v221 = v130->cache_dirty;
    v221[v318] = 0;
    int * v223 = v130->cache_age;
    v223[v318] = 1;
    int * v225 = v130->cache_age;
    int v226 = v225[v318];
    int v227 = v225[v248];
    int v325 = v227 + ((int)((unsigned int)(v227 - v226) >> 31));
    v225[v248] = v325;
    int * v229 = v130->cache_age;
    int v230 = v229[v249];
    int v327 = v230 + ((int)((unsigned int)(v230 - v226) >> 31));
    v229[v249] = v327;
    int * v232 = v130->cache_age;
    v232[v318] = 0;
    v235 = v318;
  }
  int v330 = (v235 * 2) + (((int)((unsigned int)v136 >> 2)) & 1);
  int v236 = v142[v330];
  int * v237 = v130->reg_ready;
  int v333 = ((v134 + ((v131 - v134) & (~((v131 - v134) >> 31)))) + 1) + ((100 ^ (((~(((v140 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))) | (-(v140 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))))) >> 31)) | (~(((v141 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))) | (-(v141 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v138 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))) | (-(v138 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))))) >> 31)) | (~(((v139 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))) | (-(v139 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v140 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))) | (-(v140 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))))) >> 31)) | (~(((v141 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))) | (-(v141 ^ ((int)((unsigned int)((int)((unsigned int)v136 >> 2)) >> 1))))) >> 31))) & 104)))));
  v237[10] = v333;
  int * v239 = v130->regs;
  v239[10] = v236;
  struct StateT * v241 = slot_7(v130);
  return v241;
}

struct StateT * slot_5(struct StateT * v105) {
  int v106 = v105->timer;
  int v119 = v106 + 1;
  v105->timer = v119;
  int * v108 = v105->reg_ready;
  int v109 = v108[12];
  int * v110 = v105->regs;
  int v111 = v110[12];
  int v112 = v108[14];
  int v113 = v110[14];
  int v125 = (v112 + (((v109 + ((v106 - v109) & (~((v106 - v109) >> 31)))) - v112) & (~(((v109 + ((v106 - v109) & (~((v106 - v109) >> 31)))) - v112) >> 31)))) + 1;
  v108[5] = v125;
  int * v115 = v105->regs;
  int v127 = v111 + v113;
  v115[5] = v127;
  struct StateT * v117 = slot_6(v105);
  return v117;
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

struct StateT * slot_7(struct StateT * v338) {
  int v339 = v338->timer;
  int v352 = v339 + 1;
  v338->timer = v352;
  int * v341 = v338->reg_ready;
  int v342 = v341[13];
  int * v343 = v338->regs;
  int v344 = v343[13];
  int v345 = v341[14];
  int v346 = v343[14];
  int v358 = (v345 + (((v342 + ((v339 - v342) & (~((v339 - v342) >> 31)))) - v345) & (~(((v342 + ((v339 - v342) & (~((v339 - v342) >> 31)))) - v345) >> 31)))) + 1;
  v341[6] = v358;
  int * v348 = v338->regs;
  int v360 = v344 + v346;
  v348[6] = v360;
  struct StateT * v350 = slot_8(v338);
  return v350;
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

struct StateT * slot_10(struct StateT * v613) {
  int v614 = v613->timer;
  int v625 = v614 + 1;
  v613->timer = v625;
  int * v616 = v613->reg_ready;
  int v617 = v616[14];
  int * v618 = v613->regs;
  int v619 = v618[14];
  int v629 = (v617 + ((v614 - v617) & (~((v614 - v617) >> 31)))) + 1;
  v616[14] = v629;
  int * v621 = v613->regs;
  int v631 = v619 + 4;
  v621[14] = v631;
  struct StateT * v623 = slot_11(v613);
  return v623;
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

struct StateT * slot_8(struct StateT * v363) {
  int v364 = v363->timer;
  int v476 = v364 + 1;
  v363->timer = v476;
  int * v366 = v363->reg_ready;
  int v367 = v366[6];
  int * v368 = v363->regs;
  int v369 = v368[6];
  int * v370 = v363->cache_tags;
  int v481 = (((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1)) & 1) * 2;
  int v371 = v370[v481];
  int v482 = ((((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1)) & 1) * 2) + 1;
  int v372 = v370[v482];
  int v483 = 4 + ((((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1)) & 3) * 2);
  int v373 = v370[v483];
  int v484 = (4 + ((((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v374 = v370[v484];
  int * v375 = v363->cache_vals;
  bool v485 = !(((~(((v371 ^ ((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1))) | (-(v371 ^ ((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1))))) >> 31)) | (~(((v372 ^ ((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1))) | (-(v372 ^ ((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1))))) >> 31))) == 0);
  int v468;
  if (v485) {
    int * v376 = v363->cache_age;
    int v487 = ((((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1)) & 1) * 2) + ((~(((v372 ^ ((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1))) | (-(v372 ^ ((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1))))) >> 31)) & 1);
    int v377 = v376[v487];
    int v378 = v376[v481];
    int v488 = v378 + ((int)((unsigned int)(v378 - v377) >> 31));
    v376[v481] = v488;
    int * v380 = v363->cache_age;
    int v381 = v380[v482];
    int v490 = v381 + ((int)((unsigned int)(v381 - v377) >> 31));
    v380[v482] = v490;
    int * v383 = v363->cache_age;
    v383[v487] = 0;
    v468 = v487;
  } else {
    int * v386 = v363->cache_age;
    int v494 = (((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1)) & 1) * 2;
    int v387 = v386[v494];
    int * v388 = v363->cache_tags;
    int v389 = v388[v494];
    int v390 = v386[v482];
    int v391 = v388[v482];
    bool v496 = !(((~(((v373 ^ ((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1))) | (-(v373 ^ ((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1))))) >> 31)) | (~(((v374 ^ ((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1))) | (-(v374 ^ ((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1))))) >> 31))) == 0);
    int v445;
    if (v496) {
      int * v392 = v363->cache_age;
      int v498 = (4 + ((((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1)) & 3) * 2)) + ((~(((v374 ^ ((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1))) | (-(v374 ^ ((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1))))) >> 31)) & 1);
      int v393 = v392[v498];
      int v394 = v392[v483];
      int v499 = v394 + ((int)((unsigned int)(v394 - v393) >> 31));
      v392[v483] = v499;
      int * v396 = v363->cache_age;
      int v397 = v396[v484];
      int v501 = v397 + ((int)((unsigned int)(v397 - v393) >> 31));
      v396[v484] = v501;
      int * v399 = v363->cache_age;
      v399[v498] = 0;
      v445 = v498;
    } else {
      int * v402 = v363->cache_age;
      int v505 = 4 + ((((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1)) & 3) * 2);
      int v403 = v402[v505];
      int * v404 = v363->cache_tags;
      int v405 = v404[v505];
      int v406 = v402[v484];
      int v407 = v404[v484];
      int * v408 = v363->cache_dirty;
      int v508 = (4 + ((((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1)) & 3) * 2)) + ((((v403 + ((~(((v405 ^ -1) | (-(v405 ^ -1))) >> 31)) & 2)) - (v406 + ((~(((v407 ^ -1) | (-(v407 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v409 = v408[v508];
      bool v509 = !(v409 == 0);
      if (v509) {
        int * v410 = v363->cache_tags;
        int v411 = v410[v508];
        int * v412 = v363->cache_vals;
        int v512 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1)) & 3) * 2)) + ((((v403 + ((~(((v405 ^ -1) | (-(v405 ^ -1))) >> 31)) & 2)) - (v406 + ((~(((v407 ^ -1) | (-(v407 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v413 = v412[v512];
        int v513 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1)) & 3) * 2)) + ((((v403 + ((~(((v405 ^ -1) | (-(v405 ^ -1))) >> 31)) & 2)) - (v406 + ((~(((v407 ^ -1) | (-(v407 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v414 = v412[v513];
        int * v415 = v363->mem;
        int v515 = v411 * 2;
        v415[v515] = v413;
        int * v417 = v363->mem;
        int v518 = (v411 * 2) + 1;
        v417[v518] = v414;
        ;
      } else {
        ;
      }
      int * v422 = v363->mem;
      int v523 = ((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1)) * 2;
      int v423 = v422[v523];
      int v524 = (((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1)) * 2) + 1;
      int v424 = v422[v524];
      int * v425 = v363->cache_vals;
      int v526 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1)) & 3) * 2)) + ((((v403 + ((~(((v405 ^ -1) | (-(v405 ^ -1))) >> 31)) & 2)) - (v406 + ((~(((v407 ^ -1) | (-(v407 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v425[v526] = v423;
      int * v427 = v363->cache_vals;
      int v529 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1)) & 3) * 2)) + ((((v403 + ((~(((v405 ^ -1) | (-(v405 ^ -1))) >> 31)) & 2)) - (v406 + ((~(((v407 ^ -1) | (-(v407 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v427[v529] = v424;
      int * v429 = v363->cache_tags;
      int v532 = (int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1);
      v429[v508] = v532;
      int * v431 = v363->cache_dirty;
      v431[v508] = 0;
      int * v433 = v363->cache_age;
      v433[v508] = 1;
      int * v435 = v363->cache_age;
      int v436 = v435[v508];
      int v437 = v435[v483];
      int v538 = v437 + ((int)((unsigned int)(v437 - v436) >> 31));
      v435[v483] = v538;
      int * v439 = v363->cache_age;
      int v440 = v439[v484];
      int v540 = v440 + ((int)((unsigned int)(v440 - v436) >> 31));
      v439[v484] = v540;
      int * v442 = v363->cache_age;
      v442[v508] = 0;
      v445 = v508;
    }
    int * v446 = v363->cache_vals;
    int v543 = v445 * 2;
    int v447 = v446[v543];
    int v544 = (v445 * 2) + 1;
    int v448 = v446[v544];
    int v545 = (((((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1)) & 1) * 2) + ((((v387 + ((~(((v389 ^ -1) | (-(v389 ^ -1))) >> 31)) & 2)) - (v390 + ((~(((v391 ^ -1) | (-(v391 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v446[v545] = v447;
    int * v450 = v363->cache_vals;
    int v548 = ((((((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1)) & 1) * 2) + ((((v387 + ((~(((v389 ^ -1) | (-(v389 ^ -1))) >> 31)) & 2)) - (v390 + ((~(((v391 ^ -1) | (-(v391 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v450[v548] = v448;
    int * v452 = v363->cache_tags;
    int v551 = ((((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1)) & 1) * 2) + ((((v387 + ((~(((v389 ^ -1) | (-(v389 ^ -1))) >> 31)) & 2)) - (v390 + ((~(((v391 ^ -1) | (-(v391 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v552 = (int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1);
    v452[v551] = v552;
    int * v454 = v363->cache_dirty;
    v454[v551] = 0;
    int * v456 = v363->cache_age;
    v456[v551] = 1;
    int * v458 = v363->cache_age;
    int v459 = v458[v551];
    int v460 = v458[v481];
    int v558 = v460 + ((int)((unsigned int)(v460 - v459) >> 31));
    v458[v481] = v558;
    int * v462 = v363->cache_age;
    int v463 = v462[v482];
    int v560 = v463 + ((int)((unsigned int)(v463 - v459) >> 31));
    v462[v482] = v560;
    int * v465 = v363->cache_age;
    v465[v551] = 0;
    v468 = v551;
  }
  int v563 = (v468 * 2) + (((int)((unsigned int)v369 >> 2)) & 1);
  int v469 = v375[v563];
  int * v470 = v363->reg_ready;
  int v566 = ((v367 + ((v364 - v367) & (~((v364 - v367) >> 31)))) + 1) + ((100 ^ (((~(((v373 ^ ((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1))) | (-(v373 ^ ((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1))))) >> 31)) | (~(((v374 ^ ((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1))) | (-(v374 ^ ((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v371 ^ ((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1))) | (-(v371 ^ ((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1))))) >> 31)) | (~(((v372 ^ ((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1))) | (-(v372 ^ ((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v373 ^ ((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1))) | (-(v373 ^ ((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1))))) >> 31)) | (~(((v374 ^ ((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1))) | (-(v374 ^ ((int)((unsigned int)((int)((unsigned int)v369 >> 2)) >> 1))))) >> 31))) & 104)))));
  v470[11] = v566;
  int * v472 = v363->regs;
  v472[11] = v469;
  struct StateT * v474 = slot_9(v363);
  return v474;
}

struct StateT * slot_4(struct StateT * v66) {
  int v67 = v66->timer;
  int v81 = v67 + 1;
  v66->timer = v81;
  int * v69 = v66->reg_ready;
  int * v71 = v66->regs;
  int v72 = v71[14];
  int v74 = v71[15];
  bool v86 = v72 >= v74;
  struct StateT * v79;
  if (v86) {
    struct StateT * v75 = slot_14(v66);
    v79 = v75;
  } else {
    struct StateT * v77 = slot_5(v66);
    v79 = v77;
  }
  return v79;
}

struct StateT * slot_13(struct StateT * v634) {
  int v635 = v634->timer;
  int v638 = v635 + 1;
  v634->timer = v638;
  return v634;
}

struct StateT * slot_9(struct StateT * v571) {
  int v572 = v571->timer;
  int v586 = v572 + 1;
  v571->timer = v586;
  int * v574 = v571->reg_ready;
  int * v576 = v571->regs;
  int v577 = v576[10];
  int v579 = v576[11];
  bool v591 = !(v577 == v579);
  struct StateT * v584;
  if (v591) {
    struct StateT * v580 = slot_12(v571);
    v584 = v580;
  } else {
    struct StateT * v582 = slot_10(v571);
    v584 = v582;
  }
  return v584;
}

struct StateT * slot_11(struct StateT * v639) {
  int v640 = v639->timer;
  int v644 = v640 + 1;
  v639->timer = v644;
  struct StateT * v642 = slot_4(v639);
  return v642;
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
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}