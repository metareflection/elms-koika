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

void lockstep_assert(bool);
void lockstep_assume(bool);

struct StateT2 * slot_12(struct StateT2 * v732_p);
struct StateT2 * slot_6(struct StateT2 * v265_p);
struct StateT2 * slot_16(struct StateT2 * v791_p);
struct StateT2 * slot_5(struct StateT2 * v251_p);
struct StateT2 * slot_2(struct StateT2 * v206_p);
struct StateT2 * slot_7(struct StateT2 * v469_p);
struct StateT2 * slot_21(struct StateT2 * v1054_p);
struct StateT2 * slot_3(struct StateT2 * v222_p);
struct StateT2 * slot_10(struct StateT2 * v514_p);
struct StateT2 * slot_1(struct StateT2 * v15_p);
struct StateT2 * slot_19(struct StateT2 * v1026_p);
struct StateT2 * slot_13(struct StateT2 * v748_p);
struct StateT2 * slot_0(struct StateT2 * v2_p);
struct StateT2 * slot_14(struct StateT2 * v763_p);
struct StateT2 * slot_17(struct StateT2 * v995_p);
struct StateT2 * slot_20(struct StateT2 * v1040_p);
struct StateT2 * snippet(struct StateT2 * v0_p);
struct StateT2 * slot_8(struct StateT2 * v485_p);
struct StateT2 * slot_4(struct StateT2 * v237_p);
struct StateT2 * slot_15(struct StateT2 * v777_p);
struct StateT2 * slot_18(struct StateT2 * v1011_p);
struct StateT2 * slot_9(struct StateT2 * v500_p);
struct StateT2 * slot_22(struct StateT2 * v1258_p);
struct StateT2 * slot_11(struct StateT2 * v528_p);
struct StateT2 * slot_12(struct StateT2 * v732_p) {
  lockstep_assert(((v732_p->a)->timer) == ((v732_p->b)->timer));
  lockstep_assume(((v732_p->a)->timer) == ((v732_p->b)->timer));
  int v733_a = (v732_p->a)->timer;
  int v733_b = (v732_p->b)->timer;
  int v741_a = v733_a + 1;
  int v741_b = v733_b + 1;
  (v732_p->a)->timer = v741_a;
  (v732_p->b)->timer = v741_b;
  int * v735_a = (v732_p->a)->regs;
  int * v735_b = (v732_p->b)->regs;
  int v736_a = v735_a[5];
  int v736_b = v735_b[5];
  int v737_a = v735_a[7];
  int v737_b = v735_b[7];
  int v745_a = v736_a ^ v737_a;
  int v745_b = v736_b ^ v737_b;
  v735_a[5] = v745_a;
  v735_b[5] = v745_b;
  struct StateT2 * v739_p = slot_13(v732_p);
  return v739_p;
}

