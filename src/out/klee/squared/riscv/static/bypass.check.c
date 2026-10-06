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

struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_1(struct StateT2 * v42);
struct StateT2 * slot_6(struct StateT2 * v1210);
struct StateT2 * slot_5(struct StateT2 * v1171);
struct StateT2 * slot_4(struct StateT2 * v753);
struct StateT2 * slot_2(struct StateT2 * v81);
struct StateT2 * slot_3(struct StateT2 * v117);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  return v1;
}

struct StateT2 * slot_1(struct StateT2 * v42) {
  struct StateT * v43 = v42->a;
  int v44 = v43->timer;
  struct StateT * v45 = v42->b;
  int v46 = v45->timer;
  bool v67 = v44 == v46;
  squared_assert(v67);
  squared_assume(v67);
  struct StateT * v49 = v42->a;
  int v50 = v49->timer;
  int v69 = v50 + 1;
  v49->timer = v69;
  struct StateT * v52 = v42->b;
  int v53 = v52->timer;
  int v71 = v53 + 1;
  v52->timer = v71;
  struct StateT * v55 = v42->a;
  int * v56 = v55->regs;
  int v57 = v56[6];
  int v75 = v57 + 80;
  v56[6] = v75;
  struct StateT * v59 = v42->b;
  int * v60 = v59->regs;
  int v61 = v60[6];
  int v78 = v61 + 80;
  v60[6] = v78;
  struct StateT2 * v63 = slot_2(v42);
  return v63;
}

