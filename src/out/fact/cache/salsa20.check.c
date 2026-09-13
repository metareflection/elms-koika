// verify: clean (CBMC should report VERIFICATION SUCCESSFUL)

#define NUM_REGS 32
#define MEM_SIZE 64
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

struct StateT {
  int regs[32];
  int mem[64];
  int saved_regs[32];
  int cache_keys[10];
  int cache_vals[10];
  int timer;
};

struct StateT * v2389(struct StateT * v2390);
struct StateT * v7777(struct StateT * v7778);
struct StateT * v7695(struct StateT * v7696);
struct StateT * v6601(struct StateT * v6602);
struct StateT * v6525(struct StateT * v6526);
struct StateT * v7567(struct StateT * v7568);
struct StateT * v6463(struct StateT * v6464);
struct StateT * v2521(struct StateT * v2522);
struct StateT * v2745(struct StateT * v2746);
struct StateT * v2453(struct StateT * v2454);
struct StateT * v7869(struct StateT * v7870);
struct StateT * v7051(struct StateT * v7052);
struct StateT * v6631(struct StateT * v6632);
struct StateT * v2111(struct StateT * v2112);
struct StateT * v6841(struct StateT * v6842);
struct StateT * v2027(struct StateT * v2028);
struct StateT * v7665(struct StateT * v7666);
struct StateT * v63(struct StateT * v64);
struct StateT * v441(struct StateT * v442);
struct StateT * v7481(struct StateT * v7482);
struct StateT * v3393(struct StateT * v3394);
struct StateT * v4131(struct StateT * v4132);
struct StateT * v3447(struct StateT * v3448);
struct StateT * v7585(struct StateT * v7586);
struct StateT * v6755(struct StateT * v6756);
struct StateT * v1469(struct StateT * v1470);
struct StateT * v6745(struct StateT * v6746);
struct StateT * v7225(struct StateT * v7226);
struct StateT * v7033(struct StateT * v7034);
struct StateT * v7199(struct StateT * v7200);
struct StateT * v7675(struct StateT * v7676);
struct StateT * v7347(struct StateT * v7348);
struct StateT * v6795(struct StateT * v6796);
struct StateT * v891(struct StateT * v892);
struct StateT * v6735(struct StateT * v6736);
struct StateT * v3667(struct StateT * v3668);
struct StateT * v2599(struct StateT * v2600);
struct StateT * v4189(struct StateT * v4190);
struct StateT * v2667(struct StateT * v2668);
struct StateT * v7803(struct StateT * v7804);
struct StateT * v1065(struct StateT * v1066);
struct StateT * v7769(struct StateT * v7770);
struct StateT * v657(struct StateT * v658);
struct StateT * v7511(struct StateT * v7512);
struct StateT * v3957(struct StateT * v3958);
struct StateT * v1907(struct StateT * v1908);
struct StateT * v1413(struct StateT * v1414);
struct StateT * v2001(struct StateT * v2002);
struct StateT * v1993(struct StateT * v1994);
struct StateT * v7655(struct StateT * v7656);
struct StateT * v7725(struct StateT * v7726);
struct StateT * v2175(struct StateT * v2176);
struct StateT * v7085(struct StateT * v7086);
struct StateT * v1475(struct StateT * v1476);
struct StateT * v7217(struct StateT * v7218);
struct StateT * v6455(struct StateT * v6456);
struct StateT * v7383(struct StateT * v7384);
struct StateT * v7849(struct StateT * v7850);
struct StateT * v7619(struct StateT * v7620);
struct StateT * v6785(struct StateT * v6786);
struct StateT * v2681(struct StateT * v2682);
struct StateT * v7093(struct StateT * v7094);
struct StateT * v1425(struct StateT * v1426);
struct StateT * v1637(struct StateT * v1638);
struct StateT * v7593(struct StateT * v7594);
struct StateT * v7427(struct StateT * v7428);
struct StateT * v7209(struct StateT * v7210);
struct StateT * v6875(struct StateT * v6876);
struct StateT * v7307(struct StateT * v7308);
struct StateT * v7887(struct StateT * v7888);
struct StateT * v7337(struct StateT * v7338);
struct StateT * v7685(struct StateT * v7686);
struct StateT * v2589(struct StateT * v2590);
struct StateT * v6499(struct StateT * v6500);
struct StateT * v7715(struct StateT * v7716);
struct StateT * v7795(struct StateT * v7796);
struct StateT * v6561(struct StateT * v6562);
struct StateT * v1239(struct StateT * v1240);
struct StateT * v7163(struct StateT * v7164);
struct StateT * v7705(struct StateT * v7706);
struct StateT * v3783(struct StateT * v3784);
struct StateT * v7367(struct StateT * v7368);
struct StateT * v333(struct StateT * v334);
struct StateT * v7829(struct StateT * v7830);
struct StateT * v7879(struct StateT * v7880);
struct StateT * v7007(struct StateT * v7008);
struct StateT * v7243(struct StateT * v7244);
struct StateT * v2907(struct StateT * v2908);
struct StateT * v3899(struct StateT * v3900);
struct StateT * v949(struct StateT * v950);
struct StateT * v1447(struct StateT * v1448);
struct StateT * v2463(struct StateT * v2464);
struct StateT * v7435(struct StateT * v7436);
struct StateT * v3841(struct StateT * v3842);
struct StateT * v2735(struct StateT * v2736);
struct StateT * v7491(struct StateT * v7492);
struct StateT * v6657(struct StateT * v6658);
struct StateT * v2705(struct StateT * v2706);
struct StateT * v1123(struct StateT * v1124);
struct StateT * v7461(struct StateT * v7462);
struct StateT * v1419(struct StateT * v1420);
struct StateT * v7297(struct StateT * v7298);
struct StateT * v225(struct StateT * v226);
struct StateT * v7611(struct StateT * v7612);
struct StateT * v1691(struct StateT * v1692);
struct StateT * v6507(struct StateT * v6508);
struct StateT * v717(struct StateT * v718);
struct StateT * v6919(struct StateT * v6920);
struct StateT * v6717(struct StateT * v6718);
struct StateT * v775(struct StateT * v776);
struct StateT * v7103(struct StateT * v7104);
struct StateT * v2395(struct StateT * v2396);
struct StateT * v4015(struct StateT * v4016);
struct StateT * v2961(struct StateT * v2962);
struct StateT * v6621(struct StateT * v6622);
struct StateT * v2697(struct StateT * v2698);
struct StateT * v7251(struct StateT * v7252);
struct StateT * v6639(struct StateT * v6640);
struct StateT * v7077(struct StateT * v7078);
struct StateT * v6765(struct StateT * v6766);
struct StateT * v7577(struct StateT * v7578);
struct StateT * v2033(struct StateT * v2034);
struct StateT * v7629(struct StateT * v7630);
struct StateT * v2185(struct StateT * v2186);
struct StateT * v6591(struct StateT * v6592);
struct StateT * v7143(struct StateT * v7144);
struct StateT * v6673(struct StateT * v6674);
struct StateT * v2007(struct StateT * v2008);
struct StateT * v7471(struct StateT * v7472);
struct StateT * v7859(struct StateT * v7860);
struct StateT * v2689(struct StateT * v2690);
struct StateT * v3555(struct StateT * v3556);
struct StateT * v1939(struct StateT * v1940);
struct StateT * v7501(struct StateT * v7502);
struct StateT * v6647(struct StateT * v6648);
struct StateT * v6857(struct StateT * v6858);
struct StateT * v6823(struct StateT * v6824);
struct StateT * v7751(struct StateT * v7752);
struct StateT * v6417(struct StateT * v6418);
struct StateT * v6489(struct StateT * v6490);
struct StateT * v7123(struct StateT * v7124);
struct StateT * v7559(struct StateT * v7560);
struct StateT * v6699(struct StateT * v6700);
struct StateT * v3177(struct StateT * v3178);
struct StateT * v6883(struct StateT * v6884);
struct StateT * v7375(struct StateT * v7376);
struct StateT * v4371(struct StateT * v4372);
struct StateT * v7261(struct StateT * v7262);
struct StateT * v6831(struct StateT * v6832);
struct StateT * v6775(struct StateT * v6776);
struct StateT * v2043(struct StateT * v2044);
struct StateT * v6581(struct StateT * v6582);
struct StateT * v2379(struct StateT * v2380);
struct StateT * v1297(struct StateT * v1298);
struct StateT * v7041(struct StateT * v7042);
struct StateT * v6949(struct StateT * v6950);
struct StateT * v6909(struct StateT * v6910);
struct StateT * v7761(struct StateT * v7762);
struct StateT * v833(struct StateT * v834);
struct StateT * v7067(struct StateT * v7068);
struct StateT * v1745(struct StateT * v1746);
struct StateT * v549(struct StateT * v550);
struct StateT * v7317(struct StateT * v7318);
struct StateT * v6427(struct StateT * v6428);
struct StateT * v387(struct StateT * v388);
struct StateT * v1461(struct StateT * v1462);
struct StateT * v171(struct StateT * v172);
struct StateT * v6551(struct StateT * v6552);
struct StateT * v7183(struct StateT * v7184);
struct StateT * v2017(struct StateT * v2018);
struct StateT * v2725(struct StateT * v2726);
struct StateT * v3501(struct StateT * v3502);
struct StateT * v1915(struct StateT * v1916);
struct StateT * v6989(struct StateT * v6990);
struct StateT * v6725(struct StateT * v6726);
struct StateT * v3339(struct StateT * v3340);
struct StateT * v1439(struct StateT * v1440);
struct StateT * v3015(struct StateT * v3016);
struct StateT * v6611(struct StateT * v6612);
struct StateT * v7191(struct StateT * v7192);
struct StateT * v7541(struct StateT * v7542);
struct StateT * v7153(struct StateT * v7154);
struct StateT * v3725(struct StateT * v3726);
struct StateT * v7637(struct StateT * v7638);
struct StateT * v2657(struct StateT * v2658);
struct StateT * v2253(struct StateT * v2254);
struct StateT * v7327(struct StateT * v7328);
struct StateT * v4073(struct StateT * v4074);
struct StateT * v7787(struct StateT * v7788);
struct StateT * v6533(struct StateT * v6534);
struct StateT * v7603(struct StateT * v7604);
struct StateT * v7453(struct StateT * v7454);
struct StateT * v6979(struct StateT * v6980);
struct StateT * v603(struct StateT * v604);
struct StateT * v4247(struct StateT * v4248);
struct StateT * v495(struct StateT * v496);
struct StateT * v3285(struct StateT * v3286);
struct StateT * v1431(struct StateT * v1432);
struct StateT * v6665(struct StateT * v6666);
struct StateT * v7015(struct StateT * v7016);
struct StateT * v6473(struct StateT * v6474);
struct StateT * v6683(struct StateT * v6684);
struct StateT * v3123(struct StateT * v3124);
struct StateT * v2853(struct StateT * v2854);
struct StateT * v7173(struct StateT * v7174);
struct StateT * v6929(struct StateT * v6930);
struct StateT * v6709(struct StateT * v6710);
struct StateT * v1799(struct StateT * v1800);
struct StateT * v117(struct StateT * v118);
struct StateT * v6407(struct StateT * v6408);
struct StateT * v7287(struct StateT * v7288);
struct StateT * v9(struct StateT * v10);
struct StateT * v1007(struct StateT * v1008);
struct StateT * v7059(struct StateT * v7060);
struct StateT * v2531(struct StateT * v2532);
struct StateT * v7821(struct StateT * v7822);
struct StateT * v1529(struct StateT * v1530);
struct StateT * v6867(struct StateT * v6868);
struct StateT * v1181(struct StateT * v1182);
struct StateT * v6939(struct StateT * v6940);
struct StateT * v6571(struct StateT * v6572);
struct StateT * v6901(struct StateT * v6902);
struct StateT * v6447(struct StateT * v6448);
struct StateT * v6999(struct StateT * v7000);
struct StateT * v2799(struct StateT * v2800);
struct StateT * v7645(struct StateT * v7646);
struct StateT * v2243(struct StateT * v2244);
struct StateT * v7401(struct StateT * v7402);
struct StateT * v6515(struct StateT * v6516);
struct StateT * v7743(struct StateT * v7744);
struct StateT * v1455(struct StateT * v1456);
struct StateT * v6691(struct StateT * v6692);
struct StateT * v1853(struct StateT * v1854);
struct StateT * v279(struct StateT * v280);
struct StateT * v4305(struct StateT * v4306);
struct StateT * v6959(struct StateT * v6960);
struct StateT * v6541(struct StateT * v6542);
struct StateT * v7409(struct StateT * v7410);
struct StateT * v6805(struct StateT * v6806);
struct StateT * v6481(struct StateT * v6482);
struct StateT * v7113(struct StateT * v7114);
struct StateT * v6969(struct StateT * v6970);
struct StateT * v711(struct StateT * v712);
struct StateT * v2117(struct StateT * v2118);
struct StateT * v7735(struct StateT * v7736);
struct StateT * v6815(struct StateT * v6816);
struct StateT * v2715(struct StateT * v2716);
struct StateT * v7269(struct StateT * v7270);
struct StateT * v6437(struct StateT * v6438);
struct StateT * v4363(struct StateT * v4364);
struct StateT * v7813(struct StateT * v7814);
struct StateT * v7521(struct StateT * v7522);
struct StateT * v3069(struct StateT * v3070);
struct StateT * v2321(struct StateT * v2322);
struct StateT * v2101(struct StateT * v2102);
struct StateT * v1923(struct StateT * v1924);
struct StateT * v7357(struct StateT * v7358);
struct StateT * v7393(struct StateT * v7394);
struct StateT * v1583(struct StateT * v1584);
struct StateT * v7235(struct StateT * v7236);
struct StateT * v7025(struct StateT * v7026);
struct StateT * v7419(struct StateT * v7420);
struct StateT * v1931(struct StateT * v1932);
struct StateT * v7445(struct StateT * v7446);
struct StateT * v6893(struct StateT * v6894);
struct StateT * v7839(struct StateT * v7840);
struct StateT * v7133(struct StateT * v7134);
struct StateT * v1355(struct StateT * v1356);
struct StateT * snippet(struct StateT * v0);
struct StateT * v7551(struct StateT * v7552);
struct StateT * v7531(struct StateT * v7532);
struct StateT * v6849(struct StateT * v6850);
struct StateT * v1(struct StateT * v2);
struct StateT * v3609(struct StateT * v3610);
struct StateT * v2673(struct StateT * v2674);
struct StateT * v3231(struct StateT * v3232);
struct StateT * v7277(struct StateT * v7278);
struct StateT * v2311(struct StateT * v2312);
struct StateT * v2389(struct StateT * v2390) {
  int v2391 = v2390->timer;
  int v6055 = v2391 + 1;
  v2390->timer = v6055;
  int * v2393 = v2390->regs;
  v2393[7] = 2036477952;
  struct StateT * v6053 = v2395(v2390);
  return v6053;
}

struct StateT * v7777(struct StateT * v7778) {
  int v7779 = v7778->timer;
  int v8029 = v7779 + 1;
  v7778->timer = v8029;
  int * v7781 = v7778->regs;
  int v7782 = v7781[15];
  int * v7783 = v7778->regs;
  int v7784 = v7783[9];
  int * v7785 = v7778->regs;
  int v8035 = v7782 | v7784;
  v7785[15] = v8035;
  struct StateT * v8027 = v7787(v7778);
  return v8027;
}

struct StateT * v7695(struct StateT * v7696) {
  int v7697 = v7696->timer;
  int v8125 = v7697 + 1;
  v7696->timer = v8125;
  int * v7699 = v7696->regs;
  int v7700 = v7699[14];
  int * v7701 = v7696->regs;
  int v7702 = v7701[27];
  int * v7703 = v7696->regs;
  int v8132 = v7700 + v7702;
  v7703[11] = v8132;
  struct StateT * v8123 = v7705(v7696);
  return v8123;
}

struct StateT * v6601(struct StateT * v6602) {
  int v6603 = v6602->timer;
  int v9394 = v6603 + 1;
  v6602->timer = v9394;
  int * v6605 = v6602->regs;
  int v6606 = v6605[13];
  int * v6607 = v6602->regs;
  int v6608 = v6607[11];
  int * v6609 = v6602->regs;
  int v9401 = v6606 + v6608;
  v6609[8] = v9401;
  struct StateT * v9392 = v6611(v6602);
  return v9392;
}

struct StateT * v6525(struct StateT * v6526) {
  int v6527 = v6526->timer;
  int v9482 = v6527 + 1;
  v6526->timer = v9482;
  int * v6529 = v6526->regs;
  int v6530 = v6529[8];
  int * v6531 = v6526->regs;
  int v9487 = (int)((unsigned int)v6530 >> 25);
  v6531[20] = v9487;
  struct StateT * v9480 = v6533(v6526);
  return v9480;
}

struct StateT * v7567(struct StateT * v7568) {
  int v7569 = v7568->timer;
  int v8271 = v7569 + 1;
  v7568->timer = v8271;
  int * v7571 = v7568->regs;
  int v7572 = v7571[11];
  int * v7573 = v7568->regs;
  int v7574 = v7573[9];
  int * v7575 = v7568->regs;
  int v8277 = v7572 | v7574;
  v7575[11] = v8277;
  struct StateT * v8269 = v7577(v7568);
  return v8269;
}

struct StateT * v6463(struct StateT * v6464) {
  int v6465 = v6464->timer;
  int v9552 = v6465 + 1;
  v6464->timer = v9552;
  int * v6467 = v6464->regs;
  int v6468 = v6467[15];
  int * v6469 = v6464->regs;
  int v6470 = v6469[9];
  int * v6471 = v6464->regs;
  int v9558 = v6468 | v6470;
  v6471[15] = v9558;
  struct StateT * v9550 = v6473(v6464);
  return v9550;
}

struct StateT * v2521(struct StateT * v2522) {
  int v2523 = v2522->timer;
  int v5937 = v2523 + 1;
  v2522->timer = v5937;
  int * v2525 = v2522->regs;
  int v2526 = v2525[16];
  int * v2527 = v2522->regs;
  int v2528 = v2527[30];
  int * v2529 = v2522->regs;
  int v5943 = v2526 + v2528;
  v2529[16] = v5943;
  struct StateT * v5935 = v2531(v2522);
  return v5935;
}

struct StateT * v2745(struct StateT * v2746) {
  int v2747 = v2746->timer;
  int v5686 = v2747 + 1;
  v2746->timer = v5686;
  int * v2749 = v2746->regs;
  int v2750 = v2749[10];
  int * v2751 = v2746->regs;
  int v2752 = v2751[15];
  int * v2753 = v2746->cache_keys;
  int v2754 = v2753[0];
  bool v5693 = v2754 == ((int)((unsigned int)v2750 >> 2));
  int v2798;
  if (v5693) {
    int * v2755 = v2746->cache_vals;
    v2755[0] = v2752;
    v2798 = v2752;
  } else {
    int * v2758 = v2746->cache_keys;
    int v2759 = v2758[1];
    bool v5698 = v2759 == ((int)((unsigned int)v2750 >> 2));
    int v2796;
    if (v5698) {
      int * v2760 = v2746->cache_keys;
      int * v2761 = v2746->cache_keys;
      int v2762 = v2761[0];
      v2760[1] = v2762;
      int * v2764 = v2746->cache_vals;
      int * v2765 = v2746->cache_vals;
      int v2766 = v2765[0];
      v2764[1] = v2766;
      int * v2768 = v2746->cache_keys;
      int v5706 = (int)((unsigned int)v2750 >> 2);
      v2768[0] = v5706;
      int * v2770 = v2746->cache_vals;
      v2770[0] = v2752;
      int v2772 = v2746->timer;
      int v5709 = v2772 + 1;
      v2746->timer = v5709;
      v2796 = v2752;
    } else {
      int * v2775 = v2746->mem;
      int * v2776 = v2746->cache_keys;
      int v2777 = v2776[1];
      int * v2778 = v2746->cache_vals;
      int v2779 = v2778[1];
      v2775[v2777] = v2779;
      int * v2781 = v2746->cache_keys;
      int * v2782 = v2746->cache_keys;
      int v2783 = v2782[0];
      v2781[1] = v2783;
      int * v2785 = v2746->cache_vals;
      int * v2786 = v2746->cache_vals;
      int v2787 = v2786[0];
      v2785[1] = v2787;
      int * v2789 = v2746->cache_keys;
      int v5722 = (int)((unsigned int)v2750 >> 2);
      v2789[0] = v5722;
      int * v2791 = v2746->cache_vals;
      v2791[0] = v2752;
      int v2793 = v2746->timer;
      int v5725 = v2793 + 100;
      v2746->timer = v5725;
      v2796 = v2752;
    }
    v2798 = v2796;
  }
  struct StateT * v5684 = v2799(v2746);
  return v5684;
}

struct StateT * v2453(struct StateT * v2454) {
  int v2455 = v2454->timer;
  int v5996 = v2455 + 1;
  v2454->timer = v5996;
  int * v2457 = v2454->regs;
  int v2458 = v2457[17];
  int * v2459 = v2454->regs;
  int v2460 = v2459[30];
  int * v2461 = v2454->regs;
  int v6002 = v2458 + v2460;
  v2461[17] = v6002;
  struct StateT * v5994 = v2463(v2454);
  return v5994;
}

struct StateT * v7869(struct StateT * v7870) {
  int v7871 = v7870->timer;
  int v7924 = v7871 + 1;
  v7870->timer = v7924;
  int * v7873 = v7870->regs;
  int v7874 = v7873[22];
  int * v7875 = v7870->regs;
  int v7876 = v7875[8];
  int * v7877 = v7870->regs;
  int v7930 = v7874 ^ v7876;
  v7877[22] = v7930;
  struct StateT * v7922 = v7879(v7870);
  return v7922;
}

struct StateT * v7051(struct StateT * v7052) {
  int v7053 = v7052->timer;
  int v8872 = v7053 + 1;
  v7052->timer = v8872;
  int * v7055 = v7052->regs;
  int v7056 = v7055[17];
  int * v7057 = v7052->regs;
  int v8877 = (int)((unsigned int)v7056 >> 14);
  v7057[6] = v8877;
  struct StateT * v8870 = v7059(v7052);
  return v8870;
}

struct StateT * v6631(struct StateT * v6632) {
  int v6633 = v6632->timer;
  int v9360 = v6633 + 1;
  v6632->timer = v9360;
  int * v6635 = v6632->regs;
  int v6636 = v6635[15];
  int * v6637 = v6632->regs;
  int v9365 = (int)((unsigned int)v6636 >> 23);
  v6637[20] = v9365;
  struct StateT * v9358 = v6639(v6632);
  return v9358;
}

struct StateT * v2111(struct StateT * v2112) {
  int v2113 = v2112->timer;
  int v6299 = v2113 + 1;
  v2112->timer = v6299;
  int * v2115 = v2112->regs;
  v2115[6] = 857759744;
  struct StateT * v6297 = v2117(v2112);
  return v6297;
}

struct StateT * v6841(struct StateT * v6842) {
  int v6843 = v6842->timer;
  int v9118 = v6843 + 1;
  v6842->timer = v9118;
  int * v6845 = v6842->regs;
  int v6846 = v6845[8];
  int * v6847 = v6842->regs;
  int v9123 = (int)((unsigned int)v6846 >> 19);
  v6847[20] = v9123;
  struct StateT * v9116 = v6849(v6842);
  return v9116;
}

struct StateT * v2027(struct StateT * v2028) {
  int v2029 = v2028->timer;
  int v6377 = v2029 + 1;
  v2028->timer = v6377;
  int * v2031 = v2028->regs;
  v2031[15] = 1634762752;
  struct StateT * v6375 = v2033(v2028);
  return v6375;
}

struct StateT * v7665(struct StateT * v7666) {
  int v7667 = v7666->timer;
  int v8159 = v7667 + 1;
  v7666->timer = v8159;
  int * v7669 = v7666->regs;
  int v7670 = v7669[12];
  int * v7671 = v7666->regs;
  int v7672 = v7671[15];
  int * v7673 = v7666->regs;
  int v8165 = v7670 ^ v7672;
  v7673[12] = v8165;
  struct StateT * v8157 = v7675(v7666);
  return v8157;
}

struct StateT * v63(struct StateT * v64) {
  int v65 = v64->timer;
  int v11255 = v65 + 1;
  v64->timer = v11255;
  int * v67 = v64->regs;
  int v68 = v67[2];
  int * v69 = v64->regs;
  int v70 = v69[8];
  int * v71 = v64->cache_keys;
  int v72 = v71[0];
  bool v11262 = v72 == ((int)((unsigned int)(v68 + 88) >> 2));
  int v116;
  if (v11262) {
    int * v73 = v64->cache_vals;
    v73[0] = v70;
    v116 = v70;
  } else {
    int * v76 = v64->cache_keys;
    int v77 = v76[1];
    bool v11267 = v77 == ((int)((unsigned int)(v68 + 88) >> 2));
    int v114;
    if (v11267) {
      int * v78 = v64->cache_keys;
      int * v79 = v64->cache_keys;
      int v80 = v79[0];
      v78[1] = v80;
      int * v82 = v64->cache_vals;
      int * v83 = v64->cache_vals;
      int v84 = v83[0];
      v82[1] = v84;
      int * v86 = v64->cache_keys;
      int v11275 = (int)((unsigned int)(v68 + 88) >> 2);
      v86[0] = v11275;
      int * v88 = v64->cache_vals;
      v88[0] = v70;
      int v90 = v64->timer;
      int v11278 = v90 + 1;
      v64->timer = v11278;
      v114 = v70;
    } else {
      int * v93 = v64->mem;
      int * v94 = v64->cache_keys;
      int v95 = v94[1];
      int * v96 = v64->cache_vals;
      int v97 = v96[1];
      v93[v95] = v97;
      int * v99 = v64->cache_keys;
      int * v100 = v64->cache_keys;
      int v101 = v100[0];
      v99[1] = v101;
      int * v103 = v64->cache_vals;
      int * v104 = v64->cache_vals;
      int v105 = v104[0];
      v103[1] = v105;
      int * v107 = v64->cache_keys;
      int v11291 = (int)((unsigned int)(v68 + 88) >> 2);
      v107[0] = v11291;
      int * v109 = v64->cache_vals;
      v109[0] = v70;
      int v111 = v64->timer;
      int v11294 = v111 + 100;
      v64->timer = v11294;
      v114 = v70;
    }
    v116 = v114;
  }
  struct StateT * v11253 = v117(v64);
  return v11253;
}

struct StateT * v441(struct StateT * v442) {
  int v443 = v442->timer;
  int v10940 = v443 + 1;
  v442->timer = v10940;
  int * v445 = v442->regs;
  int v446 = v445[2];
  int * v447 = v442->regs;
  int v448 = v447[23];
  int * v449 = v442->cache_keys;
  int v450 = v449[0];
  bool v10947 = v450 == ((int)((unsigned int)(v446 + 60) >> 2));
  int v494;
  if (v10947) {
    int * v451 = v442->cache_vals;
    v451[0] = v448;
    v494 = v448;
  } else {
    int * v454 = v442->cache_keys;
    int v455 = v454[1];
    bool v10952 = v455 == ((int)((unsigned int)(v446 + 60) >> 2));
    int v492;
    if (v10952) {
      int * v456 = v442->cache_keys;
      int * v457 = v442->cache_keys;
      int v458 = v457[0];
      v456[1] = v458;
      int * v460 = v442->cache_vals;
      int * v461 = v442->cache_vals;
      int v462 = v461[0];
      v460[1] = v462;
      int * v464 = v442->cache_keys;
      int v10960 = (int)((unsigned int)(v446 + 60) >> 2);
      v464[0] = v10960;
      int * v466 = v442->cache_vals;
      v466[0] = v448;
      int v468 = v442->timer;
      int v10963 = v468 + 1;
      v442->timer = v10963;
      v492 = v448;
    } else {
      int * v471 = v442->mem;
      int * v472 = v442->cache_keys;
      int v473 = v472[1];
      int * v474 = v442->cache_vals;
      int v475 = v474[1];
      v471[v473] = v475;
      int * v477 = v442->cache_keys;
      int * v478 = v442->cache_keys;
      int v479 = v478[0];
      v477[1] = v479;
      int * v481 = v442->cache_vals;
      int * v482 = v442->cache_vals;
      int v483 = v482[0];
      v481[1] = v483;
      int * v485 = v442->cache_keys;
      int v10976 = (int)((unsigned int)(v446 + 60) >> 2);
      v485[0] = v10976;
      int * v487 = v442->cache_vals;
      v487[0] = v448;
      int v489 = v442->timer;
      int v10979 = v489 + 100;
      v442->timer = v10979;
      v492 = v448;
    }
    v494 = v492;
  }
  struct StateT * v10938 = v495(v442);
  return v10938;
}

struct StateT * v7481(struct StateT * v7482) {
  int v7483 = v7482->timer;
  int v8371 = v7483 + 1;
  v7482->timer = v8371;
  int * v7485 = v7482->regs;
  int v7486 = v7485[25];
  int * v7487 = v7482->regs;
  int v7488 = v7487[15];
  int * v7489 = v7482->regs;
  int v8377 = v7486 ^ v7488;
  v7489[25] = v8377;
  struct StateT * v8369 = v7491(v7482);
  return v8369;
}

struct StateT * v3393(struct StateT * v3394) {
  int v3395 = v3394->timer;
  int v5146 = v3395 + 1;
  v3394->timer = v5146;
  int * v3397 = v3394->regs;
  int v3398 = v3397[10];
  int * v3399 = v3394->regs;
  int v3400 = v3399[16];
  int * v3401 = v3394->cache_keys;
  int v3402 = v3401[0];
  bool v5153 = v3402 == ((int)((unsigned int)(v3398 + 48) >> 2));
  int v3446;
  if (v5153) {
    int * v3403 = v3394->cache_vals;
    v3403[0] = v3400;
    v3446 = v3400;
  } else {
    int * v3406 = v3394->cache_keys;
    int v3407 = v3406[1];
    bool v5158 = v3407 == ((int)((unsigned int)(v3398 + 48) >> 2));
    int v3444;
    if (v5158) {
      int * v3408 = v3394->cache_keys;
      int * v3409 = v3394->cache_keys;
      int v3410 = v3409[0];
      v3408[1] = v3410;
      int * v3412 = v3394->cache_vals;
      int * v3413 = v3394->cache_vals;
      int v3414 = v3413[0];
      v3412[1] = v3414;
      int * v3416 = v3394->cache_keys;
      int v5166 = (int)((unsigned int)(v3398 + 48) >> 2);
      v3416[0] = v5166;
      int * v3418 = v3394->cache_vals;
      v3418[0] = v3400;
      int v3420 = v3394->timer;
      int v5169 = v3420 + 1;
      v3394->timer = v5169;
      v3444 = v3400;
    } else {
      int * v3423 = v3394->mem;
      int * v3424 = v3394->cache_keys;
      int v3425 = v3424[1];
      int * v3426 = v3394->cache_vals;
      int v3427 = v3426[1];
      v3423[v3425] = v3427;
      int * v3429 = v3394->cache_keys;
      int * v3430 = v3394->cache_keys;
      int v3431 = v3430[0];
      v3429[1] = v3431;
      int * v3433 = v3394->cache_vals;
      int * v3434 = v3394->cache_vals;
      int v3435 = v3434[0];
      v3433[1] = v3435;
      int * v3437 = v3394->cache_keys;
      int v5182 = (int)((unsigned int)(v3398 + 48) >> 2);
      v3437[0] = v5182;
      int * v3439 = v3394->cache_vals;
      v3439[0] = v3400;
      int v3441 = v3394->timer;
      int v5185 = v3441 + 100;
      v3394->timer = v5185;
      v3444 = v3400;
    }
    v3446 = v3444;
  }
  struct StateT * v5144 = v3447(v3394);
  return v5144;
}

struct StateT * v4131(struct StateT * v4132) {
  int v4133 = v4132->timer;
  int v4532 = v4133 + 1;
  v4132->timer = v4532;
  int * v4135 = v4132->regs;
  int v4136 = v4135[2];
  int * v4137 = v4132->cache_keys;
  int v4138 = v4137[0];
  bool v4537 = v4138 == ((int)((unsigned int)(v4136 + 56) >> 2));
  int v4186;
  if (v4537) {
    int * v4139 = v4132->cache_vals;
    int v4140 = v4139[0];
    v4186 = v4140;
  } else {
    int * v4142 = v4132->cache_keys;
    int v4143 = v4142[1];
    bool v4542 = v4143 == ((int)((unsigned int)(v4136 + 56) >> 2));
    int v4184;
    if (v4542) {
      int * v4144 = v4132->cache_vals;
      int v4145 = v4144[1];
      int * v4146 = v4132->cache_keys;
      int * v4147 = v4132->cache_keys;
      int v4148 = v4147[0];
      v4146[1] = v4148;
      int * v4150 = v4132->cache_vals;
      int * v4151 = v4132->cache_vals;
      int v4152 = v4151[0];
      v4150[1] = v4152;
      int * v4154 = v4132->cache_keys;
      int v4551 = (int)((unsigned int)(v4136 + 56) >> 2);
      v4154[0] = v4551;
      int * v4156 = v4132->cache_vals;
      v4156[0] = v4145;
      int v4158 = v4132->timer;
      int v4554 = v4158 + 1;
      v4132->timer = v4554;
      v4184 = v4145;
    } else {
      int * v4161 = v4132->mem;
      int v4556 = (int)((unsigned int)(v4136 + 56) >> 2);
      int v4162 = v4161[v4556];
      int * v4163 = v4132->mem;
      int * v4164 = v4132->cache_keys;
      int v4165 = v4164[1];
      int * v4166 = v4132->cache_vals;
      int v4167 = v4166[1];
      v4163[v4165] = v4167;
      int * v4169 = v4132->cache_keys;
      int * v4170 = v4132->cache_keys;
      int v4171 = v4170[0];
      v4169[1] = v4171;
      int * v4173 = v4132->cache_vals;
      int * v4174 = v4132->cache_vals;
      int v4175 = v4174[0];
      v4173[1] = v4175;
      int * v4177 = v4132->cache_keys;
      v4177[0] = v4556;
      int * v4179 = v4132->cache_vals;
      v4179[0] = v4162;
      int v4181 = v4132->timer;
      int v4571 = v4181 + 100;
      v4132->timer = v4571;
      v4184 = v4162;
    }
    v4186 = v4184;
  }
  int * v4187 = v4132->regs;
  v4187[24] = v4186;
  struct StateT * v4530 = v4189(v4132);
  return v4530;
}

struct StateT * v3447(struct StateT * v3448) {
  int v3449 = v3448->timer;
  int v5101 = v3449 + 1;
  v3448->timer = v5101;
  int * v3451 = v3448->regs;
  int v3452 = v3451[10];
  int * v3453 = v3448->regs;
  int v3454 = v3453[24];
  int * v3455 = v3448->cache_keys;
  int v3456 = v3455[0];
  bool v5108 = v3456 == ((int)((unsigned int)(v3452 + 52) >> 2));
  int v3500;
  if (v5108) {
    int * v3457 = v3448->cache_vals;
    v3457[0] = v3454;
    v3500 = v3454;
  } else {
    int * v3460 = v3448->cache_keys;
    int v3461 = v3460[1];
    bool v5113 = v3461 == ((int)((unsigned int)(v3452 + 52) >> 2));
    int v3498;
    if (v5113) {
      int * v3462 = v3448->cache_keys;
      int * v3463 = v3448->cache_keys;
      int v3464 = v3463[0];
      v3462[1] = v3464;
      int * v3466 = v3448->cache_vals;
      int * v3467 = v3448->cache_vals;
      int v3468 = v3467[0];
      v3466[1] = v3468;
      int * v3470 = v3448->cache_keys;
      int v5121 = (int)((unsigned int)(v3452 + 52) >> 2);
      v3470[0] = v5121;
      int * v3472 = v3448->cache_vals;
      v3472[0] = v3454;
      int v3474 = v3448->timer;
      int v5124 = v3474 + 1;
      v3448->timer = v5124;
      v3498 = v3454;
    } else {
      int * v3477 = v3448->mem;
      int * v3478 = v3448->cache_keys;
      int v3479 = v3478[1];
      int * v3480 = v3448->cache_vals;
      int v3481 = v3480[1];
      v3477[v3479] = v3481;
      int * v3483 = v3448->cache_keys;
      int * v3484 = v3448->cache_keys;
      int v3485 = v3484[0];
      v3483[1] = v3485;
      int * v3487 = v3448->cache_vals;
      int * v3488 = v3448->cache_vals;
      int v3489 = v3488[0];
      v3487[1] = v3489;
      int * v3491 = v3448->cache_keys;
      int v5137 = (int)((unsigned int)(v3452 + 52) >> 2);
      v3491[0] = v5137;
      int * v3493 = v3448->cache_vals;
      v3493[0] = v3454;
      int v3495 = v3448->timer;
      int v5140 = v3495 + 100;
      v3448->timer = v5140;
      v3498 = v3454;
    }
    v3500 = v3498;
  }
  struct StateT * v5099 = v3501(v3448);
  return v5099;
}

