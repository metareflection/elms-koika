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

struct StateT2 {
  struct StateT * a;
  struct StateT * b;
};

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

void squared_assert(bool);
void squared_assume(bool);
void squared_diverged(bool);

struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_1(struct StateT2 * v38);
struct StateT2 * slot_8(struct StateT2 * v1106);
struct StateT2 * slot_6(struct StateT2 * v631);
struct StateT2 * slot_5(struct StateT2 * v195);
struct StateT2 * slot_4(struct StateT2 * v134);
struct StateT2 * slot_2(struct StateT2 * v74);
struct StateT2 * slot_7(struct StateT2 * v670);
struct StateT2 * slot_3(struct StateT2 * v110);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  return v1;
}

struct StateT2 * slot_1(struct StateT2 * v38) {
  struct StateT * v39 = v38->a;
  int v40 = v39->timer;
  struct StateT * v41 = v38->b;
  int v42 = v41->timer;
  bool v61 = v40 == v42;
  squared_assert(v61);
  squared_assume(v61);
  struct StateT * v45 = v38->a;
  int v46 = v45->timer;
  int v63 = v46 + 1;
  v45->timer = v63;
  struct StateT * v48 = v38->b;
  int v49 = v48->timer;
  int v65 = v49 + 1;
  v48->timer = v65;
  struct StateT * v51 = v38->a;
  int * v52 = v51->regs;
  v52[10] = 80;
  struct StateT * v54 = v38->b;
  int * v55 = v54->regs;
  v55[10] = 80;
  struct StateT2 * v57 = slot_2(v38);
  return v57;
}

struct StateT2 * slot_8(struct StateT2 * v1106) {
  struct StateT * v1107 = v1106->a;
  int v1108 = v1107->timer;
  struct StateT * v1109 = v1106->b;
  int v1110 = v1109->timer;
  bool v1159 = v1108 == v1110;
  squared_assert(v1159);
  squared_assume(v1159);
  struct StateT * v1113 = v1106->a;
  int * v1114 = v1113->regs;
  int v1115 = v1114[10];
  int v1116 = v1114[15];
  struct StateT * v1117 = v1106->b;
  int * v1118 = v1117->regs;
  int v1119 = v1118[10];
  int v1120 = v1118[15];
  bool v1166 = (v1115 >= v1116) == (v1119 >= v1120);
  squared_diverged(v1166);
  squared_assume(v1166);
  bool v1167 = v1115 >= v1116;
  struct StateT2 * v1155;
  if (v1167) {
    struct StateT * v1123 = v1106->a;
    int v1124 = v1123->timer;
    int v1169 = v1124 + 15;
    v1123->timer = v1169;
    int * v1126 = v1123->saved_regs;
    int v1127 = v1126[5];
    int * v1128 = v1123->regs;
    v1128[5] = v1127;
    int * v1130 = v1123->saved_regs;
    int v1131 = v1130[11];
    int * v1132 = v1123->regs;
    v1132[11] = v1131;
    int * v1134 = v1123->saved_regs;
    int v1135 = v1134[12];
    int * v1136 = v1123->regs;
    v1136[12] = v1135;
    struct StateT * v1138 = v1106->b;
    int v1139 = v1138->timer;
    int v1183 = v1139 + 15;
    v1138->timer = v1183;
    int * v1141 = v1138->saved_regs;
    int v1142 = v1141[5];
    int * v1143 = v1138->regs;
    v1143[5] = v1142;
    int * v1145 = v1138->saved_regs;
    int v1146 = v1145[11];
    int * v1147 = v1138->regs;
    v1147[11] = v1146;
    int * v1149 = v1138->saved_regs;
    int v1150 = v1149[12];
    int * v1151 = v1138->regs;
    v1151[12] = v1150;
    v1155 = v1106;
  } else {
    v1155 = v1106;
  }
  return v1155;
}

struct StateT2 * slot_6(struct StateT2 * v631) {
  struct StateT * v632 = v631->a;
  int v633 = v632->timer;
  struct StateT * v634 = v631->b;
  int v635 = v634->timer;
  bool v656 = v633 == v635;
  squared_assert(v656);
  squared_assume(v656);
  struct StateT * v638 = v631->a;
  int v639 = v638->timer;
  int v658 = v639 + 1;
  v638->timer = v658;
  struct StateT * v641 = v631->b;
  int v642 = v641->timer;
  int v660 = v642 + 1;
  v641->timer = v660;
  struct StateT * v644 = v631->a;
  int * v645 = v644->regs;
  int v646 = v645[11];
  int v664 = v646 << 2;
  v645[11] = v664;
  struct StateT * v648 = v631->b;
  int * v649 = v648->regs;
  int v650 = v649[11];
  int v667 = v650 << 2;
  v649[11] = v667;
  struct StateT2 * v652 = slot_7(v631);
  return v652;
}

