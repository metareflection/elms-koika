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

struct StateT * slot_12(struct StateT * v569);
struct StateT * slot_43(struct StateT * v1859);
struct StateT * slot_6(struct StateT * v85);
struct StateT * slot_47(struct StateT * v1938);
struct StateT * slot_29(struct StateT * v1242);
struct StateT * slot_16(struct StateT * v653);
struct StateT * slot_5(struct StateT * v61);
struct StateT * slot_7(struct StateT * v109);
struct StateT * slot_31(struct StateT * v1280);
struct StateT * slot_10(struct StateT * v531);
struct StateT * slot_19(struct StateT * v738);
struct StateT * slot_14(struct StateT * v609);
struct StateT * slot_44(struct StateT * v1875);
struct StateT * slot_28(struct StateT * v1039);
struct StateT * slot_32(struct StateT * v1296);
struct StateT * slot_17(struct StateT * v713);
struct StateT * slot_33(struct StateT * v1313);
struct StateT * slot_36(struct StateT * v1359);
struct StateT * slot_37(struct StateT * v1367);
struct StateT * slot_40(struct StateT * v1618);
struct StateT * slot_27(struct StateT * v836);
struct StateT * slot_15(struct StateT * v632);
struct StateT * slot_48(struct StateT * v1959);
struct StateT * slot_22(struct StateT * v767);
struct StateT * slot_35(struct StateT * v1345);
struct StateT * slot_34(struct StateT * v1329);
struct StateT * slot_25(struct StateT * v819);
struct StateT * slot_23(struct StateT * v797);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_3(struct StateT * v41);
struct StateT * slot_45(struct StateT * v1892);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_13(struct StateT * v586);
struct StateT * slot_38(struct StateT * v1391);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_42(struct StateT * v1837);
struct StateT * slot_46(struct StateT * v1915);
struct StateT * slot_20(struct StateT * v743);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_41(struct StateT * v1821);
struct StateT * slot_39(struct StateT * v1415);
struct StateT * slot_8(struct StateT * v312);
struct StateT * slot_30(struct StateT * v1258);
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