struct StateT * v7585(struct StateT * v7586) {
  int v7587 = v7586->timer;
  int v8252 = v7587 + 1;
  v7586->timer = v8252;
  int * v7589 = v7586->regs;
  int v7590 = v7589[15];
  int * v7591 = v7586->regs;
  int v8256 = v7590 << 13;
  v7591[15] = v8256;
  struct StateT * v8250 = v7593(v7586);
  return v8250;
}

struct StateT * v6755(struct StateT * v6756) {
  int v6757 = v6756->timer;
  int v9217 = v6757 + 1;
  v6756->timer = v9217;
  int * v6759 = v6756->regs;
  int v6760 = v6759[27];
  int * v6761 = v6756->regs;
  int v6762 = v6761[9];
  int * v6763 = v6756->regs;
  int v9223 = v6760 ^ v6762;
  v6763[27] = v9223;
  struct StateT * v9215 = v6765(v6756);
  return v9215;
}

struct StateT * v1469(struct StateT * v1470) {
  int v1471 = v1470->timer;
  int v10097 = v1471 + 1;
  v1470->timer = v10097;
  int * v1473 = v1470->regs;
  v1473[31] = 9;
  struct StateT * v10095 = v1475(v1470);
  return v10095;
}

struct StateT * v6745(struct StateT * v6746) {
  int v6747 = v6746->timer;
  int v9228 = v6747 + 1;
  v6746->timer = v9228;
  int * v6749 = v6746->regs;
  int v6750 = v6749[24];
  int * v6751 = v6746->regs;
  int v6752 = v6751[8];
  int * v6753 = v6746->regs;
  int v9234 = v6750 ^ v6752;
  v6753[24] = v9234;
  struct StateT * v9226 = v6755(v6746);
  return v9226;
}

struct StateT * v7225(struct StateT * v7226) {
  int v7227 = v7226->timer;
  int v8669 = v7227 + 1;
  v7226->timer = v8669;
  int * v7229 = v7226->regs;
  int v7230 = v7229[11];
  int * v7231 = v7226->regs;
  int v7232 = v7231[5];
  int * v7233 = v7226->regs;
  int v8675 = v7230 | v7232;
  v7233[11] = v8675;
  struct StateT * v8667 = v7235(v7226);
  return v8667;
}

struct StateT * v7033(struct StateT * v7034) {
  int v7035 = v7034->timer;
  int v8893 = v7035 + 1;
  v7034->timer = v8893;
  int * v7037 = v7034->regs;
  int v7038 = v7037[16];
  int * v7039 = v7034->regs;
  int v8897 = v7038 << 18;
  v7039[16] = v8897;
  struct StateT * v8891 = v7041(v7034);
  return v8891;
}

struct StateT * v7199(struct StateT * v7200) {
  int v7201 = v7200->timer;
  int v8699 = v7201 + 1;
  v7200->timer = v8699;
  int * v7203 = v7200->regs;
  int v7204 = v7203[15];
  int * v7205 = v7200->regs;
  int v7206 = v7205[5];
  int * v7207 = v7200->regs;
  int v8705 = v7204 | v7206;
  v7207[15] = v8705;
  struct StateT * v8697 = v7209(v7200);
  return v8697;
}

struct StateT * v7675(struct StateT * v7676) {
  int v7677 = v7676->timer;
  int v8148 = v7677 + 1;
  v7676->timer = v8148;
  int * v7679 = v7676->regs;
  int v7680 = v7679[13];
  int * v7681 = v7676->regs;
  int v7682 = v7681[6];
  int * v7683 = v7676->regs;
  int v8154 = v7680 ^ v7682;
  v7683[13] = v8154;
  struct StateT * v8146 = v7685(v7676);
  return v8146;
}

struct StateT * v7347(struct StateT * v7348) {
  int v7349 = v7348->timer;
  int v8525 = v7349 + 1;
  v7348->timer = v8525;
  int * v7351 = v7348->regs;
  int v7352 = v7351[17];
  int * v7353 = v7348->regs;
  int v7354 = v7353[19];
  int * v7355 = v7348->regs;
  int v8532 = v7352 + v7354;
  v7355[6] = v8532;
  struct StateT * v8523 = v7357(v7348);
  return v8523;
}

struct StateT * v6795(struct StateT * v6796) {
  int v6797 = v6796->timer;
  int v9170 = v6797 + 1;
  v6796->timer = v9170;
  int * v6799 = v6796->regs;
  int v6800 = v6799[27];
  int * v6801 = v6796->regs;
  int v6802 = v6801[1];
  int * v6803 = v6796->regs;
  int v9177 = v6800 + v6802;
  v6803[9] = v9177;
  struct StateT * v9168 = v6805(v6796);
  return v9168;
}

struct StateT * v891(struct StateT * v892) {
  int v893 = v892->timer;
  int v10560 = v893 + 1;
  v892->timer = v10560;
  int * v895 = v892->regs;
  int v896 = v895[12];
  int * v897 = v892->cache_keys;
  int v898 = v897[0];
  bool v10565 = v898 == ((int)((unsigned int)(v896 + 12) >> 2));
  int v946;
  if (v10565) {
    int * v899 = v892->cache_vals;
    int v900 = v899[0];
    v946 = v900;
  } else {
    int * v902 = v892->cache_keys;
    int v903 = v902[1];
    bool v10570 = v903 == ((int)((unsigned int)(v896 + 12) >> 2));
    int v944;
    if (v10570) {
      int * v904 = v892->cache_vals;
      int v905 = v904[1];
      int * v906 = v892->cache_keys;
      int * v907 = v892->cache_keys;
      int v908 = v907[0];
      v906[1] = v908;
      int * v910 = v892->cache_vals;
      int * v911 = v892->cache_vals;
      int v912 = v911[0];
      v910[1] = v912;
      int * v914 = v892->cache_keys;
      int v10579 = (int)((unsigned int)(v896 + 12) >> 2);
      v914[0] = v10579;
      int * v916 = v892->cache_vals;
      v916[0] = v905;
      int v918 = v892->timer;
      int v10582 = v918 + 1;
      v892->timer = v10582;
      v944 = v905;
    } else {
      int * v921 = v892->mem;
      int v10584 = (int)((unsigned int)(v896 + 12) >> 2);
      int v922 = v921[v10584];
      int * v923 = v892->mem;
      int * v924 = v892->cache_keys;
      int v925 = v924[1];
      int * v926 = v892->cache_vals;
      int v927 = v926[1];
      v923[v925] = v927;
      int * v929 = v892->cache_keys;
      int * v930 = v892->cache_keys;
      int v931 = v930[0];
      v929[1] = v931;
      int * v933 = v892->cache_vals;
      int * v934 = v892->cache_vals;
      int v935 = v934[0];
      v933[1] = v935;
      int * v937 = v892->cache_keys;
      v937[0] = v10584;
      int * v939 = v892->cache_vals;
      v939[0] = v922;
      int v941 = v892->timer;
      int v10599 = v941 + 100;
      v892->timer = v10599;
      v944 = v922;
    }
    v946 = v944;
  }
  int * v947 = v892->regs;
  v947[6] = v946;
  struct StateT * v10558 = v949(v892);
  return v10558;
}

struct StateT * v6735(struct StateT * v6736) {
  int v6737 = v6736->timer;
  int v9239 = v6737 + 1;
  v6736->timer = v9239;
  int * v6739 = v6736->regs;
  int v6740 = v6739[26];
  int * v6741 = v6736->regs;
  int v6742 = v6741[15];
  int * v6743 = v6736->regs;
  int v9245 = v6740 ^ v6742;
  v6743[26] = v9245;
  struct StateT * v9237 = v6745(v6736);
  return v9237;
}

struct StateT * v3667(struct StateT * v3668) {
  int v3669 = v3668->timer;
  int v4916 = v3669 + 1;
  v3668->timer = v4916;
  int * v3671 = v3668->regs;
  int v3672 = v3671[2];
  int * v3673 = v3668->cache_keys;
  int v3674 = v3673[0];
  bool v4921 = v3674 == ((int)((unsigned int)(v3672 + 88) >> 2));
  int v3722;
  if (v4921) {
    int * v3675 = v3668->cache_vals;
    int v3676 = v3675[0];
    v3722 = v3676;
  } else {
    int * v3678 = v3668->cache_keys;
    int v3679 = v3678[1];
    bool v4926 = v3679 == ((int)((unsigned int)(v3672 + 88) >> 2));
    int v3720;
    if (v4926) {
      int * v3680 = v3668->cache_vals;
      int v3681 = v3680[1];
      int * v3682 = v3668->cache_keys;
      int * v3683 = v3668->cache_keys;
      int v3684 = v3683[0];
      v3682[1] = v3684;
      int * v3686 = v3668->cache_vals;
      int * v3687 = v3668->cache_vals;
      int v3688 = v3687[0];
      v3686[1] = v3688;
      int * v3690 = v3668->cache_keys;
      int v4935 = (int)((unsigned int)(v3672 + 88) >> 2);
      v3690[0] = v4935;
      int * v3692 = v3668->cache_vals;
      v3692[0] = v3681;
      int v3694 = v3668->timer;
      int v4938 = v3694 + 1;
      v3668->timer = v4938;
      v3720 = v3681;
    } else {
      int * v3697 = v3668->mem;
      int v4940 = (int)((unsigned int)(v3672 + 88) >> 2);
      int v3698 = v3697[v4940];
      int * v3699 = v3668->mem;
      int * v3700 = v3668->cache_keys;
      int v3701 = v3700[1];
      int * v3702 = v3668->cache_vals;
      int v3703 = v3702[1];
      v3699[v3701] = v3703;
      int * v3705 = v3668->cache_keys;
      int * v3706 = v3668->cache_keys;
      int v3707 = v3706[0];
      v3705[1] = v3707;
      int * v3709 = v3668->cache_vals;
      int * v3710 = v3668->cache_vals;
      int v3711 = v3710[0];
      v3709[1] = v3711;
      int * v3713 = v3668->cache_keys;
      v3713[0] = v4940;
      int * v3715 = v3668->cache_vals;
      v3715[0] = v3698;
      int v3717 = v3668->timer;
      int v4955 = v3717 + 100;
      v3668->timer = v4955;
      v3720 = v3698;
    }
    v3722 = v3720;
  }
  int * v3723 = v3668->regs;
  v3723[8] = v3722;
  struct StateT * v4914 = v3725(v3668);
  return v4914;
}

struct StateT * v2599(struct StateT * v2600) {
  int v2601 = v2600->timer;
  int v5830 = v2601 + 1;
  v2600->timer = v5830;
  int * v2603 = v2600->regs;
  int v2604 = v2603[2];
  int * v2605 = v2600->cache_keys;
  int v2606 = v2605[0];
  bool v5835 = v2606 == ((int)((unsigned int)(v2604 + 40) >> 2));
  int v2654;
  if (v5835) {
    int * v2607 = v2600->cache_vals;
    int v2608 = v2607[0];
    v2654 = v2608;
  } else {
    int * v2610 = v2600->cache_keys;
    int v2611 = v2610[1];
    bool v5840 = v2611 == ((int)((unsigned int)(v2604 + 40) >> 2));
    int v2652;
    if (v5840) {
      int * v2612 = v2600->cache_vals;
      int v2613 = v2612[1];
      int * v2614 = v2600->cache_keys;
      int * v2615 = v2600->cache_keys;
      int v2616 = v2615[0];
      v2614[1] = v2616;
      int * v2618 = v2600->cache_vals;
      int * v2619 = v2600->cache_vals;
      int v2620 = v2619[0];
      v2618[1] = v2620;
      int * v2622 = v2600->cache_keys;
      int v5849 = (int)((unsigned int)(v2604 + 40) >> 2);
      v2622[0] = v5849;
      int * v2624 = v2600->cache_vals;
      v2624[0] = v2613;
      int v2626 = v2600->timer;
      int v5852 = v2626 + 1;
      v2600->timer = v5852;
      v2652 = v2613;
    } else {
      int * v2629 = v2600->mem;
      int v5854 = (int)((unsigned int)(v2604 + 40) >> 2);
      int v2630 = v2629[v5854];
      int * v2631 = v2600->mem;
      int * v2632 = v2600->cache_keys;
      int v2633 = v2632[1];
      int * v2634 = v2600->cache_vals;
      int v2635 = v2634[1];
      v2631[v2633] = v2635;
      int * v2637 = v2600->cache_keys;
      int * v2638 = v2600->cache_keys;
      int v2639 = v2638[0];
      v2637[1] = v2639;
      int * v2641 = v2600->cache_vals;
      int * v2642 = v2600->cache_vals;
      int v2643 = v2642[0];
      v2641[1] = v2643;
      int * v2645 = v2600->cache_keys;
      v2645[0] = v5854;
      int * v2647 = v2600->cache_vals;
      v2647[0] = v2630;
      int v2649 = v2600->timer;
      int v5869 = v2649 + 100;
      v2600->timer = v5869;
      v2652 = v2630;
    }
    v2654 = v2652;
  }
  int * v2655 = v2600->regs;
  v2655[30] = v2654;
  struct StateT * v5828 = v2657(v2600);
  return v5828;
}

struct StateT * v4189(struct StateT * v4190) {
  int v4191 = v4190->timer;
  int v4484 = v4191 + 1;
  v4190->timer = v4484;
  int * v4193 = v4190->regs;
  int v4194 = v4193[2];
  int * v4195 = v4190->cache_keys;
  int v4196 = v4195[0];
  bool v4489 = v4196 == ((int)((unsigned int)(v4194 + 52) >> 2));
  int v4244;
  if (v4489) {
    int * v4197 = v4190->cache_vals;
    int v4198 = v4197[0];
    v4244 = v4198;
  } else {
    int * v4200 = v4190->cache_keys;
    int v4201 = v4200[1];
    bool v4494 = v4201 == ((int)((unsigned int)(v4194 + 52) >> 2));
    int v4242;
    if (v4494) {
      int * v4202 = v4190->cache_vals;
      int v4203 = v4202[1];
      int * v4204 = v4190->cache_keys;
      int * v4205 = v4190->cache_keys;
      int v4206 = v4205[0];
      v4204[1] = v4206;
      int * v4208 = v4190->cache_vals;
      int * v4209 = v4190->cache_vals;
      int v4210 = v4209[0];
      v4208[1] = v4210;
      int * v4212 = v4190->cache_keys;
      int v4503 = (int)((unsigned int)(v4194 + 52) >> 2);
      v4212[0] = v4503;
      int * v4214 = v4190->cache_vals;
      v4214[0] = v4203;
      int v4216 = v4190->timer;
      int v4506 = v4216 + 1;
      v4190->timer = v4506;
      v4242 = v4203;
    } else {
      int * v4219 = v4190->mem;
      int v4508 = (int)((unsigned int)(v4194 + 52) >> 2);
      int v4220 = v4219[v4508];
      int * v4221 = v4190->mem;
      int * v4222 = v4190->cache_keys;
      int v4223 = v4222[1];
      int * v4224 = v4190->cache_vals;
      int v4225 = v4224[1];
      v4221[v4223] = v4225;
      int * v4227 = v4190->cache_keys;
      int * v4228 = v4190->cache_keys;
      int v4229 = v4228[0];
      v4227[1] = v4229;
      int * v4231 = v4190->cache_vals;
      int * v4232 = v4190->cache_vals;
      int v4233 = v4232[0];
      v4231[1] = v4233;
      int * v4235 = v4190->cache_keys;
      v4235[0] = v4508;
      int * v4237 = v4190->cache_vals;
      v4237[0] = v4220;
      int v4239 = v4190->timer;
      int v4523 = v4239 + 100;
      v4190->timer = v4523;
      v4242 = v4220;
    }
    v4244 = v4242;
  }
  int * v4245 = v4190->regs;
  v4245[25] = v4244;
  struct StateT * v4482 = v4247(v4190);
  return v4482;
}

struct StateT * v2667(struct StateT * v2668) {
  int v2669 = v2668->timer;
  int v5811 = v2669 + 1;
  v2668->timer = v5811;
  int * v2671 = v2668->regs;
  v2671[30] = 1797283840;
  struct StateT * v5809 = v2673(v2668);
  return v5809;
}

struct StateT * v7803(struct StateT * v7804) {
  int v7805 = v7804->timer;
  int v7999 = v7805 + 1;
  v7804->timer = v7999;
  int * v7807 = v7804->regs;
  int v7808 = v7807[6];
  int * v7809 = v7804->regs;
  int v7810 = v7809[9];
  int * v7811 = v7804->regs;
  int v8005 = v7808 | v7810;
  v7811[6] = v8005;
  struct StateT * v7997 = v7813(v7804);
  return v7997;
}

struct StateT * v1065(struct StateT * v1066) {
  int v1067 = v1066->timer;
  int v10416 = v1067 + 1;
  v1066->timer = v10416;
  int * v1069 = v1066->regs;
  int v1070 = v1069[12];
  int * v1071 = v1066->cache_keys;
  int v1072 = v1071[0];
  bool v10421 = v1072 == ((int)((unsigned int)(v1070 + 24) >> 2));
  int v1120;
  if (v10421) {
    int * v1073 = v1066->cache_vals;
    int v1074 = v1073[0];
    v1120 = v1074;
  } else {
    int * v1076 = v1066->cache_keys;
    int v1077 = v1076[1];
    bool v10426 = v1077 == ((int)((unsigned int)(v1070 + 24) >> 2));
    int v1118;
    if (v10426) {
      int * v1078 = v1066->cache_vals;
      int v1079 = v1078[1];
      int * v1080 = v1066->cache_keys;
      int * v1081 = v1066->cache_keys;
      int v1082 = v1081[0];
      v1080[1] = v1082;
      int * v1084 = v1066->cache_vals;
      int * v1085 = v1066->cache_vals;
      int v1086 = v1085[0];
      v1084[1] = v1086;
      int * v1088 = v1066->cache_keys;
      int v10435 = (int)((unsigned int)(v1070 + 24) >> 2);
      v1088[0] = v10435;
      int * v1090 = v1066->cache_vals;
      v1090[0] = v1079;
      int v1092 = v1066->timer;
      int v10438 = v1092 + 1;
      v1066->timer = v10438;
      v1118 = v1079;
    } else {
      int * v1095 = v1066->mem;
      int v10440 = (int)((unsigned int)(v1070 + 24) >> 2);
      int v1096 = v1095[v10440];
      int * v1097 = v1066->mem;
      int * v1098 = v1066->cache_keys;
      int v1099 = v1098[1];
      int * v1100 = v1066->cache_vals;
      int v1101 = v1100[1];
      v1097[v1099] = v1101;
      int * v1103 = v1066->cache_keys;
      int * v1104 = v1066->cache_keys;
      int v1105 = v1104[0];
      v1103[1] = v1105;
      int * v1107 = v1066->cache_vals;
      int * v1108 = v1066->cache_vals;
      int v1109 = v1108[0];
      v1107[1] = v1109;
      int * v1111 = v1066->cache_keys;
      v1111[0] = v10440;
      int * v1113 = v1066->cache_vals;
      v1113[0] = v1096;
      int v1115 = v1066->timer;
      int v10455 = v1115 + 100;
      v1066->timer = v10455;
      v1118 = v1096;
    }
    v1120 = v1118;
  }
  int * v1121 = v1066->regs;
  v1121[24] = v1120;
  struct StateT * v10414 = v1123(v1066);
  return v10414;
}

struct StateT * v7769(struct StateT * v7770) {
  int v7771 = v7770->timer;
  int v8040 = v7771 + 1;
  v7770->timer = v8040;
  int * v7773 = v7770->regs;
  int v7774 = v7773[15];
  int * v7775 = v7770->regs;
  int v8044 = v7774 << 18;
  v7775[15] = v8044;
  struct StateT * v8038 = v7777(v7770);
  return v8038;
}

struct StateT * v657(struct StateT * v658) {
  int v659 = v658->timer;
  int v10760 = v659 + 1;
  v658->timer = v10760;
  int * v661 = v658->regs;
  int v662 = v661[2];
  int * v663 = v658->regs;
  int v664 = v663[27];
  int * v665 = v658->cache_keys;
  int v666 = v665[0];
  bool v10767 = v666 == ((int)((unsigned int)(v662 + 44) >> 2));
  int v710;
  if (v10767) {
    int * v667 = v658->cache_vals;
    v667[0] = v664;
    v710 = v664;
  } else {
    int * v670 = v658->cache_keys;
    int v671 = v670[1];
    bool v10772 = v671 == ((int)((unsigned int)(v662 + 44) >> 2));
    int v708;
    if (v10772) {
      int * v672 = v658->cache_keys;
      int * v673 = v658->cache_keys;
      int v674 = v673[0];
      v672[1] = v674;
      int * v676 = v658->cache_vals;
      int * v677 = v658->cache_vals;
      int v678 = v677[0];
      v676[1] = v678;
      int * v680 = v658->cache_keys;
      int v10780 = (int)((unsigned int)(v662 + 44) >> 2);
      v680[0] = v10780;
      int * v682 = v658->cache_vals;
      v682[0] = v664;
      int v684 = v658->timer;
      int v10783 = v684 + 1;
      v658->timer = v10783;
      v708 = v664;
    } else {
      int * v687 = v658->mem;
      int * v688 = v658->cache_keys;
      int v689 = v688[1];
      int * v690 = v658->cache_vals;
      int v691 = v690[1];
      v687[v689] = v691;
      int * v693 = v658->cache_keys;
      int * v694 = v658->cache_keys;
      int v695 = v694[0];
      v693[1] = v695;
      int * v697 = v658->cache_vals;
      int * v698 = v658->cache_vals;
      int v699 = v698[0];
      v697[1] = v699;
      int * v701 = v658->cache_keys;
      int v10796 = (int)((unsigned int)(v662 + 44) >> 2);
      v701[0] = v10796;
      int * v703 = v658->cache_vals;
      v703[0] = v664;
      int v705 = v658->timer;
      int v10799 = v705 + 100;
      v658->timer = v10799;
      v708 = v664;
    }
    v710 = v708;
  }
  struct StateT * v10758 = v711(v658);
  return v10758;
}

struct StateT * v7511(struct StateT * v7512) {
  int v7513 = v7512->timer;
  int v8337 = v7513 + 1;
  v7512->timer = v8337;
  int * v7515 = v7512->regs;
  int v7516 = v7515[27];
  int * v7517 = v7512->regs;
  int v7518 = v7517[23];
  int * v7519 = v7512->regs;
  int v8344 = v7516 + v7518;
  v7519[11] = v8344;
  struct StateT * v8335 = v7521(v7512);
  return v8335;
}

struct StateT * v3957(struct StateT * v3958) {
  int v3959 = v3958->timer;
  int v4676 = v3959 + 1;
  v3958->timer = v4676;
  int * v3961 = v3958->regs;
  int v3962 = v3961[2];
  int * v3963 = v3958->cache_keys;
  int v3964 = v3963[0];
  bool v4681 = v3964 == ((int)((unsigned int)(v3962 + 68) >> 2));
  int v4012;
  if (v4681) {
    int * v3965 = v3958->cache_vals;
    int v3966 = v3965[0];
    v4012 = v3966;
  } else {
    int * v3968 = v3958->cache_keys;
    int v3969 = v3968[1];
    bool v4686 = v3969 == ((int)((unsigned int)(v3962 + 68) >> 2));
    int v4010;
    if (v4686) {
      int * v3970 = v3958->cache_vals;
      int v3971 = v3970[1];
      int * v3972 = v3958->cache_keys;
      int * v3973 = v3958->cache_keys;
      int v3974 = v3973[0];
      v3972[1] = v3974;
      int * v3976 = v3958->cache_vals;
      int * v3977 = v3958->cache_vals;
      int v3978 = v3977[0];
      v3976[1] = v3978;
      int * v3980 = v3958->cache_keys;
      int v4695 = (int)((unsigned int)(v3962 + 68) >> 2);
      v3980[0] = v4695;
      int * v3982 = v3958->cache_vals;
      v3982[0] = v3971;
      int v3984 = v3958->timer;
      int v4698 = v3984 + 1;
      v3958->timer = v4698;
      v4010 = v3971;
    } else {
      int * v3987 = v3958->mem;
      int v4700 = (int)((unsigned int)(v3962 + 68) >> 2);
      int v3988 = v3987[v4700];
      int * v3989 = v3958->mem;
      int * v3990 = v3958->cache_keys;
      int v3991 = v3990[1];
      int * v3992 = v3958->cache_vals;
      int v3993 = v3992[1];
      v3989[v3991] = v3993;
      int * v3995 = v3958->cache_keys;
      int * v3996 = v3958->cache_keys;
      int v3997 = v3996[0];
      v3995[1] = v3997;
      int * v3999 = v3958->cache_vals;
      int * v4000 = v3958->cache_vals;
      int v4001 = v4000[0];
      v3999[1] = v4001;
      int * v4003 = v3958->cache_keys;
      v4003[0] = v4700;
      int * v4005 = v3958->cache_vals;
      v4005[0] = v3988;
      int v4007 = v3958->timer;
      int v4715 = v4007 + 100;
      v3958->timer = v4715;
      v4010 = v3988;
    }
    v4012 = v4010;
  }
  int * v4013 = v3958->regs;
  v4013[21] = v4012;
  struct StateT * v4674 = v4015(v3958);
  return v4674;
}

struct StateT * v1907(struct StateT * v1908) {
  int v1909 = v1908->timer;
  int v9728 = v1909 + 1;
  v1908->timer = v9728;
  int * v1911 = v1908->regs;
  int v1912 = v1911[6];
  int * v1913 = v1908->regs;
  v1913[12] = v1912;
  struct StateT * v9726 = v1915(v1908);
  return v9726;
}

struct StateT * v1413(struct StateT * v1414) {
  int v1415 = v1414->timer;
  int v10168 = v1415 + 1;
  v1414->timer = v10168;
  int * v1417 = v1414->regs;
  v1417[12] = 1634762752;
  struct StateT * v10166 = v1419(v1414);
  return v10166;
}

struct StateT * v2001(struct StateT * v2002) {
  int v2003 = v2002->timer;
  int v9632 = v2003 + 1;
  v2002->timer = v9632;
  int * v2005 = v2002->regs;
  int v2006 = v2005[31];
  bool v9635 = (v2006 ^ -2147483648) < -2147483648;
  struct StateT * v9630;
  if (v9635) {
    struct StateT * v6405 = v2007(v2002);
    v9630 = v6405;
  } else {
    struct StateT * v9628 = v6407(v2002);
    v9630 = v9628;
  }
  return v9630;
}

struct StateT * v1993(struct StateT * v1994) {
  int v1995 = v1994->timer;
  int v9643 = v1995 + 1;
  v1994->timer = v9643;
  int * v1997 = v1994->regs;
  int v1998 = v1997[15];
  int * v1999 = v1994->regs;
  v1999[13] = v1998;
  struct StateT * v9641 = v2001(v1994);
  return v9641;
}

struct StateT * v7655(struct StateT * v7656) {
  int v7657 = v7656->timer;
  int v8170 = v7657 + 1;
  v7656->timer = v8170;
  int * v7659 = v7656->regs;
  int v7660 = v7659[14];
  int * v7661 = v7656->regs;
  int v7662 = v7661[11];
  int * v7663 = v7656->regs;
  int v8176 = v7660 ^ v7662;
  v7663[14] = v8176;
  struct StateT * v8168 = v7665(v7656);
  return v8168;
}

struct StateT * v7725(struct StateT * v7726) {
  int v7727 = v7726->timer;
  int v8089 = v7727 + 1;
  v7726->timer = v8089;
  int * v7729 = v7726->regs;
  int v7730 = v7729[1];
  int * v7731 = v7726->regs;
  int v7732 = v7731[24];
  int * v7733 = v7726->regs;
  int v8096 = v7730 + v7732;
  v7733[8] = v8096;
  struct StateT * v8087 = v7735(v7726);
  return v8087;
}

struct StateT * v2175(struct StateT * v2176) {
  int v2177 = v2176->timer;
  int v6240 = v2177 + 1;
  v2176->timer = v6240;
  int * v2179 = v2176->regs;
  int v2180 = v2179[5];
  int * v2181 = v2176->regs;
  int v2182 = v2181[7];
  int * v2183 = v2176->regs;
  int v6246 = v2180 + v2182;
  v2183[5] = v6246;
  struct StateT * v6238 = v2185(v2176);
  return v6238;
}

struct StateT * v7085(struct StateT * v7086) {
  int v7087 = v7086->timer;
  int v8833 = v7087 + 1;
  v7086->timer = v8833;
  int * v7089 = v7086->regs;
  int v7090 = v7089[5];
  int * v7091 = v7086->regs;
  int v8837 = v7090 << 18;
  v7091[5] = v8837;
  struct StateT * v8831 = v7093(v7086);
  return v8831;
}

struct StateT * v1475(struct StateT * v1476) {
  int v1477 = v1476->timer;
  int v10052 = v1477 + 1;
  v1476->timer = v10052;
  int * v1479 = v1476->regs;
  int v1480 = v1479[2];
  int * v1481 = v1476->regs;
  int v1482 = v1481[26];
  int * v1483 = v1476->cache_keys;
  int v1484 = v1483[0];
  bool v10059 = v1484 == ((int)((unsigned int)(v1480 + 20) >> 2));
  int v1528;
  if (v10059) {
    int * v1485 = v1476->cache_vals;
    v1485[0] = v1482;
    v1528 = v1482;
  } else {
    int * v1488 = v1476->cache_keys;
    int v1489 = v1488[1];
    bool v10064 = v1489 == ((int)((unsigned int)(v1480 + 20) >> 2));
    int v1526;
    if (v10064) {
      int * v1490 = v1476->cache_keys;
      int * v1491 = v1476->cache_keys;
      int v1492 = v1491[0];
      v1490[1] = v1492;
      int * v1494 = v1476->cache_vals;
      int * v1495 = v1476->cache_vals;
      int v1496 = v1495[0];
      v1494[1] = v1496;
      int * v1498 = v1476->cache_keys;
      int v10072 = (int)((unsigned int)(v1480 + 20) >> 2);
      v1498[0] = v10072;
      int * v1500 = v1476->cache_vals;
      v1500[0] = v1482;
      int v1502 = v1476->timer;
      int v10075 = v1502 + 1;
      v1476->timer = v10075;
      v1526 = v1482;
    } else {
      int * v1505 = v1476->mem;
      int * v1506 = v1476->cache_keys;
      int v1507 = v1506[1];
      int * v1508 = v1476->cache_vals;
      int v1509 = v1508[1];
      v1505[v1507] = v1509;
      int * v1511 = v1476->cache_keys;
      int * v1512 = v1476->cache_keys;
      int v1513 = v1512[0];
      v1511[1] = v1513;
      int * v1515 = v1476->cache_vals;
      int * v1516 = v1476->cache_vals;
      int v1517 = v1516[0];
      v1515[1] = v1517;
      int * v1519 = v1476->cache_keys;
      int v10088 = (int)((unsigned int)(v1480 + 20) >> 2);
      v1519[0] = v10088;
      int * v1521 = v1476->cache_vals;
      v1521[0] = v1482;
      int v1523 = v1476->timer;
      int v10091 = v1523 + 100;
      v1476->timer = v10091;
      v1526 = v1482;
    }
    v1528 = v1526;
  }
  struct StateT * v10050 = v1529(v1476);
  return v10050;
}

struct StateT * v7217(struct StateT * v7218) {
  int v7219 = v7218->timer;
  int v8680 = v7219 + 1;
  v7218->timer = v8680;
  int * v7221 = v7218->regs;
  int v7222 = v7221[11];
  int * v7223 = v7218->regs;
  int v8684 = v7222 << 7;
  v7223[11] = v8684;
  struct StateT * v8678 = v7225(v7218);
  return v8678;
}

struct StateT * v6455(struct StateT * v6456) {
  int v6457 = v6456->timer;
  int v9563 = v6457 + 1;
  v6456->timer = v9563;
  int * v6459 = v6456->regs;
  int v6460 = v6459[15];
  int * v6461 = v6456->regs;
  int v9567 = v6460 << 7;
  v6461[15] = v9567;
  struct StateT * v9561 = v6463(v6456);
  return v9561;
}

struct StateT * v7383(struct StateT * v7384) {
  int v7385 = v7384->timer;
  int v8483 = v7385 + 1;
  v7384->timer = v8483;
  int * v7387 = v7384->regs;
  int v7388 = v7387[11];
  int * v7389 = v7384->regs;
  int v7390 = v7389[9];
  int * v7391 = v7384->regs;
  int v8489 = v7388 | v7390;
  v7391[11] = v8489;
  struct StateT * v8481 = v7393(v7384);
  return v8481;
}

struct StateT * v7849(struct StateT * v7850) {
  int v7851 = v7850->timer;
  int v7946 = v7851 + 1;
  v7850->timer = v7946;
  int * v7853 = v7850->regs;
  int v7854 = v7853[20];
  int * v7855 = v7850->regs;
  int v7856 = v7855[15];
  int * v7857 = v7850->regs;
  int v7953 = v7854 ^ v7856;
  v7857[11] = v7953;
  struct StateT * v7944 = v7859(v7850);
  return v7944;
}

struct StateT * v7619(struct StateT * v7620) {
  int v7621 = v7620->timer;
  int v8211 = v7621 + 1;
  v7620->timer = v8211;
  int * v7623 = v7620->regs;
  int v7624 = v7623[6];
  int * v7625 = v7620->regs;
  int v7626 = v7625[9];
  int * v7627 = v7620->regs;
  int v8217 = v7624 | v7626;
  v7627[6] = v8217;
  struct StateT * v8209 = v7629(v7620);
  return v8209;
}

struct StateT * v6785(struct StateT * v6786) {
  int v6787 = v6786->timer;
  int v9182 = v6787 + 1;
  v6786->timer = v9182;
  int * v6789 = v6786->regs;
  int v6790 = v6789[24];
  int * v6791 = v6786->regs;
  int v6792 = v6791[13];
  int * v6793 = v6786->regs;
  int v9189 = v6790 + v6792;
  v6793[8] = v9189;
  struct StateT * v9180 = v6795(v6786);
  return v9180;
}

struct StateT * v2681(struct StateT * v2682) {
  int v2683 = v2682->timer;
  int v5793 = v2683 + 1;
  v2682->timer = v5793;
  int * v2685 = v2682->regs;
  int v2686 = v2685[6];
  int * v2687 = v2682->regs;
  int v5797 = v2686 + 1134;
  v2687[6] = v5797;
  struct StateT * v5791 = v2689(v2682);
  return v5791;
}

struct StateT * v7093(struct StateT * v7094) {
  int v7095 = v7094->timer;
  int v8822 = v7095 + 1;
  v7094->timer = v8822;
  int * v7097 = v7094->regs;
  int v7098 = v7097[5];
  int * v7099 = v7094->regs;
  int v7100 = v7099[6];
  int * v7101 = v7094->regs;
  int v8828 = v7098 | v7100;
  v7101[5] = v8828;
  struct StateT * v8820 = v7103(v7094);
  return v8820;
}

struct StateT * v1425(struct StateT * v1426) {
  int v1427 = v1426->timer;
  int v10152 = v1427 + 1;
  v1426->timer = v10152;
  int * v1429 = v1426->regs;
  v1429[14] = 2036477952;
  struct StateT * v10150 = v1431(v1426);
  return v10150;
}

struct StateT * v1637(struct StateT * v1638) {
  int v1639 = v1638->timer;
  int v9918 = v1639 + 1;
  v1638->timer = v9918;
  int * v1641 = v1638->regs;
  int v1642 = v1641[2];
  int * v1643 = v1638->regs;
  int v1644 = v1643[1];
  int * v1645 = v1638->cache_keys;
  int v1646 = v1645[0];
  bool v9925 = v1646 == ((int)((unsigned int)(v1642 + 40) >> 2));
  int v1690;
  if (v9925) {
    int * v1647 = v1638->cache_vals;
    v1647[0] = v1644;
    v1690 = v1644;
  } else {
    int * v1650 = v1638->cache_keys;
    int v1651 = v1650[1];
    bool v9929 = v1651 == ((int)((unsigned int)(v1642 + 40) >> 2));
    int v1688;
    if (v9929) {
      int * v1652 = v1638->cache_keys;
      int * v1653 = v1638->cache_keys;
      int v1654 = v1653[0];
      v1652[1] = v1654;
      int * v1656 = v1638->cache_vals;
      int * v1657 = v1638->cache_vals;
      int v1658 = v1657[0];
      v1656[1] = v1658;
      int * v1660 = v1638->cache_keys;
      int v9937 = (int)((unsigned int)(v1642 + 40) >> 2);
      v1660[0] = v9937;
      int * v1662 = v1638->cache_vals;
      v1662[0] = v1644;
      int v1664 = v1638->timer;
      int v9940 = v1664 + 1;
      v1638->timer = v9940;
      v1688 = v1644;
    } else {
      int * v1667 = v1638->mem;
      int * v1668 = v1638->cache_keys;
      int v1669 = v1668[1];
      int * v1670 = v1638->cache_vals;
      int v1671 = v1670[1];
      v1667[v1669] = v1671;
      int * v1673 = v1638->cache_keys;
      int * v1674 = v1638->cache_keys;
      int v1675 = v1674[0];
      v1673[1] = v1675;
      int * v1677 = v1638->cache_vals;
      int * v1678 = v1638->cache_vals;
      int v1679 = v1678[0];
      v1677[1] = v1679;
      int * v1681 = v1638->cache_keys;
      int v9953 = (int)((unsigned int)(v1642 + 40) >> 2);
      v1681[0] = v9953;
      int * v1683 = v1638->cache_vals;
      v1683[0] = v1644;
      int v1685 = v1638->timer;
      int v9956 = v1685 + 100;
      v1638->timer = v9956;
      v1688 = v1644;
    }
    v1690 = v1688;
  }
  struct StateT * v9916 = v1691(v1638);
  return v9916;
}