struct StateT2 * slot_5(struct StateT2 * v195) {
  struct StateT * v196 = v195->a;
  int v197 = v196->timer;
  struct StateT * v198 = v195->b;
  int v199 = v198->timer;
  bool v436 = v197 == v199;
  squared_assert(v436);
  squared_assume(v436);
  struct StateT * v202 = v195->a;
  int * v203 = v202->saved_regs;
  int * v204 = v202->regs;
  int v205 = v204[11];
  v203[11] = v205;
  struct StateT * v207 = v195->b;
  int * v208 = v207->saved_regs;
  int * v209 = v207->regs;
  int v210 = v209[11];
  v208[11] = v210;
  struct StateT * v212 = v195->a;
  int v213 = v212->timer;
  int v447 = v213 + 1;
  v212->timer = v447;
  struct StateT * v215 = v195->b;
  int v216 = v215->timer;
  int v449 = v216 + 1;
  v215->timer = v449;
  struct StateT * v218 = v195->a;
  int * v219 = v218->regs;
  int v220 = v219[5];
  int * v221 = v218->cache_tags;
  int v454 = (((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 1) * 2;
  int v222 = v221[v454];
  int v455 = ((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 1) * 2) + 1;
  int v223 = v221[v455];
  int v456 = 4 + ((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 3) * 2);
  int v224 = v221[v456];
  int v457 = (4 + ((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v225 = v221[v457];
  int v226 = v218->timer;
  int v458 = v226 + ((100 ^ (((~(((v224 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))) | (-(v224 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))))) >> 31)) | (~(((v225 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))) | (-(v225 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v222 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))) | (-(v222 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))))) >> 31)) | (~(((v223 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))) | (-(v223 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v224 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))) | (-(v224 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))))) >> 31)) | (~(((v225 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))) | (-(v225 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))))) >> 31))) & 104)))));
  v218->timer = v458;
  int * v228 = v218->cache_vals;
  bool v459 = !(((~(((v222 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))) | (-(v222 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))))) >> 31)) | (~(((v223 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))) | (-(v223 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))))) >> 31))) == 0);
  int v321;
  if (v459) {
    int * v229 = v218->cache_age;
    int v461 = ((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 1) * 2) + ((~(((v223 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))) | (-(v223 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))))) >> 31)) & 1);
    int v230 = v229[v461];
    int v231 = v229[v454];
    int v462 = v231 + ((int)((unsigned int)(v231 - v230) >> 31));
    v229[v454] = v462;
    int * v233 = v218->cache_age;
    int v234 = v233[v455];
    int v464 = v234 + ((int)((unsigned int)(v234 - v230) >> 31));
    v233[v455] = v464;
    int * v236 = v218->cache_age;
    v236[v461] = 0;
    v321 = v461;
  } else {
    int * v239 = v218->cache_age;
    int v468 = (((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 1) * 2;
    int v240 = v239[v468];
    int * v241 = v218->cache_tags;
    int v242 = v241[v468];
    int v243 = v239[v455];
    int v244 = v241[v455];
    bool v470 = !(((~(((v224 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))) | (-(v224 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))))) >> 31)) | (~(((v225 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))) | (-(v225 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))))) >> 31))) == 0);
    int v298;
    if (v470) {
      int * v245 = v218->cache_age;
      int v472 = (4 + ((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 3) * 2)) + ((~(((v225 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))) | (-(v225 ^ ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1))))) >> 31)) & 1);
      int v246 = v245[v472];
      int v247 = v245[v456];
      int v473 = v247 + ((int)((unsigned int)(v247 - v246) >> 31));
      v245[v456] = v473;
      int * v249 = v218->cache_age;
      int v250 = v249[v457];
      int v475 = v250 + ((int)((unsigned int)(v250 - v246) >> 31));
      v249[v457] = v475;
      int * v252 = v218->cache_age;
      v252[v472] = 0;
      v298 = v472;
    } else {
      int * v255 = v218->cache_age;
      int v479 = 4 + ((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 3) * 2);
      int v256 = v255[v479];
      int * v257 = v218->cache_tags;
      int v258 = v257[v479];
      int v259 = v255[v457];
      int v260 = v257[v457];
      int * v261 = v218->cache_dirty;
      int v482 = (4 + ((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 3) * 2)) + ((((v256 + ((~(((v258 ^ -1) | (-(v258 ^ -1))) >> 31)) & 2)) - (v259 + ((~(((v260 ^ -1) | (-(v260 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v262 = v261[v482];
      bool v483 = !(v262 == 0);
      if (v483) {
        int * v263 = v218->cache_tags;
        int v264 = v263[v482];
        int * v265 = v218->cache_vals;
        int v486 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 3) * 2)) + ((((v256 + ((~(((v258 ^ -1) | (-(v258 ^ -1))) >> 31)) & 2)) - (v259 + ((~(((v260 ^ -1) | (-(v260 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v266 = v265[v486];
        int v487 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 3) * 2)) + ((((v256 + ((~(((v258 ^ -1) | (-(v258 ^ -1))) >> 31)) & 2)) - (v259 + ((~(((v260 ^ -1) | (-(v260 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v267 = v265[v487];
        int * v268 = v218->mem;
        int v489 = v264 * 2;
        v268[v489] = v266;
        int * v270 = v218->mem;
        int v492 = (v264 * 2) + 1;
        v270[v492] = v267;
        ;
      } else {
        ;
      }
      int * v275 = v218->mem;
      int v497 = ((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) * 2;
      int v276 = v275[v497];
      int v498 = (((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) * 2) + 1;
      int v277 = v275[v498];
      int * v278 = v218->cache_vals;
      int v500 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 3) * 2)) + ((((v256 + ((~(((v258 ^ -1) | (-(v258 ^ -1))) >> 31)) & 2)) - (v259 + ((~(((v260 ^ -1) | (-(v260 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v278[v500] = v276;
      int * v280 = v218->cache_vals;
      int v503 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 3) * 2)) + ((((v256 + ((~(((v258 ^ -1) | (-(v258 ^ -1))) >> 31)) & 2)) - (v259 + ((~(((v260 ^ -1) | (-(v260 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v280[v503] = v277;
      int * v282 = v218->cache_tags;
      int v506 = (int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1);
      v282[v482] = v506;
      int * v284 = v218->cache_dirty;
      v284[v482] = 0;
      int * v286 = v218->cache_age;
      v286[v482] = 1;
      int * v288 = v218->cache_age;
      int v289 = v288[v482];
      int v290 = v288[v456];
      int v512 = v290 + ((int)((unsigned int)(v290 - v289) >> 31));
      v288[v456] = v512;
      int * v292 = v218->cache_age;
      int v293 = v292[v457];
      int v514 = v293 + ((int)((unsigned int)(v293 - v289) >> 31));
      v292[v457] = v514;
      int * v295 = v218->cache_age;
      v295[v482] = 0;
      v298 = v482;
    }
    int * v299 = v218->cache_vals;
    int v517 = v298 * 2;
    int v300 = v299[v517];
    int v518 = (v298 * 2) + 1;
    int v301 = v299[v518];
    int v519 = (((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 1) * 2) + ((((v240 + ((~(((v242 ^ -1) | (-(v242 ^ -1))) >> 31)) & 2)) - (v243 + ((~(((v244 ^ -1) | (-(v244 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v299[v519] = v300;
    int * v303 = v218->cache_vals;
    int v522 = ((((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 1) * 2) + ((((v240 + ((~(((v242 ^ -1) | (-(v242 ^ -1))) >> 31)) & 2)) - (v243 + ((~(((v244 ^ -1) | (-(v244 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v303[v522] = v301;
    int * v305 = v218->cache_tags;
    int v525 = ((((int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1)) & 1) * 2) + ((((v240 + ((~(((v242 ^ -1) | (-(v242 ^ -1))) >> 31)) & 2)) - (v243 + ((~(((v244 ^ -1) | (-(v244 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v526 = (int)((unsigned int)((int)((unsigned int)v220 >> 2)) >> 1);
    v305[v525] = v526;
    int * v307 = v218->cache_dirty;
    v307[v525] = 0;
    int * v309 = v218->cache_age;
    v309[v525] = 1;
    int * v311 = v218->cache_age;
    int v312 = v311[v525];
    int v313 = v311[v454];
    int v532 = v313 + ((int)((unsigned int)(v313 - v312) >> 31));
    v311[v454] = v532;
    int * v315 = v218->cache_age;
    int v316 = v315[v455];
    int v534 = v316 + ((int)((unsigned int)(v316 - v312) >> 31));
    v315[v455] = v534;
    int * v318 = v218->cache_age;
    v318[v525] = 0;
    v321 = v525;
  }
  int v537 = (v321 * 2) + (((int)((unsigned int)v220 >> 2)) & 1);
  int v322 = v228[v537];
  int * v323 = v218->regs;
  v323[11] = v322;
  struct StateT * v325 = v195->b;
  int * v326 = v325->regs;
  int v327 = v326[5];
  int * v328 = v325->cache_tags;
  int v543 = (((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1)) & 1) * 2;
  int v329 = v328[v543];
  int v544 = ((((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1)) & 1) * 2) + 1;
  int v330 = v328[v544];
  int v545 = 4 + ((((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1)) & 3) * 2);
  int v331 = v328[v545];
  int v546 = (4 + ((((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v332 = v328[v546];
  int v333 = v325->timer;
  int v547 = v333 + ((100 ^ (((~(((v331 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))) | (-(v331 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))))) >> 31)) | (~(((v332 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))) | (-(v332 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v329 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))) | (-(v329 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))))) >> 31)) | (~(((v330 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))) | (-(v330 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v331 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))) | (-(v331 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))))) >> 31)) | (~(((v332 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))) | (-(v332 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))))) >> 31))) & 104)))));
  v325->timer = v547;
  int * v335 = v325->cache_vals;
  bool v548 = !(((~(((v329 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))) | (-(v329 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))))) >> 31)) | (~(((v330 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))) | (-(v330 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))))) >> 31))) == 0);
  int v428;
  if (v548) {
    int * v336 = v325->cache_age;
    int v550 = ((((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1)) & 1) * 2) + ((~(((v330 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))) | (-(v330 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))))) >> 31)) & 1);
    int v337 = v336[v550];
    int v338 = v336[v543];
    int v551 = v338 + ((int)((unsigned int)(v338 - v337) >> 31));
    v336[v543] = v551;
    int * v340 = v325->cache_age;
    int v341 = v340[v544];
    int v553 = v341 + ((int)((unsigned int)(v341 - v337) >> 31));
    v340[v544] = v553;
    int * v343 = v325->cache_age;
    v343[v550] = 0;
    v428 = v550;
  } else {
    int * v346 = v325->cache_age;
    int v557 = (((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1)) & 1) * 2;
    int v347 = v346[v557];
    int * v348 = v325->cache_tags;
    int v349 = v348[v557];
    int v350 = v346[v544];
    int v351 = v348[v544];
    bool v559 = !(((~(((v331 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))) | (-(v331 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))))) >> 31)) | (~(((v332 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))) | (-(v332 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))))) >> 31))) == 0);
    int v405;
    if (v559) {
      int * v352 = v325->cache_age;
      int v561 = (4 + ((((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1)) & 3) * 2)) + ((~(((v332 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))) | (-(v332 ^ ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1))))) >> 31)) & 1);
      int v353 = v352[v561];
      int v354 = v352[v545];
      int v562 = v354 + ((int)((unsigned int)(v354 - v353) >> 31));
      v352[v545] = v562;
      int * v356 = v325->cache_age;
      int v357 = v356[v546];
      int v564 = v357 + ((int)((unsigned int)(v357 - v353) >> 31));
      v356[v546] = v564;
      int * v359 = v325->cache_age;
      v359[v561] = 0;
      v405 = v561;
    } else {
      int * v362 = v325->cache_age;
      int v568 = 4 + ((((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1)) & 3) * 2);
      int v363 = v362[v568];
      int * v364 = v325->cache_tags;
      int v365 = v364[v568];
      int v366 = v362[v546];
      int v367 = v364[v546];
      int * v368 = v325->cache_dirty;
      int v571 = (4 + ((((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1)) & 3) * 2)) + ((((v363 + ((~(((v365 ^ -1) | (-(v365 ^ -1))) >> 31)) & 2)) - (v366 + ((~(((v367 ^ -1) | (-(v367 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v369 = v368[v571];
      bool v572 = !(v369 == 0);
      if (v572) {
        int * v370 = v325->cache_tags;
        int v371 = v370[v571];
        int * v372 = v325->cache_vals;
        int v575 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1)) & 3) * 2)) + ((((v363 + ((~(((v365 ^ -1) | (-(v365 ^ -1))) >> 31)) & 2)) - (v366 + ((~(((v367 ^ -1) | (-(v367 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v373 = v372[v575];
        int v576 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1)) & 3) * 2)) + ((((v363 + ((~(((v365 ^ -1) | (-(v365 ^ -1))) >> 31)) & 2)) - (v366 + ((~(((v367 ^ -1) | (-(v367 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v374 = v372[v576];
        int * v375 = v325->mem;
        int v578 = v371 * 2;
        v375[v578] = v373;
        int * v377 = v325->mem;
        int v581 = (v371 * 2) + 1;
        v377[v581] = v374;
        ;
      } else {
        ;
      }
      int * v382 = v325->mem;
      int v586 = ((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1)) * 2;
      int v383 = v382[v586];
      int v587 = (((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1)) * 2) + 1;
      int v384 = v382[v587];
      int * v385 = v325->cache_vals;
      int v589 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1)) & 3) * 2)) + ((((v363 + ((~(((v365 ^ -1) | (-(v365 ^ -1))) >> 31)) & 2)) - (v366 + ((~(((v367 ^ -1) | (-(v367 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v385[v589] = v383;
      int * v387 = v325->cache_vals;
      int v592 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1)) & 3) * 2)) + ((((v363 + ((~(((v365 ^ -1) | (-(v365 ^ -1))) >> 31)) & 2)) - (v366 + ((~(((v367 ^ -1) | (-(v367 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v387[v592] = v384;
      int * v389 = v325->cache_tags;
      int v595 = (int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1);
      v389[v571] = v595;
      int * v391 = v325->cache_dirty;
      v391[v571] = 0;
      int * v393 = v325->cache_age;
      v393[v571] = 1;
      int * v395 = v325->cache_age;
      int v396 = v395[v571];
      int v397 = v395[v545];
      int v601 = v397 + ((int)((unsigned int)(v397 - v396) >> 31));
      v395[v545] = v601;
      int * v399 = v325->cache_age;
      int v400 = v399[v546];
      int v603 = v400 + ((int)((unsigned int)(v400 - v396) >> 31));
      v399[v546] = v603;
      int * v402 = v325->cache_age;
      v402[v571] = 0;
      v405 = v571;
    }
    int * v406 = v325->cache_vals;
    int v606 = v405 * 2;
    int v407 = v406[v606];
    int v607 = (v405 * 2) + 1;
    int v408 = v406[v607];
    int v608 = (((((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1)) & 1) * 2) + ((((v347 + ((~(((v349 ^ -1) | (-(v349 ^ -1))) >> 31)) & 2)) - (v350 + ((~(((v351 ^ -1) | (-(v351 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v406[v608] = v407;
    int * v410 = v325->cache_vals;
    int v611 = ((((((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1)) & 1) * 2) + ((((v347 + ((~(((v349 ^ -1) | (-(v349 ^ -1))) >> 31)) & 2)) - (v350 + ((~(((v351 ^ -1) | (-(v351 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v410[v611] = v408;
    int * v412 = v325->cache_tags;
    int v614 = ((((int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1)) & 1) * 2) + ((((v347 + ((~(((v349 ^ -1) | (-(v349 ^ -1))) >> 31)) & 2)) - (v350 + ((~(((v351 ^ -1) | (-(v351 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v615 = (int)((unsigned int)((int)((unsigned int)v327 >> 2)) >> 1);
    v412[v614] = v615;
    int * v414 = v325->cache_dirty;
    v414[v614] = 0;
    int * v416 = v325->cache_age;
    v416[v614] = 1;
    int * v418 = v325->cache_age;
    int v419 = v418[v614];
    int v420 = v418[v543];
    int v621 = v420 + ((int)((unsigned int)(v420 - v419) >> 31));
    v418[v543] = v621;
    int * v422 = v325->cache_age;
    int v423 = v422[v544];
    int v623 = v423 + ((int)((unsigned int)(v423 - v419) >> 31));
    v422[v544] = v623;
    int * v425 = v325->cache_age;
    v425[v614] = 0;
    v428 = v614;
  }
  int v626 = (v428 * 2) + (((int)((unsigned int)v327 >> 2)) & 1);
  int v429 = v335[v626];
  int * v430 = v325->regs;
  v430[11] = v429;
  struct StateT2 * v432 = slot_6(v195);
  return v432;
}

struct StateT2 * slot_4(struct StateT2 * v134) {
  struct StateT * v135 = v134->a;
  int v136 = v135->timer;
  struct StateT * v137 = v134->b;
  int v138 = v137->timer;
  bool v171 = v136 == v138;
  squared_assert(v171);
  squared_assume(v171);
  struct StateT * v141 = v134->a;
  int * v142 = v141->saved_regs;
  int * v143 = v141->regs;
  int v144 = v143[5];
  v142[5] = v144;
  struct StateT * v146 = v134->b;
  int * v147 = v146->saved_regs;
  int * v148 = v146->regs;
  int v149 = v148[5];
  v147[5] = v149;
  struct StateT * v151 = v134->a;
  int v152 = v151->timer;
  int v182 = v152 + 1;
  v151->timer = v182;
  struct StateT * v154 = v134->b;
  int v155 = v154->timer;
  int v184 = v155 + 1;
  v154->timer = v184;
  struct StateT * v157 = v134->a;
  int * v158 = v157->regs;
  int v159 = v158[13];
  int v160 = v158[10];
  int v189 = v159 + v160;
  v158[5] = v189;
  struct StateT * v162 = v134->b;
  int * v163 = v162->regs;
  int v164 = v163[13];
  int v165 = v163[10];
  int v192 = v164 + v165;
  v163[5] = v192;
  struct StateT2 * v167 = slot_5(v134);
  return v167;
}

struct StateT2 * slot_2(struct StateT2 * v74) {
  struct StateT * v75 = v74->a;
  int v76 = v75->timer;
  struct StateT * v77 = v74->b;
  int v78 = v77->timer;
  bool v97 = v76 == v78;
  squared_assert(v97);
  squared_assume(v97);
  struct StateT * v81 = v74->a;
  int v82 = v81->timer;
  int v99 = v82 + 1;
  v81->timer = v99;
  struct StateT * v84 = v74->b;
  int v85 = v84->timer;
  int v101 = v85 + 1;
  v84->timer = v101;
  struct StateT * v87 = v74->a;
  int * v88 = v87->regs;
  v88[15] = 80;
  struct StateT * v90 = v74->b;
  int * v91 = v90->regs;
  v91[15] = 80;
  struct StateT2 * v93 = slot_3(v74);
  return v93;
}

struct StateT2 * slot_7(struct StateT2 * v670) {
  struct StateT * v671 = v670->a;
  int v672 = v671->timer;
  struct StateT * v673 = v670->b;
  int v674 = v673->timer;
  bool v911 = v672 == v674;
  squared_assert(v911);
  squared_assume(v911);
  struct StateT * v677 = v670->a;
  int * v678 = v677->saved_regs;
  int * v679 = v677->regs;
  int v680 = v679[12];
  v678[12] = v680;
  struct StateT * v682 = v670->b;
  int * v683 = v682->saved_regs;
  int * v684 = v682->regs;
  int v685 = v684[12];
  v683[12] = v685;
  struct StateT * v687 = v670->a;
  int v688 = v687->timer;
  int v922 = v688 + 1;
  v687->timer = v922;
  struct StateT * v690 = v670->b;
  int v691 = v690->timer;
  int v924 = v691 + 1;
  v690->timer = v924;
  struct StateT * v693 = v670->a;
  int * v694 = v693->regs;
  int v695 = v694[11];
  int * v696 = v693->cache_tags;
  int v929 = (((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1)) & 1) * 2;
  int v697 = v696[v929];
  int v930 = ((((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1)) & 1) * 2) + 1;
  int v698 = v696[v930];
  int v931 = 4 + ((((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1)) & 3) * 2);
  int v699 = v696[v931];
  int v932 = (4 + ((((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v700 = v696[v932];
  int v701 = v693->timer;
  int v933 = v701 + ((100 ^ (((~(((v699 ^ ((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1))) | (-(v699 ^ ((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1))))) >> 31)) | (~(((v700 ^ ((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1))) | (-(v700 ^ ((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v697 ^ ((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1))) | (-(v697 ^ ((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1))))) >> 31)) | (~(((v698 ^ ((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1))) | (-(v698 ^ ((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v699 ^ ((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1))) | (-(v699 ^ ((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1))))) >> 31)) | (~(((v700 ^ ((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1))) | (-(v700 ^ ((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1))))) >> 31))) & 104)))));
  v693->timer = v933;
  int * v703 = v693->cache_vals;
  bool v934 = !(((~(((v697 ^ ((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1))) | (-(v697 ^ ((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1))))) >> 31)) | (~(((v698 ^ ((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1))) | (-(v698 ^ ((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1))))) >> 31))) == 0);
  int v796;
  if (v934) {
    int * v704 = v693->cache_age;
    int v936 = ((((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1)) & 1) * 2) + ((~(((v698 ^ ((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1))) | (-(v698 ^ ((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1))))) >> 31)) & 1);
    int v705 = v704[v936];
    int v706 = v704[v929];
    int v937 = v706 + ((int)((unsigned int)(v706 - v705) >> 31));
    v704[v929] = v937;
    int * v708 = v693->cache_age;
    int v709 = v708[v930];
    int v939 = v709 + ((int)((unsigned int)(v709 - v705) >> 31));
    v708[v930] = v939;
    int * v711 = v693->cache_age;
    v711[v936] = 0;
    v796 = v936;
  } else {
    int * v714 = v693->cache_age;
    int v943 = (((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1)) & 1) * 2;
    int v715 = v714[v943];
    int * v716 = v693->cache_tags;
    int v717 = v716[v943];
    int v718 = v714[v930];
    int v719 = v716[v930];
    bool v945 = !(((~(((v699 ^ ((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1))) | (-(v699 ^ ((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1))))) >> 31)) | (~(((v700 ^ ((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1))) | (-(v700 ^ ((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1))))) >> 31))) == 0);
    int v773;
    if (v945) {
      int * v720 = v693->cache_age;
      int v947 = (4 + ((((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1)) & 3) * 2)) + ((~(((v700 ^ ((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1))) | (-(v700 ^ ((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1))))) >> 31)) & 1);
      int v721 = v720[v947];
      int v722 = v720[v931];
      int v948 = v722 + ((int)((unsigned int)(v722 - v721) >> 31));
      v720[v931] = v948;
      int * v724 = v693->cache_age;
      int v725 = v724[v932];
      int v950 = v725 + ((int)((unsigned int)(v725 - v721) >> 31));
      v724[v932] = v950;
      int * v727 = v693->cache_age;
      v727[v947] = 0;
      v773 = v947;
    } else {
      int * v730 = v693->cache_age;
      int v954 = 4 + ((((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1)) & 3) * 2);
      int v731 = v730[v954];
      int * v732 = v693->cache_tags;
      int v733 = v732[v954];
      int v734 = v730[v932];
      int v735 = v732[v932];
      int * v736 = v693->cache_dirty;
      int v957 = (4 + ((((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1)) & 3) * 2)) + ((((v731 + ((~(((v733 ^ -1) | (-(v733 ^ -1))) >> 31)) & 2)) - (v734 + ((~(((v735 ^ -1) | (-(v735 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v737 = v736[v957];
      bool v958 = !(v737 == 0);
      if (v958) {
        int * v738 = v693->cache_tags;
        int v739 = v738[v957];
        int * v740 = v693->cache_vals;
        int v961 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1)) & 3) * 2)) + ((((v731 + ((~(((v733 ^ -1) | (-(v733 ^ -1))) >> 31)) & 2)) - (v734 + ((~(((v735 ^ -1) | (-(v735 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v741 = v740[v961];
        int v962 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1)) & 3) * 2)) + ((((v731 + ((~(((v733 ^ -1) | (-(v733 ^ -1))) >> 31)) & 2)) - (v734 + ((~(((v735 ^ -1) | (-(v735 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v742 = v740[v962];
        int * v743 = v693->mem;
        int v964 = v739 * 2;
        v743[v964] = v741;
        int * v745 = v693->mem;
        int v967 = (v739 * 2) + 1;
        v745[v967] = v742;
        ;
      } else {
        ;
      }
      int * v750 = v693->mem;
      int v972 = ((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1)) * 2;
      int v751 = v750[v972];
      int v973 = (((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1)) * 2) + 1;
      int v752 = v750[v973];
      int * v753 = v693->cache_vals;
      int v975 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1)) & 3) * 2)) + ((((v731 + ((~(((v733 ^ -1) | (-(v733 ^ -1))) >> 31)) & 2)) - (v734 + ((~(((v735 ^ -1) | (-(v735 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v753[v975] = v751;
      int * v755 = v693->cache_vals;
      int v978 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1)) & 3) * 2)) + ((((v731 + ((~(((v733 ^ -1) | (-(v733 ^ -1))) >> 31)) & 2)) - (v734 + ((~(((v735 ^ -1) | (-(v735 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v755[v978] = v752;
      int * v757 = v693->cache_tags;
      int v981 = (int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1);
      v757[v957] = v981;
      int * v759 = v693->cache_dirty;
      v759[v957] = 0;
      int * v761 = v693->cache_age;
      v761[v957] = 1;
      int * v763 = v693->cache_age;
      int v764 = v763[v957];
      int v765 = v763[v931];
      int v987 = v765 + ((int)((unsigned int)(v765 - v764) >> 31));
      v763[v931] = v987;
      int * v767 = v693->cache_age;
      int v768 = v767[v932];
      int v989 = v768 + ((int)((unsigned int)(v768 - v764) >> 31));
      v767[v932] = v989;
      int * v770 = v693->cache_age;
      v770[v957] = 0;
      v773 = v957;
    }
    int * v774 = v693->cache_vals;
    int v992 = v773 * 2;
    int v775 = v774[v992];
    int v993 = (v773 * 2) + 1;
    int v776 = v774[v993];
    int v994 = (((((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1)) & 1) * 2) + ((((v715 + ((~(((v717 ^ -1) | (-(v717 ^ -1))) >> 31)) & 2)) - (v718 + ((~(((v719 ^ -1) | (-(v719 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v774[v994] = v775;
    int * v778 = v693->cache_vals;
    int v997 = ((((((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1)) & 1) * 2) + ((((v715 + ((~(((v717 ^ -1) | (-(v717 ^ -1))) >> 31)) & 2)) - (v718 + ((~(((v719 ^ -1) | (-(v719 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v778[v997] = v776;
    int * v780 = v693->cache_tags;
    int v1000 = ((((int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1)) & 1) * 2) + ((((v715 + ((~(((v717 ^ -1) | (-(v717 ^ -1))) >> 31)) & 2)) - (v718 + ((~(((v719 ^ -1) | (-(v719 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1001 = (int)((unsigned int)((int)((unsigned int)v695 >> 2)) >> 1);
    v780[v1000] = v1001;
    int * v782 = v693->cache_dirty;
    v782[v1000] = 0;
    int * v784 = v693->cache_age;
    v784[v1000] = 1;
    int * v786 = v693->cache_age;
    int v787 = v786[v1000];
    int v788 = v786[v929];
    int v1007 = v788 + ((int)((unsigned int)(v788 - v787) >> 31));
    v786[v929] = v1007;
    int * v790 = v693->cache_age;
    int v791 = v790[v930];
    int v1009 = v791 + ((int)((unsigned int)(v791 - v787) >> 31));
    v790[v930] = v1009;
    int * v793 = v693->cache_age;
    v793[v1000] = 0;
    v796 = v1000;
  }
  int v1012 = (v796 * 2) + (((int)((unsigned int)v695 >> 2)) & 1);
  int v797 = v703[v1012];
  int * v798 = v693->regs;
  v798[12] = v797;
  struct StateT * v800 = v670->b;
  int * v801 = v800->regs;
  int v802 = v801[11];
  int * v803 = v800->cache_tags;
  int v1018 = (((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1)) & 1) * 2;
  int v804 = v803[v1018];
  int v1019 = ((((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1)) & 1) * 2) + 1;
  int v805 = v803[v1019];
  int v1020 = 4 + ((((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1)) & 3) * 2);
  int v806 = v803[v1020];
  int v1021 = (4 + ((((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v807 = v803[v1021];
  int v808 = v800->timer;
  int v1022 = v808 + ((100 ^ (((~(((v806 ^ ((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1))) | (-(v806 ^ ((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1))))) >> 31)) | (~(((v807 ^ ((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1))) | (-(v807 ^ ((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v804 ^ ((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1))) | (-(v804 ^ ((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1))))) >> 31)) | (~(((v805 ^ ((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1))) | (-(v805 ^ ((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v806 ^ ((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1))) | (-(v806 ^ ((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1))))) >> 31)) | (~(((v807 ^ ((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1))) | (-(v807 ^ ((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1))))) >> 31))) & 104)))));
  v800->timer = v1022;
  int * v810 = v800->cache_vals;
  bool v1023 = !(((~(((v804 ^ ((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1))) | (-(v804 ^ ((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1))))) >> 31)) | (~(((v805 ^ ((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1))) | (-(v805 ^ ((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1))))) >> 31))) == 0);
  int v903;
  if (v1023) {
    int * v811 = v800->cache_age;
    int v1025 = ((((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1)) & 1) * 2) + ((~(((v805 ^ ((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1))) | (-(v805 ^ ((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1))))) >> 31)) & 1);
    int v812 = v811[v1025];
    int v813 = v811[v1018];
    int v1026 = v813 + ((int)((unsigned int)(v813 - v812) >> 31));
    v811[v1018] = v1026;
    int * v815 = v800->cache_age;
    int v816 = v815[v1019];
    int v1028 = v816 + ((int)((unsigned int)(v816 - v812) >> 31));
    v815[v1019] = v1028;
    int * v818 = v800->cache_age;
    v818[v1025] = 0;
    v903 = v1025;
  } else {
    int * v821 = v800->cache_age;
    int v1032 = (((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1)) & 1) * 2;
    int v822 = v821[v1032];
    int * v823 = v800->cache_tags;
    int v824 = v823[v1032];
    int v825 = v821[v1019];
    int v826 = v823[v1019];
    bool v1034 = !(((~(((v806 ^ ((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1))) | (-(v806 ^ ((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1))))) >> 31)) | (~(((v807 ^ ((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1))) | (-(v807 ^ ((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1))))) >> 31))) == 0);
    int v880;
    if (v1034) {
      int * v827 = v800->cache_age;
      int v1036 = (4 + ((((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1)) & 3) * 2)) + ((~(((v807 ^ ((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1))) | (-(v807 ^ ((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1))))) >> 31)) & 1);
      int v828 = v827[v1036];
      int v829 = v827[v1020];
      int v1037 = v829 + ((int)((unsigned int)(v829 - v828) >> 31));
      v827[v1020] = v1037;
      int * v831 = v800->cache_age;
      int v832 = v831[v1021];
      int v1039 = v832 + ((int)((unsigned int)(v832 - v828) >> 31));
      v831[v1021] = v1039;
      int * v834 = v800->cache_age;
      v834[v1036] = 0;
      v880 = v1036;
    } else {
      int * v837 = v800->cache_age;
      int v1043 = 4 + ((((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1)) & 3) * 2);
      int v838 = v837[v1043];
      int * v839 = v800->cache_tags;
      int v840 = v839[v1043];
      int v841 = v837[v1021];
      int v842 = v839[v1021];
      int * v843 = v800->cache_dirty;
      int v1046 = (4 + ((((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1)) & 3) * 2)) + ((((v838 + ((~(((v840 ^ -1) | (-(v840 ^ -1))) >> 31)) & 2)) - (v841 + ((~(((v842 ^ -1) | (-(v842 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v844 = v843[v1046];
      bool v1047 = !(v844 == 0);
      if (v1047) {
        int * v845 = v800->cache_tags;
        int v846 = v845[v1046];
        int * v847 = v800->cache_vals;
        int v1050 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1)) & 3) * 2)) + ((((v838 + ((~(((v840 ^ -1) | (-(v840 ^ -1))) >> 31)) & 2)) - (v841 + ((~(((v842 ^ -1) | (-(v842 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v848 = v847[v1050];
        int v1051 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1)) & 3) * 2)) + ((((v838 + ((~(((v840 ^ -1) | (-(v840 ^ -1))) >> 31)) & 2)) - (v841 + ((~(((v842 ^ -1) | (-(v842 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v849 = v847[v1051];
        int * v850 = v800->mem;
        int v1053 = v846 * 2;
        v850[v1053] = v848;
        int * v852 = v800->mem;
        int v1056 = (v846 * 2) + 1;
        v852[v1056] = v849;
        ;
      } else {
        ;
      }
      int * v857 = v800->mem;
      int v1061 = ((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1)) * 2;
      int v858 = v857[v1061];
      int v1062 = (((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1)) * 2) + 1;
      int v859 = v857[v1062];
      int * v860 = v800->cache_vals;
      int v1064 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1)) & 3) * 2)) + ((((v838 + ((~(((v840 ^ -1) | (-(v840 ^ -1))) >> 31)) & 2)) - (v841 + ((~(((v842 ^ -1) | (-(v842 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v860[v1064] = v858;
      int * v862 = v800->cache_vals;
      int v1067 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1)) & 3) * 2)) + ((((v838 + ((~(((v840 ^ -1) | (-(v840 ^ -1))) >> 31)) & 2)) - (v841 + ((~(((v842 ^ -1) | (-(v842 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v862[v1067] = v859;
      int * v864 = v800->cache_tags;
      int v1070 = (int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1);
      v864[v1046] = v1070;
      int * v866 = v800->cache_dirty;
      v866[v1046] = 0;
      int * v868 = v800->cache_age;
      v868[v1046] = 1;
      int * v870 = v800->cache_age;
      int v871 = v870[v1046];
      int v872 = v870[v1020];
      int v1076 = v872 + ((int)((unsigned int)(v872 - v871) >> 31));
      v870[v1020] = v1076;
      int * v874 = v800->cache_age;
      int v875 = v874[v1021];
      int v1078 = v875 + ((int)((unsigned int)(v875 - v871) >> 31));
      v874[v1021] = v1078;
      int * v877 = v800->cache_age;
      v877[v1046] = 0;
      v880 = v1046;
    }
    int * v881 = v800->cache_vals;
    int v1081 = v880 * 2;
    int v882 = v881[v1081];
    int v1082 = (v880 * 2) + 1;
    int v883 = v881[v1082];
    int v1083 = (((((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1)) & 1) * 2) + ((((v822 + ((~(((v824 ^ -1) | (-(v824 ^ -1))) >> 31)) & 2)) - (v825 + ((~(((v826 ^ -1) | (-(v826 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v881[v1083] = v882;
    int * v885 = v800->cache_vals;
    int v1086 = ((((((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1)) & 1) * 2) + ((((v822 + ((~(((v824 ^ -1) | (-(v824 ^ -1))) >> 31)) & 2)) - (v825 + ((~(((v826 ^ -1) | (-(v826 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v885[v1086] = v883;
    int * v887 = v800->cache_tags;
    int v1089 = ((((int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1)) & 1) * 2) + ((((v822 + ((~(((v824 ^ -1) | (-(v824 ^ -1))) >> 31)) & 2)) - (v825 + ((~(((v826 ^ -1) | (-(v826 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1090 = (int)((unsigned int)((int)((unsigned int)v802 >> 2)) >> 1);
    v887[v1089] = v1090;
    int * v889 = v800->cache_dirty;
    v889[v1089] = 0;
    int * v891 = v800->cache_age;
    v891[v1089] = 1;
    int * v893 = v800->cache_age;
    int v894 = v893[v1089];
    int v895 = v893[v1018];
    int v1096 = v895 + ((int)((unsigned int)(v895 - v894) >> 31));
    v893[v1018] = v1096;
    int * v897 = v800->cache_age;
    int v898 = v897[v1019];
    int v1098 = v898 + ((int)((unsigned int)(v898 - v894) >> 31));
    v897[v1019] = v1098;
    int * v900 = v800->cache_age;
    v900[v1089] = 0;
    v903 = v1089;
  }
  int v1101 = (v903 * 2) + (((int)((unsigned int)v802 >> 2)) & 1);
  int v904 = v810[v1101];
  int * v905 = v800->regs;
  v905[12] = v904;
  struct StateT2 * v907 = slot_8(v670);
  return v907;
}

struct StateT2 * slot_3(struct StateT2 * v110) {
  struct StateT * v111 = v110->a;
  int v112 = v111->timer;
  struct StateT * v113 = v110->b;
  int v114 = v113->timer;
  bool v127 = v112 == v114;
  squared_assert(v127);
  squared_assume(v127);
  struct StateT * v117 = v110->a;
  int v118 = v117->timer;
  int v129 = v118 + 1;
  v117->timer = v129;
  struct StateT * v120 = v110->b;
  int v121 = v120->timer;
  int v131 = v121 + 1;
  v120->timer = v131;
  struct StateT2 * v123 = slot_4(v110);
  return v123;
}

struct StateT2 * slot_0(struct StateT2 * v2) {
  struct StateT * v3 = v2->a;
  int v4 = v3->timer;
  struct StateT * v5 = v2->b;
  int v6 = v5->timer;
  bool v25 = v4 == v6;
  squared_assert(v25);
  squared_assume(v25);
  struct StateT * v9 = v2->a;
  int v10 = v9->timer;
  int v27 = v10 + 1;
  v9->timer = v27;
  struct StateT * v12 = v2->b;
  int v13 = v12->timer;
  int v29 = v13 + 1;
  v12->timer = v29;
  struct StateT * v15 = v2->a;
  int * v16 = v15->regs;
  v16[13] = 0;
  struct StateT * v18 = v2->b;
  int * v19 = v18->regs;
  v19[13] = 0;
  struct StateT2 * v21 = slot_1(v2);
  return v21;
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

void squared_assert(bool c) { koika_assert(c, "timer drift"); }
void squared_diverged(bool c) { koika_assert(c, "control flow diverged"); }
void squared_assume(bool c) { koika_assume(c); }

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
  struct StateT2 p = { .a = &s1, .b = &s2 };
  struct StateT2 *p_ = snippet(&p);
  //@ assert untainted_timer: !\tainted(p_->a->timer==p_->b->timer);
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}