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

struct StateT * slot_12(struct StateT * v780);
struct StateT * slot_6(struct StateT * v101);
struct StateT * slot_16(struct StateT * v1088);
struct StateT * slot_23(struct StateT * v1747);
struct StateT * slot_5(struct StateT * v92);
struct StateT * slot_2(struct StateT * v38);
struct StateT * slot_7(struct StateT * v140);
struct StateT * slot_21(struct StateT * v1446);
struct StateT * slot_3(struct StateT * v56);
struct StateT * slot_10(struct StateT * v703);
struct StateT * slot_1(struct StateT * v20);
struct StateT * slot_19(struct StateT * v1145);
struct StateT * slot_13(struct StateT * v1036);
struct StateT * slot_24(struct StateT * v1785);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v1064);
struct StateT * slot_17(struct StateT * v1097);
struct StateT * slot_20(struct StateT * v1407);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v402);
struct StateT * slot_4(struct StateT * v74);
struct StateT * slot_18(struct StateT * v1106);
struct StateT * slot_9(struct StateT * v441);
struct StateT * slot_22(struct StateT * v1708);
struct StateT * slot_11(struct StateT * v742);
struct StateT * slot_12(struct StateT * v780) {
  int * v781 = v780->regs;
  int v782 = v781[14];
  int * v783 = v780->regs;
  int v784 = v783[15];
  bool v917 = v782 >= v784;
  struct StateT * v911;
  if (v917) {
    int v785 = v780->timer;
    int v918 = v785 + 15;
    v780->timer = v918;
    int * v787 = v780->saved_regs;
    int v788 = v787[6];
    int * v789 = v780->regs;
    v789[6] = v788;
    int * v791 = v780->saved_regs;
    int v792 = v791[7];
    int * v793 = v780->regs;
    v793[7] = v792;
    int * v795 = v780->saved_regs;
    int v796 = v795[8];
    int * v797 = v780->regs;
    v797[8] = v796;
    int * v799 = v780->saved_regs;
    int v800 = v799[9];
    int * v801 = v780->regs;
    v801[9] = v800;
    int * v803 = v780->saved_regs;
    int v804 = v803[16];
    int * v805 = v780->regs;
    v805[16] = v804;
    int * v807 = v780->saved_regs;
    int v808 = v807[5];
    int * v809 = v780->regs;
    v809[5] = v808;
    int * v811 = v780->reg_ready;
    int v812 = v780->timer;
    v811[0] = v812;
    int * v814 = v780->reg_ready;
    int v815 = v780->timer;
    v814[1] = v815;
    int * v817 = v780->reg_ready;
    int v818 = v780->timer;
    v817[2] = v818;
    int * v820 = v780->reg_ready;
    int v821 = v780->timer;
    v820[3] = v821;
    int * v823 = v780->reg_ready;
    int v824 = v780->timer;
    v823[4] = v824;
    int * v826 = v780->reg_ready;
    int v827 = v780->timer;
    v826[5] = v827;
    int * v829 = v780->reg_ready;
    int v830 = v780->timer;
    v829[6] = v830;
    int * v832 = v780->reg_ready;
    int v833 = v780->timer;
    v832[7] = v833;
    int * v835 = v780->reg_ready;
    int v836 = v780->timer;
    v835[8] = v836;
    int * v838 = v780->reg_ready;
    int v839 = v780->timer;
    v838[9] = v839;
    int * v841 = v780->reg_ready;
    int v842 = v780->timer;
    v841[10] = v842;
    int * v844 = v780->reg_ready;
    int v845 = v780->timer;
    v844[11] = v845;
    int * v847 = v780->reg_ready;
    int v848 = v780->timer;
    v847[12] = v848;
    int * v850 = v780->reg_ready;
    int v851 = v780->timer;
    v850[13] = v851;
    int * v853 = v780->reg_ready;
    int v854 = v780->timer;
    v853[14] = v854;
    int * v856 = v780->reg_ready;
    int v857 = v780->timer;
    v856[15] = v857;
    int * v859 = v780->reg_ready;
    int v860 = v780->timer;
    v859[16] = v860;
    int * v862 = v780->reg_ready;
    int v863 = v780->timer;
    v862[17] = v863;
    int * v865 = v780->reg_ready;
    int v866 = v780->timer;
    v865[18] = v866;
    int * v868 = v780->reg_ready;
    int v869 = v780->timer;
    v868[19] = v869;
    int * v871 = v780->reg_ready;
    int v872 = v780->timer;
    v871[20] = v872;
    int * v874 = v780->reg_ready;
    int v875 = v780->timer;
    v874[21] = v875;
    int * v877 = v780->reg_ready;
    int v878 = v780->timer;
    v877[22] = v878;
    int * v880 = v780->reg_ready;
    int v881 = v780->timer;
    v880[23] = v881;
    int * v883 = v780->reg_ready;
    int v884 = v780->timer;
    v883[24] = v884;
    int * v886 = v780->reg_ready;
    int v887 = v780->timer;
    v886[25] = v887;
    int * v889 = v780->reg_ready;
    int v890 = v780->timer;
    v889[26] = v890;
    int * v892 = v780->reg_ready;
    int v893 = v780->timer;
    v892[27] = v893;
    int * v895 = v780->reg_ready;
    int v896 = v780->timer;
    v895[28] = v896;
    int * v898 = v780->reg_ready;
    int v899 = v780->timer;
    v898[29] = v899;
    int * v901 = v780->reg_ready;
    int v902 = v780->timer;
    v901[30] = v902;
    int * v904 = v780->reg_ready;
    int v905 = v780->timer;
    v904[31] = v905;
    struct StateT * v907 = slot_13(v780);
    v911 = v907;
  } else {
    struct StateT * v909 = slot_14(v780);
    v911 = v909;
  }
  return v911;
}

struct StateT * slot_6(struct StateT * v101) {
  int * v102 = v101->saved_regs;
  int * v103 = v101->regs;
  int v104 = v103[6];
  v102[6] = v104;
  int v106 = v101->timer;
  int v107 = v101->timer;
  int v127 = v107 + 1;
  v101->timer = v127;
  int * v109 = v101->reg_ready;
  int v110 = v109[12];
  int * v111 = v101->regs;
  int v112 = v111[12];
  int * v113 = v101->reg_ready;
  int v114 = v113[14];
  int * v115 = v101->regs;
  int v116 = v115[14];
  int * v117 = v101->reg_ready;
  int v135 = (v114 + (((v110 + ((v106 - v110) & (~((v106 - v110) >> 31)))) - v114) & (~(((v110 + ((v106 - v110) & (~((v106 - v110) >> 31)))) - v114) >> 31)))) + 1;
  v117[6] = v135;
  int * v119 = v101->regs;
  int v137 = v112 + v116;
  v119[6] = v137;
  struct StateT * v121 = slot_7(v101);
  return v121;
}

struct StateT * slot_16(struct StateT * v1088) {
  int v1089 = v1088->timer;
  int v1090 = v1088->timer;
  int v1094 = v1090 + 1;
  v1088->timer = v1094;
  struct StateT * v1092 = slot_17(v1088);
  return v1092;
}

struct StateT * slot_23(struct StateT * v1747) {
  int * v1748 = v1747->saved_regs;
  int * v1749 = v1747->regs;
  int v1750 = v1749[5];
  v1748[5] = v1750;
  int v1752 = v1747->timer;
  int v1753 = v1747->timer;
  int v1773 = v1753 + 1;
  v1747->timer = v1773;
  int * v1755 = v1747->reg_ready;
  int v1756 = v1755[5];
  int * v1757 = v1747->regs;
  int v1758 = v1757[5];
  int * v1759 = v1747->reg_ready;
  int v1760 = v1759[16];
  int * v1761 = v1747->regs;
  int v1762 = v1761[16];
  int * v1763 = v1747->reg_ready;
  int v1780 = (v1760 + (((v1756 + ((v1752 - v1756) & (~((v1752 - v1756) >> 31)))) - v1760) & (~(((v1756 + ((v1752 - v1756) & (~((v1752 - v1756) >> 31)))) - v1760) >> 31)))) + 1;
  v1763[5] = v1780;
  int * v1765 = v1747->regs;
  int v1782 = v1758 | v1762;
  v1765[5] = v1782;
  struct StateT * v1767 = slot_24(v1747);
  return v1767;
}

struct StateT * slot_5(struct StateT * v92) {
  int v93 = v92->timer;
  int v94 = v92->timer;
  int v98 = v94 + 1;
  v92->timer = v98;
  struct StateT * v96 = slot_6(v92);
  return v96;
}

struct StateT * slot_2(struct StateT * v38) {
  int v39 = v38->timer;
  int v40 = v38->timer;
  int v48 = v40 + 1;
  v38->timer = v48;
  int * v42 = v38->reg_ready;
  int v51 = v39 + 1;
  v42[14] = v51;
  int * v44 = v38->regs;
  v44[14] = 0;
  struct StateT * v46 = slot_3(v38);
  return v46;
}