struct StateT * v7593(struct StateT * v7594) {
  int v7595 = v7594->timer;
  int v8241 = v7595 + 1;
  v7594->timer = v8241;
  int * v7597 = v7594->regs;
  int v7598 = v7597[15];
  int * v7599 = v7594->regs;
  int v7600 = v7599[9];
  int * v7601 = v7594->regs;
  int v8247 = v7598 | v7600;
  v7601[15] = v8247;
  struct StateT * v8239 = v7603(v7594);
  return v8239;
}

struct StateT * v7427(struct StateT * v7428) {
  int v7429 = v7428->timer;
  int v8434 = v7429 + 1;
  v7428->timer = v8434;
  int * v7431 = v7428->regs;
  int v7432 = v7431[6];
  int * v7433 = v7428->regs;
  int v8438 = v7432 << 9;
  v7433[6] = v8438;
  struct StateT * v8432 = v7435(v7428);
  return v8432;
}

struct StateT * v7209(struct StateT * v7210) {
  int v7211 = v7210->timer;
  int v8689 = v7211 + 1;
  v7210->timer = v8689;
  int * v7213 = v7210->regs;
  int v7214 = v7213[11];
  int * v7215 = v7210->regs;
  int v8694 = (int)((unsigned int)v7214 >> 25);
  v7215[5] = v8694;
  struct StateT * v8687 = v7217(v7210);
  return v8687;
}

struct StateT * v6875(struct StateT * v6876) {
  int v6877 = v6876->timer;
  int v9079 = v6877 + 1;
  v6876->timer = v9079;
  int * v6879 = v6876->regs;
  int v6880 = v6879[9];
  int * v6881 = v6876->regs;
  int v9083 = v6880 << 13;
  v6881[9] = v9083;
  struct StateT * v9077 = v6883(v6876);
  return v9077;
}

struct StateT * v7307(struct StateT * v7308) {
  int v7309 = v7308->timer;
  int v8573 = v7309 + 1;
  v7308->timer = v8573;
  int * v7311 = v7308->regs;
  int v7312 = v7311[8];
  int * v7313 = v7308->regs;
  int v7314 = v7313[16];
  int * v7315 = v7308->regs;
  int v8580 = v7312 ^ v7314;
  v7315[17] = v8580;
  struct StateT * v8571 = v7317(v7308);
  return v8571;
}

struct StateT * v7887(struct StateT * v7888) {
  int v7889 = v7888->timer;
  int v7902 = v7889 + 1;
  v7888->timer = v7902;
  int * v7891 = v7888->regs;
  int v7892 = v7891[31];
  int * v7893 = v7888->regs;
  int v7894 = v7893[30];
  bool v7907 = (v7892 ^ -2147483648) >= (v7894 ^ -2147483648);
  struct StateT * v7900;
  if (v7907) {
    struct StateT * v7896 = v6407(v7888);
    v7900 = v7896;
  } else {
    struct StateT * v7898 = v2007(v7888);
    v7900 = v7898;
  }
  return v7900;
}

struct StateT * v7337(struct StateT * v7338) {
  int v7339 = v7338->timer;
  int v8537 = v7339 + 1;
  v7338->timer = v8537;
  int * v7341 = v7338->regs;
  int v7342 = v7341[5];
  int * v7343 = v7338->regs;
  int v7344 = v7343[20];
  int * v7345 = v7338->regs;
  int v8544 = v7342 + v7344;
  v7345[15] = v8544;
  struct StateT * v8535 = v7347(v7338);
  return v8535;
}

struct StateT * v7685(struct StateT * v7686) {
  int v7687 = v7686->timer;
  int v8137 = v7687 + 1;
  v7686->timer = v8137;
  int * v7689 = v7686->regs;
  int v7690 = v7689[1];
  int * v7691 = v7686->regs;
  int v7692 = v7691[8];
  int * v7693 = v7686->regs;
  int v8143 = v7690 ^ v7692;
  v7693[1] = v8143;
  struct StateT * v8135 = v7695(v7686);
  return v8135;
}

struct StateT * v2589(struct StateT * v2590) {
  int v2591 = v2590->timer;
  int v5878 = v2591 + 1;
  v2590->timer = v5878;
  int * v2593 = v2590->regs;
  int v2594 = v2593[24];
  int * v2595 = v2590->regs;
  int v2596 = v2595[30];
  int * v2597 = v2590->regs;
  int v5884 = v2594 + v2596;
  v2597[24] = v5884;
  struct StateT * v5876 = v2599(v2590);
  return v5876;
}

struct StateT * v6499(struct StateT * v6500) {
  int v6501 = v6500->timer;
  int v9512 = v6501 + 1;
  v6500->timer = v9512;
  int * v6503 = v6500->regs;
  int v6504 = v6503[18];
  int * v6505 = v6500->regs;
  int v9517 = (int)((unsigned int)v6504 >> 25);
  v6505[20] = v9517;
  struct StateT * v9510 = v6507(v6500);
  return v9510;
}

struct StateT * v7715(struct StateT * v7716) {
  int v7717 = v7716->timer;
  int v8101 = v7717 + 1;
  v7716->timer = v8101;
  int * v7719 = v7716->regs;
  int v7720 = v7719[13];
  int * v7721 = v7716->regs;
  int v7722 = v7721[26];
  int * v7723 = v7716->regs;
  int v8108 = v7720 + v7722;
  v7723[6] = v8108;
  struct StateT * v8099 = v7725(v7716);
  return v8099;
}

struct StateT * v7795(struct StateT * v7796) {
  int v7797 = v7796->timer;
  int v8010 = v7797 + 1;
  v7796->timer = v8010;
  int * v7799 = v7796->regs;
  int v7800 = v7799[6];
  int * v7801 = v7796->regs;
  int v8014 = v7800 << 18;
  v7801[6] = v8014;
  struct StateT * v8008 = v7803(v7796);
  return v8008;
}

struct StateT * v6561(struct StateT * v6562) {
  int v6563 = v6562->timer;
  int v9440 = v6563 + 1;
  v6562->timer = v9440;
  int * v6565 = v6562->regs;
  int v6566 = v6565[13];
  int * v6567 = v6562->regs;
  int v6568 = v6567[9];
  int * v6569 = v6562->regs;
  int v9446 = v6566 ^ v6568;
  v6569[13] = v9446;
  struct StateT * v9438 = v6571(v6562);
  return v9438;
}

struct StateT * v1239(struct StateT * v1240) {
  int v1241 = v1240->timer;
  int v10272 = v1241 + 1;
  v1240->timer = v10272;
  int * v1243 = v1240->regs;
  int v1244 = v1243[11];
  int * v1245 = v1240->cache_keys;
  int v1246 = v1245[0];
  bool v10277 = v1246 == ((int)((unsigned int)(v1244 + 4) >> 2));
  int v1294;
  if (v10277) {
    int * v1247 = v1240->cache_vals;
    int v1248 = v1247[0];
    v1294 = v1248;
  } else {
    int * v1250 = v1240->cache_keys;
    int v1251 = v1250[1];
    bool v10282 = v1251 == ((int)((unsigned int)(v1244 + 4) >> 2));
    int v1292;
    if (v10282) {
      int * v1252 = v1240->cache_vals;
      int v1253 = v1252[1];
      int * v1254 = v1240->cache_keys;
      int * v1255 = v1240->cache_keys;
      int v1256 = v1255[0];
      v1254[1] = v1256;
      int * v1258 = v1240->cache_vals;
      int * v1259 = v1240->cache_vals;
      int v1260 = v1259[0];
      v1258[1] = v1260;
      int * v1262 = v1240->cache_keys;
      int v10291 = (int)((unsigned int)(v1244 + 4) >> 2);
      v1262[0] = v10291;
      int * v1264 = v1240->cache_vals;
      v1264[0] = v1253;
      int v1266 = v1240->timer;
      int v10294 = v1266 + 1;
      v1240->timer = v10294;
      v1292 = v1253;
    } else {
      int * v1269 = v1240->mem;
      int v10296 = (int)((unsigned int)(v1244 + 4) >> 2);
      int v1270 = v1269[v10296];
      int * v1271 = v1240->mem;
      int * v1272 = v1240->cache_keys;
      int v1273 = v1272[1];
      int * v1274 = v1240->cache_vals;
      int v1275 = v1274[1];
      v1271[v1273] = v1275;
      int * v1277 = v1240->cache_keys;
      int * v1278 = v1240->cache_keys;
      int v1279 = v1278[0];
      v1277[1] = v1279;
      int * v1281 = v1240->cache_vals;
      int * v1282 = v1240->cache_vals;
      int v1283 = v1282[0];
      v1281[1] = v1283;
      int * v1285 = v1240->cache_keys;
      v1285[0] = v10296;
      int * v1287 = v1240->cache_vals;
      v1287[0] = v1270;
      int v1289 = v1240->timer;
      int v10311 = v1289 + 100;
      v1240->timer = v10311;
      v1292 = v1270;
    }
    v1294 = v1292;
  }
  int * v1295 = v1240->regs;
  v1295[25] = v1294;
  struct StateT * v10270 = v1297(v1240);
  return v10270;
}

struct StateT * v7163(struct StateT * v7164) {
  int v7165 = v7164->timer;
  int v8741 = v7165 + 1;
  v7164->timer = v8741;
  int * v7167 = v7164->regs;
  int v7168 = v7167[19];
  int * v7169 = v7164->regs;
  int v7170 = v7169[13];
  int * v7171 = v7164->regs;
  int v8748 = v7168 + v7170;
  v7171[16] = v8748;
  struct StateT * v8739 = v7173(v7164);
  return v8739;
}

struct StateT * v7705(struct StateT * v7706) {
  int v7707 = v7706->timer;
  int v8113 = v7707 + 1;
  v7706->timer = v8113;
  int * v7709 = v7706->regs;
  int v7710 = v7709[12];
  int * v7711 = v7706->regs;
  int v7712 = v7711[25];
  int * v7713 = v7706->regs;
  int v8120 = v7710 + v7712;
  v7713[15] = v8120;
  struct StateT * v8111 = v7715(v7706);
  return v8111;
}

struct StateT * v3783(struct StateT * v3784) {
  int v3785 = v3784->timer;
  int v4820 = v3785 + 1;
  v3784->timer = v4820;
  int * v3787 = v3784->regs;
  int v3788 = v3787[2];
  int * v3789 = v3784->cache_keys;
  int v3790 = v3789[0];
  bool v4825 = v3790 == ((int)((unsigned int)(v3788 + 80) >> 2));
  int v3838;
  if (v4825) {
    int * v3791 = v3784->cache_vals;
    int v3792 = v3791[0];
    v3838 = v3792;
  } else {
    int * v3794 = v3784->cache_keys;
    int v3795 = v3794[1];
    bool v4830 = v3795 == ((int)((unsigned int)(v3788 + 80) >> 2));
    int v3836;
    if (v4830) {
      int * v3796 = v3784->cache_vals;
      int v3797 = v3796[1];
      int * v3798 = v3784->cache_keys;
      int * v3799 = v3784->cache_keys;
      int v3800 = v3799[0];
      v3798[1] = v3800;
      int * v3802 = v3784->cache_vals;
      int * v3803 = v3784->cache_vals;
      int v3804 = v3803[0];
      v3802[1] = v3804;
      int * v3806 = v3784->cache_keys;
      int v4839 = (int)((unsigned int)(v3788 + 80) >> 2);
      v3806[0] = v4839;
      int * v3808 = v3784->cache_vals;
      v3808[0] = v3797;
      int v3810 = v3784->timer;
      int v4842 = v3810 + 1;
      v3784->timer = v4842;
      v3836 = v3797;
    } else {
      int * v3813 = v3784->mem;
      int v4844 = (int)((unsigned int)(v3788 + 80) >> 2);
      int v3814 = v3813[v4844];
      int * v3815 = v3784->mem;
      int * v3816 = v3784->cache_keys;
      int v3817 = v3816[1];
      int * v3818 = v3784->cache_vals;
      int v3819 = v3818[1];
      v3815[v3817] = v3819;
      int * v3821 = v3784->cache_keys;
      int * v3822 = v3784->cache_keys;
      int v3823 = v3822[0];
      v3821[1] = v3823;
      int * v3825 = v3784->cache_vals;
      int * v3826 = v3784->cache_vals;
      int v3827 = v3826[0];
      v3825[1] = v3827;
      int * v3829 = v3784->cache_keys;
      v3829[0] = v4844;
      int * v3831 = v3784->cache_vals;
      v3831[0] = v3814;
      int v3833 = v3784->timer;
      int v4859 = v3833 + 100;
      v3784->timer = v4859;
      v3836 = v3814;
    }
    v3838 = v3836;
  }
  int * v3839 = v3784->regs;
  v3839[18] = v3838;
  struct StateT * v4818 = v3841(v3784);
  return v4818;
}

struct StateT * v7367(struct StateT * v7368) {
  int v7369 = v7368->timer;
  int v8503 = v7369 + 1;
  v7368->timer = v8503;
  int * v7371 = v7368->regs;
  int v7372 = v7371[11];
  int * v7373 = v7368->regs;
  int v8508 = (int)((unsigned int)v7372 >> 23);
  v7373[9] = v8508;
  struct StateT * v8501 = v7375(v7368);
  return v8501;
}

struct StateT * v333(struct StateT * v334) {
  int v335 = v334->timer;
  int v11030 = v335 + 1;
  v334->timer = v11030;
  int * v337 = v334->regs;
  int v338 = v337[2];
  int * v339 = v334->regs;
  int v340 = v339[21];
  int * v341 = v334->cache_keys;
  int v342 = v341[0];
  bool v11037 = v342 == ((int)((unsigned int)(v338 + 68) >> 2));
  int v386;
  if (v11037) {
    int * v343 = v334->cache_vals;
    v343[0] = v340;
    v386 = v340;
  } else {
    int * v346 = v334->cache_keys;
    int v347 = v346[1];
    bool v11042 = v347 == ((int)((unsigned int)(v338 + 68) >> 2));
    int v384;
    if (v11042) {
      int * v348 = v334->cache_keys;
      int * v349 = v334->cache_keys;
      int v350 = v349[0];
      v348[1] = v350;
      int * v352 = v334->cache_vals;
      int * v353 = v334->cache_vals;
      int v354 = v353[0];
      v352[1] = v354;
      int * v356 = v334->cache_keys;
      int v11050 = (int)((unsigned int)(v338 + 68) >> 2);
      v356[0] = v11050;
      int * v358 = v334->cache_vals;
      v358[0] = v340;
      int v360 = v334->timer;
      int v11053 = v360 + 1;
      v334->timer = v11053;
      v384 = v340;
    } else {
      int * v363 = v334->mem;
      int * v364 = v334->cache_keys;
      int v365 = v364[1];
      int * v366 = v334->cache_vals;
      int v367 = v366[1];
      v363[v365] = v367;
      int * v369 = v334->cache_keys;
      int * v370 = v334->cache_keys;
      int v371 = v370[0];
      v369[1] = v371;
      int * v373 = v334->cache_vals;
      int * v374 = v334->cache_vals;
      int v375 = v374[0];
      v373[1] = v375;
      int * v377 = v334->cache_keys;
      int v11066 = (int)((unsigned int)(v338 + 68) >> 2);
      v377[0] = v11066;
      int * v379 = v334->cache_vals;
      v379[0] = v340;
      int v381 = v334->timer;
      int v11069 = v381 + 100;
      v334->timer = v11069;
      v384 = v340;
    }
    v386 = v384;
  }
  struct StateT * v11028 = v387(v334);
  return v11028;
}

struct StateT * v7829(struct StateT * v7830) {
  int v7831 = v7830->timer;
  int v7969 = v7831 + 1;
  v7830->timer = v7969;
  int * v7833 = v7830->regs;
  int v7834 = v7833[8];
  int * v7835 = v7830->regs;
  int v7836 = v7835[9];
  int * v7837 = v7830->regs;
  int v7975 = v7834 | v7836;
  v7837[8] = v7975;
  struct StateT * v7967 = v7839(v7830);
  return v7967;
}

struct StateT * v7879(struct StateT * v7880) {
  int v7881 = v7880->timer;
  int v7915 = v7881 + 1;
  v7880->timer = v7915;
  int * v7883 = v7880->regs;
  int v7884 = v7883[30];
  int * v7885 = v7880->regs;
  int v7919 = v7884 + 1;
  v7885[30] = v7919;
  struct StateT * v7913 = v7887(v7880);
  return v7913;
}

struct StateT * v7007(struct StateT * v7008) {
  int v7009 = v7008->timer;
  int v8923 = v7009 + 1;
  v7008->timer = v8923;
  int * v7011 = v7008->regs;
  int v7012 = v7011[15];
  int * v7013 = v7008->regs;
  int v8927 = v7012 << 18;
  v7013[15] = v8927;
  struct StateT * v8921 = v7015(v7008);
  return v8921;
}

struct StateT * v7243(struct StateT * v7244) {
  int v7245 = v7244->timer;
  int v8650 = v7245 + 1;
  v7244->timer = v8650;
  int * v7247 = v7244->regs;
  int v7248 = v7247[16];
  int * v7249 = v7244->regs;
  int v8654 = v7248 << 7;
  v7249[16] = v8654;
  struct StateT * v8648 = v7251(v7244);
  return v8648;
}

struct StateT * v2907(struct StateT * v2908) {
  int v2909 = v2908->timer;
  int v5551 = v2909 + 1;
  v2908->timer = v5551;
  int * v2911 = v2908->regs;
  int v2912 = v2911[10];
  int * v2913 = v2908->regs;
  int v2914 = v2913[14];
  int * v2915 = v2908->cache_keys;
  int v2916 = v2915[0];
  bool v5558 = v2916 == ((int)((unsigned int)(v2912 + 12) >> 2));
  int v2960;
  if (v5558) {
    int * v2917 = v2908->cache_vals;
    v2917[0] = v2914;
    v2960 = v2914;
  } else {
    int * v2920 = v2908->cache_keys;
    int v2921 = v2920[1];
    bool v5563 = v2921 == ((int)((unsigned int)(v2912 + 12) >> 2));
    int v2958;
    if (v5563) {
      int * v2922 = v2908->cache_keys;
      int * v2923 = v2908->cache_keys;
      int v2924 = v2923[0];
      v2922[1] = v2924;
      int * v2926 = v2908->cache_vals;
      int * v2927 = v2908->cache_vals;
      int v2928 = v2927[0];
      v2926[1] = v2928;
      int * v2930 = v2908->cache_keys;
      int v5571 = (int)((unsigned int)(v2912 + 12) >> 2);
      v2930[0] = v5571;
      int * v2932 = v2908->cache_vals;
      v2932[0] = v2914;
      int v2934 = v2908->timer;
      int v5574 = v2934 + 1;
      v2908->timer = v5574;
      v2958 = v2914;
    } else {
      int * v2937 = v2908->mem;
      int * v2938 = v2908->cache_keys;
      int v2939 = v2938[1];
      int * v2940 = v2908->cache_vals;
      int v2941 = v2940[1];
      v2937[v2939] = v2941;
      int * v2943 = v2908->cache_keys;
      int * v2944 = v2908->cache_keys;
      int v2945 = v2944[0];
      v2943[1] = v2945;
      int * v2947 = v2908->cache_vals;
      int * v2948 = v2908->cache_vals;
      int v2949 = v2948[0];
      v2947[1] = v2949;
      int * v2951 = v2908->cache_keys;
      int v5587 = (int)((unsigned int)(v2912 + 12) >> 2);
      v2951[0] = v5587;
      int * v2953 = v2908->cache_vals;
      v2953[0] = v2914;
      int v2955 = v2908->timer;
      int v5590 = v2955 + 100;
      v2908->timer = v5590;
      v2958 = v2914;
    }
    v2960 = v2958;
  }
  struct StateT * v5549 = v2961(v2908);
  return v5549;
}

struct StateT * v3899(struct StateT * v3900) {
  int v3901 = v3900->timer;
  int v4724 = v3901 + 1;
  v3900->timer = v4724;
  int * v3903 = v3900->regs;
  int v3904 = v3903[2];
  int * v3905 = v3900->cache_keys;
  int v3906 = v3905[0];
  bool v4729 = v3906 == ((int)((unsigned int)(v3904 + 72) >> 2));
  int v3954;
  if (v4729) {
    int * v3907 = v3900->cache_vals;
    int v3908 = v3907[0];
    v3954 = v3908;
  } else {
    int * v3910 = v3900->cache_keys;
    int v3911 = v3910[1];
    bool v4734 = v3911 == ((int)((unsigned int)(v3904 + 72) >> 2));
    int v3952;
    if (v4734) {
      int * v3912 = v3900->cache_vals;
      int v3913 = v3912[1];
      int * v3914 = v3900->cache_keys;
      int * v3915 = v3900->cache_keys;
      int v3916 = v3915[0];
      v3914[1] = v3916;
      int * v3918 = v3900->cache_vals;
      int * v3919 = v3900->cache_vals;
      int v3920 = v3919[0];
      v3918[1] = v3920;
      int * v3922 = v3900->cache_keys;
      int v4743 = (int)((unsigned int)(v3904 + 72) >> 2);
      v3922[0] = v4743;
      int * v3924 = v3900->cache_vals;
      v3924[0] = v3913;
      int v3926 = v3900->timer;
      int v4746 = v3926 + 1;
      v3900->timer = v4746;
      v3952 = v3913;
    } else {
      int * v3929 = v3900->mem;
      int v4748 = (int)((unsigned int)(v3904 + 72) >> 2);
      int v3930 = v3929[v4748];
      int * v3931 = v3900->mem;
      int * v3932 = v3900->cache_keys;
      int v3933 = v3932[1];
      int * v3934 = v3900->cache_vals;
      int v3935 = v3934[1];
      v3931[v3933] = v3935;
      int * v3937 = v3900->cache_keys;
      int * v3938 = v3900->cache_keys;
      int v3939 = v3938[0];
      v3937[1] = v3939;
      int * v3941 = v3900->cache_vals;
      int * v3942 = v3900->cache_vals;
      int v3943 = v3942[0];
      v3941[1] = v3943;
      int * v3945 = v3900->cache_keys;
      v3945[0] = v4748;
      int * v3947 = v3900->cache_vals;
      v3947[0] = v3930;
      int v3949 = v3900->timer;
      int v4763 = v3949 + 100;
      v3900->timer = v4763;
      v3952 = v3930;
    }
    v3954 = v3952;
  }
  int * v3955 = v3900->regs;
  v3955[20] = v3954;
  struct StateT * v4722 = v3957(v3900);
  return v4722;
}

struct StateT * v949(struct StateT * v950) {
  int v951 = v950->timer;
  int v10512 = v951 + 1;
  v950->timer = v10512;
  int * v953 = v950->regs;
  int v954 = v953[12];
  int * v955 = v950->cache_keys;
  int v956 = v955[0];
  bool v10517 = v956 == ((int)((unsigned int)(v954 + 16) >> 2));
  int v1004;
  if (v10517) {
    int * v957 = v950->cache_vals;
    int v958 = v957[0];
    v1004 = v958;
  } else {
    int * v960 = v950->cache_keys;
    int v961 = v960[1];
    bool v10522 = v961 == ((int)((unsigned int)(v954 + 16) >> 2));
    int v1002;
    if (v10522) {
      int * v962 = v950->cache_vals;
      int v963 = v962[1];
      int * v964 = v950->cache_keys;
      int * v965 = v950->cache_keys;
      int v966 = v965[0];
      v964[1] = v966;
      int * v968 = v950->cache_vals;
      int * v969 = v950->cache_vals;
      int v970 = v969[0];
      v968[1] = v970;
      int * v972 = v950->cache_keys;
      int v10531 = (int)((unsigned int)(v954 + 16) >> 2);
      v972[0] = v10531;
      int * v974 = v950->cache_vals;
      v974[0] = v963;
      int v976 = v950->timer;
      int v10534 = v976 + 1;
      v950->timer = v10534;
      v1002 = v963;
    } else {
      int * v979 = v950->mem;
      int v10536 = (int)((unsigned int)(v954 + 16) >> 2);
      int v980 = v979[v10536];
      int * v981 = v950->mem;
      int * v982 = v950->cache_keys;
      int v983 = v982[1];
      int * v984 = v950->cache_vals;
      int v985 = v984[1];
      v981[v983] = v985;
      int * v987 = v950->cache_keys;
      int * v988 = v950->cache_keys;
      int v989 = v988[0];
      v987[1] = v989;
      int * v991 = v950->cache_vals;
      int * v992 = v950->cache_vals;
      int v993 = v992[0];
      v991[1] = v993;
      int * v995 = v950->cache_keys;
      v995[0] = v10536;
      int * v997 = v950->cache_vals;
      v997[0] = v980;
      int v999 = v950->timer;
      int v10551 = v999 + 100;
      v950->timer = v10551;
      v1002 = v980;
    }
    v1004 = v1002;
  }
  int * v1005 = v950->regs;
  v1005[17] = v1004;
  struct StateT * v10510 = v1007(v950);
  return v10510;
}

struct StateT * v1447(struct StateT * v1448) {
  int v1449 = v1448->timer;
  int v10122 = v1449 + 1;
  v1448->timer = v10122;
  int * v1451 = v1448->regs;
  int v1452 = v1451[14];
  int * v1453 = v1448->regs;
  int v10127 = v1452 + -718;
  v1453[19] = v10127;
  struct StateT * v10120 = v1455(v1448);
  return v10120;
}

struct StateT * v2463(struct StateT * v2464) {
  int v2465 = v2464->timer;
  int v5948 = v2465 + 1;
  v2464->timer = v5948;
  int * v2467 = v2464->regs;
  int v2468 = v2467[2];
  int * v2469 = v2464->cache_keys;
  int v2470 = v2469[0];
  bool v5953 = v2470 == ((int)((unsigned int)(v2468 + 32) >> 2));
  int v2518;
  if (v5953) {
    int * v2471 = v2464->cache_vals;
    int v2472 = v2471[0];
    v2518 = v2472;
  } else {
    int * v2474 = v2464->cache_keys;
    int v2475 = v2474[1];
    bool v5958 = v2475 == ((int)((unsigned int)(v2468 + 32) >> 2));
    int v2516;
    if (v5958) {
      int * v2476 = v2464->cache_vals;
      int v2477 = v2476[1];
      int * v2478 = v2464->cache_keys;
      int * v2479 = v2464->cache_keys;
      int v2480 = v2479[0];
      v2478[1] = v2480;
      int * v2482 = v2464->cache_vals;
      int * v2483 = v2464->cache_vals;
      int v2484 = v2483[0];
      v2482[1] = v2484;
      int * v2486 = v2464->cache_keys;
      int v5967 = (int)((unsigned int)(v2468 + 32) >> 2);
      v2486[0] = v5967;
      int * v2488 = v2464->cache_vals;
      v2488[0] = v2477;
      int v2490 = v2464->timer;
      int v5970 = v2490 + 1;
      v2464->timer = v5970;
      v2516 = v2477;
    } else {
      int * v2493 = v2464->mem;
      int v5972 = (int)((unsigned int)(v2468 + 32) >> 2);
      int v2494 = v2493[v5972];
      int * v2495 = v2464->mem;
      int * v2496 = v2464->cache_keys;
      int v2497 = v2496[1];
      int * v2498 = v2464->cache_vals;
      int v2499 = v2498[1];
      v2495[v2497] = v2499;
      int * v2501 = v2464->cache_keys;
      int * v2502 = v2464->cache_keys;
      int v2503 = v2502[0];
      v2501[1] = v2503;
      int * v2505 = v2464->cache_vals;
      int * v2506 = v2464->cache_vals;
      int v2507 = v2506[0];
      v2505[1] = v2507;
      int * v2509 = v2464->cache_keys;
      v2509[0] = v5972;
      int * v2511 = v2464->cache_vals;
      v2511[0] = v2494;
      int v2513 = v2464->timer;
      int v5987 = v2513 + 100;
      v2464->timer = v5987;
      v2516 = v2494;
    }
    v2518 = v2516;
  }
  int * v2519 = v2464->regs;
  v2519[30] = v2518;
  struct StateT * v5946 = v2521(v2464);
  return v5946;
}

struct StateT * v7435(struct StateT * v7436) {
  int v7437 = v7436->timer;
  int v8423 = v7437 + 1;
  v7436->timer = v8423;
  int * v7439 = v7436->regs;
  int v7440 = v7439[6];
  int * v7441 = v7436->regs;
  int v7442 = v7441[9];
  int * v7443 = v7436->regs;
  int v8429 = v7440 | v7442;
  v7443[6] = v8429;
  struct StateT * v8421 = v7445(v7436);
  return v8421;
}

struct StateT * v3841(struct StateT * v3842) {
  int v3843 = v3842->timer;
  int v4772 = v3843 + 1;
  v3842->timer = v4772;
  int * v3845 = v3842->regs;
  int v3846 = v3845[2];
  int * v3847 = v3842->cache_keys;
  int v3848 = v3847[0];
  bool v4777 = v3848 == ((int)((unsigned int)(v3846 + 76) >> 2));
  int v3896;
  if (v4777) {
    int * v3849 = v3842->cache_vals;
    int v3850 = v3849[0];
    v3896 = v3850;
  } else {
    int * v3852 = v3842->cache_keys;
    int v3853 = v3852[1];
    bool v4782 = v3853 == ((int)((unsigned int)(v3846 + 76) >> 2));
    int v3894;
    if (v4782) {
      int * v3854 = v3842->cache_vals;
      int v3855 = v3854[1];
      int * v3856 = v3842->cache_keys;
      int * v3857 = v3842->cache_keys;
      int v3858 = v3857[0];
      v3856[1] = v3858;
      int * v3860 = v3842->cache_vals;
      int * v3861 = v3842->cache_vals;
      int v3862 = v3861[0];
      v3860[1] = v3862;
      int * v3864 = v3842->cache_keys;
      int v4791 = (int)((unsigned int)(v3846 + 76) >> 2);
      v3864[0] = v4791;
      int * v3866 = v3842->cache_vals;
      v3866[0] = v3855;
      int v3868 = v3842->timer;
      int v4794 = v3868 + 1;
      v3842->timer = v4794;
      v3894 = v3855;
    } else {
      int * v3871 = v3842->mem;
      int v4796 = (int)((unsigned int)(v3846 + 76) >> 2);
      int v3872 = v3871[v4796];
      int * v3873 = v3842->mem;
      int * v3874 = v3842->cache_keys;
      int v3875 = v3874[1];
      int * v3876 = v3842->cache_vals;
      int v3877 = v3876[1];
      v3873[v3875] = v3877;
      int * v3879 = v3842->cache_keys;
      int * v3880 = v3842->cache_keys;
      int v3881 = v3880[0];
      v3879[1] = v3881;
      int * v3883 = v3842->cache_vals;
      int * v3884 = v3842->cache_vals;
      int v3885 = v3884[0];
      v3883[1] = v3885;
      int * v3887 = v3842->cache_keys;
      v3887[0] = v4796;
      int * v3889 = v3842->cache_vals;
      v3889[0] = v3872;
      int v3891 = v3842->timer;
      int v4811 = v3891 + 100;
      v3842->timer = v4811;
      v3894 = v3872;
    }
    v3896 = v3894;
  }
  int * v3897 = v3842->regs;
  v3897[19] = v3896;
  struct StateT * v4770 = v3899(v3842);
  return v4770;
}

struct StateT * v2735(struct StateT * v2736) {
  int v2737 = v2736->timer;
  int v5731 = v2737 + 1;
  v2736->timer = v5731;
  int * v2739 = v2736->regs;
  int v2740 = v2739[22];
  int * v2741 = v2736->regs;
  int v2742 = v2741[30];
  int * v2743 = v2736->regs;
  int v5737 = v2740 + v2742;
  v2743[30] = v5737;
  struct StateT * v5729 = v2745(v2736);
  return v5729;
}

struct StateT * v7491(struct StateT * v7492) {
  int v7493 = v7492->timer;
  int v8360 = v7493 + 1;
  v7492->timer = v8360;
  int * v7495 = v7492->regs;
  int v7496 = v7495[26];
  int * v7497 = v7492->regs;
  int v7498 = v7497[6];
  int * v7499 = v7492->regs;
  int v8366 = v7496 ^ v7498;
  v7499[26] = v8366;
  struct StateT * v8358 = v7501(v7492);
  return v8358;
}

struct StateT * v6657(struct StateT * v6658) {
  int v6659 = v6658->timer;
  int v9330 = v6659 + 1;
  v6658->timer = v9330;
  int * v6661 = v6658->regs;
  int v6662 = v6661[8];
  int * v6663 = v6658->regs;
  int v9335 = (int)((unsigned int)v6662 >> 23);
  v6663[20] = v9335;
  struct StateT * v9328 = v6665(v6658);
  return v9328;
}

struct StateT * v2705(struct StateT * v2706) {
  int v2707 = v2706->timer;
  int v5764 = v2707 + 1;
  v2706->timer = v5764;
  int * v2709 = v2706->regs;
  int v2710 = v2709[21];
  int * v2711 = v2706->regs;
  int v2712 = v2711[15];
  int * v2713 = v2706->regs;
  int v5770 = v2710 + v2712;
  v2713[15] = v5770;
  struct StateT * v5762 = v2715(v2706);
  return v5762;
}

struct StateT * v1123(struct StateT * v1124) {
  int v1125 = v1124->timer;
  int v10368 = v1125 + 1;
  v1124->timer = v10368;
  int * v1127 = v1124->regs;
  int v1128 = v1127[12];
  int * v1129 = v1124->cache_keys;
  int v1130 = v1129[0];
  bool v10373 = v1130 == ((int)((unsigned int)(v1128 + 28) >> 2));
  int v1178;
  if (v10373) {
    int * v1131 = v1124->cache_vals;
    int v1132 = v1131[0];
    v1178 = v1132;
  } else {
    int * v1134 = v1124->cache_keys;
    int v1135 = v1134[1];
    bool v10378 = v1135 == ((int)((unsigned int)(v1128 + 28) >> 2));
    int v1176;
    if (v10378) {
      int * v1136 = v1124->cache_vals;
      int v1137 = v1136[1];
      int * v1138 = v1124->cache_keys;
      int * v1139 = v1124->cache_keys;
      int v1140 = v1139[0];
      v1138[1] = v1140;
      int * v1142 = v1124->cache_vals;
      int * v1143 = v1124->cache_vals;
      int v1144 = v1143[0];
      v1142[1] = v1144;
      int * v1146 = v1124->cache_keys;
      int v10387 = (int)((unsigned int)(v1128 + 28) >> 2);
      v1146[0] = v10387;
      int * v1148 = v1124->cache_vals;
      v1148[0] = v1137;
      int v1150 = v1124->timer;
      int v10390 = v1150 + 1;
      v1124->timer = v10390;
      v1176 = v1137;
    } else {
      int * v1153 = v1124->mem;
      int v10392 = (int)((unsigned int)(v1128 + 28) >> 2);
      int v1154 = v1153[v10392];
      int * v1155 = v1124->mem;
      int * v1156 = v1124->cache_keys;
      int v1157 = v1156[1];
      int * v1158 = v1124->cache_vals;
      int v1159 = v1158[1];
      v1155[v1157] = v1159;
      int * v1161 = v1124->cache_keys;
      int * v1162 = v1124->cache_keys;
      int v1163 = v1162[0];
      v1161[1] = v1163;
      int * v1165 = v1124->cache_vals;
      int * v1166 = v1124->cache_vals;
      int v1167 = v1166[0];
      v1165[1] = v1167;
      int * v1169 = v1124->cache_keys;
      v1169[0] = v10392;
      int * v1171 = v1124->cache_vals;
      v1171[0] = v1154;
      int v1173 = v1124->timer;
      int v10407 = v1173 + 100;
      v1124->timer = v10407;
      v1176 = v1154;
    }
    v1178 = v1176;
  }
  int * v1179 = v1124->regs;
  v1179[1] = v1178;
  struct StateT * v10366 = v1181(v1124);
  return v10366;
}

