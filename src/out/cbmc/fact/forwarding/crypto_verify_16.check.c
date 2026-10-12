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

struct StateT * slot_12(struct StateT * v569);
struct StateT * slot_43(struct StateT * v1887);
struct StateT * slot_6(struct StateT * v85);
struct StateT * slot_29(struct StateT * v1275);
struct StateT * slot_16(struct StateT * v653);
struct StateT * slot_5(struct StateT * v61);
struct StateT * slot_7(struct StateT * v109);
struct StateT * slot_31(struct StateT * v1308);
struct StateT * slot_26(struct StateT * v1034);
struct StateT * slot_10(struct StateT * v531);
struct StateT * slot_19(struct StateT * v738);
struct StateT * slot_14(struct StateT * v609);
struct StateT * slot_44(struct StateT * v1910);
struct StateT * slot_28(struct StateT * v1253);
struct StateT * slot_32(struct StateT * v1324);
struct StateT * slot_17(struct StateT * v713);
struct StateT * slot_33(struct StateT * v1340);
struct StateT * slot_36(struct StateT * v1386);
struct StateT * slot_37(struct StateT * v1410);
struct StateT * slot_40(struct StateT * v1832);
struct StateT * slot_27(struct StateT * v1237);
struct StateT * slot_15(struct StateT * v632);
struct StateT * slot_22(struct StateT * v767);
struct StateT * slot_35(struct StateT * v1362);
struct StateT * slot_34(struct StateT * v1354);
struct StateT * slot_25(struct StateT * v831);
struct StateT * slot_23(struct StateT * v797);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_3(struct StateT * v41);
struct StateT * slot_45(struct StateT * v1933);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_13(struct StateT * v586);
struct StateT * slot_38(struct StateT * v1613);
struct StateT * slot_24(struct StateT * v814);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_42(struct StateT * v1870);
struct StateT * slot_46(struct StateT * v1954);
struct StateT * slot_20(struct StateT * v743);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_41(struct StateT * v1854);
struct StateT * slot_39(struct StateT * v1816);
struct StateT * slot_8(struct StateT * v312);
struct StateT * slot_30(struct StateT * v1291);
struct StateT * slot_4(struct StateT * v53);
struct StateT * slot_18(struct StateT * v730);
struct StateT * slot_9(struct StateT * v515);
struct StateT * slot_11(struct StateT * v553);
struct StateT * slot_12(struct StateT * v569) {
  int v570 = v569->timer;
  int v578 = v570 + 1;
  v569->timer = v578;
  int * v572 = v569->regs;
  int v573 = v572[16];
  int v574 = v572[12];
  int v583 = v573 & v574;
  v572[17] = v583;
  struct StateT * v576 = slot_13(v569);
  return v576;
}

struct StateT * slot_43(struct StateT * v1887) {
  int * v1888 = v1887->saved_regs;
  int * v1889 = v1887->regs;
  int v1890 = v1889[14];
  v1888[14] = v1890;
  int v1892 = v1887->timer;
  int v1904 = v1892 + 1;
  v1887->timer = v1904;
  int * v1894 = v1887->regs;
  int v1895 = v1894[14];
  int v1896 = v1894[16];
  int v1907 = v1895 ^ v1896;
  v1894[14] = v1907;
  struct StateT * v1898 = slot_44(v1887);
  return v1898;
}

struct StateT * slot_6(struct StateT * v85) {
  int * v86 = v85->saved_regs;
  int * v87 = v85->regs;
  int v88 = v87[17];
  v86[17] = v88;
  int v90 = v85->timer;
  int v102 = v90 + 1;
  v85->timer = v102;
  int * v92 = v85->regs;
  int v93 = v92[11];
  int v94 = v92[13];
  int v106 = v93 + v94;
  v92[17] = v106;
  struct StateT * v96 = slot_7(v85);
  return v96;
}

struct StateT * slot_29(struct StateT * v1275) {
  int v1276 = v1275->timer;
  int v1284 = v1276 + 1;
  v1275->timer = v1284;
  int * v1278 = v1275->regs;
  int v1279 = v1278[16];
  int v1280 = v1278[14];
  int v1288 = v1279 & v1280;
  v1278[16] = v1288;
  struct StateT * v1282 = slot_30(v1275);
  return v1282;
}

struct StateT * slot_16(struct StateT * v653) {
  int * v654 = v653->regs;
  int v655 = v654[15];
  bool v686 = (v655 ^ -2147483648) < -2147483648;
  struct StateT * v682;
  if (v686) {
    int v656 = v653->timer;
    int v687 = v656 + 15;
    v653->timer = v687;
    int * v658 = v653->saved_regs;
    int v659 = v658[16];
    int * v660 = v653->regs;
    v660[16] = v659;
    int * v662 = v653->saved_regs;
    int v663 = v662[17];
    int * v664 = v653->regs;
    v664[17] = v663;
    int * v666 = v653->saved_regs;
    int v667 = v666[14];
    int * v668 = v653->regs;
    v668[14] = v667;
    int * v670 = v653->saved_regs;
    int v671 = v670[12];
    int * v672 = v653->regs;
    v672[12] = v671;
    int * v674 = v653->saved_regs;
    int v675 = v674[13];
    int * v676 = v653->regs;
    v676[13] = v675;
    struct StateT * v678 = slot_17(v653);
    v682 = v678;
  } else {
    struct StateT * v680 = slot_18(v653);
    v682 = v680;
  }
  return v682;
}

struct StateT * slot_5(struct StateT * v61) {
  int * v62 = v61->saved_regs;
  int * v63 = v61->regs;
  int v64 = v63[16];
  v62[16] = v64;
  int v66 = v61->timer;
  int v78 = v66 + 1;
  v61->timer = v78;
  int * v68 = v61->regs;
  int v69 = v68[10];
  int v70 = v68[13];
  int v82 = v69 + v70;
  v68[16] = v82;
  struct StateT * v72 = slot_6(v61);
  return v72;
}