struct StateT * slot_7(struct StateT * v140) {
  int * v141 = v140->saved_regs;
  int * v142 = v140->regs;
  int v143 = v142[7];
  v141[7] = v143;
  int v145 = v140->timer;
  int v146 = v140->timer;
  int v285 = v146 + 1;
  v140->timer = v285;
  int * v148 = v140->reg_ready;
  int v149 = v148[6];
  int * v150 = v140->regs;
  int v151 = v150[6];
  int * v152 = v140->cache_tags;
  int v290 = (((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 1) * 2;
  int v153 = v152[v290];
  int * v154 = v140->cache_tags;
  int v292 = ((((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 1) * 2) + 1;
  int v155 = v154[v292];
  int * v156 = v140->cache_tags;
  int v294 = 4 + ((((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 3) * 2);
  int v157 = v156[v294];
  int * v158 = v140->cache_tags;
  int v296 = (4 + ((((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v159 = v158[v296];
  int * v160 = v140->cache_vals;
  bool v297 = !(((~(((v153 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))) | (-(v153 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))))) >> 31)) | (~(((v155 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))) | (-(v155 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))))) >> 31))) == 0);
  int v273;
  if (v297) {
    int * v161 = v140->cache_age;
    int v299 = ((((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 1) * 2) + ((~(((v155 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))) | (-(v155 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))))) >> 31)) & 1);
    int v162 = v161[v299];
    int * v163 = v140->cache_age;
    int v164 = v163[v290];
    int * v165 = v140->cache_age;
    int v302 = v164 + ((int)((unsigned int)(v164 - v162) >> 31));
    v165[v290] = v302;
    int * v167 = v140->cache_age;
    int v168 = v167[v292];
    int * v169 = v140->cache_age;
    int v305 = v168 + ((int)((unsigned int)(v168 - v162) >> 31));
    v169[v292] = v305;
    int * v171 = v140->cache_age;
    v171[v299] = 0;
    v273 = v299;
  } else {
    int * v174 = v140->cache_age;
    int v309 = (((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 1) * 2;
    int v175 = v174[v309];
    int * v176 = v140->cache_tags;
    int v177 = v176[v309];
    int * v178 = v140->cache_age;
    int v179 = v178[v292];
    int * v180 = v140->cache_tags;
    int v181 = v180[v292];
    bool v313 = !(((~(((v157 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))) | (-(v157 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))))) >> 31)) | (~(((v159 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))) | (-(v159 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))))) >> 31))) == 0);
    int v245;
    if (v313) {
      int * v182 = v140->cache_age;
      int v315 = (4 + ((((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 3) * 2)) + ((~(((v159 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))) | (-(v159 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))))) >> 31)) & 1);
      int v183 = v182[v315];
      int * v184 = v140->cache_age;
      int v185 = v184[v294];
      int * v186 = v140->cache_age;
      int v318 = v185 + ((int)((unsigned int)(v185 - v183) >> 31));
      v186[v294] = v318;
      int * v188 = v140->cache_age;
      int v189 = v188[v296];
      int * v190 = v140->cache_age;
      int v321 = v189 + ((int)((unsigned int)(v189 - v183) >> 31));
      v190[v296] = v321;
      int * v192 = v140->cache_age;
      v192[v315] = 0;
      v245 = v315;
    } else {
      int * v195 = v140->cache_age;
      int v325 = 4 + ((((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 3) * 2);
      int v196 = v195[v325];
      int * v197 = v140->cache_tags;
      int v198 = v197[v325];
      int * v199 = v140->cache_age;
      int v200 = v199[v296];
      int * v201 = v140->cache_tags;
      int v202 = v201[v296];
      int * v203 = v140->cache_dirty;
      int v330 = (4 + ((((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 3) * 2)) + ((((v196 + ((~(((v198 ^ -1) | (-(v198 ^ -1))) >> 31)) & 2)) - (v200 + ((~(((v202 ^ -1) | (-(v202 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v204 = v203[v330];
      bool v331 = !(v204 == 0);
      if (v331) {
        int * v205 = v140->cache_tags;
        int v206 = v205[v330];
        int * v207 = v140->cache_vals;
        int v334 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 3) * 2)) + ((((v196 + ((~(((v198 ^ -1) | (-(v198 ^ -1))) >> 31)) & 2)) - (v200 + ((~(((v202 ^ -1) | (-(v202 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v208 = v207[v334];
        int * v209 = v140->cache_vals;
        int v336 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 3) * 2)) + ((((v196 + ((~(((v198 ^ -1) | (-(v198 ^ -1))) >> 31)) & 2)) - (v200 + ((~(((v202 ^ -1) | (-(v202 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v210 = v209[v336];
        int * v211 = v140->mem;
        int v338 = v206 * 2;
        v211[v338] = v208;
        int * v213 = v140->mem;
        int v341 = (v206 * 2) + 1;
        v213[v341] = v210;
        ;
      } else {
        ;
      }
      int * v218 = v140->mem;
      int v346 = ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) * 2;
      int v219 = v218[v346];
      int * v220 = v140->mem;
      int v348 = (((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) * 2) + 1;
      int v221 = v220[v348];
      int * v222 = v140->cache_vals;
      int v350 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 3) * 2)) + ((((v196 + ((~(((v198 ^ -1) | (-(v198 ^ -1))) >> 31)) & 2)) - (v200 + ((~(((v202 ^ -1) | (-(v202 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v222[v350] = v219;
      int * v224 = v140->cache_vals;
      int v353 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 3) * 2)) + ((((v196 + ((~(((v198 ^ -1) | (-(v198 ^ -1))) >> 31)) & 2)) - (v200 + ((~(((v202 ^ -1) | (-(v202 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v224[v353] = v221;
      int * v226 = v140->cache_tags;
      int v356 = (int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1);
      v226[v330] = v356;
      int * v228 = v140->cache_dirty;
      v228[v330] = 0;
      int * v230 = v140->cache_age;
      v230[v330] = 1;
      int * v232 = v140->cache_age;
      int v233 = v232[v330];
      int * v234 = v140->cache_age;
      int v235 = v234[v294];
      int * v236 = v140->cache_age;
      int v364 = v235 + ((int)((unsigned int)(v235 - v233) >> 31));
      v236[v294] = v364;
      int * v238 = v140->cache_age;
      int v239 = v238[v296];
      int * v240 = v140->cache_age;
      int v367 = v239 + ((int)((unsigned int)(v239 - v233) >> 31));
      v240[v296] = v367;
      int * v242 = v140->cache_age;
      v242[v330] = 0;
      v245 = v330;
    }
    int * v246 = v140->cache_vals;
    int v370 = v245 * 2;
    int v247 = v246[v370];
    int * v248 = v140->cache_vals;
    int v372 = (v245 * 2) + 1;
    int v249 = v248[v372];
    int * v250 = v140->cache_vals;
    int v374 = (((((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 1) * 2) + ((((v175 + ((~(((v177 ^ -1) | (-(v177 ^ -1))) >> 31)) & 2)) - (v179 + ((~(((v181 ^ -1) | (-(v181 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v250[v374] = v247;
    int * v252 = v140->cache_vals;
    int v377 = ((((((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 1) * 2) + ((((v175 + ((~(((v177 ^ -1) | (-(v177 ^ -1))) >> 31)) & 2)) - (v179 + ((~(((v181 ^ -1) | (-(v181 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v252[v377] = v249;
    int * v254 = v140->cache_tags;
    int v380 = ((((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1)) & 1) * 2) + ((((v175 + ((~(((v177 ^ -1) | (-(v177 ^ -1))) >> 31)) & 2)) - (v179 + ((~(((v181 ^ -1) | (-(v181 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v381 = (int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1);
    v254[v380] = v381;
    int * v256 = v140->cache_dirty;
    v256[v380] = 0;
    int * v258 = v140->cache_age;
    v258[v380] = 1;
    int * v260 = v140->cache_age;
    int v261 = v260[v380];
    int * v262 = v140->cache_age;
    int v263 = v262[v290];
    int * v264 = v140->cache_age;
    int v389 = v263 + ((int)((unsigned int)(v263 - v261) >> 31));
    v264[v290] = v389;
    int * v266 = v140->cache_age;
    int v267 = v266[v292];
    int * v268 = v140->cache_age;
    int v392 = v267 + ((int)((unsigned int)(v267 - v261) >> 31));
    v268[v292] = v392;
    int * v270 = v140->cache_age;
    v270[v380] = 0;
    v273 = v380;
  }
  int v395 = (v273 * 2) + (((int)((unsigned int)v151 >> 2)) & 1);
  int v274 = v160[v395];
  int * v275 = v140->reg_ready;
  int v397 = ((v149 + ((v145 - v149) & (~((v145 - v149) >> 31)))) + 1) + ((100 ^ (((~(((v157 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))) | (-(v157 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))))) >> 31)) | (~(((v159 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))) | (-(v159 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v153 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))) | (-(v153 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))))) >> 31)) | (~(((v155 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))) | (-(v155 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v157 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))) | (-(v157 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))))) >> 31)) | (~(((v159 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))) | (-(v159 ^ ((int)((unsigned int)((int)((unsigned int)v151 >> 2)) >> 1))))) >> 31))) & 104)))));
  v275[7] = v397;
  int * v277 = v140->regs;
  v277[7] = v274;
  struct StateT * v279 = slot_8(v140);
  return v279;
}

struct StateT * slot_21(struct StateT * v1446) {
  int * v1447 = v1446->saved_regs;
  int * v1448 = v1446->regs;
  int v1449 = v1448[9];
  v1447[9] = v1449;
  int v1451 = v1446->timer;
  int v1452 = v1446->timer;
  int v1591 = v1452 + 1;
  v1446->timer = v1591;
  int * v1454 = v1446->reg_ready;
  int v1455 = v1454[8];
  int * v1456 = v1446->regs;
  int v1457 = v1456[8];
  int * v1458 = v1446->cache_tags;
  int v1596 = (((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1)) & 1) * 2;
  int v1459 = v1458[v1596];
  int * v1460 = v1446->cache_tags;
  int v1598 = ((((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1461 = v1460[v1598];
  int * v1462 = v1446->cache_tags;
  int v1600 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1)) & 3) * 2);
  int v1463 = v1462[v1600];
  int * v1464 = v1446->cache_tags;
  int v1602 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1465 = v1464[v1602];
  int * v1466 = v1446->cache_vals;
  bool v1603 = !(((~(((v1459 ^ ((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1))) | (-(v1459 ^ ((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1))))) >> 31)) | (~(((v1461 ^ ((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1))) | (-(v1461 ^ ((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1))))) >> 31))) == 0);
  int v1579;
  if (v1603) {
    int * v1467 = v1446->cache_age;
    int v1605 = ((((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1)) & 1) * 2) + ((~(((v1461 ^ ((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1))) | (-(v1461 ^ ((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1))))) >> 31)) & 1);
    int v1468 = v1467[v1605];
    int * v1469 = v1446->cache_age;
    int v1470 = v1469[v1596];
    int * v1471 = v1446->cache_age;
    int v1608 = v1470 + ((int)((unsigned int)(v1470 - v1468) >> 31));
    v1471[v1596] = v1608;
    int * v1473 = v1446->cache_age;
    int v1474 = v1473[v1598];
    int * v1475 = v1446->cache_age;
    int v1611 = v1474 + ((int)((unsigned int)(v1474 - v1468) >> 31));
    v1475[v1598] = v1611;
    int * v1477 = v1446->cache_age;
    v1477[v1605] = 0;
    v1579 = v1605;
  } else {
    int * v1480 = v1446->cache_age;
    int v1615 = (((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1)) & 1) * 2;
    int v1481 = v1480[v1615];
    int * v1482 = v1446->cache_tags;
    int v1483 = v1482[v1615];
    int * v1484 = v1446->cache_age;
    int v1485 = v1484[v1598];
    int * v1486 = v1446->cache_tags;
    int v1487 = v1486[v1598];
    bool v1619 = !(((~(((v1463 ^ ((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1))) | (-(v1463 ^ ((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1))))) >> 31)) | (~(((v1465 ^ ((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1))) | (-(v1465 ^ ((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1))))) >> 31))) == 0);
    int v1551;
    if (v1619) {
      int * v1488 = v1446->cache_age;
      int v1621 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1465 ^ ((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1))) | (-(v1465 ^ ((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1))))) >> 31)) & 1);
      int v1489 = v1488[v1621];
      int * v1490 = v1446->cache_age;
      int v1491 = v1490[v1600];
      int * v1492 = v1446->cache_age;
      int v1624 = v1491 + ((int)((unsigned int)(v1491 - v1489) >> 31));
      v1492[v1600] = v1624;
      int * v1494 = v1446->cache_age;
      int v1495 = v1494[v1602];
      int * v1496 = v1446->cache_age;
      int v1627 = v1495 + ((int)((unsigned int)(v1495 - v1489) >> 31));
      v1496[v1602] = v1627;
      int * v1498 = v1446->cache_age;
      v1498[v1621] = 0;
      v1551 = v1621;
    } else {
      int * v1501 = v1446->cache_age;
      int v1631 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1)) & 3) * 2);
      int v1502 = v1501[v1631];
      int * v1503 = v1446->cache_tags;
      int v1504 = v1503[v1631];
      int * v1505 = v1446->cache_age;
      int v1506 = v1505[v1602];
      int * v1507 = v1446->cache_tags;
      int v1508 = v1507[v1602];
      int * v1509 = v1446->cache_dirty;
      int v1636 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1)) & 3) * 2)) + ((((v1502 + ((~(((v1504 ^ -1) | (-(v1504 ^ -1))) >> 31)) & 2)) - (v1506 + ((~(((v1508 ^ -1) | (-(v1508 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1510 = v1509[v1636];
      bool v1637 = !(v1510 == 0);
      if (v1637) {
        int * v1511 = v1446->cache_tags;
        int v1512 = v1511[v1636];
        int * v1513 = v1446->cache_vals;
        int v1640 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1)) & 3) * 2)) + ((((v1502 + ((~(((v1504 ^ -1) | (-(v1504 ^ -1))) >> 31)) & 2)) - (v1506 + ((~(((v1508 ^ -1) | (-(v1508 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1514 = v1513[v1640];
        int * v1515 = v1446->cache_vals;
        int v1642 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1)) & 3) * 2)) + ((((v1502 + ((~(((v1504 ^ -1) | (-(v1504 ^ -1))) >> 31)) & 2)) - (v1506 + ((~(((v1508 ^ -1) | (-(v1508 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1516 = v1515[v1642];
        int * v1517 = v1446->mem;
        int v1644 = v1512 * 2;
        v1517[v1644] = v1514;
        int * v1519 = v1446->mem;
        int v1647 = (v1512 * 2) + 1;
        v1519[v1647] = v1516;
        ;
      } else {
        ;
      }
      int * v1524 = v1446->mem;
      int v1652 = ((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1)) * 2;
      int v1525 = v1524[v1652];
      int * v1526 = v1446->mem;
      int v1654 = (((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1)) * 2) + 1;
      int v1527 = v1526[v1654];
      int * v1528 = v1446->cache_vals;
      int v1656 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1)) & 3) * 2)) + ((((v1502 + ((~(((v1504 ^ -1) | (-(v1504 ^ -1))) >> 31)) & 2)) - (v1506 + ((~(((v1508 ^ -1) | (-(v1508 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1528[v1656] = v1525;
      int * v1530 = v1446->cache_vals;
      int v1659 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1)) & 3) * 2)) + ((((v1502 + ((~(((v1504 ^ -1) | (-(v1504 ^ -1))) >> 31)) & 2)) - (v1506 + ((~(((v1508 ^ -1) | (-(v1508 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1530[v1659] = v1527;
      int * v1532 = v1446->cache_tags;
      int v1662 = (int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1);
      v1532[v1636] = v1662;
      int * v1534 = v1446->cache_dirty;
      v1534[v1636] = 0;
      int * v1536 = v1446->cache_age;
      v1536[v1636] = 1;
      int * v1538 = v1446->cache_age;
      int v1539 = v1538[v1636];
      int * v1540 = v1446->cache_age;
      int v1541 = v1540[v1600];
      int * v1542 = v1446->cache_age;
      int v1670 = v1541 + ((int)((unsigned int)(v1541 - v1539) >> 31));
      v1542[v1600] = v1670;
      int * v1544 = v1446->cache_age;
      int v1545 = v1544[v1602];
      int * v1546 = v1446->cache_age;
      int v1673 = v1545 + ((int)((unsigned int)(v1545 - v1539) >> 31));
      v1546[v1602] = v1673;
      int * v1548 = v1446->cache_age;
      v1548[v1636] = 0;
      v1551 = v1636;
    }
    int * v1552 = v1446->cache_vals;
    int v1676 = v1551 * 2;
    int v1553 = v1552[v1676];
    int * v1554 = v1446->cache_vals;
    int v1678 = (v1551 * 2) + 1;
    int v1555 = v1554[v1678];
    int * v1556 = v1446->cache_vals;
    int v1680 = (((((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1)) & 1) * 2) + ((((v1481 + ((~(((v1483 ^ -1) | (-(v1483 ^ -1))) >> 31)) & 2)) - (v1485 + ((~(((v1487 ^ -1) | (-(v1487 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1556[v1680] = v1553;
    int * v1558 = v1446->cache_vals;
    int v1683 = ((((((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1)) & 1) * 2) + ((((v1481 + ((~(((v1483 ^ -1) | (-(v1483 ^ -1))) >> 31)) & 2)) - (v1485 + ((~(((v1487 ^ -1) | (-(v1487 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1558[v1683] = v1555;
    int * v1560 = v1446->cache_tags;
    int v1686 = ((((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1)) & 1) * 2) + ((((v1481 + ((~(((v1483 ^ -1) | (-(v1483 ^ -1))) >> 31)) & 2)) - (v1485 + ((~(((v1487 ^ -1) | (-(v1487 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1687 = (int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1);
    v1560[v1686] = v1687;
    int * v1562 = v1446->cache_dirty;
    v1562[v1686] = 0;
    int * v1564 = v1446->cache_age;
    v1564[v1686] = 1;
    int * v1566 = v1446->cache_age;
    int v1567 = v1566[v1686];
    int * v1568 = v1446->cache_age;
    int v1569 = v1568[v1596];
    int * v1570 = v1446->cache_age;
    int v1695 = v1569 + ((int)((unsigned int)(v1569 - v1567) >> 31));
    v1570[v1596] = v1695;
    int * v1572 = v1446->cache_age;
    int v1573 = v1572[v1598];
    int * v1574 = v1446->cache_age;
    int v1698 = v1573 + ((int)((unsigned int)(v1573 - v1567) >> 31));
    v1574[v1598] = v1698;
    int * v1576 = v1446->cache_age;
    v1576[v1686] = 0;
    v1579 = v1686;
  }
  int v1701 = (v1579 * 2) + (((int)((unsigned int)v1457 >> 2)) & 1);
  int v1580 = v1466[v1701];
  int * v1581 = v1446->reg_ready;
  int v1703 = ((v1455 + ((v1451 - v1455) & (~((v1451 - v1455) >> 31)))) + 1) + ((100 ^ (((~(((v1463 ^ ((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1))) | (-(v1463 ^ ((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1))))) >> 31)) | (~(((v1465 ^ ((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1))) | (-(v1465 ^ ((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1459 ^ ((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1))) | (-(v1459 ^ ((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1))))) >> 31)) | (~(((v1461 ^ ((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1))) | (-(v1461 ^ ((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1463 ^ ((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1))) | (-(v1463 ^ ((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1))))) >> 31)) | (~(((v1465 ^ ((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1))) | (-(v1465 ^ ((int)((unsigned int)((int)((unsigned int)v1457 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1581[9] = v1703;
  int * v1583 = v1446->regs;
  v1583[9] = v1580;
  struct StateT * v1585 = slot_22(v1446);
  return v1585;
}

struct StateT * slot_3(struct StateT * v56) {
  int v57 = v56->timer;
  int v58 = v56->timer;
  int v66 = v58 + 1;
  v56->timer = v66;
  int * v60 = v56->reg_ready;
  int v69 = v57 + 1;
  v60[15] = v69;
  int * v62 = v56->regs;
  v62[15] = 16;
  struct StateT * v64 = slot_4(v56);
  return v64;
}

struct StateT * slot_10(struct StateT * v703) {
  int * v704 = v703->saved_regs;
  int * v705 = v703->regs;
  int v706 = v705[16];
  v704[16] = v706;
  int v708 = v703->timer;
  int v709 = v703->timer;
  int v729 = v709 + 1;
  v703->timer = v729;
  int * v711 = v703->reg_ready;
  int v712 = v711[7];
  int * v713 = v703->regs;
  int v714 = v713[7];
  int * v715 = v703->reg_ready;
  int v716 = v715[9];
  int * v717 = v703->regs;
  int v718 = v717[9];
  int * v719 = v703->reg_ready;
  int v737 = (v716 + (((v712 + ((v708 - v712) & (~((v708 - v712) >> 31)))) - v716) & (~(((v712 + ((v708 - v712) & (~((v708 - v712) >> 31)))) - v716) >> 31)))) + 1;
  v719[16] = v737;
  int * v721 = v703->regs;
  int v739 = v714 ^ v718;
  v721[16] = v739;
  struct StateT * v723 = slot_11(v703);
  return v723;
}

struct StateT * slot_1(struct StateT * v20) {
  int v21 = v20->timer;
  int v22 = v20->timer;
  int v30 = v22 + 1;
  v20->timer = v30;
  int * v24 = v20->reg_ready;
  int v33 = v21 + 1;
  v24[13] = v33;
  int * v26 = v20->regs;
  v26[13] = 80;
  struct StateT * v28 = slot_2(v20);
  return v28;
}

struct StateT * slot_19(struct StateT * v1145) {
  int * v1146 = v1145->saved_regs;
  int * v1147 = v1145->regs;
  int v1148 = v1147[7];
  v1146[7] = v1148;
  int v1150 = v1145->timer;
  int v1151 = v1145->timer;
  int v1290 = v1151 + 1;
  v1145->timer = v1290;
  int * v1153 = v1145->reg_ready;
  int v1154 = v1153[6];
  int * v1155 = v1145->regs;
  int v1156 = v1155[6];
  int * v1157 = v1145->cache_tags;
  int v1295 = (((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1)) & 1) * 2;
  int v1158 = v1157[v1295];
  int * v1159 = v1145->cache_tags;
  int v1297 = ((((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1160 = v1159[v1297];
  int * v1161 = v1145->cache_tags;
  int v1299 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1)) & 3) * 2);
  int v1162 = v1161[v1299];
  int * v1163 = v1145->cache_tags;
  int v1301 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1164 = v1163[v1301];
  int * v1165 = v1145->cache_vals;
  bool v1302 = !(((~(((v1158 ^ ((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1))) | (-(v1158 ^ ((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1))))) >> 31)) | (~(((v1160 ^ ((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1))) | (-(v1160 ^ ((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1))))) >> 31))) == 0);
  int v1278;
  if (v1302) {
    int * v1166 = v1145->cache_age;
    int v1304 = ((((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1)) & 1) * 2) + ((~(((v1160 ^ ((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1))) | (-(v1160 ^ ((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1))))) >> 31)) & 1);
    int v1167 = v1166[v1304];
    int * v1168 = v1145->cache_age;
    int v1169 = v1168[v1295];
    int * v1170 = v1145->cache_age;
    int v1307 = v1169 + ((int)((unsigned int)(v1169 - v1167) >> 31));
    v1170[v1295] = v1307;
    int * v1172 = v1145->cache_age;
    int v1173 = v1172[v1297];
    int * v1174 = v1145->cache_age;
    int v1310 = v1173 + ((int)((unsigned int)(v1173 - v1167) >> 31));
    v1174[v1297] = v1310;
    int * v1176 = v1145->cache_age;
    v1176[v1304] = 0;
    v1278 = v1304;
  } else {
    int * v1179 = v1145->cache_age;
    int v1314 = (((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1)) & 1) * 2;
    int v1180 = v1179[v1314];
    int * v1181 = v1145->cache_tags;
    int v1182 = v1181[v1314];
    int * v1183 = v1145->cache_age;
    int v1184 = v1183[v1297];
    int * v1185 = v1145->cache_tags;
    int v1186 = v1185[v1297];
    bool v1318 = !(((~(((v1162 ^ ((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1))) | (-(v1162 ^ ((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1))))) >> 31)) | (~(((v1164 ^ ((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1))) | (-(v1164 ^ ((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1))))) >> 31))) == 0);
    int v1250;
    if (v1318) {
      int * v1187 = v1145->cache_age;
      int v1320 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1164 ^ ((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1))) | (-(v1164 ^ ((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1))))) >> 31)) & 1);
      int v1188 = v1187[v1320];
      int * v1189 = v1145->cache_age;
      int v1190 = v1189[v1299];
      int * v1191 = v1145->cache_age;
      int v1323 = v1190 + ((int)((unsigned int)(v1190 - v1188) >> 31));
      v1191[v1299] = v1323;
      int * v1193 = v1145->cache_age;
      int v1194 = v1193[v1301];
      int * v1195 = v1145->cache_age;
      int v1326 = v1194 + ((int)((unsigned int)(v1194 - v1188) >> 31));
      v1195[v1301] = v1326;
      int * v1197 = v1145->cache_age;
      v1197[v1320] = 0;
      v1250 = v1320;
    } else {
      int * v1200 = v1145->cache_age;
      int v1330 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1)) & 3) * 2);
      int v1201 = v1200[v1330];
      int * v1202 = v1145->cache_tags;
      int v1203 = v1202[v1330];
      int * v1204 = v1145->cache_age;
      int v1205 = v1204[v1301];
      int * v1206 = v1145->cache_tags;
      int v1207 = v1206[v1301];
      int * v1208 = v1145->cache_dirty;
      int v1335 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1)) & 3) * 2)) + ((((v1201 + ((~(((v1203 ^ -1) | (-(v1203 ^ -1))) >> 31)) & 2)) - (v1205 + ((~(((v1207 ^ -1) | (-(v1207 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1209 = v1208[v1335];
      bool v1336 = !(v1209 == 0);
      if (v1336) {
        int * v1210 = v1145->cache_tags;
        int v1211 = v1210[v1335];
        int * v1212 = v1145->cache_vals;
        int v1339 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1)) & 3) * 2)) + ((((v1201 + ((~(((v1203 ^ -1) | (-(v1203 ^ -1))) >> 31)) & 2)) - (v1205 + ((~(((v1207 ^ -1) | (-(v1207 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1213 = v1212[v1339];
        int * v1214 = v1145->cache_vals;
        int v1341 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1)) & 3) * 2)) + ((((v1201 + ((~(((v1203 ^ -1) | (-(v1203 ^ -1))) >> 31)) & 2)) - (v1205 + ((~(((v1207 ^ -1) | (-(v1207 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1215 = v1214[v1341];
        int * v1216 = v1145->mem;
        int v1343 = v1211 * 2;
        v1216[v1343] = v1213;
        int * v1218 = v1145->mem;
        int v1346 = (v1211 * 2) + 1;
        v1218[v1346] = v1215;
        ;
      } else {
        ;
      }
      int * v1223 = v1145->mem;
      int v1351 = ((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1)) * 2;
      int v1224 = v1223[v1351];
      int * v1225 = v1145->mem;
      int v1353 = (((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1)) * 2) + 1;
      int v1226 = v1225[v1353];
      int * v1227 = v1145->cache_vals;
      int v1355 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1)) & 3) * 2)) + ((((v1201 + ((~(((v1203 ^ -1) | (-(v1203 ^ -1))) >> 31)) & 2)) - (v1205 + ((~(((v1207 ^ -1) | (-(v1207 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1227[v1355] = v1224;
      int * v1229 = v1145->cache_vals;
      int v1358 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1)) & 3) * 2)) + ((((v1201 + ((~(((v1203 ^ -1) | (-(v1203 ^ -1))) >> 31)) & 2)) - (v1205 + ((~(((v1207 ^ -1) | (-(v1207 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1229[v1358] = v1226;
      int * v1231 = v1145->cache_tags;
      int v1361 = (int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1);
      v1231[v1335] = v1361;
      int * v1233 = v1145->cache_dirty;
      v1233[v1335] = 0;
      int * v1235 = v1145->cache_age;
      v1235[v1335] = 1;
      int * v1237 = v1145->cache_age;
      int v1238 = v1237[v1335];
      int * v1239 = v1145->cache_age;
      int v1240 = v1239[v1299];
      int * v1241 = v1145->cache_age;
      int v1369 = v1240 + ((int)((unsigned int)(v1240 - v1238) >> 31));
      v1241[v1299] = v1369;
      int * v1243 = v1145->cache_age;
      int v1244 = v1243[v1301];
      int * v1245 = v1145->cache_age;
      int v1372 = v1244 + ((int)((unsigned int)(v1244 - v1238) >> 31));
      v1245[v1301] = v1372;
      int * v1247 = v1145->cache_age;
      v1247[v1335] = 0;
      v1250 = v1335;
    }
    int * v1251 = v1145->cache_vals;
    int v1375 = v1250 * 2;
    int v1252 = v1251[v1375];
    int * v1253 = v1145->cache_vals;
    int v1377 = (v1250 * 2) + 1;
    int v1254 = v1253[v1377];
    int * v1255 = v1145->cache_vals;
    int v1379 = (((((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1)) & 1) * 2) + ((((v1180 + ((~(((v1182 ^ -1) | (-(v1182 ^ -1))) >> 31)) & 2)) - (v1184 + ((~(((v1186 ^ -1) | (-(v1186 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1255[v1379] = v1252;
    int * v1257 = v1145->cache_vals;
    int v1382 = ((((((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1)) & 1) * 2) + ((((v1180 + ((~(((v1182 ^ -1) | (-(v1182 ^ -1))) >> 31)) & 2)) - (v1184 + ((~(((v1186 ^ -1) | (-(v1186 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1257[v1382] = v1254;
    int * v1259 = v1145->cache_tags;
    int v1385 = ((((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1)) & 1) * 2) + ((((v1180 + ((~(((v1182 ^ -1) | (-(v1182 ^ -1))) >> 31)) & 2)) - (v1184 + ((~(((v1186 ^ -1) | (-(v1186 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1386 = (int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1);
    v1259[v1385] = v1386;
    int * v1261 = v1145->cache_dirty;
    v1261[v1385] = 0;
    int * v1263 = v1145->cache_age;
    v1263[v1385] = 1;
    int * v1265 = v1145->cache_age;
    int v1266 = v1265[v1385];
    int * v1267 = v1145->cache_age;
    int v1268 = v1267[v1295];
    int * v1269 = v1145->cache_age;
    int v1394 = v1268 + ((int)((unsigned int)(v1268 - v1266) >> 31));
    v1269[v1295] = v1394;
    int * v1271 = v1145->cache_age;
    int v1272 = v1271[v1297];
    int * v1273 = v1145->cache_age;
    int v1397 = v1272 + ((int)((unsigned int)(v1272 - v1266) >> 31));
    v1273[v1297] = v1397;
    int * v1275 = v1145->cache_age;
    v1275[v1385] = 0;
    v1278 = v1385;
  }
  int v1400 = (v1278 * 2) + (((int)((unsigned int)v1156 >> 2)) & 1);
  int v1279 = v1165[v1400];
  int * v1280 = v1145->reg_ready;
  int v1402 = ((v1154 + ((v1150 - v1154) & (~((v1150 - v1154) >> 31)))) + 1) + ((100 ^ (((~(((v1162 ^ ((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1))) | (-(v1162 ^ ((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1))))) >> 31)) | (~(((v1164 ^ ((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1))) | (-(v1164 ^ ((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1158 ^ ((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1))) | (-(v1158 ^ ((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1))))) >> 31)) | (~(((v1160 ^ ((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1))) | (-(v1160 ^ ((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1162 ^ ((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1))) | (-(v1162 ^ ((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1))))) >> 31)) | (~(((v1164 ^ ((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1))) | (-(v1164 ^ ((int)((unsigned int)((int)((unsigned int)v1156 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1280[7] = v1402;
  int * v1282 = v1145->regs;
  v1282[7] = v1279;
  struct StateT * v1284 = slot_20(v1145);
  return v1284;
}

struct StateT * slot_13(struct StateT * v1036) {
  int v1037 = v1036->timer;
  int v1038 = v1036->timer;
  int v1052 = v1038 + 1;
  v1036->timer = v1052;
  int * v1040 = v1036->reg_ready;
  int v1041 = v1040[5];
  int * v1042 = v1036->regs;
  int v1043 = v1042[5];
  bool v1056 = (v1043 ^ -2147483648) < -2147483647;
  int v1046;
  if (v1056) {
    v1046 = 1;
  } else {
    v1046 = 0;
  }
  int * v1047 = v1036->reg_ready;
  int v1061 = (v1041 + ((v1037 - v1041) & (~((v1037 - v1041) >> 31)))) + 1;
  v1047[11] = v1061;
  int * v1049 = v1036->regs;
  v1049[11] = v1046;
  return v1036;
}

struct StateT * slot_24(struct StateT * v1785) {
  int * v1786 = v1785->regs;
  int v1787 = v1786[14];
  int * v1788 = v1785->regs;
  int v1789 = v1788[15];
  bool v1922 = v1787 >= v1789;
  struct StateT * v1916;
  if (v1922) {
    int v1790 = v1785->timer;
    int v1923 = v1790 + 15;
    v1785->timer = v1923;
    int * v1792 = v1785->saved_regs;
    int v1793 = v1792[6];
    int * v1794 = v1785->regs;
    v1794[6] = v1793;
    int * v1796 = v1785->saved_regs;
    int v1797 = v1796[7];
    int * v1798 = v1785->regs;
    v1798[7] = v1797;
    int * v1800 = v1785->saved_regs;
    int v1801 = v1800[8];
    int * v1802 = v1785->regs;
    v1802[8] = v1801;
    int * v1804 = v1785->saved_regs;
    int v1805 = v1804[9];
    int * v1806 = v1785->regs;
    v1806[9] = v1805;
    int * v1808 = v1785->saved_regs;
    int v1809 = v1808[16];
    int * v1810 = v1785->regs;
    v1810[16] = v1809;
    int * v1812 = v1785->saved_regs;
    int v1813 = v1812[5];
    int * v1814 = v1785->regs;
    v1814[5] = v1813;
    int * v1816 = v1785->reg_ready;
    int v1817 = v1785->timer;
    v1816[0] = v1817;
    int * v1819 = v1785->reg_ready;
    int v1820 = v1785->timer;
    v1819[1] = v1820;
    int * v1822 = v1785->reg_ready;
    int v1823 = v1785->timer;
    v1822[2] = v1823;
    int * v1825 = v1785->reg_ready;
    int v1826 = v1785->timer;
    v1825[3] = v1826;
    int * v1828 = v1785->reg_ready;
    int v1829 = v1785->timer;
    v1828[4] = v1829;
    int * v1831 = v1785->reg_ready;
    int v1832 = v1785->timer;
    v1831[5] = v1832;
    int * v1834 = v1785->reg_ready;
    int v1835 = v1785->timer;
    v1834[6] = v1835;
    int * v1837 = v1785->reg_ready;
    int v1838 = v1785->timer;
    v1837[7] = v1838;
    int * v1840 = v1785->reg_ready;
    int v1841 = v1785->timer;
    v1840[8] = v1841;
    int * v1843 = v1785->reg_ready;
    int v1844 = v1785->timer;
    v1843[9] = v1844;
    int * v1846 = v1785->reg_ready;
    int v1847 = v1785->timer;
    v1846[10] = v1847;
    int * v1849 = v1785->reg_ready;
    int v1850 = v1785->timer;
    v1849[11] = v1850;
    int * v1852 = v1785->reg_ready;
    int v1853 = v1785->timer;
    v1852[12] = v1853;
    int * v1855 = v1785->reg_ready;
    int v1856 = v1785->timer;
    v1855[13] = v1856;
    int * v1858 = v1785->reg_ready;
    int v1859 = v1785->timer;
    v1858[14] = v1859;
    int * v1861 = v1785->reg_ready;
    int v1862 = v1785->timer;
    v1861[15] = v1862;
    int * v1864 = v1785->reg_ready;
    int v1865 = v1785->timer;
    v1864[16] = v1865;
    int * v1867 = v1785->reg_ready;
    int v1868 = v1785->timer;
    v1867[17] = v1868;
    int * v1870 = v1785->reg_ready;
    int v1871 = v1785->timer;
    v1870[18] = v1871;
    int * v1873 = v1785->reg_ready;
    int v1874 = v1785->timer;
    v1873[19] = v1874;
    int * v1876 = v1785->reg_ready;
    int v1877 = v1785->timer;
    v1876[20] = v1877;
    int * v1879 = v1785->reg_ready;
    int v1880 = v1785->timer;
    v1879[21] = v1880;
    int * v1882 = v1785->reg_ready;
    int v1883 = v1785->timer;
    v1882[22] = v1883;
    int * v1885 = v1785->reg_ready;
    int v1886 = v1785->timer;
    v1885[23] = v1886;
    int * v1888 = v1785->reg_ready;
    int v1889 = v1785->timer;
    v1888[24] = v1889;
    int * v1891 = v1785->reg_ready;
    int v1892 = v1785->timer;
    v1891[25] = v1892;
    int * v1894 = v1785->reg_ready;
    int v1895 = v1785->timer;
    v1894[26] = v1895;
    int * v1897 = v1785->reg_ready;
    int v1898 = v1785->timer;
    v1897[27] = v1898;
    int * v1900 = v1785->reg_ready;
    int v1901 = v1785->timer;
    v1900[28] = v1901;
    int * v1903 = v1785->reg_ready;
    int v1904 = v1785->timer;
    v1903[29] = v1904;
    int * v1906 = v1785->reg_ready;
    int v1907 = v1785->timer;
    v1906[30] = v1907;
    int * v1909 = v1785->reg_ready;
    int v1910 = v1785->timer;
    v1909[31] = v1910;
    struct StateT * v1912 = slot_13(v1785);
    v1916 = v1912;
  } else {
    struct StateT * v1914 = slot_14(v1785);
    v1916 = v1914;
  }
  return v1916;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v4 = v2->timer;
  int v12 = v4 + 1;
  v2->timer = v12;
  int * v6 = v2->reg_ready;
  int v15 = v3 + 1;
  v6[12] = v15;
  int * v8 = v2->regs;
  v8[12] = 0;
  struct StateT * v10 = slot_1(v2);
  return v10;
}

struct StateT * slot_14(struct StateT * v1064) {
  int v1065 = v1064->timer;
  int v1066 = v1064->timer;
  int v1078 = v1066 + 1;
  v1064->timer = v1078;
  int * v1068 = v1064->reg_ready;
  int v1069 = v1068[14];
  int * v1070 = v1064->regs;
  int v1071 = v1070[14];
  int * v1072 = v1064->reg_ready;
  int v1083 = (v1069 + ((v1065 - v1069) & (~((v1065 - v1069) >> 31)))) + 1;
  v1072[14] = v1083;
  int * v1074 = v1064->regs;
  int v1085 = v1071 + 4;
  v1074[14] = v1085;
  struct StateT * v1076 = slot_16(v1064);
  return v1076;
}

struct StateT * slot_17(struct StateT * v1097) {
  int v1098 = v1097->timer;
  int v1099 = v1097->timer;
  int v1103 = v1099 + 1;
  v1097->timer = v1103;
  struct StateT * v1101 = slot_18(v1097);
  return v1101;
}

struct StateT * slot_20(struct StateT * v1407) {
  int * v1408 = v1407->saved_regs;
  int * v1409 = v1407->regs;
  int v1410 = v1409[8];
  v1408[8] = v1410;
  int v1412 = v1407->timer;
  int v1413 = v1407->timer;
  int v1433 = v1413 + 1;
  v1407->timer = v1433;
  int * v1415 = v1407->reg_ready;
  int v1416 = v1415[13];
  int * v1417 = v1407->regs;
  int v1418 = v1417[13];
  int * v1419 = v1407->reg_ready;
  int v1420 = v1419[14];
  int * v1421 = v1407->regs;
  int v1422 = v1421[14];
  int * v1423 = v1407->reg_ready;
  int v1441 = (v1420 + (((v1416 + ((v1412 - v1416) & (~((v1412 - v1416) >> 31)))) - v1420) & (~(((v1416 + ((v1412 - v1416) & (~((v1412 - v1416) >> 31)))) - v1420) >> 31)))) + 1;
  v1423[8] = v1441;
  int * v1425 = v1407->regs;
  int v1443 = v1418 + v1422;
  v1425[8] = v1443;
  struct StateT * v1427 = slot_21(v1407);
  return v1427;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v2041 = v1->timer;
  int * v2042 = v1->reg_ready;
  int v2043 = v2042[0];
  int v2174 = v2043 + ((v2041 - v2043) & (~((v2041 - v2043) >> 31)));
  v1->timer = v2174;
  int v2045 = v1->timer;
  int * v2046 = v1->reg_ready;
  int v2047 = v2046[1];
  int v2177 = v2047 + ((v2045 - v2047) & (~((v2045 - v2047) >> 31)));
  v1->timer = v2177;
  int v2049 = v1->timer;
  int * v2050 = v1->reg_ready;
  int v2051 = v2050[2];
  int v2180 = v2051 + ((v2049 - v2051) & (~((v2049 - v2051) >> 31)));
  v1->timer = v2180;
  int v2053 = v1->timer;
  int * v2054 = v1->reg_ready;
  int v2055 = v2054[3];
  int v2183 = v2055 + ((v2053 - v2055) & (~((v2053 - v2055) >> 31)));
  v1->timer = v2183;
  int v2057 = v1->timer;
  int * v2058 = v1->reg_ready;
  int v2059 = v2058[4];
  int v2186 = v2059 + ((v2057 - v2059) & (~((v2057 - v2059) >> 31)));
  v1->timer = v2186;
  int v2061 = v1->timer;
  int * v2062 = v1->reg_ready;
  int v2063 = v2062[5];
  int v2189 = v2063 + ((v2061 - v2063) & (~((v2061 - v2063) >> 31)));
  v1->timer = v2189;
  int v2065 = v1->timer;
  int * v2066 = v1->reg_ready;
  int v2067 = v2066[6];
  int v2192 = v2067 + ((v2065 - v2067) & (~((v2065 - v2067) >> 31)));
  v1->timer = v2192;
  int v2069 = v1->timer;
  int * v2070 = v1->reg_ready;
  int v2071 = v2070[7];
  int v2195 = v2071 + ((v2069 - v2071) & (~((v2069 - v2071) >> 31)));
  v1->timer = v2195;
  int v2073 = v1->timer;
  int * v2074 = v1->reg_ready;
  int v2075 = v2074[8];
  int v2198 = v2075 + ((v2073 - v2075) & (~((v2073 - v2075) >> 31)));
  v1->timer = v2198;
  int v2077 = v1->timer;
  int * v2078 = v1->reg_ready;
  int v2079 = v2078[9];
  int v2201 = v2079 + ((v2077 - v2079) & (~((v2077 - v2079) >> 31)));
  v1->timer = v2201;
  int v2081 = v1->timer;
  int * v2082 = v1->reg_ready;
  int v2083 = v2082[10];
  int v2204 = v2083 + ((v2081 - v2083) & (~((v2081 - v2083) >> 31)));
  v1->timer = v2204;
  int v2085 = v1->timer;
  int * v2086 = v1->reg_ready;
  int v2087 = v2086[11];
  int v2207 = v2087 + ((v2085 - v2087) & (~((v2085 - v2087) >> 31)));
  v1->timer = v2207;
  int v2089 = v1->timer;
  int * v2090 = v1->reg_ready;
  int v2091 = v2090[12];
  int v2210 = v2091 + ((v2089 - v2091) & (~((v2089 - v2091) >> 31)));
  v1->timer = v2210;
  int v2093 = v1->timer;
  int * v2094 = v1->reg_ready;
  int v2095 = v2094[13];
  int v2213 = v2095 + ((v2093 - v2095) & (~((v2093 - v2095) >> 31)));
  v1->timer = v2213;
  int v2097 = v1->timer;
  int * v2098 = v1->reg_ready;
  int v2099 = v2098[14];
  int v2216 = v2099 + ((v2097 - v2099) & (~((v2097 - v2099) >> 31)));
  v1->timer = v2216;
  int v2101 = v1->timer;
  int * v2102 = v1->reg_ready;
  int v2103 = v2102[15];
  int v2219 = v2103 + ((v2101 - v2103) & (~((v2101 - v2103) >> 31)));
  v1->timer = v2219;
  int v2105 = v1->timer;
  int * v2106 = v1->reg_ready;
  int v2107 = v2106[16];
  int v2222 = v2107 + ((v2105 - v2107) & (~((v2105 - v2107) >> 31)));
  v1->timer = v2222;
  int v2109 = v1->timer;
  int * v2110 = v1->reg_ready;
  int v2111 = v2110[17];
  int v2225 = v2111 + ((v2109 - v2111) & (~((v2109 - v2111) >> 31)));
  v1->timer = v2225;
  int v2113 = v1->timer;
  int * v2114 = v1->reg_ready;
  int v2115 = v2114[18];
  int v2228 = v2115 + ((v2113 - v2115) & (~((v2113 - v2115) >> 31)));
  v1->timer = v2228;
  int v2117 = v1->timer;
  int * v2118 = v1->reg_ready;
  int v2119 = v2118[19];
  int v2231 = v2119 + ((v2117 - v2119) & (~((v2117 - v2119) >> 31)));
  v1->timer = v2231;
  int v2121 = v1->timer;
  int * v2122 = v1->reg_ready;
  int v2123 = v2122[20];
  int v2234 = v2123 + ((v2121 - v2123) & (~((v2121 - v2123) >> 31)));
  v1->timer = v2234;
  int v2125 = v1->timer;
  int * v2126 = v1->reg_ready;
  int v2127 = v2126[21];
  int v2237 = v2127 + ((v2125 - v2127) & (~((v2125 - v2127) >> 31)));
  v1->timer = v2237;
  int v2129 = v1->timer;
  int * v2130 = v1->reg_ready;
  int v2131 = v2130[22];
  int v2240 = v2131 + ((v2129 - v2131) & (~((v2129 - v2131) >> 31)));
  v1->timer = v2240;
  int v2133 = v1->timer;
  int * v2134 = v1->reg_ready;
  int v2135 = v2134[23];
  int v2243 = v2135 + ((v2133 - v2135) & (~((v2133 - v2135) >> 31)));
  v1->timer = v2243;
  int v2137 = v1->timer;
  int * v2138 = v1->reg_ready;
  int v2139 = v2138[24];
  int v2246 = v2139 + ((v2137 - v2139) & (~((v2137 - v2139) >> 31)));
  v1->timer = v2246;
  int v2141 = v1->timer;
  int * v2142 = v1->reg_ready;
  int v2143 = v2142[25];
  int v2249 = v2143 + ((v2141 - v2143) & (~((v2141 - v2143) >> 31)));
  v1->timer = v2249;
  int v2145 = v1->timer;
  int * v2146 = v1->reg_ready;
  int v2147 = v2146[26];
  int v2252 = v2147 + ((v2145 - v2147) & (~((v2145 - v2147) >> 31)));
  v1->timer = v2252;
  int v2149 = v1->timer;
  int * v2150 = v1->reg_ready;
  int v2151 = v2150[27];
  int v2255 = v2151 + ((v2149 - v2151) & (~((v2149 - v2151) >> 31)));
  v1->timer = v2255;
  int v2153 = v1->timer;
  int * v2154 = v1->reg_ready;
  int v2155 = v2154[28];
  int v2258 = v2155 + ((v2153 - v2155) & (~((v2153 - v2155) >> 31)));
  v1->timer = v2258;
  int v2157 = v1->timer;
  int * v2158 = v1->reg_ready;
  int v2159 = v2158[29];
  int v2261 = v2159 + ((v2157 - v2159) & (~((v2157 - v2159) >> 31)));
  v1->timer = v2261;
  int v2161 = v1->timer;
  int * v2162 = v1->reg_ready;
  int v2163 = v2162[30];
  int v2264 = v2163 + ((v2161 - v2163) & (~((v2161 - v2163) >> 31)));
  v1->timer = v2264;
  int v2165 = v1->timer;
  int * v2166 = v1->reg_ready;
  int v2167 = v2166[31];
  int v2267 = v2167 + ((v2165 - v2167) & (~((v2165 - v2167) >> 31)));
  v1->timer = v2267;
  return v1;
}

struct StateT * slot_8(struct StateT * v402) {
  int * v403 = v402->saved_regs;
  int * v404 = v402->regs;
  int v405 = v404[8];
  v403[8] = v405;
  int v407 = v402->timer;
  int v408 = v402->timer;
  int v428 = v408 + 1;
  v402->timer = v428;
  int * v410 = v402->reg_ready;
  int v411 = v410[13];
  int * v412 = v402->regs;
  int v413 = v412[13];
  int * v414 = v402->reg_ready;
  int v415 = v414[14];
  int * v416 = v402->regs;
  int v417 = v416[14];
  int * v418 = v402->reg_ready;
  int v436 = (v415 + (((v411 + ((v407 - v411) & (~((v407 - v411) >> 31)))) - v415) & (~(((v411 + ((v407 - v411) & (~((v407 - v411) >> 31)))) - v415) >> 31)))) + 1;
  v418[8] = v436;
  int * v420 = v402->regs;
  int v438 = v413 + v417;
  v420[8] = v438;
  struct StateT * v422 = slot_9(v402);
  return v422;
}

struct StateT * slot_4(struct StateT * v74) {
  int v75 = v74->timer;
  int v76 = v74->timer;
  int v84 = v76 + 1;
  v74->timer = v84;
  int * v78 = v74->reg_ready;
  int v87 = v75 + 1;
  v78[5] = v87;
  int * v80 = v74->regs;
  v80[5] = 0;
  struct StateT * v82 = slot_5(v74);
  return v82;
}

struct StateT * slot_18(struct StateT * v1106) {
  int * v1107 = v1106->saved_regs;
  int * v1108 = v1106->regs;
  int v1109 = v1108[6];
  v1107[6] = v1109;
  int v1111 = v1106->timer;
  int v1112 = v1106->timer;
  int v1132 = v1112 + 1;
  v1106->timer = v1132;
  int * v1114 = v1106->reg_ready;
  int v1115 = v1114[12];
  int * v1116 = v1106->regs;
  int v1117 = v1116[12];
  int * v1118 = v1106->reg_ready;
  int v1119 = v1118[14];
  int * v1120 = v1106->regs;
  int v1121 = v1120[14];
  int * v1122 = v1106->reg_ready;
  int v1140 = (v1119 + (((v1115 + ((v1111 - v1115) & (~((v1111 - v1115) >> 31)))) - v1119) & (~(((v1115 + ((v1111 - v1115) & (~((v1111 - v1115) >> 31)))) - v1119) >> 31)))) + 1;
  v1122[6] = v1140;
  int * v1124 = v1106->regs;
  int v1142 = v1117 + v1121;
  v1124[6] = v1142;
  struct StateT * v1126 = slot_19(v1106);
  return v1126;
}

struct StateT * slot_9(struct StateT * v441) {
  int * v442 = v441->saved_regs;
  int * v443 = v441->regs;
  int v444 = v443[9];
  v442[9] = v444;
  int v446 = v441->timer;
  int v447 = v441->timer;
  int v586 = v447 + 1;
  v441->timer = v586;
  int * v449 = v441->reg_ready;
  int v450 = v449[8];
  int * v451 = v441->regs;
  int v452 = v451[8];
  int * v453 = v441->cache_tags;
  int v591 = (((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1)) & 1) * 2;
  int v454 = v453[v591];
  int * v455 = v441->cache_tags;
  int v593 = ((((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1)) & 1) * 2) + 1;
  int v456 = v455[v593];
  int * v457 = v441->cache_tags;
  int v595 = 4 + ((((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1)) & 3) * 2);
  int v458 = v457[v595];
  int * v459 = v441->cache_tags;
  int v597 = (4 + ((((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v460 = v459[v597];
  int * v461 = v441->cache_vals;
  bool v598 = !(((~(((v454 ^ ((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1))) | (-(v454 ^ ((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1))))) >> 31)) | (~(((v456 ^ ((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1))) | (-(v456 ^ ((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1))))) >> 31))) == 0);
  int v574;
  if (v598) {
    int * v462 = v441->cache_age;
    int v600 = ((((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1)) & 1) * 2) + ((~(((v456 ^ ((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1))) | (-(v456 ^ ((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1))))) >> 31)) & 1);
    int v463 = v462[v600];
    int * v464 = v441->cache_age;
    int v465 = v464[v591];
    int * v466 = v441->cache_age;
    int v603 = v465 + ((int)((unsigned int)(v465 - v463) >> 31));
    v466[v591] = v603;
    int * v468 = v441->cache_age;
    int v469 = v468[v593];
    int * v470 = v441->cache_age;
    int v606 = v469 + ((int)((unsigned int)(v469 - v463) >> 31));
    v470[v593] = v606;
    int * v472 = v441->cache_age;
    v472[v600] = 0;
    v574 = v600;
  } else {
    int * v475 = v441->cache_age;
    int v610 = (((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1)) & 1) * 2;
    int v476 = v475[v610];
    int * v477 = v441->cache_tags;
    int v478 = v477[v610];
    int * v479 = v441->cache_age;
    int v480 = v479[v593];
    int * v481 = v441->cache_tags;
    int v482 = v481[v593];
    bool v614 = !(((~(((v458 ^ ((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1))) | (-(v458 ^ ((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1))))) >> 31)) | (~(((v460 ^ ((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1))) | (-(v460 ^ ((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1))))) >> 31))) == 0);
    int v546;
    if (v614) {
      int * v483 = v441->cache_age;
      int v616 = (4 + ((((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1)) & 3) * 2)) + ((~(((v460 ^ ((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1))) | (-(v460 ^ ((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1))))) >> 31)) & 1);
      int v484 = v483[v616];
      int * v485 = v441->cache_age;
      int v486 = v485[v595];
      int * v487 = v441->cache_age;
      int v619 = v486 + ((int)((unsigned int)(v486 - v484) >> 31));
      v487[v595] = v619;
      int * v489 = v441->cache_age;
      int v490 = v489[v597];
      int * v491 = v441->cache_age;
      int v622 = v490 + ((int)((unsigned int)(v490 - v484) >> 31));
      v491[v597] = v622;
      int * v493 = v441->cache_age;
      v493[v616] = 0;
      v546 = v616;
    } else {
      int * v496 = v441->cache_age;
      int v626 = 4 + ((((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1)) & 3) * 2);
      int v497 = v496[v626];
      int * v498 = v441->cache_tags;
      int v499 = v498[v626];
      int * v500 = v441->cache_age;
      int v501 = v500[v597];
      int * v502 = v441->cache_tags;
      int v503 = v502[v597];
      int * v504 = v441->cache_dirty;
      int v631 = (4 + ((((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1)) & 3) * 2)) + ((((v497 + ((~(((v499 ^ -1) | (-(v499 ^ -1))) >> 31)) & 2)) - (v501 + ((~(((v503 ^ -1) | (-(v503 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v505 = v504[v631];
      bool v632 = !(v505 == 0);
      if (v632) {
        int * v506 = v441->cache_tags;
        int v507 = v506[v631];
        int * v508 = v441->cache_vals;
        int v635 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1)) & 3) * 2)) + ((((v497 + ((~(((v499 ^ -1) | (-(v499 ^ -1))) >> 31)) & 2)) - (v501 + ((~(((v503 ^ -1) | (-(v503 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v509 = v508[v635];
        int * v510 = v441->cache_vals;
        int v637 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1)) & 3) * 2)) + ((((v497 + ((~(((v499 ^ -1) | (-(v499 ^ -1))) >> 31)) & 2)) - (v501 + ((~(((v503 ^ -1) | (-(v503 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v511 = v510[v637];
        int * v512 = v441->mem;
        int v639 = v507 * 2;
        v512[v639] = v509;
        int * v514 = v441->mem;
        int v642 = (v507 * 2) + 1;
        v514[v642] = v511;
        ;
      } else {
        ;
      }
      int * v519 = v441->mem;
      int v647 = ((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1)) * 2;
      int v520 = v519[v647];
      int * v521 = v441->mem;
      int v649 = (((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1)) * 2) + 1;
      int v522 = v521[v649];
      int * v523 = v441->cache_vals;
      int v651 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1)) & 3) * 2)) + ((((v497 + ((~(((v499 ^ -1) | (-(v499 ^ -1))) >> 31)) & 2)) - (v501 + ((~(((v503 ^ -1) | (-(v503 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v523[v651] = v520;
      int * v525 = v441->cache_vals;
      int v654 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1)) & 3) * 2)) + ((((v497 + ((~(((v499 ^ -1) | (-(v499 ^ -1))) >> 31)) & 2)) - (v501 + ((~(((v503 ^ -1) | (-(v503 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v525[v654] = v522;
      int * v527 = v441->cache_tags;
      int v657 = (int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1);
      v527[v631] = v657;
      int * v529 = v441->cache_dirty;
      v529[v631] = 0;
      int * v531 = v441->cache_age;
      v531[v631] = 1;
      int * v533 = v441->cache_age;
      int v534 = v533[v631];
      int * v535 = v441->cache_age;
      int v536 = v535[v595];
      int * v537 = v441->cache_age;
      int v665 = v536 + ((int)((unsigned int)(v536 - v534) >> 31));
      v537[v595] = v665;
      int * v539 = v441->cache_age;
      int v540 = v539[v597];
      int * v541 = v441->cache_age;
      int v668 = v540 + ((int)((unsigned int)(v540 - v534) >> 31));
      v541[v597] = v668;
      int * v543 = v441->cache_age;
      v543[v631] = 0;
      v546 = v631;
    }
    int * v547 = v441->cache_vals;
    int v671 = v546 * 2;
    int v548 = v547[v671];
    int * v549 = v441->cache_vals;
    int v673 = (v546 * 2) + 1;
    int v550 = v549[v673];
    int * v551 = v441->cache_vals;
    int v675 = (((((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1)) & 1) * 2) + ((((v476 + ((~(((v478 ^ -1) | (-(v478 ^ -1))) >> 31)) & 2)) - (v480 + ((~(((v482 ^ -1) | (-(v482 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v551[v675] = v548;
    int * v553 = v441->cache_vals;
    int v678 = ((((((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1)) & 1) * 2) + ((((v476 + ((~(((v478 ^ -1) | (-(v478 ^ -1))) >> 31)) & 2)) - (v480 + ((~(((v482 ^ -1) | (-(v482 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v553[v678] = v550;
    int * v555 = v441->cache_tags;
    int v681 = ((((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1)) & 1) * 2) + ((((v476 + ((~(((v478 ^ -1) | (-(v478 ^ -1))) >> 31)) & 2)) - (v480 + ((~(((v482 ^ -1) | (-(v482 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v682 = (int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1);
    v555[v681] = v682;
    int * v557 = v441->cache_dirty;
    v557[v681] = 0;
    int * v559 = v441->cache_age;
    v559[v681] = 1;
    int * v561 = v441->cache_age;
    int v562 = v561[v681];
    int * v563 = v441->cache_age;
    int v564 = v563[v591];
    int * v565 = v441->cache_age;
    int v690 = v564 + ((int)((unsigned int)(v564 - v562) >> 31));
    v565[v591] = v690;
    int * v567 = v441->cache_age;
    int v568 = v567[v593];
    int * v569 = v441->cache_age;
    int v693 = v568 + ((int)((unsigned int)(v568 - v562) >> 31));
    v569[v593] = v693;
    int * v571 = v441->cache_age;
    v571[v681] = 0;
    v574 = v681;
  }
  int v696 = (v574 * 2) + (((int)((unsigned int)v452 >> 2)) & 1);
  int v575 = v461[v696];
  int * v576 = v441->reg_ready;
  int v698 = ((v450 + ((v446 - v450) & (~((v446 - v450) >> 31)))) + 1) + ((100 ^ (((~(((v458 ^ ((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1))) | (-(v458 ^ ((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1))))) >> 31)) | (~(((v460 ^ ((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1))) | (-(v460 ^ ((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v454 ^ ((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1))) | (-(v454 ^ ((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1))))) >> 31)) | (~(((v456 ^ ((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1))) | (-(v456 ^ ((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v458 ^ ((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1))) | (-(v458 ^ ((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1))))) >> 31)) | (~(((v460 ^ ((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1))) | (-(v460 ^ ((int)((unsigned int)((int)((unsigned int)v452 >> 2)) >> 1))))) >> 31))) & 104)))));
  v576[9] = v698;
  int * v578 = v441->regs;
  v578[9] = v575;
  struct StateT * v580 = slot_10(v441);
  return v580;
}

struct StateT * slot_22(struct StateT * v1708) {
  int * v1709 = v1708->saved_regs;
  int * v1710 = v1708->regs;
  int v1711 = v1710[16];
  v1709[16] = v1711;
  int v1713 = v1708->timer;
  int v1714 = v1708->timer;
  int v1734 = v1714 + 1;
  v1708->timer = v1734;
  int * v1716 = v1708->reg_ready;
  int v1717 = v1716[7];
  int * v1718 = v1708->regs;
  int v1719 = v1718[7];
  int * v1720 = v1708->reg_ready;
  int v1721 = v1720[9];
  int * v1722 = v1708->regs;
  int v1723 = v1722[9];
  int * v1724 = v1708->reg_ready;
  int v1742 = (v1721 + (((v1717 + ((v1713 - v1717) & (~((v1713 - v1717) >> 31)))) - v1721) & (~(((v1717 + ((v1713 - v1717) & (~((v1713 - v1717) >> 31)))) - v1721) >> 31)))) + 1;
  v1724[16] = v1742;
  int * v1726 = v1708->regs;
  int v1744 = v1719 ^ v1723;
  v1726[16] = v1744;
  struct StateT * v1728 = slot_23(v1708);
  return v1728;
}

struct StateT * slot_11(struct StateT * v742) {
  int * v743 = v742->saved_regs;
  int * v744 = v742->regs;
  int v745 = v744[5];
  v743[5] = v745;
  int v747 = v742->timer;
  int v748 = v742->timer;
  int v768 = v748 + 1;
  v742->timer = v768;
  int * v750 = v742->reg_ready;
  int v751 = v750[5];
  int * v752 = v742->regs;
  int v753 = v752[5];
  int * v754 = v742->reg_ready;
  int v755 = v754[16];
  int * v756 = v742->regs;
  int v757 = v756[16];
  int * v758 = v742->reg_ready;
  int v775 = (v755 + (((v751 + ((v747 - v751) & (~((v747 - v751) >> 31)))) - v755) & (~(((v751 + ((v747 - v751) & (~((v747 - v751) >> 31)))) - v755) >> 31)))) + 1;
  v758[5] = v775;
  int * v760 = v742->regs;
  int v777 = v753 | v757;
  v760[5] = v777;
  struct StateT * v762 = slot_12(v742);
  return v762;
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