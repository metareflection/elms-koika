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

struct StateT * slot_12(struct StateT * v788);
struct StateT * slot_14(struct StateT * v123);
struct StateT * slot_6(struct StateT * v151);
struct StateT * slot_5(struct StateT * v92);
struct StateT * slot_2(struct StateT * v38);
struct StateT * slot_7(struct StateT * v183);
struct StateT * slot_3(struct StateT * v56);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v725);
struct StateT * slot_1(struct StateT * v20);
struct StateT * slot_8(struct StateT * v438);
struct StateT * slot_4(struct StateT * v74);
struct StateT * slot_13(struct StateT * v812);
struct StateT * slot_9(struct StateT * v470);
struct StateT * slot_11(struct StateT * v757);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v788) {
  int v789 = v788->timer;
  int v790 = v788->timer;
  int v802 = v790 + 1;
  v788->timer = v802;
  int * v792 = v788->reg_ready;
  int v793 = v792[14];
  int * v794 = v788->regs;
  int v795 = v794[14];
  int * v796 = v788->reg_ready;
  int v807 = (v793 + ((v789 - v793) & (~((v789 - v793) >> 31)))) + 1;
  v796[14] = v807;
  int * v798 = v788->regs;
  int v809 = v795 + 4;
  v798[14] = v809;
  struct StateT * v800 = slot_13(v788);
  return v800;
}

struct StateT * slot_14(struct StateT * v123) {
  int v124 = v123->timer;
  int v125 = v123->timer;
  int v139 = v125 + 1;
  v123->timer = v139;
  int * v127 = v123->reg_ready;
  int v128 = v127[5];
  int * v129 = v123->regs;
  int v130 = v129[5];
  bool v143 = (v130 ^ -2147483648) < -2147483647;
  int v133;
  if (v143) {
    v133 = 1;
  } else {
    v133 = 0;
  }
  int * v134 = v123->reg_ready;
  int v148 = (v128 + ((v124 - v128) & (~((v124 - v128) >> 31)))) + 1;
  v134[11] = v148;
  int * v136 = v123->regs;
  v136[11] = v133;
  return v123;
}

struct StateT * slot_6(struct StateT * v151) {
  int v152 = v151->timer;
  int v153 = v151->timer;
  int v169 = v153 + 1;
  v151->timer = v169;
  int * v155 = v151->reg_ready;
  int v156 = v155[12];
  int * v157 = v151->regs;
  int v158 = v157[12];
  int * v159 = v151->reg_ready;
  int v160 = v159[14];
  int * v161 = v151->regs;
  int v162 = v161[14];
  int * v163 = v151->reg_ready;
  int v178 = (v160 + (((v156 + ((v152 - v156) & (~((v152 - v156) >> 31)))) - v160) & (~(((v156 + ((v152 - v156) & (~((v152 - v156) >> 31)))) - v160) >> 31)))) + 1;
  v163[6] = v178;
  int * v165 = v151->regs;
  int v180 = v158 + v162;
  v165[6] = v180;
  struct StateT * v167 = slot_7(v151);
  return v167;
}

