// verify: clean (Eva should report untainted_timer: Valid) [unroll 65]
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

struct StateT * slot_12(struct StateT * v650);
struct StateT * slot_14(struct StateT * v108);
struct StateT * slot_6(struct StateT * v135);
struct StateT * slot_5(struct StateT * v82);
struct StateT * slot_2(struct StateT * v34);
struct StateT * slot_7(struct StateT * v160);
struct StateT * slot_3(struct StateT * v50);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v601);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_8(struct StateT * v368);
struct StateT * slot_4(struct StateT * v66);
struct StateT * slot_13(struct StateT * v671);
struct StateT * slot_9(struct StateT * v393);
struct StateT * slot_11(struct StateT * v626);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v650) {
  int v651 = v650->timer;
  int v662 = v651 + 1;
  v650->timer = v662;
  int * v653 = v650->reg_ready;
  int v654 = v653[14];
  int * v655 = v650->regs;
  int v656 = v655[14];
  int v666 = (v654 + ((v651 - v654) & (~((v651 - v654) >> 31)))) + 1;
  v653[14] = v666;
  int * v658 = v650->regs;
  int v668 = v656 + 4;
  v658[14] = v668;
  struct StateT * v660 = slot_13(v650);
  return v660;
}

struct StateT * slot_14(struct StateT * v108) {
  int v109 = v108->timer;
  int v123 = v109 + 1;
  v108->timer = v123;
  int * v111 = v108->reg_ready;
  int v112 = v111[5];
  int * v113 = v108->regs;
  int v114 = v113[5];
  bool v127 = (v114 ^ -2147483648) < -2147483647;
  int v117;
  if (v127) {
    v117 = 1;
  } else {
    v117 = 0;
  }
  int * v118 = v108->reg_ready;
  int v132 = (v112 + ((v109 - v112) & (~((v109 - v112) >> 31)))) + 1;
  v118[11] = v132;
  int * v120 = v108->regs;
  v120[11] = v117;
  return v108;
}

struct StateT * slot_6(struct StateT * v135) {
  int v136 = v135->timer;
  int v149 = v136 + 1;
  v135->timer = v149;
  int * v138 = v135->reg_ready;
  int v139 = v138[12];
  int * v140 = v135->regs;
  int v141 = v140[12];
  int v142 = v138[14];
  int v143 = v140[14];
  int v155 = (v142 + (((v139 + ((v136 - v139) & (~((v136 - v139) >> 31)))) - v142) & (~(((v139 + ((v136 - v139) & (~((v136 - v139) >> 31)))) - v142) >> 31)))) + 1;
  v138[6] = v155;
  int * v145 = v135->regs;
  int v157 = v141 + v143;
  v145[6] = v157;
  struct StateT * v147 = slot_7(v135);
  return v147;
}

