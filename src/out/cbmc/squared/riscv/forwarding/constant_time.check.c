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

struct StateT2 * slot_12(struct StateT2 * v1321);
struct StateT2 * slot_6(struct StateT2 * v206);
struct StateT2 * slot_16(struct StateT2 * v1552);
struct StateT2 * slot_23(struct StateT2 * v2657);
struct StateT2 * slot_5(struct StateT2 * v182);
struct StateT2 * slot_2(struct StateT2 * v74);
struct StateT2 * slot_7(struct StateT2 * v267);
struct StateT2 * slot_21(struct StateT2 * v2160);
struct StateT2 * slot_3(struct StateT2 * v110);
struct StateT2 * slot_10(struct StateT2 * v1200);
struct StateT2 * slot_1(struct StateT2 * v38);
struct StateT2 * slot_13(struct StateT2 * v1460);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * slot_14(struct StateT2 * v1513);
struct StateT2 * slot_20(struct StateT2 * v2099);
struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_4(struct StateT2 * v146);
struct StateT2 * slot_12(struct StateT2 * v1321) {
  struct StateT * v1322 = v1321->a;
  int v1323 = v1322->timer;
  struct StateT * v1324 = v1321->b;
  int v1325 = v1324->timer;
  bool v1400 = v1323 == v1325;
  squared_assert(v1400);
  squared_assume(v1400);
  struct StateT * v1328 = v1321->a;
  int * v1329 = v1328->regs;
  int v1330 = v1329[14];
  int v1331 = v1329[15];
  struct StateT * v1332 = v1321->b;
  int * v1333 = v1332->regs;
  int v1334 = v1333[14];
  int v1335 = v1333[15];
  bool v1407 = (v1330 >= v1331) == (v1334 >= v1335);
  squared_diverged(v1407);
  squared_assume(v1407);
  bool v1408 = v1330 >= v1331;
  struct StateT2 * v1396;
  if (v1408) {
    struct StateT * v1338 = v1321->a;
    int v1339 = v1338->timer;
    int v1410 = v1339 + 15;
    v1338->timer = v1410;
    int * v1341 = v1338->saved_regs;
    int v1342 = v1341[6];
    int * v1343 = v1338->regs;
    v1343[6] = v1342;
    int * v1345 = v1338->saved_regs;
    int v1346 = v1345[7];
    int * v1347 = v1338->regs;
    v1347[7] = v1346;
    int * v1349 = v1338->saved_regs;
    int v1350 = v1349[8];
    int * v1351 = v1338->regs;
    v1351[8] = v1350;
    int * v1353 = v1338->saved_regs;
    int v1354 = v1353[9];
    int * v1355 = v1338->regs;
    v1355[9] = v1354;
    int * v1357 = v1338->saved_regs;
    int v1358 = v1357[16];
    int * v1359 = v1338->regs;
    v1359[16] = v1358;
    int * v1361 = v1338->saved_regs;
    int v1362 = v1361[5];
    int * v1363 = v1338->regs;
    v1363[5] = v1362;
    struct StateT * v1365 = v1321->b;
    int v1366 = v1365->timer;
    int v1436 = v1366 + 15;
    v1365->timer = v1436;
    int * v1368 = v1365->saved_regs;
    int v1369 = v1368[6];
    int * v1370 = v1365->regs;
    v1370[6] = v1369;
    int * v1372 = v1365->saved_regs;
    int v1373 = v1372[7];
    int * v1374 = v1365->regs;
    v1374[7] = v1373;
    int * v1376 = v1365->saved_regs;
    int v1377 = v1376[8];
    int * v1378 = v1365->regs;
    v1378[8] = v1377;
    int * v1380 = v1365->saved_regs;
    int v1381 = v1380[9];
    int * v1382 = v1365->regs;
    v1382[9] = v1381;
    int * v1384 = v1365->saved_regs;
    int v1385 = v1384[16];
    int * v1386 = v1365->regs;
    v1386[16] = v1385;
    int * v1388 = v1365->saved_regs;
    int v1389 = v1388[5];
    int * v1390 = v1365->regs;
    v1390[5] = v1389;
    struct StateT2 * v1392 = slot_13(v1321);
    v1396 = v1392;
  } else {
    struct StateT2 * v1394 = slot_14(v1321);
    v1396 = v1394;
  }
  return v1396;
}

struct StateT2 * slot_6(struct StateT2 * v206) {
  struct StateT * v207 = v206->a;
  int v208 = v207->timer;
  struct StateT * v209 = v206->b;
  int v210 = v209->timer;
  bool v243 = v208 == v210;
  squared_assert(v243);
  squared_assume(v243);
  struct StateT * v213 = v206->a;
  int * v214 = v213->saved_regs;
  int * v215 = v213->regs;
  int v216 = v215[6];
  v214[6] = v216;
  struct StateT * v218 = v206->b;
  int * v219 = v218->saved_regs;
  int * v220 = v218->regs;
  int v221 = v220[6];
  v219[6] = v221;
  struct StateT * v223 = v206->a;
  int v224 = v223->timer;
  int v254 = v224 + 1;
  v223->timer = v254;
  struct StateT * v226 = v206->b;
  int v227 = v226->timer;
  int v256 = v227 + 1;
  v226->timer = v256;
  struct StateT * v229 = v206->a;
  int * v230 = v229->regs;
  int v231 = v230[12];
  int v232 = v230[14];
  int v261 = v231 + v232;
  v230[6] = v261;
  struct StateT * v234 = v206->b;
  int * v235 = v234->regs;
  int v236 = v235[12];
  int v237 = v235[14];
  int v264 = v236 + v237;
  v235[6] = v264;
  struct StateT2 * v239 = slot_7(v206);
  return v239;
}

struct StateT2 * slot_16(struct StateT2 * v1552) {
  struct StateT * v1553 = v1552->a;
  int v1554 = v1553->timer;
  struct StateT * v1555 = v1552->b;
  int v1556 = v1555->timer;
  bool v1571 = v1554 == v1556;
  squared_assert(v1571);
  squared_assume(v1571);
  struct StateT * v1559 = v1552->a;
  int v1560 = v1559->timer;
  int v1573 = v1560 + 1;
  v1559->timer = v1573;
  struct StateT * v1562 = v1552->b;
  int v1563 = v1562->timer;
  int v1575 = v1563 + 1;
  v1562->timer = v1575;
  struct StateT2 * v1567 = slot_5(v1552);
  return v1567;
}

