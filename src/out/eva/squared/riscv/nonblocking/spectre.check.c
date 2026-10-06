// verify: clean (Eva should report untainted_timer: Valid) [unroll 65]
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
struct StateT2 * slot_1(struct StateT2 * v44);
struct StateT2 * slot_6(struct StateT2 * v667);
struct StateT2 * slot_5(struct StateT2 * v241);
struct StateT2 * slot_4(struct StateT2 * v182);
struct StateT2 * slot_2(struct StateT2 * v86);
struct StateT2 * slot_7(struct StateT2 * v720);
struct StateT2 * slot_3(struct StateT2 * v128);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  struct StateT * v1143 = v1->a;
  int v1144 = v1143->timer;
  int * v1145 = v1143->reg_ready;
  int v1146 = v1145[0];
  int v1407 = v1146 + ((v1144 - v1146) & (~((v1144 - v1146) >> 31)));
  v1143->timer = v1407;
  int v1148 = v1143->timer;
  int * v1149 = v1143->reg_ready;
  int v1150 = v1149[1];
  int v1410 = v1150 + ((v1148 - v1150) & (~((v1148 - v1150) >> 31)));
  v1143->timer = v1410;
  int v1152 = v1143->timer;
  int * v1153 = v1143->reg_ready;
  int v1154 = v1153[2];
  int v1413 = v1154 + ((v1152 - v1154) & (~((v1152 - v1154) >> 31)));
  v1143->timer = v1413;
  int v1156 = v1143->timer;
  int * v1157 = v1143->reg_ready;
  int v1158 = v1157[3];
  int v1416 = v1158 + ((v1156 - v1158) & (~((v1156 - v1158) >> 31)));
  v1143->timer = v1416;
  int v1160 = v1143->timer;
  int * v1161 = v1143->reg_ready;
  int v1162 = v1161[4];
  int v1419 = v1162 + ((v1160 - v1162) & (~((v1160 - v1162) >> 31)));
  v1143->timer = v1419;
  int v1164 = v1143->timer;
  int * v1165 = v1143->reg_ready;
  int v1166 = v1165[5];
  int v1422 = v1166 + ((v1164 - v1166) & (~((v1164 - v1166) >> 31)));
  v1143->timer = v1422;
  int v1168 = v1143->timer;
  int * v1169 = v1143->reg_ready;
  int v1170 = v1169[6];
  int v1425 = v1170 + ((v1168 - v1170) & (~((v1168 - v1170) >> 31)));
  v1143->timer = v1425;
  int v1172 = v1143->timer;
  int * v1173 = v1143->reg_ready;
  int v1174 = v1173[7];
  int v1428 = v1174 + ((v1172 - v1174) & (~((v1172 - v1174) >> 31)));
  v1143->timer = v1428;
  int v1176 = v1143->timer;
  int * v1177 = v1143->reg_ready;
  int v1178 = v1177[8];
  int v1431 = v1178 + ((v1176 - v1178) & (~((v1176 - v1178) >> 31)));
  v1143->timer = v1431;
  int v1180 = v1143->timer;
  int * v1181 = v1143->reg_ready;
  int v1182 = v1181[9];
  int v1434 = v1182 + ((v1180 - v1182) & (~((v1180 - v1182) >> 31)));
  v1143->timer = v1434;
  int v1184 = v1143->timer;
  int * v1185 = v1143->reg_ready;
  int v1186 = v1185[10];
  int v1437 = v1186 + ((v1184 - v1186) & (~((v1184 - v1186) >> 31)));
  v1143->timer = v1437;
  int v1188 = v1143->timer;
  int * v1189 = v1143->reg_ready;
  int v1190 = v1189[11];
  int v1440 = v1190 + ((v1188 - v1190) & (~((v1188 - v1190) >> 31)));
  v1143->timer = v1440;
  int v1192 = v1143->timer;
  int * v1193 = v1143->reg_ready;
  int v1194 = v1193[12];
  int v1443 = v1194 + ((v1192 - v1194) & (~((v1192 - v1194) >> 31)));
  v1143->timer = v1443;
  int v1196 = v1143->timer;
  int * v1197 = v1143->reg_ready;
  int v1198 = v1197[13];
  int v1446 = v1198 + ((v1196 - v1198) & (~((v1196 - v1198) >> 31)));
  v1143->timer = v1446;
  int v1200 = v1143->timer;
  int * v1201 = v1143->reg_ready;
  int v1202 = v1201[14];
  int v1449 = v1202 + ((v1200 - v1202) & (~((v1200 - v1202) >> 31)));
  v1143->timer = v1449;
  int v1204 = v1143->timer;
  int * v1205 = v1143->reg_ready;
  int v1206 = v1205[15];
  int v1452 = v1206 + ((v1204 - v1206) & (~((v1204 - v1206) >> 31)));
  v1143->timer = v1452;
  int v1208 = v1143->timer;
  int * v1209 = v1143->reg_ready;
  int v1210 = v1209[16];
  int v1455 = v1210 + ((v1208 - v1210) & (~((v1208 - v1210) >> 31)));
  v1143->timer = v1455;
  int v1212 = v1143->timer;
  int * v1213 = v1143->reg_ready;
  int v1214 = v1213[17];
  int v1458 = v1214 + ((v1212 - v1214) & (~((v1212 - v1214) >> 31)));
  v1143->timer = v1458;
  int v1216 = v1143->timer;
  int * v1217 = v1143->reg_ready;
  int v1218 = v1217[18];
  int v1461 = v1218 + ((v1216 - v1218) & (~((v1216 - v1218) >> 31)));
  v1143->timer = v1461;
  int v1220 = v1143->timer;
  int * v1221 = v1143->reg_ready;
  int v1222 = v1221[19];
  int v1464 = v1222 + ((v1220 - v1222) & (~((v1220 - v1222) >> 31)));
  v1143->timer = v1464;
  int v1224 = v1143->timer;
  int * v1225 = v1143->reg_ready;
  int v1226 = v1225[20];
  int v1467 = v1226 + ((v1224 - v1226) & (~((v1224 - v1226) >> 31)));
  v1143->timer = v1467;
  int v1228 = v1143->timer;
  int * v1229 = v1143->reg_ready;
  int v1230 = v1229[21];
  int v1470 = v1230 + ((v1228 - v1230) & (~((v1228 - v1230) >> 31)));
  v1143->timer = v1470;
  int v1232 = v1143->timer;
  int * v1233 = v1143->reg_ready;
  int v1234 = v1233[22];
  int v1473 = v1234 + ((v1232 - v1234) & (~((v1232 - v1234) >> 31)));
  v1143->timer = v1473;
  int v1236 = v1143->timer;
  int * v1237 = v1143->reg_ready;
  int v1238 = v1237[23];
  int v1476 = v1238 + ((v1236 - v1238) & (~((v1236 - v1238) >> 31)));
  v1143->timer = v1476;
  int v1240 = v1143->timer;
  int * v1241 = v1143->reg_ready;
  int v1242 = v1241[24];
  int v1479 = v1242 + ((v1240 - v1242) & (~((v1240 - v1242) >> 31)));
  v1143->timer = v1479;
  int v1244 = v1143->timer;
  int * v1245 = v1143->reg_ready;
  int v1246 = v1245[25];
  int v1482 = v1246 + ((v1244 - v1246) & (~((v1244 - v1246) >> 31)));
  v1143->timer = v1482;
  int v1248 = v1143->timer;
  int * v1249 = v1143->reg_ready;
  int v1250 = v1249[26];
  int v1485 = v1250 + ((v1248 - v1250) & (~((v1248 - v1250) >> 31)));
  v1143->timer = v1485;
  int v1252 = v1143->timer;
  int * v1253 = v1143->reg_ready;
  int v1254 = v1253[27];
  int v1488 = v1254 + ((v1252 - v1254) & (~((v1252 - v1254) >> 31)));
  v1143->timer = v1488;
  int v1256 = v1143->timer;
  int * v1257 = v1143->reg_ready;
  int v1258 = v1257[28];
  int v1491 = v1258 + ((v1256 - v1258) & (~((v1256 - v1258) >> 31)));
  v1143->timer = v1491;
  int v1260 = v1143->timer;
  int * v1261 = v1143->reg_ready;
  int v1262 = v1261[29];
  int v1494 = v1262 + ((v1260 - v1262) & (~((v1260 - v1262) >> 31)));
  v1143->timer = v1494;
  int v1264 = v1143->timer;
  int * v1265 = v1143->reg_ready;
  int v1266 = v1265[30];
  int v1497 = v1266 + ((v1264 - v1266) & (~((v1264 - v1266) >> 31)));
  v1143->timer = v1497;
  int v1268 = v1143->timer;
  int * v1269 = v1143->reg_ready;
  int v1270 = v1269[31];
  int v1500 = v1270 + ((v1268 - v1270) & (~((v1268 - v1270) >> 31)));
  v1143->timer = v1500;
  struct StateT * v1272 = v1->b;
  int v1273 = v1272->timer;
  int * v1274 = v1272->reg_ready;
  int v1275 = v1274[0];
  int v1503 = v1275 + ((v1273 - v1275) & (~((v1273 - v1275) >> 31)));
  v1272->timer = v1503;
  int v1277 = v1272->timer;
  int * v1278 = v1272->reg_ready;
  int v1279 = v1278[1];
  int v1505 = v1279 + ((v1277 - v1279) & (~((v1277 - v1279) >> 31)));
  v1272->timer = v1505;
  int v1281 = v1272->timer;
  int * v1282 = v1272->reg_ready;
  int v1283 = v1282[2];
  int v1507 = v1283 + ((v1281 - v1283) & (~((v1281 - v1283) >> 31)));
  v1272->timer = v1507;
  int v1285 = v1272->timer;
  int * v1286 = v1272->reg_ready;
  int v1287 = v1286[3];
  int v1509 = v1287 + ((v1285 - v1287) & (~((v1285 - v1287) >> 31)));
  v1272->timer = v1509;
  int v1289 = v1272->timer;
  int * v1290 = v1272->reg_ready;
  int v1291 = v1290[4];
  int v1511 = v1291 + ((v1289 - v1291) & (~((v1289 - v1291) >> 31)));
  v1272->timer = v1511;
  int v1293 = v1272->timer;
  int * v1294 = v1272->reg_ready;
  int v1295 = v1294[5];
  int v1513 = v1295 + ((v1293 - v1295) & (~((v1293 - v1295) >> 31)));
  v1272->timer = v1513;
  int v1297 = v1272->timer;
  int * v1298 = v1272->reg_ready;
  int v1299 = v1298[6];
  int v1515 = v1299 + ((v1297 - v1299) & (~((v1297 - v1299) >> 31)));
  v1272->timer = v1515;
  int v1301 = v1272->timer;
  int * v1302 = v1272->reg_ready;
  int v1303 = v1302[7];
  int v1517 = v1303 + ((v1301 - v1303) & (~((v1301 - v1303) >> 31)));
  v1272->timer = v1517;
  int v1305 = v1272->timer;
  int * v1306 = v1272->reg_ready;
  int v1307 = v1306[8];
  int v1519 = v1307 + ((v1305 - v1307) & (~((v1305 - v1307) >> 31)));
  v1272->timer = v1519;
  int v1309 = v1272->timer;
  int * v1310 = v1272->reg_ready;
  int v1311 = v1310[9];
  int v1521 = v1311 + ((v1309 - v1311) & (~((v1309 - v1311) >> 31)));
  v1272->timer = v1521;
  int v1313 = v1272->timer;
  int * v1314 = v1272->reg_ready;
  int v1315 = v1314[10];
  int v1523 = v1315 + ((v1313 - v1315) & (~((v1313 - v1315) >> 31)));
  v1272->timer = v1523;
  int v1317 = v1272->timer;
  int * v1318 = v1272->reg_ready;
  int v1319 = v1318[11];
  int v1525 = v1319 + ((v1317 - v1319) & (~((v1317 - v1319) >> 31)));
  v1272->timer = v1525;
  int v1321 = v1272->timer;
  int * v1322 = v1272->reg_ready;
  int v1323 = v1322[12];
  int v1527 = v1323 + ((v1321 - v1323) & (~((v1321 - v1323) >> 31)));
  v1272->timer = v1527;
  int v1325 = v1272->timer;
  int * v1326 = v1272->reg_ready;
  int v1327 = v1326[13];
  int v1529 = v1327 + ((v1325 - v1327) & (~((v1325 - v1327) >> 31)));
  v1272->timer = v1529;
  int v1329 = v1272->timer;
  int * v1330 = v1272->reg_ready;
  int v1331 = v1330[14];
  int v1531 = v1331 + ((v1329 - v1331) & (~((v1329 - v1331) >> 31)));
  v1272->timer = v1531;
  int v1333 = v1272->timer;
  int * v1334 = v1272->reg_ready;
  int v1335 = v1334[15];
  int v1533 = v1335 + ((v1333 - v1335) & (~((v1333 - v1335) >> 31)));
  v1272->timer = v1533;
  int v1337 = v1272->timer;
  int * v1338 = v1272->reg_ready;
  int v1339 = v1338[16];
  int v1535 = v1339 + ((v1337 - v1339) & (~((v1337 - v1339) >> 31)));
  v1272->timer = v1535;
  int v1341 = v1272->timer;
  int * v1342 = v1272->reg_ready;
  int v1343 = v1342[17];
  int v1537 = v1343 + ((v1341 - v1343) & (~((v1341 - v1343) >> 31)));
  v1272->timer = v1537;
  int v1345 = v1272->timer;
  int * v1346 = v1272->reg_ready;
  int v1347 = v1346[18];
  int v1539 = v1347 + ((v1345 - v1347) & (~((v1345 - v1347) >> 31)));
  v1272->timer = v1539;
  int v1349 = v1272->timer;
  int * v1350 = v1272->reg_ready;
  int v1351 = v1350[19];
  int v1541 = v1351 + ((v1349 - v1351) & (~((v1349 - v1351) >> 31)));
  v1272->timer = v1541;
  int v1353 = v1272->timer;
  int * v1354 = v1272->reg_ready;
  int v1355 = v1354[20];
  int v1543 = v1355 + ((v1353 - v1355) & (~((v1353 - v1355) >> 31)));
  v1272->timer = v1543;
  int v1357 = v1272->timer;
  int * v1358 = v1272->reg_ready;
  int v1359 = v1358[21];
  int v1545 = v1359 + ((v1357 - v1359) & (~((v1357 - v1359) >> 31)));
  v1272->timer = v1545;
  int v1361 = v1272->timer;
  int * v1362 = v1272->reg_ready;
  int v1363 = v1362[22];
  int v1547 = v1363 + ((v1361 - v1363) & (~((v1361 - v1363) >> 31)));
  v1272->timer = v1547;
  int v1365 = v1272->timer;
  int * v1366 = v1272->reg_ready;
  int v1367 = v1366[23];
  int v1549 = v1367 + ((v1365 - v1367) & (~((v1365 - v1367) >> 31)));
  v1272->timer = v1549;
  int v1369 = v1272->timer;
  int * v1370 = v1272->reg_ready;
  int v1371 = v1370[24];
  int v1551 = v1371 + ((v1369 - v1371) & (~((v1369 - v1371) >> 31)));
  v1272->timer = v1551;
  int v1373 = v1272->timer;
  int * v1374 = v1272->reg_ready;
  int v1375 = v1374[25];
  int v1553 = v1375 + ((v1373 - v1375) & (~((v1373 - v1375) >> 31)));
  v1272->timer = v1553;
  int v1377 = v1272->timer;
  int * v1378 = v1272->reg_ready;
  int v1379 = v1378[26];
  int v1555 = v1379 + ((v1377 - v1379) & (~((v1377 - v1379) >> 31)));
  v1272->timer = v1555;
  int v1381 = v1272->timer;
  int * v1382 = v1272->reg_ready;
  int v1383 = v1382[27];
  int v1557 = v1383 + ((v1381 - v1383) & (~((v1381 - v1383) >> 31)));
  v1272->timer = v1557;
  int v1385 = v1272->timer;
  int * v1386 = v1272->reg_ready;
  int v1387 = v1386[28];
  int v1559 = v1387 + ((v1385 - v1387) & (~((v1385 - v1387) >> 31)));
  v1272->timer = v1559;
  int v1389 = v1272->timer;
  int * v1390 = v1272->reg_ready;
  int v1391 = v1390[29];
  int v1561 = v1391 + ((v1389 - v1391) & (~((v1389 - v1391) >> 31)));
  v1272->timer = v1561;
  int v1393 = v1272->timer;
  int * v1394 = v1272->reg_ready;
  int v1395 = v1394[30];
  int v1563 = v1395 + ((v1393 - v1395) & (~((v1393 - v1395) >> 31)));
  v1272->timer = v1563;
  int v1397 = v1272->timer;
  int * v1398 = v1272->reg_ready;
  int v1399 = v1398[31];
  int v1565 = v1399 + ((v1397 - v1399) & (~((v1397 - v1399) >> 31)));
  v1272->timer = v1565;
  return v1;
}

