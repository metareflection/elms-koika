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
struct StateT2 * slot_4(struct StateT2 * v1123);
struct StateT2 * slot_2(struct StateT2 * v81);
struct StateT2 * slot_3(struct StateT2 * v705);
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

struct StateT2 * slot_4(struct StateT2 * v1123) {
  struct StateT * v1124 = v1123->a;
  int v1125 = v1124->timer;
  struct StateT * v1126 = v1123->b;
  int v1127 = v1126->timer;
  bool v1353 = v1125 == v1127;
  squared_assert(v1353);
  squared_assume(v1353);
  struct StateT * v1130 = v1123->a;
  int v1131 = v1130->timer;
  int v1355 = v1131 + 1;
  v1130->timer = v1355;
  struct StateT * v1133 = v1123->b;
  int v1134 = v1133->timer;
  int v1357 = v1134 + 1;
  v1133->timer = v1357;
  struct StateT * v1136 = v1123->a;
  int * v1137 = v1136->regs;
  int v1138 = v1137[11];
  int * v1139 = v1136->cache_tags;
  int v1362 = (((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1)) & 1) * 2;
  int v1140 = v1139[v1362];
  int v1363 = ((((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1141 = v1139[v1363];
  int v1364 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1)) & 3) * 2);
  int v1142 = v1139[v1364];
  int v1365 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1143 = v1139[v1365];
  int v1144 = v1136->timer;
  int v1366 = v1144 + ((100 ^ (((~(((v1142 ^ ((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1))) | (-(v1142 ^ ((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1))))) >> 31)) | (~(((v1143 ^ ((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1))) | (-(v1143 ^ ((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1140 ^ ((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1))) | (-(v1140 ^ ((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1))))) >> 31)) | (~(((v1141 ^ ((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1))) | (-(v1141 ^ ((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1142 ^ ((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1))) | (-(v1142 ^ ((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1))))) >> 31)) | (~(((v1143 ^ ((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1))) | (-(v1143 ^ ((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1136->timer = v1366;
  int * v1146 = v1136->cache_vals;
  bool v1367 = !(((~(((v1140 ^ ((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1))) | (-(v1140 ^ ((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1))))) >> 31)) | (~(((v1141 ^ ((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1))) | (-(v1141 ^ ((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1))))) >> 31))) == 0);
  int v1239;
  if (v1367) {
    int * v1147 = v1136->cache_age;
    int v1369 = ((((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1)) & 1) * 2) + ((~(((v1141 ^ ((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1))) | (-(v1141 ^ ((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1))))) >> 31)) & 1);
    int v1148 = v1147[v1369];
    int v1149 = v1147[v1362];
    int v1370 = v1149 + ((int)((unsigned int)(v1149 - v1148) >> 31));
    v1147[v1362] = v1370;
    int * v1151 = v1136->cache_age;
    int v1152 = v1151[v1363];
    int v1372 = v1152 + ((int)((unsigned int)(v1152 - v1148) >> 31));
    v1151[v1363] = v1372;
    int * v1154 = v1136->cache_age;
    v1154[v1369] = 0;
    v1239 = v1369;
  } else {
    int * v1157 = v1136->cache_age;
    int v1376 = (((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1)) & 1) * 2;
    int v1158 = v1157[v1376];
    int * v1159 = v1136->cache_tags;
    int v1160 = v1159[v1376];
    int v1161 = v1157[v1363];
    int v1162 = v1159[v1363];
    bool v1378 = !(((~(((v1142 ^ ((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1))) | (-(v1142 ^ ((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1))))) >> 31)) | (~(((v1143 ^ ((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1))) | (-(v1143 ^ ((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1))))) >> 31))) == 0);
    int v1216;
    if (v1378) {
      int * v1163 = v1136->cache_age;
      int v1380 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1143 ^ ((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1))) | (-(v1143 ^ ((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1))))) >> 31)) & 1);
      int v1164 = v1163[v1380];
      int v1165 = v1163[v1364];
      int v1381 = v1165 + ((int)((unsigned int)(v1165 - v1164) >> 31));
      v1163[v1364] = v1381;
      int * v1167 = v1136->cache_age;
      int v1168 = v1167[v1365];
      int v1383 = v1168 + ((int)((unsigned int)(v1168 - v1164) >> 31));
      v1167[v1365] = v1383;
      int * v1170 = v1136->cache_age;
      v1170[v1380] = 0;
      v1216 = v1380;
    } else {
      int * v1173 = v1136->cache_age;
      int v1387 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1)) & 3) * 2);
      int v1174 = v1173[v1387];
      int * v1175 = v1136->cache_tags;
      int v1176 = v1175[v1387];
      int v1177 = v1173[v1365];
      int v1178 = v1175[v1365];
      int * v1179 = v1136->cache_dirty;
      int v1390 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1)) & 3) * 2)) + ((((v1174 + ((~(((v1176 ^ -1) | (-(v1176 ^ -1))) >> 31)) & 2)) - (v1177 + ((~(((v1178 ^ -1) | (-(v1178 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1180 = v1179[v1390];
      bool v1391 = !(v1180 == 0);
      if (v1391) {
        int * v1181 = v1136->cache_tags;
        int v1182 = v1181[v1390];
        int * v1183 = v1136->cache_vals;
        int v1394 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1)) & 3) * 2)) + ((((v1174 + ((~(((v1176 ^ -1) | (-(v1176 ^ -1))) >> 31)) & 2)) - (v1177 + ((~(((v1178 ^ -1) | (-(v1178 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1184 = v1183[v1394];
        int v1395 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1)) & 3) * 2)) + ((((v1174 + ((~(((v1176 ^ -1) | (-(v1176 ^ -1))) >> 31)) & 2)) - (v1177 + ((~(((v1178 ^ -1) | (-(v1178 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1185 = v1183[v1395];
        int * v1186 = v1136->mem;
        int v1397 = v1182 * 2;
        v1186[v1397] = v1184;
        int * v1188 = v1136->mem;
        int v1400 = (v1182 * 2) + 1;
        v1188[v1400] = v1185;
        ;
      } else {
        ;
      }
      int * v1193 = v1136->mem;
      int v1405 = ((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1)) * 2;
      int v1194 = v1193[v1405];
      int v1406 = (((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1)) * 2) + 1;
      int v1195 = v1193[v1406];
      int * v1196 = v1136->cache_vals;
      int v1408 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1)) & 3) * 2)) + ((((v1174 + ((~(((v1176 ^ -1) | (-(v1176 ^ -1))) >> 31)) & 2)) - (v1177 + ((~(((v1178 ^ -1) | (-(v1178 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1196[v1408] = v1194;
      int * v1198 = v1136->cache_vals;
      int v1411 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1)) & 3) * 2)) + ((((v1174 + ((~(((v1176 ^ -1) | (-(v1176 ^ -1))) >> 31)) & 2)) - (v1177 + ((~(((v1178 ^ -1) | (-(v1178 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1198[v1411] = v1195;
      int * v1200 = v1136->cache_tags;
      int v1414 = (int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1);
      v1200[v1390] = v1414;
      int * v1202 = v1136->cache_dirty;
      v1202[v1390] = 0;
      int * v1204 = v1136->cache_age;
      v1204[v1390] = 1;
      int * v1206 = v1136->cache_age;
      int v1207 = v1206[v1390];
      int v1208 = v1206[v1364];
      int v1420 = v1208 + ((int)((unsigned int)(v1208 - v1207) >> 31));
      v1206[v1364] = v1420;
      int * v1210 = v1136->cache_age;
      int v1211 = v1210[v1365];
      int v1422 = v1211 + ((int)((unsigned int)(v1211 - v1207) >> 31));
      v1210[v1365] = v1422;
      int * v1213 = v1136->cache_age;
      v1213[v1390] = 0;
      v1216 = v1390;
    }
    int * v1217 = v1136->cache_vals;
    int v1425 = v1216 * 2;
    int v1218 = v1217[v1425];
    int v1426 = (v1216 * 2) + 1;
    int v1219 = v1217[v1426];
    int v1427 = (((((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1)) & 1) * 2) + ((((v1158 + ((~(((v1160 ^ -1) | (-(v1160 ^ -1))) >> 31)) & 2)) - (v1161 + ((~(((v1162 ^ -1) | (-(v1162 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1217[v1427] = v1218;
    int * v1221 = v1136->cache_vals;
    int v1430 = ((((((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1)) & 1) * 2) + ((((v1158 + ((~(((v1160 ^ -1) | (-(v1160 ^ -1))) >> 31)) & 2)) - (v1161 + ((~(((v1162 ^ -1) | (-(v1162 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1221[v1430] = v1219;
    int * v1223 = v1136->cache_tags;
    int v1433 = ((((int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1)) & 1) * 2) + ((((v1158 + ((~(((v1160 ^ -1) | (-(v1160 ^ -1))) >> 31)) & 2)) - (v1161 + ((~(((v1162 ^ -1) | (-(v1162 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1434 = (int)((unsigned int)((int)((unsigned int)v1138 >> 2)) >> 1);
    v1223[v1433] = v1434;
    int * v1225 = v1136->cache_dirty;
    v1225[v1433] = 0;
    int * v1227 = v1136->cache_age;
    v1227[v1433] = 1;
    int * v1229 = v1136->cache_age;
    int v1230 = v1229[v1433];
    int v1231 = v1229[v1362];
    int v1440 = v1231 + ((int)((unsigned int)(v1231 - v1230) >> 31));
    v1229[v1362] = v1440;
    int * v1233 = v1136->cache_age;
    int v1234 = v1233[v1363];
    int v1442 = v1234 + ((int)((unsigned int)(v1234 - v1230) >> 31));
    v1233[v1363] = v1442;
    int * v1236 = v1136->cache_age;
    v1236[v1433] = 0;
    v1239 = v1433;
  }
  int v1445 = (v1239 * 2) + (((int)((unsigned int)v1138 >> 2)) & 1);
  int v1240 = v1146[v1445];
  int * v1241 = v1136->regs;
  v1241[12] = v1240;
  struct StateT * v1243 = v1123->b;
  int * v1244 = v1243->regs;
  int v1245 = v1244[11];
  int * v1246 = v1243->cache_tags;
  int v1452 = (((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1)) & 1) * 2;
  int v1247 = v1246[v1452];
  int v1453 = ((((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1248 = v1246[v1453];
  int v1454 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1)) & 3) * 2);
  int v1249 = v1246[v1454];
  int v1455 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1250 = v1246[v1455];
  int v1251 = v1243->timer;
  int v1456 = v1251 + ((100 ^ (((~(((v1249 ^ ((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1))) | (-(v1249 ^ ((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1))))) >> 31)) | (~(((v1250 ^ ((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1))) | (-(v1250 ^ ((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1247 ^ ((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1))) | (-(v1247 ^ ((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1))))) >> 31)) | (~(((v1248 ^ ((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1))) | (-(v1248 ^ ((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1249 ^ ((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1))) | (-(v1249 ^ ((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1))))) >> 31)) | (~(((v1250 ^ ((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1))) | (-(v1250 ^ ((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1243->timer = v1456;
  int * v1253 = v1243->cache_vals;
  bool v1457 = !(((~(((v1247 ^ ((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1))) | (-(v1247 ^ ((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1))))) >> 31)) | (~(((v1248 ^ ((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1))) | (-(v1248 ^ ((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1))))) >> 31))) == 0);
  int v1346;
  if (v1457) {
    int * v1254 = v1243->cache_age;
    int v1459 = ((((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1)) & 1) * 2) + ((~(((v1248 ^ ((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1))) | (-(v1248 ^ ((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1))))) >> 31)) & 1);
    int v1255 = v1254[v1459];
    int v1256 = v1254[v1452];
    int v1460 = v1256 + ((int)((unsigned int)(v1256 - v1255) >> 31));
    v1254[v1452] = v1460;
    int * v1258 = v1243->cache_age;
    int v1259 = v1258[v1453];
    int v1462 = v1259 + ((int)((unsigned int)(v1259 - v1255) >> 31));
    v1258[v1453] = v1462;
    int * v1261 = v1243->cache_age;
    v1261[v1459] = 0;
    v1346 = v1459;
  } else {
    int * v1264 = v1243->cache_age;
    int v1466 = (((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1)) & 1) * 2;
    int v1265 = v1264[v1466];
    int * v1266 = v1243->cache_tags;
    int v1267 = v1266[v1466];
    int v1268 = v1264[v1453];
    int v1269 = v1266[v1453];
    bool v1468 = !(((~(((v1249 ^ ((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1))) | (-(v1249 ^ ((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1))))) >> 31)) | (~(((v1250 ^ ((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1))) | (-(v1250 ^ ((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1))))) >> 31))) == 0);
    int v1323;
    if (v1468) {
      int * v1270 = v1243->cache_age;
      int v1470 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1250 ^ ((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1))) | (-(v1250 ^ ((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1))))) >> 31)) & 1);
      int v1271 = v1270[v1470];
      int v1272 = v1270[v1454];
      int v1471 = v1272 + ((int)((unsigned int)(v1272 - v1271) >> 31));
      v1270[v1454] = v1471;
      int * v1274 = v1243->cache_age;
      int v1275 = v1274[v1455];
      int v1473 = v1275 + ((int)((unsigned int)(v1275 - v1271) >> 31));
      v1274[v1455] = v1473;
      int * v1277 = v1243->cache_age;
      v1277[v1470] = 0;
      v1323 = v1470;
    } else {
      int * v1280 = v1243->cache_age;
      int v1477 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1)) & 3) * 2);
      int v1281 = v1280[v1477];
      int * v1282 = v1243->cache_tags;
      int v1283 = v1282[v1477];
      int v1284 = v1280[v1455];
      int v1285 = v1282[v1455];
      int * v1286 = v1243->cache_dirty;
      int v1480 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1)) & 3) * 2)) + ((((v1281 + ((~(((v1283 ^ -1) | (-(v1283 ^ -1))) >> 31)) & 2)) - (v1284 + ((~(((v1285 ^ -1) | (-(v1285 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1287 = v1286[v1480];
      bool v1481 = !(v1287 == 0);
      if (v1481) {
        int * v1288 = v1243->cache_tags;
        int v1289 = v1288[v1480];
        int * v1290 = v1243->cache_vals;
        int v1484 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1)) & 3) * 2)) + ((((v1281 + ((~(((v1283 ^ -1) | (-(v1283 ^ -1))) >> 31)) & 2)) - (v1284 + ((~(((v1285 ^ -1) | (-(v1285 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1291 = v1290[v1484];
        int v1485 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1)) & 3) * 2)) + ((((v1281 + ((~(((v1283 ^ -1) | (-(v1283 ^ -1))) >> 31)) & 2)) - (v1284 + ((~(((v1285 ^ -1) | (-(v1285 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1292 = v1290[v1485];
        int * v1293 = v1243->mem;
        int v1487 = v1289 * 2;
        v1293[v1487] = v1291;
        int * v1295 = v1243->mem;
        int v1490 = (v1289 * 2) + 1;
        v1295[v1490] = v1292;
        ;
      } else {
        ;
      }
      int * v1300 = v1243->mem;
      int v1495 = ((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1)) * 2;
      int v1301 = v1300[v1495];
      int v1496 = (((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1)) * 2) + 1;
      int v1302 = v1300[v1496];
      int * v1303 = v1243->cache_vals;
      int v1498 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1)) & 3) * 2)) + ((((v1281 + ((~(((v1283 ^ -1) | (-(v1283 ^ -1))) >> 31)) & 2)) - (v1284 + ((~(((v1285 ^ -1) | (-(v1285 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1303[v1498] = v1301;
      int * v1305 = v1243->cache_vals;
      int v1501 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1)) & 3) * 2)) + ((((v1281 + ((~(((v1283 ^ -1) | (-(v1283 ^ -1))) >> 31)) & 2)) - (v1284 + ((~(((v1285 ^ -1) | (-(v1285 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1305[v1501] = v1302;
      int * v1307 = v1243->cache_tags;
      int v1504 = (int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1);
      v1307[v1480] = v1504;
      int * v1309 = v1243->cache_dirty;
      v1309[v1480] = 0;
      int * v1311 = v1243->cache_age;
      v1311[v1480] = 1;
      int * v1313 = v1243->cache_age;
      int v1314 = v1313[v1480];
      int v1315 = v1313[v1454];
      int v1510 = v1315 + ((int)((unsigned int)(v1315 - v1314) >> 31));
      v1313[v1454] = v1510;
      int * v1317 = v1243->cache_age;
      int v1318 = v1317[v1455];
      int v1512 = v1318 + ((int)((unsigned int)(v1318 - v1314) >> 31));
      v1317[v1455] = v1512;
      int * v1320 = v1243->cache_age;
      v1320[v1480] = 0;
      v1323 = v1480;
    }
    int * v1324 = v1243->cache_vals;
    int v1515 = v1323 * 2;
    int v1325 = v1324[v1515];
    int v1516 = (v1323 * 2) + 1;
    int v1326 = v1324[v1516];
    int v1517 = (((((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1)) & 1) * 2) + ((((v1265 + ((~(((v1267 ^ -1) | (-(v1267 ^ -1))) >> 31)) & 2)) - (v1268 + ((~(((v1269 ^ -1) | (-(v1269 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1324[v1517] = v1325;
    int * v1328 = v1243->cache_vals;
    int v1520 = ((((((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1)) & 1) * 2) + ((((v1265 + ((~(((v1267 ^ -1) | (-(v1267 ^ -1))) >> 31)) & 2)) - (v1268 + ((~(((v1269 ^ -1) | (-(v1269 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1328[v1520] = v1326;
    int * v1330 = v1243->cache_tags;
    int v1523 = ((((int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1)) & 1) * 2) + ((((v1265 + ((~(((v1267 ^ -1) | (-(v1267 ^ -1))) >> 31)) & 2)) - (v1268 + ((~(((v1269 ^ -1) | (-(v1269 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1524 = (int)((unsigned int)((int)((unsigned int)v1245 >> 2)) >> 1);
    v1330[v1523] = v1524;
    int * v1332 = v1243->cache_dirty;
    v1332[v1523] = 0;
    int * v1334 = v1243->cache_age;
    v1334[v1523] = 1;
    int * v1336 = v1243->cache_age;
    int v1337 = v1336[v1523];
    int v1338 = v1336[v1452];
    int v1530 = v1338 + ((int)((unsigned int)(v1338 - v1337) >> 31));
    v1336[v1452] = v1530;
    int * v1340 = v1243->cache_age;
    int v1341 = v1340[v1453];
    int v1532 = v1341 + ((int)((unsigned int)(v1341 - v1337) >> 31));
    v1340[v1453] = v1532;
    int * v1343 = v1243->cache_age;
    v1343[v1523] = 0;
    v1346 = v1523;
  }
  int v1535 = (v1346 * 2) + (((int)((unsigned int)v1245 >> 2)) & 1);
  int v1347 = v1253[v1535];
  int * v1348 = v1243->regs;
  v1348[12] = v1347;
  return v1123;
}

struct StateT2 * slot_2(struct StateT2 * v81) {
  struct StateT * v82 = v81->a;
  int v83 = v82->timer;
  struct StateT * v84 = v81->b;
  int v85 = v84->timer;
  bool v430 = v83 == v85;
  squared_assert(v430);
  squared_assume(v430);
  struct StateT * v88 = v81->a;
  int v89 = v88->timer;
  int v432 = v89 + 1;
  v88->timer = v432;
  struct StateT * v91 = v81->b;
  int v92 = v91->timer;
  int v434 = v92 + 1;
  v91->timer = v434;
  struct StateT * v94 = v81->a;
  int * v95 = v94->regs;
  int v96 = v95[6];
  int * v97 = v94->cache_tags;
  int v439 = (((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 1) * 2;
  int v98 = v97[v439];
  int v440 = ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 1) * 2) + 1;
  int v99 = v97[v440];
  int v441 = 4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2);
  int v100 = v97[v441];
  int v442 = (4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v101 = v97[v442];
  int v102 = v94->timer;
  int v443 = v102 + ((100 ^ (((~(((v100 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v100 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31)) | (~(((v101 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v101 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v98 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v98 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31)) | (~(((v99 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v99 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v100 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v100 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31)) | (~(((v101 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v101 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31))) & 104)))));
  v94->timer = v443;
  bool v444 = !(((~(((v98 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v98 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31)) | (~(((v99 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v99 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31))) == 0);
  int v196;
  if (v444) {
    int * v104 = v94->cache_age;
    int v446 = ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 1) * 2) + ((~(((v99 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v99 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31)) & 1);
    int v105 = v104[v446];
    int v106 = v104[v439];
    int v447 = v106 + ((int)((unsigned int)(v106 - v105) >> 31));
    v104[v439] = v447;
    int * v108 = v94->cache_age;
    int v109 = v108[v440];
    int v449 = v109 + ((int)((unsigned int)(v109 - v105) >> 31));
    v108[v440] = v449;
    int * v111 = v94->cache_age;
    v111[v446] = 0;
    v196 = v446;
  } else {
    int * v114 = v94->cache_age;
    int v453 = (((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 1) * 2;
    int v115 = v114[v453];
    int * v116 = v94->cache_tags;
    int v117 = v116[v453];
    int v118 = v114[v440];
    int v119 = v116[v440];
    bool v455 = !(((~(((v100 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v100 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31)) | (~(((v101 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v101 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31))) == 0);
    int v173;
    if (v455) {
      int * v120 = v94->cache_age;
      int v457 = (4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + ((~(((v101 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v101 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31)) & 1);
      int v121 = v120[v457];
      int v122 = v120[v441];
      int v458 = v122 + ((int)((unsigned int)(v122 - v121) >> 31));
      v120[v441] = v458;
      int * v124 = v94->cache_age;
      int v125 = v124[v442];
      int v460 = v125 + ((int)((unsigned int)(v125 - v121) >> 31));
      v124[v442] = v460;
      int * v127 = v94->cache_age;
      v127[v457] = 0;
      v173 = v457;
    } else {
      int * v130 = v94->cache_age;
      int v464 = 4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2);
      int v131 = v130[v464];
      int * v132 = v94->cache_tags;
      int v133 = v132[v464];
      int v134 = v130[v442];
      int v135 = v132[v442];
      int * v136 = v94->cache_dirty;
      int v467 = (4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + ((((v131 + ((~(((v133 ^ -1) | (-(v133 ^ -1))) >> 31)) & 2)) - (v134 + ((~(((v135 ^ -1) | (-(v135 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v137 = v136[v467];
      bool v468 = !(v137 == 0);
      if (v468) {
        int * v138 = v94->cache_tags;
        int v139 = v138[v467];
        int * v140 = v94->cache_vals;
        int v471 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + ((((v131 + ((~(((v133 ^ -1) | (-(v133 ^ -1))) >> 31)) & 2)) - (v134 + ((~(((v135 ^ -1) | (-(v135 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v141 = v140[v471];
        int v472 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + ((((v131 + ((~(((v133 ^ -1) | (-(v133 ^ -1))) >> 31)) & 2)) - (v134 + ((~(((v135 ^ -1) | (-(v135 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v142 = v140[v472];
        int * v143 = v94->mem;
        int v474 = v139 * 2;
        v143[v474] = v141;
        int * v145 = v94->mem;
        int v477 = (v139 * 2) + 1;
        v145[v477] = v142;
        ;
      } else {
        ;
      }
      int * v150 = v94->mem;
      int v482 = ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) * 2;
      int v151 = v150[v482];
      int v483 = (((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) * 2) + 1;
      int v152 = v150[v483];
      int * v153 = v94->cache_vals;
      int v485 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + ((((v131 + ((~(((v133 ^ -1) | (-(v133 ^ -1))) >> 31)) & 2)) - (v134 + ((~(((v135 ^ -1) | (-(v135 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v153[v485] = v151;
      int * v155 = v94->cache_vals;
      int v488 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + ((((v131 + ((~(((v133 ^ -1) | (-(v133 ^ -1))) >> 31)) & 2)) - (v134 + ((~(((v135 ^ -1) | (-(v135 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v155[v488] = v152;
      int * v157 = v94->cache_tags;
      int v491 = (int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1);
      v157[v467] = v491;
      int * v159 = v94->cache_dirty;
      v159[v467] = 0;
      int * v161 = v94->cache_age;
      v161[v467] = 1;
      int * v163 = v94->cache_age;
      int v164 = v163[v467];
      int v165 = v163[v441];
      int v497 = v165 + ((int)((unsigned int)(v165 - v164) >> 31));
      v163[v441] = v497;
      int * v167 = v94->cache_age;
      int v168 = v167[v442];
      int v499 = v168 + ((int)((unsigned int)(v168 - v164) >> 31));
      v167[v442] = v499;
      int * v170 = v94->cache_age;
      v170[v467] = 0;
      v173 = v467;
    }
    int * v174 = v94->cache_vals;
    int v502 = v173 * 2;
    int v175 = v174[v502];
    int v503 = (v173 * 2) + 1;
    int v176 = v174[v503];
    int v504 = (((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 1) * 2) + ((((v115 + ((~(((v117 ^ -1) | (-(v117 ^ -1))) >> 31)) & 2)) - (v118 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v174[v504] = v175;
    int * v178 = v94->cache_vals;
    int v507 = ((((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 1) * 2) + ((((v115 + ((~(((v117 ^ -1) | (-(v117 ^ -1))) >> 31)) & 2)) - (v118 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v178[v507] = v176;
    int * v180 = v94->cache_tags;
    int v510 = ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 1) * 2) + ((((v115 + ((~(((v117 ^ -1) | (-(v117 ^ -1))) >> 31)) & 2)) - (v118 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v511 = (int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1);
    v180[v510] = v511;
    int * v182 = v94->cache_dirty;
    v182[v510] = 0;
    int * v184 = v94->cache_age;
    v184[v510] = 1;
    int * v186 = v94->cache_age;
    int v187 = v186[v510];
    int v188 = v186[v439];
    int v517 = v188 + ((int)((unsigned int)(v188 - v187) >> 31));
    v186[v439] = v517;
    int * v190 = v94->cache_age;
    int v191 = v190[v440];
    int v519 = v191 + ((int)((unsigned int)(v191 - v187) >> 31));
    v190[v440] = v519;
    int * v193 = v94->cache_age;
    v193[v510] = 0;
    v196 = v510;
  }
  int * v197 = v94->cache_vals;
  int v522 = (v196 * 2) + (((int)((unsigned int)v96 >> 2)) & 1);
  v197[v522] = 0;
  int * v199 = v94->cache_tags;
  int v200 = v199[v441];
  int v201 = v199[v442];
  bool v525 = !(((~(((v200 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v200 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31)) | (~(((v201 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v201 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31))) == 0);
  int v255;
  if (v525) {
    int * v202 = v94->cache_age;
    int v527 = (4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + ((~(((v201 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))) | (-(v201 ^ ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1))))) >> 31)) & 1);
    int v203 = v202[v527];
    int v204 = v202[v441];
    int v528 = v204 + ((int)((unsigned int)(v204 - v203) >> 31));
    v202[v441] = v528;
    int * v206 = v94->cache_age;
    int v207 = v206[v442];
    int v530 = v207 + ((int)((unsigned int)(v207 - v203) >> 31));
    v206[v442] = v530;
    int * v209 = v94->cache_age;
    v209[v527] = 0;
    v255 = v527;
  } else {
    int * v212 = v94->cache_age;
    int v533 = 4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2);
    int v213 = v212[v533];
    int * v214 = v94->cache_tags;
    int v215 = v214[v533];
    int v216 = v212[v442];
    int v217 = v214[v442];
    int * v218 = v94->cache_dirty;
    int v536 = (4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + ((((v213 + ((~(((v215 ^ -1) | (-(v215 ^ -1))) >> 31)) & 2)) - (v216 + ((~(((v217 ^ -1) | (-(v217 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v219 = v218[v536];
    bool v537 = !(v219 == 0);
    if (v537) {
      int * v220 = v94->cache_tags;
      int v221 = v220[v536];
      int * v222 = v94->cache_vals;
      int v540 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + ((((v213 + ((~(((v215 ^ -1) | (-(v215 ^ -1))) >> 31)) & 2)) - (v216 + ((~(((v217 ^ -1) | (-(v217 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v223 = v222[v540];
      int v541 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + ((((v213 + ((~(((v215 ^ -1) | (-(v215 ^ -1))) >> 31)) & 2)) - (v216 + ((~(((v217 ^ -1) | (-(v217 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v224 = v222[v541];
      int * v225 = v94->mem;
      int v543 = v221 * 2;
      v225[v543] = v223;
      int * v227 = v94->mem;
      int v546 = (v221 * 2) + 1;
      v227[v546] = v224;
      ;
    } else {
      ;
    }
    int * v232 = v94->mem;
    int v551 = ((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) * 2;
    int v233 = v232[v551];
    int v552 = (((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) * 2) + 1;
    int v234 = v232[v552];
    int * v235 = v94->cache_vals;
    int v554 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + ((((v213 + ((~(((v215 ^ -1) | (-(v215 ^ -1))) >> 31)) & 2)) - (v216 + ((~(((v217 ^ -1) | (-(v217 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v235[v554] = v233;
    int * v237 = v94->cache_vals;
    int v557 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1)) & 3) * 2)) + ((((v213 + ((~(((v215 ^ -1) | (-(v215 ^ -1))) >> 31)) & 2)) - (v216 + ((~(((v217 ^ -1) | (-(v217 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v237[v557] = v234;
    int * v239 = v94->cache_tags;
    int v560 = (int)((unsigned int)((int)((unsigned int)v96 >> 2)) >> 1);
    v239[v536] = v560;
    int * v241 = v94->cache_dirty;
    v241[v536] = 0;
    int * v243 = v94->cache_age;
    v243[v536] = 1;
    int * v245 = v94->cache_age;
    int v246 = v245[v536];
    int v247 = v245[v441];
    int v565 = v247 + ((int)((unsigned int)(v247 - v246) >> 31));
    v245[v441] = v565;
    int * v249 = v94->cache_age;
    int v250 = v249[v442];
    int v567 = v250 + ((int)((unsigned int)(v250 - v246) >> 31));
    v249[v442] = v567;
    int * v252 = v94->cache_age;
    v252[v536] = 0;
    v255 = v536;
  }
  int * v256 = v94->cache_vals;
  int v570 = (v255 * 2) + (((int)((unsigned int)v96 >> 2)) & 1);
  v256[v570] = 0;
  int * v258 = v94->cache_dirty;
  v258[v255] = 1;
  struct StateT * v260 = v81->b;
  int * v261 = v260->regs;
  int v262 = v261[6];
  int * v263 = v260->cache_tags;
  int v577 = (((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 1) * 2;
  int v264 = v263[v577];
  int v578 = ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 1) * 2) + 1;
  int v265 = v263[v578];
  int v579 = 4 + ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 3) * 2);
  int v266 = v263[v579];
  int v580 = (4 + ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v267 = v263[v580];
  int v268 = v260->timer;
  int v581 = v268 + ((100 ^ (((~(((v266 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))) | (-(v266 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))))) >> 31)) | (~(((v267 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))) | (-(v267 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v264 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))) | (-(v264 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))))) >> 31)) | (~(((v265 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))) | (-(v265 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v266 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))) | (-(v266 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))))) >> 31)) | (~(((v267 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))) | (-(v267 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))))) >> 31))) & 104)))));
  v260->timer = v581;
  bool v582 = !(((~(((v264 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))) | (-(v264 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))))) >> 31)) | (~(((v265 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))) | (-(v265 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))))) >> 31))) == 0);
  int v362;
  if (v582) {
    int * v270 = v260->cache_age;
    int v584 = ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 1) * 2) + ((~(((v265 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))) | (-(v265 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))))) >> 31)) & 1);
    int v271 = v270[v584];
    int v272 = v270[v577];
    int v585 = v272 + ((int)((unsigned int)(v272 - v271) >> 31));
    v270[v577] = v585;
    int * v274 = v260->cache_age;
    int v275 = v274[v578];
    int v587 = v275 + ((int)((unsigned int)(v275 - v271) >> 31));
    v274[v578] = v587;
    int * v277 = v260->cache_age;
    v277[v584] = 0;
    v362 = v584;
  } else {
    int * v280 = v260->cache_age;
    int v590 = (((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 1) * 2;
    int v281 = v280[v590];
    int * v282 = v260->cache_tags;
    int v283 = v282[v590];
    int v284 = v280[v578];
    int v285 = v282[v578];
    bool v592 = !(((~(((v266 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))) | (-(v266 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))))) >> 31)) | (~(((v267 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))) | (-(v267 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))))) >> 31))) == 0);
    int v339;
    if (v592) {
      int * v286 = v260->cache_age;
      int v594 = (4 + ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 3) * 2)) + ((~(((v267 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))) | (-(v267 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))))) >> 31)) & 1);
      int v287 = v286[v594];
      int v288 = v286[v579];
      int v595 = v288 + ((int)((unsigned int)(v288 - v287) >> 31));
      v286[v579] = v595;
      int * v290 = v260->cache_age;
      int v291 = v290[v580];
      int v597 = v291 + ((int)((unsigned int)(v291 - v287) >> 31));
      v290[v580] = v597;
      int * v293 = v260->cache_age;
      v293[v594] = 0;
      v339 = v594;
    } else {
      int * v296 = v260->cache_age;
      int v600 = 4 + ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 3) * 2);
      int v297 = v296[v600];
      int * v298 = v260->cache_tags;
      int v299 = v298[v600];
      int v300 = v296[v580];
      int v301 = v298[v580];
      int * v302 = v260->cache_dirty;
      int v603 = (4 + ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 3) * 2)) + ((((v297 + ((~(((v299 ^ -1) | (-(v299 ^ -1))) >> 31)) & 2)) - (v300 + ((~(((v301 ^ -1) | (-(v301 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v303 = v302[v603];
      bool v604 = !(v303 == 0);
      if (v604) {
        int * v304 = v260->cache_tags;
        int v305 = v304[v603];
        int * v306 = v260->cache_vals;
        int v607 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 3) * 2)) + ((((v297 + ((~(((v299 ^ -1) | (-(v299 ^ -1))) >> 31)) & 2)) - (v300 + ((~(((v301 ^ -1) | (-(v301 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v307 = v306[v607];
        int v608 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 3) * 2)) + ((((v297 + ((~(((v299 ^ -1) | (-(v299 ^ -1))) >> 31)) & 2)) - (v300 + ((~(((v301 ^ -1) | (-(v301 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v308 = v306[v608];
        int * v309 = v260->mem;
        int v610 = v305 * 2;
        v309[v610] = v307;
        int * v311 = v260->mem;
        int v613 = (v305 * 2) + 1;
        v311[v613] = v308;
        ;
      } else {
        ;
      }
      int * v316 = v260->mem;
      int v618 = ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) * 2;
      int v317 = v316[v618];
      int v619 = (((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) * 2) + 1;
      int v318 = v316[v619];
      int * v319 = v260->cache_vals;
      int v621 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 3) * 2)) + ((((v297 + ((~(((v299 ^ -1) | (-(v299 ^ -1))) >> 31)) & 2)) - (v300 + ((~(((v301 ^ -1) | (-(v301 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v319[v621] = v317;
      int * v321 = v260->cache_vals;
      int v624 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 3) * 2)) + ((((v297 + ((~(((v299 ^ -1) | (-(v299 ^ -1))) >> 31)) & 2)) - (v300 + ((~(((v301 ^ -1) | (-(v301 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v321[v624] = v318;
      int * v323 = v260->cache_tags;
      int v627 = (int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1);
      v323[v603] = v627;
      int * v325 = v260->cache_dirty;
      v325[v603] = 0;
      int * v327 = v260->cache_age;
      v327[v603] = 1;
      int * v329 = v260->cache_age;
      int v330 = v329[v603];
      int v331 = v329[v579];
      int v631 = v331 + ((int)((unsigned int)(v331 - v330) >> 31));
      v329[v579] = v631;
      int * v333 = v260->cache_age;
      int v334 = v333[v580];
      int v633 = v334 + ((int)((unsigned int)(v334 - v330) >> 31));
      v333[v580] = v633;
      int * v336 = v260->cache_age;
      v336[v603] = 0;
      v339 = v603;
    }
    int * v340 = v260->cache_vals;
    int v636 = v339 * 2;
    int v341 = v340[v636];
    int v637 = (v339 * 2) + 1;
    int v342 = v340[v637];
    int v638 = (((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 1) * 2) + ((((v281 + ((~(((v283 ^ -1) | (-(v283 ^ -1))) >> 31)) & 2)) - (v284 + ((~(((v285 ^ -1) | (-(v285 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v340[v638] = v341;
    int * v344 = v260->cache_vals;
    int v641 = ((((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 1) * 2) + ((((v281 + ((~(((v283 ^ -1) | (-(v283 ^ -1))) >> 31)) & 2)) - (v284 + ((~(((v285 ^ -1) | (-(v285 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v344[v641] = v342;
    int * v346 = v260->cache_tags;
    int v644 = ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 1) * 2) + ((((v281 + ((~(((v283 ^ -1) | (-(v283 ^ -1))) >> 31)) & 2)) - (v284 + ((~(((v285 ^ -1) | (-(v285 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v645 = (int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1);
    v346[v644] = v645;
    int * v348 = v260->cache_dirty;
    v348[v644] = 0;
    int * v350 = v260->cache_age;
    v350[v644] = 1;
    int * v352 = v260->cache_age;
    int v353 = v352[v644];
    int v354 = v352[v577];
    int v649 = v354 + ((int)((unsigned int)(v354 - v353) >> 31));
    v352[v577] = v649;
    int * v356 = v260->cache_age;
    int v357 = v356[v578];
    int v651 = v357 + ((int)((unsigned int)(v357 - v353) >> 31));
    v356[v578] = v651;
    int * v359 = v260->cache_age;
    v359[v644] = 0;
    v362 = v644;
  }
  int * v363 = v260->cache_vals;
  int v654 = (v362 * 2) + (((int)((unsigned int)v262 >> 2)) & 1);
  v363[v654] = 0;
  int * v365 = v260->cache_tags;
  int v366 = v365[v579];
  int v367 = v365[v580];
  bool v656 = !(((~(((v366 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))) | (-(v366 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))))) >> 31)) | (~(((v367 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))) | (-(v367 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))))) >> 31))) == 0);
  int v421;
  if (v656) {
    int * v368 = v260->cache_age;
    int v658 = (4 + ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 3) * 2)) + ((~(((v367 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))) | (-(v367 ^ ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1))))) >> 31)) & 1);
    int v369 = v368[v658];
    int v370 = v368[v579];
    int v659 = v370 + ((int)((unsigned int)(v370 - v369) >> 31));
    v368[v579] = v659;
    int * v372 = v260->cache_age;
    int v373 = v372[v580];
    int v661 = v373 + ((int)((unsigned int)(v373 - v369) >> 31));
    v372[v580] = v661;
    int * v375 = v260->cache_age;
    v375[v658] = 0;
    v421 = v658;
  } else {
    int * v378 = v260->cache_age;
    int v664 = 4 + ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 3) * 2);
    int v379 = v378[v664];
    int * v380 = v260->cache_tags;
    int v381 = v380[v664];
    int v382 = v378[v580];
    int v383 = v380[v580];
    int * v384 = v260->cache_dirty;
    int v667 = (4 + ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 3) * 2)) + ((((v379 + ((~(((v381 ^ -1) | (-(v381 ^ -1))) >> 31)) & 2)) - (v382 + ((~(((v383 ^ -1) | (-(v383 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v385 = v384[v667];
    bool v668 = !(v385 == 0);
    if (v668) {
      int * v386 = v260->cache_tags;
      int v387 = v386[v667];
      int * v388 = v260->cache_vals;
      int v671 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 3) * 2)) + ((((v379 + ((~(((v381 ^ -1) | (-(v381 ^ -1))) >> 31)) & 2)) - (v382 + ((~(((v383 ^ -1) | (-(v383 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v389 = v388[v671];
      int v672 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 3) * 2)) + ((((v379 + ((~(((v381 ^ -1) | (-(v381 ^ -1))) >> 31)) & 2)) - (v382 + ((~(((v383 ^ -1) | (-(v383 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v390 = v388[v672];
      int * v391 = v260->mem;
      int v674 = v387 * 2;
      v391[v674] = v389;
      int * v393 = v260->mem;
      int v677 = (v387 * 2) + 1;
      v393[v677] = v390;
      ;
    } else {
      ;
    }
    int * v398 = v260->mem;
    int v682 = ((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) * 2;
    int v399 = v398[v682];
    int v683 = (((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) * 2) + 1;
    int v400 = v398[v683];
    int * v401 = v260->cache_vals;
    int v685 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 3) * 2)) + ((((v379 + ((~(((v381 ^ -1) | (-(v381 ^ -1))) >> 31)) & 2)) - (v382 + ((~(((v383 ^ -1) | (-(v383 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v401[v685] = v399;
    int * v403 = v260->cache_vals;
    int v688 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1)) & 3) * 2)) + ((((v379 + ((~(((v381 ^ -1) | (-(v381 ^ -1))) >> 31)) & 2)) - (v382 + ((~(((v383 ^ -1) | (-(v383 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v403[v688] = v400;
    int * v405 = v260->cache_tags;
    int v691 = (int)((unsigned int)((int)((unsigned int)v262 >> 2)) >> 1);
    v405[v667] = v691;
    int * v407 = v260->cache_dirty;
    v407[v667] = 0;
    int * v409 = v260->cache_age;
    v409[v667] = 1;
    int * v411 = v260->cache_age;
    int v412 = v411[v667];
    int v413 = v411[v579];
    int v695 = v413 + ((int)((unsigned int)(v413 - v412) >> 31));
    v411[v579] = v695;
    int * v415 = v260->cache_age;
    int v416 = v415[v580];
    int v697 = v416 + ((int)((unsigned int)(v416 - v412) >> 31));
    v415[v580] = v697;
    int * v418 = v260->cache_age;
    v418[v667] = 0;
    v421 = v667;
  }
  int * v422 = v260->cache_vals;
  int v700 = (v421 * 2) + (((int)((unsigned int)v262 >> 2)) & 1);
  v422[v700] = 0;
  int * v424 = v260->cache_dirty;
  v424[v421] = 1;
  struct StateT2 * v426 = slot_3(v81);
  return v426;
}

struct StateT2 * slot_3(struct StateT2 * v705) {
  struct StateT * v706 = v705->a;
  int v707 = v706->timer;
  struct StateT * v708 = v705->b;
  int v709 = v708->timer;
  bool v936 = v707 == v709;
  squared_assert(v936);
  squared_assume(v936);
  struct StateT * v712 = v705->a;
  int v713 = v712->timer;
  int v938 = v713 + 1;
  v712->timer = v938;
  struct StateT * v715 = v705->b;
  int v716 = v715->timer;
  int v940 = v716 + 1;
  v715->timer = v940;
  struct StateT * v718 = v705->a;
  int * v719 = v718->regs;
  int v720 = v719[6];
  int * v721 = v718->cache_tags;
  int v945 = (((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1)) & 1) * 2;
  int v722 = v721[v945];
  int v946 = ((((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1)) & 1) * 2) + 1;
  int v723 = v721[v946];
  int v947 = 4 + ((((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1)) & 3) * 2);
  int v724 = v721[v947];
  int v948 = (4 + ((((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v725 = v721[v948];
  int v726 = v718->timer;
  int v949 = v726 + ((100 ^ (((~(((v724 ^ ((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1))) | (-(v724 ^ ((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1))))) >> 31)) | (~(((v725 ^ ((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1))) | (-(v725 ^ ((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v722 ^ ((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1))) | (-(v722 ^ ((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1))))) >> 31)) | (~(((v723 ^ ((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1))) | (-(v723 ^ ((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v724 ^ ((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1))) | (-(v724 ^ ((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1))))) >> 31)) | (~(((v725 ^ ((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1))) | (-(v725 ^ ((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1))))) >> 31))) & 104)))));
  v718->timer = v949;
  int * v728 = v718->cache_vals;
  bool v950 = !(((~(((v722 ^ ((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1))) | (-(v722 ^ ((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1))))) >> 31)) | (~(((v723 ^ ((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1))) | (-(v723 ^ ((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1))))) >> 31))) == 0);
  int v821;
  if (v950) {
    int * v729 = v718->cache_age;
    int v952 = ((((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1)) & 1) * 2) + ((~(((v723 ^ ((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1))) | (-(v723 ^ ((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1))))) >> 31)) & 1);
    int v730 = v729[v952];
    int v731 = v729[v945];
    int v953 = v731 + ((int)((unsigned int)(v731 - v730) >> 31));
    v729[v945] = v953;
    int * v733 = v718->cache_age;
    int v734 = v733[v946];
    int v955 = v734 + ((int)((unsigned int)(v734 - v730) >> 31));
    v733[v946] = v955;
    int * v736 = v718->cache_age;
    v736[v952] = 0;
    v821 = v952;
  } else {
    int * v739 = v718->cache_age;
    int v959 = (((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1)) & 1) * 2;
    int v740 = v739[v959];
    int * v741 = v718->cache_tags;
    int v742 = v741[v959];
    int v743 = v739[v946];
    int v744 = v741[v946];
    bool v961 = !(((~(((v724 ^ ((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1))) | (-(v724 ^ ((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1))))) >> 31)) | (~(((v725 ^ ((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1))) | (-(v725 ^ ((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1))))) >> 31))) == 0);
    int v798;
    if (v961) {
      int * v745 = v718->cache_age;
      int v963 = (4 + ((((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1)) & 3) * 2)) + ((~(((v725 ^ ((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1))) | (-(v725 ^ ((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1))))) >> 31)) & 1);
      int v746 = v745[v963];
      int v747 = v745[v947];
      int v964 = v747 + ((int)((unsigned int)(v747 - v746) >> 31));
      v745[v947] = v964;
      int * v749 = v718->cache_age;
      int v750 = v749[v948];
      int v966 = v750 + ((int)((unsigned int)(v750 - v746) >> 31));
      v749[v948] = v966;
      int * v752 = v718->cache_age;
      v752[v963] = 0;
      v798 = v963;
    } else {
      int * v755 = v718->cache_age;
      int v970 = 4 + ((((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1)) & 3) * 2);
      int v756 = v755[v970];
      int * v757 = v718->cache_tags;
      int v758 = v757[v970];
      int v759 = v755[v948];
      int v760 = v757[v948];
      int * v761 = v718->cache_dirty;
      int v973 = (4 + ((((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1)) & 3) * 2)) + ((((v756 + ((~(((v758 ^ -1) | (-(v758 ^ -1))) >> 31)) & 2)) - (v759 + ((~(((v760 ^ -1) | (-(v760 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v762 = v761[v973];
      bool v974 = !(v762 == 0);
      if (v974) {
        int * v763 = v718->cache_tags;
        int v764 = v763[v973];
        int * v765 = v718->cache_vals;
        int v977 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1)) & 3) * 2)) + ((((v756 + ((~(((v758 ^ -1) | (-(v758 ^ -1))) >> 31)) & 2)) - (v759 + ((~(((v760 ^ -1) | (-(v760 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v766 = v765[v977];
        int v978 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1)) & 3) * 2)) + ((((v756 + ((~(((v758 ^ -1) | (-(v758 ^ -1))) >> 31)) & 2)) - (v759 + ((~(((v760 ^ -1) | (-(v760 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v767 = v765[v978];
        int * v768 = v718->mem;
        int v980 = v764 * 2;
        v768[v980] = v766;
        int * v770 = v718->mem;
        int v983 = (v764 * 2) + 1;
        v770[v983] = v767;
        ;
      } else {
        ;
      }
      int * v775 = v718->mem;
      int v988 = ((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1)) * 2;
      int v776 = v775[v988];
      int v989 = (((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1)) * 2) + 1;
      int v777 = v775[v989];
      int * v778 = v718->cache_vals;
      int v991 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1)) & 3) * 2)) + ((((v756 + ((~(((v758 ^ -1) | (-(v758 ^ -1))) >> 31)) & 2)) - (v759 + ((~(((v760 ^ -1) | (-(v760 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v778[v991] = v776;
      int * v780 = v718->cache_vals;
      int v994 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1)) & 3) * 2)) + ((((v756 + ((~(((v758 ^ -1) | (-(v758 ^ -1))) >> 31)) & 2)) - (v759 + ((~(((v760 ^ -1) | (-(v760 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v780[v994] = v777;
      int * v782 = v718->cache_tags;
      int v997 = (int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1);
      v782[v973] = v997;
      int * v784 = v718->cache_dirty;
      v784[v973] = 0;
      int * v786 = v718->cache_age;
      v786[v973] = 1;
      int * v788 = v718->cache_age;
      int v789 = v788[v973];
      int v790 = v788[v947];
      int v1003 = v790 + ((int)((unsigned int)(v790 - v789) >> 31));
      v788[v947] = v1003;
      int * v792 = v718->cache_age;
      int v793 = v792[v948];
      int v1005 = v793 + ((int)((unsigned int)(v793 - v789) >> 31));
      v792[v948] = v1005;
      int * v795 = v718->cache_age;
      v795[v973] = 0;
      v798 = v973;
    }
    int * v799 = v718->cache_vals;
    int v1008 = v798 * 2;
    int v800 = v799[v1008];
    int v1009 = (v798 * 2) + 1;
    int v801 = v799[v1009];
    int v1010 = (((((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1)) & 1) * 2) + ((((v740 + ((~(((v742 ^ -1) | (-(v742 ^ -1))) >> 31)) & 2)) - (v743 + ((~(((v744 ^ -1) | (-(v744 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v799[v1010] = v800;
    int * v803 = v718->cache_vals;
    int v1013 = ((((((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1)) & 1) * 2) + ((((v740 + ((~(((v742 ^ -1) | (-(v742 ^ -1))) >> 31)) & 2)) - (v743 + ((~(((v744 ^ -1) | (-(v744 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v803[v1013] = v801;
    int * v805 = v718->cache_tags;
    int v1016 = ((((int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1)) & 1) * 2) + ((((v740 + ((~(((v742 ^ -1) | (-(v742 ^ -1))) >> 31)) & 2)) - (v743 + ((~(((v744 ^ -1) | (-(v744 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1017 = (int)((unsigned int)((int)((unsigned int)v720 >> 2)) >> 1);
    v805[v1016] = v1017;
    int * v807 = v718->cache_dirty;
    v807[v1016] = 0;
    int * v809 = v718->cache_age;
    v809[v1016] = 1;
    int * v811 = v718->cache_age;
    int v812 = v811[v1016];
    int v813 = v811[v945];
    int v1023 = v813 + ((int)((unsigned int)(v813 - v812) >> 31));
    v811[v945] = v1023;
    int * v815 = v718->cache_age;
    int v816 = v815[v946];
    int v1025 = v816 + ((int)((unsigned int)(v816 - v812) >> 31));
    v815[v946] = v1025;
    int * v818 = v718->cache_age;
    v818[v1016] = 0;
    v821 = v1016;
  }
  int v1028 = (v821 * 2) + (((int)((unsigned int)v720 >> 2)) & 1);
  int v822 = v728[v1028];
  int * v823 = v718->regs;
  v823[11] = v822;
  struct StateT * v825 = v705->b;
  int * v826 = v825->regs;
  int v827 = v826[6];
  int * v828 = v825->cache_tags;
  int v1035 = (((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1)) & 1) * 2;
  int v829 = v828[v1035];
  int v1036 = ((((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1)) & 1) * 2) + 1;
  int v830 = v828[v1036];
  int v1037 = 4 + ((((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1)) & 3) * 2);
  int v831 = v828[v1037];
  int v1038 = (4 + ((((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v832 = v828[v1038];
  int v833 = v825->timer;
  int v1039 = v833 + ((100 ^ (((~(((v831 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))) | (-(v831 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))))) >> 31)) | (~(((v832 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))) | (-(v832 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v829 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))) | (-(v829 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))))) >> 31)) | (~(((v830 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))) | (-(v830 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v831 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))) | (-(v831 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))))) >> 31)) | (~(((v832 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))) | (-(v832 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))))) >> 31))) & 104)))));
  v825->timer = v1039;
  int * v835 = v825->cache_vals;
  bool v1040 = !(((~(((v829 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))) | (-(v829 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))))) >> 31)) | (~(((v830 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))) | (-(v830 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))))) >> 31))) == 0);
  int v928;
  if (v1040) {
    int * v836 = v825->cache_age;
    int v1042 = ((((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1)) & 1) * 2) + ((~(((v830 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))) | (-(v830 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))))) >> 31)) & 1);
    int v837 = v836[v1042];
    int v838 = v836[v1035];
    int v1043 = v838 + ((int)((unsigned int)(v838 - v837) >> 31));
    v836[v1035] = v1043;
    int * v840 = v825->cache_age;
    int v841 = v840[v1036];
    int v1045 = v841 + ((int)((unsigned int)(v841 - v837) >> 31));
    v840[v1036] = v1045;
    int * v843 = v825->cache_age;
    v843[v1042] = 0;
    v928 = v1042;
  } else {
    int * v846 = v825->cache_age;
    int v1049 = (((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1)) & 1) * 2;
    int v847 = v846[v1049];
    int * v848 = v825->cache_tags;
    int v849 = v848[v1049];
    int v850 = v846[v1036];
    int v851 = v848[v1036];
    bool v1051 = !(((~(((v831 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))) | (-(v831 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))))) >> 31)) | (~(((v832 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))) | (-(v832 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))))) >> 31))) == 0);
    int v905;
    if (v1051) {
      int * v852 = v825->cache_age;
      int v1053 = (4 + ((((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1)) & 3) * 2)) + ((~(((v832 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))) | (-(v832 ^ ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1))))) >> 31)) & 1);
      int v853 = v852[v1053];
      int v854 = v852[v1037];
      int v1054 = v854 + ((int)((unsigned int)(v854 - v853) >> 31));
      v852[v1037] = v1054;
      int * v856 = v825->cache_age;
      int v857 = v856[v1038];
      int v1056 = v857 + ((int)((unsigned int)(v857 - v853) >> 31));
      v856[v1038] = v1056;
      int * v859 = v825->cache_age;
      v859[v1053] = 0;
      v905 = v1053;
    } else {
      int * v862 = v825->cache_age;
      int v1060 = 4 + ((((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1)) & 3) * 2);
      int v863 = v862[v1060];
      int * v864 = v825->cache_tags;
      int v865 = v864[v1060];
      int v866 = v862[v1038];
      int v867 = v864[v1038];
      int * v868 = v825->cache_dirty;
      int v1063 = (4 + ((((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1)) & 3) * 2)) + ((((v863 + ((~(((v865 ^ -1) | (-(v865 ^ -1))) >> 31)) & 2)) - (v866 + ((~(((v867 ^ -1) | (-(v867 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v869 = v868[v1063];
      bool v1064 = !(v869 == 0);
      if (v1064) {
        int * v870 = v825->cache_tags;
        int v871 = v870[v1063];
        int * v872 = v825->cache_vals;
        int v1067 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1)) & 3) * 2)) + ((((v863 + ((~(((v865 ^ -1) | (-(v865 ^ -1))) >> 31)) & 2)) - (v866 + ((~(((v867 ^ -1) | (-(v867 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v873 = v872[v1067];
        int v1068 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1)) & 3) * 2)) + ((((v863 + ((~(((v865 ^ -1) | (-(v865 ^ -1))) >> 31)) & 2)) - (v866 + ((~(((v867 ^ -1) | (-(v867 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v874 = v872[v1068];
        int * v875 = v825->mem;
        int v1070 = v871 * 2;
        v875[v1070] = v873;
        int * v877 = v825->mem;
        int v1073 = (v871 * 2) + 1;
        v877[v1073] = v874;
        ;
      } else {
        ;
      }
      int * v882 = v825->mem;
      int v1078 = ((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1)) * 2;
      int v883 = v882[v1078];
      int v1079 = (((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1)) * 2) + 1;
      int v884 = v882[v1079];
      int * v885 = v825->cache_vals;
      int v1081 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1)) & 3) * 2)) + ((((v863 + ((~(((v865 ^ -1) | (-(v865 ^ -1))) >> 31)) & 2)) - (v866 + ((~(((v867 ^ -1) | (-(v867 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v885[v1081] = v883;
      int * v887 = v825->cache_vals;
      int v1084 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1)) & 3) * 2)) + ((((v863 + ((~(((v865 ^ -1) | (-(v865 ^ -1))) >> 31)) & 2)) - (v866 + ((~(((v867 ^ -1) | (-(v867 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v887[v1084] = v884;
      int * v889 = v825->cache_tags;
      int v1087 = (int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1);
      v889[v1063] = v1087;
      int * v891 = v825->cache_dirty;
      v891[v1063] = 0;
      int * v893 = v825->cache_age;
      v893[v1063] = 1;
      int * v895 = v825->cache_age;
      int v896 = v895[v1063];
      int v897 = v895[v1037];
      int v1093 = v897 + ((int)((unsigned int)(v897 - v896) >> 31));
      v895[v1037] = v1093;
      int * v899 = v825->cache_age;
      int v900 = v899[v1038];
      int v1095 = v900 + ((int)((unsigned int)(v900 - v896) >> 31));
      v899[v1038] = v1095;
      int * v902 = v825->cache_age;
      v902[v1063] = 0;
      v905 = v1063;
    }
    int * v906 = v825->cache_vals;
    int v1098 = v905 * 2;
    int v907 = v906[v1098];
    int v1099 = (v905 * 2) + 1;
    int v908 = v906[v1099];
    int v1100 = (((((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1)) & 1) * 2) + ((((v847 + ((~(((v849 ^ -1) | (-(v849 ^ -1))) >> 31)) & 2)) - (v850 + ((~(((v851 ^ -1) | (-(v851 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v906[v1100] = v907;
    int * v910 = v825->cache_vals;
    int v1103 = ((((((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1)) & 1) * 2) + ((((v847 + ((~(((v849 ^ -1) | (-(v849 ^ -1))) >> 31)) & 2)) - (v850 + ((~(((v851 ^ -1) | (-(v851 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v910[v1103] = v908;
    int * v912 = v825->cache_tags;
    int v1106 = ((((int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1)) & 1) * 2) + ((((v847 + ((~(((v849 ^ -1) | (-(v849 ^ -1))) >> 31)) & 2)) - (v850 + ((~(((v851 ^ -1) | (-(v851 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1107 = (int)((unsigned int)((int)((unsigned int)v827 >> 2)) >> 1);
    v912[v1106] = v1107;
    int * v914 = v825->cache_dirty;
    v914[v1106] = 0;
    int * v916 = v825->cache_age;
    v916[v1106] = 1;
    int * v918 = v825->cache_age;
    int v919 = v918[v1106];
    int v920 = v918[v1035];
    int v1113 = v920 + ((int)((unsigned int)(v920 - v919) >> 31));
    v918[v1035] = v1113;
    int * v922 = v825->cache_age;
    int v923 = v922[v1036];
    int v1115 = v923 + ((int)((unsigned int)(v923 - v919) >> 31));
    v922[v1036] = v1115;
    int * v925 = v825->cache_age;
    v925[v1106] = 0;
    v928 = v1106;
  }
  int v1118 = (v928 * 2) + (((int)((unsigned int)v827 >> 2)) & 1);
  int v929 = v835[v1118];
  int * v930 = v825->regs;
  v930[11] = v929;
  struct StateT2 * v932 = slot_4(v705);
  return v932;
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