struct StateT2 * slot_6(struct StateT2 * v265_p) {
  lockstep_assert(((v265_p->a)->timer) == ((v265_p->b)->timer));
  lockstep_assume(((v265_p->a)->timer) == ((v265_p->b)->timer));
  int v266_a = (v265_p->a)->timer;
  int v266_b = (v265_p->b)->timer;
  int v376_a = v266_a + 1;
  int v376_b = v266_b + 1;
  (v265_p->a)->timer = v376_a;
  (v265_p->b)->timer = v376_b;
  int * v268_a = (v265_p->a)->regs;
  int * v268_b = (v265_p->b)->regs;
  int v269_a = v268_a[6];
  int v269_b = v268_b[6];
  int * v270_a = (v265_p->a)->cache_tags;
  int * v270_b = (v265_p->b)->cache_tags;
  int v380_a = (((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1)) & 1) * 2;
  int v380_b = (((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1)) & 1) * 2;
  int v271_a = v270_a[v380_a];
  int v271_b = v270_b[v380_b];
  int v381_a = ((((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1)) & 1) * 2) + 1;
  int v381_b = ((((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1)) & 1) * 2) + 1;
  int v272_a = v270_a[v381_a];
  int v272_b = v270_b[v381_b];
  int v382_a = 4 + ((((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1)) & 3) * 2);
  int v382_b = 4 + ((((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1)) & 3) * 2);
  int v273_a = v270_a[v382_a];
  int v273_b = v270_b[v382_b];
  int v383_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1)) & 3) * 2)) + 1;
  int v383_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1)) & 3) * 2)) + 1;
  int v274_a = v270_a[v383_a];
  int v274_b = v270_b[v383_b];
  int v275_a = (v265_p->a)->timer;
  int v275_b = (v265_p->b)->timer;
  int v384_a = v275_a + ((100 ^ (((~(((v273_a ^ ((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1))) | (-(v273_a ^ ((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1))))) >> 31)) | (~(((v274_a ^ ((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1))) | (-(v274_a ^ ((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v271_a ^ ((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1))) | (-(v271_a ^ ((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1))))) >> 31)) | (~(((v272_a ^ ((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1))) | (-(v272_a ^ ((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v273_a ^ ((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1))) | (-(v273_a ^ ((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1))))) >> 31)) | (~(((v274_a ^ ((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1))) | (-(v274_a ^ ((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1))))) >> 31))) & 104)))));
  int v384_b = v275_b + ((100 ^ (((~(((v273_b ^ ((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1))) | (-(v273_b ^ ((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1))))) >> 31)) | (~(((v274_b ^ ((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1))) | (-(v274_b ^ ((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v271_b ^ ((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1))) | (-(v271_b ^ ((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1))))) >> 31)) | (~(((v272_b ^ ((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1))) | (-(v272_b ^ ((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v273_b ^ ((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1))) | (-(v273_b ^ ((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1))))) >> 31)) | (~(((v274_b ^ ((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1))) | (-(v274_b ^ ((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1))))) >> 31))) & 104)))));
  (v265_p->a)->timer = v384_a;
  (v265_p->b)->timer = v384_b;
  int * v277_a = (v265_p->a)->cache_vals;
  int * v277_b = (v265_p->b)->cache_vals;
  bool v385_a = !(((~(((v271_a ^ ((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1))) | (-(v271_a ^ ((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1))))) >> 31)) | (~(((v272_a ^ ((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1))) | (-(v272_a ^ ((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1))))) >> 31))) == 0);
  bool v385_b = !(((~(((v271_b ^ ((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1))) | (-(v271_b ^ ((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1))))) >> 31)) | (~(((v272_b ^ ((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1))) | (-(v272_b ^ ((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1))))) >> 31))) == 0);
  int v370_a;
  if (v385_a) {
    int * v278_a = (v265_p->a)->cache_age;
    int v387_a = ((((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1)) & 1) * 2) + ((~(((v272_a ^ ((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1))) | (-(v272_a ^ ((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1))))) >> 31)) & 1);
    int v279_a = v278_a[v387_a];
    int v280_a = v278_a[v380_a];
    int v388_a = v280_a + ((int)((unsigned int)(v280_a - v279_a) >> 31));
    v278_a[v380_a] = v388_a;
    int * v282_a = (v265_p->a)->cache_age;
    int v283_a = v282_a[v381_a];
    int v390_a = v283_a + ((int)((unsigned int)(v283_a - v279_a) >> 31));
    v282_a[v381_a] = v390_a;
    int * v285_a = (v265_p->a)->cache_age;
    v285_a[v387_a] = 0;
    v370_a = v387_a;
  } else {
    int * v288_a = (v265_p->a)->cache_age;
    int v394_a = (((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1)) & 1) * 2;
    int v289_a = v288_a[v394_a];
    int * v290_a = (v265_p->a)->cache_tags;
    int v291_a = v290_a[v394_a];
    int v292_a = v288_a[v381_a];
    int v293_a = v290_a[v381_a];
    bool v396_a = !(((~(((v273_a ^ ((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1))) | (-(v273_a ^ ((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1))))) >> 31)) | (~(((v274_a ^ ((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1))) | (-(v274_a ^ ((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1))))) >> 31))) == 0);
    int v347_a;
    if (v396_a) {
      int * v294_a = (v265_p->a)->cache_age;
      int v398_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1)) & 3) * 2)) + ((~(((v274_a ^ ((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1))) | (-(v274_a ^ ((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1))))) >> 31)) & 1);
      int v295_a = v294_a[v398_a];
      int v296_a = v294_a[v382_a];
      int v399_a = v296_a + ((int)((unsigned int)(v296_a - v295_a) >> 31));
      v294_a[v382_a] = v399_a;
      int * v298_a = (v265_p->a)->cache_age;
      int v299_a = v298_a[v383_a];
      int v401_a = v299_a + ((int)((unsigned int)(v299_a - v295_a) >> 31));
      v298_a[v383_a] = v401_a;
      int * v301_a = (v265_p->a)->cache_age;
      v301_a[v398_a] = 0;
      v347_a = v398_a;
    } else {
      int * v304_a = (v265_p->a)->cache_age;
      int v405_a = 4 + ((((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1)) & 3) * 2);
      int v305_a = v304_a[v405_a];
      int * v306_a = (v265_p->a)->cache_tags;
      int v307_a = v306_a[v405_a];
      int v308_a = v304_a[v383_a];
      int v309_a = v306_a[v383_a];
      int * v310_a = (v265_p->a)->cache_dirty;
      int v408_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1)) & 3) * 2)) + ((((v305_a + ((~(((v307_a ^ -1) | (-(v307_a ^ -1))) >> 31)) & 2)) - (v308_a + ((~(((v309_a ^ -1) | (-(v309_a ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v311_a = v310_a[v408_a];
      bool v409_a = !(v311_a == 0);
      if (v409_a) {
        int * v312_a = (v265_p->a)->cache_tags;
        int v313_a = v312_a[v408_a];
        int * v314_a = (v265_p->a)->cache_vals;
        int v412_a = ((4 + ((((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1)) & 3) * 2)) + ((((v305_a + ((~(((v307_a ^ -1) | (-(v307_a ^ -1))) >> 31)) & 2)) - (v308_a + ((~(((v309_a ^ -1) | (-(v309_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v315_a = v314_a[v412_a];
        int v413_a = (((4 + ((((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1)) & 3) * 2)) + ((((v305_a + ((~(((v307_a ^ -1) | (-(v307_a ^ -1))) >> 31)) & 2)) - (v308_a + ((~(((v309_a ^ -1) | (-(v309_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v316_a = v314_a[v413_a];
        int * v317_a = (v265_p->a)->mem;
        int v415_a = v313_a * 2;
        v317_a[v415_a] = v315_a;
        int * v319_a = (v265_p->a)->mem;
        int v418_a = (v313_a * 2) + 1;
        v319_a[v418_a] = v316_a;
        ;
      } else {
        ;
      }
      int * v324_a = (v265_p->a)->mem;
      int v423_a = ((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1)) * 2;
      int v325_a = v324_a[v423_a];
      int v424_a = (((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1)) * 2) + 1;
      int v326_a = v324_a[v424_a];
      int * v327_a = (v265_p->a)->cache_vals;
      int v426_a = ((4 + ((((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1)) & 3) * 2)) + ((((v305_a + ((~(((v307_a ^ -1) | (-(v307_a ^ -1))) >> 31)) & 2)) - (v308_a + ((~(((v309_a ^ -1) | (-(v309_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v327_a[v426_a] = v325_a;
      int * v329_a = (v265_p->a)->cache_vals;
      int v429_a = (((4 + ((((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1)) & 3) * 2)) + ((((v305_a + ((~(((v307_a ^ -1) | (-(v307_a ^ -1))) >> 31)) & 2)) - (v308_a + ((~(((v309_a ^ -1) | (-(v309_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v329_a[v429_a] = v326_a;
      int * v331_a = (v265_p->a)->cache_tags;
      int v432_a = (int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1);
      v331_a[v408_a] = v432_a;
      int * v333_a = (v265_p->a)->cache_dirty;
      v333_a[v408_a] = 0;
      int * v335_a = (v265_p->a)->cache_age;
      v335_a[v408_a] = 1;
      int * v337_a = (v265_p->a)->cache_age;
      int v338_a = v337_a[v408_a];
      int v339_a = v337_a[v382_a];
      int v438_a = v339_a + ((int)((unsigned int)(v339_a - v338_a) >> 31));
      v337_a[v382_a] = v438_a;
      int * v341_a = (v265_p->a)->cache_age;
      int v342_a = v341_a[v383_a];
      int v440_a = v342_a + ((int)((unsigned int)(v342_a - v338_a) >> 31));
      v341_a[v383_a] = v440_a;
      int * v344_a = (v265_p->a)->cache_age;
      v344_a[v408_a] = 0;
      v347_a = v408_a;
    }
    int * v348_a = (v265_p->a)->cache_vals;
    int v443_a = v347_a * 2;
    int v349_a = v348_a[v443_a];
    int v444_a = (v347_a * 2) + 1;
    int v350_a = v348_a[v444_a];
    int v445_a = (((((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1)) & 1) * 2) + ((((v289_a + ((~(((v291_a ^ -1) | (-(v291_a ^ -1))) >> 31)) & 2)) - (v292_a + ((~(((v293_a ^ -1) | (-(v293_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v348_a[v445_a] = v349_a;
    int * v352_a = (v265_p->a)->cache_vals;
    int v448_a = ((((((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1)) & 1) * 2) + ((((v289_a + ((~(((v291_a ^ -1) | (-(v291_a ^ -1))) >> 31)) & 2)) - (v292_a + ((~(((v293_a ^ -1) | (-(v293_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v352_a[v448_a] = v350_a;
    int * v354_a = (v265_p->a)->cache_tags;
    int v451_a = ((((int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1)) & 1) * 2) + ((((v289_a + ((~(((v291_a ^ -1) | (-(v291_a ^ -1))) >> 31)) & 2)) - (v292_a + ((~(((v293_a ^ -1) | (-(v293_a ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v452_a = (int)((unsigned int)((int)((unsigned int)v269_a >> 2)) >> 1);
    v354_a[v451_a] = v452_a;
    int * v356_a = (v265_p->a)->cache_dirty;
    v356_a[v451_a] = 0;
    int * v358_a = (v265_p->a)->cache_age;
    v358_a[v451_a] = 1;
    int * v360_a = (v265_p->a)->cache_age;
    int v361_a = v360_a[v451_a];
    int v362_a = v360_a[v380_a];
    int v458_a = v362_a + ((int)((unsigned int)(v362_a - v361_a) >> 31));
    v360_a[v380_a] = v458_a;
    int * v364_a = (v265_p->a)->cache_age;
    int v365_a = v364_a[v381_a];
    int v460_a = v365_a + ((int)((unsigned int)(v365_a - v361_a) >> 31));
    v364_a[v381_a] = v460_a;
    int * v367_a = (v265_p->a)->cache_age;
    v367_a[v451_a] = 0;
    v370_a = v451_a;
  }
  int v370_b;
  if (v385_b) {
    int * v278_b = (v265_p->b)->cache_age;
    int v387_b = ((((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1)) & 1) * 2) + ((~(((v272_b ^ ((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1))) | (-(v272_b ^ ((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1))))) >> 31)) & 1);
    int v279_b = v278_b[v387_b];
    int v280_b = v278_b[v380_b];
    int v388_b = v280_b + ((int)((unsigned int)(v280_b - v279_b) >> 31));
    v278_b[v380_b] = v388_b;
    int * v282_b = (v265_p->b)->cache_age;
    int v283_b = v282_b[v381_b];
    int v390_b = v283_b + ((int)((unsigned int)(v283_b - v279_b) >> 31));
    v282_b[v381_b] = v390_b;
    int * v285_b = (v265_p->b)->cache_age;
    v285_b[v387_b] = 0;
    v370_b = v387_b;
  } else {
    int * v288_b = (v265_p->b)->cache_age;
    int v394_b = (((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1)) & 1) * 2;
    int v289_b = v288_b[v394_b];
    int * v290_b = (v265_p->b)->cache_tags;
    int v291_b = v290_b[v394_b];
    int v292_b = v288_b[v381_b];
    int v293_b = v290_b[v381_b];
    bool v396_b = !(((~(((v273_b ^ ((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1))) | (-(v273_b ^ ((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1))))) >> 31)) | (~(((v274_b ^ ((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1))) | (-(v274_b ^ ((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1))))) >> 31))) == 0);
    int v347_b;
    if (v396_b) {
      int * v294_b = (v265_p->b)->cache_age;
      int v398_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1)) & 3) * 2)) + ((~(((v274_b ^ ((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1))) | (-(v274_b ^ ((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1))))) >> 31)) & 1);
      int v295_b = v294_b[v398_b];
      int v296_b = v294_b[v382_b];
      int v399_b = v296_b + ((int)((unsigned int)(v296_b - v295_b) >> 31));
      v294_b[v382_b] = v399_b;
      int * v298_b = (v265_p->b)->cache_age;
      int v299_b = v298_b[v383_b];
      int v401_b = v299_b + ((int)((unsigned int)(v299_b - v295_b) >> 31));
      v298_b[v383_b] = v401_b;
      int * v301_b = (v265_p->b)->cache_age;
      v301_b[v398_b] = 0;
      v347_b = v398_b;
    } else {
      int * v304_b = (v265_p->b)->cache_age;
      int v405_b = 4 + ((((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1)) & 3) * 2);
      int v305_b = v304_b[v405_b];
      int * v306_b = (v265_p->b)->cache_tags;
      int v307_b = v306_b[v405_b];
      int v308_b = v304_b[v383_b];
      int v309_b = v306_b[v383_b];
      int * v310_b = (v265_p->b)->cache_dirty;
      int v408_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1)) & 3) * 2)) + ((((v305_b + ((~(((v307_b ^ -1) | (-(v307_b ^ -1))) >> 31)) & 2)) - (v308_b + ((~(((v309_b ^ -1) | (-(v309_b ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v311_b = v310_b[v408_b];
      bool v409_b = !(v311_b == 0);
      if (v409_b) {
        int * v312_b = (v265_p->b)->cache_tags;
        int v313_b = v312_b[v408_b];
        int * v314_b = (v265_p->b)->cache_vals;
        int v412_b = ((4 + ((((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1)) & 3) * 2)) + ((((v305_b + ((~(((v307_b ^ -1) | (-(v307_b ^ -1))) >> 31)) & 2)) - (v308_b + ((~(((v309_b ^ -1) | (-(v309_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v315_b = v314_b[v412_b];
        int v413_b = (((4 + ((((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1)) & 3) * 2)) + ((((v305_b + ((~(((v307_b ^ -1) | (-(v307_b ^ -1))) >> 31)) & 2)) - (v308_b + ((~(((v309_b ^ -1) | (-(v309_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v316_b = v314_b[v413_b];
        int * v317_b = (v265_p->b)->mem;
        int v415_b = v313_b * 2;
        v317_b[v415_b] = v315_b;
        int * v319_b = (v265_p->b)->mem;
        int v418_b = (v313_b * 2) + 1;
        v319_b[v418_b] = v316_b;
        ;
      } else {
        ;
      }
      int * v324_b = (v265_p->b)->mem;
      int v423_b = ((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1)) * 2;
      int v325_b = v324_b[v423_b];
      int v424_b = (((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1)) * 2) + 1;
      int v326_b = v324_b[v424_b];
      int * v327_b = (v265_p->b)->cache_vals;
      int v426_b = ((4 + ((((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1)) & 3) * 2)) + ((((v305_b + ((~(((v307_b ^ -1) | (-(v307_b ^ -1))) >> 31)) & 2)) - (v308_b + ((~(((v309_b ^ -1) | (-(v309_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v327_b[v426_b] = v325_b;
      int * v329_b = (v265_p->b)->cache_vals;
      int v429_b = (((4 + ((((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1)) & 3) * 2)) + ((((v305_b + ((~(((v307_b ^ -1) | (-(v307_b ^ -1))) >> 31)) & 2)) - (v308_b + ((~(((v309_b ^ -1) | (-(v309_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v329_b[v429_b] = v326_b;
      int * v331_b = (v265_p->b)->cache_tags;
      int v432_b = (int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1);
      v331_b[v408_b] = v432_b;
      int * v333_b = (v265_p->b)->cache_dirty;
      v333_b[v408_b] = 0;
      int * v335_b = (v265_p->b)->cache_age;
      v335_b[v408_b] = 1;
      int * v337_b = (v265_p->b)->cache_age;
      int v338_b = v337_b[v408_b];
      int v339_b = v337_b[v382_b];
      int v438_b = v339_b + ((int)((unsigned int)(v339_b - v338_b) >> 31));
      v337_b[v382_b] = v438_b;
      int * v341_b = (v265_p->b)->cache_age;
      int v342_b = v341_b[v383_b];
      int v440_b = v342_b + ((int)((unsigned int)(v342_b - v338_b) >> 31));
      v341_b[v383_b] = v440_b;
      int * v344_b = (v265_p->b)->cache_age;
      v344_b[v408_b] = 0;
      v347_b = v408_b;
    }
    int * v348_b = (v265_p->b)->cache_vals;
    int v443_b = v347_b * 2;
    int v349_b = v348_b[v443_b];
    int v444_b = (v347_b * 2) + 1;
    int v350_b = v348_b[v444_b];
    int v445_b = (((((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1)) & 1) * 2) + ((((v289_b + ((~(((v291_b ^ -1) | (-(v291_b ^ -1))) >> 31)) & 2)) - (v292_b + ((~(((v293_b ^ -1) | (-(v293_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v348_b[v445_b] = v349_b;
    int * v352_b = (v265_p->b)->cache_vals;
    int v448_b = ((((((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1)) & 1) * 2) + ((((v289_b + ((~(((v291_b ^ -1) | (-(v291_b ^ -1))) >> 31)) & 2)) - (v292_b + ((~(((v293_b ^ -1) | (-(v293_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v352_b[v448_b] = v350_b;
    int * v354_b = (v265_p->b)->cache_tags;
    int v451_b = ((((int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1)) & 1) * 2) + ((((v289_b + ((~(((v291_b ^ -1) | (-(v291_b ^ -1))) >> 31)) & 2)) - (v292_b + ((~(((v293_b ^ -1) | (-(v293_b ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v452_b = (int)((unsigned int)((int)((unsigned int)v269_b >> 2)) >> 1);
    v354_b[v451_b] = v452_b;
    int * v356_b = (v265_p->b)->cache_dirty;
    v356_b[v451_b] = 0;
    int * v358_b = (v265_p->b)->cache_age;
    v358_b[v451_b] = 1;
    int * v360_b = (v265_p->b)->cache_age;
    int v361_b = v360_b[v451_b];
    int v362_b = v360_b[v380_b];
    int v458_b = v362_b + ((int)((unsigned int)(v362_b - v361_b) >> 31));
    v360_b[v380_b] = v458_b;
    int * v364_b = (v265_p->b)->cache_age;
    int v365_b = v364_b[v381_b];
    int v460_b = v365_b + ((int)((unsigned int)(v365_b - v361_b) >> 31));
    v364_b[v381_b] = v460_b;
    int * v367_b = (v265_p->b)->cache_age;
    v367_b[v451_b] = 0;
    v370_b = v451_b;
  }
  int v463_a = (v370_a * 2) + (((int)((unsigned int)v269_a >> 2)) & 1);
  int v463_b = (v370_b * 2) + (((int)((unsigned int)v269_b >> 2)) & 1);
  int v371_a = v277_a[v463_a];
  int v371_b = v277_b[v463_b];
  int * v372_a = (v265_p->a)->regs;
  int * v372_b = (v265_p->b)->regs;
  v372_a[7] = v371_a;
  v372_b[7] = v371_b;
  struct StateT2 * v374_p = slot_7(v265_p);
  return v374_p;
}

struct StateT2 * slot_16(struct StateT2 * v791_p) {
  lockstep_assert(((v791_p->a)->timer) == ((v791_p->b)->timer));
  lockstep_assume(((v791_p->a)->timer) == ((v791_p->b)->timer));
  int v792_a = (v791_p->a)->timer;
  int v792_b = (v791_p->b)->timer;
  int v902_a = v792_a + 1;
  int v902_b = v792_b + 1;
  (v791_p->a)->timer = v902_a;
  (v791_p->b)->timer = v902_b;
  int * v794_a = (v791_p->a)->regs;
  int * v794_b = (v791_p->b)->regs;
  int v795_a = v794_a[6];
  int v795_b = v794_b[6];
  int * v796_a = (v791_p->a)->cache_tags;
  int * v796_b = (v791_p->b)->cache_tags;
  int v906_a = (((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1)) & 1) * 2;
  int v906_b = (((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1)) & 1) * 2;
  int v797_a = v796_a[v906_a];
  int v797_b = v796_b[v906_b];
  int v907_a = ((((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1)) & 1) * 2) + 1;
  int v907_b = ((((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1)) & 1) * 2) + 1;
  int v798_a = v796_a[v907_a];
  int v798_b = v796_b[v907_b];
  int v908_a = 4 + ((((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1)) & 3) * 2);
  int v908_b = 4 + ((((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1)) & 3) * 2);
  int v799_a = v796_a[v908_a];
  int v799_b = v796_b[v908_b];
  int v909_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1)) & 3) * 2)) + 1;
  int v909_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1)) & 3) * 2)) + 1;
  int v800_a = v796_a[v909_a];
  int v800_b = v796_b[v909_b];
  int v801_a = (v791_p->a)->timer;
  int v801_b = (v791_p->b)->timer;
  int v910_a = v801_a + ((100 ^ (((~(((v799_a ^ ((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1))) | (-(v799_a ^ ((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1))))) >> 31)) | (~(((v800_a ^ ((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1))) | (-(v800_a ^ ((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v797_a ^ ((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1))) | (-(v797_a ^ ((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1))))) >> 31)) | (~(((v798_a ^ ((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1))) | (-(v798_a ^ ((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v799_a ^ ((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1))) | (-(v799_a ^ ((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1))))) >> 31)) | (~(((v800_a ^ ((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1))) | (-(v800_a ^ ((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1))))) >> 31))) & 104)))));
  int v910_b = v801_b + ((100 ^ (((~(((v799_b ^ ((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1))) | (-(v799_b ^ ((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1))))) >> 31)) | (~(((v800_b ^ ((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1))) | (-(v800_b ^ ((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v797_b ^ ((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1))) | (-(v797_b ^ ((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1))))) >> 31)) | (~(((v798_b ^ ((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1))) | (-(v798_b ^ ((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v799_b ^ ((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1))) | (-(v799_b ^ ((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1))))) >> 31)) | (~(((v800_b ^ ((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1))) | (-(v800_b ^ ((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1))))) >> 31))) & 104)))));
  (v791_p->a)->timer = v910_a;
  (v791_p->b)->timer = v910_b;
  int * v803_a = (v791_p->a)->cache_vals;
  int * v803_b = (v791_p->b)->cache_vals;
  bool v911_a = !(((~(((v797_a ^ ((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1))) | (-(v797_a ^ ((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1))))) >> 31)) | (~(((v798_a ^ ((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1))) | (-(v798_a ^ ((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1))))) >> 31))) == 0);
  bool v911_b = !(((~(((v797_b ^ ((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1))) | (-(v797_b ^ ((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1))))) >> 31)) | (~(((v798_b ^ ((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1))) | (-(v798_b ^ ((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1))))) >> 31))) == 0);
  int v896_a;
  if (v911_a) {
    int * v804_a = (v791_p->a)->cache_age;
    int v913_a = ((((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1)) & 1) * 2) + ((~(((v798_a ^ ((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1))) | (-(v798_a ^ ((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1))))) >> 31)) & 1);
    int v805_a = v804_a[v913_a];
    int v806_a = v804_a[v906_a];
    int v914_a = v806_a + ((int)((unsigned int)(v806_a - v805_a) >> 31));
    v804_a[v906_a] = v914_a;
    int * v808_a = (v791_p->a)->cache_age;
    int v809_a = v808_a[v907_a];
    int v916_a = v809_a + ((int)((unsigned int)(v809_a - v805_a) >> 31));
    v808_a[v907_a] = v916_a;
    int * v811_a = (v791_p->a)->cache_age;
    v811_a[v913_a] = 0;
    v896_a = v913_a;
  } else {
    int * v814_a = (v791_p->a)->cache_age;
    int v920_a = (((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1)) & 1) * 2;
    int v815_a = v814_a[v920_a];
    int * v816_a = (v791_p->a)->cache_tags;
    int v817_a = v816_a[v920_a];
    int v818_a = v814_a[v907_a];
    int v819_a = v816_a[v907_a];
    bool v922_a = !(((~(((v799_a ^ ((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1))) | (-(v799_a ^ ((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1))))) >> 31)) | (~(((v800_a ^ ((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1))) | (-(v800_a ^ ((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1))))) >> 31))) == 0);
    int v873_a;
    if (v922_a) {
      int * v820_a = (v791_p->a)->cache_age;
      int v924_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1)) & 3) * 2)) + ((~(((v800_a ^ ((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1))) | (-(v800_a ^ ((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1))))) >> 31)) & 1);
      int v821_a = v820_a[v924_a];
      int v822_a = v820_a[v908_a];
      int v925_a = v822_a + ((int)((unsigned int)(v822_a - v821_a) >> 31));
      v820_a[v908_a] = v925_a;
      int * v824_a = (v791_p->a)->cache_age;
      int v825_a = v824_a[v909_a];
      int v927_a = v825_a + ((int)((unsigned int)(v825_a - v821_a) >> 31));
      v824_a[v909_a] = v927_a;
      int * v827_a = (v791_p->a)->cache_age;
      v827_a[v924_a] = 0;
      v873_a = v924_a;
    } else {
      int * v830_a = (v791_p->a)->cache_age;
      int v931_a = 4 + ((((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1)) & 3) * 2);
      int v831_a = v830_a[v931_a];
      int * v832_a = (v791_p->a)->cache_tags;
      int v833_a = v832_a[v931_a];
      int v834_a = v830_a[v909_a];
      int v835_a = v832_a[v909_a];
      int * v836_a = (v791_p->a)->cache_dirty;
      int v934_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1)) & 3) * 2)) + ((((v831_a + ((~(((v833_a ^ -1) | (-(v833_a ^ -1))) >> 31)) & 2)) - (v834_a + ((~(((v835_a ^ -1) | (-(v835_a ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v837_a = v836_a[v934_a];
      bool v935_a = !(v837_a == 0);
      if (v935_a) {
        int * v838_a = (v791_p->a)->cache_tags;
        int v839_a = v838_a[v934_a];
        int * v840_a = (v791_p->a)->cache_vals;
        int v938_a = ((4 + ((((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1)) & 3) * 2)) + ((((v831_a + ((~(((v833_a ^ -1) | (-(v833_a ^ -1))) >> 31)) & 2)) - (v834_a + ((~(((v835_a ^ -1) | (-(v835_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v841_a = v840_a[v938_a];
        int v939_a = (((4 + ((((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1)) & 3) * 2)) + ((((v831_a + ((~(((v833_a ^ -1) | (-(v833_a ^ -1))) >> 31)) & 2)) - (v834_a + ((~(((v835_a ^ -1) | (-(v835_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v842_a = v840_a[v939_a];
        int * v843_a = (v791_p->a)->mem;
        int v941_a = v839_a * 2;
        v843_a[v941_a] = v841_a;
        int * v845_a = (v791_p->a)->mem;
        int v944_a = (v839_a * 2) + 1;
        v845_a[v944_a] = v842_a;
        ;
      } else {
        ;
      }
      int * v850_a = (v791_p->a)->mem;
      int v949_a = ((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1)) * 2;
      int v851_a = v850_a[v949_a];
      int v950_a = (((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1)) * 2) + 1;
      int v852_a = v850_a[v950_a];
      int * v853_a = (v791_p->a)->cache_vals;
      int v952_a = ((4 + ((((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1)) & 3) * 2)) + ((((v831_a + ((~(((v833_a ^ -1) | (-(v833_a ^ -1))) >> 31)) & 2)) - (v834_a + ((~(((v835_a ^ -1) | (-(v835_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v853_a[v952_a] = v851_a;
      int * v855_a = (v791_p->a)->cache_vals;
      int v955_a = (((4 + ((((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1)) & 3) * 2)) + ((((v831_a + ((~(((v833_a ^ -1) | (-(v833_a ^ -1))) >> 31)) & 2)) - (v834_a + ((~(((v835_a ^ -1) | (-(v835_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v855_a[v955_a] = v852_a;
      int * v857_a = (v791_p->a)->cache_tags;
      int v958_a = (int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1);
      v857_a[v934_a] = v958_a;
      int * v859_a = (v791_p->a)->cache_dirty;
      v859_a[v934_a] = 0;
      int * v861_a = (v791_p->a)->cache_age;
      v861_a[v934_a] = 1;
      int * v863_a = (v791_p->a)->cache_age;
      int v864_a = v863_a[v934_a];
      int v865_a = v863_a[v908_a];
      int v964_a = v865_a + ((int)((unsigned int)(v865_a - v864_a) >> 31));
      v863_a[v908_a] = v964_a;
      int * v867_a = (v791_p->a)->cache_age;
      int v868_a = v867_a[v909_a];
      int v966_a = v868_a + ((int)((unsigned int)(v868_a - v864_a) >> 31));
      v867_a[v909_a] = v966_a;
      int * v870_a = (v791_p->a)->cache_age;
      v870_a[v934_a] = 0;
      v873_a = v934_a;
    }
    int * v874_a = (v791_p->a)->cache_vals;
    int v969_a = v873_a * 2;
    int v875_a = v874_a[v969_a];
    int v970_a = (v873_a * 2) + 1;
    int v876_a = v874_a[v970_a];
    int v971_a = (((((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1)) & 1) * 2) + ((((v815_a + ((~(((v817_a ^ -1) | (-(v817_a ^ -1))) >> 31)) & 2)) - (v818_a + ((~(((v819_a ^ -1) | (-(v819_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v874_a[v971_a] = v875_a;
    int * v878_a = (v791_p->a)->cache_vals;
    int v974_a = ((((((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1)) & 1) * 2) + ((((v815_a + ((~(((v817_a ^ -1) | (-(v817_a ^ -1))) >> 31)) & 2)) - (v818_a + ((~(((v819_a ^ -1) | (-(v819_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v878_a[v974_a] = v876_a;
    int * v880_a = (v791_p->a)->cache_tags;
    int v977_a = ((((int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1)) & 1) * 2) + ((((v815_a + ((~(((v817_a ^ -1) | (-(v817_a ^ -1))) >> 31)) & 2)) - (v818_a + ((~(((v819_a ^ -1) | (-(v819_a ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v978_a = (int)((unsigned int)((int)((unsigned int)v795_a >> 2)) >> 1);
    v880_a[v977_a] = v978_a;
    int * v882_a = (v791_p->a)->cache_dirty;
    v882_a[v977_a] = 0;
    int * v884_a = (v791_p->a)->cache_age;
    v884_a[v977_a] = 1;
    int * v886_a = (v791_p->a)->cache_age;
    int v887_a = v886_a[v977_a];
    int v888_a = v886_a[v906_a];
    int v984_a = v888_a + ((int)((unsigned int)(v888_a - v887_a) >> 31));
    v886_a[v906_a] = v984_a;
    int * v890_a = (v791_p->a)->cache_age;
    int v891_a = v890_a[v907_a];
    int v986_a = v891_a + ((int)((unsigned int)(v891_a - v887_a) >> 31));
    v890_a[v907_a] = v986_a;
    int * v893_a = (v791_p->a)->cache_age;
    v893_a[v977_a] = 0;
    v896_a = v977_a;
  }
  int v896_b;
  if (v911_b) {
    int * v804_b = (v791_p->b)->cache_age;
    int v913_b = ((((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1)) & 1) * 2) + ((~(((v798_b ^ ((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1))) | (-(v798_b ^ ((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1))))) >> 31)) & 1);
    int v805_b = v804_b[v913_b];
    int v806_b = v804_b[v906_b];
    int v914_b = v806_b + ((int)((unsigned int)(v806_b - v805_b) >> 31));
    v804_b[v906_b] = v914_b;
    int * v808_b = (v791_p->b)->cache_age;
    int v809_b = v808_b[v907_b];
    int v916_b = v809_b + ((int)((unsigned int)(v809_b - v805_b) >> 31));
    v808_b[v907_b] = v916_b;
    int * v811_b = (v791_p->b)->cache_age;
    v811_b[v913_b] = 0;
    v896_b = v913_b;
  } else {
    int * v814_b = (v791_p->b)->cache_age;
    int v920_b = (((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1)) & 1) * 2;
    int v815_b = v814_b[v920_b];
    int * v816_b = (v791_p->b)->cache_tags;
    int v817_b = v816_b[v920_b];
    int v818_b = v814_b[v907_b];
    int v819_b = v816_b[v907_b];
    bool v922_b = !(((~(((v799_b ^ ((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1))) | (-(v799_b ^ ((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1))))) >> 31)) | (~(((v800_b ^ ((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1))) | (-(v800_b ^ ((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1))))) >> 31))) == 0);
    int v873_b;
    if (v922_b) {
      int * v820_b = (v791_p->b)->cache_age;
      int v924_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1)) & 3) * 2)) + ((~(((v800_b ^ ((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1))) | (-(v800_b ^ ((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1))))) >> 31)) & 1);
      int v821_b = v820_b[v924_b];
      int v822_b = v820_b[v908_b];
      int v925_b = v822_b + ((int)((unsigned int)(v822_b - v821_b) >> 31));
      v820_b[v908_b] = v925_b;
      int * v824_b = (v791_p->b)->cache_age;
      int v825_b = v824_b[v909_b];
      int v927_b = v825_b + ((int)((unsigned int)(v825_b - v821_b) >> 31));
      v824_b[v909_b] = v927_b;
      int * v827_b = (v791_p->b)->cache_age;
      v827_b[v924_b] = 0;
      v873_b = v924_b;
    } else {
      int * v830_b = (v791_p->b)->cache_age;
      int v931_b = 4 + ((((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1)) & 3) * 2);
      int v831_b = v830_b[v931_b];
      int * v832_b = (v791_p->b)->cache_tags;
      int v833_b = v832_b[v931_b];
      int v834_b = v830_b[v909_b];
      int v835_b = v832_b[v909_b];
      int * v836_b = (v791_p->b)->cache_dirty;
      int v934_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1)) & 3) * 2)) + ((((v831_b + ((~(((v833_b ^ -1) | (-(v833_b ^ -1))) >> 31)) & 2)) - (v834_b + ((~(((v835_b ^ -1) | (-(v835_b ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v837_b = v836_b[v934_b];
      bool v935_b = !(v837_b == 0);
      if (v935_b) {
        int * v838_b = (v791_p->b)->cache_tags;
        int v839_b = v838_b[v934_b];
        int * v840_b = (v791_p->b)->cache_vals;
        int v938_b = ((4 + ((((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1)) & 3) * 2)) + ((((v831_b + ((~(((v833_b ^ -1) | (-(v833_b ^ -1))) >> 31)) & 2)) - (v834_b + ((~(((v835_b ^ -1) | (-(v835_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v841_b = v840_b[v938_b];
        int v939_b = (((4 + ((((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1)) & 3) * 2)) + ((((v831_b + ((~(((v833_b ^ -1) | (-(v833_b ^ -1))) >> 31)) & 2)) - (v834_b + ((~(((v835_b ^ -1) | (-(v835_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v842_b = v840_b[v939_b];
        int * v843_b = (v791_p->b)->mem;
        int v941_b = v839_b * 2;
        v843_b[v941_b] = v841_b;
        int * v845_b = (v791_p->b)->mem;
        int v944_b = (v839_b * 2) + 1;
        v845_b[v944_b] = v842_b;
        ;
      } else {
        ;
      }
      int * v850_b = (v791_p->b)->mem;
      int v949_b = ((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1)) * 2;
      int v851_b = v850_b[v949_b];
      int v950_b = (((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1)) * 2) + 1;
      int v852_b = v850_b[v950_b];
      int * v853_b = (v791_p->b)->cache_vals;
      int v952_b = ((4 + ((((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1)) & 3) * 2)) + ((((v831_b + ((~(((v833_b ^ -1) | (-(v833_b ^ -1))) >> 31)) & 2)) - (v834_b + ((~(((v835_b ^ -1) | (-(v835_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v853_b[v952_b] = v851_b;
      int * v855_b = (v791_p->b)->cache_vals;
      int v955_b = (((4 + ((((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1)) & 3) * 2)) + ((((v831_b + ((~(((v833_b ^ -1) | (-(v833_b ^ -1))) >> 31)) & 2)) - (v834_b + ((~(((v835_b ^ -1) | (-(v835_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v855_b[v955_b] = v852_b;
      int * v857_b = (v791_p->b)->cache_tags;
      int v958_b = (int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1);
      v857_b[v934_b] = v958_b;
      int * v859_b = (v791_p->b)->cache_dirty;
      v859_b[v934_b] = 0;
      int * v861_b = (v791_p->b)->cache_age;
      v861_b[v934_b] = 1;
      int * v863_b = (v791_p->b)->cache_age;
      int v864_b = v863_b[v934_b];
      int v865_b = v863_b[v908_b];
      int v964_b = v865_b + ((int)((unsigned int)(v865_b - v864_b) >> 31));
      v863_b[v908_b] = v964_b;
      int * v867_b = (v791_p->b)->cache_age;
      int v868_b = v867_b[v909_b];
      int v966_b = v868_b + ((int)((unsigned int)(v868_b - v864_b) >> 31));
      v867_b[v909_b] = v966_b;
      int * v870_b = (v791_p->b)->cache_age;
      v870_b[v934_b] = 0;
      v873_b = v934_b;
    }
    int * v874_b = (v791_p->b)->cache_vals;
    int v969_b = v873_b * 2;
    int v875_b = v874_b[v969_b];
    int v970_b = (v873_b * 2) + 1;
    int v876_b = v874_b[v970_b];
    int v971_b = (((((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1)) & 1) * 2) + ((((v815_b + ((~(((v817_b ^ -1) | (-(v817_b ^ -1))) >> 31)) & 2)) - (v818_b + ((~(((v819_b ^ -1) | (-(v819_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v874_b[v971_b] = v875_b;
    int * v878_b = (v791_p->b)->cache_vals;
    int v974_b = ((((((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1)) & 1) * 2) + ((((v815_b + ((~(((v817_b ^ -1) | (-(v817_b ^ -1))) >> 31)) & 2)) - (v818_b + ((~(((v819_b ^ -1) | (-(v819_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v878_b[v974_b] = v876_b;
    int * v880_b = (v791_p->b)->cache_tags;
    int v977_b = ((((int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1)) & 1) * 2) + ((((v815_b + ((~(((v817_b ^ -1) | (-(v817_b ^ -1))) >> 31)) & 2)) - (v818_b + ((~(((v819_b ^ -1) | (-(v819_b ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v978_b = (int)((unsigned int)((int)((unsigned int)v795_b >> 2)) >> 1);
    v880_b[v977_b] = v978_b;
    int * v882_b = (v791_p->b)->cache_dirty;
    v882_b[v977_b] = 0;
    int * v884_b = (v791_p->b)->cache_age;
    v884_b[v977_b] = 1;
    int * v886_b = (v791_p->b)->cache_age;
    int v887_b = v886_b[v977_b];
    int v888_b = v886_b[v906_b];
    int v984_b = v888_b + ((int)((unsigned int)(v888_b - v887_b) >> 31));
    v886_b[v906_b] = v984_b;
    int * v890_b = (v791_p->b)->cache_age;
    int v891_b = v890_b[v907_b];
    int v986_b = v891_b + ((int)((unsigned int)(v891_b - v887_b) >> 31));
    v890_b[v907_b] = v986_b;
    int * v893_b = (v791_p->b)->cache_age;
    v893_b[v977_b] = 0;
    v896_b = v977_b;
  }
  int v989_a = (v896_a * 2) + (((int)((unsigned int)v795_a >> 2)) & 1);
  int v989_b = (v896_b * 2) + (((int)((unsigned int)v795_b >> 2)) & 1);
  int v897_a = v803_a[v989_a];
  int v897_b = v803_b[v989_b];
  int * v898_a = (v791_p->a)->regs;
  int * v898_b = (v791_p->b)->regs;
  v898_a[7] = v897_a;
  v898_b[7] = v897_b;
  struct StateT2 * v900_p = slot_17(v791_p);
  return v900_p;
}

struct StateT2 * slot_5(struct StateT2 * v251_p) {
  lockstep_assert(((v251_p->a)->timer) == ((v251_p->b)->timer));
  lockstep_assume(((v251_p->a)->timer) == ((v251_p->b)->timer));
  int v252_a = (v251_p->a)->timer;
  int v252_b = (v251_p->b)->timer;
  int v259_a = v252_a + 1;
  int v259_b = v252_b + 1;
  (v251_p->a)->timer = v259_a;
  (v251_p->b)->timer = v259_b;
  int * v254_a = (v251_p->a)->regs;
  int * v254_b = (v251_p->b)->regs;
  int v255_a = v254_a[6];
  int v255_b = v254_b[6];
  int v262_a = v255_a << 2;
  int v262_b = v255_b << 2;
  v254_a[6] = v262_a;
  v254_b[6] = v262_b;
  struct StateT2 * v257_p = slot_6(v251_p);
  return v257_p;
}

struct StateT2 * slot_2(struct StateT2 * v206_p) {
  lockstep_assert(((v206_p->a)->timer) == ((v206_p->b)->timer));
  lockstep_assume(((v206_p->a)->timer) == ((v206_p->b)->timer));
  int v207_a = (v206_p->a)->timer;
  int v207_b = (v206_p->b)->timer;
  int v215_a = v207_a + 1;
  int v215_b = v207_b + 1;
  (v206_p->a)->timer = v215_a;
  (v206_p->b)->timer = v215_b;
  int * v209_a = (v206_p->a)->regs;
  int * v209_b = (v206_p->b)->regs;
  int v210_a = v209_a[5];
  int v210_b = v209_b[5];
  int v211_a = v209_a[9];
  int v211_b = v209_b[9];
  int v219_a = v210_a ^ v211_a;
  int v219_b = v210_b ^ v211_b;
  v209_a[5] = v219_a;
  v209_b[5] = v219_b;
  struct StateT2 * v213_p = slot_3(v206_p);
  return v213_p;
}

struct StateT2 * slot_7(struct StateT2 * v469_p) {
  lockstep_assert(((v469_p->a)->timer) == ((v469_p->b)->timer));
  lockstep_assume(((v469_p->a)->timer) == ((v469_p->b)->timer));
  int v470_a = (v469_p->a)->timer;
  int v470_b = (v469_p->b)->timer;
  int v478_a = v470_a + 1;
  int v478_b = v470_b + 1;
  (v469_p->a)->timer = v478_a;
  (v469_p->b)->timer = v478_b;
  int * v472_a = (v469_p->a)->regs;
  int * v472_b = (v469_p->b)->regs;
  int v473_a = v472_a[5];
  int v473_b = v472_b[5];
  int v474_a = v472_a[7];
  int v474_b = v472_b[7];
  int v482_a = v473_a ^ v474_a;
  int v482_b = v473_b ^ v474_b;
  v472_a[5] = v482_a;
  v472_b[5] = v482_b;
  struct StateT2 * v476_p = slot_8(v469_p);
  return v476_p;
}

struct StateT2 * slot_21(struct StateT2 * v1054_p) {
  lockstep_assert(((v1054_p->a)->timer) == ((v1054_p->b)->timer));
  lockstep_assume(((v1054_p->a)->timer) == ((v1054_p->b)->timer));
  int v1055_a = (v1054_p->a)->timer;
  int v1055_b = (v1054_p->b)->timer;
  int v1165_a = v1055_a + 1;
  int v1165_b = v1055_b + 1;
  (v1054_p->a)->timer = v1165_a;
  (v1054_p->b)->timer = v1165_b;
  int * v1057_a = (v1054_p->a)->regs;
  int * v1057_b = (v1054_p->b)->regs;
  int v1058_a = v1057_a[6];
  int v1058_b = v1057_b[6];
  int * v1059_a = (v1054_p->a)->cache_tags;
  int * v1059_b = (v1054_p->b)->cache_tags;
  int v1169_a = (((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1)) & 1) * 2;
  int v1169_b = (((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1)) & 1) * 2;
  int v1060_a = v1059_a[v1169_a];
  int v1060_b = v1059_b[v1169_b];
  int v1170_a = ((((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1)) & 1) * 2) + 1;
  int v1170_b = ((((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1)) & 1) * 2) + 1;
  int v1061_a = v1059_a[v1170_a];
  int v1061_b = v1059_b[v1170_b];
  int v1171_a = 4 + ((((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1)) & 3) * 2);
  int v1171_b = 4 + ((((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1)) & 3) * 2);
  int v1062_a = v1059_a[v1171_a];
  int v1062_b = v1059_b[v1171_b];
  int v1172_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1172_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1063_a = v1059_a[v1172_a];
  int v1063_b = v1059_b[v1172_b];
  int v1064_a = (v1054_p->a)->timer;
  int v1064_b = (v1054_p->b)->timer;
  int v1173_a = v1064_a + ((100 ^ (((~(((v1062_a ^ ((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1))) | (-(v1062_a ^ ((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1))))) >> 31)) | (~(((v1063_a ^ ((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1))) | (-(v1063_a ^ ((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1060_a ^ ((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1))) | (-(v1060_a ^ ((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1))))) >> 31)) | (~(((v1061_a ^ ((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1))) | (-(v1061_a ^ ((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1062_a ^ ((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1))) | (-(v1062_a ^ ((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1))))) >> 31)) | (~(((v1063_a ^ ((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1))) | (-(v1063_a ^ ((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1))))) >> 31))) & 104)))));
  int v1173_b = v1064_b + ((100 ^ (((~(((v1062_b ^ ((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1))) | (-(v1062_b ^ ((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1))))) >> 31)) | (~(((v1063_b ^ ((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1))) | (-(v1063_b ^ ((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1060_b ^ ((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1))) | (-(v1060_b ^ ((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1))))) >> 31)) | (~(((v1061_b ^ ((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1))) | (-(v1061_b ^ ((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1062_b ^ ((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1))) | (-(v1062_b ^ ((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1))))) >> 31)) | (~(((v1063_b ^ ((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1))) | (-(v1063_b ^ ((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1))))) >> 31))) & 104)))));
  (v1054_p->a)->timer = v1173_a;
  (v1054_p->b)->timer = v1173_b;
  int * v1066_a = (v1054_p->a)->cache_vals;
  int * v1066_b = (v1054_p->b)->cache_vals;
  bool v1174_a = !(((~(((v1060_a ^ ((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1))) | (-(v1060_a ^ ((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1))))) >> 31)) | (~(((v1061_a ^ ((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1))) | (-(v1061_a ^ ((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1))))) >> 31))) == 0);
  bool v1174_b = !(((~(((v1060_b ^ ((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1))) | (-(v1060_b ^ ((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1))))) >> 31)) | (~(((v1061_b ^ ((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1))) | (-(v1061_b ^ ((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1))))) >> 31))) == 0);
  int v1159_a;
  if (v1174_a) {
    int * v1067_a = (v1054_p->a)->cache_age;
    int v1176_a = ((((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1)) & 1) * 2) + ((~(((v1061_a ^ ((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1))) | (-(v1061_a ^ ((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1))))) >> 31)) & 1);
    int v1068_a = v1067_a[v1176_a];
    int v1069_a = v1067_a[v1169_a];
    int v1177_a = v1069_a + ((int)((unsigned int)(v1069_a - v1068_a) >> 31));
    v1067_a[v1169_a] = v1177_a;
    int * v1071_a = (v1054_p->a)->cache_age;
    int v1072_a = v1071_a[v1170_a];
    int v1179_a = v1072_a + ((int)((unsigned int)(v1072_a - v1068_a) >> 31));
    v1071_a[v1170_a] = v1179_a;
    int * v1074_a = (v1054_p->a)->cache_age;
    v1074_a[v1176_a] = 0;
    v1159_a = v1176_a;
  } else {
    int * v1077_a = (v1054_p->a)->cache_age;
    int v1183_a = (((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1)) & 1) * 2;
    int v1078_a = v1077_a[v1183_a];
    int * v1079_a = (v1054_p->a)->cache_tags;
    int v1080_a = v1079_a[v1183_a];
    int v1081_a = v1077_a[v1170_a];
    int v1082_a = v1079_a[v1170_a];
    bool v1185_a = !(((~(((v1062_a ^ ((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1))) | (-(v1062_a ^ ((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1))))) >> 31)) | (~(((v1063_a ^ ((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1))) | (-(v1063_a ^ ((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1))))) >> 31))) == 0);
    int v1136_a;
    if (v1185_a) {
      int * v1083_a = (v1054_p->a)->cache_age;
      int v1187_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1)) & 3) * 2)) + ((~(((v1063_a ^ ((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1))) | (-(v1063_a ^ ((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1))))) >> 31)) & 1);
      int v1084_a = v1083_a[v1187_a];
      int v1085_a = v1083_a[v1171_a];
      int v1188_a = v1085_a + ((int)((unsigned int)(v1085_a - v1084_a) >> 31));
      v1083_a[v1171_a] = v1188_a;
      int * v1087_a = (v1054_p->a)->cache_age;
      int v1088_a = v1087_a[v1172_a];
      int v1190_a = v1088_a + ((int)((unsigned int)(v1088_a - v1084_a) >> 31));
      v1087_a[v1172_a] = v1190_a;
      int * v1090_a = (v1054_p->a)->cache_age;
      v1090_a[v1187_a] = 0;
      v1136_a = v1187_a;
    } else {
      int * v1093_a = (v1054_p->a)->cache_age;
      int v1194_a = 4 + ((((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1)) & 3) * 2);
      int v1094_a = v1093_a[v1194_a];
      int * v1095_a = (v1054_p->a)->cache_tags;
      int v1096_a = v1095_a[v1194_a];
      int v1097_a = v1093_a[v1172_a];
      int v1098_a = v1095_a[v1172_a];
      int * v1099_a = (v1054_p->a)->cache_dirty;
      int v1197_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1)) & 3) * 2)) + ((((v1094_a + ((~(((v1096_a ^ -1) | (-(v1096_a ^ -1))) >> 31)) & 2)) - (v1097_a + ((~(((v1098_a ^ -1) | (-(v1098_a ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1100_a = v1099_a[v1197_a];
      bool v1198_a = !(v1100_a == 0);
      if (v1198_a) {
        int * v1101_a = (v1054_p->a)->cache_tags;
        int v1102_a = v1101_a[v1197_a];
        int * v1103_a = (v1054_p->a)->cache_vals;
        int v1201_a = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1)) & 3) * 2)) + ((((v1094_a + ((~(((v1096_a ^ -1) | (-(v1096_a ^ -1))) >> 31)) & 2)) - (v1097_a + ((~(((v1098_a ^ -1) | (-(v1098_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1104_a = v1103_a[v1201_a];
        int v1202_a = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1)) & 3) * 2)) + ((((v1094_a + ((~(((v1096_a ^ -1) | (-(v1096_a ^ -1))) >> 31)) & 2)) - (v1097_a + ((~(((v1098_a ^ -1) | (-(v1098_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1105_a = v1103_a[v1202_a];
        int * v1106_a = (v1054_p->a)->mem;
        int v1204_a = v1102_a * 2;
        v1106_a[v1204_a] = v1104_a;
        int * v1108_a = (v1054_p->a)->mem;
        int v1207_a = (v1102_a * 2) + 1;
        v1108_a[v1207_a] = v1105_a;
        ;
      } else {
        ;
      }
      int * v1113_a = (v1054_p->a)->mem;
      int v1212_a = ((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1)) * 2;
      int v1114_a = v1113_a[v1212_a];
      int v1213_a = (((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1)) * 2) + 1;
      int v1115_a = v1113_a[v1213_a];
      int * v1116_a = (v1054_p->a)->cache_vals;
      int v1215_a = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1)) & 3) * 2)) + ((((v1094_a + ((~(((v1096_a ^ -1) | (-(v1096_a ^ -1))) >> 31)) & 2)) - (v1097_a + ((~(((v1098_a ^ -1) | (-(v1098_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1116_a[v1215_a] = v1114_a;
      int * v1118_a = (v1054_p->a)->cache_vals;
      int v1218_a = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1)) & 3) * 2)) + ((((v1094_a + ((~(((v1096_a ^ -1) | (-(v1096_a ^ -1))) >> 31)) & 2)) - (v1097_a + ((~(((v1098_a ^ -1) | (-(v1098_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1118_a[v1218_a] = v1115_a;
      int * v1120_a = (v1054_p->a)->cache_tags;
      int v1221_a = (int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1);
      v1120_a[v1197_a] = v1221_a;
      int * v1122_a = (v1054_p->a)->cache_dirty;
      v1122_a[v1197_a] = 0;
      int * v1124_a = (v1054_p->a)->cache_age;
      v1124_a[v1197_a] = 1;
      int * v1126_a = (v1054_p->a)->cache_age;
      int v1127_a = v1126_a[v1197_a];
      int v1128_a = v1126_a[v1171_a];
      int v1227_a = v1128_a + ((int)((unsigned int)(v1128_a - v1127_a) >> 31));
      v1126_a[v1171_a] = v1227_a;
      int * v1130_a = (v1054_p->a)->cache_age;
      int v1131_a = v1130_a[v1172_a];
      int v1229_a = v1131_a + ((int)((unsigned int)(v1131_a - v1127_a) >> 31));
      v1130_a[v1172_a] = v1229_a;
      int * v1133_a = (v1054_p->a)->cache_age;
      v1133_a[v1197_a] = 0;
      v1136_a = v1197_a;
    }
    int * v1137_a = (v1054_p->a)->cache_vals;
    int v1232_a = v1136_a * 2;
    int v1138_a = v1137_a[v1232_a];
    int v1233_a = (v1136_a * 2) + 1;
    int v1139_a = v1137_a[v1233_a];
    int v1234_a = (((((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1)) & 1) * 2) + ((((v1078_a + ((~(((v1080_a ^ -1) | (-(v1080_a ^ -1))) >> 31)) & 2)) - (v1081_a + ((~(((v1082_a ^ -1) | (-(v1082_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1137_a[v1234_a] = v1138_a;
    int * v1141_a = (v1054_p->a)->cache_vals;
    int v1237_a = ((((((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1)) & 1) * 2) + ((((v1078_a + ((~(((v1080_a ^ -1) | (-(v1080_a ^ -1))) >> 31)) & 2)) - (v1081_a + ((~(((v1082_a ^ -1) | (-(v1082_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1141_a[v1237_a] = v1139_a;
    int * v1143_a = (v1054_p->a)->cache_tags;
    int v1240_a = ((((int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1)) & 1) * 2) + ((((v1078_a + ((~(((v1080_a ^ -1) | (-(v1080_a ^ -1))) >> 31)) & 2)) - (v1081_a + ((~(((v1082_a ^ -1) | (-(v1082_a ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1241_a = (int)((unsigned int)((int)((unsigned int)v1058_a >> 2)) >> 1);
    v1143_a[v1240_a] = v1241_a;
    int * v1145_a = (v1054_p->a)->cache_dirty;
    v1145_a[v1240_a] = 0;
    int * v1147_a = (v1054_p->a)->cache_age;
    v1147_a[v1240_a] = 1;
    int * v1149_a = (v1054_p->a)->cache_age;
    int v1150_a = v1149_a[v1240_a];
    int v1151_a = v1149_a[v1169_a];
    int v1247_a = v1151_a + ((int)((unsigned int)(v1151_a - v1150_a) >> 31));
    v1149_a[v1169_a] = v1247_a;
    int * v1153_a = (v1054_p->a)->cache_age;
    int v1154_a = v1153_a[v1170_a];
    int v1249_a = v1154_a + ((int)((unsigned int)(v1154_a - v1150_a) >> 31));
    v1153_a[v1170_a] = v1249_a;
    int * v1156_a = (v1054_p->a)->cache_age;
    v1156_a[v1240_a] = 0;
    v1159_a = v1240_a;
  }
  int v1159_b;
  if (v1174_b) {
    int * v1067_b = (v1054_p->b)->cache_age;
    int v1176_b = ((((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1)) & 1) * 2) + ((~(((v1061_b ^ ((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1))) | (-(v1061_b ^ ((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1))))) >> 31)) & 1);
    int v1068_b = v1067_b[v1176_b];
    int v1069_b = v1067_b[v1169_b];
    int v1177_b = v1069_b + ((int)((unsigned int)(v1069_b - v1068_b) >> 31));
    v1067_b[v1169_b] = v1177_b;
    int * v1071_b = (v1054_p->b)->cache_age;
    int v1072_b = v1071_b[v1170_b];
    int v1179_b = v1072_b + ((int)((unsigned int)(v1072_b - v1068_b) >> 31));
    v1071_b[v1170_b] = v1179_b;
    int * v1074_b = (v1054_p->b)->cache_age;
    v1074_b[v1176_b] = 0;
    v1159_b = v1176_b;
  } else {
    int * v1077_b = (v1054_p->b)->cache_age;
    int v1183_b = (((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1)) & 1) * 2;
    int v1078_b = v1077_b[v1183_b];
    int * v1079_b = (v1054_p->b)->cache_tags;
    int v1080_b = v1079_b[v1183_b];
    int v1081_b = v1077_b[v1170_b];
    int v1082_b = v1079_b[v1170_b];
    bool v1185_b = !(((~(((v1062_b ^ ((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1))) | (-(v1062_b ^ ((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1))))) >> 31)) | (~(((v1063_b ^ ((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1))) | (-(v1063_b ^ ((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1))))) >> 31))) == 0);
    int v1136_b;
    if (v1185_b) {
      int * v1083_b = (v1054_p->b)->cache_age;
      int v1187_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1)) & 3) * 2)) + ((~(((v1063_b ^ ((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1))) | (-(v1063_b ^ ((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1))))) >> 31)) & 1);
      int v1084_b = v1083_b[v1187_b];
      int v1085_b = v1083_b[v1171_b];
      int v1188_b = v1085_b + ((int)((unsigned int)(v1085_b - v1084_b) >> 31));
      v1083_b[v1171_b] = v1188_b;
      int * v1087_b = (v1054_p->b)->cache_age;
      int v1088_b = v1087_b[v1172_b];
      int v1190_b = v1088_b + ((int)((unsigned int)(v1088_b - v1084_b) >> 31));
      v1087_b[v1172_b] = v1190_b;
      int * v1090_b = (v1054_p->b)->cache_age;
      v1090_b[v1187_b] = 0;
      v1136_b = v1187_b;
    } else {
      int * v1093_b = (v1054_p->b)->cache_age;
      int v1194_b = 4 + ((((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1)) & 3) * 2);
      int v1094_b = v1093_b[v1194_b];
      int * v1095_b = (v1054_p->b)->cache_tags;
      int v1096_b = v1095_b[v1194_b];
      int v1097_b = v1093_b[v1172_b];
      int v1098_b = v1095_b[v1172_b];
      int * v1099_b = (v1054_p->b)->cache_dirty;
      int v1197_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1)) & 3) * 2)) + ((((v1094_b + ((~(((v1096_b ^ -1) | (-(v1096_b ^ -1))) >> 31)) & 2)) - (v1097_b + ((~(((v1098_b ^ -1) | (-(v1098_b ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1100_b = v1099_b[v1197_b];
      bool v1198_b = !(v1100_b == 0);
      if (v1198_b) {
        int * v1101_b = (v1054_p->b)->cache_tags;
        int v1102_b = v1101_b[v1197_b];
        int * v1103_b = (v1054_p->b)->cache_vals;
        int v1201_b = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1)) & 3) * 2)) + ((((v1094_b + ((~(((v1096_b ^ -1) | (-(v1096_b ^ -1))) >> 31)) & 2)) - (v1097_b + ((~(((v1098_b ^ -1) | (-(v1098_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1104_b = v1103_b[v1201_b];
        int v1202_b = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1)) & 3) * 2)) + ((((v1094_b + ((~(((v1096_b ^ -1) | (-(v1096_b ^ -1))) >> 31)) & 2)) - (v1097_b + ((~(((v1098_b ^ -1) | (-(v1098_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1105_b = v1103_b[v1202_b];
        int * v1106_b = (v1054_p->b)->mem;
        int v1204_b = v1102_b * 2;
        v1106_b[v1204_b] = v1104_b;
        int * v1108_b = (v1054_p->b)->mem;
        int v1207_b = (v1102_b * 2) + 1;
        v1108_b[v1207_b] = v1105_b;
        ;
      } else {
        ;
      }
      int * v1113_b = (v1054_p->b)->mem;
      int v1212_b = ((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1)) * 2;
      int v1114_b = v1113_b[v1212_b];
      int v1213_b = (((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1)) * 2) + 1;
      int v1115_b = v1113_b[v1213_b];
      int * v1116_b = (v1054_p->b)->cache_vals;
      int v1215_b = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1)) & 3) * 2)) + ((((v1094_b + ((~(((v1096_b ^ -1) | (-(v1096_b ^ -1))) >> 31)) & 2)) - (v1097_b + ((~(((v1098_b ^ -1) | (-(v1098_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1116_b[v1215_b] = v1114_b;
      int * v1118_b = (v1054_p->b)->cache_vals;
      int v1218_b = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1)) & 3) * 2)) + ((((v1094_b + ((~(((v1096_b ^ -1) | (-(v1096_b ^ -1))) >> 31)) & 2)) - (v1097_b + ((~(((v1098_b ^ -1) | (-(v1098_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1118_b[v1218_b] = v1115_b;
      int * v1120_b = (v1054_p->b)->cache_tags;
      int v1221_b = (int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1);
      v1120_b[v1197_b] = v1221_b;
      int * v1122_b = (v1054_p->b)->cache_dirty;
      v1122_b[v1197_b] = 0;
      int * v1124_b = (v1054_p->b)->cache_age;
      v1124_b[v1197_b] = 1;
      int * v1126_b = (v1054_p->b)->cache_age;
      int v1127_b = v1126_b[v1197_b];
      int v1128_b = v1126_b[v1171_b];
      int v1227_b = v1128_b + ((int)((unsigned int)(v1128_b - v1127_b) >> 31));
      v1126_b[v1171_b] = v1227_b;
      int * v1130_b = (v1054_p->b)->cache_age;
      int v1131_b = v1130_b[v1172_b];
      int v1229_b = v1131_b + ((int)((unsigned int)(v1131_b - v1127_b) >> 31));
      v1130_b[v1172_b] = v1229_b;
      int * v1133_b = (v1054_p->b)->cache_age;
      v1133_b[v1197_b] = 0;
      v1136_b = v1197_b;
    }
    int * v1137_b = (v1054_p->b)->cache_vals;
    int v1232_b = v1136_b * 2;
    int v1138_b = v1137_b[v1232_b];
    int v1233_b = (v1136_b * 2) + 1;
    int v1139_b = v1137_b[v1233_b];
    int v1234_b = (((((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1)) & 1) * 2) + ((((v1078_b + ((~(((v1080_b ^ -1) | (-(v1080_b ^ -1))) >> 31)) & 2)) - (v1081_b + ((~(((v1082_b ^ -1) | (-(v1082_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1137_b[v1234_b] = v1138_b;
    int * v1141_b = (v1054_p->b)->cache_vals;
    int v1237_b = ((((((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1)) & 1) * 2) + ((((v1078_b + ((~(((v1080_b ^ -1) | (-(v1080_b ^ -1))) >> 31)) & 2)) - (v1081_b + ((~(((v1082_b ^ -1) | (-(v1082_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1141_b[v1237_b] = v1139_b;
    int * v1143_b = (v1054_p->b)->cache_tags;
    int v1240_b = ((((int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1)) & 1) * 2) + ((((v1078_b + ((~(((v1080_b ^ -1) | (-(v1080_b ^ -1))) >> 31)) & 2)) - (v1081_b + ((~(((v1082_b ^ -1) | (-(v1082_b ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1241_b = (int)((unsigned int)((int)((unsigned int)v1058_b >> 2)) >> 1);
    v1143_b[v1240_b] = v1241_b;
    int * v1145_b = (v1054_p->b)->cache_dirty;
    v1145_b[v1240_b] = 0;
    int * v1147_b = (v1054_p->b)->cache_age;
    v1147_b[v1240_b] = 1;
    int * v1149_b = (v1054_p->b)->cache_age;
    int v1150_b = v1149_b[v1240_b];
    int v1151_b = v1149_b[v1169_b];
    int v1247_b = v1151_b + ((int)((unsigned int)(v1151_b - v1150_b) >> 31));
    v1149_b[v1169_b] = v1247_b;
    int * v1153_b = (v1054_p->b)->cache_age;
    int v1154_b = v1153_b[v1170_b];
    int v1249_b = v1154_b + ((int)((unsigned int)(v1154_b - v1150_b) >> 31));
    v1153_b[v1170_b] = v1249_b;
    int * v1156_b = (v1054_p->b)->cache_age;
    v1156_b[v1240_b] = 0;
    v1159_b = v1240_b;
  }
  int v1252_a = (v1159_a * 2) + (((int)((unsigned int)v1058_a >> 2)) & 1);
  int v1252_b = (v1159_b * 2) + (((int)((unsigned int)v1058_b >> 2)) & 1);
  int v1160_a = v1066_a[v1252_a];
  int v1160_b = v1066_b[v1252_b];
  int * v1161_a = (v1054_p->a)->regs;
  int * v1161_b = (v1054_p->b)->regs;
  v1161_a[7] = v1160_a;
  v1161_b[7] = v1160_b;
  struct StateT2 * v1163_p = slot_22(v1054_p);
  return v1163_p;
}

struct StateT2 * slot_3(struct StateT2 * v222_p) {
  lockstep_assert(((v222_p->a)->timer) == ((v222_p->b)->timer));
  lockstep_assume(((v222_p->a)->timer) == ((v222_p->b)->timer));
  int v223_a = (v222_p->a)->timer;
  int v223_b = (v222_p->b)->timer;
  int v230_a = v223_a + 1;
  int v230_b = v223_b + 1;
  (v222_p->a)->timer = v230_a;
  (v222_p->b)->timer = v230_b;
  int * v225_a = (v222_p->a)->regs;
  int * v225_b = (v222_p->b)->regs;
  int v226_a = v225_a[10];
  int v226_b = v225_b[10];
  v225_a[6] = v226_a;
  v225_b[6] = v226_b;
  struct StateT2 * v228_p = slot_4(v222_p);
  return v228_p;
}

struct StateT2 * slot_10(struct StateT2 * v514_p) {
  lockstep_assert(((v514_p->a)->timer) == ((v514_p->b)->timer));
  lockstep_assume(((v514_p->a)->timer) == ((v514_p->b)->timer));
  int v515_a = (v514_p->a)->timer;
  int v515_b = (v514_p->b)->timer;
  int v522_a = v515_a + 1;
  int v522_b = v515_b + 1;
  (v514_p->a)->timer = v522_a;
  (v514_p->b)->timer = v522_b;
  int * v517_a = (v514_p->a)->regs;
  int * v517_b = (v514_p->b)->regs;
  int v518_a = v517_a[6];
  int v518_b = v517_b[6];
  int v525_a = v518_a << 2;
  int v525_b = v518_b << 2;
  v517_a[6] = v525_a;
  v517_b[6] = v525_b;
  struct StateT2 * v520_p = slot_11(v514_p);
  return v520_p;
}

struct StateT2 * slot_1(struct StateT2 * v15_p) {
  lockstep_assert(((v15_p->a)->timer) == ((v15_p->b)->timer));
  lockstep_assume(((v15_p->a)->timer) == ((v15_p->b)->timer));
  int v16_a = (v15_p->a)->timer;
  int v16_b = (v15_p->b)->timer;
  int v124_a = v16_a + 1;
  int v124_b = v16_b + 1;
  (v15_p->a)->timer = v124_a;
  (v15_p->b)->timer = v124_b;
  int * v18_a = (v15_p->a)->cache_tags;
  int * v18_b = (v15_p->b)->cache_tags;
  int v19_a = v18_a[0];
  int v19_b = v18_b[0];
  int v20_a = v18_a[1];
  int v20_b = v18_b[1];
  int v21_a = v18_a[8];
  int v21_b = v18_b[8];
  int v22_a = v18_a[9];
  int v22_b = v18_b[9];
  int v23_a = (v15_p->a)->timer;
  int v23_b = (v15_p->b)->timer;
  int v130_a = v23_a + ((100 ^ (((~(((v21_a ^ 10) | (-(v21_a ^ 10))) >> 31)) | (~(((v22_a ^ 10) | (-(v22_a ^ 10))) >> 31))) & 104)) ^ (((~(((v19_a ^ 10) | (-(v19_a ^ 10))) >> 31)) | (~(((v20_a ^ 10) | (-(v20_a ^ 10))) >> 31))) & (1 ^ (100 ^ (((~(((v21_a ^ 10) | (-(v21_a ^ 10))) >> 31)) | (~(((v22_a ^ 10) | (-(v22_a ^ 10))) >> 31))) & 104)))));
  int v130_b = v23_b + ((100 ^ (((~(((v21_b ^ 10) | (-(v21_b ^ 10))) >> 31)) | (~(((v22_b ^ 10) | (-(v22_b ^ 10))) >> 31))) & 104)) ^ (((~(((v19_b ^ 10) | (-(v19_b ^ 10))) >> 31)) | (~(((v20_b ^ 10) | (-(v20_b ^ 10))) >> 31))) & (1 ^ (100 ^ (((~(((v21_b ^ 10) | (-(v21_b ^ 10))) >> 31)) | (~(((v22_b ^ 10) | (-(v22_b ^ 10))) >> 31))) & 104)))));
  (v15_p->a)->timer = v130_a;
  (v15_p->b)->timer = v130_b;
  int * v25_a = (v15_p->a)->cache_vals;
  int * v25_b = (v15_p->b)->cache_vals;
  bool v131_a = !(((~(((v19_a ^ 10) | (-(v19_a ^ 10))) >> 31)) | (~(((v20_a ^ 10) | (-(v20_a ^ 10))) >> 31))) == 0);
  bool v131_b = !(((~(((v19_b ^ 10) | (-(v19_b ^ 10))) >> 31)) | (~(((v20_b ^ 10) | (-(v20_b ^ 10))) >> 31))) == 0);
  int v118_a;
  if (v131_a) {
    int * v26_a = (v15_p->a)->cache_age;
    int v133_a = (~(((v20_a ^ 10) | (-(v20_a ^ 10))) >> 31)) & 1;
    int v27_a = v26_a[v133_a];
    int v28_a = v26_a[0];
    int v134_a = v28_a + ((int)((unsigned int)(v28_a - v27_a) >> 31));
    v26_a[0] = v134_a;
    int * v30_a = (v15_p->a)->cache_age;
    int v31_a = v30_a[1];
    int v136_a = v31_a + ((int)((unsigned int)(v31_a - v27_a) >> 31));
    v30_a[1] = v136_a;
    int * v33_a = (v15_p->a)->cache_age;
    v33_a[v133_a] = 0;
    v118_a = v133_a;
  } else {
    int * v36_a = (v15_p->a)->cache_age;
    int v37_a = v36_a[0];
    int * v38_a = (v15_p->a)->cache_tags;
    int v39_a = v38_a[0];
    int v40_a = v36_a[1];
    int v41_a = v38_a[1];
    bool v140_a = !(((~(((v21_a ^ 10) | (-(v21_a ^ 10))) >> 31)) | (~(((v22_a ^ 10) | (-(v22_a ^ 10))) >> 31))) == 0);
    int v95_a;
    if (v140_a) {
      int * v42_a = (v15_p->a)->cache_age;
      int v142_a = 8 + ((~(((v22_a ^ 10) | (-(v22_a ^ 10))) >> 31)) & 1);
      int v43_a = v42_a[v142_a];
      int v44_a = v42_a[8];
      int v143_a = v44_a + ((int)((unsigned int)(v44_a - v43_a) >> 31));
      v42_a[8] = v143_a;
      int * v46_a = (v15_p->a)->cache_age;
      int v47_a = v46_a[9];
      int v145_a = v47_a + ((int)((unsigned int)(v47_a - v43_a) >> 31));
      v46_a[9] = v145_a;
      int * v49_a = (v15_p->a)->cache_age;
      v49_a[v142_a] = 0;
      v95_a = v142_a;
    } else {
      int * v52_a = (v15_p->a)->cache_age;
      int v53_a = v52_a[8];
      int * v54_a = (v15_p->a)->cache_tags;
      int v55_a = v54_a[8];
      int v56_a = v52_a[9];
      int v57_a = v54_a[9];
      int * v58_a = (v15_p->a)->cache_dirty;
      int v150_a = 8 + ((((v53_a + ((~(((v55_a ^ -1) | (-(v55_a ^ -1))) >> 31)) & 2)) - (v56_a + ((~(((v57_a ^ -1) | (-(v57_a ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v59_a = v58_a[v150_a];
      bool v151_a = !(v59_a == 0);
      if (v151_a) {
        int * v60_a = (v15_p->a)->cache_tags;
        int v61_a = v60_a[v150_a];
        int * v62_a = (v15_p->a)->cache_vals;
        int v154_a = (8 + ((((v53_a + ((~(((v55_a ^ -1) | (-(v55_a ^ -1))) >> 31)) & 2)) - (v56_a + ((~(((v57_a ^ -1) | (-(v57_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v63_a = v62_a[v154_a];
        int v155_a = ((8 + ((((v53_a + ((~(((v55_a ^ -1) | (-(v55_a ^ -1))) >> 31)) & 2)) - (v56_a + ((~(((v57_a ^ -1) | (-(v57_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v64_a = v62_a[v155_a];
        int * v65_a = (v15_p->a)->mem;
        int v157_a = v61_a * 2;
        v65_a[v157_a] = v63_a;
        int * v67_a = (v15_p->a)->mem;
        int v160_a = (v61_a * 2) + 1;
        v67_a[v160_a] = v64_a;
        ;
      } else {
        ;
      }
      int * v72_a = (v15_p->a)->mem;
      int v73_a = v72_a[20];
      int v74_a = v72_a[21];
      int * v75_a = (v15_p->a)->cache_vals;
      int v168_a = (8 + ((((v53_a + ((~(((v55_a ^ -1) | (-(v55_a ^ -1))) >> 31)) & 2)) - (v56_a + ((~(((v57_a ^ -1) | (-(v57_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v75_a[v168_a] = v73_a;
      int * v77_a = (v15_p->a)->cache_vals;
      int v171_a = ((8 + ((((v53_a + ((~(((v55_a ^ -1) | (-(v55_a ^ -1))) >> 31)) & 2)) - (v56_a + ((~(((v57_a ^ -1) | (-(v57_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v77_a[v171_a] = v74_a;
      int * v79_a = (v15_p->a)->cache_tags;
      v79_a[v150_a] = 10;
      int * v81_a = (v15_p->a)->cache_dirty;
      v81_a[v150_a] = 0;
      int * v83_a = (v15_p->a)->cache_age;
      v83_a[v150_a] = 1;
      int * v85_a = (v15_p->a)->cache_age;
      int v86_a = v85_a[v150_a];
      int v87_a = v85_a[8];
      int v178_a = v87_a + ((int)((unsigned int)(v87_a - v86_a) >> 31));
      v85_a[8] = v178_a;
      int * v89_a = (v15_p->a)->cache_age;
      int v90_a = v89_a[9];
      int v180_a = v90_a + ((int)((unsigned int)(v90_a - v86_a) >> 31));
      v89_a[9] = v180_a;
      int * v92_a = (v15_p->a)->cache_age;
      v92_a[v150_a] = 0;
      v95_a = v150_a;
    }
    int * v96_a = (v15_p->a)->cache_vals;
    int v183_a = v95_a * 2;
    int v97_a = v96_a[v183_a];
    int v184_a = (v95_a * 2) + 1;
    int v98_a = v96_a[v184_a];
    int v185_a = ((((v37_a + ((~(((v39_a ^ -1) | (-(v39_a ^ -1))) >> 31)) & 2)) - (v40_a + ((~(((v41_a ^ -1) | (-(v41_a ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v96_a[v185_a] = v97_a;
    int * v100_a = (v15_p->a)->cache_vals;
    int v188_a = (((((v37_a + ((~(((v39_a ^ -1) | (-(v39_a ^ -1))) >> 31)) & 2)) - (v40_a + ((~(((v41_a ^ -1) | (-(v41_a ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v100_a[v188_a] = v98_a;
    int * v102_a = (v15_p->a)->cache_tags;
    int v191_a = (((v37_a + ((~(((v39_a ^ -1) | (-(v39_a ^ -1))) >> 31)) & 2)) - (v40_a + ((~(((v41_a ^ -1) | (-(v41_a ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v102_a[v191_a] = 10;
    int * v104_a = (v15_p->a)->cache_dirty;
    v104_a[v191_a] = 0;
    int * v106_a = (v15_p->a)->cache_age;
    v106_a[v191_a] = 1;
    int * v108_a = (v15_p->a)->cache_age;
    int v109_a = v108_a[v191_a];
    int v110_a = v108_a[0];
    int v196_a = v110_a + ((int)((unsigned int)(v110_a - v109_a) >> 31));
    v108_a[0] = v196_a;
    int * v112_a = (v15_p->a)->cache_age;
    int v113_a = v112_a[1];
    int v198_a = v113_a + ((int)((unsigned int)(v113_a - v109_a) >> 31));
    v112_a[1] = v198_a;
    int * v115_a = (v15_p->a)->cache_age;
    v115_a[v191_a] = 0;
    v118_a = v191_a;
  }
  int v118_b;
  if (v131_b) {
    int * v26_b = (v15_p->b)->cache_age;
    int v133_b = (~(((v20_b ^ 10) | (-(v20_b ^ 10))) >> 31)) & 1;
    int v27_b = v26_b[v133_b];
    int v28_b = v26_b[0];
    int v134_b = v28_b + ((int)((unsigned int)(v28_b - v27_b) >> 31));
    v26_b[0] = v134_b;
    int * v30_b = (v15_p->b)->cache_age;
    int v31_b = v30_b[1];
    int v136_b = v31_b + ((int)((unsigned int)(v31_b - v27_b) >> 31));
    v30_b[1] = v136_b;
    int * v33_b = (v15_p->b)->cache_age;
    v33_b[v133_b] = 0;
    v118_b = v133_b;
  } else {
    int * v36_b = (v15_p->b)->cache_age;
    int v37_b = v36_b[0];
    int * v38_b = (v15_p->b)->cache_tags;
    int v39_b = v38_b[0];
    int v40_b = v36_b[1];
    int v41_b = v38_b[1];
    bool v140_b = !(((~(((v21_b ^ 10) | (-(v21_b ^ 10))) >> 31)) | (~(((v22_b ^ 10) | (-(v22_b ^ 10))) >> 31))) == 0);
    int v95_b;
    if (v140_b) {
      int * v42_b = (v15_p->b)->cache_age;
      int v142_b = 8 + ((~(((v22_b ^ 10) | (-(v22_b ^ 10))) >> 31)) & 1);
      int v43_b = v42_b[v142_b];
      int v44_b = v42_b[8];
      int v143_b = v44_b + ((int)((unsigned int)(v44_b - v43_b) >> 31));
      v42_b[8] = v143_b;
      int * v46_b = (v15_p->b)->cache_age;
      int v47_b = v46_b[9];
      int v145_b = v47_b + ((int)((unsigned int)(v47_b - v43_b) >> 31));
      v46_b[9] = v145_b;
      int * v49_b = (v15_p->b)->cache_age;
      v49_b[v142_b] = 0;
      v95_b = v142_b;
    } else {
      int * v52_b = (v15_p->b)->cache_age;
      int v53_b = v52_b[8];
      int * v54_b = (v15_p->b)->cache_tags;
      int v55_b = v54_b[8];
      int v56_b = v52_b[9];
      int v57_b = v54_b[9];
      int * v58_b = (v15_p->b)->cache_dirty;
      int v150_b = 8 + ((((v53_b + ((~(((v55_b ^ -1) | (-(v55_b ^ -1))) >> 31)) & 2)) - (v56_b + ((~(((v57_b ^ -1) | (-(v57_b ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v59_b = v58_b[v150_b];
      bool v151_b = !(v59_b == 0);
      if (v151_b) {
        int * v60_b = (v15_p->b)->cache_tags;
        int v61_b = v60_b[v150_b];
        int * v62_b = (v15_p->b)->cache_vals;
        int v154_b = (8 + ((((v53_b + ((~(((v55_b ^ -1) | (-(v55_b ^ -1))) >> 31)) & 2)) - (v56_b + ((~(((v57_b ^ -1) | (-(v57_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v63_b = v62_b[v154_b];
        int v155_b = ((8 + ((((v53_b + ((~(((v55_b ^ -1) | (-(v55_b ^ -1))) >> 31)) & 2)) - (v56_b + ((~(((v57_b ^ -1) | (-(v57_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v64_b = v62_b[v155_b];
        int * v65_b = (v15_p->b)->mem;
        int v157_b = v61_b * 2;
        v65_b[v157_b] = v63_b;
        int * v67_b = (v15_p->b)->mem;
        int v160_b = (v61_b * 2) + 1;
        v67_b[v160_b] = v64_b;
        ;
      } else {
        ;
      }
      int * v72_b = (v15_p->b)->mem;
      int v73_b = v72_b[20];
      int v74_b = v72_b[21];
      int * v75_b = (v15_p->b)->cache_vals;
      int v168_b = (8 + ((((v53_b + ((~(((v55_b ^ -1) | (-(v55_b ^ -1))) >> 31)) & 2)) - (v56_b + ((~(((v57_b ^ -1) | (-(v57_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v75_b[v168_b] = v73_b;
      int * v77_b = (v15_p->b)->cache_vals;
      int v171_b = ((8 + ((((v53_b + ((~(((v55_b ^ -1) | (-(v55_b ^ -1))) >> 31)) & 2)) - (v56_b + ((~(((v57_b ^ -1) | (-(v57_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v77_b[v171_b] = v74_b;
      int * v79_b = (v15_p->b)->cache_tags;
      v79_b[v150_b] = 10;
      int * v81_b = (v15_p->b)->cache_dirty;
      v81_b[v150_b] = 0;
      int * v83_b = (v15_p->b)->cache_age;
      v83_b[v150_b] = 1;
      int * v85_b = (v15_p->b)->cache_age;
      int v86_b = v85_b[v150_b];
      int v87_b = v85_b[8];
      int v178_b = v87_b + ((int)((unsigned int)(v87_b - v86_b) >> 31));
      v85_b[8] = v178_b;
      int * v89_b = (v15_p->b)->cache_age;
      int v90_b = v89_b[9];
      int v180_b = v90_b + ((int)((unsigned int)(v90_b - v86_b) >> 31));
      v89_b[9] = v180_b;
      int * v92_b = (v15_p->b)->cache_age;
      v92_b[v150_b] = 0;
      v95_b = v150_b;
    }
    int * v96_b = (v15_p->b)->cache_vals;
    int v183_b = v95_b * 2;
    int v97_b = v96_b[v183_b];
    int v184_b = (v95_b * 2) + 1;
    int v98_b = v96_b[v184_b];
    int v185_b = ((((v37_b + ((~(((v39_b ^ -1) | (-(v39_b ^ -1))) >> 31)) & 2)) - (v40_b + ((~(((v41_b ^ -1) | (-(v41_b ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v96_b[v185_b] = v97_b;
    int * v100_b = (v15_p->b)->cache_vals;
    int v188_b = (((((v37_b + ((~(((v39_b ^ -1) | (-(v39_b ^ -1))) >> 31)) & 2)) - (v40_b + ((~(((v41_b ^ -1) | (-(v41_b ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v100_b[v188_b] = v98_b;
    int * v102_b = (v15_p->b)->cache_tags;
    int v191_b = (((v37_b + ((~(((v39_b ^ -1) | (-(v39_b ^ -1))) >> 31)) & 2)) - (v40_b + ((~(((v41_b ^ -1) | (-(v41_b ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v102_b[v191_b] = 10;
    int * v104_b = (v15_p->b)->cache_dirty;
    v104_b[v191_b] = 0;
    int * v106_b = (v15_p->b)->cache_age;
    v106_b[v191_b] = 1;
    int * v108_b = (v15_p->b)->cache_age;
    int v109_b = v108_b[v191_b];
    int v110_b = v108_b[0];
    int v196_b = v110_b + ((int)((unsigned int)(v110_b - v109_b) >> 31));
    v108_b[0] = v196_b;
    int * v112_b = (v15_p->b)->cache_age;
    int v113_b = v112_b[1];
    int v198_b = v113_b + ((int)((unsigned int)(v113_b - v109_b) >> 31));
    v112_b[1] = v198_b;
    int * v115_b = (v15_p->b)->cache_age;
    v115_b[v191_b] = 0;
    v118_b = v191_b;
  }
  int v201_a = v118_a * 2;
  int v201_b = v118_b * 2;
  int v119_a = v25_a[v201_a];
  int v119_b = v25_b[v201_b];
  int * v120_a = (v15_p->a)->regs;
  int * v120_b = (v15_p->b)->regs;
  v120_a[9] = v119_a;
  v120_b[9] = v119_b;
  struct StateT2 * v122_p = slot_2(v15_p);
  return v122_p;
}

struct StateT2 * slot_19(struct StateT2 * v1026_p) {
  lockstep_assert(((v1026_p->a)->timer) == ((v1026_p->b)->timer));
  lockstep_assume(((v1026_p->a)->timer) == ((v1026_p->b)->timer));
  int v1027_a = (v1026_p->a)->timer;
  int v1027_b = (v1026_p->b)->timer;
  int v1034_a = v1027_a + 1;
  int v1034_b = v1027_b + 1;
  (v1026_p->a)->timer = v1034_a;
  (v1026_p->b)->timer = v1034_b;
  int * v1029_a = (v1026_p->a)->regs;
  int * v1029_b = (v1026_p->b)->regs;
  int v1030_a = v1029_a[6];
  int v1030_b = v1029_b[6];
  int v1037_a = v1030_a & 63;
  int v1037_b = v1030_b & 63;
  v1029_a[6] = v1037_a;
  v1029_b[6] = v1037_b;
  struct StateT2 * v1032_p = slot_20(v1026_p);
  return v1032_p;
}

struct StateT2 * slot_13(struct StateT2 * v748_p) {
  lockstep_assert(((v748_p->a)->timer) == ((v748_p->b)->timer));
  lockstep_assume(((v748_p->a)->timer) == ((v748_p->b)->timer));
  int v749_a = (v748_p->a)->timer;
  int v749_b = (v748_p->b)->timer;
  int v756_a = v749_a + 1;
  int v756_b = v749_b + 1;
  (v748_p->a)->timer = v756_a;
  (v748_p->b)->timer = v756_b;
  int * v751_a = (v748_p->a)->regs;
  int * v751_b = (v748_p->b)->regs;
  int v752_a = v751_a[10];
  int v752_b = v751_b[10];
  int v760_a = (int)((unsigned int)v752_a >> 16);
  int v760_b = (int)((unsigned int)v752_b >> 16);
  v751_a[6] = v760_a;
  v751_b[6] = v760_b;
  struct StateT2 * v754_p = slot_14(v748_p);
  return v754_p;
}

struct StateT2 * slot_0(struct StateT2 * v2_p) {
  lockstep_assert(((v2_p->a)->timer) == ((v2_p->b)->timer));
  lockstep_assume(((v2_p->a)->timer) == ((v2_p->b)->timer));
  int v3_a = (v2_p->a)->timer;
  int v3_b = (v2_p->b)->timer;
  int v9_a = v3_a + 1;
  int v9_b = v3_b + 1;
  (v2_p->a)->timer = v9_a;
  (v2_p->b)->timer = v9_b;
  int * v5_a = (v2_p->a)->regs;
  int * v5_b = (v2_p->b)->regs;
  v5_a[5] = 0;
  v5_b[5] = 0;
  struct StateT2 * v7_p = slot_1(v2_p);
  return v7_p;
}

struct StateT2 * slot_14(struct StateT2 * v763_p) {
  lockstep_assert(((v763_p->a)->timer) == ((v763_p->b)->timer));
  lockstep_assume(((v763_p->a)->timer) == ((v763_p->b)->timer));
  int v764_a = (v763_p->a)->timer;
  int v764_b = (v763_p->b)->timer;
  int v771_a = v764_a + 1;
  int v771_b = v764_b + 1;
  (v763_p->a)->timer = v771_a;
  (v763_p->b)->timer = v771_b;
  int * v766_a = (v763_p->a)->regs;
  int * v766_b = (v763_p->b)->regs;
  int v767_a = v766_a[6];
  int v767_b = v766_b[6];
  int v774_a = v767_a & 63;
  int v774_b = v767_b & 63;
  v766_a[6] = v774_a;
  v766_b[6] = v774_b;
  struct StateT2 * v769_p = slot_15(v763_p);
  return v769_p;
}

struct StateT2 * slot_17(struct StateT2 * v995_p) {
  lockstep_assert(((v995_p->a)->timer) == ((v995_p->b)->timer));
  lockstep_assume(((v995_p->a)->timer) == ((v995_p->b)->timer));
  int v996_a = (v995_p->a)->timer;
  int v996_b = (v995_p->b)->timer;
  int v1004_a = v996_a + 1;
  int v1004_b = v996_b + 1;
  (v995_p->a)->timer = v1004_a;
  (v995_p->b)->timer = v1004_b;
  int * v998_a = (v995_p->a)->regs;
  int * v998_b = (v995_p->b)->regs;
  int v999_a = v998_a[5];
  int v999_b = v998_b[5];
  int v1000_a = v998_a[7];
  int v1000_b = v998_b[7];
  int v1008_a = v999_a ^ v1000_a;
  int v1008_b = v999_b ^ v1000_b;
  v998_a[5] = v1008_a;
  v998_b[5] = v1008_b;
  struct StateT2 * v1002_p = slot_18(v995_p);
  return v1002_p;
}

struct StateT2 * slot_20(struct StateT2 * v1040_p) {
  lockstep_assert(((v1040_p->a)->timer) == ((v1040_p->b)->timer));
  lockstep_assume(((v1040_p->a)->timer) == ((v1040_p->b)->timer));
  int v1041_a = (v1040_p->a)->timer;
  int v1041_b = (v1040_p->b)->timer;
  int v1048_a = v1041_a + 1;
  int v1048_b = v1041_b + 1;
  (v1040_p->a)->timer = v1048_a;
  (v1040_p->b)->timer = v1048_b;
  int * v1043_a = (v1040_p->a)->regs;
  int * v1043_b = (v1040_p->b)->regs;
  int v1044_a = v1043_a[6];
  int v1044_b = v1043_b[6];
  int v1051_a = v1044_a << 2;
  int v1051_b = v1044_b << 2;
  v1043_a[6] = v1051_a;
  v1043_b[6] = v1051_b;
  struct StateT2 * v1046_p = slot_21(v1040_p);
  return v1046_p;
}

struct StateT2 * snippet(struct StateT2 * v0_p) {
  lockstep_assert(((v0_p->a)->timer) == ((v0_p->b)->timer));
  lockstep_assume(((v0_p->a)->timer) == ((v0_p->b)->timer));
  struct StateT2 * v1_p = slot_0(v0_p);
  return v1_p;
}

struct StateT2 * slot_8(struct StateT2 * v485_p) {
  lockstep_assert(((v485_p->a)->timer) == ((v485_p->b)->timer));
  lockstep_assume(((v485_p->a)->timer) == ((v485_p->b)->timer));
  int v486_a = (v485_p->a)->timer;
  int v486_b = (v485_p->b)->timer;
  int v493_a = v486_a + 1;
  int v493_b = v486_b + 1;
  (v485_p->a)->timer = v493_a;
  (v485_p->b)->timer = v493_b;
  int * v488_a = (v485_p->a)->regs;
  int * v488_b = (v485_p->b)->regs;
  int v489_a = v488_a[10];
  int v489_b = v488_b[10];
  int v497_a = (int)((unsigned int)v489_a >> 8);
  int v497_b = (int)((unsigned int)v489_b >> 8);
  v488_a[6] = v497_a;
  v488_b[6] = v497_b;
  struct StateT2 * v491_p = slot_9(v485_p);
  return v491_p;
}

struct StateT2 * slot_4(struct StateT2 * v237_p) {
  lockstep_assert(((v237_p->a)->timer) == ((v237_p->b)->timer));
  lockstep_assume(((v237_p->a)->timer) == ((v237_p->b)->timer));
  int v238_a = (v237_p->a)->timer;
  int v238_b = (v237_p->b)->timer;
  int v245_a = v238_a + 1;
  int v245_b = v238_b + 1;
  (v237_p->a)->timer = v245_a;
  (v237_p->b)->timer = v245_b;
  int * v240_a = (v237_p->a)->regs;
  int * v240_b = (v237_p->b)->regs;
  int v241_a = v240_a[6];
  int v241_b = v240_b[6];
  int v248_a = v241_a & 63;
  int v248_b = v241_b & 63;
  v240_a[6] = v248_a;
  v240_b[6] = v248_b;
  struct StateT2 * v243_p = slot_5(v237_p);
  return v243_p;
}

struct StateT2 * slot_15(struct StateT2 * v777_p) {
  lockstep_assert(((v777_p->a)->timer) == ((v777_p->b)->timer));
  lockstep_assume(((v777_p->a)->timer) == ((v777_p->b)->timer));
  int v778_a = (v777_p->a)->timer;
  int v778_b = (v777_p->b)->timer;
  int v785_a = v778_a + 1;
  int v785_b = v778_b + 1;
  (v777_p->a)->timer = v785_a;
  (v777_p->b)->timer = v785_b;
  int * v780_a = (v777_p->a)->regs;
  int * v780_b = (v777_p->b)->regs;
  int v781_a = v780_a[6];
  int v781_b = v780_b[6];
  int v788_a = v781_a << 2;
  int v788_b = v781_b << 2;
  v780_a[6] = v788_a;
  v780_b[6] = v788_b;
  struct StateT2 * v783_p = slot_16(v777_p);
  return v783_p;
}

struct StateT2 * slot_18(struct StateT2 * v1011_p) {
  lockstep_assert(((v1011_p->a)->timer) == ((v1011_p->b)->timer));
  lockstep_assume(((v1011_p->a)->timer) == ((v1011_p->b)->timer));
  int v1012_a = (v1011_p->a)->timer;
  int v1012_b = (v1011_p->b)->timer;
  int v1019_a = v1012_a + 1;
  int v1019_b = v1012_b + 1;
  (v1011_p->a)->timer = v1019_a;
  (v1011_p->b)->timer = v1019_b;
  int * v1014_a = (v1011_p->a)->regs;
  int * v1014_b = (v1011_p->b)->regs;
  int v1015_a = v1014_a[10];
  int v1015_b = v1014_b[10];
  int v1023_a = (int)((unsigned int)v1015_a >> 24);
  int v1023_b = (int)((unsigned int)v1015_b >> 24);
  v1014_a[6] = v1023_a;
  v1014_b[6] = v1023_b;
  struct StateT2 * v1017_p = slot_19(v1011_p);
  return v1017_p;
}

struct StateT2 * slot_9(struct StateT2 * v500_p) {
  lockstep_assert(((v500_p->a)->timer) == ((v500_p->b)->timer));
  lockstep_assume(((v500_p->a)->timer) == ((v500_p->b)->timer));
  int v501_a = (v500_p->a)->timer;
  int v501_b = (v500_p->b)->timer;
  int v508_a = v501_a + 1;
  int v508_b = v501_b + 1;
  (v500_p->a)->timer = v508_a;
  (v500_p->b)->timer = v508_b;
  int * v503_a = (v500_p->a)->regs;
  int * v503_b = (v500_p->b)->regs;
  int v504_a = v503_a[6];
  int v504_b = v503_b[6];
  int v511_a = v504_a & 63;
  int v511_b = v504_b & 63;
  v503_a[6] = v511_a;
  v503_b[6] = v511_b;
  struct StateT2 * v506_p = slot_10(v500_p);
  return v506_p;
}

struct StateT2 * slot_22(struct StateT2 * v1258_p) {
  lockstep_assert(((v1258_p->a)->timer) == ((v1258_p->b)->timer));
  lockstep_assume(((v1258_p->a)->timer) == ((v1258_p->b)->timer));
  int v1259_a = (v1258_p->a)->timer;
  int v1259_b = (v1258_p->b)->timer;
  int v1266_a = v1259_a + 1;
  int v1266_b = v1259_b + 1;
  (v1258_p->a)->timer = v1266_a;
  (v1258_p->b)->timer = v1266_b;
  int * v1261_a = (v1258_p->a)->regs;
  int * v1261_b = (v1258_p->b)->regs;
  int v1262_a = v1261_a[5];
  int v1262_b = v1261_b[5];
  int v1263_a = v1261_a[7];
  int v1263_b = v1261_b[7];
  int v1270_a = v1262_a ^ v1263_a;
  int v1270_b = v1262_b ^ v1263_b;
  v1261_a[5] = v1270_a;
  v1261_b[5] = v1270_b;
  return v1258_p;
}

struct StateT2 * slot_11(struct StateT2 * v528_p) {
  lockstep_assert(((v528_p->a)->timer) == ((v528_p->b)->timer));
  lockstep_assume(((v528_p->a)->timer) == ((v528_p->b)->timer));
  int v529_a = (v528_p->a)->timer;
  int v529_b = (v528_p->b)->timer;
  int v639_a = v529_a + 1;
  int v639_b = v529_b + 1;
  (v528_p->a)->timer = v639_a;
  (v528_p->b)->timer = v639_b;
  int * v531_a = (v528_p->a)->regs;
  int * v531_b = (v528_p->b)->regs;
  int v532_a = v531_a[6];
  int v532_b = v531_b[6];
  int * v533_a = (v528_p->a)->cache_tags;
  int * v533_b = (v528_p->b)->cache_tags;
  int v643_a = (((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1)) & 1) * 2;
  int v643_b = (((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1)) & 1) * 2;
  int v534_a = v533_a[v643_a];
  int v534_b = v533_b[v643_b];
  int v644_a = ((((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1)) & 1) * 2) + 1;
  int v644_b = ((((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1)) & 1) * 2) + 1;
  int v535_a = v533_a[v644_a];
  int v535_b = v533_b[v644_b];
  int v645_a = 4 + ((((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1)) & 3) * 2);
  int v645_b = 4 + ((((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1)) & 3) * 2);
  int v536_a = v533_a[v645_a];
  int v536_b = v533_b[v645_b];
  int v646_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1)) & 3) * 2)) + 1;
  int v646_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1)) & 3) * 2)) + 1;
  int v537_a = v533_a[v646_a];
  int v537_b = v533_b[v646_b];
  int v538_a = (v528_p->a)->timer;
  int v538_b = (v528_p->b)->timer;
  int v647_a = v538_a + ((100 ^ (((~(((v536_a ^ ((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1))) | (-(v536_a ^ ((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1))))) >> 31)) | (~(((v537_a ^ ((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1))) | (-(v537_a ^ ((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v534_a ^ ((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1))) | (-(v534_a ^ ((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1))))) >> 31)) | (~(((v535_a ^ ((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1))) | (-(v535_a ^ ((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v536_a ^ ((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1))) | (-(v536_a ^ ((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1))))) >> 31)) | (~(((v537_a ^ ((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1))) | (-(v537_a ^ ((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1))))) >> 31))) & 104)))));
  int v647_b = v538_b + ((100 ^ (((~(((v536_b ^ ((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1))) | (-(v536_b ^ ((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1))))) >> 31)) | (~(((v537_b ^ ((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1))) | (-(v537_b ^ ((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v534_b ^ ((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1))) | (-(v534_b ^ ((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1))))) >> 31)) | (~(((v535_b ^ ((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1))) | (-(v535_b ^ ((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v536_b ^ ((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1))) | (-(v536_b ^ ((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1))))) >> 31)) | (~(((v537_b ^ ((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1))) | (-(v537_b ^ ((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1))))) >> 31))) & 104)))));
  (v528_p->a)->timer = v647_a;
  (v528_p->b)->timer = v647_b;
  int * v540_a = (v528_p->a)->cache_vals;
  int * v540_b = (v528_p->b)->cache_vals;
  bool v648_a = !(((~(((v534_a ^ ((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1))) | (-(v534_a ^ ((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1))))) >> 31)) | (~(((v535_a ^ ((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1))) | (-(v535_a ^ ((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1))))) >> 31))) == 0);
  bool v648_b = !(((~(((v534_b ^ ((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1))) | (-(v534_b ^ ((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1))))) >> 31)) | (~(((v535_b ^ ((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1))) | (-(v535_b ^ ((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1))))) >> 31))) == 0);
  int v633_a;
  if (v648_a) {
    int * v541_a = (v528_p->a)->cache_age;
    int v650_a = ((((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1)) & 1) * 2) + ((~(((v535_a ^ ((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1))) | (-(v535_a ^ ((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1))))) >> 31)) & 1);
    int v542_a = v541_a[v650_a];
    int v543_a = v541_a[v643_a];
    int v651_a = v543_a + ((int)((unsigned int)(v543_a - v542_a) >> 31));
    v541_a[v643_a] = v651_a;
    int * v545_a = (v528_p->a)->cache_age;
    int v546_a = v545_a[v644_a];
    int v653_a = v546_a + ((int)((unsigned int)(v546_a - v542_a) >> 31));
    v545_a[v644_a] = v653_a;
    int * v548_a = (v528_p->a)->cache_age;
    v548_a[v650_a] = 0;
    v633_a = v650_a;
  } else {
    int * v551_a = (v528_p->a)->cache_age;
    int v657_a = (((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1)) & 1) * 2;
    int v552_a = v551_a[v657_a];
    int * v553_a = (v528_p->a)->cache_tags;
    int v554_a = v553_a[v657_a];
    int v555_a = v551_a[v644_a];
    int v556_a = v553_a[v644_a];
    bool v659_a = !(((~(((v536_a ^ ((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1))) | (-(v536_a ^ ((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1))))) >> 31)) | (~(((v537_a ^ ((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1))) | (-(v537_a ^ ((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1))))) >> 31))) == 0);
    int v610_a;
    if (v659_a) {
      int * v557_a = (v528_p->a)->cache_age;
      int v661_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1)) & 3) * 2)) + ((~(((v537_a ^ ((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1))) | (-(v537_a ^ ((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1))))) >> 31)) & 1);
      int v558_a = v557_a[v661_a];
      int v559_a = v557_a[v645_a];
      int v662_a = v559_a + ((int)((unsigned int)(v559_a - v558_a) >> 31));
      v557_a[v645_a] = v662_a;
      int * v561_a = (v528_p->a)->cache_age;
      int v562_a = v561_a[v646_a];
      int v664_a = v562_a + ((int)((unsigned int)(v562_a - v558_a) >> 31));
      v561_a[v646_a] = v664_a;
      int * v564_a = (v528_p->a)->cache_age;
      v564_a[v661_a] = 0;
      v610_a = v661_a;
    } else {
      int * v567_a = (v528_p->a)->cache_age;
      int v668_a = 4 + ((((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1)) & 3) * 2);
      int v568_a = v567_a[v668_a];
      int * v569_a = (v528_p->a)->cache_tags;
      int v570_a = v569_a[v668_a];
      int v571_a = v567_a[v646_a];
      int v572_a = v569_a[v646_a];
      int * v573_a = (v528_p->a)->cache_dirty;
      int v671_a = (4 + ((((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1)) & 3) * 2)) + ((((v568_a + ((~(((v570_a ^ -1) | (-(v570_a ^ -1))) >> 31)) & 2)) - (v571_a + ((~(((v572_a ^ -1) | (-(v572_a ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v574_a = v573_a[v671_a];
      bool v672_a = !(v574_a == 0);
      if (v672_a) {
        int * v575_a = (v528_p->a)->cache_tags;
        int v576_a = v575_a[v671_a];
        int * v577_a = (v528_p->a)->cache_vals;
        int v675_a = ((4 + ((((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1)) & 3) * 2)) + ((((v568_a + ((~(((v570_a ^ -1) | (-(v570_a ^ -1))) >> 31)) & 2)) - (v571_a + ((~(((v572_a ^ -1) | (-(v572_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v578_a = v577_a[v675_a];
        int v676_a = (((4 + ((((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1)) & 3) * 2)) + ((((v568_a + ((~(((v570_a ^ -1) | (-(v570_a ^ -1))) >> 31)) & 2)) - (v571_a + ((~(((v572_a ^ -1) | (-(v572_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v579_a = v577_a[v676_a];
        int * v580_a = (v528_p->a)->mem;
        int v678_a = v576_a * 2;
        v580_a[v678_a] = v578_a;
        int * v582_a = (v528_p->a)->mem;
        int v681_a = (v576_a * 2) + 1;
        v582_a[v681_a] = v579_a;
        ;
      } else {
        ;
      }
      int * v587_a = (v528_p->a)->mem;
      int v686_a = ((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1)) * 2;
      int v588_a = v587_a[v686_a];
      int v687_a = (((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1)) * 2) + 1;
      int v589_a = v587_a[v687_a];
      int * v590_a = (v528_p->a)->cache_vals;
      int v689_a = ((4 + ((((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1)) & 3) * 2)) + ((((v568_a + ((~(((v570_a ^ -1) | (-(v570_a ^ -1))) >> 31)) & 2)) - (v571_a + ((~(((v572_a ^ -1) | (-(v572_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v590_a[v689_a] = v588_a;
      int * v592_a = (v528_p->a)->cache_vals;
      int v692_a = (((4 + ((((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1)) & 3) * 2)) + ((((v568_a + ((~(((v570_a ^ -1) | (-(v570_a ^ -1))) >> 31)) & 2)) - (v571_a + ((~(((v572_a ^ -1) | (-(v572_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v592_a[v692_a] = v589_a;
      int * v594_a = (v528_p->a)->cache_tags;
      int v695_a = (int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1);
      v594_a[v671_a] = v695_a;
      int * v596_a = (v528_p->a)->cache_dirty;
      v596_a[v671_a] = 0;
      int * v598_a = (v528_p->a)->cache_age;
      v598_a[v671_a] = 1;
      int * v600_a = (v528_p->a)->cache_age;
      int v601_a = v600_a[v671_a];
      int v602_a = v600_a[v645_a];
      int v701_a = v602_a + ((int)((unsigned int)(v602_a - v601_a) >> 31));
      v600_a[v645_a] = v701_a;
      int * v604_a = (v528_p->a)->cache_age;
      int v605_a = v604_a[v646_a];
      int v703_a = v605_a + ((int)((unsigned int)(v605_a - v601_a) >> 31));
      v604_a[v646_a] = v703_a;
      int * v607_a = (v528_p->a)->cache_age;
      v607_a[v671_a] = 0;
      v610_a = v671_a;
    }
    int * v611_a = (v528_p->a)->cache_vals;
    int v706_a = v610_a * 2;
    int v612_a = v611_a[v706_a];
    int v707_a = (v610_a * 2) + 1;
    int v613_a = v611_a[v707_a];
    int v708_a = (((((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1)) & 1) * 2) + ((((v552_a + ((~(((v554_a ^ -1) | (-(v554_a ^ -1))) >> 31)) & 2)) - (v555_a + ((~(((v556_a ^ -1) | (-(v556_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v611_a[v708_a] = v612_a;
    int * v615_a = (v528_p->a)->cache_vals;
    int v711_a = ((((((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1)) & 1) * 2) + ((((v552_a + ((~(((v554_a ^ -1) | (-(v554_a ^ -1))) >> 31)) & 2)) - (v555_a + ((~(((v556_a ^ -1) | (-(v556_a ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v615_a[v711_a] = v613_a;
    int * v617_a = (v528_p->a)->cache_tags;
    int v714_a = ((((int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1)) & 1) * 2) + ((((v552_a + ((~(((v554_a ^ -1) | (-(v554_a ^ -1))) >> 31)) & 2)) - (v555_a + ((~(((v556_a ^ -1) | (-(v556_a ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v715_a = (int)((unsigned int)((int)((unsigned int)v532_a >> 2)) >> 1);
    v617_a[v714_a] = v715_a;
    int * v619_a = (v528_p->a)->cache_dirty;
    v619_a[v714_a] = 0;
    int * v621_a = (v528_p->a)->cache_age;
    v621_a[v714_a] = 1;
    int * v623_a = (v528_p->a)->cache_age;
    int v624_a = v623_a[v714_a];
    int v625_a = v623_a[v643_a];
    int v721_a = v625_a + ((int)((unsigned int)(v625_a - v624_a) >> 31));
    v623_a[v643_a] = v721_a;
    int * v627_a = (v528_p->a)->cache_age;
    int v628_a = v627_a[v644_a];
    int v723_a = v628_a + ((int)((unsigned int)(v628_a - v624_a) >> 31));
    v627_a[v644_a] = v723_a;
    int * v630_a = (v528_p->a)->cache_age;
    v630_a[v714_a] = 0;
    v633_a = v714_a;
  }
  int v633_b;
  if (v648_b) {
    int * v541_b = (v528_p->b)->cache_age;
    int v650_b = ((((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1)) & 1) * 2) + ((~(((v535_b ^ ((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1))) | (-(v535_b ^ ((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1))))) >> 31)) & 1);
    int v542_b = v541_b[v650_b];
    int v543_b = v541_b[v643_b];
    int v651_b = v543_b + ((int)((unsigned int)(v543_b - v542_b) >> 31));
    v541_b[v643_b] = v651_b;
    int * v545_b = (v528_p->b)->cache_age;
    int v546_b = v545_b[v644_b];
    int v653_b = v546_b + ((int)((unsigned int)(v546_b - v542_b) >> 31));
    v545_b[v644_b] = v653_b;
    int * v548_b = (v528_p->b)->cache_age;
    v548_b[v650_b] = 0;
    v633_b = v650_b;
  } else {
    int * v551_b = (v528_p->b)->cache_age;
    int v657_b = (((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1)) & 1) * 2;
    int v552_b = v551_b[v657_b];
    int * v553_b = (v528_p->b)->cache_tags;
    int v554_b = v553_b[v657_b];
    int v555_b = v551_b[v644_b];
    int v556_b = v553_b[v644_b];
    bool v659_b = !(((~(((v536_b ^ ((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1))) | (-(v536_b ^ ((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1))))) >> 31)) | (~(((v537_b ^ ((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1))) | (-(v537_b ^ ((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1))))) >> 31))) == 0);
    int v610_b;
    if (v659_b) {
      int * v557_b = (v528_p->b)->cache_age;
      int v661_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1)) & 3) * 2)) + ((~(((v537_b ^ ((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1))) | (-(v537_b ^ ((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1))))) >> 31)) & 1);
      int v558_b = v557_b[v661_b];
      int v559_b = v557_b[v645_b];
      int v662_b = v559_b + ((int)((unsigned int)(v559_b - v558_b) >> 31));
      v557_b[v645_b] = v662_b;
      int * v561_b = (v528_p->b)->cache_age;
      int v562_b = v561_b[v646_b];
      int v664_b = v562_b + ((int)((unsigned int)(v562_b - v558_b) >> 31));
      v561_b[v646_b] = v664_b;
      int * v564_b = (v528_p->b)->cache_age;
      v564_b[v661_b] = 0;
      v610_b = v661_b;
    } else {
      int * v567_b = (v528_p->b)->cache_age;
      int v668_b = 4 + ((((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1)) & 3) * 2);
      int v568_b = v567_b[v668_b];
      int * v569_b = (v528_p->b)->cache_tags;
      int v570_b = v569_b[v668_b];
      int v571_b = v567_b[v646_b];
      int v572_b = v569_b[v646_b];
      int * v573_b = (v528_p->b)->cache_dirty;
      int v671_b = (4 + ((((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1)) & 3) * 2)) + ((((v568_b + ((~(((v570_b ^ -1) | (-(v570_b ^ -1))) >> 31)) & 2)) - (v571_b + ((~(((v572_b ^ -1) | (-(v572_b ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v574_b = v573_b[v671_b];
      bool v672_b = !(v574_b == 0);
      if (v672_b) {
        int * v575_b = (v528_p->b)->cache_tags;
        int v576_b = v575_b[v671_b];
        int * v577_b = (v528_p->b)->cache_vals;
        int v675_b = ((4 + ((((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1)) & 3) * 2)) + ((((v568_b + ((~(((v570_b ^ -1) | (-(v570_b ^ -1))) >> 31)) & 2)) - (v571_b + ((~(((v572_b ^ -1) | (-(v572_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v578_b = v577_b[v675_b];
        int v676_b = (((4 + ((((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1)) & 3) * 2)) + ((((v568_b + ((~(((v570_b ^ -1) | (-(v570_b ^ -1))) >> 31)) & 2)) - (v571_b + ((~(((v572_b ^ -1) | (-(v572_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v579_b = v577_b[v676_b];
        int * v580_b = (v528_p->b)->mem;
        int v678_b = v576_b * 2;
        v580_b[v678_b] = v578_b;
        int * v582_b = (v528_p->b)->mem;
        int v681_b = (v576_b * 2) + 1;
        v582_b[v681_b] = v579_b;
        ;
      } else {
        ;
      }
      int * v587_b = (v528_p->b)->mem;
      int v686_b = ((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1)) * 2;
      int v588_b = v587_b[v686_b];
      int v687_b = (((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1)) * 2) + 1;
      int v589_b = v587_b[v687_b];
      int * v590_b = (v528_p->b)->cache_vals;
      int v689_b = ((4 + ((((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1)) & 3) * 2)) + ((((v568_b + ((~(((v570_b ^ -1) | (-(v570_b ^ -1))) >> 31)) & 2)) - (v571_b + ((~(((v572_b ^ -1) | (-(v572_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v590_b[v689_b] = v588_b;
      int * v592_b = (v528_p->b)->cache_vals;
      int v692_b = (((4 + ((((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1)) & 3) * 2)) + ((((v568_b + ((~(((v570_b ^ -1) | (-(v570_b ^ -1))) >> 31)) & 2)) - (v571_b + ((~(((v572_b ^ -1) | (-(v572_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v592_b[v692_b] = v589_b;
      int * v594_b = (v528_p->b)->cache_tags;
      int v695_b = (int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1);
      v594_b[v671_b] = v695_b;
      int * v596_b = (v528_p->b)->cache_dirty;
      v596_b[v671_b] = 0;
      int * v598_b = (v528_p->b)->cache_age;
      v598_b[v671_b] = 1;
      int * v600_b = (v528_p->b)->cache_age;
      int v601_b = v600_b[v671_b];
      int v602_b = v600_b[v645_b];
      int v701_b = v602_b + ((int)((unsigned int)(v602_b - v601_b) >> 31));
      v600_b[v645_b] = v701_b;
      int * v604_b = (v528_p->b)->cache_age;
      int v605_b = v604_b[v646_b];
      int v703_b = v605_b + ((int)((unsigned int)(v605_b - v601_b) >> 31));
      v604_b[v646_b] = v703_b;
      int * v607_b = (v528_p->b)->cache_age;
      v607_b[v671_b] = 0;
      v610_b = v671_b;
    }
    int * v611_b = (v528_p->b)->cache_vals;
    int v706_b = v610_b * 2;
    int v612_b = v611_b[v706_b];
    int v707_b = (v610_b * 2) + 1;
    int v613_b = v611_b[v707_b];
    int v708_b = (((((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1)) & 1) * 2) + ((((v552_b + ((~(((v554_b ^ -1) | (-(v554_b ^ -1))) >> 31)) & 2)) - (v555_b + ((~(((v556_b ^ -1) | (-(v556_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v611_b[v708_b] = v612_b;
    int * v615_b = (v528_p->b)->cache_vals;
    int v711_b = ((((((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1)) & 1) * 2) + ((((v552_b + ((~(((v554_b ^ -1) | (-(v554_b ^ -1))) >> 31)) & 2)) - (v555_b + ((~(((v556_b ^ -1) | (-(v556_b ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v615_b[v711_b] = v613_b;
    int * v617_b = (v528_p->b)->cache_tags;
    int v714_b = ((((int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1)) & 1) * 2) + ((((v552_b + ((~(((v554_b ^ -1) | (-(v554_b ^ -1))) >> 31)) & 2)) - (v555_b + ((~(((v556_b ^ -1) | (-(v556_b ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v715_b = (int)((unsigned int)((int)((unsigned int)v532_b >> 2)) >> 1);
    v617_b[v714_b] = v715_b;
    int * v619_b = (v528_p->b)->cache_dirty;
    v619_b[v714_b] = 0;
    int * v621_b = (v528_p->b)->cache_age;
    v621_b[v714_b] = 1;
    int * v623_b = (v528_p->b)->cache_age;
    int v624_b = v623_b[v714_b];
    int v625_b = v623_b[v643_b];
    int v721_b = v625_b + ((int)((unsigned int)(v625_b - v624_b) >> 31));
    v623_b[v643_b] = v721_b;
    int * v627_b = (v528_p->b)->cache_age;
    int v628_b = v627_b[v644_b];
    int v723_b = v628_b + ((int)((unsigned int)(v628_b - v624_b) >> 31));
    v627_b[v644_b] = v723_b;
    int * v630_b = (v528_p->b)->cache_age;
    v630_b[v714_b] = 0;
    v633_b = v714_b;
  }
  int v726_a = (v633_a * 2) + (((int)((unsigned int)v532_a >> 2)) & 1);
  int v726_b = (v633_b * 2) + (((int)((unsigned int)v532_b >> 2)) & 1);
  int v634_a = v540_a[v726_a];
  int v634_b = v540_b[v726_b];
  int * v635_a = (v528_p->a)->regs;
  int * v635_b = (v528_p->b)->regs;
  v635_a[7] = v634_a;
  v635_b[7] = v634_b;
  struct StateT2 * v637_p = slot_12(v528_p);
  return v637_p;
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

void lockstep_assert(bool c) { koika_assert(c, "lockstep drift"); }
void lockstep_assume(bool c) { koika_assume(c); }

int main(int argc, char* argv[]) {
  struct StateT s1, s2;
  init(&s1);
  init(&s2);
  
  // the indices, public: one draw into both states
  int i10 = bounded(0, 1073741823);
  s1.regs[10] = i10;
  s2.regs[10] = i10;
  
  // initialize secret
  for (int i=0; i<SECRET_SIZE; i++) {
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateT2 p = { .a = &s1, .b = &s2 };
  struct StateT2 *p_ = snippet(&p);
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}