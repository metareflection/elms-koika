// verify: leak (Eva should report untainted: unknown) [unroll 65]
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
struct StateT2 * slot_1(struct StateT2 * v51);
struct StateT2 * slot_2(struct StateT2 * v477);
struct StateT2 * slot_3(struct StateT2 * v530);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  struct StateT * v953 = v1->a;
  int v954 = v953->timer;
  int * v955 = v953->reg_ready;
  int v956 = v955[0];
  int v1217 = v956 + ((v954 - v956) & (~((v954 - v956) >> 31)));
  v953->timer = v1217;
  int v958 = v953->timer;
  int * v959 = v953->reg_ready;
  int v960 = v959[1];
  int v1220 = v960 + ((v958 - v960) & (~((v958 - v960) >> 31)));
  v953->timer = v1220;
  int v962 = v953->timer;
  int * v963 = v953->reg_ready;
  int v964 = v963[2];
  int v1223 = v964 + ((v962 - v964) & (~((v962 - v964) >> 31)));
  v953->timer = v1223;
  int v966 = v953->timer;
  int * v967 = v953->reg_ready;
  int v968 = v967[3];
  int v1226 = v968 + ((v966 - v968) & (~((v966 - v968) >> 31)));
  v953->timer = v1226;
  int v970 = v953->timer;
  int * v971 = v953->reg_ready;
  int v972 = v971[4];
  int v1229 = v972 + ((v970 - v972) & (~((v970 - v972) >> 31)));
  v953->timer = v1229;
  int v974 = v953->timer;
  int * v975 = v953->reg_ready;
  int v976 = v975[5];
  int v1232 = v976 + ((v974 - v976) & (~((v974 - v976) >> 31)));
  v953->timer = v1232;
  int v978 = v953->timer;
  int * v979 = v953->reg_ready;
  int v980 = v979[6];
  int v1235 = v980 + ((v978 - v980) & (~((v978 - v980) >> 31)));
  v953->timer = v1235;
  int v982 = v953->timer;
  int * v983 = v953->reg_ready;
  int v984 = v983[7];
  int v1238 = v984 + ((v982 - v984) & (~((v982 - v984) >> 31)));
  v953->timer = v1238;
  int v986 = v953->timer;
  int * v987 = v953->reg_ready;
  int v988 = v987[8];
  int v1241 = v988 + ((v986 - v988) & (~((v986 - v988) >> 31)));
  v953->timer = v1241;
  int v990 = v953->timer;
  int * v991 = v953->reg_ready;
  int v992 = v991[9];
  int v1244 = v992 + ((v990 - v992) & (~((v990 - v992) >> 31)));
  v953->timer = v1244;
  int v994 = v953->timer;
  int * v995 = v953->reg_ready;
  int v996 = v995[10];
  int v1247 = v996 + ((v994 - v996) & (~((v994 - v996) >> 31)));
  v953->timer = v1247;
  int v998 = v953->timer;
  int * v999 = v953->reg_ready;
  int v1000 = v999[11];
  int v1250 = v1000 + ((v998 - v1000) & (~((v998 - v1000) >> 31)));
  v953->timer = v1250;
  int v1002 = v953->timer;
  int * v1003 = v953->reg_ready;
  int v1004 = v1003[12];
  int v1253 = v1004 + ((v1002 - v1004) & (~((v1002 - v1004) >> 31)));
  v953->timer = v1253;
  int v1006 = v953->timer;
  int * v1007 = v953->reg_ready;
  int v1008 = v1007[13];
  int v1256 = v1008 + ((v1006 - v1008) & (~((v1006 - v1008) >> 31)));
  v953->timer = v1256;
  int v1010 = v953->timer;
  int * v1011 = v953->reg_ready;
  int v1012 = v1011[14];
  int v1259 = v1012 + ((v1010 - v1012) & (~((v1010 - v1012) >> 31)));
  v953->timer = v1259;
  int v1014 = v953->timer;
  int * v1015 = v953->reg_ready;
  int v1016 = v1015[15];
  int v1262 = v1016 + ((v1014 - v1016) & (~((v1014 - v1016) >> 31)));
  v953->timer = v1262;
  int v1018 = v953->timer;
  int * v1019 = v953->reg_ready;
  int v1020 = v1019[16];
  int v1265 = v1020 + ((v1018 - v1020) & (~((v1018 - v1020) >> 31)));
  v953->timer = v1265;
  int v1022 = v953->timer;
  int * v1023 = v953->reg_ready;
  int v1024 = v1023[17];
  int v1268 = v1024 + ((v1022 - v1024) & (~((v1022 - v1024) >> 31)));
  v953->timer = v1268;
  int v1026 = v953->timer;
  int * v1027 = v953->reg_ready;
  int v1028 = v1027[18];
  int v1271 = v1028 + ((v1026 - v1028) & (~((v1026 - v1028) >> 31)));
  v953->timer = v1271;
  int v1030 = v953->timer;
  int * v1031 = v953->reg_ready;
  int v1032 = v1031[19];
  int v1274 = v1032 + ((v1030 - v1032) & (~((v1030 - v1032) >> 31)));
  v953->timer = v1274;
  int v1034 = v953->timer;
  int * v1035 = v953->reg_ready;
  int v1036 = v1035[20];
  int v1277 = v1036 + ((v1034 - v1036) & (~((v1034 - v1036) >> 31)));
  v953->timer = v1277;
  int v1038 = v953->timer;
  int * v1039 = v953->reg_ready;
  int v1040 = v1039[21];
  int v1280 = v1040 + ((v1038 - v1040) & (~((v1038 - v1040) >> 31)));
  v953->timer = v1280;
  int v1042 = v953->timer;
  int * v1043 = v953->reg_ready;
  int v1044 = v1043[22];
  int v1283 = v1044 + ((v1042 - v1044) & (~((v1042 - v1044) >> 31)));
  v953->timer = v1283;
  int v1046 = v953->timer;
  int * v1047 = v953->reg_ready;
  int v1048 = v1047[23];
  int v1286 = v1048 + ((v1046 - v1048) & (~((v1046 - v1048) >> 31)));
  v953->timer = v1286;
  int v1050 = v953->timer;
  int * v1051 = v953->reg_ready;
  int v1052 = v1051[24];
  int v1289 = v1052 + ((v1050 - v1052) & (~((v1050 - v1052) >> 31)));
  v953->timer = v1289;
  int v1054 = v953->timer;
  int * v1055 = v953->reg_ready;
  int v1056 = v1055[25];
  int v1292 = v1056 + ((v1054 - v1056) & (~((v1054 - v1056) >> 31)));
  v953->timer = v1292;
  int v1058 = v953->timer;
  int * v1059 = v953->reg_ready;
  int v1060 = v1059[26];
  int v1295 = v1060 + ((v1058 - v1060) & (~((v1058 - v1060) >> 31)));
  v953->timer = v1295;
  int v1062 = v953->timer;
  int * v1063 = v953->reg_ready;
  int v1064 = v1063[27];
  int v1298 = v1064 + ((v1062 - v1064) & (~((v1062 - v1064) >> 31)));
  v953->timer = v1298;
  int v1066 = v953->timer;
  int * v1067 = v953->reg_ready;
  int v1068 = v1067[28];
  int v1301 = v1068 + ((v1066 - v1068) & (~((v1066 - v1068) >> 31)));
  v953->timer = v1301;
  int v1070 = v953->timer;
  int * v1071 = v953->reg_ready;
  int v1072 = v1071[29];
  int v1304 = v1072 + ((v1070 - v1072) & (~((v1070 - v1072) >> 31)));
  v953->timer = v1304;
  int v1074 = v953->timer;
  int * v1075 = v953->reg_ready;
  int v1076 = v1075[30];
  int v1307 = v1076 + ((v1074 - v1076) & (~((v1074 - v1076) >> 31)));
  v953->timer = v1307;
  int v1078 = v953->timer;
  int * v1079 = v953->reg_ready;
  int v1080 = v1079[31];
  int v1310 = v1080 + ((v1078 - v1080) & (~((v1078 - v1080) >> 31)));
  v953->timer = v1310;
  struct StateT * v1082 = v1->b;
  int v1083 = v1082->timer;
  int * v1084 = v1082->reg_ready;
  int v1085 = v1084[0];
  int v1313 = v1085 + ((v1083 - v1085) & (~((v1083 - v1085) >> 31)));
  v1082->timer = v1313;
  int v1087 = v1082->timer;
  int * v1088 = v1082->reg_ready;
  int v1089 = v1088[1];
  int v1315 = v1089 + ((v1087 - v1089) & (~((v1087 - v1089) >> 31)));
  v1082->timer = v1315;
  int v1091 = v1082->timer;
  int * v1092 = v1082->reg_ready;
  int v1093 = v1092[2];
  int v1317 = v1093 + ((v1091 - v1093) & (~((v1091 - v1093) >> 31)));
  v1082->timer = v1317;
  int v1095 = v1082->timer;
  int * v1096 = v1082->reg_ready;
  int v1097 = v1096[3];
  int v1319 = v1097 + ((v1095 - v1097) & (~((v1095 - v1097) >> 31)));
  v1082->timer = v1319;
  int v1099 = v1082->timer;
  int * v1100 = v1082->reg_ready;
  int v1101 = v1100[4];
  int v1321 = v1101 + ((v1099 - v1101) & (~((v1099 - v1101) >> 31)));
  v1082->timer = v1321;
  int v1103 = v1082->timer;
  int * v1104 = v1082->reg_ready;
  int v1105 = v1104[5];
  int v1323 = v1105 + ((v1103 - v1105) & (~((v1103 - v1105) >> 31)));
  v1082->timer = v1323;
  int v1107 = v1082->timer;
  int * v1108 = v1082->reg_ready;
  int v1109 = v1108[6];
  int v1325 = v1109 + ((v1107 - v1109) & (~((v1107 - v1109) >> 31)));
  v1082->timer = v1325;
  int v1111 = v1082->timer;
  int * v1112 = v1082->reg_ready;
  int v1113 = v1112[7];
  int v1327 = v1113 + ((v1111 - v1113) & (~((v1111 - v1113) >> 31)));
  v1082->timer = v1327;
  int v1115 = v1082->timer;
  int * v1116 = v1082->reg_ready;
  int v1117 = v1116[8];
  int v1329 = v1117 + ((v1115 - v1117) & (~((v1115 - v1117) >> 31)));
  v1082->timer = v1329;
  int v1119 = v1082->timer;
  int * v1120 = v1082->reg_ready;
  int v1121 = v1120[9];
  int v1331 = v1121 + ((v1119 - v1121) & (~((v1119 - v1121) >> 31)));
  v1082->timer = v1331;
  int v1123 = v1082->timer;
  int * v1124 = v1082->reg_ready;
  int v1125 = v1124[10];
  int v1333 = v1125 + ((v1123 - v1125) & (~((v1123 - v1125) >> 31)));
  v1082->timer = v1333;
  int v1127 = v1082->timer;
  int * v1128 = v1082->reg_ready;
  int v1129 = v1128[11];
  int v1335 = v1129 + ((v1127 - v1129) & (~((v1127 - v1129) >> 31)));
  v1082->timer = v1335;
  int v1131 = v1082->timer;
  int * v1132 = v1082->reg_ready;
  int v1133 = v1132[12];
  int v1337 = v1133 + ((v1131 - v1133) & (~((v1131 - v1133) >> 31)));
  v1082->timer = v1337;
  int v1135 = v1082->timer;
  int * v1136 = v1082->reg_ready;
  int v1137 = v1136[13];
  int v1339 = v1137 + ((v1135 - v1137) & (~((v1135 - v1137) >> 31)));
  v1082->timer = v1339;
  int v1139 = v1082->timer;
  int * v1140 = v1082->reg_ready;
  int v1141 = v1140[14];
  int v1341 = v1141 + ((v1139 - v1141) & (~((v1139 - v1141) >> 31)));
  v1082->timer = v1341;
  int v1143 = v1082->timer;
  int * v1144 = v1082->reg_ready;
  int v1145 = v1144[15];
  int v1343 = v1145 + ((v1143 - v1145) & (~((v1143 - v1145) >> 31)));
  v1082->timer = v1343;
  int v1147 = v1082->timer;
  int * v1148 = v1082->reg_ready;
  int v1149 = v1148[16];
  int v1345 = v1149 + ((v1147 - v1149) & (~((v1147 - v1149) >> 31)));
  v1082->timer = v1345;
  int v1151 = v1082->timer;
  int * v1152 = v1082->reg_ready;
  int v1153 = v1152[17];
  int v1347 = v1153 + ((v1151 - v1153) & (~((v1151 - v1153) >> 31)));
  v1082->timer = v1347;
  int v1155 = v1082->timer;
  int * v1156 = v1082->reg_ready;
  int v1157 = v1156[18];
  int v1349 = v1157 + ((v1155 - v1157) & (~((v1155 - v1157) >> 31)));
  v1082->timer = v1349;
  int v1159 = v1082->timer;
  int * v1160 = v1082->reg_ready;
  int v1161 = v1160[19];
  int v1351 = v1161 + ((v1159 - v1161) & (~((v1159 - v1161) >> 31)));
  v1082->timer = v1351;
  int v1163 = v1082->timer;
  int * v1164 = v1082->reg_ready;
  int v1165 = v1164[20];
  int v1353 = v1165 + ((v1163 - v1165) & (~((v1163 - v1165) >> 31)));
  v1082->timer = v1353;
  int v1167 = v1082->timer;
  int * v1168 = v1082->reg_ready;
  int v1169 = v1168[21];
  int v1355 = v1169 + ((v1167 - v1169) & (~((v1167 - v1169) >> 31)));
  v1082->timer = v1355;
  int v1171 = v1082->timer;
  int * v1172 = v1082->reg_ready;
  int v1173 = v1172[22];
  int v1357 = v1173 + ((v1171 - v1173) & (~((v1171 - v1173) >> 31)));
  v1082->timer = v1357;
  int v1175 = v1082->timer;
  int * v1176 = v1082->reg_ready;
  int v1177 = v1176[23];
  int v1359 = v1177 + ((v1175 - v1177) & (~((v1175 - v1177) >> 31)));
  v1082->timer = v1359;
  int v1179 = v1082->timer;
  int * v1180 = v1082->reg_ready;
  int v1181 = v1180[24];
  int v1361 = v1181 + ((v1179 - v1181) & (~((v1179 - v1181) >> 31)));
  v1082->timer = v1361;
  int v1183 = v1082->timer;
  int * v1184 = v1082->reg_ready;
  int v1185 = v1184[25];
  int v1363 = v1185 + ((v1183 - v1185) & (~((v1183 - v1185) >> 31)));
  v1082->timer = v1363;
  int v1187 = v1082->timer;
  int * v1188 = v1082->reg_ready;
  int v1189 = v1188[26];
  int v1365 = v1189 + ((v1187 - v1189) & (~((v1187 - v1189) >> 31)));
  v1082->timer = v1365;
  int v1191 = v1082->timer;
  int * v1192 = v1082->reg_ready;
  int v1193 = v1192[27];
  int v1367 = v1193 + ((v1191 - v1193) & (~((v1191 - v1193) >> 31)));
  v1082->timer = v1367;
  int v1195 = v1082->timer;
  int * v1196 = v1082->reg_ready;
  int v1197 = v1196[28];
  int v1369 = v1197 + ((v1195 - v1197) & (~((v1195 - v1197) >> 31)));
  v1082->timer = v1369;
  int v1199 = v1082->timer;
  int * v1200 = v1082->reg_ready;
  int v1201 = v1200[29];
  int v1371 = v1201 + ((v1199 - v1201) & (~((v1199 - v1201) >> 31)));
  v1082->timer = v1371;
  int v1203 = v1082->timer;
  int * v1204 = v1082->reg_ready;
  int v1205 = v1204[30];
  int v1373 = v1205 + ((v1203 - v1205) & (~((v1203 - v1205) >> 31)));
  v1082->timer = v1373;
  int v1207 = v1082->timer;
  int * v1208 = v1082->reg_ready;
  int v1209 = v1208[31];
  int v1375 = v1209 + ((v1207 - v1209) & (~((v1207 - v1209) >> 31)));
  v1082->timer = v1375;
  return v1;
}