struct StateT * v7461(struct StateT * v7462) {
  int v7463 = v7462->timer;
  int v8393 = v7463 + 1;
  v7462->timer = v8393;
  int * v7465 = v7462->regs;
  int v7466 = v7465[8];
  int * v7467 = v7462->regs;
  int v7468 = v7467[9];
  int * v7469 = v7462->regs;
  int v8399 = v7466 | v7468;
  v7469[8] = v8399;
  struct StateT * v8391 = v7471(v7462);
  return v8391;
}

struct StateT * v1419(struct StateT * v1420) {
  int v1421 = v1420->timer;
  int v10160 = v1421 + 1;
  v1420->timer = v10160;
  int * v1423 = v1420->regs;
  v1423[13] = 857759744;
  struct StateT * v10158 = v1425(v1420);
  return v10158;
}

struct StateT * v7297(struct StateT * v7298) {
  int v7299 = v7298->timer;
  int v8585 = v7299 + 1;
  v7298->timer = v8585;
  int * v7301 = v7298->regs;
  int v7302 = v7301[18];
  int * v7303 = v7298->regs;
  int v7304 = v7303[11];
  int * v7305 = v7298->regs;
  int v8592 = v7302 ^ v7304;
  v7305[5] = v8592;
  struct StateT * v8583 = v7307(v7298);
  return v8583;
}

struct StateT * v225(struct StateT * v226) {
  int v227 = v226->timer;
  int v11120 = v227 + 1;
  v226->timer = v11120;
  int * v229 = v226->regs;
  int v230 = v229[2];
  int * v231 = v226->regs;
  int v232 = v231[19];
  int * v233 = v226->cache_keys;
  int v234 = v233[0];
  bool v11127 = v234 == ((int)((unsigned int)(v230 + 76) >> 2));
  int v278;
  if (v11127) {
    int * v235 = v226->cache_vals;
    v235[0] = v232;
    v278 = v232;
  } else {
    int * v238 = v226->cache_keys;
    int v239 = v238[1];
    bool v11132 = v239 == ((int)((unsigned int)(v230 + 76) >> 2));
    int v276;
    if (v11132) {
      int * v240 = v226->cache_keys;
      int * v241 = v226->cache_keys;
      int v242 = v241[0];
      v240[1] = v242;
      int * v244 = v226->cache_vals;
      int * v245 = v226->cache_vals;
      int v246 = v245[0];
      v244[1] = v246;
      int * v248 = v226->cache_keys;
      int v11140 = (int)((unsigned int)(v230 + 76) >> 2);
      v248[0] = v11140;
      int * v250 = v226->cache_vals;
      v250[0] = v232;
      int v252 = v226->timer;
      int v11143 = v252 + 1;
      v226->timer = v11143;
      v276 = v232;
    } else {
      int * v255 = v226->mem;
      int * v256 = v226->cache_keys;
      int v257 = v256[1];
      int * v258 = v226->cache_vals;
      int v259 = v258[1];
      v255[v257] = v259;
      int * v261 = v226->cache_keys;
      int * v262 = v226->cache_keys;
      int v263 = v262[0];
      v261[1] = v263;
      int * v265 = v226->cache_vals;
      int * v266 = v226->cache_vals;
      int v267 = v266[0];
      v265[1] = v267;
      int * v269 = v226->cache_keys;
      int v11156 = (int)((unsigned int)(v230 + 76) >> 2);
      v269[0] = v11156;
      int * v271 = v226->cache_vals;
      v271[0] = v232;
      int v273 = v226->timer;
      int v11159 = v273 + 100;
      v226->timer = v11159;
      v276 = v232;
    }
    v278 = v276;
  }
  struct StateT * v11118 = v279(v226);
  return v11118;
}

struct StateT * v7611(struct StateT * v7612) {
  int v7613 = v7612->timer;
  int v8222 = v7613 + 1;
  v7612->timer = v8222;
  int * v7615 = v7612->regs;
  int v7616 = v7615[6];
  int * v7617 = v7612->regs;
  int v8226 = v7616 << 13;
  v7617[6] = v8226;
  struct StateT * v8220 = v7619(v7612);
  return v8220;
}

struct StateT * v1691(struct StateT * v1692) {
  int v1693 = v1692->timer;
  int v9873 = v1693 + 1;
  v1692->timer = v9873;
  int * v1695 = v1692->regs;
  int v1696 = v1695[2];
  int * v1697 = v1692->regs;
  int v1698 = v1697[24];
  int * v1699 = v1692->cache_keys;
  int v1700 = v1699[0];
  bool v9880 = v1700 == ((int)((unsigned int)(v1696 + 36) >> 2));
  int v1744;
  if (v9880) {
    int * v1701 = v1692->cache_vals;
    v1701[0] = v1698;
    v1744 = v1698;
  } else {
    int * v1704 = v1692->cache_keys;
    int v1705 = v1704[1];
    bool v9885 = v1705 == ((int)((unsigned int)(v1696 + 36) >> 2));
    int v1742;
    if (v9885) {
      int * v1706 = v1692->cache_keys;
      int * v1707 = v1692->cache_keys;
      int v1708 = v1707[0];
      v1706[1] = v1708;
      int * v1710 = v1692->cache_vals;
      int * v1711 = v1692->cache_vals;
      int v1712 = v1711[0];
      v1710[1] = v1712;
      int * v1714 = v1692->cache_keys;
      int v9893 = (int)((unsigned int)(v1696 + 36) >> 2);
      v1714[0] = v9893;
      int * v1716 = v1692->cache_vals;
      v1716[0] = v1698;
      int v1718 = v1692->timer;
      int v9896 = v1718 + 1;
      v1692->timer = v9896;
      v1742 = v1698;
    } else {
      int * v1721 = v1692->mem;
      int * v1722 = v1692->cache_keys;
      int v1723 = v1722[1];
      int * v1724 = v1692->cache_vals;
      int v1725 = v1724[1];
      v1721[v1723] = v1725;
      int * v1727 = v1692->cache_keys;
      int * v1728 = v1692->cache_keys;
      int v1729 = v1728[0];
      v1727[1] = v1729;
      int * v1731 = v1692->cache_vals;
      int * v1732 = v1692->cache_vals;
      int v1733 = v1732[0];
      v1731[1] = v1733;
      int * v1735 = v1692->cache_keys;
      int v9909 = (int)((unsigned int)(v1696 + 36) >> 2);
      v1735[0] = v9909;
      int * v1737 = v1692->cache_vals;
      v1737[0] = v1698;
      int v1739 = v1692->timer;
      int v9912 = v1739 + 100;
      v1692->timer = v9912;
      v1742 = v1698;
    }
    v1744 = v1742;
  }
  struct StateT * v9871 = v1745(v1692);
  return v9871;
}

struct StateT * v6507(struct StateT * v6508) {
  int v6509 = v6508->timer;
  int v9503 = v6509 + 1;
  v6508->timer = v9503;
  int * v6511 = v6508->regs;
  int v6512 = v6511[18];
  int * v6513 = v6508->regs;
  int v9507 = v6512 << 7;
  v6513[18] = v9507;
  struct StateT * v9501 = v6515(v6508);
  return v9501;
}

struct StateT * v717(struct StateT * v718) {
  int v719 = v718->timer;
  int v10704 = v719 + 1;
  v718->timer = v10704;
  int * v721 = v718->regs;
  int v722 = v721[12];
  int * v723 = v718->cache_keys;
  int v724 = v723[0];
  bool v10709 = v724 == ((int)((unsigned int)v722 >> 2));
  int v772;
  if (v10709) {
    int * v725 = v718->cache_vals;
    int v726 = v725[0];
    v772 = v726;
  } else {
    int * v728 = v718->cache_keys;
    int v729 = v728[1];
    bool v10714 = v729 == ((int)((unsigned int)v722 >> 2));
    int v770;
    if (v10714) {
      int * v730 = v718->cache_vals;
      int v731 = v730[1];
      int * v732 = v718->cache_keys;
      int * v733 = v718->cache_keys;
      int v734 = v733[0];
      v732[1] = v734;
      int * v736 = v718->cache_vals;
      int * v737 = v718->cache_vals;
      int v738 = v737[0];
      v736[1] = v738;
      int * v740 = v718->cache_keys;
      int v10723 = (int)((unsigned int)v722 >> 2);
      v740[0] = v10723;
      int * v742 = v718->cache_vals;
      v742[0] = v731;
      int v744 = v718->timer;
      int v10726 = v744 + 1;
      v718->timer = v10726;
      v770 = v731;
    } else {
      int * v747 = v718->mem;
      int v10728 = (int)((unsigned int)v722 >> 2);
      int v748 = v747[v10728];
      int * v749 = v718->mem;
      int * v750 = v718->cache_keys;
      int v751 = v750[1];
      int * v752 = v718->cache_vals;
      int v753 = v752[1];
      v749[v751] = v753;
      int * v755 = v718->cache_keys;
      int * v756 = v718->cache_keys;
      int v757 = v756[0];
      v755[1] = v757;
      int * v759 = v718->cache_vals;
      int * v760 = v718->cache_vals;
      int v761 = v760[0];
      v759[1] = v761;
      int * v763 = v718->cache_keys;
      v763[0] = v10728;
      int * v765 = v718->cache_vals;
      v765[0] = v748;
      int v767 = v718->timer;
      int v10743 = v767 + 100;
      v718->timer = v10743;
      v770 = v748;
    }
    v772 = v770;
  }
  int * v773 = v718->regs;
  v773[29] = v772;
  struct StateT * v10702 = v775(v718);
  return v10702;
}

struct StateT * v6919(struct StateT * v6920) {
  int v6921 = v6920->timer;
  int v9025 = v6921 + 1;
  v6920->timer = v9025;
  int * v6923 = v6920->regs;
  int v6924 = v6923[16];
  int * v6925 = v6920->regs;
  int v6926 = v6925[15];
  int * v6927 = v6920->regs;
  int v9032 = v6924 ^ v6926;
  v6927[9] = v9032;
  struct StateT * v9023 = v6929(v6920);
  return v9023;
}

struct StateT * v6717(struct StateT * v6718) {
  int v6719 = v6718->timer;
  int v9261 = v6719 + 1;
  v6718->timer = v9261;
  int * v6721 = v6718->regs;
  int v6722 = v6721[18];
  int * v6723 = v6718->regs;
  int v9265 = v6722 << 9;
  v6723[18] = v9265;
  struct StateT * v9259 = v6725(v6718);
  return v9259;
}

struct StateT * v775(struct StateT * v776) {
  int v777 = v776->timer;
  int v10656 = v777 + 1;
  v776->timer = v10656;
  int * v779 = v776->regs;
  int v780 = v779[12];
  int * v781 = v776->cache_keys;
  int v782 = v781[0];
  bool v10661 = v782 == ((int)((unsigned int)(v780 + 4) >> 2));
  int v830;
  if (v10661) {
    int * v783 = v776->cache_vals;
    int v784 = v783[0];
    v830 = v784;
  } else {
    int * v786 = v776->cache_keys;
    int v787 = v786[1];
    bool v10666 = v787 == ((int)((unsigned int)(v780 + 4) >> 2));
    int v828;
    if (v10666) {
      int * v788 = v776->cache_vals;
      int v789 = v788[1];
      int * v790 = v776->cache_keys;
      int * v791 = v776->cache_keys;
      int v792 = v791[0];
      v790[1] = v792;
      int * v794 = v776->cache_vals;
      int * v795 = v776->cache_vals;
      int v796 = v795[0];
      v794[1] = v796;
      int * v798 = v776->cache_keys;
      int v10675 = (int)((unsigned int)(v780 + 4) >> 2);
      v798[0] = v10675;
      int * v800 = v776->cache_vals;
      v800[0] = v789;
      int v802 = v776->timer;
      int v10678 = v802 + 1;
      v776->timer = v10678;
      v828 = v789;
    } else {
      int * v805 = v776->mem;
      int v10680 = (int)((unsigned int)(v780 + 4) >> 2);
      int v806 = v805[v10680];
      int * v807 = v776->mem;
      int * v808 = v776->cache_keys;
      int v809 = v808[1];
      int * v810 = v776->cache_vals;
      int v811 = v810[1];
      v807[v809] = v811;
      int * v813 = v776->cache_keys;
      int * v814 = v776->cache_keys;
      int v815 = v814[0];
      v813[1] = v815;
      int * v817 = v776->cache_vals;
      int * v818 = v776->cache_vals;
      int v819 = v818[0];
      v817[1] = v819;
      int * v821 = v776->cache_keys;
      v821[0] = v10680;
      int * v823 = v776->cache_vals;
      v823[0] = v806;
      int v825 = v776->timer;
      int v10695 = v825 + 100;
      v776->timer = v10695;
      v828 = v806;
    }
    v830 = v828;
  }
  int * v831 = v776->regs;
  v831[28] = v830;
  struct StateT * v10654 = v833(v776);
  return v10654;
}

struct StateT * v7103(struct StateT * v7104) {
  int v7105 = v7104->timer;
  int v8811 = v7105 + 1;
  v7104->timer = v8811;
  int * v7107 = v7104->regs;
  int v7108 = v7107[21];
  int * v7109 = v7104->regs;
  int v7110 = v7109[15];
  int * v7111 = v7104->regs;
  int v8817 = v7108 ^ v7110;
  v7111[21] = v8817;
  struct StateT * v8809 = v7113(v7104);
  return v8809;
}

struct StateT * v2395(struct StateT * v2396) {
  int v2397 = v2396->timer;
  int v6007 = v2397 + 1;
  v2396->timer = v6007;
  int * v2399 = v2396->regs;
  int v2400 = v2399[2];
  int * v2401 = v2396->cache_keys;
  int v2402 = v2401[0];
  bool v6012 = v2402 == ((int)((unsigned int)(v2400 + 28) >> 2));
  int v2450;
  if (v6012) {
    int * v2403 = v2396->cache_vals;
    int v2404 = v2403[0];
    v2450 = v2404;
  } else {
    int * v2406 = v2396->cache_keys;
    int v2407 = v2406[1];
    bool v6017 = v2407 == ((int)((unsigned int)(v2400 + 28) >> 2));
    int v2448;
    if (v6017) {
      int * v2408 = v2396->cache_vals;
      int v2409 = v2408[1];
      int * v2410 = v2396->cache_keys;
      int * v2411 = v2396->cache_keys;
      int v2412 = v2411[0];
      v2410[1] = v2412;
      int * v2414 = v2396->cache_vals;
      int * v2415 = v2396->cache_vals;
      int v2416 = v2415[0];
      v2414[1] = v2416;
      int * v2418 = v2396->cache_keys;
      int v6026 = (int)((unsigned int)(v2400 + 28) >> 2);
      v2418[0] = v6026;
      int * v2420 = v2396->cache_vals;
      v2420[0] = v2409;
      int v2422 = v2396->timer;
      int v6029 = v2422 + 1;
      v2396->timer = v6029;
      v2448 = v2409;
    } else {
      int * v2425 = v2396->mem;
      int v6031 = (int)((unsigned int)(v2400 + 28) >> 2);
      int v2426 = v2425[v6031];
      int * v2427 = v2396->mem;
      int * v2428 = v2396->cache_keys;
      int v2429 = v2428[1];
      int * v2430 = v2396->cache_vals;
      int v2431 = v2430[1];
      v2427[v2429] = v2431;
      int * v2433 = v2396->cache_keys;
      int * v2434 = v2396->cache_keys;
      int v2435 = v2434[0];
      v2433[1] = v2435;
      int * v2437 = v2396->cache_vals;
      int * v2438 = v2396->cache_vals;
      int v2439 = v2438[0];
      v2437[1] = v2439;
      int * v2441 = v2396->cache_keys;
      v2441[0] = v6031;
      int * v2443 = v2396->cache_vals;
      v2443[0] = v2426;
      int v2445 = v2396->timer;
      int v6046 = v2445 + 100;
      v2396->timer = v6046;
      v2448 = v2426;
    }
    v2450 = v2448;
  }
  int * v2451 = v2396->regs;
  v2451[30] = v2450;
  struct StateT * v6005 = v2453(v2396);
  return v6005;
}

struct StateT * v4015(struct StateT * v4016) {
  int v4017 = v4016->timer;
  int v4628 = v4017 + 1;
  v4016->timer = v4628;
  int * v4019 = v4016->regs;
  int v4020 = v4019[2];
  int * v4021 = v4016->cache_keys;
  int v4022 = v4021[0];
  bool v4633 = v4022 == ((int)((unsigned int)(v4020 + 64) >> 2));
  int v4070;
  if (v4633) {
    int * v4023 = v4016->cache_vals;
    int v4024 = v4023[0];
    v4070 = v4024;
  } else {
    int * v4026 = v4016->cache_keys;
    int v4027 = v4026[1];
    bool v4638 = v4027 == ((int)((unsigned int)(v4020 + 64) >> 2));
    int v4068;
    if (v4638) {
      int * v4028 = v4016->cache_vals;
      int v4029 = v4028[1];
      int * v4030 = v4016->cache_keys;
      int * v4031 = v4016->cache_keys;
      int v4032 = v4031[0];
      v4030[1] = v4032;
      int * v4034 = v4016->cache_vals;
      int * v4035 = v4016->cache_vals;
      int v4036 = v4035[0];
      v4034[1] = v4036;
      int * v4038 = v4016->cache_keys;
      int v4647 = (int)((unsigned int)(v4020 + 64) >> 2);
      v4038[0] = v4647;
      int * v4040 = v4016->cache_vals;
      v4040[0] = v4029;
      int v4042 = v4016->timer;
      int v4650 = v4042 + 1;
      v4016->timer = v4650;
      v4068 = v4029;
    } else {
      int * v4045 = v4016->mem;
      int v4652 = (int)((unsigned int)(v4020 + 64) >> 2);
      int v4046 = v4045[v4652];
      int * v4047 = v4016->mem;
      int * v4048 = v4016->cache_keys;
      int v4049 = v4048[1];
      int * v4050 = v4016->cache_vals;
      int v4051 = v4050[1];
      v4047[v4049] = v4051;
      int * v4053 = v4016->cache_keys;
      int * v4054 = v4016->cache_keys;
      int v4055 = v4054[0];
      v4053[1] = v4055;
      int * v4057 = v4016->cache_vals;
      int * v4058 = v4016->cache_vals;
      int v4059 = v4058[0];
      v4057[1] = v4059;
      int * v4061 = v4016->cache_keys;
      v4061[0] = v4652;
      int * v4063 = v4016->cache_vals;
      v4063[0] = v4046;
      int v4065 = v4016->timer;
      int v4667 = v4065 + 100;
      v4016->timer = v4667;
      v4068 = v4046;
    }
    v4070 = v4068;
  }
  int * v4071 = v4016->regs;
  v4071[22] = v4070;
  struct StateT * v4626 = v4073(v4016);
  return v4626;
}

struct StateT * v2961(struct StateT * v2962) {
  int v2963 = v2962->timer;
  int v5506 = v2963 + 1;
  v2962->timer = v5506;
  int * v2965 = v2962->regs;
  int v2966 = v2965[10];
  int * v2967 = v2962->regs;
  int v2968 = v2967[12];
  int * v2969 = v2962->cache_keys;
  int v2970 = v2969[0];
  bool v5513 = v2970 == ((int)((unsigned int)(v2966 + 16) >> 2));
  int v3014;
  if (v5513) {
    int * v2971 = v2962->cache_vals;
    v2971[0] = v2968;
    v3014 = v2968;
  } else {
    int * v2974 = v2962->cache_keys;
    int v2975 = v2974[1];
    bool v5518 = v2975 == ((int)((unsigned int)(v2966 + 16) >> 2));
    int v3012;
    if (v5518) {
      int * v2976 = v2962->cache_keys;
      int * v2977 = v2962->cache_keys;
      int v2978 = v2977[0];
      v2976[1] = v2978;
      int * v2980 = v2962->cache_vals;
      int * v2981 = v2962->cache_vals;
      int v2982 = v2981[0];
      v2980[1] = v2982;
      int * v2984 = v2962->cache_keys;
      int v5526 = (int)((unsigned int)(v2966 + 16) >> 2);
      v2984[0] = v5526;
      int * v2986 = v2962->cache_vals;
      v2986[0] = v2968;
      int v2988 = v2962->timer;
      int v5529 = v2988 + 1;
      v2962->timer = v5529;
      v3012 = v2968;
    } else {
      int * v2991 = v2962->mem;
      int * v2992 = v2962->cache_keys;
      int v2993 = v2992[1];
      int * v2994 = v2962->cache_vals;
      int v2995 = v2994[1];
      v2991[v2993] = v2995;
      int * v2997 = v2962->cache_keys;
      int * v2998 = v2962->cache_keys;
      int v2999 = v2998[0];
      v2997[1] = v2999;
      int * v3001 = v2962->cache_vals;
      int * v3002 = v2962->cache_vals;
      int v3003 = v3002[0];
      v3001[1] = v3003;
      int * v3005 = v2962->cache_keys;
      int v5542 = (int)((unsigned int)(v2966 + 16) >> 2);
      v3005[0] = v5542;
      int * v3007 = v2962->cache_vals;
      v3007[0] = v2968;
      int v3009 = v2962->timer;
      int v5545 = v3009 + 100;
      v2962->timer = v5545;
      v3012 = v2968;
    }
    v3014 = v3012;
  }
  struct StateT * v5504 = v3015(v2962);
  return v5504;
}

struct StateT * v6621(struct StateT * v6622) {
  int v6623 = v6622->timer;
  int v9370 = v6623 + 1;
  v6622->timer = v9370;
  int * v6625 = v6622->regs;
  int v6626 = v6625[14];
  int * v6627 = v6622->regs;
  int v6628 = v6627[22];
  int * v6629 = v6622->regs;
  int v9377 = v6626 + v6628;
  v6629[18] = v9377;
  struct StateT * v9368 = v6631(v6622);
  return v9368;
}

struct StateT * v2697(struct StateT * v2698) {
  int v2699 = v2698->timer;
  int v5775 = v2699 + 1;
  v2698->timer = v5775;
  int * v2701 = v2698->regs;
  int v2702 = v2701[30];
  int * v2703 = v2698->regs;
  int v5779 = v2702 + 1396;
  v2703[30] = v5779;
  struct StateT * v5773 = v2705(v2698);
  return v5773;
}

struct StateT * v7251(struct StateT * v7252) {
  int v7253 = v7252->timer;
  int v8639 = v7253 + 1;
  v7252->timer = v8639;
  int * v7255 = v7252->regs;
  int v7256 = v7255[16];
  int * v7257 = v7252->regs;
  int v7258 = v7257[5];
  int * v7259 = v7252->regs;
  int v8645 = v7256 | v7258;
  v7259[16] = v8645;
  struct StateT * v8637 = v7261(v7252);
  return v8637;
}

struct StateT * v6639(struct StateT * v6640) {
  int v6641 = v6640->timer;
  int v9351 = v6641 + 1;
  v6640->timer = v9351;
  int * v6643 = v6640->regs;
  int v6644 = v6643[15];
  int * v6645 = v6640->regs;
  int v9355 = v6644 << 9;
  v6645[15] = v9355;
  struct StateT * v9349 = v6647(v6640);
  return v9349;
}

struct StateT * v7077(struct StateT * v7078) {
  int v7079 = v7078->timer;
  int v8842 = v7079 + 1;
  v7078->timer = v8842;
  int * v7081 = v7078->regs;
  int v7082 = v7081[5];
  int * v7083 = v7078->regs;
  int v8847 = (int)((unsigned int)v7082 >> 14);
  v7083[6] = v8847;
  struct StateT * v8840 = v7085(v7078);
  return v8840;
}

struct StateT * v6765(struct StateT * v6766) {
  int v6767 = v6766->timer;
  int v9206 = v6767 + 1;
  v6766->timer = v9206;
  int * v6769 = v6766->regs;
  int v6770 = v6769[25];
  int * v6771 = v6766->regs;
  int v6772 = v6771[18];
  int * v6773 = v6766->regs;
  int v9212 = v6770 ^ v6772;
  v6773[25] = v9212;
  struct StateT * v9204 = v6775(v6766);
  return v9204;
}

struct StateT * v7577(struct StateT * v7578) {
  int v7579 = v7578->timer;
  int v8261 = v7579 + 1;
  v7578->timer = v8261;
  int * v7581 = v7578->regs;
  int v7582 = v7581[15];
  int * v7583 = v7578->regs;
  int v8266 = (int)((unsigned int)v7582 >> 19);
  v7583[9] = v8266;
  struct StateT * v8259 = v7585(v7578);
  return v8259;
}

struct StateT * v2033(struct StateT * v2034) {
  int v2035 = v2034->timer;
  int v6366 = v2035 + 1;
  v2034->timer = v6366;
  int * v2037 = v2034->regs;
  int v2038 = v2037[14];
  int * v2039 = v2034->regs;
  int v2040 = v2039[7];
  int * v2041 = v2034->regs;
  int v6372 = v2038 + v2040;
  v2041[14] = v6372;
  struct StateT * v6364 = v2043(v2034);
  return v6364;
}

struct StateT * v7629(struct StateT * v7630) {
  int v7631 = v7630->timer;
  int v8201 = v7631 + 1;
  v7630->timer = v8201;
  int * v7633 = v7630->regs;
  int v7634 = v7633[8];
  int * v7635 = v7630->regs;
  int v8206 = (int)((unsigned int)v7634 >> 19);
  v7635[9] = v8206;
  struct StateT * v8199 = v7637(v7630);
  return v8199;
}

struct StateT * v2185(struct StateT * v2186) {
  int v2187 = v2186->timer;
  int v6192 = v2187 + 1;
  v2186->timer = v6192;
  int * v2189 = v2186->regs;
  int v2190 = v2189[2];
  int * v2191 = v2186->cache_keys;
  int v2192 = v2191[0];
  bool v6197 = v2192 == ((int)((unsigned int)(v2190 + 16) >> 2));
  int v2240;
  if (v6197) {
    int * v2193 = v2186->cache_vals;
    int v2194 = v2193[0];
    v2240 = v2194;
  } else {
    int * v2196 = v2186->cache_keys;
    int v2197 = v2196[1];
    bool v6202 = v2197 == ((int)((unsigned int)(v2190 + 16) >> 2));
    int v2238;
    if (v6202) {
      int * v2198 = v2186->cache_vals;
      int v2199 = v2198[1];
      int * v2200 = v2186->cache_keys;
      int * v2201 = v2186->cache_keys;
      int v2202 = v2201[0];
      v2200[1] = v2202;
      int * v2204 = v2186->cache_vals;
      int * v2205 = v2186->cache_vals;
      int v2206 = v2205[0];
      v2204[1] = v2206;
      int * v2208 = v2186->cache_keys;
      int v6211 = (int)((unsigned int)(v2190 + 16) >> 2);
      v2208[0] = v6211;
      int * v2210 = v2186->cache_vals;
      v2210[0] = v2199;
      int v2212 = v2186->timer;
      int v6214 = v2212 + 1;
      v2186->timer = v6214;
      v2238 = v2199;
    } else {
      int * v2215 = v2186->mem;
      int v6216 = (int)((unsigned int)(v2190 + 16) >> 2);
      int v2216 = v2215[v6216];
      int * v2217 = v2186->mem;
      int * v2218 = v2186->cache_keys;
      int v2219 = v2218[1];
      int * v2220 = v2186->cache_vals;
      int v2221 = v2220[1];
      v2217[v2219] = v2221;
      int * v2223 = v2186->cache_keys;
      int * v2224 = v2186->cache_keys;
      int v2225 = v2224[0];
      v2223[1] = v2225;
      int * v2227 = v2186->cache_vals;
      int * v2228 = v2186->cache_vals;
      int v2229 = v2228[0];
      v2227[1] = v2229;
      int * v2231 = v2186->cache_keys;
      v2231[0] = v6216;
      int * v2233 = v2186->cache_vals;
      v2233[0] = v2216;
      int v2235 = v2186->timer;
      int v6231 = v2235 + 100;
      v2186->timer = v6231;
      v2238 = v2216;
    }
    v2240 = v2238;
  }
  int * v2241 = v2186->regs;
  v2241[7] = v2240;
  struct StateT * v6190 = v2243(v2186);
  return v6190;
}

struct StateT * v6591(struct StateT * v6592) {
  int v6593 = v6592->timer;
  int v9406 = v6593 + 1;
  v6592->timer = v9406;
  int * v6595 = v6592->regs;
  int v6596 = v6595[12];
  int * v6597 = v6592->regs;
  int v6598 = v6597[21];
  int * v6599 = v6592->regs;
  int v9413 = v6596 + v6598;
  v6599[15] = v9413;
  struct StateT * v9404 = v6601(v6592);
  return v9404;
}

struct StateT * v7143(struct StateT * v7144) {
  int v7145 = v7144->timer;
  int v8765 = v7145 + 1;
  v7144->timer = v8765;
  int * v7147 = v7144->regs;
  int v7148 = v7147[21];
  int * v7149 = v7144->regs;
  int v7150 = v7149[14];
  int * v7151 = v7144->regs;
  int v8772 = v7148 + v7150;
  v7151[15] = v8772;
  struct StateT * v8763 = v7153(v7144);
  return v8763;
}

struct StateT * v6673(struct StateT * v6674) {
  int v6675 = v6674->timer;
  int v9310 = v6675 + 1;
  v6674->timer = v9310;
  int * v6677 = v6674->regs;
  int v6678 = v6677[8];
  int * v6679 = v6674->regs;
  int v6680 = v6679[20];
  int * v6681 = v6674->regs;
  int v9316 = v6678 | v6680;
  v6681[8] = v9316;
  struct StateT * v9308 = v6683(v6674);
  return v9308;
}

struct StateT * v2007(struct StateT * v2008) {
  int v2009 = v2008->timer;
  int v6396 = v2009 + 1;
  v2008->timer = v6396;
  int * v2011 = v2008->regs;
  int v2012 = v2011[23];
  int * v2013 = v2008->regs;
  int v2014 = v2013[29];
  int * v2015 = v2008->regs;
  int v6402 = v2012 + v2014;
  v2015[29] = v6402;
  struct StateT * v6394 = v2017(v2008);
  return v6394;
}

struct StateT * v7471(struct StateT * v7472) {
  int v7473 = v7472->timer;
  int v8382 = v7473 + 1;
  v7472->timer = v8382;
  int * v7475 = v7472->regs;
  int v7476 = v7475[27];
  int * v7477 = v7472->regs;
  int v7478 = v7477[11];
  int * v7479 = v7472->regs;
  int v8388 = v7476 ^ v7478;
  v7479[27] = v8388;
  struct StateT * v8380 = v7481(v7472);
  return v8380;
}

struct StateT * v7859(struct StateT * v7860) {
  int v7861 = v7860->timer;
  int v7935 = v7861 + 1;
  v7860->timer = v7935;
  int * v7863 = v7860->regs;
  int v7864 = v7863[19];
  int * v7865 = v7860->regs;
  int v7866 = v7865[6];
  int * v7867 = v7860->regs;
  int v7941 = v7864 ^ v7866;
  v7867[19] = v7941;
  struct StateT * v7933 = v7869(v7860);
  return v7933;
}

struct StateT * v2689(struct StateT * v2690) {
  int v2691 = v2690->timer;
  int v5784 = v2691 + 1;
  v2690->timer = v5784;
  int * v2693 = v2690->regs;
  int v2694 = v2693[7];
  int * v2695 = v2690->regs;
  int v5788 = v2694 + -718;
  v2695[7] = v5788;
  struct StateT * v5782 = v2697(v2690);
  return v5782;
}

struct StateT * v3555(struct StateT * v3556) {
  int v3557 = v3556->timer;
  int v5012 = v3557 + 1;
  v3556->timer = v5012;
  int * v3559 = v3556->regs;
  int v3560 = v3559[10];
  int * v3561 = v3556->regs;
  int v3562 = v3561[30];
  int * v3563 = v3556->cache_keys;
  int v3564 = v3563[0];
  bool v5019 = v3564 == ((int)((unsigned int)(v3560 + 60) >> 2));
  int v3608;
  if (v5019) {
    int * v3565 = v3556->cache_vals;
    v3565[0] = v3562;
    v3608 = v3562;
  } else {
    int * v3568 = v3556->cache_keys;
    int v3569 = v3568[1];
    bool v5024 = v3569 == ((int)((unsigned int)(v3560 + 60) >> 2));
    int v3606;
    if (v5024) {
      int * v3570 = v3556->cache_keys;
      int * v3571 = v3556->cache_keys;
      int v3572 = v3571[0];
      v3570[1] = v3572;
      int * v3574 = v3556->cache_vals;
      int * v3575 = v3556->cache_vals;
      int v3576 = v3575[0];
      v3574[1] = v3576;
      int * v3578 = v3556->cache_keys;
      int v5032 = (int)((unsigned int)(v3560 + 60) >> 2);
      v3578[0] = v5032;
      int * v3580 = v3556->cache_vals;
      v3580[0] = v3562;
      int v3582 = v3556->timer;
      int v5035 = v3582 + 1;
      v3556->timer = v5035;
      v3606 = v3562;
    } else {
      int * v3585 = v3556->mem;
      int * v3586 = v3556->cache_keys;
      int v3587 = v3586[1];
      int * v3588 = v3556->cache_vals;
      int v3589 = v3588[1];
      v3585[v3587] = v3589;
      int * v3591 = v3556->cache_keys;
      int * v3592 = v3556->cache_keys;
      int v3593 = v3592[0];
      v3591[1] = v3593;
      int * v3595 = v3556->cache_vals;
      int * v3596 = v3556->cache_vals;
      int v3597 = v3596[0];
      v3595[1] = v3597;
      int * v3599 = v3556->cache_keys;
      int v5048 = (int)((unsigned int)(v3560 + 60) >> 2);
      v3599[0] = v5048;
      int * v3601 = v3556->cache_vals;
      v3601[0] = v3562;
      int v3603 = v3556->timer;
      int v5051 = v3603 + 100;
      v3556->timer = v5051;
      v3606 = v3562;
    }
    v3608 = v3606;
  }
  struct StateT * v5010 = v3609(v3556);
  return v5010;
}

struct StateT * v1939(struct StateT * v1940) {
  int v1941 = v1940->timer;
  int v9653 = v1941 + 1;
  v1940->timer = v9653;
  int * v1943 = v1940->regs;
  int v1944 = v1943[2];
  int * v1945 = v1940->regs;
  int v1946 = v1945[15];
  int * v1947 = v1940->cache_keys;
  int v1948 = v1947[0];
  bool v9660 = v1948 == ((int)((unsigned int)(v1944 + 24) >> 2));
  int v1992;
  if (v9660) {
    int * v1949 = v1940->cache_vals;
    v1949[0] = v1946;
    v1992 = v1946;
  } else {
    int * v1952 = v1940->cache_keys;
    int v1953 = v1952[1];
    bool v9665 = v1953 == ((int)((unsigned int)(v1944 + 24) >> 2));
    int v1990;
    if (v9665) {
      int * v1954 = v1940->cache_keys;
      int * v1955 = v1940->cache_keys;
      int v1956 = v1955[0];
      v1954[1] = v1956;
      int * v1958 = v1940->cache_vals;
      int * v1959 = v1940->cache_vals;
      int v1960 = v1959[0];
      v1958[1] = v1960;
      int * v1962 = v1940->cache_keys;
      int v9673 = (int)((unsigned int)(v1944 + 24) >> 2);
      v1962[0] = v9673;
      int * v1964 = v1940->cache_vals;
      v1964[0] = v1946;
      int v1966 = v1940->timer;
      int v9676 = v1966 + 1;
      v1940->timer = v9676;
      v1990 = v1946;
    } else {
      int * v1969 = v1940->mem;
      int * v1970 = v1940->cache_keys;
      int v1971 = v1970[1];
      int * v1972 = v1940->cache_vals;
      int v1973 = v1972[1];
      v1969[v1971] = v1973;
      int * v1975 = v1940->cache_keys;
      int * v1976 = v1940->cache_keys;
      int v1977 = v1976[0];
      v1975[1] = v1977;
      int * v1979 = v1940->cache_vals;
      int * v1980 = v1940->cache_vals;
      int v1981 = v1980[0];
      v1979[1] = v1981;
      int * v1983 = v1940->cache_keys;
      int v9689 = (int)((unsigned int)(v1944 + 24) >> 2);
      v1983[0] = v9689;
      int * v1985 = v1940->cache_vals;
      v1985[0] = v1946;
      int v1987 = v1940->timer;
      int v9692 = v1987 + 100;
      v1940->timer = v9692;
      v1990 = v1946;
    }
    v1992 = v1990;
  }
  struct StateT * v9651 = v1993(v1940);
  return v9651;
}

