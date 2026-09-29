// verify: clean (Eva should report untainted: Valid) [unroll 65]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef EVA
#include "__fc_builtin.h"
/*@ requires untainted: !\tainted(b);
    assigns \nothing; */
void koika_check(int b);
/*@ assigns *p \from \nothing;
    taints *p; */
void koika_mark(int *p);
#define koika_assert(b, s) koika_check(b)
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

struct StateT * slot_12(struct StateT * v1084);
struct StateT * slot_14(struct StateT * v1124);
struct StateT * slot_6(struct StateT * v305);
struct StateT * slot_2(struct StateT * v34);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v1055);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_8(struct StateT * v528);
struct StateT * slot_4(struct StateT * v58);
struct StateT * slot_9(struct StateT * v847);
struct StateT * slot_11(struct StateT * v1076);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v1084) {
  int v1085 = v1084->timer;
  int v1089 = v1085 + 1;
  v1084->timer = v1089;
  struct StateT * v1087 = slot_4(v1084);
  return v1087;
}

struct StateT * slot_14(struct StateT * v1124) {
  int * v1125 = v1124->saved_regs;
  int * v1126 = v1124->regs;
  int v1127 = v1126[5];
  v1125[5] = v1127;
  int v1129 = v1124->timer;
  int v1245 = v1129 + 1;
  v1124->timer = v1245;
  int * v1131 = v1124->reg_ready;
  int v1132 = v1131[8];
  int * v1133 = v1124->regs;
  int v1134 = v1133[8];
  int * v1135 = v1124->cache_tags;
  int v1250 = (((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1)) & 1) * 2;
  int v1136 = v1135[v1250];
  int v1251 = ((((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1137 = v1135[v1251];
  int v1252 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1)) & 3) * 2);
  int v1138 = v1135[v1252];
  int v1253 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1139 = v1135[v1253];
  int * v1140 = v1124->cache_vals;
  bool v1254 = !(((~(((v1136 ^ ((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1))) | (-(v1136 ^ ((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1))))) >> 31)) | (~(((v1137 ^ ((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1))) | (-(v1137 ^ ((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1))))) >> 31))) == 0);
  int v1233;
  if (v1254) {
    int * v1141 = v1124->cache_age;
    int v1256 = ((((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1)) & 1) * 2) + ((~(((v1137 ^ ((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1))) | (-(v1137 ^ ((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1))))) >> 31)) & 1);
    int v1142 = v1141[v1256];
    int v1143 = v1141[v1250];
    int v1257 = v1143 + ((int)((unsigned int)(v1143 - v1142) >> 31));
    v1141[v1250] = v1257;
    int * v1145 = v1124->cache_age;
    int v1146 = v1145[v1251];
    int v1259 = v1146 + ((int)((unsigned int)(v1146 - v1142) >> 31));
    v1145[v1251] = v1259;
    int * v1148 = v1124->cache_age;
    v1148[v1256] = 0;
    v1233 = v1256;
  } else {
    int * v1151 = v1124->cache_age;
    int v1263 = (((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1)) & 1) * 2;
    int v1152 = v1151[v1263];
    int * v1153 = v1124->cache_tags;
    int v1154 = v1153[v1263];
    int v1155 = v1151[v1251];
    int v1156 = v1153[v1251];
    bool v1265 = !(((~(((v1138 ^ ((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1))) | (-(v1138 ^ ((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1))))) >> 31)) | (~(((v1139 ^ ((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1))) | (-(v1139 ^ ((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1))))) >> 31))) == 0);
    int v1210;
    if (v1265) {
      int * v1157 = v1124->cache_age;
      int v1267 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1139 ^ ((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1))) | (-(v1139 ^ ((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1))))) >> 31)) & 1);
      int v1158 = v1157[v1267];
      int v1159 = v1157[v1252];
      int v1268 = v1159 + ((int)((unsigned int)(v1159 - v1158) >> 31));
      v1157[v1252] = v1268;
      int * v1161 = v1124->cache_age;
      int v1162 = v1161[v1253];
      int v1270 = v1162 + ((int)((unsigned int)(v1162 - v1158) >> 31));
      v1161[v1253] = v1270;
      int * v1164 = v1124->cache_age;
      v1164[v1267] = 0;
      v1210 = v1267;
    } else {
      int * v1167 = v1124->cache_age;
      int v1274 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1)) & 3) * 2);
      int v1168 = v1167[v1274];
      int * v1169 = v1124->cache_tags;
      int v1170 = v1169[v1274];
      int v1171 = v1167[v1253];
      int v1172 = v1169[v1253];
      int * v1173 = v1124->cache_dirty;
      int v1277 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1)) & 3) * 2)) + ((((v1168 + ((~(((v1170 ^ -1) | (-(v1170 ^ -1))) >> 31)) & 2)) - (v1171 + ((~(((v1172 ^ -1) | (-(v1172 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1174 = v1173[v1277];
      bool v1278 = !(v1174 == 0);
      if (v1278) {
        int * v1175 = v1124->cache_tags;
        int v1176 = v1175[v1277];
        int * v1177 = v1124->cache_vals;
        int v1281 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1)) & 3) * 2)) + ((((v1168 + ((~(((v1170 ^ -1) | (-(v1170 ^ -1))) >> 31)) & 2)) - (v1171 + ((~(((v1172 ^ -1) | (-(v1172 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1178 = v1177[v1281];
        int v1282 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1)) & 3) * 2)) + ((((v1168 + ((~(((v1170 ^ -1) | (-(v1170 ^ -1))) >> 31)) & 2)) - (v1171 + ((~(((v1172 ^ -1) | (-(v1172 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1179 = v1177[v1282];
        int * v1180 = v1124->mem;
        int v1284 = v1176 * 2;
        v1180[v1284] = v1178;
        int * v1182 = v1124->mem;
        int v1287 = (v1176 * 2) + 1;
        v1182[v1287] = v1179;
        ;
      } else {
        ;
      }
      int * v1187 = v1124->mem;
      int v1292 = ((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1)) * 2;
      int v1188 = v1187[v1292];
      int v1293 = (((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1)) * 2) + 1;
      int v1189 = v1187[v1293];
      int * v1190 = v1124->cache_vals;
      int v1295 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1)) & 3) * 2)) + ((((v1168 + ((~(((v1170 ^ -1) | (-(v1170 ^ -1))) >> 31)) & 2)) - (v1171 + ((~(((v1172 ^ -1) | (-(v1172 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1190[v1295] = v1188;
      int * v1192 = v1124->cache_vals;
      int v1298 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1)) & 3) * 2)) + ((((v1168 + ((~(((v1170 ^ -1) | (-(v1170 ^ -1))) >> 31)) & 2)) - (v1171 + ((~(((v1172 ^ -1) | (-(v1172 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1192[v1298] = v1189;
      int * v1194 = v1124->cache_tags;
      int v1301 = (int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1);
      v1194[v1277] = v1301;
      int * v1196 = v1124->cache_dirty;
      v1196[v1277] = 0;
      int * v1198 = v1124->cache_age;
      v1198[v1277] = 1;
      int * v1200 = v1124->cache_age;
      int v1201 = v1200[v1277];
      int v1202 = v1200[v1252];
      int v1307 = v1202 + ((int)((unsigned int)(v1202 - v1201) >> 31));
      v1200[v1252] = v1307;
      int * v1204 = v1124->cache_age;
      int v1205 = v1204[v1253];
      int v1309 = v1205 + ((int)((unsigned int)(v1205 - v1201) >> 31));
      v1204[v1253] = v1309;
      int * v1207 = v1124->cache_age;
      v1207[v1277] = 0;
      v1210 = v1277;
    }
    int * v1211 = v1124->cache_vals;
    int v1312 = v1210 * 2;
    int v1212 = v1211[v1312];
    int v1313 = (v1210 * 2) + 1;
    int v1213 = v1211[v1313];
    int v1314 = (((((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1)) & 1) * 2) + ((((v1152 + ((~(((v1154 ^ -1) | (-(v1154 ^ -1))) >> 31)) & 2)) - (v1155 + ((~(((v1156 ^ -1) | (-(v1156 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1211[v1314] = v1212;
    int * v1215 = v1124->cache_vals;
    int v1317 = ((((((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1)) & 1) * 2) + ((((v1152 + ((~(((v1154 ^ -1) | (-(v1154 ^ -1))) >> 31)) & 2)) - (v1155 + ((~(((v1156 ^ -1) | (-(v1156 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1215[v1317] = v1213;
    int * v1217 = v1124->cache_tags;
    int v1320 = ((((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1)) & 1) * 2) + ((((v1152 + ((~(((v1154 ^ -1) | (-(v1154 ^ -1))) >> 31)) & 2)) - (v1155 + ((~(((v1156 ^ -1) | (-(v1156 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1321 = (int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1);
    v1217[v1320] = v1321;
    int * v1219 = v1124->cache_dirty;
    v1219[v1320] = 0;
    int * v1221 = v1124->cache_age;
    v1221[v1320] = 1;
    int * v1223 = v1124->cache_age;
    int v1224 = v1223[v1320];
    int v1225 = v1223[v1250];
    int v1327 = v1225 + ((int)((unsigned int)(v1225 - v1224) >> 31));
    v1223[v1250] = v1327;
    int * v1227 = v1124->cache_age;
    int v1228 = v1227[v1251];
    int v1329 = v1228 + ((int)((unsigned int)(v1228 - v1224) >> 31));
    v1227[v1251] = v1329;
    int * v1230 = v1124->cache_age;
    v1230[v1320] = 0;
    v1233 = v1320;
  }
  int v1332 = (v1233 * 2) + (((int)((unsigned int)v1134 >> 2)) & 1);
  int v1234 = v1140[v1332];
  int * v1235 = v1124->reg_ready;
  int v1334 = ((v1132 + ((v1129 - v1132) & (~((v1129 - v1132) >> 31)))) + 1) + ((100 ^ (((~(((v1138 ^ ((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1))) | (-(v1138 ^ ((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1))))) >> 31)) | (~(((v1139 ^ ((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1))) | (-(v1139 ^ ((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1136 ^ ((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1))) | (-(v1136 ^ ((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1))))) >> 31)) | (~(((v1137 ^ ((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1))) | (-(v1137 ^ ((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1138 ^ ((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1))) | (-(v1138 ^ ((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1))))) >> 31)) | (~(((v1139 ^ ((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1))) | (-(v1139 ^ ((int)((unsigned int)((int)((unsigned int)v1134 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1235[5] = v1334;
  int * v1237 = v1124->regs;
  v1237[5] = v1234;
  struct StateT * v1239 = slot_6(v1124);
  return v1239;
}

struct StateT * slot_6(struct StateT * v305) {
  int * v306 = v305->regs;
  int v307 = v306[6];
  int v308 = v306[7];
  bool v423 = v307 >= v308;
  struct StateT * v418;
  if (v423) {
    int v309 = v305->timer;
    int v424 = v309 + 15;
    v305->timer = v424;
    int * v311 = v305->saved_regs;
    int v312 = v311[8];
    int * v313 = v305->regs;
    v313[8] = v312;
    int * v315 = v305->saved_regs;
    int v316 = v315[5];
    int * v317 = v305->regs;
    v317[5] = v316;
    int * v319 = v305->reg_ready;
    int v320 = v305->timer;
    v319[0] = v320;
    int * v322 = v305->reg_ready;
    int v323 = v305->timer;
    v322[1] = v323;
    int * v325 = v305->reg_ready;
    int v326 = v305->timer;
    v325[2] = v326;
    int * v328 = v305->reg_ready;
    int v329 = v305->timer;
    v328[3] = v329;
    int * v331 = v305->reg_ready;
    int v332 = v305->timer;
    v331[4] = v332;
    int * v334 = v305->reg_ready;
    int v335 = v305->timer;
    v334[5] = v335;
    int * v337 = v305->reg_ready;
    int v338 = v305->timer;
    v337[6] = v338;
    int * v340 = v305->reg_ready;
    int v341 = v305->timer;
    v340[7] = v341;
    int * v343 = v305->reg_ready;
    int v344 = v305->timer;
    v343[8] = v344;
    int * v346 = v305->reg_ready;
    int v347 = v305->timer;
    v346[9] = v347;
    int * v349 = v305->reg_ready;
    int v350 = v305->timer;
    v349[10] = v350;
    int * v352 = v305->reg_ready;
    int v353 = v305->timer;
    v352[11] = v353;
    int * v355 = v305->reg_ready;
    int v356 = v305->timer;
    v355[12] = v356;
    int * v358 = v305->reg_ready;
    int v359 = v305->timer;
    v358[13] = v359;
    int * v361 = v305->reg_ready;
    int v362 = v305->timer;
    v361[14] = v362;
    int * v364 = v305->reg_ready;
    int v365 = v305->timer;
    v364[15] = v365;
    int * v367 = v305->reg_ready;
    int v368 = v305->timer;
    v367[16] = v368;
    int * v370 = v305->reg_ready;
    int v371 = v305->timer;
    v370[17] = v371;
    int * v373 = v305->reg_ready;
    int v374 = v305->timer;
    v373[18] = v374;
    int * v376 = v305->reg_ready;
    int v377 = v305->timer;
    v376[19] = v377;
    int * v379 = v305->reg_ready;
    int v380 = v305->timer;
    v379[20] = v380;
    int * v382 = v305->reg_ready;
    int v383 = v305->timer;
    v382[21] = v383;
    int * v385 = v305->reg_ready;
    int v386 = v305->timer;
    v385[22] = v386;
    int * v388 = v305->reg_ready;
    int v389 = v305->timer;
    v388[23] = v389;
    int * v391 = v305->reg_ready;
    int v392 = v305->timer;
    v391[24] = v392;
    int * v394 = v305->reg_ready;
    int v395 = v305->timer;
    v394[25] = v395;
    int * v397 = v305->reg_ready;
    int v398 = v305->timer;
    v397[26] = v398;
    int * v400 = v305->reg_ready;
    int v401 = v305->timer;
    v400[27] = v401;
    int * v403 = v305->reg_ready;
    int v404 = v305->timer;
    v403[28] = v404;
    int * v406 = v305->reg_ready;
    int v407 = v305->timer;
    v406[29] = v407;
    int * v409 = v305->reg_ready;
    int v410 = v305->timer;
    v409[30] = v410;
    int * v412 = v305->reg_ready;
    int v413 = v305->timer;
    v412[31] = v413;
    v418 = v305;
  } else {
    struct StateT * v416 = slot_8(v305);
    v418 = v416;
  }
  return v418;
}

struct StateT * slot_2(struct StateT * v34) {
  int v35 = v34->timer;
  int v43 = v35 + 1;
  v34->timer = v43;
  int * v37 = v34->reg_ready;
  v37[9] = v43;
  int * v39 = v34->regs;
  v39[9] = 80;
  struct StateT * v41 = slot_12(v34);
  return v41;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v1562 = v1->timer;
  int * v1563 = v1->reg_ready;
  int v1564 = v1563[0];
  int v1695 = v1564 + ((v1562 - v1564) & (~((v1562 - v1564) >> 31)));
  v1->timer = v1695;
  int v1566 = v1->timer;
  int * v1567 = v1->reg_ready;
  int v1568 = v1567[1];
  int v1698 = v1568 + ((v1566 - v1568) & (~((v1566 - v1568) >> 31)));
  v1->timer = v1698;
  int v1570 = v1->timer;
  int * v1571 = v1->reg_ready;
  int v1572 = v1571[2];
  int v1701 = v1572 + ((v1570 - v1572) & (~((v1570 - v1572) >> 31)));
  v1->timer = v1701;
  int v1574 = v1->timer;
  int * v1575 = v1->reg_ready;
  int v1576 = v1575[3];
  int v1704 = v1576 + ((v1574 - v1576) & (~((v1574 - v1576) >> 31)));
  v1->timer = v1704;
  int v1578 = v1->timer;
  int * v1579 = v1->reg_ready;
  int v1580 = v1579[4];
  int v1707 = v1580 + ((v1578 - v1580) & (~((v1578 - v1580) >> 31)));
  v1->timer = v1707;
  int v1582 = v1->timer;
  int * v1583 = v1->reg_ready;
  int v1584 = v1583[5];
  int v1710 = v1584 + ((v1582 - v1584) & (~((v1582 - v1584) >> 31)));
  v1->timer = v1710;
  int v1586 = v1->timer;
  int * v1587 = v1->reg_ready;
  int v1588 = v1587[6];
  int v1713 = v1588 + ((v1586 - v1588) & (~((v1586 - v1588) >> 31)));
  v1->timer = v1713;
  int v1590 = v1->timer;
  int * v1591 = v1->reg_ready;
  int v1592 = v1591[7];
  int v1716 = v1592 + ((v1590 - v1592) & (~((v1590 - v1592) >> 31)));
  v1->timer = v1716;
  int v1594 = v1->timer;
  int * v1595 = v1->reg_ready;
  int v1596 = v1595[8];
  int v1719 = v1596 + ((v1594 - v1596) & (~((v1594 - v1596) >> 31)));
  v1->timer = v1719;
  int v1598 = v1->timer;
  int * v1599 = v1->reg_ready;
  int v1600 = v1599[9];
  int v1722 = v1600 + ((v1598 - v1600) & (~((v1598 - v1600) >> 31)));
  v1->timer = v1722;
  int v1602 = v1->timer;
  int * v1603 = v1->reg_ready;
  int v1604 = v1603[10];
  int v1725 = v1604 + ((v1602 - v1604) & (~((v1602 - v1604) >> 31)));
  v1->timer = v1725;
  int v1606 = v1->timer;
  int * v1607 = v1->reg_ready;
  int v1608 = v1607[11];
  int v1728 = v1608 + ((v1606 - v1608) & (~((v1606 - v1608) >> 31)));
  v1->timer = v1728;
  int v1610 = v1->timer;
  int * v1611 = v1->reg_ready;
  int v1612 = v1611[12];
  int v1731 = v1612 + ((v1610 - v1612) & (~((v1610 - v1612) >> 31)));
  v1->timer = v1731;
  int v1614 = v1->timer;
  int * v1615 = v1->reg_ready;
  int v1616 = v1615[13];
  int v1734 = v1616 + ((v1614 - v1616) & (~((v1614 - v1616) >> 31)));
  v1->timer = v1734;
  int v1618 = v1->timer;
  int * v1619 = v1->reg_ready;
  int v1620 = v1619[14];
  int v1737 = v1620 + ((v1618 - v1620) & (~((v1618 - v1620) >> 31)));
  v1->timer = v1737;
  int v1622 = v1->timer;
  int * v1623 = v1->reg_ready;
  int v1624 = v1623[15];
  int v1740 = v1624 + ((v1622 - v1624) & (~((v1622 - v1624) >> 31)));
  v1->timer = v1740;
  int v1626 = v1->timer;
  int * v1627 = v1->reg_ready;
  int v1628 = v1627[16];
  int v1743 = v1628 + ((v1626 - v1628) & (~((v1626 - v1628) >> 31)));
  v1->timer = v1743;
  int v1630 = v1->timer;
  int * v1631 = v1->reg_ready;
  int v1632 = v1631[17];
  int v1746 = v1632 + ((v1630 - v1632) & (~((v1630 - v1632) >> 31)));
  v1->timer = v1746;
  int v1634 = v1->timer;
  int * v1635 = v1->reg_ready;
  int v1636 = v1635[18];
  int v1749 = v1636 + ((v1634 - v1636) & (~((v1634 - v1636) >> 31)));
  v1->timer = v1749;
  int v1638 = v1->timer;
  int * v1639 = v1->reg_ready;
  int v1640 = v1639[19];
  int v1752 = v1640 + ((v1638 - v1640) & (~((v1638 - v1640) >> 31)));
  v1->timer = v1752;
  int v1642 = v1->timer;
  int * v1643 = v1->reg_ready;
  int v1644 = v1643[20];
  int v1755 = v1644 + ((v1642 - v1644) & (~((v1642 - v1644) >> 31)));
  v1->timer = v1755;
  int v1646 = v1->timer;
  int * v1647 = v1->reg_ready;
  int v1648 = v1647[21];
  int v1758 = v1648 + ((v1646 - v1648) & (~((v1646 - v1648) >> 31)));
  v1->timer = v1758;
  int v1650 = v1->timer;
  int * v1651 = v1->reg_ready;
  int v1652 = v1651[22];
  int v1761 = v1652 + ((v1650 - v1652) & (~((v1650 - v1652) >> 31)));
  v1->timer = v1761;
  int v1654 = v1->timer;
  int * v1655 = v1->reg_ready;
  int v1656 = v1655[23];
  int v1764 = v1656 + ((v1654 - v1656) & (~((v1654 - v1656) >> 31)));
  v1->timer = v1764;
  int v1658 = v1->timer;
  int * v1659 = v1->reg_ready;
  int v1660 = v1659[24];
  int v1767 = v1660 + ((v1658 - v1660) & (~((v1658 - v1660) >> 31)));
  v1->timer = v1767;
  int v1662 = v1->timer;
  int * v1663 = v1->reg_ready;
  int v1664 = v1663[25];
  int v1770 = v1664 + ((v1662 - v1664) & (~((v1662 - v1664) >> 31)));
  v1->timer = v1770;
  int v1666 = v1->timer;
  int * v1667 = v1->reg_ready;
  int v1668 = v1667[26];
  int v1773 = v1668 + ((v1666 - v1668) & (~((v1666 - v1668) >> 31)));
  v1->timer = v1773;
  int v1670 = v1->timer;
  int * v1671 = v1->reg_ready;
  int v1672 = v1671[27];
  int v1776 = v1672 + ((v1670 - v1672) & (~((v1670 - v1672) >> 31)));
  v1->timer = v1776;
  int v1674 = v1->timer;
  int * v1675 = v1->reg_ready;
  int v1676 = v1675[28];
  int v1779 = v1676 + ((v1674 - v1676) & (~((v1674 - v1676) >> 31)));
  v1->timer = v1779;
  int v1678 = v1->timer;
  int * v1679 = v1->reg_ready;
  int v1680 = v1679[29];
  int v1782 = v1680 + ((v1678 - v1680) & (~((v1678 - v1680) >> 31)));
  v1->timer = v1782;
  int v1682 = v1->timer;
  int * v1683 = v1->reg_ready;
  int v1684 = v1683[30];
  int v1785 = v1684 + ((v1682 - v1684) & (~((v1682 - v1684) >> 31)));
  v1->timer = v1785;
  int v1686 = v1->timer;
  int * v1687 = v1->reg_ready;
  int v1688 = v1687[31];
  int v1788 = v1688 + ((v1686 - v1688) & (~((v1686 - v1688) >> 31)));
  v1->timer = v1788;
  return v1;
}

struct StateT * slot_10(struct StateT * v1055) {
  int v1056 = v1055->timer;
  int v1067 = v1056 + 1;
  v1055->timer = v1067;
  int * v1058 = v1055->reg_ready;
  int v1059 = v1058[6];
  int * v1060 = v1055->regs;
  int v1061 = v1060[6];
  int v1071 = (v1059 + ((v1056 - v1059) & (~((v1056 - v1059) >> 31)))) + 1;
  v1058[6] = v1071;
  int * v1063 = v1055->regs;
  int v1073 = v1061 + 4;
  v1063[6] = v1073;
  struct StateT * v1065 = slot_11(v1055);
  return v1065;
}

struct StateT * slot_1(struct StateT * v18) {
  int v19 = v18->timer;
  int v27 = v19 + 1;
  v18->timer = v27;
  int * v21 = v18->reg_ready;
  v21[7] = v27;
  int * v23 = v18->regs;
  v23[7] = 16;
  struct StateT * v25 = slot_2(v18);
  return v25;
}

struct StateT * slot_8(struct StateT * v528) {
  int v529 = v528->timer;
  int v702 = v529 + 1;
  v528->timer = v702;
  int * v531 = v528->reg_ready;
  int * v533 = v528->regs;
  int v534 = v533[6];
  int v536 = v533[5];
  int * v537 = v528->cache_tags;
  int v708 = (((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1)) & 1) * 2;
  int v538 = v537[v708];
  int v709 = ((((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1)) & 1) * 2) + 1;
  int v539 = v537[v709];
  int v710 = 4 + ((((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1)) & 3) * 2);
  int v540 = v537[v710];
  int v711 = (4 + ((((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v541 = v537[v711];
  int v542 = v528->timer;
  int v712 = v542 + ((100 ^ (((~(((v540 ^ ((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1))) | (-(v540 ^ ((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1))))) >> 31)) | (~(((v541 ^ ((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1))) | (-(v541 ^ ((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v538 ^ ((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1))) | (-(v538 ^ ((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1))))) >> 31)) | (~(((v539 ^ ((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1))) | (-(v539 ^ ((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v540 ^ ((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1))) | (-(v540 ^ ((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1))))) >> 31)) | (~(((v541 ^ ((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1))) | (-(v541 ^ ((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1))))) >> 31))) & 104)))));
  v528->timer = v712;
  bool v713 = !(((~(((v538 ^ ((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1))) | (-(v538 ^ ((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1))))) >> 31)) | (~(((v539 ^ ((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1))) | (-(v539 ^ ((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1))))) >> 31))) == 0);
  int v636;
  if (v713) {
    int * v544 = v528->cache_age;
    int v715 = ((((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1)) & 1) * 2) + ((~(((v539 ^ ((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1))) | (-(v539 ^ ((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1))))) >> 31)) & 1);
    int v545 = v544[v715];
    int v546 = v544[v708];
    int v716 = v546 + ((int)((unsigned int)(v546 - v545) >> 31));
    v544[v708] = v716;
    int * v548 = v528->cache_age;
    int v549 = v548[v709];
    int v718 = v549 + ((int)((unsigned int)(v549 - v545) >> 31));
    v548[v709] = v718;
    int * v551 = v528->cache_age;
    v551[v715] = 0;
    v636 = v715;
  } else {
    int * v554 = v528->cache_age;
    int v722 = (((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1)) & 1) * 2;
    int v555 = v554[v722];
    int * v556 = v528->cache_tags;
    int v557 = v556[v722];
    int v558 = v554[v709];
    int v559 = v556[v709];
    bool v724 = !(((~(((v540 ^ ((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1))) | (-(v540 ^ ((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1))))) >> 31)) | (~(((v541 ^ ((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1))) | (-(v541 ^ ((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1))))) >> 31))) == 0);
    int v613;
    if (v724) {
      int * v560 = v528->cache_age;
      int v726 = (4 + ((((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1)) & 3) * 2)) + ((~(((v541 ^ ((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1))) | (-(v541 ^ ((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1))))) >> 31)) & 1);
      int v561 = v560[v726];
      int v562 = v560[v710];
      int v727 = v562 + ((int)((unsigned int)(v562 - v561) >> 31));
      v560[v710] = v727;
      int * v564 = v528->cache_age;
      int v565 = v564[v711];
      int v729 = v565 + ((int)((unsigned int)(v565 - v561) >> 31));
      v564[v711] = v729;
      int * v567 = v528->cache_age;
      v567[v726] = 0;
      v613 = v726;
    } else {
      int * v570 = v528->cache_age;
      int v733 = 4 + ((((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1)) & 3) * 2);
      int v571 = v570[v733];
      int * v572 = v528->cache_tags;
      int v573 = v572[v733];
      int v574 = v570[v711];
      int v575 = v572[v711];
      int * v576 = v528->cache_dirty;
      int v736 = (4 + ((((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1)) & 3) * 2)) + ((((v571 + ((~(((v573 ^ -1) | (-(v573 ^ -1))) >> 31)) & 2)) - (v574 + ((~(((v575 ^ -1) | (-(v575 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v577 = v576[v736];
      bool v737 = !(v577 == 0);
      if (v737) {
        int * v578 = v528->cache_tags;
        int v579 = v578[v736];
        int * v580 = v528->cache_vals;
        int v740 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1)) & 3) * 2)) + ((((v571 + ((~(((v573 ^ -1) | (-(v573 ^ -1))) >> 31)) & 2)) - (v574 + ((~(((v575 ^ -1) | (-(v575 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v581 = v580[v740];
        int v741 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1)) & 3) * 2)) + ((((v571 + ((~(((v573 ^ -1) | (-(v573 ^ -1))) >> 31)) & 2)) - (v574 + ((~(((v575 ^ -1) | (-(v575 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v582 = v580[v741];
        int * v583 = v528->mem;
        int v743 = v579 * 2;
        v583[v743] = v581;
        int * v585 = v528->mem;
        int v746 = (v579 * 2) + 1;
        v585[v746] = v582;
        ;
      } else {
        ;
      }
      int * v590 = v528->mem;
      int v751 = ((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1)) * 2;
      int v591 = v590[v751];
      int v752 = (((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1)) * 2) + 1;
      int v592 = v590[v752];
      int * v593 = v528->cache_vals;
      int v754 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1)) & 3) * 2)) + ((((v571 + ((~(((v573 ^ -1) | (-(v573 ^ -1))) >> 31)) & 2)) - (v574 + ((~(((v575 ^ -1) | (-(v575 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v593[v754] = v591;
      int * v595 = v528->cache_vals;
      int v757 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1)) & 3) * 2)) + ((((v571 + ((~(((v573 ^ -1) | (-(v573 ^ -1))) >> 31)) & 2)) - (v574 + ((~(((v575 ^ -1) | (-(v575 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v595[v757] = v592;
      int * v597 = v528->cache_tags;
      int v760 = (int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1);
      v597[v736] = v760;
      int * v599 = v528->cache_dirty;
      v599[v736] = 0;
      int * v601 = v528->cache_age;
      v601[v736] = 1;
      int * v603 = v528->cache_age;
      int v604 = v603[v736];
      int v605 = v603[v710];
      int v766 = v605 + ((int)((unsigned int)(v605 - v604) >> 31));
      v603[v710] = v766;
      int * v607 = v528->cache_age;
      int v608 = v607[v711];
      int v768 = v608 + ((int)((unsigned int)(v608 - v604) >> 31));
      v607[v711] = v768;
      int * v610 = v528->cache_age;
      v610[v736] = 0;
      v613 = v736;
    }
    int * v614 = v528->cache_vals;
    int v771 = v613 * 2;
    int v615 = v614[v771];
    int v772 = (v613 * 2) + 1;
    int v616 = v614[v772];
    int v773 = (((((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1)) & 1) * 2) + ((((v555 + ((~(((v557 ^ -1) | (-(v557 ^ -1))) >> 31)) & 2)) - (v558 + ((~(((v559 ^ -1) | (-(v559 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v614[v773] = v615;
    int * v618 = v528->cache_vals;
    int v776 = ((((((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1)) & 1) * 2) + ((((v555 + ((~(((v557 ^ -1) | (-(v557 ^ -1))) >> 31)) & 2)) - (v558 + ((~(((v559 ^ -1) | (-(v559 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v618[v776] = v616;
    int * v620 = v528->cache_tags;
    int v779 = ((((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1)) & 1) * 2) + ((((v555 + ((~(((v557 ^ -1) | (-(v557 ^ -1))) >> 31)) & 2)) - (v558 + ((~(((v559 ^ -1) | (-(v559 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v780 = (int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1);
    v620[v779] = v780;
    int * v622 = v528->cache_dirty;
    v622[v779] = 0;
    int * v624 = v528->cache_age;
    v624[v779] = 1;
    int * v626 = v528->cache_age;
    int v627 = v626[v779];
    int v628 = v626[v708];
    int v786 = v628 + ((int)((unsigned int)(v628 - v627) >> 31));
    v626[v708] = v786;
    int * v630 = v528->cache_age;
    int v631 = v630[v709];
    int v788 = v631 + ((int)((unsigned int)(v631 - v627) >> 31));
    v630[v709] = v788;
    int * v633 = v528->cache_age;
    v633[v779] = 0;
    v636 = v779;
  }
  int * v637 = v528->cache_vals;
  int v791 = (v636 * 2) + (((int)((unsigned int)v534 >> 2)) & 1);
  v637[v791] = v536;
  int * v639 = v528->cache_tags;
  int v640 = v639[v710];
  int v641 = v639[v711];
  bool v794 = !(((~(((v640 ^ ((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1))) | (-(v640 ^ ((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1))))) >> 31)) | (~(((v641 ^ ((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1))) | (-(v641 ^ ((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1))))) >> 31))) == 0);
  int v695;
  if (v794) {
    int * v642 = v528->cache_age;
    int v796 = (4 + ((((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1)) & 3) * 2)) + ((~(((v641 ^ ((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1))) | (-(v641 ^ ((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1))))) >> 31)) & 1);
    int v643 = v642[v796];
    int v644 = v642[v710];
    int v797 = v644 + ((int)((unsigned int)(v644 - v643) >> 31));
    v642[v710] = v797;
    int * v646 = v528->cache_age;
    int v647 = v646[v711];
    int v799 = v647 + ((int)((unsigned int)(v647 - v643) >> 31));
    v646[v711] = v799;
    int * v649 = v528->cache_age;
    v649[v796] = 0;
    v695 = v796;
  } else {
    int * v652 = v528->cache_age;
    int v803 = 4 + ((((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1)) & 3) * 2);
    int v653 = v652[v803];
    int * v654 = v528->cache_tags;
    int v655 = v654[v803];
    int v656 = v652[v711];
    int v657 = v654[v711];
    int * v658 = v528->cache_dirty;
    int v806 = (4 + ((((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1)) & 3) * 2)) + ((((v653 + ((~(((v655 ^ -1) | (-(v655 ^ -1))) >> 31)) & 2)) - (v656 + ((~(((v657 ^ -1) | (-(v657 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v659 = v658[v806];
    bool v807 = !(v659 == 0);
    if (v807) {
      int * v660 = v528->cache_tags;
      int v661 = v660[v806];
      int * v662 = v528->cache_vals;
      int v810 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1)) & 3) * 2)) + ((((v653 + ((~(((v655 ^ -1) | (-(v655 ^ -1))) >> 31)) & 2)) - (v656 + ((~(((v657 ^ -1) | (-(v657 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v663 = v662[v810];
      int v811 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1)) & 3) * 2)) + ((((v653 + ((~(((v655 ^ -1) | (-(v655 ^ -1))) >> 31)) & 2)) - (v656 + ((~(((v657 ^ -1) | (-(v657 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v664 = v662[v811];
      int * v665 = v528->mem;
      int v813 = v661 * 2;
      v665[v813] = v663;
      int * v667 = v528->mem;
      int v816 = (v661 * 2) + 1;
      v667[v816] = v664;
      ;
    } else {
      ;
    }
    int * v672 = v528->mem;
    int v821 = ((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1)) * 2;
    int v673 = v672[v821];
    int v822 = (((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1)) * 2) + 1;
    int v674 = v672[v822];
    int * v675 = v528->cache_vals;
    int v824 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1)) & 3) * 2)) + ((((v653 + ((~(((v655 ^ -1) | (-(v655 ^ -1))) >> 31)) & 2)) - (v656 + ((~(((v657 ^ -1) | (-(v657 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v675[v824] = v673;
    int * v677 = v528->cache_vals;
    int v827 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1)) & 3) * 2)) + ((((v653 + ((~(((v655 ^ -1) | (-(v655 ^ -1))) >> 31)) & 2)) - (v656 + ((~(((v657 ^ -1) | (-(v657 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v677[v827] = v674;
    int * v679 = v528->cache_tags;
    int v830 = (int)((unsigned int)((int)((unsigned int)v534 >> 2)) >> 1);
    v679[v806] = v830;
    int * v681 = v528->cache_dirty;
    v681[v806] = 0;
    int * v683 = v528->cache_age;
    v683[v806] = 1;
    int * v685 = v528->cache_age;
    int v686 = v685[v806];
    int v687 = v685[v710];
    int v836 = v687 + ((int)((unsigned int)(v687 - v686) >> 31));
    v685[v710] = v836;
    int * v689 = v528->cache_age;
    int v690 = v689[v711];
    int v838 = v690 + ((int)((unsigned int)(v690 - v686) >> 31));
    v689[v711] = v838;
    int * v692 = v528->cache_age;
    v692[v806] = 0;
    v695 = v806;
  }
  int * v696 = v528->cache_vals;
  int v841 = (v695 * 2) + (((int)((unsigned int)v534 >> 2)) & 1);
  v696[v841] = v536;
  int * v698 = v528->cache_dirty;
  v698[v695] = 1;
  struct StateT * v700 = slot_9(v528);
  return v700;
}

struct StateT * slot_4(struct StateT * v58) {
  int * v59 = v58->saved_regs;
  int * v60 = v58->regs;
  int v61 = v60[8];
  v59[8] = v61;
  int v63 = v58->timer;
  int v80 = v63 + 1;
  v58->timer = v80;
  int * v65 = v58->reg_ready;
  int v66 = v65[9];
  int * v67 = v58->regs;
  int v68 = v67[9];
  int v69 = v65[6];
  int v70 = v67[6];
  int v85 = (v69 + (((v66 + ((v63 - v66) & (~((v63 - v66) >> 31)))) - v69) & (~(((v66 + ((v63 - v66) & (~((v63 - v66) >> 31)))) - v69) >> 31)))) + 1;
  v65[8] = v85;
  int * v72 = v58->regs;
  int v87 = v68 + v70;
  v72[8] = v87;
  struct StateT * v74 = slot_14(v58);
  return v74;
}

struct StateT * slot_9(struct StateT * v847) {
  int v848 = v847->timer;
  int v960 = v848 + 1;
  v847->timer = v960;
  int * v850 = v847->reg_ready;
  int v851 = v850[6];
  int * v852 = v847->regs;
  int v853 = v852[6];
  int * v854 = v847->cache_tags;
  int v965 = (((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1)) & 1) * 2;
  int v855 = v854[v965];
  int v966 = ((((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1)) & 1) * 2) + 1;
  int v856 = v854[v966];
  int v967 = 4 + ((((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1)) & 3) * 2);
  int v857 = v854[v967];
  int v968 = (4 + ((((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v858 = v854[v968];
  int * v859 = v847->cache_vals;
  bool v969 = !(((~(((v855 ^ ((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1))) | (-(v855 ^ ((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1))))) >> 31)) | (~(((v856 ^ ((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1))) | (-(v856 ^ ((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1))))) >> 31))) == 0);
  int v952;
  if (v969) {
    int * v860 = v847->cache_age;
    int v971 = ((((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1)) & 1) * 2) + ((~(((v856 ^ ((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1))) | (-(v856 ^ ((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1))))) >> 31)) & 1);
    int v861 = v860[v971];
    int v862 = v860[v965];
    int v972 = v862 + ((int)((unsigned int)(v862 - v861) >> 31));
    v860[v965] = v972;
    int * v864 = v847->cache_age;
    int v865 = v864[v966];
    int v974 = v865 + ((int)((unsigned int)(v865 - v861) >> 31));
    v864[v966] = v974;
    int * v867 = v847->cache_age;
    v867[v971] = 0;
    v952 = v971;
  } else {
    int * v870 = v847->cache_age;
    int v978 = (((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1)) & 1) * 2;
    int v871 = v870[v978];
    int * v872 = v847->cache_tags;
    int v873 = v872[v978];
    int v874 = v870[v966];
    int v875 = v872[v966];
    bool v980 = !(((~(((v857 ^ ((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1))) | (-(v857 ^ ((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1))))) >> 31)) | (~(((v858 ^ ((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1))) | (-(v858 ^ ((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1))))) >> 31))) == 0);
    int v929;
    if (v980) {
      int * v876 = v847->cache_age;
      int v982 = (4 + ((((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1)) & 3) * 2)) + ((~(((v858 ^ ((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1))) | (-(v858 ^ ((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1))))) >> 31)) & 1);
      int v877 = v876[v982];
      int v878 = v876[v967];
      int v983 = v878 + ((int)((unsigned int)(v878 - v877) >> 31));
      v876[v967] = v983;
      int * v880 = v847->cache_age;
      int v881 = v880[v968];
      int v985 = v881 + ((int)((unsigned int)(v881 - v877) >> 31));
      v880[v968] = v985;
      int * v883 = v847->cache_age;
      v883[v982] = 0;
      v929 = v982;
    } else {
      int * v886 = v847->cache_age;
      int v989 = 4 + ((((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1)) & 3) * 2);
      int v887 = v886[v989];
      int * v888 = v847->cache_tags;
      int v889 = v888[v989];
      int v890 = v886[v968];
      int v891 = v888[v968];
      int * v892 = v847->cache_dirty;
      int v992 = (4 + ((((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1)) & 3) * 2)) + ((((v887 + ((~(((v889 ^ -1) | (-(v889 ^ -1))) >> 31)) & 2)) - (v890 + ((~(((v891 ^ -1) | (-(v891 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v893 = v892[v992];
      bool v993 = !(v893 == 0);
      if (v993) {
        int * v894 = v847->cache_tags;
        int v895 = v894[v992];
        int * v896 = v847->cache_vals;
        int v996 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1)) & 3) * 2)) + ((((v887 + ((~(((v889 ^ -1) | (-(v889 ^ -1))) >> 31)) & 2)) - (v890 + ((~(((v891 ^ -1) | (-(v891 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v897 = v896[v996];
        int v997 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1)) & 3) * 2)) + ((((v887 + ((~(((v889 ^ -1) | (-(v889 ^ -1))) >> 31)) & 2)) - (v890 + ((~(((v891 ^ -1) | (-(v891 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v898 = v896[v997];
        int * v899 = v847->mem;
        int v999 = v895 * 2;
        v899[v999] = v897;
        int * v901 = v847->mem;
        int v1002 = (v895 * 2) + 1;
        v901[v1002] = v898;
        ;
      } else {
        ;
      }
      int * v906 = v847->mem;
      int v1007 = ((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1)) * 2;
      int v907 = v906[v1007];
      int v1008 = (((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1)) * 2) + 1;
      int v908 = v906[v1008];
      int * v909 = v847->cache_vals;
      int v1010 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1)) & 3) * 2)) + ((((v887 + ((~(((v889 ^ -1) | (-(v889 ^ -1))) >> 31)) & 2)) - (v890 + ((~(((v891 ^ -1) | (-(v891 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v909[v1010] = v907;
      int * v911 = v847->cache_vals;
      int v1013 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1)) & 3) * 2)) + ((((v887 + ((~(((v889 ^ -1) | (-(v889 ^ -1))) >> 31)) & 2)) - (v890 + ((~(((v891 ^ -1) | (-(v891 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v911[v1013] = v908;
      int * v913 = v847->cache_tags;
      int v1016 = (int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1);
      v913[v992] = v1016;
      int * v915 = v847->cache_dirty;
      v915[v992] = 0;
      int * v917 = v847->cache_age;
      v917[v992] = 1;
      int * v919 = v847->cache_age;
      int v920 = v919[v992];
      int v921 = v919[v967];
      int v1022 = v921 + ((int)((unsigned int)(v921 - v920) >> 31));
      v919[v967] = v1022;
      int * v923 = v847->cache_age;
      int v924 = v923[v968];
      int v1024 = v924 + ((int)((unsigned int)(v924 - v920) >> 31));
      v923[v968] = v1024;
      int * v926 = v847->cache_age;
      v926[v992] = 0;
      v929 = v992;
    }
    int * v930 = v847->cache_vals;
    int v1027 = v929 * 2;
    int v931 = v930[v1027];
    int v1028 = (v929 * 2) + 1;
    int v932 = v930[v1028];
    int v1029 = (((((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1)) & 1) * 2) + ((((v871 + ((~(((v873 ^ -1) | (-(v873 ^ -1))) >> 31)) & 2)) - (v874 + ((~(((v875 ^ -1) | (-(v875 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v930[v1029] = v931;
    int * v934 = v847->cache_vals;
    int v1032 = ((((((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1)) & 1) * 2) + ((((v871 + ((~(((v873 ^ -1) | (-(v873 ^ -1))) >> 31)) & 2)) - (v874 + ((~(((v875 ^ -1) | (-(v875 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v934[v1032] = v932;
    int * v936 = v847->cache_tags;
    int v1035 = ((((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1)) & 1) * 2) + ((((v871 + ((~(((v873 ^ -1) | (-(v873 ^ -1))) >> 31)) & 2)) - (v874 + ((~(((v875 ^ -1) | (-(v875 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1036 = (int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1);
    v936[v1035] = v1036;
    int * v938 = v847->cache_dirty;
    v938[v1035] = 0;
    int * v940 = v847->cache_age;
    v940[v1035] = 1;
    int * v942 = v847->cache_age;
    int v943 = v942[v1035];
    int v944 = v942[v965];
    int v1042 = v944 + ((int)((unsigned int)(v944 - v943) >> 31));
    v942[v965] = v1042;
    int * v946 = v847->cache_age;
    int v947 = v946[v966];
    int v1044 = v947 + ((int)((unsigned int)(v947 - v943) >> 31));
    v946[v966] = v1044;
    int * v949 = v847->cache_age;
    v949[v1035] = 0;
    v952 = v1035;
  }
  int v1047 = (v952 * 2) + (((int)((unsigned int)v853 >> 2)) & 1);
  int v953 = v859[v1047];
  int * v954 = v847->reg_ready;
  int v1050 = ((v851 + ((v848 - v851) & (~((v848 - v851) >> 31)))) + 1) + ((100 ^ (((~(((v857 ^ ((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1))) | (-(v857 ^ ((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1))))) >> 31)) | (~(((v858 ^ ((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1))) | (-(v858 ^ ((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v855 ^ ((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1))) | (-(v855 ^ ((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1))))) >> 31)) | (~(((v856 ^ ((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1))) | (-(v856 ^ ((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v857 ^ ((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1))) | (-(v857 ^ ((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1))))) >> 31)) | (~(((v858 ^ ((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1))) | (-(v858 ^ ((int)((unsigned int)((int)((unsigned int)v853 >> 2)) >> 1))))) >> 31))) & 104)))));
  v954[11] = v1050;
  int * v956 = v847->regs;
  v956[11] = v953;
  struct StateT * v958 = slot_10(v847);
  return v958;
}

struct StateT * slot_11(struct StateT * v1076) {
  int v1077 = v1076->timer;
  int v1081 = v1077 + 1;
  v1076->timer = v1081;
  struct StateT * v1079 = slot_12(v1076);
  return v1079;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->reg_ready;
  v5[6] = v11;
  int * v7 = v2->regs;
  v7[6] = 0;
  struct StateT * v9 = slot_1(v2);
  return v9;
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
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}