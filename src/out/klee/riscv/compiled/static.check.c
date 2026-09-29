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

struct StateT * slot_6(struct StateT * v96);
struct StateT * slot_16(struct StateT * v760);
struct StateT * slot_5(struct StateT * v76);
struct StateT * slot_2(struct StateT * v32);
struct StateT * slot_7(struct StateT * v112);
struct StateT * slot_21(struct StateT * v854);
struct StateT * slot_3(struct StateT * v40);
struct StateT * slot_10(struct StateT * v678);
struct StateT * slot_1(struct StateT * v19);
struct StateT * slot_19(struct StateT * v829);
struct StateT * slot_13(struct StateT * v691);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v714);
struct StateT * slot_17(struct StateT * v808);
struct StateT * slot_20(struct StateT * v834);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v369);
struct StateT * slot_4(struct StateT * v60);
struct StateT * slot_15(struct StateT * v737);
struct StateT * slot_18(struct StateT * v821);
struct StateT * slot_9(struct StateT * v626);
struct StateT * slot_22(struct StateT * v1104);
struct StateT * slot_11(struct StateT * v683);
struct StateT * slot_6(struct StateT * v96) {
  int v97 = v96->timer;
  int v105 = v97 + 1;
  v96->timer = v105;
  int * v99 = v96->regs;
  int v100 = v99[13];
  int * v101 = v96->regs;
  v101[13] = v100;
  struct StateT * v103 = slot_7(v96);
  return v103;
}

struct StateT * slot_16(struct StateT * v760) {
  int * v761 = v760->regs;
  int v762 = v761[14];
  int * v763 = v760->regs;
  int v764 = v763[15];
  bool v789 = !(v762 == v764);
  struct StateT * v783;
  if (v789) {
    int v765 = v760->timer;
    int v790 = v765 + 15;
    v760->timer = v790;
    int * v767 = v760->saved_regs;
    int v768 = v767[11];
    int * v769 = v760->regs;
    v769[11] = v768;
    int * v771 = v760->saved_regs;
    int v772 = v771[12];
    int * v773 = v760->regs;
    v773[12] = v772;
    int * v775 = v760->saved_regs;
    int v776 = v775[13];
    int * v777 = v760->regs;
    v777[13] = v776;
    struct StateT * v779 = slot_17(v760);
    v783 = v779;
  } else {
    struct StateT * v781 = slot_18(v760);
    v783 = v781;
  }
  return v783;
}

struct StateT * slot_5(struct StateT * v76) {
  int * v77 = v76->saved_regs;
  int * v78 = v76->regs;
  int v79 = v78[13];
  v77[13] = v79;
  int v81 = v76->timer;
  int v91 = v81 + 1;
  v76->timer = v91;
  int * v83 = v76->regs;
  v83[13] = 0;
  struct StateT * v85 = slot_6(v76);
  return v85;
}

struct StateT * slot_2(struct StateT * v32) {
  int v33 = v32->timer;
  int v37 = v33 + 1;
  v32->timer = v37;
  struct StateT * v35 = slot_3(v32);
  return v35;
}