struct StateT * v7501(struct StateT * v7502) {
  int v7503 = v7502->timer;
  int v8349 = v7503 + 1;
  v7502->timer = v8349;
  int * v7505 = v7502->regs;
  int v7506 = v7505[24];
  int * v7507 = v7502->regs;
  int v7508 = v7507[8];
  int * v7509 = v7502->regs;
  int v8355 = v7506 ^ v7508;
  v7509[24] = v8355;
  struct StateT * v8347 = v7511(v7502);
  return v8347;
}

struct StateT * v6647(struct StateT * v6648) {
  int v6649 = v6648->timer;
  int v9340 = v6649 + 1;
  v6648->timer = v9340;
  int * v6651 = v6648->regs;
  int v6652 = v6651[15];
  int * v6653 = v6648->regs;
  int v6654 = v6653[20];
  int * v6655 = v6648->regs;
  int v9346 = v6652 | v6654;
  v6655[15] = v9346;
  struct StateT * v9338 = v6657(v6648);
  return v9338;
}

struct StateT * v6857(struct StateT * v6858) {
  int v6859 = v6858->timer;
  int v9098 = v6859 + 1;
  v6858->timer = v9098;
  int * v6861 = v6858->regs;
  int v6862 = v6861[8];
  int * v6863 = v6858->regs;
  int v6864 = v6863[20];
  int * v6865 = v6858->regs;
  int v9104 = v6862 | v6864;
  v6865[8] = v9104;
  struct StateT * v9096 = v6867(v6858);
  return v9096;
}

struct StateT * v6823(struct StateT * v6824) {
  int v6825 = v6824->timer;
  int v9139 = v6825 + 1;
  v6824->timer = v9139;
  int * v6827 = v6824->regs;
  int v6828 = v6827[15];
  int * v6829 = v6824->regs;
  int v9143 = v6828 << 13;
  v6829[15] = v9143;
  struct StateT * v9137 = v6831(v6824);
  return v9137;
}

struct StateT * v7751(struct StateT * v7752) {
  int v7753 = v7752->timer;
  int v8059 = v7753 + 1;
  v7752->timer = v8059;
  int * v7755 = v7752->regs;
  int v7756 = v7755[11];
  int * v7757 = v7752->regs;
  int v7758 = v7757[9];
  int * v7759 = v7752->regs;
  int v8065 = v7756 | v7758;
  v7759[11] = v8065;
  struct StateT * v8057 = v7761(v7752);
  return v8057;
}

struct StateT * v6417(struct StateT * v6418) {
  int v6419 = v6418->timer;
  int v9606 = v6419 + 1;
  v6418->timer = v9606;
  int * v6421 = v6418->regs;
  int v6422 = v6421[11];
  int * v6423 = v6418->regs;
  int v6424 = v6423[23];
  int * v6425 = v6418->regs;
  int v9613 = v6422 + v6424;
  v6425[20] = v9613;
  struct StateT * v9604 = v6427(v6418);
  return v9604;
}

struct StateT * v6489(struct StateT * v6490) {
  int v6491 = v6490->timer;
  int v9522 = v6491 + 1;
  v6490->timer = v9522;
  int * v6493 = v6490->regs;
  int v6494 = v6493[20];
  int * v6495 = v6490->regs;
  int v6496 = v6495[9];
  int * v6497 = v6490->regs;
  int v9528 = v6494 | v6496;
  v6497[9] = v9528;
  struct StateT * v9520 = v6499(v6490);
  return v9520;
}

struct StateT * v7123(struct StateT * v7124) {
  int v7125 = v7124->timer;
  int v8788 = v7125 + 1;
  v7124->timer = v8788;
  int * v7127 = v7124->regs;
  int v7128 = v7127[19];
  int * v7129 = v7124->regs;
  int v7130 = v7129[17];
  int * v7131 = v7124->regs;
  int v8794 = v7128 ^ v7130;
  v7131[19] = v8794;
  struct StateT * v8786 = v7133(v7124);
  return v8786;
}

struct StateT * v7559(struct StateT * v7560) {
  int v7561 = v7560->timer;
  int v8282 = v7561 + 1;
  v7560->timer = v8282;
  int * v7563 = v7560->regs;
  int v7564 = v7563[11];
  int * v7565 = v7560->regs;
  int v8286 = v7564 << 13;
  v7565[11] = v8286;
  struct StateT * v8280 = v7567(v7560);
  return v8280;
}

struct StateT * v6699(struct StateT * v6700) {
  int v6701 = v6700->timer;
  int v9280 = v6701 + 1;
  v6700->timer = v9280;
  int * v6703 = v6700->regs;
  int v6704 = v6703[9];
  int * v6705 = v6700->regs;
  int v6706 = v6705[20];
  int * v6707 = v6700->regs;
  int v9286 = v6704 | v6706;
  v6707[9] = v9286;
  struct StateT * v9278 = v6709(v6700);
  return v9278;
}

struct StateT * v3177(struct StateT * v3178) {
  int v3179 = v3178->timer;
  int v5326 = v3179 + 1;
  v3178->timer = v5326;
  int * v3181 = v3178->regs;
  int v3182 = v3181[10];
  int * v3183 = v3178->regs;
  int v3184 = v3183[26];
  int * v3185 = v3178->cache_keys;
  int v3186 = v3185[0];
  bool v5333 = v3186 == ((int)((unsigned int)(v3182 + 32) >> 2));
  int v3230;
  if (v5333) {
    int * v3187 = v3178->cache_vals;
    v3187[0] = v3184;
    v3230 = v3184;
  } else {
    int * v3190 = v3178->cache_keys;
    int v3191 = v3190[1];
    bool v5338 = v3191 == ((int)((unsigned int)(v3182 + 32) >> 2));
    int v3228;
    if (v5338) {
      int * v3192 = v3178->cache_keys;
      int * v3193 = v3178->cache_keys;
      int v3194 = v3193[0];
      v3192[1] = v3194;
      int * v3196 = v3178->cache_vals;
      int * v3197 = v3178->cache_vals;
      int v3198 = v3197[0];
      v3196[1] = v3198;
      int * v3200 = v3178->cache_keys;
      int v5346 = (int)((unsigned int)(v3182 + 32) >> 2);
      v3200[0] = v5346;
      int * v3202 = v3178->cache_vals;
      v3202[0] = v3184;
      int v3204 = v3178->timer;
      int v5349 = v3204 + 1;
      v3178->timer = v5349;
      v3228 = v3184;
    } else {
      int * v3207 = v3178->mem;
      int * v3208 = v3178->cache_keys;
      int v3209 = v3208[1];
      int * v3210 = v3178->cache_vals;
      int v3211 = v3210[1];
      v3207[v3209] = v3211;
      int * v3213 = v3178->cache_keys;
      int * v3214 = v3178->cache_keys;
      int v3215 = v3214[0];
      v3213[1] = v3215;
      int * v3217 = v3178->cache_vals;
      int * v3218 = v3178->cache_vals;
      int v3219 = v3218[0];
      v3217[1] = v3219;
      int * v3221 = v3178->cache_keys;
      int v5362 = (int)((unsigned int)(v3182 + 32) >> 2);
      v3221[0] = v5362;
      int * v3223 = v3178->cache_vals;
      v3223[0] = v3184;
      int v3225 = v3178->timer;
      int v5365 = v3225 + 100;
      v3178->timer = v5365;
      v3228 = v3184;
    }
    v3230 = v3228;
  }
  struct StateT * v5324 = v3231(v3178);
  return v5324;
}

struct StateT * v6883(struct StateT * v6884) {
  int v6885 = v6884->timer;
  int v9068 = v6885 + 1;
  v6884->timer = v9068;
  int * v6887 = v6884->regs;
  int v6888 = v6887[9];
  int * v6889 = v6884->regs;
  int v6890 = v6889[20];
  int * v6891 = v6884->regs;
  int v9074 = v6888 | v6890;
  v6891[20] = v9074;
  struct StateT * v9066 = v6893(v6884);
  return v9066;
}

struct StateT * v7375(struct StateT * v7376) {
  int v7377 = v7376->timer;
  int v8494 = v7377 + 1;
  v7376->timer = v8494;
  int * v7379 = v7376->regs;
  int v7380 = v7379[11];
  int * v7381 = v7376->regs;
  int v8498 = v7380 << 9;
  v7381[11] = v8498;
  struct StateT * v8492 = v7383(v7376);
  return v8492;
}

struct StateT * v4371(struct StateT * v4372) {
  int v4373 = v4372->timer;
  int v4376 = v4373 + 1;
  v4372->timer = v4376;
  return v4372;
}

struct StateT * v7261(struct StateT * v7262) {
  int v7263 = v7262->timer;
  int v8629 = v7263 + 1;
  v7262->timer = v8629;
  int * v7265 = v7262->regs;
  int v7266 = v7265[17];
  int * v7267 = v7262->regs;
  int v8634 = (int)((unsigned int)v7266 >> 25);
  v7267[5] = v8634;
  struct StateT * v8627 = v7269(v7262);
  return v8627;
}

struct StateT * v6831(struct StateT * v6832) {
  int v6833 = v6832->timer;
  int v9128 = v6833 + 1;
  v6832->timer = v9128;
  int * v6835 = v6832->regs;
  int v6836 = v6835[15];
  int * v6837 = v6832->regs;
  int v6838 = v6837[20];
  int * v6839 = v6832->regs;
  int v9134 = v6836 | v6838;
  v6839[15] = v9134;
  struct StateT * v9126 = v6841(v6832);
  return v9126;
}

struct StateT * v6775(struct StateT * v6776) {
  int v6777 = v6776->timer;
  int v9194 = v6777 + 1;
  v6776->timer = v9194;
  int * v6779 = v6776->regs;
  int v6780 = v6779[26];
  int * v6781 = v6776->regs;
  int v6782 = v6781[12];
  int * v6783 = v6776->regs;
  int v9201 = v6780 + v6782;
  v6783[15] = v9201;
  struct StateT * v9192 = v6785(v6776);
  return v9192;
}

struct StateT * v2043(struct StateT * v2044) {
  int v2045 = v2044->timer;
  int v6318 = v2045 + 1;
  v2044->timer = v6318;
  int * v2047 = v2044->regs;
  int v2048 = v2047[2];
  int * v2049 = v2044->cache_keys;
  int v2050 = v2049[0];
  bool v6323 = v2050 == ((int)((unsigned int)(v2048 + 8) >> 2));
  int v2098;
  if (v6323) {
    int * v2051 = v2044->cache_vals;
    int v2052 = v2051[0];
    v2098 = v2052;
  } else {
    int * v2054 = v2044->cache_keys;
    int v2055 = v2054[1];
    bool v6328 = v2055 == ((int)((unsigned int)(v2048 + 8) >> 2));
    int v2096;
    if (v6328) {
      int * v2056 = v2044->cache_vals;
      int v2057 = v2056[1];
      int * v2058 = v2044->cache_keys;
      int * v2059 = v2044->cache_keys;
      int v2060 = v2059[0];
      v2058[1] = v2060;
      int * v2062 = v2044->cache_vals;
      int * v2063 = v2044->cache_vals;
      int v2064 = v2063[0];
      v2062[1] = v2064;
      int * v2066 = v2044->cache_keys;
      int v6337 = (int)((unsigned int)(v2048 + 8) >> 2);
      v2066[0] = v6337;
      int * v2068 = v2044->cache_vals;
      v2068[0] = v2057;
      int v2070 = v2044->timer;
      int v6340 = v2070 + 1;
      v2044->timer = v6340;
      v2096 = v2057;
    } else {
      int * v2073 = v2044->mem;
      int v6342 = (int)((unsigned int)(v2048 + 8) >> 2);
      int v2074 = v2073[v6342];
      int * v2075 = v2044->mem;
      int * v2076 = v2044->cache_keys;
      int v2077 = v2076[1];
      int * v2078 = v2044->cache_vals;
      int v2079 = v2078[1];
      v2075[v2077] = v2079;
      int * v2081 = v2044->cache_keys;
      int * v2082 = v2044->cache_keys;
      int v2083 = v2082[0];
      v2081[1] = v2083;
      int * v2085 = v2044->cache_vals;
      int * v2086 = v2044->cache_vals;
      int v2087 = v2086[0];
      v2085[1] = v2087;
      int * v2089 = v2044->cache_keys;
      v2089[0] = v6342;
      int * v2091 = v2044->cache_vals;
      v2091[0] = v2074;
      int v2093 = v2044->timer;
      int v6357 = v2093 + 100;
      v2044->timer = v6357;
      v2096 = v2074;
    }
    v2098 = v2096;
  }
  int * v2099 = v2044->regs;
  v2099[6] = v2098;
  struct StateT * v6316 = v2101(v2044);
  return v6316;
}

struct StateT * v6581(struct StateT * v6582) {
  int v6583 = v6582->timer;
  int v9418 = v6583 + 1;
  v6582->timer = v9418;
  int * v6585 = v6582->regs;
  int v6586 = v6585[14];
  int * v6587 = v6582->regs;
  int v6588 = v6587[8];
  int * v6589 = v6582->regs;
  int v9424 = v6586 ^ v6588;
  v6589[14] = v9424;
  struct StateT * v9416 = v6591(v6582);
  return v9416;
}

struct StateT * v2379(struct StateT * v2380) {
  int v2381 = v2380->timer;
  int v6063 = v2381 + 1;
  v2380->timer = v6063;
  int * v2383 = v2380->regs;
  int v2384 = v2383[13];
  int * v2385 = v2380->regs;
  int v2386 = v2385[7];
  int * v2387 = v2380->regs;
  int v6069 = v2384 + v2386;
  v2387[13] = v6069;
  struct StateT * v6061 = v2389(v2380);
  return v6061;
}

struct StateT * v1297(struct StateT * v1298) {
  int v1299 = v1298->timer;
  int v10224 = v1299 + 1;
  v1298->timer = v10224;
  int * v1301 = v1298->regs;
  int v1302 = v1301[11];
  int * v1303 = v1298->cache_keys;
  int v1304 = v1303[0];
  bool v10229 = v1304 == ((int)((unsigned int)(v1302 + 8) >> 2));
  int v1352;
  if (v10229) {
    int * v1305 = v1298->cache_vals;
    int v1306 = v1305[0];
    v1352 = v1306;
  } else {
    int * v1308 = v1298->cache_keys;
    int v1309 = v1308[1];
    bool v10234 = v1309 == ((int)((unsigned int)(v1302 + 8) >> 2));
    int v1350;
    if (v10234) {
      int * v1310 = v1298->cache_vals;
      int v1311 = v1310[1];
      int * v1312 = v1298->cache_keys;
      int * v1313 = v1298->cache_keys;
      int v1314 = v1313[0];
      v1312[1] = v1314;
      int * v1316 = v1298->cache_vals;
      int * v1317 = v1298->cache_vals;
      int v1318 = v1317[0];
      v1316[1] = v1318;
      int * v1320 = v1298->cache_keys;
      int v10243 = (int)((unsigned int)(v1302 + 8) >> 2);
      v1320[0] = v10243;
      int * v1322 = v1298->cache_vals;
      v1322[0] = v1311;
      int v1324 = v1298->timer;
      int v10246 = v1324 + 1;
      v1298->timer = v10246;
      v1350 = v1311;
    } else {
      int * v1327 = v1298->mem;
      int v10248 = (int)((unsigned int)(v1302 + 8) >> 2);
      int v1328 = v1327[v10248];
      int * v1329 = v1298->mem;
      int * v1330 = v1298->cache_keys;
      int v1331 = v1330[1];
      int * v1332 = v1298->cache_vals;
      int v1333 = v1332[1];
      v1329[v1331] = v1333;
      int * v1335 = v1298->cache_keys;
      int * v1336 = v1298->cache_keys;
      int v1337 = v1336[0];
      v1335[1] = v1337;
      int * v1339 = v1298->cache_vals;
      int * v1340 = v1298->cache_vals;
      int v1341 = v1340[0];
      v1339[1] = v1341;
      int * v1343 = v1298->cache_keys;
      v1343[0] = v10248;
      int * v1345 = v1298->cache_vals;
      v1345[0] = v1328;
      int v1347 = v1298->timer;
      int v10263 = v1347 + 100;
      v1298->timer = v10263;
      v1350 = v1328;
    }
    v1352 = v1350;
  }
  int * v1353 = v1298->regs;
  v1353[26] = v1352;
  struct StateT * v10222 = v1355(v1298);
  return v10222;
}

struct StateT * v7041(struct StateT * v7042) {
  int v7043 = v7042->timer;
  int v8882 = v7043 + 1;
  v7042->timer = v8882;
  int * v7045 = v7042->regs;
  int v7046 = v7045[16];
  int * v7047 = v7042->regs;
  int v7048 = v7047[6];
  int * v7049 = v7042->regs;
  int v8888 = v7046 | v7048;
  v7049[16] = v8888;
  struct StateT * v8880 = v7051(v7042);
  return v8880;
}

struct StateT * v6949(struct StateT * v6950) {
  int v6951 = v6950->timer;
  int v8990 = v6951 + 1;
  v6950->timer = v8990;
  int * v6953 = v6950->regs;
  int v6954 = v6953[17];
  int * v6955 = v6950->regs;
  int v6956 = v6955[6];
  int * v6957 = v6950->regs;
  int v8997 = v6954 ^ v6956;
  v6957[8] = v8997;
  struct StateT * v8988 = v6959(v6950);
  return v8988;
}

struct StateT * v6909(struct StateT * v6910) {
  int v6911 = v6910->timer;
  int v9037 = v6911 + 1;
  v6910->timer = v9037;
  int * v6913 = v6910->regs;
  int v6914 = v6913[18];
  int * v6915 = v6910->regs;
  int v6916 = v6915[9];
  int * v6917 = v6910->regs;
  int v9044 = v6914 | v6916;
  v6917[6] = v9044;
  struct StateT * v9035 = v6919(v6910);
  return v9035;
}

struct StateT * v7761(struct StateT * v7762) {
  int v7763 = v7762->timer;
  int v8049 = v7763 + 1;
  v7762->timer = v8049;
  int * v7765 = v7762->regs;
  int v7766 = v7765[15];
  int * v7767 = v7762->regs;
  int v8054 = (int)((unsigned int)v7766 >> 14);
  v7767[9] = v8054;
  struct StateT * v8047 = v7769(v7762);
  return v8047;
}

struct StateT * v833(struct StateT * v834) {
  int v835 = v834->timer;
  int v10608 = v835 + 1;
  v834->timer = v10608;
  int * v837 = v834->regs;
  int v838 = v837[12];
  int * v839 = v834->cache_keys;
  int v840 = v839[0];
  bool v10613 = v840 == ((int)((unsigned int)(v838 + 8) >> 2));
  int v888;
  if (v10613) {
    int * v841 = v834->cache_vals;
    int v842 = v841[0];
    v888 = v842;
  } else {
    int * v844 = v834->cache_keys;
    int v845 = v844[1];
    bool v10618 = v845 == ((int)((unsigned int)(v838 + 8) >> 2));
    int v886;
    if (v10618) {
      int * v846 = v834->cache_vals;
      int v847 = v846[1];
      int * v848 = v834->cache_keys;
      int * v849 = v834->cache_keys;
      int v850 = v849[0];
      v848[1] = v850;
      int * v852 = v834->cache_vals;
      int * v853 = v834->cache_vals;
      int v854 = v853[0];
      v852[1] = v854;
      int * v856 = v834->cache_keys;
      int v10627 = (int)((unsigned int)(v838 + 8) >> 2);
      v856[0] = v10627;
      int * v858 = v834->cache_vals;
      v858[0] = v847;
      int v860 = v834->timer;
      int v10630 = v860 + 1;
      v834->timer = v10630;
      v886 = v847;
    } else {
      int * v863 = v834->mem;
      int v10632 = (int)((unsigned int)(v838 + 8) >> 2);
      int v864 = v863[v10632];
      int * v865 = v834->mem;
      int * v866 = v834->cache_keys;
      int v867 = v866[1];
      int * v868 = v834->cache_vals;
      int v869 = v868[1];
      v865[v867] = v869;
      int * v871 = v834->cache_keys;
      int * v872 = v834->cache_keys;
      int v873 = v872[0];
      v871[1] = v873;
      int * v875 = v834->cache_vals;
      int * v876 = v834->cache_vals;
      int v877 = v876[0];
      v875[1] = v877;
      int * v879 = v834->cache_keys;
      v879[0] = v10632;
      int * v881 = v834->cache_vals;
      v881[0] = v864;
      int v883 = v834->timer;
      int v10647 = v883 + 100;
      v834->timer = v10647;
      v886 = v864;
    }
    v888 = v886;
  }
  int * v889 = v834->regs;
  v889[7] = v888;
  struct StateT * v10606 = v891(v834);
  return v10606;
}

struct StateT * v7067(struct StateT * v7068) {
  int v7069 = v7068->timer;
  int v8852 = v7069 + 1;
  v7068->timer = v8852;
  int * v7071 = v7068->regs;
  int v7072 = v7071[17];
  int * v7073 = v7068->regs;
  int v7074 = v7073[6];
  int * v7075 = v7068->regs;
  int v8858 = v7072 | v7074;
  v7075[17] = v8858;
  struct StateT * v8850 = v7077(v7068);
  return v8850;
}

struct StateT * v1745(struct StateT * v1746) {
  int v1747 = v1746->timer;
  int v9828 = v1747 + 1;
  v1746->timer = v9828;
  int * v1749 = v1746->regs;
  int v1750 = v1749[2];
  int * v1751 = v1746->regs;
  int v1752 = v1751[16];
  int * v1753 = v1746->cache_keys;
  int v1754 = v1753[0];
  bool v9835 = v1754 == ((int)((unsigned int)(v1750 + 32) >> 2));
  int v1798;
  if (v9835) {
    int * v1755 = v1746->cache_vals;
    v1755[0] = v1752;
    v1798 = v1752;
  } else {
    int * v1758 = v1746->cache_keys;
    int v1759 = v1758[1];
    bool v9840 = v1759 == ((int)((unsigned int)(v1750 + 32) >> 2));
    int v1796;
    if (v9840) {
      int * v1760 = v1746->cache_keys;
      int * v1761 = v1746->cache_keys;
      int v1762 = v1761[0];
      v1760[1] = v1762;
      int * v1764 = v1746->cache_vals;
      int * v1765 = v1746->cache_vals;
      int v1766 = v1765[0];
      v1764[1] = v1766;
      int * v1768 = v1746->cache_keys;
      int v9848 = (int)((unsigned int)(v1750 + 32) >> 2);
      v1768[0] = v9848;
      int * v1770 = v1746->cache_vals;
      v1770[0] = v1752;
      int v1772 = v1746->timer;
      int v9851 = v1772 + 1;
      v1746->timer = v9851;
      v1796 = v1752;
    } else {
      int * v1775 = v1746->mem;
      int * v1776 = v1746->cache_keys;
      int v1777 = v1776[1];
      int * v1778 = v1746->cache_vals;
      int v1779 = v1778[1];
      v1775[v1777] = v1779;
      int * v1781 = v1746->cache_keys;
      int * v1782 = v1746->cache_keys;
      int v1783 = v1782[0];
      v1781[1] = v1783;
      int * v1785 = v1746->cache_vals;
      int * v1786 = v1746->cache_vals;
      int v1787 = v1786[0];
      v1785[1] = v1787;
      int * v1789 = v1746->cache_keys;
      int v9864 = (int)((unsigned int)(v1750 + 32) >> 2);
      v1789[0] = v9864;
      int * v1791 = v1746->cache_vals;
      v1791[0] = v1752;
      int v1793 = v1746->timer;
      int v9867 = v1793 + 100;
      v1746->timer = v9867;
      v1796 = v1752;
    }
    v1798 = v1796;
  }
  struct StateT * v9826 = v1799(v1746);
  return v9826;
}

struct StateT * v549(struct StateT * v550) {
  int v551 = v550->timer;
  int v10850 = v551 + 1;
  v550->timer = v10850;
  int * v553 = v550->regs;
  int v554 = v553[2];
  int * v555 = v550->regs;
  int v556 = v555[25];
  int * v557 = v550->cache_keys;
  int v558 = v557[0];
  bool v10857 = v558 == ((int)((unsigned int)(v554 + 52) >> 2));
  int v602;
  if (v10857) {
    int * v559 = v550->cache_vals;
    v559[0] = v556;
    v602 = v556;
  } else {
    int * v562 = v550->cache_keys;
    int v563 = v562[1];
    bool v10862 = v563 == ((int)((unsigned int)(v554 + 52) >> 2));
    int v600;
    if (v10862) {
      int * v564 = v550->cache_keys;
      int * v565 = v550->cache_keys;
      int v566 = v565[0];
      v564[1] = v566;
      int * v568 = v550->cache_vals;
      int * v569 = v550->cache_vals;
      int v570 = v569[0];
      v568[1] = v570;
      int * v572 = v550->cache_keys;
      int v10870 = (int)((unsigned int)(v554 + 52) >> 2);
      v572[0] = v10870;
      int * v574 = v550->cache_vals;
      v574[0] = v556;
      int v576 = v550->timer;
      int v10873 = v576 + 1;
      v550->timer = v10873;
      v600 = v556;
    } else {
      int * v579 = v550->mem;
      int * v580 = v550->cache_keys;
      int v581 = v580[1];
      int * v582 = v550->cache_vals;
      int v583 = v582[1];
      v579[v581] = v583;
      int * v585 = v550->cache_keys;
      int * v586 = v550->cache_keys;
      int v587 = v586[0];
      v585[1] = v587;
      int * v589 = v550->cache_vals;
      int * v590 = v550->cache_vals;
      int v591 = v590[0];
      v589[1] = v591;
      int * v593 = v550->cache_keys;
      int v10886 = (int)((unsigned int)(v554 + 52) >> 2);
      v593[0] = v10886;
      int * v595 = v550->cache_vals;
      v595[0] = v556;
      int v597 = v550->timer;
      int v10889 = v597 + 100;
      v550->timer = v10889;
      v600 = v556;
    }
    v602 = v600;
  }
  struct StateT * v10848 = v603(v550);
  return v10848;
}

struct StateT * v7317(struct StateT * v7318) {
  int v7319 = v7318->timer;
  int v8561 = v7319 + 1;
  v7318->timer = v8561;
  int * v7321 = v7318->regs;
  int v7322 = v7321[9];
  int * v7323 = v7318->regs;
  int v7324 = v7323[6];
  int * v7325 = v7318->regs;
  int v8568 = v7322 ^ v7324;
  v7325[16] = v8568;
  struct StateT * v8559 = v7327(v7318);
  return v8559;
}

struct StateT * v6427(struct StateT * v6428) {
  int v6429 = v6428->timer;
  int v9594 = v6429 + 1;
  v6428->timer = v9594;
  int * v6431 = v6428->regs;
  int v6432 = v6431[19];
  int * v6433 = v6428->regs;
  int v6434 = v6433[5];
  int * v6435 = v6428->regs;
  int v9601 = v6432 + v6434;
  v6435[18] = v9601;
  struct StateT * v9592 = v6437(v6428);
  return v9592;
}

struct StateT * v387(struct StateT * v388) {
  int v389 = v388->timer;
  int v10985 = v389 + 1;
  v388->timer = v10985;
  int * v391 = v388->regs;
  int v392 = v391[2];
  int * v393 = v388->regs;
  int v394 = v393[22];
  int * v395 = v388->cache_keys;
  int v396 = v395[0];
  bool v10992 = v396 == ((int)((unsigned int)(v392 + 64) >> 2));
  int v440;
  if (v10992) {
    int * v397 = v388->cache_vals;
    v397[0] = v394;
    v440 = v394;
  } else {
    int * v400 = v388->cache_keys;
    int v401 = v400[1];
    bool v10997 = v401 == ((int)((unsigned int)(v392 + 64) >> 2));
    int v438;
    if (v10997) {
      int * v402 = v388->cache_keys;
      int * v403 = v388->cache_keys;
      int v404 = v403[0];
      v402[1] = v404;
      int * v406 = v388->cache_vals;
      int * v407 = v388->cache_vals;
      int v408 = v407[0];
      v406[1] = v408;
      int * v410 = v388->cache_keys;
      int v11005 = (int)((unsigned int)(v392 + 64) >> 2);
      v410[0] = v11005;
      int * v412 = v388->cache_vals;
      v412[0] = v394;
      int v414 = v388->timer;
      int v11008 = v414 + 1;
      v388->timer = v11008;
      v438 = v394;
    } else {
      int * v417 = v388->mem;
      int * v418 = v388->cache_keys;
      int v419 = v418[1];
      int * v420 = v388->cache_vals;
      int v421 = v420[1];
      v417[v419] = v421;
      int * v423 = v388->cache_keys;
      int * v424 = v388->cache_keys;
      int v425 = v424[0];
      v423[1] = v425;
      int * v427 = v388->cache_vals;
      int * v428 = v388->cache_vals;
      int v429 = v428[0];
      v427[1] = v429;
      int * v431 = v388->cache_keys;
      int v11021 = (int)((unsigned int)(v392 + 64) >> 2);
      v431[0] = v11021;
      int * v433 = v388->cache_vals;
      v433[0] = v394;
      int v435 = v388->timer;
      int v11024 = v435 + 100;
      v388->timer = v11024;
      v438 = v394;
    }
    v440 = v438;
  }
  struct StateT * v10983 = v441(v388);
  return v10983;
}

struct StateT * v1461(struct StateT * v1462) {
  int v1463 = v1462->timer;
  int v10105 = v1463 + 1;
  v1462->timer = v10105;
  int * v1465 = v1462->regs;
  int v1466 = v1465[22];
  int * v1467 = v1462->regs;
  int v10109 = v1466 + 1396;
  v1467[22] = v10109;
  struct StateT * v10103 = v1469(v1462);
  return v10103;
}

struct StateT * v171(struct StateT * v172) {
  int v173 = v172->timer;
  int v11165 = v173 + 1;
  v172->timer = v11165;
  int * v175 = v172->regs;
  int v176 = v175[2];
  int * v177 = v172->regs;
  int v178 = v177[18];
  int * v179 = v172->cache_keys;
  int v180 = v179[0];
  bool v11172 = v180 == ((int)((unsigned int)(v176 + 80) >> 2));
  int v224;
  if (v11172) {
    int * v181 = v172->cache_vals;
    v181[0] = v178;
    v224 = v178;
  } else {
    int * v184 = v172->cache_keys;
    int v185 = v184[1];
    bool v11177 = v185 == ((int)((unsigned int)(v176 + 80) >> 2));
    int v222;
    if (v11177) {
      int * v186 = v172->cache_keys;
      int * v187 = v172->cache_keys;
      int v188 = v187[0];
      v186[1] = v188;
      int * v190 = v172->cache_vals;
      int * v191 = v172->cache_vals;
      int v192 = v191[0];
      v190[1] = v192;
      int * v194 = v172->cache_keys;
      int v11185 = (int)((unsigned int)(v176 + 80) >> 2);
      v194[0] = v11185;
      int * v196 = v172->cache_vals;
      v196[0] = v178;
      int v198 = v172->timer;
      int v11188 = v198 + 1;
      v172->timer = v11188;
      v222 = v178;
    } else {
      int * v201 = v172->mem;
      int * v202 = v172->cache_keys;
      int v203 = v202[1];
      int * v204 = v172->cache_vals;
      int v205 = v204[1];
      v201[v203] = v205;
      int * v207 = v172->cache_keys;
      int * v208 = v172->cache_keys;
      int v209 = v208[0];
      v207[1] = v209;
      int * v211 = v172->cache_vals;
      int * v212 = v172->cache_vals;
      int v213 = v212[0];
      v211[1] = v213;
      int * v215 = v172->cache_keys;
      int v11201 = (int)((unsigned int)(v176 + 80) >> 2);
      v215[0] = v11201;
      int * v217 = v172->cache_vals;
      v217[0] = v178;
      int v219 = v172->timer;
      int v11204 = v219 + 100;
      v172->timer = v11204;
      v222 = v178;
    }
    v224 = v222;
  }
  struct StateT * v11163 = v225(v172);
  return v11163;
}

struct StateT * v6551(struct StateT * v6552) {
  int v6553 = v6552->timer;
  int v9451 = v6553 + 1;
  v6552->timer = v9451;
  int * v6555 = v6552->regs;
  int v6556 = v6555[12];
  int * v6557 = v6552->regs;
  int v6558 = v6557[15];
  int * v6559 = v6552->regs;
  int v9457 = v6556 ^ v6558;
  v6559[12] = v9457;
  struct StateT * v9449 = v6561(v6552);
  return v9449;
}

struct StateT * v7183(struct StateT * v7184) {
  int v7185 = v7184->timer;
  int v8719 = v7185 + 1;
  v7184->timer = v8719;
  int * v7187 = v7184->regs;
  int v7188 = v7187[15];
  int * v7189 = v7184->regs;
  int v8724 = (int)((unsigned int)v7188 >> 25);
  v7189[5] = v8724;
  struct StateT * v8717 = v7191(v7184);
  return v8717;
}

struct StateT * v2017(struct StateT * v2018) {
  int v2019 = v2018->timer;
  int v6385 = v2019 + 1;
  v2018->timer = v6385;
  int * v2021 = v2018->regs;
  int v2022 = v2021[27];
  int * v2023 = v2018->regs;
  int v2024 = v2023[28];
  int * v2025 = v2018->regs;
  int v6391 = v2022 + v2024;
  v2025[28] = v6391;
  struct StateT * v6383 = v2027(v2018);
  return v6383;
}

struct StateT * v2725(struct StateT * v2726) {
  int v2727 = v2726->timer;
  int v5742 = v2727 + 1;
  v2726->timer = v5742;
  int * v2729 = v2726->regs;
  int v2730 = v2729[19];
  int * v2731 = v2726->regs;
  int v2732 = v2731[7];
  int * v2733 = v2726->regs;
  int v5748 = v2730 + v2732;
  v2733[7] = v5748;
  struct StateT * v5740 = v2735(v2726);
  return v5740;
}

struct StateT * v3501(struct StateT * v3502) {
  int v3503 = v3502->timer;
  int v5057 = v3503 + 1;
  v3502->timer = v5057;
  int * v3505 = v3502->regs;
  int v3506 = v3505[10];
  int * v3507 = v3502->regs;
  int v3508 = v3507[1];
  int * v3509 = v3502->cache_keys;
  int v3510 = v3509[0];
  bool v5064 = v3510 == ((int)((unsigned int)(v3506 + 56) >> 2));
  int v3554;
  if (v5064) {
    int * v3511 = v3502->cache_vals;
    v3511[0] = v3508;
    v3554 = v3508;
  } else {
    int * v3514 = v3502->cache_keys;
    int v3515 = v3514[1];
    bool v5068 = v3515 == ((int)((unsigned int)(v3506 + 56) >> 2));
    int v3552;
    if (v5068) {
      int * v3516 = v3502->cache_keys;
      int * v3517 = v3502->cache_keys;
      int v3518 = v3517[0];
      v3516[1] = v3518;
      int * v3520 = v3502->cache_vals;
      int * v3521 = v3502->cache_vals;
      int v3522 = v3521[0];
      v3520[1] = v3522;
      int * v3524 = v3502->cache_keys;
      int v5076 = (int)((unsigned int)(v3506 + 56) >> 2);
      v3524[0] = v5076;
      int * v3526 = v3502->cache_vals;
      v3526[0] = v3508;
      int v3528 = v3502->timer;
      int v5079 = v3528 + 1;
      v3502->timer = v5079;
      v3552 = v3508;
    } else {
      int * v3531 = v3502->mem;
      int * v3532 = v3502->cache_keys;
      int v3533 = v3532[1];
      int * v3534 = v3502->cache_vals;
      int v3535 = v3534[1];
      v3531[v3533] = v3535;
      int * v3537 = v3502->cache_keys;
      int * v3538 = v3502->cache_keys;
      int v3539 = v3538[0];
      v3537[1] = v3539;
      int * v3541 = v3502->cache_vals;
      int * v3542 = v3502->cache_vals;
      int v3543 = v3542[0];
      v3541[1] = v3543;
      int * v3545 = v3502->cache_keys;
      int v5092 = (int)((unsigned int)(v3506 + 56) >> 2);
      v3545[0] = v5092;
      int * v3547 = v3502->cache_vals;
      v3547[0] = v3508;
      int v3549 = v3502->timer;
      int v5095 = v3549 + 100;
      v3502->timer = v5095;
      v3552 = v3508;
    }
    v3554 = v3552;
  }
  struct StateT * v5055 = v3555(v3502);
  return v5055;
}

