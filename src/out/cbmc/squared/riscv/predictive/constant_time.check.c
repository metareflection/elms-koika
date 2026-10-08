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

struct StateT2 {
  struct StateT * a;
  struct StateT * b;
};

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

void squared_assert(bool);
void squared_assume(bool);
void squared_diverged(bool);

struct StateT2 * slot_12(struct StateT2 * v1321);
struct StateT2 * slot_6(struct StateT2 * v206);
struct StateT2 * slot_25(struct StateT2 * v2810);
struct StateT2 * slot_23(struct StateT2 * v2693);
struct StateT2 * slot_5(struct StateT2 * v182);
struct StateT2 * slot_2(struct StateT2 * v74);
struct StateT2 * slot_7(struct StateT2 * v267);
struct StateT2 * slot_21(struct StateT2 * v2196);
struct StateT2 * slot_3(struct StateT2 * v110);
struct StateT2 * slot_10(struct StateT2 * v1200);
struct StateT2 * slot_1(struct StateT2 * v38);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * slot_14(struct StateT2 * v1535);
struct StateT2 * slot_20(struct StateT2 * v2135);
struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_4(struct StateT2 * v146);
struct StateT2 * slot_15(struct StateT2 * v1588);
struct StateT2 * slot_12(struct StateT2 * v1321) {
  struct StateT * v1322 = v1321->a;
  int v1323 = v1322->timer;
  struct StateT * v1324 = v1321->b;
  int v1325 = v1324->timer;
  bool v1356 = v1323 == v1325;
  squared_assert(v1356);
  squared_assume(v1356);
  struct StateT * v1328 = v1321->a;
  int * v1329 = v1328->saved_regs;
  int * v1330 = v1328->regs;
  int v1331 = v1330[14];
  v1329[14] = v1331;
  struct StateT * v1333 = v1321->b;
  int * v1334 = v1333->saved_regs;
  int * v1335 = v1333->regs;
  int v1336 = v1335[14];
  v1334[14] = v1336;
  struct StateT * v1338 = v1321->a;
  int v1339 = v1338->timer;
  int v1367 = v1339 + 1;
  v1338->timer = v1367;
  struct StateT * v1341 = v1321->b;
  int v1342 = v1341->timer;
  int v1369 = v1342 + 1;
  v1341->timer = v1369;
  struct StateT * v1344 = v1321->a;
  int * v1345 = v1344->regs;
  int v1346 = v1345[14];
  int v1372 = v1346 + 4;
  v1345[14] = v1372;
  struct StateT * v1348 = v1321->b;
  int * v1349 = v1348->regs;
  int v1350 = v1349[14];
  int v1375 = v1350 + 4;
  v1349[14] = v1375;
  struct StateT2 * v1352 = slot_25(v1321);
  return v1352;
}

struct StateT2 * slot_6(struct StateT2 * v206) {
  struct StateT * v207 = v206->a;
  int v208 = v207->timer;
  struct StateT * v209 = v206->b;
  int v210 = v209->timer;
  bool v243 = v208 == v210;
  squared_assert(v243);
  squared_assume(v243);
  struct StateT * v213 = v206->a;
  int * v214 = v213->saved_regs;
  int * v215 = v213->regs;
  int v216 = v215[6];
  v214[6] = v216;
  struct StateT * v218 = v206->b;
  int * v219 = v218->saved_regs;
  int * v220 = v218->regs;
  int v221 = v220[6];
  v219[6] = v221;
  struct StateT * v223 = v206->a;
  int v224 = v223->timer;
  int v254 = v224 + 1;
  v223->timer = v254;
  struct StateT * v226 = v206->b;
  int v227 = v226->timer;
  int v256 = v227 + 1;
  v226->timer = v256;
  struct StateT * v229 = v206->a;
  int * v230 = v229->regs;
  int v231 = v230[12];
  int v232 = v230[14];
  int v261 = v231 + v232;
  v230[6] = v261;
  struct StateT * v234 = v206->b;
  int * v235 = v234->regs;
  int v236 = v235[12];
  int v237 = v235[14];
  int v264 = v236 + v237;
  v235[6] = v264;
  struct StateT2 * v239 = slot_7(v206);
  return v239;
}

struct StateT2 * slot_25(struct StateT2 * v2810) {
  struct StateT * v2811 = v2810->a;
  int v2812 = v2811->timer;
  struct StateT * v2813 = v2810->b;
  int v2814 = v2813->timer;
  bool v2899 = v2812 == v2814;
  squared_assert(v2899);
  squared_assume(v2899);
  struct StateT * v2817 = v2810->a;
  int * v2818 = v2817->saved_regs;
  int v2819 = v2818[14];
  int * v2820 = v2817->regs;
  int v2821 = v2820[15];
  struct StateT * v2822 = v2810->b;
  int * v2823 = v2822->saved_regs;
  int v2824 = v2823[14];
  int * v2825 = v2822->regs;
  int v2826 = v2825[15];
  bool v2908 = (v2819 >= v2821) == (v2824 >= v2826);
  squared_diverged(v2908);
  squared_assume(v2908);
  bool v2909 = v2819 >= v2821;
  struct StateT2 * v2895;
  if (v2909) {
    struct StateT * v2829 = v2810->a;
    int v2830 = v2829->timer;
    int v2911 = v2830 + 15;
    v2829->timer = v2911;
    int * v2832 = v2829->saved_regs;
    int v2833 = v2832[6];
    int * v2834 = v2829->regs;
    v2834[6] = v2833;
    int * v2836 = v2829->saved_regs;
    int v2837 = v2836[7];
    int * v2838 = v2829->regs;
    v2838[7] = v2837;
    int * v2840 = v2829->saved_regs;
    int v2841 = v2840[8];
    int * v2842 = v2829->regs;
    v2842[8] = v2841;
    int * v2844 = v2829->saved_regs;
    int v2845 = v2844[9];
    int * v2846 = v2829->regs;
    v2846[9] = v2845;
    int * v2848 = v2829->saved_regs;
    int v2849 = v2848[16];
    int * v2850 = v2829->regs;
    v2850[16] = v2849;
    int * v2852 = v2829->saved_regs;
    int v2853 = v2852[5];
    int * v2854 = v2829->regs;
    v2854[5] = v2853;
    int * v2856 = v2829->saved_regs;
    int v2857 = v2856[14];
    int * v2858 = v2829->regs;
    v2858[14] = v2857;
    struct StateT * v2860 = v2810->b;
    int v2861 = v2860->timer;
    int v2940 = v2861 + 15;
    v2860->timer = v2940;
    int * v2863 = v2860->saved_regs;
    int v2864 = v2863[6];
    int * v2865 = v2860->regs;
    v2865[6] = v2864;
    int * v2867 = v2860->saved_regs;
    int v2868 = v2867[7];
    int * v2869 = v2860->regs;
    v2869[7] = v2868;
    int * v2871 = v2860->saved_regs;
    int v2872 = v2871[8];
    int * v2873 = v2860->regs;
    v2873[8] = v2872;
    int * v2875 = v2860->saved_regs;
    int v2876 = v2875[9];
    int * v2877 = v2860->regs;
    v2877[9] = v2876;
    int * v2879 = v2860->saved_regs;
    int v2880 = v2879[16];
    int * v2881 = v2860->regs;
    v2881[16] = v2880;
    int * v2883 = v2860->saved_regs;
    int v2884 = v2883[5];
    int * v2885 = v2860->regs;
    v2885[5] = v2884;
    int * v2887 = v2860->saved_regs;
    int v2888 = v2887[14];
    int * v2889 = v2860->regs;
    v2889[14] = v2888;
    struct StateT2 * v2891 = slot_14(v2810);
    v2895 = v2891;
  } else {
    struct StateT2 * v2893 = slot_15(v2810);
    v2895 = v2893;
  }
  return v2895;
}

