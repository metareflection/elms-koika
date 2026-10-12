// verify: leak widened (the program is clean; Eva cannot prove it) [unroll 65]
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

struct StateT * slot_12(struct StateT * v759);
struct StateT * slot_34(struct StateT * v1815);
struct StateT * slot_6(struct StateT * v469);
struct StateT * slot_29(struct StateT * v1540);
struct StateT * slot_25(struct StateT * v1292);
struct StateT * slot_16(struct StateT * v827);
struct StateT * slot_23(struct StateT * v1262);
struct StateT * slot_5(struct StateT * v266);
struct StateT * slot_2(struct StateT * v218);
struct StateT * slot_7(struct StateT * v489);
struct StateT * slot_21(struct StateT * v1211);
struct StateT * slot_31(struct StateT * v1575);
struct StateT * slot_3(struct StateT * v226);
struct StateT * slot_26(struct StateT * v1495);
struct StateT * slot_10(struct StateT * v540);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_19(struct StateT * v888);
struct StateT * slot_13(struct StateT * v814);
struct StateT * slot_24(struct StateT * v1276);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v819);
struct StateT * slot_28(struct StateT * v1519);
struct StateT * slot_32(struct StateT * v1596);
struct StateT * slot_17(struct StateT * v848);
struct StateT * slot_20(struct StateT * v896);
struct StateT * slot_33(struct StateT * v1612);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v503);
struct StateT * slot_27(struct StateT * v1511);
struct StateT * slot_30(struct StateT * v1567);
struct StateT * slot_4(struct StateT * v246);
struct StateT * slot_18(struct StateT * v875);
struct StateT * slot_9(struct StateT * v524);
struct StateT * slot_22(struct StateT * v1231);
struct StateT * slot_11(struct StateT * v743);
struct StateT * slot_35(struct StateT * v1838);
struct StateT * slot_12(struct StateT * v759) {
  int * v760 = v759->saved_regs;
  int v761 = v760[10];
  int * v762 = v759->regs;
  int v763 = v762[11];
  bool v792 = (v761 ^ -2147483648) >= (v763 ^ -2147483648);
  struct StateT * v786;
  if (v792) {
    int v764 = v759->timer;
    int v793 = v764 + 15;
    v759->timer = v793;
    int * v766 = v759->saved_regs;
    int v767 = v766[13];
    int * v768 = v759->regs;
    v768[13] = v767;
    int * v770 = v759->saved_regs;
    int v771 = v770[12];
    int * v772 = v759->regs;
    v772[12] = v771;
    int * v774 = v759->saved_regs;
    int v775 = v774[14];
    int * v776 = v759->regs;
    v776[14] = v775;
    int * v778 = v759->saved_regs;
    int v779 = v778[10];
    int * v780 = v759->regs;
    v780[10] = v779;
    struct StateT * v782 = slot_13(v759);
    v786 = v782;
  } else {
    struct StateT * v784 = slot_14(v759);
    v786 = v784;
  }
  return v786;
}

struct StateT * slot_34(struct StateT * v1815) {
  int * v1816 = v1815->saved_regs;
  int * v1817 = v1815->regs;
  int v1818 = v1817[12];
  v1816[12] = v1818;
  int v1820 = v1815->timer;
  int v1832 = v1820 + 1;
  v1815->timer = v1832;
  int * v1822 = v1815->regs;
  int v1823 = v1822[12];
  int v1824 = v1822[10];
  int v1835 = v1823 & v1824;
  v1822[12] = v1835;
  struct StateT * v1826 = slot_35(v1815);
  return v1826;
}

struct StateT * slot_6(struct StateT * v469) {
  int * v470 = v469->saved_regs;
  int * v471 = v469->regs;
  int v472 = v471[14];
  v470[14] = v472;
  int v474 = v469->timer;
  int v484 = v474 + 1;
  v469->timer = v484;
  int * v476 = v469->regs;
  v476[14] = 0;
  struct StateT * v478 = slot_7(v469);
  return v478;
}

struct StateT * slot_29(struct StateT * v1540) {
  int * v1541 = v1540->saved_regs;
  int v1542 = v1541[13];
  bool v1557 = !(v1542 == 0);
  struct StateT * v1553;
  if (v1557) {
    int v1543 = v1540->timer;
    int v1558 = v1543 + 15;
    v1540->timer = v1558;
    int * v1545 = v1540->saved_regs;
    int v1546 = v1545[13];
    int * v1547 = v1540->regs;
    v1547[13] = v1546;
    struct StateT * v1549 = slot_18(v1540);
    v1553 = v1549;
  } else {
    struct StateT * v1551 = slot_30(v1540);
    v1553 = v1551;
  }
  return v1553;
}

