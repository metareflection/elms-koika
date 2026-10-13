// verify: leak (CBMC should report VERIFICATION FAILED) [unwind 65]
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

struct StateT * slot_12(struct StateT * v1140);
struct StateT * slot_43(struct StateT * v4383);
struct StateT * slot_70(struct StateT * v6757);
struct StateT * slot_76(struct StateT * v7348);
struct StateT * slot_6(struct StateT * v848);
struct StateT * slot_47(struct StateT * v4637);
struct StateT * slot_29(struct StateT * v3185);
struct StateT * slot_55(struct StateT * v5551);
struct StateT * slot_16(struct StateT * v1786);
struct StateT * slot_5(struct StateT * v832);
struct StateT * slot_7(struct StateT * v870);
struct StateT * slot_31(struct StateT * v3221);
struct StateT * slot_54(struct StateT * v5236);
struct StateT * slot_26(struct StateT * v2939);
struct StateT * slot_82(struct StateT * v7631);
struct StateT * slot_65(struct StateT * v6208);
struct StateT * slot_10(struct StateT * v916);
struct StateT * slot_74(struct StateT * v6830);
struct StateT * slot_19(struct StateT * v2221);
struct StateT * slot_58(struct StateT * v5609);
struct StateT * slot_67(struct StateT * v6231);
struct StateT * slot_81(struct StateT * v7428);
struct StateT * slot_64(struct StateT * v6180);
struct StateT * slot_14(struct StateT * v1770);
struct StateT * slot_53(struct StateT * v5033);
struct StateT * slot_80(struct StateT * v7420);
struct StateT * slot_44(struct StateT * v4411);
struct StateT * slot_66(struct StateT * v6223);
struct StateT * slot_78(struct StateT * v7378);
struct StateT * slot_28(struct StateT * v3170);
struct StateT * slot_32(struct StateT * v3424);
struct StateT * slot_17(struct StateT * v1806);
struct StateT * slot_49(struct StateT * v4960);
struct StateT * slot_33(struct StateT * v3439);
struct StateT * slot_50(struct StateT * v4982);
struct StateT * slot_36(struct StateT * v3784);
struct StateT * slot_37(struct StateT * v3812);
struct StateT * slot_57(struct StateT * v5581);
struct StateT * slot_68(struct StateT * v6434);
struct StateT * slot_59(struct StateT * v5624);
struct StateT * slot_40(struct StateT * v4038);
struct StateT * slot_27(struct StateT * v2967);
struct StateT * slot_15(struct StateT * v1778);
struct StateT * slot_62(struct StateT * v6150);
struct StateT * slot_48(struct StateT * v4952);
struct StateT * slot_77(struct StateT * v7356);
struct StateT * slot_22(struct StateT * v2879);
struct StateT * slot_35(struct StateT * v3762);
struct StateT * slot_75(struct StateT * v7033);
struct StateT * slot_56(struct StateT * v5559);
struct StateT * slot_72(struct StateT * v6807);
struct StateT * slot_34(struct StateT * v3754);
struct StateT * slot_71(struct StateT * v6779);
struct StateT * slot_51(struct StateT * v5010);
struct StateT * slot_52(struct StateT * v5025);
struct StateT * slot_83(struct StateT * v7946);
struct StateT * slot_25(struct StateT * v2917);
struct StateT * slot_23(struct StateT * v2887);
struct StateT * slot_2(struct StateT * v409);
struct StateT * slot_21(struct StateT * v2564);
struct StateT * slot_3(struct StateT * v613);
struct StateT * slot_45(struct StateT * v4426);
struct StateT * slot_73(struct StateT * v6822);
struct StateT * slot_1(struct StateT * v205);
struct StateT * slot_69(struct StateT * v6749);
struct StateT * slot_13(struct StateT * v1455);
struct StateT * slot_38(struct StateT * v3827);
struct StateT * slot_63(struct StateT * v6158);
struct StateT * slot_24(struct StateT * v2895);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_42(struct StateT * v4361);
struct StateT * slot_46(struct StateT * v4434);
struct StateT * slot_20(struct StateT * v2536);
struct StateT * slot_61(struct StateT * v5835);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_79(struct StateT * v7406);
struct StateT * slot_41(struct StateT * v4353);
struct StateT * slot_39(struct StateT * v3835);
struct StateT * slot_8(struct StateT * v892);
struct StateT * slot_30(struct StateT * v3193);
struct StateT * slot_60(struct StateT * v5632);
struct StateT * slot_4(struct StateT * v816);
struct StateT * slot_18(struct StateT * v2017);
struct StateT * slot_9(struct StateT * v908);
struct StateT * slot_11(struct StateT * v936);
struct StateT * slot_12(struct StateT * v1140) {
  int v1141 = v1140->timer;
  int v1311 = v1141 + 1;
  v1140->timer = v1311;
  int * v1143 = v1140->regs;
  int v1144 = v1143[10];
  int v1145 = v1143[15];
  int * v1146 = v1140->cache_tags;
  int v1316 = (((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1)) & 1) * 2;
  int v1147 = v1146[v1316];
  int v1317 = ((((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1148 = v1146[v1317];
  int v1318 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1)) & 3) * 2);
  int v1149 = v1146[v1318];
  int v1319 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1150 = v1146[v1319];
  int v1151 = v1140->timer;
  int v1320 = v1151 + ((100 ^ (((~(((v1149 ^ ((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1))) | (-(v1149 ^ ((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1))))) >> 31)) | (~(((v1150 ^ ((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1))) | (-(v1150 ^ ((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1147 ^ ((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1))) | (-(v1147 ^ ((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1))))) >> 31)) | (~(((v1148 ^ ((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1))) | (-(v1148 ^ ((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1149 ^ ((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1))) | (-(v1149 ^ ((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1))))) >> 31)) | (~(((v1150 ^ ((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1))) | (-(v1150 ^ ((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1140->timer = v1320;
  bool v1321 = !(((~(((v1147 ^ ((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1))) | (-(v1147 ^ ((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1))))) >> 31)) | (~(((v1148 ^ ((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1))) | (-(v1148 ^ ((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1))))) >> 31))) == 0);
  int v1245;
  if (v1321) {
    int * v1153 = v1140->cache_age;
    int v1323 = ((((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1)) & 1) * 2) + ((~(((v1148 ^ ((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1))) | (-(v1148 ^ ((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1))))) >> 31)) & 1);
    int v1154 = v1153[v1323];
    int v1155 = v1153[v1316];
    int v1324 = v1155 + ((int)((unsigned int)(v1155 - v1154) >> 31));
    v1153[v1316] = v1324;
    int * v1157 = v1140->cache_age;
    int v1158 = v1157[v1317];
    int v1326 = v1158 + ((int)((unsigned int)(v1158 - v1154) >> 31));
    v1157[v1317] = v1326;
    int * v1160 = v1140->cache_age;
    v1160[v1323] = 0;
    v1245 = v1323;
  } else {
    int * v1163 = v1140->cache_age;
    int v1330 = (((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1)) & 1) * 2;
    int v1164 = v1163[v1330];
    int * v1165 = v1140->cache_tags;
    int v1166 = v1165[v1330];
    int v1167 = v1163[v1317];
    int v1168 = v1165[v1317];
    bool v1332 = !(((~(((v1149 ^ ((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1))) | (-(v1149 ^ ((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1))))) >> 31)) | (~(((v1150 ^ ((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1))) | (-(v1150 ^ ((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1))))) >> 31))) == 0);
    int v1222;
    if (v1332) {
      int * v1169 = v1140->cache_age;
      int v1334 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1150 ^ ((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1))) | (-(v1150 ^ ((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1))))) >> 31)) & 1);
      int v1170 = v1169[v1334];
      int v1171 = v1169[v1318];
      int v1335 = v1171 + ((int)((unsigned int)(v1171 - v1170) >> 31));
      v1169[v1318] = v1335;
      int * v1173 = v1140->cache_age;
      int v1174 = v1173[v1319];
      int v1337 = v1174 + ((int)((unsigned int)(v1174 - v1170) >> 31));
      v1173[v1319] = v1337;
      int * v1176 = v1140->cache_age;
      v1176[v1334] = 0;
      v1222 = v1334;
    } else {
      int * v1179 = v1140->cache_age;
      int v1341 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1)) & 3) * 2);
      int v1180 = v1179[v1341];
      int * v1181 = v1140->cache_tags;
      int v1182 = v1181[v1341];
      int v1183 = v1179[v1319];
      int v1184 = v1181[v1319];
      int * v1185 = v1140->cache_dirty;
      int v1344 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1)) & 3) * 2)) + ((((v1180 + ((~(((v1182 ^ -1) | (-(v1182 ^ -1))) >> 31)) & 2)) - (v1183 + ((~(((v1184 ^ -1) | (-(v1184 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1186 = v1185[v1344];
      bool v1345 = !(v1186 == 0);
      if (v1345) {
        int * v1187 = v1140->cache_tags;
        int v1188 = v1187[v1344];
        int * v1189 = v1140->cache_vals;
        int v1348 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1)) & 3) * 2)) + ((((v1180 + ((~(((v1182 ^ -1) | (-(v1182 ^ -1))) >> 31)) & 2)) - (v1183 + ((~(((v1184 ^ -1) | (-(v1184 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1190 = v1189[v1348];
        int v1349 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1)) & 3) * 2)) + ((((v1180 + ((~(((v1182 ^ -1) | (-(v1182 ^ -1))) >> 31)) & 2)) - (v1183 + ((~(((v1184 ^ -1) | (-(v1184 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1191 = v1189[v1349];
        int * v1192 = v1140->mem;
        int v1351 = v1188 * 2;
        v1192[v1351] = v1190;
        int * v1194 = v1140->mem;
        int v1354 = (v1188 * 2) + 1;
        v1194[v1354] = v1191;
        ;
      } else {
        ;
      }
      int * v1199 = v1140->mem;
      int v1359 = ((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1)) * 2;
      int v1200 = v1199[v1359];
      int v1360 = (((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1)) * 2) + 1;
      int v1201 = v1199[v1360];
      int * v1202 = v1140->cache_vals;
      int v1362 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1)) & 3) * 2)) + ((((v1180 + ((~(((v1182 ^ -1) | (-(v1182 ^ -1))) >> 31)) & 2)) - (v1183 + ((~(((v1184 ^ -1) | (-(v1184 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1202[v1362] = v1200;
      int * v1204 = v1140->cache_vals;
      int v1365 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1)) & 3) * 2)) + ((((v1180 + ((~(((v1182 ^ -1) | (-(v1182 ^ -1))) >> 31)) & 2)) - (v1183 + ((~(((v1184 ^ -1) | (-(v1184 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1204[v1365] = v1201;
      int * v1206 = v1140->cache_tags;
      int v1368 = (int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1);
      v1206[v1344] = v1368;
      int * v1208 = v1140->cache_dirty;
      v1208[v1344] = 0;
      int * v1210 = v1140->cache_age;
      v1210[v1344] = 1;
      int * v1212 = v1140->cache_age;
      int v1213 = v1212[v1344];
      int v1214 = v1212[v1318];
      int v1374 = v1214 + ((int)((unsigned int)(v1214 - v1213) >> 31));
      v1212[v1318] = v1374;
      int * v1216 = v1140->cache_age;
      int v1217 = v1216[v1319];
      int v1376 = v1217 + ((int)((unsigned int)(v1217 - v1213) >> 31));
      v1216[v1319] = v1376;
      int * v1219 = v1140->cache_age;
      v1219[v1344] = 0;
      v1222 = v1344;
    }
    int * v1223 = v1140->cache_vals;
    int v1379 = v1222 * 2;
    int v1224 = v1223[v1379];
    int v1380 = (v1222 * 2) + 1;
    int v1225 = v1223[v1380];
    int v1381 = (((((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1)) & 1) * 2) + ((((v1164 + ((~(((v1166 ^ -1) | (-(v1166 ^ -1))) >> 31)) & 2)) - (v1167 + ((~(((v1168 ^ -1) | (-(v1168 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1223[v1381] = v1224;
    int * v1227 = v1140->cache_vals;
    int v1384 = ((((((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1)) & 1) * 2) + ((((v1164 + ((~(((v1166 ^ -1) | (-(v1166 ^ -1))) >> 31)) & 2)) - (v1167 + ((~(((v1168 ^ -1) | (-(v1168 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1227[v1384] = v1225;
    int * v1229 = v1140->cache_tags;
    int v1387 = ((((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1)) & 1) * 2) + ((((v1164 + ((~(((v1166 ^ -1) | (-(v1166 ^ -1))) >> 31)) & 2)) - (v1167 + ((~(((v1168 ^ -1) | (-(v1168 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1388 = (int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1);
    v1229[v1387] = v1388;
    int * v1231 = v1140->cache_dirty;
    v1231[v1387] = 0;
    int * v1233 = v1140->cache_age;
    v1233[v1387] = 1;
    int * v1235 = v1140->cache_age;
    int v1236 = v1235[v1387];
    int v1237 = v1235[v1316];
    int v1394 = v1237 + ((int)((unsigned int)(v1237 - v1236) >> 31));
    v1235[v1316] = v1394;
    int * v1239 = v1140->cache_age;
    int v1240 = v1239[v1317];
    int v1396 = v1240 + ((int)((unsigned int)(v1240 - v1236) >> 31));
    v1239[v1317] = v1396;
    int * v1242 = v1140->cache_age;
    v1242[v1387] = 0;
    v1245 = v1387;
  }
  int * v1246 = v1140->cache_vals;
  int v1399 = (v1245 * 2) + (((int)((unsigned int)v1144 >> 2)) & 1);
  v1246[v1399] = v1145;
  int * v1248 = v1140->cache_tags;
  int v1249 = v1248[v1318];
  int v1250 = v1248[v1319];
  bool v1402 = !(((~(((v1249 ^ ((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1))) | (-(v1249 ^ ((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1))))) >> 31)) | (~(((v1250 ^ ((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1))) | (-(v1250 ^ ((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1))))) >> 31))) == 0);
  int v1304;
  if (v1402) {
    int * v1251 = v1140->cache_age;
    int v1404 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1250 ^ ((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1))) | (-(v1250 ^ ((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1))))) >> 31)) & 1);
    int v1252 = v1251[v1404];
    int v1253 = v1251[v1318];
    int v1405 = v1253 + ((int)((unsigned int)(v1253 - v1252) >> 31));
    v1251[v1318] = v1405;
    int * v1255 = v1140->cache_age;
    int v1256 = v1255[v1319];
    int v1407 = v1256 + ((int)((unsigned int)(v1256 - v1252) >> 31));
    v1255[v1319] = v1407;
    int * v1258 = v1140->cache_age;
    v1258[v1404] = 0;
    v1304 = v1404;
  } else {
    int * v1261 = v1140->cache_age;
    int v1411 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1)) & 3) * 2);
    int v1262 = v1261[v1411];
    int * v1263 = v1140->cache_tags;
    int v1264 = v1263[v1411];
    int v1265 = v1261[v1319];
    int v1266 = v1263[v1319];
    int * v1267 = v1140->cache_dirty;
    int v1414 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1)) & 3) * 2)) + ((((v1262 + ((~(((v1264 ^ -1) | (-(v1264 ^ -1))) >> 31)) & 2)) - (v1265 + ((~(((v1266 ^ -1) | (-(v1266 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1268 = v1267[v1414];
    bool v1415 = !(v1268 == 0);
    if (v1415) {
      int * v1269 = v1140->cache_tags;
      int v1270 = v1269[v1414];
      int * v1271 = v1140->cache_vals;
      int v1418 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1)) & 3) * 2)) + ((((v1262 + ((~(((v1264 ^ -1) | (-(v1264 ^ -1))) >> 31)) & 2)) - (v1265 + ((~(((v1266 ^ -1) | (-(v1266 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1272 = v1271[v1418];
      int v1419 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1)) & 3) * 2)) + ((((v1262 + ((~(((v1264 ^ -1) | (-(v1264 ^ -1))) >> 31)) & 2)) - (v1265 + ((~(((v1266 ^ -1) | (-(v1266 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1273 = v1271[v1419];
      int * v1274 = v1140->mem;
      int v1421 = v1270 * 2;
      v1274[v1421] = v1272;
      int * v1276 = v1140->mem;
      int v1424 = (v1270 * 2) + 1;
      v1276[v1424] = v1273;
      ;
    } else {
      ;
    }
    int * v1281 = v1140->mem;
    int v1429 = ((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1)) * 2;
    int v1282 = v1281[v1429];
    int v1430 = (((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1)) * 2) + 1;
    int v1283 = v1281[v1430];
    int * v1284 = v1140->cache_vals;
    int v1432 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1)) & 3) * 2)) + ((((v1262 + ((~(((v1264 ^ -1) | (-(v1264 ^ -1))) >> 31)) & 2)) - (v1265 + ((~(((v1266 ^ -1) | (-(v1266 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1284[v1432] = v1282;
    int * v1286 = v1140->cache_vals;
    int v1435 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1)) & 3) * 2)) + ((((v1262 + ((~(((v1264 ^ -1) | (-(v1264 ^ -1))) >> 31)) & 2)) - (v1265 + ((~(((v1266 ^ -1) | (-(v1266 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1286[v1435] = v1283;
    int * v1288 = v1140->cache_tags;
    int v1438 = (int)((unsigned int)((int)((unsigned int)v1144 >> 2)) >> 1);
    v1288[v1414] = v1438;
    int * v1290 = v1140->cache_dirty;
    v1290[v1414] = 0;
    int * v1292 = v1140->cache_age;
    v1292[v1414] = 1;
    int * v1294 = v1140->cache_age;
    int v1295 = v1294[v1414];
    int v1296 = v1294[v1318];
    int v1444 = v1296 + ((int)((unsigned int)(v1296 - v1295) >> 31));
    v1294[v1318] = v1444;
    int * v1298 = v1140->cache_age;
    int v1299 = v1298[v1319];
    int v1446 = v1299 + ((int)((unsigned int)(v1299 - v1295) >> 31));
    v1298[v1319] = v1446;
    int * v1301 = v1140->cache_age;
    v1301[v1414] = 0;
    v1304 = v1414;
  }
  int * v1305 = v1140->cache_vals;
  int v1449 = (v1304 * 2) + (((int)((unsigned int)v1144 >> 2)) & 1);
  v1305[v1449] = v1145;
  int * v1307 = v1140->cache_dirty;
  v1307[v1304] = 1;
  struct StateT * v1309 = slot_14(v1140);
  return v1309;
}

struct StateT * slot_43(struct StateT * v4383) {
  int * v4384 = v4383->regs;
  int v4385 = v4384[12];
  bool v4400 = !(v4385 == 0);
  struct StateT * v4396;
  if (v4400) {
    int v4386 = v4383->timer;
    int v4401 = v4386 + 15;
    v4383->timer = v4401;
    int * v4388 = v4383->saved_regs;
    int v4389 = v4388[13];
    int * v4390 = v4383->regs;
    v4390[13] = v4389;
    struct StateT * v4392 = slot_44(v4383);
    v4396 = v4392;
  } else {
    struct StateT * v4394 = slot_45(v4383);
    v4396 = v4394;
  }
  return v4396;
}

struct StateT * slot_70(struct StateT * v6757) {
  int * v6758 = v6757->saved_regs;
  int * v6759 = v6757->regs;
  int v6760 = v6759[13];
  v6758[13] = v6760;
  int v6762 = v6757->timer;
  int v6773 = v6762 + 1;
  v6757->timer = v6773;
  int * v6764 = v6757->regs;
  int v6765 = v6764[10];
  int v6776 = v6765 + 32;
  v6764[13] = v6776;
  struct StateT * v6767 = slot_71(v6757);
  return v6767;
}

struct StateT * slot_76(struct StateT * v7348) {
  int v7349 = v7348->timer;
  int v7353 = v7349 + 1;
  v7348->timer = v7353;
  struct StateT * v7351 = slot_77(v7348);
  return v7351;
}

struct StateT * slot_6(struct StateT * v848) {
  int v849 = v848->timer;
  int v860 = v849 + 1;
  v848->timer = v860;
  int * v851 = v848->regs;
  int v852 = v851[12];
  bool v863 = -2147483648 < (v852 ^ -2147483648);
  int v855;
  if (v863) {
    v855 = 1;
  } else {
    v855 = 0;
  }
  int * v856 = v848->regs;
  v856[12] = v855;
  struct StateT * v858 = slot_7(v848);
  return v858;
}

struct StateT * slot_47(struct StateT * v4637) {
  int v4638 = v4637->timer;
  int v4808 = v4638 + 1;
  v4637->timer = v4808;
  int * v4640 = v4637->regs;
  int v4641 = v4640[10];
  int v4642 = v4640[13];
  int * v4643 = v4637->cache_tags;
  int v4813 = (((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1)) & 1) * 2;
  int v4644 = v4643[v4813];
  int v4814 = ((((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4645 = v4643[v4814];
  int v4815 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1)) & 3) * 2);
  int v4646 = v4643[v4815];
  int v4816 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4647 = v4643[v4816];
  int v4648 = v4637->timer;
  int v4817 = v4648 + ((100 ^ (((~(((v4646 ^ ((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1))) | (-(v4646 ^ ((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v4647 ^ ((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1))) | (-(v4647 ^ ((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4644 ^ ((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1))) | (-(v4644 ^ ((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v4645 ^ ((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1))) | (-(v4645 ^ ((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4646 ^ ((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1))) | (-(v4646 ^ ((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v4647 ^ ((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1))) | (-(v4647 ^ ((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4637->timer = v4817;
  bool v4818 = !(((~(((v4644 ^ ((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1))) | (-(v4644 ^ ((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v4645 ^ ((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1))) | (-(v4645 ^ ((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v4742;
  if (v4818) {
    int * v4650 = v4637->cache_age;
    int v4820 = ((((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v4645 ^ ((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1))) | (-(v4645 ^ ((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v4651 = v4650[v4820];
    int v4652 = v4650[v4813];
    int v4821 = v4652 + ((int)((unsigned int)(v4652 - v4651) >> 31));
    v4650[v4813] = v4821;
    int * v4654 = v4637->cache_age;
    int v4655 = v4654[v4814];
    int v4823 = v4655 + ((int)((unsigned int)(v4655 - v4651) >> 31));
    v4654[v4814] = v4823;
    int * v4657 = v4637->cache_age;
    v4657[v4820] = 0;
    v4742 = v4820;
  } else {
    int * v4660 = v4637->cache_age;
    int v4827 = (((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1)) & 1) * 2;
    int v4661 = v4660[v4827];
    int * v4662 = v4637->cache_tags;
    int v4663 = v4662[v4827];
    int v4664 = v4660[v4814];
    int v4665 = v4662[v4814];
    bool v4829 = !(((~(((v4646 ^ ((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1))) | (-(v4646 ^ ((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v4647 ^ ((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1))) | (-(v4647 ^ ((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v4719;
    if (v4829) {
      int * v4666 = v4637->cache_age;
      int v4831 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4647 ^ ((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1))) | (-(v4647 ^ ((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v4667 = v4666[v4831];
      int v4668 = v4666[v4815];
      int v4832 = v4668 + ((int)((unsigned int)(v4668 - v4667) >> 31));
      v4666[v4815] = v4832;
      int * v4670 = v4637->cache_age;
      int v4671 = v4670[v4816];
      int v4834 = v4671 + ((int)((unsigned int)(v4671 - v4667) >> 31));
      v4670[v4816] = v4834;
      int * v4673 = v4637->cache_age;
      v4673[v4831] = 0;
      v4719 = v4831;
    } else {
      int * v4676 = v4637->cache_age;
      int v4838 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1)) & 3) * 2);
      int v4677 = v4676[v4838];
      int * v4678 = v4637->cache_tags;
      int v4679 = v4678[v4838];
      int v4680 = v4676[v4816];
      int v4681 = v4678[v4816];
      int * v4682 = v4637->cache_dirty;
      int v4841 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4677 + ((~(((v4679 ^ -1) | (-(v4679 ^ -1))) >> 31)) & 2)) - (v4680 + ((~(((v4681 ^ -1) | (-(v4681 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4683 = v4682[v4841];
      bool v4842 = !(v4683 == 0);
      if (v4842) {
        int * v4684 = v4637->cache_tags;
        int v4685 = v4684[v4841];
        int * v4686 = v4637->cache_vals;
        int v4845 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4677 + ((~(((v4679 ^ -1) | (-(v4679 ^ -1))) >> 31)) & 2)) - (v4680 + ((~(((v4681 ^ -1) | (-(v4681 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4687 = v4686[v4845];
        int v4846 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4677 + ((~(((v4679 ^ -1) | (-(v4679 ^ -1))) >> 31)) & 2)) - (v4680 + ((~(((v4681 ^ -1) | (-(v4681 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4688 = v4686[v4846];
        int * v4689 = v4637->mem;
        int v4848 = v4685 * 2;
        v4689[v4848] = v4687;
        int * v4691 = v4637->mem;
        int v4851 = (v4685 * 2) + 1;
        v4691[v4851] = v4688;
        ;
      } else {
        ;
      }
      int * v4696 = v4637->mem;
      int v4856 = ((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1)) * 2;
      int v4697 = v4696[v4856];
      int v4857 = (((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1)) * 2) + 1;
      int v4698 = v4696[v4857];
      int * v4699 = v4637->cache_vals;
      int v4859 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4677 + ((~(((v4679 ^ -1) | (-(v4679 ^ -1))) >> 31)) & 2)) - (v4680 + ((~(((v4681 ^ -1) | (-(v4681 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4699[v4859] = v4697;
      int * v4701 = v4637->cache_vals;
      int v4862 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4677 + ((~(((v4679 ^ -1) | (-(v4679 ^ -1))) >> 31)) & 2)) - (v4680 + ((~(((v4681 ^ -1) | (-(v4681 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4701[v4862] = v4698;
      int * v4703 = v4637->cache_tags;
      int v4865 = (int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1);
      v4703[v4841] = v4865;
      int * v4705 = v4637->cache_dirty;
      v4705[v4841] = 0;
      int * v4707 = v4637->cache_age;
      v4707[v4841] = 1;
      int * v4709 = v4637->cache_age;
      int v4710 = v4709[v4841];
      int v4711 = v4709[v4815];
      int v4871 = v4711 + ((int)((unsigned int)(v4711 - v4710) >> 31));
      v4709[v4815] = v4871;
      int * v4713 = v4637->cache_age;
      int v4714 = v4713[v4816];
      int v4873 = v4714 + ((int)((unsigned int)(v4714 - v4710) >> 31));
      v4713[v4816] = v4873;
      int * v4716 = v4637->cache_age;
      v4716[v4841] = 0;
      v4719 = v4841;
    }
    int * v4720 = v4637->cache_vals;
    int v4876 = v4719 * 2;
    int v4721 = v4720[v4876];
    int v4877 = (v4719 * 2) + 1;
    int v4722 = v4720[v4877];
    int v4878 = (((((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v4661 + ((~(((v4663 ^ -1) | (-(v4663 ^ -1))) >> 31)) & 2)) - (v4664 + ((~(((v4665 ^ -1) | (-(v4665 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4720[v4878] = v4721;
    int * v4724 = v4637->cache_vals;
    int v4881 = ((((((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v4661 + ((~(((v4663 ^ -1) | (-(v4663 ^ -1))) >> 31)) & 2)) - (v4664 + ((~(((v4665 ^ -1) | (-(v4665 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4724[v4881] = v4722;
    int * v4726 = v4637->cache_tags;
    int v4884 = ((((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v4661 + ((~(((v4663 ^ -1) | (-(v4663 ^ -1))) >> 31)) & 2)) - (v4664 + ((~(((v4665 ^ -1) | (-(v4665 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4885 = (int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1);
    v4726[v4884] = v4885;
    int * v4728 = v4637->cache_dirty;
    v4728[v4884] = 0;
    int * v4730 = v4637->cache_age;
    v4730[v4884] = 1;
    int * v4732 = v4637->cache_age;
    int v4733 = v4732[v4884];
    int v4734 = v4732[v4813];
    int v4891 = v4734 + ((int)((unsigned int)(v4734 - v4733) >> 31));
    v4732[v4813] = v4891;
    int * v4736 = v4637->cache_age;
    int v4737 = v4736[v4814];
    int v4893 = v4737 + ((int)((unsigned int)(v4737 - v4733) >> 31));
    v4736[v4814] = v4893;
    int * v4739 = v4637->cache_age;
    v4739[v4884] = 0;
    v4742 = v4884;
  }
  int * v4743 = v4637->cache_vals;
  int v4896 = (v4742 * 2) + (((int)((unsigned int)(v4641 + 16) >> 2)) & 1);
  v4743[v4896] = v4642;
  int * v4745 = v4637->cache_tags;
  int v4746 = v4745[v4815];
  int v4747 = v4745[v4816];
  bool v4899 = !(((~(((v4746 ^ ((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1))) | (-(v4746 ^ ((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v4747 ^ ((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1))) | (-(v4747 ^ ((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v4801;
  if (v4899) {
    int * v4748 = v4637->cache_age;
    int v4901 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4747 ^ ((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1))) | (-(v4747 ^ ((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v4749 = v4748[v4901];
    int v4750 = v4748[v4815];
    int v4902 = v4750 + ((int)((unsigned int)(v4750 - v4749) >> 31));
    v4748[v4815] = v4902;
    int * v4752 = v4637->cache_age;
    int v4753 = v4752[v4816];
    int v4904 = v4753 + ((int)((unsigned int)(v4753 - v4749) >> 31));
    v4752[v4816] = v4904;
    int * v4755 = v4637->cache_age;
    v4755[v4901] = 0;
    v4801 = v4901;
  } else {
    int * v4758 = v4637->cache_age;
    int v4908 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1)) & 3) * 2);
    int v4759 = v4758[v4908];
    int * v4760 = v4637->cache_tags;
    int v4761 = v4760[v4908];
    int v4762 = v4758[v4816];
    int v4763 = v4760[v4816];
    int * v4764 = v4637->cache_dirty;
    int v4911 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4759 + ((~(((v4761 ^ -1) | (-(v4761 ^ -1))) >> 31)) & 2)) - (v4762 + ((~(((v4763 ^ -1) | (-(v4763 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4765 = v4764[v4911];
    bool v4912 = !(v4765 == 0);
    if (v4912) {
      int * v4766 = v4637->cache_tags;
      int v4767 = v4766[v4911];
      int * v4768 = v4637->cache_vals;
      int v4915 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4759 + ((~(((v4761 ^ -1) | (-(v4761 ^ -1))) >> 31)) & 2)) - (v4762 + ((~(((v4763 ^ -1) | (-(v4763 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v4769 = v4768[v4915];
      int v4916 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4759 + ((~(((v4761 ^ -1) | (-(v4761 ^ -1))) >> 31)) & 2)) - (v4762 + ((~(((v4763 ^ -1) | (-(v4763 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v4770 = v4768[v4916];
      int * v4771 = v4637->mem;
      int v4918 = v4767 * 2;
      v4771[v4918] = v4769;
      int * v4773 = v4637->mem;
      int v4921 = (v4767 * 2) + 1;
      v4773[v4921] = v4770;
      ;
    } else {
      ;
    }
    int * v4778 = v4637->mem;
    int v4926 = ((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1)) * 2;
    int v4779 = v4778[v4926];
    int v4927 = (((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1)) * 2) + 1;
    int v4780 = v4778[v4927];
    int * v4781 = v4637->cache_vals;
    int v4929 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4759 + ((~(((v4761 ^ -1) | (-(v4761 ^ -1))) >> 31)) & 2)) - (v4762 + ((~(((v4763 ^ -1) | (-(v4763 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4781[v4929] = v4779;
    int * v4783 = v4637->cache_vals;
    int v4932 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4759 + ((~(((v4761 ^ -1) | (-(v4761 ^ -1))) >> 31)) & 2)) - (v4762 + ((~(((v4763 ^ -1) | (-(v4763 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4783[v4932] = v4780;
    int * v4785 = v4637->cache_tags;
    int v4935 = (int)((unsigned int)((int)((unsigned int)(v4641 + 16) >> 2)) >> 1);
    v4785[v4911] = v4935;
    int * v4787 = v4637->cache_dirty;
    v4787[v4911] = 0;
    int * v4789 = v4637->cache_age;
    v4789[v4911] = 1;
    int * v4791 = v4637->cache_age;
    int v4792 = v4791[v4911];
    int v4793 = v4791[v4815];
    int v4941 = v4793 + ((int)((unsigned int)(v4793 - v4792) >> 31));
    v4791[v4815] = v4941;
    int * v4795 = v4637->cache_age;
    int v4796 = v4795[v4816];
    int v4943 = v4796 + ((int)((unsigned int)(v4796 - v4792) >> 31));
    v4795[v4816] = v4943;
    int * v4798 = v4637->cache_age;
    v4798[v4911] = 0;
    v4801 = v4911;
  }
  int * v4802 = v4637->cache_vals;
  int v4946 = (v4801 * 2) + (((int)((unsigned int)(v4641 + 16) >> 2)) & 1);
  v4802[v4946] = v4642;
  int * v4804 = v4637->cache_dirty;
  v4804[v4801] = 1;
  struct StateT * v4806 = slot_48(v4637);
  return v4806;
}

struct StateT * slot_29(struct StateT * v3185) {
  int v3186 = v3185->timer;
  int v3190 = v3186 + 1;
  v3185->timer = v3190;
  struct StateT * v3188 = slot_31(v3185);
  return v3188;
}

struct StateT * slot_55(struct StateT * v5551) {
  int v5552 = v5551->timer;
  int v5556 = v5552 + 1;
  v5551->timer = v5556;
  struct StateT * v5554 = slot_56(v5551);
  return v5554;
}

struct StateT * slot_16(struct StateT * v1786) {
  int * v1787 = v1786->regs;
  int v1788 = v1787[12];
  bool v1799 = !(v1788 == 0);
  struct StateT * v1795;
  if (v1799) {
    int v1789 = v1786->timer;
    int v1800 = v1789 + 15;
    v1786->timer = v1800;
    struct StateT * v1791 = slot_18(v1786);
    v1795 = v1791;
  } else {
    struct StateT * v1793 = slot_19(v1786);
    v1795 = v1793;
  }
  return v1795;
}

struct StateT * slot_5(struct StateT * v832) {
  int v833 = v832->timer;
  int v841 = v833 + 1;
  v832->timer = v841;
  int * v835 = v832->regs;
  int v836 = v835[14];
  int v837 = v835[13];
  int v845 = v836 ^ v837;
  v835[13] = v845;
  struct StateT * v839 = slot_6(v832);
  return v839;
}

struct StateT * slot_7(struct StateT * v870) {
  int v871 = v870->timer;
  int v882 = v871 + 1;
  v870->timer = v882;
  int * v873 = v870->regs;
  int v874 = v873[13];
  bool v885 = -2147483648 < (v874 ^ -2147483648);
  int v877;
  if (v885) {
    v877 = 1;
  } else {
    v877 = 0;
  }
  int * v878 = v870->regs;
  v878[13] = v877;
  struct StateT * v880 = slot_8(v870);
  return v880;
}

struct StateT * slot_31(struct StateT * v3221) {
  int v3222 = v3221->timer;
  int v3332 = v3222 + 1;
  v3221->timer = v3332;
  int * v3224 = v3221->regs;
  int v3225 = v3224[13];
  int * v3226 = v3221->cache_tags;
  int v3336 = (((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1)) & 1) * 2;
  int v3227 = v3226[v3336];
  int v3337 = ((((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1)) & 1) * 2) + 1;
  int v3228 = v3226[v3337];
  int v3338 = 4 + ((((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1)) & 3) * 2);
  int v3229 = v3226[v3338];
  int v3339 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3230 = v3226[v3339];
  int v3231 = v3221->timer;
  int v3340 = v3231 + ((100 ^ (((~(((v3229 ^ ((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1))) | (-(v3229 ^ ((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1))))) >> 31)) | (~(((v3230 ^ ((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1))) | (-(v3230 ^ ((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3227 ^ ((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1))) | (-(v3227 ^ ((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1))))) >> 31)) | (~(((v3228 ^ ((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1))) | (-(v3228 ^ ((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3229 ^ ((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1))) | (-(v3229 ^ ((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1))))) >> 31)) | (~(((v3230 ^ ((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1))) | (-(v3230 ^ ((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1))))) >> 31))) & 104)))));
  v3221->timer = v3340;
  int * v3233 = v3221->cache_vals;
  bool v3341 = !(((~(((v3227 ^ ((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1))) | (-(v3227 ^ ((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1))))) >> 31)) | (~(((v3228 ^ ((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1))) | (-(v3228 ^ ((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1))))) >> 31))) == 0);
  int v3326;
  if (v3341) {
    int * v3234 = v3221->cache_age;
    int v3343 = ((((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1)) & 1) * 2) + ((~(((v3228 ^ ((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1))) | (-(v3228 ^ ((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1))))) >> 31)) & 1);
    int v3235 = v3234[v3343];
    int v3236 = v3234[v3336];
    int v3344 = v3236 + ((int)((unsigned int)(v3236 - v3235) >> 31));
    v3234[v3336] = v3344;
    int * v3238 = v3221->cache_age;
    int v3239 = v3238[v3337];
    int v3346 = v3239 + ((int)((unsigned int)(v3239 - v3235) >> 31));
    v3238[v3337] = v3346;
    int * v3241 = v3221->cache_age;
    v3241[v3343] = 0;
    v3326 = v3343;
  } else {
    int * v3244 = v3221->cache_age;
    int v3350 = (((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1)) & 1) * 2;
    int v3245 = v3244[v3350];
    int * v3246 = v3221->cache_tags;
    int v3247 = v3246[v3350];
    int v3248 = v3244[v3337];
    int v3249 = v3246[v3337];
    bool v3352 = !(((~(((v3229 ^ ((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1))) | (-(v3229 ^ ((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1))))) >> 31)) | (~(((v3230 ^ ((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1))) | (-(v3230 ^ ((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1))))) >> 31))) == 0);
    int v3303;
    if (v3352) {
      int * v3250 = v3221->cache_age;
      int v3354 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1)) & 3) * 2)) + ((~(((v3230 ^ ((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1))) | (-(v3230 ^ ((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1))))) >> 31)) & 1);
      int v3251 = v3250[v3354];
      int v3252 = v3250[v3338];
      int v3355 = v3252 + ((int)((unsigned int)(v3252 - v3251) >> 31));
      v3250[v3338] = v3355;
      int * v3254 = v3221->cache_age;
      int v3255 = v3254[v3339];
      int v3357 = v3255 + ((int)((unsigned int)(v3255 - v3251) >> 31));
      v3254[v3339] = v3357;
      int * v3257 = v3221->cache_age;
      v3257[v3354] = 0;
      v3303 = v3354;
    } else {
      int * v3260 = v3221->cache_age;
      int v3361 = 4 + ((((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1)) & 3) * 2);
      int v3261 = v3260[v3361];
      int * v3262 = v3221->cache_tags;
      int v3263 = v3262[v3361];
      int v3264 = v3260[v3339];
      int v3265 = v3262[v3339];
      int * v3266 = v3221->cache_dirty;
      int v3364 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1)) & 3) * 2)) + ((((v3261 + ((~(((v3263 ^ -1) | (-(v3263 ^ -1))) >> 31)) & 2)) - (v3264 + ((~(((v3265 ^ -1) | (-(v3265 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3267 = v3266[v3364];
      bool v3365 = !(v3267 == 0);
      if (v3365) {
        int * v3268 = v3221->cache_tags;
        int v3269 = v3268[v3364];
        int * v3270 = v3221->cache_vals;
        int v3368 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1)) & 3) * 2)) + ((((v3261 + ((~(((v3263 ^ -1) | (-(v3263 ^ -1))) >> 31)) & 2)) - (v3264 + ((~(((v3265 ^ -1) | (-(v3265 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3271 = v3270[v3368];
        int v3369 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1)) & 3) * 2)) + ((((v3261 + ((~(((v3263 ^ -1) | (-(v3263 ^ -1))) >> 31)) & 2)) - (v3264 + ((~(((v3265 ^ -1) | (-(v3265 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3272 = v3270[v3369];
        int * v3273 = v3221->mem;
        int v3371 = v3269 * 2;
        v3273[v3371] = v3271;
        int * v3275 = v3221->mem;
        int v3374 = (v3269 * 2) + 1;
        v3275[v3374] = v3272;
        ;
      } else {
        ;
      }
      int * v3280 = v3221->mem;
      int v3379 = ((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1)) * 2;
      int v3281 = v3280[v3379];
      int v3380 = (((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1)) * 2) + 1;
      int v3282 = v3280[v3380];
      int * v3283 = v3221->cache_vals;
      int v3382 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1)) & 3) * 2)) + ((((v3261 + ((~(((v3263 ^ -1) | (-(v3263 ^ -1))) >> 31)) & 2)) - (v3264 + ((~(((v3265 ^ -1) | (-(v3265 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3283[v3382] = v3281;
      int * v3285 = v3221->cache_vals;
      int v3385 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1)) & 3) * 2)) + ((((v3261 + ((~(((v3263 ^ -1) | (-(v3263 ^ -1))) >> 31)) & 2)) - (v3264 + ((~(((v3265 ^ -1) | (-(v3265 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3285[v3385] = v3282;
      int * v3287 = v3221->cache_tags;
      int v3388 = (int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1);
      v3287[v3364] = v3388;
      int * v3289 = v3221->cache_dirty;
      v3289[v3364] = 0;
      int * v3291 = v3221->cache_age;
      v3291[v3364] = 1;
      int * v3293 = v3221->cache_age;
      int v3294 = v3293[v3364];
      int v3295 = v3293[v3338];
      int v3394 = v3295 + ((int)((unsigned int)(v3295 - v3294) >> 31));
      v3293[v3338] = v3394;
      int * v3297 = v3221->cache_age;
      int v3298 = v3297[v3339];
      int v3396 = v3298 + ((int)((unsigned int)(v3298 - v3294) >> 31));
      v3297[v3339] = v3396;
      int * v3300 = v3221->cache_age;
      v3300[v3364] = 0;
      v3303 = v3364;
    }
    int * v3304 = v3221->cache_vals;
    int v3399 = v3303 * 2;
    int v3305 = v3304[v3399];
    int v3400 = (v3303 * 2) + 1;
    int v3306 = v3304[v3400];
    int v3401 = (((((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1)) & 1) * 2) + ((((v3245 + ((~(((v3247 ^ -1) | (-(v3247 ^ -1))) >> 31)) & 2)) - (v3248 + ((~(((v3249 ^ -1) | (-(v3249 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3304[v3401] = v3305;
    int * v3308 = v3221->cache_vals;
    int v3404 = ((((((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1)) & 1) * 2) + ((((v3245 + ((~(((v3247 ^ -1) | (-(v3247 ^ -1))) >> 31)) & 2)) - (v3248 + ((~(((v3249 ^ -1) | (-(v3249 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3308[v3404] = v3306;
    int * v3310 = v3221->cache_tags;
    int v3407 = ((((int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1)) & 1) * 2) + ((((v3245 + ((~(((v3247 ^ -1) | (-(v3247 ^ -1))) >> 31)) & 2)) - (v3248 + ((~(((v3249 ^ -1) | (-(v3249 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3408 = (int)((unsigned int)((int)((unsigned int)v3225 >> 2)) >> 1);
    v3310[v3407] = v3408;
    int * v3312 = v3221->cache_dirty;
    v3312[v3407] = 0;
    int * v3314 = v3221->cache_age;
    v3314[v3407] = 1;
    int * v3316 = v3221->cache_age;
    int v3317 = v3316[v3407];
    int v3318 = v3316[v3336];
    int v3414 = v3318 + ((int)((unsigned int)(v3318 - v3317) >> 31));
    v3316[v3336] = v3414;
    int * v3320 = v3221->cache_age;
    int v3321 = v3320[v3337];
    int v3416 = v3321 + ((int)((unsigned int)(v3321 - v3317) >> 31));
    v3320[v3337] = v3416;
    int * v3323 = v3221->cache_age;
    v3323[v3407] = 0;
    v3326 = v3407;
  }
  int v3419 = (v3326 * 2) + (((int)((unsigned int)v3225 >> 2)) & 1);
  int v3327 = v3233[v3419];
  int * v3328 = v3221->regs;
  v3328[13] = v3327;
  struct StateT * v3330 = slot_33(v3221);
  return v3330;
}

struct StateT * slot_54(struct StateT * v5236) {
  int v5237 = v5236->timer;
  int v5407 = v5237 + 1;
  v5236->timer = v5407;
  int * v5239 = v5236->regs;
  int v5240 = v5239[10];
  int v5241 = v5239[13];
  int * v5242 = v5236->cache_tags;
  int v5412 = (((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1)) & 1) * 2;
  int v5243 = v5242[v5412];
  int v5413 = ((((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1)) & 1) * 2) + 1;
  int v5244 = v5242[v5413];
  int v5414 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1)) & 3) * 2);
  int v5245 = v5242[v5414];
  int v5415 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5246 = v5242[v5415];
  int v5247 = v5236->timer;
  int v5416 = v5247 + ((100 ^ (((~(((v5245 ^ ((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1))) | (-(v5245 ^ ((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v5246 ^ ((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1))) | (-(v5246 ^ ((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5243 ^ ((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1))) | (-(v5243 ^ ((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v5244 ^ ((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1))) | (-(v5244 ^ ((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5245 ^ ((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1))) | (-(v5245 ^ ((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v5246 ^ ((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1))) | (-(v5246 ^ ((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1))))) >> 31))) & 104)))));
  v5236->timer = v5416;
  bool v5417 = !(((~(((v5243 ^ ((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1))) | (-(v5243 ^ ((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v5244 ^ ((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1))) | (-(v5244 ^ ((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v5341;
  if (v5417) {
    int * v5249 = v5236->cache_age;
    int v5419 = ((((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1)) & 1) * 2) + ((~(((v5244 ^ ((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1))) | (-(v5244 ^ ((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v5250 = v5249[v5419];
    int v5251 = v5249[v5412];
    int v5420 = v5251 + ((int)((unsigned int)(v5251 - v5250) >> 31));
    v5249[v5412] = v5420;
    int * v5253 = v5236->cache_age;
    int v5254 = v5253[v5413];
    int v5422 = v5254 + ((int)((unsigned int)(v5254 - v5250) >> 31));
    v5253[v5413] = v5422;
    int * v5256 = v5236->cache_age;
    v5256[v5419] = 0;
    v5341 = v5419;
  } else {
    int * v5259 = v5236->cache_age;
    int v5426 = (((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1)) & 1) * 2;
    int v5260 = v5259[v5426];
    int * v5261 = v5236->cache_tags;
    int v5262 = v5261[v5426];
    int v5263 = v5259[v5413];
    int v5264 = v5261[v5413];
    bool v5428 = !(((~(((v5245 ^ ((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1))) | (-(v5245 ^ ((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v5246 ^ ((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1))) | (-(v5246 ^ ((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1))))) >> 31))) == 0);
    int v5318;
    if (v5428) {
      int * v5265 = v5236->cache_age;
      int v5430 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5246 ^ ((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1))) | (-(v5246 ^ ((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1))))) >> 31)) & 1);
      int v5266 = v5265[v5430];
      int v5267 = v5265[v5414];
      int v5431 = v5267 + ((int)((unsigned int)(v5267 - v5266) >> 31));
      v5265[v5414] = v5431;
      int * v5269 = v5236->cache_age;
      int v5270 = v5269[v5415];
      int v5433 = v5270 + ((int)((unsigned int)(v5270 - v5266) >> 31));
      v5269[v5415] = v5433;
      int * v5272 = v5236->cache_age;
      v5272[v5430] = 0;
      v5318 = v5430;
    } else {
      int * v5275 = v5236->cache_age;
      int v5437 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1)) & 3) * 2);
      int v5276 = v5275[v5437];
      int * v5277 = v5236->cache_tags;
      int v5278 = v5277[v5437];
      int v5279 = v5275[v5415];
      int v5280 = v5277[v5415];
      int * v5281 = v5236->cache_dirty;
      int v5440 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5276 + ((~(((v5278 ^ -1) | (-(v5278 ^ -1))) >> 31)) & 2)) - (v5279 + ((~(((v5280 ^ -1) | (-(v5280 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5282 = v5281[v5440];
      bool v5441 = !(v5282 == 0);
      if (v5441) {
        int * v5283 = v5236->cache_tags;
        int v5284 = v5283[v5440];
        int * v5285 = v5236->cache_vals;
        int v5444 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5276 + ((~(((v5278 ^ -1) | (-(v5278 ^ -1))) >> 31)) & 2)) - (v5279 + ((~(((v5280 ^ -1) | (-(v5280 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5286 = v5285[v5444];
        int v5445 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5276 + ((~(((v5278 ^ -1) | (-(v5278 ^ -1))) >> 31)) & 2)) - (v5279 + ((~(((v5280 ^ -1) | (-(v5280 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5287 = v5285[v5445];
        int * v5288 = v5236->mem;
        int v5447 = v5284 * 2;
        v5288[v5447] = v5286;
        int * v5290 = v5236->mem;
        int v5450 = (v5284 * 2) + 1;
        v5290[v5450] = v5287;
        ;
      } else {
        ;
      }
      int * v5295 = v5236->mem;
      int v5455 = ((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1)) * 2;
      int v5296 = v5295[v5455];
      int v5456 = (((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1)) * 2) + 1;
      int v5297 = v5295[v5456];
      int * v5298 = v5236->cache_vals;
      int v5458 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5276 + ((~(((v5278 ^ -1) | (-(v5278 ^ -1))) >> 31)) & 2)) - (v5279 + ((~(((v5280 ^ -1) | (-(v5280 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5298[v5458] = v5296;
      int * v5300 = v5236->cache_vals;
      int v5461 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5276 + ((~(((v5278 ^ -1) | (-(v5278 ^ -1))) >> 31)) & 2)) - (v5279 + ((~(((v5280 ^ -1) | (-(v5280 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5300[v5461] = v5297;
      int * v5302 = v5236->cache_tags;
      int v5464 = (int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1);
      v5302[v5440] = v5464;
      int * v5304 = v5236->cache_dirty;
      v5304[v5440] = 0;
      int * v5306 = v5236->cache_age;
      v5306[v5440] = 1;
      int * v5308 = v5236->cache_age;
      int v5309 = v5308[v5440];
      int v5310 = v5308[v5414];
      int v5470 = v5310 + ((int)((unsigned int)(v5310 - v5309) >> 31));
      v5308[v5414] = v5470;
      int * v5312 = v5236->cache_age;
      int v5313 = v5312[v5415];
      int v5472 = v5313 + ((int)((unsigned int)(v5313 - v5309) >> 31));
      v5312[v5415] = v5472;
      int * v5315 = v5236->cache_age;
      v5315[v5440] = 0;
      v5318 = v5440;
    }
    int * v5319 = v5236->cache_vals;
    int v5475 = v5318 * 2;
    int v5320 = v5319[v5475];
    int v5476 = (v5318 * 2) + 1;
    int v5321 = v5319[v5476];
    int v5477 = (((((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v5260 + ((~(((v5262 ^ -1) | (-(v5262 ^ -1))) >> 31)) & 2)) - (v5263 + ((~(((v5264 ^ -1) | (-(v5264 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5319[v5477] = v5320;
    int * v5323 = v5236->cache_vals;
    int v5480 = ((((((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v5260 + ((~(((v5262 ^ -1) | (-(v5262 ^ -1))) >> 31)) & 2)) - (v5263 + ((~(((v5264 ^ -1) | (-(v5264 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5323[v5480] = v5321;
    int * v5325 = v5236->cache_tags;
    int v5483 = ((((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v5260 + ((~(((v5262 ^ -1) | (-(v5262 ^ -1))) >> 31)) & 2)) - (v5263 + ((~(((v5264 ^ -1) | (-(v5264 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5484 = (int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1);
    v5325[v5483] = v5484;
    int * v5327 = v5236->cache_dirty;
    v5327[v5483] = 0;
    int * v5329 = v5236->cache_age;
    v5329[v5483] = 1;
    int * v5331 = v5236->cache_age;
    int v5332 = v5331[v5483];
    int v5333 = v5331[v5412];
    int v5490 = v5333 + ((int)((unsigned int)(v5333 - v5332) >> 31));
    v5331[v5412] = v5490;
    int * v5335 = v5236->cache_age;
    int v5336 = v5335[v5413];
    int v5492 = v5336 + ((int)((unsigned int)(v5336 - v5332) >> 31));
    v5335[v5413] = v5492;
    int * v5338 = v5236->cache_age;
    v5338[v5483] = 0;
    v5341 = v5483;
  }
  int * v5342 = v5236->cache_vals;
  int v5495 = (v5341 * 2) + (((int)((unsigned int)(v5240 + 20) >> 2)) & 1);
  v5342[v5495] = v5241;
  int * v5344 = v5236->cache_tags;
  int v5345 = v5344[v5414];
  int v5346 = v5344[v5415];
  bool v5498 = !(((~(((v5345 ^ ((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1))) | (-(v5345 ^ ((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v5346 ^ ((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1))) | (-(v5346 ^ ((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v5400;
  if (v5498) {
    int * v5347 = v5236->cache_age;
    int v5500 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5346 ^ ((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1))) | (-(v5346 ^ ((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v5348 = v5347[v5500];
    int v5349 = v5347[v5414];
    int v5501 = v5349 + ((int)((unsigned int)(v5349 - v5348) >> 31));
    v5347[v5414] = v5501;
    int * v5351 = v5236->cache_age;
    int v5352 = v5351[v5415];
    int v5503 = v5352 + ((int)((unsigned int)(v5352 - v5348) >> 31));
    v5351[v5415] = v5503;
    int * v5354 = v5236->cache_age;
    v5354[v5500] = 0;
    v5400 = v5500;
  } else {
    int * v5357 = v5236->cache_age;
    int v5507 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1)) & 3) * 2);
    int v5358 = v5357[v5507];
    int * v5359 = v5236->cache_tags;
    int v5360 = v5359[v5507];
    int v5361 = v5357[v5415];
    int v5362 = v5359[v5415];
    int * v5363 = v5236->cache_dirty;
    int v5510 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5358 + ((~(((v5360 ^ -1) | (-(v5360 ^ -1))) >> 31)) & 2)) - (v5361 + ((~(((v5362 ^ -1) | (-(v5362 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5364 = v5363[v5510];
    bool v5511 = !(v5364 == 0);
    if (v5511) {
      int * v5365 = v5236->cache_tags;
      int v5366 = v5365[v5510];
      int * v5367 = v5236->cache_vals;
      int v5514 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5358 + ((~(((v5360 ^ -1) | (-(v5360 ^ -1))) >> 31)) & 2)) - (v5361 + ((~(((v5362 ^ -1) | (-(v5362 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v5368 = v5367[v5514];
      int v5515 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5358 + ((~(((v5360 ^ -1) | (-(v5360 ^ -1))) >> 31)) & 2)) - (v5361 + ((~(((v5362 ^ -1) | (-(v5362 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v5369 = v5367[v5515];
      int * v5370 = v5236->mem;
      int v5517 = v5366 * 2;
      v5370[v5517] = v5368;
      int * v5372 = v5236->mem;
      int v5520 = (v5366 * 2) + 1;
      v5372[v5520] = v5369;
      ;
    } else {
      ;
    }
    int * v5377 = v5236->mem;
    int v5525 = ((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1)) * 2;
    int v5378 = v5377[v5525];
    int v5526 = (((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1)) * 2) + 1;
    int v5379 = v5377[v5526];
    int * v5380 = v5236->cache_vals;
    int v5528 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5358 + ((~(((v5360 ^ -1) | (-(v5360 ^ -1))) >> 31)) & 2)) - (v5361 + ((~(((v5362 ^ -1) | (-(v5362 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5380[v5528] = v5378;
    int * v5382 = v5236->cache_vals;
    int v5531 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v5358 + ((~(((v5360 ^ -1) | (-(v5360 ^ -1))) >> 31)) & 2)) - (v5361 + ((~(((v5362 ^ -1) | (-(v5362 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5382[v5531] = v5379;
    int * v5384 = v5236->cache_tags;
    int v5534 = (int)((unsigned int)((int)((unsigned int)(v5240 + 20) >> 2)) >> 1);
    v5384[v5510] = v5534;
    int * v5386 = v5236->cache_dirty;
    v5386[v5510] = 0;
    int * v5388 = v5236->cache_age;
    v5388[v5510] = 1;
    int * v5390 = v5236->cache_age;
    int v5391 = v5390[v5510];
    int v5392 = v5390[v5414];
    int v5540 = v5392 + ((int)((unsigned int)(v5392 - v5391) >> 31));
    v5390[v5414] = v5540;
    int * v5394 = v5236->cache_age;
    int v5395 = v5394[v5415];
    int v5542 = v5395 + ((int)((unsigned int)(v5395 - v5391) >> 31));
    v5394[v5415] = v5542;
    int * v5397 = v5236->cache_age;
    v5397[v5510] = 0;
    v5400 = v5510;
  }
  int * v5401 = v5236->cache_vals;
  int v5545 = (v5400 * 2) + (((int)((unsigned int)(v5240 + 20) >> 2)) & 1);
  v5401[v5545] = v5241;
  int * v5403 = v5236->cache_dirty;
  v5403[v5400] = 1;
  struct StateT * v5405 = slot_55(v5236);
  return v5405;
}

struct StateT * slot_26(struct StateT * v2939) {
  int * v2940 = v2939->regs;
  int v2941 = v2940[12];
  bool v2956 = !(v2941 == 0);
  struct StateT * v2952;
  if (v2956) {
    int v2942 = v2939->timer;
    int v2957 = v2942 + 15;
    v2939->timer = v2957;
    int * v2944 = v2939->saved_regs;
    int v2945 = v2944[13];
    int * v2946 = v2939->regs;
    v2946[13] = v2945;
    struct StateT * v2948 = slot_28(v2939);
    v2952 = v2948;
  } else {
    struct StateT * v2950 = slot_29(v2939);
    v2952 = v2950;
  }
  return v2952;
}

struct StateT * slot_82(struct StateT * v7631) {
  int v7632 = v7631->timer;
  int v7802 = v7632 + 1;
  v7631->timer = v7802;
  int * v7634 = v7631->regs;
  int v7635 = v7634[10];
  int v7636 = v7634[11];
  int * v7637 = v7631->cache_tags;
  int v7807 = (((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1)) & 1) * 2;
  int v7638 = v7637[v7807];
  int v7808 = ((((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1)) & 1) * 2) + 1;
  int v7639 = v7637[v7808];
  int v7809 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1)) & 3) * 2);
  int v7640 = v7637[v7809];
  int v7810 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v7641 = v7637[v7810];
  int v7642 = v7631->timer;
  int v7811 = v7642 + ((100 ^ (((~(((v7640 ^ ((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1))) | (-(v7640 ^ ((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v7641 ^ ((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1))) | (-(v7641 ^ ((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v7638 ^ ((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1))) | (-(v7638 ^ ((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v7639 ^ ((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1))) | (-(v7639 ^ ((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v7640 ^ ((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1))) | (-(v7640 ^ ((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v7641 ^ ((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1))) | (-(v7641 ^ ((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1))))) >> 31))) & 104)))));
  v7631->timer = v7811;
  bool v7812 = !(((~(((v7638 ^ ((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1))) | (-(v7638 ^ ((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v7639 ^ ((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1))) | (-(v7639 ^ ((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v7736;
  if (v7812) {
    int * v7644 = v7631->cache_age;
    int v7814 = ((((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1)) & 1) * 2) + ((~(((v7639 ^ ((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1))) | (-(v7639 ^ ((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1))))) >> 31)) & 1);
    int v7645 = v7644[v7814];
    int v7646 = v7644[v7807];
    int v7815 = v7646 + ((int)((unsigned int)(v7646 - v7645) >> 31));
    v7644[v7807] = v7815;
    int * v7648 = v7631->cache_age;
    int v7649 = v7648[v7808];
    int v7817 = v7649 + ((int)((unsigned int)(v7649 - v7645) >> 31));
    v7648[v7808] = v7817;
    int * v7651 = v7631->cache_age;
    v7651[v7814] = 0;
    v7736 = v7814;
  } else {
    int * v7654 = v7631->cache_age;
    int v7821 = (((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1)) & 1) * 2;
    int v7655 = v7654[v7821];
    int * v7656 = v7631->cache_tags;
    int v7657 = v7656[v7821];
    int v7658 = v7654[v7808];
    int v7659 = v7656[v7808];
    bool v7823 = !(((~(((v7640 ^ ((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1))) | (-(v7640 ^ ((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v7641 ^ ((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1))) | (-(v7641 ^ ((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1))))) >> 31))) == 0);
    int v7713;
    if (v7823) {
      int * v7660 = v7631->cache_age;
      int v7825 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7641 ^ ((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1))) | (-(v7641 ^ ((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1))))) >> 31)) & 1);
      int v7661 = v7660[v7825];
      int v7662 = v7660[v7809];
      int v7826 = v7662 + ((int)((unsigned int)(v7662 - v7661) >> 31));
      v7660[v7809] = v7826;
      int * v7664 = v7631->cache_age;
      int v7665 = v7664[v7810];
      int v7828 = v7665 + ((int)((unsigned int)(v7665 - v7661) >> 31));
      v7664[v7810] = v7828;
      int * v7667 = v7631->cache_age;
      v7667[v7825] = 0;
      v7713 = v7825;
    } else {
      int * v7670 = v7631->cache_age;
      int v7832 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1)) & 3) * 2);
      int v7671 = v7670[v7832];
      int * v7672 = v7631->cache_tags;
      int v7673 = v7672[v7832];
      int v7674 = v7670[v7810];
      int v7675 = v7672[v7810];
      int * v7676 = v7631->cache_dirty;
      int v7835 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v7671 + ((~(((v7673 ^ -1) | (-(v7673 ^ -1))) >> 31)) & 2)) - (v7674 + ((~(((v7675 ^ -1) | (-(v7675 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v7677 = v7676[v7835];
      bool v7836 = !(v7677 == 0);
      if (v7836) {
        int * v7678 = v7631->cache_tags;
        int v7679 = v7678[v7835];
        int * v7680 = v7631->cache_vals;
        int v7839 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v7671 + ((~(((v7673 ^ -1) | (-(v7673 ^ -1))) >> 31)) & 2)) - (v7674 + ((~(((v7675 ^ -1) | (-(v7675 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v7681 = v7680[v7839];
        int v7840 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v7671 + ((~(((v7673 ^ -1) | (-(v7673 ^ -1))) >> 31)) & 2)) - (v7674 + ((~(((v7675 ^ -1) | (-(v7675 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v7682 = v7680[v7840];
        int * v7683 = v7631->mem;
        int v7842 = v7679 * 2;
        v7683[v7842] = v7681;
        int * v7685 = v7631->mem;
        int v7845 = (v7679 * 2) + 1;
        v7685[v7845] = v7682;
        ;
      } else {
        ;
      }
      int * v7690 = v7631->mem;
      int v7850 = ((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1)) * 2;
      int v7691 = v7690[v7850];
      int v7851 = (((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1)) * 2) + 1;
      int v7692 = v7690[v7851];
      int * v7693 = v7631->cache_vals;
      int v7853 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v7671 + ((~(((v7673 ^ -1) | (-(v7673 ^ -1))) >> 31)) & 2)) - (v7674 + ((~(((v7675 ^ -1) | (-(v7675 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v7693[v7853] = v7691;
      int * v7695 = v7631->cache_vals;
      int v7856 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v7671 + ((~(((v7673 ^ -1) | (-(v7673 ^ -1))) >> 31)) & 2)) - (v7674 + ((~(((v7675 ^ -1) | (-(v7675 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v7695[v7856] = v7692;
      int * v7697 = v7631->cache_tags;
      int v7859 = (int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1);
      v7697[v7835] = v7859;
      int * v7699 = v7631->cache_dirty;
      v7699[v7835] = 0;
      int * v7701 = v7631->cache_age;
      v7701[v7835] = 1;
      int * v7703 = v7631->cache_age;
      int v7704 = v7703[v7835];
      int v7705 = v7703[v7809];
      int v7865 = v7705 + ((int)((unsigned int)(v7705 - v7704) >> 31));
      v7703[v7809] = v7865;
      int * v7707 = v7631->cache_age;
      int v7708 = v7707[v7810];
      int v7867 = v7708 + ((int)((unsigned int)(v7708 - v7704) >> 31));
      v7707[v7810] = v7867;
      int * v7710 = v7631->cache_age;
      v7710[v7835] = 0;
      v7713 = v7835;
    }
    int * v7714 = v7631->cache_vals;
    int v7870 = v7713 * 2;
    int v7715 = v7714[v7870];
    int v7871 = (v7713 * 2) + 1;
    int v7716 = v7714[v7871];
    int v7872 = (((((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v7655 + ((~(((v7657 ^ -1) | (-(v7657 ^ -1))) >> 31)) & 2)) - (v7658 + ((~(((v7659 ^ -1) | (-(v7659 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7714[v7872] = v7715;
    int * v7718 = v7631->cache_vals;
    int v7875 = ((((((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v7655 + ((~(((v7657 ^ -1) | (-(v7657 ^ -1))) >> 31)) & 2)) - (v7658 + ((~(((v7659 ^ -1) | (-(v7659 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7718[v7875] = v7716;
    int * v7720 = v7631->cache_tags;
    int v7878 = ((((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v7655 + ((~(((v7657 ^ -1) | (-(v7657 ^ -1))) >> 31)) & 2)) - (v7658 + ((~(((v7659 ^ -1) | (-(v7659 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7879 = (int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1);
    v7720[v7878] = v7879;
    int * v7722 = v7631->cache_dirty;
    v7722[v7878] = 0;
    int * v7724 = v7631->cache_age;
    v7724[v7878] = 1;
    int * v7726 = v7631->cache_age;
    int v7727 = v7726[v7878];
    int v7728 = v7726[v7807];
    int v7885 = v7728 + ((int)((unsigned int)(v7728 - v7727) >> 31));
    v7726[v7807] = v7885;
    int * v7730 = v7631->cache_age;
    int v7731 = v7730[v7808];
    int v7887 = v7731 + ((int)((unsigned int)(v7731 - v7727) >> 31));
    v7730[v7808] = v7887;
    int * v7733 = v7631->cache_age;
    v7733[v7878] = 0;
    v7736 = v7878;
  }
  int * v7737 = v7631->cache_vals;
  int v7890 = (v7736 * 2) + (((int)((unsigned int)(v7635 + 36) >> 2)) & 1);
  v7737[v7890] = v7636;
  int * v7739 = v7631->cache_tags;
  int v7740 = v7739[v7809];
  int v7741 = v7739[v7810];
  bool v7893 = !(((~(((v7740 ^ ((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1))) | (-(v7740 ^ ((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v7741 ^ ((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1))) | (-(v7741 ^ ((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v7795;
  if (v7893) {
    int * v7742 = v7631->cache_age;
    int v7895 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7741 ^ ((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1))) | (-(v7741 ^ ((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1))))) >> 31)) & 1);
    int v7743 = v7742[v7895];
    int v7744 = v7742[v7809];
    int v7896 = v7744 + ((int)((unsigned int)(v7744 - v7743) >> 31));
    v7742[v7809] = v7896;
    int * v7746 = v7631->cache_age;
    int v7747 = v7746[v7810];
    int v7898 = v7747 + ((int)((unsigned int)(v7747 - v7743) >> 31));
    v7746[v7810] = v7898;
    int * v7749 = v7631->cache_age;
    v7749[v7895] = 0;
    v7795 = v7895;
  } else {
    int * v7752 = v7631->cache_age;
    int v7902 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1)) & 3) * 2);
    int v7753 = v7752[v7902];
    int * v7754 = v7631->cache_tags;
    int v7755 = v7754[v7902];
    int v7756 = v7752[v7810];
    int v7757 = v7754[v7810];
    int * v7758 = v7631->cache_dirty;
    int v7905 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v7753 + ((~(((v7755 ^ -1) | (-(v7755 ^ -1))) >> 31)) & 2)) - (v7756 + ((~(((v7757 ^ -1) | (-(v7757 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7759 = v7758[v7905];
    bool v7906 = !(v7759 == 0);
    if (v7906) {
      int * v7760 = v7631->cache_tags;
      int v7761 = v7760[v7905];
      int * v7762 = v7631->cache_vals;
      int v7909 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v7753 + ((~(((v7755 ^ -1) | (-(v7755 ^ -1))) >> 31)) & 2)) - (v7756 + ((~(((v7757 ^ -1) | (-(v7757 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v7763 = v7762[v7909];
      int v7910 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v7753 + ((~(((v7755 ^ -1) | (-(v7755 ^ -1))) >> 31)) & 2)) - (v7756 + ((~(((v7757 ^ -1) | (-(v7757 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v7764 = v7762[v7910];
      int * v7765 = v7631->mem;
      int v7912 = v7761 * 2;
      v7765[v7912] = v7763;
      int * v7767 = v7631->mem;
      int v7915 = (v7761 * 2) + 1;
      v7767[v7915] = v7764;
      ;
    } else {
      ;
    }
    int * v7772 = v7631->mem;
    int v7920 = ((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1)) * 2;
    int v7773 = v7772[v7920];
    int v7921 = (((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1)) * 2) + 1;
    int v7774 = v7772[v7921];
    int * v7775 = v7631->cache_vals;
    int v7923 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v7753 + ((~(((v7755 ^ -1) | (-(v7755 ^ -1))) >> 31)) & 2)) - (v7756 + ((~(((v7757 ^ -1) | (-(v7757 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7775[v7923] = v7773;
    int * v7777 = v7631->cache_vals;
    int v7926 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v7753 + ((~(((v7755 ^ -1) | (-(v7755 ^ -1))) >> 31)) & 2)) - (v7756 + ((~(((v7757 ^ -1) | (-(v7757 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7777[v7926] = v7774;
    int * v7779 = v7631->cache_tags;
    int v7929 = (int)((unsigned int)((int)((unsigned int)(v7635 + 36) >> 2)) >> 1);
    v7779[v7905] = v7929;
    int * v7781 = v7631->cache_dirty;
    v7781[v7905] = 0;
    int * v7783 = v7631->cache_age;
    v7783[v7905] = 1;
    int * v7785 = v7631->cache_age;
    int v7786 = v7785[v7905];
    int v7787 = v7785[v7809];
    int v7935 = v7787 + ((int)((unsigned int)(v7787 - v7786) >> 31));
    v7785[v7809] = v7935;
    int * v7789 = v7631->cache_age;
    int v7790 = v7789[v7810];
    int v7937 = v7790 + ((int)((unsigned int)(v7790 - v7786) >> 31));
    v7789[v7810] = v7937;
    int * v7792 = v7631->cache_age;
    v7792[v7905] = 0;
    v7795 = v7905;
  }
  int * v7796 = v7631->cache_vals;
  int v7940 = (v7795 * 2) + (((int)((unsigned int)(v7635 + 36) >> 2)) & 1);
  v7796[v7940] = v7636;
  int * v7798 = v7631->cache_dirty;
  v7798[v7795] = 1;
  struct StateT * v7800 = slot_83(v7631);
  return v7800;
}

struct StateT * slot_65(struct StateT * v6208) {
  int v6209 = v6208->timer;
  int v6216 = v6209 + 1;
  v6208->timer = v6216;
  int * v6211 = v6208->regs;
  int v6212 = v6211[11];
  int v6220 = v6212 + 28;
  v6211[13] = v6220;
  struct StateT * v6214 = slot_67(v6208);
  return v6214;
}

struct StateT * slot_10(struct StateT * v916) {
  int * v917 = v916->regs;
  int v918 = v917[12];
  bool v929 = !(v918 == 0);
  struct StateT * v925;
  if (v929) {
    int v919 = v916->timer;
    int v930 = v919 + 15;
    v916->timer = v930;
    struct StateT * v921 = slot_11(v916);
    v925 = v921;
  } else {
    struct StateT * v923 = slot_12(v916);
    v925 = v923;
  }
  return v925;
}

struct StateT * slot_74(struct StateT * v6830) {
  int v6831 = v6830->timer;
  int v6941 = v6831 + 1;
  v6830->timer = v6941;
  int * v6833 = v6830->regs;
  int v6834 = v6833[13];
  int * v6835 = v6830->cache_tags;
  int v6945 = (((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1)) & 1) * 2;
  int v6836 = v6835[v6945];
  int v6946 = ((((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1)) & 1) * 2) + 1;
  int v6837 = v6835[v6946];
  int v6947 = 4 + ((((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1)) & 3) * 2);
  int v6838 = v6835[v6947];
  int v6948 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v6839 = v6835[v6948];
  int v6840 = v6830->timer;
  int v6949 = v6840 + ((100 ^ (((~(((v6838 ^ ((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1))) | (-(v6838 ^ ((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1))))) >> 31)) | (~(((v6839 ^ ((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1))) | (-(v6839 ^ ((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v6836 ^ ((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1))) | (-(v6836 ^ ((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1))))) >> 31)) | (~(((v6837 ^ ((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1))) | (-(v6837 ^ ((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v6838 ^ ((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1))) | (-(v6838 ^ ((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1))))) >> 31)) | (~(((v6839 ^ ((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1))) | (-(v6839 ^ ((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1))))) >> 31))) & 104)))));
  v6830->timer = v6949;
  int * v6842 = v6830->cache_vals;
  bool v6950 = !(((~(((v6836 ^ ((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1))) | (-(v6836 ^ ((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1))))) >> 31)) | (~(((v6837 ^ ((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1))) | (-(v6837 ^ ((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1))))) >> 31))) == 0);
  int v6935;
  if (v6950) {
    int * v6843 = v6830->cache_age;
    int v6952 = ((((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1)) & 1) * 2) + ((~(((v6837 ^ ((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1))) | (-(v6837 ^ ((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1))))) >> 31)) & 1);
    int v6844 = v6843[v6952];
    int v6845 = v6843[v6945];
    int v6953 = v6845 + ((int)((unsigned int)(v6845 - v6844) >> 31));
    v6843[v6945] = v6953;
    int * v6847 = v6830->cache_age;
    int v6848 = v6847[v6946];
    int v6955 = v6848 + ((int)((unsigned int)(v6848 - v6844) >> 31));
    v6847[v6946] = v6955;
    int * v6850 = v6830->cache_age;
    v6850[v6952] = 0;
    v6935 = v6952;
  } else {
    int * v6853 = v6830->cache_age;
    int v6959 = (((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1)) & 1) * 2;
    int v6854 = v6853[v6959];
    int * v6855 = v6830->cache_tags;
    int v6856 = v6855[v6959];
    int v6857 = v6853[v6946];
    int v6858 = v6855[v6946];
    bool v6961 = !(((~(((v6838 ^ ((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1))) | (-(v6838 ^ ((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1))))) >> 31)) | (~(((v6839 ^ ((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1))) | (-(v6839 ^ ((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1))))) >> 31))) == 0);
    int v6912;
    if (v6961) {
      int * v6859 = v6830->cache_age;
      int v6963 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1)) & 3) * 2)) + ((~(((v6839 ^ ((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1))) | (-(v6839 ^ ((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1))))) >> 31)) & 1);
      int v6860 = v6859[v6963];
      int v6861 = v6859[v6947];
      int v6964 = v6861 + ((int)((unsigned int)(v6861 - v6860) >> 31));
      v6859[v6947] = v6964;
      int * v6863 = v6830->cache_age;
      int v6864 = v6863[v6948];
      int v6966 = v6864 + ((int)((unsigned int)(v6864 - v6860) >> 31));
      v6863[v6948] = v6966;
      int * v6866 = v6830->cache_age;
      v6866[v6963] = 0;
      v6912 = v6963;
    } else {
      int * v6869 = v6830->cache_age;
      int v6970 = 4 + ((((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1)) & 3) * 2);
      int v6870 = v6869[v6970];
      int * v6871 = v6830->cache_tags;
      int v6872 = v6871[v6970];
      int v6873 = v6869[v6948];
      int v6874 = v6871[v6948];
      int * v6875 = v6830->cache_dirty;
      int v6973 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1)) & 3) * 2)) + ((((v6870 + ((~(((v6872 ^ -1) | (-(v6872 ^ -1))) >> 31)) & 2)) - (v6873 + ((~(((v6874 ^ -1) | (-(v6874 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v6876 = v6875[v6973];
      bool v6974 = !(v6876 == 0);
      if (v6974) {
        int * v6877 = v6830->cache_tags;
        int v6878 = v6877[v6973];
        int * v6879 = v6830->cache_vals;
        int v6977 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1)) & 3) * 2)) + ((((v6870 + ((~(((v6872 ^ -1) | (-(v6872 ^ -1))) >> 31)) & 2)) - (v6873 + ((~(((v6874 ^ -1) | (-(v6874 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v6880 = v6879[v6977];
        int v6978 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1)) & 3) * 2)) + ((((v6870 + ((~(((v6872 ^ -1) | (-(v6872 ^ -1))) >> 31)) & 2)) - (v6873 + ((~(((v6874 ^ -1) | (-(v6874 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v6881 = v6879[v6978];
        int * v6882 = v6830->mem;
        int v6980 = v6878 * 2;
        v6882[v6980] = v6880;
        int * v6884 = v6830->mem;
        int v6983 = (v6878 * 2) + 1;
        v6884[v6983] = v6881;
        ;
      } else {
        ;
      }
      int * v6889 = v6830->mem;
      int v6988 = ((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1)) * 2;
      int v6890 = v6889[v6988];
      int v6989 = (((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1)) * 2) + 1;
      int v6891 = v6889[v6989];
      int * v6892 = v6830->cache_vals;
      int v6991 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1)) & 3) * 2)) + ((((v6870 + ((~(((v6872 ^ -1) | (-(v6872 ^ -1))) >> 31)) & 2)) - (v6873 + ((~(((v6874 ^ -1) | (-(v6874 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v6892[v6991] = v6890;
      int * v6894 = v6830->cache_vals;
      int v6994 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1)) & 3) * 2)) + ((((v6870 + ((~(((v6872 ^ -1) | (-(v6872 ^ -1))) >> 31)) & 2)) - (v6873 + ((~(((v6874 ^ -1) | (-(v6874 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v6894[v6994] = v6891;
      int * v6896 = v6830->cache_tags;
      int v6997 = (int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1);
      v6896[v6973] = v6997;
      int * v6898 = v6830->cache_dirty;
      v6898[v6973] = 0;
      int * v6900 = v6830->cache_age;
      v6900[v6973] = 1;
      int * v6902 = v6830->cache_age;
      int v6903 = v6902[v6973];
      int v6904 = v6902[v6947];
      int v7003 = v6904 + ((int)((unsigned int)(v6904 - v6903) >> 31));
      v6902[v6947] = v7003;
      int * v6906 = v6830->cache_age;
      int v6907 = v6906[v6948];
      int v7005 = v6907 + ((int)((unsigned int)(v6907 - v6903) >> 31));
      v6906[v6948] = v7005;
      int * v6909 = v6830->cache_age;
      v6909[v6973] = 0;
      v6912 = v6973;
    }
    int * v6913 = v6830->cache_vals;
    int v7008 = v6912 * 2;
    int v6914 = v6913[v7008];
    int v7009 = (v6912 * 2) + 1;
    int v6915 = v6913[v7009];
    int v7010 = (((((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1)) & 1) * 2) + ((((v6854 + ((~(((v6856 ^ -1) | (-(v6856 ^ -1))) >> 31)) & 2)) - (v6857 + ((~(((v6858 ^ -1) | (-(v6858 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6913[v7010] = v6914;
    int * v6917 = v6830->cache_vals;
    int v7013 = ((((((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1)) & 1) * 2) + ((((v6854 + ((~(((v6856 ^ -1) | (-(v6856 ^ -1))) >> 31)) & 2)) - (v6857 + ((~(((v6858 ^ -1) | (-(v6858 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6917[v7013] = v6915;
    int * v6919 = v6830->cache_tags;
    int v7016 = ((((int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1)) & 1) * 2) + ((((v6854 + ((~(((v6856 ^ -1) | (-(v6856 ^ -1))) >> 31)) & 2)) - (v6857 + ((~(((v6858 ^ -1) | (-(v6858 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7017 = (int)((unsigned int)((int)((unsigned int)v6834 >> 2)) >> 1);
    v6919[v7016] = v7017;
    int * v6921 = v6830->cache_dirty;
    v6921[v7016] = 0;
    int * v6923 = v6830->cache_age;
    v6923[v7016] = 1;
    int * v6925 = v6830->cache_age;
    int v6926 = v6925[v7016];
    int v6927 = v6925[v6945];
    int v7023 = v6927 + ((int)((unsigned int)(v6927 - v6926) >> 31));
    v6925[v6945] = v7023;
    int * v6929 = v6830->cache_age;
    int v6930 = v6929[v6946];
    int v7025 = v6930 + ((int)((unsigned int)(v6930 - v6926) >> 31));
    v6929[v6946] = v7025;
    int * v6932 = v6830->cache_age;
    v6932[v7016] = 0;
    v6935 = v7016;
  }
  int v7028 = (v6935 * 2) + (((int)((unsigned int)v6834 >> 2)) & 1);
  int v6936 = v6842[v7028];
  int * v6937 = v6830->regs;
  v6937[13] = v6936;
  struct StateT * v6939 = slot_75(v6830);
  return v6939;
}

struct StateT * slot_19(struct StateT * v2221) {
  int v2222 = v2221->timer;
  int v2392 = v2222 + 1;
  v2221->timer = v2392;
  int * v2224 = v2221->regs;
  int v2225 = v2224[10];
  int v2226 = v2224[14];
  int * v2227 = v2221->cache_tags;
  int v2397 = (((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1)) & 1) * 2;
  int v2228 = v2227[v2397];
  int v2398 = ((((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2229 = v2227[v2398];
  int v2399 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1)) & 3) * 2);
  int v2230 = v2227[v2399];
  int v2400 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2231 = v2227[v2400];
  int v2232 = v2221->timer;
  int v2401 = v2232 + ((100 ^ (((~(((v2230 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1))) | (-(v2230 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2231 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1))) | (-(v2231 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2228 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1))) | (-(v2228 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2229 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1))) | (-(v2229 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2230 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1))) | (-(v2230 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2231 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1))) | (-(v2231 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2221->timer = v2401;
  bool v2402 = !(((~(((v2228 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1))) | (-(v2228 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2229 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1))) | (-(v2229 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v2326;
  if (v2402) {
    int * v2234 = v2221->cache_age;
    int v2404 = ((((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v2229 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1))) | (-(v2229 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v2235 = v2234[v2404];
    int v2236 = v2234[v2397];
    int v2405 = v2236 + ((int)((unsigned int)(v2236 - v2235) >> 31));
    v2234[v2397] = v2405;
    int * v2238 = v2221->cache_age;
    int v2239 = v2238[v2398];
    int v2407 = v2239 + ((int)((unsigned int)(v2239 - v2235) >> 31));
    v2238[v2398] = v2407;
    int * v2241 = v2221->cache_age;
    v2241[v2404] = 0;
    v2326 = v2404;
  } else {
    int * v2244 = v2221->cache_age;
    int v2411 = (((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1)) & 1) * 2;
    int v2245 = v2244[v2411];
    int * v2246 = v2221->cache_tags;
    int v2247 = v2246[v2411];
    int v2248 = v2244[v2398];
    int v2249 = v2246[v2398];
    bool v2413 = !(((~(((v2230 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1))) | (-(v2230 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2231 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1))) | (-(v2231 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v2303;
    if (v2413) {
      int * v2250 = v2221->cache_age;
      int v2415 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2231 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1))) | (-(v2231 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v2251 = v2250[v2415];
      int v2252 = v2250[v2399];
      int v2416 = v2252 + ((int)((unsigned int)(v2252 - v2251) >> 31));
      v2250[v2399] = v2416;
      int * v2254 = v2221->cache_age;
      int v2255 = v2254[v2400];
      int v2418 = v2255 + ((int)((unsigned int)(v2255 - v2251) >> 31));
      v2254[v2400] = v2418;
      int * v2257 = v2221->cache_age;
      v2257[v2415] = 0;
      v2303 = v2415;
    } else {
      int * v2260 = v2221->cache_age;
      int v2422 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1)) & 3) * 2);
      int v2261 = v2260[v2422];
      int * v2262 = v2221->cache_tags;
      int v2263 = v2262[v2422];
      int v2264 = v2260[v2400];
      int v2265 = v2262[v2400];
      int * v2266 = v2221->cache_dirty;
      int v2425 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2261 + ((~(((v2263 ^ -1) | (-(v2263 ^ -1))) >> 31)) & 2)) - (v2264 + ((~(((v2265 ^ -1) | (-(v2265 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2267 = v2266[v2425];
      bool v2426 = !(v2267 == 0);
      if (v2426) {
        int * v2268 = v2221->cache_tags;
        int v2269 = v2268[v2425];
        int * v2270 = v2221->cache_vals;
        int v2429 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2261 + ((~(((v2263 ^ -1) | (-(v2263 ^ -1))) >> 31)) & 2)) - (v2264 + ((~(((v2265 ^ -1) | (-(v2265 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2271 = v2270[v2429];
        int v2430 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2261 + ((~(((v2263 ^ -1) | (-(v2263 ^ -1))) >> 31)) & 2)) - (v2264 + ((~(((v2265 ^ -1) | (-(v2265 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2272 = v2270[v2430];
        int * v2273 = v2221->mem;
        int v2432 = v2269 * 2;
        v2273[v2432] = v2271;
        int * v2275 = v2221->mem;
        int v2435 = (v2269 * 2) + 1;
        v2275[v2435] = v2272;
        ;
      } else {
        ;
      }
      int * v2280 = v2221->mem;
      int v2440 = ((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1)) * 2;
      int v2281 = v2280[v2440];
      int v2441 = (((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1)) * 2) + 1;
      int v2282 = v2280[v2441];
      int * v2283 = v2221->cache_vals;
      int v2443 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2261 + ((~(((v2263 ^ -1) | (-(v2263 ^ -1))) >> 31)) & 2)) - (v2264 + ((~(((v2265 ^ -1) | (-(v2265 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2283[v2443] = v2281;
      int * v2285 = v2221->cache_vals;
      int v2446 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2261 + ((~(((v2263 ^ -1) | (-(v2263 ^ -1))) >> 31)) & 2)) - (v2264 + ((~(((v2265 ^ -1) | (-(v2265 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2285[v2446] = v2282;
      int * v2287 = v2221->cache_tags;
      int v2449 = (int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1);
      v2287[v2425] = v2449;
      int * v2289 = v2221->cache_dirty;
      v2289[v2425] = 0;
      int * v2291 = v2221->cache_age;
      v2291[v2425] = 1;
      int * v2293 = v2221->cache_age;
      int v2294 = v2293[v2425];
      int v2295 = v2293[v2399];
      int v2455 = v2295 + ((int)((unsigned int)(v2295 - v2294) >> 31));
      v2293[v2399] = v2455;
      int * v2297 = v2221->cache_age;
      int v2298 = v2297[v2400];
      int v2457 = v2298 + ((int)((unsigned int)(v2298 - v2294) >> 31));
      v2297[v2400] = v2457;
      int * v2300 = v2221->cache_age;
      v2300[v2425] = 0;
      v2303 = v2425;
    }
    int * v2304 = v2221->cache_vals;
    int v2460 = v2303 * 2;
    int v2305 = v2304[v2460];
    int v2461 = (v2303 * 2) + 1;
    int v2306 = v2304[v2461];
    int v2462 = (((((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v2245 + ((~(((v2247 ^ -1) | (-(v2247 ^ -1))) >> 31)) & 2)) - (v2248 + ((~(((v2249 ^ -1) | (-(v2249 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2304[v2462] = v2305;
    int * v2308 = v2221->cache_vals;
    int v2465 = ((((((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v2245 + ((~(((v2247 ^ -1) | (-(v2247 ^ -1))) >> 31)) & 2)) - (v2248 + ((~(((v2249 ^ -1) | (-(v2249 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2308[v2465] = v2306;
    int * v2310 = v2221->cache_tags;
    int v2468 = ((((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v2245 + ((~(((v2247 ^ -1) | (-(v2247 ^ -1))) >> 31)) & 2)) - (v2248 + ((~(((v2249 ^ -1) | (-(v2249 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2469 = (int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1);
    v2310[v2468] = v2469;
    int * v2312 = v2221->cache_dirty;
    v2312[v2468] = 0;
    int * v2314 = v2221->cache_age;
    v2314[v2468] = 1;
    int * v2316 = v2221->cache_age;
    int v2317 = v2316[v2468];
    int v2318 = v2316[v2397];
    int v2475 = v2318 + ((int)((unsigned int)(v2318 - v2317) >> 31));
    v2316[v2397] = v2475;
    int * v2320 = v2221->cache_age;
    int v2321 = v2320[v2398];
    int v2477 = v2321 + ((int)((unsigned int)(v2321 - v2317) >> 31));
    v2320[v2398] = v2477;
    int * v2323 = v2221->cache_age;
    v2323[v2468] = 0;
    v2326 = v2468;
  }
  int * v2327 = v2221->cache_vals;
  int v2480 = (v2326 * 2) + (((int)((unsigned int)(v2225 + 4) >> 2)) & 1);
  v2327[v2480] = v2226;
  int * v2329 = v2221->cache_tags;
  int v2330 = v2329[v2399];
  int v2331 = v2329[v2400];
  bool v2483 = !(((~(((v2330 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1))) | (-(v2330 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2331 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1))) | (-(v2331 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v2385;
  if (v2483) {
    int * v2332 = v2221->cache_age;
    int v2485 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2331 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1))) | (-(v2331 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v2333 = v2332[v2485];
    int v2334 = v2332[v2399];
    int v2486 = v2334 + ((int)((unsigned int)(v2334 - v2333) >> 31));
    v2332[v2399] = v2486;
    int * v2336 = v2221->cache_age;
    int v2337 = v2336[v2400];
    int v2488 = v2337 + ((int)((unsigned int)(v2337 - v2333) >> 31));
    v2336[v2400] = v2488;
    int * v2339 = v2221->cache_age;
    v2339[v2485] = 0;
    v2385 = v2485;
  } else {
    int * v2342 = v2221->cache_age;
    int v2492 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1)) & 3) * 2);
    int v2343 = v2342[v2492];
    int * v2344 = v2221->cache_tags;
    int v2345 = v2344[v2492];
    int v2346 = v2342[v2400];
    int v2347 = v2344[v2400];
    int * v2348 = v2221->cache_dirty;
    int v2495 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2343 + ((~(((v2345 ^ -1) | (-(v2345 ^ -1))) >> 31)) & 2)) - (v2346 + ((~(((v2347 ^ -1) | (-(v2347 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2349 = v2348[v2495];
    bool v2496 = !(v2349 == 0);
    if (v2496) {
      int * v2350 = v2221->cache_tags;
      int v2351 = v2350[v2495];
      int * v2352 = v2221->cache_vals;
      int v2499 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2343 + ((~(((v2345 ^ -1) | (-(v2345 ^ -1))) >> 31)) & 2)) - (v2346 + ((~(((v2347 ^ -1) | (-(v2347 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v2353 = v2352[v2499];
      int v2500 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2343 + ((~(((v2345 ^ -1) | (-(v2345 ^ -1))) >> 31)) & 2)) - (v2346 + ((~(((v2347 ^ -1) | (-(v2347 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v2354 = v2352[v2500];
      int * v2355 = v2221->mem;
      int v2502 = v2351 * 2;
      v2355[v2502] = v2353;
      int * v2357 = v2221->mem;
      int v2505 = (v2351 * 2) + 1;
      v2357[v2505] = v2354;
      ;
    } else {
      ;
    }
    int * v2362 = v2221->mem;
    int v2510 = ((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1)) * 2;
    int v2363 = v2362[v2510];
    int v2511 = (((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1)) * 2) + 1;
    int v2364 = v2362[v2511];
    int * v2365 = v2221->cache_vals;
    int v2513 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2343 + ((~(((v2345 ^ -1) | (-(v2345 ^ -1))) >> 31)) & 2)) - (v2346 + ((~(((v2347 ^ -1) | (-(v2347 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2365[v2513] = v2363;
    int * v2367 = v2221->cache_vals;
    int v2516 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2343 + ((~(((v2345 ^ -1) | (-(v2345 ^ -1))) >> 31)) & 2)) - (v2346 + ((~(((v2347 ^ -1) | (-(v2347 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2367[v2516] = v2364;
    int * v2369 = v2221->cache_tags;
    int v2519 = (int)((unsigned int)((int)((unsigned int)(v2225 + 4) >> 2)) >> 1);
    v2369[v2495] = v2519;
    int * v2371 = v2221->cache_dirty;
    v2371[v2495] = 0;
    int * v2373 = v2221->cache_age;
    v2373[v2495] = 1;
    int * v2375 = v2221->cache_age;
    int v2376 = v2375[v2495];
    int v2377 = v2375[v2399];
    int v2525 = v2377 + ((int)((unsigned int)(v2377 - v2376) >> 31));
    v2375[v2399] = v2525;
    int * v2379 = v2221->cache_age;
    int v2380 = v2379[v2400];
    int v2527 = v2380 + ((int)((unsigned int)(v2380 - v2376) >> 31));
    v2379[v2400] = v2527;
    int * v2382 = v2221->cache_age;
    v2382[v2495] = 0;
    v2385 = v2495;
  }
  int * v2386 = v2221->cache_vals;
  int v2530 = (v2385 * 2) + (((int)((unsigned int)(v2225 + 4) >> 2)) & 1);
  v2386[v2530] = v2226;
  int * v2388 = v2221->cache_dirty;
  v2388[v2385] = 1;
  struct StateT * v2390 = slot_22(v2221);
  return v2390;
}

struct StateT * slot_58(struct StateT * v5609) {
  int v5610 = v5609->timer;
  int v5617 = v5610 + 1;
  v5609->timer = v5617;
  int * v5612 = v5609->regs;
  int v5613 = v5612[11];
  int v5621 = v5613 + 24;
  v5612[13] = v5621;
  struct StateT * v5615 = slot_60(v5609);
  return v5615;
}

struct StateT * slot_67(struct StateT * v6231) {
  int v6232 = v6231->timer;
  int v6342 = v6232 + 1;
  v6231->timer = v6342;
  int * v6234 = v6231->regs;
  int v6235 = v6234[13];
  int * v6236 = v6231->cache_tags;
  int v6346 = (((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1)) & 1) * 2;
  int v6237 = v6236[v6346];
  int v6347 = ((((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1)) & 1) * 2) + 1;
  int v6238 = v6236[v6347];
  int v6348 = 4 + ((((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1)) & 3) * 2);
  int v6239 = v6236[v6348];
  int v6349 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v6240 = v6236[v6349];
  int v6241 = v6231->timer;
  int v6350 = v6241 + ((100 ^ (((~(((v6239 ^ ((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1))) | (-(v6239 ^ ((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1))))) >> 31)) | (~(((v6240 ^ ((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1))) | (-(v6240 ^ ((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v6237 ^ ((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1))) | (-(v6237 ^ ((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1))))) >> 31)) | (~(((v6238 ^ ((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1))) | (-(v6238 ^ ((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v6239 ^ ((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1))) | (-(v6239 ^ ((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1))))) >> 31)) | (~(((v6240 ^ ((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1))) | (-(v6240 ^ ((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1))))) >> 31))) & 104)))));
  v6231->timer = v6350;
  int * v6243 = v6231->cache_vals;
  bool v6351 = !(((~(((v6237 ^ ((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1))) | (-(v6237 ^ ((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1))))) >> 31)) | (~(((v6238 ^ ((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1))) | (-(v6238 ^ ((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1))))) >> 31))) == 0);
  int v6336;
  if (v6351) {
    int * v6244 = v6231->cache_age;
    int v6353 = ((((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1)) & 1) * 2) + ((~(((v6238 ^ ((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1))) | (-(v6238 ^ ((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1))))) >> 31)) & 1);
    int v6245 = v6244[v6353];
    int v6246 = v6244[v6346];
    int v6354 = v6246 + ((int)((unsigned int)(v6246 - v6245) >> 31));
    v6244[v6346] = v6354;
    int * v6248 = v6231->cache_age;
    int v6249 = v6248[v6347];
    int v6356 = v6249 + ((int)((unsigned int)(v6249 - v6245) >> 31));
    v6248[v6347] = v6356;
    int * v6251 = v6231->cache_age;
    v6251[v6353] = 0;
    v6336 = v6353;
  } else {
    int * v6254 = v6231->cache_age;
    int v6360 = (((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1)) & 1) * 2;
    int v6255 = v6254[v6360];
    int * v6256 = v6231->cache_tags;
    int v6257 = v6256[v6360];
    int v6258 = v6254[v6347];
    int v6259 = v6256[v6347];
    bool v6362 = !(((~(((v6239 ^ ((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1))) | (-(v6239 ^ ((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1))))) >> 31)) | (~(((v6240 ^ ((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1))) | (-(v6240 ^ ((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1))))) >> 31))) == 0);
    int v6313;
    if (v6362) {
      int * v6260 = v6231->cache_age;
      int v6364 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1)) & 3) * 2)) + ((~(((v6240 ^ ((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1))) | (-(v6240 ^ ((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1))))) >> 31)) & 1);
      int v6261 = v6260[v6364];
      int v6262 = v6260[v6348];
      int v6365 = v6262 + ((int)((unsigned int)(v6262 - v6261) >> 31));
      v6260[v6348] = v6365;
      int * v6264 = v6231->cache_age;
      int v6265 = v6264[v6349];
      int v6367 = v6265 + ((int)((unsigned int)(v6265 - v6261) >> 31));
      v6264[v6349] = v6367;
      int * v6267 = v6231->cache_age;
      v6267[v6364] = 0;
      v6313 = v6364;
    } else {
      int * v6270 = v6231->cache_age;
      int v6371 = 4 + ((((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1)) & 3) * 2);
      int v6271 = v6270[v6371];
      int * v6272 = v6231->cache_tags;
      int v6273 = v6272[v6371];
      int v6274 = v6270[v6349];
      int v6275 = v6272[v6349];
      int * v6276 = v6231->cache_dirty;
      int v6374 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1)) & 3) * 2)) + ((((v6271 + ((~(((v6273 ^ -1) | (-(v6273 ^ -1))) >> 31)) & 2)) - (v6274 + ((~(((v6275 ^ -1) | (-(v6275 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v6277 = v6276[v6374];
      bool v6375 = !(v6277 == 0);
      if (v6375) {
        int * v6278 = v6231->cache_tags;
        int v6279 = v6278[v6374];
        int * v6280 = v6231->cache_vals;
        int v6378 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1)) & 3) * 2)) + ((((v6271 + ((~(((v6273 ^ -1) | (-(v6273 ^ -1))) >> 31)) & 2)) - (v6274 + ((~(((v6275 ^ -1) | (-(v6275 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v6281 = v6280[v6378];
        int v6379 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1)) & 3) * 2)) + ((((v6271 + ((~(((v6273 ^ -1) | (-(v6273 ^ -1))) >> 31)) & 2)) - (v6274 + ((~(((v6275 ^ -1) | (-(v6275 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v6282 = v6280[v6379];
        int * v6283 = v6231->mem;
        int v6381 = v6279 * 2;
        v6283[v6381] = v6281;
        int * v6285 = v6231->mem;
        int v6384 = (v6279 * 2) + 1;
        v6285[v6384] = v6282;
        ;
      } else {
        ;
      }
      int * v6290 = v6231->mem;
      int v6389 = ((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1)) * 2;
      int v6291 = v6290[v6389];
      int v6390 = (((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1)) * 2) + 1;
      int v6292 = v6290[v6390];
      int * v6293 = v6231->cache_vals;
      int v6392 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1)) & 3) * 2)) + ((((v6271 + ((~(((v6273 ^ -1) | (-(v6273 ^ -1))) >> 31)) & 2)) - (v6274 + ((~(((v6275 ^ -1) | (-(v6275 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v6293[v6392] = v6291;
      int * v6295 = v6231->cache_vals;
      int v6395 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1)) & 3) * 2)) + ((((v6271 + ((~(((v6273 ^ -1) | (-(v6273 ^ -1))) >> 31)) & 2)) - (v6274 + ((~(((v6275 ^ -1) | (-(v6275 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v6295[v6395] = v6292;
      int * v6297 = v6231->cache_tags;
      int v6398 = (int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1);
      v6297[v6374] = v6398;
      int * v6299 = v6231->cache_dirty;
      v6299[v6374] = 0;
      int * v6301 = v6231->cache_age;
      v6301[v6374] = 1;
      int * v6303 = v6231->cache_age;
      int v6304 = v6303[v6374];
      int v6305 = v6303[v6348];
      int v6404 = v6305 + ((int)((unsigned int)(v6305 - v6304) >> 31));
      v6303[v6348] = v6404;
      int * v6307 = v6231->cache_age;
      int v6308 = v6307[v6349];
      int v6406 = v6308 + ((int)((unsigned int)(v6308 - v6304) >> 31));
      v6307[v6349] = v6406;
      int * v6310 = v6231->cache_age;
      v6310[v6374] = 0;
      v6313 = v6374;
    }
    int * v6314 = v6231->cache_vals;
    int v6409 = v6313 * 2;
    int v6315 = v6314[v6409];
    int v6410 = (v6313 * 2) + 1;
    int v6316 = v6314[v6410];
    int v6411 = (((((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1)) & 1) * 2) + ((((v6255 + ((~(((v6257 ^ -1) | (-(v6257 ^ -1))) >> 31)) & 2)) - (v6258 + ((~(((v6259 ^ -1) | (-(v6259 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6314[v6411] = v6315;
    int * v6318 = v6231->cache_vals;
    int v6414 = ((((((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1)) & 1) * 2) + ((((v6255 + ((~(((v6257 ^ -1) | (-(v6257 ^ -1))) >> 31)) & 2)) - (v6258 + ((~(((v6259 ^ -1) | (-(v6259 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6318[v6414] = v6316;
    int * v6320 = v6231->cache_tags;
    int v6417 = ((((int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1)) & 1) * 2) + ((((v6255 + ((~(((v6257 ^ -1) | (-(v6257 ^ -1))) >> 31)) & 2)) - (v6258 + ((~(((v6259 ^ -1) | (-(v6259 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6418 = (int)((unsigned int)((int)((unsigned int)v6235 >> 2)) >> 1);
    v6320[v6417] = v6418;
    int * v6322 = v6231->cache_dirty;
    v6322[v6417] = 0;
    int * v6324 = v6231->cache_age;
    v6324[v6417] = 1;
    int * v6326 = v6231->cache_age;
    int v6327 = v6326[v6417];
    int v6328 = v6326[v6346];
    int v6424 = v6328 + ((int)((unsigned int)(v6328 - v6327) >> 31));
    v6326[v6346] = v6424;
    int * v6330 = v6231->cache_age;
    int v6331 = v6330[v6347];
    int v6426 = v6331 + ((int)((unsigned int)(v6331 - v6327) >> 31));
    v6330[v6347] = v6426;
    int * v6333 = v6231->cache_age;
    v6333[v6417] = 0;
    v6336 = v6417;
  }
  int v6429 = (v6336 * 2) + (((int)((unsigned int)v6235 >> 2)) & 1);
  int v6337 = v6243[v6429];
  int * v6338 = v6231->regs;
  v6338[13] = v6337;
  struct StateT * v6340 = slot_68(v6231);
  return v6340;
}

struct StateT * slot_81(struct StateT * v7428) {
  int v7429 = v7428->timer;
  int v7539 = v7429 + 1;
  v7428->timer = v7539;
  int * v7431 = v7428->regs;
  int v7432 = v7431[11];
  int * v7433 = v7428->cache_tags;
  int v7543 = (((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1)) & 1) * 2;
  int v7434 = v7433[v7543];
  int v7544 = ((((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1)) & 1) * 2) + 1;
  int v7435 = v7433[v7544];
  int v7545 = 4 + ((((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1)) & 3) * 2);
  int v7436 = v7433[v7545];
  int v7546 = (4 + ((((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v7437 = v7433[v7546];
  int v7438 = v7428->timer;
  int v7547 = v7438 + ((100 ^ (((~(((v7436 ^ ((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1))) | (-(v7436 ^ ((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1))))) >> 31)) | (~(((v7437 ^ ((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1))) | (-(v7437 ^ ((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v7434 ^ ((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1))) | (-(v7434 ^ ((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1))))) >> 31)) | (~(((v7435 ^ ((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1))) | (-(v7435 ^ ((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v7436 ^ ((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1))) | (-(v7436 ^ ((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1))))) >> 31)) | (~(((v7437 ^ ((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1))) | (-(v7437 ^ ((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1))))) >> 31))) & 104)))));
  v7428->timer = v7547;
  int * v7440 = v7428->cache_vals;
  bool v7548 = !(((~(((v7434 ^ ((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1))) | (-(v7434 ^ ((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1))))) >> 31)) | (~(((v7435 ^ ((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1))) | (-(v7435 ^ ((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1))))) >> 31))) == 0);
  int v7533;
  if (v7548) {
    int * v7441 = v7428->cache_age;
    int v7550 = ((((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1)) & 1) * 2) + ((~(((v7435 ^ ((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1))) | (-(v7435 ^ ((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1))))) >> 31)) & 1);
    int v7442 = v7441[v7550];
    int v7443 = v7441[v7543];
    int v7551 = v7443 + ((int)((unsigned int)(v7443 - v7442) >> 31));
    v7441[v7543] = v7551;
    int * v7445 = v7428->cache_age;
    int v7446 = v7445[v7544];
    int v7553 = v7446 + ((int)((unsigned int)(v7446 - v7442) >> 31));
    v7445[v7544] = v7553;
    int * v7448 = v7428->cache_age;
    v7448[v7550] = 0;
    v7533 = v7550;
  } else {
    int * v7451 = v7428->cache_age;
    int v7557 = (((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1)) & 1) * 2;
    int v7452 = v7451[v7557];
    int * v7453 = v7428->cache_tags;
    int v7454 = v7453[v7557];
    int v7455 = v7451[v7544];
    int v7456 = v7453[v7544];
    bool v7559 = !(((~(((v7436 ^ ((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1))) | (-(v7436 ^ ((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1))))) >> 31)) | (~(((v7437 ^ ((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1))) | (-(v7437 ^ ((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1))))) >> 31))) == 0);
    int v7510;
    if (v7559) {
      int * v7457 = v7428->cache_age;
      int v7561 = (4 + ((((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1)) & 3) * 2)) + ((~(((v7437 ^ ((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1))) | (-(v7437 ^ ((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1))))) >> 31)) & 1);
      int v7458 = v7457[v7561];
      int v7459 = v7457[v7545];
      int v7562 = v7459 + ((int)((unsigned int)(v7459 - v7458) >> 31));
      v7457[v7545] = v7562;
      int * v7461 = v7428->cache_age;
      int v7462 = v7461[v7546];
      int v7564 = v7462 + ((int)((unsigned int)(v7462 - v7458) >> 31));
      v7461[v7546] = v7564;
      int * v7464 = v7428->cache_age;
      v7464[v7561] = 0;
      v7510 = v7561;
    } else {
      int * v7467 = v7428->cache_age;
      int v7568 = 4 + ((((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1)) & 3) * 2);
      int v7468 = v7467[v7568];
      int * v7469 = v7428->cache_tags;
      int v7470 = v7469[v7568];
      int v7471 = v7467[v7546];
      int v7472 = v7469[v7546];
      int * v7473 = v7428->cache_dirty;
      int v7571 = (4 + ((((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1)) & 3) * 2)) + ((((v7468 + ((~(((v7470 ^ -1) | (-(v7470 ^ -1))) >> 31)) & 2)) - (v7471 + ((~(((v7472 ^ -1) | (-(v7472 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v7474 = v7473[v7571];
      bool v7572 = !(v7474 == 0);
      if (v7572) {
        int * v7475 = v7428->cache_tags;
        int v7476 = v7475[v7571];
        int * v7477 = v7428->cache_vals;
        int v7575 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1)) & 3) * 2)) + ((((v7468 + ((~(((v7470 ^ -1) | (-(v7470 ^ -1))) >> 31)) & 2)) - (v7471 + ((~(((v7472 ^ -1) | (-(v7472 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v7478 = v7477[v7575];
        int v7576 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1)) & 3) * 2)) + ((((v7468 + ((~(((v7470 ^ -1) | (-(v7470 ^ -1))) >> 31)) & 2)) - (v7471 + ((~(((v7472 ^ -1) | (-(v7472 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v7479 = v7477[v7576];
        int * v7480 = v7428->mem;
        int v7578 = v7476 * 2;
        v7480[v7578] = v7478;
        int * v7482 = v7428->mem;
        int v7581 = (v7476 * 2) + 1;
        v7482[v7581] = v7479;
        ;
      } else {
        ;
      }
      int * v7487 = v7428->mem;
      int v7586 = ((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1)) * 2;
      int v7488 = v7487[v7586];
      int v7587 = (((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1)) * 2) + 1;
      int v7489 = v7487[v7587];
      int * v7490 = v7428->cache_vals;
      int v7589 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1)) & 3) * 2)) + ((((v7468 + ((~(((v7470 ^ -1) | (-(v7470 ^ -1))) >> 31)) & 2)) - (v7471 + ((~(((v7472 ^ -1) | (-(v7472 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v7490[v7589] = v7488;
      int * v7492 = v7428->cache_vals;
      int v7592 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1)) & 3) * 2)) + ((((v7468 + ((~(((v7470 ^ -1) | (-(v7470 ^ -1))) >> 31)) & 2)) - (v7471 + ((~(((v7472 ^ -1) | (-(v7472 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v7492[v7592] = v7489;
      int * v7494 = v7428->cache_tags;
      int v7595 = (int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1);
      v7494[v7571] = v7595;
      int * v7496 = v7428->cache_dirty;
      v7496[v7571] = 0;
      int * v7498 = v7428->cache_age;
      v7498[v7571] = 1;
      int * v7500 = v7428->cache_age;
      int v7501 = v7500[v7571];
      int v7502 = v7500[v7545];
      int v7601 = v7502 + ((int)((unsigned int)(v7502 - v7501) >> 31));
      v7500[v7545] = v7601;
      int * v7504 = v7428->cache_age;
      int v7505 = v7504[v7546];
      int v7603 = v7505 + ((int)((unsigned int)(v7505 - v7501) >> 31));
      v7504[v7546] = v7603;
      int * v7507 = v7428->cache_age;
      v7507[v7571] = 0;
      v7510 = v7571;
    }
    int * v7511 = v7428->cache_vals;
    int v7606 = v7510 * 2;
    int v7512 = v7511[v7606];
    int v7607 = (v7510 * 2) + 1;
    int v7513 = v7511[v7607];
    int v7608 = (((((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1)) & 1) * 2) + ((((v7452 + ((~(((v7454 ^ -1) | (-(v7454 ^ -1))) >> 31)) & 2)) - (v7455 + ((~(((v7456 ^ -1) | (-(v7456 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7511[v7608] = v7512;
    int * v7515 = v7428->cache_vals;
    int v7611 = ((((((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1)) & 1) * 2) + ((((v7452 + ((~(((v7454 ^ -1) | (-(v7454 ^ -1))) >> 31)) & 2)) - (v7455 + ((~(((v7456 ^ -1) | (-(v7456 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7515[v7611] = v7513;
    int * v7517 = v7428->cache_tags;
    int v7614 = ((((int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1)) & 1) * 2) + ((((v7452 + ((~(((v7454 ^ -1) | (-(v7454 ^ -1))) >> 31)) & 2)) - (v7455 + ((~(((v7456 ^ -1) | (-(v7456 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7615 = (int)((unsigned int)((int)((unsigned int)v7432 >> 2)) >> 1);
    v7517[v7614] = v7615;
    int * v7519 = v7428->cache_dirty;
    v7519[v7614] = 0;
    int * v7521 = v7428->cache_age;
    v7521[v7614] = 1;
    int * v7523 = v7428->cache_age;
    int v7524 = v7523[v7614];
    int v7525 = v7523[v7543];
    int v7621 = v7525 + ((int)((unsigned int)(v7525 - v7524) >> 31));
    v7523[v7543] = v7621;
    int * v7527 = v7428->cache_age;
    int v7528 = v7527[v7544];
    int v7623 = v7528 + ((int)((unsigned int)(v7528 - v7524) >> 31));
    v7527[v7544] = v7623;
    int * v7530 = v7428->cache_age;
    v7530[v7614] = 0;
    v7533 = v7614;
  }
  int v7626 = (v7533 * 2) + (((int)((unsigned int)v7432 >> 2)) & 1);
  int v7534 = v7440[v7626];
  int * v7535 = v7428->regs;
  v7535[11] = v7534;
  struct StateT * v7537 = slot_82(v7428);
  return v7537;
}

struct StateT * slot_64(struct StateT * v6180) {
  int * v6181 = v6180->regs;
  int v6182 = v6181[12];
  bool v6197 = !(v6182 == 0);
  struct StateT * v6193;
  if (v6197) {
    int v6183 = v6180->timer;
    int v6198 = v6183 + 15;
    v6180->timer = v6198;
    int * v6185 = v6180->saved_regs;
    int v6186 = v6185[13];
    int * v6187 = v6180->regs;
    v6187[13] = v6186;
    struct StateT * v6189 = slot_65(v6180);
    v6193 = v6189;
  } else {
    struct StateT * v6191 = slot_66(v6180);
    v6193 = v6191;
  }
  return v6193;
}

struct StateT * slot_14(struct StateT * v1770) {
  int v1771 = v1770->timer;
  int v1775 = v1771 + 1;
  v1770->timer = v1775;
  struct StateT * v1773 = slot_16(v1770);
  return v1773;
}

struct StateT * slot_53(struct StateT * v5033) {
  int v5034 = v5033->timer;
  int v5144 = v5034 + 1;
  v5033->timer = v5144;
  int * v5036 = v5033->regs;
  int v5037 = v5036[13];
  int * v5038 = v5033->cache_tags;
  int v5148 = (((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1)) & 1) * 2;
  int v5039 = v5038[v5148];
  int v5149 = ((((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1)) & 1) * 2) + 1;
  int v5040 = v5038[v5149];
  int v5150 = 4 + ((((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1)) & 3) * 2);
  int v5041 = v5038[v5150];
  int v5151 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5042 = v5038[v5151];
  int v5043 = v5033->timer;
  int v5152 = v5043 + ((100 ^ (((~(((v5041 ^ ((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1))) | (-(v5041 ^ ((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1))))) >> 31)) | (~(((v5042 ^ ((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1))) | (-(v5042 ^ ((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5039 ^ ((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1))) | (-(v5039 ^ ((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1))))) >> 31)) | (~(((v5040 ^ ((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1))) | (-(v5040 ^ ((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5041 ^ ((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1))) | (-(v5041 ^ ((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1))))) >> 31)) | (~(((v5042 ^ ((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1))) | (-(v5042 ^ ((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1))))) >> 31))) & 104)))));
  v5033->timer = v5152;
  int * v5045 = v5033->cache_vals;
  bool v5153 = !(((~(((v5039 ^ ((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1))) | (-(v5039 ^ ((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1))))) >> 31)) | (~(((v5040 ^ ((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1))) | (-(v5040 ^ ((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1))))) >> 31))) == 0);
  int v5138;
  if (v5153) {
    int * v5046 = v5033->cache_age;
    int v5155 = ((((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1)) & 1) * 2) + ((~(((v5040 ^ ((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1))) | (-(v5040 ^ ((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1))))) >> 31)) & 1);
    int v5047 = v5046[v5155];
    int v5048 = v5046[v5148];
    int v5156 = v5048 + ((int)((unsigned int)(v5048 - v5047) >> 31));
    v5046[v5148] = v5156;
    int * v5050 = v5033->cache_age;
    int v5051 = v5050[v5149];
    int v5158 = v5051 + ((int)((unsigned int)(v5051 - v5047) >> 31));
    v5050[v5149] = v5158;
    int * v5053 = v5033->cache_age;
    v5053[v5155] = 0;
    v5138 = v5155;
  } else {
    int * v5056 = v5033->cache_age;
    int v5162 = (((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1)) & 1) * 2;
    int v5057 = v5056[v5162];
    int * v5058 = v5033->cache_tags;
    int v5059 = v5058[v5162];
    int v5060 = v5056[v5149];
    int v5061 = v5058[v5149];
    bool v5164 = !(((~(((v5041 ^ ((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1))) | (-(v5041 ^ ((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1))))) >> 31)) | (~(((v5042 ^ ((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1))) | (-(v5042 ^ ((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1))))) >> 31))) == 0);
    int v5115;
    if (v5164) {
      int * v5062 = v5033->cache_age;
      int v5166 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1)) & 3) * 2)) + ((~(((v5042 ^ ((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1))) | (-(v5042 ^ ((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1))))) >> 31)) & 1);
      int v5063 = v5062[v5166];
      int v5064 = v5062[v5150];
      int v5167 = v5064 + ((int)((unsigned int)(v5064 - v5063) >> 31));
      v5062[v5150] = v5167;
      int * v5066 = v5033->cache_age;
      int v5067 = v5066[v5151];
      int v5169 = v5067 + ((int)((unsigned int)(v5067 - v5063) >> 31));
      v5066[v5151] = v5169;
      int * v5069 = v5033->cache_age;
      v5069[v5166] = 0;
      v5115 = v5166;
    } else {
      int * v5072 = v5033->cache_age;
      int v5173 = 4 + ((((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1)) & 3) * 2);
      int v5073 = v5072[v5173];
      int * v5074 = v5033->cache_tags;
      int v5075 = v5074[v5173];
      int v5076 = v5072[v5151];
      int v5077 = v5074[v5151];
      int * v5078 = v5033->cache_dirty;
      int v5176 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1)) & 3) * 2)) + ((((v5073 + ((~(((v5075 ^ -1) | (-(v5075 ^ -1))) >> 31)) & 2)) - (v5076 + ((~(((v5077 ^ -1) | (-(v5077 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5079 = v5078[v5176];
      bool v5177 = !(v5079 == 0);
      if (v5177) {
        int * v5080 = v5033->cache_tags;
        int v5081 = v5080[v5176];
        int * v5082 = v5033->cache_vals;
        int v5180 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1)) & 3) * 2)) + ((((v5073 + ((~(((v5075 ^ -1) | (-(v5075 ^ -1))) >> 31)) & 2)) - (v5076 + ((~(((v5077 ^ -1) | (-(v5077 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5083 = v5082[v5180];
        int v5181 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1)) & 3) * 2)) + ((((v5073 + ((~(((v5075 ^ -1) | (-(v5075 ^ -1))) >> 31)) & 2)) - (v5076 + ((~(((v5077 ^ -1) | (-(v5077 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5084 = v5082[v5181];
        int * v5085 = v5033->mem;
        int v5183 = v5081 * 2;
        v5085[v5183] = v5083;
        int * v5087 = v5033->mem;
        int v5186 = (v5081 * 2) + 1;
        v5087[v5186] = v5084;
        ;
      } else {
        ;
      }
      int * v5092 = v5033->mem;
      int v5191 = ((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1)) * 2;
      int v5093 = v5092[v5191];
      int v5192 = (((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1)) * 2) + 1;
      int v5094 = v5092[v5192];
      int * v5095 = v5033->cache_vals;
      int v5194 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1)) & 3) * 2)) + ((((v5073 + ((~(((v5075 ^ -1) | (-(v5075 ^ -1))) >> 31)) & 2)) - (v5076 + ((~(((v5077 ^ -1) | (-(v5077 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5095[v5194] = v5093;
      int * v5097 = v5033->cache_vals;
      int v5197 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1)) & 3) * 2)) + ((((v5073 + ((~(((v5075 ^ -1) | (-(v5075 ^ -1))) >> 31)) & 2)) - (v5076 + ((~(((v5077 ^ -1) | (-(v5077 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5097[v5197] = v5094;
      int * v5099 = v5033->cache_tags;
      int v5200 = (int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1);
      v5099[v5176] = v5200;
      int * v5101 = v5033->cache_dirty;
      v5101[v5176] = 0;
      int * v5103 = v5033->cache_age;
      v5103[v5176] = 1;
      int * v5105 = v5033->cache_age;
      int v5106 = v5105[v5176];
      int v5107 = v5105[v5150];
      int v5206 = v5107 + ((int)((unsigned int)(v5107 - v5106) >> 31));
      v5105[v5150] = v5206;
      int * v5109 = v5033->cache_age;
      int v5110 = v5109[v5151];
      int v5208 = v5110 + ((int)((unsigned int)(v5110 - v5106) >> 31));
      v5109[v5151] = v5208;
      int * v5112 = v5033->cache_age;
      v5112[v5176] = 0;
      v5115 = v5176;
    }
    int * v5116 = v5033->cache_vals;
    int v5211 = v5115 * 2;
    int v5117 = v5116[v5211];
    int v5212 = (v5115 * 2) + 1;
    int v5118 = v5116[v5212];
    int v5213 = (((((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1)) & 1) * 2) + ((((v5057 + ((~(((v5059 ^ -1) | (-(v5059 ^ -1))) >> 31)) & 2)) - (v5060 + ((~(((v5061 ^ -1) | (-(v5061 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5116[v5213] = v5117;
    int * v5120 = v5033->cache_vals;
    int v5216 = ((((((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1)) & 1) * 2) + ((((v5057 + ((~(((v5059 ^ -1) | (-(v5059 ^ -1))) >> 31)) & 2)) - (v5060 + ((~(((v5061 ^ -1) | (-(v5061 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5120[v5216] = v5118;
    int * v5122 = v5033->cache_tags;
    int v5219 = ((((int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1)) & 1) * 2) + ((((v5057 + ((~(((v5059 ^ -1) | (-(v5059 ^ -1))) >> 31)) & 2)) - (v5060 + ((~(((v5061 ^ -1) | (-(v5061 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5220 = (int)((unsigned int)((int)((unsigned int)v5037 >> 2)) >> 1);
    v5122[v5219] = v5220;
    int * v5124 = v5033->cache_dirty;
    v5124[v5219] = 0;
    int * v5126 = v5033->cache_age;
    v5126[v5219] = 1;
    int * v5128 = v5033->cache_age;
    int v5129 = v5128[v5219];
    int v5130 = v5128[v5148];
    int v5226 = v5130 + ((int)((unsigned int)(v5130 - v5129) >> 31));
    v5128[v5148] = v5226;
    int * v5132 = v5033->cache_age;
    int v5133 = v5132[v5149];
    int v5228 = v5133 + ((int)((unsigned int)(v5133 - v5129) >> 31));
    v5132[v5149] = v5228;
    int * v5135 = v5033->cache_age;
    v5135[v5219] = 0;
    v5138 = v5219;
  }
  int v5231 = (v5138 * 2) + (((int)((unsigned int)v5037 >> 2)) & 1);
  int v5139 = v5045[v5231];
  int * v5140 = v5033->regs;
  v5140[13] = v5139;
  struct StateT * v5142 = slot_54(v5033);
  return v5142;
}

struct StateT * slot_80(struct StateT * v7420) {
  int v7421 = v7420->timer;
  int v7425 = v7421 + 1;
  v7420->timer = v7425;
  struct StateT * v7423 = slot_81(v7420);
  return v7423;
}

struct StateT * slot_44(struct StateT * v4411) {
  int v4412 = v4411->timer;
  int v4419 = v4412 + 1;
  v4411->timer = v4419;
  int * v4414 = v4411->regs;
  int v4415 = v4414[11];
  int v4423 = v4415 + 16;
  v4414[13] = v4423;
  struct StateT * v4417 = slot_46(v4411);
  return v4417;
}

struct StateT * slot_66(struct StateT * v6223) {
  int v6224 = v6223->timer;
  int v6228 = v6224 + 1;
  v6223->timer = v6228;
  struct StateT * v6226 = slot_67(v6223);
  return v6226;
}

struct StateT * slot_78(struct StateT * v7378) {
  int * v7379 = v7378->regs;
  int v7380 = v7379[12];
  bool v7395 = !(v7380 == 0);
  struct StateT * v7391;
  if (v7395) {
    int v7381 = v7378->timer;
    int v7396 = v7381 + 15;
    v7378->timer = v7396;
    int * v7383 = v7378->saved_regs;
    int v7384 = v7383[11];
    int * v7385 = v7378->regs;
    v7385[11] = v7384;
    struct StateT * v7387 = slot_79(v7378);
    v7391 = v7387;
  } else {
    struct StateT * v7389 = slot_80(v7378);
    v7391 = v7389;
  }
  return v7391;
}

struct StateT * slot_28(struct StateT * v3170) {
  int v3171 = v3170->timer;
  int v3178 = v3171 + 1;
  v3170->timer = v3178;
  int * v3173 = v3170->regs;
  int v3174 = v3173[11];
  int v3182 = v3174 + 8;
  v3173[13] = v3182;
  struct StateT * v3176 = slot_31(v3170);
  return v3176;
}

struct StateT * slot_32(struct StateT * v3424) {
  int v3425 = v3424->timer;
  int v3432 = v3425 + 1;
  v3424->timer = v3432;
  int * v3427 = v3424->regs;
  int v3428 = v3427[10];
  int v3436 = v3428 + 8;
  v3427[13] = v3436;
  struct StateT * v3430 = slot_29(v3424);
  return v3430;
}

struct StateT * slot_17(struct StateT * v1806) {
  int * v1807 = v1806->saved_regs;
  int * v1808 = v1806->regs;
  int v1809 = v1808[14];
  v1807[14] = v1809;
  int v1811 = v1806->timer;
  int v1925 = v1811 + 1;
  v1806->timer = v1925;
  int * v1813 = v1806->regs;
  int v1814 = v1813[11];
  int * v1815 = v1806->cache_tags;
  int v1929 = (((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1)) & 1) * 2;
  int v1816 = v1815[v1929];
  int v1930 = ((((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1817 = v1815[v1930];
  int v1931 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1)) & 3) * 2);
  int v1818 = v1815[v1931];
  int v1932 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1819 = v1815[v1932];
  int v1820 = v1806->timer;
  int v1933 = v1820 + ((100 ^ (((~(((v1818 ^ ((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1))) | (-(v1818 ^ ((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1819 ^ ((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1))) | (-(v1819 ^ ((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1816 ^ ((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1))) | (-(v1816 ^ ((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1817 ^ ((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1))) | (-(v1817 ^ ((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1818 ^ ((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1))) | (-(v1818 ^ ((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1819 ^ ((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1))) | (-(v1819 ^ ((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1806->timer = v1933;
  int * v1822 = v1806->cache_vals;
  bool v1934 = !(((~(((v1816 ^ ((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1))) | (-(v1816 ^ ((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1817 ^ ((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1))) | (-(v1817 ^ ((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v1915;
  if (v1934) {
    int * v1823 = v1806->cache_age;
    int v1936 = ((((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v1817 ^ ((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1))) | (-(v1817 ^ ((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v1824 = v1823[v1936];
    int v1825 = v1823[v1929];
    int v1937 = v1825 + ((int)((unsigned int)(v1825 - v1824) >> 31));
    v1823[v1929] = v1937;
    int * v1827 = v1806->cache_age;
    int v1828 = v1827[v1930];
    int v1939 = v1828 + ((int)((unsigned int)(v1828 - v1824) >> 31));
    v1827[v1930] = v1939;
    int * v1830 = v1806->cache_age;
    v1830[v1936] = 0;
    v1915 = v1936;
  } else {
    int * v1833 = v1806->cache_age;
    int v1943 = (((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1)) & 1) * 2;
    int v1834 = v1833[v1943];
    int * v1835 = v1806->cache_tags;
    int v1836 = v1835[v1943];
    int v1837 = v1833[v1930];
    int v1838 = v1835[v1930];
    bool v1945 = !(((~(((v1818 ^ ((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1))) | (-(v1818 ^ ((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1819 ^ ((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1))) | (-(v1819 ^ ((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v1892;
    if (v1945) {
      int * v1839 = v1806->cache_age;
      int v1947 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1819 ^ ((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1))) | (-(v1819 ^ ((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v1840 = v1839[v1947];
      int v1841 = v1839[v1931];
      int v1948 = v1841 + ((int)((unsigned int)(v1841 - v1840) >> 31));
      v1839[v1931] = v1948;
      int * v1843 = v1806->cache_age;
      int v1844 = v1843[v1932];
      int v1950 = v1844 + ((int)((unsigned int)(v1844 - v1840) >> 31));
      v1843[v1932] = v1950;
      int * v1846 = v1806->cache_age;
      v1846[v1947] = 0;
      v1892 = v1947;
    } else {
      int * v1849 = v1806->cache_age;
      int v1954 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1)) & 3) * 2);
      int v1850 = v1849[v1954];
      int * v1851 = v1806->cache_tags;
      int v1852 = v1851[v1954];
      int v1853 = v1849[v1932];
      int v1854 = v1851[v1932];
      int * v1855 = v1806->cache_dirty;
      int v1957 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1850 + ((~(((v1852 ^ -1) | (-(v1852 ^ -1))) >> 31)) & 2)) - (v1853 + ((~(((v1854 ^ -1) | (-(v1854 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1856 = v1855[v1957];
      bool v1958 = !(v1856 == 0);
      if (v1958) {
        int * v1857 = v1806->cache_tags;
        int v1858 = v1857[v1957];
        int * v1859 = v1806->cache_vals;
        int v1961 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1850 + ((~(((v1852 ^ -1) | (-(v1852 ^ -1))) >> 31)) & 2)) - (v1853 + ((~(((v1854 ^ -1) | (-(v1854 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1860 = v1859[v1961];
        int v1962 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1850 + ((~(((v1852 ^ -1) | (-(v1852 ^ -1))) >> 31)) & 2)) - (v1853 + ((~(((v1854 ^ -1) | (-(v1854 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1861 = v1859[v1962];
        int * v1862 = v1806->mem;
        int v1964 = v1858 * 2;
        v1862[v1964] = v1860;
        int * v1864 = v1806->mem;
        int v1967 = (v1858 * 2) + 1;
        v1864[v1967] = v1861;
        ;
      } else {
        ;
      }
      int * v1869 = v1806->mem;
      int v1972 = ((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1)) * 2;
      int v1870 = v1869[v1972];
      int v1973 = (((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1)) * 2) + 1;
      int v1871 = v1869[v1973];
      int * v1872 = v1806->cache_vals;
      int v1975 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1850 + ((~(((v1852 ^ -1) | (-(v1852 ^ -1))) >> 31)) & 2)) - (v1853 + ((~(((v1854 ^ -1) | (-(v1854 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1872[v1975] = v1870;
      int * v1874 = v1806->cache_vals;
      int v1978 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1850 + ((~(((v1852 ^ -1) | (-(v1852 ^ -1))) >> 31)) & 2)) - (v1853 + ((~(((v1854 ^ -1) | (-(v1854 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1874[v1978] = v1871;
      int * v1876 = v1806->cache_tags;
      int v1981 = (int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1);
      v1876[v1957] = v1981;
      int * v1878 = v1806->cache_dirty;
      v1878[v1957] = 0;
      int * v1880 = v1806->cache_age;
      v1880[v1957] = 1;
      int * v1882 = v1806->cache_age;
      int v1883 = v1882[v1957];
      int v1884 = v1882[v1931];
      int v1987 = v1884 + ((int)((unsigned int)(v1884 - v1883) >> 31));
      v1882[v1931] = v1987;
      int * v1886 = v1806->cache_age;
      int v1887 = v1886[v1932];
      int v1989 = v1887 + ((int)((unsigned int)(v1887 - v1883) >> 31));
      v1886[v1932] = v1989;
      int * v1889 = v1806->cache_age;
      v1889[v1957] = 0;
      v1892 = v1957;
    }
    int * v1893 = v1806->cache_vals;
    int v1992 = v1892 * 2;
    int v1894 = v1893[v1992];
    int v1993 = (v1892 * 2) + 1;
    int v1895 = v1893[v1993];
    int v1994 = (((((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1834 + ((~(((v1836 ^ -1) | (-(v1836 ^ -1))) >> 31)) & 2)) - (v1837 + ((~(((v1838 ^ -1) | (-(v1838 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1893[v1994] = v1894;
    int * v1897 = v1806->cache_vals;
    int v1997 = ((((((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1834 + ((~(((v1836 ^ -1) | (-(v1836 ^ -1))) >> 31)) & 2)) - (v1837 + ((~(((v1838 ^ -1) | (-(v1838 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1897[v1997] = v1895;
    int * v1899 = v1806->cache_tags;
    int v2000 = ((((int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1834 + ((~(((v1836 ^ -1) | (-(v1836 ^ -1))) >> 31)) & 2)) - (v1837 + ((~(((v1838 ^ -1) | (-(v1838 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2001 = (int)((unsigned int)((int)((unsigned int)(v1814 + 4) >> 2)) >> 1);
    v1899[v2000] = v2001;
    int * v1901 = v1806->cache_dirty;
    v1901[v2000] = 0;
    int * v1903 = v1806->cache_age;
    v1903[v2000] = 1;
    int * v1905 = v1806->cache_age;
    int v1906 = v1905[v2000];
    int v1907 = v1905[v1929];
    int v2007 = v1907 + ((int)((unsigned int)(v1907 - v1906) >> 31));
    v1905[v1929] = v2007;
    int * v1909 = v1806->cache_age;
    int v1910 = v1909[v1930];
    int v2009 = v1910 + ((int)((unsigned int)(v1910 - v1906) >> 31));
    v1909[v1930] = v2009;
    int * v1912 = v1806->cache_age;
    v1912[v2000] = 0;
    v1915 = v2000;
  }
  int v2012 = (v1915 * 2) + (((int)((unsigned int)(v1814 + 4) >> 2)) & 1);
  int v1916 = v1822[v2012];
  int * v1917 = v1806->regs;
  v1917[14] = v1916;
  struct StateT * v1919 = slot_20(v1806);
  return v1919;
}

struct StateT * slot_49(struct StateT * v4960) {
  int * v4961 = v4960->saved_regs;
  int * v4962 = v4960->regs;
  int v4963 = v4962[13];
  v4961[13] = v4963;
  int v4965 = v4960->timer;
  int v4976 = v4965 + 1;
  v4960->timer = v4976;
  int * v4967 = v4960->regs;
  int v4968 = v4967[10];
  int v4979 = v4968 + 20;
  v4967[13] = v4979;
  struct StateT * v4970 = slot_50(v4960);
  return v4970;
}

struct StateT * slot_33(struct StateT * v3439) {
  int v3440 = v3439->timer;
  int v3610 = v3440 + 1;
  v3439->timer = v3610;
  int * v3442 = v3439->regs;
  int v3443 = v3442[10];
  int v3444 = v3442[13];
  int * v3445 = v3439->cache_tags;
  int v3615 = (((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1)) & 1) * 2;
  int v3446 = v3445[v3615];
  int v3616 = ((((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v3447 = v3445[v3616];
  int v3617 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1)) & 3) * 2);
  int v3448 = v3445[v3617];
  int v3618 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3449 = v3445[v3618];
  int v3450 = v3439->timer;
  int v3619 = v3450 + ((100 ^ (((~(((v3448 ^ ((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1))) | (-(v3448 ^ ((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3449 ^ ((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1))) | (-(v3449 ^ ((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3446 ^ ((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1))) | (-(v3446 ^ ((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3447 ^ ((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1))) | (-(v3447 ^ ((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3448 ^ ((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1))) | (-(v3448 ^ ((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3449 ^ ((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1))) | (-(v3449 ^ ((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v3439->timer = v3619;
  bool v3620 = !(((~(((v3446 ^ ((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1))) | (-(v3446 ^ ((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3447 ^ ((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1))) | (-(v3447 ^ ((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v3544;
  if (v3620) {
    int * v3452 = v3439->cache_age;
    int v3622 = ((((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v3447 ^ ((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1))) | (-(v3447 ^ ((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v3453 = v3452[v3622];
    int v3454 = v3452[v3615];
    int v3623 = v3454 + ((int)((unsigned int)(v3454 - v3453) >> 31));
    v3452[v3615] = v3623;
    int * v3456 = v3439->cache_age;
    int v3457 = v3456[v3616];
    int v3625 = v3457 + ((int)((unsigned int)(v3457 - v3453) >> 31));
    v3456[v3616] = v3625;
    int * v3459 = v3439->cache_age;
    v3459[v3622] = 0;
    v3544 = v3622;
  } else {
    int * v3462 = v3439->cache_age;
    int v3629 = (((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1)) & 1) * 2;
    int v3463 = v3462[v3629];
    int * v3464 = v3439->cache_tags;
    int v3465 = v3464[v3629];
    int v3466 = v3462[v3616];
    int v3467 = v3464[v3616];
    bool v3631 = !(((~(((v3448 ^ ((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1))) | (-(v3448 ^ ((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3449 ^ ((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1))) | (-(v3449 ^ ((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v3521;
    if (v3631) {
      int * v3468 = v3439->cache_age;
      int v3633 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3449 ^ ((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1))) | (-(v3449 ^ ((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v3469 = v3468[v3633];
      int v3470 = v3468[v3617];
      int v3634 = v3470 + ((int)((unsigned int)(v3470 - v3469) >> 31));
      v3468[v3617] = v3634;
      int * v3472 = v3439->cache_age;
      int v3473 = v3472[v3618];
      int v3636 = v3473 + ((int)((unsigned int)(v3473 - v3469) >> 31));
      v3472[v3618] = v3636;
      int * v3475 = v3439->cache_age;
      v3475[v3633] = 0;
      v3521 = v3633;
    } else {
      int * v3478 = v3439->cache_age;
      int v3640 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1)) & 3) * 2);
      int v3479 = v3478[v3640];
      int * v3480 = v3439->cache_tags;
      int v3481 = v3480[v3640];
      int v3482 = v3478[v3618];
      int v3483 = v3480[v3618];
      int * v3484 = v3439->cache_dirty;
      int v3643 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3479 + ((~(((v3481 ^ -1) | (-(v3481 ^ -1))) >> 31)) & 2)) - (v3482 + ((~(((v3483 ^ -1) | (-(v3483 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3485 = v3484[v3643];
      bool v3644 = !(v3485 == 0);
      if (v3644) {
        int * v3486 = v3439->cache_tags;
        int v3487 = v3486[v3643];
        int * v3488 = v3439->cache_vals;
        int v3647 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3479 + ((~(((v3481 ^ -1) | (-(v3481 ^ -1))) >> 31)) & 2)) - (v3482 + ((~(((v3483 ^ -1) | (-(v3483 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3489 = v3488[v3647];
        int v3648 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3479 + ((~(((v3481 ^ -1) | (-(v3481 ^ -1))) >> 31)) & 2)) - (v3482 + ((~(((v3483 ^ -1) | (-(v3483 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3490 = v3488[v3648];
        int * v3491 = v3439->mem;
        int v3650 = v3487 * 2;
        v3491[v3650] = v3489;
        int * v3493 = v3439->mem;
        int v3653 = (v3487 * 2) + 1;
        v3493[v3653] = v3490;
        ;
      } else {
        ;
      }
      int * v3498 = v3439->mem;
      int v3658 = ((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1)) * 2;
      int v3499 = v3498[v3658];
      int v3659 = (((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1)) * 2) + 1;
      int v3500 = v3498[v3659];
      int * v3501 = v3439->cache_vals;
      int v3661 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3479 + ((~(((v3481 ^ -1) | (-(v3481 ^ -1))) >> 31)) & 2)) - (v3482 + ((~(((v3483 ^ -1) | (-(v3483 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3501[v3661] = v3499;
      int * v3503 = v3439->cache_vals;
      int v3664 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3479 + ((~(((v3481 ^ -1) | (-(v3481 ^ -1))) >> 31)) & 2)) - (v3482 + ((~(((v3483 ^ -1) | (-(v3483 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3503[v3664] = v3500;
      int * v3505 = v3439->cache_tags;
      int v3667 = (int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1);
      v3505[v3643] = v3667;
      int * v3507 = v3439->cache_dirty;
      v3507[v3643] = 0;
      int * v3509 = v3439->cache_age;
      v3509[v3643] = 1;
      int * v3511 = v3439->cache_age;
      int v3512 = v3511[v3643];
      int v3513 = v3511[v3617];
      int v3673 = v3513 + ((int)((unsigned int)(v3513 - v3512) >> 31));
      v3511[v3617] = v3673;
      int * v3515 = v3439->cache_age;
      int v3516 = v3515[v3618];
      int v3675 = v3516 + ((int)((unsigned int)(v3516 - v3512) >> 31));
      v3515[v3618] = v3675;
      int * v3518 = v3439->cache_age;
      v3518[v3643] = 0;
      v3521 = v3643;
    }
    int * v3522 = v3439->cache_vals;
    int v3678 = v3521 * 2;
    int v3523 = v3522[v3678];
    int v3679 = (v3521 * 2) + 1;
    int v3524 = v3522[v3679];
    int v3680 = (((((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v3463 + ((~(((v3465 ^ -1) | (-(v3465 ^ -1))) >> 31)) & 2)) - (v3466 + ((~(((v3467 ^ -1) | (-(v3467 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3522[v3680] = v3523;
    int * v3526 = v3439->cache_vals;
    int v3683 = ((((((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v3463 + ((~(((v3465 ^ -1) | (-(v3465 ^ -1))) >> 31)) & 2)) - (v3466 + ((~(((v3467 ^ -1) | (-(v3467 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3526[v3683] = v3524;
    int * v3528 = v3439->cache_tags;
    int v3686 = ((((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v3463 + ((~(((v3465 ^ -1) | (-(v3465 ^ -1))) >> 31)) & 2)) - (v3466 + ((~(((v3467 ^ -1) | (-(v3467 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3687 = (int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1);
    v3528[v3686] = v3687;
    int * v3530 = v3439->cache_dirty;
    v3530[v3686] = 0;
    int * v3532 = v3439->cache_age;
    v3532[v3686] = 1;
    int * v3534 = v3439->cache_age;
    int v3535 = v3534[v3686];
    int v3536 = v3534[v3615];
    int v3693 = v3536 + ((int)((unsigned int)(v3536 - v3535) >> 31));
    v3534[v3615] = v3693;
    int * v3538 = v3439->cache_age;
    int v3539 = v3538[v3616];
    int v3695 = v3539 + ((int)((unsigned int)(v3539 - v3535) >> 31));
    v3538[v3616] = v3695;
    int * v3541 = v3439->cache_age;
    v3541[v3686] = 0;
    v3544 = v3686;
  }
  int * v3545 = v3439->cache_vals;
  int v3698 = (v3544 * 2) + (((int)((unsigned int)(v3443 + 8) >> 2)) & 1);
  v3545[v3698] = v3444;
  int * v3547 = v3439->cache_tags;
  int v3548 = v3547[v3617];
  int v3549 = v3547[v3618];
  bool v3701 = !(((~(((v3548 ^ ((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1))) | (-(v3548 ^ ((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3549 ^ ((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1))) | (-(v3549 ^ ((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v3603;
  if (v3701) {
    int * v3550 = v3439->cache_age;
    int v3703 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3549 ^ ((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1))) | (-(v3549 ^ ((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v3551 = v3550[v3703];
    int v3552 = v3550[v3617];
    int v3704 = v3552 + ((int)((unsigned int)(v3552 - v3551) >> 31));
    v3550[v3617] = v3704;
    int * v3554 = v3439->cache_age;
    int v3555 = v3554[v3618];
    int v3706 = v3555 + ((int)((unsigned int)(v3555 - v3551) >> 31));
    v3554[v3618] = v3706;
    int * v3557 = v3439->cache_age;
    v3557[v3703] = 0;
    v3603 = v3703;
  } else {
    int * v3560 = v3439->cache_age;
    int v3710 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1)) & 3) * 2);
    int v3561 = v3560[v3710];
    int * v3562 = v3439->cache_tags;
    int v3563 = v3562[v3710];
    int v3564 = v3560[v3618];
    int v3565 = v3562[v3618];
    int * v3566 = v3439->cache_dirty;
    int v3713 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3561 + ((~(((v3563 ^ -1) | (-(v3563 ^ -1))) >> 31)) & 2)) - (v3564 + ((~(((v3565 ^ -1) | (-(v3565 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3567 = v3566[v3713];
    bool v3714 = !(v3567 == 0);
    if (v3714) {
      int * v3568 = v3439->cache_tags;
      int v3569 = v3568[v3713];
      int * v3570 = v3439->cache_vals;
      int v3717 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3561 + ((~(((v3563 ^ -1) | (-(v3563 ^ -1))) >> 31)) & 2)) - (v3564 + ((~(((v3565 ^ -1) | (-(v3565 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v3571 = v3570[v3717];
      int v3718 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3561 + ((~(((v3563 ^ -1) | (-(v3563 ^ -1))) >> 31)) & 2)) - (v3564 + ((~(((v3565 ^ -1) | (-(v3565 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v3572 = v3570[v3718];
      int * v3573 = v3439->mem;
      int v3720 = v3569 * 2;
      v3573[v3720] = v3571;
      int * v3575 = v3439->mem;
      int v3723 = (v3569 * 2) + 1;
      v3575[v3723] = v3572;
      ;
    } else {
      ;
    }
    int * v3580 = v3439->mem;
    int v3728 = ((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1)) * 2;
    int v3581 = v3580[v3728];
    int v3729 = (((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1)) * 2) + 1;
    int v3582 = v3580[v3729];
    int * v3583 = v3439->cache_vals;
    int v3731 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3561 + ((~(((v3563 ^ -1) | (-(v3563 ^ -1))) >> 31)) & 2)) - (v3564 + ((~(((v3565 ^ -1) | (-(v3565 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3583[v3731] = v3581;
    int * v3585 = v3439->cache_vals;
    int v3734 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3561 + ((~(((v3563 ^ -1) | (-(v3563 ^ -1))) >> 31)) & 2)) - (v3564 + ((~(((v3565 ^ -1) | (-(v3565 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3585[v3734] = v3582;
    int * v3587 = v3439->cache_tags;
    int v3737 = (int)((unsigned int)((int)((unsigned int)(v3443 + 8) >> 2)) >> 1);
    v3587[v3713] = v3737;
    int * v3589 = v3439->cache_dirty;
    v3589[v3713] = 0;
    int * v3591 = v3439->cache_age;
    v3591[v3713] = 1;
    int * v3593 = v3439->cache_age;
    int v3594 = v3593[v3713];
    int v3595 = v3593[v3617];
    int v3743 = v3595 + ((int)((unsigned int)(v3595 - v3594) >> 31));
    v3593[v3617] = v3743;
    int * v3597 = v3439->cache_age;
    int v3598 = v3597[v3618];
    int v3745 = v3598 + ((int)((unsigned int)(v3598 - v3594) >> 31));
    v3597[v3618] = v3745;
    int * v3600 = v3439->cache_age;
    v3600[v3713] = 0;
    v3603 = v3713;
  }
  int * v3604 = v3439->cache_vals;
  int v3748 = (v3603 * 2) + (((int)((unsigned int)(v3443 + 8) >> 2)) & 1);
  v3604[v3748] = v3444;
  int * v3606 = v3439->cache_dirty;
  v3606[v3603] = 1;
  struct StateT * v3608 = slot_34(v3439);
  return v3608;
}

struct StateT * slot_50(struct StateT * v4982) {
  int * v4983 = v4982->regs;
  int v4984 = v4983[12];
  bool v4999 = !(v4984 == 0);
  struct StateT * v4995;
  if (v4999) {
    int v4985 = v4982->timer;
    int v5000 = v4985 + 15;
    v4982->timer = v5000;
    int * v4987 = v4982->saved_regs;
    int v4988 = v4987[13];
    int * v4989 = v4982->regs;
    v4989[13] = v4988;
    struct StateT * v4991 = slot_51(v4982);
    v4995 = v4991;
  } else {
    struct StateT * v4993 = slot_52(v4982);
    v4995 = v4993;
  }
  return v4995;
}

struct StateT * slot_36(struct StateT * v3784) {
  int * v3785 = v3784->regs;
  int v3786 = v3785[12];
  bool v3801 = !(v3786 == 0);
  struct StateT * v3797;
  if (v3801) {
    int v3787 = v3784->timer;
    int v3802 = v3787 + 15;
    v3784->timer = v3802;
    int * v3789 = v3784->saved_regs;
    int v3790 = v3789[13];
    int * v3791 = v3784->regs;
    v3791[13] = v3790;
    struct StateT * v3793 = slot_37(v3784);
    v3797 = v3793;
  } else {
    struct StateT * v3795 = slot_38(v3784);
    v3797 = v3795;
  }
  return v3797;
}

struct StateT * slot_37(struct StateT * v3812) {
  int v3813 = v3812->timer;
  int v3820 = v3813 + 1;
  v3812->timer = v3820;
  int * v3815 = v3812->regs;
  int v3816 = v3815[11];
  int v3824 = v3816 + 12;
  v3815[13] = v3824;
  struct StateT * v3818 = slot_39(v3812);
  return v3818;
}

struct StateT * slot_57(struct StateT * v5581) {
  int * v5582 = v5581->regs;
  int v5583 = v5582[12];
  bool v5598 = !(v5583 == 0);
  struct StateT * v5594;
  if (v5598) {
    int v5584 = v5581->timer;
    int v5599 = v5584 + 15;
    v5581->timer = v5599;
    int * v5586 = v5581->saved_regs;
    int v5587 = v5586[13];
    int * v5588 = v5581->regs;
    v5588[13] = v5587;
    struct StateT * v5590 = slot_58(v5581);
    v5594 = v5590;
  } else {
    struct StateT * v5592 = slot_59(v5581);
    v5594 = v5592;
  }
  return v5594;
}

struct StateT * slot_68(struct StateT * v6434) {
  int v6435 = v6434->timer;
  int v6605 = v6435 + 1;
  v6434->timer = v6605;
  int * v6437 = v6434->regs;
  int v6438 = v6437[10];
  int v6439 = v6437[13];
  int * v6440 = v6434->cache_tags;
  int v6610 = (((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1)) & 1) * 2;
  int v6441 = v6440[v6610];
  int v6611 = ((((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1)) & 1) * 2) + 1;
  int v6442 = v6440[v6611];
  int v6612 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1)) & 3) * 2);
  int v6443 = v6440[v6612];
  int v6613 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v6444 = v6440[v6613];
  int v6445 = v6434->timer;
  int v6614 = v6445 + ((100 ^ (((~(((v6443 ^ ((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1))) | (-(v6443 ^ ((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v6444 ^ ((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1))) | (-(v6444 ^ ((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v6441 ^ ((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1))) | (-(v6441 ^ ((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v6442 ^ ((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1))) | (-(v6442 ^ ((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v6443 ^ ((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1))) | (-(v6443 ^ ((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v6444 ^ ((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1))) | (-(v6444 ^ ((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1))))) >> 31))) & 104)))));
  v6434->timer = v6614;
  bool v6615 = !(((~(((v6441 ^ ((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1))) | (-(v6441 ^ ((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v6442 ^ ((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1))) | (-(v6442 ^ ((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v6539;
  if (v6615) {
    int * v6447 = v6434->cache_age;
    int v6617 = ((((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1)) & 1) * 2) + ((~(((v6442 ^ ((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1))) | (-(v6442 ^ ((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v6448 = v6447[v6617];
    int v6449 = v6447[v6610];
    int v6618 = v6449 + ((int)((unsigned int)(v6449 - v6448) >> 31));
    v6447[v6610] = v6618;
    int * v6451 = v6434->cache_age;
    int v6452 = v6451[v6611];
    int v6620 = v6452 + ((int)((unsigned int)(v6452 - v6448) >> 31));
    v6451[v6611] = v6620;
    int * v6454 = v6434->cache_age;
    v6454[v6617] = 0;
    v6539 = v6617;
  } else {
    int * v6457 = v6434->cache_age;
    int v6624 = (((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1)) & 1) * 2;
    int v6458 = v6457[v6624];
    int * v6459 = v6434->cache_tags;
    int v6460 = v6459[v6624];
    int v6461 = v6457[v6611];
    int v6462 = v6459[v6611];
    bool v6626 = !(((~(((v6443 ^ ((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1))) | (-(v6443 ^ ((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v6444 ^ ((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1))) | (-(v6444 ^ ((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1))))) >> 31))) == 0);
    int v6516;
    if (v6626) {
      int * v6463 = v6434->cache_age;
      int v6628 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v6444 ^ ((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1))) | (-(v6444 ^ ((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1))))) >> 31)) & 1);
      int v6464 = v6463[v6628];
      int v6465 = v6463[v6612];
      int v6629 = v6465 + ((int)((unsigned int)(v6465 - v6464) >> 31));
      v6463[v6612] = v6629;
      int * v6467 = v6434->cache_age;
      int v6468 = v6467[v6613];
      int v6631 = v6468 + ((int)((unsigned int)(v6468 - v6464) >> 31));
      v6467[v6613] = v6631;
      int * v6470 = v6434->cache_age;
      v6470[v6628] = 0;
      v6516 = v6628;
    } else {
      int * v6473 = v6434->cache_age;
      int v6635 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1)) & 3) * 2);
      int v6474 = v6473[v6635];
      int * v6475 = v6434->cache_tags;
      int v6476 = v6475[v6635];
      int v6477 = v6473[v6613];
      int v6478 = v6475[v6613];
      int * v6479 = v6434->cache_dirty;
      int v6638 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v6474 + ((~(((v6476 ^ -1) | (-(v6476 ^ -1))) >> 31)) & 2)) - (v6477 + ((~(((v6478 ^ -1) | (-(v6478 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v6480 = v6479[v6638];
      bool v6639 = !(v6480 == 0);
      if (v6639) {
        int * v6481 = v6434->cache_tags;
        int v6482 = v6481[v6638];
        int * v6483 = v6434->cache_vals;
        int v6642 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v6474 + ((~(((v6476 ^ -1) | (-(v6476 ^ -1))) >> 31)) & 2)) - (v6477 + ((~(((v6478 ^ -1) | (-(v6478 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v6484 = v6483[v6642];
        int v6643 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v6474 + ((~(((v6476 ^ -1) | (-(v6476 ^ -1))) >> 31)) & 2)) - (v6477 + ((~(((v6478 ^ -1) | (-(v6478 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v6485 = v6483[v6643];
        int * v6486 = v6434->mem;
        int v6645 = v6482 * 2;
        v6486[v6645] = v6484;
        int * v6488 = v6434->mem;
        int v6648 = (v6482 * 2) + 1;
        v6488[v6648] = v6485;
        ;
      } else {
        ;
      }
      int * v6493 = v6434->mem;
      int v6653 = ((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1)) * 2;
      int v6494 = v6493[v6653];
      int v6654 = (((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1)) * 2) + 1;
      int v6495 = v6493[v6654];
      int * v6496 = v6434->cache_vals;
      int v6656 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v6474 + ((~(((v6476 ^ -1) | (-(v6476 ^ -1))) >> 31)) & 2)) - (v6477 + ((~(((v6478 ^ -1) | (-(v6478 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v6496[v6656] = v6494;
      int * v6498 = v6434->cache_vals;
      int v6659 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v6474 + ((~(((v6476 ^ -1) | (-(v6476 ^ -1))) >> 31)) & 2)) - (v6477 + ((~(((v6478 ^ -1) | (-(v6478 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v6498[v6659] = v6495;
      int * v6500 = v6434->cache_tags;
      int v6662 = (int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1);
      v6500[v6638] = v6662;
      int * v6502 = v6434->cache_dirty;
      v6502[v6638] = 0;
      int * v6504 = v6434->cache_age;
      v6504[v6638] = 1;
      int * v6506 = v6434->cache_age;
      int v6507 = v6506[v6638];
      int v6508 = v6506[v6612];
      int v6668 = v6508 + ((int)((unsigned int)(v6508 - v6507) >> 31));
      v6506[v6612] = v6668;
      int * v6510 = v6434->cache_age;
      int v6511 = v6510[v6613];
      int v6670 = v6511 + ((int)((unsigned int)(v6511 - v6507) >> 31));
      v6510[v6613] = v6670;
      int * v6513 = v6434->cache_age;
      v6513[v6638] = 0;
      v6516 = v6638;
    }
    int * v6517 = v6434->cache_vals;
    int v6673 = v6516 * 2;
    int v6518 = v6517[v6673];
    int v6674 = (v6516 * 2) + 1;
    int v6519 = v6517[v6674];
    int v6675 = (((((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v6458 + ((~(((v6460 ^ -1) | (-(v6460 ^ -1))) >> 31)) & 2)) - (v6461 + ((~(((v6462 ^ -1) | (-(v6462 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6517[v6675] = v6518;
    int * v6521 = v6434->cache_vals;
    int v6678 = ((((((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v6458 + ((~(((v6460 ^ -1) | (-(v6460 ^ -1))) >> 31)) & 2)) - (v6461 + ((~(((v6462 ^ -1) | (-(v6462 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6521[v6678] = v6519;
    int * v6523 = v6434->cache_tags;
    int v6681 = ((((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v6458 + ((~(((v6460 ^ -1) | (-(v6460 ^ -1))) >> 31)) & 2)) - (v6461 + ((~(((v6462 ^ -1) | (-(v6462 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6682 = (int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1);
    v6523[v6681] = v6682;
    int * v6525 = v6434->cache_dirty;
    v6525[v6681] = 0;
    int * v6527 = v6434->cache_age;
    v6527[v6681] = 1;
    int * v6529 = v6434->cache_age;
    int v6530 = v6529[v6681];
    int v6531 = v6529[v6610];
    int v6688 = v6531 + ((int)((unsigned int)(v6531 - v6530) >> 31));
    v6529[v6610] = v6688;
    int * v6533 = v6434->cache_age;
    int v6534 = v6533[v6611];
    int v6690 = v6534 + ((int)((unsigned int)(v6534 - v6530) >> 31));
    v6533[v6611] = v6690;
    int * v6536 = v6434->cache_age;
    v6536[v6681] = 0;
    v6539 = v6681;
  }
  int * v6540 = v6434->cache_vals;
  int v6693 = (v6539 * 2) + (((int)((unsigned int)(v6438 + 28) >> 2)) & 1);
  v6540[v6693] = v6439;
  int * v6542 = v6434->cache_tags;
  int v6543 = v6542[v6612];
  int v6544 = v6542[v6613];
  bool v6696 = !(((~(((v6543 ^ ((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1))) | (-(v6543 ^ ((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v6544 ^ ((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1))) | (-(v6544 ^ ((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v6598;
  if (v6696) {
    int * v6545 = v6434->cache_age;
    int v6698 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v6544 ^ ((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1))) | (-(v6544 ^ ((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v6546 = v6545[v6698];
    int v6547 = v6545[v6612];
    int v6699 = v6547 + ((int)((unsigned int)(v6547 - v6546) >> 31));
    v6545[v6612] = v6699;
    int * v6549 = v6434->cache_age;
    int v6550 = v6549[v6613];
    int v6701 = v6550 + ((int)((unsigned int)(v6550 - v6546) >> 31));
    v6549[v6613] = v6701;
    int * v6552 = v6434->cache_age;
    v6552[v6698] = 0;
    v6598 = v6698;
  } else {
    int * v6555 = v6434->cache_age;
    int v6705 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1)) & 3) * 2);
    int v6556 = v6555[v6705];
    int * v6557 = v6434->cache_tags;
    int v6558 = v6557[v6705];
    int v6559 = v6555[v6613];
    int v6560 = v6557[v6613];
    int * v6561 = v6434->cache_dirty;
    int v6708 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v6556 + ((~(((v6558 ^ -1) | (-(v6558 ^ -1))) >> 31)) & 2)) - (v6559 + ((~(((v6560 ^ -1) | (-(v6560 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6562 = v6561[v6708];
    bool v6709 = !(v6562 == 0);
    if (v6709) {
      int * v6563 = v6434->cache_tags;
      int v6564 = v6563[v6708];
      int * v6565 = v6434->cache_vals;
      int v6712 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v6556 + ((~(((v6558 ^ -1) | (-(v6558 ^ -1))) >> 31)) & 2)) - (v6559 + ((~(((v6560 ^ -1) | (-(v6560 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v6566 = v6565[v6712];
      int v6713 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v6556 + ((~(((v6558 ^ -1) | (-(v6558 ^ -1))) >> 31)) & 2)) - (v6559 + ((~(((v6560 ^ -1) | (-(v6560 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v6567 = v6565[v6713];
      int * v6568 = v6434->mem;
      int v6715 = v6564 * 2;
      v6568[v6715] = v6566;
      int * v6570 = v6434->mem;
      int v6718 = (v6564 * 2) + 1;
      v6570[v6718] = v6567;
      ;
    } else {
      ;
    }
    int * v6575 = v6434->mem;
    int v6723 = ((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1)) * 2;
    int v6576 = v6575[v6723];
    int v6724 = (((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1)) * 2) + 1;
    int v6577 = v6575[v6724];
    int * v6578 = v6434->cache_vals;
    int v6726 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v6556 + ((~(((v6558 ^ -1) | (-(v6558 ^ -1))) >> 31)) & 2)) - (v6559 + ((~(((v6560 ^ -1) | (-(v6560 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6578[v6726] = v6576;
    int * v6580 = v6434->cache_vals;
    int v6729 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v6556 + ((~(((v6558 ^ -1) | (-(v6558 ^ -1))) >> 31)) & 2)) - (v6559 + ((~(((v6560 ^ -1) | (-(v6560 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6580[v6729] = v6577;
    int * v6582 = v6434->cache_tags;
    int v6732 = (int)((unsigned int)((int)((unsigned int)(v6438 + 28) >> 2)) >> 1);
    v6582[v6708] = v6732;
    int * v6584 = v6434->cache_dirty;
    v6584[v6708] = 0;
    int * v6586 = v6434->cache_age;
    v6586[v6708] = 1;
    int * v6588 = v6434->cache_age;
    int v6589 = v6588[v6708];
    int v6590 = v6588[v6612];
    int v6738 = v6590 + ((int)((unsigned int)(v6590 - v6589) >> 31));
    v6588[v6612] = v6738;
    int * v6592 = v6434->cache_age;
    int v6593 = v6592[v6613];
    int v6740 = v6593 + ((int)((unsigned int)(v6593 - v6589) >> 31));
    v6592[v6613] = v6740;
    int * v6595 = v6434->cache_age;
    v6595[v6708] = 0;
    v6598 = v6708;
  }
  int * v6599 = v6434->cache_vals;
  int v6743 = (v6598 * 2) + (((int)((unsigned int)(v6438 + 28) >> 2)) & 1);
  v6599[v6743] = v6439;
  int * v6601 = v6434->cache_dirty;
  v6601[v6598] = 1;
  struct StateT * v6603 = slot_69(v6434);
  return v6603;
}

struct StateT * slot_59(struct StateT * v5624) {
  int v5625 = v5624->timer;
  int v5629 = v5625 + 1;
  v5624->timer = v5629;
  struct StateT * v5627 = slot_60(v5624);
  return v5627;
}

struct StateT * slot_40(struct StateT * v4038) {
  int v4039 = v4038->timer;
  int v4209 = v4039 + 1;
  v4038->timer = v4209;
  int * v4041 = v4038->regs;
  int v4042 = v4041[10];
  int v4043 = v4041[13];
  int * v4044 = v4038->cache_tags;
  int v4214 = (((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1)) & 1) * 2;
  int v4045 = v4044[v4214];
  int v4215 = ((((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4046 = v4044[v4215];
  int v4216 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1)) & 3) * 2);
  int v4047 = v4044[v4216];
  int v4217 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4048 = v4044[v4217];
  int v4049 = v4038->timer;
  int v4218 = v4049 + ((100 ^ (((~(((v4047 ^ ((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1))) | (-(v4047 ^ ((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v4048 ^ ((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1))) | (-(v4048 ^ ((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4045 ^ ((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1))) | (-(v4045 ^ ((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v4046 ^ ((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1))) | (-(v4046 ^ ((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4047 ^ ((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1))) | (-(v4047 ^ ((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v4048 ^ ((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1))) | (-(v4048 ^ ((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4038->timer = v4218;
  bool v4219 = !(((~(((v4045 ^ ((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1))) | (-(v4045 ^ ((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v4046 ^ ((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1))) | (-(v4046 ^ ((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v4143;
  if (v4219) {
    int * v4051 = v4038->cache_age;
    int v4221 = ((((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v4046 ^ ((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1))) | (-(v4046 ^ ((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v4052 = v4051[v4221];
    int v4053 = v4051[v4214];
    int v4222 = v4053 + ((int)((unsigned int)(v4053 - v4052) >> 31));
    v4051[v4214] = v4222;
    int * v4055 = v4038->cache_age;
    int v4056 = v4055[v4215];
    int v4224 = v4056 + ((int)((unsigned int)(v4056 - v4052) >> 31));
    v4055[v4215] = v4224;
    int * v4058 = v4038->cache_age;
    v4058[v4221] = 0;
    v4143 = v4221;
  } else {
    int * v4061 = v4038->cache_age;
    int v4228 = (((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1)) & 1) * 2;
    int v4062 = v4061[v4228];
    int * v4063 = v4038->cache_tags;
    int v4064 = v4063[v4228];
    int v4065 = v4061[v4215];
    int v4066 = v4063[v4215];
    bool v4230 = !(((~(((v4047 ^ ((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1))) | (-(v4047 ^ ((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v4048 ^ ((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1))) | (-(v4048 ^ ((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v4120;
    if (v4230) {
      int * v4067 = v4038->cache_age;
      int v4232 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4048 ^ ((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1))) | (-(v4048 ^ ((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v4068 = v4067[v4232];
      int v4069 = v4067[v4216];
      int v4233 = v4069 + ((int)((unsigned int)(v4069 - v4068) >> 31));
      v4067[v4216] = v4233;
      int * v4071 = v4038->cache_age;
      int v4072 = v4071[v4217];
      int v4235 = v4072 + ((int)((unsigned int)(v4072 - v4068) >> 31));
      v4071[v4217] = v4235;
      int * v4074 = v4038->cache_age;
      v4074[v4232] = 0;
      v4120 = v4232;
    } else {
      int * v4077 = v4038->cache_age;
      int v4239 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1)) & 3) * 2);
      int v4078 = v4077[v4239];
      int * v4079 = v4038->cache_tags;
      int v4080 = v4079[v4239];
      int v4081 = v4077[v4217];
      int v4082 = v4079[v4217];
      int * v4083 = v4038->cache_dirty;
      int v4242 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4078 + ((~(((v4080 ^ -1) | (-(v4080 ^ -1))) >> 31)) & 2)) - (v4081 + ((~(((v4082 ^ -1) | (-(v4082 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4084 = v4083[v4242];
      bool v4243 = !(v4084 == 0);
      if (v4243) {
        int * v4085 = v4038->cache_tags;
        int v4086 = v4085[v4242];
        int * v4087 = v4038->cache_vals;
        int v4246 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4078 + ((~(((v4080 ^ -1) | (-(v4080 ^ -1))) >> 31)) & 2)) - (v4081 + ((~(((v4082 ^ -1) | (-(v4082 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4088 = v4087[v4246];
        int v4247 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4078 + ((~(((v4080 ^ -1) | (-(v4080 ^ -1))) >> 31)) & 2)) - (v4081 + ((~(((v4082 ^ -1) | (-(v4082 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4089 = v4087[v4247];
        int * v4090 = v4038->mem;
        int v4249 = v4086 * 2;
        v4090[v4249] = v4088;
        int * v4092 = v4038->mem;
        int v4252 = (v4086 * 2) + 1;
        v4092[v4252] = v4089;
        ;
      } else {
        ;
      }
      int * v4097 = v4038->mem;
      int v4257 = ((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1)) * 2;
      int v4098 = v4097[v4257];
      int v4258 = (((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1)) * 2) + 1;
      int v4099 = v4097[v4258];
      int * v4100 = v4038->cache_vals;
      int v4260 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4078 + ((~(((v4080 ^ -1) | (-(v4080 ^ -1))) >> 31)) & 2)) - (v4081 + ((~(((v4082 ^ -1) | (-(v4082 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4100[v4260] = v4098;
      int * v4102 = v4038->cache_vals;
      int v4263 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4078 + ((~(((v4080 ^ -1) | (-(v4080 ^ -1))) >> 31)) & 2)) - (v4081 + ((~(((v4082 ^ -1) | (-(v4082 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4102[v4263] = v4099;
      int * v4104 = v4038->cache_tags;
      int v4266 = (int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1);
      v4104[v4242] = v4266;
      int * v4106 = v4038->cache_dirty;
      v4106[v4242] = 0;
      int * v4108 = v4038->cache_age;
      v4108[v4242] = 1;
      int * v4110 = v4038->cache_age;
      int v4111 = v4110[v4242];
      int v4112 = v4110[v4216];
      int v4272 = v4112 + ((int)((unsigned int)(v4112 - v4111) >> 31));
      v4110[v4216] = v4272;
      int * v4114 = v4038->cache_age;
      int v4115 = v4114[v4217];
      int v4274 = v4115 + ((int)((unsigned int)(v4115 - v4111) >> 31));
      v4114[v4217] = v4274;
      int * v4117 = v4038->cache_age;
      v4117[v4242] = 0;
      v4120 = v4242;
    }
    int * v4121 = v4038->cache_vals;
    int v4277 = v4120 * 2;
    int v4122 = v4121[v4277];
    int v4278 = (v4120 * 2) + 1;
    int v4123 = v4121[v4278];
    int v4279 = (((((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v4062 + ((~(((v4064 ^ -1) | (-(v4064 ^ -1))) >> 31)) & 2)) - (v4065 + ((~(((v4066 ^ -1) | (-(v4066 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4121[v4279] = v4122;
    int * v4125 = v4038->cache_vals;
    int v4282 = ((((((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v4062 + ((~(((v4064 ^ -1) | (-(v4064 ^ -1))) >> 31)) & 2)) - (v4065 + ((~(((v4066 ^ -1) | (-(v4066 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4125[v4282] = v4123;
    int * v4127 = v4038->cache_tags;
    int v4285 = ((((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v4062 + ((~(((v4064 ^ -1) | (-(v4064 ^ -1))) >> 31)) & 2)) - (v4065 + ((~(((v4066 ^ -1) | (-(v4066 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4286 = (int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1);
    v4127[v4285] = v4286;
    int * v4129 = v4038->cache_dirty;
    v4129[v4285] = 0;
    int * v4131 = v4038->cache_age;
    v4131[v4285] = 1;
    int * v4133 = v4038->cache_age;
    int v4134 = v4133[v4285];
    int v4135 = v4133[v4214];
    int v4292 = v4135 + ((int)((unsigned int)(v4135 - v4134) >> 31));
    v4133[v4214] = v4292;
    int * v4137 = v4038->cache_age;
    int v4138 = v4137[v4215];
    int v4294 = v4138 + ((int)((unsigned int)(v4138 - v4134) >> 31));
    v4137[v4215] = v4294;
    int * v4140 = v4038->cache_age;
    v4140[v4285] = 0;
    v4143 = v4285;
  }
  int * v4144 = v4038->cache_vals;
  int v4297 = (v4143 * 2) + (((int)((unsigned int)(v4042 + 12) >> 2)) & 1);
  v4144[v4297] = v4043;
  int * v4146 = v4038->cache_tags;
  int v4147 = v4146[v4216];
  int v4148 = v4146[v4217];
  bool v4300 = !(((~(((v4147 ^ ((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1))) | (-(v4147 ^ ((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v4148 ^ ((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1))) | (-(v4148 ^ ((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v4202;
  if (v4300) {
    int * v4149 = v4038->cache_age;
    int v4302 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4148 ^ ((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1))) | (-(v4148 ^ ((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v4150 = v4149[v4302];
    int v4151 = v4149[v4216];
    int v4303 = v4151 + ((int)((unsigned int)(v4151 - v4150) >> 31));
    v4149[v4216] = v4303;
    int * v4153 = v4038->cache_age;
    int v4154 = v4153[v4217];
    int v4305 = v4154 + ((int)((unsigned int)(v4154 - v4150) >> 31));
    v4153[v4217] = v4305;
    int * v4156 = v4038->cache_age;
    v4156[v4302] = 0;
    v4202 = v4302;
  } else {
    int * v4159 = v4038->cache_age;
    int v4309 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1)) & 3) * 2);
    int v4160 = v4159[v4309];
    int * v4161 = v4038->cache_tags;
    int v4162 = v4161[v4309];
    int v4163 = v4159[v4217];
    int v4164 = v4161[v4217];
    int * v4165 = v4038->cache_dirty;
    int v4312 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4160 + ((~(((v4162 ^ -1) | (-(v4162 ^ -1))) >> 31)) & 2)) - (v4163 + ((~(((v4164 ^ -1) | (-(v4164 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4166 = v4165[v4312];
    bool v4313 = !(v4166 == 0);
    if (v4313) {
      int * v4167 = v4038->cache_tags;
      int v4168 = v4167[v4312];
      int * v4169 = v4038->cache_vals;
      int v4316 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4160 + ((~(((v4162 ^ -1) | (-(v4162 ^ -1))) >> 31)) & 2)) - (v4163 + ((~(((v4164 ^ -1) | (-(v4164 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v4170 = v4169[v4316];
      int v4317 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4160 + ((~(((v4162 ^ -1) | (-(v4162 ^ -1))) >> 31)) & 2)) - (v4163 + ((~(((v4164 ^ -1) | (-(v4164 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v4171 = v4169[v4317];
      int * v4172 = v4038->mem;
      int v4319 = v4168 * 2;
      v4172[v4319] = v4170;
      int * v4174 = v4038->mem;
      int v4322 = (v4168 * 2) + 1;
      v4174[v4322] = v4171;
      ;
    } else {
      ;
    }
    int * v4179 = v4038->mem;
    int v4327 = ((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1)) * 2;
    int v4180 = v4179[v4327];
    int v4328 = (((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1)) * 2) + 1;
    int v4181 = v4179[v4328];
    int * v4182 = v4038->cache_vals;
    int v4330 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4160 + ((~(((v4162 ^ -1) | (-(v4162 ^ -1))) >> 31)) & 2)) - (v4163 + ((~(((v4164 ^ -1) | (-(v4164 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4182[v4330] = v4180;
    int * v4184 = v4038->cache_vals;
    int v4333 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v4160 + ((~(((v4162 ^ -1) | (-(v4162 ^ -1))) >> 31)) & 2)) - (v4163 + ((~(((v4164 ^ -1) | (-(v4164 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4184[v4333] = v4181;
    int * v4186 = v4038->cache_tags;
    int v4336 = (int)((unsigned int)((int)((unsigned int)(v4042 + 12) >> 2)) >> 1);
    v4186[v4312] = v4336;
    int * v4188 = v4038->cache_dirty;
    v4188[v4312] = 0;
    int * v4190 = v4038->cache_age;
    v4190[v4312] = 1;
    int * v4192 = v4038->cache_age;
    int v4193 = v4192[v4312];
    int v4194 = v4192[v4216];
    int v4342 = v4194 + ((int)((unsigned int)(v4194 - v4193) >> 31));
    v4192[v4216] = v4342;
    int * v4196 = v4038->cache_age;
    int v4197 = v4196[v4217];
    int v4344 = v4197 + ((int)((unsigned int)(v4197 - v4193) >> 31));
    v4196[v4217] = v4344;
    int * v4199 = v4038->cache_age;
    v4199[v4312] = 0;
    v4202 = v4312;
  }
  int * v4203 = v4038->cache_vals;
  int v4347 = (v4202 * 2) + (((int)((unsigned int)(v4042 + 12) >> 2)) & 1);
  v4203[v4347] = v4043;
  int * v4205 = v4038->cache_dirty;
  v4205[v4202] = 1;
  struct StateT * v4207 = slot_41(v4038);
  return v4207;
}

struct StateT * slot_27(struct StateT * v2967) {
  int v2968 = v2967->timer;
  int v3078 = v2968 + 1;
  v2967->timer = v3078;
  int * v2970 = v2967->regs;
  int v2971 = v2970[13];
  int * v2972 = v2967->cache_tags;
  int v3082 = (((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1)) & 1) * 2;
  int v2973 = v2972[v3082];
  int v3083 = ((((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1)) & 1) * 2) + 1;
  int v2974 = v2972[v3083];
  int v3084 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1)) & 3) * 2);
  int v2975 = v2972[v3084];
  int v3085 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2976 = v2972[v3085];
  int v2977 = v2967->timer;
  int v3086 = v2977 + ((100 ^ (((~(((v2975 ^ ((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1))) | (-(v2975 ^ ((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1))))) >> 31)) | (~(((v2976 ^ ((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1))) | (-(v2976 ^ ((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2973 ^ ((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1))) | (-(v2973 ^ ((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1))))) >> 31)) | (~(((v2974 ^ ((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1))) | (-(v2974 ^ ((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2975 ^ ((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1))) | (-(v2975 ^ ((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1))))) >> 31)) | (~(((v2976 ^ ((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1))) | (-(v2976 ^ ((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2967->timer = v3086;
  int * v2979 = v2967->cache_vals;
  bool v3087 = !(((~(((v2973 ^ ((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1))) | (-(v2973 ^ ((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1))))) >> 31)) | (~(((v2974 ^ ((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1))) | (-(v2974 ^ ((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1))))) >> 31))) == 0);
  int v3072;
  if (v3087) {
    int * v2980 = v2967->cache_age;
    int v3089 = ((((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1)) & 1) * 2) + ((~(((v2974 ^ ((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1))) | (-(v2974 ^ ((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1))))) >> 31)) & 1);
    int v2981 = v2980[v3089];
    int v2982 = v2980[v3082];
    int v3090 = v2982 + ((int)((unsigned int)(v2982 - v2981) >> 31));
    v2980[v3082] = v3090;
    int * v2984 = v2967->cache_age;
    int v2985 = v2984[v3083];
    int v3092 = v2985 + ((int)((unsigned int)(v2985 - v2981) >> 31));
    v2984[v3083] = v3092;
    int * v2987 = v2967->cache_age;
    v2987[v3089] = 0;
    v3072 = v3089;
  } else {
    int * v2990 = v2967->cache_age;
    int v3096 = (((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1)) & 1) * 2;
    int v2991 = v2990[v3096];
    int * v2992 = v2967->cache_tags;
    int v2993 = v2992[v3096];
    int v2994 = v2990[v3083];
    int v2995 = v2992[v3083];
    bool v3098 = !(((~(((v2975 ^ ((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1))) | (-(v2975 ^ ((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1))))) >> 31)) | (~(((v2976 ^ ((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1))) | (-(v2976 ^ ((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1))))) >> 31))) == 0);
    int v3049;
    if (v3098) {
      int * v2996 = v2967->cache_age;
      int v3100 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2976 ^ ((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1))) | (-(v2976 ^ ((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1))))) >> 31)) & 1);
      int v2997 = v2996[v3100];
      int v2998 = v2996[v3084];
      int v3101 = v2998 + ((int)((unsigned int)(v2998 - v2997) >> 31));
      v2996[v3084] = v3101;
      int * v3000 = v2967->cache_age;
      int v3001 = v3000[v3085];
      int v3103 = v3001 + ((int)((unsigned int)(v3001 - v2997) >> 31));
      v3000[v3085] = v3103;
      int * v3003 = v2967->cache_age;
      v3003[v3100] = 0;
      v3049 = v3100;
    } else {
      int * v3006 = v2967->cache_age;
      int v3107 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1)) & 3) * 2);
      int v3007 = v3006[v3107];
      int * v3008 = v2967->cache_tags;
      int v3009 = v3008[v3107];
      int v3010 = v3006[v3085];
      int v3011 = v3008[v3085];
      int * v3012 = v2967->cache_dirty;
      int v3110 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1)) & 3) * 2)) + ((((v3007 + ((~(((v3009 ^ -1) | (-(v3009 ^ -1))) >> 31)) & 2)) - (v3010 + ((~(((v3011 ^ -1) | (-(v3011 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3013 = v3012[v3110];
      bool v3111 = !(v3013 == 0);
      if (v3111) {
        int * v3014 = v2967->cache_tags;
        int v3015 = v3014[v3110];
        int * v3016 = v2967->cache_vals;
        int v3114 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1)) & 3) * 2)) + ((((v3007 + ((~(((v3009 ^ -1) | (-(v3009 ^ -1))) >> 31)) & 2)) - (v3010 + ((~(((v3011 ^ -1) | (-(v3011 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3017 = v3016[v3114];
        int v3115 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1)) & 3) * 2)) + ((((v3007 + ((~(((v3009 ^ -1) | (-(v3009 ^ -1))) >> 31)) & 2)) - (v3010 + ((~(((v3011 ^ -1) | (-(v3011 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3018 = v3016[v3115];
        int * v3019 = v2967->mem;
        int v3117 = v3015 * 2;
        v3019[v3117] = v3017;
        int * v3021 = v2967->mem;
        int v3120 = (v3015 * 2) + 1;
        v3021[v3120] = v3018;
        ;
      } else {
        ;
      }
      int * v3026 = v2967->mem;
      int v3125 = ((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1)) * 2;
      int v3027 = v3026[v3125];
      int v3126 = (((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1)) * 2) + 1;
      int v3028 = v3026[v3126];
      int * v3029 = v2967->cache_vals;
      int v3128 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1)) & 3) * 2)) + ((((v3007 + ((~(((v3009 ^ -1) | (-(v3009 ^ -1))) >> 31)) & 2)) - (v3010 + ((~(((v3011 ^ -1) | (-(v3011 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3029[v3128] = v3027;
      int * v3031 = v2967->cache_vals;
      int v3131 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1)) & 3) * 2)) + ((((v3007 + ((~(((v3009 ^ -1) | (-(v3009 ^ -1))) >> 31)) & 2)) - (v3010 + ((~(((v3011 ^ -1) | (-(v3011 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3031[v3131] = v3028;
      int * v3033 = v2967->cache_tags;
      int v3134 = (int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1);
      v3033[v3110] = v3134;
      int * v3035 = v2967->cache_dirty;
      v3035[v3110] = 0;
      int * v3037 = v2967->cache_age;
      v3037[v3110] = 1;
      int * v3039 = v2967->cache_age;
      int v3040 = v3039[v3110];
      int v3041 = v3039[v3084];
      int v3140 = v3041 + ((int)((unsigned int)(v3041 - v3040) >> 31));
      v3039[v3084] = v3140;
      int * v3043 = v2967->cache_age;
      int v3044 = v3043[v3085];
      int v3142 = v3044 + ((int)((unsigned int)(v3044 - v3040) >> 31));
      v3043[v3085] = v3142;
      int * v3046 = v2967->cache_age;
      v3046[v3110] = 0;
      v3049 = v3110;
    }
    int * v3050 = v2967->cache_vals;
    int v3145 = v3049 * 2;
    int v3051 = v3050[v3145];
    int v3146 = (v3049 * 2) + 1;
    int v3052 = v3050[v3146];
    int v3147 = (((((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1)) & 1) * 2) + ((((v2991 + ((~(((v2993 ^ -1) | (-(v2993 ^ -1))) >> 31)) & 2)) - (v2994 + ((~(((v2995 ^ -1) | (-(v2995 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3050[v3147] = v3051;
    int * v3054 = v2967->cache_vals;
    int v3150 = ((((((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1)) & 1) * 2) + ((((v2991 + ((~(((v2993 ^ -1) | (-(v2993 ^ -1))) >> 31)) & 2)) - (v2994 + ((~(((v2995 ^ -1) | (-(v2995 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3054[v3150] = v3052;
    int * v3056 = v2967->cache_tags;
    int v3153 = ((((int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1)) & 1) * 2) + ((((v2991 + ((~(((v2993 ^ -1) | (-(v2993 ^ -1))) >> 31)) & 2)) - (v2994 + ((~(((v2995 ^ -1) | (-(v2995 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3154 = (int)((unsigned int)((int)((unsigned int)v2971 >> 2)) >> 1);
    v3056[v3153] = v3154;
    int * v3058 = v2967->cache_dirty;
    v3058[v3153] = 0;
    int * v3060 = v2967->cache_age;
    v3060[v3153] = 1;
    int * v3062 = v2967->cache_age;
    int v3063 = v3062[v3153];
    int v3064 = v3062[v3082];
    int v3160 = v3064 + ((int)((unsigned int)(v3064 - v3063) >> 31));
    v3062[v3082] = v3160;
    int * v3066 = v2967->cache_age;
    int v3067 = v3066[v3083];
    int v3162 = v3067 + ((int)((unsigned int)(v3067 - v3063) >> 31));
    v3066[v3083] = v3162;
    int * v3069 = v2967->cache_age;
    v3069[v3153] = 0;
    v3072 = v3153;
  }
  int v3165 = (v3072 * 2) + (((int)((unsigned int)v2971 >> 2)) & 1);
  int v3073 = v2979[v3165];
  int * v3074 = v2967->regs;
  v3074[13] = v3073;
  struct StateT * v3076 = slot_30(v2967);
  return v3076;
}

struct StateT * slot_15(struct StateT * v1778) {
  int v1779 = v1778->timer;
  int v1783 = v1779 + 1;
  v1778->timer = v1783;
  struct StateT * v1781 = slot_17(v1778);
  return v1781;
}

struct StateT * slot_62(struct StateT * v6150) {
  int v6151 = v6150->timer;
  int v6155 = v6151 + 1;
  v6150->timer = v6155;
  struct StateT * v6153 = slot_63(v6150);
  return v6153;
}

struct StateT * slot_48(struct StateT * v4952) {
  int v4953 = v4952->timer;
  int v4957 = v4953 + 1;
  v4952->timer = v4957;
  struct StateT * v4955 = slot_49(v4952);
  return v4955;
}

struct StateT * slot_77(struct StateT * v7356) {
  int * v7357 = v7356->saved_regs;
  int * v7358 = v7356->regs;
  int v7359 = v7358[11];
  v7357[11] = v7359;
  int v7361 = v7356->timer;
  int v7372 = v7361 + 1;
  v7356->timer = v7372;
  int * v7363 = v7356->regs;
  int v7364 = v7363[10];
  int v7375 = v7364 + 36;
  v7363[11] = v7375;
  struct StateT * v7366 = slot_78(v7356);
  return v7366;
}

struct StateT * slot_22(struct StateT * v2879) {
  int v2880 = v2879->timer;
  int v2884 = v2880 + 1;
  v2879->timer = v2884;
  struct StateT * v2882 = slot_24(v2879);
  return v2882;
}

struct StateT * slot_35(struct StateT * v3762) {
  int * v3763 = v3762->saved_regs;
  int * v3764 = v3762->regs;
  int v3765 = v3764[13];
  v3763[13] = v3765;
  int v3767 = v3762->timer;
  int v3778 = v3767 + 1;
  v3762->timer = v3778;
  int * v3769 = v3762->regs;
  int v3770 = v3769[10];
  int v3781 = v3770 + 12;
  v3769[13] = v3781;
  struct StateT * v3772 = slot_36(v3762);
  return v3772;
}

struct StateT * slot_75(struct StateT * v7033) {
  int v7034 = v7033->timer;
  int v7204 = v7034 + 1;
  v7033->timer = v7204;
  int * v7036 = v7033->regs;
  int v7037 = v7036[10];
  int v7038 = v7036[13];
  int * v7039 = v7033->cache_tags;
  int v7209 = (((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1)) & 1) * 2;
  int v7040 = v7039[v7209];
  int v7210 = ((((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1)) & 1) * 2) + 1;
  int v7041 = v7039[v7210];
  int v7211 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1)) & 3) * 2);
  int v7042 = v7039[v7211];
  int v7212 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v7043 = v7039[v7212];
  int v7044 = v7033->timer;
  int v7213 = v7044 + ((100 ^ (((~(((v7042 ^ ((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1))) | (-(v7042 ^ ((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v7043 ^ ((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1))) | (-(v7043 ^ ((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v7040 ^ ((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1))) | (-(v7040 ^ ((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v7041 ^ ((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1))) | (-(v7041 ^ ((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v7042 ^ ((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1))) | (-(v7042 ^ ((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v7043 ^ ((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1))) | (-(v7043 ^ ((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1))))) >> 31))) & 104)))));
  v7033->timer = v7213;
  bool v7214 = !(((~(((v7040 ^ ((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1))) | (-(v7040 ^ ((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v7041 ^ ((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1))) | (-(v7041 ^ ((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v7138;
  if (v7214) {
    int * v7046 = v7033->cache_age;
    int v7216 = ((((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1)) & 1) * 2) + ((~(((v7041 ^ ((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1))) | (-(v7041 ^ ((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1))))) >> 31)) & 1);
    int v7047 = v7046[v7216];
    int v7048 = v7046[v7209];
    int v7217 = v7048 + ((int)((unsigned int)(v7048 - v7047) >> 31));
    v7046[v7209] = v7217;
    int * v7050 = v7033->cache_age;
    int v7051 = v7050[v7210];
    int v7219 = v7051 + ((int)((unsigned int)(v7051 - v7047) >> 31));
    v7050[v7210] = v7219;
    int * v7053 = v7033->cache_age;
    v7053[v7216] = 0;
    v7138 = v7216;
  } else {
    int * v7056 = v7033->cache_age;
    int v7223 = (((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1)) & 1) * 2;
    int v7057 = v7056[v7223];
    int * v7058 = v7033->cache_tags;
    int v7059 = v7058[v7223];
    int v7060 = v7056[v7210];
    int v7061 = v7058[v7210];
    bool v7225 = !(((~(((v7042 ^ ((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1))) | (-(v7042 ^ ((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v7043 ^ ((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1))) | (-(v7043 ^ ((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1))))) >> 31))) == 0);
    int v7115;
    if (v7225) {
      int * v7062 = v7033->cache_age;
      int v7227 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7043 ^ ((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1))) | (-(v7043 ^ ((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1))))) >> 31)) & 1);
      int v7063 = v7062[v7227];
      int v7064 = v7062[v7211];
      int v7228 = v7064 + ((int)((unsigned int)(v7064 - v7063) >> 31));
      v7062[v7211] = v7228;
      int * v7066 = v7033->cache_age;
      int v7067 = v7066[v7212];
      int v7230 = v7067 + ((int)((unsigned int)(v7067 - v7063) >> 31));
      v7066[v7212] = v7230;
      int * v7069 = v7033->cache_age;
      v7069[v7227] = 0;
      v7115 = v7227;
    } else {
      int * v7072 = v7033->cache_age;
      int v7234 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1)) & 3) * 2);
      int v7073 = v7072[v7234];
      int * v7074 = v7033->cache_tags;
      int v7075 = v7074[v7234];
      int v7076 = v7072[v7212];
      int v7077 = v7074[v7212];
      int * v7078 = v7033->cache_dirty;
      int v7237 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v7073 + ((~(((v7075 ^ -1) | (-(v7075 ^ -1))) >> 31)) & 2)) - (v7076 + ((~(((v7077 ^ -1) | (-(v7077 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v7079 = v7078[v7237];
      bool v7238 = !(v7079 == 0);
      if (v7238) {
        int * v7080 = v7033->cache_tags;
        int v7081 = v7080[v7237];
        int * v7082 = v7033->cache_vals;
        int v7241 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v7073 + ((~(((v7075 ^ -1) | (-(v7075 ^ -1))) >> 31)) & 2)) - (v7076 + ((~(((v7077 ^ -1) | (-(v7077 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v7083 = v7082[v7241];
        int v7242 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v7073 + ((~(((v7075 ^ -1) | (-(v7075 ^ -1))) >> 31)) & 2)) - (v7076 + ((~(((v7077 ^ -1) | (-(v7077 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v7084 = v7082[v7242];
        int * v7085 = v7033->mem;
        int v7244 = v7081 * 2;
        v7085[v7244] = v7083;
        int * v7087 = v7033->mem;
        int v7247 = (v7081 * 2) + 1;
        v7087[v7247] = v7084;
        ;
      } else {
        ;
      }
      int * v7092 = v7033->mem;
      int v7252 = ((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1)) * 2;
      int v7093 = v7092[v7252];
      int v7253 = (((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1)) * 2) + 1;
      int v7094 = v7092[v7253];
      int * v7095 = v7033->cache_vals;
      int v7255 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v7073 + ((~(((v7075 ^ -1) | (-(v7075 ^ -1))) >> 31)) & 2)) - (v7076 + ((~(((v7077 ^ -1) | (-(v7077 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v7095[v7255] = v7093;
      int * v7097 = v7033->cache_vals;
      int v7258 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v7073 + ((~(((v7075 ^ -1) | (-(v7075 ^ -1))) >> 31)) & 2)) - (v7076 + ((~(((v7077 ^ -1) | (-(v7077 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v7097[v7258] = v7094;
      int * v7099 = v7033->cache_tags;
      int v7261 = (int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1);
      v7099[v7237] = v7261;
      int * v7101 = v7033->cache_dirty;
      v7101[v7237] = 0;
      int * v7103 = v7033->cache_age;
      v7103[v7237] = 1;
      int * v7105 = v7033->cache_age;
      int v7106 = v7105[v7237];
      int v7107 = v7105[v7211];
      int v7267 = v7107 + ((int)((unsigned int)(v7107 - v7106) >> 31));
      v7105[v7211] = v7267;
      int * v7109 = v7033->cache_age;
      int v7110 = v7109[v7212];
      int v7269 = v7110 + ((int)((unsigned int)(v7110 - v7106) >> 31));
      v7109[v7212] = v7269;
      int * v7112 = v7033->cache_age;
      v7112[v7237] = 0;
      v7115 = v7237;
    }
    int * v7116 = v7033->cache_vals;
    int v7272 = v7115 * 2;
    int v7117 = v7116[v7272];
    int v7273 = (v7115 * 2) + 1;
    int v7118 = v7116[v7273];
    int v7274 = (((((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v7057 + ((~(((v7059 ^ -1) | (-(v7059 ^ -1))) >> 31)) & 2)) - (v7060 + ((~(((v7061 ^ -1) | (-(v7061 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7116[v7274] = v7117;
    int * v7120 = v7033->cache_vals;
    int v7277 = ((((((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v7057 + ((~(((v7059 ^ -1) | (-(v7059 ^ -1))) >> 31)) & 2)) - (v7060 + ((~(((v7061 ^ -1) | (-(v7061 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7120[v7277] = v7118;
    int * v7122 = v7033->cache_tags;
    int v7280 = ((((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v7057 + ((~(((v7059 ^ -1) | (-(v7059 ^ -1))) >> 31)) & 2)) - (v7060 + ((~(((v7061 ^ -1) | (-(v7061 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7281 = (int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1);
    v7122[v7280] = v7281;
    int * v7124 = v7033->cache_dirty;
    v7124[v7280] = 0;
    int * v7126 = v7033->cache_age;
    v7126[v7280] = 1;
    int * v7128 = v7033->cache_age;
    int v7129 = v7128[v7280];
    int v7130 = v7128[v7209];
    int v7287 = v7130 + ((int)((unsigned int)(v7130 - v7129) >> 31));
    v7128[v7209] = v7287;
    int * v7132 = v7033->cache_age;
    int v7133 = v7132[v7210];
    int v7289 = v7133 + ((int)((unsigned int)(v7133 - v7129) >> 31));
    v7132[v7210] = v7289;
    int * v7135 = v7033->cache_age;
    v7135[v7280] = 0;
    v7138 = v7280;
  }
  int * v7139 = v7033->cache_vals;
  int v7292 = (v7138 * 2) + (((int)((unsigned int)(v7037 + 32) >> 2)) & 1);
  v7139[v7292] = v7038;
  int * v7141 = v7033->cache_tags;
  int v7142 = v7141[v7211];
  int v7143 = v7141[v7212];
  bool v7295 = !(((~(((v7142 ^ ((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1))) | (-(v7142 ^ ((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v7143 ^ ((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1))) | (-(v7143 ^ ((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v7197;
  if (v7295) {
    int * v7144 = v7033->cache_age;
    int v7297 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7143 ^ ((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1))) | (-(v7143 ^ ((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1))))) >> 31)) & 1);
    int v7145 = v7144[v7297];
    int v7146 = v7144[v7211];
    int v7298 = v7146 + ((int)((unsigned int)(v7146 - v7145) >> 31));
    v7144[v7211] = v7298;
    int * v7148 = v7033->cache_age;
    int v7149 = v7148[v7212];
    int v7300 = v7149 + ((int)((unsigned int)(v7149 - v7145) >> 31));
    v7148[v7212] = v7300;
    int * v7151 = v7033->cache_age;
    v7151[v7297] = 0;
    v7197 = v7297;
  } else {
    int * v7154 = v7033->cache_age;
    int v7304 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1)) & 3) * 2);
    int v7155 = v7154[v7304];
    int * v7156 = v7033->cache_tags;
    int v7157 = v7156[v7304];
    int v7158 = v7154[v7212];
    int v7159 = v7156[v7212];
    int * v7160 = v7033->cache_dirty;
    int v7307 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v7155 + ((~(((v7157 ^ -1) | (-(v7157 ^ -1))) >> 31)) & 2)) - (v7158 + ((~(((v7159 ^ -1) | (-(v7159 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7161 = v7160[v7307];
    bool v7308 = !(v7161 == 0);
    if (v7308) {
      int * v7162 = v7033->cache_tags;
      int v7163 = v7162[v7307];
      int * v7164 = v7033->cache_vals;
      int v7311 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v7155 + ((~(((v7157 ^ -1) | (-(v7157 ^ -1))) >> 31)) & 2)) - (v7158 + ((~(((v7159 ^ -1) | (-(v7159 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v7165 = v7164[v7311];
      int v7312 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v7155 + ((~(((v7157 ^ -1) | (-(v7157 ^ -1))) >> 31)) & 2)) - (v7158 + ((~(((v7159 ^ -1) | (-(v7159 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v7166 = v7164[v7312];
      int * v7167 = v7033->mem;
      int v7314 = v7163 * 2;
      v7167[v7314] = v7165;
      int * v7169 = v7033->mem;
      int v7317 = (v7163 * 2) + 1;
      v7169[v7317] = v7166;
      ;
    } else {
      ;
    }
    int * v7174 = v7033->mem;
    int v7322 = ((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1)) * 2;
    int v7175 = v7174[v7322];
    int v7323 = (((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1)) * 2) + 1;
    int v7176 = v7174[v7323];
    int * v7177 = v7033->cache_vals;
    int v7325 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v7155 + ((~(((v7157 ^ -1) | (-(v7157 ^ -1))) >> 31)) & 2)) - (v7158 + ((~(((v7159 ^ -1) | (-(v7159 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7177[v7325] = v7175;
    int * v7179 = v7033->cache_vals;
    int v7328 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v7155 + ((~(((v7157 ^ -1) | (-(v7157 ^ -1))) >> 31)) & 2)) - (v7158 + ((~(((v7159 ^ -1) | (-(v7159 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7179[v7328] = v7176;
    int * v7181 = v7033->cache_tags;
    int v7331 = (int)((unsigned int)((int)((unsigned int)(v7037 + 32) >> 2)) >> 1);
    v7181[v7307] = v7331;
    int * v7183 = v7033->cache_dirty;
    v7183[v7307] = 0;
    int * v7185 = v7033->cache_age;
    v7185[v7307] = 1;
    int * v7187 = v7033->cache_age;
    int v7188 = v7187[v7307];
    int v7189 = v7187[v7211];
    int v7337 = v7189 + ((int)((unsigned int)(v7189 - v7188) >> 31));
    v7187[v7211] = v7337;
    int * v7191 = v7033->cache_age;
    int v7192 = v7191[v7212];
    int v7339 = v7192 + ((int)((unsigned int)(v7192 - v7188) >> 31));
    v7191[v7212] = v7339;
    int * v7194 = v7033->cache_age;
    v7194[v7307] = 0;
    v7197 = v7307;
  }
  int * v7198 = v7033->cache_vals;
  int v7342 = (v7197 * 2) + (((int)((unsigned int)(v7037 + 32) >> 2)) & 1);
  v7198[v7342] = v7038;
  int * v7200 = v7033->cache_dirty;
  v7200[v7197] = 1;
  struct StateT * v7202 = slot_76(v7033);
  return v7202;
}

struct StateT * slot_56(struct StateT * v5559) {
  int * v5560 = v5559->saved_regs;
  int * v5561 = v5559->regs;
  int v5562 = v5561[13];
  v5560[13] = v5562;
  int v5564 = v5559->timer;
  int v5575 = v5564 + 1;
  v5559->timer = v5575;
  int * v5566 = v5559->regs;
  int v5567 = v5566[10];
  int v5578 = v5567 + 24;
  v5566[13] = v5578;
  struct StateT * v5569 = slot_57(v5559);
  return v5569;
}

struct StateT * slot_72(struct StateT * v6807) {
  int v6808 = v6807->timer;
  int v6815 = v6808 + 1;
  v6807->timer = v6815;
  int * v6810 = v6807->regs;
  int v6811 = v6810[11];
  int v6819 = v6811 + 32;
  v6810[13] = v6819;
  struct StateT * v6813 = slot_74(v6807);
  return v6813;
}

struct StateT * slot_34(struct StateT * v3754) {
  int v3755 = v3754->timer;
  int v3759 = v3755 + 1;
  v3754->timer = v3759;
  struct StateT * v3757 = slot_35(v3754);
  return v3757;
}

struct StateT * slot_71(struct StateT * v6779) {
  int * v6780 = v6779->regs;
  int v6781 = v6780[12];
  bool v6796 = !(v6781 == 0);
  struct StateT * v6792;
  if (v6796) {
    int v6782 = v6779->timer;
    int v6797 = v6782 + 15;
    v6779->timer = v6797;
    int * v6784 = v6779->saved_regs;
    int v6785 = v6784[13];
    int * v6786 = v6779->regs;
    v6786[13] = v6785;
    struct StateT * v6788 = slot_72(v6779);
    v6792 = v6788;
  } else {
    struct StateT * v6790 = slot_73(v6779);
    v6792 = v6790;
  }
  return v6792;
}

struct StateT * slot_51(struct StateT * v5010) {
  int v5011 = v5010->timer;
  int v5018 = v5011 + 1;
  v5010->timer = v5018;
  int * v5013 = v5010->regs;
  int v5014 = v5013[11];
  int v5022 = v5014 + 20;
  v5013[13] = v5022;
  struct StateT * v5016 = slot_53(v5010);
  return v5016;
}

struct StateT * slot_52(struct StateT * v5025) {
  int v5026 = v5025->timer;
  int v5030 = v5026 + 1;
  v5025->timer = v5030;
  struct StateT * v5028 = slot_53(v5025);
  return v5028;
}

struct StateT * slot_83(struct StateT * v7946) {
  int v7947 = v7946->timer;
  int v7950 = v7947 + 1;
  v7946->timer = v7950;
  return v7946;
}

struct StateT * slot_25(struct StateT * v2917) {
  int * v2918 = v2917->saved_regs;
  int * v2919 = v2917->regs;
  int v2920 = v2919[13];
  v2918[13] = v2920;
  int v2922 = v2917->timer;
  int v2933 = v2922 + 1;
  v2917->timer = v2933;
  int * v2924 = v2917->regs;
  int v2925 = v2924[11];
  int v2936 = v2925 + 8;
  v2924[13] = v2936;
  struct StateT * v2927 = slot_27(v2917);
  return v2927;
}

struct StateT * slot_23(struct StateT * v2887) {
  int v2888 = v2887->timer;
  int v2892 = v2888 + 1;
  v2887->timer = v2892;
  struct StateT * v2890 = slot_25(v2887);
  return v2890;
}

struct StateT * slot_2(struct StateT * v409) {
  int v410 = v409->timer;
  int v520 = v410 + 1;
  v409->timer = v520;
  int * v412 = v409->regs;
  int v413 = v412[10];
  int * v414 = v409->cache_tags;
  int v524 = (((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1)) & 1) * 2;
  int v415 = v414[v524];
  int v525 = ((((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v416 = v414[v525];
  int v526 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1)) & 3) * 2);
  int v417 = v414[v526];
  int v527 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v418 = v414[v527];
  int v419 = v409->timer;
  int v528 = v419 + ((100 ^ (((~(((v417 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))) | (-(v417 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v418 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))) | (-(v418 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v415 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))) | (-(v415 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v416 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))) | (-(v416 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v417 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))) | (-(v417 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v418 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))) | (-(v418 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v409->timer = v528;
  int * v421 = v409->cache_vals;
  bool v529 = !(((~(((v415 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))) | (-(v415 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v416 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))) | (-(v416 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v514;
  if (v529) {
    int * v422 = v409->cache_age;
    int v531 = ((((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v416 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))) | (-(v416 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v423 = v422[v531];
    int v424 = v422[v524];
    int v532 = v424 + ((int)((unsigned int)(v424 - v423) >> 31));
    v422[v524] = v532;
    int * v426 = v409->cache_age;
    int v427 = v426[v525];
    int v534 = v427 + ((int)((unsigned int)(v427 - v423) >> 31));
    v426[v525] = v534;
    int * v429 = v409->cache_age;
    v429[v531] = 0;
    v514 = v531;
  } else {
    int * v432 = v409->cache_age;
    int v538 = (((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1)) & 1) * 2;
    int v433 = v432[v538];
    int * v434 = v409->cache_tags;
    int v435 = v434[v538];
    int v436 = v432[v525];
    int v437 = v434[v525];
    bool v540 = !(((~(((v417 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))) | (-(v417 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v418 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))) | (-(v418 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v491;
    if (v540) {
      int * v438 = v409->cache_age;
      int v542 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v418 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))) | (-(v418 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v439 = v438[v542];
      int v440 = v438[v526];
      int v543 = v440 + ((int)((unsigned int)(v440 - v439) >> 31));
      v438[v526] = v543;
      int * v442 = v409->cache_age;
      int v443 = v442[v527];
      int v545 = v443 + ((int)((unsigned int)(v443 - v439) >> 31));
      v442[v527] = v545;
      int * v445 = v409->cache_age;
      v445[v542] = 0;
      v491 = v542;
    } else {
      int * v448 = v409->cache_age;
      int v549 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1)) & 3) * 2);
      int v449 = v448[v549];
      int * v450 = v409->cache_tags;
      int v451 = v450[v549];
      int v452 = v448[v527];
      int v453 = v450[v527];
      int * v454 = v409->cache_dirty;
      int v552 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v449 + ((~(((v451 ^ -1) | (-(v451 ^ -1))) >> 31)) & 2)) - (v452 + ((~(((v453 ^ -1) | (-(v453 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v455 = v454[v552];
      bool v553 = !(v455 == 0);
      if (v553) {
        int * v456 = v409->cache_tags;
        int v457 = v456[v552];
        int * v458 = v409->cache_vals;
        int v556 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v449 + ((~(((v451 ^ -1) | (-(v451 ^ -1))) >> 31)) & 2)) - (v452 + ((~(((v453 ^ -1) | (-(v453 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v459 = v458[v556];
        int v557 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v449 + ((~(((v451 ^ -1) | (-(v451 ^ -1))) >> 31)) & 2)) - (v452 + ((~(((v453 ^ -1) | (-(v453 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v460 = v458[v557];
        int * v461 = v409->mem;
        int v559 = v457 * 2;
        v461[v559] = v459;
        int * v463 = v409->mem;
        int v562 = (v457 * 2) + 1;
        v463[v562] = v460;
        ;
      } else {
        ;
      }
      int * v468 = v409->mem;
      int v567 = ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1)) * 2;
      int v469 = v468[v567];
      int v568 = (((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1)) * 2) + 1;
      int v470 = v468[v568];
      int * v471 = v409->cache_vals;
      int v570 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v449 + ((~(((v451 ^ -1) | (-(v451 ^ -1))) >> 31)) & 2)) - (v452 + ((~(((v453 ^ -1) | (-(v453 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v471[v570] = v469;
      int * v473 = v409->cache_vals;
      int v573 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v449 + ((~(((v451 ^ -1) | (-(v451 ^ -1))) >> 31)) & 2)) - (v452 + ((~(((v453 ^ -1) | (-(v453 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v473[v573] = v470;
      int * v475 = v409->cache_tags;
      int v576 = (int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1);
      v475[v552] = v576;
      int * v477 = v409->cache_dirty;
      v477[v552] = 0;
      int * v479 = v409->cache_age;
      v479[v552] = 1;
      int * v481 = v409->cache_age;
      int v482 = v481[v552];
      int v483 = v481[v526];
      int v582 = v483 + ((int)((unsigned int)(v483 - v482) >> 31));
      v481[v526] = v582;
      int * v485 = v409->cache_age;
      int v486 = v485[v527];
      int v584 = v486 + ((int)((unsigned int)(v486 - v482) >> 31));
      v485[v527] = v584;
      int * v488 = v409->cache_age;
      v488[v552] = 0;
      v491 = v552;
    }
    int * v492 = v409->cache_vals;
    int v587 = v491 * 2;
    int v493 = v492[v587];
    int v588 = (v491 * 2) + 1;
    int v494 = v492[v588];
    int v589 = (((((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v433 + ((~(((v435 ^ -1) | (-(v435 ^ -1))) >> 31)) & 2)) - (v436 + ((~(((v437 ^ -1) | (-(v437 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v492[v589] = v493;
    int * v496 = v409->cache_vals;
    int v592 = ((((((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v433 + ((~(((v435 ^ -1) | (-(v435 ^ -1))) >> 31)) & 2)) - (v436 + ((~(((v437 ^ -1) | (-(v437 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v496[v592] = v494;
    int * v498 = v409->cache_tags;
    int v595 = ((((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v433 + ((~(((v435 ^ -1) | (-(v435 ^ -1))) >> 31)) & 2)) - (v436 + ((~(((v437 ^ -1) | (-(v437 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v596 = (int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1);
    v498[v595] = v596;
    int * v500 = v409->cache_dirty;
    v500[v595] = 0;
    int * v502 = v409->cache_age;
    v502[v595] = 1;
    int * v504 = v409->cache_age;
    int v505 = v504[v595];
    int v506 = v504[v524];
    int v602 = v506 + ((int)((unsigned int)(v506 - v505) >> 31));
    v504[v524] = v602;
    int * v508 = v409->cache_age;
    int v509 = v508[v525];
    int v604 = v509 + ((int)((unsigned int)(v509 - v505) >> 31));
    v508[v525] = v604;
    int * v511 = v409->cache_age;
    v511[v595] = 0;
    v514 = v595;
  }
  int v607 = (v514 * 2) + (((int)((unsigned int)(v413 + 4) >> 2)) & 1);
  int v515 = v421[v607];
  int * v516 = v409->regs;
  v516[14] = v515;
  struct StateT * v518 = slot_3(v409);
  return v518;
}

struct StateT * slot_21(struct StateT * v2564) {
  int v2565 = v2564->timer;
  int v2735 = v2565 + 1;
  v2564->timer = v2735;
  int * v2567 = v2564->regs;
  int v2568 = v2567[10];
  int v2569 = v2567[14];
  int * v2570 = v2564->cache_tags;
  int v2740 = (((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1)) & 1) * 2;
  int v2571 = v2570[v2740];
  int v2741 = ((((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2572 = v2570[v2741];
  int v2742 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1)) & 3) * 2);
  int v2573 = v2570[v2742];
  int v2743 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2574 = v2570[v2743];
  int v2575 = v2564->timer;
  int v2744 = v2575 + ((100 ^ (((~(((v2573 ^ ((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1))) | (-(v2573 ^ ((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2574 ^ ((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1))) | (-(v2574 ^ ((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2571 ^ ((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1))) | (-(v2571 ^ ((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2572 ^ ((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1))) | (-(v2572 ^ ((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2573 ^ ((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1))) | (-(v2573 ^ ((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2574 ^ ((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1))) | (-(v2574 ^ ((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2564->timer = v2744;
  bool v2745 = !(((~(((v2571 ^ ((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1))) | (-(v2571 ^ ((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2572 ^ ((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1))) | (-(v2572 ^ ((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v2669;
  if (v2745) {
    int * v2577 = v2564->cache_age;
    int v2747 = ((((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v2572 ^ ((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1))) | (-(v2572 ^ ((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v2578 = v2577[v2747];
    int v2579 = v2577[v2740];
    int v2748 = v2579 + ((int)((unsigned int)(v2579 - v2578) >> 31));
    v2577[v2740] = v2748;
    int * v2581 = v2564->cache_age;
    int v2582 = v2581[v2741];
    int v2750 = v2582 + ((int)((unsigned int)(v2582 - v2578) >> 31));
    v2581[v2741] = v2750;
    int * v2584 = v2564->cache_age;
    v2584[v2747] = 0;
    v2669 = v2747;
  } else {
    int * v2587 = v2564->cache_age;
    int v2754 = (((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1)) & 1) * 2;
    int v2588 = v2587[v2754];
    int * v2589 = v2564->cache_tags;
    int v2590 = v2589[v2754];
    int v2591 = v2587[v2741];
    int v2592 = v2589[v2741];
    bool v2756 = !(((~(((v2573 ^ ((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1))) | (-(v2573 ^ ((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2574 ^ ((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1))) | (-(v2574 ^ ((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v2646;
    if (v2756) {
      int * v2593 = v2564->cache_age;
      int v2758 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2574 ^ ((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1))) | (-(v2574 ^ ((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v2594 = v2593[v2758];
      int v2595 = v2593[v2742];
      int v2759 = v2595 + ((int)((unsigned int)(v2595 - v2594) >> 31));
      v2593[v2742] = v2759;
      int * v2597 = v2564->cache_age;
      int v2598 = v2597[v2743];
      int v2761 = v2598 + ((int)((unsigned int)(v2598 - v2594) >> 31));
      v2597[v2743] = v2761;
      int * v2600 = v2564->cache_age;
      v2600[v2758] = 0;
      v2646 = v2758;
    } else {
      int * v2603 = v2564->cache_age;
      int v2765 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1)) & 3) * 2);
      int v2604 = v2603[v2765];
      int * v2605 = v2564->cache_tags;
      int v2606 = v2605[v2765];
      int v2607 = v2603[v2743];
      int v2608 = v2605[v2743];
      int * v2609 = v2564->cache_dirty;
      int v2768 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2604 + ((~(((v2606 ^ -1) | (-(v2606 ^ -1))) >> 31)) & 2)) - (v2607 + ((~(((v2608 ^ -1) | (-(v2608 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2610 = v2609[v2768];
      bool v2769 = !(v2610 == 0);
      if (v2769) {
        int * v2611 = v2564->cache_tags;
        int v2612 = v2611[v2768];
        int * v2613 = v2564->cache_vals;
        int v2772 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2604 + ((~(((v2606 ^ -1) | (-(v2606 ^ -1))) >> 31)) & 2)) - (v2607 + ((~(((v2608 ^ -1) | (-(v2608 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2614 = v2613[v2772];
        int v2773 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2604 + ((~(((v2606 ^ -1) | (-(v2606 ^ -1))) >> 31)) & 2)) - (v2607 + ((~(((v2608 ^ -1) | (-(v2608 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2615 = v2613[v2773];
        int * v2616 = v2564->mem;
        int v2775 = v2612 * 2;
        v2616[v2775] = v2614;
        int * v2618 = v2564->mem;
        int v2778 = (v2612 * 2) + 1;
        v2618[v2778] = v2615;
        ;
      } else {
        ;
      }
      int * v2623 = v2564->mem;
      int v2783 = ((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1)) * 2;
      int v2624 = v2623[v2783];
      int v2784 = (((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1)) * 2) + 1;
      int v2625 = v2623[v2784];
      int * v2626 = v2564->cache_vals;
      int v2786 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2604 + ((~(((v2606 ^ -1) | (-(v2606 ^ -1))) >> 31)) & 2)) - (v2607 + ((~(((v2608 ^ -1) | (-(v2608 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2626[v2786] = v2624;
      int * v2628 = v2564->cache_vals;
      int v2789 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2604 + ((~(((v2606 ^ -1) | (-(v2606 ^ -1))) >> 31)) & 2)) - (v2607 + ((~(((v2608 ^ -1) | (-(v2608 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2628[v2789] = v2625;
      int * v2630 = v2564->cache_tags;
      int v2792 = (int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1);
      v2630[v2768] = v2792;
      int * v2632 = v2564->cache_dirty;
      v2632[v2768] = 0;
      int * v2634 = v2564->cache_age;
      v2634[v2768] = 1;
      int * v2636 = v2564->cache_age;
      int v2637 = v2636[v2768];
      int v2638 = v2636[v2742];
      int v2798 = v2638 + ((int)((unsigned int)(v2638 - v2637) >> 31));
      v2636[v2742] = v2798;
      int * v2640 = v2564->cache_age;
      int v2641 = v2640[v2743];
      int v2800 = v2641 + ((int)((unsigned int)(v2641 - v2637) >> 31));
      v2640[v2743] = v2800;
      int * v2643 = v2564->cache_age;
      v2643[v2768] = 0;
      v2646 = v2768;
    }
    int * v2647 = v2564->cache_vals;
    int v2803 = v2646 * 2;
    int v2648 = v2647[v2803];
    int v2804 = (v2646 * 2) + 1;
    int v2649 = v2647[v2804];
    int v2805 = (((((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v2588 + ((~(((v2590 ^ -1) | (-(v2590 ^ -1))) >> 31)) & 2)) - (v2591 + ((~(((v2592 ^ -1) | (-(v2592 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2647[v2805] = v2648;
    int * v2651 = v2564->cache_vals;
    int v2808 = ((((((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v2588 + ((~(((v2590 ^ -1) | (-(v2590 ^ -1))) >> 31)) & 2)) - (v2591 + ((~(((v2592 ^ -1) | (-(v2592 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2651[v2808] = v2649;
    int * v2653 = v2564->cache_tags;
    int v2811 = ((((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v2588 + ((~(((v2590 ^ -1) | (-(v2590 ^ -1))) >> 31)) & 2)) - (v2591 + ((~(((v2592 ^ -1) | (-(v2592 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2812 = (int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1);
    v2653[v2811] = v2812;
    int * v2655 = v2564->cache_dirty;
    v2655[v2811] = 0;
    int * v2657 = v2564->cache_age;
    v2657[v2811] = 1;
    int * v2659 = v2564->cache_age;
    int v2660 = v2659[v2811];
    int v2661 = v2659[v2740];
    int v2818 = v2661 + ((int)((unsigned int)(v2661 - v2660) >> 31));
    v2659[v2740] = v2818;
    int * v2663 = v2564->cache_age;
    int v2664 = v2663[v2741];
    int v2820 = v2664 + ((int)((unsigned int)(v2664 - v2660) >> 31));
    v2663[v2741] = v2820;
    int * v2666 = v2564->cache_age;
    v2666[v2811] = 0;
    v2669 = v2811;
  }
  int * v2670 = v2564->cache_vals;
  int v2823 = (v2669 * 2) + (((int)((unsigned int)(v2568 + 4) >> 2)) & 1);
  v2670[v2823] = v2569;
  int * v2672 = v2564->cache_tags;
  int v2673 = v2672[v2742];
  int v2674 = v2672[v2743];
  bool v2826 = !(((~(((v2673 ^ ((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1))) | (-(v2673 ^ ((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2674 ^ ((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1))) | (-(v2674 ^ ((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v2728;
  if (v2826) {
    int * v2675 = v2564->cache_age;
    int v2828 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2674 ^ ((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1))) | (-(v2674 ^ ((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v2676 = v2675[v2828];
    int v2677 = v2675[v2742];
    int v2829 = v2677 + ((int)((unsigned int)(v2677 - v2676) >> 31));
    v2675[v2742] = v2829;
    int * v2679 = v2564->cache_age;
    int v2680 = v2679[v2743];
    int v2831 = v2680 + ((int)((unsigned int)(v2680 - v2676) >> 31));
    v2679[v2743] = v2831;
    int * v2682 = v2564->cache_age;
    v2682[v2828] = 0;
    v2728 = v2828;
  } else {
    int * v2685 = v2564->cache_age;
    int v2835 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1)) & 3) * 2);
    int v2686 = v2685[v2835];
    int * v2687 = v2564->cache_tags;
    int v2688 = v2687[v2835];
    int v2689 = v2685[v2743];
    int v2690 = v2687[v2743];
    int * v2691 = v2564->cache_dirty;
    int v2838 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2686 + ((~(((v2688 ^ -1) | (-(v2688 ^ -1))) >> 31)) & 2)) - (v2689 + ((~(((v2690 ^ -1) | (-(v2690 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2692 = v2691[v2838];
    bool v2839 = !(v2692 == 0);
    if (v2839) {
      int * v2693 = v2564->cache_tags;
      int v2694 = v2693[v2838];
      int * v2695 = v2564->cache_vals;
      int v2842 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2686 + ((~(((v2688 ^ -1) | (-(v2688 ^ -1))) >> 31)) & 2)) - (v2689 + ((~(((v2690 ^ -1) | (-(v2690 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v2696 = v2695[v2842];
      int v2843 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2686 + ((~(((v2688 ^ -1) | (-(v2688 ^ -1))) >> 31)) & 2)) - (v2689 + ((~(((v2690 ^ -1) | (-(v2690 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v2697 = v2695[v2843];
      int * v2698 = v2564->mem;
      int v2845 = v2694 * 2;
      v2698[v2845] = v2696;
      int * v2700 = v2564->mem;
      int v2848 = (v2694 * 2) + 1;
      v2700[v2848] = v2697;
      ;
    } else {
      ;
    }
    int * v2705 = v2564->mem;
    int v2853 = ((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1)) * 2;
    int v2706 = v2705[v2853];
    int v2854 = (((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1)) * 2) + 1;
    int v2707 = v2705[v2854];
    int * v2708 = v2564->cache_vals;
    int v2856 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2686 + ((~(((v2688 ^ -1) | (-(v2688 ^ -1))) >> 31)) & 2)) - (v2689 + ((~(((v2690 ^ -1) | (-(v2690 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2708[v2856] = v2706;
    int * v2710 = v2564->cache_vals;
    int v2859 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2686 + ((~(((v2688 ^ -1) | (-(v2688 ^ -1))) >> 31)) & 2)) - (v2689 + ((~(((v2690 ^ -1) | (-(v2690 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2710[v2859] = v2707;
    int * v2712 = v2564->cache_tags;
    int v2862 = (int)((unsigned int)((int)((unsigned int)(v2568 + 4) >> 2)) >> 1);
    v2712[v2838] = v2862;
    int * v2714 = v2564->cache_dirty;
    v2714[v2838] = 0;
    int * v2716 = v2564->cache_age;
    v2716[v2838] = 1;
    int * v2718 = v2564->cache_age;
    int v2719 = v2718[v2838];
    int v2720 = v2718[v2742];
    int v2868 = v2720 + ((int)((unsigned int)(v2720 - v2719) >> 31));
    v2718[v2742] = v2868;
    int * v2722 = v2564->cache_age;
    int v2723 = v2722[v2743];
    int v2870 = v2723 + ((int)((unsigned int)(v2723 - v2719) >> 31));
    v2722[v2743] = v2870;
    int * v2725 = v2564->cache_age;
    v2725[v2838] = 0;
    v2728 = v2838;
  }
  int * v2729 = v2564->cache_vals;
  int v2873 = (v2728 * 2) + (((int)((unsigned int)(v2568 + 4) >> 2)) & 1);
  v2729[v2873] = v2569;
  int * v2731 = v2564->cache_dirty;
  v2731[v2728] = 1;
  struct StateT * v2733 = slot_23(v2564);
  return v2733;
}

struct StateT * slot_3(struct StateT * v613) {
  int v614 = v613->timer;
  int v724 = v614 + 1;
  v613->timer = v724;
  int * v616 = v613->regs;
  int v617 = v616[13];
  int * v618 = v613->cache_tags;
  int v728 = (((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1)) & 1) * 2;
  int v619 = v618[v728];
  int v729 = ((((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v620 = v618[v729];
  int v730 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1)) & 3) * 2);
  int v621 = v618[v730];
  int v731 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v622 = v618[v731];
  int v623 = v613->timer;
  int v732 = v623 + ((100 ^ (((~(((v621 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))) | (-(v621 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v622 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))) | (-(v622 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v619 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))) | (-(v619 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v620 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))) | (-(v620 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v621 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))) | (-(v621 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v622 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))) | (-(v622 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v613->timer = v732;
  int * v625 = v613->cache_vals;
  bool v733 = !(((~(((v619 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))) | (-(v619 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v620 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))) | (-(v620 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v718;
  if (v733) {
    int * v626 = v613->cache_age;
    int v735 = ((((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v620 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))) | (-(v620 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v627 = v626[v735];
    int v628 = v626[v728];
    int v736 = v628 + ((int)((unsigned int)(v628 - v627) >> 31));
    v626[v728] = v736;
    int * v630 = v613->cache_age;
    int v631 = v630[v729];
    int v738 = v631 + ((int)((unsigned int)(v631 - v627) >> 31));
    v630[v729] = v738;
    int * v633 = v613->cache_age;
    v633[v735] = 0;
    v718 = v735;
  } else {
    int * v636 = v613->cache_age;
    int v742 = (((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1)) & 1) * 2;
    int v637 = v636[v742];
    int * v638 = v613->cache_tags;
    int v639 = v638[v742];
    int v640 = v636[v729];
    int v641 = v638[v729];
    bool v744 = !(((~(((v621 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))) | (-(v621 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v622 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))) | (-(v622 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v695;
    if (v744) {
      int * v642 = v613->cache_age;
      int v746 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v622 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))) | (-(v622 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v643 = v642[v746];
      int v644 = v642[v730];
      int v747 = v644 + ((int)((unsigned int)(v644 - v643) >> 31));
      v642[v730] = v747;
      int * v646 = v613->cache_age;
      int v647 = v646[v731];
      int v749 = v647 + ((int)((unsigned int)(v647 - v643) >> 31));
      v646[v731] = v749;
      int * v649 = v613->cache_age;
      v649[v746] = 0;
      v695 = v746;
    } else {
      int * v652 = v613->cache_age;
      int v753 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1)) & 3) * 2);
      int v653 = v652[v753];
      int * v654 = v613->cache_tags;
      int v655 = v654[v753];
      int v656 = v652[v731];
      int v657 = v654[v731];
      int * v658 = v613->cache_dirty;
      int v756 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v653 + ((~(((v655 ^ -1) | (-(v655 ^ -1))) >> 31)) & 2)) - (v656 + ((~(((v657 ^ -1) | (-(v657 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v659 = v658[v756];
      bool v757 = !(v659 == 0);
      if (v757) {
        int * v660 = v613->cache_tags;
        int v661 = v660[v756];
        int * v662 = v613->cache_vals;
        int v760 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v653 + ((~(((v655 ^ -1) | (-(v655 ^ -1))) >> 31)) & 2)) - (v656 + ((~(((v657 ^ -1) | (-(v657 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v663 = v662[v760];
        int v761 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v653 + ((~(((v655 ^ -1) | (-(v655 ^ -1))) >> 31)) & 2)) - (v656 + ((~(((v657 ^ -1) | (-(v657 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v664 = v662[v761];
        int * v665 = v613->mem;
        int v763 = v661 * 2;
        v665[v763] = v663;
        int * v667 = v613->mem;
        int v766 = (v661 * 2) + 1;
        v667[v766] = v664;
        ;
      } else {
        ;
      }
      int * v672 = v613->mem;
      int v771 = ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1)) * 2;
      int v673 = v672[v771];
      int v772 = (((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1)) * 2) + 1;
      int v674 = v672[v772];
      int * v675 = v613->cache_vals;
      int v774 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v653 + ((~(((v655 ^ -1) | (-(v655 ^ -1))) >> 31)) & 2)) - (v656 + ((~(((v657 ^ -1) | (-(v657 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v675[v774] = v673;
      int * v677 = v613->cache_vals;
      int v777 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v653 + ((~(((v655 ^ -1) | (-(v655 ^ -1))) >> 31)) & 2)) - (v656 + ((~(((v657 ^ -1) | (-(v657 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v677[v777] = v674;
      int * v679 = v613->cache_tags;
      int v780 = (int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1);
      v679[v756] = v780;
      int * v681 = v613->cache_dirty;
      v681[v756] = 0;
      int * v683 = v613->cache_age;
      v683[v756] = 1;
      int * v685 = v613->cache_age;
      int v686 = v685[v756];
      int v687 = v685[v730];
      int v786 = v687 + ((int)((unsigned int)(v687 - v686) >> 31));
      v685[v730] = v786;
      int * v689 = v613->cache_age;
      int v690 = v689[v731];
      int v788 = v690 + ((int)((unsigned int)(v690 - v686) >> 31));
      v689[v731] = v788;
      int * v692 = v613->cache_age;
      v692[v756] = 0;
      v695 = v756;
    }
    int * v696 = v613->cache_vals;
    int v791 = v695 * 2;
    int v697 = v696[v791];
    int v792 = (v695 * 2) + 1;
    int v698 = v696[v792];
    int v793 = (((((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v637 + ((~(((v639 ^ -1) | (-(v639 ^ -1))) >> 31)) & 2)) - (v640 + ((~(((v641 ^ -1) | (-(v641 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v696[v793] = v697;
    int * v700 = v613->cache_vals;
    int v796 = ((((((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v637 + ((~(((v639 ^ -1) | (-(v639 ^ -1))) >> 31)) & 2)) - (v640 + ((~(((v641 ^ -1) | (-(v641 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v700[v796] = v698;
    int * v702 = v613->cache_tags;
    int v799 = ((((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v637 + ((~(((v639 ^ -1) | (-(v639 ^ -1))) >> 31)) & 2)) - (v640 + ((~(((v641 ^ -1) | (-(v641 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v800 = (int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1);
    v702[v799] = v800;
    int * v704 = v613->cache_dirty;
    v704[v799] = 0;
    int * v706 = v613->cache_age;
    v706[v799] = 1;
    int * v708 = v613->cache_age;
    int v709 = v708[v799];
    int v710 = v708[v728];
    int v806 = v710 + ((int)((unsigned int)(v710 - v709) >> 31));
    v708[v728] = v806;
    int * v712 = v613->cache_age;
    int v713 = v712[v729];
    int v808 = v713 + ((int)((unsigned int)(v713 - v709) >> 31));
    v712[v729] = v808;
    int * v715 = v613->cache_age;
    v715[v799] = 0;
    v718 = v799;
  }
  int v811 = (v718 * 2) + (((int)((unsigned int)(v617 + 4) >> 2)) & 1);
  int v719 = v625[v811];
  int * v720 = v613->regs;
  v720[13] = v719;
  struct StateT * v722 = slot_4(v613);
  return v722;
}

struct StateT * slot_45(struct StateT * v4426) {
  int v4427 = v4426->timer;
  int v4431 = v4427 + 1;
  v4426->timer = v4431;
  struct StateT * v4429 = slot_46(v4426);
  return v4429;
}

struct StateT * slot_73(struct StateT * v6822) {
  int v6823 = v6822->timer;
  int v6827 = v6823 + 1;
  v6822->timer = v6827;
  struct StateT * v6825 = slot_74(v6822);
  return v6825;
}

struct StateT * slot_1(struct StateT * v205) {
  int v206 = v205->timer;
  int v316 = v206 + 1;
  v205->timer = v316;
  int * v208 = v205->regs;
  int v209 = v208[10];
  int * v210 = v205->cache_tags;
  int v320 = (((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1)) & 1) * 2;
  int v211 = v210[v320];
  int v321 = ((((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1)) & 1) * 2) + 1;
  int v212 = v210[v321];
  int v322 = 4 + ((((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1)) & 3) * 2);
  int v213 = v210[v322];
  int v323 = (4 + ((((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v214 = v210[v323];
  int v215 = v205->timer;
  int v324 = v215 + ((100 ^ (((~(((v213 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))) | (-(v213 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))))) >> 31)) | (~(((v214 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))) | (-(v214 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v211 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))) | (-(v211 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))))) >> 31)) | (~(((v212 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))) | (-(v212 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v213 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))) | (-(v213 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))))) >> 31)) | (~(((v214 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))) | (-(v214 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))))) >> 31))) & 104)))));
  v205->timer = v324;
  int * v217 = v205->cache_vals;
  bool v325 = !(((~(((v211 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))) | (-(v211 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))))) >> 31)) | (~(((v212 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))) | (-(v212 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))))) >> 31))) == 0);
  int v310;
  if (v325) {
    int * v218 = v205->cache_age;
    int v327 = ((((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1)) & 1) * 2) + ((~(((v212 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))) | (-(v212 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))))) >> 31)) & 1);
    int v219 = v218[v327];
    int v220 = v218[v320];
    int v328 = v220 + ((int)((unsigned int)(v220 - v219) >> 31));
    v218[v320] = v328;
    int * v222 = v205->cache_age;
    int v223 = v222[v321];
    int v330 = v223 + ((int)((unsigned int)(v223 - v219) >> 31));
    v222[v321] = v330;
    int * v225 = v205->cache_age;
    v225[v327] = 0;
    v310 = v327;
  } else {
    int * v228 = v205->cache_age;
    int v334 = (((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1)) & 1) * 2;
    int v229 = v228[v334];
    int * v230 = v205->cache_tags;
    int v231 = v230[v334];
    int v232 = v228[v321];
    int v233 = v230[v321];
    bool v336 = !(((~(((v213 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))) | (-(v213 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))))) >> 31)) | (~(((v214 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))) | (-(v214 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))))) >> 31))) == 0);
    int v287;
    if (v336) {
      int * v234 = v205->cache_age;
      int v338 = (4 + ((((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1)) & 3) * 2)) + ((~(((v214 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))) | (-(v214 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))))) >> 31)) & 1);
      int v235 = v234[v338];
      int v236 = v234[v322];
      int v339 = v236 + ((int)((unsigned int)(v236 - v235) >> 31));
      v234[v322] = v339;
      int * v238 = v205->cache_age;
      int v239 = v238[v323];
      int v341 = v239 + ((int)((unsigned int)(v239 - v235) >> 31));
      v238[v323] = v341;
      int * v241 = v205->cache_age;
      v241[v338] = 0;
      v287 = v338;
    } else {
      int * v244 = v205->cache_age;
      int v345 = 4 + ((((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1)) & 3) * 2);
      int v245 = v244[v345];
      int * v246 = v205->cache_tags;
      int v247 = v246[v345];
      int v248 = v244[v323];
      int v249 = v246[v323];
      int * v250 = v205->cache_dirty;
      int v348 = (4 + ((((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1)) & 3) * 2)) + ((((v245 + ((~(((v247 ^ -1) | (-(v247 ^ -1))) >> 31)) & 2)) - (v248 + ((~(((v249 ^ -1) | (-(v249 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v251 = v250[v348];
      bool v349 = !(v251 == 0);
      if (v349) {
        int * v252 = v205->cache_tags;
        int v253 = v252[v348];
        int * v254 = v205->cache_vals;
        int v352 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1)) & 3) * 2)) + ((((v245 + ((~(((v247 ^ -1) | (-(v247 ^ -1))) >> 31)) & 2)) - (v248 + ((~(((v249 ^ -1) | (-(v249 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v255 = v254[v352];
        int v353 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1)) & 3) * 2)) + ((((v245 + ((~(((v247 ^ -1) | (-(v247 ^ -1))) >> 31)) & 2)) - (v248 + ((~(((v249 ^ -1) | (-(v249 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v256 = v254[v353];
        int * v257 = v205->mem;
        int v355 = v253 * 2;
        v257[v355] = v255;
        int * v259 = v205->mem;
        int v358 = (v253 * 2) + 1;
        v259[v358] = v256;
        ;
      } else {
        ;
      }
      int * v264 = v205->mem;
      int v363 = ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1)) * 2;
      int v265 = v264[v363];
      int v364 = (((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1)) * 2) + 1;
      int v266 = v264[v364];
      int * v267 = v205->cache_vals;
      int v366 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1)) & 3) * 2)) + ((((v245 + ((~(((v247 ^ -1) | (-(v247 ^ -1))) >> 31)) & 2)) - (v248 + ((~(((v249 ^ -1) | (-(v249 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v267[v366] = v265;
      int * v269 = v205->cache_vals;
      int v369 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1)) & 3) * 2)) + ((((v245 + ((~(((v247 ^ -1) | (-(v247 ^ -1))) >> 31)) & 2)) - (v248 + ((~(((v249 ^ -1) | (-(v249 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v269[v369] = v266;
      int * v271 = v205->cache_tags;
      int v372 = (int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1);
      v271[v348] = v372;
      int * v273 = v205->cache_dirty;
      v273[v348] = 0;
      int * v275 = v205->cache_age;
      v275[v348] = 1;
      int * v277 = v205->cache_age;
      int v278 = v277[v348];
      int v279 = v277[v322];
      int v378 = v279 + ((int)((unsigned int)(v279 - v278) >> 31));
      v277[v322] = v378;
      int * v281 = v205->cache_age;
      int v282 = v281[v323];
      int v380 = v282 + ((int)((unsigned int)(v282 - v278) >> 31));
      v281[v323] = v380;
      int * v284 = v205->cache_age;
      v284[v348] = 0;
      v287 = v348;
    }
    int * v288 = v205->cache_vals;
    int v383 = v287 * 2;
    int v289 = v288[v383];
    int v384 = (v287 * 2) + 1;
    int v290 = v288[v384];
    int v385 = (((((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1)) & 1) * 2) + ((((v229 + ((~(((v231 ^ -1) | (-(v231 ^ -1))) >> 31)) & 2)) - (v232 + ((~(((v233 ^ -1) | (-(v233 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v288[v385] = v289;
    int * v292 = v205->cache_vals;
    int v388 = ((((((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1)) & 1) * 2) + ((((v229 + ((~(((v231 ^ -1) | (-(v231 ^ -1))) >> 31)) & 2)) - (v232 + ((~(((v233 ^ -1) | (-(v233 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v292[v388] = v290;
    int * v294 = v205->cache_tags;
    int v391 = ((((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1)) & 1) * 2) + ((((v229 + ((~(((v231 ^ -1) | (-(v231 ^ -1))) >> 31)) & 2)) - (v232 + ((~(((v233 ^ -1) | (-(v233 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v392 = (int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1);
    v294[v391] = v392;
    int * v296 = v205->cache_dirty;
    v296[v391] = 0;
    int * v298 = v205->cache_age;
    v298[v391] = 1;
    int * v300 = v205->cache_age;
    int v301 = v300[v391];
    int v302 = v300[v320];
    int v398 = v302 + ((int)((unsigned int)(v302 - v301) >> 31));
    v300[v320] = v398;
    int * v304 = v205->cache_age;
    int v305 = v304[v321];
    int v400 = v305 + ((int)((unsigned int)(v305 - v301) >> 31));
    v304[v321] = v400;
    int * v307 = v205->cache_age;
    v307[v391] = 0;
    v310 = v391;
  }
  int v403 = (v310 * 2) + (((int)((unsigned int)v209 >> 2)) & 1);
  int v311 = v217[v403];
  int * v312 = v205->regs;
  v312[15] = v311;
  struct StateT * v314 = slot_2(v205);
  return v314;
}

struct StateT * slot_69(struct StateT * v6749) {
  int v6750 = v6749->timer;
  int v6754 = v6750 + 1;
  v6749->timer = v6754;
  struct StateT * v6752 = slot_70(v6749);
  return v6752;
}

struct StateT * slot_13(struct StateT * v1455) {
  int v1456 = v1455->timer;
  int v1626 = v1456 + 1;
  v1455->timer = v1626;
  int * v1458 = v1455->regs;
  int v1459 = v1458[10];
  int v1460 = v1458[15];
  int * v1461 = v1455->cache_tags;
  int v1631 = (((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1)) & 1) * 2;
  int v1462 = v1461[v1631];
  int v1632 = ((((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1463 = v1461[v1632];
  int v1633 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1)) & 3) * 2);
  int v1464 = v1461[v1633];
  int v1634 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1465 = v1461[v1634];
  int v1466 = v1455->timer;
  int v1635 = v1466 + ((100 ^ (((~(((v1464 ^ ((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1))) | (-(v1464 ^ ((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1))))) >> 31)) | (~(((v1465 ^ ((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1))) | (-(v1465 ^ ((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1462 ^ ((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1))) | (-(v1462 ^ ((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1))))) >> 31)) | (~(((v1463 ^ ((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1))) | (-(v1463 ^ ((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1464 ^ ((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1))) | (-(v1464 ^ ((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1))))) >> 31)) | (~(((v1465 ^ ((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1))) | (-(v1465 ^ ((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1455->timer = v1635;
  bool v1636 = !(((~(((v1462 ^ ((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1))) | (-(v1462 ^ ((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1))))) >> 31)) | (~(((v1463 ^ ((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1))) | (-(v1463 ^ ((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1))))) >> 31))) == 0);
  int v1560;
  if (v1636) {
    int * v1468 = v1455->cache_age;
    int v1638 = ((((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1)) & 1) * 2) + ((~(((v1463 ^ ((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1))) | (-(v1463 ^ ((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1))))) >> 31)) & 1);
    int v1469 = v1468[v1638];
    int v1470 = v1468[v1631];
    int v1639 = v1470 + ((int)((unsigned int)(v1470 - v1469) >> 31));
    v1468[v1631] = v1639;
    int * v1472 = v1455->cache_age;
    int v1473 = v1472[v1632];
    int v1641 = v1473 + ((int)((unsigned int)(v1473 - v1469) >> 31));
    v1472[v1632] = v1641;
    int * v1475 = v1455->cache_age;
    v1475[v1638] = 0;
    v1560 = v1638;
  } else {
    int * v1478 = v1455->cache_age;
    int v1645 = (((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1)) & 1) * 2;
    int v1479 = v1478[v1645];
    int * v1480 = v1455->cache_tags;
    int v1481 = v1480[v1645];
    int v1482 = v1478[v1632];
    int v1483 = v1480[v1632];
    bool v1647 = !(((~(((v1464 ^ ((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1))) | (-(v1464 ^ ((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1))))) >> 31)) | (~(((v1465 ^ ((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1))) | (-(v1465 ^ ((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1))))) >> 31))) == 0);
    int v1537;
    if (v1647) {
      int * v1484 = v1455->cache_age;
      int v1649 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1465 ^ ((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1))) | (-(v1465 ^ ((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1))))) >> 31)) & 1);
      int v1485 = v1484[v1649];
      int v1486 = v1484[v1633];
      int v1650 = v1486 + ((int)((unsigned int)(v1486 - v1485) >> 31));
      v1484[v1633] = v1650;
      int * v1488 = v1455->cache_age;
      int v1489 = v1488[v1634];
      int v1652 = v1489 + ((int)((unsigned int)(v1489 - v1485) >> 31));
      v1488[v1634] = v1652;
      int * v1491 = v1455->cache_age;
      v1491[v1649] = 0;
      v1537 = v1649;
    } else {
      int * v1494 = v1455->cache_age;
      int v1656 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1)) & 3) * 2);
      int v1495 = v1494[v1656];
      int * v1496 = v1455->cache_tags;
      int v1497 = v1496[v1656];
      int v1498 = v1494[v1634];
      int v1499 = v1496[v1634];
      int * v1500 = v1455->cache_dirty;
      int v1659 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1)) & 3) * 2)) + ((((v1495 + ((~(((v1497 ^ -1) | (-(v1497 ^ -1))) >> 31)) & 2)) - (v1498 + ((~(((v1499 ^ -1) | (-(v1499 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1501 = v1500[v1659];
      bool v1660 = !(v1501 == 0);
      if (v1660) {
        int * v1502 = v1455->cache_tags;
        int v1503 = v1502[v1659];
        int * v1504 = v1455->cache_vals;
        int v1663 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1)) & 3) * 2)) + ((((v1495 + ((~(((v1497 ^ -1) | (-(v1497 ^ -1))) >> 31)) & 2)) - (v1498 + ((~(((v1499 ^ -1) | (-(v1499 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1505 = v1504[v1663];
        int v1664 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1)) & 3) * 2)) + ((((v1495 + ((~(((v1497 ^ -1) | (-(v1497 ^ -1))) >> 31)) & 2)) - (v1498 + ((~(((v1499 ^ -1) | (-(v1499 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1506 = v1504[v1664];
        int * v1507 = v1455->mem;
        int v1666 = v1503 * 2;
        v1507[v1666] = v1505;
        int * v1509 = v1455->mem;
        int v1669 = (v1503 * 2) + 1;
        v1509[v1669] = v1506;
        ;
      } else {
        ;
      }
      int * v1514 = v1455->mem;
      int v1674 = ((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1)) * 2;
      int v1515 = v1514[v1674];
      int v1675 = (((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1)) * 2) + 1;
      int v1516 = v1514[v1675];
      int * v1517 = v1455->cache_vals;
      int v1677 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1)) & 3) * 2)) + ((((v1495 + ((~(((v1497 ^ -1) | (-(v1497 ^ -1))) >> 31)) & 2)) - (v1498 + ((~(((v1499 ^ -1) | (-(v1499 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1517[v1677] = v1515;
      int * v1519 = v1455->cache_vals;
      int v1680 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1)) & 3) * 2)) + ((((v1495 + ((~(((v1497 ^ -1) | (-(v1497 ^ -1))) >> 31)) & 2)) - (v1498 + ((~(((v1499 ^ -1) | (-(v1499 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1519[v1680] = v1516;
      int * v1521 = v1455->cache_tags;
      int v1683 = (int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1);
      v1521[v1659] = v1683;
      int * v1523 = v1455->cache_dirty;
      v1523[v1659] = 0;
      int * v1525 = v1455->cache_age;
      v1525[v1659] = 1;
      int * v1527 = v1455->cache_age;
      int v1528 = v1527[v1659];
      int v1529 = v1527[v1633];
      int v1689 = v1529 + ((int)((unsigned int)(v1529 - v1528) >> 31));
      v1527[v1633] = v1689;
      int * v1531 = v1455->cache_age;
      int v1532 = v1531[v1634];
      int v1691 = v1532 + ((int)((unsigned int)(v1532 - v1528) >> 31));
      v1531[v1634] = v1691;
      int * v1534 = v1455->cache_age;
      v1534[v1659] = 0;
      v1537 = v1659;
    }
    int * v1538 = v1455->cache_vals;
    int v1694 = v1537 * 2;
    int v1539 = v1538[v1694];
    int v1695 = (v1537 * 2) + 1;
    int v1540 = v1538[v1695];
    int v1696 = (((((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1)) & 1) * 2) + ((((v1479 + ((~(((v1481 ^ -1) | (-(v1481 ^ -1))) >> 31)) & 2)) - (v1482 + ((~(((v1483 ^ -1) | (-(v1483 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1538[v1696] = v1539;
    int * v1542 = v1455->cache_vals;
    int v1699 = ((((((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1)) & 1) * 2) + ((((v1479 + ((~(((v1481 ^ -1) | (-(v1481 ^ -1))) >> 31)) & 2)) - (v1482 + ((~(((v1483 ^ -1) | (-(v1483 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1542[v1699] = v1540;
    int * v1544 = v1455->cache_tags;
    int v1702 = ((((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1)) & 1) * 2) + ((((v1479 + ((~(((v1481 ^ -1) | (-(v1481 ^ -1))) >> 31)) & 2)) - (v1482 + ((~(((v1483 ^ -1) | (-(v1483 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1703 = (int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1);
    v1544[v1702] = v1703;
    int * v1546 = v1455->cache_dirty;
    v1546[v1702] = 0;
    int * v1548 = v1455->cache_age;
    v1548[v1702] = 1;
    int * v1550 = v1455->cache_age;
    int v1551 = v1550[v1702];
    int v1552 = v1550[v1631];
    int v1709 = v1552 + ((int)((unsigned int)(v1552 - v1551) >> 31));
    v1550[v1631] = v1709;
    int * v1554 = v1455->cache_age;
    int v1555 = v1554[v1632];
    int v1711 = v1555 + ((int)((unsigned int)(v1555 - v1551) >> 31));
    v1554[v1632] = v1711;
    int * v1557 = v1455->cache_age;
    v1557[v1702] = 0;
    v1560 = v1702;
  }
  int * v1561 = v1455->cache_vals;
  int v1714 = (v1560 * 2) + (((int)((unsigned int)v1459 >> 2)) & 1);
  v1561[v1714] = v1460;
  int * v1563 = v1455->cache_tags;
  int v1564 = v1563[v1633];
  int v1565 = v1563[v1634];
  bool v1717 = !(((~(((v1564 ^ ((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1))) | (-(v1564 ^ ((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1))))) >> 31)) | (~(((v1565 ^ ((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1))) | (-(v1565 ^ ((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1))))) >> 31))) == 0);
  int v1619;
  if (v1717) {
    int * v1566 = v1455->cache_age;
    int v1719 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1565 ^ ((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1))) | (-(v1565 ^ ((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1))))) >> 31)) & 1);
    int v1567 = v1566[v1719];
    int v1568 = v1566[v1633];
    int v1720 = v1568 + ((int)((unsigned int)(v1568 - v1567) >> 31));
    v1566[v1633] = v1720;
    int * v1570 = v1455->cache_age;
    int v1571 = v1570[v1634];
    int v1722 = v1571 + ((int)((unsigned int)(v1571 - v1567) >> 31));
    v1570[v1634] = v1722;
    int * v1573 = v1455->cache_age;
    v1573[v1719] = 0;
    v1619 = v1719;
  } else {
    int * v1576 = v1455->cache_age;
    int v1726 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1)) & 3) * 2);
    int v1577 = v1576[v1726];
    int * v1578 = v1455->cache_tags;
    int v1579 = v1578[v1726];
    int v1580 = v1576[v1634];
    int v1581 = v1578[v1634];
    int * v1582 = v1455->cache_dirty;
    int v1729 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1)) & 3) * 2)) + ((((v1577 + ((~(((v1579 ^ -1) | (-(v1579 ^ -1))) >> 31)) & 2)) - (v1580 + ((~(((v1581 ^ -1) | (-(v1581 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1583 = v1582[v1729];
    bool v1730 = !(v1583 == 0);
    if (v1730) {
      int * v1584 = v1455->cache_tags;
      int v1585 = v1584[v1729];
      int * v1586 = v1455->cache_vals;
      int v1733 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1)) & 3) * 2)) + ((((v1577 + ((~(((v1579 ^ -1) | (-(v1579 ^ -1))) >> 31)) & 2)) - (v1580 + ((~(((v1581 ^ -1) | (-(v1581 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1587 = v1586[v1733];
      int v1734 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1)) & 3) * 2)) + ((((v1577 + ((~(((v1579 ^ -1) | (-(v1579 ^ -1))) >> 31)) & 2)) - (v1580 + ((~(((v1581 ^ -1) | (-(v1581 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1588 = v1586[v1734];
      int * v1589 = v1455->mem;
      int v1736 = v1585 * 2;
      v1589[v1736] = v1587;
      int * v1591 = v1455->mem;
      int v1739 = (v1585 * 2) + 1;
      v1591[v1739] = v1588;
      ;
    } else {
      ;
    }
    int * v1596 = v1455->mem;
    int v1744 = ((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1)) * 2;
    int v1597 = v1596[v1744];
    int v1745 = (((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1)) * 2) + 1;
    int v1598 = v1596[v1745];
    int * v1599 = v1455->cache_vals;
    int v1747 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1)) & 3) * 2)) + ((((v1577 + ((~(((v1579 ^ -1) | (-(v1579 ^ -1))) >> 31)) & 2)) - (v1580 + ((~(((v1581 ^ -1) | (-(v1581 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1599[v1747] = v1597;
    int * v1601 = v1455->cache_vals;
    int v1750 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1)) & 3) * 2)) + ((((v1577 + ((~(((v1579 ^ -1) | (-(v1579 ^ -1))) >> 31)) & 2)) - (v1580 + ((~(((v1581 ^ -1) | (-(v1581 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1601[v1750] = v1598;
    int * v1603 = v1455->cache_tags;
    int v1753 = (int)((unsigned int)((int)((unsigned int)v1459 >> 2)) >> 1);
    v1603[v1729] = v1753;
    int * v1605 = v1455->cache_dirty;
    v1605[v1729] = 0;
    int * v1607 = v1455->cache_age;
    v1607[v1729] = 1;
    int * v1609 = v1455->cache_age;
    int v1610 = v1609[v1729];
    int v1611 = v1609[v1633];
    int v1759 = v1611 + ((int)((unsigned int)(v1611 - v1610) >> 31));
    v1609[v1633] = v1759;
    int * v1613 = v1455->cache_age;
    int v1614 = v1613[v1634];
    int v1761 = v1614 + ((int)((unsigned int)(v1614 - v1610) >> 31));
    v1613[v1634] = v1761;
    int * v1616 = v1455->cache_age;
    v1616[v1729] = 0;
    v1619 = v1729;
  }
  int * v1620 = v1455->cache_vals;
  int v1764 = (v1619 * 2) + (((int)((unsigned int)v1459 >> 2)) & 1);
  v1620[v1764] = v1460;
  int * v1622 = v1455->cache_dirty;
  v1622[v1619] = 1;
  struct StateT * v1624 = slot_15(v1455);
  return v1624;
}

struct StateT * slot_38(struct StateT * v3827) {
  int v3828 = v3827->timer;
  int v3832 = v3828 + 1;
  v3827->timer = v3832;
  struct StateT * v3830 = slot_39(v3827);
  return v3830;
}

struct StateT * slot_63(struct StateT * v6158) {
  int * v6159 = v6158->saved_regs;
  int * v6160 = v6158->regs;
  int v6161 = v6160[13];
  v6159[13] = v6161;
  int v6163 = v6158->timer;
  int v6174 = v6163 + 1;
  v6158->timer = v6174;
  int * v6165 = v6158->regs;
  int v6166 = v6165[10];
  int v6177 = v6166 + 28;
  v6165[13] = v6177;
  struct StateT * v6168 = slot_64(v6158);
  return v6168;
}

struct StateT * slot_24(struct StateT * v2895) {
  int * v2896 = v2895->saved_regs;
  int * v2897 = v2895->regs;
  int v2898 = v2897[13];
  v2896[13] = v2898;
  int v2900 = v2895->timer;
  int v2911 = v2900 + 1;
  v2895->timer = v2911;
  int * v2902 = v2895->regs;
  int v2903 = v2902[10];
  int v2914 = v2903 + 8;
  v2902[13] = v2914;
  struct StateT * v2905 = slot_26(v2895);
  return v2905;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v113 = v3 + 1;
  v2->timer = v113;
  int * v5 = v2->regs;
  int v6 = v5[12];
  int * v7 = v2->cache_tags;
  int v117 = (((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2;
  int v8 = v7[v117];
  int v118 = ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + 1;
  int v9 = v7[v118];
  int v119 = 4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2);
  int v10 = v7[v119];
  int v120 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v11 = v7[v120];
  int v12 = v2->timer;
  int v121 = v12 + ((100 ^ (((~(((v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v11 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v11 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v8 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v8 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v9 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v9 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v11 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v11 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2->timer = v121;
  int * v14 = v2->cache_vals;
  bool v122 = !(((~(((v8 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v8 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v9 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v9 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) == 0);
  int v107;
  if (v122) {
    int * v15 = v2->cache_age;
    int v124 = ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + ((~(((v9 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v9 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) & 1);
    int v16 = v15[v124];
    int v17 = v15[v117];
    int v125 = v17 + ((int)((unsigned int)(v17 - v16) >> 31));
    v15[v117] = v125;
    int * v19 = v2->cache_age;
    int v20 = v19[v118];
    int v127 = v20 + ((int)((unsigned int)(v20 - v16) >> 31));
    v19[v118] = v127;
    int * v22 = v2->cache_age;
    v22[v124] = 0;
    v107 = v124;
  } else {
    int * v25 = v2->cache_age;
    int v131 = (((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2;
    int v26 = v25[v131];
    int * v27 = v2->cache_tags;
    int v28 = v27[v131];
    int v29 = v25[v118];
    int v30 = v27[v118];
    bool v133 = !(((~(((v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v11 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v11 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) == 0);
    int v84;
    if (v133) {
      int * v31 = v2->cache_age;
      int v135 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((~(((v11 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v11 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) & 1);
      int v32 = v31[v135];
      int v33 = v31[v119];
      int v136 = v33 + ((int)((unsigned int)(v33 - v32) >> 31));
      v31[v119] = v136;
      int * v35 = v2->cache_age;
      int v36 = v35[v120];
      int v138 = v36 + ((int)((unsigned int)(v36 - v32) >> 31));
      v35[v120] = v138;
      int * v38 = v2->cache_age;
      v38[v135] = 0;
      v84 = v135;
    } else {
      int * v41 = v2->cache_age;
      int v142 = 4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2);
      int v42 = v41[v142];
      int * v43 = v2->cache_tags;
      int v44 = v43[v142];
      int v45 = v41[v120];
      int v46 = v43[v120];
      int * v47 = v2->cache_dirty;
      int v145 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v48 = v47[v145];
      bool v146 = !(v48 == 0);
      if (v146) {
        int * v49 = v2->cache_tags;
        int v50 = v49[v145];
        int * v51 = v2->cache_vals;
        int v149 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v52 = v51[v149];
        int v150 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v53 = v51[v150];
        int * v54 = v2->mem;
        int v152 = v50 * 2;
        v54[v152] = v52;
        int * v56 = v2->mem;
        int v155 = (v50 * 2) + 1;
        v56[v155] = v53;
        ;
      } else {
        ;
      }
      int * v61 = v2->mem;
      int v160 = ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) * 2;
      int v62 = v61[v160];
      int v161 = (((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) * 2) + 1;
      int v63 = v61[v161];
      int * v64 = v2->cache_vals;
      int v163 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v64[v163] = v62;
      int * v66 = v2->cache_vals;
      int v166 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v66[v166] = v63;
      int * v68 = v2->cache_tags;
      int v169 = (int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1);
      v68[v145] = v169;
      int * v70 = v2->cache_dirty;
      v70[v145] = 0;
      int * v72 = v2->cache_age;
      v72[v145] = 1;
      int * v74 = v2->cache_age;
      int v75 = v74[v145];
      int v76 = v74[v119];
      int v175 = v76 + ((int)((unsigned int)(v76 - v75) >> 31));
      v74[v119] = v175;
      int * v78 = v2->cache_age;
      int v79 = v78[v120];
      int v177 = v79 + ((int)((unsigned int)(v79 - v75) >> 31));
      v78[v120] = v177;
      int * v81 = v2->cache_age;
      v81[v145] = 0;
      v84 = v145;
    }
    int * v85 = v2->cache_vals;
    int v180 = v84 * 2;
    int v86 = v85[v180];
    int v181 = (v84 * 2) + 1;
    int v87 = v85[v181];
    int v182 = (((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + ((((v26 + ((~(((v28 ^ -1) | (-(v28 ^ -1))) >> 31)) & 2)) - (v29 + ((~(((v30 ^ -1) | (-(v30 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v85[v182] = v86;
    int * v89 = v2->cache_vals;
    int v185 = ((((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + ((((v26 + ((~(((v28 ^ -1) | (-(v28 ^ -1))) >> 31)) & 2)) - (v29 + ((~(((v30 ^ -1) | (-(v30 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v89[v185] = v87;
    int * v91 = v2->cache_tags;
    int v188 = ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + ((((v26 + ((~(((v28 ^ -1) | (-(v28 ^ -1))) >> 31)) & 2)) - (v29 + ((~(((v30 ^ -1) | (-(v30 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v189 = (int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1);
    v91[v188] = v189;
    int * v93 = v2->cache_dirty;
    v93[v188] = 0;
    int * v95 = v2->cache_age;
    v95[v188] = 1;
    int * v97 = v2->cache_age;
    int v98 = v97[v188];
    int v99 = v97[v117];
    int v195 = v99 + ((int)((unsigned int)(v99 - v98) >> 31));
    v97[v117] = v195;
    int * v101 = v2->cache_age;
    int v102 = v101[v118];
    int v197 = v102 + ((int)((unsigned int)(v102 - v98) >> 31));
    v101[v118] = v197;
    int * v104 = v2->cache_age;
    v104[v188] = 0;
    v107 = v188;
  }
  int v200 = (v107 * 2) + (((int)((unsigned int)v6 >> 2)) & 1);
  int v108 = v14[v200];
  int * v109 = v2->regs;
  v109[12] = v108;
  struct StateT * v111 = slot_1(v2);
  return v111;
}

struct StateT * slot_42(struct StateT * v4361) {
  int * v4362 = v4361->saved_regs;
  int * v4363 = v4361->regs;
  int v4364 = v4363[13];
  v4362[13] = v4364;
  int v4366 = v4361->timer;
  int v4377 = v4366 + 1;
  v4361->timer = v4377;
  int * v4368 = v4361->regs;
  int v4369 = v4368[10];
  int v4380 = v4369 + 16;
  v4368[13] = v4380;
  struct StateT * v4371 = slot_43(v4361);
  return v4371;
}

struct StateT * slot_46(struct StateT * v4434) {
  int v4435 = v4434->timer;
  int v4545 = v4435 + 1;
  v4434->timer = v4545;
  int * v4437 = v4434->regs;
  int v4438 = v4437[13];
  int * v4439 = v4434->cache_tags;
  int v4549 = (((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1)) & 1) * 2;
  int v4440 = v4439[v4549];
  int v4550 = ((((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1)) & 1) * 2) + 1;
  int v4441 = v4439[v4550];
  int v4551 = 4 + ((((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1)) & 3) * 2);
  int v4442 = v4439[v4551];
  int v4552 = (4 + ((((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4443 = v4439[v4552];
  int v4444 = v4434->timer;
  int v4553 = v4444 + ((100 ^ (((~(((v4442 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))) | (-(v4442 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))))) >> 31)) | (~(((v4443 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))) | (-(v4443 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4440 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))) | (-(v4440 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))))) >> 31)) | (~(((v4441 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))) | (-(v4441 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4442 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))) | (-(v4442 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))))) >> 31)) | (~(((v4443 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))) | (-(v4443 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))))) >> 31))) & 104)))));
  v4434->timer = v4553;
  int * v4446 = v4434->cache_vals;
  bool v4554 = !(((~(((v4440 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))) | (-(v4440 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))))) >> 31)) | (~(((v4441 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))) | (-(v4441 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))))) >> 31))) == 0);
  int v4539;
  if (v4554) {
    int * v4447 = v4434->cache_age;
    int v4556 = ((((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1)) & 1) * 2) + ((~(((v4441 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))) | (-(v4441 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))))) >> 31)) & 1);
    int v4448 = v4447[v4556];
    int v4449 = v4447[v4549];
    int v4557 = v4449 + ((int)((unsigned int)(v4449 - v4448) >> 31));
    v4447[v4549] = v4557;
    int * v4451 = v4434->cache_age;
    int v4452 = v4451[v4550];
    int v4559 = v4452 + ((int)((unsigned int)(v4452 - v4448) >> 31));
    v4451[v4550] = v4559;
    int * v4454 = v4434->cache_age;
    v4454[v4556] = 0;
    v4539 = v4556;
  } else {
    int * v4457 = v4434->cache_age;
    int v4563 = (((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1)) & 1) * 2;
    int v4458 = v4457[v4563];
    int * v4459 = v4434->cache_tags;
    int v4460 = v4459[v4563];
    int v4461 = v4457[v4550];
    int v4462 = v4459[v4550];
    bool v4565 = !(((~(((v4442 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))) | (-(v4442 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))))) >> 31)) | (~(((v4443 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))) | (-(v4443 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))))) >> 31))) == 0);
    int v4516;
    if (v4565) {
      int * v4463 = v4434->cache_age;
      int v4567 = (4 + ((((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1)) & 3) * 2)) + ((~(((v4443 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))) | (-(v4443 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))))) >> 31)) & 1);
      int v4464 = v4463[v4567];
      int v4465 = v4463[v4551];
      int v4568 = v4465 + ((int)((unsigned int)(v4465 - v4464) >> 31));
      v4463[v4551] = v4568;
      int * v4467 = v4434->cache_age;
      int v4468 = v4467[v4552];
      int v4570 = v4468 + ((int)((unsigned int)(v4468 - v4464) >> 31));
      v4467[v4552] = v4570;
      int * v4470 = v4434->cache_age;
      v4470[v4567] = 0;
      v4516 = v4567;
    } else {
      int * v4473 = v4434->cache_age;
      int v4574 = 4 + ((((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1)) & 3) * 2);
      int v4474 = v4473[v4574];
      int * v4475 = v4434->cache_tags;
      int v4476 = v4475[v4574];
      int v4477 = v4473[v4552];
      int v4478 = v4475[v4552];
      int * v4479 = v4434->cache_dirty;
      int v4577 = (4 + ((((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1)) & 3) * 2)) + ((((v4474 + ((~(((v4476 ^ -1) | (-(v4476 ^ -1))) >> 31)) & 2)) - (v4477 + ((~(((v4478 ^ -1) | (-(v4478 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4480 = v4479[v4577];
      bool v4578 = !(v4480 == 0);
      if (v4578) {
        int * v4481 = v4434->cache_tags;
        int v4482 = v4481[v4577];
        int * v4483 = v4434->cache_vals;
        int v4581 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1)) & 3) * 2)) + ((((v4474 + ((~(((v4476 ^ -1) | (-(v4476 ^ -1))) >> 31)) & 2)) - (v4477 + ((~(((v4478 ^ -1) | (-(v4478 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4484 = v4483[v4581];
        int v4582 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1)) & 3) * 2)) + ((((v4474 + ((~(((v4476 ^ -1) | (-(v4476 ^ -1))) >> 31)) & 2)) - (v4477 + ((~(((v4478 ^ -1) | (-(v4478 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4485 = v4483[v4582];
        int * v4486 = v4434->mem;
        int v4584 = v4482 * 2;
        v4486[v4584] = v4484;
        int * v4488 = v4434->mem;
        int v4587 = (v4482 * 2) + 1;
        v4488[v4587] = v4485;
        ;
      } else {
        ;
      }
      int * v4493 = v4434->mem;
      int v4592 = ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1)) * 2;
      int v4494 = v4493[v4592];
      int v4593 = (((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1)) * 2) + 1;
      int v4495 = v4493[v4593];
      int * v4496 = v4434->cache_vals;
      int v4595 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1)) & 3) * 2)) + ((((v4474 + ((~(((v4476 ^ -1) | (-(v4476 ^ -1))) >> 31)) & 2)) - (v4477 + ((~(((v4478 ^ -1) | (-(v4478 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4496[v4595] = v4494;
      int * v4498 = v4434->cache_vals;
      int v4598 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1)) & 3) * 2)) + ((((v4474 + ((~(((v4476 ^ -1) | (-(v4476 ^ -1))) >> 31)) & 2)) - (v4477 + ((~(((v4478 ^ -1) | (-(v4478 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4498[v4598] = v4495;
      int * v4500 = v4434->cache_tags;
      int v4601 = (int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1);
      v4500[v4577] = v4601;
      int * v4502 = v4434->cache_dirty;
      v4502[v4577] = 0;
      int * v4504 = v4434->cache_age;
      v4504[v4577] = 1;
      int * v4506 = v4434->cache_age;
      int v4507 = v4506[v4577];
      int v4508 = v4506[v4551];
      int v4607 = v4508 + ((int)((unsigned int)(v4508 - v4507) >> 31));
      v4506[v4551] = v4607;
      int * v4510 = v4434->cache_age;
      int v4511 = v4510[v4552];
      int v4609 = v4511 + ((int)((unsigned int)(v4511 - v4507) >> 31));
      v4510[v4552] = v4609;
      int * v4513 = v4434->cache_age;
      v4513[v4577] = 0;
      v4516 = v4577;
    }
    int * v4517 = v4434->cache_vals;
    int v4612 = v4516 * 2;
    int v4518 = v4517[v4612];
    int v4613 = (v4516 * 2) + 1;
    int v4519 = v4517[v4613];
    int v4614 = (((((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1)) & 1) * 2) + ((((v4458 + ((~(((v4460 ^ -1) | (-(v4460 ^ -1))) >> 31)) & 2)) - (v4461 + ((~(((v4462 ^ -1) | (-(v4462 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4517[v4614] = v4518;
    int * v4521 = v4434->cache_vals;
    int v4617 = ((((((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1)) & 1) * 2) + ((((v4458 + ((~(((v4460 ^ -1) | (-(v4460 ^ -1))) >> 31)) & 2)) - (v4461 + ((~(((v4462 ^ -1) | (-(v4462 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4521[v4617] = v4519;
    int * v4523 = v4434->cache_tags;
    int v4620 = ((((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1)) & 1) * 2) + ((((v4458 + ((~(((v4460 ^ -1) | (-(v4460 ^ -1))) >> 31)) & 2)) - (v4461 + ((~(((v4462 ^ -1) | (-(v4462 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4621 = (int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1);
    v4523[v4620] = v4621;
    int * v4525 = v4434->cache_dirty;
    v4525[v4620] = 0;
    int * v4527 = v4434->cache_age;
    v4527[v4620] = 1;
    int * v4529 = v4434->cache_age;
    int v4530 = v4529[v4620];
    int v4531 = v4529[v4549];
    int v4627 = v4531 + ((int)((unsigned int)(v4531 - v4530) >> 31));
    v4529[v4549] = v4627;
    int * v4533 = v4434->cache_age;
    int v4534 = v4533[v4550];
    int v4629 = v4534 + ((int)((unsigned int)(v4534 - v4530) >> 31));
    v4533[v4550] = v4629;
    int * v4536 = v4434->cache_age;
    v4536[v4620] = 0;
    v4539 = v4620;
  }
  int v4632 = (v4539 * 2) + (((int)((unsigned int)v4438 >> 2)) & 1);
  int v4540 = v4446[v4632];
  int * v4541 = v4434->regs;
  v4541[13] = v4540;
  struct StateT * v4543 = slot_47(v4434);
  return v4543;
}

struct StateT * slot_20(struct StateT * v2536) {
  int * v2537 = v2536->regs;
  int v2538 = v2537[12];
  bool v2553 = v2538 == 0;
  struct StateT * v2549;
  if (v2553) {
    int v2539 = v2536->timer;
    int v2554 = v2539 + 15;
    v2536->timer = v2554;
    int * v2541 = v2536->saved_regs;
    int v2542 = v2541[14];
    int * v2543 = v2536->regs;
    v2543[14] = v2542;
    struct StateT * v2545 = slot_19(v2536);
    v2549 = v2545;
  } else {
    struct StateT * v2547 = slot_21(v2536);
    v2549 = v2547;
  }
  return v2549;
}

struct StateT * slot_61(struct StateT * v5835) {
  int v5836 = v5835->timer;
  int v6006 = v5836 + 1;
  v5835->timer = v6006;
  int * v5838 = v5835->regs;
  int v5839 = v5838[10];
  int v5840 = v5838[13];
  int * v5841 = v5835->cache_tags;
  int v6011 = (((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1)) & 1) * 2;
  int v5842 = v5841[v6011];
  int v6012 = ((((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1)) & 1) * 2) + 1;
  int v5843 = v5841[v6012];
  int v6013 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1)) & 3) * 2);
  int v5844 = v5841[v6013];
  int v6014 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5845 = v5841[v6014];
  int v5846 = v5835->timer;
  int v6015 = v5846 + ((100 ^ (((~(((v5844 ^ ((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1))) | (-(v5844 ^ ((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v5845 ^ ((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1))) | (-(v5845 ^ ((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5842 ^ ((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1))) | (-(v5842 ^ ((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v5843 ^ ((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1))) | (-(v5843 ^ ((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5844 ^ ((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1))) | (-(v5844 ^ ((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v5845 ^ ((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1))) | (-(v5845 ^ ((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1))))) >> 31))) & 104)))));
  v5835->timer = v6015;
  bool v6016 = !(((~(((v5842 ^ ((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1))) | (-(v5842 ^ ((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v5843 ^ ((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1))) | (-(v5843 ^ ((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v5940;
  if (v6016) {
    int * v5848 = v5835->cache_age;
    int v6018 = ((((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1)) & 1) * 2) + ((~(((v5843 ^ ((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1))) | (-(v5843 ^ ((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v5849 = v5848[v6018];
    int v5850 = v5848[v6011];
    int v6019 = v5850 + ((int)((unsigned int)(v5850 - v5849) >> 31));
    v5848[v6011] = v6019;
    int * v5852 = v5835->cache_age;
    int v5853 = v5852[v6012];
    int v6021 = v5853 + ((int)((unsigned int)(v5853 - v5849) >> 31));
    v5852[v6012] = v6021;
    int * v5855 = v5835->cache_age;
    v5855[v6018] = 0;
    v5940 = v6018;
  } else {
    int * v5858 = v5835->cache_age;
    int v6025 = (((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1)) & 1) * 2;
    int v5859 = v5858[v6025];
    int * v5860 = v5835->cache_tags;
    int v5861 = v5860[v6025];
    int v5862 = v5858[v6012];
    int v5863 = v5860[v6012];
    bool v6027 = !(((~(((v5844 ^ ((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1))) | (-(v5844 ^ ((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v5845 ^ ((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1))) | (-(v5845 ^ ((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1))))) >> 31))) == 0);
    int v5917;
    if (v6027) {
      int * v5864 = v5835->cache_age;
      int v6029 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5845 ^ ((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1))) | (-(v5845 ^ ((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1))))) >> 31)) & 1);
      int v5865 = v5864[v6029];
      int v5866 = v5864[v6013];
      int v6030 = v5866 + ((int)((unsigned int)(v5866 - v5865) >> 31));
      v5864[v6013] = v6030;
      int * v5868 = v5835->cache_age;
      int v5869 = v5868[v6014];
      int v6032 = v5869 + ((int)((unsigned int)(v5869 - v5865) >> 31));
      v5868[v6014] = v6032;
      int * v5871 = v5835->cache_age;
      v5871[v6029] = 0;
      v5917 = v6029;
    } else {
      int * v5874 = v5835->cache_age;
      int v6036 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1)) & 3) * 2);
      int v5875 = v5874[v6036];
      int * v5876 = v5835->cache_tags;
      int v5877 = v5876[v6036];
      int v5878 = v5874[v6014];
      int v5879 = v5876[v6014];
      int * v5880 = v5835->cache_dirty;
      int v6039 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5875 + ((~(((v5877 ^ -1) | (-(v5877 ^ -1))) >> 31)) & 2)) - (v5878 + ((~(((v5879 ^ -1) | (-(v5879 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5881 = v5880[v6039];
      bool v6040 = !(v5881 == 0);
      if (v6040) {
        int * v5882 = v5835->cache_tags;
        int v5883 = v5882[v6039];
        int * v5884 = v5835->cache_vals;
        int v6043 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5875 + ((~(((v5877 ^ -1) | (-(v5877 ^ -1))) >> 31)) & 2)) - (v5878 + ((~(((v5879 ^ -1) | (-(v5879 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5885 = v5884[v6043];
        int v6044 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5875 + ((~(((v5877 ^ -1) | (-(v5877 ^ -1))) >> 31)) & 2)) - (v5878 + ((~(((v5879 ^ -1) | (-(v5879 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5886 = v5884[v6044];
        int * v5887 = v5835->mem;
        int v6046 = v5883 * 2;
        v5887[v6046] = v5885;
        int * v5889 = v5835->mem;
        int v6049 = (v5883 * 2) + 1;
        v5889[v6049] = v5886;
        ;
      } else {
        ;
      }
      int * v5894 = v5835->mem;
      int v6054 = ((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1)) * 2;
      int v5895 = v5894[v6054];
      int v6055 = (((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1)) * 2) + 1;
      int v5896 = v5894[v6055];
      int * v5897 = v5835->cache_vals;
      int v6057 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5875 + ((~(((v5877 ^ -1) | (-(v5877 ^ -1))) >> 31)) & 2)) - (v5878 + ((~(((v5879 ^ -1) | (-(v5879 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5897[v6057] = v5895;
      int * v5899 = v5835->cache_vals;
      int v6060 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5875 + ((~(((v5877 ^ -1) | (-(v5877 ^ -1))) >> 31)) & 2)) - (v5878 + ((~(((v5879 ^ -1) | (-(v5879 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5899[v6060] = v5896;
      int * v5901 = v5835->cache_tags;
      int v6063 = (int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1);
      v5901[v6039] = v6063;
      int * v5903 = v5835->cache_dirty;
      v5903[v6039] = 0;
      int * v5905 = v5835->cache_age;
      v5905[v6039] = 1;
      int * v5907 = v5835->cache_age;
      int v5908 = v5907[v6039];
      int v5909 = v5907[v6013];
      int v6069 = v5909 + ((int)((unsigned int)(v5909 - v5908) >> 31));
      v5907[v6013] = v6069;
      int * v5911 = v5835->cache_age;
      int v5912 = v5911[v6014];
      int v6071 = v5912 + ((int)((unsigned int)(v5912 - v5908) >> 31));
      v5911[v6014] = v6071;
      int * v5914 = v5835->cache_age;
      v5914[v6039] = 0;
      v5917 = v6039;
    }
    int * v5918 = v5835->cache_vals;
    int v6074 = v5917 * 2;
    int v5919 = v5918[v6074];
    int v6075 = (v5917 * 2) + 1;
    int v5920 = v5918[v6075];
    int v6076 = (((((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v5859 + ((~(((v5861 ^ -1) | (-(v5861 ^ -1))) >> 31)) & 2)) - (v5862 + ((~(((v5863 ^ -1) | (-(v5863 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5918[v6076] = v5919;
    int * v5922 = v5835->cache_vals;
    int v6079 = ((((((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v5859 + ((~(((v5861 ^ -1) | (-(v5861 ^ -1))) >> 31)) & 2)) - (v5862 + ((~(((v5863 ^ -1) | (-(v5863 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5922[v6079] = v5920;
    int * v5924 = v5835->cache_tags;
    int v6082 = ((((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v5859 + ((~(((v5861 ^ -1) | (-(v5861 ^ -1))) >> 31)) & 2)) - (v5862 + ((~(((v5863 ^ -1) | (-(v5863 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6083 = (int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1);
    v5924[v6082] = v6083;
    int * v5926 = v5835->cache_dirty;
    v5926[v6082] = 0;
    int * v5928 = v5835->cache_age;
    v5928[v6082] = 1;
    int * v5930 = v5835->cache_age;
    int v5931 = v5930[v6082];
    int v5932 = v5930[v6011];
    int v6089 = v5932 + ((int)((unsigned int)(v5932 - v5931) >> 31));
    v5930[v6011] = v6089;
    int * v5934 = v5835->cache_age;
    int v5935 = v5934[v6012];
    int v6091 = v5935 + ((int)((unsigned int)(v5935 - v5931) >> 31));
    v5934[v6012] = v6091;
    int * v5937 = v5835->cache_age;
    v5937[v6082] = 0;
    v5940 = v6082;
  }
  int * v5941 = v5835->cache_vals;
  int v6094 = (v5940 * 2) + (((int)((unsigned int)(v5839 + 24) >> 2)) & 1);
  v5941[v6094] = v5840;
  int * v5943 = v5835->cache_tags;
  int v5944 = v5943[v6013];
  int v5945 = v5943[v6014];
  bool v6097 = !(((~(((v5944 ^ ((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1))) | (-(v5944 ^ ((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v5945 ^ ((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1))) | (-(v5945 ^ ((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v5999;
  if (v6097) {
    int * v5946 = v5835->cache_age;
    int v6099 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5945 ^ ((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1))) | (-(v5945 ^ ((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v5947 = v5946[v6099];
    int v5948 = v5946[v6013];
    int v6100 = v5948 + ((int)((unsigned int)(v5948 - v5947) >> 31));
    v5946[v6013] = v6100;
    int * v5950 = v5835->cache_age;
    int v5951 = v5950[v6014];
    int v6102 = v5951 + ((int)((unsigned int)(v5951 - v5947) >> 31));
    v5950[v6014] = v6102;
    int * v5953 = v5835->cache_age;
    v5953[v6099] = 0;
    v5999 = v6099;
  } else {
    int * v5956 = v5835->cache_age;
    int v6106 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1)) & 3) * 2);
    int v5957 = v5956[v6106];
    int * v5958 = v5835->cache_tags;
    int v5959 = v5958[v6106];
    int v5960 = v5956[v6014];
    int v5961 = v5958[v6014];
    int * v5962 = v5835->cache_dirty;
    int v6109 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5957 + ((~(((v5959 ^ -1) | (-(v5959 ^ -1))) >> 31)) & 2)) - (v5960 + ((~(((v5961 ^ -1) | (-(v5961 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5963 = v5962[v6109];
    bool v6110 = !(v5963 == 0);
    if (v6110) {
      int * v5964 = v5835->cache_tags;
      int v5965 = v5964[v6109];
      int * v5966 = v5835->cache_vals;
      int v6113 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5957 + ((~(((v5959 ^ -1) | (-(v5959 ^ -1))) >> 31)) & 2)) - (v5960 + ((~(((v5961 ^ -1) | (-(v5961 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v5967 = v5966[v6113];
      int v6114 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5957 + ((~(((v5959 ^ -1) | (-(v5959 ^ -1))) >> 31)) & 2)) - (v5960 + ((~(((v5961 ^ -1) | (-(v5961 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v5968 = v5966[v6114];
      int * v5969 = v5835->mem;
      int v6116 = v5965 * 2;
      v5969[v6116] = v5967;
      int * v5971 = v5835->mem;
      int v6119 = (v5965 * 2) + 1;
      v5971[v6119] = v5968;
      ;
    } else {
      ;
    }
    int * v5976 = v5835->mem;
    int v6124 = ((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1)) * 2;
    int v5977 = v5976[v6124];
    int v6125 = (((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1)) * 2) + 1;
    int v5978 = v5976[v6125];
    int * v5979 = v5835->cache_vals;
    int v6127 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5957 + ((~(((v5959 ^ -1) | (-(v5959 ^ -1))) >> 31)) & 2)) - (v5960 + ((~(((v5961 ^ -1) | (-(v5961 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5979[v6127] = v5977;
    int * v5981 = v5835->cache_vals;
    int v6130 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5957 + ((~(((v5959 ^ -1) | (-(v5959 ^ -1))) >> 31)) & 2)) - (v5960 + ((~(((v5961 ^ -1) | (-(v5961 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5981[v6130] = v5978;
    int * v5983 = v5835->cache_tags;
    int v6133 = (int)((unsigned int)((int)((unsigned int)(v5839 + 24) >> 2)) >> 1);
    v5983[v6109] = v6133;
    int * v5985 = v5835->cache_dirty;
    v5985[v6109] = 0;
    int * v5987 = v5835->cache_age;
    v5987[v6109] = 1;
    int * v5989 = v5835->cache_age;
    int v5990 = v5989[v6109];
    int v5991 = v5989[v6013];
    int v6139 = v5991 + ((int)((unsigned int)(v5991 - v5990) >> 31));
    v5989[v6013] = v6139;
    int * v5993 = v5835->cache_age;
    int v5994 = v5993[v6014];
    int v6141 = v5994 + ((int)((unsigned int)(v5994 - v5990) >> 31));
    v5993[v6014] = v6141;
    int * v5996 = v5835->cache_age;
    v5996[v6109] = 0;
    v5999 = v6109;
  }
  int * v6000 = v5835->cache_vals;
  int v6144 = (v5999 * 2) + (((int)((unsigned int)(v5839 + 24) >> 2)) & 1);
  v6000[v6144] = v5840;
  int * v6002 = v5835->cache_dirty;
  v6002[v5999] = 1;
  struct StateT * v6004 = slot_62(v5835);
  return v6004;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_79(struct StateT * v7406) {
  int v7407 = v7406->timer;
  int v7414 = v7407 + 1;
  v7406->timer = v7414;
  int * v7409 = v7406->regs;
  int v7410 = v7409[11];
  int v7417 = v7410 + 36;
  v7409[11] = v7417;
  struct StateT * v7412 = slot_81(v7406);
  return v7412;
}

struct StateT * slot_41(struct StateT * v4353) {
  int v4354 = v4353->timer;
  int v4358 = v4354 + 1;
  v4353->timer = v4358;
  struct StateT * v4356 = slot_42(v4353);
  return v4356;
}

struct StateT * slot_39(struct StateT * v3835) {
  int v3836 = v3835->timer;
  int v3946 = v3836 + 1;
  v3835->timer = v3946;
  int * v3838 = v3835->regs;
  int v3839 = v3838[13];
  int * v3840 = v3835->cache_tags;
  int v3950 = (((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1)) & 1) * 2;
  int v3841 = v3840[v3950];
  int v3951 = ((((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1)) & 1) * 2) + 1;
  int v3842 = v3840[v3951];
  int v3952 = 4 + ((((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1)) & 3) * 2);
  int v3843 = v3840[v3952];
  int v3953 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3844 = v3840[v3953];
  int v3845 = v3835->timer;
  int v3954 = v3845 + ((100 ^ (((~(((v3843 ^ ((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1))) | (-(v3843 ^ ((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1))))) >> 31)) | (~(((v3844 ^ ((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1))) | (-(v3844 ^ ((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3841 ^ ((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1))) | (-(v3841 ^ ((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1))))) >> 31)) | (~(((v3842 ^ ((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1))) | (-(v3842 ^ ((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3843 ^ ((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1))) | (-(v3843 ^ ((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1))))) >> 31)) | (~(((v3844 ^ ((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1))) | (-(v3844 ^ ((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1))))) >> 31))) & 104)))));
  v3835->timer = v3954;
  int * v3847 = v3835->cache_vals;
  bool v3955 = !(((~(((v3841 ^ ((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1))) | (-(v3841 ^ ((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1))))) >> 31)) | (~(((v3842 ^ ((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1))) | (-(v3842 ^ ((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1))))) >> 31))) == 0);
  int v3940;
  if (v3955) {
    int * v3848 = v3835->cache_age;
    int v3957 = ((((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1)) & 1) * 2) + ((~(((v3842 ^ ((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1))) | (-(v3842 ^ ((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1))))) >> 31)) & 1);
    int v3849 = v3848[v3957];
    int v3850 = v3848[v3950];
    int v3958 = v3850 + ((int)((unsigned int)(v3850 - v3849) >> 31));
    v3848[v3950] = v3958;
    int * v3852 = v3835->cache_age;
    int v3853 = v3852[v3951];
    int v3960 = v3853 + ((int)((unsigned int)(v3853 - v3849) >> 31));
    v3852[v3951] = v3960;
    int * v3855 = v3835->cache_age;
    v3855[v3957] = 0;
    v3940 = v3957;
  } else {
    int * v3858 = v3835->cache_age;
    int v3964 = (((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1)) & 1) * 2;
    int v3859 = v3858[v3964];
    int * v3860 = v3835->cache_tags;
    int v3861 = v3860[v3964];
    int v3862 = v3858[v3951];
    int v3863 = v3860[v3951];
    bool v3966 = !(((~(((v3843 ^ ((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1))) | (-(v3843 ^ ((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1))))) >> 31)) | (~(((v3844 ^ ((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1))) | (-(v3844 ^ ((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1))))) >> 31))) == 0);
    int v3917;
    if (v3966) {
      int * v3864 = v3835->cache_age;
      int v3968 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1)) & 3) * 2)) + ((~(((v3844 ^ ((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1))) | (-(v3844 ^ ((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1))))) >> 31)) & 1);
      int v3865 = v3864[v3968];
      int v3866 = v3864[v3952];
      int v3969 = v3866 + ((int)((unsigned int)(v3866 - v3865) >> 31));
      v3864[v3952] = v3969;
      int * v3868 = v3835->cache_age;
      int v3869 = v3868[v3953];
      int v3971 = v3869 + ((int)((unsigned int)(v3869 - v3865) >> 31));
      v3868[v3953] = v3971;
      int * v3871 = v3835->cache_age;
      v3871[v3968] = 0;
      v3917 = v3968;
    } else {
      int * v3874 = v3835->cache_age;
      int v3975 = 4 + ((((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1)) & 3) * 2);
      int v3875 = v3874[v3975];
      int * v3876 = v3835->cache_tags;
      int v3877 = v3876[v3975];
      int v3878 = v3874[v3953];
      int v3879 = v3876[v3953];
      int * v3880 = v3835->cache_dirty;
      int v3978 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1)) & 3) * 2)) + ((((v3875 + ((~(((v3877 ^ -1) | (-(v3877 ^ -1))) >> 31)) & 2)) - (v3878 + ((~(((v3879 ^ -1) | (-(v3879 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3881 = v3880[v3978];
      bool v3979 = !(v3881 == 0);
      if (v3979) {
        int * v3882 = v3835->cache_tags;
        int v3883 = v3882[v3978];
        int * v3884 = v3835->cache_vals;
        int v3982 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1)) & 3) * 2)) + ((((v3875 + ((~(((v3877 ^ -1) | (-(v3877 ^ -1))) >> 31)) & 2)) - (v3878 + ((~(((v3879 ^ -1) | (-(v3879 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3885 = v3884[v3982];
        int v3983 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1)) & 3) * 2)) + ((((v3875 + ((~(((v3877 ^ -1) | (-(v3877 ^ -1))) >> 31)) & 2)) - (v3878 + ((~(((v3879 ^ -1) | (-(v3879 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3886 = v3884[v3983];
        int * v3887 = v3835->mem;
        int v3985 = v3883 * 2;
        v3887[v3985] = v3885;
        int * v3889 = v3835->mem;
        int v3988 = (v3883 * 2) + 1;
        v3889[v3988] = v3886;
        ;
      } else {
        ;
      }
      int * v3894 = v3835->mem;
      int v3993 = ((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1)) * 2;
      int v3895 = v3894[v3993];
      int v3994 = (((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1)) * 2) + 1;
      int v3896 = v3894[v3994];
      int * v3897 = v3835->cache_vals;
      int v3996 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1)) & 3) * 2)) + ((((v3875 + ((~(((v3877 ^ -1) | (-(v3877 ^ -1))) >> 31)) & 2)) - (v3878 + ((~(((v3879 ^ -1) | (-(v3879 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3897[v3996] = v3895;
      int * v3899 = v3835->cache_vals;
      int v3999 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1)) & 3) * 2)) + ((((v3875 + ((~(((v3877 ^ -1) | (-(v3877 ^ -1))) >> 31)) & 2)) - (v3878 + ((~(((v3879 ^ -1) | (-(v3879 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3899[v3999] = v3896;
      int * v3901 = v3835->cache_tags;
      int v4002 = (int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1);
      v3901[v3978] = v4002;
      int * v3903 = v3835->cache_dirty;
      v3903[v3978] = 0;
      int * v3905 = v3835->cache_age;
      v3905[v3978] = 1;
      int * v3907 = v3835->cache_age;
      int v3908 = v3907[v3978];
      int v3909 = v3907[v3952];
      int v4008 = v3909 + ((int)((unsigned int)(v3909 - v3908) >> 31));
      v3907[v3952] = v4008;
      int * v3911 = v3835->cache_age;
      int v3912 = v3911[v3953];
      int v4010 = v3912 + ((int)((unsigned int)(v3912 - v3908) >> 31));
      v3911[v3953] = v4010;
      int * v3914 = v3835->cache_age;
      v3914[v3978] = 0;
      v3917 = v3978;
    }
    int * v3918 = v3835->cache_vals;
    int v4013 = v3917 * 2;
    int v3919 = v3918[v4013];
    int v4014 = (v3917 * 2) + 1;
    int v3920 = v3918[v4014];
    int v4015 = (((((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1)) & 1) * 2) + ((((v3859 + ((~(((v3861 ^ -1) | (-(v3861 ^ -1))) >> 31)) & 2)) - (v3862 + ((~(((v3863 ^ -1) | (-(v3863 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3918[v4015] = v3919;
    int * v3922 = v3835->cache_vals;
    int v4018 = ((((((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1)) & 1) * 2) + ((((v3859 + ((~(((v3861 ^ -1) | (-(v3861 ^ -1))) >> 31)) & 2)) - (v3862 + ((~(((v3863 ^ -1) | (-(v3863 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3922[v4018] = v3920;
    int * v3924 = v3835->cache_tags;
    int v4021 = ((((int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1)) & 1) * 2) + ((((v3859 + ((~(((v3861 ^ -1) | (-(v3861 ^ -1))) >> 31)) & 2)) - (v3862 + ((~(((v3863 ^ -1) | (-(v3863 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4022 = (int)((unsigned int)((int)((unsigned int)v3839 >> 2)) >> 1);
    v3924[v4021] = v4022;
    int * v3926 = v3835->cache_dirty;
    v3926[v4021] = 0;
    int * v3928 = v3835->cache_age;
    v3928[v4021] = 1;
    int * v3930 = v3835->cache_age;
    int v3931 = v3930[v4021];
    int v3932 = v3930[v3950];
    int v4028 = v3932 + ((int)((unsigned int)(v3932 - v3931) >> 31));
    v3930[v3950] = v4028;
    int * v3934 = v3835->cache_age;
    int v3935 = v3934[v3951];
    int v4030 = v3935 + ((int)((unsigned int)(v3935 - v3931) >> 31));
    v3934[v3951] = v4030;
    int * v3937 = v3835->cache_age;
    v3937[v4021] = 0;
    v3940 = v4021;
  }
  int v4033 = (v3940 * 2) + (((int)((unsigned int)v3839 >> 2)) & 1);
  int v3941 = v3847[v4033];
  int * v3942 = v3835->regs;
  v3942[13] = v3941;
  struct StateT * v3944 = slot_40(v3835);
  return v3944;
}

struct StateT * slot_8(struct StateT * v892) {
  int v893 = v892->timer;
  int v901 = v893 + 1;
  v892->timer = v901;
  int * v895 = v892->regs;
  int v896 = v895[12];
  int v897 = v895[13];
  int v905 = v896 & v897;
  v895[12] = v905;
  struct StateT * v899 = slot_9(v892);
  return v899;
}

struct StateT * slot_30(struct StateT * v3193) {
  int * v3194 = v3193->regs;
  int v3195 = v3194[12];
  bool v3210 = v3195 == 0;
  struct StateT * v3206;
  if (v3210) {
    int v3196 = v3193->timer;
    int v3211 = v3196 + 15;
    v3193->timer = v3211;
    int * v3198 = v3193->saved_regs;
    int v3199 = v3198[13];
    int * v3200 = v3193->regs;
    v3200[13] = v3199;
    struct StateT * v3202 = slot_32(v3193);
    v3206 = v3202;
  } else {
    struct StateT * v3204 = slot_33(v3193);
    v3206 = v3204;
  }
  return v3206;
}

struct StateT * slot_60(struct StateT * v5632) {
  int v5633 = v5632->timer;
  int v5743 = v5633 + 1;
  v5632->timer = v5743;
  int * v5635 = v5632->regs;
  int v5636 = v5635[13];
  int * v5637 = v5632->cache_tags;
  int v5747 = (((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1)) & 1) * 2;
  int v5638 = v5637[v5747];
  int v5748 = ((((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1)) & 1) * 2) + 1;
  int v5639 = v5637[v5748];
  int v5749 = 4 + ((((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1)) & 3) * 2);
  int v5640 = v5637[v5749];
  int v5750 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5641 = v5637[v5750];
  int v5642 = v5632->timer;
  int v5751 = v5642 + ((100 ^ (((~(((v5640 ^ ((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1))) | (-(v5640 ^ ((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1))))) >> 31)) | (~(((v5641 ^ ((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1))) | (-(v5641 ^ ((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5638 ^ ((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1))) | (-(v5638 ^ ((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1))))) >> 31)) | (~(((v5639 ^ ((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1))) | (-(v5639 ^ ((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5640 ^ ((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1))) | (-(v5640 ^ ((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1))))) >> 31)) | (~(((v5641 ^ ((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1))) | (-(v5641 ^ ((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1))))) >> 31))) & 104)))));
  v5632->timer = v5751;
  int * v5644 = v5632->cache_vals;
  bool v5752 = !(((~(((v5638 ^ ((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1))) | (-(v5638 ^ ((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1))))) >> 31)) | (~(((v5639 ^ ((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1))) | (-(v5639 ^ ((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1))))) >> 31))) == 0);
  int v5737;
  if (v5752) {
    int * v5645 = v5632->cache_age;
    int v5754 = ((((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1)) & 1) * 2) + ((~(((v5639 ^ ((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1))) | (-(v5639 ^ ((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1))))) >> 31)) & 1);
    int v5646 = v5645[v5754];
    int v5647 = v5645[v5747];
    int v5755 = v5647 + ((int)((unsigned int)(v5647 - v5646) >> 31));
    v5645[v5747] = v5755;
    int * v5649 = v5632->cache_age;
    int v5650 = v5649[v5748];
    int v5757 = v5650 + ((int)((unsigned int)(v5650 - v5646) >> 31));
    v5649[v5748] = v5757;
    int * v5652 = v5632->cache_age;
    v5652[v5754] = 0;
    v5737 = v5754;
  } else {
    int * v5655 = v5632->cache_age;
    int v5761 = (((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1)) & 1) * 2;
    int v5656 = v5655[v5761];
    int * v5657 = v5632->cache_tags;
    int v5658 = v5657[v5761];
    int v5659 = v5655[v5748];
    int v5660 = v5657[v5748];
    bool v5763 = !(((~(((v5640 ^ ((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1))) | (-(v5640 ^ ((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1))))) >> 31)) | (~(((v5641 ^ ((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1))) | (-(v5641 ^ ((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1))))) >> 31))) == 0);
    int v5714;
    if (v5763) {
      int * v5661 = v5632->cache_age;
      int v5765 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1)) & 3) * 2)) + ((~(((v5641 ^ ((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1))) | (-(v5641 ^ ((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1))))) >> 31)) & 1);
      int v5662 = v5661[v5765];
      int v5663 = v5661[v5749];
      int v5766 = v5663 + ((int)((unsigned int)(v5663 - v5662) >> 31));
      v5661[v5749] = v5766;
      int * v5665 = v5632->cache_age;
      int v5666 = v5665[v5750];
      int v5768 = v5666 + ((int)((unsigned int)(v5666 - v5662) >> 31));
      v5665[v5750] = v5768;
      int * v5668 = v5632->cache_age;
      v5668[v5765] = 0;
      v5714 = v5765;
    } else {
      int * v5671 = v5632->cache_age;
      int v5772 = 4 + ((((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1)) & 3) * 2);
      int v5672 = v5671[v5772];
      int * v5673 = v5632->cache_tags;
      int v5674 = v5673[v5772];
      int v5675 = v5671[v5750];
      int v5676 = v5673[v5750];
      int * v5677 = v5632->cache_dirty;
      int v5775 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1)) & 3) * 2)) + ((((v5672 + ((~(((v5674 ^ -1) | (-(v5674 ^ -1))) >> 31)) & 2)) - (v5675 + ((~(((v5676 ^ -1) | (-(v5676 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5678 = v5677[v5775];
      bool v5776 = !(v5678 == 0);
      if (v5776) {
        int * v5679 = v5632->cache_tags;
        int v5680 = v5679[v5775];
        int * v5681 = v5632->cache_vals;
        int v5779 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1)) & 3) * 2)) + ((((v5672 + ((~(((v5674 ^ -1) | (-(v5674 ^ -1))) >> 31)) & 2)) - (v5675 + ((~(((v5676 ^ -1) | (-(v5676 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5682 = v5681[v5779];
        int v5780 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1)) & 3) * 2)) + ((((v5672 + ((~(((v5674 ^ -1) | (-(v5674 ^ -1))) >> 31)) & 2)) - (v5675 + ((~(((v5676 ^ -1) | (-(v5676 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5683 = v5681[v5780];
        int * v5684 = v5632->mem;
        int v5782 = v5680 * 2;
        v5684[v5782] = v5682;
        int * v5686 = v5632->mem;
        int v5785 = (v5680 * 2) + 1;
        v5686[v5785] = v5683;
        ;
      } else {
        ;
      }
      int * v5691 = v5632->mem;
      int v5790 = ((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1)) * 2;
      int v5692 = v5691[v5790];
      int v5791 = (((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1)) * 2) + 1;
      int v5693 = v5691[v5791];
      int * v5694 = v5632->cache_vals;
      int v5793 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1)) & 3) * 2)) + ((((v5672 + ((~(((v5674 ^ -1) | (-(v5674 ^ -1))) >> 31)) & 2)) - (v5675 + ((~(((v5676 ^ -1) | (-(v5676 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5694[v5793] = v5692;
      int * v5696 = v5632->cache_vals;
      int v5796 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1)) & 3) * 2)) + ((((v5672 + ((~(((v5674 ^ -1) | (-(v5674 ^ -1))) >> 31)) & 2)) - (v5675 + ((~(((v5676 ^ -1) | (-(v5676 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5696[v5796] = v5693;
      int * v5698 = v5632->cache_tags;
      int v5799 = (int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1);
      v5698[v5775] = v5799;
      int * v5700 = v5632->cache_dirty;
      v5700[v5775] = 0;
      int * v5702 = v5632->cache_age;
      v5702[v5775] = 1;
      int * v5704 = v5632->cache_age;
      int v5705 = v5704[v5775];
      int v5706 = v5704[v5749];
      int v5805 = v5706 + ((int)((unsigned int)(v5706 - v5705) >> 31));
      v5704[v5749] = v5805;
      int * v5708 = v5632->cache_age;
      int v5709 = v5708[v5750];
      int v5807 = v5709 + ((int)((unsigned int)(v5709 - v5705) >> 31));
      v5708[v5750] = v5807;
      int * v5711 = v5632->cache_age;
      v5711[v5775] = 0;
      v5714 = v5775;
    }
    int * v5715 = v5632->cache_vals;
    int v5810 = v5714 * 2;
    int v5716 = v5715[v5810];
    int v5811 = (v5714 * 2) + 1;
    int v5717 = v5715[v5811];
    int v5812 = (((((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1)) & 1) * 2) + ((((v5656 + ((~(((v5658 ^ -1) | (-(v5658 ^ -1))) >> 31)) & 2)) - (v5659 + ((~(((v5660 ^ -1) | (-(v5660 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5715[v5812] = v5716;
    int * v5719 = v5632->cache_vals;
    int v5815 = ((((((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1)) & 1) * 2) + ((((v5656 + ((~(((v5658 ^ -1) | (-(v5658 ^ -1))) >> 31)) & 2)) - (v5659 + ((~(((v5660 ^ -1) | (-(v5660 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5719[v5815] = v5717;
    int * v5721 = v5632->cache_tags;
    int v5818 = ((((int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1)) & 1) * 2) + ((((v5656 + ((~(((v5658 ^ -1) | (-(v5658 ^ -1))) >> 31)) & 2)) - (v5659 + ((~(((v5660 ^ -1) | (-(v5660 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5819 = (int)((unsigned int)((int)((unsigned int)v5636 >> 2)) >> 1);
    v5721[v5818] = v5819;
    int * v5723 = v5632->cache_dirty;
    v5723[v5818] = 0;
    int * v5725 = v5632->cache_age;
    v5725[v5818] = 1;
    int * v5727 = v5632->cache_age;
    int v5728 = v5727[v5818];
    int v5729 = v5727[v5747];
    int v5825 = v5729 + ((int)((unsigned int)(v5729 - v5728) >> 31));
    v5727[v5747] = v5825;
    int * v5731 = v5632->cache_age;
    int v5732 = v5731[v5748];
    int v5827 = v5732 + ((int)((unsigned int)(v5732 - v5728) >> 31));
    v5731[v5748] = v5827;
    int * v5734 = v5632->cache_age;
    v5734[v5818] = 0;
    v5737 = v5818;
  }
  int v5830 = (v5737 * 2) + (((int)((unsigned int)v5636 >> 2)) & 1);
  int v5738 = v5644[v5830];
  int * v5739 = v5632->regs;
  v5739[13] = v5738;
  struct StateT * v5741 = slot_61(v5632);
  return v5741;
}

struct StateT * slot_4(struct StateT * v816) {
  int v817 = v816->timer;
  int v825 = v817 + 1;
  v816->timer = v825;
  int * v819 = v816->regs;
  int v820 = v819[15];
  int v821 = v819[12];
  int v829 = v820 ^ v821;
  v819[12] = v829;
  struct StateT * v823 = slot_5(v816);
  return v823;
}

struct StateT * slot_18(struct StateT * v2017) {
  int v2018 = v2017->timer;
  int v2128 = v2018 + 1;
  v2017->timer = v2128;
  int * v2020 = v2017->regs;
  int v2021 = v2020[11];
  int * v2022 = v2017->cache_tags;
  int v2132 = (((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1)) & 1) * 2;
  int v2023 = v2022[v2132];
  int v2133 = ((((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2024 = v2022[v2133];
  int v2134 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1)) & 3) * 2);
  int v2025 = v2022[v2134];
  int v2135 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2026 = v2022[v2135];
  int v2027 = v2017->timer;
  int v2136 = v2027 + ((100 ^ (((~(((v2025 ^ ((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1))) | (-(v2025 ^ ((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2026 ^ ((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1))) | (-(v2026 ^ ((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2023 ^ ((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1))) | (-(v2023 ^ ((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2024 ^ ((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1))) | (-(v2024 ^ ((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2025 ^ ((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1))) | (-(v2025 ^ ((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2026 ^ ((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1))) | (-(v2026 ^ ((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2017->timer = v2136;
  int * v2029 = v2017->cache_vals;
  bool v2137 = !(((~(((v2023 ^ ((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1))) | (-(v2023 ^ ((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2024 ^ ((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1))) | (-(v2024 ^ ((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v2122;
  if (v2137) {
    int * v2030 = v2017->cache_age;
    int v2139 = ((((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v2024 ^ ((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1))) | (-(v2024 ^ ((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v2031 = v2030[v2139];
    int v2032 = v2030[v2132];
    int v2140 = v2032 + ((int)((unsigned int)(v2032 - v2031) >> 31));
    v2030[v2132] = v2140;
    int * v2034 = v2017->cache_age;
    int v2035 = v2034[v2133];
    int v2142 = v2035 + ((int)((unsigned int)(v2035 - v2031) >> 31));
    v2034[v2133] = v2142;
    int * v2037 = v2017->cache_age;
    v2037[v2139] = 0;
    v2122 = v2139;
  } else {
    int * v2040 = v2017->cache_age;
    int v2146 = (((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1)) & 1) * 2;
    int v2041 = v2040[v2146];
    int * v2042 = v2017->cache_tags;
    int v2043 = v2042[v2146];
    int v2044 = v2040[v2133];
    int v2045 = v2042[v2133];
    bool v2148 = !(((~(((v2025 ^ ((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1))) | (-(v2025 ^ ((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2026 ^ ((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1))) | (-(v2026 ^ ((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v2099;
    if (v2148) {
      int * v2046 = v2017->cache_age;
      int v2150 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2026 ^ ((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1))) | (-(v2026 ^ ((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v2047 = v2046[v2150];
      int v2048 = v2046[v2134];
      int v2151 = v2048 + ((int)((unsigned int)(v2048 - v2047) >> 31));
      v2046[v2134] = v2151;
      int * v2050 = v2017->cache_age;
      int v2051 = v2050[v2135];
      int v2153 = v2051 + ((int)((unsigned int)(v2051 - v2047) >> 31));
      v2050[v2135] = v2153;
      int * v2053 = v2017->cache_age;
      v2053[v2150] = 0;
      v2099 = v2150;
    } else {
      int * v2056 = v2017->cache_age;
      int v2157 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1)) & 3) * 2);
      int v2057 = v2056[v2157];
      int * v2058 = v2017->cache_tags;
      int v2059 = v2058[v2157];
      int v2060 = v2056[v2135];
      int v2061 = v2058[v2135];
      int * v2062 = v2017->cache_dirty;
      int v2160 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2057 + ((~(((v2059 ^ -1) | (-(v2059 ^ -1))) >> 31)) & 2)) - (v2060 + ((~(((v2061 ^ -1) | (-(v2061 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2063 = v2062[v2160];
      bool v2161 = !(v2063 == 0);
      if (v2161) {
        int * v2064 = v2017->cache_tags;
        int v2065 = v2064[v2160];
        int * v2066 = v2017->cache_vals;
        int v2164 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2057 + ((~(((v2059 ^ -1) | (-(v2059 ^ -1))) >> 31)) & 2)) - (v2060 + ((~(((v2061 ^ -1) | (-(v2061 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2067 = v2066[v2164];
        int v2165 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2057 + ((~(((v2059 ^ -1) | (-(v2059 ^ -1))) >> 31)) & 2)) - (v2060 + ((~(((v2061 ^ -1) | (-(v2061 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2068 = v2066[v2165];
        int * v2069 = v2017->mem;
        int v2167 = v2065 * 2;
        v2069[v2167] = v2067;
        int * v2071 = v2017->mem;
        int v2170 = (v2065 * 2) + 1;
        v2071[v2170] = v2068;
        ;
      } else {
        ;
      }
      int * v2076 = v2017->mem;
      int v2175 = ((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1)) * 2;
      int v2077 = v2076[v2175];
      int v2176 = (((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1)) * 2) + 1;
      int v2078 = v2076[v2176];
      int * v2079 = v2017->cache_vals;
      int v2178 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2057 + ((~(((v2059 ^ -1) | (-(v2059 ^ -1))) >> 31)) & 2)) - (v2060 + ((~(((v2061 ^ -1) | (-(v2061 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2079[v2178] = v2077;
      int * v2081 = v2017->cache_vals;
      int v2181 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2057 + ((~(((v2059 ^ -1) | (-(v2059 ^ -1))) >> 31)) & 2)) - (v2060 + ((~(((v2061 ^ -1) | (-(v2061 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2081[v2181] = v2078;
      int * v2083 = v2017->cache_tags;
      int v2184 = (int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1);
      v2083[v2160] = v2184;
      int * v2085 = v2017->cache_dirty;
      v2085[v2160] = 0;
      int * v2087 = v2017->cache_age;
      v2087[v2160] = 1;
      int * v2089 = v2017->cache_age;
      int v2090 = v2089[v2160];
      int v2091 = v2089[v2134];
      int v2190 = v2091 + ((int)((unsigned int)(v2091 - v2090) >> 31));
      v2089[v2134] = v2190;
      int * v2093 = v2017->cache_age;
      int v2094 = v2093[v2135];
      int v2192 = v2094 + ((int)((unsigned int)(v2094 - v2090) >> 31));
      v2093[v2135] = v2192;
      int * v2096 = v2017->cache_age;
      v2096[v2160] = 0;
      v2099 = v2160;
    }
    int * v2100 = v2017->cache_vals;
    int v2195 = v2099 * 2;
    int v2101 = v2100[v2195];
    int v2196 = (v2099 * 2) + 1;
    int v2102 = v2100[v2196];
    int v2197 = (((((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v2041 + ((~(((v2043 ^ -1) | (-(v2043 ^ -1))) >> 31)) & 2)) - (v2044 + ((~(((v2045 ^ -1) | (-(v2045 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2100[v2197] = v2101;
    int * v2104 = v2017->cache_vals;
    int v2200 = ((((((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v2041 + ((~(((v2043 ^ -1) | (-(v2043 ^ -1))) >> 31)) & 2)) - (v2044 + ((~(((v2045 ^ -1) | (-(v2045 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2104[v2200] = v2102;
    int * v2106 = v2017->cache_tags;
    int v2203 = ((((int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v2041 + ((~(((v2043 ^ -1) | (-(v2043 ^ -1))) >> 31)) & 2)) - (v2044 + ((~(((v2045 ^ -1) | (-(v2045 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2204 = (int)((unsigned int)((int)((unsigned int)(v2021 + 4) >> 2)) >> 1);
    v2106[v2203] = v2204;
    int * v2108 = v2017->cache_dirty;
    v2108[v2203] = 0;
    int * v2110 = v2017->cache_age;
    v2110[v2203] = 1;
    int * v2112 = v2017->cache_age;
    int v2113 = v2112[v2203];
    int v2114 = v2112[v2132];
    int v2210 = v2114 + ((int)((unsigned int)(v2114 - v2113) >> 31));
    v2112[v2132] = v2210;
    int * v2116 = v2017->cache_age;
    int v2117 = v2116[v2133];
    int v2212 = v2117 + ((int)((unsigned int)(v2117 - v2113) >> 31));
    v2116[v2133] = v2212;
    int * v2119 = v2017->cache_age;
    v2119[v2203] = 0;
    v2122 = v2203;
  }
  int v2215 = (v2122 * 2) + (((int)((unsigned int)(v2021 + 4) >> 2)) & 1);
  int v2123 = v2029[v2215];
  int * v2124 = v2017->regs;
  v2124[14] = v2123;
  struct StateT * v2126 = slot_21(v2017);
  return v2126;
}

struct StateT * slot_9(struct StateT * v908) {
  int v909 = v908->timer;
  int v913 = v909 + 1;
  v908->timer = v913;
  struct StateT * v911 = slot_10(v908);
  return v911;
}

struct StateT * slot_11(struct StateT * v936) {
  int v937 = v936->timer;
  int v1047 = v937 + 1;
  v936->timer = v1047;
  int * v939 = v936->regs;
  int v940 = v939[11];
  int * v941 = v936->cache_tags;
  int v1051 = (((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1)) & 1) * 2;
  int v942 = v941[v1051];
  int v1052 = ((((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1)) & 1) * 2) + 1;
  int v943 = v941[v1052];
  int v1053 = 4 + ((((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1)) & 3) * 2);
  int v944 = v941[v1053];
  int v1054 = (4 + ((((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v945 = v941[v1054];
  int v946 = v936->timer;
  int v1055 = v946 + ((100 ^ (((~(((v944 ^ ((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1))) | (-(v944 ^ ((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1))))) >> 31)) | (~(((v945 ^ ((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1))) | (-(v945 ^ ((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v942 ^ ((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1))) | (-(v942 ^ ((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1))))) >> 31)) | (~(((v943 ^ ((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1))) | (-(v943 ^ ((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v944 ^ ((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1))) | (-(v944 ^ ((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1))))) >> 31)) | (~(((v945 ^ ((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1))) | (-(v945 ^ ((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1))))) >> 31))) & 104)))));
  v936->timer = v1055;
  int * v948 = v936->cache_vals;
  bool v1056 = !(((~(((v942 ^ ((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1))) | (-(v942 ^ ((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1))))) >> 31)) | (~(((v943 ^ ((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1))) | (-(v943 ^ ((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1))))) >> 31))) == 0);
  int v1041;
  if (v1056) {
    int * v949 = v936->cache_age;
    int v1058 = ((((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1)) & 1) * 2) + ((~(((v943 ^ ((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1))) | (-(v943 ^ ((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1))))) >> 31)) & 1);
    int v950 = v949[v1058];
    int v951 = v949[v1051];
    int v1059 = v951 + ((int)((unsigned int)(v951 - v950) >> 31));
    v949[v1051] = v1059;
    int * v953 = v936->cache_age;
    int v954 = v953[v1052];
    int v1061 = v954 + ((int)((unsigned int)(v954 - v950) >> 31));
    v953[v1052] = v1061;
    int * v956 = v936->cache_age;
    v956[v1058] = 0;
    v1041 = v1058;
  } else {
    int * v959 = v936->cache_age;
    int v1065 = (((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1)) & 1) * 2;
    int v960 = v959[v1065];
    int * v961 = v936->cache_tags;
    int v962 = v961[v1065];
    int v963 = v959[v1052];
    int v964 = v961[v1052];
    bool v1067 = !(((~(((v944 ^ ((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1))) | (-(v944 ^ ((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1))))) >> 31)) | (~(((v945 ^ ((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1))) | (-(v945 ^ ((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1))))) >> 31))) == 0);
    int v1018;
    if (v1067) {
      int * v965 = v936->cache_age;
      int v1069 = (4 + ((((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1)) & 3) * 2)) + ((~(((v945 ^ ((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1))) | (-(v945 ^ ((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1))))) >> 31)) & 1);
      int v966 = v965[v1069];
      int v967 = v965[v1053];
      int v1070 = v967 + ((int)((unsigned int)(v967 - v966) >> 31));
      v965[v1053] = v1070;
      int * v969 = v936->cache_age;
      int v970 = v969[v1054];
      int v1072 = v970 + ((int)((unsigned int)(v970 - v966) >> 31));
      v969[v1054] = v1072;
      int * v972 = v936->cache_age;
      v972[v1069] = 0;
      v1018 = v1069;
    } else {
      int * v975 = v936->cache_age;
      int v1076 = 4 + ((((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1)) & 3) * 2);
      int v976 = v975[v1076];
      int * v977 = v936->cache_tags;
      int v978 = v977[v1076];
      int v979 = v975[v1054];
      int v980 = v977[v1054];
      int * v981 = v936->cache_dirty;
      int v1079 = (4 + ((((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1)) & 3) * 2)) + ((((v976 + ((~(((v978 ^ -1) | (-(v978 ^ -1))) >> 31)) & 2)) - (v979 + ((~(((v980 ^ -1) | (-(v980 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v982 = v981[v1079];
      bool v1080 = !(v982 == 0);
      if (v1080) {
        int * v983 = v936->cache_tags;
        int v984 = v983[v1079];
        int * v985 = v936->cache_vals;
        int v1083 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1)) & 3) * 2)) + ((((v976 + ((~(((v978 ^ -1) | (-(v978 ^ -1))) >> 31)) & 2)) - (v979 + ((~(((v980 ^ -1) | (-(v980 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v986 = v985[v1083];
        int v1084 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1)) & 3) * 2)) + ((((v976 + ((~(((v978 ^ -1) | (-(v978 ^ -1))) >> 31)) & 2)) - (v979 + ((~(((v980 ^ -1) | (-(v980 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v987 = v985[v1084];
        int * v988 = v936->mem;
        int v1086 = v984 * 2;
        v988[v1086] = v986;
        int * v990 = v936->mem;
        int v1089 = (v984 * 2) + 1;
        v990[v1089] = v987;
        ;
      } else {
        ;
      }
      int * v995 = v936->mem;
      int v1094 = ((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1)) * 2;
      int v996 = v995[v1094];
      int v1095 = (((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1)) * 2) + 1;
      int v997 = v995[v1095];
      int * v998 = v936->cache_vals;
      int v1097 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1)) & 3) * 2)) + ((((v976 + ((~(((v978 ^ -1) | (-(v978 ^ -1))) >> 31)) & 2)) - (v979 + ((~(((v980 ^ -1) | (-(v980 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v998[v1097] = v996;
      int * v1000 = v936->cache_vals;
      int v1100 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1)) & 3) * 2)) + ((((v976 + ((~(((v978 ^ -1) | (-(v978 ^ -1))) >> 31)) & 2)) - (v979 + ((~(((v980 ^ -1) | (-(v980 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1000[v1100] = v997;
      int * v1002 = v936->cache_tags;
      int v1103 = (int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1);
      v1002[v1079] = v1103;
      int * v1004 = v936->cache_dirty;
      v1004[v1079] = 0;
      int * v1006 = v936->cache_age;
      v1006[v1079] = 1;
      int * v1008 = v936->cache_age;
      int v1009 = v1008[v1079];
      int v1010 = v1008[v1053];
      int v1109 = v1010 + ((int)((unsigned int)(v1010 - v1009) >> 31));
      v1008[v1053] = v1109;
      int * v1012 = v936->cache_age;
      int v1013 = v1012[v1054];
      int v1111 = v1013 + ((int)((unsigned int)(v1013 - v1009) >> 31));
      v1012[v1054] = v1111;
      int * v1015 = v936->cache_age;
      v1015[v1079] = 0;
      v1018 = v1079;
    }
    int * v1019 = v936->cache_vals;
    int v1114 = v1018 * 2;
    int v1020 = v1019[v1114];
    int v1115 = (v1018 * 2) + 1;
    int v1021 = v1019[v1115];
    int v1116 = (((((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1)) & 1) * 2) + ((((v960 + ((~(((v962 ^ -1) | (-(v962 ^ -1))) >> 31)) & 2)) - (v963 + ((~(((v964 ^ -1) | (-(v964 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1019[v1116] = v1020;
    int * v1023 = v936->cache_vals;
    int v1119 = ((((((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1)) & 1) * 2) + ((((v960 + ((~(((v962 ^ -1) | (-(v962 ^ -1))) >> 31)) & 2)) - (v963 + ((~(((v964 ^ -1) | (-(v964 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1023[v1119] = v1021;
    int * v1025 = v936->cache_tags;
    int v1122 = ((((int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1)) & 1) * 2) + ((((v960 + ((~(((v962 ^ -1) | (-(v962 ^ -1))) >> 31)) & 2)) - (v963 + ((~(((v964 ^ -1) | (-(v964 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1123 = (int)((unsigned int)((int)((unsigned int)v940 >> 2)) >> 1);
    v1025[v1122] = v1123;
    int * v1027 = v936->cache_dirty;
    v1027[v1122] = 0;
    int * v1029 = v936->cache_age;
    v1029[v1122] = 1;
    int * v1031 = v936->cache_age;
    int v1032 = v1031[v1122];
    int v1033 = v1031[v1051];
    int v1129 = v1033 + ((int)((unsigned int)(v1033 - v1032) >> 31));
    v1031[v1051] = v1129;
    int * v1035 = v936->cache_age;
    int v1036 = v1035[v1052];
    int v1131 = v1036 + ((int)((unsigned int)(v1036 - v1032) >> 31));
    v1035[v1052] = v1131;
    int * v1038 = v936->cache_age;
    v1038[v1122] = 0;
    v1041 = v1122;
  }
  int v1134 = (v1041 * 2) + (((int)((unsigned int)v940 >> 2)) & 1);
  int v1042 = v948[v1134];
  int * v1043 = v936->regs;
  v1043[15] = v1042;
  struct StateT * v1045 = slot_13(v936);
  return v1045;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
    s->saved_regs[i] = 0;
  }
  s->regs[2] = 4 * MEM_SIZE;
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
  
  // a10, 10 words: the address is public
  s1.regs[10] = 0;
  s2.regs[10] = 0;
  // a11, 10 words: the address is public
  s1.regs[11] = 40;
  s2.regs[11] = 40;
  // a12, 10 words: the address is public
  s1.regs[12] = 80;
  s2.regs[12] = 80;
  // a13, 10 words: the address is public
  s1.regs[13] = 120;
  s2.regs[13] = 120;
  // its contents, public: the same draw in both states
  for (int i=0; i<10; i++) {
    int v = bounded(0, 1);
    s1.mem[20 + i] = v;
    s2.mem[20 + i] = v;
  }
  // its contents, public: the same draw in both states
  for (int i=0; i<10; i++) {
    int v = bounded(0, 1);
    s1.mem[30 + i] = v;
    s2.mem[30 + i] = v;
  }
  
  // a10's contents, secret: a different draw in each state. f[0] and
  // f[1] are what the comparisons read, so they draw against
  // 1 and the rest against 20.
  s1.mem[0] = secret(0, 1);
  s2.mem[0] = secret(0, 1);
  s1.mem[1] = secret(0, 1);
  s2.mem[1] = secret(0, 1);
  for (int i=2; i<10; i++) {
    s1.mem[0 + i] = secret(0, 20);
    s2.mem[0 + i] = secret(0, 20);
  }
  // a11's contents, secret: the value copied in, drawn separately
  for (int i=0; i<10; i++) {
    s1.mem[10 + i] = secret(0, 20);
    s2.mem[10 + i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}