struct StateT * slot_7(struct StateT * v112) {
  int * v113 = v112->saved_regs;
  int * v114 = v112->regs;
  int v115 = v114[14];
  v113[14] = v115;
  int v117 = v112->timer;
  int v254 = v117 + 1;
  v112->timer = v254;
  int * v119 = v112->regs;
  int v120 = v119[12];
  int * v121 = v112->cache_tags;
  int v258 = (((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1)) & 1) * 2;
  int v122 = v121[v258];
  int * v123 = v112->cache_tags;
  int v260 = ((((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1)) & 1) * 2) + 1;
  int v124 = v123[v260];
  int * v125 = v112->cache_tags;
  int v262 = 4 + ((((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1)) & 3) * 2);
  int v126 = v125[v262];
  int * v127 = v112->cache_tags;
  int v264 = (4 + ((((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v128 = v127[v264];
  int v129 = v112->timer;
  int v265 = v129 + ((100 ^ (((~(((v126 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))) | (-(v126 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))))) >> 31)) | (~(((v128 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))) | (-(v128 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v122 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))) | (-(v122 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))))) >> 31)) | (~(((v124 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))) | (-(v124 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v126 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))) | (-(v126 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))))) >> 31)) | (~(((v128 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))) | (-(v128 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))))) >> 31))) & 104)))));
  v112->timer = v265;
  int * v131 = v112->cache_vals;
  bool v266 = !(((~(((v122 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))) | (-(v122 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))))) >> 31)) | (~(((v124 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))) | (-(v124 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))))) >> 31))) == 0);
  int v244;
  if (v266) {
    int * v132 = v112->cache_age;
    int v268 = ((((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1)) & 1) * 2) + ((~(((v124 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))) | (-(v124 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))))) >> 31)) & 1);
    int v133 = v132[v268];
    int * v134 = v112->cache_age;
    int v135 = v134[v258];
    int * v136 = v112->cache_age;
    int v271 = v135 + ((int)((unsigned int)(v135 - v133) >> 31));
    v136[v258] = v271;
    int * v138 = v112->cache_age;
    int v139 = v138[v260];
    int * v140 = v112->cache_age;
    int v274 = v139 + ((int)((unsigned int)(v139 - v133) >> 31));
    v140[v260] = v274;
    int * v142 = v112->cache_age;
    v142[v268] = 0;
    v244 = v268;
  } else {
    int * v145 = v112->cache_age;
    int v278 = (((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1)) & 1) * 2;
    int v146 = v145[v278];
    int * v147 = v112->cache_tags;
    int v148 = v147[v278];
    int * v149 = v112->cache_age;
    int v150 = v149[v260];
    int * v151 = v112->cache_tags;
    int v152 = v151[v260];
    bool v282 = !(((~(((v126 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))) | (-(v126 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))))) >> 31)) | (~(((v128 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))) | (-(v128 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))))) >> 31))) == 0);
    int v216;
    if (v282) {
      int * v153 = v112->cache_age;
      int v284 = (4 + ((((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1)) & 3) * 2)) + ((~(((v128 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))) | (-(v128 ^ ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1))))) >> 31)) & 1);
      int v154 = v153[v284];
      int * v155 = v112->cache_age;
      int v156 = v155[v262];
      int * v157 = v112->cache_age;
      int v287 = v156 + ((int)((unsigned int)(v156 - v154) >> 31));
      v157[v262] = v287;
      int * v159 = v112->cache_age;
      int v160 = v159[v264];
      int * v161 = v112->cache_age;
      int v290 = v160 + ((int)((unsigned int)(v160 - v154) >> 31));
      v161[v264] = v290;
      int * v163 = v112->cache_age;
      v163[v284] = 0;
      v216 = v284;
    } else {
      int * v166 = v112->cache_age;
      int v294 = 4 + ((((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1)) & 3) * 2);
      int v167 = v166[v294];
      int * v168 = v112->cache_tags;
      int v169 = v168[v294];
      int * v170 = v112->cache_age;
      int v171 = v170[v264];
      int * v172 = v112->cache_tags;
      int v173 = v172[v264];
      int * v174 = v112->cache_dirty;
      int v299 = (4 + ((((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1)) & 3) * 2)) + ((((v167 + ((~(((v169 ^ -1) | (-(v169 ^ -1))) >> 31)) & 2)) - (v171 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v175 = v174[v299];
      bool v300 = !(v175 == 0);
      if (v300) {
        int * v176 = v112->cache_tags;
        int v177 = v176[v299];
        int * v178 = v112->cache_vals;
        int v303 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1)) & 3) * 2)) + ((((v167 + ((~(((v169 ^ -1) | (-(v169 ^ -1))) >> 31)) & 2)) - (v171 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v179 = v178[v303];
        int * v180 = v112->cache_vals;
        int v305 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1)) & 3) * 2)) + ((((v167 + ((~(((v169 ^ -1) | (-(v169 ^ -1))) >> 31)) & 2)) - (v171 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v181 = v180[v305];
        int * v182 = v112->mem;
        int v307 = v177 * 2;
        v182[v307] = v179;
        int * v184 = v112->mem;
        int v310 = (v177 * 2) + 1;
        v184[v310] = v181;
        ;
      } else {
        ;
      }
      int * v189 = v112->mem;
      int v315 = ((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1)) * 2;
      int v190 = v189[v315];
      int * v191 = v112->mem;
      int v317 = (((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1)) * 2) + 1;
      int v192 = v191[v317];
      int * v193 = v112->cache_vals;
      int v319 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1)) & 3) * 2)) + ((((v167 + ((~(((v169 ^ -1) | (-(v169 ^ -1))) >> 31)) & 2)) - (v171 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v193[v319] = v190;
      int * v195 = v112->cache_vals;
      int v322 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1)) & 3) * 2)) + ((((v167 + ((~(((v169 ^ -1) | (-(v169 ^ -1))) >> 31)) & 2)) - (v171 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v195[v322] = v192;
      int * v197 = v112->cache_tags;
      int v325 = (int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1);
      v197[v299] = v325;
      int * v199 = v112->cache_dirty;
      v199[v299] = 0;
      int * v201 = v112->cache_age;
      v201[v299] = 1;
      int * v203 = v112->cache_age;
      int v204 = v203[v299];
      int * v205 = v112->cache_age;
      int v206 = v205[v262];
      int * v207 = v112->cache_age;
      int v333 = v206 + ((int)((unsigned int)(v206 - v204) >> 31));
      v207[v262] = v333;
      int * v209 = v112->cache_age;
      int v210 = v209[v264];
      int * v211 = v112->cache_age;
      int v336 = v210 + ((int)((unsigned int)(v210 - v204) >> 31));
      v211[v264] = v336;
      int * v213 = v112->cache_age;
      v213[v299] = 0;
      v216 = v299;
    }
    int * v217 = v112->cache_vals;
    int v339 = v216 * 2;
    int v218 = v217[v339];
    int * v219 = v112->cache_vals;
    int v341 = (v216 * 2) + 1;
    int v220 = v219[v341];
    int * v221 = v112->cache_vals;
    int v343 = (((((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1)) & 1) * 2) + ((((v146 + ((~(((v148 ^ -1) | (-(v148 ^ -1))) >> 31)) & 2)) - (v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v221[v343] = v218;
    int * v223 = v112->cache_vals;
    int v346 = ((((((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1)) & 1) * 2) + ((((v146 + ((~(((v148 ^ -1) | (-(v148 ^ -1))) >> 31)) & 2)) - (v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v223[v346] = v220;
    int * v225 = v112->cache_tags;
    int v349 = ((((int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1)) & 1) * 2) + ((((v146 + ((~(((v148 ^ -1) | (-(v148 ^ -1))) >> 31)) & 2)) - (v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v350 = (int)((unsigned int)((int)((unsigned int)v120 >> 2)) >> 1);
    v225[v349] = v350;
    int * v227 = v112->cache_dirty;
    v227[v349] = 0;
    int * v229 = v112->cache_age;
    v229[v349] = 1;
    int * v231 = v112->cache_age;
    int v232 = v231[v349];
    int * v233 = v112->cache_age;
    int v234 = v233[v258];
    int * v235 = v112->cache_age;
    int v358 = v234 + ((int)((unsigned int)(v234 - v232) >> 31));
    v235[v258] = v358;
    int * v237 = v112->cache_age;
    int v238 = v237[v260];
    int * v239 = v112->cache_age;
    int v361 = v238 + ((int)((unsigned int)(v238 - v232) >> 31));
    v239[v260] = v361;
    int * v241 = v112->cache_age;
    v241[v349] = 0;
    v244 = v349;
  }
  int v364 = (v244 * 2) + (((int)((unsigned int)v120 >> 2)) & 1);
  int v245 = v131[v364];
  int * v246 = v112->regs;
  v246[14] = v245;
  struct StateT * v248 = slot_8(v112);
  return v248;
}

struct StateT * slot_21(struct StateT * v854) {
  int v855 = v854->timer;
  int v988 = v855 + 1;
  v854->timer = v988;
  int * v857 = v854->regs;
  int v858 = v857[12];
  int * v859 = v854->cache_tags;
  int v992 = (((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1)) & 1) * 2;
  int v860 = v859[v992];
  int * v861 = v854->cache_tags;
  int v994 = ((((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1)) & 1) * 2) + 1;
  int v862 = v861[v994];
  int * v863 = v854->cache_tags;
  int v996 = 4 + ((((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1)) & 3) * 2);
  int v864 = v863[v996];
  int * v865 = v854->cache_tags;
  int v998 = (4 + ((((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v866 = v865[v998];
  int v867 = v854->timer;
  int v999 = v867 + ((100 ^ (((~(((v864 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))) | (-(v864 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))))) >> 31)) | (~(((v866 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))) | (-(v866 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v860 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))) | (-(v860 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))))) >> 31)) | (~(((v862 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))) | (-(v862 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v864 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))) | (-(v864 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))))) >> 31)) | (~(((v866 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))) | (-(v866 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))))) >> 31))) & 104)))));
  v854->timer = v999;
  int * v869 = v854->cache_vals;
  bool v1000 = !(((~(((v860 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))) | (-(v860 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))))) >> 31)) | (~(((v862 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))) | (-(v862 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))))) >> 31))) == 0);
  int v982;
  if (v1000) {
    int * v870 = v854->cache_age;
    int v1002 = ((((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1)) & 1) * 2) + ((~(((v862 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))) | (-(v862 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))))) >> 31)) & 1);
    int v871 = v870[v1002];
    int * v872 = v854->cache_age;
    int v873 = v872[v992];
    int * v874 = v854->cache_age;
    int v1005 = v873 + ((int)((unsigned int)(v873 - v871) >> 31));
    v874[v992] = v1005;
    int * v876 = v854->cache_age;
    int v877 = v876[v994];
    int * v878 = v854->cache_age;
    int v1008 = v877 + ((int)((unsigned int)(v877 - v871) >> 31));
    v878[v994] = v1008;
    int * v880 = v854->cache_age;
    v880[v1002] = 0;
    v982 = v1002;
  } else {
    int * v883 = v854->cache_age;
    int v1012 = (((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1)) & 1) * 2;
    int v884 = v883[v1012];
    int * v885 = v854->cache_tags;
    int v886 = v885[v1012];
    int * v887 = v854->cache_age;
    int v888 = v887[v994];
    int * v889 = v854->cache_tags;
    int v890 = v889[v994];
    bool v1016 = !(((~(((v864 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))) | (-(v864 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))))) >> 31)) | (~(((v866 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))) | (-(v866 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))))) >> 31))) == 0);
    int v954;
    if (v1016) {
      int * v891 = v854->cache_age;
      int v1018 = (4 + ((((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1)) & 3) * 2)) + ((~(((v866 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))) | (-(v866 ^ ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1))))) >> 31)) & 1);
      int v892 = v891[v1018];
      int * v893 = v854->cache_age;
      int v894 = v893[v996];
      int * v895 = v854->cache_age;
      int v1021 = v894 + ((int)((unsigned int)(v894 - v892) >> 31));
      v895[v996] = v1021;
      int * v897 = v854->cache_age;
      int v898 = v897[v998];
      int * v899 = v854->cache_age;
      int v1024 = v898 + ((int)((unsigned int)(v898 - v892) >> 31));
      v899[v998] = v1024;
      int * v901 = v854->cache_age;
      v901[v1018] = 0;
      v954 = v1018;
    } else {
      int * v904 = v854->cache_age;
      int v1028 = 4 + ((((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1)) & 3) * 2);
      int v905 = v904[v1028];
      int * v906 = v854->cache_tags;
      int v907 = v906[v1028];
      int * v908 = v854->cache_age;
      int v909 = v908[v998];
      int * v910 = v854->cache_tags;
      int v911 = v910[v998];
      int * v912 = v854->cache_dirty;
      int v1033 = (4 + ((((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1)) & 3) * 2)) + ((((v905 + ((~(((v907 ^ -1) | (-(v907 ^ -1))) >> 31)) & 2)) - (v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v913 = v912[v1033];
      bool v1034 = !(v913 == 0);
      if (v1034) {
        int * v914 = v854->cache_tags;
        int v915 = v914[v1033];
        int * v916 = v854->cache_vals;
        int v1037 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1)) & 3) * 2)) + ((((v905 + ((~(((v907 ^ -1) | (-(v907 ^ -1))) >> 31)) & 2)) - (v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v917 = v916[v1037];
        int * v918 = v854->cache_vals;
        int v1039 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1)) & 3) * 2)) + ((((v905 + ((~(((v907 ^ -1) | (-(v907 ^ -1))) >> 31)) & 2)) - (v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v919 = v918[v1039];
        int * v920 = v854->mem;
        int v1041 = v915 * 2;
        v920[v1041] = v917;
        int * v922 = v854->mem;
        int v1044 = (v915 * 2) + 1;
        v922[v1044] = v919;
        ;
      } else {
        ;
      }
      int * v927 = v854->mem;
      int v1049 = ((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1)) * 2;
      int v928 = v927[v1049];
      int * v929 = v854->mem;
      int v1051 = (((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1)) * 2) + 1;
      int v930 = v929[v1051];
      int * v931 = v854->cache_vals;
      int v1053 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1)) & 3) * 2)) + ((((v905 + ((~(((v907 ^ -1) | (-(v907 ^ -1))) >> 31)) & 2)) - (v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v931[v1053] = v928;
      int * v933 = v854->cache_vals;
      int v1056 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1)) & 3) * 2)) + ((((v905 + ((~(((v907 ^ -1) | (-(v907 ^ -1))) >> 31)) & 2)) - (v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v933[v1056] = v930;
      int * v935 = v854->cache_tags;
      int v1059 = (int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1);
      v935[v1033] = v1059;
      int * v937 = v854->cache_dirty;
      v937[v1033] = 0;
      int * v939 = v854->cache_age;
      v939[v1033] = 1;
      int * v941 = v854->cache_age;
      int v942 = v941[v1033];
      int * v943 = v854->cache_age;
      int v944 = v943[v996];
      int * v945 = v854->cache_age;
      int v1067 = v944 + ((int)((unsigned int)(v944 - v942) >> 31));
      v945[v996] = v1067;
      int * v947 = v854->cache_age;
      int v948 = v947[v998];
      int * v949 = v854->cache_age;
      int v1070 = v948 + ((int)((unsigned int)(v948 - v942) >> 31));
      v949[v998] = v1070;
      int * v951 = v854->cache_age;
      v951[v1033] = 0;
      v954 = v1033;
    }
    int * v955 = v854->cache_vals;
    int v1073 = v954 * 2;
    int v956 = v955[v1073];
    int * v957 = v854->cache_vals;
    int v1075 = (v954 * 2) + 1;
    int v958 = v957[v1075];
    int * v959 = v854->cache_vals;
    int v1077 = (((((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1)) & 1) * 2) + ((((v884 + ((~(((v886 ^ -1) | (-(v886 ^ -1))) >> 31)) & 2)) - (v888 + ((~(((v890 ^ -1) | (-(v890 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v959[v1077] = v956;
    int * v961 = v854->cache_vals;
    int v1080 = ((((((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1)) & 1) * 2) + ((((v884 + ((~(((v886 ^ -1) | (-(v886 ^ -1))) >> 31)) & 2)) - (v888 + ((~(((v890 ^ -1) | (-(v890 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v961[v1080] = v958;
    int * v963 = v854->cache_tags;
    int v1083 = ((((int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1)) & 1) * 2) + ((((v884 + ((~(((v886 ^ -1) | (-(v886 ^ -1))) >> 31)) & 2)) - (v888 + ((~(((v890 ^ -1) | (-(v890 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1084 = (int)((unsigned int)((int)((unsigned int)v858 >> 2)) >> 1);
    v963[v1083] = v1084;
    int * v965 = v854->cache_dirty;
    v965[v1083] = 0;
    int * v967 = v854->cache_age;
    v967[v1083] = 1;
    int * v969 = v854->cache_age;
    int v970 = v969[v1083];
    int * v971 = v854->cache_age;
    int v972 = v971[v992];
    int * v973 = v854->cache_age;
    int v1092 = v972 + ((int)((unsigned int)(v972 - v970) >> 31));
    v973[v992] = v1092;
    int * v975 = v854->cache_age;
    int v976 = v975[v994];
    int * v977 = v854->cache_age;
    int v1095 = v976 + ((int)((unsigned int)(v976 - v970) >> 31));
    v977[v994] = v1095;
    int * v979 = v854->cache_age;
    v979[v1083] = 0;
    v982 = v1083;
  }
  int v1098 = (v982 * 2) + (((int)((unsigned int)v858 >> 2)) & 1);
  int v983 = v869[v1098];
  int * v984 = v854->regs;
  v984[14] = v983;
  struct StateT * v986 = slot_22(v854);
  return v986;
}

struct StateT * slot_3(struct StateT * v40) {
  int * v41 = v40->saved_regs;
  int * v42 = v40->regs;
  int v43 = v42[12];
  v41[12] = v43;
  int v45 = v40->timer;
  int v55 = v45 + 1;
  v40->timer = v55;
  int * v47 = v40->regs;
  v47[12] = 0;
  struct StateT * v49 = slot_4(v40);
  return v49;
}

struct StateT * slot_10(struct StateT * v678) {
  int v679 = v678->timer;
  int v682 = v679 + 1;
  v678->timer = v682;
  return v678;
}

struct StateT * slot_1(struct StateT * v19) {
  int v20 = v19->timer;
  int v26 = v20 + 1;
  v19->timer = v26;
  int * v22 = v19->regs;
  v22[10] = 1;
  struct StateT * v24 = slot_2(v19);
  return v24;
}

struct StateT * slot_19(struct StateT * v829) {
  int v830 = v829->timer;
  int v833 = v830 + 1;
  v829->timer = v833;
  return v829;
}

struct StateT * slot_13(struct StateT * v691) {
  int * v692 = v691->saved_regs;
  int * v693 = v691->regs;
  int v694 = v693[11];
  v692[11] = v694;
  int v696 = v691->timer;
  int v708 = v696 + 1;
  v691->timer = v708;
  int * v698 = v691->regs;
  int v699 = v698[11];
  int * v700 = v691->regs;
  int v711 = v699 + -1;
  v700[11] = v711;
  struct StateT * v702 = slot_14(v691);
  return v702;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int * v7 = v2->regs;
  v7[11] = v6;
  struct StateT * v9 = slot_1(v2);
  return v9;
}

struct StateT * slot_14(struct StateT * v714) {
  int * v715 = v714->saved_regs;
  int * v716 = v714->regs;
  int v717 = v716[12];
  v715[12] = v717;
  int v719 = v714->timer;
  int v731 = v719 + 1;
  v714->timer = v731;
  int * v721 = v714->regs;
  int v722 = v721[12];
  int * v723 = v714->regs;
  int v734 = v722 + 4;
  v723[12] = v734;
  struct StateT * v725 = slot_15(v714);
  return v725;
}

struct StateT * slot_17(struct StateT * v808) {
  int v809 = v808->timer;
  int v815 = v809 + 1;
  v808->timer = v815;
  int * v811 = v808->regs;
  v811[10] = 0;
  struct StateT * v813 = slot_19(v808);
  return v813;
}

struct StateT * slot_20(struct StateT * v834) {
  int * v835 = v834->regs;
  int v836 = v835[11];
  bool v847 = !(v836 == 0);
  struct StateT * v843;
  if (v847) {
    int v837 = v834->timer;
    int v848 = v837 + 15;
    v834->timer = v848;
    struct StateT * v839 = slot_21(v834);
    v843 = v839;
  } else {
    struct StateT * v841 = slot_10(v834);
    v843 = v841;
  }
  return v843;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_8(struct StateT * v369) {
  int * v370 = v369->saved_regs;
  int * v371 = v369->regs;
  int v372 = v371[15];
  v370[15] = v372;
  int v374 = v369->timer;
  int v511 = v374 + 1;
  v369->timer = v511;
  int * v376 = v369->regs;
  int v377 = v376[13];
  int * v378 = v369->cache_tags;
  int v515 = (((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1)) & 1) * 2;
  int v379 = v378[v515];
  int * v380 = v369->cache_tags;
  int v517 = ((((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1)) & 1) * 2) + 1;
  int v381 = v380[v517];
  int * v382 = v369->cache_tags;
  int v519 = 4 + ((((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1)) & 3) * 2);
  int v383 = v382[v519];
  int * v384 = v369->cache_tags;
  int v521 = (4 + ((((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v385 = v384[v521];
  int v386 = v369->timer;
  int v522 = v386 + ((100 ^ (((~(((v383 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))) | (-(v383 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))))) >> 31)) | (~(((v385 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))) | (-(v385 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v379 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))) | (-(v379 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))))) >> 31)) | (~(((v381 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))) | (-(v381 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v383 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))) | (-(v383 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))))) >> 31)) | (~(((v385 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))) | (-(v385 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))))) >> 31))) & 104)))));
  v369->timer = v522;
  int * v388 = v369->cache_vals;
  bool v523 = !(((~(((v379 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))) | (-(v379 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))))) >> 31)) | (~(((v381 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))) | (-(v381 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))))) >> 31))) == 0);
  int v501;
  if (v523) {
    int * v389 = v369->cache_age;
    int v525 = ((((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1)) & 1) * 2) + ((~(((v381 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))) | (-(v381 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))))) >> 31)) & 1);
    int v390 = v389[v525];
    int * v391 = v369->cache_age;
    int v392 = v391[v515];
    int * v393 = v369->cache_age;
    int v528 = v392 + ((int)((unsigned int)(v392 - v390) >> 31));
    v393[v515] = v528;
    int * v395 = v369->cache_age;
    int v396 = v395[v517];
    int * v397 = v369->cache_age;
    int v531 = v396 + ((int)((unsigned int)(v396 - v390) >> 31));
    v397[v517] = v531;
    int * v399 = v369->cache_age;
    v399[v525] = 0;
    v501 = v525;
  } else {
    int * v402 = v369->cache_age;
    int v535 = (((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1)) & 1) * 2;
    int v403 = v402[v535];
    int * v404 = v369->cache_tags;
    int v405 = v404[v535];
    int * v406 = v369->cache_age;
    int v407 = v406[v517];
    int * v408 = v369->cache_tags;
    int v409 = v408[v517];
    bool v539 = !(((~(((v383 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))) | (-(v383 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))))) >> 31)) | (~(((v385 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))) | (-(v385 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))))) >> 31))) == 0);
    int v473;
    if (v539) {
      int * v410 = v369->cache_age;
      int v541 = (4 + ((((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1)) & 3) * 2)) + ((~(((v385 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))) | (-(v385 ^ ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1))))) >> 31)) & 1);
      int v411 = v410[v541];
      int * v412 = v369->cache_age;
      int v413 = v412[v519];
      int * v414 = v369->cache_age;
      int v544 = v413 + ((int)((unsigned int)(v413 - v411) >> 31));
      v414[v519] = v544;
      int * v416 = v369->cache_age;
      int v417 = v416[v521];
      int * v418 = v369->cache_age;
      int v547 = v417 + ((int)((unsigned int)(v417 - v411) >> 31));
      v418[v521] = v547;
      int * v420 = v369->cache_age;
      v420[v541] = 0;
      v473 = v541;
    } else {
      int * v423 = v369->cache_age;
      int v551 = 4 + ((((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1)) & 3) * 2);
      int v424 = v423[v551];
      int * v425 = v369->cache_tags;
      int v426 = v425[v551];
      int * v427 = v369->cache_age;
      int v428 = v427[v521];
      int * v429 = v369->cache_tags;
      int v430 = v429[v521];
      int * v431 = v369->cache_dirty;
      int v556 = (4 + ((((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1)) & 3) * 2)) + ((((v424 + ((~(((v426 ^ -1) | (-(v426 ^ -1))) >> 31)) & 2)) - (v428 + ((~(((v430 ^ -1) | (-(v430 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v432 = v431[v556];
      bool v557 = !(v432 == 0);
      if (v557) {
        int * v433 = v369->cache_tags;
        int v434 = v433[v556];
        int * v435 = v369->cache_vals;
        int v560 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1)) & 3) * 2)) + ((((v424 + ((~(((v426 ^ -1) | (-(v426 ^ -1))) >> 31)) & 2)) - (v428 + ((~(((v430 ^ -1) | (-(v430 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v436 = v435[v560];
        int * v437 = v369->cache_vals;
        int v562 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1)) & 3) * 2)) + ((((v424 + ((~(((v426 ^ -1) | (-(v426 ^ -1))) >> 31)) & 2)) - (v428 + ((~(((v430 ^ -1) | (-(v430 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v438 = v437[v562];
        int * v439 = v369->mem;
        int v564 = v434 * 2;
        v439[v564] = v436;
        int * v441 = v369->mem;
        int v567 = (v434 * 2) + 1;
        v441[v567] = v438;
        ;
      } else {
        ;
      }
      int * v446 = v369->mem;
      int v572 = ((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1)) * 2;
      int v447 = v446[v572];
      int * v448 = v369->mem;
      int v574 = (((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1)) * 2) + 1;
      int v449 = v448[v574];
      int * v450 = v369->cache_vals;
      int v576 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1)) & 3) * 2)) + ((((v424 + ((~(((v426 ^ -1) | (-(v426 ^ -1))) >> 31)) & 2)) - (v428 + ((~(((v430 ^ -1) | (-(v430 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v450[v576] = v447;
      int * v452 = v369->cache_vals;
      int v579 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1)) & 3) * 2)) + ((((v424 + ((~(((v426 ^ -1) | (-(v426 ^ -1))) >> 31)) & 2)) - (v428 + ((~(((v430 ^ -1) | (-(v430 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v452[v579] = v449;
      int * v454 = v369->cache_tags;
      int v582 = (int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1);
      v454[v556] = v582;
      int * v456 = v369->cache_dirty;
      v456[v556] = 0;
      int * v458 = v369->cache_age;
      v458[v556] = 1;
      int * v460 = v369->cache_age;
      int v461 = v460[v556];
      int * v462 = v369->cache_age;
      int v463 = v462[v519];
      int * v464 = v369->cache_age;
      int v590 = v463 + ((int)((unsigned int)(v463 - v461) >> 31));
      v464[v519] = v590;
      int * v466 = v369->cache_age;
      int v467 = v466[v521];
      int * v468 = v369->cache_age;
      int v593 = v467 + ((int)((unsigned int)(v467 - v461) >> 31));
      v468[v521] = v593;
      int * v470 = v369->cache_age;
      v470[v556] = 0;
      v473 = v556;
    }
    int * v474 = v369->cache_vals;
    int v596 = v473 * 2;
    int v475 = v474[v596];
    int * v476 = v369->cache_vals;
    int v598 = (v473 * 2) + 1;
    int v477 = v476[v598];
    int * v478 = v369->cache_vals;
    int v600 = (((((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1)) & 1) * 2) + ((((v403 + ((~(((v405 ^ -1) | (-(v405 ^ -1))) >> 31)) & 2)) - (v407 + ((~(((v409 ^ -1) | (-(v409 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v478[v600] = v475;
    int * v480 = v369->cache_vals;
    int v603 = ((((((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1)) & 1) * 2) + ((((v403 + ((~(((v405 ^ -1) | (-(v405 ^ -1))) >> 31)) & 2)) - (v407 + ((~(((v409 ^ -1) | (-(v409 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v480[v603] = v477;
    int * v482 = v369->cache_tags;
    int v606 = ((((int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1)) & 1) * 2) + ((((v403 + ((~(((v405 ^ -1) | (-(v405 ^ -1))) >> 31)) & 2)) - (v407 + ((~(((v409 ^ -1) | (-(v409 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v607 = (int)((unsigned int)((int)((unsigned int)v377 >> 2)) >> 1);
    v482[v606] = v607;
    int * v484 = v369->cache_dirty;
    v484[v606] = 0;
    int * v486 = v369->cache_age;
    v486[v606] = 1;
    int * v488 = v369->cache_age;
    int v489 = v488[v606];
    int * v490 = v369->cache_age;
    int v491 = v490[v515];
    int * v492 = v369->cache_age;
    int v615 = v491 + ((int)((unsigned int)(v491 - v489) >> 31));
    v492[v515] = v615;
    int * v494 = v369->cache_age;
    int v495 = v494[v517];
    int * v496 = v369->cache_age;
    int v618 = v495 + ((int)((unsigned int)(v495 - v489) >> 31));
    v496[v517] = v618;
    int * v498 = v369->cache_age;
    v498[v606] = 0;
    v501 = v606;
  }
  int v621 = (v501 * 2) + (((int)((unsigned int)v377 >> 2)) & 1);
  int v502 = v388[v621];
  int * v503 = v369->regs;
  v503[15] = v502;
  struct StateT * v505 = slot_9(v369);
  return v505;
}

struct StateT * slot_4(struct StateT * v60) {
  int v61 = v60->timer;
  int v69 = v61 + 1;
  v60->timer = v69;
  int * v63 = v60->regs;
  int v64 = v63[12];
  int * v65 = v60->regs;
  int v73 = v64 + 16;
  v65[12] = v73;
  struct StateT * v67 = slot_5(v60);
  return v67;
}

struct StateT * slot_15(struct StateT * v737) {
  int * v738 = v737->saved_regs;
  int * v739 = v737->regs;
  int v740 = v739[13];
  v738[13] = v740;
  int v742 = v737->timer;
  int v754 = v742 + 1;
  v737->timer = v754;
  int * v744 = v737->regs;
  int v745 = v744[13];
  int * v746 = v737->regs;
  int v757 = v745 + 4;
  v746[13] = v757;
  struct StateT * v748 = slot_16(v737);
  return v748;
}

struct StateT * slot_18(struct StateT * v821) {
  int v822 = v821->timer;
  int v826 = v822 + 1;
  v821->timer = v826;
  struct StateT * v824 = slot_20(v821);
  return v824;
}

struct StateT * slot_9(struct StateT * v626) {
  int * v627 = v626->regs;
  int v628 = v627[11];
  bool v655 = 0 >= v628;
  struct StateT * v651;
  if (v655) {
    int v629 = v626->timer;
    int v656 = v629 + 15;
    v626->timer = v656;
    int * v631 = v626->saved_regs;
    int v632 = v631[12];
    int * v633 = v626->regs;
    v633[12] = v632;
    int * v635 = v626->saved_regs;
    int v636 = v635[13];
    int * v637 = v626->regs;
    v637[13] = v636;
    int * v639 = v626->saved_regs;
    int v640 = v639[14];
    int * v641 = v626->regs;
    v641[14] = v640;
    int * v643 = v626->saved_regs;
    int v644 = v643[15];
    int * v645 = v626->regs;
    v645[15] = v644;
    struct StateT * v647 = slot_10(v626);
    v651 = v647;
  } else {
    struct StateT * v649 = slot_11(v626);
    v651 = v649;
  }
  return v651;
}

struct StateT * slot_22(struct StateT * v1104) {
  int v1105 = v1104->timer;
  int v1238 = v1105 + 1;
  v1104->timer = v1238;
  int * v1107 = v1104->regs;
  int v1108 = v1107[13];
  int * v1109 = v1104->cache_tags;
  int v1242 = (((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1)) & 1) * 2;
  int v1110 = v1109[v1242];
  int * v1111 = v1104->cache_tags;
  int v1244 = ((((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1112 = v1111[v1244];
  int * v1113 = v1104->cache_tags;
  int v1246 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1)) & 3) * 2);
  int v1114 = v1113[v1246];
  int * v1115 = v1104->cache_tags;
  int v1248 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1116 = v1115[v1248];
  int v1117 = v1104->timer;
  int v1249 = v1117 + ((100 ^ (((~(((v1114 ^ ((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1))) | (-(v1114 ^ ((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1))))) >> 31)) | (~(((v1116 ^ ((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1))) | (-(v1116 ^ ((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1110 ^ ((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1))) | (-(v1110 ^ ((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1))))) >> 31)) | (~(((v1112 ^ ((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1))) | (-(v1112 ^ ((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1114 ^ ((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1))) | (-(v1114 ^ ((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1))))) >> 31)) | (~(((v1116 ^ ((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1))) | (-(v1116 ^ ((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1104->timer = v1249;
  int * v1119 = v1104->cache_vals;
  bool v1250 = !(((~(((v1110 ^ ((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1))) | (-(v1110 ^ ((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1))))) >> 31)) | (~(((v1112 ^ ((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1))) | (-(v1112 ^ ((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1))))) >> 31))) == 0);
  int v1232;
  if (v1250) {
    int * v1120 = v1104->cache_age;
    int v1252 = ((((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1)) & 1) * 2) + ((~(((v1112 ^ ((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1))) | (-(v1112 ^ ((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1))))) >> 31)) & 1);
    int v1121 = v1120[v1252];
    int * v1122 = v1104->cache_age;
    int v1123 = v1122[v1242];
    int * v1124 = v1104->cache_age;
    int v1255 = v1123 + ((int)((unsigned int)(v1123 - v1121) >> 31));
    v1124[v1242] = v1255;
    int * v1126 = v1104->cache_age;
    int v1127 = v1126[v1244];
    int * v1128 = v1104->cache_age;
    int v1258 = v1127 + ((int)((unsigned int)(v1127 - v1121) >> 31));
    v1128[v1244] = v1258;
    int * v1130 = v1104->cache_age;
    v1130[v1252] = 0;
    v1232 = v1252;
  } else {
    int * v1133 = v1104->cache_age;
    int v1262 = (((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1)) & 1) * 2;
    int v1134 = v1133[v1262];
    int * v1135 = v1104->cache_tags;
    int v1136 = v1135[v1262];
    int * v1137 = v1104->cache_age;
    int v1138 = v1137[v1244];
    int * v1139 = v1104->cache_tags;
    int v1140 = v1139[v1244];
    bool v1266 = !(((~(((v1114 ^ ((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1))) | (-(v1114 ^ ((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1))))) >> 31)) | (~(((v1116 ^ ((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1))) | (-(v1116 ^ ((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1))))) >> 31))) == 0);
    int v1204;
    if (v1266) {
      int * v1141 = v1104->cache_age;
      int v1268 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1116 ^ ((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1))) | (-(v1116 ^ ((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1))))) >> 31)) & 1);
      int v1142 = v1141[v1268];
      int * v1143 = v1104->cache_age;
      int v1144 = v1143[v1246];
      int * v1145 = v1104->cache_age;
      int v1271 = v1144 + ((int)((unsigned int)(v1144 - v1142) >> 31));
      v1145[v1246] = v1271;
      int * v1147 = v1104->cache_age;
      int v1148 = v1147[v1248];
      int * v1149 = v1104->cache_age;
      int v1274 = v1148 + ((int)((unsigned int)(v1148 - v1142) >> 31));
      v1149[v1248] = v1274;
      int * v1151 = v1104->cache_age;
      v1151[v1268] = 0;
      v1204 = v1268;
    } else {
      int * v1154 = v1104->cache_age;
      int v1278 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1)) & 3) * 2);
      int v1155 = v1154[v1278];
      int * v1156 = v1104->cache_tags;
      int v1157 = v1156[v1278];
      int * v1158 = v1104->cache_age;
      int v1159 = v1158[v1248];
      int * v1160 = v1104->cache_tags;
      int v1161 = v1160[v1248];
      int * v1162 = v1104->cache_dirty;
      int v1283 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1)) & 3) * 2)) + ((((v1155 + ((~(((v1157 ^ -1) | (-(v1157 ^ -1))) >> 31)) & 2)) - (v1159 + ((~(((v1161 ^ -1) | (-(v1161 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1163 = v1162[v1283];
      bool v1284 = !(v1163 == 0);
      if (v1284) {
        int * v1164 = v1104->cache_tags;
        int v1165 = v1164[v1283];
        int * v1166 = v1104->cache_vals;
        int v1287 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1)) & 3) * 2)) + ((((v1155 + ((~(((v1157 ^ -1) | (-(v1157 ^ -1))) >> 31)) & 2)) - (v1159 + ((~(((v1161 ^ -1) | (-(v1161 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1167 = v1166[v1287];
        int * v1168 = v1104->cache_vals;
        int v1289 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1)) & 3) * 2)) + ((((v1155 + ((~(((v1157 ^ -1) | (-(v1157 ^ -1))) >> 31)) & 2)) - (v1159 + ((~(((v1161 ^ -1) | (-(v1161 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1169 = v1168[v1289];
        int * v1170 = v1104->mem;
        int v1291 = v1165 * 2;
        v1170[v1291] = v1167;
        int * v1172 = v1104->mem;
        int v1294 = (v1165 * 2) + 1;
        v1172[v1294] = v1169;
        ;
      } else {
        ;
      }
      int * v1177 = v1104->mem;
      int v1299 = ((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1)) * 2;
      int v1178 = v1177[v1299];
      int * v1179 = v1104->mem;
      int v1301 = (((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1)) * 2) + 1;
      int v1180 = v1179[v1301];
      int * v1181 = v1104->cache_vals;
      int v1303 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1)) & 3) * 2)) + ((((v1155 + ((~(((v1157 ^ -1) | (-(v1157 ^ -1))) >> 31)) & 2)) - (v1159 + ((~(((v1161 ^ -1) | (-(v1161 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1181[v1303] = v1178;
      int * v1183 = v1104->cache_vals;
      int v1306 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1)) & 3) * 2)) + ((((v1155 + ((~(((v1157 ^ -1) | (-(v1157 ^ -1))) >> 31)) & 2)) - (v1159 + ((~(((v1161 ^ -1) | (-(v1161 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1183[v1306] = v1180;
      int * v1185 = v1104->cache_tags;
      int v1309 = (int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1);
      v1185[v1283] = v1309;
      int * v1187 = v1104->cache_dirty;
      v1187[v1283] = 0;
      int * v1189 = v1104->cache_age;
      v1189[v1283] = 1;
      int * v1191 = v1104->cache_age;
      int v1192 = v1191[v1283];
      int * v1193 = v1104->cache_age;
      int v1194 = v1193[v1246];
      int * v1195 = v1104->cache_age;
      int v1317 = v1194 + ((int)((unsigned int)(v1194 - v1192) >> 31));
      v1195[v1246] = v1317;
      int * v1197 = v1104->cache_age;
      int v1198 = v1197[v1248];
      int * v1199 = v1104->cache_age;
      int v1320 = v1198 + ((int)((unsigned int)(v1198 - v1192) >> 31));
      v1199[v1248] = v1320;
      int * v1201 = v1104->cache_age;
      v1201[v1283] = 0;
      v1204 = v1283;
    }
    int * v1205 = v1104->cache_vals;
    int v1323 = v1204 * 2;
    int v1206 = v1205[v1323];
    int * v1207 = v1104->cache_vals;
    int v1325 = (v1204 * 2) + 1;
    int v1208 = v1207[v1325];
    int * v1209 = v1104->cache_vals;
    int v1327 = (((((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1)) & 1) * 2) + ((((v1134 + ((~(((v1136 ^ -1) | (-(v1136 ^ -1))) >> 31)) & 2)) - (v1138 + ((~(((v1140 ^ -1) | (-(v1140 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1209[v1327] = v1206;
    int * v1211 = v1104->cache_vals;
    int v1330 = ((((((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1)) & 1) * 2) + ((((v1134 + ((~(((v1136 ^ -1) | (-(v1136 ^ -1))) >> 31)) & 2)) - (v1138 + ((~(((v1140 ^ -1) | (-(v1140 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1211[v1330] = v1208;
    int * v1213 = v1104->cache_tags;
    int v1333 = ((((int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1)) & 1) * 2) + ((((v1134 + ((~(((v1136 ^ -1) | (-(v1136 ^ -1))) >> 31)) & 2)) - (v1138 + ((~(((v1140 ^ -1) | (-(v1140 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1334 = (int)((unsigned int)((int)((unsigned int)v1108 >> 2)) >> 1);
    v1213[v1333] = v1334;
    int * v1215 = v1104->cache_dirty;
    v1215[v1333] = 0;
    int * v1217 = v1104->cache_age;
    v1217[v1333] = 1;
    int * v1219 = v1104->cache_age;
    int v1220 = v1219[v1333];
    int * v1221 = v1104->cache_age;
    int v1222 = v1221[v1242];
    int * v1223 = v1104->cache_age;
    int v1342 = v1222 + ((int)((unsigned int)(v1222 - v1220) >> 31));
    v1223[v1242] = v1342;
    int * v1225 = v1104->cache_age;
    int v1226 = v1225[v1244];
    int * v1227 = v1104->cache_age;
    int v1345 = v1226 + ((int)((unsigned int)(v1226 - v1220) >> 31));
    v1227[v1244] = v1345;
    int * v1229 = v1104->cache_age;
    v1229[v1333] = 0;
    v1232 = v1333;
  }
  int v1348 = (v1232 * 2) + (((int)((unsigned int)v1108 >> 2)) & 1);
  int v1233 = v1119[v1348];
  int * v1234 = v1104->regs;
  v1234[15] = v1233;
  struct StateT * v1236 = slot_11(v1104);
  return v1236;
}

struct StateT * slot_11(struct StateT * v683) {
  int v684 = v683->timer;
  int v688 = v684 + 1;
  v683->timer = v688;
  struct StateT * v686 = slot_13(v683);
  return v686;
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
  
  int n = bounded(0, 4);
  s1.regs[10] = n;
  s2.regs[10] = n;
  // guess, the attacker's: the same draw in both states
  for (int i=0; i<4; i++) {
    int v = bounded(0, 20);
    s1.mem[4 + i] = v;
    s2.mem[4 + i] = v;
  }
  
  // secret, secret: a different draw in each state
  for (int i=0; i<4; i++) {
    s1.mem[0 + i] = secret(0, 20);
    s2.mem[0 + i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}