struct StateT2 * slot_1(struct StateT2 * v51) {
  struct StateT * v52 = v51->a;
  int v53 = v52->timer;
  struct StateT * v54 = v51->b;
  int v55 = v54->timer;
  bool v286 = v53 == v55;
  squared_assert(v286);
  squared_assume(v286);
  struct StateT * v58 = v51->a;
  int v59 = v58->timer;
  int v288 = v59 + 1;
  v58->timer = v288;
  struct StateT * v61 = v51->b;
  int v62 = v61->timer;
  int v290 = v62 + 1;
  v61->timer = v290;
  struct StateT * v64 = v51->a;
  int * v65 = v64->reg_ready;
  int v66 = v65[10];
  int * v67 = v64->regs;
  int v68 = v67[10];
  int * v69 = v64->cache_tags;
  int v296 = (((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1)) & 1) * 2;
  int v70 = v69[v296];
  int v297 = ((((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1)) & 1) * 2) + 1;
  int v71 = v69[v297];
  int v298 = 4 + ((((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1)) & 3) * 2);
  int v72 = v69[v298];
  int v299 = (4 + ((((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v73 = v69[v299];
  int * v74 = v64->cache_vals;
  bool v300 = !(((~(((v70 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))) | (-(v70 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))))) >> 31)) | (~(((v71 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))) | (-(v71 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))))) >> 31))) == 0);
  int v167;
  if (v300) {
    int * v75 = v64->cache_age;
    int v302 = ((((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1)) & 1) * 2) + ((~(((v71 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))) | (-(v71 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))))) >> 31)) & 1);
    int v76 = v75[v302];
    int v77 = v75[v296];
    int v303 = v77 + ((int)((unsigned int)(v77 - v76) >> 31));
    v75[v296] = v303;
    int * v79 = v64->cache_age;
    int v80 = v79[v297];
    int v305 = v80 + ((int)((unsigned int)(v80 - v76) >> 31));
    v79[v297] = v305;
    int * v82 = v64->cache_age;
    v82[v302] = 0;
    v167 = v302;
  } else {
    int * v85 = v64->cache_age;
    int v309 = (((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1)) & 1) * 2;
    int v86 = v85[v309];
    int * v87 = v64->cache_tags;
    int v88 = v87[v309];
    int v89 = v85[v297];
    int v90 = v87[v297];
    bool v311 = !(((~(((v72 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))) | (-(v72 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))))) >> 31)) | (~(((v73 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))) | (-(v73 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))))) >> 31))) == 0);
    int v144;
    if (v311) {
      int * v91 = v64->cache_age;
      int v313 = (4 + ((((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1)) & 3) * 2)) + ((~(((v73 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))) | (-(v73 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))))) >> 31)) & 1);
      int v92 = v91[v313];
      int v93 = v91[v298];
      int v314 = v93 + ((int)((unsigned int)(v93 - v92) >> 31));
      v91[v298] = v314;
      int * v95 = v64->cache_age;
      int v96 = v95[v299];
      int v316 = v96 + ((int)((unsigned int)(v96 - v92) >> 31));
      v95[v299] = v316;
      int * v98 = v64->cache_age;
      v98[v313] = 0;
      v144 = v313;
    } else {
      int * v101 = v64->cache_age;
      int v320 = 4 + ((((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1)) & 3) * 2);
      int v102 = v101[v320];
      int * v103 = v64->cache_tags;
      int v104 = v103[v320];
      int v105 = v101[v299];
      int v106 = v103[v299];
      int * v107 = v64->cache_dirty;
      int v323 = (4 + ((((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1)) & 3) * 2)) + ((((v102 + ((~(((v104 ^ -1) | (-(v104 ^ -1))) >> 31)) & 2)) - (v105 + ((~(((v106 ^ -1) | (-(v106 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v108 = v107[v323];
      bool v324 = !(v108 == 0);
      if (v324) {
        int * v109 = v64->cache_tags;
        int v110 = v109[v323];
        int * v111 = v64->cache_vals;
        int v327 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1)) & 3) * 2)) + ((((v102 + ((~(((v104 ^ -1) | (-(v104 ^ -1))) >> 31)) & 2)) - (v105 + ((~(((v106 ^ -1) | (-(v106 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v112 = v111[v327];
        int v328 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1)) & 3) * 2)) + ((((v102 + ((~(((v104 ^ -1) | (-(v104 ^ -1))) >> 31)) & 2)) - (v105 + ((~(((v106 ^ -1) | (-(v106 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v113 = v111[v328];
        int * v114 = v64->mem;
        int v330 = v110 * 2;
        v114[v330] = v112;
        int * v116 = v64->mem;
        int v333 = (v110 * 2) + 1;
        v116[v333] = v113;
        ;
      } else {
        ;
      }
      int * v121 = v64->mem;
      int v338 = ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1)) * 2;
      int v122 = v121[v338];
      int v339 = (((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1)) * 2) + 1;
      int v123 = v121[v339];
      int * v124 = v64->cache_vals;
      int v341 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1)) & 3) * 2)) + ((((v102 + ((~(((v104 ^ -1) | (-(v104 ^ -1))) >> 31)) & 2)) - (v105 + ((~(((v106 ^ -1) | (-(v106 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v124[v341] = v122;
      int * v126 = v64->cache_vals;
      int v344 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1)) & 3) * 2)) + ((((v102 + ((~(((v104 ^ -1) | (-(v104 ^ -1))) >> 31)) & 2)) - (v105 + ((~(((v106 ^ -1) | (-(v106 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v126[v344] = v123;
      int * v128 = v64->cache_tags;
      int v347 = (int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1);
      v128[v323] = v347;
      int * v130 = v64->cache_dirty;
      v130[v323] = 0;
      int * v132 = v64->cache_age;
      v132[v323] = 1;
      int * v134 = v64->cache_age;
      int v135 = v134[v323];
      int v136 = v134[v298];
      int v353 = v136 + ((int)((unsigned int)(v136 - v135) >> 31));
      v134[v298] = v353;
      int * v138 = v64->cache_age;
      int v139 = v138[v299];
      int v355 = v139 + ((int)((unsigned int)(v139 - v135) >> 31));
      v138[v299] = v355;
      int * v141 = v64->cache_age;
      v141[v323] = 0;
      v144 = v323;
    }
    int * v145 = v64->cache_vals;
    int v358 = v144 * 2;
    int v146 = v145[v358];
    int v359 = (v144 * 2) + 1;
    int v147 = v145[v359];
    int v360 = (((((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1)) & 1) * 2) + ((((v86 + ((~(((v88 ^ -1) | (-(v88 ^ -1))) >> 31)) & 2)) - (v89 + ((~(((v90 ^ -1) | (-(v90 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v145[v360] = v146;
    int * v149 = v64->cache_vals;
    int v363 = ((((((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1)) & 1) * 2) + ((((v86 + ((~(((v88 ^ -1) | (-(v88 ^ -1))) >> 31)) & 2)) - (v89 + ((~(((v90 ^ -1) | (-(v90 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v149[v363] = v147;
    int * v151 = v64->cache_tags;
    int v366 = ((((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1)) & 1) * 2) + ((((v86 + ((~(((v88 ^ -1) | (-(v88 ^ -1))) >> 31)) & 2)) - (v89 + ((~(((v90 ^ -1) | (-(v90 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v367 = (int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1);
    v151[v366] = v367;
    int * v153 = v64->cache_dirty;
    v153[v366] = 0;
    int * v155 = v64->cache_age;
    v155[v366] = 1;
    int * v157 = v64->cache_age;
    int v158 = v157[v366];
    int v159 = v157[v296];
    int v373 = v159 + ((int)((unsigned int)(v159 - v158) >> 31));
    v157[v296] = v373;
    int * v161 = v64->cache_age;
    int v162 = v161[v297];
    int v375 = v162 + ((int)((unsigned int)(v162 - v158) >> 31));
    v161[v297] = v375;
    int * v164 = v64->cache_age;
    v164[v366] = 0;
    v167 = v366;
  }
  int v378 = (v167 * 2) + (((int)((unsigned int)v68 >> 2)) & 1);
  int v168 = v74[v378];
  int * v169 = v64->reg_ready;
  int v381 = ((v66 + ((v59 - v66) & (~((v59 - v66) >> 31)))) + 1) + ((100 ^ (((~(((v72 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))) | (-(v72 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))))) >> 31)) | (~(((v73 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))) | (-(v73 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v70 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))) | (-(v70 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))))) >> 31)) | (~(((v71 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))) | (-(v71 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v72 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))) | (-(v72 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))))) >> 31)) | (~(((v73 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))) | (-(v73 ^ ((int)((unsigned int)((int)((unsigned int)v68 >> 2)) >> 1))))) >> 31))) & 104)))));
  v169[11] = v381;
  int * v171 = v64->regs;
  v171[11] = v168;
  struct StateT * v173 = v51->b;
  int * v174 = v173->reg_ready;
  int v175 = v174[10];
  int * v176 = v173->regs;
  int v177 = v176[10];
  int * v178 = v173->cache_tags;
  int v388 = (((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1)) & 1) * 2;
  int v179 = v178[v388];
  int v389 = ((((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1)) & 1) * 2) + 1;
  int v180 = v178[v389];
  int v390 = 4 + ((((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1)) & 3) * 2);
  int v181 = v178[v390];
  int v391 = (4 + ((((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v182 = v178[v391];
  int * v183 = v173->cache_vals;
  bool v392 = !(((~(((v179 ^ ((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1))) | (-(v179 ^ ((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1))))) >> 31)) | (~(((v180 ^ ((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1))) | (-(v180 ^ ((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1))))) >> 31))) == 0);
  int v276;
  if (v392) {
    int * v184 = v173->cache_age;
    int v394 = ((((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1)) & 1) * 2) + ((~(((v180 ^ ((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1))) | (-(v180 ^ ((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1))))) >> 31)) & 1);
    int v185 = v184[v394];
    int v186 = v184[v388];
    int v395 = v186 + ((int)((unsigned int)(v186 - v185) >> 31));
    v184[v388] = v395;
    int * v188 = v173->cache_age;
    int v189 = v188[v389];
    int v397 = v189 + ((int)((unsigned int)(v189 - v185) >> 31));
    v188[v389] = v397;
    int * v191 = v173->cache_age;
    v191[v394] = 0;
    v276 = v394;
  } else {
    int * v194 = v173->cache_age;
    int v401 = (((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1)) & 1) * 2;
    int v195 = v194[v401];
    int * v196 = v173->cache_tags;
    int v197 = v196[v401];
    int v198 = v194[v389];
    int v199 = v196[v389];
    bool v403 = !(((~(((v181 ^ ((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1))) | (-(v181 ^ ((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1))))) >> 31)) | (~(((v182 ^ ((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1))) | (-(v182 ^ ((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1))))) >> 31))) == 0);
    int v253;
    if (v403) {
      int * v200 = v173->cache_age;
      int v405 = (4 + ((((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1)) & 3) * 2)) + ((~(((v182 ^ ((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1))) | (-(v182 ^ ((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1))))) >> 31)) & 1);
      int v201 = v200[v405];
      int v202 = v200[v390];
      int v406 = v202 + ((int)((unsigned int)(v202 - v201) >> 31));
      v200[v390] = v406;
      int * v204 = v173->cache_age;
      int v205 = v204[v391];
      int v408 = v205 + ((int)((unsigned int)(v205 - v201) >> 31));
      v204[v391] = v408;
      int * v207 = v173->cache_age;
      v207[v405] = 0;
      v253 = v405;
    } else {
      int * v210 = v173->cache_age;
      int v412 = 4 + ((((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1)) & 3) * 2);
      int v211 = v210[v412];
      int * v212 = v173->cache_tags;
      int v213 = v212[v412];
      int v214 = v210[v391];
      int v215 = v212[v391];
      int * v216 = v173->cache_dirty;
      int v415 = (4 + ((((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1)) & 3) * 2)) + ((((v211 + ((~(((v213 ^ -1) | (-(v213 ^ -1))) >> 31)) & 2)) - (v214 + ((~(((v215 ^ -1) | (-(v215 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v217 = v216[v415];
      bool v416 = !(v217 == 0);
      if (v416) {
        int * v218 = v173->cache_tags;
        int v219 = v218[v415];
        int * v220 = v173->cache_vals;
        int v419 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1)) & 3) * 2)) + ((((v211 + ((~(((v213 ^ -1) | (-(v213 ^ -1))) >> 31)) & 2)) - (v214 + ((~(((v215 ^ -1) | (-(v215 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v221 = v220[v419];
        int v420 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1)) & 3) * 2)) + ((((v211 + ((~(((v213 ^ -1) | (-(v213 ^ -1))) >> 31)) & 2)) - (v214 + ((~(((v215 ^ -1) | (-(v215 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v222 = v220[v420];
        int * v223 = v173->mem;
        int v422 = v219 * 2;
        v223[v422] = v221;
        int * v225 = v173->mem;
        int v425 = (v219 * 2) + 1;
        v225[v425] = v222;
        ;
      } else {
        ;
      }
      int * v230 = v173->mem;
      int v430 = ((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1)) * 2;
      int v231 = v230[v430];
      int v431 = (((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1)) * 2) + 1;
      int v232 = v230[v431];
      int * v233 = v173->cache_vals;
      int v433 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1)) & 3) * 2)) + ((((v211 + ((~(((v213 ^ -1) | (-(v213 ^ -1))) >> 31)) & 2)) - (v214 + ((~(((v215 ^ -1) | (-(v215 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v233[v433] = v231;
      int * v235 = v173->cache_vals;
      int v436 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1)) & 3) * 2)) + ((((v211 + ((~(((v213 ^ -1) | (-(v213 ^ -1))) >> 31)) & 2)) - (v214 + ((~(((v215 ^ -1) | (-(v215 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v235[v436] = v232;
      int * v237 = v173->cache_tags;
      int v439 = (int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1);
      v237[v415] = v439;
      int * v239 = v173->cache_dirty;
      v239[v415] = 0;
      int * v241 = v173->cache_age;
      v241[v415] = 1;
      int * v243 = v173->cache_age;
      int v244 = v243[v415];
      int v245 = v243[v390];
      int v445 = v245 + ((int)((unsigned int)(v245 - v244) >> 31));
      v243[v390] = v445;
      int * v247 = v173->cache_age;
      int v248 = v247[v391];
      int v447 = v248 + ((int)((unsigned int)(v248 - v244) >> 31));
      v247[v391] = v447;
      int * v250 = v173->cache_age;
      v250[v415] = 0;
      v253 = v415;
    }
    int * v254 = v173->cache_vals;
    int v450 = v253 * 2;
    int v255 = v254[v450];
    int v451 = (v253 * 2) + 1;
    int v256 = v254[v451];
    int v452 = (((((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1)) & 1) * 2) + ((((v195 + ((~(((v197 ^ -1) | (-(v197 ^ -1))) >> 31)) & 2)) - (v198 + ((~(((v199 ^ -1) | (-(v199 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v254[v452] = v255;
    int * v258 = v173->cache_vals;
    int v455 = ((((((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1)) & 1) * 2) + ((((v195 + ((~(((v197 ^ -1) | (-(v197 ^ -1))) >> 31)) & 2)) - (v198 + ((~(((v199 ^ -1) | (-(v199 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v258[v455] = v256;
    int * v260 = v173->cache_tags;
    int v458 = ((((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1)) & 1) * 2) + ((((v195 + ((~(((v197 ^ -1) | (-(v197 ^ -1))) >> 31)) & 2)) - (v198 + ((~(((v199 ^ -1) | (-(v199 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v459 = (int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1);
    v260[v458] = v459;
    int * v262 = v173->cache_dirty;
    v262[v458] = 0;
    int * v264 = v173->cache_age;
    v264[v458] = 1;
    int * v266 = v173->cache_age;
    int v267 = v266[v458];
    int v268 = v266[v388];
    int v465 = v268 + ((int)((unsigned int)(v268 - v267) >> 31));
    v266[v388] = v465;
    int * v270 = v173->cache_age;
    int v271 = v270[v389];
    int v467 = v271 + ((int)((unsigned int)(v271 - v267) >> 31));
    v270[v389] = v467;
    int * v273 = v173->cache_age;
    v273[v458] = 0;
    v276 = v458;
  }
  int v470 = (v276 * 2) + (((int)((unsigned int)v177 >> 2)) & 1);
  int v277 = v183[v470];
  int * v278 = v173->reg_ready;
  int v472 = ((v175 + ((v62 - v175) & (~((v62 - v175) >> 31)))) + 1) + ((100 ^ (((~(((v181 ^ ((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1))) | (-(v181 ^ ((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1))))) >> 31)) | (~(((v182 ^ ((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1))) | (-(v182 ^ ((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v179 ^ ((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1))) | (-(v179 ^ ((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1))))) >> 31)) | (~(((v180 ^ ((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1))) | (-(v180 ^ ((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v181 ^ ((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1))) | (-(v181 ^ ((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1))))) >> 31)) | (~(((v182 ^ ((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1))) | (-(v182 ^ ((int)((unsigned int)((int)((unsigned int)v177 >> 2)) >> 1))))) >> 31))) & 104)))));
  v278[11] = v472;
  int * v280 = v173->regs;
  v280[11] = v277;
  struct StateT2 * v282 = slot_2(v51);
  return v282;
}

struct StateT2 * slot_2(struct StateT2 * v477) {
  struct StateT * v478 = v477->a;
  int v479 = v478->timer;
  struct StateT * v480 = v477->b;
  int v481 = v480->timer;
  bool v510 = v479 == v481;
  squared_assert(v510);
  squared_assume(v510);
  struct StateT * v484 = v477->a;
  int v485 = v484->timer;
  int v512 = v485 + 1;
  v484->timer = v512;
  struct StateT * v487 = v477->b;
  int v488 = v487->timer;
  int v514 = v488 + 1;
  v487->timer = v514;
  struct StateT * v490 = v477->a;
  int * v491 = v490->reg_ready;
  int v492 = v491[11];
  int * v493 = v490->regs;
  int v494 = v493[11];
  int v519 = (v492 + ((v485 - v492) & (~((v485 - v492) >> 31)))) + 1;
  v491[11] = v519;
  int * v496 = v490->regs;
  int v521 = v494 << 2;
  v496[11] = v521;
  struct StateT * v498 = v477->b;
  int * v499 = v498->reg_ready;
  int v500 = v499[11];
  int * v501 = v498->regs;
  int v502 = v501[11];
  int v525 = (v500 + ((v488 - v500) & (~((v488 - v500) >> 31)))) + 1;
  v499[11] = v525;
  int * v504 = v498->regs;
  int v527 = v502 << 2;
  v504[11] = v527;
  struct StateT2 * v506 = slot_3(v477);
  return v506;
}

struct StateT2 * slot_3(struct StateT2 * v530) {
  struct StateT * v531 = v530->a;
  int v532 = v531->timer;
  struct StateT * v533 = v530->b;
  int v534 = v533->timer;
  bool v764 = v532 == v534;
  squared_assert(v764);
  squared_assume(v764);
  struct StateT * v537 = v530->a;
  int v538 = v537->timer;
  int v766 = v538 + 1;
  v537->timer = v766;
  struct StateT * v540 = v530->b;
  int v541 = v540->timer;
  int v768 = v541 + 1;
  v540->timer = v768;
  struct StateT * v543 = v530->a;
  int * v544 = v543->reg_ready;
  int v545 = v544[11];
  int * v546 = v543->regs;
  int v547 = v546[11];
  int * v548 = v543->cache_tags;
  int v774 = (((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1)) & 1) * 2;
  int v549 = v548[v774];
  int v775 = ((((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v550 = v548[v775];
  int v776 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1)) & 3) * 2);
  int v551 = v548[v776];
  int v777 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v552 = v548[v777];
  int * v553 = v543->cache_vals;
  bool v778 = !(((~(((v549 ^ ((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1))) | (-(v549 ^ ((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v550 ^ ((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1))) | (-(v550 ^ ((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v646;
  if (v778) {
    int * v554 = v543->cache_age;
    int v780 = ((((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v550 ^ ((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1))) | (-(v550 ^ ((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v555 = v554[v780];
    int v556 = v554[v774];
    int v781 = v556 + ((int)((unsigned int)(v556 - v555) >> 31));
    v554[v774] = v781;
    int * v558 = v543->cache_age;
    int v559 = v558[v775];
    int v783 = v559 + ((int)((unsigned int)(v559 - v555) >> 31));
    v558[v775] = v783;
    int * v561 = v543->cache_age;
    v561[v780] = 0;
    v646 = v780;
  } else {
    int * v564 = v543->cache_age;
    int v787 = (((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1)) & 1) * 2;
    int v565 = v564[v787];
    int * v566 = v543->cache_tags;
    int v567 = v566[v787];
    int v568 = v564[v775];
    int v569 = v566[v775];
    bool v789 = !(((~(((v551 ^ ((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1))) | (-(v551 ^ ((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v552 ^ ((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1))) | (-(v552 ^ ((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v623;
    if (v789) {
      int * v570 = v543->cache_age;
      int v791 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v552 ^ ((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1))) | (-(v552 ^ ((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v571 = v570[v791];
      int v572 = v570[v776];
      int v792 = v572 + ((int)((unsigned int)(v572 - v571) >> 31));
      v570[v776] = v792;
      int * v574 = v543->cache_age;
      int v575 = v574[v777];
      int v794 = v575 + ((int)((unsigned int)(v575 - v571) >> 31));
      v574[v777] = v794;
      int * v577 = v543->cache_age;
      v577[v791] = 0;
      v623 = v791;
    } else {
      int * v580 = v543->cache_age;
      int v798 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1)) & 3) * 2);
      int v581 = v580[v798];
      int * v582 = v543->cache_tags;
      int v583 = v582[v798];
      int v584 = v580[v777];
      int v585 = v582[v777];
      int * v586 = v543->cache_dirty;
      int v801 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v581 + ((~(((v583 ^ -1) | (-(v583 ^ -1))) >> 31)) & 2)) - (v584 + ((~(((v585 ^ -1) | (-(v585 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v587 = v586[v801];
      bool v802 = !(v587 == 0);
      if (v802) {
        int * v588 = v543->cache_tags;
        int v589 = v588[v801];
        int * v590 = v543->cache_vals;
        int v805 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v581 + ((~(((v583 ^ -1) | (-(v583 ^ -1))) >> 31)) & 2)) - (v584 + ((~(((v585 ^ -1) | (-(v585 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v591 = v590[v805];
        int v806 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v581 + ((~(((v583 ^ -1) | (-(v583 ^ -1))) >> 31)) & 2)) - (v584 + ((~(((v585 ^ -1) | (-(v585 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v592 = v590[v806];
        int * v593 = v543->mem;
        int v808 = v589 * 2;
        v593[v808] = v591;
        int * v595 = v543->mem;
        int v811 = (v589 * 2) + 1;
        v595[v811] = v592;
        ;
      } else {
        ;
      }
      int * v600 = v543->mem;
      int v816 = ((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1)) * 2;
      int v601 = v600[v816];
      int v817 = (((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1)) * 2) + 1;
      int v602 = v600[v817];
      int * v603 = v543->cache_vals;
      int v819 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v581 + ((~(((v583 ^ -1) | (-(v583 ^ -1))) >> 31)) & 2)) - (v584 + ((~(((v585 ^ -1) | (-(v585 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v603[v819] = v601;
      int * v605 = v543->cache_vals;
      int v822 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v581 + ((~(((v583 ^ -1) | (-(v583 ^ -1))) >> 31)) & 2)) - (v584 + ((~(((v585 ^ -1) | (-(v585 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v605[v822] = v602;
      int * v607 = v543->cache_tags;
      int v825 = (int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1);
      v607[v801] = v825;
      int * v609 = v543->cache_dirty;
      v609[v801] = 0;
      int * v611 = v543->cache_age;
      v611[v801] = 1;
      int * v613 = v543->cache_age;
      int v614 = v613[v801];
      int v615 = v613[v776];
      int v831 = v615 + ((int)((unsigned int)(v615 - v614) >> 31));
      v613[v776] = v831;
      int * v617 = v543->cache_age;
      int v618 = v617[v777];
      int v833 = v618 + ((int)((unsigned int)(v618 - v614) >> 31));
      v617[v777] = v833;
      int * v620 = v543->cache_age;
      v620[v801] = 0;
      v623 = v801;
    }
    int * v624 = v543->cache_vals;
    int v836 = v623 * 2;
    int v625 = v624[v836];
    int v837 = (v623 * 2) + 1;
    int v626 = v624[v837];
    int v838 = (((((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v565 + ((~(((v567 ^ -1) | (-(v567 ^ -1))) >> 31)) & 2)) - (v568 + ((~(((v569 ^ -1) | (-(v569 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v624[v838] = v625;
    int * v628 = v543->cache_vals;
    int v841 = ((((((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v565 + ((~(((v567 ^ -1) | (-(v567 ^ -1))) >> 31)) & 2)) - (v568 + ((~(((v569 ^ -1) | (-(v569 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v628[v841] = v626;
    int * v630 = v543->cache_tags;
    int v844 = ((((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v565 + ((~(((v567 ^ -1) | (-(v567 ^ -1))) >> 31)) & 2)) - (v568 + ((~(((v569 ^ -1) | (-(v569 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v845 = (int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1);
    v630[v844] = v845;
    int * v632 = v543->cache_dirty;
    v632[v844] = 0;
    int * v634 = v543->cache_age;
    v634[v844] = 1;
    int * v636 = v543->cache_age;
    int v637 = v636[v844];
    int v638 = v636[v774];
    int v851 = v638 + ((int)((unsigned int)(v638 - v637) >> 31));
    v636[v774] = v851;
    int * v640 = v543->cache_age;
    int v641 = v640[v775];
    int v853 = v641 + ((int)((unsigned int)(v641 - v637) >> 31));
    v640[v775] = v853;
    int * v643 = v543->cache_age;
    v643[v844] = 0;
    v646 = v844;
  }
  int v856 = (v646 * 2) + (((int)((unsigned int)(v547 + 16) >> 2)) & 1);
  int v647 = v553[v856];
  int * v648 = v543->reg_ready;
  int v859 = ((v545 + ((v538 - v545) & (~((v538 - v545) >> 31)))) + 1) + ((100 ^ (((~(((v551 ^ ((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1))) | (-(v551 ^ ((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v552 ^ ((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1))) | (-(v552 ^ ((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v549 ^ ((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1))) | (-(v549 ^ ((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v550 ^ ((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1))) | (-(v550 ^ ((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v551 ^ ((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1))) | (-(v551 ^ ((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v552 ^ ((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1))) | (-(v552 ^ ((int)((unsigned int)((int)((unsigned int)(v547 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v648[12] = v859;
  int * v650 = v543->regs;
  v650[12] = v647;
  struct StateT * v652 = v530->b;
  int * v653 = v652->reg_ready;
  int v654 = v653[11];
  int * v655 = v652->regs;
  int v656 = v655[11];
  int * v657 = v652->cache_tags;
  int v866 = (((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1)) & 1) * 2;
  int v658 = v657[v866];
  int v867 = ((((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v659 = v657[v867];
  int v868 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1)) & 3) * 2);
  int v660 = v657[v868];
  int v869 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v661 = v657[v869];
  int * v662 = v652->cache_vals;
  bool v870 = !(((~(((v658 ^ ((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1))) | (-(v658 ^ ((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v659 ^ ((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1))) | (-(v659 ^ ((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v755;
  if (v870) {
    int * v663 = v652->cache_age;
    int v872 = ((((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v659 ^ ((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1))) | (-(v659 ^ ((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v664 = v663[v872];
    int v665 = v663[v866];
    int v873 = v665 + ((int)((unsigned int)(v665 - v664) >> 31));
    v663[v866] = v873;
    int * v667 = v652->cache_age;
    int v668 = v667[v867];
    int v875 = v668 + ((int)((unsigned int)(v668 - v664) >> 31));
    v667[v867] = v875;
    int * v670 = v652->cache_age;
    v670[v872] = 0;
    v755 = v872;
  } else {
    int * v673 = v652->cache_age;
    int v879 = (((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1)) & 1) * 2;
    int v674 = v673[v879];
    int * v675 = v652->cache_tags;
    int v676 = v675[v879];
    int v677 = v673[v867];
    int v678 = v675[v867];
    bool v881 = !(((~(((v660 ^ ((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1))) | (-(v660 ^ ((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v661 ^ ((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1))) | (-(v661 ^ ((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v732;
    if (v881) {
      int * v679 = v652->cache_age;
      int v883 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v661 ^ ((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1))) | (-(v661 ^ ((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v680 = v679[v883];
      int v681 = v679[v868];
      int v884 = v681 + ((int)((unsigned int)(v681 - v680) >> 31));
      v679[v868] = v884;
      int * v683 = v652->cache_age;
      int v684 = v683[v869];
      int v886 = v684 + ((int)((unsigned int)(v684 - v680) >> 31));
      v683[v869] = v886;
      int * v686 = v652->cache_age;
      v686[v883] = 0;
      v732 = v883;
    } else {
      int * v689 = v652->cache_age;
      int v890 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1)) & 3) * 2);
      int v690 = v689[v890];
      int * v691 = v652->cache_tags;
      int v692 = v691[v890];
      int v693 = v689[v869];
      int v694 = v691[v869];
      int * v695 = v652->cache_dirty;
      int v893 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v690 + ((~(((v692 ^ -1) | (-(v692 ^ -1))) >> 31)) & 2)) - (v693 + ((~(((v694 ^ -1) | (-(v694 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v696 = v695[v893];
      bool v894 = !(v696 == 0);
      if (v894) {
        int * v697 = v652->cache_tags;
        int v698 = v697[v893];
        int * v699 = v652->cache_vals;
        int v897 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v690 + ((~(((v692 ^ -1) | (-(v692 ^ -1))) >> 31)) & 2)) - (v693 + ((~(((v694 ^ -1) | (-(v694 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v700 = v699[v897];
        int v898 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v690 + ((~(((v692 ^ -1) | (-(v692 ^ -1))) >> 31)) & 2)) - (v693 + ((~(((v694 ^ -1) | (-(v694 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v701 = v699[v898];
        int * v702 = v652->mem;
        int v900 = v698 * 2;
        v702[v900] = v700;
        int * v704 = v652->mem;
        int v903 = (v698 * 2) + 1;
        v704[v903] = v701;
        ;
      } else {
        ;
      }
      int * v709 = v652->mem;
      int v908 = ((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1)) * 2;
      int v710 = v709[v908];
      int v909 = (((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1)) * 2) + 1;
      int v711 = v709[v909];
      int * v712 = v652->cache_vals;
      int v911 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v690 + ((~(((v692 ^ -1) | (-(v692 ^ -1))) >> 31)) & 2)) - (v693 + ((~(((v694 ^ -1) | (-(v694 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v712[v911] = v710;
      int * v714 = v652->cache_vals;
      int v914 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v690 + ((~(((v692 ^ -1) | (-(v692 ^ -1))) >> 31)) & 2)) - (v693 + ((~(((v694 ^ -1) | (-(v694 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v714[v914] = v711;
      int * v716 = v652->cache_tags;
      int v917 = (int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1);
      v716[v893] = v917;
      int * v718 = v652->cache_dirty;
      v718[v893] = 0;
      int * v720 = v652->cache_age;
      v720[v893] = 1;
      int * v722 = v652->cache_age;
      int v723 = v722[v893];
      int v724 = v722[v868];
      int v923 = v724 + ((int)((unsigned int)(v724 - v723) >> 31));
      v722[v868] = v923;
      int * v726 = v652->cache_age;
      int v727 = v726[v869];
      int v925 = v727 + ((int)((unsigned int)(v727 - v723) >> 31));
      v726[v869] = v925;
      int * v729 = v652->cache_age;
      v729[v893] = 0;
      v732 = v893;
    }
    int * v733 = v652->cache_vals;
    int v928 = v732 * 2;
    int v734 = v733[v928];
    int v929 = (v732 * 2) + 1;
    int v735 = v733[v929];
    int v930 = (((((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v674 + ((~(((v676 ^ -1) | (-(v676 ^ -1))) >> 31)) & 2)) - (v677 + ((~(((v678 ^ -1) | (-(v678 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v733[v930] = v734;
    int * v737 = v652->cache_vals;
    int v933 = ((((((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v674 + ((~(((v676 ^ -1) | (-(v676 ^ -1))) >> 31)) & 2)) - (v677 + ((~(((v678 ^ -1) | (-(v678 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v737[v933] = v735;
    int * v739 = v652->cache_tags;
    int v936 = ((((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v674 + ((~(((v676 ^ -1) | (-(v676 ^ -1))) >> 31)) & 2)) - (v677 + ((~(((v678 ^ -1) | (-(v678 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v937 = (int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1);
    v739[v936] = v937;
    int * v741 = v652->cache_dirty;
    v741[v936] = 0;
    int * v743 = v652->cache_age;
    v743[v936] = 1;
    int * v745 = v652->cache_age;
    int v746 = v745[v936];
    int v747 = v745[v866];
    int v943 = v747 + ((int)((unsigned int)(v747 - v746) >> 31));
    v745[v866] = v943;
    int * v749 = v652->cache_age;
    int v750 = v749[v867];
    int v945 = v750 + ((int)((unsigned int)(v750 - v746) >> 31));
    v749[v867] = v945;
    int * v752 = v652->cache_age;
    v752[v936] = 0;
    v755 = v936;
  }
  int v948 = (v755 * 2) + (((int)((unsigned int)(v656 + 16) >> 2)) & 1);
  int v756 = v662[v948];
  int * v757 = v652->reg_ready;
  int v950 = ((v654 + ((v541 - v654) & (~((v541 - v654) >> 31)))) + 1) + ((100 ^ (((~(((v660 ^ ((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1))) | (-(v660 ^ ((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v661 ^ ((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1))) | (-(v661 ^ ((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v658 ^ ((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1))) | (-(v658 ^ ((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v659 ^ ((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1))) | (-(v659 ^ ((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v660 ^ ((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1))) | (-(v660 ^ ((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v661 ^ ((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1))) | (-(v661 ^ ((int)((unsigned int)((int)((unsigned int)(v656 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v757[12] = v950;
  int * v759 = v652->regs;
  v759[12] = v756;
  return v530;
}

struct StateT2 * slot_0(struct StateT2 * v2) {
  struct StateT * v3 = v2->a;
  int v4 = v3->timer;
  struct StateT * v5 = v2->b;
  int v6 = v5->timer;
  bool v34 = v4 == v6;
  squared_assert(v34);
  squared_assume(v34);
  struct StateT * v9 = v2->a;
  int v10 = v9->timer;
  int v36 = v10 + 1;
  v9->timer = v36;
  struct StateT * v12 = v2->b;
  int v13 = v12->timer;
  int v38 = v13 + 1;
  v12->timer = v38;
  struct StateT * v15 = v2->a;
  int * v16 = v15->reg_ready;
  int * v18 = v15->regs;
  int v19 = v18[10];
  struct StateT * v20 = v2->b;
  int * v21 = v20->reg_ready;
  int * v23 = v20->regs;
  int v24 = v23[10];
  bool v46 = (v19 == 0) == (v24 == 0);
  squared_diverged(v46);
  squared_assume(v46);
  bool v47 = v19 == 0;
  struct StateT2 * v30;
  if (v47) {
    v30 = v2;
  } else {
    struct StateT2 * v28 = slot_1(v2);
    v30 = v28;
  }
  return v30;
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
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}