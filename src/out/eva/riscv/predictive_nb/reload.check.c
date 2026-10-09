// verify: leak (Eva should report untainted_timer: unknown) [unroll 65]
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

struct StateT * slot_12(struct StateT * v804);
struct StateT * slot_6(struct StateT * v305);
struct StateT * slot_5(struct StateT * v90);
struct StateT * slot_2(struct StateT * v34);
struct StateT * slot_7(struct StateT * v326);
struct StateT * slot_3(struct StateT * v50);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v610);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_8(struct StateT * v541);
struct StateT * slot_4(struct StateT * v58);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v804) {
  int v805 = v804->timer;
  int v912 = v805 + 1;
  v804->timer = v912;
  int * v807 = v804->cache_tags;
  int v808 = v807[0];
  int v809 = v807[1];
  int v810 = v807[4];
  int v811 = v807[5];
  int * v812 = v804->cache_vals;
  bool v918 = !(((~((v808 | (-v808)) >> 31)) | (~((v809 | (-v809)) >> 31))) == 0);
  int v905;
  if (v918) {
    int * v813 = v804->cache_age;
    int v920 = (~((v809 | (-v809)) >> 31)) & 1;
    int v814 = v813[v920];
    int v815 = v813[0];
    int v921 = v815 + ((int)((unsigned int)(v815 - v814) >> 31));
    v813[0] = v921;
    int * v817 = v804->cache_age;
    int v818 = v817[1];
    int v923 = v818 + ((int)((unsigned int)(v818 - v814) >> 31));
    v817[1] = v923;
    int * v820 = v804->cache_age;
    v820[v920] = 0;
    v905 = v920;
  } else {
    int * v823 = v804->cache_age;
    int v824 = v823[0];
    int * v825 = v804->cache_tags;
    int v826 = v825[0];
    int v827 = v823[1];
    int v828 = v825[1];
    bool v927 = !(((~((v810 | (-v810)) >> 31)) | (~((v811 | (-v811)) >> 31))) == 0);
    int v882;
    if (v927) {
      int * v829 = v804->cache_age;
      int v929 = 4 + ((~((v811 | (-v811)) >> 31)) & 1);
      int v830 = v829[v929];
      int v831 = v829[4];
      int v930 = v831 + ((int)((unsigned int)(v831 - v830) >> 31));
      v829[4] = v930;
      int * v833 = v804->cache_age;
      int v834 = v833[5];
      int v932 = v834 + ((int)((unsigned int)(v834 - v830) >> 31));
      v833[5] = v932;
      int * v836 = v804->cache_age;
      v836[v929] = 0;
      v882 = v929;
    } else {
      int * v839 = v804->cache_age;
      int v840 = v839[4];
      int * v841 = v804->cache_tags;
      int v842 = v841[4];
      int v843 = v839[5];
      int v844 = v841[5];
      int * v845 = v804->cache_dirty;
      int v937 = 4 + ((((v840 + ((~(((v842 ^ -1) | (-(v842 ^ -1))) >> 31)) & 2)) - (v843 + ((~(((v844 ^ -1) | (-(v844 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v846 = v845[v937];
      bool v938 = !(v846 == 0);
      if (v938) {
        int * v847 = v804->cache_tags;
        int v848 = v847[v937];
        int * v849 = v804->cache_vals;
        int v941 = (4 + ((((v840 + ((~(((v842 ^ -1) | (-(v842 ^ -1))) >> 31)) & 2)) - (v843 + ((~(((v844 ^ -1) | (-(v844 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v850 = v849[v941];
        int v942 = ((4 + ((((v840 + ((~(((v842 ^ -1) | (-(v842 ^ -1))) >> 31)) & 2)) - (v843 + ((~(((v844 ^ -1) | (-(v844 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v851 = v849[v942];
        int * v852 = v804->mem;
        int v944 = v848 * 2;
        v852[v944] = v850;
        int * v854 = v804->mem;
        int v947 = (v848 * 2) + 1;
        v854[v947] = v851;
        ;
      } else {
        ;
      }
      int * v859 = v804->mem;
      int v860 = v859[0];
      int v861 = v859[1];
      int * v862 = v804->cache_vals;
      int v953 = (4 + ((((v840 + ((~(((v842 ^ -1) | (-(v842 ^ -1))) >> 31)) & 2)) - (v843 + ((~(((v844 ^ -1) | (-(v844 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v862[v953] = v860;
      int * v864 = v804->cache_vals;
      int v956 = ((4 + ((((v840 + ((~(((v842 ^ -1) | (-(v842 ^ -1))) >> 31)) & 2)) - (v843 + ((~(((v844 ^ -1) | (-(v844 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v864[v956] = v861;
      int * v866 = v804->cache_tags;
      v866[v937] = 0;
      int * v868 = v804->cache_dirty;
      v868[v937] = 0;
      int * v870 = v804->cache_age;
      v870[v937] = 1;
      int * v872 = v804->cache_age;
      int v873 = v872[v937];
      int v874 = v872[4];
      int v962 = v874 + ((int)((unsigned int)(v874 - v873) >> 31));
      v872[4] = v962;
      int * v876 = v804->cache_age;
      int v877 = v876[5];
      int v964 = v877 + ((int)((unsigned int)(v877 - v873) >> 31));
      v876[5] = v964;
      int * v879 = v804->cache_age;
      v879[v937] = 0;
      v882 = v937;
    }
    int * v883 = v804->cache_vals;
    int v967 = v882 * 2;
    int v884 = v883[v967];
    int v968 = (v882 * 2) + 1;
    int v885 = v883[v968];
    int v969 = ((((v824 + ((~(((v826 ^ -1) | (-(v826 ^ -1))) >> 31)) & 2)) - (v827 + ((~(((v828 ^ -1) | (-(v828 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v883[v969] = v884;
    int * v887 = v804->cache_vals;
    int v972 = (((((v824 + ((~(((v826 ^ -1) | (-(v826 ^ -1))) >> 31)) & 2)) - (v827 + ((~(((v828 ^ -1) | (-(v828 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v887[v972] = v885;
    int * v889 = v804->cache_tags;
    int v975 = (((v824 + ((~(((v826 ^ -1) | (-(v826 ^ -1))) >> 31)) & 2)) - (v827 + ((~(((v828 ^ -1) | (-(v828 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v889[v975] = 0;
    int * v891 = v804->cache_dirty;
    v891[v975] = 0;
    int * v893 = v804->cache_age;
    v893[v975] = 1;
    int * v895 = v804->cache_age;
    int v896 = v895[v975];
    int v897 = v895[0];
    int v979 = v897 + ((int)((unsigned int)(v897 - v896) >> 31));
    v895[0] = v979;
    int * v899 = v804->cache_age;
    int v900 = v899[1];
    int v981 = v900 + ((int)((unsigned int)(v900 - v896) >> 31));
    v899[1] = v981;
    int * v902 = v804->cache_age;
    v902[v975] = 0;
    v905 = v975;
  }
  int v984 = v905 * 2;
  int v906 = v812[v984];
  int * v907 = v804->reg_ready;
  int v987 = (v805 + 1) + ((100 ^ (((~((v810 | (-v810)) >> 31)) | (~((v811 | (-v811)) >> 31))) & 104)) ^ (((~((v808 | (-v808)) >> 31)) | (~((v809 | (-v809)) >> 31))) & (1 ^ (100 ^ (((~((v810 | (-v810)) >> 31)) | (~((v811 | (-v811)) >> 31))) & 104)))));
  v907[14] = v987;
  int * v909 = v804->regs;
  v909[14] = v906;
  return v804;
}

struct StateT * slot_6(struct StateT * v305) {
  int v306 = v305->timer;
  int v317 = v306 + 1;
  v305->timer = v317;
  int * v308 = v305->reg_ready;
  int v309 = v308[11];
  int * v310 = v305->regs;
  int v311 = v310[11];
  int v321 = (v309 + ((v306 - v309) & (~((v306 - v309) >> 31)))) + 1;
  v308[11] = v321;
  int * v313 = v305->regs;
  int v323 = v311 << 2;
  v313[11] = v323;
  struct StateT * v315 = slot_7(v305);
  return v315;
}

struct StateT * slot_5(struct StateT * v90) {
  int * v91 = v90->saved_regs;
  int * v92 = v90->regs;
  int v93 = v92[11];
  v91[11] = v93;
  int v95 = v90->timer;
  int v211 = v95 + 1;
  v90->timer = v211;
  int * v97 = v90->reg_ready;
  int v98 = v97[5];
  int * v99 = v90->regs;
  int v100 = v99[5];
  int * v101 = v90->cache_tags;
  int v216 = (((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 1) * 2;
  int v102 = v101[v216];
  int v217 = ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 1) * 2) + 1;
  int v103 = v101[v217];
  int v218 = 4 + ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 3) * 2);
  int v104 = v101[v218];
  int v219 = (4 + ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v105 = v101[v219];
  int * v106 = v90->cache_vals;
  bool v220 = !(((~(((v102 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v102 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31)) | (~(((v103 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v103 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31))) == 0);
  int v199;
  if (v220) {
    int * v107 = v90->cache_age;
    int v222 = ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 1) * 2) + ((~(((v103 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v103 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31)) & 1);
    int v108 = v107[v222];
    int v109 = v107[v216];
    int v223 = v109 + ((int)((unsigned int)(v109 - v108) >> 31));
    v107[v216] = v223;
    int * v111 = v90->cache_age;
    int v112 = v111[v217];
    int v225 = v112 + ((int)((unsigned int)(v112 - v108) >> 31));
    v111[v217] = v225;
    int * v114 = v90->cache_age;
    v114[v222] = 0;
    v199 = v222;
  } else {
    int * v117 = v90->cache_age;
    int v229 = (((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 1) * 2;
    int v118 = v117[v229];
    int * v119 = v90->cache_tags;
    int v120 = v119[v229];
    int v121 = v117[v217];
    int v122 = v119[v217];
    bool v231 = !(((~(((v104 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v104 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31)) | (~(((v105 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v105 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31))) == 0);
    int v176;
    if (v231) {
      int * v123 = v90->cache_age;
      int v233 = (4 + ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 3) * 2)) + ((~(((v105 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v105 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31)) & 1);
      int v124 = v123[v233];
      int v125 = v123[v218];
      int v234 = v125 + ((int)((unsigned int)(v125 - v124) >> 31));
      v123[v218] = v234;
      int * v127 = v90->cache_age;
      int v128 = v127[v219];
      int v236 = v128 + ((int)((unsigned int)(v128 - v124) >> 31));
      v127[v219] = v236;
      int * v130 = v90->cache_age;
      v130[v233] = 0;
      v176 = v233;
    } else {
      int * v133 = v90->cache_age;
      int v240 = 4 + ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 3) * 2);
      int v134 = v133[v240];
      int * v135 = v90->cache_tags;
      int v136 = v135[v240];
      int v137 = v133[v219];
      int v138 = v135[v219];
      int * v139 = v90->cache_dirty;
      int v243 = (4 + ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 3) * 2)) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v137 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v140 = v139[v243];
      bool v244 = !(v140 == 0);
      if (v244) {
        int * v141 = v90->cache_tags;
        int v142 = v141[v243];
        int * v143 = v90->cache_vals;
        int v247 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 3) * 2)) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v137 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v144 = v143[v247];
        int v248 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 3) * 2)) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v137 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v145 = v143[v248];
        int * v146 = v90->mem;
        int v250 = v142 * 2;
        v146[v250] = v144;
        int * v148 = v90->mem;
        int v253 = (v142 * 2) + 1;
        v148[v253] = v145;
        ;
      } else {
        ;
      }
      int * v153 = v90->mem;
      int v258 = ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) * 2;
      int v154 = v153[v258];
      int v259 = (((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) * 2) + 1;
      int v155 = v153[v259];
      int * v156 = v90->cache_vals;
      int v261 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 3) * 2)) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v137 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v156[v261] = v154;
      int * v158 = v90->cache_vals;
      int v264 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 3) * 2)) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v137 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v158[v264] = v155;
      int * v160 = v90->cache_tags;
      int v267 = (int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1);
      v160[v243] = v267;
      int * v162 = v90->cache_dirty;
      v162[v243] = 0;
      int * v164 = v90->cache_age;
      v164[v243] = 1;
      int * v166 = v90->cache_age;
      int v167 = v166[v243];
      int v168 = v166[v218];
      int v273 = v168 + ((int)((unsigned int)(v168 - v167) >> 31));
      v166[v218] = v273;
      int * v170 = v90->cache_age;
      int v171 = v170[v219];
      int v275 = v171 + ((int)((unsigned int)(v171 - v167) >> 31));
      v170[v219] = v275;
      int * v173 = v90->cache_age;
      v173[v243] = 0;
      v176 = v243;
    }
    int * v177 = v90->cache_vals;
    int v278 = v176 * 2;
    int v178 = v177[v278];
    int v279 = (v176 * 2) + 1;
    int v179 = v177[v279];
    int v280 = (((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 1) * 2) + ((((v118 + ((~(((v120 ^ -1) | (-(v120 ^ -1))) >> 31)) & 2)) - (v121 + ((~(((v122 ^ -1) | (-(v122 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v177[v280] = v178;
    int * v181 = v90->cache_vals;
    int v283 = ((((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 1) * 2) + ((((v118 + ((~(((v120 ^ -1) | (-(v120 ^ -1))) >> 31)) & 2)) - (v121 + ((~(((v122 ^ -1) | (-(v122 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v181[v283] = v179;
    int * v183 = v90->cache_tags;
    int v286 = ((((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1)) & 1) * 2) + ((((v118 + ((~(((v120 ^ -1) | (-(v120 ^ -1))) >> 31)) & 2)) - (v121 + ((~(((v122 ^ -1) | (-(v122 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v287 = (int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1);
    v183[v286] = v287;
    int * v185 = v90->cache_dirty;
    v185[v286] = 0;
    int * v187 = v90->cache_age;
    v187[v286] = 1;
    int * v189 = v90->cache_age;
    int v190 = v189[v286];
    int v191 = v189[v216];
    int v293 = v191 + ((int)((unsigned int)(v191 - v190) >> 31));
    v189[v216] = v293;
    int * v193 = v90->cache_age;
    int v194 = v193[v217];
    int v295 = v194 + ((int)((unsigned int)(v194 - v190) >> 31));
    v193[v217] = v295;
    int * v196 = v90->cache_age;
    v196[v286] = 0;
    v199 = v286;
  }
  int v298 = (v199 * 2) + (((int)((unsigned int)v100 >> 2)) & 1);
  int v200 = v106[v298];
  int * v201 = v90->reg_ready;
  int v300 = ((v98 + ((v95 - v98) & (~((v95 - v98) >> 31)))) + 1) + ((100 ^ (((~(((v104 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v104 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31)) | (~(((v105 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v105 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v102 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v102 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31)) | (~(((v103 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v103 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v104 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v104 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31)) | (~(((v105 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))) | (-(v105 ^ ((int)((unsigned int)((int)((unsigned int)v100 >> 2)) >> 1))))) >> 31))) & 104)))));
  v201[11] = v300;
  int * v203 = v90->regs;
  v203[11] = v200;
  struct StateT * v205 = slot_6(v90);
  return v205;
}

struct StateT * slot_2(struct StateT * v34) {
  int v35 = v34->timer;
  int v43 = v35 + 1;
  v34->timer = v43;
  int * v37 = v34->reg_ready;
  v37[15] = v43;
  int * v39 = v34->regs;
  v39[15] = 80;
  struct StateT * v41 = slot_3(v34);
  return v41;
}

struct StateT * slot_7(struct StateT * v326) {
  int * v327 = v326->saved_regs;
  int * v328 = v326->regs;
  int v329 = v328[12];
  v327[12] = v329;
  int v331 = v326->timer;
  int v447 = v331 + 1;
  v326->timer = v447;
  int * v333 = v326->reg_ready;
  int v334 = v333[11];
  int * v335 = v326->regs;
  int v336 = v335[11];
  int * v337 = v326->cache_tags;
  int v452 = (((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 1) * 2;
  int v338 = v337[v452];
  int v453 = ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 1) * 2) + 1;
  int v339 = v337[v453];
  int v454 = 4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2);
  int v340 = v337[v454];
  int v455 = (4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v341 = v337[v455];
  int * v342 = v326->cache_vals;
  bool v456 = !(((~(((v338 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v338 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31)) | (~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31))) == 0);
  int v435;
  if (v456) {
    int * v343 = v326->cache_age;
    int v458 = ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 1) * 2) + ((~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31)) & 1);
    int v344 = v343[v458];
    int v345 = v343[v452];
    int v459 = v345 + ((int)((unsigned int)(v345 - v344) >> 31));
    v343[v452] = v459;
    int * v347 = v326->cache_age;
    int v348 = v347[v453];
    int v461 = v348 + ((int)((unsigned int)(v348 - v344) >> 31));
    v347[v453] = v461;
    int * v350 = v326->cache_age;
    v350[v458] = 0;
    v435 = v458;
  } else {
    int * v353 = v326->cache_age;
    int v465 = (((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 1) * 2;
    int v354 = v353[v465];
    int * v355 = v326->cache_tags;
    int v356 = v355[v465];
    int v357 = v353[v453];
    int v358 = v355[v453];
    bool v467 = !(((~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31)) | (~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31))) == 0);
    int v412;
    if (v467) {
      int * v359 = v326->cache_age;
      int v469 = (4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2)) + ((~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31)) & 1);
      int v360 = v359[v469];
      int v361 = v359[v454];
      int v470 = v361 + ((int)((unsigned int)(v361 - v360) >> 31));
      v359[v454] = v470;
      int * v363 = v326->cache_age;
      int v364 = v363[v455];
      int v472 = v364 + ((int)((unsigned int)(v364 - v360) >> 31));
      v363[v455] = v472;
      int * v366 = v326->cache_age;
      v366[v469] = 0;
      v412 = v469;
    } else {
      int * v369 = v326->cache_age;
      int v476 = 4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2);
      int v370 = v369[v476];
      int * v371 = v326->cache_tags;
      int v372 = v371[v476];
      int v373 = v369[v455];
      int v374 = v371[v455];
      int * v375 = v326->cache_dirty;
      int v479 = (4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2)) + ((((v370 + ((~(((v372 ^ -1) | (-(v372 ^ -1))) >> 31)) & 2)) - (v373 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v376 = v375[v479];
      bool v480 = !(v376 == 0);
      if (v480) {
        int * v377 = v326->cache_tags;
        int v378 = v377[v479];
        int * v379 = v326->cache_vals;
        int v483 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2)) + ((((v370 + ((~(((v372 ^ -1) | (-(v372 ^ -1))) >> 31)) & 2)) - (v373 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v380 = v379[v483];
        int v484 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2)) + ((((v370 + ((~(((v372 ^ -1) | (-(v372 ^ -1))) >> 31)) & 2)) - (v373 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v381 = v379[v484];
        int * v382 = v326->mem;
        int v486 = v378 * 2;
        v382[v486] = v380;
        int * v384 = v326->mem;
        int v489 = (v378 * 2) + 1;
        v384[v489] = v381;
        ;
      } else {
        ;
      }
      int * v389 = v326->mem;
      int v494 = ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) * 2;
      int v390 = v389[v494];
      int v495 = (((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) * 2) + 1;
      int v391 = v389[v495];
      int * v392 = v326->cache_vals;
      int v497 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2)) + ((((v370 + ((~(((v372 ^ -1) | (-(v372 ^ -1))) >> 31)) & 2)) - (v373 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v392[v497] = v390;
      int * v394 = v326->cache_vals;
      int v500 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 3) * 2)) + ((((v370 + ((~(((v372 ^ -1) | (-(v372 ^ -1))) >> 31)) & 2)) - (v373 + ((~(((v374 ^ -1) | (-(v374 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v394[v500] = v391;
      int * v396 = v326->cache_tags;
      int v503 = (int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1);
      v396[v479] = v503;
      int * v398 = v326->cache_dirty;
      v398[v479] = 0;
      int * v400 = v326->cache_age;
      v400[v479] = 1;
      int * v402 = v326->cache_age;
      int v403 = v402[v479];
      int v404 = v402[v454];
      int v509 = v404 + ((int)((unsigned int)(v404 - v403) >> 31));
      v402[v454] = v509;
      int * v406 = v326->cache_age;
      int v407 = v406[v455];
      int v511 = v407 + ((int)((unsigned int)(v407 - v403) >> 31));
      v406[v455] = v511;
      int * v409 = v326->cache_age;
      v409[v479] = 0;
      v412 = v479;
    }
    int * v413 = v326->cache_vals;
    int v514 = v412 * 2;
    int v414 = v413[v514];
    int v515 = (v412 * 2) + 1;
    int v415 = v413[v515];
    int v516 = (((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 1) * 2) + ((((v354 + ((~(((v356 ^ -1) | (-(v356 ^ -1))) >> 31)) & 2)) - (v357 + ((~(((v358 ^ -1) | (-(v358 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v413[v516] = v414;
    int * v417 = v326->cache_vals;
    int v519 = ((((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 1) * 2) + ((((v354 + ((~(((v356 ^ -1) | (-(v356 ^ -1))) >> 31)) & 2)) - (v357 + ((~(((v358 ^ -1) | (-(v358 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v417[v519] = v415;
    int * v419 = v326->cache_tags;
    int v522 = ((((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1)) & 1) * 2) + ((((v354 + ((~(((v356 ^ -1) | (-(v356 ^ -1))) >> 31)) & 2)) - (v357 + ((~(((v358 ^ -1) | (-(v358 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v523 = (int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1);
    v419[v522] = v523;
    int * v421 = v326->cache_dirty;
    v421[v522] = 0;
    int * v423 = v326->cache_age;
    v423[v522] = 1;
    int * v425 = v326->cache_age;
    int v426 = v425[v522];
    int v427 = v425[v452];
    int v529 = v427 + ((int)((unsigned int)(v427 - v426) >> 31));
    v425[v452] = v529;
    int * v429 = v326->cache_age;
    int v430 = v429[v453];
    int v531 = v430 + ((int)((unsigned int)(v430 - v426) >> 31));
    v429[v453] = v531;
    int * v432 = v326->cache_age;
    v432[v522] = 0;
    v435 = v522;
  }
  int v534 = (v435 * 2) + (((int)((unsigned int)v336 >> 2)) & 1);
  int v436 = v342[v534];
  int * v437 = v326->reg_ready;
  int v536 = ((v334 + ((v331 - v334) & (~((v331 - v334) >> 31)))) + 1) + ((100 ^ (((~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31)) | (~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v338 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v338 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31)) | (~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31)) | (~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)v336 >> 2)) >> 1))))) >> 31))) & 104)))));
  v437[12] = v536;
  int * v439 = v326->regs;
  v439[12] = v436;
  struct StateT * v441 = slot_8(v326);
  return v441;
}

struct StateT * slot_3(struct StateT * v50) {
  int v51 = v50->timer;
  int v55 = v51 + 1;
  v50->timer = v55;
  struct StateT * v53 = slot_4(v50);
  return v53;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v990 = v1->timer;
  int * v991 = v1->reg_ready;
  int v992 = v991[0];
  int v1123 = v992 + ((v990 - v992) & (~((v990 - v992) >> 31)));
  v1->timer = v1123;
  int v994 = v1->timer;
  int * v995 = v1->reg_ready;
  int v996 = v995[1];
  int v1126 = v996 + ((v994 - v996) & (~((v994 - v996) >> 31)));
  v1->timer = v1126;
  int v998 = v1->timer;
  int * v999 = v1->reg_ready;
  int v1000 = v999[2];
  int v1129 = v1000 + ((v998 - v1000) & (~((v998 - v1000) >> 31)));
  v1->timer = v1129;
  int v1002 = v1->timer;
  int * v1003 = v1->reg_ready;
  int v1004 = v1003[3];
  int v1132 = v1004 + ((v1002 - v1004) & (~((v1002 - v1004) >> 31)));
  v1->timer = v1132;
  int v1006 = v1->timer;
  int * v1007 = v1->reg_ready;
  int v1008 = v1007[4];
  int v1135 = v1008 + ((v1006 - v1008) & (~((v1006 - v1008) >> 31)));
  v1->timer = v1135;
  int v1010 = v1->timer;
  int * v1011 = v1->reg_ready;
  int v1012 = v1011[5];
  int v1138 = v1012 + ((v1010 - v1012) & (~((v1010 - v1012) >> 31)));
  v1->timer = v1138;
  int v1014 = v1->timer;
  int * v1015 = v1->reg_ready;
  int v1016 = v1015[6];
  int v1141 = v1016 + ((v1014 - v1016) & (~((v1014 - v1016) >> 31)));
  v1->timer = v1141;
  int v1018 = v1->timer;
  int * v1019 = v1->reg_ready;
  int v1020 = v1019[7];
  int v1144 = v1020 + ((v1018 - v1020) & (~((v1018 - v1020) >> 31)));
  v1->timer = v1144;
  int v1022 = v1->timer;
  int * v1023 = v1->reg_ready;
  int v1024 = v1023[8];
  int v1147 = v1024 + ((v1022 - v1024) & (~((v1022 - v1024) >> 31)));
  v1->timer = v1147;
  int v1026 = v1->timer;
  int * v1027 = v1->reg_ready;
  int v1028 = v1027[9];
  int v1150 = v1028 + ((v1026 - v1028) & (~((v1026 - v1028) >> 31)));
  v1->timer = v1150;
  int v1030 = v1->timer;
  int * v1031 = v1->reg_ready;
  int v1032 = v1031[10];
  int v1153 = v1032 + ((v1030 - v1032) & (~((v1030 - v1032) >> 31)));
  v1->timer = v1153;
  int v1034 = v1->timer;
  int * v1035 = v1->reg_ready;
  int v1036 = v1035[11];
  int v1156 = v1036 + ((v1034 - v1036) & (~((v1034 - v1036) >> 31)));
  v1->timer = v1156;
  int v1038 = v1->timer;
  int * v1039 = v1->reg_ready;
  int v1040 = v1039[12];
  int v1159 = v1040 + ((v1038 - v1040) & (~((v1038 - v1040) >> 31)));
  v1->timer = v1159;
  int v1042 = v1->timer;
  int * v1043 = v1->reg_ready;
  int v1044 = v1043[13];
  int v1162 = v1044 + ((v1042 - v1044) & (~((v1042 - v1044) >> 31)));
  v1->timer = v1162;
  int v1046 = v1->timer;
  int * v1047 = v1->reg_ready;
  int v1048 = v1047[14];
  int v1165 = v1048 + ((v1046 - v1048) & (~((v1046 - v1048) >> 31)));
  v1->timer = v1165;
  int v1050 = v1->timer;
  int * v1051 = v1->reg_ready;
  int v1052 = v1051[15];
  int v1168 = v1052 + ((v1050 - v1052) & (~((v1050 - v1052) >> 31)));
  v1->timer = v1168;
  int v1054 = v1->timer;
  int * v1055 = v1->reg_ready;
  int v1056 = v1055[16];
  int v1171 = v1056 + ((v1054 - v1056) & (~((v1054 - v1056) >> 31)));
  v1->timer = v1171;
  int v1058 = v1->timer;
  int * v1059 = v1->reg_ready;
  int v1060 = v1059[17];
  int v1174 = v1060 + ((v1058 - v1060) & (~((v1058 - v1060) >> 31)));
  v1->timer = v1174;
  int v1062 = v1->timer;
  int * v1063 = v1->reg_ready;
  int v1064 = v1063[18];
  int v1177 = v1064 + ((v1062 - v1064) & (~((v1062 - v1064) >> 31)));
  v1->timer = v1177;
  int v1066 = v1->timer;
  int * v1067 = v1->reg_ready;
  int v1068 = v1067[19];
  int v1180 = v1068 + ((v1066 - v1068) & (~((v1066 - v1068) >> 31)));
  v1->timer = v1180;
  int v1070 = v1->timer;
  int * v1071 = v1->reg_ready;
  int v1072 = v1071[20];
  int v1183 = v1072 + ((v1070 - v1072) & (~((v1070 - v1072) >> 31)));
  v1->timer = v1183;
  int v1074 = v1->timer;
  int * v1075 = v1->reg_ready;
  int v1076 = v1075[21];
  int v1186 = v1076 + ((v1074 - v1076) & (~((v1074 - v1076) >> 31)));
  v1->timer = v1186;
  int v1078 = v1->timer;
  int * v1079 = v1->reg_ready;
  int v1080 = v1079[22];
  int v1189 = v1080 + ((v1078 - v1080) & (~((v1078 - v1080) >> 31)));
  v1->timer = v1189;
  int v1082 = v1->timer;
  int * v1083 = v1->reg_ready;
  int v1084 = v1083[23];
  int v1192 = v1084 + ((v1082 - v1084) & (~((v1082 - v1084) >> 31)));
  v1->timer = v1192;
  int v1086 = v1->timer;
  int * v1087 = v1->reg_ready;
  int v1088 = v1087[24];
  int v1195 = v1088 + ((v1086 - v1088) & (~((v1086 - v1088) >> 31)));
  v1->timer = v1195;
  int v1090 = v1->timer;
  int * v1091 = v1->reg_ready;
  int v1092 = v1091[25];
  int v1198 = v1092 + ((v1090 - v1092) & (~((v1090 - v1092) >> 31)));
  v1->timer = v1198;
  int v1094 = v1->timer;
  int * v1095 = v1->reg_ready;
  int v1096 = v1095[26];
  int v1201 = v1096 + ((v1094 - v1096) & (~((v1094 - v1096) >> 31)));
  v1->timer = v1201;
  int v1098 = v1->timer;
  int * v1099 = v1->reg_ready;
  int v1100 = v1099[27];
  int v1204 = v1100 + ((v1098 - v1100) & (~((v1098 - v1100) >> 31)));
  v1->timer = v1204;
  int v1102 = v1->timer;
  int * v1103 = v1->reg_ready;
  int v1104 = v1103[28];
  int v1207 = v1104 + ((v1102 - v1104) & (~((v1102 - v1104) >> 31)));
  v1->timer = v1207;
  int v1106 = v1->timer;
  int * v1107 = v1->reg_ready;
  int v1108 = v1107[29];
  int v1210 = v1108 + ((v1106 - v1108) & (~((v1106 - v1108) >> 31)));
  v1->timer = v1210;
  int v1110 = v1->timer;
  int * v1111 = v1->reg_ready;
  int v1112 = v1111[30];
  int v1213 = v1112 + ((v1110 - v1112) & (~((v1110 - v1112) >> 31)));
  v1->timer = v1213;
  int v1114 = v1->timer;
  int * v1115 = v1->reg_ready;
  int v1116 = v1115[31];
  int v1216 = v1116 + ((v1114 - v1116) & (~((v1114 - v1116) >> 31)));
  v1->timer = v1216;
  return v1;
}

struct StateT * slot_10(struct StateT * v610) {
  int v611 = v610->timer;
  int v615 = v611 + 1;
  v610->timer = v615;
  struct StateT * v613 = slot_12(v610);
  return v613;
}

struct StateT * slot_1(struct StateT * v18) {
  int v19 = v18->timer;
  int v27 = v19 + 1;
  v18->timer = v27;
  int * v21 = v18->reg_ready;
  v21[10] = v27;
  int * v23 = v18->regs;
  v23[10] = 80;
  struct StateT * v25 = slot_2(v18);
  return v25;
}

struct StateT * slot_8(struct StateT * v541) {
  int * v542 = v541->regs;
  int v543 = v542[10];
  int v544 = v542[15];
  bool v577 = v543 >= v544;
  struct StateT * v572;
  if (v577) {
    int v545 = v541->timer;
    int v578 = v545 + 15;
    v541->timer = v578;
    int * v547 = v541->saved_regs;
    int v548 = v547[5];
    int * v549 = v541->regs;
    v549[5] = v548;
    int * v551 = v541->saved_regs;
    int v552 = v551[11];
    int * v553 = v541->regs;
    v553[11] = v552;
    int * v555 = v541->saved_regs;
    int v556 = v555[12];
    int * v557 = v541->regs;
    v557[12] = v556;
    int * v559 = v541->reg_ready;
    int v560 = v541->timer;
    v559[5] = v560;
    int * v562 = v541->reg_ready;
    int v563 = v541->timer;
    v562[11] = v563;
    int * v565 = v541->reg_ready;
    int v566 = v541->timer;
    v565[12] = v566;
    struct StateT * v568 = slot_10(v541);
    v572 = v568;
  } else {
    struct StateT * v570 = slot_10(v541);
    v572 = v570;
  }
  return v572;
}

struct StateT * slot_4(struct StateT * v58) {
  int * v59 = v58->saved_regs;
  int * v60 = v58->regs;
  int v61 = v60[5];
  v59[5] = v61;
  int v63 = v58->timer;
  int v80 = v63 + 1;
  v58->timer = v80;
  int * v65 = v58->reg_ready;
  int v66 = v65[13];
  int * v67 = v58->regs;
  int v68 = v67[13];
  int v69 = v65[10];
  int v70 = v67[10];
  int v85 = (v69 + (((v66 + ((v63 - v66) & (~((v63 - v66) >> 31)))) - v69) & (~(((v66 + ((v63 - v66) & (~((v63 - v66) >> 31)))) - v69) >> 31)))) + 1;
  v65[5] = v85;
  int * v72 = v58->regs;
  int v87 = v68 + v70;
  v72[5] = v87;
  struct StateT * v74 = slot_5(v58);
  return v74;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->reg_ready;
  v5[13] = v11;
  int * v7 = v2->regs;
  v7[13] = 0;
  struct StateT * v9 = slot_1(v2);
  return v9;
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
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}