struct StateT2 * slot_23(struct StateT2 * v2693) {
  struct StateT * v2694 = v2693->a;
  int v2695 = v2694->timer;
  struct StateT * v2696 = v2693->b;
  int v2697 = v2696->timer;
  bool v2730 = v2695 == v2697;
  squared_assert(v2730);
  squared_assume(v2730);
  struct StateT * v2700 = v2693->a;
  int * v2701 = v2700->saved_regs;
  int * v2702 = v2700->regs;
  int v2703 = v2702[5];
  v2701[5] = v2703;
  struct StateT * v2705 = v2693->b;
  int * v2706 = v2705->saved_regs;
  int * v2707 = v2705->regs;
  int v2708 = v2707[5];
  v2706[5] = v2708;
  struct StateT * v2710 = v2693->a;
  int v2711 = v2710->timer;
  int v2741 = v2711 + 1;
  v2710->timer = v2741;
  struct StateT * v2713 = v2693->b;
  int v2714 = v2713->timer;
  int v2743 = v2714 + 1;
  v2713->timer = v2743;
  struct StateT * v2716 = v2693->a;
  int * v2717 = v2716->regs;
  int v2718 = v2717[5];
  int v2719 = v2717[16];
  int v2747 = v2718 | v2719;
  v2717[5] = v2747;
  struct StateT * v2721 = v2693->b;
  int * v2722 = v2721->regs;
  int v2723 = v2722[5];
  int v2724 = v2722[16];
  int v2750 = v2723 | v2724;
  v2722[5] = v2750;
  struct StateT2 * v2726 = slot_12(v2693);
  return v2726;
}

struct StateT2 * slot_5(struct StateT2 * v182) {
  struct StateT * v183 = v182->a;
  int v184 = v183->timer;
  struct StateT * v185 = v182->b;
  int v186 = v185->timer;
  bool v199 = v184 == v186;
  squared_assert(v199);
  squared_assume(v199);
  struct StateT * v189 = v182->a;
  int v190 = v189->timer;
  int v201 = v190 + 1;
  v189->timer = v201;
  struct StateT * v192 = v182->b;
  int v193 = v192->timer;
  int v203 = v193 + 1;
  v192->timer = v203;
  struct StateT2 * v195 = slot_6(v182);
  return v195;
}

struct StateT2 * slot_2(struct StateT2 * v74) {
  struct StateT * v75 = v74->a;
  int v76 = v75->timer;
  struct StateT * v77 = v74->b;
  int v78 = v77->timer;
  bool v97 = v76 == v78;
  squared_assert(v97);
  squared_assume(v97);
  struct StateT * v81 = v74->a;
  int v82 = v81->timer;
  int v99 = v82 + 1;
  v81->timer = v99;
  struct StateT * v84 = v74->b;
  int v85 = v84->timer;
  int v101 = v85 + 1;
  v84->timer = v101;
  struct StateT * v87 = v74->a;
  int * v88 = v87->regs;
  v88[14] = 0;
  struct StateT * v90 = v74->b;
  int * v91 = v90->regs;
  v91[14] = 0;
  struct StateT2 * v93 = slot_3(v74);
  return v93;
}

