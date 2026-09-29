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

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v19);
struct StateT * slot_2(struct StateT * v223);
struct StateT * slot_3(struct StateT * v237);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v19) {
  int v20 = v19->timer;
  int v130 = v20 + 1;
  v19->timer = v130;
  int * v22 = v19->regs;
  int v23 = v22[10];
  int * v24 = v19->cache_tags;
  int v134 = (((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1)) & 1) * 2;
  int v25 = v24[v134];
  int v135 = ((((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1)) & 1) * 2) + 1;
  int v26 = v24[v135];
  int v136 = 4 + ((((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1)) & 3) * 2);
  int v27 = v24[v136];
  int v137 = (4 + ((((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v28 = v24[v137];
  int v29 = v19->timer;
  int v138 = v29 + ((100 ^ (((~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))))) >> 31)) | (~(((v28 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))) | (-(v28 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v25 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))) | (-(v25 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))))) >> 31)) | (~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))))) >> 31)) | (~(((v28 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))) | (-(v28 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))))) >> 31))) & 104)))));
  v19->timer = v138;
  int * v31 = v19->cache_vals;
  bool v139 = !(((~(((v25 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))) | (-(v25 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))))) >> 31)) | (~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))))) >> 31))) == 0);
  int v124;
  if (v139) {
    int * v32 = v19->cache_age;
    int v141 = ((((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1)) & 1) * 2) + ((~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))))) >> 31)) & 1);
    int v33 = v32[v141];
    int v34 = v32[v134];
    int v142 = v34 + ((int)((unsigned int)(v34 - v33) >> 31));
    v32[v134] = v142;
    int * v36 = v19->cache_age;
    int v37 = v36[v135];
    int v144 = v37 + ((int)((unsigned int)(v37 - v33) >> 31));
    v36[v135] = v144;
    int * v39 = v19->cache_age;
    v39[v141] = 0;
    v124 = v141;
  } else {
    int * v42 = v19->cache_age;
    int v148 = (((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1)) & 1) * 2;
    int v43 = v42[v148];
    int * v44 = v19->cache_tags;
    int v45 = v44[v148];
    int v46 = v42[v135];
    int v47 = v44[v135];
    bool v150 = !(((~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))))) >> 31)) | (~(((v28 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))) | (-(v28 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))))) >> 31))) == 0);
    int v101;
    if (v150) {
      int * v48 = v19->cache_age;
      int v152 = (4 + ((((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1)) & 3) * 2)) + ((~(((v28 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))) | (-(v28 ^ ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1))))) >> 31)) & 1);
      int v49 = v48[v152];
      int v50 = v48[v136];
      int v153 = v50 + ((int)((unsigned int)(v50 - v49) >> 31));
      v48[v136] = v153;
      int * v52 = v19->cache_age;
      int v53 = v52[v137];
      int v155 = v53 + ((int)((unsigned int)(v53 - v49) >> 31));
      v52[v137] = v155;
      int * v55 = v19->cache_age;
      v55[v152] = 0;
      v101 = v152;
    } else {
      int * v58 = v19->cache_age;
      int v159 = 4 + ((((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1)) & 3) * 2);
      int v59 = v58[v159];
      int * v60 = v19->cache_tags;
      int v61 = v60[v159];
      int v62 = v58[v137];
      int v63 = v60[v137];
      int * v64 = v19->cache_dirty;
      int v162 = (4 + ((((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1)) & 3) * 2)) + ((((v59 + ((~(((v61 ^ -1) | (-(v61 ^ -1))) >> 31)) & 2)) - (v62 + ((~(((v63 ^ -1) | (-(v63 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v65 = v64[v162];
      bool v163 = !(v65 == 0);
      if (v163) {
        int * v66 = v19->cache_tags;
        int v67 = v66[v162];
        int * v68 = v19->cache_vals;
        int v166 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1)) & 3) * 2)) + ((((v59 + ((~(((v61 ^ -1) | (-(v61 ^ -1))) >> 31)) & 2)) - (v62 + ((~(((v63 ^ -1) | (-(v63 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v69 = v68[v166];
        int v167 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1)) & 3) * 2)) + ((((v59 + ((~(((v61 ^ -1) | (-(v61 ^ -1))) >> 31)) & 2)) - (v62 + ((~(((v63 ^ -1) | (-(v63 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v70 = v68[v167];
        int * v71 = v19->mem;
        int v169 = v67 * 2;
        v71[v169] = v69;
        int * v73 = v19->mem;
        int v172 = (v67 * 2) + 1;
        v73[v172] = v70;
        ;
      } else {
        ;
      }
      int * v78 = v19->mem;
      int v177 = ((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1)) * 2;
      int v79 = v78[v177];
      int v178 = (((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1)) * 2) + 1;
      int v80 = v78[v178];
      int * v81 = v19->cache_vals;
      int v180 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1)) & 3) * 2)) + ((((v59 + ((~(((v61 ^ -1) | (-(v61 ^ -1))) >> 31)) & 2)) - (v62 + ((~(((v63 ^ -1) | (-(v63 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v81[v180] = v79;
      int * v83 = v19->cache_vals;
      int v183 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1)) & 3) * 2)) + ((((v59 + ((~(((v61 ^ -1) | (-(v61 ^ -1))) >> 31)) & 2)) - (v62 + ((~(((v63 ^ -1) | (-(v63 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v83[v183] = v80;
      int * v85 = v19->cache_tags;
      int v186 = (int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1);
      v85[v162] = v186;
      int * v87 = v19->cache_dirty;
      v87[v162] = 0;
      int * v89 = v19->cache_age;
      v89[v162] = 1;
      int * v91 = v19->cache_age;
      int v92 = v91[v162];
      int v93 = v91[v136];
      int v192 = v93 + ((int)((unsigned int)(v93 - v92) >> 31));
      v91[v136] = v192;
      int * v95 = v19->cache_age;
      int v96 = v95[v137];
      int v194 = v96 + ((int)((unsigned int)(v96 - v92) >> 31));
      v95[v137] = v194;
      int * v98 = v19->cache_age;
      v98[v162] = 0;
      v101 = v162;
    }
    int * v102 = v19->cache_vals;
    int v197 = v101 * 2;
    int v103 = v102[v197];
    int v198 = (v101 * 2) + 1;
    int v104 = v102[v198];
    int v199 = (((((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1)) & 1) * 2) + ((((v43 + ((~(((v45 ^ -1) | (-(v45 ^ -1))) >> 31)) & 2)) - (v46 + ((~(((v47 ^ -1) | (-(v47 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v102[v199] = v103;
    int * v106 = v19->cache_vals;
    int v202 = ((((((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1)) & 1) * 2) + ((((v43 + ((~(((v45 ^ -1) | (-(v45 ^ -1))) >> 31)) & 2)) - (v46 + ((~(((v47 ^ -1) | (-(v47 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v106[v202] = v104;
    int * v108 = v19->cache_tags;
    int v205 = ((((int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1)) & 1) * 2) + ((((v43 + ((~(((v45 ^ -1) | (-(v45 ^ -1))) >> 31)) & 2)) - (v46 + ((~(((v47 ^ -1) | (-(v47 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v206 = (int)((unsigned int)((int)((unsigned int)v23 >> 2)) >> 1);
    v108[v205] = v206;
    int * v110 = v19->cache_dirty;
    v110[v205] = 0;
    int * v112 = v19->cache_age;
    v112[v205] = 1;
    int * v114 = v19->cache_age;
    int v115 = v114[v205];
    int v116 = v114[v134];
    int v212 = v116 + ((int)((unsigned int)(v116 - v115) >> 31));
    v114[v134] = v212;
    int * v118 = v19->cache_age;
    int v119 = v118[v135];
    int v214 = v119 + ((int)((unsigned int)(v119 - v115) >> 31));
    v118[v135] = v214;
    int * v121 = v19->cache_age;
    v121[v205] = 0;
    v124 = v205;
  }
  int v217 = (v124 * 2) + (((int)((unsigned int)v23 >> 2)) & 1);
  int v125 = v31[v217];
  int * v126 = v19->regs;
  v126[11] = v125;
  struct StateT * v128 = slot_2(v19);
  return v128;
}

struct StateT * slot_2(struct StateT * v223) {
  int v224 = v223->timer;
  int v231 = v224 + 1;
  v223->timer = v231;
  int * v226 = v223->regs;
  int v227 = v226[11];
  int v234 = v227 << 2;
  v226[11] = v234;
  struct StateT * v229 = slot_3(v223);
  return v229;
}

struct StateT * slot_3(struct StateT * v237) {
  int v238 = v237->timer;
  int v347 = v238 + 1;
  v237->timer = v347;
  int * v240 = v237->regs;
  int v241 = v240[11];
  int * v242 = v237->cache_tags;
  int v351 = (((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1)) & 1) * 2;
  int v243 = v242[v351];
  int v352 = ((((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v244 = v242[v352];
  int v353 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1)) & 3) * 2);
  int v245 = v242[v353];
  int v354 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v246 = v242[v354];
  int v247 = v237->timer;
  int v355 = v247 + ((100 ^ (((~(((v245 ^ ((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1))) | (-(v245 ^ ((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v246 ^ ((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1))) | (-(v246 ^ ((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v243 ^ ((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1))) | (-(v243 ^ ((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v244 ^ ((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1))) | (-(v244 ^ ((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v245 ^ ((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1))) | (-(v245 ^ ((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v246 ^ ((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1))) | (-(v246 ^ ((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v237->timer = v355;
  int * v249 = v237->cache_vals;
  bool v356 = !(((~(((v243 ^ ((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1))) | (-(v243 ^ ((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v244 ^ ((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1))) | (-(v244 ^ ((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v342;
  if (v356) {
    int * v250 = v237->cache_age;
    int v358 = ((((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v244 ^ ((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1))) | (-(v244 ^ ((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v251 = v250[v358];
    int v252 = v250[v351];
    int v359 = v252 + ((int)((unsigned int)(v252 - v251) >> 31));
    v250[v351] = v359;
    int * v254 = v237->cache_age;
    int v255 = v254[v352];
    int v361 = v255 + ((int)((unsigned int)(v255 - v251) >> 31));
    v254[v352] = v361;
    int * v257 = v237->cache_age;
    v257[v358] = 0;
    v342 = v358;
  } else {
    int * v260 = v237->cache_age;
    int v365 = (((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1)) & 1) * 2;
    int v261 = v260[v365];
    int * v262 = v237->cache_tags;
    int v263 = v262[v365];
    int v264 = v260[v352];
    int v265 = v262[v352];
    bool v367 = !(((~(((v245 ^ ((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1))) | (-(v245 ^ ((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v246 ^ ((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1))) | (-(v246 ^ ((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v319;
    if (v367) {
      int * v266 = v237->cache_age;
      int v369 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v246 ^ ((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1))) | (-(v246 ^ ((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v267 = v266[v369];
      int v268 = v266[v353];
      int v370 = v268 + ((int)((unsigned int)(v268 - v267) >> 31));
      v266[v353] = v370;
      int * v270 = v237->cache_age;
      int v271 = v270[v354];
      int v372 = v271 + ((int)((unsigned int)(v271 - v267) >> 31));
      v270[v354] = v372;
      int * v273 = v237->cache_age;
      v273[v369] = 0;
      v319 = v369;
    } else {
      int * v276 = v237->cache_age;
      int v376 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1)) & 3) * 2);
      int v277 = v276[v376];
      int * v278 = v237->cache_tags;
      int v279 = v278[v376];
      int v280 = v276[v354];
      int v281 = v278[v354];
      int * v282 = v237->cache_dirty;
      int v379 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v277 + ((~(((v279 ^ -1) | (-(v279 ^ -1))) >> 31)) & 2)) - (v280 + ((~(((v281 ^ -1) | (-(v281 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v283 = v282[v379];
      bool v380 = !(v283 == 0);
      if (v380) {
        int * v284 = v237->cache_tags;
        int v285 = v284[v379];
        int * v286 = v237->cache_vals;
        int v383 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v277 + ((~(((v279 ^ -1) | (-(v279 ^ -1))) >> 31)) & 2)) - (v280 + ((~(((v281 ^ -1) | (-(v281 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v287 = v286[v383];
        int v384 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v277 + ((~(((v279 ^ -1) | (-(v279 ^ -1))) >> 31)) & 2)) - (v280 + ((~(((v281 ^ -1) | (-(v281 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v288 = v286[v384];
        int * v289 = v237->mem;
        int v386 = v285 * 2;
        v289[v386] = v287;
        int * v291 = v237->mem;
        int v389 = (v285 * 2) + 1;
        v291[v389] = v288;
        ;
      } else {
        ;
      }
      int * v296 = v237->mem;
      int v394 = ((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1)) * 2;
      int v297 = v296[v394];
      int v395 = (((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1)) * 2) + 1;
      int v298 = v296[v395];
      int * v299 = v237->cache_vals;
      int v397 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v277 + ((~(((v279 ^ -1) | (-(v279 ^ -1))) >> 31)) & 2)) - (v280 + ((~(((v281 ^ -1) | (-(v281 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v299[v397] = v297;
      int * v301 = v237->cache_vals;
      int v400 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v277 + ((~(((v279 ^ -1) | (-(v279 ^ -1))) >> 31)) & 2)) - (v280 + ((~(((v281 ^ -1) | (-(v281 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v301[v400] = v298;
      int * v303 = v237->cache_tags;
      int v403 = (int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1);
      v303[v379] = v403;
      int * v305 = v237->cache_dirty;
      v305[v379] = 0;
      int * v307 = v237->cache_age;
      v307[v379] = 1;
      int * v309 = v237->cache_age;
      int v310 = v309[v379];
      int v311 = v309[v353];
      int v409 = v311 + ((int)((unsigned int)(v311 - v310) >> 31));
      v309[v353] = v409;
      int * v313 = v237->cache_age;
      int v314 = v313[v354];
      int v411 = v314 + ((int)((unsigned int)(v314 - v310) >> 31));
      v313[v354] = v411;
      int * v316 = v237->cache_age;
      v316[v379] = 0;
      v319 = v379;
    }
    int * v320 = v237->cache_vals;
    int v414 = v319 * 2;
    int v321 = v320[v414];
    int v415 = (v319 * 2) + 1;
    int v322 = v320[v415];
    int v416 = (((((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v261 + ((~(((v263 ^ -1) | (-(v263 ^ -1))) >> 31)) & 2)) - (v264 + ((~(((v265 ^ -1) | (-(v265 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v320[v416] = v321;
    int * v324 = v237->cache_vals;
    int v419 = ((((((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v261 + ((~(((v263 ^ -1) | (-(v263 ^ -1))) >> 31)) & 2)) - (v264 + ((~(((v265 ^ -1) | (-(v265 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v324[v419] = v322;
    int * v326 = v237->cache_tags;
    int v422 = ((((int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v261 + ((~(((v263 ^ -1) | (-(v263 ^ -1))) >> 31)) & 2)) - (v264 + ((~(((v265 ^ -1) | (-(v265 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v423 = (int)((unsigned int)((int)((unsigned int)(v241 + 16) >> 2)) >> 1);
    v326[v422] = v423;
    int * v328 = v237->cache_dirty;
    v328[v422] = 0;
    int * v330 = v237->cache_age;
    v330[v422] = 1;
    int * v332 = v237->cache_age;
    int v333 = v332[v422];
    int v334 = v332[v351];
    int v429 = v334 + ((int)((unsigned int)(v334 - v333) >> 31));
    v332[v351] = v429;
    int * v336 = v237->cache_age;
    int v337 = v336[v352];
    int v431 = v337 + ((int)((unsigned int)(v337 - v333) >> 31));
    v336[v352] = v431;
    int * v339 = v237->cache_age;
    v339[v422] = 0;
    v342 = v422;
  }
  int v434 = (v342 * 2) + (((int)((unsigned int)(v241 + 16) >> 2)) & 1);
  int v343 = v249[v434];
  int * v344 = v237->regs;
  v344[12] = v343;
  return v237;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v12 = v3 + 1;
  v2->timer = v12;
  int * v5 = v2->regs;
  int v6 = v5[10];
  bool v15 = v6 == 0;
  struct StateT * v10;
  if (v15) {
    v10 = v2;
  } else {
    struct StateT * v8 = slot_1(v2);
    v10 = v8;
  }
  return v10;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
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