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

struct StateT * slot_6(struct StateT * v92);
struct StateT * slot_16(struct StateT * v656);
struct StateT * slot_5(struct StateT * v72);
struct StateT * slot_2(struct StateT * v30);
struct StateT * slot_7(struct StateT * v106);
struct StateT * slot_21(struct StateT * v748);
struct StateT * slot_3(struct StateT * v38);
struct StateT * slot_10(struct StateT * v580);
struct StateT * slot_1(struct StateT * v17);
struct StateT * slot_13(struct StateT * v593);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v614);
struct StateT * slot_17(struct StateT * v702);
struct StateT * slot_20(struct StateT * v728);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v317);
struct StateT * slot_4(struct StateT * v58);
struct StateT * slot_15(struct StateT * v635);
struct StateT * slot_18(struct StateT * v715);
struct StateT * slot_9(struct StateT * v528);
struct StateT * slot_22(struct StateT * v952);
struct StateT * slot_11(struct StateT * v585);
struct StateT * slot_6(struct StateT * v92) {
  int v93 = v92->timer;
  int v100 = v93 + 1;
  v92->timer = v100;
  int * v95 = v92->regs;
  int v96 = v95[13];
  v95[13] = v96;
  struct StateT * v98 = slot_7(v92);
  return v98;
}

struct StateT * slot_16(struct StateT * v656) {
  int * v657 = v656->regs;
  int v658 = v657[14];
  int v659 = v657[15];
  bool v683 = !(v658 == v659);
  struct StateT * v678;
  if (v683) {
    int v660 = v656->timer;
    int v684 = v660 + 15;
    v656->timer = v684;
    int * v662 = v656->saved_regs;
    int v663 = v662[11];
    int * v664 = v656->regs;
    v664[11] = v663;
    int * v666 = v656->saved_regs;
    int v667 = v666[12];
    int * v668 = v656->regs;
    v668[12] = v667;
    int * v670 = v656->saved_regs;
    int v671 = v670[13];
    int * v672 = v656->regs;
    v672[13] = v671;
    struct StateT * v674 = slot_17(v656);
    v678 = v674;
  } else {
    struct StateT * v676 = slot_18(v656);
    v678 = v676;
  }
  return v678;
}

struct StateT * slot_5(struct StateT * v72) {
  int * v73 = v72->saved_regs;
  int * v74 = v72->regs;
  int v75 = v74[13];
  v73[13] = v75;
  int v77 = v72->timer;
  int v87 = v77 + 1;
  v72->timer = v87;
  int * v79 = v72->regs;
  v79[13] = 0;
  struct StateT * v81 = slot_6(v72);
  return v81;
}

struct StateT * slot_2(struct StateT * v30) {
  int v31 = v30->timer;
  int v35 = v31 + 1;
  v30->timer = v35;
  struct StateT * v33 = slot_3(v30);
  return v33;
}

