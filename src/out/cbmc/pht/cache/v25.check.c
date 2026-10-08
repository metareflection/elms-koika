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

struct StateT * slot_12(struct StateT * v490);
struct StateT * slot_6(struct StateT * v562);
struct StateT * slot_16(struct StateT * v606);
struct StateT * slot_5(struct StateT * v536);
struct StateT * slot_2(struct StateT * v62);
struct StateT * slot_7(struct StateT * v590);
struct StateT * slot_21(struct StateT * v1067);
struct StateT * slot_3(struct StateT * v468);
struct StateT * slot_10(struct StateT * v48);
struct StateT * slot_1(struct StateT * v35);
struct StateT * slot_19(struct StateT * v847);
struct StateT * slot_13(struct StateT * v522);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v549);
struct StateT * slot_17(struct StateT * v628);
struct StateT * slot_20(struct StateT * v1051);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v620);
struct StateT * slot_4(struct StateT * v508);
struct StateT * slot_15(struct StateT * v576);
struct StateT * slot_18(struct StateT * v644);
struct StateT * slot_9(struct StateT * v22);
struct StateT * slot_22(struct StateT * v503);
struct StateT * slot_11(struct StateT * v265);
struct StateT * slot_12(struct StateT * v490) {
  int v491 = v490->timer;
  int v497 = v491 + 1;
  v490->timer = v497;
  int * v493 = v490->regs;
  v493[11] = 0;
  struct StateT * v495 = slot_13(v490);
  return v495;
}

struct StateT * slot_6(struct StateT * v562) {
  int v563 = v562->timer;
  int v570 = v563 + 1;
  v562->timer = v570;
  int * v565 = v562->regs;
  int v566 = v565[11];
  int v573 = v566 + 72;
  v565[11] = v573;
  struct StateT * v568 = slot_7(v562);
  return v568;
}

struct StateT * slot_16(struct StateT * v606) {
  int v607 = v606->timer;
  int v614 = v607 + 1;
  v606->timer = v614;
  int * v609 = v606->regs;
  int v610 = v609[10];
  int v617 = (int)((unsigned int)v610 >> 26);
  v609[10] = v617;
  struct StateT * v612 = slot_17(v606);
  return v612;
}

struct StateT * slot_5(struct StateT * v536) {
  int v537 = v536->timer;
  int v543 = v537 + 1;
  v536->timer = v543;
  int * v539 = v536->regs;
  v539[11] = 0;
  struct StateT * v541 = slot_6(v536);
  return v541;
}