struct StateT2 * slot_1(struct StateT2 * v44) {
  struct StateT * v45 = v44->a;
  int v46 = v45->timer;
  struct StateT * v47 = v44->b;
  int v48 = v47->timer;
  bool v71 = v46 == v48;
  squared_assert(v71);
  squared_assume(v71);
  struct StateT * v51 = v44->a;
  int v52 = v51->timer;
  int v73 = v52 + 1;
  v51->timer = v73;
  struct StateT * v54 = v44->b;
  int v55 = v54->timer;
  int v75 = v55 + 1;
  v54->timer = v75;
  struct StateT * v57 = v44->a;
  int * v58 = v57->reg_ready;
  v58[10] = v73;
  int * v60 = v57->regs;
  v60[10] = 80;
  struct StateT * v62 = v44->b;
  int * v63 = v62->reg_ready;
  v63[10] = v75;
  int * v65 = v62->regs;
  v65[10] = 80;
  struct StateT2 * v67 = slot_2(v44);
  return v67;
}

struct StateT2 * slot_6(struct StateT2 * v667) {
  struct StateT * v668 = v667->a;
  int v669 = v668->timer;
  struct StateT * v670 = v667->b;
  int v671 = v670->timer;
  bool v700 = v669 == v671;
  squared_assert(v700);
  squared_assume(v700);
  struct StateT * v674 = v667->a;
  int v675 = v674->timer;
  int v702 = v675 + 1;
  v674->timer = v702;
  struct StateT * v677 = v667->b;
  int v678 = v677->timer;
  int v704 = v678 + 1;
  v677->timer = v704;
  struct StateT * v680 = v667->a;
  int * v681 = v680->reg_ready;
  int v682 = v681[11];
  int * v683 = v680->regs;
  int v684 = v683[11];
  int v709 = (v682 + ((v675 - v682) & (~((v675 - v682) >> 31)))) + 1;
  v681[11] = v709;
  int * v686 = v680->regs;
  int v711 = v684 << 2;
  v686[11] = v711;
  struct StateT * v688 = v667->b;
  int * v689 = v688->reg_ready;
  int v690 = v689[11];
  int * v691 = v688->regs;
  int v692 = v691[11];
  int v715 = (v690 + ((v678 - v690) & (~((v678 - v690) >> 31)))) + 1;
  v689[11] = v715;
  int * v694 = v688->regs;
  int v717 = v692 << 2;
  v694[11] = v717;
  struct StateT2 * v696 = slot_7(v667);
  return v696;
}

