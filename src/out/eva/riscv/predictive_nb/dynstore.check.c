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

struct StateT * slot_12(struct StateT * v906);
struct StateT * slot_14(struct StateT * v946);
struct StateT * slot_6(struct StateT * v305);
struct StateT * slot_2(struct StateT * v34);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v877);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_8(struct StateT * v350);
struct StateT * slot_4(struct StateT * v58);
struct StateT * slot_9(struct StateT * v669);
struct StateT * slot_11(struct StateT * v898);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v906) {
  int v907 = v906->timer;
  int v911 = v907 + 1;
  v906->timer = v911;
  struct StateT * v909 = slot_4(v906);
  return v909;
}

struct StateT * slot_14(struct StateT * v946) {
  int * v947 = v946->saved_regs;
  int * v948 = v946->regs;
  int v949 = v948[5];
  v947[5] = v949;
  int v951 = v946->timer;
  int v1067 = v951 + 1;
  v946->timer = v1067;
  int * v953 = v946->reg_ready;
  int v954 = v953[8];
  int * v955 = v946->regs;
  int v956 = v955[8];
  int * v957 = v946->cache_tags;
  int v1072 = (((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 1) * 2;
  int v958 = v957[v1072];
  int v1073 = ((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 1) * 2) + 1;
  int v959 = v957[v1073];
  int v1074 = 4 + ((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 3) * 2);
  int v960 = v957[v1074];
  int v1075 = (4 + ((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v961 = v957[v1075];
  int * v962 = v946->cache_vals;
  bool v1076 = !(((~(((v958 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))) | (-(v958 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))))) >> 31)) | (~(((v959 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))) | (-(v959 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))))) >> 31))) == 0);
  int v1055;
  if (v1076) {
    int * v963 = v946->cache_age;
    int v1078 = ((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 1) * 2) + ((~(((v959 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))) | (-(v959 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))))) >> 31)) & 1);
    int v964 = v963[v1078];
    int v965 = v963[v1072];
    int v1079 = v965 + ((int)((unsigned int)(v965 - v964) >> 31));
    v963[v1072] = v1079;
    int * v967 = v946->cache_age;
    int v968 = v967[v1073];
    int v1081 = v968 + ((int)((unsigned int)(v968 - v964) >> 31));
    v967[v1073] = v1081;
    int * v970 = v946->cache_age;
    v970[v1078] = 0;
    v1055 = v1078;
  } else {
    int * v973 = v946->cache_age;
    int v1085 = (((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 1) * 2;
    int v974 = v973[v1085];
    int * v975 = v946->cache_tags;
    int v976 = v975[v1085];
    int v977 = v973[v1073];
    int v978 = v975[v1073];
    bool v1087 = !(((~(((v960 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))) | (-(v960 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))))) >> 31)) | (~(((v961 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))) | (-(v961 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))))) >> 31))) == 0);
    int v1032;
    if (v1087) {
      int * v979 = v946->cache_age;
      int v1089 = (4 + ((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 3) * 2)) + ((~(((v961 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))) | (-(v961 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))))) >> 31)) & 1);
      int v980 = v979[v1089];
      int v981 = v979[v1074];
      int v1090 = v981 + ((int)((unsigned int)(v981 - v980) >> 31));
      v979[v1074] = v1090;
      int * v983 = v946->cache_age;
      int v984 = v983[v1075];
      int v1092 = v984 + ((int)((unsigned int)(v984 - v980) >> 31));
      v983[v1075] = v1092;
      int * v986 = v946->cache_age;
      v986[v1089] = 0;
      v1032 = v1089;
    } else {
      int * v989 = v946->cache_age;
      int v1096 = 4 + ((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 3) * 2);
      int v990 = v989[v1096];
      int * v991 = v946->cache_tags;
      int v992 = v991[v1096];
      int v993 = v989[v1075];
      int v994 = v991[v1075];
      int * v995 = v946->cache_dirty;
      int v1099 = (4 + ((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 3) * 2)) + ((((v990 + ((~(((v992 ^ -1) | (-(v992 ^ -1))) >> 31)) & 2)) - (v993 + ((~(((v994 ^ -1) | (-(v994 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v996 = v995[v1099];
      bool v1100 = !(v996 == 0);
      if (v1100) {
        int * v997 = v946->cache_tags;
        int v998 = v997[v1099];
        int * v999 = v946->cache_vals;
        int v1103 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 3) * 2)) + ((((v990 + ((~(((v992 ^ -1) | (-(v992 ^ -1))) >> 31)) & 2)) - (v993 + ((~(((v994 ^ -1) | (-(v994 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1000 = v999[v1103];
        int v1104 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 3) * 2)) + ((((v990 + ((~(((v992 ^ -1) | (-(v992 ^ -1))) >> 31)) & 2)) - (v993 + ((~(((v994 ^ -1) | (-(v994 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1001 = v999[v1104];
        int * v1002 = v946->mem;
        int v1106 = v998 * 2;
        v1002[v1106] = v1000;
        int * v1004 = v946->mem;
        int v1109 = (v998 * 2) + 1;
        v1004[v1109] = v1001;
        ;
      } else {
        ;
      }
      int * v1009 = v946->mem;
      int v1114 = ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) * 2;
      int v1010 = v1009[v1114];
      int v1115 = (((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) * 2) + 1;
      int v1011 = v1009[v1115];
      int * v1012 = v946->cache_vals;
      int v1117 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 3) * 2)) + ((((v990 + ((~(((v992 ^ -1) | (-(v992 ^ -1))) >> 31)) & 2)) - (v993 + ((~(((v994 ^ -1) | (-(v994 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1012[v1117] = v1010;
      int * v1014 = v946->cache_vals;
      int v1120 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 3) * 2)) + ((((v990 + ((~(((v992 ^ -1) | (-(v992 ^ -1))) >> 31)) & 2)) - (v993 + ((~(((v994 ^ -1) | (-(v994 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1014[v1120] = v1011;
      int * v1016 = v946->cache_tags;
      int v1123 = (int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1);
      v1016[v1099] = v1123;
      int * v1018 = v946->cache_dirty;
      v1018[v1099] = 0;
      int * v1020 = v946->cache_age;
      v1020[v1099] = 1;
      int * v1022 = v946->cache_age;
      int v1023 = v1022[v1099];
      int v1024 = v1022[v1074];
      int v1129 = v1024 + ((int)((unsigned int)(v1024 - v1023) >> 31));
      v1022[v1074] = v1129;
      int * v1026 = v946->cache_age;
      int v1027 = v1026[v1075];
      int v1131 = v1027 + ((int)((unsigned int)(v1027 - v1023) >> 31));
      v1026[v1075] = v1131;
      int * v1029 = v946->cache_age;
      v1029[v1099] = 0;
      v1032 = v1099;
    }
    int * v1033 = v946->cache_vals;
    int v1134 = v1032 * 2;
    int v1034 = v1033[v1134];
    int v1135 = (v1032 * 2) + 1;
    int v1035 = v1033[v1135];
    int v1136 = (((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 1) * 2) + ((((v974 + ((~(((v976 ^ -1) | (-(v976 ^ -1))) >> 31)) & 2)) - (v977 + ((~(((v978 ^ -1) | (-(v978 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1033[v1136] = v1034;
    int * v1037 = v946->cache_vals;
    int v1139 = ((((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 1) * 2) + ((((v974 + ((~(((v976 ^ -1) | (-(v976 ^ -1))) >> 31)) & 2)) - (v977 + ((~(((v978 ^ -1) | (-(v978 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1037[v1139] = v1035;
    int * v1039 = v946->cache_tags;
    int v1142 = ((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 1) * 2) + ((((v974 + ((~(((v976 ^ -1) | (-(v976 ^ -1))) >> 31)) & 2)) - (v977 + ((~(((v978 ^ -1) | (-(v978 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1143 = (int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1);
    v1039[v1142] = v1143;
    int * v1041 = v946->cache_dirty;
    v1041[v1142] = 0;
    int * v1043 = v946->cache_age;
    v1043[v1142] = 1;
    int * v1045 = v946->cache_age;
    int v1046 = v1045[v1142];
    int v1047 = v1045[v1072];
    int v1149 = v1047 + ((int)((unsigned int)(v1047 - v1046) >> 31));
    v1045[v1072] = v1149;
    int * v1049 = v946->cache_age;
    int v1050 = v1049[v1073];
    int v1151 = v1050 + ((int)((unsigned int)(v1050 - v1046) >> 31));
    v1049[v1073] = v1151;
    int * v1052 = v946->cache_age;
    v1052[v1142] = 0;
    v1055 = v1142;
  }
  int v1154 = (v1055 * 2) + (((int)((unsigned int)v956 >> 2)) & 1);
  int v1056 = v962[v1154];
  int * v1057 = v946->reg_ready;
  int v1156 = ((v954 + ((v951 - v954) & (~((v951 - v954) >> 31)))) + 1) + ((100 ^ (((~(((v960 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))) | (-(v960 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))))) >> 31)) | (~(((v961 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))) | (-(v961 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v958 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))) | (-(v958 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))))) >> 31)) | (~(((v959 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))) | (-(v959 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v960 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))) | (-(v960 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))))) >> 31)) | (~(((v961 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))) | (-(v961 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1057[5] = v1156;
  int * v1059 = v946->regs;
  v1059[5] = v1056;
  struct StateT * v1061 = slot_6(v946);
  return v1061;
}

struct StateT * slot_6(struct StateT * v305) {
  int * v306 = v305->regs;
  int v307 = v306[6];
  int v308 = v306[7];
  bool v333 = v307 >= v308;
  struct StateT * v328;
  if (v333) {
    int v309 = v305->timer;
    int v334 = v309 + 15;
    v305->timer = v334;
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
    v319[8] = v320;
    int * v322 = v305->reg_ready;
    int v323 = v305->timer;
    v322[5] = v323;
    v328 = v305;
  } else {
    struct StateT * v326 = slot_8(v305);
    v328 = v326;
  }
  return v328;
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
  int v1206 = v1->timer;
  int * v1207 = v1->reg_ready;
  int v1208 = v1207[0];
  int v1339 = v1208 + ((v1206 - v1208) & (~((v1206 - v1208) >> 31)));
  v1->timer = v1339;
  int v1210 = v1->timer;
  int * v1211 = v1->reg_ready;
  int v1212 = v1211[1];
  int v1342 = v1212 + ((v1210 - v1212) & (~((v1210 - v1212) >> 31)));
  v1->timer = v1342;
  int v1214 = v1->timer;
  int * v1215 = v1->reg_ready;
  int v1216 = v1215[2];
  int v1345 = v1216 + ((v1214 - v1216) & (~((v1214 - v1216) >> 31)));
  v1->timer = v1345;
  int v1218 = v1->timer;
  int * v1219 = v1->reg_ready;
  int v1220 = v1219[3];
  int v1348 = v1220 + ((v1218 - v1220) & (~((v1218 - v1220) >> 31)));
  v1->timer = v1348;
  int v1222 = v1->timer;
  int * v1223 = v1->reg_ready;
  int v1224 = v1223[4];
  int v1351 = v1224 + ((v1222 - v1224) & (~((v1222 - v1224) >> 31)));
  v1->timer = v1351;
  int v1226 = v1->timer;
  int * v1227 = v1->reg_ready;
  int v1228 = v1227[5];
  int v1354 = v1228 + ((v1226 - v1228) & (~((v1226 - v1228) >> 31)));
  v1->timer = v1354;
  int v1230 = v1->timer;
  int * v1231 = v1->reg_ready;
  int v1232 = v1231[6];
  int v1357 = v1232 + ((v1230 - v1232) & (~((v1230 - v1232) >> 31)));
  v1->timer = v1357;
  int v1234 = v1->timer;
  int * v1235 = v1->reg_ready;
  int v1236 = v1235[7];
  int v1360 = v1236 + ((v1234 - v1236) & (~((v1234 - v1236) >> 31)));
  v1->timer = v1360;
  int v1238 = v1->timer;
  int * v1239 = v1->reg_ready;
  int v1240 = v1239[8];
  int v1363 = v1240 + ((v1238 - v1240) & (~((v1238 - v1240) >> 31)));
  v1->timer = v1363;
  int v1242 = v1->timer;
  int * v1243 = v1->reg_ready;
  int v1244 = v1243[9];
  int v1366 = v1244 + ((v1242 - v1244) & (~((v1242 - v1244) >> 31)));
  v1->timer = v1366;
  int v1246 = v1->timer;
  int * v1247 = v1->reg_ready;
  int v1248 = v1247[10];
  int v1369 = v1248 + ((v1246 - v1248) & (~((v1246 - v1248) >> 31)));
  v1->timer = v1369;
  int v1250 = v1->timer;
  int * v1251 = v1->reg_ready;
  int v1252 = v1251[11];
  int v1372 = v1252 + ((v1250 - v1252) & (~((v1250 - v1252) >> 31)));
  v1->timer = v1372;
  int v1254 = v1->timer;
  int * v1255 = v1->reg_ready;
  int v1256 = v1255[12];
  int v1375 = v1256 + ((v1254 - v1256) & (~((v1254 - v1256) >> 31)));
  v1->timer = v1375;
  int v1258 = v1->timer;
  int * v1259 = v1->reg_ready;
  int v1260 = v1259[13];
  int v1378 = v1260 + ((v1258 - v1260) & (~((v1258 - v1260) >> 31)));
  v1->timer = v1378;
  int v1262 = v1->timer;
  int * v1263 = v1->reg_ready;
  int v1264 = v1263[14];
  int v1381 = v1264 + ((v1262 - v1264) & (~((v1262 - v1264) >> 31)));
  v1->timer = v1381;
  int v1266 = v1->timer;
  int * v1267 = v1->reg_ready;
  int v1268 = v1267[15];
  int v1384 = v1268 + ((v1266 - v1268) & (~((v1266 - v1268) >> 31)));
  v1->timer = v1384;
  int v1270 = v1->timer;
  int * v1271 = v1->reg_ready;
  int v1272 = v1271[16];
  int v1387 = v1272 + ((v1270 - v1272) & (~((v1270 - v1272) >> 31)));
  v1->timer = v1387;
  int v1274 = v1->timer;
  int * v1275 = v1->reg_ready;
  int v1276 = v1275[17];
  int v1390 = v1276 + ((v1274 - v1276) & (~((v1274 - v1276) >> 31)));
  v1->timer = v1390;
  int v1278 = v1->timer;
  int * v1279 = v1->reg_ready;
  int v1280 = v1279[18];
  int v1393 = v1280 + ((v1278 - v1280) & (~((v1278 - v1280) >> 31)));
  v1->timer = v1393;
  int v1282 = v1->timer;
  int * v1283 = v1->reg_ready;
  int v1284 = v1283[19];
  int v1396 = v1284 + ((v1282 - v1284) & (~((v1282 - v1284) >> 31)));
  v1->timer = v1396;
  int v1286 = v1->timer;
  int * v1287 = v1->reg_ready;
  int v1288 = v1287[20];
  int v1399 = v1288 + ((v1286 - v1288) & (~((v1286 - v1288) >> 31)));
  v1->timer = v1399;
  int v1290 = v1->timer;
  int * v1291 = v1->reg_ready;
  int v1292 = v1291[21];
  int v1402 = v1292 + ((v1290 - v1292) & (~((v1290 - v1292) >> 31)));
  v1->timer = v1402;
  int v1294 = v1->timer;
  int * v1295 = v1->reg_ready;
  int v1296 = v1295[22];
  int v1405 = v1296 + ((v1294 - v1296) & (~((v1294 - v1296) >> 31)));
  v1->timer = v1405;
  int v1298 = v1->timer;
  int * v1299 = v1->reg_ready;
  int v1300 = v1299[23];
  int v1408 = v1300 + ((v1298 - v1300) & (~((v1298 - v1300) >> 31)));
  v1->timer = v1408;
  int v1302 = v1->timer;
  int * v1303 = v1->reg_ready;
  int v1304 = v1303[24];
  int v1411 = v1304 + ((v1302 - v1304) & (~((v1302 - v1304) >> 31)));
  v1->timer = v1411;
  int v1306 = v1->timer;
  int * v1307 = v1->reg_ready;
  int v1308 = v1307[25];
  int v1414 = v1308 + ((v1306 - v1308) & (~((v1306 - v1308) >> 31)));
  v1->timer = v1414;
  int v1310 = v1->timer;
  int * v1311 = v1->reg_ready;
  int v1312 = v1311[26];
  int v1417 = v1312 + ((v1310 - v1312) & (~((v1310 - v1312) >> 31)));
  v1->timer = v1417;
  int v1314 = v1->timer;
  int * v1315 = v1->reg_ready;
  int v1316 = v1315[27];
  int v1420 = v1316 + ((v1314 - v1316) & (~((v1314 - v1316) >> 31)));
  v1->timer = v1420;
  int v1318 = v1->timer;
  int * v1319 = v1->reg_ready;
  int v1320 = v1319[28];
  int v1423 = v1320 + ((v1318 - v1320) & (~((v1318 - v1320) >> 31)));
  v1->timer = v1423;
  int v1322 = v1->timer;
  int * v1323 = v1->reg_ready;
  int v1324 = v1323[29];
  int v1426 = v1324 + ((v1322 - v1324) & (~((v1322 - v1324) >> 31)));
  v1->timer = v1426;
  int v1326 = v1->timer;
  int * v1327 = v1->reg_ready;
  int v1328 = v1327[30];
  int v1429 = v1328 + ((v1326 - v1328) & (~((v1326 - v1328) >> 31)));
  v1->timer = v1429;
  int v1330 = v1->timer;
  int * v1331 = v1->reg_ready;
  int v1332 = v1331[31];
  int v1432 = v1332 + ((v1330 - v1332) & (~((v1330 - v1332) >> 31)));
  v1->timer = v1432;
  return v1;
}

struct StateT * slot_10(struct StateT * v877) {
  int v878 = v877->timer;
  int v889 = v878 + 1;
  v877->timer = v889;
  int * v880 = v877->reg_ready;
  int v881 = v880[6];
  int * v882 = v877->regs;
  int v883 = v882[6];
  int v893 = (v881 + ((v878 - v881) & (~((v878 - v881) >> 31)))) + 1;
  v880[6] = v893;
  int * v885 = v877->regs;
  int v895 = v883 + 4;
  v885[6] = v895;
  struct StateT * v887 = slot_11(v877);
  return v887;
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

struct StateT * slot_8(struct StateT * v350) {
  int v351 = v350->timer;
  int v524 = v351 + 1;
  v350->timer = v524;
  int * v353 = v350->reg_ready;
  int * v355 = v350->regs;
  int v356 = v355[6];
  int v358 = v355[5];
  int * v359 = v350->cache_tags;
  int v530 = (((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1)) & 1) * 2;
  int v360 = v359[v530];
  int v531 = ((((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1)) & 1) * 2) + 1;
  int v361 = v359[v531];
  int v532 = 4 + ((((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1)) & 3) * 2);
  int v362 = v359[v532];
  int v533 = (4 + ((((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v363 = v359[v533];
  int v364 = v350->timer;
  int v534 = v364 + ((100 ^ (((~(((v362 ^ ((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1))) | (-(v362 ^ ((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1))))) >> 31)) | (~(((v363 ^ ((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1))) | (-(v363 ^ ((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v360 ^ ((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1))) | (-(v360 ^ ((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1))))) >> 31)) | (~(((v361 ^ ((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1))) | (-(v361 ^ ((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v362 ^ ((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1))) | (-(v362 ^ ((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1))))) >> 31)) | (~(((v363 ^ ((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1))) | (-(v363 ^ ((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1))))) >> 31))) & 104)))));
  v350->timer = v534;
  bool v535 = !(((~(((v360 ^ ((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1))) | (-(v360 ^ ((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1))))) >> 31)) | (~(((v361 ^ ((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1))) | (-(v361 ^ ((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1))))) >> 31))) == 0);
  int v458;
  if (v535) {
    int * v366 = v350->cache_age;
    int v537 = ((((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1)) & 1) * 2) + ((~(((v361 ^ ((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1))) | (-(v361 ^ ((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1))))) >> 31)) & 1);
    int v367 = v366[v537];
    int v368 = v366[v530];
    int v538 = v368 + ((int)((unsigned int)(v368 - v367) >> 31));
    v366[v530] = v538;
    int * v370 = v350->cache_age;
    int v371 = v370[v531];
    int v540 = v371 + ((int)((unsigned int)(v371 - v367) >> 31));
    v370[v531] = v540;
    int * v373 = v350->cache_age;
    v373[v537] = 0;
    v458 = v537;
  } else {
    int * v376 = v350->cache_age;
    int v544 = (((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1)) & 1) * 2;
    int v377 = v376[v544];
    int * v378 = v350->cache_tags;
    int v379 = v378[v544];
    int v380 = v376[v531];
    int v381 = v378[v531];
    bool v546 = !(((~(((v362 ^ ((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1))) | (-(v362 ^ ((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1))))) >> 31)) | (~(((v363 ^ ((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1))) | (-(v363 ^ ((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1))))) >> 31))) == 0);
    int v435;
    if (v546) {
      int * v382 = v350->cache_age;
      int v548 = (4 + ((((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1)) & 3) * 2)) + ((~(((v363 ^ ((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1))) | (-(v363 ^ ((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1))))) >> 31)) & 1);
      int v383 = v382[v548];
      int v384 = v382[v532];
      int v549 = v384 + ((int)((unsigned int)(v384 - v383) >> 31));
      v382[v532] = v549;
      int * v386 = v350->cache_age;
      int v387 = v386[v533];
      int v551 = v387 + ((int)((unsigned int)(v387 - v383) >> 31));
      v386[v533] = v551;
      int * v389 = v350->cache_age;
      v389[v548] = 0;
      v435 = v548;
    } else {
      int * v392 = v350->cache_age;
      int v555 = 4 + ((((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1)) & 3) * 2);
      int v393 = v392[v555];
      int * v394 = v350->cache_tags;
      int v395 = v394[v555];
      int v396 = v392[v533];
      int v397 = v394[v533];
      int * v398 = v350->cache_dirty;
      int v558 = (4 + ((((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1)) & 3) * 2)) + ((((v393 + ((~(((v395 ^ -1) | (-(v395 ^ -1))) >> 31)) & 2)) - (v396 + ((~(((v397 ^ -1) | (-(v397 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v399 = v398[v558];
      bool v559 = !(v399 == 0);
      if (v559) {
        int * v400 = v350->cache_tags;
        int v401 = v400[v558];
        int * v402 = v350->cache_vals;
        int v562 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1)) & 3) * 2)) + ((((v393 + ((~(((v395 ^ -1) | (-(v395 ^ -1))) >> 31)) & 2)) - (v396 + ((~(((v397 ^ -1) | (-(v397 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v403 = v402[v562];
        int v563 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1)) & 3) * 2)) + ((((v393 + ((~(((v395 ^ -1) | (-(v395 ^ -1))) >> 31)) & 2)) - (v396 + ((~(((v397 ^ -1) | (-(v397 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v404 = v402[v563];
        int * v405 = v350->mem;
        int v565 = v401 * 2;
        v405[v565] = v403;
        int * v407 = v350->mem;
        int v568 = (v401 * 2) + 1;
        v407[v568] = v404;
        ;
      } else {
        ;
      }
      int * v412 = v350->mem;
      int v573 = ((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1)) * 2;
      int v413 = v412[v573];
      int v574 = (((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1)) * 2) + 1;
      int v414 = v412[v574];
      int * v415 = v350->cache_vals;
      int v576 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1)) & 3) * 2)) + ((((v393 + ((~(((v395 ^ -1) | (-(v395 ^ -1))) >> 31)) & 2)) - (v396 + ((~(((v397 ^ -1) | (-(v397 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v415[v576] = v413;
      int * v417 = v350->cache_vals;
      int v579 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1)) & 3) * 2)) + ((((v393 + ((~(((v395 ^ -1) | (-(v395 ^ -1))) >> 31)) & 2)) - (v396 + ((~(((v397 ^ -1) | (-(v397 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v417[v579] = v414;
      int * v419 = v350->cache_tags;
      int v582 = (int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1);
      v419[v558] = v582;
      int * v421 = v350->cache_dirty;
      v421[v558] = 0;
      int * v423 = v350->cache_age;
      v423[v558] = 1;
      int * v425 = v350->cache_age;
      int v426 = v425[v558];
      int v427 = v425[v532];
      int v588 = v427 + ((int)((unsigned int)(v427 - v426) >> 31));
      v425[v532] = v588;
      int * v429 = v350->cache_age;
      int v430 = v429[v533];
      int v590 = v430 + ((int)((unsigned int)(v430 - v426) >> 31));
      v429[v533] = v590;
      int * v432 = v350->cache_age;
      v432[v558] = 0;
      v435 = v558;
    }
    int * v436 = v350->cache_vals;
    int v593 = v435 * 2;
    int v437 = v436[v593];
    int v594 = (v435 * 2) + 1;
    int v438 = v436[v594];
    int v595 = (((((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1)) & 1) * 2) + ((((v377 + ((~(((v379 ^ -1) | (-(v379 ^ -1))) >> 31)) & 2)) - (v380 + ((~(((v381 ^ -1) | (-(v381 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v436[v595] = v437;
    int * v440 = v350->cache_vals;
    int v598 = ((((((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1)) & 1) * 2) + ((((v377 + ((~(((v379 ^ -1) | (-(v379 ^ -1))) >> 31)) & 2)) - (v380 + ((~(((v381 ^ -1) | (-(v381 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v440[v598] = v438;
    int * v442 = v350->cache_tags;
    int v601 = ((((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1)) & 1) * 2) + ((((v377 + ((~(((v379 ^ -1) | (-(v379 ^ -1))) >> 31)) & 2)) - (v380 + ((~(((v381 ^ -1) | (-(v381 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v602 = (int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1);
    v442[v601] = v602;
    int * v444 = v350->cache_dirty;
    v444[v601] = 0;
    int * v446 = v350->cache_age;
    v446[v601] = 1;
    int * v448 = v350->cache_age;
    int v449 = v448[v601];
    int v450 = v448[v530];
    int v608 = v450 + ((int)((unsigned int)(v450 - v449) >> 31));
    v448[v530] = v608;
    int * v452 = v350->cache_age;
    int v453 = v452[v531];
    int v610 = v453 + ((int)((unsigned int)(v453 - v449) >> 31));
    v452[v531] = v610;
    int * v455 = v350->cache_age;
    v455[v601] = 0;
    v458 = v601;
  }
  int * v459 = v350->cache_vals;
  int v613 = (v458 * 2) + (((int)((unsigned int)v356 >> 2)) & 1);
  v459[v613] = v358;
  int * v461 = v350->cache_tags;
  int v462 = v461[v532];
  int v463 = v461[v533];
  bool v616 = !(((~(((v462 ^ ((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1))) | (-(v462 ^ ((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1))))) >> 31)) | (~(((v463 ^ ((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1))) | (-(v463 ^ ((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1))))) >> 31))) == 0);
  int v517;
  if (v616) {
    int * v464 = v350->cache_age;
    int v618 = (4 + ((((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1)) & 3) * 2)) + ((~(((v463 ^ ((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1))) | (-(v463 ^ ((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1))))) >> 31)) & 1);
    int v465 = v464[v618];
    int v466 = v464[v532];
    int v619 = v466 + ((int)((unsigned int)(v466 - v465) >> 31));
    v464[v532] = v619;
    int * v468 = v350->cache_age;
    int v469 = v468[v533];
    int v621 = v469 + ((int)((unsigned int)(v469 - v465) >> 31));
    v468[v533] = v621;
    int * v471 = v350->cache_age;
    v471[v618] = 0;
    v517 = v618;
  } else {
    int * v474 = v350->cache_age;
    int v625 = 4 + ((((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1)) & 3) * 2);
    int v475 = v474[v625];
    int * v476 = v350->cache_tags;
    int v477 = v476[v625];
    int v478 = v474[v533];
    int v479 = v476[v533];
    int * v480 = v350->cache_dirty;
    int v628 = (4 + ((((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1)) & 3) * 2)) + ((((v475 + ((~(((v477 ^ -1) | (-(v477 ^ -1))) >> 31)) & 2)) - (v478 + ((~(((v479 ^ -1) | (-(v479 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v481 = v480[v628];
    bool v629 = !(v481 == 0);
    if (v629) {
      int * v482 = v350->cache_tags;
      int v483 = v482[v628];
      int * v484 = v350->cache_vals;
      int v632 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1)) & 3) * 2)) + ((((v475 + ((~(((v477 ^ -1) | (-(v477 ^ -1))) >> 31)) & 2)) - (v478 + ((~(((v479 ^ -1) | (-(v479 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v485 = v484[v632];
      int v633 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1)) & 3) * 2)) + ((((v475 + ((~(((v477 ^ -1) | (-(v477 ^ -1))) >> 31)) & 2)) - (v478 + ((~(((v479 ^ -1) | (-(v479 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v486 = v484[v633];
      int * v487 = v350->mem;
      int v635 = v483 * 2;
      v487[v635] = v485;
      int * v489 = v350->mem;
      int v638 = (v483 * 2) + 1;
      v489[v638] = v486;
      ;
    } else {
      ;
    }
    int * v494 = v350->mem;
    int v643 = ((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1)) * 2;
    int v495 = v494[v643];
    int v644 = (((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1)) * 2) + 1;
    int v496 = v494[v644];
    int * v497 = v350->cache_vals;
    int v646 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1)) & 3) * 2)) + ((((v475 + ((~(((v477 ^ -1) | (-(v477 ^ -1))) >> 31)) & 2)) - (v478 + ((~(((v479 ^ -1) | (-(v479 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v497[v646] = v495;
    int * v499 = v350->cache_vals;
    int v649 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1)) & 3) * 2)) + ((((v475 + ((~(((v477 ^ -1) | (-(v477 ^ -1))) >> 31)) & 2)) - (v478 + ((~(((v479 ^ -1) | (-(v479 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v499[v649] = v496;
    int * v501 = v350->cache_tags;
    int v652 = (int)((unsigned int)((int)((unsigned int)v356 >> 2)) >> 1);
    v501[v628] = v652;
    int * v503 = v350->cache_dirty;
    v503[v628] = 0;
    int * v505 = v350->cache_age;
    v505[v628] = 1;
    int * v507 = v350->cache_age;
    int v508 = v507[v628];
    int v509 = v507[v532];
    int v658 = v509 + ((int)((unsigned int)(v509 - v508) >> 31));
    v507[v532] = v658;
    int * v511 = v350->cache_age;
    int v512 = v511[v533];
    int v660 = v512 + ((int)((unsigned int)(v512 - v508) >> 31));
    v511[v533] = v660;
    int * v514 = v350->cache_age;
    v514[v628] = 0;
    v517 = v628;
  }
  int * v518 = v350->cache_vals;
  int v663 = (v517 * 2) + (((int)((unsigned int)v356 >> 2)) & 1);
  v518[v663] = v358;
  int * v520 = v350->cache_dirty;
  v520[v517] = 1;
  struct StateT * v522 = slot_9(v350);
  return v522;
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

struct StateT * slot_9(struct StateT * v669) {
  int v670 = v669->timer;
  int v782 = v670 + 1;
  v669->timer = v782;
  int * v672 = v669->reg_ready;
  int v673 = v672[6];
  int * v674 = v669->regs;
  int v675 = v674[6];
  int * v676 = v669->cache_tags;
  int v787 = (((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1)) & 1) * 2;
  int v677 = v676[v787];
  int v788 = ((((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1)) & 1) * 2) + 1;
  int v678 = v676[v788];
  int v789 = 4 + ((((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1)) & 3) * 2);
  int v679 = v676[v789];
  int v790 = (4 + ((((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v680 = v676[v790];
  int * v681 = v669->cache_vals;
  bool v791 = !(((~(((v677 ^ ((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1))) | (-(v677 ^ ((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1))))) >> 31)) | (~(((v678 ^ ((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1))) | (-(v678 ^ ((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1))))) >> 31))) == 0);
  int v774;
  if (v791) {
    int * v682 = v669->cache_age;
    int v793 = ((((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1)) & 1) * 2) + ((~(((v678 ^ ((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1))) | (-(v678 ^ ((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1))))) >> 31)) & 1);
    int v683 = v682[v793];
    int v684 = v682[v787];
    int v794 = v684 + ((int)((unsigned int)(v684 - v683) >> 31));
    v682[v787] = v794;
    int * v686 = v669->cache_age;
    int v687 = v686[v788];
    int v796 = v687 + ((int)((unsigned int)(v687 - v683) >> 31));
    v686[v788] = v796;
    int * v689 = v669->cache_age;
    v689[v793] = 0;
    v774 = v793;
  } else {
    int * v692 = v669->cache_age;
    int v800 = (((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1)) & 1) * 2;
    int v693 = v692[v800];
    int * v694 = v669->cache_tags;
    int v695 = v694[v800];
    int v696 = v692[v788];
    int v697 = v694[v788];
    bool v802 = !(((~(((v679 ^ ((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1))) | (-(v679 ^ ((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1))))) >> 31)) | (~(((v680 ^ ((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1))) | (-(v680 ^ ((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1))))) >> 31))) == 0);
    int v751;
    if (v802) {
      int * v698 = v669->cache_age;
      int v804 = (4 + ((((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1)) & 3) * 2)) + ((~(((v680 ^ ((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1))) | (-(v680 ^ ((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1))))) >> 31)) & 1);
      int v699 = v698[v804];
      int v700 = v698[v789];
      int v805 = v700 + ((int)((unsigned int)(v700 - v699) >> 31));
      v698[v789] = v805;
      int * v702 = v669->cache_age;
      int v703 = v702[v790];
      int v807 = v703 + ((int)((unsigned int)(v703 - v699) >> 31));
      v702[v790] = v807;
      int * v705 = v669->cache_age;
      v705[v804] = 0;
      v751 = v804;
    } else {
      int * v708 = v669->cache_age;
      int v811 = 4 + ((((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1)) & 3) * 2);
      int v709 = v708[v811];
      int * v710 = v669->cache_tags;
      int v711 = v710[v811];
      int v712 = v708[v790];
      int v713 = v710[v790];
      int * v714 = v669->cache_dirty;
      int v814 = (4 + ((((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1)) & 3) * 2)) + ((((v709 + ((~(((v711 ^ -1) | (-(v711 ^ -1))) >> 31)) & 2)) - (v712 + ((~(((v713 ^ -1) | (-(v713 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v715 = v714[v814];
      bool v815 = !(v715 == 0);
      if (v815) {
        int * v716 = v669->cache_tags;
        int v717 = v716[v814];
        int * v718 = v669->cache_vals;
        int v818 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1)) & 3) * 2)) + ((((v709 + ((~(((v711 ^ -1) | (-(v711 ^ -1))) >> 31)) & 2)) - (v712 + ((~(((v713 ^ -1) | (-(v713 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v719 = v718[v818];
        int v819 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1)) & 3) * 2)) + ((((v709 + ((~(((v711 ^ -1) | (-(v711 ^ -1))) >> 31)) & 2)) - (v712 + ((~(((v713 ^ -1) | (-(v713 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v720 = v718[v819];
        int * v721 = v669->mem;
        int v821 = v717 * 2;
        v721[v821] = v719;
        int * v723 = v669->mem;
        int v824 = (v717 * 2) + 1;
        v723[v824] = v720;
        ;
      } else {
        ;
      }
      int * v728 = v669->mem;
      int v829 = ((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1)) * 2;
      int v729 = v728[v829];
      int v830 = (((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1)) * 2) + 1;
      int v730 = v728[v830];
      int * v731 = v669->cache_vals;
      int v832 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1)) & 3) * 2)) + ((((v709 + ((~(((v711 ^ -1) | (-(v711 ^ -1))) >> 31)) & 2)) - (v712 + ((~(((v713 ^ -1) | (-(v713 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v731[v832] = v729;
      int * v733 = v669->cache_vals;
      int v835 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1)) & 3) * 2)) + ((((v709 + ((~(((v711 ^ -1) | (-(v711 ^ -1))) >> 31)) & 2)) - (v712 + ((~(((v713 ^ -1) | (-(v713 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v733[v835] = v730;
      int * v735 = v669->cache_tags;
      int v838 = (int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1);
      v735[v814] = v838;
      int * v737 = v669->cache_dirty;
      v737[v814] = 0;
      int * v739 = v669->cache_age;
      v739[v814] = 1;
      int * v741 = v669->cache_age;
      int v742 = v741[v814];
      int v743 = v741[v789];
      int v844 = v743 + ((int)((unsigned int)(v743 - v742) >> 31));
      v741[v789] = v844;
      int * v745 = v669->cache_age;
      int v746 = v745[v790];
      int v846 = v746 + ((int)((unsigned int)(v746 - v742) >> 31));
      v745[v790] = v846;
      int * v748 = v669->cache_age;
      v748[v814] = 0;
      v751 = v814;
    }
    int * v752 = v669->cache_vals;
    int v849 = v751 * 2;
    int v753 = v752[v849];
    int v850 = (v751 * 2) + 1;
    int v754 = v752[v850];
    int v851 = (((((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1)) & 1) * 2) + ((((v693 + ((~(((v695 ^ -1) | (-(v695 ^ -1))) >> 31)) & 2)) - (v696 + ((~(((v697 ^ -1) | (-(v697 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v752[v851] = v753;
    int * v756 = v669->cache_vals;
    int v854 = ((((((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1)) & 1) * 2) + ((((v693 + ((~(((v695 ^ -1) | (-(v695 ^ -1))) >> 31)) & 2)) - (v696 + ((~(((v697 ^ -1) | (-(v697 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v756[v854] = v754;
    int * v758 = v669->cache_tags;
    int v857 = ((((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1)) & 1) * 2) + ((((v693 + ((~(((v695 ^ -1) | (-(v695 ^ -1))) >> 31)) & 2)) - (v696 + ((~(((v697 ^ -1) | (-(v697 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v858 = (int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1);
    v758[v857] = v858;
    int * v760 = v669->cache_dirty;
    v760[v857] = 0;
    int * v762 = v669->cache_age;
    v762[v857] = 1;
    int * v764 = v669->cache_age;
    int v765 = v764[v857];
    int v766 = v764[v787];
    int v864 = v766 + ((int)((unsigned int)(v766 - v765) >> 31));
    v764[v787] = v864;
    int * v768 = v669->cache_age;
    int v769 = v768[v788];
    int v866 = v769 + ((int)((unsigned int)(v769 - v765) >> 31));
    v768[v788] = v866;
    int * v771 = v669->cache_age;
    v771[v857] = 0;
    v774 = v857;
  }
  int v869 = (v774 * 2) + (((int)((unsigned int)v675 >> 2)) & 1);
  int v775 = v681[v869];
  int * v776 = v669->reg_ready;
  int v872 = ((v673 + ((v670 - v673) & (~((v670 - v673) >> 31)))) + 1) + ((100 ^ (((~(((v679 ^ ((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1))) | (-(v679 ^ ((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1))))) >> 31)) | (~(((v680 ^ ((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1))) | (-(v680 ^ ((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v677 ^ ((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1))) | (-(v677 ^ ((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1))))) >> 31)) | (~(((v678 ^ ((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1))) | (-(v678 ^ ((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v679 ^ ((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1))) | (-(v679 ^ ((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1))))) >> 31)) | (~(((v680 ^ ((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1))) | (-(v680 ^ ((int)((unsigned int)((int)((unsigned int)v675 >> 2)) >> 1))))) >> 31))) & 104)))));
  v776[11] = v872;
  int * v778 = v669->regs;
  v778[11] = v775;
  struct StateT * v780 = slot_10(v669);
  return v780;
}

struct StateT * slot_11(struct StateT * v898) {
  int v899 = v898->timer;
  int v903 = v899 + 1;
  v898->timer = v903;
  struct StateT * v901 = slot_12(v898);
  return v901;
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
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}