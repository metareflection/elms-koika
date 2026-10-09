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

struct StateT * slot_12(struct StateT * v617);
struct StateT * slot_6(struct StateT * v305);
struct StateT * slot_29(struct StateT * v2716);
struct StateT * slot_25(struct StateT * v1958);
struct StateT * slot_16(struct StateT * v1077);
struct StateT * slot_23(struct StateT * v1734);
struct StateT * slot_5(struct StateT * v284);
struct StateT * slot_2(struct StateT * v225);
struct StateT * slot_7(struct StateT * v329);
struct StateT * slot_21(struct StateT * v1511);
struct StateT * slot_31(struct StateT * v2745);
struct StateT * slot_3(struct StateT * v233);
struct StateT * slot_10(struct StateT * v573);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_19(struct StateT * v1176);
struct StateT * slot_13(struct StateT * v638);
struct StateT * slot_24(struct StateT * v1750);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_14(struct StateT * v662);
struct StateT * slot_17(struct StateT * v1101);
struct StateT * slot_33(struct StateT * v3064);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_8(struct StateT * v536);
struct StateT * slot_4(struct StateT * v261);
struct StateT * slot_15(struct StateT * v869);
struct StateT * slot_9(struct StateT * v552);
struct StateT * slot_11(struct StateT * v596);
struct StateT * slot_12(struct StateT * v617) {
  int v618 = v617->timer;
  int v629 = v618 + 1;
  v617->timer = v629;
  int * v620 = v617->reg_ready;
  int v621 = v620[10];
  int * v622 = v617->regs;
  int v623 = v622[10];
  int v633 = (v621 + ((v618 - v621) & (~((v618 - v621) >> 31)))) + 1;
  v620[10] = v633;
  int * v625 = v617->regs;
  int v635 = (int)((unsigned int)v623 >> 26);
  v625[10] = v635;
  struct StateT * v627 = slot_13(v617);
  return v627;
}

struct StateT * slot_6(struct StateT * v305) {
  int v306 = v305->timer;
  int v319 = v306 + 1;
  v305->timer = v319;
  int * v308 = v305->reg_ready;
  int v309 = v308[11];
  int * v310 = v305->regs;
  int v311 = v310[11];
  int v312 = v308[10];
  int v313 = v310[10];
  int v324 = (v312 + (((v309 + ((v306 - v309) & (~((v306 - v309) >> 31)))) - v312) & (~(((v309 + ((v306 - v309) & (~((v306 - v309) >> 31)))) - v312) >> 31)))) + 1;
  v308[10] = v324;
  int * v315 = v305->regs;
  int v326 = v311 + v313;
  v315[10] = v326;
  struct StateT * v317 = slot_7(v305);
  return v317;
}

struct StateT * slot_29(struct StateT * v2716) {
  int v2717 = v2716->timer;
  int v2730 = v2717 + 1;
  v2716->timer = v2730;
  int * v2719 = v2716->reg_ready;
  int v2720 = v2719[12];
  int * v2721 = v2716->regs;
  int v2722 = v2721[12];
  int v2723 = v2719[10];
  int v2724 = v2721[10];
  int v2735 = (v2723 + (((v2720 + ((v2717 - v2720) & (~((v2717 - v2720) >> 31)))) - v2723) & (~(((v2720 + ((v2717 - v2720) & (~((v2717 - v2720) >> 31)))) - v2723) >> 31)))) + 1;
  v2719[10] = v2735;
  int * v2726 = v2716->regs;
  int v2737 = v2722 & v2724;
  v2726[10] = v2737;
  struct StateT * v2728 = slot_31(v2716);
  return v2728;
}