struct StateT * slot_43(struct StateT * v1859) {
  int v1860 = v1859->timer;
  int v1868 = v1860 + 1;
  v1859->timer = v1868;
  int * v1862 = v1859->regs;
  int v1863 = v1862[16];
  int v1864 = v1862[14];
  int v1872 = v1863 & v1864;
  v1862[16] = v1872;
  struct StateT * v1866 = slot_44(v1859);
  return v1866;
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

struct StateT * slot_47(struct StateT * v1938) {
  int * v1939 = v1938->saved_regs;
  int * v1940 = v1938->regs;
  int v1941 = v1940[13];
  v1939[13] = v1941;
  int v1943 = v1938->timer;
  int v1954 = v1943 + 1;
  v1938->timer = v1954;
  int * v1945 = v1938->regs;
  int v1946 = v1945[13];
  int v1956 = v1946 + 1;
  v1945[13] = v1956;
  struct StateT * v1948 = slot_48(v1938);
  return v1948;
}

struct StateT * slot_29(struct StateT * v1242) {
  int v1243 = v1242->timer;
  int v1251 = v1243 + 1;
  v1242->timer = v1251;
  int * v1245 = v1242->regs;
  int v1246 = v1245[16];
  int v1247 = v1245[17];
  int v1255 = v1246 ^ v1247;
  v1245[16] = v1255;
  struct StateT * v1249 = slot_30(v1242);
  return v1249;
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

struct StateT * slot_31(struct StateT * v1280) {
  int v1281 = v1280->timer;
  int v1289 = v1281 + 1;
  v1280->timer = v1289;
  int * v1283 = v1280->regs;
  int v1284 = v1283[16];
  int v1285 = v1283[14];
  int v1293 = v1284 & v1285;
  v1283[16] = v1293;
  struct StateT * v1287 = slot_32(v1280);
  return v1287;
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

struct StateT * slot_44(struct StateT * v1875) {
  int v1876 = v1875->timer;
  int v1884 = v1876 + 1;
  v1875->timer = v1884;
  int * v1878 = v1875->regs;
  int v1879 = v1878[16];
  int v1880 = v1878[12];
  int v1889 = v1879 & v1880;
  v1878[17] = v1889;
  struct StateT * v1882 = slot_45(v1875);
  return v1882;
}

struct StateT * slot_28(struct StateT * v1039) {
  int v1040 = v1039->timer;
  int v1150 = v1040 + 1;
  v1039->timer = v1150;
  int * v1042 = v1039->regs;
  int v1043 = v1042[17];
  int * v1044 = v1039->cache_tags;
  int v1154 = (((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1)) & 1) * 2;
  int v1045 = v1044[v1154];
  int v1155 = ((((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1046 = v1044[v1155];
  int v1156 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1)) & 3) * 2);
  int v1047 = v1044[v1156];
  int v1157 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1048 = v1044[v1157];
  int v1049 = v1039->timer;
  int v1158 = v1049 + ((100 ^ (((~(((v1047 ^ ((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1))) | (-(v1047 ^ ((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1))))) >> 31)) | (~(((v1048 ^ ((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1))) | (-(v1048 ^ ((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1045 ^ ((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1))) | (-(v1045 ^ ((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1))))) >> 31)) | (~(((v1046 ^ ((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1))) | (-(v1046 ^ ((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1047 ^ ((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1))) | (-(v1047 ^ ((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1))))) >> 31)) | (~(((v1048 ^ ((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1))) | (-(v1048 ^ ((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1039->timer = v1158;
  int * v1051 = v1039->cache_vals;
  bool v1159 = !(((~(((v1045 ^ ((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1))) | (-(v1045 ^ ((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1))))) >> 31)) | (~(((v1046 ^ ((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1))) | (-(v1046 ^ ((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1))))) >> 31))) == 0);
  int v1144;
  if (v1159) {
    int * v1052 = v1039->cache_age;
    int v1161 = ((((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1)) & 1) * 2) + ((~(((v1046 ^ ((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1))) | (-(v1046 ^ ((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1))))) >> 31)) & 1);
    int v1053 = v1052[v1161];
    int v1054 = v1052[v1154];
    int v1162 = v1054 + ((int)((unsigned int)(v1054 - v1053) >> 31));
    v1052[v1154] = v1162;
    int * v1056 = v1039->cache_age;
    int v1057 = v1056[v1155];
    int v1164 = v1057 + ((int)((unsigned int)(v1057 - v1053) >> 31));
    v1056[v1155] = v1164;
    int * v1059 = v1039->cache_age;
    v1059[v1161] = 0;
    v1144 = v1161;
  } else {
    int * v1062 = v1039->cache_age;
    int v1168 = (((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1)) & 1) * 2;
    int v1063 = v1062[v1168];
    int * v1064 = v1039->cache_tags;
    int v1065 = v1064[v1168];
    int v1066 = v1062[v1155];
    int v1067 = v1064[v1155];
    bool v1170 = !(((~(((v1047 ^ ((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1))) | (-(v1047 ^ ((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1))))) >> 31)) | (~(((v1048 ^ ((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1))) | (-(v1048 ^ ((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1))))) >> 31))) == 0);
    int v1121;
    if (v1170) {
      int * v1068 = v1039->cache_age;
      int v1172 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1048 ^ ((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1))) | (-(v1048 ^ ((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1))))) >> 31)) & 1);
      int v1069 = v1068[v1172];
      int v1070 = v1068[v1156];
      int v1173 = v1070 + ((int)((unsigned int)(v1070 - v1069) >> 31));
      v1068[v1156] = v1173;
      int * v1072 = v1039->cache_age;
      int v1073 = v1072[v1157];
      int v1175 = v1073 + ((int)((unsigned int)(v1073 - v1069) >> 31));
      v1072[v1157] = v1175;
      int * v1075 = v1039->cache_age;
      v1075[v1172] = 0;
      v1121 = v1172;
    } else {
      int * v1078 = v1039->cache_age;
      int v1179 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1)) & 3) * 2);
      int v1079 = v1078[v1179];
      int * v1080 = v1039->cache_tags;
      int v1081 = v1080[v1179];
      int v1082 = v1078[v1157];
      int v1083 = v1080[v1157];
      int * v1084 = v1039->cache_dirty;
      int v1182 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1)) & 3) * 2)) + ((((v1079 + ((~(((v1081 ^ -1) | (-(v1081 ^ -1))) >> 31)) & 2)) - (v1082 + ((~(((v1083 ^ -1) | (-(v1083 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1085 = v1084[v1182];
      bool v1183 = !(v1085 == 0);
      if (v1183) {
        int * v1086 = v1039->cache_tags;
        int v1087 = v1086[v1182];
        int * v1088 = v1039->cache_vals;
        int v1186 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1)) & 3) * 2)) + ((((v1079 + ((~(((v1081 ^ -1) | (-(v1081 ^ -1))) >> 31)) & 2)) - (v1082 + ((~(((v1083 ^ -1) | (-(v1083 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1089 = v1088[v1186];
        int v1187 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1)) & 3) * 2)) + ((((v1079 + ((~(((v1081 ^ -1) | (-(v1081 ^ -1))) >> 31)) & 2)) - (v1082 + ((~(((v1083 ^ -1) | (-(v1083 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1090 = v1088[v1187];
        int * v1091 = v1039->mem;
        int v1189 = v1087 * 2;
        v1091[v1189] = v1089;
        int * v1093 = v1039->mem;
        int v1192 = (v1087 * 2) + 1;
        v1093[v1192] = v1090;
        ;
      } else {
        ;
      }
      int * v1098 = v1039->mem;
      int v1197 = ((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1)) * 2;
      int v1099 = v1098[v1197];
      int v1198 = (((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1)) * 2) + 1;
      int v1100 = v1098[v1198];
      int * v1101 = v1039->cache_vals;
      int v1200 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1)) & 3) * 2)) + ((((v1079 + ((~(((v1081 ^ -1) | (-(v1081 ^ -1))) >> 31)) & 2)) - (v1082 + ((~(((v1083 ^ -1) | (-(v1083 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1101[v1200] = v1099;
      int * v1103 = v1039->cache_vals;
      int v1203 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1)) & 3) * 2)) + ((((v1079 + ((~(((v1081 ^ -1) | (-(v1081 ^ -1))) >> 31)) & 2)) - (v1082 + ((~(((v1083 ^ -1) | (-(v1083 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1103[v1203] = v1100;
      int * v1105 = v1039->cache_tags;
      int v1206 = (int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1);
      v1105[v1182] = v1206;
      int * v1107 = v1039->cache_dirty;
      v1107[v1182] = 0;
      int * v1109 = v1039->cache_age;
      v1109[v1182] = 1;
      int * v1111 = v1039->cache_age;
      int v1112 = v1111[v1182];
      int v1113 = v1111[v1156];
      int v1212 = v1113 + ((int)((unsigned int)(v1113 - v1112) >> 31));
      v1111[v1156] = v1212;
      int * v1115 = v1039->cache_age;
      int v1116 = v1115[v1157];
      int v1214 = v1116 + ((int)((unsigned int)(v1116 - v1112) >> 31));
      v1115[v1157] = v1214;
      int * v1118 = v1039->cache_age;
      v1118[v1182] = 0;
      v1121 = v1182;
    }
    int * v1122 = v1039->cache_vals;
    int v1217 = v1121 * 2;
    int v1123 = v1122[v1217];
    int v1218 = (v1121 * 2) + 1;
    int v1124 = v1122[v1218];
    int v1219 = (((((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1)) & 1) * 2) + ((((v1063 + ((~(((v1065 ^ -1) | (-(v1065 ^ -1))) >> 31)) & 2)) - (v1066 + ((~(((v1067 ^ -1) | (-(v1067 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1122[v1219] = v1123;
    int * v1126 = v1039->cache_vals;
    int v1222 = ((((((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1)) & 1) * 2) + ((((v1063 + ((~(((v1065 ^ -1) | (-(v1065 ^ -1))) >> 31)) & 2)) - (v1066 + ((~(((v1067 ^ -1) | (-(v1067 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1126[v1222] = v1124;
    int * v1128 = v1039->cache_tags;
    int v1225 = ((((int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1)) & 1) * 2) + ((((v1063 + ((~(((v1065 ^ -1) | (-(v1065 ^ -1))) >> 31)) & 2)) - (v1066 + ((~(((v1067 ^ -1) | (-(v1067 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1226 = (int)((unsigned int)((int)((unsigned int)v1043 >> 2)) >> 1);
    v1128[v1225] = v1226;
    int * v1130 = v1039->cache_dirty;
    v1130[v1225] = 0;
    int * v1132 = v1039->cache_age;
    v1132[v1225] = 1;
    int * v1134 = v1039->cache_age;
    int v1135 = v1134[v1225];
    int v1136 = v1134[v1154];
    int v1232 = v1136 + ((int)((unsigned int)(v1136 - v1135) >> 31));
    v1134[v1154] = v1232;
    int * v1138 = v1039->cache_age;
    int v1139 = v1138[v1155];
    int v1234 = v1139 + ((int)((unsigned int)(v1139 - v1135) >> 31));
    v1138[v1155] = v1234;
    int * v1141 = v1039->cache_age;
    v1141[v1225] = 0;
    v1144 = v1225;
  }
  int v1237 = (v1144 * 2) + (((int)((unsigned int)v1043 >> 2)) & 1);
  int v1145 = v1051[v1237];
  int * v1146 = v1039->regs;
  int v1239 = ((int)((unsigned int)v1145 >> ((v1043 & 3) << 3))) & 255;
  v1146[17] = v1239;
  struct StateT * v1148 = slot_29(v1039);
  return v1148;
}

struct StateT * slot_32(struct StateT * v1296) {
  int v1297 = v1296->timer;
  int v1305 = v1297 + 1;
  v1296->timer = v1305;
  int * v1299 = v1296->regs;
  int v1300 = v1299[16];
  int v1301 = v1299[12];
  int v1310 = v1300 & v1301;
  v1299[17] = v1310;
  struct StateT * v1303 = slot_33(v1296);
  return v1303;
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

struct StateT * slot_33(struct StateT * v1313) {
  int v1314 = v1313->timer;
  int v1322 = v1314 + 1;
  v1313->timer = v1322;
  int * v1316 = v1313->regs;
  int v1317 = v1316[14];
  int v1318 = v1316[16];
  int v1326 = v1317 ^ v1318;
  v1316[14] = v1326;
  struct StateT * v1320 = slot_34(v1313);
  return v1320;
}

struct StateT * slot_36(struct StateT * v1359) {
  int v1360 = v1359->timer;
  int v1364 = v1360 + 1;
  v1359->timer = v1364;
  struct StateT * v1362 = slot_37(v1359);
  return v1362;
}

struct StateT * slot_37(struct StateT * v1367) {
  int * v1368 = v1367->saved_regs;
  int * v1369 = v1367->regs;
  int v1370 = v1369[16];
  v1368[16] = v1370;
  int v1372 = v1367->timer;
  int v1384 = v1372 + 1;
  v1367->timer = v1384;
  int * v1374 = v1367->regs;
  int v1375 = v1374[10];
  int v1376 = v1374[13];
  int v1388 = v1375 + v1376;
  v1374[16] = v1388;
  struct StateT * v1378 = slot_38(v1367);
  return v1378;
}

struct StateT * slot_40(struct StateT * v1618) {
  int v1619 = v1618->timer;
  int v1729 = v1619 + 1;
  v1618->timer = v1729;
  int * v1621 = v1618->regs;
  int v1622 = v1621[17];
  int * v1623 = v1618->cache_tags;
  int v1733 = (((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1)) & 1) * 2;
  int v1624 = v1623[v1733];
  int v1734 = ((((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1625 = v1623[v1734];
  int v1735 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1)) & 3) * 2);
  int v1626 = v1623[v1735];
  int v1736 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1627 = v1623[v1736];
  int v1628 = v1618->timer;
  int v1737 = v1628 + ((100 ^ (((~(((v1626 ^ ((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1))) | (-(v1626 ^ ((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1))))) >> 31)) | (~(((v1627 ^ ((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1))) | (-(v1627 ^ ((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1624 ^ ((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1))) | (-(v1624 ^ ((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1))))) >> 31)) | (~(((v1625 ^ ((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1))) | (-(v1625 ^ ((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1626 ^ ((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1))) | (-(v1626 ^ ((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1))))) >> 31)) | (~(((v1627 ^ ((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1))) | (-(v1627 ^ ((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1618->timer = v1737;
  int * v1630 = v1618->cache_vals;
  bool v1738 = !(((~(((v1624 ^ ((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1))) | (-(v1624 ^ ((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1))))) >> 31)) | (~(((v1625 ^ ((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1))) | (-(v1625 ^ ((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1))))) >> 31))) == 0);
  int v1723;
  if (v1738) {
    int * v1631 = v1618->cache_age;
    int v1740 = ((((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1)) & 1) * 2) + ((~(((v1625 ^ ((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1))) | (-(v1625 ^ ((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1))))) >> 31)) & 1);
    int v1632 = v1631[v1740];
    int v1633 = v1631[v1733];
    int v1741 = v1633 + ((int)((unsigned int)(v1633 - v1632) >> 31));
    v1631[v1733] = v1741;
    int * v1635 = v1618->cache_age;
    int v1636 = v1635[v1734];
    int v1743 = v1636 + ((int)((unsigned int)(v1636 - v1632) >> 31));
    v1635[v1734] = v1743;
    int * v1638 = v1618->cache_age;
    v1638[v1740] = 0;
    v1723 = v1740;
  } else {
    int * v1641 = v1618->cache_age;
    int v1747 = (((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1)) & 1) * 2;
    int v1642 = v1641[v1747];
    int * v1643 = v1618->cache_tags;
    int v1644 = v1643[v1747];
    int v1645 = v1641[v1734];
    int v1646 = v1643[v1734];
    bool v1749 = !(((~(((v1626 ^ ((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1))) | (-(v1626 ^ ((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1))))) >> 31)) | (~(((v1627 ^ ((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1))) | (-(v1627 ^ ((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1))))) >> 31))) == 0);
    int v1700;
    if (v1749) {
      int * v1647 = v1618->cache_age;
      int v1751 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1627 ^ ((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1))) | (-(v1627 ^ ((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1))))) >> 31)) & 1);
      int v1648 = v1647[v1751];
      int v1649 = v1647[v1735];
      int v1752 = v1649 + ((int)((unsigned int)(v1649 - v1648) >> 31));
      v1647[v1735] = v1752;
      int * v1651 = v1618->cache_age;
      int v1652 = v1651[v1736];
      int v1754 = v1652 + ((int)((unsigned int)(v1652 - v1648) >> 31));
      v1651[v1736] = v1754;
      int * v1654 = v1618->cache_age;
      v1654[v1751] = 0;
      v1700 = v1751;
    } else {
      int * v1657 = v1618->cache_age;
      int v1758 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1)) & 3) * 2);
      int v1658 = v1657[v1758];
      int * v1659 = v1618->cache_tags;
      int v1660 = v1659[v1758];
      int v1661 = v1657[v1736];
      int v1662 = v1659[v1736];
      int * v1663 = v1618->cache_dirty;
      int v1761 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1)) & 3) * 2)) + ((((v1658 + ((~(((v1660 ^ -1) | (-(v1660 ^ -1))) >> 31)) & 2)) - (v1661 + ((~(((v1662 ^ -1) | (-(v1662 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1664 = v1663[v1761];
      bool v1762 = !(v1664 == 0);
      if (v1762) {
        int * v1665 = v1618->cache_tags;
        int v1666 = v1665[v1761];
        int * v1667 = v1618->cache_vals;
        int v1765 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1)) & 3) * 2)) + ((((v1658 + ((~(((v1660 ^ -1) | (-(v1660 ^ -1))) >> 31)) & 2)) - (v1661 + ((~(((v1662 ^ -1) | (-(v1662 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1668 = v1667[v1765];
        int v1766 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1)) & 3) * 2)) + ((((v1658 + ((~(((v1660 ^ -1) | (-(v1660 ^ -1))) >> 31)) & 2)) - (v1661 + ((~(((v1662 ^ -1) | (-(v1662 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1669 = v1667[v1766];
        int * v1670 = v1618->mem;
        int v1768 = v1666 * 2;
        v1670[v1768] = v1668;
        int * v1672 = v1618->mem;
        int v1771 = (v1666 * 2) + 1;
        v1672[v1771] = v1669;
        ;
      } else {
        ;
      }
      int * v1677 = v1618->mem;
      int v1776 = ((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1)) * 2;
      int v1678 = v1677[v1776];
      int v1777 = (((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1)) * 2) + 1;
      int v1679 = v1677[v1777];
      int * v1680 = v1618->cache_vals;
      int v1779 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1)) & 3) * 2)) + ((((v1658 + ((~(((v1660 ^ -1) | (-(v1660 ^ -1))) >> 31)) & 2)) - (v1661 + ((~(((v1662 ^ -1) | (-(v1662 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1680[v1779] = v1678;
      int * v1682 = v1618->cache_vals;
      int v1782 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1)) & 3) * 2)) + ((((v1658 + ((~(((v1660 ^ -1) | (-(v1660 ^ -1))) >> 31)) & 2)) - (v1661 + ((~(((v1662 ^ -1) | (-(v1662 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1682[v1782] = v1679;
      int * v1684 = v1618->cache_tags;
      int v1785 = (int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1);
      v1684[v1761] = v1785;
      int * v1686 = v1618->cache_dirty;
      v1686[v1761] = 0;
      int * v1688 = v1618->cache_age;
      v1688[v1761] = 1;
      int * v1690 = v1618->cache_age;
      int v1691 = v1690[v1761];
      int v1692 = v1690[v1735];
      int v1791 = v1692 + ((int)((unsigned int)(v1692 - v1691) >> 31));
      v1690[v1735] = v1791;
      int * v1694 = v1618->cache_age;
      int v1695 = v1694[v1736];
      int v1793 = v1695 + ((int)((unsigned int)(v1695 - v1691) >> 31));
      v1694[v1736] = v1793;
      int * v1697 = v1618->cache_age;
      v1697[v1761] = 0;
      v1700 = v1761;
    }
    int * v1701 = v1618->cache_vals;
    int v1796 = v1700 * 2;
    int v1702 = v1701[v1796];
    int v1797 = (v1700 * 2) + 1;
    int v1703 = v1701[v1797];
    int v1798 = (((((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1)) & 1) * 2) + ((((v1642 + ((~(((v1644 ^ -1) | (-(v1644 ^ -1))) >> 31)) & 2)) - (v1645 + ((~(((v1646 ^ -1) | (-(v1646 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1701[v1798] = v1702;
    int * v1705 = v1618->cache_vals;
    int v1801 = ((((((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1)) & 1) * 2) + ((((v1642 + ((~(((v1644 ^ -1) | (-(v1644 ^ -1))) >> 31)) & 2)) - (v1645 + ((~(((v1646 ^ -1) | (-(v1646 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1705[v1801] = v1703;
    int * v1707 = v1618->cache_tags;
    int v1804 = ((((int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1)) & 1) * 2) + ((((v1642 + ((~(((v1644 ^ -1) | (-(v1644 ^ -1))) >> 31)) & 2)) - (v1645 + ((~(((v1646 ^ -1) | (-(v1646 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1805 = (int)((unsigned int)((int)((unsigned int)v1622 >> 2)) >> 1);
    v1707[v1804] = v1805;
    int * v1709 = v1618->cache_dirty;
    v1709[v1804] = 0;
    int * v1711 = v1618->cache_age;
    v1711[v1804] = 1;
    int * v1713 = v1618->cache_age;
    int v1714 = v1713[v1804];
    int v1715 = v1713[v1733];
    int v1811 = v1715 + ((int)((unsigned int)(v1715 - v1714) >> 31));
    v1713[v1733] = v1811;
    int * v1717 = v1618->cache_age;
    int v1718 = v1717[v1734];
    int v1813 = v1718 + ((int)((unsigned int)(v1718 - v1714) >> 31));
    v1717[v1734] = v1813;
    int * v1720 = v1618->cache_age;
    v1720[v1804] = 0;
    v1723 = v1804;
  }
  int v1816 = (v1723 * 2) + (((int)((unsigned int)v1622 >> 2)) & 1);
  int v1724 = v1630[v1816];
  int * v1725 = v1618->regs;
  int v1818 = ((int)((unsigned int)v1724 >> ((v1622 & 3) << 3))) & 255;
  v1725[17] = v1818;
  struct StateT * v1727 = slot_41(v1618);
  return v1727;
}

struct StateT * slot_27(struct StateT * v836) {
  int v837 = v836->timer;
  int v947 = v837 + 1;
  v836->timer = v947;
  int * v839 = v836->regs;
  int v840 = v839[16];
  int * v841 = v836->cache_tags;
  int v951 = (((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1)) & 1) * 2;
  int v842 = v841[v951];
  int v952 = ((((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1)) & 1) * 2) + 1;
  int v843 = v841[v952];
  int v953 = 4 + ((((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1)) & 3) * 2);
  int v844 = v841[v953];
  int v954 = (4 + ((((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v845 = v841[v954];
  int v846 = v836->timer;
  int v955 = v846 + ((100 ^ (((~(((v844 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))) | (-(v844 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))))) >> 31)) | (~(((v845 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))) | (-(v845 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v842 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))) | (-(v842 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))))) >> 31)) | (~(((v843 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))) | (-(v843 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v844 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))) | (-(v844 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))))) >> 31)) | (~(((v845 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))) | (-(v845 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))))) >> 31))) & 104)))));
  v836->timer = v955;
  int * v848 = v836->cache_vals;
  bool v956 = !(((~(((v842 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))) | (-(v842 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))))) >> 31)) | (~(((v843 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))) | (-(v843 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))))) >> 31))) == 0);
  int v941;
  if (v956) {
    int * v849 = v836->cache_age;
    int v958 = ((((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1)) & 1) * 2) + ((~(((v843 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))) | (-(v843 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))))) >> 31)) & 1);
    int v850 = v849[v958];
    int v851 = v849[v951];
    int v959 = v851 + ((int)((unsigned int)(v851 - v850) >> 31));
    v849[v951] = v959;
    int * v853 = v836->cache_age;
    int v854 = v853[v952];
    int v961 = v854 + ((int)((unsigned int)(v854 - v850) >> 31));
    v853[v952] = v961;
    int * v856 = v836->cache_age;
    v856[v958] = 0;
    v941 = v958;
  } else {
    int * v859 = v836->cache_age;
    int v965 = (((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1)) & 1) * 2;
    int v860 = v859[v965];
    int * v861 = v836->cache_tags;
    int v862 = v861[v965];
    int v863 = v859[v952];
    int v864 = v861[v952];
    bool v967 = !(((~(((v844 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))) | (-(v844 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))))) >> 31)) | (~(((v845 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))) | (-(v845 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))))) >> 31))) == 0);
    int v918;
    if (v967) {
      int * v865 = v836->cache_age;
      int v969 = (4 + ((((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1)) & 3) * 2)) + ((~(((v845 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))) | (-(v845 ^ ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1))))) >> 31)) & 1);
      int v866 = v865[v969];
      int v867 = v865[v953];
      int v970 = v867 + ((int)((unsigned int)(v867 - v866) >> 31));
      v865[v953] = v970;
      int * v869 = v836->cache_age;
      int v870 = v869[v954];
      int v972 = v870 + ((int)((unsigned int)(v870 - v866) >> 31));
      v869[v954] = v972;
      int * v872 = v836->cache_age;
      v872[v969] = 0;
      v918 = v969;
    } else {
      int * v875 = v836->cache_age;
      int v976 = 4 + ((((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1)) & 3) * 2);
      int v876 = v875[v976];
      int * v877 = v836->cache_tags;
      int v878 = v877[v976];
      int v879 = v875[v954];
      int v880 = v877[v954];
      int * v881 = v836->cache_dirty;
      int v979 = (4 + ((((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1)) & 3) * 2)) + ((((v876 + ((~(((v878 ^ -1) | (-(v878 ^ -1))) >> 31)) & 2)) - (v879 + ((~(((v880 ^ -1) | (-(v880 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v882 = v881[v979];
      bool v980 = !(v882 == 0);
      if (v980) {
        int * v883 = v836->cache_tags;
        int v884 = v883[v979];
        int * v885 = v836->cache_vals;
        int v983 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1)) & 3) * 2)) + ((((v876 + ((~(((v878 ^ -1) | (-(v878 ^ -1))) >> 31)) & 2)) - (v879 + ((~(((v880 ^ -1) | (-(v880 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v886 = v885[v983];
        int v984 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1)) & 3) * 2)) + ((((v876 + ((~(((v878 ^ -1) | (-(v878 ^ -1))) >> 31)) & 2)) - (v879 + ((~(((v880 ^ -1) | (-(v880 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v887 = v885[v984];
        int * v888 = v836->mem;
        int v986 = v884 * 2;
        v888[v986] = v886;
        int * v890 = v836->mem;
        int v989 = (v884 * 2) + 1;
        v890[v989] = v887;
        ;
      } else {
        ;
      }
      int * v895 = v836->mem;
      int v994 = ((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1)) * 2;
      int v896 = v895[v994];
      int v995 = (((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1)) * 2) + 1;
      int v897 = v895[v995];
      int * v898 = v836->cache_vals;
      int v997 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1)) & 3) * 2)) + ((((v876 + ((~(((v878 ^ -1) | (-(v878 ^ -1))) >> 31)) & 2)) - (v879 + ((~(((v880 ^ -1) | (-(v880 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v898[v997] = v896;
      int * v900 = v836->cache_vals;
      int v1000 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1)) & 3) * 2)) + ((((v876 + ((~(((v878 ^ -1) | (-(v878 ^ -1))) >> 31)) & 2)) - (v879 + ((~(((v880 ^ -1) | (-(v880 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v900[v1000] = v897;
      int * v902 = v836->cache_tags;
      int v1003 = (int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1);
      v902[v979] = v1003;
      int * v904 = v836->cache_dirty;
      v904[v979] = 0;
      int * v906 = v836->cache_age;
      v906[v979] = 1;
      int * v908 = v836->cache_age;
      int v909 = v908[v979];
      int v910 = v908[v953];
      int v1009 = v910 + ((int)((unsigned int)(v910 - v909) >> 31));
      v908[v953] = v1009;
      int * v912 = v836->cache_age;
      int v913 = v912[v954];
      int v1011 = v913 + ((int)((unsigned int)(v913 - v909) >> 31));
      v912[v954] = v1011;
      int * v915 = v836->cache_age;
      v915[v979] = 0;
      v918 = v979;
    }
    int * v919 = v836->cache_vals;
    int v1014 = v918 * 2;
    int v920 = v919[v1014];
    int v1015 = (v918 * 2) + 1;
    int v921 = v919[v1015];
    int v1016 = (((((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1)) & 1) * 2) + ((((v860 + ((~(((v862 ^ -1) | (-(v862 ^ -1))) >> 31)) & 2)) - (v863 + ((~(((v864 ^ -1) | (-(v864 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v919[v1016] = v920;
    int * v923 = v836->cache_vals;
    int v1019 = ((((((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1)) & 1) * 2) + ((((v860 + ((~(((v862 ^ -1) | (-(v862 ^ -1))) >> 31)) & 2)) - (v863 + ((~(((v864 ^ -1) | (-(v864 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v923[v1019] = v921;
    int * v925 = v836->cache_tags;
    int v1022 = ((((int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1)) & 1) * 2) + ((((v860 + ((~(((v862 ^ -1) | (-(v862 ^ -1))) >> 31)) & 2)) - (v863 + ((~(((v864 ^ -1) | (-(v864 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1023 = (int)((unsigned int)((int)((unsigned int)v840 >> 2)) >> 1);
    v925[v1022] = v1023;
    int * v927 = v836->cache_dirty;
    v927[v1022] = 0;
    int * v929 = v836->cache_age;
    v929[v1022] = 1;
    int * v931 = v836->cache_age;
    int v932 = v931[v1022];
    int v933 = v931[v951];
    int v1029 = v933 + ((int)((unsigned int)(v933 - v932) >> 31));
    v931[v951] = v1029;
    int * v935 = v836->cache_age;
    int v936 = v935[v952];
    int v1031 = v936 + ((int)((unsigned int)(v936 - v932) >> 31));
    v935[v952] = v1031;
    int * v938 = v836->cache_age;
    v938[v1022] = 0;
    v941 = v1022;
  }
  int v1034 = (v941 * 2) + (((int)((unsigned int)v840 >> 2)) & 1);
  int v942 = v848[v1034];
  int * v943 = v836->regs;
  int v1036 = ((int)((unsigned int)v942 >> ((v840 & 3) << 3))) & 255;
  v943[16] = v1036;
  struct StateT * v945 = slot_28(v836);
  return v945;
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

struct StateT * slot_48(struct StateT * v1959) {
  int * v1960 = v1959->regs;
  int v1961 = v1960[15];
  int * v1962 = v1959->saved_regs;
  int v1963 = v1962[13];
  bool v1996 = (v1961 ^ -2147483648) >= (v1963 ^ -2147483648);
  struct StateT * v1990;
  if (v1996) {
    struct StateT * v1964 = slot_36(v1959);
    v1990 = v1964;
  } else {
    int v1966 = v1959->timer;
    int v1999 = v1966 + 15;
    v1959->timer = v1999;
    int * v1968 = v1959->saved_regs;
    int v1969 = v1968[16];
    int * v1970 = v1959->regs;
    v1970[16] = v1969;
    int * v1972 = v1959->saved_regs;
    int v1973 = v1972[17];
    int * v1974 = v1959->regs;
    v1974[17] = v1973;
    int * v1976 = v1959->saved_regs;
    int v1977 = v1976[14];
    int * v1978 = v1959->regs;
    v1978[14] = v1977;
    int * v1980 = v1959->saved_regs;
    int v1981 = v1980[12];
    int * v1982 = v1959->regs;
    v1982[12] = v1981;
    int * v1984 = v1959->saved_regs;
    int v1985 = v1984[13];
    int * v1986 = v1959->regs;
    v1986[13] = v1985;
    struct StateT * v1988 = slot_17(v1959);
    v1990 = v1988;
  }
  return v1990;
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

struct StateT * slot_35(struct StateT * v1345) {
  int v1346 = v1345->timer;
  int v1353 = v1346 + 1;
  v1345->timer = v1353;
  int * v1348 = v1345->regs;
  int v1349 = v1348[13];
  int v1356 = v1349 + 1;
  v1348[13] = v1356;
  struct StateT * v1351 = slot_36(v1345);
  return v1351;
}

struct StateT * slot_34(struct StateT * v1329) {
  int v1330 = v1329->timer;
  int v1338 = v1330 + 1;
  v1329->timer = v1338;
  int * v1332 = v1329->regs;
  int v1333 = v1332[12];
  int v1334 = v1332[17];
  int v1342 = v1333 ^ v1334;
  v1332[12] = v1342;
  struct StateT * v1336 = slot_35(v1329);
  return v1336;
}

struct StateT * slot_25(struct StateT * v819) {
  int v820 = v819->timer;
  int v828 = v820 + 1;
  v819->timer = v828;
  int * v822 = v819->regs;
  int v823 = v822[11];
  int v824 = v822[13];
  int v833 = v823 + v824;
  v822[17] = v833;
  struct StateT * v826 = slot_27(v819);
  return v826;
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
  struct StateT * v804 = slot_25(v797);
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

struct StateT * slot_45(struct StateT * v1892) {
  int * v1893 = v1892->saved_regs;
  int * v1894 = v1892->regs;
  int v1895 = v1894[14];
  v1893[14] = v1895;
  int v1897 = v1892->timer;
  int v1909 = v1897 + 1;
  v1892->timer = v1909;
  int * v1899 = v1892->regs;
  int v1900 = v1899[14];
  int v1901 = v1899[16];
  int v1912 = v1900 ^ v1901;
  v1899[14] = v1912;
  struct StateT * v1903 = slot_46(v1892);
  return v1903;
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

struct StateT * slot_38(struct StateT * v1391) {
  int * v1392 = v1391->saved_regs;
  int * v1393 = v1391->regs;
  int v1394 = v1393[17];
  v1392[17] = v1394;
  int v1396 = v1391->timer;
  int v1408 = v1396 + 1;
  v1391->timer = v1408;
  int * v1398 = v1391->regs;
  int v1399 = v1398[11];
  int v1400 = v1398[13];
  int v1412 = v1399 + v1400;
  v1398[17] = v1412;
  struct StateT * v1402 = slot_39(v1391);
  return v1402;
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

struct StateT * slot_42(struct StateT * v1837) {
  int v1838 = v1837->timer;
  int v1849 = v1838 + 1;
  v1837->timer = v1849;
  int * v1840 = v1837->regs;
  int v1841 = v1840[16];
  bool v1852 = -2147483648 < (v1841 ^ -2147483648);
  int v1844;
  if (v1852) {
    v1844 = 1;
  } else {
    v1844 = 0;
  }
  int * v1845 = v1837->regs;
  v1845[16] = v1844;
  struct StateT * v1847 = slot_43(v1837);
  return v1847;
}

struct StateT * slot_46(struct StateT * v1915) {
  int * v1916 = v1915->saved_regs;
  int * v1917 = v1915->regs;
  int v1918 = v1917[12];
  v1916[12] = v1918;
  int v1920 = v1915->timer;
  int v1932 = v1920 + 1;
  v1915->timer = v1932;
  int * v1922 = v1915->regs;
  int v1923 = v1922[12];
  int v1924 = v1922[17];
  int v1935 = v1923 ^ v1924;
  v1922[12] = v1935;
  struct StateT * v1926 = slot_47(v1915);
  return v1926;
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

struct StateT * slot_41(struct StateT * v1821) {
  int v1822 = v1821->timer;
  int v1830 = v1822 + 1;
  v1821->timer = v1830;
  int * v1824 = v1821->regs;
  int v1825 = v1824[16];
  int v1826 = v1824[17];
  int v1834 = v1825 ^ v1826;
  v1824[16] = v1834;
  struct StateT * v1828 = slot_42(v1821);
  return v1828;
}

struct StateT * slot_39(struct StateT * v1415) {
  int v1416 = v1415->timer;
  int v1526 = v1416 + 1;
  v1415->timer = v1526;
  int * v1418 = v1415->regs;
  int v1419 = v1418[16];
  int * v1420 = v1415->cache_tags;
  int v1530 = (((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1)) & 1) * 2;
  int v1421 = v1420[v1530];
  int v1531 = ((((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1422 = v1420[v1531];
  int v1532 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1)) & 3) * 2);
  int v1423 = v1420[v1532];
  int v1533 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1424 = v1420[v1533];
  int v1425 = v1415->timer;
  int v1534 = v1425 + ((100 ^ (((~(((v1423 ^ ((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1))) | (-(v1423 ^ ((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1))))) >> 31)) | (~(((v1424 ^ ((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1))) | (-(v1424 ^ ((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1421 ^ ((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1))) | (-(v1421 ^ ((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1))))) >> 31)) | (~(((v1422 ^ ((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1))) | (-(v1422 ^ ((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1423 ^ ((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1))) | (-(v1423 ^ ((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1))))) >> 31)) | (~(((v1424 ^ ((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1))) | (-(v1424 ^ ((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1415->timer = v1534;
  int * v1427 = v1415->cache_vals;
  bool v1535 = !(((~(((v1421 ^ ((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1))) | (-(v1421 ^ ((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1))))) >> 31)) | (~(((v1422 ^ ((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1))) | (-(v1422 ^ ((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1))))) >> 31))) == 0);
  int v1520;
  if (v1535) {
    int * v1428 = v1415->cache_age;
    int v1537 = ((((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1)) & 1) * 2) + ((~(((v1422 ^ ((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1))) | (-(v1422 ^ ((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1))))) >> 31)) & 1);
    int v1429 = v1428[v1537];
    int v1430 = v1428[v1530];
    int v1538 = v1430 + ((int)((unsigned int)(v1430 - v1429) >> 31));
    v1428[v1530] = v1538;
    int * v1432 = v1415->cache_age;
    int v1433 = v1432[v1531];
    int v1540 = v1433 + ((int)((unsigned int)(v1433 - v1429) >> 31));
    v1432[v1531] = v1540;
    int * v1435 = v1415->cache_age;
    v1435[v1537] = 0;
    v1520 = v1537;
  } else {
    int * v1438 = v1415->cache_age;
    int v1544 = (((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1)) & 1) * 2;
    int v1439 = v1438[v1544];
    int * v1440 = v1415->cache_tags;
    int v1441 = v1440[v1544];
    int v1442 = v1438[v1531];
    int v1443 = v1440[v1531];
    bool v1546 = !(((~(((v1423 ^ ((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1))) | (-(v1423 ^ ((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1))))) >> 31)) | (~(((v1424 ^ ((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1))) | (-(v1424 ^ ((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1))))) >> 31))) == 0);
    int v1497;
    if (v1546) {
      int * v1444 = v1415->cache_age;
      int v1548 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1424 ^ ((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1))) | (-(v1424 ^ ((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1))))) >> 31)) & 1);
      int v1445 = v1444[v1548];
      int v1446 = v1444[v1532];
      int v1549 = v1446 + ((int)((unsigned int)(v1446 - v1445) >> 31));
      v1444[v1532] = v1549;
      int * v1448 = v1415->cache_age;
      int v1449 = v1448[v1533];
      int v1551 = v1449 + ((int)((unsigned int)(v1449 - v1445) >> 31));
      v1448[v1533] = v1551;
      int * v1451 = v1415->cache_age;
      v1451[v1548] = 0;
      v1497 = v1548;
    } else {
      int * v1454 = v1415->cache_age;
      int v1555 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1)) & 3) * 2);
      int v1455 = v1454[v1555];
      int * v1456 = v1415->cache_tags;
      int v1457 = v1456[v1555];
      int v1458 = v1454[v1533];
      int v1459 = v1456[v1533];
      int * v1460 = v1415->cache_dirty;
      int v1558 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1)) & 3) * 2)) + ((((v1455 + ((~(((v1457 ^ -1) | (-(v1457 ^ -1))) >> 31)) & 2)) - (v1458 + ((~(((v1459 ^ -1) | (-(v1459 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1461 = v1460[v1558];
      bool v1559 = !(v1461 == 0);
      if (v1559) {
        int * v1462 = v1415->cache_tags;
        int v1463 = v1462[v1558];
        int * v1464 = v1415->cache_vals;
        int v1562 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1)) & 3) * 2)) + ((((v1455 + ((~(((v1457 ^ -1) | (-(v1457 ^ -1))) >> 31)) & 2)) - (v1458 + ((~(((v1459 ^ -1) | (-(v1459 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1465 = v1464[v1562];
        int v1563 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1)) & 3) * 2)) + ((((v1455 + ((~(((v1457 ^ -1) | (-(v1457 ^ -1))) >> 31)) & 2)) - (v1458 + ((~(((v1459 ^ -1) | (-(v1459 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1466 = v1464[v1563];
        int * v1467 = v1415->mem;
        int v1565 = v1463 * 2;
        v1467[v1565] = v1465;
        int * v1469 = v1415->mem;
        int v1568 = (v1463 * 2) + 1;
        v1469[v1568] = v1466;
        ;
      } else {
        ;
      }
      int * v1474 = v1415->mem;
      int v1573 = ((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1)) * 2;
      int v1475 = v1474[v1573];
      int v1574 = (((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1)) * 2) + 1;
      int v1476 = v1474[v1574];
      int * v1477 = v1415->cache_vals;
      int v1576 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1)) & 3) * 2)) + ((((v1455 + ((~(((v1457 ^ -1) | (-(v1457 ^ -1))) >> 31)) & 2)) - (v1458 + ((~(((v1459 ^ -1) | (-(v1459 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1477[v1576] = v1475;
      int * v1479 = v1415->cache_vals;
      int v1579 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1)) & 3) * 2)) + ((((v1455 + ((~(((v1457 ^ -1) | (-(v1457 ^ -1))) >> 31)) & 2)) - (v1458 + ((~(((v1459 ^ -1) | (-(v1459 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1479[v1579] = v1476;
      int * v1481 = v1415->cache_tags;
      int v1582 = (int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1);
      v1481[v1558] = v1582;
      int * v1483 = v1415->cache_dirty;
      v1483[v1558] = 0;
      int * v1485 = v1415->cache_age;
      v1485[v1558] = 1;
      int * v1487 = v1415->cache_age;
      int v1488 = v1487[v1558];
      int v1489 = v1487[v1532];
      int v1588 = v1489 + ((int)((unsigned int)(v1489 - v1488) >> 31));
      v1487[v1532] = v1588;
      int * v1491 = v1415->cache_age;
      int v1492 = v1491[v1533];
      int v1590 = v1492 + ((int)((unsigned int)(v1492 - v1488) >> 31));
      v1491[v1533] = v1590;
      int * v1494 = v1415->cache_age;
      v1494[v1558] = 0;
      v1497 = v1558;
    }
    int * v1498 = v1415->cache_vals;
    int v1593 = v1497 * 2;
    int v1499 = v1498[v1593];
    int v1594 = (v1497 * 2) + 1;
    int v1500 = v1498[v1594];
    int v1595 = (((((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1)) & 1) * 2) + ((((v1439 + ((~(((v1441 ^ -1) | (-(v1441 ^ -1))) >> 31)) & 2)) - (v1442 + ((~(((v1443 ^ -1) | (-(v1443 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1498[v1595] = v1499;
    int * v1502 = v1415->cache_vals;
    int v1598 = ((((((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1)) & 1) * 2) + ((((v1439 + ((~(((v1441 ^ -1) | (-(v1441 ^ -1))) >> 31)) & 2)) - (v1442 + ((~(((v1443 ^ -1) | (-(v1443 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1502[v1598] = v1500;
    int * v1504 = v1415->cache_tags;
    int v1601 = ((((int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1)) & 1) * 2) + ((((v1439 + ((~(((v1441 ^ -1) | (-(v1441 ^ -1))) >> 31)) & 2)) - (v1442 + ((~(((v1443 ^ -1) | (-(v1443 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1602 = (int)((unsigned int)((int)((unsigned int)v1419 >> 2)) >> 1);
    v1504[v1601] = v1602;
    int * v1506 = v1415->cache_dirty;
    v1506[v1601] = 0;
    int * v1508 = v1415->cache_age;
    v1508[v1601] = 1;
    int * v1510 = v1415->cache_age;
    int v1511 = v1510[v1601];
    int v1512 = v1510[v1530];
    int v1608 = v1512 + ((int)((unsigned int)(v1512 - v1511) >> 31));
    v1510[v1530] = v1608;
    int * v1514 = v1415->cache_age;
    int v1515 = v1514[v1531];
    int v1610 = v1515 + ((int)((unsigned int)(v1515 - v1511) >> 31));
    v1514[v1531] = v1610;
    int * v1517 = v1415->cache_age;
    v1517[v1601] = 0;
    v1520 = v1601;
  }
  int v1613 = (v1520 * 2) + (((int)((unsigned int)v1419 >> 2)) & 1);
  int v1521 = v1427[v1613];
  int * v1522 = v1415->regs;
  int v1615 = ((int)((unsigned int)v1521 >> ((v1419 & 3) << 3))) & 255;
  v1522[16] = v1615;
  struct StateT * v1524 = slot_40(v1415);
  return v1524;
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

struct StateT * slot_30(struct StateT * v1258) {
  int v1259 = v1258->timer;
  int v1270 = v1259 + 1;
  v1258->timer = v1270;
  int * v1261 = v1258->regs;
  int v1262 = v1261[16];
  bool v1273 = -2147483648 < (v1262 ^ -2147483648);
  int v1265;
  if (v1273) {
    v1265 = 1;
  } else {
    v1265 = 0;
  }
  int * v1266 = v1258->regs;
  v1266[16] = v1265;
  struct StateT * v1268 = slot_31(v1258);
  return v1268;
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