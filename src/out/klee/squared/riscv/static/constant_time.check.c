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
struct StateT2 * slot_14(struct StateT2 * v1513);
struct StateT2 * slot_6(struct StateT2 * v206);
struct StateT2 * slot_16(struct StateT2 * v1552);
struct StateT2 * slot_5(struct StateT2 * v182);
struct StateT2 * slot_2(struct StateT2 * v74);
struct StateT2 * slot_7(struct StateT2 * v267);
struct StateT2 * slot_3(struct StateT2 * v110);
struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_10(struct StateT2 * v1200);
struct StateT2 * slot_1(struct StateT2 * v38);
struct StateT2 * slot_8(struct StateT2 * v703);
struct StateT2 * slot_4(struct StateT2 * v146);
struct StateT2 * slot_13(struct StateT2 * v1460);
struct StateT2 * slot_9(struct StateT2 * v764);
struct StateT2 * slot_11(struct StateT2 * v1261);
struct StateT2 * slot_0(struct StateT2 * v2);
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
  struct StateT2 * v504 = slot_8(v267);
  return v504;
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

struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  return v1;
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
  struct StateT2 * v1233 = slot_11(v1200);
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

struct StateT2 * slot_8(struct StateT2 * v703) {
  struct StateT * v704 = v703->a;
  int v705 = v704->timer;
  struct StateT * v706 = v703->b;
  int v707 = v706->timer;
  bool v740 = v705 == v707;
  squared_assert(v740);
  squared_assume(v740);
  struct StateT * v710 = v703->a;
  int * v711 = v710->saved_regs;
  int * v712 = v710->regs;
  int v713 = v712[8];
  v711[8] = v713;
  struct StateT * v715 = v703->b;
  int * v716 = v715->saved_regs;
  int * v717 = v715->regs;
  int v718 = v717[8];
  v716[8] = v718;
  struct StateT * v720 = v703->a;
  int v721 = v720->timer;
  int v751 = v721 + 1;
  v720->timer = v751;
  struct StateT * v723 = v703->b;
  int v724 = v723->timer;
  int v753 = v724 + 1;
  v723->timer = v753;
  struct StateT * v726 = v703->a;
  int * v727 = v726->regs;
  int v728 = v727[13];
  int v729 = v727[14];
  int v758 = v728 + v729;
  v727[8] = v758;
  struct StateT * v731 = v703->b;
  int * v732 = v731->regs;
  int v733 = v732[13];
  int v734 = v732[14];
  int v761 = v733 + v734;
  v732[8] = v761;
  struct StateT2 * v736 = slot_9(v703);
  return v736;
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

struct StateT2 * slot_9(struct StateT2 * v764) {
  struct StateT * v765 = v764->a;
  int v766 = v765->timer;
  struct StateT * v767 = v764->b;
  int v768 = v767->timer;
  bool v1005 = v766 == v768;
  squared_assert(v1005);
  squared_assume(v1005);
  struct StateT * v771 = v764->a;
  int * v772 = v771->saved_regs;
  int * v773 = v771->regs;
  int v774 = v773[9];
  v772[9] = v774;
  struct StateT * v776 = v764->b;
  int * v777 = v776->saved_regs;
  int * v778 = v776->regs;
  int v779 = v778[9];
  v777[9] = v779;
  struct StateT * v781 = v764->a;
  int v782 = v781->timer;
  int v1016 = v782 + 1;
  v781->timer = v1016;
  struct StateT * v784 = v764->b;
  int v785 = v784->timer;
  int v1018 = v785 + 1;
  v784->timer = v1018;
  struct StateT * v787 = v764->a;
  int * v788 = v787->regs;
  int v789 = v788[8];
  int * v790 = v787->cache_tags;
  int v1023 = (((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1)) & 1) * 2;
  int v791 = v790[v1023];
  int v1024 = ((((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1)) & 1) * 2) + 1;
  int v792 = v790[v1024];
  int v1025 = 4 + ((((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1)) & 3) * 2);
  int v793 = v790[v1025];
  int v1026 = (4 + ((((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v794 = v790[v1026];
  int v795 = v787->timer;
  int v1027 = v795 + ((100 ^ (((~(((v793 ^ ((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1))) | (-(v793 ^ ((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1))))) >> 31)) | (~(((v794 ^ ((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1))) | (-(v794 ^ ((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v791 ^ ((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1))) | (-(v791 ^ ((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1))))) >> 31)) | (~(((v792 ^ ((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1))) | (-(v792 ^ ((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v793 ^ ((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1))) | (-(v793 ^ ((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1))))) >> 31)) | (~(((v794 ^ ((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1))) | (-(v794 ^ ((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1))))) >> 31))) & 104)))));
  v787->timer = v1027;
  int * v797 = v787->cache_vals;
  bool v1028 = !(((~(((v791 ^ ((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1))) | (-(v791 ^ ((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1))))) >> 31)) | (~(((v792 ^ ((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1))) | (-(v792 ^ ((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1))))) >> 31))) == 0);
  int v890;
  if (v1028) {
    int * v798 = v787->cache_age;
    int v1030 = ((((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1)) & 1) * 2) + ((~(((v792 ^ ((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1))) | (-(v792 ^ ((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1))))) >> 31)) & 1);
    int v799 = v798[v1030];
    int v800 = v798[v1023];
    int v1031 = v800 + ((int)((unsigned int)(v800 - v799) >> 31));
    v798[v1023] = v1031;
    int * v802 = v787->cache_age;
    int v803 = v802[v1024];
    int v1033 = v803 + ((int)((unsigned int)(v803 - v799) >> 31));
    v802[v1024] = v1033;
    int * v805 = v787->cache_age;
    v805[v1030] = 0;
    v890 = v1030;
  } else {
    int * v808 = v787->cache_age;
    int v1037 = (((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1)) & 1) * 2;
    int v809 = v808[v1037];
    int * v810 = v787->cache_tags;
    int v811 = v810[v1037];
    int v812 = v808[v1024];
    int v813 = v810[v1024];
    bool v1039 = !(((~(((v793 ^ ((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1))) | (-(v793 ^ ((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1))))) >> 31)) | (~(((v794 ^ ((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1))) | (-(v794 ^ ((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1))))) >> 31))) == 0);
    int v867;
    if (v1039) {
      int * v814 = v787->cache_age;
      int v1041 = (4 + ((((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1)) & 3) * 2)) + ((~(((v794 ^ ((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1))) | (-(v794 ^ ((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1))))) >> 31)) & 1);
      int v815 = v814[v1041];
      int v816 = v814[v1025];
      int v1042 = v816 + ((int)((unsigned int)(v816 - v815) >> 31));
      v814[v1025] = v1042;
      int * v818 = v787->cache_age;
      int v819 = v818[v1026];
      int v1044 = v819 + ((int)((unsigned int)(v819 - v815) >> 31));
      v818[v1026] = v1044;
      int * v821 = v787->cache_age;
      v821[v1041] = 0;
      v867 = v1041;
    } else {
      int * v824 = v787->cache_age;
      int v1048 = 4 + ((((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1)) & 3) * 2);
      int v825 = v824[v1048];
      int * v826 = v787->cache_tags;
      int v827 = v826[v1048];
      int v828 = v824[v1026];
      int v829 = v826[v1026];
      int * v830 = v787->cache_dirty;
      int v1051 = (4 + ((((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1)) & 3) * 2)) + ((((v825 + ((~(((v827 ^ -1) | (-(v827 ^ -1))) >> 31)) & 2)) - (v828 + ((~(((v829 ^ -1) | (-(v829 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v831 = v830[v1051];
      bool v1052 = !(v831 == 0);
      if (v1052) {
        int * v832 = v787->cache_tags;
        int v833 = v832[v1051];
        int * v834 = v787->cache_vals;
        int v1055 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1)) & 3) * 2)) + ((((v825 + ((~(((v827 ^ -1) | (-(v827 ^ -1))) >> 31)) & 2)) - (v828 + ((~(((v829 ^ -1) | (-(v829 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v835 = v834[v1055];
        int v1056 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1)) & 3) * 2)) + ((((v825 + ((~(((v827 ^ -1) | (-(v827 ^ -1))) >> 31)) & 2)) - (v828 + ((~(((v829 ^ -1) | (-(v829 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v836 = v834[v1056];
        int * v837 = v787->mem;
        int v1058 = v833 * 2;
        v837[v1058] = v835;
        int * v839 = v787->mem;
        int v1061 = (v833 * 2) + 1;
        v839[v1061] = v836;
        ;
      } else {
        ;
      }
      int * v844 = v787->mem;
      int v1066 = ((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1)) * 2;
      int v845 = v844[v1066];
      int v1067 = (((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1)) * 2) + 1;
      int v846 = v844[v1067];
      int * v847 = v787->cache_vals;
      int v1069 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1)) & 3) * 2)) + ((((v825 + ((~(((v827 ^ -1) | (-(v827 ^ -1))) >> 31)) & 2)) - (v828 + ((~(((v829 ^ -1) | (-(v829 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v847[v1069] = v845;
      int * v849 = v787->cache_vals;
      int v1072 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1)) & 3) * 2)) + ((((v825 + ((~(((v827 ^ -1) | (-(v827 ^ -1))) >> 31)) & 2)) - (v828 + ((~(((v829 ^ -1) | (-(v829 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v849[v1072] = v846;
      int * v851 = v787->cache_tags;
      int v1075 = (int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1);
      v851[v1051] = v1075;
      int * v853 = v787->cache_dirty;
      v853[v1051] = 0;
      int * v855 = v787->cache_age;
      v855[v1051] = 1;
      int * v857 = v787->cache_age;
      int v858 = v857[v1051];
      int v859 = v857[v1025];
      int v1081 = v859 + ((int)((unsigned int)(v859 - v858) >> 31));
      v857[v1025] = v1081;
      int * v861 = v787->cache_age;
      int v862 = v861[v1026];
      int v1083 = v862 + ((int)((unsigned int)(v862 - v858) >> 31));
      v861[v1026] = v1083;
      int * v864 = v787->cache_age;
      v864[v1051] = 0;
      v867 = v1051;
    }
    int * v868 = v787->cache_vals;
    int v1086 = v867 * 2;
    int v869 = v868[v1086];
    int v1087 = (v867 * 2) + 1;
    int v870 = v868[v1087];
    int v1088 = (((((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1)) & 1) * 2) + ((((v809 + ((~(((v811 ^ -1) | (-(v811 ^ -1))) >> 31)) & 2)) - (v812 + ((~(((v813 ^ -1) | (-(v813 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v868[v1088] = v869;
    int * v872 = v787->cache_vals;
    int v1091 = ((((((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1)) & 1) * 2) + ((((v809 + ((~(((v811 ^ -1) | (-(v811 ^ -1))) >> 31)) & 2)) - (v812 + ((~(((v813 ^ -1) | (-(v813 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v872[v1091] = v870;
    int * v874 = v787->cache_tags;
    int v1094 = ((((int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1)) & 1) * 2) + ((((v809 + ((~(((v811 ^ -1) | (-(v811 ^ -1))) >> 31)) & 2)) - (v812 + ((~(((v813 ^ -1) | (-(v813 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1095 = (int)((unsigned int)((int)((unsigned int)v789 >> 2)) >> 1);
    v874[v1094] = v1095;
    int * v876 = v787->cache_dirty;
    v876[v1094] = 0;
    int * v878 = v787->cache_age;
    v878[v1094] = 1;
    int * v880 = v787->cache_age;
    int v881 = v880[v1094];
    int v882 = v880[v1023];
    int v1101 = v882 + ((int)((unsigned int)(v882 - v881) >> 31));
    v880[v1023] = v1101;
    int * v884 = v787->cache_age;
    int v885 = v884[v1024];
    int v1103 = v885 + ((int)((unsigned int)(v885 - v881) >> 31));
    v884[v1024] = v1103;
    int * v887 = v787->cache_age;
    v887[v1094] = 0;
    v890 = v1094;
  }
  int v1106 = (v890 * 2) + (((int)((unsigned int)v789 >> 2)) & 1);
  int v891 = v797[v1106];
  int * v892 = v787->regs;
  v892[9] = v891;
  struct StateT * v894 = v764->b;
  int * v895 = v894->regs;
  int v896 = v895[8];
  int * v897 = v894->cache_tags;
  int v1112 = (((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1)) & 1) * 2;
  int v898 = v897[v1112];
  int v1113 = ((((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1)) & 1) * 2) + 1;
  int v899 = v897[v1113];
  int v1114 = 4 + ((((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1)) & 3) * 2);
  int v900 = v897[v1114];
  int v1115 = (4 + ((((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v901 = v897[v1115];
  int v902 = v894->timer;
  int v1116 = v902 + ((100 ^ (((~(((v900 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))) | (-(v900 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))))) >> 31)) | (~(((v901 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))) | (-(v901 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v898 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))) | (-(v898 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))))) >> 31)) | (~(((v899 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))) | (-(v899 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v900 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))) | (-(v900 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))))) >> 31)) | (~(((v901 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))) | (-(v901 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))))) >> 31))) & 104)))));
  v894->timer = v1116;
  int * v904 = v894->cache_vals;
  bool v1117 = !(((~(((v898 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))) | (-(v898 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))))) >> 31)) | (~(((v899 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))) | (-(v899 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))))) >> 31))) == 0);
  int v997;
  if (v1117) {
    int * v905 = v894->cache_age;
    int v1119 = ((((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1)) & 1) * 2) + ((~(((v899 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))) | (-(v899 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))))) >> 31)) & 1);
    int v906 = v905[v1119];
    int v907 = v905[v1112];
    int v1120 = v907 + ((int)((unsigned int)(v907 - v906) >> 31));
    v905[v1112] = v1120;
    int * v909 = v894->cache_age;
    int v910 = v909[v1113];
    int v1122 = v910 + ((int)((unsigned int)(v910 - v906) >> 31));
    v909[v1113] = v1122;
    int * v912 = v894->cache_age;
    v912[v1119] = 0;
    v997 = v1119;
  } else {
    int * v915 = v894->cache_age;
    int v1126 = (((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1)) & 1) * 2;
    int v916 = v915[v1126];
    int * v917 = v894->cache_tags;
    int v918 = v917[v1126];
    int v919 = v915[v1113];
    int v920 = v917[v1113];
    bool v1128 = !(((~(((v900 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))) | (-(v900 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))))) >> 31)) | (~(((v901 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))) | (-(v901 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))))) >> 31))) == 0);
    int v974;
    if (v1128) {
      int * v921 = v894->cache_age;
      int v1130 = (4 + ((((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1)) & 3) * 2)) + ((~(((v901 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))) | (-(v901 ^ ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1))))) >> 31)) & 1);
      int v922 = v921[v1130];
      int v923 = v921[v1114];
      int v1131 = v923 + ((int)((unsigned int)(v923 - v922) >> 31));
      v921[v1114] = v1131;
      int * v925 = v894->cache_age;
      int v926 = v925[v1115];
      int v1133 = v926 + ((int)((unsigned int)(v926 - v922) >> 31));
      v925[v1115] = v1133;
      int * v928 = v894->cache_age;
      v928[v1130] = 0;
      v974 = v1130;
    } else {
      int * v931 = v894->cache_age;
      int v1137 = 4 + ((((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1)) & 3) * 2);
      int v932 = v931[v1137];
      int * v933 = v894->cache_tags;
      int v934 = v933[v1137];
      int v935 = v931[v1115];
      int v936 = v933[v1115];
      int * v937 = v894->cache_dirty;
      int v1140 = (4 + ((((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1)) & 3) * 2)) + ((((v932 + ((~(((v934 ^ -1) | (-(v934 ^ -1))) >> 31)) & 2)) - (v935 + ((~(((v936 ^ -1) | (-(v936 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v938 = v937[v1140];
      bool v1141 = !(v938 == 0);
      if (v1141) {
        int * v939 = v894->cache_tags;
        int v940 = v939[v1140];
        int * v941 = v894->cache_vals;
        int v1144 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1)) & 3) * 2)) + ((((v932 + ((~(((v934 ^ -1) | (-(v934 ^ -1))) >> 31)) & 2)) - (v935 + ((~(((v936 ^ -1) | (-(v936 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v942 = v941[v1144];
        int v1145 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1)) & 3) * 2)) + ((((v932 + ((~(((v934 ^ -1) | (-(v934 ^ -1))) >> 31)) & 2)) - (v935 + ((~(((v936 ^ -1) | (-(v936 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v943 = v941[v1145];
        int * v944 = v894->mem;
        int v1147 = v940 * 2;
        v944[v1147] = v942;
        int * v946 = v894->mem;
        int v1150 = (v940 * 2) + 1;
        v946[v1150] = v943;
        ;
      } else {
        ;
      }
      int * v951 = v894->mem;
      int v1155 = ((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1)) * 2;
      int v952 = v951[v1155];
      int v1156 = (((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1)) * 2) + 1;
      int v953 = v951[v1156];
      int * v954 = v894->cache_vals;
      int v1158 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1)) & 3) * 2)) + ((((v932 + ((~(((v934 ^ -1) | (-(v934 ^ -1))) >> 31)) & 2)) - (v935 + ((~(((v936 ^ -1) | (-(v936 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v954[v1158] = v952;
      int * v956 = v894->cache_vals;
      int v1161 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1)) & 3) * 2)) + ((((v932 + ((~(((v934 ^ -1) | (-(v934 ^ -1))) >> 31)) & 2)) - (v935 + ((~(((v936 ^ -1) | (-(v936 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v956[v1161] = v953;
      int * v958 = v894->cache_tags;
      int v1164 = (int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1);
      v958[v1140] = v1164;
      int * v960 = v894->cache_dirty;
      v960[v1140] = 0;
      int * v962 = v894->cache_age;
      v962[v1140] = 1;
      int * v964 = v894->cache_age;
      int v965 = v964[v1140];
      int v966 = v964[v1114];
      int v1170 = v966 + ((int)((unsigned int)(v966 - v965) >> 31));
      v964[v1114] = v1170;
      int * v968 = v894->cache_age;
      int v969 = v968[v1115];
      int v1172 = v969 + ((int)((unsigned int)(v969 - v965) >> 31));
      v968[v1115] = v1172;
      int * v971 = v894->cache_age;
      v971[v1140] = 0;
      v974 = v1140;
    }
    int * v975 = v894->cache_vals;
    int v1175 = v974 * 2;
    int v976 = v975[v1175];
    int v1176 = (v974 * 2) + 1;
    int v977 = v975[v1176];
    int v1177 = (((((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1)) & 1) * 2) + ((((v916 + ((~(((v918 ^ -1) | (-(v918 ^ -1))) >> 31)) & 2)) - (v919 + ((~(((v920 ^ -1) | (-(v920 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v975[v1177] = v976;
    int * v979 = v894->cache_vals;
    int v1180 = ((((((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1)) & 1) * 2) + ((((v916 + ((~(((v918 ^ -1) | (-(v918 ^ -1))) >> 31)) & 2)) - (v919 + ((~(((v920 ^ -1) | (-(v920 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v979[v1180] = v977;
    int * v981 = v894->cache_tags;
    int v1183 = ((((int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1)) & 1) * 2) + ((((v916 + ((~(((v918 ^ -1) | (-(v918 ^ -1))) >> 31)) & 2)) - (v919 + ((~(((v920 ^ -1) | (-(v920 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1184 = (int)((unsigned int)((int)((unsigned int)v896 >> 2)) >> 1);
    v981[v1183] = v1184;
    int * v983 = v894->cache_dirty;
    v983[v1183] = 0;
    int * v985 = v894->cache_age;
    v985[v1183] = 1;
    int * v987 = v894->cache_age;
    int v988 = v987[v1183];
    int v989 = v987[v1112];
    int v1190 = v989 + ((int)((unsigned int)(v989 - v988) >> 31));
    v987[v1112] = v1190;
    int * v991 = v894->cache_age;
    int v992 = v991[v1113];
    int v1192 = v992 + ((int)((unsigned int)(v992 - v988) >> 31));
    v991[v1113] = v1192;
    int * v994 = v894->cache_age;
    v994[v1183] = 0;
    v997 = v1183;
  }
  int v1195 = (v997 * 2) + (((int)((unsigned int)v896 >> 2)) & 1);
  int v998 = v904[v1195];
  int * v999 = v894->regs;
  v999[9] = v998;
  struct StateT2 * v1001 = slot_10(v764);
  return v1001;
}

struct StateT2 * slot_11(struct StateT2 * v1261) {
  struct StateT * v1262 = v1261->a;
  int v1263 = v1262->timer;
  struct StateT * v1264 = v1261->b;
  int v1265 = v1264->timer;
  bool v1298 = v1263 == v1265;
  squared_assert(v1298);
  squared_assume(v1298);
  struct StateT * v1268 = v1261->a;
  int * v1269 = v1268->saved_regs;
  int * v1270 = v1268->regs;
  int v1271 = v1270[5];
  v1269[5] = v1271;
  struct StateT * v1273 = v1261->b;
  int * v1274 = v1273->saved_regs;
  int * v1275 = v1273->regs;
  int v1276 = v1275[5];
  v1274[5] = v1276;
  struct StateT * v1278 = v1261->a;
  int v1279 = v1278->timer;
  int v1309 = v1279 + 1;
  v1278->timer = v1309;
  struct StateT * v1281 = v1261->b;
  int v1282 = v1281->timer;
  int v1311 = v1282 + 1;
  v1281->timer = v1311;
  struct StateT * v1284 = v1261->a;
  int * v1285 = v1284->regs;
  int v1286 = v1285[5];
  int v1287 = v1285[16];
  int v1315 = v1286 | v1287;
  v1285[5] = v1315;
  struct StateT * v1289 = v1261->b;
  int * v1290 = v1289->regs;
  int v1291 = v1290[5];
  int v1292 = v1290[16];
  int v1318 = v1291 | v1292;
  v1290[5] = v1318;
  struct StateT2 * v1294 = slot_12(v1261);
  return v1294;
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