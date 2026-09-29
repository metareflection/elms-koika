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
#include <stdio.h>
#include <stdlib.h>

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

struct StateT * slot_12(struct StateT * v1138);
struct StateT * slot_6(struct StateT * v366);
struct StateT * slot_5(struct StateT * v104);
struct StateT * slot_2(struct StateT * v38);
struct StateT * slot_7(struct StateT * v390);
struct StateT * slot_3(struct StateT * v56);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v896);
struct StateT * slot_1(struct StateT * v20);
struct StateT * slot_8(struct StateT * v652);
struct StateT * slot_4(struct StateT * v65);
struct StateT * slot_9(struct StateT * v887);
struct StateT * slot_11(struct StateT * v905);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v1138) {
  int v1139 = v1138->timer;
  int v1140 = v1138->timer;
  int v1270 = v1140 + 1;
  v1138->timer = v1270;
  int * v1142 = v1138->cache_tags;
  int v1143 = v1142[0];
  int * v1144 = v1138->cache_tags;
  int v1145 = v1144[1];
  int * v1146 = v1138->cache_tags;
  int v1147 = v1146[4];
  int * v1148 = v1138->cache_tags;
  int v1149 = v1148[5];
  int * v1150 = v1138->cache_vals;
  bool v1279 = !(((~((v1143 | (-v1143)) >> 31)) | (~((v1145 | (-v1145)) >> 31))) == 0);
  int v1263;
  if (v1279) {
    int * v1151 = v1138->cache_age;
    int v1281 = (~((v1145 | (-v1145)) >> 31)) & 1;
    int v1152 = v1151[v1281];
    int * v1153 = v1138->cache_age;
    int v1154 = v1153[0];
    int * v1155 = v1138->cache_age;
    int v1284 = v1154 + ((int)((unsigned int)(v1154 - v1152) >> 31));
    v1155[0] = v1284;
    int * v1157 = v1138->cache_age;
    int v1158 = v1157[1];
    int * v1159 = v1138->cache_age;
    int v1287 = v1158 + ((int)((unsigned int)(v1158 - v1152) >> 31));
    v1159[1] = v1287;
    int * v1161 = v1138->cache_age;
    v1161[v1281] = 0;
    v1263 = v1281;
  } else {
    int * v1164 = v1138->cache_age;
    int v1165 = v1164[0];
    int * v1166 = v1138->cache_tags;
    int v1167 = v1166[0];
    int * v1168 = v1138->cache_age;
    int v1169 = v1168[1];
    int * v1170 = v1138->cache_tags;
    int v1171 = v1170[1];
    bool v1293 = !(((~((v1147 | (-v1147)) >> 31)) | (~((v1149 | (-v1149)) >> 31))) == 0);
    int v1235;
    if (v1293) {
      int * v1172 = v1138->cache_age;
      int v1295 = 4 + ((~((v1149 | (-v1149)) >> 31)) & 1);
      int v1173 = v1172[v1295];
      int * v1174 = v1138->cache_age;
      int v1175 = v1174[4];
      int * v1176 = v1138->cache_age;
      int v1298 = v1175 + ((int)((unsigned int)(v1175 - v1173) >> 31));
      v1176[4] = v1298;
      int * v1178 = v1138->cache_age;
      int v1179 = v1178[5];
      int * v1180 = v1138->cache_age;
      int v1301 = v1179 + ((int)((unsigned int)(v1179 - v1173) >> 31));
      v1180[5] = v1301;
      int * v1182 = v1138->cache_age;
      v1182[v1295] = 0;
      v1235 = v1295;
    } else {
      int * v1185 = v1138->cache_age;
      int v1186 = v1185[4];
      int * v1187 = v1138->cache_tags;
      int v1188 = v1187[4];
      int * v1189 = v1138->cache_age;
      int v1190 = v1189[5];
      int * v1191 = v1138->cache_tags;
      int v1192 = v1191[5];
      int * v1193 = v1138->cache_dirty;
      int v1308 = 4 + ((((v1186 + ((~(((v1188 ^ -1) | (-(v1188 ^ -1))) >> 31)) & 2)) - (v1190 + ((~(((v1192 ^ -1) | (-(v1192 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1194 = v1193[v1308];
      bool v1309 = !(v1194 == 0);
      if (v1309) {
        int * v1195 = v1138->cache_tags;
        int v1196 = v1195[v1308];
        int * v1197 = v1138->cache_vals;
        int v1312 = (4 + ((((v1186 + ((~(((v1188 ^ -1) | (-(v1188 ^ -1))) >> 31)) & 2)) - (v1190 + ((~(((v1192 ^ -1) | (-(v1192 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1198 = v1197[v1312];
        int * v1199 = v1138->cache_vals;
        int v1314 = ((4 + ((((v1186 + ((~(((v1188 ^ -1) | (-(v1188 ^ -1))) >> 31)) & 2)) - (v1190 + ((~(((v1192 ^ -1) | (-(v1192 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1200 = v1199[v1314];
        int * v1201 = v1138->mem;
        int v1316 = v1196 * 2;
        v1201[v1316] = v1198;
        int * v1203 = v1138->mem;
        int v1319 = (v1196 * 2) + 1;
        v1203[v1319] = v1200;
        ;
      } else {
        ;
      }
      int * v1208 = v1138->mem;
      int v1209 = v1208[0];
      int * v1210 = v1138->mem;
      int v1211 = v1210[1];
      int * v1212 = v1138->cache_vals;
      int v1326 = (4 + ((((v1186 + ((~(((v1188 ^ -1) | (-(v1188 ^ -1))) >> 31)) & 2)) - (v1190 + ((~(((v1192 ^ -1) | (-(v1192 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1212[v1326] = v1209;
      int * v1214 = v1138->cache_vals;
      int v1329 = ((4 + ((((v1186 + ((~(((v1188 ^ -1) | (-(v1188 ^ -1))) >> 31)) & 2)) - (v1190 + ((~(((v1192 ^ -1) | (-(v1192 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1214[v1329] = v1211;
      int * v1216 = v1138->cache_tags;
      v1216[v1308] = 0;
      int * v1218 = v1138->cache_dirty;
      v1218[v1308] = 0;
      int * v1220 = v1138->cache_age;
      v1220[v1308] = 1;
      int * v1222 = v1138->cache_age;
      int v1223 = v1222[v1308];
      int * v1224 = v1138->cache_age;
      int v1225 = v1224[4];
      int * v1226 = v1138->cache_age;
      int v1337 = v1225 + ((int)((unsigned int)(v1225 - v1223) >> 31));
      v1226[4] = v1337;
      int * v1228 = v1138->cache_age;
      int v1229 = v1228[5];
      int * v1230 = v1138->cache_age;
      int v1340 = v1229 + ((int)((unsigned int)(v1229 - v1223) >> 31));
      v1230[5] = v1340;
      int * v1232 = v1138->cache_age;
      v1232[v1308] = 0;
      v1235 = v1308;
    }
    int * v1236 = v1138->cache_vals;
    int v1343 = v1235 * 2;
    int v1237 = v1236[v1343];
    int * v1238 = v1138->cache_vals;
    int v1345 = (v1235 * 2) + 1;
    int v1239 = v1238[v1345];
    int * v1240 = v1138->cache_vals;
    int v1347 = ((((v1165 + ((~(((v1167 ^ -1) | (-(v1167 ^ -1))) >> 31)) & 2)) - (v1169 + ((~(((v1171 ^ -1) | (-(v1171 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v1240[v1347] = v1237;
    int * v1242 = v1138->cache_vals;
    int v1350 = (((((v1165 + ((~(((v1167 ^ -1) | (-(v1167 ^ -1))) >> 31)) & 2)) - (v1169 + ((~(((v1171 ^ -1) | (-(v1171 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v1242[v1350] = v1239;
    int * v1244 = v1138->cache_tags;
    int v1353 = (((v1165 + ((~(((v1167 ^ -1) | (-(v1167 ^ -1))) >> 31)) & 2)) - (v1169 + ((~(((v1171 ^ -1) | (-(v1171 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v1244[v1353] = 0;
    int * v1246 = v1138->cache_dirty;
    v1246[v1353] = 0;
    int * v1248 = v1138->cache_age;
    v1248[v1353] = 1;
    int * v1250 = v1138->cache_age;
    int v1251 = v1250[v1353];
    int * v1252 = v1138->cache_age;
    int v1253 = v1252[0];
    int * v1254 = v1138->cache_age;
    int v1359 = v1253 + ((int)((unsigned int)(v1253 - v1251) >> 31));
    v1254[0] = v1359;
    int * v1256 = v1138->cache_age;
    int v1257 = v1256[1];
    int * v1258 = v1138->cache_age;
    int v1362 = v1257 + ((int)((unsigned int)(v1257 - v1251) >> 31));
    v1258[1] = v1362;
    int * v1260 = v1138->cache_age;
    v1260[v1353] = 0;
    v1263 = v1353;
  }
  int v1365 = v1263 * 2;
  int v1264 = v1150[v1365];
  int * v1265 = v1138->reg_ready;
  int v1368 = (v1139 + 1) + ((100 ^ (((~((v1147 | (-v1147)) >> 31)) | (~((v1149 | (-v1149)) >> 31))) & 104)) ^ (((~((v1143 | (-v1143)) >> 31)) | (~((v1145 | (-v1145)) >> 31))) & (1 ^ (100 ^ (((~((v1147 | (-v1147)) >> 31)) | (~((v1149 | (-v1149)) >> 31))) & 104)))));
  v1265[14] = v1368;
  int * v1267 = v1138->regs;
  v1267[14] = v1264;
  return v1138;
}

struct StateT * slot_6(struct StateT * v366) {
  int v367 = v366->timer;
  int v368 = v366->timer;
  int v380 = v368 + 1;
  v366->timer = v380;
  int * v370 = v366->reg_ready;
  int v371 = v370[11];
  int * v372 = v366->regs;
  int v373 = v372[11];
  int * v374 = v366->reg_ready;
  int v385 = (v371 + ((v367 - v371) & (~((v367 - v371) >> 31)))) + 1;
  v374[11] = v385;
  int * v376 = v366->regs;
  int v387 = v373 << 2;
  v376[11] = v387;
  struct StateT * v378 = slot_7(v366);
  return v378;
}

struct StateT * slot_5(struct StateT * v104) {
  int * v105 = v104->saved_regs;
  int * v106 = v104->regs;
  int v107 = v106[11];
  v105[11] = v107;
  int v109 = v104->timer;
  int v110 = v104->timer;
  int v249 = v110 + 1;
  v104->timer = v249;
  int * v112 = v104->reg_ready;
  int v113 = v112[5];
  int * v114 = v104->regs;
  int v115 = v114[5];
  int * v116 = v104->cache_tags;
  int v254 = (((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 1) * 2;
  int v117 = v116[v254];
  int * v118 = v104->cache_tags;
  int v256 = ((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 1) * 2) + 1;
  int v119 = v118[v256];
  int * v120 = v104->cache_tags;
  int v258 = 4 + ((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 3) * 2);
  int v121 = v120[v258];
  int * v122 = v104->cache_tags;
  int v260 = (4 + ((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v123 = v122[v260];
  int * v124 = v104->cache_vals;
  bool v261 = !(((~(((v117 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))) | (-(v117 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))))) >> 31)) | (~(((v119 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))) | (-(v119 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))))) >> 31))) == 0);
  int v237;
  if (v261) {
    int * v125 = v104->cache_age;
    int v263 = ((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 1) * 2) + ((~(((v119 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))) | (-(v119 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))))) >> 31)) & 1);
    int v126 = v125[v263];
    int * v127 = v104->cache_age;
    int v128 = v127[v254];
    int * v129 = v104->cache_age;
    int v266 = v128 + ((int)((unsigned int)(v128 - v126) >> 31));
    v129[v254] = v266;
    int * v131 = v104->cache_age;
    int v132 = v131[v256];
    int * v133 = v104->cache_age;
    int v269 = v132 + ((int)((unsigned int)(v132 - v126) >> 31));
    v133[v256] = v269;
    int * v135 = v104->cache_age;
    v135[v263] = 0;
    v237 = v263;
  } else {
    int * v138 = v104->cache_age;
    int v273 = (((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 1) * 2;
    int v139 = v138[v273];
    int * v140 = v104->cache_tags;
    int v141 = v140[v273];
    int * v142 = v104->cache_age;
    int v143 = v142[v256];
    int * v144 = v104->cache_tags;
    int v145 = v144[v256];
    bool v277 = !(((~(((v121 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))) | (-(v121 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))))) >> 31)) | (~(((v123 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))) | (-(v123 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))))) >> 31))) == 0);
    int v209;
    if (v277) {
      int * v146 = v104->cache_age;
      int v279 = (4 + ((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 3) * 2)) + ((~(((v123 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))) | (-(v123 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))))) >> 31)) & 1);
      int v147 = v146[v279];
      int * v148 = v104->cache_age;
      int v149 = v148[v258];
      int * v150 = v104->cache_age;
      int v282 = v149 + ((int)((unsigned int)(v149 - v147) >> 31));
      v150[v258] = v282;
      int * v152 = v104->cache_age;
      int v153 = v152[v260];
      int * v154 = v104->cache_age;
      int v285 = v153 + ((int)((unsigned int)(v153 - v147) >> 31));
      v154[v260] = v285;
      int * v156 = v104->cache_age;
      v156[v279] = 0;
      v209 = v279;
    } else {
      int * v159 = v104->cache_age;
      int v289 = 4 + ((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 3) * 2);
      int v160 = v159[v289];
      int * v161 = v104->cache_tags;
      int v162 = v161[v289];
      int * v163 = v104->cache_age;
      int v164 = v163[v260];
      int * v165 = v104->cache_tags;
      int v166 = v165[v260];
      int * v167 = v104->cache_dirty;
      int v294 = (4 + ((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 3) * 2)) + ((((v160 + ((~(((v162 ^ -1) | (-(v162 ^ -1))) >> 31)) & 2)) - (v164 + ((~(((v166 ^ -1) | (-(v166 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v168 = v167[v294];
      bool v295 = !(v168 == 0);
      if (v295) {
        int * v169 = v104->cache_tags;
        int v170 = v169[v294];
        int * v171 = v104->cache_vals;
        int v298 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 3) * 2)) + ((((v160 + ((~(((v162 ^ -1) | (-(v162 ^ -1))) >> 31)) & 2)) - (v164 + ((~(((v166 ^ -1) | (-(v166 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v172 = v171[v298];
        int * v173 = v104->cache_vals;
        int v300 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 3) * 2)) + ((((v160 + ((~(((v162 ^ -1) | (-(v162 ^ -1))) >> 31)) & 2)) - (v164 + ((~(((v166 ^ -1) | (-(v166 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v174 = v173[v300];
        int * v175 = v104->mem;
        int v302 = v170 * 2;
        v175[v302] = v172;
        int * v177 = v104->mem;
        int v305 = (v170 * 2) + 1;
        v177[v305] = v174;
        ;
      } else {
        ;
      }
      int * v182 = v104->mem;
      int v310 = ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) * 2;
      int v183 = v182[v310];
      int * v184 = v104->mem;
      int v312 = (((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) * 2) + 1;
      int v185 = v184[v312];
      int * v186 = v104->cache_vals;
      int v314 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 3) * 2)) + ((((v160 + ((~(((v162 ^ -1) | (-(v162 ^ -1))) >> 31)) & 2)) - (v164 + ((~(((v166 ^ -1) | (-(v166 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v186[v314] = v183;
      int * v188 = v104->cache_vals;
      int v317 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 3) * 2)) + ((((v160 + ((~(((v162 ^ -1) | (-(v162 ^ -1))) >> 31)) & 2)) - (v164 + ((~(((v166 ^ -1) | (-(v166 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v188[v317] = v185;
      int * v190 = v104->cache_tags;
      int v320 = (int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1);
      v190[v294] = v320;
      int * v192 = v104->cache_dirty;
      v192[v294] = 0;
      int * v194 = v104->cache_age;
      v194[v294] = 1;
      int * v196 = v104->cache_age;
      int v197 = v196[v294];
      int * v198 = v104->cache_age;
      int v199 = v198[v258];
      int * v200 = v104->cache_age;
      int v328 = v199 + ((int)((unsigned int)(v199 - v197) >> 31));
      v200[v258] = v328;
      int * v202 = v104->cache_age;
      int v203 = v202[v260];
      int * v204 = v104->cache_age;
      int v331 = v203 + ((int)((unsigned int)(v203 - v197) >> 31));
      v204[v260] = v331;
      int * v206 = v104->cache_age;
      v206[v294] = 0;
      v209 = v294;
    }
    int * v210 = v104->cache_vals;
    int v334 = v209 * 2;
    int v211 = v210[v334];
    int * v212 = v104->cache_vals;
    int v336 = (v209 * 2) + 1;
    int v213 = v212[v336];
    int * v214 = v104->cache_vals;
    int v338 = (((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 1) * 2) + ((((v139 + ((~(((v141 ^ -1) | (-(v141 ^ -1))) >> 31)) & 2)) - (v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v214[v338] = v211;
    int * v216 = v104->cache_vals;
    int v341 = ((((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 1) * 2) + ((((v139 + ((~(((v141 ^ -1) | (-(v141 ^ -1))) >> 31)) & 2)) - (v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v216[v341] = v213;
    int * v218 = v104->cache_tags;
    int v344 = ((((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1)) & 1) * 2) + ((((v139 + ((~(((v141 ^ -1) | (-(v141 ^ -1))) >> 31)) & 2)) - (v143 + ((~(((v145 ^ -1) | (-(v145 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v345 = (int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1);
    v218[v344] = v345;
    int * v220 = v104->cache_dirty;
    v220[v344] = 0;
    int * v222 = v104->cache_age;
    v222[v344] = 1;
    int * v224 = v104->cache_age;
    int v225 = v224[v344];
    int * v226 = v104->cache_age;
    int v227 = v226[v254];
    int * v228 = v104->cache_age;
    int v353 = v227 + ((int)((unsigned int)(v227 - v225) >> 31));
    v228[v254] = v353;
    int * v230 = v104->cache_age;
    int v231 = v230[v256];
    int * v232 = v104->cache_age;
    int v356 = v231 + ((int)((unsigned int)(v231 - v225) >> 31));
    v232[v256] = v356;
    int * v234 = v104->cache_age;
    v234[v344] = 0;
    v237 = v344;
  }
  int v359 = (v237 * 2) + (((int)((unsigned int)v115 >> 2)) & 1);
  int v238 = v124[v359];
  int * v239 = v104->reg_ready;
  int v361 = ((v113 + ((v109 - v113) & (~((v109 - v113) >> 31)))) + 1) + ((100 ^ (((~(((v121 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))) | (-(v121 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))))) >> 31)) | (~(((v123 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))) | (-(v123 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v117 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))) | (-(v117 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))))) >> 31)) | (~(((v119 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))) | (-(v119 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v121 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))) | (-(v121 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))))) >> 31)) | (~(((v123 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))) | (-(v123 ^ ((int)((unsigned int)((int)((unsigned int)v115 >> 2)) >> 1))))) >> 31))) & 104)))));
  v239[11] = v361;
  int * v241 = v104->regs;
  v241[11] = v238;
  struct StateT * v243 = slot_6(v104);
  return v243;
}

struct StateT * slot_2(struct StateT * v38) {
  int v39 = v38->timer;
  int v40 = v38->timer;
  int v48 = v40 + 1;
  v38->timer = v48;
  int * v42 = v38->reg_ready;
  int v51 = v39 + 1;
  v42[15] = v51;
  int * v44 = v38->regs;
  v44[15] = 80;
  struct StateT * v46 = slot_3(v38);
  return v46;
}

struct StateT * slot_7(struct StateT * v390) {
  int * v391 = v390->saved_regs;
  int * v392 = v390->regs;
  int v393 = v392[12];
  v391[12] = v393;
  int v395 = v390->timer;
  int v396 = v390->timer;
  int v535 = v396 + 1;
  v390->timer = v535;
  int * v398 = v390->reg_ready;
  int v399 = v398[11];
  int * v400 = v390->regs;
  int v401 = v400[11];
  int * v402 = v390->cache_tags;
  int v540 = (((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1)) & 1) * 2;
  int v403 = v402[v540];
  int * v404 = v390->cache_tags;
  int v542 = ((((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1)) & 1) * 2) + 1;
  int v405 = v404[v542];
  int * v406 = v390->cache_tags;
  int v544 = 4 + ((((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1)) & 3) * 2);
  int v407 = v406[v544];
  int * v408 = v390->cache_tags;
  int v546 = (4 + ((((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v409 = v408[v546];
  int * v410 = v390->cache_vals;
  bool v547 = !(((~(((v403 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))) | (-(v403 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))))) >> 31)) | (~(((v405 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))) | (-(v405 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))))) >> 31))) == 0);
  int v523;
  if (v547) {
    int * v411 = v390->cache_age;
    int v549 = ((((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1)) & 1) * 2) + ((~(((v405 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))) | (-(v405 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))))) >> 31)) & 1);
    int v412 = v411[v549];
    int * v413 = v390->cache_age;
    int v414 = v413[v540];
    int * v415 = v390->cache_age;
    int v552 = v414 + ((int)((unsigned int)(v414 - v412) >> 31));
    v415[v540] = v552;
    int * v417 = v390->cache_age;
    int v418 = v417[v542];
    int * v419 = v390->cache_age;
    int v555 = v418 + ((int)((unsigned int)(v418 - v412) >> 31));
    v419[v542] = v555;
    int * v421 = v390->cache_age;
    v421[v549] = 0;
    v523 = v549;
  } else {
    int * v424 = v390->cache_age;
    int v559 = (((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1)) & 1) * 2;
    int v425 = v424[v559];
    int * v426 = v390->cache_tags;
    int v427 = v426[v559];
    int * v428 = v390->cache_age;
    int v429 = v428[v542];
    int * v430 = v390->cache_tags;
    int v431 = v430[v542];
    bool v563 = !(((~(((v407 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))) | (-(v407 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))))) >> 31)) | (~(((v409 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))) | (-(v409 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))))) >> 31))) == 0);
    int v495;
    if (v563) {
      int * v432 = v390->cache_age;
      int v565 = (4 + ((((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1)) & 3) * 2)) + ((~(((v409 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))) | (-(v409 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))))) >> 31)) & 1);
      int v433 = v432[v565];
      int * v434 = v390->cache_age;
      int v435 = v434[v544];
      int * v436 = v390->cache_age;
      int v568 = v435 + ((int)((unsigned int)(v435 - v433) >> 31));
      v436[v544] = v568;
      int * v438 = v390->cache_age;
      int v439 = v438[v546];
      int * v440 = v390->cache_age;
      int v571 = v439 + ((int)((unsigned int)(v439 - v433) >> 31));
      v440[v546] = v571;
      int * v442 = v390->cache_age;
      v442[v565] = 0;
      v495 = v565;
    } else {
      int * v445 = v390->cache_age;
      int v575 = 4 + ((((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1)) & 3) * 2);
      int v446 = v445[v575];
      int * v447 = v390->cache_tags;
      int v448 = v447[v575];
      int * v449 = v390->cache_age;
      int v450 = v449[v546];
      int * v451 = v390->cache_tags;
      int v452 = v451[v546];
      int * v453 = v390->cache_dirty;
      int v580 = (4 + ((((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1)) & 3) * 2)) + ((((v446 + ((~(((v448 ^ -1) | (-(v448 ^ -1))) >> 31)) & 2)) - (v450 + ((~(((v452 ^ -1) | (-(v452 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v454 = v453[v580];
      bool v581 = !(v454 == 0);
      if (v581) {
        int * v455 = v390->cache_tags;
        int v456 = v455[v580];
        int * v457 = v390->cache_vals;
        int v584 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1)) & 3) * 2)) + ((((v446 + ((~(((v448 ^ -1) | (-(v448 ^ -1))) >> 31)) & 2)) - (v450 + ((~(((v452 ^ -1) | (-(v452 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v458 = v457[v584];
        int * v459 = v390->cache_vals;
        int v586 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1)) & 3) * 2)) + ((((v446 + ((~(((v448 ^ -1) | (-(v448 ^ -1))) >> 31)) & 2)) - (v450 + ((~(((v452 ^ -1) | (-(v452 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v460 = v459[v586];
        int * v461 = v390->mem;
        int v588 = v456 * 2;
        v461[v588] = v458;
        int * v463 = v390->mem;
        int v591 = (v456 * 2) + 1;
        v463[v591] = v460;
        ;
      } else {
        ;
      }
      int * v468 = v390->mem;
      int v596 = ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1)) * 2;
      int v469 = v468[v596];
      int * v470 = v390->mem;
      int v598 = (((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1)) * 2) + 1;
      int v471 = v470[v598];
      int * v472 = v390->cache_vals;
      int v600 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1)) & 3) * 2)) + ((((v446 + ((~(((v448 ^ -1) | (-(v448 ^ -1))) >> 31)) & 2)) - (v450 + ((~(((v452 ^ -1) | (-(v452 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v472[v600] = v469;
      int * v474 = v390->cache_vals;
      int v603 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1)) & 3) * 2)) + ((((v446 + ((~(((v448 ^ -1) | (-(v448 ^ -1))) >> 31)) & 2)) - (v450 + ((~(((v452 ^ -1) | (-(v452 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v474[v603] = v471;
      int * v476 = v390->cache_tags;
      int v606 = (int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1);
      v476[v580] = v606;
      int * v478 = v390->cache_dirty;
      v478[v580] = 0;
      int * v480 = v390->cache_age;
      v480[v580] = 1;
      int * v482 = v390->cache_age;
      int v483 = v482[v580];
      int * v484 = v390->cache_age;
      int v485 = v484[v544];
      int * v486 = v390->cache_age;
      int v614 = v485 + ((int)((unsigned int)(v485 - v483) >> 31));
      v486[v544] = v614;
      int * v488 = v390->cache_age;
      int v489 = v488[v546];
      int * v490 = v390->cache_age;
      int v617 = v489 + ((int)((unsigned int)(v489 - v483) >> 31));
      v490[v546] = v617;
      int * v492 = v390->cache_age;
      v492[v580] = 0;
      v495 = v580;
    }
    int * v496 = v390->cache_vals;
    int v620 = v495 * 2;
    int v497 = v496[v620];
    int * v498 = v390->cache_vals;
    int v622 = (v495 * 2) + 1;
    int v499 = v498[v622];
    int * v500 = v390->cache_vals;
    int v624 = (((((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1)) & 1) * 2) + ((((v425 + ((~(((v427 ^ -1) | (-(v427 ^ -1))) >> 31)) & 2)) - (v429 + ((~(((v431 ^ -1) | (-(v431 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v500[v624] = v497;
    int * v502 = v390->cache_vals;
    int v627 = ((((((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1)) & 1) * 2) + ((((v425 + ((~(((v427 ^ -1) | (-(v427 ^ -1))) >> 31)) & 2)) - (v429 + ((~(((v431 ^ -1) | (-(v431 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v502[v627] = v499;
    int * v504 = v390->cache_tags;
    int v630 = ((((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1)) & 1) * 2) + ((((v425 + ((~(((v427 ^ -1) | (-(v427 ^ -1))) >> 31)) & 2)) - (v429 + ((~(((v431 ^ -1) | (-(v431 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v631 = (int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1);
    v504[v630] = v631;
    int * v506 = v390->cache_dirty;
    v506[v630] = 0;
    int * v508 = v390->cache_age;
    v508[v630] = 1;
    int * v510 = v390->cache_age;
    int v511 = v510[v630];
    int * v512 = v390->cache_age;
    int v513 = v512[v540];
    int * v514 = v390->cache_age;
    int v639 = v513 + ((int)((unsigned int)(v513 - v511) >> 31));
    v514[v540] = v639;
    int * v516 = v390->cache_age;
    int v517 = v516[v542];
    int * v518 = v390->cache_age;
    int v642 = v517 + ((int)((unsigned int)(v517 - v511) >> 31));
    v518[v542] = v642;
    int * v520 = v390->cache_age;
    v520[v630] = 0;
    v523 = v630;
  }
  int v645 = (v523 * 2) + (((int)((unsigned int)v401 >> 2)) & 1);
  int v524 = v410[v645];
  int * v525 = v390->reg_ready;
  int v647 = ((v399 + ((v395 - v399) & (~((v395 - v399) >> 31)))) + 1) + ((100 ^ (((~(((v407 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))) | (-(v407 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))))) >> 31)) | (~(((v409 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))) | (-(v409 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v403 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))) | (-(v403 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))))) >> 31)) | (~(((v405 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))) | (-(v405 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v407 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))) | (-(v407 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))))) >> 31)) | (~(((v409 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))) | (-(v409 ^ ((int)((unsigned int)((int)((unsigned int)v401 >> 2)) >> 1))))) >> 31))) & 104)))));
  v525[12] = v647;
  int * v527 = v390->regs;
  v527[12] = v524;
  struct StateT * v529 = slot_8(v390);
  return v529;
}

struct StateT * slot_3(struct StateT * v56) {
  int v57 = v56->timer;
  int v58 = v56->timer;
  int v62 = v58 + 1;
  v56->timer = v62;
  struct StateT * v60 = slot_4(v56);
  return v60;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v1371 = v1->timer;
  int * v1372 = v1->reg_ready;
  int v1373 = v1372[0];
  int v1504 = v1373 + ((v1371 - v1373) & (~((v1371 - v1373) >> 31)));
  v1->timer = v1504;
  int v1375 = v1->timer;
  int * v1376 = v1->reg_ready;
  int v1377 = v1376[1];
  int v1507 = v1377 + ((v1375 - v1377) & (~((v1375 - v1377) >> 31)));
  v1->timer = v1507;
  int v1379 = v1->timer;
  int * v1380 = v1->reg_ready;
  int v1381 = v1380[2];
  int v1510 = v1381 + ((v1379 - v1381) & (~((v1379 - v1381) >> 31)));
  v1->timer = v1510;
  int v1383 = v1->timer;
  int * v1384 = v1->reg_ready;
  int v1385 = v1384[3];
  int v1513 = v1385 + ((v1383 - v1385) & (~((v1383 - v1385) >> 31)));
  v1->timer = v1513;
  int v1387 = v1->timer;
  int * v1388 = v1->reg_ready;
  int v1389 = v1388[4];
  int v1516 = v1389 + ((v1387 - v1389) & (~((v1387 - v1389) >> 31)));
  v1->timer = v1516;
  int v1391 = v1->timer;
  int * v1392 = v1->reg_ready;
  int v1393 = v1392[5];
  int v1519 = v1393 + ((v1391 - v1393) & (~((v1391 - v1393) >> 31)));
  v1->timer = v1519;
  int v1395 = v1->timer;
  int * v1396 = v1->reg_ready;
  int v1397 = v1396[6];
  int v1522 = v1397 + ((v1395 - v1397) & (~((v1395 - v1397) >> 31)));
  v1->timer = v1522;
  int v1399 = v1->timer;
  int * v1400 = v1->reg_ready;
  int v1401 = v1400[7];
  int v1525 = v1401 + ((v1399 - v1401) & (~((v1399 - v1401) >> 31)));
  v1->timer = v1525;
  int v1403 = v1->timer;
  int * v1404 = v1->reg_ready;
  int v1405 = v1404[8];
  int v1528 = v1405 + ((v1403 - v1405) & (~((v1403 - v1405) >> 31)));
  v1->timer = v1528;
  int v1407 = v1->timer;
  int * v1408 = v1->reg_ready;
  int v1409 = v1408[9];
  int v1531 = v1409 + ((v1407 - v1409) & (~((v1407 - v1409) >> 31)));
  v1->timer = v1531;
  int v1411 = v1->timer;
  int * v1412 = v1->reg_ready;
  int v1413 = v1412[10];
  int v1534 = v1413 + ((v1411 - v1413) & (~((v1411 - v1413) >> 31)));
  v1->timer = v1534;
  int v1415 = v1->timer;
  int * v1416 = v1->reg_ready;
  int v1417 = v1416[11];
  int v1537 = v1417 + ((v1415 - v1417) & (~((v1415 - v1417) >> 31)));
  v1->timer = v1537;
  int v1419 = v1->timer;
  int * v1420 = v1->reg_ready;
  int v1421 = v1420[12];
  int v1540 = v1421 + ((v1419 - v1421) & (~((v1419 - v1421) >> 31)));
  v1->timer = v1540;
  int v1423 = v1->timer;
  int * v1424 = v1->reg_ready;
  int v1425 = v1424[13];
  int v1543 = v1425 + ((v1423 - v1425) & (~((v1423 - v1425) >> 31)));
  v1->timer = v1543;
  int v1427 = v1->timer;
  int * v1428 = v1->reg_ready;
  int v1429 = v1428[14];
  int v1546 = v1429 + ((v1427 - v1429) & (~((v1427 - v1429) >> 31)));
  v1->timer = v1546;
  int v1431 = v1->timer;
  int * v1432 = v1->reg_ready;
  int v1433 = v1432[15];
  int v1549 = v1433 + ((v1431 - v1433) & (~((v1431 - v1433) >> 31)));
  v1->timer = v1549;
  int v1435 = v1->timer;
  int * v1436 = v1->reg_ready;
  int v1437 = v1436[16];
  int v1552 = v1437 + ((v1435 - v1437) & (~((v1435 - v1437) >> 31)));
  v1->timer = v1552;
  int v1439 = v1->timer;
  int * v1440 = v1->reg_ready;
  int v1441 = v1440[17];
  int v1555 = v1441 + ((v1439 - v1441) & (~((v1439 - v1441) >> 31)));
  v1->timer = v1555;
  int v1443 = v1->timer;
  int * v1444 = v1->reg_ready;
  int v1445 = v1444[18];
  int v1558 = v1445 + ((v1443 - v1445) & (~((v1443 - v1445) >> 31)));
  v1->timer = v1558;
  int v1447 = v1->timer;
  int * v1448 = v1->reg_ready;
  int v1449 = v1448[19];
  int v1561 = v1449 + ((v1447 - v1449) & (~((v1447 - v1449) >> 31)));
  v1->timer = v1561;
  int v1451 = v1->timer;
  int * v1452 = v1->reg_ready;
  int v1453 = v1452[20];
  int v1564 = v1453 + ((v1451 - v1453) & (~((v1451 - v1453) >> 31)));
  v1->timer = v1564;
  int v1455 = v1->timer;
  int * v1456 = v1->reg_ready;
  int v1457 = v1456[21];
  int v1567 = v1457 + ((v1455 - v1457) & (~((v1455 - v1457) >> 31)));
  v1->timer = v1567;
  int v1459 = v1->timer;
  int * v1460 = v1->reg_ready;
  int v1461 = v1460[22];
  int v1570 = v1461 + ((v1459 - v1461) & (~((v1459 - v1461) >> 31)));
  v1->timer = v1570;
  int v1463 = v1->timer;
  int * v1464 = v1->reg_ready;
  int v1465 = v1464[23];
  int v1573 = v1465 + ((v1463 - v1465) & (~((v1463 - v1465) >> 31)));
  v1->timer = v1573;
  int v1467 = v1->timer;
  int * v1468 = v1->reg_ready;
  int v1469 = v1468[24];
  int v1576 = v1469 + ((v1467 - v1469) & (~((v1467 - v1469) >> 31)));
  v1->timer = v1576;
  int v1471 = v1->timer;
  int * v1472 = v1->reg_ready;
  int v1473 = v1472[25];
  int v1579 = v1473 + ((v1471 - v1473) & (~((v1471 - v1473) >> 31)));
  v1->timer = v1579;
  int v1475 = v1->timer;
  int * v1476 = v1->reg_ready;
  int v1477 = v1476[26];
  int v1582 = v1477 + ((v1475 - v1477) & (~((v1475 - v1477) >> 31)));
  v1->timer = v1582;
  int v1479 = v1->timer;
  int * v1480 = v1->reg_ready;
  int v1481 = v1480[27];
  int v1585 = v1481 + ((v1479 - v1481) & (~((v1479 - v1481) >> 31)));
  v1->timer = v1585;
  int v1483 = v1->timer;
  int * v1484 = v1->reg_ready;
  int v1485 = v1484[28];
  int v1588 = v1485 + ((v1483 - v1485) & (~((v1483 - v1485) >> 31)));
  v1->timer = v1588;
  int v1487 = v1->timer;
  int * v1488 = v1->reg_ready;
  int v1489 = v1488[29];
  int v1591 = v1489 + ((v1487 - v1489) & (~((v1487 - v1489) >> 31)));
  v1->timer = v1591;
  int v1491 = v1->timer;
  int * v1492 = v1->reg_ready;
  int v1493 = v1492[30];
  int v1594 = v1493 + ((v1491 - v1493) & (~((v1491 - v1493) >> 31)));
  v1->timer = v1594;
  int v1495 = v1->timer;
  int * v1496 = v1->reg_ready;
  int v1497 = v1496[31];
  int v1597 = v1497 + ((v1495 - v1497) & (~((v1495 - v1497) >> 31)));
  v1->timer = v1597;
  return v1;
}

struct StateT * slot_10(struct StateT * v896) {
  int v897 = v896->timer;
  int v898 = v896->timer;
  int v902 = v898 + 1;
  v896->timer = v902;
  struct StateT * v900 = slot_12(v896);
  return v900;
}

struct StateT * slot_1(struct StateT * v20) {
  int v21 = v20->timer;
  int v22 = v20->timer;
  int v30 = v22 + 1;
  v20->timer = v30;
  int * v24 = v20->reg_ready;
  int v33 = v21 + 1;
  v24[10] = v33;
  int * v26 = v20->regs;
  v26[10] = 80;
  struct StateT * v28 = slot_2(v20);
  return v28;
}

struct StateT * slot_8(struct StateT * v652) {
  int * v653 = v652->regs;
  int v654 = v653[10];
  int * v655 = v652->regs;
  int v656 = v655[15];
  bool v777 = v654 >= v656;
  struct StateT * v771;
  if (v777) {
    int v657 = v652->timer;
    int v778 = v657 + 15;
    v652->timer = v778;
    int * v659 = v652->saved_regs;
    int v660 = v659[5];
    int * v661 = v652->regs;
    v661[5] = v660;
    int * v663 = v652->saved_regs;
    int v664 = v663[11];
    int * v665 = v652->regs;
    v665[11] = v664;
    int * v667 = v652->saved_regs;
    int v668 = v667[12];
    int * v669 = v652->regs;
    v669[12] = v668;
    int * v671 = v652->reg_ready;
    int v672 = v652->timer;
    v671[0] = v672;
    int * v674 = v652->reg_ready;
    int v675 = v652->timer;
    v674[1] = v675;
    int * v677 = v652->reg_ready;
    int v678 = v652->timer;
    v677[2] = v678;
    int * v680 = v652->reg_ready;
    int v681 = v652->timer;
    v680[3] = v681;
    int * v683 = v652->reg_ready;
    int v684 = v652->timer;
    v683[4] = v684;
    int * v686 = v652->reg_ready;
    int v687 = v652->timer;
    v686[5] = v687;
    int * v689 = v652->reg_ready;
    int v690 = v652->timer;
    v689[6] = v690;
    int * v692 = v652->reg_ready;
    int v693 = v652->timer;
    v692[7] = v693;
    int * v695 = v652->reg_ready;
    int v696 = v652->timer;
    v695[8] = v696;
    int * v698 = v652->reg_ready;
    int v699 = v652->timer;
    v698[9] = v699;
    int * v701 = v652->reg_ready;
    int v702 = v652->timer;
    v701[10] = v702;
    int * v704 = v652->reg_ready;
    int v705 = v652->timer;
    v704[11] = v705;
    int * v707 = v652->reg_ready;
    int v708 = v652->timer;
    v707[12] = v708;
    int * v710 = v652->reg_ready;
    int v711 = v652->timer;
    v710[13] = v711;
    int * v713 = v652->reg_ready;
    int v714 = v652->timer;
    v713[14] = v714;
    int * v716 = v652->reg_ready;
    int v717 = v652->timer;
    v716[15] = v717;
    int * v719 = v652->reg_ready;
    int v720 = v652->timer;
    v719[16] = v720;
    int * v722 = v652->reg_ready;
    int v723 = v652->timer;
    v722[17] = v723;
    int * v725 = v652->reg_ready;
    int v726 = v652->timer;
    v725[18] = v726;
    int * v728 = v652->reg_ready;
    int v729 = v652->timer;
    v728[19] = v729;
    int * v731 = v652->reg_ready;
    int v732 = v652->timer;
    v731[20] = v732;
    int * v734 = v652->reg_ready;
    int v735 = v652->timer;
    v734[21] = v735;
    int * v737 = v652->reg_ready;
    int v738 = v652->timer;
    v737[22] = v738;
    int * v740 = v652->reg_ready;
    int v741 = v652->timer;
    v740[23] = v741;
    int * v743 = v652->reg_ready;
    int v744 = v652->timer;
    v743[24] = v744;
    int * v746 = v652->reg_ready;
    int v747 = v652->timer;
    v746[25] = v747;
    int * v749 = v652->reg_ready;
    int v750 = v652->timer;
    v749[26] = v750;
    int * v752 = v652->reg_ready;
    int v753 = v652->timer;
    v752[27] = v753;
    int * v755 = v652->reg_ready;
    int v756 = v652->timer;
    v755[28] = v756;
    int * v758 = v652->reg_ready;
    int v759 = v652->timer;
    v758[29] = v759;
    int * v761 = v652->reg_ready;
    int v762 = v652->timer;
    v761[30] = v762;
    int * v764 = v652->reg_ready;
    int v765 = v652->timer;
    v764[31] = v765;
    struct StateT * v767 = slot_9(v652);
    v771 = v767;
  } else {
    struct StateT * v769 = slot_10(v652);
    v771 = v769;
  }
  return v771;
}

struct StateT * slot_4(struct StateT * v65) {
  int * v66 = v65->saved_regs;
  int * v67 = v65->regs;
  int v68 = v67[5];
  v66[5] = v68;
  int v70 = v65->timer;
  int v71 = v65->timer;
  int v91 = v71 + 1;
  v65->timer = v91;
  int * v73 = v65->reg_ready;
  int v74 = v73[13];
  int * v75 = v65->regs;
  int v76 = v75[13];
  int * v77 = v65->reg_ready;
  int v78 = v77[10];
  int * v79 = v65->regs;
  int v80 = v79[10];
  int * v81 = v65->reg_ready;
  int v99 = (v78 + (((v74 + ((v70 - v74) & (~((v70 - v74) >> 31)))) - v78) & (~(((v74 + ((v70 - v74) & (~((v70 - v74) >> 31)))) - v78) >> 31)))) + 1;
  v81[5] = v99;
  int * v83 = v65->regs;
  int v101 = v76 + v80;
  v83[5] = v101;
  struct StateT * v85 = slot_5(v65);
  return v85;
}

struct StateT * slot_9(struct StateT * v887) {
  int v888 = v887->timer;
  int v889 = v887->timer;
  int v893 = v889 + 1;
  v887->timer = v893;
  struct StateT * v891 = slot_11(v887);
  return v891;
}

struct StateT * slot_11(struct StateT * v905) {
  int v906 = v905->timer;
  int v907 = v905->timer;
  int v1037 = v907 + 1;
  v905->timer = v1037;
  int * v909 = v905->cache_tags;
  int v910 = v909[0];
  int * v911 = v905->cache_tags;
  int v912 = v911[1];
  int * v913 = v905->cache_tags;
  int v914 = v913[4];
  int * v915 = v905->cache_tags;
  int v916 = v915[5];
  int * v917 = v905->cache_vals;
  bool v1046 = !(((~((v910 | (-v910)) >> 31)) | (~((v912 | (-v912)) >> 31))) == 0);
  int v1030;
  if (v1046) {
    int * v918 = v905->cache_age;
    int v1048 = (~((v912 | (-v912)) >> 31)) & 1;
    int v919 = v918[v1048];
    int * v920 = v905->cache_age;
    int v921 = v920[0];
    int * v922 = v905->cache_age;
    int v1051 = v921 + ((int)((unsigned int)(v921 - v919) >> 31));
    v922[0] = v1051;
    int * v924 = v905->cache_age;
    int v925 = v924[1];
    int * v926 = v905->cache_age;
    int v1054 = v925 + ((int)((unsigned int)(v925 - v919) >> 31));
    v926[1] = v1054;
    int * v928 = v905->cache_age;
    v928[v1048] = 0;
    v1030 = v1048;
  } else {
    int * v931 = v905->cache_age;
    int v932 = v931[0];
    int * v933 = v905->cache_tags;
    int v934 = v933[0];
    int * v935 = v905->cache_age;
    int v936 = v935[1];
    int * v937 = v905->cache_tags;
    int v938 = v937[1];
    bool v1060 = !(((~((v914 | (-v914)) >> 31)) | (~((v916 | (-v916)) >> 31))) == 0);
    int v1002;
    if (v1060) {
      int * v939 = v905->cache_age;
      int v1062 = 4 + ((~((v916 | (-v916)) >> 31)) & 1);
      int v940 = v939[v1062];
      int * v941 = v905->cache_age;
      int v942 = v941[4];
      int * v943 = v905->cache_age;
      int v1065 = v942 + ((int)((unsigned int)(v942 - v940) >> 31));
      v943[4] = v1065;
      int * v945 = v905->cache_age;
      int v946 = v945[5];
      int * v947 = v905->cache_age;
      int v1068 = v946 + ((int)((unsigned int)(v946 - v940) >> 31));
      v947[5] = v1068;
      int * v949 = v905->cache_age;
      v949[v1062] = 0;
      v1002 = v1062;
    } else {
      int * v952 = v905->cache_age;
      int v953 = v952[4];
      int * v954 = v905->cache_tags;
      int v955 = v954[4];
      int * v956 = v905->cache_age;
      int v957 = v956[5];
      int * v958 = v905->cache_tags;
      int v959 = v958[5];
      int * v960 = v905->cache_dirty;
      int v1075 = 4 + ((((v953 + ((~(((v955 ^ -1) | (-(v955 ^ -1))) >> 31)) & 2)) - (v957 + ((~(((v959 ^ -1) | (-(v959 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v961 = v960[v1075];
      bool v1076 = !(v961 == 0);
      if (v1076) {
        int * v962 = v905->cache_tags;
        int v963 = v962[v1075];
        int * v964 = v905->cache_vals;
        int v1079 = (4 + ((((v953 + ((~(((v955 ^ -1) | (-(v955 ^ -1))) >> 31)) & 2)) - (v957 + ((~(((v959 ^ -1) | (-(v959 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v965 = v964[v1079];
        int * v966 = v905->cache_vals;
        int v1081 = ((4 + ((((v953 + ((~(((v955 ^ -1) | (-(v955 ^ -1))) >> 31)) & 2)) - (v957 + ((~(((v959 ^ -1) | (-(v959 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v967 = v966[v1081];
        int * v968 = v905->mem;
        int v1083 = v963 * 2;
        v968[v1083] = v965;
        int * v970 = v905->mem;
        int v1086 = (v963 * 2) + 1;
        v970[v1086] = v967;
        ;
      } else {
        ;
      }
      int * v975 = v905->mem;
      int v976 = v975[0];
      int * v977 = v905->mem;
      int v978 = v977[1];
      int * v979 = v905->cache_vals;
      int v1093 = (4 + ((((v953 + ((~(((v955 ^ -1) | (-(v955 ^ -1))) >> 31)) & 2)) - (v957 + ((~(((v959 ^ -1) | (-(v959 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v979[v1093] = v976;
      int * v981 = v905->cache_vals;
      int v1096 = ((4 + ((((v953 + ((~(((v955 ^ -1) | (-(v955 ^ -1))) >> 31)) & 2)) - (v957 + ((~(((v959 ^ -1) | (-(v959 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v981[v1096] = v978;
      int * v983 = v905->cache_tags;
      v983[v1075] = 0;
      int * v985 = v905->cache_dirty;
      v985[v1075] = 0;
      int * v987 = v905->cache_age;
      v987[v1075] = 1;
      int * v989 = v905->cache_age;
      int v990 = v989[v1075];
      int * v991 = v905->cache_age;
      int v992 = v991[4];
      int * v993 = v905->cache_age;
      int v1104 = v992 + ((int)((unsigned int)(v992 - v990) >> 31));
      v993[4] = v1104;
      int * v995 = v905->cache_age;
      int v996 = v995[5];
      int * v997 = v905->cache_age;
      int v1107 = v996 + ((int)((unsigned int)(v996 - v990) >> 31));
      v997[5] = v1107;
      int * v999 = v905->cache_age;
      v999[v1075] = 0;
      v1002 = v1075;
    }
    int * v1003 = v905->cache_vals;
    int v1110 = v1002 * 2;
    int v1004 = v1003[v1110];
    int * v1005 = v905->cache_vals;
    int v1112 = (v1002 * 2) + 1;
    int v1006 = v1005[v1112];
    int * v1007 = v905->cache_vals;
    int v1114 = ((((v932 + ((~(((v934 ^ -1) | (-(v934 ^ -1))) >> 31)) & 2)) - (v936 + ((~(((v938 ^ -1) | (-(v938 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v1007[v1114] = v1004;
    int * v1009 = v905->cache_vals;
    int v1117 = (((((v932 + ((~(((v934 ^ -1) | (-(v934 ^ -1))) >> 31)) & 2)) - (v936 + ((~(((v938 ^ -1) | (-(v938 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v1009[v1117] = v1006;
    int * v1011 = v905->cache_tags;
    int v1120 = (((v932 + ((~(((v934 ^ -1) | (-(v934 ^ -1))) >> 31)) & 2)) - (v936 + ((~(((v938 ^ -1) | (-(v938 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v1011[v1120] = 0;
    int * v1013 = v905->cache_dirty;
    v1013[v1120] = 0;
    int * v1015 = v905->cache_age;
    v1015[v1120] = 1;
    int * v1017 = v905->cache_age;
    int v1018 = v1017[v1120];
    int * v1019 = v905->cache_age;
    int v1020 = v1019[0];
    int * v1021 = v905->cache_age;
    int v1126 = v1020 + ((int)((unsigned int)(v1020 - v1018) >> 31));
    v1021[0] = v1126;
    int * v1023 = v905->cache_age;
    int v1024 = v1023[1];
    int * v1025 = v905->cache_age;
    int v1129 = v1024 + ((int)((unsigned int)(v1024 - v1018) >> 31));
    v1025[1] = v1129;
    int * v1027 = v905->cache_age;
    v1027[v1120] = 0;
    v1030 = v1120;
  }
  int v1132 = v1030 * 2;
  int v1031 = v917[v1132];
  int * v1032 = v905->reg_ready;
  int v1135 = (v906 + 1) + ((100 ^ (((~((v914 | (-v914)) >> 31)) | (~((v916 | (-v916)) >> 31))) & 104)) ^ (((~((v910 | (-v910)) >> 31)) | (~((v912 | (-v912)) >> 31))) & (1 ^ (100 ^ (((~((v914 | (-v914)) >> 31)) | (~((v916 | (-v916)) >> 31))) & 104)))));
  v1032[14] = v1135;
  int * v1034 = v905->regs;
  v1034[14] = v1031;
  return v905;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v4 = v2->timer;
  int v12 = v4 + 1;
  v2->timer = v12;
  int * v6 = v2->reg_ready;
  int v15 = v3 + 1;
  v6[13] = v15;
  int * v8 = v2->regs;
  v8[13] = 0;
  struct StateT * v10 = slot_1(v2);
  return v10;
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