struct StateT * slot_5(struct StateT * v92) {
  int v93 = v92->timer;
  int v94 = v92->timer;
  int v110 = v94 + 1;
  v92->timer = v110;
  int * v96 = v92->reg_ready;
  int v97 = v96[14];
  int * v98 = v92->regs;
  int v99 = v98[14];
  int * v100 = v92->reg_ready;
  int v101 = v100[15];
  int * v102 = v92->regs;
  int v103 = v102[15];
  bool v117 = v99 >= v103;
  struct StateT * v108;
  if (v117) {
    struct StateT * v104 = slot_14(v92);
    v108 = v104;
  } else {
    struct StateT * v106 = slot_6(v92);
    v108 = v106;
  }
  return v108;
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

struct StateT * slot_7(struct StateT * v183) {
  int v184 = v183->timer;
  int v185 = v183->timer;
  int v320 = v185 + 1;
  v183->timer = v320;
  int * v187 = v183->reg_ready;
  int v188 = v187[6];
  int * v189 = v183->regs;
  int v190 = v189[6];
  int * v191 = v183->cache_tags;
  int v325 = (((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1)) & 1) * 2;
  int v192 = v191[v325];
  int * v193 = v183->cache_tags;
  int v327 = ((((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1)) & 1) * 2) + 1;
  int v194 = v193[v327];
  int * v195 = v183->cache_tags;
  int v329 = 4 + ((((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1)) & 3) * 2);
  int v196 = v195[v329];
  int * v197 = v183->cache_tags;
  int v331 = (4 + ((((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v198 = v197[v331];
  int * v199 = v183->cache_vals;
  bool v332 = !(((~(((v192 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))) | (-(v192 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))))) >> 31)) | (~(((v194 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))) | (-(v194 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))))) >> 31))) == 0);
  int v312;
  if (v332) {
    int * v200 = v183->cache_age;
    int v334 = ((((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1)) & 1) * 2) + ((~(((v194 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))) | (-(v194 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))))) >> 31)) & 1);
    int v201 = v200[v334];
    int * v202 = v183->cache_age;
    int v203 = v202[v325];
    int * v204 = v183->cache_age;
    int v337 = v203 + ((int)((unsigned int)(v203 - v201) >> 31));
    v204[v325] = v337;
    int * v206 = v183->cache_age;
    int v207 = v206[v327];
    int * v208 = v183->cache_age;
    int v340 = v207 + ((int)((unsigned int)(v207 - v201) >> 31));
    v208[v327] = v340;
    int * v210 = v183->cache_age;
    v210[v334] = 0;
    v312 = v334;
  } else {
    int * v213 = v183->cache_age;
    int v344 = (((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1)) & 1) * 2;
    int v214 = v213[v344];
    int * v215 = v183->cache_tags;
    int v216 = v215[v344];
    int * v217 = v183->cache_age;
    int v218 = v217[v327];
    int * v219 = v183->cache_tags;
    int v220 = v219[v327];
    bool v348 = !(((~(((v196 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))) | (-(v196 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))))) >> 31)) | (~(((v198 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))) | (-(v198 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))))) >> 31))) == 0);
    int v284;
    if (v348) {
      int * v221 = v183->cache_age;
      int v350 = (4 + ((((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1)) & 3) * 2)) + ((~(((v198 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))) | (-(v198 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))))) >> 31)) & 1);
      int v222 = v221[v350];
      int * v223 = v183->cache_age;
      int v224 = v223[v329];
      int * v225 = v183->cache_age;
      int v353 = v224 + ((int)((unsigned int)(v224 - v222) >> 31));
      v225[v329] = v353;
      int * v227 = v183->cache_age;
      int v228 = v227[v331];
      int * v229 = v183->cache_age;
      int v356 = v228 + ((int)((unsigned int)(v228 - v222) >> 31));
      v229[v331] = v356;
      int * v231 = v183->cache_age;
      v231[v350] = 0;
      v284 = v350;
    } else {
      int * v234 = v183->cache_age;
      int v360 = 4 + ((((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1)) & 3) * 2);
      int v235 = v234[v360];
      int * v236 = v183->cache_tags;
      int v237 = v236[v360];
      int * v238 = v183->cache_age;
      int v239 = v238[v331];
      int * v240 = v183->cache_tags;
      int v241 = v240[v331];
      int * v242 = v183->cache_dirty;
      int v365 = (4 + ((((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1)) & 3) * 2)) + ((((v235 + ((~(((v237 ^ -1) | (-(v237 ^ -1))) >> 31)) & 2)) - (v239 + ((~(((v241 ^ -1) | (-(v241 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v243 = v242[v365];
      bool v366 = !(v243 == 0);
      if (v366) {
        int * v244 = v183->cache_tags;
        int v245 = v244[v365];
        int * v246 = v183->cache_vals;
        int v369 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1)) & 3) * 2)) + ((((v235 + ((~(((v237 ^ -1) | (-(v237 ^ -1))) >> 31)) & 2)) - (v239 + ((~(((v241 ^ -1) | (-(v241 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v247 = v246[v369];
        int * v248 = v183->cache_vals;
        int v371 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1)) & 3) * 2)) + ((((v235 + ((~(((v237 ^ -1) | (-(v237 ^ -1))) >> 31)) & 2)) - (v239 + ((~(((v241 ^ -1) | (-(v241 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v249 = v248[v371];
        int * v250 = v183->mem;
        int v373 = v245 * 2;
        v250[v373] = v247;
        int * v252 = v183->mem;
        int v376 = (v245 * 2) + 1;
        v252[v376] = v249;
        ;
      } else {
        ;
      }
      int * v257 = v183->mem;
      int v381 = ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1)) * 2;
      int v258 = v257[v381];
      int * v259 = v183->mem;
      int v383 = (((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1)) * 2) + 1;
      int v260 = v259[v383];
      int * v261 = v183->cache_vals;
      int v385 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1)) & 3) * 2)) + ((((v235 + ((~(((v237 ^ -1) | (-(v237 ^ -1))) >> 31)) & 2)) - (v239 + ((~(((v241 ^ -1) | (-(v241 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v261[v385] = v258;
      int * v263 = v183->cache_vals;
      int v388 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1)) & 3) * 2)) + ((((v235 + ((~(((v237 ^ -1) | (-(v237 ^ -1))) >> 31)) & 2)) - (v239 + ((~(((v241 ^ -1) | (-(v241 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v263[v388] = v260;
      int * v265 = v183->cache_tags;
      int v391 = (int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1);
      v265[v365] = v391;
      int * v267 = v183->cache_dirty;
      v267[v365] = 0;
      int * v269 = v183->cache_age;
      v269[v365] = 1;
      int * v271 = v183->cache_age;
      int v272 = v271[v365];
      int * v273 = v183->cache_age;
      int v274 = v273[v329];
      int * v275 = v183->cache_age;
      int v399 = v274 + ((int)((unsigned int)(v274 - v272) >> 31));
      v275[v329] = v399;
      int * v277 = v183->cache_age;
      int v278 = v277[v331];
      int * v279 = v183->cache_age;
      int v402 = v278 + ((int)((unsigned int)(v278 - v272) >> 31));
      v279[v331] = v402;
      int * v281 = v183->cache_age;
      v281[v365] = 0;
      v284 = v365;
    }
    int * v285 = v183->cache_vals;
    int v405 = v284 * 2;
    int v286 = v285[v405];
    int * v287 = v183->cache_vals;
    int v407 = (v284 * 2) + 1;
    int v288 = v287[v407];
    int * v289 = v183->cache_vals;
    int v409 = (((((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1)) & 1) * 2) + ((((v214 + ((~(((v216 ^ -1) | (-(v216 ^ -1))) >> 31)) & 2)) - (v218 + ((~(((v220 ^ -1) | (-(v220 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v289[v409] = v286;
    int * v291 = v183->cache_vals;
    int v412 = ((((((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1)) & 1) * 2) + ((((v214 + ((~(((v216 ^ -1) | (-(v216 ^ -1))) >> 31)) & 2)) - (v218 + ((~(((v220 ^ -1) | (-(v220 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v291[v412] = v288;
    int * v293 = v183->cache_tags;
    int v415 = ((((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1)) & 1) * 2) + ((((v214 + ((~(((v216 ^ -1) | (-(v216 ^ -1))) >> 31)) & 2)) - (v218 + ((~(((v220 ^ -1) | (-(v220 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v416 = (int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1);
    v293[v415] = v416;
    int * v295 = v183->cache_dirty;
    v295[v415] = 0;
    int * v297 = v183->cache_age;
    v297[v415] = 1;
    int * v299 = v183->cache_age;
    int v300 = v299[v415];
    int * v301 = v183->cache_age;
    int v302 = v301[v325];
    int * v303 = v183->cache_age;
    int v424 = v302 + ((int)((unsigned int)(v302 - v300) >> 31));
    v303[v325] = v424;
    int * v305 = v183->cache_age;
    int v306 = v305[v327];
    int * v307 = v183->cache_age;
    int v427 = v306 + ((int)((unsigned int)(v306 - v300) >> 31));
    v307[v327] = v427;
    int * v309 = v183->cache_age;
    v309[v415] = 0;
    v312 = v415;
  }
  int v430 = (v312 * 2) + (((int)((unsigned int)v190 >> 2)) & 1);
  int v313 = v199[v430];
  int * v314 = v183->reg_ready;
  int v433 = ((v188 + ((v184 - v188) & (~((v184 - v188) >> 31)))) + 1) + ((100 ^ (((~(((v196 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))) | (-(v196 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))))) >> 31)) | (~(((v198 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))) | (-(v198 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v192 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))) | (-(v192 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))))) >> 31)) | (~(((v194 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))) | (-(v194 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v196 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))) | (-(v196 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))))) >> 31)) | (~(((v198 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))) | (-(v198 ^ ((int)((unsigned int)((int)((unsigned int)v190 >> 2)) >> 1))))) >> 31))) & 104)))));
  v314[7] = v433;
  int * v316 = v183->regs;
  v316[7] = v313;
  struct StateT * v318 = slot_8(v183);
  return v318;
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
  int v821 = v1->timer;
  int * v822 = v1->reg_ready;
  int v823 = v822[0];
  int v954 = v823 + ((v821 - v823) & (~((v821 - v823) >> 31)));
  v1->timer = v954;
  int v825 = v1->timer;
  int * v826 = v1->reg_ready;
  int v827 = v826[1];
  int v957 = v827 + ((v825 - v827) & (~((v825 - v827) >> 31)));
  v1->timer = v957;
  int v829 = v1->timer;
  int * v830 = v1->reg_ready;
  int v831 = v830[2];
  int v960 = v831 + ((v829 - v831) & (~((v829 - v831) >> 31)));
  v1->timer = v960;
  int v833 = v1->timer;
  int * v834 = v1->reg_ready;
  int v835 = v834[3];
  int v963 = v835 + ((v833 - v835) & (~((v833 - v835) >> 31)));
  v1->timer = v963;
  int v837 = v1->timer;
  int * v838 = v1->reg_ready;
  int v839 = v838[4];
  int v966 = v839 + ((v837 - v839) & (~((v837 - v839) >> 31)));
  v1->timer = v966;
  int v841 = v1->timer;
  int * v842 = v1->reg_ready;
  int v843 = v842[5];
  int v969 = v843 + ((v841 - v843) & (~((v841 - v843) >> 31)));
  v1->timer = v969;
  int v845 = v1->timer;
  int * v846 = v1->reg_ready;
  int v847 = v846[6];
  int v972 = v847 + ((v845 - v847) & (~((v845 - v847) >> 31)));
  v1->timer = v972;
  int v849 = v1->timer;
  int * v850 = v1->reg_ready;
  int v851 = v850[7];
  int v975 = v851 + ((v849 - v851) & (~((v849 - v851) >> 31)));
  v1->timer = v975;
  int v853 = v1->timer;
  int * v854 = v1->reg_ready;
  int v855 = v854[8];
  int v978 = v855 + ((v853 - v855) & (~((v853 - v855) >> 31)));
  v1->timer = v978;
  int v857 = v1->timer;
  int * v858 = v1->reg_ready;
  int v859 = v858[9];
  int v981 = v859 + ((v857 - v859) & (~((v857 - v859) >> 31)));
  v1->timer = v981;
  int v861 = v1->timer;
  int * v862 = v1->reg_ready;
  int v863 = v862[10];
  int v984 = v863 + ((v861 - v863) & (~((v861 - v863) >> 31)));
  v1->timer = v984;
  int v865 = v1->timer;
  int * v866 = v1->reg_ready;
  int v867 = v866[11];
  int v987 = v867 + ((v865 - v867) & (~((v865 - v867) >> 31)));
  v1->timer = v987;
  int v869 = v1->timer;
  int * v870 = v1->reg_ready;
  int v871 = v870[12];
  int v990 = v871 + ((v869 - v871) & (~((v869 - v871) >> 31)));
  v1->timer = v990;
  int v873 = v1->timer;
  int * v874 = v1->reg_ready;
  int v875 = v874[13];
  int v993 = v875 + ((v873 - v875) & (~((v873 - v875) >> 31)));
  v1->timer = v993;
  int v877 = v1->timer;
  int * v878 = v1->reg_ready;
  int v879 = v878[14];
  int v996 = v879 + ((v877 - v879) & (~((v877 - v879) >> 31)));
  v1->timer = v996;
  int v881 = v1->timer;
  int * v882 = v1->reg_ready;
  int v883 = v882[15];
  int v999 = v883 + ((v881 - v883) & (~((v881 - v883) >> 31)));
  v1->timer = v999;
  int v885 = v1->timer;
  int * v886 = v1->reg_ready;
  int v887 = v886[16];
  int v1002 = v887 + ((v885 - v887) & (~((v885 - v887) >> 31)));
  v1->timer = v1002;
  int v889 = v1->timer;
  int * v890 = v1->reg_ready;
  int v891 = v890[17];
  int v1005 = v891 + ((v889 - v891) & (~((v889 - v891) >> 31)));
  v1->timer = v1005;
  int v893 = v1->timer;
  int * v894 = v1->reg_ready;
  int v895 = v894[18];
  int v1008 = v895 + ((v893 - v895) & (~((v893 - v895) >> 31)));
  v1->timer = v1008;
  int v897 = v1->timer;
  int * v898 = v1->reg_ready;
  int v899 = v898[19];
  int v1011 = v899 + ((v897 - v899) & (~((v897 - v899) >> 31)));
  v1->timer = v1011;
  int v901 = v1->timer;
  int * v902 = v1->reg_ready;
  int v903 = v902[20];
  int v1014 = v903 + ((v901 - v903) & (~((v901 - v903) >> 31)));
  v1->timer = v1014;
  int v905 = v1->timer;
  int * v906 = v1->reg_ready;
  int v907 = v906[21];
  int v1017 = v907 + ((v905 - v907) & (~((v905 - v907) >> 31)));
  v1->timer = v1017;
  int v909 = v1->timer;
  int * v910 = v1->reg_ready;
  int v911 = v910[22];
  int v1020 = v911 + ((v909 - v911) & (~((v909 - v911) >> 31)));
  v1->timer = v1020;
  int v913 = v1->timer;
  int * v914 = v1->reg_ready;
  int v915 = v914[23];
  int v1023 = v915 + ((v913 - v915) & (~((v913 - v915) >> 31)));
  v1->timer = v1023;
  int v917 = v1->timer;
  int * v918 = v1->reg_ready;
  int v919 = v918[24];
  int v1026 = v919 + ((v917 - v919) & (~((v917 - v919) >> 31)));
  v1->timer = v1026;
  int v921 = v1->timer;
  int * v922 = v1->reg_ready;
  int v923 = v922[25];
  int v1029 = v923 + ((v921 - v923) & (~((v921 - v923) >> 31)));
  v1->timer = v1029;
  int v925 = v1->timer;
  int * v926 = v1->reg_ready;
  int v927 = v926[26];
  int v1032 = v927 + ((v925 - v927) & (~((v925 - v927) >> 31)));
  v1->timer = v1032;
  int v929 = v1->timer;
  int * v930 = v1->reg_ready;
  int v931 = v930[27];
  int v1035 = v931 + ((v929 - v931) & (~((v929 - v931) >> 31)));
  v1->timer = v1035;
  int v933 = v1->timer;
  int * v934 = v1->reg_ready;
  int v935 = v934[28];
  int v1038 = v935 + ((v933 - v935) & (~((v933 - v935) >> 31)));
  v1->timer = v1038;
  int v937 = v1->timer;
  int * v938 = v1->reg_ready;
  int v939 = v938[29];
  int v1041 = v939 + ((v937 - v939) & (~((v937 - v939) >> 31)));
  v1->timer = v1041;
  int v941 = v1->timer;
  int * v942 = v1->reg_ready;
  int v943 = v942[30];
  int v1044 = v943 + ((v941 - v943) & (~((v941 - v943) >> 31)));
  v1->timer = v1044;
  int v945 = v1->timer;
  int * v946 = v1->reg_ready;
  int v947 = v946[31];
  int v1047 = v947 + ((v945 - v947) & (~((v945 - v947) >> 31)));
  v1->timer = v1047;
  return v1;
}

struct StateT * slot_10(struct StateT * v725) {
  int v726 = v725->timer;
  int v727 = v725->timer;
  int v743 = v727 + 1;
  v725->timer = v743;
  int * v729 = v725->reg_ready;
  int v730 = v729[7];
  int * v731 = v725->regs;
  int v732 = v731[7];
  int * v733 = v725->reg_ready;
  int v734 = v733[9];
  int * v735 = v725->regs;
  int v736 = v735[9];
  int * v737 = v725->reg_ready;
  int v752 = (v734 + (((v730 + ((v726 - v730) & (~((v726 - v730) >> 31)))) - v734) & (~(((v730 + ((v726 - v730) & (~((v726 - v730) >> 31)))) - v734) >> 31)))) + 1;
  v737[16] = v752;
  int * v739 = v725->regs;
  int v754 = v732 ^ v736;
  v739[16] = v754;
  struct StateT * v741 = slot_11(v725);
  return v741;
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

struct StateT * slot_8(struct StateT * v438) {
  int v439 = v438->timer;
  int v440 = v438->timer;
  int v456 = v440 + 1;
  v438->timer = v456;
  int * v442 = v438->reg_ready;
  int v443 = v442[13];
  int * v444 = v438->regs;
  int v445 = v444[13];
  int * v446 = v438->reg_ready;
  int v447 = v446[14];
  int * v448 = v438->regs;
  int v449 = v448[14];
  int * v450 = v438->reg_ready;
  int v465 = (v447 + (((v443 + ((v439 - v443) & (~((v439 - v443) >> 31)))) - v447) & (~(((v443 + ((v439 - v443) & (~((v439 - v443) >> 31)))) - v447) >> 31)))) + 1;
  v450[8] = v465;
  int * v452 = v438->regs;
  int v467 = v445 + v449;
  v452[8] = v467;
  struct StateT * v454 = slot_9(v438);
  return v454;
}

struct StateT * slot_4(struct StateT * v74) {
  int v75 = v74->timer;
  int v76 = v74->timer;
  int v84 = v76 + 1;
  v74->timer = v84;
  int * v78 = v74->reg_ready;
  int v87 = v75 + 1;
  v78[5] = v87;
  int * v80 = v74->regs;
  v80[5] = 0;
  struct StateT * v82 = slot_5(v74);
  return v82;
}

struct StateT * slot_13(struct StateT * v812) {
  int v813 = v812->timer;
  int v814 = v812->timer;
  int v818 = v814 + 1;
  v812->timer = v818;
  struct StateT * v816 = slot_5(v812);
  return v816;
}

struct StateT * slot_9(struct StateT * v470) {
  int v471 = v470->timer;
  int v472 = v470->timer;
  int v607 = v472 + 1;
  v470->timer = v607;
  int * v474 = v470->reg_ready;
  int v475 = v474[8];
  int * v476 = v470->regs;
  int v477 = v476[8];
  int * v478 = v470->cache_tags;
  int v612 = (((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1)) & 1) * 2;
  int v479 = v478[v612];
  int * v480 = v470->cache_tags;
  int v614 = ((((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1)) & 1) * 2) + 1;
  int v481 = v480[v614];
  int * v482 = v470->cache_tags;
  int v616 = 4 + ((((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1)) & 3) * 2);
  int v483 = v482[v616];
  int * v484 = v470->cache_tags;
  int v618 = (4 + ((((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v485 = v484[v618];
  int * v486 = v470->cache_vals;
  bool v619 = !(((~(((v479 ^ ((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1))) | (-(v479 ^ ((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1))))) >> 31)) | (~(((v481 ^ ((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1))) | (-(v481 ^ ((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1))))) >> 31))) == 0);
  int v599;
  if (v619) {
    int * v487 = v470->cache_age;
    int v621 = ((((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1)) & 1) * 2) + ((~(((v481 ^ ((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1))) | (-(v481 ^ ((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1))))) >> 31)) & 1);
    int v488 = v487[v621];
    int * v489 = v470->cache_age;
    int v490 = v489[v612];
    int * v491 = v470->cache_age;
    int v624 = v490 + ((int)((unsigned int)(v490 - v488) >> 31));
    v491[v612] = v624;
    int * v493 = v470->cache_age;
    int v494 = v493[v614];
    int * v495 = v470->cache_age;
    int v627 = v494 + ((int)((unsigned int)(v494 - v488) >> 31));
    v495[v614] = v627;
    int * v497 = v470->cache_age;
    v497[v621] = 0;
    v599 = v621;
  } else {
    int * v500 = v470->cache_age;
    int v631 = (((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1)) & 1) * 2;
    int v501 = v500[v631];
    int * v502 = v470->cache_tags;
    int v503 = v502[v631];
    int * v504 = v470->cache_age;
    int v505 = v504[v614];
    int * v506 = v470->cache_tags;
    int v507 = v506[v614];
    bool v635 = !(((~(((v483 ^ ((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1))) | (-(v483 ^ ((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1))))) >> 31)) | (~(((v485 ^ ((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1))) | (-(v485 ^ ((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1))))) >> 31))) == 0);
    int v571;
    if (v635) {
      int * v508 = v470->cache_age;
      int v637 = (4 + ((((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1)) & 3) * 2)) + ((~(((v485 ^ ((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1))) | (-(v485 ^ ((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1))))) >> 31)) & 1);
      int v509 = v508[v637];
      int * v510 = v470->cache_age;
      int v511 = v510[v616];
      int * v512 = v470->cache_age;
      int v640 = v511 + ((int)((unsigned int)(v511 - v509) >> 31));
      v512[v616] = v640;
      int * v514 = v470->cache_age;
      int v515 = v514[v618];
      int * v516 = v470->cache_age;
      int v643 = v515 + ((int)((unsigned int)(v515 - v509) >> 31));
      v516[v618] = v643;
      int * v518 = v470->cache_age;
      v518[v637] = 0;
      v571 = v637;
    } else {
      int * v521 = v470->cache_age;
      int v647 = 4 + ((((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1)) & 3) * 2);
      int v522 = v521[v647];
      int * v523 = v470->cache_tags;
      int v524 = v523[v647];
      int * v525 = v470->cache_age;
      int v526 = v525[v618];
      int * v527 = v470->cache_tags;
      int v528 = v527[v618];
      int * v529 = v470->cache_dirty;
      int v652 = (4 + ((((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1)) & 3) * 2)) + ((((v522 + ((~(((v524 ^ -1) | (-(v524 ^ -1))) >> 31)) & 2)) - (v526 + ((~(((v528 ^ -1) | (-(v528 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v530 = v529[v652];
      bool v653 = !(v530 == 0);
      if (v653) {
        int * v531 = v470->cache_tags;
        int v532 = v531[v652];
        int * v533 = v470->cache_vals;
        int v656 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1)) & 3) * 2)) + ((((v522 + ((~(((v524 ^ -1) | (-(v524 ^ -1))) >> 31)) & 2)) - (v526 + ((~(((v528 ^ -1) | (-(v528 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v534 = v533[v656];
        int * v535 = v470->cache_vals;
        int v658 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1)) & 3) * 2)) + ((((v522 + ((~(((v524 ^ -1) | (-(v524 ^ -1))) >> 31)) & 2)) - (v526 + ((~(((v528 ^ -1) | (-(v528 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v536 = v535[v658];
        int * v537 = v470->mem;
        int v660 = v532 * 2;
        v537[v660] = v534;
        int * v539 = v470->mem;
        int v663 = (v532 * 2) + 1;
        v539[v663] = v536;
        ;
      } else {
        ;
      }
      int * v544 = v470->mem;
      int v668 = ((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1)) * 2;
      int v545 = v544[v668];
      int * v546 = v470->mem;
      int v670 = (((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1)) * 2) + 1;
      int v547 = v546[v670];
      int * v548 = v470->cache_vals;
      int v672 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1)) & 3) * 2)) + ((((v522 + ((~(((v524 ^ -1) | (-(v524 ^ -1))) >> 31)) & 2)) - (v526 + ((~(((v528 ^ -1) | (-(v528 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v548[v672] = v545;
      int * v550 = v470->cache_vals;
      int v675 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1)) & 3) * 2)) + ((((v522 + ((~(((v524 ^ -1) | (-(v524 ^ -1))) >> 31)) & 2)) - (v526 + ((~(((v528 ^ -1) | (-(v528 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v550[v675] = v547;
      int * v552 = v470->cache_tags;
      int v678 = (int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1);
      v552[v652] = v678;
      int * v554 = v470->cache_dirty;
      v554[v652] = 0;
      int * v556 = v470->cache_age;
      v556[v652] = 1;
      int * v558 = v470->cache_age;
      int v559 = v558[v652];
      int * v560 = v470->cache_age;
      int v561 = v560[v616];
      int * v562 = v470->cache_age;
      int v686 = v561 + ((int)((unsigned int)(v561 - v559) >> 31));
      v562[v616] = v686;
      int * v564 = v470->cache_age;
      int v565 = v564[v618];
      int * v566 = v470->cache_age;
      int v689 = v565 + ((int)((unsigned int)(v565 - v559) >> 31));
      v566[v618] = v689;
      int * v568 = v470->cache_age;
      v568[v652] = 0;
      v571 = v652;
    }
    int * v572 = v470->cache_vals;
    int v692 = v571 * 2;
    int v573 = v572[v692];
    int * v574 = v470->cache_vals;
    int v694 = (v571 * 2) + 1;
    int v575 = v574[v694];
    int * v576 = v470->cache_vals;
    int v696 = (((((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1)) & 1) * 2) + ((((v501 + ((~(((v503 ^ -1) | (-(v503 ^ -1))) >> 31)) & 2)) - (v505 + ((~(((v507 ^ -1) | (-(v507 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v576[v696] = v573;
    int * v578 = v470->cache_vals;
    int v699 = ((((((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1)) & 1) * 2) + ((((v501 + ((~(((v503 ^ -1) | (-(v503 ^ -1))) >> 31)) & 2)) - (v505 + ((~(((v507 ^ -1) | (-(v507 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v578[v699] = v575;
    int * v580 = v470->cache_tags;
    int v702 = ((((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1)) & 1) * 2) + ((((v501 + ((~(((v503 ^ -1) | (-(v503 ^ -1))) >> 31)) & 2)) - (v505 + ((~(((v507 ^ -1) | (-(v507 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v703 = (int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1);
    v580[v702] = v703;
    int * v582 = v470->cache_dirty;
    v582[v702] = 0;
    int * v584 = v470->cache_age;
    v584[v702] = 1;
    int * v586 = v470->cache_age;
    int v587 = v586[v702];
    int * v588 = v470->cache_age;
    int v589 = v588[v612];
    int * v590 = v470->cache_age;
    int v711 = v589 + ((int)((unsigned int)(v589 - v587) >> 31));
    v590[v612] = v711;
    int * v592 = v470->cache_age;
    int v593 = v592[v614];
    int * v594 = v470->cache_age;
    int v714 = v593 + ((int)((unsigned int)(v593 - v587) >> 31));
    v594[v614] = v714;
    int * v596 = v470->cache_age;
    v596[v702] = 0;
    v599 = v702;
  }
  int v717 = (v599 * 2) + (((int)((unsigned int)v477 >> 2)) & 1);
  int v600 = v486[v717];
  int * v601 = v470->reg_ready;
  int v720 = ((v475 + ((v471 - v475) & (~((v471 - v475) >> 31)))) + 1) + ((100 ^ (((~(((v483 ^ ((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1))) | (-(v483 ^ ((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1))))) >> 31)) | (~(((v485 ^ ((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1))) | (-(v485 ^ ((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v479 ^ ((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1))) | (-(v479 ^ ((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1))))) >> 31)) | (~(((v481 ^ ((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1))) | (-(v481 ^ ((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v483 ^ ((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1))) | (-(v483 ^ ((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1))))) >> 31)) | (~(((v485 ^ ((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1))) | (-(v485 ^ ((int)((unsigned int)((int)((unsigned int)v477 >> 2)) >> 1))))) >> 31))) & 104)))));
  v601[9] = v720;
  int * v603 = v470->regs;
  v603[9] = v600;
  struct StateT * v605 = slot_10(v470);
  return v605;
}

struct StateT * slot_11(struct StateT * v757) {
  int v758 = v757->timer;
  int v759 = v757->timer;
  int v775 = v759 + 1;
  v757->timer = v775;
  int * v761 = v757->reg_ready;
  int v762 = v761[5];
  int * v763 = v757->regs;
  int v764 = v763[5];
  int * v765 = v757->reg_ready;
  int v766 = v765[16];
  int * v767 = v757->regs;
  int v768 = v767[16];
  int * v769 = v757->reg_ready;
  int v783 = (v766 + (((v762 + ((v758 - v762) & (~((v758 - v762) >> 31)))) - v766) & (~(((v762 + ((v758 - v762) & (~((v758 - v762) >> 31)))) - v766) >> 31)))) + 1;
  v769[5] = v783;
  int * v771 = v757->regs;
  int v785 = v764 | v768;
  v771[5] = v785;
  struct StateT * v773 = slot_12(v757);
  return v773;
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
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}