struct StateT * slot_2(struct StateT * v62) {
  int v63 = v62->timer;
  int v173 = v63 + 1;
  v62->timer = v173;
  int * v65 = v62->regs;
  int v66 = v65[11];
  int * v67 = v62->cache_tags;
  int v177 = (((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1)) & 1) * 2;
  int v68 = v67[v177];
  int v178 = ((((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1)) & 1) * 2) + 1;
  int v69 = v67[v178];
  int v179 = 4 + ((((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1)) & 3) * 2);
  int v70 = v67[v179];
  int v180 = (4 + ((((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v71 = v67[v180];
  int v72 = v62->timer;
  int v181 = v72 + ((100 ^ (((~(((v70 ^ ((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1))) | (-(v70 ^ ((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1))))) >> 31)) | (~(((v71 ^ ((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1))) | (-(v71 ^ ((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v68 ^ ((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1))) | (-(v68 ^ ((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1))))) >> 31)) | (~(((v69 ^ ((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1))) | (-(v69 ^ ((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v70 ^ ((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1))) | (-(v70 ^ ((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1))))) >> 31)) | (~(((v71 ^ ((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1))) | (-(v71 ^ ((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1))))) >> 31))) & 104)))));
  v62->timer = v181;
  int * v74 = v62->cache_vals;
  bool v182 = !(((~(((v68 ^ ((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1))) | (-(v68 ^ ((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1))))) >> 31)) | (~(((v69 ^ ((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1))) | (-(v69 ^ ((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1))))) >> 31))) == 0);
  int v167;
  if (v182) {
    int * v75 = v62->cache_age;
    int v184 = ((((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1)) & 1) * 2) + ((~(((v69 ^ ((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1))) | (-(v69 ^ ((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1))))) >> 31)) & 1);
    int v76 = v75[v184];
    int v77 = v75[v177];
    int v185 = v77 + ((int)((unsigned int)(v77 - v76) >> 31));
    v75[v177] = v185;
    int * v79 = v62->cache_age;
    int v80 = v79[v178];
    int v187 = v80 + ((int)((unsigned int)(v80 - v76) >> 31));
    v79[v178] = v187;
    int * v82 = v62->cache_age;
    v82[v184] = 0;
    v167 = v184;
  } else {
    int * v85 = v62->cache_age;
    int v191 = (((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1)) & 1) * 2;
    int v86 = v85[v191];
    int * v87 = v62->cache_tags;
    int v88 = v87[v191];
    int v89 = v85[v178];
    int v90 = v87[v178];
    bool v193 = !(((~(((v70 ^ ((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1))) | (-(v70 ^ ((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1))))) >> 31)) | (~(((v71 ^ ((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1))) | (-(v71 ^ ((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1))))) >> 31))) == 0);
    int v144;
    if (v193) {
      int * v91 = v62->cache_age;
      int v195 = (4 + ((((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1)) & 3) * 2)) + ((~(((v71 ^ ((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1))) | (-(v71 ^ ((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1))))) >> 31)) & 1);
      int v92 = v91[v195];
      int v93 = v91[v179];
      int v196 = v93 + ((int)((unsigned int)(v93 - v92) >> 31));
      v91[v179] = v196;
      int * v95 = v62->cache_age;
      int v96 = v95[v180];
      int v198 = v96 + ((int)((unsigned int)(v96 - v92) >> 31));
      v95[v180] = v198;
      int * v98 = v62->cache_age;
      v98[v195] = 0;
      v144 = v195;
    } else {
      int * v101 = v62->cache_age;
      int v202 = 4 + ((((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1)) & 3) * 2);
      int v102 = v101[v202];
      int * v103 = v62->cache_tags;
      int v104 = v103[v202];
      int v105 = v101[v180];
      int v106 = v103[v180];
      int * v107 = v62->cache_dirty;
      int v205 = (4 + ((((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1)) & 3) * 2)) + ((((v102 + ((~(((v104 ^ -1) | (-(v104 ^ -1))) >> 31)) & 2)) - (v105 + ((~(((v106 ^ -1) | (-(v106 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v108 = v107[v205];
      bool v206 = !(v108 == 0);
      if (v206) {
        int * v109 = v62->cache_tags;
        int v110 = v109[v205];
        int * v111 = v62->cache_vals;
        int v209 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1)) & 3) * 2)) + ((((v102 + ((~(((v104 ^ -1) | (-(v104 ^ -1))) >> 31)) & 2)) - (v105 + ((~(((v106 ^ -1) | (-(v106 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v112 = v111[v209];
        int v210 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1)) & 3) * 2)) + ((((v102 + ((~(((v104 ^ -1) | (-(v104 ^ -1))) >> 31)) & 2)) - (v105 + ((~(((v106 ^ -1) | (-(v106 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v113 = v111[v210];
        int * v114 = v62->mem;
        int v212 = v110 * 2;
        v114[v212] = v112;
        int * v116 = v62->mem;
        int v215 = (v110 * 2) + 1;
        v116[v215] = v113;
        ;
      } else {
        ;
      }
      int * v121 = v62->mem;
      int v220 = ((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1)) * 2;
      int v122 = v121[v220];
      int v221 = (((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1)) * 2) + 1;
      int v123 = v121[v221];
      int * v124 = v62->cache_vals;
      int v223 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1)) & 3) * 2)) + ((((v102 + ((~(((v104 ^ -1) | (-(v104 ^ -1))) >> 31)) & 2)) - (v105 + ((~(((v106 ^ -1) | (-(v106 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v124[v223] = v122;
      int * v126 = v62->cache_vals;
      int v226 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1)) & 3) * 2)) + ((((v102 + ((~(((v104 ^ -1) | (-(v104 ^ -1))) >> 31)) & 2)) - (v105 + ((~(((v106 ^ -1) | (-(v106 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v126[v226] = v123;
      int * v128 = v62->cache_tags;
      int v229 = (int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1);
      v128[v205] = v229;
      int * v130 = v62->cache_dirty;
      v130[v205] = 0;
      int * v132 = v62->cache_age;
      v132[v205] = 1;
      int * v134 = v62->cache_age;
      int v135 = v134[v205];
      int v136 = v134[v179];
      int v235 = v136 + ((int)((unsigned int)(v136 - v135) >> 31));
      v134[v179] = v235;
      int * v138 = v62->cache_age;
      int v139 = v138[v180];
      int v237 = v139 + ((int)((unsigned int)(v139 - v135) >> 31));
      v138[v180] = v237;
      int * v141 = v62->cache_age;
      v141[v205] = 0;
      v144 = v205;
    }
    int * v145 = v62->cache_vals;
    int v240 = v144 * 2;
    int v146 = v145[v240];
    int v241 = (v144 * 2) + 1;
    int v147 = v145[v241];
    int v242 = (((((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1)) & 1) * 2) + ((((v86 + ((~(((v88 ^ -1) | (-(v88 ^ -1))) >> 31)) & 2)) - (v89 + ((~(((v90 ^ -1) | (-(v90 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v145[v242] = v146;
    int * v149 = v62->cache_vals;
    int v245 = ((((((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1)) & 1) * 2) + ((((v86 + ((~(((v88 ^ -1) | (-(v88 ^ -1))) >> 31)) & 2)) - (v89 + ((~(((v90 ^ -1) | (-(v90 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v149[v245] = v147;
    int * v151 = v62->cache_tags;
    int v248 = ((((int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1)) & 1) * 2) + ((((v86 + ((~(((v88 ^ -1) | (-(v88 ^ -1))) >> 31)) & 2)) - (v89 + ((~(((v90 ^ -1) | (-(v90 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v249 = (int)((unsigned int)((int)((unsigned int)v66 >> 2)) >> 1);
    v151[v248] = v249;
    int * v153 = v62->cache_dirty;
    v153[v248] = 0;
    int * v155 = v62->cache_age;
    v155[v248] = 1;
    int * v157 = v62->cache_age;
    int v158 = v157[v248];
    int v159 = v157[v177];
    int v255 = v159 + ((int)((unsigned int)(v159 - v158) >> 31));
    v157[v177] = v255;
    int * v161 = v62->cache_age;
    int v162 = v161[v178];
    int v257 = v162 + ((int)((unsigned int)(v162 - v158) >> 31));
    v161[v178] = v257;
    int * v164 = v62->cache_age;
    v164[v248] = 0;
    v167 = v248;
  }
  int v260 = (v167 * 2) + (((int)((unsigned int)v66 >> 2)) & 1);
  int v168 = v74[v260];
  int * v169 = v62->regs;
  v169[11] = v168;
  struct StateT * v171 = slot_3(v62);
  return v171;
}

struct StateT * slot_7(struct StateT * v590) {
  int v591 = v590->timer;
  int v599 = v591 + 1;
  v590->timer = v599;
  int * v593 = v590->regs;
  int v594 = v593[11];
  int v595 = v593[10];
  int v603 = v594 + v595;
  v593[10] = v603;
  struct StateT * v597 = slot_8(v590);
  return v597;
}

struct StateT * slot_21(struct StateT * v1067) {
  int v1068 = v1067->timer;
  int v1238 = v1068 + 1;
  v1067->timer = v1238;
  int * v1070 = v1067->regs;
  int v1071 = v1070[12];
  int v1072 = v1070[10];
  int * v1073 = v1067->cache_tags;
  int v1243 = (((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1074 = v1073[v1243];
  int v1244 = ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1075 = v1073[v1244];
  int v1245 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1076 = v1073[v1245];
  int v1246 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1077 = v1073[v1246];
  int v1078 = v1067->timer;
  int v1247 = v1078 + ((100 ^ (((~(((v1076 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1076 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1077 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1077 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1074 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1074 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1075 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1075 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1076 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1076 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1077 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1077 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1067->timer = v1247;
  bool v1248 = !(((~(((v1074 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1074 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1075 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1075 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1172;
  if (v1248) {
    int * v1080 = v1067->cache_age;
    int v1250 = ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1075 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1075 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1081 = v1080[v1250];
    int v1082 = v1080[v1243];
    int v1251 = v1082 + ((int)((unsigned int)(v1082 - v1081) >> 31));
    v1080[v1243] = v1251;
    int * v1084 = v1067->cache_age;
    int v1085 = v1084[v1244];
    int v1253 = v1085 + ((int)((unsigned int)(v1085 - v1081) >> 31));
    v1084[v1244] = v1253;
    int * v1087 = v1067->cache_age;
    v1087[v1250] = 0;
    v1172 = v1250;
  } else {
    int * v1090 = v1067->cache_age;
    int v1257 = (((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1091 = v1090[v1257];
    int * v1092 = v1067->cache_tags;
    int v1093 = v1092[v1257];
    int v1094 = v1090[v1244];
    int v1095 = v1092[v1244];
    bool v1259 = !(((~(((v1076 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1076 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1077 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1077 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1149;
    if (v1259) {
      int * v1096 = v1067->cache_age;
      int v1261 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1077 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1077 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1097 = v1096[v1261];
      int v1098 = v1096[v1245];
      int v1262 = v1098 + ((int)((unsigned int)(v1098 - v1097) >> 31));
      v1096[v1245] = v1262;
      int * v1100 = v1067->cache_age;
      int v1101 = v1100[v1246];
      int v1264 = v1101 + ((int)((unsigned int)(v1101 - v1097) >> 31));
      v1100[v1246] = v1264;
      int * v1103 = v1067->cache_age;
      v1103[v1261] = 0;
      v1149 = v1261;
    } else {
      int * v1106 = v1067->cache_age;
      int v1268 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1107 = v1106[v1268];
      int * v1108 = v1067->cache_tags;
      int v1109 = v1108[v1268];
      int v1110 = v1106[v1246];
      int v1111 = v1108[v1246];
      int * v1112 = v1067->cache_dirty;
      int v1271 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1107 + ((~(((v1109 ^ -1) | (-(v1109 ^ -1))) >> 31)) & 2)) - (v1110 + ((~(((v1111 ^ -1) | (-(v1111 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1113 = v1112[v1271];
      bool v1272 = !(v1113 == 0);
      if (v1272) {
        int * v1114 = v1067->cache_tags;
        int v1115 = v1114[v1271];
        int * v1116 = v1067->cache_vals;
        int v1275 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1107 + ((~(((v1109 ^ -1) | (-(v1109 ^ -1))) >> 31)) & 2)) - (v1110 + ((~(((v1111 ^ -1) | (-(v1111 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1117 = v1116[v1275];
        int v1276 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1107 + ((~(((v1109 ^ -1) | (-(v1109 ^ -1))) >> 31)) & 2)) - (v1110 + ((~(((v1111 ^ -1) | (-(v1111 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1118 = v1116[v1276];
        int * v1119 = v1067->mem;
        int v1278 = v1115 * 2;
        v1119[v1278] = v1117;
        int * v1121 = v1067->mem;
        int v1281 = (v1115 * 2) + 1;
        v1121[v1281] = v1118;
        ;
      } else {
        ;
      }
      int * v1126 = v1067->mem;
      int v1286 = ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) * 2;
      int v1127 = v1126[v1286];
      int v1287 = (((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1128 = v1126[v1287];
      int * v1129 = v1067->cache_vals;
      int v1289 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1107 + ((~(((v1109 ^ -1) | (-(v1109 ^ -1))) >> 31)) & 2)) - (v1110 + ((~(((v1111 ^ -1) | (-(v1111 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1129[v1289] = v1127;
      int * v1131 = v1067->cache_vals;
      int v1292 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1107 + ((~(((v1109 ^ -1) | (-(v1109 ^ -1))) >> 31)) & 2)) - (v1110 + ((~(((v1111 ^ -1) | (-(v1111 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1131[v1292] = v1128;
      int * v1133 = v1067->cache_tags;
      int v1295 = (int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1);
      v1133[v1271] = v1295;
      int * v1135 = v1067->cache_dirty;
      v1135[v1271] = 0;
      int * v1137 = v1067->cache_age;
      v1137[v1271] = 1;
      int * v1139 = v1067->cache_age;
      int v1140 = v1139[v1271];
      int v1141 = v1139[v1245];
      int v1301 = v1141 + ((int)((unsigned int)(v1141 - v1140) >> 31));
      v1139[v1245] = v1301;
      int * v1143 = v1067->cache_age;
      int v1144 = v1143[v1246];
      int v1303 = v1144 + ((int)((unsigned int)(v1144 - v1140) >> 31));
      v1143[v1246] = v1303;
      int * v1146 = v1067->cache_age;
      v1146[v1271] = 0;
      v1149 = v1271;
    }
    int * v1150 = v1067->cache_vals;
    int v1306 = v1149 * 2;
    int v1151 = v1150[v1306];
    int v1307 = (v1149 * 2) + 1;
    int v1152 = v1150[v1307];
    int v1308 = (((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1091 + ((~(((v1093 ^ -1) | (-(v1093 ^ -1))) >> 31)) & 2)) - (v1094 + ((~(((v1095 ^ -1) | (-(v1095 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1150[v1308] = v1151;
    int * v1154 = v1067->cache_vals;
    int v1311 = ((((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1091 + ((~(((v1093 ^ -1) | (-(v1093 ^ -1))) >> 31)) & 2)) - (v1094 + ((~(((v1095 ^ -1) | (-(v1095 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1154[v1311] = v1152;
    int * v1156 = v1067->cache_tags;
    int v1314 = ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1091 + ((~(((v1093 ^ -1) | (-(v1093 ^ -1))) >> 31)) & 2)) - (v1094 + ((~(((v1095 ^ -1) | (-(v1095 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1315 = (int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1);
    v1156[v1314] = v1315;
    int * v1158 = v1067->cache_dirty;
    v1158[v1314] = 0;
    int * v1160 = v1067->cache_age;
    v1160[v1314] = 1;
    int * v1162 = v1067->cache_age;
    int v1163 = v1162[v1314];
    int v1164 = v1162[v1243];
    int v1321 = v1164 + ((int)((unsigned int)(v1164 - v1163) >> 31));
    v1162[v1243] = v1321;
    int * v1166 = v1067->cache_age;
    int v1167 = v1166[v1244];
    int v1323 = v1167 + ((int)((unsigned int)(v1167 - v1163) >> 31));
    v1166[v1244] = v1323;
    int * v1169 = v1067->cache_age;
    v1169[v1314] = 0;
    v1172 = v1314;
  }
  int * v1173 = v1067->cache_vals;
  int v1326 = (v1172 * 2) + (((int)((unsigned int)(v1071 + 68) >> 2)) & 1);
  v1173[v1326] = v1072;
  int * v1175 = v1067->cache_tags;
  int v1176 = v1175[v1245];
  int v1177 = v1175[v1246];
  bool v1329 = !(((~(((v1176 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1176 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1177 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1177 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1231;
  if (v1329) {
    int * v1178 = v1067->cache_age;
    int v1331 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1177 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))) | (-(v1177 ^ ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1179 = v1178[v1331];
    int v1180 = v1178[v1245];
    int v1332 = v1180 + ((int)((unsigned int)(v1180 - v1179) >> 31));
    v1178[v1245] = v1332;
    int * v1182 = v1067->cache_age;
    int v1183 = v1182[v1246];
    int v1334 = v1183 + ((int)((unsigned int)(v1183 - v1179) >> 31));
    v1182[v1246] = v1334;
    int * v1185 = v1067->cache_age;
    v1185[v1331] = 0;
    v1231 = v1331;
  } else {
    int * v1188 = v1067->cache_age;
    int v1338 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1189 = v1188[v1338];
    int * v1190 = v1067->cache_tags;
    int v1191 = v1190[v1338];
    int v1192 = v1188[v1246];
    int v1193 = v1190[v1246];
    int * v1194 = v1067->cache_dirty;
    int v1341 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1189 + ((~(((v1191 ^ -1) | (-(v1191 ^ -1))) >> 31)) & 2)) - (v1192 + ((~(((v1193 ^ -1) | (-(v1193 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1195 = v1194[v1341];
    bool v1342 = !(v1195 == 0);
    if (v1342) {
      int * v1196 = v1067->cache_tags;
      int v1197 = v1196[v1341];
      int * v1198 = v1067->cache_vals;
      int v1345 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1189 + ((~(((v1191 ^ -1) | (-(v1191 ^ -1))) >> 31)) & 2)) - (v1192 + ((~(((v1193 ^ -1) | (-(v1193 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1199 = v1198[v1345];
      int v1346 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1189 + ((~(((v1191 ^ -1) | (-(v1191 ^ -1))) >> 31)) & 2)) - (v1192 + ((~(((v1193 ^ -1) | (-(v1193 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1200 = v1198[v1346];
      int * v1201 = v1067->mem;
      int v1348 = v1197 * 2;
      v1201[v1348] = v1199;
      int * v1203 = v1067->mem;
      int v1351 = (v1197 * 2) + 1;
      v1203[v1351] = v1200;
      ;
    } else {
      ;
    }
    int * v1208 = v1067->mem;
    int v1356 = ((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) * 2;
    int v1209 = v1208[v1356];
    int v1357 = (((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1210 = v1208[v1357];
    int * v1211 = v1067->cache_vals;
    int v1359 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1189 + ((~(((v1191 ^ -1) | (-(v1191 ^ -1))) >> 31)) & 2)) - (v1192 + ((~(((v1193 ^ -1) | (-(v1193 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1211[v1359] = v1209;
    int * v1213 = v1067->cache_vals;
    int v1362 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1189 + ((~(((v1191 ^ -1) | (-(v1191 ^ -1))) >> 31)) & 2)) - (v1192 + ((~(((v1193 ^ -1) | (-(v1193 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1213[v1362] = v1210;
    int * v1215 = v1067->cache_tags;
    int v1365 = (int)((unsigned int)((int)((unsigned int)(v1071 + 68) >> 2)) >> 1);
    v1215[v1341] = v1365;
    int * v1217 = v1067->cache_dirty;
    v1217[v1341] = 0;
    int * v1219 = v1067->cache_age;
    v1219[v1341] = 1;
    int * v1221 = v1067->cache_age;
    int v1222 = v1221[v1341];
    int v1223 = v1221[v1245];
    int v1371 = v1223 + ((int)((unsigned int)(v1223 - v1222) >> 31));
    v1221[v1245] = v1371;
    int * v1225 = v1067->cache_age;
    int v1226 = v1225[v1246];
    int v1373 = v1226 + ((int)((unsigned int)(v1226 - v1222) >> 31));
    v1225[v1246] = v1373;
    int * v1228 = v1067->cache_age;
    v1228[v1341] = 0;
    v1231 = v1341;
  }
  int * v1232 = v1067->cache_vals;
  int v1376 = (v1231 * 2) + (((int)((unsigned int)(v1071 + 68) >> 2)) & 1);
  v1232[v1376] = v1072;
  int * v1234 = v1067->cache_dirty;
  v1234[v1231] = 1;
  struct StateT * v1236 = slot_22(v1067);
  return v1236;
}

struct StateT * slot_3(struct StateT * v468) {
  int v469 = v468->timer;
  int v480 = v469 + 1;
  v468->timer = v480;
  int * v471 = v468->regs;
  int v472 = v471[10];
  int v473 = v471[11];
  bool v484 = (v472 ^ -2147483648) >= (v473 ^ -2147483648);
  struct StateT * v478;
  if (v484) {
    struct StateT * v474 = slot_22(v468);
    v478 = v474;
  } else {
    struct StateT * v476 = slot_4(v468);
    v478 = v476;
  }
  return v478;
}

struct StateT * slot_10(struct StateT * v48) {
  int v49 = v48->timer;
  int v56 = v49 + 1;
  v48->timer = v56;
  int * v51 = v48->regs;
  int v52 = v51[10];
  int v59 = v52 + 72;
  v51[10] = v59;
  struct StateT * v54 = slot_11(v48);
  return v54;
}

struct StateT * slot_1(struct StateT * v35) {
  int v36 = v35->timer;
  int v42 = v36 + 1;
  v35->timer = v42;
  int * v38 = v35->regs;
  v38[11] = 0;
  struct StateT * v40 = slot_2(v35);
  return v40;
}

struct StateT * slot_19(struct StateT * v847) {
  int v848 = v847->timer;
  int v958 = v848 + 1;
  v847->timer = v958;
  int * v850 = v847->regs;
  int v851 = v850[12];
  int * v852 = v847->cache_tags;
  int v962 = (((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1)) & 1) * 2;
  int v853 = v852[v962];
  int v963 = ((((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v854 = v852[v963];
  int v964 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1)) & 3) * 2);
  int v855 = v852[v964];
  int v965 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v856 = v852[v965];
  int v857 = v847->timer;
  int v966 = v857 + ((100 ^ (((~(((v855 ^ ((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1))) | (-(v855 ^ ((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v856 ^ ((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1))) | (-(v856 ^ ((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v853 ^ ((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1))) | (-(v853 ^ ((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v854 ^ ((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1))) | (-(v854 ^ ((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v855 ^ ((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1))) | (-(v855 ^ ((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v856 ^ ((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1))) | (-(v856 ^ ((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v847->timer = v966;
  int * v859 = v847->cache_vals;
  bool v967 = !(((~(((v853 ^ ((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1))) | (-(v853 ^ ((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v854 ^ ((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1))) | (-(v854 ^ ((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v952;
  if (v967) {
    int * v860 = v847->cache_age;
    int v969 = ((((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v854 ^ ((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1))) | (-(v854 ^ ((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v861 = v860[v969];
    int v862 = v860[v962];
    int v970 = v862 + ((int)((unsigned int)(v862 - v861) >> 31));
    v860[v962] = v970;
    int * v864 = v847->cache_age;
    int v865 = v864[v963];
    int v972 = v865 + ((int)((unsigned int)(v865 - v861) >> 31));
    v864[v963] = v972;
    int * v867 = v847->cache_age;
    v867[v969] = 0;
    v952 = v969;
  } else {
    int * v870 = v847->cache_age;
    int v976 = (((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1)) & 1) * 2;
    int v871 = v870[v976];
    int * v872 = v847->cache_tags;
    int v873 = v872[v976];
    int v874 = v870[v963];
    int v875 = v872[v963];
    bool v978 = !(((~(((v855 ^ ((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1))) | (-(v855 ^ ((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v856 ^ ((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1))) | (-(v856 ^ ((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v929;
    if (v978) {
      int * v876 = v847->cache_age;
      int v980 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v856 ^ ((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1))) | (-(v856 ^ ((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v877 = v876[v980];
      int v878 = v876[v964];
      int v981 = v878 + ((int)((unsigned int)(v878 - v877) >> 31));
      v876[v964] = v981;
      int * v880 = v847->cache_age;
      int v881 = v880[v965];
      int v983 = v881 + ((int)((unsigned int)(v881 - v877) >> 31));
      v880[v965] = v983;
      int * v883 = v847->cache_age;
      v883[v980] = 0;
      v929 = v980;
    } else {
      int * v886 = v847->cache_age;
      int v987 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1)) & 3) * 2);
      int v887 = v886[v987];
      int * v888 = v847->cache_tags;
      int v889 = v888[v987];
      int v890 = v886[v965];
      int v891 = v888[v965];
      int * v892 = v847->cache_dirty;
      int v990 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v887 + ((~(((v889 ^ -1) | (-(v889 ^ -1))) >> 31)) & 2)) - (v890 + ((~(((v891 ^ -1) | (-(v891 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v893 = v892[v990];
      bool v991 = !(v893 == 0);
      if (v991) {
        int * v894 = v847->cache_tags;
        int v895 = v894[v990];
        int * v896 = v847->cache_vals;
        int v994 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v887 + ((~(((v889 ^ -1) | (-(v889 ^ -1))) >> 31)) & 2)) - (v890 + ((~(((v891 ^ -1) | (-(v891 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v897 = v896[v994];
        int v995 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v887 + ((~(((v889 ^ -1) | (-(v889 ^ -1))) >> 31)) & 2)) - (v890 + ((~(((v891 ^ -1) | (-(v891 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v898 = v896[v995];
        int * v899 = v847->mem;
        int v997 = v895 * 2;
        v899[v997] = v897;
        int * v901 = v847->mem;
        int v1000 = (v895 * 2) + 1;
        v901[v1000] = v898;
        ;
      } else {
        ;
      }
      int * v906 = v847->mem;
      int v1005 = ((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1)) * 2;
      int v907 = v906[v1005];
      int v1006 = (((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1)) * 2) + 1;
      int v908 = v906[v1006];
      int * v909 = v847->cache_vals;
      int v1008 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v887 + ((~(((v889 ^ -1) | (-(v889 ^ -1))) >> 31)) & 2)) - (v890 + ((~(((v891 ^ -1) | (-(v891 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v909[v1008] = v907;
      int * v911 = v847->cache_vals;
      int v1011 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v887 + ((~(((v889 ^ -1) | (-(v889 ^ -1))) >> 31)) & 2)) - (v890 + ((~(((v891 ^ -1) | (-(v891 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v911[v1011] = v908;
      int * v913 = v847->cache_tags;
      int v1014 = (int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1);
      v913[v990] = v1014;
      int * v915 = v847->cache_dirty;
      v915[v990] = 0;
      int * v917 = v847->cache_age;
      v917[v990] = 1;
      int * v919 = v847->cache_age;
      int v920 = v919[v990];
      int v921 = v919[v964];
      int v1020 = v921 + ((int)((unsigned int)(v921 - v920) >> 31));
      v919[v964] = v1020;
      int * v923 = v847->cache_age;
      int v924 = v923[v965];
      int v1022 = v924 + ((int)((unsigned int)(v924 - v920) >> 31));
      v923[v965] = v1022;
      int * v926 = v847->cache_age;
      v926[v990] = 0;
      v929 = v990;
    }
    int * v930 = v847->cache_vals;
    int v1025 = v929 * 2;
    int v931 = v930[v1025];
    int v1026 = (v929 * 2) + 1;
    int v932 = v930[v1026];
    int v1027 = (((((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v871 + ((~(((v873 ^ -1) | (-(v873 ^ -1))) >> 31)) & 2)) - (v874 + ((~(((v875 ^ -1) | (-(v875 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v930[v1027] = v931;
    int * v934 = v847->cache_vals;
    int v1030 = ((((((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v871 + ((~(((v873 ^ -1) | (-(v873 ^ -1))) >> 31)) & 2)) - (v874 + ((~(((v875 ^ -1) | (-(v875 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v934[v1030] = v932;
    int * v936 = v847->cache_tags;
    int v1033 = ((((int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v871 + ((~(((v873 ^ -1) | (-(v873 ^ -1))) >> 31)) & 2)) - (v874 + ((~(((v875 ^ -1) | (-(v875 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1034 = (int)((unsigned int)((int)((unsigned int)(v851 + 68) >> 2)) >> 1);
    v936[v1033] = v1034;
    int * v938 = v847->cache_dirty;
    v938[v1033] = 0;
    int * v940 = v847->cache_age;
    v940[v1033] = 1;
    int * v942 = v847->cache_age;
    int v943 = v942[v1033];
    int v944 = v942[v962];
    int v1040 = v944 + ((int)((unsigned int)(v944 - v943) >> 31));
    v942[v962] = v1040;
    int * v946 = v847->cache_age;
    int v947 = v946[v963];
    int v1042 = v947 + ((int)((unsigned int)(v947 - v943) >> 31));
    v946[v963] = v1042;
    int * v949 = v847->cache_age;
    v949[v1033] = 0;
    v952 = v1033;
  }
  int v1045 = (v952 * 2) + (((int)((unsigned int)(v851 + 68) >> 2)) & 1);
  int v953 = v859[v1045];
  int * v954 = v847->regs;
  v954[11] = v953;
  struct StateT * v956 = slot_20(v847);
  return v956;
}

struct StateT * slot_13(struct StateT * v522) {
  int v523 = v522->timer;
  int v530 = v523 + 1;
  v522->timer = v530;
  int * v525 = v522->regs;
  int v526 = v525[11];
  int v533 = v526 + 4;
  v525[11] = v533;
  struct StateT * v528 = slot_14(v522);
  return v528;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v13 = v3 + 1;
  v2->timer = v13;
  int * v5 = v2->regs;
  int v6 = v5[10];
  bool v16 = v6 == 0;
  struct StateT * v11;
  if (v16) {
    struct StateT * v7 = slot_9(v2);
    v11 = v7;
  } else {
    struct StateT * v9 = slot_1(v2);
    v11 = v9;
  }
  return v11;
}

struct StateT * slot_14(struct StateT * v549) {
  int v550 = v549->timer;
  int v556 = v550 + 1;
  v549->timer = v556;
  int * v552 = v549->regs;
  v552[12] = 0;
  struct StateT * v554 = slot_15(v549);
  return v554;
}

struct StateT * slot_17(struct StateT * v628) {
  int v629 = v628->timer;
  int v637 = v629 + 1;
  v628->timer = v637;
  int * v631 = v628->regs;
  int v632 = v631[11];
  int v633 = v631[10];
  int v641 = v632 + v633;
  v631[10] = v641;
  struct StateT * v635 = slot_18(v628);
  return v635;
}

struct StateT * slot_20(struct StateT * v1051) {
  int v1052 = v1051->timer;
  int v1060 = v1052 + 1;
  v1051->timer = v1060;
  int * v1054 = v1051->regs;
  int v1055 = v1054[11];
  int v1056 = v1054[10];
  int v1064 = v1055 & v1056;
  v1054[10] = v1064;
  struct StateT * v1058 = slot_21(v1051);
  return v1058;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_8(struct StateT * v620) {
  int v621 = v620->timer;
  int v625 = v621 + 1;
  v620->timer = v625;
  struct StateT * v623 = slot_11(v620);
  return v623;
}

struct StateT * slot_4(struct StateT * v508) {
  int v509 = v508->timer;
  int v516 = v509 + 1;
  v508->timer = v516;
  int * v511 = v508->regs;
  int v512 = v511[10];
  int v519 = v512 << 2;
  v511[10] = v519;
  struct StateT * v514 = slot_5(v508);
  return v514;
}

struct StateT * slot_15(struct StateT * v576) {
  int v577 = v576->timer;
  int v584 = v577 + 1;
  v576->timer = v584;
  int * v579 = v576->regs;
  int v580 = v579[10];
  int v587 = v580 << 29;
  v579[10] = v587;
  struct StateT * v582 = slot_16(v576);
  return v582;
}

struct StateT * slot_18(struct StateT * v644) {
  int v645 = v644->timer;
  int v755 = v645 + 1;
  v644->timer = v755;
  int * v647 = v644->regs;
  int v648 = v647[10];
  int * v649 = v644->cache_tags;
  int v759 = (((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1)) & 1) * 2;
  int v650 = v649[v759];
  int v760 = ((((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1)) & 1) * 2) + 1;
  int v651 = v649[v760];
  int v761 = 4 + ((((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1)) & 3) * 2);
  int v652 = v649[v761];
  int v762 = (4 + ((((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v653 = v649[v762];
  int v654 = v644->timer;
  int v763 = v654 + ((100 ^ (((~(((v652 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))) | (-(v652 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))))) >> 31)) | (~(((v653 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))) | (-(v653 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v650 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))) | (-(v650 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))))) >> 31)) | (~(((v651 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))) | (-(v651 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v652 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))) | (-(v652 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))))) >> 31)) | (~(((v653 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))) | (-(v653 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))))) >> 31))) & 104)))));
  v644->timer = v763;
  int * v656 = v644->cache_vals;
  bool v764 = !(((~(((v650 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))) | (-(v650 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))))) >> 31)) | (~(((v651 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))) | (-(v651 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))))) >> 31))) == 0);
  int v749;
  if (v764) {
    int * v657 = v644->cache_age;
    int v766 = ((((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1)) & 1) * 2) + ((~(((v651 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))) | (-(v651 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))))) >> 31)) & 1);
    int v658 = v657[v766];
    int v659 = v657[v759];
    int v767 = v659 + ((int)((unsigned int)(v659 - v658) >> 31));
    v657[v759] = v767;
    int * v661 = v644->cache_age;
    int v662 = v661[v760];
    int v769 = v662 + ((int)((unsigned int)(v662 - v658) >> 31));
    v661[v760] = v769;
    int * v664 = v644->cache_age;
    v664[v766] = 0;
    v749 = v766;
  } else {
    int * v667 = v644->cache_age;
    int v773 = (((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1)) & 1) * 2;
    int v668 = v667[v773];
    int * v669 = v644->cache_tags;
    int v670 = v669[v773];
    int v671 = v667[v760];
    int v672 = v669[v760];
    bool v775 = !(((~(((v652 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))) | (-(v652 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))))) >> 31)) | (~(((v653 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))) | (-(v653 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))))) >> 31))) == 0);
    int v726;
    if (v775) {
      int * v673 = v644->cache_age;
      int v777 = (4 + ((((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1)) & 3) * 2)) + ((~(((v653 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))) | (-(v653 ^ ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1))))) >> 31)) & 1);
      int v674 = v673[v777];
      int v675 = v673[v761];
      int v778 = v675 + ((int)((unsigned int)(v675 - v674) >> 31));
      v673[v761] = v778;
      int * v677 = v644->cache_age;
      int v678 = v677[v762];
      int v780 = v678 + ((int)((unsigned int)(v678 - v674) >> 31));
      v677[v762] = v780;
      int * v680 = v644->cache_age;
      v680[v777] = 0;
      v726 = v777;
    } else {
      int * v683 = v644->cache_age;
      int v784 = 4 + ((((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1)) & 3) * 2);
      int v684 = v683[v784];
      int * v685 = v644->cache_tags;
      int v686 = v685[v784];
      int v687 = v683[v762];
      int v688 = v685[v762];
      int * v689 = v644->cache_dirty;
      int v787 = (4 + ((((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1)) & 3) * 2)) + ((((v684 + ((~(((v686 ^ -1) | (-(v686 ^ -1))) >> 31)) & 2)) - (v687 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v690 = v689[v787];
      bool v788 = !(v690 == 0);
      if (v788) {
        int * v691 = v644->cache_tags;
        int v692 = v691[v787];
        int * v693 = v644->cache_vals;
        int v791 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1)) & 3) * 2)) + ((((v684 + ((~(((v686 ^ -1) | (-(v686 ^ -1))) >> 31)) & 2)) - (v687 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v694 = v693[v791];
        int v792 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1)) & 3) * 2)) + ((((v684 + ((~(((v686 ^ -1) | (-(v686 ^ -1))) >> 31)) & 2)) - (v687 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v695 = v693[v792];
        int * v696 = v644->mem;
        int v794 = v692 * 2;
        v696[v794] = v694;
        int * v698 = v644->mem;
        int v797 = (v692 * 2) + 1;
        v698[v797] = v695;
        ;
      } else {
        ;
      }
      int * v703 = v644->mem;
      int v802 = ((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1)) * 2;
      int v704 = v703[v802];
      int v803 = (((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1)) * 2) + 1;
      int v705 = v703[v803];
      int * v706 = v644->cache_vals;
      int v805 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1)) & 3) * 2)) + ((((v684 + ((~(((v686 ^ -1) | (-(v686 ^ -1))) >> 31)) & 2)) - (v687 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v706[v805] = v704;
      int * v708 = v644->cache_vals;
      int v808 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1)) & 3) * 2)) + ((((v684 + ((~(((v686 ^ -1) | (-(v686 ^ -1))) >> 31)) & 2)) - (v687 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v708[v808] = v705;
      int * v710 = v644->cache_tags;
      int v811 = (int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1);
      v710[v787] = v811;
      int * v712 = v644->cache_dirty;
      v712[v787] = 0;
      int * v714 = v644->cache_age;
      v714[v787] = 1;
      int * v716 = v644->cache_age;
      int v717 = v716[v787];
      int v718 = v716[v761];
      int v817 = v718 + ((int)((unsigned int)(v718 - v717) >> 31));
      v716[v761] = v817;
      int * v720 = v644->cache_age;
      int v721 = v720[v762];
      int v819 = v721 + ((int)((unsigned int)(v721 - v717) >> 31));
      v720[v762] = v819;
      int * v723 = v644->cache_age;
      v723[v787] = 0;
      v726 = v787;
    }
    int * v727 = v644->cache_vals;
    int v822 = v726 * 2;
    int v728 = v727[v822];
    int v823 = (v726 * 2) + 1;
    int v729 = v727[v823];
    int v824 = (((((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1)) & 1) * 2) + ((((v668 + ((~(((v670 ^ -1) | (-(v670 ^ -1))) >> 31)) & 2)) - (v671 + ((~(((v672 ^ -1) | (-(v672 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v727[v824] = v728;
    int * v731 = v644->cache_vals;
    int v827 = ((((((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1)) & 1) * 2) + ((((v668 + ((~(((v670 ^ -1) | (-(v670 ^ -1))) >> 31)) & 2)) - (v671 + ((~(((v672 ^ -1) | (-(v672 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v731[v827] = v729;
    int * v733 = v644->cache_tags;
    int v830 = ((((int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1)) & 1) * 2) + ((((v668 + ((~(((v670 ^ -1) | (-(v670 ^ -1))) >> 31)) & 2)) - (v671 + ((~(((v672 ^ -1) | (-(v672 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v831 = (int)((unsigned int)((int)((unsigned int)v648 >> 2)) >> 1);
    v733[v830] = v831;
    int * v735 = v644->cache_dirty;
    v735[v830] = 0;
    int * v737 = v644->cache_age;
    v737[v830] = 1;
    int * v739 = v644->cache_age;
    int v740 = v739[v830];
    int v741 = v739[v759];
    int v837 = v741 + ((int)((unsigned int)(v741 - v740) >> 31));
    v739[v759] = v837;
    int * v743 = v644->cache_age;
    int v744 = v743[v760];
    int v839 = v744 + ((int)((unsigned int)(v744 - v740) >> 31));
    v743[v760] = v839;
    int * v746 = v644->cache_age;
    v746[v830] = 0;
    v749 = v830;
  }
  int v842 = (v749 * 2) + (((int)((unsigned int)v648 >> 2)) & 1);
  int v750 = v656[v842];
  int * v751 = v644->regs;
  v751[10] = v750;
  struct StateT * v753 = slot_19(v644);
  return v753;
}

struct StateT * slot_9(struct StateT * v22) {
  int v23 = v22->timer;
  int v29 = v23 + 1;
  v22->timer = v29;
  int * v25 = v22->regs;
  v25[10] = 0;
  struct StateT * v27 = slot_10(v22);
  return v27;
}

struct StateT * slot_22(struct StateT * v503) {
  int v504 = v503->timer;
  int v507 = v504 + 1;
  v503->timer = v507;
  return v503;
}

struct StateT * slot_11(struct StateT * v265) {
  int v266 = v265->timer;
  int v376 = v266 + 1;
  v265->timer = v376;
  int * v268 = v265->regs;
  int v269 = v268[10];
  int * v270 = v265->cache_tags;
  int v380 = (((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1)) & 1) * 2;
  int v271 = v270[v380];
  int v381 = ((((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1)) & 1) * 2) + 1;
  int v272 = v270[v381];
  int v382 = 4 + ((((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1)) & 3) * 2);
  int v273 = v270[v382];
  int v383 = (4 + ((((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v274 = v270[v383];
  int v275 = v265->timer;
  int v384 = v275 + ((100 ^ (((~(((v273 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))) | (-(v273 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))))) >> 31)) | (~(((v274 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))) | (-(v274 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v271 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))) | (-(v271 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))))) >> 31)) | (~(((v272 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))) | (-(v272 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v273 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))) | (-(v273 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))))) >> 31)) | (~(((v274 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))) | (-(v274 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))))) >> 31))) & 104)))));
  v265->timer = v384;
  int * v277 = v265->cache_vals;
  bool v385 = !(((~(((v271 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))) | (-(v271 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))))) >> 31)) | (~(((v272 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))) | (-(v272 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))))) >> 31))) == 0);
  int v370;
  if (v385) {
    int * v278 = v265->cache_age;
    int v387 = ((((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1)) & 1) * 2) + ((~(((v272 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))) | (-(v272 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))))) >> 31)) & 1);
    int v279 = v278[v387];
    int v280 = v278[v380];
    int v388 = v280 + ((int)((unsigned int)(v280 - v279) >> 31));
    v278[v380] = v388;
    int * v282 = v265->cache_age;
    int v283 = v282[v381];
    int v390 = v283 + ((int)((unsigned int)(v283 - v279) >> 31));
    v282[v381] = v390;
    int * v285 = v265->cache_age;
    v285[v387] = 0;
    v370 = v387;
  } else {
    int * v288 = v265->cache_age;
    int v394 = (((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1)) & 1) * 2;
    int v289 = v288[v394];
    int * v290 = v265->cache_tags;
    int v291 = v290[v394];
    int v292 = v288[v381];
    int v293 = v290[v381];
    bool v396 = !(((~(((v273 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))) | (-(v273 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))))) >> 31)) | (~(((v274 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))) | (-(v274 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))))) >> 31))) == 0);
    int v347;
    if (v396) {
      int * v294 = v265->cache_age;
      int v398 = (4 + ((((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1)) & 3) * 2)) + ((~(((v274 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))) | (-(v274 ^ ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1))))) >> 31)) & 1);
      int v295 = v294[v398];
      int v296 = v294[v382];
      int v399 = v296 + ((int)((unsigned int)(v296 - v295) >> 31));
      v294[v382] = v399;
      int * v298 = v265->cache_age;
      int v299 = v298[v383];
      int v401 = v299 + ((int)((unsigned int)(v299 - v295) >> 31));
      v298[v383] = v401;
      int * v301 = v265->cache_age;
      v301[v398] = 0;
      v347 = v398;
    } else {
      int * v304 = v265->cache_age;
      int v405 = 4 + ((((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1)) & 3) * 2);
      int v305 = v304[v405];
      int * v306 = v265->cache_tags;
      int v307 = v306[v405];
      int v308 = v304[v383];
      int v309 = v306[v383];
      int * v310 = v265->cache_dirty;
      int v408 = (4 + ((((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1)) & 3) * 2)) + ((((v305 + ((~(((v307 ^ -1) | (-(v307 ^ -1))) >> 31)) & 2)) - (v308 + ((~(((v309 ^ -1) | (-(v309 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v311 = v310[v408];
      bool v409 = !(v311 == 0);
      if (v409) {
        int * v312 = v265->cache_tags;
        int v313 = v312[v408];
        int * v314 = v265->cache_vals;
        int v412 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1)) & 3) * 2)) + ((((v305 + ((~(((v307 ^ -1) | (-(v307 ^ -1))) >> 31)) & 2)) - (v308 + ((~(((v309 ^ -1) | (-(v309 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v315 = v314[v412];
        int v413 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1)) & 3) * 2)) + ((((v305 + ((~(((v307 ^ -1) | (-(v307 ^ -1))) >> 31)) & 2)) - (v308 + ((~(((v309 ^ -1) | (-(v309 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v316 = v314[v413];
        int * v317 = v265->mem;
        int v415 = v313 * 2;
        v317[v415] = v315;
        int * v319 = v265->mem;
        int v418 = (v313 * 2) + 1;
        v319[v418] = v316;
        ;
      } else {
        ;
      }
      int * v324 = v265->mem;
      int v423 = ((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1)) * 2;
      int v325 = v324[v423];
      int v424 = (((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1)) * 2) + 1;
      int v326 = v324[v424];
      int * v327 = v265->cache_vals;
      int v426 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1)) & 3) * 2)) + ((((v305 + ((~(((v307 ^ -1) | (-(v307 ^ -1))) >> 31)) & 2)) - (v308 + ((~(((v309 ^ -1) | (-(v309 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v327[v426] = v325;
      int * v329 = v265->cache_vals;
      int v429 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1)) & 3) * 2)) + ((((v305 + ((~(((v307 ^ -1) | (-(v307 ^ -1))) >> 31)) & 2)) - (v308 + ((~(((v309 ^ -1) | (-(v309 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v329[v429] = v326;
      int * v331 = v265->cache_tags;
      int v432 = (int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1);
      v331[v408] = v432;
      int * v333 = v265->cache_dirty;
      v333[v408] = 0;
      int * v335 = v265->cache_age;
      v335[v408] = 1;
      int * v337 = v265->cache_age;
      int v338 = v337[v408];
      int v339 = v337[v382];
      int v438 = v339 + ((int)((unsigned int)(v339 - v338) >> 31));
      v337[v382] = v438;
      int * v341 = v265->cache_age;
      int v342 = v341[v383];
      int v440 = v342 + ((int)((unsigned int)(v342 - v338) >> 31));
      v341[v383] = v440;
      int * v344 = v265->cache_age;
      v344[v408] = 0;
      v347 = v408;
    }
    int * v348 = v265->cache_vals;
    int v443 = v347 * 2;
    int v349 = v348[v443];
    int v444 = (v347 * 2) + 1;
    int v350 = v348[v444];
    int v445 = (((((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1)) & 1) * 2) + ((((v289 + ((~(((v291 ^ -1) | (-(v291 ^ -1))) >> 31)) & 2)) - (v292 + ((~(((v293 ^ -1) | (-(v293 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v348[v445] = v349;
    int * v352 = v265->cache_vals;
    int v448 = ((((((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1)) & 1) * 2) + ((((v289 + ((~(((v291 ^ -1) | (-(v291 ^ -1))) >> 31)) & 2)) - (v292 + ((~(((v293 ^ -1) | (-(v293 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v352[v448] = v350;
    int * v354 = v265->cache_tags;
    int v451 = ((((int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1)) & 1) * 2) + ((((v289 + ((~(((v291 ^ -1) | (-(v291 ^ -1))) >> 31)) & 2)) - (v292 + ((~(((v293 ^ -1) | (-(v293 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v452 = (int)((unsigned int)((int)((unsigned int)v269 >> 2)) >> 1);
    v354[v451] = v452;
    int * v356 = v265->cache_dirty;
    v356[v451] = 0;
    int * v358 = v265->cache_age;
    v358[v451] = 1;
    int * v360 = v265->cache_age;
    int v361 = v360[v451];
    int v362 = v360[v380];
    int v458 = v362 + ((int)((unsigned int)(v362 - v361) >> 31));
    v360[v380] = v458;
    int * v364 = v265->cache_age;
    int v365 = v364[v381];
    int v460 = v365 + ((int)((unsigned int)(v365 - v361) >> 31));
    v364[v381] = v460;
    int * v367 = v265->cache_age;
    v367[v451] = 0;
    v370 = v451;
  }
  int v463 = (v370 * 2) + (((int)((unsigned int)v269 >> 2)) & 1);
  int v371 = v277[v463];
  int * v372 = v265->regs;
  v372[10] = v371;
  struct StateT * v374 = slot_12(v265);
  return v374;
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