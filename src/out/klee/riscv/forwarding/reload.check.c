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

struct StateT * slot_12(struct StateT * v756);
struct StateT * slot_6(struct StateT * v284);
struct StateT * slot_5(struct StateT * v73);
struct StateT * slot_2(struct StateT * v28);
struct StateT * slot_7(struct StateT * v298);
struct StateT * slot_3(struct StateT * v41);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v563);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v509);
struct StateT * slot_4(struct StateT * v49);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v756) {
  int v757 = v756->timer;
  int v864 = v757 + 1;
  v756->timer = v864;
  int * v759 = v756->cache_tags;
  int v760 = v759[0];
  int v761 = v759[1];
  int v762 = v759[4];
  int v763 = v759[5];
  int v764 = v756->timer;
  int v870 = v764 + ((100 ^ (((~((v762 | (-v762)) >> 31)) | (~((v763 | (-v763)) >> 31))) & 104)) ^ (((~((v760 | (-v760)) >> 31)) | (~((v761 | (-v761)) >> 31))) & (1 ^ (100 ^ (((~((v762 | (-v762)) >> 31)) | (~((v763 | (-v763)) >> 31))) & 104)))));
  v756->timer = v870;
  int * v766 = v756->cache_vals;
  bool v871 = !(((~((v760 | (-v760)) >> 31)) | (~((v761 | (-v761)) >> 31))) == 0);
  int v859;
  if (v871) {
    int * v767 = v756->cache_age;
    int v873 = (~((v761 | (-v761)) >> 31)) & 1;
    int v768 = v767[v873];
    int v769 = v767[0];
    int v874 = v769 + ((int)((unsigned int)(v769 - v768) >> 31));
    v767[0] = v874;
    int * v771 = v756->cache_age;
    int v772 = v771[1];
    int v876 = v772 + ((int)((unsigned int)(v772 - v768) >> 31));
    v771[1] = v876;
    int * v774 = v756->cache_age;
    v774[v873] = 0;
    v859 = v873;
  } else {
    int * v777 = v756->cache_age;
    int v778 = v777[0];
    int * v779 = v756->cache_tags;
    int v780 = v779[0];
    int v781 = v777[1];
    int v782 = v779[1];
    bool v880 = !(((~((v762 | (-v762)) >> 31)) | (~((v763 | (-v763)) >> 31))) == 0);
    int v836;
    if (v880) {
      int * v783 = v756->cache_age;
      int v882 = 4 + ((~((v763 | (-v763)) >> 31)) & 1);
      int v784 = v783[v882];
      int v785 = v783[4];
      int v883 = v785 + ((int)((unsigned int)(v785 - v784) >> 31));
      v783[4] = v883;
      int * v787 = v756->cache_age;
      int v788 = v787[5];
      int v885 = v788 + ((int)((unsigned int)(v788 - v784) >> 31));
      v787[5] = v885;
      int * v790 = v756->cache_age;
      v790[v882] = 0;
      v836 = v882;
    } else {
      int * v793 = v756->cache_age;
      int v794 = v793[4];
      int * v795 = v756->cache_tags;
      int v796 = v795[4];
      int v797 = v793[5];
      int v798 = v795[5];
      int * v799 = v756->cache_dirty;
      int v890 = 4 + ((((v794 + ((~(((v796 ^ -1) | (-(v796 ^ -1))) >> 31)) & 2)) - (v797 + ((~(((v798 ^ -1) | (-(v798 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v800 = v799[v890];
      bool v891 = !(v800 == 0);
      if (v891) {
        int * v801 = v756->cache_tags;
        int v802 = v801[v890];
        int * v803 = v756->cache_vals;
        int v894 = (4 + ((((v794 + ((~(((v796 ^ -1) | (-(v796 ^ -1))) >> 31)) & 2)) - (v797 + ((~(((v798 ^ -1) | (-(v798 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v804 = v803[v894];
        int v895 = ((4 + ((((v794 + ((~(((v796 ^ -1) | (-(v796 ^ -1))) >> 31)) & 2)) - (v797 + ((~(((v798 ^ -1) | (-(v798 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v805 = v803[v895];
        int * v806 = v756->mem;
        int v897 = v802 * 2;
        v806[v897] = v804;
        int * v808 = v756->mem;
        int v900 = (v802 * 2) + 1;
        v808[v900] = v805;
        ;
      } else {
        ;
      }
      int * v813 = v756->mem;
      int v814 = v813[0];
      int v815 = v813[1];
      int * v816 = v756->cache_vals;
      int v906 = (4 + ((((v794 + ((~(((v796 ^ -1) | (-(v796 ^ -1))) >> 31)) & 2)) - (v797 + ((~(((v798 ^ -1) | (-(v798 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v816[v906] = v814;
      int * v818 = v756->cache_vals;
      int v909 = ((4 + ((((v794 + ((~(((v796 ^ -1) | (-(v796 ^ -1))) >> 31)) & 2)) - (v797 + ((~(((v798 ^ -1) | (-(v798 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v818[v909] = v815;
      int * v820 = v756->cache_tags;
      v820[v890] = 0;
      int * v822 = v756->cache_dirty;
      v822[v890] = 0;
      int * v824 = v756->cache_age;
      v824[v890] = 1;
      int * v826 = v756->cache_age;
      int v827 = v826[v890];
      int v828 = v826[4];
      int v915 = v828 + ((int)((unsigned int)(v828 - v827) >> 31));
      v826[4] = v915;
      int * v830 = v756->cache_age;
      int v831 = v830[5];
      int v917 = v831 + ((int)((unsigned int)(v831 - v827) >> 31));
      v830[5] = v917;
      int * v833 = v756->cache_age;
      v833[v890] = 0;
      v836 = v890;
    }
    int * v837 = v756->cache_vals;
    int v920 = v836 * 2;
    int v838 = v837[v920];
    int v921 = (v836 * 2) + 1;
    int v839 = v837[v921];
    int v922 = ((((v778 + ((~(((v780 ^ -1) | (-(v780 ^ -1))) >> 31)) & 2)) - (v781 + ((~(((v782 ^ -1) | (-(v782 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v837[v922] = v838;
    int * v841 = v756->cache_vals;
    int v925 = (((((v778 + ((~(((v780 ^ -1) | (-(v780 ^ -1))) >> 31)) & 2)) - (v781 + ((~(((v782 ^ -1) | (-(v782 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v841[v925] = v839;
    int * v843 = v756->cache_tags;
    int v928 = (((v778 + ((~(((v780 ^ -1) | (-(v780 ^ -1))) >> 31)) & 2)) - (v781 + ((~(((v782 ^ -1) | (-(v782 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v843[v928] = 0;
    int * v845 = v756->cache_dirty;
    v845[v928] = 0;
    int * v847 = v756->cache_age;
    v847[v928] = 1;
    int * v849 = v756->cache_age;
    int v850 = v849[v928];
    int v851 = v849[0];
    int v932 = v851 + ((int)((unsigned int)(v851 - v850) >> 31));
    v849[0] = v932;
    int * v853 = v756->cache_age;
    int v854 = v853[1];
    int v934 = v854 + ((int)((unsigned int)(v854 - v850) >> 31));
    v853[1] = v934;
    int * v856 = v756->cache_age;
    v856[v928] = 0;
    v859 = v928;
  }
  int v937 = v859 * 2;
  int v860 = v766[v937];
  int * v861 = v756->regs;
  v861[14] = v860;
  return v756;
}

struct StateT * slot_6(struct StateT * v284) {
  int v285 = v284->timer;
  int v292 = v285 + 1;
  v284->timer = v292;
  int * v287 = v284->regs;
  int v288 = v287[11];
  int v295 = v288 << 2;
  v287[11] = v295;
  struct StateT * v290 = slot_7(v284);
  return v290;
}

struct StateT * slot_5(struct StateT * v73) {
  int * v74 = v73->saved_regs;
  int * v75 = v73->regs;
  int v76 = v75[11];
  v74[11] = v76;
  int v78 = v73->timer;
  int v192 = v78 + 1;
  v73->timer = v192;
  int * v80 = v73->regs;
  int v81 = v80[5];
  int * v82 = v73->cache_tags;
  int v196 = (((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 1) * 2;
  int v83 = v82[v196];
  int v197 = ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 1) * 2) + 1;
  int v84 = v82[v197];
  int v198 = 4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2);
  int v85 = v82[v198];
  int v199 = (4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v86 = v82[v199];
  int v87 = v73->timer;
  int v200 = v87 + ((100 ^ (((~(((v85 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v85 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) | (~(((v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v83 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v83 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) | (~(((v84 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v84 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v85 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v85 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) | (~(((v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31))) & 104)))));
  v73->timer = v200;
  int * v89 = v73->cache_vals;
  bool v201 = !(((~(((v83 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v83 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) | (~(((v84 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v84 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31))) == 0);
  int v182;
  if (v201) {
    int * v90 = v73->cache_age;
    int v203 = ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 1) * 2) + ((~(((v84 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v84 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) & 1);
    int v91 = v90[v203];
    int v92 = v90[v196];
    int v204 = v92 + ((int)((unsigned int)(v92 - v91) >> 31));
    v90[v196] = v204;
    int * v94 = v73->cache_age;
    int v95 = v94[v197];
    int v206 = v95 + ((int)((unsigned int)(v95 - v91) >> 31));
    v94[v197] = v206;
    int * v97 = v73->cache_age;
    v97[v203] = 0;
    v182 = v203;
  } else {
    int * v100 = v73->cache_age;
    int v210 = (((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 1) * 2;
    int v101 = v100[v210];
    int * v102 = v73->cache_tags;
    int v103 = v102[v210];
    int v104 = v100[v197];
    int v105 = v102[v197];
    bool v212 = !(((~(((v85 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v85 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) | (~(((v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31))) == 0);
    int v159;
    if (v212) {
      int * v106 = v73->cache_age;
      int v214 = (4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + ((~(((v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))) | (-(v86 ^ ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1))))) >> 31)) & 1);
      int v107 = v106[v214];
      int v108 = v106[v198];
      int v215 = v108 + ((int)((unsigned int)(v108 - v107) >> 31));
      v106[v198] = v215;
      int * v110 = v73->cache_age;
      int v111 = v110[v199];
      int v217 = v111 + ((int)((unsigned int)(v111 - v107) >> 31));
      v110[v199] = v217;
      int * v113 = v73->cache_age;
      v113[v214] = 0;
      v159 = v214;
    } else {
      int * v116 = v73->cache_age;
      int v221 = 4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2);
      int v117 = v116[v221];
      int * v118 = v73->cache_tags;
      int v119 = v118[v221];
      int v120 = v116[v199];
      int v121 = v118[v199];
      int * v122 = v73->cache_dirty;
      int v224 = (4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + ((((v117 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2)) - (v120 + ((~(((v121 ^ -1) | (-(v121 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v123 = v122[v224];
      bool v225 = !(v123 == 0);
      if (v225) {
        int * v124 = v73->cache_tags;
        int v125 = v124[v224];
        int * v126 = v73->cache_vals;
        int v228 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + ((((v117 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2)) - (v120 + ((~(((v121 ^ -1) | (-(v121 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v127 = v126[v228];
        int v229 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + ((((v117 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2)) - (v120 + ((~(((v121 ^ -1) | (-(v121 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v128 = v126[v229];
        int * v129 = v73->mem;
        int v231 = v125 * 2;
        v129[v231] = v127;
        int * v131 = v73->mem;
        int v234 = (v125 * 2) + 1;
        v131[v234] = v128;
        ;
      } else {
        ;
      }
      int * v136 = v73->mem;
      int v239 = ((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) * 2;
      int v137 = v136[v239];
      int v240 = (((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) * 2) + 1;
      int v138 = v136[v240];
      int * v139 = v73->cache_vals;
      int v242 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + ((((v117 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2)) - (v120 + ((~(((v121 ^ -1) | (-(v121 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v139[v242] = v137;
      int * v141 = v73->cache_vals;
      int v245 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 3) * 2)) + ((((v117 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2)) - (v120 + ((~(((v121 ^ -1) | (-(v121 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v141[v245] = v138;
      int * v143 = v73->cache_tags;
      int v248 = (int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1);
      v143[v224] = v248;
      int * v145 = v73->cache_dirty;
      v145[v224] = 0;
      int * v147 = v73->cache_age;
      v147[v224] = 1;
      int * v149 = v73->cache_age;
      int v150 = v149[v224];
      int v151 = v149[v198];
      int v254 = v151 + ((int)((unsigned int)(v151 - v150) >> 31));
      v149[v198] = v254;
      int * v153 = v73->cache_age;
      int v154 = v153[v199];
      int v256 = v154 + ((int)((unsigned int)(v154 - v150) >> 31));
      v153[v199] = v256;
      int * v156 = v73->cache_age;
      v156[v224] = 0;
      v159 = v224;
    }
    int * v160 = v73->cache_vals;
    int v259 = v159 * 2;
    int v161 = v160[v259];
    int v260 = (v159 * 2) + 1;
    int v162 = v160[v260];
    int v261 = (((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 1) * 2) + ((((v101 + ((~(((v103 ^ -1) | (-(v103 ^ -1))) >> 31)) & 2)) - (v104 + ((~(((v105 ^ -1) | (-(v105 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v160[v261] = v161;
    int * v164 = v73->cache_vals;
    int v264 = ((((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 1) * 2) + ((((v101 + ((~(((v103 ^ -1) | (-(v103 ^ -1))) >> 31)) & 2)) - (v104 + ((~(((v105 ^ -1) | (-(v105 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v164[v264] = v162;
    int * v166 = v73->cache_tags;
    int v267 = ((((int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1)) & 1) * 2) + ((((v101 + ((~(((v103 ^ -1) | (-(v103 ^ -1))) >> 31)) & 2)) - (v104 + ((~(((v105 ^ -1) | (-(v105 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v268 = (int)((unsigned int)((int)((unsigned int)v81 >> 2)) >> 1);
    v166[v267] = v268;
    int * v168 = v73->cache_dirty;
    v168[v267] = 0;
    int * v170 = v73->cache_age;
    v170[v267] = 1;
    int * v172 = v73->cache_age;
    int v173 = v172[v267];
    int v174 = v172[v196];
    int v274 = v174 + ((int)((unsigned int)(v174 - v173) >> 31));
    v172[v196] = v274;
    int * v176 = v73->cache_age;
    int v177 = v176[v197];
    int v276 = v177 + ((int)((unsigned int)(v177 - v173) >> 31));
    v176[v197] = v276;
    int * v179 = v73->cache_age;
    v179[v267] = 0;
    v182 = v267;
  }
  int v279 = (v182 * 2) + (((int)((unsigned int)v81 >> 2)) & 1);
  int v183 = v89[v279];
  int * v184 = v73->regs;
  v184[11] = v183;
  struct StateT * v186 = slot_6(v73);
  return v186;
}

struct StateT * slot_2(struct StateT * v28) {
  int v29 = v28->timer;
  int v35 = v29 + 1;
  v28->timer = v35;
  int * v31 = v28->regs;
  v31[15] = 80;
  struct StateT * v33 = slot_3(v28);
  return v33;
}

struct StateT * slot_7(struct StateT * v298) {
  int * v299 = v298->saved_regs;
  int * v300 = v298->regs;
  int v301 = v300[12];
  v299[12] = v301;
  int v303 = v298->timer;
  int v417 = v303 + 1;
  v298->timer = v417;
  int * v305 = v298->regs;
  int v306 = v305[11];
  int * v307 = v298->cache_tags;
  int v421 = (((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 1) * 2;
  int v308 = v307[v421];
  int v422 = ((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 1) * 2) + 1;
  int v309 = v307[v422];
  int v423 = 4 + ((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 3) * 2);
  int v310 = v307[v423];
  int v424 = (4 + ((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v311 = v307[v424];
  int v312 = v298->timer;
  int v425 = v312 + ((100 ^ (((~(((v310 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))) | (-(v310 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))))) >> 31)) | (~(((v311 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))) | (-(v311 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v308 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))) | (-(v308 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))))) >> 31)) | (~(((v309 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))) | (-(v309 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v310 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))) | (-(v310 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))))) >> 31)) | (~(((v311 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))) | (-(v311 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))))) >> 31))) & 104)))));
  v298->timer = v425;
  int * v314 = v298->cache_vals;
  bool v426 = !(((~(((v308 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))) | (-(v308 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))))) >> 31)) | (~(((v309 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))) | (-(v309 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))))) >> 31))) == 0);
  int v407;
  if (v426) {
    int * v315 = v298->cache_age;
    int v428 = ((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 1) * 2) + ((~(((v309 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))) | (-(v309 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))))) >> 31)) & 1);
    int v316 = v315[v428];
    int v317 = v315[v421];
    int v429 = v317 + ((int)((unsigned int)(v317 - v316) >> 31));
    v315[v421] = v429;
    int * v319 = v298->cache_age;
    int v320 = v319[v422];
    int v431 = v320 + ((int)((unsigned int)(v320 - v316) >> 31));
    v319[v422] = v431;
    int * v322 = v298->cache_age;
    v322[v428] = 0;
    v407 = v428;
  } else {
    int * v325 = v298->cache_age;
    int v435 = (((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 1) * 2;
    int v326 = v325[v435];
    int * v327 = v298->cache_tags;
    int v328 = v327[v435];
    int v329 = v325[v422];
    int v330 = v327[v422];
    bool v437 = !(((~(((v310 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))) | (-(v310 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))))) >> 31)) | (~(((v311 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))) | (-(v311 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))))) >> 31))) == 0);
    int v384;
    if (v437) {
      int * v331 = v298->cache_age;
      int v439 = (4 + ((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 3) * 2)) + ((~(((v311 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))) | (-(v311 ^ ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1))))) >> 31)) & 1);
      int v332 = v331[v439];
      int v333 = v331[v423];
      int v440 = v333 + ((int)((unsigned int)(v333 - v332) >> 31));
      v331[v423] = v440;
      int * v335 = v298->cache_age;
      int v336 = v335[v424];
      int v442 = v336 + ((int)((unsigned int)(v336 - v332) >> 31));
      v335[v424] = v442;
      int * v338 = v298->cache_age;
      v338[v439] = 0;
      v384 = v439;
    } else {
      int * v341 = v298->cache_age;
      int v446 = 4 + ((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 3) * 2);
      int v342 = v341[v446];
      int * v343 = v298->cache_tags;
      int v344 = v343[v446];
      int v345 = v341[v424];
      int v346 = v343[v424];
      int * v347 = v298->cache_dirty;
      int v449 = (4 + ((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 3) * 2)) + ((((v342 + ((~(((v344 ^ -1) | (-(v344 ^ -1))) >> 31)) & 2)) - (v345 + ((~(((v346 ^ -1) | (-(v346 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v348 = v347[v449];
      bool v450 = !(v348 == 0);
      if (v450) {
        int * v349 = v298->cache_tags;
        int v350 = v349[v449];
        int * v351 = v298->cache_vals;
        int v453 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 3) * 2)) + ((((v342 + ((~(((v344 ^ -1) | (-(v344 ^ -1))) >> 31)) & 2)) - (v345 + ((~(((v346 ^ -1) | (-(v346 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v352 = v351[v453];
        int v454 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 3) * 2)) + ((((v342 + ((~(((v344 ^ -1) | (-(v344 ^ -1))) >> 31)) & 2)) - (v345 + ((~(((v346 ^ -1) | (-(v346 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v353 = v351[v454];
        int * v354 = v298->mem;
        int v456 = v350 * 2;
        v354[v456] = v352;
        int * v356 = v298->mem;
        int v459 = (v350 * 2) + 1;
        v356[v459] = v353;
        ;
      } else {
        ;
      }
      int * v361 = v298->mem;
      int v464 = ((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) * 2;
      int v362 = v361[v464];
      int v465 = (((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) * 2) + 1;
      int v363 = v361[v465];
      int * v364 = v298->cache_vals;
      int v467 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 3) * 2)) + ((((v342 + ((~(((v344 ^ -1) | (-(v344 ^ -1))) >> 31)) & 2)) - (v345 + ((~(((v346 ^ -1) | (-(v346 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v364[v467] = v362;
      int * v366 = v298->cache_vals;
      int v470 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 3) * 2)) + ((((v342 + ((~(((v344 ^ -1) | (-(v344 ^ -1))) >> 31)) & 2)) - (v345 + ((~(((v346 ^ -1) | (-(v346 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v366[v470] = v363;
      int * v368 = v298->cache_tags;
      int v473 = (int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1);
      v368[v449] = v473;
      int * v370 = v298->cache_dirty;
      v370[v449] = 0;
      int * v372 = v298->cache_age;
      v372[v449] = 1;
      int * v374 = v298->cache_age;
      int v375 = v374[v449];
      int v376 = v374[v423];
      int v479 = v376 + ((int)((unsigned int)(v376 - v375) >> 31));
      v374[v423] = v479;
      int * v378 = v298->cache_age;
      int v379 = v378[v424];
      int v481 = v379 + ((int)((unsigned int)(v379 - v375) >> 31));
      v378[v424] = v481;
      int * v381 = v298->cache_age;
      v381[v449] = 0;
      v384 = v449;
    }
    int * v385 = v298->cache_vals;
    int v484 = v384 * 2;
    int v386 = v385[v484];
    int v485 = (v384 * 2) + 1;
    int v387 = v385[v485];
    int v486 = (((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 1) * 2) + ((((v326 + ((~(((v328 ^ -1) | (-(v328 ^ -1))) >> 31)) & 2)) - (v329 + ((~(((v330 ^ -1) | (-(v330 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v385[v486] = v386;
    int * v389 = v298->cache_vals;
    int v489 = ((((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 1) * 2) + ((((v326 + ((~(((v328 ^ -1) | (-(v328 ^ -1))) >> 31)) & 2)) - (v329 + ((~(((v330 ^ -1) | (-(v330 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v389[v489] = v387;
    int * v391 = v298->cache_tags;
    int v492 = ((((int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1)) & 1) * 2) + ((((v326 + ((~(((v328 ^ -1) | (-(v328 ^ -1))) >> 31)) & 2)) - (v329 + ((~(((v330 ^ -1) | (-(v330 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v493 = (int)((unsigned int)((int)((unsigned int)v306 >> 2)) >> 1);
    v391[v492] = v493;
    int * v393 = v298->cache_dirty;
    v393[v492] = 0;
    int * v395 = v298->cache_age;
    v395[v492] = 1;
    int * v397 = v298->cache_age;
    int v398 = v397[v492];
    int v399 = v397[v421];
    int v499 = v399 + ((int)((unsigned int)(v399 - v398) >> 31));
    v397[v421] = v499;
    int * v401 = v298->cache_age;
    int v402 = v401[v422];
    int v501 = v402 + ((int)((unsigned int)(v402 - v398) >> 31));
    v401[v422] = v501;
    int * v404 = v298->cache_age;
    v404[v492] = 0;
    v407 = v492;
  }
  int v504 = (v407 * 2) + (((int)((unsigned int)v306 >> 2)) & 1);
  int v408 = v314[v504];
  int * v409 = v298->regs;
  v409[12] = v408;
  struct StateT * v411 = slot_8(v298);
  return v411;
}

struct StateT * slot_3(struct StateT * v41) {
  int v42 = v41->timer;
  int v46 = v42 + 1;
  v41->timer = v46;
  struct StateT * v44 = slot_4(v41);
  return v44;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v563) {
  int v564 = v563->timer;
  int v568 = v564 + 1;
  v563->timer = v568;
  struct StateT * v566 = slot_12(v563);
  return v566;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v22 = v16 + 1;
  v15->timer = v22;
  int * v18 = v15->regs;
  v18[10] = 80;
  struct StateT * v20 = slot_2(v15);
  return v20;
}

struct StateT * slot_8(struct StateT * v509) {
  int * v510 = v509->regs;
  int v511 = v510[10];
  int v512 = v510[15];
  bool v536 = v511 >= v512;
  struct StateT * v531;
  if (v536) {
    int v513 = v509->timer;
    int v537 = v513 + 15;
    v509->timer = v537;
    int * v515 = v509->saved_regs;
    int v516 = v515[5];
    int * v517 = v509->regs;
    v517[5] = v516;
    int * v519 = v509->saved_regs;
    int v520 = v519[11];
    int * v521 = v509->regs;
    v521[11] = v520;
    int * v523 = v509->saved_regs;
    int v524 = v523[12];
    int * v525 = v509->regs;
    v525[12] = v524;
    struct StateT * v527 = slot_10(v509);
    v531 = v527;
  } else {
    struct StateT * v529 = slot_10(v509);
    v531 = v529;
  }
  return v531;
}

struct StateT * slot_4(struct StateT * v49) {
  int * v50 = v49->saved_regs;
  int * v51 = v49->regs;
  int v52 = v51[5];
  v50[5] = v52;
  int v54 = v49->timer;
  int v66 = v54 + 1;
  v49->timer = v66;
  int * v56 = v49->regs;
  int v57 = v56[13];
  int v58 = v56[10];
  int v70 = v57 + v58;
  v56[5] = v70;
  struct StateT * v60 = slot_5(v49);
  return v60;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[13] = 0;
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