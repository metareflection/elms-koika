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

struct StateT * slot_12(struct StateT * v1103);
struct StateT * slot_14(struct StateT * v1135);
struct StateT * slot_6(struct StateT * v284);
struct StateT * slot_2(struct StateT * v28);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v1089);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v319);
struct StateT * slot_4(struct StateT * v49);
struct StateT * slot_9(struct StateT * v877);
struct StateT * slot_11(struct StateT * v1081);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v1103) {
  int v1104 = v1103->timer;
  int v1108 = v1104 + 1;
  v1103->timer = v1108;
  struct StateT * v1106 = slot_4(v1103);
  return v1106;
}

struct StateT * slot_14(struct StateT * v1135) {
  int * v1136 = v1135->saved_regs;
  int * v1137 = v1135->regs;
  int v1138 = v1137[5];
  v1136[5] = v1138;
  int v1140 = v1135->timer;
  int v1254 = v1140 + 1;
  v1135->timer = v1254;
  int * v1142 = v1135->regs;
  int v1143 = v1142[8];
  int * v1144 = v1135->cache_tags;
  int v1258 = (((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1)) & 1) * 2;
  int v1145 = v1144[v1258];
  int v1259 = ((((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1146 = v1144[v1259];
  int v1260 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1)) & 3) * 2);
  int v1147 = v1144[v1260];
  int v1261 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1148 = v1144[v1261];
  int v1149 = v1135->timer;
  int v1262 = v1149 + ((100 ^ (((~(((v1147 ^ ((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1))) | (-(v1147 ^ ((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1))))) >> 31)) | (~(((v1148 ^ ((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1))) | (-(v1148 ^ ((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1145 ^ ((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1))) | (-(v1145 ^ ((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1))))) >> 31)) | (~(((v1146 ^ ((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1))) | (-(v1146 ^ ((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1147 ^ ((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1))) | (-(v1147 ^ ((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1))))) >> 31)) | (~(((v1148 ^ ((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1))) | (-(v1148 ^ ((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1135->timer = v1262;
  int * v1151 = v1135->cache_vals;
  bool v1263 = !(((~(((v1145 ^ ((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1))) | (-(v1145 ^ ((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1))))) >> 31)) | (~(((v1146 ^ ((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1))) | (-(v1146 ^ ((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1))))) >> 31))) == 0);
  int v1244;
  if (v1263) {
    int * v1152 = v1135->cache_age;
    int v1265 = ((((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1)) & 1) * 2) + ((~(((v1146 ^ ((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1))) | (-(v1146 ^ ((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1))))) >> 31)) & 1);
    int v1153 = v1152[v1265];
    int v1154 = v1152[v1258];
    int v1266 = v1154 + ((int)((unsigned int)(v1154 - v1153) >> 31));
    v1152[v1258] = v1266;
    int * v1156 = v1135->cache_age;
    int v1157 = v1156[v1259];
    int v1268 = v1157 + ((int)((unsigned int)(v1157 - v1153) >> 31));
    v1156[v1259] = v1268;
    int * v1159 = v1135->cache_age;
    v1159[v1265] = 0;
    v1244 = v1265;
  } else {
    int * v1162 = v1135->cache_age;
    int v1272 = (((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1)) & 1) * 2;
    int v1163 = v1162[v1272];
    int * v1164 = v1135->cache_tags;
    int v1165 = v1164[v1272];
    int v1166 = v1162[v1259];
    int v1167 = v1164[v1259];
    bool v1274 = !(((~(((v1147 ^ ((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1))) | (-(v1147 ^ ((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1))))) >> 31)) | (~(((v1148 ^ ((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1))) | (-(v1148 ^ ((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1))))) >> 31))) == 0);
    int v1221;
    if (v1274) {
      int * v1168 = v1135->cache_age;
      int v1276 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1148 ^ ((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1))) | (-(v1148 ^ ((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1))))) >> 31)) & 1);
      int v1169 = v1168[v1276];
      int v1170 = v1168[v1260];
      int v1277 = v1170 + ((int)((unsigned int)(v1170 - v1169) >> 31));
      v1168[v1260] = v1277;
      int * v1172 = v1135->cache_age;
      int v1173 = v1172[v1261];
      int v1279 = v1173 + ((int)((unsigned int)(v1173 - v1169) >> 31));
      v1172[v1261] = v1279;
      int * v1175 = v1135->cache_age;
      v1175[v1276] = 0;
      v1221 = v1276;
    } else {
      int * v1178 = v1135->cache_age;
      int v1283 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1)) & 3) * 2);
      int v1179 = v1178[v1283];
      int * v1180 = v1135->cache_tags;
      int v1181 = v1180[v1283];
      int v1182 = v1178[v1261];
      int v1183 = v1180[v1261];
      int * v1184 = v1135->cache_dirty;
      int v1286 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1)) & 3) * 2)) + ((((v1179 + ((~(((v1181 ^ -1) | (-(v1181 ^ -1))) >> 31)) & 2)) - (v1182 + ((~(((v1183 ^ -1) | (-(v1183 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1185 = v1184[v1286];
      bool v1287 = !(v1185 == 0);
      if (v1287) {
        int * v1186 = v1135->cache_tags;
        int v1187 = v1186[v1286];
        int * v1188 = v1135->cache_vals;
        int v1290 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1)) & 3) * 2)) + ((((v1179 + ((~(((v1181 ^ -1) | (-(v1181 ^ -1))) >> 31)) & 2)) - (v1182 + ((~(((v1183 ^ -1) | (-(v1183 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1189 = v1188[v1290];
        int v1291 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1)) & 3) * 2)) + ((((v1179 + ((~(((v1181 ^ -1) | (-(v1181 ^ -1))) >> 31)) & 2)) - (v1182 + ((~(((v1183 ^ -1) | (-(v1183 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1190 = v1188[v1291];
        int * v1191 = v1135->mem;
        int v1293 = v1187 * 2;
        v1191[v1293] = v1189;
        int * v1193 = v1135->mem;
        int v1296 = (v1187 * 2) + 1;
        v1193[v1296] = v1190;
        ;
      } else {
        ;
      }
      int * v1198 = v1135->mem;
      int v1301 = ((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1)) * 2;
      int v1199 = v1198[v1301];
      int v1302 = (((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1)) * 2) + 1;
      int v1200 = v1198[v1302];
      int * v1201 = v1135->cache_vals;
      int v1304 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1)) & 3) * 2)) + ((((v1179 + ((~(((v1181 ^ -1) | (-(v1181 ^ -1))) >> 31)) & 2)) - (v1182 + ((~(((v1183 ^ -1) | (-(v1183 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1201[v1304] = v1199;
      int * v1203 = v1135->cache_vals;
      int v1307 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1)) & 3) * 2)) + ((((v1179 + ((~(((v1181 ^ -1) | (-(v1181 ^ -1))) >> 31)) & 2)) - (v1182 + ((~(((v1183 ^ -1) | (-(v1183 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1203[v1307] = v1200;
      int * v1205 = v1135->cache_tags;
      int v1310 = (int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1);
      v1205[v1286] = v1310;
      int * v1207 = v1135->cache_dirty;
      v1207[v1286] = 0;
      int * v1209 = v1135->cache_age;
      v1209[v1286] = 1;
      int * v1211 = v1135->cache_age;
      int v1212 = v1211[v1286];
      int v1213 = v1211[v1260];
      int v1316 = v1213 + ((int)((unsigned int)(v1213 - v1212) >> 31));
      v1211[v1260] = v1316;
      int * v1215 = v1135->cache_age;
      int v1216 = v1215[v1261];
      int v1318 = v1216 + ((int)((unsigned int)(v1216 - v1212) >> 31));
      v1215[v1261] = v1318;
      int * v1218 = v1135->cache_age;
      v1218[v1286] = 0;
      v1221 = v1286;
    }
    int * v1222 = v1135->cache_vals;
    int v1321 = v1221 * 2;
    int v1223 = v1222[v1321];
    int v1322 = (v1221 * 2) + 1;
    int v1224 = v1222[v1322];
    int v1323 = (((((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1)) & 1) * 2) + ((((v1163 + ((~(((v1165 ^ -1) | (-(v1165 ^ -1))) >> 31)) & 2)) - (v1166 + ((~(((v1167 ^ -1) | (-(v1167 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1222[v1323] = v1223;
    int * v1226 = v1135->cache_vals;
    int v1326 = ((((((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1)) & 1) * 2) + ((((v1163 + ((~(((v1165 ^ -1) | (-(v1165 ^ -1))) >> 31)) & 2)) - (v1166 + ((~(((v1167 ^ -1) | (-(v1167 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1226[v1326] = v1224;
    int * v1228 = v1135->cache_tags;
    int v1329 = ((((int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1)) & 1) * 2) + ((((v1163 + ((~(((v1165 ^ -1) | (-(v1165 ^ -1))) >> 31)) & 2)) - (v1166 + ((~(((v1167 ^ -1) | (-(v1167 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1330 = (int)((unsigned int)((int)((unsigned int)v1143 >> 2)) >> 1);
    v1228[v1329] = v1330;
    int * v1230 = v1135->cache_dirty;
    v1230[v1329] = 0;
    int * v1232 = v1135->cache_age;
    v1232[v1329] = 1;
    int * v1234 = v1135->cache_age;
    int v1235 = v1234[v1329];
    int v1236 = v1234[v1258];
    int v1336 = v1236 + ((int)((unsigned int)(v1236 - v1235) >> 31));
    v1234[v1258] = v1336;
    int * v1238 = v1135->cache_age;
    int v1239 = v1238[v1259];
    int v1338 = v1239 + ((int)((unsigned int)(v1239 - v1235) >> 31));
    v1238[v1259] = v1338;
    int * v1241 = v1135->cache_age;
    v1241[v1329] = 0;
    v1244 = v1329;
  }
  int v1341 = (v1244 * 2) + (((int)((unsigned int)v1143 >> 2)) & 1);
  int v1245 = v1151[v1341];
  int * v1246 = v1135->regs;
  v1246[5] = v1245;
  struct StateT * v1248 = slot_6(v1135);
  return v1248;
}

struct StateT * slot_6(struct StateT * v284) {
  int * v285 = v284->regs;
  int v286 = v285[6];
  int v287 = v285[7];
  bool v306 = v286 >= v287;
  struct StateT * v301;
  if (v306) {
    int v288 = v284->timer;
    int v307 = v288 + 15;
    v284->timer = v307;
    int * v290 = v284->saved_regs;
    int v291 = v290[8];
    int * v292 = v284->regs;
    v292[8] = v291;
    int * v294 = v284->saved_regs;
    int v295 = v294[5];
    int * v296 = v284->regs;
    v296[5] = v295;
    v301 = v284;
  } else {
    struct StateT * v299 = slot_8(v284);
    v301 = v299;
  }
  return v301;
}

struct StateT * slot_2(struct StateT * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[9] = 80;
  struct StateT * v33 = slot_12(v28);
  return v33;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v1089) {
  int v1090 = v1089->timer;
  int v1097 = v1090 + 1;
  v1089->timer = v1097;
  int * v1092 = v1089->regs;
  int v1093 = v1092[6];
  int v1100 = v1093 + 4;
  v1092[6] = v1100;
  struct StateT * v1095 = slot_11(v1089);
  return v1095;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v22 = v16 + 1;
  v15->timer = v22;
  int * v18 = v15->regs;
  v18[7] = 16;
  struct StateT * v20 = slot_2(v15);
  return v20;
}

struct StateT * slot_8(struct StateT * v319) {
  int v320 = v319->timer;
  int v624 = v320 + 1;
  v319->timer = v624;
  int * v322 = v319->regs;
  int v323 = v322[6];
  int v324 = v322[5];
  int * v325 = v319->saved_regs;
  int v326 = v322[11];
  v325[11] = v326;
  int v328 = v319->timer;
  int v631 = v328 + 1;
  v319->timer = v631;
  int * v330 = v319->regs;
  int v331 = v330[6];
  int * v332 = v319->cache_tags;
  int v634 = (((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1)) & 1) * 2;
  int v333 = v332[v634];
  int v635 = ((((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1)) & 1) * 2) + 1;
  int v334 = v332[v635];
  int v636 = 4 + ((((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1)) & 3) * 2);
  int v335 = v332[v636];
  int v637 = (4 + ((((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v336 = v332[v637];
  int v337 = v319->timer;
  int v638 = v337 + ((100 ^ (((~(((v335 ^ ((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1))) | (-(v335 ^ ((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1))))) >> 31)) | (~(((v336 ^ ((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1))) | (-(v336 ^ ((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v333 ^ ((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1))) | (-(v333 ^ ((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1))))) >> 31)) | (~(((v334 ^ ((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1))) | (-(v334 ^ ((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v335 ^ ((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1))) | (-(v335 ^ ((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1))))) >> 31)) | (~(((v336 ^ ((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1))) | (-(v336 ^ ((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1))))) >> 31))) & 104)))));
  v319->timer = v638;
  int * v339 = v319->cache_vals;
  bool v639 = !(((~(((v333 ^ ((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1))) | (-(v333 ^ ((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1))))) >> 31)) | (~(((v334 ^ ((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1))) | (-(v334 ^ ((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1))))) >> 31))) == 0);
  int v432;
  if (v639) {
    int * v340 = v319->cache_age;
    int v641 = ((((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1)) & 1) * 2) + ((~(((v334 ^ ((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1))) | (-(v334 ^ ((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1))))) >> 31)) & 1);
    int v341 = v340[v641];
    int v342 = v340[v634];
    int v642 = v342 + ((int)((unsigned int)(v342 - v341) >> 31));
    v340[v634] = v642;
    int * v344 = v319->cache_age;
    int v345 = v344[v635];
    int v644 = v345 + ((int)((unsigned int)(v345 - v341) >> 31));
    v344[v635] = v644;
    int * v347 = v319->cache_age;
    v347[v641] = 0;
    v432 = v641;
  } else {
    int * v350 = v319->cache_age;
    int v648 = (((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1)) & 1) * 2;
    int v351 = v350[v648];
    int * v352 = v319->cache_tags;
    int v353 = v352[v648];
    int v354 = v350[v635];
    int v355 = v352[v635];
    bool v650 = !(((~(((v335 ^ ((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1))) | (-(v335 ^ ((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1))))) >> 31)) | (~(((v336 ^ ((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1))) | (-(v336 ^ ((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1))))) >> 31))) == 0);
    int v409;
    if (v650) {
      int * v356 = v319->cache_age;
      int v652 = (4 + ((((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1)) & 3) * 2)) + ((~(((v336 ^ ((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1))) | (-(v336 ^ ((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1))))) >> 31)) & 1);
      int v357 = v356[v652];
      int v358 = v356[v636];
      int v653 = v358 + ((int)((unsigned int)(v358 - v357) >> 31));
      v356[v636] = v653;
      int * v360 = v319->cache_age;
      int v361 = v360[v637];
      int v655 = v361 + ((int)((unsigned int)(v361 - v357) >> 31));
      v360[v637] = v655;
      int * v363 = v319->cache_age;
      v363[v652] = 0;
      v409 = v652;
    } else {
      int * v366 = v319->cache_age;
      int v659 = 4 + ((((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1)) & 3) * 2);
      int v367 = v366[v659];
      int * v368 = v319->cache_tags;
      int v369 = v368[v659];
      int v370 = v366[v637];
      int v371 = v368[v637];
      int * v372 = v319->cache_dirty;
      int v662 = (4 + ((((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1)) & 3) * 2)) + ((((v367 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2)) - (v370 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v373 = v372[v662];
      bool v663 = !(v373 == 0);
      if (v663) {
        int * v374 = v319->cache_tags;
        int v375 = v374[v662];
        int * v376 = v319->cache_vals;
        int v666 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1)) & 3) * 2)) + ((((v367 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2)) - (v370 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v377 = v376[v666];
        int v667 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1)) & 3) * 2)) + ((((v367 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2)) - (v370 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v378 = v376[v667];
        int * v379 = v319->mem;
        int v669 = v375 * 2;
        v379[v669] = v377;
        int * v381 = v319->mem;
        int v672 = (v375 * 2) + 1;
        v381[v672] = v378;
        ;
      } else {
        ;
      }
      int * v386 = v319->mem;
      int v677 = ((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1)) * 2;
      int v387 = v386[v677];
      int v678 = (((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1)) * 2) + 1;
      int v388 = v386[v678];
      int * v389 = v319->cache_vals;
      int v680 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1)) & 3) * 2)) + ((((v367 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2)) - (v370 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v389[v680] = v387;
      int * v391 = v319->cache_vals;
      int v683 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1)) & 3) * 2)) + ((((v367 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2)) - (v370 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v391[v683] = v388;
      int * v393 = v319->cache_tags;
      int v686 = (int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1);
      v393[v662] = v686;
      int * v395 = v319->cache_dirty;
      v395[v662] = 0;
      int * v397 = v319->cache_age;
      v397[v662] = 1;
      int * v399 = v319->cache_age;
      int v400 = v399[v662];
      int v401 = v399[v636];
      int v692 = v401 + ((int)((unsigned int)(v401 - v400) >> 31));
      v399[v636] = v692;
      int * v403 = v319->cache_age;
      int v404 = v403[v637];
      int v694 = v404 + ((int)((unsigned int)(v404 - v400) >> 31));
      v403[v637] = v694;
      int * v406 = v319->cache_age;
      v406[v662] = 0;
      v409 = v662;
    }
    int * v410 = v319->cache_vals;
    int v697 = v409 * 2;
    int v411 = v410[v697];
    int v698 = (v409 * 2) + 1;
    int v412 = v410[v698];
    int v699 = (((((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1)) & 1) * 2) + ((((v351 + ((~(((v353 ^ -1) | (-(v353 ^ -1))) >> 31)) & 2)) - (v354 + ((~(((v355 ^ -1) | (-(v355 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v410[v699] = v411;
    int * v414 = v319->cache_vals;
    int v702 = ((((((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1)) & 1) * 2) + ((((v351 + ((~(((v353 ^ -1) | (-(v353 ^ -1))) >> 31)) & 2)) - (v354 + ((~(((v355 ^ -1) | (-(v355 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v414[v702] = v412;
    int * v416 = v319->cache_tags;
    int v705 = ((((int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1)) & 1) * 2) + ((((v351 + ((~(((v353 ^ -1) | (-(v353 ^ -1))) >> 31)) & 2)) - (v354 + ((~(((v355 ^ -1) | (-(v355 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v706 = (int)((unsigned int)((int)((unsigned int)v331 >> 2)) >> 1);
    v416[v705] = v706;
    int * v418 = v319->cache_dirty;
    v418[v705] = 0;
    int * v420 = v319->cache_age;
    v420[v705] = 1;
    int * v422 = v319->cache_age;
    int v423 = v422[v705];
    int v424 = v422[v634];
    int v712 = v424 + ((int)((unsigned int)(v424 - v423) >> 31));
    v422[v634] = v712;
    int * v426 = v319->cache_age;
    int v427 = v426[v635];
    int v714 = v427 + ((int)((unsigned int)(v427 - v423) >> 31));
    v426[v635] = v714;
    int * v429 = v319->cache_age;
    v429[v705] = 0;
    v432 = v705;
  }
  int v717 = (v432 * 2) + (((int)((unsigned int)v331 >> 2)) & 1);
  int v433 = v339[v717];
  int * v434 = v319->regs;
  v434[11] = v433;
  int * v436 = v319->saved_regs;
  int * v437 = v319->regs;
  int v438 = v437[6];
  v436[6] = v438;
  int v440 = v319->timer;
  int v723 = v440 + 1;
  v319->timer = v723;
  int * v442 = v319->regs;
  int v443 = v442[6];
  int v725 = v443 + 4;
  v442[6] = v725;
  int * v445 = v319->cache_tags;
  int v727 = (((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 1) * 2;
  int v446 = v445[v727];
  int v728 = ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 1) * 2) + 1;
  int v447 = v445[v728];
  int v729 = 4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2);
  int v448 = v445[v729];
  int v730 = (4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v449 = v445[v730];
  int v450 = v319->timer;
  int v731 = v450 + ((100 ^ (((~(((v448 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v448 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31)) | (~(((v449 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v449 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v446 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v446 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31)) | (~(((v447 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v447 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v448 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v448 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31)) | (~(((v449 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v449 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31))) & 104)))));
  v319->timer = v731;
  bool v732 = !(((~(((v446 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v446 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31)) | (~(((v447 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v447 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31))) == 0);
  int v544;
  if (v732) {
    int * v452 = v319->cache_age;
    int v734 = ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 1) * 2) + ((~(((v447 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v447 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31)) & 1);
    int v453 = v452[v734];
    int v454 = v452[v727];
    int v735 = v454 + ((int)((unsigned int)(v454 - v453) >> 31));
    v452[v727] = v735;
    int * v456 = v319->cache_age;
    int v457 = v456[v728];
    int v737 = v457 + ((int)((unsigned int)(v457 - v453) >> 31));
    v456[v728] = v737;
    int * v459 = v319->cache_age;
    v459[v734] = 0;
    v544 = v734;
  } else {
    int * v462 = v319->cache_age;
    int v741 = (((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 1) * 2;
    int v463 = v462[v741];
    int * v464 = v319->cache_tags;
    int v465 = v464[v741];
    int v466 = v462[v728];
    int v467 = v464[v728];
    bool v743 = !(((~(((v448 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v448 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31)) | (~(((v449 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v449 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31))) == 0);
    int v521;
    if (v743) {
      int * v468 = v319->cache_age;
      int v745 = (4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + ((~(((v449 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v449 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31)) & 1);
      int v469 = v468[v745];
      int v470 = v468[v729];
      int v746 = v470 + ((int)((unsigned int)(v470 - v469) >> 31));
      v468[v729] = v746;
      int * v472 = v319->cache_age;
      int v473 = v472[v730];
      int v748 = v473 + ((int)((unsigned int)(v473 - v469) >> 31));
      v472[v730] = v748;
      int * v475 = v319->cache_age;
      v475[v745] = 0;
      v521 = v745;
    } else {
      int * v478 = v319->cache_age;
      int v752 = 4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2);
      int v479 = v478[v752];
      int * v480 = v319->cache_tags;
      int v481 = v480[v752];
      int v482 = v478[v730];
      int v483 = v480[v730];
      int * v484 = v319->cache_dirty;
      int v755 = (4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + ((((v479 + ((~(((v481 ^ -1) | (-(v481 ^ -1))) >> 31)) & 2)) - (v482 + ((~(((v483 ^ -1) | (-(v483 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v485 = v484[v755];
      bool v756 = !(v485 == 0);
      if (v756) {
        int * v486 = v319->cache_tags;
        int v487 = v486[v755];
        int * v488 = v319->cache_vals;
        int v759 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + ((((v479 + ((~(((v481 ^ -1) | (-(v481 ^ -1))) >> 31)) & 2)) - (v482 + ((~(((v483 ^ -1) | (-(v483 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v489 = v488[v759];
        int v760 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + ((((v479 + ((~(((v481 ^ -1) | (-(v481 ^ -1))) >> 31)) & 2)) - (v482 + ((~(((v483 ^ -1) | (-(v483 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v490 = v488[v760];
        int * v491 = v319->mem;
        int v762 = v487 * 2;
        v491[v762] = v489;
        int * v493 = v319->mem;
        int v765 = (v487 * 2) + 1;
        v493[v765] = v490;
        ;
      } else {
        ;
      }
      int * v498 = v319->mem;
      int v770 = ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) * 2;
      int v499 = v498[v770];
      int v771 = (((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) * 2) + 1;
      int v500 = v498[v771];
      int * v501 = v319->cache_vals;
      int v773 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + ((((v479 + ((~(((v481 ^ -1) | (-(v481 ^ -1))) >> 31)) & 2)) - (v482 + ((~(((v483 ^ -1) | (-(v483 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v501[v773] = v499;
      int * v503 = v319->cache_vals;
      int v776 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + ((((v479 + ((~(((v481 ^ -1) | (-(v481 ^ -1))) >> 31)) & 2)) - (v482 + ((~(((v483 ^ -1) | (-(v483 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v503[v776] = v500;
      int * v505 = v319->cache_tags;
      int v779 = (int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1);
      v505[v755] = v779;
      int * v507 = v319->cache_dirty;
      v507[v755] = 0;
      int * v509 = v319->cache_age;
      v509[v755] = 1;
      int * v511 = v319->cache_age;
      int v512 = v511[v755];
      int v513 = v511[v729];
      int v785 = v513 + ((int)((unsigned int)(v513 - v512) >> 31));
      v511[v729] = v785;
      int * v515 = v319->cache_age;
      int v516 = v515[v730];
      int v787 = v516 + ((int)((unsigned int)(v516 - v512) >> 31));
      v515[v730] = v787;
      int * v518 = v319->cache_age;
      v518[v755] = 0;
      v521 = v755;
    }
    int * v522 = v319->cache_vals;
    int v790 = v521 * 2;
    int v523 = v522[v790];
    int v791 = (v521 * 2) + 1;
    int v524 = v522[v791];
    int v792 = (((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 1) * 2) + ((((v463 + ((~(((v465 ^ -1) | (-(v465 ^ -1))) >> 31)) & 2)) - (v466 + ((~(((v467 ^ -1) | (-(v467 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v522[v792] = v523;
    int * v526 = v319->cache_vals;
    int v795 = ((((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 1) * 2) + ((((v463 + ((~(((v465 ^ -1) | (-(v465 ^ -1))) >> 31)) & 2)) - (v466 + ((~(((v467 ^ -1) | (-(v467 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v526[v795] = v524;
    int * v528 = v319->cache_tags;
    int v798 = ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 1) * 2) + ((((v463 + ((~(((v465 ^ -1) | (-(v465 ^ -1))) >> 31)) & 2)) - (v466 + ((~(((v467 ^ -1) | (-(v467 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v799 = (int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1);
    v528[v798] = v799;
    int * v530 = v319->cache_dirty;
    v530[v798] = 0;
    int * v532 = v319->cache_age;
    v532[v798] = 1;
    int * v534 = v319->cache_age;
    int v535 = v534[v798];
    int v536 = v534[v727];
    int v805 = v536 + ((int)((unsigned int)(v536 - v535) >> 31));
    v534[v727] = v805;
    int * v538 = v319->cache_age;
    int v539 = v538[v728];
    int v807 = v539 + ((int)((unsigned int)(v539 - v535) >> 31));
    v538[v728] = v807;
    int * v541 = v319->cache_age;
    v541[v798] = 0;
    v544 = v798;
  }
  int * v545 = v319->cache_vals;
  int v810 = (v544 * 2) + (((int)((unsigned int)v323 >> 2)) & 1);
  v545[v810] = v324;
  int * v547 = v319->cache_tags;
  int v548 = v547[v729];
  int v549 = v547[v730];
  bool v813 = !(((~(((v548 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v548 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31)) | (~(((v549 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v549 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31))) == 0);
  int v603;
  if (v813) {
    int * v550 = v319->cache_age;
    int v815 = (4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + ((~(((v549 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))) | (-(v549 ^ ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1))))) >> 31)) & 1);
    int v551 = v550[v815];
    int v552 = v550[v729];
    int v816 = v552 + ((int)((unsigned int)(v552 - v551) >> 31));
    v550[v729] = v816;
    int * v554 = v319->cache_age;
    int v555 = v554[v730];
    int v818 = v555 + ((int)((unsigned int)(v555 - v551) >> 31));
    v554[v730] = v818;
    int * v557 = v319->cache_age;
    v557[v815] = 0;
    v603 = v815;
  } else {
    int * v560 = v319->cache_age;
    int v822 = 4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2);
    int v561 = v560[v822];
    int * v562 = v319->cache_tags;
    int v563 = v562[v822];
    int v564 = v560[v730];
    int v565 = v562[v730];
    int * v566 = v319->cache_dirty;
    int v825 = (4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + ((((v561 + ((~(((v563 ^ -1) | (-(v563 ^ -1))) >> 31)) & 2)) - (v564 + ((~(((v565 ^ -1) | (-(v565 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v567 = v566[v825];
    bool v826 = !(v567 == 0);
    if (v826) {
      int * v568 = v319->cache_tags;
      int v569 = v568[v825];
      int * v570 = v319->cache_vals;
      int v829 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + ((((v561 + ((~(((v563 ^ -1) | (-(v563 ^ -1))) >> 31)) & 2)) - (v564 + ((~(((v565 ^ -1) | (-(v565 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v571 = v570[v829];
      int v830 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + ((((v561 + ((~(((v563 ^ -1) | (-(v563 ^ -1))) >> 31)) & 2)) - (v564 + ((~(((v565 ^ -1) | (-(v565 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v572 = v570[v830];
      int * v573 = v319->mem;
      int v832 = v569 * 2;
      v573[v832] = v571;
      int * v575 = v319->mem;
      int v835 = (v569 * 2) + 1;
      v575[v835] = v572;
      ;
    } else {
      ;
    }
    int * v580 = v319->mem;
    int v840 = ((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) * 2;
    int v581 = v580[v840];
    int v841 = (((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) * 2) + 1;
    int v582 = v580[v841];
    int * v583 = v319->cache_vals;
    int v843 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + ((((v561 + ((~(((v563 ^ -1) | (-(v563 ^ -1))) >> 31)) & 2)) - (v564 + ((~(((v565 ^ -1) | (-(v565 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v583[v843] = v581;
    int * v585 = v319->cache_vals;
    int v846 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1)) & 3) * 2)) + ((((v561 + ((~(((v563 ^ -1) | (-(v563 ^ -1))) >> 31)) & 2)) - (v564 + ((~(((v565 ^ -1) | (-(v565 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v585[v846] = v582;
    int * v587 = v319->cache_tags;
    int v849 = (int)((unsigned int)((int)((unsigned int)v323 >> 2)) >> 1);
    v587[v825] = v849;
    int * v589 = v319->cache_dirty;
    v589[v825] = 0;
    int * v591 = v319->cache_age;
    v591[v825] = 1;
    int * v593 = v319->cache_age;
    int v594 = v593[v825];
    int v595 = v593[v729];
    int v855 = v595 + ((int)((unsigned int)(v595 - v594) >> 31));
    v593[v729] = v855;
    int * v597 = v319->cache_age;
    int v598 = v597[v730];
    int v857 = v598 + ((int)((unsigned int)(v598 - v594) >> 31));
    v597[v730] = v857;
    int * v600 = v319->cache_age;
    v600[v825] = 0;
    v603 = v825;
  }
  int * v604 = v319->cache_vals;
  int v860 = (v603 * 2) + (((int)((unsigned int)v323 >> 2)) & 1);
  v604[v860] = v324;
  int * v606 = v319->cache_dirty;
  v606[v603] = 1;
  bool v864 = ((int)((unsigned int)v331 >> 2)) == ((int)((unsigned int)v323 >> 2));
  struct StateT * v622;
  if (v864) {
    int v608 = v319->timer;
    int v865 = v608 + 15;
    v319->timer = v865;
    int * v610 = v319->saved_regs;
    int v611 = v610[11];
    int * v612 = v319->regs;
    v612[11] = v611;
    int * v614 = v319->saved_regs;
    int v615 = v614[6];
    int * v616 = v319->regs;
    v616[6] = v615;
    struct StateT * v618 = slot_9(v319);
    v622 = v618;
  } else {
    struct StateT * v620 = slot_11(v319);
    v622 = v620;
  }
  return v622;
}

struct StateT * slot_4(struct StateT * v49) {
  int * v50 = v49->saved_regs;
  int * v51 = v49->regs;
  int v52 = v51[8];
  v50[8] = v52;
  int v54 = v49->timer;
  int v66 = v54 + 1;
  v49->timer = v66;
  int * v56 = v49->regs;
  int v57 = v56[9];
  int v58 = v56[6];
  int v70 = v57 + v58;
  v56[8] = v70;
  struct StateT * v60 = slot_14(v49);
  return v60;
}

struct StateT * slot_9(struct StateT * v877) {
  int v878 = v877->timer;
  int v988 = v878 + 1;
  v877->timer = v988;
  int * v880 = v877->regs;
  int v881 = v880[6];
  int * v882 = v877->cache_tags;
  int v992 = (((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1)) & 1) * 2;
  int v883 = v882[v992];
  int v993 = ((((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1)) & 1) * 2) + 1;
  int v884 = v882[v993];
  int v994 = 4 + ((((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1)) & 3) * 2);
  int v885 = v882[v994];
  int v995 = (4 + ((((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v886 = v882[v995];
  int v887 = v877->timer;
  int v996 = v887 + ((100 ^ (((~(((v885 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))) | (-(v885 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))))) >> 31)) | (~(((v886 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))) | (-(v886 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v883 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))) | (-(v883 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))))) >> 31)) | (~(((v884 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))) | (-(v884 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v885 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))) | (-(v885 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))))) >> 31)) | (~(((v886 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))) | (-(v886 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))))) >> 31))) & 104)))));
  v877->timer = v996;
  int * v889 = v877->cache_vals;
  bool v997 = !(((~(((v883 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))) | (-(v883 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))))) >> 31)) | (~(((v884 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))) | (-(v884 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))))) >> 31))) == 0);
  int v982;
  if (v997) {
    int * v890 = v877->cache_age;
    int v999 = ((((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1)) & 1) * 2) + ((~(((v884 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))) | (-(v884 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))))) >> 31)) & 1);
    int v891 = v890[v999];
    int v892 = v890[v992];
    int v1000 = v892 + ((int)((unsigned int)(v892 - v891) >> 31));
    v890[v992] = v1000;
    int * v894 = v877->cache_age;
    int v895 = v894[v993];
    int v1002 = v895 + ((int)((unsigned int)(v895 - v891) >> 31));
    v894[v993] = v1002;
    int * v897 = v877->cache_age;
    v897[v999] = 0;
    v982 = v999;
  } else {
    int * v900 = v877->cache_age;
    int v1006 = (((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1)) & 1) * 2;
    int v901 = v900[v1006];
    int * v902 = v877->cache_tags;
    int v903 = v902[v1006];
    int v904 = v900[v993];
    int v905 = v902[v993];
    bool v1008 = !(((~(((v885 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))) | (-(v885 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))))) >> 31)) | (~(((v886 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))) | (-(v886 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))))) >> 31))) == 0);
    int v959;
    if (v1008) {
      int * v906 = v877->cache_age;
      int v1010 = (4 + ((((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1)) & 3) * 2)) + ((~(((v886 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))) | (-(v886 ^ ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1))))) >> 31)) & 1);
      int v907 = v906[v1010];
      int v908 = v906[v994];
      int v1011 = v908 + ((int)((unsigned int)(v908 - v907) >> 31));
      v906[v994] = v1011;
      int * v910 = v877->cache_age;
      int v911 = v910[v995];
      int v1013 = v911 + ((int)((unsigned int)(v911 - v907) >> 31));
      v910[v995] = v1013;
      int * v913 = v877->cache_age;
      v913[v1010] = 0;
      v959 = v1010;
    } else {
      int * v916 = v877->cache_age;
      int v1017 = 4 + ((((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1)) & 3) * 2);
      int v917 = v916[v1017];
      int * v918 = v877->cache_tags;
      int v919 = v918[v1017];
      int v920 = v916[v995];
      int v921 = v918[v995];
      int * v922 = v877->cache_dirty;
      int v1020 = (4 + ((((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1)) & 3) * 2)) + ((((v917 + ((~(((v919 ^ -1) | (-(v919 ^ -1))) >> 31)) & 2)) - (v920 + ((~(((v921 ^ -1) | (-(v921 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v923 = v922[v1020];
      bool v1021 = !(v923 == 0);
      if (v1021) {
        int * v924 = v877->cache_tags;
        int v925 = v924[v1020];
        int * v926 = v877->cache_vals;
        int v1024 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1)) & 3) * 2)) + ((((v917 + ((~(((v919 ^ -1) | (-(v919 ^ -1))) >> 31)) & 2)) - (v920 + ((~(((v921 ^ -1) | (-(v921 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v927 = v926[v1024];
        int v1025 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1)) & 3) * 2)) + ((((v917 + ((~(((v919 ^ -1) | (-(v919 ^ -1))) >> 31)) & 2)) - (v920 + ((~(((v921 ^ -1) | (-(v921 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v928 = v926[v1025];
        int * v929 = v877->mem;
        int v1027 = v925 * 2;
        v929[v1027] = v927;
        int * v931 = v877->mem;
        int v1030 = (v925 * 2) + 1;
        v931[v1030] = v928;
        ;
      } else {
        ;
      }
      int * v936 = v877->mem;
      int v1035 = ((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1)) * 2;
      int v937 = v936[v1035];
      int v1036 = (((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1)) * 2) + 1;
      int v938 = v936[v1036];
      int * v939 = v877->cache_vals;
      int v1038 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1)) & 3) * 2)) + ((((v917 + ((~(((v919 ^ -1) | (-(v919 ^ -1))) >> 31)) & 2)) - (v920 + ((~(((v921 ^ -1) | (-(v921 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v939[v1038] = v937;
      int * v941 = v877->cache_vals;
      int v1041 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1)) & 3) * 2)) + ((((v917 + ((~(((v919 ^ -1) | (-(v919 ^ -1))) >> 31)) & 2)) - (v920 + ((~(((v921 ^ -1) | (-(v921 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v941[v1041] = v938;
      int * v943 = v877->cache_tags;
      int v1044 = (int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1);
      v943[v1020] = v1044;
      int * v945 = v877->cache_dirty;
      v945[v1020] = 0;
      int * v947 = v877->cache_age;
      v947[v1020] = 1;
      int * v949 = v877->cache_age;
      int v950 = v949[v1020];
      int v951 = v949[v994];
      int v1050 = v951 + ((int)((unsigned int)(v951 - v950) >> 31));
      v949[v994] = v1050;
      int * v953 = v877->cache_age;
      int v954 = v953[v995];
      int v1052 = v954 + ((int)((unsigned int)(v954 - v950) >> 31));
      v953[v995] = v1052;
      int * v956 = v877->cache_age;
      v956[v1020] = 0;
      v959 = v1020;
    }
    int * v960 = v877->cache_vals;
    int v1055 = v959 * 2;
    int v961 = v960[v1055];
    int v1056 = (v959 * 2) + 1;
    int v962 = v960[v1056];
    int v1057 = (((((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1)) & 1) * 2) + ((((v901 + ((~(((v903 ^ -1) | (-(v903 ^ -1))) >> 31)) & 2)) - (v904 + ((~(((v905 ^ -1) | (-(v905 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v960[v1057] = v961;
    int * v964 = v877->cache_vals;
    int v1060 = ((((((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1)) & 1) * 2) + ((((v901 + ((~(((v903 ^ -1) | (-(v903 ^ -1))) >> 31)) & 2)) - (v904 + ((~(((v905 ^ -1) | (-(v905 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v964[v1060] = v962;
    int * v966 = v877->cache_tags;
    int v1063 = ((((int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1)) & 1) * 2) + ((((v901 + ((~(((v903 ^ -1) | (-(v903 ^ -1))) >> 31)) & 2)) - (v904 + ((~(((v905 ^ -1) | (-(v905 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1064 = (int)((unsigned int)((int)((unsigned int)v881 >> 2)) >> 1);
    v966[v1063] = v1064;
    int * v968 = v877->cache_dirty;
    v968[v1063] = 0;
    int * v970 = v877->cache_age;
    v970[v1063] = 1;
    int * v972 = v877->cache_age;
    int v973 = v972[v1063];
    int v974 = v972[v992];
    int v1070 = v974 + ((int)((unsigned int)(v974 - v973) >> 31));
    v972[v992] = v1070;
    int * v976 = v877->cache_age;
    int v977 = v976[v993];
    int v1072 = v977 + ((int)((unsigned int)(v977 - v973) >> 31));
    v976[v993] = v1072;
    int * v979 = v877->cache_age;
    v979[v1063] = 0;
    v982 = v1063;
  }
  int v1075 = (v982 * 2) + (((int)((unsigned int)v881 >> 2)) & 1);
  int v983 = v889[v1075];
  int * v984 = v877->regs;
  v984[11] = v983;
  struct StateT * v986 = slot_10(v877);
  return v986;
}

struct StateT * slot_11(struct StateT * v1081) {
  int v1082 = v1081->timer;
  int v1086 = v1082 + 1;
  v1081->timer = v1086;
  struct StateT * v1084 = slot_12(v1081);
  return v1084;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[6] = 0;
  struct StateT * v7 = slot_1(v2);
  return v7;
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