struct StateT2 * slot_23(struct StateT2 * v2657) {
  struct StateT * v2658 = v2657->a;
  int v2659 = v2658->timer;
  struct StateT * v2660 = v2657->b;
  int v2661 = v2660->timer;
  bool v2694 = v2659 == v2661;
  squared_assert(v2694);
  squared_assume(v2694);
  struct StateT * v2664 = v2657->a;
  int * v2665 = v2664->saved_regs;
  int * v2666 = v2664->regs;
  int v2667 = v2666[5];
  v2665[5] = v2667;
  struct StateT * v2669 = v2657->b;
  int * v2670 = v2669->saved_regs;
  int * v2671 = v2669->regs;
  int v2672 = v2671[5];
  v2670[5] = v2672;
  struct StateT * v2674 = v2657->a;
  int v2675 = v2674->timer;
  int v2705 = v2675 + 1;
  v2674->timer = v2705;
  struct StateT * v2677 = v2657->b;
  int v2678 = v2677->timer;
  int v2707 = v2678 + 1;
  v2677->timer = v2707;
  struct StateT * v2680 = v2657->a;
  int * v2681 = v2680->regs;
  int v2682 = v2681[5];
  int v2683 = v2681[16];
  int v2711 = v2682 | v2683;
  v2681[5] = v2711;
  struct StateT * v2685 = v2657->b;
  int * v2686 = v2685->regs;
  int v2687 = v2686[5];
  int v2688 = v2686[16];
  int v2714 = v2687 | v2688;
  v2686[5] = v2714;
  struct StateT2 * v2690 = slot_12(v2657);
  return v2690;
}

struct StateT2 * slot_5(struct StateT2 * v182) {
  struct StateT * v183 = v182->a;
  int v184 = v183->timer;
  struct StateT * v185 = v182->b;
  int v186 = v185->timer;
  bool v199 = v184 == v186;
  squared_assert(v199);
  squared_assume(v199);
  struct StateT * v189 = v182->a;
  int v190 = v189->timer;
  int v201 = v190 + 1;
  v189->timer = v201;
  struct StateT * v192 = v182->b;
  int v193 = v192->timer;
  int v203 = v193 + 1;
  v192->timer = v203;
  struct StateT2 * v195 = slot_6(v182);
  return v195;
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
  v88[14] = 0;
  struct StateT * v90 = v74->b;
  int * v91 = v90->regs;
  v91[14] = 0;
  struct StateT2 * v93 = slot_3(v74);
  return v93;
}