struct StateT2 * slot_7(struct StateT2 * v267) {
  struct StateT * v268 = v267->a;
  int v269 = v268->timer;
  struct StateT * v270 = v267->b;
  int v271 = v270->timer;
  bool v508 = v269 == v271;
  squared_assert(v508);
  squared_assume(v508);
  struct StateT * v274 = v267->a;
  int * v275 = v274->saved_regs;
  int * v276 = v274->regs;
  int v277 = v276[7];
  v275[7] = v277;
  struct StateT * v279 = v267->b;
  int * v280 = v279->saved_regs;
  int * v281 = v279->regs;
  int v282 = v281[7];
  v280[7] = v282;
  struct StateT * v284 = v267->a;
  int v285 = v284->timer;
  int v519 = v285 + 1;
  v284->timer = v519;
  struct StateT * v287 = v267->b;
  int v288 = v287->timer;
  int v521 = v288 + 1;
  v287->timer = v521;
  struct StateT * v290 = v267->a;
  int * v291 = v290->regs;
  int v292 = v291[6];
  int * v293 = v290->cache_tags;
  int v526 = (((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1)) & 1) * 2;
  int v294 = v293[v526];
  int v527 = ((((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1)) & 1) * 2) + 1;
  int v295 = v293[v527];
  int v528 = 4 + ((((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1)) & 3) * 2);
  int v296 = v293[v528];
  int v529 = (4 + ((((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v297 = v293[v529];
  int v298 = v290->timer;
  int v530 = v298 + ((100 ^ (((~(((v296 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))) | (-(v296 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))))) >> 31)) | (~(((v297 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))) | (-(v297 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v294 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))) | (-(v294 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))))) >> 31)) | (~(((v295 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))) | (-(v295 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v296 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))) | (-(v296 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))))) >> 31)) | (~(((v297 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))) | (-(v297 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))))) >> 31))) & 104)))));
  v290->timer = v530;
  int * v300 = v290->cache_vals;
  bool v531 = !(((~(((v294 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))) | (-(v294 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))))) >> 31)) | (~(((v295 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))) | (-(v295 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))))) >> 31))) == 0);
  int v393;
  if (v531) {
    int * v301 = v290->cache_age;
    int v533 = ((((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1)) & 1) * 2) + ((~(((v295 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))) | (-(v295 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))))) >> 31)) & 1);
    int v302 = v301[v533];
    int v303 = v301[v526];
    int v534 = v303 + ((int)((unsigned int)(v303 - v302) >> 31));
    v301[v526] = v534;
    int * v305 = v290->cache_age;
    int v306 = v305[v527];
    int v536 = v306 + ((int)((unsigned int)(v306 - v302) >> 31));
    v305[v527] = v536;
    int * v308 = v290->cache_age;
    v308[v533] = 0;
    v393 = v533;
  } else {
    int * v311 = v290->cache_age;
    int v540 = (((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1)) & 1) * 2;
    int v312 = v311[v540];
    int * v313 = v290->cache_tags;
    int v314 = v313[v540];
    int v315 = v311[v527];
    int v316 = v313[v527];
    bool v542 = !(((~(((v296 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))) | (-(v296 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))))) >> 31)) | (~(((v297 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))) | (-(v297 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))))) >> 31))) == 0);
    int v370;
    if (v542) {
      int * v317 = v290->cache_age;
      int v544 = (4 + ((((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1)) & 3) * 2)) + ((~(((v297 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))) | (-(v297 ^ ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1))))) >> 31)) & 1);
      int v318 = v317[v544];
      int v319 = v317[v528];
      int v545 = v319 + ((int)((unsigned int)(v319 - v318) >> 31));
      v317[v528] = v545;
      int * v321 = v290->cache_age;
      int v322 = v321[v529];
      int v547 = v322 + ((int)((unsigned int)(v322 - v318) >> 31));
      v321[v529] = v547;
      int * v324 = v290->cache_age;
      v324[v544] = 0;
      v370 = v544;
    } else {
      int * v327 = v290->cache_age;
      int v551 = 4 + ((((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1)) & 3) * 2);
      int v328 = v327[v551];
      int * v329 = v290->cache_tags;
      int v330 = v329[v551];
      int v331 = v327[v529];
      int v332 = v329[v529];
      int * v333 = v290->cache_dirty;
      int v554 = (4 + ((((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1)) & 3) * 2)) + ((((v328 + ((~(((v330 ^ -1) | (-(v330 ^ -1))) >> 31)) & 2)) - (v331 + ((~(((v332 ^ -1) | (-(v332 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v334 = v333[v554];
      bool v555 = !(v334 == 0);
      if (v555) {
        int * v335 = v290->cache_tags;
        int v336 = v335[v554];
        int * v337 = v290->cache_vals;
        int v558 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1)) & 3) * 2)) + ((((v328 + ((~(((v330 ^ -1) | (-(v330 ^ -1))) >> 31)) & 2)) - (v331 + ((~(((v332 ^ -1) | (-(v332 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v338 = v337[v558];
        int v559 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1)) & 3) * 2)) + ((((v328 + ((~(((v330 ^ -1) | (-(v330 ^ -1))) >> 31)) & 2)) - (v331 + ((~(((v332 ^ -1) | (-(v332 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v339 = v337[v559];
        int * v340 = v290->mem;
        int v561 = v336 * 2;
        v340[v561] = v338;
        int * v342 = v290->mem;
        int v564 = (v336 * 2) + 1;
        v342[v564] = v339;
        ;
      } else {
        ;
      }
      int * v347 = v290->mem;
      int v569 = ((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1)) * 2;
      int v348 = v347[v569];
      int v570 = (((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1)) * 2) + 1;
      int v349 = v347[v570];
      int * v350 = v290->cache_vals;
      int v572 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1)) & 3) * 2)) + ((((v328 + ((~(((v330 ^ -1) | (-(v330 ^ -1))) >> 31)) & 2)) - (v331 + ((~(((v332 ^ -1) | (-(v332 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v350[v572] = v348;
      int * v352 = v290->cache_vals;
      int v575 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1)) & 3) * 2)) + ((((v328 + ((~(((v330 ^ -1) | (-(v330 ^ -1))) >> 31)) & 2)) - (v331 + ((~(((v332 ^ -1) | (-(v332 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v352[v575] = v349;
      int * v354 = v290->cache_tags;
      int v578 = (int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1);
      v354[v554] = v578;
      int * v356 = v290->cache_dirty;
      v356[v554] = 0;
      int * v358 = v290->cache_age;
      v358[v554] = 1;
      int * v360 = v290->cache_age;
      int v361 = v360[v554];
      int v362 = v360[v528];
      int v584 = v362 + ((int)((unsigned int)(v362 - v361) >> 31));
      v360[v528] = v584;
      int * v364 = v290->cache_age;
      int v365 = v364[v529];
      int v586 = v365 + ((int)((unsigned int)(v365 - v361) >> 31));
      v364[v529] = v586;
      int * v367 = v290->cache_age;
      v367[v554] = 0;
      v370 = v554;
    }
    int * v371 = v290->cache_vals;
    int v589 = v370 * 2;
    int v372 = v371[v589];
    int v590 = (v370 * 2) + 1;
    int v373 = v371[v590];
    int v591 = (((((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1)) & 1) * 2) + ((((v312 + ((~(((v314 ^ -1) | (-(v314 ^ -1))) >> 31)) & 2)) - (v315 + ((~(((v316 ^ -1) | (-(v316 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v371[v591] = v372;
    int * v375 = v290->cache_vals;
    int v594 = ((((((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1)) & 1) * 2) + ((((v312 + ((~(((v314 ^ -1) | (-(v314 ^ -1))) >> 31)) & 2)) - (v315 + ((~(((v316 ^ -1) | (-(v316 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v375[v594] = v373;
    int * v377 = v290->cache_tags;
    int v597 = ((((int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1)) & 1) * 2) + ((((v312 + ((~(((v314 ^ -1) | (-(v314 ^ -1))) >> 31)) & 2)) - (v315 + ((~(((v316 ^ -1) | (-(v316 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v598 = (int)((unsigned int)((int)((unsigned int)v292 >> 2)) >> 1);
    v377[v597] = v598;
    int * v379 = v290->cache_dirty;
    v379[v597] = 0;
    int * v381 = v290->cache_age;
    v381[v597] = 1;
    int * v383 = v290->cache_age;
    int v384 = v383[v597];
    int v385 = v383[v526];
    int v604 = v385 + ((int)((unsigned int)(v385 - v384) >> 31));
    v383[v526] = v604;
    int * v387 = v290->cache_age;
    int v388 = v387[v527];
    int v606 = v388 + ((int)((unsigned int)(v388 - v384) >> 31));
    v387[v527] = v606;
    int * v390 = v290->cache_age;
    v390[v597] = 0;
    v393 = v597;
  }
  int v609 = (v393 * 2) + (((int)((unsigned int)v292 >> 2)) & 1);
  int v394 = v300[v609];
  int * v395 = v290->regs;
  v395[7] = v394;
  struct StateT * v397 = v267->b;
  int * v398 = v397->regs;
  int v399 = v398[6];
  int * v400 = v397->cache_tags;
  int v615 = (((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 1) * 2;
  int v401 = v400[v615];
  int v616 = ((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 1) * 2) + 1;
  int v402 = v400[v616];
  int v617 = 4 + ((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 3) * 2);
  int v403 = v400[v617];
  int v618 = (4 + ((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v404 = v400[v618];
  int v405 = v397->timer;
  int v619 = v405 + ((100 ^ (((~(((v403 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))) | (-(v403 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))))) >> 31)) | (~(((v404 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))) | (-(v404 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v401 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))) | (-(v401 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))))) >> 31)) | (~(((v402 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))) | (-(v402 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v403 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))) | (-(v403 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))))) >> 31)) | (~(((v404 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))) | (-(v404 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))))) >> 31))) & 104)))));
  v397->timer = v619;
  int * v407 = v397->cache_vals;
  bool v620 = !(((~(((v401 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))) | (-(v401 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))))) >> 31)) | (~(((v402 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))) | (-(v402 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))))) >> 31))) == 0);
  int v500;
  if (v620) {
    int * v408 = v397->cache_age;
    int v622 = ((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 1) * 2) + ((~(((v402 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))) | (-(v402 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))))) >> 31)) & 1);
    int v409 = v408[v622];
    int v410 = v408[v615];
    int v623 = v410 + ((int)((unsigned int)(v410 - v409) >> 31));
    v408[v615] = v623;
    int * v412 = v397->cache_age;
    int v413 = v412[v616];
    int v625 = v413 + ((int)((unsigned int)(v413 - v409) >> 31));
    v412[v616] = v625;
    int * v415 = v397->cache_age;
    v415[v622] = 0;
    v500 = v622;
  } else {
    int * v418 = v397->cache_age;
    int v629 = (((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 1) * 2;
    int v419 = v418[v629];
    int * v420 = v397->cache_tags;
    int v421 = v420[v629];
    int v422 = v418[v616];
    int v423 = v420[v616];
    bool v631 = !(((~(((v403 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))) | (-(v403 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))))) >> 31)) | (~(((v404 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))) | (-(v404 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))))) >> 31))) == 0);
    int v477;
    if (v631) {
      int * v424 = v397->cache_age;
      int v633 = (4 + ((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 3) * 2)) + ((~(((v404 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))) | (-(v404 ^ ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1))))) >> 31)) & 1);
      int v425 = v424[v633];
      int v426 = v424[v617];
      int v634 = v426 + ((int)((unsigned int)(v426 - v425) >> 31));
      v424[v617] = v634;
      int * v428 = v397->cache_age;
      int v429 = v428[v618];
      int v636 = v429 + ((int)((unsigned int)(v429 - v425) >> 31));
      v428[v618] = v636;
      int * v431 = v397->cache_age;
      v431[v633] = 0;
      v477 = v633;
    } else {
      int * v434 = v397->cache_age;
      int v640 = 4 + ((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 3) * 2);
      int v435 = v434[v640];
      int * v436 = v397->cache_tags;
      int v437 = v436[v640];
      int v438 = v434[v618];
      int v439 = v436[v618];
      int * v440 = v397->cache_dirty;
      int v643 = (4 + ((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 3) * 2)) + ((((v435 + ((~(((v437 ^ -1) | (-(v437 ^ -1))) >> 31)) & 2)) - (v438 + ((~(((v439 ^ -1) | (-(v439 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v441 = v440[v643];
      bool v644 = !(v441 == 0);
      if (v644) {
        int * v442 = v397->cache_tags;
        int v443 = v442[v643];
        int * v444 = v397->cache_vals;
        int v647 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 3) * 2)) + ((((v435 + ((~(((v437 ^ -1) | (-(v437 ^ -1))) >> 31)) & 2)) - (v438 + ((~(((v439 ^ -1) | (-(v439 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v445 = v444[v647];
        int v648 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 3) * 2)) + ((((v435 + ((~(((v437 ^ -1) | (-(v437 ^ -1))) >> 31)) & 2)) - (v438 + ((~(((v439 ^ -1) | (-(v439 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v446 = v444[v648];
        int * v447 = v397->mem;
        int v650 = v443 * 2;
        v447[v650] = v445;
        int * v449 = v397->mem;
        int v653 = (v443 * 2) + 1;
        v449[v653] = v446;
        ;
      } else {
        ;
      }
      int * v454 = v397->mem;
      int v658 = ((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) * 2;
      int v455 = v454[v658];
      int v659 = (((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) * 2) + 1;
      int v456 = v454[v659];
      int * v457 = v397->cache_vals;
      int v661 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 3) * 2)) + ((((v435 + ((~(((v437 ^ -1) | (-(v437 ^ -1))) >> 31)) & 2)) - (v438 + ((~(((v439 ^ -1) | (-(v439 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v457[v661] = v455;
      int * v459 = v397->cache_vals;
      int v664 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 3) * 2)) + ((((v435 + ((~(((v437 ^ -1) | (-(v437 ^ -1))) >> 31)) & 2)) - (v438 + ((~(((v439 ^ -1) | (-(v439 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v459[v664] = v456;
      int * v461 = v397->cache_tags;
      int v667 = (int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1);
      v461[v643] = v667;
      int * v463 = v397->cache_dirty;
      v463[v643] = 0;
      int * v465 = v397->cache_age;
      v465[v643] = 1;
      int * v467 = v397->cache_age;
      int v468 = v467[v643];
      int v469 = v467[v617];
      int v673 = v469 + ((int)((unsigned int)(v469 - v468) >> 31));
      v467[v617] = v673;
      int * v471 = v397->cache_age;
      int v472 = v471[v618];
      int v675 = v472 + ((int)((unsigned int)(v472 - v468) >> 31));
      v471[v618] = v675;
      int * v474 = v397->cache_age;
      v474[v643] = 0;
      v477 = v643;
    }
    int * v478 = v397->cache_vals;
    int v678 = v477 * 2;
    int v479 = v478[v678];
    int v679 = (v477 * 2) + 1;
    int v480 = v478[v679];
    int v680 = (((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 1) * 2) + ((((v419 + ((~(((v421 ^ -1) | (-(v421 ^ -1))) >> 31)) & 2)) - (v422 + ((~(((v423 ^ -1) | (-(v423 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v478[v680] = v479;
    int * v482 = v397->cache_vals;
    int v683 = ((((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 1) * 2) + ((((v419 + ((~(((v421 ^ -1) | (-(v421 ^ -1))) >> 31)) & 2)) - (v422 + ((~(((v423 ^ -1) | (-(v423 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v482[v683] = v480;
    int * v484 = v397->cache_tags;
    int v686 = ((((int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1)) & 1) * 2) + ((((v419 + ((~(((v421 ^ -1) | (-(v421 ^ -1))) >> 31)) & 2)) - (v422 + ((~(((v423 ^ -1) | (-(v423 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v687 = (int)((unsigned int)((int)((unsigned int)v399 >> 2)) >> 1);
    v484[v686] = v687;
    int * v486 = v397->cache_dirty;
    v486[v686] = 0;
    int * v488 = v397->cache_age;
    v488[v686] = 1;
    int * v490 = v397->cache_age;
    int v491 = v490[v686];
    int v492 = v490[v615];
    int v693 = v492 + ((int)((unsigned int)(v492 - v491) >> 31));
    v490[v615] = v693;
    int * v494 = v397->cache_age;
    int v495 = v494[v616];
    int v695 = v495 + ((int)((unsigned int)(v495 - v491) >> 31));
    v494[v616] = v695;
    int * v497 = v397->cache_age;
    v497[v686] = 0;
    v500 = v686;
  }
  int v698 = (v500 * 2) + (((int)((unsigned int)v399 >> 2)) & 1);
  int v501 = v407[v698];
  int * v502 = v397->regs;
  v502[7] = v501;
  struct StateT2 * v504 = slot_20(v267);
  return v504;
}

struct StateT2 * slot_21(struct StateT2 * v2196) {
  struct StateT * v2197 = v2196->a;
  int v2198 = v2197->timer;
  struct StateT * v2199 = v2196->b;
  int v2200 = v2199->timer;
  bool v2437 = v2198 == v2200;
  squared_assert(v2437);
  squared_assume(v2437);
  struct StateT * v2203 = v2196->a;
  int * v2204 = v2203->saved_regs;
  int * v2205 = v2203->regs;
  int v2206 = v2205[9];
  v2204[9] = v2206;
  struct StateT * v2208 = v2196->b;
  int * v2209 = v2208->saved_regs;
  int * v2210 = v2208->regs;
  int v2211 = v2210[9];
  v2209[9] = v2211;
  struct StateT * v2213 = v2196->a;
  int v2214 = v2213->timer;
  int v2448 = v2214 + 1;
  v2213->timer = v2448;
  struct StateT * v2216 = v2196->b;
  int v2217 = v2216->timer;
  int v2450 = v2217 + 1;
  v2216->timer = v2450;
  struct StateT * v2219 = v2196->a;
  int * v2220 = v2219->regs;
  int v2221 = v2220[8];
  int * v2222 = v2219->cache_tags;
  int v2455 = (((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1)) & 1) * 2;
  int v2223 = v2222[v2455];
  int v2456 = ((((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1)) & 1) * 2) + 1;
  int v2224 = v2222[v2456];
  int v2457 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1)) & 3) * 2);
  int v2225 = v2222[v2457];
  int v2458 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2226 = v2222[v2458];
  int v2227 = v2219->timer;
  int v2459 = v2227 + ((100 ^ (((~(((v2225 ^ ((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1))) | (-(v2225 ^ ((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1))))) >> 31)) | (~(((v2226 ^ ((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1))) | (-(v2226 ^ ((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2223 ^ ((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1))) | (-(v2223 ^ ((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1))))) >> 31)) | (~(((v2224 ^ ((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1))) | (-(v2224 ^ ((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2225 ^ ((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1))) | (-(v2225 ^ ((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1))))) >> 31)) | (~(((v2226 ^ ((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1))) | (-(v2226 ^ ((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2219->timer = v2459;
  int * v2229 = v2219->cache_vals;
  bool v2460 = !(((~(((v2223 ^ ((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1))) | (-(v2223 ^ ((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1))))) >> 31)) | (~(((v2224 ^ ((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1))) | (-(v2224 ^ ((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1))))) >> 31))) == 0);
  int v2322;
  if (v2460) {
    int * v2230 = v2219->cache_age;
    int v2462 = ((((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1)) & 1) * 2) + ((~(((v2224 ^ ((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1))) | (-(v2224 ^ ((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1))))) >> 31)) & 1);
    int v2231 = v2230[v2462];
    int v2232 = v2230[v2455];
    int v2463 = v2232 + ((int)((unsigned int)(v2232 - v2231) >> 31));
    v2230[v2455] = v2463;
    int * v2234 = v2219->cache_age;
    int v2235 = v2234[v2456];
    int v2465 = v2235 + ((int)((unsigned int)(v2235 - v2231) >> 31));
    v2234[v2456] = v2465;
    int * v2237 = v2219->cache_age;
    v2237[v2462] = 0;
    v2322 = v2462;
  } else {
    int * v2240 = v2219->cache_age;
    int v2469 = (((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1)) & 1) * 2;
    int v2241 = v2240[v2469];
    int * v2242 = v2219->cache_tags;
    int v2243 = v2242[v2469];
    int v2244 = v2240[v2456];
    int v2245 = v2242[v2456];
    bool v2471 = !(((~(((v2225 ^ ((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1))) | (-(v2225 ^ ((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1))))) >> 31)) | (~(((v2226 ^ ((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1))) | (-(v2226 ^ ((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1))))) >> 31))) == 0);
    int v2299;
    if (v2471) {
      int * v2246 = v2219->cache_age;
      int v2473 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2226 ^ ((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1))) | (-(v2226 ^ ((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1))))) >> 31)) & 1);
      int v2247 = v2246[v2473];
      int v2248 = v2246[v2457];
      int v2474 = v2248 + ((int)((unsigned int)(v2248 - v2247) >> 31));
      v2246[v2457] = v2474;
      int * v2250 = v2219->cache_age;
      int v2251 = v2250[v2458];
      int v2476 = v2251 + ((int)((unsigned int)(v2251 - v2247) >> 31));
      v2250[v2458] = v2476;
      int * v2253 = v2219->cache_age;
      v2253[v2473] = 0;
      v2299 = v2473;
    } else {
      int * v2256 = v2219->cache_age;
      int v2480 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1)) & 3) * 2);
      int v2257 = v2256[v2480];
      int * v2258 = v2219->cache_tags;
      int v2259 = v2258[v2480];
      int v2260 = v2256[v2458];
      int v2261 = v2258[v2458];
      int * v2262 = v2219->cache_dirty;
      int v2483 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1)) & 3) * 2)) + ((((v2257 + ((~(((v2259 ^ -1) | (-(v2259 ^ -1))) >> 31)) & 2)) - (v2260 + ((~(((v2261 ^ -1) | (-(v2261 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2263 = v2262[v2483];
      bool v2484 = !(v2263 == 0);
      if (v2484) {
        int * v2264 = v2219->cache_tags;
        int v2265 = v2264[v2483];
        int * v2266 = v2219->cache_vals;
        int v2487 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1)) & 3) * 2)) + ((((v2257 + ((~(((v2259 ^ -1) | (-(v2259 ^ -1))) >> 31)) & 2)) - (v2260 + ((~(((v2261 ^ -1) | (-(v2261 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2267 = v2266[v2487];
        int v2488 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1)) & 3) * 2)) + ((((v2257 + ((~(((v2259 ^ -1) | (-(v2259 ^ -1))) >> 31)) & 2)) - (v2260 + ((~(((v2261 ^ -1) | (-(v2261 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2268 = v2266[v2488];
        int * v2269 = v2219->mem;
        int v2490 = v2265 * 2;
        v2269[v2490] = v2267;
        int * v2271 = v2219->mem;
        int v2493 = (v2265 * 2) + 1;
        v2271[v2493] = v2268;
        ;
      } else {
        ;
      }
      int * v2276 = v2219->mem;
      int v2498 = ((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1)) * 2;
      int v2277 = v2276[v2498];
      int v2499 = (((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1)) * 2) + 1;
      int v2278 = v2276[v2499];
      int * v2279 = v2219->cache_vals;
      int v2501 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1)) & 3) * 2)) + ((((v2257 + ((~(((v2259 ^ -1) | (-(v2259 ^ -1))) >> 31)) & 2)) - (v2260 + ((~(((v2261 ^ -1) | (-(v2261 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2279[v2501] = v2277;
      int * v2281 = v2219->cache_vals;
      int v2504 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1)) & 3) * 2)) + ((((v2257 + ((~(((v2259 ^ -1) | (-(v2259 ^ -1))) >> 31)) & 2)) - (v2260 + ((~(((v2261 ^ -1) | (-(v2261 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2281[v2504] = v2278;
      int * v2283 = v2219->cache_tags;
      int v2507 = (int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1);
      v2283[v2483] = v2507;
      int * v2285 = v2219->cache_dirty;
      v2285[v2483] = 0;
      int * v2287 = v2219->cache_age;
      v2287[v2483] = 1;
      int * v2289 = v2219->cache_age;
      int v2290 = v2289[v2483];
      int v2291 = v2289[v2457];
      int v2513 = v2291 + ((int)((unsigned int)(v2291 - v2290) >> 31));
      v2289[v2457] = v2513;
      int * v2293 = v2219->cache_age;
      int v2294 = v2293[v2458];
      int v2515 = v2294 + ((int)((unsigned int)(v2294 - v2290) >> 31));
      v2293[v2458] = v2515;
      int * v2296 = v2219->cache_age;
      v2296[v2483] = 0;
      v2299 = v2483;
    }
    int * v2300 = v2219->cache_vals;
    int v2518 = v2299 * 2;
    int v2301 = v2300[v2518];
    int v2519 = (v2299 * 2) + 1;
    int v2302 = v2300[v2519];
    int v2520 = (((((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1)) & 1) * 2) + ((((v2241 + ((~(((v2243 ^ -1) | (-(v2243 ^ -1))) >> 31)) & 2)) - (v2244 + ((~(((v2245 ^ -1) | (-(v2245 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2300[v2520] = v2301;
    int * v2304 = v2219->cache_vals;
    int v2523 = ((((((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1)) & 1) * 2) + ((((v2241 + ((~(((v2243 ^ -1) | (-(v2243 ^ -1))) >> 31)) & 2)) - (v2244 + ((~(((v2245 ^ -1) | (-(v2245 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2304[v2523] = v2302;
    int * v2306 = v2219->cache_tags;
    int v2526 = ((((int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1)) & 1) * 2) + ((((v2241 + ((~(((v2243 ^ -1) | (-(v2243 ^ -1))) >> 31)) & 2)) - (v2244 + ((~(((v2245 ^ -1) | (-(v2245 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2527 = (int)((unsigned int)((int)((unsigned int)v2221 >> 2)) >> 1);
    v2306[v2526] = v2527;
    int * v2308 = v2219->cache_dirty;
    v2308[v2526] = 0;
    int * v2310 = v2219->cache_age;
    v2310[v2526] = 1;
    int * v2312 = v2219->cache_age;
    int v2313 = v2312[v2526];
    int v2314 = v2312[v2455];
    int v2533 = v2314 + ((int)((unsigned int)(v2314 - v2313) >> 31));
    v2312[v2455] = v2533;
    int * v2316 = v2219->cache_age;
    int v2317 = v2316[v2456];
    int v2535 = v2317 + ((int)((unsigned int)(v2317 - v2313) >> 31));
    v2316[v2456] = v2535;
    int * v2319 = v2219->cache_age;
    v2319[v2526] = 0;
    v2322 = v2526;
  }
  int v2538 = (v2322 * 2) + (((int)((unsigned int)v2221 >> 2)) & 1);
  int v2323 = v2229[v2538];
  int * v2324 = v2219->regs;
  v2324[9] = v2323;
  struct StateT * v2326 = v2196->b;
  int * v2327 = v2326->regs;
  int v2328 = v2327[8];
  int * v2329 = v2326->cache_tags;
  int v2544 = (((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1)) & 1) * 2;
  int v2330 = v2329[v2544];
  int v2545 = ((((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1)) & 1) * 2) + 1;
  int v2331 = v2329[v2545];
  int v2546 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1)) & 3) * 2);
  int v2332 = v2329[v2546];
  int v2547 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2333 = v2329[v2547];
  int v2334 = v2326->timer;
  int v2548 = v2334 + ((100 ^ (((~(((v2332 ^ ((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1))) | (-(v2332 ^ ((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1))))) >> 31)) | (~(((v2333 ^ ((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1))) | (-(v2333 ^ ((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2330 ^ ((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1))) | (-(v2330 ^ ((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1))))) >> 31)) | (~(((v2331 ^ ((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1))) | (-(v2331 ^ ((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2332 ^ ((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1))) | (-(v2332 ^ ((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1))))) >> 31)) | (~(((v2333 ^ ((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1))) | (-(v2333 ^ ((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2326->timer = v2548;
  int * v2336 = v2326->cache_vals;
  bool v2549 = !(((~(((v2330 ^ ((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1))) | (-(v2330 ^ ((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1))))) >> 31)) | (~(((v2331 ^ ((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1))) | (-(v2331 ^ ((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1))))) >> 31))) == 0);
  int v2429;
  if (v2549) {
    int * v2337 = v2326->cache_age;
    int v2551 = ((((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1)) & 1) * 2) + ((~(((v2331 ^ ((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1))) | (-(v2331 ^ ((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1))))) >> 31)) & 1);
    int v2338 = v2337[v2551];
    int v2339 = v2337[v2544];
    int v2552 = v2339 + ((int)((unsigned int)(v2339 - v2338) >> 31));
    v2337[v2544] = v2552;
    int * v2341 = v2326->cache_age;
    int v2342 = v2341[v2545];
    int v2554 = v2342 + ((int)((unsigned int)(v2342 - v2338) >> 31));
    v2341[v2545] = v2554;
    int * v2344 = v2326->cache_age;
    v2344[v2551] = 0;
    v2429 = v2551;
  } else {
    int * v2347 = v2326->cache_age;
    int v2558 = (((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1)) & 1) * 2;
    int v2348 = v2347[v2558];
    int * v2349 = v2326->cache_tags;
    int v2350 = v2349[v2558];
    int v2351 = v2347[v2545];
    int v2352 = v2349[v2545];
    bool v2560 = !(((~(((v2332 ^ ((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1))) | (-(v2332 ^ ((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1))))) >> 31)) | (~(((v2333 ^ ((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1))) | (-(v2333 ^ ((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1))))) >> 31))) == 0);
    int v2406;
    if (v2560) {
      int * v2353 = v2326->cache_age;
      int v2562 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2333 ^ ((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1))) | (-(v2333 ^ ((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1))))) >> 31)) & 1);
      int v2354 = v2353[v2562];
      int v2355 = v2353[v2546];
      int v2563 = v2355 + ((int)((unsigned int)(v2355 - v2354) >> 31));
      v2353[v2546] = v2563;
      int * v2357 = v2326->cache_age;
      int v2358 = v2357[v2547];
      int v2565 = v2358 + ((int)((unsigned int)(v2358 - v2354) >> 31));
      v2357[v2547] = v2565;
      int * v2360 = v2326->cache_age;
      v2360[v2562] = 0;
      v2406 = v2562;
    } else {
      int * v2363 = v2326->cache_age;
      int v2569 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1)) & 3) * 2);
      int v2364 = v2363[v2569];
      int * v2365 = v2326->cache_tags;
      int v2366 = v2365[v2569];
      int v2367 = v2363[v2547];
      int v2368 = v2365[v2547];
      int * v2369 = v2326->cache_dirty;
      int v2572 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1)) & 3) * 2)) + ((((v2364 + ((~(((v2366 ^ -1) | (-(v2366 ^ -1))) >> 31)) & 2)) - (v2367 + ((~(((v2368 ^ -1) | (-(v2368 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2370 = v2369[v2572];
      bool v2573 = !(v2370 == 0);
      if (v2573) {
        int * v2371 = v2326->cache_tags;
        int v2372 = v2371[v2572];
        int * v2373 = v2326->cache_vals;
        int v2576 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1)) & 3) * 2)) + ((((v2364 + ((~(((v2366 ^ -1) | (-(v2366 ^ -1))) >> 31)) & 2)) - (v2367 + ((~(((v2368 ^ -1) | (-(v2368 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2374 = v2373[v2576];
        int v2577 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1)) & 3) * 2)) + ((((v2364 + ((~(((v2366 ^ -1) | (-(v2366 ^ -1))) >> 31)) & 2)) - (v2367 + ((~(((v2368 ^ -1) | (-(v2368 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2375 = v2373[v2577];
        int * v2376 = v2326->mem;
        int v2579 = v2372 * 2;
        v2376[v2579] = v2374;
        int * v2378 = v2326->mem;
        int v2582 = (v2372 * 2) + 1;
        v2378[v2582] = v2375;
        ;
      } else {
        ;
      }
      int * v2383 = v2326->mem;
      int v2587 = ((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1)) * 2;
      int v2384 = v2383[v2587];
      int v2588 = (((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1)) * 2) + 1;
      int v2385 = v2383[v2588];
      int * v2386 = v2326->cache_vals;
      int v2590 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1)) & 3) * 2)) + ((((v2364 + ((~(((v2366 ^ -1) | (-(v2366 ^ -1))) >> 31)) & 2)) - (v2367 + ((~(((v2368 ^ -1) | (-(v2368 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2386[v2590] = v2384;
      int * v2388 = v2326->cache_vals;
      int v2593 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1)) & 3) * 2)) + ((((v2364 + ((~(((v2366 ^ -1) | (-(v2366 ^ -1))) >> 31)) & 2)) - (v2367 + ((~(((v2368 ^ -1) | (-(v2368 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2388[v2593] = v2385;
      int * v2390 = v2326->cache_tags;
      int v2596 = (int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1);
      v2390[v2572] = v2596;
      int * v2392 = v2326->cache_dirty;
      v2392[v2572] = 0;
      int * v2394 = v2326->cache_age;
      v2394[v2572] = 1;
      int * v2396 = v2326->cache_age;
      int v2397 = v2396[v2572];
      int v2398 = v2396[v2546];
      int v2602 = v2398 + ((int)((unsigned int)(v2398 - v2397) >> 31));
      v2396[v2546] = v2602;
      int * v2400 = v2326->cache_age;
      int v2401 = v2400[v2547];
      int v2604 = v2401 + ((int)((unsigned int)(v2401 - v2397) >> 31));
      v2400[v2547] = v2604;
      int * v2403 = v2326->cache_age;
      v2403[v2572] = 0;
      v2406 = v2572;
    }
    int * v2407 = v2326->cache_vals;
    int v2607 = v2406 * 2;
    int v2408 = v2407[v2607];
    int v2608 = (v2406 * 2) + 1;
    int v2409 = v2407[v2608];
    int v2609 = (((((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1)) & 1) * 2) + ((((v2348 + ((~(((v2350 ^ -1) | (-(v2350 ^ -1))) >> 31)) & 2)) - (v2351 + ((~(((v2352 ^ -1) | (-(v2352 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2407[v2609] = v2408;
    int * v2411 = v2326->cache_vals;
    int v2612 = ((((((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1)) & 1) * 2) + ((((v2348 + ((~(((v2350 ^ -1) | (-(v2350 ^ -1))) >> 31)) & 2)) - (v2351 + ((~(((v2352 ^ -1) | (-(v2352 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2411[v2612] = v2409;
    int * v2413 = v2326->cache_tags;
    int v2615 = ((((int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1)) & 1) * 2) + ((((v2348 + ((~(((v2350 ^ -1) | (-(v2350 ^ -1))) >> 31)) & 2)) - (v2351 + ((~(((v2352 ^ -1) | (-(v2352 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2616 = (int)((unsigned int)((int)((unsigned int)v2328 >> 2)) >> 1);
    v2413[v2615] = v2616;
    int * v2415 = v2326->cache_dirty;
    v2415[v2615] = 0;
    int * v2417 = v2326->cache_age;
    v2417[v2615] = 1;
    int * v2419 = v2326->cache_age;
    int v2420 = v2419[v2615];
    int v2421 = v2419[v2544];
    int v2622 = v2421 + ((int)((unsigned int)(v2421 - v2420) >> 31));
    v2419[v2544] = v2622;
    int * v2423 = v2326->cache_age;
    int v2424 = v2423[v2545];
    int v2624 = v2424 + ((int)((unsigned int)(v2424 - v2420) >> 31));
    v2423[v2545] = v2624;
    int * v2426 = v2326->cache_age;
    v2426[v2615] = 0;
    v2429 = v2615;
  }
  int v2627 = (v2429 * 2) + (((int)((unsigned int)v2328 >> 2)) & 1);
  int v2430 = v2336[v2627];
  int * v2431 = v2326->regs;
  v2431[9] = v2430;
  struct StateT2 * v2433 = slot_10(v2196);
  return v2433;
}

struct StateT2 * slot_3(struct StateT2 * v110) {
  struct StateT * v111 = v110->a;
  int v112 = v111->timer;
  struct StateT * v113 = v110->b;
  int v114 = v113->timer;
  bool v133 = v112 == v114;
  squared_assert(v133);
  squared_assume(v133);
  struct StateT * v117 = v110->a;
  int v118 = v117->timer;
  int v135 = v118 + 1;
  v117->timer = v135;
  struct StateT * v120 = v110->b;
  int v121 = v120->timer;
  int v137 = v121 + 1;
  v120->timer = v137;
  struct StateT * v123 = v110->a;
  int * v124 = v123->regs;
  v124[15] = 16;
  struct StateT * v126 = v110->b;
  int * v127 = v126->regs;
  v127[15] = 16;
  struct StateT2 * v129 = slot_4(v110);
  return v129;
}

struct StateT2 * slot_10(struct StateT2 * v1200) {
  struct StateT * v1201 = v1200->a;
  int v1202 = v1201->timer;
  struct StateT * v1203 = v1200->b;
  int v1204 = v1203->timer;
  bool v1237 = v1202 == v1204;
  squared_assert(v1237);
  squared_assume(v1237);
  struct StateT * v1207 = v1200->a;
  int * v1208 = v1207->saved_regs;
  int * v1209 = v1207->regs;
  int v1210 = v1209[16];
  v1208[16] = v1210;
  struct StateT * v1212 = v1200->b;
  int * v1213 = v1212->saved_regs;
  int * v1214 = v1212->regs;
  int v1215 = v1214[16];
  v1213[16] = v1215;
  struct StateT * v1217 = v1200->a;
  int v1218 = v1217->timer;
  int v1248 = v1218 + 1;
  v1217->timer = v1248;
  struct StateT * v1220 = v1200->b;
  int v1221 = v1220->timer;
  int v1250 = v1221 + 1;
  v1220->timer = v1250;
  struct StateT * v1223 = v1200->a;
  int * v1224 = v1223->regs;
  int v1225 = v1224[7];
  int v1226 = v1224[9];
  int v1255 = v1225 ^ v1226;
  v1224[16] = v1255;
  struct StateT * v1228 = v1200->b;
  int * v1229 = v1228->regs;
  int v1230 = v1229[7];
  int v1231 = v1229[9];
  int v1258 = v1230 ^ v1231;
  v1229[16] = v1258;
  struct StateT2 * v1233 = slot_23(v1200);
  return v1233;
}

struct StateT2 * slot_1(struct StateT2 * v38) {
  struct StateT * v39 = v38->a;
  int v40 = v39->timer;
  struct StateT * v41 = v38->b;
  int v42 = v41->timer;
  bool v61 = v40 == v42;
  squared_assert(v61);
  squared_assume(v61);
  struct StateT * v45 = v38->a;
  int v46 = v45->timer;
  int v63 = v46 + 1;
  v45->timer = v63;
  struct StateT * v48 = v38->b;
  int v49 = v48->timer;
  int v65 = v49 + 1;
  v48->timer = v65;
  struct StateT * v51 = v38->a;
  int * v52 = v51->regs;
  v52[13] = 80;
  struct StateT * v54 = v38->b;
  int * v55 = v54->regs;
  v55[13] = 80;
  struct StateT2 * v57 = slot_2(v38);
  return v57;
}

struct StateT2 * slot_0(struct StateT2 * v2) {
  struct StateT * v3 = v2->a;
  int v4 = v3->timer;
  struct StateT * v5 = v2->b;
  int v6 = v5->timer;
  bool v25 = v4 == v6;
  squared_assert(v25);
  squared_assume(v25);
  struct StateT * v9 = v2->a;
  int v10 = v9->timer;
  int v27 = v10 + 1;
  v9->timer = v27;
  struct StateT * v12 = v2->b;
  int v13 = v12->timer;
  int v29 = v13 + 1;
  v12->timer = v29;
  struct StateT * v15 = v2->a;
  int * v16 = v15->regs;
  v16[12] = 0;
  struct StateT * v18 = v2->b;
  int * v19 = v18->regs;
  v19[12] = 0;
  struct StateT2 * v21 = slot_1(v2);
  return v21;
}

struct StateT2 * slot_14(struct StateT2 * v1535) {
  struct StateT * v1536 = v1535->a;
  int v1537 = v1536->timer;
  struct StateT * v1538 = v1535->b;
  int v1539 = v1538->timer;
  bool v1567 = v1537 == v1539;
  squared_assert(v1567);
  squared_assume(v1567);
  struct StateT * v1542 = v1535->a;
  int v1543 = v1542->timer;
  int v1569 = v1543 + 1;
  v1542->timer = v1569;
  struct StateT * v1545 = v1535->b;
  int v1546 = v1545->timer;
  int v1571 = v1546 + 1;
  v1545->timer = v1571;
  struct StateT * v1548 = v1535->a;
  int * v1549 = v1548->regs;
  int v1550 = v1549[5];
  bool v1575 = (v1550 ^ -2147483648) < -2147483647;
  int v1553;
  if (v1575) {
    v1553 = 1;
  } else {
    v1553 = 0;
  }
  int * v1554 = v1548->regs;
  v1554[11] = v1553;
  struct StateT * v1556 = v1535->b;
  int * v1557 = v1556->regs;
  int v1558 = v1557[5];
  bool v1583 = (v1558 ^ -2147483648) < -2147483647;
  int v1561;
  if (v1583) {
    v1561 = 1;
  } else {
    v1561 = 0;
  }
  int * v1562 = v1556->regs;
  v1562[11] = v1561;
  return v1535;
}

struct StateT2 * slot_20(struct StateT2 * v2135) {
  struct StateT * v2136 = v2135->a;
  int v2137 = v2136->timer;
  struct StateT * v2138 = v2135->b;
  int v2139 = v2138->timer;
  bool v2172 = v2137 == v2139;
  squared_assert(v2172);
  squared_assume(v2172);
  struct StateT * v2142 = v2135->a;
  int * v2143 = v2142->saved_regs;
  int * v2144 = v2142->regs;
  int v2145 = v2144[8];
  v2143[8] = v2145;
  struct StateT * v2147 = v2135->b;
  int * v2148 = v2147->saved_regs;
  int * v2149 = v2147->regs;
  int v2150 = v2149[8];
  v2148[8] = v2150;
  struct StateT * v2152 = v2135->a;
  int v2153 = v2152->timer;
  int v2183 = v2153 + 1;
  v2152->timer = v2183;
  struct StateT * v2155 = v2135->b;
  int v2156 = v2155->timer;
  int v2185 = v2156 + 1;
  v2155->timer = v2185;
  struct StateT * v2158 = v2135->a;
  int * v2159 = v2158->regs;
  int v2160 = v2159[13];
  int v2161 = v2159[14];
  int v2190 = v2160 + v2161;
  v2159[8] = v2190;
  struct StateT * v2163 = v2135->b;
  int * v2164 = v2163->regs;
  int v2165 = v2164[13];
  int v2166 = v2164[14];
  int v2193 = v2165 + v2166;
  v2164[8] = v2193;
  struct StateT2 * v2168 = slot_21(v2135);
  return v2168;
}

struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  return v1;
}

struct StateT2 * slot_4(struct StateT2 * v146) {
  struct StateT * v147 = v146->a;
  int v148 = v147->timer;
  struct StateT * v149 = v146->b;
  int v150 = v149->timer;
  bool v169 = v148 == v150;
  squared_assert(v169);
  squared_assume(v169);
  struct StateT * v153 = v146->a;
  int v154 = v153->timer;
  int v171 = v154 + 1;
  v153->timer = v171;
  struct StateT * v156 = v146->b;
  int v157 = v156->timer;
  int v173 = v157 + 1;
  v156->timer = v173;
  struct StateT * v159 = v146->a;
  int * v160 = v159->regs;
  v160[5] = 0;
  struct StateT * v162 = v146->b;
  int * v163 = v162->regs;
  v163[5] = 0;
  struct StateT2 * v165 = slot_5(v146);
  return v165;
}

struct StateT2 * slot_15(struct StateT2 * v1588) {
  struct StateT * v1589 = v1588->a;
  int v1590 = v1589->timer;
  struct StateT * v1591 = v1588->b;
  int v1592 = v1591->timer;
  bool v1607 = v1590 == v1592;
  squared_assert(v1607);
  squared_assume(v1607);
  struct StateT * v1595 = v1588->a;
  int v1596 = v1595->timer;
  int v1609 = v1596 + 1;
  v1595->timer = v1609;
  struct StateT * v1598 = v1588->b;
  int v1599 = v1598->timer;
  int v1611 = v1599 + 1;
  v1598->timer = v1611;
  struct StateT2 * v1603 = slot_5(v1588);
  return v1603;
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

void squared_assert(bool c) { koika_assert(c, "timer drift"); }
void squared_diverged(bool c) { koika_assert(c, "control flow diverged"); }
void squared_assume(bool c) { koika_assume(c); }

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
  struct StateT2 p = { .a = &s1, .b = &s2 };
  struct StateT2 *p_ = snippet(&p);
  //@ assert untainted_timer: !\tainted(p_->a->timer==p_->b->timer);
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}