struct StateT * v1915(struct StateT * v1916) {
  int v1917 = v1916->timer;
  int v9718 = v1917 + 1;
  v1916->timer = v9718;
  int * v1919 = v1916->regs;
  int v1920 = v1919[7];
  int * v1921 = v1916->regs;
  v1921[14] = v1920;
  struct StateT * v9716 = v1923(v1916);
  return v9716;
}

struct StateT * v6989(struct StateT * v6990) {
  int v6991 = v6990->timer;
  int v8942 = v6991 + 1;
  v6990->timer = v8942;
  int * v6993 = v6990->regs;
  int v6994 = v6993[8];
  int * v6995 = v6990->regs;
  int v6996 = v6995[25];
  int * v6997 = v6990->regs;
  int v8949 = v6994 + v6996;
  v6997[5] = v8949;
  struct StateT * v8940 = v6999(v6990);
  return v8940;
}

struct StateT * v6725(struct StateT * v6726) {
  int v6727 = v6726->timer;
  int v9250 = v6727 + 1;
  v6726->timer = v9250;
  int * v6729 = v6726->regs;
  int v6730 = v6729[18];
  int * v6731 = v6726->regs;
  int v6732 = v6731[20];
  int * v6733 = v6726->regs;
  int v9256 = v6730 | v6732;
  v6733[18] = v9256;
  struct StateT * v9248 = v6735(v6726);
  return v9248;
}

struct StateT * v3339(struct StateT * v3340) {
  int v3341 = v3340->timer;
  int v5191 = v3341 + 1;
  v3340->timer = v5191;
  int * v3343 = v3340->regs;
  int v3344 = v3343[10];
  int * v3345 = v3340->regs;
  int v3346 = v3345[17];
  int * v3347 = v3340->cache_keys;
  int v3348 = v3347[0];
  bool v5198 = v3348 == ((int)((unsigned int)(v3344 + 44) >> 2));
  int v3392;
  if (v5198) {
    int * v3349 = v3340->cache_vals;
    v3349[0] = v3346;
    v3392 = v3346;
  } else {
    int * v3352 = v3340->cache_keys;
    int v3353 = v3352[1];
    bool v5203 = v3353 == ((int)((unsigned int)(v3344 + 44) >> 2));
    int v3390;
    if (v5203) {
      int * v3354 = v3340->cache_keys;
      int * v3355 = v3340->cache_keys;
      int v3356 = v3355[0];
      v3354[1] = v3356;
      int * v3358 = v3340->cache_vals;
      int * v3359 = v3340->cache_vals;
      int v3360 = v3359[0];
      v3358[1] = v3360;
      int * v3362 = v3340->cache_keys;
      int v5211 = (int)((unsigned int)(v3344 + 44) >> 2);
      v3362[0] = v5211;
      int * v3364 = v3340->cache_vals;
      v3364[0] = v3346;
      int v3366 = v3340->timer;
      int v5214 = v3366 + 1;
      v3340->timer = v5214;
      v3390 = v3346;
    } else {
      int * v3369 = v3340->mem;
      int * v3370 = v3340->cache_keys;
      int v3371 = v3370[1];
      int * v3372 = v3340->cache_vals;
      int v3373 = v3372[1];
      v3369[v3371] = v3373;
      int * v3375 = v3340->cache_keys;
      int * v3376 = v3340->cache_keys;
      int v3377 = v3376[0];
      v3375[1] = v3377;
      int * v3379 = v3340->cache_vals;
      int * v3380 = v3340->cache_vals;
      int v3381 = v3380[0];
      v3379[1] = v3381;
      int * v3383 = v3340->cache_keys;
      int v5227 = (int)((unsigned int)(v3344 + 44) >> 2);
      v3383[0] = v5227;
      int * v3385 = v3340->cache_vals;
      v3385[0] = v3346;
      int v3387 = v3340->timer;
      int v5230 = v3387 + 100;
      v3340->timer = v5230;
      v3390 = v3346;
    }
    v3392 = v3390;
  }
  struct StateT * v5189 = v3393(v3340);
  return v5189;
}

struct StateT * v1439(struct StateT * v1440) {
  int v1441 = v1440->timer;
  int v10132 = v1441 + 1;
  v1440->timer = v10132;
  int * v1443 = v1440->regs;
  int v1444 = v1443[13];
  int * v1445 = v1440->regs;
  int v10137 = v1444 + 1134;
  v1445[11] = v10137;
  struct StateT * v10130 = v1447(v1440);
  return v10130;
}

struct StateT * v3015(struct StateT * v3016) {
  int v3017 = v3016->timer;
  int v5461 = v3017 + 1;
  v3016->timer = v5461;
  int * v3019 = v3016->regs;
  int v3020 = v3019[10];
  int * v3021 = v3016->regs;
  int v3022 = v3021[11];
  int * v3023 = v3016->cache_keys;
  int v3024 = v3023[0];
  bool v5468 = v3024 == ((int)((unsigned int)(v3020 + 20) >> 2));
  int v3068;
  if (v5468) {
    int * v3025 = v3016->cache_vals;
    v3025[0] = v3022;
    v3068 = v3022;
  } else {
    int * v3028 = v3016->cache_keys;
    int v3029 = v3028[1];
    bool v5473 = v3029 == ((int)((unsigned int)(v3020 + 20) >> 2));
    int v3066;
    if (v5473) {
      int * v3030 = v3016->cache_keys;
      int * v3031 = v3016->cache_keys;
      int v3032 = v3031[0];
      v3030[1] = v3032;
      int * v3034 = v3016->cache_vals;
      int * v3035 = v3016->cache_vals;
      int v3036 = v3035[0];
      v3034[1] = v3036;
      int * v3038 = v3016->cache_keys;
      int v5481 = (int)((unsigned int)(v3020 + 20) >> 2);
      v3038[0] = v5481;
      int * v3040 = v3016->cache_vals;
      v3040[0] = v3022;
      int v3042 = v3016->timer;
      int v5484 = v3042 + 1;
      v3016->timer = v5484;
      v3066 = v3022;
    } else {
      int * v3045 = v3016->mem;
      int * v3046 = v3016->cache_keys;
      int v3047 = v3046[1];
      int * v3048 = v3016->cache_vals;
      int v3049 = v3048[1];
      v3045[v3047] = v3049;
      int * v3051 = v3016->cache_keys;
      int * v3052 = v3016->cache_keys;
      int v3053 = v3052[0];
      v3051[1] = v3053;
      int * v3055 = v3016->cache_vals;
      int * v3056 = v3016->cache_vals;
      int v3057 = v3056[0];
      v3055[1] = v3057;
      int * v3059 = v3016->cache_keys;
      int v5497 = (int)((unsigned int)(v3020 + 20) >> 2);
      v3059[0] = v5497;
      int * v3061 = v3016->cache_vals;
      v3061[0] = v3022;
      int v3063 = v3016->timer;
      int v5500 = v3063 + 100;
      v3016->timer = v5500;
      v3066 = v3022;
    }
    v3068 = v3066;
  }
  struct StateT * v5459 = v3069(v3016);
  return v5459;
}

struct StateT * v6611(struct StateT * v6612) {
  int v6613 = v6612->timer;
  int v9382 = v6613 + 1;
  v6612->timer = v9382;
  int * v6615 = v6612->regs;
  int v6616 = v6615[1];
  int * v6617 = v6612->regs;
  int v6618 = v6617[19];
  int * v6619 = v6612->regs;
  int v9389 = v6616 + v6618;
  v6619[9] = v9389;
  struct StateT * v9380 = v6621(v6612);
  return v9380;
}

struct StateT * v7191(struct StateT * v7192) {
  int v7193 = v7192->timer;
  int v8710 = v7193 + 1;
  v7192->timer = v8710;
  int * v7195 = v7192->regs;
  int v7196 = v7195[15];
  int * v7197 = v7192->regs;
  int v8714 = v7196 << 7;
  v7197[15] = v8714;
  struct StateT * v8708 = v7199(v7192);
  return v8708;
}

struct StateT * v7541(struct StateT * v7542) {
  int v7543 = v7542->timer;
  int v8301 = v7543 + 1;
  v7542->timer = v8301;
  int * v7545 = v7542->regs;
  int v7546 = v7545[24];
  int * v7547 = v7542->regs;
  int v7548 = v7547[16];
  int * v7549 = v7542->regs;
  int v8308 = v7546 + v7548;
  v7549[8] = v8308;
  struct StateT * v8299 = v7551(v7542);
  return v8299;
}

struct StateT * v7153(struct StateT * v7154) {
  int v7155 = v7154->timer;
  int v8753 = v7155 + 1;
  v7154->timer = v8753;
  int * v7157 = v7154->regs;
  int v7158 = v7157[20];
  int * v7159 = v7154->regs;
  int v7160 = v7159[12];
  int * v7161 = v7154->regs;
  int v8760 = v7158 + v7160;
  v7161[11] = v8760;
  struct StateT * v8751 = v7163(v7154);
  return v8751;
}

struct StateT * v3725(struct StateT * v3726) {
  int v3727 = v3726->timer;
  int v4868 = v3727 + 1;
  v3726->timer = v4868;
  int * v3729 = v3726->regs;
  int v3730 = v3729[2];
  int * v3731 = v3726->cache_keys;
  int v3732 = v3731[0];
  bool v4873 = v3732 == ((int)((unsigned int)(v3730 + 84) >> 2));
  int v3780;
  if (v4873) {
    int * v3733 = v3726->cache_vals;
    int v3734 = v3733[0];
    v3780 = v3734;
  } else {
    int * v3736 = v3726->cache_keys;
    int v3737 = v3736[1];
    bool v4878 = v3737 == ((int)((unsigned int)(v3730 + 84) >> 2));
    int v3778;
    if (v4878) {
      int * v3738 = v3726->cache_vals;
      int v3739 = v3738[1];
      int * v3740 = v3726->cache_keys;
      int * v3741 = v3726->cache_keys;
      int v3742 = v3741[0];
      v3740[1] = v3742;
      int * v3744 = v3726->cache_vals;
      int * v3745 = v3726->cache_vals;
      int v3746 = v3745[0];
      v3744[1] = v3746;
      int * v3748 = v3726->cache_keys;
      int v4887 = (int)((unsigned int)(v3730 + 84) >> 2);
      v3748[0] = v4887;
      int * v3750 = v3726->cache_vals;
      v3750[0] = v3739;
      int v3752 = v3726->timer;
      int v4890 = v3752 + 1;
      v3726->timer = v4890;
      v3778 = v3739;
    } else {
      int * v3755 = v3726->mem;
      int v4892 = (int)((unsigned int)(v3730 + 84) >> 2);
      int v3756 = v3755[v4892];
      int * v3757 = v3726->mem;
      int * v3758 = v3726->cache_keys;
      int v3759 = v3758[1];
      int * v3760 = v3726->cache_vals;
      int v3761 = v3760[1];
      v3757[v3759] = v3761;
      int * v3763 = v3726->cache_keys;
      int * v3764 = v3726->cache_keys;
      int v3765 = v3764[0];
      v3763[1] = v3765;
      int * v3767 = v3726->cache_vals;
      int * v3768 = v3726->cache_vals;
      int v3769 = v3768[0];
      v3767[1] = v3769;
      int * v3771 = v3726->cache_keys;
      v3771[0] = v4892;
      int * v3773 = v3726->cache_vals;
      v3773[0] = v3756;
      int v3775 = v3726->timer;
      int v4907 = v3775 + 100;
      v3726->timer = v4907;
      v3778 = v3756;
    }
    v3780 = v3778;
  }
  int * v3781 = v3726->regs;
  v3781[9] = v3780;
  struct StateT * v4866 = v3783(v3726);
  return v4866;
}

struct StateT * v7637(struct StateT * v7638) {
  int v7639 = v7638->timer;
  int v8192 = v7639 + 1;
  v7638->timer = v8192;
  int * v7641 = v7638->regs;
  int v7642 = v7641[8];
  int * v7643 = v7638->regs;
  int v8196 = v7642 << 13;
  v7643[8] = v8196;
  struct StateT * v8190 = v7645(v7638);
  return v8190;
}

struct StateT * v2657(struct StateT * v2658) {
  int v2659 = v2658->timer;
  int v5819 = v2659 + 1;
  v2658->timer = v5819;
  int * v2661 = v2658->regs;
  int v2662 = v2661[1];
  int * v2663 = v2658->regs;
  int v2664 = v2663[30];
  int * v2665 = v2658->regs;
  int v5825 = v2662 + v2664;
  v2665[1] = v5825;
  struct StateT * v5817 = v2667(v2658);
  return v5817;
}

struct StateT * v2253(struct StateT * v2254) {
  int v2255 = v2254->timer;
  int v6133 = v2255 + 1;
  v2254->timer = v6133;
  int * v2257 = v2254->regs;
  int v2258 = v2257[2];
  int * v2259 = v2254->cache_keys;
  int v2260 = v2259[0];
  bool v6138 = v2260 == ((int)((unsigned int)(v2258 + 20) >> 2));
  int v2308;
  if (v6138) {
    int * v2261 = v2254->cache_vals;
    int v2262 = v2261[0];
    v2308 = v2262;
  } else {
    int * v2264 = v2254->cache_keys;
    int v2265 = v2264[1];
    bool v6143 = v2265 == ((int)((unsigned int)(v2258 + 20) >> 2));
    int v2306;
    if (v6143) {
      int * v2266 = v2254->cache_vals;
      int v2267 = v2266[1];
      int * v2268 = v2254->cache_keys;
      int * v2269 = v2254->cache_keys;
      int v2270 = v2269[0];
      v2268[1] = v2270;
      int * v2272 = v2254->cache_vals;
      int * v2273 = v2254->cache_vals;
      int v2274 = v2273[0];
      v2272[1] = v2274;
      int * v2276 = v2254->cache_keys;
      int v6152 = (int)((unsigned int)(v2258 + 20) >> 2);
      v2276[0] = v6152;
      int * v2278 = v2254->cache_vals;
      v2278[0] = v2267;
      int v2280 = v2254->timer;
      int v6155 = v2280 + 1;
      v2254->timer = v6155;
      v2306 = v2267;
    } else {
      int * v2283 = v2254->mem;
      int v6157 = (int)((unsigned int)(v2258 + 20) >> 2);
      int v2284 = v2283[v6157];
      int * v2285 = v2254->mem;
      int * v2286 = v2254->cache_keys;
      int v2287 = v2286[1];
      int * v2288 = v2254->cache_vals;
      int v2289 = v2288[1];
      v2285[v2287] = v2289;
      int * v2291 = v2254->cache_keys;
      int * v2292 = v2254->cache_keys;
      int v2293 = v2292[0];
      v2291[1] = v2293;
      int * v2295 = v2254->cache_vals;
      int * v2296 = v2254->cache_vals;
      int v2297 = v2296[0];
      v2295[1] = v2297;
      int * v2299 = v2254->cache_keys;
      v2299[0] = v6157;
      int * v2301 = v2254->cache_vals;
      v2301[0] = v2284;
      int v2303 = v2254->timer;
      int v6172 = v2303 + 100;
      v2254->timer = v6172;
      v2306 = v2284;
    }
    v2308 = v2306;
  }
  int * v2309 = v2254->regs;
  v2309[7] = v2308;
  struct StateT * v6131 = v2311(v2254);
  return v6131;
}

struct StateT * v7327(struct StateT * v7328) {
  int v7329 = v7328->timer;
  int v8549 = v7329 + 1;
  v7328->timer = v8549;
  int * v7331 = v7328->regs;
  int v7332 = v7331[23];
  int * v7333 = v7328->regs;
  int v7334 = v7333[21];
  int * v7335 = v7328->regs;
  int v8556 = v7332 + v7334;
  v7335[11] = v8556;
  struct StateT * v8547 = v7337(v7328);
  return v8547;
}

struct StateT * v4073(struct StateT * v4074) {
  int v4075 = v4074->timer;
  int v4580 = v4075 + 1;
  v4074->timer = v4580;
  int * v4077 = v4074->regs;
  int v4078 = v4077[2];
  int * v4079 = v4074->cache_keys;
  int v4080 = v4079[0];
  bool v4585 = v4080 == ((int)((unsigned int)(v4078 + 60) >> 2));
  int v4128;
  if (v4585) {
    int * v4081 = v4074->cache_vals;
    int v4082 = v4081[0];
    v4128 = v4082;
  } else {
    int * v4084 = v4074->cache_keys;
    int v4085 = v4084[1];
    bool v4590 = v4085 == ((int)((unsigned int)(v4078 + 60) >> 2));
    int v4126;
    if (v4590) {
      int * v4086 = v4074->cache_vals;
      int v4087 = v4086[1];
      int * v4088 = v4074->cache_keys;
      int * v4089 = v4074->cache_keys;
      int v4090 = v4089[0];
      v4088[1] = v4090;
      int * v4092 = v4074->cache_vals;
      int * v4093 = v4074->cache_vals;
      int v4094 = v4093[0];
      v4092[1] = v4094;
      int * v4096 = v4074->cache_keys;
      int v4599 = (int)((unsigned int)(v4078 + 60) >> 2);
      v4096[0] = v4599;
      int * v4098 = v4074->cache_vals;
      v4098[0] = v4087;
      int v4100 = v4074->timer;
      int v4602 = v4100 + 1;
      v4074->timer = v4602;
      v4126 = v4087;
    } else {
      int * v4103 = v4074->mem;
      int v4604 = (int)((unsigned int)(v4078 + 60) >> 2);
      int v4104 = v4103[v4604];
      int * v4105 = v4074->mem;
      int * v4106 = v4074->cache_keys;
      int v4107 = v4106[1];
      int * v4108 = v4074->cache_vals;
      int v4109 = v4108[1];
      v4105[v4107] = v4109;
      int * v4111 = v4074->cache_keys;
      int * v4112 = v4074->cache_keys;
      int v4113 = v4112[0];
      v4111[1] = v4113;
      int * v4115 = v4074->cache_vals;
      int * v4116 = v4074->cache_vals;
      int v4117 = v4116[0];
      v4115[1] = v4117;
      int * v4119 = v4074->cache_keys;
      v4119[0] = v4604;
      int * v4121 = v4074->cache_vals;
      v4121[0] = v4104;
      int v4123 = v4074->timer;
      int v4619 = v4123 + 100;
      v4074->timer = v4619;
      v4126 = v4104;
    }
    v4128 = v4126;
  }
  int * v4129 = v4074->regs;
  v4129[23] = v4128;
  struct StateT * v4578 = v4131(v4074);
  return v4578;
}

struct StateT * v7787(struct StateT * v7788) {
  int v7789 = v7788->timer;
  int v8019 = v7789 + 1;
  v7788->timer = v8019;
  int * v7791 = v7788->regs;
  int v7792 = v7791[6];
  int * v7793 = v7788->regs;
  int v8024 = (int)((unsigned int)v7792 >> 14);
  v7793[9] = v8024;
  struct StateT * v8017 = v7795(v7788);
  return v8017;
}

struct StateT * v6533(struct StateT * v6534) {
  int v6535 = v6534->timer;
  int v9473 = v6535 + 1;
  v6534->timer = v9473;
  int * v6537 = v6534->regs;
  int v6538 = v6537[8];
  int * v6539 = v6534->regs;
  int v9477 = v6538 << 7;
  v6539[8] = v9477;
  struct StateT * v9471 = v6541(v6534);
  return v9471;
}

struct StateT * v7603(struct StateT * v7604) {
  int v7605 = v7604->timer;
  int v8231 = v7605 + 1;
  v7604->timer = v8231;
  int * v7607 = v7604->regs;
  int v7608 = v7607[6];
  int * v7609 = v7604->regs;
  int v8236 = (int)((unsigned int)v7608 >> 19);
  v7609[9] = v8236;
  struct StateT * v8229 = v7611(v7604);
  return v8229;
}

struct StateT * v7453(struct StateT * v7454) {
  int v7455 = v7454->timer;
  int v8404 = v7455 + 1;
  v7454->timer = v8404;
  int * v7457 = v7454->regs;
  int v7458 = v7457[8];
  int * v7459 = v7454->regs;
  int v8408 = v7458 << 9;
  v7459[8] = v8408;
  struct StateT * v8402 = v7461(v7454);
  return v8402;
}

struct StateT * v6979(struct StateT * v6980) {
  int v6981 = v6980->timer;
  int v8954 = v6981 + 1;
  v6980->timer = v8954;
  int * v6983 = v6980->regs;
  int v6984 = v6983[18];
  int * v6985 = v6980->regs;
  int v6986 = v6985[27];
  int * v6987 = v6980->regs;
  int v8961 = v6984 + v6986;
  v6987[17] = v8961;
  struct StateT * v8952 = v6989(v6980);
  return v8952;
}

struct StateT * v603(struct StateT * v604) {
  int v605 = v604->timer;
  int v10805 = v605 + 1;
  v604->timer = v10805;
  int * v607 = v604->regs;
  int v608 = v607[2];
  int * v609 = v604->regs;
  int v610 = v609[26];
  int * v611 = v604->cache_keys;
  int v612 = v611[0];
  bool v10812 = v612 == ((int)((unsigned int)(v608 + 48) >> 2));
  int v656;
  if (v10812) {
    int * v613 = v604->cache_vals;
    v613[0] = v610;
    v656 = v610;
  } else {
    int * v616 = v604->cache_keys;
    int v617 = v616[1];
    bool v10817 = v617 == ((int)((unsigned int)(v608 + 48) >> 2));
    int v654;
    if (v10817) {
      int * v618 = v604->cache_keys;
      int * v619 = v604->cache_keys;
      int v620 = v619[0];
      v618[1] = v620;
      int * v622 = v604->cache_vals;
      int * v623 = v604->cache_vals;
      int v624 = v623[0];
      v622[1] = v624;
      int * v626 = v604->cache_keys;
      int v10825 = (int)((unsigned int)(v608 + 48) >> 2);
      v626[0] = v10825;
      int * v628 = v604->cache_vals;
      v628[0] = v610;
      int v630 = v604->timer;
      int v10828 = v630 + 1;
      v604->timer = v10828;
      v654 = v610;
    } else {
      int * v633 = v604->mem;
      int * v634 = v604->cache_keys;
      int v635 = v634[1];
      int * v636 = v604->cache_vals;
      int v637 = v636[1];
      v633[v635] = v637;
      int * v639 = v604->cache_keys;
      int * v640 = v604->cache_keys;
      int v641 = v640[0];
      v639[1] = v641;
      int * v643 = v604->cache_vals;
      int * v644 = v604->cache_vals;
      int v645 = v644[0];
      v643[1] = v645;
      int * v647 = v604->cache_keys;
      int v10841 = (int)((unsigned int)(v608 + 48) >> 2);
      v647[0] = v10841;
      int * v649 = v604->cache_vals;
      v649[0] = v610;
      int v651 = v604->timer;
      int v10844 = v651 + 100;
      v604->timer = v10844;
      v654 = v610;
    }
    v656 = v654;
  }
  struct StateT * v10803 = v657(v604);
  return v10803;
}

struct StateT * v4247(struct StateT * v4248) {
  int v4249 = v4248->timer;
  int v4436 = v4249 + 1;
  v4248->timer = v4436;
  int * v4251 = v4248->regs;
  int v4252 = v4251[2];
  int * v4253 = v4248->cache_keys;
  int v4254 = v4253[0];
  bool v4441 = v4254 == ((int)((unsigned int)(v4252 + 48) >> 2));
  int v4302;
  if (v4441) {
    int * v4255 = v4248->cache_vals;
    int v4256 = v4255[0];
    v4302 = v4256;
  } else {
    int * v4258 = v4248->cache_keys;
    int v4259 = v4258[1];
    bool v4446 = v4259 == ((int)((unsigned int)(v4252 + 48) >> 2));
    int v4300;
    if (v4446) {
      int * v4260 = v4248->cache_vals;
      int v4261 = v4260[1];
      int * v4262 = v4248->cache_keys;
      int * v4263 = v4248->cache_keys;
      int v4264 = v4263[0];
      v4262[1] = v4264;
      int * v4266 = v4248->cache_vals;
      int * v4267 = v4248->cache_vals;
      int v4268 = v4267[0];
      v4266[1] = v4268;
      int * v4270 = v4248->cache_keys;
      int v4455 = (int)((unsigned int)(v4252 + 48) >> 2);
      v4270[0] = v4455;
      int * v4272 = v4248->cache_vals;
      v4272[0] = v4261;
      int v4274 = v4248->timer;
      int v4458 = v4274 + 1;
      v4248->timer = v4458;
      v4300 = v4261;
    } else {
      int * v4277 = v4248->mem;
      int v4460 = (int)((unsigned int)(v4252 + 48) >> 2);
      int v4278 = v4277[v4460];
      int * v4279 = v4248->mem;
      int * v4280 = v4248->cache_keys;
      int v4281 = v4280[1];
      int * v4282 = v4248->cache_vals;
      int v4283 = v4282[1];
      v4279[v4281] = v4283;
      int * v4285 = v4248->cache_keys;
      int * v4286 = v4248->cache_keys;
      int v4287 = v4286[0];
      v4285[1] = v4287;
      int * v4289 = v4248->cache_vals;
      int * v4290 = v4248->cache_vals;
      int v4291 = v4290[0];
      v4289[1] = v4291;
      int * v4293 = v4248->cache_keys;
      v4293[0] = v4460;
      int * v4295 = v4248->cache_vals;
      v4295[0] = v4278;
      int v4297 = v4248->timer;
      int v4475 = v4297 + 100;
      v4248->timer = v4475;
      v4300 = v4278;
    }
    v4302 = v4300;
  }
  int * v4303 = v4248->regs;
  v4303[26] = v4302;
  struct StateT * v4434 = v4305(v4248);
  return v4434;
}

struct StateT * v495(struct StateT * v496) {
  int v497 = v496->timer;
  int v10895 = v497 + 1;
  v496->timer = v10895;
  int * v499 = v496->regs;
  int v500 = v499[2];
  int * v501 = v496->regs;
  int v502 = v501[24];
  int * v503 = v496->cache_keys;
  int v504 = v503[0];
  bool v10902 = v504 == ((int)((unsigned int)(v500 + 56) >> 2));
  int v548;
  if (v10902) {
    int * v505 = v496->cache_vals;
    v505[0] = v502;
    v548 = v502;
  } else {
    int * v508 = v496->cache_keys;
    int v509 = v508[1];
    bool v10907 = v509 == ((int)((unsigned int)(v500 + 56) >> 2));
    int v546;
    if (v10907) {
      int * v510 = v496->cache_keys;
      int * v511 = v496->cache_keys;
      int v512 = v511[0];
      v510[1] = v512;
      int * v514 = v496->cache_vals;
      int * v515 = v496->cache_vals;
      int v516 = v515[0];
      v514[1] = v516;
      int * v518 = v496->cache_keys;
      int v10915 = (int)((unsigned int)(v500 + 56) >> 2);
      v518[0] = v10915;
      int * v520 = v496->cache_vals;
      v520[0] = v502;
      int v522 = v496->timer;
      int v10918 = v522 + 1;
      v496->timer = v10918;
      v546 = v502;
    } else {
      int * v525 = v496->mem;
      int * v526 = v496->cache_keys;
      int v527 = v526[1];
      int * v528 = v496->cache_vals;
      int v529 = v528[1];
      v525[v527] = v529;
      int * v531 = v496->cache_keys;
      int * v532 = v496->cache_keys;
      int v533 = v532[0];
      v531[1] = v533;
      int * v535 = v496->cache_vals;
      int * v536 = v496->cache_vals;
      int v537 = v536[0];
      v535[1] = v537;
      int * v539 = v496->cache_keys;
      int v10931 = (int)((unsigned int)(v500 + 56) >> 2);
      v539[0] = v10931;
      int * v541 = v496->cache_vals;
      v541[0] = v502;
      int v543 = v496->timer;
      int v10934 = v543 + 100;
      v496->timer = v10934;
      v546 = v502;
    }
    v548 = v546;
  }
  struct StateT * v10893 = v549(v496);
  return v10893;
}

struct StateT * v3285(struct StateT * v3286) {
  int v3287 = v3286->timer;
  int v5236 = v3287 + 1;
  v3286->timer = v5236;
  int * v3289 = v3286->regs;
  int v3290 = v3289[10];
  int * v3291 = v3286->regs;
  int v3292 = v3291[7];
  int * v3293 = v3286->cache_keys;
  int v3294 = v3293[0];
  bool v5243 = v3294 == ((int)((unsigned int)(v3290 + 40) >> 2));
  int v3338;
  if (v5243) {
    int * v3295 = v3286->cache_vals;
    v3295[0] = v3292;
    v3338 = v3292;
  } else {
    int * v3298 = v3286->cache_keys;
    int v3299 = v3298[1];
    bool v5248 = v3299 == ((int)((unsigned int)(v3290 + 40) >> 2));
    int v3336;
    if (v5248) {
      int * v3300 = v3286->cache_keys;
      int * v3301 = v3286->cache_keys;
      int v3302 = v3301[0];
      v3300[1] = v3302;
      int * v3304 = v3286->cache_vals;
      int * v3305 = v3286->cache_vals;
      int v3306 = v3305[0];
      v3304[1] = v3306;
      int * v3308 = v3286->cache_keys;
      int v5256 = (int)((unsigned int)(v3290 + 40) >> 2);
      v3308[0] = v5256;
      int * v3310 = v3286->cache_vals;
      v3310[0] = v3292;
      int v3312 = v3286->timer;
      int v5259 = v3312 + 1;
      v3286->timer = v5259;
      v3336 = v3292;
    } else {
      int * v3315 = v3286->mem;
      int * v3316 = v3286->cache_keys;
      int v3317 = v3316[1];
      int * v3318 = v3286->cache_vals;
      int v3319 = v3318[1];
      v3315[v3317] = v3319;
      int * v3321 = v3286->cache_keys;
      int * v3322 = v3286->cache_keys;
      int v3323 = v3322[0];
      v3321[1] = v3323;
      int * v3325 = v3286->cache_vals;
      int * v3326 = v3286->cache_vals;
      int v3327 = v3326[0];
      v3325[1] = v3327;
      int * v3329 = v3286->cache_keys;
      int v5272 = (int)((unsigned int)(v3290 + 40) >> 2);
      v3329[0] = v5272;
      int * v3331 = v3286->cache_vals;
      v3331[0] = v3292;
      int v3333 = v3286->timer;
      int v5275 = v3333 + 100;
      v3286->timer = v5275;
      v3336 = v3292;
    }
    v3338 = v3336;
  }
  struct StateT * v5234 = v3339(v3286);
  return v5234;
}

struct StateT * v1431(struct StateT * v1432) {
  int v1433 = v1432->timer;
  int v10142 = v1433 + 1;
  v1432->timer = v10142;
  int * v1435 = v1432->regs;
  int v1436 = v1435[12];
  int * v1437 = v1432->regs;
  int v10147 = v1436 + -1947;
  v1437[21] = v10147;
  struct StateT * v10140 = v1439(v1432);
  return v10140;
}

struct StateT * v6665(struct StateT * v6666) {
  int v6667 = v6666->timer;
  int v9321 = v6667 + 1;
  v6666->timer = v9321;
  int * v6669 = v6666->regs;
  int v6670 = v6669[8];
  int * v6671 = v6666->regs;
  int v9325 = v6670 << 9;
  v6671[8] = v9325;
  struct StateT * v9319 = v6673(v6666);
  return v9319;
}

struct StateT * v7015(struct StateT * v7016) {
  int v7017 = v7016->timer;
  int v8912 = v7017 + 1;
  v7016->timer = v8912;
  int * v7019 = v7016->regs;
  int v7020 = v7019[15];
  int * v7021 = v7016->regs;
  int v7022 = v7021[6];
  int * v7023 = v7016->regs;
  int v8918 = v7020 | v7022;
  v7023[15] = v8918;
  struct StateT * v8910 = v7025(v7016);
  return v8910;
}

struct StateT * v6473(struct StateT * v6474) {
  int v6475 = v6474->timer;
  int v9542 = v6475 + 1;
  v6474->timer = v9542;
  int * v6477 = v6474->regs;
  int v6478 = v6477[20];
  int * v6479 = v6474->regs;
  int v9547 = (int)((unsigned int)v6478 >> 25);
  v6479[9] = v9547;
  struct StateT * v9540 = v6481(v6474);
  return v9540;
}

struct StateT * v6683(struct StateT * v6684) {
  int v6685 = v6684->timer;
  int v9300 = v6685 + 1;
  v6684->timer = v9300;
  int * v6687 = v6684->regs;
  int v6688 = v6687[9];
  int * v6689 = v6684->regs;
  int v9305 = (int)((unsigned int)v6688 >> 23);
  v6689[20] = v9305;
  struct StateT * v9298 = v6691(v6684);
  return v9298;
}

struct StateT * v3123(struct StateT * v3124) {
  int v3125 = v3124->timer;
  int v5371 = v3125 + 1;
  v3124->timer = v5371;
  int * v3127 = v3124->regs;
  int v3128 = v3127[10];
  int * v3129 = v3124->regs;
  int v3130 = v3129[25];
  int * v3131 = v3124->cache_keys;
  int v3132 = v3131[0];
  bool v5378 = v3132 == ((int)((unsigned int)(v3128 + 28) >> 2));
  int v3176;
  if (v5378) {
    int * v3133 = v3124->cache_vals;
    v3133[0] = v3130;
    v3176 = v3130;
  } else {
    int * v3136 = v3124->cache_keys;
    int v3137 = v3136[1];
    bool v5383 = v3137 == ((int)((unsigned int)(v3128 + 28) >> 2));
    int v3174;
    if (v5383) {
      int * v3138 = v3124->cache_keys;
      int * v3139 = v3124->cache_keys;
      int v3140 = v3139[0];
      v3138[1] = v3140;
      int * v3142 = v3124->cache_vals;
      int * v3143 = v3124->cache_vals;
      int v3144 = v3143[0];
      v3142[1] = v3144;
      int * v3146 = v3124->cache_keys;
      int v5391 = (int)((unsigned int)(v3128 + 28) >> 2);
      v3146[0] = v5391;
      int * v3148 = v3124->cache_vals;
      v3148[0] = v3130;
      int v3150 = v3124->timer;
      int v5394 = v3150 + 1;
      v3124->timer = v5394;
      v3174 = v3130;
    } else {
      int * v3153 = v3124->mem;
      int * v3154 = v3124->cache_keys;
      int v3155 = v3154[1];
      int * v3156 = v3124->cache_vals;
      int v3157 = v3156[1];
      v3153[v3155] = v3157;
      int * v3159 = v3124->cache_keys;
      int * v3160 = v3124->cache_keys;
      int v3161 = v3160[0];
      v3159[1] = v3161;
      int * v3163 = v3124->cache_vals;
      int * v3164 = v3124->cache_vals;
      int v3165 = v3164[0];
      v3163[1] = v3165;
      int * v3167 = v3124->cache_keys;
      int v5407 = (int)((unsigned int)(v3128 + 28) >> 2);
      v3167[0] = v5407;
      int * v3169 = v3124->cache_vals;
      v3169[0] = v3130;
      int v3171 = v3124->timer;
      int v5410 = v3171 + 100;
      v3124->timer = v5410;
      v3174 = v3130;
    }
    v3176 = v3174;
  }
  struct StateT * v5369 = v3177(v3124);
  return v5369;
}

struct StateT * v2853(struct StateT * v2854) {
  int v2855 = v2854->timer;
  int v5596 = v2855 + 1;
  v2854->timer = v5596;
  int * v2857 = v2854->regs;
  int v2858 = v2857[10];
  int * v2859 = v2854->regs;
  int v2860 = v2859[28];
  int * v2861 = v2854->cache_keys;
  int v2862 = v2861[0];
  bool v5603 = v2862 == ((int)((unsigned int)(v2858 + 8) >> 2));
  int v2906;
  if (v5603) {
    int * v2863 = v2854->cache_vals;
    v2863[0] = v2860;
    v2906 = v2860;
  } else {
    int * v2866 = v2854->cache_keys;
    int v2867 = v2866[1];
    bool v5608 = v2867 == ((int)((unsigned int)(v2858 + 8) >> 2));
    int v2904;
    if (v5608) {
      int * v2868 = v2854->cache_keys;
      int * v2869 = v2854->cache_keys;
      int v2870 = v2869[0];
      v2868[1] = v2870;
      int * v2872 = v2854->cache_vals;
      int * v2873 = v2854->cache_vals;
      int v2874 = v2873[0];
      v2872[1] = v2874;
      int * v2876 = v2854->cache_keys;
      int v5616 = (int)((unsigned int)(v2858 + 8) >> 2);
      v2876[0] = v5616;
      int * v2878 = v2854->cache_vals;
      v2878[0] = v2860;
      int v2880 = v2854->timer;
      int v5619 = v2880 + 1;
      v2854->timer = v5619;
      v2904 = v2860;
    } else {
      int * v2883 = v2854->mem;
      int * v2884 = v2854->cache_keys;
      int v2885 = v2884[1];
      int * v2886 = v2854->cache_vals;
      int v2887 = v2886[1];
      v2883[v2885] = v2887;
      int * v2889 = v2854->cache_keys;
      int * v2890 = v2854->cache_keys;
      int v2891 = v2890[0];
      v2889[1] = v2891;
      int * v2893 = v2854->cache_vals;
      int * v2894 = v2854->cache_vals;
      int v2895 = v2894[0];
      v2893[1] = v2895;
      int * v2897 = v2854->cache_keys;
      int v5632 = (int)((unsigned int)(v2858 + 8) >> 2);
      v2897[0] = v5632;
      int * v2899 = v2854->cache_vals;
      v2899[0] = v2860;
      int v2901 = v2854->timer;
      int v5635 = v2901 + 100;
      v2854->timer = v5635;
      v2904 = v2860;
    }
    v2906 = v2904;
  }
  struct StateT * v5594 = v2907(v2854);
  return v5594;
}

