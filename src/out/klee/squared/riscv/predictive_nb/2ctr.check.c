// verify: leak (KLEE should report a failing assertion) [budget 1200s]
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

struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_1(struct StateT2 * v26);
struct StateT2 * slot_4(struct StateT2 * v967);
struct StateT2 * slot_2(struct StateT2 * v470);
struct StateT2 * slot_3(struct StateT2 * v523);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  struct StateT * v1061 = v1->a;
  int v1062 = v1061->timer;
  int * v1063 = v1061->reg_ready;
  int v1064 = v1063[0];
  int v1325 = v1064 + ((v1062 - v1064) & (~((v1062 - v1064) >> 31)));
  v1061->timer = v1325;
  int v1066 = v1061->timer;
  int * v1067 = v1061->reg_ready;
  int v1068 = v1067[1];
  int v1328 = v1068 + ((v1066 - v1068) & (~((v1066 - v1068) >> 31)));
  v1061->timer = v1328;
  int v1070 = v1061->timer;
  int * v1071 = v1061->reg_ready;
  int v1072 = v1071[2];
  int v1331 = v1072 + ((v1070 - v1072) & (~((v1070 - v1072) >> 31)));
  v1061->timer = v1331;
  int v1074 = v1061->timer;
  int * v1075 = v1061->reg_ready;
  int v1076 = v1075[3];
  int v1334 = v1076 + ((v1074 - v1076) & (~((v1074 - v1076) >> 31)));
  v1061->timer = v1334;
  int v1078 = v1061->timer;
  int * v1079 = v1061->reg_ready;
  int v1080 = v1079[4];
  int v1337 = v1080 + ((v1078 - v1080) & (~((v1078 - v1080) >> 31)));
  v1061->timer = v1337;
  int v1082 = v1061->timer;
  int * v1083 = v1061->reg_ready;
  int v1084 = v1083[5];
  int v1340 = v1084 + ((v1082 - v1084) & (~((v1082 - v1084) >> 31)));
  v1061->timer = v1340;
  int v1086 = v1061->timer;
  int * v1087 = v1061->reg_ready;
  int v1088 = v1087[6];
  int v1343 = v1088 + ((v1086 - v1088) & (~((v1086 - v1088) >> 31)));
  v1061->timer = v1343;
  int v1090 = v1061->timer;
  int * v1091 = v1061->reg_ready;
  int v1092 = v1091[7];
  int v1346 = v1092 + ((v1090 - v1092) & (~((v1090 - v1092) >> 31)));
  v1061->timer = v1346;
  int v1094 = v1061->timer;
  int * v1095 = v1061->reg_ready;
  int v1096 = v1095[8];
  int v1349 = v1096 + ((v1094 - v1096) & (~((v1094 - v1096) >> 31)));
  v1061->timer = v1349;
  int v1098 = v1061->timer;
  int * v1099 = v1061->reg_ready;
  int v1100 = v1099[9];
  int v1352 = v1100 + ((v1098 - v1100) & (~((v1098 - v1100) >> 31)));
  v1061->timer = v1352;
  int v1102 = v1061->timer;
  int * v1103 = v1061->reg_ready;
  int v1104 = v1103[10];
  int v1355 = v1104 + ((v1102 - v1104) & (~((v1102 - v1104) >> 31)));
  v1061->timer = v1355;
  int v1106 = v1061->timer;
  int * v1107 = v1061->reg_ready;
  int v1108 = v1107[11];
  int v1358 = v1108 + ((v1106 - v1108) & (~((v1106 - v1108) >> 31)));
  v1061->timer = v1358;
  int v1110 = v1061->timer;
  int * v1111 = v1061->reg_ready;
  int v1112 = v1111[12];
  int v1361 = v1112 + ((v1110 - v1112) & (~((v1110 - v1112) >> 31)));
  v1061->timer = v1361;
  int v1114 = v1061->timer;
  int * v1115 = v1061->reg_ready;
  int v1116 = v1115[13];
  int v1364 = v1116 + ((v1114 - v1116) & (~((v1114 - v1116) >> 31)));
  v1061->timer = v1364;
  int v1118 = v1061->timer;
  int * v1119 = v1061->reg_ready;
  int v1120 = v1119[14];
  int v1367 = v1120 + ((v1118 - v1120) & (~((v1118 - v1120) >> 31)));
  v1061->timer = v1367;
  int v1122 = v1061->timer;
  int * v1123 = v1061->reg_ready;
  int v1124 = v1123[15];
  int v1370 = v1124 + ((v1122 - v1124) & (~((v1122 - v1124) >> 31)));
  v1061->timer = v1370;
  int v1126 = v1061->timer;
  int * v1127 = v1061->reg_ready;
  int v1128 = v1127[16];
  int v1373 = v1128 + ((v1126 - v1128) & (~((v1126 - v1128) >> 31)));
  v1061->timer = v1373;
  int v1130 = v1061->timer;
  int * v1131 = v1061->reg_ready;
  int v1132 = v1131[17];
  int v1376 = v1132 + ((v1130 - v1132) & (~((v1130 - v1132) >> 31)));
  v1061->timer = v1376;
  int v1134 = v1061->timer;
  int * v1135 = v1061->reg_ready;
  int v1136 = v1135[18];
  int v1379 = v1136 + ((v1134 - v1136) & (~((v1134 - v1136) >> 31)));
  v1061->timer = v1379;
  int v1138 = v1061->timer;
  int * v1139 = v1061->reg_ready;
  int v1140 = v1139[19];
  int v1382 = v1140 + ((v1138 - v1140) & (~((v1138 - v1140) >> 31)));
  v1061->timer = v1382;
  int v1142 = v1061->timer;
  int * v1143 = v1061->reg_ready;
  int v1144 = v1143[20];
  int v1385 = v1144 + ((v1142 - v1144) & (~((v1142 - v1144) >> 31)));
  v1061->timer = v1385;
  int v1146 = v1061->timer;
  int * v1147 = v1061->reg_ready;
  int v1148 = v1147[21];
  int v1388 = v1148 + ((v1146 - v1148) & (~((v1146 - v1148) >> 31)));
  v1061->timer = v1388;
  int v1150 = v1061->timer;
  int * v1151 = v1061->reg_ready;
  int v1152 = v1151[22];
  int v1391 = v1152 + ((v1150 - v1152) & (~((v1150 - v1152) >> 31)));
  v1061->timer = v1391;
  int v1154 = v1061->timer;
  int * v1155 = v1061->reg_ready;
  int v1156 = v1155[23];
  int v1394 = v1156 + ((v1154 - v1156) & (~((v1154 - v1156) >> 31)));
  v1061->timer = v1394;
  int v1158 = v1061->timer;
  int * v1159 = v1061->reg_ready;
  int v1160 = v1159[24];
  int v1397 = v1160 + ((v1158 - v1160) & (~((v1158 - v1160) >> 31)));
  v1061->timer = v1397;
  int v1162 = v1061->timer;
  int * v1163 = v1061->reg_ready;
  int v1164 = v1163[25];
  int v1400 = v1164 + ((v1162 - v1164) & (~((v1162 - v1164) >> 31)));
  v1061->timer = v1400;
  int v1166 = v1061->timer;
  int * v1167 = v1061->reg_ready;
  int v1168 = v1167[26];
  int v1403 = v1168 + ((v1166 - v1168) & (~((v1166 - v1168) >> 31)));
  v1061->timer = v1403;
  int v1170 = v1061->timer;
  int * v1171 = v1061->reg_ready;
  int v1172 = v1171[27];
  int v1406 = v1172 + ((v1170 - v1172) & (~((v1170 - v1172) >> 31)));
  v1061->timer = v1406;
  int v1174 = v1061->timer;
  int * v1175 = v1061->reg_ready;
  int v1176 = v1175[28];
  int v1409 = v1176 + ((v1174 - v1176) & (~((v1174 - v1176) >> 31)));
  v1061->timer = v1409;
  int v1178 = v1061->timer;
  int * v1179 = v1061->reg_ready;
  int v1180 = v1179[29];
  int v1412 = v1180 + ((v1178 - v1180) & (~((v1178 - v1180) >> 31)));
  v1061->timer = v1412;
  int v1182 = v1061->timer;
  int * v1183 = v1061->reg_ready;
  int v1184 = v1183[30];
  int v1415 = v1184 + ((v1182 - v1184) & (~((v1182 - v1184) >> 31)));
  v1061->timer = v1415;
  int v1186 = v1061->timer;
  int * v1187 = v1061->reg_ready;
  int v1188 = v1187[31];
  int v1418 = v1188 + ((v1186 - v1188) & (~((v1186 - v1188) >> 31)));
  v1061->timer = v1418;
  struct StateT * v1190 = v1->b;
  int v1191 = v1190->timer;
  int * v1192 = v1190->reg_ready;
  int v1193 = v1192[0];
  int v1421 = v1193 + ((v1191 - v1193) & (~((v1191 - v1193) >> 31)));
  v1190->timer = v1421;
  int v1195 = v1190->timer;
  int * v1196 = v1190->reg_ready;
  int v1197 = v1196[1];
  int v1423 = v1197 + ((v1195 - v1197) & (~((v1195 - v1197) >> 31)));
  v1190->timer = v1423;
  int v1199 = v1190->timer;
  int * v1200 = v1190->reg_ready;
  int v1201 = v1200[2];
  int v1425 = v1201 + ((v1199 - v1201) & (~((v1199 - v1201) >> 31)));
  v1190->timer = v1425;
  int v1203 = v1190->timer;
  int * v1204 = v1190->reg_ready;
  int v1205 = v1204[3];
  int v1427 = v1205 + ((v1203 - v1205) & (~((v1203 - v1205) >> 31)));
  v1190->timer = v1427;
  int v1207 = v1190->timer;
  int * v1208 = v1190->reg_ready;
  int v1209 = v1208[4];
  int v1429 = v1209 + ((v1207 - v1209) & (~((v1207 - v1209) >> 31)));
  v1190->timer = v1429;
  int v1211 = v1190->timer;
  int * v1212 = v1190->reg_ready;
  int v1213 = v1212[5];
  int v1431 = v1213 + ((v1211 - v1213) & (~((v1211 - v1213) >> 31)));
  v1190->timer = v1431;
  int v1215 = v1190->timer;
  int * v1216 = v1190->reg_ready;
  int v1217 = v1216[6];
  int v1433 = v1217 + ((v1215 - v1217) & (~((v1215 - v1217) >> 31)));
  v1190->timer = v1433;
  int v1219 = v1190->timer;
  int * v1220 = v1190->reg_ready;
  int v1221 = v1220[7];
  int v1435 = v1221 + ((v1219 - v1221) & (~((v1219 - v1221) >> 31)));
  v1190->timer = v1435;
  int v1223 = v1190->timer;
  int * v1224 = v1190->reg_ready;
  int v1225 = v1224[8];
  int v1437 = v1225 + ((v1223 - v1225) & (~((v1223 - v1225) >> 31)));
  v1190->timer = v1437;
  int v1227 = v1190->timer;
  int * v1228 = v1190->reg_ready;
  int v1229 = v1228[9];
  int v1439 = v1229 + ((v1227 - v1229) & (~((v1227 - v1229) >> 31)));
  v1190->timer = v1439;
  int v1231 = v1190->timer;
  int * v1232 = v1190->reg_ready;
  int v1233 = v1232[10];
  int v1441 = v1233 + ((v1231 - v1233) & (~((v1231 - v1233) >> 31)));
  v1190->timer = v1441;
  int v1235 = v1190->timer;
  int * v1236 = v1190->reg_ready;
  int v1237 = v1236[11];
  int v1443 = v1237 + ((v1235 - v1237) & (~((v1235 - v1237) >> 31)));
  v1190->timer = v1443;
  int v1239 = v1190->timer;
  int * v1240 = v1190->reg_ready;
  int v1241 = v1240[12];
  int v1445 = v1241 + ((v1239 - v1241) & (~((v1239 - v1241) >> 31)));
  v1190->timer = v1445;
  int v1243 = v1190->timer;
  int * v1244 = v1190->reg_ready;
  int v1245 = v1244[13];
  int v1447 = v1245 + ((v1243 - v1245) & (~((v1243 - v1245) >> 31)));
  v1190->timer = v1447;
  int v1247 = v1190->timer;
  int * v1248 = v1190->reg_ready;
  int v1249 = v1248[14];
  int v1449 = v1249 + ((v1247 - v1249) & (~((v1247 - v1249) >> 31)));
  v1190->timer = v1449;
  int v1251 = v1190->timer;
  int * v1252 = v1190->reg_ready;
  int v1253 = v1252[15];
  int v1451 = v1253 + ((v1251 - v1253) & (~((v1251 - v1253) >> 31)));
  v1190->timer = v1451;
  int v1255 = v1190->timer;
  int * v1256 = v1190->reg_ready;
  int v1257 = v1256[16];
  int v1453 = v1257 + ((v1255 - v1257) & (~((v1255 - v1257) >> 31)));
  v1190->timer = v1453;
  int v1259 = v1190->timer;
  int * v1260 = v1190->reg_ready;
  int v1261 = v1260[17];
  int v1455 = v1261 + ((v1259 - v1261) & (~((v1259 - v1261) >> 31)));
  v1190->timer = v1455;
  int v1263 = v1190->timer;
  int * v1264 = v1190->reg_ready;
  int v1265 = v1264[18];
  int v1457 = v1265 + ((v1263 - v1265) & (~((v1263 - v1265) >> 31)));
  v1190->timer = v1457;
  int v1267 = v1190->timer;
  int * v1268 = v1190->reg_ready;
  int v1269 = v1268[19];
  int v1459 = v1269 + ((v1267 - v1269) & (~((v1267 - v1269) >> 31)));
  v1190->timer = v1459;
  int v1271 = v1190->timer;
  int * v1272 = v1190->reg_ready;
  int v1273 = v1272[20];
  int v1461 = v1273 + ((v1271 - v1273) & (~((v1271 - v1273) >> 31)));
  v1190->timer = v1461;
  int v1275 = v1190->timer;
  int * v1276 = v1190->reg_ready;
  int v1277 = v1276[21];
  int v1463 = v1277 + ((v1275 - v1277) & (~((v1275 - v1277) >> 31)));
  v1190->timer = v1463;
  int v1279 = v1190->timer;
  int * v1280 = v1190->reg_ready;
  int v1281 = v1280[22];
  int v1465 = v1281 + ((v1279 - v1281) & (~((v1279 - v1281) >> 31)));
  v1190->timer = v1465;
  int v1283 = v1190->timer;
  int * v1284 = v1190->reg_ready;
  int v1285 = v1284[23];
  int v1467 = v1285 + ((v1283 - v1285) & (~((v1283 - v1285) >> 31)));
  v1190->timer = v1467;
  int v1287 = v1190->timer;
  int * v1288 = v1190->reg_ready;
  int v1289 = v1288[24];
  int v1469 = v1289 + ((v1287 - v1289) & (~((v1287 - v1289) >> 31)));
  v1190->timer = v1469;
  int v1291 = v1190->timer;
  int * v1292 = v1190->reg_ready;
  int v1293 = v1292[25];
  int v1471 = v1293 + ((v1291 - v1293) & (~((v1291 - v1293) >> 31)));
  v1190->timer = v1471;
  int v1295 = v1190->timer;
  int * v1296 = v1190->reg_ready;
  int v1297 = v1296[26];
  int v1473 = v1297 + ((v1295 - v1297) & (~((v1295 - v1297) >> 31)));
  v1190->timer = v1473;
  int v1299 = v1190->timer;
  int * v1300 = v1190->reg_ready;
  int v1301 = v1300[27];
  int v1475 = v1301 + ((v1299 - v1301) & (~((v1299 - v1301) >> 31)));
  v1190->timer = v1475;
  int v1303 = v1190->timer;
  int * v1304 = v1190->reg_ready;
  int v1305 = v1304[28];
  int v1477 = v1305 + ((v1303 - v1305) & (~((v1303 - v1305) >> 31)));
  v1190->timer = v1477;
  int v1307 = v1190->timer;
  int * v1308 = v1190->reg_ready;
  int v1309 = v1308[29];
  int v1479 = v1309 + ((v1307 - v1309) & (~((v1307 - v1309) >> 31)));
  v1190->timer = v1479;
  int v1311 = v1190->timer;
  int * v1312 = v1190->reg_ready;
  int v1313 = v1312[30];
  int v1481 = v1313 + ((v1311 - v1313) & (~((v1311 - v1313) >> 31)));
  v1190->timer = v1481;
  int v1315 = v1190->timer;
  int * v1316 = v1190->reg_ready;
  int v1317 = v1316[31];
  int v1483 = v1317 + ((v1315 - v1317) & (~((v1315 - v1317) >> 31)));
  v1190->timer = v1483;
  return v1;
}

