// verify: clean (CBMC should report VERIFICATION SUCCESSFUL) [unwind 33]

#define NUM_REGS 32
#define MEM_SIZE 32
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_LRU_SIZE 10
#ifndef CBMC
#define __CPROVER_assert(b,s) 0
#define nondet_uint() 0
#else
int nondet_uint();
#endif
int bounded(int low, int high) {
  int x = nondet_uint();
  __CPROVER_assume(low <= x && x <= high);
  return x;
}

/*****************************************
Emitting C Generated Code
*******************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct StateT2 {
  struct StateT * a;
  struct StateT * b;
};

struct StateT {
  int regs[32];
  int mem[32];
  int saved_regs[32];
  int cache_keys[10];
  int cache_vals[10];
  int timer;
};

void lockstep_assert(bool);
void lockstep_assume(bool);

struct StateT2 * slot_12(struct StateT2 * v464_p);
struct StateT2 * slot_43(struct StateT2 * v1528_p);
struct StateT2 * slot_6(struct StateT2 * v185_p);
struct StateT2 * slot_47(struct StateT2 * v1682_p);
struct StateT2 * slot_29(struct StateT2 * v1023_p);
struct StateT2 * slot_55(struct StateT2 * v1909_p);
struct StateT2 * slot_16(struct StateT2 * v533_p);
struct StateT2 * slot_5(struct StateT2 * v169_p);
struct StateT2 * slot_7(struct StateT2 * v290_p);
struct StateT2 * slot_31(struct StateT2 * v1055_p);
struct StateT2 * slot_54(struct StateT2 * v1893_p);
struct StateT2 * slot_26(struct StateT2 * v881_p);
struct StateT2 * slot_10(struct StateT2 * v343_p);
struct StateT2 * slot_19(struct StateT2 * v675_p);
struct StateT2 * slot_58(struct StateT2 * v2050_p);
struct StateT2 * slot_14(struct StateT2 * v501_p);
struct StateT2 * slot_53(struct StateT2 * v1876_p);
struct StateT2 * slot_44(struct StateT2 * v1545_p);
struct StateT2 * slot_28(struct StateT2 * v1006_p);
struct StateT2 * slot_32(struct StateT2 * v1160_p);
struct StateT2 * slot_17(struct StateT2 * v638_p);
struct StateT2 * slot_49(struct StateT2 * v1719_p);
struct StateT2 * slot_33(struct StateT2 * v1180_p);
struct StateT2 * slot_50(struct StateT2 * v1735_p);
struct StateT2 * slot_36(struct StateT2 * v1229_p);
struct StateT2 * slot_37(struct StateT2 * v1334_p);
struct StateT2 * slot_57(struct StateT2 * v2030_p);
struct StateT2 * slot_59(struct StateT2 * v2067_p);
struct StateT2 * slot_40(struct StateT2 * v1387_p);
struct StateT2 * slot_27(struct StateT2 * v986_p);
struct StateT2 * slot_15(struct StateT2 * v517_p);
struct StateT2 * slot_62(struct StateT2 * v2204_p);
struct StateT2 * slot_48(struct StateT2 * v1702_p);
struct StateT2 * slot_22(struct StateT2 * v812_p);
struct StateT2 * slot_35(struct StateT2 * v1213_p);
struct StateT2 * slot_56(struct StateT2 * v1925_p);
struct StateT2 * slot_34(struct StateT2 * v1197_p);
struct StateT2 * slot_51(struct StateT2 * v1751_p);
struct StateT2 * slot_52(struct StateT2 * v1856_p);
struct StateT2 * slot_25(struct StateT2 * v865_p);
struct StateT2 * slot_23(struct StateT2 * v832_p);
struct StateT2 * slot_2(struct StateT2 * v116_p);
struct StateT2 * slot_21(struct StateT2 * v707_p);
struct StateT2 * slot_3(struct StateT2 * v136_p);
struct StateT2 * slot_45(struct StateT2 * v1561_p);
struct StateT2 * slot_1(struct StateT2 * v15_p);
struct StateT2 * slot_13(struct StateT2 * v484_p);
struct StateT2 * slot_38(struct StateT2 * v1354_p);
struct StateT2 * slot_24(struct StateT2 * v849_p);
struct StateT2 * slot_0(struct StateT2 * v2_p);
struct StateT2 * slot_42(struct StateT2 * v1508_p);
struct StateT2 * slot_46(struct StateT2 * v1577_p);
struct StateT2 * slot_20(struct StateT2 * v691_p);
struct StateT2 * slot_61(struct StateT2 * v2099_p);
struct StateT2 * snippet(struct StateT2 * v0_p);
struct StateT2 * slot_41(struct StateT2 * v1403_p);
struct StateT2 * slot_39(struct StateT2 * v1371_p);
struct StateT2 * slot_8(struct StateT2 * v310_p);
struct StateT2 * slot_30(struct StateT2 * v1039_p);
struct StateT2 * slot_60(struct StateT2 * v2083_p);
struct StateT2 * slot_4(struct StateT2 * v153_p);
struct StateT2 * slot_18(struct StateT2 * v658_p);
struct StateT2 * slot_9(struct StateT2 * v327_p);
struct StateT2 * slot_11(struct StateT2 * v359_p);
struct StateT2 * slot_12(struct StateT2 * v464_p) {
  lockstep_assert(((v464_p->a)->timer) == ((v464_p->b)->timer));
  lockstep_assume(((v464_p->a)->timer) == ((v464_p->b)->timer));
  int v465_a = (v464_p->a)->timer;
  int v465_b = (v464_p->b)->timer;
  int v475_a = v465_a + 1;
  int v475_b = v465_b + 1;
  (v464_p->a)->timer = v475_a;
  (v464_p->b)->timer = v475_b;
  int * v467_a = (v464_p->a)->regs;
  int * v467_b = (v464_p->b)->regs;
  int v468_a = v467_a[5];
  int v468_b = v467_b[5];
  int * v469_a = (v464_p->a)->regs;
  int * v469_b = (v464_p->b)->regs;
  int v470_a = v469_a[7];
  int v470_b = v469_b[7];
  int * v471_a = (v464_p->a)->regs;
  int * v471_b = (v464_p->b)->regs;
  int v481_a = v468_a ^ v470_a;
  int v481_b = v468_b ^ v470_b;
  v471_a[5] = v481_a;
  v471_b[5] = v481_b;
  struct StateT2 * v473_p = slot_13(v464_p);
  return v473_p;
}

struct StateT2 * slot_43(struct StateT2 * v1528_p) {
  lockstep_assert(((v1528_p->a)->timer) == ((v1528_p->b)->timer));
  lockstep_assume(((v1528_p->a)->timer) == ((v1528_p->b)->timer));
  int v1529_a = (v1528_p->a)->timer;
  int v1529_b = (v1528_p->b)->timer;
  int v1537_a = v1529_a + 1;
  int v1537_b = v1529_b + 1;
  (v1528_p->a)->timer = v1537_a;
  (v1528_p->b)->timer = v1537_b;
  int * v1531_a = (v1528_p->a)->regs;
  int * v1531_b = (v1528_p->b)->regs;
  int v1532_a = v1531_a[11];
  int v1532_b = v1531_b[11];
  int * v1533_a = (v1528_p->a)->regs;
  int * v1533_b = (v1528_p->b)->regs;
  int v1542_a = (int)((unsigned int)v1532_a >> 10);
  int v1542_b = (int)((unsigned int)v1532_b >> 10);
  v1533_a[6] = v1542_a;
  v1533_b[6] = v1542_b;
  struct StateT2 * v1535_p = slot_44(v1528_p);
  return v1535_p;
}

struct StateT2 * slot_6(struct StateT2 * v185_p) {
  lockstep_assert(((v185_p->a)->timer) == ((v185_p->b)->timer));
  lockstep_assume(((v185_p->a)->timer) == ((v185_p->b)->timer));
  int v186_a = (v185_p->a)->timer;
  int v186_b = (v185_p->b)->timer;
  int v244_a = v186_a + 1;
  int v244_b = v186_b + 1;
  (v185_p->a)->timer = v244_a;
  (v185_p->b)->timer = v244_b;
  int * v188_a = (v185_p->a)->regs;
  int * v188_b = (v185_p->b)->regs;
  int v189_a = v188_a[6];
  int v189_b = v188_b[6];
  int * v190_a = (v185_p->a)->cache_keys;
  int * v190_b = (v185_p->b)->cache_keys;
  int v191_a = v190_a[0];
  int v191_b = v190_b[0];
  bool v249_a = v191_a == ((int)((unsigned int)v189_a >> 2));
  bool v249_b = v191_b == ((int)((unsigned int)v189_b >> 2));
  int v239_a;
  if (v249_a) {
    int * v192_a = (v185_p->a)->cache_vals;
    int v193_a = v192_a[0];
    v239_a = v193_a;
  } else {
    int * v195_a = (v185_p->a)->cache_keys;
    int v196_a = v195_a[1];
    bool v254_a = v196_a == ((int)((unsigned int)v189_a >> 2));
    int v237_a;
    if (v254_a) {
      int * v197_a = (v185_p->a)->cache_vals;
      int v198_a = v197_a[1];
      int * v199_a = (v185_p->a)->cache_keys;
      int * v200_a = (v185_p->a)->cache_keys;
      int v201_a = v200_a[0];
      v199_a[1] = v201_a;
      int * v203_a = (v185_p->a)->cache_vals;
      int * v204_a = (v185_p->a)->cache_vals;
      int v205_a = v204_a[0];
      v203_a[1] = v205_a;
      int * v207_a = (v185_p->a)->cache_keys;
      int v263_a = (int)((unsigned int)v189_a >> 2);
      v207_a[0] = v263_a;
      int * v209_a = (v185_p->a)->cache_vals;
      v209_a[0] = v198_a;
      int v211_a = (v185_p->a)->timer;
      int v266_a = v211_a + 1;
      (v185_p->a)->timer = v266_a;
      v237_a = v198_a;
    } else {
      int * v214_a = (v185_p->a)->mem;
      int v268_a = (int)((unsigned int)v189_a >> 2);
      int v215_a = v214_a[v268_a];
      int * v216_a = (v185_p->a)->mem;
      int * v217_a = (v185_p->a)->cache_keys;
      int v218_a = v217_a[1];
      int * v219_a = (v185_p->a)->cache_vals;
      int v220_a = v219_a[1];
      v216_a[v218_a] = v220_a;
      int * v222_a = (v185_p->a)->cache_keys;
      int * v223_a = (v185_p->a)->cache_keys;
      int v224_a = v223_a[0];
      v222_a[1] = v224_a;
      int * v226_a = (v185_p->a)->cache_vals;
      int * v227_a = (v185_p->a)->cache_vals;
      int v228_a = v227_a[0];
      v226_a[1] = v228_a;
      int * v230_a = (v185_p->a)->cache_keys;
      v230_a[0] = v268_a;
      int * v232_a = (v185_p->a)->cache_vals;
      v232_a[0] = v215_a;
      int v234_a = (v185_p->a)->timer;
      int v283_a = v234_a + 100;
      (v185_p->a)->timer = v283_a;
      v237_a = v215_a;
    }
    v239_a = v237_a;
  }
  int v239_b;
  if (v249_b) {
    int * v192_b = (v185_p->b)->cache_vals;
    int v193_b = v192_b[0];
    v239_b = v193_b;
  } else {
    int * v195_b = (v185_p->b)->cache_keys;
    int v196_b = v195_b[1];
    bool v254_b = v196_b == ((int)((unsigned int)v189_b >> 2));
    int v237_b;
    if (v254_b) {
      int * v197_b = (v185_p->b)->cache_vals;
      int v198_b = v197_b[1];
      int * v199_b = (v185_p->b)->cache_keys;
      int * v200_b = (v185_p->b)->cache_keys;
      int v201_b = v200_b[0];
      v199_b[1] = v201_b;
      int * v203_b = (v185_p->b)->cache_vals;
      int * v204_b = (v185_p->b)->cache_vals;
      int v205_b = v204_b[0];
      v203_b[1] = v205_b;
      int * v207_b = (v185_p->b)->cache_keys;
      int v263_b = (int)((unsigned int)v189_b >> 2);
      v207_b[0] = v263_b;
      int * v209_b = (v185_p->b)->cache_vals;
      v209_b[0] = v198_b;
      int v211_b = (v185_p->b)->timer;
      int v266_b = v211_b + 1;
      (v185_p->b)->timer = v266_b;
      v237_b = v198_b;
    } else {
      int * v214_b = (v185_p->b)->mem;
      int v268_b = (int)((unsigned int)v189_b >> 2);
      int v215_b = v214_b[v268_b];
      int * v216_b = (v185_p->b)->mem;
      int * v217_b = (v185_p->b)->cache_keys;
      int v218_b = v217_b[1];
      int * v219_b = (v185_p->b)->cache_vals;
      int v220_b = v219_b[1];
      v216_b[v218_b] = v220_b;
      int * v222_b = (v185_p->b)->cache_keys;
      int * v223_b = (v185_p->b)->cache_keys;
      int v224_b = v223_b[0];
      v222_b[1] = v224_b;
      int * v226_b = (v185_p->b)->cache_vals;
      int * v227_b = (v185_p->b)->cache_vals;
      int v228_b = v227_b[0];
      v226_b[1] = v228_b;
      int * v230_b = (v185_p->b)->cache_keys;
      v230_b[0] = v268_b;
      int * v232_b = (v185_p->b)->cache_vals;
      v232_b[0] = v215_b;
      int v234_b = (v185_p->b)->timer;
      int v283_b = v234_b + 100;
      (v185_p->b)->timer = v283_b;
      v237_b = v215_b;
    }
    v239_b = v237_b;
  }
  int * v240_a = (v185_p->a)->regs;
  int * v240_b = (v185_p->b)->regs;
  v240_a[7] = v239_a;
  v240_b[7] = v239_b;
  struct StateT2 * v242_p = slot_7(v185_p);
  return v242_p;
}

struct StateT2 * slot_47(struct StateT2 * v1682_p) {
  lockstep_assert(((v1682_p->a)->timer) == ((v1682_p->b)->timer));
  lockstep_assume(((v1682_p->a)->timer) == ((v1682_p->b)->timer));
  int v1683_a = (v1682_p->a)->timer;
  int v1683_b = (v1682_p->b)->timer;
  int v1693_a = v1683_a + 1;
  int v1693_b = v1683_b + 1;
  (v1682_p->a)->timer = v1693_a;
  (v1682_p->b)->timer = v1693_b;
  int * v1685_a = (v1682_p->a)->regs;
  int * v1685_b = (v1682_p->b)->regs;
  int v1686_a = v1685_a[5];
  int v1686_b = v1685_b[5];
  int * v1687_a = (v1682_p->a)->regs;
  int * v1687_b = (v1682_p->b)->regs;
  int v1688_a = v1687_a[7];
  int v1688_b = v1687_b[7];
  int * v1689_a = (v1682_p->a)->regs;
  int * v1689_b = (v1682_p->b)->regs;
  int v1699_a = v1686_a ^ v1688_a;
  int v1699_b = v1686_b ^ v1688_b;
  v1689_a[5] = v1699_a;
  v1689_b[5] = v1699_b;
  struct StateT2 * v1691_p = slot_48(v1682_p);
  return v1691_p;
}

struct StateT2 * slot_29(struct StateT2 * v1023_p) {
  lockstep_assert(((v1023_p->a)->timer) == ((v1023_p->b)->timer));
  lockstep_assume(((v1023_p->a)->timer) == ((v1023_p->b)->timer));
  int v1024_a = (v1023_p->a)->timer;
  int v1024_b = (v1023_p->b)->timer;
  int v1032_a = v1024_a + 1;
  int v1032_b = v1024_b + 1;
  (v1023_p->a)->timer = v1032_a;
  (v1023_p->b)->timer = v1032_b;
  int * v1026_a = (v1023_p->a)->regs;
  int * v1026_b = (v1023_p->b)->regs;
  int v1027_a = v1026_a[6];
  int v1027_b = v1026_b[6];
  int * v1028_a = (v1023_p->a)->regs;
  int * v1028_b = (v1023_p->b)->regs;
  int v1036_a = v1027_a & 31;
  int v1036_b = v1027_b & 31;
  v1028_a[6] = v1036_a;
  v1028_b[6] = v1036_b;
  struct StateT2 * v1030_p = slot_30(v1023_p);
  return v1030_p;
}

struct StateT2 * slot_55(struct StateT2 * v1909_p) {
  lockstep_assert(((v1909_p->a)->timer) == ((v1909_p->b)->timer));
  lockstep_assume(((v1909_p->a)->timer) == ((v1909_p->b)->timer));
  int v1910_a = (v1909_p->a)->timer;
  int v1910_b = (v1909_p->b)->timer;
  int v1918_a = v1910_a + 1;
  int v1918_b = v1910_b + 1;
  (v1909_p->a)->timer = v1918_a;
  (v1909_p->b)->timer = v1918_b;
  int * v1912_a = (v1909_p->a)->regs;
  int * v1912_b = (v1909_p->b)->regs;
  int v1913_a = v1912_a[6];
  int v1913_b = v1912_b[6];
  int * v1914_a = (v1909_p->a)->regs;
  int * v1914_b = (v1909_p->b)->regs;
  int v1922_a = v1913_a << 2;
  int v1922_b = v1913_b << 2;
  v1914_a[6] = v1922_a;
  v1914_b[6] = v1922_b;
  struct StateT2 * v1916_p = slot_56(v1909_p);
  return v1916_p;
}

struct StateT2 * slot_16(struct StateT2 * v533_p) {
  lockstep_assert(((v533_p->a)->timer) == ((v533_p->b)->timer));
  lockstep_assume(((v533_p->a)->timer) == ((v533_p->b)->timer));
  int v534_a = (v533_p->a)->timer;
  int v534_b = (v533_p->b)->timer;
  int v592_a = v534_a + 1;
  int v592_b = v534_b + 1;
  (v533_p->a)->timer = v592_a;
  (v533_p->b)->timer = v592_b;
  int * v536_a = (v533_p->a)->regs;
  int * v536_b = (v533_p->b)->regs;
  int v537_a = v536_a[6];
  int v537_b = v536_b[6];
  int * v538_a = (v533_p->a)->cache_keys;
  int * v538_b = (v533_p->b)->cache_keys;
  int v539_a = v538_a[0];
  int v539_b = v538_b[0];
  bool v597_a = v539_a == ((int)((unsigned int)v537_a >> 2));
  bool v597_b = v539_b == ((int)((unsigned int)v537_b >> 2));
  int v587_a;
  if (v597_a) {
    int * v540_a = (v533_p->a)->cache_vals;
    int v541_a = v540_a[0];
    v587_a = v541_a;
  } else {
    int * v543_a = (v533_p->a)->cache_keys;
    int v544_a = v543_a[1];
    bool v602_a = v544_a == ((int)((unsigned int)v537_a >> 2));
    int v585_a;
    if (v602_a) {
      int * v545_a = (v533_p->a)->cache_vals;
      int v546_a = v545_a[1];
      int * v547_a = (v533_p->a)->cache_keys;
      int * v548_a = (v533_p->a)->cache_keys;
      int v549_a = v548_a[0];
      v547_a[1] = v549_a;
      int * v551_a = (v533_p->a)->cache_vals;
      int * v552_a = (v533_p->a)->cache_vals;
      int v553_a = v552_a[0];
      v551_a[1] = v553_a;
      int * v555_a = (v533_p->a)->cache_keys;
      int v611_a = (int)((unsigned int)v537_a >> 2);
      v555_a[0] = v611_a;
      int * v557_a = (v533_p->a)->cache_vals;
      v557_a[0] = v546_a;
      int v559_a = (v533_p->a)->timer;
      int v614_a = v559_a + 1;
      (v533_p->a)->timer = v614_a;
      v585_a = v546_a;
    } else {
      int * v562_a = (v533_p->a)->mem;
      int v616_a = (int)((unsigned int)v537_a >> 2);
      int v563_a = v562_a[v616_a];
      int * v564_a = (v533_p->a)->mem;
      int * v565_a = (v533_p->a)->cache_keys;
      int v566_a = v565_a[1];
      int * v567_a = (v533_p->a)->cache_vals;
      int v568_a = v567_a[1];
      v564_a[v566_a] = v568_a;
      int * v570_a = (v533_p->a)->cache_keys;
      int * v571_a = (v533_p->a)->cache_keys;
      int v572_a = v571_a[0];
      v570_a[1] = v572_a;
      int * v574_a = (v533_p->a)->cache_vals;
      int * v575_a = (v533_p->a)->cache_vals;
      int v576_a = v575_a[0];
      v574_a[1] = v576_a;
      int * v578_a = (v533_p->a)->cache_keys;
      v578_a[0] = v616_a;
      int * v580_a = (v533_p->a)->cache_vals;
      v580_a[0] = v563_a;
      int v582_a = (v533_p->a)->timer;
      int v631_a = v582_a + 100;
      (v533_p->a)->timer = v631_a;
      v585_a = v563_a;
    }
    v587_a = v585_a;
  }
  int v587_b;
  if (v597_b) {
    int * v540_b = (v533_p->b)->cache_vals;
    int v541_b = v540_b[0];
    v587_b = v541_b;
  } else {
    int * v543_b = (v533_p->b)->cache_keys;
    int v544_b = v543_b[1];
    bool v602_b = v544_b == ((int)((unsigned int)v537_b >> 2));
    int v585_b;
    if (v602_b) {
      int * v545_b = (v533_p->b)->cache_vals;
      int v546_b = v545_b[1];
      int * v547_b = (v533_p->b)->cache_keys;
      int * v548_b = (v533_p->b)->cache_keys;
      int v549_b = v548_b[0];
      v547_b[1] = v549_b;
      int * v551_b = (v533_p->b)->cache_vals;
      int * v552_b = (v533_p->b)->cache_vals;
      int v553_b = v552_b[0];
      v551_b[1] = v553_b;
      int * v555_b = (v533_p->b)->cache_keys;
      int v611_b = (int)((unsigned int)v537_b >> 2);
      v555_b[0] = v611_b;
      int * v557_b = (v533_p->b)->cache_vals;
      v557_b[0] = v546_b;
      int v559_b = (v533_p->b)->timer;
      int v614_b = v559_b + 1;
      (v533_p->b)->timer = v614_b;
      v585_b = v546_b;
    } else {
      int * v562_b = (v533_p->b)->mem;
      int v616_b = (int)((unsigned int)v537_b >> 2);
      int v563_b = v562_b[v616_b];
      int * v564_b = (v533_p->b)->mem;
      int * v565_b = (v533_p->b)->cache_keys;
      int v566_b = v565_b[1];
      int * v567_b = (v533_p->b)->cache_vals;
      int v568_b = v567_b[1];
      v564_b[v566_b] = v568_b;
      int * v570_b = (v533_p->b)->cache_keys;
      int * v571_b = (v533_p->b)->cache_keys;
      int v572_b = v571_b[0];
      v570_b[1] = v572_b;
      int * v574_b = (v533_p->b)->cache_vals;
      int * v575_b = (v533_p->b)->cache_vals;
      int v576_b = v575_b[0];
      v574_b[1] = v576_b;
      int * v578_b = (v533_p->b)->cache_keys;
      v578_b[0] = v616_b;
      int * v580_b = (v533_p->b)->cache_vals;
      v580_b[0] = v563_b;
      int v582_b = (v533_p->b)->timer;
      int v631_b = v582_b + 100;
      (v533_p->b)->timer = v631_b;
      v585_b = v563_b;
    }
    v587_b = v585_b;
  }
  int * v588_a = (v533_p->a)->regs;
  int * v588_b = (v533_p->b)->regs;
  v588_a[7] = v587_a;
  v588_b[7] = v587_b;
  struct StateT2 * v590_p = slot_17(v533_p);
  return v590_p;
}

struct StateT2 * slot_5(struct StateT2 * v169_p) {
  lockstep_assert(((v169_p->a)->timer) == ((v169_p->b)->timer));
  lockstep_assume(((v169_p->a)->timer) == ((v169_p->b)->timer));
  int v170_a = (v169_p->a)->timer;
  int v170_b = (v169_p->b)->timer;
  int v178_a = v170_a + 1;
  int v178_b = v170_b + 1;
  (v169_p->a)->timer = v178_a;
  (v169_p->b)->timer = v178_b;
  int * v172_a = (v169_p->a)->regs;
  int * v172_b = (v169_p->b)->regs;
  int v173_a = v172_a[6];
  int v173_b = v172_b[6];
  int * v174_a = (v169_p->a)->regs;
  int * v174_b = (v169_p->b)->regs;
  int v182_a = v173_a << 2;
  int v182_b = v173_b << 2;
  v174_a[6] = v182_a;
  v174_b[6] = v182_b;
  struct StateT2 * v176_p = slot_6(v169_p);
  return v176_p;
}

struct StateT2 * slot_7(struct StateT2 * v290_p) {
  lockstep_assert(((v290_p->a)->timer) == ((v290_p->b)->timer));
  lockstep_assume(((v290_p->a)->timer) == ((v290_p->b)->timer));
  int v291_a = (v290_p->a)->timer;
  int v291_b = (v290_p->b)->timer;
  int v301_a = v291_a + 1;
  int v301_b = v291_b + 1;
  (v290_p->a)->timer = v301_a;
  (v290_p->b)->timer = v301_b;
  int * v293_a = (v290_p->a)->regs;
  int * v293_b = (v290_p->b)->regs;
  int v294_a = v293_a[5];
  int v294_b = v293_b[5];
  int * v295_a = (v290_p->a)->regs;
  int * v295_b = (v290_p->b)->regs;
  int v296_a = v295_a[7];
  int v296_b = v295_b[7];
  int * v297_a = (v290_p->a)->regs;
  int * v297_b = (v290_p->b)->regs;
  int v307_a = v294_a ^ v296_a;
  int v307_b = v294_b ^ v296_b;
  v297_a[5] = v307_a;
  v297_b[5] = v307_b;
  struct StateT2 * v299_p = slot_8(v290_p);
  return v299_p;
}

struct StateT2 * slot_31(struct StateT2 * v1055_p) {
  lockstep_assert(((v1055_p->a)->timer) == ((v1055_p->b)->timer));
  lockstep_assume(((v1055_p->a)->timer) == ((v1055_p->b)->timer));
  int v1056_a = (v1055_p->a)->timer;
  int v1056_b = (v1055_p->b)->timer;
  int v1114_a = v1056_a + 1;
  int v1114_b = v1056_b + 1;
  (v1055_p->a)->timer = v1114_a;
  (v1055_p->b)->timer = v1114_b;
  int * v1058_a = (v1055_p->a)->regs;
  int * v1058_b = (v1055_p->b)->regs;
  int v1059_a = v1058_a[6];
  int v1059_b = v1058_b[6];
  int * v1060_a = (v1055_p->a)->cache_keys;
  int * v1060_b = (v1055_p->b)->cache_keys;
  int v1061_a = v1060_a[0];
  int v1061_b = v1060_b[0];
  bool v1119_a = v1061_a == ((int)((unsigned int)v1059_a >> 2));
  bool v1119_b = v1061_b == ((int)((unsigned int)v1059_b >> 2));
  int v1109_a;
  if (v1119_a) {
    int * v1062_a = (v1055_p->a)->cache_vals;
    int v1063_a = v1062_a[0];
    v1109_a = v1063_a;
  } else {
    int * v1065_a = (v1055_p->a)->cache_keys;
    int v1066_a = v1065_a[1];
    bool v1124_a = v1066_a == ((int)((unsigned int)v1059_a >> 2));
    int v1107_a;
    if (v1124_a) {
      int * v1067_a = (v1055_p->a)->cache_vals;
      int v1068_a = v1067_a[1];
      int * v1069_a = (v1055_p->a)->cache_keys;
      int * v1070_a = (v1055_p->a)->cache_keys;
      int v1071_a = v1070_a[0];
      v1069_a[1] = v1071_a;
      int * v1073_a = (v1055_p->a)->cache_vals;
      int * v1074_a = (v1055_p->a)->cache_vals;
      int v1075_a = v1074_a[0];
      v1073_a[1] = v1075_a;
      int * v1077_a = (v1055_p->a)->cache_keys;
      int v1133_a = (int)((unsigned int)v1059_a >> 2);
      v1077_a[0] = v1133_a;
      int * v1079_a = (v1055_p->a)->cache_vals;
      v1079_a[0] = v1068_a;
      int v1081_a = (v1055_p->a)->timer;
      int v1136_a = v1081_a + 1;
      (v1055_p->a)->timer = v1136_a;
      v1107_a = v1068_a;
    } else {
      int * v1084_a = (v1055_p->a)->mem;
      int v1138_a = (int)((unsigned int)v1059_a >> 2);
      int v1085_a = v1084_a[v1138_a];
      int * v1086_a = (v1055_p->a)->mem;
      int * v1087_a = (v1055_p->a)->cache_keys;
      int v1088_a = v1087_a[1];
      int * v1089_a = (v1055_p->a)->cache_vals;
      int v1090_a = v1089_a[1];
      v1086_a[v1088_a] = v1090_a;
      int * v1092_a = (v1055_p->a)->cache_keys;
      int * v1093_a = (v1055_p->a)->cache_keys;
      int v1094_a = v1093_a[0];
      v1092_a[1] = v1094_a;
      int * v1096_a = (v1055_p->a)->cache_vals;
      int * v1097_a = (v1055_p->a)->cache_vals;
      int v1098_a = v1097_a[0];
      v1096_a[1] = v1098_a;
      int * v1100_a = (v1055_p->a)->cache_keys;
      v1100_a[0] = v1138_a;
      int * v1102_a = (v1055_p->a)->cache_vals;
      v1102_a[0] = v1085_a;
      int v1104_a = (v1055_p->a)->timer;
      int v1153_a = v1104_a + 100;
      (v1055_p->a)->timer = v1153_a;
      v1107_a = v1085_a;
    }
    v1109_a = v1107_a;
  }
  int v1109_b;
  if (v1119_b) {
    int * v1062_b = (v1055_p->b)->cache_vals;
    int v1063_b = v1062_b[0];
    v1109_b = v1063_b;
  } else {
    int * v1065_b = (v1055_p->b)->cache_keys;
    int v1066_b = v1065_b[1];
    bool v1124_b = v1066_b == ((int)((unsigned int)v1059_b >> 2));
    int v1107_b;
    if (v1124_b) {
      int * v1067_b = (v1055_p->b)->cache_vals;
      int v1068_b = v1067_b[1];
      int * v1069_b = (v1055_p->b)->cache_keys;
      int * v1070_b = (v1055_p->b)->cache_keys;
      int v1071_b = v1070_b[0];
      v1069_b[1] = v1071_b;
      int * v1073_b = (v1055_p->b)->cache_vals;
      int * v1074_b = (v1055_p->b)->cache_vals;
      int v1075_b = v1074_b[0];
      v1073_b[1] = v1075_b;
      int * v1077_b = (v1055_p->b)->cache_keys;
      int v1133_b = (int)((unsigned int)v1059_b >> 2);
      v1077_b[0] = v1133_b;
      int * v1079_b = (v1055_p->b)->cache_vals;
      v1079_b[0] = v1068_b;
      int v1081_b = (v1055_p->b)->timer;
      int v1136_b = v1081_b + 1;
      (v1055_p->b)->timer = v1136_b;
      v1107_b = v1068_b;
    } else {
      int * v1084_b = (v1055_p->b)->mem;
      int v1138_b = (int)((unsigned int)v1059_b >> 2);
      int v1085_b = v1084_b[v1138_b];
      int * v1086_b = (v1055_p->b)->mem;
      int * v1087_b = (v1055_p->b)->cache_keys;
      int v1088_b = v1087_b[1];
      int * v1089_b = (v1055_p->b)->cache_vals;
      int v1090_b = v1089_b[1];
      v1086_b[v1088_b] = v1090_b;
      int * v1092_b = (v1055_p->b)->cache_keys;
      int * v1093_b = (v1055_p->b)->cache_keys;
      int v1094_b = v1093_b[0];
      v1092_b[1] = v1094_b;
      int * v1096_b = (v1055_p->b)->cache_vals;
      int * v1097_b = (v1055_p->b)->cache_vals;
      int v1098_b = v1097_b[0];
      v1096_b[1] = v1098_b;
      int * v1100_b = (v1055_p->b)->cache_keys;
      v1100_b[0] = v1138_b;
      int * v1102_b = (v1055_p->b)->cache_vals;
      v1102_b[0] = v1085_b;
      int v1104_b = (v1055_p->b)->timer;
      int v1153_b = v1104_b + 100;
      (v1055_p->b)->timer = v1153_b;
      v1107_b = v1085_b;
    }
    v1109_b = v1107_b;
  }
  int * v1110_a = (v1055_p->a)->regs;
  int * v1110_b = (v1055_p->b)->regs;
  v1110_a[7] = v1109_a;
  v1110_b[7] = v1109_b;
  struct StateT2 * v1112_p = slot_32(v1055_p);
  return v1112_p;
}

struct StateT2 * slot_54(struct StateT2 * v1893_p) {
  lockstep_assert(((v1893_p->a)->timer) == ((v1893_p->b)->timer));
  lockstep_assume(((v1893_p->a)->timer) == ((v1893_p->b)->timer));
  int v1894_a = (v1893_p->a)->timer;
  int v1894_b = (v1893_p->b)->timer;
  int v1902_a = v1894_a + 1;
  int v1902_b = v1894_b + 1;
  (v1893_p->a)->timer = v1902_a;
  (v1893_p->b)->timer = v1902_b;
  int * v1896_a = (v1893_p->a)->regs;
  int * v1896_b = (v1893_p->b)->regs;
  int v1897_a = v1896_a[6];
  int v1897_b = v1896_b[6];
  int * v1898_a = (v1893_p->a)->regs;
  int * v1898_b = (v1893_p->b)->regs;
  int v1906_a = v1897_a & 31;
  int v1906_b = v1897_b & 31;
  v1898_a[6] = v1906_a;
  v1898_b[6] = v1906_b;
  struct StateT2 * v1900_p = slot_55(v1893_p);
  return v1900_p;
}

struct StateT2 * slot_26(struct StateT2 * v881_p) {
  lockstep_assert(((v881_p->a)->timer) == ((v881_p->b)->timer));
  lockstep_assume(((v881_p->a)->timer) == ((v881_p->b)->timer));
  int v882_a = (v881_p->a)->timer;
  int v882_b = (v881_p->b)->timer;
  int v940_a = v882_a + 1;
  int v940_b = v882_b + 1;
  (v881_p->a)->timer = v940_a;
  (v881_p->b)->timer = v940_b;
  int * v884_a = (v881_p->a)->regs;
  int * v884_b = (v881_p->b)->regs;
  int v885_a = v884_a[6];
  int v885_b = v884_b[6];
  int * v886_a = (v881_p->a)->cache_keys;
  int * v886_b = (v881_p->b)->cache_keys;
  int v887_a = v886_a[0];
  int v887_b = v886_b[0];
  bool v945_a = v887_a == ((int)((unsigned int)v885_a >> 2));
  bool v945_b = v887_b == ((int)((unsigned int)v885_b >> 2));
  int v935_a;
  if (v945_a) {
    int * v888_a = (v881_p->a)->cache_vals;
    int v889_a = v888_a[0];
    v935_a = v889_a;
  } else {
    int * v891_a = (v881_p->a)->cache_keys;
    int v892_a = v891_a[1];
    bool v950_a = v892_a == ((int)((unsigned int)v885_a >> 2));
    int v933_a;
    if (v950_a) {
      int * v893_a = (v881_p->a)->cache_vals;
      int v894_a = v893_a[1];
      int * v895_a = (v881_p->a)->cache_keys;
      int * v896_a = (v881_p->a)->cache_keys;
      int v897_a = v896_a[0];
      v895_a[1] = v897_a;
      int * v899_a = (v881_p->a)->cache_vals;
      int * v900_a = (v881_p->a)->cache_vals;
      int v901_a = v900_a[0];
      v899_a[1] = v901_a;
      int * v903_a = (v881_p->a)->cache_keys;
      int v959_a = (int)((unsigned int)v885_a >> 2);
      v903_a[0] = v959_a;
      int * v905_a = (v881_p->a)->cache_vals;
      v905_a[0] = v894_a;
      int v907_a = (v881_p->a)->timer;
      int v962_a = v907_a + 1;
      (v881_p->a)->timer = v962_a;
      v933_a = v894_a;
    } else {
      int * v910_a = (v881_p->a)->mem;
      int v964_a = (int)((unsigned int)v885_a >> 2);
      int v911_a = v910_a[v964_a];
      int * v912_a = (v881_p->a)->mem;
      int * v913_a = (v881_p->a)->cache_keys;
      int v914_a = v913_a[1];
      int * v915_a = (v881_p->a)->cache_vals;
      int v916_a = v915_a[1];
      v912_a[v914_a] = v916_a;
      int * v918_a = (v881_p->a)->cache_keys;
      int * v919_a = (v881_p->a)->cache_keys;
      int v920_a = v919_a[0];
      v918_a[1] = v920_a;
      int * v922_a = (v881_p->a)->cache_vals;
      int * v923_a = (v881_p->a)->cache_vals;
      int v924_a = v923_a[0];
      v922_a[1] = v924_a;
      int * v926_a = (v881_p->a)->cache_keys;
      v926_a[0] = v964_a;
      int * v928_a = (v881_p->a)->cache_vals;
      v928_a[0] = v911_a;
      int v930_a = (v881_p->a)->timer;
      int v979_a = v930_a + 100;
      (v881_p->a)->timer = v979_a;
      v933_a = v911_a;
    }
    v935_a = v933_a;
  }
  int v935_b;
  if (v945_b) {
    int * v888_b = (v881_p->b)->cache_vals;
    int v889_b = v888_b[0];
    v935_b = v889_b;
  } else {
    int * v891_b = (v881_p->b)->cache_keys;
    int v892_b = v891_b[1];
    bool v950_b = v892_b == ((int)((unsigned int)v885_b >> 2));
    int v933_b;
    if (v950_b) {
      int * v893_b = (v881_p->b)->cache_vals;
      int v894_b = v893_b[1];
      int * v895_b = (v881_p->b)->cache_keys;
      int * v896_b = (v881_p->b)->cache_keys;
      int v897_b = v896_b[0];
      v895_b[1] = v897_b;
      int * v899_b = (v881_p->b)->cache_vals;
      int * v900_b = (v881_p->b)->cache_vals;
      int v901_b = v900_b[0];
      v899_b[1] = v901_b;
      int * v903_b = (v881_p->b)->cache_keys;
      int v959_b = (int)((unsigned int)v885_b >> 2);
      v903_b[0] = v959_b;
      int * v905_b = (v881_p->b)->cache_vals;
      v905_b[0] = v894_b;
      int v907_b = (v881_p->b)->timer;
      int v962_b = v907_b + 1;
      (v881_p->b)->timer = v962_b;
      v933_b = v894_b;
    } else {
      int * v910_b = (v881_p->b)->mem;
      int v964_b = (int)((unsigned int)v885_b >> 2);
      int v911_b = v910_b[v964_b];
      int * v912_b = (v881_p->b)->mem;
      int * v913_b = (v881_p->b)->cache_keys;
      int v914_b = v913_b[1];
      int * v915_b = (v881_p->b)->cache_vals;
      int v916_b = v915_b[1];
      v912_b[v914_b] = v916_b;
      int * v918_b = (v881_p->b)->cache_keys;
      int * v919_b = (v881_p->b)->cache_keys;
      int v920_b = v919_b[0];
      v918_b[1] = v920_b;
      int * v922_b = (v881_p->b)->cache_vals;
      int * v923_b = (v881_p->b)->cache_vals;
      int v924_b = v923_b[0];
      v922_b[1] = v924_b;
      int * v926_b = (v881_p->b)->cache_keys;
      v926_b[0] = v964_b;
      int * v928_b = (v881_p->b)->cache_vals;
      v928_b[0] = v911_b;
      int v930_b = (v881_p->b)->timer;
      int v979_b = v930_b + 100;
      (v881_p->b)->timer = v979_b;
      v933_b = v911_b;
    }
    v935_b = v933_b;
  }
  int * v936_a = (v881_p->a)->regs;
  int * v936_b = (v881_p->b)->regs;
  v936_a[7] = v935_a;
  v936_b[7] = v935_b;
  struct StateT2 * v938_p = slot_27(v881_p);
  return v938_p;
}

struct StateT2 * slot_10(struct StateT2 * v343_p) {
  lockstep_assert(((v343_p->a)->timer) == ((v343_p->b)->timer));
  lockstep_assume(((v343_p->a)->timer) == ((v343_p->b)->timer));
  int v344_a = (v343_p->a)->timer;
  int v344_b = (v343_p->b)->timer;
  int v352_a = v344_a + 1;
  int v352_b = v344_b + 1;
  (v343_p->a)->timer = v352_a;
  (v343_p->b)->timer = v352_b;
  int * v346_a = (v343_p->a)->regs;
  int * v346_b = (v343_p->b)->regs;
  int v347_a = v346_a[6];
  int v347_b = v346_b[6];
  int * v348_a = (v343_p->a)->regs;
  int * v348_b = (v343_p->b)->regs;
  int v356_a = v347_a << 2;
  int v356_b = v347_b << 2;
  v348_a[6] = v356_a;
  v348_b[6] = v356_b;
  struct StateT2 * v350_p = slot_11(v343_p);
  return v350_p;
}

struct StateT2 * slot_19(struct StateT2 * v675_p) {
  lockstep_assert(((v675_p->a)->timer) == ((v675_p->b)->timer));
  lockstep_assume(((v675_p->a)->timer) == ((v675_p->b)->timer));
  int v676_a = (v675_p->a)->timer;
  int v676_b = (v675_p->b)->timer;
  int v684_a = v676_a + 1;
  int v684_b = v676_b + 1;
  (v675_p->a)->timer = v684_a;
  (v675_p->b)->timer = v684_b;
  int * v678_a = (v675_p->a)->regs;
  int * v678_b = (v675_p->b)->regs;
  int v679_a = v678_a[6];
  int v679_b = v678_b[6];
  int * v680_a = (v675_p->a)->regs;
  int * v680_b = (v675_p->b)->regs;
  int v688_a = v679_a & 31;
  int v688_b = v679_b & 31;
  v680_a[6] = v688_a;
  v680_b[6] = v688_b;
  struct StateT2 * v682_p = slot_20(v675_p);
  return v682_p;
}

struct StateT2 * slot_58(struct StateT2 * v2050_p) {
  lockstep_assert(((v2050_p->a)->timer) == ((v2050_p->b)->timer));
  lockstep_assume(((v2050_p->a)->timer) == ((v2050_p->b)->timer));
  int v2051_a = (v2050_p->a)->timer;
  int v2051_b = (v2050_p->b)->timer;
  int v2059_a = v2051_a + 1;
  int v2059_b = v2051_b + 1;
  (v2050_p->a)->timer = v2059_a;
  (v2050_p->b)->timer = v2059_b;
  int * v2053_a = (v2050_p->a)->regs;
  int * v2053_b = (v2050_p->b)->regs;
  int v2054_a = v2053_a[11];
  int v2054_b = v2053_b[11];
  int * v2055_a = (v2050_p->a)->regs;
  int * v2055_b = (v2050_p->b)->regs;
  int v2064_a = (int)((unsigned int)v2054_a >> 25);
  int v2064_b = (int)((unsigned int)v2054_b >> 25);
  v2055_a[6] = v2064_a;
  v2055_b[6] = v2064_b;
  struct StateT2 * v2057_p = slot_59(v2050_p);
  return v2057_p;
}

struct StateT2 * slot_14(struct StateT2 * v501_p) {
  lockstep_assert(((v501_p->a)->timer) == ((v501_p->b)->timer));
  lockstep_assume(((v501_p->a)->timer) == ((v501_p->b)->timer));
  int v502_a = (v501_p->a)->timer;
  int v502_b = (v501_p->b)->timer;
  int v510_a = v502_a + 1;
  int v510_b = v502_b + 1;
  (v501_p->a)->timer = v510_a;
  (v501_p->b)->timer = v510_b;
  int * v504_a = (v501_p->a)->regs;
  int * v504_b = (v501_p->b)->regs;
  int v505_a = v504_a[6];
  int v505_b = v504_b[6];
  int * v506_a = (v501_p->a)->regs;
  int * v506_b = (v501_p->b)->regs;
  int v514_a = v505_a & 31;
  int v514_b = v505_b & 31;
  v506_a[6] = v514_a;
  v506_b[6] = v514_b;
  struct StateT2 * v508_p = slot_15(v501_p);
  return v508_p;
}

struct StateT2 * slot_53(struct StateT2 * v1876_p) {
  lockstep_assert(((v1876_p->a)->timer) == ((v1876_p->b)->timer));
  lockstep_assume(((v1876_p->a)->timer) == ((v1876_p->b)->timer));
  int v1877_a = (v1876_p->a)->timer;
  int v1877_b = (v1876_p->b)->timer;
  int v1885_a = v1877_a + 1;
  int v1885_b = v1877_b + 1;
  (v1876_p->a)->timer = v1885_a;
  (v1876_p->b)->timer = v1885_b;
  int * v1879_a = (v1876_p->a)->regs;
  int * v1879_b = (v1876_p->b)->regs;
  int v1880_a = v1879_a[11];
  int v1880_b = v1879_b[11];
  int * v1881_a = (v1876_p->a)->regs;
  int * v1881_b = (v1876_p->b)->regs;
  int v1890_a = (int)((unsigned int)v1880_a >> 20);
  int v1890_b = (int)((unsigned int)v1880_b >> 20);
  v1881_a[6] = v1890_a;
  v1881_b[6] = v1890_b;
  struct StateT2 * v1883_p = slot_54(v1876_p);
  return v1883_p;
}

struct StateT2 * slot_44(struct StateT2 * v1545_p) {
  lockstep_assert(((v1545_p->a)->timer) == ((v1545_p->b)->timer));
  lockstep_assume(((v1545_p->a)->timer) == ((v1545_p->b)->timer));
  int v1546_a = (v1545_p->a)->timer;
  int v1546_b = (v1545_p->b)->timer;
  int v1554_a = v1546_a + 1;
  int v1554_b = v1546_b + 1;
  (v1545_p->a)->timer = v1554_a;
  (v1545_p->b)->timer = v1554_b;
  int * v1548_a = (v1545_p->a)->regs;
  int * v1548_b = (v1545_p->b)->regs;
  int v1549_a = v1548_a[6];
  int v1549_b = v1548_b[6];
  int * v1550_a = (v1545_p->a)->regs;
  int * v1550_b = (v1545_p->b)->regs;
  int v1558_a = v1549_a & 31;
  int v1558_b = v1549_b & 31;
  v1550_a[6] = v1558_a;
  v1550_b[6] = v1558_b;
  struct StateT2 * v1552_p = slot_45(v1545_p);
  return v1552_p;
}

struct StateT2 * slot_28(struct StateT2 * v1006_p) {
  lockstep_assert(((v1006_p->a)->timer) == ((v1006_p->b)->timer));
  lockstep_assume(((v1006_p->a)->timer) == ((v1006_p->b)->timer));
  int v1007_a = (v1006_p->a)->timer;
  int v1007_b = (v1006_p->b)->timer;
  int v1015_a = v1007_a + 1;
  int v1015_b = v1007_b + 1;
  (v1006_p->a)->timer = v1015_a;
  (v1006_p->b)->timer = v1015_b;
  int * v1009_a = (v1006_p->a)->regs;
  int * v1009_b = (v1006_p->b)->regs;
  int v1010_a = v1009_a[10];
  int v1010_b = v1009_b[10];
  int * v1011_a = (v1006_p->a)->regs;
  int * v1011_b = (v1006_p->b)->regs;
  int v1020_a = (int)((unsigned int)v1010_a >> 25);
  int v1020_b = (int)((unsigned int)v1010_b >> 25);
  v1011_a[6] = v1020_a;
  v1011_b[6] = v1020_b;
  struct StateT2 * v1013_p = slot_29(v1006_p);
  return v1013_p;
}

struct StateT2 * slot_32(struct StateT2 * v1160_p) {
  lockstep_assert(((v1160_p->a)->timer) == ((v1160_p->b)->timer));
  lockstep_assume(((v1160_p->a)->timer) == ((v1160_p->b)->timer));
  int v1161_a = (v1160_p->a)->timer;
  int v1161_b = (v1160_p->b)->timer;
  int v1171_a = v1161_a + 1;
  int v1171_b = v1161_b + 1;
  (v1160_p->a)->timer = v1171_a;
  (v1160_p->b)->timer = v1171_b;
  int * v1163_a = (v1160_p->a)->regs;
  int * v1163_b = (v1160_p->b)->regs;
  int v1164_a = v1163_a[5];
  int v1164_b = v1163_b[5];
  int * v1165_a = (v1160_p->a)->regs;
  int * v1165_b = (v1160_p->b)->regs;
  int v1166_a = v1165_a[7];
  int v1166_b = v1165_b[7];
  int * v1167_a = (v1160_p->a)->regs;
  int * v1167_b = (v1160_p->b)->regs;
  int v1177_a = v1164_a ^ v1166_a;
  int v1177_b = v1164_b ^ v1166_b;
  v1167_a[5] = v1177_a;
  v1167_b[5] = v1177_b;
  struct StateT2 * v1169_p = slot_33(v1160_p);
  return v1169_p;
}

struct StateT2 * slot_17(struct StateT2 * v638_p) {
  lockstep_assert(((v638_p->a)->timer) == ((v638_p->b)->timer));
  lockstep_assume(((v638_p->a)->timer) == ((v638_p->b)->timer));
  int v639_a = (v638_p->a)->timer;
  int v639_b = (v638_p->b)->timer;
  int v649_a = v639_a + 1;
  int v649_b = v639_b + 1;
  (v638_p->a)->timer = v649_a;
  (v638_p->b)->timer = v649_b;
  int * v641_a = (v638_p->a)->regs;
  int * v641_b = (v638_p->b)->regs;
  int v642_a = v641_a[5];
  int v642_b = v641_b[5];
  int * v643_a = (v638_p->a)->regs;
  int * v643_b = (v638_p->b)->regs;
  int v644_a = v643_a[7];
  int v644_b = v643_b[7];
  int * v645_a = (v638_p->a)->regs;
  int * v645_b = (v638_p->b)->regs;
  int v655_a = v642_a ^ v644_a;
  int v655_b = v642_b ^ v644_b;
  v645_a[5] = v655_a;
  v645_b[5] = v655_b;
  struct StateT2 * v647_p = slot_18(v638_p);
  return v647_p;
}

struct StateT2 * slot_49(struct StateT2 * v1719_p) {
  lockstep_assert(((v1719_p->a)->timer) == ((v1719_p->b)->timer));
  lockstep_assume(((v1719_p->a)->timer) == ((v1719_p->b)->timer));
  int v1720_a = (v1719_p->a)->timer;
  int v1720_b = (v1719_p->b)->timer;
  int v1728_a = v1720_a + 1;
  int v1728_b = v1720_b + 1;
  (v1719_p->a)->timer = v1728_a;
  (v1719_p->b)->timer = v1728_b;
  int * v1722_a = (v1719_p->a)->regs;
  int * v1722_b = (v1719_p->b)->regs;
  int v1723_a = v1722_a[6];
  int v1723_b = v1722_b[6];
  int * v1724_a = (v1719_p->a)->regs;
  int * v1724_b = (v1719_p->b)->regs;
  int v1732_a = v1723_a & 31;
  int v1732_b = v1723_b & 31;
  v1724_a[6] = v1732_a;
  v1724_b[6] = v1732_b;
  struct StateT2 * v1726_p = slot_50(v1719_p);
  return v1726_p;
}

struct StateT2 * slot_33(struct StateT2 * v1180_p) {
  lockstep_assert(((v1180_p->a)->timer) == ((v1180_p->b)->timer));
  lockstep_assume(((v1180_p->a)->timer) == ((v1180_p->b)->timer));
  int v1181_a = (v1180_p->a)->timer;
  int v1181_b = (v1180_p->b)->timer;
  int v1189_a = v1181_a + 1;
  int v1189_b = v1181_b + 1;
  (v1180_p->a)->timer = v1189_a;
  (v1180_p->b)->timer = v1189_b;
  int * v1183_a = (v1180_p->a)->regs;
  int * v1183_b = (v1180_p->b)->regs;
  int v1184_a = v1183_a[11];
  int v1184_b = v1183_b[11];
  int * v1185_a = (v1180_p->a)->regs;
  int * v1185_b = (v1180_p->b)->regs;
  v1185_a[6] = v1184_a;
  v1185_b[6] = v1184_b;
  struct StateT2 * v1187_p = slot_34(v1180_p);
  return v1187_p;
}

struct StateT2 * slot_50(struct StateT2 * v1735_p) {
  lockstep_assert(((v1735_p->a)->timer) == ((v1735_p->b)->timer));
  lockstep_assume(((v1735_p->a)->timer) == ((v1735_p->b)->timer));
  int v1736_a = (v1735_p->a)->timer;
  int v1736_b = (v1735_p->b)->timer;
  int v1744_a = v1736_a + 1;
  int v1744_b = v1736_b + 1;
  (v1735_p->a)->timer = v1744_a;
  (v1735_p->b)->timer = v1744_b;
  int * v1738_a = (v1735_p->a)->regs;
  int * v1738_b = (v1735_p->b)->regs;
  int v1739_a = v1738_a[6];
  int v1739_b = v1738_b[6];
  int * v1740_a = (v1735_p->a)->regs;
  int * v1740_b = (v1735_p->b)->regs;
  int v1748_a = v1739_a << 2;
  int v1748_b = v1739_b << 2;
  v1740_a[6] = v1748_a;
  v1740_b[6] = v1748_b;
  struct StateT2 * v1742_p = slot_51(v1735_p);
  return v1742_p;
}

struct StateT2 * slot_36(struct StateT2 * v1229_p) {
  lockstep_assert(((v1229_p->a)->timer) == ((v1229_p->b)->timer));
  lockstep_assume(((v1229_p->a)->timer) == ((v1229_p->b)->timer));
  int v1230_a = (v1229_p->a)->timer;
  int v1230_b = (v1229_p->b)->timer;
  int v1288_a = v1230_a + 1;
  int v1288_b = v1230_b + 1;
  (v1229_p->a)->timer = v1288_a;
  (v1229_p->b)->timer = v1288_b;
  int * v1232_a = (v1229_p->a)->regs;
  int * v1232_b = (v1229_p->b)->regs;
  int v1233_a = v1232_a[6];
  int v1233_b = v1232_b[6];
  int * v1234_a = (v1229_p->a)->cache_keys;
  int * v1234_b = (v1229_p->b)->cache_keys;
  int v1235_a = v1234_a[0];
  int v1235_b = v1234_b[0];
  bool v1293_a = v1235_a == ((int)((unsigned int)v1233_a >> 2));
  bool v1293_b = v1235_b == ((int)((unsigned int)v1233_b >> 2));
  int v1283_a;
  if (v1293_a) {
    int * v1236_a = (v1229_p->a)->cache_vals;
    int v1237_a = v1236_a[0];
    v1283_a = v1237_a;
  } else {
    int * v1239_a = (v1229_p->a)->cache_keys;
    int v1240_a = v1239_a[1];
    bool v1298_a = v1240_a == ((int)((unsigned int)v1233_a >> 2));
    int v1281_a;
    if (v1298_a) {
      int * v1241_a = (v1229_p->a)->cache_vals;
      int v1242_a = v1241_a[1];
      int * v1243_a = (v1229_p->a)->cache_keys;
      int * v1244_a = (v1229_p->a)->cache_keys;
      int v1245_a = v1244_a[0];
      v1243_a[1] = v1245_a;
      int * v1247_a = (v1229_p->a)->cache_vals;
      int * v1248_a = (v1229_p->a)->cache_vals;
      int v1249_a = v1248_a[0];
      v1247_a[1] = v1249_a;
      int * v1251_a = (v1229_p->a)->cache_keys;
      int v1307_a = (int)((unsigned int)v1233_a >> 2);
      v1251_a[0] = v1307_a;
      int * v1253_a = (v1229_p->a)->cache_vals;
      v1253_a[0] = v1242_a;
      int v1255_a = (v1229_p->a)->timer;
      int v1310_a = v1255_a + 1;
      (v1229_p->a)->timer = v1310_a;
      v1281_a = v1242_a;
    } else {
      int * v1258_a = (v1229_p->a)->mem;
      int v1312_a = (int)((unsigned int)v1233_a >> 2);
      int v1259_a = v1258_a[v1312_a];
      int * v1260_a = (v1229_p->a)->mem;
      int * v1261_a = (v1229_p->a)->cache_keys;
      int v1262_a = v1261_a[1];
      int * v1263_a = (v1229_p->a)->cache_vals;
      int v1264_a = v1263_a[1];
      v1260_a[v1262_a] = v1264_a;
      int * v1266_a = (v1229_p->a)->cache_keys;
      int * v1267_a = (v1229_p->a)->cache_keys;
      int v1268_a = v1267_a[0];
      v1266_a[1] = v1268_a;
      int * v1270_a = (v1229_p->a)->cache_vals;
      int * v1271_a = (v1229_p->a)->cache_vals;
      int v1272_a = v1271_a[0];
      v1270_a[1] = v1272_a;
      int * v1274_a = (v1229_p->a)->cache_keys;
      v1274_a[0] = v1312_a;
      int * v1276_a = (v1229_p->a)->cache_vals;
      v1276_a[0] = v1259_a;
      int v1278_a = (v1229_p->a)->timer;
      int v1327_a = v1278_a + 100;
      (v1229_p->a)->timer = v1327_a;
      v1281_a = v1259_a;
    }
    v1283_a = v1281_a;
  }
  int v1283_b;
  if (v1293_b) {
    int * v1236_b = (v1229_p->b)->cache_vals;
    int v1237_b = v1236_b[0];
    v1283_b = v1237_b;
  } else {
    int * v1239_b = (v1229_p->b)->cache_keys;
    int v1240_b = v1239_b[1];
    bool v1298_b = v1240_b == ((int)((unsigned int)v1233_b >> 2));
    int v1281_b;
    if (v1298_b) {
      int * v1241_b = (v1229_p->b)->cache_vals;
      int v1242_b = v1241_b[1];
      int * v1243_b = (v1229_p->b)->cache_keys;
      int * v1244_b = (v1229_p->b)->cache_keys;
      int v1245_b = v1244_b[0];
      v1243_b[1] = v1245_b;
      int * v1247_b = (v1229_p->b)->cache_vals;
      int * v1248_b = (v1229_p->b)->cache_vals;
      int v1249_b = v1248_b[0];
      v1247_b[1] = v1249_b;
      int * v1251_b = (v1229_p->b)->cache_keys;
      int v1307_b = (int)((unsigned int)v1233_b >> 2);
      v1251_b[0] = v1307_b;
      int * v1253_b = (v1229_p->b)->cache_vals;
      v1253_b[0] = v1242_b;
      int v1255_b = (v1229_p->b)->timer;
      int v1310_b = v1255_b + 1;
      (v1229_p->b)->timer = v1310_b;
      v1281_b = v1242_b;
    } else {
      int * v1258_b = (v1229_p->b)->mem;
      int v1312_b = (int)((unsigned int)v1233_b >> 2);
      int v1259_b = v1258_b[v1312_b];
      int * v1260_b = (v1229_p->b)->mem;
      int * v1261_b = (v1229_p->b)->cache_keys;
      int v1262_b = v1261_b[1];
      int * v1263_b = (v1229_p->b)->cache_vals;
      int v1264_b = v1263_b[1];
      v1260_b[v1262_b] = v1264_b;
      int * v1266_b = (v1229_p->b)->cache_keys;
      int * v1267_b = (v1229_p->b)->cache_keys;
      int v1268_b = v1267_b[0];
      v1266_b[1] = v1268_b;
      int * v1270_b = (v1229_p->b)->cache_vals;
      int * v1271_b = (v1229_p->b)->cache_vals;
      int v1272_b = v1271_b[0];
      v1270_b[1] = v1272_b;
      int * v1274_b = (v1229_p->b)->cache_keys;
      v1274_b[0] = v1312_b;
      int * v1276_b = (v1229_p->b)->cache_vals;
      v1276_b[0] = v1259_b;
      int v1278_b = (v1229_p->b)->timer;
      int v1327_b = v1278_b + 100;
      (v1229_p->b)->timer = v1327_b;
      v1281_b = v1259_b;
    }
    v1283_b = v1281_b;
  }
  int * v1284_a = (v1229_p->a)->regs;
  int * v1284_b = (v1229_p->b)->regs;
  v1284_a[7] = v1283_a;
  v1284_b[7] = v1283_b;
  struct StateT2 * v1286_p = slot_37(v1229_p);
  return v1286_p;
}

struct StateT2 * slot_37(struct StateT2 * v1334_p) {
  lockstep_assert(((v1334_p->a)->timer) == ((v1334_p->b)->timer));
  lockstep_assume(((v1334_p->a)->timer) == ((v1334_p->b)->timer));
  int v1335_a = (v1334_p->a)->timer;
  int v1335_b = (v1334_p->b)->timer;
  int v1345_a = v1335_a + 1;
  int v1345_b = v1335_b + 1;
  (v1334_p->a)->timer = v1345_a;
  (v1334_p->b)->timer = v1345_b;
  int * v1337_a = (v1334_p->a)->regs;
  int * v1337_b = (v1334_p->b)->regs;
  int v1338_a = v1337_a[5];
  int v1338_b = v1337_b[5];
  int * v1339_a = (v1334_p->a)->regs;
  int * v1339_b = (v1334_p->b)->regs;
  int v1340_a = v1339_a[7];
  int v1340_b = v1339_b[7];
  int * v1341_a = (v1334_p->a)->regs;
  int * v1341_b = (v1334_p->b)->regs;
  int v1351_a = v1338_a ^ v1340_a;
  int v1351_b = v1338_b ^ v1340_b;
  v1341_a[5] = v1351_a;
  v1341_b[5] = v1351_b;
  struct StateT2 * v1343_p = slot_38(v1334_p);
  return v1343_p;
}

struct StateT2 * slot_57(struct StateT2 * v2030_p) {
  lockstep_assert(((v2030_p->a)->timer) == ((v2030_p->b)->timer));
  lockstep_assume(((v2030_p->a)->timer) == ((v2030_p->b)->timer));
  int v2031_a = (v2030_p->a)->timer;
  int v2031_b = (v2030_p->b)->timer;
  int v2041_a = v2031_a + 1;
  int v2041_b = v2031_b + 1;
  (v2030_p->a)->timer = v2041_a;
  (v2030_p->b)->timer = v2041_b;
  int * v2033_a = (v2030_p->a)->regs;
  int * v2033_b = (v2030_p->b)->regs;
  int v2034_a = v2033_a[5];
  int v2034_b = v2033_b[5];
  int * v2035_a = (v2030_p->a)->regs;
  int * v2035_b = (v2030_p->b)->regs;
  int v2036_a = v2035_a[7];
  int v2036_b = v2035_b[7];
  int * v2037_a = (v2030_p->a)->regs;
  int * v2037_b = (v2030_p->b)->regs;
  int v2047_a = v2034_a ^ v2036_a;
  int v2047_b = v2034_b ^ v2036_b;
  v2037_a[5] = v2047_a;
  v2037_b[5] = v2047_b;
  struct StateT2 * v2039_p = slot_58(v2030_p);
  return v2039_p;
}

struct StateT2 * slot_59(struct StateT2 * v2067_p) {
  lockstep_assert(((v2067_p->a)->timer) == ((v2067_p->b)->timer));
  lockstep_assume(((v2067_p->a)->timer) == ((v2067_p->b)->timer));
  int v2068_a = (v2067_p->a)->timer;
  int v2068_b = (v2067_p->b)->timer;
  int v2076_a = v2068_a + 1;
  int v2076_b = v2068_b + 1;
  (v2067_p->a)->timer = v2076_a;
  (v2067_p->b)->timer = v2076_b;
  int * v2070_a = (v2067_p->a)->regs;
  int * v2070_b = (v2067_p->b)->regs;
  int v2071_a = v2070_a[6];
  int v2071_b = v2070_b[6];
  int * v2072_a = (v2067_p->a)->regs;
  int * v2072_b = (v2067_p->b)->regs;
  int v2080_a = v2071_a & 31;
  int v2080_b = v2071_b & 31;
  v2072_a[6] = v2080_a;
  v2072_b[6] = v2080_b;
  struct StateT2 * v2074_p = slot_60(v2067_p);
  return v2074_p;
}

struct StateT2 * slot_40(struct StateT2 * v1387_p) {
  lockstep_assert(((v1387_p->a)->timer) == ((v1387_p->b)->timer));
  lockstep_assume(((v1387_p->a)->timer) == ((v1387_p->b)->timer));
  int v1388_a = (v1387_p->a)->timer;
  int v1388_b = (v1387_p->b)->timer;
  int v1396_a = v1388_a + 1;
  int v1396_b = v1388_b + 1;
  (v1387_p->a)->timer = v1396_a;
  (v1387_p->b)->timer = v1396_b;
  int * v1390_a = (v1387_p->a)->regs;
  int * v1390_b = (v1387_p->b)->regs;
  int v1391_a = v1390_a[6];
  int v1391_b = v1390_b[6];
  int * v1392_a = (v1387_p->a)->regs;
  int * v1392_b = (v1387_p->b)->regs;
  int v1400_a = v1391_a << 2;
  int v1400_b = v1391_b << 2;
  v1392_a[6] = v1400_a;
  v1392_b[6] = v1400_b;
  struct StateT2 * v1394_p = slot_41(v1387_p);
  return v1394_p;
}

struct StateT2 * slot_27(struct StateT2 * v986_p) {
  lockstep_assert(((v986_p->a)->timer) == ((v986_p->b)->timer));
  lockstep_assume(((v986_p->a)->timer) == ((v986_p->b)->timer));
  int v987_a = (v986_p->a)->timer;
  int v987_b = (v986_p->b)->timer;
  int v997_a = v987_a + 1;
  int v997_b = v987_b + 1;
  (v986_p->a)->timer = v997_a;
  (v986_p->b)->timer = v997_b;
  int * v989_a = (v986_p->a)->regs;
  int * v989_b = (v986_p->b)->regs;
  int v990_a = v989_a[5];
  int v990_b = v989_b[5];
  int * v991_a = (v986_p->a)->regs;
  int * v991_b = (v986_p->b)->regs;
  int v992_a = v991_a[7];
  int v992_b = v991_b[7];
  int * v993_a = (v986_p->a)->regs;
  int * v993_b = (v986_p->b)->regs;
  int v1003_a = v990_a ^ v992_a;
  int v1003_b = v990_b ^ v992_b;
  v993_a[5] = v1003_a;
  v993_b[5] = v1003_b;
  struct StateT2 * v995_p = slot_28(v986_p);
  return v995_p;
}

struct StateT2 * slot_15(struct StateT2 * v517_p) {
  lockstep_assert(((v517_p->a)->timer) == ((v517_p->b)->timer));
  lockstep_assume(((v517_p->a)->timer) == ((v517_p->b)->timer));
  int v518_a = (v517_p->a)->timer;
  int v518_b = (v517_p->b)->timer;
  int v526_a = v518_a + 1;
  int v526_b = v518_b + 1;
  (v517_p->a)->timer = v526_a;
  (v517_p->b)->timer = v526_b;
  int * v520_a = (v517_p->a)->regs;
  int * v520_b = (v517_p->b)->regs;
  int v521_a = v520_a[6];
  int v521_b = v520_b[6];
  int * v522_a = (v517_p->a)->regs;
  int * v522_b = (v517_p->b)->regs;
  int v530_a = v521_a << 2;
  int v530_b = v521_b << 2;
  v522_a[6] = v530_a;
  v522_b[6] = v530_b;
  struct StateT2 * v524_p = slot_16(v517_p);
  return v524_p;
}

struct StateT2 * slot_62(struct StateT2 * v2204_p) {
  lockstep_assert(((v2204_p->a)->timer) == ((v2204_p->b)->timer));
  lockstep_assume(((v2204_p->a)->timer) == ((v2204_p->b)->timer));
  int v2205_a = (v2204_p->a)->timer;
  int v2205_b = (v2204_p->b)->timer;
  int v2214_a = v2205_a + 1;
  int v2214_b = v2205_b + 1;
  (v2204_p->a)->timer = v2214_a;
  (v2204_p->b)->timer = v2214_b;
  int * v2207_a = (v2204_p->a)->regs;
  int * v2207_b = (v2204_p->b)->regs;
  int v2208_a = v2207_a[5];
  int v2208_b = v2207_b[5];
  int * v2209_a = (v2204_p->a)->regs;
  int * v2209_b = (v2204_p->b)->regs;
  int v2210_a = v2209_a[7];
  int v2210_b = v2209_b[7];
  int * v2211_a = (v2204_p->a)->regs;
  int * v2211_b = (v2204_p->b)->regs;
  int v2220_a = v2208_a ^ v2210_a;
  int v2220_b = v2208_b ^ v2210_b;
  v2211_a[5] = v2220_a;
  v2211_b[5] = v2220_b;
  return v2204_p;
}

struct StateT2 * slot_48(struct StateT2 * v1702_p) {
  lockstep_assert(((v1702_p->a)->timer) == ((v1702_p->b)->timer));
  lockstep_assume(((v1702_p->a)->timer) == ((v1702_p->b)->timer));
  int v1703_a = (v1702_p->a)->timer;
  int v1703_b = (v1702_p->b)->timer;
  int v1711_a = v1703_a + 1;
  int v1711_b = v1703_b + 1;
  (v1702_p->a)->timer = v1711_a;
  (v1702_p->b)->timer = v1711_b;
  int * v1705_a = (v1702_p->a)->regs;
  int * v1705_b = (v1702_p->b)->regs;
  int v1706_a = v1705_a[11];
  int v1706_b = v1705_b[11];
  int * v1707_a = (v1702_p->a)->regs;
  int * v1707_b = (v1702_p->b)->regs;
  int v1716_a = (int)((unsigned int)v1706_a >> 15);
  int v1716_b = (int)((unsigned int)v1706_b >> 15);
  v1707_a[6] = v1716_a;
  v1707_b[6] = v1716_b;
  struct StateT2 * v1709_p = slot_49(v1702_p);
  return v1709_p;
}

struct StateT2 * slot_22(struct StateT2 * v812_p) {
  lockstep_assert(((v812_p->a)->timer) == ((v812_p->b)->timer));
  lockstep_assume(((v812_p->a)->timer) == ((v812_p->b)->timer));
  int v813_a = (v812_p->a)->timer;
  int v813_b = (v812_p->b)->timer;
  int v823_a = v813_a + 1;
  int v823_b = v813_b + 1;
  (v812_p->a)->timer = v823_a;
  (v812_p->b)->timer = v823_b;
  int * v815_a = (v812_p->a)->regs;
  int * v815_b = (v812_p->b)->regs;
  int v816_a = v815_a[5];
  int v816_b = v815_b[5];
  int * v817_a = (v812_p->a)->regs;
  int * v817_b = (v812_p->b)->regs;
  int v818_a = v817_a[7];
  int v818_b = v817_b[7];
  int * v819_a = (v812_p->a)->regs;
  int * v819_b = (v812_p->b)->regs;
  int v829_a = v816_a ^ v818_a;
  int v829_b = v816_b ^ v818_b;
  v819_a[5] = v829_a;
  v819_b[5] = v829_b;
  struct StateT2 * v821_p = slot_23(v812_p);
  return v821_p;
}

struct StateT2 * slot_35(struct StateT2 * v1213_p) {
  lockstep_assert(((v1213_p->a)->timer) == ((v1213_p->b)->timer));
  lockstep_assume(((v1213_p->a)->timer) == ((v1213_p->b)->timer));
  int v1214_a = (v1213_p->a)->timer;
  int v1214_b = (v1213_p->b)->timer;
  int v1222_a = v1214_a + 1;
  int v1222_b = v1214_b + 1;
  (v1213_p->a)->timer = v1222_a;
  (v1213_p->b)->timer = v1222_b;
  int * v1216_a = (v1213_p->a)->regs;
  int * v1216_b = (v1213_p->b)->regs;
  int v1217_a = v1216_a[6];
  int v1217_b = v1216_b[6];
  int * v1218_a = (v1213_p->a)->regs;
  int * v1218_b = (v1213_p->b)->regs;
  int v1226_a = v1217_a << 2;
  int v1226_b = v1217_b << 2;
  v1218_a[6] = v1226_a;
  v1218_b[6] = v1226_b;
  struct StateT2 * v1220_p = slot_36(v1213_p);
  return v1220_p;
}

struct StateT2 * slot_56(struct StateT2 * v1925_p) {
  lockstep_assert(((v1925_p->a)->timer) == ((v1925_p->b)->timer));
  lockstep_assume(((v1925_p->a)->timer) == ((v1925_p->b)->timer));
  int v1926_a = (v1925_p->a)->timer;
  int v1926_b = (v1925_p->b)->timer;
  int v1984_a = v1926_a + 1;
  int v1984_b = v1926_b + 1;
  (v1925_p->a)->timer = v1984_a;
  (v1925_p->b)->timer = v1984_b;
  int * v1928_a = (v1925_p->a)->regs;
  int * v1928_b = (v1925_p->b)->regs;
  int v1929_a = v1928_a[6];
  int v1929_b = v1928_b[6];
  int * v1930_a = (v1925_p->a)->cache_keys;
  int * v1930_b = (v1925_p->b)->cache_keys;
  int v1931_a = v1930_a[0];
  int v1931_b = v1930_b[0];
  bool v1989_a = v1931_a == ((int)((unsigned int)v1929_a >> 2));
  bool v1989_b = v1931_b == ((int)((unsigned int)v1929_b >> 2));
  int v1979_a;
  if (v1989_a) {
    int * v1932_a = (v1925_p->a)->cache_vals;
    int v1933_a = v1932_a[0];
    v1979_a = v1933_a;
  } else {
    int * v1935_a = (v1925_p->a)->cache_keys;
    int v1936_a = v1935_a[1];
    bool v1994_a = v1936_a == ((int)((unsigned int)v1929_a >> 2));
    int v1977_a;
    if (v1994_a) {
      int * v1937_a = (v1925_p->a)->cache_vals;
      int v1938_a = v1937_a[1];
      int * v1939_a = (v1925_p->a)->cache_keys;
      int * v1940_a = (v1925_p->a)->cache_keys;
      int v1941_a = v1940_a[0];
      v1939_a[1] = v1941_a;
      int * v1943_a = (v1925_p->a)->cache_vals;
      int * v1944_a = (v1925_p->a)->cache_vals;
      int v1945_a = v1944_a[0];
      v1943_a[1] = v1945_a;
      int * v1947_a = (v1925_p->a)->cache_keys;
      int v2003_a = (int)((unsigned int)v1929_a >> 2);
      v1947_a[0] = v2003_a;
      int * v1949_a = (v1925_p->a)->cache_vals;
      v1949_a[0] = v1938_a;
      int v1951_a = (v1925_p->a)->timer;
      int v2006_a = v1951_a + 1;
      (v1925_p->a)->timer = v2006_a;
      v1977_a = v1938_a;
    } else {
      int * v1954_a = (v1925_p->a)->mem;
      int v2008_a = (int)((unsigned int)v1929_a >> 2);
      int v1955_a = v1954_a[v2008_a];
      int * v1956_a = (v1925_p->a)->mem;
      int * v1957_a = (v1925_p->a)->cache_keys;
      int v1958_a = v1957_a[1];
      int * v1959_a = (v1925_p->a)->cache_vals;
      int v1960_a = v1959_a[1];
      v1956_a[v1958_a] = v1960_a;
      int * v1962_a = (v1925_p->a)->cache_keys;
      int * v1963_a = (v1925_p->a)->cache_keys;
      int v1964_a = v1963_a[0];
      v1962_a[1] = v1964_a;
      int * v1966_a = (v1925_p->a)->cache_vals;
      int * v1967_a = (v1925_p->a)->cache_vals;
      int v1968_a = v1967_a[0];
      v1966_a[1] = v1968_a;
      int * v1970_a = (v1925_p->a)->cache_keys;
      v1970_a[0] = v2008_a;
      int * v1972_a = (v1925_p->a)->cache_vals;
      v1972_a[0] = v1955_a;
      int v1974_a = (v1925_p->a)->timer;
      int v2023_a = v1974_a + 100;
      (v1925_p->a)->timer = v2023_a;
      v1977_a = v1955_a;
    }
    v1979_a = v1977_a;
  }
  int v1979_b;
  if (v1989_b) {
    int * v1932_b = (v1925_p->b)->cache_vals;
    int v1933_b = v1932_b[0];
    v1979_b = v1933_b;
  } else {
    int * v1935_b = (v1925_p->b)->cache_keys;
    int v1936_b = v1935_b[1];
    bool v1994_b = v1936_b == ((int)((unsigned int)v1929_b >> 2));
    int v1977_b;
    if (v1994_b) {
      int * v1937_b = (v1925_p->b)->cache_vals;
      int v1938_b = v1937_b[1];
      int * v1939_b = (v1925_p->b)->cache_keys;
      int * v1940_b = (v1925_p->b)->cache_keys;
      int v1941_b = v1940_b[0];
      v1939_b[1] = v1941_b;
      int * v1943_b = (v1925_p->b)->cache_vals;
      int * v1944_b = (v1925_p->b)->cache_vals;
      int v1945_b = v1944_b[0];
      v1943_b[1] = v1945_b;
      int * v1947_b = (v1925_p->b)->cache_keys;
      int v2003_b = (int)((unsigned int)v1929_b >> 2);
      v1947_b[0] = v2003_b;
      int * v1949_b = (v1925_p->b)->cache_vals;
      v1949_b[0] = v1938_b;
      int v1951_b = (v1925_p->b)->timer;
      int v2006_b = v1951_b + 1;
      (v1925_p->b)->timer = v2006_b;
      v1977_b = v1938_b;
    } else {
      int * v1954_b = (v1925_p->b)->mem;
      int v2008_b = (int)((unsigned int)v1929_b >> 2);
      int v1955_b = v1954_b[v2008_b];
      int * v1956_b = (v1925_p->b)->mem;
      int * v1957_b = (v1925_p->b)->cache_keys;
      int v1958_b = v1957_b[1];
      int * v1959_b = (v1925_p->b)->cache_vals;
      int v1960_b = v1959_b[1];
      v1956_b[v1958_b] = v1960_b;
      int * v1962_b = (v1925_p->b)->cache_keys;
      int * v1963_b = (v1925_p->b)->cache_keys;
      int v1964_b = v1963_b[0];
      v1962_b[1] = v1964_b;
      int * v1966_b = (v1925_p->b)->cache_vals;
      int * v1967_b = (v1925_p->b)->cache_vals;
      int v1968_b = v1967_b[0];
      v1966_b[1] = v1968_b;
      int * v1970_b = (v1925_p->b)->cache_keys;
      v1970_b[0] = v2008_b;
      int * v1972_b = (v1925_p->b)->cache_vals;
      v1972_b[0] = v1955_b;
      int v1974_b = (v1925_p->b)->timer;
      int v2023_b = v1974_b + 100;
      (v1925_p->b)->timer = v2023_b;
      v1977_b = v1955_b;
    }
    v1979_b = v1977_b;
  }
  int * v1980_a = (v1925_p->a)->regs;
  int * v1980_b = (v1925_p->b)->regs;
  v1980_a[7] = v1979_a;
  v1980_b[7] = v1979_b;
  struct StateT2 * v1982_p = slot_57(v1925_p);
  return v1982_p;
}

struct StateT2 * slot_34(struct StateT2 * v1197_p) {
  lockstep_assert(((v1197_p->a)->timer) == ((v1197_p->b)->timer));
  lockstep_assume(((v1197_p->a)->timer) == ((v1197_p->b)->timer));
  int v1198_a = (v1197_p->a)->timer;
  int v1198_b = (v1197_p->b)->timer;
  int v1206_a = v1198_a + 1;
  int v1206_b = v1198_b + 1;
  (v1197_p->a)->timer = v1206_a;
  (v1197_p->b)->timer = v1206_b;
  int * v1200_a = (v1197_p->a)->regs;
  int * v1200_b = (v1197_p->b)->regs;
  int v1201_a = v1200_a[6];
  int v1201_b = v1200_b[6];
  int * v1202_a = (v1197_p->a)->regs;
  int * v1202_b = (v1197_p->b)->regs;
  int v1210_a = v1201_a & 31;
  int v1210_b = v1201_b & 31;
  v1202_a[6] = v1210_a;
  v1202_b[6] = v1210_b;
  struct StateT2 * v1204_p = slot_35(v1197_p);
  return v1204_p;
}

struct StateT2 * slot_51(struct StateT2 * v1751_p) {
  lockstep_assert(((v1751_p->a)->timer) == ((v1751_p->b)->timer));
  lockstep_assume(((v1751_p->a)->timer) == ((v1751_p->b)->timer));
  int v1752_a = (v1751_p->a)->timer;
  int v1752_b = (v1751_p->b)->timer;
  int v1810_a = v1752_a + 1;
  int v1810_b = v1752_b + 1;
  (v1751_p->a)->timer = v1810_a;
  (v1751_p->b)->timer = v1810_b;
  int * v1754_a = (v1751_p->a)->regs;
  int * v1754_b = (v1751_p->b)->regs;
  int v1755_a = v1754_a[6];
  int v1755_b = v1754_b[6];
  int * v1756_a = (v1751_p->a)->cache_keys;
  int * v1756_b = (v1751_p->b)->cache_keys;
  int v1757_a = v1756_a[0];
  int v1757_b = v1756_b[0];
  bool v1815_a = v1757_a == ((int)((unsigned int)v1755_a >> 2));
  bool v1815_b = v1757_b == ((int)((unsigned int)v1755_b >> 2));
  int v1805_a;
  if (v1815_a) {
    int * v1758_a = (v1751_p->a)->cache_vals;
    int v1759_a = v1758_a[0];
    v1805_a = v1759_a;
  } else {
    int * v1761_a = (v1751_p->a)->cache_keys;
    int v1762_a = v1761_a[1];
    bool v1820_a = v1762_a == ((int)((unsigned int)v1755_a >> 2));
    int v1803_a;
    if (v1820_a) {
      int * v1763_a = (v1751_p->a)->cache_vals;
      int v1764_a = v1763_a[1];
      int * v1765_a = (v1751_p->a)->cache_keys;
      int * v1766_a = (v1751_p->a)->cache_keys;
      int v1767_a = v1766_a[0];
      v1765_a[1] = v1767_a;
      int * v1769_a = (v1751_p->a)->cache_vals;
      int * v1770_a = (v1751_p->a)->cache_vals;
      int v1771_a = v1770_a[0];
      v1769_a[1] = v1771_a;
      int * v1773_a = (v1751_p->a)->cache_keys;
      int v1829_a = (int)((unsigned int)v1755_a >> 2);
      v1773_a[0] = v1829_a;
      int * v1775_a = (v1751_p->a)->cache_vals;
      v1775_a[0] = v1764_a;
      int v1777_a = (v1751_p->a)->timer;
      int v1832_a = v1777_a + 1;
      (v1751_p->a)->timer = v1832_a;
      v1803_a = v1764_a;
    } else {
      int * v1780_a = (v1751_p->a)->mem;
      int v1834_a = (int)((unsigned int)v1755_a >> 2);
      int v1781_a = v1780_a[v1834_a];
      int * v1782_a = (v1751_p->a)->mem;
      int * v1783_a = (v1751_p->a)->cache_keys;
      int v1784_a = v1783_a[1];
      int * v1785_a = (v1751_p->a)->cache_vals;
      int v1786_a = v1785_a[1];
      v1782_a[v1784_a] = v1786_a;
      int * v1788_a = (v1751_p->a)->cache_keys;
      int * v1789_a = (v1751_p->a)->cache_keys;
      int v1790_a = v1789_a[0];
      v1788_a[1] = v1790_a;
      int * v1792_a = (v1751_p->a)->cache_vals;
      int * v1793_a = (v1751_p->a)->cache_vals;
      int v1794_a = v1793_a[0];
      v1792_a[1] = v1794_a;
      int * v1796_a = (v1751_p->a)->cache_keys;
      v1796_a[0] = v1834_a;
      int * v1798_a = (v1751_p->a)->cache_vals;
      v1798_a[0] = v1781_a;
      int v1800_a = (v1751_p->a)->timer;
      int v1849_a = v1800_a + 100;
      (v1751_p->a)->timer = v1849_a;
      v1803_a = v1781_a;
    }
    v1805_a = v1803_a;
  }
  int v1805_b;
  if (v1815_b) {
    int * v1758_b = (v1751_p->b)->cache_vals;
    int v1759_b = v1758_b[0];
    v1805_b = v1759_b;
  } else {
    int * v1761_b = (v1751_p->b)->cache_keys;
    int v1762_b = v1761_b[1];
    bool v1820_b = v1762_b == ((int)((unsigned int)v1755_b >> 2));
    int v1803_b;
    if (v1820_b) {
      int * v1763_b = (v1751_p->b)->cache_vals;
      int v1764_b = v1763_b[1];
      int * v1765_b = (v1751_p->b)->cache_keys;
      int * v1766_b = (v1751_p->b)->cache_keys;
      int v1767_b = v1766_b[0];
      v1765_b[1] = v1767_b;
      int * v1769_b = (v1751_p->b)->cache_vals;
      int * v1770_b = (v1751_p->b)->cache_vals;
      int v1771_b = v1770_b[0];
      v1769_b[1] = v1771_b;
      int * v1773_b = (v1751_p->b)->cache_keys;
      int v1829_b = (int)((unsigned int)v1755_b >> 2);
      v1773_b[0] = v1829_b;
      int * v1775_b = (v1751_p->b)->cache_vals;
      v1775_b[0] = v1764_b;
      int v1777_b = (v1751_p->b)->timer;
      int v1832_b = v1777_b + 1;
      (v1751_p->b)->timer = v1832_b;
      v1803_b = v1764_b;
    } else {
      int * v1780_b = (v1751_p->b)->mem;
      int v1834_b = (int)((unsigned int)v1755_b >> 2);
      int v1781_b = v1780_b[v1834_b];
      int * v1782_b = (v1751_p->b)->mem;
      int * v1783_b = (v1751_p->b)->cache_keys;
      int v1784_b = v1783_b[1];
      int * v1785_b = (v1751_p->b)->cache_vals;
      int v1786_b = v1785_b[1];
      v1782_b[v1784_b] = v1786_b;
      int * v1788_b = (v1751_p->b)->cache_keys;
      int * v1789_b = (v1751_p->b)->cache_keys;
      int v1790_b = v1789_b[0];
      v1788_b[1] = v1790_b;
      int * v1792_b = (v1751_p->b)->cache_vals;
      int * v1793_b = (v1751_p->b)->cache_vals;
      int v1794_b = v1793_b[0];
      v1792_b[1] = v1794_b;
      int * v1796_b = (v1751_p->b)->cache_keys;
      v1796_b[0] = v1834_b;
      int * v1798_b = (v1751_p->b)->cache_vals;
      v1798_b[0] = v1781_b;
      int v1800_b = (v1751_p->b)->timer;
      int v1849_b = v1800_b + 100;
      (v1751_p->b)->timer = v1849_b;
      v1803_b = v1781_b;
    }
    v1805_b = v1803_b;
  }
  int * v1806_a = (v1751_p->a)->regs;
  int * v1806_b = (v1751_p->b)->regs;
  v1806_a[7] = v1805_a;
  v1806_b[7] = v1805_b;
  struct StateT2 * v1808_p = slot_52(v1751_p);
  return v1808_p;
}

struct StateT2 * slot_52(struct StateT2 * v1856_p) {
  lockstep_assert(((v1856_p->a)->timer) == ((v1856_p->b)->timer));
  lockstep_assume(((v1856_p->a)->timer) == ((v1856_p->b)->timer));
  int v1857_a = (v1856_p->a)->timer;
  int v1857_b = (v1856_p->b)->timer;
  int v1867_a = v1857_a + 1;
  int v1867_b = v1857_b + 1;
  (v1856_p->a)->timer = v1867_a;
  (v1856_p->b)->timer = v1867_b;
  int * v1859_a = (v1856_p->a)->regs;
  int * v1859_b = (v1856_p->b)->regs;
  int v1860_a = v1859_a[5];
  int v1860_b = v1859_b[5];
  int * v1861_a = (v1856_p->a)->regs;
  int * v1861_b = (v1856_p->b)->regs;
  int v1862_a = v1861_a[7];
  int v1862_b = v1861_b[7];
  int * v1863_a = (v1856_p->a)->regs;
  int * v1863_b = (v1856_p->b)->regs;
  int v1873_a = v1860_a ^ v1862_a;
  int v1873_b = v1860_b ^ v1862_b;
  v1863_a[5] = v1873_a;
  v1863_b[5] = v1873_b;
  struct StateT2 * v1865_p = slot_53(v1856_p);
  return v1865_p;
}

struct StateT2 * slot_25(struct StateT2 * v865_p) {
  lockstep_assert(((v865_p->a)->timer) == ((v865_p->b)->timer));
  lockstep_assume(((v865_p->a)->timer) == ((v865_p->b)->timer));
  int v866_a = (v865_p->a)->timer;
  int v866_b = (v865_p->b)->timer;
  int v874_a = v866_a + 1;
  int v874_b = v866_b + 1;
  (v865_p->a)->timer = v874_a;
  (v865_p->b)->timer = v874_b;
  int * v868_a = (v865_p->a)->regs;
  int * v868_b = (v865_p->b)->regs;
  int v869_a = v868_a[6];
  int v869_b = v868_b[6];
  int * v870_a = (v865_p->a)->regs;
  int * v870_b = (v865_p->b)->regs;
  int v878_a = v869_a << 2;
  int v878_b = v869_b << 2;
  v870_a[6] = v878_a;
  v870_b[6] = v878_b;
  struct StateT2 * v872_p = slot_26(v865_p);
  return v872_p;
}

struct StateT2 * slot_23(struct StateT2 * v832_p) {
  lockstep_assert(((v832_p->a)->timer) == ((v832_p->b)->timer));
  lockstep_assume(((v832_p->a)->timer) == ((v832_p->b)->timer));
  int v833_a = (v832_p->a)->timer;
  int v833_b = (v832_p->b)->timer;
  int v841_a = v833_a + 1;
  int v841_b = v833_b + 1;
  (v832_p->a)->timer = v841_a;
  (v832_p->b)->timer = v841_b;
  int * v835_a = (v832_p->a)->regs;
  int * v835_b = (v832_p->b)->regs;
  int v836_a = v835_a[10];
  int v836_b = v835_b[10];
  int * v837_a = (v832_p->a)->regs;
  int * v837_b = (v832_p->b)->regs;
  int v846_a = (int)((unsigned int)v836_a >> 20);
  int v846_b = (int)((unsigned int)v836_b >> 20);
  v837_a[6] = v846_a;
  v837_b[6] = v846_b;
  struct StateT2 * v839_p = slot_24(v832_p);
  return v839_p;
}

struct StateT2 * slot_2(struct StateT2 * v116_p) {
  lockstep_assert(((v116_p->a)->timer) == ((v116_p->b)->timer));
  lockstep_assume(((v116_p->a)->timer) == ((v116_p->b)->timer));
  int v117_a = (v116_p->a)->timer;
  int v117_b = (v116_p->b)->timer;
  int v127_a = v117_a + 1;
  int v127_b = v117_b + 1;
  (v116_p->a)->timer = v127_a;
  (v116_p->b)->timer = v127_b;
  int * v119_a = (v116_p->a)->regs;
  int * v119_b = (v116_p->b)->regs;
  int v120_a = v119_a[5];
  int v120_b = v119_b[5];
  int * v121_a = (v116_p->a)->regs;
  int * v121_b = (v116_p->b)->regs;
  int v122_a = v121_a[9];
  int v122_b = v121_b[9];
  int * v123_a = (v116_p->a)->regs;
  int * v123_b = (v116_p->b)->regs;
  int v133_a = v120_a ^ v122_a;
  int v133_b = v120_b ^ v122_b;
  v123_a[5] = v133_a;
  v123_b[5] = v133_b;
  struct StateT2 * v125_p = slot_3(v116_p);
  return v125_p;
}

struct StateT2 * slot_21(struct StateT2 * v707_p) {
  lockstep_assert(((v707_p->a)->timer) == ((v707_p->b)->timer));
  lockstep_assume(((v707_p->a)->timer) == ((v707_p->b)->timer));
  int v708_a = (v707_p->a)->timer;
  int v708_b = (v707_p->b)->timer;
  int v766_a = v708_a + 1;
  int v766_b = v708_b + 1;
  (v707_p->a)->timer = v766_a;
  (v707_p->b)->timer = v766_b;
  int * v710_a = (v707_p->a)->regs;
  int * v710_b = (v707_p->b)->regs;
  int v711_a = v710_a[6];
  int v711_b = v710_b[6];
  int * v712_a = (v707_p->a)->cache_keys;
  int * v712_b = (v707_p->b)->cache_keys;
  int v713_a = v712_a[0];
  int v713_b = v712_b[0];
  bool v771_a = v713_a == ((int)((unsigned int)v711_a >> 2));
  bool v771_b = v713_b == ((int)((unsigned int)v711_b >> 2));
  int v761_a;
  if (v771_a) {
    int * v714_a = (v707_p->a)->cache_vals;
    int v715_a = v714_a[0];
    v761_a = v715_a;
  } else {
    int * v717_a = (v707_p->a)->cache_keys;
    int v718_a = v717_a[1];
    bool v776_a = v718_a == ((int)((unsigned int)v711_a >> 2));
    int v759_a;
    if (v776_a) {
      int * v719_a = (v707_p->a)->cache_vals;
      int v720_a = v719_a[1];
      int * v721_a = (v707_p->a)->cache_keys;
      int * v722_a = (v707_p->a)->cache_keys;
      int v723_a = v722_a[0];
      v721_a[1] = v723_a;
      int * v725_a = (v707_p->a)->cache_vals;
      int * v726_a = (v707_p->a)->cache_vals;
      int v727_a = v726_a[0];
      v725_a[1] = v727_a;
      int * v729_a = (v707_p->a)->cache_keys;
      int v785_a = (int)((unsigned int)v711_a >> 2);
      v729_a[0] = v785_a;
      int * v731_a = (v707_p->a)->cache_vals;
      v731_a[0] = v720_a;
      int v733_a = (v707_p->a)->timer;
      int v788_a = v733_a + 1;
      (v707_p->a)->timer = v788_a;
      v759_a = v720_a;
    } else {
      int * v736_a = (v707_p->a)->mem;
      int v790_a = (int)((unsigned int)v711_a >> 2);
      int v737_a = v736_a[v790_a];
      int * v738_a = (v707_p->a)->mem;
      int * v739_a = (v707_p->a)->cache_keys;
      int v740_a = v739_a[1];
      int * v741_a = (v707_p->a)->cache_vals;
      int v742_a = v741_a[1];
      v738_a[v740_a] = v742_a;
      int * v744_a = (v707_p->a)->cache_keys;
      int * v745_a = (v707_p->a)->cache_keys;
      int v746_a = v745_a[0];
      v744_a[1] = v746_a;
      int * v748_a = (v707_p->a)->cache_vals;
      int * v749_a = (v707_p->a)->cache_vals;
      int v750_a = v749_a[0];
      v748_a[1] = v750_a;
      int * v752_a = (v707_p->a)->cache_keys;
      v752_a[0] = v790_a;
      int * v754_a = (v707_p->a)->cache_vals;
      v754_a[0] = v737_a;
      int v756_a = (v707_p->a)->timer;
      int v805_a = v756_a + 100;
      (v707_p->a)->timer = v805_a;
      v759_a = v737_a;
    }
    v761_a = v759_a;
  }
  int v761_b;
  if (v771_b) {
    int * v714_b = (v707_p->b)->cache_vals;
    int v715_b = v714_b[0];
    v761_b = v715_b;
  } else {
    int * v717_b = (v707_p->b)->cache_keys;
    int v718_b = v717_b[1];
    bool v776_b = v718_b == ((int)((unsigned int)v711_b >> 2));
    int v759_b;
    if (v776_b) {
      int * v719_b = (v707_p->b)->cache_vals;
      int v720_b = v719_b[1];
      int * v721_b = (v707_p->b)->cache_keys;
      int * v722_b = (v707_p->b)->cache_keys;
      int v723_b = v722_b[0];
      v721_b[1] = v723_b;
      int * v725_b = (v707_p->b)->cache_vals;
      int * v726_b = (v707_p->b)->cache_vals;
      int v727_b = v726_b[0];
      v725_b[1] = v727_b;
      int * v729_b = (v707_p->b)->cache_keys;
      int v785_b = (int)((unsigned int)v711_b >> 2);
      v729_b[0] = v785_b;
      int * v731_b = (v707_p->b)->cache_vals;
      v731_b[0] = v720_b;
      int v733_b = (v707_p->b)->timer;
      int v788_b = v733_b + 1;
      (v707_p->b)->timer = v788_b;
      v759_b = v720_b;
    } else {
      int * v736_b = (v707_p->b)->mem;
      int v790_b = (int)((unsigned int)v711_b >> 2);
      int v737_b = v736_b[v790_b];
      int * v738_b = (v707_p->b)->mem;
      int * v739_b = (v707_p->b)->cache_keys;
      int v740_b = v739_b[1];
      int * v741_b = (v707_p->b)->cache_vals;
      int v742_b = v741_b[1];
      v738_b[v740_b] = v742_b;
      int * v744_b = (v707_p->b)->cache_keys;
      int * v745_b = (v707_p->b)->cache_keys;
      int v746_b = v745_b[0];
      v744_b[1] = v746_b;
      int * v748_b = (v707_p->b)->cache_vals;
      int * v749_b = (v707_p->b)->cache_vals;
      int v750_b = v749_b[0];
      v748_b[1] = v750_b;
      int * v752_b = (v707_p->b)->cache_keys;
      v752_b[0] = v790_b;
      int * v754_b = (v707_p->b)->cache_vals;
      v754_b[0] = v737_b;
      int v756_b = (v707_p->b)->timer;
      int v805_b = v756_b + 100;
      (v707_p->b)->timer = v805_b;
      v759_b = v737_b;
    }
    v761_b = v759_b;
  }
  int * v762_a = (v707_p->a)->regs;
  int * v762_b = (v707_p->b)->regs;
  v762_a[7] = v761_a;
  v762_b[7] = v761_b;
  struct StateT2 * v764_p = slot_22(v707_p);
  return v764_p;
}

struct StateT2 * slot_3(struct StateT2 * v136_p) {
  lockstep_assert(((v136_p->a)->timer) == ((v136_p->b)->timer));
  lockstep_assume(((v136_p->a)->timer) == ((v136_p->b)->timer));
  int v137_a = (v136_p->a)->timer;
  int v137_b = (v136_p->b)->timer;
  int v145_a = v137_a + 1;
  int v145_b = v137_b + 1;
  (v136_p->a)->timer = v145_a;
  (v136_p->b)->timer = v145_b;
  int * v139_a = (v136_p->a)->regs;
  int * v139_b = (v136_p->b)->regs;
  int v140_a = v139_a[10];
  int v140_b = v139_b[10];
  int * v141_a = (v136_p->a)->regs;
  int * v141_b = (v136_p->b)->regs;
  v141_a[6] = v140_a;
  v141_b[6] = v140_b;
  struct StateT2 * v143_p = slot_4(v136_p);
  return v143_p;
}

struct StateT2 * slot_45(struct StateT2 * v1561_p) {
  lockstep_assert(((v1561_p->a)->timer) == ((v1561_p->b)->timer));
  lockstep_assume(((v1561_p->a)->timer) == ((v1561_p->b)->timer));
  int v1562_a = (v1561_p->a)->timer;
  int v1562_b = (v1561_p->b)->timer;
  int v1570_a = v1562_a + 1;
  int v1570_b = v1562_b + 1;
  (v1561_p->a)->timer = v1570_a;
  (v1561_p->b)->timer = v1570_b;
  int * v1564_a = (v1561_p->a)->regs;
  int * v1564_b = (v1561_p->b)->regs;
  int v1565_a = v1564_a[6];
  int v1565_b = v1564_b[6];
  int * v1566_a = (v1561_p->a)->regs;
  int * v1566_b = (v1561_p->b)->regs;
  int v1574_a = v1565_a << 2;
  int v1574_b = v1565_b << 2;
  v1566_a[6] = v1574_a;
  v1566_b[6] = v1574_b;
  struct StateT2 * v1568_p = slot_46(v1561_p);
  return v1568_p;
}

struct StateT2 * slot_1(struct StateT2 * v15_p) {
  lockstep_assert(((v15_p->a)->timer) == ((v15_p->b)->timer));
  lockstep_assume(((v15_p->a)->timer) == ((v15_p->b)->timer));
  int v16_a = (v15_p->a)->timer;
  int v16_b = (v15_p->b)->timer;
  int v72_a = v16_a + 1;
  int v72_b = v16_b + 1;
  (v15_p->a)->timer = v72_a;
  (v15_p->b)->timer = v72_b;
  int * v18_a = (v15_p->a)->cache_keys;
  int * v18_b = (v15_p->b)->cache_keys;
  int v19_a = v18_a[0];
  int v19_b = v18_b[0];
  bool v75_a = v19_a == 20;
  bool v75_b = v19_b == 20;
  int v67_a;
  if (v75_a) {
    int * v20_a = (v15_p->a)->cache_vals;
    int v21_a = v20_a[0];
    v67_a = v21_a;
  } else {
    int * v23_a = (v15_p->a)->cache_keys;
    int v24_a = v23_a[1];
    bool v80_a = v24_a == 20;
    int v65_a;
    if (v80_a) {
      int * v25_a = (v15_p->a)->cache_vals;
      int v26_a = v25_a[1];
      int * v27_a = (v15_p->a)->cache_keys;
      int * v28_a = (v15_p->a)->cache_keys;
      int v29_a = v28_a[0];
      v27_a[1] = v29_a;
      int * v31_a = (v15_p->a)->cache_vals;
      int * v32_a = (v15_p->a)->cache_vals;
      int v33_a = v32_a[0];
      v31_a[1] = v33_a;
      int * v35_a = (v15_p->a)->cache_keys;
      v35_a[0] = 20;
      int * v37_a = (v15_p->a)->cache_vals;
      v37_a[0] = v26_a;
      int v39_a = (v15_p->a)->timer;
      int v92_a = v39_a + 1;
      (v15_p->a)->timer = v92_a;
      v65_a = v26_a;
    } else {
      int * v42_a = (v15_p->a)->mem;
      int v43_a = v42_a[20];
      int * v44_a = (v15_p->a)->mem;
      int * v45_a = (v15_p->a)->cache_keys;
      int v46_a = v45_a[1];
      int * v47_a = (v15_p->a)->cache_vals;
      int v48_a = v47_a[1];
      v44_a[v46_a] = v48_a;
      int * v50_a = (v15_p->a)->cache_keys;
      int * v51_a = (v15_p->a)->cache_keys;
      int v52_a = v51_a[0];
      v50_a[1] = v52_a;
      int * v54_a = (v15_p->a)->cache_vals;
      int * v55_a = (v15_p->a)->cache_vals;
      int v56_a = v55_a[0];
      v54_a[1] = v56_a;
      int * v58_a = (v15_p->a)->cache_keys;
      v58_a[0] = 20;
      int * v60_a = (v15_p->a)->cache_vals;
      v60_a[0] = v43_a;
      int v62_a = (v15_p->a)->timer;
      int v109_a = v62_a + 100;
      (v15_p->a)->timer = v109_a;
      v65_a = v43_a;
    }
    v67_a = v65_a;
  }
  int v67_b;
  if (v75_b) {
    int * v20_b = (v15_p->b)->cache_vals;
    int v21_b = v20_b[0];
    v67_b = v21_b;
  } else {
    int * v23_b = (v15_p->b)->cache_keys;
    int v24_b = v23_b[1];
    bool v80_b = v24_b == 20;
    int v65_b;
    if (v80_b) {
      int * v25_b = (v15_p->b)->cache_vals;
      int v26_b = v25_b[1];
      int * v27_b = (v15_p->b)->cache_keys;
      int * v28_b = (v15_p->b)->cache_keys;
      int v29_b = v28_b[0];
      v27_b[1] = v29_b;
      int * v31_b = (v15_p->b)->cache_vals;
      int * v32_b = (v15_p->b)->cache_vals;
      int v33_b = v32_b[0];
      v31_b[1] = v33_b;
      int * v35_b = (v15_p->b)->cache_keys;
      v35_b[0] = 20;
      int * v37_b = (v15_p->b)->cache_vals;
      v37_b[0] = v26_b;
      int v39_b = (v15_p->b)->timer;
      int v92_b = v39_b + 1;
      (v15_p->b)->timer = v92_b;
      v65_b = v26_b;
    } else {
      int * v42_b = (v15_p->b)->mem;
      int v43_b = v42_b[20];
      int * v44_b = (v15_p->b)->mem;
      int * v45_b = (v15_p->b)->cache_keys;
      int v46_b = v45_b[1];
      int * v47_b = (v15_p->b)->cache_vals;
      int v48_b = v47_b[1];
      v44_b[v46_b] = v48_b;
      int * v50_b = (v15_p->b)->cache_keys;
      int * v51_b = (v15_p->b)->cache_keys;
      int v52_b = v51_b[0];
      v50_b[1] = v52_b;
      int * v54_b = (v15_p->b)->cache_vals;
      int * v55_b = (v15_p->b)->cache_vals;
      int v56_b = v55_b[0];
      v54_b[1] = v56_b;
      int * v58_b = (v15_p->b)->cache_keys;
      v58_b[0] = 20;
      int * v60_b = (v15_p->b)->cache_vals;
      v60_b[0] = v43_b;
      int v62_b = (v15_p->b)->timer;
      int v109_b = v62_b + 100;
      (v15_p->b)->timer = v109_b;
      v65_b = v43_b;
    }
    v67_b = v65_b;
  }
  int * v68_a = (v15_p->a)->regs;
  int * v68_b = (v15_p->b)->regs;
  v68_a[9] = v67_a;
  v68_b[9] = v67_b;
  struct StateT2 * v70_p = slot_2(v15_p);
  return v70_p;
}

struct StateT2 * slot_13(struct StateT2 * v484_p) {
  lockstep_assert(((v484_p->a)->timer) == ((v484_p->b)->timer));
  lockstep_assume(((v484_p->a)->timer) == ((v484_p->b)->timer));
  int v485_a = (v484_p->a)->timer;
  int v485_b = (v484_p->b)->timer;
  int v493_a = v485_a + 1;
  int v493_b = v485_b + 1;
  (v484_p->a)->timer = v493_a;
  (v484_p->b)->timer = v493_b;
  int * v487_a = (v484_p->a)->regs;
  int * v487_b = (v484_p->b)->regs;
  int v488_a = v487_a[10];
  int v488_b = v487_b[10];
  int * v489_a = (v484_p->a)->regs;
  int * v489_b = (v484_p->b)->regs;
  int v498_a = (int)((unsigned int)v488_a >> 10);
  int v498_b = (int)((unsigned int)v488_b >> 10);
  v489_a[6] = v498_a;
  v489_b[6] = v498_b;
  struct StateT2 * v491_p = slot_14(v484_p);
  return v491_p;
}

struct StateT2 * slot_38(struct StateT2 * v1354_p) {
  lockstep_assert(((v1354_p->a)->timer) == ((v1354_p->b)->timer));
  lockstep_assume(((v1354_p->a)->timer) == ((v1354_p->b)->timer));
  int v1355_a = (v1354_p->a)->timer;
  int v1355_b = (v1354_p->b)->timer;
  int v1363_a = v1355_a + 1;
  int v1363_b = v1355_b + 1;
  (v1354_p->a)->timer = v1363_a;
  (v1354_p->b)->timer = v1363_b;
  int * v1357_a = (v1354_p->a)->regs;
  int * v1357_b = (v1354_p->b)->regs;
  int v1358_a = v1357_a[11];
  int v1358_b = v1357_b[11];
  int * v1359_a = (v1354_p->a)->regs;
  int * v1359_b = (v1354_p->b)->regs;
  int v1368_a = (int)((unsigned int)v1358_a >> 5);
  int v1368_b = (int)((unsigned int)v1358_b >> 5);
  v1359_a[6] = v1368_a;
  v1359_b[6] = v1368_b;
  struct StateT2 * v1361_p = slot_39(v1354_p);
  return v1361_p;
}

struct StateT2 * slot_24(struct StateT2 * v849_p) {
  lockstep_assert(((v849_p->a)->timer) == ((v849_p->b)->timer));
  lockstep_assume(((v849_p->a)->timer) == ((v849_p->b)->timer));
  int v850_a = (v849_p->a)->timer;
  int v850_b = (v849_p->b)->timer;
  int v858_a = v850_a + 1;
  int v858_b = v850_b + 1;
  (v849_p->a)->timer = v858_a;
  (v849_p->b)->timer = v858_b;
  int * v852_a = (v849_p->a)->regs;
  int * v852_b = (v849_p->b)->regs;
  int v853_a = v852_a[6];
  int v853_b = v852_b[6];
  int * v854_a = (v849_p->a)->regs;
  int * v854_b = (v849_p->b)->regs;
  int v862_a = v853_a & 31;
  int v862_b = v853_b & 31;
  v854_a[6] = v862_a;
  v854_b[6] = v862_b;
  struct StateT2 * v856_p = slot_25(v849_p);
  return v856_p;
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

struct StateT2 * slot_42(struct StateT2 * v1508_p) {
  lockstep_assert(((v1508_p->a)->timer) == ((v1508_p->b)->timer));
  lockstep_assume(((v1508_p->a)->timer) == ((v1508_p->b)->timer));
  int v1509_a = (v1508_p->a)->timer;
  int v1509_b = (v1508_p->b)->timer;
  int v1519_a = v1509_a + 1;
  int v1519_b = v1509_b + 1;
  (v1508_p->a)->timer = v1519_a;
  (v1508_p->b)->timer = v1519_b;
  int * v1511_a = (v1508_p->a)->regs;
  int * v1511_b = (v1508_p->b)->regs;
  int v1512_a = v1511_a[5];
  int v1512_b = v1511_b[5];
  int * v1513_a = (v1508_p->a)->regs;
  int * v1513_b = (v1508_p->b)->regs;
  int v1514_a = v1513_a[7];
  int v1514_b = v1513_b[7];
  int * v1515_a = (v1508_p->a)->regs;
  int * v1515_b = (v1508_p->b)->regs;
  int v1525_a = v1512_a ^ v1514_a;
  int v1525_b = v1512_b ^ v1514_b;
  v1515_a[5] = v1525_a;
  v1515_b[5] = v1525_b;
  struct StateT2 * v1517_p = slot_43(v1508_p);
  return v1517_p;
}

struct StateT2 * slot_46(struct StateT2 * v1577_p) {
  lockstep_assert(((v1577_p->a)->timer) == ((v1577_p->b)->timer));
  lockstep_assume(((v1577_p->a)->timer) == ((v1577_p->b)->timer));
  int v1578_a = (v1577_p->a)->timer;
  int v1578_b = (v1577_p->b)->timer;
  int v1636_a = v1578_a + 1;
  int v1636_b = v1578_b + 1;
  (v1577_p->a)->timer = v1636_a;
  (v1577_p->b)->timer = v1636_b;
  int * v1580_a = (v1577_p->a)->regs;
  int * v1580_b = (v1577_p->b)->regs;
  int v1581_a = v1580_a[6];
  int v1581_b = v1580_b[6];
  int * v1582_a = (v1577_p->a)->cache_keys;
  int * v1582_b = (v1577_p->b)->cache_keys;
  int v1583_a = v1582_a[0];
  int v1583_b = v1582_b[0];
  bool v1641_a = v1583_a == ((int)((unsigned int)v1581_a >> 2));
  bool v1641_b = v1583_b == ((int)((unsigned int)v1581_b >> 2));
  int v1631_a;
  if (v1641_a) {
    int * v1584_a = (v1577_p->a)->cache_vals;
    int v1585_a = v1584_a[0];
    v1631_a = v1585_a;
  } else {
    int * v1587_a = (v1577_p->a)->cache_keys;
    int v1588_a = v1587_a[1];
    bool v1646_a = v1588_a == ((int)((unsigned int)v1581_a >> 2));
    int v1629_a;
    if (v1646_a) {
      int * v1589_a = (v1577_p->a)->cache_vals;
      int v1590_a = v1589_a[1];
      int * v1591_a = (v1577_p->a)->cache_keys;
      int * v1592_a = (v1577_p->a)->cache_keys;
      int v1593_a = v1592_a[0];
      v1591_a[1] = v1593_a;
      int * v1595_a = (v1577_p->a)->cache_vals;
      int * v1596_a = (v1577_p->a)->cache_vals;
      int v1597_a = v1596_a[0];
      v1595_a[1] = v1597_a;
      int * v1599_a = (v1577_p->a)->cache_keys;
      int v1655_a = (int)((unsigned int)v1581_a >> 2);
      v1599_a[0] = v1655_a;
      int * v1601_a = (v1577_p->a)->cache_vals;
      v1601_a[0] = v1590_a;
      int v1603_a = (v1577_p->a)->timer;
      int v1658_a = v1603_a + 1;
      (v1577_p->a)->timer = v1658_a;
      v1629_a = v1590_a;
    } else {
      int * v1606_a = (v1577_p->a)->mem;
      int v1660_a = (int)((unsigned int)v1581_a >> 2);
      int v1607_a = v1606_a[v1660_a];
      int * v1608_a = (v1577_p->a)->mem;
      int * v1609_a = (v1577_p->a)->cache_keys;
      int v1610_a = v1609_a[1];
      int * v1611_a = (v1577_p->a)->cache_vals;
      int v1612_a = v1611_a[1];
      v1608_a[v1610_a] = v1612_a;
      int * v1614_a = (v1577_p->a)->cache_keys;
      int * v1615_a = (v1577_p->a)->cache_keys;
      int v1616_a = v1615_a[0];
      v1614_a[1] = v1616_a;
      int * v1618_a = (v1577_p->a)->cache_vals;
      int * v1619_a = (v1577_p->a)->cache_vals;
      int v1620_a = v1619_a[0];
      v1618_a[1] = v1620_a;
      int * v1622_a = (v1577_p->a)->cache_keys;
      v1622_a[0] = v1660_a;
      int * v1624_a = (v1577_p->a)->cache_vals;
      v1624_a[0] = v1607_a;
      int v1626_a = (v1577_p->a)->timer;
      int v1675_a = v1626_a + 100;
      (v1577_p->a)->timer = v1675_a;
      v1629_a = v1607_a;
    }
    v1631_a = v1629_a;
  }
  int v1631_b;
  if (v1641_b) {
    int * v1584_b = (v1577_p->b)->cache_vals;
    int v1585_b = v1584_b[0];
    v1631_b = v1585_b;
  } else {
    int * v1587_b = (v1577_p->b)->cache_keys;
    int v1588_b = v1587_b[1];
    bool v1646_b = v1588_b == ((int)((unsigned int)v1581_b >> 2));
    int v1629_b;
    if (v1646_b) {
      int * v1589_b = (v1577_p->b)->cache_vals;
      int v1590_b = v1589_b[1];
      int * v1591_b = (v1577_p->b)->cache_keys;
      int * v1592_b = (v1577_p->b)->cache_keys;
      int v1593_b = v1592_b[0];
      v1591_b[1] = v1593_b;
      int * v1595_b = (v1577_p->b)->cache_vals;
      int * v1596_b = (v1577_p->b)->cache_vals;
      int v1597_b = v1596_b[0];
      v1595_b[1] = v1597_b;
      int * v1599_b = (v1577_p->b)->cache_keys;
      int v1655_b = (int)((unsigned int)v1581_b >> 2);
      v1599_b[0] = v1655_b;
      int * v1601_b = (v1577_p->b)->cache_vals;
      v1601_b[0] = v1590_b;
      int v1603_b = (v1577_p->b)->timer;
      int v1658_b = v1603_b + 1;
      (v1577_p->b)->timer = v1658_b;
      v1629_b = v1590_b;
    } else {
      int * v1606_b = (v1577_p->b)->mem;
      int v1660_b = (int)((unsigned int)v1581_b >> 2);
      int v1607_b = v1606_b[v1660_b];
      int * v1608_b = (v1577_p->b)->mem;
      int * v1609_b = (v1577_p->b)->cache_keys;
      int v1610_b = v1609_b[1];
      int * v1611_b = (v1577_p->b)->cache_vals;
      int v1612_b = v1611_b[1];
      v1608_b[v1610_b] = v1612_b;
      int * v1614_b = (v1577_p->b)->cache_keys;
      int * v1615_b = (v1577_p->b)->cache_keys;
      int v1616_b = v1615_b[0];
      v1614_b[1] = v1616_b;
      int * v1618_b = (v1577_p->b)->cache_vals;
      int * v1619_b = (v1577_p->b)->cache_vals;
      int v1620_b = v1619_b[0];
      v1618_b[1] = v1620_b;
      int * v1622_b = (v1577_p->b)->cache_keys;
      v1622_b[0] = v1660_b;
      int * v1624_b = (v1577_p->b)->cache_vals;
      v1624_b[0] = v1607_b;
      int v1626_b = (v1577_p->b)->timer;
      int v1675_b = v1626_b + 100;
      (v1577_p->b)->timer = v1675_b;
      v1629_b = v1607_b;
    }
    v1631_b = v1629_b;
  }
  int * v1632_a = (v1577_p->a)->regs;
  int * v1632_b = (v1577_p->b)->regs;
  v1632_a[7] = v1631_a;
  v1632_b[7] = v1631_b;
  struct StateT2 * v1634_p = slot_47(v1577_p);
  return v1634_p;
}

struct StateT2 * slot_20(struct StateT2 * v691_p) {
  lockstep_assert(((v691_p->a)->timer) == ((v691_p->b)->timer));
  lockstep_assume(((v691_p->a)->timer) == ((v691_p->b)->timer));
  int v692_a = (v691_p->a)->timer;
  int v692_b = (v691_p->b)->timer;
  int v700_a = v692_a + 1;
  int v700_b = v692_b + 1;
  (v691_p->a)->timer = v700_a;
  (v691_p->b)->timer = v700_b;
  int * v694_a = (v691_p->a)->regs;
  int * v694_b = (v691_p->b)->regs;
  int v695_a = v694_a[6];
  int v695_b = v694_b[6];
  int * v696_a = (v691_p->a)->regs;
  int * v696_b = (v691_p->b)->regs;
  int v704_a = v695_a << 2;
  int v704_b = v695_b << 2;
  v696_a[6] = v704_a;
  v696_b[6] = v704_b;
  struct StateT2 * v698_p = slot_21(v691_p);
  return v698_p;
}

struct StateT2 * slot_61(struct StateT2 * v2099_p) {
  lockstep_assert(((v2099_p->a)->timer) == ((v2099_p->b)->timer));
  lockstep_assume(((v2099_p->a)->timer) == ((v2099_p->b)->timer));
  int v2100_a = (v2099_p->a)->timer;
  int v2100_b = (v2099_p->b)->timer;
  int v2158_a = v2100_a + 1;
  int v2158_b = v2100_b + 1;
  (v2099_p->a)->timer = v2158_a;
  (v2099_p->b)->timer = v2158_b;
  int * v2102_a = (v2099_p->a)->regs;
  int * v2102_b = (v2099_p->b)->regs;
  int v2103_a = v2102_a[6];
  int v2103_b = v2102_b[6];
  int * v2104_a = (v2099_p->a)->cache_keys;
  int * v2104_b = (v2099_p->b)->cache_keys;
  int v2105_a = v2104_a[0];
  int v2105_b = v2104_b[0];
  bool v2163_a = v2105_a == ((int)((unsigned int)v2103_a >> 2));
  bool v2163_b = v2105_b == ((int)((unsigned int)v2103_b >> 2));
  int v2153_a;
  if (v2163_a) {
    int * v2106_a = (v2099_p->a)->cache_vals;
    int v2107_a = v2106_a[0];
    v2153_a = v2107_a;
  } else {
    int * v2109_a = (v2099_p->a)->cache_keys;
    int v2110_a = v2109_a[1];
    bool v2168_a = v2110_a == ((int)((unsigned int)v2103_a >> 2));
    int v2151_a;
    if (v2168_a) {
      int * v2111_a = (v2099_p->a)->cache_vals;
      int v2112_a = v2111_a[1];
      int * v2113_a = (v2099_p->a)->cache_keys;
      int * v2114_a = (v2099_p->a)->cache_keys;
      int v2115_a = v2114_a[0];
      v2113_a[1] = v2115_a;
      int * v2117_a = (v2099_p->a)->cache_vals;
      int * v2118_a = (v2099_p->a)->cache_vals;
      int v2119_a = v2118_a[0];
      v2117_a[1] = v2119_a;
      int * v2121_a = (v2099_p->a)->cache_keys;
      int v2177_a = (int)((unsigned int)v2103_a >> 2);
      v2121_a[0] = v2177_a;
      int * v2123_a = (v2099_p->a)->cache_vals;
      v2123_a[0] = v2112_a;
      int v2125_a = (v2099_p->a)->timer;
      int v2180_a = v2125_a + 1;
      (v2099_p->a)->timer = v2180_a;
      v2151_a = v2112_a;
    } else {
      int * v2128_a = (v2099_p->a)->mem;
      int v2182_a = (int)((unsigned int)v2103_a >> 2);
      int v2129_a = v2128_a[v2182_a];
      int * v2130_a = (v2099_p->a)->mem;
      int * v2131_a = (v2099_p->a)->cache_keys;
      int v2132_a = v2131_a[1];
      int * v2133_a = (v2099_p->a)->cache_vals;
      int v2134_a = v2133_a[1];
      v2130_a[v2132_a] = v2134_a;
      int * v2136_a = (v2099_p->a)->cache_keys;
      int * v2137_a = (v2099_p->a)->cache_keys;
      int v2138_a = v2137_a[0];
      v2136_a[1] = v2138_a;
      int * v2140_a = (v2099_p->a)->cache_vals;
      int * v2141_a = (v2099_p->a)->cache_vals;
      int v2142_a = v2141_a[0];
      v2140_a[1] = v2142_a;
      int * v2144_a = (v2099_p->a)->cache_keys;
      v2144_a[0] = v2182_a;
      int * v2146_a = (v2099_p->a)->cache_vals;
      v2146_a[0] = v2129_a;
      int v2148_a = (v2099_p->a)->timer;
      int v2197_a = v2148_a + 100;
      (v2099_p->a)->timer = v2197_a;
      v2151_a = v2129_a;
    }
    v2153_a = v2151_a;
  }
  int v2153_b;
  if (v2163_b) {
    int * v2106_b = (v2099_p->b)->cache_vals;
    int v2107_b = v2106_b[0];
    v2153_b = v2107_b;
  } else {
    int * v2109_b = (v2099_p->b)->cache_keys;
    int v2110_b = v2109_b[1];
    bool v2168_b = v2110_b == ((int)((unsigned int)v2103_b >> 2));
    int v2151_b;
    if (v2168_b) {
      int * v2111_b = (v2099_p->b)->cache_vals;
      int v2112_b = v2111_b[1];
      int * v2113_b = (v2099_p->b)->cache_keys;
      int * v2114_b = (v2099_p->b)->cache_keys;
      int v2115_b = v2114_b[0];
      v2113_b[1] = v2115_b;
      int * v2117_b = (v2099_p->b)->cache_vals;
      int * v2118_b = (v2099_p->b)->cache_vals;
      int v2119_b = v2118_b[0];
      v2117_b[1] = v2119_b;
      int * v2121_b = (v2099_p->b)->cache_keys;
      int v2177_b = (int)((unsigned int)v2103_b >> 2);
      v2121_b[0] = v2177_b;
      int * v2123_b = (v2099_p->b)->cache_vals;
      v2123_b[0] = v2112_b;
      int v2125_b = (v2099_p->b)->timer;
      int v2180_b = v2125_b + 1;
      (v2099_p->b)->timer = v2180_b;
      v2151_b = v2112_b;
    } else {
      int * v2128_b = (v2099_p->b)->mem;
      int v2182_b = (int)((unsigned int)v2103_b >> 2);
      int v2129_b = v2128_b[v2182_b];
      int * v2130_b = (v2099_p->b)->mem;
      int * v2131_b = (v2099_p->b)->cache_keys;
      int v2132_b = v2131_b[1];
      int * v2133_b = (v2099_p->b)->cache_vals;
      int v2134_b = v2133_b[1];
      v2130_b[v2132_b] = v2134_b;
      int * v2136_b = (v2099_p->b)->cache_keys;
      int * v2137_b = (v2099_p->b)->cache_keys;
      int v2138_b = v2137_b[0];
      v2136_b[1] = v2138_b;
      int * v2140_b = (v2099_p->b)->cache_vals;
      int * v2141_b = (v2099_p->b)->cache_vals;
      int v2142_b = v2141_b[0];
      v2140_b[1] = v2142_b;
      int * v2144_b = (v2099_p->b)->cache_keys;
      v2144_b[0] = v2182_b;
      int * v2146_b = (v2099_p->b)->cache_vals;
      v2146_b[0] = v2129_b;
      int v2148_b = (v2099_p->b)->timer;
      int v2197_b = v2148_b + 100;
      (v2099_p->b)->timer = v2197_b;
      v2151_b = v2129_b;
    }
    v2153_b = v2151_b;
  }
  int * v2154_a = (v2099_p->a)->regs;
  int * v2154_b = (v2099_p->b)->regs;
  v2154_a[7] = v2153_a;
  v2154_b[7] = v2153_b;
  struct StateT2 * v2156_p = slot_62(v2099_p);
  return v2156_p;
}

struct StateT2 * snippet(struct StateT2 * v0_p) {
  lockstep_assert(((v0_p->a)->timer) == ((v0_p->b)->timer));
  lockstep_assume(((v0_p->a)->timer) == ((v0_p->b)->timer));
  struct StateT2 * v1_p = slot_0(v0_p);
  return v1_p;
}

struct StateT2 * slot_41(struct StateT2 * v1403_p) {
  lockstep_assert(((v1403_p->a)->timer) == ((v1403_p->b)->timer));
  lockstep_assume(((v1403_p->a)->timer) == ((v1403_p->b)->timer));
  int v1404_a = (v1403_p->a)->timer;
  int v1404_b = (v1403_p->b)->timer;
  int v1462_a = v1404_a + 1;
  int v1462_b = v1404_b + 1;
  (v1403_p->a)->timer = v1462_a;
  (v1403_p->b)->timer = v1462_b;
  int * v1406_a = (v1403_p->a)->regs;
  int * v1406_b = (v1403_p->b)->regs;
  int v1407_a = v1406_a[6];
  int v1407_b = v1406_b[6];
  int * v1408_a = (v1403_p->a)->cache_keys;
  int * v1408_b = (v1403_p->b)->cache_keys;
  int v1409_a = v1408_a[0];
  int v1409_b = v1408_b[0];
  bool v1467_a = v1409_a == ((int)((unsigned int)v1407_a >> 2));
  bool v1467_b = v1409_b == ((int)((unsigned int)v1407_b >> 2));
  int v1457_a;
  if (v1467_a) {
    int * v1410_a = (v1403_p->a)->cache_vals;
    int v1411_a = v1410_a[0];
    v1457_a = v1411_a;
  } else {
    int * v1413_a = (v1403_p->a)->cache_keys;
    int v1414_a = v1413_a[1];
    bool v1472_a = v1414_a == ((int)((unsigned int)v1407_a >> 2));
    int v1455_a;
    if (v1472_a) {
      int * v1415_a = (v1403_p->a)->cache_vals;
      int v1416_a = v1415_a[1];
      int * v1417_a = (v1403_p->a)->cache_keys;
      int * v1418_a = (v1403_p->a)->cache_keys;
      int v1419_a = v1418_a[0];
      v1417_a[1] = v1419_a;
      int * v1421_a = (v1403_p->a)->cache_vals;
      int * v1422_a = (v1403_p->a)->cache_vals;
      int v1423_a = v1422_a[0];
      v1421_a[1] = v1423_a;
      int * v1425_a = (v1403_p->a)->cache_keys;
      int v1481_a = (int)((unsigned int)v1407_a >> 2);
      v1425_a[0] = v1481_a;
      int * v1427_a = (v1403_p->a)->cache_vals;
      v1427_a[0] = v1416_a;
      int v1429_a = (v1403_p->a)->timer;
      int v1484_a = v1429_a + 1;
      (v1403_p->a)->timer = v1484_a;
      v1455_a = v1416_a;
    } else {
      int * v1432_a = (v1403_p->a)->mem;
      int v1486_a = (int)((unsigned int)v1407_a >> 2);
      int v1433_a = v1432_a[v1486_a];
      int * v1434_a = (v1403_p->a)->mem;
      int * v1435_a = (v1403_p->a)->cache_keys;
      int v1436_a = v1435_a[1];
      int * v1437_a = (v1403_p->a)->cache_vals;
      int v1438_a = v1437_a[1];
      v1434_a[v1436_a] = v1438_a;
      int * v1440_a = (v1403_p->a)->cache_keys;
      int * v1441_a = (v1403_p->a)->cache_keys;
      int v1442_a = v1441_a[0];
      v1440_a[1] = v1442_a;
      int * v1444_a = (v1403_p->a)->cache_vals;
      int * v1445_a = (v1403_p->a)->cache_vals;
      int v1446_a = v1445_a[0];
      v1444_a[1] = v1446_a;
      int * v1448_a = (v1403_p->a)->cache_keys;
      v1448_a[0] = v1486_a;
      int * v1450_a = (v1403_p->a)->cache_vals;
      v1450_a[0] = v1433_a;
      int v1452_a = (v1403_p->a)->timer;
      int v1501_a = v1452_a + 100;
      (v1403_p->a)->timer = v1501_a;
      v1455_a = v1433_a;
    }
    v1457_a = v1455_a;
  }
  int v1457_b;
  if (v1467_b) {
    int * v1410_b = (v1403_p->b)->cache_vals;
    int v1411_b = v1410_b[0];
    v1457_b = v1411_b;
  } else {
    int * v1413_b = (v1403_p->b)->cache_keys;
    int v1414_b = v1413_b[1];
    bool v1472_b = v1414_b == ((int)((unsigned int)v1407_b >> 2));
    int v1455_b;
    if (v1472_b) {
      int * v1415_b = (v1403_p->b)->cache_vals;
      int v1416_b = v1415_b[1];
      int * v1417_b = (v1403_p->b)->cache_keys;
      int * v1418_b = (v1403_p->b)->cache_keys;
      int v1419_b = v1418_b[0];
      v1417_b[1] = v1419_b;
      int * v1421_b = (v1403_p->b)->cache_vals;
      int * v1422_b = (v1403_p->b)->cache_vals;
      int v1423_b = v1422_b[0];
      v1421_b[1] = v1423_b;
      int * v1425_b = (v1403_p->b)->cache_keys;
      int v1481_b = (int)((unsigned int)v1407_b >> 2);
      v1425_b[0] = v1481_b;
      int * v1427_b = (v1403_p->b)->cache_vals;
      v1427_b[0] = v1416_b;
      int v1429_b = (v1403_p->b)->timer;
      int v1484_b = v1429_b + 1;
      (v1403_p->b)->timer = v1484_b;
      v1455_b = v1416_b;
    } else {
      int * v1432_b = (v1403_p->b)->mem;
      int v1486_b = (int)((unsigned int)v1407_b >> 2);
      int v1433_b = v1432_b[v1486_b];
      int * v1434_b = (v1403_p->b)->mem;
      int * v1435_b = (v1403_p->b)->cache_keys;
      int v1436_b = v1435_b[1];
      int * v1437_b = (v1403_p->b)->cache_vals;
      int v1438_b = v1437_b[1];
      v1434_b[v1436_b] = v1438_b;
      int * v1440_b = (v1403_p->b)->cache_keys;
      int * v1441_b = (v1403_p->b)->cache_keys;
      int v1442_b = v1441_b[0];
      v1440_b[1] = v1442_b;
      int * v1444_b = (v1403_p->b)->cache_vals;
      int * v1445_b = (v1403_p->b)->cache_vals;
      int v1446_b = v1445_b[0];
      v1444_b[1] = v1446_b;
      int * v1448_b = (v1403_p->b)->cache_keys;
      v1448_b[0] = v1486_b;
      int * v1450_b = (v1403_p->b)->cache_vals;
      v1450_b[0] = v1433_b;
      int v1452_b = (v1403_p->b)->timer;
      int v1501_b = v1452_b + 100;
      (v1403_p->b)->timer = v1501_b;
      v1455_b = v1433_b;
    }
    v1457_b = v1455_b;
  }
  int * v1458_a = (v1403_p->a)->regs;
  int * v1458_b = (v1403_p->b)->regs;
  v1458_a[7] = v1457_a;
  v1458_b[7] = v1457_b;
  struct StateT2 * v1460_p = slot_42(v1403_p);
  return v1460_p;
}

struct StateT2 * slot_39(struct StateT2 * v1371_p) {
  lockstep_assert(((v1371_p->a)->timer) == ((v1371_p->b)->timer));
  lockstep_assume(((v1371_p->a)->timer) == ((v1371_p->b)->timer));
  int v1372_a = (v1371_p->a)->timer;
  int v1372_b = (v1371_p->b)->timer;
  int v1380_a = v1372_a + 1;
  int v1380_b = v1372_b + 1;
  (v1371_p->a)->timer = v1380_a;
  (v1371_p->b)->timer = v1380_b;
  int * v1374_a = (v1371_p->a)->regs;
  int * v1374_b = (v1371_p->b)->regs;
  int v1375_a = v1374_a[6];
  int v1375_b = v1374_b[6];
  int * v1376_a = (v1371_p->a)->regs;
  int * v1376_b = (v1371_p->b)->regs;
  int v1384_a = v1375_a & 31;
  int v1384_b = v1375_b & 31;
  v1376_a[6] = v1384_a;
  v1376_b[6] = v1384_b;
  struct StateT2 * v1378_p = slot_40(v1371_p);
  return v1378_p;
}

struct StateT2 * slot_8(struct StateT2 * v310_p) {
  lockstep_assert(((v310_p->a)->timer) == ((v310_p->b)->timer));
  lockstep_assume(((v310_p->a)->timer) == ((v310_p->b)->timer));
  int v311_a = (v310_p->a)->timer;
  int v311_b = (v310_p->b)->timer;
  int v319_a = v311_a + 1;
  int v319_b = v311_b + 1;
  (v310_p->a)->timer = v319_a;
  (v310_p->b)->timer = v319_b;
  int * v313_a = (v310_p->a)->regs;
  int * v313_b = (v310_p->b)->regs;
  int v314_a = v313_a[10];
  int v314_b = v313_b[10];
  int * v315_a = (v310_p->a)->regs;
  int * v315_b = (v310_p->b)->regs;
  int v324_a = (int)((unsigned int)v314_a >> 5);
  int v324_b = (int)((unsigned int)v314_b >> 5);
  v315_a[6] = v324_a;
  v315_b[6] = v324_b;
  struct StateT2 * v317_p = slot_9(v310_p);
  return v317_p;
}

struct StateT2 * slot_30(struct StateT2 * v1039_p) {
  lockstep_assert(((v1039_p->a)->timer) == ((v1039_p->b)->timer));
  lockstep_assume(((v1039_p->a)->timer) == ((v1039_p->b)->timer));
  int v1040_a = (v1039_p->a)->timer;
  int v1040_b = (v1039_p->b)->timer;
  int v1048_a = v1040_a + 1;
  int v1048_b = v1040_b + 1;
  (v1039_p->a)->timer = v1048_a;
  (v1039_p->b)->timer = v1048_b;
  int * v1042_a = (v1039_p->a)->regs;
  int * v1042_b = (v1039_p->b)->regs;
  int v1043_a = v1042_a[6];
  int v1043_b = v1042_b[6];
  int * v1044_a = (v1039_p->a)->regs;
  int * v1044_b = (v1039_p->b)->regs;
  int v1052_a = v1043_a << 2;
  int v1052_b = v1043_b << 2;
  v1044_a[6] = v1052_a;
  v1044_b[6] = v1052_b;
  struct StateT2 * v1046_p = slot_31(v1039_p);
  return v1046_p;
}

struct StateT2 * slot_60(struct StateT2 * v2083_p) {
  lockstep_assert(((v2083_p->a)->timer) == ((v2083_p->b)->timer));
  lockstep_assume(((v2083_p->a)->timer) == ((v2083_p->b)->timer));
  int v2084_a = (v2083_p->a)->timer;
  int v2084_b = (v2083_p->b)->timer;
  int v2092_a = v2084_a + 1;
  int v2092_b = v2084_b + 1;
  (v2083_p->a)->timer = v2092_a;
  (v2083_p->b)->timer = v2092_b;
  int * v2086_a = (v2083_p->a)->regs;
  int * v2086_b = (v2083_p->b)->regs;
  int v2087_a = v2086_a[6];
  int v2087_b = v2086_b[6];
  int * v2088_a = (v2083_p->a)->regs;
  int * v2088_b = (v2083_p->b)->regs;
  int v2096_a = v2087_a << 2;
  int v2096_b = v2087_b << 2;
  v2088_a[6] = v2096_a;
  v2088_b[6] = v2096_b;
  struct StateT2 * v2090_p = slot_61(v2083_p);
  return v2090_p;
}

struct StateT2 * slot_4(struct StateT2 * v153_p) {
  lockstep_assert(((v153_p->a)->timer) == ((v153_p->b)->timer));
  lockstep_assume(((v153_p->a)->timer) == ((v153_p->b)->timer));
  int v154_a = (v153_p->a)->timer;
  int v154_b = (v153_p->b)->timer;
  int v162_a = v154_a + 1;
  int v162_b = v154_b + 1;
  (v153_p->a)->timer = v162_a;
  (v153_p->b)->timer = v162_b;
  int * v156_a = (v153_p->a)->regs;
  int * v156_b = (v153_p->b)->regs;
  int v157_a = v156_a[6];
  int v157_b = v156_b[6];
  int * v158_a = (v153_p->a)->regs;
  int * v158_b = (v153_p->b)->regs;
  int v166_a = v157_a & 31;
  int v166_b = v157_b & 31;
  v158_a[6] = v166_a;
  v158_b[6] = v166_b;
  struct StateT2 * v160_p = slot_5(v153_p);
  return v160_p;
}

struct StateT2 * slot_18(struct StateT2 * v658_p) {
  lockstep_assert(((v658_p->a)->timer) == ((v658_p->b)->timer));
  lockstep_assume(((v658_p->a)->timer) == ((v658_p->b)->timer));
  int v659_a = (v658_p->a)->timer;
  int v659_b = (v658_p->b)->timer;
  int v667_a = v659_a + 1;
  int v667_b = v659_b + 1;
  (v658_p->a)->timer = v667_a;
  (v658_p->b)->timer = v667_b;
  int * v661_a = (v658_p->a)->regs;
  int * v661_b = (v658_p->b)->regs;
  int v662_a = v661_a[10];
  int v662_b = v661_b[10];
  int * v663_a = (v658_p->a)->regs;
  int * v663_b = (v658_p->b)->regs;
  int v672_a = (int)((unsigned int)v662_a >> 15);
  int v672_b = (int)((unsigned int)v662_b >> 15);
  v663_a[6] = v672_a;
  v663_b[6] = v672_b;
  struct StateT2 * v665_p = slot_19(v658_p);
  return v665_p;
}

struct StateT2 * slot_9(struct StateT2 * v327_p) {
  lockstep_assert(((v327_p->a)->timer) == ((v327_p->b)->timer));
  lockstep_assume(((v327_p->a)->timer) == ((v327_p->b)->timer));
  int v328_a = (v327_p->a)->timer;
  int v328_b = (v327_p->b)->timer;
  int v336_a = v328_a + 1;
  int v336_b = v328_b + 1;
  (v327_p->a)->timer = v336_a;
  (v327_p->b)->timer = v336_b;
  int * v330_a = (v327_p->a)->regs;
  int * v330_b = (v327_p->b)->regs;
  int v331_a = v330_a[6];
  int v331_b = v330_b[6];
  int * v332_a = (v327_p->a)->regs;
  int * v332_b = (v327_p->b)->regs;
  int v340_a = v331_a & 31;
  int v340_b = v331_b & 31;
  v332_a[6] = v340_a;
  v332_b[6] = v340_b;
  struct StateT2 * v334_p = slot_10(v327_p);
  return v334_p;
}

struct StateT2 * slot_11(struct StateT2 * v359_p) {
  lockstep_assert(((v359_p->a)->timer) == ((v359_p->b)->timer));
  lockstep_assume(((v359_p->a)->timer) == ((v359_p->b)->timer));
  int v360_a = (v359_p->a)->timer;
  int v360_b = (v359_p->b)->timer;
  int v418_a = v360_a + 1;
  int v418_b = v360_b + 1;
  (v359_p->a)->timer = v418_a;
  (v359_p->b)->timer = v418_b;
  int * v362_a = (v359_p->a)->regs;
  int * v362_b = (v359_p->b)->regs;
  int v363_a = v362_a[6];
  int v363_b = v362_b[6];
  int * v364_a = (v359_p->a)->cache_keys;
  int * v364_b = (v359_p->b)->cache_keys;
  int v365_a = v364_a[0];
  int v365_b = v364_b[0];
  bool v423_a = v365_a == ((int)((unsigned int)v363_a >> 2));
  bool v423_b = v365_b == ((int)((unsigned int)v363_b >> 2));
  int v413_a;
  if (v423_a) {
    int * v366_a = (v359_p->a)->cache_vals;
    int v367_a = v366_a[0];
    v413_a = v367_a;
  } else {
    int * v369_a = (v359_p->a)->cache_keys;
    int v370_a = v369_a[1];
    bool v428_a = v370_a == ((int)((unsigned int)v363_a >> 2));
    int v411_a;
    if (v428_a) {
      int * v371_a = (v359_p->a)->cache_vals;
      int v372_a = v371_a[1];
      int * v373_a = (v359_p->a)->cache_keys;
      int * v374_a = (v359_p->a)->cache_keys;
      int v375_a = v374_a[0];
      v373_a[1] = v375_a;
      int * v377_a = (v359_p->a)->cache_vals;
      int * v378_a = (v359_p->a)->cache_vals;
      int v379_a = v378_a[0];
      v377_a[1] = v379_a;
      int * v381_a = (v359_p->a)->cache_keys;
      int v437_a = (int)((unsigned int)v363_a >> 2);
      v381_a[0] = v437_a;
      int * v383_a = (v359_p->a)->cache_vals;
      v383_a[0] = v372_a;
      int v385_a = (v359_p->a)->timer;
      int v440_a = v385_a + 1;
      (v359_p->a)->timer = v440_a;
      v411_a = v372_a;
    } else {
      int * v388_a = (v359_p->a)->mem;
      int v442_a = (int)((unsigned int)v363_a >> 2);
      int v389_a = v388_a[v442_a];
      int * v390_a = (v359_p->a)->mem;
      int * v391_a = (v359_p->a)->cache_keys;
      int v392_a = v391_a[1];
      int * v393_a = (v359_p->a)->cache_vals;
      int v394_a = v393_a[1];
      v390_a[v392_a] = v394_a;
      int * v396_a = (v359_p->a)->cache_keys;
      int * v397_a = (v359_p->a)->cache_keys;
      int v398_a = v397_a[0];
      v396_a[1] = v398_a;
      int * v400_a = (v359_p->a)->cache_vals;
      int * v401_a = (v359_p->a)->cache_vals;
      int v402_a = v401_a[0];
      v400_a[1] = v402_a;
      int * v404_a = (v359_p->a)->cache_keys;
      v404_a[0] = v442_a;
      int * v406_a = (v359_p->a)->cache_vals;
      v406_a[0] = v389_a;
      int v408_a = (v359_p->a)->timer;
      int v457_a = v408_a + 100;
      (v359_p->a)->timer = v457_a;
      v411_a = v389_a;
    }
    v413_a = v411_a;
  }
  int v413_b;
  if (v423_b) {
    int * v366_b = (v359_p->b)->cache_vals;
    int v367_b = v366_b[0];
    v413_b = v367_b;
  } else {
    int * v369_b = (v359_p->b)->cache_keys;
    int v370_b = v369_b[1];
    bool v428_b = v370_b == ((int)((unsigned int)v363_b >> 2));
    int v411_b;
    if (v428_b) {
      int * v371_b = (v359_p->b)->cache_vals;
      int v372_b = v371_b[1];
      int * v373_b = (v359_p->b)->cache_keys;
      int * v374_b = (v359_p->b)->cache_keys;
      int v375_b = v374_b[0];
      v373_b[1] = v375_b;
      int * v377_b = (v359_p->b)->cache_vals;
      int * v378_b = (v359_p->b)->cache_vals;
      int v379_b = v378_b[0];
      v377_b[1] = v379_b;
      int * v381_b = (v359_p->b)->cache_keys;
      int v437_b = (int)((unsigned int)v363_b >> 2);
      v381_b[0] = v437_b;
      int * v383_b = (v359_p->b)->cache_vals;
      v383_b[0] = v372_b;
      int v385_b = (v359_p->b)->timer;
      int v440_b = v385_b + 1;
      (v359_p->b)->timer = v440_b;
      v411_b = v372_b;
    } else {
      int * v388_b = (v359_p->b)->mem;
      int v442_b = (int)((unsigned int)v363_b >> 2);
      int v389_b = v388_b[v442_b];
      int * v390_b = (v359_p->b)->mem;
      int * v391_b = (v359_p->b)->cache_keys;
      int v392_b = v391_b[1];
      int * v393_b = (v359_p->b)->cache_vals;
      int v394_b = v393_b[1];
      v390_b[v392_b] = v394_b;
      int * v396_b = (v359_p->b)->cache_keys;
      int * v397_b = (v359_p->b)->cache_keys;
      int v398_b = v397_b[0];
      v396_b[1] = v398_b;
      int * v400_b = (v359_p->b)->cache_vals;
      int * v401_b = (v359_p->b)->cache_vals;
      int v402_b = v401_b[0];
      v400_b[1] = v402_b;
      int * v404_b = (v359_p->b)->cache_keys;
      v404_b[0] = v442_b;
      int * v406_b = (v359_p->b)->cache_vals;
      v406_b[0] = v389_b;
      int v408_b = (v359_p->b)->timer;
      int v457_b = v408_b + 100;
      (v359_p->b)->timer = v457_b;
      v411_b = v389_b;
    }
    v413_b = v411_b;
  }
  int * v414_a = (v359_p->a)->regs;
  int * v414_b = (v359_p->b)->regs;
  v414_a[7] = v413_a;
  v414_b[7] = v413_b;
  struct StateT2 * v416_p = slot_12(v359_p);
  return v416_p;
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
  for (int i=0; i<CACHE_LRU_SIZE; i++) {
    s->cache_keys[i] = -1;
    s->cache_vals[i] = -1;
  }
}

void lockstep_assert(bool c) { __CPROVER_assert(c, "lockstep drift"); }
void lockstep_assume(bool c) { __CPROVER_assume(c); }

int main(int argc, char* argv[]) {
  struct StateT s1, s2;
  init(&s1);
  init(&s2);
  
  // the indices, public: one draw into both states
  int i10 = bounded(0, 1073741823);
  s1.regs[10] = i10;
  s2.regs[10] = i10;
  int i11 = bounded(0, 1073741823);
  s1.regs[11] = i11;
  s2.regs[11] = i11;
  
  // initialize secret
  for (int i=0; i<SECRET_SIZE; i++) {
    s1.mem[SECRET_OFFSET+i] = bounded(0, 20);
    s2.mem[SECRET_OFFSET+i] = bounded(0, 20);
  }
  struct StateT2 p = { .a = &s1, .b = &s2 };
  struct StateT2 *p_ = snippet(&p);
  __CPROVER_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}