struct StateT * v7173(struct StateT * v7174) {
  int v7175 = v7174->timer;
  int v8729 = v7175 + 1;
  v7174->timer = v8729;
  int * v7177 = v7174->regs;
  int v7178 = v7177[22];
  int * v7179 = v7174->regs;
  int v7180 = v7179[1];
  int * v7181 = v7174->regs;
  int v8736 = v7178 + v7180;
  v7181[17] = v8736;
  struct StateT * v8727 = v7183(v7174);
  return v8727;
}

struct StateT * v6929(struct StateT * v6930) {
  int v6931 = v6930->timer;
  int v9014 = v6931 + 1;
  v6930->timer = v9014;
  int * v6933 = v6930->regs;
  int v6934 = v6933[23];
  int * v6935 = v6930->regs;
  int v6936 = v6935[8];
  int * v6937 = v6930->regs;
  int v9020 = v6934 ^ v6936;
  v6937[23] = v9020;
  struct StateT * v9012 = v6939(v6930);
  return v9012;
}

struct StateT * v6709(struct StateT * v6710) {
  int v6711 = v6710->timer;
  int v9270 = v6711 + 1;
  v6710->timer = v9270;
  int * v6713 = v6710->regs;
  int v6714 = v6713[18];
  int * v6715 = v6710->regs;
  int v9275 = (int)((unsigned int)v6714 >> 23);
  v6715[20] = v9275;
  struct StateT * v9268 = v6717(v6710);
  return v9268;
}

struct StateT * v1799(struct StateT * v1800) {
  int v1801 = v1800->timer;
  int v9783 = v1801 + 1;
  v1800->timer = v9783;
  int * v1803 = v1800->regs;
  int v1804 = v1803[2];
  int * v1805 = v1800->regs;
  int v1806 = v1805[17];
  int * v1807 = v1800->cache_keys;
  int v1808 = v1807[0];
  bool v9790 = v1808 == ((int)((unsigned int)(v1804 + 28) >> 2));
  int v1852;
  if (v9790) {
    int * v1809 = v1800->cache_vals;
    v1809[0] = v1806;
    v1852 = v1806;
  } else {
    int * v1812 = v1800->cache_keys;
    int v1813 = v1812[1];
    bool v9795 = v1813 == ((int)((unsigned int)(v1804 + 28) >> 2));
    int v1850;
    if (v9795) {
      int * v1814 = v1800->cache_keys;
      int * v1815 = v1800->cache_keys;
      int v1816 = v1815[0];
      v1814[1] = v1816;
      int * v1818 = v1800->cache_vals;
      int * v1819 = v1800->cache_vals;
      int v1820 = v1819[0];
      v1818[1] = v1820;
      int * v1822 = v1800->cache_keys;
      int v9803 = (int)((unsigned int)(v1804 + 28) >> 2);
      v1822[0] = v9803;
      int * v1824 = v1800->cache_vals;
      v1824[0] = v1806;
      int v1826 = v1800->timer;
      int v9806 = v1826 + 1;
      v1800->timer = v9806;
      v1850 = v1806;
    } else {
      int * v1829 = v1800->mem;
      int * v1830 = v1800->cache_keys;
      int v1831 = v1830[1];
      int * v1832 = v1800->cache_vals;
      int v1833 = v1832[1];
      v1829[v1831] = v1833;
      int * v1835 = v1800->cache_keys;
      int * v1836 = v1800->cache_keys;
      int v1837 = v1836[0];
      v1835[1] = v1837;
      int * v1839 = v1800->cache_vals;
      int * v1840 = v1800->cache_vals;
      int v1841 = v1840[0];
      v1839[1] = v1841;
      int * v1843 = v1800->cache_keys;
      int v9819 = (int)((unsigned int)(v1804 + 28) >> 2);
      v1843[0] = v9819;
      int * v1845 = v1800->cache_vals;
      v1845[0] = v1806;
      int v1847 = v1800->timer;
      int v9822 = v1847 + 100;
      v1800->timer = v9822;
      v1850 = v1806;
    }
    v1852 = v1850;
  }
  struct StateT * v9781 = v1853(v1800);
  return v9781;
}

struct StateT * v117(struct StateT * v118) {
  int v119 = v118->timer;
  int v11210 = v119 + 1;
  v118->timer = v11210;
  int * v121 = v118->regs;
  int v122 = v121[2];
  int * v123 = v118->regs;
  int v124 = v123[9];
  int * v125 = v118->cache_keys;
  int v126 = v125[0];
  bool v11217 = v126 == ((int)((unsigned int)(v122 + 84) >> 2));
  int v170;
  if (v11217) {
    int * v127 = v118->cache_vals;
    v127[0] = v124;
    v170 = v124;
  } else {
    int * v130 = v118->cache_keys;
    int v131 = v130[1];
    bool v11222 = v131 == ((int)((unsigned int)(v122 + 84) >> 2));
    int v168;
    if (v11222) {
      int * v132 = v118->cache_keys;
      int * v133 = v118->cache_keys;
      int v134 = v133[0];
      v132[1] = v134;
      int * v136 = v118->cache_vals;
      int * v137 = v118->cache_vals;
      int v138 = v137[0];
      v136[1] = v138;
      int * v140 = v118->cache_keys;
      int v11230 = (int)((unsigned int)(v122 + 84) >> 2);
      v140[0] = v11230;
      int * v142 = v118->cache_vals;
      v142[0] = v124;
      int v144 = v118->timer;
      int v11233 = v144 + 1;
      v118->timer = v11233;
      v168 = v124;
    } else {
      int * v147 = v118->mem;
      int * v148 = v118->cache_keys;
      int v149 = v148[1];
      int * v150 = v118->cache_vals;
      int v151 = v150[1];
      v147[v149] = v151;
      int * v153 = v118->cache_keys;
      int * v154 = v118->cache_keys;
      int v155 = v154[0];
      v153[1] = v155;
      int * v157 = v118->cache_vals;
      int * v158 = v118->cache_vals;
      int v159 = v158[0];
      v157[1] = v159;
      int * v161 = v118->cache_keys;
      int v11246 = (int)((unsigned int)(v122 + 84) >> 2);
      v161[0] = v11246;
      int * v163 = v118->cache_vals;
      v163[0] = v124;
      int v165 = v118->timer;
      int v11249 = v165 + 100;
      v118->timer = v11249;
      v168 = v124;
    }
    v170 = v168;
  }
  struct StateT * v11208 = v171(v118);
  return v11208;
}

struct StateT * v6407(struct StateT * v6408) {
  int v6409 = v6408->timer;
  int v9618 = v6409 + 1;
  v6408->timer = v9618;
  int * v6411 = v6408->regs;
  int v6412 = v6411[21];
  int * v6413 = v6408->regs;
  int v6414 = v6413[16];
  int * v6415 = v6408->regs;
  int v9625 = v6412 + v6414;
  v6415[15] = v9625;
  struct StateT * v9616 = v6417(v6408);
  return v9616;
}

struct StateT * v7287(struct StateT * v7288) {
  int v7289 = v7288->timer;
  int v8597 = v7289 + 1;
  v7288->timer = v8597;
  int * v7291 = v7288->regs;
  int v7292 = v7291[23];
  int * v7293 = v7288->regs;
  int v7294 = v7293[15];
  int * v7295 = v7288->regs;
  int v8603 = v7292 ^ v7294;
  v7295[23] = v8603;
  struct StateT * v8595 = v7297(v7288);
  return v8595;
}

struct StateT * v9(struct StateT * v10) {
  int v11 = v10->timer;
  int v11300 = v11 + 1;
  v10->timer = v11300;
  int * v13 = v10->regs;
  int v14 = v13[2];
  int * v15 = v10->regs;
  int v16 = v15[1];
  int * v17 = v10->cache_keys;
  int v18 = v17[0];
  bool v11307 = v18 == ((int)((unsigned int)(v14 + 92) >> 2));
  int v62;
  if (v11307) {
    int * v19 = v10->cache_vals;
    v19[0] = v16;
    v62 = v16;
  } else {
    int * v22 = v10->cache_keys;
    int v23 = v22[1];
    bool v11311 = v23 == ((int)((unsigned int)(v14 + 92) >> 2));
    int v60;
    if (v11311) {
      int * v24 = v10->cache_keys;
      int * v25 = v10->cache_keys;
      int v26 = v25[0];
      v24[1] = v26;
      int * v28 = v10->cache_vals;
      int * v29 = v10->cache_vals;
      int v30 = v29[0];
      v28[1] = v30;
      int * v32 = v10->cache_keys;
      int v11319 = (int)((unsigned int)(v14 + 92) >> 2);
      v32[0] = v11319;
      int * v34 = v10->cache_vals;
      v34[0] = v16;
      int v36 = v10->timer;
      int v11322 = v36 + 1;
      v10->timer = v11322;
      v60 = v16;
    } else {
      int * v39 = v10->mem;
      int * v40 = v10->cache_keys;
      int v41 = v40[1];
      int * v42 = v10->cache_vals;
      int v43 = v42[1];
      v39[v41] = v43;
      int * v45 = v10->cache_keys;
      int * v46 = v10->cache_keys;
      int v47 = v46[0];
      v45[1] = v47;
      int * v49 = v10->cache_vals;
      int * v50 = v10->cache_vals;
      int v51 = v50[0];
      v49[1] = v51;
      int * v53 = v10->cache_keys;
      int v11335 = (int)((unsigned int)(v14 + 92) >> 2);
      v53[0] = v11335;
      int * v55 = v10->cache_vals;
      v55[0] = v16;
      int v57 = v10->timer;
      int v11338 = v57 + 100;
      v10->timer = v11338;
      v60 = v16;
    }
    v62 = v60;
  }
  struct StateT * v11298 = v63(v10);
  return v11298;
}

struct StateT * v1007(struct StateT * v1008) {
  int v1009 = v1008->timer;
  int v10464 = v1009 + 1;
  v1008->timer = v10464;
  int * v1011 = v1008->regs;
  int v1012 = v1011[12];
  int * v1013 = v1008->cache_keys;
  int v1014 = v1013[0];
  bool v10469 = v1014 == ((int)((unsigned int)(v1012 + 20) >> 2));
  int v1062;
  if (v10469) {
    int * v1015 = v1008->cache_vals;
    int v1016 = v1015[0];
    v1062 = v1016;
  } else {
    int * v1018 = v1008->cache_keys;
    int v1019 = v1018[1];
    bool v10474 = v1019 == ((int)((unsigned int)(v1012 + 20) >> 2));
    int v1060;
    if (v10474) {
      int * v1020 = v1008->cache_vals;
      int v1021 = v1020[1];
      int * v1022 = v1008->cache_keys;
      int * v1023 = v1008->cache_keys;
      int v1024 = v1023[0];
      v1022[1] = v1024;
      int * v1026 = v1008->cache_vals;
      int * v1027 = v1008->cache_vals;
      int v1028 = v1027[0];
      v1026[1] = v1028;
      int * v1030 = v1008->cache_keys;
      int v10483 = (int)((unsigned int)(v1012 + 20) >> 2);
      v1030[0] = v10483;
      int * v1032 = v1008->cache_vals;
      v1032[0] = v1021;
      int v1034 = v1008->timer;
      int v10486 = v1034 + 1;
      v1008->timer = v10486;
      v1060 = v1021;
    } else {
      int * v1037 = v1008->mem;
      int v10488 = (int)((unsigned int)(v1012 + 20) >> 2);
      int v1038 = v1037[v10488];
      int * v1039 = v1008->mem;
      int * v1040 = v1008->cache_keys;
      int v1041 = v1040[1];
      int * v1042 = v1008->cache_vals;
      int v1043 = v1042[1];
      v1039[v1041] = v1043;
      int * v1045 = v1008->cache_keys;
      int * v1046 = v1008->cache_keys;
      int v1047 = v1046[0];
      v1045[1] = v1047;
      int * v1049 = v1008->cache_vals;
      int * v1050 = v1008->cache_vals;
      int v1051 = v1050[0];
      v1049[1] = v1051;
      int * v1053 = v1008->cache_keys;
      v1053[0] = v10488;
      int * v1055 = v1008->cache_vals;
      v1055[0] = v1038;
      int v1057 = v1008->timer;
      int v10503 = v1057 + 100;
      v1008->timer = v10503;
      v1060 = v1038;
    }
    v1062 = v1060;
  }
  int * v1063 = v1008->regs;
  v1063[16] = v1062;
  struct StateT * v10462 = v1065(v1008);
  return v10462;
}

struct StateT * v7059(struct StateT * v7060) {
  int v7061 = v7060->timer;
  int v8863 = v7061 + 1;
  v7060->timer = v8863;
  int * v7063 = v7060->regs;
  int v7064 = v7063[17];
  int * v7065 = v7060->regs;
  int v8867 = v7064 << 18;
  v7065[17] = v8867;
  struct StateT * v8861 = v7067(v7060);
  return v8861;
}

struct StateT * v2531(struct StateT * v2532) {
  int v2533 = v2532->timer;
  int v5889 = v2533 + 1;
  v2532->timer = v5889;
  int * v2535 = v2532->regs;
  int v2536 = v2535[2];
  int * v2537 = v2532->cache_keys;
  int v2538 = v2537[0];
  bool v5894 = v2538 == ((int)((unsigned int)(v2536 + 36) >> 2));
  int v2586;
  if (v5894) {
    int * v2539 = v2532->cache_vals;
    int v2540 = v2539[0];
    v2586 = v2540;
  } else {
    int * v2542 = v2532->cache_keys;
    int v2543 = v2542[1];
    bool v5899 = v2543 == ((int)((unsigned int)(v2536 + 36) >> 2));
    int v2584;
    if (v5899) {
      int * v2544 = v2532->cache_vals;
      int v2545 = v2544[1];
      int * v2546 = v2532->cache_keys;
      int * v2547 = v2532->cache_keys;
      int v2548 = v2547[0];
      v2546[1] = v2548;
      int * v2550 = v2532->cache_vals;
      int * v2551 = v2532->cache_vals;
      int v2552 = v2551[0];
      v2550[1] = v2552;
      int * v2554 = v2532->cache_keys;
      int v5908 = (int)((unsigned int)(v2536 + 36) >> 2);
      v2554[0] = v5908;
      int * v2556 = v2532->cache_vals;
      v2556[0] = v2545;
      int v2558 = v2532->timer;
      int v5911 = v2558 + 1;
      v2532->timer = v5911;
      v2584 = v2545;
    } else {
      int * v2561 = v2532->mem;
      int v5913 = (int)((unsigned int)(v2536 + 36) >> 2);
      int v2562 = v2561[v5913];
      int * v2563 = v2532->mem;
      int * v2564 = v2532->cache_keys;
      int v2565 = v2564[1];
      int * v2566 = v2532->cache_vals;
      int v2567 = v2566[1];
      v2563[v2565] = v2567;
      int * v2569 = v2532->cache_keys;
      int * v2570 = v2532->cache_keys;
      int v2571 = v2570[0];
      v2569[1] = v2571;
      int * v2573 = v2532->cache_vals;
      int * v2574 = v2532->cache_vals;
      int v2575 = v2574[0];
      v2573[1] = v2575;
      int * v2577 = v2532->cache_keys;
      v2577[0] = v5913;
      int * v2579 = v2532->cache_vals;
      v2579[0] = v2562;
      int v2581 = v2532->timer;
      int v5928 = v2581 + 100;
      v2532->timer = v5928;
      v2584 = v2562;
    }
    v2586 = v2584;
  }
  int * v2587 = v2532->regs;
  v2587[30] = v2586;
  struct StateT * v5887 = v2589(v2532);
  return v5887;
}

struct StateT * v7821(struct StateT * v7822) {
  int v7823 = v7822->timer;
  int v7980 = v7823 + 1;
  v7822->timer = v7980;
  int * v7825 = v7822->regs;
  int v7826 = v7825[8];
  int * v7827 = v7822->regs;
  int v7984 = v7826 << 18;
  v7827[8] = v7984;
  struct StateT * v7978 = v7829(v7822);
  return v7978;
}

struct StateT * v1529(struct StateT * v1530) {
  int v1531 = v1530->timer;
  int v10007 = v1531 + 1;
  v1530->timer = v10007;
  int * v1533 = v1530->regs;
  int v1534 = v1533[2];
  int * v1535 = v1530->regs;
  int v1536 = v1535[25];
  int * v1537 = v1530->cache_keys;
  int v1538 = v1537[0];
  bool v10014 = v1538 == ((int)((unsigned int)(v1534 + 16) >> 2));
  int v1582;
  if (v10014) {
    int * v1539 = v1530->cache_vals;
    v1539[0] = v1536;
    v1582 = v1536;
  } else {
    int * v1542 = v1530->cache_keys;
    int v1543 = v1542[1];
    bool v10019 = v1543 == ((int)((unsigned int)(v1534 + 16) >> 2));
    int v1580;
    if (v10019) {
      int * v1544 = v1530->cache_keys;
      int * v1545 = v1530->cache_keys;
      int v1546 = v1545[0];
      v1544[1] = v1546;
      int * v1548 = v1530->cache_vals;
      int * v1549 = v1530->cache_vals;
      int v1550 = v1549[0];
      v1548[1] = v1550;
      int * v1552 = v1530->cache_keys;
      int v10027 = (int)((unsigned int)(v1534 + 16) >> 2);
      v1552[0] = v10027;
      int * v1554 = v1530->cache_vals;
      v1554[0] = v1536;
      int v1556 = v1530->timer;
      int v10030 = v1556 + 1;
      v1530->timer = v10030;
      v1580 = v1536;
    } else {
      int * v1559 = v1530->mem;
      int * v1560 = v1530->cache_keys;
      int v1561 = v1560[1];
      int * v1562 = v1530->cache_vals;
      int v1563 = v1562[1];
      v1559[v1561] = v1563;
      int * v1565 = v1530->cache_keys;
      int * v1566 = v1530->cache_keys;
      int v1567 = v1566[0];
      v1565[1] = v1567;
      int * v1569 = v1530->cache_vals;
      int * v1570 = v1530->cache_vals;
      int v1571 = v1570[0];
      v1569[1] = v1571;
      int * v1573 = v1530->cache_keys;
      int v10043 = (int)((unsigned int)(v1534 + 16) >> 2);
      v1573[0] = v10043;
      int * v1575 = v1530->cache_vals;
      v1575[0] = v1536;
      int v1577 = v1530->timer;
      int v10046 = v1577 + 100;
      v1530->timer = v10046;
      v1580 = v1536;
    }
    v1582 = v1580;
  }
  struct StateT * v10005 = v1583(v1530);
  return v10005;
}

struct StateT * v6867(struct StateT * v6868) {
  int v6869 = v6868->timer;
  int v9088 = v6869 + 1;
  v6868->timer = v9088;
  int * v6871 = v6868->regs;
  int v6872 = v6871[9];
  int * v6873 = v6868->regs;
  int v9093 = (int)((unsigned int)v6872 >> 19);
  v6873[20] = v9093;
  struct StateT * v9086 = v6875(v6868);
  return v9086;
}

struct StateT * v1181(struct StateT * v1182) {
  int v1183 = v1182->timer;
  int v10320 = v1183 + 1;
  v1182->timer = v10320;
  int * v1185 = v1182->regs;
  int v1186 = v1185[11];
  int * v1187 = v1182->cache_keys;
  int v1188 = v1187[0];
  bool v10325 = v1188 == ((int)((unsigned int)v1186 >> 2));
  int v1236;
  if (v10325) {
    int * v1189 = v1182->cache_vals;
    int v1190 = v1189[0];
    v1236 = v1190;
  } else {
    int * v1192 = v1182->cache_keys;
    int v1193 = v1192[1];
    bool v10330 = v1193 == ((int)((unsigned int)v1186 >> 2));
    int v1234;
    if (v10330) {
      int * v1194 = v1182->cache_vals;
      int v1195 = v1194[1];
      int * v1196 = v1182->cache_keys;
      int * v1197 = v1182->cache_keys;
      int v1198 = v1197[0];
      v1196[1] = v1198;
      int * v1200 = v1182->cache_vals;
      int * v1201 = v1182->cache_vals;
      int v1202 = v1201[0];
      v1200[1] = v1202;
      int * v1204 = v1182->cache_keys;
      int v10339 = (int)((unsigned int)v1186 >> 2);
      v1204[0] = v10339;
      int * v1206 = v1182->cache_vals;
      v1206[0] = v1195;
      int v1208 = v1182->timer;
      int v10342 = v1208 + 1;
      v1182->timer = v10342;
      v1234 = v1195;
    } else {
      int * v1211 = v1182->mem;
      int v10344 = (int)((unsigned int)v1186 >> 2);
      int v1212 = v1211[v10344];
      int * v1213 = v1182->mem;
      int * v1214 = v1182->cache_keys;
      int v1215 = v1214[1];
      int * v1216 = v1182->cache_vals;
      int v1217 = v1216[1];
      v1213[v1215] = v1217;
      int * v1219 = v1182->cache_keys;
      int * v1220 = v1182->cache_keys;
      int v1221 = v1220[0];
      v1219[1] = v1221;
      int * v1223 = v1182->cache_vals;
      int * v1224 = v1182->cache_vals;
      int v1225 = v1224[0];
      v1223[1] = v1225;
      int * v1227 = v1182->cache_keys;
      v1227[0] = v10344;
      int * v1229 = v1182->cache_vals;
      v1229[0] = v1212;
      int v1231 = v1182->timer;
      int v10359 = v1231 + 100;
      v1182->timer = v10359;
      v1234 = v1212;
    }
    v1236 = v1234;
  }
  int * v1237 = v1182->regs;
  v1237[5] = v1236;
  struct StateT * v10318 = v1239(v1182);
  return v10318;
}

struct StateT * v6939(struct StateT * v6940) {
  int v6941 = v6940->timer;
  int v9002 = v6941 + 1;
  v6940->timer = v9002;
  int * v6943 = v6940->regs;
  int v6944 = v6943[5];
  int * v6945 = v6940->regs;
  int v6946 = v6945[20];
  int * v6947 = v6940->regs;
  int v9009 = v6944 ^ v6946;
  v6947[18] = v9009;
  struct StateT * v9000 = v6949(v6940);
  return v9000;
}

struct StateT * v6571(struct StateT * v6572) {
  int v6573 = v6572->timer;
  int v9429 = v6573 + 1;
  v6572->timer = v9429;
  int * v6575 = v6572->regs;
  int v6576 = v6575[1];
  int * v6577 = v6572->regs;
  int v6578 = v6577[18];
  int * v6579 = v6572->regs;
  int v9435 = v6576 ^ v6578;
  v6579[1] = v9435;
  struct StateT * v9427 = v6581(v6572);
  return v9427;
}

struct StateT * v6901(struct StateT * v6902) {
  int v6903 = v6902->timer;
  int v9049 = v6903 + 1;
  v6902->timer = v9049;
  int * v6905 = v6902->regs;
  int v6906 = v6905[18];
  int * v6907 = v6902->regs;
  int v9053 = v6906 << 13;
  v6907[18] = v9053;
  struct StateT * v9047 = v6909(v6902);
  return v9047;
}

struct StateT * v6447(struct StateT * v6448) {
  int v6449 = v6448->timer;
  int v9572 = v6449 + 1;
  v6448->timer = v9572;
  int * v6451 = v6448->regs;
  int v6452 = v6451[15];
  int * v6453 = v6448->regs;
  int v9577 = (int)((unsigned int)v6452 >> 25);
  v6453[9] = v9577;
  struct StateT * v9570 = v6455(v6448);
  return v9570;
}

struct StateT * v6999(struct StateT * v7000) {
  int v7001 = v7000->timer;
  int v8932 = v7001 + 1;
  v7000->timer = v8932;
  int * v7003 = v7000->regs;
  int v7004 = v7003[15];
  int * v7005 = v7000->regs;
  int v8937 = (int)((unsigned int)v7004 >> 14);
  v7005[6] = v8937;
  struct StateT * v8930 = v7007(v7000);
  return v8930;
}

struct StateT * v2799(struct StateT * v2800) {
  int v2801 = v2800->timer;
  int v5641 = v2801 + 1;
  v2800->timer = v5641;
  int * v2803 = v2800->regs;
  int v2804 = v2803[10];
  int * v2805 = v2800->regs;
  int v2806 = v2805[29];
  int * v2807 = v2800->cache_keys;
  int v2808 = v2807[0];
  bool v5648 = v2808 == ((int)((unsigned int)(v2804 + 4) >> 2));
  int v2852;
  if (v5648) {
    int * v2809 = v2800->cache_vals;
    v2809[0] = v2806;
    v2852 = v2806;
  } else {
    int * v2812 = v2800->cache_keys;
    int v2813 = v2812[1];
    bool v5653 = v2813 == ((int)((unsigned int)(v2804 + 4) >> 2));
    int v2850;
    if (v5653) {
      int * v2814 = v2800->cache_keys;
      int * v2815 = v2800->cache_keys;
      int v2816 = v2815[0];
      v2814[1] = v2816;
      int * v2818 = v2800->cache_vals;
      int * v2819 = v2800->cache_vals;
      int v2820 = v2819[0];
      v2818[1] = v2820;
      int * v2822 = v2800->cache_keys;
      int v5661 = (int)((unsigned int)(v2804 + 4) >> 2);
      v2822[0] = v5661;
      int * v2824 = v2800->cache_vals;
      v2824[0] = v2806;
      int v2826 = v2800->timer;
      int v5664 = v2826 + 1;
      v2800->timer = v5664;
      v2850 = v2806;
    } else {
      int * v2829 = v2800->mem;
      int * v2830 = v2800->cache_keys;
      int v2831 = v2830[1];
      int * v2832 = v2800->cache_vals;
      int v2833 = v2832[1];
      v2829[v2831] = v2833;
      int * v2835 = v2800->cache_keys;
      int * v2836 = v2800->cache_keys;
      int v2837 = v2836[0];
      v2835[1] = v2837;
      int * v2839 = v2800->cache_vals;
      int * v2840 = v2800->cache_vals;
      int v2841 = v2840[0];
      v2839[1] = v2841;
      int * v2843 = v2800->cache_keys;
      int v5677 = (int)((unsigned int)(v2804 + 4) >> 2);
      v2843[0] = v5677;
      int * v2845 = v2800->cache_vals;
      v2845[0] = v2806;
      int v2847 = v2800->timer;
      int v5680 = v2847 + 100;
      v2800->timer = v5680;
      v2850 = v2806;
    }
    v2852 = v2850;
  }
  struct StateT * v5639 = v2853(v2800);
  return v5639;
}

struct StateT * v7645(struct StateT * v7646) {
  int v7647 = v7646->timer;
  int v8181 = v7647 + 1;
  v7646->timer = v8181;
  int * v7649 = v7646->regs;
  int v7650 = v7649[8];
  int * v7651 = v7646->regs;
  int v7652 = v7651[9];
  int * v7653 = v7646->regs;
  int v8187 = v7650 | v7652;
  v7653[8] = v8187;
  struct StateT * v8179 = v7655(v7646);
  return v8179;
}

struct StateT * v2243(struct StateT * v2244) {
  int v2245 = v2244->timer;
  int v6181 = v2245 + 1;
  v2244->timer = v6181;
  int * v2247 = v2244->regs;
  int v2248 = v2247[25];
  int * v2249 = v2244->regs;
  int v2250 = v2249[7];
  int * v2251 = v2244->regs;
  int v6187 = v2248 + v2250;
  v2251[25] = v6187;
  struct StateT * v6179 = v2253(v2244);
  return v6179;
}

struct StateT * v7401(struct StateT * v7402) {
  int v7403 = v7402->timer;
  int v8464 = v7403 + 1;
  v7402->timer = v8464;
  int * v7405 = v7402->regs;
  int v7406 = v7405[15];
  int * v7407 = v7402->regs;
  int v8468 = v7406 << 9;
  v7407[15] = v8468;
  struct StateT * v8462 = v7409(v7402);
  return v8462;
}

struct StateT * v6515(struct StateT * v6516) {
  int v6517 = v6516->timer;
  int v9492 = v6517 + 1;
  v6516->timer = v9492;
  int * v6519 = v6516->regs;
  int v6520 = v6519[18];
  int * v6521 = v6516->regs;
  int v6522 = v6521[20];
  int * v6523 = v6516->regs;
  int v9498 = v6520 | v6522;
  v6523[18] = v9498;
  struct StateT * v9490 = v6525(v6516);
  return v9490;
}

struct StateT * v7743(struct StateT * v7744) {
  int v7745 = v7744->timer;
  int v8070 = v7745 + 1;
  v7744->timer = v8070;
  int * v7747 = v7744->regs;
  int v7748 = v7747[11];
  int * v7749 = v7744->regs;
  int v8074 = v7748 << 18;
  v7749[11] = v8074;
  struct StateT * v8068 = v7751(v7744);
  return v8068;
}

struct StateT * v1455(struct StateT * v1456) {
  int v1457 = v1456->timer;
  int v10114 = v1457 + 1;
  v1456->timer = v10114;
  int * v1459 = v1456->regs;
  v1459[22] = 1797283840;
  struct StateT * v10112 = v1461(v1456);
  return v10112;
}

struct StateT * v6691(struct StateT * v6692) {
  int v6693 = v6692->timer;
  int v9291 = v6693 + 1;
  v6692->timer = v9291;
  int * v6695 = v6692->regs;
  int v6696 = v6695[9];
  int * v6697 = v6692->regs;
  int v9295 = v6696 << 9;
  v6697[9] = v9295;
  struct StateT * v9289 = v6699(v6692);
  return v9289;
}

struct StateT * v1853(struct StateT * v1854) {
  int v1855 = v1854->timer;
  int v9738 = v1855 + 1;
  v1854->timer = v9738;
  int * v1857 = v1854->regs;
  int v1858 = v1857[2];
  int * v1859 = v1854->regs;
  int v1860 = v1859[6];
  int * v1861 = v1854->cache_keys;
  int v1862 = v1861[0];
  bool v9745 = v1862 == ((int)((unsigned int)(v1858 + 8) >> 2));
  int v1906;
  if (v9745) {
    int * v1863 = v1854->cache_vals;
    v1863[0] = v1860;
    v1906 = v1860;
  } else {
    int * v1866 = v1854->cache_keys;
    int v1867 = v1866[1];
    bool v9750 = v1867 == ((int)((unsigned int)(v1858 + 8) >> 2));
    int v1904;
    if (v9750) {
      int * v1868 = v1854->cache_keys;
      int * v1869 = v1854->cache_keys;
      int v1870 = v1869[0];
      v1868[1] = v1870;
      int * v1872 = v1854->cache_vals;
      int * v1873 = v1854->cache_vals;
      int v1874 = v1873[0];
      v1872[1] = v1874;
      int * v1876 = v1854->cache_keys;
      int v9758 = (int)((unsigned int)(v1858 + 8) >> 2);
      v1876[0] = v9758;
      int * v1878 = v1854->cache_vals;
      v1878[0] = v1860;
      int v1880 = v1854->timer;
      int v9761 = v1880 + 1;
      v1854->timer = v9761;
      v1904 = v1860;
    } else {
      int * v1883 = v1854->mem;
      int * v1884 = v1854->cache_keys;
      int v1885 = v1884[1];
      int * v1886 = v1854->cache_vals;
      int v1887 = v1886[1];
      v1883[v1885] = v1887;
      int * v1889 = v1854->cache_keys;
      int * v1890 = v1854->cache_keys;
      int v1891 = v1890[0];
      v1889[1] = v1891;
      int * v1893 = v1854->cache_vals;
      int * v1894 = v1854->cache_vals;
      int v1895 = v1894[0];
      v1893[1] = v1895;
      int * v1897 = v1854->cache_keys;
      int v9774 = (int)((unsigned int)(v1858 + 8) >> 2);
      v1897[0] = v9774;
      int * v1899 = v1854->cache_vals;
      v1899[0] = v1860;
      int v1901 = v1854->timer;
      int v9777 = v1901 + 100;
      v1854->timer = v9777;
      v1904 = v1860;
    }
    v1906 = v1904;
  }
  struct StateT * v9736 = v1907(v1854);
  return v9736;
}

struct StateT * v279(struct StateT * v280) {
  int v281 = v280->timer;
  int v11075 = v281 + 1;
  v280->timer = v11075;
  int * v283 = v280->regs;
  int v284 = v283[2];
  int * v285 = v280->regs;
  int v286 = v285[20];
  int * v287 = v280->cache_keys;
  int v288 = v287[0];
  bool v11082 = v288 == ((int)((unsigned int)(v284 + 72) >> 2));
  int v332;
  if (v11082) {
    int * v289 = v280->cache_vals;
    v289[0] = v286;
    v332 = v286;
  } else {
    int * v292 = v280->cache_keys;
    int v293 = v292[1];
    bool v11087 = v293 == ((int)((unsigned int)(v284 + 72) >> 2));
    int v330;
    if (v11087) {
      int * v294 = v280->cache_keys;
      int * v295 = v280->cache_keys;
      int v296 = v295[0];
      v294[1] = v296;
      int * v298 = v280->cache_vals;
      int * v299 = v280->cache_vals;
      int v300 = v299[0];
      v298[1] = v300;
      int * v302 = v280->cache_keys;
      int v11095 = (int)((unsigned int)(v284 + 72) >> 2);
      v302[0] = v11095;
      int * v304 = v280->cache_vals;
      v304[0] = v286;
      int v306 = v280->timer;
      int v11098 = v306 + 1;
      v280->timer = v11098;
      v330 = v286;
    } else {
      int * v309 = v280->mem;
      int * v310 = v280->cache_keys;
      int v311 = v310[1];
      int * v312 = v280->cache_vals;
      int v313 = v312[1];
      v309[v311] = v313;
      int * v315 = v280->cache_keys;
      int * v316 = v280->cache_keys;
      int v317 = v316[0];
      v315[1] = v317;
      int * v319 = v280->cache_vals;
      int * v320 = v280->cache_vals;
      int v321 = v320[0];
      v319[1] = v321;
      int * v323 = v280->cache_keys;
      int v11111 = (int)((unsigned int)(v284 + 72) >> 2);
      v323[0] = v11111;
      int * v325 = v280->cache_vals;
      v325[0] = v286;
      int v327 = v280->timer;
      int v11114 = v327 + 100;
      v280->timer = v11114;
      v330 = v286;
    }
    v332 = v330;
  }
  struct StateT * v11073 = v333(v280);
  return v11073;
}

struct StateT * v4305(struct StateT * v4306) {
  int v4307 = v4306->timer;
  int v4388 = v4307 + 1;
  v4306->timer = v4388;
  int * v4309 = v4306->regs;
  int v4310 = v4309[2];
  int * v4311 = v4306->cache_keys;
  int v4312 = v4311[0];
  bool v4393 = v4312 == ((int)((unsigned int)(v4310 + 44) >> 2));
  int v4360;
  if (v4393) {
    int * v4313 = v4306->cache_vals;
    int v4314 = v4313[0];
    v4360 = v4314;
  } else {
    int * v4316 = v4306->cache_keys;
    int v4317 = v4316[1];
    bool v4398 = v4317 == ((int)((unsigned int)(v4310 + 44) >> 2));
    int v4358;
    if (v4398) {
      int * v4318 = v4306->cache_vals;
      int v4319 = v4318[1];
      int * v4320 = v4306->cache_keys;
      int * v4321 = v4306->cache_keys;
      int v4322 = v4321[0];
      v4320[1] = v4322;
      int * v4324 = v4306->cache_vals;
      int * v4325 = v4306->cache_vals;
      int v4326 = v4325[0];
      v4324[1] = v4326;
      int * v4328 = v4306->cache_keys;
      int v4407 = (int)((unsigned int)(v4310 + 44) >> 2);
      v4328[0] = v4407;
      int * v4330 = v4306->cache_vals;
      v4330[0] = v4319;
      int v4332 = v4306->timer;
      int v4410 = v4332 + 1;
      v4306->timer = v4410;
      v4358 = v4319;
    } else {
      int * v4335 = v4306->mem;
      int v4412 = (int)((unsigned int)(v4310 + 44) >> 2);
      int v4336 = v4335[v4412];
      int * v4337 = v4306->mem;
      int * v4338 = v4306->cache_keys;
      int v4339 = v4338[1];
      int * v4340 = v4306->cache_vals;
      int v4341 = v4340[1];
      v4337[v4339] = v4341;
      int * v4343 = v4306->cache_keys;
      int * v4344 = v4306->cache_keys;
      int v4345 = v4344[0];
      v4343[1] = v4345;
      int * v4347 = v4306->cache_vals;
      int * v4348 = v4306->cache_vals;
      int v4349 = v4348[0];
      v4347[1] = v4349;
      int * v4351 = v4306->cache_keys;
      v4351[0] = v4412;
      int * v4353 = v4306->cache_vals;
      v4353[0] = v4336;
      int v4355 = v4306->timer;
      int v4427 = v4355 + 100;
      v4306->timer = v4427;
      v4358 = v4336;
    }
    v4360 = v4358;
  }
  int * v4361 = v4306->regs;
  v4361[27] = v4360;
  struct StateT * v4386 = v4363(v4306);
  return v4386;
}

