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
struct StateT * slot_1(struct StateT * v24);
struct StateT * slot_6(struct StateT * v1044);
struct StateT * slot_5(struct StateT * v836);
struct StateT * slot_4(struct StateT * v645);
struct StateT * slot_2(struct StateT * v46);
struct StateT * slot_3(struct StateT * v346);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v1249 = v1->timer;
  int * v1250 = v1->reg_ready;
  int v1251 = v1250[0];
  int v1382 = v1251 + ((v1249 - v1251) & (~((v1249 - v1251) >> 31)));
  v1->timer = v1382;
  int v1253 = v1->timer;
  int * v1254 = v1->reg_ready;
  int v1255 = v1254[1];
  int v1385 = v1255 + ((v1253 - v1255) & (~((v1253 - v1255) >> 31)));
  v1->timer = v1385;
  int v1257 = v1->timer;
  int * v1258 = v1->reg_ready;
  int v1259 = v1258[2];
  int v1388 = v1259 + ((v1257 - v1259) & (~((v1257 - v1259) >> 31)));
  v1->timer = v1388;
  int v1261 = v1->timer;
  int * v1262 = v1->reg_ready;
  int v1263 = v1262[3];
  int v1391 = v1263 + ((v1261 - v1263) & (~((v1261 - v1263) >> 31)));
  v1->timer = v1391;
  int v1265 = v1->timer;
  int * v1266 = v1->reg_ready;
  int v1267 = v1266[4];
  int v1394 = v1267 + ((v1265 - v1267) & (~((v1265 - v1267) >> 31)));
  v1->timer = v1394;
  int v1269 = v1->timer;
  int * v1270 = v1->reg_ready;
  int v1271 = v1270[5];
  int v1397 = v1271 + ((v1269 - v1271) & (~((v1269 - v1271) >> 31)));
  v1->timer = v1397;
  int v1273 = v1->timer;
  int * v1274 = v1->reg_ready;
  int v1275 = v1274[6];
  int v1400 = v1275 + ((v1273 - v1275) & (~((v1273 - v1275) >> 31)));
  v1->timer = v1400;
  int v1277 = v1->timer;
  int * v1278 = v1->reg_ready;
  int v1279 = v1278[7];
  int v1403 = v1279 + ((v1277 - v1279) & (~((v1277 - v1279) >> 31)));
  v1->timer = v1403;
  int v1281 = v1->timer;
  int * v1282 = v1->reg_ready;
  int v1283 = v1282[8];
  int v1406 = v1283 + ((v1281 - v1283) & (~((v1281 - v1283) >> 31)));
  v1->timer = v1406;
  int v1285 = v1->timer;
  int * v1286 = v1->reg_ready;
  int v1287 = v1286[9];
  int v1409 = v1287 + ((v1285 - v1287) & (~((v1285 - v1287) >> 31)));
  v1->timer = v1409;
  int v1289 = v1->timer;
  int * v1290 = v1->reg_ready;
  int v1291 = v1290[10];
  int v1412 = v1291 + ((v1289 - v1291) & (~((v1289 - v1291) >> 31)));
  v1->timer = v1412;
  int v1293 = v1->timer;
  int * v1294 = v1->reg_ready;
  int v1295 = v1294[11];
  int v1415 = v1295 + ((v1293 - v1295) & (~((v1293 - v1295) >> 31)));
  v1->timer = v1415;
  int v1297 = v1->timer;
  int * v1298 = v1->reg_ready;
  int v1299 = v1298[12];
  int v1418 = v1299 + ((v1297 - v1299) & (~((v1297 - v1299) >> 31)));
  v1->timer = v1418;
  int v1301 = v1->timer;
  int * v1302 = v1->reg_ready;
  int v1303 = v1302[13];
  int v1421 = v1303 + ((v1301 - v1303) & (~((v1301 - v1303) >> 31)));
  v1->timer = v1421;
  int v1305 = v1->timer;
  int * v1306 = v1->reg_ready;
  int v1307 = v1306[14];
  int v1424 = v1307 + ((v1305 - v1307) & (~((v1305 - v1307) >> 31)));
  v1->timer = v1424;
  int v1309 = v1->timer;
  int * v1310 = v1->reg_ready;
  int v1311 = v1310[15];
  int v1427 = v1311 + ((v1309 - v1311) & (~((v1309 - v1311) >> 31)));
  v1->timer = v1427;
  int v1313 = v1->timer;
  int * v1314 = v1->reg_ready;
  int v1315 = v1314[16];
  int v1430 = v1315 + ((v1313 - v1315) & (~((v1313 - v1315) >> 31)));
  v1->timer = v1430;
  int v1317 = v1->timer;
  int * v1318 = v1->reg_ready;
  int v1319 = v1318[17];
  int v1433 = v1319 + ((v1317 - v1319) & (~((v1317 - v1319) >> 31)));
  v1->timer = v1433;
  int v1321 = v1->timer;
  int * v1322 = v1->reg_ready;
  int v1323 = v1322[18];
  int v1436 = v1323 + ((v1321 - v1323) & (~((v1321 - v1323) >> 31)));
  v1->timer = v1436;
  int v1325 = v1->timer;
  int * v1326 = v1->reg_ready;
  int v1327 = v1326[19];
  int v1439 = v1327 + ((v1325 - v1327) & (~((v1325 - v1327) >> 31)));
  v1->timer = v1439;
  int v1329 = v1->timer;
  int * v1330 = v1->reg_ready;
  int v1331 = v1330[20];
  int v1442 = v1331 + ((v1329 - v1331) & (~((v1329 - v1331) >> 31)));
  v1->timer = v1442;
  int v1333 = v1->timer;
  int * v1334 = v1->reg_ready;
  int v1335 = v1334[21];
  int v1445 = v1335 + ((v1333 - v1335) & (~((v1333 - v1335) >> 31)));
  v1->timer = v1445;
  int v1337 = v1->timer;
  int * v1338 = v1->reg_ready;
  int v1339 = v1338[22];
  int v1448 = v1339 + ((v1337 - v1339) & (~((v1337 - v1339) >> 31)));
  v1->timer = v1448;
  int v1341 = v1->timer;
  int * v1342 = v1->reg_ready;
  int v1343 = v1342[23];
  int v1451 = v1343 + ((v1341 - v1343) & (~((v1341 - v1343) >> 31)));
  v1->timer = v1451;
  int v1345 = v1->timer;
  int * v1346 = v1->reg_ready;
  int v1347 = v1346[24];
  int v1454 = v1347 + ((v1345 - v1347) & (~((v1345 - v1347) >> 31)));
  v1->timer = v1454;
  int v1349 = v1->timer;
  int * v1350 = v1->reg_ready;
  int v1351 = v1350[25];
  int v1457 = v1351 + ((v1349 - v1351) & (~((v1349 - v1351) >> 31)));
  v1->timer = v1457;
  int v1353 = v1->timer;
  int * v1354 = v1->reg_ready;
  int v1355 = v1354[26];
  int v1460 = v1355 + ((v1353 - v1355) & (~((v1353 - v1355) >> 31)));
  v1->timer = v1460;
  int v1357 = v1->timer;
  int * v1358 = v1->reg_ready;
  int v1359 = v1358[27];
  int v1463 = v1359 + ((v1357 - v1359) & (~((v1357 - v1359) >> 31)));
  v1->timer = v1463;
  int v1361 = v1->timer;
  int * v1362 = v1->reg_ready;
  int v1363 = v1362[28];
  int v1466 = v1363 + ((v1361 - v1363) & (~((v1361 - v1363) >> 31)));
  v1->timer = v1466;
  int v1365 = v1->timer;
  int * v1366 = v1->reg_ready;
  int v1367 = v1366[29];
  int v1469 = v1367 + ((v1365 - v1367) & (~((v1365 - v1367) >> 31)));
  v1->timer = v1469;
  int v1369 = v1->timer;
  int * v1370 = v1->reg_ready;
  int v1371 = v1370[30];
  int v1472 = v1371 + ((v1369 - v1371) & (~((v1369 - v1371) >> 31)));
  v1->timer = v1472;
  int v1373 = v1->timer;
  int * v1374 = v1->reg_ready;
  int v1375 = v1374[31];
  int v1475 = v1375 + ((v1373 - v1375) & (~((v1373 - v1375) >> 31)));
  v1->timer = v1475;
  return v1;
}

