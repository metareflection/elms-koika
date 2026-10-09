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
struct StateT * slot_1(struct StateT * v17);
struct StateT * slot_8(struct StateT * v1267);
struct StateT * slot_6(struct StateT * v859);
struct StateT * slot_5(struct StateT * v661);
struct StateT * slot_4(struct StateT * v354);
struct StateT * slot_2(struct StateT * v32);
struct StateT * slot_7(struct StateT * v1063);
struct StateT * slot_3(struct StateT * v341);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v17) {
  int v18 = v17->timer;
  int v25 = v18 + 1;
  v17->timer = v25;
  int * v20 = v17->regs;
  int v21 = v20[5];
  int v29 = v21 + 80;
  v20[6] = v29;
  struct StateT * v23 = slot_2(v17);
  return v23;
}

struct StateT * slot_8(struct StateT * v1267) {
  int v1268 = v1267->timer;
  int v1377 = v1268 + 1;
  v1267->timer = v1377;
  int * v1270 = v1267->regs;
  int v1271 = v1270[11];
  int * v1272 = v1267->cache_tags;
  int v1381 = (((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1)) & 1) * 2;
  int v1273 = v1272[v1381];
  int v1382 = ((((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1274 = v1272[v1382];
  int v1383 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1)) & 3) * 2);
  int v1275 = v1272[v1383];
  int v1384 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1276 = v1272[v1384];
  int v1277 = v1267->timer;
  int v1385 = v1277 + ((100 ^ (((~(((v1275 ^ ((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1))) | (-(v1275 ^ ((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1))))) >> 31)) | (~(((v1276 ^ ((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1))) | (-(v1276 ^ ((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1273 ^ ((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1))) | (-(v1273 ^ ((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1))))) >> 31)) | (~(((v1274 ^ ((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1))) | (-(v1274 ^ ((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1275 ^ ((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1))) | (-(v1275 ^ ((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1))))) >> 31)) | (~(((v1276 ^ ((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1))) | (-(v1276 ^ ((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1267->timer = v1385;
  int * v1279 = v1267->cache_vals;
  bool v1386 = !(((~(((v1273 ^ ((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1))) | (-(v1273 ^ ((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1))))) >> 31)) | (~(((v1274 ^ ((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1))) | (-(v1274 ^ ((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1))))) >> 31))) == 0);
  int v1372;
  if (v1386) {
    int * v1280 = v1267->cache_age;
    int v1388 = ((((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1)) & 1) * 2) + ((~(((v1274 ^ ((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1))) | (-(v1274 ^ ((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1))))) >> 31)) & 1);
    int v1281 = v1280[v1388];
    int v1282 = v1280[v1381];
    int v1389 = v1282 + ((int)((unsigned int)(v1282 - v1281) >> 31));
    v1280[v1381] = v1389;
    int * v1284 = v1267->cache_age;
    int v1285 = v1284[v1382];
    int v1391 = v1285 + ((int)((unsigned int)(v1285 - v1281) >> 31));
    v1284[v1382] = v1391;
    int * v1287 = v1267->cache_age;
    v1287[v1388] = 0;
    v1372 = v1388;
  } else {
    int * v1290 = v1267->cache_age;
    int v1395 = (((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1)) & 1) * 2;
    int v1291 = v1290[v1395];
    int * v1292 = v1267->cache_tags;
    int v1293 = v1292[v1395];
    int v1294 = v1290[v1382];
    int v1295 = v1292[v1382];
    bool v1397 = !(((~(((v1275 ^ ((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1))) | (-(v1275 ^ ((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1))))) >> 31)) | (~(((v1276 ^ ((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1))) | (-(v1276 ^ ((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1))))) >> 31))) == 0);
    int v1349;
    if (v1397) {
      int * v1296 = v1267->cache_age;
      int v1399 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1276 ^ ((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1))) | (-(v1276 ^ ((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1))))) >> 31)) & 1);
      int v1297 = v1296[v1399];
      int v1298 = v1296[v1383];
      int v1400 = v1298 + ((int)((unsigned int)(v1298 - v1297) >> 31));
      v1296[v1383] = v1400;
      int * v1300 = v1267->cache_age;
      int v1301 = v1300[v1384];
      int v1402 = v1301 + ((int)((unsigned int)(v1301 - v1297) >> 31));
      v1300[v1384] = v1402;
      int * v1303 = v1267->cache_age;
      v1303[v1399] = 0;
      v1349 = v1399;
    } else {
      int * v1306 = v1267->cache_age;
      int v1406 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1)) & 3) * 2);
      int v1307 = v1306[v1406];
      int * v1308 = v1267->cache_tags;
      int v1309 = v1308[v1406];
      int v1310 = v1306[v1384];
      int v1311 = v1308[v1384];
      int * v1312 = v1267->cache_dirty;
      int v1409 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1)) & 3) * 2)) + ((((v1307 + ((~(((v1309 ^ -1) | (-(v1309 ^ -1))) >> 31)) & 2)) - (v1310 + ((~(((v1311 ^ -1) | (-(v1311 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1313 = v1312[v1409];
      bool v1410 = !(v1313 == 0);
      if (v1410) {
        int * v1314 = v1267->cache_tags;
        int v1315 = v1314[v1409];
        int * v1316 = v1267->cache_vals;
        int v1413 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1)) & 3) * 2)) + ((((v1307 + ((~(((v1309 ^ -1) | (-(v1309 ^ -1))) >> 31)) & 2)) - (v1310 + ((~(((v1311 ^ -1) | (-(v1311 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1317 = v1316[v1413];
        int v1414 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1)) & 3) * 2)) + ((((v1307 + ((~(((v1309 ^ -1) | (-(v1309 ^ -1))) >> 31)) & 2)) - (v1310 + ((~(((v1311 ^ -1) | (-(v1311 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1318 = v1316[v1414];
        int * v1319 = v1267->mem;
        int v1416 = v1315 * 2;
        v1319[v1416] = v1317;
        int * v1321 = v1267->mem;
        int v1419 = (v1315 * 2) + 1;
        v1321[v1419] = v1318;
        ;
      } else {
        ;
      }
      int * v1326 = v1267->mem;
      int v1424 = ((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1)) * 2;
      int v1327 = v1326[v1424];
      int v1425 = (((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1)) * 2) + 1;
      int v1328 = v1326[v1425];
      int * v1329 = v1267->cache_vals;
      int v1427 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1)) & 3) * 2)) + ((((v1307 + ((~(((v1309 ^ -1) | (-(v1309 ^ -1))) >> 31)) & 2)) - (v1310 + ((~(((v1311 ^ -1) | (-(v1311 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1329[v1427] = v1327;
      int * v1331 = v1267->cache_vals;
      int v1430 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1)) & 3) * 2)) + ((((v1307 + ((~(((v1309 ^ -1) | (-(v1309 ^ -1))) >> 31)) & 2)) - (v1310 + ((~(((v1311 ^ -1) | (-(v1311 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1331[v1430] = v1328;
      int * v1333 = v1267->cache_tags;
      int v1433 = (int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1);
      v1333[v1409] = v1433;
      int * v1335 = v1267->cache_dirty;
      v1335[v1409] = 0;
      int * v1337 = v1267->cache_age;
      v1337[v1409] = 1;
      int * v1339 = v1267->cache_age;
      int v1340 = v1339[v1409];
      int v1341 = v1339[v1383];
      int v1439 = v1341 + ((int)((unsigned int)(v1341 - v1340) >> 31));
      v1339[v1383] = v1439;
      int * v1343 = v1267->cache_age;
      int v1344 = v1343[v1384];
      int v1441 = v1344 + ((int)((unsigned int)(v1344 - v1340) >> 31));
      v1343[v1384] = v1441;
      int * v1346 = v1267->cache_age;
      v1346[v1409] = 0;
      v1349 = v1409;
    }
    int * v1350 = v1267->cache_vals;
    int v1444 = v1349 * 2;
    int v1351 = v1350[v1444];
    int v1445 = (v1349 * 2) + 1;
    int v1352 = v1350[v1445];
    int v1446 = (((((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1)) & 1) * 2) + ((((v1291 + ((~(((v1293 ^ -1) | (-(v1293 ^ -1))) >> 31)) & 2)) - (v1294 + ((~(((v1295 ^ -1) | (-(v1295 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1350[v1446] = v1351;
    int * v1354 = v1267->cache_vals;
    int v1449 = ((((((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1)) & 1) * 2) + ((((v1291 + ((~(((v1293 ^ -1) | (-(v1293 ^ -1))) >> 31)) & 2)) - (v1294 + ((~(((v1295 ^ -1) | (-(v1295 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1354[v1449] = v1352;
    int * v1356 = v1267->cache_tags;
    int v1452 = ((((int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1)) & 1) * 2) + ((((v1291 + ((~(((v1293 ^ -1) | (-(v1293 ^ -1))) >> 31)) & 2)) - (v1294 + ((~(((v1295 ^ -1) | (-(v1295 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1453 = (int)((unsigned int)((int)((unsigned int)v1271 >> 2)) >> 1);
    v1356[v1452] = v1453;
    int * v1358 = v1267->cache_dirty;
    v1358[v1452] = 0;
    int * v1360 = v1267->cache_age;
    v1360[v1452] = 1;
    int * v1362 = v1267->cache_age;
    int v1363 = v1362[v1452];
    int v1364 = v1362[v1381];
    int v1459 = v1364 + ((int)((unsigned int)(v1364 - v1363) >> 31));
    v1362[v1381] = v1459;
    int * v1366 = v1267->cache_age;
    int v1367 = v1366[v1382];
    int v1461 = v1367 + ((int)((unsigned int)(v1367 - v1363) >> 31));
    v1366[v1382] = v1461;
    int * v1369 = v1267->cache_age;
    v1369[v1452] = 0;
    v1372 = v1452;
  }
  int v1464 = (v1372 * 2) + (((int)((unsigned int)v1271 >> 2)) & 1);
  int v1373 = v1279[v1464];
  int * v1374 = v1267->regs;
  v1374[12] = v1373;
  return v1267;
}

struct StateT * slot_6(struct StateT * v859) {
  int v860 = v859->timer;
  int v970 = v860 + 1;
  v859->timer = v970;
  int * v862 = v859->regs;
  int v863 = v862[8];
  int * v864 = v859->cache_tags;
  int v974 = (((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1)) & 1) * 2;
  int v865 = v864[v974];
  int v975 = ((((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1)) & 1) * 2) + 1;
  int v866 = v864[v975];
  int v976 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1)) & 3) * 2);
  int v867 = v864[v976];
  int v977 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v868 = v864[v977];
  int v869 = v859->timer;
  int v978 = v869 + ((100 ^ (((~(((v867 ^ ((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1))) | (-(v867 ^ ((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v868 ^ ((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1))) | (-(v868 ^ ((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v865 ^ ((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1))) | (-(v865 ^ ((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v866 ^ ((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1))) | (-(v866 ^ ((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v867 ^ ((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1))) | (-(v867 ^ ((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v868 ^ ((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1))) | (-(v868 ^ ((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1))))) >> 31))) & 104)))));
  v859->timer = v978;
  int * v871 = v859->cache_vals;
  bool v979 = !(((~(((v865 ^ ((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1))) | (-(v865 ^ ((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v866 ^ ((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1))) | (-(v866 ^ ((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1))))) >> 31))) == 0);
  int v964;
  if (v979) {
    int * v872 = v859->cache_age;
    int v981 = ((((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1)) & 1) * 2) + ((~(((v866 ^ ((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1))) | (-(v866 ^ ((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1))))) >> 31)) & 1);
    int v873 = v872[v981];
    int v874 = v872[v974];
    int v982 = v874 + ((int)((unsigned int)(v874 - v873) >> 31));
    v872[v974] = v982;
    int * v876 = v859->cache_age;
    int v877 = v876[v975];
    int v984 = v877 + ((int)((unsigned int)(v877 - v873) >> 31));
    v876[v975] = v984;
    int * v879 = v859->cache_age;
    v879[v981] = 0;
    v964 = v981;
  } else {
    int * v882 = v859->cache_age;
    int v988 = (((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1)) & 1) * 2;
    int v883 = v882[v988];
    int * v884 = v859->cache_tags;
    int v885 = v884[v988];
    int v886 = v882[v975];
    int v887 = v884[v975];
    bool v990 = !(((~(((v867 ^ ((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1))) | (-(v867 ^ ((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v868 ^ ((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1))) | (-(v868 ^ ((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1))))) >> 31))) == 0);
    int v941;
    if (v990) {
      int * v888 = v859->cache_age;
      int v992 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1)) & 3) * 2)) + ((~(((v868 ^ ((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1))) | (-(v868 ^ ((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1))))) >> 31)) & 1);
      int v889 = v888[v992];
      int v890 = v888[v976];
      int v993 = v890 + ((int)((unsigned int)(v890 - v889) >> 31));
      v888[v976] = v993;
      int * v892 = v859->cache_age;
      int v893 = v892[v977];
      int v995 = v893 + ((int)((unsigned int)(v893 - v889) >> 31));
      v892[v977] = v995;
      int * v895 = v859->cache_age;
      v895[v992] = 0;
      v941 = v992;
    } else {
      int * v898 = v859->cache_age;
      int v999 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1)) & 3) * 2);
      int v899 = v898[v999];
      int * v900 = v859->cache_tags;
      int v901 = v900[v999];
      int v902 = v898[v977];
      int v903 = v900[v977];
      int * v904 = v859->cache_dirty;
      int v1002 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v899 + ((~(((v901 ^ -1) | (-(v901 ^ -1))) >> 31)) & 2)) - (v902 + ((~(((v903 ^ -1) | (-(v903 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v905 = v904[v1002];
      bool v1003 = !(v905 == 0);
      if (v1003) {
        int * v906 = v859->cache_tags;
        int v907 = v906[v1002];
        int * v908 = v859->cache_vals;
        int v1006 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v899 + ((~(((v901 ^ -1) | (-(v901 ^ -1))) >> 31)) & 2)) - (v902 + ((~(((v903 ^ -1) | (-(v903 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v909 = v908[v1006];
        int v1007 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v899 + ((~(((v901 ^ -1) | (-(v901 ^ -1))) >> 31)) & 2)) - (v902 + ((~(((v903 ^ -1) | (-(v903 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v910 = v908[v1007];
        int * v911 = v859->mem;
        int v1009 = v907 * 2;
        v911[v1009] = v909;
        int * v913 = v859->mem;
        int v1012 = (v907 * 2) + 1;
        v913[v1012] = v910;
        ;
      } else {
        ;
      }
      int * v918 = v859->mem;
      int v1017 = ((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1)) * 2;
      int v919 = v918[v1017];
      int v1018 = (((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1)) * 2) + 1;
      int v920 = v918[v1018];
      int * v921 = v859->cache_vals;
      int v1020 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v899 + ((~(((v901 ^ -1) | (-(v901 ^ -1))) >> 31)) & 2)) - (v902 + ((~(((v903 ^ -1) | (-(v903 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v921[v1020] = v919;
      int * v923 = v859->cache_vals;
      int v1023 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v899 + ((~(((v901 ^ -1) | (-(v901 ^ -1))) >> 31)) & 2)) - (v902 + ((~(((v903 ^ -1) | (-(v903 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v923[v1023] = v920;
      int * v925 = v859->cache_tags;
      int v1026 = (int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1);
      v925[v1002] = v1026;
      int * v927 = v859->cache_dirty;
      v927[v1002] = 0;
      int * v929 = v859->cache_age;
      v929[v1002] = 1;
      int * v931 = v859->cache_age;
      int v932 = v931[v1002];
      int v933 = v931[v976];
      int v1032 = v933 + ((int)((unsigned int)(v933 - v932) >> 31));
      v931[v976] = v1032;
      int * v935 = v859->cache_age;
      int v936 = v935[v977];
      int v1034 = v936 + ((int)((unsigned int)(v936 - v932) >> 31));
      v935[v977] = v1034;
      int * v938 = v859->cache_age;
      v938[v1002] = 0;
      v941 = v1002;
    }
    int * v942 = v859->cache_vals;
    int v1037 = v941 * 2;
    int v943 = v942[v1037];
    int v1038 = (v941 * 2) + 1;
    int v944 = v942[v1038];
    int v1039 = (((((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v883 + ((~(((v885 ^ -1) | (-(v885 ^ -1))) >> 31)) & 2)) - (v886 + ((~(((v887 ^ -1) | (-(v887 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v942[v1039] = v943;
    int * v946 = v859->cache_vals;
    int v1042 = ((((((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v883 + ((~(((v885 ^ -1) | (-(v885 ^ -1))) >> 31)) & 2)) - (v886 + ((~(((v887 ^ -1) | (-(v887 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v946[v1042] = v944;
    int * v948 = v859->cache_tags;
    int v1045 = ((((int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v883 + ((~(((v885 ^ -1) | (-(v885 ^ -1))) >> 31)) & 2)) - (v886 + ((~(((v887 ^ -1) | (-(v887 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1046 = (int)((unsigned int)((int)((unsigned int)(v863 + 40) >> 2)) >> 1);
    v948[v1045] = v1046;
    int * v950 = v859->cache_dirty;
    v950[v1045] = 0;
    int * v952 = v859->cache_age;
    v952[v1045] = 1;
    int * v954 = v859->cache_age;
    int v955 = v954[v1045];
    int v956 = v954[v974];
    int v1052 = v956 + ((int)((unsigned int)(v956 - v955) >> 31));
    v954[v974] = v1052;
    int * v958 = v859->cache_age;
    int v959 = v958[v975];
    int v1054 = v959 + ((int)((unsigned int)(v959 - v955) >> 31));
    v958[v975] = v1054;
    int * v961 = v859->cache_age;
    v961[v1045] = 0;
    v964 = v1045;
  }
  int v1057 = (v964 * 2) + (((int)((unsigned int)(v863 + 40) >> 2)) & 1);
  int v965 = v871[v1057];
  int * v966 = v859->regs;
  v966[9] = v965;
  struct StateT * v968 = slot_7(v859);
  return v968;
}

struct StateT * slot_5(struct StateT * v661) {
  int v662 = v661->timer;
  int v770 = v662 + 1;
  v661->timer = v770;
  int * v664 = v661->cache_tags;
  int v665 = v664[2];
  int v666 = v664[3];
  int v667 = v664[10];
  int v668 = v664[11];
  int v669 = v661->timer;
  int v776 = v669 + ((100 ^ (((~(((v667 ^ 7) | (-(v667 ^ 7))) >> 31)) | (~(((v668 ^ 7) | (-(v668 ^ 7))) >> 31))) & 104)) ^ (((~(((v665 ^ 7) | (-(v665 ^ 7))) >> 31)) | (~(((v666 ^ 7) | (-(v666 ^ 7))) >> 31))) & (1 ^ (100 ^ (((~(((v667 ^ 7) | (-(v667 ^ 7))) >> 31)) | (~(((v668 ^ 7) | (-(v668 ^ 7))) >> 31))) & 104)))));
  v661->timer = v776;
  int * v671 = v661->cache_vals;
  bool v777 = !(((~(((v665 ^ 7) | (-(v665 ^ 7))) >> 31)) | (~(((v666 ^ 7) | (-(v666 ^ 7))) >> 31))) == 0);
  int v764;
  if (v777) {
    int * v672 = v661->cache_age;
    int v779 = 2 + ((~(((v666 ^ 7) | (-(v666 ^ 7))) >> 31)) & 1);
    int v673 = v672[v779];
    int v674 = v672[2];
    int v780 = v674 + ((int)((unsigned int)(v674 - v673) >> 31));
    v672[2] = v780;
    int * v676 = v661->cache_age;
    int v677 = v676[3];
    int v782 = v677 + ((int)((unsigned int)(v677 - v673) >> 31));
    v676[3] = v782;
    int * v679 = v661->cache_age;
    v679[v779] = 0;
    v764 = v779;
  } else {
    int * v682 = v661->cache_age;
    int v683 = v682[2];
    int * v684 = v661->cache_tags;
    int v685 = v684[2];
    int v686 = v682[3];
    int v687 = v684[3];
    bool v787 = !(((~(((v667 ^ 7) | (-(v667 ^ 7))) >> 31)) | (~(((v668 ^ 7) | (-(v668 ^ 7))) >> 31))) == 0);
    int v741;
    if (v787) {
      int * v688 = v661->cache_age;
      int v789 = 10 + ((~(((v668 ^ 7) | (-(v668 ^ 7))) >> 31)) & 1);
      int v689 = v688[v789];
      int v690 = v688[10];
      int v790 = v690 + ((int)((unsigned int)(v690 - v689) >> 31));
      v688[10] = v790;
      int * v692 = v661->cache_age;
      int v693 = v692[11];
      int v792 = v693 + ((int)((unsigned int)(v693 - v689) >> 31));
      v692[11] = v792;
      int * v695 = v661->cache_age;
      v695[v789] = 0;
      v741 = v789;
    } else {
      int * v698 = v661->cache_age;
      int v699 = v698[10];
      int * v700 = v661->cache_tags;
      int v701 = v700[10];
      int v702 = v698[11];
      int v703 = v700[11];
      int * v704 = v661->cache_dirty;
      int v798 = 10 + ((((v699 + ((~(((v701 ^ -1) | (-(v701 ^ -1))) >> 31)) & 2)) - (v702 + ((~(((v703 ^ -1) | (-(v703 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v705 = v704[v798];
      bool v799 = !(v705 == 0);
      if (v799) {
        int * v706 = v661->cache_tags;
        int v707 = v706[v798];
        int * v708 = v661->cache_vals;
        int v802 = (10 + ((((v699 + ((~(((v701 ^ -1) | (-(v701 ^ -1))) >> 31)) & 2)) - (v702 + ((~(((v703 ^ -1) | (-(v703 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v709 = v708[v802];
        int v803 = ((10 + ((((v699 + ((~(((v701 ^ -1) | (-(v701 ^ -1))) >> 31)) & 2)) - (v702 + ((~(((v703 ^ -1) | (-(v703 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v710 = v708[v803];
        int * v711 = v661->mem;
        int v805 = v707 * 2;
        v711[v805] = v709;
        int * v713 = v661->mem;
        int v808 = (v707 * 2) + 1;
        v713[v808] = v710;
        ;
      } else {
        ;
      }
      int * v718 = v661->mem;
      int v719 = v718[14];
      int v720 = v718[15];
      int * v721 = v661->cache_vals;
      int v816 = (10 + ((((v699 + ((~(((v701 ^ -1) | (-(v701 ^ -1))) >> 31)) & 2)) - (v702 + ((~(((v703 ^ -1) | (-(v703 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v721[v816] = v719;
      int * v723 = v661->cache_vals;
      int v819 = ((10 + ((((v699 + ((~(((v701 ^ -1) | (-(v701 ^ -1))) >> 31)) & 2)) - (v702 + ((~(((v703 ^ -1) | (-(v703 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v723[v819] = v720;
      int * v725 = v661->cache_tags;
      v725[v798] = 7;
      int * v727 = v661->cache_dirty;
      v727[v798] = 0;
      int * v729 = v661->cache_age;
      v729[v798] = 1;
      int * v731 = v661->cache_age;
      int v732 = v731[v798];
      int v733 = v731[10];
      int v828 = v733 + ((int)((unsigned int)(v733 - v732) >> 31));
      v731[10] = v828;
      int * v735 = v661->cache_age;
      int v736 = v735[11];
      int v830 = v736 + ((int)((unsigned int)(v736 - v732) >> 31));
      v735[11] = v830;
      int * v738 = v661->cache_age;
      v738[v798] = 0;
      v741 = v798;
    }
    int * v742 = v661->cache_vals;
    int v833 = v741 * 2;
    int v743 = v742[v833];
    int v834 = (v741 * 2) + 1;
    int v744 = v742[v834];
    int v835 = (2 + ((((v683 + ((~(((v685 ^ -1) | (-(v685 ^ -1))) >> 31)) & 2)) - (v686 + ((~(((v687 ^ -1) | (-(v687 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v742[v835] = v743;
    int * v746 = v661->cache_vals;
    int v838 = ((2 + ((((v683 + ((~(((v685 ^ -1) | (-(v685 ^ -1))) >> 31)) & 2)) - (v686 + ((~(((v687 ^ -1) | (-(v687 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v746[v838] = v744;
    int * v748 = v661->cache_tags;
    int v841 = 2 + ((((v683 + ((~(((v685 ^ -1) | (-(v685 ^ -1))) >> 31)) & 2)) - (v686 + ((~(((v687 ^ -1) | (-(v687 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    v748[v841] = 7;
    int * v750 = v661->cache_dirty;
    v750[v841] = 0;
    int * v752 = v661->cache_age;
    v752[v841] = 1;
    int * v754 = v661->cache_age;
    int v755 = v754[v841];
    int v756 = v754[2];
    int v848 = v756 + ((int)((unsigned int)(v756 - v755) >> 31));
    v754[2] = v848;
    int * v758 = v661->cache_age;
    int v759 = v758[3];
    int v850 = v759 + ((int)((unsigned int)(v759 - v755) >> 31));
    v758[3] = v850;
    int * v761 = v661->cache_age;
    v761[v841] = 0;
    v764 = v841;
  }
  int v853 = v764 * 2;
  int v765 = v671[v853];
  int * v766 = v661->regs;
  v766[8] = v765;
  struct StateT * v768 = slot_6(v661);
  return v768;
}

struct StateT * slot_4(struct StateT * v354) {
  int v355 = v354->timer;
  int v524 = v355 + 1;
  v354->timer = v524;
  int * v357 = v354->regs;
  int v358 = v357[7];
  int * v359 = v354->cache_tags;
  int v360 = v359[2];
  int v361 = v359[3];
  int v362 = v359[10];
  int v363 = v359[11];
  int v364 = v354->timer;
  int v532 = v364 + ((100 ^ (((~(((v362 ^ 7) | (-(v362 ^ 7))) >> 31)) | (~(((v363 ^ 7) | (-(v363 ^ 7))) >> 31))) & 104)) ^ (((~(((v360 ^ 7) | (-(v360 ^ 7))) >> 31)) | (~(((v361 ^ 7) | (-(v361 ^ 7))) >> 31))) & (1 ^ (100 ^ (((~(((v362 ^ 7) | (-(v362 ^ 7))) >> 31)) | (~(((v363 ^ 7) | (-(v363 ^ 7))) >> 31))) & 104)))));
  v354->timer = v532;
  bool v533 = !(((~(((v360 ^ 7) | (-(v360 ^ 7))) >> 31)) | (~(((v361 ^ 7) | (-(v361 ^ 7))) >> 31))) == 0);
  int v458;
  if (v533) {
    int * v366 = v354->cache_age;
    int v535 = 2 + ((~(((v361 ^ 7) | (-(v361 ^ 7))) >> 31)) & 1);
    int v367 = v366[v535];
    int v368 = v366[2];
    int v536 = v368 + ((int)((unsigned int)(v368 - v367) >> 31));
    v366[2] = v536;
    int * v370 = v354->cache_age;
    int v371 = v370[3];
    int v538 = v371 + ((int)((unsigned int)(v371 - v367) >> 31));
    v370[3] = v538;
    int * v373 = v354->cache_age;
    v373[v535] = 0;
    v458 = v535;
  } else {
    int * v376 = v354->cache_age;
    int v377 = v376[2];
    int * v378 = v354->cache_tags;
    int v379 = v378[2];
    int v380 = v376[3];
    int v381 = v378[3];
    bool v543 = !(((~(((v362 ^ 7) | (-(v362 ^ 7))) >> 31)) | (~(((v363 ^ 7) | (-(v363 ^ 7))) >> 31))) == 0);
    int v435;
    if (v543) {
      int * v382 = v354->cache_age;
      int v545 = 10 + ((~(((v363 ^ 7) | (-(v363 ^ 7))) >> 31)) & 1);
      int v383 = v382[v545];
      int v384 = v382[10];
      int v546 = v384 + ((int)((unsigned int)(v384 - v383) >> 31));
      v382[10] = v546;
      int * v386 = v354->cache_age;
      int v387 = v386[11];
      int v548 = v387 + ((int)((unsigned int)(v387 - v383) >> 31));
      v386[11] = v548;
      int * v389 = v354->cache_age;
      v389[v545] = 0;
      v435 = v545;
    } else {
      int * v392 = v354->cache_age;
      int v393 = v392[10];
      int * v394 = v354->cache_tags;
      int v395 = v394[10];
      int v396 = v392[11];
      int v397 = v394[11];
      int * v398 = v354->cache_dirty;
      int v554 = 10 + ((((v393 + ((~(((v395 ^ -1) | (-(v395 ^ -1))) >> 31)) & 2)) - (v396 + ((~(((v397 ^ -1) | (-(v397 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v399 = v398[v554];
      bool v555 = !(v399 == 0);
      if (v555) {
        int * v400 = v354->cache_tags;
        int v401 = v400[v554];
        int * v402 = v354->cache_vals;
        int v558 = (10 + ((((v393 + ((~(((v395 ^ -1) | (-(v395 ^ -1))) >> 31)) & 2)) - (v396 + ((~(((v397 ^ -1) | (-(v397 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v403 = v402[v558];
        int v559 = ((10 + ((((v393 + ((~(((v395 ^ -1) | (-(v395 ^ -1))) >> 31)) & 2)) - (v396 + ((~(((v397 ^ -1) | (-(v397 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v404 = v402[v559];
        int * v405 = v354->mem;
        int v561 = v401 * 2;
        v405[v561] = v403;
        int * v407 = v354->mem;
        int v564 = (v401 * 2) + 1;
        v407[v564] = v404;
        ;
      } else {
        ;
      }
      int * v412 = v354->mem;
      int v413 = v412[14];
      int v414 = v412[15];
      int * v415 = v354->cache_vals;
      int v572 = (10 + ((((v393 + ((~(((v395 ^ -1) | (-(v395 ^ -1))) >> 31)) & 2)) - (v396 + ((~(((v397 ^ -1) | (-(v397 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v415[v572] = v413;
      int * v417 = v354->cache_vals;
      int v575 = ((10 + ((((v393 + ((~(((v395 ^ -1) | (-(v395 ^ -1))) >> 31)) & 2)) - (v396 + ((~(((v397 ^ -1) | (-(v397 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v417[v575] = v414;
      int * v419 = v354->cache_tags;
      v419[v554] = 7;
      int * v421 = v354->cache_dirty;
      v421[v554] = 0;
      int * v423 = v354->cache_age;
      v423[v554] = 1;
      int * v425 = v354->cache_age;
      int v426 = v425[v554];
      int v427 = v425[10];
      int v583 = v427 + ((int)((unsigned int)(v427 - v426) >> 31));
      v425[10] = v583;
      int * v429 = v354->cache_age;
      int v430 = v429[11];
      int v585 = v430 + ((int)((unsigned int)(v430 - v426) >> 31));
      v429[11] = v585;
      int * v432 = v354->cache_age;
      v432[v554] = 0;
      v435 = v554;
    }
    int * v436 = v354->cache_vals;
    int v588 = v435 * 2;
    int v437 = v436[v588];
    int v589 = (v435 * 2) + 1;
    int v438 = v436[v589];
    int v590 = (2 + ((((v377 + ((~(((v379 ^ -1) | (-(v379 ^ -1))) >> 31)) & 2)) - (v380 + ((~(((v381 ^ -1) | (-(v381 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v436[v590] = v437;
    int * v440 = v354->cache_vals;
    int v593 = ((2 + ((((v377 + ((~(((v379 ^ -1) | (-(v379 ^ -1))) >> 31)) & 2)) - (v380 + ((~(((v381 ^ -1) | (-(v381 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v440[v593] = v438;
    int * v442 = v354->cache_tags;
    int v596 = 2 + ((((v377 + ((~(((v379 ^ -1) | (-(v379 ^ -1))) >> 31)) & 2)) - (v380 + ((~(((v381 ^ -1) | (-(v381 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    v442[v596] = 7;
    int * v444 = v354->cache_dirty;
    v444[v596] = 0;
    int * v446 = v354->cache_age;
    v446[v596] = 1;
    int * v448 = v354->cache_age;
    int v449 = v448[v596];
    int v450 = v448[2];
    int v602 = v450 + ((int)((unsigned int)(v450 - v449) >> 31));
    v448[2] = v602;
    int * v452 = v354->cache_age;
    int v453 = v452[3];
    int v604 = v453 + ((int)((unsigned int)(v453 - v449) >> 31));
    v452[3] = v604;
    int * v455 = v354->cache_age;
    v455[v596] = 0;
    v458 = v596;
  }
  int * v459 = v354->cache_vals;
  int v607 = v458 * 2;
  v459[v607] = v358;
  int * v461 = v354->cache_tags;
  int v462 = v461[10];
  int v463 = v461[11];
  bool v610 = !(((~(((v462 ^ 7) | (-(v462 ^ 7))) >> 31)) | (~(((v463 ^ 7) | (-(v463 ^ 7))) >> 31))) == 0);
  int v517;
  if (v610) {
    int * v464 = v354->cache_age;
    int v612 = 10 + ((~(((v463 ^ 7) | (-(v463 ^ 7))) >> 31)) & 1);
    int v465 = v464[v612];
    int v466 = v464[10];
    int v613 = v466 + ((int)((unsigned int)(v466 - v465) >> 31));
    v464[10] = v613;
    int * v468 = v354->cache_age;
    int v469 = v468[11];
    int v615 = v469 + ((int)((unsigned int)(v469 - v465) >> 31));
    v468[11] = v615;
    int * v471 = v354->cache_age;
    v471[v612] = 0;
    v517 = v612;
  } else {
    int * v474 = v354->cache_age;
    int v475 = v474[10];
    int * v476 = v354->cache_tags;
    int v477 = v476[10];
    int v478 = v474[11];
    int v479 = v476[11];
    int * v480 = v354->cache_dirty;
    int v621 = 10 + ((((v475 + ((~(((v477 ^ -1) | (-(v477 ^ -1))) >> 31)) & 2)) - (v478 + ((~(((v479 ^ -1) | (-(v479 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v481 = v480[v621];
    bool v622 = !(v481 == 0);
    if (v622) {
      int * v482 = v354->cache_tags;
      int v483 = v482[v621];
      int * v484 = v354->cache_vals;
      int v625 = (10 + ((((v475 + ((~(((v477 ^ -1) | (-(v477 ^ -1))) >> 31)) & 2)) - (v478 + ((~(((v479 ^ -1) | (-(v479 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v485 = v484[v625];
      int v626 = ((10 + ((((v475 + ((~(((v477 ^ -1) | (-(v477 ^ -1))) >> 31)) & 2)) - (v478 + ((~(((v479 ^ -1) | (-(v479 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v486 = v484[v626];
      int * v487 = v354->mem;
      int v628 = v483 * 2;
      v487[v628] = v485;
      int * v489 = v354->mem;
      int v631 = (v483 * 2) + 1;
      v489[v631] = v486;
      ;
    } else {
      ;
    }
    int * v494 = v354->mem;
    int v495 = v494[14];
    int v496 = v494[15];
    int * v497 = v354->cache_vals;
    int v639 = (10 + ((((v475 + ((~(((v477 ^ -1) | (-(v477 ^ -1))) >> 31)) & 2)) - (v478 + ((~(((v479 ^ -1) | (-(v479 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v497[v639] = v495;
    int * v499 = v354->cache_vals;
    int v642 = ((10 + ((((v475 + ((~(((v477 ^ -1) | (-(v477 ^ -1))) >> 31)) & 2)) - (v478 + ((~(((v479 ^ -1) | (-(v479 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v499[v642] = v496;
    int * v501 = v354->cache_tags;
    v501[v621] = 7;
    int * v503 = v354->cache_dirty;
    v503[v621] = 0;
    int * v505 = v354->cache_age;
    v505[v621] = 1;
    int * v507 = v354->cache_age;
    int v508 = v507[v621];
    int v509 = v507[10];
    int v650 = v509 + ((int)((unsigned int)(v509 - v508) >> 31));
    v507[10] = v650;
    int * v511 = v354->cache_age;
    int v512 = v511[11];
    int v652 = v512 + ((int)((unsigned int)(v512 - v508) >> 31));
    v511[11] = v652;
    int * v514 = v354->cache_age;
    v514[v621] = 0;
    v517 = v621;
  }
  int * v518 = v354->cache_vals;
  int v655 = v517 * 2;
  v518[v655] = v358;
  int * v520 = v354->cache_dirty;
  v520[v517] = 1;
  struct StateT * v522 = slot_5(v354);
  return v522;
}

struct StateT * slot_2(struct StateT * v32) {
  int v33 = v32->timer;
  int v202 = v33 + 1;
  v32->timer = v202;
  int * v35 = v32->regs;
  int v36 = v35[6];
  int * v37 = v32->cache_tags;
  int v38 = v37[2];
  int v39 = v37[3];
  int v40 = v37[6];
  int v41 = v37[7];
  int v42 = v32->timer;
  int v209 = v42 + ((100 ^ (((~(((v40 ^ 5) | (-(v40 ^ 5))) >> 31)) | (~(((v41 ^ 5) | (-(v41 ^ 5))) >> 31))) & 104)) ^ (((~(((v38 ^ 5) | (-(v38 ^ 5))) >> 31)) | (~(((v39 ^ 5) | (-(v39 ^ 5))) >> 31))) & (1 ^ (100 ^ (((~(((v40 ^ 5) | (-(v40 ^ 5))) >> 31)) | (~(((v41 ^ 5) | (-(v41 ^ 5))) >> 31))) & 104)))));
  v32->timer = v209;
  bool v210 = !(((~(((v38 ^ 5) | (-(v38 ^ 5))) >> 31)) | (~(((v39 ^ 5) | (-(v39 ^ 5))) >> 31))) == 0);
  int v136;
  if (v210) {
    int * v44 = v32->cache_age;
    int v212 = 2 + ((~(((v39 ^ 5) | (-(v39 ^ 5))) >> 31)) & 1);
    int v45 = v44[v212];
    int v46 = v44[2];
    int v213 = v46 + ((int)((unsigned int)(v46 - v45) >> 31));
    v44[2] = v213;
    int * v48 = v32->cache_age;
    int v49 = v48[3];
    int v215 = v49 + ((int)((unsigned int)(v49 - v45) >> 31));
    v48[3] = v215;
    int * v51 = v32->cache_age;
    v51[v212] = 0;
    v136 = v212;
  } else {
    int * v54 = v32->cache_age;
    int v55 = v54[2];
    int * v56 = v32->cache_tags;
    int v57 = v56[2];
    int v58 = v54[3];
    int v59 = v56[3];
    bool v220 = !(((~(((v40 ^ 5) | (-(v40 ^ 5))) >> 31)) | (~(((v41 ^ 5) | (-(v41 ^ 5))) >> 31))) == 0);
    int v113;
    if (v220) {
      int * v60 = v32->cache_age;
      int v222 = 6 + ((~(((v41 ^ 5) | (-(v41 ^ 5))) >> 31)) & 1);
      int v61 = v60[v222];
      int v62 = v60[6];
      int v223 = v62 + ((int)((unsigned int)(v62 - v61) >> 31));
      v60[6] = v223;
      int * v64 = v32->cache_age;
      int v65 = v64[7];
      int v225 = v65 + ((int)((unsigned int)(v65 - v61) >> 31));
      v64[7] = v225;
      int * v67 = v32->cache_age;
      v67[v222] = 0;
      v113 = v222;
    } else {
      int * v70 = v32->cache_age;
      int v71 = v70[6];
      int * v72 = v32->cache_tags;
      int v73 = v72[6];
      int v74 = v70[7];
      int v75 = v72[7];
      int * v76 = v32->cache_dirty;
      int v231 = 6 + ((((v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v77 = v76[v231];
      bool v232 = !(v77 == 0);
      if (v232) {
        int * v78 = v32->cache_tags;
        int v79 = v78[v231];
        int * v80 = v32->cache_vals;
        int v235 = (6 + ((((v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v81 = v80[v235];
        int v236 = ((6 + ((((v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v82 = v80[v236];
        int * v83 = v32->mem;
        int v238 = v79 * 2;
        v83[v238] = v81;
        int * v85 = v32->mem;
        int v241 = (v79 * 2) + 1;
        v85[v241] = v82;
        ;
      } else {
        ;
      }
      int * v90 = v32->mem;
      int v91 = v90[10];
      int v92 = v90[11];
      int * v93 = v32->cache_vals;
      int v249 = (6 + ((((v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v93[v249] = v91;
      int * v95 = v32->cache_vals;
      int v252 = ((6 + ((((v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v95[v252] = v92;
      int * v97 = v32->cache_tags;
      v97[v231] = 5;
      int * v99 = v32->cache_dirty;
      v99[v231] = 0;
      int * v101 = v32->cache_age;
      v101[v231] = 1;
      int * v103 = v32->cache_age;
      int v104 = v103[v231];
      int v105 = v103[6];
      int v261 = v105 + ((int)((unsigned int)(v105 - v104) >> 31));
      v103[6] = v261;
      int * v107 = v32->cache_age;
      int v108 = v107[7];
      int v263 = v108 + ((int)((unsigned int)(v108 - v104) >> 31));
      v107[7] = v263;
      int * v110 = v32->cache_age;
      v110[v231] = 0;
      v113 = v231;
    }
    int * v114 = v32->cache_vals;
    int v266 = v113 * 2;
    int v115 = v114[v266];
    int v267 = (v113 * 2) + 1;
    int v116 = v114[v267];
    int v268 = (2 + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v114[v268] = v115;
    int * v118 = v32->cache_vals;
    int v271 = ((2 + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v118[v271] = v116;
    int * v120 = v32->cache_tags;
    int v274 = 2 + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    v120[v274] = 5;
    int * v122 = v32->cache_dirty;
    v122[v274] = 0;
    int * v124 = v32->cache_age;
    v124[v274] = 1;
    int * v126 = v32->cache_age;
    int v127 = v126[v274];
    int v128 = v126[2];
    int v281 = v128 + ((int)((unsigned int)(v128 - v127) >> 31));
    v126[2] = v281;
    int * v130 = v32->cache_age;
    int v131 = v130[3];
    int v283 = v131 + ((int)((unsigned int)(v131 - v127) >> 31));
    v130[3] = v283;
    int * v133 = v32->cache_age;
    v133[v274] = 0;
    v136 = v274;
  }
  int * v137 = v32->cache_vals;
  int v286 = v136 * 2;
  v137[v286] = v36;
  int * v139 = v32->cache_tags;
  int v140 = v139[6];
  int v141 = v139[7];
  bool v289 = !(((~(((v140 ^ 5) | (-(v140 ^ 5))) >> 31)) | (~(((v141 ^ 5) | (-(v141 ^ 5))) >> 31))) == 0);
  int v195;
  if (v289) {
    int * v142 = v32->cache_age;
    int v291 = 6 + ((~(((v141 ^ 5) | (-(v141 ^ 5))) >> 31)) & 1);
    int v143 = v142[v291];
    int v144 = v142[6];
    int v292 = v144 + ((int)((unsigned int)(v144 - v143) >> 31));
    v142[6] = v292;
    int * v146 = v32->cache_age;
    int v147 = v146[7];
    int v294 = v147 + ((int)((unsigned int)(v147 - v143) >> 31));
    v146[7] = v294;
    int * v149 = v32->cache_age;
    v149[v291] = 0;
    v195 = v291;
  } else {
    int * v152 = v32->cache_age;
    int v153 = v152[6];
    int * v154 = v32->cache_tags;
    int v155 = v154[6];
    int v156 = v152[7];
    int v157 = v154[7];
    int * v158 = v32->cache_dirty;
    int v300 = 6 + ((((v153 + ((~(((v155 ^ -1) | (-(v155 ^ -1))) >> 31)) & 2)) - (v156 + ((~(((v157 ^ -1) | (-(v157 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v159 = v158[v300];
    bool v301 = !(v159 == 0);
    if (v301) {
      int * v160 = v32->cache_tags;
      int v161 = v160[v300];
      int * v162 = v32->cache_vals;
      int v304 = (6 + ((((v153 + ((~(((v155 ^ -1) | (-(v155 ^ -1))) >> 31)) & 2)) - (v156 + ((~(((v157 ^ -1) | (-(v157 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v163 = v162[v304];
      int v305 = ((6 + ((((v153 + ((~(((v155 ^ -1) | (-(v155 ^ -1))) >> 31)) & 2)) - (v156 + ((~(((v157 ^ -1) | (-(v157 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v164 = v162[v305];
      int * v165 = v32->mem;
      int v307 = v161 * 2;
      v165[v307] = v163;
      int * v167 = v32->mem;
      int v310 = (v161 * 2) + 1;
      v167[v310] = v164;
      ;
    } else {
      ;
    }
    int * v172 = v32->mem;
    int v173 = v172[10];
    int v174 = v172[11];
    int * v175 = v32->cache_vals;
    int v318 = (6 + ((((v153 + ((~(((v155 ^ -1) | (-(v155 ^ -1))) >> 31)) & 2)) - (v156 + ((~(((v157 ^ -1) | (-(v157 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v175[v318] = v173;
    int * v177 = v32->cache_vals;
    int v321 = ((6 + ((((v153 + ((~(((v155 ^ -1) | (-(v155 ^ -1))) >> 31)) & 2)) - (v156 + ((~(((v157 ^ -1) | (-(v157 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v177[v321] = v174;
    int * v179 = v32->cache_tags;
    v179[v300] = 5;
    int * v181 = v32->cache_dirty;
    v181[v300] = 0;
    int * v183 = v32->cache_age;
    v183[v300] = 1;
    int * v185 = v32->cache_age;
    int v186 = v185[v300];
    int v187 = v185[6];
    int v330 = v187 + ((int)((unsigned int)(v187 - v186) >> 31));
    v185[6] = v330;
    int * v189 = v32->cache_age;
    int v190 = v189[7];
    int v332 = v190 + ((int)((unsigned int)(v190 - v186) >> 31));
    v189[7] = v332;
    int * v192 = v32->cache_age;
    v192[v300] = 0;
    v195 = v300;
  }
  int * v196 = v32->cache_vals;
  int v335 = v195 * 2;
  v196[v335] = v36;
  int * v198 = v32->cache_dirty;
  v198[v195] = 1;
  struct StateT * v200 = slot_3(v32);
  return v200;
}

struct StateT * slot_7(struct StateT * v1063) {
  int v1064 = v1063->timer;
  int v1174 = v1064 + 1;
  v1063->timer = v1174;
  int * v1066 = v1063->regs;
  int v1067 = v1066[9];
  int * v1068 = v1063->cache_tags;
  int v1178 = (((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1)) & 1) * 2;
  int v1069 = v1068[v1178];
  int v1179 = ((((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1070 = v1068[v1179];
  int v1180 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1)) & 3) * 2);
  int v1071 = v1068[v1180];
  int v1181 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1072 = v1068[v1181];
  int v1073 = v1063->timer;
  int v1182 = v1073 + ((100 ^ (((~(((v1071 ^ ((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1))) | (-(v1071 ^ ((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1))))) >> 31)) | (~(((v1072 ^ ((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1))) | (-(v1072 ^ ((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1069 ^ ((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1))) | (-(v1069 ^ ((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1))))) >> 31)) | (~(((v1070 ^ ((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1))) | (-(v1070 ^ ((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1071 ^ ((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1))) | (-(v1071 ^ ((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1))))) >> 31)) | (~(((v1072 ^ ((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1))) | (-(v1072 ^ ((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1063->timer = v1182;
  int * v1075 = v1063->cache_vals;
  bool v1183 = !(((~(((v1069 ^ ((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1))) | (-(v1069 ^ ((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1))))) >> 31)) | (~(((v1070 ^ ((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1))) | (-(v1070 ^ ((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1))))) >> 31))) == 0);
  int v1168;
  if (v1183) {
    int * v1076 = v1063->cache_age;
    int v1185 = ((((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1)) & 1) * 2) + ((~(((v1070 ^ ((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1))) | (-(v1070 ^ ((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1))))) >> 31)) & 1);
    int v1077 = v1076[v1185];
    int v1078 = v1076[v1178];
    int v1186 = v1078 + ((int)((unsigned int)(v1078 - v1077) >> 31));
    v1076[v1178] = v1186;
    int * v1080 = v1063->cache_age;
    int v1081 = v1080[v1179];
    int v1188 = v1081 + ((int)((unsigned int)(v1081 - v1077) >> 31));
    v1080[v1179] = v1188;
    int * v1083 = v1063->cache_age;
    v1083[v1185] = 0;
    v1168 = v1185;
  } else {
    int * v1086 = v1063->cache_age;
    int v1192 = (((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1)) & 1) * 2;
    int v1087 = v1086[v1192];
    int * v1088 = v1063->cache_tags;
    int v1089 = v1088[v1192];
    int v1090 = v1086[v1179];
    int v1091 = v1088[v1179];
    bool v1194 = !(((~(((v1071 ^ ((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1))) | (-(v1071 ^ ((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1))))) >> 31)) | (~(((v1072 ^ ((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1))) | (-(v1072 ^ ((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1))))) >> 31))) == 0);
    int v1145;
    if (v1194) {
      int * v1092 = v1063->cache_age;
      int v1196 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1072 ^ ((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1))) | (-(v1072 ^ ((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1))))) >> 31)) & 1);
      int v1093 = v1092[v1196];
      int v1094 = v1092[v1180];
      int v1197 = v1094 + ((int)((unsigned int)(v1094 - v1093) >> 31));
      v1092[v1180] = v1197;
      int * v1096 = v1063->cache_age;
      int v1097 = v1096[v1181];
      int v1199 = v1097 + ((int)((unsigned int)(v1097 - v1093) >> 31));
      v1096[v1181] = v1199;
      int * v1099 = v1063->cache_age;
      v1099[v1196] = 0;
      v1145 = v1196;
    } else {
      int * v1102 = v1063->cache_age;
      int v1203 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1)) & 3) * 2);
      int v1103 = v1102[v1203];
      int * v1104 = v1063->cache_tags;
      int v1105 = v1104[v1203];
      int v1106 = v1102[v1181];
      int v1107 = v1104[v1181];
      int * v1108 = v1063->cache_dirty;
      int v1206 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1)) & 3) * 2)) + ((((v1103 + ((~(((v1105 ^ -1) | (-(v1105 ^ -1))) >> 31)) & 2)) - (v1106 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1109 = v1108[v1206];
      bool v1207 = !(v1109 == 0);
      if (v1207) {
        int * v1110 = v1063->cache_tags;
        int v1111 = v1110[v1206];
        int * v1112 = v1063->cache_vals;
        int v1210 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1)) & 3) * 2)) + ((((v1103 + ((~(((v1105 ^ -1) | (-(v1105 ^ -1))) >> 31)) & 2)) - (v1106 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1113 = v1112[v1210];
        int v1211 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1)) & 3) * 2)) + ((((v1103 + ((~(((v1105 ^ -1) | (-(v1105 ^ -1))) >> 31)) & 2)) - (v1106 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1114 = v1112[v1211];
        int * v1115 = v1063->mem;
        int v1213 = v1111 * 2;
        v1115[v1213] = v1113;
        int * v1117 = v1063->mem;
        int v1216 = (v1111 * 2) + 1;
        v1117[v1216] = v1114;
        ;
      } else {
        ;
      }
      int * v1122 = v1063->mem;
      int v1221 = ((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1)) * 2;
      int v1123 = v1122[v1221];
      int v1222 = (((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1)) * 2) + 1;
      int v1124 = v1122[v1222];
      int * v1125 = v1063->cache_vals;
      int v1224 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1)) & 3) * 2)) + ((((v1103 + ((~(((v1105 ^ -1) | (-(v1105 ^ -1))) >> 31)) & 2)) - (v1106 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1125[v1224] = v1123;
      int * v1127 = v1063->cache_vals;
      int v1227 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1)) & 3) * 2)) + ((((v1103 + ((~(((v1105 ^ -1) | (-(v1105 ^ -1))) >> 31)) & 2)) - (v1106 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1127[v1227] = v1124;
      int * v1129 = v1063->cache_tags;
      int v1230 = (int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1);
      v1129[v1206] = v1230;
      int * v1131 = v1063->cache_dirty;
      v1131[v1206] = 0;
      int * v1133 = v1063->cache_age;
      v1133[v1206] = 1;
      int * v1135 = v1063->cache_age;
      int v1136 = v1135[v1206];
      int v1137 = v1135[v1180];
      int v1236 = v1137 + ((int)((unsigned int)(v1137 - v1136) >> 31));
      v1135[v1180] = v1236;
      int * v1139 = v1063->cache_age;
      int v1140 = v1139[v1181];
      int v1238 = v1140 + ((int)((unsigned int)(v1140 - v1136) >> 31));
      v1139[v1181] = v1238;
      int * v1142 = v1063->cache_age;
      v1142[v1206] = 0;
      v1145 = v1206;
    }
    int * v1146 = v1063->cache_vals;
    int v1241 = v1145 * 2;
    int v1147 = v1146[v1241];
    int v1242 = (v1145 * 2) + 1;
    int v1148 = v1146[v1242];
    int v1243 = (((((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1)) & 1) * 2) + ((((v1087 + ((~(((v1089 ^ -1) | (-(v1089 ^ -1))) >> 31)) & 2)) - (v1090 + ((~(((v1091 ^ -1) | (-(v1091 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1146[v1243] = v1147;
    int * v1150 = v1063->cache_vals;
    int v1246 = ((((((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1)) & 1) * 2) + ((((v1087 + ((~(((v1089 ^ -1) | (-(v1089 ^ -1))) >> 31)) & 2)) - (v1090 + ((~(((v1091 ^ -1) | (-(v1091 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1150[v1246] = v1148;
    int * v1152 = v1063->cache_tags;
    int v1249 = ((((int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1)) & 1) * 2) + ((((v1087 + ((~(((v1089 ^ -1) | (-(v1089 ^ -1))) >> 31)) & 2)) - (v1090 + ((~(((v1091 ^ -1) | (-(v1091 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1250 = (int)((unsigned int)((int)((unsigned int)v1067 >> 2)) >> 1);
    v1152[v1249] = v1250;
    int * v1154 = v1063->cache_dirty;
    v1154[v1249] = 0;
    int * v1156 = v1063->cache_age;
    v1156[v1249] = 1;
    int * v1158 = v1063->cache_age;
    int v1159 = v1158[v1249];
    int v1160 = v1158[v1178];
    int v1256 = v1160 + ((int)((unsigned int)(v1160 - v1159) >> 31));
    v1158[v1178] = v1256;
    int * v1162 = v1063->cache_age;
    int v1163 = v1162[v1179];
    int v1258 = v1163 + ((int)((unsigned int)(v1163 - v1159) >> 31));
    v1162[v1179] = v1258;
    int * v1165 = v1063->cache_age;
    v1165[v1249] = 0;
    v1168 = v1249;
  }
  int v1261 = (v1168 * 2) + (((int)((unsigned int)v1067 >> 2)) & 1);
  int v1169 = v1075[v1261];
  int * v1170 = v1063->regs;
  v1170[11] = v1169;
  struct StateT * v1172 = slot_8(v1063);
  return v1172;
}

struct StateT * slot_3(struct StateT * v341) {
  int v342 = v341->timer;
  int v348 = v342 + 1;
  v341->timer = v348;
  int * v344 = v341->regs;
  v344[7] = 4;
  struct StateT * v346 = slot_4(v341);
  return v346;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v10 = v3 + 1;
  v2->timer = v10;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int v14 = v6 & 28;
  v5[5] = v14;
  struct StateT * v8 = slot_1(v2);
  return v8;
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