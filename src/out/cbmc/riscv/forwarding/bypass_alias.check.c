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

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v1256);
struct StateT * slot_6(struct StateT * v1038);
struct StateT * slot_5(struct StateT * v1025);
struct StateT * slot_4(struct StateT * v245);
struct StateT * slot_2(struct StateT * v219);
struct StateT * slot_7(struct StateT * v1052);
struct StateT * slot_3(struct StateT * v232);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v126 = v16 + 1;
  v15->timer = v126;
  int * v18 = v15->regs;
  int v19 = v18[6];
  int * v20 = v15->cache_tags;
  int v130 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2;
  int v21 = v20[v130];
  int v131 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + 1;
  int v22 = v20[v131];
  int v132 = 4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2);
  int v23 = v20[v132];
  int v133 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v24 = v20[v133];
  int v25 = v15->timer;
  int v134 = v25 + ((100 ^ (((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & 104)))));
  v15->timer = v134;
  int * v27 = v15->cache_vals;
  bool v135 = !(((~(((v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) == 0);
  int v120;
  if (v135) {
    int * v28 = v15->cache_age;
    int v137 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) & 1);
    int v29 = v28[v137];
    int v30 = v28[v130];
    int v138 = v30 + ((int)((unsigned int)(v30 - v29) >> 31));
    v28[v130] = v138;
    int * v32 = v15->cache_age;
    int v33 = v32[v131];
    int v140 = v33 + ((int)((unsigned int)(v33 - v29) >> 31));
    v32[v131] = v140;
    int * v35 = v15->cache_age;
    v35[v137] = 0;
    v120 = v137;
  } else {
    int * v38 = v15->cache_age;
    int v144 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2;
    int v39 = v38[v144];
    int * v40 = v15->cache_tags;
    int v41 = v40[v144];
    int v42 = v38[v131];
    int v43 = v40[v131];
    bool v146 = !(((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) == 0);
    int v97;
    if (v146) {
      int * v44 = v15->cache_age;
      int v148 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) & 1);
      int v45 = v44[v148];
      int v46 = v44[v132];
      int v149 = v46 + ((int)((unsigned int)(v46 - v45) >> 31));
      v44[v132] = v149;
      int * v48 = v15->cache_age;
      int v49 = v48[v133];
      int v151 = v49 + ((int)((unsigned int)(v49 - v45) >> 31));
      v48[v133] = v151;
      int * v51 = v15->cache_age;
      v51[v148] = 0;
      v97 = v148;
    } else {
      int * v54 = v15->cache_age;
      int v155 = 4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2);
      int v55 = v54[v155];
      int * v56 = v15->cache_tags;
      int v57 = v56[v155];
      int v58 = v54[v133];
      int v59 = v56[v133];
      int * v60 = v15->cache_dirty;
      int v158 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v61 = v60[v158];
      bool v159 = !(v61 == 0);
      if (v159) {
        int * v62 = v15->cache_tags;
        int v63 = v62[v158];
        int * v64 = v15->cache_vals;
        int v162 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v65 = v64[v162];
        int v163 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v66 = v64[v163];
        int * v67 = v15->mem;
        int v165 = v63 * 2;
        v67[v165] = v65;
        int * v69 = v15->mem;
        int v168 = (v63 * 2) + 1;
        v69[v168] = v66;
        ;
      } else {
        ;
      }
      int * v74 = v15->mem;
      int v173 = ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) * 2;
      int v75 = v74[v173];
      int v174 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) * 2) + 1;
      int v76 = v74[v174];
      int * v77 = v15->cache_vals;
      int v176 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v77[v176] = v75;
      int * v79 = v15->cache_vals;
      int v179 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v79[v179] = v76;
      int * v81 = v15->cache_tags;
      int v182 = (int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1);
      v81[v158] = v182;
      int * v83 = v15->cache_dirty;
      v83[v158] = 0;
      int * v85 = v15->cache_age;
      v85[v158] = 1;
      int * v87 = v15->cache_age;
      int v88 = v87[v158];
      int v89 = v87[v132];
      int v188 = v89 + ((int)((unsigned int)(v89 - v88) >> 31));
      v87[v132] = v188;
      int * v91 = v15->cache_age;
      int v92 = v91[v133];
      int v190 = v92 + ((int)((unsigned int)(v92 - v88) >> 31));
      v91[v133] = v190;
      int * v94 = v15->cache_age;
      v94[v158] = 0;
      v97 = v158;
    }
    int * v98 = v15->cache_vals;
    int v193 = v97 * 2;
    int v99 = v98[v193];
    int v194 = (v97 * 2) + 1;
    int v100 = v98[v194];
    int v195 = (((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v39 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2)) - (v42 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v98[v195] = v99;
    int * v102 = v15->cache_vals;
    int v198 = ((((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v39 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2)) - (v42 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v102[v198] = v100;
    int * v104 = v15->cache_tags;
    int v201 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v39 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2)) - (v42 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v202 = (int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1);
    v104[v201] = v202;
    int * v106 = v15->cache_dirty;
    v106[v201] = 0;
    int * v108 = v15->cache_age;
    v108[v201] = 1;
    int * v110 = v15->cache_age;
    int v111 = v110[v201];
    int v112 = v110[v130];
    int v208 = v112 + ((int)((unsigned int)(v112 - v111) >> 31));
    v110[v130] = v208;
    int * v114 = v15->cache_age;
    int v115 = v114[v131];
    int v210 = v115 + ((int)((unsigned int)(v115 - v111) >> 31));
    v114[v131] = v210;
    int * v117 = v15->cache_age;
    v117[v201] = 0;
    v120 = v201;
  }
  int v213 = (v120 * 2) + (((int)((unsigned int)v19 >> 2)) & 1);
  int v121 = v27[v213];
  int * v122 = v15->regs;
  v122[5] = v121;
  struct StateT * v124 = slot_2(v15);
  return v124;
}

struct StateT * slot_8(struct StateT * v1256) {
  int v1257 = v1256->timer;
  int v1366 = v1257 + 1;
  v1256->timer = v1366;
  int * v1259 = v1256->regs;
  int v1260 = v1259[11];
  int * v1261 = v1256->cache_tags;
  int v1370 = (((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1)) & 1) * 2;
  int v1262 = v1261[v1370];
  int v1371 = ((((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1263 = v1261[v1371];
  int v1372 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1)) & 3) * 2);
  int v1264 = v1261[v1372];
  int v1373 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1265 = v1261[v1373];
  int v1266 = v1256->timer;
  int v1374 = v1266 + ((100 ^ (((~(((v1264 ^ ((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1))) | (-(v1264 ^ ((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1))))) >> 31)) | (~(((v1265 ^ ((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1))) | (-(v1265 ^ ((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1262 ^ ((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1))) | (-(v1262 ^ ((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1))))) >> 31)) | (~(((v1263 ^ ((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1))) | (-(v1263 ^ ((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1264 ^ ((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1))) | (-(v1264 ^ ((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1))))) >> 31)) | (~(((v1265 ^ ((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1))) | (-(v1265 ^ ((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1256->timer = v1374;
  int * v1268 = v1256->cache_vals;
  bool v1375 = !(((~(((v1262 ^ ((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1))) | (-(v1262 ^ ((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1))))) >> 31)) | (~(((v1263 ^ ((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1))) | (-(v1263 ^ ((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1))))) >> 31))) == 0);
  int v1361;
  if (v1375) {
    int * v1269 = v1256->cache_age;
    int v1377 = ((((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1)) & 1) * 2) + ((~(((v1263 ^ ((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1))) | (-(v1263 ^ ((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1))))) >> 31)) & 1);
    int v1270 = v1269[v1377];
    int v1271 = v1269[v1370];
    int v1378 = v1271 + ((int)((unsigned int)(v1271 - v1270) >> 31));
    v1269[v1370] = v1378;
    int * v1273 = v1256->cache_age;
    int v1274 = v1273[v1371];
    int v1380 = v1274 + ((int)((unsigned int)(v1274 - v1270) >> 31));
    v1273[v1371] = v1380;
    int * v1276 = v1256->cache_age;
    v1276[v1377] = 0;
    v1361 = v1377;
  } else {
    int * v1279 = v1256->cache_age;
    int v1384 = (((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1)) & 1) * 2;
    int v1280 = v1279[v1384];
    int * v1281 = v1256->cache_tags;
    int v1282 = v1281[v1384];
    int v1283 = v1279[v1371];
    int v1284 = v1281[v1371];
    bool v1386 = !(((~(((v1264 ^ ((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1))) | (-(v1264 ^ ((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1))))) >> 31)) | (~(((v1265 ^ ((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1))) | (-(v1265 ^ ((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1))))) >> 31))) == 0);
    int v1338;
    if (v1386) {
      int * v1285 = v1256->cache_age;
      int v1388 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1265 ^ ((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1))) | (-(v1265 ^ ((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1))))) >> 31)) & 1);
      int v1286 = v1285[v1388];
      int v1287 = v1285[v1372];
      int v1389 = v1287 + ((int)((unsigned int)(v1287 - v1286) >> 31));
      v1285[v1372] = v1389;
      int * v1289 = v1256->cache_age;
      int v1290 = v1289[v1373];
      int v1391 = v1290 + ((int)((unsigned int)(v1290 - v1286) >> 31));
      v1289[v1373] = v1391;
      int * v1292 = v1256->cache_age;
      v1292[v1388] = 0;
      v1338 = v1388;
    } else {
      int * v1295 = v1256->cache_age;
      int v1395 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1)) & 3) * 2);
      int v1296 = v1295[v1395];
      int * v1297 = v1256->cache_tags;
      int v1298 = v1297[v1395];
      int v1299 = v1295[v1373];
      int v1300 = v1297[v1373];
      int * v1301 = v1256->cache_dirty;
      int v1398 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1)) & 3) * 2)) + ((((v1296 + ((~(((v1298 ^ -1) | (-(v1298 ^ -1))) >> 31)) & 2)) - (v1299 + ((~(((v1300 ^ -1) | (-(v1300 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1302 = v1301[v1398];
      bool v1399 = !(v1302 == 0);
      if (v1399) {
        int * v1303 = v1256->cache_tags;
        int v1304 = v1303[v1398];
        int * v1305 = v1256->cache_vals;
        int v1402 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1)) & 3) * 2)) + ((((v1296 + ((~(((v1298 ^ -1) | (-(v1298 ^ -1))) >> 31)) & 2)) - (v1299 + ((~(((v1300 ^ -1) | (-(v1300 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1306 = v1305[v1402];
        int v1403 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1)) & 3) * 2)) + ((((v1296 + ((~(((v1298 ^ -1) | (-(v1298 ^ -1))) >> 31)) & 2)) - (v1299 + ((~(((v1300 ^ -1) | (-(v1300 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1307 = v1305[v1403];
        int * v1308 = v1256->mem;
        int v1405 = v1304 * 2;
        v1308[v1405] = v1306;
        int * v1310 = v1256->mem;
        int v1408 = (v1304 * 2) + 1;
        v1310[v1408] = v1307;
        ;
      } else {
        ;
      }
      int * v1315 = v1256->mem;
      int v1413 = ((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1)) * 2;
      int v1316 = v1315[v1413];
      int v1414 = (((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1)) * 2) + 1;
      int v1317 = v1315[v1414];
      int * v1318 = v1256->cache_vals;
      int v1416 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1)) & 3) * 2)) + ((((v1296 + ((~(((v1298 ^ -1) | (-(v1298 ^ -1))) >> 31)) & 2)) - (v1299 + ((~(((v1300 ^ -1) | (-(v1300 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1318[v1416] = v1316;
      int * v1320 = v1256->cache_vals;
      int v1419 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1)) & 3) * 2)) + ((((v1296 + ((~(((v1298 ^ -1) | (-(v1298 ^ -1))) >> 31)) & 2)) - (v1299 + ((~(((v1300 ^ -1) | (-(v1300 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1320[v1419] = v1317;
      int * v1322 = v1256->cache_tags;
      int v1422 = (int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1);
      v1322[v1398] = v1422;
      int * v1324 = v1256->cache_dirty;
      v1324[v1398] = 0;
      int * v1326 = v1256->cache_age;
      v1326[v1398] = 1;
      int * v1328 = v1256->cache_age;
      int v1329 = v1328[v1398];
      int v1330 = v1328[v1372];
      int v1428 = v1330 + ((int)((unsigned int)(v1330 - v1329) >> 31));
      v1328[v1372] = v1428;
      int * v1332 = v1256->cache_age;
      int v1333 = v1332[v1373];
      int v1430 = v1333 + ((int)((unsigned int)(v1333 - v1329) >> 31));
      v1332[v1373] = v1430;
      int * v1335 = v1256->cache_age;
      v1335[v1398] = 0;
      v1338 = v1398;
    }
    int * v1339 = v1256->cache_vals;
    int v1433 = v1338 * 2;
    int v1340 = v1339[v1433];
    int v1434 = (v1338 * 2) + 1;
    int v1341 = v1339[v1434];
    int v1435 = (((((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1)) & 1) * 2) + ((((v1280 + ((~(((v1282 ^ -1) | (-(v1282 ^ -1))) >> 31)) & 2)) - (v1283 + ((~(((v1284 ^ -1) | (-(v1284 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1339[v1435] = v1340;
    int * v1343 = v1256->cache_vals;
    int v1438 = ((((((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1)) & 1) * 2) + ((((v1280 + ((~(((v1282 ^ -1) | (-(v1282 ^ -1))) >> 31)) & 2)) - (v1283 + ((~(((v1284 ^ -1) | (-(v1284 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1343[v1438] = v1341;
    int * v1345 = v1256->cache_tags;
    int v1441 = ((((int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1)) & 1) * 2) + ((((v1280 + ((~(((v1282 ^ -1) | (-(v1282 ^ -1))) >> 31)) & 2)) - (v1283 + ((~(((v1284 ^ -1) | (-(v1284 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1442 = (int)((unsigned int)((int)((unsigned int)v1260 >> 2)) >> 1);
    v1345[v1441] = v1442;
    int * v1347 = v1256->cache_dirty;
    v1347[v1441] = 0;
    int * v1349 = v1256->cache_age;
    v1349[v1441] = 1;
    int * v1351 = v1256->cache_age;
    int v1352 = v1351[v1441];
    int v1353 = v1351[v1370];
    int v1448 = v1353 + ((int)((unsigned int)(v1353 - v1352) >> 31));
    v1351[v1370] = v1448;
    int * v1355 = v1256->cache_age;
    int v1356 = v1355[v1371];
    int v1450 = v1356 + ((int)((unsigned int)(v1356 - v1352) >> 31));
    v1355[v1371] = v1450;
    int * v1358 = v1256->cache_age;
    v1358[v1441] = 0;
    v1361 = v1441;
  }
  int v1453 = (v1361 * 2) + (((int)((unsigned int)v1260 >> 2)) & 1);
  int v1362 = v1268[v1453];
  int * v1363 = v1256->regs;
  v1363[12] = v1362;
  return v1256;
}

struct StateT * slot_6(struct StateT * v1038) {
  int v1039 = v1038->timer;
  int v1046 = v1039 + 1;
  v1038->timer = v1046;
  int * v1041 = v1038->regs;
  int v1042 = v1041[7];
  int v1049 = v1042 + 1;
  v1041[7] = v1049;
  struct StateT * v1044 = slot_7(v1038);
  return v1044;
}

struct StateT * slot_5(struct StateT * v1025) {
  int v1026 = v1025->timer;
  int v1032 = v1026 + 1;
  v1025->timer = v1032;
  int * v1028 = v1025->regs;
  v1028[7] = 0;
  struct StateT * v1030 = slot_6(v1025);
  return v1030;
}

struct StateT * slot_4(struct StateT * v245) {
  int v246 = v245->timer;
  int v679 = v246 + 1;
  v245->timer = v679;
  int * v248 = v245->regs;
  int v249 = v248[8];
  int v250 = v248[5];
  int * v251 = v245->saved_regs;
  int v252 = v248[7];
  v251[7] = v252;
  int v254 = v245->timer;
  int v686 = v254 + 1;
  v245->timer = v686;
  int * v256 = v245->regs;
  v256[7] = 0;
  int v258 = v245->timer;
  int v689 = v258 + 1;
  v245->timer = v689;
  int * v260 = v245->regs;
  int v261 = v260[7];
  int v691 = v261 + 1;
  v260[7] = v691;
  int * v263 = v245->saved_regs;
  int * v264 = v245->regs;
  int v265 = v264[11];
  v263[11] = v265;
  int v267 = v245->timer;
  int v696 = v267 + 1;
  v245->timer = v696;
  int * v269 = v245->regs;
  int v270 = v269[9];
  bool v699 = (((int)((unsigned int)v249 >> 2)) & 3) == (((int)((unsigned int)v270 >> 2)) & 3);
  int v377;
  if (v699) {
    int v271 = v245->timer;
    int v700 = v271 + 1;
    v245->timer = v700;
    v377 = v250;
  } else {
    int * v274 = v245->cache_tags;
    int v703 = (((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1)) & 1) * 2;
    int v275 = v274[v703];
    int v704 = ((((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1)) & 1) * 2) + 1;
    int v276 = v274[v704];
    int v705 = 4 + ((((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1)) & 3) * 2);
    int v277 = v274[v705];
    int v706 = (4 + ((((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1)) & 3) * 2)) + 1;
    int v278 = v274[v706];
    int v279 = v245->timer;
    int v707 = v279 + ((100 ^ (((~(((v277 ^ ((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1))) | (-(v277 ^ ((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1))))) >> 31)) | (~(((v278 ^ ((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1))) | (-(v278 ^ ((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v275 ^ ((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1))) | (-(v275 ^ ((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1))))) >> 31)) | (~(((v276 ^ ((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1))) | (-(v276 ^ ((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v277 ^ ((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1))) | (-(v277 ^ ((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1))))) >> 31)) | (~(((v278 ^ ((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1))) | (-(v278 ^ ((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1))))) >> 31))) & 104)))));
    v245->timer = v707;
    int * v281 = v245->cache_vals;
    bool v708 = !(((~(((v275 ^ ((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1))) | (-(v275 ^ ((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1))))) >> 31)) | (~(((v276 ^ ((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1))) | (-(v276 ^ ((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1))))) >> 31))) == 0);
    int v374;
    if (v708) {
      int * v282 = v245->cache_age;
      int v710 = ((((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1)) & 1) * 2) + ((~(((v276 ^ ((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1))) | (-(v276 ^ ((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1))))) >> 31)) & 1);
      int v283 = v282[v710];
      int v284 = v282[v703];
      int v711 = v284 + ((int)((unsigned int)(v284 - v283) >> 31));
      v282[v703] = v711;
      int * v286 = v245->cache_age;
      int v287 = v286[v704];
      int v713 = v287 + ((int)((unsigned int)(v287 - v283) >> 31));
      v286[v704] = v713;
      int * v289 = v245->cache_age;
      v289[v710] = 0;
      v374 = v710;
    } else {
      int * v292 = v245->cache_age;
      int v716 = (((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1)) & 1) * 2;
      int v293 = v292[v716];
      int * v294 = v245->cache_tags;
      int v295 = v294[v716];
      int v296 = v292[v704];
      int v297 = v294[v704];
      bool v718 = !(((~(((v277 ^ ((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1))) | (-(v277 ^ ((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1))))) >> 31)) | (~(((v278 ^ ((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1))) | (-(v278 ^ ((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1))))) >> 31))) == 0);
      int v351;
      if (v718) {
        int * v298 = v245->cache_age;
        int v720 = (4 + ((((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1)) & 3) * 2)) + ((~(((v278 ^ ((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1))) | (-(v278 ^ ((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1))))) >> 31)) & 1);
        int v299 = v298[v720];
        int v300 = v298[v705];
        int v721 = v300 + ((int)((unsigned int)(v300 - v299) >> 31));
        v298[v705] = v721;
        int * v302 = v245->cache_age;
        int v303 = v302[v706];
        int v723 = v303 + ((int)((unsigned int)(v303 - v299) >> 31));
        v302[v706] = v723;
        int * v305 = v245->cache_age;
        v305[v720] = 0;
        v351 = v720;
      } else {
        int * v308 = v245->cache_age;
        int v726 = 4 + ((((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1)) & 3) * 2);
        int v309 = v308[v726];
        int * v310 = v245->cache_tags;
        int v311 = v310[v726];
        int v312 = v308[v706];
        int v313 = v310[v706];
        int * v314 = v245->cache_dirty;
        int v729 = (4 + ((((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1)) & 3) * 2)) + ((((v309 + ((~(((v311 ^ -1) | (-(v311 ^ -1))) >> 31)) & 2)) - (v312 + ((~(((v313 ^ -1) | (-(v313 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v315 = v314[v729];
        bool v730 = !(v315 == 0);
        if (v730) {
          int * v316 = v245->cache_tags;
          int v317 = v316[v729];
          int * v318 = v245->cache_vals;
          int v733 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1)) & 3) * 2)) + ((((v309 + ((~(((v311 ^ -1) | (-(v311 ^ -1))) >> 31)) & 2)) - (v312 + ((~(((v313 ^ -1) | (-(v313 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v319 = v318[v733];
          int v734 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1)) & 3) * 2)) + ((((v309 + ((~(((v311 ^ -1) | (-(v311 ^ -1))) >> 31)) & 2)) - (v312 + ((~(((v313 ^ -1) | (-(v313 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v320 = v318[v734];
          int * v321 = v245->mem;
          int v736 = v317 * 2;
          v321[v736] = v319;
          int * v323 = v245->mem;
          int v739 = (v317 * 2) + 1;
          v323[v739] = v320;
          ;
        } else {
          ;
        }
        int * v328 = v245->mem;
        int v744 = ((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1)) * 2;
        int v329 = v328[v744];
        int v745 = (((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1)) * 2) + 1;
        int v330 = v328[v745];
        int * v331 = v245->cache_vals;
        int v747 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1)) & 3) * 2)) + ((((v309 + ((~(((v311 ^ -1) | (-(v311 ^ -1))) >> 31)) & 2)) - (v312 + ((~(((v313 ^ -1) | (-(v313 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v331[v747] = v329;
        int * v333 = v245->cache_vals;
        int v750 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1)) & 3) * 2)) + ((((v309 + ((~(((v311 ^ -1) | (-(v311 ^ -1))) >> 31)) & 2)) - (v312 + ((~(((v313 ^ -1) | (-(v313 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v333[v750] = v330;
        int * v335 = v245->cache_tags;
        int v753 = (int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1);
        v335[v729] = v753;
        int * v337 = v245->cache_dirty;
        v337[v729] = 0;
        int * v339 = v245->cache_age;
        v339[v729] = 1;
        int * v341 = v245->cache_age;
        int v342 = v341[v729];
        int v343 = v341[v705];
        int v758 = v343 + ((int)((unsigned int)(v343 - v342) >> 31));
        v341[v705] = v758;
        int * v345 = v245->cache_age;
        int v346 = v345[v706];
        int v760 = v346 + ((int)((unsigned int)(v346 - v342) >> 31));
        v345[v706] = v760;
        int * v348 = v245->cache_age;
        v348[v729] = 0;
        v351 = v729;
      }
      int * v352 = v245->cache_vals;
      int v763 = v351 * 2;
      int v353 = v352[v763];
      int v764 = (v351 * 2) + 1;
      int v354 = v352[v764];
      int v765 = (((((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1)) & 1) * 2) + ((((v293 + ((~(((v295 ^ -1) | (-(v295 ^ -1))) >> 31)) & 2)) - (v296 + ((~(((v297 ^ -1) | (-(v297 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v352[v765] = v353;
      int * v356 = v245->cache_vals;
      int v768 = ((((((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1)) & 1) * 2) + ((((v293 + ((~(((v295 ^ -1) | (-(v295 ^ -1))) >> 31)) & 2)) - (v296 + ((~(((v297 ^ -1) | (-(v297 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v356[v768] = v354;
      int * v358 = v245->cache_tags;
      int v771 = ((((int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1)) & 1) * 2) + ((((v293 + ((~(((v295 ^ -1) | (-(v295 ^ -1))) >> 31)) & 2)) - (v296 + ((~(((v297 ^ -1) | (-(v297 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v772 = (int)((unsigned int)((int)((unsigned int)v270 >> 2)) >> 1);
      v358[v771] = v772;
      int * v360 = v245->cache_dirty;
      v360[v771] = 0;
      int * v362 = v245->cache_age;
      v362[v771] = 1;
      int * v364 = v245->cache_age;
      int v365 = v364[v771];
      int v366 = v364[v703];
      int v777 = v366 + ((int)((unsigned int)(v366 - v365) >> 31));
      v364[v703] = v777;
      int * v368 = v245->cache_age;
      int v369 = v368[v704];
      int v779 = v369 + ((int)((unsigned int)(v369 - v365) >> 31));
      v368[v704] = v779;
      int * v371 = v245->cache_age;
      v371[v771] = 0;
      v374 = v771;
    }
    int v782 = (v374 * 2) + (((int)((unsigned int)v270 >> 2)) & 1);
    int v375 = v281[v782];
    v377 = v375;
  }
  int * v378 = v245->regs;
  v378[11] = v377;
  int * v380 = v245->saved_regs;
  int * v381 = v245->regs;
  int v382 = v381[12];
  v380[12] = v382;
  int v384 = v245->timer;
  int v790 = v384 + 1;
  v245->timer = v790;
  int * v386 = v245->regs;
  int v387 = v386[11];
  bool v792 = (((int)((unsigned int)v249 >> 2)) & 3) == (((int)((unsigned int)v387 >> 2)) & 3);
  int v494;
  if (v792) {
    int v388 = v245->timer;
    int v793 = v388 + 1;
    v245->timer = v793;
    v494 = v250;
  } else {
    int * v391 = v245->cache_tags;
    int v796 = (((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1)) & 1) * 2;
    int v392 = v391[v796];
    int v797 = ((((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1)) & 1) * 2) + 1;
    int v393 = v391[v797];
    int v798 = 4 + ((((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1)) & 3) * 2);
    int v394 = v391[v798];
    int v799 = (4 + ((((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1)) & 3) * 2)) + 1;
    int v395 = v391[v799];
    int v396 = v245->timer;
    int v800 = v396 + ((100 ^ (((~(((v394 ^ ((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1))) | (-(v394 ^ ((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1))))) >> 31)) | (~(((v395 ^ ((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1))) | (-(v395 ^ ((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v392 ^ ((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1))) | (-(v392 ^ ((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1))))) >> 31)) | (~(((v393 ^ ((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1))) | (-(v393 ^ ((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v394 ^ ((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1))) | (-(v394 ^ ((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1))))) >> 31)) | (~(((v395 ^ ((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1))) | (-(v395 ^ ((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1))))) >> 31))) & 104)))));
    v245->timer = v800;
    int * v398 = v245->cache_vals;
    bool v801 = !(((~(((v392 ^ ((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1))) | (-(v392 ^ ((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1))))) >> 31)) | (~(((v393 ^ ((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1))) | (-(v393 ^ ((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1))))) >> 31))) == 0);
    int v491;
    if (v801) {
      int * v399 = v245->cache_age;
      int v803 = ((((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1)) & 1) * 2) + ((~(((v393 ^ ((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1))) | (-(v393 ^ ((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1))))) >> 31)) & 1);
      int v400 = v399[v803];
      int v401 = v399[v796];
      int v804 = v401 + ((int)((unsigned int)(v401 - v400) >> 31));
      v399[v796] = v804;
      int * v403 = v245->cache_age;
      int v404 = v403[v797];
      int v806 = v404 + ((int)((unsigned int)(v404 - v400) >> 31));
      v403[v797] = v806;
      int * v406 = v245->cache_age;
      v406[v803] = 0;
      v491 = v803;
    } else {
      int * v409 = v245->cache_age;
      int v809 = (((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1)) & 1) * 2;
      int v410 = v409[v809];
      int * v411 = v245->cache_tags;
      int v412 = v411[v809];
      int v413 = v409[v797];
      int v414 = v411[v797];
      bool v811 = !(((~(((v394 ^ ((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1))) | (-(v394 ^ ((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1))))) >> 31)) | (~(((v395 ^ ((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1))) | (-(v395 ^ ((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1))))) >> 31))) == 0);
      int v468;
      if (v811) {
        int * v415 = v245->cache_age;
        int v813 = (4 + ((((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1)) & 3) * 2)) + ((~(((v395 ^ ((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1))) | (-(v395 ^ ((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1))))) >> 31)) & 1);
        int v416 = v415[v813];
        int v417 = v415[v798];
        int v814 = v417 + ((int)((unsigned int)(v417 - v416) >> 31));
        v415[v798] = v814;
        int * v419 = v245->cache_age;
        int v420 = v419[v799];
        int v816 = v420 + ((int)((unsigned int)(v420 - v416) >> 31));
        v419[v799] = v816;
        int * v422 = v245->cache_age;
        v422[v813] = 0;
        v468 = v813;
      } else {
        int * v425 = v245->cache_age;
        int v819 = 4 + ((((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1)) & 3) * 2);
        int v426 = v425[v819];
        int * v427 = v245->cache_tags;
        int v428 = v427[v819];
        int v429 = v425[v799];
        int v430 = v427[v799];
        int * v431 = v245->cache_dirty;
        int v822 = (4 + ((((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1)) & 3) * 2)) + ((((v426 + ((~(((v428 ^ -1) | (-(v428 ^ -1))) >> 31)) & 2)) - (v429 + ((~(((v430 ^ -1) | (-(v430 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v432 = v431[v822];
        bool v823 = !(v432 == 0);
        if (v823) {
          int * v433 = v245->cache_tags;
          int v434 = v433[v822];
          int * v435 = v245->cache_vals;
          int v826 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1)) & 3) * 2)) + ((((v426 + ((~(((v428 ^ -1) | (-(v428 ^ -1))) >> 31)) & 2)) - (v429 + ((~(((v430 ^ -1) | (-(v430 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v436 = v435[v826];
          int v827 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1)) & 3) * 2)) + ((((v426 + ((~(((v428 ^ -1) | (-(v428 ^ -1))) >> 31)) & 2)) - (v429 + ((~(((v430 ^ -1) | (-(v430 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v437 = v435[v827];
          int * v438 = v245->mem;
          int v829 = v434 * 2;
          v438[v829] = v436;
          int * v440 = v245->mem;
          int v832 = (v434 * 2) + 1;
          v440[v832] = v437;
          ;
        } else {
          ;
        }
        int * v445 = v245->mem;
        int v837 = ((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1)) * 2;
        int v446 = v445[v837];
        int v838 = (((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1)) * 2) + 1;
        int v447 = v445[v838];
        int * v448 = v245->cache_vals;
        int v840 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1)) & 3) * 2)) + ((((v426 + ((~(((v428 ^ -1) | (-(v428 ^ -1))) >> 31)) & 2)) - (v429 + ((~(((v430 ^ -1) | (-(v430 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v448[v840] = v446;
        int * v450 = v245->cache_vals;
        int v843 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1)) & 3) * 2)) + ((((v426 + ((~(((v428 ^ -1) | (-(v428 ^ -1))) >> 31)) & 2)) - (v429 + ((~(((v430 ^ -1) | (-(v430 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v450[v843] = v447;
        int * v452 = v245->cache_tags;
        int v846 = (int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1);
        v452[v822] = v846;
        int * v454 = v245->cache_dirty;
        v454[v822] = 0;
        int * v456 = v245->cache_age;
        v456[v822] = 1;
        int * v458 = v245->cache_age;
        int v459 = v458[v822];
        int v460 = v458[v798];
        int v851 = v460 + ((int)((unsigned int)(v460 - v459) >> 31));
        v458[v798] = v851;
        int * v462 = v245->cache_age;
        int v463 = v462[v799];
        int v853 = v463 + ((int)((unsigned int)(v463 - v459) >> 31));
        v462[v799] = v853;
        int * v465 = v245->cache_age;
        v465[v822] = 0;
        v468 = v822;
      }
      int * v469 = v245->cache_vals;
      int v856 = v468 * 2;
      int v470 = v469[v856];
      int v857 = (v468 * 2) + 1;
      int v471 = v469[v857];
      int v858 = (((((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1)) & 1) * 2) + ((((v410 + ((~(((v412 ^ -1) | (-(v412 ^ -1))) >> 31)) & 2)) - (v413 + ((~(((v414 ^ -1) | (-(v414 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v469[v858] = v470;
      int * v473 = v245->cache_vals;
      int v861 = ((((((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1)) & 1) * 2) + ((((v410 + ((~(((v412 ^ -1) | (-(v412 ^ -1))) >> 31)) & 2)) - (v413 + ((~(((v414 ^ -1) | (-(v414 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v473[v861] = v471;
      int * v475 = v245->cache_tags;
      int v864 = ((((int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1)) & 1) * 2) + ((((v410 + ((~(((v412 ^ -1) | (-(v412 ^ -1))) >> 31)) & 2)) - (v413 + ((~(((v414 ^ -1) | (-(v414 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v865 = (int)((unsigned int)((int)((unsigned int)v387 >> 2)) >> 1);
      v475[v864] = v865;
      int * v477 = v245->cache_dirty;
      v477[v864] = 0;
      int * v479 = v245->cache_age;
      v479[v864] = 1;
      int * v481 = v245->cache_age;
      int v482 = v481[v864];
      int v483 = v481[v796];
      int v870 = v483 + ((int)((unsigned int)(v483 - v482) >> 31));
      v481[v796] = v870;
      int * v485 = v245->cache_age;
      int v486 = v485[v797];
      int v872 = v486 + ((int)((unsigned int)(v486 - v482) >> 31));
      v485[v797] = v872;
      int * v488 = v245->cache_age;
      v488[v864] = 0;
      v491 = v864;
    }
    int v875 = (v491 * 2) + (((int)((unsigned int)v387 >> 2)) & 1);
    int v492 = v398[v875];
    v494 = v492;
  }
  int * v495 = v245->regs;
  v495[12] = v494;
  int * v497 = v245->cache_tags;
  int v880 = (((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 1) * 2;
  int v498 = v497[v880];
  int v881 = ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 1) * 2) + 1;
  int v499 = v497[v881];
  int v882 = 4 + ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 3) * 2);
  int v500 = v497[v882];
  int v883 = (4 + ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v501 = v497[v883];
  int v502 = v245->timer;
  int v884 = v502 + ((100 ^ (((~(((v500 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))) | (-(v500 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))))) >> 31)) | (~(((v501 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))) | (-(v501 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v498 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))) | (-(v498 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))))) >> 31)) | (~(((v499 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))) | (-(v499 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v500 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))) | (-(v500 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))))) >> 31)) | (~(((v501 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))) | (-(v501 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))))) >> 31))) & 104)))));
  v245->timer = v884;
  bool v885 = !(((~(((v498 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))) | (-(v498 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))))) >> 31)) | (~(((v499 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))) | (-(v499 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))))) >> 31))) == 0);
  int v596;
  if (v885) {
    int * v504 = v245->cache_age;
    int v887 = ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 1) * 2) + ((~(((v499 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))) | (-(v499 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))))) >> 31)) & 1);
    int v505 = v504[v887];
    int v506 = v504[v880];
    int v888 = v506 + ((int)((unsigned int)(v506 - v505) >> 31));
    v504[v880] = v888;
    int * v508 = v245->cache_age;
    int v509 = v508[v881];
    int v890 = v509 + ((int)((unsigned int)(v509 - v505) >> 31));
    v508[v881] = v890;
    int * v511 = v245->cache_age;
    v511[v887] = 0;
    v596 = v887;
  } else {
    int * v514 = v245->cache_age;
    int v893 = (((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 1) * 2;
    int v515 = v514[v893];
    int * v516 = v245->cache_tags;
    int v517 = v516[v893];
    int v518 = v514[v881];
    int v519 = v516[v881];
    bool v895 = !(((~(((v500 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))) | (-(v500 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))))) >> 31)) | (~(((v501 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))) | (-(v501 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))))) >> 31))) == 0);
    int v573;
    if (v895) {
      int * v520 = v245->cache_age;
      int v897 = (4 + ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 3) * 2)) + ((~(((v501 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))) | (-(v501 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))))) >> 31)) & 1);
      int v521 = v520[v897];
      int v522 = v520[v882];
      int v898 = v522 + ((int)((unsigned int)(v522 - v521) >> 31));
      v520[v882] = v898;
      int * v524 = v245->cache_age;
      int v525 = v524[v883];
      int v900 = v525 + ((int)((unsigned int)(v525 - v521) >> 31));
      v524[v883] = v900;
      int * v527 = v245->cache_age;
      v527[v897] = 0;
      v573 = v897;
    } else {
      int * v530 = v245->cache_age;
      int v903 = 4 + ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 3) * 2);
      int v531 = v530[v903];
      int * v532 = v245->cache_tags;
      int v533 = v532[v903];
      int v534 = v530[v883];
      int v535 = v532[v883];
      int * v536 = v245->cache_dirty;
      int v906 = (4 + ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 3) * 2)) + ((((v531 + ((~(((v533 ^ -1) | (-(v533 ^ -1))) >> 31)) & 2)) - (v534 + ((~(((v535 ^ -1) | (-(v535 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v537 = v536[v906];
      bool v907 = !(v537 == 0);
      if (v907) {
        int * v538 = v245->cache_tags;
        int v539 = v538[v906];
        int * v540 = v245->cache_vals;
        int v910 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 3) * 2)) + ((((v531 + ((~(((v533 ^ -1) | (-(v533 ^ -1))) >> 31)) & 2)) - (v534 + ((~(((v535 ^ -1) | (-(v535 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v541 = v540[v910];
        int v911 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 3) * 2)) + ((((v531 + ((~(((v533 ^ -1) | (-(v533 ^ -1))) >> 31)) & 2)) - (v534 + ((~(((v535 ^ -1) | (-(v535 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v542 = v540[v911];
        int * v543 = v245->mem;
        int v913 = v539 * 2;
        v543[v913] = v541;
        int * v545 = v245->mem;
        int v916 = (v539 * 2) + 1;
        v545[v916] = v542;
        ;
      } else {
        ;
      }
      int * v550 = v245->mem;
      int v921 = ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) * 2;
      int v551 = v550[v921];
      int v922 = (((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) * 2) + 1;
      int v552 = v550[v922];
      int * v553 = v245->cache_vals;
      int v924 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 3) * 2)) + ((((v531 + ((~(((v533 ^ -1) | (-(v533 ^ -1))) >> 31)) & 2)) - (v534 + ((~(((v535 ^ -1) | (-(v535 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v553[v924] = v551;
      int * v555 = v245->cache_vals;
      int v927 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 3) * 2)) + ((((v531 + ((~(((v533 ^ -1) | (-(v533 ^ -1))) >> 31)) & 2)) - (v534 + ((~(((v535 ^ -1) | (-(v535 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v555[v927] = v552;
      int * v557 = v245->cache_tags;
      int v930 = (int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1);
      v557[v906] = v930;
      int * v559 = v245->cache_dirty;
      v559[v906] = 0;
      int * v561 = v245->cache_age;
      v561[v906] = 1;
      int * v563 = v245->cache_age;
      int v564 = v563[v906];
      int v565 = v563[v882];
      int v935 = v565 + ((int)((unsigned int)(v565 - v564) >> 31));
      v563[v882] = v935;
      int * v567 = v245->cache_age;
      int v568 = v567[v883];
      int v937 = v568 + ((int)((unsigned int)(v568 - v564) >> 31));
      v567[v883] = v937;
      int * v570 = v245->cache_age;
      v570[v906] = 0;
      v573 = v906;
    }
    int * v574 = v245->cache_vals;
    int v940 = v573 * 2;
    int v575 = v574[v940];
    int v941 = (v573 * 2) + 1;
    int v576 = v574[v941];
    int v942 = (((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 1) * 2) + ((((v515 + ((~(((v517 ^ -1) | (-(v517 ^ -1))) >> 31)) & 2)) - (v518 + ((~(((v519 ^ -1) | (-(v519 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v574[v942] = v575;
    int * v578 = v245->cache_vals;
    int v945 = ((((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 1) * 2) + ((((v515 + ((~(((v517 ^ -1) | (-(v517 ^ -1))) >> 31)) & 2)) - (v518 + ((~(((v519 ^ -1) | (-(v519 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v578[v945] = v576;
    int * v580 = v245->cache_tags;
    int v948 = ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 1) * 2) + ((((v515 + ((~(((v517 ^ -1) | (-(v517 ^ -1))) >> 31)) & 2)) - (v518 + ((~(((v519 ^ -1) | (-(v519 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v949 = (int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1);
    v580[v948] = v949;
    int * v582 = v245->cache_dirty;
    v582[v948] = 0;
    int * v584 = v245->cache_age;
    v584[v948] = 1;
    int * v586 = v245->cache_age;
    int v587 = v586[v948];
    int v588 = v586[v880];
    int v954 = v588 + ((int)((unsigned int)(v588 - v587) >> 31));
    v586[v880] = v954;
    int * v590 = v245->cache_age;
    int v591 = v590[v881];
    int v956 = v591 + ((int)((unsigned int)(v591 - v587) >> 31));
    v590[v881] = v956;
    int * v593 = v245->cache_age;
    v593[v948] = 0;
    v596 = v948;
  }
  int * v597 = v245->cache_vals;
  int v959 = (v596 * 2) + (((int)((unsigned int)v249 >> 2)) & 1);
  v597[v959] = v250;
  int * v599 = v245->cache_tags;
  int v600 = v599[v882];
  int v601 = v599[v883];
  bool v962 = !(((~(((v600 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))) | (-(v600 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))))) >> 31)) | (~(((v601 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))) | (-(v601 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))))) >> 31))) == 0);
  int v655;
  if (v962) {
    int * v602 = v245->cache_age;
    int v964 = (4 + ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 3) * 2)) + ((~(((v601 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))) | (-(v601 ^ ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1))))) >> 31)) & 1);
    int v603 = v602[v964];
    int v604 = v602[v882];
    int v965 = v604 + ((int)((unsigned int)(v604 - v603) >> 31));
    v602[v882] = v965;
    int * v606 = v245->cache_age;
    int v607 = v606[v883];
    int v967 = v607 + ((int)((unsigned int)(v607 - v603) >> 31));
    v606[v883] = v967;
    int * v609 = v245->cache_age;
    v609[v964] = 0;
    v655 = v964;
  } else {
    int * v612 = v245->cache_age;
    int v970 = 4 + ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 3) * 2);
    int v613 = v612[v970];
    int * v614 = v245->cache_tags;
    int v615 = v614[v970];
    int v616 = v612[v883];
    int v617 = v614[v883];
    int * v618 = v245->cache_dirty;
    int v973 = (4 + ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 3) * 2)) + ((((v613 + ((~(((v615 ^ -1) | (-(v615 ^ -1))) >> 31)) & 2)) - (v616 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v619 = v618[v973];
    bool v974 = !(v619 == 0);
    if (v974) {
      int * v620 = v245->cache_tags;
      int v621 = v620[v973];
      int * v622 = v245->cache_vals;
      int v977 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 3) * 2)) + ((((v613 + ((~(((v615 ^ -1) | (-(v615 ^ -1))) >> 31)) & 2)) - (v616 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v623 = v622[v977];
      int v978 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 3) * 2)) + ((((v613 + ((~(((v615 ^ -1) | (-(v615 ^ -1))) >> 31)) & 2)) - (v616 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v624 = v622[v978];
      int * v625 = v245->mem;
      int v980 = v621 * 2;
      v625[v980] = v623;
      int * v627 = v245->mem;
      int v983 = (v621 * 2) + 1;
      v627[v983] = v624;
      ;
    } else {
      ;
    }
    int * v632 = v245->mem;
    int v988 = ((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) * 2;
    int v633 = v632[v988];
    int v989 = (((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) * 2) + 1;
    int v634 = v632[v989];
    int * v635 = v245->cache_vals;
    int v991 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 3) * 2)) + ((((v613 + ((~(((v615 ^ -1) | (-(v615 ^ -1))) >> 31)) & 2)) - (v616 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v635[v991] = v633;
    int * v637 = v245->cache_vals;
    int v994 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1)) & 3) * 2)) + ((((v613 + ((~(((v615 ^ -1) | (-(v615 ^ -1))) >> 31)) & 2)) - (v616 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v637[v994] = v634;
    int * v639 = v245->cache_tags;
    int v997 = (int)((unsigned int)((int)((unsigned int)v249 >> 2)) >> 1);
    v639[v973] = v997;
    int * v641 = v245->cache_dirty;
    v641[v973] = 0;
    int * v643 = v245->cache_age;
    v643[v973] = 1;
    int * v645 = v245->cache_age;
    int v646 = v645[v973];
    int v647 = v645[v882];
    int v1002 = v647 + ((int)((unsigned int)(v647 - v646) >> 31));
    v645[v882] = v1002;
    int * v649 = v245->cache_age;
    int v650 = v649[v883];
    int v1004 = v650 + ((int)((unsigned int)(v650 - v646) >> 31));
    v649[v883] = v1004;
    int * v652 = v245->cache_age;
    v652[v973] = 0;
    v655 = v973;
  }
  int * v656 = v245->cache_vals;
  int v1007 = (v655 * 2) + (((int)((unsigned int)v249 >> 2)) & 1);
  v656[v1007] = v250;
  int * v658 = v245->cache_dirty;
  v658[v655] = 1;
  bool v1011 = (((((int)((unsigned int)v270 >> 2)) & 3) == (((int)((unsigned int)v249 >> 2)) & 3)) & (!(((int)((unsigned int)v270 >> 2)) == ((int)((unsigned int)v249 >> 2))))) | (((((int)((unsigned int)v387 >> 2)) & 3) == (((int)((unsigned int)v249 >> 2)) & 3)) & (!(((int)((unsigned int)v387 >> 2)) == ((int)((unsigned int)v249 >> 2)))));
  struct StateT * v677;
  if (v1011) {
    int v660 = v245->timer;
    int v1012 = v660 + 15;
    v245->timer = v1012;
    int * v662 = v245->saved_regs;
    int v663 = v662[7];
    int * v664 = v245->regs;
    v664[7] = v663;
    int * v666 = v245->saved_regs;
    int v667 = v666[11];
    int * v668 = v245->regs;
    v668[11] = v667;
    int * v670 = v245->saved_regs;
    int v671 = v670[12];
    int * v672 = v245->regs;
    v672[12] = v671;
    struct StateT * v674 = slot_5(v245);
    v677 = v674;
  } else {
    v677 = v245;
  }
  return v677;
}

struct StateT * slot_2(struct StateT * v219) {
  int v220 = v219->timer;
  int v226 = v220 + 1;
  v219->timer = v226;
  int * v222 = v219->regs;
  v222[8] = 96;
  struct StateT * v224 = slot_3(v219);
  return v224;
}

struct StateT * slot_7(struct StateT * v1052) {
  int v1053 = v1052->timer;
  int v1163 = v1053 + 1;
  v1052->timer = v1163;
  int * v1055 = v1052->regs;
  int v1056 = v1055[9];
  int * v1057 = v1052->cache_tags;
  int v1167 = (((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1)) & 1) * 2;
  int v1058 = v1057[v1167];
  int v1168 = ((((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1059 = v1057[v1168];
  int v1169 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1)) & 3) * 2);
  int v1060 = v1057[v1169];
  int v1170 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1061 = v1057[v1170];
  int v1062 = v1052->timer;
  int v1171 = v1062 + ((100 ^ (((~(((v1060 ^ ((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1))) | (-(v1060 ^ ((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1))))) >> 31)) | (~(((v1061 ^ ((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1))) | (-(v1061 ^ ((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1058 ^ ((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1))) | (-(v1058 ^ ((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1))))) >> 31)) | (~(((v1059 ^ ((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1))) | (-(v1059 ^ ((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1060 ^ ((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1))) | (-(v1060 ^ ((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1))))) >> 31)) | (~(((v1061 ^ ((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1))) | (-(v1061 ^ ((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1052->timer = v1171;
  int * v1064 = v1052->cache_vals;
  bool v1172 = !(((~(((v1058 ^ ((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1))) | (-(v1058 ^ ((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1))))) >> 31)) | (~(((v1059 ^ ((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1))) | (-(v1059 ^ ((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1))))) >> 31))) == 0);
  int v1157;
  if (v1172) {
    int * v1065 = v1052->cache_age;
    int v1174 = ((((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1)) & 1) * 2) + ((~(((v1059 ^ ((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1))) | (-(v1059 ^ ((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1))))) >> 31)) & 1);
    int v1066 = v1065[v1174];
    int v1067 = v1065[v1167];
    int v1175 = v1067 + ((int)((unsigned int)(v1067 - v1066) >> 31));
    v1065[v1167] = v1175;
    int * v1069 = v1052->cache_age;
    int v1070 = v1069[v1168];
    int v1177 = v1070 + ((int)((unsigned int)(v1070 - v1066) >> 31));
    v1069[v1168] = v1177;
    int * v1072 = v1052->cache_age;
    v1072[v1174] = 0;
    v1157 = v1174;
  } else {
    int * v1075 = v1052->cache_age;
    int v1181 = (((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1)) & 1) * 2;
    int v1076 = v1075[v1181];
    int * v1077 = v1052->cache_tags;
    int v1078 = v1077[v1181];
    int v1079 = v1075[v1168];
    int v1080 = v1077[v1168];
    bool v1183 = !(((~(((v1060 ^ ((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1))) | (-(v1060 ^ ((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1))))) >> 31)) | (~(((v1061 ^ ((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1))) | (-(v1061 ^ ((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1))))) >> 31))) == 0);
    int v1134;
    if (v1183) {
      int * v1081 = v1052->cache_age;
      int v1185 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1061 ^ ((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1))) | (-(v1061 ^ ((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1))))) >> 31)) & 1);
      int v1082 = v1081[v1185];
      int v1083 = v1081[v1169];
      int v1186 = v1083 + ((int)((unsigned int)(v1083 - v1082) >> 31));
      v1081[v1169] = v1186;
      int * v1085 = v1052->cache_age;
      int v1086 = v1085[v1170];
      int v1188 = v1086 + ((int)((unsigned int)(v1086 - v1082) >> 31));
      v1085[v1170] = v1188;
      int * v1088 = v1052->cache_age;
      v1088[v1185] = 0;
      v1134 = v1185;
    } else {
      int * v1091 = v1052->cache_age;
      int v1192 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1)) & 3) * 2);
      int v1092 = v1091[v1192];
      int * v1093 = v1052->cache_tags;
      int v1094 = v1093[v1192];
      int v1095 = v1091[v1170];
      int v1096 = v1093[v1170];
      int * v1097 = v1052->cache_dirty;
      int v1195 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1)) & 3) * 2)) + ((((v1092 + ((~(((v1094 ^ -1) | (-(v1094 ^ -1))) >> 31)) & 2)) - (v1095 + ((~(((v1096 ^ -1) | (-(v1096 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1098 = v1097[v1195];
      bool v1196 = !(v1098 == 0);
      if (v1196) {
        int * v1099 = v1052->cache_tags;
        int v1100 = v1099[v1195];
        int * v1101 = v1052->cache_vals;
        int v1199 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1)) & 3) * 2)) + ((((v1092 + ((~(((v1094 ^ -1) | (-(v1094 ^ -1))) >> 31)) & 2)) - (v1095 + ((~(((v1096 ^ -1) | (-(v1096 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1102 = v1101[v1199];
        int v1200 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1)) & 3) * 2)) + ((((v1092 + ((~(((v1094 ^ -1) | (-(v1094 ^ -1))) >> 31)) & 2)) - (v1095 + ((~(((v1096 ^ -1) | (-(v1096 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1103 = v1101[v1200];
        int * v1104 = v1052->mem;
        int v1202 = v1100 * 2;
        v1104[v1202] = v1102;
        int * v1106 = v1052->mem;
        int v1205 = (v1100 * 2) + 1;
        v1106[v1205] = v1103;
        ;
      } else {
        ;
      }
      int * v1111 = v1052->mem;
      int v1210 = ((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1)) * 2;
      int v1112 = v1111[v1210];
      int v1211 = (((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1)) * 2) + 1;
      int v1113 = v1111[v1211];
      int * v1114 = v1052->cache_vals;
      int v1213 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1)) & 3) * 2)) + ((((v1092 + ((~(((v1094 ^ -1) | (-(v1094 ^ -1))) >> 31)) & 2)) - (v1095 + ((~(((v1096 ^ -1) | (-(v1096 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1114[v1213] = v1112;
      int * v1116 = v1052->cache_vals;
      int v1216 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1)) & 3) * 2)) + ((((v1092 + ((~(((v1094 ^ -1) | (-(v1094 ^ -1))) >> 31)) & 2)) - (v1095 + ((~(((v1096 ^ -1) | (-(v1096 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1116[v1216] = v1113;
      int * v1118 = v1052->cache_tags;
      int v1219 = (int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1);
      v1118[v1195] = v1219;
      int * v1120 = v1052->cache_dirty;
      v1120[v1195] = 0;
      int * v1122 = v1052->cache_age;
      v1122[v1195] = 1;
      int * v1124 = v1052->cache_age;
      int v1125 = v1124[v1195];
      int v1126 = v1124[v1169];
      int v1225 = v1126 + ((int)((unsigned int)(v1126 - v1125) >> 31));
      v1124[v1169] = v1225;
      int * v1128 = v1052->cache_age;
      int v1129 = v1128[v1170];
      int v1227 = v1129 + ((int)((unsigned int)(v1129 - v1125) >> 31));
      v1128[v1170] = v1227;
      int * v1131 = v1052->cache_age;
      v1131[v1195] = 0;
      v1134 = v1195;
    }
    int * v1135 = v1052->cache_vals;
    int v1230 = v1134 * 2;
    int v1136 = v1135[v1230];
    int v1231 = (v1134 * 2) + 1;
    int v1137 = v1135[v1231];
    int v1232 = (((((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1)) & 1) * 2) + ((((v1076 + ((~(((v1078 ^ -1) | (-(v1078 ^ -1))) >> 31)) & 2)) - (v1079 + ((~(((v1080 ^ -1) | (-(v1080 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1135[v1232] = v1136;
    int * v1139 = v1052->cache_vals;
    int v1235 = ((((((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1)) & 1) * 2) + ((((v1076 + ((~(((v1078 ^ -1) | (-(v1078 ^ -1))) >> 31)) & 2)) - (v1079 + ((~(((v1080 ^ -1) | (-(v1080 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1139[v1235] = v1137;
    int * v1141 = v1052->cache_tags;
    int v1238 = ((((int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1)) & 1) * 2) + ((((v1076 + ((~(((v1078 ^ -1) | (-(v1078 ^ -1))) >> 31)) & 2)) - (v1079 + ((~(((v1080 ^ -1) | (-(v1080 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1239 = (int)((unsigned int)((int)((unsigned int)v1056 >> 2)) >> 1);
    v1141[v1238] = v1239;
    int * v1143 = v1052->cache_dirty;
    v1143[v1238] = 0;
    int * v1145 = v1052->cache_age;
    v1145[v1238] = 1;
    int * v1147 = v1052->cache_age;
    int v1148 = v1147[v1238];
    int v1149 = v1147[v1167];
    int v1245 = v1149 + ((int)((unsigned int)(v1149 - v1148) >> 31));
    v1147[v1167] = v1245;
    int * v1151 = v1052->cache_age;
    int v1152 = v1151[v1168];
    int v1247 = v1152 + ((int)((unsigned int)(v1152 - v1148) >> 31));
    v1151[v1168] = v1247;
    int * v1154 = v1052->cache_age;
    v1154[v1238] = 0;
    v1157 = v1238;
  }
  int v1250 = (v1157 * 2) + (((int)((unsigned int)v1056 >> 2)) & 1);
  int v1158 = v1064[v1250];
  int * v1159 = v1052->regs;
  v1159[11] = v1158;
  struct StateT * v1161 = slot_8(v1052);
  return v1161;
}

struct StateT * slot_3(struct StateT * v232) {
  int v233 = v232->timer;
  int v239 = v233 + 1;
  v232->timer = v239;
  int * v235 = v232->regs;
  v235[9] = 0;
  struct StateT * v237 = slot_4(v232);
  return v237;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[6] = 80;
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