struct StateT2 * slot_7(struct StateT2 * v267) {
  struct StateT * v268 = v267->a;
  int v269 = v268->timer;
  struct StateT * v270 = v267->b;
  int v271 = v270->timer;
  bool v508 = v269 == v271;
  squared_assert(v508);
  squared_assume(v508);
  struct StateT * v274 = v267->a;
  int * v275 = v274->saved_regs;
  int * v276 = v274->regs;
  int v277 = v276[7];
  v275[7] = v277;
  struct StateT * v279 = v267->b;
  int * v280 = v279->saved_regs;
  int * v281 = v279->regs;
  int v282 = v281[7];
  v280[7] = v282;
  struct StateT * v284 = v267->a;
  int v285 = v284->timer;
  int v519 = v285 + 1;
  v284->timer = v519;
  struct StateT * v287 = v267->b;
  int v288 = v287->timer;
  int v521 = v288 + 1;
  v287->timer = v521;
  struct StateT * v290 = v267->a;
  int * v291 = v290->regs;
  int v292 = v291[6];
  int * v293 = v290->cache_tags;
  int v526 = (((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1)) & 1) * 2;
  int v294 = v293[v526];
  int v527 = ((((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1)) & 1) * 2) + 1;
  int v295 = v293[v527];
  int v528 = 4 + ((((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1)) & 3) * 2);
  int v296 = v293[v528];
  int v529 = (4 + ((((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v297 = v293[v529];
  int v298 = v290->timer;
  int v530 = v298 + ((100 ^ (((~(((v296 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))) | (-(v296 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))))) >> 31)) | (~(((v297 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))) | (-(v297 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v294 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))) | (-(v294 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))))) >> 31)) | (~(((v295 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))) | (-(v295 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v296 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))) | (-(v296 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))))) >> 31)) | (~(((v297 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))) | (-(v297 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))))) >> 31))) & 104)))));
  v290->timer = v530;
  int * v300 = v290->cache_vals;
  bool v531 = !(((~(((v294 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))) | (-(v294 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))))) >> 31)) | (~(((v295 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))) | (-(v295 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))))) >> 31))) == 0);
  int v393;
  if (v531) {
    int * v301 = v290->cache_age;
    int v533 = ((((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1)) & 1) * 2) + ((~(((v295 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))) | (-(v295 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))))) >> 31)) & 1);
    int v302 = v301[v533];
    int v303 = v301[v526];
    int v534 = v303 + ((int)((unsigned int)(v303 - v302) >> 31));
    v301[v526] = v534;
    int * v305 = v290->cache_age;
    int v306 = v305[v527];
    int v536 = v306 + ((int)((unsigned int)(v306 - v302) >> 31));
    v305[v527] = v536;
    int * v308 = v290->cache_age;
    v308[v533] = 0;
    v393 = v533;
  } else {
    int * v311 = v290->cache_age;
    int v540 = (((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1)) & 1) * 2;
    int v312 = v311[v540];
    int * v313 = v290->cache_tags;
    int v314 = v313[v540];
    int v315 = v311[v527];
    int v316 = v313[v527];
    bool v542 = !(((~(((v296 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))) | (-(v296 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))))) >> 31)) | (~(((v297 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))) | (-(v297 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))))) >> 31))) == 0);
    int v370;
    if (v542) {
      int * v317 = v290->cache_age;
      int v544 = (4 + ((((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1)) & 3) * 2)) + ((~(((v297 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))) | (-(v297 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))))) >> 31)) & 1);
      int v318 = v317[v544];
      int v319 = v317[v528];
      int v545 = v319 + ((int)((unsigned int)(v319 - v318) >> 31));
      v317[v528] = v545;
      int * v321 = v290->cache_age;
      int v322 = v321[v529];
      int v547 = v322 + ((int)((unsigned int)(v322 - v318) >> 31));
      v321[v529] = v547;
      int * v324 = v290->cache_age;
      v324[v544] = 0;
      v370 = v544;
    } else {
      int * v327 = v290->cache_age;
      int v551 = 4 + ((((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1)) & 3) * 2);
      int v328 = v327[v551];
      int * v329 = v290->cache_tags;
      int v330 = v329[v551];
      int v331 = v327[v529];
      int v332 = v329[v529];
      int * v333 = v290->cache_dirty;
      int v554 = (4 + ((((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1)) & 3) * 2)) + ((((v328 + ((~(((v330 ^ -1) | (-(v330 ^ -1))) >> 31)) & 2)) - (v331 + ((~(((v332 ^ -1) | (-(v332 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v334 = v333[v554];
      bool v555 = !(v334 == 0);
      if (v555) {
        int * v335 = v290->cache_tags;
        int v336 = v335[v554];
        int * v337 = v290->cache_vals;
        int v558 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1)) & 3) * 2)) + ((((v328 + ((~(((v330 ^ -1) | (-(v330 ^ -1))) >> 31)) & 2)) - (v331 + ((~(((v332 ^ -1) | (-(v332 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v338 = v337[v558];
        int v559 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1)) & 3) * 2)) + ((((v328 + ((~(((v330 ^ -1) | (-(v330 ^ -1))) >> 31)) & 2)) - (v331 + ((~(((v332 ^ -1) | (-(v332 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v339 = v337[v559];
        int * v340 = v290->mem;
        int v561 = v336 * 2;
        v340[v561] = v338;
        int * v342 = v290->mem;
        int v564 = (v336 * 2) + 1;
        v342[v564] = v339;
        ;
      } else {
        ;
      }
      int * v347 = v290->mem;
      int v569 = ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1)) * 2;
      int v348 = v347[v569];
      int v570 = (((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1)) * 2) + 1;
      int v349 = v347[v570];
      int * v350 = v290->cache_vals;
      int v572 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1)) & 3) * 2)) + ((((v328 + ((~(((v330 ^ -1) | (-(v330 ^ -1))) >> 31)) & 2)) - (v331 + ((~(((v332 ^ -1) | (-(v332 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v350[v572] = v348;
      int * v352 = v290->cache_vals;
      int v575 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1)) & 3) * 2)) + ((((v328 + ((~(((v330 ^ -1) | (-(v330 ^ -1))) >> 31)) & 2)) - (v331 + ((~(((v332 ^ -1) | (-(v332 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v352[v575] = v349;
      int * v354 = v290->cache_tags;
      int v578 = (int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1);
      v354[v554] = v578;
      int * v356 = v290->cache_dirty;
      v356[v554] = 0;
      int * v358 = v290->cache_age;
      v358[v554] = 1;
      int * v360 = v290->cache_age;
      int v361 = v360[v554];
      int v362 = v360[v528];
      int v584 = v362 + ((int)((unsigned int)(v362 - v361) >> 31));
      v360[v528] = v584;
      int * v364 = v290->cache_age;
      int v365 = v364[v529];
      int v586 = v365 + ((int)((unsigned int)(v365 - v361) >> 31));
      v364[v529] = v586;
      int * v367 = v290->cache_age;
      v367[v554] = 0;
      v370 = v554;
    }
    int * v371 = v290->cache_vals;
    int v589 = v370 * 2;
    int v372 = v371[v589];
    int v590 = (v370 * 2) + 1;
    int v373 = v371[v590];
    int v591 = (((((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1)) & 1) * 2) + ((((v312 + ((~(((v314 ^ -1) | (-(v314 ^ -1))) >> 31)) & 2)) - (v315 + ((~(((v316 ^ -1) | (-(v316 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v371[v591] = v372;
    int * v375 = v290->cache_vals;
    int v594 = ((((((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1)) & 1) * 2) + ((((v312 + ((~(((v314 ^ -1) | (-(v314 ^ -1))) >> 31)) & 2)) - (v315 + ((~(((v316 ^ -1) | (-(v316 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v375[v594] = v373;
    int * v377 = v290->cache_tags;
    int v597 = ((((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1)) & 1) * 2) + ((((v312 + ((~(((v314 ^ -1) | (-(v314 ^ -1))) >> 31)) & 2)) - (v315 + ((~(((v316 ^ -1) | (-(v316 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v598 = (int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1);
    v377[v597] = v598;
    int * v379 = v290->cache_dirty;
    v379[v597] = 0;
    int * v381 = v290->cache_age;
    v381[v597] = 1;
    int * v383 = v290->cache_age;
    int v384 = v383[v597];
    int v385 = v383[v526];
    int v604 = v385 + ((int)((unsigned int)(v385 - v384) >> 31));
    v383[v526] = v604;
    int * v387 = v290->cache_age;
    int v388 = v387[v527];
    int v606 = v388 + ((int)((unsigned int)(v388 - v384) >> 31));
    v387[v527] = v606;
    int * v390 = v290->cache_age;
    v390[v597] = 0;
    v393 = v597;
  }
  int v609 = (v393 * 2) + (((int)((unsigned int)v292 >> 2)) & 1);
  int v394 = v300[v609];
  int * v395 = v290->regs;
  v395[7] = v394;
  struct StateT * v397 = v267->b;
  int * v398 = v397->regs;
  int v399 = v398[6];
  int * v400 = v397->cache_tags;
  int v615 = (((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 1) * 2;
  int v401 = v400[v615];
  int v616 = ((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 1) * 2) + 1;
  int v402 = v400[v616];
  int v617 = 4 + ((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 3) * 2);
  int v403 = v400[v617];
  int v618 = (4 + ((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v404 = v400[v618];
  int v405 = v397->timer;
  int v619 = v405 + ((100 ^ (((~(((v403 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))) | (-(v403 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))))) >> 31)) | (~(((v404 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))) | (-(v404 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v401 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))) | (-(v401 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))))) >> 31)) | (~(((v402 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))) | (-(v402 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v403 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))) | (-(v403 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))))) >> 31)) | (~(((v404 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))) | (-(v404 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))))) >> 31))) & 104)))));
  v397->timer = v619;
  int * v407 = v397->cache_vals;
  bool v620 = !(((~(((v401 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))) | (-(v401 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))))) >> 31)) | (~(((v402 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))) | (-(v402 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))))) >> 31))) == 0);
  int v500;
  if (v620) {
    int * v408 = v397->cache_age;
    int v622 = ((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 1) * 2) + ((~(((v402 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))) | (-(v402 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))))) >> 31)) & 1);
    int v409 = v408[v622];
    int v410 = v408[v615];
    int v623 = v410 + ((int)((unsigned int)(v410 - v409) >> 31));
    v408[v615] = v623;
    int * v412 = v397->cache_age;
    int v413 = v412[v616];
    int v625 = v413 + ((int)((unsigned int)(v413 - v409) >> 31));
    v412[v616] = v625;
    int * v415 = v397->cache_age;
    v415[v622] = 0;
    v500 = v622;
  } else {
    int * v418 = v397->cache_age;
    int v629 = (((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 1) * 2;
    int v419 = v418[v629];
    int * v420 = v397->cache_tags;
    int v421 = v420[v629];
    int v422 = v418[v616];
    int v423 = v420[v616];
    bool v631 = !(((~(((v403 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))) | (-(v403 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))))) >> 31)) | (~(((v404 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))) | (-(v404 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))))) >> 31))) == 0);
    int v477;
    if (v631) {
      int * v424 = v397->cache_age;
      int v633 = (4 + ((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 3) * 2)) + ((~(((v404 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))) | (-(v404 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))))) >> 31)) & 1);
      int v425 = v424[v633];
      int v426 = v424[v617];
      int v634 = v426 + ((int)((unsigned int)(v426 - v425) >> 31));
      v424[v617] = v634;
      int * v428 = v397->cache_age;
      int v429 = v428[v618];
      int v636 = v429 + ((int)((unsigned int)(v429 - v425) >> 31));
      v428[v618] = v636;
      int * v431 = v397->cache_age;
      v431[v633] = 0;
      v477 = v633;
    } else {
      int * v434 = v397->cache_age;
      int v640 = 4 + ((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 3) * 2);
      int v435 = v434[v640];
      int * v436 = v397->cache_tags;
      int v437 = v436[v640];
      int v438 = v434[v618];
      int v439 = v436[v618];
      int * v440 = v397->cache_dirty;
      int v643 = (4 + ((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 3) * 2)) + ((((v435 + ((~(((v437 ^ -1) | (-(v437 ^ -1))) >> 31)) & 2)) - (v438 + ((~(((v439 ^ -1) | (-(v439 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v441 = v440[v643];
      bool v644 = !(v441 == 0);
      if (v644) {
        int * v442 = v397->cache_tags;
        int v443 = v442[v643];
        int * v444 = v397->cache_vals;
        int v647 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 3) * 2)) + ((((v435 + ((~(((v437 ^ -1) | (-(v437 ^ -1))) >> 31)) & 2)) - (v438 + ((~(((v439 ^ -1) | (-(v439 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v445 = v444[v647];
        int v648 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 3) * 2)) + ((((v435 + ((~(((v437 ^ -1) | (-(v437 ^ -1))) >> 31)) & 2)) - (v438 + ((~(((v439 ^ -1) | (-(v439 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v446 = v444[v648];
        int * v447 = v397->mem;
        int v650 = v443 * 2;
        v447[v650] = v445;
        int * v449 = v397->mem;
        int v653 = (v443 * 2) + 1;
        v449[v653] = v446;
        ;
      } else {
        ;
      }
      int * v454 = v397->mem;
      int v658 = ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) * 2;
      int v455 = v454[v658];
      int v659 = (((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) * 2) + 1;
      int v456 = v454[v659];
      int * v457 = v397->cache_vals;
      int v661 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 3) * 2)) + ((((v435 + ((~(((v437 ^ -1) | (-(v437 ^ -1))) >> 31)) & 2)) - (v438 + ((~(((v439 ^ -1) | (-(v439 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v457[v661] = v455;
      int * v459 = v397->cache_vals;
      int v664 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 3) * 2)) + ((((v435 + ((~(((v437 ^ -1) | (-(v437 ^ -1))) >> 31)) & 2)) - (v438 + ((~(((v439 ^ -1) | (-(v439 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v459[v664] = v456;
      int * v461 = v397->cache_tags;
      int v667 = (int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1);
      v461[v643] = v667;
      int * v463 = v397->cache_dirty;
      v463[v643] = 0;
      int * v465 = v397->cache_age;
      v465[v643] = 1;
      int * v467 = v397->cache_age;
      int v468 = v467[v643];
      int v469 = v467[v617];
      int v673 = v469 + ((int)((unsigned int)(v469 - v468) >> 31));
      v467[v617] = v673;
      int * v471 = v397->cache_age;
      int v472 = v471[v618];
      int v675 = v472 + ((int)((unsigned int)(v472 - v468) >> 31));
      v471[v618] = v675;
      int * v474 = v397->cache_age;
      v474[v643] = 0;
      v477 = v643;
    }
    int * v478 = v397->cache_vals;
    int v678 = v477 * 2;
    int v479 = v478[v678];
    int v679 = (v477 * 2) + 1;
    int v480 = v478[v679];
    int v680 = (((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 1) * 2) + ((((v419 + ((~(((v421 ^ -1) | (-(v421 ^ -1))) >> 31)) & 2)) - (v422 + ((~(((v423 ^ -1) | (-(v423 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v478[v680] = v479;
    int * v482 = v397->cache_vals;
    int v683 = ((((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 1) * 2) + ((((v419 + ((~(((v421 ^ -1) | (-(v421 ^ -1))) >> 31)) & 2)) - (v422 + ((~(((v423 ^ -1) | (-(v423 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v482[v683] = v480;
    int * v484 = v397->cache_tags;
    int v686 = ((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 1) * 2) + ((((v419 + ((~(((v421 ^ -1) | (-(v421 ^ -1))) >> 31)) & 2)) - (v422 + ((~(((v423 ^ -1) | (-(v423 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v687 = (int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1);
    v484[v686] = v687;
    int * v486 = v397->cache_dirty;
    v486[v686] = 0;
    int * v488 = v397->cache_age;
    v488[v686] = 1;
    int * v490 = v397->cache_age;
    int v491 = v490[v686];
    int v492 = v490[v615];
    int v693 = v492 + ((int)((unsigned int)(v492 - v491) >> 31));
    v490[v615] = v693;
    int * v494 = v397->cache_age;
    int v495 = v494[v616];
    int v695 = v495 + ((int)((unsigned int)(v495 - v491) >> 31));
    v494[v616] = v695;
    int * v497 = v397->cache_age;
    v497[v686] = 0;
    v500 = v686;
  }
  int v698 = (v500 * 2) + (((int)((unsigned int)v399 >> 2)) & 1);
  int v501 = v407[v698];
  int * v502 = v397->regs;
  v502[7] = v501;
  struct StateT2 * v504 = slot_20(v267);
  return v504;
}

struct StateT2 * slot_21(struct StateT2 * v2160) {
  struct StateT * v2161 = v2160->a;
  int v2162 = v2161->timer;
  struct StateT * v2163 = v2160->b;
  int v2164 = v2163->timer;
  bool v2401 = v2162 == v2164;
  squared_assert(v2401);
  squared_assume(v2401);
  struct StateT * v2167 = v2160->a;
  int * v2168 = v2167->saved_regs;
  int * v2169 = v2167->regs;
  int v2170 = v2169[9];
  v2168[9] = v2170;
  struct StateT * v2172 = v2160->b;
  int * v2173 = v2172->saved_regs;
  int * v2174 = v2172->regs;
  int v2175 = v2174[9];
  v2173[9] = v2175;
  struct StateT * v2177 = v2160->a;
  int v2178 = v2177->timer;
  int v2412 = v2178 + 1;
  v2177->timer = v2412;
  struct StateT * v2180 = v2160->b;
  int v2181 = v2180->timer;
  int v2414 = v2181 + 1;
  v2180->timer = v2414;
  struct StateT * v2183 = v2160->a;
  int * v2184 = v2183->regs;
  int v2185 = v2184[8];
  int * v2186 = v2183->cache_tags;
  int v2419 = (((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1)) & 1) * 2;
  int v2187 = v2186[v2419];
  int v2420 = ((((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1)) & 1) * 2) + 1;
  int v2188 = v2186[v2420];
  int v2421 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1)) & 3) * 2);
  int v2189 = v2186[v2421];
  int v2422 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2190 = v2186[v2422];
  int v2191 = v2183->timer;
  int v2423 = v2191 + ((100 ^ (((~(((v2189 ^ ((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1))) | (-(v2189 ^ ((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1))))) >> 31)) | (~(((v2190 ^ ((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1))) | (-(v2190 ^ ((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2187 ^ ((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1))) | (-(v2187 ^ ((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1))))) >> 31)) | (~(((v2188 ^ ((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1))) | (-(v2188 ^ ((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2189 ^ ((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1))) | (-(v2189 ^ ((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1))))) >> 31)) | (~(((v2190 ^ ((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1))) | (-(v2190 ^ ((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2183->timer = v2423;
  int * v2193 = v2183->cache_vals;
  bool v2424 = !(((~(((v2187 ^ ((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1))) | (-(v2187 ^ ((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1))))) >> 31)) | (~(((v2188 ^ ((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1))) | (-(v2188 ^ ((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1))))) >> 31))) == 0);
  int v2286;
  if (v2424) {
    int * v2194 = v2183->cache_age;
    int v2426 = ((((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1)) & 1) * 2) + ((~(((v2188 ^ ((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1))) | (-(v2188 ^ ((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1))))) >> 31)) & 1);
    int v2195 = v2194[v2426];
    int v2196 = v2194[v2419];
    int v2427 = v2196 + ((int)((unsigned int)(v2196 - v2195) >> 31));
    v2194[v2419] = v2427;
    int * v2198 = v2183->cache_age;
    int v2199 = v2198[v2420];
    int v2429 = v2199 + ((int)((unsigned int)(v2199 - v2195) >> 31));
    v2198[v2420] = v2429;
    int * v2201 = v2183->cache_age;
    v2201[v2426] = 0;
    v2286 = v2426;
  } else {
    int * v2204 = v2183->cache_age;
    int v2433 = (((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1)) & 1) * 2;
    int v2205 = v2204[v2433];
    int * v2206 = v2183->cache_tags;
    int v2207 = v2206[v2433];
    int v2208 = v2204[v2420];
    int v2209 = v2206[v2420];
    bool v2435 = !(((~(((v2189 ^ ((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1))) | (-(v2189 ^ ((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1))))) >> 31)) | (~(((v2190 ^ ((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1))) | (-(v2190 ^ ((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1))))) >> 31))) == 0);
    int v2263;
    if (v2435) {
      int * v2210 = v2183->cache_age;
      int v2437 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2190 ^ ((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1))) | (-(v2190 ^ ((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1))))) >> 31)) & 1);
      int v2211 = v2210[v2437];
      int v2212 = v2210[v2421];
      int v2438 = v2212 + ((int)((unsigned int)(v2212 - v2211) >> 31));
      v2210[v2421] = v2438;
      int * v2214 = v2183->cache_age;
      int v2215 = v2214[v2422];
      int v2440 = v2215 + ((int)((unsigned int)(v2215 - v2211) >> 31));
      v2214[v2422] = v2440;
      int * v2217 = v2183->cache_age;
      v2217[v2437] = 0;
      v2263 = v2437;
    } else {
      int * v2220 = v2183->cache_age;
      int v2444 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1)) & 3) * 2);
      int v2221 = v2220[v2444];
      int * v2222 = v2183->cache_tags;
      int v2223 = v2222[v2444];
      int v2224 = v2220[v2422];
      int v2225 = v2222[v2422];
      int * v2226 = v2183->cache_dirty;
      int v2447 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1)) & 3) * 2)) + ((((v2221 + ((~(((v2223 ^ -1) | (-(v2223 ^ -1))) >> 31)) & 2)) - (v2224 + ((~(((v2225 ^ -1) | (-(v2225 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2227 = v2226[v2447];
      bool v2448 = !(v2227 == 0);
      if (v2448) {
        int * v2228 = v2183->cache_tags;
        int v2229 = v2228[v2447];
        int * v2230 = v2183->cache_vals;
        int v2451 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1)) & 3) * 2)) + ((((v2221 + ((~(((v2223 ^ -1) | (-(v2223 ^ -1))) >> 31)) & 2)) - (v2224 + ((~(((v2225 ^ -1) | (-(v2225 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2231 = v2230[v2451];
        int v2452 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1)) & 3) * 2)) + ((((v2221 + ((~(((v2223 ^ -1) | (-(v2223 ^ -1))) >> 31)) & 2)) - (v2224 + ((~(((v2225 ^ -1) | (-(v2225 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2232 = v2230[v2452];
        int * v2233 = v2183->mem;
        int v2454 = v2229 * 2;
        v2233[v2454] = v2231;
        int * v2235 = v2183->mem;
        int v2457 = (v2229 * 2) + 1;
        v2235[v2457] = v2232;
        ;
      } else {
        ;
      }
      int * v2240 = v2183->mem;
      int v2462 = ((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1)) * 2;
      int v2241 = v2240[v2462];
      int v2463 = (((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1)) * 2) + 1;
      int v2242 = v2240[v2463];
      int * v2243 = v2183->cache_vals;
      int v2465 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1)) & 3) * 2)) + ((((v2221 + ((~(((v2223 ^ -1) | (-(v2223 ^ -1))) >> 31)) & 2)) - (v2224 + ((~(((v2225 ^ -1) | (-(v2225 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2243[v2465] = v2241;
      int * v2245 = v2183->cache_vals;
      int v2468 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1)) & 3) * 2)) + ((((v2221 + ((~(((v2223 ^ -1) | (-(v2223 ^ -1))) >> 31)) & 2)) - (v2224 + ((~(((v2225 ^ -1) | (-(v2225 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2245[v2468] = v2242;
      int * v2247 = v2183->cache_tags;
      int v2471 = (int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1);
      v2247[v2447] = v2471;
      int * v2249 = v2183->cache_dirty;
      v2249[v2447] = 0;
      int * v2251 = v2183->cache_age;
      v2251[v2447] = 1;
      int * v2253 = v2183->cache_age;
      int v2254 = v2253[v2447];
      int v2255 = v2253[v2421];
      int v2477 = v2255 + ((int)((unsigned int)(v2255 - v2254) >> 31));
      v2253[v2421] = v2477;
      int * v2257 = v2183->cache_age;
      int v2258 = v2257[v2422];
      int v2479 = v2258 + ((int)((unsigned int)(v2258 - v2254) >> 31));
      v2257[v2422] = v2479;
      int * v2260 = v2183->cache_age;
      v2260[v2447] = 0;
      v2263 = v2447;
    }
    int * v2264 = v2183->cache_vals;
    int v2482 = v2263 * 2;
    int v2265 = v2264[v2482];
    int v2483 = (v2263 * 2) + 1;
    int v2266 = v2264[v2483];
    int v2484 = (((((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1)) & 1) * 2) + ((((v2205 + ((~(((v2207 ^ -1) | (-(v2207 ^ -1))) >> 31)) & 2)) - (v2208 + ((~(((v2209 ^ -1) | (-(v2209 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2264[v2484] = v2265;
    int * v2268 = v2183->cache_vals;
    int v2487 = ((((((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1)) & 1) * 2) + ((((v2205 + ((~(((v2207 ^ -1) | (-(v2207 ^ -1))) >> 31)) & 2)) - (v2208 + ((~(((v2209 ^ -1) | (-(v2209 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2268[v2487] = v2266;
    int * v2270 = v2183->cache_tags;
    int v2490 = ((((int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1)) & 1) * 2) + ((((v2205 + ((~(((v2207 ^ -1) | (-(v2207 ^ -1))) >> 31)) & 2)) - (v2208 + ((~(((v2209 ^ -1) | (-(v2209 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2491 = (int)((unsigned int)((int)((unsigned int)v2185 >> 2)) >> 1);
    v2270[v2490] = v2491;
    int * v2272 = v2183->cache_dirty;
    v2272[v2490] = 0;
    int * v2274 = v2183->cache_age;
    v2274[v2490] = 1;
    int * v2276 = v2183->cache_age;
    int v2277 = v2276[v2490];
    int v2278 = v2276[v2419];
    int v2497 = v2278 + ((int)((unsigned int)(v2278 - v2277) >> 31));
    v2276[v2419] = v2497;
    int * v2280 = v2183->cache_age;
    int v2281 = v2280[v2420];
    int v2499 = v2281 + ((int)((unsigned int)(v2281 - v2277) >> 31));
    v2280[v2420] = v2499;
    int * v2283 = v2183->cache_age;
    v2283[v2490] = 0;
    v2286 = v2490;
  }
  int v2502 = (v2286 * 2) + (((int)((unsigned int)v2185 >> 2)) & 1);
  int v2287 = v2193[v2502];
  int * v2288 = v2183->regs;
  v2288[9] = v2287;
  struct StateT * v2290 = v2160->b;
  int * v2291 = v2290->regs;
  int v2292 = v2291[8];
  int * v2293 = v2290->cache_tags;
  int v2508 = (((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1)) & 1) * 2;
  int v2294 = v2293[v2508];
  int v2509 = ((((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1)) & 1) * 2) + 1;
  int v2295 = v2293[v2509];
  int v2510 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1)) & 3) * 2);
  int v2296 = v2293[v2510];
  int v2511 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2297 = v2293[v2511];
  int v2298 = v2290->timer;
  int v2512 = v2298 + ((100 ^ (((~(((v2296 ^ ((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1))) | (-(v2296 ^ ((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1))))) >> 31)) | (~(((v2297 ^ ((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1))) | (-(v2297 ^ ((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2294 ^ ((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1))) | (-(v2294 ^ ((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1))))) >> 31)) | (~(((v2295 ^ ((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1))) | (-(v2295 ^ ((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2296 ^ ((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1))) | (-(v2296 ^ ((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1))))) >> 31)) | (~(((v2297 ^ ((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1))) | (-(v2297 ^ ((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2290->timer = v2512;
  int * v2300 = v2290->cache_vals;
  bool v2513 = !(((~(((v2294 ^ ((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1))) | (-(v2294 ^ ((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1))))) >> 31)) | (~(((v2295 ^ ((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1))) | (-(v2295 ^ ((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1))))) >> 31))) == 0);
  int v2393;
  if (v2513) {
    int * v2301 = v2290->cache_age;
    int v2515 = ((((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1)) & 1) * 2) + ((~(((v2295 ^ ((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1))) | (-(v2295 ^ ((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1))))) >> 31)) & 1);
    int v2302 = v2301[v2515];
    int v2303 = v2301[v2508];
    int v2516 = v2303 + ((int)((unsigned int)(v2303 - v2302) >> 31));
    v2301[v2508] = v2516;
    int * v2305 = v2290->cache_age;
    int v2306 = v2305[v2509];
    int v2518 = v2306 + ((int)((unsigned int)(v2306 - v2302) >> 31));
    v2305[v2509] = v2518;
    int * v2308 = v2290->cache_age;
    v2308[v2515] = 0;
    v2393 = v2515;
  } else {
    int * v2311 = v2290->cache_age;
    int v2522 = (((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1)) & 1) * 2;
    int v2312 = v2311[v2522];
    int * v2313 = v2290->cache_tags;
    int v2314 = v2313[v2522];
    int v2315 = v2311[v2509];
    int v2316 = v2313[v2509];
    bool v2524 = !(((~(((v2296 ^ ((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1))) | (-(v2296 ^ ((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1))))) >> 31)) | (~(((v2297 ^ ((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1))) | (-(v2297 ^ ((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1))))) >> 31))) == 0);
    int v2370;
    if (v2524) {
      int * v2317 = v2290->cache_age;
      int v2526 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2297 ^ ((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1))) | (-(v2297 ^ ((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1))))) >> 31)) & 1);
      int v2318 = v2317[v2526];
      int v2319 = v2317[v2510];
      int v2527 = v2319 + ((int)((unsigned int)(v2319 - v2318) >> 31));
      v2317[v2510] = v2527;
      int * v2321 = v2290->cache_age;
      int v2322 = v2321[v2511];
      int v2529 = v2322 + ((int)((unsigned int)(v2322 - v2318) >> 31));
      v2321[v2511] = v2529;
      int * v2324 = v2290->cache_age;
      v2324[v2526] = 0;
      v2370 = v2526;
    } else {
      int * v2327 = v2290->cache_age;
      int v2533 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1)) & 3) * 2);
      int v2328 = v2327[v2533];
      int * v2329 = v2290->cache_tags;
      int v2330 = v2329[v2533];
      int v2331 = v2327[v2511];
      int v2332 = v2329[v2511];
      int * v2333 = v2290->cache_dirty;
      int v2536 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1)) & 3) * 2)) + ((((v2328 + ((~(((v2330 ^ -1) | (-(v2330 ^ -1))) >> 31)) & 2)) - (v2331 + ((~(((v2332 ^ -1) | (-(v2332 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2334 = v2333[v2536];
      bool v2537 = !(v2334 == 0);
      if (v2537) {
        int * v2335 = v2290->cache_tags;
        int v2336 = v2335[v2536];
        int * v2337 = v2290->cache_vals;
        int v2540 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1)) & 3) * 2)) + ((((v2328 + ((~(((v2330 ^ -1) | (-(v2330 ^ -1))) >> 31)) & 2)) - (v2331 + ((~(((v2332 ^ -1) | (-(v2332 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2338 = v2337[v2540];
        int v2541 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1)) & 3) * 2)) + ((((v2328 + ((~(((v2330 ^ -1) | (-(v2330 ^ -1))) >> 31)) & 2)) - (v2331 + ((~(((v2332 ^ -1) | (-(v2332 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2339 = v2337[v2541];
        int * v2340 = v2290->mem;
        int v2543 = v2336 * 2;
        v2340[v2543] = v2338;
        int * v2342 = v2290->mem;
        int v2546 = (v2336 * 2) + 1;
        v2342[v2546] = v2339;
        ;
      } else {
        ;
      }
      int * v2347 = v2290->mem;
      int v2551 = ((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1)) * 2;
      int v2348 = v2347[v2551];
      int v2552 = (((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1)) * 2) + 1;
      int v2349 = v2347[v2552];
      int * v2350 = v2290->cache_vals;
      int v2554 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1)) & 3) * 2)) + ((((v2328 + ((~(((v2330 ^ -1) | (-(v2330 ^ -1))) >> 31)) & 2)) - (v2331 + ((~(((v2332 ^ -1) | (-(v2332 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2350[v2554] = v2348;
      int * v2352 = v2290->cache_vals;
      int v2557 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1)) & 3) * 2)) + ((((v2328 + ((~(((v2330 ^ -1) | (-(v2330 ^ -1))) >> 31)) & 2)) - (v2331 + ((~(((v2332 ^ -1) | (-(v2332 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2352[v2557] = v2349;
      int * v2354 = v2290->cache_tags;
      int v2560 = (int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1);
      v2354[v2536] = v2560;
      int * v2356 = v2290->cache_dirty;
      v2356[v2536] = 0;
      int * v2358 = v2290->cache_age;
      v2358[v2536] = 1;
      int * v2360 = v2290->cache_age;
      int v2361 = v2360[v2536];
      int v2362 = v2360[v2510];
      int v2566 = v2362 + ((int)((unsigned int)(v2362 - v2361) >> 31));
      v2360[v2510] = v2566;
      int * v2364 = v2290->cache_age;
      int v2365 = v2364[v2511];
      int v2568 = v2365 + ((int)((unsigned int)(v2365 - v2361) >> 31));
      v2364[v2511] = v2568;
      int * v2367 = v2290->cache_age;
      v2367[v2536] = 0;
      v2370 = v2536;
    }
    int * v2371 = v2290->cache_vals;
    int v2571 = v2370 * 2;
    int v2372 = v2371[v2571];
    int v2572 = (v2370 * 2) + 1;
    int v2373 = v2371[v2572];
    int v2573 = (((((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1)) & 1) * 2) + ((((v2312 + ((~(((v2314 ^ -1) | (-(v2314 ^ -1))) >> 31)) & 2)) - (v2315 + ((~(((v2316 ^ -1) | (-(v2316 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2371[v2573] = v2372;
    int * v2375 = v2290->cache_vals;
    int v2576 = ((((((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1)) & 1) * 2) + ((((v2312 + ((~(((v2314 ^ -1) | (-(v2314 ^ -1))) >> 31)) & 2)) - (v2315 + ((~(((v2316 ^ -1) | (-(v2316 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2375[v2576] = v2373;
    int * v2377 = v2290->cache_tags;
    int v2579 = ((((int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1)) & 1) * 2) + ((((v2312 + ((~(((v2314 ^ -1) | (-(v2314 ^ -1))) >> 31)) & 2)) - (v2315 + ((~(((v2316 ^ -1) | (-(v2316 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2580 = (int)((unsigned int)((int)((unsigned int)v2292 >> 2)) >> 1);
    v2377[v2579] = v2580;
    int * v2379 = v2290->cache_dirty;
    v2379[v2579] = 0;
    int * v2381 = v2290->cache_age;
    v2381[v2579] = 1;
    int * v2383 = v2290->cache_age;
    int v2384 = v2383[v2579];
    int v2385 = v2383[v2508];
    int v2586 = v2385 + ((int)((unsigned int)(v2385 - v2384) >> 31));
    v2383[v2508] = v2586;
    int * v2387 = v2290->cache_age;
    int v2388 = v2387[v2509];
    int v2588 = v2388 + ((int)((unsigned int)(v2388 - v2384) >> 31));
    v2387[v2509] = v2588;
    int * v2390 = v2290->cache_age;
    v2390[v2579] = 0;
    v2393 = v2579;
  }
  int v2591 = (v2393 * 2) + (((int)((unsigned int)v2292 >> 2)) & 1);
  int v2394 = v2300[v2591];
  int * v2395 = v2290->regs;
  v2395[9] = v2394;
  struct StateT2 * v2397 = slot_10(v2160);
  return v2397;
}

struct StateT2 * slot_3(struct StateT2 * v110) {
  struct StateT * v111 = v110->a;
  int v112 = v111->timer;
  struct StateT * v113 = v110->b;
  int v114 = v113->timer;
  bool v133 = v112 == v114;
  squared_assert(v133);
  squared_assume(v133);
  struct StateT * v117 = v110->a;
  int v118 = v117->timer;
  int v135 = v118 + 1;
  v117->timer = v135;
  struct StateT * v120 = v110->b;
  int v121 = v120->timer;
  int v137 = v121 + 1;
  v120->timer = v137;
  struct StateT * v123 = v110->a;
  int * v124 = v123->regs;
  v124[15] = 16;
  struct StateT * v126 = v110->b;
  int * v127 = v126->regs;
  v127[15] = 16;
  struct StateT2 * v129 = slot_4(v110);
  return v129;
}

struct StateT2 * slot_10(struct StateT2 * v1200) {
  struct StateT * v1201 = v1200->a;
  int v1202 = v1201->timer;
  struct StateT * v1203 = v1200->b;
  int v1204 = v1203->timer;
  bool v1237 = v1202 == v1204;
  squared_assert(v1237);
  squared_assume(v1237);
  struct StateT * v1207 = v1200->a;
  int * v1208 = v1207->saved_regs;
  int * v1209 = v1207->regs;
  int v1210 = v1209[16];
  v1208[16] = v1210;
  struct StateT * v1212 = v1200->b;
  int * v1213 = v1212->saved_regs;
  int * v1214 = v1212->regs;
  int v1215 = v1214[16];
  v1213[16] = v1215;
  struct StateT * v1217 = v1200->a;
  int v1218 = v1217->timer;
  int v1248 = v1218 + 1;
  v1217->timer = v1248;
  struct StateT * v1220 = v1200->b;
  int v1221 = v1220->timer;
  int v1250 = v1221 + 1;
  v1220->timer = v1250;
  struct StateT * v1223 = v1200->a;
  int * v1224 = v1223->regs;
  int v1225 = v1224[7];
  int v1226 = v1224[9];
  int v1255 = v1225 ^ v1226;
  v1224[16] = v1255;
  struct StateT * v1228 = v1200->b;
  int * v1229 = v1228->regs;
  int v1230 = v1229[7];
  int v1231 = v1229[9];
  int v1258 = v1230 ^ v1231;
  v1229[16] = v1258;
  struct StateT2 * v1233 = slot_23(v1200);
  return v1233;
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
  v52[13] = 80;
  struct StateT * v54 = v38->b;
  int * v55 = v54->regs;
  v55[13] = 80;
  struct StateT2 * v57 = slot_2(v38);
  return v57;
}

struct StateT2 * slot_13(struct StateT2 * v1460) {
  struct StateT * v1461 = v1460->a;
  int v1462 = v1461->timer;
  struct StateT * v1463 = v1460->b;
  int v1464 = v1463->timer;
  bool v1492 = v1462 == v1464;
  squared_assert(v1492);
  squared_assume(v1492);
  struct StateT * v1467 = v1460->a;
  int v1468 = v1467->timer;
  int v1494 = v1468 + 1;
  v1467->timer = v1494;
  struct StateT * v1470 = v1460->b;
  int v1471 = v1470->timer;
  int v1496 = v1471 + 1;
  v1470->timer = v1496;
  struct StateT * v1473 = v1460->a;
  int * v1474 = v1473->regs;
  int v1475 = v1474[5];
  bool v1500 = (v1475 ^ -2147483648) < -2147483647;
  int v1478;
  if (v1500) {
    v1478 = 1;
  } else {
    v1478 = 0;
  }
  int * v1479 = v1473->regs;
  v1479[11] = v1478;
  struct StateT * v1481 = v1460->b;
  int * v1482 = v1481->regs;
  int v1483 = v1482[5];
  bool v1508 = (v1483 ^ -2147483648) < -2147483647;
  int v1486;
  if (v1508) {
    v1486 = 1;
  } else {
    v1486 = 0;
  }
  int * v1487 = v1481->regs;
  v1487[11] = v1486;
  return v1460;
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
  v16[12] = 0;
  struct StateT * v18 = v2->b;
  int * v19 = v18->regs;
  v19[12] = 0;
  struct StateT2 * v21 = slot_1(v2);
  return v21;
}

struct StateT2 * slot_14(struct StateT2 * v1513) {
  struct StateT * v1514 = v1513->a;
  int v1515 = v1514->timer;
  struct StateT * v1516 = v1513->b;
  int v1517 = v1516->timer;
  bool v1538 = v1515 == v1517;
  squared_assert(v1538);
  squared_assume(v1538);
  struct StateT * v1520 = v1513->a;
  int v1521 = v1520->timer;
  int v1540 = v1521 + 1;
  v1520->timer = v1540;
  struct StateT * v1523 = v1513->b;
  int v1524 = v1523->timer;
  int v1542 = v1524 + 1;
  v1523->timer = v1542;
  struct StateT * v1526 = v1513->a;
  int * v1527 = v1526->regs;
  int v1528 = v1527[14];
  int v1546 = v1528 + 4;
  v1527[14] = v1546;
  struct StateT * v1530 = v1513->b;
  int * v1531 = v1530->regs;
  int v1532 = v1531[14];
  int v1549 = v1532 + 4;
  v1531[14] = v1549;
  struct StateT2 * v1534 = slot_16(v1513);
  return v1534;
}

struct StateT2 * slot_20(struct StateT2 * v2099) {
  struct StateT * v2100 = v2099->a;
  int v2101 = v2100->timer;
  struct StateT * v2102 = v2099->b;
  int v2103 = v2102->timer;
  bool v2136 = v2101 == v2103;
  squared_assert(v2136);
  squared_assume(v2136);
  struct StateT * v2106 = v2099->a;
  int * v2107 = v2106->saved_regs;
  int * v2108 = v2106->regs;
  int v2109 = v2108[8];
  v2107[8] = v2109;
  struct StateT * v2111 = v2099->b;
  int * v2112 = v2111->saved_regs;
  int * v2113 = v2111->regs;
  int v2114 = v2113[8];
  v2112[8] = v2114;
  struct StateT * v2116 = v2099->a;
  int v2117 = v2116->timer;
  int v2147 = v2117 + 1;
  v2116->timer = v2147;
  struct StateT * v2119 = v2099->b;
  int v2120 = v2119->timer;
  int v2149 = v2120 + 1;
  v2119->timer = v2149;
  struct StateT * v2122 = v2099->a;
  int * v2123 = v2122->regs;
  int v2124 = v2123[13];
  int v2125 = v2123[14];
  int v2154 = v2124 + v2125;
  v2123[8] = v2154;
  struct StateT * v2127 = v2099->b;
  int * v2128 = v2127->regs;
  int v2129 = v2128[13];
  int v2130 = v2128[14];
  int v2157 = v2129 + v2130;
  v2128[8] = v2157;
  struct StateT2 * v2132 = slot_21(v2099);
  return v2132;
}

struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  return v1;
}

struct StateT2 * slot_4(struct StateT2 * v146) {
  struct StateT * v147 = v146->a;
  int v148 = v147->timer;
  struct StateT * v149 = v146->b;
  int v150 = v149->timer;
  bool v169 = v148 == v150;
  squared_assert(v169);
  squared_assume(v169);
  struct StateT * v153 = v146->a;
  int v154 = v153->timer;
  int v171 = v154 + 1;
  v153->timer = v171;
  struct StateT * v156 = v146->b;
  int v157 = v156->timer;
  int v173 = v157 + 1;
  v156->timer = v173;
  struct StateT * v159 = v146->a;
  int * v160 = v159->regs;
  v160[5] = 0;
  struct StateT * v162 = v146->b;
  int * v163 = v162->regs;
  v163[5] = 0;
  struct StateT2 * v165 = slot_5(v146);
  return v165;
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
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}