struct StateT * slot_1(struct StateT * v24) {
  int v25 = v24->timer;
  int v36 = v25 + 1;
  v24->timer = v36;
  int * v27 = v24->reg_ready;
  int v28 = v27[5];
  int * v29 = v24->regs;
  int v30 = v29[5];
  int v41 = (v28 + ((v25 - v28) & (~((v25 - v28) >> 31)))) + 1;
  v27[6] = v41;
  int * v32 = v24->regs;
  int v43 = v30 + 80;
  v32[6] = v43;
  struct StateT * v34 = slot_2(v24);
  return v34;
}

struct StateT * slot_6(struct StateT * v1044) {
  int v1045 = v1044->timer;
  int v1156 = v1045 + 1;
  v1044->timer = v1156;
  int * v1047 = v1044->reg_ready;
  int v1048 = v1047[11];
  int * v1049 = v1044->regs;
  int v1050 = v1049[11];
  int * v1051 = v1044->cache_tags;
  int v1161 = (((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1)) & 1) * 2;
  int v1052 = v1051[v1161];
  int v1162 = ((((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1053 = v1051[v1162];
  int v1163 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1)) & 3) * 2);
  int v1054 = v1051[v1163];
  int v1164 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1055 = v1051[v1164];
  int * v1056 = v1044->cache_vals;
  bool v1165 = !(((~(((v1052 ^ ((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1))) | (-(v1052 ^ ((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1))))) >> 31)) | (~(((v1053 ^ ((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1))) | (-(v1053 ^ ((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1))))) >> 31))) == 0);
  int v1149;
  if (v1165) {
    int * v1057 = v1044->cache_age;
    int v1167 = ((((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1)) & 1) * 2) + ((~(((v1053 ^ ((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1))) | (-(v1053 ^ ((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1))))) >> 31)) & 1);
    int v1058 = v1057[v1167];
    int v1059 = v1057[v1161];
    int v1168 = v1059 + ((int)((unsigned int)(v1059 - v1058) >> 31));
    v1057[v1161] = v1168;
    int * v1061 = v1044->cache_age;
    int v1062 = v1061[v1162];
    int v1170 = v1062 + ((int)((unsigned int)(v1062 - v1058) >> 31));
    v1061[v1162] = v1170;
    int * v1064 = v1044->cache_age;
    v1064[v1167] = 0;
    v1149 = v1167;
  } else {
    int * v1067 = v1044->cache_age;
    int v1174 = (((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1)) & 1) * 2;
    int v1068 = v1067[v1174];
    int * v1069 = v1044->cache_tags;
    int v1070 = v1069[v1174];
    int v1071 = v1067[v1162];
    int v1072 = v1069[v1162];
    bool v1176 = !(((~(((v1054 ^ ((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1))) | (-(v1054 ^ ((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1))))) >> 31)) | (~(((v1055 ^ ((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1))) | (-(v1055 ^ ((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1))))) >> 31))) == 0);
    int v1126;
    if (v1176) {
      int * v1073 = v1044->cache_age;
      int v1178 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1055 ^ ((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1))) | (-(v1055 ^ ((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1))))) >> 31)) & 1);
      int v1074 = v1073[v1178];
      int v1075 = v1073[v1163];
      int v1179 = v1075 + ((int)((unsigned int)(v1075 - v1074) >> 31));
      v1073[v1163] = v1179;
      int * v1077 = v1044->cache_age;
      int v1078 = v1077[v1164];
      int v1181 = v1078 + ((int)((unsigned int)(v1078 - v1074) >> 31));
      v1077[v1164] = v1181;
      int * v1080 = v1044->cache_age;
      v1080[v1178] = 0;
      v1126 = v1178;
    } else {
      int * v1083 = v1044->cache_age;
      int v1185 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1)) & 3) * 2);
      int v1084 = v1083[v1185];
      int * v1085 = v1044->cache_tags;
      int v1086 = v1085[v1185];
      int v1087 = v1083[v1164];
      int v1088 = v1085[v1164];
      int * v1089 = v1044->cache_dirty;
      int v1188 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1)) & 3) * 2)) + ((((v1084 + ((~(((v1086 ^ -1) | (-(v1086 ^ -1))) >> 31)) & 2)) - (v1087 + ((~(((v1088 ^ -1) | (-(v1088 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1090 = v1089[v1188];
      bool v1189 = !(v1090 == 0);
      if (v1189) {
        int * v1091 = v1044->cache_tags;
        int v1092 = v1091[v1188];
        int * v1093 = v1044->cache_vals;
        int v1192 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1)) & 3) * 2)) + ((((v1084 + ((~(((v1086 ^ -1) | (-(v1086 ^ -1))) >> 31)) & 2)) - (v1087 + ((~(((v1088 ^ -1) | (-(v1088 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1094 = v1093[v1192];
        int v1193 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1)) & 3) * 2)) + ((((v1084 + ((~(((v1086 ^ -1) | (-(v1086 ^ -1))) >> 31)) & 2)) - (v1087 + ((~(((v1088 ^ -1) | (-(v1088 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1095 = v1093[v1193];
        int * v1096 = v1044->mem;
        int v1195 = v1092 * 2;
        v1096[v1195] = v1094;
        int * v1098 = v1044->mem;
        int v1198 = (v1092 * 2) + 1;
        v1098[v1198] = v1095;
        ;
      } else {
        ;
      }
      int * v1103 = v1044->mem;
      int v1203 = ((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1)) * 2;
      int v1104 = v1103[v1203];
      int v1204 = (((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1)) * 2) + 1;
      int v1105 = v1103[v1204];
      int * v1106 = v1044->cache_vals;
      int v1206 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1)) & 3) * 2)) + ((((v1084 + ((~(((v1086 ^ -1) | (-(v1086 ^ -1))) >> 31)) & 2)) - (v1087 + ((~(((v1088 ^ -1) | (-(v1088 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1106[v1206] = v1104;
      int * v1108 = v1044->cache_vals;
      int v1209 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1)) & 3) * 2)) + ((((v1084 + ((~(((v1086 ^ -1) | (-(v1086 ^ -1))) >> 31)) & 2)) - (v1087 + ((~(((v1088 ^ -1) | (-(v1088 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1108[v1209] = v1105;
      int * v1110 = v1044->cache_tags;
      int v1212 = (int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1);
      v1110[v1188] = v1212;
      int * v1112 = v1044->cache_dirty;
      v1112[v1188] = 0;
      int * v1114 = v1044->cache_age;
      v1114[v1188] = 1;
      int * v1116 = v1044->cache_age;
      int v1117 = v1116[v1188];
      int v1118 = v1116[v1163];
      int v1218 = v1118 + ((int)((unsigned int)(v1118 - v1117) >> 31));
      v1116[v1163] = v1218;
      int * v1120 = v1044->cache_age;
      int v1121 = v1120[v1164];
      int v1220 = v1121 + ((int)((unsigned int)(v1121 - v1117) >> 31));
      v1120[v1164] = v1220;
      int * v1123 = v1044->cache_age;
      v1123[v1188] = 0;
      v1126 = v1188;
    }
    int * v1127 = v1044->cache_vals;
    int v1223 = v1126 * 2;
    int v1128 = v1127[v1223];
    int v1224 = (v1126 * 2) + 1;
    int v1129 = v1127[v1224];
    int v1225 = (((((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1)) & 1) * 2) + ((((v1068 + ((~(((v1070 ^ -1) | (-(v1070 ^ -1))) >> 31)) & 2)) - (v1071 + ((~(((v1072 ^ -1) | (-(v1072 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1127[v1225] = v1128;
    int * v1131 = v1044->cache_vals;
    int v1228 = ((((((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1)) & 1) * 2) + ((((v1068 + ((~(((v1070 ^ -1) | (-(v1070 ^ -1))) >> 31)) & 2)) - (v1071 + ((~(((v1072 ^ -1) | (-(v1072 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1131[v1228] = v1129;
    int * v1133 = v1044->cache_tags;
    int v1231 = ((((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1)) & 1) * 2) + ((((v1068 + ((~(((v1070 ^ -1) | (-(v1070 ^ -1))) >> 31)) & 2)) - (v1071 + ((~(((v1072 ^ -1) | (-(v1072 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1232 = (int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1);
    v1133[v1231] = v1232;
    int * v1135 = v1044->cache_dirty;
    v1135[v1231] = 0;
    int * v1137 = v1044->cache_age;
    v1137[v1231] = 1;
    int * v1139 = v1044->cache_age;
    int v1140 = v1139[v1231];
    int v1141 = v1139[v1161];
    int v1238 = v1141 + ((int)((unsigned int)(v1141 - v1140) >> 31));
    v1139[v1161] = v1238;
    int * v1143 = v1044->cache_age;
    int v1144 = v1143[v1162];
    int v1240 = v1144 + ((int)((unsigned int)(v1144 - v1140) >> 31));
    v1143[v1162] = v1240;
    int * v1146 = v1044->cache_age;
    v1146[v1231] = 0;
    v1149 = v1231;
  }
  int v1243 = (v1149 * 2) + (((int)((unsigned int)v1050 >> 2)) & 1);
  int v1150 = v1056[v1243];
  int * v1151 = v1044->reg_ready;
  int v1246 = ((v1048 + ((v1045 - v1048) & (~((v1045 - v1048) >> 31)))) + 1) + ((100 ^ (((~(((v1054 ^ ((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1))) | (-(v1054 ^ ((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1))))) >> 31)) | (~(((v1055 ^ ((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1))) | (-(v1055 ^ ((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1052 ^ ((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1))) | (-(v1052 ^ ((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1))))) >> 31)) | (~(((v1053 ^ ((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1))) | (-(v1053 ^ ((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1054 ^ ((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1))) | (-(v1054 ^ ((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1))))) >> 31)) | (~(((v1055 ^ ((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1))) | (-(v1055 ^ ((int)((unsigned int)((int)((unsigned int)v1050 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1151[12] = v1246;
  int * v1153 = v1044->regs;
  v1153[12] = v1150;
  return v1044;
}

struct StateT * slot_5(struct StateT * v836) {
  int v837 = v836->timer;
  int v949 = v837 + 1;
  v836->timer = v949;
  int * v839 = v836->reg_ready;
  int v840 = v839[8];
  int * v841 = v836->regs;
  int v842 = v841[8];
  int * v843 = v836->cache_tags;
  int v954 = (((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1)) & 1) * 2;
  int v844 = v843[v954];
  int v955 = ((((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1)) & 1) * 2) + 1;
  int v845 = v843[v955];
  int v956 = 4 + ((((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1)) & 3) * 2);
  int v846 = v843[v956];
  int v957 = (4 + ((((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v847 = v843[v957];
  int * v848 = v836->cache_vals;
  bool v958 = !(((~(((v844 ^ ((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1))) | (-(v844 ^ ((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1))))) >> 31)) | (~(((v845 ^ ((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1))) | (-(v845 ^ ((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1))))) >> 31))) == 0);
  int v941;
  if (v958) {
    int * v849 = v836->cache_age;
    int v960 = ((((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1)) & 1) * 2) + ((~(((v845 ^ ((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1))) | (-(v845 ^ ((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1))))) >> 31)) & 1);
    int v850 = v849[v960];
    int v851 = v849[v954];
    int v961 = v851 + ((int)((unsigned int)(v851 - v850) >> 31));
    v849[v954] = v961;
    int * v853 = v836->cache_age;
    int v854 = v853[v955];
    int v963 = v854 + ((int)((unsigned int)(v854 - v850) >> 31));
    v853[v955] = v963;
    int * v856 = v836->cache_age;
    v856[v960] = 0;
    v941 = v960;
  } else {
    int * v859 = v836->cache_age;
    int v967 = (((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1)) & 1) * 2;
    int v860 = v859[v967];
    int * v861 = v836->cache_tags;
    int v862 = v861[v967];
    int v863 = v859[v955];
    int v864 = v861[v955];
    bool v969 = !(((~(((v846 ^ ((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1))) | (-(v846 ^ ((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1))))) >> 31)) | (~(((v847 ^ ((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1))) | (-(v847 ^ ((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1))))) >> 31))) == 0);
    int v918;
    if (v969) {
      int * v865 = v836->cache_age;
      int v971 = (4 + ((((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1)) & 3) * 2)) + ((~(((v847 ^ ((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1))) | (-(v847 ^ ((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1))))) >> 31)) & 1);
      int v866 = v865[v971];
      int v867 = v865[v956];
      int v972 = v867 + ((int)((unsigned int)(v867 - v866) >> 31));
      v865[v956] = v972;
      int * v869 = v836->cache_age;
      int v870 = v869[v957];
      int v974 = v870 + ((int)((unsigned int)(v870 - v866) >> 31));
      v869[v957] = v974;
      int * v872 = v836->cache_age;
      v872[v971] = 0;
      v918 = v971;
    } else {
      int * v875 = v836->cache_age;
      int v978 = 4 + ((((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1)) & 3) * 2);
      int v876 = v875[v978];
      int * v877 = v836->cache_tags;
      int v878 = v877[v978];
      int v879 = v875[v957];
      int v880 = v877[v957];
      int * v881 = v836->cache_dirty;
      int v981 = (4 + ((((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1)) & 3) * 2)) + ((((v876 + ((~(((v878 ^ -1) | (-(v878 ^ -1))) >> 31)) & 2)) - (v879 + ((~(((v880 ^ -1) | (-(v880 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v882 = v881[v981];
      bool v982 = !(v882 == 0);
      if (v982) {
        int * v883 = v836->cache_tags;
        int v884 = v883[v981];
        int * v885 = v836->cache_vals;
        int v985 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1)) & 3) * 2)) + ((((v876 + ((~(((v878 ^ -1) | (-(v878 ^ -1))) >> 31)) & 2)) - (v879 + ((~(((v880 ^ -1) | (-(v880 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v886 = v885[v985];
        int v986 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1)) & 3) * 2)) + ((((v876 + ((~(((v878 ^ -1) | (-(v878 ^ -1))) >> 31)) & 2)) - (v879 + ((~(((v880 ^ -1) | (-(v880 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v887 = v885[v986];
        int * v888 = v836->mem;
        int v988 = v884 * 2;
        v888[v988] = v886;
        int * v890 = v836->mem;
        int v991 = (v884 * 2) + 1;
        v890[v991] = v887;
        ;
      } else {
        ;
      }
      int * v895 = v836->mem;
      int v996 = ((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1)) * 2;
      int v896 = v895[v996];
      int v997 = (((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1)) * 2) + 1;
      int v897 = v895[v997];
      int * v898 = v836->cache_vals;
      int v999 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1)) & 3) * 2)) + ((((v876 + ((~(((v878 ^ -1) | (-(v878 ^ -1))) >> 31)) & 2)) - (v879 + ((~(((v880 ^ -1) | (-(v880 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v898[v999] = v896;
      int * v900 = v836->cache_vals;
      int v1002 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1)) & 3) * 2)) + ((((v876 + ((~(((v878 ^ -1) | (-(v878 ^ -1))) >> 31)) & 2)) - (v879 + ((~(((v880 ^ -1) | (-(v880 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v900[v1002] = v897;
      int * v902 = v836->cache_tags;
      int v1005 = (int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1);
      v902[v981] = v1005;
      int * v904 = v836->cache_dirty;
      v904[v981] = 0;
      int * v906 = v836->cache_age;
      v906[v981] = 1;
      int * v908 = v836->cache_age;
      int v909 = v908[v981];
      int v910 = v908[v956];
      int v1011 = v910 + ((int)((unsigned int)(v910 - v909) >> 31));
      v908[v956] = v1011;
      int * v912 = v836->cache_age;
      int v913 = v912[v957];
      int v1013 = v913 + ((int)((unsigned int)(v913 - v909) >> 31));
      v912[v957] = v1013;
      int * v915 = v836->cache_age;
      v915[v981] = 0;
      v918 = v981;
    }
    int * v919 = v836->cache_vals;
    int v1016 = v918 * 2;
    int v920 = v919[v1016];
    int v1017 = (v918 * 2) + 1;
    int v921 = v919[v1017];
    int v1018 = (((((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1)) & 1) * 2) + ((((v860 + ((~(((v862 ^ -1) | (-(v862 ^ -1))) >> 31)) & 2)) - (v863 + ((~(((v864 ^ -1) | (-(v864 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v919[v1018] = v920;
    int * v923 = v836->cache_vals;
    int v1021 = ((((((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1)) & 1) * 2) + ((((v860 + ((~(((v862 ^ -1) | (-(v862 ^ -1))) >> 31)) & 2)) - (v863 + ((~(((v864 ^ -1) | (-(v864 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v923[v1021] = v921;
    int * v925 = v836->cache_tags;
    int v1024 = ((((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1)) & 1) * 2) + ((((v860 + ((~(((v862 ^ -1) | (-(v862 ^ -1))) >> 31)) & 2)) - (v863 + ((~(((v864 ^ -1) | (-(v864 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1025 = (int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1);
    v925[v1024] = v1025;
    int * v927 = v836->cache_dirty;
    v927[v1024] = 0;
    int * v929 = v836->cache_age;
    v929[v1024] = 1;
    int * v931 = v836->cache_age;
    int v932 = v931[v1024];
    int v933 = v931[v954];
    int v1031 = v933 + ((int)((unsigned int)(v933 - v932) >> 31));
    v931[v954] = v1031;
    int * v935 = v836->cache_age;
    int v936 = v935[v955];
    int v1033 = v936 + ((int)((unsigned int)(v936 - v932) >> 31));
    v935[v955] = v1033;
    int * v938 = v836->cache_age;
    v938[v1024] = 0;
    v941 = v1024;
  }
  int v1036 = (v941 * 2) + (((int)((unsigned int)v842 >> 2)) & 1);
  int v942 = v848[v1036];
  int * v943 = v836->reg_ready;
  int v1039 = ((v840 + ((v837 - v840) & (~((v837 - v840) >> 31)))) + 1) + ((100 ^ (((~(((v846 ^ ((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1))) | (-(v846 ^ ((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1))))) >> 31)) | (~(((v847 ^ ((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1))) | (-(v847 ^ ((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v844 ^ ((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1))) | (-(v844 ^ ((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1))))) >> 31)) | (~(((v845 ^ ((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1))) | (-(v845 ^ ((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v846 ^ ((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1))) | (-(v846 ^ ((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1))))) >> 31)) | (~(((v847 ^ ((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1))) | (-(v847 ^ ((int)((unsigned int)((int)((unsigned int)v842 >> 2)) >> 1))))) >> 31))) & 104)))));
  v943[11] = v1039;
  int * v945 = v836->regs;
  v945[11] = v942;
  struct StateT * v947 = slot_6(v836);
  return v947;
}

struct StateT * slot_4(struct StateT * v645) {
  int v646 = v645->timer;
  int v754 = v646 + 1;
  v645->timer = v754;
  int * v648 = v645->cache_tags;
  int v649 = v648[0];
  int v650 = v648[1];
  int v651 = v648[4];
  int v652 = v648[5];
  int * v653 = v645->cache_vals;
  bool v760 = !(((~(((v649 ^ 4) | (-(v649 ^ 4))) >> 31)) | (~(((v650 ^ 4) | (-(v650 ^ 4))) >> 31))) == 0);
  int v746;
  if (v760) {
    int * v654 = v645->cache_age;
    int v762 = (~(((v650 ^ 4) | (-(v650 ^ 4))) >> 31)) & 1;
    int v655 = v654[v762];
    int v656 = v654[0];
    int v763 = v656 + ((int)((unsigned int)(v656 - v655) >> 31));
    v654[0] = v763;
    int * v658 = v645->cache_age;
    int v659 = v658[1];
    int v765 = v659 + ((int)((unsigned int)(v659 - v655) >> 31));
    v658[1] = v765;
    int * v661 = v645->cache_age;
    v661[v762] = 0;
    v746 = v762;
  } else {
    int * v664 = v645->cache_age;
    int v665 = v664[0];
    int * v666 = v645->cache_tags;
    int v667 = v666[0];
    int v668 = v664[1];
    int v669 = v666[1];
    bool v769 = !(((~(((v651 ^ 4) | (-(v651 ^ 4))) >> 31)) | (~(((v652 ^ 4) | (-(v652 ^ 4))) >> 31))) == 0);
    int v723;
    if (v769) {
      int * v670 = v645->cache_age;
      int v771 = 4 + ((~(((v652 ^ 4) | (-(v652 ^ 4))) >> 31)) & 1);
      int v671 = v670[v771];
      int v672 = v670[4];
      int v772 = v672 + ((int)((unsigned int)(v672 - v671) >> 31));
      v670[4] = v772;
      int * v674 = v645->cache_age;
      int v675 = v674[5];
      int v774 = v675 + ((int)((unsigned int)(v675 - v671) >> 31));
      v674[5] = v774;
      int * v677 = v645->cache_age;
      v677[v771] = 0;
      v723 = v771;
    } else {
      int * v680 = v645->cache_age;
      int v681 = v680[4];
      int * v682 = v645->cache_tags;
      int v683 = v682[4];
      int v684 = v680[5];
      int v685 = v682[5];
      int * v686 = v645->cache_dirty;
      int v779 = 4 + ((((v681 + ((~(((v683 ^ -1) | (-(v683 ^ -1))) >> 31)) & 2)) - (v684 + ((~(((v685 ^ -1) | (-(v685 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v687 = v686[v779];
      bool v780 = !(v687 == 0);
      if (v780) {
        int * v688 = v645->cache_tags;
        int v689 = v688[v779];
        int * v690 = v645->cache_vals;
        int v783 = (4 + ((((v681 + ((~(((v683 ^ -1) | (-(v683 ^ -1))) >> 31)) & 2)) - (v684 + ((~(((v685 ^ -1) | (-(v685 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v691 = v690[v783];
        int v784 = ((4 + ((((v681 + ((~(((v683 ^ -1) | (-(v683 ^ -1))) >> 31)) & 2)) - (v684 + ((~(((v685 ^ -1) | (-(v685 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v692 = v690[v784];
        int * v693 = v645->mem;
        int v786 = v689 * 2;
        v693[v786] = v691;
        int * v695 = v645->mem;
        int v789 = (v689 * 2) + 1;
        v695[v789] = v692;
        ;
      } else {
        ;
      }
      int * v700 = v645->mem;
      int v701 = v700[8];
      int v702 = v700[9];
      int * v703 = v645->cache_vals;
      int v797 = (4 + ((((v681 + ((~(((v683 ^ -1) | (-(v683 ^ -1))) >> 31)) & 2)) - (v684 + ((~(((v685 ^ -1) | (-(v685 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v703[v797] = v701;
      int * v705 = v645->cache_vals;
      int v800 = ((4 + ((((v681 + ((~(((v683 ^ -1) | (-(v683 ^ -1))) >> 31)) & 2)) - (v684 + ((~(((v685 ^ -1) | (-(v685 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v705[v800] = v702;
      int * v707 = v645->cache_tags;
      v707[v779] = 4;
      int * v709 = v645->cache_dirty;
      v709[v779] = 0;
      int * v711 = v645->cache_age;
      v711[v779] = 1;
      int * v713 = v645->cache_age;
      int v714 = v713[v779];
      int v715 = v713[4];
      int v806 = v715 + ((int)((unsigned int)(v715 - v714) >> 31));
      v713[4] = v806;
      int * v717 = v645->cache_age;
      int v718 = v717[5];
      int v808 = v718 + ((int)((unsigned int)(v718 - v714) >> 31));
      v717[5] = v808;
      int * v720 = v645->cache_age;
      v720[v779] = 0;
      v723 = v779;
    }
    int * v724 = v645->cache_vals;
    int v811 = v723 * 2;
    int v725 = v724[v811];
    int v812 = (v723 * 2) + 1;
    int v726 = v724[v812];
    int v813 = ((((v665 + ((~(((v667 ^ -1) | (-(v667 ^ -1))) >> 31)) & 2)) - (v668 + ((~(((v669 ^ -1) | (-(v669 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v724[v813] = v725;
    int * v728 = v645->cache_vals;
    int v816 = (((((v665 + ((~(((v667 ^ -1) | (-(v667 ^ -1))) >> 31)) & 2)) - (v668 + ((~(((v669 ^ -1) | (-(v669 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v728[v816] = v726;
    int * v730 = v645->cache_tags;
    int v819 = (((v665 + ((~(((v667 ^ -1) | (-(v667 ^ -1))) >> 31)) & 2)) - (v668 + ((~(((v669 ^ -1) | (-(v669 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v730[v819] = 4;
    int * v732 = v645->cache_dirty;
    v732[v819] = 0;
    int * v734 = v645->cache_age;
    v734[v819] = 1;
    int * v736 = v645->cache_age;
    int v737 = v736[v819];
    int v738 = v736[0];
    int v823 = v738 + ((int)((unsigned int)(v738 - v737) >> 31));
    v736[0] = v823;
    int * v740 = v645->cache_age;
    int v741 = v740[1];
    int v825 = v741 + ((int)((unsigned int)(v741 - v737) >> 31));
    v740[1] = v825;
    int * v743 = v645->cache_age;
    v743[v819] = 0;
    v746 = v819;
  }
  int v828 = (v746 * 2) + 1;
  int v747 = v653[v828];
  int * v748 = v645->reg_ready;
  int v831 = (v646 + 1) + ((100 ^ (((~(((v651 ^ 4) | (-(v651 ^ 4))) >> 31)) | (~(((v652 ^ 4) | (-(v652 ^ 4))) >> 31))) & 104)) ^ (((~(((v649 ^ 4) | (-(v649 ^ 4))) >> 31)) | (~(((v650 ^ 4) | (-(v650 ^ 4))) >> 31))) & (1 ^ (100 ^ (((~(((v651 ^ 4) | (-(v651 ^ 4))) >> 31)) | (~(((v652 ^ 4) | (-(v652 ^ 4))) >> 31))) & 104)))));
  v748[8] = v831;
  int * v750 = v645->regs;
  v750[8] = v747;
  struct StateT * v752 = slot_5(v645);
  return v752;
}

struct StateT * slot_2(struct StateT * v46) {
  int v47 = v46->timer;
  int v218 = v47 + 1;
  v46->timer = v218;
  int * v49 = v46->reg_ready;
  int * v51 = v46->regs;
  int v52 = v51[6];
  int * v53 = v46->cache_tags;
  int v54 = v53[0];
  int v55 = v53[1];
  int v56 = v53[4];
  int v57 = v53[5];
  int v58 = v46->timer;
  int v227 = v58 + ((100 ^ (((~(((v56 ^ 4) | (-(v56 ^ 4))) >> 31)) | (~(((v57 ^ 4) | (-(v57 ^ 4))) >> 31))) & 104)) ^ (((~(((v54 ^ 4) | (-(v54 ^ 4))) >> 31)) | (~(((v55 ^ 4) | (-(v55 ^ 4))) >> 31))) & (1 ^ (100 ^ (((~(((v56 ^ 4) | (-(v56 ^ 4))) >> 31)) | (~(((v57 ^ 4) | (-(v57 ^ 4))) >> 31))) & 104)))));
  v46->timer = v227;
  bool v228 = !(((~(((v54 ^ 4) | (-(v54 ^ 4))) >> 31)) | (~(((v55 ^ 4) | (-(v55 ^ 4))) >> 31))) == 0);
  int v152;
  if (v228) {
    int * v60 = v46->cache_age;
    int v230 = (~(((v55 ^ 4) | (-(v55 ^ 4))) >> 31)) & 1;
    int v61 = v60[v230];
    int v62 = v60[0];
    int v231 = v62 + ((int)((unsigned int)(v62 - v61) >> 31));
    v60[0] = v231;
    int * v64 = v46->cache_age;
    int v65 = v64[1];
    int v233 = v65 + ((int)((unsigned int)(v65 - v61) >> 31));
    v64[1] = v233;
    int * v67 = v46->cache_age;
    v67[v230] = 0;
    v152 = v230;
  } else {
    int * v70 = v46->cache_age;
    int v71 = v70[0];
    int * v72 = v46->cache_tags;
    int v73 = v72[0];
    int v74 = v70[1];
    int v75 = v72[1];
    bool v237 = !(((~(((v56 ^ 4) | (-(v56 ^ 4))) >> 31)) | (~(((v57 ^ 4) | (-(v57 ^ 4))) >> 31))) == 0);
    int v129;
    if (v237) {
      int * v76 = v46->cache_age;
      int v239 = 4 + ((~(((v57 ^ 4) | (-(v57 ^ 4))) >> 31)) & 1);
      int v77 = v76[v239];
      int v78 = v76[4];
      int v240 = v78 + ((int)((unsigned int)(v78 - v77) >> 31));
      v76[4] = v240;
      int * v80 = v46->cache_age;
      int v81 = v80[5];
      int v242 = v81 + ((int)((unsigned int)(v81 - v77) >> 31));
      v80[5] = v242;
      int * v83 = v46->cache_age;
      v83[v239] = 0;
      v129 = v239;
    } else {
      int * v86 = v46->cache_age;
      int v87 = v86[4];
      int * v88 = v46->cache_tags;
      int v89 = v88[4];
      int v90 = v86[5];
      int v91 = v88[5];
      int * v92 = v46->cache_dirty;
      int v247 = 4 + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v90 + ((~(((v91 ^ -1) | (-(v91 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v93 = v92[v247];
      bool v248 = !(v93 == 0);
      if (v248) {
        int * v94 = v46->cache_tags;
        int v95 = v94[v247];
        int * v96 = v46->cache_vals;
        int v251 = (4 + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v90 + ((~(((v91 ^ -1) | (-(v91 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v97 = v96[v251];
        int v252 = ((4 + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v90 + ((~(((v91 ^ -1) | (-(v91 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v98 = v96[v252];
        int * v99 = v46->mem;
        int v254 = v95 * 2;
        v99[v254] = v97;
        int * v101 = v46->mem;
        int v257 = (v95 * 2) + 1;
        v101[v257] = v98;
        ;
      } else {
        ;
      }
      int * v106 = v46->mem;
      int v107 = v106[8];
      int v108 = v106[9];
      int * v109 = v46->cache_vals;
      int v265 = (4 + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v90 + ((~(((v91 ^ -1) | (-(v91 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v109[v265] = v107;
      int * v111 = v46->cache_vals;
      int v268 = ((4 + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v90 + ((~(((v91 ^ -1) | (-(v91 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v111[v268] = v108;
      int * v113 = v46->cache_tags;
      v113[v247] = 4;
      int * v115 = v46->cache_dirty;
      v115[v247] = 0;
      int * v117 = v46->cache_age;
      v117[v247] = 1;
      int * v119 = v46->cache_age;
      int v120 = v119[v247];
      int v121 = v119[4];
      int v274 = v121 + ((int)((unsigned int)(v121 - v120) >> 31));
      v119[4] = v274;
      int * v123 = v46->cache_age;
      int v124 = v123[5];
      int v276 = v124 + ((int)((unsigned int)(v124 - v120) >> 31));
      v123[5] = v276;
      int * v126 = v46->cache_age;
      v126[v247] = 0;
      v129 = v247;
    }
    int * v130 = v46->cache_vals;
    int v279 = v129 * 2;
    int v131 = v130[v279];
    int v280 = (v129 * 2) + 1;
    int v132 = v130[v280];
    int v281 = ((((v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v130[v281] = v131;
    int * v134 = v46->cache_vals;
    int v284 = (((((v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v134[v284] = v132;
    int * v136 = v46->cache_tags;
    int v287 = (((v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v136[v287] = 4;
    int * v138 = v46->cache_dirty;
    v138[v287] = 0;
    int * v140 = v46->cache_age;
    v140[v287] = 1;
    int * v142 = v46->cache_age;
    int v143 = v142[v287];
    int v144 = v142[0];
    int v291 = v144 + ((int)((unsigned int)(v144 - v143) >> 31));
    v142[0] = v291;
    int * v146 = v46->cache_age;
    int v147 = v146[1];
    int v293 = v147 + ((int)((unsigned int)(v147 - v143) >> 31));
    v146[1] = v293;
    int * v149 = v46->cache_age;
    v149[v287] = 0;
    v152 = v287;
  }
  int * v153 = v46->cache_vals;
  int v296 = (v152 * 2) + 1;
  v153[v296] = v52;
  int * v155 = v46->cache_tags;
  int v156 = v155[4];
  int v157 = v155[5];
  bool v299 = !(((~(((v156 ^ 4) | (-(v156 ^ 4))) >> 31)) | (~(((v157 ^ 4) | (-(v157 ^ 4))) >> 31))) == 0);
  int v211;
  if (v299) {
    int * v158 = v46->cache_age;
    int v301 = 4 + ((~(((v157 ^ 4) | (-(v157 ^ 4))) >> 31)) & 1);
    int v159 = v158[v301];
    int v160 = v158[4];
    int v302 = v160 + ((int)((unsigned int)(v160 - v159) >> 31));
    v158[4] = v302;
    int * v162 = v46->cache_age;
    int v163 = v162[5];
    int v304 = v163 + ((int)((unsigned int)(v163 - v159) >> 31));
    v162[5] = v304;
    int * v165 = v46->cache_age;
    v165[v301] = 0;
    v211 = v301;
  } else {
    int * v168 = v46->cache_age;
    int v169 = v168[4];
    int * v170 = v46->cache_tags;
    int v171 = v170[4];
    int v172 = v168[5];
    int v173 = v170[5];
    int * v174 = v46->cache_dirty;
    int v309 = 4 + ((((v169 + ((~(((v171 ^ -1) | (-(v171 ^ -1))) >> 31)) & 2)) - (v172 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v175 = v174[v309];
    bool v310 = !(v175 == 0);
    if (v310) {
      int * v176 = v46->cache_tags;
      int v177 = v176[v309];
      int * v178 = v46->cache_vals;
      int v313 = (4 + ((((v169 + ((~(((v171 ^ -1) | (-(v171 ^ -1))) >> 31)) & 2)) - (v172 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v179 = v178[v313];
      int v314 = ((4 + ((((v169 + ((~(((v171 ^ -1) | (-(v171 ^ -1))) >> 31)) & 2)) - (v172 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v180 = v178[v314];
      int * v181 = v46->mem;
      int v316 = v177 * 2;
      v181[v316] = v179;
      int * v183 = v46->mem;
      int v319 = (v177 * 2) + 1;
      v183[v319] = v180;
      ;
    } else {
      ;
    }
    int * v188 = v46->mem;
    int v189 = v188[8];
    int v190 = v188[9];
    int * v191 = v46->cache_vals;
    int v327 = (4 + ((((v169 + ((~(((v171 ^ -1) | (-(v171 ^ -1))) >> 31)) & 2)) - (v172 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v191[v327] = v189;
    int * v193 = v46->cache_vals;
    int v330 = ((4 + ((((v169 + ((~(((v171 ^ -1) | (-(v171 ^ -1))) >> 31)) & 2)) - (v172 + ((~(((v173 ^ -1) | (-(v173 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v193[v330] = v190;
    int * v195 = v46->cache_tags;
    v195[v309] = 4;
    int * v197 = v46->cache_dirty;
    v197[v309] = 0;
    int * v199 = v46->cache_age;
    v199[v309] = 1;
    int * v201 = v46->cache_age;
    int v202 = v201[v309];
    int v203 = v201[4];
    int v336 = v203 + ((int)((unsigned int)(v203 - v202) >> 31));
    v201[4] = v336;
    int * v205 = v46->cache_age;
    int v206 = v205[5];
    int v338 = v206 + ((int)((unsigned int)(v206 - v202) >> 31));
    v205[5] = v338;
    int * v208 = v46->cache_age;
    v208[v309] = 0;
    v211 = v309;
  }
  int * v212 = v46->cache_vals;
  int v341 = (v211 * 2) + 1;
  v212[v341] = v52;
  int * v214 = v46->cache_dirty;
  v214[v211] = 1;
  struct StateT * v216 = slot_3(v46);
  return v216;
}

struct StateT * slot_3(struct StateT * v346) {
  int v347 = v346->timer;
  int v518 = v347 + 1;
  v346->timer = v518;
  int * v349 = v346->reg_ready;
  int * v351 = v346->regs;
  int v352 = v351[5];
  int * v353 = v346->cache_tags;
  int v354 = v353[0];
  int v355 = v353[1];
  int v356 = v353[4];
  int v357 = v353[5];
  int v358 = v346->timer;
  int v526 = v358 + ((100 ^ (((~(((v356 ^ 4) | (-(v356 ^ 4))) >> 31)) | (~(((v357 ^ 4) | (-(v357 ^ 4))) >> 31))) & 104)) ^ (((~(((v354 ^ 4) | (-(v354 ^ 4))) >> 31)) | (~(((v355 ^ 4) | (-(v355 ^ 4))) >> 31))) & (1 ^ (100 ^ (((~(((v356 ^ 4) | (-(v356 ^ 4))) >> 31)) | (~(((v357 ^ 4) | (-(v357 ^ 4))) >> 31))) & 104)))));
  v346->timer = v526;
  bool v527 = !(((~(((v354 ^ 4) | (-(v354 ^ 4))) >> 31)) | (~(((v355 ^ 4) | (-(v355 ^ 4))) >> 31))) == 0);
  int v452;
  if (v527) {
    int * v360 = v346->cache_age;
    int v529 = (~(((v355 ^ 4) | (-(v355 ^ 4))) >> 31)) & 1;
    int v361 = v360[v529];
    int v362 = v360[0];
    int v530 = v362 + ((int)((unsigned int)(v362 - v361) >> 31));
    v360[0] = v530;
    int * v364 = v346->cache_age;
    int v365 = v364[1];
    int v532 = v365 + ((int)((unsigned int)(v365 - v361) >> 31));
    v364[1] = v532;
    int * v367 = v346->cache_age;
    v367[v529] = 0;
    v452 = v529;
  } else {
    int * v370 = v346->cache_age;
    int v371 = v370[0];
    int * v372 = v346->cache_tags;
    int v373 = v372[0];
    int v374 = v370[1];
    int v375 = v372[1];
    bool v536 = !(((~(((v356 ^ 4) | (-(v356 ^ 4))) >> 31)) | (~(((v357 ^ 4) | (-(v357 ^ 4))) >> 31))) == 0);
    int v429;
    if (v536) {
      int * v376 = v346->cache_age;
      int v538 = 4 + ((~(((v357 ^ 4) | (-(v357 ^ 4))) >> 31)) & 1);
      int v377 = v376[v538];
      int v378 = v376[4];
      int v539 = v378 + ((int)((unsigned int)(v378 - v377) >> 31));
      v376[4] = v539;
      int * v380 = v346->cache_age;
      int v381 = v380[5];
      int v541 = v381 + ((int)((unsigned int)(v381 - v377) >> 31));
      v380[5] = v541;
      int * v383 = v346->cache_age;
      v383[v538] = 0;
      v429 = v538;
    } else {
      int * v386 = v346->cache_age;
      int v387 = v386[4];
      int * v388 = v346->cache_tags;
      int v389 = v388[4];
      int v390 = v386[5];
      int v391 = v388[5];
      int * v392 = v346->cache_dirty;
      int v546 = 4 + ((((v387 + ((~(((v389 ^ -1) | (-(v389 ^ -1))) >> 31)) & 2)) - (v390 + ((~(((v391 ^ -1) | (-(v391 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v393 = v392[v546];
      bool v547 = !(v393 == 0);
      if (v547) {
        int * v394 = v346->cache_tags;
        int v395 = v394[v546];
        int * v396 = v346->cache_vals;
        int v550 = (4 + ((((v387 + ((~(((v389 ^ -1) | (-(v389 ^ -1))) >> 31)) & 2)) - (v390 + ((~(((v391 ^ -1) | (-(v391 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v397 = v396[v550];
        int v551 = ((4 + ((((v387 + ((~(((v389 ^ -1) | (-(v389 ^ -1))) >> 31)) & 2)) - (v390 + ((~(((v391 ^ -1) | (-(v391 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v398 = v396[v551];
        int * v399 = v346->mem;
        int v553 = v395 * 2;
        v399[v553] = v397;
        int * v401 = v346->mem;
        int v556 = (v395 * 2) + 1;
        v401[v556] = v398;
        ;
      } else {
        ;
      }
      int * v406 = v346->mem;
      int v407 = v406[8];
      int v408 = v406[9];
      int * v409 = v346->cache_vals;
      int v564 = (4 + ((((v387 + ((~(((v389 ^ -1) | (-(v389 ^ -1))) >> 31)) & 2)) - (v390 + ((~(((v391 ^ -1) | (-(v391 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v409[v564] = v407;
      int * v411 = v346->cache_vals;
      int v567 = ((4 + ((((v387 + ((~(((v389 ^ -1) | (-(v389 ^ -1))) >> 31)) & 2)) - (v390 + ((~(((v391 ^ -1) | (-(v391 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v411[v567] = v408;
      int * v413 = v346->cache_tags;
      v413[v546] = 4;
      int * v415 = v346->cache_dirty;
      v415[v546] = 0;
      int * v417 = v346->cache_age;
      v417[v546] = 1;
      int * v419 = v346->cache_age;
      int v420 = v419[v546];
      int v421 = v419[4];
      int v573 = v421 + ((int)((unsigned int)(v421 - v420) >> 31));
      v419[4] = v573;
      int * v423 = v346->cache_age;
      int v424 = v423[5];
      int v575 = v424 + ((int)((unsigned int)(v424 - v420) >> 31));
      v423[5] = v575;
      int * v426 = v346->cache_age;
      v426[v546] = 0;
      v429 = v546;
    }
    int * v430 = v346->cache_vals;
    int v578 = v429 * 2;
    int v431 = v430[v578];
    int v579 = (v429 * 2) + 1;
    int v432 = v430[v579];
    int v580 = ((((v371 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2)) - (v374 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v430[v580] = v431;
    int * v434 = v346->cache_vals;
    int v583 = (((((v371 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2)) - (v374 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v434[v583] = v432;
    int * v436 = v346->cache_tags;
    int v586 = (((v371 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2)) - (v374 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v436[v586] = 4;
    int * v438 = v346->cache_dirty;
    v438[v586] = 0;
    int * v440 = v346->cache_age;
    v440[v586] = 1;
    int * v442 = v346->cache_age;
    int v443 = v442[v586];
    int v444 = v442[0];
    int v590 = v444 + ((int)((unsigned int)(v444 - v443) >> 31));
    v442[0] = v590;
    int * v446 = v346->cache_age;
    int v447 = v446[1];
    int v592 = v447 + ((int)((unsigned int)(v447 - v443) >> 31));
    v446[1] = v592;
    int * v449 = v346->cache_age;
    v449[v586] = 0;
    v452 = v586;
  }
  int * v453 = v346->cache_vals;
  int v595 = (v452 * 2) + 1;
  v453[v595] = v352;
  int * v455 = v346->cache_tags;
  int v456 = v455[4];
  int v457 = v455[5];
  bool v598 = !(((~(((v456 ^ 4) | (-(v456 ^ 4))) >> 31)) | (~(((v457 ^ 4) | (-(v457 ^ 4))) >> 31))) == 0);
  int v511;
  if (v598) {
    int * v458 = v346->cache_age;
    int v600 = 4 + ((~(((v457 ^ 4) | (-(v457 ^ 4))) >> 31)) & 1);
    int v459 = v458[v600];
    int v460 = v458[4];
    int v601 = v460 + ((int)((unsigned int)(v460 - v459) >> 31));
    v458[4] = v601;
    int * v462 = v346->cache_age;
    int v463 = v462[5];
    int v603 = v463 + ((int)((unsigned int)(v463 - v459) >> 31));
    v462[5] = v603;
    int * v465 = v346->cache_age;
    v465[v600] = 0;
    v511 = v600;
  } else {
    int * v468 = v346->cache_age;
    int v469 = v468[4];
    int * v470 = v346->cache_tags;
    int v471 = v470[4];
    int v472 = v468[5];
    int v473 = v470[5];
    int * v474 = v346->cache_dirty;
    int v608 = 4 + ((((v469 + ((~(((v471 ^ -1) | (-(v471 ^ -1))) >> 31)) & 2)) - (v472 + ((~(((v473 ^ -1) | (-(v473 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v475 = v474[v608];
    bool v609 = !(v475 == 0);
    if (v609) {
      int * v476 = v346->cache_tags;
      int v477 = v476[v608];
      int * v478 = v346->cache_vals;
      int v612 = (4 + ((((v469 + ((~(((v471 ^ -1) | (-(v471 ^ -1))) >> 31)) & 2)) - (v472 + ((~(((v473 ^ -1) | (-(v473 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v479 = v478[v612];
      int v613 = ((4 + ((((v469 + ((~(((v471 ^ -1) | (-(v471 ^ -1))) >> 31)) & 2)) - (v472 + ((~(((v473 ^ -1) | (-(v473 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v480 = v478[v613];
      int * v481 = v346->mem;
      int v615 = v477 * 2;
      v481[v615] = v479;
      int * v483 = v346->mem;
      int v618 = (v477 * 2) + 1;
      v483[v618] = v480;
      ;
    } else {
      ;
    }
    int * v488 = v346->mem;
    int v489 = v488[8];
    int v490 = v488[9];
    int * v491 = v346->cache_vals;
    int v626 = (4 + ((((v469 + ((~(((v471 ^ -1) | (-(v471 ^ -1))) >> 31)) & 2)) - (v472 + ((~(((v473 ^ -1) | (-(v473 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v491[v626] = v489;
    int * v493 = v346->cache_vals;
    int v629 = ((4 + ((((v469 + ((~(((v471 ^ -1) | (-(v471 ^ -1))) >> 31)) & 2)) - (v472 + ((~(((v473 ^ -1) | (-(v473 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v493[v629] = v490;
    int * v495 = v346->cache_tags;
    v495[v608] = 4;
    int * v497 = v346->cache_dirty;
    v497[v608] = 0;
    int * v499 = v346->cache_age;
    v499[v608] = 1;
    int * v501 = v346->cache_age;
    int v502 = v501[v608];
    int v503 = v501[4];
    int v635 = v503 + ((int)((unsigned int)(v503 - v502) >> 31));
    v501[4] = v635;
    int * v505 = v346->cache_age;
    int v506 = v505[5];
    int v637 = v506 + ((int)((unsigned int)(v506 - v502) >> 31));
    v505[5] = v637;
    int * v508 = v346->cache_age;
    v508[v608] = 0;
    v511 = v608;
  }
  int * v512 = v346->cache_vals;
  int v640 = (v511 * 2) + 1;
  v512[v640] = v352;
  int * v514 = v346->cache_dirty;
  v514[v511] = 1;
  struct StateT * v516 = slot_4(v346);
  return v516;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v14 = v3 + 1;
  v2->timer = v14;
  int * v5 = v2->reg_ready;
  int v6 = v5[10];
  int * v7 = v2->regs;
  int v8 = v7[10];
  int v19 = (v6 + ((v3 - v6) & (~((v3 - v6) >> 31)))) + 1;
  v5[5] = v19;
  int * v10 = v2->regs;
  int v21 = v8 & 28;
  v10[5] = v21;
  struct StateT * v12 = slot_1(v2);
  return v12;
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