struct StateT2 * slot_6(struct StateT2 * v1210) {
  struct StateT * v1211 = v1210->a;
  int v1212 = v1211->timer;
  struct StateT * v1213 = v1210->b;
  int v1214 = v1213->timer;
  bool v1440 = v1212 == v1214;
  squared_assert(v1440);
  squared_assume(v1440);
  struct StateT * v1217 = v1210->a;
  int v1218 = v1217->timer;
  int v1442 = v1218 + 1;
  v1217->timer = v1442;
  struct StateT * v1220 = v1210->b;
  int v1221 = v1220->timer;
  int v1444 = v1221 + 1;
  v1220->timer = v1444;
  struct StateT * v1223 = v1210->a;
  int * v1224 = v1223->regs;
  int v1225 = v1224[11];
  int * v1226 = v1223->cache_tags;
  int v1449 = (((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1)) & 1) * 2;
  int v1227 = v1226[v1449];
  int v1450 = ((((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1228 = v1226[v1450];
  int v1451 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1)) & 3) * 2);
  int v1229 = v1226[v1451];
  int v1452 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1230 = v1226[v1452];
  int v1231 = v1223->timer;
  int v1453 = v1231 + ((100 ^ (((~(((v1229 ^ ((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1))) | (-(v1229 ^ ((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1))))) >> 31)) | (~(((v1230 ^ ((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1))) | (-(v1230 ^ ((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1227 ^ ((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1))) | (-(v1227 ^ ((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1))))) >> 31)) | (~(((v1228 ^ ((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1))) | (-(v1228 ^ ((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1229 ^ ((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1))) | (-(v1229 ^ ((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1))))) >> 31)) | (~(((v1230 ^ ((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1))) | (-(v1230 ^ ((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1223->timer = v1453;
  int * v1233 = v1223->cache_vals;
  bool v1454 = !(((~(((v1227 ^ ((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1))) | (-(v1227 ^ ((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1))))) >> 31)) | (~(((v1228 ^ ((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1))) | (-(v1228 ^ ((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1))))) >> 31))) == 0);
  int v1326;
  if (v1454) {
    int * v1234 = v1223->cache_age;
    int v1456 = ((((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1)) & 1) * 2) + ((~(((v1228 ^ ((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1))) | (-(v1228 ^ ((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1))))) >> 31)) & 1);
    int v1235 = v1234[v1456];
    int v1236 = v1234[v1449];
    int v1457 = v1236 + ((int)((unsigned int)(v1236 - v1235) >> 31));
    v1234[v1449] = v1457;
    int * v1238 = v1223->cache_age;
    int v1239 = v1238[v1450];
    int v1459 = v1239 + ((int)((unsigned int)(v1239 - v1235) >> 31));
    v1238[v1450] = v1459;
    int * v1241 = v1223->cache_age;
    v1241[v1456] = 0;
    v1326 = v1456;
  } else {
    int * v1244 = v1223->cache_age;
    int v1463 = (((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1)) & 1) * 2;
    int v1245 = v1244[v1463];
    int * v1246 = v1223->cache_tags;
    int v1247 = v1246[v1463];
    int v1248 = v1244[v1450];
    int v1249 = v1246[v1450];
    bool v1465 = !(((~(((v1229 ^ ((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1))) | (-(v1229 ^ ((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1))))) >> 31)) | (~(((v1230 ^ ((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1))) | (-(v1230 ^ ((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1))))) >> 31))) == 0);
    int v1303;
    if (v1465) {
      int * v1250 = v1223->cache_age;
      int v1467 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1230 ^ ((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1))) | (-(v1230 ^ ((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1))))) >> 31)) & 1);
      int v1251 = v1250[v1467];
      int v1252 = v1250[v1451];
      int v1468 = v1252 + ((int)((unsigned int)(v1252 - v1251) >> 31));
      v1250[v1451] = v1468;
      int * v1254 = v1223->cache_age;
      int v1255 = v1254[v1452];
      int v1470 = v1255 + ((int)((unsigned int)(v1255 - v1251) >> 31));
      v1254[v1452] = v1470;
      int * v1257 = v1223->cache_age;
      v1257[v1467] = 0;
      v1303 = v1467;
    } else {
      int * v1260 = v1223->cache_age;
      int v1474 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1)) & 3) * 2);
      int v1261 = v1260[v1474];
      int * v1262 = v1223->cache_tags;
      int v1263 = v1262[v1474];
      int v1264 = v1260[v1452];
      int v1265 = v1262[v1452];
      int * v1266 = v1223->cache_dirty;
      int v1477 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1)) & 3) * 2)) + ((((v1261 + ((~(((v1263 ^ -1) | (-(v1263 ^ -1))) >> 31)) & 2)) - (v1264 + ((~(((v1265 ^ -1) | (-(v1265 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1267 = v1266[v1477];
      bool v1478 = !(v1267 == 0);
      if (v1478) {
        int * v1268 = v1223->cache_tags;
        int v1269 = v1268[v1477];
        int * v1270 = v1223->cache_vals;
        int v1481 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1)) & 3) * 2)) + ((((v1261 + ((~(((v1263 ^ -1) | (-(v1263 ^ -1))) >> 31)) & 2)) - (v1264 + ((~(((v1265 ^ -1) | (-(v1265 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1271 = v1270[v1481];
        int v1482 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1)) & 3) * 2)) + ((((v1261 + ((~(((v1263 ^ -1) | (-(v1263 ^ -1))) >> 31)) & 2)) - (v1264 + ((~(((v1265 ^ -1) | (-(v1265 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1272 = v1270[v1482];
        int * v1273 = v1223->mem;
        int v1484 = v1269 * 2;
        v1273[v1484] = v1271;
        int * v1275 = v1223->mem;
        int v1487 = (v1269 * 2) + 1;
        v1275[v1487] = v1272;
        ;
      } else {
        ;
      }
      int * v1280 = v1223->mem;
      int v1492 = ((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1)) * 2;
      int v1281 = v1280[v1492];
      int v1493 = (((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1)) * 2) + 1;
      int v1282 = v1280[v1493];
      int * v1283 = v1223->cache_vals;
      int v1495 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1)) & 3) * 2)) + ((((v1261 + ((~(((v1263 ^ -1) | (-(v1263 ^ -1))) >> 31)) & 2)) - (v1264 + ((~(((v1265 ^ -1) | (-(v1265 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1283[v1495] = v1281;
      int * v1285 = v1223->cache_vals;
      int v1498 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1)) & 3) * 2)) + ((((v1261 + ((~(((v1263 ^ -1) | (-(v1263 ^ -1))) >> 31)) & 2)) - (v1264 + ((~(((v1265 ^ -1) | (-(v1265 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1285[v1498] = v1282;
      int * v1287 = v1223->cache_tags;
      int v1501 = (int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1);
      v1287[v1477] = v1501;
      int * v1289 = v1223->cache_dirty;
      v1289[v1477] = 0;
      int * v1291 = v1223->cache_age;
      v1291[v1477] = 1;
      int * v1293 = v1223->cache_age;
      int v1294 = v1293[v1477];
      int v1295 = v1293[v1451];
      int v1507 = v1295 + ((int)((unsigned int)(v1295 - v1294) >> 31));
      v1293[v1451] = v1507;
      int * v1297 = v1223->cache_age;
      int v1298 = v1297[v1452];
      int v1509 = v1298 + ((int)((unsigned int)(v1298 - v1294) >> 31));
      v1297[v1452] = v1509;
      int * v1300 = v1223->cache_age;
      v1300[v1477] = 0;
      v1303 = v1477;
    }
    int * v1304 = v1223->cache_vals;
    int v1512 = v1303 * 2;
    int v1305 = v1304[v1512];
    int v1513 = (v1303 * 2) + 1;
    int v1306 = v1304[v1513];
    int v1514 = (((((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1)) & 1) * 2) + ((((v1245 + ((~(((v1247 ^ -1) | (-(v1247 ^ -1))) >> 31)) & 2)) - (v1248 + ((~(((v1249 ^ -1) | (-(v1249 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1304[v1514] = v1305;
    int * v1308 = v1223->cache_vals;
    int v1517 = ((((((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1)) & 1) * 2) + ((((v1245 + ((~(((v1247 ^ -1) | (-(v1247 ^ -1))) >> 31)) & 2)) - (v1248 + ((~(((v1249 ^ -1) | (-(v1249 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1308[v1517] = v1306;
    int * v1310 = v1223->cache_tags;
    int v1520 = ((((int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1)) & 1) * 2) + ((((v1245 + ((~(((v1247 ^ -1) | (-(v1247 ^ -1))) >> 31)) & 2)) - (v1248 + ((~(((v1249 ^ -1) | (-(v1249 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1521 = (int)((unsigned int)((int)((unsigned int)v1225 >> 2)) >> 1);
    v1310[v1520] = v1521;
    int * v1312 = v1223->cache_dirty;
    v1312[v1520] = 0;
    int * v1314 = v1223->cache_age;
    v1314[v1520] = 1;
    int * v1316 = v1223->cache_age;
    int v1317 = v1316[v1520];
    int v1318 = v1316[v1449];
    int v1527 = v1318 + ((int)((unsigned int)(v1318 - v1317) >> 31));
    v1316[v1449] = v1527;
    int * v1320 = v1223->cache_age;
    int v1321 = v1320[v1450];
    int v1529 = v1321 + ((int)((unsigned int)(v1321 - v1317) >> 31));
    v1320[v1450] = v1529;
    int * v1323 = v1223->cache_age;
    v1323[v1520] = 0;
    v1326 = v1520;
  }
  int v1532 = (v1326 * 2) + (((int)((unsigned int)v1225 >> 2)) & 1);
  int v1327 = v1233[v1532];
  int * v1328 = v1223->regs;
  v1328[12] = v1327;
  struct StateT * v1330 = v1210->b;
  int * v1331 = v1330->regs;
  int v1332 = v1331[11];
  int * v1333 = v1330->cache_tags;
  int v1539 = (((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1)) & 1) * 2;
  int v1334 = v1333[v1539];
  int v1540 = ((((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1335 = v1333[v1540];
  int v1541 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1)) & 3) * 2);
  int v1336 = v1333[v1541];
  int v1542 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1337 = v1333[v1542];
  int v1338 = v1330->timer;
  int v1543 = v1338 + ((100 ^ (((~(((v1336 ^ ((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1))) | (-(v1336 ^ ((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1))))) >> 31)) | (~(((v1337 ^ ((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1))) | (-(v1337 ^ ((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1334 ^ ((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1))) | (-(v1334 ^ ((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1))))) >> 31)) | (~(((v1335 ^ ((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1))) | (-(v1335 ^ ((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1336 ^ ((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1))) | (-(v1336 ^ ((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1))))) >> 31)) | (~(((v1337 ^ ((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1))) | (-(v1337 ^ ((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1330->timer = v1543;
  int * v1340 = v1330->cache_vals;
  bool v1544 = !(((~(((v1334 ^ ((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1))) | (-(v1334 ^ ((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1))))) >> 31)) | (~(((v1335 ^ ((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1))) | (-(v1335 ^ ((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1))))) >> 31))) == 0);
  int v1433;
  if (v1544) {
    int * v1341 = v1330->cache_age;
    int v1546 = ((((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1)) & 1) * 2) + ((~(((v1335 ^ ((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1))) | (-(v1335 ^ ((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1))))) >> 31)) & 1);
    int v1342 = v1341[v1546];
    int v1343 = v1341[v1539];
    int v1547 = v1343 + ((int)((unsigned int)(v1343 - v1342) >> 31));
    v1341[v1539] = v1547;
    int * v1345 = v1330->cache_age;
    int v1346 = v1345[v1540];
    int v1549 = v1346 + ((int)((unsigned int)(v1346 - v1342) >> 31));
    v1345[v1540] = v1549;
    int * v1348 = v1330->cache_age;
    v1348[v1546] = 0;
    v1433 = v1546;
  } else {
    int * v1351 = v1330->cache_age;
    int v1553 = (((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1)) & 1) * 2;
    int v1352 = v1351[v1553];
    int * v1353 = v1330->cache_tags;
    int v1354 = v1353[v1553];
    int v1355 = v1351[v1540];
    int v1356 = v1353[v1540];
    bool v1555 = !(((~(((v1336 ^ ((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1))) | (-(v1336 ^ ((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1))))) >> 31)) | (~(((v1337 ^ ((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1))) | (-(v1337 ^ ((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1))))) >> 31))) == 0);
    int v1410;
    if (v1555) {
      int * v1357 = v1330->cache_age;
      int v1557 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1337 ^ ((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1))) | (-(v1337 ^ ((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1))))) >> 31)) & 1);
      int v1358 = v1357[v1557];
      int v1359 = v1357[v1541];
      int v1558 = v1359 + ((int)((unsigned int)(v1359 - v1358) >> 31));
      v1357[v1541] = v1558;
      int * v1361 = v1330->cache_age;
      int v1362 = v1361[v1542];
      int v1560 = v1362 + ((int)((unsigned int)(v1362 - v1358) >> 31));
      v1361[v1542] = v1560;
      int * v1364 = v1330->cache_age;
      v1364[v1557] = 0;
      v1410 = v1557;
    } else {
      int * v1367 = v1330->cache_age;
      int v1564 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1)) & 3) * 2);
      int v1368 = v1367[v1564];
      int * v1369 = v1330->cache_tags;
      int v1370 = v1369[v1564];
      int v1371 = v1367[v1542];
      int v1372 = v1369[v1542];
      int * v1373 = v1330->cache_dirty;
      int v1567 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1)) & 3) * 2)) + ((((v1368 + ((~(((v1370 ^ -1) | (-(v1370 ^ -1))) >> 31)) & 2)) - (v1371 + ((~(((v1372 ^ -1) | (-(v1372 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1374 = v1373[v1567];
      bool v1568 = !(v1374 == 0);
      if (v1568) {
        int * v1375 = v1330->cache_tags;
        int v1376 = v1375[v1567];
        int * v1377 = v1330->cache_vals;
        int v1571 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1)) & 3) * 2)) + ((((v1368 + ((~(((v1370 ^ -1) | (-(v1370 ^ -1))) >> 31)) & 2)) - (v1371 + ((~(((v1372 ^ -1) | (-(v1372 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1378 = v1377[v1571];
        int v1572 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1)) & 3) * 2)) + ((((v1368 + ((~(((v1370 ^ -1) | (-(v1370 ^ -1))) >> 31)) & 2)) - (v1371 + ((~(((v1372 ^ -1) | (-(v1372 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1379 = v1377[v1572];
        int * v1380 = v1330->mem;
        int v1574 = v1376 * 2;
        v1380[v1574] = v1378;
        int * v1382 = v1330->mem;
        int v1577 = (v1376 * 2) + 1;
        v1382[v1577] = v1379;
        ;
      } else {
        ;
      }
      int * v1387 = v1330->mem;
      int v1582 = ((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1)) * 2;
      int v1388 = v1387[v1582];
      int v1583 = (((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1)) * 2) + 1;
      int v1389 = v1387[v1583];
      int * v1390 = v1330->cache_vals;
      int v1585 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1)) & 3) * 2)) + ((((v1368 + ((~(((v1370 ^ -1) | (-(v1370 ^ -1))) >> 31)) & 2)) - (v1371 + ((~(((v1372 ^ -1) | (-(v1372 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1390[v1585] = v1388;
      int * v1392 = v1330->cache_vals;
      int v1588 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1)) & 3) * 2)) + ((((v1368 + ((~(((v1370 ^ -1) | (-(v1370 ^ -1))) >> 31)) & 2)) - (v1371 + ((~(((v1372 ^ -1) | (-(v1372 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1392[v1588] = v1389;
      int * v1394 = v1330->cache_tags;
      int v1591 = (int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1);
      v1394[v1567] = v1591;
      int * v1396 = v1330->cache_dirty;
      v1396[v1567] = 0;
      int * v1398 = v1330->cache_age;
      v1398[v1567] = 1;
      int * v1400 = v1330->cache_age;
      int v1401 = v1400[v1567];
      int v1402 = v1400[v1541];
      int v1597 = v1402 + ((int)((unsigned int)(v1402 - v1401) >> 31));
      v1400[v1541] = v1597;
      int * v1404 = v1330->cache_age;
      int v1405 = v1404[v1542];
      int v1599 = v1405 + ((int)((unsigned int)(v1405 - v1401) >> 31));
      v1404[v1542] = v1599;
      int * v1407 = v1330->cache_age;
      v1407[v1567] = 0;
      v1410 = v1567;
    }
    int * v1411 = v1330->cache_vals;
    int v1602 = v1410 * 2;
    int v1412 = v1411[v1602];
    int v1603 = (v1410 * 2) + 1;
    int v1413 = v1411[v1603];
    int v1604 = (((((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1)) & 1) * 2) + ((((v1352 + ((~(((v1354 ^ -1) | (-(v1354 ^ -1))) >> 31)) & 2)) - (v1355 + ((~(((v1356 ^ -1) | (-(v1356 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1411[v1604] = v1412;
    int * v1415 = v1330->cache_vals;
    int v1607 = ((((((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1)) & 1) * 2) + ((((v1352 + ((~(((v1354 ^ -1) | (-(v1354 ^ -1))) >> 31)) & 2)) - (v1355 + ((~(((v1356 ^ -1) | (-(v1356 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1415[v1607] = v1413;
    int * v1417 = v1330->cache_tags;
    int v1610 = ((((int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1)) & 1) * 2) + ((((v1352 + ((~(((v1354 ^ -1) | (-(v1354 ^ -1))) >> 31)) & 2)) - (v1355 + ((~(((v1356 ^ -1) | (-(v1356 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1611 = (int)((unsigned int)((int)((unsigned int)v1332 >> 2)) >> 1);
    v1417[v1610] = v1611;
    int * v1419 = v1330->cache_dirty;
    v1419[v1610] = 0;
    int * v1421 = v1330->cache_age;
    v1421[v1610] = 1;
    int * v1423 = v1330->cache_age;
    int v1424 = v1423[v1610];
    int v1425 = v1423[v1539];
    int v1617 = v1425 + ((int)((unsigned int)(v1425 - v1424) >> 31));
    v1423[v1539] = v1617;
    int * v1427 = v1330->cache_age;
    int v1428 = v1427[v1540];
    int v1619 = v1428 + ((int)((unsigned int)(v1428 - v1424) >> 31));
    v1427[v1540] = v1619;
    int * v1430 = v1330->cache_age;
    v1430[v1610] = 0;
    v1433 = v1610;
  }
  int v1622 = (v1433 * 2) + (((int)((unsigned int)v1332 >> 2)) & 1);
  int v1434 = v1340[v1622];
  int * v1435 = v1330->regs;
  v1435[12] = v1434;
  return v1210;
}

struct StateT2 * slot_5(struct StateT2 * v1171) {
  struct StateT * v1172 = v1171->a;
  int v1173 = v1172->timer;
  struct StateT * v1174 = v1171->b;
  int v1175 = v1174->timer;
  bool v1196 = v1173 == v1175;
  squared_assert(v1196);
  squared_assume(v1196);
  struct StateT * v1178 = v1171->a;
  int v1179 = v1178->timer;
  int v1198 = v1179 + 1;
  v1178->timer = v1198;
  struct StateT * v1181 = v1171->b;
  int v1182 = v1181->timer;
  int v1200 = v1182 + 1;
  v1181->timer = v1200;
  struct StateT * v1184 = v1171->a;
  int * v1185 = v1184->regs;
  int v1186 = v1185[11];
  int v1204 = v1186 << 2;
  v1185[11] = v1204;
  struct StateT * v1188 = v1171->b;
  int * v1189 = v1188->regs;
  int v1190 = v1189[11];
  int v1207 = v1190 << 2;
  v1189[11] = v1207;
  struct StateT2 * v1192 = slot_6(v1171);
  return v1192;
}

struct StateT2 * slot_4(struct StateT2 * v753) {
  struct StateT * v754 = v753->a;
  int v755 = v754->timer;
  struct StateT * v756 = v753->b;
  int v757 = v756->timer;
  bool v984 = v755 == v757;
  squared_assert(v984);
  squared_assume(v984);
  struct StateT * v760 = v753->a;
  int v761 = v760->timer;
  int v986 = v761 + 1;
  v760->timer = v986;
  struct StateT * v763 = v753->b;
  int v764 = v763->timer;
  int v988 = v764 + 1;
  v763->timer = v988;
  struct StateT * v766 = v753->a;
  int * v767 = v766->regs;
  int v768 = v767[6];
  int * v769 = v766->cache_tags;
  int v993 = (((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1)) & 1) * 2;
  int v770 = v769[v993];
  int v994 = ((((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1)) & 1) * 2) + 1;
  int v771 = v769[v994];
  int v995 = 4 + ((((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1)) & 3) * 2);
  int v772 = v769[v995];
  int v996 = (4 + ((((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v773 = v769[v996];
  int v774 = v766->timer;
  int v997 = v774 + ((100 ^ (((~(((v772 ^ ((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1))) | (-(v772 ^ ((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1))))) >> 31)) | (~(((v773 ^ ((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1))) | (-(v773 ^ ((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v770 ^ ((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1))) | (-(v770 ^ ((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1))))) >> 31)) | (~(((v771 ^ ((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1))) | (-(v771 ^ ((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v772 ^ ((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1))) | (-(v772 ^ ((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1))))) >> 31)) | (~(((v773 ^ ((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1))) | (-(v773 ^ ((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1))))) >> 31))) & 104)))));
  v766->timer = v997;
  int * v776 = v766->cache_vals;
  bool v998 = !(((~(((v770 ^ ((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1))) | (-(v770 ^ ((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1))))) >> 31)) | (~(((v771 ^ ((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1))) | (-(v771 ^ ((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1))))) >> 31))) == 0);
  int v869;
  if (v998) {
    int * v777 = v766->cache_age;
    int v1000 = ((((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1)) & 1) * 2) + ((~(((v771 ^ ((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1))) | (-(v771 ^ ((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1))))) >> 31)) & 1);
    int v778 = v777[v1000];
    int v779 = v777[v993];
    int v1001 = v779 + ((int)((unsigned int)(v779 - v778) >> 31));
    v777[v993] = v1001;
    int * v781 = v766->cache_age;
    int v782 = v781[v994];
    int v1003 = v782 + ((int)((unsigned int)(v782 - v778) >> 31));
    v781[v994] = v1003;
    int * v784 = v766->cache_age;
    v784[v1000] = 0;
    v869 = v1000;
  } else {
    int * v787 = v766->cache_age;
    int v1007 = (((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1)) & 1) * 2;
    int v788 = v787[v1007];
    int * v789 = v766->cache_tags;
    int v790 = v789[v1007];
    int v791 = v787[v994];
    int v792 = v789[v994];
    bool v1009 = !(((~(((v772 ^ ((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1))) | (-(v772 ^ ((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1))))) >> 31)) | (~(((v773 ^ ((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1))) | (-(v773 ^ ((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1))))) >> 31))) == 0);
    int v846;
    if (v1009) {
      int * v793 = v766->cache_age;
      int v1011 = (4 + ((((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1)) & 3) * 2)) + ((~(((v773 ^ ((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1))) | (-(v773 ^ ((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1))))) >> 31)) & 1);
      int v794 = v793[v1011];
      int v795 = v793[v995];
      int v1012 = v795 + ((int)((unsigned int)(v795 - v794) >> 31));
      v793[v995] = v1012;
      int * v797 = v766->cache_age;
      int v798 = v797[v996];
      int v1014 = v798 + ((int)((unsigned int)(v798 - v794) >> 31));
      v797[v996] = v1014;
      int * v800 = v766->cache_age;
      v800[v1011] = 0;
      v846 = v1011;
    } else {
      int * v803 = v766->cache_age;
      int v1018 = 4 + ((((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1)) & 3) * 2);
      int v804 = v803[v1018];
      int * v805 = v766->cache_tags;
      int v806 = v805[v1018];
      int v807 = v803[v996];
      int v808 = v805[v996];
      int * v809 = v766->cache_dirty;
      int v1021 = (4 + ((((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1)) & 3) * 2)) + ((((v804 + ((~(((v806 ^ -1) | (-(v806 ^ -1))) >> 31)) & 2)) - (v807 + ((~(((v808 ^ -1) | (-(v808 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v810 = v809[v1021];
      bool v1022 = !(v810 == 0);
      if (v1022) {
        int * v811 = v766->cache_tags;
        int v812 = v811[v1021];
        int * v813 = v766->cache_vals;
        int v1025 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1)) & 3) * 2)) + ((((v804 + ((~(((v806 ^ -1) | (-(v806 ^ -1))) >> 31)) & 2)) - (v807 + ((~(((v808 ^ -1) | (-(v808 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v814 = v813[v1025];
        int v1026 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1)) & 3) * 2)) + ((((v804 + ((~(((v806 ^ -1) | (-(v806 ^ -1))) >> 31)) & 2)) - (v807 + ((~(((v808 ^ -1) | (-(v808 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v815 = v813[v1026];
        int * v816 = v766->mem;
        int v1028 = v812 * 2;
        v816[v1028] = v814;
        int * v818 = v766->mem;
        int v1031 = (v812 * 2) + 1;
        v818[v1031] = v815;
        ;
      } else {
        ;
      }
      int * v823 = v766->mem;
      int v1036 = ((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1)) * 2;
      int v824 = v823[v1036];
      int v1037 = (((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1)) * 2) + 1;
      int v825 = v823[v1037];
      int * v826 = v766->cache_vals;
      int v1039 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1)) & 3) * 2)) + ((((v804 + ((~(((v806 ^ -1) | (-(v806 ^ -1))) >> 31)) & 2)) - (v807 + ((~(((v808 ^ -1) | (-(v808 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v826[v1039] = v824;
      int * v828 = v766->cache_vals;
      int v1042 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1)) & 3) * 2)) + ((((v804 + ((~(((v806 ^ -1) | (-(v806 ^ -1))) >> 31)) & 2)) - (v807 + ((~(((v808 ^ -1) | (-(v808 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v828[v1042] = v825;
      int * v830 = v766->cache_tags;
      int v1045 = (int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1);
      v830[v1021] = v1045;
      int * v832 = v766->cache_dirty;
      v832[v1021] = 0;
      int * v834 = v766->cache_age;
      v834[v1021] = 1;
      int * v836 = v766->cache_age;
      int v837 = v836[v1021];
      int v838 = v836[v995];
      int v1051 = v838 + ((int)((unsigned int)(v838 - v837) >> 31));
      v836[v995] = v1051;
      int * v840 = v766->cache_age;
      int v841 = v840[v996];
      int v1053 = v841 + ((int)((unsigned int)(v841 - v837) >> 31));
      v840[v996] = v1053;
      int * v843 = v766->cache_age;
      v843[v1021] = 0;
      v846 = v1021;
    }
    int * v847 = v766->cache_vals;
    int v1056 = v846 * 2;
    int v848 = v847[v1056];
    int v1057 = (v846 * 2) + 1;
    int v849 = v847[v1057];
    int v1058 = (((((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1)) & 1) * 2) + ((((v788 + ((~(((v790 ^ -1) | (-(v790 ^ -1))) >> 31)) & 2)) - (v791 + ((~(((v792 ^ -1) | (-(v792 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v847[v1058] = v848;
    int * v851 = v766->cache_vals;
    int v1061 = ((((((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1)) & 1) * 2) + ((((v788 + ((~(((v790 ^ -1) | (-(v790 ^ -1))) >> 31)) & 2)) - (v791 + ((~(((v792 ^ -1) | (-(v792 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v851[v1061] = v849;
    int * v853 = v766->cache_tags;
    int v1064 = ((((int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1)) & 1) * 2) + ((((v788 + ((~(((v790 ^ -1) | (-(v790 ^ -1))) >> 31)) & 2)) - (v791 + ((~(((v792 ^ -1) | (-(v792 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1065 = (int)((unsigned int)((int)((unsigned int)v768 >> 2)) >> 1);
    v853[v1064] = v1065;
    int * v855 = v766->cache_dirty;
    v855[v1064] = 0;
    int * v857 = v766->cache_age;
    v857[v1064] = 1;
    int * v859 = v766->cache_age;
    int v860 = v859[v1064];
    int v861 = v859[v993];
    int v1071 = v861 + ((int)((unsigned int)(v861 - v860) >> 31));
    v859[v993] = v1071;
    int * v863 = v766->cache_age;
    int v864 = v863[v994];
    int v1073 = v864 + ((int)((unsigned int)(v864 - v860) >> 31));
    v863[v994] = v1073;
    int * v866 = v766->cache_age;
    v866[v1064] = 0;
    v869 = v1064;
  }
  int v1076 = (v869 * 2) + (((int)((unsigned int)v768 >> 2)) & 1);
  int v870 = v776[v1076];
  int * v871 = v766->regs;
  v871[11] = v870;
  struct StateT * v873 = v753->b;
  int * v874 = v873->regs;
  int v875 = v874[6];
  int * v876 = v873->cache_tags;
  int v1083 = (((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1)) & 1) * 2;
  int v877 = v876[v1083];
  int v1084 = ((((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1)) & 1) * 2) + 1;
  int v878 = v876[v1084];
  int v1085 = 4 + ((((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1)) & 3) * 2);
  int v879 = v876[v1085];
  int v1086 = (4 + ((((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v880 = v876[v1086];
  int v881 = v873->timer;
  int v1087 = v881 + ((100 ^ (((~(((v879 ^ ((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1))) | (-(v879 ^ ((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1))))) >> 31)) | (~(((v880 ^ ((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1))) | (-(v880 ^ ((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v877 ^ ((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1))) | (-(v877 ^ ((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1))))) >> 31)) | (~(((v878 ^ ((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1))) | (-(v878 ^ ((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v879 ^ ((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1))) | (-(v879 ^ ((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1))))) >> 31)) | (~(((v880 ^ ((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1))) | (-(v880 ^ ((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1))))) >> 31))) & 104)))));
  v873->timer = v1087;
  int * v883 = v873->cache_vals;
  bool v1088 = !(((~(((v877 ^ ((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1))) | (-(v877 ^ ((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1))))) >> 31)) | (~(((v878 ^ ((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1))) | (-(v878 ^ ((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1))))) >> 31))) == 0);
  int v976;
  if (v1088) {
    int * v884 = v873->cache_age;
    int v1090 = ((((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1)) & 1) * 2) + ((~(((v878 ^ ((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1))) | (-(v878 ^ ((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1))))) >> 31)) & 1);
    int v885 = v884[v1090];
    int v886 = v884[v1083];
    int v1091 = v886 + ((int)((unsigned int)(v886 - v885) >> 31));
    v884[v1083] = v1091;
    int * v888 = v873->cache_age;
    int v889 = v888[v1084];
    int v1093 = v889 + ((int)((unsigned int)(v889 - v885) >> 31));
    v888[v1084] = v1093;
    int * v891 = v873->cache_age;
    v891[v1090] = 0;
    v976 = v1090;
  } else {
    int * v894 = v873->cache_age;
    int v1097 = (((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1)) & 1) * 2;
    int v895 = v894[v1097];
    int * v896 = v873->cache_tags;
    int v897 = v896[v1097];
    int v898 = v894[v1084];
    int v899 = v896[v1084];
    bool v1099 = !(((~(((v879 ^ ((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1))) | (-(v879 ^ ((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1))))) >> 31)) | (~(((v880 ^ ((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1))) | (-(v880 ^ ((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1))))) >> 31))) == 0);
    int v953;
    if (v1099) {
      int * v900 = v873->cache_age;
      int v1101 = (4 + ((((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1)) & 3) * 2)) + ((~(((v880 ^ ((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1))) | (-(v880 ^ ((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1))))) >> 31)) & 1);
      int v901 = v900[v1101];
      int v902 = v900[v1085];
      int v1102 = v902 + ((int)((unsigned int)(v902 - v901) >> 31));
      v900[v1085] = v1102;
      int * v904 = v873->cache_age;
      int v905 = v904[v1086];
      int v1104 = v905 + ((int)((unsigned int)(v905 - v901) >> 31));
      v904[v1086] = v1104;
      int * v907 = v873->cache_age;
      v907[v1101] = 0;
      v953 = v1101;
    } else {
      int * v910 = v873->cache_age;
      int v1108 = 4 + ((((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1)) & 3) * 2);
      int v911 = v910[v1108];
      int * v912 = v873->cache_tags;
      int v913 = v912[v1108];
      int v914 = v910[v1086];
      int v915 = v912[v1086];
      int * v916 = v873->cache_dirty;
      int v1111 = (4 + ((((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1)) & 3) * 2)) + ((((v911 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2)) - (v914 + ((~(((v915 ^ -1) | (-(v915 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v917 = v916[v1111];
      bool v1112 = !(v917 == 0);
      if (v1112) {
        int * v918 = v873->cache_tags;
        int v919 = v918[v1111];
        int * v920 = v873->cache_vals;
        int v1115 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1)) & 3) * 2)) + ((((v911 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2)) - (v914 + ((~(((v915 ^ -1) | (-(v915 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v921 = v920[v1115];
        int v1116 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1)) & 3) * 2)) + ((((v911 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2)) - (v914 + ((~(((v915 ^ -1) | (-(v915 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v922 = v920[v1116];
        int * v923 = v873->mem;
        int v1118 = v919 * 2;
        v923[v1118] = v921;
        int * v925 = v873->mem;
        int v1121 = (v919 * 2) + 1;
        v925[v1121] = v922;
        ;
      } else {
        ;
      }
      int * v930 = v873->mem;
      int v1126 = ((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1)) * 2;
      int v931 = v930[v1126];
      int v1127 = (((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1)) * 2) + 1;
      int v932 = v930[v1127];
      int * v933 = v873->cache_vals;
      int v1129 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1)) & 3) * 2)) + ((((v911 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2)) - (v914 + ((~(((v915 ^ -1) | (-(v915 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v933[v1129] = v931;
      int * v935 = v873->cache_vals;
      int v1132 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1)) & 3) * 2)) + ((((v911 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2)) - (v914 + ((~(((v915 ^ -1) | (-(v915 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v935[v1132] = v932;
      int * v937 = v873->cache_tags;
      int v1135 = (int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1);
      v937[v1111] = v1135;
      int * v939 = v873->cache_dirty;
      v939[v1111] = 0;
      int * v941 = v873->cache_age;
      v941[v1111] = 1;
      int * v943 = v873->cache_age;
      int v944 = v943[v1111];
      int v945 = v943[v1085];
      int v1141 = v945 + ((int)((unsigned int)(v945 - v944) >> 31));
      v943[v1085] = v1141;
      int * v947 = v873->cache_age;
      int v948 = v947[v1086];
      int v1143 = v948 + ((int)((unsigned int)(v948 - v944) >> 31));
      v947[v1086] = v1143;
      int * v950 = v873->cache_age;
      v950[v1111] = 0;
      v953 = v1111;
    }
    int * v954 = v873->cache_vals;
    int v1146 = v953 * 2;
    int v955 = v954[v1146];
    int v1147 = (v953 * 2) + 1;
    int v956 = v954[v1147];
    int v1148 = (((((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1)) & 1) * 2) + ((((v895 + ((~(((v897 ^ -1) | (-(v897 ^ -1))) >> 31)) & 2)) - (v898 + ((~(((v899 ^ -1) | (-(v899 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v954[v1148] = v955;
    int * v958 = v873->cache_vals;
    int v1151 = ((((((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1)) & 1) * 2) + ((((v895 + ((~(((v897 ^ -1) | (-(v897 ^ -1))) >> 31)) & 2)) - (v898 + ((~(((v899 ^ -1) | (-(v899 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v958[v1151] = v956;
    int * v960 = v873->cache_tags;
    int v1154 = ((((int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1)) & 1) * 2) + ((((v895 + ((~(((v897 ^ -1) | (-(v897 ^ -1))) >> 31)) & 2)) - (v898 + ((~(((v899 ^ -1) | (-(v899 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1155 = (int)((unsigned int)((int)((unsigned int)v875 >> 2)) >> 1);
    v960[v1154] = v1155;
    int * v962 = v873->cache_dirty;
    v962[v1154] = 0;
    int * v964 = v873->cache_age;
    v964[v1154] = 1;
    int * v966 = v873->cache_age;
    int v967 = v966[v1154];
    int v968 = v966[v1083];
    int v1161 = v968 + ((int)((unsigned int)(v968 - v967) >> 31));
    v966[v1083] = v1161;
    int * v970 = v873->cache_age;
    int v971 = v970[v1084];
    int v1163 = v971 + ((int)((unsigned int)(v971 - v967) >> 31));
    v970[v1084] = v1163;
    int * v973 = v873->cache_age;
    v973[v1154] = 0;
    v976 = v1154;
  }
  int v1166 = (v976 * 2) + (((int)((unsigned int)v875 >> 2)) & 1);
  int v977 = v883[v1166];
  int * v978 = v873->regs;
  v978[11] = v977;
  struct StateT2 * v980 = slot_5(v753);
  return v980;
}

struct StateT2 * slot_2(struct StateT2 * v81) {
  struct StateT * v82 = v81->a;
  int v83 = v82->timer;
  struct StateT * v84 = v81->b;
  int v85 = v84->timer;
  bool v104 = v83 == v85;
  squared_assert(v104);
  squared_assume(v104);
  struct StateT * v88 = v81->a;
  int v89 = v88->timer;
  int v106 = v89 + 1;
  v88->timer = v106;
  struct StateT * v91 = v81->b;
  int v92 = v91->timer;
  int v108 = v92 + 1;
  v91->timer = v108;
  struct StateT * v94 = v81->a;
  int * v95 = v94->regs;
  v95[7] = 0;
  struct StateT * v97 = v81->b;
  int * v98 = v97->regs;
  v98[7] = 0;
  struct StateT2 * v100 = slot_3(v81);
  return v100;
}

struct StateT2 * slot_3(struct StateT2 * v117) {
  struct StateT * v118 = v117->a;
  int v119 = v118->timer;
  struct StateT * v120 = v117->b;
  int v121 = v120->timer;
  bool v468 = v119 == v121;
  squared_assert(v468);
  squared_assume(v468);
  struct StateT * v124 = v117->a;
  int v125 = v124->timer;
  int v470 = v125 + 1;
  v124->timer = v470;
  struct StateT * v127 = v117->b;
  int v128 = v127->timer;
  int v472 = v128 + 1;
  v127->timer = v472;
  struct StateT * v130 = v117->a;
  int * v131 = v130->regs;
  int v132 = v131[6];
  int v133 = v131[7];
  int * v134 = v130->cache_tags;
  int v478 = (((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 1) * 2;
  int v135 = v134[v478];
  int v479 = ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 1) * 2) + 1;
  int v136 = v134[v479];
  int v480 = 4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2);
  int v137 = v134[v480];
  int v481 = (4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v138 = v134[v481];
  int v139 = v130->timer;
  int v482 = v139 + ((100 ^ (((~(((v137 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v137 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31)) | (~(((v138 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v138 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v135 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v135 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31)) | (~(((v136 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v136 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v137 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v137 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31)) | (~(((v138 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v138 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31))) & 104)))));
  v130->timer = v482;
  bool v483 = !(((~(((v135 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v135 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31)) | (~(((v136 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v136 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31))) == 0);
  int v233;
  if (v483) {
    int * v141 = v130->cache_age;
    int v485 = ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 1) * 2) + ((~(((v136 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v136 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31)) & 1);
    int v142 = v141[v485];
    int v143 = v141[v478];
    int v486 = v143 + ((int)((unsigned int)(v143 - v142) >> 31));
    v141[v478] = v486;
    int * v145 = v130->cache_age;
    int v146 = v145[v479];
    int v488 = v146 + ((int)((unsigned int)(v146 - v142) >> 31));
    v145[v479] = v488;
    int * v148 = v130->cache_age;
    v148[v485] = 0;
    v233 = v485;
  } else {
    int * v151 = v130->cache_age;
    int v492 = (((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 1) * 2;
    int v152 = v151[v492];
    int * v153 = v130->cache_tags;
    int v154 = v153[v492];
    int v155 = v151[v479];
    int v156 = v153[v479];
    bool v494 = !(((~(((v137 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v137 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31)) | (~(((v138 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v138 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31))) == 0);
    int v210;
    if (v494) {
      int * v157 = v130->cache_age;
      int v496 = (4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2)) + ((~(((v138 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v138 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31)) & 1);
      int v158 = v157[v496];
      int v159 = v157[v480];
      int v497 = v159 + ((int)((unsigned int)(v159 - v158) >> 31));
      v157[v480] = v497;
      int * v161 = v130->cache_age;
      int v162 = v161[v481];
      int v499 = v162 + ((int)((unsigned int)(v162 - v158) >> 31));
      v161[v481] = v499;
      int * v164 = v130->cache_age;
      v164[v496] = 0;
      v210 = v496;
    } else {
      int * v167 = v130->cache_age;
      int v503 = 4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2);
      int v168 = v167[v503];
      int * v169 = v130->cache_tags;
      int v170 = v169[v503];
      int v171 = v167[v481];
      int v172 = v169[v481];
      int * v173 = v130->cache_dirty;
      int v506 = (4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2)) + ((((v168 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2)) - (v171 + ((~(((v172 ^ -1) | (-(v172 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v174 = v173[v506];
      bool v507 = !(v174 == 0);
      if (v507) {
        int * v175 = v130->cache_tags;
        int v176 = v175[v506];
        int * v177 = v130->cache_vals;
        int v510 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2)) + ((((v168 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2)) - (v171 + ((~(((v172 ^ -1) | (-(v172 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v178 = v177[v510];
        int v511 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2)) + ((((v168 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2)) - (v171 + ((~(((v172 ^ -1) | (-(v172 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v179 = v177[v511];
        int * v180 = v130->mem;
        int v513 = v176 * 2;
        v180[v513] = v178;
        int * v182 = v130->mem;
        int v516 = (v176 * 2) + 1;
        v182[v516] = v179;
        ;
      } else {
        ;
      }
      int * v187 = v130->mem;
      int v521 = ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) * 2;
      int v188 = v187[v521];
      int v522 = (((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) * 2) + 1;
      int v189 = v187[v522];
      int * v190 = v130->cache_vals;
      int v524 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2)) + ((((v168 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2)) - (v171 + ((~(((v172 ^ -1) | (-(v172 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v190[v524] = v188;
      int * v192 = v130->cache_vals;
      int v527 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2)) + ((((v168 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2)) - (v171 + ((~(((v172 ^ -1) | (-(v172 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v192[v527] = v189;
      int * v194 = v130->cache_tags;
      int v530 = (int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1);
      v194[v506] = v530;
      int * v196 = v130->cache_dirty;
      v196[v506] = 0;
      int * v198 = v130->cache_age;
      v198[v506] = 1;
      int * v200 = v130->cache_age;
      int v201 = v200[v506];
      int v202 = v200[v480];
      int v536 = v202 + ((int)((unsigned int)(v202 - v201) >> 31));
      v200[v480] = v536;
      int * v204 = v130->cache_age;
      int v205 = v204[v481];
      int v538 = v205 + ((int)((unsigned int)(v205 - v201) >> 31));
      v204[v481] = v538;
      int * v207 = v130->cache_age;
      v207[v506] = 0;
      v210 = v506;
    }
    int * v211 = v130->cache_vals;
    int v541 = v210 * 2;
    int v212 = v211[v541];
    int v542 = (v210 * 2) + 1;
    int v213 = v211[v542];
    int v543 = (((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 1) * 2) + ((((v152 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2)) - (v155 + ((~(((v156 ^ -1) | (-(v156 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v211[v543] = v212;
    int * v215 = v130->cache_vals;
    int v546 = ((((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 1) * 2) + ((((v152 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2)) - (v155 + ((~(((v156 ^ -1) | (-(v156 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v215[v546] = v213;
    int * v217 = v130->cache_tags;
    int v549 = ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 1) * 2) + ((((v152 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2)) - (v155 + ((~(((v156 ^ -1) | (-(v156 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v550 = (int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1);
    v217[v549] = v550;
    int * v219 = v130->cache_dirty;
    v219[v549] = 0;
    int * v221 = v130->cache_age;
    v221[v549] = 1;
    int * v223 = v130->cache_age;
    int v224 = v223[v549];
    int v225 = v223[v478];
    int v556 = v225 + ((int)((unsigned int)(v225 - v224) >> 31));
    v223[v478] = v556;
    int * v227 = v130->cache_age;
    int v228 = v227[v479];
    int v558 = v228 + ((int)((unsigned int)(v228 - v224) >> 31));
    v227[v479] = v558;
    int * v230 = v130->cache_age;
    v230[v549] = 0;
    v233 = v549;
  }
  int * v234 = v130->cache_vals;
  int v561 = (v233 * 2) + (((int)((unsigned int)v132 >> 2)) & 1);
  v234[v561] = v133;
  int * v236 = v130->cache_tags;
  int v237 = v236[v480];
  int v238 = v236[v481];
  bool v564 = !(((~(((v237 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v237 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31)) | (~(((v238 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v238 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31))) == 0);
  int v292;
  if (v564) {
    int * v239 = v130->cache_age;
    int v566 = (4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2)) + ((~(((v238 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))) | (-(v238 ^ ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1))))) >> 31)) & 1);
    int v240 = v239[v566];
    int v241 = v239[v480];
    int v567 = v241 + ((int)((unsigned int)(v241 - v240) >> 31));
    v239[v480] = v567;
    int * v243 = v130->cache_age;
    int v244 = v243[v481];
    int v569 = v244 + ((int)((unsigned int)(v244 - v240) >> 31));
    v243[v481] = v569;
    int * v246 = v130->cache_age;
    v246[v566] = 0;
    v292 = v566;
  } else {
    int * v249 = v130->cache_age;
    int v573 = 4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2);
    int v250 = v249[v573];
    int * v251 = v130->cache_tags;
    int v252 = v251[v573];
    int v253 = v249[v481];
    int v254 = v251[v481];
    int * v255 = v130->cache_dirty;
    int v576 = (4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2)) + ((((v250 + ((~(((v252 ^ -1) | (-(v252 ^ -1))) >> 31)) & 2)) - (v253 + ((~(((v254 ^ -1) | (-(v254 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v256 = v255[v576];
    bool v577 = !(v256 == 0);
    if (v577) {
      int * v257 = v130->cache_tags;
      int v258 = v257[v576];
      int * v259 = v130->cache_vals;
      int v580 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2)) + ((((v250 + ((~(((v252 ^ -1) | (-(v252 ^ -1))) >> 31)) & 2)) - (v253 + ((~(((v254 ^ -1) | (-(v254 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v260 = v259[v580];
      int v581 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2)) + ((((v250 + ((~(((v252 ^ -1) | (-(v252 ^ -1))) >> 31)) & 2)) - (v253 + ((~(((v254 ^ -1) | (-(v254 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v261 = v259[v581];
      int * v262 = v130->mem;
      int v583 = v258 * 2;
      v262[v583] = v260;
      int * v264 = v130->mem;
      int v586 = (v258 * 2) + 1;
      v264[v586] = v261;
      ;
    } else {
      ;
    }
    int * v269 = v130->mem;
    int v591 = ((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) * 2;
    int v270 = v269[v591];
    int v592 = (((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) * 2) + 1;
    int v271 = v269[v592];
    int * v272 = v130->cache_vals;
    int v594 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2)) + ((((v250 + ((~(((v252 ^ -1) | (-(v252 ^ -1))) >> 31)) & 2)) - (v253 + ((~(((v254 ^ -1) | (-(v254 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v272[v594] = v270;
    int * v274 = v130->cache_vals;
    int v597 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1)) & 3) * 2)) + ((((v250 + ((~(((v252 ^ -1) | (-(v252 ^ -1))) >> 31)) & 2)) - (v253 + ((~(((v254 ^ -1) | (-(v254 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v274[v597] = v271;
    int * v276 = v130->cache_tags;
    int v600 = (int)((unsigned int)((int)((unsigned int)v132 >> 2)) >> 1);
    v276[v576] = v600;
    int * v278 = v130->cache_dirty;
    v278[v576] = 0;
    int * v280 = v130->cache_age;
    v280[v576] = 1;
    int * v282 = v130->cache_age;
    int v283 = v282[v576];
    int v284 = v282[v480];
    int v606 = v284 + ((int)((unsigned int)(v284 - v283) >> 31));
    v282[v480] = v606;
    int * v286 = v130->cache_age;
    int v287 = v286[v481];
    int v608 = v287 + ((int)((unsigned int)(v287 - v283) >> 31));
    v286[v481] = v608;
    int * v289 = v130->cache_age;
    v289[v576] = 0;
    v292 = v576;
  }
  int * v293 = v130->cache_vals;
  int v611 = (v292 * 2) + (((int)((unsigned int)v132 >> 2)) & 1);
  v293[v611] = v133;
  int * v295 = v130->cache_dirty;
  v295[v292] = 1;
  struct StateT * v297 = v117->b;
  int * v298 = v297->regs;
  int v299 = v298[6];
  int v300 = v298[7];
  int * v301 = v297->cache_tags;
  int v618 = (((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 1) * 2;
  int v302 = v301[v618];
  int v619 = ((((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 1) * 2) + 1;
  int v303 = v301[v619];
  int v620 = 4 + ((((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 3) * 2);
  int v304 = v301[v620];
  int v621 = (4 + ((((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v305 = v301[v621];
  int v306 = v297->timer;
  int v622 = v306 + ((100 ^ (((~(((v304 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))) | (-(v304 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))))) >> 31)) | (~(((v305 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))) | (-(v305 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v302 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))) | (-(v302 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))))) >> 31)) | (~(((v303 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))) | (-(v303 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v304 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))) | (-(v304 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))))) >> 31)) | (~(((v305 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))) | (-(v305 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))))) >> 31))) & 104)))));
  v297->timer = v622;
  bool v623 = !(((~(((v302 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))) | (-(v302 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))))) >> 31)) | (~(((v303 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))) | (-(v303 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))))) >> 31))) == 0);
  int v400;
  if (v623) {
    int * v308 = v297->cache_age;
    int v625 = ((((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 1) * 2) + ((~(((v303 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))) | (-(v303 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))))) >> 31)) & 1);
    int v309 = v308[v625];
    int v310 = v308[v618];
    int v626 = v310 + ((int)((unsigned int)(v310 - v309) >> 31));
    v308[v618] = v626;
    int * v312 = v297->cache_age;
    int v313 = v312[v619];
    int v628 = v313 + ((int)((unsigned int)(v313 - v309) >> 31));
    v312[v619] = v628;
    int * v315 = v297->cache_age;
    v315[v625] = 0;
    v400 = v625;
  } else {
    int * v318 = v297->cache_age;
    int v632 = (((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 1) * 2;
    int v319 = v318[v632];
    int * v320 = v297->cache_tags;
    int v321 = v320[v632];
    int v322 = v318[v619];
    int v323 = v320[v619];
    bool v634 = !(((~(((v304 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))) | (-(v304 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))))) >> 31)) | (~(((v305 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))) | (-(v305 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))))) >> 31))) == 0);
    int v377;
    if (v634) {
      int * v324 = v297->cache_age;
      int v636 = (4 + ((((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 3) * 2)) + ((~(((v305 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))) | (-(v305 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))))) >> 31)) & 1);
      int v325 = v324[v636];
      int v326 = v324[v620];
      int v637 = v326 + ((int)((unsigned int)(v326 - v325) >> 31));
      v324[v620] = v637;
      int * v328 = v297->cache_age;
      int v329 = v328[v621];
      int v639 = v329 + ((int)((unsigned int)(v329 - v325) >> 31));
      v328[v621] = v639;
      int * v331 = v297->cache_age;
      v331[v636] = 0;
      v377 = v636;
    } else {
      int * v334 = v297->cache_age;
      int v643 = 4 + ((((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 3) * 2);
      int v335 = v334[v643];
      int * v336 = v297->cache_tags;
      int v337 = v336[v643];
      int v338 = v334[v621];
      int v339 = v336[v621];
      int * v340 = v297->cache_dirty;
      int v646 = (4 + ((((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 3) * 2)) + ((((v335 + ((~(((v337 ^ -1) | (-(v337 ^ -1))) >> 31)) & 2)) - (v338 + ((~(((v339 ^ -1) | (-(v339 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v341 = v340[v646];
      bool v647 = !(v341 == 0);
      if (v647) {
        int * v342 = v297->cache_tags;
        int v343 = v342[v646];
        int * v344 = v297->cache_vals;
        int v650 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 3) * 2)) + ((((v335 + ((~(((v337 ^ -1) | (-(v337 ^ -1))) >> 31)) & 2)) - (v338 + ((~(((v339 ^ -1) | (-(v339 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v345 = v344[v650];
        int v651 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 3) * 2)) + ((((v335 + ((~(((v337 ^ -1) | (-(v337 ^ -1))) >> 31)) & 2)) - (v338 + ((~(((v339 ^ -1) | (-(v339 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v346 = v344[v651];
        int * v347 = v297->mem;
        int v653 = v343 * 2;
        v347[v653] = v345;
        int * v349 = v297->mem;
        int v656 = (v343 * 2) + 1;
        v349[v656] = v346;
        ;
      } else {
        ;
      }
      int * v354 = v297->mem;
      int v661 = ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) * 2;
      int v355 = v354[v661];
      int v662 = (((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) * 2) + 1;
      int v356 = v354[v662];
      int * v357 = v297->cache_vals;
      int v664 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 3) * 2)) + ((((v335 + ((~(((v337 ^ -1) | (-(v337 ^ -1))) >> 31)) & 2)) - (v338 + ((~(((v339 ^ -1) | (-(v339 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v357[v664] = v355;
      int * v359 = v297->cache_vals;
      int v667 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 3) * 2)) + ((((v335 + ((~(((v337 ^ -1) | (-(v337 ^ -1))) >> 31)) & 2)) - (v338 + ((~(((v339 ^ -1) | (-(v339 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v359[v667] = v356;
      int * v361 = v297->cache_tags;
      int v670 = (int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1);
      v361[v646] = v670;
      int * v363 = v297->cache_dirty;
      v363[v646] = 0;
      int * v365 = v297->cache_age;
      v365[v646] = 1;
      int * v367 = v297->cache_age;
      int v368 = v367[v646];
      int v369 = v367[v620];
      int v675 = v369 + ((int)((unsigned int)(v369 - v368) >> 31));
      v367[v620] = v675;
      int * v371 = v297->cache_age;
      int v372 = v371[v621];
      int v677 = v372 + ((int)((unsigned int)(v372 - v368) >> 31));
      v371[v621] = v677;
      int * v374 = v297->cache_age;
      v374[v646] = 0;
      v377 = v646;
    }
    int * v378 = v297->cache_vals;
    int v680 = v377 * 2;
    int v379 = v378[v680];
    int v681 = (v377 * 2) + 1;
    int v380 = v378[v681];
    int v682 = (((((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 1) * 2) + ((((v319 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2)) - (v322 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v378[v682] = v379;
    int * v382 = v297->cache_vals;
    int v685 = ((((((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 1) * 2) + ((((v319 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2)) - (v322 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v382[v685] = v380;
    int * v384 = v297->cache_tags;
    int v688 = ((((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 1) * 2) + ((((v319 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2)) - (v322 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v689 = (int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1);
    v384[v688] = v689;
    int * v386 = v297->cache_dirty;
    v386[v688] = 0;
    int * v388 = v297->cache_age;
    v388[v688] = 1;
    int * v390 = v297->cache_age;
    int v391 = v390[v688];
    int v392 = v390[v618];
    int v694 = v392 + ((int)((unsigned int)(v392 - v391) >> 31));
    v390[v618] = v694;
    int * v394 = v297->cache_age;
    int v395 = v394[v619];
    int v696 = v395 + ((int)((unsigned int)(v395 - v391) >> 31));
    v394[v619] = v696;
    int * v397 = v297->cache_age;
    v397[v688] = 0;
    v400 = v688;
  }
  int * v401 = v297->cache_vals;
  int v699 = (v400 * 2) + (((int)((unsigned int)v299 >> 2)) & 1);
  v401[v699] = v300;
  int * v403 = v297->cache_tags;
  int v404 = v403[v620];
  int v405 = v403[v621];
  bool v702 = !(((~(((v404 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))) | (-(v404 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))))) >> 31)) | (~(((v405 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))) | (-(v405 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))))) >> 31))) == 0);
  int v459;
  if (v702) {
    int * v406 = v297->cache_age;
    int v704 = (4 + ((((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 3) * 2)) + ((~(((v405 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))) | (-(v405 ^ ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1))))) >> 31)) & 1);
    int v407 = v406[v704];
    int v408 = v406[v620];
    int v705 = v408 + ((int)((unsigned int)(v408 - v407) >> 31));
    v406[v620] = v705;
    int * v410 = v297->cache_age;
    int v411 = v410[v621];
    int v707 = v411 + ((int)((unsigned int)(v411 - v407) >> 31));
    v410[v621] = v707;
    int * v413 = v297->cache_age;
    v413[v704] = 0;
    v459 = v704;
  } else {
    int * v416 = v297->cache_age;
    int v711 = 4 + ((((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 3) * 2);
    int v417 = v416[v711];
    int * v418 = v297->cache_tags;
    int v419 = v418[v711];
    int v420 = v416[v621];
    int v421 = v418[v621];
    int * v422 = v297->cache_dirty;
    int v714 = (4 + ((((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 3) * 2)) + ((((v417 + ((~(((v419 ^ -1) | (-(v419 ^ -1))) >> 31)) & 2)) - (v420 + ((~(((v421 ^ -1) | (-(v421 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v423 = v422[v714];
    bool v715 = !(v423 == 0);
    if (v715) {
      int * v424 = v297->cache_tags;
      int v425 = v424[v714];
      int * v426 = v297->cache_vals;
      int v718 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 3) * 2)) + ((((v417 + ((~(((v419 ^ -1) | (-(v419 ^ -1))) >> 31)) & 2)) - (v420 + ((~(((v421 ^ -1) | (-(v421 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v427 = v426[v718];
      int v719 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 3) * 2)) + ((((v417 + ((~(((v419 ^ -1) | (-(v419 ^ -1))) >> 31)) & 2)) - (v420 + ((~(((v421 ^ -1) | (-(v421 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v428 = v426[v719];
      int * v429 = v297->mem;
      int v721 = v425 * 2;
      v429[v721] = v427;
      int * v431 = v297->mem;
      int v724 = (v425 * 2) + 1;
      v431[v724] = v428;
      ;
    } else {
      ;
    }
    int * v436 = v297->mem;
    int v729 = ((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) * 2;
    int v437 = v436[v729];
    int v730 = (((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) * 2) + 1;
    int v438 = v436[v730];
    int * v439 = v297->cache_vals;
    int v732 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 3) * 2)) + ((((v417 + ((~(((v419 ^ -1) | (-(v419 ^ -1))) >> 31)) & 2)) - (v420 + ((~(((v421 ^ -1) | (-(v421 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v439[v732] = v437;
    int * v441 = v297->cache_vals;
    int v735 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1)) & 3) * 2)) + ((((v417 + ((~(((v419 ^ -1) | (-(v419 ^ -1))) >> 31)) & 2)) - (v420 + ((~(((v421 ^ -1) | (-(v421 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v441[v735] = v438;
    int * v443 = v297->cache_tags;
    int v738 = (int)((unsigned int)((int)((unsigned int)v299 >> 2)) >> 1);
    v443[v714] = v738;
    int * v445 = v297->cache_dirty;
    v445[v714] = 0;
    int * v447 = v297->cache_age;
    v447[v714] = 1;
    int * v449 = v297->cache_age;
    int v450 = v449[v714];
    int v451 = v449[v620];
    int v743 = v451 + ((int)((unsigned int)(v451 - v450) >> 31));
    v449[v620] = v743;
    int * v453 = v297->cache_age;
    int v454 = v453[v621];
    int v745 = v454 + ((int)((unsigned int)(v454 - v450) >> 31));
    v453[v621] = v745;
    int * v456 = v297->cache_age;
    v456[v714] = 0;
    v459 = v714;
  }
  int * v460 = v297->cache_vals;
  int v748 = (v459 * 2) + (((int)((unsigned int)v299 >> 2)) & 1);
  v460[v748] = v300;
  int * v462 = v297->cache_dirty;
  v462[v459] = 1;
  struct StateT2 * v464 = slot_4(v117);
  return v464;
}

struct StateT2 * slot_0(struct StateT2 * v2) {
  struct StateT * v3 = v2->a;
  int v4 = v3->timer;
  struct StateT * v5 = v2->b;
  int v6 = v5->timer;
  bool v27 = v4 == v6;
  squared_assert(v27);
  squared_assume(v27);
  struct StateT * v9 = v2->a;
  int v10 = v9->timer;
  int v29 = v10 + 1;
  v9->timer = v29;
  struct StateT * v12 = v2->b;
  int v13 = v12->timer;
  int v31 = v13 + 1;
  v12->timer = v31;
  struct StateT * v15 = v2->a;
  int * v16 = v15->regs;
  int v17 = v16[10];
  int v36 = v17 & 28;
  v16[6] = v36;
  struct StateT * v19 = v2->b;
  int * v20 = v19->regs;
  int v21 = v20[10];
  int v39 = v21 & 28;
  v20[6] = v39;
  struct StateT2 * v23 = slot_1(v2);
  return v23;
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