struct StateT2 * slot_1(struct StateT2 * v26) {
  struct StateT * v27 = v26->a;
  int v28 = v27->timer;
  struct StateT * v29 = v26->b;
  int v30 = v29->timer;
  bool v271 = v28 == v30;
  squared_assert(v271);
  squared_assume(v271);
  struct StateT * v33 = v26->a;
  int * v34 = v33->saved_regs;
  int * v35 = v33->regs;
  int v36 = v35[11];
  v34[11] = v36;
  struct StateT * v38 = v26->b;
  int * v39 = v38->saved_regs;
  int * v40 = v38->regs;
  int v41 = v40[11];
  v39[11] = v41;
  struct StateT * v43 = v26->a;
  int v44 = v43->timer;
  int v282 = v44 + 1;
  v43->timer = v282;
  struct StateT * v46 = v26->b;
  int v47 = v46->timer;
  int v284 = v47 + 1;
  v46->timer = v284;
  struct StateT * v49 = v26->a;
  int * v50 = v49->reg_ready;
  int v51 = v50[10];
  int * v52 = v49->regs;
  int v53 = v52[10];
  int * v54 = v49->cache_tags;
  int v290 = (((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 1) * 2;
  int v55 = v54[v290];
  int v291 = ((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 1) * 2) + 1;
  int v56 = v54[v291];
  int v292 = 4 + ((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 3) * 2);
  int v57 = v54[v292];
  int v293 = (4 + ((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v58 = v54[v293];
  int * v59 = v49->cache_vals;
  bool v294 = !(((~(((v55 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))) | (-(v55 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))))) >> 31)) | (~(((v56 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))) | (-(v56 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))))) >> 31))) == 0);
  int v152;
  if (v294) {
    int * v60 = v49->cache_age;
    int v296 = ((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 1) * 2) + ((~(((v56 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))) | (-(v56 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))))) >> 31)) & 1);
    int v61 = v60[v296];
    int v62 = v60[v290];
    int v297 = v62 + ((int)((unsigned int)(v62 - v61) >> 31));
    v60[v290] = v297;
    int * v64 = v49->cache_age;
    int v65 = v64[v291];
    int v299 = v65 + ((int)((unsigned int)(v65 - v61) >> 31));
    v64[v291] = v299;
    int * v67 = v49->cache_age;
    v67[v296] = 0;
    v152 = v296;
  } else {
    int * v70 = v49->cache_age;
    int v303 = (((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 1) * 2;
    int v71 = v70[v303];
    int * v72 = v49->cache_tags;
    int v73 = v72[v303];
    int v74 = v70[v291];
    int v75 = v72[v291];
    bool v305 = !(((~(((v57 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))) | (-(v57 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))))) >> 31)) | (~(((v58 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))) | (-(v58 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))))) >> 31))) == 0);
    int v129;
    if (v305) {
      int * v76 = v49->cache_age;
      int v307 = (4 + ((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 3) * 2)) + ((~(((v58 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))) | (-(v58 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))))) >> 31)) & 1);
      int v77 = v76[v307];
      int v78 = v76[v292];
      int v308 = v78 + ((int)((unsigned int)(v78 - v77) >> 31));
      v76[v292] = v308;
      int * v80 = v49->cache_age;
      int v81 = v80[v293];
      int v310 = v81 + ((int)((unsigned int)(v81 - v77) >> 31));
      v80[v293] = v310;
      int * v83 = v49->cache_age;
      v83[v307] = 0;
      v129 = v307;
    } else {
      int * v86 = v49->cache_age;
      int v314 = 4 + ((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 3) * 2);
      int v87 = v86[v314];
      int * v88 = v49->cache_tags;
      int v89 = v88[v314];
      int v90 = v86[v293];
      int v91 = v88[v293];
      int * v92 = v49->cache_dirty;
      int v317 = (4 + ((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 3) * 2)) + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v90 + ((~(((v91 ^ -1) | (-(v91 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v93 = v92[v317];
      bool v318 = !(v93 == 0);
      if (v318) {
        int * v94 = v49->cache_tags;
        int v95 = v94[v317];
        int * v96 = v49->cache_vals;
        int v321 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 3) * 2)) + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v90 + ((~(((v91 ^ -1) | (-(v91 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v97 = v96[v321];
        int v322 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 3) * 2)) + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v90 + ((~(((v91 ^ -1) | (-(v91 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v98 = v96[v322];
        int * v99 = v49->mem;
        int v324 = v95 * 2;
        v99[v324] = v97;
        int * v101 = v49->mem;
        int v327 = (v95 * 2) + 1;
        v101[v327] = v98;
        ;
      } else {
        ;
      }
      int * v106 = v49->mem;
      int v332 = ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) * 2;
      int v107 = v106[v332];
      int v333 = (((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) * 2) + 1;
      int v108 = v106[v333];
      int * v109 = v49->cache_vals;
      int v335 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 3) * 2)) + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v90 + ((~(((v91 ^ -1) | (-(v91 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v109[v335] = v107;
      int * v111 = v49->cache_vals;
      int v338 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 3) * 2)) + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v90 + ((~(((v91 ^ -1) | (-(v91 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v111[v338] = v108;
      int * v113 = v49->cache_tags;
      int v341 = (int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1);
      v113[v317] = v341;
      int * v115 = v49->cache_dirty;
      v115[v317] = 0;
      int * v117 = v49->cache_age;
      v117[v317] = 1;
      int * v119 = v49->cache_age;
      int v120 = v119[v317];
      int v121 = v119[v292];
      int v347 = v121 + ((int)((unsigned int)(v121 - v120) >> 31));
      v119[v292] = v347;
      int * v123 = v49->cache_age;
      int v124 = v123[v293];
      int v349 = v124 + ((int)((unsigned int)(v124 - v120) >> 31));
      v123[v293] = v349;
      int * v126 = v49->cache_age;
      v126[v317] = 0;
      v129 = v317;
    }
    int * v130 = v49->cache_vals;
    int v352 = v129 * 2;
    int v131 = v130[v352];
    int v353 = (v129 * 2) + 1;
    int v132 = v130[v353];
    int v354 = (((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 1) * 2) + ((((v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v130[v354] = v131;
    int * v134 = v49->cache_vals;
    int v357 = ((((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 1) * 2) + ((((v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v134[v357] = v132;
    int * v136 = v49->cache_tags;
    int v360 = ((((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1)) & 1) * 2) + ((((v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v361 = (int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1);
    v136[v360] = v361;
    int * v138 = v49->cache_dirty;
    v138[v360] = 0;
    int * v140 = v49->cache_age;
    v140[v360] = 1;
    int * v142 = v49->cache_age;
    int v143 = v142[v360];
    int v144 = v142[v290];
    int v367 = v144 + ((int)((unsigned int)(v144 - v143) >> 31));
    v142[v290] = v367;
    int * v146 = v49->cache_age;
    int v147 = v146[v291];
    int v369 = v147 + ((int)((unsigned int)(v147 - v143) >> 31));
    v146[v291] = v369;
    int * v149 = v49->cache_age;
    v149[v360] = 0;
    v152 = v360;
  }
  int v372 = (v152 * 2) + (((int)((unsigned int)v53 >> 2)) & 1);
  int v153 = v59[v372];
  int * v154 = v49->reg_ready;
  int v374 = ((v51 + ((v44 - v51) & (~((v44 - v51) >> 31)))) + 1) + ((100 ^ (((~(((v57 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))) | (-(v57 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))))) >> 31)) | (~(((v58 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))) | (-(v58 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v55 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))) | (-(v55 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))))) >> 31)) | (~(((v56 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))) | (-(v56 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v57 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))) | (-(v57 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))))) >> 31)) | (~(((v58 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))) | (-(v58 ^ ((int)((unsigned int)((int)((unsigned int)v53 >> 2)) >> 1))))) >> 31))) & 104)))));
  v154[11] = v374;
  int * v156 = v49->regs;
  v156[11] = v153;
  struct StateT * v158 = v26->b;
  int * v159 = v158->reg_ready;
  int v160 = v159[10];
  int * v161 = v158->regs;
  int v162 = v161[10];
  int * v163 = v158->cache_tags;
  int v381 = (((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1)) & 1) * 2;
  int v164 = v163[v381];
  int v382 = ((((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1)) & 1) * 2) + 1;
  int v165 = v163[v382];
  int v383 = 4 + ((((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1)) & 3) * 2);
  int v166 = v163[v383];
  int v384 = (4 + ((((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v167 = v163[v384];
  int * v168 = v158->cache_vals;
  bool v385 = !(((~(((v164 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))) | (-(v164 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))))) >> 31)) | (~(((v165 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))) | (-(v165 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))))) >> 31))) == 0);
  int v261;
  if (v385) {
    int * v169 = v158->cache_age;
    int v387 = ((((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1)) & 1) * 2) + ((~(((v165 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))) | (-(v165 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))))) >> 31)) & 1);
    int v170 = v169[v387];
    int v171 = v169[v381];
    int v388 = v171 + ((int)((unsigned int)(v171 - v170) >> 31));
    v169[v381] = v388;
    int * v173 = v158->cache_age;
    int v174 = v173[v382];
    int v390 = v174 + ((int)((unsigned int)(v174 - v170) >> 31));
    v173[v382] = v390;
    int * v176 = v158->cache_age;
    v176[v387] = 0;
    v261 = v387;
  } else {
    int * v179 = v158->cache_age;
    int v394 = (((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1)) & 1) * 2;
    int v180 = v179[v394];
    int * v181 = v158->cache_tags;
    int v182 = v181[v394];
    int v183 = v179[v382];
    int v184 = v181[v382];
    bool v396 = !(((~(((v166 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))) | (-(v166 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))))) >> 31)) | (~(((v167 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))) | (-(v167 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))))) >> 31))) == 0);
    int v238;
    if (v396) {
      int * v185 = v158->cache_age;
      int v398 = (4 + ((((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1)) & 3) * 2)) + ((~(((v167 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))) | (-(v167 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))))) >> 31)) & 1);
      int v186 = v185[v398];
      int v187 = v185[v383];
      int v399 = v187 + ((int)((unsigned int)(v187 - v186) >> 31));
      v185[v383] = v399;
      int * v189 = v158->cache_age;
      int v190 = v189[v384];
      int v401 = v190 + ((int)((unsigned int)(v190 - v186) >> 31));
      v189[v384] = v401;
      int * v192 = v158->cache_age;
      v192[v398] = 0;
      v238 = v398;
    } else {
      int * v195 = v158->cache_age;
      int v405 = 4 + ((((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1)) & 3) * 2);
      int v196 = v195[v405];
      int * v197 = v158->cache_tags;
      int v198 = v197[v405];
      int v199 = v195[v384];
      int v200 = v197[v384];
      int * v201 = v158->cache_dirty;
      int v408 = (4 + ((((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1)) & 3) * 2)) + ((((v196 + ((~(((v198 ^ -1) | (-(v198 ^ -1))) >> 31)) & 2)) - (v199 + ((~(((v200 ^ -1) | (-(v200 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v202 = v201[v408];
      bool v409 = !(v202 == 0);
      if (v409) {
        int * v203 = v158->cache_tags;
        int v204 = v203[v408];
        int * v205 = v158->cache_vals;
        int v412 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1)) & 3) * 2)) + ((((v196 + ((~(((v198 ^ -1) | (-(v198 ^ -1))) >> 31)) & 2)) - (v199 + ((~(((v200 ^ -1) | (-(v200 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v206 = v205[v412];
        int v413 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1)) & 3) * 2)) + ((((v196 + ((~(((v198 ^ -1) | (-(v198 ^ -1))) >> 31)) & 2)) - (v199 + ((~(((v200 ^ -1) | (-(v200 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v207 = v205[v413];
        int * v208 = v158->mem;
        int v415 = v204 * 2;
        v208[v415] = v206;
        int * v210 = v158->mem;
        int v418 = (v204 * 2) + 1;
        v210[v418] = v207;
        ;
      } else {
        ;
      }
      int * v215 = v158->mem;
      int v423 = ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1)) * 2;
      int v216 = v215[v423];
      int v424 = (((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1)) * 2) + 1;
      int v217 = v215[v424];
      int * v218 = v158->cache_vals;
      int v426 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1)) & 3) * 2)) + ((((v196 + ((~(((v198 ^ -1) | (-(v198 ^ -1))) >> 31)) & 2)) - (v199 + ((~(((v200 ^ -1) | (-(v200 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v218[v426] = v216;
      int * v220 = v158->cache_vals;
      int v429 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1)) & 3) * 2)) + ((((v196 + ((~(((v198 ^ -1) | (-(v198 ^ -1))) >> 31)) & 2)) - (v199 + ((~(((v200 ^ -1) | (-(v200 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v220[v429] = v217;
      int * v222 = v158->cache_tags;
      int v432 = (int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1);
      v222[v408] = v432;
      int * v224 = v158->cache_dirty;
      v224[v408] = 0;
      int * v226 = v158->cache_age;
      v226[v408] = 1;
      int * v228 = v158->cache_age;
      int v229 = v228[v408];
      int v230 = v228[v383];
      int v438 = v230 + ((int)((unsigned int)(v230 - v229) >> 31));
      v228[v383] = v438;
      int * v232 = v158->cache_age;
      int v233 = v232[v384];
      int v440 = v233 + ((int)((unsigned int)(v233 - v229) >> 31));
      v232[v384] = v440;
      int * v235 = v158->cache_age;
      v235[v408] = 0;
      v238 = v408;
    }
    int * v239 = v158->cache_vals;
    int v443 = v238 * 2;
    int v240 = v239[v443];
    int v444 = (v238 * 2) + 1;
    int v241 = v239[v444];
    int v445 = (((((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1)) & 1) * 2) + ((((v180 + ((~(((v182 ^ -1) | (-(v182 ^ -1))) >> 31)) & 2)) - (v183 + ((~(((v184 ^ -1) | (-(v184 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v239[v445] = v240;
    int * v243 = v158->cache_vals;
    int v448 = ((((((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1)) & 1) * 2) + ((((v180 + ((~(((v182 ^ -1) | (-(v182 ^ -1))) >> 31)) & 2)) - (v183 + ((~(((v184 ^ -1) | (-(v184 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v243[v448] = v241;
    int * v245 = v158->cache_tags;
    int v451 = ((((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1)) & 1) * 2) + ((((v180 + ((~(((v182 ^ -1) | (-(v182 ^ -1))) >> 31)) & 2)) - (v183 + ((~(((v184 ^ -1) | (-(v184 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v452 = (int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1);
    v245[v451] = v452;
    int * v247 = v158->cache_dirty;
    v247[v451] = 0;
    int * v249 = v158->cache_age;
    v249[v451] = 1;
    int * v251 = v158->cache_age;
    int v252 = v251[v451];
    int v253 = v251[v381];
    int v458 = v253 + ((int)((unsigned int)(v253 - v252) >> 31));
    v251[v381] = v458;
    int * v255 = v158->cache_age;
    int v256 = v255[v382];
    int v460 = v256 + ((int)((unsigned int)(v256 - v252) >> 31));
    v255[v382] = v460;
    int * v258 = v158->cache_age;
    v258[v451] = 0;
    v261 = v451;
  }
  int v463 = (v261 * 2) + (((int)((unsigned int)v162 >> 2)) & 1);
  int v262 = v168[v463];
  int * v263 = v158->reg_ready;
  int v465 = ((v160 + ((v47 - v160) & (~((v47 - v160) >> 31)))) + 1) + ((100 ^ (((~(((v166 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))) | (-(v166 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))))) >> 31)) | (~(((v167 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))) | (-(v167 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v164 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))) | (-(v164 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))))) >> 31)) | (~(((v165 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))) | (-(v165 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v166 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))) | (-(v166 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))))) >> 31)) | (~(((v167 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))) | (-(v167 ^ ((int)((unsigned int)((int)((unsigned int)v162 >> 2)) >> 1))))) >> 31))) & 104)))));
  v263[11] = v465;
  int * v265 = v158->regs;
  v265[11] = v262;
  struct StateT2 * v267 = slot_2(v26);
  return v267;
}

struct StateT2 * slot_4(struct StateT2 * v967) {
  struct StateT * v968 = v967->a;
  int v969 = v968->timer;
  struct StateT * v970 = v967->b;
  int v971 = v970->timer;
  bool v1024 = v969 == v971;
  squared_assert(v1024);
  squared_assume(v1024);
  struct StateT * v974 = v967->a;
  int * v975 = v974->regs;
  int v976 = v975[10];
  struct StateT * v977 = v967->b;
  int * v978 = v977->regs;
  int v979 = v978[10];
  bool v1030 = (v976 == 0) == (v979 == 0);
  squared_diverged(v1030);
  squared_assume(v1030);
  bool v1031 = v976 == 0;
  struct StateT2 * v1020;
  if (v1031) {
    struct StateT * v982 = v967->a;
    int v983 = v982->timer;
    int v1033 = v983 + 15;
    v982->timer = v1033;
    int * v985 = v982->saved_regs;
    int v986 = v985[11];
    int * v987 = v982->regs;
    v987[11] = v986;
    int * v989 = v982->saved_regs;
    int v990 = v989[12];
    int * v991 = v982->regs;
    v991[12] = v990;
    struct StateT * v993 = v967->b;
    int v994 = v993->timer;
    int v1043 = v994 + 15;
    v993->timer = v1043;
    int * v996 = v993->saved_regs;
    int v997 = v996[11];
    int * v998 = v993->regs;
    v998[11] = v997;
    int * v1000 = v993->saved_regs;
    int v1001 = v1000[12];
    int * v1002 = v993->regs;
    v1002[12] = v1001;
    struct StateT * v1004 = v967->a;
    int * v1005 = v1004->reg_ready;
    int v1006 = v1004->timer;
    v1005[11] = v1006;
    int * v1008 = v1004->reg_ready;
    int v1009 = v1004->timer;
    v1008[12] = v1009;
    struct StateT * v1011 = v967->b;
    int * v1012 = v1011->reg_ready;
    int v1013 = v1011->timer;
    v1012[11] = v1013;
    int * v1015 = v1011->reg_ready;
    int v1016 = v1011->timer;
    v1015[12] = v1016;
    v1020 = v967;
  } else {
    v1020 = v967;
  }
  return v1020;
}

struct StateT2 * slot_2(struct StateT2 * v470) {
  struct StateT * v471 = v470->a;
  int v472 = v471->timer;
  struct StateT * v473 = v470->b;
  int v474 = v473->timer;
  bool v503 = v472 == v474;
  squared_assert(v503);
  squared_assume(v503);
  struct StateT * v477 = v470->a;
  int v478 = v477->timer;
  int v505 = v478 + 1;
  v477->timer = v505;
  struct StateT * v480 = v470->b;
  int v481 = v480->timer;
  int v507 = v481 + 1;
  v480->timer = v507;
  struct StateT * v483 = v470->a;
  int * v484 = v483->reg_ready;
  int v485 = v484[11];
  int * v486 = v483->regs;
  int v487 = v486[11];
  int v512 = (v485 + ((v478 - v485) & (~((v478 - v485) >> 31)))) + 1;
  v484[11] = v512;
  int * v489 = v483->regs;
  int v514 = v487 << 2;
  v489[11] = v514;
  struct StateT * v491 = v470->b;
  int * v492 = v491->reg_ready;
  int v493 = v492[11];
  int * v494 = v491->regs;
  int v495 = v494[11];
  int v518 = (v493 + ((v481 - v493) & (~((v481 - v493) >> 31)))) + 1;
  v492[11] = v518;
  int * v497 = v491->regs;
  int v520 = v495 << 2;
  v497[11] = v520;
  struct StateT2 * v499 = slot_3(v470);
  return v499;
}

struct StateT2 * slot_3(struct StateT2 * v523) {
  struct StateT * v524 = v523->a;
  int v525 = v524->timer;
  struct StateT * v526 = v523->b;
  int v527 = v526->timer;
  bool v768 = v525 == v527;
  squared_assert(v768);
  squared_assume(v768);
  struct StateT * v530 = v523->a;
  int * v531 = v530->saved_regs;
  int * v532 = v530->regs;
  int v533 = v532[12];
  v531[12] = v533;
  struct StateT * v535 = v523->b;
  int * v536 = v535->saved_regs;
  int * v537 = v535->regs;
  int v538 = v537[12];
  v536[12] = v538;
  struct StateT * v540 = v523->a;
  int v541 = v540->timer;
  int v779 = v541 + 1;
  v540->timer = v779;
  struct StateT * v543 = v523->b;
  int v544 = v543->timer;
  int v781 = v544 + 1;
  v543->timer = v781;
  struct StateT * v546 = v523->a;
  int * v547 = v546->reg_ready;
  int v548 = v547[11];
  int * v549 = v546->regs;
  int v550 = v549[11];
  int * v551 = v546->cache_tags;
  int v787 = (((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1)) & 1) * 2;
  int v552 = v551[v787];
  int v788 = ((((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v553 = v551[v788];
  int v789 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1)) & 3) * 2);
  int v554 = v551[v789];
  int v790 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v555 = v551[v790];
  int * v556 = v546->cache_vals;
  bool v791 = !(((~(((v552 ^ ((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1))) | (-(v552 ^ ((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v553 ^ ((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1))) | (-(v553 ^ ((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v649;
  if (v791) {
    int * v557 = v546->cache_age;
    int v793 = ((((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v553 ^ ((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1))) | (-(v553 ^ ((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v558 = v557[v793];
    int v559 = v557[v787];
    int v794 = v559 + ((int)((unsigned int)(v559 - v558) >> 31));
    v557[v787] = v794;
    int * v561 = v546->cache_age;
    int v562 = v561[v788];
    int v796 = v562 + ((int)((unsigned int)(v562 - v558) >> 31));
    v561[v788] = v796;
    int * v564 = v546->cache_age;
    v564[v793] = 0;
    v649 = v793;
  } else {
    int * v567 = v546->cache_age;
    int v800 = (((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1)) & 1) * 2;
    int v568 = v567[v800];
    int * v569 = v546->cache_tags;
    int v570 = v569[v800];
    int v571 = v567[v788];
    int v572 = v569[v788];
    bool v802 = !(((~(((v554 ^ ((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1))) | (-(v554 ^ ((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v555 ^ ((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1))) | (-(v555 ^ ((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v626;
    if (v802) {
      int * v573 = v546->cache_age;
      int v804 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v555 ^ ((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1))) | (-(v555 ^ ((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v574 = v573[v804];
      int v575 = v573[v789];
      int v805 = v575 + ((int)((unsigned int)(v575 - v574) >> 31));
      v573[v789] = v805;
      int * v577 = v546->cache_age;
      int v578 = v577[v790];
      int v807 = v578 + ((int)((unsigned int)(v578 - v574) >> 31));
      v577[v790] = v807;
      int * v580 = v546->cache_age;
      v580[v804] = 0;
      v626 = v804;
    } else {
      int * v583 = v546->cache_age;
      int v811 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1)) & 3) * 2);
      int v584 = v583[v811];
      int * v585 = v546->cache_tags;
      int v586 = v585[v811];
      int v587 = v583[v790];
      int v588 = v585[v790];
      int * v589 = v546->cache_dirty;
      int v814 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v584 + ((~(((v586 ^ -1) | (-(v586 ^ -1))) >> 31)) & 2)) - (v587 + ((~(((v588 ^ -1) | (-(v588 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v590 = v589[v814];
      bool v815 = !(v590 == 0);
      if (v815) {
        int * v591 = v546->cache_tags;
        int v592 = v591[v814];
        int * v593 = v546->cache_vals;
        int v818 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v584 + ((~(((v586 ^ -1) | (-(v586 ^ -1))) >> 31)) & 2)) - (v587 + ((~(((v588 ^ -1) | (-(v588 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v594 = v593[v818];
        int v819 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v584 + ((~(((v586 ^ -1) | (-(v586 ^ -1))) >> 31)) & 2)) - (v587 + ((~(((v588 ^ -1) | (-(v588 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v595 = v593[v819];
        int * v596 = v546->mem;
        int v821 = v592 * 2;
        v596[v821] = v594;
        int * v598 = v546->mem;
        int v824 = (v592 * 2) + 1;
        v598[v824] = v595;
        ;
      } else {
        ;
      }
      int * v603 = v546->mem;
      int v829 = ((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1)) * 2;
      int v604 = v603[v829];
      int v830 = (((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1)) * 2) + 1;
      int v605 = v603[v830];
      int * v606 = v546->cache_vals;
      int v832 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v584 + ((~(((v586 ^ -1) | (-(v586 ^ -1))) >> 31)) & 2)) - (v587 + ((~(((v588 ^ -1) | (-(v588 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v606[v832] = v604;
      int * v608 = v546->cache_vals;
      int v835 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v584 + ((~(((v586 ^ -1) | (-(v586 ^ -1))) >> 31)) & 2)) - (v587 + ((~(((v588 ^ -1) | (-(v588 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v608[v835] = v605;
      int * v610 = v546->cache_tags;
      int v838 = (int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1);
      v610[v814] = v838;
      int * v612 = v546->cache_dirty;
      v612[v814] = 0;
      int * v614 = v546->cache_age;
      v614[v814] = 1;
      int * v616 = v546->cache_age;
      int v617 = v616[v814];
      int v618 = v616[v789];
      int v844 = v618 + ((int)((unsigned int)(v618 - v617) >> 31));
      v616[v789] = v844;
      int * v620 = v546->cache_age;
      int v621 = v620[v790];
      int v846 = v621 + ((int)((unsigned int)(v621 - v617) >> 31));
      v620[v790] = v846;
      int * v623 = v546->cache_age;
      v623[v814] = 0;
      v626 = v814;
    }
    int * v627 = v546->cache_vals;
    int v849 = v626 * 2;
    int v628 = v627[v849];
    int v850 = (v626 * 2) + 1;
    int v629 = v627[v850];
    int v851 = (((((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v568 + ((~(((v570 ^ -1) | (-(v570 ^ -1))) >> 31)) & 2)) - (v571 + ((~(((v572 ^ -1) | (-(v572 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v627[v851] = v628;
    int * v631 = v546->cache_vals;
    int v854 = ((((((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v568 + ((~(((v570 ^ -1) | (-(v570 ^ -1))) >> 31)) & 2)) - (v571 + ((~(((v572 ^ -1) | (-(v572 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v631[v854] = v629;
    int * v633 = v546->cache_tags;
    int v857 = ((((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v568 + ((~(((v570 ^ -1) | (-(v570 ^ -1))) >> 31)) & 2)) - (v571 + ((~(((v572 ^ -1) | (-(v572 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v858 = (int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1);
    v633[v857] = v858;
    int * v635 = v546->cache_dirty;
    v635[v857] = 0;
    int * v637 = v546->cache_age;
    v637[v857] = 1;
    int * v639 = v546->cache_age;
    int v640 = v639[v857];
    int v641 = v639[v787];
    int v864 = v641 + ((int)((unsigned int)(v641 - v640) >> 31));
    v639[v787] = v864;
    int * v643 = v546->cache_age;
    int v644 = v643[v788];
    int v866 = v644 + ((int)((unsigned int)(v644 - v640) >> 31));
    v643[v788] = v866;
    int * v646 = v546->cache_age;
    v646[v857] = 0;
    v649 = v857;
  }
  int v869 = (v649 * 2) + (((int)((unsigned int)(v550 + 16) >> 2)) & 1);
  int v650 = v556[v869];
  int * v651 = v546->reg_ready;
  int v871 = ((v548 + ((v541 - v548) & (~((v541 - v548) >> 31)))) + 1) + ((100 ^ (((~(((v554 ^ ((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1))) | (-(v554 ^ ((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v555 ^ ((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1))) | (-(v555 ^ ((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v552 ^ ((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1))) | (-(v552 ^ ((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v553 ^ ((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1))) | (-(v553 ^ ((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v554 ^ ((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1))) | (-(v554 ^ ((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v555 ^ ((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1))) | (-(v555 ^ ((int)((unsigned int)((int)((unsigned int)(v550 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v651[12] = v871;
  int * v653 = v546->regs;
  v653[12] = v650;
  struct StateT * v655 = v523->b;
  int * v656 = v655->reg_ready;
  int v657 = v656[11];
  int * v658 = v655->regs;
  int v659 = v658[11];
  int * v660 = v655->cache_tags;
  int v878 = (((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1)) & 1) * 2;
  int v661 = v660[v878];
  int v879 = ((((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v662 = v660[v879];
  int v880 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1)) & 3) * 2);
  int v663 = v660[v880];
  int v881 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v664 = v660[v881];
  int * v665 = v655->cache_vals;
  bool v882 = !(((~(((v661 ^ ((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1))) | (-(v661 ^ ((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v662 ^ ((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1))) | (-(v662 ^ ((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v758;
  if (v882) {
    int * v666 = v655->cache_age;
    int v884 = ((((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v662 ^ ((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1))) | (-(v662 ^ ((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v667 = v666[v884];
    int v668 = v666[v878];
    int v885 = v668 + ((int)((unsigned int)(v668 - v667) >> 31));
    v666[v878] = v885;
    int * v670 = v655->cache_age;
    int v671 = v670[v879];
    int v887 = v671 + ((int)((unsigned int)(v671 - v667) >> 31));
    v670[v879] = v887;
    int * v673 = v655->cache_age;
    v673[v884] = 0;
    v758 = v884;
  } else {
    int * v676 = v655->cache_age;
    int v891 = (((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1)) & 1) * 2;
    int v677 = v676[v891];
    int * v678 = v655->cache_tags;
    int v679 = v678[v891];
    int v680 = v676[v879];
    int v681 = v678[v879];
    bool v893 = !(((~(((v663 ^ ((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1))) | (-(v663 ^ ((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v664 ^ ((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1))) | (-(v664 ^ ((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v735;
    if (v893) {
      int * v682 = v655->cache_age;
      int v895 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v664 ^ ((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1))) | (-(v664 ^ ((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v683 = v682[v895];
      int v684 = v682[v880];
      int v896 = v684 + ((int)((unsigned int)(v684 - v683) >> 31));
      v682[v880] = v896;
      int * v686 = v655->cache_age;
      int v687 = v686[v881];
      int v898 = v687 + ((int)((unsigned int)(v687 - v683) >> 31));
      v686[v881] = v898;
      int * v689 = v655->cache_age;
      v689[v895] = 0;
      v735 = v895;
    } else {
      int * v692 = v655->cache_age;
      int v902 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1)) & 3) * 2);
      int v693 = v692[v902];
      int * v694 = v655->cache_tags;
      int v695 = v694[v902];
      int v696 = v692[v881];
      int v697 = v694[v881];
      int * v698 = v655->cache_dirty;
      int v905 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v693 + ((~(((v695 ^ -1) | (-(v695 ^ -1))) >> 31)) & 2)) - (v696 + ((~(((v697 ^ -1) | (-(v697 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v699 = v698[v905];
      bool v906 = !(v699 == 0);
      if (v906) {
        int * v700 = v655->cache_tags;
        int v701 = v700[v905];
        int * v702 = v655->cache_vals;
        int v909 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v693 + ((~(((v695 ^ -1) | (-(v695 ^ -1))) >> 31)) & 2)) - (v696 + ((~(((v697 ^ -1) | (-(v697 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v703 = v702[v909];
        int v910 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v693 + ((~(((v695 ^ -1) | (-(v695 ^ -1))) >> 31)) & 2)) - (v696 + ((~(((v697 ^ -1) | (-(v697 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v704 = v702[v910];
        int * v705 = v655->mem;
        int v912 = v701 * 2;
        v705[v912] = v703;
        int * v707 = v655->mem;
        int v915 = (v701 * 2) + 1;
        v707[v915] = v704;
        ;
      } else {
        ;
      }
      int * v712 = v655->mem;
      int v920 = ((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1)) * 2;
      int v713 = v712[v920];
      int v921 = (((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1)) * 2) + 1;
      int v714 = v712[v921];
      int * v715 = v655->cache_vals;
      int v923 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v693 + ((~(((v695 ^ -1) | (-(v695 ^ -1))) >> 31)) & 2)) - (v696 + ((~(((v697 ^ -1) | (-(v697 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v715[v923] = v713;
      int * v717 = v655->cache_vals;
      int v926 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v693 + ((~(((v695 ^ -1) | (-(v695 ^ -1))) >> 31)) & 2)) - (v696 + ((~(((v697 ^ -1) | (-(v697 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v717[v926] = v714;
      int * v719 = v655->cache_tags;
      int v929 = (int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1);
      v719[v905] = v929;
      int * v721 = v655->cache_dirty;
      v721[v905] = 0;
      int * v723 = v655->cache_age;
      v723[v905] = 1;
      int * v725 = v655->cache_age;
      int v726 = v725[v905];
      int v727 = v725[v880];
      int v935 = v727 + ((int)((unsigned int)(v727 - v726) >> 31));
      v725[v880] = v935;
      int * v729 = v655->cache_age;
      int v730 = v729[v881];
      int v937 = v730 + ((int)((unsigned int)(v730 - v726) >> 31));
      v729[v881] = v937;
      int * v732 = v655->cache_age;
      v732[v905] = 0;
      v735 = v905;
    }
    int * v736 = v655->cache_vals;
    int v940 = v735 * 2;
    int v737 = v736[v940];
    int v941 = (v735 * 2) + 1;
    int v738 = v736[v941];
    int v942 = (((((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v677 + ((~(((v679 ^ -1) | (-(v679 ^ -1))) >> 31)) & 2)) - (v680 + ((~(((v681 ^ -1) | (-(v681 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v736[v942] = v737;
    int * v740 = v655->cache_vals;
    int v945 = ((((((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v677 + ((~(((v679 ^ -1) | (-(v679 ^ -1))) >> 31)) & 2)) - (v680 + ((~(((v681 ^ -1) | (-(v681 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v740[v945] = v738;
    int * v742 = v655->cache_tags;
    int v948 = ((((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v677 + ((~(((v679 ^ -1) | (-(v679 ^ -1))) >> 31)) & 2)) - (v680 + ((~(((v681 ^ -1) | (-(v681 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v949 = (int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1);
    v742[v948] = v949;
    int * v744 = v655->cache_dirty;
    v744[v948] = 0;
    int * v746 = v655->cache_age;
    v746[v948] = 1;
    int * v748 = v655->cache_age;
    int v749 = v748[v948];
    int v750 = v748[v878];
    int v955 = v750 + ((int)((unsigned int)(v750 - v749) >> 31));
    v748[v878] = v955;
    int * v752 = v655->cache_age;
    int v753 = v752[v879];
    int v957 = v753 + ((int)((unsigned int)(v753 - v749) >> 31));
    v752[v879] = v957;
    int * v755 = v655->cache_age;
    v755[v948] = 0;
    v758 = v948;
  }
  int v960 = (v758 * 2) + (((int)((unsigned int)(v659 + 16) >> 2)) & 1);
  int v759 = v665[v960];
  int * v760 = v655->reg_ready;
  int v962 = ((v657 + ((v544 - v657) & (~((v544 - v657) >> 31)))) + 1) + ((100 ^ (((~(((v663 ^ ((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1))) | (-(v663 ^ ((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v664 ^ ((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1))) | (-(v664 ^ ((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v661 ^ ((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1))) | (-(v661 ^ ((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v662 ^ ((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1))) | (-(v662 ^ ((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v663 ^ ((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1))) | (-(v663 ^ ((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v664 ^ ((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1))) | (-(v664 ^ ((int)((unsigned int)((int)((unsigned int)(v659 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v760[12] = v962;
  int * v762 = v655->regs;
  v762[12] = v759;
  struct StateT2 * v764 = slot_4(v523);
  return v764;
}

struct StateT2 * slot_0(struct StateT2 * v2) {
  struct StateT * v3 = v2->a;
  int v4 = v3->timer;
  struct StateT * v5 = v2->b;
  int v6 = v5->timer;
  bool v19 = v4 == v6;
  squared_assert(v19);
  squared_assume(v19);
  struct StateT * v9 = v2->a;
  int v10 = v9->timer;
  int v21 = v10 + 1;
  v9->timer = v21;
  struct StateT * v12 = v2->b;
  int v13 = v12->timer;
  int v23 = v13 + 1;
  v12->timer = v23;
  struct StateT2 * v15 = slot_1(v2);
  return v15;
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