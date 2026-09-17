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

struct StateT * slot_12(struct StateT * v725);
struct StateT * slot_14(struct StateT * v105);
struct StateT * slot_6(struct StateT * v152);
struct StateT * slot_5(struct StateT * v120);
struct StateT * slot_2(struct StateT * v38);
struct StateT * slot_7(struct StateT * v407);
struct StateT * slot_3(struct StateT * v56);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v743);
struct StateT * slot_1(struct StateT * v20);
struct StateT * slot_8(struct StateT * v439);
struct StateT * slot_4(struct StateT * v74);
struct StateT * slot_13(struct StateT * v767);
struct StateT * slot_9(struct StateT * v694);
struct StateT * slot_11(struct StateT * v773);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v725) {
  int v726 = v725->timer;
  int v727 = v725->timer;
  int v735 = v727 + 1;
  v725->timer = v735;
  int * v729 = v725->reg_ready;
  int v738 = v726 + 1;
  v729[10] = v738;
  int * v731 = v725->regs;
  v731[10] = 0;
  struct StateT * v733 = slot_13(v725);
  return v733;
}

struct StateT * slot_14(struct StateT * v105) {
  int v106 = v105->timer;
  int v107 = v105->timer;
  int v114 = v107 + 1;
  v105->timer = v114;
  int * v109 = v105->reg_ready;
  int v117 = v106 + 1;
  v109[10] = v117;
  int * v111 = v105->regs;
  v111[10] = 1;
  return v105;
}