struct StateT * slot_7(struct StateT * v109) {
  int v110 = v109->timer;
  int v220 = v110 + 1;
  v109->timer = v220;
  int * v112 = v109->regs;
  int v113 = v112[16];
  int * v114 = v109->cache_tags;
  int v224 = (((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1)) & 1) * 2;
  int v115 = v114[v224];
  int v225 = ((((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1)) & 1) * 2) + 1;
  int v116 = v114[v225];
  int v226 = 4 + ((((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1)) & 3) * 2);
  int v117 = v114[v226];
  int v227 = (4 + ((((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v118 = v114[v227];
  int v119 = v109->timer;
  int v228 = v119 + ((100 ^ (((~(((v117 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))) | (-(v117 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))))) >> 31)) | (~(((v118 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))) | (-(v118 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v115 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))) | (-(v115 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))))) >> 31)) | (~(((v116 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))) | (-(v116 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v117 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))) | (-(v117 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))))) >> 31)) | (~(((v118 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))) | (-(v118 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))))) >> 31))) & 104)))));
  v109->timer = v228;
  int * v121 = v109->cache_vals;
  bool v229 = !(((~(((v115 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))) | (-(v115 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))))) >> 31)) | (~(((v116 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))) | (-(v116 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))))) >> 31))) == 0);
  int v214;
  if (v229) {
    int * v122 = v109->cache_age;
    int v231 = ((((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1)) & 1) * 2) + ((~(((v116 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))) | (-(v116 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))))) >> 31)) & 1);
    int v123 = v122[v231];
    int v124 = v122[v224];
    int v232 = v124 + ((int)((unsigned int)(v124 - v123) >> 31));
    v122[v224] = v232;
    int * v126 = v109->cache_age;
    int v127 = v126[v225];
    int v234 = v127 + ((int)((unsigned int)(v127 - v123) >> 31));
    v126[v225] = v234;
    int * v129 = v109->cache_age;
    v129[v231] = 0;
    v214 = v231;
  } else {
    int * v132 = v109->cache_age;
    int v238 = (((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1)) & 1) * 2;
    int v133 = v132[v238];
    int * v134 = v109->cache_tags;
    int v135 = v134[v238];
    int v136 = v132[v225];
    int v137 = v134[v225];
    bool v240 = !(((~(((v117 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))) | (-(v117 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))))) >> 31)) | (~(((v118 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))) | (-(v118 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))))) >> 31))) == 0);
    int v191;
    if (v240) {
      int * v138 = v109->cache_age;
      int v242 = (4 + ((((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1)) & 3) * 2)) + ((~(((v118 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))) | (-(v118 ^ ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1))))) >> 31)) & 1);
      int v139 = v138[v242];
      int v140 = v138[v226];
      int v243 = v140 + ((int)((unsigned int)(v140 - v139) >> 31));
      v138[v226] = v243;
      int * v142 = v109->cache_age;
      int v143 = v142[v227];
      int v245 = v143 + ((int)((unsigned int)(v143 - v139) >> 31));
      v142[v227] = v245;
      int * v145 = v109->cache_age;
      v145[v242] = 0;
      v191 = v242;
    } else {
      int * v148 = v109->cache_age;
      int v249 = 4 + ((((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1)) & 3) * 2);
      int v149 = v148[v249];
      int * v150 = v109->cache_tags;
      int v151 = v150[v249];
      int v152 = v148[v227];
      int v153 = v150[v227];
      int * v154 = v109->cache_dirty;
      int v252 = (4 + ((((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1)) & 3) * 2)) + ((((v149 + ((~(((v151 ^ -1) | (-(v151 ^ -1))) >> 31)) & 2)) - (v152 + ((~(((v153 ^ -1) | (-(v153 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v155 = v154[v252];
      bool v253 = !(v155 == 0);
      if (v253) {
        int * v156 = v109->cache_tags;
        int v157 = v156[v252];
        int * v158 = v109->cache_vals;
        int v256 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1)) & 3) * 2)) + ((((v149 + ((~(((v151 ^ -1) | (-(v151 ^ -1))) >> 31)) & 2)) - (v152 + ((~(((v153 ^ -1) | (-(v153 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v159 = v158[v256];
        int v257 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1)) & 3) * 2)) + ((((v149 + ((~(((v151 ^ -1) | (-(v151 ^ -1))) >> 31)) & 2)) - (v152 + ((~(((v153 ^ -1) | (-(v153 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v160 = v158[v257];
        int * v161 = v109->mem;
        int v259 = v157 * 2;
        v161[v259] = v159;
        int * v163 = v109->mem;
        int v262 = (v157 * 2) + 1;
        v163[v262] = v160;
        ;
      } else {
        ;
      }
      int * v168 = v109->mem;
      int v267 = ((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1)) * 2;
      int v169 = v168[v267];
      int v268 = (((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1)) * 2) + 1;
      int v170 = v168[v268];
      int * v171 = v109->cache_vals;
      int v270 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1)) & 3) * 2)) + ((((v149 + ((~(((v151 ^ -1) | (-(v151 ^ -1))) >> 31)) & 2)) - (v152 + ((~(((v153 ^ -1) | (-(v153 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v171[v270] = v169;
      int * v173 = v109->cache_vals;
      int v273 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1)) & 3) * 2)) + ((((v149 + ((~(((v151 ^ -1) | (-(v151 ^ -1))) >> 31)) & 2)) - (v152 + ((~(((v153 ^ -1) | (-(v153 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v173[v273] = v170;
      int * v175 = v109->cache_tags;
      int v276 = (int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1);
      v175[v252] = v276;
      int * v177 = v109->cache_dirty;
      v177[v252] = 0;
      int * v179 = v109->cache_age;
      v179[v252] = 1;
      int * v181 = v109->cache_age;
      int v182 = v181[v252];
      int v183 = v181[v226];
      int v282 = v183 + ((int)((unsigned int)(v183 - v182) >> 31));
      v181[v226] = v282;
      int * v185 = v109->cache_age;
      int v186 = v185[v227];
      int v284 = v186 + ((int)((unsigned int)(v186 - v182) >> 31));
      v185[v227] = v284;
      int * v188 = v109->cache_age;
      v188[v252] = 0;
      v191 = v252;
    }
    int * v192 = v109->cache_vals;
    int v287 = v191 * 2;
    int v193 = v192[v287];
    int v288 = (v191 * 2) + 1;
    int v194 = v192[v288];
    int v289 = (((((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1)) & 1) * 2) + ((((v133 + ((~(((v135 ^ -1) | (-(v135 ^ -1))) >> 31)) & 2)) - (v136 + ((~(((v137 ^ -1) | (-(v137 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v192[v289] = v193;
    int * v196 = v109->cache_vals;
    int v292 = ((((((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1)) & 1) * 2) + ((((v133 + ((~(((v135 ^ -1) | (-(v135 ^ -1))) >> 31)) & 2)) - (v136 + ((~(((v137 ^ -1) | (-(v137 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v196[v292] = v194;
    int * v198 = v109->cache_tags;
    int v295 = ((((int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1)) & 1) * 2) + ((((v133 + ((~(((v135 ^ -1) | (-(v135 ^ -1))) >> 31)) & 2)) - (v136 + ((~(((v137 ^ -1) | (-(v137 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v296 = (int)((unsigned int)((int)((unsigned int)v113 >> 2)) >> 1);
    v198[v295] = v296;
    int * v200 = v109->cache_dirty;
    v200[v295] = 0;
    int * v202 = v109->cache_age;
    v202[v295] = 1;
    int * v204 = v109->cache_age;
    int v205 = v204[v295];
    int v206 = v204[v224];
    int v302 = v206 + ((int)((unsigned int)(v206 - v205) >> 31));
    v204[v224] = v302;
    int * v208 = v109->cache_age;
    int v209 = v208[v225];
    int v304 = v209 + ((int)((unsigned int)(v209 - v205) >> 31));
    v208[v225] = v304;
    int * v211 = v109->cache_age;
    v211[v295] = 0;
    v214 = v295;
  }
  int v307 = (v214 * 2) + (((int)((unsigned int)v113 >> 2)) & 1);
  int v215 = v121[v307];
  int * v216 = v109->regs;
  int v309 = ((int)((unsigned int)v215 >> ((v113 & 3) << 3))) & 255;
  v216[16] = v309;
  struct StateT * v218 = slot_8(v109);
  return v218;
}

struct StateT * slot_31(struct StateT * v1308) {
  int v1309 = v1308->timer;
  int v1317 = v1309 + 1;
  v1308->timer = v1317;
  int * v1311 = v1308->regs;
  int v1312 = v1311[14];
  int v1313 = v1311[16];
  int v1321 = v1312 ^ v1313;
  v1311[14] = v1321;
  struct StateT * v1315 = slot_32(v1308);
  return v1315;
}

struct StateT * slot_26(struct StateT * v1034) {
  int v1035 = v1034->timer;
  int v1145 = v1035 + 1;
  v1034->timer = v1145;
  int * v1037 = v1034->regs;
  int v1038 = v1037[17];
  int * v1039 = v1034->cache_tags;
  int v1149 = (((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1)) & 1) * 2;
  int v1040 = v1039[v1149];
  int v1150 = ((((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1041 = v1039[v1150];
  int v1151 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1)) & 3) * 2);
  int v1042 = v1039[v1151];
  int v1152 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1043 = v1039[v1152];
  int v1044 = v1034->timer;
  int v1153 = v1044 + ((100 ^ (((~(((v1042 ^ ((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1))) | (-(v1042 ^ ((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1))))) >> 31)) | (~(((v1043 ^ ((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1))) | (-(v1043 ^ ((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1040 ^ ((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1))) | (-(v1040 ^ ((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1))))) >> 31)) | (~(((v1041 ^ ((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1))) | (-(v1041 ^ ((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1042 ^ ((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1))) | (-(v1042 ^ ((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1))))) >> 31)) | (~(((v1043 ^ ((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1))) | (-(v1043 ^ ((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1034->timer = v1153;
  int * v1046 = v1034->cache_vals;
  bool v1154 = !(((~(((v1040 ^ ((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1))) | (-(v1040 ^ ((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1))))) >> 31)) | (~(((v1041 ^ ((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1))) | (-(v1041 ^ ((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1))))) >> 31))) == 0);
  int v1139;
  if (v1154) {
    int * v1047 = v1034->cache_age;
    int v1156 = ((((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1)) & 1) * 2) + ((~(((v1041 ^ ((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1))) | (-(v1041 ^ ((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1))))) >> 31)) & 1);
    int v1048 = v1047[v1156];
    int v1049 = v1047[v1149];
    int v1157 = v1049 + ((int)((unsigned int)(v1049 - v1048) >> 31));
    v1047[v1149] = v1157;
    int * v1051 = v1034->cache_age;
    int v1052 = v1051[v1150];
    int v1159 = v1052 + ((int)((unsigned int)(v1052 - v1048) >> 31));
    v1051[v1150] = v1159;
    int * v1054 = v1034->cache_age;
    v1054[v1156] = 0;
    v1139 = v1156;
  } else {
    int * v1057 = v1034->cache_age;
    int v1163 = (((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1)) & 1) * 2;
    int v1058 = v1057[v1163];
    int * v1059 = v1034->cache_tags;
    int v1060 = v1059[v1163];
    int v1061 = v1057[v1150];
    int v1062 = v1059[v1150];
    bool v1165 = !(((~(((v1042 ^ ((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1))) | (-(v1042 ^ ((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1))))) >> 31)) | (~(((v1043 ^ ((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1))) | (-(v1043 ^ ((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1))))) >> 31))) == 0);
    int v1116;
    if (v1165) {
      int * v1063 = v1034->cache_age;
      int v1167 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1043 ^ ((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1))) | (-(v1043 ^ ((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1))))) >> 31)) & 1);
      int v1064 = v1063[v1167];
      int v1065 = v1063[v1151];
      int v1168 = v1065 + ((int)((unsigned int)(v1065 - v1064) >> 31));
      v1063[v1151] = v1168;
      int * v1067 = v1034->cache_age;
      int v1068 = v1067[v1152];
      int v1170 = v1068 + ((int)((unsigned int)(v1068 - v1064) >> 31));
      v1067[v1152] = v1170;
      int * v1070 = v1034->cache_age;
      v1070[v1167] = 0;
      v1116 = v1167;
    } else {
      int * v1073 = v1034->cache_age;
      int v1174 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1)) & 3) * 2);
      int v1074 = v1073[v1174];
      int * v1075 = v1034->cache_tags;
      int v1076 = v1075[v1174];
      int v1077 = v1073[v1152];
      int v1078 = v1075[v1152];
      int * v1079 = v1034->cache_dirty;
      int v1177 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1)) & 3) * 2)) + ((((v1074 + ((~(((v1076 ^ -1) | (-(v1076 ^ -1))) >> 31)) & 2)) - (v1077 + ((~(((v1078 ^ -1) | (-(v1078 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1080 = v1079[v1177];
      bool v1178 = !(v1080 == 0);
      if (v1178) {
        int * v1081 = v1034->cache_tags;
        int v1082 = v1081[v1177];
        int * v1083 = v1034->cache_vals;
        int v1181 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1)) & 3) * 2)) + ((((v1074 + ((~(((v1076 ^ -1) | (-(v1076 ^ -1))) >> 31)) & 2)) - (v1077 + ((~(((v1078 ^ -1) | (-(v1078 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1084 = v1083[v1181];
        int v1182 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1)) & 3) * 2)) + ((((v1074 + ((~(((v1076 ^ -1) | (-(v1076 ^ -1))) >> 31)) & 2)) - (v1077 + ((~(((v1078 ^ -1) | (-(v1078 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1085 = v1083[v1182];
        int * v1086 = v1034->mem;
        int v1184 = v1082 * 2;
        v1086[v1184] = v1084;
        int * v1088 = v1034->mem;
        int v1187 = (v1082 * 2) + 1;
        v1088[v1187] = v1085;
        ;
      } else {
        ;
      }
      int * v1093 = v1034->mem;
      int v1192 = ((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1)) * 2;
      int v1094 = v1093[v1192];
      int v1193 = (((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1)) * 2) + 1;
      int v1095 = v1093[v1193];
      int * v1096 = v1034->cache_vals;
      int v1195 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1)) & 3) * 2)) + ((((v1074 + ((~(((v1076 ^ -1) | (-(v1076 ^ -1))) >> 31)) & 2)) - (v1077 + ((~(((v1078 ^ -1) | (-(v1078 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1096[v1195] = v1094;
      int * v1098 = v1034->cache_vals;
      int v1198 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1)) & 3) * 2)) + ((((v1074 + ((~(((v1076 ^ -1) | (-(v1076 ^ -1))) >> 31)) & 2)) - (v1077 + ((~(((v1078 ^ -1) | (-(v1078 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1098[v1198] = v1095;
      int * v1100 = v1034->cache_tags;
      int v1201 = (int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1);
      v1100[v1177] = v1201;
      int * v1102 = v1034->cache_dirty;
      v1102[v1177] = 0;
      int * v1104 = v1034->cache_age;
      v1104[v1177] = 1;
      int * v1106 = v1034->cache_age;
      int v1107 = v1106[v1177];
      int v1108 = v1106[v1151];
      int v1207 = v1108 + ((int)((unsigned int)(v1108 - v1107) >> 31));
      v1106[v1151] = v1207;
      int * v1110 = v1034->cache_age;
      int v1111 = v1110[v1152];
      int v1209 = v1111 + ((int)((unsigned int)(v1111 - v1107) >> 31));
      v1110[v1152] = v1209;
      int * v1113 = v1034->cache_age;
      v1113[v1177] = 0;
      v1116 = v1177;
    }
    int * v1117 = v1034->cache_vals;
    int v1212 = v1116 * 2;
    int v1118 = v1117[v1212];
    int v1213 = (v1116 * 2) + 1;
    int v1119 = v1117[v1213];
    int v1214 = (((((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1)) & 1) * 2) + ((((v1058 + ((~(((v1060 ^ -1) | (-(v1060 ^ -1))) >> 31)) & 2)) - (v1061 + ((~(((v1062 ^ -1) | (-(v1062 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1117[v1214] = v1118;
    int * v1121 = v1034->cache_vals;
    int v1217 = ((((((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1)) & 1) * 2) + ((((v1058 + ((~(((v1060 ^ -1) | (-(v1060 ^ -1))) >> 31)) & 2)) - (v1061 + ((~(((v1062 ^ -1) | (-(v1062 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1121[v1217] = v1119;
    int * v1123 = v1034->cache_tags;
    int v1220 = ((((int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1)) & 1) * 2) + ((((v1058 + ((~(((v1060 ^ -1) | (-(v1060 ^ -1))) >> 31)) & 2)) - (v1061 + ((~(((v1062 ^ -1) | (-(v1062 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1221 = (int)((unsigned int)((int)((unsigned int)v1038 >> 2)) >> 1);
    v1123[v1220] = v1221;
    int * v1125 = v1034->cache_dirty;
    v1125[v1220] = 0;
    int * v1127 = v1034->cache_age;
    v1127[v1220] = 1;
    int * v1129 = v1034->cache_age;
    int v1130 = v1129[v1220];
    int v1131 = v1129[v1149];
    int v1227 = v1131 + ((int)((unsigned int)(v1131 - v1130) >> 31));
    v1129[v1149] = v1227;
    int * v1133 = v1034->cache_age;
    int v1134 = v1133[v1150];
    int v1229 = v1134 + ((int)((unsigned int)(v1134 - v1130) >> 31));
    v1133[v1150] = v1229;
    int * v1136 = v1034->cache_age;
    v1136[v1220] = 0;
    v1139 = v1220;
  }
  int v1232 = (v1139 * 2) + (((int)((unsigned int)v1038 >> 2)) & 1);
  int v1140 = v1046[v1232];
  int * v1141 = v1034->regs;
  int v1234 = ((int)((unsigned int)v1140 >> ((v1038 & 3) << 3))) & 255;
  v1141[17] = v1234;
  struct StateT * v1143 = slot_27(v1034);
  return v1143;
}

struct StateT * slot_10(struct StateT * v531) {
  int v532 = v531->timer;
  int v543 = v532 + 1;
  v531->timer = v543;
  int * v534 = v531->regs;
  int v535 = v534[16];
  bool v546 = -2147483648 < (v535 ^ -2147483648);
  int v538;
  if (v546) {
    v538 = 1;
  } else {
    v538 = 0;
  }
  int * v539 = v531->regs;
  v539[16] = v538;
  struct StateT * v541 = slot_11(v531);
  return v541;
}

struct StateT * slot_19(struct StateT * v738) {
  int v739 = v738->timer;
  int v742 = v739 + 1;
  v738->timer = v742;
  return v738;
}

struct StateT * slot_14(struct StateT * v609) {
  int * v610 = v609->saved_regs;
  int * v611 = v609->regs;
  int v612 = v611[12];
  v610[12] = v612;
  int v614 = v609->timer;
  int v626 = v614 + 1;
  v609->timer = v626;
  int * v616 = v609->regs;
  int v617 = v616[12];
  int v618 = v616[17];
  int v629 = v617 ^ v618;
  v616[12] = v629;
  struct StateT * v620 = slot_15(v609);
  return v620;
}

struct StateT * slot_44(struct StateT * v1910) {
  int * v1911 = v1910->saved_regs;
  int * v1912 = v1910->regs;
  int v1913 = v1912[12];
  v1911[12] = v1913;
  int v1915 = v1910->timer;
  int v1927 = v1915 + 1;
  v1910->timer = v1927;
  int * v1917 = v1910->regs;
  int v1918 = v1917[12];
  int v1919 = v1917[17];
  int v1930 = v1918 ^ v1919;
  v1917[12] = v1930;
  struct StateT * v1921 = slot_45(v1910);
  return v1921;
}

struct StateT * slot_28(struct StateT * v1253) {
  int v1254 = v1253->timer;
  int v1265 = v1254 + 1;
  v1253->timer = v1265;
  int * v1256 = v1253->regs;
  int v1257 = v1256[16];
  bool v1268 = -2147483648 < (v1257 ^ -2147483648);
  int v1260;
  if (v1268) {
    v1260 = 1;
  } else {
    v1260 = 0;
  }
  int * v1261 = v1253->regs;
  v1261[16] = v1260;
  struct StateT * v1263 = slot_29(v1253);
  return v1263;
}

struct StateT * slot_32(struct StateT * v1324) {
  int v1325 = v1324->timer;
  int v1333 = v1325 + 1;
  v1324->timer = v1333;
  int * v1327 = v1324->regs;
  int v1328 = v1327[12];
  int v1329 = v1327[17];
  int v1337 = v1328 ^ v1329;
  v1327[12] = v1337;
  struct StateT * v1331 = slot_33(v1324);
  return v1331;
}

struct StateT * slot_17(struct StateT * v713) {
  int v714 = v713->timer;
  int v722 = v714 + 1;
  v713->timer = v722;
  int * v716 = v713->regs;
  int v717 = v716[14];
  int v718 = v716[12];
  int v727 = v717 | v718;
  v716[10] = v727;
  struct StateT * v720 = slot_19(v713);
  return v720;
}

struct StateT * slot_33(struct StateT * v1340) {
  int v1341 = v1340->timer;
  int v1348 = v1341 + 1;
  v1340->timer = v1348;
  int * v1343 = v1340->regs;
  int v1344 = v1343[13];
  int v1351 = v1344 + 1;
  v1343[13] = v1351;
  struct StateT * v1346 = slot_34(v1340);
  return v1346;
}

struct StateT * slot_36(struct StateT * v1386) {
  int * v1387 = v1386->saved_regs;
  int * v1388 = v1386->regs;
  int v1389 = v1388[17];
  v1387[17] = v1389;
  int v1391 = v1386->timer;
  int v1403 = v1391 + 1;
  v1386->timer = v1403;
  int * v1393 = v1386->regs;
  int v1394 = v1393[11];
  int v1395 = v1393[13];
  int v1407 = v1394 + v1395;
  v1393[17] = v1407;
  struct StateT * v1397 = slot_37(v1386);
  return v1397;
}

struct StateT * slot_37(struct StateT * v1410) {
  int v1411 = v1410->timer;
  int v1521 = v1411 + 1;
  v1410->timer = v1521;
  int * v1413 = v1410->regs;
  int v1414 = v1413[16];
  int * v1415 = v1410->cache_tags;
  int v1525 = (((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1)) & 1) * 2;
  int v1416 = v1415[v1525];
  int v1526 = ((((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1417 = v1415[v1526];
  int v1527 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1)) & 3) * 2);
  int v1418 = v1415[v1527];
  int v1528 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1419 = v1415[v1528];
  int v1420 = v1410->timer;
  int v1529 = v1420 + ((100 ^ (((~(((v1418 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))) | (-(v1418 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))))) >> 31)) | (~(((v1419 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))) | (-(v1419 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1416 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))) | (-(v1416 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))))) >> 31)) | (~(((v1417 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))) | (-(v1417 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1418 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))) | (-(v1418 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))))) >> 31)) | (~(((v1419 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))) | (-(v1419 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1410->timer = v1529;
  int * v1422 = v1410->cache_vals;
  bool v1530 = !(((~(((v1416 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))) | (-(v1416 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))))) >> 31)) | (~(((v1417 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))) | (-(v1417 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))))) >> 31))) == 0);
  int v1515;
  if (v1530) {
    int * v1423 = v1410->cache_age;
    int v1532 = ((((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1)) & 1) * 2) + ((~(((v1417 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))) | (-(v1417 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))))) >> 31)) & 1);
    int v1424 = v1423[v1532];
    int v1425 = v1423[v1525];
    int v1533 = v1425 + ((int)((unsigned int)(v1425 - v1424) >> 31));
    v1423[v1525] = v1533;
    int * v1427 = v1410->cache_age;
    int v1428 = v1427[v1526];
    int v1535 = v1428 + ((int)((unsigned int)(v1428 - v1424) >> 31));
    v1427[v1526] = v1535;
    int * v1430 = v1410->cache_age;
    v1430[v1532] = 0;
    v1515 = v1532;
  } else {
    int * v1433 = v1410->cache_age;
    int v1539 = (((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1)) & 1) * 2;
    int v1434 = v1433[v1539];
    int * v1435 = v1410->cache_tags;
    int v1436 = v1435[v1539];
    int v1437 = v1433[v1526];
    int v1438 = v1435[v1526];
    bool v1541 = !(((~(((v1418 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))) | (-(v1418 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))))) >> 31)) | (~(((v1419 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))) | (-(v1419 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))))) >> 31))) == 0);
    int v1492;
    if (v1541) {
      int * v1439 = v1410->cache_age;
      int v1543 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1419 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))) | (-(v1419 ^ ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1))))) >> 31)) & 1);
      int v1440 = v1439[v1543];
      int v1441 = v1439[v1527];
      int v1544 = v1441 + ((int)((unsigned int)(v1441 - v1440) >> 31));
      v1439[v1527] = v1544;
      int * v1443 = v1410->cache_age;
      int v1444 = v1443[v1528];
      int v1546 = v1444 + ((int)((unsigned int)(v1444 - v1440) >> 31));
      v1443[v1528] = v1546;
      int * v1446 = v1410->cache_age;
      v1446[v1543] = 0;
      v1492 = v1543;
    } else {
      int * v1449 = v1410->cache_age;
      int v1550 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1)) & 3) * 2);
      int v1450 = v1449[v1550];
      int * v1451 = v1410->cache_tags;
      int v1452 = v1451[v1550];
      int v1453 = v1449[v1528];
      int v1454 = v1451[v1528];
      int * v1455 = v1410->cache_dirty;
      int v1553 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1)) & 3) * 2)) + ((((v1450 + ((~(((v1452 ^ -1) | (-(v1452 ^ -1))) >> 31)) & 2)) - (v1453 + ((~(((v1454 ^ -1) | (-(v1454 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1456 = v1455[v1553];
      bool v1554 = !(v1456 == 0);
      if (v1554) {
        int * v1457 = v1410->cache_tags;
        int v1458 = v1457[v1553];
        int * v1459 = v1410->cache_vals;
        int v1557 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1)) & 3) * 2)) + ((((v1450 + ((~(((v1452 ^ -1) | (-(v1452 ^ -1))) >> 31)) & 2)) - (v1453 + ((~(((v1454 ^ -1) | (-(v1454 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1460 = v1459[v1557];
        int v1558 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1)) & 3) * 2)) + ((((v1450 + ((~(((v1452 ^ -1) | (-(v1452 ^ -1))) >> 31)) & 2)) - (v1453 + ((~(((v1454 ^ -1) | (-(v1454 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1461 = v1459[v1558];
        int * v1462 = v1410->mem;
        int v1560 = v1458 * 2;
        v1462[v1560] = v1460;
        int * v1464 = v1410->mem;
        int v1563 = (v1458 * 2) + 1;
        v1464[v1563] = v1461;
        ;
      } else {
        ;
      }
      int * v1469 = v1410->mem;
      int v1568 = ((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1)) * 2;
      int v1470 = v1469[v1568];
      int v1569 = (((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1)) * 2) + 1;
      int v1471 = v1469[v1569];
      int * v1472 = v1410->cache_vals;
      int v1571 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1)) & 3) * 2)) + ((((v1450 + ((~(((v1452 ^ -1) | (-(v1452 ^ -1))) >> 31)) & 2)) - (v1453 + ((~(((v1454 ^ -1) | (-(v1454 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1472[v1571] = v1470;
      int * v1474 = v1410->cache_vals;
      int v1574 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1)) & 3) * 2)) + ((((v1450 + ((~(((v1452 ^ -1) | (-(v1452 ^ -1))) >> 31)) & 2)) - (v1453 + ((~(((v1454 ^ -1) | (-(v1454 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1474[v1574] = v1471;
      int * v1476 = v1410->cache_tags;
      int v1577 = (int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1);
      v1476[v1553] = v1577;
      int * v1478 = v1410->cache_dirty;
      v1478[v1553] = 0;
      int * v1480 = v1410->cache_age;
      v1480[v1553] = 1;
      int * v1482 = v1410->cache_age;
      int v1483 = v1482[v1553];
      int v1484 = v1482[v1527];
      int v1583 = v1484 + ((int)((unsigned int)(v1484 - v1483) >> 31));
      v1482[v1527] = v1583;
      int * v1486 = v1410->cache_age;
      int v1487 = v1486[v1528];
      int v1585 = v1487 + ((int)((unsigned int)(v1487 - v1483) >> 31));
      v1486[v1528] = v1585;
      int * v1489 = v1410->cache_age;
      v1489[v1553] = 0;
      v1492 = v1553;
    }
    int * v1493 = v1410->cache_vals;
    int v1588 = v1492 * 2;
    int v1494 = v1493[v1588];
    int v1589 = (v1492 * 2) + 1;
    int v1495 = v1493[v1589];
    int v1590 = (((((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1)) & 1) * 2) + ((((v1434 + ((~(((v1436 ^ -1) | (-(v1436 ^ -1))) >> 31)) & 2)) - (v1437 + ((~(((v1438 ^ -1) | (-(v1438 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1493[v1590] = v1494;
    int * v1497 = v1410->cache_vals;
    int v1593 = ((((((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1)) & 1) * 2) + ((((v1434 + ((~(((v1436 ^ -1) | (-(v1436 ^ -1))) >> 31)) & 2)) - (v1437 + ((~(((v1438 ^ -1) | (-(v1438 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1497[v1593] = v1495;
    int * v1499 = v1410->cache_tags;
    int v1596 = ((((int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1)) & 1) * 2) + ((((v1434 + ((~(((v1436 ^ -1) | (-(v1436 ^ -1))) >> 31)) & 2)) - (v1437 + ((~(((v1438 ^ -1) | (-(v1438 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1597 = (int)((unsigned int)((int)((unsigned int)v1414 >> 2)) >> 1);
    v1499[v1596] = v1597;
    int * v1501 = v1410->cache_dirty;
    v1501[v1596] = 0;
    int * v1503 = v1410->cache_age;
    v1503[v1596] = 1;
    int * v1505 = v1410->cache_age;
    int v1506 = v1505[v1596];
    int v1507 = v1505[v1525];
    int v1603 = v1507 + ((int)((unsigned int)(v1507 - v1506) >> 31));
    v1505[v1525] = v1603;
    int * v1509 = v1410->cache_age;
    int v1510 = v1509[v1526];
    int v1605 = v1510 + ((int)((unsigned int)(v1510 - v1506) >> 31));
    v1509[v1526] = v1605;
    int * v1512 = v1410->cache_age;
    v1512[v1596] = 0;
    v1515 = v1596;
  }
  int v1608 = (v1515 * 2) + (((int)((unsigned int)v1414 >> 2)) & 1);
  int v1516 = v1422[v1608];
  int * v1517 = v1410->regs;
  int v1610 = ((int)((unsigned int)v1516 >> ((v1414 & 3) << 3))) & 255;
  v1517[16] = v1610;
  struct StateT * v1519 = slot_38(v1410);
  return v1519;
}

struct StateT * slot_40(struct StateT * v1832) {
  int v1833 = v1832->timer;
  int v1844 = v1833 + 1;
  v1832->timer = v1844;
  int * v1835 = v1832->regs;
  int v1836 = v1835[16];
  bool v1847 = -2147483648 < (v1836 ^ -2147483648);
  int v1839;
  if (v1847) {
    v1839 = 1;
  } else {
    v1839 = 0;
  }
  int * v1840 = v1832->regs;
  v1840[16] = v1839;
  struct StateT * v1842 = slot_41(v1832);
  return v1842;
}

struct StateT * slot_27(struct StateT * v1237) {
  int v1238 = v1237->timer;
  int v1246 = v1238 + 1;
  v1237->timer = v1246;
  int * v1240 = v1237->regs;
  int v1241 = v1240[16];
  int v1242 = v1240[17];
  int v1250 = v1241 ^ v1242;
  v1240[16] = v1250;
  struct StateT * v1244 = slot_28(v1237);
  return v1244;
}

struct StateT * slot_15(struct StateT * v632) {
  int * v633 = v632->saved_regs;
  int * v634 = v632->regs;
  int v635 = v634[13];
  v633[13] = v635;
  int v637 = v632->timer;
  int v648 = v637 + 1;
  v632->timer = v648;
  int * v639 = v632->regs;
  int v640 = v639[13];
  int v650 = v640 + 1;
  v639[13] = v650;
  struct StateT * v642 = slot_16(v632);
  return v642;
}

struct StateT * slot_22(struct StateT * v767) {
  int * v768 = v767->regs;
  int v769 = v768[15];
  int v770 = v768[13];
  bool v786 = (v769 ^ -2147483648) >= (v770 ^ -2147483648);
  struct StateT * v781;
  if (v786) {
    int v771 = v767->timer;
    int v787 = v771 + 15;
    v767->timer = v787;
    int * v773 = v767->saved_regs;
    int v774 = v773[10];
    int * v775 = v767->regs;
    v775[10] = v774;
    struct StateT * v777 = slot_23(v767);
    v781 = v777;
  } else {
    struct StateT * v779 = slot_19(v767);
    v781 = v779;
  }
  return v781;
}

struct StateT * slot_35(struct StateT * v1362) {
  int * v1363 = v1362->saved_regs;
  int * v1364 = v1362->regs;
  int v1365 = v1364[16];
  v1363[16] = v1365;
  int v1367 = v1362->timer;
  int v1379 = v1367 + 1;
  v1362->timer = v1379;
  int * v1369 = v1362->regs;
  int v1370 = v1369[10];
  int v1371 = v1369[13];
  int v1383 = v1370 + v1371;
  v1369[16] = v1383;
  struct StateT * v1373 = slot_36(v1362);
  return v1373;
}

struct StateT * slot_34(struct StateT * v1354) {
  int v1355 = v1354->timer;
  int v1359 = v1355 + 1;
  v1354->timer = v1359;
  struct StateT * v1357 = slot_35(v1354);
  return v1357;
}

struct StateT * slot_25(struct StateT * v831) {
  int v832 = v831->timer;
  int v942 = v832 + 1;
  v831->timer = v942;
  int * v834 = v831->regs;
  int v835 = v834[16];
  int * v836 = v831->cache_tags;
  int v946 = (((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1)) & 1) * 2;
  int v837 = v836[v946];
  int v947 = ((((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1)) & 1) * 2) + 1;
  int v838 = v836[v947];
  int v948 = 4 + ((((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1)) & 3) * 2);
  int v839 = v836[v948];
  int v949 = (4 + ((((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v840 = v836[v949];
  int v841 = v831->timer;
  int v950 = v841 + ((100 ^ (((~(((v839 ^ ((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1))) | (-(v839 ^ ((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1))))) >> 31)) | (~(((v840 ^ ((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1))) | (-(v840 ^ ((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v837 ^ ((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1))) | (-(v837 ^ ((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1))))) >> 31)) | (~(((v838 ^ ((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1))) | (-(v838 ^ ((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v839 ^ ((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1))) | (-(v839 ^ ((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1))))) >> 31)) | (~(((v840 ^ ((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1))) | (-(v840 ^ ((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1))))) >> 31))) & 104)))));
  v831->timer = v950;
  int * v843 = v831->cache_vals;
  bool v951 = !(((~(((v837 ^ ((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1))) | (-(v837 ^ ((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1))))) >> 31)) | (~(((v838 ^ ((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1))) | (-(v838 ^ ((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1))))) >> 31))) == 0);
  int v936;
  if (v951) {
    int * v844 = v831->cache_age;
    int v953 = ((((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1)) & 1) * 2) + ((~(((v838 ^ ((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1))) | (-(v838 ^ ((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1))))) >> 31)) & 1);
    int v845 = v844[v953];
    int v846 = v844[v946];
    int v954 = v846 + ((int)((unsigned int)(v846 - v845) >> 31));
    v844[v946] = v954;
    int * v848 = v831->cache_age;
    int v849 = v848[v947];
    int v956 = v849 + ((int)((unsigned int)(v849 - v845) >> 31));
    v848[v947] = v956;
    int * v851 = v831->cache_age;
    v851[v953] = 0;
    v936 = v953;
  } else {
    int * v854 = v831->cache_age;
    int v960 = (((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1)) & 1) * 2;
    int v855 = v854[v960];
    int * v856 = v831->cache_tags;
    int v857 = v856[v960];
    int v858 = v854[v947];
    int v859 = v856[v947];
    bool v962 = !(((~(((v839 ^ ((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1))) | (-(v839 ^ ((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1))))) >> 31)) | (~(((v840 ^ ((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1))) | (-(v840 ^ ((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1))))) >> 31))) == 0);
    int v913;
    if (v962) {
      int * v860 = v831->cache_age;
      int v964 = (4 + ((((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1)) & 3) * 2)) + ((~(((v840 ^ ((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1))) | (-(v840 ^ ((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1))))) >> 31)) & 1);
      int v861 = v860[v964];
      int v862 = v860[v948];
      int v965 = v862 + ((int)((unsigned int)(v862 - v861) >> 31));
      v860[v948] = v965;
      int * v864 = v831->cache_age;
      int v865 = v864[v949];
      int v967 = v865 + ((int)((unsigned int)(v865 - v861) >> 31));
      v864[v949] = v967;
      int * v867 = v831->cache_age;
      v867[v964] = 0;
      v913 = v964;
    } else {
      int * v870 = v831->cache_age;
      int v971 = 4 + ((((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1)) & 3) * 2);
      int v871 = v870[v971];
      int * v872 = v831->cache_tags;
      int v873 = v872[v971];
      int v874 = v870[v949];
      int v875 = v872[v949];
      int * v876 = v831->cache_dirty;
      int v974 = (4 + ((((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1)) & 3) * 2)) + ((((v871 + ((~(((v873 ^ -1) | (-(v873 ^ -1))) >> 31)) & 2)) - (v874 + ((~(((v875 ^ -1) | (-(v875 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v877 = v876[v974];
      bool v975 = !(v877 == 0);
      if (v975) {
        int * v878 = v831->cache_tags;
        int v879 = v878[v974];
        int * v880 = v831->cache_vals;
        int v978 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1)) & 3) * 2)) + ((((v871 + ((~(((v873 ^ -1) | (-(v873 ^ -1))) >> 31)) & 2)) - (v874 + ((~(((v875 ^ -1) | (-(v875 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v881 = v880[v978];
        int v979 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1)) & 3) * 2)) + ((((v871 + ((~(((v873 ^ -1) | (-(v873 ^ -1))) >> 31)) & 2)) - (v874 + ((~(((v875 ^ -1) | (-(v875 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v882 = v880[v979];
        int * v883 = v831->mem;
        int v981 = v879 * 2;
        v883[v981] = v881;
        int * v885 = v831->mem;
        int v984 = (v879 * 2) + 1;
        v885[v984] = v882;
        ;
      } else {
        ;
      }
      int * v890 = v831->mem;
      int v989 = ((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1)) * 2;
      int v891 = v890[v989];
      int v990 = (((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1)) * 2) + 1;
      int v892 = v890[v990];
      int * v893 = v831->cache_vals;
      int v992 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1)) & 3) * 2)) + ((((v871 + ((~(((v873 ^ -1) | (-(v873 ^ -1))) >> 31)) & 2)) - (v874 + ((~(((v875 ^ -1) | (-(v875 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v893[v992] = v891;
      int * v895 = v831->cache_vals;
      int v995 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1)) & 3) * 2)) + ((((v871 + ((~(((v873 ^ -1) | (-(v873 ^ -1))) >> 31)) & 2)) - (v874 + ((~(((v875 ^ -1) | (-(v875 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v895[v995] = v892;
      int * v897 = v831->cache_tags;
      int v998 = (int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1);
      v897[v974] = v998;
      int * v899 = v831->cache_dirty;
      v899[v974] = 0;
      int * v901 = v831->cache_age;
      v901[v974] = 1;
      int * v903 = v831->cache_age;
      int v904 = v903[v974];
      int v905 = v903[v948];
      int v1004 = v905 + ((int)((unsigned int)(v905 - v904) >> 31));
      v903[v948] = v1004;
      int * v907 = v831->cache_age;
      int v908 = v907[v949];
      int v1006 = v908 + ((int)((unsigned int)(v908 - v904) >> 31));
      v907[v949] = v1006;
      int * v910 = v831->cache_age;
      v910[v974] = 0;
      v913 = v974;
    }
    int * v914 = v831->cache_vals;
    int v1009 = v913 * 2;
    int v915 = v914[v1009];
    int v1010 = (v913 * 2) + 1;
    int v916 = v914[v1010];
    int v1011 = (((((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1)) & 1) * 2) + ((((v855 + ((~(((v857 ^ -1) | (-(v857 ^ -1))) >> 31)) & 2)) - (v858 + ((~(((v859 ^ -1) | (-(v859 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v914[v1011] = v915;
    int * v918 = v831->cache_vals;
    int v1014 = ((((((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1)) & 1) * 2) + ((((v855 + ((~(((v857 ^ -1) | (-(v857 ^ -1))) >> 31)) & 2)) - (v858 + ((~(((v859 ^ -1) | (-(v859 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v918[v1014] = v916;
    int * v920 = v831->cache_tags;
    int v1017 = ((((int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1)) & 1) * 2) + ((((v855 + ((~(((v857 ^ -1) | (-(v857 ^ -1))) >> 31)) & 2)) - (v858 + ((~(((v859 ^ -1) | (-(v859 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1018 = (int)((unsigned int)((int)((unsigned int)v835 >> 2)) >> 1);
    v920[v1017] = v1018;
    int * v922 = v831->cache_dirty;
    v922[v1017] = 0;
    int * v924 = v831->cache_age;
    v924[v1017] = 1;
    int * v926 = v831->cache_age;
    int v927 = v926[v1017];
    int v928 = v926[v946];
    int v1024 = v928 + ((int)((unsigned int)(v928 - v927) >> 31));
    v926[v946] = v1024;
    int * v930 = v831->cache_age;
    int v931 = v930[v947];
    int v1026 = v931 + ((int)((unsigned int)(v931 - v927) >> 31));
    v930[v947] = v1026;
    int * v933 = v831->cache_age;
    v933[v1017] = 0;
    v936 = v1017;
  }
  int v1029 = (v936 * 2) + (((int)((unsigned int)v835 >> 2)) & 1);
  int v937 = v843[v1029];
  int * v938 = v831->regs;
  int v1031 = ((int)((unsigned int)v937 >> ((v835 & 3) << 3))) & 255;
  v938[16] = v1031;
  struct StateT * v940 = slot_26(v831);
  return v940;
}

struct StateT * slot_23(struct StateT * v797) {
  int v798 = v797->timer;
  int v806 = v798 + 1;
  v797->timer = v806;
  int * v800 = v797->regs;
  int v801 = v800[10];
  int v802 = v800[13];
  int v811 = v801 + v802;
  v800[16] = v811;
  struct StateT * v804 = slot_24(v797);
  return v804;
}

struct StateT * slot_2(struct StateT * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[14] = 1;
  struct StateT * v33 = slot_3(v28);
  return v33;
}

struct StateT * slot_3(struct StateT * v41) {
  int v42 = v41->timer;
  int v48 = v42 + 1;
  v41->timer = v48;
  int * v44 = v41->regs;
  v44[15] = 15;
  struct StateT * v46 = slot_4(v41);
  return v46;
}

struct StateT * slot_45(struct StateT * v1933) {
  int * v1934 = v1933->saved_regs;
  int * v1935 = v1933->regs;
  int v1936 = v1935[13];
  v1934[13] = v1936;
  int v1938 = v1933->timer;
  int v1949 = v1938 + 1;
  v1933->timer = v1949;
  int * v1940 = v1933->regs;
  int v1941 = v1940[13];
  int v1951 = v1941 + 1;
  v1940[13] = v1951;
  struct StateT * v1943 = slot_46(v1933);
  return v1943;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v22 = v16 + 1;
  v15->timer = v22;
  int * v18 = v15->regs;
  v18[13] = 0;
  struct StateT * v20 = slot_2(v15);
  return v20;
}

struct StateT * slot_13(struct StateT * v586) {
  int * v587 = v586->saved_regs;
  int * v588 = v586->regs;
  int v589 = v588[14];
  v587[14] = v589;
  int v591 = v586->timer;
  int v603 = v591 + 1;
  v586->timer = v603;
  int * v593 = v586->regs;
  int v594 = v593[14];
  int v595 = v593[16];
  int v606 = v594 ^ v595;
  v593[14] = v606;
  struct StateT * v597 = slot_14(v586);
  return v597;
}

struct StateT * slot_38(struct StateT * v1613) {
  int v1614 = v1613->timer;
  int v1724 = v1614 + 1;
  v1613->timer = v1724;
  int * v1616 = v1613->regs;
  int v1617 = v1616[17];
  int * v1618 = v1613->cache_tags;
  int v1728 = (((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1)) & 1) * 2;
  int v1619 = v1618[v1728];
  int v1729 = ((((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1620 = v1618[v1729];
  int v1730 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1)) & 3) * 2);
  int v1621 = v1618[v1730];
  int v1731 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1622 = v1618[v1731];
  int v1623 = v1613->timer;
  int v1732 = v1623 + ((100 ^ (((~(((v1621 ^ ((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1))) | (-(v1621 ^ ((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1))))) >> 31)) | (~(((v1622 ^ ((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1))) | (-(v1622 ^ ((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1619 ^ ((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1))) | (-(v1619 ^ ((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1))))) >> 31)) | (~(((v1620 ^ ((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1))) | (-(v1620 ^ ((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1621 ^ ((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1))) | (-(v1621 ^ ((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1))))) >> 31)) | (~(((v1622 ^ ((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1))) | (-(v1622 ^ ((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1613->timer = v1732;
  int * v1625 = v1613->cache_vals;
  bool v1733 = !(((~(((v1619 ^ ((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1))) | (-(v1619 ^ ((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1))))) >> 31)) | (~(((v1620 ^ ((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1))) | (-(v1620 ^ ((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1))))) >> 31))) == 0);
  int v1718;
  if (v1733) {
    int * v1626 = v1613->cache_age;
    int v1735 = ((((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1)) & 1) * 2) + ((~(((v1620 ^ ((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1))) | (-(v1620 ^ ((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1))))) >> 31)) & 1);
    int v1627 = v1626[v1735];
    int v1628 = v1626[v1728];
    int v1736 = v1628 + ((int)((unsigned int)(v1628 - v1627) >> 31));
    v1626[v1728] = v1736;
    int * v1630 = v1613->cache_age;
    int v1631 = v1630[v1729];
    int v1738 = v1631 + ((int)((unsigned int)(v1631 - v1627) >> 31));
    v1630[v1729] = v1738;
    int * v1633 = v1613->cache_age;
    v1633[v1735] = 0;
    v1718 = v1735;
  } else {
    int * v1636 = v1613->cache_age;
    int v1742 = (((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1)) & 1) * 2;
    int v1637 = v1636[v1742];
    int * v1638 = v1613->cache_tags;
    int v1639 = v1638[v1742];
    int v1640 = v1636[v1729];
    int v1641 = v1638[v1729];
    bool v1744 = !(((~(((v1621 ^ ((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1))) | (-(v1621 ^ ((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1))))) >> 31)) | (~(((v1622 ^ ((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1))) | (-(v1622 ^ ((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1))))) >> 31))) == 0);
    int v1695;
    if (v1744) {
      int * v1642 = v1613->cache_age;
      int v1746 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1622 ^ ((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1))) | (-(v1622 ^ ((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1))))) >> 31)) & 1);
      int v1643 = v1642[v1746];
      int v1644 = v1642[v1730];
      int v1747 = v1644 + ((int)((unsigned int)(v1644 - v1643) >> 31));
      v1642[v1730] = v1747;
      int * v1646 = v1613->cache_age;
      int v1647 = v1646[v1731];
      int v1749 = v1647 + ((int)((unsigned int)(v1647 - v1643) >> 31));
      v1646[v1731] = v1749;
      int * v1649 = v1613->cache_age;
      v1649[v1746] = 0;
      v1695 = v1746;
    } else {
      int * v1652 = v1613->cache_age;
      int v1753 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1)) & 3) * 2);
      int v1653 = v1652[v1753];
      int * v1654 = v1613->cache_tags;
      int v1655 = v1654[v1753];
      int v1656 = v1652[v1731];
      int v1657 = v1654[v1731];
      int * v1658 = v1613->cache_dirty;
      int v1756 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1)) & 3) * 2)) + ((((v1653 + ((~(((v1655 ^ -1) | (-(v1655 ^ -1))) >> 31)) & 2)) - (v1656 + ((~(((v1657 ^ -1) | (-(v1657 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1659 = v1658[v1756];
      bool v1757 = !(v1659 == 0);
      if (v1757) {
        int * v1660 = v1613->cache_tags;
        int v1661 = v1660[v1756];
        int * v1662 = v1613->cache_vals;
        int v1760 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1)) & 3) * 2)) + ((((v1653 + ((~(((v1655 ^ -1) | (-(v1655 ^ -1))) >> 31)) & 2)) - (v1656 + ((~(((v1657 ^ -1) | (-(v1657 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1663 = v1662[v1760];
        int v1761 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1)) & 3) * 2)) + ((((v1653 + ((~(((v1655 ^ -1) | (-(v1655 ^ -1))) >> 31)) & 2)) - (v1656 + ((~(((v1657 ^ -1) | (-(v1657 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1664 = v1662[v1761];
        int * v1665 = v1613->mem;
        int v1763 = v1661 * 2;
        v1665[v1763] = v1663;
        int * v1667 = v1613->mem;
        int v1766 = (v1661 * 2) + 1;
        v1667[v1766] = v1664;
        ;
      } else {
        ;
      }
      int * v1672 = v1613->mem;
      int v1771 = ((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1)) * 2;
      int v1673 = v1672[v1771];
      int v1772 = (((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1)) * 2) + 1;
      int v1674 = v1672[v1772];
      int * v1675 = v1613->cache_vals;
      int v1774 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1)) & 3) * 2)) + ((((v1653 + ((~(((v1655 ^ -1) | (-(v1655 ^ -1))) >> 31)) & 2)) - (v1656 + ((~(((v1657 ^ -1) | (-(v1657 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1675[v1774] = v1673;
      int * v1677 = v1613->cache_vals;
      int v1777 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1)) & 3) * 2)) + ((((v1653 + ((~(((v1655 ^ -1) | (-(v1655 ^ -1))) >> 31)) & 2)) - (v1656 + ((~(((v1657 ^ -1) | (-(v1657 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1677[v1777] = v1674;
      int * v1679 = v1613->cache_tags;
      int v1780 = (int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1);
      v1679[v1756] = v1780;
      int * v1681 = v1613->cache_dirty;
      v1681[v1756] = 0;
      int * v1683 = v1613->cache_age;
      v1683[v1756] = 1;
      int * v1685 = v1613->cache_age;
      int v1686 = v1685[v1756];
      int v1687 = v1685[v1730];
      int v1786 = v1687 + ((int)((unsigned int)(v1687 - v1686) >> 31));
      v1685[v1730] = v1786;
      int * v1689 = v1613->cache_age;
      int v1690 = v1689[v1731];
      int v1788 = v1690 + ((int)((unsigned int)(v1690 - v1686) >> 31));
      v1689[v1731] = v1788;
      int * v1692 = v1613->cache_age;
      v1692[v1756] = 0;
      v1695 = v1756;
    }
    int * v1696 = v1613->cache_vals;
    int v1791 = v1695 * 2;
    int v1697 = v1696[v1791];
    int v1792 = (v1695 * 2) + 1;
    int v1698 = v1696[v1792];
    int v1793 = (((((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1)) & 1) * 2) + ((((v1637 + ((~(((v1639 ^ -1) | (-(v1639 ^ -1))) >> 31)) & 2)) - (v1640 + ((~(((v1641 ^ -1) | (-(v1641 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1696[v1793] = v1697;
    int * v1700 = v1613->cache_vals;
    int v1796 = ((((((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1)) & 1) * 2) + ((((v1637 + ((~(((v1639 ^ -1) | (-(v1639 ^ -1))) >> 31)) & 2)) - (v1640 + ((~(((v1641 ^ -1) | (-(v1641 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1700[v1796] = v1698;
    int * v1702 = v1613->cache_tags;
    int v1799 = ((((int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1)) & 1) * 2) + ((((v1637 + ((~(((v1639 ^ -1) | (-(v1639 ^ -1))) >> 31)) & 2)) - (v1640 + ((~(((v1641 ^ -1) | (-(v1641 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1800 = (int)((unsigned int)((int)((unsigned int)v1617 >> 2)) >> 1);
    v1702[v1799] = v1800;
    int * v1704 = v1613->cache_dirty;
    v1704[v1799] = 0;
    int * v1706 = v1613->cache_age;
    v1706[v1799] = 1;
    int * v1708 = v1613->cache_age;
    int v1709 = v1708[v1799];
    int v1710 = v1708[v1728];
    int v1806 = v1710 + ((int)((unsigned int)(v1710 - v1709) >> 31));
    v1708[v1728] = v1806;
    int * v1712 = v1613->cache_age;
    int v1713 = v1712[v1729];
    int v1808 = v1713 + ((int)((unsigned int)(v1713 - v1709) >> 31));
    v1712[v1729] = v1808;
    int * v1715 = v1613->cache_age;
    v1715[v1799] = 0;
    v1718 = v1799;
  }
  int v1811 = (v1718 * 2) + (((int)((unsigned int)v1617 >> 2)) & 1);
  int v1719 = v1625[v1811];
  int * v1720 = v1613->regs;
  int v1813 = ((int)((unsigned int)v1719 >> ((v1617 & 3) << 3))) & 255;
  v1720[17] = v1813;
  struct StateT * v1722 = slot_39(v1613);
  return v1722;
}

struct StateT * slot_24(struct StateT * v814) {
  int v815 = v814->timer;
  int v823 = v815 + 1;
  v814->timer = v823;
  int * v817 = v814->regs;
  int v818 = v817[11];
  int v819 = v817[13];
  int v828 = v818 + v819;
  v817[17] = v828;
  struct StateT * v821 = slot_25(v814);
  return v821;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[12] = 0;
  struct StateT * v7 = slot_1(v2);
  return v7;
}

struct StateT * slot_42(struct StateT * v1870) {
  int v1871 = v1870->timer;
  int v1879 = v1871 + 1;
  v1870->timer = v1879;
  int * v1873 = v1870->regs;
  int v1874 = v1873[16];
  int v1875 = v1873[12];
  int v1884 = v1874 & v1875;
  v1873[17] = v1884;
  struct StateT * v1877 = slot_43(v1870);
  return v1877;
}

struct StateT * slot_46(struct StateT * v1954) {
  int * v1955 = v1954->regs;
  int v1956 = v1955[15];
  int * v1957 = v1954->saved_regs;
  int v1958 = v1957[13];
  bool v1991 = (v1956 ^ -2147483648) >= (v1958 ^ -2147483648);
  struct StateT * v1985;
  if (v1991) {
    struct StateT * v1959 = slot_34(v1954);
    v1985 = v1959;
  } else {
    int v1961 = v1954->timer;
    int v1994 = v1961 + 15;
    v1954->timer = v1994;
    int * v1963 = v1954->saved_regs;
    int v1964 = v1963[16];
    int * v1965 = v1954->regs;
    v1965[16] = v1964;
    int * v1967 = v1954->saved_regs;
    int v1968 = v1967[17];
    int * v1969 = v1954->regs;
    v1969[17] = v1968;
    int * v1971 = v1954->saved_regs;
    int v1972 = v1971[14];
    int * v1973 = v1954->regs;
    v1973[14] = v1972;
    int * v1975 = v1954->saved_regs;
    int v1976 = v1975[12];
    int * v1977 = v1954->regs;
    v1977[12] = v1976;
    int * v1979 = v1954->saved_regs;
    int v1980 = v1979[13];
    int * v1981 = v1954->regs;
    v1981[13] = v1980;
    struct StateT * v1983 = slot_17(v1954);
    v1985 = v1983;
  }
  return v1985;
}

struct StateT * slot_20(struct StateT * v743) {
  int * v744 = v743->saved_regs;
  int * v745 = v743->regs;
  int v746 = v745[10];
  v744[10] = v746;
  int v748 = v743->timer;
  int v760 = v748 + 1;
  v743->timer = v760;
  int * v750 = v743->regs;
  int v751 = v750[14];
  int v752 = v750[12];
  int v764 = v751 | v752;
  v750[10] = v764;
  struct StateT * v754 = slot_22(v743);
  return v754;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_41(struct StateT * v1854) {
  int v1855 = v1854->timer;
  int v1863 = v1855 + 1;
  v1854->timer = v1863;
  int * v1857 = v1854->regs;
  int v1858 = v1857[16];
  int v1859 = v1857[14];
  int v1867 = v1858 & v1859;
  v1857[16] = v1867;
  struct StateT * v1861 = slot_42(v1854);
  return v1861;
}

struct StateT * slot_39(struct StateT * v1816) {
  int v1817 = v1816->timer;
  int v1825 = v1817 + 1;
  v1816->timer = v1825;
  int * v1819 = v1816->regs;
  int v1820 = v1819[16];
  int v1821 = v1819[17];
  int v1829 = v1820 ^ v1821;
  v1819[16] = v1829;
  struct StateT * v1823 = slot_40(v1816);
  return v1823;
}

struct StateT * slot_8(struct StateT * v312) {
  int v313 = v312->timer;
  int v423 = v313 + 1;
  v312->timer = v423;
  int * v315 = v312->regs;
  int v316 = v315[17];
  int * v317 = v312->cache_tags;
  int v427 = (((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1)) & 1) * 2;
  int v318 = v317[v427];
  int v428 = ((((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1)) & 1) * 2) + 1;
  int v319 = v317[v428];
  int v429 = 4 + ((((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1)) & 3) * 2);
  int v320 = v317[v429];
  int v430 = (4 + ((((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v321 = v317[v430];
  int v322 = v312->timer;
  int v431 = v322 + ((100 ^ (((~(((v320 ^ ((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1))) | (-(v320 ^ ((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1))))) >> 31)) | (~(((v321 ^ ((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1))) | (-(v321 ^ ((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v318 ^ ((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1))) | (-(v318 ^ ((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1))))) >> 31)) | (~(((v319 ^ ((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1))) | (-(v319 ^ ((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v320 ^ ((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1))) | (-(v320 ^ ((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1))))) >> 31)) | (~(((v321 ^ ((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1))) | (-(v321 ^ ((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1))))) >> 31))) & 104)))));
  v312->timer = v431;
  int * v324 = v312->cache_vals;
  bool v432 = !(((~(((v318 ^ ((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1))) | (-(v318 ^ ((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1))))) >> 31)) | (~(((v319 ^ ((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1))) | (-(v319 ^ ((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1))))) >> 31))) == 0);
  int v417;
  if (v432) {
    int * v325 = v312->cache_age;
    int v434 = ((((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1)) & 1) * 2) + ((~(((v319 ^ ((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1))) | (-(v319 ^ ((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1))))) >> 31)) & 1);
    int v326 = v325[v434];
    int v327 = v325[v427];
    int v435 = v327 + ((int)((unsigned int)(v327 - v326) >> 31));
    v325[v427] = v435;
    int * v329 = v312->cache_age;
    int v330 = v329[v428];
    int v437 = v330 + ((int)((unsigned int)(v330 - v326) >> 31));
    v329[v428] = v437;
    int * v332 = v312->cache_age;
    v332[v434] = 0;
    v417 = v434;
  } else {
    int * v335 = v312->cache_age;
    int v441 = (((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1)) & 1) * 2;
    int v336 = v335[v441];
    int * v337 = v312->cache_tags;
    int v338 = v337[v441];
    int v339 = v335[v428];
    int v340 = v337[v428];
    bool v443 = !(((~(((v320 ^ ((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1))) | (-(v320 ^ ((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1))))) >> 31)) | (~(((v321 ^ ((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1))) | (-(v321 ^ ((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1))))) >> 31))) == 0);
    int v394;
    if (v443) {
      int * v341 = v312->cache_age;
      int v445 = (4 + ((((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1)) & 3) * 2)) + ((~(((v321 ^ ((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1))) | (-(v321 ^ ((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1))))) >> 31)) & 1);
      int v342 = v341[v445];
      int v343 = v341[v429];
      int v446 = v343 + ((int)((unsigned int)(v343 - v342) >> 31));
      v341[v429] = v446;
      int * v345 = v312->cache_age;
      int v346 = v345[v430];
      int v448 = v346 + ((int)((unsigned int)(v346 - v342) >> 31));
      v345[v430] = v448;
      int * v348 = v312->cache_age;
      v348[v445] = 0;
      v394 = v445;
    } else {
      int * v351 = v312->cache_age;
      int v452 = 4 + ((((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1)) & 3) * 2);
      int v352 = v351[v452];
      int * v353 = v312->cache_tags;
      int v354 = v353[v452];
      int v355 = v351[v430];
      int v356 = v353[v430];
      int * v357 = v312->cache_dirty;
      int v455 = (4 + ((((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1)) & 3) * 2)) + ((((v352 + ((~(((v354 ^ -1) | (-(v354 ^ -1))) >> 31)) & 2)) - (v355 + ((~(((v356 ^ -1) | (-(v356 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v358 = v357[v455];
      bool v456 = !(v358 == 0);
      if (v456) {
        int * v359 = v312->cache_tags;
        int v360 = v359[v455];
        int * v361 = v312->cache_vals;
        int v459 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1)) & 3) * 2)) + ((((v352 + ((~(((v354 ^ -1) | (-(v354 ^ -1))) >> 31)) & 2)) - (v355 + ((~(((v356 ^ -1) | (-(v356 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v362 = v361[v459];
        int v460 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1)) & 3) * 2)) + ((((v352 + ((~(((v354 ^ -1) | (-(v354 ^ -1))) >> 31)) & 2)) - (v355 + ((~(((v356 ^ -1) | (-(v356 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v363 = v361[v460];
        int * v364 = v312->mem;
        int v462 = v360 * 2;
        v364[v462] = v362;
        int * v366 = v312->mem;
        int v465 = (v360 * 2) + 1;
        v366[v465] = v363;
        ;
      } else {
        ;
      }
      int * v371 = v312->mem;
      int v470 = ((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1)) * 2;
      int v372 = v371[v470];
      int v471 = (((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1)) * 2) + 1;
      int v373 = v371[v471];
      int * v374 = v312->cache_vals;
      int v473 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1)) & 3) * 2)) + ((((v352 + ((~(((v354 ^ -1) | (-(v354 ^ -1))) >> 31)) & 2)) - (v355 + ((~(((v356 ^ -1) | (-(v356 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v374[v473] = v372;
      int * v376 = v312->cache_vals;
      int v476 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1)) & 3) * 2)) + ((((v352 + ((~(((v354 ^ -1) | (-(v354 ^ -1))) >> 31)) & 2)) - (v355 + ((~(((v356 ^ -1) | (-(v356 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v376[v476] = v373;
      int * v378 = v312->cache_tags;
      int v479 = (int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1);
      v378[v455] = v479;
      int * v380 = v312->cache_dirty;
      v380[v455] = 0;
      int * v382 = v312->cache_age;
      v382[v455] = 1;
      int * v384 = v312->cache_age;
      int v385 = v384[v455];
      int v386 = v384[v429];
      int v485 = v386 + ((int)((unsigned int)(v386 - v385) >> 31));
      v384[v429] = v485;
      int * v388 = v312->cache_age;
      int v389 = v388[v430];
      int v487 = v389 + ((int)((unsigned int)(v389 - v385) >> 31));
      v388[v430] = v487;
      int * v391 = v312->cache_age;
      v391[v455] = 0;
      v394 = v455;
    }
    int * v395 = v312->cache_vals;
    int v490 = v394 * 2;
    int v396 = v395[v490];
    int v491 = (v394 * 2) + 1;
    int v397 = v395[v491];
    int v492 = (((((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1)) & 1) * 2) + ((((v336 + ((~(((v338 ^ -1) | (-(v338 ^ -1))) >> 31)) & 2)) - (v339 + ((~(((v340 ^ -1) | (-(v340 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v395[v492] = v396;
    int * v399 = v312->cache_vals;
    int v495 = ((((((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1)) & 1) * 2) + ((((v336 + ((~(((v338 ^ -1) | (-(v338 ^ -1))) >> 31)) & 2)) - (v339 + ((~(((v340 ^ -1) | (-(v340 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v399[v495] = v397;
    int * v401 = v312->cache_tags;
    int v498 = ((((int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1)) & 1) * 2) + ((((v336 + ((~(((v338 ^ -1) | (-(v338 ^ -1))) >> 31)) & 2)) - (v339 + ((~(((v340 ^ -1) | (-(v340 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v499 = (int)((unsigned int)((int)((unsigned int)v316 >> 2)) >> 1);
    v401[v498] = v499;
    int * v403 = v312->cache_dirty;
    v403[v498] = 0;
    int * v405 = v312->cache_age;
    v405[v498] = 1;
    int * v407 = v312->cache_age;
    int v408 = v407[v498];
    int v409 = v407[v427];
    int v505 = v409 + ((int)((unsigned int)(v409 - v408) >> 31));
    v407[v427] = v505;
    int * v411 = v312->cache_age;
    int v412 = v411[v428];
    int v507 = v412 + ((int)((unsigned int)(v412 - v408) >> 31));
    v411[v428] = v507;
    int * v414 = v312->cache_age;
    v414[v498] = 0;
    v417 = v498;
  }
  int v510 = (v417 * 2) + (((int)((unsigned int)v316 >> 2)) & 1);
  int v418 = v324[v510];
  int * v419 = v312->regs;
  int v512 = ((int)((unsigned int)v418 >> ((v316 & 3) << 3))) & 255;
  v419[17] = v512;
  struct StateT * v421 = slot_9(v312);
  return v421;
}

struct StateT * slot_30(struct StateT * v1291) {
  int v1292 = v1291->timer;
  int v1300 = v1292 + 1;
  v1291->timer = v1300;
  int * v1294 = v1291->regs;
  int v1295 = v1294[16];
  int v1296 = v1294[12];
  int v1305 = v1295 & v1296;
  v1294[17] = v1305;
  struct StateT * v1298 = slot_31(v1291);
  return v1298;
}

struct StateT * slot_4(struct StateT * v53) {
  int v54 = v53->timer;
  int v58 = v54 + 1;
  v53->timer = v58;
  struct StateT * v56 = slot_5(v53);
  return v56;
}

struct StateT * slot_18(struct StateT * v730) {
  int v731 = v730->timer;
  int v735 = v731 + 1;
  v730->timer = v735;
  struct StateT * v733 = slot_20(v730);
  return v733;
}

struct StateT * slot_9(struct StateT * v515) {
  int v516 = v515->timer;
  int v524 = v516 + 1;
  v515->timer = v524;
  int * v518 = v515->regs;
  int v519 = v518[16];
  int v520 = v518[17];
  int v528 = v519 ^ v520;
  v518[16] = v528;
  struct StateT * v522 = slot_10(v515);
  return v522;
}

struct StateT * slot_11(struct StateT * v553) {
  int v554 = v553->timer;
  int v562 = v554 + 1;
  v553->timer = v562;
  int * v556 = v553->regs;
  int v557 = v556[16];
  int v558 = v556[14];
  int v566 = v557 & v558;
  v556[16] = v566;
  struct StateT * v560 = slot_12(v553);
  return v560;
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
  
  // a10, 4 words read by the callee: the address is public
  s1.regs[10] = 0;
  s2.regs[10] = 0;
  // a11, 4 words read by the callee: the address is public
  s1.regs[11] = 16;
  s2.regs[11] = 16;
  
  // a10's contents, secret: a different draw in each state
  for (int i=0; i<4; i++) {
    s1.mem[0 + i] = secret(0, 20);
    s2.mem[0 + i] = secret(0, 20);
  }
  // a11's contents, secret: a different draw in each state
  for (int i=0; i<4; i++) {
    s1.mem[4 + i] = secret(0, 20);
    s2.mem[4 + i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}