struct StateT * slot_25(struct StateT * v1292) {
  int v1293 = v1292->timer;
  int v1403 = v1293 + 1;
  v1292->timer = v1403;
  int * v1295 = v1292->regs;
  int v1296 = v1295[10];
  int * v1297 = v1292->cache_tags;
  int v1407 = (((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1)) & 1) * 2;
  int v1298 = v1297[v1407];
  int v1408 = ((((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1299 = v1297[v1408];
  int v1409 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1)) & 3) * 2);
  int v1300 = v1297[v1409];
  int v1410 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1301 = v1297[v1410];
  int v1302 = v1292->timer;
  int v1411 = v1302 + ((100 ^ (((~(((v1300 ^ ((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1))) | (-(v1300 ^ ((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1))))) >> 31)) | (~(((v1301 ^ ((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1))) | (-(v1301 ^ ((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1298 ^ ((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1))) | (-(v1298 ^ ((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1))))) >> 31)) | (~(((v1299 ^ ((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1))) | (-(v1299 ^ ((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1300 ^ ((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1))) | (-(v1300 ^ ((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1))))) >> 31)) | (~(((v1301 ^ ((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1))) | (-(v1301 ^ ((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1292->timer = v1411;
  int * v1304 = v1292->cache_vals;
  bool v1412 = !(((~(((v1298 ^ ((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1))) | (-(v1298 ^ ((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1))))) >> 31)) | (~(((v1299 ^ ((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1))) | (-(v1299 ^ ((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1))))) >> 31))) == 0);
  int v1397;
  if (v1412) {
    int * v1305 = v1292->cache_age;
    int v1414 = ((((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1)) & 1) * 2) + ((~(((v1299 ^ ((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1))) | (-(v1299 ^ ((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1))))) >> 31)) & 1);
    int v1306 = v1305[v1414];
    int v1307 = v1305[v1407];
    int v1415 = v1307 + ((int)((unsigned int)(v1307 - v1306) >> 31));
    v1305[v1407] = v1415;
    int * v1309 = v1292->cache_age;
    int v1310 = v1309[v1408];
    int v1417 = v1310 + ((int)((unsigned int)(v1310 - v1306) >> 31));
    v1309[v1408] = v1417;
    int * v1312 = v1292->cache_age;
    v1312[v1414] = 0;
    v1397 = v1414;
  } else {
    int * v1315 = v1292->cache_age;
    int v1421 = (((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1)) & 1) * 2;
    int v1316 = v1315[v1421];
    int * v1317 = v1292->cache_tags;
    int v1318 = v1317[v1421];
    int v1319 = v1315[v1408];
    int v1320 = v1317[v1408];
    bool v1423 = !(((~(((v1300 ^ ((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1))) | (-(v1300 ^ ((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1))))) >> 31)) | (~(((v1301 ^ ((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1))) | (-(v1301 ^ ((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1))))) >> 31))) == 0);
    int v1374;
    if (v1423) {
      int * v1321 = v1292->cache_age;
      int v1425 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1301 ^ ((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1))) | (-(v1301 ^ ((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1))))) >> 31)) & 1);
      int v1322 = v1321[v1425];
      int v1323 = v1321[v1409];
      int v1426 = v1323 + ((int)((unsigned int)(v1323 - v1322) >> 31));
      v1321[v1409] = v1426;
      int * v1325 = v1292->cache_age;
      int v1326 = v1325[v1410];
      int v1428 = v1326 + ((int)((unsigned int)(v1326 - v1322) >> 31));
      v1325[v1410] = v1428;
      int * v1328 = v1292->cache_age;
      v1328[v1425] = 0;
      v1374 = v1425;
    } else {
      int * v1331 = v1292->cache_age;
      int v1432 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1)) & 3) * 2);
      int v1332 = v1331[v1432];
      int * v1333 = v1292->cache_tags;
      int v1334 = v1333[v1432];
      int v1335 = v1331[v1410];
      int v1336 = v1333[v1410];
      int * v1337 = v1292->cache_dirty;
      int v1435 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1)) & 3) * 2)) + ((((v1332 + ((~(((v1334 ^ -1) | (-(v1334 ^ -1))) >> 31)) & 2)) - (v1335 + ((~(((v1336 ^ -1) | (-(v1336 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1338 = v1337[v1435];
      bool v1436 = !(v1338 == 0);
      if (v1436) {
        int * v1339 = v1292->cache_tags;
        int v1340 = v1339[v1435];
        int * v1341 = v1292->cache_vals;
        int v1439 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1)) & 3) * 2)) + ((((v1332 + ((~(((v1334 ^ -1) | (-(v1334 ^ -1))) >> 31)) & 2)) - (v1335 + ((~(((v1336 ^ -1) | (-(v1336 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1342 = v1341[v1439];
        int v1440 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1)) & 3) * 2)) + ((((v1332 + ((~(((v1334 ^ -1) | (-(v1334 ^ -1))) >> 31)) & 2)) - (v1335 + ((~(((v1336 ^ -1) | (-(v1336 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1343 = v1341[v1440];
        int * v1344 = v1292->mem;
        int v1442 = v1340 * 2;
        v1344[v1442] = v1342;
        int * v1346 = v1292->mem;
        int v1445 = (v1340 * 2) + 1;
        v1346[v1445] = v1343;
        ;
      } else {
        ;
      }
      int * v1351 = v1292->mem;
      int v1450 = ((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1)) * 2;
      int v1352 = v1351[v1450];
      int v1451 = (((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1)) * 2) + 1;
      int v1353 = v1351[v1451];
      int * v1354 = v1292->cache_vals;
      int v1453 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1)) & 3) * 2)) + ((((v1332 + ((~(((v1334 ^ -1) | (-(v1334 ^ -1))) >> 31)) & 2)) - (v1335 + ((~(((v1336 ^ -1) | (-(v1336 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1354[v1453] = v1352;
      int * v1356 = v1292->cache_vals;
      int v1456 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1)) & 3) * 2)) + ((((v1332 + ((~(((v1334 ^ -1) | (-(v1334 ^ -1))) >> 31)) & 2)) - (v1335 + ((~(((v1336 ^ -1) | (-(v1336 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1356[v1456] = v1353;
      int * v1358 = v1292->cache_tags;
      int v1459 = (int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1);
      v1358[v1435] = v1459;
      int * v1360 = v1292->cache_dirty;
      v1360[v1435] = 0;
      int * v1362 = v1292->cache_age;
      v1362[v1435] = 1;
      int * v1364 = v1292->cache_age;
      int v1365 = v1364[v1435];
      int v1366 = v1364[v1409];
      int v1465 = v1366 + ((int)((unsigned int)(v1366 - v1365) >> 31));
      v1364[v1409] = v1465;
      int * v1368 = v1292->cache_age;
      int v1369 = v1368[v1410];
      int v1467 = v1369 + ((int)((unsigned int)(v1369 - v1365) >> 31));
      v1368[v1410] = v1467;
      int * v1371 = v1292->cache_age;
      v1371[v1435] = 0;
      v1374 = v1435;
    }
    int * v1375 = v1292->cache_vals;
    int v1470 = v1374 * 2;
    int v1376 = v1375[v1470];
    int v1471 = (v1374 * 2) + 1;
    int v1377 = v1375[v1471];
    int v1472 = (((((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1)) & 1) * 2) + ((((v1316 + ((~(((v1318 ^ -1) | (-(v1318 ^ -1))) >> 31)) & 2)) - (v1319 + ((~(((v1320 ^ -1) | (-(v1320 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1375[v1472] = v1376;
    int * v1379 = v1292->cache_vals;
    int v1475 = ((((((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1)) & 1) * 2) + ((((v1316 + ((~(((v1318 ^ -1) | (-(v1318 ^ -1))) >> 31)) & 2)) - (v1319 + ((~(((v1320 ^ -1) | (-(v1320 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1379[v1475] = v1377;
    int * v1381 = v1292->cache_tags;
    int v1478 = ((((int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1)) & 1) * 2) + ((((v1316 + ((~(((v1318 ^ -1) | (-(v1318 ^ -1))) >> 31)) & 2)) - (v1319 + ((~(((v1320 ^ -1) | (-(v1320 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1479 = (int)((unsigned int)((int)((unsigned int)v1296 >> 2)) >> 1);
    v1381[v1478] = v1479;
    int * v1383 = v1292->cache_dirty;
    v1383[v1478] = 0;
    int * v1385 = v1292->cache_age;
    v1385[v1478] = 1;
    int * v1387 = v1292->cache_age;
    int v1388 = v1387[v1478];
    int v1389 = v1387[v1407];
    int v1485 = v1389 + ((int)((unsigned int)(v1389 - v1388) >> 31));
    v1387[v1407] = v1485;
    int * v1391 = v1292->cache_age;
    int v1392 = v1391[v1408];
    int v1487 = v1392 + ((int)((unsigned int)(v1392 - v1388) >> 31));
    v1391[v1408] = v1487;
    int * v1394 = v1292->cache_age;
    v1394[v1478] = 0;
    v1397 = v1478;
  }
  int v1490 = (v1397 * 2) + (((int)((unsigned int)v1296 >> 2)) & 1);
  int v1398 = v1304[v1490];
  int * v1399 = v1292->regs;
  v1399[10] = v1398;
  struct StateT * v1401 = slot_26(v1292);
  return v1401;
}

struct StateT * slot_16(struct StateT * v827) {
  int * v828 = v827->saved_regs;
  int * v829 = v827->regs;
  int v830 = v829[13];
  v828[13] = v830;
  int v832 = v827->timer;
  int v843 = v832 + 1;
  v827->timer = v843;
  int * v834 = v827->regs;
  int v835 = v834[13];
  int v845 = v835 + -1;
  v834[13] = v845;
  struct StateT * v837 = slot_17(v827);
  return v837;
}

struct StateT * slot_23(struct StateT * v1262) {
  int v1263 = v1262->timer;
  int v1270 = v1263 + 1;
  v1262->timer = v1270;
  int * v1265 = v1262->regs;
  int v1266 = v1265[10];
  int v1273 = v1266 << 2;
  v1265[10] = v1273;
  struct StateT * v1268 = slot_24(v1262);
  return v1268;
}

struct StateT * slot_5(struct StateT * v266) {
  int v267 = v266->timer;
  int v377 = v267 + 1;
  v266->timer = v377;
  int * v269 = v266->regs;
  int v270 = v269[12];
  int * v271 = v266->cache_tags;
  int v381 = (((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 1) * 2;
  int v272 = v271[v381];
  int v382 = ((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v273 = v271[v382];
  int v383 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 3) * 2);
  int v274 = v271[v383];
  int v384 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v275 = v271[v384];
  int v276 = v266->timer;
  int v385 = v276 + ((100 ^ (((~(((v274 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))) | (-(v274 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v275 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))) | (-(v275 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v272 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))) | (-(v272 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v273 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))) | (-(v273 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v274 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))) | (-(v274 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v275 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))) | (-(v275 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v266->timer = v385;
  int * v278 = v266->cache_vals;
  bool v386 = !(((~(((v272 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))) | (-(v272 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v273 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))) | (-(v273 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v371;
  if (v386) {
    int * v279 = v266->cache_age;
    int v388 = ((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v273 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))) | (-(v273 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v280 = v279[v388];
    int v281 = v279[v381];
    int v389 = v281 + ((int)((unsigned int)(v281 - v280) >> 31));
    v279[v381] = v389;
    int * v283 = v266->cache_age;
    int v284 = v283[v382];
    int v391 = v284 + ((int)((unsigned int)(v284 - v280) >> 31));
    v283[v382] = v391;
    int * v286 = v266->cache_age;
    v286[v388] = 0;
    v371 = v388;
  } else {
    int * v289 = v266->cache_age;
    int v395 = (((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 1) * 2;
    int v290 = v289[v395];
    int * v291 = v266->cache_tags;
    int v292 = v291[v395];
    int v293 = v289[v382];
    int v294 = v291[v382];
    bool v397 = !(((~(((v274 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))) | (-(v274 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v275 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))) | (-(v275 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v348;
    if (v397) {
      int * v295 = v266->cache_age;
      int v399 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v275 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))) | (-(v275 ^ ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v296 = v295[v399];
      int v297 = v295[v383];
      int v400 = v297 + ((int)((unsigned int)(v297 - v296) >> 31));
      v295[v383] = v400;
      int * v299 = v266->cache_age;
      int v300 = v299[v384];
      int v402 = v300 + ((int)((unsigned int)(v300 - v296) >> 31));
      v299[v384] = v402;
      int * v302 = v266->cache_age;
      v302[v399] = 0;
      v348 = v399;
    } else {
      int * v305 = v266->cache_age;
      int v406 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 3) * 2);
      int v306 = v305[v406];
      int * v307 = v266->cache_tags;
      int v308 = v307[v406];
      int v309 = v305[v384];
      int v310 = v307[v384];
      int * v311 = v266->cache_dirty;
      int v409 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v306 + ((~(((v308 ^ -1) | (-(v308 ^ -1))) >> 31)) & 2)) - (v309 + ((~(((v310 ^ -1) | (-(v310 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v312 = v311[v409];
      bool v410 = !(v312 == 0);
      if (v410) {
        int * v313 = v266->cache_tags;
        int v314 = v313[v409];
        int * v315 = v266->cache_vals;
        int v413 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v306 + ((~(((v308 ^ -1) | (-(v308 ^ -1))) >> 31)) & 2)) - (v309 + ((~(((v310 ^ -1) | (-(v310 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v316 = v315[v413];
        int v414 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v306 + ((~(((v308 ^ -1) | (-(v308 ^ -1))) >> 31)) & 2)) - (v309 + ((~(((v310 ^ -1) | (-(v310 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v317 = v315[v414];
        int * v318 = v266->mem;
        int v416 = v314 * 2;
        v318[v416] = v316;
        int * v320 = v266->mem;
        int v419 = (v314 * 2) + 1;
        v320[v419] = v317;
        ;
      } else {
        ;
      }
      int * v325 = v266->mem;
      int v424 = ((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) * 2;
      int v326 = v325[v424];
      int v425 = (((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) * 2) + 1;
      int v327 = v325[v425];
      int * v328 = v266->cache_vals;
      int v427 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v306 + ((~(((v308 ^ -1) | (-(v308 ^ -1))) >> 31)) & 2)) - (v309 + ((~(((v310 ^ -1) | (-(v310 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v328[v427] = v326;
      int * v330 = v266->cache_vals;
      int v430 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v306 + ((~(((v308 ^ -1) | (-(v308 ^ -1))) >> 31)) & 2)) - (v309 + ((~(((v310 ^ -1) | (-(v310 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v330[v430] = v327;
      int * v332 = v266->cache_tags;
      int v433 = (int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1);
      v332[v409] = v433;
      int * v334 = v266->cache_dirty;
      v334[v409] = 0;
      int * v336 = v266->cache_age;
      v336[v409] = 1;
      int * v338 = v266->cache_age;
      int v339 = v338[v409];
      int v340 = v338[v383];
      int v439 = v340 + ((int)((unsigned int)(v340 - v339) >> 31));
      v338[v383] = v439;
      int * v342 = v266->cache_age;
      int v343 = v342[v384];
      int v441 = v343 + ((int)((unsigned int)(v343 - v339) >> 31));
      v342[v384] = v441;
      int * v345 = v266->cache_age;
      v345[v409] = 0;
      v348 = v409;
    }
    int * v349 = v266->cache_vals;
    int v444 = v348 * 2;
    int v350 = v349[v444];
    int v445 = (v348 * 2) + 1;
    int v351 = v349[v445];
    int v446 = (((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v290 + ((~(((v292 ^ -1) | (-(v292 ^ -1))) >> 31)) & 2)) - (v293 + ((~(((v294 ^ -1) | (-(v294 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v349[v446] = v350;
    int * v353 = v266->cache_vals;
    int v449 = ((((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v290 + ((~(((v292 ^ -1) | (-(v292 ^ -1))) >> 31)) & 2)) - (v293 + ((~(((v294 ^ -1) | (-(v294 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v353[v449] = v351;
    int * v355 = v266->cache_tags;
    int v452 = ((((int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v290 + ((~(((v292 ^ -1) | (-(v292 ^ -1))) >> 31)) & 2)) - (v293 + ((~(((v294 ^ -1) | (-(v294 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v453 = (int)((unsigned int)((int)((unsigned int)(v270 + 68) >> 2)) >> 1);
    v355[v452] = v453;
    int * v357 = v266->cache_dirty;
    v357[v452] = 0;
    int * v359 = v266->cache_age;
    v359[v452] = 1;
    int * v361 = v266->cache_age;
    int v362 = v361[v452];
    int v363 = v361[v381];
    int v459 = v363 + ((int)((unsigned int)(v363 - v362) >> 31));
    v361[v381] = v459;
    int * v365 = v266->cache_age;
    int v366 = v365[v382];
    int v461 = v366 + ((int)((unsigned int)(v366 - v362) >> 31));
    v365[v382] = v461;
    int * v368 = v266->cache_age;
    v368[v452] = 0;
    v371 = v452;
  }
  int v464 = (v371 * 2) + (((int)((unsigned int)(v270 + 68) >> 2)) & 1);
  int v372 = v278[v464];
  int * v373 = v266->regs;
  v373[12] = v372;
  struct StateT * v375 = slot_6(v266);
  return v375;
}

struct StateT * slot_2(struct StateT * v218) {
  int v219 = v218->timer;
  int v223 = v219 + 1;
  v218->timer = v223;
  struct StateT * v221 = slot_3(v218);
  return v221;
}

struct StateT * slot_7(struct StateT * v489) {
  int v490 = v489->timer;
  int v497 = v490 + 1;
  v489->timer = v497;
  int * v492 = v489->regs;
  int v493 = v492[14];
  int v500 = v493 + 72;
  v492[14] = v500;
  struct StateT * v495 = slot_8(v489);
  return v495;
}

struct StateT * slot_21(struct StateT * v1211) {
  int * v1212 = v1211->saved_regs;
  int * v1213 = v1211->regs;
  int v1214 = v1213[10];
  v1212[10] = v1214;
  int v1216 = v1211->timer;
  int v1226 = v1216 + 1;
  v1211->timer = v1226;
  int * v1218 = v1211->regs;
  v1218[10] = 0;
  struct StateT * v1220 = slot_22(v1211);
  return v1220;
}

struct StateT * slot_31(struct StateT * v1575) {
  int * v1576 = v1575->saved_regs;
  int * v1577 = v1575->regs;
  int v1578 = v1577[10];
  v1576[10] = v1578;
  int v1580 = v1575->timer;
  int v1591 = v1580 + 1;
  v1575->timer = v1591;
  int * v1582 = v1575->regs;
  int v1583 = v1582[10];
  int v1593 = v1583 << 2;
  v1582[10] = v1593;
  struct StateT * v1585 = slot_32(v1575);
  return v1585;
}

struct StateT * slot_3(struct StateT * v226) {
  int * v227 = v226->saved_regs;
  int * v228 = v226->regs;
  int v229 = v228[13];
  v227[13] = v229;
  int v231 = v226->timer;
  int v241 = v231 + 1;
  v226->timer = v241;
  int * v233 = v226->regs;
  v233[13] = 0;
  struct StateT * v235 = slot_4(v226);
  return v235;
}

struct StateT * slot_26(struct StateT * v1495) {
  int v1496 = v1495->timer;
  int v1504 = v1496 + 1;
  v1495->timer = v1504;
  int * v1498 = v1495->regs;
  int v1499 = v1498[12];
  int v1500 = v1498[10];
  int v1508 = v1499 & v1500;
  v1498[12] = v1508;
  struct StateT * v1502 = slot_27(v1495);
  return v1502;
}

struct StateT * slot_10(struct StateT * v540) {
  int v541 = v540->timer;
  int v651 = v541 + 1;
  v540->timer = v651;
  int * v543 = v540->regs;
  int v544 = v543[10];
  int * v545 = v540->cache_tags;
  int v655 = (((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1)) & 1) * 2;
  int v546 = v545[v655];
  int v656 = ((((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1)) & 1) * 2) + 1;
  int v547 = v545[v656];
  int v657 = 4 + ((((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1)) & 3) * 2);
  int v548 = v545[v657];
  int v658 = (4 + ((((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v549 = v545[v658];
  int v550 = v540->timer;
  int v659 = v550 + ((100 ^ (((~(((v548 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))) | (-(v548 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))))) >> 31)) | (~(((v549 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))) | (-(v549 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v546 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))) | (-(v546 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))))) >> 31)) | (~(((v547 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))) | (-(v547 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v548 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))) | (-(v548 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))))) >> 31)) | (~(((v549 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))) | (-(v549 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))))) >> 31))) & 104)))));
  v540->timer = v659;
  int * v552 = v540->cache_vals;
  bool v660 = !(((~(((v546 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))) | (-(v546 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))))) >> 31)) | (~(((v547 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))) | (-(v547 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))))) >> 31))) == 0);
  int v645;
  if (v660) {
    int * v553 = v540->cache_age;
    int v662 = ((((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1)) & 1) * 2) + ((~(((v547 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))) | (-(v547 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))))) >> 31)) & 1);
    int v554 = v553[v662];
    int v555 = v553[v655];
    int v663 = v555 + ((int)((unsigned int)(v555 - v554) >> 31));
    v553[v655] = v663;
    int * v557 = v540->cache_age;
    int v558 = v557[v656];
    int v665 = v558 + ((int)((unsigned int)(v558 - v554) >> 31));
    v557[v656] = v665;
    int * v560 = v540->cache_age;
    v560[v662] = 0;
    v645 = v662;
  } else {
    int * v563 = v540->cache_age;
    int v669 = (((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1)) & 1) * 2;
    int v564 = v563[v669];
    int * v565 = v540->cache_tags;
    int v566 = v565[v669];
    int v567 = v563[v656];
    int v568 = v565[v656];
    bool v671 = !(((~(((v548 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))) | (-(v548 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))))) >> 31)) | (~(((v549 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))) | (-(v549 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))))) >> 31))) == 0);
    int v622;
    if (v671) {
      int * v569 = v540->cache_age;
      int v673 = (4 + ((((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1)) & 3) * 2)) + ((~(((v549 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))) | (-(v549 ^ ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1))))) >> 31)) & 1);
      int v570 = v569[v673];
      int v571 = v569[v657];
      int v674 = v571 + ((int)((unsigned int)(v571 - v570) >> 31));
      v569[v657] = v674;
      int * v573 = v540->cache_age;
      int v574 = v573[v658];
      int v676 = v574 + ((int)((unsigned int)(v574 - v570) >> 31));
      v573[v658] = v676;
      int * v576 = v540->cache_age;
      v576[v673] = 0;
      v622 = v673;
    } else {
      int * v579 = v540->cache_age;
      int v680 = 4 + ((((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1)) & 3) * 2);
      int v580 = v579[v680];
      int * v581 = v540->cache_tags;
      int v582 = v581[v680];
      int v583 = v579[v658];
      int v584 = v581[v658];
      int * v585 = v540->cache_dirty;
      int v683 = (4 + ((((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1)) & 3) * 2)) + ((((v580 + ((~(((v582 ^ -1) | (-(v582 ^ -1))) >> 31)) & 2)) - (v583 + ((~(((v584 ^ -1) | (-(v584 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v586 = v585[v683];
      bool v684 = !(v586 == 0);
      if (v684) {
        int * v587 = v540->cache_tags;
        int v588 = v587[v683];
        int * v589 = v540->cache_vals;
        int v687 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1)) & 3) * 2)) + ((((v580 + ((~(((v582 ^ -1) | (-(v582 ^ -1))) >> 31)) & 2)) - (v583 + ((~(((v584 ^ -1) | (-(v584 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v590 = v589[v687];
        int v688 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1)) & 3) * 2)) + ((((v580 + ((~(((v582 ^ -1) | (-(v582 ^ -1))) >> 31)) & 2)) - (v583 + ((~(((v584 ^ -1) | (-(v584 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v591 = v589[v688];
        int * v592 = v540->mem;
        int v690 = v588 * 2;
        v592[v690] = v590;
        int * v594 = v540->mem;
        int v693 = (v588 * 2) + 1;
        v594[v693] = v591;
        ;
      } else {
        ;
      }
      int * v599 = v540->mem;
      int v698 = ((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1)) * 2;
      int v600 = v599[v698];
      int v699 = (((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1)) * 2) + 1;
      int v601 = v599[v699];
      int * v602 = v540->cache_vals;
      int v701 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1)) & 3) * 2)) + ((((v580 + ((~(((v582 ^ -1) | (-(v582 ^ -1))) >> 31)) & 2)) - (v583 + ((~(((v584 ^ -1) | (-(v584 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v602[v701] = v600;
      int * v604 = v540->cache_vals;
      int v704 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1)) & 3) * 2)) + ((((v580 + ((~(((v582 ^ -1) | (-(v582 ^ -1))) >> 31)) & 2)) - (v583 + ((~(((v584 ^ -1) | (-(v584 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v604[v704] = v601;
      int * v606 = v540->cache_tags;
      int v707 = (int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1);
      v606[v683] = v707;
      int * v608 = v540->cache_dirty;
      v608[v683] = 0;
      int * v610 = v540->cache_age;
      v610[v683] = 1;
      int * v612 = v540->cache_age;
      int v613 = v612[v683];
      int v614 = v612[v657];
      int v713 = v614 + ((int)((unsigned int)(v614 - v613) >> 31));
      v612[v657] = v713;
      int * v616 = v540->cache_age;
      int v617 = v616[v658];
      int v715 = v617 + ((int)((unsigned int)(v617 - v613) >> 31));
      v616[v658] = v715;
      int * v619 = v540->cache_age;
      v619[v683] = 0;
      v622 = v683;
    }
    int * v623 = v540->cache_vals;
    int v718 = v622 * 2;
    int v624 = v623[v718];
    int v719 = (v622 * 2) + 1;
    int v625 = v623[v719];
    int v720 = (((((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1)) & 1) * 2) + ((((v564 + ((~(((v566 ^ -1) | (-(v566 ^ -1))) >> 31)) & 2)) - (v567 + ((~(((v568 ^ -1) | (-(v568 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v623[v720] = v624;
    int * v627 = v540->cache_vals;
    int v723 = ((((((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1)) & 1) * 2) + ((((v564 + ((~(((v566 ^ -1) | (-(v566 ^ -1))) >> 31)) & 2)) - (v567 + ((~(((v568 ^ -1) | (-(v568 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v627[v723] = v625;
    int * v629 = v540->cache_tags;
    int v726 = ((((int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1)) & 1) * 2) + ((((v564 + ((~(((v566 ^ -1) | (-(v566 ^ -1))) >> 31)) & 2)) - (v567 + ((~(((v568 ^ -1) | (-(v568 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v727 = (int)((unsigned int)((int)((unsigned int)v544 >> 2)) >> 1);
    v629[v726] = v727;
    int * v631 = v540->cache_dirty;
    v631[v726] = 0;
    int * v633 = v540->cache_age;
    v633[v726] = 1;
    int * v635 = v540->cache_age;
    int v636 = v635[v726];
    int v637 = v635[v655];
    int v733 = v637 + ((int)((unsigned int)(v637 - v636) >> 31));
    v635[v655] = v733;
    int * v639 = v540->cache_age;
    int v640 = v639[v656];
    int v735 = v640 + ((int)((unsigned int)(v640 - v636) >> 31));
    v639[v656] = v735;
    int * v642 = v540->cache_age;
    v642[v726] = 0;
    v645 = v726;
  }
  int v738 = (v645 * 2) + (((int)((unsigned int)v544 >> 2)) & 1);
  int v646 = v552[v738];
  int * v647 = v540->regs;
  v647[10] = v646;
  struct StateT * v649 = slot_11(v540);
  return v649;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v126 = v16 + 1;
  v15->timer = v126;
  int * v18 = v15->regs;
  int v19 = v18[11];
  int * v20 = v15->cache_tags;
  int v130 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2;
  int v21 = v20[v130];
  int v131 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + 1;
  int v22 = v20[v131];
  int v132 = 4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2);
  int v23 = v20[v132];
  int v133 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v24 = v20[v133];
  int v25 = v15->timer;
  int v134 = v25 + ((100 ^ (((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & 104)))));
  v15->timer = v134;
  int * v27 = v15->cache_vals;
  bool v135 = !(((~(((v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) == 0);
  int v120;
  if (v135) {
    int * v28 = v15->cache_age;
    int v137 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) & 1);
    int v29 = v28[v137];
    int v30 = v28[v130];
    int v138 = v30 + ((int)((unsigned int)(v30 - v29) >> 31));
    v28[v130] = v138;
    int * v32 = v15->cache_age;
    int v33 = v32[v131];
    int v140 = v33 + ((int)((unsigned int)(v33 - v29) >> 31));
    v32[v131] = v140;
    int * v35 = v15->cache_age;
    v35[v137] = 0;
    v120 = v137;
  } else {
    int * v38 = v15->cache_age;
    int v144 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2;
    int v39 = v38[v144];
    int * v40 = v15->cache_tags;
    int v41 = v40[v144];
    int v42 = v38[v131];
    int v43 = v40[v131];
    bool v146 = !(((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) == 0);
    int v97;
    if (v146) {
      int * v44 = v15->cache_age;
      int v148 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) & 1);
      int v45 = v44[v148];
      int v46 = v44[v132];
      int v149 = v46 + ((int)((unsigned int)(v46 - v45) >> 31));
      v44[v132] = v149;
      int * v48 = v15->cache_age;
      int v49 = v48[v133];
      int v151 = v49 + ((int)((unsigned int)(v49 - v45) >> 31));
      v48[v133] = v151;
      int * v51 = v15->cache_age;
      v51[v148] = 0;
      v97 = v148;
    } else {
      int * v54 = v15->cache_age;
      int v155 = 4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2);
      int v55 = v54[v155];
      int * v56 = v15->cache_tags;
      int v57 = v56[v155];
      int v58 = v54[v133];
      int v59 = v56[v133];
      int * v60 = v15->cache_dirty;
      int v158 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v61 = v60[v158];
      bool v159 = !(v61 == 0);
      if (v159) {
        int * v62 = v15->cache_tags;
        int v63 = v62[v158];
        int * v64 = v15->cache_vals;
        int v162 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v65 = v64[v162];
        int v163 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v66 = v64[v163];
        int * v67 = v15->mem;
        int v165 = v63 * 2;
        v67[v165] = v65;
        int * v69 = v15->mem;
        int v168 = (v63 * 2) + 1;
        v69[v168] = v66;
        ;
      } else {
        ;
      }
      int * v74 = v15->mem;
      int v173 = ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) * 2;
      int v75 = v74[v173];
      int v174 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) * 2) + 1;
      int v76 = v74[v174];
      int * v77 = v15->cache_vals;
      int v176 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v77[v176] = v75;
      int * v79 = v15->cache_vals;
      int v179 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v79[v179] = v76;
      int * v81 = v15->cache_tags;
      int v182 = (int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1);
      v81[v158] = v182;
      int * v83 = v15->cache_dirty;
      v83[v158] = 0;
      int * v85 = v15->cache_age;
      v85[v158] = 1;
      int * v87 = v15->cache_age;
      int v88 = v87[v158];
      int v89 = v87[v132];
      int v188 = v89 + ((int)((unsigned int)(v89 - v88) >> 31));
      v87[v132] = v188;
      int * v91 = v15->cache_age;
      int v92 = v91[v133];
      int v190 = v92 + ((int)((unsigned int)(v92 - v88) >> 31));
      v91[v133] = v190;
      int * v94 = v15->cache_age;
      v94[v158] = 0;
      v97 = v158;
    }
    int * v98 = v15->cache_vals;
    int v193 = v97 * 2;
    int v99 = v98[v193];
    int v194 = (v97 * 2) + 1;
    int v100 = v98[v194];
    int v195 = (((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v39 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2)) - (v42 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v98[v195] = v99;
    int * v102 = v15->cache_vals;
    int v198 = ((((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v39 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2)) - (v42 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v102[v198] = v100;
    int * v104 = v15->cache_tags;
    int v201 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v39 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2)) - (v42 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v202 = (int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1);
    v104[v201] = v202;
    int * v106 = v15->cache_dirty;
    v106[v201] = 0;
    int * v108 = v15->cache_age;
    v108[v201] = 1;
    int * v110 = v15->cache_age;
    int v111 = v110[v201];
    int v112 = v110[v130];
    int v208 = v112 + ((int)((unsigned int)(v112 - v111) >> 31));
    v110[v130] = v208;
    int * v114 = v15->cache_age;
    int v115 = v114[v131];
    int v210 = v115 + ((int)((unsigned int)(v115 - v111) >> 31));
    v114[v131] = v210;
    int * v117 = v15->cache_age;
    v117[v201] = 0;
    v120 = v201;
  }
  int v213 = (v120 * 2) + (((int)((unsigned int)v19 >> 2)) & 1);
  int v121 = v27[v213];
  int * v122 = v15->regs;
  v122[11] = v121;
  struct StateT * v124 = slot_2(v15);
  return v124;
}

struct StateT * slot_19(struct StateT * v888) {
  int v889 = v888->timer;
  int v893 = v889 + 1;
  v888->timer = v893;
  struct StateT * v891 = slot_21(v888);
  return v891;
}

struct StateT * slot_13(struct StateT * v814) {
  int v815 = v814->timer;
  int v818 = v815 + 1;
  v814->timer = v818;
  return v814;
}

struct StateT * slot_24(struct StateT * v1276) {
  int v1277 = v1276->timer;
  int v1285 = v1277 + 1;
  v1276->timer = v1285;
  int * v1279 = v1276->regs;
  int v1280 = v1279[14];
  int v1281 = v1279[10];
  int v1289 = v1280 + v1281;
  v1279[10] = v1289;
  struct StateT * v1283 = slot_25(v1276);
  return v1283;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[11] = 0;
  struct StateT * v7 = slot_1(v2);
  return v7;
}

struct StateT * slot_14(struct StateT * v819) {
  int v820 = v819->timer;
  int v824 = v820 + 1;
  v819->timer = v824;
  struct StateT * v822 = slot_16(v819);
  return v822;
}

struct StateT * slot_28(struct StateT * v1519) {
  int * v1520 = v1519->saved_regs;
  int * v1521 = v1519->regs;
  int v1522 = v1521[13];
  v1520[13] = v1522;
  int v1524 = v1519->timer;
  int v1535 = v1524 + 1;
  v1519->timer = v1535;
  int * v1526 = v1519->regs;
  int v1527 = v1526[13];
  int v1537 = v1527 + -1;
  v1526[13] = v1537;
  struct StateT * v1529 = slot_29(v1519);
  return v1529;
}

struct StateT * slot_32(struct StateT * v1596) {
  int v1597 = v1596->timer;
  int v1605 = v1597 + 1;
  v1596->timer = v1605;
  int * v1599 = v1596->regs;
  int v1600 = v1599[14];
  int v1601 = v1599[10];
  int v1609 = v1600 + v1601;
  v1599[10] = v1609;
  struct StateT * v1603 = slot_33(v1596);
  return v1603;
}

struct StateT * slot_17(struct StateT * v848) {
  int * v849 = v848->saved_regs;
  int v850 = v849[13];
  bool v865 = !(v850 == 0);
  struct StateT * v861;
  if (v865) {
    int v851 = v848->timer;
    int v866 = v851 + 15;
    v848->timer = v866;
    int * v853 = v848->saved_regs;
    int v854 = v853[13];
    int * v855 = v848->regs;
    v855[13] = v854;
    struct StateT * v857 = slot_18(v848);
    v861 = v857;
  } else {
    struct StateT * v859 = slot_19(v848);
    v861 = v859;
  }
  return v861;
}

struct StateT * slot_20(struct StateT * v896) {
  int v897 = v896->timer;
  int v1067 = v897 + 1;
  v896->timer = v1067;
  int * v899 = v896->regs;
  int v900 = v899[10];
  int v901 = v899[12];
  int * v902 = v896->cache_tags;
  int v1072 = (((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1)) & 1) * 2;
  int v903 = v902[v1072];
  int v1073 = ((((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v904 = v902[v1073];
  int v1074 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1)) & 3) * 2);
  int v905 = v902[v1074];
  int v1075 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v906 = v902[v1075];
  int v907 = v896->timer;
  int v1076 = v907 + ((100 ^ (((~(((v905 ^ ((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1))) | (-(v905 ^ ((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v906 ^ ((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1))) | (-(v906 ^ ((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v903 ^ ((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1))) | (-(v903 ^ ((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v904 ^ ((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1))) | (-(v904 ^ ((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v905 ^ ((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1))) | (-(v905 ^ ((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v906 ^ ((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1))) | (-(v906 ^ ((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v896->timer = v1076;
  bool v1077 = !(((~(((v903 ^ ((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1))) | (-(v903 ^ ((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v904 ^ ((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1))) | (-(v904 ^ ((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1001;
  if (v1077) {
    int * v909 = v896->cache_age;
    int v1079 = ((((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v904 ^ ((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1))) | (-(v904 ^ ((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v910 = v909[v1079];
    int v911 = v909[v1072];
    int v1080 = v911 + ((int)((unsigned int)(v911 - v910) >> 31));
    v909[v1072] = v1080;
    int * v913 = v896->cache_age;
    int v914 = v913[v1073];
    int v1082 = v914 + ((int)((unsigned int)(v914 - v910) >> 31));
    v913[v1073] = v1082;
    int * v916 = v896->cache_age;
    v916[v1079] = 0;
    v1001 = v1079;
  } else {
    int * v919 = v896->cache_age;
    int v1086 = (((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1)) & 1) * 2;
    int v920 = v919[v1086];
    int * v921 = v896->cache_tags;
    int v922 = v921[v1086];
    int v923 = v919[v1073];
    int v924 = v921[v1073];
    bool v1088 = !(((~(((v905 ^ ((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1))) | (-(v905 ^ ((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v906 ^ ((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1))) | (-(v906 ^ ((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v978;
    if (v1088) {
      int * v925 = v896->cache_age;
      int v1090 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v906 ^ ((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1))) | (-(v906 ^ ((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v926 = v925[v1090];
      int v927 = v925[v1074];
      int v1091 = v927 + ((int)((unsigned int)(v927 - v926) >> 31));
      v925[v1074] = v1091;
      int * v929 = v896->cache_age;
      int v930 = v929[v1075];
      int v1093 = v930 + ((int)((unsigned int)(v930 - v926) >> 31));
      v929[v1075] = v1093;
      int * v932 = v896->cache_age;
      v932[v1090] = 0;
      v978 = v1090;
    } else {
      int * v935 = v896->cache_age;
      int v1097 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1)) & 3) * 2);
      int v936 = v935[v1097];
      int * v937 = v896->cache_tags;
      int v938 = v937[v1097];
      int v939 = v935[v1075];
      int v940 = v937[v1075];
      int * v941 = v896->cache_dirty;
      int v1100 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v936 + ((~(((v938 ^ -1) | (-(v938 ^ -1))) >> 31)) & 2)) - (v939 + ((~(((v940 ^ -1) | (-(v940 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v942 = v941[v1100];
      bool v1101 = !(v942 == 0);
      if (v1101) {
        int * v943 = v896->cache_tags;
        int v944 = v943[v1100];
        int * v945 = v896->cache_vals;
        int v1104 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v936 + ((~(((v938 ^ -1) | (-(v938 ^ -1))) >> 31)) & 2)) - (v939 + ((~(((v940 ^ -1) | (-(v940 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v946 = v945[v1104];
        int v1105 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v936 + ((~(((v938 ^ -1) | (-(v938 ^ -1))) >> 31)) & 2)) - (v939 + ((~(((v940 ^ -1) | (-(v940 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v947 = v945[v1105];
        int * v948 = v896->mem;
        int v1107 = v944 * 2;
        v948[v1107] = v946;
        int * v950 = v896->mem;
        int v1110 = (v944 * 2) + 1;
        v950[v1110] = v947;
        ;
      } else {
        ;
      }
      int * v955 = v896->mem;
      int v1115 = ((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1)) * 2;
      int v956 = v955[v1115];
      int v1116 = (((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1)) * 2) + 1;
      int v957 = v955[v1116];
      int * v958 = v896->cache_vals;
      int v1118 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v936 + ((~(((v938 ^ -1) | (-(v938 ^ -1))) >> 31)) & 2)) - (v939 + ((~(((v940 ^ -1) | (-(v940 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v958[v1118] = v956;
      int * v960 = v896->cache_vals;
      int v1121 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v936 + ((~(((v938 ^ -1) | (-(v938 ^ -1))) >> 31)) & 2)) - (v939 + ((~(((v940 ^ -1) | (-(v940 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v960[v1121] = v957;
      int * v962 = v896->cache_tags;
      int v1124 = (int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1);
      v962[v1100] = v1124;
      int * v964 = v896->cache_dirty;
      v964[v1100] = 0;
      int * v966 = v896->cache_age;
      v966[v1100] = 1;
      int * v968 = v896->cache_age;
      int v969 = v968[v1100];
      int v970 = v968[v1074];
      int v1130 = v970 + ((int)((unsigned int)(v970 - v969) >> 31));
      v968[v1074] = v1130;
      int * v972 = v896->cache_age;
      int v973 = v972[v1075];
      int v1132 = v973 + ((int)((unsigned int)(v973 - v969) >> 31));
      v972[v1075] = v1132;
      int * v975 = v896->cache_age;
      v975[v1100] = 0;
      v978 = v1100;
    }
    int * v979 = v896->cache_vals;
    int v1135 = v978 * 2;
    int v980 = v979[v1135];
    int v1136 = (v978 * 2) + 1;
    int v981 = v979[v1136];
    int v1137 = (((((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v920 + ((~(((v922 ^ -1) | (-(v922 ^ -1))) >> 31)) & 2)) - (v923 + ((~(((v924 ^ -1) | (-(v924 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v979[v1137] = v980;
    int * v983 = v896->cache_vals;
    int v1140 = ((((((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v920 + ((~(((v922 ^ -1) | (-(v922 ^ -1))) >> 31)) & 2)) - (v923 + ((~(((v924 ^ -1) | (-(v924 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v983[v1140] = v981;
    int * v985 = v896->cache_tags;
    int v1143 = ((((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v920 + ((~(((v922 ^ -1) | (-(v922 ^ -1))) >> 31)) & 2)) - (v923 + ((~(((v924 ^ -1) | (-(v924 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1144 = (int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1);
    v985[v1143] = v1144;
    int * v987 = v896->cache_dirty;
    v987[v1143] = 0;
    int * v989 = v896->cache_age;
    v989[v1143] = 1;
    int * v991 = v896->cache_age;
    int v992 = v991[v1143];
    int v993 = v991[v1072];
    int v1150 = v993 + ((int)((unsigned int)(v993 - v992) >> 31));
    v991[v1072] = v1150;
    int * v995 = v896->cache_age;
    int v996 = v995[v1073];
    int v1152 = v996 + ((int)((unsigned int)(v996 - v992) >> 31));
    v995[v1073] = v1152;
    int * v998 = v896->cache_age;
    v998[v1143] = 0;
    v1001 = v1143;
  }
  int * v1002 = v896->cache_vals;
  int v1155 = (v1001 * 2) + (((int)((unsigned int)(v900 + 68) >> 2)) & 1);
  v1002[v1155] = v901;
  int * v1004 = v896->cache_tags;
  int v1005 = v1004[v1074];
  int v1006 = v1004[v1075];
  bool v1158 = !(((~(((v1005 ^ ((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1))) | (-(v1005 ^ ((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1006 ^ ((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1))) | (-(v1006 ^ ((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1060;
  if (v1158) {
    int * v1007 = v896->cache_age;
    int v1160 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1006 ^ ((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1))) | (-(v1006 ^ ((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1008 = v1007[v1160];
    int v1009 = v1007[v1074];
    int v1161 = v1009 + ((int)((unsigned int)(v1009 - v1008) >> 31));
    v1007[v1074] = v1161;
    int * v1011 = v896->cache_age;
    int v1012 = v1011[v1075];
    int v1163 = v1012 + ((int)((unsigned int)(v1012 - v1008) >> 31));
    v1011[v1075] = v1163;
    int * v1014 = v896->cache_age;
    v1014[v1160] = 0;
    v1060 = v1160;
  } else {
    int * v1017 = v896->cache_age;
    int v1167 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1018 = v1017[v1167];
    int * v1019 = v896->cache_tags;
    int v1020 = v1019[v1167];
    int v1021 = v1017[v1075];
    int v1022 = v1019[v1075];
    int * v1023 = v896->cache_dirty;
    int v1170 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1018 + ((~(((v1020 ^ -1) | (-(v1020 ^ -1))) >> 31)) & 2)) - (v1021 + ((~(((v1022 ^ -1) | (-(v1022 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1024 = v1023[v1170];
    bool v1171 = !(v1024 == 0);
    if (v1171) {
      int * v1025 = v896->cache_tags;
      int v1026 = v1025[v1170];
      int * v1027 = v896->cache_vals;
      int v1174 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1018 + ((~(((v1020 ^ -1) | (-(v1020 ^ -1))) >> 31)) & 2)) - (v1021 + ((~(((v1022 ^ -1) | (-(v1022 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1028 = v1027[v1174];
      int v1175 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1018 + ((~(((v1020 ^ -1) | (-(v1020 ^ -1))) >> 31)) & 2)) - (v1021 + ((~(((v1022 ^ -1) | (-(v1022 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1029 = v1027[v1175];
      int * v1030 = v896->mem;
      int v1177 = v1026 * 2;
      v1030[v1177] = v1028;
      int * v1032 = v896->mem;
      int v1180 = (v1026 * 2) + 1;
      v1032[v1180] = v1029;
      ;
    } else {
      ;
    }
    int * v1037 = v896->mem;
    int v1185 = ((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1)) * 2;
    int v1038 = v1037[v1185];
    int v1186 = (((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1039 = v1037[v1186];
    int * v1040 = v896->cache_vals;
    int v1188 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1018 + ((~(((v1020 ^ -1) | (-(v1020 ^ -1))) >> 31)) & 2)) - (v1021 + ((~(((v1022 ^ -1) | (-(v1022 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1040[v1188] = v1038;
    int * v1042 = v896->cache_vals;
    int v1191 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1018 + ((~(((v1020 ^ -1) | (-(v1020 ^ -1))) >> 31)) & 2)) - (v1021 + ((~(((v1022 ^ -1) | (-(v1022 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1042[v1191] = v1039;
    int * v1044 = v896->cache_tags;
    int v1194 = (int)((unsigned int)((int)((unsigned int)(v900 + 68) >> 2)) >> 1);
    v1044[v1170] = v1194;
    int * v1046 = v896->cache_dirty;
    v1046[v1170] = 0;
    int * v1048 = v896->cache_age;
    v1048[v1170] = 1;
    int * v1050 = v896->cache_age;
    int v1051 = v1050[v1170];
    int v1052 = v1050[v1074];
    int v1200 = v1052 + ((int)((unsigned int)(v1052 - v1051) >> 31));
    v1050[v1074] = v1200;
    int * v1054 = v896->cache_age;
    int v1055 = v1054[v1075];
    int v1202 = v1055 + ((int)((unsigned int)(v1055 - v1051) >> 31));
    v1054[v1075] = v1202;
    int * v1057 = v896->cache_age;
    v1057[v1170] = 0;
    v1060 = v1170;
  }
  int * v1061 = v896->cache_vals;
  int v1205 = (v1060 * 2) + (((int)((unsigned int)(v900 + 68) >> 2)) & 1);
  v1061[v1205] = v901;
  int * v1063 = v896->cache_dirty;
  v1063[v1060] = 1;
  struct StateT * v1065 = slot_13(v896);
  return v1065;
}

struct StateT * slot_33(struct StateT * v1612) {
  int v1613 = v1612->timer;
  int v1723 = v1613 + 1;
  v1612->timer = v1723;
  int * v1615 = v1612->regs;
  int v1616 = v1615[10];
  int * v1617 = v1612->cache_tags;
  int v1727 = (((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1)) & 1) * 2;
  int v1618 = v1617[v1727];
  int v1728 = ((((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1619 = v1617[v1728];
  int v1729 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1)) & 3) * 2);
  int v1620 = v1617[v1729];
  int v1730 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1621 = v1617[v1730];
  int v1622 = v1612->timer;
  int v1731 = v1622 + ((100 ^ (((~(((v1620 ^ ((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1))) | (-(v1620 ^ ((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1))))) >> 31)) | (~(((v1621 ^ ((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1))) | (-(v1621 ^ ((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1618 ^ ((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1))) | (-(v1618 ^ ((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1))))) >> 31)) | (~(((v1619 ^ ((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1))) | (-(v1619 ^ ((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1620 ^ ((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1))) | (-(v1620 ^ ((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1))))) >> 31)) | (~(((v1621 ^ ((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1))) | (-(v1621 ^ ((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1612->timer = v1731;
  int * v1624 = v1612->cache_vals;
  bool v1732 = !(((~(((v1618 ^ ((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1))) | (-(v1618 ^ ((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1))))) >> 31)) | (~(((v1619 ^ ((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1))) | (-(v1619 ^ ((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1))))) >> 31))) == 0);
  int v1717;
  if (v1732) {
    int * v1625 = v1612->cache_age;
    int v1734 = ((((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1)) & 1) * 2) + ((~(((v1619 ^ ((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1))) | (-(v1619 ^ ((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1))))) >> 31)) & 1);
    int v1626 = v1625[v1734];
    int v1627 = v1625[v1727];
    int v1735 = v1627 + ((int)((unsigned int)(v1627 - v1626) >> 31));
    v1625[v1727] = v1735;
    int * v1629 = v1612->cache_age;
    int v1630 = v1629[v1728];
    int v1737 = v1630 + ((int)((unsigned int)(v1630 - v1626) >> 31));
    v1629[v1728] = v1737;
    int * v1632 = v1612->cache_age;
    v1632[v1734] = 0;
    v1717 = v1734;
  } else {
    int * v1635 = v1612->cache_age;
    int v1741 = (((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1)) & 1) * 2;
    int v1636 = v1635[v1741];
    int * v1637 = v1612->cache_tags;
    int v1638 = v1637[v1741];
    int v1639 = v1635[v1728];
    int v1640 = v1637[v1728];
    bool v1743 = !(((~(((v1620 ^ ((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1))) | (-(v1620 ^ ((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1))))) >> 31)) | (~(((v1621 ^ ((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1))) | (-(v1621 ^ ((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1))))) >> 31))) == 0);
    int v1694;
    if (v1743) {
      int * v1641 = v1612->cache_age;
      int v1745 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1621 ^ ((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1))) | (-(v1621 ^ ((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1))))) >> 31)) & 1);
      int v1642 = v1641[v1745];
      int v1643 = v1641[v1729];
      int v1746 = v1643 + ((int)((unsigned int)(v1643 - v1642) >> 31));
      v1641[v1729] = v1746;
      int * v1645 = v1612->cache_age;
      int v1646 = v1645[v1730];
      int v1748 = v1646 + ((int)((unsigned int)(v1646 - v1642) >> 31));
      v1645[v1730] = v1748;
      int * v1648 = v1612->cache_age;
      v1648[v1745] = 0;
      v1694 = v1745;
    } else {
      int * v1651 = v1612->cache_age;
      int v1752 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1)) & 3) * 2);
      int v1652 = v1651[v1752];
      int * v1653 = v1612->cache_tags;
      int v1654 = v1653[v1752];
      int v1655 = v1651[v1730];
      int v1656 = v1653[v1730];
      int * v1657 = v1612->cache_dirty;
      int v1755 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1)) & 3) * 2)) + ((((v1652 + ((~(((v1654 ^ -1) | (-(v1654 ^ -1))) >> 31)) & 2)) - (v1655 + ((~(((v1656 ^ -1) | (-(v1656 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1658 = v1657[v1755];
      bool v1756 = !(v1658 == 0);
      if (v1756) {
        int * v1659 = v1612->cache_tags;
        int v1660 = v1659[v1755];
        int * v1661 = v1612->cache_vals;
        int v1759 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1)) & 3) * 2)) + ((((v1652 + ((~(((v1654 ^ -1) | (-(v1654 ^ -1))) >> 31)) & 2)) - (v1655 + ((~(((v1656 ^ -1) | (-(v1656 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1662 = v1661[v1759];
        int v1760 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1)) & 3) * 2)) + ((((v1652 + ((~(((v1654 ^ -1) | (-(v1654 ^ -1))) >> 31)) & 2)) - (v1655 + ((~(((v1656 ^ -1) | (-(v1656 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1663 = v1661[v1760];
        int * v1664 = v1612->mem;
        int v1762 = v1660 * 2;
        v1664[v1762] = v1662;
        int * v1666 = v1612->mem;
        int v1765 = (v1660 * 2) + 1;
        v1666[v1765] = v1663;
        ;
      } else {
        ;
      }
      int * v1671 = v1612->mem;
      int v1770 = ((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1)) * 2;
      int v1672 = v1671[v1770];
      int v1771 = (((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1)) * 2) + 1;
      int v1673 = v1671[v1771];
      int * v1674 = v1612->cache_vals;
      int v1773 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1)) & 3) * 2)) + ((((v1652 + ((~(((v1654 ^ -1) | (-(v1654 ^ -1))) >> 31)) & 2)) - (v1655 + ((~(((v1656 ^ -1) | (-(v1656 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1674[v1773] = v1672;
      int * v1676 = v1612->cache_vals;
      int v1776 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1)) & 3) * 2)) + ((((v1652 + ((~(((v1654 ^ -1) | (-(v1654 ^ -1))) >> 31)) & 2)) - (v1655 + ((~(((v1656 ^ -1) | (-(v1656 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1676[v1776] = v1673;
      int * v1678 = v1612->cache_tags;
      int v1779 = (int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1);
      v1678[v1755] = v1779;
      int * v1680 = v1612->cache_dirty;
      v1680[v1755] = 0;
      int * v1682 = v1612->cache_age;
      v1682[v1755] = 1;
      int * v1684 = v1612->cache_age;
      int v1685 = v1684[v1755];
      int v1686 = v1684[v1729];
      int v1785 = v1686 + ((int)((unsigned int)(v1686 - v1685) >> 31));
      v1684[v1729] = v1785;
      int * v1688 = v1612->cache_age;
      int v1689 = v1688[v1730];
      int v1787 = v1689 + ((int)((unsigned int)(v1689 - v1685) >> 31));
      v1688[v1730] = v1787;
      int * v1691 = v1612->cache_age;
      v1691[v1755] = 0;
      v1694 = v1755;
    }
    int * v1695 = v1612->cache_vals;
    int v1790 = v1694 * 2;
    int v1696 = v1695[v1790];
    int v1791 = (v1694 * 2) + 1;
    int v1697 = v1695[v1791];
    int v1792 = (((((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1)) & 1) * 2) + ((((v1636 + ((~(((v1638 ^ -1) | (-(v1638 ^ -1))) >> 31)) & 2)) - (v1639 + ((~(((v1640 ^ -1) | (-(v1640 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1695[v1792] = v1696;
    int * v1699 = v1612->cache_vals;
    int v1795 = ((((((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1)) & 1) * 2) + ((((v1636 + ((~(((v1638 ^ -1) | (-(v1638 ^ -1))) >> 31)) & 2)) - (v1639 + ((~(((v1640 ^ -1) | (-(v1640 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1699[v1795] = v1697;
    int * v1701 = v1612->cache_tags;
    int v1798 = ((((int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1)) & 1) * 2) + ((((v1636 + ((~(((v1638 ^ -1) | (-(v1638 ^ -1))) >> 31)) & 2)) - (v1639 + ((~(((v1640 ^ -1) | (-(v1640 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1799 = (int)((unsigned int)((int)((unsigned int)v1616 >> 2)) >> 1);
    v1701[v1798] = v1799;
    int * v1703 = v1612->cache_dirty;
    v1703[v1798] = 0;
    int * v1705 = v1612->cache_age;
    v1705[v1798] = 1;
    int * v1707 = v1612->cache_age;
    int v1708 = v1707[v1798];
    int v1709 = v1707[v1727];
    int v1805 = v1709 + ((int)((unsigned int)(v1709 - v1708) >> 31));
    v1707[v1727] = v1805;
    int * v1711 = v1612->cache_age;
    int v1712 = v1711[v1728];
    int v1807 = v1712 + ((int)((unsigned int)(v1712 - v1708) >> 31));
    v1711[v1728] = v1807;
    int * v1714 = v1612->cache_age;
    v1714[v1798] = 0;
    v1717 = v1798;
  }
  int v1810 = (v1717 * 2) + (((int)((unsigned int)v1616 >> 2)) & 1);
  int v1718 = v1624[v1810];
  int * v1719 = v1612->regs;
  v1719[10] = v1718;
  struct StateT * v1721 = slot_34(v1612);
  return v1721;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_8(struct StateT * v503) {
  int * v504 = v503->saved_regs;
  int * v505 = v503->regs;
  int v506 = v505[10];
  v504[10] = v506;
  int v508 = v503->timer;
  int v519 = v508 + 1;
  v503->timer = v519;
  int * v510 = v503->regs;
  int v511 = v510[10];
  int v521 = v511 << 2;
  v510[10] = v521;
  struct StateT * v513 = slot_9(v503);
  return v513;
}

struct StateT * slot_27(struct StateT * v1511) {
  int v1512 = v1511->timer;
  int v1516 = v1512 + 1;
  v1511->timer = v1516;
  struct StateT * v1514 = slot_28(v1511);
  return v1514;
}

struct StateT * slot_30(struct StateT * v1567) {
  int v1568 = v1567->timer;
  int v1572 = v1568 + 1;
  v1567->timer = v1572;
  struct StateT * v1570 = slot_31(v1567);
  return v1570;
}

struct StateT * slot_4(struct StateT * v246) {
  int * v247 = v246->saved_regs;
  int * v248 = v246->regs;
  int v249 = v248[12];
  v247[12] = v249;
  int v251 = v246->timer;
  int v261 = v251 + 1;
  v246->timer = v261;
  int * v253 = v246->regs;
  v253[12] = 0;
  struct StateT * v255 = slot_5(v246);
  return v255;
}

struct StateT * slot_18(struct StateT * v875) {
  int v876 = v875->timer;
  int v882 = v876 + 1;
  v875->timer = v882;
  int * v878 = v875->regs;
  v878[10] = 0;
  struct StateT * v880 = slot_20(v875);
  return v880;
}

struct StateT * slot_9(struct StateT * v524) {
  int v525 = v524->timer;
  int v533 = v525 + 1;
  v524->timer = v533;
  int * v527 = v524->regs;
  int v528 = v527[14];
  int v529 = v527[10];
  int v537 = v528 + v529;
  v527[10] = v537;
  struct StateT * v531 = slot_10(v524);
  return v531;
}

struct StateT * slot_22(struct StateT * v1231) {
  int * v1232 = v1231->saved_regs;
  int v1233 = v1232[10];
  int * v1234 = v1231->regs;
  int v1235 = v1234[11];
  bool v1252 = (v1233 ^ -2147483648) < (v1235 ^ -2147483648);
  struct StateT * v1246;
  if (v1252) {
    int v1236 = v1231->timer;
    int v1253 = v1236 + 15;
    v1231->timer = v1253;
    int * v1238 = v1231->saved_regs;
    int v1239 = v1238[10];
    int * v1240 = v1231->regs;
    v1240[10] = v1239;
    struct StateT * v1242 = slot_23(v1231);
    v1246 = v1242;
  } else {
    struct StateT * v1244 = slot_20(v1231);
    v1246 = v1244;
  }
  return v1246;
}

struct StateT * slot_11(struct StateT * v743) {
  int v744 = v743->timer;
  int v752 = v744 + 1;
  v743->timer = v752;
  int * v746 = v743->regs;
  int v747 = v746[12];
  int v748 = v746[10];
  int v756 = v747 & v748;
  v746[12] = v756;
  struct StateT * v750 = slot_12(v743);
  return v750;
}

struct StateT * slot_35(struct StateT * v1838) {
  int * v1839 = v1838->saved_regs;
  int v1840 = v1839[10];
  int * v1841 = v1838->regs;
  int v1842 = v1841[11];
  bool v1863 = (v1840 ^ -2147483648) < (v1842 ^ -2147483648);
  struct StateT * v1857;
  if (v1863) {
    struct StateT * v1843 = slot_27(v1838);
    v1857 = v1843;
  } else {
    int v1845 = v1838->timer;
    int v1866 = v1845 + 15;
    v1838->timer = v1866;
    int * v1847 = v1838->saved_regs;
    int v1848 = v1847[10];
    int * v1849 = v1838->regs;
    v1849[10] = v1848;
    int * v1851 = v1838->saved_regs;
    int v1852 = v1851[12];
    int * v1853 = v1838->regs;
    v1853[12] = v1852;
    struct StateT * v1855 = slot_18(v1838);
    v1857 = v1855;
  }
  return v1857;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
    s->saved_regs[i] = 0;
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
  
  // public data, where the section headers put it
  s1.mem[0] = 8;
  s2.mem[0] = 8;
  int x = bounded(0, 15);
  s1.regs[10] = x;
  s2.regs[10] = x;
  // probe, the attacker's: the same draw in both states
  for (int i=0; i<16; i++) {
    int v = bounded(0, 20);
    s1.mem[1 + i] = v;
    s2.mem[1 + i] = v;
  }
  // temp, the attacker's: the same draw in both states
  for (int i=0; i<1; i++) {
    int v = bounded(0, 20);
    s1.mem[17 + i] = v;
    s2.mem[17 + i] = v;
  }
  // publicarray, the attacker's: the same draw in both states
  for (int i=0; i<8; i++) {
    int v = bounded(0, 20);
    s1.mem[18 + i] = v;
    s2.mem[18 + i] = v;
  }
  
  // secretarray, secret: a different draw in each state
  for (int i=0; i<8; i++) {
    s1.mem[26 + i] = secret(0, 20);
    s2.mem[26 + i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}