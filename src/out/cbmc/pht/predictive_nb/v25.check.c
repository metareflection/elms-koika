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

struct StateT * slot_12(struct StateT * v798);
struct StateT * slot_6(struct StateT * v482);
struct StateT * slot_29(struct StateT * v1863);
struct StateT * slot_23(struct StateT * v1371);
struct StateT * slot_5(struct StateT * v474);
struct StateT * slot_2(struct StateT * v33);
struct StateT * slot_7(struct StateT * v503);
struct StateT * slot_21(struct StateT * v1140);
struct StateT * slot_31(struct StateT * v2203);
struct StateT * slot_3(struct StateT * v240);
struct StateT * slot_26(struct StateT * v1615);
struct StateT * slot_1(struct StateT * v10);
struct StateT * slot_13(struct StateT * v819);
struct StateT * slot_38(struct StateT * v2692);
struct StateT * slot_24(struct StateT * v1387);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v843);
struct StateT * slot_28(struct StateT * v1839);
struct StateT * slot_32(struct StateT * v2224);
struct StateT * slot_33(struct StateT * v2229);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_4(struct StateT * v458);
struct StateT * slot_15(struct StateT * v859);
struct StateT * slot_18(struct StateT * v1111);
struct StateT * slot_9(struct StateT * v738);
struct StateT * slot_11(struct StateT * v777);
struct StateT * slot_12(struct StateT * v798) {
  int v799 = v798->timer;
  int v810 = v799 + 1;
  v798->timer = v810;
  int * v801 = v798->reg_ready;
  int v802 = v801[11];
  int * v803 = v798->regs;
  int v804 = v803[11];
  int v814 = (v802 + ((v799 - v802) & (~((v799 - v802) >> 31)))) + 1;
  v801[11] = v814;
  int * v806 = v798->regs;
  int v816 = v804 + 4;
  v806[11] = v816;
  struct StateT * v808 = slot_14(v798);
  return v808;
}

struct StateT * slot_6(struct StateT * v482) {
  int v483 = v482->timer;
  int v494 = v483 + 1;
  v482->timer = v494;
  int * v485 = v482->reg_ready;
  int v486 = v485[10];
  int * v487 = v482->regs;
  int v488 = v487[10];
  int v498 = (v486 + ((v483 - v486) & (~((v483 - v486) >> 31)))) + 1;
  v485[10] = v498;
  int * v490 = v482->regs;
  int v500 = v488 + 72;
  v490[10] = v500;
  struct StateT * v492 = slot_21(v482);
  return v492;
}

struct StateT * slot_29(struct StateT * v1863) {
  int v1864 = v1863->timer;
  int v1875 = v1864 + 1;
  v1863->timer = v1875;
  int * v1866 = v1863->reg_ready;
  int v1867 = v1866[10];
  int * v1868 = v1863->regs;
  int v1869 = v1868[10];
  int v1879 = (v1867 + ((v1864 - v1867) & (~((v1864 - v1867) >> 31)))) + 1;
  v1866[10] = v1879;
  int * v1871 = v1863->regs;
  int v1881 = v1869 << 29;
  v1871[10] = v1881;
  struct StateT * v1873 = slot_31(v1863);
  return v1873;
}

struct StateT * slot_23(struct StateT * v1371) {
  int v1372 = v1371->timer;
  int v1380 = v1372 + 1;
  v1371->timer = v1380;
  int * v1374 = v1371->reg_ready;
  v1374[11] = v1380;
  int * v1376 = v1371->regs;
  v1376[11] = 0;
  struct StateT * v1378 = slot_12(v1371);
  return v1378;
}

struct StateT * slot_5(struct StateT * v474) {
  int v475 = v474->timer;
  int v479 = v475 + 1;
  v474->timer = v479;
  struct StateT * v477 = slot_7(v474);
  return v477;
}