struct StateT * slot_25(struct StateT * v1958) {
  int v1959 = v1958->timer;
  int v2071 = v1959 + 1;
  v1958->timer = v2071;
  int * v1961 = v1958->reg_ready;
  int v1962 = v1961[10];
  int * v1963 = v1958->regs;
  int v1964 = v1963[10];
  int * v1965 = v1958->cache_tags;
  int v2076 = (((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1)) & 1) * 2;
  int v1966 = v1965[v2076];
  int v2077 = ((((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1967 = v1965[v2077];
  int v2078 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1)) & 3) * 2);
  int v1968 = v1965[v2078];
  int v2079 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1969 = v1965[v2079];
  int * v1970 = v1958->cache_vals;
  bool v2080 = !(((~(((v1966 ^ ((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1))) | (-(v1966 ^ ((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1967 ^ ((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1))) | (-(v1967 ^ ((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v2063;
  if (v2080) {
    int * v1971 = v1958->cache_age;
    int v2082 = ((((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v1967 ^ ((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1))) | (-(v1967 ^ ((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v1972 = v1971[v2082];
    int v1973 = v1971[v2076];
    int v2083 = v1973 + ((int)((unsigned int)(v1973 - v1972) >> 31));
    v1971[v2076] = v2083;
    int * v1975 = v1958->cache_age;
    int v1976 = v1975[v2077];
    int v2085 = v1976 + ((int)((unsigned int)(v1976 - v1972) >> 31));
    v1975[v2077] = v2085;
    int * v1978 = v1958->cache_age;
    v1978[v2082] = 0;
    v2063 = v2082;
  } else {
    int * v1981 = v1958->cache_age;
    int v2089 = (((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1)) & 1) * 2;
    int v1982 = v1981[v2089];
    int * v1983 = v1958->cache_tags;
    int v1984 = v1983[v2089];
    int v1985 = v1981[v2077];
    int v1986 = v1983[v2077];
    bool v2091 = !(((~(((v1968 ^ ((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1))) | (-(v1968 ^ ((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1969 ^ ((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1))) | (-(v1969 ^ ((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v2040;
    if (v2091) {
      int * v1987 = v1958->cache_age;
      int v2093 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1969 ^ ((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1))) | (-(v1969 ^ ((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v1988 = v1987[v2093];
      int v1989 = v1987[v2078];
      int v2094 = v1989 + ((int)((unsigned int)(v1989 - v1988) >> 31));
      v1987[v2078] = v2094;
      int * v1991 = v1958->cache_age;
      int v1992 = v1991[v2079];
      int v2096 = v1992 + ((int)((unsigned int)(v1992 - v1988) >> 31));
      v1991[v2079] = v2096;
      int * v1994 = v1958->cache_age;
      v1994[v2093] = 0;
      v2040 = v2093;
    } else {
      int * v1997 = v1958->cache_age;
      int v2100 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1)) & 3) * 2);
      int v1998 = v1997[v2100];
      int * v1999 = v1958->cache_tags;
      int v2000 = v1999[v2100];
      int v2001 = v1997[v2079];
      int v2002 = v1999[v2079];
      int * v2003 = v1958->cache_dirty;
      int v2103 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1998 + ((~(((v2000 ^ -1) | (-(v2000 ^ -1))) >> 31)) & 2)) - (v2001 + ((~(((v2002 ^ -1) | (-(v2002 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2004 = v2003[v2103];
      bool v2104 = !(v2004 == 0);
      if (v2104) {
        int * v2005 = v1958->cache_tags;
        int v2006 = v2005[v2103];
        int * v2007 = v1958->cache_vals;
        int v2107 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1998 + ((~(((v2000 ^ -1) | (-(v2000 ^ -1))) >> 31)) & 2)) - (v2001 + ((~(((v2002 ^ -1) | (-(v2002 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2008 = v2007[v2107];
        int v2108 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1998 + ((~(((v2000 ^ -1) | (-(v2000 ^ -1))) >> 31)) & 2)) - (v2001 + ((~(((v2002 ^ -1) | (-(v2002 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2009 = v2007[v2108];
        int * v2010 = v1958->mem;
        int v2110 = v2006 * 2;
        v2010[v2110] = v2008;
        int * v2012 = v1958->mem;
        int v2113 = (v2006 * 2) + 1;
        v2012[v2113] = v2009;
        ;
      } else {
        ;
      }
      int * v2017 = v1958->mem;
      int v2118 = ((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1)) * 2;
      int v2018 = v2017[v2118];
      int v2119 = (((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1)) * 2) + 1;
      int v2019 = v2017[v2119];
      int * v2020 = v1958->cache_vals;
      int v2121 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1998 + ((~(((v2000 ^ -1) | (-(v2000 ^ -1))) >> 31)) & 2)) - (v2001 + ((~(((v2002 ^ -1) | (-(v2002 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2020[v2121] = v2018;
      int * v2022 = v1958->cache_vals;
      int v2124 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1998 + ((~(((v2000 ^ -1) | (-(v2000 ^ -1))) >> 31)) & 2)) - (v2001 + ((~(((v2002 ^ -1) | (-(v2002 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2022[v2124] = v2019;
      int * v2024 = v1958->cache_tags;
      int v2127 = (int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1);
      v2024[v2103] = v2127;
      int * v2026 = v1958->cache_dirty;
      v2026[v2103] = 0;
      int * v2028 = v1958->cache_age;
      v2028[v2103] = 1;
      int * v2030 = v1958->cache_age;
      int v2031 = v2030[v2103];
      int v2032 = v2030[v2078];
      int v2133 = v2032 + ((int)((unsigned int)(v2032 - v2031) >> 31));
      v2030[v2078] = v2133;
      int * v2034 = v1958->cache_age;
      int v2035 = v2034[v2079];
      int v2135 = v2035 + ((int)((unsigned int)(v2035 - v2031) >> 31));
      v2034[v2079] = v2135;
      int * v2037 = v1958->cache_age;
      v2037[v2103] = 0;
      v2040 = v2103;
    }
    int * v2041 = v1958->cache_vals;
    int v2138 = v2040 * 2;
    int v2042 = v2041[v2138];
    int v2139 = (v2040 * 2) + 1;
    int v2043 = v2041[v2139];
    int v2140 = (((((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1982 + ((~(((v1984 ^ -1) | (-(v1984 ^ -1))) >> 31)) & 2)) - (v1985 + ((~(((v1986 ^ -1) | (-(v1986 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2041[v2140] = v2042;
    int * v2045 = v1958->cache_vals;
    int v2143 = ((((((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1982 + ((~(((v1984 ^ -1) | (-(v1984 ^ -1))) >> 31)) & 2)) - (v1985 + ((~(((v1986 ^ -1) | (-(v1986 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2045[v2143] = v2043;
    int * v2047 = v1958->cache_tags;
    int v2146 = ((((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1982 + ((~(((v1984 ^ -1) | (-(v1984 ^ -1))) >> 31)) & 2)) - (v1985 + ((~(((v1986 ^ -1) | (-(v1986 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2147 = (int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1);
    v2047[v2146] = v2147;
    int * v2049 = v1958->cache_dirty;
    v2049[v2146] = 0;
    int * v2051 = v1958->cache_age;
    v2051[v2146] = 1;
    int * v2053 = v1958->cache_age;
    int v2054 = v2053[v2146];
    int v2055 = v2053[v2076];
    int v2153 = v2055 + ((int)((unsigned int)(v2055 - v2054) >> 31));
    v2053[v2076] = v2153;
    int * v2057 = v1958->cache_age;
    int v2058 = v2057[v2077];
    int v2155 = v2058 + ((int)((unsigned int)(v2058 - v2054) >> 31));
    v2057[v2077] = v2155;
    int * v2060 = v1958->cache_age;
    v2060[v2146] = 0;
    v2063 = v2146;
  }
  int v2158 = (v2063 * 2) + (((int)((unsigned int)(v1964 + 4) >> 2)) & 1);
  int v2064 = v1970[v2158];
  int * v2065 = v1958->reg_ready;
  int v2160 = ((v1962 + ((v1959 - v1962) & (~((v1959 - v1962) >> 31)))) + 1) + ((100 ^ (((~(((v1968 ^ ((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1))) | (-(v1968 ^ ((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1969 ^ ((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1))) | (-(v1969 ^ ((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1966 ^ ((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1))) | (-(v1966 ^ ((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1967 ^ ((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1))) | (-(v1967 ^ ((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1968 ^ ((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1))) | (-(v1968 ^ ((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1969 ^ ((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1))) | (-(v1969 ^ ((int)((unsigned int)((int)((unsigned int)(v1964 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2065[10] = v2160;
  int * v2067 = v1958->regs;
  v2067[10] = v2064;
  struct StateT * v2069 = slot_24(v1958);
  return v2069;
}

struct StateT * slot_16(struct StateT * v1077) {
  int v1078 = v1077->timer;
  int v1091 = v1078 + 1;
  v1077->timer = v1091;
  int * v1080 = v1077->reg_ready;
  int v1081 = v1080[11];
  int * v1082 = v1077->regs;
  int v1083 = v1082[11];
  int v1084 = v1080[10];
  int v1085 = v1082[10];
  int v1096 = (v1084 + (((v1081 + ((v1078 - v1081) & (~((v1078 - v1081) >> 31)))) - v1084) & (~(((v1081 + ((v1078 - v1081) & (~((v1078 - v1081) >> 31)))) - v1084) >> 31)))) + 1;
  v1080[10] = v1096;
  int * v1087 = v1077->regs;
  int v1098 = v1083 & v1085;
  v1087[10] = v1098;
  struct StateT * v1089 = slot_17(v1077);
  return v1089;
}

struct StateT * slot_23(struct StateT * v1734) {
  int v1735 = v1734->timer;
  int v1743 = v1735 + 1;
  v1734->timer = v1743;
  int * v1737 = v1734->reg_ready;
  v1737[11] = v1743;
  int * v1739 = v1734->regs;
  v1739[11] = 0;
  struct StateT * v1741 = slot_25(v1734);
  return v1741;
}

struct StateT * slot_5(struct StateT * v284) {
  int v285 = v284->timer;
  int v296 = v285 + 1;
  v284->timer = v296;
  int * v287 = v284->reg_ready;
  int v288 = v287[11];
  int * v289 = v284->regs;
  int v290 = v289[11];
  int v300 = (v288 + ((v285 - v288) & (~((v285 - v288) >> 31)))) + 1;
  v287[11] = v300;
  int * v292 = v284->regs;
  int v302 = v290 + 72;
  v292[11] = v302;
  struct StateT * v294 = slot_6(v284);
  return v294;
}

struct StateT * slot_2(struct StateT * v225) {
  int v226 = v225->timer;
  int v230 = v226 + 1;
  v225->timer = v230;
  struct StateT * v228 = slot_3(v225);
  return v228;
}

struct StateT * slot_7(struct StateT * v329) {
  int v330 = v329->timer;
  int v442 = v330 + 1;
  v329->timer = v442;
  int * v332 = v329->reg_ready;
  int v333 = v332[10];
  int * v334 = v329->regs;
  int v335 = v334[10];
  int * v336 = v329->cache_tags;
  int v447 = (((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 1) * 2;
  int v337 = v336[v447];
  int v448 = ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 1) * 2) + 1;
  int v338 = v336[v448];
  int v449 = 4 + ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 3) * 2);
  int v339 = v336[v449];
  int v450 = (4 + ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v340 = v336[v450];
  int * v341 = v329->cache_vals;
  bool v451 = !(((~(((v337 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v337 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31)) | (~(((v338 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v338 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31))) == 0);
  int v434;
  if (v451) {
    int * v342 = v329->cache_age;
    int v453 = ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 1) * 2) + ((~(((v338 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v338 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31)) & 1);
    int v343 = v342[v453];
    int v344 = v342[v447];
    int v454 = v344 + ((int)((unsigned int)(v344 - v343) >> 31));
    v342[v447] = v454;
    int * v346 = v329->cache_age;
    int v347 = v346[v448];
    int v456 = v347 + ((int)((unsigned int)(v347 - v343) >> 31));
    v346[v448] = v456;
    int * v349 = v329->cache_age;
    v349[v453] = 0;
    v434 = v453;
  } else {
    int * v352 = v329->cache_age;
    int v460 = (((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 1) * 2;
    int v353 = v352[v460];
    int * v354 = v329->cache_tags;
    int v355 = v354[v460];
    int v356 = v352[v448];
    int v357 = v354[v448];
    bool v462 = !(((~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31)) | (~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31))) == 0);
    int v411;
    if (v462) {
      int * v358 = v329->cache_age;
      int v464 = (4 + ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 3) * 2)) + ((~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31)) & 1);
      int v359 = v358[v464];
      int v360 = v358[v449];
      int v465 = v360 + ((int)((unsigned int)(v360 - v359) >> 31));
      v358[v449] = v465;
      int * v362 = v329->cache_age;
      int v363 = v362[v450];
      int v467 = v363 + ((int)((unsigned int)(v363 - v359) >> 31));
      v362[v450] = v467;
      int * v365 = v329->cache_age;
      v365[v464] = 0;
      v411 = v464;
    } else {
      int * v368 = v329->cache_age;
      int v471 = 4 + ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 3) * 2);
      int v369 = v368[v471];
      int * v370 = v329->cache_tags;
      int v371 = v370[v471];
      int v372 = v368[v450];
      int v373 = v370[v450];
      int * v374 = v329->cache_dirty;
      int v474 = (4 + ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 3) * 2)) + ((((v369 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2)) - (v372 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v375 = v374[v474];
      bool v475 = !(v375 == 0);
      if (v475) {
        int * v376 = v329->cache_tags;
        int v377 = v376[v474];
        int * v378 = v329->cache_vals;
        int v478 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 3) * 2)) + ((((v369 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2)) - (v372 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v379 = v378[v478];
        int v479 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 3) * 2)) + ((((v369 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2)) - (v372 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v380 = v378[v479];
        int * v381 = v329->mem;
        int v481 = v377 * 2;
        v381[v481] = v379;
        int * v383 = v329->mem;
        int v484 = (v377 * 2) + 1;
        v383[v484] = v380;
        ;
      } else {
        ;
      }
      int * v388 = v329->mem;
      int v489 = ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) * 2;
      int v389 = v388[v489];
      int v490 = (((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) * 2) + 1;
      int v390 = v388[v490];
      int * v391 = v329->cache_vals;
      int v492 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 3) * 2)) + ((((v369 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2)) - (v372 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v391[v492] = v389;
      int * v393 = v329->cache_vals;
      int v495 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 3) * 2)) + ((((v369 + ((~(((v371 ^ -1) | (-(v371 ^ -1))) >> 31)) & 2)) - (v372 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v393[v495] = v390;
      int * v395 = v329->cache_tags;
      int v498 = (int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1);
      v395[v474] = v498;
      int * v397 = v329->cache_dirty;
      v397[v474] = 0;
      int * v399 = v329->cache_age;
      v399[v474] = 1;
      int * v401 = v329->cache_age;
      int v402 = v401[v474];
      int v403 = v401[v449];
      int v504 = v403 + ((int)((unsigned int)(v403 - v402) >> 31));
      v401[v449] = v504;
      int * v405 = v329->cache_age;
      int v406 = v405[v450];
      int v506 = v406 + ((int)((unsigned int)(v406 - v402) >> 31));
      v405[v450] = v506;
      int * v408 = v329->cache_age;
      v408[v474] = 0;
      v411 = v474;
    }
    int * v412 = v329->cache_vals;
    int v509 = v411 * 2;
    int v413 = v412[v509];
    int v510 = (v411 * 2) + 1;
    int v414 = v412[v510];
    int v511 = (((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 1) * 2) + ((((v353 + ((~(((v355 ^ -1) | (-(v355 ^ -1))) >> 31)) & 2)) - (v356 + ((~(((v357 ^ -1) | (-(v357 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v412[v511] = v413;
    int * v416 = v329->cache_vals;
    int v514 = ((((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 1) * 2) + ((((v353 + ((~(((v355 ^ -1) | (-(v355 ^ -1))) >> 31)) & 2)) - (v356 + ((~(((v357 ^ -1) | (-(v357 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v416[v514] = v414;
    int * v418 = v329->cache_tags;
    int v517 = ((((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1)) & 1) * 2) + ((((v353 + ((~(((v355 ^ -1) | (-(v355 ^ -1))) >> 31)) & 2)) - (v356 + ((~(((v357 ^ -1) | (-(v357 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v518 = (int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1);
    v418[v517] = v518;
    int * v420 = v329->cache_dirty;
    v420[v517] = 0;
    int * v422 = v329->cache_age;
    v422[v517] = 1;
    int * v424 = v329->cache_age;
    int v425 = v424[v517];
    int v426 = v424[v447];
    int v524 = v426 + ((int)((unsigned int)(v426 - v425) >> 31));
    v424[v447] = v524;
    int * v428 = v329->cache_age;
    int v429 = v428[v448];
    int v526 = v429 + ((int)((unsigned int)(v429 - v425) >> 31));
    v428[v448] = v526;
    int * v431 = v329->cache_age;
    v431[v517] = 0;
    v434 = v517;
  }
  int v529 = (v434 * 2) + (((int)((unsigned int)v335 >> 2)) & 1);
  int v435 = v341[v529];
  int * v436 = v329->reg_ready;
  int v531 = ((v333 + ((v330 - v333) & (~((v330 - v333) >> 31)))) + 1) + ((100 ^ (((~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31)) | (~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v337 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v337 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31)) | (~(((v338 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v338 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31)) | (~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)v335 >> 2)) >> 1))))) >> 31))) & 104)))));
  v436[10] = v531;
  int * v438 = v329->regs;
  v438[10] = v435;
  struct StateT * v440 = slot_8(v329);
  return v440;
}

struct StateT * slot_21(struct StateT * v1511) {
  int v1512 = v1511->timer;
  int v1520 = v1512 + 1;
  v1511->timer = v1520;
  int * v1514 = v1511->reg_ready;
  v1514[10] = v1520;
  int * v1516 = v1511->regs;
  v1516[10] = 0;
  struct StateT * v1518 = slot_23(v1511);
  return v1518;
}

struct StateT * slot_31(struct StateT * v2745) {
  int v2746 = v2745->timer;
  int v2919 = v2746 + 1;
  v2745->timer = v2919;
  int * v2748 = v2745->reg_ready;
  int * v2750 = v2745->regs;
  int v2751 = v2750[11];
  int v2753 = v2750[10];
  int * v2754 = v2745->cache_tags;
  int v2925 = (((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1)) & 1) * 2;
  int v2755 = v2754[v2925];
  int v2926 = ((((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2756 = v2754[v2926];
  int v2927 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1)) & 3) * 2);
  int v2757 = v2754[v2927];
  int v2928 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2758 = v2754[v2928];
  int v2759 = v2745->timer;
  int v2929 = v2759 + ((100 ^ (((~(((v2757 ^ ((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1))) | (-(v2757 ^ ((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2758 ^ ((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1))) | (-(v2758 ^ ((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2755 ^ ((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1))) | (-(v2755 ^ ((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2756 ^ ((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1))) | (-(v2756 ^ ((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2757 ^ ((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1))) | (-(v2757 ^ ((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2758 ^ ((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1))) | (-(v2758 ^ ((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2745->timer = v2929;
  bool v2930 = !(((~(((v2755 ^ ((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1))) | (-(v2755 ^ ((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2756 ^ ((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1))) | (-(v2756 ^ ((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v2853;
  if (v2930) {
    int * v2761 = v2745->cache_age;
    int v2932 = ((((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v2756 ^ ((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1))) | (-(v2756 ^ ((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v2762 = v2761[v2932];
    int v2763 = v2761[v2925];
    int v2933 = v2763 + ((int)((unsigned int)(v2763 - v2762) >> 31));
    v2761[v2925] = v2933;
    int * v2765 = v2745->cache_age;
    int v2766 = v2765[v2926];
    int v2935 = v2766 + ((int)((unsigned int)(v2766 - v2762) >> 31));
    v2765[v2926] = v2935;
    int * v2768 = v2745->cache_age;
    v2768[v2932] = 0;
    v2853 = v2932;
  } else {
    int * v2771 = v2745->cache_age;
    int v2939 = (((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1)) & 1) * 2;
    int v2772 = v2771[v2939];
    int * v2773 = v2745->cache_tags;
    int v2774 = v2773[v2939];
    int v2775 = v2771[v2926];
    int v2776 = v2773[v2926];
    bool v2941 = !(((~(((v2757 ^ ((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1))) | (-(v2757 ^ ((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2758 ^ ((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1))) | (-(v2758 ^ ((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v2830;
    if (v2941) {
      int * v2777 = v2745->cache_age;
      int v2943 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2758 ^ ((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1))) | (-(v2758 ^ ((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v2778 = v2777[v2943];
      int v2779 = v2777[v2927];
      int v2944 = v2779 + ((int)((unsigned int)(v2779 - v2778) >> 31));
      v2777[v2927] = v2944;
      int * v2781 = v2745->cache_age;
      int v2782 = v2781[v2928];
      int v2946 = v2782 + ((int)((unsigned int)(v2782 - v2778) >> 31));
      v2781[v2928] = v2946;
      int * v2784 = v2745->cache_age;
      v2784[v2943] = 0;
      v2830 = v2943;
    } else {
      int * v2787 = v2745->cache_age;
      int v2950 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1)) & 3) * 2);
      int v2788 = v2787[v2950];
      int * v2789 = v2745->cache_tags;
      int v2790 = v2789[v2950];
      int v2791 = v2787[v2928];
      int v2792 = v2789[v2928];
      int * v2793 = v2745->cache_dirty;
      int v2953 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2788 + ((~(((v2790 ^ -1) | (-(v2790 ^ -1))) >> 31)) & 2)) - (v2791 + ((~(((v2792 ^ -1) | (-(v2792 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2794 = v2793[v2953];
      bool v2954 = !(v2794 == 0);
      if (v2954) {
        int * v2795 = v2745->cache_tags;
        int v2796 = v2795[v2953];
        int * v2797 = v2745->cache_vals;
        int v2957 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2788 + ((~(((v2790 ^ -1) | (-(v2790 ^ -1))) >> 31)) & 2)) - (v2791 + ((~(((v2792 ^ -1) | (-(v2792 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2798 = v2797[v2957];
        int v2958 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2788 + ((~(((v2790 ^ -1) | (-(v2790 ^ -1))) >> 31)) & 2)) - (v2791 + ((~(((v2792 ^ -1) | (-(v2792 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2799 = v2797[v2958];
        int * v2800 = v2745->mem;
        int v2960 = v2796 * 2;
        v2800[v2960] = v2798;
        int * v2802 = v2745->mem;
        int v2963 = (v2796 * 2) + 1;
        v2802[v2963] = v2799;
        ;
      } else {
        ;
      }
      int * v2807 = v2745->mem;
      int v2968 = ((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1)) * 2;
      int v2808 = v2807[v2968];
      int v2969 = (((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1)) * 2) + 1;
      int v2809 = v2807[v2969];
      int * v2810 = v2745->cache_vals;
      int v2971 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2788 + ((~(((v2790 ^ -1) | (-(v2790 ^ -1))) >> 31)) & 2)) - (v2791 + ((~(((v2792 ^ -1) | (-(v2792 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2810[v2971] = v2808;
      int * v2812 = v2745->cache_vals;
      int v2974 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2788 + ((~(((v2790 ^ -1) | (-(v2790 ^ -1))) >> 31)) & 2)) - (v2791 + ((~(((v2792 ^ -1) | (-(v2792 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2812[v2974] = v2809;
      int * v2814 = v2745->cache_tags;
      int v2977 = (int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1);
      v2814[v2953] = v2977;
      int * v2816 = v2745->cache_dirty;
      v2816[v2953] = 0;
      int * v2818 = v2745->cache_age;
      v2818[v2953] = 1;
      int * v2820 = v2745->cache_age;
      int v2821 = v2820[v2953];
      int v2822 = v2820[v2927];
      int v2983 = v2822 + ((int)((unsigned int)(v2822 - v2821) >> 31));
      v2820[v2927] = v2983;
      int * v2824 = v2745->cache_age;
      int v2825 = v2824[v2928];
      int v2985 = v2825 + ((int)((unsigned int)(v2825 - v2821) >> 31));
      v2824[v2928] = v2985;
      int * v2827 = v2745->cache_age;
      v2827[v2953] = 0;
      v2830 = v2953;
    }
    int * v2831 = v2745->cache_vals;
    int v2988 = v2830 * 2;
    int v2832 = v2831[v2988];
    int v2989 = (v2830 * 2) + 1;
    int v2833 = v2831[v2989];
    int v2990 = (((((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v2772 + ((~(((v2774 ^ -1) | (-(v2774 ^ -1))) >> 31)) & 2)) - (v2775 + ((~(((v2776 ^ -1) | (-(v2776 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2831[v2990] = v2832;
    int * v2835 = v2745->cache_vals;
    int v2993 = ((((((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v2772 + ((~(((v2774 ^ -1) | (-(v2774 ^ -1))) >> 31)) & 2)) - (v2775 + ((~(((v2776 ^ -1) | (-(v2776 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2835[v2993] = v2833;
    int * v2837 = v2745->cache_tags;
    int v2996 = ((((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v2772 + ((~(((v2774 ^ -1) | (-(v2774 ^ -1))) >> 31)) & 2)) - (v2775 + ((~(((v2776 ^ -1) | (-(v2776 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2997 = (int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1);
    v2837[v2996] = v2997;
    int * v2839 = v2745->cache_dirty;
    v2839[v2996] = 0;
    int * v2841 = v2745->cache_age;
    v2841[v2996] = 1;
    int * v2843 = v2745->cache_age;
    int v2844 = v2843[v2996];
    int v2845 = v2843[v2925];
    int v3003 = v2845 + ((int)((unsigned int)(v2845 - v2844) >> 31));
    v2843[v2925] = v3003;
    int * v2847 = v2745->cache_age;
    int v2848 = v2847[v2926];
    int v3005 = v2848 + ((int)((unsigned int)(v2848 - v2844) >> 31));
    v2847[v2926] = v3005;
    int * v2850 = v2745->cache_age;
    v2850[v2996] = 0;
    v2853 = v2996;
  }
  int * v2854 = v2745->cache_vals;
  int v3008 = (v2853 * 2) + (((int)((unsigned int)(v2751 + 68) >> 2)) & 1);
  v2854[v3008] = v2753;
  int * v2856 = v2745->cache_tags;
  int v2857 = v2856[v2927];
  int v2858 = v2856[v2928];
  bool v3011 = !(((~(((v2857 ^ ((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1))) | (-(v2857 ^ ((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v2858 ^ ((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1))) | (-(v2858 ^ ((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v2912;
  if (v3011) {
    int * v2859 = v2745->cache_age;
    int v3013 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2858 ^ ((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1))) | (-(v2858 ^ ((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v2860 = v2859[v3013];
    int v2861 = v2859[v2927];
    int v3014 = v2861 + ((int)((unsigned int)(v2861 - v2860) >> 31));
    v2859[v2927] = v3014;
    int * v2863 = v2745->cache_age;
    int v2864 = v2863[v2928];
    int v3016 = v2864 + ((int)((unsigned int)(v2864 - v2860) >> 31));
    v2863[v2928] = v3016;
    int * v2866 = v2745->cache_age;
    v2866[v3013] = 0;
    v2912 = v3013;
  } else {
    int * v2869 = v2745->cache_age;
    int v3020 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1)) & 3) * 2);
    int v2870 = v2869[v3020];
    int * v2871 = v2745->cache_tags;
    int v2872 = v2871[v3020];
    int v2873 = v2869[v2928];
    int v2874 = v2871[v2928];
    int * v2875 = v2745->cache_dirty;
    int v3023 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2870 + ((~(((v2872 ^ -1) | (-(v2872 ^ -1))) >> 31)) & 2)) - (v2873 + ((~(((v2874 ^ -1) | (-(v2874 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2876 = v2875[v3023];
    bool v3024 = !(v2876 == 0);
    if (v3024) {
      int * v2877 = v2745->cache_tags;
      int v2878 = v2877[v3023];
      int * v2879 = v2745->cache_vals;
      int v3027 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2870 + ((~(((v2872 ^ -1) | (-(v2872 ^ -1))) >> 31)) & 2)) - (v2873 + ((~(((v2874 ^ -1) | (-(v2874 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v2880 = v2879[v3027];
      int v3028 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2870 + ((~(((v2872 ^ -1) | (-(v2872 ^ -1))) >> 31)) & 2)) - (v2873 + ((~(((v2874 ^ -1) | (-(v2874 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v2881 = v2879[v3028];
      int * v2882 = v2745->mem;
      int v3030 = v2878 * 2;
      v2882[v3030] = v2880;
      int * v2884 = v2745->mem;
      int v3033 = (v2878 * 2) + 1;
      v2884[v3033] = v2881;
      ;
    } else {
      ;
    }
    int * v2889 = v2745->mem;
    int v3038 = ((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1)) * 2;
    int v2890 = v2889[v3038];
    int v3039 = (((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1)) * 2) + 1;
    int v2891 = v2889[v3039];
    int * v2892 = v2745->cache_vals;
    int v3041 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2870 + ((~(((v2872 ^ -1) | (-(v2872 ^ -1))) >> 31)) & 2)) - (v2873 + ((~(((v2874 ^ -1) | (-(v2874 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2892[v3041] = v2890;
    int * v2894 = v2745->cache_vals;
    int v3044 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v2870 + ((~(((v2872 ^ -1) | (-(v2872 ^ -1))) >> 31)) & 2)) - (v2873 + ((~(((v2874 ^ -1) | (-(v2874 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2894[v3044] = v2891;
    int * v2896 = v2745->cache_tags;
    int v3047 = (int)((unsigned int)((int)((unsigned int)(v2751 + 68) >> 2)) >> 1);
    v2896[v3023] = v3047;
    int * v2898 = v2745->cache_dirty;
    v2898[v3023] = 0;
    int * v2900 = v2745->cache_age;
    v2900[v3023] = 1;
    int * v2902 = v2745->cache_age;
    int v2903 = v2902[v3023];
    int v2904 = v2902[v2927];
    int v3053 = v2904 + ((int)((unsigned int)(v2904 - v2903) >> 31));
    v2902[v2927] = v3053;
    int * v2906 = v2745->cache_age;
    int v2907 = v2906[v2928];
    int v3055 = v2907 + ((int)((unsigned int)(v2907 - v2903) >> 31));
    v2906[v2928] = v3055;
    int * v2909 = v2745->cache_age;
    v2909[v3023] = 0;
    v2912 = v3023;
  }
  int * v2913 = v2745->cache_vals;
  int v3058 = (v2912 * 2) + (((int)((unsigned int)(v2751 + 68) >> 2)) & 1);
  v2913[v3058] = v2753;
  int * v2915 = v2745->cache_dirty;
  v2915[v2912] = 1;
  struct StateT * v2917 = slot_33(v2745);
  return v2917;
}

struct StateT * slot_3(struct StateT * v233) {
  int * v234 = v233->saved_regs;
  int * v235 = v233->regs;
  int v236 = v235[10];
  v234[10] = v236;
  int v238 = v233->timer;
  int v253 = v238 + 1;
  v233->timer = v253;
  int * v240 = v233->reg_ready;
  int v241 = v240[10];
  int * v242 = v233->regs;
  int v243 = v242[10];
  int v256 = (v241 + ((v238 - v241) & (~((v238 - v241) >> 31)))) + 1;
  v240[10] = v256;
  int * v245 = v233->regs;
  int v258 = v243 << 2;
  v245[10] = v258;
  struct StateT * v247 = slot_4(v233);
  return v247;
}

struct StateT * slot_10(struct StateT * v573) {
  int * v574 = v573->saved_regs;
  int * v575 = v573->regs;
  int v576 = v575[12];
  v574[12] = v576;
  int v578 = v573->timer;
  int v590 = v578 + 1;
  v573->timer = v590;
  int * v580 = v573->reg_ready;
  v580[12] = v590;
  int * v582 = v573->regs;
  v582[12] = 0;
  struct StateT * v584 = slot_11(v573);
  return v584;
}

struct StateT * slot_1(struct StateT * v18) {
  int v19 = v18->timer;
  int v131 = v19 + 1;
  v18->timer = v131;
  int * v21 = v18->reg_ready;
  int v22 = v21[11];
  int * v23 = v18->regs;
  int v24 = v23[11];
  int * v25 = v18->cache_tags;
  int v136 = (((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2;
  int v26 = v25[v136];
  int v137 = ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + 1;
  int v27 = v25[v137];
  int v138 = 4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2);
  int v28 = v25[v138];
  int v139 = (4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v29 = v25[v139];
  int * v30 = v18->cache_vals;
  bool v140 = !(((~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) == 0);
  int v123;
  if (v140) {
    int * v31 = v18->cache_age;
    int v142 = ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + ((~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) & 1);
    int v32 = v31[v142];
    int v33 = v31[v136];
    int v143 = v33 + ((int)((unsigned int)(v33 - v32) >> 31));
    v31[v136] = v143;
    int * v35 = v18->cache_age;
    int v36 = v35[v137];
    int v145 = v36 + ((int)((unsigned int)(v36 - v32) >> 31));
    v35[v137] = v145;
    int * v38 = v18->cache_age;
    v38[v142] = 0;
    v123 = v142;
  } else {
    int * v41 = v18->cache_age;
    int v149 = (((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2;
    int v42 = v41[v149];
    int * v43 = v18->cache_tags;
    int v44 = v43[v149];
    int v45 = v41[v137];
    int v46 = v43[v137];
    bool v151 = !(((~(((v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) == 0);
    int v100;
    if (v151) {
      int * v47 = v18->cache_age;
      int v153 = (4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) & 1);
      int v48 = v47[v153];
      int v49 = v47[v138];
      int v154 = v49 + ((int)((unsigned int)(v49 - v48) >> 31));
      v47[v138] = v154;
      int * v51 = v18->cache_age;
      int v52 = v51[v139];
      int v156 = v52 + ((int)((unsigned int)(v52 - v48) >> 31));
      v51[v139] = v156;
      int * v54 = v18->cache_age;
      v54[v153] = 0;
      v100 = v153;
    } else {
      int * v57 = v18->cache_age;
      int v160 = 4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2);
      int v58 = v57[v160];
      int * v59 = v18->cache_tags;
      int v60 = v59[v160];
      int v61 = v57[v139];
      int v62 = v59[v139];
      int * v63 = v18->cache_dirty;
      int v163 = (4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v64 = v63[v163];
      bool v164 = !(v64 == 0);
      if (v164) {
        int * v65 = v18->cache_tags;
        int v66 = v65[v163];
        int * v67 = v18->cache_vals;
        int v167 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v68 = v67[v167];
        int v168 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v69 = v67[v168];
        int * v70 = v18->mem;
        int v170 = v66 * 2;
        v70[v170] = v68;
        int * v72 = v18->mem;
        int v173 = (v66 * 2) + 1;
        v72[v173] = v69;
        ;
      } else {
        ;
      }
      int * v77 = v18->mem;
      int v178 = ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) * 2;
      int v78 = v77[v178];
      int v179 = (((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) * 2) + 1;
      int v79 = v77[v179];
      int * v80 = v18->cache_vals;
      int v181 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v80[v181] = v78;
      int * v82 = v18->cache_vals;
      int v184 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 3) * 2)) + ((((v58 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2)) - (v61 + ((~(((v62 ^ -1) | (-(v62 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v82[v184] = v79;
      int * v84 = v18->cache_tags;
      int v187 = (int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1);
      v84[v163] = v187;
      int * v86 = v18->cache_dirty;
      v86[v163] = 0;
      int * v88 = v18->cache_age;
      v88[v163] = 1;
      int * v90 = v18->cache_age;
      int v91 = v90[v163];
      int v92 = v90[v138];
      int v193 = v92 + ((int)((unsigned int)(v92 - v91) >> 31));
      v90[v138] = v193;
      int * v94 = v18->cache_age;
      int v95 = v94[v139];
      int v195 = v95 + ((int)((unsigned int)(v95 - v91) >> 31));
      v94[v139] = v195;
      int * v97 = v18->cache_age;
      v97[v163] = 0;
      v100 = v163;
    }
    int * v101 = v18->cache_vals;
    int v198 = v100 * 2;
    int v102 = v101[v198];
    int v199 = (v100 * 2) + 1;
    int v103 = v101[v199];
    int v200 = (((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v101[v200] = v102;
    int * v105 = v18->cache_vals;
    int v203 = ((((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v105[v203] = v103;
    int * v107 = v18->cache_tags;
    int v206 = ((((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1)) & 1) * 2) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v207 = (int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1);
    v107[v206] = v207;
    int * v109 = v18->cache_dirty;
    v109[v206] = 0;
    int * v111 = v18->cache_age;
    v111[v206] = 1;
    int * v113 = v18->cache_age;
    int v114 = v113[v206];
    int v115 = v113[v136];
    int v213 = v115 + ((int)((unsigned int)(v115 - v114) >> 31));
    v113[v136] = v213;
    int * v117 = v18->cache_age;
    int v118 = v117[v137];
    int v215 = v118 + ((int)((unsigned int)(v118 - v114) >> 31));
    v117[v137] = v215;
    int * v120 = v18->cache_age;
    v120[v206] = 0;
    v123 = v206;
  }
  int v218 = (v123 * 2) + (((int)((unsigned int)v24 >> 2)) & 1);
  int v124 = v30[v218];
  int * v125 = v18->reg_ready;
  int v220 = ((v22 + ((v19 - v22) & (~((v19 - v22) >> 31)))) + 1) + ((100 ^ (((~(((v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v27 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v28 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31)) | (~(((v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))) | (-(v29 ^ ((int)((unsigned int)((int)((unsigned int)v24 >> 2)) >> 1))))) >> 31))) & 104)))));
  v125[11] = v220;
  int * v127 = v18->regs;
  v127[11] = v124;
  struct StateT * v129 = slot_2(v18);
  return v129;
}

struct StateT * slot_19(struct StateT * v1176) {
  int v1177 = v1176->timer;
  int v1350 = v1177 + 1;
  v1176->timer = v1350;
  int * v1179 = v1176->reg_ready;
  int * v1181 = v1176->regs;
  int v1182 = v1181[12];
  int v1184 = v1181[10];
  int * v1185 = v1176->cache_tags;
  int v1356 = (((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1186 = v1185[v1356];
  int v1357 = ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1187 = v1185[v1357];
  int v1358 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1188 = v1185[v1358];
  int v1359 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1189 = v1185[v1359];
  int v1190 = v1176->timer;
  int v1360 = v1190 + ((100 ^ (((~(((v1188 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))) | (-(v1188 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1189 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))) | (-(v1189 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1186 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))) | (-(v1186 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1187 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))) | (-(v1187 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1188 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))) | (-(v1188 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1189 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))) | (-(v1189 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1176->timer = v1360;
  bool v1361 = !(((~(((v1186 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))) | (-(v1186 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1187 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))) | (-(v1187 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1284;
  if (v1361) {
    int * v1192 = v1176->cache_age;
    int v1363 = ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1187 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))) | (-(v1187 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1193 = v1192[v1363];
    int v1194 = v1192[v1356];
    int v1364 = v1194 + ((int)((unsigned int)(v1194 - v1193) >> 31));
    v1192[v1356] = v1364;
    int * v1196 = v1176->cache_age;
    int v1197 = v1196[v1357];
    int v1366 = v1197 + ((int)((unsigned int)(v1197 - v1193) >> 31));
    v1196[v1357] = v1366;
    int * v1199 = v1176->cache_age;
    v1199[v1363] = 0;
    v1284 = v1363;
  } else {
    int * v1202 = v1176->cache_age;
    int v1370 = (((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1203 = v1202[v1370];
    int * v1204 = v1176->cache_tags;
    int v1205 = v1204[v1370];
    int v1206 = v1202[v1357];
    int v1207 = v1204[v1357];
    bool v1372 = !(((~(((v1188 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))) | (-(v1188 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1189 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))) | (-(v1189 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1261;
    if (v1372) {
      int * v1208 = v1176->cache_age;
      int v1374 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1189 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))) | (-(v1189 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1209 = v1208[v1374];
      int v1210 = v1208[v1358];
      int v1375 = v1210 + ((int)((unsigned int)(v1210 - v1209) >> 31));
      v1208[v1358] = v1375;
      int * v1212 = v1176->cache_age;
      int v1213 = v1212[v1359];
      int v1377 = v1213 + ((int)((unsigned int)(v1213 - v1209) >> 31));
      v1212[v1359] = v1377;
      int * v1215 = v1176->cache_age;
      v1215[v1374] = 0;
      v1261 = v1374;
    } else {
      int * v1218 = v1176->cache_age;
      int v1381 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1219 = v1218[v1381];
      int * v1220 = v1176->cache_tags;
      int v1221 = v1220[v1381];
      int v1222 = v1218[v1359];
      int v1223 = v1220[v1359];
      int * v1224 = v1176->cache_dirty;
      int v1384 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1219 + ((~(((v1221 ^ -1) | (-(v1221 ^ -1))) >> 31)) & 2)) - (v1222 + ((~(((v1223 ^ -1) | (-(v1223 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1225 = v1224[v1384];
      bool v1385 = !(v1225 == 0);
      if (v1385) {
        int * v1226 = v1176->cache_tags;
        int v1227 = v1226[v1384];
        int * v1228 = v1176->cache_vals;
        int v1388 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1219 + ((~(((v1221 ^ -1) | (-(v1221 ^ -1))) >> 31)) & 2)) - (v1222 + ((~(((v1223 ^ -1) | (-(v1223 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1229 = v1228[v1388];
        int v1389 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1219 + ((~(((v1221 ^ -1) | (-(v1221 ^ -1))) >> 31)) & 2)) - (v1222 + ((~(((v1223 ^ -1) | (-(v1223 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1230 = v1228[v1389];
        int * v1231 = v1176->mem;
        int v1391 = v1227 * 2;
        v1231[v1391] = v1229;
        int * v1233 = v1176->mem;
        int v1394 = (v1227 * 2) + 1;
        v1233[v1394] = v1230;
        ;
      } else {
        ;
      }
      int * v1238 = v1176->mem;
      int v1399 = ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) * 2;
      int v1239 = v1238[v1399];
      int v1400 = (((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1240 = v1238[v1400];
      int * v1241 = v1176->cache_vals;
      int v1402 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1219 + ((~(((v1221 ^ -1) | (-(v1221 ^ -1))) >> 31)) & 2)) - (v1222 + ((~(((v1223 ^ -1) | (-(v1223 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1241[v1402] = v1239;
      int * v1243 = v1176->cache_vals;
      int v1405 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1219 + ((~(((v1221 ^ -1) | (-(v1221 ^ -1))) >> 31)) & 2)) - (v1222 + ((~(((v1223 ^ -1) | (-(v1223 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1243[v1405] = v1240;
      int * v1245 = v1176->cache_tags;
      int v1408 = (int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1);
      v1245[v1384] = v1408;
      int * v1247 = v1176->cache_dirty;
      v1247[v1384] = 0;
      int * v1249 = v1176->cache_age;
      v1249[v1384] = 1;
      int * v1251 = v1176->cache_age;
      int v1252 = v1251[v1384];
      int v1253 = v1251[v1358];
      int v1414 = v1253 + ((int)((unsigned int)(v1253 - v1252) >> 31));
      v1251[v1358] = v1414;
      int * v1255 = v1176->cache_age;
      int v1256 = v1255[v1359];
      int v1416 = v1256 + ((int)((unsigned int)(v1256 - v1252) >> 31));
      v1255[v1359] = v1416;
      int * v1258 = v1176->cache_age;
      v1258[v1384] = 0;
      v1261 = v1384;
    }
    int * v1262 = v1176->cache_vals;
    int v1419 = v1261 * 2;
    int v1263 = v1262[v1419];
    int v1420 = (v1261 * 2) + 1;
    int v1264 = v1262[v1420];
    int v1421 = (((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1203 + ((~(((v1205 ^ -1) | (-(v1205 ^ -1))) >> 31)) & 2)) - (v1206 + ((~(((v1207 ^ -1) | (-(v1207 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1262[v1421] = v1263;
    int * v1266 = v1176->cache_vals;
    int v1424 = ((((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1203 + ((~(((v1205 ^ -1) | (-(v1205 ^ -1))) >> 31)) & 2)) - (v1206 + ((~(((v1207 ^ -1) | (-(v1207 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1266[v1424] = v1264;
    int * v1268 = v1176->cache_tags;
    int v1427 = ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1203 + ((~(((v1205 ^ -1) | (-(v1205 ^ -1))) >> 31)) & 2)) - (v1206 + ((~(((v1207 ^ -1) | (-(v1207 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1428 = (int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1);
    v1268[v1427] = v1428;
    int * v1270 = v1176->cache_dirty;
    v1270[v1427] = 0;
    int * v1272 = v1176->cache_age;
    v1272[v1427] = 1;
    int * v1274 = v1176->cache_age;
    int v1275 = v1274[v1427];
    int v1276 = v1274[v1356];
    int v1434 = v1276 + ((int)((unsigned int)(v1276 - v1275) >> 31));
    v1274[v1356] = v1434;
    int * v1278 = v1176->cache_age;
    int v1279 = v1278[v1357];
    int v1436 = v1279 + ((int)((unsigned int)(v1279 - v1275) >> 31));
    v1278[v1357] = v1436;
    int * v1281 = v1176->cache_age;
    v1281[v1427] = 0;
    v1284 = v1427;
  }
  int * v1285 = v1176->cache_vals;
  int v1439 = (v1284 * 2) + (((int)((unsigned int)(v1182 + 68) >> 2)) & 1);
  v1285[v1439] = v1184;
  int * v1287 = v1176->cache_tags;
  int v1288 = v1287[v1358];
  int v1289 = v1287[v1359];
  bool v1442 = !(((~(((v1288 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))) | (-(v1288 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1289 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))) | (-(v1289 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1343;
  if (v1442) {
    int * v1290 = v1176->cache_age;
    int v1444 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1289 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))) | (-(v1289 ^ ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1291 = v1290[v1444];
    int v1292 = v1290[v1358];
    int v1445 = v1292 + ((int)((unsigned int)(v1292 - v1291) >> 31));
    v1290[v1358] = v1445;
    int * v1294 = v1176->cache_age;
    int v1295 = v1294[v1359];
    int v1447 = v1295 + ((int)((unsigned int)(v1295 - v1291) >> 31));
    v1294[v1359] = v1447;
    int * v1297 = v1176->cache_age;
    v1297[v1444] = 0;
    v1343 = v1444;
  } else {
    int * v1300 = v1176->cache_age;
    int v1451 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1301 = v1300[v1451];
    int * v1302 = v1176->cache_tags;
    int v1303 = v1302[v1451];
    int v1304 = v1300[v1359];
    int v1305 = v1302[v1359];
    int * v1306 = v1176->cache_dirty;
    int v1454 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1301 + ((~(((v1303 ^ -1) | (-(v1303 ^ -1))) >> 31)) & 2)) - (v1304 + ((~(((v1305 ^ -1) | (-(v1305 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1307 = v1306[v1454];
    bool v1455 = !(v1307 == 0);
    if (v1455) {
      int * v1308 = v1176->cache_tags;
      int v1309 = v1308[v1454];
      int * v1310 = v1176->cache_vals;
      int v1458 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1301 + ((~(((v1303 ^ -1) | (-(v1303 ^ -1))) >> 31)) & 2)) - (v1304 + ((~(((v1305 ^ -1) | (-(v1305 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1311 = v1310[v1458];
      int v1459 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1301 + ((~(((v1303 ^ -1) | (-(v1303 ^ -1))) >> 31)) & 2)) - (v1304 + ((~(((v1305 ^ -1) | (-(v1305 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1312 = v1310[v1459];
      int * v1313 = v1176->mem;
      int v1461 = v1309 * 2;
      v1313[v1461] = v1311;
      int * v1315 = v1176->mem;
      int v1464 = (v1309 * 2) + 1;
      v1315[v1464] = v1312;
      ;
    } else {
      ;
    }
    int * v1320 = v1176->mem;
    int v1469 = ((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) * 2;
    int v1321 = v1320[v1469];
    int v1470 = (((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1322 = v1320[v1470];
    int * v1323 = v1176->cache_vals;
    int v1472 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1301 + ((~(((v1303 ^ -1) | (-(v1303 ^ -1))) >> 31)) & 2)) - (v1304 + ((~(((v1305 ^ -1) | (-(v1305 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1323[v1472] = v1321;
    int * v1325 = v1176->cache_vals;
    int v1475 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1301 + ((~(((v1303 ^ -1) | (-(v1303 ^ -1))) >> 31)) & 2)) - (v1304 + ((~(((v1305 ^ -1) | (-(v1305 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1325[v1475] = v1322;
    int * v1327 = v1176->cache_tags;
    int v1478 = (int)((unsigned int)((int)((unsigned int)(v1182 + 68) >> 2)) >> 1);
    v1327[v1454] = v1478;
    int * v1329 = v1176->cache_dirty;
    v1329[v1454] = 0;
    int * v1331 = v1176->cache_age;
    v1331[v1454] = 1;
    int * v1333 = v1176->cache_age;
    int v1334 = v1333[v1454];
    int v1335 = v1333[v1358];
    int v1484 = v1335 + ((int)((unsigned int)(v1335 - v1334) >> 31));
    v1333[v1358] = v1484;
    int * v1337 = v1176->cache_age;
    int v1338 = v1337[v1359];
    int v1486 = v1338 + ((int)((unsigned int)(v1338 - v1334) >> 31));
    v1337[v1359] = v1486;
    int * v1340 = v1176->cache_age;
    v1340[v1454] = 0;
    v1343 = v1454;
  }
  int * v1344 = v1176->cache_vals;
  int v1489 = (v1343 * 2) + (((int)((unsigned int)(v1182 + 68) >> 2)) & 1);
  v1344[v1489] = v1184;
  int * v1346 = v1176->cache_dirty;
  v1346[v1343] = 1;
  struct StateT * v1348 = slot_21(v1176);
  return v1348;
}

struct StateT * slot_13(struct StateT * v638) {
  int v639 = v638->timer;
  int v652 = v639 + 1;
  v638->timer = v652;
  int * v641 = v638->reg_ready;
  int v642 = v641[11];
  int * v643 = v638->regs;
  int v644 = v643[11];
  int v645 = v641[10];
  int v646 = v643[10];
  int v657 = (v645 + (((v642 + ((v639 - v642) & (~((v639 - v642) >> 31)))) - v645) & (~(((v642 + ((v639 - v642) & (~((v639 - v642) >> 31)))) - v645) >> 31)))) + 1;
  v641[10] = v657;
  int * v648 = v638->regs;
  int v659 = v644 + v646;
  v648[10] = v659;
  struct StateT * v650 = slot_14(v638);
  return v650;
}

struct StateT * slot_24(struct StateT * v1750) {
  int v1751 = v1750->timer;
  int v1863 = v1751 + 1;
  v1750->timer = v1863;
  int * v1753 = v1750->reg_ready;
  int v1754 = v1753[11];
  int * v1755 = v1750->regs;
  int v1756 = v1755[11];
  int * v1757 = v1750->cache_tags;
  int v1868 = (((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1758 = v1757[v1868];
  int v1869 = ((((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1759 = v1757[v1869];
  int v1870 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1760 = v1757[v1870];
  int v1871 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1761 = v1757[v1871];
  int * v1762 = v1750->cache_vals;
  bool v1872 = !(((~(((v1758 ^ ((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1))) | (-(v1758 ^ ((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1759 ^ ((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1))) | (-(v1759 ^ ((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1855;
  if (v1872) {
    int * v1763 = v1750->cache_age;
    int v1874 = ((((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1759 ^ ((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1))) | (-(v1759 ^ ((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1764 = v1763[v1874];
    int v1765 = v1763[v1868];
    int v1875 = v1765 + ((int)((unsigned int)(v1765 - v1764) >> 31));
    v1763[v1868] = v1875;
    int * v1767 = v1750->cache_age;
    int v1768 = v1767[v1869];
    int v1877 = v1768 + ((int)((unsigned int)(v1768 - v1764) >> 31));
    v1767[v1869] = v1877;
    int * v1770 = v1750->cache_age;
    v1770[v1874] = 0;
    v1855 = v1874;
  } else {
    int * v1773 = v1750->cache_age;
    int v1881 = (((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1774 = v1773[v1881];
    int * v1775 = v1750->cache_tags;
    int v1776 = v1775[v1881];
    int v1777 = v1773[v1869];
    int v1778 = v1775[v1869];
    bool v1883 = !(((~(((v1760 ^ ((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1))) | (-(v1760 ^ ((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1761 ^ ((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1))) | (-(v1761 ^ ((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1832;
    if (v1883) {
      int * v1779 = v1750->cache_age;
      int v1885 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1761 ^ ((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1))) | (-(v1761 ^ ((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1780 = v1779[v1885];
      int v1781 = v1779[v1870];
      int v1886 = v1781 + ((int)((unsigned int)(v1781 - v1780) >> 31));
      v1779[v1870] = v1886;
      int * v1783 = v1750->cache_age;
      int v1784 = v1783[v1871];
      int v1888 = v1784 + ((int)((unsigned int)(v1784 - v1780) >> 31));
      v1783[v1871] = v1888;
      int * v1786 = v1750->cache_age;
      v1786[v1885] = 0;
      v1832 = v1885;
    } else {
      int * v1789 = v1750->cache_age;
      int v1892 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1790 = v1789[v1892];
      int * v1791 = v1750->cache_tags;
      int v1792 = v1791[v1892];
      int v1793 = v1789[v1871];
      int v1794 = v1791[v1871];
      int * v1795 = v1750->cache_dirty;
      int v1895 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1790 + ((~(((v1792 ^ -1) | (-(v1792 ^ -1))) >> 31)) & 2)) - (v1793 + ((~(((v1794 ^ -1) | (-(v1794 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1796 = v1795[v1895];
      bool v1896 = !(v1796 == 0);
      if (v1896) {
        int * v1797 = v1750->cache_tags;
        int v1798 = v1797[v1895];
        int * v1799 = v1750->cache_vals;
        int v1899 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1790 + ((~(((v1792 ^ -1) | (-(v1792 ^ -1))) >> 31)) & 2)) - (v1793 + ((~(((v1794 ^ -1) | (-(v1794 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1800 = v1799[v1899];
        int v1900 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1790 + ((~(((v1792 ^ -1) | (-(v1792 ^ -1))) >> 31)) & 2)) - (v1793 + ((~(((v1794 ^ -1) | (-(v1794 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1801 = v1799[v1900];
        int * v1802 = v1750->mem;
        int v1902 = v1798 * 2;
        v1802[v1902] = v1800;
        int * v1804 = v1750->mem;
        int v1905 = (v1798 * 2) + 1;
        v1804[v1905] = v1801;
        ;
      } else {
        ;
      }
      int * v1809 = v1750->mem;
      int v1910 = ((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1)) * 2;
      int v1810 = v1809[v1910];
      int v1911 = (((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1811 = v1809[v1911];
      int * v1812 = v1750->cache_vals;
      int v1913 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1790 + ((~(((v1792 ^ -1) | (-(v1792 ^ -1))) >> 31)) & 2)) - (v1793 + ((~(((v1794 ^ -1) | (-(v1794 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1812[v1913] = v1810;
      int * v1814 = v1750->cache_vals;
      int v1916 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1790 + ((~(((v1792 ^ -1) | (-(v1792 ^ -1))) >> 31)) & 2)) - (v1793 + ((~(((v1794 ^ -1) | (-(v1794 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1814[v1916] = v1811;
      int * v1816 = v1750->cache_tags;
      int v1919 = (int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1);
      v1816[v1895] = v1919;
      int * v1818 = v1750->cache_dirty;
      v1818[v1895] = 0;
      int * v1820 = v1750->cache_age;
      v1820[v1895] = 1;
      int * v1822 = v1750->cache_age;
      int v1823 = v1822[v1895];
      int v1824 = v1822[v1870];
      int v1925 = v1824 + ((int)((unsigned int)(v1824 - v1823) >> 31));
      v1822[v1870] = v1925;
      int * v1826 = v1750->cache_age;
      int v1827 = v1826[v1871];
      int v1927 = v1827 + ((int)((unsigned int)(v1827 - v1823) >> 31));
      v1826[v1871] = v1927;
      int * v1829 = v1750->cache_age;
      v1829[v1895] = 0;
      v1832 = v1895;
    }
    int * v1833 = v1750->cache_vals;
    int v1930 = v1832 * 2;
    int v1834 = v1833[v1930];
    int v1931 = (v1832 * 2) + 1;
    int v1835 = v1833[v1931];
    int v1932 = (((((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1774 + ((~(((v1776 ^ -1) | (-(v1776 ^ -1))) >> 31)) & 2)) - (v1777 + ((~(((v1778 ^ -1) | (-(v1778 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1833[v1932] = v1834;
    int * v1837 = v1750->cache_vals;
    int v1935 = ((((((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1774 + ((~(((v1776 ^ -1) | (-(v1776 ^ -1))) >> 31)) & 2)) - (v1777 + ((~(((v1778 ^ -1) | (-(v1778 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1837[v1935] = v1835;
    int * v1839 = v1750->cache_tags;
    int v1938 = ((((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1774 + ((~(((v1776 ^ -1) | (-(v1776 ^ -1))) >> 31)) & 2)) - (v1777 + ((~(((v1778 ^ -1) | (-(v1778 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1939 = (int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1);
    v1839[v1938] = v1939;
    int * v1841 = v1750->cache_dirty;
    v1841[v1938] = 0;
    int * v1843 = v1750->cache_age;
    v1843[v1938] = 1;
    int * v1845 = v1750->cache_age;
    int v1846 = v1845[v1938];
    int v1847 = v1845[v1868];
    int v1945 = v1847 + ((int)((unsigned int)(v1847 - v1846) >> 31));
    v1845[v1868] = v1945;
    int * v1849 = v1750->cache_age;
    int v1850 = v1849[v1869];
    int v1947 = v1850 + ((int)((unsigned int)(v1850 - v1846) >> 31));
    v1849[v1869] = v1947;
    int * v1852 = v1750->cache_age;
    v1852[v1938] = 0;
    v1855 = v1938;
  }
  int v1950 = (v1855 * 2) + (((int)((unsigned int)(v1756 + 68) >> 2)) & 1);
  int v1856 = v1762[v1950];
  int * v1857 = v1750->reg_ready;
  int v1953 = ((v1754 + ((v1751 - v1754) & (~((v1751 - v1754) >> 31)))) + 1) + ((100 ^ (((~(((v1760 ^ ((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1))) | (-(v1760 ^ ((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1761 ^ ((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1))) | (-(v1761 ^ ((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1758 ^ ((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1))) | (-(v1758 ^ ((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1759 ^ ((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1))) | (-(v1759 ^ ((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1760 ^ ((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1))) | (-(v1760 ^ ((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1761 ^ ((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1))) | (-(v1761 ^ ((int)((unsigned int)((int)((unsigned int)(v1756 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1857[12] = v1953;
  int * v1859 = v1750->regs;
  v1859[12] = v1856;
  struct StateT * v1861 = slot_29(v1750);
  return v1861;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->reg_ready;
  v5[11] = v11;
  int * v7 = v2->regs;
  v7[11] = 0;
  struct StateT * v9 = slot_1(v2);
  return v9;
}

struct StateT * slot_14(struct StateT * v662) {
  int v663 = v662->timer;
  int v775 = v663 + 1;
  v662->timer = v775;
  int * v665 = v662->reg_ready;
  int v666 = v665[10];
  int * v667 = v662->regs;
  int v668 = v667[10];
  int * v669 = v662->cache_tags;
  int v780 = (((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 1) * 2;
  int v670 = v669[v780];
  int v781 = ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 1) * 2) + 1;
  int v671 = v669[v781];
  int v782 = 4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2);
  int v672 = v669[v782];
  int v783 = (4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v673 = v669[v783];
  int * v674 = v662->cache_vals;
  bool v784 = !(((~(((v670 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v670 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31)) | (~(((v671 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v671 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31))) == 0);
  int v767;
  if (v784) {
    int * v675 = v662->cache_age;
    int v786 = ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 1) * 2) + ((~(((v671 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v671 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31)) & 1);
    int v676 = v675[v786];
    int v677 = v675[v780];
    int v787 = v677 + ((int)((unsigned int)(v677 - v676) >> 31));
    v675[v780] = v787;
    int * v679 = v662->cache_age;
    int v680 = v679[v781];
    int v789 = v680 + ((int)((unsigned int)(v680 - v676) >> 31));
    v679[v781] = v789;
    int * v682 = v662->cache_age;
    v682[v786] = 0;
    v767 = v786;
  } else {
    int * v685 = v662->cache_age;
    int v793 = (((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 1) * 2;
    int v686 = v685[v793];
    int * v687 = v662->cache_tags;
    int v688 = v687[v793];
    int v689 = v685[v781];
    int v690 = v687[v781];
    bool v795 = !(((~(((v672 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v672 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31)) | (~(((v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31))) == 0);
    int v744;
    if (v795) {
      int * v691 = v662->cache_age;
      int v797 = (4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2)) + ((~(((v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31)) & 1);
      int v692 = v691[v797];
      int v693 = v691[v782];
      int v798 = v693 + ((int)((unsigned int)(v693 - v692) >> 31));
      v691[v782] = v798;
      int * v695 = v662->cache_age;
      int v696 = v695[v783];
      int v800 = v696 + ((int)((unsigned int)(v696 - v692) >> 31));
      v695[v783] = v800;
      int * v698 = v662->cache_age;
      v698[v797] = 0;
      v744 = v797;
    } else {
      int * v701 = v662->cache_age;
      int v804 = 4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2);
      int v702 = v701[v804];
      int * v703 = v662->cache_tags;
      int v704 = v703[v804];
      int v705 = v701[v783];
      int v706 = v703[v783];
      int * v707 = v662->cache_dirty;
      int v807 = (4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2)) + ((((v702 + ((~(((v704 ^ -1) | (-(v704 ^ -1))) >> 31)) & 2)) - (v705 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v708 = v707[v807];
      bool v808 = !(v708 == 0);
      if (v808) {
        int * v709 = v662->cache_tags;
        int v710 = v709[v807];
        int * v711 = v662->cache_vals;
        int v811 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2)) + ((((v702 + ((~(((v704 ^ -1) | (-(v704 ^ -1))) >> 31)) & 2)) - (v705 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v712 = v711[v811];
        int v812 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2)) + ((((v702 + ((~(((v704 ^ -1) | (-(v704 ^ -1))) >> 31)) & 2)) - (v705 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v713 = v711[v812];
        int * v714 = v662->mem;
        int v814 = v710 * 2;
        v714[v814] = v712;
        int * v716 = v662->mem;
        int v817 = (v710 * 2) + 1;
        v716[v817] = v713;
        ;
      } else {
        ;
      }
      int * v721 = v662->mem;
      int v822 = ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) * 2;
      int v722 = v721[v822];
      int v823 = (((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) * 2) + 1;
      int v723 = v721[v823];
      int * v724 = v662->cache_vals;
      int v825 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2)) + ((((v702 + ((~(((v704 ^ -1) | (-(v704 ^ -1))) >> 31)) & 2)) - (v705 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v724[v825] = v722;
      int * v726 = v662->cache_vals;
      int v828 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 3) * 2)) + ((((v702 + ((~(((v704 ^ -1) | (-(v704 ^ -1))) >> 31)) & 2)) - (v705 + ((~(((v706 ^ -1) | (-(v706 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v726[v828] = v723;
      int * v728 = v662->cache_tags;
      int v831 = (int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1);
      v728[v807] = v831;
      int * v730 = v662->cache_dirty;
      v730[v807] = 0;
      int * v732 = v662->cache_age;
      v732[v807] = 1;
      int * v734 = v662->cache_age;
      int v735 = v734[v807];
      int v736 = v734[v782];
      int v837 = v736 + ((int)((unsigned int)(v736 - v735) >> 31));
      v734[v782] = v837;
      int * v738 = v662->cache_age;
      int v739 = v738[v783];
      int v839 = v739 + ((int)((unsigned int)(v739 - v735) >> 31));
      v738[v783] = v839;
      int * v741 = v662->cache_age;
      v741[v807] = 0;
      v744 = v807;
    }
    int * v745 = v662->cache_vals;
    int v842 = v744 * 2;
    int v746 = v745[v842];
    int v843 = (v744 * 2) + 1;
    int v747 = v745[v843];
    int v844 = (((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 1) * 2) + ((((v686 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2)) - (v689 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v745[v844] = v746;
    int * v749 = v662->cache_vals;
    int v847 = ((((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 1) * 2) + ((((v686 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2)) - (v689 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v749[v847] = v747;
    int * v751 = v662->cache_tags;
    int v850 = ((((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1)) & 1) * 2) + ((((v686 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2)) - (v689 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v851 = (int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1);
    v751[v850] = v851;
    int * v753 = v662->cache_dirty;
    v753[v850] = 0;
    int * v755 = v662->cache_age;
    v755[v850] = 1;
    int * v757 = v662->cache_age;
    int v758 = v757[v850];
    int v759 = v757[v780];
    int v857 = v759 + ((int)((unsigned int)(v759 - v758) >> 31));
    v757[v780] = v857;
    int * v761 = v662->cache_age;
    int v762 = v761[v781];
    int v859 = v762 + ((int)((unsigned int)(v762 - v758) >> 31));
    v761[v781] = v859;
    int * v764 = v662->cache_age;
    v764[v850] = 0;
    v767 = v850;
  }
  int v862 = (v767 * 2) + (((int)((unsigned int)v668 >> 2)) & 1);
  int v768 = v674[v862];
  int * v769 = v662->reg_ready;
  int v864 = ((v666 + ((v663 - v666) & (~((v663 - v666) >> 31)))) + 1) + ((100 ^ (((~(((v672 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v672 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31)) | (~(((v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v670 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v670 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31)) | (~(((v671 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v671 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v672 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v672 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31)) | (~(((v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))) | (-(v673 ^ ((int)((unsigned int)((int)((unsigned int)v668 >> 2)) >> 1))))) >> 31))) & 104)))));
  v769[10] = v864;
  int * v771 = v662->regs;
  v771[10] = v768;
  struct StateT * v773 = slot_15(v662);
  return v773;
}

struct StateT * slot_17(struct StateT * v1101) {
  int * v1102 = v1101->saved_regs;
  int v1103 = v1102[10];
  int v1104 = v1102[11];
  bool v1137 = (v1103 ^ -2147483648) >= (v1104 ^ -2147483648);
  struct StateT * v1132;
  if (v1137) {
    int v1105 = v1101->timer;
    int v1138 = v1105 + 15;
    v1101->timer = v1138;
    int * v1107 = v1101->saved_regs;
    int v1108 = v1107[10];
    int * v1109 = v1101->regs;
    v1109[10] = v1108;
    int * v1111 = v1101->saved_regs;
    int v1112 = v1111[11];
    int * v1113 = v1101->regs;
    v1113[11] = v1112;
    int * v1115 = v1101->saved_regs;
    int v1116 = v1115[12];
    int * v1117 = v1101->regs;
    v1117[12] = v1116;
    int * v1119 = v1101->reg_ready;
    int v1120 = v1101->timer;
    v1119[10] = v1120;
    int * v1122 = v1101->reg_ready;
    int v1123 = v1101->timer;
    v1122[11] = v1123;
    int * v1125 = v1101->reg_ready;
    int v1126 = v1101->timer;
    v1125[12] = v1126;
    struct StateT * v1128 = slot_21(v1101);
    v1132 = v1128;
  } else {
    struct StateT * v1130 = slot_19(v1101);
    v1132 = v1130;
  }
  return v1132;
}

struct StateT * slot_33(struct StateT * v3064) {
  int v3065 = v3064->timer;
  int v3068 = v3065 + 1;
  v3064->timer = v3068;
  return v3064;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v3069 = v1->timer;
  int * v3070 = v1->reg_ready;
  int v3071 = v3070[0];
  int v3202 = v3071 + ((v3069 - v3071) & (~((v3069 - v3071) >> 31)));
  v1->timer = v3202;
  int v3073 = v1->timer;
  int * v3074 = v1->reg_ready;
  int v3075 = v3074[1];
  int v3205 = v3075 + ((v3073 - v3075) & (~((v3073 - v3075) >> 31)));
  v1->timer = v3205;
  int v3077 = v1->timer;
  int * v3078 = v1->reg_ready;
  int v3079 = v3078[2];
  int v3208 = v3079 + ((v3077 - v3079) & (~((v3077 - v3079) >> 31)));
  v1->timer = v3208;
  int v3081 = v1->timer;
  int * v3082 = v1->reg_ready;
  int v3083 = v3082[3];
  int v3211 = v3083 + ((v3081 - v3083) & (~((v3081 - v3083) >> 31)));
  v1->timer = v3211;
  int v3085 = v1->timer;
  int * v3086 = v1->reg_ready;
  int v3087 = v3086[4];
  int v3214 = v3087 + ((v3085 - v3087) & (~((v3085 - v3087) >> 31)));
  v1->timer = v3214;
  int v3089 = v1->timer;
  int * v3090 = v1->reg_ready;
  int v3091 = v3090[5];
  int v3217 = v3091 + ((v3089 - v3091) & (~((v3089 - v3091) >> 31)));
  v1->timer = v3217;
  int v3093 = v1->timer;
  int * v3094 = v1->reg_ready;
  int v3095 = v3094[6];
  int v3220 = v3095 + ((v3093 - v3095) & (~((v3093 - v3095) >> 31)));
  v1->timer = v3220;
  int v3097 = v1->timer;
  int * v3098 = v1->reg_ready;
  int v3099 = v3098[7];
  int v3223 = v3099 + ((v3097 - v3099) & (~((v3097 - v3099) >> 31)));
  v1->timer = v3223;
  int v3101 = v1->timer;
  int * v3102 = v1->reg_ready;
  int v3103 = v3102[8];
  int v3226 = v3103 + ((v3101 - v3103) & (~((v3101 - v3103) >> 31)));
  v1->timer = v3226;
  int v3105 = v1->timer;
  int * v3106 = v1->reg_ready;
  int v3107 = v3106[9];
  int v3229 = v3107 + ((v3105 - v3107) & (~((v3105 - v3107) >> 31)));
  v1->timer = v3229;
  int v3109 = v1->timer;
  int * v3110 = v1->reg_ready;
  int v3111 = v3110[10];
  int v3232 = v3111 + ((v3109 - v3111) & (~((v3109 - v3111) >> 31)));
  v1->timer = v3232;
  int v3113 = v1->timer;
  int * v3114 = v1->reg_ready;
  int v3115 = v3114[11];
  int v3235 = v3115 + ((v3113 - v3115) & (~((v3113 - v3115) >> 31)));
  v1->timer = v3235;
  int v3117 = v1->timer;
  int * v3118 = v1->reg_ready;
  int v3119 = v3118[12];
  int v3238 = v3119 + ((v3117 - v3119) & (~((v3117 - v3119) >> 31)));
  v1->timer = v3238;
  int v3121 = v1->timer;
  int * v3122 = v1->reg_ready;
  int v3123 = v3122[13];
  int v3241 = v3123 + ((v3121 - v3123) & (~((v3121 - v3123) >> 31)));
  v1->timer = v3241;
  int v3125 = v1->timer;
  int * v3126 = v1->reg_ready;
  int v3127 = v3126[14];
  int v3244 = v3127 + ((v3125 - v3127) & (~((v3125 - v3127) >> 31)));
  v1->timer = v3244;
  int v3129 = v1->timer;
  int * v3130 = v1->reg_ready;
  int v3131 = v3130[15];
  int v3247 = v3131 + ((v3129 - v3131) & (~((v3129 - v3131) >> 31)));
  v1->timer = v3247;
  int v3133 = v1->timer;
  int * v3134 = v1->reg_ready;
  int v3135 = v3134[16];
  int v3250 = v3135 + ((v3133 - v3135) & (~((v3133 - v3135) >> 31)));
  v1->timer = v3250;
  int v3137 = v1->timer;
  int * v3138 = v1->reg_ready;
  int v3139 = v3138[17];
  int v3253 = v3139 + ((v3137 - v3139) & (~((v3137 - v3139) >> 31)));
  v1->timer = v3253;
  int v3141 = v1->timer;
  int * v3142 = v1->reg_ready;
  int v3143 = v3142[18];
  int v3256 = v3143 + ((v3141 - v3143) & (~((v3141 - v3143) >> 31)));
  v1->timer = v3256;
  int v3145 = v1->timer;
  int * v3146 = v1->reg_ready;
  int v3147 = v3146[19];
  int v3259 = v3147 + ((v3145 - v3147) & (~((v3145 - v3147) >> 31)));
  v1->timer = v3259;
  int v3149 = v1->timer;
  int * v3150 = v1->reg_ready;
  int v3151 = v3150[20];
  int v3262 = v3151 + ((v3149 - v3151) & (~((v3149 - v3151) >> 31)));
  v1->timer = v3262;
  int v3153 = v1->timer;
  int * v3154 = v1->reg_ready;
  int v3155 = v3154[21];
  int v3265 = v3155 + ((v3153 - v3155) & (~((v3153 - v3155) >> 31)));
  v1->timer = v3265;
  int v3157 = v1->timer;
  int * v3158 = v1->reg_ready;
  int v3159 = v3158[22];
  int v3268 = v3159 + ((v3157 - v3159) & (~((v3157 - v3159) >> 31)));
  v1->timer = v3268;
  int v3161 = v1->timer;
  int * v3162 = v1->reg_ready;
  int v3163 = v3162[23];
  int v3271 = v3163 + ((v3161 - v3163) & (~((v3161 - v3163) >> 31)));
  v1->timer = v3271;
  int v3165 = v1->timer;
  int * v3166 = v1->reg_ready;
  int v3167 = v3166[24];
  int v3274 = v3167 + ((v3165 - v3167) & (~((v3165 - v3167) >> 31)));
  v1->timer = v3274;
  int v3169 = v1->timer;
  int * v3170 = v1->reg_ready;
  int v3171 = v3170[25];
  int v3277 = v3171 + ((v3169 - v3171) & (~((v3169 - v3171) >> 31)));
  v1->timer = v3277;
  int v3173 = v1->timer;
  int * v3174 = v1->reg_ready;
  int v3175 = v3174[26];
  int v3280 = v3175 + ((v3173 - v3175) & (~((v3173 - v3175) >> 31)));
  v1->timer = v3280;
  int v3177 = v1->timer;
  int * v3178 = v1->reg_ready;
  int v3179 = v3178[27];
  int v3283 = v3179 + ((v3177 - v3179) & (~((v3177 - v3179) >> 31)));
  v1->timer = v3283;
  int v3181 = v1->timer;
  int * v3182 = v1->reg_ready;
  int v3183 = v3182[28];
  int v3286 = v3183 + ((v3181 - v3183) & (~((v3181 - v3183) >> 31)));
  v1->timer = v3286;
  int v3185 = v1->timer;
  int * v3186 = v1->reg_ready;
  int v3187 = v3186[29];
  int v3289 = v3187 + ((v3185 - v3187) & (~((v3185 - v3187) >> 31)));
  v1->timer = v3289;
  int v3189 = v1->timer;
  int * v3190 = v1->reg_ready;
  int v3191 = v3190[30];
  int v3292 = v3191 + ((v3189 - v3191) & (~((v3189 - v3191) >> 31)));
  v1->timer = v3292;
  int v3193 = v1->timer;
  int * v3194 = v1->reg_ready;
  int v3195 = v3194[31];
  int v3295 = v3195 + ((v3193 - v3195) & (~((v3193 - v3195) >> 31)));
  v1->timer = v3295;
  return v1;
}

struct StateT * slot_8(struct StateT * v536) {
  int v537 = v536->timer;
  int v545 = v537 + 1;
  v536->timer = v545;
  int * v539 = v536->reg_ready;
  v539[11] = v545;
  int * v541 = v536->regs;
  v541[11] = 0;
  struct StateT * v543 = slot_9(v536);
  return v543;
}

struct StateT * slot_4(struct StateT * v261) {
  int * v262 = v261->saved_regs;
  int * v263 = v261->regs;
  int v264 = v263[11];
  v262[11] = v264;
  int v266 = v261->timer;
  int v278 = v266 + 1;
  v261->timer = v278;
  int * v268 = v261->reg_ready;
  v268[11] = v278;
  int * v270 = v261->regs;
  v270[11] = 0;
  struct StateT * v272 = slot_5(v261);
  return v272;
}

struct StateT * slot_15(struct StateT * v869) {
  int v870 = v869->timer;
  int v982 = v870 + 1;
  v869->timer = v982;
  int * v872 = v869->reg_ready;
  int v873 = v872[12];
  int * v874 = v869->regs;
  int v875 = v874[12];
  int * v876 = v869->cache_tags;
  int v987 = (((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 1) * 2;
  int v877 = v876[v987];
  int v988 = ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v878 = v876[v988];
  int v989 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2);
  int v879 = v876[v989];
  int v990 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v880 = v876[v990];
  int * v881 = v869->cache_vals;
  bool v991 = !(((~(((v877 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v877 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v878 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v878 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v974;
  if (v991) {
    int * v882 = v869->cache_age;
    int v993 = ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v878 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v878 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v883 = v882[v993];
    int v884 = v882[v987];
    int v994 = v884 + ((int)((unsigned int)(v884 - v883) >> 31));
    v882[v987] = v994;
    int * v886 = v869->cache_age;
    int v887 = v886[v988];
    int v996 = v887 + ((int)((unsigned int)(v887 - v883) >> 31));
    v886[v988] = v996;
    int * v889 = v869->cache_age;
    v889[v993] = 0;
    v974 = v993;
  } else {
    int * v892 = v869->cache_age;
    int v1000 = (((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 1) * 2;
    int v893 = v892[v1000];
    int * v894 = v869->cache_tags;
    int v895 = v894[v1000];
    int v896 = v892[v988];
    int v897 = v894[v988];
    bool v1002 = !(((~(((v879 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v879 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v951;
    if (v1002) {
      int * v898 = v869->cache_age;
      int v1004 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v899 = v898[v1004];
      int v900 = v898[v989];
      int v1005 = v900 + ((int)((unsigned int)(v900 - v899) >> 31));
      v898[v989] = v1005;
      int * v902 = v869->cache_age;
      int v903 = v902[v990];
      int v1007 = v903 + ((int)((unsigned int)(v903 - v899) >> 31));
      v902[v990] = v1007;
      int * v905 = v869->cache_age;
      v905[v1004] = 0;
      v951 = v1004;
    } else {
      int * v908 = v869->cache_age;
      int v1011 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2);
      int v909 = v908[v1011];
      int * v910 = v869->cache_tags;
      int v911 = v910[v1011];
      int v912 = v908[v990];
      int v913 = v910[v990];
      int * v914 = v869->cache_dirty;
      int v1014 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v915 = v914[v1014];
      bool v1015 = !(v915 == 0);
      if (v1015) {
        int * v916 = v869->cache_tags;
        int v917 = v916[v1014];
        int * v918 = v869->cache_vals;
        int v1018 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v919 = v918[v1018];
        int v1019 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v920 = v918[v1019];
        int * v921 = v869->mem;
        int v1021 = v917 * 2;
        v921[v1021] = v919;
        int * v923 = v869->mem;
        int v1024 = (v917 * 2) + 1;
        v923[v1024] = v920;
        ;
      } else {
        ;
      }
      int * v928 = v869->mem;
      int v1029 = ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) * 2;
      int v929 = v928[v1029];
      int v1030 = (((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) * 2) + 1;
      int v930 = v928[v1030];
      int * v931 = v869->cache_vals;
      int v1032 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v931[v1032] = v929;
      int * v933 = v869->cache_vals;
      int v1035 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v909 + ((~(((v911 ^ -1) | (-(v911 ^ -1))) >> 31)) & 2)) - (v912 + ((~(((v913 ^ -1) | (-(v913 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v933[v1035] = v930;
      int * v935 = v869->cache_tags;
      int v1038 = (int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1);
      v935[v1014] = v1038;
      int * v937 = v869->cache_dirty;
      v937[v1014] = 0;
      int * v939 = v869->cache_age;
      v939[v1014] = 1;
      int * v941 = v869->cache_age;
      int v942 = v941[v1014];
      int v943 = v941[v989];
      int v1044 = v943 + ((int)((unsigned int)(v943 - v942) >> 31));
      v941[v989] = v1044;
      int * v945 = v869->cache_age;
      int v946 = v945[v990];
      int v1046 = v946 + ((int)((unsigned int)(v946 - v942) >> 31));
      v945[v990] = v1046;
      int * v948 = v869->cache_age;
      v948[v1014] = 0;
      v951 = v1014;
    }
    int * v952 = v869->cache_vals;
    int v1049 = v951 * 2;
    int v953 = v952[v1049];
    int v1050 = (v951 * 2) + 1;
    int v954 = v952[v1050];
    int v1051 = (((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v893 + ((~(((v895 ^ -1) | (-(v895 ^ -1))) >> 31)) & 2)) - (v896 + ((~(((v897 ^ -1) | (-(v897 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v952[v1051] = v953;
    int * v956 = v869->cache_vals;
    int v1054 = ((((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v893 + ((~(((v895 ^ -1) | (-(v895 ^ -1))) >> 31)) & 2)) - (v896 + ((~(((v897 ^ -1) | (-(v897 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v956[v1054] = v954;
    int * v958 = v869->cache_tags;
    int v1057 = ((((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v893 + ((~(((v895 ^ -1) | (-(v895 ^ -1))) >> 31)) & 2)) - (v896 + ((~(((v897 ^ -1) | (-(v897 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1058 = (int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1);
    v958[v1057] = v1058;
    int * v960 = v869->cache_dirty;
    v960[v1057] = 0;
    int * v962 = v869->cache_age;
    v962[v1057] = 1;
    int * v964 = v869->cache_age;
    int v965 = v964[v1057];
    int v966 = v964[v987];
    int v1064 = v966 + ((int)((unsigned int)(v966 - v965) >> 31));
    v964[v987] = v1064;
    int * v968 = v869->cache_age;
    int v969 = v968[v988];
    int v1066 = v969 + ((int)((unsigned int)(v969 - v965) >> 31));
    v968[v988] = v1066;
    int * v971 = v869->cache_age;
    v971[v1057] = 0;
    v974 = v1057;
  }
  int v1069 = (v974 * 2) + (((int)((unsigned int)(v875 + 68) >> 2)) & 1);
  int v975 = v881[v1069];
  int * v976 = v869->reg_ready;
  int v1072 = ((v873 + ((v870 - v873) & (~((v870 - v873) >> 31)))) + 1) + ((100 ^ (((~(((v879 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v879 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v877 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v877 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v878 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v878 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v879 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v879 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))) | (-(v880 ^ ((int)((unsigned int)((int)((unsigned int)(v875 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v976[11] = v1072;
  int * v978 = v869->regs;
  v978[11] = v975;
  struct StateT * v980 = slot_16(v869);
  return v980;
}

struct StateT * slot_9(struct StateT * v552) {
  int v553 = v552->timer;
  int v564 = v553 + 1;
  v552->timer = v564;
  int * v555 = v552->reg_ready;
  int v556 = v555[11];
  int * v557 = v552->regs;
  int v558 = v557[11];
  int v568 = (v556 + ((v553 - v556) & (~((v553 - v556) >> 31)))) + 1;
  v555[11] = v568;
  int * v560 = v552->regs;
  int v570 = v558 + 4;
  v560[11] = v570;
  struct StateT * v562 = slot_10(v552);
  return v562;
}

struct StateT * slot_11(struct StateT * v596) {
  int v597 = v596->timer;
  int v608 = v597 + 1;
  v596->timer = v608;
  int * v599 = v596->reg_ready;
  int v600 = v599[10];
  int * v601 = v596->regs;
  int v602 = v601[10];
  int v612 = (v600 + ((v597 - v600) & (~((v597 - v600) >> 31)))) + 1;
  v599[10] = v612;
  int * v604 = v596->regs;
  int v614 = v602 << 29;
  v604[10] = v614;
  struct StateT * v606 = slot_12(v596);
  return v606;
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