struct StateT * slot_5(struct StateT * v82) {
  int v83 = v82->timer;
  int v97 = v83 + 1;
  v82->timer = v97;
  int * v85 = v82->reg_ready;
  int * v87 = v82->regs;
  int v88 = v87[14];
  int v90 = v87[15];
  bool v102 = v88 >= v90;
  struct StateT * v95;
  if (v102) {
    struct StateT * v91 = slot_14(v82);
    v95 = v91;
  } else {
    struct StateT * v93 = slot_6(v82);
    v95 = v93;
  }
  return v95;
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

struct StateT * slot_7(struct StateT * v160) {
  int v161 = v160->timer;
  int v273 = v161 + 1;
  v160->timer = v273;
  int * v163 = v160->reg_ready;
  int v164 = v163[6];
  int * v165 = v160->regs;
  int v166 = v165[6];
  int * v167 = v160->cache_tags;
  int v278 = (((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1)) & 1) * 2;
  int v168 = v167[v278];
  int v279 = ((((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1)) & 1) * 2) + 1;
  int v169 = v167[v279];
  int v280 = 4 + ((((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1)) & 3) * 2);
  int v170 = v167[v280];
  int v281 = (4 + ((((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v171 = v167[v281];
  int * v172 = v160->cache_vals;
  bool v282 = !(((~(((v168 ^ ((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1))) | (-(v168 ^ ((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1))))) >> 31)) | (~(((v169 ^ ((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1))) | (-(v169 ^ ((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1))))) >> 31))) == 0);
  int v265;
  if (v282) {
    int * v173 = v160->cache_age;
    int v284 = ((((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1)) & 1) * 2) + ((~(((v169 ^ ((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1))) | (-(v169 ^ ((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1))))) >> 31)) & 1);
    int v174 = v173[v284];
    int v175 = v173[v278];
    int v285 = v175 + ((int)((unsigned int)(v175 - v174) >> 31));
    v173[v278] = v285;
    int * v177 = v160->cache_age;
    int v178 = v177[v279];
    int v287 = v178 + ((int)((unsigned int)(v178 - v174) >> 31));
    v177[v279] = v287;
    int * v180 = v160->cache_age;
    v180[v284] = 0;
    v265 = v284;
  } else {
    int * v183 = v160->cache_age;
    int v291 = (((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1)) & 1) * 2;
    int v184 = v183[v291];
    int * v185 = v160->cache_tags;
    int v186 = v185[v291];
    int v187 = v183[v279];
    int v188 = v185[v279];
    bool v293 = !(((~(((v170 ^ ((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1))) | (-(v170 ^ ((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1))))) >> 31)) | (~(((v171 ^ ((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1))) | (-(v171 ^ ((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1))))) >> 31))) == 0);
    int v242;
    if (v293) {
      int * v189 = v160->cache_age;
      int v295 = (4 + ((((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1)) & 3) * 2)) + ((~(((v171 ^ ((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1))) | (-(v171 ^ ((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1))))) >> 31)) & 1);
      int v190 = v189[v295];
      int v191 = v189[v280];
      int v296 = v191 + ((int)((unsigned int)(v191 - v190) >> 31));
      v189[v280] = v296;
      int * v193 = v160->cache_age;
      int v194 = v193[v281];
      int v298 = v194 + ((int)((unsigned int)(v194 - v190) >> 31));
      v193[v281] = v298;
      int * v196 = v160->cache_age;
      v196[v295] = 0;
      v242 = v295;
    } else {
      int * v199 = v160->cache_age;
      int v302 = 4 + ((((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1)) & 3) * 2);
      int v200 = v199[v302];
      int * v201 = v160->cache_tags;
      int v202 = v201[v302];
      int v203 = v199[v281];
      int v204 = v201[v281];
      int * v205 = v160->cache_dirty;
      int v305 = (4 + ((((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1)) & 3) * 2)) + ((((v200 + ((~(((v202 ^ -1) | (-(v202 ^ -1))) >> 31)) & 2)) - (v203 + ((~(((v204 ^ -1) | (-(v204 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v206 = v205[v305];
      bool v306 = !(v206 == 0);
      if (v306) {
        int * v207 = v160->cache_tags;
        int v208 = v207[v305];
        int * v209 = v160->cache_vals;
        int v309 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1)) & 3) * 2)) + ((((v200 + ((~(((v202 ^ -1) | (-(v202 ^ -1))) >> 31)) & 2)) - (v203 + ((~(((v204 ^ -1) | (-(v204 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v210 = v209[v309];
        int v310 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1)) & 3) * 2)) + ((((v200 + ((~(((v202 ^ -1) | (-(v202 ^ -1))) >> 31)) & 2)) - (v203 + ((~(((v204 ^ -1) | (-(v204 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v211 = v209[v310];
        int * v212 = v160->mem;
        int v312 = v208 * 2;
        v212[v312] = v210;
        int * v214 = v160->mem;
        int v315 = (v208 * 2) + 1;
        v214[v315] = v211;
        ;
      } else {
        ;
      }
      int * v219 = v160->mem;
      int v320 = ((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1)) * 2;
      int v220 = v219[v320];
      int v321 = (((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1)) * 2) + 1;
      int v221 = v219[v321];
      int * v222 = v160->cache_vals;
      int v323 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1)) & 3) * 2)) + ((((v200 + ((~(((v202 ^ -1) | (-(v202 ^ -1))) >> 31)) & 2)) - (v203 + ((~(((v204 ^ -1) | (-(v204 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v222[v323] = v220;
      int * v224 = v160->cache_vals;
      int v326 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1)) & 3) * 2)) + ((((v200 + ((~(((v202 ^ -1) | (-(v202 ^ -1))) >> 31)) & 2)) - (v203 + ((~(((v204 ^ -1) | (-(v204 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v224[v326] = v221;
      int * v226 = v160->cache_tags;
      int v329 = (int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1);
      v226[v305] = v329;
      int * v228 = v160->cache_dirty;
      v228[v305] = 0;
      int * v230 = v160->cache_age;
      v230[v305] = 1;
      int * v232 = v160->cache_age;
      int v233 = v232[v305];
      int v234 = v232[v280];
      int v335 = v234 + ((int)((unsigned int)(v234 - v233) >> 31));
      v232[v280] = v335;
      int * v236 = v160->cache_age;
      int v237 = v236[v281];
      int v337 = v237 + ((int)((unsigned int)(v237 - v233) >> 31));
      v236[v281] = v337;
      int * v239 = v160->cache_age;
      v239[v305] = 0;
      v242 = v305;
    }
    int * v243 = v160->cache_vals;
    int v340 = v242 * 2;
    int v244 = v243[v340];
    int v341 = (v242 * 2) + 1;
    int v245 = v243[v341];
    int v342 = (((((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1)) & 1) * 2) + ((((v184 + ((~(((v186 ^ -1) | (-(v186 ^ -1))) >> 31)) & 2)) - (v187 + ((~(((v188 ^ -1) | (-(v188 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v243[v342] = v244;
    int * v247 = v160->cache_vals;
    int v345 = ((((((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1)) & 1) * 2) + ((((v184 + ((~(((v186 ^ -1) | (-(v186 ^ -1))) >> 31)) & 2)) - (v187 + ((~(((v188 ^ -1) | (-(v188 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v247[v345] = v245;
    int * v249 = v160->cache_tags;
    int v348 = ((((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1)) & 1) * 2) + ((((v184 + ((~(((v186 ^ -1) | (-(v186 ^ -1))) >> 31)) & 2)) - (v187 + ((~(((v188 ^ -1) | (-(v188 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v349 = (int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1);
    v249[v348] = v349;
    int * v251 = v160->cache_dirty;
    v251[v348] = 0;
    int * v253 = v160->cache_age;
    v253[v348] = 1;
    int * v255 = v160->cache_age;
    int v256 = v255[v348];
    int v257 = v255[v278];
    int v355 = v257 + ((int)((unsigned int)(v257 - v256) >> 31));
    v255[v278] = v355;
    int * v259 = v160->cache_age;
    int v260 = v259[v279];
    int v357 = v260 + ((int)((unsigned int)(v260 - v256) >> 31));
    v259[v279] = v357;
    int * v262 = v160->cache_age;
    v262[v348] = 0;
    v265 = v348;
  }
  int v360 = (v265 * 2) + (((int)((unsigned int)v166 >> 2)) & 1);
  int v266 = v172[v360];
  int * v267 = v160->reg_ready;
  int v363 = ((v164 + ((v161 - v164) & (~((v161 - v164) >> 31)))) + 1) + ((100 ^ (((~(((v170 ^ ((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1))) | (-(v170 ^ ((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1))))) >> 31)) | (~(((v171 ^ ((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1))) | (-(v171 ^ ((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v168 ^ ((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1))) | (-(v168 ^ ((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1))))) >> 31)) | (~(((v169 ^ ((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1))) | (-(v169 ^ ((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v170 ^ ((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1))) | (-(v170 ^ ((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1))))) >> 31)) | (~(((v171 ^ ((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1))) | (-(v171 ^ ((int)((unsigned int)((int)((unsigned int)v166 >> 2)) >> 1))))) >> 31))) & 104)))));
  v267[7] = v363;
  int * v269 = v160->regs;
  v269[7] = v266;
  struct StateT * v271 = slot_8(v160);
  return v271;
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
  int v679 = v1->timer;
  int * v680 = v1->reg_ready;
  int v681 = v680[0];
  int v812 = v681 + ((v679 - v681) & (~((v679 - v681) >> 31)));
  v1->timer = v812;
  int v683 = v1->timer;
  int * v684 = v1->reg_ready;
  int v685 = v684[1];
  int v815 = v685 + ((v683 - v685) & (~((v683 - v685) >> 31)));
  v1->timer = v815;
  int v687 = v1->timer;
  int * v688 = v1->reg_ready;
  int v689 = v688[2];
  int v818 = v689 + ((v687 - v689) & (~((v687 - v689) >> 31)));
  v1->timer = v818;
  int v691 = v1->timer;
  int * v692 = v1->reg_ready;
  int v693 = v692[3];
  int v821 = v693 + ((v691 - v693) & (~((v691 - v693) >> 31)));
  v1->timer = v821;
  int v695 = v1->timer;
  int * v696 = v1->reg_ready;
  int v697 = v696[4];
  int v824 = v697 + ((v695 - v697) & (~((v695 - v697) >> 31)));
  v1->timer = v824;
  int v699 = v1->timer;
  int * v700 = v1->reg_ready;
  int v701 = v700[5];
  int v827 = v701 + ((v699 - v701) & (~((v699 - v701) >> 31)));
  v1->timer = v827;
  int v703 = v1->timer;
  int * v704 = v1->reg_ready;
  int v705 = v704[6];
  int v830 = v705 + ((v703 - v705) & (~((v703 - v705) >> 31)));
  v1->timer = v830;
  int v707 = v1->timer;
  int * v708 = v1->reg_ready;
  int v709 = v708[7];
  int v833 = v709 + ((v707 - v709) & (~((v707 - v709) >> 31)));
  v1->timer = v833;
  int v711 = v1->timer;
  int * v712 = v1->reg_ready;
  int v713 = v712[8];
  int v836 = v713 + ((v711 - v713) & (~((v711 - v713) >> 31)));
  v1->timer = v836;
  int v715 = v1->timer;
  int * v716 = v1->reg_ready;
  int v717 = v716[9];
  int v839 = v717 + ((v715 - v717) & (~((v715 - v717) >> 31)));
  v1->timer = v839;
  int v719 = v1->timer;
  int * v720 = v1->reg_ready;
  int v721 = v720[10];
  int v842 = v721 + ((v719 - v721) & (~((v719 - v721) >> 31)));
  v1->timer = v842;
  int v723 = v1->timer;
  int * v724 = v1->reg_ready;
  int v725 = v724[11];
  int v845 = v725 + ((v723 - v725) & (~((v723 - v725) >> 31)));
  v1->timer = v845;
  int v727 = v1->timer;
  int * v728 = v1->reg_ready;
  int v729 = v728[12];
  int v848 = v729 + ((v727 - v729) & (~((v727 - v729) >> 31)));
  v1->timer = v848;
  int v731 = v1->timer;
  int * v732 = v1->reg_ready;
  int v733 = v732[13];
  int v851 = v733 + ((v731 - v733) & (~((v731 - v733) >> 31)));
  v1->timer = v851;
  int v735 = v1->timer;
  int * v736 = v1->reg_ready;
  int v737 = v736[14];
  int v854 = v737 + ((v735 - v737) & (~((v735 - v737) >> 31)));
  v1->timer = v854;
  int v739 = v1->timer;
  int * v740 = v1->reg_ready;
  int v741 = v740[15];
  int v857 = v741 + ((v739 - v741) & (~((v739 - v741) >> 31)));
  v1->timer = v857;
  int v743 = v1->timer;
  int * v744 = v1->reg_ready;
  int v745 = v744[16];
  int v860 = v745 + ((v743 - v745) & (~((v743 - v745) >> 31)));
  v1->timer = v860;
  int v747 = v1->timer;
  int * v748 = v1->reg_ready;
  int v749 = v748[17];
  int v863 = v749 + ((v747 - v749) & (~((v747 - v749) >> 31)));
  v1->timer = v863;
  int v751 = v1->timer;
  int * v752 = v1->reg_ready;
  int v753 = v752[18];
  int v866 = v753 + ((v751 - v753) & (~((v751 - v753) >> 31)));
  v1->timer = v866;
  int v755 = v1->timer;
  int * v756 = v1->reg_ready;
  int v757 = v756[19];
  int v869 = v757 + ((v755 - v757) & (~((v755 - v757) >> 31)));
  v1->timer = v869;
  int v759 = v1->timer;
  int * v760 = v1->reg_ready;
  int v761 = v760[20];
  int v872 = v761 + ((v759 - v761) & (~((v759 - v761) >> 31)));
  v1->timer = v872;
  int v763 = v1->timer;
  int * v764 = v1->reg_ready;
  int v765 = v764[21];
  int v875 = v765 + ((v763 - v765) & (~((v763 - v765) >> 31)));
  v1->timer = v875;
  int v767 = v1->timer;
  int * v768 = v1->reg_ready;
  int v769 = v768[22];
  int v878 = v769 + ((v767 - v769) & (~((v767 - v769) >> 31)));
  v1->timer = v878;
  int v771 = v1->timer;
  int * v772 = v1->reg_ready;
  int v773 = v772[23];
  int v881 = v773 + ((v771 - v773) & (~((v771 - v773) >> 31)));
  v1->timer = v881;
  int v775 = v1->timer;
  int * v776 = v1->reg_ready;
  int v777 = v776[24];
  int v884 = v777 + ((v775 - v777) & (~((v775 - v777) >> 31)));
  v1->timer = v884;
  int v779 = v1->timer;
  int * v780 = v1->reg_ready;
  int v781 = v780[25];
  int v887 = v781 + ((v779 - v781) & (~((v779 - v781) >> 31)));
  v1->timer = v887;
  int v783 = v1->timer;
  int * v784 = v1->reg_ready;
  int v785 = v784[26];
  int v890 = v785 + ((v783 - v785) & (~((v783 - v785) >> 31)));
  v1->timer = v890;
  int v787 = v1->timer;
  int * v788 = v1->reg_ready;
  int v789 = v788[27];
  int v893 = v789 + ((v787 - v789) & (~((v787 - v789) >> 31)));
  v1->timer = v893;
  int v791 = v1->timer;
  int * v792 = v1->reg_ready;
  int v793 = v792[28];
  int v896 = v793 + ((v791 - v793) & (~((v791 - v793) >> 31)));
  v1->timer = v896;
  int v795 = v1->timer;
  int * v796 = v1->reg_ready;
  int v797 = v796[29];
  int v899 = v797 + ((v795 - v797) & (~((v795 - v797) >> 31)));
  v1->timer = v899;
  int v799 = v1->timer;
  int * v800 = v1->reg_ready;
  int v801 = v800[30];
  int v902 = v801 + ((v799 - v801) & (~((v799 - v801) >> 31)));
  v1->timer = v902;
  int v803 = v1->timer;
  int * v804 = v1->reg_ready;
  int v805 = v804[31];
  int v905 = v805 + ((v803 - v805) & (~((v803 - v805) >> 31)));
  v1->timer = v905;
  return v1;
}

struct StateT * slot_10(struct StateT * v601) {
  int v602 = v601->timer;
  int v615 = v602 + 1;
  v601->timer = v615;
  int * v604 = v601->reg_ready;
  int v605 = v604[7];
  int * v606 = v601->regs;
  int v607 = v606[7];
  int v608 = v604[9];
  int v609 = v606[9];
  int v621 = (v608 + (((v605 + ((v602 - v605) & (~((v602 - v605) >> 31)))) - v608) & (~(((v605 + ((v602 - v605) & (~((v602 - v605) >> 31)))) - v608) >> 31)))) + 1;
  v604[16] = v621;
  int * v611 = v601->regs;
  int v623 = v607 ^ v609;
  v611[16] = v623;
  struct StateT * v613 = slot_11(v601);
  return v613;
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

struct StateT * slot_8(struct StateT * v368) {
  int v369 = v368->timer;
  int v382 = v369 + 1;
  v368->timer = v382;
  int * v371 = v368->reg_ready;
  int v372 = v371[13];
  int * v373 = v368->regs;
  int v374 = v373[13];
  int v375 = v371[14];
  int v376 = v373[14];
  int v388 = (v375 + (((v372 + ((v369 - v372) & (~((v369 - v372) >> 31)))) - v375) & (~(((v372 + ((v369 - v372) & (~((v369 - v372) >> 31)))) - v375) >> 31)))) + 1;
  v371[8] = v388;
  int * v378 = v368->regs;
  int v390 = v374 + v376;
  v378[8] = v390;
  struct StateT * v380 = slot_9(v368);
  return v380;
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

struct StateT * slot_13(struct StateT * v671) {
  int v672 = v671->timer;
  int v676 = v672 + 1;
  v671->timer = v676;
  struct StateT * v674 = slot_5(v671);
  return v674;
}

struct StateT * slot_9(struct StateT * v393) {
  int v394 = v393->timer;
  int v506 = v394 + 1;
  v393->timer = v506;
  int * v396 = v393->reg_ready;
  int v397 = v396[8];
  int * v398 = v393->regs;
  int v399 = v398[8];
  int * v400 = v393->cache_tags;
  int v511 = (((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 1) * 2;
  int v401 = v400[v511];
  int v512 = ((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 1) * 2) + 1;
  int v402 = v400[v512];
  int v513 = 4 + ((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 3) * 2);
  int v403 = v400[v513];
  int v514 = (4 + ((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v404 = v400[v514];
  int * v405 = v393->cache_vals;
  bool v515 = !(((~(((v401 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))) | (-(v401 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))))) >> 31)) | (~(((v402 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))) | (-(v402 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))))) >> 31))) == 0);
  int v498;
  if (v515) {
    int * v406 = v393->cache_age;
    int v517 = ((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 1) * 2) + ((~(((v402 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))) | (-(v402 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))))) >> 31)) & 1);
    int v407 = v406[v517];
    int v408 = v406[v511];
    int v518 = v408 + ((int)((unsigned int)(v408 - v407) >> 31));
    v406[v511] = v518;
    int * v410 = v393->cache_age;
    int v411 = v410[v512];
    int v520 = v411 + ((int)((unsigned int)(v411 - v407) >> 31));
    v410[v512] = v520;
    int * v413 = v393->cache_age;
    v413[v517] = 0;
    v498 = v517;
  } else {
    int * v416 = v393->cache_age;
    int v524 = (((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 1) * 2;
    int v417 = v416[v524];
    int * v418 = v393->cache_tags;
    int v419 = v418[v524];
    int v420 = v416[v512];
    int v421 = v418[v512];
    bool v526 = !(((~(((v403 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))) | (-(v403 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))))) >> 31)) | (~(((v404 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))) | (-(v404 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))))) >> 31))) == 0);
    int v475;
    if (v526) {
      int * v422 = v393->cache_age;
      int v528 = (4 + ((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 3) * 2)) + ((~(((v404 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))) | (-(v404 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))))) >> 31)) & 1);
      int v423 = v422[v528];
      int v424 = v422[v513];
      int v529 = v424 + ((int)((unsigned int)(v424 - v423) >> 31));
      v422[v513] = v529;
      int * v426 = v393->cache_age;
      int v427 = v426[v514];
      int v531 = v427 + ((int)((unsigned int)(v427 - v423) >> 31));
      v426[v514] = v531;
      int * v429 = v393->cache_age;
      v429[v528] = 0;
      v475 = v528;
    } else {
      int * v432 = v393->cache_age;
      int v535 = 4 + ((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 3) * 2);
      int v433 = v432[v535];
      int * v434 = v393->cache_tags;
      int v435 = v434[v535];
      int v436 = v432[v514];
      int v437 = v434[v514];
      int * v438 = v393->cache_dirty;
      int v538 = (4 + ((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 3) * 2)) + ((((v433 + ((~(((v435 ^ -1) | (-(v435 ^ -1))) >> 31)) & 2)) - (v436 + ((~(((v437 ^ -1) | (-(v437 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v439 = v438[v538];
      bool v539 = !(v439 == 0);
      if (v539) {
        int * v440 = v393->cache_tags;
        int v441 = v440[v538];
        int * v442 = v393->cache_vals;
        int v542 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 3) * 2)) + ((((v433 + ((~(((v435 ^ -1) | (-(v435 ^ -1))) >> 31)) & 2)) - (v436 + ((~(((v437 ^ -1) | (-(v437 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v443 = v442[v542];
        int v543 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 3) * 2)) + ((((v433 + ((~(((v435 ^ -1) | (-(v435 ^ -1))) >> 31)) & 2)) - (v436 + ((~(((v437 ^ -1) | (-(v437 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v444 = v442[v543];
        int * v445 = v393->mem;
        int v545 = v441 * 2;
        v445[v545] = v443;
        int * v447 = v393->mem;
        int v548 = (v441 * 2) + 1;
        v447[v548] = v444;
        ;
      } else {
        ;
      }
      int * v452 = v393->mem;
      int v553 = ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) * 2;
      int v453 = v452[v553];
      int v554 = (((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) * 2) + 1;
      int v454 = v452[v554];
      int * v455 = v393->cache_vals;
      int v556 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 3) * 2)) + ((((v433 + ((~(((v435 ^ -1) | (-(v435 ^ -1))) >> 31)) & 2)) - (v436 + ((~(((v437 ^ -1) | (-(v437 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v455[v556] = v453;
      int * v457 = v393->cache_vals;
      int v559 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 3) * 2)) + ((((v433 + ((~(((v435 ^ -1) | (-(v435 ^ -1))) >> 31)) & 2)) - (v436 + ((~(((v437 ^ -1) | (-(v437 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v457[v559] = v454;
      int * v459 = v393->cache_tags;
      int v562 = (int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1);
      v459[v538] = v562;
      int * v461 = v393->cache_dirty;
      v461[v538] = 0;
      int * v463 = v393->cache_age;
      v463[v538] = 1;
      int * v465 = v393->cache_age;
      int v466 = v465[v538];
      int v467 = v465[v513];
      int v568 = v467 + ((int)((unsigned int)(v467 - v466) >> 31));
      v465[v513] = v568;
      int * v469 = v393->cache_age;
      int v470 = v469[v514];
      int v570 = v470 + ((int)((unsigned int)(v470 - v466) >> 31));
      v469[v514] = v570;
      int * v472 = v393->cache_age;
      v472[v538] = 0;
      v475 = v538;
    }
    int * v476 = v393->cache_vals;
    int v573 = v475 * 2;
    int v477 = v476[v573];
    int v574 = (v475 * 2) + 1;
    int v478 = v476[v574];
    int v575 = (((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 1) * 2) + ((((v417 + ((~(((v419 ^ -1) | (-(v419 ^ -1))) >> 31)) & 2)) - (v420 + ((~(((v421 ^ -1) | (-(v421 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v476[v575] = v477;
    int * v480 = v393->cache_vals;
    int v578 = ((((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 1) * 2) + ((((v417 + ((~(((v419 ^ -1) | (-(v419 ^ -1))) >> 31)) & 2)) - (v420 + ((~(((v421 ^ -1) | (-(v421 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v480[v578] = v478;
    int * v482 = v393->cache_tags;
    int v581 = ((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 1) * 2) + ((((v417 + ((~(((v419 ^ -1) | (-(v419 ^ -1))) >> 31)) & 2)) - (v420 + ((~(((v421 ^ -1) | (-(v421 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v582 = (int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1);
    v482[v581] = v582;
    int * v484 = v393->cache_dirty;
    v484[v581] = 0;
    int * v486 = v393->cache_age;
    v486[v581] = 1;
    int * v488 = v393->cache_age;
    int v489 = v488[v581];
    int v490 = v488[v511];
    int v588 = v490 + ((int)((unsigned int)(v490 - v489) >> 31));
    v488[v511] = v588;
    int * v492 = v393->cache_age;
    int v493 = v492[v512];
    int v590 = v493 + ((int)((unsigned int)(v493 - v489) >> 31));
    v492[v512] = v590;
    int * v495 = v393->cache_age;
    v495[v581] = 0;
    v498 = v581;
  }
  int v593 = (v498 * 2) + (((int)((unsigned int)v399 >> 2)) & 1);
  int v499 = v405[v593];
  int * v500 = v393->reg_ready;
  int v596 = ((v397 + ((v394 - v397) & (~((v394 - v397) >> 31)))) + 1) + ((100 ^ (((~(((v403 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))) | (-(v403 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))))) >> 31)) | (~(((v404 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))) | (-(v404 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v401 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))) | (-(v401 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))))) >> 31)) | (~(((v402 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))) | (-(v402 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v403 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))) | (-(v403 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))))) >> 31)) | (~(((v404 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))) | (-(v404 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))))) >> 31))) & 104)))));
  v500[9] = v596;
  int * v502 = v393->regs;
  v502[9] = v499;
  struct StateT * v504 = slot_10(v393);
  return v504;
}

struct StateT * slot_11(struct StateT * v626) {
  int v627 = v626->timer;
  int v640 = v627 + 1;
  v626->timer = v640;
  int * v629 = v626->reg_ready;
  int v630 = v629[5];
  int * v631 = v626->regs;
  int v632 = v631[5];
  int v633 = v629[16];
  int v634 = v631[16];
  int v645 = (v633 + (((v630 + ((v627 - v630) & (~((v627 - v630) >> 31)))) - v633) & (~(((v630 + ((v627 - v630) & (~((v627 - v630) >> 31)))) - v633) >> 31)))) + 1;
  v629[5] = v645;
  int * v636 = v626->regs;
  int v647 = v632 | v634;
  v636[5] = v647;
  struct StateT * v638 = slot_12(v626);
  return v638;
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
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}