struct StateT * slot_2(struct StateT * v33) {
  int v34 = v33->timer;
  int v146 = v34 + 1;
  v33->timer = v146;
  int * v36 = v33->reg_ready;
  int v37 = v36[11];
  int * v38 = v33->regs;
  int v39 = v38[11];
  int * v40 = v33->cache_tags;
  int v151 = (((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 1) * 2;
  int v41 = v40[v151];
  int v152 = ((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 1) * 2) + 1;
  int v42 = v40[v152];
  int v153 = 4 + ((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 3) * 2);
  int v43 = v40[v153];
  int v154 = (4 + ((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v44 = v40[v154];
  int * v45 = v33->cache_vals;
  bool v155 = !(((~(((v41 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))) | (-(v41 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))))) >> 31)) | (~(((v42 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))) | (-(v42 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))))) >> 31))) == 0);
  int v138;
  if (v155) {
    int * v46 = v33->cache_age;
    int v157 = ((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 1) * 2) + ((~(((v42 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))) | (-(v42 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))))) >> 31)) & 1);
    int v47 = v46[v157];
    int v48 = v46[v151];
    int v158 = v48 + ((int)((unsigned int)(v48 - v47) >> 31));
    v46[v151] = v158;
    int * v50 = v33->cache_age;
    int v51 = v50[v152];
    int v160 = v51 + ((int)((unsigned int)(v51 - v47) >> 31));
    v50[v152] = v160;
    int * v53 = v33->cache_age;
    v53[v157] = 0;
    v138 = v157;
  } else {
    int * v56 = v33->cache_age;
    int v164 = (((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 1) * 2;
    int v57 = v56[v164];
    int * v58 = v33->cache_tags;
    int v59 = v58[v164];
    int v60 = v56[v152];
    int v61 = v58[v152];
    bool v166 = !(((~(((v43 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))) | (-(v43 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))))) >> 31)) | (~(((v44 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))) | (-(v44 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))))) >> 31))) == 0);
    int v115;
    if (v166) {
      int * v62 = v33->cache_age;
      int v168 = (4 + ((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 3) * 2)) + ((~(((v44 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))) | (-(v44 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))))) >> 31)) & 1);
      int v63 = v62[v168];
      int v64 = v62[v153];
      int v169 = v64 + ((int)((unsigned int)(v64 - v63) >> 31));
      v62[v153] = v169;
      int * v66 = v33->cache_age;
      int v67 = v66[v154];
      int v171 = v67 + ((int)((unsigned int)(v67 - v63) >> 31));
      v66[v154] = v171;
      int * v69 = v33->cache_age;
      v69[v168] = 0;
      v115 = v168;
    } else {
      int * v72 = v33->cache_age;
      int v175 = 4 + ((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 3) * 2);
      int v73 = v72[v175];
      int * v74 = v33->cache_tags;
      int v75 = v74[v175];
      int v76 = v72[v154];
      int v77 = v74[v154];
      int * v78 = v33->cache_dirty;
      int v178 = (4 + ((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 3) * 2)) + ((((v73 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2)) - (v76 + ((~(((v77 ^ -1) | (-(v77 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v79 = v78[v178];
      bool v179 = !(v79 == 0);
      if (v179) {
        int * v80 = v33->cache_tags;
        int v81 = v80[v178];
        int * v82 = v33->cache_vals;
        int v182 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 3) * 2)) + ((((v73 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2)) - (v76 + ((~(((v77 ^ -1) | (-(v77 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v83 = v82[v182];
        int v183 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 3) * 2)) + ((((v73 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2)) - (v76 + ((~(((v77 ^ -1) | (-(v77 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v84 = v82[v183];
        int * v85 = v33->mem;
        int v185 = v81 * 2;
        v85[v185] = v83;
        int * v87 = v33->mem;
        int v188 = (v81 * 2) + 1;
        v87[v188] = v84;
        ;
      } else {
        ;
      }
      int * v92 = v33->mem;
      int v193 = ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) * 2;
      int v93 = v92[v193];
      int v194 = (((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) * 2) + 1;
      int v94 = v92[v194];
      int * v95 = v33->cache_vals;
      int v196 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 3) * 2)) + ((((v73 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2)) - (v76 + ((~(((v77 ^ -1) | (-(v77 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v95[v196] = v93;
      int * v97 = v33->cache_vals;
      int v199 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 3) * 2)) + ((((v73 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2)) - (v76 + ((~(((v77 ^ -1) | (-(v77 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v97[v199] = v94;
      int * v99 = v33->cache_tags;
      int v202 = (int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1);
      v99[v178] = v202;
      int * v101 = v33->cache_dirty;
      v101[v178] = 0;
      int * v103 = v33->cache_age;
      v103[v178] = 1;
      int * v105 = v33->cache_age;
      int v106 = v105[v178];
      int v107 = v105[v153];
      int v208 = v107 + ((int)((unsigned int)(v107 - v106) >> 31));
      v105[v153] = v208;
      int * v109 = v33->cache_age;
      int v110 = v109[v154];
      int v210 = v110 + ((int)((unsigned int)(v110 - v106) >> 31));
      v109[v154] = v210;
      int * v112 = v33->cache_age;
      v112[v178] = 0;
      v115 = v178;
    }
    int * v116 = v33->cache_vals;
    int v213 = v115 * 2;
    int v117 = v116[v213];
    int v214 = (v115 * 2) + 1;
    int v118 = v116[v214];
    int v215 = (((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 1) * 2) + ((((v57 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2)) - (v60 + ((~(((v61 ^ -1) | (-(v61 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v116[v215] = v117;
    int * v120 = v33->cache_vals;
    int v218 = ((((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 1) * 2) + ((((v57 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2)) - (v60 + ((~(((v61 ^ -1) | (-(v61 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v120[v218] = v118;
    int * v122 = v33->cache_tags;
    int v221 = ((((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1)) & 1) * 2) + ((((v57 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2)) - (v60 + ((~(((v61 ^ -1) | (-(v61 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v222 = (int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1);
    v122[v221] = v222;
    int * v124 = v33->cache_dirty;
    v124[v221] = 0;
    int * v126 = v33->cache_age;
    v126[v221] = 1;
    int * v128 = v33->cache_age;
    int v129 = v128[v221];
    int v130 = v128[v151];
    int v228 = v130 + ((int)((unsigned int)(v130 - v129) >> 31));
    v128[v151] = v228;
    int * v132 = v33->cache_age;
    int v133 = v132[v152];
    int v230 = v133 + ((int)((unsigned int)(v133 - v129) >> 31));
    v132[v152] = v230;
    int * v135 = v33->cache_age;
    v135[v221] = 0;
    v138 = v221;
  }
  int v233 = (v138 * 2) + (((int)((unsigned int)v39 >> 2)) & 1);
  int v139 = v45[v233];
  int * v140 = v33->reg_ready;
  int v235 = ((v37 + ((v34 - v37) & (~((v34 - v37) >> 31)))) + 1) + ((100 ^ (((~(((v43 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))) | (-(v43 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))))) >> 31)) | (~(((v44 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))) | (-(v44 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v41 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))) | (-(v41 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))))) >> 31)) | (~(((v42 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))) | (-(v42 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v43 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))) | (-(v43 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))))) >> 31)) | (~(((v44 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))) | (-(v44 ^ ((int)((unsigned int)((int)((unsigned int)v39 >> 2)) >> 1))))) >> 31))) & 104)))));
  v140[11] = v235;
  int * v142 = v33->regs;
  v142[11] = v139;
  struct StateT * v144 = slot_3(v33);
  return v144;
}

struct StateT * slot_7(struct StateT * v503) {
  int * v504 = v503->saved_regs;
  int * v505 = v503->regs;
  int v506 = v505[10];
  v504[10] = v506;
  int v508 = v503->timer;
  int v523 = v508 + 1;
  v503->timer = v523;
  int * v510 = v503->reg_ready;
  int v511 = v510[10];
  int * v512 = v503->regs;
  int v513 = v512[10];
  int v526 = (v511 + ((v508 - v511) & (~((v508 - v511) >> 31)))) + 1;
  v510[10] = v526;
  int * v515 = v503->regs;
  int v528 = v513 << 2;
  v515[10] = v528;
  struct StateT * v517 = slot_9(v503);
  return v517;
}

struct StateT * slot_21(struct StateT * v1140) {
  int v1141 = v1140->timer;
  int v1253 = v1141 + 1;
  v1140->timer = v1253;
  int * v1143 = v1140->reg_ready;
  int v1144 = v1143[10];
  int * v1145 = v1140->regs;
  int v1146 = v1145[10];
  int * v1147 = v1140->cache_tags;
  int v1258 = (((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1)) & 1) * 2;
  int v1148 = v1147[v1258];
  int v1259 = ((((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1149 = v1147[v1259];
  int v1260 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1)) & 3) * 2);
  int v1150 = v1147[v1260];
  int v1261 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1151 = v1147[v1261];
  int * v1152 = v1140->cache_vals;
  bool v1262 = !(((~(((v1148 ^ ((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1))) | (-(v1148 ^ ((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1))))) >> 31)) | (~(((v1149 ^ ((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1))) | (-(v1149 ^ ((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1))))) >> 31))) == 0);
  int v1245;
  if (v1262) {
    int * v1153 = v1140->cache_age;
    int v1264 = ((((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1)) & 1) * 2) + ((~(((v1149 ^ ((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1))) | (-(v1149 ^ ((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1))))) >> 31)) & 1);
    int v1154 = v1153[v1264];
    int v1155 = v1153[v1258];
    int v1265 = v1155 + ((int)((unsigned int)(v1155 - v1154) >> 31));
    v1153[v1258] = v1265;
    int * v1157 = v1140->cache_age;
    int v1158 = v1157[v1259];
    int v1267 = v1158 + ((int)((unsigned int)(v1158 - v1154) >> 31));
    v1157[v1259] = v1267;
    int * v1160 = v1140->cache_age;
    v1160[v1264] = 0;
    v1245 = v1264;
  } else {
    int * v1163 = v1140->cache_age;
    int v1271 = (((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1)) & 1) * 2;
    int v1164 = v1163[v1271];
    int * v1165 = v1140->cache_tags;
    int v1166 = v1165[v1271];
    int v1167 = v1163[v1259];
    int v1168 = v1165[v1259];
    bool v1273 = !(((~(((v1150 ^ ((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1))) | (-(v1150 ^ ((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1))))) >> 31)) | (~(((v1151 ^ ((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1))) | (-(v1151 ^ ((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1))))) >> 31))) == 0);
    int v1222;
    if (v1273) {
      int * v1169 = v1140->cache_age;
      int v1275 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1151 ^ ((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1))) | (-(v1151 ^ ((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1))))) >> 31)) & 1);
      int v1170 = v1169[v1275];
      int v1171 = v1169[v1260];
      int v1276 = v1171 + ((int)((unsigned int)(v1171 - v1170) >> 31));
      v1169[v1260] = v1276;
      int * v1173 = v1140->cache_age;
      int v1174 = v1173[v1261];
      int v1278 = v1174 + ((int)((unsigned int)(v1174 - v1170) >> 31));
      v1173[v1261] = v1278;
      int * v1176 = v1140->cache_age;
      v1176[v1275] = 0;
      v1222 = v1275;
    } else {
      int * v1179 = v1140->cache_age;
      int v1282 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1)) & 3) * 2);
      int v1180 = v1179[v1282];
      int * v1181 = v1140->cache_tags;
      int v1182 = v1181[v1282];
      int v1183 = v1179[v1261];
      int v1184 = v1181[v1261];
      int * v1185 = v1140->cache_dirty;
      int v1285 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1)) & 3) * 2)) + ((((v1180 + ((~(((v1182 ^ -1) | (-(v1182 ^ -1))) >> 31)) & 2)) - (v1183 + ((~(((v1184 ^ -1) | (-(v1184 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1186 = v1185[v1285];
      bool v1286 = !(v1186 == 0);
      if (v1286) {
        int * v1187 = v1140->cache_tags;
        int v1188 = v1187[v1285];
        int * v1189 = v1140->cache_vals;
        int v1289 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1)) & 3) * 2)) + ((((v1180 + ((~(((v1182 ^ -1) | (-(v1182 ^ -1))) >> 31)) & 2)) - (v1183 + ((~(((v1184 ^ -1) | (-(v1184 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1190 = v1189[v1289];
        int v1290 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1)) & 3) * 2)) + ((((v1180 + ((~(((v1182 ^ -1) | (-(v1182 ^ -1))) >> 31)) & 2)) - (v1183 + ((~(((v1184 ^ -1) | (-(v1184 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1191 = v1189[v1290];
        int * v1192 = v1140->mem;
        int v1292 = v1188 * 2;
        v1192[v1292] = v1190;
        int * v1194 = v1140->mem;
        int v1295 = (v1188 * 2) + 1;
        v1194[v1295] = v1191;
        ;
      } else {
        ;
      }
      int * v1199 = v1140->mem;
      int v1300 = ((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1)) * 2;
      int v1200 = v1199[v1300];
      int v1301 = (((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1)) * 2) + 1;
      int v1201 = v1199[v1301];
      int * v1202 = v1140->cache_vals;
      int v1303 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1)) & 3) * 2)) + ((((v1180 + ((~(((v1182 ^ -1) | (-(v1182 ^ -1))) >> 31)) & 2)) - (v1183 + ((~(((v1184 ^ -1) | (-(v1184 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1202[v1303] = v1200;
      int * v1204 = v1140->cache_vals;
      int v1306 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1)) & 3) * 2)) + ((((v1180 + ((~(((v1182 ^ -1) | (-(v1182 ^ -1))) >> 31)) & 2)) - (v1183 + ((~(((v1184 ^ -1) | (-(v1184 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1204[v1306] = v1201;
      int * v1206 = v1140->cache_tags;
      int v1309 = (int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1);
      v1206[v1285] = v1309;
      int * v1208 = v1140->cache_dirty;
      v1208[v1285] = 0;
      int * v1210 = v1140->cache_age;
      v1210[v1285] = 1;
      int * v1212 = v1140->cache_age;
      int v1213 = v1212[v1285];
      int v1214 = v1212[v1260];
      int v1315 = v1214 + ((int)((unsigned int)(v1214 - v1213) >> 31));
      v1212[v1260] = v1315;
      int * v1216 = v1140->cache_age;
      int v1217 = v1216[v1261];
      int v1317 = v1217 + ((int)((unsigned int)(v1217 - v1213) >> 31));
      v1216[v1261] = v1317;
      int * v1219 = v1140->cache_age;
      v1219[v1285] = 0;
      v1222 = v1285;
    }
    int * v1223 = v1140->cache_vals;
    int v1320 = v1222 * 2;
    int v1224 = v1223[v1320];
    int v1321 = (v1222 * 2) + 1;
    int v1225 = v1223[v1321];
    int v1322 = (((((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1)) & 1) * 2) + ((((v1164 + ((~(((v1166 ^ -1) | (-(v1166 ^ -1))) >> 31)) & 2)) - (v1167 + ((~(((v1168 ^ -1) | (-(v1168 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1223[v1322] = v1224;
    int * v1227 = v1140->cache_vals;
    int v1325 = ((((((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1)) & 1) * 2) + ((((v1164 + ((~(((v1166 ^ -1) | (-(v1166 ^ -1))) >> 31)) & 2)) - (v1167 + ((~(((v1168 ^ -1) | (-(v1168 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1227[v1325] = v1225;
    int * v1229 = v1140->cache_tags;
    int v1328 = ((((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1)) & 1) * 2) + ((((v1164 + ((~(((v1166 ^ -1) | (-(v1166 ^ -1))) >> 31)) & 2)) - (v1167 + ((~(((v1168 ^ -1) | (-(v1168 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1329 = (int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1);
    v1229[v1328] = v1329;
    int * v1231 = v1140->cache_dirty;
    v1231[v1328] = 0;
    int * v1233 = v1140->cache_age;
    v1233[v1328] = 1;
    int * v1235 = v1140->cache_age;
    int v1236 = v1235[v1328];
    int v1237 = v1235[v1258];
    int v1335 = v1237 + ((int)((unsigned int)(v1237 - v1236) >> 31));
    v1235[v1258] = v1335;
    int * v1239 = v1140->cache_age;
    int v1240 = v1239[v1259];
    int v1337 = v1240 + ((int)((unsigned int)(v1240 - v1236) >> 31));
    v1239[v1259] = v1337;
    int * v1242 = v1140->cache_age;
    v1242[v1328] = 0;
    v1245 = v1328;
  }
  int v1340 = (v1245 * 2) + (((int)((unsigned int)v1146 >> 2)) & 1);
  int v1246 = v1152[v1340];
  int * v1247 = v1140->reg_ready;
  int v1342 = ((v1144 + ((v1141 - v1144) & (~((v1141 - v1144) >> 31)))) + 1) + ((100 ^ (((~(((v1150 ^ ((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1))) | (-(v1150 ^ ((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1))))) >> 31)) | (~(((v1151 ^ ((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1))) | (-(v1151 ^ ((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1148 ^ ((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1))) | (-(v1148 ^ ((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1))))) >> 31)) | (~(((v1149 ^ ((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1))) | (-(v1149 ^ ((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1150 ^ ((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1))) | (-(v1150 ^ ((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1))))) >> 31)) | (~(((v1151 ^ ((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1))) | (-(v1151 ^ ((int)((unsigned int)((int)((unsigned int)v1146 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1247[10] = v1342;
  int * v1249 = v1140->regs;
  v1249[10] = v1246;
  struct StateT * v1251 = slot_23(v1140);
  return v1251;
}

struct StateT * slot_31(struct StateT * v2203) {
  int v2204 = v2203->timer;
  int v2215 = v2204 + 1;
  v2203->timer = v2215;
  int * v2206 = v2203->reg_ready;
  int v2207 = v2206[10];
  int * v2208 = v2203->regs;
  int v2209 = v2208[10];
  int v2219 = (v2207 + ((v2204 - v2207) & (~((v2204 - v2207) >> 31)))) + 1;
  v2206[10] = v2219;
  int * v2211 = v2203->regs;
  int v2221 = (int)((unsigned int)v2209 >> 26);
  v2211[10] = v2221;
  struct StateT * v2213 = slot_33(v2203);
  return v2213;
}

struct StateT * slot_3(struct StateT * v240) {
  int * v241 = v240->regs;
  int v242 = v241[10];
  bool v353 = v242 == 0;
  struct StateT * v349;
  if (v353) {
    int v243 = v240->timer;
    int v354 = v243 + 15;
    v240->timer = v354;
    int * v245 = v240->saved_regs;
    int v246 = v245[11];
    int * v247 = v240->regs;
    v247[11] = v246;
    int * v249 = v240->reg_ready;
    int v250 = v240->timer;
    v249[0] = v250;
    int * v252 = v240->reg_ready;
    int v253 = v240->timer;
    v252[1] = v253;
    int * v255 = v240->reg_ready;
    int v256 = v240->timer;
    v255[2] = v256;
    int * v258 = v240->reg_ready;
    int v259 = v240->timer;
    v258[3] = v259;
    int * v261 = v240->reg_ready;
    int v262 = v240->timer;
    v261[4] = v262;
    int * v264 = v240->reg_ready;
    int v265 = v240->timer;
    v264[5] = v265;
    int * v267 = v240->reg_ready;
    int v268 = v240->timer;
    v267[6] = v268;
    int * v270 = v240->reg_ready;
    int v271 = v240->timer;
    v270[7] = v271;
    int * v273 = v240->reg_ready;
    int v274 = v240->timer;
    v273[8] = v274;
    int * v276 = v240->reg_ready;
    int v277 = v240->timer;
    v276[9] = v277;
    int * v279 = v240->reg_ready;
    int v280 = v240->timer;
    v279[10] = v280;
    int * v282 = v240->reg_ready;
    int v283 = v240->timer;
    v282[11] = v283;
    int * v285 = v240->reg_ready;
    int v286 = v240->timer;
    v285[12] = v286;
    int * v288 = v240->reg_ready;
    int v289 = v240->timer;
    v288[13] = v289;
    int * v291 = v240->reg_ready;
    int v292 = v240->timer;
    v291[14] = v292;
    int * v294 = v240->reg_ready;
    int v295 = v240->timer;
    v294[15] = v295;
    int * v297 = v240->reg_ready;
    int v298 = v240->timer;
    v297[16] = v298;
    int * v300 = v240->reg_ready;
    int v301 = v240->timer;
    v300[17] = v301;
    int * v303 = v240->reg_ready;
    int v304 = v240->timer;
    v303[18] = v304;
    int * v306 = v240->reg_ready;
    int v307 = v240->timer;
    v306[19] = v307;
    int * v309 = v240->reg_ready;
    int v310 = v240->timer;
    v309[20] = v310;
    int * v312 = v240->reg_ready;
    int v313 = v240->timer;
    v312[21] = v313;
    int * v315 = v240->reg_ready;
    int v316 = v240->timer;
    v315[22] = v316;
    int * v318 = v240->reg_ready;
    int v319 = v240->timer;
    v318[23] = v319;
    int * v321 = v240->reg_ready;
    int v322 = v240->timer;
    v321[24] = v322;
    int * v324 = v240->reg_ready;
    int v325 = v240->timer;
    v324[25] = v325;
    int * v327 = v240->reg_ready;
    int v328 = v240->timer;
    v327[26] = v328;
    int * v330 = v240->reg_ready;
    int v331 = v240->timer;
    v330[27] = v331;
    int * v333 = v240->reg_ready;
    int v334 = v240->timer;
    v333[28] = v334;
    int * v336 = v240->reg_ready;
    int v337 = v240->timer;
    v336[29] = v337;
    int * v339 = v240->reg_ready;
    int v340 = v240->timer;
    v339[30] = v340;
    int * v342 = v240->reg_ready;
    int v343 = v240->timer;
    v342[31] = v343;
    struct StateT * v345 = slot_4(v240);
    v349 = v345;
  } else {
    struct StateT * v347 = slot_5(v240);
    v349 = v347;
  }
  return v349;
}

struct StateT * slot_26(struct StateT * v1615) {
  int v1616 = v1615->timer;
  int v1728 = v1616 + 1;
  v1615->timer = v1728;
  int * v1618 = v1615->reg_ready;
  int v1619 = v1618[12];
  int * v1620 = v1615->regs;
  int v1621 = v1620[12];
  int * v1622 = v1615->cache_tags;
  int v1733 = (((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1623 = v1622[v1733];
  int v1734 = ((((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1624 = v1622[v1734];
  int v1735 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1625 = v1622[v1735];
  int v1736 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1626 = v1622[v1736];
  int * v1627 = v1615->cache_vals;
  bool v1737 = !(((~(((v1623 ^ ((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1))) | (-(v1623 ^ ((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1624 ^ ((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1))) | (-(v1624 ^ ((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1720;
  if (v1737) {
    int * v1628 = v1615->cache_age;
    int v1739 = ((((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1624 ^ ((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1))) | (-(v1624 ^ ((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1629 = v1628[v1739];
    int v1630 = v1628[v1733];
    int v1740 = v1630 + ((int)((unsigned int)(v1630 - v1629) >> 31));
    v1628[v1733] = v1740;
    int * v1632 = v1615->cache_age;
    int v1633 = v1632[v1734];
    int v1742 = v1633 + ((int)((unsigned int)(v1633 - v1629) >> 31));
    v1632[v1734] = v1742;
    int * v1635 = v1615->cache_age;
    v1635[v1739] = 0;
    v1720 = v1739;
  } else {
    int * v1638 = v1615->cache_age;
    int v1746 = (((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1639 = v1638[v1746];
    int * v1640 = v1615->cache_tags;
    int v1641 = v1640[v1746];
    int v1642 = v1638[v1734];
    int v1643 = v1640[v1734];
    bool v1748 = !(((~(((v1625 ^ ((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1))) | (-(v1625 ^ ((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1626 ^ ((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1))) | (-(v1626 ^ ((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1697;
    if (v1748) {
      int * v1644 = v1615->cache_age;
      int v1750 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1626 ^ ((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1))) | (-(v1626 ^ ((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1645 = v1644[v1750];
      int v1646 = v1644[v1735];
      int v1751 = v1646 + ((int)((unsigned int)(v1646 - v1645) >> 31));
      v1644[v1735] = v1751;
      int * v1648 = v1615->cache_age;
      int v1649 = v1648[v1736];
      int v1753 = v1649 + ((int)((unsigned int)(v1649 - v1645) >> 31));
      v1648[v1736] = v1753;
      int * v1651 = v1615->cache_age;
      v1651[v1750] = 0;
      v1697 = v1750;
    } else {
      int * v1654 = v1615->cache_age;
      int v1757 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1655 = v1654[v1757];
      int * v1656 = v1615->cache_tags;
      int v1657 = v1656[v1757];
      int v1658 = v1654[v1736];
      int v1659 = v1656[v1736];
      int * v1660 = v1615->cache_dirty;
      int v1760 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1655 + ((~(((v1657 ^ -1) | (-(v1657 ^ -1))) >> 31)) & 2)) - (v1658 + ((~(((v1659 ^ -1) | (-(v1659 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1661 = v1660[v1760];
      bool v1761 = !(v1661 == 0);
      if (v1761) {
        int * v1662 = v1615->cache_tags;
        int v1663 = v1662[v1760];
        int * v1664 = v1615->cache_vals;
        int v1764 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1655 + ((~(((v1657 ^ -1) | (-(v1657 ^ -1))) >> 31)) & 2)) - (v1658 + ((~(((v1659 ^ -1) | (-(v1659 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1665 = v1664[v1764];
        int v1765 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1655 + ((~(((v1657 ^ -1) | (-(v1657 ^ -1))) >> 31)) & 2)) - (v1658 + ((~(((v1659 ^ -1) | (-(v1659 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1666 = v1664[v1765];
        int * v1667 = v1615->mem;
        int v1767 = v1663 * 2;
        v1667[v1767] = v1665;
        int * v1669 = v1615->mem;
        int v1770 = (v1663 * 2) + 1;
        v1669[v1770] = v1666;
        ;
      } else {
        ;
      }
      int * v1674 = v1615->mem;
      int v1775 = ((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1)) * 2;
      int v1675 = v1674[v1775];
      int v1776 = (((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1676 = v1674[v1776];
      int * v1677 = v1615->cache_vals;
      int v1778 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1655 + ((~(((v1657 ^ -1) | (-(v1657 ^ -1))) >> 31)) & 2)) - (v1658 + ((~(((v1659 ^ -1) | (-(v1659 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1677[v1778] = v1675;
      int * v1679 = v1615->cache_vals;
      int v1781 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1655 + ((~(((v1657 ^ -1) | (-(v1657 ^ -1))) >> 31)) & 2)) - (v1658 + ((~(((v1659 ^ -1) | (-(v1659 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1679[v1781] = v1676;
      int * v1681 = v1615->cache_tags;
      int v1784 = (int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1);
      v1681[v1760] = v1784;
      int * v1683 = v1615->cache_dirty;
      v1683[v1760] = 0;
      int * v1685 = v1615->cache_age;
      v1685[v1760] = 1;
      int * v1687 = v1615->cache_age;
      int v1688 = v1687[v1760];
      int v1689 = v1687[v1735];
      int v1790 = v1689 + ((int)((unsigned int)(v1689 - v1688) >> 31));
      v1687[v1735] = v1790;
      int * v1691 = v1615->cache_age;
      int v1692 = v1691[v1736];
      int v1792 = v1692 + ((int)((unsigned int)(v1692 - v1688) >> 31));
      v1691[v1736] = v1792;
      int * v1694 = v1615->cache_age;
      v1694[v1760] = 0;
      v1697 = v1760;
    }
    int * v1698 = v1615->cache_vals;
    int v1795 = v1697 * 2;
    int v1699 = v1698[v1795];
    int v1796 = (v1697 * 2) + 1;
    int v1700 = v1698[v1796];
    int v1797 = (((((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1639 + ((~(((v1641 ^ -1) | (-(v1641 ^ -1))) >> 31)) & 2)) - (v1642 + ((~(((v1643 ^ -1) | (-(v1643 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1698[v1797] = v1699;
    int * v1702 = v1615->cache_vals;
    int v1800 = ((((((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1639 + ((~(((v1641 ^ -1) | (-(v1641 ^ -1))) >> 31)) & 2)) - (v1642 + ((~(((v1643 ^ -1) | (-(v1643 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1702[v1800] = v1700;
    int * v1704 = v1615->cache_tags;
    int v1803 = ((((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1639 + ((~(((v1641 ^ -1) | (-(v1641 ^ -1))) >> 31)) & 2)) - (v1642 + ((~(((v1643 ^ -1) | (-(v1643 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1804 = (int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1);
    v1704[v1803] = v1804;
    int * v1706 = v1615->cache_dirty;
    v1706[v1803] = 0;
    int * v1708 = v1615->cache_age;
    v1708[v1803] = 1;
    int * v1710 = v1615->cache_age;
    int v1711 = v1710[v1803];
    int v1712 = v1710[v1733];
    int v1810 = v1712 + ((int)((unsigned int)(v1712 - v1711) >> 31));
    v1710[v1733] = v1810;
    int * v1714 = v1615->cache_age;
    int v1715 = v1714[v1734];
    int v1812 = v1715 + ((int)((unsigned int)(v1715 - v1711) >> 31));
    v1714[v1734] = v1812;
    int * v1717 = v1615->cache_age;
    v1717[v1803] = 0;
    v1720 = v1803;
  }
  int v1815 = (v1720 * 2) + (((int)((unsigned int)(v1621 + 68) >> 2)) & 1);
  int v1721 = v1627[v1815];
  int * v1722 = v1615->reg_ready;
  int v1818 = ((v1619 + ((v1616 - v1619) & (~((v1616 - v1619) >> 31)))) + 1) + ((100 ^ (((~(((v1625 ^ ((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1))) | (-(v1625 ^ ((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1626 ^ ((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1))) | (-(v1626 ^ ((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1623 ^ ((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1))) | (-(v1623 ^ ((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1624 ^ ((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1))) | (-(v1624 ^ ((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1625 ^ ((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1))) | (-(v1625 ^ ((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1626 ^ ((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1))) | (-(v1626 ^ ((int)((unsigned int)((int)((unsigned int)(v1621 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1722[11] = v1818;
  int * v1724 = v1615->regs;
  v1724[11] = v1721;
  struct StateT * v1726 = slot_28(v1615);
  return v1726;
}

struct StateT * slot_1(struct StateT * v10) {
  int * v11 = v10->saved_regs;
  int * v12 = v10->regs;
  int v13 = v12[11];
  v11[11] = v13;
  int v15 = v10->timer;
  int v27 = v15 + 1;
  v10->timer = v27;
  int * v17 = v10->reg_ready;
  v17[11] = v27;
  int * v19 = v10->regs;
  v19[11] = 0;
  struct StateT * v21 = slot_2(v10);
  return v21;
}

struct StateT * slot_13(struct StateT * v819) {
  int v820 = v819->timer;
  int v833 = v820 + 1;
  v819->timer = v833;
  int * v822 = v819->reg_ready;
  int v823 = v822[11];
  int * v824 = v819->regs;
  int v825 = v824[11];
  int v826 = v822[10];
  int v827 = v824[10];
  int v838 = (v826 + (((v823 + ((v820 - v823) & (~((v820 - v823) >> 31)))) - v826) & (~(((v823 + ((v820 - v823) & (~((v820 - v823) >> 31)))) - v826) >> 31)))) + 1;
  v822[10] = v838;
  int * v829 = v819->regs;
  int v840 = v825 + v827;
  v829[10] = v840;
  struct StateT * v831 = slot_15(v819);
  return v831;
}

struct StateT * slot_38(struct StateT * v2692) {
  int v2693 = v2692->timer;
  int v2866 = v2693 + 1;
  v2692->timer = v2866;
  int * v2695 = v2692->reg_ready;
  int * v2697 = v2692->regs;
  int v2698 = v2697[12];
  int v2700 = v2697[10];
  int * v2701 = v2692->cache_tags;
  int v2872 = (((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1)) & 1) * 2;
  int v2702 = v2701[v2872];
  int v2873 = ((((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2703 = v2701[v2873];
  int v2874 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1)) & 3) * 2);
  int v2704 = v2701[v2874];
  int v2875 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2705 = v2701[v2875];
  int v2706 = v2692->timer;
  int v2876 = v2706 + ((100 ^ (((~(((v2704 ^ ((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1))) | (-(v2704 ^ ((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2705 ^ ((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1))) | (-(v2705 ^ ((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2702 ^ ((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1))) | (-(v2702 ^ ((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2703 ^ ((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1))) | (-(v2703 ^ ((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2704 ^ ((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1))) | (-(v2704 ^ ((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2705 ^ ((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1))) | (-(v2705 ^ ((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2692->timer = v2876;
  bool v2877 = !(((~(((v2702 ^ ((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1))) | (-(v2702 ^ ((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2703 ^ ((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1))) | (-(v2703 ^ ((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v2800;
  if (v2877) {
    int * v2708 = v2692->cache_age;
    int v2879 = ((((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v2703 ^ ((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1))) | (-(v2703 ^ ((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v2709 = v2708[v2879];
    int v2710 = v2708[v2872];
    int v2880 = v2710 + ((int)((unsigned int)(v2710 - v2709) >> 31));
    v2708[v2872] = v2880;
    int * v2712 = v2692->cache_age;
    int v2713 = v2712[v2873];
    int v2882 = v2713 + ((int)((unsigned int)(v2713 - v2709) >> 31));
    v2712[v2873] = v2882;
    int * v2715 = v2692->cache_age;
    v2715[v2879] = 0;
    v2800 = v2879;
  } else {
    int * v2718 = v2692->cache_age;
    int v2886 = (((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1)) & 1) * 2;
    int v2719 = v2718[v2886];
    int * v2720 = v2692->cache_tags;
    int v2721 = v2720[v2886];
    int v2722 = v2718[v2873];
    int v2723 = v2720[v2873];
    bool v2888 = !(((~(((v2704 ^ ((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1))) | (-(v2704 ^ ((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2705 ^ ((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1))) | (-(v2705 ^ ((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v2777;
    if (v2888) {
      int * v2724 = v2692->cache_age;
      int v2890 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2705 ^ ((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1))) | (-(v2705 ^ ((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v2725 = v2724[v2890];
      int v2726 = v2724[v2874];
      int v2891 = v2726 + ((int)((unsigned int)(v2726 - v2725) >> 31));
      v2724[v2874] = v2891;
      int * v2728 = v2692->cache_age;
      int v2729 = v2728[v2875];
      int v2893 = v2729 + ((int)((unsigned int)(v2729 - v2725) >> 31));
      v2728[v2875] = v2893;
      int * v2731 = v2692->cache_age;
      v2731[v2890] = 0;
      v2777 = v2890;
    } else {
      int * v2734 = v2692->cache_age;
      int v2897 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1)) & 3) * 2);
      int v2735 = v2734[v2897];
      int * v2736 = v2692->cache_tags;
      int v2737 = v2736[v2897];
      int v2738 = v2734[v2875];
      int v2739 = v2736[v2875];
      int * v2740 = v2692->cache_dirty;
      int v2900 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2735 + ((~(((v2737 ^ -1) | (-(v2737 ^ -1))) >> 31)) & 2)) - (v2738 + ((~(((v2739 ^ -1) | (-(v2739 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2741 = v2740[v2900];
      bool v2901 = !(v2741 == 0);
      if (v2901) {
        int * v2742 = v2692->cache_tags;
        int v2743 = v2742[v2900];
        int * v2744 = v2692->cache_vals;
        int v2904 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2735 + ((~(((v2737 ^ -1) | (-(v2737 ^ -1))) >> 31)) & 2)) - (v2738 + ((~(((v2739 ^ -1) | (-(v2739 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2745 = v2744[v2904];
        int v2905 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2735 + ((~(((v2737 ^ -1) | (-(v2737 ^ -1))) >> 31)) & 2)) - (v2738 + ((~(((v2739 ^ -1) | (-(v2739 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2746 = v2744[v2905];
        int * v2747 = v2692->mem;
        int v2907 = v2743 * 2;
        v2747[v2907] = v2745;
        int * v2749 = v2692->mem;
        int v2910 = (v2743 * 2) + 1;
        v2749[v2910] = v2746;
        ;
      } else {
        ;
      }
      int * v2754 = v2692->mem;
      int v2915 = ((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1)) * 2;
      int v2755 = v2754[v2915];
      int v2916 = (((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1)) * 2) + 1;
      int v2756 = v2754[v2916];
      int * v2757 = v2692->cache_vals;
      int v2918 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2735 + ((~(((v2737 ^ -1) | (-(v2737 ^ -1))) >> 31)) & 2)) - (v2738 + ((~(((v2739 ^ -1) | (-(v2739 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2757[v2918] = v2755;
      int * v2759 = v2692->cache_vals;
      int v2921 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2735 + ((~(((v2737 ^ -1) | (-(v2737 ^ -1))) >> 31)) & 2)) - (v2738 + ((~(((v2739 ^ -1) | (-(v2739 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2759[v2921] = v2756;
      int * v2761 = v2692->cache_tags;
      int v2924 = (int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1);
      v2761[v2900] = v2924;
      int * v2763 = v2692->cache_dirty;
      v2763[v2900] = 0;
      int * v2765 = v2692->cache_age;
      v2765[v2900] = 1;
      int * v2767 = v2692->cache_age;
      int v2768 = v2767[v2900];
      int v2769 = v2767[v2874];
      int v2930 = v2769 + ((int)((unsigned int)(v2769 - v2768) >> 31));
      v2767[v2874] = v2930;
      int * v2771 = v2692->cache_age;
      int v2772 = v2771[v2875];
      int v2932 = v2772 + ((int)((unsigned int)(v2772 - v2768) >> 31));
      v2771[v2875] = v2932;
      int * v2774 = v2692->cache_age;
      v2774[v2900] = 0;
      v2777 = v2900;
    }
    int * v2778 = v2692->cache_vals;
    int v2935 = v2777 * 2;
    int v2779 = v2778[v2935];
    int v2936 = (v2777 * 2) + 1;
    int v2780 = v2778[v2936];
    int v2937 = (((((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v2719 + ((~(((v2721 ^ -1) | (-(v2721 ^ -1))) >> 31)) & 2)) - (v2722 + ((~(((v2723 ^ -1) | (-(v2723 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2778[v2937] = v2779;
    int * v2782 = v2692->cache_vals;
    int v2940 = ((((((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v2719 + ((~(((v2721 ^ -1) | (-(v2721 ^ -1))) >> 31)) & 2)) - (v2722 + ((~(((v2723 ^ -1) | (-(v2723 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2782[v2940] = v2780;
    int * v2784 = v2692->cache_tags;
    int v2943 = ((((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v2719 + ((~(((v2721 ^ -1) | (-(v2721 ^ -1))) >> 31)) & 2)) - (v2722 + ((~(((v2723 ^ -1) | (-(v2723 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2944 = (int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1);
    v2784[v2943] = v2944;
    int * v2786 = v2692->cache_dirty;
    v2786[v2943] = 0;
    int * v2788 = v2692->cache_age;
    v2788[v2943] = 1;
    int * v2790 = v2692->cache_age;
    int v2791 = v2790[v2943];
    int v2792 = v2790[v2872];
    int v2950 = v2792 + ((int)((unsigned int)(v2792 - v2791) >> 31));
    v2790[v2872] = v2950;
    int * v2794 = v2692->cache_age;
    int v2795 = v2794[v2873];
    int v2952 = v2795 + ((int)((unsigned int)(v2795 - v2791) >> 31));
    v2794[v2873] = v2952;
    int * v2797 = v2692->cache_age;
    v2797[v2943] = 0;
    v2800 = v2943;
  }
  int * v2801 = v2692->cache_vals;
  int v2955 = (v2800 * 2) + (((int)((unsigned int)(v2698 + 68) >> 2)) & 1);
  v2801[v2955] = v2700;
  int * v2803 = v2692->cache_tags;
  int v2804 = v2803[v2874];
  int v2805 = v2803[v2875];
  bool v2958 = !(((~(((v2804 ^ ((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1))) | (-(v2804 ^ ((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2805 ^ ((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1))) | (-(v2805 ^ ((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v2859;
  if (v2958) {
    int * v2806 = v2692->cache_age;
    int v2960 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2805 ^ ((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1))) | (-(v2805 ^ ((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v2807 = v2806[v2960];
    int v2808 = v2806[v2874];
    int v2961 = v2808 + ((int)((unsigned int)(v2808 - v2807) >> 31));
    v2806[v2874] = v2961;
    int * v2810 = v2692->cache_age;
    int v2811 = v2810[v2875];
    int v2963 = v2811 + ((int)((unsigned int)(v2811 - v2807) >> 31));
    v2810[v2875] = v2963;
    int * v2813 = v2692->cache_age;
    v2813[v2960] = 0;
    v2859 = v2960;
  } else {
    int * v2816 = v2692->cache_age;
    int v2967 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1)) & 3) * 2);
    int v2817 = v2816[v2967];
    int * v2818 = v2692->cache_tags;
    int v2819 = v2818[v2967];
    int v2820 = v2816[v2875];
    int v2821 = v2818[v2875];
    int * v2822 = v2692->cache_dirty;
    int v2970 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2817 + ((~(((v2819 ^ -1) | (-(v2819 ^ -1))) >> 31)) & 2)) - (v2820 + ((~(((v2821 ^ -1) | (-(v2821 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2823 = v2822[v2970];
    bool v2971 = !(v2823 == 0);
    if (v2971) {
      int * v2824 = v2692->cache_tags;
      int v2825 = v2824[v2970];
      int * v2826 = v2692->cache_vals;
      int v2974 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2817 + ((~(((v2819 ^ -1) | (-(v2819 ^ -1))) >> 31)) & 2)) - (v2820 + ((~(((v2821 ^ -1) | (-(v2821 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v2827 = v2826[v2974];
      int v2975 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2817 + ((~(((v2819 ^ -1) | (-(v2819 ^ -1))) >> 31)) & 2)) - (v2820 + ((~(((v2821 ^ -1) | (-(v2821 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v2828 = v2826[v2975];
      int * v2829 = v2692->mem;
      int v2977 = v2825 * 2;
      v2829[v2977] = v2827;
      int * v2831 = v2692->mem;
      int v2980 = (v2825 * 2) + 1;
      v2831[v2980] = v2828;
      ;
    } else {
      ;
    }
    int * v2836 = v2692->mem;
    int v2985 = ((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1)) * 2;
    int v2837 = v2836[v2985];
    int v2986 = (((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1)) * 2) + 1;
    int v2838 = v2836[v2986];
    int * v2839 = v2692->cache_vals;
    int v2988 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2817 + ((~(((v2819 ^ -1) | (-(v2819 ^ -1))) >> 31)) & 2)) - (v2820 + ((~(((v2821 ^ -1) | (-(v2821 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2839[v2988] = v2837;
    int * v2841 = v2692->cache_vals;
    int v2991 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2817 + ((~(((v2819 ^ -1) | (-(v2819 ^ -1))) >> 31)) & 2)) - (v2820 + ((~(((v2821 ^ -1) | (-(v2821 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2841[v2991] = v2838;
    int * v2843 = v2692->cache_tags;
    int v2994 = (int)((unsigned int)((int)((unsigned int)(v2698 + 68) >> 2)) >> 1);
    v2843[v2970] = v2994;
    int * v2845 = v2692->cache_dirty;
    v2845[v2970] = 0;
    int * v2847 = v2692->cache_age;
    v2847[v2970] = 1;
    int * v2849 = v2692->cache_age;
    int v2850 = v2849[v2970];
    int v2851 = v2849[v2874];
    int v3000 = v2851 + ((int)((unsigned int)(v2851 - v2850) >> 31));
    v2849[v2874] = v3000;
    int * v2853 = v2692->cache_age;
    int v2854 = v2853[v2875];
    int v3002 = v2854 + ((int)((unsigned int)(v2854 - v2850) >> 31));
    v2853[v2875] = v3002;
    int * v2856 = v2692->cache_age;
    v2856[v2970] = 0;
    v2859 = v2970;
  }
  int * v2860 = v2692->cache_vals;
  int v3005 = (v2859 * 2) + (((int)((unsigned int)(v2698 + 68) >> 2)) & 1);
  v2860[v3005] = v2700;
  int * v2862 = v2692->cache_dirty;
  v2862[v2859] = 1;
  struct StateT * v2864 = slot_32(v2692);
  return v2864;
}

struct StateT * slot_24(struct StateT * v1387) {
  int v1388 = v1387->timer;
  int v1500 = v1388 + 1;
  v1387->timer = v1500;
  int * v1390 = v1387->reg_ready;
  int v1391 = v1390[10];
  int * v1392 = v1387->regs;
  int v1393 = v1392[10];
  int * v1394 = v1387->cache_tags;
  int v1505 = (((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1)) & 1) * 2;
  int v1395 = v1394[v1505];
  int v1506 = ((((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1396 = v1394[v1506];
  int v1507 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1)) & 3) * 2);
  int v1397 = v1394[v1507];
  int v1508 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1398 = v1394[v1508];
  int * v1399 = v1387->cache_vals;
  bool v1509 = !(((~(((v1395 ^ ((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1))) | (-(v1395 ^ ((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1))))) >> 31)) | (~(((v1396 ^ ((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1))) | (-(v1396 ^ ((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1))))) >> 31))) == 0);
  int v1492;
  if (v1509) {
    int * v1400 = v1387->cache_age;
    int v1511 = ((((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1)) & 1) * 2) + ((~(((v1396 ^ ((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1))) | (-(v1396 ^ ((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1))))) >> 31)) & 1);
    int v1401 = v1400[v1511];
    int v1402 = v1400[v1505];
    int v1512 = v1402 + ((int)((unsigned int)(v1402 - v1401) >> 31));
    v1400[v1505] = v1512;
    int * v1404 = v1387->cache_age;
    int v1405 = v1404[v1506];
    int v1514 = v1405 + ((int)((unsigned int)(v1405 - v1401) >> 31));
    v1404[v1506] = v1514;
    int * v1407 = v1387->cache_age;
    v1407[v1511] = 0;
    v1492 = v1511;
  } else {
    int * v1410 = v1387->cache_age;
    int v1518 = (((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1)) & 1) * 2;
    int v1411 = v1410[v1518];
    int * v1412 = v1387->cache_tags;
    int v1413 = v1412[v1518];
    int v1414 = v1410[v1506];
    int v1415 = v1412[v1506];
    bool v1520 = !(((~(((v1397 ^ ((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1))) | (-(v1397 ^ ((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1))))) >> 31)) | (~(((v1398 ^ ((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1))) | (-(v1398 ^ ((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1))))) >> 31))) == 0);
    int v1469;
    if (v1520) {
      int * v1416 = v1387->cache_age;
      int v1522 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1398 ^ ((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1))) | (-(v1398 ^ ((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1))))) >> 31)) & 1);
      int v1417 = v1416[v1522];
      int v1418 = v1416[v1507];
      int v1523 = v1418 + ((int)((unsigned int)(v1418 - v1417) >> 31));
      v1416[v1507] = v1523;
      int * v1420 = v1387->cache_age;
      int v1421 = v1420[v1508];
      int v1525 = v1421 + ((int)((unsigned int)(v1421 - v1417) >> 31));
      v1420[v1508] = v1525;
      int * v1423 = v1387->cache_age;
      v1423[v1522] = 0;
      v1469 = v1522;
    } else {
      int * v1426 = v1387->cache_age;
      int v1529 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1)) & 3) * 2);
      int v1427 = v1426[v1529];
      int * v1428 = v1387->cache_tags;
      int v1429 = v1428[v1529];
      int v1430 = v1426[v1508];
      int v1431 = v1428[v1508];
      int * v1432 = v1387->cache_dirty;
      int v1532 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1)) & 3) * 2)) + ((((v1427 + ((~(((v1429 ^ -1) | (-(v1429 ^ -1))) >> 31)) & 2)) - (v1430 + ((~(((v1431 ^ -1) | (-(v1431 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1433 = v1432[v1532];
      bool v1533 = !(v1433 == 0);
      if (v1533) {
        int * v1434 = v1387->cache_tags;
        int v1435 = v1434[v1532];
        int * v1436 = v1387->cache_vals;
        int v1536 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1)) & 3) * 2)) + ((((v1427 + ((~(((v1429 ^ -1) | (-(v1429 ^ -1))) >> 31)) & 2)) - (v1430 + ((~(((v1431 ^ -1) | (-(v1431 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1437 = v1436[v1536];
        int v1537 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1)) & 3) * 2)) + ((((v1427 + ((~(((v1429 ^ -1) | (-(v1429 ^ -1))) >> 31)) & 2)) - (v1430 + ((~(((v1431 ^ -1) | (-(v1431 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1438 = v1436[v1537];
        int * v1439 = v1387->mem;
        int v1539 = v1435 * 2;
        v1439[v1539] = v1437;
        int * v1441 = v1387->mem;
        int v1542 = (v1435 * 2) + 1;
        v1441[v1542] = v1438;
        ;
      } else {
        ;
      }
      int * v1446 = v1387->mem;
      int v1547 = ((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1)) * 2;
      int v1447 = v1446[v1547];
      int v1548 = (((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1)) * 2) + 1;
      int v1448 = v1446[v1548];
      int * v1449 = v1387->cache_vals;
      int v1550 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1)) & 3) * 2)) + ((((v1427 + ((~(((v1429 ^ -1) | (-(v1429 ^ -1))) >> 31)) & 2)) - (v1430 + ((~(((v1431 ^ -1) | (-(v1431 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1449[v1550] = v1447;
      int * v1451 = v1387->cache_vals;
      int v1553 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1)) & 3) * 2)) + ((((v1427 + ((~(((v1429 ^ -1) | (-(v1429 ^ -1))) >> 31)) & 2)) - (v1430 + ((~(((v1431 ^ -1) | (-(v1431 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1451[v1553] = v1448;
      int * v1453 = v1387->cache_tags;
      int v1556 = (int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1);
      v1453[v1532] = v1556;
      int * v1455 = v1387->cache_dirty;
      v1455[v1532] = 0;
      int * v1457 = v1387->cache_age;
      v1457[v1532] = 1;
      int * v1459 = v1387->cache_age;
      int v1460 = v1459[v1532];
      int v1461 = v1459[v1507];
      int v1562 = v1461 + ((int)((unsigned int)(v1461 - v1460) >> 31));
      v1459[v1507] = v1562;
      int * v1463 = v1387->cache_age;
      int v1464 = v1463[v1508];
      int v1564 = v1464 + ((int)((unsigned int)(v1464 - v1460) >> 31));
      v1463[v1508] = v1564;
      int * v1466 = v1387->cache_age;
      v1466[v1532] = 0;
      v1469 = v1532;
    }
    int * v1470 = v1387->cache_vals;
    int v1567 = v1469 * 2;
    int v1471 = v1470[v1567];
    int v1568 = (v1469 * 2) + 1;
    int v1472 = v1470[v1568];
    int v1569 = (((((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1)) & 1) * 2) + ((((v1411 + ((~(((v1413 ^ -1) | (-(v1413 ^ -1))) >> 31)) & 2)) - (v1414 + ((~(((v1415 ^ -1) | (-(v1415 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1470[v1569] = v1471;
    int * v1474 = v1387->cache_vals;
    int v1572 = ((((((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1)) & 1) * 2) + ((((v1411 + ((~(((v1413 ^ -1) | (-(v1413 ^ -1))) >> 31)) & 2)) - (v1414 + ((~(((v1415 ^ -1) | (-(v1415 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1474[v1572] = v1472;
    int * v1476 = v1387->cache_tags;
    int v1575 = ((((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1)) & 1) * 2) + ((((v1411 + ((~(((v1413 ^ -1) | (-(v1413 ^ -1))) >> 31)) & 2)) - (v1414 + ((~(((v1415 ^ -1) | (-(v1415 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1576 = (int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1);
    v1476[v1575] = v1576;
    int * v1478 = v1387->cache_dirty;
    v1478[v1575] = 0;
    int * v1480 = v1387->cache_age;
    v1480[v1575] = 1;
    int * v1482 = v1387->cache_age;
    int v1483 = v1482[v1575];
    int v1484 = v1482[v1505];
    int v1582 = v1484 + ((int)((unsigned int)(v1484 - v1483) >> 31));
    v1482[v1505] = v1582;
    int * v1486 = v1387->cache_age;
    int v1487 = v1486[v1506];
    int v1584 = v1487 + ((int)((unsigned int)(v1487 - v1483) >> 31));
    v1486[v1506] = v1584;
    int * v1489 = v1387->cache_age;
    v1489[v1575] = 0;
    v1492 = v1575;
  }
  int v1587 = (v1492 * 2) + (((int)((unsigned int)v1393 >> 2)) & 1);
  int v1493 = v1399[v1587];
  int * v1494 = v1387->reg_ready;
  int v1589 = ((v1391 + ((v1388 - v1391) & (~((v1388 - v1391) >> 31)))) + 1) + ((100 ^ (((~(((v1397 ^ ((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1))) | (-(v1397 ^ ((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1))))) >> 31)) | (~(((v1398 ^ ((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1))) | (-(v1398 ^ ((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1395 ^ ((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1))) | (-(v1395 ^ ((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1))))) >> 31)) | (~(((v1396 ^ ((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1))) | (-(v1396 ^ ((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1397 ^ ((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1))) | (-(v1397 ^ ((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1))))) >> 31)) | (~(((v1398 ^ ((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1))) | (-(v1398 ^ ((int)((unsigned int)((int)((unsigned int)v1393 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1494[10] = v1589;
  int * v1496 = v1387->regs;
  v1496[10] = v1493;
  struct StateT * v1498 = slot_26(v1387);
  return v1498;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v7 = v3 + 1;
  v2->timer = v7;
  struct StateT * v5 = slot_1(v2);
  return v5;
}

struct StateT * slot_14(struct StateT * v843) {
  int v844 = v843->timer;
  int v852 = v844 + 1;
  v843->timer = v852;
  int * v846 = v843->reg_ready;
  v846[12] = v852;
  int * v848 = v843->regs;
  v848[12] = 0;
  struct StateT * v850 = slot_29(v843);
  return v850;
}

struct StateT * slot_28(struct StateT * v1839) {
  int v1840 = v1839->timer;
  int v1853 = v1840 + 1;
  v1839->timer = v1853;
  int * v1842 = v1839->reg_ready;
  int v1843 = v1842[11];
  int * v1844 = v1839->regs;
  int v1845 = v1844[11];
  int v1846 = v1842[10];
  int v1847 = v1844[10];
  int v1858 = (v1846 + (((v1843 + ((v1840 - v1843) & (~((v1840 - v1843) >> 31)))) - v1846) & (~(((v1843 + ((v1840 - v1843) & (~((v1840 - v1843) >> 31)))) - v1846) >> 31)))) + 1;
  v1842[10] = v1858;
  int * v1849 = v1839->regs;
  int v1860 = v1845 & v1847;
  v1849[10] = v1860;
  struct StateT * v1851 = slot_38(v1839);
  return v1851;
}

struct StateT * slot_32(struct StateT * v2224) {
  int v2225 = v2224->timer;
  int v2228 = v2225 + 1;
  v2224->timer = v2228;
  return v2224;
}

struct StateT * slot_33(struct StateT * v2229) {
  int v2230 = v2229->timer;
  int v2243 = v2230 + 1;
  v2229->timer = v2243;
  int * v2232 = v2229->reg_ready;
  int v2233 = v2232[11];
  int * v2234 = v2229->regs;
  int v2235 = v2234[11];
  int v2236 = v2232[10];
  int v2237 = v2234[10];
  int v2248 = (v2236 + (((v2233 + ((v2230 - v2233) & (~((v2230 - v2233) >> 31)))) - v2236) & (~(((v2233 + ((v2230 - v2233) & (~((v2230 - v2233) >> 31)))) - v2236) >> 31)))) + 1;
  v2232[10] = v2248;
  int * v2239 = v2229->regs;
  int v2250 = v2235 + v2237;
  v2239[10] = v2250;
  struct StateT * v2241 = slot_24(v2229);
  return v2241;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v3016 = v1->timer;
  int * v3017 = v1->reg_ready;
  int v3018 = v3017[0];
  int v3149 = v3018 + ((v3016 - v3018) & (~((v3016 - v3018) >> 31)));
  v1->timer = v3149;
  int v3020 = v1->timer;
  int * v3021 = v1->reg_ready;
  int v3022 = v3021[1];
  int v3152 = v3022 + ((v3020 - v3022) & (~((v3020 - v3022) >> 31)));
  v1->timer = v3152;
  int v3024 = v1->timer;
  int * v3025 = v1->reg_ready;
  int v3026 = v3025[2];
  int v3155 = v3026 + ((v3024 - v3026) & (~((v3024 - v3026) >> 31)));
  v1->timer = v3155;
  int v3028 = v1->timer;
  int * v3029 = v1->reg_ready;
  int v3030 = v3029[3];
  int v3158 = v3030 + ((v3028 - v3030) & (~((v3028 - v3030) >> 31)));
  v1->timer = v3158;
  int v3032 = v1->timer;
  int * v3033 = v1->reg_ready;
  int v3034 = v3033[4];
  int v3161 = v3034 + ((v3032 - v3034) & (~((v3032 - v3034) >> 31)));
  v1->timer = v3161;
  int v3036 = v1->timer;
  int * v3037 = v1->reg_ready;
  int v3038 = v3037[5];
  int v3164 = v3038 + ((v3036 - v3038) & (~((v3036 - v3038) >> 31)));
  v1->timer = v3164;
  int v3040 = v1->timer;
  int * v3041 = v1->reg_ready;
  int v3042 = v3041[6];
  int v3167 = v3042 + ((v3040 - v3042) & (~((v3040 - v3042) >> 31)));
  v1->timer = v3167;
  int v3044 = v1->timer;
  int * v3045 = v1->reg_ready;
  int v3046 = v3045[7];
  int v3170 = v3046 + ((v3044 - v3046) & (~((v3044 - v3046) >> 31)));
  v1->timer = v3170;
  int v3048 = v1->timer;
  int * v3049 = v1->reg_ready;
  int v3050 = v3049[8];
  int v3173 = v3050 + ((v3048 - v3050) & (~((v3048 - v3050) >> 31)));
  v1->timer = v3173;
  int v3052 = v1->timer;
  int * v3053 = v1->reg_ready;
  int v3054 = v3053[9];
  int v3176 = v3054 + ((v3052 - v3054) & (~((v3052 - v3054) >> 31)));
  v1->timer = v3176;
  int v3056 = v1->timer;
  int * v3057 = v1->reg_ready;
  int v3058 = v3057[10];
  int v3179 = v3058 + ((v3056 - v3058) & (~((v3056 - v3058) >> 31)));
  v1->timer = v3179;
  int v3060 = v1->timer;
  int * v3061 = v1->reg_ready;
  int v3062 = v3061[11];
  int v3182 = v3062 + ((v3060 - v3062) & (~((v3060 - v3062) >> 31)));
  v1->timer = v3182;
  int v3064 = v1->timer;
  int * v3065 = v1->reg_ready;
  int v3066 = v3065[12];
  int v3185 = v3066 + ((v3064 - v3066) & (~((v3064 - v3066) >> 31)));
  v1->timer = v3185;
  int v3068 = v1->timer;
  int * v3069 = v1->reg_ready;
  int v3070 = v3069[13];
  int v3188 = v3070 + ((v3068 - v3070) & (~((v3068 - v3070) >> 31)));
  v1->timer = v3188;
  int v3072 = v1->timer;
  int * v3073 = v1->reg_ready;
  int v3074 = v3073[14];
  int v3191 = v3074 + ((v3072 - v3074) & (~((v3072 - v3074) >> 31)));
  v1->timer = v3191;
  int v3076 = v1->timer;
  int * v3077 = v1->reg_ready;
  int v3078 = v3077[15];
  int v3194 = v3078 + ((v3076 - v3078) & (~((v3076 - v3078) >> 31)));
  v1->timer = v3194;
  int v3080 = v1->timer;
  int * v3081 = v1->reg_ready;
  int v3082 = v3081[16];
  int v3197 = v3082 + ((v3080 - v3082) & (~((v3080 - v3082) >> 31)));
  v1->timer = v3197;
  int v3084 = v1->timer;
  int * v3085 = v1->reg_ready;
  int v3086 = v3085[17];
  int v3200 = v3086 + ((v3084 - v3086) & (~((v3084 - v3086) >> 31)));
  v1->timer = v3200;
  int v3088 = v1->timer;
  int * v3089 = v1->reg_ready;
  int v3090 = v3089[18];
  int v3203 = v3090 + ((v3088 - v3090) & (~((v3088 - v3090) >> 31)));
  v1->timer = v3203;
  int v3092 = v1->timer;
  int * v3093 = v1->reg_ready;
  int v3094 = v3093[19];
  int v3206 = v3094 + ((v3092 - v3094) & (~((v3092 - v3094) >> 31)));
  v1->timer = v3206;
  int v3096 = v1->timer;
  int * v3097 = v1->reg_ready;
  int v3098 = v3097[20];
  int v3209 = v3098 + ((v3096 - v3098) & (~((v3096 - v3098) >> 31)));
  v1->timer = v3209;
  int v3100 = v1->timer;
  int * v3101 = v1->reg_ready;
  int v3102 = v3101[21];
  int v3212 = v3102 + ((v3100 - v3102) & (~((v3100 - v3102) >> 31)));
  v1->timer = v3212;
  int v3104 = v1->timer;
  int * v3105 = v1->reg_ready;
  int v3106 = v3105[22];
  int v3215 = v3106 + ((v3104 - v3106) & (~((v3104 - v3106) >> 31)));
  v1->timer = v3215;
  int v3108 = v1->timer;
  int * v3109 = v1->reg_ready;
  int v3110 = v3109[23];
  int v3218 = v3110 + ((v3108 - v3110) & (~((v3108 - v3110) >> 31)));
  v1->timer = v3218;
  int v3112 = v1->timer;
  int * v3113 = v1->reg_ready;
  int v3114 = v3113[24];
  int v3221 = v3114 + ((v3112 - v3114) & (~((v3112 - v3114) >> 31)));
  v1->timer = v3221;
  int v3116 = v1->timer;
  int * v3117 = v1->reg_ready;
  int v3118 = v3117[25];
  int v3224 = v3118 + ((v3116 - v3118) & (~((v3116 - v3118) >> 31)));
  v1->timer = v3224;
  int v3120 = v1->timer;
  int * v3121 = v1->reg_ready;
  int v3122 = v3121[26];
  int v3227 = v3122 + ((v3120 - v3122) & (~((v3120 - v3122) >> 31)));
  v1->timer = v3227;
  int v3124 = v1->timer;
  int * v3125 = v1->reg_ready;
  int v3126 = v3125[27];
  int v3230 = v3126 + ((v3124 - v3126) & (~((v3124 - v3126) >> 31)));
  v1->timer = v3230;
  int v3128 = v1->timer;
  int * v3129 = v1->reg_ready;
  int v3130 = v3129[28];
  int v3233 = v3130 + ((v3128 - v3130) & (~((v3128 - v3130) >> 31)));
  v1->timer = v3233;
  int v3132 = v1->timer;
  int * v3133 = v1->reg_ready;
  int v3134 = v3133[29];
  int v3236 = v3134 + ((v3132 - v3134) & (~((v3132 - v3134) >> 31)));
  v1->timer = v3236;
  int v3136 = v1->timer;
  int * v3137 = v1->reg_ready;
  int v3138 = v3137[30];
  int v3239 = v3138 + ((v3136 - v3138) & (~((v3136 - v3138) >> 31)));
  v1->timer = v3239;
  int v3140 = v1->timer;
  int * v3141 = v1->reg_ready;
  int v3142 = v3141[31];
  int v3242 = v3142 + ((v3140 - v3142) & (~((v3140 - v3142) >> 31)));
  v1->timer = v3242;
  return v1;
}

struct StateT * slot_4(struct StateT * v458) {
  int v459 = v458->timer;
  int v467 = v459 + 1;
  v458->timer = v467;
  int * v461 = v458->reg_ready;
  v461[10] = v467;
  int * v463 = v458->regs;
  v463[10] = 0;
  struct StateT * v465 = slot_6(v458);
  return v465;
}

struct StateT * slot_15(struct StateT * v859) {
  int * v860 = v859->saved_regs;
  int v861 = v860[10];
  int v862 = v860[11];
  bool v978 = (v861 ^ -2147483648) >= (v862 ^ -2147483648);
  struct StateT * v973;
  if (v978) {
    int v863 = v859->timer;
    int v979 = v863 + 15;
    v859->timer = v979;
    int * v865 = v859->saved_regs;
    int v866 = v865[10];
    int * v867 = v859->regs;
    v867[10] = v866;
    int * v869 = v859->saved_regs;
    int v870 = v869[11];
    int * v871 = v859->regs;
    v871[11] = v870;
    int * v873 = v859->reg_ready;
    int v874 = v859->timer;
    v873[0] = v874;
    int * v876 = v859->reg_ready;
    int v877 = v859->timer;
    v876[1] = v877;
    int * v879 = v859->reg_ready;
    int v880 = v859->timer;
    v879[2] = v880;
    int * v882 = v859->reg_ready;
    int v883 = v859->timer;
    v882[3] = v883;
    int * v885 = v859->reg_ready;
    int v886 = v859->timer;
    v885[4] = v886;
    int * v888 = v859->reg_ready;
    int v889 = v859->timer;
    v888[5] = v889;
    int * v891 = v859->reg_ready;
    int v892 = v859->timer;
    v891[6] = v892;
    int * v894 = v859->reg_ready;
    int v895 = v859->timer;
    v894[7] = v895;
    int * v897 = v859->reg_ready;
    int v898 = v859->timer;
    v897[8] = v898;
    int * v900 = v859->reg_ready;
    int v901 = v859->timer;
    v900[9] = v901;
    int * v903 = v859->reg_ready;
    int v904 = v859->timer;
    v903[10] = v904;
    int * v906 = v859->reg_ready;
    int v907 = v859->timer;
    v906[11] = v907;
    int * v909 = v859->reg_ready;
    int v910 = v859->timer;
    v909[12] = v910;
    int * v912 = v859->reg_ready;
    int v913 = v859->timer;
    v912[13] = v913;
    int * v915 = v859->reg_ready;
    int v916 = v859->timer;
    v915[14] = v916;
    int * v918 = v859->reg_ready;
    int v919 = v859->timer;
    v918[15] = v919;
    int * v921 = v859->reg_ready;
    int v922 = v859->timer;
    v921[16] = v922;
    int * v924 = v859->reg_ready;
    int v925 = v859->timer;
    v924[17] = v925;
    int * v927 = v859->reg_ready;
    int v928 = v859->timer;
    v927[18] = v928;
    int * v930 = v859->reg_ready;
    int v931 = v859->timer;
    v930[19] = v931;
    int * v933 = v859->reg_ready;
    int v934 = v859->timer;
    v933[20] = v934;
    int * v936 = v859->reg_ready;
    int v937 = v859->timer;
    v936[21] = v937;
    int * v939 = v859->reg_ready;
    int v940 = v859->timer;
    v939[22] = v940;
    int * v942 = v859->reg_ready;
    int v943 = v859->timer;
    v942[23] = v943;
    int * v945 = v859->reg_ready;
    int v946 = v859->timer;
    v945[24] = v946;
    int * v948 = v859->reg_ready;
    int v949 = v859->timer;
    v948[25] = v949;
    int * v951 = v859->reg_ready;
    int v952 = v859->timer;
    v951[26] = v952;
    int * v954 = v859->reg_ready;
    int v955 = v859->timer;
    v954[27] = v955;
    int * v957 = v859->reg_ready;
    int v958 = v859->timer;
    v957[28] = v958;
    int * v960 = v859->reg_ready;
    int v961 = v859->timer;
    v960[29] = v961;
    int * v963 = v859->reg_ready;
    int v964 = v859->timer;
    v963[30] = v964;
    int * v966 = v859->reg_ready;
    int v967 = v859->timer;
    v966[31] = v967;
    struct StateT * v969 = slot_32(v859);
    v973 = v969;
  } else {
    struct StateT * v971 = slot_18(v859);
    v973 = v971;
  }
  return v973;
}

struct StateT * slot_18(struct StateT * v1111) {
  int v1112 = v1111->timer;
  int v1116 = v1112 + 1;
  v1111->timer = v1116;
  struct StateT * v1114 = slot_21(v1111);
  return v1114;
}

struct StateT * slot_9(struct StateT * v738) {
  int * v739 = v738->saved_regs;
  int * v740 = v738->regs;
  int v741 = v740[11];
  v739[11] = v741;
  int v743 = v738->timer;
  int v755 = v743 + 1;
  v738->timer = v755;
  int * v745 = v738->reg_ready;
  v745[11] = v755;
  int * v747 = v738->regs;
  v747[11] = 0;
  struct StateT * v749 = slot_11(v738);
  return v749;
}

struct StateT * slot_11(struct StateT * v777) {
  int v778 = v777->timer;
  int v789 = v778 + 1;
  v777->timer = v789;
  int * v780 = v777->reg_ready;
  int v781 = v780[11];
  int * v782 = v777->regs;
  int v783 = v782[11];
  int v793 = (v781 + ((v778 - v781) & (~((v778 - v781) >> 31)))) + 1;
  v780[11] = v793;
  int * v785 = v777->regs;
  int v795 = v783 + 72;
  v785[11] = v795;
  struct StateT * v787 = slot_13(v777);
  return v787;
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
  
  // public data, where the section headers put it
  s1.mem[0] = 8;
  s2.mem[0] = 8;
  int x = bounded(0, 15);
  s1.regs[10] = x;
  s2.regs[10] = x;
  // probe, the attacker's: the same draw in both states
  for (int i=0; i<16; i++) {
    int v = bounded(0, 20);
    s1.mem[1 + i] = v;
    s2.mem[1 + i] = v;
  }
  // temp, the attacker's: the same draw in both states
  for (int i=0; i<1; i++) {
    int v = bounded(0, 20);
    s1.mem[17 + i] = v;
    s2.mem[17 + i] = v;
  }
  // publicarray, the attacker's: the same draw in both states
  for (int i=0; i<8; i++) {
    int v = bounded(0, 20);
    s1.mem[18 + i] = v;
    s2.mem[18 + i] = v;
  }
  
  // secretarray, secret: a different draw in each state
  for (int i=0; i<8; i++) {
    s1.mem[26 + i] = secret(0, 20);
    s2.mem[26 + i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}