struct StateT * slot_6(struct StateT * v152) {
  int v153 = v152->timer;
  int v154 = v152->timer;
  int v289 = v154 + 1;
  v152->timer = v289;
  int * v156 = v152->reg_ready;
  int v157 = v156[5];
  int * v158 = v152->regs;
  int v159 = v158[5];
  int * v160 = v152->cache_tags;
  int v294 = (((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1)) & 1) * 2;
  int v161 = v160[v294];
  int * v162 = v152->cache_tags;
  int v296 = ((((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1)) & 1) * 2) + 1;
  int v163 = v162[v296];
  int * v164 = v152->cache_tags;
  int v298 = 4 + ((((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1)) & 3) * 2);
  int v165 = v164[v298];
  int * v166 = v152->cache_tags;
  int v300 = (4 + ((((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v167 = v166[v300];
  int * v168 = v152->cache_vals;
  bool v301 = !(((~(((v161 ^ ((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1))) | (-(v161 ^ ((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1))))) >> 31)) | (~(((v163 ^ ((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1))) | (-(v163 ^ ((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1))))) >> 31))) == 0);
  int v281;
  if (v301) {
    int * v169 = v152->cache_age;
    int v303 = ((((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1)) & 1) * 2) + ((~(((v163 ^ ((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1))) | (-(v163 ^ ((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1))))) >> 31)) & 1);
    int v170 = v169[v303];
    int * v171 = v152->cache_age;
    int v172 = v171[v294];
    int * v173 = v152->cache_age;
    int v306 = v172 + ((int)((unsigned int)(v172 - v170) >> 31));
    v173[v294] = v306;
    int * v175 = v152->cache_age;
    int v176 = v175[v296];
    int * v177 = v152->cache_age;
    int v309 = v176 + ((int)((unsigned int)(v176 - v170) >> 31));
    v177[v296] = v309;
    int * v179 = v152->cache_age;
    v179[v303] = 0;
    v281 = v303;
  } else {
    int * v182 = v152->cache_age;
    int v313 = (((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1)) & 1) * 2;
    int v183 = v182[v313];
    int * v184 = v152->cache_tags;
    int v185 = v184[v313];
    int * v186 = v152->cache_age;
    int v187 = v186[v296];
    int * v188 = v152->cache_tags;
    int v189 = v188[v296];
    bool v317 = !(((~(((v165 ^ ((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1))) | (-(v165 ^ ((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1))))) >> 31)) | (~(((v167 ^ ((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1))) | (-(v167 ^ ((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1))))) >> 31))) == 0);
    int v253;
    if (v317) {
      int * v190 = v152->cache_age;
      int v319 = (4 + ((((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1)) & 3) * 2)) + ((~(((v167 ^ ((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1))) | (-(v167 ^ ((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1))))) >> 31)) & 1);
      int v191 = v190[v319];
      int * v192 = v152->cache_age;
      int v193 = v192[v298];
      int * v194 = v152->cache_age;
      int v322 = v193 + ((int)((unsigned int)(v193 - v191) >> 31));
      v194[v298] = v322;
      int * v196 = v152->cache_age;
      int v197 = v196[v300];
      int * v198 = v152->cache_age;
      int v325 = v197 + ((int)((unsigned int)(v197 - v191) >> 31));
      v198[v300] = v325;
      int * v200 = v152->cache_age;
      v200[v319] = 0;
      v253 = v319;
    } else {
      int * v203 = v152->cache_age;
      int v329 = 4 + ((((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1)) & 3) * 2);
      int v204 = v203[v329];
      int * v205 = v152->cache_tags;
      int v206 = v205[v329];
      int * v207 = v152->cache_age;
      int v208 = v207[v300];
      int * v209 = v152->cache_tags;
      int v210 = v209[v300];
      int * v211 = v152->cache_dirty;
      int v334 = (4 + ((((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1)) & 3) * 2)) + ((((v204 + ((~(((v206 ^ -1) | (-(v206 ^ -1))) >> 31)) & 2)) - (v208 + ((~(((v210 ^ -1) | (-(v210 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v212 = v211[v334];
      bool v335 = !(v212 == 0);
      if (v335) {
        int * v213 = v152->cache_tags;
        int v214 = v213[v334];
        int * v215 = v152->cache_vals;
        int v338 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1)) & 3) * 2)) + ((((v204 + ((~(((v206 ^ -1) | (-(v206 ^ -1))) >> 31)) & 2)) - (v208 + ((~(((v210 ^ -1) | (-(v210 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v216 = v215[v338];
        int * v217 = v152->cache_vals;
        int v340 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1)) & 3) * 2)) + ((((v204 + ((~(((v206 ^ -1) | (-(v206 ^ -1))) >> 31)) & 2)) - (v208 + ((~(((v210 ^ -1) | (-(v210 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v218 = v217[v340];
        int * v219 = v152->mem;
        int v342 = v214 * 2;
        v219[v342] = v216;
        int * v221 = v152->mem;
        int v345 = (v214 * 2) + 1;
        v221[v345] = v218;
        ;
      } else {
        ;
      }
      int * v226 = v152->mem;
      int v350 = ((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1)) * 2;
      int v227 = v226[v350];
      int * v228 = v152->mem;
      int v352 = (((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1)) * 2) + 1;
      int v229 = v228[v352];
      int * v230 = v152->cache_vals;
      int v354 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1)) & 3) * 2)) + ((((v204 + ((~(((v206 ^ -1) | (-(v206 ^ -1))) >> 31)) & 2)) - (v208 + ((~(((v210 ^ -1) | (-(v210 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v230[v354] = v227;
      int * v232 = v152->cache_vals;
      int v357 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1)) & 3) * 2)) + ((((v204 + ((~(((v206 ^ -1) | (-(v206 ^ -1))) >> 31)) & 2)) - (v208 + ((~(((v210 ^ -1) | (-(v210 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v232[v357] = v229;
      int * v234 = v152->cache_tags;
      int v360 = (int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1);
      v234[v334] = v360;
      int * v236 = v152->cache_dirty;
      v236[v334] = 0;
      int * v238 = v152->cache_age;
      v238[v334] = 1;
      int * v240 = v152->cache_age;
      int v241 = v240[v334];
      int * v242 = v152->cache_age;
      int v243 = v242[v298];
      int * v244 = v152->cache_age;
      int v368 = v243 + ((int)((unsigned int)(v243 - v241) >> 31));
      v244[v298] = v368;
      int * v246 = v152->cache_age;
      int v247 = v246[v300];
      int * v248 = v152->cache_age;
      int v371 = v247 + ((int)((unsigned int)(v247 - v241) >> 31));
      v248[v300] = v371;
      int * v250 = v152->cache_age;
      v250[v334] = 0;
      v253 = v334;
    }
    int * v254 = v152->cache_vals;
    int v374 = v253 * 2;
    int v255 = v254[v374];
    int * v256 = v152->cache_vals;
    int v376 = (v253 * 2) + 1;
    int v257 = v256[v376];
    int * v258 = v152->cache_vals;
    int v378 = (((((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1)) & 1) * 2) + ((((v183 + ((~(((v185 ^ -1) | (-(v185 ^ -1))) >> 31)) & 2)) - (v187 + ((~(((v189 ^ -1) | (-(v189 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v258[v378] = v255;
    int * v260 = v152->cache_vals;
    int v381 = ((((((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1)) & 1) * 2) + ((((v183 + ((~(((v185 ^ -1) | (-(v185 ^ -1))) >> 31)) & 2)) - (v187 + ((~(((v189 ^ -1) | (-(v189 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v260[v381] = v257;
    int * v262 = v152->cache_tags;
    int v384 = ((((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1)) & 1) * 2) + ((((v183 + ((~(((v185 ^ -1) | (-(v185 ^ -1))) >> 31)) & 2)) - (v187 + ((~(((v189 ^ -1) | (-(v189 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v385 = (int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1);
    v262[v384] = v385;
    int * v264 = v152->cache_dirty;
    v264[v384] = 0;
    int * v266 = v152->cache_age;
    v266[v384] = 1;
    int * v268 = v152->cache_age;
    int v269 = v268[v384];
    int * v270 = v152->cache_age;
    int v271 = v270[v294];
    int * v272 = v152->cache_age;
    int v393 = v271 + ((int)((unsigned int)(v271 - v269) >> 31));
    v272[v294] = v393;
    int * v274 = v152->cache_age;
    int v275 = v274[v296];
    int * v276 = v152->cache_age;
    int v396 = v275 + ((int)((unsigned int)(v275 - v269) >> 31));
    v276[v296] = v396;
    int * v278 = v152->cache_age;
    v278[v384] = 0;
    v281 = v384;
  }
  int v399 = (v281 * 2) + (((int)((unsigned int)v159 >> 2)) & 1);
  int v282 = v168[v399];
  int * v283 = v152->reg_ready;
  int v402 = ((v157 + ((v153 - v157) & (~((v153 - v157) >> 31)))) + 1) + ((100 ^ (((~(((v165 ^ ((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1))) | (-(v165 ^ ((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1))))) >> 31)) | (~(((v167 ^ ((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1))) | (-(v167 ^ ((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v161 ^ ((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1))) | (-(v161 ^ ((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1))))) >> 31)) | (~(((v163 ^ ((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1))) | (-(v163 ^ ((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v165 ^ ((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1))) | (-(v165 ^ ((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1))))) >> 31)) | (~(((v167 ^ ((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1))) | (-(v167 ^ ((int)((unsigned int)((int)((unsigned int)v159 >> 2)) >> 1))))) >> 31))) & 104)))));
  v283[10] = v402;
  int * v285 = v152->regs;
  v285[10] = v282;
  struct StateT * v287 = slot_7(v152);
  return v287;
}

struct StateT * slot_5(struct StateT * v120) {
  int v121 = v120->timer;
  int v122 = v120->timer;
  int v138 = v122 + 1;
  v120->timer = v138;
  int * v124 = v120->reg_ready;
  int v125 = v124[12];
  int * v126 = v120->regs;
  int v127 = v126[12];
  int * v128 = v120->reg_ready;
  int v129 = v128[14];
  int * v130 = v120->regs;
  int v131 = v130[14];
  int * v132 = v120->reg_ready;
  int v147 = (v129 + (((v125 + ((v121 - v125) & (~((v121 - v125) >> 31)))) - v129) & (~(((v125 + ((v121 - v125) & (~((v121 - v125) >> 31)))) - v129) >> 31)))) + 1;
  v132[5] = v147;
  int * v134 = v120->regs;
  int v149 = v127 + v131;
  v134[5] = v149;
  struct StateT * v136 = slot_6(v120);
  return v136;
}

struct StateT * slot_2(struct StateT * v38) {
  int v39 = v38->timer;
  int v40 = v38->timer;
  int v48 = v40 + 1;
  v38->timer = v48;
  int * v42 = v38->reg_ready;
  int v51 = v39 + 1;
  v42[14] = v51;
  int * v44 = v38->regs;
  v44[14] = 0;
  struct StateT * v46 = slot_3(v38);
  return v46;
}

struct StateT * slot_7(struct StateT * v407) {
  int v408 = v407->timer;
  int v409 = v407->timer;
  int v425 = v409 + 1;
  v407->timer = v425;
  int * v411 = v407->reg_ready;
  int v412 = v411[13];
  int * v413 = v407->regs;
  int v414 = v413[13];
  int * v415 = v407->reg_ready;
  int v416 = v415[14];
  int * v417 = v407->regs;
  int v418 = v417[14];
  int * v419 = v407->reg_ready;
  int v434 = (v416 + (((v412 + ((v408 - v412) & (~((v408 - v412) >> 31)))) - v416) & (~(((v412 + ((v408 - v412) & (~((v408 - v412) >> 31)))) - v416) >> 31)))) + 1;
  v419[6] = v434;
  int * v421 = v407->regs;
  int v436 = v414 + v418;
  v421[6] = v436;
  struct StateT * v423 = slot_8(v407);
  return v423;
}

struct StateT * slot_3(struct StateT * v56) {
  int v57 = v56->timer;
  int v58 = v56->timer;
  int v66 = v58 + 1;
  v56->timer = v66;
  int * v60 = v56->reg_ready;
  int v69 = v57 + 1;
  v60[15] = v69;
  int * v62 = v56->regs;
  v62[15] = 16;
  struct StateT * v64 = slot_4(v56);
  return v64;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v782 = v1->timer;
  int * v783 = v1->reg_ready;
  int v784 = v783[0];
  int v915 = v784 + ((v782 - v784) & (~((v782 - v784) >> 31)));
  v1->timer = v915;
  int v786 = v1->timer;
  int * v787 = v1->reg_ready;
  int v788 = v787[1];
  int v918 = v788 + ((v786 - v788) & (~((v786 - v788) >> 31)));
  v1->timer = v918;
  int v790 = v1->timer;
  int * v791 = v1->reg_ready;
  int v792 = v791[2];
  int v921 = v792 + ((v790 - v792) & (~((v790 - v792) >> 31)));
  v1->timer = v921;
  int v794 = v1->timer;
  int * v795 = v1->reg_ready;
  int v796 = v795[3];
  int v924 = v796 + ((v794 - v796) & (~((v794 - v796) >> 31)));
  v1->timer = v924;
  int v798 = v1->timer;
  int * v799 = v1->reg_ready;
  int v800 = v799[4];
  int v927 = v800 + ((v798 - v800) & (~((v798 - v800) >> 31)));
  v1->timer = v927;
  int v802 = v1->timer;
  int * v803 = v1->reg_ready;
  int v804 = v803[5];
  int v930 = v804 + ((v802 - v804) & (~((v802 - v804) >> 31)));
  v1->timer = v930;
  int v806 = v1->timer;
  int * v807 = v1->reg_ready;
  int v808 = v807[6];
  int v933 = v808 + ((v806 - v808) & (~((v806 - v808) >> 31)));
  v1->timer = v933;
  int v810 = v1->timer;
  int * v811 = v1->reg_ready;
  int v812 = v811[7];
  int v936 = v812 + ((v810 - v812) & (~((v810 - v812) >> 31)));
  v1->timer = v936;
  int v814 = v1->timer;
  int * v815 = v1->reg_ready;
  int v816 = v815[8];
  int v939 = v816 + ((v814 - v816) & (~((v814 - v816) >> 31)));
  v1->timer = v939;
  int v818 = v1->timer;
  int * v819 = v1->reg_ready;
  int v820 = v819[9];
  int v942 = v820 + ((v818 - v820) & (~((v818 - v820) >> 31)));
  v1->timer = v942;
  int v822 = v1->timer;
  int * v823 = v1->reg_ready;
  int v824 = v823[10];
  int v945 = v824 + ((v822 - v824) & (~((v822 - v824) >> 31)));
  v1->timer = v945;
  int v826 = v1->timer;
  int * v827 = v1->reg_ready;
  int v828 = v827[11];
  int v948 = v828 + ((v826 - v828) & (~((v826 - v828) >> 31)));
  v1->timer = v948;
  int v830 = v1->timer;
  int * v831 = v1->reg_ready;
  int v832 = v831[12];
  int v951 = v832 + ((v830 - v832) & (~((v830 - v832) >> 31)));
  v1->timer = v951;
  int v834 = v1->timer;
  int * v835 = v1->reg_ready;
  int v836 = v835[13];
  int v954 = v836 + ((v834 - v836) & (~((v834 - v836) >> 31)));
  v1->timer = v954;
  int v838 = v1->timer;
  int * v839 = v1->reg_ready;
  int v840 = v839[14];
  int v957 = v840 + ((v838 - v840) & (~((v838 - v840) >> 31)));
  v1->timer = v957;
  int v842 = v1->timer;
  int * v843 = v1->reg_ready;
  int v844 = v843[15];
  int v960 = v844 + ((v842 - v844) & (~((v842 - v844) >> 31)));
  v1->timer = v960;
  int v846 = v1->timer;
  int * v847 = v1->reg_ready;
  int v848 = v847[16];
  int v963 = v848 + ((v846 - v848) & (~((v846 - v848) >> 31)));
  v1->timer = v963;
  int v850 = v1->timer;
  int * v851 = v1->reg_ready;
  int v852 = v851[17];
  int v966 = v852 + ((v850 - v852) & (~((v850 - v852) >> 31)));
  v1->timer = v966;
  int v854 = v1->timer;
  int * v855 = v1->reg_ready;
  int v856 = v855[18];
  int v969 = v856 + ((v854 - v856) & (~((v854 - v856) >> 31)));
  v1->timer = v969;
  int v858 = v1->timer;
  int * v859 = v1->reg_ready;
  int v860 = v859[19];
  int v972 = v860 + ((v858 - v860) & (~((v858 - v860) >> 31)));
  v1->timer = v972;
  int v862 = v1->timer;
  int * v863 = v1->reg_ready;
  int v864 = v863[20];
  int v975 = v864 + ((v862 - v864) & (~((v862 - v864) >> 31)));
  v1->timer = v975;
  int v866 = v1->timer;
  int * v867 = v1->reg_ready;
  int v868 = v867[21];
  int v978 = v868 + ((v866 - v868) & (~((v866 - v868) >> 31)));
  v1->timer = v978;
  int v870 = v1->timer;
  int * v871 = v1->reg_ready;
  int v872 = v871[22];
  int v981 = v872 + ((v870 - v872) & (~((v870 - v872) >> 31)));
  v1->timer = v981;
  int v874 = v1->timer;
  int * v875 = v1->reg_ready;
  int v876 = v875[23];
  int v984 = v876 + ((v874 - v876) & (~((v874 - v876) >> 31)));
  v1->timer = v984;
  int v878 = v1->timer;
  int * v879 = v1->reg_ready;
  int v880 = v879[24];
  int v987 = v880 + ((v878 - v880) & (~((v878 - v880) >> 31)));
  v1->timer = v987;
  int v882 = v1->timer;
  int * v883 = v1->reg_ready;
  int v884 = v883[25];
  int v990 = v884 + ((v882 - v884) & (~((v882 - v884) >> 31)));
  v1->timer = v990;
  int v886 = v1->timer;
  int * v887 = v1->reg_ready;
  int v888 = v887[26];
  int v993 = v888 + ((v886 - v888) & (~((v886 - v888) >> 31)));
  v1->timer = v993;
  int v890 = v1->timer;
  int * v891 = v1->reg_ready;
  int v892 = v891[27];
  int v996 = v892 + ((v890 - v892) & (~((v890 - v892) >> 31)));
  v1->timer = v996;
  int v894 = v1->timer;
  int * v895 = v1->reg_ready;
  int v896 = v895[28];
  int v999 = v896 + ((v894 - v896) & (~((v894 - v896) >> 31)));
  v1->timer = v999;
  int v898 = v1->timer;
  int * v899 = v1->reg_ready;
  int v900 = v899[29];
  int v1002 = v900 + ((v898 - v900) & (~((v898 - v900) >> 31)));
  v1->timer = v1002;
  int v902 = v1->timer;
  int * v903 = v1->reg_ready;
  int v904 = v903[30];
  int v1005 = v904 + ((v902 - v904) & (~((v902 - v904) >> 31)));
  v1->timer = v1005;
  int v906 = v1->timer;
  int * v907 = v1->reg_ready;
  int v908 = v907[31];
  int v1008 = v908 + ((v906 - v908) & (~((v906 - v908) >> 31)));
  v1->timer = v1008;
  return v1;
}

struct StateT * slot_10(struct StateT * v743) {
  int v744 = v743->timer;
  int v745 = v743->timer;
  int v757 = v745 + 1;
  v743->timer = v757;
  int * v747 = v743->reg_ready;
  int v748 = v747[14];
  int * v749 = v743->regs;
  int v750 = v749[14];
  int * v751 = v743->reg_ready;
  int v762 = (v748 + ((v744 - v748) & (~((v744 - v748) >> 31)))) + 1;
  v751[14] = v762;
  int * v753 = v743->regs;
  int v764 = v750 + 4;
  v753[14] = v764;
  struct StateT * v755 = slot_11(v743);
  return v755;
}

struct StateT * slot_1(struct StateT * v20) {
  int v21 = v20->timer;
  int v22 = v20->timer;
  int v30 = v22 + 1;
  v20->timer = v30;
  int * v24 = v20->reg_ready;
  int v33 = v21 + 1;
  v24[13] = v33;
  int * v26 = v20->regs;
  v26[13] = 80;
  struct StateT * v28 = slot_2(v20);
  return v28;
}

struct StateT * slot_8(struct StateT * v439) {
  int v440 = v439->timer;
  int v441 = v439->timer;
  int v576 = v441 + 1;
  v439->timer = v576;
  int * v443 = v439->reg_ready;
  int v444 = v443[6];
  int * v445 = v439->regs;
  int v446 = v445[6];
  int * v447 = v439->cache_tags;
  int v581 = (((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1)) & 1) * 2;
  int v448 = v447[v581];
  int * v449 = v439->cache_tags;
  int v583 = ((((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1)) & 1) * 2) + 1;
  int v450 = v449[v583];
  int * v451 = v439->cache_tags;
  int v585 = 4 + ((((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1)) & 3) * 2);
  int v452 = v451[v585];
  int * v453 = v439->cache_tags;
  int v587 = (4 + ((((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v454 = v453[v587];
  int * v455 = v439->cache_vals;
  bool v588 = !(((~(((v448 ^ ((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1))) | (-(v448 ^ ((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1))))) >> 31)) | (~(((v450 ^ ((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1))) | (-(v450 ^ ((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1))))) >> 31))) == 0);
  int v568;
  if (v588) {
    int * v456 = v439->cache_age;
    int v590 = ((((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1)) & 1) * 2) + ((~(((v450 ^ ((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1))) | (-(v450 ^ ((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1))))) >> 31)) & 1);
    int v457 = v456[v590];
    int * v458 = v439->cache_age;
    int v459 = v458[v581];
    int * v460 = v439->cache_age;
    int v593 = v459 + ((int)((unsigned int)(v459 - v457) >> 31));
    v460[v581] = v593;
    int * v462 = v439->cache_age;
    int v463 = v462[v583];
    int * v464 = v439->cache_age;
    int v596 = v463 + ((int)((unsigned int)(v463 - v457) >> 31));
    v464[v583] = v596;
    int * v466 = v439->cache_age;
    v466[v590] = 0;
    v568 = v590;
  } else {
    int * v469 = v439->cache_age;
    int v600 = (((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1)) & 1) * 2;
    int v470 = v469[v600];
    int * v471 = v439->cache_tags;
    int v472 = v471[v600];
    int * v473 = v439->cache_age;
    int v474 = v473[v583];
    int * v475 = v439->cache_tags;
    int v476 = v475[v583];
    bool v604 = !(((~(((v452 ^ ((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1))) | (-(v452 ^ ((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1))))) >> 31)) | (~(((v454 ^ ((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1))) | (-(v454 ^ ((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1))))) >> 31))) == 0);
    int v540;
    if (v604) {
      int * v477 = v439->cache_age;
      int v606 = (4 + ((((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1)) & 3) * 2)) + ((~(((v454 ^ ((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1))) | (-(v454 ^ ((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1))))) >> 31)) & 1);
      int v478 = v477[v606];
      int * v479 = v439->cache_age;
      int v480 = v479[v585];
      int * v481 = v439->cache_age;
      int v609 = v480 + ((int)((unsigned int)(v480 - v478) >> 31));
      v481[v585] = v609;
      int * v483 = v439->cache_age;
      int v484 = v483[v587];
      int * v485 = v439->cache_age;
      int v612 = v484 + ((int)((unsigned int)(v484 - v478) >> 31));
      v485[v587] = v612;
      int * v487 = v439->cache_age;
      v487[v606] = 0;
      v540 = v606;
    } else {
      int * v490 = v439->cache_age;
      int v616 = 4 + ((((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1)) & 3) * 2);
      int v491 = v490[v616];
      int * v492 = v439->cache_tags;
      int v493 = v492[v616];
      int * v494 = v439->cache_age;
      int v495 = v494[v587];
      int * v496 = v439->cache_tags;
      int v497 = v496[v587];
      int * v498 = v439->cache_dirty;
      int v621 = (4 + ((((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1)) & 3) * 2)) + ((((v491 + ((~(((v493 ^ -1) | (-(v493 ^ -1))) >> 31)) & 2)) - (v495 + ((~(((v497 ^ -1) | (-(v497 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v499 = v498[v621];
      bool v622 = !(v499 == 0);
      if (v622) {
        int * v500 = v439->cache_tags;
        int v501 = v500[v621];
        int * v502 = v439->cache_vals;
        int v625 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1)) & 3) * 2)) + ((((v491 + ((~(((v493 ^ -1) | (-(v493 ^ -1))) >> 31)) & 2)) - (v495 + ((~(((v497 ^ -1) | (-(v497 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v503 = v502[v625];
        int * v504 = v439->cache_vals;
        int v627 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1)) & 3) * 2)) + ((((v491 + ((~(((v493 ^ -1) | (-(v493 ^ -1))) >> 31)) & 2)) - (v495 + ((~(((v497 ^ -1) | (-(v497 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v505 = v504[v627];
        int * v506 = v439->mem;
        int v629 = v501 * 2;
        v506[v629] = v503;
        int * v508 = v439->mem;
        int v632 = (v501 * 2) + 1;
        v508[v632] = v505;
        ;
      } else {
        ;
      }
      int * v513 = v439->mem;
      int v637 = ((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1)) * 2;
      int v514 = v513[v637];
      int * v515 = v439->mem;
      int v639 = (((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1)) * 2) + 1;
      int v516 = v515[v639];
      int * v517 = v439->cache_vals;
      int v641 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1)) & 3) * 2)) + ((((v491 + ((~(((v493 ^ -1) | (-(v493 ^ -1))) >> 31)) & 2)) - (v495 + ((~(((v497 ^ -1) | (-(v497 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v517[v641] = v514;
      int * v519 = v439->cache_vals;
      int v644 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1)) & 3) * 2)) + ((((v491 + ((~(((v493 ^ -1) | (-(v493 ^ -1))) >> 31)) & 2)) - (v495 + ((~(((v497 ^ -1) | (-(v497 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v519[v644] = v516;
      int * v521 = v439->cache_tags;
      int v647 = (int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1);
      v521[v621] = v647;
      int * v523 = v439->cache_dirty;
      v523[v621] = 0;
      int * v525 = v439->cache_age;
      v525[v621] = 1;
      int * v527 = v439->cache_age;
      int v528 = v527[v621];
      int * v529 = v439->cache_age;
      int v530 = v529[v585];
      int * v531 = v439->cache_age;
      int v655 = v530 + ((int)((unsigned int)(v530 - v528) >> 31));
      v531[v585] = v655;
      int * v533 = v439->cache_age;
      int v534 = v533[v587];
      int * v535 = v439->cache_age;
      int v658 = v534 + ((int)((unsigned int)(v534 - v528) >> 31));
      v535[v587] = v658;
      int * v537 = v439->cache_age;
      v537[v621] = 0;
      v540 = v621;
    }
    int * v541 = v439->cache_vals;
    int v661 = v540 * 2;
    int v542 = v541[v661];
    int * v543 = v439->cache_vals;
    int v663 = (v540 * 2) + 1;
    int v544 = v543[v663];
    int * v545 = v439->cache_vals;
    int v665 = (((((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1)) & 1) * 2) + ((((v470 + ((~(((v472 ^ -1) | (-(v472 ^ -1))) >> 31)) & 2)) - (v474 + ((~(((v476 ^ -1) | (-(v476 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v545[v665] = v542;
    int * v547 = v439->cache_vals;
    int v668 = ((((((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1)) & 1) * 2) + ((((v470 + ((~(((v472 ^ -1) | (-(v472 ^ -1))) >> 31)) & 2)) - (v474 + ((~(((v476 ^ -1) | (-(v476 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v547[v668] = v544;
    int * v549 = v439->cache_tags;
    int v671 = ((((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1)) & 1) * 2) + ((((v470 + ((~(((v472 ^ -1) | (-(v472 ^ -1))) >> 31)) & 2)) - (v474 + ((~(((v476 ^ -1) | (-(v476 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v672 = (int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1);
    v549[v671] = v672;
    int * v551 = v439->cache_dirty;
    v551[v671] = 0;
    int * v553 = v439->cache_age;
    v553[v671] = 1;
    int * v555 = v439->cache_age;
    int v556 = v555[v671];
    int * v557 = v439->cache_age;
    int v558 = v557[v581];
    int * v559 = v439->cache_age;
    int v680 = v558 + ((int)((unsigned int)(v558 - v556) >> 31));
    v559[v581] = v680;
    int * v561 = v439->cache_age;
    int v562 = v561[v583];
    int * v563 = v439->cache_age;
    int v683 = v562 + ((int)((unsigned int)(v562 - v556) >> 31));
    v563[v583] = v683;
    int * v565 = v439->cache_age;
    v565[v671] = 0;
    v568 = v671;
  }
  int v686 = (v568 * 2) + (((int)((unsigned int)v446 >> 2)) & 1);
  int v569 = v455[v686];
  int * v570 = v439->reg_ready;
  int v689 = ((v444 + ((v440 - v444) & (~((v440 - v444) >> 31)))) + 1) + ((100 ^ (((~(((v452 ^ ((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1))) | (-(v452 ^ ((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1))))) >> 31)) | (~(((v454 ^ ((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1))) | (-(v454 ^ ((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v448 ^ ((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1))) | (-(v448 ^ ((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1))))) >> 31)) | (~(((v450 ^ ((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1))) | (-(v450 ^ ((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v452 ^ ((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1))) | (-(v452 ^ ((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1))))) >> 31)) | (~(((v454 ^ ((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1))) | (-(v454 ^ ((int)((unsigned int)((int)((unsigned int)v446 >> 2)) >> 1))))) >> 31))) & 104)))));
  v570[11] = v689;
  int * v572 = v439->regs;
  v572[11] = v569;
  struct StateT * v574 = slot_9(v439);
  return v574;
}

struct StateT * slot_4(struct StateT * v74) {
  int v75 = v74->timer;
  int v76 = v74->timer;
  int v92 = v76 + 1;
  v74->timer = v92;
  int * v78 = v74->reg_ready;
  int v79 = v78[14];
  int * v80 = v74->regs;
  int v81 = v80[14];
  int * v82 = v74->reg_ready;
  int v83 = v82[15];
  int * v84 = v74->regs;
  int v85 = v84[15];
  bool v99 = v81 >= v85;
  struct StateT * v90;
  if (v99) {
    struct StateT * v86 = slot_14(v74);
    v90 = v86;
  } else {
    struct StateT * v88 = slot_5(v74);
    v90 = v88;
  }
  return v90;
}

struct StateT * slot_13(struct StateT * v767) {
  int v768 = v767->timer;
  int v769 = v767->timer;
  int v772 = v769 + 1;
  v767->timer = v772;
  return v767;
}

struct StateT * slot_9(struct StateT * v694) {
  int v695 = v694->timer;
  int v696 = v694->timer;
  int v712 = v696 + 1;
  v694->timer = v712;
  int * v698 = v694->reg_ready;
  int v699 = v698[10];
  int * v700 = v694->regs;
  int v701 = v700[10];
  int * v702 = v694->reg_ready;
  int v703 = v702[11];
  int * v704 = v694->regs;
  int v705 = v704[11];
  bool v719 = !(v701 == v705);
  struct StateT * v710;
  if (v719) {
    struct StateT * v706 = slot_12(v694);
    v710 = v706;
  } else {
    struct StateT * v708 = slot_10(v694);
    v710 = v708;
  }
  return v710;
}

struct StateT * slot_11(struct StateT * v773) {
  int v774 = v773->timer;
  int v775 = v773->timer;
  int v779 = v775 + 1;
  v773->timer = v779;
  struct StateT * v777 = slot_4(v773);
  return v777;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v4 = v2->timer;
  int v12 = v4 + 1;
  v2->timer = v12;
  int * v6 = v2->reg_ready;
  int v15 = v3 + 1;
  v6[12] = v15;
  int * v8 = v2->regs;
  v8[12] = 0;
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