struct StateT * v6959(struct StateT * v6960) {
  int v6961 = v6960->timer;
  int v8978 = v6961 + 1;
  v6960->timer = v8978;
  int * v6963 = v6960->regs;
  int v6964 = v6963[9];
  int * v6965 = v6960->regs;
  int v6966 = v6965[26];
  int * v6967 = v6960->regs;
  int v8985 = v6964 + v6966;
  v6967[15] = v8985;
  struct StateT * v8976 = v6969(v6960);
  return v8976;
}

struct StateT * v6541(struct StateT * v6542) {
  int v6543 = v6542->timer;
  int v9462 = v6543 + 1;
  v6542->timer = v9462;
  int * v6545 = v6542->regs;
  int v6546 = v6545[8];
  int * v6547 = v6542->regs;
  int v6548 = v6547[20];
  int * v6549 = v6542->regs;
  int v9468 = v6546 | v6548;
  v6549[8] = v9468;
  struct StateT * v9460 = v6551(v6542);
  return v9460;
}

struct StateT * v7409(struct StateT * v7410) {
  int v7411 = v7410->timer;
  int v8453 = v7411 + 1;
  v7410->timer = v8453;
  int * v7413 = v7410->regs;
  int v7414 = v7413[15];
  int * v7415 = v7410->regs;
  int v7416 = v7415[9];
  int * v7417 = v7410->regs;
  int v8459 = v7414 | v7416;
  v7417[15] = v8459;
  struct StateT * v8451 = v7419(v7410);
  return v8451;
}

struct StateT * v6805(struct StateT * v6806) {
  int v6807 = v6806->timer;
  int v9158 = v6807 + 1;
  v6806->timer = v9158;
  int * v6809 = v6806->regs;
  int v6810 = v6809[25];
  int * v6811 = v6806->regs;
  int v6812 = v6811[14];
  int * v6813 = v6806->regs;
  int v9165 = v6810 + v6812;
  v6813[18] = v9165;
  struct StateT * v9156 = v6815(v6806);
  return v9156;
}

struct StateT * v6481(struct StateT * v6482) {
  int v6483 = v6482->timer;
  int v9533 = v6483 + 1;
  v6482->timer = v9533;
  int * v6485 = v6482->regs;
  int v6486 = v6485[20];
  int * v6487 = v6482->regs;
  int v9537 = v6486 << 7;
  v6487[20] = v9537;
  struct StateT * v9531 = v6489(v6482);
  return v9531;
}

struct StateT * v7113(struct StateT * v7114) {
  int v7115 = v7114->timer;
  int v8799 = v7115 + 1;
  v7114->timer = v8799;
  int * v7117 = v7114->regs;
  int v7118 = v7117[11];
  int * v7119 = v7114->regs;
  int v7120 = v7119[16];
  int * v7121 = v7114->regs;
  int v8806 = v7118 ^ v7120;
  v7121[20] = v8806;
  struct StateT * v8797 = v7123(v7114);
  return v8797;
}

struct StateT * v6969(struct StateT * v6970) {
  int v6971 = v6970->timer;
  int v8966 = v6971 + 1;
  v6970->timer = v8966;
  int * v6973 = v6970->regs;
  int v6974 = v6973[23];
  int * v6975 = v6970->regs;
  int v6976 = v6975[24];
  int * v6977 = v6970->regs;
  int v8973 = v6974 + v6976;
  v6977[16] = v8973;
  struct StateT * v8964 = v6979(v6970);
  return v8964;
}

struct StateT * v711(struct StateT * v712) {
  int v713 = v712->timer;
  int v10752 = v713 + 1;
  v712->timer = v10752;
  int * v715 = v712->regs;
  v715[30] = 0;
  struct StateT * v10750 = v717(v712);
  return v10750;
}

struct StateT * v2117(struct StateT * v2118) {
  int v2119 = v2118->timer;
  int v6251 = v2119 + 1;
  v2118->timer = v6251;
  int * v2121 = v2118->regs;
  int v2122 = v2121[2];
  int * v2123 = v2118->cache_keys;
  int v2124 = v2123[0];
  bool v6256 = v2124 == ((int)((unsigned int)(v2122 + 12) >> 2));
  int v2172;
  if (v6256) {
    int * v2125 = v2118->cache_vals;
    int v2126 = v2125[0];
    v2172 = v2126;
  } else {
    int * v2128 = v2118->cache_keys;
    int v2129 = v2128[1];
    bool v6261 = v2129 == ((int)((unsigned int)(v2122 + 12) >> 2));
    int v2170;
    if (v6261) {
      int * v2130 = v2118->cache_vals;
      int v2131 = v2130[1];
      int * v2132 = v2118->cache_keys;
      int * v2133 = v2118->cache_keys;
      int v2134 = v2133[0];
      v2132[1] = v2134;
      int * v2136 = v2118->cache_vals;
      int * v2137 = v2118->cache_vals;
      int v2138 = v2137[0];
      v2136[1] = v2138;
      int * v2140 = v2118->cache_keys;
      int v6270 = (int)((unsigned int)(v2122 + 12) >> 2);
      v2140[0] = v6270;
      int * v2142 = v2118->cache_vals;
      v2142[0] = v2131;
      int v2144 = v2118->timer;
      int v6273 = v2144 + 1;
      v2118->timer = v6273;
      v2170 = v2131;
    } else {
      int * v2147 = v2118->mem;
      int v6275 = (int)((unsigned int)(v2122 + 12) >> 2);
      int v2148 = v2147[v6275];
      int * v2149 = v2118->mem;
      int * v2150 = v2118->cache_keys;
      int v2151 = v2150[1];
      int * v2152 = v2118->cache_vals;
      int v2153 = v2152[1];
      v2149[v2151] = v2153;
      int * v2155 = v2118->cache_keys;
      int * v2156 = v2118->cache_keys;
      int v2157 = v2156[0];
      v2155[1] = v2157;
      int * v2159 = v2118->cache_vals;
      int * v2160 = v2118->cache_vals;
      int v2161 = v2160[0];
      v2159[1] = v2161;
      int * v2163 = v2118->cache_keys;
      v2163[0] = v6275;
      int * v2165 = v2118->cache_vals;
      v2165[0] = v2148;
      int v2167 = v2118->timer;
      int v6290 = v2167 + 100;
      v2118->timer = v6290;
      v2170 = v2148;
    }
    v2172 = v2170;
  }
  int * v2173 = v2118->regs;
  v2173[7] = v2172;
  struct StateT * v6249 = v2175(v2118);
  return v6249;
}

struct StateT * v7735(struct StateT * v7736) {
  int v7737 = v7736->timer;
  int v8079 = v7737 + 1;
  v7736->timer = v8079;
  int * v7739 = v7736->regs;
  int v7740 = v7739[11];
  int * v7741 = v7736->regs;
  int v8084 = (int)((unsigned int)v7740 >> 14);
  v7741[9] = v8084;
  struct StateT * v8077 = v7743(v7736);
  return v8077;
}

struct StateT * v6815(struct StateT * v6816) {
  int v6817 = v6816->timer;
  int v9148 = v6817 + 1;
  v6816->timer = v9148;
  int * v6819 = v6816->regs;
  int v6820 = v6819[15];
  int * v6821 = v6816->regs;
  int v9153 = (int)((unsigned int)v6820 >> 19);
  v6821[20] = v9153;
  struct StateT * v9146 = v6823(v6816);
  return v9146;
}

struct StateT * v2715(struct StateT * v2716) {
  int v2717 = v2716->timer;
  int v5753 = v2717 + 1;
  v2716->timer = v5753;
  int * v2719 = v2716->regs;
  int v2720 = v2719[11];
  int * v2721 = v2716->regs;
  int v2722 = v2721[6];
  int * v2723 = v2716->regs;
  int v5759 = v2720 + v2722;
  v2723[11] = v5759;
  struct StateT * v5751 = v2725(v2716);
  return v5751;
}

struct StateT * v7269(struct StateT * v7270) {
  int v7271 = v7270->timer;
  int v8620 = v7271 + 1;
  v7270->timer = v8620;
  int * v7273 = v7270->regs;
  int v7274 = v7273[17];
  int * v7275 = v7270->regs;
  int v8624 = v7274 << 7;
  v7275[17] = v8624;
  struct StateT * v8618 = v7277(v7270);
  return v8618;
}

struct StateT * v6437(struct StateT * v6438) {
  int v6439 = v6438->timer;
  int v9582 = v6439 + 1;
  v6438->timer = v9582;
  int * v6441 = v6438->regs;
  int v6442 = v6441[22];
  int * v6443 = v6438->regs;
  int v6444 = v6443[17];
  int * v6445 = v6438->regs;
  int v9589 = v6442 + v6444;
  v6445[8] = v9589;
  struct StateT * v9580 = v6447(v6438);
  return v9580;
}

struct StateT * v4363(struct StateT * v4364) {
  int v4365 = v4364->timer;
  int v4379 = v4365 + 1;
  v4364->timer = v4379;
  int * v4367 = v4364->regs;
  int v4368 = v4367[2];
  int * v4369 = v4364->regs;
  int v4383 = v4368 + 96;
  v4369[2] = v4383;
  struct StateT * v4377 = v4371(v4364);
  return v4377;
}

struct StateT * v7813(struct StateT * v7814) {
  int v7815 = v7814->timer;
  int v7989 = v7815 + 1;
  v7814->timer = v7989;
  int * v7817 = v7814->regs;
  int v7818 = v7817[8];
  int * v7819 = v7814->regs;
  int v7994 = (int)((unsigned int)v7818 >> 14);
  v7819[9] = v7994;
  struct StateT * v7987 = v7821(v7814);
  return v7987;
}

struct StateT * v7521(struct StateT * v7522) {
  int v7523 = v7522->timer;
  int v8325 = v7523 + 1;
  v7522->timer = v8325;
  int * v7525 = v7522->regs;
  int v7526 = v7525[25];
  int * v7527 = v7522->regs;
  int v7528 = v7527[5];
  int * v7529 = v7522->regs;
  int v8332 = v7526 + v7528;
  v7529[15] = v8332;
  struct StateT * v8323 = v7531(v7522);
  return v8323;
}

struct StateT * v3069(struct StateT * v3070) {
  int v3071 = v3070->timer;
  int v5416 = v3071 + 1;
  v3070->timer = v5416;
  int * v3073 = v3070->regs;
  int v3074 = v3073[10];
  int * v3075 = v3070->regs;
  int v3076 = v3075[5];
  int * v3077 = v3070->cache_keys;
  int v3078 = v3077[0];
  bool v5423 = v3078 == ((int)((unsigned int)(v3074 + 24) >> 2));
  int v3122;
  if (v5423) {
    int * v3079 = v3070->cache_vals;
    v3079[0] = v3076;
    v3122 = v3076;
  } else {
    int * v3082 = v3070->cache_keys;
    int v3083 = v3082[1];
    bool v5428 = v3083 == ((int)((unsigned int)(v3074 + 24) >> 2));
    int v3120;
    if (v5428) {
      int * v3084 = v3070->cache_keys;
      int * v3085 = v3070->cache_keys;
      int v3086 = v3085[0];
      v3084[1] = v3086;
      int * v3088 = v3070->cache_vals;
      int * v3089 = v3070->cache_vals;
      int v3090 = v3089[0];
      v3088[1] = v3090;
      int * v3092 = v3070->cache_keys;
      int v5436 = (int)((unsigned int)(v3074 + 24) >> 2);
      v3092[0] = v5436;
      int * v3094 = v3070->cache_vals;
      v3094[0] = v3076;
      int v3096 = v3070->timer;
      int v5439 = v3096 + 1;
      v3070->timer = v5439;
      v3120 = v3076;
    } else {
      int * v3099 = v3070->mem;
      int * v3100 = v3070->cache_keys;
      int v3101 = v3100[1];
      int * v3102 = v3070->cache_vals;
      int v3103 = v3102[1];
      v3099[v3101] = v3103;
      int * v3105 = v3070->cache_keys;
      int * v3106 = v3070->cache_keys;
      int v3107 = v3106[0];
      v3105[1] = v3107;
      int * v3109 = v3070->cache_vals;
      int * v3110 = v3070->cache_vals;
      int v3111 = v3110[0];
      v3109[1] = v3111;
      int * v3113 = v3070->cache_keys;
      int v5452 = (int)((unsigned int)(v3074 + 24) >> 2);
      v3113[0] = v5452;
      int * v3115 = v3070->cache_vals;
      v3115[0] = v3076;
      int v3117 = v3070->timer;
      int v5455 = v3117 + 100;
      v3070->timer = v5455;
      v3120 = v3076;
    }
    v3122 = v3120;
  }
  struct StateT * v5414 = v3123(v3070);
  return v5414;
}

struct StateT * v2321(struct StateT * v2322) {
  int v2323 = v2322->timer;
  int v6074 = v2323 + 1;
  v2322->timer = v6074;
  int * v2325 = v2322->regs;
  int v2326 = v2325[2];
  int * v2327 = v2322->cache_keys;
  int v2328 = v2327[0];
  bool v6079 = v2328 == ((int)((unsigned int)(v2326 + 24) >> 2));
  int v2376;
  if (v6079) {
    int * v2329 = v2322->cache_vals;
    int v2330 = v2329[0];
    v2376 = v2330;
  } else {
    int * v2332 = v2322->cache_keys;
    int v2333 = v2332[1];
    bool v6084 = v2333 == ((int)((unsigned int)(v2326 + 24) >> 2));
    int v2374;
    if (v6084) {
      int * v2334 = v2322->cache_vals;
      int v2335 = v2334[1];
      int * v2336 = v2322->cache_keys;
      int * v2337 = v2322->cache_keys;
      int v2338 = v2337[0];
      v2336[1] = v2338;
      int * v2340 = v2322->cache_vals;
      int * v2341 = v2322->cache_vals;
      int v2342 = v2341[0];
      v2340[1] = v2342;
      int * v2344 = v2322->cache_keys;
      int v6093 = (int)((unsigned int)(v2326 + 24) >> 2);
      v2344[0] = v6093;
      int * v2346 = v2322->cache_vals;
      v2346[0] = v2335;
      int v2348 = v2322->timer;
      int v6096 = v2348 + 1;
      v2322->timer = v6096;
      v2374 = v2335;
    } else {
      int * v2351 = v2322->mem;
      int v6098 = (int)((unsigned int)(v2326 + 24) >> 2);
      int v2352 = v2351[v6098];
      int * v2353 = v2322->mem;
      int * v2354 = v2322->cache_keys;
      int v2355 = v2354[1];
      int * v2356 = v2322->cache_vals;
      int v2357 = v2356[1];
      v2353[v2355] = v2357;
      int * v2359 = v2322->cache_keys;
      int * v2360 = v2322->cache_keys;
      int v2361 = v2360[0];
      v2359[1] = v2361;
      int * v2363 = v2322->cache_vals;
      int * v2364 = v2322->cache_vals;
      int v2365 = v2364[0];
      v2363[1] = v2365;
      int * v2367 = v2322->cache_keys;
      v2367[0] = v6098;
      int * v2369 = v2322->cache_vals;
      v2369[0] = v2352;
      int v2371 = v2322->timer;
      int v6113 = v2371 + 100;
      v2322->timer = v6113;
      v2374 = v2352;
    }
    v2376 = v2374;
  }
  int * v2377 = v2322->regs;
  v2377[7] = v2376;
  struct StateT * v6072 = v2379(v2322);
  return v6072;
}

struct StateT * v2101(struct StateT * v2102) {
  int v2103 = v2102->timer;
  int v6307 = v2103 + 1;
  v2102->timer = v6307;
  int * v2105 = v2102->regs;
  int v2106 = v2105[12];
  int * v2107 = v2102->regs;
  int v2108 = v2107[6];
  int * v2109 = v2102->regs;
  int v6313 = v2106 + v2108;
  v2109[12] = v6313;
  struct StateT * v6305 = v2111(v2102);
  return v6305;
}

struct StateT * v1923(struct StateT * v1924) {
  int v1925 = v1924->timer;
  int v9708 = v1925 + 1;
  v1924->timer = v9708;
  int * v1927 = v1924->regs;
  int v1928 = v1927[28];
  int * v1929 = v1924->regs;
  v1929[27] = v1928;
  struct StateT * v9706 = v1931(v1924);
  return v9706;
}

struct StateT * v7357(struct StateT * v7358) {
  int v7359 = v7358->timer;
  int v8513 = v7359 + 1;
  v7358->timer = v8513;
  int * v7361 = v7358->regs;
  int v7362 = v7361[16];
  int * v7363 = v7358->regs;
  int v7364 = v7363[22];
  int * v7365 = v7358->regs;
  int v8520 = v7362 + v7364;
  v7365[8] = v8520;
  struct StateT * v8511 = v7367(v7358);
  return v8511;
}

struct StateT * v7393(struct StateT * v7394) {
  int v7395 = v7394->timer;
  int v8473 = v7395 + 1;
  v7394->timer = v8473;
  int * v7397 = v7394->regs;
  int v7398 = v7397[15];
  int * v7399 = v7394->regs;
  int v8478 = (int)((unsigned int)v7398 >> 23);
  v7399[9] = v8478;
  struct StateT * v8471 = v7401(v7394);
  return v8471;
}

struct StateT * v1583(struct StateT * v1584) {
  int v1585 = v1584->timer;
  int v9962 = v1585 + 1;
  v1584->timer = v9962;
  int * v1587 = v1584->regs;
  int v1588 = v1587[2];
  int * v1589 = v1584->regs;
  int v1590 = v1589[5];
  int * v1591 = v1584->cache_keys;
  int v1592 = v1591[0];
  bool v9969 = v1592 == ((int)((unsigned int)(v1588 + 12) >> 2));
  int v1636;
  if (v9969) {
    int * v1593 = v1584->cache_vals;
    v1593[0] = v1590;
    v1636 = v1590;
  } else {
    int * v1596 = v1584->cache_keys;
    int v1597 = v1596[1];
    bool v9974 = v1597 == ((int)((unsigned int)(v1588 + 12) >> 2));
    int v1634;
    if (v9974) {
      int * v1598 = v1584->cache_keys;
      int * v1599 = v1584->cache_keys;
      int v1600 = v1599[0];
      v1598[1] = v1600;
      int * v1602 = v1584->cache_vals;
      int * v1603 = v1584->cache_vals;
      int v1604 = v1603[0];
      v1602[1] = v1604;
      int * v1606 = v1584->cache_keys;
      int v9982 = (int)((unsigned int)(v1588 + 12) >> 2);
      v1606[0] = v9982;
      int * v1608 = v1584->cache_vals;
      v1608[0] = v1590;
      int v1610 = v1584->timer;
      int v9985 = v1610 + 1;
      v1584->timer = v9985;
      v1634 = v1590;
    } else {
      int * v1613 = v1584->mem;
      int * v1614 = v1584->cache_keys;
      int v1615 = v1614[1];
      int * v1616 = v1584->cache_vals;
      int v1617 = v1616[1];
      v1613[v1615] = v1617;
      int * v1619 = v1584->cache_keys;
      int * v1620 = v1584->cache_keys;
      int v1621 = v1620[0];
      v1619[1] = v1621;
      int * v1623 = v1584->cache_vals;
      int * v1624 = v1584->cache_vals;
      int v1625 = v1624[0];
      v1623[1] = v1625;
      int * v1627 = v1584->cache_keys;
      int v9998 = (int)((unsigned int)(v1588 + 12) >> 2);
      v1627[0] = v9998;
      int * v1629 = v1584->cache_vals;
      v1629[0] = v1590;
      int v1631 = v1584->timer;
      int v10001 = v1631 + 100;
      v1584->timer = v10001;
      v1634 = v1590;
    }
    v1636 = v1634;
  }
  struct StateT * v9960 = v1637(v1584);
  return v9960;
}

struct StateT * v7235(struct StateT * v7236) {
  int v7237 = v7236->timer;
  int v8659 = v7237 + 1;
  v7236->timer = v8659;
  int * v7239 = v7236->regs;
  int v7240 = v7239[16];
  int * v7241 = v7236->regs;
  int v8664 = (int)((unsigned int)v7240 >> 25);
  v7241[5] = v8664;
  struct StateT * v8657 = v7243(v7236);
  return v8657;
}

struct StateT * v7025(struct StateT * v7026) {
  int v7027 = v7026->timer;
  int v8902 = v7027 + 1;
  v7026->timer = v8902;
  int * v7029 = v7026->regs;
  int v7030 = v7029[16];
  int * v7031 = v7026->regs;
  int v8907 = (int)((unsigned int)v7030 >> 14);
  v7031[6] = v8907;
  struct StateT * v8900 = v7033(v7026);
  return v8900;
}

struct StateT * v7419(struct StateT * v7420) {
  int v7421 = v7420->timer;
  int v8443 = v7421 + 1;
  v7420->timer = v8443;
  int * v7423 = v7420->regs;
  int v7424 = v7423[6];
  int * v7425 = v7420->regs;
  int v8448 = (int)((unsigned int)v7424 >> 23);
  v7425[9] = v8448;
  struct StateT * v8441 = v7427(v7420);
  return v8441;
}

struct StateT * v1931(struct StateT * v1932) {
  int v1933 = v1932->timer;
  int v9698 = v1933 + 1;
  v1932->timer = v9698;
  int * v1935 = v1932->regs;
  int v1936 = v1935[29];
  int * v1937 = v1932->regs;
  v1937[23] = v1936;
  struct StateT * v9696 = v1939(v1932);
  return v9696;
}

struct StateT * v7445(struct StateT * v7446) {
  int v7447 = v7446->timer;
  int v8413 = v7447 + 1;
  v7446->timer = v8413;
  int * v7449 = v7446->regs;
  int v7450 = v7449[8];
  int * v7451 = v7446->regs;
  int v8418 = (int)((unsigned int)v7450 >> 23);
  v7451[9] = v8418;
  struct StateT * v8411 = v7453(v7446);
  return v8411;
}

struct StateT * v6893(struct StateT * v6894) {
  int v6895 = v6894->timer;
  int v9058 = v6895 + 1;
  v6894->timer = v9058;
  int * v6897 = v6894->regs;
  int v6898 = v6897[18];
  int * v6899 = v6894->regs;
  int v9063 = (int)((unsigned int)v6898 >> 19);
  v6899[9] = v9063;
  struct StateT * v9056 = v6901(v6894);
  return v9056;
}

struct StateT * v7839(struct StateT * v7840) {
  int v7841 = v7840->timer;
  int v7958 = v7841 + 1;
  v7840->timer = v7958;
  int * v7843 = v7840->regs;
  int v7844 = v7843[21];
  int * v7845 = v7840->regs;
  int v7846 = v7845[11];
  int * v7847 = v7840->regs;
  int v7964 = v7844 ^ v7846;
  v7847[21] = v7964;
  struct StateT * v7956 = v7849(v7840);
  return v7956;
}

struct StateT * v7133(struct StateT * v7134) {
  int v7135 = v7134->timer;
  int v8777 = v7135 + 1;
  v7134->timer = v8777;
  int * v7137 = v7134->regs;
  int v7138 = v7137[22];
  int * v7139 = v7134->regs;
  int v7140 = v7139[5];
  int * v7141 = v7134->regs;
  int v8783 = v7138 ^ v7140;
  v7141[22] = v8783;
  struct StateT * v8775 = v7143(v7134);
  return v8775;
}

struct StateT * v1355(struct StateT * v1356) {
  int v1357 = v1356->timer;
  int v10176 = v1357 + 1;
  v1356->timer = v10176;
  int * v1359 = v1356->regs;
  int v1360 = v1359[11];
  int * v1361 = v1356->cache_keys;
  int v1362 = v1361[0];
  bool v10181 = v1362 == ((int)((unsigned int)(v1360 + 12) >> 2));
  int v1410;
  if (v10181) {
    int * v1363 = v1356->cache_vals;
    int v1364 = v1363[0];
    v1410 = v1364;
  } else {
    int * v1366 = v1356->cache_keys;
    int v1367 = v1366[1];
    bool v10186 = v1367 == ((int)((unsigned int)(v1360 + 12) >> 2));
    int v1408;
    if (v10186) {
      int * v1368 = v1356->cache_vals;
      int v1369 = v1368[1];
      int * v1370 = v1356->cache_keys;
      int * v1371 = v1356->cache_keys;
      int v1372 = v1371[0];
      v1370[1] = v1372;
      int * v1374 = v1356->cache_vals;
      int * v1375 = v1356->cache_vals;
      int v1376 = v1375[0];
      v1374[1] = v1376;
      int * v1378 = v1356->cache_keys;
      int v10195 = (int)((unsigned int)(v1360 + 12) >> 2);
      v1378[0] = v10195;
      int * v1380 = v1356->cache_vals;
      v1380[0] = v1369;
      int v1382 = v1356->timer;
      int v10198 = v1382 + 1;
      v1356->timer = v10198;
      v1408 = v1369;
    } else {
      int * v1385 = v1356->mem;
      int v10200 = (int)((unsigned int)(v1360 + 12) >> 2);
      int v1386 = v1385[v10200];
      int * v1387 = v1356->mem;
      int * v1388 = v1356->cache_keys;
      int v1389 = v1388[1];
      int * v1390 = v1356->cache_vals;
      int v1391 = v1390[1];
      v1387[v1389] = v1391;
      int * v1393 = v1356->cache_keys;
      int * v1394 = v1356->cache_keys;
      int v1395 = v1394[0];
      v1393[1] = v1395;
      int * v1397 = v1356->cache_vals;
      int * v1398 = v1356->cache_vals;
      int v1399 = v1398[0];
      v1397[1] = v1399;
      int * v1401 = v1356->cache_keys;
      v1401[0] = v10200;
      int * v1403 = v1356->cache_vals;
      v1403[0] = v1386;
      int v1405 = v1356->timer;
      int v10215 = v1405 + 100;
      v1356->timer = v10215;
      v1408 = v1386;
    }
    v1410 = v1408;
  }
  int * v1411 = v1356->regs;
  v1411[15] = v1410;
  struct StateT * v10174 = v1413(v1356);
  return v10174;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v11351 = v1(v0);
  return v11351;
}

struct StateT * v7551(struct StateT * v7552) {
  int v7553 = v7552->timer;
  int v8291 = v7553 + 1;
  v7552->timer = v8291;
  int * v7555 = v7552->regs;
  int v7556 = v7555[11];
  int * v7557 = v7552->regs;
  int v8296 = (int)((unsigned int)v7556 >> 19);
  v7557[9] = v8296;
  struct StateT * v8289 = v7559(v7552);
  return v8289;
}

struct StateT * v7531(struct StateT * v7532) {
  int v7533 = v7532->timer;
  int v8313 = v7533 + 1;
  v7532->timer = v8313;
  int * v7535 = v7532->regs;
  int v7536 = v7535[26];
  int * v7537 = v7532->regs;
  int v7538 = v7537[17];
  int * v7539 = v7532->regs;
  int v8320 = v7536 + v7538;
  v7539[6] = v8320;
  struct StateT * v8311 = v7541(v7532);
  return v8311;
}

struct StateT * v6849(struct StateT * v6850) {
  int v6851 = v6850->timer;
  int v9109 = v6851 + 1;
  v6850->timer = v9109;
  int * v6853 = v6850->regs;
  int v6854 = v6853[8];
  int * v6855 = v6850->regs;
  int v9113 = v6854 << 13;
  v6855[8] = v9113;
  struct StateT * v9107 = v6857(v6850);
  return v9107;
}

struct StateT * v1(struct StateT * v2) {
  int v3 = v2->timer;
  int v11344 = v3 + 1;
  v2->timer = v11344;
  int * v5 = v2->regs;
  int v6 = v5[2];
  int * v7 = v2->regs;
  int v11348 = v6 + -96;
  v7[2] = v11348;
  struct StateT * v11342 = v9(v2);
  return v11342;
}

struct StateT * v3609(struct StateT * v3610) {
  int v3611 = v3610->timer;
  int v4964 = v3611 + 1;
  v3610->timer = v4964;
  int * v3613 = v3610->regs;
  int v3614 = v3613[2];
  int * v3615 = v3610->cache_keys;
  int v3616 = v3615[0];
  bool v4969 = v3616 == ((int)((unsigned int)(v3614 + 92) >> 2));
  int v3664;
  if (v4969) {
    int * v3617 = v3610->cache_vals;
    int v3618 = v3617[0];
    v3664 = v3618;
  } else {
    int * v3620 = v3610->cache_keys;
    int v3621 = v3620[1];
    bool v4974 = v3621 == ((int)((unsigned int)(v3614 + 92) >> 2));
    int v3662;
    if (v4974) {
      int * v3622 = v3610->cache_vals;
      int v3623 = v3622[1];
      int * v3624 = v3610->cache_keys;
      int * v3625 = v3610->cache_keys;
      int v3626 = v3625[0];
      v3624[1] = v3626;
      int * v3628 = v3610->cache_vals;
      int * v3629 = v3610->cache_vals;
      int v3630 = v3629[0];
      v3628[1] = v3630;
      int * v3632 = v3610->cache_keys;
      int v4983 = (int)((unsigned int)(v3614 + 92) >> 2);
      v3632[0] = v4983;
      int * v3634 = v3610->cache_vals;
      v3634[0] = v3623;
      int v3636 = v3610->timer;
      int v4986 = v3636 + 1;
      v3610->timer = v4986;
      v3662 = v3623;
    } else {
      int * v3639 = v3610->mem;
      int v4988 = (int)((unsigned int)(v3614 + 92) >> 2);
      int v3640 = v3639[v4988];
      int * v3641 = v3610->mem;
      int * v3642 = v3610->cache_keys;
      int v3643 = v3642[1];
      int * v3644 = v3610->cache_vals;
      int v3645 = v3644[1];
      v3641[v3643] = v3645;
      int * v3647 = v3610->cache_keys;
      int * v3648 = v3610->cache_keys;
      int v3649 = v3648[0];
      v3647[1] = v3649;
      int * v3651 = v3610->cache_vals;
      int * v3652 = v3610->cache_vals;
      int v3653 = v3652[0];
      v3651[1] = v3653;
      int * v3655 = v3610->cache_keys;
      v3655[0] = v4988;
      int * v3657 = v3610->cache_vals;
      v3657[0] = v3640;
      int v3659 = v3610->timer;
      int v5003 = v3659 + 100;
      v3610->timer = v5003;
      v3662 = v3640;
    }
    v3664 = v3662;
  }
  int * v3665 = v3610->regs;
  v3665[1] = v3664;
  struct StateT * v4962 = v3667(v3610);
  return v4962;
}

struct StateT * v2673(struct StateT * v2674) {
  int v2675 = v2674->timer;
  int v5802 = v2675 + 1;
  v2674->timer = v5802;
  int * v2677 = v2674->regs;
  int v2678 = v2677[15];
  int * v2679 = v2674->regs;
  int v5806 = v2678 + -1947;
  v2679[15] = v5806;
  struct StateT * v5800 = v2681(v2674);
  return v5800;
}

struct StateT * v3231(struct StateT * v3232) {
  int v3233 = v3232->timer;
  int v5281 = v3233 + 1;
  v3232->timer = v5281;
  int * v3235 = v3232->regs;
  int v3236 = v3235[10];
  int * v3237 = v3232->regs;
  int v3238 = v3237[13];
  int * v3239 = v3232->cache_keys;
  int v3240 = v3239[0];
  bool v5288 = v3240 == ((int)((unsigned int)(v3236 + 36) >> 2));
  int v3284;
  if (v5288) {
    int * v3241 = v3232->cache_vals;
    v3241[0] = v3238;
    v3284 = v3238;
  } else {
    int * v3244 = v3232->cache_keys;
    int v3245 = v3244[1];
    bool v5293 = v3245 == ((int)((unsigned int)(v3236 + 36) >> 2));
    int v3282;
    if (v5293) {
      int * v3246 = v3232->cache_keys;
      int * v3247 = v3232->cache_keys;
      int v3248 = v3247[0];
      v3246[1] = v3248;
      int * v3250 = v3232->cache_vals;
      int * v3251 = v3232->cache_vals;
      int v3252 = v3251[0];
      v3250[1] = v3252;
      int * v3254 = v3232->cache_keys;
      int v5301 = (int)((unsigned int)(v3236 + 36) >> 2);
      v3254[0] = v5301;
      int * v3256 = v3232->cache_vals;
      v3256[0] = v3238;
      int v3258 = v3232->timer;
      int v5304 = v3258 + 1;
      v3232->timer = v5304;
      v3282 = v3238;
    } else {
      int * v3261 = v3232->mem;
      int * v3262 = v3232->cache_keys;
      int v3263 = v3262[1];
      int * v3264 = v3232->cache_vals;
      int v3265 = v3264[1];
      v3261[v3263] = v3265;
      int * v3267 = v3232->cache_keys;
      int * v3268 = v3232->cache_keys;
      int v3269 = v3268[0];
      v3267[1] = v3269;
      int * v3271 = v3232->cache_vals;
      int * v3272 = v3232->cache_vals;
      int v3273 = v3272[0];
      v3271[1] = v3273;
      int * v3275 = v3232->cache_keys;
      int v5317 = (int)((unsigned int)(v3236 + 36) >> 2);
      v3275[0] = v5317;
      int * v3277 = v3232->cache_vals;
      v3277[0] = v3238;
      int v3279 = v3232->timer;
      int v5320 = v3279 + 100;
      v3232->timer = v5320;
      v3282 = v3238;
    }
    v3284 = v3282;
  }
  struct StateT * v5279 = v3285(v3232);
  return v5279;
}

struct StateT * v7277(struct StateT * v7278) {
  int v7279 = v7278->timer;
  int v8608 = v7279 + 1;
  v7278->timer = v8608;
  int * v7281 = v7278->regs;
  int v7282 = v7281[17];
  int * v7283 = v7278->regs;
  int v7284 = v7283[5];
  int * v7285 = v7278->regs;
  int v8615 = v7282 | v7284;
  v7285[6] = v8615;
  struct StateT * v8606 = v7287(v7278);
  return v8606;
}

struct StateT * v2311(struct StateT * v2312) {
  int v2313 = v2312->timer;
  int v6122 = v2313 + 1;
  v2312->timer = v6122;
  int * v2315 = v2312->regs;
  int v2316 = v2315[26];
  int * v2317 = v2312->regs;
  int v2318 = v2317[7];
  int * v2319 = v2312->regs;
  int v6128 = v2316 + v2318;
  v2319[26] = v6128;
  struct StateT * v6120 = v2321(v2312);
  return v6120;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
  }
  s->regs[2] = 4 * MEM_SIZE;
  s->timer = 0;
  for (int i=0; i<MEM_SIZE; i++) {
    s->mem[i] = 0;
  }
  for (int i=0; i<CACHE_LRU_SIZE; i++) {
    s->cache_keys[i] = -1;
    s->cache_vals[i] = -1;
  }
}

int main(int argc, char* argv[]) {
  struct StateT s1, s2;
  init(&s1);
  init(&s2);
  
  // a10, 16 words written by the callee: the address is public
  s1.regs[10] = 0;
  s2.regs[10] = 0;
  // a11, 4 words read by the callee: the address is public
  s1.regs[11] = 64;
  s2.regs[11] = 64;
  // a12, 8 words read by the callee: the address is public
  s1.regs[12] = 80;
  s2.regs[12] = 80;
  
  // a11's contents, secret: a different draw in each state
  for (int i=0; i<4; i++) {
    s1.mem[16 + i] = bounded(0, 20);
    s2.mem[16 + i] = bounded(0, 20);
  }
  // a12's contents, secret: a different draw in each state
  for (int i=0; i<8; i++) {
    s1.mem[20 + i] = bounded(0, 20);
    s2.mem[20 + i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  __CPROVER_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}