struct StateT * slot_7(struct StateT * v106) {
  int * v107 = v106->saved_regs;
  int * v108 = v106->regs;
  int v109 = v108[14];
  v107[14] = v109;
  int v111 = v106->timer;
  int v225 = v111 + 1;
  v106->timer = v225;
  int * v113 = v106->regs;
  int v114 = v113[12];
  int * v115 = v106->cache_tags;
  int v229 = (((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1)) & 1) * 2;
  int v116 = v115[v229];
  int v230 = ((((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1)) & 1) * 2) + 1;
  int v117 = v115[v230];
  int v231 = 4 + ((((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1)) & 3) * 2);
  int v118 = v115[v231];
  int v232 = (4 + ((((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v119 = v115[v232];
  int v120 = v106->timer;
  int v233 = v120 + ((100 ^ (((~(((v118 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))) | (-(v118 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))))) >> 31)) | (~(((v119 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))) | (-(v119 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v116 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))) | (-(v116 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))))) >> 31)) | (~(((v117 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))) | (-(v117 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v118 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))) | (-(v118 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))))) >> 31)) | (~(((v119 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))) | (-(v119 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))))) >> 31))) & 104)))));
  v106->timer = v233;
  int * v122 = v106->cache_vals;
  bool v234 = !(((~(((v116 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))) | (-(v116 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))))) >> 31)) | (~(((v117 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))) | (-(v117 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))))) >> 31))) == 0);
  int v215;
  if (v234) {
    int * v123 = v106->cache_age;
    int v236 = ((((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1)) & 1) * 2) + ((~(((v117 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))) | (-(v117 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))))) >> 31)) & 1);
    int v124 = v123[v236];
    int v125 = v123[v229];
    int v237 = v125 + ((int)((unsigned int)(v125 - v124) >> 31));
    v123[v229] = v237;
    int * v127 = v106->cache_age;
    int v128 = v127[v230];
    int v239 = v128 + ((int)((unsigned int)(v128 - v124) >> 31));
    v127[v230] = v239;
    int * v130 = v106->cache_age;
    v130[v236] = 0;
    v215 = v236;
  } else {
    int * v133 = v106->cache_age;
    int v243 = (((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1)) & 1) * 2;
    int v134 = v133[v243];
    int * v135 = v106->cache_tags;
    int v136 = v135[v243];
    int v137 = v133[v230];
    int v138 = v135[v230];
    bool v245 = !(((~(((v118 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))) | (-(v118 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))))) >> 31)) | (~(((v119 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))) | (-(v119 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))))) >> 31))) == 0);
    int v192;
    if (v245) {
      int * v139 = v106->cache_age;
      int v247 = (4 + ((((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1)) & 3) * 2)) + ((~(((v119 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))) | (-(v119 ^ ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1))))) >> 31)) & 1);
      int v140 = v139[v247];
      int v141 = v139[v231];
      int v248 = v141 + ((int)((unsigned int)(v141 - v140) >> 31));
      v139[v231] = v248;
      int * v143 = v106->cache_age;
      int v144 = v143[v232];
      int v250 = v144 + ((int)((unsigned int)(v144 - v140) >> 31));
      v143[v232] = v250;
      int * v146 = v106->cache_age;
      v146[v247] = 0;
      v192 = v247;
    } else {
      int * v149 = v106->cache_age;
      int v254 = 4 + ((((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1)) & 3) * 2);
      int v150 = v149[v254];
      int * v151 = v106->cache_tags;
      int v152 = v151[v254];
      int v153 = v149[v232];
      int v154 = v151[v232];
      int * v155 = v106->cache_dirty;
      int v257 = (4 + ((((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1)) & 3) * 2)) + ((((v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2)) - (v153 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v156 = v155[v257];
      bool v258 = !(v156 == 0);
      if (v258) {
        int * v157 = v106->cache_tags;
        int v158 = v157[v257];
        int * v159 = v106->cache_vals;
        int v261 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1)) & 3) * 2)) + ((((v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2)) - (v153 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v160 = v159[v261];
        int v262 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1)) & 3) * 2)) + ((((v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2)) - (v153 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v161 = v159[v262];
        int * v162 = v106->mem;
        int v264 = v158 * 2;
        v162[v264] = v160;
        int * v164 = v106->mem;
        int v267 = (v158 * 2) + 1;
        v164[v267] = v161;
        ;
      } else {
        ;
      }
      int * v169 = v106->mem;
      int v272 = ((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1)) * 2;
      int v170 = v169[v272];
      int v273 = (((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1)) * 2) + 1;
      int v171 = v169[v273];
      int * v172 = v106->cache_vals;
      int v275 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1)) & 3) * 2)) + ((((v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2)) - (v153 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v172[v275] = v170;
      int * v174 = v106->cache_vals;
      int v278 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1)) & 3) * 2)) + ((((v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2)) - (v153 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v174[v278] = v171;
      int * v176 = v106->cache_tags;
      int v281 = (int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1);
      v176[v257] = v281;
      int * v178 = v106->cache_dirty;
      v178[v257] = 0;
      int * v180 = v106->cache_age;
      v180[v257] = 1;
      int * v182 = v106->cache_age;
      int v183 = v182[v257];
      int v184 = v182[v231];
      int v287 = v184 + ((int)((unsigned int)(v184 - v183) >> 31));
      v182[v231] = v287;
      int * v186 = v106->cache_age;
      int v187 = v186[v232];
      int v289 = v187 + ((int)((unsigned int)(v187 - v183) >> 31));
      v186[v232] = v289;
      int * v189 = v106->cache_age;
      v189[v257] = 0;
      v192 = v257;
    }
    int * v193 = v106->cache_vals;
    int v292 = v192 * 2;
    int v194 = v193[v292];
    int v293 = (v192 * 2) + 1;
    int v195 = v193[v293];
    int v294 = (((((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1)) & 1) * 2) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v137 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v193[v294] = v194;
    int * v197 = v106->cache_vals;
    int v297 = ((((((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1)) & 1) * 2) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v137 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v197[v297] = v195;
    int * v199 = v106->cache_tags;
    int v300 = ((((int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1)) & 1) * 2) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v137 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v301 = (int)((unsigned int)((int)((unsigned int)v114 >> 2)) >> 1);
    v199[v300] = v301;
    int * v201 = v106->cache_dirty;
    v201[v300] = 0;
    int * v203 = v106->cache_age;
    v203[v300] = 1;
    int * v205 = v106->cache_age;
    int v206 = v205[v300];
    int v207 = v205[v229];
    int v307 = v207 + ((int)((unsigned int)(v207 - v206) >> 31));
    v205[v229] = v307;
    int * v209 = v106->cache_age;
    int v210 = v209[v230];
    int v309 = v210 + ((int)((unsigned int)(v210 - v206) >> 31));
    v209[v230] = v309;
    int * v212 = v106->cache_age;
    v212[v300] = 0;
    v215 = v300;
  }
  int v312 = (v215 * 2) + (((int)((unsigned int)v114 >> 2)) & 1);
  int v216 = v122[v312];
  int * v217 = v106->regs;
  v217[14] = v216;
  struct StateT * v219 = slot_8(v106);
  return v219;
}

struct StateT * slot_21(struct StateT * v748) {
  int v749 = v748->timer;
  int v859 = v749 + 1;
  v748->timer = v859;
  int * v751 = v748->regs;
  int v752 = v751[12];
  int * v753 = v748->cache_tags;
  int v863 = (((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 1) * 2;
  int v754 = v753[v863];
  int v864 = ((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 1) * 2) + 1;
  int v755 = v753[v864];
  int v865 = 4 + ((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 3) * 2);
  int v756 = v753[v865];
  int v866 = (4 + ((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v757 = v753[v866];
  int v758 = v748->timer;
  int v867 = v758 + ((100 ^ (((~(((v756 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))) | (-(v756 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))))) >> 31)) | (~(((v757 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))) | (-(v757 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v754 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))) | (-(v754 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))))) >> 31)) | (~(((v755 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))) | (-(v755 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v756 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))) | (-(v756 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))))) >> 31)) | (~(((v757 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))) | (-(v757 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))))) >> 31))) & 104)))));
  v748->timer = v867;
  int * v760 = v748->cache_vals;
  bool v868 = !(((~(((v754 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))) | (-(v754 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))))) >> 31)) | (~(((v755 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))) | (-(v755 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))))) >> 31))) == 0);
  int v853;
  if (v868) {
    int * v761 = v748->cache_age;
    int v870 = ((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 1) * 2) + ((~(((v755 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))) | (-(v755 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))))) >> 31)) & 1);
    int v762 = v761[v870];
    int v763 = v761[v863];
    int v871 = v763 + ((int)((unsigned int)(v763 - v762) >> 31));
    v761[v863] = v871;
    int * v765 = v748->cache_age;
    int v766 = v765[v864];
    int v873 = v766 + ((int)((unsigned int)(v766 - v762) >> 31));
    v765[v864] = v873;
    int * v768 = v748->cache_age;
    v768[v870] = 0;
    v853 = v870;
  } else {
    int * v771 = v748->cache_age;
    int v877 = (((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 1) * 2;
    int v772 = v771[v877];
    int * v773 = v748->cache_tags;
    int v774 = v773[v877];
    int v775 = v771[v864];
    int v776 = v773[v864];
    bool v879 = !(((~(((v756 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))) | (-(v756 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))))) >> 31)) | (~(((v757 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))) | (-(v757 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))))) >> 31))) == 0);
    int v830;
    if (v879) {
      int * v777 = v748->cache_age;
      int v881 = (4 + ((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 3) * 2)) + ((~(((v757 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))) | (-(v757 ^ ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1))))) >> 31)) & 1);
      int v778 = v777[v881];
      int v779 = v777[v865];
      int v882 = v779 + ((int)((unsigned int)(v779 - v778) >> 31));
      v777[v865] = v882;
      int * v781 = v748->cache_age;
      int v782 = v781[v866];
      int v884 = v782 + ((int)((unsigned int)(v782 - v778) >> 31));
      v781[v866] = v884;
      int * v784 = v748->cache_age;
      v784[v881] = 0;
      v830 = v881;
    } else {
      int * v787 = v748->cache_age;
      int v888 = 4 + ((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 3) * 2);
      int v788 = v787[v888];
      int * v789 = v748->cache_tags;
      int v790 = v789[v888];
      int v791 = v787[v866];
      int v792 = v789[v866];
      int * v793 = v748->cache_dirty;
      int v891 = (4 + ((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 3) * 2)) + ((((v788 + ((~(((v790 ^ -1) | (-(v790 ^ -1))) >> 31)) & 2)) - (v791 + ((~(((v792 ^ -1) | (-(v792 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v794 = v793[v891];
      bool v892 = !(v794 == 0);
      if (v892) {
        int * v795 = v748->cache_tags;
        int v796 = v795[v891];
        int * v797 = v748->cache_vals;
        int v895 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 3) * 2)) + ((((v788 + ((~(((v790 ^ -1) | (-(v790 ^ -1))) >> 31)) & 2)) - (v791 + ((~(((v792 ^ -1) | (-(v792 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v798 = v797[v895];
        int v896 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 3) * 2)) + ((((v788 + ((~(((v790 ^ -1) | (-(v790 ^ -1))) >> 31)) & 2)) - (v791 + ((~(((v792 ^ -1) | (-(v792 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v799 = v797[v896];
        int * v800 = v748->mem;
        int v898 = v796 * 2;
        v800[v898] = v798;
        int * v802 = v748->mem;
        int v901 = (v796 * 2) + 1;
        v802[v901] = v799;
        ;
      } else {
        ;
      }
      int * v807 = v748->mem;
      int v906 = ((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) * 2;
      int v808 = v807[v906];
      int v907 = (((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) * 2) + 1;
      int v809 = v807[v907];
      int * v810 = v748->cache_vals;
      int v909 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 3) * 2)) + ((((v788 + ((~(((v790 ^ -1) | (-(v790 ^ -1))) >> 31)) & 2)) - (v791 + ((~(((v792 ^ -1) | (-(v792 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v810[v909] = v808;
      int * v812 = v748->cache_vals;
      int v912 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 3) * 2)) + ((((v788 + ((~(((v790 ^ -1) | (-(v790 ^ -1))) >> 31)) & 2)) - (v791 + ((~(((v792 ^ -1) | (-(v792 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v812[v912] = v809;
      int * v814 = v748->cache_tags;
      int v915 = (int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1);
      v814[v891] = v915;
      int * v816 = v748->cache_dirty;
      v816[v891] = 0;
      int * v818 = v748->cache_age;
      v818[v891] = 1;
      int * v820 = v748->cache_age;
      int v821 = v820[v891];
      int v822 = v820[v865];
      int v921 = v822 + ((int)((unsigned int)(v822 - v821) >> 31));
      v820[v865] = v921;
      int * v824 = v748->cache_age;
      int v825 = v824[v866];
      int v923 = v825 + ((int)((unsigned int)(v825 - v821) >> 31));
      v824[v866] = v923;
      int * v827 = v748->cache_age;
      v827[v891] = 0;
      v830 = v891;
    }
    int * v831 = v748->cache_vals;
    int v926 = v830 * 2;
    int v832 = v831[v926];
    int v927 = (v830 * 2) + 1;
    int v833 = v831[v927];
    int v928 = (((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 1) * 2) + ((((v772 + ((~(((v774 ^ -1) | (-(v774 ^ -1))) >> 31)) & 2)) - (v775 + ((~(((v776 ^ -1) | (-(v776 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v831[v928] = v832;
    int * v835 = v748->cache_vals;
    int v931 = ((((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 1) * 2) + ((((v772 + ((~(((v774 ^ -1) | (-(v774 ^ -1))) >> 31)) & 2)) - (v775 + ((~(((v776 ^ -1) | (-(v776 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v835[v931] = v833;
    int * v837 = v748->cache_tags;
    int v934 = ((((int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1)) & 1) * 2) + ((((v772 + ((~(((v774 ^ -1) | (-(v774 ^ -1))) >> 31)) & 2)) - (v775 + ((~(((v776 ^ -1) | (-(v776 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v935 = (int)((unsigned int)((int)((unsigned int)v752 >> 2)) >> 1);
    v837[v934] = v935;
    int * v839 = v748->cache_dirty;
    v839[v934] = 0;
    int * v841 = v748->cache_age;
    v841[v934] = 1;
    int * v843 = v748->cache_age;
    int v844 = v843[v934];
    int v845 = v843[v863];
    int v941 = v845 + ((int)((unsigned int)(v845 - v844) >> 31));
    v843[v863] = v941;
    int * v847 = v748->cache_age;
    int v848 = v847[v864];
    int v943 = v848 + ((int)((unsigned int)(v848 - v844) >> 31));
    v847[v864] = v943;
    int * v850 = v748->cache_age;
    v850[v934] = 0;
    v853 = v934;
  }
  int v946 = (v853 * 2) + (((int)((unsigned int)v752 >> 2)) & 1);
  int v854 = v760[v946];
  int * v855 = v748->regs;
  v855[14] = v854;
  struct StateT * v857 = slot_22(v748);
  return v857;
}

struct StateT * slot_3(struct StateT * v38) {
  int * v39 = v38->saved_regs;
  int * v40 = v38->regs;
  int v41 = v40[12];
  v39[12] = v41;
  int v43 = v38->timer;
  int v53 = v43 + 1;
  v38->timer = v53;
  int * v45 = v38->regs;
  v45[12] = 0;
  struct StateT * v47 = slot_4(v38);
  return v47;
}

struct StateT * slot_10(struct StateT * v580) {
  int v581 = v580->timer;
  int v584 = v581 + 1;
  v580->timer = v584;
  return v580;
}

struct StateT * slot_1(struct StateT * v17) {
  int v18 = v17->timer;
  int v24 = v18 + 1;
  v17->timer = v24;
  int * v20 = v17->regs;
  v20[10] = 1;
  struct StateT * v22 = slot_2(v17);
  return v22;
}

struct StateT * slot_13(struct StateT * v593) {
  int * v594 = v593->saved_regs;
  int * v595 = v593->regs;
  int v596 = v595[11];
  v594[11] = v596;
  int v598 = v593->timer;
  int v609 = v598 + 1;
  v593->timer = v609;
  int * v600 = v593->regs;
  int v601 = v600[11];
  int v611 = v601 + -1;
  v600[11] = v611;
  struct StateT * v603 = slot_14(v593);
  return v603;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v10 = v3 + 1;
  v2->timer = v10;
  int * v5 = v2->regs;
  int v6 = v5[10];
  v5[11] = v6;
  struct StateT * v8 = slot_1(v2);
  return v8;
}

struct StateT * slot_14(struct StateT * v614) {
  int * v615 = v614->saved_regs;
  int * v616 = v614->regs;
  int v617 = v616[12];
  v615[12] = v617;
  int v619 = v614->timer;
  int v630 = v619 + 1;
  v614->timer = v630;
  int * v621 = v614->regs;
  int v622 = v621[12];
  int v632 = v622 + 4;
  v621[12] = v632;
  struct StateT * v624 = slot_15(v614);
  return v624;
}

struct StateT * slot_17(struct StateT * v702) {
  int v703 = v702->timer;
  int v709 = v703 + 1;
  v702->timer = v709;
  int * v705 = v702->regs;
  v705[10] = 0;
  struct StateT * v707 = slot_10(v702);
  return v707;
}

struct StateT * slot_20(struct StateT * v728) {
  int * v729 = v728->regs;
  int v730 = v729[11];
  bool v741 = !(v730 == 0);
  struct StateT * v737;
  if (v741) {
    int v731 = v728->timer;
    int v742 = v731 + 15;
    v728->timer = v742;
    struct StateT * v733 = slot_21(v728);
    v737 = v733;
  } else {
    struct StateT * v735 = slot_10(v728);
    v737 = v735;
  }
  return v737;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_8(struct StateT * v317) {
  int * v318 = v317->saved_regs;
  int * v319 = v317->regs;
  int v320 = v319[15];
  v318[15] = v320;
  int v322 = v317->timer;
  int v436 = v322 + 1;
  v317->timer = v436;
  int * v324 = v317->regs;
  int v325 = v324[13];
  int * v326 = v317->cache_tags;
  int v440 = (((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 1) * 2;
  int v327 = v326[v440];
  int v441 = ((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 1) * 2) + 1;
  int v328 = v326[v441];
  int v442 = 4 + ((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 3) * 2);
  int v329 = v326[v442];
  int v443 = (4 + ((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v330 = v326[v443];
  int v331 = v317->timer;
  int v444 = v331 + ((100 ^ (((~(((v329 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))) | (-(v329 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))))) >> 31)) | (~(((v330 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))) | (-(v330 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v327 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))) | (-(v327 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))))) >> 31)) | (~(((v328 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))) | (-(v328 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v329 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))) | (-(v329 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))))) >> 31)) | (~(((v330 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))) | (-(v330 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))))) >> 31))) & 104)))));
  v317->timer = v444;
  int * v333 = v317->cache_vals;
  bool v445 = !(((~(((v327 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))) | (-(v327 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))))) >> 31)) | (~(((v328 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))) | (-(v328 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))))) >> 31))) == 0);
  int v426;
  if (v445) {
    int * v334 = v317->cache_age;
    int v447 = ((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 1) * 2) + ((~(((v328 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))) | (-(v328 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))))) >> 31)) & 1);
    int v335 = v334[v447];
    int v336 = v334[v440];
    int v448 = v336 + ((int)((unsigned int)(v336 - v335) >> 31));
    v334[v440] = v448;
    int * v338 = v317->cache_age;
    int v339 = v338[v441];
    int v450 = v339 + ((int)((unsigned int)(v339 - v335) >> 31));
    v338[v441] = v450;
    int * v341 = v317->cache_age;
    v341[v447] = 0;
    v426 = v447;
  } else {
    int * v344 = v317->cache_age;
    int v454 = (((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 1) * 2;
    int v345 = v344[v454];
    int * v346 = v317->cache_tags;
    int v347 = v346[v454];
    int v348 = v344[v441];
    int v349 = v346[v441];
    bool v456 = !(((~(((v329 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))) | (-(v329 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))))) >> 31)) | (~(((v330 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))) | (-(v330 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))))) >> 31))) == 0);
    int v403;
    if (v456) {
      int * v350 = v317->cache_age;
      int v458 = (4 + ((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 3) * 2)) + ((~(((v330 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))) | (-(v330 ^ ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1))))) >> 31)) & 1);
      int v351 = v350[v458];
      int v352 = v350[v442];
      int v459 = v352 + ((int)((unsigned int)(v352 - v351) >> 31));
      v350[v442] = v459;
      int * v354 = v317->cache_age;
      int v355 = v354[v443];
      int v461 = v355 + ((int)((unsigned int)(v355 - v351) >> 31));
      v354[v443] = v461;
      int * v357 = v317->cache_age;
      v357[v458] = 0;
      v403 = v458;
    } else {
      int * v360 = v317->cache_age;
      int v465 = 4 + ((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 3) * 2);
      int v361 = v360[v465];
      int * v362 = v317->cache_tags;
      int v363 = v362[v465];
      int v364 = v360[v443];
      int v365 = v362[v443];
      int * v366 = v317->cache_dirty;
      int v468 = (4 + ((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 3) * 2)) + ((((v361 + ((~(((v363 ^ -1) | (-(v363 ^ -1))) >> 31)) & 2)) - (v364 + ((~(((v365 ^ -1) | (-(v365 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v367 = v366[v468];
      bool v469 = !(v367 == 0);
      if (v469) {
        int * v368 = v317->cache_tags;
        int v369 = v368[v468];
        int * v370 = v317->cache_vals;
        int v472 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 3) * 2)) + ((((v361 + ((~(((v363 ^ -1) | (-(v363 ^ -1))) >> 31)) & 2)) - (v364 + ((~(((v365 ^ -1) | (-(v365 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v371 = v370[v472];
        int v473 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 3) * 2)) + ((((v361 + ((~(((v363 ^ -1) | (-(v363 ^ -1))) >> 31)) & 2)) - (v364 + ((~(((v365 ^ -1) | (-(v365 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v372 = v370[v473];
        int * v373 = v317->mem;
        int v475 = v369 * 2;
        v373[v475] = v371;
        int * v375 = v317->mem;
        int v478 = (v369 * 2) + 1;
        v375[v478] = v372;
        ;
      } else {
        ;
      }
      int * v380 = v317->mem;
      int v483 = ((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) * 2;
      int v381 = v380[v483];
      int v484 = (((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) * 2) + 1;
      int v382 = v380[v484];
      int * v383 = v317->cache_vals;
      int v486 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 3) * 2)) + ((((v361 + ((~(((v363 ^ -1) | (-(v363 ^ -1))) >> 31)) & 2)) - (v364 + ((~(((v365 ^ -1) | (-(v365 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v383[v486] = v381;
      int * v385 = v317->cache_vals;
      int v489 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 3) * 2)) + ((((v361 + ((~(((v363 ^ -1) | (-(v363 ^ -1))) >> 31)) & 2)) - (v364 + ((~(((v365 ^ -1) | (-(v365 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v385[v489] = v382;
      int * v387 = v317->cache_tags;
      int v492 = (int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1);
      v387[v468] = v492;
      int * v389 = v317->cache_dirty;
      v389[v468] = 0;
      int * v391 = v317->cache_age;
      v391[v468] = 1;
      int * v393 = v317->cache_age;
      int v394 = v393[v468];
      int v395 = v393[v442];
      int v498 = v395 + ((int)((unsigned int)(v395 - v394) >> 31));
      v393[v442] = v498;
      int * v397 = v317->cache_age;
      int v398 = v397[v443];
      int v500 = v398 + ((int)((unsigned int)(v398 - v394) >> 31));
      v397[v443] = v500;
      int * v400 = v317->cache_age;
      v400[v468] = 0;
      v403 = v468;
    }
    int * v404 = v317->cache_vals;
    int v503 = v403 * 2;
    int v405 = v404[v503];
    int v504 = (v403 * 2) + 1;
    int v406 = v404[v504];
    int v505 = (((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 1) * 2) + ((((v345 + ((~(((v347 ^ -1) | (-(v347 ^ -1))) >> 31)) & 2)) - (v348 + ((~(((v349 ^ -1) | (-(v349 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v404[v505] = v405;
    int * v408 = v317->cache_vals;
    int v508 = ((((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 1) * 2) + ((((v345 + ((~(((v347 ^ -1) | (-(v347 ^ -1))) >> 31)) & 2)) - (v348 + ((~(((v349 ^ -1) | (-(v349 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v408[v508] = v406;
    int * v410 = v317->cache_tags;
    int v511 = ((((int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1)) & 1) * 2) + ((((v345 + ((~(((v347 ^ -1) | (-(v347 ^ -1))) >> 31)) & 2)) - (v348 + ((~(((v349 ^ -1) | (-(v349 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v512 = (int)((unsigned int)((int)((unsigned int)v325 >> 2)) >> 1);
    v410[v511] = v512;
    int * v412 = v317->cache_dirty;
    v412[v511] = 0;
    int * v414 = v317->cache_age;
    v414[v511] = 1;
    int * v416 = v317->cache_age;
    int v417 = v416[v511];
    int v418 = v416[v440];
    int v518 = v418 + ((int)((unsigned int)(v418 - v417) >> 31));
    v416[v440] = v518;
    int * v420 = v317->cache_age;
    int v421 = v420[v441];
    int v520 = v421 + ((int)((unsigned int)(v421 - v417) >> 31));
    v420[v441] = v520;
    int * v423 = v317->cache_age;
    v423[v511] = 0;
    v426 = v511;
  }
  int v523 = (v426 * 2) + (((int)((unsigned int)v325 >> 2)) & 1);
  int v427 = v333[v523];
  int * v428 = v317->regs;
  v428[15] = v427;
  struct StateT * v430 = slot_9(v317);
  return v430;
}

struct StateT * slot_4(struct StateT * v58) {
  int v59 = v58->timer;
  int v66 = v59 + 1;
  v58->timer = v66;
  int * v61 = v58->regs;
  int v62 = v61[12];
  int v69 = v62 + 16;
  v61[12] = v69;
  struct StateT * v64 = slot_5(v58);
  return v64;
}

struct StateT * slot_15(struct StateT * v635) {
  int * v636 = v635->saved_regs;
  int * v637 = v635->regs;
  int v638 = v637[13];
  v636[13] = v638;
  int v640 = v635->timer;
  int v651 = v640 + 1;
  v635->timer = v651;
  int * v642 = v635->regs;
  int v643 = v642[13];
  int v653 = v643 + 4;
  v642[13] = v653;
  struct StateT * v645 = slot_16(v635);
  return v645;
}

struct StateT * slot_18(struct StateT * v715) {
  int v716 = v715->timer;
  int v720 = v716 + 1;
  v715->timer = v720;
  struct StateT * v718 = slot_20(v715);
  return v718;
}

struct StateT * slot_9(struct StateT * v528) {
  int * v529 = v528->regs;
  int v530 = v529[11];
  bool v557 = 0 >= v530;
  struct StateT * v553;
  if (v557) {
    int v531 = v528->timer;
    int v558 = v531 + 15;
    v528->timer = v558;
    int * v533 = v528->saved_regs;
    int v534 = v533[12];
    int * v535 = v528->regs;
    v535[12] = v534;
    int * v537 = v528->saved_regs;
    int v538 = v537[13];
    int * v539 = v528->regs;
    v539[13] = v538;
    int * v541 = v528->saved_regs;
    int v542 = v541[14];
    int * v543 = v528->regs;
    v543[14] = v542;
    int * v545 = v528->saved_regs;
    int v546 = v545[15];
    int * v547 = v528->regs;
    v547[15] = v546;
    struct StateT * v549 = slot_10(v528);
    v553 = v549;
  } else {
    struct StateT * v551 = slot_11(v528);
    v553 = v551;
  }
  return v553;
}

struct StateT * slot_22(struct StateT * v952) {
  int v953 = v952->timer;
  int v1063 = v953 + 1;
  v952->timer = v1063;
  int * v955 = v952->regs;
  int v956 = v955[13];
  int * v957 = v952->cache_tags;
  int v1067 = (((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 1) * 2;
  int v958 = v957[v1067];
  int v1068 = ((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 1) * 2) + 1;
  int v959 = v957[v1068];
  int v1069 = 4 + ((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 3) * 2);
  int v960 = v957[v1069];
  int v1070 = (4 + ((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v961 = v957[v1070];
  int v962 = v952->timer;
  int v1071 = v962 + ((100 ^ (((~(((v960 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))) | (-(v960 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))))) >> 31)) | (~(((v961 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))) | (-(v961 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v958 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))) | (-(v958 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))))) >> 31)) | (~(((v959 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))) | (-(v959 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v960 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))) | (-(v960 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))))) >> 31)) | (~(((v961 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))) | (-(v961 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))))) >> 31))) & 104)))));
  v952->timer = v1071;
  int * v964 = v952->cache_vals;
  bool v1072 = !(((~(((v958 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))) | (-(v958 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))))) >> 31)) | (~(((v959 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))) | (-(v959 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))))) >> 31))) == 0);
  int v1057;
  if (v1072) {
    int * v965 = v952->cache_age;
    int v1074 = ((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 1) * 2) + ((~(((v959 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))) | (-(v959 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))))) >> 31)) & 1);
    int v966 = v965[v1074];
    int v967 = v965[v1067];
    int v1075 = v967 + ((int)((unsigned int)(v967 - v966) >> 31));
    v965[v1067] = v1075;
    int * v969 = v952->cache_age;
    int v970 = v969[v1068];
    int v1077 = v970 + ((int)((unsigned int)(v970 - v966) >> 31));
    v969[v1068] = v1077;
    int * v972 = v952->cache_age;
    v972[v1074] = 0;
    v1057 = v1074;
  } else {
    int * v975 = v952->cache_age;
    int v1081 = (((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 1) * 2;
    int v976 = v975[v1081];
    int * v977 = v952->cache_tags;
    int v978 = v977[v1081];
    int v979 = v975[v1068];
    int v980 = v977[v1068];
    bool v1083 = !(((~(((v960 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))) | (-(v960 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))))) >> 31)) | (~(((v961 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))) | (-(v961 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))))) >> 31))) == 0);
    int v1034;
    if (v1083) {
      int * v981 = v952->cache_age;
      int v1085 = (4 + ((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 3) * 2)) + ((~(((v961 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))) | (-(v961 ^ ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1))))) >> 31)) & 1);
      int v982 = v981[v1085];
      int v983 = v981[v1069];
      int v1086 = v983 + ((int)((unsigned int)(v983 - v982) >> 31));
      v981[v1069] = v1086;
      int * v985 = v952->cache_age;
      int v986 = v985[v1070];
      int v1088 = v986 + ((int)((unsigned int)(v986 - v982) >> 31));
      v985[v1070] = v1088;
      int * v988 = v952->cache_age;
      v988[v1085] = 0;
      v1034 = v1085;
    } else {
      int * v991 = v952->cache_age;
      int v1092 = 4 + ((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 3) * 2);
      int v992 = v991[v1092];
      int * v993 = v952->cache_tags;
      int v994 = v993[v1092];
      int v995 = v991[v1070];
      int v996 = v993[v1070];
      int * v997 = v952->cache_dirty;
      int v1095 = (4 + ((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 3) * 2)) + ((((v992 + ((~(((v994 ^ -1) | (-(v994 ^ -1))) >> 31)) & 2)) - (v995 + ((~(((v996 ^ -1) | (-(v996 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v998 = v997[v1095];
      bool v1096 = !(v998 == 0);
      if (v1096) {
        int * v999 = v952->cache_tags;
        int v1000 = v999[v1095];
        int * v1001 = v952->cache_vals;
        int v1099 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 3) * 2)) + ((((v992 + ((~(((v994 ^ -1) | (-(v994 ^ -1))) >> 31)) & 2)) - (v995 + ((~(((v996 ^ -1) | (-(v996 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1002 = v1001[v1099];
        int v1100 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 3) * 2)) + ((((v992 + ((~(((v994 ^ -1) | (-(v994 ^ -1))) >> 31)) & 2)) - (v995 + ((~(((v996 ^ -1) | (-(v996 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1003 = v1001[v1100];
        int * v1004 = v952->mem;
        int v1102 = v1000 * 2;
        v1004[v1102] = v1002;
        int * v1006 = v952->mem;
        int v1105 = (v1000 * 2) + 1;
        v1006[v1105] = v1003;
        ;
      } else {
        ;
      }
      int * v1011 = v952->mem;
      int v1110 = ((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) * 2;
      int v1012 = v1011[v1110];
      int v1111 = (((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) * 2) + 1;
      int v1013 = v1011[v1111];
      int * v1014 = v952->cache_vals;
      int v1113 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 3) * 2)) + ((((v992 + ((~(((v994 ^ -1) | (-(v994 ^ -1))) >> 31)) & 2)) - (v995 + ((~(((v996 ^ -1) | (-(v996 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1014[v1113] = v1012;
      int * v1016 = v952->cache_vals;
      int v1116 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 3) * 2)) + ((((v992 + ((~(((v994 ^ -1) | (-(v994 ^ -1))) >> 31)) & 2)) - (v995 + ((~(((v996 ^ -1) | (-(v996 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1016[v1116] = v1013;
      int * v1018 = v952->cache_tags;
      int v1119 = (int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1);
      v1018[v1095] = v1119;
      int * v1020 = v952->cache_dirty;
      v1020[v1095] = 0;
      int * v1022 = v952->cache_age;
      v1022[v1095] = 1;
      int * v1024 = v952->cache_age;
      int v1025 = v1024[v1095];
      int v1026 = v1024[v1069];
      int v1125 = v1026 + ((int)((unsigned int)(v1026 - v1025) >> 31));
      v1024[v1069] = v1125;
      int * v1028 = v952->cache_age;
      int v1029 = v1028[v1070];
      int v1127 = v1029 + ((int)((unsigned int)(v1029 - v1025) >> 31));
      v1028[v1070] = v1127;
      int * v1031 = v952->cache_age;
      v1031[v1095] = 0;
      v1034 = v1095;
    }
    int * v1035 = v952->cache_vals;
    int v1130 = v1034 * 2;
    int v1036 = v1035[v1130];
    int v1131 = (v1034 * 2) + 1;
    int v1037 = v1035[v1131];
    int v1132 = (((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 1) * 2) + ((((v976 + ((~(((v978 ^ -1) | (-(v978 ^ -1))) >> 31)) & 2)) - (v979 + ((~(((v980 ^ -1) | (-(v980 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1035[v1132] = v1036;
    int * v1039 = v952->cache_vals;
    int v1135 = ((((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 1) * 2) + ((((v976 + ((~(((v978 ^ -1) | (-(v978 ^ -1))) >> 31)) & 2)) - (v979 + ((~(((v980 ^ -1) | (-(v980 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1039[v1135] = v1037;
    int * v1041 = v952->cache_tags;
    int v1138 = ((((int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1)) & 1) * 2) + ((((v976 + ((~(((v978 ^ -1) | (-(v978 ^ -1))) >> 31)) & 2)) - (v979 + ((~(((v980 ^ -1) | (-(v980 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1139 = (int)((unsigned int)((int)((unsigned int)v956 >> 2)) >> 1);
    v1041[v1138] = v1139;
    int * v1043 = v952->cache_dirty;
    v1043[v1138] = 0;
    int * v1045 = v952->cache_age;
    v1045[v1138] = 1;
    int * v1047 = v952->cache_age;
    int v1048 = v1047[v1138];
    int v1049 = v1047[v1067];
    int v1145 = v1049 + ((int)((unsigned int)(v1049 - v1048) >> 31));
    v1047[v1067] = v1145;
    int * v1051 = v952->cache_age;
    int v1052 = v1051[v1068];
    int v1147 = v1052 + ((int)((unsigned int)(v1052 - v1048) >> 31));
    v1051[v1068] = v1147;
    int * v1054 = v952->cache_age;
    v1054[v1138] = 0;
    v1057 = v1138;
  }
  int v1150 = (v1057 * 2) + (((int)((unsigned int)v956 >> 2)) & 1);
  int v1058 = v964[v1150];
  int * v1059 = v952->regs;
  v1059[15] = v1058;
  struct StateT * v1061 = slot_11(v952);
  return v1061;
}

struct StateT * slot_11(struct StateT * v585) {
  int v586 = v585->timer;
  int v590 = v586 + 1;
  v585->timer = v590;
  struct StateT * v588 = slot_13(v585);
  return v588;
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
  
  int n = bounded(0, 4);
  s1.regs[10] = n;
  s2.regs[10] = n;
  // guess, the attacker's: the same draw in both states
  for (int i=0; i<4; i++) {
    int v = bounded(0, 20);
    s1.mem[4 + i] = v;
    s2.mem[4 + i] = v;
  }
  
  // secret, secret: a different draw in each state
  for (int i=0; i<4; i++) {
    s1.mem[0 + i] = secret(0, 20);
    s2.mem[0 + i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}