struct StateT2 * slot_5(struct StateT2 * v241) {
  struct StateT * v242 = v241->a;
  int v243 = v242->timer;
  struct StateT * v244 = v241->b;
  int v245 = v244->timer;
  bool v476 = v243 == v245;
  squared_assert(v476);
  squared_assume(v476);
  struct StateT * v248 = v241->a;
  int v249 = v248->timer;
  int v478 = v249 + 1;
  v248->timer = v478;
  struct StateT * v251 = v241->b;
  int v252 = v251->timer;
  int v480 = v252 + 1;
  v251->timer = v480;
  struct StateT * v254 = v241->a;
  int * v255 = v254->reg_ready;
  int v256 = v255[5];
  int * v257 = v254->regs;
  int v258 = v257[5];
  int * v259 = v254->cache_tags;
  int v486 = (((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1)) & 1) * 2;
  int v260 = v259[v486];
  int v487 = ((((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1)) & 1) * 2) + 1;
  int v261 = v259[v487];
  int v488 = 4 + ((((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1)) & 3) * 2);
  int v262 = v259[v488];
  int v489 = (4 + ((((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v263 = v259[v489];
  int * v264 = v254->cache_vals;
  bool v490 = !(((~(((v260 ^ ((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1))) | (-(v260 ^ ((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1))))) >> 31)) | (~(((v261 ^ ((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1))) | (-(v261 ^ ((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1))))) >> 31))) == 0);
  int v357;
  if (v490) {
    int * v265 = v254->cache_age;
    int v492 = ((((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1)) & 1) * 2) + ((~(((v261 ^ ((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1))) | (-(v261 ^ ((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1))))) >> 31)) & 1);
    int v266 = v265[v492];
    int v267 = v265[v486];
    int v493 = v267 + ((int)((unsigned int)(v267 - v266) >> 31));
    v265[v486] = v493;
    int * v269 = v254->cache_age;
    int v270 = v269[v487];
    int v495 = v270 + ((int)((unsigned int)(v270 - v266) >> 31));
    v269[v487] = v495;
    int * v272 = v254->cache_age;
    v272[v492] = 0;
    v357 = v492;
  } else {
    int * v275 = v254->cache_age;
    int v499 = (((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1)) & 1) * 2;
    int v276 = v275[v499];
    int * v277 = v254->cache_tags;
    int v278 = v277[v499];
    int v279 = v275[v487];
    int v280 = v277[v487];
    bool v501 = !(((~(((v262 ^ ((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1))) | (-(v262 ^ ((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1))))) >> 31)) | (~(((v263 ^ ((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1))) | (-(v263 ^ ((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1))))) >> 31))) == 0);
    int v334;
    if (v501) {
      int * v281 = v254->cache_age;
      int v503 = (4 + ((((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1)) & 3) * 2)) + ((~(((v263 ^ ((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1))) | (-(v263 ^ ((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1))))) >> 31)) & 1);
      int v282 = v281[v503];
      int v283 = v281[v488];
      int v504 = v283 + ((int)((unsigned int)(v283 - v282) >> 31));
      v281[v488] = v504;
      int * v285 = v254->cache_age;
      int v286 = v285[v489];
      int v506 = v286 + ((int)((unsigned int)(v286 - v282) >> 31));
      v285[v489] = v506;
      int * v288 = v254->cache_age;
      v288[v503] = 0;
      v334 = v503;
    } else {
      int * v291 = v254->cache_age;
      int v510 = 4 + ((((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1)) & 3) * 2);
      int v292 = v291[v510];
      int * v293 = v254->cache_tags;
      int v294 = v293[v510];
      int v295 = v291[v489];
      int v296 = v293[v489];
      int * v297 = v254->cache_dirty;
      int v513 = (4 + ((((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1)) & 3) * 2)) + ((((v292 + ((~(((v294 ^ -1) | (-(v294 ^ -1))) >> 31)) & 2)) - (v295 + ((~(((v296 ^ -1) | (-(v296 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v298 = v297[v513];
      bool v514 = !(v298 == 0);
      if (v514) {
        int * v299 = v254->cache_tags;
        int v300 = v299[v513];
        int * v301 = v254->cache_vals;
        int v517 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1)) & 3) * 2)) + ((((v292 + ((~(((v294 ^ -1) | (-(v294 ^ -1))) >> 31)) & 2)) - (v295 + ((~(((v296 ^ -1) | (-(v296 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v302 = v301[v517];
        int v518 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1)) & 3) * 2)) + ((((v292 + ((~(((v294 ^ -1) | (-(v294 ^ -1))) >> 31)) & 2)) - (v295 + ((~(((v296 ^ -1) | (-(v296 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v303 = v301[v518];
        int * v304 = v254->mem;
        int v520 = v300 * 2;
        v304[v520] = v302;
        int * v306 = v254->mem;
        int v523 = (v300 * 2) + 1;
        v306[v523] = v303;
        ;
      } else {
        ;
      }
      int * v311 = v254->mem;
      int v528 = ((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1)) * 2;
      int v312 = v311[v528];
      int v529 = (((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1)) * 2) + 1;
      int v313 = v311[v529];
      int * v314 = v254->cache_vals;
      int v531 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1)) & 3) * 2)) + ((((v292 + ((~(((v294 ^ -1) | (-(v294 ^ -1))) >> 31)) & 2)) - (v295 + ((~(((v296 ^ -1) | (-(v296 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v314[v531] = v312;
      int * v316 = v254->cache_vals;
      int v534 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1)) & 3) * 2)) + ((((v292 + ((~(((v294 ^ -1) | (-(v294 ^ -1))) >> 31)) & 2)) - (v295 + ((~(((v296 ^ -1) | (-(v296 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v316[v534] = v313;
      int * v318 = v254->cache_tags;
      int v537 = (int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1);
      v318[v513] = v537;
      int * v320 = v254->cache_dirty;
      v320[v513] = 0;
      int * v322 = v254->cache_age;
      v322[v513] = 1;
      int * v324 = v254->cache_age;
      int v325 = v324[v513];
      int v326 = v324[v488];
      int v543 = v326 + ((int)((unsigned int)(v326 - v325) >> 31));
      v324[v488] = v543;
      int * v328 = v254->cache_age;
      int v329 = v328[v489];
      int v545 = v329 + ((int)((unsigned int)(v329 - v325) >> 31));
      v328[v489] = v545;
      int * v331 = v254->cache_age;
      v331[v513] = 0;
      v334 = v513;
    }
    int * v335 = v254->cache_vals;
    int v548 = v334 * 2;
    int v336 = v335[v548];
    int v549 = (v334 * 2) + 1;
    int v337 = v335[v549];
    int v550 = (((((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1)) & 1) * 2) + ((((v276 + ((~(((v278 ^ -1) | (-(v278 ^ -1))) >> 31)) & 2)) - (v279 + ((~(((v280 ^ -1) | (-(v280 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v335[v550] = v336;
    int * v339 = v254->cache_vals;
    int v553 = ((((((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1)) & 1) * 2) + ((((v276 + ((~(((v278 ^ -1) | (-(v278 ^ -1))) >> 31)) & 2)) - (v279 + ((~(((v280 ^ -1) | (-(v280 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v339[v553] = v337;
    int * v341 = v254->cache_tags;
    int v556 = ((((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1)) & 1) * 2) + ((((v276 + ((~(((v278 ^ -1) | (-(v278 ^ -1))) >> 31)) & 2)) - (v279 + ((~(((v280 ^ -1) | (-(v280 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v557 = (int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1);
    v341[v556] = v557;
    int * v343 = v254->cache_dirty;
    v343[v556] = 0;
    int * v345 = v254->cache_age;
    v345[v556] = 1;
    int * v347 = v254->cache_age;
    int v348 = v347[v556];
    int v349 = v347[v486];
    int v563 = v349 + ((int)((unsigned int)(v349 - v348) >> 31));
    v347[v486] = v563;
    int * v351 = v254->cache_age;
    int v352 = v351[v487];
    int v565 = v352 + ((int)((unsigned int)(v352 - v348) >> 31));
    v351[v487] = v565;
    int * v354 = v254->cache_age;
    v354[v556] = 0;
    v357 = v556;
  }
  int v568 = (v357 * 2) + (((int)((unsigned int)v258 >> 2)) & 1);
  int v358 = v264[v568];
  int * v359 = v254->reg_ready;
  int v571 = ((v256 + ((v249 - v256) & (~((v249 - v256) >> 31)))) + 1) + ((100 ^ (((~(((v262 ^ ((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1))) | (-(v262 ^ ((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1))))) >> 31)) | (~(((v263 ^ ((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1))) | (-(v263 ^ ((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v260 ^ ((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1))) | (-(v260 ^ ((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1))))) >> 31)) | (~(((v261 ^ ((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1))) | (-(v261 ^ ((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v262 ^ ((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1))) | (-(v262 ^ ((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1))))) >> 31)) | (~(((v263 ^ ((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1))) | (-(v263 ^ ((int)((unsigned int)((int)((unsigned int)v258 >> 2)) >> 1))))) >> 31))) & 104)))));
  v359[11] = v571;
  int * v361 = v254->regs;
  v361[11] = v358;
  struct StateT * v363 = v241->b;
  int * v364 = v363->reg_ready;
  int v365 = v364[5];
  int * v366 = v363->regs;
  int v367 = v366[5];
  int * v368 = v363->cache_tags;
  int v578 = (((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1)) & 1) * 2;
  int v369 = v368[v578];
  int v579 = ((((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1)) & 1) * 2) + 1;
  int v370 = v368[v579];
  int v580 = 4 + ((((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1)) & 3) * 2);
  int v371 = v368[v580];
  int v581 = (4 + ((((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v372 = v368[v581];
  int * v373 = v363->cache_vals;
  bool v582 = !(((~(((v369 ^ ((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1))) | (-(v369 ^ ((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1))))) >> 31)) | (~(((v370 ^ ((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1))) | (-(v370 ^ ((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1))))) >> 31))) == 0);
  int v466;
  if (v582) {
    int * v374 = v363->cache_age;
    int v584 = ((((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1)) & 1) * 2) + ((~(((v370 ^ ((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1))) | (-(v370 ^ ((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1))))) >> 31)) & 1);
    int v375 = v374[v584];
    int v376 = v374[v578];
    int v585 = v376 + ((int)((unsigned int)(v376 - v375) >> 31));
    v374[v578] = v585;
    int * v378 = v363->cache_age;
    int v379 = v378[v579];
    int v587 = v379 + ((int)((unsigned int)(v379 - v375) >> 31));
    v378[v579] = v587;
    int * v381 = v363->cache_age;
    v381[v584] = 0;
    v466 = v584;
  } else {
    int * v384 = v363->cache_age;
    int v591 = (((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1)) & 1) * 2;
    int v385 = v384[v591];
    int * v386 = v363->cache_tags;
    int v387 = v386[v591];
    int v388 = v384[v579];
    int v389 = v386[v579];
    bool v593 = !(((~(((v371 ^ ((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1))) | (-(v371 ^ ((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1))))) >> 31)) | (~(((v372 ^ ((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1))) | (-(v372 ^ ((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1))))) >> 31))) == 0);
    int v443;
    if (v593) {
      int * v390 = v363->cache_age;
      int v595 = (4 + ((((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1)) & 3) * 2)) + ((~(((v372 ^ ((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1))) | (-(v372 ^ ((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1))))) >> 31)) & 1);
      int v391 = v390[v595];
      int v392 = v390[v580];
      int v596 = v392 + ((int)((unsigned int)(v392 - v391) >> 31));
      v390[v580] = v596;
      int * v394 = v363->cache_age;
      int v395 = v394[v581];
      int v598 = v395 + ((int)((unsigned int)(v395 - v391) >> 31));
      v394[v581] = v598;
      int * v397 = v363->cache_age;
      v397[v595] = 0;
      v443 = v595;
    } else {
      int * v400 = v363->cache_age;
      int v602 = 4 + ((((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1)) & 3) * 2);
      int v401 = v400[v602];
      int * v402 = v363->cache_tags;
      int v403 = v402[v602];
      int v404 = v400[v581];
      int v405 = v402[v581];
      int * v406 = v363->cache_dirty;
      int v605 = (4 + ((((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1)) & 3) * 2)) + ((((v401 + ((~(((v403 ^ -1) | (-(v403 ^ -1))) >> 31)) & 2)) - (v404 + ((~(((v405 ^ -1) | (-(v405 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v407 = v406[v605];
      bool v606 = !(v407 == 0);
      if (v606) {
        int * v408 = v363->cache_tags;
        int v409 = v408[v605];
        int * v410 = v363->cache_vals;
        int v609 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1)) & 3) * 2)) + ((((v401 + ((~(((v403 ^ -1) | (-(v403 ^ -1))) >> 31)) & 2)) - (v404 + ((~(((v405 ^ -1) | (-(v405 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v411 = v410[v609];
        int v610 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1)) & 3) * 2)) + ((((v401 + ((~(((v403 ^ -1) | (-(v403 ^ -1))) >> 31)) & 2)) - (v404 + ((~(((v405 ^ -1) | (-(v405 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v412 = v410[v610];
        int * v413 = v363->mem;
        int v612 = v409 * 2;
        v413[v612] = v411;
        int * v415 = v363->mem;
        int v615 = (v409 * 2) + 1;
        v415[v615] = v412;
        ;
      } else {
        ;
      }
      int * v420 = v363->mem;
      int v620 = ((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1)) * 2;
      int v421 = v420[v620];
      int v621 = (((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1)) * 2) + 1;
      int v422 = v420[v621];
      int * v423 = v363->cache_vals;
      int v623 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1)) & 3) * 2)) + ((((v401 + ((~(((v403 ^ -1) | (-(v403 ^ -1))) >> 31)) & 2)) - (v404 + ((~(((v405 ^ -1) | (-(v405 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v423[v623] = v421;
      int * v425 = v363->cache_vals;
      int v626 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1)) & 3) * 2)) + ((((v401 + ((~(((v403 ^ -1) | (-(v403 ^ -1))) >> 31)) & 2)) - (v404 + ((~(((v405 ^ -1) | (-(v405 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v425[v626] = v422;
      int * v427 = v363->cache_tags;
      int v629 = (int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1);
      v427[v605] = v629;
      int * v429 = v363->cache_dirty;
      v429[v605] = 0;
      int * v431 = v363->cache_age;
      v431[v605] = 1;
      int * v433 = v363->cache_age;
      int v434 = v433[v605];
      int v435 = v433[v580];
      int v635 = v435 + ((int)((unsigned int)(v435 - v434) >> 31));
      v433[v580] = v635;
      int * v437 = v363->cache_age;
      int v438 = v437[v581];
      int v637 = v438 + ((int)((unsigned int)(v438 - v434) >> 31));
      v437[v581] = v637;
      int * v440 = v363->cache_age;
      v440[v605] = 0;
      v443 = v605;
    }
    int * v444 = v363->cache_vals;
    int v640 = v443 * 2;
    int v445 = v444[v640];
    int v641 = (v443 * 2) + 1;
    int v446 = v444[v641];
    int v642 = (((((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1)) & 1) * 2) + ((((v385 + ((~(((v387 ^ -1) | (-(v387 ^ -1))) >> 31)) & 2)) - (v388 + ((~(((v389 ^ -1) | (-(v389 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v444[v642] = v445;
    int * v448 = v363->cache_vals;
    int v645 = ((((((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1)) & 1) * 2) + ((((v385 + ((~(((v387 ^ -1) | (-(v387 ^ -1))) >> 31)) & 2)) - (v388 + ((~(((v389 ^ -1) | (-(v389 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v448[v645] = v446;
    int * v450 = v363->cache_tags;
    int v648 = ((((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1)) & 1) * 2) + ((((v385 + ((~(((v387 ^ -1) | (-(v387 ^ -1))) >> 31)) & 2)) - (v388 + ((~(((v389 ^ -1) | (-(v389 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v649 = (int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1);
    v450[v648] = v649;
    int * v452 = v363->cache_dirty;
    v452[v648] = 0;
    int * v454 = v363->cache_age;
    v454[v648] = 1;
    int * v456 = v363->cache_age;
    int v457 = v456[v648];
    int v458 = v456[v578];
    int v655 = v458 + ((int)((unsigned int)(v458 - v457) >> 31));
    v456[v578] = v655;
    int * v460 = v363->cache_age;
    int v461 = v460[v579];
    int v657 = v461 + ((int)((unsigned int)(v461 - v457) >> 31));
    v460[v579] = v657;
    int * v463 = v363->cache_age;
    v463[v648] = 0;
    v466 = v648;
  }
  int v660 = (v466 * 2) + (((int)((unsigned int)v367 >> 2)) & 1);
  int v467 = v373[v660];
  int * v468 = v363->reg_ready;
  int v662 = ((v365 + ((v252 - v365) & (~((v252 - v365) >> 31)))) + 1) + ((100 ^ (((~(((v371 ^ ((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1))) | (-(v371 ^ ((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1))))) >> 31)) | (~(((v372 ^ ((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1))) | (-(v372 ^ ((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v369 ^ ((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1))) | (-(v369 ^ ((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1))))) >> 31)) | (~(((v370 ^ ((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1))) | (-(v370 ^ ((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v371 ^ ((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1))) | (-(v371 ^ ((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1))))) >> 31)) | (~(((v372 ^ ((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1))) | (-(v372 ^ ((int)((unsigned int)((int)((unsigned int)v367 >> 2)) >> 1))))) >> 31))) & 104)))));
  v468[11] = v662;
  int * v470 = v363->regs;
  v470[11] = v467;
  struct StateT2 * v472 = slot_6(v241);
  return v472;
}

struct StateT2 * slot_4(struct StateT2 * v182) {
  struct StateT * v183 = v182->a;
  int v184 = v183->timer;
  struct StateT * v185 = v182->b;
  int v186 = v185->timer;
  bool v219 = v184 == v186;
  squared_assert(v219);
  squared_assume(v219);
  struct StateT * v189 = v182->a;
  int v190 = v189->timer;
  int v221 = v190 + 1;
  v189->timer = v221;
  struct StateT * v192 = v182->b;
  int v193 = v192->timer;
  int v223 = v193 + 1;
  v192->timer = v223;
  struct StateT * v195 = v182->a;
  int * v196 = v195->reg_ready;
  int v197 = v196[13];
  int * v198 = v195->regs;
  int v199 = v198[13];
  int v200 = v196[10];
  int v201 = v198[10];
  int v230 = (v200 + (((v197 + ((v190 - v197) & (~((v190 - v197) >> 31)))) - v200) & (~(((v197 + ((v190 - v197) & (~((v190 - v197) >> 31)))) - v200) >> 31)))) + 1;
  v196[5] = v230;
  int * v203 = v195->regs;
  int v232 = v199 + v201;
  v203[5] = v232;
  struct StateT * v205 = v182->b;
  int * v206 = v205->reg_ready;
  int v207 = v206[13];
  int * v208 = v205->regs;
  int v209 = v208[13];
  int v210 = v206[10];
  int v211 = v208[10];
  int v236 = (v210 + (((v207 + ((v193 - v207) & (~((v193 - v207) >> 31)))) - v210) & (~(((v207 + ((v193 - v207) & (~((v193 - v207) >> 31)))) - v210) >> 31)))) + 1;
  v206[5] = v236;
  int * v213 = v205->regs;
  int v238 = v209 + v211;
  v213[5] = v238;
  struct StateT2 * v215 = slot_5(v182);
  return v215;
}

struct StateT2 * slot_2(struct StateT2 * v86) {
  struct StateT * v87 = v86->a;
  int v88 = v87->timer;
  struct StateT * v89 = v86->b;
  int v90 = v89->timer;
  bool v113 = v88 == v90;
  squared_assert(v113);
  squared_assume(v113);
  struct StateT * v93 = v86->a;
  int v94 = v93->timer;
  int v115 = v94 + 1;
  v93->timer = v115;
  struct StateT * v96 = v86->b;
  int v97 = v96->timer;
  int v117 = v97 + 1;
  v96->timer = v117;
  struct StateT * v99 = v86->a;
  int * v100 = v99->reg_ready;
  v100[15] = v115;
  int * v102 = v99->regs;
  v102[15] = 80;
  struct StateT * v104 = v86->b;
  int * v105 = v104->reg_ready;
  v105[15] = v117;
  int * v107 = v104->regs;
  v107[15] = 80;
  struct StateT2 * v109 = slot_3(v86);
  return v109;
}

struct StateT2 * slot_7(struct StateT2 * v720) {
  struct StateT * v721 = v720->a;
  int v722 = v721->timer;
  struct StateT * v723 = v720->b;
  int v724 = v723->timer;
  bool v954 = v722 == v724;
  squared_assert(v954);
  squared_assume(v954);
  struct StateT * v727 = v720->a;
  int v728 = v727->timer;
  int v956 = v728 + 1;
  v727->timer = v956;
  struct StateT * v730 = v720->b;
  int v731 = v730->timer;
  int v958 = v731 + 1;
  v730->timer = v958;
  struct StateT * v733 = v720->a;
  int * v734 = v733->reg_ready;
  int v735 = v734[11];
  int * v736 = v733->regs;
  int v737 = v736[11];
  int * v738 = v733->cache_tags;
  int v964 = (((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1)) & 1) * 2;
  int v739 = v738[v964];
  int v965 = ((((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1)) & 1) * 2) + 1;
  int v740 = v738[v965];
  int v966 = 4 + ((((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1)) & 3) * 2);
  int v741 = v738[v966];
  int v967 = (4 + ((((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v742 = v738[v967];
  int * v743 = v733->cache_vals;
  bool v968 = !(((~(((v739 ^ ((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1))) | (-(v739 ^ ((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1))))) >> 31)) | (~(((v740 ^ ((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1))) | (-(v740 ^ ((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1))))) >> 31))) == 0);
  int v836;
  if (v968) {
    int * v744 = v733->cache_age;
    int v970 = ((((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1)) & 1) * 2) + ((~(((v740 ^ ((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1))) | (-(v740 ^ ((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1))))) >> 31)) & 1);
    int v745 = v744[v970];
    int v746 = v744[v964];
    int v971 = v746 + ((int)((unsigned int)(v746 - v745) >> 31));
    v744[v964] = v971;
    int * v748 = v733->cache_age;
    int v749 = v748[v965];
    int v973 = v749 + ((int)((unsigned int)(v749 - v745) >> 31));
    v748[v965] = v973;
    int * v751 = v733->cache_age;
    v751[v970] = 0;
    v836 = v970;
  } else {
    int * v754 = v733->cache_age;
    int v977 = (((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1)) & 1) * 2;
    int v755 = v754[v977];
    int * v756 = v733->cache_tags;
    int v757 = v756[v977];
    int v758 = v754[v965];
    int v759 = v756[v965];
    bool v979 = !(((~(((v741 ^ ((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1))) | (-(v741 ^ ((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1))))) >> 31)) | (~(((v742 ^ ((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1))) | (-(v742 ^ ((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1))))) >> 31))) == 0);
    int v813;
    if (v979) {
      int * v760 = v733->cache_age;
      int v981 = (4 + ((((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1)) & 3) * 2)) + ((~(((v742 ^ ((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1))) | (-(v742 ^ ((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1))))) >> 31)) & 1);
      int v761 = v760[v981];
      int v762 = v760[v966];
      int v982 = v762 + ((int)((unsigned int)(v762 - v761) >> 31));
      v760[v966] = v982;
      int * v764 = v733->cache_age;
      int v765 = v764[v967];
      int v984 = v765 + ((int)((unsigned int)(v765 - v761) >> 31));
      v764[v967] = v984;
      int * v767 = v733->cache_age;
      v767[v981] = 0;
      v813 = v981;
    } else {
      int * v770 = v733->cache_age;
      int v988 = 4 + ((((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1)) & 3) * 2);
      int v771 = v770[v988];
      int * v772 = v733->cache_tags;
      int v773 = v772[v988];
      int v774 = v770[v967];
      int v775 = v772[v967];
      int * v776 = v733->cache_dirty;
      int v991 = (4 + ((((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1)) & 3) * 2)) + ((((v771 + ((~(((v773 ^ -1) | (-(v773 ^ -1))) >> 31)) & 2)) - (v774 + ((~(((v775 ^ -1) | (-(v775 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v777 = v776[v991];
      bool v992 = !(v777 == 0);
      if (v992) {
        int * v778 = v733->cache_tags;
        int v779 = v778[v991];
        int * v780 = v733->cache_vals;
        int v995 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1)) & 3) * 2)) + ((((v771 + ((~(((v773 ^ -1) | (-(v773 ^ -1))) >> 31)) & 2)) - (v774 + ((~(((v775 ^ -1) | (-(v775 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v781 = v780[v995];
        int v996 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1)) & 3) * 2)) + ((((v771 + ((~(((v773 ^ -1) | (-(v773 ^ -1))) >> 31)) & 2)) - (v774 + ((~(((v775 ^ -1) | (-(v775 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v782 = v780[v996];
        int * v783 = v733->mem;
        int v998 = v779 * 2;
        v783[v998] = v781;
        int * v785 = v733->mem;
        int v1001 = (v779 * 2) + 1;
        v785[v1001] = v782;
        ;
      } else {
        ;
      }
      int * v790 = v733->mem;
      int v1006 = ((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1)) * 2;
      int v791 = v790[v1006];
      int v1007 = (((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1)) * 2) + 1;
      int v792 = v790[v1007];
      int * v793 = v733->cache_vals;
      int v1009 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1)) & 3) * 2)) + ((((v771 + ((~(((v773 ^ -1) | (-(v773 ^ -1))) >> 31)) & 2)) - (v774 + ((~(((v775 ^ -1) | (-(v775 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v793[v1009] = v791;
      int * v795 = v733->cache_vals;
      int v1012 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1)) & 3) * 2)) + ((((v771 + ((~(((v773 ^ -1) | (-(v773 ^ -1))) >> 31)) & 2)) - (v774 + ((~(((v775 ^ -1) | (-(v775 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v795[v1012] = v792;
      int * v797 = v733->cache_tags;
      int v1015 = (int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1);
      v797[v991] = v1015;
      int * v799 = v733->cache_dirty;
      v799[v991] = 0;
      int * v801 = v733->cache_age;
      v801[v991] = 1;
      int * v803 = v733->cache_age;
      int v804 = v803[v991];
      int v805 = v803[v966];
      int v1021 = v805 + ((int)((unsigned int)(v805 - v804) >> 31));
      v803[v966] = v1021;
      int * v807 = v733->cache_age;
      int v808 = v807[v967];
      int v1023 = v808 + ((int)((unsigned int)(v808 - v804) >> 31));
      v807[v967] = v1023;
      int * v810 = v733->cache_age;
      v810[v991] = 0;
      v813 = v991;
    }
    int * v814 = v733->cache_vals;
    int v1026 = v813 * 2;
    int v815 = v814[v1026];
    int v1027 = (v813 * 2) + 1;
    int v816 = v814[v1027];
    int v1028 = (((((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1)) & 1) * 2) + ((((v755 + ((~(((v757 ^ -1) | (-(v757 ^ -1))) >> 31)) & 2)) - (v758 + ((~(((v759 ^ -1) | (-(v759 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v814[v1028] = v815;
    int * v818 = v733->cache_vals;
    int v1031 = ((((((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1)) & 1) * 2) + ((((v755 + ((~(((v757 ^ -1) | (-(v757 ^ -1))) >> 31)) & 2)) - (v758 + ((~(((v759 ^ -1) | (-(v759 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v818[v1031] = v816;
    int * v820 = v733->cache_tags;
    int v1034 = ((((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1)) & 1) * 2) + ((((v755 + ((~(((v757 ^ -1) | (-(v757 ^ -1))) >> 31)) & 2)) - (v758 + ((~(((v759 ^ -1) | (-(v759 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1035 = (int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1);
    v820[v1034] = v1035;
    int * v822 = v733->cache_dirty;
    v822[v1034] = 0;
    int * v824 = v733->cache_age;
    v824[v1034] = 1;
    int * v826 = v733->cache_age;
    int v827 = v826[v1034];
    int v828 = v826[v964];
    int v1041 = v828 + ((int)((unsigned int)(v828 - v827) >> 31));
    v826[v964] = v1041;
    int * v830 = v733->cache_age;
    int v831 = v830[v965];
    int v1043 = v831 + ((int)((unsigned int)(v831 - v827) >> 31));
    v830[v965] = v1043;
    int * v833 = v733->cache_age;
    v833[v1034] = 0;
    v836 = v1034;
  }
  int v1046 = (v836 * 2) + (((int)((unsigned int)v737 >> 2)) & 1);
  int v837 = v743[v1046];
  int * v838 = v733->reg_ready;
  int v1049 = ((v735 + ((v728 - v735) & (~((v728 - v735) >> 31)))) + 1) + ((100 ^ (((~(((v741 ^ ((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1))) | (-(v741 ^ ((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1))))) >> 31)) | (~(((v742 ^ ((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1))) | (-(v742 ^ ((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v739 ^ ((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1))) | (-(v739 ^ ((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1))))) >> 31)) | (~(((v740 ^ ((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1))) | (-(v740 ^ ((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v741 ^ ((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1))) | (-(v741 ^ ((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1))))) >> 31)) | (~(((v742 ^ ((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1))) | (-(v742 ^ ((int)((unsigned int)((int)((unsigned int)v737 >> 2)) >> 1))))) >> 31))) & 104)))));
  v838[12] = v1049;
  int * v840 = v733->regs;
  v840[12] = v837;
  struct StateT * v842 = v720->b;
  int * v843 = v842->reg_ready;
  int v844 = v843[11];
  int * v845 = v842->regs;
  int v846 = v845[11];
  int * v847 = v842->cache_tags;
  int v1056 = (((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1)) & 1) * 2;
  int v848 = v847[v1056];
  int v1057 = ((((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1)) & 1) * 2) + 1;
  int v849 = v847[v1057];
  int v1058 = 4 + ((((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1)) & 3) * 2);
  int v850 = v847[v1058];
  int v1059 = (4 + ((((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v851 = v847[v1059];
  int * v852 = v842->cache_vals;
  bool v1060 = !(((~(((v848 ^ ((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1))) | (-(v848 ^ ((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1))))) >> 31)) | (~(((v849 ^ ((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1))) | (-(v849 ^ ((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1))))) >> 31))) == 0);
  int v945;
  if (v1060) {
    int * v853 = v842->cache_age;
    int v1062 = ((((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1)) & 1) * 2) + ((~(((v849 ^ ((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1))) | (-(v849 ^ ((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1))))) >> 31)) & 1);
    int v854 = v853[v1062];
    int v855 = v853[v1056];
    int v1063 = v855 + ((int)((unsigned int)(v855 - v854) >> 31));
    v853[v1056] = v1063;
    int * v857 = v842->cache_age;
    int v858 = v857[v1057];
    int v1065 = v858 + ((int)((unsigned int)(v858 - v854) >> 31));
    v857[v1057] = v1065;
    int * v860 = v842->cache_age;
    v860[v1062] = 0;
    v945 = v1062;
  } else {
    int * v863 = v842->cache_age;
    int v1069 = (((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1)) & 1) * 2;
    int v864 = v863[v1069];
    int * v865 = v842->cache_tags;
    int v866 = v865[v1069];
    int v867 = v863[v1057];
    int v868 = v865[v1057];
    bool v1071 = !(((~(((v850 ^ ((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1))) | (-(v850 ^ ((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1))))) >> 31)) | (~(((v851 ^ ((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1))) | (-(v851 ^ ((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1))))) >> 31))) == 0);
    int v922;
    if (v1071) {
      int * v869 = v842->cache_age;
      int v1073 = (4 + ((((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1)) & 3) * 2)) + ((~(((v851 ^ ((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1))) | (-(v851 ^ ((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1))))) >> 31)) & 1);
      int v870 = v869[v1073];
      int v871 = v869[v1058];
      int v1074 = v871 + ((int)((unsigned int)(v871 - v870) >> 31));
      v869[v1058] = v1074;
      int * v873 = v842->cache_age;
      int v874 = v873[v1059];
      int v1076 = v874 + ((int)((unsigned int)(v874 - v870) >> 31));
      v873[v1059] = v1076;
      int * v876 = v842->cache_age;
      v876[v1073] = 0;
      v922 = v1073;
    } else {
      int * v879 = v842->cache_age;
      int v1080 = 4 + ((((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1)) & 3) * 2);
      int v880 = v879[v1080];
      int * v881 = v842->cache_tags;
      int v882 = v881[v1080];
      int v883 = v879[v1059];
      int v884 = v881[v1059];
      int * v885 = v842->cache_dirty;
      int v1083 = (4 + ((((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1)) & 3) * 2)) + ((((v880 + ((~(((v882 ^ -1) | (-(v882 ^ -1))) >> 31)) & 2)) - (v883 + ((~(((v884 ^ -1) | (-(v884 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v886 = v885[v1083];
      bool v1084 = !(v886 == 0);
      if (v1084) {
        int * v887 = v842->cache_tags;
        int v888 = v887[v1083];
        int * v889 = v842->cache_vals;
        int v1087 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1)) & 3) * 2)) + ((((v880 + ((~(((v882 ^ -1) | (-(v882 ^ -1))) >> 31)) & 2)) - (v883 + ((~(((v884 ^ -1) | (-(v884 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v890 = v889[v1087];
        int v1088 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1)) & 3) * 2)) + ((((v880 + ((~(((v882 ^ -1) | (-(v882 ^ -1))) >> 31)) & 2)) - (v883 + ((~(((v884 ^ -1) | (-(v884 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v891 = v889[v1088];
        int * v892 = v842->mem;
        int v1090 = v888 * 2;
        v892[v1090] = v890;
        int * v894 = v842->mem;
        int v1093 = (v888 * 2) + 1;
        v894[v1093] = v891;
        ;
      } else {
        ;
      }
      int * v899 = v842->mem;
      int v1098 = ((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1)) * 2;
      int v900 = v899[v1098];
      int v1099 = (((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1)) * 2) + 1;
      int v901 = v899[v1099];
      int * v902 = v842->cache_vals;
      int v1101 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1)) & 3) * 2)) + ((((v880 + ((~(((v882 ^ -1) | (-(v882 ^ -1))) >> 31)) & 2)) - (v883 + ((~(((v884 ^ -1) | (-(v884 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v902[v1101] = v900;
      int * v904 = v842->cache_vals;
      int v1104 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1)) & 3) * 2)) + ((((v880 + ((~(((v882 ^ -1) | (-(v882 ^ -1))) >> 31)) & 2)) - (v883 + ((~(((v884 ^ -1) | (-(v884 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v904[v1104] = v901;
      int * v906 = v842->cache_tags;
      int v1107 = (int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1);
      v906[v1083] = v1107;
      int * v908 = v842->cache_dirty;
      v908[v1083] = 0;
      int * v910 = v842->cache_age;
      v910[v1083] = 1;
      int * v912 = v842->cache_age;
      int v913 = v912[v1083];
      int v914 = v912[v1058];
      int v1113 = v914 + ((int)((unsigned int)(v914 - v913) >> 31));
      v912[v1058] = v1113;
      int * v916 = v842->cache_age;
      int v917 = v916[v1059];
      int v1115 = v917 + ((int)((unsigned int)(v917 - v913) >> 31));
      v916[v1059] = v1115;
      int * v919 = v842->cache_age;
      v919[v1083] = 0;
      v922 = v1083;
    }
    int * v923 = v842->cache_vals;
    int v1118 = v922 * 2;
    int v924 = v923[v1118];
    int v1119 = (v922 * 2) + 1;
    int v925 = v923[v1119];
    int v1120 = (((((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1)) & 1) * 2) + ((((v864 + ((~(((v866 ^ -1) | (-(v866 ^ -1))) >> 31)) & 2)) - (v867 + ((~(((v868 ^ -1) | (-(v868 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v923[v1120] = v924;
    int * v927 = v842->cache_vals;
    int v1123 = ((((((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1)) & 1) * 2) + ((((v864 + ((~(((v866 ^ -1) | (-(v866 ^ -1))) >> 31)) & 2)) - (v867 + ((~(((v868 ^ -1) | (-(v868 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v927[v1123] = v925;
    int * v929 = v842->cache_tags;
    int v1126 = ((((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1)) & 1) * 2) + ((((v864 + ((~(((v866 ^ -1) | (-(v866 ^ -1))) >> 31)) & 2)) - (v867 + ((~(((v868 ^ -1) | (-(v868 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1127 = (int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1);
    v929[v1126] = v1127;
    int * v931 = v842->cache_dirty;
    v931[v1126] = 0;
    int * v933 = v842->cache_age;
    v933[v1126] = 1;
    int * v935 = v842->cache_age;
    int v936 = v935[v1126];
    int v937 = v935[v1056];
    int v1133 = v937 + ((int)((unsigned int)(v937 - v936) >> 31));
    v935[v1056] = v1133;
    int * v939 = v842->cache_age;
    int v940 = v939[v1057];
    int v1135 = v940 + ((int)((unsigned int)(v940 - v936) >> 31));
    v939[v1057] = v1135;
    int * v942 = v842->cache_age;
    v942[v1126] = 0;
    v945 = v1126;
  }
  int v1138 = (v945 * 2) + (((int)((unsigned int)v846 >> 2)) & 1);
  int v946 = v852[v1138];
  int * v947 = v842->reg_ready;
  int v1140 = ((v844 + ((v731 - v844) & (~((v731 - v844) >> 31)))) + 1) + ((100 ^ (((~(((v850 ^ ((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1))) | (-(v850 ^ ((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1))))) >> 31)) | (~(((v851 ^ ((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1))) | (-(v851 ^ ((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v848 ^ ((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1))) | (-(v848 ^ ((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1))))) >> 31)) | (~(((v849 ^ ((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1))) | (-(v849 ^ ((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v850 ^ ((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1))) | (-(v850 ^ ((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1))))) >> 31)) | (~(((v851 ^ ((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1))) | (-(v851 ^ ((int)((unsigned int)((int)((unsigned int)v846 >> 2)) >> 1))))) >> 31))) & 104)))));
  v947[12] = v1140;
  int * v949 = v842->regs;
  v949[12] = v946;
  return v720;
}

struct StateT2 * slot_3(struct StateT2 * v128) {
  struct StateT * v129 = v128->a;
  int v130 = v129->timer;
  struct StateT * v131 = v128->b;
  int v132 = v131->timer;
  bool v164 = v130 == v132;
  squared_assert(v164);
  squared_assume(v164);
  struct StateT * v135 = v128->a;
  int v136 = v135->timer;
  int v166 = v136 + 1;
  v135->timer = v166;
  struct StateT * v138 = v128->b;
  int v139 = v138->timer;
  int v168 = v139 + 1;
  v138->timer = v168;
  struct StateT * v141 = v128->a;
  int * v142 = v141->reg_ready;
  int * v144 = v141->regs;
  int v145 = v144[10];
  int v147 = v144[15];
  struct StateT * v148 = v128->b;
  int * v149 = v148->reg_ready;
  int * v151 = v148->regs;
  int v152 = v151[10];
  int v154 = v151[15];
  bool v177 = (v145 >= v147) == (v152 >= v154);
  squared_diverged(v177);
  squared_assume(v177);
  bool v178 = v145 >= v147;
  struct StateT2 * v160;
  if (v178) {
    v160 = v128;
  } else {
    struct StateT2 * v158 = slot_4(v128);
    v160 = v158;
  }
  return v160;
}

struct StateT2 * slot_0(struct StateT2 * v2) {
  struct StateT * v3 = v2->a;
  int v4 = v3->timer;
  struct StateT * v5 = v2->b;
  int v6 = v5->timer;
  bool v29 = v4 == v6;
  squared_assert(v29);
  squared_assume(v29);
  struct StateT * v9 = v2->a;
  int v10 = v9->timer;
  int v31 = v10 + 1;
  v9->timer = v31;
  struct StateT * v12 = v2->b;
  int v13 = v12->timer;
  int v33 = v13 + 1;
  v12->timer = v33;
  struct StateT * v15 = v2->a;
  int * v16 = v15->reg_ready;
  v16[13] = v31;
  int * v18 = v15->regs;
  v18[13] = 0;
  struct StateT * v20 = v2->b;
  int * v21 = v20->reg_ready;
  v21[13] = v33;
  int * v23 = v20->regs;
  v23[13] = 0;
  struct StateT2 * v25 = slot_1(v2);
  return v25;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
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