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
struct StateT2 * slot_8(struct StateT2 * v1181);
struct StateT2 * slot_2(struct StateT2 * v81);
struct StateT2 * slot_7(struct StateT2 * v763);
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

struct StateT2 * slot_8(struct StateT2 * v1181) {
  struct StateT * v1182 = v1181->a;
  int v1183 = v1182->timer;
  struct StateT * v1184 = v1181->b;
  int v1185 = v1184->timer;
  bool v1411 = v1183 == v1185;
  squared_assert(v1411);
  squared_assume(v1411);
  struct StateT * v1188 = v1181->a;
  int v1189 = v1188->timer;
  int v1413 = v1189 + 1;
  v1188->timer = v1413;
  struct StateT * v1191 = v1181->b;
  int v1192 = v1191->timer;
  int v1415 = v1192 + 1;
  v1191->timer = v1415;
  struct StateT * v1194 = v1181->a;
  int * v1195 = v1194->regs;
  int v1196 = v1195[11];
  int * v1197 = v1194->cache_tags;
  int v1420 = (((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1)) & 1) * 2;
  int v1198 = v1197[v1420];
  int v1421 = ((((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1199 = v1197[v1421];
  int v1422 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1)) & 3) * 2);
  int v1200 = v1197[v1422];
  int v1423 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1201 = v1197[v1423];
  int v1202 = v1194->timer;
  int v1424 = v1202 + ((100 ^ (((~(((v1200 ^ ((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1))) | (-(v1200 ^ ((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1))))) >> 31)) | (~(((v1201 ^ ((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1))) | (-(v1201 ^ ((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1198 ^ ((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1))) | (-(v1198 ^ ((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1))))) >> 31)) | (~(((v1199 ^ ((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1))) | (-(v1199 ^ ((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1200 ^ ((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1))) | (-(v1200 ^ ((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1))))) >> 31)) | (~(((v1201 ^ ((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1))) | (-(v1201 ^ ((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1194->timer = v1424;
  int * v1204 = v1194->cache_vals;
  bool v1425 = !(((~(((v1198 ^ ((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1))) | (-(v1198 ^ ((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1))))) >> 31)) | (~(((v1199 ^ ((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1))) | (-(v1199 ^ ((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1))))) >> 31))) == 0);
  int v1297;
  if (v1425) {
    int * v1205 = v1194->cache_age;
    int v1427 = ((((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1)) & 1) * 2) + ((~(((v1199 ^ ((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1))) | (-(v1199 ^ ((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1))))) >> 31)) & 1);
    int v1206 = v1205[v1427];
    int v1207 = v1205[v1420];
    int v1428 = v1207 + ((int)((unsigned int)(v1207 - v1206) >> 31));
    v1205[v1420] = v1428;
    int * v1209 = v1194->cache_age;
    int v1210 = v1209[v1421];
    int v1430 = v1210 + ((int)((unsigned int)(v1210 - v1206) >> 31));
    v1209[v1421] = v1430;
    int * v1212 = v1194->cache_age;
    v1212[v1427] = 0;
    v1297 = v1427;
  } else {
    int * v1215 = v1194->cache_age;
    int v1434 = (((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1)) & 1) * 2;
    int v1216 = v1215[v1434];
    int * v1217 = v1194->cache_tags;
    int v1218 = v1217[v1434];
    int v1219 = v1215[v1421];
    int v1220 = v1217[v1421];
    bool v1436 = !(((~(((v1200 ^ ((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1))) | (-(v1200 ^ ((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1))))) >> 31)) | (~(((v1201 ^ ((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1))) | (-(v1201 ^ ((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1))))) >> 31))) == 0);
    int v1274;
    if (v1436) {
      int * v1221 = v1194->cache_age;
      int v1438 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1201 ^ ((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1))) | (-(v1201 ^ ((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1))))) >> 31)) & 1);
      int v1222 = v1221[v1438];
      int v1223 = v1221[v1422];
      int v1439 = v1223 + ((int)((unsigned int)(v1223 - v1222) >> 31));
      v1221[v1422] = v1439;
      int * v1225 = v1194->cache_age;
      int v1226 = v1225[v1423];
      int v1441 = v1226 + ((int)((unsigned int)(v1226 - v1222) >> 31));
      v1225[v1423] = v1441;
      int * v1228 = v1194->cache_age;
      v1228[v1438] = 0;
      v1274 = v1438;
    } else {
      int * v1231 = v1194->cache_age;
      int v1445 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1)) & 3) * 2);
      int v1232 = v1231[v1445];
      int * v1233 = v1194->cache_tags;
      int v1234 = v1233[v1445];
      int v1235 = v1231[v1423];
      int v1236 = v1233[v1423];
      int * v1237 = v1194->cache_dirty;
      int v1448 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1)) & 3) * 2)) + ((((v1232 + ((~(((v1234 ^ -1) | (-(v1234 ^ -1))) >> 31)) & 2)) - (v1235 + ((~(((v1236 ^ -1) | (-(v1236 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1238 = v1237[v1448];
      bool v1449 = !(v1238 == 0);
      if (v1449) {
        int * v1239 = v1194->cache_tags;
        int v1240 = v1239[v1448];
        int * v1241 = v1194->cache_vals;
        int v1452 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1)) & 3) * 2)) + ((((v1232 + ((~(((v1234 ^ -1) | (-(v1234 ^ -1))) >> 31)) & 2)) - (v1235 + ((~(((v1236 ^ -1) | (-(v1236 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1242 = v1241[v1452];
        int v1453 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1)) & 3) * 2)) + ((((v1232 + ((~(((v1234 ^ -1) | (-(v1234 ^ -1))) >> 31)) & 2)) - (v1235 + ((~(((v1236 ^ -1) | (-(v1236 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1243 = v1241[v1453];
        int * v1244 = v1194->mem;
        int v1455 = v1240 * 2;
        v1244[v1455] = v1242;
        int * v1246 = v1194->mem;
        int v1458 = (v1240 * 2) + 1;
        v1246[v1458] = v1243;
        ;
      } else {
        ;
      }
      int * v1251 = v1194->mem;
      int v1463 = ((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1)) * 2;
      int v1252 = v1251[v1463];
      int v1464 = (((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1)) * 2) + 1;
      int v1253 = v1251[v1464];
      int * v1254 = v1194->cache_vals;
      int v1466 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1)) & 3) * 2)) + ((((v1232 + ((~(((v1234 ^ -1) | (-(v1234 ^ -1))) >> 31)) & 2)) - (v1235 + ((~(((v1236 ^ -1) | (-(v1236 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1254[v1466] = v1252;
      int * v1256 = v1194->cache_vals;
      int v1469 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1)) & 3) * 2)) + ((((v1232 + ((~(((v1234 ^ -1) | (-(v1234 ^ -1))) >> 31)) & 2)) - (v1235 + ((~(((v1236 ^ -1) | (-(v1236 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1256[v1469] = v1253;
      int * v1258 = v1194->cache_tags;
      int v1472 = (int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1);
      v1258[v1448] = v1472;
      int * v1260 = v1194->cache_dirty;
      v1260[v1448] = 0;
      int * v1262 = v1194->cache_age;
      v1262[v1448] = 1;
      int * v1264 = v1194->cache_age;
      int v1265 = v1264[v1448];
      int v1266 = v1264[v1422];
      int v1478 = v1266 + ((int)((unsigned int)(v1266 - v1265) >> 31));
      v1264[v1422] = v1478;
      int * v1268 = v1194->cache_age;
      int v1269 = v1268[v1423];
      int v1480 = v1269 + ((int)((unsigned int)(v1269 - v1265) >> 31));
      v1268[v1423] = v1480;
      int * v1271 = v1194->cache_age;
      v1271[v1448] = 0;
      v1274 = v1448;
    }
    int * v1275 = v1194->cache_vals;
    int v1483 = v1274 * 2;
    int v1276 = v1275[v1483];
    int v1484 = (v1274 * 2) + 1;
    int v1277 = v1275[v1484];
    int v1485 = (((((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1)) & 1) * 2) + ((((v1216 + ((~(((v1218 ^ -1) | (-(v1218 ^ -1))) >> 31)) & 2)) - (v1219 + ((~(((v1220 ^ -1) | (-(v1220 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1275[v1485] = v1276;
    int * v1279 = v1194->cache_vals;
    int v1488 = ((((((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1)) & 1) * 2) + ((((v1216 + ((~(((v1218 ^ -1) | (-(v1218 ^ -1))) >> 31)) & 2)) - (v1219 + ((~(((v1220 ^ -1) | (-(v1220 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1279[v1488] = v1277;
    int * v1281 = v1194->cache_tags;
    int v1491 = ((((int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1)) & 1) * 2) + ((((v1216 + ((~(((v1218 ^ -1) | (-(v1218 ^ -1))) >> 31)) & 2)) - (v1219 + ((~(((v1220 ^ -1) | (-(v1220 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1492 = (int)((unsigned int)((int)((unsigned int)v1196 >> 2)) >> 1);
    v1281[v1491] = v1492;
    int * v1283 = v1194->cache_dirty;
    v1283[v1491] = 0;
    int * v1285 = v1194->cache_age;
    v1285[v1491] = 1;
    int * v1287 = v1194->cache_age;
    int v1288 = v1287[v1491];
    int v1289 = v1287[v1420];
    int v1498 = v1289 + ((int)((unsigned int)(v1289 - v1288) >> 31));
    v1287[v1420] = v1498;
    int * v1291 = v1194->cache_age;
    int v1292 = v1291[v1421];
    int v1500 = v1292 + ((int)((unsigned int)(v1292 - v1288) >> 31));
    v1291[v1421] = v1500;
    int * v1294 = v1194->cache_age;
    v1294[v1491] = 0;
    v1297 = v1491;
  }
  int v1503 = (v1297 * 2) + (((int)((unsigned int)v1196 >> 2)) & 1);
  int v1298 = v1204[v1503];
  int * v1299 = v1194->regs;
  v1299[12] = v1298;
  struct StateT * v1301 = v1181->b;
  int * v1302 = v1301->regs;
  int v1303 = v1302[11];
  int * v1304 = v1301->cache_tags;
  int v1510 = (((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1)) & 1) * 2;
  int v1305 = v1304[v1510];
  int v1511 = ((((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1306 = v1304[v1511];
  int v1512 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1)) & 3) * 2);
  int v1307 = v1304[v1512];
  int v1513 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1308 = v1304[v1513];
  int v1309 = v1301->timer;
  int v1514 = v1309 + ((100 ^ (((~(((v1307 ^ ((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1))) | (-(v1307 ^ ((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1))))) >> 31)) | (~(((v1308 ^ ((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1))) | (-(v1308 ^ ((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1305 ^ ((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1))) | (-(v1305 ^ ((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1))))) >> 31)) | (~(((v1306 ^ ((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1))) | (-(v1306 ^ ((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1307 ^ ((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1))) | (-(v1307 ^ ((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1))))) >> 31)) | (~(((v1308 ^ ((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1))) | (-(v1308 ^ ((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1301->timer = v1514;
  int * v1311 = v1301->cache_vals;
  bool v1515 = !(((~(((v1305 ^ ((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1))) | (-(v1305 ^ ((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1))))) >> 31)) | (~(((v1306 ^ ((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1))) | (-(v1306 ^ ((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1))))) >> 31))) == 0);
  int v1404;
  if (v1515) {
    int * v1312 = v1301->cache_age;
    int v1517 = ((((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1)) & 1) * 2) + ((~(((v1306 ^ ((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1))) | (-(v1306 ^ ((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1))))) >> 31)) & 1);
    int v1313 = v1312[v1517];
    int v1314 = v1312[v1510];
    int v1518 = v1314 + ((int)((unsigned int)(v1314 - v1313) >> 31));
    v1312[v1510] = v1518;
    int * v1316 = v1301->cache_age;
    int v1317 = v1316[v1511];
    int v1520 = v1317 + ((int)((unsigned int)(v1317 - v1313) >> 31));
    v1316[v1511] = v1520;
    int * v1319 = v1301->cache_age;
    v1319[v1517] = 0;
    v1404 = v1517;
  } else {
    int * v1322 = v1301->cache_age;
    int v1524 = (((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1)) & 1) * 2;
    int v1323 = v1322[v1524];
    int * v1324 = v1301->cache_tags;
    int v1325 = v1324[v1524];
    int v1326 = v1322[v1511];
    int v1327 = v1324[v1511];
    bool v1526 = !(((~(((v1307 ^ ((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1))) | (-(v1307 ^ ((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1))))) >> 31)) | (~(((v1308 ^ ((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1))) | (-(v1308 ^ ((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1))))) >> 31))) == 0);
    int v1381;
    if (v1526) {
      int * v1328 = v1301->cache_age;
      int v1528 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1308 ^ ((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1))) | (-(v1308 ^ ((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1))))) >> 31)) & 1);
      int v1329 = v1328[v1528];
      int v1330 = v1328[v1512];
      int v1529 = v1330 + ((int)((unsigned int)(v1330 - v1329) >> 31));
      v1328[v1512] = v1529;
      int * v1332 = v1301->cache_age;
      int v1333 = v1332[v1513];
      int v1531 = v1333 + ((int)((unsigned int)(v1333 - v1329) >> 31));
      v1332[v1513] = v1531;
      int * v1335 = v1301->cache_age;
      v1335[v1528] = 0;
      v1381 = v1528;
    } else {
      int * v1338 = v1301->cache_age;
      int v1535 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1)) & 3) * 2);
      int v1339 = v1338[v1535];
      int * v1340 = v1301->cache_tags;
      int v1341 = v1340[v1535];
      int v1342 = v1338[v1513];
      int v1343 = v1340[v1513];
      int * v1344 = v1301->cache_dirty;
      int v1538 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1)) & 3) * 2)) + ((((v1339 + ((~(((v1341 ^ -1) | (-(v1341 ^ -1))) >> 31)) & 2)) - (v1342 + ((~(((v1343 ^ -1) | (-(v1343 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1345 = v1344[v1538];
      bool v1539 = !(v1345 == 0);
      if (v1539) {
        int * v1346 = v1301->cache_tags;
        int v1347 = v1346[v1538];
        int * v1348 = v1301->cache_vals;
        int v1542 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1)) & 3) * 2)) + ((((v1339 + ((~(((v1341 ^ -1) | (-(v1341 ^ -1))) >> 31)) & 2)) - (v1342 + ((~(((v1343 ^ -1) | (-(v1343 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1349 = v1348[v1542];
        int v1543 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1)) & 3) * 2)) + ((((v1339 + ((~(((v1341 ^ -1) | (-(v1341 ^ -1))) >> 31)) & 2)) - (v1342 + ((~(((v1343 ^ -1) | (-(v1343 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1350 = v1348[v1543];
        int * v1351 = v1301->mem;
        int v1545 = v1347 * 2;
        v1351[v1545] = v1349;
        int * v1353 = v1301->mem;
        int v1548 = (v1347 * 2) + 1;
        v1353[v1548] = v1350;
        ;
      } else {
        ;
      }
      int * v1358 = v1301->mem;
      int v1553 = ((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1)) * 2;
      int v1359 = v1358[v1553];
      int v1554 = (((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1)) * 2) + 1;
      int v1360 = v1358[v1554];
      int * v1361 = v1301->cache_vals;
      int v1556 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1)) & 3) * 2)) + ((((v1339 + ((~(((v1341 ^ -1) | (-(v1341 ^ -1))) >> 31)) & 2)) - (v1342 + ((~(((v1343 ^ -1) | (-(v1343 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1361[v1556] = v1359;
      int * v1363 = v1301->cache_vals;
      int v1559 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1)) & 3) * 2)) + ((((v1339 + ((~(((v1341 ^ -1) | (-(v1341 ^ -1))) >> 31)) & 2)) - (v1342 + ((~(((v1343 ^ -1) | (-(v1343 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1363[v1559] = v1360;
      int * v1365 = v1301->cache_tags;
      int v1562 = (int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1);
      v1365[v1538] = v1562;
      int * v1367 = v1301->cache_dirty;
      v1367[v1538] = 0;
      int * v1369 = v1301->cache_age;
      v1369[v1538] = 1;
      int * v1371 = v1301->cache_age;
      int v1372 = v1371[v1538];
      int v1373 = v1371[v1512];
      int v1568 = v1373 + ((int)((unsigned int)(v1373 - v1372) >> 31));
      v1371[v1512] = v1568;
      int * v1375 = v1301->cache_age;
      int v1376 = v1375[v1513];
      int v1570 = v1376 + ((int)((unsigned int)(v1376 - v1372) >> 31));
      v1375[v1513] = v1570;
      int * v1378 = v1301->cache_age;
      v1378[v1538] = 0;
      v1381 = v1538;
    }
    int * v1382 = v1301->cache_vals;
    int v1573 = v1381 * 2;
    int v1383 = v1382[v1573];
    int v1574 = (v1381 * 2) + 1;
    int v1384 = v1382[v1574];
    int v1575 = (((((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1)) & 1) * 2) + ((((v1323 + ((~(((v1325 ^ -1) | (-(v1325 ^ -1))) >> 31)) & 2)) - (v1326 + ((~(((v1327 ^ -1) | (-(v1327 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1382[v1575] = v1383;
    int * v1386 = v1301->cache_vals;
    int v1578 = ((((((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1)) & 1) * 2) + ((((v1323 + ((~(((v1325 ^ -1) | (-(v1325 ^ -1))) >> 31)) & 2)) - (v1326 + ((~(((v1327 ^ -1) | (-(v1327 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1386[v1578] = v1384;
    int * v1388 = v1301->cache_tags;
    int v1581 = ((((int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1)) & 1) * 2) + ((((v1323 + ((~(((v1325 ^ -1) | (-(v1325 ^ -1))) >> 31)) & 2)) - (v1326 + ((~(((v1327 ^ -1) | (-(v1327 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1582 = (int)((unsigned int)((int)((unsigned int)v1303 >> 2)) >> 1);
    v1388[v1581] = v1582;
    int * v1390 = v1301->cache_dirty;
    v1390[v1581] = 0;
    int * v1392 = v1301->cache_age;
    v1392[v1581] = 1;
    int * v1394 = v1301->cache_age;
    int v1395 = v1394[v1581];
    int v1396 = v1394[v1510];
    int v1588 = v1396 + ((int)((unsigned int)(v1396 - v1395) >> 31));
    v1394[v1510] = v1588;
    int * v1398 = v1301->cache_age;
    int v1399 = v1398[v1511];
    int v1590 = v1399 + ((int)((unsigned int)(v1399 - v1395) >> 31));
    v1398[v1511] = v1590;
    int * v1401 = v1301->cache_age;
    v1401[v1581] = 0;
    v1404 = v1581;
  }
  int v1593 = (v1404 * 2) + (((int)((unsigned int)v1303 >> 2)) & 1);
  int v1405 = v1311[v1593];
  int * v1406 = v1301->regs;
  v1406[12] = v1405;
  return v1181;
}

struct StateT2 * slot_2(struct StateT2 * v81) {
  struct StateT * v82 = v81->a;
  int v83 = v82->timer;
  struct StateT * v84 = v81->b;
  int v85 = v84->timer;
  bool v468 = v83 == v85;
  squared_assert(v468);
  squared_assume(v468);
  struct StateT * v88 = v81->a;
  int v89 = v88->timer;
  int v470 = v89 + 1;
  v88->timer = v470;
  struct StateT * v91 = v81->b;
  int v92 = v91->timer;
  int v472 = v92 + 1;
  v91->timer = v472;
  struct StateT * v94 = v81->a;
  int * v95 = v94->regs;
  int v96 = v95[6];
  struct StateT * v97 = v81->b;
  int * v98 = v97->regs;
  int v99 = v98[6];
  int * v100 = v94->saved_regs;
  int v101 = v95[0];
  v100[0] = v101;
  struct StateT * v103 = v81->b;
  int * v104 = v103->saved_regs;
  int * v105 = v103->regs;
  int v106 = v105[0];
  v104[0] = v106;
  struct StateT * v108 = v81->a;
  int v109 = v108->timer;
  int v486 = v109 + 1;
  v108->timer = v486;
  struct StateT * v111 = v81->b;
  int v112 = v111->timer;
  int v488 = v112 + 1;
  v111->timer = v488;
  struct StateT * v114 = v81->a;
  int v116 = v114->timer;
  int v490 = v116 + 1;
  v114->timer = v490;
  struct StateT * v118 = v81->b;
  int v119 = v118->timer;
  int v492 = v119 + 1;
  v118->timer = v492;
  struct StateT * v121 = v81->a;
  int v123 = v121->timer;
  int v494 = v123 + 1;
  v121->timer = v494;
  struct StateT * v125 = v81->b;
  int v126 = v125->timer;
  int v496 = v126 + 1;
  v125->timer = v496;
  struct StateT * v128 = v81->a;
  int v130 = v128->timer;
  int v498 = v130 + 1;
  v128->timer = v498;
  struct StateT * v132 = v81->b;
  int v133 = v132->timer;
  int v500 = v133 + 1;
  v132->timer = v500;
  struct StateT * v135 = v81->a;
  int * v137 = v135->cache_tags;
  int v503 = (((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 1) * 2;
  int v138 = v137[v503];
  int v504 = ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 1) * 2) + 1;
  int v139 = v137[v504];
  int v505 = 4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2);
  int v140 = v137[v505];
  int v506 = (4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v141 = v137[v506];
  int v142 = v135->timer;
  int v507 = v142 + ((100 ^ (((~(((v140 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v140 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31)) | (~(((v141 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v141 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v138 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v138 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31)) | (~(((v139 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v139 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v140 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v140 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31)) | (~(((v141 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v141 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31))) & 104)))));
  v135->timer = v507;
  bool v508 = !(((~(((v138 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v138 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31)) | (~(((v139 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v139 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31))) == 0);
  int v236;
  if (v508) {
    int * v144 = v135->cache_age;
    int v510 = ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 1) * 2) + ((~(((v139 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v139 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31)) & 1);
    int v145 = v144[v510];
    int v146 = v144[v503];
    int v511 = v146 + ((int)((unsigned int)(v146 - v145) >> 31));
    v144[v503] = v511;
    int * v148 = v135->cache_age;
    int v149 = v148[v504];
    int v513 = v149 + ((int)((unsigned int)(v149 - v145) >> 31));
    v148[v504] = v513;
    int * v151 = v135->cache_age;
    v151[v510] = 0;
    v236 = v510;
  } else {
    int * v154 = v135->cache_age;
    int v516 = (((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 1) * 2;
    int v155 = v154[v516];
    int * v156 = v135->cache_tags;
    int v157 = v156[v516];
    int v158 = v154[v504];
    int v159 = v156[v504];
    bool v518 = !(((~(((v140 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v140 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31)) | (~(((v141 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v141 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31))) == 0);
    int v213;
    if (v518) {
      int * v160 = v135->cache_age;
      int v520 = (4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + ((~(((v141 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v141 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31)) & 1);
      int v161 = v160[v520];
      int v162 = v160[v505];
      int v521 = v162 + ((int)((unsigned int)(v162 - v161) >> 31));
      v160[v505] = v521;
      int * v164 = v135->cache_age;
      int v165 = v164[v506];
      int v523 = v165 + ((int)((unsigned int)(v165 - v161) >> 31));
      v164[v506] = v523;
      int * v167 = v135->cache_age;
      v167[v520] = 0;
      v213 = v520;
    } else {
      int * v170 = v135->cache_age;
      int v526 = 4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2);
      int v171 = v170[v526];
      int * v172 = v135->cache_tags;
      int v173 = v172[v526];
      int v174 = v170[v506];
      int v175 = v172[v506];
      int * v176 = v135->cache_dirty;
      int v529 = (4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + ((((v171 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2)) - (v174 + ((~(((v175 ^ -1) | (-(v175 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v177 = v176[v529];
      bool v530 = !(v177 == 0);
      if (v530) {
        int * v178 = v135->cache_tags;
        int v179 = v178[v529];
        int * v180 = v135->cache_vals;
        int v533 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + ((((v171 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2)) - (v174 + ((~(((v175 ^ -1) | (-(v175 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v181 = v180[v533];
        int v534 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + ((((v171 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2)) - (v174 + ((~(((v175 ^ -1) | (-(v175 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v182 = v180[v534];
        int * v183 = v135->mem;
        int v536 = v179 * 2;
        v183[v536] = v181;
        int * v185 = v135->mem;
        int v539 = (v179 * 2) + 1;
        v185[v539] = v182;
        ;
      } else {
        ;
      }
      int * v190 = v135->mem;
      int v544 = ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) * 2;
      int v191 = v190[v544];
      int v545 = (((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) * 2) + 1;
      int v192 = v190[v545];
      int * v193 = v135->cache_vals;
      int v547 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + ((((v171 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2)) - (v174 + ((~(((v175 ^ -1) | (-(v175 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v193[v547] = v191;
      int * v195 = v135->cache_vals;
      int v550 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + ((((v171 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2)) - (v174 + ((~(((v175 ^ -1) | (-(v175 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v195[v550] = v192;
      int * v197 = v135->cache_tags;
      int v553 = (int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1);
      v197[v529] = v553;
      int * v199 = v135->cache_dirty;
      v199[v529] = 0;
      int * v201 = v135->cache_age;
      v201[v529] = 1;
      int * v203 = v135->cache_age;
      int v204 = v203[v529];
      int v205 = v203[v505];
      int v558 = v205 + ((int)((unsigned int)(v205 - v204) >> 31));
      v203[v505] = v558;
      int * v207 = v135->cache_age;
      int v208 = v207[v506];
      int v560 = v208 + ((int)((unsigned int)(v208 - v204) >> 31));
      v207[v506] = v560;
      int * v210 = v135->cache_age;
      v210[v529] = 0;
      v213 = v529;
    }
    int * v214 = v135->cache_vals;
    int v563 = v213 * 2;
    int v215 = v214[v563];
    int v564 = (v213 * 2) + 1;
    int v216 = v214[v564];
    int v565 = (((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 1) * 2) + ((((v155 + ((~(((v157 ^ -1) | (-(v157 ^ -1))) >> 31)) & 2)) - (v158 + ((~(((v159 ^ -1) | (-(v159 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v214[v565] = v215;
    int * v218 = v135->cache_vals;
    int v568 = ((((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 1) * 2) + ((((v155 + ((~(((v157 ^ -1) | (-(v157 ^ -1))) >> 31)) & 2)) - (v158 + ((~(((v159 ^ -1) | (-(v159 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v218[v568] = v216;
    int * v220 = v135->cache_tags;
    int v571 = ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 1) * 2) + ((((v155 + ((~(((v157 ^ -1) | (-(v157 ^ -1))) >> 31)) & 2)) - (v158 + ((~(((v159 ^ -1) | (-(v159 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v572 = (int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1);
    v220[v571] = v572;
    int * v222 = v135->cache_dirty;
    v222[v571] = 0;
    int * v224 = v135->cache_age;
    v224[v571] = 1;
    int * v226 = v135->cache_age;
    int v227 = v226[v571];
    int v228 = v226[v503];
    int v577 = v228 + ((int)((unsigned int)(v228 - v227) >> 31));
    v226[v503] = v577;
    int * v230 = v135->cache_age;
    int v231 = v230[v504];
    int v579 = v231 + ((int)((unsigned int)(v231 - v227) >> 31));
    v230[v504] = v579;
    int * v233 = v135->cache_age;
    v233[v571] = 0;
    v236 = v571;
  }
  int * v237 = v135->cache_vals;
  int v582 = (v236 * 2) + (((int)((unsigned int)v96 >> 2)) & 1);
  v237[v582] = 0;
  int * v239 = v135->cache_tags;
  int v240 = v239[v505];
  int v241 = v239[v506];
  bool v584 = !(((~(((v240 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v240 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31)) | (~(((v241 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v241 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31))) == 0);
  int v295;
  if (v584) {
    int * v242 = v135->cache_age;
    int v586 = (4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + ((~(((v241 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v241 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31)) & 1);
    int v243 = v242[v586];
    int v244 = v242[v505];
    int v587 = v244 + ((int)((unsigned int)(v244 - v243) >> 31));
    v242[v505] = v587;
    int * v246 = v135->cache_age;
    int v247 = v246[v506];
    int v589 = v247 + ((int)((unsigned int)(v247 - v243) >> 31));
    v246[v506] = v589;
    int * v249 = v135->cache_age;
    v249[v586] = 0;
    v295 = v586;
  } else {
    int * v252 = v135->cache_age;
    int v592 = 4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2);
    int v253 = v252[v592];
    int * v254 = v135->cache_tags;
    int v255 = v254[v592];
    int v256 = v252[v506];
    int v257 = v254[v506];
    int * v258 = v135->cache_dirty;
    int v595 = (4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + ((((v253 + ((~(((v255 ^ -1) | (-(v255 ^ -1))) >> 31)) & 2)) - (v256 + ((~(((v257 ^ -1) | (-(v257 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v259 = v258[v595];
    bool v596 = !(v259 == 0);
    if (v596) {
      int * v260 = v135->cache_tags;
      int v261 = v260[v595];
      int * v262 = v135->cache_vals;
      int v599 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + ((((v253 + ((~(((v255 ^ -1) | (-(v255 ^ -1))) >> 31)) & 2)) - (v256 + ((~(((v257 ^ -1) | (-(v257 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v263 = v262[v599];
      int v600 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + ((((v253 + ((~(((v255 ^ -1) | (-(v255 ^ -1))) >> 31)) & 2)) - (v256 + ((~(((v257 ^ -1) | (-(v257 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v264 = v262[v600];
      int * v265 = v135->mem;
      int v602 = v261 * 2;
      v265[v602] = v263;
      int * v267 = v135->mem;
      int v605 = (v261 * 2) + 1;
      v267[v605] = v264;
      ;
    } else {
      ;
    }
    int * v272 = v135->mem;
    int v610 = ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) * 2;
    int v273 = v272[v610];
    int v611 = (((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) * 2) + 1;
    int v274 = v272[v611];
    int * v275 = v135->cache_vals;
    int v613 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + ((((v253 + ((~(((v255 ^ -1) | (-(v255 ^ -1))) >> 31)) & 2)) - (v256 + ((~(((v257 ^ -1) | (-(v257 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v275[v613] = v273;
    int * v277 = v135->cache_vals;
    int v616 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + ((((v253 + ((~(((v255 ^ -1) | (-(v255 ^ -1))) >> 31)) & 2)) - (v256 + ((~(((v257 ^ -1) | (-(v257 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v277[v616] = v274;
    int * v279 = v135->cache_tags;
    int v619 = (int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1);
    v279[v595] = v619;
    int * v281 = v135->cache_dirty;
    v281[v595] = 0;
    int * v283 = v135->cache_age;
    v283[v595] = 1;
    int * v285 = v135->cache_age;
    int v286 = v285[v595];
    int v287 = v285[v505];
    int v624 = v287 + ((int)((unsigned int)(v287 - v286) >> 31));
    v285[v505] = v624;
    int * v289 = v135->cache_age;
    int v290 = v289[v506];
    int v626 = v290 + ((int)((unsigned int)(v290 - v286) >> 31));
    v289[v506] = v626;
    int * v292 = v135->cache_age;
    v292[v595] = 0;
    v295 = v595;
  }
  int * v296 = v135->cache_vals;
  int v629 = (v295 * 2) + (((int)((unsigned int)v96 >> 2)) & 1);
  v296[v629] = 0;
  int * v298 = v135->cache_dirty;
  v298[v295] = 1;
  struct StateT * v300 = v81->b;
  int * v301 = v300->cache_tags;
  int v635 = (((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1)) & 1) * 2;
  int v302 = v301[v635];
  int v636 = ((((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1)) & 1) * 2) + 1;
  int v303 = v301[v636];
  int v637 = 4 + ((((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1)) & 3) * 2);
  int v304 = v301[v637];
  int v638 = (4 + ((((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v305 = v301[v638];
  int v306 = v300->timer;
  int v639 = v306 + ((100 ^ (((~(((v304 ^ ((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1))) | (-(v304 ^ ((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1))))) >> 31)) | (~(((v305 ^ ((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1))) | (-(v305 ^ ((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v302 ^ ((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1))) | (-(v302 ^ ((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1))))) >> 31)) | (~(((v303 ^ ((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1))) | (-(v303 ^ ((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v304 ^ ((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1))) | (-(v304 ^ ((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1))))) >> 31)) | (~(((v305 ^ ((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1))) | (-(v305 ^ ((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1))))) >> 31))) & 104)))));
  v300->timer = v639;
  bool v640 = !(((~(((v302 ^ ((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1))) | (-(v302 ^ ((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1))))) >> 31)) | (~(((v303 ^ ((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1))) | (-(v303 ^ ((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1))))) >> 31))) == 0);
  int v400;
  if (v640) {
    int * v308 = v300->cache_age;
    int v642 = ((((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1)) & 1) * 2) + ((~(((v303 ^ ((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1))) | (-(v303 ^ ((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1))))) >> 31)) & 1);
    int v309 = v308[v642];
    int v310 = v308[v635];
    int v643 = v310 + ((int)((unsigned int)(v310 - v309) >> 31));
    v308[v635] = v643;
    int * v312 = v300->cache_age;
    int v313 = v312[v636];
    int v645 = v313 + ((int)((unsigned int)(v313 - v309) >> 31));
    v312[v636] = v645;
    int * v315 = v300->cache_age;
    v315[v642] = 0;
    v400 = v642;
  } else {
    int * v318 = v300->cache_age;
    int v648 = (((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1)) & 1) * 2;
    int v319 = v318[v648];
    int * v320 = v300->cache_tags;
    int v321 = v320[v648];
    int v322 = v318[v636];
    int v323 = v320[v636];
    bool v650 = !(((~(((v304 ^ ((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1))) | (-(v304 ^ ((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1))))) >> 31)) | (~(((v305 ^ ((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1))) | (-(v305 ^ ((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1))))) >> 31))) == 0);
    int v377;
    if (v650) {
      int * v324 = v300->cache_age;
      int v652 = (4 + ((((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1)) & 3) * 2)) + ((~(((v305 ^ ((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1))) | (-(v305 ^ ((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1))))) >> 31)) & 1);
      int v325 = v324[v652];
      int v326 = v324[v637];
      int v653 = v326 + ((int)((unsigned int)(v326 - v325) >> 31));
      v324[v637] = v653;
      int * v328 = v300->cache_age;
      int v329 = v328[v638];
      int v655 = v329 + ((int)((unsigned int)(v329 - v325) >> 31));
      v328[v638] = v655;
      int * v331 = v300->cache_age;
      v331[v652] = 0;
      v377 = v652;
    } else {
      int * v334 = v300->cache_age;
      int v658 = 4 + ((((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1)) & 3) * 2);
      int v335 = v334[v658];
      int * v336 = v300->cache_tags;
      int v337 = v336[v658];
      int v338 = v334[v638];
      int v339 = v336[v638];
      int * v340 = v300->cache_dirty;
      int v661 = (4 + ((((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1)) & 3) * 2)) + ((((v335 + ((~(((v337 ^ -1) | (-(v337 ^ -1))) >> 31)) & 2)) - (v338 + ((~(((v339 ^ -1) | (-(v339 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v341 = v340[v661];
      bool v662 = !(v341 == 0);
      if (v662) {
        int * v342 = v300->cache_tags;
        int v343 = v342[v661];
        int * v344 = v300->cache_vals;
        int v665 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1)) & 3) * 2)) + ((((v335 + ((~(((v337 ^ -1) | (-(v337 ^ -1))) >> 31)) & 2)) - (v338 + ((~(((v339 ^ -1) | (-(v339 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v345 = v344[v665];
        int v666 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1)) & 3) * 2)) + ((((v335 + ((~(((v337 ^ -1) | (-(v337 ^ -1))) >> 31)) & 2)) - (v338 + ((~(((v339 ^ -1) | (-(v339 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v346 = v344[v666];
        int * v347 = v300->mem;
        int v668 = v343 * 2;
        v347[v668] = v345;
        int * v349 = v300->mem;
        int v671 = (v343 * 2) + 1;
        v349[v671] = v346;
        ;
      } else {
        ;
      }
      int * v354 = v300->mem;
      int v676 = ((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1)) * 2;
      int v355 = v354[v676];
      int v677 = (((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1)) * 2) + 1;
      int v356 = v354[v677];
      int * v357 = v300->cache_vals;
      int v679 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1)) & 3) * 2)) + ((((v335 + ((~(((v337 ^ -1) | (-(v337 ^ -1))) >> 31)) & 2)) - (v338 + ((~(((v339 ^ -1) | (-(v339 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v357[v679] = v355;
      int * v359 = v300->cache_vals;
      int v682 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1)) & 3) * 2)) + ((((v335 + ((~(((v337 ^ -1) | (-(v337 ^ -1))) >> 31)) & 2)) - (v338 + ((~(((v339 ^ -1) | (-(v339 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v359[v682] = v356;
      int * v361 = v300->cache_tags;
      int v685 = (int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1);
      v361[v661] = v685;
      int * v363 = v300->cache_dirty;
      v363[v661] = 0;
      int * v365 = v300->cache_age;
      v365[v661] = 1;
      int * v367 = v300->cache_age;
      int v368 = v367[v661];
      int v369 = v367[v637];
      int v689 = v369 + ((int)((unsigned int)(v369 - v368) >> 31));
      v367[v637] = v689;
      int * v371 = v300->cache_age;
      int v372 = v371[v638];
      int v691 = v372 + ((int)((unsigned int)(v372 - v368) >> 31));
      v371[v638] = v691;
      int * v374 = v300->cache_age;
      v374[v661] = 0;
      v377 = v661;
    }
    int * v378 = v300->cache_vals;
    int v694 = v377 * 2;
    int v379 = v378[v694];
    int v695 = (v377 * 2) + 1;
    int v380 = v378[v695];
    int v696 = (((((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1)) & 1) * 2) + ((((v319 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2)) - (v322 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v378[v696] = v379;
    int * v382 = v300->cache_vals;
    int v699 = ((((((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1)) & 1) * 2) + ((((v319 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2)) - (v322 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v382[v699] = v380;
    int * v384 = v300->cache_tags;
    int v702 = ((((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1)) & 1) * 2) + ((((v319 + ((~(((v321 ^ -1) | (-(v321 ^ -1))) >> 31)) & 2)) - (v322 + ((~(((v323 ^ -1) | (-(v323 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v703 = (int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1);
    v384[v702] = v703;
    int * v386 = v300->cache_dirty;
    v386[v702] = 0;
    int * v388 = v300->cache_age;
    v388[v702] = 1;
    int * v390 = v300->cache_age;
    int v391 = v390[v702];
    int v392 = v390[v635];
    int v707 = v392 + ((int)((unsigned int)(v392 - v391) >> 31));
    v390[v635] = v707;
    int * v394 = v300->cache_age;
    int v395 = v394[v636];
    int v709 = v395 + ((int)((unsigned int)(v395 - v391) >> 31));
    v394[v636] = v709;
    int * v397 = v300->cache_age;
    v397[v702] = 0;
    v400 = v702;
  }
  int * v401 = v300->cache_vals;
  int v712 = (v400 * 2) + (((int)((unsigned int)v99 >> 2)) & 1);
  v401[v712] = 0;
  int * v403 = v300->cache_tags;
  int v404 = v403[v637];
  int v405 = v403[v638];
  bool v714 = !(((~(((v404 ^ ((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1))) | (-(v404 ^ ((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1))))) >> 31)) | (~(((v405 ^ ((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1))) | (-(v405 ^ ((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1))))) >> 31))) == 0);
  int v459;
  if (v714) {
    int * v406 = v300->cache_age;
    int v716 = (4 + ((((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1)) & 3) * 2)) + ((~(((v405 ^ ((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1))) | (-(v405 ^ ((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1))))) >> 31)) & 1);
    int v407 = v406[v716];
    int v408 = v406[v637];
    int v717 = v408 + ((int)((unsigned int)(v408 - v407) >> 31));
    v406[v637] = v717;
    int * v410 = v300->cache_age;
    int v411 = v410[v638];
    int v719 = v411 + ((int)((unsigned int)(v411 - v407) >> 31));
    v410[v638] = v719;
    int * v413 = v300->cache_age;
    v413[v716] = 0;
    v459 = v716;
  } else {
    int * v416 = v300->cache_age;
    int v722 = 4 + ((((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1)) & 3) * 2);
    int v417 = v416[v722];
    int * v418 = v300->cache_tags;
    int v419 = v418[v722];
    int v420 = v416[v638];
    int v421 = v418[v638];
    int * v422 = v300->cache_dirty;
    int v725 = (4 + ((((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1)) & 3) * 2)) + ((((v417 + ((~(((v419 ^ -1) | (-(v419 ^ -1))) >> 31)) & 2)) - (v420 + ((~(((v421 ^ -1) | (-(v421 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v423 = v422[v725];
    bool v726 = !(v423 == 0);
    if (v726) {
      int * v424 = v300->cache_tags;
      int v425 = v424[v725];
      int * v426 = v300->cache_vals;
      int v729 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1)) & 3) * 2)) + ((((v417 + ((~(((v419 ^ -1) | (-(v419 ^ -1))) >> 31)) & 2)) - (v420 + ((~(((v421 ^ -1) | (-(v421 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v427 = v426[v729];
      int v730 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1)) & 3) * 2)) + ((((v417 + ((~(((v419 ^ -1) | (-(v419 ^ -1))) >> 31)) & 2)) - (v420 + ((~(((v421 ^ -1) | (-(v421 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v428 = v426[v730];
      int * v429 = v300->mem;
      int v732 = v425 * 2;
      v429[v732] = v427;
      int * v431 = v300->mem;
      int v735 = (v425 * 2) + 1;
      v431[v735] = v428;
      ;
    } else {
      ;
    }
    int * v436 = v300->mem;
    int v740 = ((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1)) * 2;
    int v437 = v436[v740];
    int v741 = (((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1)) * 2) + 1;
    int v438 = v436[v741];
    int * v439 = v300->cache_vals;
    int v743 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1)) & 3) * 2)) + ((((v417 + ((~(((v419 ^ -1) | (-(v419 ^ -1))) >> 31)) & 2)) - (v420 + ((~(((v421 ^ -1) | (-(v421 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v439[v743] = v437;
    int * v441 = v300->cache_vals;
    int v746 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1)) & 3) * 2)) + ((((v417 + ((~(((v419 ^ -1) | (-(v419 ^ -1))) >> 31)) & 2)) - (v420 + ((~(((v421 ^ -1) | (-(v421 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v441[v746] = v438;
    int * v443 = v300->cache_tags;
    int v749 = (int)((unsigned int)((int)((unsigned int)v99 >> 2)) >> 1);
    v443[v725] = v749;
    int * v445 = v300->cache_dirty;
    v445[v725] = 0;
    int * v447 = v300->cache_age;
    v447[v725] = 1;
    int * v449 = v300->cache_age;
    int v450 = v449[v725];
    int v451 = v449[v637];
    int v753 = v451 + ((int)((unsigned int)(v451 - v450) >> 31));
    v449[v637] = v753;
    int * v453 = v300->cache_age;
    int v454 = v453[v638];
    int v755 = v454 + ((int)((unsigned int)(v454 - v450) >> 31));
    v453[v638] = v755;
    int * v456 = v300->cache_age;
    v456[v725] = 0;
    v459 = v725;
  }
  int * v460 = v300->cache_vals;
  int v758 = (v459 * 2) + (((int)((unsigned int)v99 >> 2)) & 1);
  v460[v758] = 0;
  int * v462 = v300->cache_dirty;
  v462[v459] = 1;
  struct StateT2 * v464 = slot_7(v81);
  return v464;
}

struct StateT2 * slot_7(struct StateT2 * v763) {
  struct StateT * v764 = v763->a;
  int v765 = v764->timer;
  struct StateT * v766 = v763->b;
  int v767 = v766->timer;
  bool v994 = v765 == v767;
  squared_assert(v994);
  squared_assume(v994);
  struct StateT * v770 = v763->a;
  int v771 = v770->timer;
  int v996 = v771 + 1;
  v770->timer = v996;
  struct StateT * v773 = v763->b;
  int v774 = v773->timer;
  int v998 = v774 + 1;
  v773->timer = v998;
  struct StateT * v776 = v763->a;
  int * v777 = v776->regs;
  int v778 = v777[6];
  int * v779 = v776->cache_tags;
  int v1003 = (((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1)) & 1) * 2;
  int v780 = v779[v1003];
  int v1004 = ((((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1)) & 1) * 2) + 1;
  int v781 = v779[v1004];
  int v1005 = 4 + ((((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1)) & 3) * 2);
  int v782 = v779[v1005];
  int v1006 = (4 + ((((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v783 = v779[v1006];
  int v784 = v776->timer;
  int v1007 = v784 + ((100 ^ (((~(((v782 ^ ((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1))) | (-(v782 ^ ((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1))))) >> 31)) | (~(((v783 ^ ((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1))) | (-(v783 ^ ((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v780 ^ ((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1))) | (-(v780 ^ ((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1))))) >> 31)) | (~(((v781 ^ ((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1))) | (-(v781 ^ ((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v782 ^ ((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1))) | (-(v782 ^ ((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1))))) >> 31)) | (~(((v783 ^ ((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1))) | (-(v783 ^ ((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1))))) >> 31))) & 104)))));
  v776->timer = v1007;
  int * v786 = v776->cache_vals;
  bool v1008 = !(((~(((v780 ^ ((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1))) | (-(v780 ^ ((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1))))) >> 31)) | (~(((v781 ^ ((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1))) | (-(v781 ^ ((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1))))) >> 31))) == 0);
  int v879;
  if (v1008) {
    int * v787 = v776->cache_age;
    int v1010 = ((((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1)) & 1) * 2) + ((~(((v781 ^ ((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1))) | (-(v781 ^ ((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1))))) >> 31)) & 1);
    int v788 = v787[v1010];
    int v789 = v787[v1003];
    int v1011 = v789 + ((int)((unsigned int)(v789 - v788) >> 31));
    v787[v1003] = v1011;
    int * v791 = v776->cache_age;
    int v792 = v791[v1004];
    int v1013 = v792 + ((int)((unsigned int)(v792 - v788) >> 31));
    v791[v1004] = v1013;
    int * v794 = v776->cache_age;
    v794[v1010] = 0;
    v879 = v1010;
  } else {
    int * v797 = v776->cache_age;
    int v1017 = (((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1)) & 1) * 2;
    int v798 = v797[v1017];
    int * v799 = v776->cache_tags;
    int v800 = v799[v1017];
    int v801 = v797[v1004];
    int v802 = v799[v1004];
    bool v1019 = !(((~(((v782 ^ ((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1))) | (-(v782 ^ ((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1))))) >> 31)) | (~(((v783 ^ ((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1))) | (-(v783 ^ ((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1))))) >> 31))) == 0);
    int v856;
    if (v1019) {
      int * v803 = v776->cache_age;
      int v1021 = (4 + ((((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1)) & 3) * 2)) + ((~(((v783 ^ ((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1))) | (-(v783 ^ ((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1))))) >> 31)) & 1);
      int v804 = v803[v1021];
      int v805 = v803[v1005];
      int v1022 = v805 + ((int)((unsigned int)(v805 - v804) >> 31));
      v803[v1005] = v1022;
      int * v807 = v776->cache_age;
      int v808 = v807[v1006];
      int v1024 = v808 + ((int)((unsigned int)(v808 - v804) >> 31));
      v807[v1006] = v1024;
      int * v810 = v776->cache_age;
      v810[v1021] = 0;
      v856 = v1021;
    } else {
      int * v813 = v776->cache_age;
      int v1028 = 4 + ((((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1)) & 3) * 2);
      int v814 = v813[v1028];
      int * v815 = v776->cache_tags;
      int v816 = v815[v1028];
      int v817 = v813[v1006];
      int v818 = v815[v1006];
      int * v819 = v776->cache_dirty;
      int v1031 = (4 + ((((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1)) & 3) * 2)) + ((((v814 + ((~(((v816 ^ -1) | (-(v816 ^ -1))) >> 31)) & 2)) - (v817 + ((~(((v818 ^ -1) | (-(v818 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v820 = v819[v1031];
      bool v1032 = !(v820 == 0);
      if (v1032) {
        int * v821 = v776->cache_tags;
        int v822 = v821[v1031];
        int * v823 = v776->cache_vals;
        int v1035 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1)) & 3) * 2)) + ((((v814 + ((~(((v816 ^ -1) | (-(v816 ^ -1))) >> 31)) & 2)) - (v817 + ((~(((v818 ^ -1) | (-(v818 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v824 = v823[v1035];
        int v1036 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1)) & 3) * 2)) + ((((v814 + ((~(((v816 ^ -1) | (-(v816 ^ -1))) >> 31)) & 2)) - (v817 + ((~(((v818 ^ -1) | (-(v818 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v825 = v823[v1036];
        int * v826 = v776->mem;
        int v1038 = v822 * 2;
        v826[v1038] = v824;
        int * v828 = v776->mem;
        int v1041 = (v822 * 2) + 1;
        v828[v1041] = v825;
        ;
      } else {
        ;
      }
      int * v833 = v776->mem;
      int v1046 = ((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1)) * 2;
      int v834 = v833[v1046];
      int v1047 = (((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1)) * 2) + 1;
      int v835 = v833[v1047];
      int * v836 = v776->cache_vals;
      int v1049 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1)) & 3) * 2)) + ((((v814 + ((~(((v816 ^ -1) | (-(v816 ^ -1))) >> 31)) & 2)) - (v817 + ((~(((v818 ^ -1) | (-(v818 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v836[v1049] = v834;
      int * v838 = v776->cache_vals;
      int v1052 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1)) & 3) * 2)) + ((((v814 + ((~(((v816 ^ -1) | (-(v816 ^ -1))) >> 31)) & 2)) - (v817 + ((~(((v818 ^ -1) | (-(v818 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v838[v1052] = v835;
      int * v840 = v776->cache_tags;
      int v1055 = (int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1);
      v840[v1031] = v1055;
      int * v842 = v776->cache_dirty;
      v842[v1031] = 0;
      int * v844 = v776->cache_age;
      v844[v1031] = 1;
      int * v846 = v776->cache_age;
      int v847 = v846[v1031];
      int v848 = v846[v1005];
      int v1061 = v848 + ((int)((unsigned int)(v848 - v847) >> 31));
      v846[v1005] = v1061;
      int * v850 = v776->cache_age;
      int v851 = v850[v1006];
      int v1063 = v851 + ((int)((unsigned int)(v851 - v847) >> 31));
      v850[v1006] = v1063;
      int * v853 = v776->cache_age;
      v853[v1031] = 0;
      v856 = v1031;
    }
    int * v857 = v776->cache_vals;
    int v1066 = v856 * 2;
    int v858 = v857[v1066];
    int v1067 = (v856 * 2) + 1;
    int v859 = v857[v1067];
    int v1068 = (((((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1)) & 1) * 2) + ((((v798 + ((~(((v800 ^ -1) | (-(v800 ^ -1))) >> 31)) & 2)) - (v801 + ((~(((v802 ^ -1) | (-(v802 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v857[v1068] = v858;
    int * v861 = v776->cache_vals;
    int v1071 = ((((((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1)) & 1) * 2) + ((((v798 + ((~(((v800 ^ -1) | (-(v800 ^ -1))) >> 31)) & 2)) - (v801 + ((~(((v802 ^ -1) | (-(v802 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v861[v1071] = v859;
    int * v863 = v776->cache_tags;
    int v1074 = ((((int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1)) & 1) * 2) + ((((v798 + ((~(((v800 ^ -1) | (-(v800 ^ -1))) >> 31)) & 2)) - (v801 + ((~(((v802 ^ -1) | (-(v802 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1075 = (int)((unsigned int)((int)((unsigned int)v778 >> 2)) >> 1);
    v863[v1074] = v1075;
    int * v865 = v776->cache_dirty;
    v865[v1074] = 0;
    int * v867 = v776->cache_age;
    v867[v1074] = 1;
    int * v869 = v776->cache_age;
    int v870 = v869[v1074];
    int v871 = v869[v1003];
    int v1081 = v871 + ((int)((unsigned int)(v871 - v870) >> 31));
    v869[v1003] = v1081;
    int * v873 = v776->cache_age;
    int v874 = v873[v1004];
    int v1083 = v874 + ((int)((unsigned int)(v874 - v870) >> 31));
    v873[v1004] = v1083;
    int * v876 = v776->cache_age;
    v876[v1074] = 0;
    v879 = v1074;
  }
  int v1086 = (v879 * 2) + (((int)((unsigned int)v778 >> 2)) & 1);
  int v880 = v786[v1086];
  int * v881 = v776->regs;
  v881[11] = v880;
  struct StateT * v883 = v763->b;
  int * v884 = v883->regs;
  int v885 = v884[6];
  int * v886 = v883->cache_tags;
  int v1093 = (((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1)) & 1) * 2;
  int v887 = v886[v1093];
  int v1094 = ((((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1)) & 1) * 2) + 1;
  int v888 = v886[v1094];
  int v1095 = 4 + ((((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1)) & 3) * 2);
  int v889 = v886[v1095];
  int v1096 = (4 + ((((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v890 = v886[v1096];
  int v891 = v883->timer;
  int v1097 = v891 + ((100 ^ (((~(((v889 ^ ((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1))) | (-(v889 ^ ((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1))))) >> 31)) | (~(((v890 ^ ((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1))) | (-(v890 ^ ((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v887 ^ ((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1))) | (-(v887 ^ ((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1))))) >> 31)) | (~(((v888 ^ ((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1))) | (-(v888 ^ ((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v889 ^ ((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1))) | (-(v889 ^ ((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1))))) >> 31)) | (~(((v890 ^ ((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1))) | (-(v890 ^ ((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1))))) >> 31))) & 104)))));
  v883->timer = v1097;
  int * v893 = v883->cache_vals;
  bool v1098 = !(((~(((v887 ^ ((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1))) | (-(v887 ^ ((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1))))) >> 31)) | (~(((v888 ^ ((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1))) | (-(v888 ^ ((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1))))) >> 31))) == 0);
  int v986;
  if (v1098) {
    int * v894 = v883->cache_age;
    int v1100 = ((((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1)) & 1) * 2) + ((~(((v888 ^ ((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1))) | (-(v888 ^ ((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1))))) >> 31)) & 1);
    int v895 = v894[v1100];
    int v896 = v894[v1093];
    int v1101 = v896 + ((int)((unsigned int)(v896 - v895) >> 31));
    v894[v1093] = v1101;
    int * v898 = v883->cache_age;
    int v899 = v898[v1094];
    int v1103 = v899 + ((int)((unsigned int)(v899 - v895) >> 31));
    v898[v1094] = v1103;
    int * v901 = v883->cache_age;
    v901[v1100] = 0;
    v986 = v1100;
  } else {
    int * v904 = v883->cache_age;
    int v1107 = (((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1)) & 1) * 2;
    int v905 = v904[v1107];
    int * v906 = v883->cache_tags;
    int v907 = v906[v1107];
    int v908 = v904[v1094];
    int v909 = v906[v1094];
    bool v1109 = !(((~(((v889 ^ ((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1))) | (-(v889 ^ ((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1))))) >> 31)) | (~(((v890 ^ ((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1))) | (-(v890 ^ ((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1))))) >> 31))) == 0);
    int v963;
    if (v1109) {
      int * v910 = v883->cache_age;
      int v1111 = (4 + ((((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1)) & 3) * 2)) + ((~(((v890 ^ ((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1))) | (-(v890 ^ ((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1))))) >> 31)) & 1);
      int v911 = v910[v1111];
      int v912 = v910[v1095];
      int v1112 = v912 + ((int)((unsigned int)(v912 - v911) >> 31));
      v910[v1095] = v1112;
      int * v914 = v883->cache_age;
      int v915 = v914[v1096];
      int v1114 = v915 + ((int)((unsigned int)(v915 - v911) >> 31));
      v914[v1096] = v1114;
      int * v917 = v883->cache_age;
      v917[v1111] = 0;
      v963 = v1111;
    } else {
      int * v920 = v883->cache_age;
      int v1118 = 4 + ((((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1)) & 3) * 2);
      int v921 = v920[v1118];
      int * v922 = v883->cache_tags;
      int v923 = v922[v1118];
      int v924 = v920[v1096];
      int v925 = v922[v1096];
      int * v926 = v883->cache_dirty;
      int v1121 = (4 + ((((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1)) & 3) * 2)) + ((((v921 + ((~(((v923 ^ -1) | (-(v923 ^ -1))) >> 31)) & 2)) - (v924 + ((~(((v925 ^ -1) | (-(v925 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v927 = v926[v1121];
      bool v1122 = !(v927 == 0);
      if (v1122) {
        int * v928 = v883->cache_tags;
        int v929 = v928[v1121];
        int * v930 = v883->cache_vals;
        int v1125 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1)) & 3) * 2)) + ((((v921 + ((~(((v923 ^ -1) | (-(v923 ^ -1))) >> 31)) & 2)) - (v924 + ((~(((v925 ^ -1) | (-(v925 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v931 = v930[v1125];
        int v1126 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1)) & 3) * 2)) + ((((v921 + ((~(((v923 ^ -1) | (-(v923 ^ -1))) >> 31)) & 2)) - (v924 + ((~(((v925 ^ -1) | (-(v925 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v932 = v930[v1126];
        int * v933 = v883->mem;
        int v1128 = v929 * 2;
        v933[v1128] = v931;
        int * v935 = v883->mem;
        int v1131 = (v929 * 2) + 1;
        v935[v1131] = v932;
        ;
      } else {
        ;
      }
      int * v940 = v883->mem;
      int v1136 = ((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1)) * 2;
      int v941 = v940[v1136];
      int v1137 = (((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1)) * 2) + 1;
      int v942 = v940[v1137];
      int * v943 = v883->cache_vals;
      int v1139 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1)) & 3) * 2)) + ((((v921 + ((~(((v923 ^ -1) | (-(v923 ^ -1))) >> 31)) & 2)) - (v924 + ((~(((v925 ^ -1) | (-(v925 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v943[v1139] = v941;
      int * v945 = v883->cache_vals;
      int v1142 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1)) & 3) * 2)) + ((((v921 + ((~(((v923 ^ -1) | (-(v923 ^ -1))) >> 31)) & 2)) - (v924 + ((~(((v925 ^ -1) | (-(v925 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v945[v1142] = v942;
      int * v947 = v883->cache_tags;
      int v1145 = (int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1);
      v947[v1121] = v1145;
      int * v949 = v883->cache_dirty;
      v949[v1121] = 0;
      int * v951 = v883->cache_age;
      v951[v1121] = 1;
      int * v953 = v883->cache_age;
      int v954 = v953[v1121];
      int v955 = v953[v1095];
      int v1151 = v955 + ((int)((unsigned int)(v955 - v954) >> 31));
      v953[v1095] = v1151;
      int * v957 = v883->cache_age;
      int v958 = v957[v1096];
      int v1153 = v958 + ((int)((unsigned int)(v958 - v954) >> 31));
      v957[v1096] = v1153;
      int * v960 = v883->cache_age;
      v960[v1121] = 0;
      v963 = v1121;
    }
    int * v964 = v883->cache_vals;
    int v1156 = v963 * 2;
    int v965 = v964[v1156];
    int v1157 = (v963 * 2) + 1;
    int v966 = v964[v1157];
    int v1158 = (((((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1)) & 1) * 2) + ((((v905 + ((~(((v907 ^ -1) | (-(v907 ^ -1))) >> 31)) & 2)) - (v908 + ((~(((v909 ^ -1) | (-(v909 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v964[v1158] = v965;
    int * v968 = v883->cache_vals;
    int v1161 = ((((((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1)) & 1) * 2) + ((((v905 + ((~(((v907 ^ -1) | (-(v907 ^ -1))) >> 31)) & 2)) - (v908 + ((~(((v909 ^ -1) | (-(v909 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v968[v1161] = v966;
    int * v970 = v883->cache_tags;
    int v1164 = ((((int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1)) & 1) * 2) + ((((v905 + ((~(((v907 ^ -1) | (-(v907 ^ -1))) >> 31)) & 2)) - (v908 + ((~(((v909 ^ -1) | (-(v909 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1165 = (int)((unsigned int)((int)((unsigned int)v885 >> 2)) >> 1);
    v970[v1164] = v1165;
    int * v972 = v883->cache_dirty;
    v972[v1164] = 0;
    int * v974 = v883->cache_age;
    v974[v1164] = 1;
    int * v976 = v883->cache_age;
    int v977 = v976[v1164];
    int v978 = v976[v1093];
    int v1171 = v978 + ((int)((unsigned int)(v978 - v977) >> 31));
    v976[v1093] = v1171;
    int * v980 = v883->cache_age;
    int v981 = v980[v1094];
    int v1173 = v981 + ((int)((unsigned int)(v981 - v977) >> 31));
    v980[v1094] = v1173;
    int * v983 = v883->cache_age;
    v983[v1164] = 0;
    v986 = v1164;
  }
  int v1176 = (v986 * 2) + (((int)((unsigned int)v885 >> 2)) & 1);
  int v987 = v893[v1176];
  int * v988 = v883->regs;
  v988[11] = v987;
  struct StateT2 * v990 = slot_8(v763);
  return v990;
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