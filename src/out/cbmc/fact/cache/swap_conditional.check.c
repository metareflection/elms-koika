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

struct StateT * slot_12(struct StateT * v575);
struct StateT * slot_34(struct StateT * v114);
struct StateT * slot_6(struct StateT * v94);
struct StateT * slot_29(struct StateT * v2197);
struct StateT * slot_25(struct StateT * v2133);
struct StateT * slot_16(struct StateT * v1015);
struct StateT * slot_23(struct StateT * v1913);
struct StateT * slot_5(struct StateT * v80);
struct StateT * slot_2(struct StateT * v29);
struct StateT * slot_7(struct StateT * v119);
struct StateT * slot_21(struct StateT * v1394);
struct StateT * slot_31(struct StateT * v2528);
struct StateT * slot_3(struct StateT * v45);
struct StateT * slot_26(struct StateT * v2149);
struct StateT * slot_10(struct StateT * v167);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_19(struct StateT * v1063);
struct StateT * slot_13(struct StateT * v779);
struct StateT * slot_24(struct StateT * v2117);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v983);
struct StateT * slot_28(struct StateT * v2181);
struct StateT * slot_32(struct StateT * v2843);
struct StateT * slot_17(struct StateT * v1031);
struct StateT * slot_20(struct StateT * v1079);
struct StateT * slot_33(struct StateT * v2857);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v134);
struct StateT * slot_27(struct StateT * v2165);
struct StateT * slot_30(struct StateT * v2213);
struct StateT * slot_4(struct StateT * v58);
struct StateT * slot_15(struct StateT * v999);
struct StateT * slot_18(struct StateT * v1047);
struct StateT * slot_9(struct StateT * v151);
struct StateT * slot_22(struct StateT * v1709);
struct StateT * slot_11(struct StateT * v371);
struct StateT * slot_12(struct StateT * v575) {
  int v576 = v575->timer;
  int v686 = v576 + 1;
  v575->timer = v686;
  int * v578 = v575->regs;
  int v579 = v578[15];
  int * v580 = v575->cache_tags;
  int v690 = (((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1)) & 1) * 2;
  int v581 = v580[v690];
  int v691 = ((((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v582 = v580[v691];
  int v692 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1)) & 3) * 2);
  int v583 = v580[v692];
  int v693 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v584 = v580[v693];
  int v585 = v575->timer;
  int v694 = v585 + ((100 ^ (((~(((v583 ^ ((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1))) | (-(v583 ^ ((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v584 ^ ((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1))) | (-(v584 ^ ((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v581 ^ ((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1))) | (-(v581 ^ ((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v582 ^ ((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1))) | (-(v582 ^ ((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v583 ^ ((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1))) | (-(v583 ^ ((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v584 ^ ((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1))) | (-(v584 ^ ((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v575->timer = v694;
  int * v587 = v575->cache_vals;
  bool v695 = !(((~(((v581 ^ ((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1))) | (-(v581 ^ ((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v582 ^ ((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1))) | (-(v582 ^ ((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v680;
  if (v695) {
    int * v588 = v575->cache_age;
    int v697 = ((((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v582 ^ ((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1))) | (-(v582 ^ ((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v589 = v588[v697];
    int v590 = v588[v690];
    int v698 = v590 + ((int)((unsigned int)(v590 - v589) >> 31));
    v588[v690] = v698;
    int * v592 = v575->cache_age;
    int v593 = v592[v691];
    int v700 = v593 + ((int)((unsigned int)(v593 - v589) >> 31));
    v592[v691] = v700;
    int * v595 = v575->cache_age;
    v595[v697] = 0;
    v680 = v697;
  } else {
    int * v598 = v575->cache_age;
    int v704 = (((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1)) & 1) * 2;
    int v599 = v598[v704];
    int * v600 = v575->cache_tags;
    int v601 = v600[v704];
    int v602 = v598[v691];
    int v603 = v600[v691];
    bool v706 = !(((~(((v583 ^ ((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1))) | (-(v583 ^ ((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v584 ^ ((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1))) | (-(v584 ^ ((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v657;
    if (v706) {
      int * v604 = v575->cache_age;
      int v708 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v584 ^ ((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1))) | (-(v584 ^ ((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v605 = v604[v708];
      int v606 = v604[v692];
      int v709 = v606 + ((int)((unsigned int)(v606 - v605) >> 31));
      v604[v692] = v709;
      int * v608 = v575->cache_age;
      int v609 = v608[v693];
      int v711 = v609 + ((int)((unsigned int)(v609 - v605) >> 31));
      v608[v693] = v711;
      int * v611 = v575->cache_age;
      v611[v708] = 0;
      v657 = v708;
    } else {
      int * v614 = v575->cache_age;
      int v715 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1)) & 3) * 2);
      int v615 = v614[v715];
      int * v616 = v575->cache_tags;
      int v617 = v616[v715];
      int v618 = v614[v693];
      int v619 = v616[v693];
      int * v620 = v575->cache_dirty;
      int v718 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v615 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2)) - (v618 + ((~(((v619 ^ -1) | (-(v619 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v621 = v620[v718];
      bool v719 = !(v621 == 0);
      if (v719) {
        int * v622 = v575->cache_tags;
        int v623 = v622[v718];
        int * v624 = v575->cache_vals;
        int v722 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v615 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2)) - (v618 + ((~(((v619 ^ -1) | (-(v619 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v625 = v624[v722];
        int v723 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v615 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2)) - (v618 + ((~(((v619 ^ -1) | (-(v619 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v626 = v624[v723];
        int * v627 = v575->mem;
        int v725 = v623 * 2;
        v627[v725] = v625;
        int * v629 = v575->mem;
        int v728 = (v623 * 2) + 1;
        v629[v728] = v626;
        ;
      } else {
        ;
      }
      int * v634 = v575->mem;
      int v733 = ((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1)) * 2;
      int v635 = v634[v733];
      int v734 = (((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1)) * 2) + 1;
      int v636 = v634[v734];
      int * v637 = v575->cache_vals;
      int v736 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v615 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2)) - (v618 + ((~(((v619 ^ -1) | (-(v619 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v637[v736] = v635;
      int * v639 = v575->cache_vals;
      int v739 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v615 + ((~(((v617 ^ -1) | (-(v617 ^ -1))) >> 31)) & 2)) - (v618 + ((~(((v619 ^ -1) | (-(v619 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v639[v739] = v636;
      int * v641 = v575->cache_tags;
      int v742 = (int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1);
      v641[v718] = v742;
      int * v643 = v575->cache_dirty;
      v643[v718] = 0;
      int * v645 = v575->cache_age;
      v645[v718] = 1;
      int * v647 = v575->cache_age;
      int v648 = v647[v718];
      int v649 = v647[v692];
      int v748 = v649 + ((int)((unsigned int)(v649 - v648) >> 31));
      v647[v692] = v748;
      int * v651 = v575->cache_age;
      int v652 = v651[v693];
      int v750 = v652 + ((int)((unsigned int)(v652 - v648) >> 31));
      v651[v693] = v750;
      int * v654 = v575->cache_age;
      v654[v718] = 0;
      v657 = v718;
    }
    int * v658 = v575->cache_vals;
    int v753 = v657 * 2;
    int v659 = v658[v753];
    int v754 = (v657 * 2) + 1;
    int v660 = v658[v754];
    int v755 = (((((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v599 + ((~(((v601 ^ -1) | (-(v601 ^ -1))) >> 31)) & 2)) - (v602 + ((~(((v603 ^ -1) | (-(v603 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v658[v755] = v659;
    int * v662 = v575->cache_vals;
    int v758 = ((((((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v599 + ((~(((v601 ^ -1) | (-(v601 ^ -1))) >> 31)) & 2)) - (v602 + ((~(((v603 ^ -1) | (-(v603 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v662[v758] = v660;
    int * v664 = v575->cache_tags;
    int v761 = ((((int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v599 + ((~(((v601 ^ -1) | (-(v601 ^ -1))) >> 31)) & 2)) - (v602 + ((~(((v603 ^ -1) | (-(v603 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v762 = (int)((unsigned int)((int)((unsigned int)(v579 + 4) >> 2)) >> 1);
    v664[v761] = v762;
    int * v666 = v575->cache_dirty;
    v666[v761] = 0;
    int * v668 = v575->cache_age;
    v668[v761] = 1;
    int * v670 = v575->cache_age;
    int v671 = v670[v761];
    int v672 = v670[v690];
    int v768 = v672 + ((int)((unsigned int)(v672 - v671) >> 31));
    v670[v690] = v768;
    int * v674 = v575->cache_age;
    int v675 = v674[v691];
    int v770 = v675 + ((int)((unsigned int)(v675 - v671) >> 31));
    v674[v691] = v770;
    int * v677 = v575->cache_age;
    v677[v761] = 0;
    v680 = v761;
  }
  int v773 = (v680 * 2) + (((int)((unsigned int)(v579 + 4) >> 2)) & 1);
  int v681 = v587[v773];
  int * v682 = v575->regs;
  v682[6] = v681;
  struct StateT * v684 = slot_13(v575);
  return v684;
}

struct StateT * slot_34(struct StateT * v114) {
  int v115 = v114->timer;
  int v118 = v115 + 1;
  v114->timer = v118;
  return v114;
}

struct StateT * slot_6(struct StateT * v94) {
  int v95 = v94->timer;
  int v105 = v95 + 1;
  v94->timer = v105;
  int * v97 = v94->regs;
  int v98 = v97[12];
  bool v108 = (v98 ^ -2147483648) < -2147483648;
  struct StateT * v103;
  if (v108) {
    struct StateT * v99 = slot_34(v94);
    v103 = v99;
  } else {
    struct StateT * v101 = slot_7(v94);
    v103 = v101;
  }
  return v103;
}

struct StateT * slot_29(struct StateT * v2197) {
  int v2198 = v2197->timer;
  int v2206 = v2198 + 1;
  v2197->timer = v2206;
  int * v2200 = v2197->regs;
  int v2201 = v2200[6];
  int v2202 = v2200[17];
  int v2210 = v2201 ^ v2202;
  v2200[17] = v2210;
  struct StateT * v2204 = slot_30(v2197);
  return v2204;
}

struct StateT * slot_25(struct StateT * v2133) {
  int v2134 = v2133->timer;
  int v2142 = v2134 + 1;
  v2133->timer = v2142;
  int * v2136 = v2133->regs;
  int v2137 = v2136[17];
  int v2138 = v2136[6];
  int v2146 = v2137 ^ v2138;
  v2136[17] = v2146;
  struct StateT * v2140 = slot_26(v2133);
  return v2140;
}

struct StateT * slot_16(struct StateT * v1015) {
  int v1016 = v1015->timer;
  int v1024 = v1016 + 1;
  v1015->timer = v1024;
  int * v1018 = v1015->regs;
  int v1019 = v1018[13];
  int v1020 = v1018[7];
  int v1028 = v1019 & v1020;
  v1018[7] = v1028;
  struct StateT * v1022 = slot_17(v1015);
  return v1022;
}

struct StateT * slot_23(struct StateT * v1913) {
  int v1914 = v1913->timer;
  int v2024 = v1914 + 1;
  v1913->timer = v2024;
  int * v1916 = v1913->regs;
  int v1917 = v1916[15];
  int * v1918 = v1913->cache_tags;
  int v2028 = (((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1)) & 1) * 2;
  int v1919 = v1918[v2028];
  int v2029 = ((((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1920 = v1918[v2029];
  int v2030 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1)) & 3) * 2);
  int v1921 = v1918[v2030];
  int v2031 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1922 = v1918[v2031];
  int v1923 = v1913->timer;
  int v2032 = v1923 + ((100 ^ (((~(((v1921 ^ ((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1))) | (-(v1921 ^ ((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1))))) >> 31)) | (~(((v1922 ^ ((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1))) | (-(v1922 ^ ((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1919 ^ ((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1))) | (-(v1919 ^ ((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1))))) >> 31)) | (~(((v1920 ^ ((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1))) | (-(v1920 ^ ((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1921 ^ ((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1))) | (-(v1921 ^ ((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1))))) >> 31)) | (~(((v1922 ^ ((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1))) | (-(v1922 ^ ((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1913->timer = v2032;
  int * v1925 = v1913->cache_vals;
  bool v2033 = !(((~(((v1919 ^ ((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1))) | (-(v1919 ^ ((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1))))) >> 31)) | (~(((v1920 ^ ((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1))) | (-(v1920 ^ ((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1))))) >> 31))) == 0);
  int v2018;
  if (v2033) {
    int * v1926 = v1913->cache_age;
    int v2035 = ((((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1)) & 1) * 2) + ((~(((v1920 ^ ((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1))) | (-(v1920 ^ ((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1))))) >> 31)) & 1);
    int v1927 = v1926[v2035];
    int v1928 = v1926[v2028];
    int v2036 = v1928 + ((int)((unsigned int)(v1928 - v1927) >> 31));
    v1926[v2028] = v2036;
    int * v1930 = v1913->cache_age;
    int v1931 = v1930[v2029];
    int v2038 = v1931 + ((int)((unsigned int)(v1931 - v1927) >> 31));
    v1930[v2029] = v2038;
    int * v1933 = v1913->cache_age;
    v1933[v2035] = 0;
    v2018 = v2035;
  } else {
    int * v1936 = v1913->cache_age;
    int v2042 = (((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1)) & 1) * 2;
    int v1937 = v1936[v2042];
    int * v1938 = v1913->cache_tags;
    int v1939 = v1938[v2042];
    int v1940 = v1936[v2029];
    int v1941 = v1938[v2029];
    bool v2044 = !(((~(((v1921 ^ ((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1))) | (-(v1921 ^ ((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1))))) >> 31)) | (~(((v1922 ^ ((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1))) | (-(v1922 ^ ((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1))))) >> 31))) == 0);
    int v1995;
    if (v2044) {
      int * v1942 = v1913->cache_age;
      int v2046 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1922 ^ ((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1))) | (-(v1922 ^ ((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1))))) >> 31)) & 1);
      int v1943 = v1942[v2046];
      int v1944 = v1942[v2030];
      int v2047 = v1944 + ((int)((unsigned int)(v1944 - v1943) >> 31));
      v1942[v2030] = v2047;
      int * v1946 = v1913->cache_age;
      int v1947 = v1946[v2031];
      int v2049 = v1947 + ((int)((unsigned int)(v1947 - v1943) >> 31));
      v1946[v2031] = v2049;
      int * v1949 = v1913->cache_age;
      v1949[v2046] = 0;
      v1995 = v2046;
    } else {
      int * v1952 = v1913->cache_age;
      int v2053 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1)) & 3) * 2);
      int v1953 = v1952[v2053];
      int * v1954 = v1913->cache_tags;
      int v1955 = v1954[v2053];
      int v1956 = v1952[v2031];
      int v1957 = v1954[v2031];
      int * v1958 = v1913->cache_dirty;
      int v2056 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1)) & 3) * 2)) + ((((v1953 + ((~(((v1955 ^ -1) | (-(v1955 ^ -1))) >> 31)) & 2)) - (v1956 + ((~(((v1957 ^ -1) | (-(v1957 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1959 = v1958[v2056];
      bool v2057 = !(v1959 == 0);
      if (v2057) {
        int * v1960 = v1913->cache_tags;
        int v1961 = v1960[v2056];
        int * v1962 = v1913->cache_vals;
        int v2060 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1)) & 3) * 2)) + ((((v1953 + ((~(((v1955 ^ -1) | (-(v1955 ^ -1))) >> 31)) & 2)) - (v1956 + ((~(((v1957 ^ -1) | (-(v1957 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1963 = v1962[v2060];
        int v2061 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1)) & 3) * 2)) + ((((v1953 + ((~(((v1955 ^ -1) | (-(v1955 ^ -1))) >> 31)) & 2)) - (v1956 + ((~(((v1957 ^ -1) | (-(v1957 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1964 = v1962[v2061];
        int * v1965 = v1913->mem;
        int v2063 = v1961 * 2;
        v1965[v2063] = v1963;
        int * v1967 = v1913->mem;
        int v2066 = (v1961 * 2) + 1;
        v1967[v2066] = v1964;
        ;
      } else {
        ;
      }
      int * v1972 = v1913->mem;
      int v2071 = ((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1)) * 2;
      int v1973 = v1972[v2071];
      int v2072 = (((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1)) * 2) + 1;
      int v1974 = v1972[v2072];
      int * v1975 = v1913->cache_vals;
      int v2074 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1)) & 3) * 2)) + ((((v1953 + ((~(((v1955 ^ -1) | (-(v1955 ^ -1))) >> 31)) & 2)) - (v1956 + ((~(((v1957 ^ -1) | (-(v1957 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1975[v2074] = v1973;
      int * v1977 = v1913->cache_vals;
      int v2077 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1)) & 3) * 2)) + ((((v1953 + ((~(((v1955 ^ -1) | (-(v1955 ^ -1))) >> 31)) & 2)) - (v1956 + ((~(((v1957 ^ -1) | (-(v1957 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1977[v2077] = v1974;
      int * v1979 = v1913->cache_tags;
      int v2080 = (int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1);
      v1979[v2056] = v2080;
      int * v1981 = v1913->cache_dirty;
      v1981[v2056] = 0;
      int * v1983 = v1913->cache_age;
      v1983[v2056] = 1;
      int * v1985 = v1913->cache_age;
      int v1986 = v1985[v2056];
      int v1987 = v1985[v2030];
      int v2086 = v1987 + ((int)((unsigned int)(v1987 - v1986) >> 31));
      v1985[v2030] = v2086;
      int * v1989 = v1913->cache_age;
      int v1990 = v1989[v2031];
      int v2088 = v1990 + ((int)((unsigned int)(v1990 - v1986) >> 31));
      v1989[v2031] = v2088;
      int * v1992 = v1913->cache_age;
      v1992[v2056] = 0;
      v1995 = v2056;
    }
    int * v1996 = v1913->cache_vals;
    int v2091 = v1995 * 2;
    int v1997 = v1996[v2091];
    int v2092 = (v1995 * 2) + 1;
    int v1998 = v1996[v2092];
    int v2093 = (((((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1)) & 1) * 2) + ((((v1937 + ((~(((v1939 ^ -1) | (-(v1939 ^ -1))) >> 31)) & 2)) - (v1940 + ((~(((v1941 ^ -1) | (-(v1941 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1996[v2093] = v1997;
    int * v2000 = v1913->cache_vals;
    int v2096 = ((((((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1)) & 1) * 2) + ((((v1937 + ((~(((v1939 ^ -1) | (-(v1939 ^ -1))) >> 31)) & 2)) - (v1940 + ((~(((v1941 ^ -1) | (-(v1941 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2000[v2096] = v1998;
    int * v2002 = v1913->cache_tags;
    int v2099 = ((((int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1)) & 1) * 2) + ((((v1937 + ((~(((v1939 ^ -1) | (-(v1939 ^ -1))) >> 31)) & 2)) - (v1940 + ((~(((v1941 ^ -1) | (-(v1941 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2100 = (int)((unsigned int)((int)((unsigned int)v1917 >> 2)) >> 1);
    v2002[v2099] = v2100;
    int * v2004 = v1913->cache_dirty;
    v2004[v2099] = 0;
    int * v2006 = v1913->cache_age;
    v2006[v2099] = 1;
    int * v2008 = v1913->cache_age;
    int v2009 = v2008[v2099];
    int v2010 = v2008[v2028];
    int v2106 = v2010 + ((int)((unsigned int)(v2010 - v2009) >> 31));
    v2008[v2028] = v2106;
    int * v2012 = v1913->cache_age;
    int v2013 = v2012[v2029];
    int v2108 = v2013 + ((int)((unsigned int)(v2013 - v2009) >> 31));
    v2012[v2029] = v2108;
    int * v2015 = v1913->cache_age;
    v2015[v2099] = 0;
    v2018 = v2099;
  }
  int v2111 = (v2018 * 2) + (((int)((unsigned int)v1917 >> 2)) & 1);
  int v2019 = v1925[v2111];
  int * v2020 = v1913->regs;
  v2020[6] = v2019;
  struct StateT * v2022 = slot_24(v1913);
  return v2022;
}

struct StateT * slot_5(struct StateT * v80) {
  int v81 = v80->timer;
  int v88 = v81 + 1;
  v80->timer = v88;
  int * v83 = v80->regs;
  int v84 = v83[13];
  int v91 = v84 + -1;
  v83[13] = v91;
  struct StateT * v86 = slot_6(v80);
  return v86;
}

struct StateT * slot_2(struct StateT * v29) {
  int v30 = v29->timer;
  int v38 = v30 + 1;
  v29->timer = v38;
  int * v32 = v29->regs;
  int v33 = v32[12];
  int v34 = v32[13];
  int v42 = v33 | v34;
  v32[13] = v42;
  struct StateT * v36 = slot_3(v29);
  return v36;
}

struct StateT * slot_7(struct StateT * v119) {
  int v120 = v119->timer;
  int v127 = v120 + 1;
  v119->timer = v127;
  int * v122 = v119->regs;
  int v123 = v122[14];
  int v131 = v123 << 3;
  v122[15] = v131;
  struct StateT * v125 = slot_8(v119);
  return v125;
}

struct StateT * slot_21(struct StateT * v1394) {
  int v1395 = v1394->timer;
  int v1565 = v1395 + 1;
  v1394->timer = v1565;
  int * v1397 = v1394->regs;
  int v1398 = v1397[16];
  int v1399 = v1397[6];
  int * v1400 = v1394->cache_tags;
  int v1570 = (((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1)) & 1) * 2;
  int v1401 = v1400[v1570];
  int v1571 = ((((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1402 = v1400[v1571];
  int v1572 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1)) & 3) * 2);
  int v1403 = v1400[v1572];
  int v1573 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1404 = v1400[v1573];
  int v1405 = v1394->timer;
  int v1574 = v1405 + ((100 ^ (((~(((v1403 ^ ((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1))) | (-(v1403 ^ ((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1404 ^ ((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1))) | (-(v1404 ^ ((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1401 ^ ((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1))) | (-(v1401 ^ ((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1402 ^ ((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1))) | (-(v1402 ^ ((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1403 ^ ((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1))) | (-(v1403 ^ ((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1404 ^ ((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1))) | (-(v1404 ^ ((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1394->timer = v1574;
  bool v1575 = !(((~(((v1401 ^ ((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1))) | (-(v1401 ^ ((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1402 ^ ((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1))) | (-(v1402 ^ ((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v1499;
  if (v1575) {
    int * v1407 = v1394->cache_age;
    int v1577 = ((((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v1402 ^ ((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1))) | (-(v1402 ^ ((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v1408 = v1407[v1577];
    int v1409 = v1407[v1570];
    int v1578 = v1409 + ((int)((unsigned int)(v1409 - v1408) >> 31));
    v1407[v1570] = v1578;
    int * v1411 = v1394->cache_age;
    int v1412 = v1411[v1571];
    int v1580 = v1412 + ((int)((unsigned int)(v1412 - v1408) >> 31));
    v1411[v1571] = v1580;
    int * v1414 = v1394->cache_age;
    v1414[v1577] = 0;
    v1499 = v1577;
  } else {
    int * v1417 = v1394->cache_age;
    int v1584 = (((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1)) & 1) * 2;
    int v1418 = v1417[v1584];
    int * v1419 = v1394->cache_tags;
    int v1420 = v1419[v1584];
    int v1421 = v1417[v1571];
    int v1422 = v1419[v1571];
    bool v1586 = !(((~(((v1403 ^ ((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1))) | (-(v1403 ^ ((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1404 ^ ((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1))) | (-(v1404 ^ ((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v1476;
    if (v1586) {
      int * v1423 = v1394->cache_age;
      int v1588 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1404 ^ ((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1))) | (-(v1404 ^ ((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v1424 = v1423[v1588];
      int v1425 = v1423[v1572];
      int v1589 = v1425 + ((int)((unsigned int)(v1425 - v1424) >> 31));
      v1423[v1572] = v1589;
      int * v1427 = v1394->cache_age;
      int v1428 = v1427[v1573];
      int v1591 = v1428 + ((int)((unsigned int)(v1428 - v1424) >> 31));
      v1427[v1573] = v1591;
      int * v1430 = v1394->cache_age;
      v1430[v1588] = 0;
      v1476 = v1588;
    } else {
      int * v1433 = v1394->cache_age;
      int v1595 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1)) & 3) * 2);
      int v1434 = v1433[v1595];
      int * v1435 = v1394->cache_tags;
      int v1436 = v1435[v1595];
      int v1437 = v1433[v1573];
      int v1438 = v1435[v1573];
      int * v1439 = v1394->cache_dirty;
      int v1598 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1434 + ((~(((v1436 ^ -1) | (-(v1436 ^ -1))) >> 31)) & 2)) - (v1437 + ((~(((v1438 ^ -1) | (-(v1438 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1440 = v1439[v1598];
      bool v1599 = !(v1440 == 0);
      if (v1599) {
        int * v1441 = v1394->cache_tags;
        int v1442 = v1441[v1598];
        int * v1443 = v1394->cache_vals;
        int v1602 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1434 + ((~(((v1436 ^ -1) | (-(v1436 ^ -1))) >> 31)) & 2)) - (v1437 + ((~(((v1438 ^ -1) | (-(v1438 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1444 = v1443[v1602];
        int v1603 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1434 + ((~(((v1436 ^ -1) | (-(v1436 ^ -1))) >> 31)) & 2)) - (v1437 + ((~(((v1438 ^ -1) | (-(v1438 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1445 = v1443[v1603];
        int * v1446 = v1394->mem;
        int v1605 = v1442 * 2;
        v1446[v1605] = v1444;
        int * v1448 = v1394->mem;
        int v1608 = (v1442 * 2) + 1;
        v1448[v1608] = v1445;
        ;
      } else {
        ;
      }
      int * v1453 = v1394->mem;
      int v1613 = ((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1)) * 2;
      int v1454 = v1453[v1613];
      int v1614 = (((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1)) * 2) + 1;
      int v1455 = v1453[v1614];
      int * v1456 = v1394->cache_vals;
      int v1616 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1434 + ((~(((v1436 ^ -1) | (-(v1436 ^ -1))) >> 31)) & 2)) - (v1437 + ((~(((v1438 ^ -1) | (-(v1438 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1456[v1616] = v1454;
      int * v1458 = v1394->cache_vals;
      int v1619 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1434 + ((~(((v1436 ^ -1) | (-(v1436 ^ -1))) >> 31)) & 2)) - (v1437 + ((~(((v1438 ^ -1) | (-(v1438 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1458[v1619] = v1455;
      int * v1460 = v1394->cache_tags;
      int v1622 = (int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1);
      v1460[v1598] = v1622;
      int * v1462 = v1394->cache_dirty;
      v1462[v1598] = 0;
      int * v1464 = v1394->cache_age;
      v1464[v1598] = 1;
      int * v1466 = v1394->cache_age;
      int v1467 = v1466[v1598];
      int v1468 = v1466[v1572];
      int v1628 = v1468 + ((int)((unsigned int)(v1468 - v1467) >> 31));
      v1466[v1572] = v1628;
      int * v1470 = v1394->cache_age;
      int v1471 = v1470[v1573];
      int v1630 = v1471 + ((int)((unsigned int)(v1471 - v1467) >> 31));
      v1470[v1573] = v1630;
      int * v1473 = v1394->cache_age;
      v1473[v1598] = 0;
      v1476 = v1598;
    }
    int * v1477 = v1394->cache_vals;
    int v1633 = v1476 * 2;
    int v1478 = v1477[v1633];
    int v1634 = (v1476 * 2) + 1;
    int v1479 = v1477[v1634];
    int v1635 = (((((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1418 + ((~(((v1420 ^ -1) | (-(v1420 ^ -1))) >> 31)) & 2)) - (v1421 + ((~(((v1422 ^ -1) | (-(v1422 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1477[v1635] = v1478;
    int * v1481 = v1394->cache_vals;
    int v1638 = ((((((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1418 + ((~(((v1420 ^ -1) | (-(v1420 ^ -1))) >> 31)) & 2)) - (v1421 + ((~(((v1422 ^ -1) | (-(v1422 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1481[v1638] = v1479;
    int * v1483 = v1394->cache_tags;
    int v1641 = ((((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1418 + ((~(((v1420 ^ -1) | (-(v1420 ^ -1))) >> 31)) & 2)) - (v1421 + ((~(((v1422 ^ -1) | (-(v1422 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1642 = (int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1);
    v1483[v1641] = v1642;
    int * v1485 = v1394->cache_dirty;
    v1485[v1641] = 0;
    int * v1487 = v1394->cache_age;
    v1487[v1641] = 1;
    int * v1489 = v1394->cache_age;
    int v1490 = v1489[v1641];
    int v1491 = v1489[v1570];
    int v1648 = v1491 + ((int)((unsigned int)(v1491 - v1490) >> 31));
    v1489[v1570] = v1648;
    int * v1493 = v1394->cache_age;
    int v1494 = v1493[v1571];
    int v1650 = v1494 + ((int)((unsigned int)(v1494 - v1490) >> 31));
    v1493[v1571] = v1650;
    int * v1496 = v1394->cache_age;
    v1496[v1641] = 0;
    v1499 = v1641;
  }
  int * v1500 = v1394->cache_vals;
  int v1653 = (v1499 * 2) + (((int)((unsigned int)(v1398 + 4) >> 2)) & 1);
  v1500[v1653] = v1399;
  int * v1502 = v1394->cache_tags;
  int v1503 = v1502[v1572];
  int v1504 = v1502[v1573];
  bool v1656 = !(((~(((v1503 ^ ((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1))) | (-(v1503 ^ ((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1504 ^ ((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1))) | (-(v1504 ^ ((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v1558;
  if (v1656) {
    int * v1505 = v1394->cache_age;
    int v1658 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1504 ^ ((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1))) | (-(v1504 ^ ((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v1506 = v1505[v1658];
    int v1507 = v1505[v1572];
    int v1659 = v1507 + ((int)((unsigned int)(v1507 - v1506) >> 31));
    v1505[v1572] = v1659;
    int * v1509 = v1394->cache_age;
    int v1510 = v1509[v1573];
    int v1661 = v1510 + ((int)((unsigned int)(v1510 - v1506) >> 31));
    v1509[v1573] = v1661;
    int * v1512 = v1394->cache_age;
    v1512[v1658] = 0;
    v1558 = v1658;
  } else {
    int * v1515 = v1394->cache_age;
    int v1665 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1)) & 3) * 2);
    int v1516 = v1515[v1665];
    int * v1517 = v1394->cache_tags;
    int v1518 = v1517[v1665];
    int v1519 = v1515[v1573];
    int v1520 = v1517[v1573];
    int * v1521 = v1394->cache_dirty;
    int v1668 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1516 + ((~(((v1518 ^ -1) | (-(v1518 ^ -1))) >> 31)) & 2)) - (v1519 + ((~(((v1520 ^ -1) | (-(v1520 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1522 = v1521[v1668];
    bool v1669 = !(v1522 == 0);
    if (v1669) {
      int * v1523 = v1394->cache_tags;
      int v1524 = v1523[v1668];
      int * v1525 = v1394->cache_vals;
      int v1672 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1516 + ((~(((v1518 ^ -1) | (-(v1518 ^ -1))) >> 31)) & 2)) - (v1519 + ((~(((v1520 ^ -1) | (-(v1520 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1526 = v1525[v1672];
      int v1673 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1516 + ((~(((v1518 ^ -1) | (-(v1518 ^ -1))) >> 31)) & 2)) - (v1519 + ((~(((v1520 ^ -1) | (-(v1520 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1527 = v1525[v1673];
      int * v1528 = v1394->mem;
      int v1675 = v1524 * 2;
      v1528[v1675] = v1526;
      int * v1530 = v1394->mem;
      int v1678 = (v1524 * 2) + 1;
      v1530[v1678] = v1527;
      ;
    } else {
      ;
    }
    int * v1535 = v1394->mem;
    int v1683 = ((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1)) * 2;
    int v1536 = v1535[v1683];
    int v1684 = (((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1)) * 2) + 1;
    int v1537 = v1535[v1684];
    int * v1538 = v1394->cache_vals;
    int v1686 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1516 + ((~(((v1518 ^ -1) | (-(v1518 ^ -1))) >> 31)) & 2)) - (v1519 + ((~(((v1520 ^ -1) | (-(v1520 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1538[v1686] = v1536;
    int * v1540 = v1394->cache_vals;
    int v1689 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1516 + ((~(((v1518 ^ -1) | (-(v1518 ^ -1))) >> 31)) & 2)) - (v1519 + ((~(((v1520 ^ -1) | (-(v1520 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1540[v1689] = v1537;
    int * v1542 = v1394->cache_tags;
    int v1692 = (int)((unsigned int)((int)((unsigned int)(v1398 + 4) >> 2)) >> 1);
    v1542[v1668] = v1692;
    int * v1544 = v1394->cache_dirty;
    v1544[v1668] = 0;
    int * v1546 = v1394->cache_age;
    v1546[v1668] = 1;
    int * v1548 = v1394->cache_age;
    int v1549 = v1548[v1668];
    int v1550 = v1548[v1572];
    int v1698 = v1550 + ((int)((unsigned int)(v1550 - v1549) >> 31));
    v1548[v1572] = v1698;
    int * v1552 = v1394->cache_age;
    int v1553 = v1552[v1573];
    int v1700 = v1553 + ((int)((unsigned int)(v1553 - v1549) >> 31));
    v1552[v1573] = v1700;
    int * v1555 = v1394->cache_age;
    v1555[v1668] = 0;
    v1558 = v1668;
  }
  int * v1559 = v1394->cache_vals;
  int v1703 = (v1558 * 2) + (((int)((unsigned int)(v1398 + 4) >> 2)) & 1);
  v1559[v1703] = v1399;
  int * v1561 = v1394->cache_dirty;
  v1561[v1558] = 1;
  struct StateT * v1563 = slot_22(v1394);
  return v1563;
}

struct StateT * slot_31(struct StateT * v2528) {
  int v2529 = v2528->timer;
  int v2699 = v2529 + 1;
  v2528->timer = v2699;
  int * v2531 = v2528->regs;
  int v2532 = v2531[15];
  int v2533 = v2531[16];
  int * v2534 = v2528->cache_tags;
  int v2704 = (((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1)) & 1) * 2;
  int v2535 = v2534[v2704];
  int v2705 = ((((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2536 = v2534[v2705];
  int v2706 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1)) & 3) * 2);
  int v2537 = v2534[v2706];
  int v2707 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2538 = v2534[v2707];
  int v2539 = v2528->timer;
  int v2708 = v2539 + ((100 ^ (((~(((v2537 ^ ((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1))) | (-(v2537 ^ ((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2538 ^ ((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1))) | (-(v2538 ^ ((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2535 ^ ((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1))) | (-(v2535 ^ ((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2536 ^ ((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1))) | (-(v2536 ^ ((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2537 ^ ((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1))) | (-(v2537 ^ ((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2538 ^ ((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1))) | (-(v2538 ^ ((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2528->timer = v2708;
  bool v2709 = !(((~(((v2535 ^ ((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1))) | (-(v2535 ^ ((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2536 ^ ((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1))) | (-(v2536 ^ ((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v2633;
  if (v2709) {
    int * v2541 = v2528->cache_age;
    int v2711 = ((((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v2536 ^ ((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1))) | (-(v2536 ^ ((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v2542 = v2541[v2711];
    int v2543 = v2541[v2704];
    int v2712 = v2543 + ((int)((unsigned int)(v2543 - v2542) >> 31));
    v2541[v2704] = v2712;
    int * v2545 = v2528->cache_age;
    int v2546 = v2545[v2705];
    int v2714 = v2546 + ((int)((unsigned int)(v2546 - v2542) >> 31));
    v2545[v2705] = v2714;
    int * v2548 = v2528->cache_age;
    v2548[v2711] = 0;
    v2633 = v2711;
  } else {
    int * v2551 = v2528->cache_age;
    int v2718 = (((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1)) & 1) * 2;
    int v2552 = v2551[v2718];
    int * v2553 = v2528->cache_tags;
    int v2554 = v2553[v2718];
    int v2555 = v2551[v2705];
    int v2556 = v2553[v2705];
    bool v2720 = !(((~(((v2537 ^ ((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1))) | (-(v2537 ^ ((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2538 ^ ((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1))) | (-(v2538 ^ ((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v2610;
    if (v2720) {
      int * v2557 = v2528->cache_age;
      int v2722 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2538 ^ ((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1))) | (-(v2538 ^ ((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v2558 = v2557[v2722];
      int v2559 = v2557[v2706];
      int v2723 = v2559 + ((int)((unsigned int)(v2559 - v2558) >> 31));
      v2557[v2706] = v2723;
      int * v2561 = v2528->cache_age;
      int v2562 = v2561[v2707];
      int v2725 = v2562 + ((int)((unsigned int)(v2562 - v2558) >> 31));
      v2561[v2707] = v2725;
      int * v2564 = v2528->cache_age;
      v2564[v2722] = 0;
      v2610 = v2722;
    } else {
      int * v2567 = v2528->cache_age;
      int v2729 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1)) & 3) * 2);
      int v2568 = v2567[v2729];
      int * v2569 = v2528->cache_tags;
      int v2570 = v2569[v2729];
      int v2571 = v2567[v2707];
      int v2572 = v2569[v2707];
      int * v2573 = v2528->cache_dirty;
      int v2732 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2568 + ((~(((v2570 ^ -1) | (-(v2570 ^ -1))) >> 31)) & 2)) - (v2571 + ((~(((v2572 ^ -1) | (-(v2572 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2574 = v2573[v2732];
      bool v2733 = !(v2574 == 0);
      if (v2733) {
        int * v2575 = v2528->cache_tags;
        int v2576 = v2575[v2732];
        int * v2577 = v2528->cache_vals;
        int v2736 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2568 + ((~(((v2570 ^ -1) | (-(v2570 ^ -1))) >> 31)) & 2)) - (v2571 + ((~(((v2572 ^ -1) | (-(v2572 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2578 = v2577[v2736];
        int v2737 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2568 + ((~(((v2570 ^ -1) | (-(v2570 ^ -1))) >> 31)) & 2)) - (v2571 + ((~(((v2572 ^ -1) | (-(v2572 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2579 = v2577[v2737];
        int * v2580 = v2528->mem;
        int v2739 = v2576 * 2;
        v2580[v2739] = v2578;
        int * v2582 = v2528->mem;
        int v2742 = (v2576 * 2) + 1;
        v2582[v2742] = v2579;
        ;
      } else {
        ;
      }
      int * v2587 = v2528->mem;
      int v2747 = ((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1)) * 2;
      int v2588 = v2587[v2747];
      int v2748 = (((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1)) * 2) + 1;
      int v2589 = v2587[v2748];
      int * v2590 = v2528->cache_vals;
      int v2750 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2568 + ((~(((v2570 ^ -1) | (-(v2570 ^ -1))) >> 31)) & 2)) - (v2571 + ((~(((v2572 ^ -1) | (-(v2572 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2590[v2750] = v2588;
      int * v2592 = v2528->cache_vals;
      int v2753 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2568 + ((~(((v2570 ^ -1) | (-(v2570 ^ -1))) >> 31)) & 2)) - (v2571 + ((~(((v2572 ^ -1) | (-(v2572 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2592[v2753] = v2589;
      int * v2594 = v2528->cache_tags;
      int v2756 = (int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1);
      v2594[v2732] = v2756;
      int * v2596 = v2528->cache_dirty;
      v2596[v2732] = 0;
      int * v2598 = v2528->cache_age;
      v2598[v2732] = 1;
      int * v2600 = v2528->cache_age;
      int v2601 = v2600[v2732];
      int v2602 = v2600[v2706];
      int v2762 = v2602 + ((int)((unsigned int)(v2602 - v2601) >> 31));
      v2600[v2706] = v2762;
      int * v2604 = v2528->cache_age;
      int v2605 = v2604[v2707];
      int v2764 = v2605 + ((int)((unsigned int)(v2605 - v2601) >> 31));
      v2604[v2707] = v2764;
      int * v2607 = v2528->cache_age;
      v2607[v2732] = 0;
      v2610 = v2732;
    }
    int * v2611 = v2528->cache_vals;
    int v2767 = v2610 * 2;
    int v2612 = v2611[v2767];
    int v2768 = (v2610 * 2) + 1;
    int v2613 = v2611[v2768];
    int v2769 = (((((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v2552 + ((~(((v2554 ^ -1) | (-(v2554 ^ -1))) >> 31)) & 2)) - (v2555 + ((~(((v2556 ^ -1) | (-(v2556 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2611[v2769] = v2612;
    int * v2615 = v2528->cache_vals;
    int v2772 = ((((((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v2552 + ((~(((v2554 ^ -1) | (-(v2554 ^ -1))) >> 31)) & 2)) - (v2555 + ((~(((v2556 ^ -1) | (-(v2556 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2615[v2772] = v2613;
    int * v2617 = v2528->cache_tags;
    int v2775 = ((((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v2552 + ((~(((v2554 ^ -1) | (-(v2554 ^ -1))) >> 31)) & 2)) - (v2555 + ((~(((v2556 ^ -1) | (-(v2556 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2776 = (int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1);
    v2617[v2775] = v2776;
    int * v2619 = v2528->cache_dirty;
    v2619[v2775] = 0;
    int * v2621 = v2528->cache_age;
    v2621[v2775] = 1;
    int * v2623 = v2528->cache_age;
    int v2624 = v2623[v2775];
    int v2625 = v2623[v2704];
    int v2782 = v2625 + ((int)((unsigned int)(v2625 - v2624) >> 31));
    v2623[v2704] = v2782;
    int * v2627 = v2528->cache_age;
    int v2628 = v2627[v2705];
    int v2784 = v2628 + ((int)((unsigned int)(v2628 - v2624) >> 31));
    v2627[v2705] = v2784;
    int * v2630 = v2528->cache_age;
    v2630[v2775] = 0;
    v2633 = v2775;
  }
  int * v2634 = v2528->cache_vals;
  int v2787 = (v2633 * 2) + (((int)((unsigned int)(v2532 + 4) >> 2)) & 1);
  v2634[v2787] = v2533;
  int * v2636 = v2528->cache_tags;
  int v2637 = v2636[v2706];
  int v2638 = v2636[v2707];
  bool v2790 = !(((~(((v2637 ^ ((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1))) | (-(v2637 ^ ((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2638 ^ ((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1))) | (-(v2638 ^ ((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v2692;
  if (v2790) {
    int * v2639 = v2528->cache_age;
    int v2792 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2638 ^ ((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1))) | (-(v2638 ^ ((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v2640 = v2639[v2792];
    int v2641 = v2639[v2706];
    int v2793 = v2641 + ((int)((unsigned int)(v2641 - v2640) >> 31));
    v2639[v2706] = v2793;
    int * v2643 = v2528->cache_age;
    int v2644 = v2643[v2707];
    int v2795 = v2644 + ((int)((unsigned int)(v2644 - v2640) >> 31));
    v2643[v2707] = v2795;
    int * v2646 = v2528->cache_age;
    v2646[v2792] = 0;
    v2692 = v2792;
  } else {
    int * v2649 = v2528->cache_age;
    int v2799 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1)) & 3) * 2);
    int v2650 = v2649[v2799];
    int * v2651 = v2528->cache_tags;
    int v2652 = v2651[v2799];
    int v2653 = v2649[v2707];
    int v2654 = v2651[v2707];
    int * v2655 = v2528->cache_dirty;
    int v2802 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2650 + ((~(((v2652 ^ -1) | (-(v2652 ^ -1))) >> 31)) & 2)) - (v2653 + ((~(((v2654 ^ -1) | (-(v2654 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2656 = v2655[v2802];
    bool v2803 = !(v2656 == 0);
    if (v2803) {
      int * v2657 = v2528->cache_tags;
      int v2658 = v2657[v2802];
      int * v2659 = v2528->cache_vals;
      int v2806 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2650 + ((~(((v2652 ^ -1) | (-(v2652 ^ -1))) >> 31)) & 2)) - (v2653 + ((~(((v2654 ^ -1) | (-(v2654 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v2660 = v2659[v2806];
      int v2807 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2650 + ((~(((v2652 ^ -1) | (-(v2652 ^ -1))) >> 31)) & 2)) - (v2653 + ((~(((v2654 ^ -1) | (-(v2654 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v2661 = v2659[v2807];
      int * v2662 = v2528->mem;
      int v2809 = v2658 * 2;
      v2662[v2809] = v2660;
      int * v2664 = v2528->mem;
      int v2812 = (v2658 * 2) + 1;
      v2664[v2812] = v2661;
      ;
    } else {
      ;
    }
    int * v2669 = v2528->mem;
    int v2817 = ((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1)) * 2;
    int v2670 = v2669[v2817];
    int v2818 = (((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1)) * 2) + 1;
    int v2671 = v2669[v2818];
    int * v2672 = v2528->cache_vals;
    int v2820 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2650 + ((~(((v2652 ^ -1) | (-(v2652 ^ -1))) >> 31)) & 2)) - (v2653 + ((~(((v2654 ^ -1) | (-(v2654 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2672[v2820] = v2670;
    int * v2674 = v2528->cache_vals;
    int v2823 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2650 + ((~(((v2652 ^ -1) | (-(v2652 ^ -1))) >> 31)) & 2)) - (v2653 + ((~(((v2654 ^ -1) | (-(v2654 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2674[v2823] = v2671;
    int * v2676 = v2528->cache_tags;
    int v2826 = (int)((unsigned int)((int)((unsigned int)(v2532 + 4) >> 2)) >> 1);
    v2676[v2802] = v2826;
    int * v2678 = v2528->cache_dirty;
    v2678[v2802] = 0;
    int * v2680 = v2528->cache_age;
    v2680[v2802] = 1;
    int * v2682 = v2528->cache_age;
    int v2683 = v2682[v2802];
    int v2684 = v2682[v2706];
    int v2832 = v2684 + ((int)((unsigned int)(v2684 - v2683) >> 31));
    v2682[v2706] = v2832;
    int * v2686 = v2528->cache_age;
    int v2687 = v2686[v2707];
    int v2834 = v2687 + ((int)((unsigned int)(v2687 - v2683) >> 31));
    v2686[v2707] = v2834;
    int * v2689 = v2528->cache_age;
    v2689[v2802] = 0;
    v2692 = v2802;
  }
  int * v2693 = v2528->cache_vals;
  int v2837 = (v2692 * 2) + (((int)((unsigned int)(v2532 + 4) >> 2)) & 1);
  v2693[v2837] = v2533;
  int * v2695 = v2528->cache_dirty;
  v2695[v2692] = 1;
  struct StateT * v2697 = slot_32(v2528);
  return v2697;
}

struct StateT * slot_3(struct StateT * v45) {
  int v46 = v45->timer;
  int v52 = v46 + 1;
  v45->timer = v52;
  int * v48 = v45->regs;
  v48[12] = 4;
  struct StateT * v50 = slot_4(v45);
  return v50;
}

struct StateT * slot_26(struct StateT * v2149) {
  int v2150 = v2149->timer;
  int v2158 = v2150 + 1;
  v2149->timer = v2158;
  int * v2152 = v2149->regs;
  int v2153 = v2152[13];
  int v2154 = v2152[17];
  int v2162 = v2153 & v2154;
  v2152[17] = v2162;
  struct StateT * v2156 = slot_27(v2149);
  return v2156;
}

struct StateT * slot_10(struct StateT * v167) {
  int v168 = v167->timer;
  int v278 = v168 + 1;
  v167->timer = v278;
  int * v170 = v167->regs;
  int v171 = v170[16];
  int * v172 = v167->cache_tags;
  int v282 = (((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1)) & 1) * 2;
  int v173 = v172[v282];
  int v283 = ((((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1)) & 1) * 2) + 1;
  int v174 = v172[v283];
  int v284 = 4 + ((((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1)) & 3) * 2);
  int v175 = v172[v284];
  int v285 = (4 + ((((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v176 = v172[v285];
  int v177 = v167->timer;
  int v286 = v177 + ((100 ^ (((~(((v175 ^ ((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1))) | (-(v175 ^ ((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1))))) >> 31)) | (~(((v176 ^ ((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1))) | (-(v176 ^ ((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v173 ^ ((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1))) | (-(v173 ^ ((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1))))) >> 31)) | (~(((v174 ^ ((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1))) | (-(v174 ^ ((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v175 ^ ((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1))) | (-(v175 ^ ((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1))))) >> 31)) | (~(((v176 ^ ((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1))) | (-(v176 ^ ((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1))))) >> 31))) & 104)))));
  v167->timer = v286;
  int * v179 = v167->cache_vals;
  bool v287 = !(((~(((v173 ^ ((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1))) | (-(v173 ^ ((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1))))) >> 31)) | (~(((v174 ^ ((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1))) | (-(v174 ^ ((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1))))) >> 31))) == 0);
  int v272;
  if (v287) {
    int * v180 = v167->cache_age;
    int v289 = ((((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1)) & 1) * 2) + ((~(((v174 ^ ((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1))) | (-(v174 ^ ((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1))))) >> 31)) & 1);
    int v181 = v180[v289];
    int v182 = v180[v282];
    int v290 = v182 + ((int)((unsigned int)(v182 - v181) >> 31));
    v180[v282] = v290;
    int * v184 = v167->cache_age;
    int v185 = v184[v283];
    int v292 = v185 + ((int)((unsigned int)(v185 - v181) >> 31));
    v184[v283] = v292;
    int * v187 = v167->cache_age;
    v187[v289] = 0;
    v272 = v289;
  } else {
    int * v190 = v167->cache_age;
    int v296 = (((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1)) & 1) * 2;
    int v191 = v190[v296];
    int * v192 = v167->cache_tags;
    int v193 = v192[v296];
    int v194 = v190[v283];
    int v195 = v192[v283];
    bool v298 = !(((~(((v175 ^ ((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1))) | (-(v175 ^ ((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1))))) >> 31)) | (~(((v176 ^ ((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1))) | (-(v176 ^ ((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1))))) >> 31))) == 0);
    int v249;
    if (v298) {
      int * v196 = v167->cache_age;
      int v300 = (4 + ((((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1)) & 3) * 2)) + ((~(((v176 ^ ((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1))) | (-(v176 ^ ((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1))))) >> 31)) & 1);
      int v197 = v196[v300];
      int v198 = v196[v284];
      int v301 = v198 + ((int)((unsigned int)(v198 - v197) >> 31));
      v196[v284] = v301;
      int * v200 = v167->cache_age;
      int v201 = v200[v285];
      int v303 = v201 + ((int)((unsigned int)(v201 - v197) >> 31));
      v200[v285] = v303;
      int * v203 = v167->cache_age;
      v203[v300] = 0;
      v249 = v300;
    } else {
      int * v206 = v167->cache_age;
      int v307 = 4 + ((((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1)) & 3) * 2);
      int v207 = v206[v307];
      int * v208 = v167->cache_tags;
      int v209 = v208[v307];
      int v210 = v206[v285];
      int v211 = v208[v285];
      int * v212 = v167->cache_dirty;
      int v310 = (4 + ((((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1)) & 3) * 2)) + ((((v207 + ((~(((v209 ^ -1) | (-(v209 ^ -1))) >> 31)) & 2)) - (v210 + ((~(((v211 ^ -1) | (-(v211 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v213 = v212[v310];
      bool v311 = !(v213 == 0);
      if (v311) {
        int * v214 = v167->cache_tags;
        int v215 = v214[v310];
        int * v216 = v167->cache_vals;
        int v314 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1)) & 3) * 2)) + ((((v207 + ((~(((v209 ^ -1) | (-(v209 ^ -1))) >> 31)) & 2)) - (v210 + ((~(((v211 ^ -1) | (-(v211 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v217 = v216[v314];
        int v315 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1)) & 3) * 2)) + ((((v207 + ((~(((v209 ^ -1) | (-(v209 ^ -1))) >> 31)) & 2)) - (v210 + ((~(((v211 ^ -1) | (-(v211 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v218 = v216[v315];
        int * v219 = v167->mem;
        int v317 = v215 * 2;
        v219[v317] = v217;
        int * v221 = v167->mem;
        int v320 = (v215 * 2) + 1;
        v221[v320] = v218;
        ;
      } else {
        ;
      }
      int * v226 = v167->mem;
      int v325 = ((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1)) * 2;
      int v227 = v226[v325];
      int v326 = (((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1)) * 2) + 1;
      int v228 = v226[v326];
      int * v229 = v167->cache_vals;
      int v328 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1)) & 3) * 2)) + ((((v207 + ((~(((v209 ^ -1) | (-(v209 ^ -1))) >> 31)) & 2)) - (v210 + ((~(((v211 ^ -1) | (-(v211 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v229[v328] = v227;
      int * v231 = v167->cache_vals;
      int v331 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1)) & 3) * 2)) + ((((v207 + ((~(((v209 ^ -1) | (-(v209 ^ -1))) >> 31)) & 2)) - (v210 + ((~(((v211 ^ -1) | (-(v211 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v231[v331] = v228;
      int * v233 = v167->cache_tags;
      int v334 = (int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1);
      v233[v310] = v334;
      int * v235 = v167->cache_dirty;
      v235[v310] = 0;
      int * v237 = v167->cache_age;
      v237[v310] = 1;
      int * v239 = v167->cache_age;
      int v240 = v239[v310];
      int v241 = v239[v284];
      int v340 = v241 + ((int)((unsigned int)(v241 - v240) >> 31));
      v239[v284] = v340;
      int * v243 = v167->cache_age;
      int v244 = v243[v285];
      int v342 = v244 + ((int)((unsigned int)(v244 - v240) >> 31));
      v243[v285] = v342;
      int * v246 = v167->cache_age;
      v246[v310] = 0;
      v249 = v310;
    }
    int * v250 = v167->cache_vals;
    int v345 = v249 * 2;
    int v251 = v250[v345];
    int v346 = (v249 * 2) + 1;
    int v252 = v250[v346];
    int v347 = (((((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1)) & 1) * 2) + ((((v191 + ((~(((v193 ^ -1) | (-(v193 ^ -1))) >> 31)) & 2)) - (v194 + ((~(((v195 ^ -1) | (-(v195 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v250[v347] = v251;
    int * v254 = v167->cache_vals;
    int v350 = ((((((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1)) & 1) * 2) + ((((v191 + ((~(((v193 ^ -1) | (-(v193 ^ -1))) >> 31)) & 2)) - (v194 + ((~(((v195 ^ -1) | (-(v195 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v254[v350] = v252;
    int * v256 = v167->cache_tags;
    int v353 = ((((int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1)) & 1) * 2) + ((((v191 + ((~(((v193 ^ -1) | (-(v193 ^ -1))) >> 31)) & 2)) - (v194 + ((~(((v195 ^ -1) | (-(v195 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v354 = (int)((unsigned int)((int)((unsigned int)v171 >> 2)) >> 1);
    v256[v353] = v354;
    int * v258 = v167->cache_dirty;
    v258[v353] = 0;
    int * v260 = v167->cache_age;
    v260[v353] = 1;
    int * v262 = v167->cache_age;
    int v263 = v262[v353];
    int v264 = v262[v282];
    int v360 = v264 + ((int)((unsigned int)(v264 - v263) >> 31));
    v262[v282] = v360;
    int * v266 = v167->cache_age;
    int v267 = v266[v283];
    int v362 = v267 + ((int)((unsigned int)(v267 - v263) >> 31));
    v266[v283] = v362;
    int * v269 = v167->cache_age;
    v269[v353] = 0;
    v272 = v353;
  }
  int v365 = (v272 * 2) + (((int)((unsigned int)v171 >> 2)) & 1);
  int v273 = v179[v365];
  int * v274 = v167->regs;
  v274[17] = v273;
  struct StateT * v276 = slot_11(v167);
  return v276;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v23 = v16 + 1;
  v15->timer = v23;
  int * v18 = v15->regs;
  int v19 = v18[12];
  int v26 = v19 ^ 1;
  v18[12] = v26;
  struct StateT * v21 = slot_2(v15);
  return v21;
}

struct StateT * slot_19(struct StateT * v1063) {
  int v1064 = v1063->timer;
  int v1072 = v1064 + 1;
  v1063->timer = v1072;
  int * v1066 = v1063->regs;
  int v1067 = v1066[17];
  int v1068 = v1066[7];
  int v1076 = v1067 ^ v1068;
  v1066[7] = v1076;
  struct StateT * v1070 = slot_20(v1063);
  return v1070;
}

struct StateT * slot_13(struct StateT * v779) {
  int v780 = v779->timer;
  int v890 = v780 + 1;
  v779->timer = v890;
  int * v782 = v779->regs;
  int v783 = v782[15];
  int * v784 = v779->cache_tags;
  int v894 = (((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1)) & 1) * 2;
  int v785 = v784[v894];
  int v895 = ((((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1)) & 1) * 2) + 1;
  int v786 = v784[v895];
  int v896 = 4 + ((((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1)) & 3) * 2);
  int v787 = v784[v896];
  int v897 = (4 + ((((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v788 = v784[v897];
  int v789 = v779->timer;
  int v898 = v789 + ((100 ^ (((~(((v787 ^ ((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1))) | (-(v787 ^ ((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1))))) >> 31)) | (~(((v788 ^ ((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1))) | (-(v788 ^ ((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v785 ^ ((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1))) | (-(v785 ^ ((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1))))) >> 31)) | (~(((v786 ^ ((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1))) | (-(v786 ^ ((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v787 ^ ((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1))) | (-(v787 ^ ((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1))))) >> 31)) | (~(((v788 ^ ((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1))) | (-(v788 ^ ((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1))))) >> 31))) & 104)))));
  v779->timer = v898;
  int * v791 = v779->cache_vals;
  bool v899 = !(((~(((v785 ^ ((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1))) | (-(v785 ^ ((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1))))) >> 31)) | (~(((v786 ^ ((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1))) | (-(v786 ^ ((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1))))) >> 31))) == 0);
  int v884;
  if (v899) {
    int * v792 = v779->cache_age;
    int v901 = ((((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1)) & 1) * 2) + ((~(((v786 ^ ((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1))) | (-(v786 ^ ((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1))))) >> 31)) & 1);
    int v793 = v792[v901];
    int v794 = v792[v894];
    int v902 = v794 + ((int)((unsigned int)(v794 - v793) >> 31));
    v792[v894] = v902;
    int * v796 = v779->cache_age;
    int v797 = v796[v895];
    int v904 = v797 + ((int)((unsigned int)(v797 - v793) >> 31));
    v796[v895] = v904;
    int * v799 = v779->cache_age;
    v799[v901] = 0;
    v884 = v901;
  } else {
    int * v802 = v779->cache_age;
    int v908 = (((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1)) & 1) * 2;
    int v803 = v802[v908];
    int * v804 = v779->cache_tags;
    int v805 = v804[v908];
    int v806 = v802[v895];
    int v807 = v804[v895];
    bool v910 = !(((~(((v787 ^ ((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1))) | (-(v787 ^ ((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1))))) >> 31)) | (~(((v788 ^ ((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1))) | (-(v788 ^ ((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1))))) >> 31))) == 0);
    int v861;
    if (v910) {
      int * v808 = v779->cache_age;
      int v912 = (4 + ((((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1)) & 3) * 2)) + ((~(((v788 ^ ((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1))) | (-(v788 ^ ((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1))))) >> 31)) & 1);
      int v809 = v808[v912];
      int v810 = v808[v896];
      int v913 = v810 + ((int)((unsigned int)(v810 - v809) >> 31));
      v808[v896] = v913;
      int * v812 = v779->cache_age;
      int v813 = v812[v897];
      int v915 = v813 + ((int)((unsigned int)(v813 - v809) >> 31));
      v812[v897] = v915;
      int * v815 = v779->cache_age;
      v815[v912] = 0;
      v861 = v912;
    } else {
      int * v818 = v779->cache_age;
      int v919 = 4 + ((((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1)) & 3) * 2);
      int v819 = v818[v919];
      int * v820 = v779->cache_tags;
      int v821 = v820[v919];
      int v822 = v818[v897];
      int v823 = v820[v897];
      int * v824 = v779->cache_dirty;
      int v922 = (4 + ((((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1)) & 3) * 2)) + ((((v819 + ((~(((v821 ^ -1) | (-(v821 ^ -1))) >> 31)) & 2)) - (v822 + ((~(((v823 ^ -1) | (-(v823 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v825 = v824[v922];
      bool v923 = !(v825 == 0);
      if (v923) {
        int * v826 = v779->cache_tags;
        int v827 = v826[v922];
        int * v828 = v779->cache_vals;
        int v926 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1)) & 3) * 2)) + ((((v819 + ((~(((v821 ^ -1) | (-(v821 ^ -1))) >> 31)) & 2)) - (v822 + ((~(((v823 ^ -1) | (-(v823 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v829 = v828[v926];
        int v927 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1)) & 3) * 2)) + ((((v819 + ((~(((v821 ^ -1) | (-(v821 ^ -1))) >> 31)) & 2)) - (v822 + ((~(((v823 ^ -1) | (-(v823 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v830 = v828[v927];
        int * v831 = v779->mem;
        int v929 = v827 * 2;
        v831[v929] = v829;
        int * v833 = v779->mem;
        int v932 = (v827 * 2) + 1;
        v833[v932] = v830;
        ;
      } else {
        ;
      }
      int * v838 = v779->mem;
      int v937 = ((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1)) * 2;
      int v839 = v838[v937];
      int v938 = (((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1)) * 2) + 1;
      int v840 = v838[v938];
      int * v841 = v779->cache_vals;
      int v940 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1)) & 3) * 2)) + ((((v819 + ((~(((v821 ^ -1) | (-(v821 ^ -1))) >> 31)) & 2)) - (v822 + ((~(((v823 ^ -1) | (-(v823 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v841[v940] = v839;
      int * v843 = v779->cache_vals;
      int v943 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1)) & 3) * 2)) + ((((v819 + ((~(((v821 ^ -1) | (-(v821 ^ -1))) >> 31)) & 2)) - (v822 + ((~(((v823 ^ -1) | (-(v823 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v843[v943] = v840;
      int * v845 = v779->cache_tags;
      int v946 = (int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1);
      v845[v922] = v946;
      int * v847 = v779->cache_dirty;
      v847[v922] = 0;
      int * v849 = v779->cache_age;
      v849[v922] = 1;
      int * v851 = v779->cache_age;
      int v852 = v851[v922];
      int v853 = v851[v896];
      int v952 = v853 + ((int)((unsigned int)(v853 - v852) >> 31));
      v851[v896] = v952;
      int * v855 = v779->cache_age;
      int v856 = v855[v897];
      int v954 = v856 + ((int)((unsigned int)(v856 - v852) >> 31));
      v855[v897] = v954;
      int * v858 = v779->cache_age;
      v858[v922] = 0;
      v861 = v922;
    }
    int * v862 = v779->cache_vals;
    int v957 = v861 * 2;
    int v863 = v862[v957];
    int v958 = (v861 * 2) + 1;
    int v864 = v862[v958];
    int v959 = (((((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1)) & 1) * 2) + ((((v803 + ((~(((v805 ^ -1) | (-(v805 ^ -1))) >> 31)) & 2)) - (v806 + ((~(((v807 ^ -1) | (-(v807 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v862[v959] = v863;
    int * v866 = v779->cache_vals;
    int v962 = ((((((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1)) & 1) * 2) + ((((v803 + ((~(((v805 ^ -1) | (-(v805 ^ -1))) >> 31)) & 2)) - (v806 + ((~(((v807 ^ -1) | (-(v807 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v866[v962] = v864;
    int * v868 = v779->cache_tags;
    int v965 = ((((int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1)) & 1) * 2) + ((((v803 + ((~(((v805 ^ -1) | (-(v805 ^ -1))) >> 31)) & 2)) - (v806 + ((~(((v807 ^ -1) | (-(v807 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v966 = (int)((unsigned int)((int)((unsigned int)v783 >> 2)) >> 1);
    v868[v965] = v966;
    int * v870 = v779->cache_dirty;
    v870[v965] = 0;
    int * v872 = v779->cache_age;
    v872[v965] = 1;
    int * v874 = v779->cache_age;
    int v875 = v874[v965];
    int v876 = v874[v894];
    int v972 = v876 + ((int)((unsigned int)(v876 - v875) >> 31));
    v874[v894] = v972;
    int * v878 = v779->cache_age;
    int v879 = v878[v895];
    int v974 = v879 + ((int)((unsigned int)(v879 - v875) >> 31));
    v878[v895] = v974;
    int * v881 = v779->cache_age;
    v881[v965] = 0;
    v884 = v965;
  }
  int v977 = (v884 * 2) + (((int)((unsigned int)v783 >> 2)) & 1);
  int v885 = v791[v977];
  int * v886 = v779->regs;
  v886[7] = v885;
  struct StateT * v888 = slot_14(v779);
  return v888;
}

struct StateT * slot_24(struct StateT * v2117) {
  int v2118 = v2117->timer;
  int v2126 = v2118 + 1;
  v2117->timer = v2126;
  int * v2120 = v2117->regs;
  int v2121 = v2120[5];
  int v2122 = v2120[16];
  int v2130 = v2121 ^ v2122;
  v2120[5] = v2130;
  struct StateT * v2124 = slot_25(v2117);
  return v2124;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[14] = 0;
  struct StateT * v7 = slot_1(v2);
  return v7;
}

struct StateT * slot_14(struct StateT * v983) {
  int v984 = v983->timer;
  int v992 = v984 + 1;
  v983->timer = v992;
  int * v986 = v983->regs;
  int v987 = v986[6];
  int v988 = v986[5];
  int v996 = v987 ^ v988;
  v986[6] = v996;
  struct StateT * v990 = slot_15(v983);
  return v990;
}

struct StateT * slot_28(struct StateT * v2181) {
  int v2182 = v2181->timer;
  int v2190 = v2182 + 1;
  v2181->timer = v2190;
  int * v2184 = v2181->regs;
  int v2185 = v2184[16];
  int v2186 = v2184[5];
  int v2194 = v2185 ^ v2186;
  v2184[16] = v2194;
  struct StateT * v2188 = slot_29(v2181);
  return v2188;
}

struct StateT * slot_32(struct StateT * v2843) {
  int v2844 = v2843->timer;
  int v2851 = v2844 + 1;
  v2843->timer = v2851;
  int * v2846 = v2843->regs;
  int v2847 = v2846[14];
  int v2854 = v2847 + 1;
  v2846[14] = v2854;
  struct StateT * v2849 = slot_33(v2843);
  return v2849;
}

struct StateT * slot_17(struct StateT * v1031) {
  int v1032 = v1031->timer;
  int v1040 = v1032 + 1;
  v1031->timer = v1040;
  int * v1034 = v1031->regs;
  int v1035 = v1034[13];
  int v1036 = v1034[6];
  int v1044 = v1035 & v1036;
  v1034[6] = v1044;
  struct StateT * v1038 = slot_18(v1031);
  return v1038;
}

struct StateT * slot_20(struct StateT * v1079) {
  int v1080 = v1079->timer;
  int v1250 = v1080 + 1;
  v1079->timer = v1250;
  int * v1082 = v1079->regs;
  int v1083 = v1082[16];
  int v1084 = v1082[7];
  int * v1085 = v1079->cache_tags;
  int v1255 = (((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1)) & 1) * 2;
  int v1086 = v1085[v1255];
  int v1256 = ((((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1087 = v1085[v1256];
  int v1257 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1)) & 3) * 2);
  int v1088 = v1085[v1257];
  int v1258 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1089 = v1085[v1258];
  int v1090 = v1079->timer;
  int v1259 = v1090 + ((100 ^ (((~(((v1088 ^ ((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1))) | (-(v1088 ^ ((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1))))) >> 31)) | (~(((v1089 ^ ((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1))) | (-(v1089 ^ ((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1086 ^ ((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1))) | (-(v1086 ^ ((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1))))) >> 31)) | (~(((v1087 ^ ((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1))) | (-(v1087 ^ ((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1088 ^ ((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1))) | (-(v1088 ^ ((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1))))) >> 31)) | (~(((v1089 ^ ((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1))) | (-(v1089 ^ ((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1079->timer = v1259;
  bool v1260 = !(((~(((v1086 ^ ((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1))) | (-(v1086 ^ ((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1))))) >> 31)) | (~(((v1087 ^ ((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1))) | (-(v1087 ^ ((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1))))) >> 31))) == 0);
  int v1184;
  if (v1260) {
    int * v1092 = v1079->cache_age;
    int v1262 = ((((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1)) & 1) * 2) + ((~(((v1087 ^ ((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1))) | (-(v1087 ^ ((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1))))) >> 31)) & 1);
    int v1093 = v1092[v1262];
    int v1094 = v1092[v1255];
    int v1263 = v1094 + ((int)((unsigned int)(v1094 - v1093) >> 31));
    v1092[v1255] = v1263;
    int * v1096 = v1079->cache_age;
    int v1097 = v1096[v1256];
    int v1265 = v1097 + ((int)((unsigned int)(v1097 - v1093) >> 31));
    v1096[v1256] = v1265;
    int * v1099 = v1079->cache_age;
    v1099[v1262] = 0;
    v1184 = v1262;
  } else {
    int * v1102 = v1079->cache_age;
    int v1269 = (((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1)) & 1) * 2;
    int v1103 = v1102[v1269];
    int * v1104 = v1079->cache_tags;
    int v1105 = v1104[v1269];
    int v1106 = v1102[v1256];
    int v1107 = v1104[v1256];
    bool v1271 = !(((~(((v1088 ^ ((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1))) | (-(v1088 ^ ((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1))))) >> 31)) | (~(((v1089 ^ ((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1))) | (-(v1089 ^ ((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1))))) >> 31))) == 0);
    int v1161;
    if (v1271) {
      int * v1108 = v1079->cache_age;
      int v1273 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1089 ^ ((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1))) | (-(v1089 ^ ((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1))))) >> 31)) & 1);
      int v1109 = v1108[v1273];
      int v1110 = v1108[v1257];
      int v1274 = v1110 + ((int)((unsigned int)(v1110 - v1109) >> 31));
      v1108[v1257] = v1274;
      int * v1112 = v1079->cache_age;
      int v1113 = v1112[v1258];
      int v1276 = v1113 + ((int)((unsigned int)(v1113 - v1109) >> 31));
      v1112[v1258] = v1276;
      int * v1115 = v1079->cache_age;
      v1115[v1273] = 0;
      v1161 = v1273;
    } else {
      int * v1118 = v1079->cache_age;
      int v1280 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1)) & 3) * 2);
      int v1119 = v1118[v1280];
      int * v1120 = v1079->cache_tags;
      int v1121 = v1120[v1280];
      int v1122 = v1118[v1258];
      int v1123 = v1120[v1258];
      int * v1124 = v1079->cache_dirty;
      int v1283 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1)) & 3) * 2)) + ((((v1119 + ((~(((v1121 ^ -1) | (-(v1121 ^ -1))) >> 31)) & 2)) - (v1122 + ((~(((v1123 ^ -1) | (-(v1123 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1125 = v1124[v1283];
      bool v1284 = !(v1125 == 0);
      if (v1284) {
        int * v1126 = v1079->cache_tags;
        int v1127 = v1126[v1283];
        int * v1128 = v1079->cache_vals;
        int v1287 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1)) & 3) * 2)) + ((((v1119 + ((~(((v1121 ^ -1) | (-(v1121 ^ -1))) >> 31)) & 2)) - (v1122 + ((~(((v1123 ^ -1) | (-(v1123 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1129 = v1128[v1287];
        int v1288 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1)) & 3) * 2)) + ((((v1119 + ((~(((v1121 ^ -1) | (-(v1121 ^ -1))) >> 31)) & 2)) - (v1122 + ((~(((v1123 ^ -1) | (-(v1123 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1130 = v1128[v1288];
        int * v1131 = v1079->mem;
        int v1290 = v1127 * 2;
        v1131[v1290] = v1129;
        int * v1133 = v1079->mem;
        int v1293 = (v1127 * 2) + 1;
        v1133[v1293] = v1130;
        ;
      } else {
        ;
      }
      int * v1138 = v1079->mem;
      int v1298 = ((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1)) * 2;
      int v1139 = v1138[v1298];
      int v1299 = (((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1)) * 2) + 1;
      int v1140 = v1138[v1299];
      int * v1141 = v1079->cache_vals;
      int v1301 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1)) & 3) * 2)) + ((((v1119 + ((~(((v1121 ^ -1) | (-(v1121 ^ -1))) >> 31)) & 2)) - (v1122 + ((~(((v1123 ^ -1) | (-(v1123 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1141[v1301] = v1139;
      int * v1143 = v1079->cache_vals;
      int v1304 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1)) & 3) * 2)) + ((((v1119 + ((~(((v1121 ^ -1) | (-(v1121 ^ -1))) >> 31)) & 2)) - (v1122 + ((~(((v1123 ^ -1) | (-(v1123 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1143[v1304] = v1140;
      int * v1145 = v1079->cache_tags;
      int v1307 = (int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1);
      v1145[v1283] = v1307;
      int * v1147 = v1079->cache_dirty;
      v1147[v1283] = 0;
      int * v1149 = v1079->cache_age;
      v1149[v1283] = 1;
      int * v1151 = v1079->cache_age;
      int v1152 = v1151[v1283];
      int v1153 = v1151[v1257];
      int v1313 = v1153 + ((int)((unsigned int)(v1153 - v1152) >> 31));
      v1151[v1257] = v1313;
      int * v1155 = v1079->cache_age;
      int v1156 = v1155[v1258];
      int v1315 = v1156 + ((int)((unsigned int)(v1156 - v1152) >> 31));
      v1155[v1258] = v1315;
      int * v1158 = v1079->cache_age;
      v1158[v1283] = 0;
      v1161 = v1283;
    }
    int * v1162 = v1079->cache_vals;
    int v1318 = v1161 * 2;
    int v1163 = v1162[v1318];
    int v1319 = (v1161 * 2) + 1;
    int v1164 = v1162[v1319];
    int v1320 = (((((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1)) & 1) * 2) + ((((v1103 + ((~(((v1105 ^ -1) | (-(v1105 ^ -1))) >> 31)) & 2)) - (v1106 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1162[v1320] = v1163;
    int * v1166 = v1079->cache_vals;
    int v1323 = ((((((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1)) & 1) * 2) + ((((v1103 + ((~(((v1105 ^ -1) | (-(v1105 ^ -1))) >> 31)) & 2)) - (v1106 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1166[v1323] = v1164;
    int * v1168 = v1079->cache_tags;
    int v1326 = ((((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1)) & 1) * 2) + ((((v1103 + ((~(((v1105 ^ -1) | (-(v1105 ^ -1))) >> 31)) & 2)) - (v1106 + ((~(((v1107 ^ -1) | (-(v1107 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1327 = (int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1);
    v1168[v1326] = v1327;
    int * v1170 = v1079->cache_dirty;
    v1170[v1326] = 0;
    int * v1172 = v1079->cache_age;
    v1172[v1326] = 1;
    int * v1174 = v1079->cache_age;
    int v1175 = v1174[v1326];
    int v1176 = v1174[v1255];
    int v1333 = v1176 + ((int)((unsigned int)(v1176 - v1175) >> 31));
    v1174[v1255] = v1333;
    int * v1178 = v1079->cache_age;
    int v1179 = v1178[v1256];
    int v1335 = v1179 + ((int)((unsigned int)(v1179 - v1175) >> 31));
    v1178[v1256] = v1335;
    int * v1181 = v1079->cache_age;
    v1181[v1326] = 0;
    v1184 = v1326;
  }
  int * v1185 = v1079->cache_vals;
  int v1338 = (v1184 * 2) + (((int)((unsigned int)v1083 >> 2)) & 1);
  v1185[v1338] = v1084;
  int * v1187 = v1079->cache_tags;
  int v1188 = v1187[v1257];
  int v1189 = v1187[v1258];
  bool v1341 = !(((~(((v1188 ^ ((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1))) | (-(v1188 ^ ((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1))))) >> 31)) | (~(((v1189 ^ ((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1))) | (-(v1189 ^ ((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1))))) >> 31))) == 0);
  int v1243;
  if (v1341) {
    int * v1190 = v1079->cache_age;
    int v1343 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1189 ^ ((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1))) | (-(v1189 ^ ((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1))))) >> 31)) & 1);
    int v1191 = v1190[v1343];
    int v1192 = v1190[v1257];
    int v1344 = v1192 + ((int)((unsigned int)(v1192 - v1191) >> 31));
    v1190[v1257] = v1344;
    int * v1194 = v1079->cache_age;
    int v1195 = v1194[v1258];
    int v1346 = v1195 + ((int)((unsigned int)(v1195 - v1191) >> 31));
    v1194[v1258] = v1346;
    int * v1197 = v1079->cache_age;
    v1197[v1343] = 0;
    v1243 = v1343;
  } else {
    int * v1200 = v1079->cache_age;
    int v1350 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1)) & 3) * 2);
    int v1201 = v1200[v1350];
    int * v1202 = v1079->cache_tags;
    int v1203 = v1202[v1350];
    int v1204 = v1200[v1258];
    int v1205 = v1202[v1258];
    int * v1206 = v1079->cache_dirty;
    int v1353 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1)) & 3) * 2)) + ((((v1201 + ((~(((v1203 ^ -1) | (-(v1203 ^ -1))) >> 31)) & 2)) - (v1204 + ((~(((v1205 ^ -1) | (-(v1205 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1207 = v1206[v1353];
    bool v1354 = !(v1207 == 0);
    if (v1354) {
      int * v1208 = v1079->cache_tags;
      int v1209 = v1208[v1353];
      int * v1210 = v1079->cache_vals;
      int v1357 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1)) & 3) * 2)) + ((((v1201 + ((~(((v1203 ^ -1) | (-(v1203 ^ -1))) >> 31)) & 2)) - (v1204 + ((~(((v1205 ^ -1) | (-(v1205 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1211 = v1210[v1357];
      int v1358 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1)) & 3) * 2)) + ((((v1201 + ((~(((v1203 ^ -1) | (-(v1203 ^ -1))) >> 31)) & 2)) - (v1204 + ((~(((v1205 ^ -1) | (-(v1205 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1212 = v1210[v1358];
      int * v1213 = v1079->mem;
      int v1360 = v1209 * 2;
      v1213[v1360] = v1211;
      int * v1215 = v1079->mem;
      int v1363 = (v1209 * 2) + 1;
      v1215[v1363] = v1212;
      ;
    } else {
      ;
    }
    int * v1220 = v1079->mem;
    int v1368 = ((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1)) * 2;
    int v1221 = v1220[v1368];
    int v1369 = (((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1)) * 2) + 1;
    int v1222 = v1220[v1369];
    int * v1223 = v1079->cache_vals;
    int v1371 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1)) & 3) * 2)) + ((((v1201 + ((~(((v1203 ^ -1) | (-(v1203 ^ -1))) >> 31)) & 2)) - (v1204 + ((~(((v1205 ^ -1) | (-(v1205 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1223[v1371] = v1221;
    int * v1225 = v1079->cache_vals;
    int v1374 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1)) & 3) * 2)) + ((((v1201 + ((~(((v1203 ^ -1) | (-(v1203 ^ -1))) >> 31)) & 2)) - (v1204 + ((~(((v1205 ^ -1) | (-(v1205 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1225[v1374] = v1222;
    int * v1227 = v1079->cache_tags;
    int v1377 = (int)((unsigned int)((int)((unsigned int)v1083 >> 2)) >> 1);
    v1227[v1353] = v1377;
    int * v1229 = v1079->cache_dirty;
    v1229[v1353] = 0;
    int * v1231 = v1079->cache_age;
    v1231[v1353] = 1;
    int * v1233 = v1079->cache_age;
    int v1234 = v1233[v1353];
    int v1235 = v1233[v1257];
    int v1383 = v1235 + ((int)((unsigned int)(v1235 - v1234) >> 31));
    v1233[v1257] = v1383;
    int * v1237 = v1079->cache_age;
    int v1238 = v1237[v1258];
    int v1385 = v1238 + ((int)((unsigned int)(v1238 - v1234) >> 31));
    v1237[v1258] = v1385;
    int * v1240 = v1079->cache_age;
    v1240[v1353] = 0;
    v1243 = v1353;
  }
  int * v1244 = v1079->cache_vals;
  int v1388 = (v1243 * 2) + (((int)((unsigned int)v1083 >> 2)) & 1);
  v1244[v1388] = v1084;
  int * v1246 = v1079->cache_dirty;
  v1246[v1243] = 1;
  struct StateT * v1248 = slot_21(v1079);
  return v1248;
}

struct StateT * slot_33(struct StateT * v2857) {
  int v2858 = v2857->timer;
  int v2869 = v2858 + 1;
  v2857->timer = v2869;
  int * v2860 = v2857->regs;
  int v2861 = v2860[12];
  int v2862 = v2860[14];
  bool v2873 = (v2861 ^ -2147483648) >= (v2862 ^ -2147483648);
  struct StateT * v2867;
  if (v2873) {
    struct StateT * v2863 = slot_7(v2857);
    v2867 = v2863;
  } else {
    struct StateT * v2865 = slot_34(v2857);
    v2867 = v2865;
  }
  return v2867;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_8(struct StateT * v134) {
  int v135 = v134->timer;
  int v143 = v135 + 1;
  v134->timer = v143;
  int * v137 = v134->regs;
  int v138 = v137[10];
  int v139 = v137[15];
  int v148 = v138 + v139;
  v137[16] = v148;
  struct StateT * v141 = slot_9(v134);
  return v141;
}

struct StateT * slot_27(struct StateT * v2165) {
  int v2166 = v2165->timer;
  int v2174 = v2166 + 1;
  v2165->timer = v2174;
  int * v2168 = v2165->regs;
  int v2169 = v2168[13];
  int v2170 = v2168[5];
  int v2178 = v2169 & v2170;
  v2168[5] = v2178;
  struct StateT * v2172 = slot_28(v2165);
  return v2172;
}

struct StateT * slot_30(struct StateT * v2213) {
  int v2214 = v2213->timer;
  int v2384 = v2214 + 1;
  v2213->timer = v2384;
  int * v2216 = v2213->regs;
  int v2217 = v2216[15];
  int v2218 = v2216[17];
  int * v2219 = v2213->cache_tags;
  int v2389 = (((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1)) & 1) * 2;
  int v2220 = v2219[v2389];
  int v2390 = ((((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1)) & 1) * 2) + 1;
  int v2221 = v2219[v2390];
  int v2391 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1)) & 3) * 2);
  int v2222 = v2219[v2391];
  int v2392 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2223 = v2219[v2392];
  int v2224 = v2213->timer;
  int v2393 = v2224 + ((100 ^ (((~(((v2222 ^ ((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1))) | (-(v2222 ^ ((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1))))) >> 31)) | (~(((v2223 ^ ((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1))) | (-(v2223 ^ ((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2220 ^ ((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1))) | (-(v2220 ^ ((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1))))) >> 31)) | (~(((v2221 ^ ((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1))) | (-(v2221 ^ ((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2222 ^ ((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1))) | (-(v2222 ^ ((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1))))) >> 31)) | (~(((v2223 ^ ((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1))) | (-(v2223 ^ ((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2213->timer = v2393;
  bool v2394 = !(((~(((v2220 ^ ((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1))) | (-(v2220 ^ ((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1))))) >> 31)) | (~(((v2221 ^ ((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1))) | (-(v2221 ^ ((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1))))) >> 31))) == 0);
  int v2318;
  if (v2394) {
    int * v2226 = v2213->cache_age;
    int v2396 = ((((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1)) & 1) * 2) + ((~(((v2221 ^ ((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1))) | (-(v2221 ^ ((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1))))) >> 31)) & 1);
    int v2227 = v2226[v2396];
    int v2228 = v2226[v2389];
    int v2397 = v2228 + ((int)((unsigned int)(v2228 - v2227) >> 31));
    v2226[v2389] = v2397;
    int * v2230 = v2213->cache_age;
    int v2231 = v2230[v2390];
    int v2399 = v2231 + ((int)((unsigned int)(v2231 - v2227) >> 31));
    v2230[v2390] = v2399;
    int * v2233 = v2213->cache_age;
    v2233[v2396] = 0;
    v2318 = v2396;
  } else {
    int * v2236 = v2213->cache_age;
    int v2403 = (((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1)) & 1) * 2;
    int v2237 = v2236[v2403];
    int * v2238 = v2213->cache_tags;
    int v2239 = v2238[v2403];
    int v2240 = v2236[v2390];
    int v2241 = v2238[v2390];
    bool v2405 = !(((~(((v2222 ^ ((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1))) | (-(v2222 ^ ((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1))))) >> 31)) | (~(((v2223 ^ ((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1))) | (-(v2223 ^ ((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1))))) >> 31))) == 0);
    int v2295;
    if (v2405) {
      int * v2242 = v2213->cache_age;
      int v2407 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2223 ^ ((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1))) | (-(v2223 ^ ((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1))))) >> 31)) & 1);
      int v2243 = v2242[v2407];
      int v2244 = v2242[v2391];
      int v2408 = v2244 + ((int)((unsigned int)(v2244 - v2243) >> 31));
      v2242[v2391] = v2408;
      int * v2246 = v2213->cache_age;
      int v2247 = v2246[v2392];
      int v2410 = v2247 + ((int)((unsigned int)(v2247 - v2243) >> 31));
      v2246[v2392] = v2410;
      int * v2249 = v2213->cache_age;
      v2249[v2407] = 0;
      v2295 = v2407;
    } else {
      int * v2252 = v2213->cache_age;
      int v2414 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1)) & 3) * 2);
      int v2253 = v2252[v2414];
      int * v2254 = v2213->cache_tags;
      int v2255 = v2254[v2414];
      int v2256 = v2252[v2392];
      int v2257 = v2254[v2392];
      int * v2258 = v2213->cache_dirty;
      int v2417 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1)) & 3) * 2)) + ((((v2253 + ((~(((v2255 ^ -1) | (-(v2255 ^ -1))) >> 31)) & 2)) - (v2256 + ((~(((v2257 ^ -1) | (-(v2257 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2259 = v2258[v2417];
      bool v2418 = !(v2259 == 0);
      if (v2418) {
        int * v2260 = v2213->cache_tags;
        int v2261 = v2260[v2417];
        int * v2262 = v2213->cache_vals;
        int v2421 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1)) & 3) * 2)) + ((((v2253 + ((~(((v2255 ^ -1) | (-(v2255 ^ -1))) >> 31)) & 2)) - (v2256 + ((~(((v2257 ^ -1) | (-(v2257 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2263 = v2262[v2421];
        int v2422 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1)) & 3) * 2)) + ((((v2253 + ((~(((v2255 ^ -1) | (-(v2255 ^ -1))) >> 31)) & 2)) - (v2256 + ((~(((v2257 ^ -1) | (-(v2257 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2264 = v2262[v2422];
        int * v2265 = v2213->mem;
        int v2424 = v2261 * 2;
        v2265[v2424] = v2263;
        int * v2267 = v2213->mem;
        int v2427 = (v2261 * 2) + 1;
        v2267[v2427] = v2264;
        ;
      } else {
        ;
      }
      int * v2272 = v2213->mem;
      int v2432 = ((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1)) * 2;
      int v2273 = v2272[v2432];
      int v2433 = (((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1)) * 2) + 1;
      int v2274 = v2272[v2433];
      int * v2275 = v2213->cache_vals;
      int v2435 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1)) & 3) * 2)) + ((((v2253 + ((~(((v2255 ^ -1) | (-(v2255 ^ -1))) >> 31)) & 2)) - (v2256 + ((~(((v2257 ^ -1) | (-(v2257 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2275[v2435] = v2273;
      int * v2277 = v2213->cache_vals;
      int v2438 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1)) & 3) * 2)) + ((((v2253 + ((~(((v2255 ^ -1) | (-(v2255 ^ -1))) >> 31)) & 2)) - (v2256 + ((~(((v2257 ^ -1) | (-(v2257 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2277[v2438] = v2274;
      int * v2279 = v2213->cache_tags;
      int v2441 = (int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1);
      v2279[v2417] = v2441;
      int * v2281 = v2213->cache_dirty;
      v2281[v2417] = 0;
      int * v2283 = v2213->cache_age;
      v2283[v2417] = 1;
      int * v2285 = v2213->cache_age;
      int v2286 = v2285[v2417];
      int v2287 = v2285[v2391];
      int v2447 = v2287 + ((int)((unsigned int)(v2287 - v2286) >> 31));
      v2285[v2391] = v2447;
      int * v2289 = v2213->cache_age;
      int v2290 = v2289[v2392];
      int v2449 = v2290 + ((int)((unsigned int)(v2290 - v2286) >> 31));
      v2289[v2392] = v2449;
      int * v2292 = v2213->cache_age;
      v2292[v2417] = 0;
      v2295 = v2417;
    }
    int * v2296 = v2213->cache_vals;
    int v2452 = v2295 * 2;
    int v2297 = v2296[v2452];
    int v2453 = (v2295 * 2) + 1;
    int v2298 = v2296[v2453];
    int v2454 = (((((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1)) & 1) * 2) + ((((v2237 + ((~(((v2239 ^ -1) | (-(v2239 ^ -1))) >> 31)) & 2)) - (v2240 + ((~(((v2241 ^ -1) | (-(v2241 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2296[v2454] = v2297;
    int * v2300 = v2213->cache_vals;
    int v2457 = ((((((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1)) & 1) * 2) + ((((v2237 + ((~(((v2239 ^ -1) | (-(v2239 ^ -1))) >> 31)) & 2)) - (v2240 + ((~(((v2241 ^ -1) | (-(v2241 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2300[v2457] = v2298;
    int * v2302 = v2213->cache_tags;
    int v2460 = ((((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1)) & 1) * 2) + ((((v2237 + ((~(((v2239 ^ -1) | (-(v2239 ^ -1))) >> 31)) & 2)) - (v2240 + ((~(((v2241 ^ -1) | (-(v2241 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2461 = (int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1);
    v2302[v2460] = v2461;
    int * v2304 = v2213->cache_dirty;
    v2304[v2460] = 0;
    int * v2306 = v2213->cache_age;
    v2306[v2460] = 1;
    int * v2308 = v2213->cache_age;
    int v2309 = v2308[v2460];
    int v2310 = v2308[v2389];
    int v2467 = v2310 + ((int)((unsigned int)(v2310 - v2309) >> 31));
    v2308[v2389] = v2467;
    int * v2312 = v2213->cache_age;
    int v2313 = v2312[v2390];
    int v2469 = v2313 + ((int)((unsigned int)(v2313 - v2309) >> 31));
    v2312[v2390] = v2469;
    int * v2315 = v2213->cache_age;
    v2315[v2460] = 0;
    v2318 = v2460;
  }
  int * v2319 = v2213->cache_vals;
  int v2472 = (v2318 * 2) + (((int)((unsigned int)v2217 >> 2)) & 1);
  v2319[v2472] = v2218;
  int * v2321 = v2213->cache_tags;
  int v2322 = v2321[v2391];
  int v2323 = v2321[v2392];
  bool v2475 = !(((~(((v2322 ^ ((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1))) | (-(v2322 ^ ((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1))))) >> 31)) | (~(((v2323 ^ ((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1))) | (-(v2323 ^ ((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1))))) >> 31))) == 0);
  int v2377;
  if (v2475) {
    int * v2324 = v2213->cache_age;
    int v2477 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2323 ^ ((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1))) | (-(v2323 ^ ((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1))))) >> 31)) & 1);
    int v2325 = v2324[v2477];
    int v2326 = v2324[v2391];
    int v2478 = v2326 + ((int)((unsigned int)(v2326 - v2325) >> 31));
    v2324[v2391] = v2478;
    int * v2328 = v2213->cache_age;
    int v2329 = v2328[v2392];
    int v2480 = v2329 + ((int)((unsigned int)(v2329 - v2325) >> 31));
    v2328[v2392] = v2480;
    int * v2331 = v2213->cache_age;
    v2331[v2477] = 0;
    v2377 = v2477;
  } else {
    int * v2334 = v2213->cache_age;
    int v2484 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1)) & 3) * 2);
    int v2335 = v2334[v2484];
    int * v2336 = v2213->cache_tags;
    int v2337 = v2336[v2484];
    int v2338 = v2334[v2392];
    int v2339 = v2336[v2392];
    int * v2340 = v2213->cache_dirty;
    int v2487 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1)) & 3) * 2)) + ((((v2335 + ((~(((v2337 ^ -1) | (-(v2337 ^ -1))) >> 31)) & 2)) - (v2338 + ((~(((v2339 ^ -1) | (-(v2339 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2341 = v2340[v2487];
    bool v2488 = !(v2341 == 0);
    if (v2488) {
      int * v2342 = v2213->cache_tags;
      int v2343 = v2342[v2487];
      int * v2344 = v2213->cache_vals;
      int v2491 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1)) & 3) * 2)) + ((((v2335 + ((~(((v2337 ^ -1) | (-(v2337 ^ -1))) >> 31)) & 2)) - (v2338 + ((~(((v2339 ^ -1) | (-(v2339 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v2345 = v2344[v2491];
      int v2492 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1)) & 3) * 2)) + ((((v2335 + ((~(((v2337 ^ -1) | (-(v2337 ^ -1))) >> 31)) & 2)) - (v2338 + ((~(((v2339 ^ -1) | (-(v2339 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v2346 = v2344[v2492];
      int * v2347 = v2213->mem;
      int v2494 = v2343 * 2;
      v2347[v2494] = v2345;
      int * v2349 = v2213->mem;
      int v2497 = (v2343 * 2) + 1;
      v2349[v2497] = v2346;
      ;
    } else {
      ;
    }
    int * v2354 = v2213->mem;
    int v2502 = ((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1)) * 2;
    int v2355 = v2354[v2502];
    int v2503 = (((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1)) * 2) + 1;
    int v2356 = v2354[v2503];
    int * v2357 = v2213->cache_vals;
    int v2505 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1)) & 3) * 2)) + ((((v2335 + ((~(((v2337 ^ -1) | (-(v2337 ^ -1))) >> 31)) & 2)) - (v2338 + ((~(((v2339 ^ -1) | (-(v2339 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2357[v2505] = v2355;
    int * v2359 = v2213->cache_vals;
    int v2508 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1)) & 3) * 2)) + ((((v2335 + ((~(((v2337 ^ -1) | (-(v2337 ^ -1))) >> 31)) & 2)) - (v2338 + ((~(((v2339 ^ -1) | (-(v2339 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2359[v2508] = v2356;
    int * v2361 = v2213->cache_tags;
    int v2511 = (int)((unsigned int)((int)((unsigned int)v2217 >> 2)) >> 1);
    v2361[v2487] = v2511;
    int * v2363 = v2213->cache_dirty;
    v2363[v2487] = 0;
    int * v2365 = v2213->cache_age;
    v2365[v2487] = 1;
    int * v2367 = v2213->cache_age;
    int v2368 = v2367[v2487];
    int v2369 = v2367[v2391];
    int v2517 = v2369 + ((int)((unsigned int)(v2369 - v2368) >> 31));
    v2367[v2391] = v2517;
    int * v2371 = v2213->cache_age;
    int v2372 = v2371[v2392];
    int v2519 = v2372 + ((int)((unsigned int)(v2372 - v2368) >> 31));
    v2371[v2392] = v2519;
    int * v2374 = v2213->cache_age;
    v2374[v2487] = 0;
    v2377 = v2487;
  }
  int * v2378 = v2213->cache_vals;
  int v2522 = (v2377 * 2) + (((int)((unsigned int)v2217 >> 2)) & 1);
  v2378[v2522] = v2218;
  int * v2380 = v2213->cache_dirty;
  v2380[v2377] = 1;
  struct StateT * v2382 = slot_31(v2213);
  return v2382;
}

struct StateT * slot_4(struct StateT * v58) {
  int v59 = v58->timer;
  int v70 = v59 + 1;
  v58->timer = v70;
  int * v61 = v58->regs;
  int v62 = v61[13];
  bool v73 = -2147483648 < (v62 ^ -2147483648);
  int v65;
  if (v73) {
    v65 = 1;
  } else {
    v65 = 0;
  }
  int * v66 = v58->regs;
  v66[13] = v65;
  struct StateT * v68 = slot_5(v58);
  return v68;
}

struct StateT * slot_15(struct StateT * v999) {
  int v1000 = v999->timer;
  int v1008 = v1000 + 1;
  v999->timer = v1008;
  int * v1002 = v999->regs;
  int v1003 = v1002[7];
  int v1004 = v1002[17];
  int v1012 = v1003 ^ v1004;
  v1002[7] = v1012;
  struct StateT * v1006 = slot_16(v999);
  return v1006;
}

struct StateT * slot_18(struct StateT * v1047) {
  int v1048 = v1047->timer;
  int v1056 = v1048 + 1;
  v1047->timer = v1056;
  int * v1050 = v1047->regs;
  int v1051 = v1050[5];
  int v1052 = v1050[6];
  int v1060 = v1051 ^ v1052;
  v1050[6] = v1060;
  struct StateT * v1054 = slot_19(v1047);
  return v1054;
}

struct StateT * slot_9(struct StateT * v151) {
  int v152 = v151->timer;
  int v160 = v152 + 1;
  v151->timer = v160;
  int * v154 = v151->regs;
  int v155 = v154[11];
  int v156 = v154[15];
  int v164 = v155 + v156;
  v154[15] = v164;
  struct StateT * v158 = slot_10(v151);
  return v158;
}

struct StateT * slot_22(struct StateT * v1709) {
  int v1710 = v1709->timer;
  int v1820 = v1710 + 1;
  v1709->timer = v1820;
  int * v1712 = v1709->regs;
  int v1713 = v1712[15];
  int * v1714 = v1709->cache_tags;
  int v1824 = (((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1)) & 1) * 2;
  int v1715 = v1714[v1824];
  int v1825 = ((((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1716 = v1714[v1825];
  int v1826 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1)) & 3) * 2);
  int v1717 = v1714[v1826];
  int v1827 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1718 = v1714[v1827];
  int v1719 = v1709->timer;
  int v1828 = v1719 + ((100 ^ (((~(((v1717 ^ ((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1))) | (-(v1717 ^ ((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1718 ^ ((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1))) | (-(v1718 ^ ((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1715 ^ ((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1))) | (-(v1715 ^ ((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1716 ^ ((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1))) | (-(v1716 ^ ((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1717 ^ ((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1))) | (-(v1717 ^ ((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1718 ^ ((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1))) | (-(v1718 ^ ((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1709->timer = v1828;
  int * v1721 = v1709->cache_vals;
  bool v1829 = !(((~(((v1715 ^ ((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1))) | (-(v1715 ^ ((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1716 ^ ((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1))) | (-(v1716 ^ ((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v1814;
  if (v1829) {
    int * v1722 = v1709->cache_age;
    int v1831 = ((((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v1716 ^ ((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1))) | (-(v1716 ^ ((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v1723 = v1722[v1831];
    int v1724 = v1722[v1824];
    int v1832 = v1724 + ((int)((unsigned int)(v1724 - v1723) >> 31));
    v1722[v1824] = v1832;
    int * v1726 = v1709->cache_age;
    int v1727 = v1726[v1825];
    int v1834 = v1727 + ((int)((unsigned int)(v1727 - v1723) >> 31));
    v1726[v1825] = v1834;
    int * v1729 = v1709->cache_age;
    v1729[v1831] = 0;
    v1814 = v1831;
  } else {
    int * v1732 = v1709->cache_age;
    int v1838 = (((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1)) & 1) * 2;
    int v1733 = v1732[v1838];
    int * v1734 = v1709->cache_tags;
    int v1735 = v1734[v1838];
    int v1736 = v1732[v1825];
    int v1737 = v1734[v1825];
    bool v1840 = !(((~(((v1717 ^ ((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1))) | (-(v1717 ^ ((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1718 ^ ((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1))) | (-(v1718 ^ ((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v1791;
    if (v1840) {
      int * v1738 = v1709->cache_age;
      int v1842 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1718 ^ ((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1))) | (-(v1718 ^ ((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v1739 = v1738[v1842];
      int v1740 = v1738[v1826];
      int v1843 = v1740 + ((int)((unsigned int)(v1740 - v1739) >> 31));
      v1738[v1826] = v1843;
      int * v1742 = v1709->cache_age;
      int v1743 = v1742[v1827];
      int v1845 = v1743 + ((int)((unsigned int)(v1743 - v1739) >> 31));
      v1742[v1827] = v1845;
      int * v1745 = v1709->cache_age;
      v1745[v1842] = 0;
      v1791 = v1842;
    } else {
      int * v1748 = v1709->cache_age;
      int v1849 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1)) & 3) * 2);
      int v1749 = v1748[v1849];
      int * v1750 = v1709->cache_tags;
      int v1751 = v1750[v1849];
      int v1752 = v1748[v1827];
      int v1753 = v1750[v1827];
      int * v1754 = v1709->cache_dirty;
      int v1852 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1749 + ((~(((v1751 ^ -1) | (-(v1751 ^ -1))) >> 31)) & 2)) - (v1752 + ((~(((v1753 ^ -1) | (-(v1753 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1755 = v1754[v1852];
      bool v1853 = !(v1755 == 0);
      if (v1853) {
        int * v1756 = v1709->cache_tags;
        int v1757 = v1756[v1852];
        int * v1758 = v1709->cache_vals;
        int v1856 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1749 + ((~(((v1751 ^ -1) | (-(v1751 ^ -1))) >> 31)) & 2)) - (v1752 + ((~(((v1753 ^ -1) | (-(v1753 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1759 = v1758[v1856];
        int v1857 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1749 + ((~(((v1751 ^ -1) | (-(v1751 ^ -1))) >> 31)) & 2)) - (v1752 + ((~(((v1753 ^ -1) | (-(v1753 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1760 = v1758[v1857];
        int * v1761 = v1709->mem;
        int v1859 = v1757 * 2;
        v1761[v1859] = v1759;
        int * v1763 = v1709->mem;
        int v1862 = (v1757 * 2) + 1;
        v1763[v1862] = v1760;
        ;
      } else {
        ;
      }
      int * v1768 = v1709->mem;
      int v1867 = ((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1)) * 2;
      int v1769 = v1768[v1867];
      int v1868 = (((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1)) * 2) + 1;
      int v1770 = v1768[v1868];
      int * v1771 = v1709->cache_vals;
      int v1870 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1749 + ((~(((v1751 ^ -1) | (-(v1751 ^ -1))) >> 31)) & 2)) - (v1752 + ((~(((v1753 ^ -1) | (-(v1753 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1771[v1870] = v1769;
      int * v1773 = v1709->cache_vals;
      int v1873 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1749 + ((~(((v1751 ^ -1) | (-(v1751 ^ -1))) >> 31)) & 2)) - (v1752 + ((~(((v1753 ^ -1) | (-(v1753 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1773[v1873] = v1770;
      int * v1775 = v1709->cache_tags;
      int v1876 = (int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1);
      v1775[v1852] = v1876;
      int * v1777 = v1709->cache_dirty;
      v1777[v1852] = 0;
      int * v1779 = v1709->cache_age;
      v1779[v1852] = 1;
      int * v1781 = v1709->cache_age;
      int v1782 = v1781[v1852];
      int v1783 = v1781[v1826];
      int v1882 = v1783 + ((int)((unsigned int)(v1783 - v1782) >> 31));
      v1781[v1826] = v1882;
      int * v1785 = v1709->cache_age;
      int v1786 = v1785[v1827];
      int v1884 = v1786 + ((int)((unsigned int)(v1786 - v1782) >> 31));
      v1785[v1827] = v1884;
      int * v1788 = v1709->cache_age;
      v1788[v1852] = 0;
      v1791 = v1852;
    }
    int * v1792 = v1709->cache_vals;
    int v1887 = v1791 * 2;
    int v1793 = v1792[v1887];
    int v1888 = (v1791 * 2) + 1;
    int v1794 = v1792[v1888];
    int v1889 = (((((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1733 + ((~(((v1735 ^ -1) | (-(v1735 ^ -1))) >> 31)) & 2)) - (v1736 + ((~(((v1737 ^ -1) | (-(v1737 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1792[v1889] = v1793;
    int * v1796 = v1709->cache_vals;
    int v1892 = ((((((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1733 + ((~(((v1735 ^ -1) | (-(v1735 ^ -1))) >> 31)) & 2)) - (v1736 + ((~(((v1737 ^ -1) | (-(v1737 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1796[v1892] = v1794;
    int * v1798 = v1709->cache_tags;
    int v1895 = ((((int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1733 + ((~(((v1735 ^ -1) | (-(v1735 ^ -1))) >> 31)) & 2)) - (v1736 + ((~(((v1737 ^ -1) | (-(v1737 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1896 = (int)((unsigned int)((int)((unsigned int)(v1713 + 4) >> 2)) >> 1);
    v1798[v1895] = v1896;
    int * v1800 = v1709->cache_dirty;
    v1800[v1895] = 0;
    int * v1802 = v1709->cache_age;
    v1802[v1895] = 1;
    int * v1804 = v1709->cache_age;
    int v1805 = v1804[v1895];
    int v1806 = v1804[v1824];
    int v1902 = v1806 + ((int)((unsigned int)(v1806 - v1805) >> 31));
    v1804[v1824] = v1902;
    int * v1808 = v1709->cache_age;
    int v1809 = v1808[v1825];
    int v1904 = v1809 + ((int)((unsigned int)(v1809 - v1805) >> 31));
    v1808[v1825] = v1904;
    int * v1811 = v1709->cache_age;
    v1811[v1895] = 0;
    v1814 = v1895;
  }
  int v1907 = (v1814 * 2) + (((int)((unsigned int)(v1713 + 4) >> 2)) & 1);
  int v1815 = v1721[v1907];
  int * v1816 = v1709->regs;
  v1816[16] = v1815;
  struct StateT * v1818 = slot_23(v1709);
  return v1818;
}

struct StateT * slot_11(struct StateT * v371) {
  int v372 = v371->timer;
  int v482 = v372 + 1;
  v371->timer = v482;
  int * v374 = v371->regs;
  int v375 = v374[16];
  int * v376 = v371->cache_tags;
  int v486 = (((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1)) & 1) * 2;
  int v377 = v376[v486];
  int v487 = ((((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v378 = v376[v487];
  int v488 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1)) & 3) * 2);
  int v379 = v376[v488];
  int v489 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v380 = v376[v489];
  int v381 = v371->timer;
  int v490 = v381 + ((100 ^ (((~(((v379 ^ ((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1))) | (-(v379 ^ ((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v380 ^ ((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1))) | (-(v380 ^ ((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v377 ^ ((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1))) | (-(v377 ^ ((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v378 ^ ((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1))) | (-(v378 ^ ((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v379 ^ ((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1))) | (-(v379 ^ ((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v380 ^ ((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1))) | (-(v380 ^ ((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v371->timer = v490;
  int * v383 = v371->cache_vals;
  bool v491 = !(((~(((v377 ^ ((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1))) | (-(v377 ^ ((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v378 ^ ((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1))) | (-(v378 ^ ((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v476;
  if (v491) {
    int * v384 = v371->cache_age;
    int v493 = ((((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v378 ^ ((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1))) | (-(v378 ^ ((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v385 = v384[v493];
    int v386 = v384[v486];
    int v494 = v386 + ((int)((unsigned int)(v386 - v385) >> 31));
    v384[v486] = v494;
    int * v388 = v371->cache_age;
    int v389 = v388[v487];
    int v496 = v389 + ((int)((unsigned int)(v389 - v385) >> 31));
    v388[v487] = v496;
    int * v391 = v371->cache_age;
    v391[v493] = 0;
    v476 = v493;
  } else {
    int * v394 = v371->cache_age;
    int v500 = (((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1)) & 1) * 2;
    int v395 = v394[v500];
    int * v396 = v371->cache_tags;
    int v397 = v396[v500];
    int v398 = v394[v487];
    int v399 = v396[v487];
    bool v502 = !(((~(((v379 ^ ((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1))) | (-(v379 ^ ((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v380 ^ ((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1))) | (-(v380 ^ ((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v453;
    if (v502) {
      int * v400 = v371->cache_age;
      int v504 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v380 ^ ((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1))) | (-(v380 ^ ((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v401 = v400[v504];
      int v402 = v400[v488];
      int v505 = v402 + ((int)((unsigned int)(v402 - v401) >> 31));
      v400[v488] = v505;
      int * v404 = v371->cache_age;
      int v405 = v404[v489];
      int v507 = v405 + ((int)((unsigned int)(v405 - v401) >> 31));
      v404[v489] = v507;
      int * v407 = v371->cache_age;
      v407[v504] = 0;
      v453 = v504;
    } else {
      int * v410 = v371->cache_age;
      int v511 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1)) & 3) * 2);
      int v411 = v410[v511];
      int * v412 = v371->cache_tags;
      int v413 = v412[v511];
      int v414 = v410[v489];
      int v415 = v412[v489];
      int * v416 = v371->cache_dirty;
      int v514 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v411 + ((~(((v413 ^ -1) | (-(v413 ^ -1))) >> 31)) & 2)) - (v414 + ((~(((v415 ^ -1) | (-(v415 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v417 = v416[v514];
      bool v515 = !(v417 == 0);
      if (v515) {
        int * v418 = v371->cache_tags;
        int v419 = v418[v514];
        int * v420 = v371->cache_vals;
        int v518 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v411 + ((~(((v413 ^ -1) | (-(v413 ^ -1))) >> 31)) & 2)) - (v414 + ((~(((v415 ^ -1) | (-(v415 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v421 = v420[v518];
        int v519 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v411 + ((~(((v413 ^ -1) | (-(v413 ^ -1))) >> 31)) & 2)) - (v414 + ((~(((v415 ^ -1) | (-(v415 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v422 = v420[v519];
        int * v423 = v371->mem;
        int v521 = v419 * 2;
        v423[v521] = v421;
        int * v425 = v371->mem;
        int v524 = (v419 * 2) + 1;
        v425[v524] = v422;
        ;
      } else {
        ;
      }
      int * v430 = v371->mem;
      int v529 = ((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1)) * 2;
      int v431 = v430[v529];
      int v530 = (((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1)) * 2) + 1;
      int v432 = v430[v530];
      int * v433 = v371->cache_vals;
      int v532 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v411 + ((~(((v413 ^ -1) | (-(v413 ^ -1))) >> 31)) & 2)) - (v414 + ((~(((v415 ^ -1) | (-(v415 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v433[v532] = v431;
      int * v435 = v371->cache_vals;
      int v535 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v411 + ((~(((v413 ^ -1) | (-(v413 ^ -1))) >> 31)) & 2)) - (v414 + ((~(((v415 ^ -1) | (-(v415 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v435[v535] = v432;
      int * v437 = v371->cache_tags;
      int v538 = (int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1);
      v437[v514] = v538;
      int * v439 = v371->cache_dirty;
      v439[v514] = 0;
      int * v441 = v371->cache_age;
      v441[v514] = 1;
      int * v443 = v371->cache_age;
      int v444 = v443[v514];
      int v445 = v443[v488];
      int v544 = v445 + ((int)((unsigned int)(v445 - v444) >> 31));
      v443[v488] = v544;
      int * v447 = v371->cache_age;
      int v448 = v447[v489];
      int v546 = v448 + ((int)((unsigned int)(v448 - v444) >> 31));
      v447[v489] = v546;
      int * v450 = v371->cache_age;
      v450[v514] = 0;
      v453 = v514;
    }
    int * v454 = v371->cache_vals;
    int v549 = v453 * 2;
    int v455 = v454[v549];
    int v550 = (v453 * 2) + 1;
    int v456 = v454[v550];
    int v551 = (((((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v395 + ((~(((v397 ^ -1) | (-(v397 ^ -1))) >> 31)) & 2)) - (v398 + ((~(((v399 ^ -1) | (-(v399 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v454[v551] = v455;
    int * v458 = v371->cache_vals;
    int v554 = ((((((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v395 + ((~(((v397 ^ -1) | (-(v397 ^ -1))) >> 31)) & 2)) - (v398 + ((~(((v399 ^ -1) | (-(v399 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v458[v554] = v456;
    int * v460 = v371->cache_tags;
    int v557 = ((((int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v395 + ((~(((v397 ^ -1) | (-(v397 ^ -1))) >> 31)) & 2)) - (v398 + ((~(((v399 ^ -1) | (-(v399 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v558 = (int)((unsigned int)((int)((unsigned int)(v375 + 4) >> 2)) >> 1);
    v460[v557] = v558;
    int * v462 = v371->cache_dirty;
    v462[v557] = 0;
    int * v464 = v371->cache_age;
    v464[v557] = 1;
    int * v466 = v371->cache_age;
    int v467 = v466[v557];
    int v468 = v466[v486];
    int v564 = v468 + ((int)((unsigned int)(v468 - v467) >> 31));
    v466[v486] = v564;
    int * v470 = v371->cache_age;
    int v471 = v470[v487];
    int v566 = v471 + ((int)((unsigned int)(v471 - v467) >> 31));
    v470[v487] = v566;
    int * v473 = v371->cache_age;
    v473[v557] = 0;
    v476 = v557;
  }
  int v569 = (v476 * 2) + (((int)((unsigned int)(v375 + 4) >> 2)) & 1);
  int v477 = v383[v569];
  int * v478 = v371->regs;
  v478[5] = v477;
  struct StateT * v480 = slot_12(v371);
  return v480;
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
  
  // a10, 10 words read by the callee: the address is public
  s1.regs[10] = 0;
  s2.regs[10] = 0;
  // a11, 10 words read by the callee: the address is public
  s1.regs[11] = 40;
  s2.regs[11] = 40;
  
  // a10's contents, secret: a different draw in each state
  for (int i=0; i<10; i++) {
    s1.mem[0 + i] = secret(0, 20);
    s2.mem[0 + i] = secret(0, 20);
  }
  // a11's contents, secret: a different draw in each state
  for (int i=0; i<10; i++) {
    s1.mem[10 + i] = secret(0, 20);
    s2.mem[10 + i] = secret(0, 20);
  }
  // a12 and a13, secret: a uint64's halves, drawn separately
  // in each state
  s1.regs[12] = secret(0, 1);
  s2.regs[12] = secret(0, 1);
  s1.regs[13] = secret(0, 1);
  s2.regs[13] = secret(0, 1);
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}