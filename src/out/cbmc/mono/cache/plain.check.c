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

struct StateT * slot_12(struct StateT * v2006);
struct StateT * slot_43(struct StateT * v4960);
struct StateT * slot_6(struct StateT * v848);
struct StateT * slot_47(struct StateT * v5010);
struct StateT * slot_29(struct StateT * v3282);
struct StateT * slot_55(struct StateT * v6112);
struct StateT * slot_16(struct StateT * v928);
struct StateT * slot_5(struct StateT * v832);
struct StateT * slot_7(struct StateT * v870);
struct StateT * slot_31(struct StateT * v3808);
struct StateT * slot_54(struct StateT * v5797);
struct StateT * slot_26(struct StateT * v3267);
struct StateT * slot_65(struct StateT * v6737);
struct StateT * slot_10(struct StateT * v1132);
struct StateT * slot_19(struct StateT * v1802);
struct StateT * slot_58(struct StateT * v6132);
struct StateT * slot_67(struct StateT * v7263);
struct StateT * slot_64(struct StateT * v6708);
struct StateT * slot_14(struct StateT * v2691);
struct StateT * slot_53(struct StateT * v5586);
struct StateT * slot_44(struct StateT * v4995);
struct StateT * slot_66(struct StateT * v6948);
struct StateT * slot_28(struct StateT * v3252);
struct StateT * slot_32(struct StateT * v3843);
struct StateT * slot_17(struct StateT * v1447);
struct StateT * slot_49(struct StateT * v5536);
struct StateT * slot_33(struct StateT * v4061);
struct StateT * slot_50(struct StateT * v5571);
struct StateT * slot_36(struct StateT * v4069);
struct StateT * slot_37(struct StateT * v4384);
struct StateT * slot_57(struct StateT * v6365);
struct StateT * slot_59(struct StateT * v6162);
struct StateT * slot_40(struct StateT * v4404);
struct StateT * slot_27(struct StateT * v3485);
struct StateT * slot_15(struct StateT * v2909);
struct StateT * slot_62(struct StateT * v6722);
struct StateT * slot_48(struct StateT * v5221);
struct StateT * slot_22(struct StateT * v2676);
struct StateT * slot_35(struct StateT * v3858);
struct StateT * slot_56(struct StateT * v6147);
struct StateT * slot_34(struct StateT * v3828);
struct StateT * slot_51(struct StateT * v5789);
struct StateT * slot_52(struct StateT * v5556);
struct StateT * slot_25(struct StateT * v3232);
struct StateT * slot_23(struct StateT * v2706);
struct StateT * slot_2(struct StateT * v409);
struct StateT * slot_21(struct StateT * v2656);
struct StateT * slot_3(struct StateT * v613);
struct StateT * slot_45(struct StateT * v5213);
struct StateT * slot_1(struct StateT * v205);
struct StateT * slot_13(struct StateT * v2636);
struct StateT * slot_38(struct StateT * v4419);
struct StateT * slot_63(struct StateT * v6940);
struct StateT * slot_24(struct StateT * v2917);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_42(struct StateT * v4645);
struct StateT * slot_46(struct StateT * v4980);
struct StateT * slot_20(struct StateT * v2321);
struct StateT * slot_61(struct StateT * v6688);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_41(struct StateT * v4434);
struct StateT * slot_39(struct StateT * v4637);
struct StateT * slot_8(struct StateT * v892);
struct StateT * slot_30(struct StateT * v3493);
struct StateT * slot_60(struct StateT * v6373);
struct StateT * slot_4(struct StateT * v816);
struct StateT * slot_18(struct StateT * v1782);
struct StateT * slot_9(struct StateT * v908);
struct StateT * slot_11(struct StateT * v1762);
struct StateT * slot_12(struct StateT * v2006) {
  int v2007 = v2006->timer;
  int v2177 = v2007 + 1;
  v2006->timer = v2177;
  int * v2009 = v2006->regs;
  int v2010 = v2009[10];
  int v2011 = v2009[14];
  int * v2012 = v2006->cache_tags;
  int v2182 = (((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1)) & 1) * 2;
  int v2013 = v2012[v2182];
  int v2183 = ((((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2014 = v2012[v2183];
  int v2184 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1)) & 3) * 2);
  int v2015 = v2012[v2184];
  int v2185 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2016 = v2012[v2185];
  int v2017 = v2006->timer;
  int v2186 = v2017 + ((100 ^ (((~(((v2015 ^ ((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1))) | (-(v2015 ^ ((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2016 ^ ((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1))) | (-(v2016 ^ ((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2013 ^ ((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1))) | (-(v2013 ^ ((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2014 ^ ((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1))) | (-(v2014 ^ ((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2015 ^ ((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1))) | (-(v2015 ^ ((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2016 ^ ((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1))) | (-(v2016 ^ ((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2006->timer = v2186;
  bool v2187 = !(((~(((v2013 ^ ((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1))) | (-(v2013 ^ ((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2014 ^ ((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1))) | (-(v2014 ^ ((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v2111;
  if (v2187) {
    int * v2019 = v2006->cache_age;
    int v2189 = ((((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v2014 ^ ((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1))) | (-(v2014 ^ ((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v2020 = v2019[v2189];
    int v2021 = v2019[v2182];
    int v2190 = v2021 + ((int)((unsigned int)(v2021 - v2020) >> 31));
    v2019[v2182] = v2190;
    int * v2023 = v2006->cache_age;
    int v2024 = v2023[v2183];
    int v2192 = v2024 + ((int)((unsigned int)(v2024 - v2020) >> 31));
    v2023[v2183] = v2192;
    int * v2026 = v2006->cache_age;
    v2026[v2189] = 0;
    v2111 = v2189;
  } else {
    int * v2029 = v2006->cache_age;
    int v2196 = (((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1)) & 1) * 2;
    int v2030 = v2029[v2196];
    int * v2031 = v2006->cache_tags;
    int v2032 = v2031[v2196];
    int v2033 = v2029[v2183];
    int v2034 = v2031[v2183];
    bool v2198 = !(((~(((v2015 ^ ((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1))) | (-(v2015 ^ ((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2016 ^ ((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1))) | (-(v2016 ^ ((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v2088;
    if (v2198) {
      int * v2035 = v2006->cache_age;
      int v2200 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2016 ^ ((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1))) | (-(v2016 ^ ((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v2036 = v2035[v2200];
      int v2037 = v2035[v2184];
      int v2201 = v2037 + ((int)((unsigned int)(v2037 - v2036) >> 31));
      v2035[v2184] = v2201;
      int * v2039 = v2006->cache_age;
      int v2040 = v2039[v2185];
      int v2203 = v2040 + ((int)((unsigned int)(v2040 - v2036) >> 31));
      v2039[v2185] = v2203;
      int * v2042 = v2006->cache_age;
      v2042[v2200] = 0;
      v2088 = v2200;
    } else {
      int * v2045 = v2006->cache_age;
      int v2207 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1)) & 3) * 2);
      int v2046 = v2045[v2207];
      int * v2047 = v2006->cache_tags;
      int v2048 = v2047[v2207];
      int v2049 = v2045[v2185];
      int v2050 = v2047[v2185];
      int * v2051 = v2006->cache_dirty;
      int v2210 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2046 + ((~(((v2048 ^ -1) | (-(v2048 ^ -1))) >> 31)) & 2)) - (v2049 + ((~(((v2050 ^ -1) | (-(v2050 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2052 = v2051[v2210];
      bool v2211 = !(v2052 == 0);
      if (v2211) {
        int * v2053 = v2006->cache_tags;
        int v2054 = v2053[v2210];
        int * v2055 = v2006->cache_vals;
        int v2214 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2046 + ((~(((v2048 ^ -1) | (-(v2048 ^ -1))) >> 31)) & 2)) - (v2049 + ((~(((v2050 ^ -1) | (-(v2050 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2056 = v2055[v2214];
        int v2215 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2046 + ((~(((v2048 ^ -1) | (-(v2048 ^ -1))) >> 31)) & 2)) - (v2049 + ((~(((v2050 ^ -1) | (-(v2050 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2057 = v2055[v2215];
        int * v2058 = v2006->mem;
        int v2217 = v2054 * 2;
        v2058[v2217] = v2056;
        int * v2060 = v2006->mem;
        int v2220 = (v2054 * 2) + 1;
        v2060[v2220] = v2057;
        ;
      } else {
        ;
      }
      int * v2065 = v2006->mem;
      int v2225 = ((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1)) * 2;
      int v2066 = v2065[v2225];
      int v2226 = (((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1)) * 2) + 1;
      int v2067 = v2065[v2226];
      int * v2068 = v2006->cache_vals;
      int v2228 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2046 + ((~(((v2048 ^ -1) | (-(v2048 ^ -1))) >> 31)) & 2)) - (v2049 + ((~(((v2050 ^ -1) | (-(v2050 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2068[v2228] = v2066;
      int * v2070 = v2006->cache_vals;
      int v2231 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2046 + ((~(((v2048 ^ -1) | (-(v2048 ^ -1))) >> 31)) & 2)) - (v2049 + ((~(((v2050 ^ -1) | (-(v2050 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2070[v2231] = v2067;
      int * v2072 = v2006->cache_tags;
      int v2234 = (int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1);
      v2072[v2210] = v2234;
      int * v2074 = v2006->cache_dirty;
      v2074[v2210] = 0;
      int * v2076 = v2006->cache_age;
      v2076[v2210] = 1;
      int * v2078 = v2006->cache_age;
      int v2079 = v2078[v2210];
      int v2080 = v2078[v2184];
      int v2240 = v2080 + ((int)((unsigned int)(v2080 - v2079) >> 31));
      v2078[v2184] = v2240;
      int * v2082 = v2006->cache_age;
      int v2083 = v2082[v2185];
      int v2242 = v2083 + ((int)((unsigned int)(v2083 - v2079) >> 31));
      v2082[v2185] = v2242;
      int * v2085 = v2006->cache_age;
      v2085[v2210] = 0;
      v2088 = v2210;
    }
    int * v2089 = v2006->cache_vals;
    int v2245 = v2088 * 2;
    int v2090 = v2089[v2245];
    int v2246 = (v2088 * 2) + 1;
    int v2091 = v2089[v2246];
    int v2247 = (((((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v2030 + ((~(((v2032 ^ -1) | (-(v2032 ^ -1))) >> 31)) & 2)) - (v2033 + ((~(((v2034 ^ -1) | (-(v2034 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2089[v2247] = v2090;
    int * v2093 = v2006->cache_vals;
    int v2250 = ((((((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v2030 + ((~(((v2032 ^ -1) | (-(v2032 ^ -1))) >> 31)) & 2)) - (v2033 + ((~(((v2034 ^ -1) | (-(v2034 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2093[v2250] = v2091;
    int * v2095 = v2006->cache_tags;
    int v2253 = ((((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v2030 + ((~(((v2032 ^ -1) | (-(v2032 ^ -1))) >> 31)) & 2)) - (v2033 + ((~(((v2034 ^ -1) | (-(v2034 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2254 = (int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1);
    v2095[v2253] = v2254;
    int * v2097 = v2006->cache_dirty;
    v2097[v2253] = 0;
    int * v2099 = v2006->cache_age;
    v2099[v2253] = 1;
    int * v2101 = v2006->cache_age;
    int v2102 = v2101[v2253];
    int v2103 = v2101[v2182];
    int v2260 = v2103 + ((int)((unsigned int)(v2103 - v2102) >> 31));
    v2101[v2182] = v2260;
    int * v2105 = v2006->cache_age;
    int v2106 = v2105[v2183];
    int v2262 = v2106 + ((int)((unsigned int)(v2106 - v2102) >> 31));
    v2105[v2183] = v2262;
    int * v2108 = v2006->cache_age;
    v2108[v2253] = 0;
    v2111 = v2253;
  }
  int * v2112 = v2006->cache_vals;
  int v2265 = (v2111 * 2) + (((int)((unsigned int)(v2010 + 4) >> 2)) & 1);
  v2112[v2265] = v2011;
  int * v2114 = v2006->cache_tags;
  int v2115 = v2114[v2184];
  int v2116 = v2114[v2185];
  bool v2268 = !(((~(((v2115 ^ ((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1))) | (-(v2115 ^ ((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2116 ^ ((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1))) | (-(v2116 ^ ((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v2170;
  if (v2268) {
    int * v2117 = v2006->cache_age;
    int v2270 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2116 ^ ((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1))) | (-(v2116 ^ ((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v2118 = v2117[v2270];
    int v2119 = v2117[v2184];
    int v2271 = v2119 + ((int)((unsigned int)(v2119 - v2118) >> 31));
    v2117[v2184] = v2271;
    int * v2121 = v2006->cache_age;
    int v2122 = v2121[v2185];
    int v2273 = v2122 + ((int)((unsigned int)(v2122 - v2118) >> 31));
    v2121[v2185] = v2273;
    int * v2124 = v2006->cache_age;
    v2124[v2270] = 0;
    v2170 = v2270;
  } else {
    int * v2127 = v2006->cache_age;
    int v2277 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1)) & 3) * 2);
    int v2128 = v2127[v2277];
    int * v2129 = v2006->cache_tags;
    int v2130 = v2129[v2277];
    int v2131 = v2127[v2185];
    int v2132 = v2129[v2185];
    int * v2133 = v2006->cache_dirty;
    int v2280 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2128 + ((~(((v2130 ^ -1) | (-(v2130 ^ -1))) >> 31)) & 2)) - (v2131 + ((~(((v2132 ^ -1) | (-(v2132 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2134 = v2133[v2280];
    bool v2281 = !(v2134 == 0);
    if (v2281) {
      int * v2135 = v2006->cache_tags;
      int v2136 = v2135[v2280];
      int * v2137 = v2006->cache_vals;
      int v2284 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2128 + ((~(((v2130 ^ -1) | (-(v2130 ^ -1))) >> 31)) & 2)) - (v2131 + ((~(((v2132 ^ -1) | (-(v2132 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v2138 = v2137[v2284];
      int v2285 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2128 + ((~(((v2130 ^ -1) | (-(v2130 ^ -1))) >> 31)) & 2)) - (v2131 + ((~(((v2132 ^ -1) | (-(v2132 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v2139 = v2137[v2285];
      int * v2140 = v2006->mem;
      int v2287 = v2136 * 2;
      v2140[v2287] = v2138;
      int * v2142 = v2006->mem;
      int v2290 = (v2136 * 2) + 1;
      v2142[v2290] = v2139;
      ;
    } else {
      ;
    }
    int * v2147 = v2006->mem;
    int v2295 = ((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1)) * 2;
    int v2148 = v2147[v2295];
    int v2296 = (((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1)) * 2) + 1;
    int v2149 = v2147[v2296];
    int * v2150 = v2006->cache_vals;
    int v2298 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2128 + ((~(((v2130 ^ -1) | (-(v2130 ^ -1))) >> 31)) & 2)) - (v2131 + ((~(((v2132 ^ -1) | (-(v2132 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2150[v2298] = v2148;
    int * v2152 = v2006->cache_vals;
    int v2301 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2128 + ((~(((v2130 ^ -1) | (-(v2130 ^ -1))) >> 31)) & 2)) - (v2131 + ((~(((v2132 ^ -1) | (-(v2132 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2152[v2301] = v2149;
    int * v2154 = v2006->cache_tags;
    int v2304 = (int)((unsigned int)((int)((unsigned int)(v2010 + 4) >> 2)) >> 1);
    v2154[v2280] = v2304;
    int * v2156 = v2006->cache_dirty;
    v2156[v2280] = 0;
    int * v2158 = v2006->cache_age;
    v2158[v2280] = 1;
    int * v2160 = v2006->cache_age;
    int v2161 = v2160[v2280];
    int v2162 = v2160[v2184];
    int v2310 = v2162 + ((int)((unsigned int)(v2162 - v2161) >> 31));
    v2160[v2184] = v2310;
    int * v2164 = v2006->cache_age;
    int v2165 = v2164[v2185];
    int v2312 = v2165 + ((int)((unsigned int)(v2165 - v2161) >> 31));
    v2164[v2185] = v2312;
    int * v2167 = v2006->cache_age;
    v2167[v2280] = 0;
    v2170 = v2280;
  }
  int * v2171 = v2006->cache_vals;
  int v2315 = (v2170 * 2) + (((int)((unsigned int)(v2010 + 4) >> 2)) & 1);
  v2171[v2315] = v2011;
  int * v2173 = v2006->cache_dirty;
  v2173[v2170] = 1;
  struct StateT * v2175 = slot_13(v2006);
  return v2175;
}

struct StateT * slot_43(struct StateT * v4960) {
  int v4961 = v4960->timer;
  int v4971 = v4961 + 1;
  v4960->timer = v4971;
  int * v4963 = v4960->regs;
  int v4964 = v4963[12];
  bool v4974 = !(v4964 == 0);
  struct StateT * v4969;
  if (v4974) {
    struct StateT * v4965 = slot_46(v4960);
    v4969 = v4965;
  } else {
    struct StateT * v4967 = slot_44(v4960);
    v4969 = v4967;
  }
  return v4969;
}

struct StateT * slot_6(struct StateT * v848) {
  int v849 = v848->timer;
  int v860 = v849 + 1;
  v848->timer = v860;
  int * v851 = v848->regs;
  int v852 = v851[12];
  bool v863 = -2147483648 < (v852 ^ -2147483648);
  int v855;
  if (v863) {
    v855 = 1;
  } else {
    v855 = 0;
  }
  int * v856 = v848->regs;
  v856[12] = v855;
  struct StateT * v858 = slot_7(v848);
  return v858;
}

struct StateT * slot_47(struct StateT * v5010) {
  int v5011 = v5010->timer;
  int v5121 = v5011 + 1;
  v5010->timer = v5121;
  int * v5013 = v5010->regs;
  int v5014 = v5013[13];
  int * v5015 = v5010->cache_tags;
  int v5125 = (((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1)) & 1) * 2;
  int v5016 = v5015[v5125];
  int v5126 = ((((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1)) & 1) * 2) + 1;
  int v5017 = v5015[v5126];
  int v5127 = 4 + ((((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1)) & 3) * 2);
  int v5018 = v5015[v5127];
  int v5128 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5019 = v5015[v5128];
  int v5020 = v5010->timer;
  int v5129 = v5020 + ((100 ^ (((~(((v5018 ^ ((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1))) | (-(v5018 ^ ((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1))))) >> 31)) | (~(((v5019 ^ ((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1))) | (-(v5019 ^ ((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5016 ^ ((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1))) | (-(v5016 ^ ((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1))))) >> 31)) | (~(((v5017 ^ ((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1))) | (-(v5017 ^ ((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5018 ^ ((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1))) | (-(v5018 ^ ((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1))))) >> 31)) | (~(((v5019 ^ ((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1))) | (-(v5019 ^ ((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1))))) >> 31))) & 104)))));
  v5010->timer = v5129;
  int * v5022 = v5010->cache_vals;
  bool v5130 = !(((~(((v5016 ^ ((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1))) | (-(v5016 ^ ((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1))))) >> 31)) | (~(((v5017 ^ ((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1))) | (-(v5017 ^ ((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1))))) >> 31))) == 0);
  int v5115;
  if (v5130) {
    int * v5023 = v5010->cache_age;
    int v5132 = ((((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1)) & 1) * 2) + ((~(((v5017 ^ ((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1))) | (-(v5017 ^ ((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1))))) >> 31)) & 1);
    int v5024 = v5023[v5132];
    int v5025 = v5023[v5125];
    int v5133 = v5025 + ((int)((unsigned int)(v5025 - v5024) >> 31));
    v5023[v5125] = v5133;
    int * v5027 = v5010->cache_age;
    int v5028 = v5027[v5126];
    int v5135 = v5028 + ((int)((unsigned int)(v5028 - v5024) >> 31));
    v5027[v5126] = v5135;
    int * v5030 = v5010->cache_age;
    v5030[v5132] = 0;
    v5115 = v5132;
  } else {
    int * v5033 = v5010->cache_age;
    int v5139 = (((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1)) & 1) * 2;
    int v5034 = v5033[v5139];
    int * v5035 = v5010->cache_tags;
    int v5036 = v5035[v5139];
    int v5037 = v5033[v5126];
    int v5038 = v5035[v5126];
    bool v5141 = !(((~(((v5018 ^ ((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1))) | (-(v5018 ^ ((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1))))) >> 31)) | (~(((v5019 ^ ((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1))) | (-(v5019 ^ ((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1))))) >> 31))) == 0);
    int v5092;
    if (v5141) {
      int * v5039 = v5010->cache_age;
      int v5143 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1)) & 3) * 2)) + ((~(((v5019 ^ ((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1))) | (-(v5019 ^ ((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1))))) >> 31)) & 1);
      int v5040 = v5039[v5143];
      int v5041 = v5039[v5127];
      int v5144 = v5041 + ((int)((unsigned int)(v5041 - v5040) >> 31));
      v5039[v5127] = v5144;
      int * v5043 = v5010->cache_age;
      int v5044 = v5043[v5128];
      int v5146 = v5044 + ((int)((unsigned int)(v5044 - v5040) >> 31));
      v5043[v5128] = v5146;
      int * v5046 = v5010->cache_age;
      v5046[v5143] = 0;
      v5092 = v5143;
    } else {
      int * v5049 = v5010->cache_age;
      int v5150 = 4 + ((((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1)) & 3) * 2);
      int v5050 = v5049[v5150];
      int * v5051 = v5010->cache_tags;
      int v5052 = v5051[v5150];
      int v5053 = v5049[v5128];
      int v5054 = v5051[v5128];
      int * v5055 = v5010->cache_dirty;
      int v5153 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1)) & 3) * 2)) + ((((v5050 + ((~(((v5052 ^ -1) | (-(v5052 ^ -1))) >> 31)) & 2)) - (v5053 + ((~(((v5054 ^ -1) | (-(v5054 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5056 = v5055[v5153];
      bool v5154 = !(v5056 == 0);
      if (v5154) {
        int * v5057 = v5010->cache_tags;
        int v5058 = v5057[v5153];
        int * v5059 = v5010->cache_vals;
        int v5157 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1)) & 3) * 2)) + ((((v5050 + ((~(((v5052 ^ -1) | (-(v5052 ^ -1))) >> 31)) & 2)) - (v5053 + ((~(((v5054 ^ -1) | (-(v5054 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5060 = v5059[v5157];
        int v5158 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1)) & 3) * 2)) + ((((v5050 + ((~(((v5052 ^ -1) | (-(v5052 ^ -1))) >> 31)) & 2)) - (v5053 + ((~(((v5054 ^ -1) | (-(v5054 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5061 = v5059[v5158];
        int * v5062 = v5010->mem;
        int v5160 = v5058 * 2;
        v5062[v5160] = v5060;
        int * v5064 = v5010->mem;
        int v5163 = (v5058 * 2) + 1;
        v5064[v5163] = v5061;
        ;
      } else {
        ;
      }
      int * v5069 = v5010->mem;
      int v5168 = ((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1)) * 2;
      int v5070 = v5069[v5168];
      int v5169 = (((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1)) * 2) + 1;
      int v5071 = v5069[v5169];
      int * v5072 = v5010->cache_vals;
      int v5171 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1)) & 3) * 2)) + ((((v5050 + ((~(((v5052 ^ -1) | (-(v5052 ^ -1))) >> 31)) & 2)) - (v5053 + ((~(((v5054 ^ -1) | (-(v5054 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5072[v5171] = v5070;
      int * v5074 = v5010->cache_vals;
      int v5174 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1)) & 3) * 2)) + ((((v5050 + ((~(((v5052 ^ -1) | (-(v5052 ^ -1))) >> 31)) & 2)) - (v5053 + ((~(((v5054 ^ -1) | (-(v5054 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5074[v5174] = v5071;
      int * v5076 = v5010->cache_tags;
      int v5177 = (int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1);
      v5076[v5153] = v5177;
      int * v5078 = v5010->cache_dirty;
      v5078[v5153] = 0;
      int * v5080 = v5010->cache_age;
      v5080[v5153] = 1;
      int * v5082 = v5010->cache_age;
      int v5083 = v5082[v5153];
      int v5084 = v5082[v5127];
      int v5183 = v5084 + ((int)((unsigned int)(v5084 - v5083) >> 31));
      v5082[v5127] = v5183;
      int * v5086 = v5010->cache_age;
      int v5087 = v5086[v5128];
      int v5185 = v5087 + ((int)((unsigned int)(v5087 - v5083) >> 31));
      v5086[v5128] = v5185;
      int * v5089 = v5010->cache_age;
      v5089[v5153] = 0;
      v5092 = v5153;
    }
    int * v5093 = v5010->cache_vals;
    int v5188 = v5092 * 2;
    int v5094 = v5093[v5188];
    int v5189 = (v5092 * 2) + 1;
    int v5095 = v5093[v5189];
    int v5190 = (((((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1)) & 1) * 2) + ((((v5034 + ((~(((v5036 ^ -1) | (-(v5036 ^ -1))) >> 31)) & 2)) - (v5037 + ((~(((v5038 ^ -1) | (-(v5038 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5093[v5190] = v5094;
    int * v5097 = v5010->cache_vals;
    int v5193 = ((((((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1)) & 1) * 2) + ((((v5034 + ((~(((v5036 ^ -1) | (-(v5036 ^ -1))) >> 31)) & 2)) - (v5037 + ((~(((v5038 ^ -1) | (-(v5038 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5097[v5193] = v5095;
    int * v5099 = v5010->cache_tags;
    int v5196 = ((((int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1)) & 1) * 2) + ((((v5034 + ((~(((v5036 ^ -1) | (-(v5036 ^ -1))) >> 31)) & 2)) - (v5037 + ((~(((v5038 ^ -1) | (-(v5038 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5197 = (int)((unsigned int)((int)((unsigned int)v5014 >> 2)) >> 1);
    v5099[v5196] = v5197;
    int * v5101 = v5010->cache_dirty;
    v5101[v5196] = 0;
    int * v5103 = v5010->cache_age;
    v5103[v5196] = 1;
    int * v5105 = v5010->cache_age;
    int v5106 = v5105[v5196];
    int v5107 = v5105[v5125];
    int v5203 = v5107 + ((int)((unsigned int)(v5107 - v5106) >> 31));
    v5105[v5125] = v5203;
    int * v5109 = v5010->cache_age;
    int v5110 = v5109[v5126];
    int v5205 = v5110 + ((int)((unsigned int)(v5110 - v5106) >> 31));
    v5109[v5126] = v5205;
    int * v5112 = v5010->cache_age;
    v5112[v5196] = 0;
    v5115 = v5196;
  }
  int v5208 = (v5115 * 2) + (((int)((unsigned int)v5014 >> 2)) & 1);
  int v5116 = v5022[v5208];
  int * v5117 = v5010->regs;
  v5117[13] = v5116;
  struct StateT * v5119 = slot_48(v5010);
  return v5119;
}

struct StateT * slot_29(struct StateT * v3282) {
  int v3283 = v3282->timer;
  int v3393 = v3283 + 1;
  v3282->timer = v3393;
  int * v3285 = v3282->regs;
  int v3286 = v3285[13];
  int * v3287 = v3282->cache_tags;
  int v3397 = (((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1)) & 1) * 2;
  int v3288 = v3287[v3397];
  int v3398 = ((((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1)) & 1) * 2) + 1;
  int v3289 = v3287[v3398];
  int v3399 = 4 + ((((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1)) & 3) * 2);
  int v3290 = v3287[v3399];
  int v3400 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3291 = v3287[v3400];
  int v3292 = v3282->timer;
  int v3401 = v3292 + ((100 ^ (((~(((v3290 ^ ((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1))) | (-(v3290 ^ ((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1))))) >> 31)) | (~(((v3291 ^ ((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1))) | (-(v3291 ^ ((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3288 ^ ((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1))) | (-(v3288 ^ ((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1))))) >> 31)) | (~(((v3289 ^ ((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1))) | (-(v3289 ^ ((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3290 ^ ((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1))) | (-(v3290 ^ ((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1))))) >> 31)) | (~(((v3291 ^ ((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1))) | (-(v3291 ^ ((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1))))) >> 31))) & 104)))));
  v3282->timer = v3401;
  int * v3294 = v3282->cache_vals;
  bool v3402 = !(((~(((v3288 ^ ((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1))) | (-(v3288 ^ ((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1))))) >> 31)) | (~(((v3289 ^ ((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1))) | (-(v3289 ^ ((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1))))) >> 31))) == 0);
  int v3387;
  if (v3402) {
    int * v3295 = v3282->cache_age;
    int v3404 = ((((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1)) & 1) * 2) + ((~(((v3289 ^ ((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1))) | (-(v3289 ^ ((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1))))) >> 31)) & 1);
    int v3296 = v3295[v3404];
    int v3297 = v3295[v3397];
    int v3405 = v3297 + ((int)((unsigned int)(v3297 - v3296) >> 31));
    v3295[v3397] = v3405;
    int * v3299 = v3282->cache_age;
    int v3300 = v3299[v3398];
    int v3407 = v3300 + ((int)((unsigned int)(v3300 - v3296) >> 31));
    v3299[v3398] = v3407;
    int * v3302 = v3282->cache_age;
    v3302[v3404] = 0;
    v3387 = v3404;
  } else {
    int * v3305 = v3282->cache_age;
    int v3411 = (((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1)) & 1) * 2;
    int v3306 = v3305[v3411];
    int * v3307 = v3282->cache_tags;
    int v3308 = v3307[v3411];
    int v3309 = v3305[v3398];
    int v3310 = v3307[v3398];
    bool v3413 = !(((~(((v3290 ^ ((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1))) | (-(v3290 ^ ((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1))))) >> 31)) | (~(((v3291 ^ ((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1))) | (-(v3291 ^ ((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1))))) >> 31))) == 0);
    int v3364;
    if (v3413) {
      int * v3311 = v3282->cache_age;
      int v3415 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1)) & 3) * 2)) + ((~(((v3291 ^ ((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1))) | (-(v3291 ^ ((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1))))) >> 31)) & 1);
      int v3312 = v3311[v3415];
      int v3313 = v3311[v3399];
      int v3416 = v3313 + ((int)((unsigned int)(v3313 - v3312) >> 31));
      v3311[v3399] = v3416;
      int * v3315 = v3282->cache_age;
      int v3316 = v3315[v3400];
      int v3418 = v3316 + ((int)((unsigned int)(v3316 - v3312) >> 31));
      v3315[v3400] = v3418;
      int * v3318 = v3282->cache_age;
      v3318[v3415] = 0;
      v3364 = v3415;
    } else {
      int * v3321 = v3282->cache_age;
      int v3422 = 4 + ((((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1)) & 3) * 2);
      int v3322 = v3321[v3422];
      int * v3323 = v3282->cache_tags;
      int v3324 = v3323[v3422];
      int v3325 = v3321[v3400];
      int v3326 = v3323[v3400];
      int * v3327 = v3282->cache_dirty;
      int v3425 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1)) & 3) * 2)) + ((((v3322 + ((~(((v3324 ^ -1) | (-(v3324 ^ -1))) >> 31)) & 2)) - (v3325 + ((~(((v3326 ^ -1) | (-(v3326 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3328 = v3327[v3425];
      bool v3426 = !(v3328 == 0);
      if (v3426) {
        int * v3329 = v3282->cache_tags;
        int v3330 = v3329[v3425];
        int * v3331 = v3282->cache_vals;
        int v3429 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1)) & 3) * 2)) + ((((v3322 + ((~(((v3324 ^ -1) | (-(v3324 ^ -1))) >> 31)) & 2)) - (v3325 + ((~(((v3326 ^ -1) | (-(v3326 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3332 = v3331[v3429];
        int v3430 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1)) & 3) * 2)) + ((((v3322 + ((~(((v3324 ^ -1) | (-(v3324 ^ -1))) >> 31)) & 2)) - (v3325 + ((~(((v3326 ^ -1) | (-(v3326 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3333 = v3331[v3430];
        int * v3334 = v3282->mem;
        int v3432 = v3330 * 2;
        v3334[v3432] = v3332;
        int * v3336 = v3282->mem;
        int v3435 = (v3330 * 2) + 1;
        v3336[v3435] = v3333;
        ;
      } else {
        ;
      }
      int * v3341 = v3282->mem;
      int v3440 = ((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1)) * 2;
      int v3342 = v3341[v3440];
      int v3441 = (((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1)) * 2) + 1;
      int v3343 = v3341[v3441];
      int * v3344 = v3282->cache_vals;
      int v3443 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1)) & 3) * 2)) + ((((v3322 + ((~(((v3324 ^ -1) | (-(v3324 ^ -1))) >> 31)) & 2)) - (v3325 + ((~(((v3326 ^ -1) | (-(v3326 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3344[v3443] = v3342;
      int * v3346 = v3282->cache_vals;
      int v3446 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1)) & 3) * 2)) + ((((v3322 + ((~(((v3324 ^ -1) | (-(v3324 ^ -1))) >> 31)) & 2)) - (v3325 + ((~(((v3326 ^ -1) | (-(v3326 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3346[v3446] = v3343;
      int * v3348 = v3282->cache_tags;
      int v3449 = (int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1);
      v3348[v3425] = v3449;
      int * v3350 = v3282->cache_dirty;
      v3350[v3425] = 0;
      int * v3352 = v3282->cache_age;
      v3352[v3425] = 1;
      int * v3354 = v3282->cache_age;
      int v3355 = v3354[v3425];
      int v3356 = v3354[v3399];
      int v3455 = v3356 + ((int)((unsigned int)(v3356 - v3355) >> 31));
      v3354[v3399] = v3455;
      int * v3358 = v3282->cache_age;
      int v3359 = v3358[v3400];
      int v3457 = v3359 + ((int)((unsigned int)(v3359 - v3355) >> 31));
      v3358[v3400] = v3457;
      int * v3361 = v3282->cache_age;
      v3361[v3425] = 0;
      v3364 = v3425;
    }
    int * v3365 = v3282->cache_vals;
    int v3460 = v3364 * 2;
    int v3366 = v3365[v3460];
    int v3461 = (v3364 * 2) + 1;
    int v3367 = v3365[v3461];
    int v3462 = (((((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1)) & 1) * 2) + ((((v3306 + ((~(((v3308 ^ -1) | (-(v3308 ^ -1))) >> 31)) & 2)) - (v3309 + ((~(((v3310 ^ -1) | (-(v3310 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3365[v3462] = v3366;
    int * v3369 = v3282->cache_vals;
    int v3465 = ((((((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1)) & 1) * 2) + ((((v3306 + ((~(((v3308 ^ -1) | (-(v3308 ^ -1))) >> 31)) & 2)) - (v3309 + ((~(((v3310 ^ -1) | (-(v3310 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3369[v3465] = v3367;
    int * v3371 = v3282->cache_tags;
    int v3468 = ((((int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1)) & 1) * 2) + ((((v3306 + ((~(((v3308 ^ -1) | (-(v3308 ^ -1))) >> 31)) & 2)) - (v3309 + ((~(((v3310 ^ -1) | (-(v3310 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3469 = (int)((unsigned int)((int)((unsigned int)v3286 >> 2)) >> 1);
    v3371[v3468] = v3469;
    int * v3373 = v3282->cache_dirty;
    v3373[v3468] = 0;
    int * v3375 = v3282->cache_age;
    v3375[v3468] = 1;
    int * v3377 = v3282->cache_age;
    int v3378 = v3377[v3468];
    int v3379 = v3377[v3397];
    int v3475 = v3379 + ((int)((unsigned int)(v3379 - v3378) >> 31));
    v3377[v3397] = v3475;
    int * v3381 = v3282->cache_age;
    int v3382 = v3381[v3398];
    int v3477 = v3382 + ((int)((unsigned int)(v3382 - v3378) >> 31));
    v3381[v3398] = v3477;
    int * v3384 = v3282->cache_age;
    v3384[v3468] = 0;
    v3387 = v3468;
  }
  int v3480 = (v3387 * 2) + (((int)((unsigned int)v3286 >> 2)) & 1);
  int v3388 = v3294[v3480];
  int * v3389 = v3282->regs;
  v3389[13] = v3388;
  struct StateT * v3391 = slot_30(v3282);
  return v3391;
}

struct StateT * slot_55(struct StateT * v6112) {
  int v6113 = v6112->timer;
  int v6123 = v6113 + 1;
  v6112->timer = v6123;
  int * v6115 = v6112->regs;
  int v6116 = v6115[12];
  bool v6126 = !(v6116 == 0);
  struct StateT * v6121;
  if (v6126) {
    struct StateT * v6117 = slot_58(v6112);
    v6121 = v6117;
  } else {
    struct StateT * v6119 = slot_56(v6112);
    v6121 = v6119;
  }
  return v6121;
}

struct StateT * slot_16(struct StateT * v928) {
  int v929 = v928->timer;
  int v1039 = v929 + 1;
  v928->timer = v1039;
  int * v931 = v928->regs;
  int v932 = v931[11];
  int * v933 = v928->cache_tags;
  int v1043 = (((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1)) & 1) * 2;
  int v934 = v933[v1043];
  int v1044 = ((((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1)) & 1) * 2) + 1;
  int v935 = v933[v1044];
  int v1045 = 4 + ((((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1)) & 3) * 2);
  int v936 = v933[v1045];
  int v1046 = (4 + ((((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v937 = v933[v1046];
  int v938 = v928->timer;
  int v1047 = v938 + ((100 ^ (((~(((v936 ^ ((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1))) | (-(v936 ^ ((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1))))) >> 31)) | (~(((v937 ^ ((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1))) | (-(v937 ^ ((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v934 ^ ((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1))) | (-(v934 ^ ((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1))))) >> 31)) | (~(((v935 ^ ((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1))) | (-(v935 ^ ((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v936 ^ ((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1))) | (-(v936 ^ ((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1))))) >> 31)) | (~(((v937 ^ ((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1))) | (-(v937 ^ ((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1))))) >> 31))) & 104)))));
  v928->timer = v1047;
  int * v940 = v928->cache_vals;
  bool v1048 = !(((~(((v934 ^ ((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1))) | (-(v934 ^ ((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1))))) >> 31)) | (~(((v935 ^ ((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1))) | (-(v935 ^ ((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1))))) >> 31))) == 0);
  int v1033;
  if (v1048) {
    int * v941 = v928->cache_age;
    int v1050 = ((((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1)) & 1) * 2) + ((~(((v935 ^ ((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1))) | (-(v935 ^ ((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1))))) >> 31)) & 1);
    int v942 = v941[v1050];
    int v943 = v941[v1043];
    int v1051 = v943 + ((int)((unsigned int)(v943 - v942) >> 31));
    v941[v1043] = v1051;
    int * v945 = v928->cache_age;
    int v946 = v945[v1044];
    int v1053 = v946 + ((int)((unsigned int)(v946 - v942) >> 31));
    v945[v1044] = v1053;
    int * v948 = v928->cache_age;
    v948[v1050] = 0;
    v1033 = v1050;
  } else {
    int * v951 = v928->cache_age;
    int v1057 = (((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1)) & 1) * 2;
    int v952 = v951[v1057];
    int * v953 = v928->cache_tags;
    int v954 = v953[v1057];
    int v955 = v951[v1044];
    int v956 = v953[v1044];
    bool v1059 = !(((~(((v936 ^ ((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1))) | (-(v936 ^ ((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1))))) >> 31)) | (~(((v937 ^ ((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1))) | (-(v937 ^ ((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1))))) >> 31))) == 0);
    int v1010;
    if (v1059) {
      int * v957 = v928->cache_age;
      int v1061 = (4 + ((((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1)) & 3) * 2)) + ((~(((v937 ^ ((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1))) | (-(v937 ^ ((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1))))) >> 31)) & 1);
      int v958 = v957[v1061];
      int v959 = v957[v1045];
      int v1062 = v959 + ((int)((unsigned int)(v959 - v958) >> 31));
      v957[v1045] = v1062;
      int * v961 = v928->cache_age;
      int v962 = v961[v1046];
      int v1064 = v962 + ((int)((unsigned int)(v962 - v958) >> 31));
      v961[v1046] = v1064;
      int * v964 = v928->cache_age;
      v964[v1061] = 0;
      v1010 = v1061;
    } else {
      int * v967 = v928->cache_age;
      int v1068 = 4 + ((((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1)) & 3) * 2);
      int v968 = v967[v1068];
      int * v969 = v928->cache_tags;
      int v970 = v969[v1068];
      int v971 = v967[v1046];
      int v972 = v969[v1046];
      int * v973 = v928->cache_dirty;
      int v1071 = (4 + ((((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1)) & 3) * 2)) + ((((v968 + ((~(((v970 ^ -1) | (-(v970 ^ -1))) >> 31)) & 2)) - (v971 + ((~(((v972 ^ -1) | (-(v972 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v974 = v973[v1071];
      bool v1072 = !(v974 == 0);
      if (v1072) {
        int * v975 = v928->cache_tags;
        int v976 = v975[v1071];
        int * v977 = v928->cache_vals;
        int v1075 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1)) & 3) * 2)) + ((((v968 + ((~(((v970 ^ -1) | (-(v970 ^ -1))) >> 31)) & 2)) - (v971 + ((~(((v972 ^ -1) | (-(v972 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v978 = v977[v1075];
        int v1076 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1)) & 3) * 2)) + ((((v968 + ((~(((v970 ^ -1) | (-(v970 ^ -1))) >> 31)) & 2)) - (v971 + ((~(((v972 ^ -1) | (-(v972 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v979 = v977[v1076];
        int * v980 = v928->mem;
        int v1078 = v976 * 2;
        v980[v1078] = v978;
        int * v982 = v928->mem;
        int v1081 = (v976 * 2) + 1;
        v982[v1081] = v979;
        ;
      } else {
        ;
      }
      int * v987 = v928->mem;
      int v1086 = ((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1)) * 2;
      int v988 = v987[v1086];
      int v1087 = (((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1)) * 2) + 1;
      int v989 = v987[v1087];
      int * v990 = v928->cache_vals;
      int v1089 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1)) & 3) * 2)) + ((((v968 + ((~(((v970 ^ -1) | (-(v970 ^ -1))) >> 31)) & 2)) - (v971 + ((~(((v972 ^ -1) | (-(v972 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v990[v1089] = v988;
      int * v992 = v928->cache_vals;
      int v1092 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1)) & 3) * 2)) + ((((v968 + ((~(((v970 ^ -1) | (-(v970 ^ -1))) >> 31)) & 2)) - (v971 + ((~(((v972 ^ -1) | (-(v972 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v992[v1092] = v989;
      int * v994 = v928->cache_tags;
      int v1095 = (int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1);
      v994[v1071] = v1095;
      int * v996 = v928->cache_dirty;
      v996[v1071] = 0;
      int * v998 = v928->cache_age;
      v998[v1071] = 1;
      int * v1000 = v928->cache_age;
      int v1001 = v1000[v1071];
      int v1002 = v1000[v1045];
      int v1101 = v1002 + ((int)((unsigned int)(v1002 - v1001) >> 31));
      v1000[v1045] = v1101;
      int * v1004 = v928->cache_age;
      int v1005 = v1004[v1046];
      int v1103 = v1005 + ((int)((unsigned int)(v1005 - v1001) >> 31));
      v1004[v1046] = v1103;
      int * v1007 = v928->cache_age;
      v1007[v1071] = 0;
      v1010 = v1071;
    }
    int * v1011 = v928->cache_vals;
    int v1106 = v1010 * 2;
    int v1012 = v1011[v1106];
    int v1107 = (v1010 * 2) + 1;
    int v1013 = v1011[v1107];
    int v1108 = (((((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1)) & 1) * 2) + ((((v952 + ((~(((v954 ^ -1) | (-(v954 ^ -1))) >> 31)) & 2)) - (v955 + ((~(((v956 ^ -1) | (-(v956 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1011[v1108] = v1012;
    int * v1015 = v928->cache_vals;
    int v1111 = ((((((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1)) & 1) * 2) + ((((v952 + ((~(((v954 ^ -1) | (-(v954 ^ -1))) >> 31)) & 2)) - (v955 + ((~(((v956 ^ -1) | (-(v956 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1015[v1111] = v1013;
    int * v1017 = v928->cache_tags;
    int v1114 = ((((int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1)) & 1) * 2) + ((((v952 + ((~(((v954 ^ -1) | (-(v954 ^ -1))) >> 31)) & 2)) - (v955 + ((~(((v956 ^ -1) | (-(v956 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1115 = (int)((unsigned int)((int)((unsigned int)v932 >> 2)) >> 1);
    v1017[v1114] = v1115;
    int * v1019 = v928->cache_dirty;
    v1019[v1114] = 0;
    int * v1021 = v928->cache_age;
    v1021[v1114] = 1;
    int * v1023 = v928->cache_age;
    int v1024 = v1023[v1114];
    int v1025 = v1023[v1043];
    int v1121 = v1025 + ((int)((unsigned int)(v1025 - v1024) >> 31));
    v1023[v1043] = v1121;
    int * v1027 = v928->cache_age;
    int v1028 = v1027[v1044];
    int v1123 = v1028 + ((int)((unsigned int)(v1028 - v1024) >> 31));
    v1027[v1044] = v1123;
    int * v1030 = v928->cache_age;
    v1030[v1114] = 0;
    v1033 = v1114;
  }
  int v1126 = (v1033 * 2) + (((int)((unsigned int)v932 >> 2)) & 1);
  int v1034 = v940[v1126];
  int * v1035 = v928->regs;
  v1035[15] = v1034;
  struct StateT * v1037 = slot_17(v928);
  return v1037;
}

struct StateT * slot_5(struct StateT * v832) {
  int v833 = v832->timer;
  int v841 = v833 + 1;
  v832->timer = v841;
  int * v835 = v832->regs;
  int v836 = v835[14];
  int v837 = v835[13];
  int v845 = v836 ^ v837;
  v835[13] = v845;
  struct StateT * v839 = slot_6(v832);
  return v839;
}

struct StateT * slot_7(struct StateT * v870) {
  int v871 = v870->timer;
  int v882 = v871 + 1;
  v870->timer = v882;
  int * v873 = v870->regs;
  int v874 = v873[13];
  bool v885 = -2147483648 < (v874 ^ -2147483648);
  int v877;
  if (v885) {
    v877 = 1;
  } else {
    v877 = 0;
  }
  int * v878 = v870->regs;
  v878[13] = v877;
  struct StateT * v880 = slot_8(v870);
  return v880;
}

struct StateT * slot_31(struct StateT * v3808) {
  int v3809 = v3808->timer;
  int v3819 = v3809 + 1;
  v3808->timer = v3819;
  int * v3811 = v3808->regs;
  int v3812 = v3811[12];
  bool v3822 = !(v3812 == 0);
  struct StateT * v3817;
  if (v3822) {
    struct StateT * v3813 = slot_34(v3808);
    v3817 = v3813;
  } else {
    struct StateT * v3815 = slot_32(v3808);
    v3817 = v3815;
  }
  return v3817;
}

struct StateT * slot_54(struct StateT * v5797) {
  int v5798 = v5797->timer;
  int v5968 = v5798 + 1;
  v5797->timer = v5968;
  int * v5800 = v5797->regs;
  int v5801 = v5800[10];
  int v5802 = v5800[13];
  int * v5803 = v5797->cache_tags;
  int v5973 = (((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1)) & 1) * 2;
  int v5804 = v5803[v5973];
  int v5974 = ((((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1)) & 1) * 2) + 1;
  int v5805 = v5803[v5974];
  int v5975 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1)) & 3) * 2);
  int v5806 = v5803[v5975];
  int v5976 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5807 = v5803[v5976];
  int v5808 = v5797->timer;
  int v5977 = v5808 + ((100 ^ (((~(((v5806 ^ ((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1))) | (-(v5806 ^ ((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v5807 ^ ((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1))) | (-(v5807 ^ ((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5804 ^ ((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1))) | (-(v5804 ^ ((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v5805 ^ ((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1))) | (-(v5805 ^ ((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5806 ^ ((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1))) | (-(v5806 ^ ((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v5807 ^ ((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1))) | (-(v5807 ^ ((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1))))) >> 31))) & 104)))));
  v5797->timer = v5977;
  bool v5978 = !(((~(((v5804 ^ ((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1))) | (-(v5804 ^ ((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v5805 ^ ((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1))) | (-(v5805 ^ ((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v5902;
  if (v5978) {
    int * v5810 = v5797->cache_age;
    int v5980 = ((((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1)) & 1) * 2) + ((~(((v5805 ^ ((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1))) | (-(v5805 ^ ((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v5811 = v5810[v5980];
    int v5812 = v5810[v5973];
    int v5981 = v5812 + ((int)((unsigned int)(v5812 - v5811) >> 31));
    v5810[v5973] = v5981;
    int * v5814 = v5797->cache_age;
    int v5815 = v5814[v5974];
    int v5983 = v5815 + ((int)((unsigned int)(v5815 - v5811) >> 31));
    v5814[v5974] = v5983;
    int * v5817 = v5797->cache_age;
    v5817[v5980] = 0;
    v5902 = v5980;
  } else {
    int * v5820 = v5797->cache_age;
    int v5987 = (((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1)) & 1) * 2;
    int v5821 = v5820[v5987];
    int * v5822 = v5797->cache_tags;
    int v5823 = v5822[v5987];
    int v5824 = v5820[v5974];
    int v5825 = v5822[v5974];
    bool v5989 = !(((~(((v5806 ^ ((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1))) | (-(v5806 ^ ((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v5807 ^ ((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1))) | (-(v5807 ^ ((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1))))) >> 31))) == 0);
    int v5879;
    if (v5989) {
      int * v5826 = v5797->cache_age;
      int v5991 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5807 ^ ((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1))) | (-(v5807 ^ ((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1))))) >> 31)) & 1);
      int v5827 = v5826[v5991];
      int v5828 = v5826[v5975];
      int v5992 = v5828 + ((int)((unsigned int)(v5828 - v5827) >> 31));
      v5826[v5975] = v5992;
      int * v5830 = v5797->cache_age;
      int v5831 = v5830[v5976];
      int v5994 = v5831 + ((int)((unsigned int)(v5831 - v5827) >> 31));
      v5830[v5976] = v5994;
      int * v5833 = v5797->cache_age;
      v5833[v5991] = 0;
      v5879 = v5991;
    } else {
      int * v5836 = v5797->cache_age;
      int v5998 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1)) & 3) * 2);
      int v5837 = v5836[v5998];
      int * v5838 = v5797->cache_tags;
      int v5839 = v5838[v5998];
      int v5840 = v5836[v5976];
      int v5841 = v5838[v5976];
      int * v5842 = v5797->cache_dirty;
      int v6001 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v5837 + ((~(((v5839 ^ -1) | (-(v5839 ^ -1))) >> 31)) & 2)) - (v5840 + ((~(((v5841 ^ -1) | (-(v5841 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5843 = v5842[v6001];
      bool v6002 = !(v5843 == 0);
      if (v6002) {
        int * v5844 = v5797->cache_tags;
        int v5845 = v5844[v6001];
        int * v5846 = v5797->cache_vals;
        int v6005 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v5837 + ((~(((v5839 ^ -1) | (-(v5839 ^ -1))) >> 31)) & 2)) - (v5840 + ((~(((v5841 ^ -1) | (-(v5841 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5847 = v5846[v6005];
        int v6006 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v5837 + ((~(((v5839 ^ -1) | (-(v5839 ^ -1))) >> 31)) & 2)) - (v5840 + ((~(((v5841 ^ -1) | (-(v5841 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5848 = v5846[v6006];
        int * v5849 = v5797->mem;
        int v6008 = v5845 * 2;
        v5849[v6008] = v5847;
        int * v5851 = v5797->mem;
        int v6011 = (v5845 * 2) + 1;
        v5851[v6011] = v5848;
        ;
      } else {
        ;
      }
      int * v5856 = v5797->mem;
      int v6016 = ((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1)) * 2;
      int v5857 = v5856[v6016];
      int v6017 = (((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1)) * 2) + 1;
      int v5858 = v5856[v6017];
      int * v5859 = v5797->cache_vals;
      int v6019 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v5837 + ((~(((v5839 ^ -1) | (-(v5839 ^ -1))) >> 31)) & 2)) - (v5840 + ((~(((v5841 ^ -1) | (-(v5841 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5859[v6019] = v5857;
      int * v5861 = v5797->cache_vals;
      int v6022 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v5837 + ((~(((v5839 ^ -1) | (-(v5839 ^ -1))) >> 31)) & 2)) - (v5840 + ((~(((v5841 ^ -1) | (-(v5841 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5861[v6022] = v5858;
      int * v5863 = v5797->cache_tags;
      int v6025 = (int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1);
      v5863[v6001] = v6025;
      int * v5865 = v5797->cache_dirty;
      v5865[v6001] = 0;
      int * v5867 = v5797->cache_age;
      v5867[v6001] = 1;
      int * v5869 = v5797->cache_age;
      int v5870 = v5869[v6001];
      int v5871 = v5869[v5975];
      int v6031 = v5871 + ((int)((unsigned int)(v5871 - v5870) >> 31));
      v5869[v5975] = v6031;
      int * v5873 = v5797->cache_age;
      int v5874 = v5873[v5976];
      int v6033 = v5874 + ((int)((unsigned int)(v5874 - v5870) >> 31));
      v5873[v5976] = v6033;
      int * v5876 = v5797->cache_age;
      v5876[v6001] = 0;
      v5879 = v6001;
    }
    int * v5880 = v5797->cache_vals;
    int v6036 = v5879 * 2;
    int v5881 = v5880[v6036];
    int v6037 = (v5879 * 2) + 1;
    int v5882 = v5880[v6037];
    int v6038 = (((((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v5821 + ((~(((v5823 ^ -1) | (-(v5823 ^ -1))) >> 31)) & 2)) - (v5824 + ((~(((v5825 ^ -1) | (-(v5825 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5880[v6038] = v5881;
    int * v5884 = v5797->cache_vals;
    int v6041 = ((((((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v5821 + ((~(((v5823 ^ -1) | (-(v5823 ^ -1))) >> 31)) & 2)) - (v5824 + ((~(((v5825 ^ -1) | (-(v5825 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5884[v6041] = v5882;
    int * v5886 = v5797->cache_tags;
    int v6044 = ((((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v5821 + ((~(((v5823 ^ -1) | (-(v5823 ^ -1))) >> 31)) & 2)) - (v5824 + ((~(((v5825 ^ -1) | (-(v5825 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6045 = (int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1);
    v5886[v6044] = v6045;
    int * v5888 = v5797->cache_dirty;
    v5888[v6044] = 0;
    int * v5890 = v5797->cache_age;
    v5890[v6044] = 1;
    int * v5892 = v5797->cache_age;
    int v5893 = v5892[v6044];
    int v5894 = v5892[v5973];
    int v6051 = v5894 + ((int)((unsigned int)(v5894 - v5893) >> 31));
    v5892[v5973] = v6051;
    int * v5896 = v5797->cache_age;
    int v5897 = v5896[v5974];
    int v6053 = v5897 + ((int)((unsigned int)(v5897 - v5893) >> 31));
    v5896[v5974] = v6053;
    int * v5899 = v5797->cache_age;
    v5899[v6044] = 0;
    v5902 = v6044;
  }
  int * v5903 = v5797->cache_vals;
  int v6056 = (v5902 * 2) + (((int)((unsigned int)(v5801 + 28) >> 2)) & 1);
  v5903[v6056] = v5802;
  int * v5905 = v5797->cache_tags;
  int v5906 = v5905[v5975];
  int v5907 = v5905[v5976];
  bool v6059 = !(((~(((v5906 ^ ((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1))) | (-(v5906 ^ ((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v5907 ^ ((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1))) | (-(v5907 ^ ((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v5961;
  if (v6059) {
    int * v5908 = v5797->cache_age;
    int v6061 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5907 ^ ((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1))) | (-(v5907 ^ ((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v5909 = v5908[v6061];
    int v5910 = v5908[v5975];
    int v6062 = v5910 + ((int)((unsigned int)(v5910 - v5909) >> 31));
    v5908[v5975] = v6062;
    int * v5912 = v5797->cache_age;
    int v5913 = v5912[v5976];
    int v6064 = v5913 + ((int)((unsigned int)(v5913 - v5909) >> 31));
    v5912[v5976] = v6064;
    int * v5915 = v5797->cache_age;
    v5915[v6061] = 0;
    v5961 = v6061;
  } else {
    int * v5918 = v5797->cache_age;
    int v6068 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1)) & 3) * 2);
    int v5919 = v5918[v6068];
    int * v5920 = v5797->cache_tags;
    int v5921 = v5920[v6068];
    int v5922 = v5918[v5976];
    int v5923 = v5920[v5976];
    int * v5924 = v5797->cache_dirty;
    int v6071 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v5919 + ((~(((v5921 ^ -1) | (-(v5921 ^ -1))) >> 31)) & 2)) - (v5922 + ((~(((v5923 ^ -1) | (-(v5923 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5925 = v5924[v6071];
    bool v6072 = !(v5925 == 0);
    if (v6072) {
      int * v5926 = v5797->cache_tags;
      int v5927 = v5926[v6071];
      int * v5928 = v5797->cache_vals;
      int v6075 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v5919 + ((~(((v5921 ^ -1) | (-(v5921 ^ -1))) >> 31)) & 2)) - (v5922 + ((~(((v5923 ^ -1) | (-(v5923 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v5929 = v5928[v6075];
      int v6076 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v5919 + ((~(((v5921 ^ -1) | (-(v5921 ^ -1))) >> 31)) & 2)) - (v5922 + ((~(((v5923 ^ -1) | (-(v5923 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v5930 = v5928[v6076];
      int * v5931 = v5797->mem;
      int v6078 = v5927 * 2;
      v5931[v6078] = v5929;
      int * v5933 = v5797->mem;
      int v6081 = (v5927 * 2) + 1;
      v5933[v6081] = v5930;
      ;
    } else {
      ;
    }
    int * v5938 = v5797->mem;
    int v6086 = ((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1)) * 2;
    int v5939 = v5938[v6086];
    int v6087 = (((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1)) * 2) + 1;
    int v5940 = v5938[v6087];
    int * v5941 = v5797->cache_vals;
    int v6089 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v5919 + ((~(((v5921 ^ -1) | (-(v5921 ^ -1))) >> 31)) & 2)) - (v5922 + ((~(((v5923 ^ -1) | (-(v5923 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5941[v6089] = v5939;
    int * v5943 = v5797->cache_vals;
    int v6092 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v5919 + ((~(((v5921 ^ -1) | (-(v5921 ^ -1))) >> 31)) & 2)) - (v5922 + ((~(((v5923 ^ -1) | (-(v5923 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5943[v6092] = v5940;
    int * v5945 = v5797->cache_tags;
    int v6095 = (int)((unsigned int)((int)((unsigned int)(v5801 + 28) >> 2)) >> 1);
    v5945[v6071] = v6095;
    int * v5947 = v5797->cache_dirty;
    v5947[v6071] = 0;
    int * v5949 = v5797->cache_age;
    v5949[v6071] = 1;
    int * v5951 = v5797->cache_age;
    int v5952 = v5951[v6071];
    int v5953 = v5951[v5975];
    int v6101 = v5953 + ((int)((unsigned int)(v5953 - v5952) >> 31));
    v5951[v5975] = v6101;
    int * v5955 = v5797->cache_age;
    int v5956 = v5955[v5976];
    int v6103 = v5956 + ((int)((unsigned int)(v5956 - v5952) >> 31));
    v5955[v5976] = v6103;
    int * v5958 = v5797->cache_age;
    v5958[v6071] = 0;
    v5961 = v6071;
  }
  int * v5962 = v5797->cache_vals;
  int v6106 = (v5961 * 2) + (((int)((unsigned int)(v5801 + 28) >> 2)) & 1);
  v5962[v6106] = v5802;
  int * v5964 = v5797->cache_dirty;
  v5964[v5961] = 1;
  struct StateT * v5966 = slot_55(v5797);
  return v5966;
}

struct StateT * slot_26(struct StateT * v3267) {
  int v3268 = v3267->timer;
  int v3275 = v3268 + 1;
  v3267->timer = v3275;
  int * v3270 = v3267->regs;
  int v3271 = v3270[10];
  int v3279 = v3271 + 12;
  v3270[13] = v3279;
  struct StateT * v3273 = slot_27(v3267);
  return v3273;
}

struct StateT * slot_65(struct StateT * v6737) {
  int v6738 = v6737->timer;
  int v6848 = v6738 + 1;
  v6737->timer = v6848;
  int * v6740 = v6737->regs;
  int v6741 = v6740[11];
  int * v6742 = v6737->cache_tags;
  int v6852 = (((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1)) & 1) * 2;
  int v6743 = v6742[v6852];
  int v6853 = ((((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1)) & 1) * 2) + 1;
  int v6744 = v6742[v6853];
  int v6854 = 4 + ((((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1)) & 3) * 2);
  int v6745 = v6742[v6854];
  int v6855 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v6746 = v6742[v6855];
  int v6747 = v6737->timer;
  int v6856 = v6747 + ((100 ^ (((~(((v6745 ^ ((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1))) | (-(v6745 ^ ((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1))))) >> 31)) | (~(((v6746 ^ ((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1))) | (-(v6746 ^ ((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v6743 ^ ((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1))) | (-(v6743 ^ ((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1))))) >> 31)) | (~(((v6744 ^ ((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1))) | (-(v6744 ^ ((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v6745 ^ ((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1))) | (-(v6745 ^ ((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1))))) >> 31)) | (~(((v6746 ^ ((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1))) | (-(v6746 ^ ((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1))))) >> 31))) & 104)))));
  v6737->timer = v6856;
  int * v6749 = v6737->cache_vals;
  bool v6857 = !(((~(((v6743 ^ ((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1))) | (-(v6743 ^ ((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1))))) >> 31)) | (~(((v6744 ^ ((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1))) | (-(v6744 ^ ((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1))))) >> 31))) == 0);
  int v6842;
  if (v6857) {
    int * v6750 = v6737->cache_age;
    int v6859 = ((((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1)) & 1) * 2) + ((~(((v6744 ^ ((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1))) | (-(v6744 ^ ((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1))))) >> 31)) & 1);
    int v6751 = v6750[v6859];
    int v6752 = v6750[v6852];
    int v6860 = v6752 + ((int)((unsigned int)(v6752 - v6751) >> 31));
    v6750[v6852] = v6860;
    int * v6754 = v6737->cache_age;
    int v6755 = v6754[v6853];
    int v6862 = v6755 + ((int)((unsigned int)(v6755 - v6751) >> 31));
    v6754[v6853] = v6862;
    int * v6757 = v6737->cache_age;
    v6757[v6859] = 0;
    v6842 = v6859;
  } else {
    int * v6760 = v6737->cache_age;
    int v6866 = (((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1)) & 1) * 2;
    int v6761 = v6760[v6866];
    int * v6762 = v6737->cache_tags;
    int v6763 = v6762[v6866];
    int v6764 = v6760[v6853];
    int v6765 = v6762[v6853];
    bool v6868 = !(((~(((v6745 ^ ((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1))) | (-(v6745 ^ ((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1))))) >> 31)) | (~(((v6746 ^ ((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1))) | (-(v6746 ^ ((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1))))) >> 31))) == 0);
    int v6819;
    if (v6868) {
      int * v6766 = v6737->cache_age;
      int v6870 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1)) & 3) * 2)) + ((~(((v6746 ^ ((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1))) | (-(v6746 ^ ((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1))))) >> 31)) & 1);
      int v6767 = v6766[v6870];
      int v6768 = v6766[v6854];
      int v6871 = v6768 + ((int)((unsigned int)(v6768 - v6767) >> 31));
      v6766[v6854] = v6871;
      int * v6770 = v6737->cache_age;
      int v6771 = v6770[v6855];
      int v6873 = v6771 + ((int)((unsigned int)(v6771 - v6767) >> 31));
      v6770[v6855] = v6873;
      int * v6773 = v6737->cache_age;
      v6773[v6870] = 0;
      v6819 = v6870;
    } else {
      int * v6776 = v6737->cache_age;
      int v6877 = 4 + ((((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1)) & 3) * 2);
      int v6777 = v6776[v6877];
      int * v6778 = v6737->cache_tags;
      int v6779 = v6778[v6877];
      int v6780 = v6776[v6855];
      int v6781 = v6778[v6855];
      int * v6782 = v6737->cache_dirty;
      int v6880 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1)) & 3) * 2)) + ((((v6777 + ((~(((v6779 ^ -1) | (-(v6779 ^ -1))) >> 31)) & 2)) - (v6780 + ((~(((v6781 ^ -1) | (-(v6781 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v6783 = v6782[v6880];
      bool v6881 = !(v6783 == 0);
      if (v6881) {
        int * v6784 = v6737->cache_tags;
        int v6785 = v6784[v6880];
        int * v6786 = v6737->cache_vals;
        int v6884 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1)) & 3) * 2)) + ((((v6777 + ((~(((v6779 ^ -1) | (-(v6779 ^ -1))) >> 31)) & 2)) - (v6780 + ((~(((v6781 ^ -1) | (-(v6781 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v6787 = v6786[v6884];
        int v6885 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1)) & 3) * 2)) + ((((v6777 + ((~(((v6779 ^ -1) | (-(v6779 ^ -1))) >> 31)) & 2)) - (v6780 + ((~(((v6781 ^ -1) | (-(v6781 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v6788 = v6786[v6885];
        int * v6789 = v6737->mem;
        int v6887 = v6785 * 2;
        v6789[v6887] = v6787;
        int * v6791 = v6737->mem;
        int v6890 = (v6785 * 2) + 1;
        v6791[v6890] = v6788;
        ;
      } else {
        ;
      }
      int * v6796 = v6737->mem;
      int v6895 = ((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1)) * 2;
      int v6797 = v6796[v6895];
      int v6896 = (((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1)) * 2) + 1;
      int v6798 = v6796[v6896];
      int * v6799 = v6737->cache_vals;
      int v6898 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1)) & 3) * 2)) + ((((v6777 + ((~(((v6779 ^ -1) | (-(v6779 ^ -1))) >> 31)) & 2)) - (v6780 + ((~(((v6781 ^ -1) | (-(v6781 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v6799[v6898] = v6797;
      int * v6801 = v6737->cache_vals;
      int v6901 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1)) & 3) * 2)) + ((((v6777 + ((~(((v6779 ^ -1) | (-(v6779 ^ -1))) >> 31)) & 2)) - (v6780 + ((~(((v6781 ^ -1) | (-(v6781 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v6801[v6901] = v6798;
      int * v6803 = v6737->cache_tags;
      int v6904 = (int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1);
      v6803[v6880] = v6904;
      int * v6805 = v6737->cache_dirty;
      v6805[v6880] = 0;
      int * v6807 = v6737->cache_age;
      v6807[v6880] = 1;
      int * v6809 = v6737->cache_age;
      int v6810 = v6809[v6880];
      int v6811 = v6809[v6854];
      int v6910 = v6811 + ((int)((unsigned int)(v6811 - v6810) >> 31));
      v6809[v6854] = v6910;
      int * v6813 = v6737->cache_age;
      int v6814 = v6813[v6855];
      int v6912 = v6814 + ((int)((unsigned int)(v6814 - v6810) >> 31));
      v6813[v6855] = v6912;
      int * v6816 = v6737->cache_age;
      v6816[v6880] = 0;
      v6819 = v6880;
    }
    int * v6820 = v6737->cache_vals;
    int v6915 = v6819 * 2;
    int v6821 = v6820[v6915];
    int v6916 = (v6819 * 2) + 1;
    int v6822 = v6820[v6916];
    int v6917 = (((((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1)) & 1) * 2) + ((((v6761 + ((~(((v6763 ^ -1) | (-(v6763 ^ -1))) >> 31)) & 2)) - (v6764 + ((~(((v6765 ^ -1) | (-(v6765 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6820[v6917] = v6821;
    int * v6824 = v6737->cache_vals;
    int v6920 = ((((((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1)) & 1) * 2) + ((((v6761 + ((~(((v6763 ^ -1) | (-(v6763 ^ -1))) >> 31)) & 2)) - (v6764 + ((~(((v6765 ^ -1) | (-(v6765 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6824[v6920] = v6822;
    int * v6826 = v6737->cache_tags;
    int v6923 = ((((int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1)) & 1) * 2) + ((((v6761 + ((~(((v6763 ^ -1) | (-(v6763 ^ -1))) >> 31)) & 2)) - (v6764 + ((~(((v6765 ^ -1) | (-(v6765 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6924 = (int)((unsigned int)((int)((unsigned int)v6741 >> 2)) >> 1);
    v6826[v6923] = v6924;
    int * v6828 = v6737->cache_dirty;
    v6828[v6923] = 0;
    int * v6830 = v6737->cache_age;
    v6830[v6923] = 1;
    int * v6832 = v6737->cache_age;
    int v6833 = v6832[v6923];
    int v6834 = v6832[v6852];
    int v6930 = v6834 + ((int)((unsigned int)(v6834 - v6833) >> 31));
    v6832[v6852] = v6930;
    int * v6836 = v6737->cache_age;
    int v6837 = v6836[v6853];
    int v6932 = v6837 + ((int)((unsigned int)(v6837 - v6833) >> 31));
    v6836[v6853] = v6932;
    int * v6839 = v6737->cache_age;
    v6839[v6923] = 0;
    v6842 = v6923;
  }
  int v6935 = (v6842 * 2) + (((int)((unsigned int)v6741 >> 2)) & 1);
  int v6843 = v6749[v6935];
  int * v6844 = v6737->regs;
  v6844[11] = v6843;
  struct StateT * v6846 = slot_66(v6737);
  return v6846;
}

struct StateT * slot_10(struct StateT * v1132) {
  int v1133 = v1132->timer;
  int v1303 = v1133 + 1;
  v1132->timer = v1303;
  int * v1135 = v1132->regs;
  int v1136 = v1135[10];
  int v1137 = v1135[15];
  int * v1138 = v1132->cache_tags;
  int v1308 = (((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1)) & 1) * 2;
  int v1139 = v1138[v1308];
  int v1309 = ((((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1140 = v1138[v1309];
  int v1310 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1)) & 3) * 2);
  int v1141 = v1138[v1310];
  int v1311 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1142 = v1138[v1311];
  int v1143 = v1132->timer;
  int v1312 = v1143 + ((100 ^ (((~(((v1141 ^ ((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1))) | (-(v1141 ^ ((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1))))) >> 31)) | (~(((v1142 ^ ((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1))) | (-(v1142 ^ ((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1139 ^ ((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1))) | (-(v1139 ^ ((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1))))) >> 31)) | (~(((v1140 ^ ((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1))) | (-(v1140 ^ ((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1141 ^ ((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1))) | (-(v1141 ^ ((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1))))) >> 31)) | (~(((v1142 ^ ((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1))) | (-(v1142 ^ ((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1132->timer = v1312;
  bool v1313 = !(((~(((v1139 ^ ((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1))) | (-(v1139 ^ ((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1))))) >> 31)) | (~(((v1140 ^ ((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1))) | (-(v1140 ^ ((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1))))) >> 31))) == 0);
  int v1237;
  if (v1313) {
    int * v1145 = v1132->cache_age;
    int v1315 = ((((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1)) & 1) * 2) + ((~(((v1140 ^ ((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1))) | (-(v1140 ^ ((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1))))) >> 31)) & 1);
    int v1146 = v1145[v1315];
    int v1147 = v1145[v1308];
    int v1316 = v1147 + ((int)((unsigned int)(v1147 - v1146) >> 31));
    v1145[v1308] = v1316;
    int * v1149 = v1132->cache_age;
    int v1150 = v1149[v1309];
    int v1318 = v1150 + ((int)((unsigned int)(v1150 - v1146) >> 31));
    v1149[v1309] = v1318;
    int * v1152 = v1132->cache_age;
    v1152[v1315] = 0;
    v1237 = v1315;
  } else {
    int * v1155 = v1132->cache_age;
    int v1322 = (((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1)) & 1) * 2;
    int v1156 = v1155[v1322];
    int * v1157 = v1132->cache_tags;
    int v1158 = v1157[v1322];
    int v1159 = v1155[v1309];
    int v1160 = v1157[v1309];
    bool v1324 = !(((~(((v1141 ^ ((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1))) | (-(v1141 ^ ((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1))))) >> 31)) | (~(((v1142 ^ ((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1))) | (-(v1142 ^ ((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1))))) >> 31))) == 0);
    int v1214;
    if (v1324) {
      int * v1161 = v1132->cache_age;
      int v1326 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1142 ^ ((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1))) | (-(v1142 ^ ((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1))))) >> 31)) & 1);
      int v1162 = v1161[v1326];
      int v1163 = v1161[v1310];
      int v1327 = v1163 + ((int)((unsigned int)(v1163 - v1162) >> 31));
      v1161[v1310] = v1327;
      int * v1165 = v1132->cache_age;
      int v1166 = v1165[v1311];
      int v1329 = v1166 + ((int)((unsigned int)(v1166 - v1162) >> 31));
      v1165[v1311] = v1329;
      int * v1168 = v1132->cache_age;
      v1168[v1326] = 0;
      v1214 = v1326;
    } else {
      int * v1171 = v1132->cache_age;
      int v1333 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1)) & 3) * 2);
      int v1172 = v1171[v1333];
      int * v1173 = v1132->cache_tags;
      int v1174 = v1173[v1333];
      int v1175 = v1171[v1311];
      int v1176 = v1173[v1311];
      int * v1177 = v1132->cache_dirty;
      int v1336 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1)) & 3) * 2)) + ((((v1172 + ((~(((v1174 ^ -1) | (-(v1174 ^ -1))) >> 31)) & 2)) - (v1175 + ((~(((v1176 ^ -1) | (-(v1176 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1178 = v1177[v1336];
      bool v1337 = !(v1178 == 0);
      if (v1337) {
        int * v1179 = v1132->cache_tags;
        int v1180 = v1179[v1336];
        int * v1181 = v1132->cache_vals;
        int v1340 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1)) & 3) * 2)) + ((((v1172 + ((~(((v1174 ^ -1) | (-(v1174 ^ -1))) >> 31)) & 2)) - (v1175 + ((~(((v1176 ^ -1) | (-(v1176 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1182 = v1181[v1340];
        int v1341 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1)) & 3) * 2)) + ((((v1172 + ((~(((v1174 ^ -1) | (-(v1174 ^ -1))) >> 31)) & 2)) - (v1175 + ((~(((v1176 ^ -1) | (-(v1176 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1183 = v1181[v1341];
        int * v1184 = v1132->mem;
        int v1343 = v1180 * 2;
        v1184[v1343] = v1182;
        int * v1186 = v1132->mem;
        int v1346 = (v1180 * 2) + 1;
        v1186[v1346] = v1183;
        ;
      } else {
        ;
      }
      int * v1191 = v1132->mem;
      int v1351 = ((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1)) * 2;
      int v1192 = v1191[v1351];
      int v1352 = (((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1)) * 2) + 1;
      int v1193 = v1191[v1352];
      int * v1194 = v1132->cache_vals;
      int v1354 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1)) & 3) * 2)) + ((((v1172 + ((~(((v1174 ^ -1) | (-(v1174 ^ -1))) >> 31)) & 2)) - (v1175 + ((~(((v1176 ^ -1) | (-(v1176 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1194[v1354] = v1192;
      int * v1196 = v1132->cache_vals;
      int v1357 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1)) & 3) * 2)) + ((((v1172 + ((~(((v1174 ^ -1) | (-(v1174 ^ -1))) >> 31)) & 2)) - (v1175 + ((~(((v1176 ^ -1) | (-(v1176 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1196[v1357] = v1193;
      int * v1198 = v1132->cache_tags;
      int v1360 = (int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1);
      v1198[v1336] = v1360;
      int * v1200 = v1132->cache_dirty;
      v1200[v1336] = 0;
      int * v1202 = v1132->cache_age;
      v1202[v1336] = 1;
      int * v1204 = v1132->cache_age;
      int v1205 = v1204[v1336];
      int v1206 = v1204[v1310];
      int v1366 = v1206 + ((int)((unsigned int)(v1206 - v1205) >> 31));
      v1204[v1310] = v1366;
      int * v1208 = v1132->cache_age;
      int v1209 = v1208[v1311];
      int v1368 = v1209 + ((int)((unsigned int)(v1209 - v1205) >> 31));
      v1208[v1311] = v1368;
      int * v1211 = v1132->cache_age;
      v1211[v1336] = 0;
      v1214 = v1336;
    }
    int * v1215 = v1132->cache_vals;
    int v1371 = v1214 * 2;
    int v1216 = v1215[v1371];
    int v1372 = (v1214 * 2) + 1;
    int v1217 = v1215[v1372];
    int v1373 = (((((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1)) & 1) * 2) + ((((v1156 + ((~(((v1158 ^ -1) | (-(v1158 ^ -1))) >> 31)) & 2)) - (v1159 + ((~(((v1160 ^ -1) | (-(v1160 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1215[v1373] = v1216;
    int * v1219 = v1132->cache_vals;
    int v1376 = ((((((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1)) & 1) * 2) + ((((v1156 + ((~(((v1158 ^ -1) | (-(v1158 ^ -1))) >> 31)) & 2)) - (v1159 + ((~(((v1160 ^ -1) | (-(v1160 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1219[v1376] = v1217;
    int * v1221 = v1132->cache_tags;
    int v1379 = ((((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1)) & 1) * 2) + ((((v1156 + ((~(((v1158 ^ -1) | (-(v1158 ^ -1))) >> 31)) & 2)) - (v1159 + ((~(((v1160 ^ -1) | (-(v1160 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1380 = (int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1);
    v1221[v1379] = v1380;
    int * v1223 = v1132->cache_dirty;
    v1223[v1379] = 0;
    int * v1225 = v1132->cache_age;
    v1225[v1379] = 1;
    int * v1227 = v1132->cache_age;
    int v1228 = v1227[v1379];
    int v1229 = v1227[v1308];
    int v1386 = v1229 + ((int)((unsigned int)(v1229 - v1228) >> 31));
    v1227[v1308] = v1386;
    int * v1231 = v1132->cache_age;
    int v1232 = v1231[v1309];
    int v1388 = v1232 + ((int)((unsigned int)(v1232 - v1228) >> 31));
    v1231[v1309] = v1388;
    int * v1234 = v1132->cache_age;
    v1234[v1379] = 0;
    v1237 = v1379;
  }
  int * v1238 = v1132->cache_vals;
  int v1391 = (v1237 * 2) + (((int)((unsigned int)v1136 >> 2)) & 1);
  v1238[v1391] = v1137;
  int * v1240 = v1132->cache_tags;
  int v1241 = v1240[v1310];
  int v1242 = v1240[v1311];
  bool v1394 = !(((~(((v1241 ^ ((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1))) | (-(v1241 ^ ((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1))))) >> 31)) | (~(((v1242 ^ ((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1))) | (-(v1242 ^ ((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1))))) >> 31))) == 0);
  int v1296;
  if (v1394) {
    int * v1243 = v1132->cache_age;
    int v1396 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1242 ^ ((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1))) | (-(v1242 ^ ((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1))))) >> 31)) & 1);
    int v1244 = v1243[v1396];
    int v1245 = v1243[v1310];
    int v1397 = v1245 + ((int)((unsigned int)(v1245 - v1244) >> 31));
    v1243[v1310] = v1397;
    int * v1247 = v1132->cache_age;
    int v1248 = v1247[v1311];
    int v1399 = v1248 + ((int)((unsigned int)(v1248 - v1244) >> 31));
    v1247[v1311] = v1399;
    int * v1250 = v1132->cache_age;
    v1250[v1396] = 0;
    v1296 = v1396;
  } else {
    int * v1253 = v1132->cache_age;
    int v1403 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1)) & 3) * 2);
    int v1254 = v1253[v1403];
    int * v1255 = v1132->cache_tags;
    int v1256 = v1255[v1403];
    int v1257 = v1253[v1311];
    int v1258 = v1255[v1311];
    int * v1259 = v1132->cache_dirty;
    int v1406 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1)) & 3) * 2)) + ((((v1254 + ((~(((v1256 ^ -1) | (-(v1256 ^ -1))) >> 31)) & 2)) - (v1257 + ((~(((v1258 ^ -1) | (-(v1258 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1260 = v1259[v1406];
    bool v1407 = !(v1260 == 0);
    if (v1407) {
      int * v1261 = v1132->cache_tags;
      int v1262 = v1261[v1406];
      int * v1263 = v1132->cache_vals;
      int v1410 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1)) & 3) * 2)) + ((((v1254 + ((~(((v1256 ^ -1) | (-(v1256 ^ -1))) >> 31)) & 2)) - (v1257 + ((~(((v1258 ^ -1) | (-(v1258 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1264 = v1263[v1410];
      int v1411 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1)) & 3) * 2)) + ((((v1254 + ((~(((v1256 ^ -1) | (-(v1256 ^ -1))) >> 31)) & 2)) - (v1257 + ((~(((v1258 ^ -1) | (-(v1258 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1265 = v1263[v1411];
      int * v1266 = v1132->mem;
      int v1413 = v1262 * 2;
      v1266[v1413] = v1264;
      int * v1268 = v1132->mem;
      int v1416 = (v1262 * 2) + 1;
      v1268[v1416] = v1265;
      ;
    } else {
      ;
    }
    int * v1273 = v1132->mem;
    int v1421 = ((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1)) * 2;
    int v1274 = v1273[v1421];
    int v1422 = (((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1)) * 2) + 1;
    int v1275 = v1273[v1422];
    int * v1276 = v1132->cache_vals;
    int v1424 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1)) & 3) * 2)) + ((((v1254 + ((~(((v1256 ^ -1) | (-(v1256 ^ -1))) >> 31)) & 2)) - (v1257 + ((~(((v1258 ^ -1) | (-(v1258 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1276[v1424] = v1274;
    int * v1278 = v1132->cache_vals;
    int v1427 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1)) & 3) * 2)) + ((((v1254 + ((~(((v1256 ^ -1) | (-(v1256 ^ -1))) >> 31)) & 2)) - (v1257 + ((~(((v1258 ^ -1) | (-(v1258 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1278[v1427] = v1275;
    int * v1280 = v1132->cache_tags;
    int v1430 = (int)((unsigned int)((int)((unsigned int)v1136 >> 2)) >> 1);
    v1280[v1406] = v1430;
    int * v1282 = v1132->cache_dirty;
    v1282[v1406] = 0;
    int * v1284 = v1132->cache_age;
    v1284[v1406] = 1;
    int * v1286 = v1132->cache_age;
    int v1287 = v1286[v1406];
    int v1288 = v1286[v1310];
    int v1436 = v1288 + ((int)((unsigned int)(v1288 - v1287) >> 31));
    v1286[v1310] = v1436;
    int * v1290 = v1132->cache_age;
    int v1291 = v1290[v1311];
    int v1438 = v1291 + ((int)((unsigned int)(v1291 - v1287) >> 31));
    v1290[v1311] = v1438;
    int * v1293 = v1132->cache_age;
    v1293[v1406] = 0;
    v1296 = v1406;
  }
  int * v1297 = v1132->cache_vals;
  int v1441 = (v1296 * 2) + (((int)((unsigned int)v1136 >> 2)) & 1);
  v1297[v1441] = v1137;
  int * v1299 = v1132->cache_dirty;
  v1299[v1296] = 1;
  struct StateT * v1301 = slot_11(v1132);
  return v1301;
}

struct StateT * slot_19(struct StateT * v1802) {
  int v1803 = v1802->timer;
  int v1913 = v1803 + 1;
  v1802->timer = v1913;
  int * v1805 = v1802->regs;
  int v1806 = v1805[11];
  int * v1807 = v1802->cache_tags;
  int v1917 = (((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1)) & 1) * 2;
  int v1808 = v1807[v1917];
  int v1918 = ((((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1809 = v1807[v1918];
  int v1919 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1)) & 3) * 2);
  int v1810 = v1807[v1919];
  int v1920 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1811 = v1807[v1920];
  int v1812 = v1802->timer;
  int v1921 = v1812 + ((100 ^ (((~(((v1810 ^ ((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1))) | (-(v1810 ^ ((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1811 ^ ((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1))) | (-(v1811 ^ ((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1808 ^ ((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1))) | (-(v1808 ^ ((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1809 ^ ((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1))) | (-(v1809 ^ ((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1810 ^ ((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1))) | (-(v1810 ^ ((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1811 ^ ((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1))) | (-(v1811 ^ ((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1802->timer = v1921;
  int * v1814 = v1802->cache_vals;
  bool v1922 = !(((~(((v1808 ^ ((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1))) | (-(v1808 ^ ((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1809 ^ ((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1))) | (-(v1809 ^ ((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v1907;
  if (v1922) {
    int * v1815 = v1802->cache_age;
    int v1924 = ((((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v1809 ^ ((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1))) | (-(v1809 ^ ((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v1816 = v1815[v1924];
    int v1817 = v1815[v1917];
    int v1925 = v1817 + ((int)((unsigned int)(v1817 - v1816) >> 31));
    v1815[v1917] = v1925;
    int * v1819 = v1802->cache_age;
    int v1820 = v1819[v1918];
    int v1927 = v1820 + ((int)((unsigned int)(v1820 - v1816) >> 31));
    v1819[v1918] = v1927;
    int * v1822 = v1802->cache_age;
    v1822[v1924] = 0;
    v1907 = v1924;
  } else {
    int * v1825 = v1802->cache_age;
    int v1931 = (((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1)) & 1) * 2;
    int v1826 = v1825[v1931];
    int * v1827 = v1802->cache_tags;
    int v1828 = v1827[v1931];
    int v1829 = v1825[v1918];
    int v1830 = v1827[v1918];
    bool v1933 = !(((~(((v1810 ^ ((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1))) | (-(v1810 ^ ((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v1811 ^ ((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1))) | (-(v1811 ^ ((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v1884;
    if (v1933) {
      int * v1831 = v1802->cache_age;
      int v1935 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1811 ^ ((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1))) | (-(v1811 ^ ((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v1832 = v1831[v1935];
      int v1833 = v1831[v1919];
      int v1936 = v1833 + ((int)((unsigned int)(v1833 - v1832) >> 31));
      v1831[v1919] = v1936;
      int * v1835 = v1802->cache_age;
      int v1836 = v1835[v1920];
      int v1938 = v1836 + ((int)((unsigned int)(v1836 - v1832) >> 31));
      v1835[v1920] = v1938;
      int * v1838 = v1802->cache_age;
      v1838[v1935] = 0;
      v1884 = v1935;
    } else {
      int * v1841 = v1802->cache_age;
      int v1942 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1)) & 3) * 2);
      int v1842 = v1841[v1942];
      int * v1843 = v1802->cache_tags;
      int v1844 = v1843[v1942];
      int v1845 = v1841[v1920];
      int v1846 = v1843[v1920];
      int * v1847 = v1802->cache_dirty;
      int v1945 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1842 + ((~(((v1844 ^ -1) | (-(v1844 ^ -1))) >> 31)) & 2)) - (v1845 + ((~(((v1846 ^ -1) | (-(v1846 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1848 = v1847[v1945];
      bool v1946 = !(v1848 == 0);
      if (v1946) {
        int * v1849 = v1802->cache_tags;
        int v1850 = v1849[v1945];
        int * v1851 = v1802->cache_vals;
        int v1949 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1842 + ((~(((v1844 ^ -1) | (-(v1844 ^ -1))) >> 31)) & 2)) - (v1845 + ((~(((v1846 ^ -1) | (-(v1846 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1852 = v1851[v1949];
        int v1950 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1842 + ((~(((v1844 ^ -1) | (-(v1844 ^ -1))) >> 31)) & 2)) - (v1845 + ((~(((v1846 ^ -1) | (-(v1846 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1853 = v1851[v1950];
        int * v1854 = v1802->mem;
        int v1952 = v1850 * 2;
        v1854[v1952] = v1852;
        int * v1856 = v1802->mem;
        int v1955 = (v1850 * 2) + 1;
        v1856[v1955] = v1853;
        ;
      } else {
        ;
      }
      int * v1861 = v1802->mem;
      int v1960 = ((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1)) * 2;
      int v1862 = v1861[v1960];
      int v1961 = (((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1)) * 2) + 1;
      int v1863 = v1861[v1961];
      int * v1864 = v1802->cache_vals;
      int v1963 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1842 + ((~(((v1844 ^ -1) | (-(v1844 ^ -1))) >> 31)) & 2)) - (v1845 + ((~(((v1846 ^ -1) | (-(v1846 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1864[v1963] = v1862;
      int * v1866 = v1802->cache_vals;
      int v1966 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v1842 + ((~(((v1844 ^ -1) | (-(v1844 ^ -1))) >> 31)) & 2)) - (v1845 + ((~(((v1846 ^ -1) | (-(v1846 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1866[v1966] = v1863;
      int * v1868 = v1802->cache_tags;
      int v1969 = (int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1);
      v1868[v1945] = v1969;
      int * v1870 = v1802->cache_dirty;
      v1870[v1945] = 0;
      int * v1872 = v1802->cache_age;
      v1872[v1945] = 1;
      int * v1874 = v1802->cache_age;
      int v1875 = v1874[v1945];
      int v1876 = v1874[v1919];
      int v1975 = v1876 + ((int)((unsigned int)(v1876 - v1875) >> 31));
      v1874[v1919] = v1975;
      int * v1878 = v1802->cache_age;
      int v1879 = v1878[v1920];
      int v1977 = v1879 + ((int)((unsigned int)(v1879 - v1875) >> 31));
      v1878[v1920] = v1977;
      int * v1881 = v1802->cache_age;
      v1881[v1945] = 0;
      v1884 = v1945;
    }
    int * v1885 = v1802->cache_vals;
    int v1980 = v1884 * 2;
    int v1886 = v1885[v1980];
    int v1981 = (v1884 * 2) + 1;
    int v1887 = v1885[v1981];
    int v1982 = (((((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1826 + ((~(((v1828 ^ -1) | (-(v1828 ^ -1))) >> 31)) & 2)) - (v1829 + ((~(((v1830 ^ -1) | (-(v1830 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1885[v1982] = v1886;
    int * v1889 = v1802->cache_vals;
    int v1985 = ((((((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1826 + ((~(((v1828 ^ -1) | (-(v1828 ^ -1))) >> 31)) & 2)) - (v1829 + ((~(((v1830 ^ -1) | (-(v1830 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1889[v1985] = v1887;
    int * v1891 = v1802->cache_tags;
    int v1988 = ((((int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v1826 + ((~(((v1828 ^ -1) | (-(v1828 ^ -1))) >> 31)) & 2)) - (v1829 + ((~(((v1830 ^ -1) | (-(v1830 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1989 = (int)((unsigned int)((int)((unsigned int)(v1806 + 4) >> 2)) >> 1);
    v1891[v1988] = v1989;
    int * v1893 = v1802->cache_dirty;
    v1893[v1988] = 0;
    int * v1895 = v1802->cache_age;
    v1895[v1988] = 1;
    int * v1897 = v1802->cache_age;
    int v1898 = v1897[v1988];
    int v1899 = v1897[v1917];
    int v1995 = v1899 + ((int)((unsigned int)(v1899 - v1898) >> 31));
    v1897[v1917] = v1995;
    int * v1901 = v1802->cache_age;
    int v1902 = v1901[v1918];
    int v1997 = v1902 + ((int)((unsigned int)(v1902 - v1898) >> 31));
    v1901[v1918] = v1997;
    int * v1904 = v1802->cache_age;
    v1904[v1988] = 0;
    v1907 = v1988;
  }
  int v2000 = (v1907 * 2) + (((int)((unsigned int)(v1806 + 4) >> 2)) & 1);
  int v1908 = v1814[v2000];
  int * v1909 = v1802->regs;
  v1909[14] = v1908;
  struct StateT * v1911 = slot_20(v1802);
  return v1911;
}

struct StateT * slot_58(struct StateT * v6132) {
  int v6133 = v6132->timer;
  int v6140 = v6133 + 1;
  v6132->timer = v6140;
  int * v6135 = v6132->regs;
  int v6136 = v6135[11];
  int v6144 = v6136 + 32;
  v6135[13] = v6144;
  struct StateT * v6138 = slot_59(v6132);
  return v6138;
}

struct StateT * slot_67(struct StateT * v7263) {
  int v7264 = v7263->timer;
  int v7267 = v7264 + 1;
  v7263->timer = v7267;
  return v7263;
}

struct StateT * slot_64(struct StateT * v6708) {
  int v6709 = v6708->timer;
  int v6716 = v6709 + 1;
  v6708->timer = v6716;
  int * v6711 = v6708->regs;
  int v6712 = v6711[11];
  int v6719 = v6712 + 36;
  v6711[11] = v6719;
  struct StateT * v6714 = slot_65(v6708);
  return v6714;
}

struct StateT * slot_14(struct StateT * v2691) {
  int v2692 = v2691->timer;
  int v2699 = v2692 + 1;
  v2691->timer = v2699;
  int * v2694 = v2691->regs;
  int v2695 = v2694[10];
  int v2703 = v2695 + 8;
  v2694[13] = v2703;
  struct StateT * v2697 = slot_15(v2691);
  return v2697;
}

struct StateT * slot_53(struct StateT * v5586) {
  int v5587 = v5586->timer;
  int v5697 = v5587 + 1;
  v5586->timer = v5697;
  int * v5589 = v5586->regs;
  int v5590 = v5589[13];
  int * v5591 = v5586->cache_tags;
  int v5701 = (((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1)) & 1) * 2;
  int v5592 = v5591[v5701];
  int v5702 = ((((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1)) & 1) * 2) + 1;
  int v5593 = v5591[v5702];
  int v5703 = 4 + ((((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1)) & 3) * 2);
  int v5594 = v5591[v5703];
  int v5704 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5595 = v5591[v5704];
  int v5596 = v5586->timer;
  int v5705 = v5596 + ((100 ^ (((~(((v5594 ^ ((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1))) | (-(v5594 ^ ((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1))))) >> 31)) | (~(((v5595 ^ ((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1))) | (-(v5595 ^ ((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5592 ^ ((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1))) | (-(v5592 ^ ((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1))))) >> 31)) | (~(((v5593 ^ ((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1))) | (-(v5593 ^ ((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5594 ^ ((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1))) | (-(v5594 ^ ((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1))))) >> 31)) | (~(((v5595 ^ ((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1))) | (-(v5595 ^ ((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1))))) >> 31))) & 104)))));
  v5586->timer = v5705;
  int * v5598 = v5586->cache_vals;
  bool v5706 = !(((~(((v5592 ^ ((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1))) | (-(v5592 ^ ((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1))))) >> 31)) | (~(((v5593 ^ ((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1))) | (-(v5593 ^ ((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1))))) >> 31))) == 0);
  int v5691;
  if (v5706) {
    int * v5599 = v5586->cache_age;
    int v5708 = ((((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1)) & 1) * 2) + ((~(((v5593 ^ ((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1))) | (-(v5593 ^ ((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1))))) >> 31)) & 1);
    int v5600 = v5599[v5708];
    int v5601 = v5599[v5701];
    int v5709 = v5601 + ((int)((unsigned int)(v5601 - v5600) >> 31));
    v5599[v5701] = v5709;
    int * v5603 = v5586->cache_age;
    int v5604 = v5603[v5702];
    int v5711 = v5604 + ((int)((unsigned int)(v5604 - v5600) >> 31));
    v5603[v5702] = v5711;
    int * v5606 = v5586->cache_age;
    v5606[v5708] = 0;
    v5691 = v5708;
  } else {
    int * v5609 = v5586->cache_age;
    int v5715 = (((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1)) & 1) * 2;
    int v5610 = v5609[v5715];
    int * v5611 = v5586->cache_tags;
    int v5612 = v5611[v5715];
    int v5613 = v5609[v5702];
    int v5614 = v5611[v5702];
    bool v5717 = !(((~(((v5594 ^ ((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1))) | (-(v5594 ^ ((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1))))) >> 31)) | (~(((v5595 ^ ((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1))) | (-(v5595 ^ ((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1))))) >> 31))) == 0);
    int v5668;
    if (v5717) {
      int * v5615 = v5586->cache_age;
      int v5719 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1)) & 3) * 2)) + ((~(((v5595 ^ ((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1))) | (-(v5595 ^ ((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1))))) >> 31)) & 1);
      int v5616 = v5615[v5719];
      int v5617 = v5615[v5703];
      int v5720 = v5617 + ((int)((unsigned int)(v5617 - v5616) >> 31));
      v5615[v5703] = v5720;
      int * v5619 = v5586->cache_age;
      int v5620 = v5619[v5704];
      int v5722 = v5620 + ((int)((unsigned int)(v5620 - v5616) >> 31));
      v5619[v5704] = v5722;
      int * v5622 = v5586->cache_age;
      v5622[v5719] = 0;
      v5668 = v5719;
    } else {
      int * v5625 = v5586->cache_age;
      int v5726 = 4 + ((((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1)) & 3) * 2);
      int v5626 = v5625[v5726];
      int * v5627 = v5586->cache_tags;
      int v5628 = v5627[v5726];
      int v5629 = v5625[v5704];
      int v5630 = v5627[v5704];
      int * v5631 = v5586->cache_dirty;
      int v5729 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1)) & 3) * 2)) + ((((v5626 + ((~(((v5628 ^ -1) | (-(v5628 ^ -1))) >> 31)) & 2)) - (v5629 + ((~(((v5630 ^ -1) | (-(v5630 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5632 = v5631[v5729];
      bool v5730 = !(v5632 == 0);
      if (v5730) {
        int * v5633 = v5586->cache_tags;
        int v5634 = v5633[v5729];
        int * v5635 = v5586->cache_vals;
        int v5733 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1)) & 3) * 2)) + ((((v5626 + ((~(((v5628 ^ -1) | (-(v5628 ^ -1))) >> 31)) & 2)) - (v5629 + ((~(((v5630 ^ -1) | (-(v5630 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5636 = v5635[v5733];
        int v5734 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1)) & 3) * 2)) + ((((v5626 + ((~(((v5628 ^ -1) | (-(v5628 ^ -1))) >> 31)) & 2)) - (v5629 + ((~(((v5630 ^ -1) | (-(v5630 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5637 = v5635[v5734];
        int * v5638 = v5586->mem;
        int v5736 = v5634 * 2;
        v5638[v5736] = v5636;
        int * v5640 = v5586->mem;
        int v5739 = (v5634 * 2) + 1;
        v5640[v5739] = v5637;
        ;
      } else {
        ;
      }
      int * v5645 = v5586->mem;
      int v5744 = ((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1)) * 2;
      int v5646 = v5645[v5744];
      int v5745 = (((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1)) * 2) + 1;
      int v5647 = v5645[v5745];
      int * v5648 = v5586->cache_vals;
      int v5747 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1)) & 3) * 2)) + ((((v5626 + ((~(((v5628 ^ -1) | (-(v5628 ^ -1))) >> 31)) & 2)) - (v5629 + ((~(((v5630 ^ -1) | (-(v5630 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5648[v5747] = v5646;
      int * v5650 = v5586->cache_vals;
      int v5750 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1)) & 3) * 2)) + ((((v5626 + ((~(((v5628 ^ -1) | (-(v5628 ^ -1))) >> 31)) & 2)) - (v5629 + ((~(((v5630 ^ -1) | (-(v5630 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5650[v5750] = v5647;
      int * v5652 = v5586->cache_tags;
      int v5753 = (int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1);
      v5652[v5729] = v5753;
      int * v5654 = v5586->cache_dirty;
      v5654[v5729] = 0;
      int * v5656 = v5586->cache_age;
      v5656[v5729] = 1;
      int * v5658 = v5586->cache_age;
      int v5659 = v5658[v5729];
      int v5660 = v5658[v5703];
      int v5759 = v5660 + ((int)((unsigned int)(v5660 - v5659) >> 31));
      v5658[v5703] = v5759;
      int * v5662 = v5586->cache_age;
      int v5663 = v5662[v5704];
      int v5761 = v5663 + ((int)((unsigned int)(v5663 - v5659) >> 31));
      v5662[v5704] = v5761;
      int * v5665 = v5586->cache_age;
      v5665[v5729] = 0;
      v5668 = v5729;
    }
    int * v5669 = v5586->cache_vals;
    int v5764 = v5668 * 2;
    int v5670 = v5669[v5764];
    int v5765 = (v5668 * 2) + 1;
    int v5671 = v5669[v5765];
    int v5766 = (((((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1)) & 1) * 2) + ((((v5610 + ((~(((v5612 ^ -1) | (-(v5612 ^ -1))) >> 31)) & 2)) - (v5613 + ((~(((v5614 ^ -1) | (-(v5614 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5669[v5766] = v5670;
    int * v5673 = v5586->cache_vals;
    int v5769 = ((((((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1)) & 1) * 2) + ((((v5610 + ((~(((v5612 ^ -1) | (-(v5612 ^ -1))) >> 31)) & 2)) - (v5613 + ((~(((v5614 ^ -1) | (-(v5614 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5673[v5769] = v5671;
    int * v5675 = v5586->cache_tags;
    int v5772 = ((((int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1)) & 1) * 2) + ((((v5610 + ((~(((v5612 ^ -1) | (-(v5612 ^ -1))) >> 31)) & 2)) - (v5613 + ((~(((v5614 ^ -1) | (-(v5614 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5773 = (int)((unsigned int)((int)((unsigned int)v5590 >> 2)) >> 1);
    v5675[v5772] = v5773;
    int * v5677 = v5586->cache_dirty;
    v5677[v5772] = 0;
    int * v5679 = v5586->cache_age;
    v5679[v5772] = 1;
    int * v5681 = v5586->cache_age;
    int v5682 = v5681[v5772];
    int v5683 = v5681[v5701];
    int v5779 = v5683 + ((int)((unsigned int)(v5683 - v5682) >> 31));
    v5681[v5701] = v5779;
    int * v5685 = v5586->cache_age;
    int v5686 = v5685[v5702];
    int v5781 = v5686 + ((int)((unsigned int)(v5686 - v5682) >> 31));
    v5685[v5702] = v5781;
    int * v5688 = v5586->cache_age;
    v5688[v5772] = 0;
    v5691 = v5772;
  }
  int v5784 = (v5691 * 2) + (((int)((unsigned int)v5590 >> 2)) & 1);
  int v5692 = v5598[v5784];
  int * v5693 = v5586->regs;
  v5693[13] = v5692;
  struct StateT * v5695 = slot_54(v5586);
  return v5695;
}

struct StateT * slot_44(struct StateT * v4995) {
  int v4996 = v4995->timer;
  int v5003 = v4996 + 1;
  v4995->timer = v5003;
  int * v4998 = v4995->regs;
  int v4999 = v4998[10];
  int v5007 = v4999 + 24;
  v4998[13] = v5007;
  struct StateT * v5001 = slot_45(v4995);
  return v5001;
}

struct StateT * slot_66(struct StateT * v6948) {
  int v6949 = v6948->timer;
  int v7119 = v6949 + 1;
  v6948->timer = v7119;
  int * v6951 = v6948->regs;
  int v6952 = v6951[10];
  int v6953 = v6951[11];
  int * v6954 = v6948->cache_tags;
  int v7124 = (((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1)) & 1) * 2;
  int v6955 = v6954[v7124];
  int v7125 = ((((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1)) & 1) * 2) + 1;
  int v6956 = v6954[v7125];
  int v7126 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1)) & 3) * 2);
  int v6957 = v6954[v7126];
  int v7127 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v6958 = v6954[v7127];
  int v6959 = v6948->timer;
  int v7128 = v6959 + ((100 ^ (((~(((v6957 ^ ((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1))) | (-(v6957 ^ ((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v6958 ^ ((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1))) | (-(v6958 ^ ((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v6955 ^ ((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1))) | (-(v6955 ^ ((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v6956 ^ ((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1))) | (-(v6956 ^ ((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v6957 ^ ((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1))) | (-(v6957 ^ ((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v6958 ^ ((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1))) | (-(v6958 ^ ((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1))))) >> 31))) & 104)))));
  v6948->timer = v7128;
  bool v7129 = !(((~(((v6955 ^ ((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1))) | (-(v6955 ^ ((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v6956 ^ ((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1))) | (-(v6956 ^ ((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v7053;
  if (v7129) {
    int * v6961 = v6948->cache_age;
    int v7131 = ((((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1)) & 1) * 2) + ((~(((v6956 ^ ((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1))) | (-(v6956 ^ ((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1))))) >> 31)) & 1);
    int v6962 = v6961[v7131];
    int v6963 = v6961[v7124];
    int v7132 = v6963 + ((int)((unsigned int)(v6963 - v6962) >> 31));
    v6961[v7124] = v7132;
    int * v6965 = v6948->cache_age;
    int v6966 = v6965[v7125];
    int v7134 = v6966 + ((int)((unsigned int)(v6966 - v6962) >> 31));
    v6965[v7125] = v7134;
    int * v6968 = v6948->cache_age;
    v6968[v7131] = 0;
    v7053 = v7131;
  } else {
    int * v6971 = v6948->cache_age;
    int v7138 = (((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1)) & 1) * 2;
    int v6972 = v6971[v7138];
    int * v6973 = v6948->cache_tags;
    int v6974 = v6973[v7138];
    int v6975 = v6971[v7125];
    int v6976 = v6973[v7125];
    bool v7140 = !(((~(((v6957 ^ ((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1))) | (-(v6957 ^ ((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v6958 ^ ((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1))) | (-(v6958 ^ ((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1))))) >> 31))) == 0);
    int v7030;
    if (v7140) {
      int * v6977 = v6948->cache_age;
      int v7142 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v6958 ^ ((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1))) | (-(v6958 ^ ((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1))))) >> 31)) & 1);
      int v6978 = v6977[v7142];
      int v6979 = v6977[v7126];
      int v7143 = v6979 + ((int)((unsigned int)(v6979 - v6978) >> 31));
      v6977[v7126] = v7143;
      int * v6981 = v6948->cache_age;
      int v6982 = v6981[v7127];
      int v7145 = v6982 + ((int)((unsigned int)(v6982 - v6978) >> 31));
      v6981[v7127] = v7145;
      int * v6984 = v6948->cache_age;
      v6984[v7142] = 0;
      v7030 = v7142;
    } else {
      int * v6987 = v6948->cache_age;
      int v7149 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1)) & 3) * 2);
      int v6988 = v6987[v7149];
      int * v6989 = v6948->cache_tags;
      int v6990 = v6989[v7149];
      int v6991 = v6987[v7127];
      int v6992 = v6989[v7127];
      int * v6993 = v6948->cache_dirty;
      int v7152 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v6988 + ((~(((v6990 ^ -1) | (-(v6990 ^ -1))) >> 31)) & 2)) - (v6991 + ((~(((v6992 ^ -1) | (-(v6992 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v6994 = v6993[v7152];
      bool v7153 = !(v6994 == 0);
      if (v7153) {
        int * v6995 = v6948->cache_tags;
        int v6996 = v6995[v7152];
        int * v6997 = v6948->cache_vals;
        int v7156 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v6988 + ((~(((v6990 ^ -1) | (-(v6990 ^ -1))) >> 31)) & 2)) - (v6991 + ((~(((v6992 ^ -1) | (-(v6992 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v6998 = v6997[v7156];
        int v7157 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v6988 + ((~(((v6990 ^ -1) | (-(v6990 ^ -1))) >> 31)) & 2)) - (v6991 + ((~(((v6992 ^ -1) | (-(v6992 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v6999 = v6997[v7157];
        int * v7000 = v6948->mem;
        int v7159 = v6996 * 2;
        v7000[v7159] = v6998;
        int * v7002 = v6948->mem;
        int v7162 = (v6996 * 2) + 1;
        v7002[v7162] = v6999;
        ;
      } else {
        ;
      }
      int * v7007 = v6948->mem;
      int v7167 = ((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1)) * 2;
      int v7008 = v7007[v7167];
      int v7168 = (((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1)) * 2) + 1;
      int v7009 = v7007[v7168];
      int * v7010 = v6948->cache_vals;
      int v7170 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v6988 + ((~(((v6990 ^ -1) | (-(v6990 ^ -1))) >> 31)) & 2)) - (v6991 + ((~(((v6992 ^ -1) | (-(v6992 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v7010[v7170] = v7008;
      int * v7012 = v6948->cache_vals;
      int v7173 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v6988 + ((~(((v6990 ^ -1) | (-(v6990 ^ -1))) >> 31)) & 2)) - (v6991 + ((~(((v6992 ^ -1) | (-(v6992 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v7012[v7173] = v7009;
      int * v7014 = v6948->cache_tags;
      int v7176 = (int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1);
      v7014[v7152] = v7176;
      int * v7016 = v6948->cache_dirty;
      v7016[v7152] = 0;
      int * v7018 = v6948->cache_age;
      v7018[v7152] = 1;
      int * v7020 = v6948->cache_age;
      int v7021 = v7020[v7152];
      int v7022 = v7020[v7126];
      int v7182 = v7022 + ((int)((unsigned int)(v7022 - v7021) >> 31));
      v7020[v7126] = v7182;
      int * v7024 = v6948->cache_age;
      int v7025 = v7024[v7127];
      int v7184 = v7025 + ((int)((unsigned int)(v7025 - v7021) >> 31));
      v7024[v7127] = v7184;
      int * v7027 = v6948->cache_age;
      v7027[v7152] = 0;
      v7030 = v7152;
    }
    int * v7031 = v6948->cache_vals;
    int v7187 = v7030 * 2;
    int v7032 = v7031[v7187];
    int v7188 = (v7030 * 2) + 1;
    int v7033 = v7031[v7188];
    int v7189 = (((((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v6972 + ((~(((v6974 ^ -1) | (-(v6974 ^ -1))) >> 31)) & 2)) - (v6975 + ((~(((v6976 ^ -1) | (-(v6976 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7031[v7189] = v7032;
    int * v7035 = v6948->cache_vals;
    int v7192 = ((((((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v6972 + ((~(((v6974 ^ -1) | (-(v6974 ^ -1))) >> 31)) & 2)) - (v6975 + ((~(((v6976 ^ -1) | (-(v6976 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7035[v7192] = v7033;
    int * v7037 = v6948->cache_tags;
    int v7195 = ((((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v6972 + ((~(((v6974 ^ -1) | (-(v6974 ^ -1))) >> 31)) & 2)) - (v6975 + ((~(((v6976 ^ -1) | (-(v6976 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7196 = (int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1);
    v7037[v7195] = v7196;
    int * v7039 = v6948->cache_dirty;
    v7039[v7195] = 0;
    int * v7041 = v6948->cache_age;
    v7041[v7195] = 1;
    int * v7043 = v6948->cache_age;
    int v7044 = v7043[v7195];
    int v7045 = v7043[v7124];
    int v7202 = v7045 + ((int)((unsigned int)(v7045 - v7044) >> 31));
    v7043[v7124] = v7202;
    int * v7047 = v6948->cache_age;
    int v7048 = v7047[v7125];
    int v7204 = v7048 + ((int)((unsigned int)(v7048 - v7044) >> 31));
    v7047[v7125] = v7204;
    int * v7050 = v6948->cache_age;
    v7050[v7195] = 0;
    v7053 = v7195;
  }
  int * v7054 = v6948->cache_vals;
  int v7207 = (v7053 * 2) + (((int)((unsigned int)(v6952 + 36) >> 2)) & 1);
  v7054[v7207] = v6953;
  int * v7056 = v6948->cache_tags;
  int v7057 = v7056[v7126];
  int v7058 = v7056[v7127];
  bool v7210 = !(((~(((v7057 ^ ((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1))) | (-(v7057 ^ ((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v7058 ^ ((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1))) | (-(v7058 ^ ((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v7112;
  if (v7210) {
    int * v7059 = v6948->cache_age;
    int v7212 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7058 ^ ((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1))) | (-(v7058 ^ ((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1))))) >> 31)) & 1);
    int v7060 = v7059[v7212];
    int v7061 = v7059[v7126];
    int v7213 = v7061 + ((int)((unsigned int)(v7061 - v7060) >> 31));
    v7059[v7126] = v7213;
    int * v7063 = v6948->cache_age;
    int v7064 = v7063[v7127];
    int v7215 = v7064 + ((int)((unsigned int)(v7064 - v7060) >> 31));
    v7063[v7127] = v7215;
    int * v7066 = v6948->cache_age;
    v7066[v7212] = 0;
    v7112 = v7212;
  } else {
    int * v7069 = v6948->cache_age;
    int v7219 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1)) & 3) * 2);
    int v7070 = v7069[v7219];
    int * v7071 = v6948->cache_tags;
    int v7072 = v7071[v7219];
    int v7073 = v7069[v7127];
    int v7074 = v7071[v7127];
    int * v7075 = v6948->cache_dirty;
    int v7222 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v7070 + ((~(((v7072 ^ -1) | (-(v7072 ^ -1))) >> 31)) & 2)) - (v7073 + ((~(((v7074 ^ -1) | (-(v7074 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7076 = v7075[v7222];
    bool v7223 = !(v7076 == 0);
    if (v7223) {
      int * v7077 = v6948->cache_tags;
      int v7078 = v7077[v7222];
      int * v7079 = v6948->cache_vals;
      int v7226 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v7070 + ((~(((v7072 ^ -1) | (-(v7072 ^ -1))) >> 31)) & 2)) - (v7073 + ((~(((v7074 ^ -1) | (-(v7074 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v7080 = v7079[v7226];
      int v7227 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v7070 + ((~(((v7072 ^ -1) | (-(v7072 ^ -1))) >> 31)) & 2)) - (v7073 + ((~(((v7074 ^ -1) | (-(v7074 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v7081 = v7079[v7227];
      int * v7082 = v6948->mem;
      int v7229 = v7078 * 2;
      v7082[v7229] = v7080;
      int * v7084 = v6948->mem;
      int v7232 = (v7078 * 2) + 1;
      v7084[v7232] = v7081;
      ;
    } else {
      ;
    }
    int * v7089 = v6948->mem;
    int v7237 = ((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1)) * 2;
    int v7090 = v7089[v7237];
    int v7238 = (((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1)) * 2) + 1;
    int v7091 = v7089[v7238];
    int * v7092 = v6948->cache_vals;
    int v7240 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v7070 + ((~(((v7072 ^ -1) | (-(v7072 ^ -1))) >> 31)) & 2)) - (v7073 + ((~(((v7074 ^ -1) | (-(v7074 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7092[v7240] = v7090;
    int * v7094 = v6948->cache_vals;
    int v7243 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v7070 + ((~(((v7072 ^ -1) | (-(v7072 ^ -1))) >> 31)) & 2)) - (v7073 + ((~(((v7074 ^ -1) | (-(v7074 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7094[v7243] = v7091;
    int * v7096 = v6948->cache_tags;
    int v7246 = (int)((unsigned int)((int)((unsigned int)(v6952 + 36) >> 2)) >> 1);
    v7096[v7222] = v7246;
    int * v7098 = v6948->cache_dirty;
    v7098[v7222] = 0;
    int * v7100 = v6948->cache_age;
    v7100[v7222] = 1;
    int * v7102 = v6948->cache_age;
    int v7103 = v7102[v7222];
    int v7104 = v7102[v7126];
    int v7252 = v7104 + ((int)((unsigned int)(v7104 - v7103) >> 31));
    v7102[v7126] = v7252;
    int * v7106 = v6948->cache_age;
    int v7107 = v7106[v7127];
    int v7254 = v7107 + ((int)((unsigned int)(v7107 - v7103) >> 31));
    v7106[v7127] = v7254;
    int * v7109 = v6948->cache_age;
    v7109[v7222] = 0;
    v7112 = v7222;
  }
  int * v7113 = v6948->cache_vals;
  int v7257 = (v7112 * 2) + (((int)((unsigned int)(v6952 + 36) >> 2)) & 1);
  v7113[v7257] = v6953;
  int * v7115 = v6948->cache_dirty;
  v7115[v7112] = 1;
  struct StateT * v7117 = slot_67(v6948);
  return v7117;
}

struct StateT * slot_28(struct StateT * v3252) {
  int v3253 = v3252->timer;
  int v3260 = v3253 + 1;
  v3252->timer = v3260;
  int * v3255 = v3252->regs;
  int v3256 = v3255[11];
  int v3264 = v3256 + 12;
  v3255[13] = v3264;
  struct StateT * v3258 = slot_29(v3252);
  return v3258;
}

struct StateT * slot_32(struct StateT * v3843) {
  int v3844 = v3843->timer;
  int v3851 = v3844 + 1;
  v3843->timer = v3851;
  int * v3846 = v3843->regs;
  int v3847 = v3846[10];
  int v3855 = v3847 + 16;
  v3846[13] = v3855;
  struct StateT * v3849 = slot_33(v3843);
  return v3849;
}

struct StateT * slot_17(struct StateT * v1447) {
  int v1448 = v1447->timer;
  int v1618 = v1448 + 1;
  v1447->timer = v1618;
  int * v1450 = v1447->regs;
  int v1451 = v1450[10];
  int v1452 = v1450[15];
  int * v1453 = v1447->cache_tags;
  int v1623 = (((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1)) & 1) * 2;
  int v1454 = v1453[v1623];
  int v1624 = ((((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1455 = v1453[v1624];
  int v1625 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1)) & 3) * 2);
  int v1456 = v1453[v1625];
  int v1626 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1457 = v1453[v1626];
  int v1458 = v1447->timer;
  int v1627 = v1458 + ((100 ^ (((~(((v1456 ^ ((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1))) | (-(v1456 ^ ((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1))))) >> 31)) | (~(((v1457 ^ ((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1))) | (-(v1457 ^ ((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1454 ^ ((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1))) | (-(v1454 ^ ((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1))))) >> 31)) | (~(((v1455 ^ ((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1))) | (-(v1455 ^ ((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1456 ^ ((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1))) | (-(v1456 ^ ((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1))))) >> 31)) | (~(((v1457 ^ ((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1))) | (-(v1457 ^ ((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1447->timer = v1627;
  bool v1628 = !(((~(((v1454 ^ ((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1))) | (-(v1454 ^ ((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1))))) >> 31)) | (~(((v1455 ^ ((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1))) | (-(v1455 ^ ((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1))))) >> 31))) == 0);
  int v1552;
  if (v1628) {
    int * v1460 = v1447->cache_age;
    int v1630 = ((((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1)) & 1) * 2) + ((~(((v1455 ^ ((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1))) | (-(v1455 ^ ((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1))))) >> 31)) & 1);
    int v1461 = v1460[v1630];
    int v1462 = v1460[v1623];
    int v1631 = v1462 + ((int)((unsigned int)(v1462 - v1461) >> 31));
    v1460[v1623] = v1631;
    int * v1464 = v1447->cache_age;
    int v1465 = v1464[v1624];
    int v1633 = v1465 + ((int)((unsigned int)(v1465 - v1461) >> 31));
    v1464[v1624] = v1633;
    int * v1467 = v1447->cache_age;
    v1467[v1630] = 0;
    v1552 = v1630;
  } else {
    int * v1470 = v1447->cache_age;
    int v1637 = (((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1)) & 1) * 2;
    int v1471 = v1470[v1637];
    int * v1472 = v1447->cache_tags;
    int v1473 = v1472[v1637];
    int v1474 = v1470[v1624];
    int v1475 = v1472[v1624];
    bool v1639 = !(((~(((v1456 ^ ((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1))) | (-(v1456 ^ ((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1))))) >> 31)) | (~(((v1457 ^ ((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1))) | (-(v1457 ^ ((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1))))) >> 31))) == 0);
    int v1529;
    if (v1639) {
      int * v1476 = v1447->cache_age;
      int v1641 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1457 ^ ((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1))) | (-(v1457 ^ ((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1))))) >> 31)) & 1);
      int v1477 = v1476[v1641];
      int v1478 = v1476[v1625];
      int v1642 = v1478 + ((int)((unsigned int)(v1478 - v1477) >> 31));
      v1476[v1625] = v1642;
      int * v1480 = v1447->cache_age;
      int v1481 = v1480[v1626];
      int v1644 = v1481 + ((int)((unsigned int)(v1481 - v1477) >> 31));
      v1480[v1626] = v1644;
      int * v1483 = v1447->cache_age;
      v1483[v1641] = 0;
      v1529 = v1641;
    } else {
      int * v1486 = v1447->cache_age;
      int v1648 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1)) & 3) * 2);
      int v1487 = v1486[v1648];
      int * v1488 = v1447->cache_tags;
      int v1489 = v1488[v1648];
      int v1490 = v1486[v1626];
      int v1491 = v1488[v1626];
      int * v1492 = v1447->cache_dirty;
      int v1651 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1)) & 3) * 2)) + ((((v1487 + ((~(((v1489 ^ -1) | (-(v1489 ^ -1))) >> 31)) & 2)) - (v1490 + ((~(((v1491 ^ -1) | (-(v1491 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1493 = v1492[v1651];
      bool v1652 = !(v1493 == 0);
      if (v1652) {
        int * v1494 = v1447->cache_tags;
        int v1495 = v1494[v1651];
        int * v1496 = v1447->cache_vals;
        int v1655 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1)) & 3) * 2)) + ((((v1487 + ((~(((v1489 ^ -1) | (-(v1489 ^ -1))) >> 31)) & 2)) - (v1490 + ((~(((v1491 ^ -1) | (-(v1491 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1497 = v1496[v1655];
        int v1656 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1)) & 3) * 2)) + ((((v1487 + ((~(((v1489 ^ -1) | (-(v1489 ^ -1))) >> 31)) & 2)) - (v1490 + ((~(((v1491 ^ -1) | (-(v1491 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1498 = v1496[v1656];
        int * v1499 = v1447->mem;
        int v1658 = v1495 * 2;
        v1499[v1658] = v1497;
        int * v1501 = v1447->mem;
        int v1661 = (v1495 * 2) + 1;
        v1501[v1661] = v1498;
        ;
      } else {
        ;
      }
      int * v1506 = v1447->mem;
      int v1666 = ((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1)) * 2;
      int v1507 = v1506[v1666];
      int v1667 = (((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1)) * 2) + 1;
      int v1508 = v1506[v1667];
      int * v1509 = v1447->cache_vals;
      int v1669 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1)) & 3) * 2)) + ((((v1487 + ((~(((v1489 ^ -1) | (-(v1489 ^ -1))) >> 31)) & 2)) - (v1490 + ((~(((v1491 ^ -1) | (-(v1491 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1509[v1669] = v1507;
      int * v1511 = v1447->cache_vals;
      int v1672 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1)) & 3) * 2)) + ((((v1487 + ((~(((v1489 ^ -1) | (-(v1489 ^ -1))) >> 31)) & 2)) - (v1490 + ((~(((v1491 ^ -1) | (-(v1491 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1511[v1672] = v1508;
      int * v1513 = v1447->cache_tags;
      int v1675 = (int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1);
      v1513[v1651] = v1675;
      int * v1515 = v1447->cache_dirty;
      v1515[v1651] = 0;
      int * v1517 = v1447->cache_age;
      v1517[v1651] = 1;
      int * v1519 = v1447->cache_age;
      int v1520 = v1519[v1651];
      int v1521 = v1519[v1625];
      int v1681 = v1521 + ((int)((unsigned int)(v1521 - v1520) >> 31));
      v1519[v1625] = v1681;
      int * v1523 = v1447->cache_age;
      int v1524 = v1523[v1626];
      int v1683 = v1524 + ((int)((unsigned int)(v1524 - v1520) >> 31));
      v1523[v1626] = v1683;
      int * v1526 = v1447->cache_age;
      v1526[v1651] = 0;
      v1529 = v1651;
    }
    int * v1530 = v1447->cache_vals;
    int v1686 = v1529 * 2;
    int v1531 = v1530[v1686];
    int v1687 = (v1529 * 2) + 1;
    int v1532 = v1530[v1687];
    int v1688 = (((((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1)) & 1) * 2) + ((((v1471 + ((~(((v1473 ^ -1) | (-(v1473 ^ -1))) >> 31)) & 2)) - (v1474 + ((~(((v1475 ^ -1) | (-(v1475 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1530[v1688] = v1531;
    int * v1534 = v1447->cache_vals;
    int v1691 = ((((((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1)) & 1) * 2) + ((((v1471 + ((~(((v1473 ^ -1) | (-(v1473 ^ -1))) >> 31)) & 2)) - (v1474 + ((~(((v1475 ^ -1) | (-(v1475 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1534[v1691] = v1532;
    int * v1536 = v1447->cache_tags;
    int v1694 = ((((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1)) & 1) * 2) + ((((v1471 + ((~(((v1473 ^ -1) | (-(v1473 ^ -1))) >> 31)) & 2)) - (v1474 + ((~(((v1475 ^ -1) | (-(v1475 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1695 = (int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1);
    v1536[v1694] = v1695;
    int * v1538 = v1447->cache_dirty;
    v1538[v1694] = 0;
    int * v1540 = v1447->cache_age;
    v1540[v1694] = 1;
    int * v1542 = v1447->cache_age;
    int v1543 = v1542[v1694];
    int v1544 = v1542[v1623];
    int v1701 = v1544 + ((int)((unsigned int)(v1544 - v1543) >> 31));
    v1542[v1623] = v1701;
    int * v1546 = v1447->cache_age;
    int v1547 = v1546[v1624];
    int v1703 = v1547 + ((int)((unsigned int)(v1547 - v1543) >> 31));
    v1546[v1624] = v1703;
    int * v1549 = v1447->cache_age;
    v1549[v1694] = 0;
    v1552 = v1694;
  }
  int * v1553 = v1447->cache_vals;
  int v1706 = (v1552 * 2) + (((int)((unsigned int)v1451 >> 2)) & 1);
  v1553[v1706] = v1452;
  int * v1555 = v1447->cache_tags;
  int v1556 = v1555[v1625];
  int v1557 = v1555[v1626];
  bool v1709 = !(((~(((v1556 ^ ((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1))) | (-(v1556 ^ ((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1))))) >> 31)) | (~(((v1557 ^ ((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1))) | (-(v1557 ^ ((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1))))) >> 31))) == 0);
  int v1611;
  if (v1709) {
    int * v1558 = v1447->cache_age;
    int v1711 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1557 ^ ((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1))) | (-(v1557 ^ ((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1))))) >> 31)) & 1);
    int v1559 = v1558[v1711];
    int v1560 = v1558[v1625];
    int v1712 = v1560 + ((int)((unsigned int)(v1560 - v1559) >> 31));
    v1558[v1625] = v1712;
    int * v1562 = v1447->cache_age;
    int v1563 = v1562[v1626];
    int v1714 = v1563 + ((int)((unsigned int)(v1563 - v1559) >> 31));
    v1562[v1626] = v1714;
    int * v1565 = v1447->cache_age;
    v1565[v1711] = 0;
    v1611 = v1711;
  } else {
    int * v1568 = v1447->cache_age;
    int v1718 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1)) & 3) * 2);
    int v1569 = v1568[v1718];
    int * v1570 = v1447->cache_tags;
    int v1571 = v1570[v1718];
    int v1572 = v1568[v1626];
    int v1573 = v1570[v1626];
    int * v1574 = v1447->cache_dirty;
    int v1721 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1)) & 3) * 2)) + ((((v1569 + ((~(((v1571 ^ -1) | (-(v1571 ^ -1))) >> 31)) & 2)) - (v1572 + ((~(((v1573 ^ -1) | (-(v1573 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1575 = v1574[v1721];
    bool v1722 = !(v1575 == 0);
    if (v1722) {
      int * v1576 = v1447->cache_tags;
      int v1577 = v1576[v1721];
      int * v1578 = v1447->cache_vals;
      int v1725 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1)) & 3) * 2)) + ((((v1569 + ((~(((v1571 ^ -1) | (-(v1571 ^ -1))) >> 31)) & 2)) - (v1572 + ((~(((v1573 ^ -1) | (-(v1573 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1579 = v1578[v1725];
      int v1726 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1)) & 3) * 2)) + ((((v1569 + ((~(((v1571 ^ -1) | (-(v1571 ^ -1))) >> 31)) & 2)) - (v1572 + ((~(((v1573 ^ -1) | (-(v1573 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1580 = v1578[v1726];
      int * v1581 = v1447->mem;
      int v1728 = v1577 * 2;
      v1581[v1728] = v1579;
      int * v1583 = v1447->mem;
      int v1731 = (v1577 * 2) + 1;
      v1583[v1731] = v1580;
      ;
    } else {
      ;
    }
    int * v1588 = v1447->mem;
    int v1736 = ((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1)) * 2;
    int v1589 = v1588[v1736];
    int v1737 = (((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1)) * 2) + 1;
    int v1590 = v1588[v1737];
    int * v1591 = v1447->cache_vals;
    int v1739 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1)) & 3) * 2)) + ((((v1569 + ((~(((v1571 ^ -1) | (-(v1571 ^ -1))) >> 31)) & 2)) - (v1572 + ((~(((v1573 ^ -1) | (-(v1573 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1591[v1739] = v1589;
    int * v1593 = v1447->cache_vals;
    int v1742 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1)) & 3) * 2)) + ((((v1569 + ((~(((v1571 ^ -1) | (-(v1571 ^ -1))) >> 31)) & 2)) - (v1572 + ((~(((v1573 ^ -1) | (-(v1573 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1593[v1742] = v1590;
    int * v1595 = v1447->cache_tags;
    int v1745 = (int)((unsigned int)((int)((unsigned int)v1451 >> 2)) >> 1);
    v1595[v1721] = v1745;
    int * v1597 = v1447->cache_dirty;
    v1597[v1721] = 0;
    int * v1599 = v1447->cache_age;
    v1599[v1721] = 1;
    int * v1601 = v1447->cache_age;
    int v1602 = v1601[v1721];
    int v1603 = v1601[v1625];
    int v1751 = v1603 + ((int)((unsigned int)(v1603 - v1602) >> 31));
    v1601[v1625] = v1751;
    int * v1605 = v1447->cache_age;
    int v1606 = v1605[v1626];
    int v1753 = v1606 + ((int)((unsigned int)(v1606 - v1602) >> 31));
    v1605[v1626] = v1753;
    int * v1608 = v1447->cache_age;
    v1608[v1721] = 0;
    v1611 = v1721;
  }
  int * v1612 = v1447->cache_vals;
  int v1756 = (v1611 * 2) + (((int)((unsigned int)v1451 >> 2)) & 1);
  v1612[v1756] = v1452;
  int * v1614 = v1447->cache_dirty;
  v1614[v1611] = 1;
  struct StateT * v1616 = slot_18(v1447);
  return v1616;
}

struct StateT * slot_49(struct StateT * v5536) {
  int v5537 = v5536->timer;
  int v5547 = v5537 + 1;
  v5536->timer = v5547;
  int * v5539 = v5536->regs;
  int v5540 = v5539[12];
  bool v5550 = !(v5540 == 0);
  struct StateT * v5545;
  if (v5550) {
    struct StateT * v5541 = slot_52(v5536);
    v5545 = v5541;
  } else {
    struct StateT * v5543 = slot_50(v5536);
    v5545 = v5543;
  }
  return v5545;
}

struct StateT * slot_33(struct StateT * v4061) {
  int v4062 = v4061->timer;
  int v4066 = v4062 + 1;
  v4061->timer = v4066;
  struct StateT * v4064 = slot_35(v4061);
  return v4064;
}

struct StateT * slot_50(struct StateT * v5571) {
  int v5572 = v5571->timer;
  int v5579 = v5572 + 1;
  v5571->timer = v5579;
  int * v5574 = v5571->regs;
  int v5575 = v5574[10];
  int v5583 = v5575 + 28;
  v5574[13] = v5583;
  struct StateT * v5577 = slot_51(v5571);
  return v5577;
}

struct StateT * slot_36(struct StateT * v4069) {
  int v4070 = v4069->timer;
  int v4240 = v4070 + 1;
  v4069->timer = v4240;
  int * v4072 = v4069->regs;
  int v4073 = v4072[10];
  int v4074 = v4072[13];
  int * v4075 = v4069->cache_tags;
  int v4245 = (((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1)) & 1) * 2;
  int v4076 = v4075[v4245];
  int v4246 = ((((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4077 = v4075[v4246];
  int v4247 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1)) & 3) * 2);
  int v4078 = v4075[v4247];
  int v4248 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4079 = v4075[v4248];
  int v4080 = v4069->timer;
  int v4249 = v4080 + ((100 ^ (((~(((v4078 ^ ((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1))) | (-(v4078 ^ ((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v4079 ^ ((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1))) | (-(v4079 ^ ((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4076 ^ ((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1))) | (-(v4076 ^ ((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v4077 ^ ((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1))) | (-(v4077 ^ ((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4078 ^ ((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1))) | (-(v4078 ^ ((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v4079 ^ ((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1))) | (-(v4079 ^ ((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4069->timer = v4249;
  bool v4250 = !(((~(((v4076 ^ ((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1))) | (-(v4076 ^ ((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v4077 ^ ((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1))) | (-(v4077 ^ ((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v4174;
  if (v4250) {
    int * v4082 = v4069->cache_age;
    int v4252 = ((((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v4077 ^ ((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1))) | (-(v4077 ^ ((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v4083 = v4082[v4252];
    int v4084 = v4082[v4245];
    int v4253 = v4084 + ((int)((unsigned int)(v4084 - v4083) >> 31));
    v4082[v4245] = v4253;
    int * v4086 = v4069->cache_age;
    int v4087 = v4086[v4246];
    int v4255 = v4087 + ((int)((unsigned int)(v4087 - v4083) >> 31));
    v4086[v4246] = v4255;
    int * v4089 = v4069->cache_age;
    v4089[v4252] = 0;
    v4174 = v4252;
  } else {
    int * v4092 = v4069->cache_age;
    int v4259 = (((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1)) & 1) * 2;
    int v4093 = v4092[v4259];
    int * v4094 = v4069->cache_tags;
    int v4095 = v4094[v4259];
    int v4096 = v4092[v4246];
    int v4097 = v4094[v4246];
    bool v4261 = !(((~(((v4078 ^ ((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1))) | (-(v4078 ^ ((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v4079 ^ ((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1))) | (-(v4079 ^ ((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v4151;
    if (v4261) {
      int * v4098 = v4069->cache_age;
      int v4263 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4079 ^ ((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1))) | (-(v4079 ^ ((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v4099 = v4098[v4263];
      int v4100 = v4098[v4247];
      int v4264 = v4100 + ((int)((unsigned int)(v4100 - v4099) >> 31));
      v4098[v4247] = v4264;
      int * v4102 = v4069->cache_age;
      int v4103 = v4102[v4248];
      int v4266 = v4103 + ((int)((unsigned int)(v4103 - v4099) >> 31));
      v4102[v4248] = v4266;
      int * v4105 = v4069->cache_age;
      v4105[v4263] = 0;
      v4151 = v4263;
    } else {
      int * v4108 = v4069->cache_age;
      int v4270 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1)) & 3) * 2);
      int v4109 = v4108[v4270];
      int * v4110 = v4069->cache_tags;
      int v4111 = v4110[v4270];
      int v4112 = v4108[v4248];
      int v4113 = v4110[v4248];
      int * v4114 = v4069->cache_dirty;
      int v4273 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4109 + ((~(((v4111 ^ -1) | (-(v4111 ^ -1))) >> 31)) & 2)) - (v4112 + ((~(((v4113 ^ -1) | (-(v4113 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4115 = v4114[v4273];
      bool v4274 = !(v4115 == 0);
      if (v4274) {
        int * v4116 = v4069->cache_tags;
        int v4117 = v4116[v4273];
        int * v4118 = v4069->cache_vals;
        int v4277 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4109 + ((~(((v4111 ^ -1) | (-(v4111 ^ -1))) >> 31)) & 2)) - (v4112 + ((~(((v4113 ^ -1) | (-(v4113 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4119 = v4118[v4277];
        int v4278 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4109 + ((~(((v4111 ^ -1) | (-(v4111 ^ -1))) >> 31)) & 2)) - (v4112 + ((~(((v4113 ^ -1) | (-(v4113 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4120 = v4118[v4278];
        int * v4121 = v4069->mem;
        int v4280 = v4117 * 2;
        v4121[v4280] = v4119;
        int * v4123 = v4069->mem;
        int v4283 = (v4117 * 2) + 1;
        v4123[v4283] = v4120;
        ;
      } else {
        ;
      }
      int * v4128 = v4069->mem;
      int v4288 = ((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1)) * 2;
      int v4129 = v4128[v4288];
      int v4289 = (((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1)) * 2) + 1;
      int v4130 = v4128[v4289];
      int * v4131 = v4069->cache_vals;
      int v4291 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4109 + ((~(((v4111 ^ -1) | (-(v4111 ^ -1))) >> 31)) & 2)) - (v4112 + ((~(((v4113 ^ -1) | (-(v4113 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4131[v4291] = v4129;
      int * v4133 = v4069->cache_vals;
      int v4294 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4109 + ((~(((v4111 ^ -1) | (-(v4111 ^ -1))) >> 31)) & 2)) - (v4112 + ((~(((v4113 ^ -1) | (-(v4113 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4133[v4294] = v4130;
      int * v4135 = v4069->cache_tags;
      int v4297 = (int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1);
      v4135[v4273] = v4297;
      int * v4137 = v4069->cache_dirty;
      v4137[v4273] = 0;
      int * v4139 = v4069->cache_age;
      v4139[v4273] = 1;
      int * v4141 = v4069->cache_age;
      int v4142 = v4141[v4273];
      int v4143 = v4141[v4247];
      int v4303 = v4143 + ((int)((unsigned int)(v4143 - v4142) >> 31));
      v4141[v4247] = v4303;
      int * v4145 = v4069->cache_age;
      int v4146 = v4145[v4248];
      int v4305 = v4146 + ((int)((unsigned int)(v4146 - v4142) >> 31));
      v4145[v4248] = v4305;
      int * v4148 = v4069->cache_age;
      v4148[v4273] = 0;
      v4151 = v4273;
    }
    int * v4152 = v4069->cache_vals;
    int v4308 = v4151 * 2;
    int v4153 = v4152[v4308];
    int v4309 = (v4151 * 2) + 1;
    int v4154 = v4152[v4309];
    int v4310 = (((((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v4093 + ((~(((v4095 ^ -1) | (-(v4095 ^ -1))) >> 31)) & 2)) - (v4096 + ((~(((v4097 ^ -1) | (-(v4097 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4152[v4310] = v4153;
    int * v4156 = v4069->cache_vals;
    int v4313 = ((((((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v4093 + ((~(((v4095 ^ -1) | (-(v4095 ^ -1))) >> 31)) & 2)) - (v4096 + ((~(((v4097 ^ -1) | (-(v4097 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4156[v4313] = v4154;
    int * v4158 = v4069->cache_tags;
    int v4316 = ((((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v4093 + ((~(((v4095 ^ -1) | (-(v4095 ^ -1))) >> 31)) & 2)) - (v4096 + ((~(((v4097 ^ -1) | (-(v4097 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4317 = (int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1);
    v4158[v4316] = v4317;
    int * v4160 = v4069->cache_dirty;
    v4160[v4316] = 0;
    int * v4162 = v4069->cache_age;
    v4162[v4316] = 1;
    int * v4164 = v4069->cache_age;
    int v4165 = v4164[v4316];
    int v4166 = v4164[v4245];
    int v4323 = v4166 + ((int)((unsigned int)(v4166 - v4165) >> 31));
    v4164[v4245] = v4323;
    int * v4168 = v4069->cache_age;
    int v4169 = v4168[v4246];
    int v4325 = v4169 + ((int)((unsigned int)(v4169 - v4165) >> 31));
    v4168[v4246] = v4325;
    int * v4171 = v4069->cache_age;
    v4171[v4316] = 0;
    v4174 = v4316;
  }
  int * v4175 = v4069->cache_vals;
  int v4328 = (v4174 * 2) + (((int)((unsigned int)(v4073 + 16) >> 2)) & 1);
  v4175[v4328] = v4074;
  int * v4177 = v4069->cache_tags;
  int v4178 = v4177[v4247];
  int v4179 = v4177[v4248];
  bool v4331 = !(((~(((v4178 ^ ((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1))) | (-(v4178 ^ ((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v4179 ^ ((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1))) | (-(v4179 ^ ((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v4233;
  if (v4331) {
    int * v4180 = v4069->cache_age;
    int v4333 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4179 ^ ((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1))) | (-(v4179 ^ ((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v4181 = v4180[v4333];
    int v4182 = v4180[v4247];
    int v4334 = v4182 + ((int)((unsigned int)(v4182 - v4181) >> 31));
    v4180[v4247] = v4334;
    int * v4184 = v4069->cache_age;
    int v4185 = v4184[v4248];
    int v4336 = v4185 + ((int)((unsigned int)(v4185 - v4181) >> 31));
    v4184[v4248] = v4336;
    int * v4187 = v4069->cache_age;
    v4187[v4333] = 0;
    v4233 = v4333;
  } else {
    int * v4190 = v4069->cache_age;
    int v4340 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1)) & 3) * 2);
    int v4191 = v4190[v4340];
    int * v4192 = v4069->cache_tags;
    int v4193 = v4192[v4340];
    int v4194 = v4190[v4248];
    int v4195 = v4192[v4248];
    int * v4196 = v4069->cache_dirty;
    int v4343 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4191 + ((~(((v4193 ^ -1) | (-(v4193 ^ -1))) >> 31)) & 2)) - (v4194 + ((~(((v4195 ^ -1) | (-(v4195 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4197 = v4196[v4343];
    bool v4344 = !(v4197 == 0);
    if (v4344) {
      int * v4198 = v4069->cache_tags;
      int v4199 = v4198[v4343];
      int * v4200 = v4069->cache_vals;
      int v4347 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4191 + ((~(((v4193 ^ -1) | (-(v4193 ^ -1))) >> 31)) & 2)) - (v4194 + ((~(((v4195 ^ -1) | (-(v4195 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v4201 = v4200[v4347];
      int v4348 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4191 + ((~(((v4193 ^ -1) | (-(v4193 ^ -1))) >> 31)) & 2)) - (v4194 + ((~(((v4195 ^ -1) | (-(v4195 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v4202 = v4200[v4348];
      int * v4203 = v4069->mem;
      int v4350 = v4199 * 2;
      v4203[v4350] = v4201;
      int * v4205 = v4069->mem;
      int v4353 = (v4199 * 2) + 1;
      v4205[v4353] = v4202;
      ;
    } else {
      ;
    }
    int * v4210 = v4069->mem;
    int v4358 = ((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1)) * 2;
    int v4211 = v4210[v4358];
    int v4359 = (((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1)) * 2) + 1;
    int v4212 = v4210[v4359];
    int * v4213 = v4069->cache_vals;
    int v4361 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4191 + ((~(((v4193 ^ -1) | (-(v4193 ^ -1))) >> 31)) & 2)) - (v4194 + ((~(((v4195 ^ -1) | (-(v4195 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4213[v4361] = v4211;
    int * v4215 = v4069->cache_vals;
    int v4364 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v4191 + ((~(((v4193 ^ -1) | (-(v4193 ^ -1))) >> 31)) & 2)) - (v4194 + ((~(((v4195 ^ -1) | (-(v4195 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4215[v4364] = v4212;
    int * v4217 = v4069->cache_tags;
    int v4367 = (int)((unsigned int)((int)((unsigned int)(v4073 + 16) >> 2)) >> 1);
    v4217[v4343] = v4367;
    int * v4219 = v4069->cache_dirty;
    v4219[v4343] = 0;
    int * v4221 = v4069->cache_age;
    v4221[v4343] = 1;
    int * v4223 = v4069->cache_age;
    int v4224 = v4223[v4343];
    int v4225 = v4223[v4247];
    int v4373 = v4225 + ((int)((unsigned int)(v4225 - v4224) >> 31));
    v4223[v4247] = v4373;
    int * v4227 = v4069->cache_age;
    int v4228 = v4227[v4248];
    int v4375 = v4228 + ((int)((unsigned int)(v4228 - v4224) >> 31));
    v4227[v4248] = v4375;
    int * v4230 = v4069->cache_age;
    v4230[v4343] = 0;
    v4233 = v4343;
  }
  int * v4234 = v4069->cache_vals;
  int v4378 = (v4233 * 2) + (((int)((unsigned int)(v4073 + 16) >> 2)) & 1);
  v4234[v4378] = v4074;
  int * v4236 = v4069->cache_dirty;
  v4236[v4233] = 1;
  struct StateT * v4238 = slot_37(v4069);
  return v4238;
}

struct StateT * slot_37(struct StateT * v4384) {
  int v4385 = v4384->timer;
  int v4395 = v4385 + 1;
  v4384->timer = v4395;
  int * v4387 = v4384->regs;
  int v4388 = v4387[12];
  bool v4398 = !(v4388 == 0);
  struct StateT * v4393;
  if (v4398) {
    struct StateT * v4389 = slot_40(v4384);
    v4393 = v4389;
  } else {
    struct StateT * v4391 = slot_38(v4384);
    v4393 = v4391;
  }
  return v4393;
}

struct StateT * slot_57(struct StateT * v6365) {
  int v6366 = v6365->timer;
  int v6370 = v6366 + 1;
  v6365->timer = v6370;
  struct StateT * v6368 = slot_59(v6365);
  return v6368;
}

struct StateT * slot_59(struct StateT * v6162) {
  int v6163 = v6162->timer;
  int v6273 = v6163 + 1;
  v6162->timer = v6273;
  int * v6165 = v6162->regs;
  int v6166 = v6165[13];
  int * v6167 = v6162->cache_tags;
  int v6277 = (((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1)) & 1) * 2;
  int v6168 = v6167[v6277];
  int v6278 = ((((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1)) & 1) * 2) + 1;
  int v6169 = v6167[v6278];
  int v6279 = 4 + ((((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1)) & 3) * 2);
  int v6170 = v6167[v6279];
  int v6280 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v6171 = v6167[v6280];
  int v6172 = v6162->timer;
  int v6281 = v6172 + ((100 ^ (((~(((v6170 ^ ((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1))) | (-(v6170 ^ ((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1))))) >> 31)) | (~(((v6171 ^ ((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1))) | (-(v6171 ^ ((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v6168 ^ ((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1))) | (-(v6168 ^ ((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1))))) >> 31)) | (~(((v6169 ^ ((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1))) | (-(v6169 ^ ((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v6170 ^ ((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1))) | (-(v6170 ^ ((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1))))) >> 31)) | (~(((v6171 ^ ((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1))) | (-(v6171 ^ ((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1))))) >> 31))) & 104)))));
  v6162->timer = v6281;
  int * v6174 = v6162->cache_vals;
  bool v6282 = !(((~(((v6168 ^ ((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1))) | (-(v6168 ^ ((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1))))) >> 31)) | (~(((v6169 ^ ((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1))) | (-(v6169 ^ ((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1))))) >> 31))) == 0);
  int v6267;
  if (v6282) {
    int * v6175 = v6162->cache_age;
    int v6284 = ((((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1)) & 1) * 2) + ((~(((v6169 ^ ((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1))) | (-(v6169 ^ ((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1))))) >> 31)) & 1);
    int v6176 = v6175[v6284];
    int v6177 = v6175[v6277];
    int v6285 = v6177 + ((int)((unsigned int)(v6177 - v6176) >> 31));
    v6175[v6277] = v6285;
    int * v6179 = v6162->cache_age;
    int v6180 = v6179[v6278];
    int v6287 = v6180 + ((int)((unsigned int)(v6180 - v6176) >> 31));
    v6179[v6278] = v6287;
    int * v6182 = v6162->cache_age;
    v6182[v6284] = 0;
    v6267 = v6284;
  } else {
    int * v6185 = v6162->cache_age;
    int v6291 = (((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1)) & 1) * 2;
    int v6186 = v6185[v6291];
    int * v6187 = v6162->cache_tags;
    int v6188 = v6187[v6291];
    int v6189 = v6185[v6278];
    int v6190 = v6187[v6278];
    bool v6293 = !(((~(((v6170 ^ ((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1))) | (-(v6170 ^ ((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1))))) >> 31)) | (~(((v6171 ^ ((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1))) | (-(v6171 ^ ((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1))))) >> 31))) == 0);
    int v6244;
    if (v6293) {
      int * v6191 = v6162->cache_age;
      int v6295 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1)) & 3) * 2)) + ((~(((v6171 ^ ((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1))) | (-(v6171 ^ ((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1))))) >> 31)) & 1);
      int v6192 = v6191[v6295];
      int v6193 = v6191[v6279];
      int v6296 = v6193 + ((int)((unsigned int)(v6193 - v6192) >> 31));
      v6191[v6279] = v6296;
      int * v6195 = v6162->cache_age;
      int v6196 = v6195[v6280];
      int v6298 = v6196 + ((int)((unsigned int)(v6196 - v6192) >> 31));
      v6195[v6280] = v6298;
      int * v6198 = v6162->cache_age;
      v6198[v6295] = 0;
      v6244 = v6295;
    } else {
      int * v6201 = v6162->cache_age;
      int v6302 = 4 + ((((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1)) & 3) * 2);
      int v6202 = v6201[v6302];
      int * v6203 = v6162->cache_tags;
      int v6204 = v6203[v6302];
      int v6205 = v6201[v6280];
      int v6206 = v6203[v6280];
      int * v6207 = v6162->cache_dirty;
      int v6305 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1)) & 3) * 2)) + ((((v6202 + ((~(((v6204 ^ -1) | (-(v6204 ^ -1))) >> 31)) & 2)) - (v6205 + ((~(((v6206 ^ -1) | (-(v6206 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v6208 = v6207[v6305];
      bool v6306 = !(v6208 == 0);
      if (v6306) {
        int * v6209 = v6162->cache_tags;
        int v6210 = v6209[v6305];
        int * v6211 = v6162->cache_vals;
        int v6309 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1)) & 3) * 2)) + ((((v6202 + ((~(((v6204 ^ -1) | (-(v6204 ^ -1))) >> 31)) & 2)) - (v6205 + ((~(((v6206 ^ -1) | (-(v6206 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v6212 = v6211[v6309];
        int v6310 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1)) & 3) * 2)) + ((((v6202 + ((~(((v6204 ^ -1) | (-(v6204 ^ -1))) >> 31)) & 2)) - (v6205 + ((~(((v6206 ^ -1) | (-(v6206 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v6213 = v6211[v6310];
        int * v6214 = v6162->mem;
        int v6312 = v6210 * 2;
        v6214[v6312] = v6212;
        int * v6216 = v6162->mem;
        int v6315 = (v6210 * 2) + 1;
        v6216[v6315] = v6213;
        ;
      } else {
        ;
      }
      int * v6221 = v6162->mem;
      int v6320 = ((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1)) * 2;
      int v6222 = v6221[v6320];
      int v6321 = (((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1)) * 2) + 1;
      int v6223 = v6221[v6321];
      int * v6224 = v6162->cache_vals;
      int v6323 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1)) & 3) * 2)) + ((((v6202 + ((~(((v6204 ^ -1) | (-(v6204 ^ -1))) >> 31)) & 2)) - (v6205 + ((~(((v6206 ^ -1) | (-(v6206 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v6224[v6323] = v6222;
      int * v6226 = v6162->cache_vals;
      int v6326 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1)) & 3) * 2)) + ((((v6202 + ((~(((v6204 ^ -1) | (-(v6204 ^ -1))) >> 31)) & 2)) - (v6205 + ((~(((v6206 ^ -1) | (-(v6206 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v6226[v6326] = v6223;
      int * v6228 = v6162->cache_tags;
      int v6329 = (int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1);
      v6228[v6305] = v6329;
      int * v6230 = v6162->cache_dirty;
      v6230[v6305] = 0;
      int * v6232 = v6162->cache_age;
      v6232[v6305] = 1;
      int * v6234 = v6162->cache_age;
      int v6235 = v6234[v6305];
      int v6236 = v6234[v6279];
      int v6335 = v6236 + ((int)((unsigned int)(v6236 - v6235) >> 31));
      v6234[v6279] = v6335;
      int * v6238 = v6162->cache_age;
      int v6239 = v6238[v6280];
      int v6337 = v6239 + ((int)((unsigned int)(v6239 - v6235) >> 31));
      v6238[v6280] = v6337;
      int * v6241 = v6162->cache_age;
      v6241[v6305] = 0;
      v6244 = v6305;
    }
    int * v6245 = v6162->cache_vals;
    int v6340 = v6244 * 2;
    int v6246 = v6245[v6340];
    int v6341 = (v6244 * 2) + 1;
    int v6247 = v6245[v6341];
    int v6342 = (((((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1)) & 1) * 2) + ((((v6186 + ((~(((v6188 ^ -1) | (-(v6188 ^ -1))) >> 31)) & 2)) - (v6189 + ((~(((v6190 ^ -1) | (-(v6190 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6245[v6342] = v6246;
    int * v6249 = v6162->cache_vals;
    int v6345 = ((((((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1)) & 1) * 2) + ((((v6186 + ((~(((v6188 ^ -1) | (-(v6188 ^ -1))) >> 31)) & 2)) - (v6189 + ((~(((v6190 ^ -1) | (-(v6190 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6249[v6345] = v6247;
    int * v6251 = v6162->cache_tags;
    int v6348 = ((((int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1)) & 1) * 2) + ((((v6186 + ((~(((v6188 ^ -1) | (-(v6188 ^ -1))) >> 31)) & 2)) - (v6189 + ((~(((v6190 ^ -1) | (-(v6190 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6349 = (int)((unsigned int)((int)((unsigned int)v6166 >> 2)) >> 1);
    v6251[v6348] = v6349;
    int * v6253 = v6162->cache_dirty;
    v6253[v6348] = 0;
    int * v6255 = v6162->cache_age;
    v6255[v6348] = 1;
    int * v6257 = v6162->cache_age;
    int v6258 = v6257[v6348];
    int v6259 = v6257[v6277];
    int v6355 = v6259 + ((int)((unsigned int)(v6259 - v6258) >> 31));
    v6257[v6277] = v6355;
    int * v6261 = v6162->cache_age;
    int v6262 = v6261[v6278];
    int v6357 = v6262 + ((int)((unsigned int)(v6262 - v6258) >> 31));
    v6261[v6278] = v6357;
    int * v6264 = v6162->cache_age;
    v6264[v6348] = 0;
    v6267 = v6348;
  }
  int v6360 = (v6267 * 2) + (((int)((unsigned int)v6166 >> 2)) & 1);
  int v6268 = v6174[v6360];
  int * v6269 = v6162->regs;
  v6269[13] = v6268;
  struct StateT * v6271 = slot_60(v6162);
  return v6271;
}

struct StateT * slot_40(struct StateT * v4404) {
  int v4405 = v4404->timer;
  int v4412 = v4405 + 1;
  v4404->timer = v4412;
  int * v4407 = v4404->regs;
  int v4408 = v4407[11];
  int v4416 = v4408 + 20;
  v4407[13] = v4416;
  struct StateT * v4410 = slot_41(v4404);
  return v4410;
}

struct StateT * slot_27(struct StateT * v3485) {
  int v3486 = v3485->timer;
  int v3490 = v3486 + 1;
  v3485->timer = v3490;
  struct StateT * v3488 = slot_29(v3485);
  return v3488;
}

struct StateT * slot_15(struct StateT * v2909) {
  int v2910 = v2909->timer;
  int v2914 = v2910 + 1;
  v2909->timer = v2914;
  struct StateT * v2912 = slot_23(v2909);
  return v2912;
}

struct StateT * slot_62(struct StateT * v6722) {
  int v6723 = v6722->timer;
  int v6730 = v6723 + 1;
  v6722->timer = v6730;
  int * v6725 = v6722->regs;
  int v6726 = v6725[10];
  int v6734 = v6726 + 36;
  v6725[11] = v6734;
  struct StateT * v6728 = slot_63(v6722);
  return v6728;
}

struct StateT * slot_48(struct StateT * v5221) {
  int v5222 = v5221->timer;
  int v5392 = v5222 + 1;
  v5221->timer = v5392;
  int * v5224 = v5221->regs;
  int v5225 = v5224[10];
  int v5226 = v5224[13];
  int * v5227 = v5221->cache_tags;
  int v5397 = (((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1)) & 1) * 2;
  int v5228 = v5227[v5397];
  int v5398 = ((((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1)) & 1) * 2) + 1;
  int v5229 = v5227[v5398];
  int v5399 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1)) & 3) * 2);
  int v5230 = v5227[v5399];
  int v5400 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5231 = v5227[v5400];
  int v5232 = v5221->timer;
  int v5401 = v5232 + ((100 ^ (((~(((v5230 ^ ((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1))) | (-(v5230 ^ ((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v5231 ^ ((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1))) | (-(v5231 ^ ((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5228 ^ ((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1))) | (-(v5228 ^ ((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v5229 ^ ((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1))) | (-(v5229 ^ ((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5230 ^ ((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1))) | (-(v5230 ^ ((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v5231 ^ ((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1))) | (-(v5231 ^ ((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1))))) >> 31))) & 104)))));
  v5221->timer = v5401;
  bool v5402 = !(((~(((v5228 ^ ((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1))) | (-(v5228 ^ ((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v5229 ^ ((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1))) | (-(v5229 ^ ((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v5326;
  if (v5402) {
    int * v5234 = v5221->cache_age;
    int v5404 = ((((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1)) & 1) * 2) + ((~(((v5229 ^ ((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1))) | (-(v5229 ^ ((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v5235 = v5234[v5404];
    int v5236 = v5234[v5397];
    int v5405 = v5236 + ((int)((unsigned int)(v5236 - v5235) >> 31));
    v5234[v5397] = v5405;
    int * v5238 = v5221->cache_age;
    int v5239 = v5238[v5398];
    int v5407 = v5239 + ((int)((unsigned int)(v5239 - v5235) >> 31));
    v5238[v5398] = v5407;
    int * v5241 = v5221->cache_age;
    v5241[v5404] = 0;
    v5326 = v5404;
  } else {
    int * v5244 = v5221->cache_age;
    int v5411 = (((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1)) & 1) * 2;
    int v5245 = v5244[v5411];
    int * v5246 = v5221->cache_tags;
    int v5247 = v5246[v5411];
    int v5248 = v5244[v5398];
    int v5249 = v5246[v5398];
    bool v5413 = !(((~(((v5230 ^ ((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1))) | (-(v5230 ^ ((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v5231 ^ ((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1))) | (-(v5231 ^ ((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1))))) >> 31))) == 0);
    int v5303;
    if (v5413) {
      int * v5250 = v5221->cache_age;
      int v5415 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5231 ^ ((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1))) | (-(v5231 ^ ((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1))))) >> 31)) & 1);
      int v5251 = v5250[v5415];
      int v5252 = v5250[v5399];
      int v5416 = v5252 + ((int)((unsigned int)(v5252 - v5251) >> 31));
      v5250[v5399] = v5416;
      int * v5254 = v5221->cache_age;
      int v5255 = v5254[v5400];
      int v5418 = v5255 + ((int)((unsigned int)(v5255 - v5251) >> 31));
      v5254[v5400] = v5418;
      int * v5257 = v5221->cache_age;
      v5257[v5415] = 0;
      v5303 = v5415;
    } else {
      int * v5260 = v5221->cache_age;
      int v5422 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1)) & 3) * 2);
      int v5261 = v5260[v5422];
      int * v5262 = v5221->cache_tags;
      int v5263 = v5262[v5422];
      int v5264 = v5260[v5400];
      int v5265 = v5262[v5400];
      int * v5266 = v5221->cache_dirty;
      int v5425 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5261 + ((~(((v5263 ^ -1) | (-(v5263 ^ -1))) >> 31)) & 2)) - (v5264 + ((~(((v5265 ^ -1) | (-(v5265 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5267 = v5266[v5425];
      bool v5426 = !(v5267 == 0);
      if (v5426) {
        int * v5268 = v5221->cache_tags;
        int v5269 = v5268[v5425];
        int * v5270 = v5221->cache_vals;
        int v5429 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5261 + ((~(((v5263 ^ -1) | (-(v5263 ^ -1))) >> 31)) & 2)) - (v5264 + ((~(((v5265 ^ -1) | (-(v5265 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5271 = v5270[v5429];
        int v5430 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5261 + ((~(((v5263 ^ -1) | (-(v5263 ^ -1))) >> 31)) & 2)) - (v5264 + ((~(((v5265 ^ -1) | (-(v5265 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5272 = v5270[v5430];
        int * v5273 = v5221->mem;
        int v5432 = v5269 * 2;
        v5273[v5432] = v5271;
        int * v5275 = v5221->mem;
        int v5435 = (v5269 * 2) + 1;
        v5275[v5435] = v5272;
        ;
      } else {
        ;
      }
      int * v5280 = v5221->mem;
      int v5440 = ((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1)) * 2;
      int v5281 = v5280[v5440];
      int v5441 = (((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1)) * 2) + 1;
      int v5282 = v5280[v5441];
      int * v5283 = v5221->cache_vals;
      int v5443 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5261 + ((~(((v5263 ^ -1) | (-(v5263 ^ -1))) >> 31)) & 2)) - (v5264 + ((~(((v5265 ^ -1) | (-(v5265 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5283[v5443] = v5281;
      int * v5285 = v5221->cache_vals;
      int v5446 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5261 + ((~(((v5263 ^ -1) | (-(v5263 ^ -1))) >> 31)) & 2)) - (v5264 + ((~(((v5265 ^ -1) | (-(v5265 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5285[v5446] = v5282;
      int * v5287 = v5221->cache_tags;
      int v5449 = (int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1);
      v5287[v5425] = v5449;
      int * v5289 = v5221->cache_dirty;
      v5289[v5425] = 0;
      int * v5291 = v5221->cache_age;
      v5291[v5425] = 1;
      int * v5293 = v5221->cache_age;
      int v5294 = v5293[v5425];
      int v5295 = v5293[v5399];
      int v5455 = v5295 + ((int)((unsigned int)(v5295 - v5294) >> 31));
      v5293[v5399] = v5455;
      int * v5297 = v5221->cache_age;
      int v5298 = v5297[v5400];
      int v5457 = v5298 + ((int)((unsigned int)(v5298 - v5294) >> 31));
      v5297[v5400] = v5457;
      int * v5300 = v5221->cache_age;
      v5300[v5425] = 0;
      v5303 = v5425;
    }
    int * v5304 = v5221->cache_vals;
    int v5460 = v5303 * 2;
    int v5305 = v5304[v5460];
    int v5461 = (v5303 * 2) + 1;
    int v5306 = v5304[v5461];
    int v5462 = (((((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v5245 + ((~(((v5247 ^ -1) | (-(v5247 ^ -1))) >> 31)) & 2)) - (v5248 + ((~(((v5249 ^ -1) | (-(v5249 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5304[v5462] = v5305;
    int * v5308 = v5221->cache_vals;
    int v5465 = ((((((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v5245 + ((~(((v5247 ^ -1) | (-(v5247 ^ -1))) >> 31)) & 2)) - (v5248 + ((~(((v5249 ^ -1) | (-(v5249 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5308[v5465] = v5306;
    int * v5310 = v5221->cache_tags;
    int v5468 = ((((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v5245 + ((~(((v5247 ^ -1) | (-(v5247 ^ -1))) >> 31)) & 2)) - (v5248 + ((~(((v5249 ^ -1) | (-(v5249 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5469 = (int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1);
    v5310[v5468] = v5469;
    int * v5312 = v5221->cache_dirty;
    v5312[v5468] = 0;
    int * v5314 = v5221->cache_age;
    v5314[v5468] = 1;
    int * v5316 = v5221->cache_age;
    int v5317 = v5316[v5468];
    int v5318 = v5316[v5397];
    int v5475 = v5318 + ((int)((unsigned int)(v5318 - v5317) >> 31));
    v5316[v5397] = v5475;
    int * v5320 = v5221->cache_age;
    int v5321 = v5320[v5398];
    int v5477 = v5321 + ((int)((unsigned int)(v5321 - v5317) >> 31));
    v5320[v5398] = v5477;
    int * v5323 = v5221->cache_age;
    v5323[v5468] = 0;
    v5326 = v5468;
  }
  int * v5327 = v5221->cache_vals;
  int v5480 = (v5326 * 2) + (((int)((unsigned int)(v5225 + 24) >> 2)) & 1);
  v5327[v5480] = v5226;
  int * v5329 = v5221->cache_tags;
  int v5330 = v5329[v5399];
  int v5331 = v5329[v5400];
  bool v5483 = !(((~(((v5330 ^ ((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1))) | (-(v5330 ^ ((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v5331 ^ ((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1))) | (-(v5331 ^ ((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v5385;
  if (v5483) {
    int * v5332 = v5221->cache_age;
    int v5485 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5331 ^ ((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1))) | (-(v5331 ^ ((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v5333 = v5332[v5485];
    int v5334 = v5332[v5399];
    int v5486 = v5334 + ((int)((unsigned int)(v5334 - v5333) >> 31));
    v5332[v5399] = v5486;
    int * v5336 = v5221->cache_age;
    int v5337 = v5336[v5400];
    int v5488 = v5337 + ((int)((unsigned int)(v5337 - v5333) >> 31));
    v5336[v5400] = v5488;
    int * v5339 = v5221->cache_age;
    v5339[v5485] = 0;
    v5385 = v5485;
  } else {
    int * v5342 = v5221->cache_age;
    int v5492 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1)) & 3) * 2);
    int v5343 = v5342[v5492];
    int * v5344 = v5221->cache_tags;
    int v5345 = v5344[v5492];
    int v5346 = v5342[v5400];
    int v5347 = v5344[v5400];
    int * v5348 = v5221->cache_dirty;
    int v5495 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5343 + ((~(((v5345 ^ -1) | (-(v5345 ^ -1))) >> 31)) & 2)) - (v5346 + ((~(((v5347 ^ -1) | (-(v5347 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5349 = v5348[v5495];
    bool v5496 = !(v5349 == 0);
    if (v5496) {
      int * v5350 = v5221->cache_tags;
      int v5351 = v5350[v5495];
      int * v5352 = v5221->cache_vals;
      int v5499 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5343 + ((~(((v5345 ^ -1) | (-(v5345 ^ -1))) >> 31)) & 2)) - (v5346 + ((~(((v5347 ^ -1) | (-(v5347 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v5353 = v5352[v5499];
      int v5500 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5343 + ((~(((v5345 ^ -1) | (-(v5345 ^ -1))) >> 31)) & 2)) - (v5346 + ((~(((v5347 ^ -1) | (-(v5347 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v5354 = v5352[v5500];
      int * v5355 = v5221->mem;
      int v5502 = v5351 * 2;
      v5355[v5502] = v5353;
      int * v5357 = v5221->mem;
      int v5505 = (v5351 * 2) + 1;
      v5357[v5505] = v5354;
      ;
    } else {
      ;
    }
    int * v5362 = v5221->mem;
    int v5510 = ((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1)) * 2;
    int v5363 = v5362[v5510];
    int v5511 = (((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1)) * 2) + 1;
    int v5364 = v5362[v5511];
    int * v5365 = v5221->cache_vals;
    int v5513 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5343 + ((~(((v5345 ^ -1) | (-(v5345 ^ -1))) >> 31)) & 2)) - (v5346 + ((~(((v5347 ^ -1) | (-(v5347 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5365[v5513] = v5363;
    int * v5367 = v5221->cache_vals;
    int v5516 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v5343 + ((~(((v5345 ^ -1) | (-(v5345 ^ -1))) >> 31)) & 2)) - (v5346 + ((~(((v5347 ^ -1) | (-(v5347 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5367[v5516] = v5364;
    int * v5369 = v5221->cache_tags;
    int v5519 = (int)((unsigned int)((int)((unsigned int)(v5225 + 24) >> 2)) >> 1);
    v5369[v5495] = v5519;
    int * v5371 = v5221->cache_dirty;
    v5371[v5495] = 0;
    int * v5373 = v5221->cache_age;
    v5373[v5495] = 1;
    int * v5375 = v5221->cache_age;
    int v5376 = v5375[v5495];
    int v5377 = v5375[v5399];
    int v5525 = v5377 + ((int)((unsigned int)(v5377 - v5376) >> 31));
    v5375[v5399] = v5525;
    int * v5379 = v5221->cache_age;
    int v5380 = v5379[v5400];
    int v5527 = v5380 + ((int)((unsigned int)(v5380 - v5376) >> 31));
    v5379[v5400] = v5527;
    int * v5382 = v5221->cache_age;
    v5382[v5495] = 0;
    v5385 = v5495;
  }
  int * v5386 = v5221->cache_vals;
  int v5530 = (v5385 * 2) + (((int)((unsigned int)(v5225 + 24) >> 2)) & 1);
  v5386[v5530] = v5226;
  int * v5388 = v5221->cache_dirty;
  v5388[v5385] = 1;
  struct StateT * v5390 = slot_49(v5221);
  return v5390;
}

struct StateT * slot_22(struct StateT * v2676) {
  int v2677 = v2676->timer;
  int v2684 = v2677 + 1;
  v2676->timer = v2684;
  int * v2679 = v2676->regs;
  int v2680 = v2679[11];
  int v2688 = v2680 + 8;
  v2679[13] = v2688;
  struct StateT * v2682 = slot_23(v2676);
  return v2682;
}

struct StateT * slot_35(struct StateT * v3858) {
  int v3859 = v3858->timer;
  int v3969 = v3859 + 1;
  v3858->timer = v3969;
  int * v3861 = v3858->regs;
  int v3862 = v3861[13];
  int * v3863 = v3858->cache_tags;
  int v3973 = (((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1)) & 1) * 2;
  int v3864 = v3863[v3973];
  int v3974 = ((((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1)) & 1) * 2) + 1;
  int v3865 = v3863[v3974];
  int v3975 = 4 + ((((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1)) & 3) * 2);
  int v3866 = v3863[v3975];
  int v3976 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3867 = v3863[v3976];
  int v3868 = v3858->timer;
  int v3977 = v3868 + ((100 ^ (((~(((v3866 ^ ((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1))) | (-(v3866 ^ ((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1))))) >> 31)) | (~(((v3867 ^ ((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1))) | (-(v3867 ^ ((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3864 ^ ((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1))) | (-(v3864 ^ ((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1))))) >> 31)) | (~(((v3865 ^ ((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1))) | (-(v3865 ^ ((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3866 ^ ((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1))) | (-(v3866 ^ ((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1))))) >> 31)) | (~(((v3867 ^ ((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1))) | (-(v3867 ^ ((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1))))) >> 31))) & 104)))));
  v3858->timer = v3977;
  int * v3870 = v3858->cache_vals;
  bool v3978 = !(((~(((v3864 ^ ((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1))) | (-(v3864 ^ ((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1))))) >> 31)) | (~(((v3865 ^ ((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1))) | (-(v3865 ^ ((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1))))) >> 31))) == 0);
  int v3963;
  if (v3978) {
    int * v3871 = v3858->cache_age;
    int v3980 = ((((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1)) & 1) * 2) + ((~(((v3865 ^ ((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1))) | (-(v3865 ^ ((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1))))) >> 31)) & 1);
    int v3872 = v3871[v3980];
    int v3873 = v3871[v3973];
    int v3981 = v3873 + ((int)((unsigned int)(v3873 - v3872) >> 31));
    v3871[v3973] = v3981;
    int * v3875 = v3858->cache_age;
    int v3876 = v3875[v3974];
    int v3983 = v3876 + ((int)((unsigned int)(v3876 - v3872) >> 31));
    v3875[v3974] = v3983;
    int * v3878 = v3858->cache_age;
    v3878[v3980] = 0;
    v3963 = v3980;
  } else {
    int * v3881 = v3858->cache_age;
    int v3987 = (((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1)) & 1) * 2;
    int v3882 = v3881[v3987];
    int * v3883 = v3858->cache_tags;
    int v3884 = v3883[v3987];
    int v3885 = v3881[v3974];
    int v3886 = v3883[v3974];
    bool v3989 = !(((~(((v3866 ^ ((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1))) | (-(v3866 ^ ((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1))))) >> 31)) | (~(((v3867 ^ ((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1))) | (-(v3867 ^ ((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1))))) >> 31))) == 0);
    int v3940;
    if (v3989) {
      int * v3887 = v3858->cache_age;
      int v3991 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1)) & 3) * 2)) + ((~(((v3867 ^ ((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1))) | (-(v3867 ^ ((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1))))) >> 31)) & 1);
      int v3888 = v3887[v3991];
      int v3889 = v3887[v3975];
      int v3992 = v3889 + ((int)((unsigned int)(v3889 - v3888) >> 31));
      v3887[v3975] = v3992;
      int * v3891 = v3858->cache_age;
      int v3892 = v3891[v3976];
      int v3994 = v3892 + ((int)((unsigned int)(v3892 - v3888) >> 31));
      v3891[v3976] = v3994;
      int * v3894 = v3858->cache_age;
      v3894[v3991] = 0;
      v3940 = v3991;
    } else {
      int * v3897 = v3858->cache_age;
      int v3998 = 4 + ((((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1)) & 3) * 2);
      int v3898 = v3897[v3998];
      int * v3899 = v3858->cache_tags;
      int v3900 = v3899[v3998];
      int v3901 = v3897[v3976];
      int v3902 = v3899[v3976];
      int * v3903 = v3858->cache_dirty;
      int v4001 = (4 + ((((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1)) & 3) * 2)) + ((((v3898 + ((~(((v3900 ^ -1) | (-(v3900 ^ -1))) >> 31)) & 2)) - (v3901 + ((~(((v3902 ^ -1) | (-(v3902 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3904 = v3903[v4001];
      bool v4002 = !(v3904 == 0);
      if (v4002) {
        int * v3905 = v3858->cache_tags;
        int v3906 = v3905[v4001];
        int * v3907 = v3858->cache_vals;
        int v4005 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1)) & 3) * 2)) + ((((v3898 + ((~(((v3900 ^ -1) | (-(v3900 ^ -1))) >> 31)) & 2)) - (v3901 + ((~(((v3902 ^ -1) | (-(v3902 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3908 = v3907[v4005];
        int v4006 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1)) & 3) * 2)) + ((((v3898 + ((~(((v3900 ^ -1) | (-(v3900 ^ -1))) >> 31)) & 2)) - (v3901 + ((~(((v3902 ^ -1) | (-(v3902 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3909 = v3907[v4006];
        int * v3910 = v3858->mem;
        int v4008 = v3906 * 2;
        v3910[v4008] = v3908;
        int * v3912 = v3858->mem;
        int v4011 = (v3906 * 2) + 1;
        v3912[v4011] = v3909;
        ;
      } else {
        ;
      }
      int * v3917 = v3858->mem;
      int v4016 = ((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1)) * 2;
      int v3918 = v3917[v4016];
      int v4017 = (((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1)) * 2) + 1;
      int v3919 = v3917[v4017];
      int * v3920 = v3858->cache_vals;
      int v4019 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1)) & 3) * 2)) + ((((v3898 + ((~(((v3900 ^ -1) | (-(v3900 ^ -1))) >> 31)) & 2)) - (v3901 + ((~(((v3902 ^ -1) | (-(v3902 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3920[v4019] = v3918;
      int * v3922 = v3858->cache_vals;
      int v4022 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1)) & 3) * 2)) + ((((v3898 + ((~(((v3900 ^ -1) | (-(v3900 ^ -1))) >> 31)) & 2)) - (v3901 + ((~(((v3902 ^ -1) | (-(v3902 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3922[v4022] = v3919;
      int * v3924 = v3858->cache_tags;
      int v4025 = (int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1);
      v3924[v4001] = v4025;
      int * v3926 = v3858->cache_dirty;
      v3926[v4001] = 0;
      int * v3928 = v3858->cache_age;
      v3928[v4001] = 1;
      int * v3930 = v3858->cache_age;
      int v3931 = v3930[v4001];
      int v3932 = v3930[v3975];
      int v4031 = v3932 + ((int)((unsigned int)(v3932 - v3931) >> 31));
      v3930[v3975] = v4031;
      int * v3934 = v3858->cache_age;
      int v3935 = v3934[v3976];
      int v4033 = v3935 + ((int)((unsigned int)(v3935 - v3931) >> 31));
      v3934[v3976] = v4033;
      int * v3937 = v3858->cache_age;
      v3937[v4001] = 0;
      v3940 = v4001;
    }
    int * v3941 = v3858->cache_vals;
    int v4036 = v3940 * 2;
    int v3942 = v3941[v4036];
    int v4037 = (v3940 * 2) + 1;
    int v3943 = v3941[v4037];
    int v4038 = (((((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1)) & 1) * 2) + ((((v3882 + ((~(((v3884 ^ -1) | (-(v3884 ^ -1))) >> 31)) & 2)) - (v3885 + ((~(((v3886 ^ -1) | (-(v3886 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3941[v4038] = v3942;
    int * v3945 = v3858->cache_vals;
    int v4041 = ((((((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1)) & 1) * 2) + ((((v3882 + ((~(((v3884 ^ -1) | (-(v3884 ^ -1))) >> 31)) & 2)) - (v3885 + ((~(((v3886 ^ -1) | (-(v3886 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3945[v4041] = v3943;
    int * v3947 = v3858->cache_tags;
    int v4044 = ((((int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1)) & 1) * 2) + ((((v3882 + ((~(((v3884 ^ -1) | (-(v3884 ^ -1))) >> 31)) & 2)) - (v3885 + ((~(((v3886 ^ -1) | (-(v3886 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4045 = (int)((unsigned int)((int)((unsigned int)v3862 >> 2)) >> 1);
    v3947[v4044] = v4045;
    int * v3949 = v3858->cache_dirty;
    v3949[v4044] = 0;
    int * v3951 = v3858->cache_age;
    v3951[v4044] = 1;
    int * v3953 = v3858->cache_age;
    int v3954 = v3953[v4044];
    int v3955 = v3953[v3973];
    int v4051 = v3955 + ((int)((unsigned int)(v3955 - v3954) >> 31));
    v3953[v3973] = v4051;
    int * v3957 = v3858->cache_age;
    int v3958 = v3957[v3974];
    int v4053 = v3958 + ((int)((unsigned int)(v3958 - v3954) >> 31));
    v3957[v3974] = v4053;
    int * v3960 = v3858->cache_age;
    v3960[v4044] = 0;
    v3963 = v4044;
  }
  int v4056 = (v3963 * 2) + (((int)((unsigned int)v3862 >> 2)) & 1);
  int v3964 = v3870[v4056];
  int * v3965 = v3858->regs;
  v3965[13] = v3964;
  struct StateT * v3967 = slot_36(v3858);
  return v3967;
}

struct StateT * slot_56(struct StateT * v6147) {
  int v6148 = v6147->timer;
  int v6155 = v6148 + 1;
  v6147->timer = v6155;
  int * v6150 = v6147->regs;
  int v6151 = v6150[10];
  int v6159 = v6151 + 32;
  v6150[13] = v6159;
  struct StateT * v6153 = slot_57(v6147);
  return v6153;
}

struct StateT * slot_34(struct StateT * v3828) {
  int v3829 = v3828->timer;
  int v3836 = v3829 + 1;
  v3828->timer = v3836;
  int * v3831 = v3828->regs;
  int v3832 = v3831[11];
  int v3840 = v3832 + 16;
  v3831[13] = v3840;
  struct StateT * v3834 = slot_35(v3828);
  return v3834;
}

struct StateT * slot_51(struct StateT * v5789) {
  int v5790 = v5789->timer;
  int v5794 = v5790 + 1;
  v5789->timer = v5794;
  struct StateT * v5792 = slot_53(v5789);
  return v5792;
}

struct StateT * slot_52(struct StateT * v5556) {
  int v5557 = v5556->timer;
  int v5564 = v5557 + 1;
  v5556->timer = v5564;
  int * v5559 = v5556->regs;
  int v5560 = v5559[11];
  int v5568 = v5560 + 28;
  v5559[13] = v5568;
  struct StateT * v5562 = slot_53(v5556);
  return v5562;
}

struct StateT * slot_25(struct StateT * v3232) {
  int v3233 = v3232->timer;
  int v3243 = v3233 + 1;
  v3232->timer = v3243;
  int * v3235 = v3232->regs;
  int v3236 = v3235[12];
  bool v3246 = !(v3236 == 0);
  struct StateT * v3241;
  if (v3246) {
    struct StateT * v3237 = slot_28(v3232);
    v3241 = v3237;
  } else {
    struct StateT * v3239 = slot_26(v3232);
    v3241 = v3239;
  }
  return v3241;
}

struct StateT * slot_23(struct StateT * v2706) {
  int v2707 = v2706->timer;
  int v2817 = v2707 + 1;
  v2706->timer = v2817;
  int * v2709 = v2706->regs;
  int v2710 = v2709[13];
  int * v2711 = v2706->cache_tags;
  int v2821 = (((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1)) & 1) * 2;
  int v2712 = v2711[v2821];
  int v2822 = ((((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1)) & 1) * 2) + 1;
  int v2713 = v2711[v2822];
  int v2823 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1)) & 3) * 2);
  int v2714 = v2711[v2823];
  int v2824 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2715 = v2711[v2824];
  int v2716 = v2706->timer;
  int v2825 = v2716 + ((100 ^ (((~(((v2714 ^ ((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1))) | (-(v2714 ^ ((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1))))) >> 31)) | (~(((v2715 ^ ((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1))) | (-(v2715 ^ ((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2712 ^ ((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1))) | (-(v2712 ^ ((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1))))) >> 31)) | (~(((v2713 ^ ((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1))) | (-(v2713 ^ ((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2714 ^ ((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1))) | (-(v2714 ^ ((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1))))) >> 31)) | (~(((v2715 ^ ((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1))) | (-(v2715 ^ ((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2706->timer = v2825;
  int * v2718 = v2706->cache_vals;
  bool v2826 = !(((~(((v2712 ^ ((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1))) | (-(v2712 ^ ((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1))))) >> 31)) | (~(((v2713 ^ ((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1))) | (-(v2713 ^ ((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1))))) >> 31))) == 0);
  int v2811;
  if (v2826) {
    int * v2719 = v2706->cache_age;
    int v2828 = ((((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1)) & 1) * 2) + ((~(((v2713 ^ ((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1))) | (-(v2713 ^ ((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1))))) >> 31)) & 1);
    int v2720 = v2719[v2828];
    int v2721 = v2719[v2821];
    int v2829 = v2721 + ((int)((unsigned int)(v2721 - v2720) >> 31));
    v2719[v2821] = v2829;
    int * v2723 = v2706->cache_age;
    int v2724 = v2723[v2822];
    int v2831 = v2724 + ((int)((unsigned int)(v2724 - v2720) >> 31));
    v2723[v2822] = v2831;
    int * v2726 = v2706->cache_age;
    v2726[v2828] = 0;
    v2811 = v2828;
  } else {
    int * v2729 = v2706->cache_age;
    int v2835 = (((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1)) & 1) * 2;
    int v2730 = v2729[v2835];
    int * v2731 = v2706->cache_tags;
    int v2732 = v2731[v2835];
    int v2733 = v2729[v2822];
    int v2734 = v2731[v2822];
    bool v2837 = !(((~(((v2714 ^ ((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1))) | (-(v2714 ^ ((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1))))) >> 31)) | (~(((v2715 ^ ((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1))) | (-(v2715 ^ ((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1))))) >> 31))) == 0);
    int v2788;
    if (v2837) {
      int * v2735 = v2706->cache_age;
      int v2839 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2715 ^ ((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1))) | (-(v2715 ^ ((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1))))) >> 31)) & 1);
      int v2736 = v2735[v2839];
      int v2737 = v2735[v2823];
      int v2840 = v2737 + ((int)((unsigned int)(v2737 - v2736) >> 31));
      v2735[v2823] = v2840;
      int * v2739 = v2706->cache_age;
      int v2740 = v2739[v2824];
      int v2842 = v2740 + ((int)((unsigned int)(v2740 - v2736) >> 31));
      v2739[v2824] = v2842;
      int * v2742 = v2706->cache_age;
      v2742[v2839] = 0;
      v2788 = v2839;
    } else {
      int * v2745 = v2706->cache_age;
      int v2846 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1)) & 3) * 2);
      int v2746 = v2745[v2846];
      int * v2747 = v2706->cache_tags;
      int v2748 = v2747[v2846];
      int v2749 = v2745[v2824];
      int v2750 = v2747[v2824];
      int * v2751 = v2706->cache_dirty;
      int v2849 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1)) & 3) * 2)) + ((((v2746 + ((~(((v2748 ^ -1) | (-(v2748 ^ -1))) >> 31)) & 2)) - (v2749 + ((~(((v2750 ^ -1) | (-(v2750 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2752 = v2751[v2849];
      bool v2850 = !(v2752 == 0);
      if (v2850) {
        int * v2753 = v2706->cache_tags;
        int v2754 = v2753[v2849];
        int * v2755 = v2706->cache_vals;
        int v2853 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1)) & 3) * 2)) + ((((v2746 + ((~(((v2748 ^ -1) | (-(v2748 ^ -1))) >> 31)) & 2)) - (v2749 + ((~(((v2750 ^ -1) | (-(v2750 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2756 = v2755[v2853];
        int v2854 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1)) & 3) * 2)) + ((((v2746 + ((~(((v2748 ^ -1) | (-(v2748 ^ -1))) >> 31)) & 2)) - (v2749 + ((~(((v2750 ^ -1) | (-(v2750 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2757 = v2755[v2854];
        int * v2758 = v2706->mem;
        int v2856 = v2754 * 2;
        v2758[v2856] = v2756;
        int * v2760 = v2706->mem;
        int v2859 = (v2754 * 2) + 1;
        v2760[v2859] = v2757;
        ;
      } else {
        ;
      }
      int * v2765 = v2706->mem;
      int v2864 = ((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1)) * 2;
      int v2766 = v2765[v2864];
      int v2865 = (((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1)) * 2) + 1;
      int v2767 = v2765[v2865];
      int * v2768 = v2706->cache_vals;
      int v2867 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1)) & 3) * 2)) + ((((v2746 + ((~(((v2748 ^ -1) | (-(v2748 ^ -1))) >> 31)) & 2)) - (v2749 + ((~(((v2750 ^ -1) | (-(v2750 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2768[v2867] = v2766;
      int * v2770 = v2706->cache_vals;
      int v2870 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1)) & 3) * 2)) + ((((v2746 + ((~(((v2748 ^ -1) | (-(v2748 ^ -1))) >> 31)) & 2)) - (v2749 + ((~(((v2750 ^ -1) | (-(v2750 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2770[v2870] = v2767;
      int * v2772 = v2706->cache_tags;
      int v2873 = (int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1);
      v2772[v2849] = v2873;
      int * v2774 = v2706->cache_dirty;
      v2774[v2849] = 0;
      int * v2776 = v2706->cache_age;
      v2776[v2849] = 1;
      int * v2778 = v2706->cache_age;
      int v2779 = v2778[v2849];
      int v2780 = v2778[v2823];
      int v2879 = v2780 + ((int)((unsigned int)(v2780 - v2779) >> 31));
      v2778[v2823] = v2879;
      int * v2782 = v2706->cache_age;
      int v2783 = v2782[v2824];
      int v2881 = v2783 + ((int)((unsigned int)(v2783 - v2779) >> 31));
      v2782[v2824] = v2881;
      int * v2785 = v2706->cache_age;
      v2785[v2849] = 0;
      v2788 = v2849;
    }
    int * v2789 = v2706->cache_vals;
    int v2884 = v2788 * 2;
    int v2790 = v2789[v2884];
    int v2885 = (v2788 * 2) + 1;
    int v2791 = v2789[v2885];
    int v2886 = (((((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1)) & 1) * 2) + ((((v2730 + ((~(((v2732 ^ -1) | (-(v2732 ^ -1))) >> 31)) & 2)) - (v2733 + ((~(((v2734 ^ -1) | (-(v2734 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2789[v2886] = v2790;
    int * v2793 = v2706->cache_vals;
    int v2889 = ((((((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1)) & 1) * 2) + ((((v2730 + ((~(((v2732 ^ -1) | (-(v2732 ^ -1))) >> 31)) & 2)) - (v2733 + ((~(((v2734 ^ -1) | (-(v2734 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2793[v2889] = v2791;
    int * v2795 = v2706->cache_tags;
    int v2892 = ((((int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1)) & 1) * 2) + ((((v2730 + ((~(((v2732 ^ -1) | (-(v2732 ^ -1))) >> 31)) & 2)) - (v2733 + ((~(((v2734 ^ -1) | (-(v2734 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2893 = (int)((unsigned int)((int)((unsigned int)v2710 >> 2)) >> 1);
    v2795[v2892] = v2893;
    int * v2797 = v2706->cache_dirty;
    v2797[v2892] = 0;
    int * v2799 = v2706->cache_age;
    v2799[v2892] = 1;
    int * v2801 = v2706->cache_age;
    int v2802 = v2801[v2892];
    int v2803 = v2801[v2821];
    int v2899 = v2803 + ((int)((unsigned int)(v2803 - v2802) >> 31));
    v2801[v2821] = v2899;
    int * v2805 = v2706->cache_age;
    int v2806 = v2805[v2822];
    int v2901 = v2806 + ((int)((unsigned int)(v2806 - v2802) >> 31));
    v2805[v2822] = v2901;
    int * v2808 = v2706->cache_age;
    v2808[v2892] = 0;
    v2811 = v2892;
  }
  int v2904 = (v2811 * 2) + (((int)((unsigned int)v2710 >> 2)) & 1);
  int v2812 = v2718[v2904];
  int * v2813 = v2706->regs;
  v2813[13] = v2812;
  struct StateT * v2815 = slot_24(v2706);
  return v2815;
}

struct StateT * slot_2(struct StateT * v409) {
  int v410 = v409->timer;
  int v520 = v410 + 1;
  v409->timer = v520;
  int * v412 = v409->regs;
  int v413 = v412[10];
  int * v414 = v409->cache_tags;
  int v524 = (((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1)) & 1) * 2;
  int v415 = v414[v524];
  int v525 = ((((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v416 = v414[v525];
  int v526 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1)) & 3) * 2);
  int v417 = v414[v526];
  int v527 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v418 = v414[v527];
  int v419 = v409->timer;
  int v528 = v419 + ((100 ^ (((~(((v417 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))) | (-(v417 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v418 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))) | (-(v418 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v415 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))) | (-(v415 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v416 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))) | (-(v416 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v417 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))) | (-(v417 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v418 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))) | (-(v418 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v409->timer = v528;
  int * v421 = v409->cache_vals;
  bool v529 = !(((~(((v415 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))) | (-(v415 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v416 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))) | (-(v416 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v514;
  if (v529) {
    int * v422 = v409->cache_age;
    int v531 = ((((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v416 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))) | (-(v416 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v423 = v422[v531];
    int v424 = v422[v524];
    int v532 = v424 + ((int)((unsigned int)(v424 - v423) >> 31));
    v422[v524] = v532;
    int * v426 = v409->cache_age;
    int v427 = v426[v525];
    int v534 = v427 + ((int)((unsigned int)(v427 - v423) >> 31));
    v426[v525] = v534;
    int * v429 = v409->cache_age;
    v429[v531] = 0;
    v514 = v531;
  } else {
    int * v432 = v409->cache_age;
    int v538 = (((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1)) & 1) * 2;
    int v433 = v432[v538];
    int * v434 = v409->cache_tags;
    int v435 = v434[v538];
    int v436 = v432[v525];
    int v437 = v434[v525];
    bool v540 = !(((~(((v417 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))) | (-(v417 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v418 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))) | (-(v418 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v491;
    if (v540) {
      int * v438 = v409->cache_age;
      int v542 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v418 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))) | (-(v418 ^ ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v439 = v438[v542];
      int v440 = v438[v526];
      int v543 = v440 + ((int)((unsigned int)(v440 - v439) >> 31));
      v438[v526] = v543;
      int * v442 = v409->cache_age;
      int v443 = v442[v527];
      int v545 = v443 + ((int)((unsigned int)(v443 - v439) >> 31));
      v442[v527] = v545;
      int * v445 = v409->cache_age;
      v445[v542] = 0;
      v491 = v542;
    } else {
      int * v448 = v409->cache_age;
      int v549 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1)) & 3) * 2);
      int v449 = v448[v549];
      int * v450 = v409->cache_tags;
      int v451 = v450[v549];
      int v452 = v448[v527];
      int v453 = v450[v527];
      int * v454 = v409->cache_dirty;
      int v552 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v449 + ((~(((v451 ^ -1) | (-(v451 ^ -1))) >> 31)) & 2)) - (v452 + ((~(((v453 ^ -1) | (-(v453 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v455 = v454[v552];
      bool v553 = !(v455 == 0);
      if (v553) {
        int * v456 = v409->cache_tags;
        int v457 = v456[v552];
        int * v458 = v409->cache_vals;
        int v556 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v449 + ((~(((v451 ^ -1) | (-(v451 ^ -1))) >> 31)) & 2)) - (v452 + ((~(((v453 ^ -1) | (-(v453 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v459 = v458[v556];
        int v557 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v449 + ((~(((v451 ^ -1) | (-(v451 ^ -1))) >> 31)) & 2)) - (v452 + ((~(((v453 ^ -1) | (-(v453 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v460 = v458[v557];
        int * v461 = v409->mem;
        int v559 = v457 * 2;
        v461[v559] = v459;
        int * v463 = v409->mem;
        int v562 = (v457 * 2) + 1;
        v463[v562] = v460;
        ;
      } else {
        ;
      }
      int * v468 = v409->mem;
      int v567 = ((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1)) * 2;
      int v469 = v468[v567];
      int v568 = (((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1)) * 2) + 1;
      int v470 = v468[v568];
      int * v471 = v409->cache_vals;
      int v570 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v449 + ((~(((v451 ^ -1) | (-(v451 ^ -1))) >> 31)) & 2)) - (v452 + ((~(((v453 ^ -1) | (-(v453 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v471[v570] = v469;
      int * v473 = v409->cache_vals;
      int v573 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v449 + ((~(((v451 ^ -1) | (-(v451 ^ -1))) >> 31)) & 2)) - (v452 + ((~(((v453 ^ -1) | (-(v453 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v473[v573] = v470;
      int * v475 = v409->cache_tags;
      int v576 = (int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1);
      v475[v552] = v576;
      int * v477 = v409->cache_dirty;
      v477[v552] = 0;
      int * v479 = v409->cache_age;
      v479[v552] = 1;
      int * v481 = v409->cache_age;
      int v482 = v481[v552];
      int v483 = v481[v526];
      int v582 = v483 + ((int)((unsigned int)(v483 - v482) >> 31));
      v481[v526] = v582;
      int * v485 = v409->cache_age;
      int v486 = v485[v527];
      int v584 = v486 + ((int)((unsigned int)(v486 - v482) >> 31));
      v485[v527] = v584;
      int * v488 = v409->cache_age;
      v488[v552] = 0;
      v491 = v552;
    }
    int * v492 = v409->cache_vals;
    int v587 = v491 * 2;
    int v493 = v492[v587];
    int v588 = (v491 * 2) + 1;
    int v494 = v492[v588];
    int v589 = (((((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v433 + ((~(((v435 ^ -1) | (-(v435 ^ -1))) >> 31)) & 2)) - (v436 + ((~(((v437 ^ -1) | (-(v437 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v492[v589] = v493;
    int * v496 = v409->cache_vals;
    int v592 = ((((((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v433 + ((~(((v435 ^ -1) | (-(v435 ^ -1))) >> 31)) & 2)) - (v436 + ((~(((v437 ^ -1) | (-(v437 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v496[v592] = v494;
    int * v498 = v409->cache_tags;
    int v595 = ((((int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v433 + ((~(((v435 ^ -1) | (-(v435 ^ -1))) >> 31)) & 2)) - (v436 + ((~(((v437 ^ -1) | (-(v437 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v596 = (int)((unsigned int)((int)((unsigned int)(v413 + 4) >> 2)) >> 1);
    v498[v595] = v596;
    int * v500 = v409->cache_dirty;
    v500[v595] = 0;
    int * v502 = v409->cache_age;
    v502[v595] = 1;
    int * v504 = v409->cache_age;
    int v505 = v504[v595];
    int v506 = v504[v524];
    int v602 = v506 + ((int)((unsigned int)(v506 - v505) >> 31));
    v504[v524] = v602;
    int * v508 = v409->cache_age;
    int v509 = v508[v525];
    int v604 = v509 + ((int)((unsigned int)(v509 - v505) >> 31));
    v508[v525] = v604;
    int * v511 = v409->cache_age;
    v511[v595] = 0;
    v514 = v595;
  }
  int v607 = (v514 * 2) + (((int)((unsigned int)(v413 + 4) >> 2)) & 1);
  int v515 = v421[v607];
  int * v516 = v409->regs;
  v516[14] = v515;
  struct StateT * v518 = slot_3(v409);
  return v518;
}

struct StateT * slot_21(struct StateT * v2656) {
  int v2657 = v2656->timer;
  int v2667 = v2657 + 1;
  v2656->timer = v2667;
  int * v2659 = v2656->regs;
  int v2660 = v2659[12];
  bool v2670 = v2660 == 0;
  struct StateT * v2665;
  if (v2670) {
    struct StateT * v2661 = slot_14(v2656);
    v2665 = v2661;
  } else {
    struct StateT * v2663 = slot_22(v2656);
    v2665 = v2663;
  }
  return v2665;
}

struct StateT * slot_3(struct StateT * v613) {
  int v614 = v613->timer;
  int v724 = v614 + 1;
  v613->timer = v724;
  int * v616 = v613->regs;
  int v617 = v616[13];
  int * v618 = v613->cache_tags;
  int v728 = (((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1)) & 1) * 2;
  int v619 = v618[v728];
  int v729 = ((((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v620 = v618[v729];
  int v730 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1)) & 3) * 2);
  int v621 = v618[v730];
  int v731 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v622 = v618[v731];
  int v623 = v613->timer;
  int v732 = v623 + ((100 ^ (((~(((v621 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))) | (-(v621 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v622 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))) | (-(v622 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v619 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))) | (-(v619 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v620 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))) | (-(v620 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v621 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))) | (-(v621 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v622 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))) | (-(v622 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v613->timer = v732;
  int * v625 = v613->cache_vals;
  bool v733 = !(((~(((v619 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))) | (-(v619 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v620 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))) | (-(v620 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v718;
  if (v733) {
    int * v626 = v613->cache_age;
    int v735 = ((((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v620 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))) | (-(v620 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v627 = v626[v735];
    int v628 = v626[v728];
    int v736 = v628 + ((int)((unsigned int)(v628 - v627) >> 31));
    v626[v728] = v736;
    int * v630 = v613->cache_age;
    int v631 = v630[v729];
    int v738 = v631 + ((int)((unsigned int)(v631 - v627) >> 31));
    v630[v729] = v738;
    int * v633 = v613->cache_age;
    v633[v735] = 0;
    v718 = v735;
  } else {
    int * v636 = v613->cache_age;
    int v742 = (((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1)) & 1) * 2;
    int v637 = v636[v742];
    int * v638 = v613->cache_tags;
    int v639 = v638[v742];
    int v640 = v636[v729];
    int v641 = v638[v729];
    bool v744 = !(((~(((v621 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))) | (-(v621 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v622 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))) | (-(v622 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v695;
    if (v744) {
      int * v642 = v613->cache_age;
      int v746 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v622 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))) | (-(v622 ^ ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v643 = v642[v746];
      int v644 = v642[v730];
      int v747 = v644 + ((int)((unsigned int)(v644 - v643) >> 31));
      v642[v730] = v747;
      int * v646 = v613->cache_age;
      int v647 = v646[v731];
      int v749 = v647 + ((int)((unsigned int)(v647 - v643) >> 31));
      v646[v731] = v749;
      int * v649 = v613->cache_age;
      v649[v746] = 0;
      v695 = v746;
    } else {
      int * v652 = v613->cache_age;
      int v753 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1)) & 3) * 2);
      int v653 = v652[v753];
      int * v654 = v613->cache_tags;
      int v655 = v654[v753];
      int v656 = v652[v731];
      int v657 = v654[v731];
      int * v658 = v613->cache_dirty;
      int v756 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v653 + ((~(((v655 ^ -1) | (-(v655 ^ -1))) >> 31)) & 2)) - (v656 + ((~(((v657 ^ -1) | (-(v657 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v659 = v658[v756];
      bool v757 = !(v659 == 0);
      if (v757) {
        int * v660 = v613->cache_tags;
        int v661 = v660[v756];
        int * v662 = v613->cache_vals;
        int v760 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v653 + ((~(((v655 ^ -1) | (-(v655 ^ -1))) >> 31)) & 2)) - (v656 + ((~(((v657 ^ -1) | (-(v657 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v663 = v662[v760];
        int v761 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v653 + ((~(((v655 ^ -1) | (-(v655 ^ -1))) >> 31)) & 2)) - (v656 + ((~(((v657 ^ -1) | (-(v657 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v664 = v662[v761];
        int * v665 = v613->mem;
        int v763 = v661 * 2;
        v665[v763] = v663;
        int * v667 = v613->mem;
        int v766 = (v661 * 2) + 1;
        v667[v766] = v664;
        ;
      } else {
        ;
      }
      int * v672 = v613->mem;
      int v771 = ((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1)) * 2;
      int v673 = v672[v771];
      int v772 = (((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1)) * 2) + 1;
      int v674 = v672[v772];
      int * v675 = v613->cache_vals;
      int v774 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v653 + ((~(((v655 ^ -1) | (-(v655 ^ -1))) >> 31)) & 2)) - (v656 + ((~(((v657 ^ -1) | (-(v657 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v675[v774] = v673;
      int * v677 = v613->cache_vals;
      int v777 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v653 + ((~(((v655 ^ -1) | (-(v655 ^ -1))) >> 31)) & 2)) - (v656 + ((~(((v657 ^ -1) | (-(v657 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v677[v777] = v674;
      int * v679 = v613->cache_tags;
      int v780 = (int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1);
      v679[v756] = v780;
      int * v681 = v613->cache_dirty;
      v681[v756] = 0;
      int * v683 = v613->cache_age;
      v683[v756] = 1;
      int * v685 = v613->cache_age;
      int v686 = v685[v756];
      int v687 = v685[v730];
      int v786 = v687 + ((int)((unsigned int)(v687 - v686) >> 31));
      v685[v730] = v786;
      int * v689 = v613->cache_age;
      int v690 = v689[v731];
      int v788 = v690 + ((int)((unsigned int)(v690 - v686) >> 31));
      v689[v731] = v788;
      int * v692 = v613->cache_age;
      v692[v756] = 0;
      v695 = v756;
    }
    int * v696 = v613->cache_vals;
    int v791 = v695 * 2;
    int v697 = v696[v791];
    int v792 = (v695 * 2) + 1;
    int v698 = v696[v792];
    int v793 = (((((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v637 + ((~(((v639 ^ -1) | (-(v639 ^ -1))) >> 31)) & 2)) - (v640 + ((~(((v641 ^ -1) | (-(v641 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v696[v793] = v697;
    int * v700 = v613->cache_vals;
    int v796 = ((((((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v637 + ((~(((v639 ^ -1) | (-(v639 ^ -1))) >> 31)) & 2)) - (v640 + ((~(((v641 ^ -1) | (-(v641 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v700[v796] = v698;
    int * v702 = v613->cache_tags;
    int v799 = ((((int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v637 + ((~(((v639 ^ -1) | (-(v639 ^ -1))) >> 31)) & 2)) - (v640 + ((~(((v641 ^ -1) | (-(v641 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v800 = (int)((unsigned int)((int)((unsigned int)(v617 + 4) >> 2)) >> 1);
    v702[v799] = v800;
    int * v704 = v613->cache_dirty;
    v704[v799] = 0;
    int * v706 = v613->cache_age;
    v706[v799] = 1;
    int * v708 = v613->cache_age;
    int v709 = v708[v799];
    int v710 = v708[v728];
    int v806 = v710 + ((int)((unsigned int)(v710 - v709) >> 31));
    v708[v728] = v806;
    int * v712 = v613->cache_age;
    int v713 = v712[v729];
    int v808 = v713 + ((int)((unsigned int)(v713 - v709) >> 31));
    v712[v729] = v808;
    int * v715 = v613->cache_age;
    v715[v799] = 0;
    v718 = v799;
  }
  int v811 = (v718 * 2) + (((int)((unsigned int)(v617 + 4) >> 2)) & 1);
  int v719 = v625[v811];
  int * v720 = v613->regs;
  v720[13] = v719;
  struct StateT * v722 = slot_4(v613);
  return v722;
}

struct StateT * slot_45(struct StateT * v5213) {
  int v5214 = v5213->timer;
  int v5218 = v5214 + 1;
  v5213->timer = v5218;
  struct StateT * v5216 = slot_47(v5213);
  return v5216;
}

struct StateT * slot_1(struct StateT * v205) {
  int v206 = v205->timer;
  int v316 = v206 + 1;
  v205->timer = v316;
  int * v208 = v205->regs;
  int v209 = v208[10];
  int * v210 = v205->cache_tags;
  int v320 = (((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1)) & 1) * 2;
  int v211 = v210[v320];
  int v321 = ((((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1)) & 1) * 2) + 1;
  int v212 = v210[v321];
  int v322 = 4 + ((((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1)) & 3) * 2);
  int v213 = v210[v322];
  int v323 = (4 + ((((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v214 = v210[v323];
  int v215 = v205->timer;
  int v324 = v215 + ((100 ^ (((~(((v213 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))) | (-(v213 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))))) >> 31)) | (~(((v214 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))) | (-(v214 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v211 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))) | (-(v211 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))))) >> 31)) | (~(((v212 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))) | (-(v212 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v213 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))) | (-(v213 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))))) >> 31)) | (~(((v214 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))) | (-(v214 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))))) >> 31))) & 104)))));
  v205->timer = v324;
  int * v217 = v205->cache_vals;
  bool v325 = !(((~(((v211 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))) | (-(v211 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))))) >> 31)) | (~(((v212 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))) | (-(v212 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))))) >> 31))) == 0);
  int v310;
  if (v325) {
    int * v218 = v205->cache_age;
    int v327 = ((((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1)) & 1) * 2) + ((~(((v212 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))) | (-(v212 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))))) >> 31)) & 1);
    int v219 = v218[v327];
    int v220 = v218[v320];
    int v328 = v220 + ((int)((unsigned int)(v220 - v219) >> 31));
    v218[v320] = v328;
    int * v222 = v205->cache_age;
    int v223 = v222[v321];
    int v330 = v223 + ((int)((unsigned int)(v223 - v219) >> 31));
    v222[v321] = v330;
    int * v225 = v205->cache_age;
    v225[v327] = 0;
    v310 = v327;
  } else {
    int * v228 = v205->cache_age;
    int v334 = (((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1)) & 1) * 2;
    int v229 = v228[v334];
    int * v230 = v205->cache_tags;
    int v231 = v230[v334];
    int v232 = v228[v321];
    int v233 = v230[v321];
    bool v336 = !(((~(((v213 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))) | (-(v213 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))))) >> 31)) | (~(((v214 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))) | (-(v214 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))))) >> 31))) == 0);
    int v287;
    if (v336) {
      int * v234 = v205->cache_age;
      int v338 = (4 + ((((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1)) & 3) * 2)) + ((~(((v214 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))) | (-(v214 ^ ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1))))) >> 31)) & 1);
      int v235 = v234[v338];
      int v236 = v234[v322];
      int v339 = v236 + ((int)((unsigned int)(v236 - v235) >> 31));
      v234[v322] = v339;
      int * v238 = v205->cache_age;
      int v239 = v238[v323];
      int v341 = v239 + ((int)((unsigned int)(v239 - v235) >> 31));
      v238[v323] = v341;
      int * v241 = v205->cache_age;
      v241[v338] = 0;
      v287 = v338;
    } else {
      int * v244 = v205->cache_age;
      int v345 = 4 + ((((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1)) & 3) * 2);
      int v245 = v244[v345];
      int * v246 = v205->cache_tags;
      int v247 = v246[v345];
      int v248 = v244[v323];
      int v249 = v246[v323];
      int * v250 = v205->cache_dirty;
      int v348 = (4 + ((((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1)) & 3) * 2)) + ((((v245 + ((~(((v247 ^ -1) | (-(v247 ^ -1))) >> 31)) & 2)) - (v248 + ((~(((v249 ^ -1) | (-(v249 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v251 = v250[v348];
      bool v349 = !(v251 == 0);
      if (v349) {
        int * v252 = v205->cache_tags;
        int v253 = v252[v348];
        int * v254 = v205->cache_vals;
        int v352 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1)) & 3) * 2)) + ((((v245 + ((~(((v247 ^ -1) | (-(v247 ^ -1))) >> 31)) & 2)) - (v248 + ((~(((v249 ^ -1) | (-(v249 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v255 = v254[v352];
        int v353 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1)) & 3) * 2)) + ((((v245 + ((~(((v247 ^ -1) | (-(v247 ^ -1))) >> 31)) & 2)) - (v248 + ((~(((v249 ^ -1) | (-(v249 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v256 = v254[v353];
        int * v257 = v205->mem;
        int v355 = v253 * 2;
        v257[v355] = v255;
        int * v259 = v205->mem;
        int v358 = (v253 * 2) + 1;
        v259[v358] = v256;
        ;
      } else {
        ;
      }
      int * v264 = v205->mem;
      int v363 = ((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1)) * 2;
      int v265 = v264[v363];
      int v364 = (((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1)) * 2) + 1;
      int v266 = v264[v364];
      int * v267 = v205->cache_vals;
      int v366 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1)) & 3) * 2)) + ((((v245 + ((~(((v247 ^ -1) | (-(v247 ^ -1))) >> 31)) & 2)) - (v248 + ((~(((v249 ^ -1) | (-(v249 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v267[v366] = v265;
      int * v269 = v205->cache_vals;
      int v369 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1)) & 3) * 2)) + ((((v245 + ((~(((v247 ^ -1) | (-(v247 ^ -1))) >> 31)) & 2)) - (v248 + ((~(((v249 ^ -1) | (-(v249 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v269[v369] = v266;
      int * v271 = v205->cache_tags;
      int v372 = (int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1);
      v271[v348] = v372;
      int * v273 = v205->cache_dirty;
      v273[v348] = 0;
      int * v275 = v205->cache_age;
      v275[v348] = 1;
      int * v277 = v205->cache_age;
      int v278 = v277[v348];
      int v279 = v277[v322];
      int v378 = v279 + ((int)((unsigned int)(v279 - v278) >> 31));
      v277[v322] = v378;
      int * v281 = v205->cache_age;
      int v282 = v281[v323];
      int v380 = v282 + ((int)((unsigned int)(v282 - v278) >> 31));
      v281[v323] = v380;
      int * v284 = v205->cache_age;
      v284[v348] = 0;
      v287 = v348;
    }
    int * v288 = v205->cache_vals;
    int v383 = v287 * 2;
    int v289 = v288[v383];
    int v384 = (v287 * 2) + 1;
    int v290 = v288[v384];
    int v385 = (((((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1)) & 1) * 2) + ((((v229 + ((~(((v231 ^ -1) | (-(v231 ^ -1))) >> 31)) & 2)) - (v232 + ((~(((v233 ^ -1) | (-(v233 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v288[v385] = v289;
    int * v292 = v205->cache_vals;
    int v388 = ((((((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1)) & 1) * 2) + ((((v229 + ((~(((v231 ^ -1) | (-(v231 ^ -1))) >> 31)) & 2)) - (v232 + ((~(((v233 ^ -1) | (-(v233 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v292[v388] = v290;
    int * v294 = v205->cache_tags;
    int v391 = ((((int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1)) & 1) * 2) + ((((v229 + ((~(((v231 ^ -1) | (-(v231 ^ -1))) >> 31)) & 2)) - (v232 + ((~(((v233 ^ -1) | (-(v233 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v392 = (int)((unsigned int)((int)((unsigned int)v209 >> 2)) >> 1);
    v294[v391] = v392;
    int * v296 = v205->cache_dirty;
    v296[v391] = 0;
    int * v298 = v205->cache_age;
    v298[v391] = 1;
    int * v300 = v205->cache_age;
    int v301 = v300[v391];
    int v302 = v300[v320];
    int v398 = v302 + ((int)((unsigned int)(v302 - v301) >> 31));
    v300[v320] = v398;
    int * v304 = v205->cache_age;
    int v305 = v304[v321];
    int v400 = v305 + ((int)((unsigned int)(v305 - v301) >> 31));
    v304[v321] = v400;
    int * v307 = v205->cache_age;
    v307[v391] = 0;
    v310 = v391;
  }
  int v403 = (v310 * 2) + (((int)((unsigned int)v209 >> 2)) & 1);
  int v311 = v217[v403];
  int * v312 = v205->regs;
  v312[15] = v311;
  struct StateT * v314 = slot_2(v205);
  return v314;
}

struct StateT * slot_13(struct StateT * v2636) {
  int v2637 = v2636->timer;
  int v2647 = v2637 + 1;
  v2636->timer = v2647;
  int * v2639 = v2636->regs;
  int v2640 = v2639[12];
  bool v2650 = !(v2640 == 0);
  struct StateT * v2645;
  if (v2650) {
    struct StateT * v2641 = slot_22(v2636);
    v2645 = v2641;
  } else {
    struct StateT * v2643 = slot_14(v2636);
    v2645 = v2643;
  }
  return v2645;
}

struct StateT * slot_38(struct StateT * v4419) {
  int v4420 = v4419->timer;
  int v4427 = v4420 + 1;
  v4419->timer = v4427;
  int * v4422 = v4419->regs;
  int v4423 = v4422[10];
  int v4431 = v4423 + 20;
  v4422[13] = v4431;
  struct StateT * v4425 = slot_39(v4419);
  return v4425;
}

struct StateT * slot_63(struct StateT * v6940) {
  int v6941 = v6940->timer;
  int v6945 = v6941 + 1;
  v6940->timer = v6945;
  struct StateT * v6943 = slot_65(v6940);
  return v6943;
}

struct StateT * slot_24(struct StateT * v2917) {
  int v2918 = v2917->timer;
  int v3088 = v2918 + 1;
  v2917->timer = v3088;
  int * v2920 = v2917->regs;
  int v2921 = v2920[10];
  int v2922 = v2920[13];
  int * v2923 = v2917->cache_tags;
  int v3093 = (((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1)) & 1) * 2;
  int v2924 = v2923[v3093];
  int v3094 = ((((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2925 = v2923[v3094];
  int v3095 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1)) & 3) * 2);
  int v2926 = v2923[v3095];
  int v3096 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2927 = v2923[v3096];
  int v2928 = v2917->timer;
  int v3097 = v2928 + ((100 ^ (((~(((v2926 ^ ((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1))) | (-(v2926 ^ ((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2927 ^ ((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1))) | (-(v2927 ^ ((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2924 ^ ((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1))) | (-(v2924 ^ ((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2925 ^ ((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1))) | (-(v2925 ^ ((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2926 ^ ((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1))) | (-(v2926 ^ ((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2927 ^ ((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1))) | (-(v2927 ^ ((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2917->timer = v3097;
  bool v3098 = !(((~(((v2924 ^ ((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1))) | (-(v2924 ^ ((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2925 ^ ((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1))) | (-(v2925 ^ ((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v3022;
  if (v3098) {
    int * v2930 = v2917->cache_age;
    int v3100 = ((((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v2925 ^ ((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1))) | (-(v2925 ^ ((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v2931 = v2930[v3100];
    int v2932 = v2930[v3093];
    int v3101 = v2932 + ((int)((unsigned int)(v2932 - v2931) >> 31));
    v2930[v3093] = v3101;
    int * v2934 = v2917->cache_age;
    int v2935 = v2934[v3094];
    int v3103 = v2935 + ((int)((unsigned int)(v2935 - v2931) >> 31));
    v2934[v3094] = v3103;
    int * v2937 = v2917->cache_age;
    v2937[v3100] = 0;
    v3022 = v3100;
  } else {
    int * v2940 = v2917->cache_age;
    int v3107 = (((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1)) & 1) * 2;
    int v2941 = v2940[v3107];
    int * v2942 = v2917->cache_tags;
    int v2943 = v2942[v3107];
    int v2944 = v2940[v3094];
    int v2945 = v2942[v3094];
    bool v3109 = !(((~(((v2926 ^ ((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1))) | (-(v2926 ^ ((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v2927 ^ ((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1))) | (-(v2927 ^ ((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v2999;
    if (v3109) {
      int * v2946 = v2917->cache_age;
      int v3111 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2927 ^ ((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1))) | (-(v2927 ^ ((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v2947 = v2946[v3111];
      int v2948 = v2946[v3095];
      int v3112 = v2948 + ((int)((unsigned int)(v2948 - v2947) >> 31));
      v2946[v3095] = v3112;
      int * v2950 = v2917->cache_age;
      int v2951 = v2950[v3096];
      int v3114 = v2951 + ((int)((unsigned int)(v2951 - v2947) >> 31));
      v2950[v3096] = v3114;
      int * v2953 = v2917->cache_age;
      v2953[v3111] = 0;
      v2999 = v3111;
    } else {
      int * v2956 = v2917->cache_age;
      int v3118 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1)) & 3) * 2);
      int v2957 = v2956[v3118];
      int * v2958 = v2917->cache_tags;
      int v2959 = v2958[v3118];
      int v2960 = v2956[v3096];
      int v2961 = v2958[v3096];
      int * v2962 = v2917->cache_dirty;
      int v3121 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2957 + ((~(((v2959 ^ -1) | (-(v2959 ^ -1))) >> 31)) & 2)) - (v2960 + ((~(((v2961 ^ -1) | (-(v2961 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2963 = v2962[v3121];
      bool v3122 = !(v2963 == 0);
      if (v3122) {
        int * v2964 = v2917->cache_tags;
        int v2965 = v2964[v3121];
        int * v2966 = v2917->cache_vals;
        int v3125 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2957 + ((~(((v2959 ^ -1) | (-(v2959 ^ -1))) >> 31)) & 2)) - (v2960 + ((~(((v2961 ^ -1) | (-(v2961 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2967 = v2966[v3125];
        int v3126 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2957 + ((~(((v2959 ^ -1) | (-(v2959 ^ -1))) >> 31)) & 2)) - (v2960 + ((~(((v2961 ^ -1) | (-(v2961 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2968 = v2966[v3126];
        int * v2969 = v2917->mem;
        int v3128 = v2965 * 2;
        v2969[v3128] = v2967;
        int * v2971 = v2917->mem;
        int v3131 = (v2965 * 2) + 1;
        v2971[v3131] = v2968;
        ;
      } else {
        ;
      }
      int * v2976 = v2917->mem;
      int v3136 = ((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1)) * 2;
      int v2977 = v2976[v3136];
      int v3137 = (((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1)) * 2) + 1;
      int v2978 = v2976[v3137];
      int * v2979 = v2917->cache_vals;
      int v3139 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2957 + ((~(((v2959 ^ -1) | (-(v2959 ^ -1))) >> 31)) & 2)) - (v2960 + ((~(((v2961 ^ -1) | (-(v2961 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2979[v3139] = v2977;
      int * v2981 = v2917->cache_vals;
      int v3142 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v2957 + ((~(((v2959 ^ -1) | (-(v2959 ^ -1))) >> 31)) & 2)) - (v2960 + ((~(((v2961 ^ -1) | (-(v2961 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2981[v3142] = v2978;
      int * v2983 = v2917->cache_tags;
      int v3145 = (int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1);
      v2983[v3121] = v3145;
      int * v2985 = v2917->cache_dirty;
      v2985[v3121] = 0;
      int * v2987 = v2917->cache_age;
      v2987[v3121] = 1;
      int * v2989 = v2917->cache_age;
      int v2990 = v2989[v3121];
      int v2991 = v2989[v3095];
      int v3151 = v2991 + ((int)((unsigned int)(v2991 - v2990) >> 31));
      v2989[v3095] = v3151;
      int * v2993 = v2917->cache_age;
      int v2994 = v2993[v3096];
      int v3153 = v2994 + ((int)((unsigned int)(v2994 - v2990) >> 31));
      v2993[v3096] = v3153;
      int * v2996 = v2917->cache_age;
      v2996[v3121] = 0;
      v2999 = v3121;
    }
    int * v3000 = v2917->cache_vals;
    int v3156 = v2999 * 2;
    int v3001 = v3000[v3156];
    int v3157 = (v2999 * 2) + 1;
    int v3002 = v3000[v3157];
    int v3158 = (((((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v2941 + ((~(((v2943 ^ -1) | (-(v2943 ^ -1))) >> 31)) & 2)) - (v2944 + ((~(((v2945 ^ -1) | (-(v2945 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3000[v3158] = v3001;
    int * v3004 = v2917->cache_vals;
    int v3161 = ((((((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v2941 + ((~(((v2943 ^ -1) | (-(v2943 ^ -1))) >> 31)) & 2)) - (v2944 + ((~(((v2945 ^ -1) | (-(v2945 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3004[v3161] = v3002;
    int * v3006 = v2917->cache_tags;
    int v3164 = ((((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v2941 + ((~(((v2943 ^ -1) | (-(v2943 ^ -1))) >> 31)) & 2)) - (v2944 + ((~(((v2945 ^ -1) | (-(v2945 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3165 = (int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1);
    v3006[v3164] = v3165;
    int * v3008 = v2917->cache_dirty;
    v3008[v3164] = 0;
    int * v3010 = v2917->cache_age;
    v3010[v3164] = 1;
    int * v3012 = v2917->cache_age;
    int v3013 = v3012[v3164];
    int v3014 = v3012[v3093];
    int v3171 = v3014 + ((int)((unsigned int)(v3014 - v3013) >> 31));
    v3012[v3093] = v3171;
    int * v3016 = v2917->cache_age;
    int v3017 = v3016[v3094];
    int v3173 = v3017 + ((int)((unsigned int)(v3017 - v3013) >> 31));
    v3016[v3094] = v3173;
    int * v3019 = v2917->cache_age;
    v3019[v3164] = 0;
    v3022 = v3164;
  }
  int * v3023 = v2917->cache_vals;
  int v3176 = (v3022 * 2) + (((int)((unsigned int)(v2921 + 8) >> 2)) & 1);
  v3023[v3176] = v2922;
  int * v3025 = v2917->cache_tags;
  int v3026 = v3025[v3095];
  int v3027 = v3025[v3096];
  bool v3179 = !(((~(((v3026 ^ ((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1))) | (-(v3026 ^ ((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3027 ^ ((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1))) | (-(v3027 ^ ((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v3081;
  if (v3179) {
    int * v3028 = v2917->cache_age;
    int v3181 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3027 ^ ((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1))) | (-(v3027 ^ ((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v3029 = v3028[v3181];
    int v3030 = v3028[v3095];
    int v3182 = v3030 + ((int)((unsigned int)(v3030 - v3029) >> 31));
    v3028[v3095] = v3182;
    int * v3032 = v2917->cache_age;
    int v3033 = v3032[v3096];
    int v3184 = v3033 + ((int)((unsigned int)(v3033 - v3029) >> 31));
    v3032[v3096] = v3184;
    int * v3035 = v2917->cache_age;
    v3035[v3181] = 0;
    v3081 = v3181;
  } else {
    int * v3038 = v2917->cache_age;
    int v3188 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1)) & 3) * 2);
    int v3039 = v3038[v3188];
    int * v3040 = v2917->cache_tags;
    int v3041 = v3040[v3188];
    int v3042 = v3038[v3096];
    int v3043 = v3040[v3096];
    int * v3044 = v2917->cache_dirty;
    int v3191 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3039 + ((~(((v3041 ^ -1) | (-(v3041 ^ -1))) >> 31)) & 2)) - (v3042 + ((~(((v3043 ^ -1) | (-(v3043 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3045 = v3044[v3191];
    bool v3192 = !(v3045 == 0);
    if (v3192) {
      int * v3046 = v2917->cache_tags;
      int v3047 = v3046[v3191];
      int * v3048 = v2917->cache_vals;
      int v3195 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3039 + ((~(((v3041 ^ -1) | (-(v3041 ^ -1))) >> 31)) & 2)) - (v3042 + ((~(((v3043 ^ -1) | (-(v3043 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v3049 = v3048[v3195];
      int v3196 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3039 + ((~(((v3041 ^ -1) | (-(v3041 ^ -1))) >> 31)) & 2)) - (v3042 + ((~(((v3043 ^ -1) | (-(v3043 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v3050 = v3048[v3196];
      int * v3051 = v2917->mem;
      int v3198 = v3047 * 2;
      v3051[v3198] = v3049;
      int * v3053 = v2917->mem;
      int v3201 = (v3047 * 2) + 1;
      v3053[v3201] = v3050;
      ;
    } else {
      ;
    }
    int * v3058 = v2917->mem;
    int v3206 = ((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1)) * 2;
    int v3059 = v3058[v3206];
    int v3207 = (((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1)) * 2) + 1;
    int v3060 = v3058[v3207];
    int * v3061 = v2917->cache_vals;
    int v3209 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3039 + ((~(((v3041 ^ -1) | (-(v3041 ^ -1))) >> 31)) & 2)) - (v3042 + ((~(((v3043 ^ -1) | (-(v3043 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3061[v3209] = v3059;
    int * v3063 = v2917->cache_vals;
    int v3212 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3039 + ((~(((v3041 ^ -1) | (-(v3041 ^ -1))) >> 31)) & 2)) - (v3042 + ((~(((v3043 ^ -1) | (-(v3043 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3063[v3212] = v3060;
    int * v3065 = v2917->cache_tags;
    int v3215 = (int)((unsigned int)((int)((unsigned int)(v2921 + 8) >> 2)) >> 1);
    v3065[v3191] = v3215;
    int * v3067 = v2917->cache_dirty;
    v3067[v3191] = 0;
    int * v3069 = v2917->cache_age;
    v3069[v3191] = 1;
    int * v3071 = v2917->cache_age;
    int v3072 = v3071[v3191];
    int v3073 = v3071[v3095];
    int v3221 = v3073 + ((int)((unsigned int)(v3073 - v3072) >> 31));
    v3071[v3095] = v3221;
    int * v3075 = v2917->cache_age;
    int v3076 = v3075[v3096];
    int v3223 = v3076 + ((int)((unsigned int)(v3076 - v3072) >> 31));
    v3075[v3096] = v3223;
    int * v3078 = v2917->cache_age;
    v3078[v3191] = 0;
    v3081 = v3191;
  }
  int * v3082 = v2917->cache_vals;
  int v3226 = (v3081 * 2) + (((int)((unsigned int)(v2921 + 8) >> 2)) & 1);
  v3082[v3226] = v2922;
  int * v3084 = v2917->cache_dirty;
  v3084[v3081] = 1;
  struct StateT * v3086 = slot_25(v2917);
  return v3086;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v113 = v3 + 1;
  v2->timer = v113;
  int * v5 = v2->regs;
  int v6 = v5[12];
  int * v7 = v2->cache_tags;
  int v117 = (((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2;
  int v8 = v7[v117];
  int v118 = ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + 1;
  int v9 = v7[v118];
  int v119 = 4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2);
  int v10 = v7[v119];
  int v120 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v11 = v7[v120];
  int v12 = v2->timer;
  int v121 = v12 + ((100 ^ (((~(((v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v11 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v11 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v8 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v8 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v9 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v9 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v11 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v11 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2->timer = v121;
  int * v14 = v2->cache_vals;
  bool v122 = !(((~(((v8 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v8 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v9 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v9 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) == 0);
  int v107;
  if (v122) {
    int * v15 = v2->cache_age;
    int v124 = ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + ((~(((v9 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v9 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) & 1);
    int v16 = v15[v124];
    int v17 = v15[v117];
    int v125 = v17 + ((int)((unsigned int)(v17 - v16) >> 31));
    v15[v117] = v125;
    int * v19 = v2->cache_age;
    int v20 = v19[v118];
    int v127 = v20 + ((int)((unsigned int)(v20 - v16) >> 31));
    v19[v118] = v127;
    int * v22 = v2->cache_age;
    v22[v124] = 0;
    v107 = v124;
  } else {
    int * v25 = v2->cache_age;
    int v131 = (((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2;
    int v26 = v25[v131];
    int * v27 = v2->cache_tags;
    int v28 = v27[v131];
    int v29 = v25[v118];
    int v30 = v27[v118];
    bool v133 = !(((~(((v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v10 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) | (~(((v11 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v11 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31))) == 0);
    int v84;
    if (v133) {
      int * v31 = v2->cache_age;
      int v135 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((~(((v11 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))) | (-(v11 ^ ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1))))) >> 31)) & 1);
      int v32 = v31[v135];
      int v33 = v31[v119];
      int v136 = v33 + ((int)((unsigned int)(v33 - v32) >> 31));
      v31[v119] = v136;
      int * v35 = v2->cache_age;
      int v36 = v35[v120];
      int v138 = v36 + ((int)((unsigned int)(v36 - v32) >> 31));
      v35[v120] = v138;
      int * v38 = v2->cache_age;
      v38[v135] = 0;
      v84 = v135;
    } else {
      int * v41 = v2->cache_age;
      int v142 = 4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2);
      int v42 = v41[v142];
      int * v43 = v2->cache_tags;
      int v44 = v43[v142];
      int v45 = v41[v120];
      int v46 = v43[v120];
      int * v47 = v2->cache_dirty;
      int v145 = (4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v48 = v47[v145];
      bool v146 = !(v48 == 0);
      if (v146) {
        int * v49 = v2->cache_tags;
        int v50 = v49[v145];
        int * v51 = v2->cache_vals;
        int v149 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v52 = v51[v149];
        int v150 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v53 = v51[v150];
        int * v54 = v2->mem;
        int v152 = v50 * 2;
        v54[v152] = v52;
        int * v56 = v2->mem;
        int v155 = (v50 * 2) + 1;
        v56[v155] = v53;
        ;
      } else {
        ;
      }
      int * v61 = v2->mem;
      int v160 = ((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) * 2;
      int v62 = v61[v160];
      int v161 = (((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) * 2) + 1;
      int v63 = v61[v161];
      int * v64 = v2->cache_vals;
      int v163 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v64[v163] = v62;
      int * v66 = v2->cache_vals;
      int v166 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 3) * 2)) + ((((v42 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2)) - (v45 + ((~(((v46 ^ -1) | (-(v46 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v66[v166] = v63;
      int * v68 = v2->cache_tags;
      int v169 = (int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1);
      v68[v145] = v169;
      int * v70 = v2->cache_dirty;
      v70[v145] = 0;
      int * v72 = v2->cache_age;
      v72[v145] = 1;
      int * v74 = v2->cache_age;
      int v75 = v74[v145];
      int v76 = v74[v119];
      int v175 = v76 + ((int)((unsigned int)(v76 - v75) >> 31));
      v74[v119] = v175;
      int * v78 = v2->cache_age;
      int v79 = v78[v120];
      int v177 = v79 + ((int)((unsigned int)(v79 - v75) >> 31));
      v78[v120] = v177;
      int * v81 = v2->cache_age;
      v81[v145] = 0;
      v84 = v145;
    }
    int * v85 = v2->cache_vals;
    int v180 = v84 * 2;
    int v86 = v85[v180];
    int v181 = (v84 * 2) + 1;
    int v87 = v85[v181];
    int v182 = (((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + ((((v26 + ((~(((v28 ^ -1) | (-(v28 ^ -1))) >> 31)) & 2)) - (v29 + ((~(((v30 ^ -1) | (-(v30 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v85[v182] = v86;
    int * v89 = v2->cache_vals;
    int v185 = ((((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + ((((v26 + ((~(((v28 ^ -1) | (-(v28 ^ -1))) >> 31)) & 2)) - (v29 + ((~(((v30 ^ -1) | (-(v30 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v89[v185] = v87;
    int * v91 = v2->cache_tags;
    int v188 = ((((int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1)) & 1) * 2) + ((((v26 + ((~(((v28 ^ -1) | (-(v28 ^ -1))) >> 31)) & 2)) - (v29 + ((~(((v30 ^ -1) | (-(v30 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v189 = (int)((unsigned int)((int)((unsigned int)v6 >> 2)) >> 1);
    v91[v188] = v189;
    int * v93 = v2->cache_dirty;
    v93[v188] = 0;
    int * v95 = v2->cache_age;
    v95[v188] = 1;
    int * v97 = v2->cache_age;
    int v98 = v97[v188];
    int v99 = v97[v117];
    int v195 = v99 + ((int)((unsigned int)(v99 - v98) >> 31));
    v97[v117] = v195;
    int * v101 = v2->cache_age;
    int v102 = v101[v118];
    int v197 = v102 + ((int)((unsigned int)(v102 - v98) >> 31));
    v101[v118] = v197;
    int * v104 = v2->cache_age;
    v104[v188] = 0;
    v107 = v188;
  }
  int v200 = (v107 * 2) + (((int)((unsigned int)v6 >> 2)) & 1);
  int v108 = v14[v200];
  int * v109 = v2->regs;
  v109[12] = v108;
  struct StateT * v111 = slot_1(v2);
  return v111;
}

struct StateT * slot_42(struct StateT * v4645) {
  int v4646 = v4645->timer;
  int v4816 = v4646 + 1;
  v4645->timer = v4816;
  int * v4648 = v4645->regs;
  int v4649 = v4648[10];
  int v4650 = v4648[13];
  int * v4651 = v4645->cache_tags;
  int v4821 = (((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1)) & 1) * 2;
  int v4652 = v4651[v4821];
  int v4822 = ((((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4653 = v4651[v4822];
  int v4823 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1)) & 3) * 2);
  int v4654 = v4651[v4823];
  int v4824 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4655 = v4651[v4824];
  int v4656 = v4645->timer;
  int v4825 = v4656 + ((100 ^ (((~(((v4654 ^ ((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1))) | (-(v4654 ^ ((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v4655 ^ ((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1))) | (-(v4655 ^ ((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4652 ^ ((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1))) | (-(v4652 ^ ((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v4653 ^ ((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1))) | (-(v4653 ^ ((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4654 ^ ((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1))) | (-(v4654 ^ ((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v4655 ^ ((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1))) | (-(v4655 ^ ((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4645->timer = v4825;
  bool v4826 = !(((~(((v4652 ^ ((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1))) | (-(v4652 ^ ((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v4653 ^ ((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1))) | (-(v4653 ^ ((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v4750;
  if (v4826) {
    int * v4658 = v4645->cache_age;
    int v4828 = ((((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1)) & 1) * 2) + ((~(((v4653 ^ ((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1))) | (-(v4653 ^ ((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v4659 = v4658[v4828];
    int v4660 = v4658[v4821];
    int v4829 = v4660 + ((int)((unsigned int)(v4660 - v4659) >> 31));
    v4658[v4821] = v4829;
    int * v4662 = v4645->cache_age;
    int v4663 = v4662[v4822];
    int v4831 = v4663 + ((int)((unsigned int)(v4663 - v4659) >> 31));
    v4662[v4822] = v4831;
    int * v4665 = v4645->cache_age;
    v4665[v4828] = 0;
    v4750 = v4828;
  } else {
    int * v4668 = v4645->cache_age;
    int v4835 = (((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1)) & 1) * 2;
    int v4669 = v4668[v4835];
    int * v4670 = v4645->cache_tags;
    int v4671 = v4670[v4835];
    int v4672 = v4668[v4822];
    int v4673 = v4670[v4822];
    bool v4837 = !(((~(((v4654 ^ ((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1))) | (-(v4654 ^ ((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v4655 ^ ((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1))) | (-(v4655 ^ ((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1))))) >> 31))) == 0);
    int v4727;
    if (v4837) {
      int * v4674 = v4645->cache_age;
      int v4839 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4655 ^ ((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1))) | (-(v4655 ^ ((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1))))) >> 31)) & 1);
      int v4675 = v4674[v4839];
      int v4676 = v4674[v4823];
      int v4840 = v4676 + ((int)((unsigned int)(v4676 - v4675) >> 31));
      v4674[v4823] = v4840;
      int * v4678 = v4645->cache_age;
      int v4679 = v4678[v4824];
      int v4842 = v4679 + ((int)((unsigned int)(v4679 - v4675) >> 31));
      v4678[v4824] = v4842;
      int * v4681 = v4645->cache_age;
      v4681[v4839] = 0;
      v4727 = v4839;
    } else {
      int * v4684 = v4645->cache_age;
      int v4846 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1)) & 3) * 2);
      int v4685 = v4684[v4846];
      int * v4686 = v4645->cache_tags;
      int v4687 = v4686[v4846];
      int v4688 = v4684[v4824];
      int v4689 = v4686[v4824];
      int * v4690 = v4645->cache_dirty;
      int v4849 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v4685 + ((~(((v4687 ^ -1) | (-(v4687 ^ -1))) >> 31)) & 2)) - (v4688 + ((~(((v4689 ^ -1) | (-(v4689 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4691 = v4690[v4849];
      bool v4850 = !(v4691 == 0);
      if (v4850) {
        int * v4692 = v4645->cache_tags;
        int v4693 = v4692[v4849];
        int * v4694 = v4645->cache_vals;
        int v4853 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v4685 + ((~(((v4687 ^ -1) | (-(v4687 ^ -1))) >> 31)) & 2)) - (v4688 + ((~(((v4689 ^ -1) | (-(v4689 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4695 = v4694[v4853];
        int v4854 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v4685 + ((~(((v4687 ^ -1) | (-(v4687 ^ -1))) >> 31)) & 2)) - (v4688 + ((~(((v4689 ^ -1) | (-(v4689 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4696 = v4694[v4854];
        int * v4697 = v4645->mem;
        int v4856 = v4693 * 2;
        v4697[v4856] = v4695;
        int * v4699 = v4645->mem;
        int v4859 = (v4693 * 2) + 1;
        v4699[v4859] = v4696;
        ;
      } else {
        ;
      }
      int * v4704 = v4645->mem;
      int v4864 = ((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1)) * 2;
      int v4705 = v4704[v4864];
      int v4865 = (((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1)) * 2) + 1;
      int v4706 = v4704[v4865];
      int * v4707 = v4645->cache_vals;
      int v4867 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v4685 + ((~(((v4687 ^ -1) | (-(v4687 ^ -1))) >> 31)) & 2)) - (v4688 + ((~(((v4689 ^ -1) | (-(v4689 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4707[v4867] = v4705;
      int * v4709 = v4645->cache_vals;
      int v4870 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v4685 + ((~(((v4687 ^ -1) | (-(v4687 ^ -1))) >> 31)) & 2)) - (v4688 + ((~(((v4689 ^ -1) | (-(v4689 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4709[v4870] = v4706;
      int * v4711 = v4645->cache_tags;
      int v4873 = (int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1);
      v4711[v4849] = v4873;
      int * v4713 = v4645->cache_dirty;
      v4713[v4849] = 0;
      int * v4715 = v4645->cache_age;
      v4715[v4849] = 1;
      int * v4717 = v4645->cache_age;
      int v4718 = v4717[v4849];
      int v4719 = v4717[v4823];
      int v4879 = v4719 + ((int)((unsigned int)(v4719 - v4718) >> 31));
      v4717[v4823] = v4879;
      int * v4721 = v4645->cache_age;
      int v4722 = v4721[v4824];
      int v4881 = v4722 + ((int)((unsigned int)(v4722 - v4718) >> 31));
      v4721[v4824] = v4881;
      int * v4724 = v4645->cache_age;
      v4724[v4849] = 0;
      v4727 = v4849;
    }
    int * v4728 = v4645->cache_vals;
    int v4884 = v4727 * 2;
    int v4729 = v4728[v4884];
    int v4885 = (v4727 * 2) + 1;
    int v4730 = v4728[v4885];
    int v4886 = (((((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v4669 + ((~(((v4671 ^ -1) | (-(v4671 ^ -1))) >> 31)) & 2)) - (v4672 + ((~(((v4673 ^ -1) | (-(v4673 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4728[v4886] = v4729;
    int * v4732 = v4645->cache_vals;
    int v4889 = ((((((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v4669 + ((~(((v4671 ^ -1) | (-(v4671 ^ -1))) >> 31)) & 2)) - (v4672 + ((~(((v4673 ^ -1) | (-(v4673 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4732[v4889] = v4730;
    int * v4734 = v4645->cache_tags;
    int v4892 = ((((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v4669 + ((~(((v4671 ^ -1) | (-(v4671 ^ -1))) >> 31)) & 2)) - (v4672 + ((~(((v4673 ^ -1) | (-(v4673 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4893 = (int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1);
    v4734[v4892] = v4893;
    int * v4736 = v4645->cache_dirty;
    v4736[v4892] = 0;
    int * v4738 = v4645->cache_age;
    v4738[v4892] = 1;
    int * v4740 = v4645->cache_age;
    int v4741 = v4740[v4892];
    int v4742 = v4740[v4821];
    int v4899 = v4742 + ((int)((unsigned int)(v4742 - v4741) >> 31));
    v4740[v4821] = v4899;
    int * v4744 = v4645->cache_age;
    int v4745 = v4744[v4822];
    int v4901 = v4745 + ((int)((unsigned int)(v4745 - v4741) >> 31));
    v4744[v4822] = v4901;
    int * v4747 = v4645->cache_age;
    v4747[v4892] = 0;
    v4750 = v4892;
  }
  int * v4751 = v4645->cache_vals;
  int v4904 = (v4750 * 2) + (((int)((unsigned int)(v4649 + 20) >> 2)) & 1);
  v4751[v4904] = v4650;
  int * v4753 = v4645->cache_tags;
  int v4754 = v4753[v4823];
  int v4755 = v4753[v4824];
  bool v4907 = !(((~(((v4754 ^ ((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1))) | (-(v4754 ^ ((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v4755 ^ ((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1))) | (-(v4755 ^ ((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v4809;
  if (v4907) {
    int * v4756 = v4645->cache_age;
    int v4909 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4755 ^ ((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1))) | (-(v4755 ^ ((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v4757 = v4756[v4909];
    int v4758 = v4756[v4823];
    int v4910 = v4758 + ((int)((unsigned int)(v4758 - v4757) >> 31));
    v4756[v4823] = v4910;
    int * v4760 = v4645->cache_age;
    int v4761 = v4760[v4824];
    int v4912 = v4761 + ((int)((unsigned int)(v4761 - v4757) >> 31));
    v4760[v4824] = v4912;
    int * v4763 = v4645->cache_age;
    v4763[v4909] = 0;
    v4809 = v4909;
  } else {
    int * v4766 = v4645->cache_age;
    int v4916 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1)) & 3) * 2);
    int v4767 = v4766[v4916];
    int * v4768 = v4645->cache_tags;
    int v4769 = v4768[v4916];
    int v4770 = v4766[v4824];
    int v4771 = v4768[v4824];
    int * v4772 = v4645->cache_dirty;
    int v4919 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v4767 + ((~(((v4769 ^ -1) | (-(v4769 ^ -1))) >> 31)) & 2)) - (v4770 + ((~(((v4771 ^ -1) | (-(v4771 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4773 = v4772[v4919];
    bool v4920 = !(v4773 == 0);
    if (v4920) {
      int * v4774 = v4645->cache_tags;
      int v4775 = v4774[v4919];
      int * v4776 = v4645->cache_vals;
      int v4923 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v4767 + ((~(((v4769 ^ -1) | (-(v4769 ^ -1))) >> 31)) & 2)) - (v4770 + ((~(((v4771 ^ -1) | (-(v4771 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v4777 = v4776[v4923];
      int v4924 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v4767 + ((~(((v4769 ^ -1) | (-(v4769 ^ -1))) >> 31)) & 2)) - (v4770 + ((~(((v4771 ^ -1) | (-(v4771 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v4778 = v4776[v4924];
      int * v4779 = v4645->mem;
      int v4926 = v4775 * 2;
      v4779[v4926] = v4777;
      int * v4781 = v4645->mem;
      int v4929 = (v4775 * 2) + 1;
      v4781[v4929] = v4778;
      ;
    } else {
      ;
    }
    int * v4786 = v4645->mem;
    int v4934 = ((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1)) * 2;
    int v4787 = v4786[v4934];
    int v4935 = (((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1)) * 2) + 1;
    int v4788 = v4786[v4935];
    int * v4789 = v4645->cache_vals;
    int v4937 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v4767 + ((~(((v4769 ^ -1) | (-(v4769 ^ -1))) >> 31)) & 2)) - (v4770 + ((~(((v4771 ^ -1) | (-(v4771 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4789[v4937] = v4787;
    int * v4791 = v4645->cache_vals;
    int v4940 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v4767 + ((~(((v4769 ^ -1) | (-(v4769 ^ -1))) >> 31)) & 2)) - (v4770 + ((~(((v4771 ^ -1) | (-(v4771 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4791[v4940] = v4788;
    int * v4793 = v4645->cache_tags;
    int v4943 = (int)((unsigned int)((int)((unsigned int)(v4649 + 20) >> 2)) >> 1);
    v4793[v4919] = v4943;
    int * v4795 = v4645->cache_dirty;
    v4795[v4919] = 0;
    int * v4797 = v4645->cache_age;
    v4797[v4919] = 1;
    int * v4799 = v4645->cache_age;
    int v4800 = v4799[v4919];
    int v4801 = v4799[v4823];
    int v4949 = v4801 + ((int)((unsigned int)(v4801 - v4800) >> 31));
    v4799[v4823] = v4949;
    int * v4803 = v4645->cache_age;
    int v4804 = v4803[v4824];
    int v4951 = v4804 + ((int)((unsigned int)(v4804 - v4800) >> 31));
    v4803[v4824] = v4951;
    int * v4806 = v4645->cache_age;
    v4806[v4919] = 0;
    v4809 = v4919;
  }
  int * v4810 = v4645->cache_vals;
  int v4954 = (v4809 * 2) + (((int)((unsigned int)(v4649 + 20) >> 2)) & 1);
  v4810[v4954] = v4650;
  int * v4812 = v4645->cache_dirty;
  v4812[v4809] = 1;
  struct StateT * v4814 = slot_43(v4645);
  return v4814;
}

struct StateT * slot_46(struct StateT * v4980) {
  int v4981 = v4980->timer;
  int v4988 = v4981 + 1;
  v4980->timer = v4988;
  int * v4983 = v4980->regs;
  int v4984 = v4983[11];
  int v4992 = v4984 + 24;
  v4983[13] = v4992;
  struct StateT * v4986 = slot_47(v4980);
  return v4986;
}

struct StateT * slot_20(struct StateT * v2321) {
  int v2322 = v2321->timer;
  int v2492 = v2322 + 1;
  v2321->timer = v2492;
  int * v2324 = v2321->regs;
  int v2325 = v2324[10];
  int v2326 = v2324[14];
  int * v2327 = v2321->cache_tags;
  int v2497 = (((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1)) & 1) * 2;
  int v2328 = v2327[v2497];
  int v2498 = ((((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2329 = v2327[v2498];
  int v2499 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1)) & 3) * 2);
  int v2330 = v2327[v2499];
  int v2500 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2331 = v2327[v2500];
  int v2332 = v2321->timer;
  int v2501 = v2332 + ((100 ^ (((~(((v2330 ^ ((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1))) | (-(v2330 ^ ((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2331 ^ ((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1))) | (-(v2331 ^ ((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2328 ^ ((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1))) | (-(v2328 ^ ((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2329 ^ ((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1))) | (-(v2329 ^ ((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2330 ^ ((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1))) | (-(v2330 ^ ((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2331 ^ ((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1))) | (-(v2331 ^ ((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2321->timer = v2501;
  bool v2502 = !(((~(((v2328 ^ ((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1))) | (-(v2328 ^ ((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2329 ^ ((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1))) | (-(v2329 ^ ((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v2426;
  if (v2502) {
    int * v2334 = v2321->cache_age;
    int v2504 = ((((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v2329 ^ ((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1))) | (-(v2329 ^ ((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v2335 = v2334[v2504];
    int v2336 = v2334[v2497];
    int v2505 = v2336 + ((int)((unsigned int)(v2336 - v2335) >> 31));
    v2334[v2497] = v2505;
    int * v2338 = v2321->cache_age;
    int v2339 = v2338[v2498];
    int v2507 = v2339 + ((int)((unsigned int)(v2339 - v2335) >> 31));
    v2338[v2498] = v2507;
    int * v2341 = v2321->cache_age;
    v2341[v2504] = 0;
    v2426 = v2504;
  } else {
    int * v2344 = v2321->cache_age;
    int v2511 = (((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1)) & 1) * 2;
    int v2345 = v2344[v2511];
    int * v2346 = v2321->cache_tags;
    int v2347 = v2346[v2511];
    int v2348 = v2344[v2498];
    int v2349 = v2346[v2498];
    bool v2513 = !(((~(((v2330 ^ ((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1))) | (-(v2330 ^ ((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2331 ^ ((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1))) | (-(v2331 ^ ((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v2403;
    if (v2513) {
      int * v2350 = v2321->cache_age;
      int v2515 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2331 ^ ((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1))) | (-(v2331 ^ ((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v2351 = v2350[v2515];
      int v2352 = v2350[v2499];
      int v2516 = v2352 + ((int)((unsigned int)(v2352 - v2351) >> 31));
      v2350[v2499] = v2516;
      int * v2354 = v2321->cache_age;
      int v2355 = v2354[v2500];
      int v2518 = v2355 + ((int)((unsigned int)(v2355 - v2351) >> 31));
      v2354[v2500] = v2518;
      int * v2357 = v2321->cache_age;
      v2357[v2515] = 0;
      v2403 = v2515;
    } else {
      int * v2360 = v2321->cache_age;
      int v2522 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1)) & 3) * 2);
      int v2361 = v2360[v2522];
      int * v2362 = v2321->cache_tags;
      int v2363 = v2362[v2522];
      int v2364 = v2360[v2500];
      int v2365 = v2362[v2500];
      int * v2366 = v2321->cache_dirty;
      int v2525 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2361 + ((~(((v2363 ^ -1) | (-(v2363 ^ -1))) >> 31)) & 2)) - (v2364 + ((~(((v2365 ^ -1) | (-(v2365 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2367 = v2366[v2525];
      bool v2526 = !(v2367 == 0);
      if (v2526) {
        int * v2368 = v2321->cache_tags;
        int v2369 = v2368[v2525];
        int * v2370 = v2321->cache_vals;
        int v2529 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2361 + ((~(((v2363 ^ -1) | (-(v2363 ^ -1))) >> 31)) & 2)) - (v2364 + ((~(((v2365 ^ -1) | (-(v2365 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2371 = v2370[v2529];
        int v2530 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2361 + ((~(((v2363 ^ -1) | (-(v2363 ^ -1))) >> 31)) & 2)) - (v2364 + ((~(((v2365 ^ -1) | (-(v2365 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2372 = v2370[v2530];
        int * v2373 = v2321->mem;
        int v2532 = v2369 * 2;
        v2373[v2532] = v2371;
        int * v2375 = v2321->mem;
        int v2535 = (v2369 * 2) + 1;
        v2375[v2535] = v2372;
        ;
      } else {
        ;
      }
      int * v2380 = v2321->mem;
      int v2540 = ((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1)) * 2;
      int v2381 = v2380[v2540];
      int v2541 = (((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1)) * 2) + 1;
      int v2382 = v2380[v2541];
      int * v2383 = v2321->cache_vals;
      int v2543 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2361 + ((~(((v2363 ^ -1) | (-(v2363 ^ -1))) >> 31)) & 2)) - (v2364 + ((~(((v2365 ^ -1) | (-(v2365 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2383[v2543] = v2381;
      int * v2385 = v2321->cache_vals;
      int v2546 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2361 + ((~(((v2363 ^ -1) | (-(v2363 ^ -1))) >> 31)) & 2)) - (v2364 + ((~(((v2365 ^ -1) | (-(v2365 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2385[v2546] = v2382;
      int * v2387 = v2321->cache_tags;
      int v2549 = (int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1);
      v2387[v2525] = v2549;
      int * v2389 = v2321->cache_dirty;
      v2389[v2525] = 0;
      int * v2391 = v2321->cache_age;
      v2391[v2525] = 1;
      int * v2393 = v2321->cache_age;
      int v2394 = v2393[v2525];
      int v2395 = v2393[v2499];
      int v2555 = v2395 + ((int)((unsigned int)(v2395 - v2394) >> 31));
      v2393[v2499] = v2555;
      int * v2397 = v2321->cache_age;
      int v2398 = v2397[v2500];
      int v2557 = v2398 + ((int)((unsigned int)(v2398 - v2394) >> 31));
      v2397[v2500] = v2557;
      int * v2400 = v2321->cache_age;
      v2400[v2525] = 0;
      v2403 = v2525;
    }
    int * v2404 = v2321->cache_vals;
    int v2560 = v2403 * 2;
    int v2405 = v2404[v2560];
    int v2561 = (v2403 * 2) + 1;
    int v2406 = v2404[v2561];
    int v2562 = (((((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v2345 + ((~(((v2347 ^ -1) | (-(v2347 ^ -1))) >> 31)) & 2)) - (v2348 + ((~(((v2349 ^ -1) | (-(v2349 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2404[v2562] = v2405;
    int * v2408 = v2321->cache_vals;
    int v2565 = ((((((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v2345 + ((~(((v2347 ^ -1) | (-(v2347 ^ -1))) >> 31)) & 2)) - (v2348 + ((~(((v2349 ^ -1) | (-(v2349 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2408[v2565] = v2406;
    int * v2410 = v2321->cache_tags;
    int v2568 = ((((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v2345 + ((~(((v2347 ^ -1) | (-(v2347 ^ -1))) >> 31)) & 2)) - (v2348 + ((~(((v2349 ^ -1) | (-(v2349 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2569 = (int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1);
    v2410[v2568] = v2569;
    int * v2412 = v2321->cache_dirty;
    v2412[v2568] = 0;
    int * v2414 = v2321->cache_age;
    v2414[v2568] = 1;
    int * v2416 = v2321->cache_age;
    int v2417 = v2416[v2568];
    int v2418 = v2416[v2497];
    int v2575 = v2418 + ((int)((unsigned int)(v2418 - v2417) >> 31));
    v2416[v2497] = v2575;
    int * v2420 = v2321->cache_age;
    int v2421 = v2420[v2498];
    int v2577 = v2421 + ((int)((unsigned int)(v2421 - v2417) >> 31));
    v2420[v2498] = v2577;
    int * v2423 = v2321->cache_age;
    v2423[v2568] = 0;
    v2426 = v2568;
  }
  int * v2427 = v2321->cache_vals;
  int v2580 = (v2426 * 2) + (((int)((unsigned int)(v2325 + 4) >> 2)) & 1);
  v2427[v2580] = v2326;
  int * v2429 = v2321->cache_tags;
  int v2430 = v2429[v2499];
  int v2431 = v2429[v2500];
  bool v2583 = !(((~(((v2430 ^ ((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1))) | (-(v2430 ^ ((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v2431 ^ ((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1))) | (-(v2431 ^ ((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v2485;
  if (v2583) {
    int * v2432 = v2321->cache_age;
    int v2585 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2431 ^ ((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1))) | (-(v2431 ^ ((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v2433 = v2432[v2585];
    int v2434 = v2432[v2499];
    int v2586 = v2434 + ((int)((unsigned int)(v2434 - v2433) >> 31));
    v2432[v2499] = v2586;
    int * v2436 = v2321->cache_age;
    int v2437 = v2436[v2500];
    int v2588 = v2437 + ((int)((unsigned int)(v2437 - v2433) >> 31));
    v2436[v2500] = v2588;
    int * v2439 = v2321->cache_age;
    v2439[v2585] = 0;
    v2485 = v2585;
  } else {
    int * v2442 = v2321->cache_age;
    int v2592 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1)) & 3) * 2);
    int v2443 = v2442[v2592];
    int * v2444 = v2321->cache_tags;
    int v2445 = v2444[v2592];
    int v2446 = v2442[v2500];
    int v2447 = v2444[v2500];
    int * v2448 = v2321->cache_dirty;
    int v2595 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2443 + ((~(((v2445 ^ -1) | (-(v2445 ^ -1))) >> 31)) & 2)) - (v2446 + ((~(((v2447 ^ -1) | (-(v2447 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2449 = v2448[v2595];
    bool v2596 = !(v2449 == 0);
    if (v2596) {
      int * v2450 = v2321->cache_tags;
      int v2451 = v2450[v2595];
      int * v2452 = v2321->cache_vals;
      int v2599 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2443 + ((~(((v2445 ^ -1) | (-(v2445 ^ -1))) >> 31)) & 2)) - (v2446 + ((~(((v2447 ^ -1) | (-(v2447 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v2453 = v2452[v2599];
      int v2600 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2443 + ((~(((v2445 ^ -1) | (-(v2445 ^ -1))) >> 31)) & 2)) - (v2446 + ((~(((v2447 ^ -1) | (-(v2447 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v2454 = v2452[v2600];
      int * v2455 = v2321->mem;
      int v2602 = v2451 * 2;
      v2455[v2602] = v2453;
      int * v2457 = v2321->mem;
      int v2605 = (v2451 * 2) + 1;
      v2457[v2605] = v2454;
      ;
    } else {
      ;
    }
    int * v2462 = v2321->mem;
    int v2610 = ((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1)) * 2;
    int v2463 = v2462[v2610];
    int v2611 = (((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1)) * 2) + 1;
    int v2464 = v2462[v2611];
    int * v2465 = v2321->cache_vals;
    int v2613 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2443 + ((~(((v2445 ^ -1) | (-(v2445 ^ -1))) >> 31)) & 2)) - (v2446 + ((~(((v2447 ^ -1) | (-(v2447 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2465[v2613] = v2463;
    int * v2467 = v2321->cache_vals;
    int v2616 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v2443 + ((~(((v2445 ^ -1) | (-(v2445 ^ -1))) >> 31)) & 2)) - (v2446 + ((~(((v2447 ^ -1) | (-(v2447 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2467[v2616] = v2464;
    int * v2469 = v2321->cache_tags;
    int v2619 = (int)((unsigned int)((int)((unsigned int)(v2325 + 4) >> 2)) >> 1);
    v2469[v2595] = v2619;
    int * v2471 = v2321->cache_dirty;
    v2471[v2595] = 0;
    int * v2473 = v2321->cache_age;
    v2473[v2595] = 1;
    int * v2475 = v2321->cache_age;
    int v2476 = v2475[v2595];
    int v2477 = v2475[v2499];
    int v2625 = v2477 + ((int)((unsigned int)(v2477 - v2476) >> 31));
    v2475[v2499] = v2625;
    int * v2479 = v2321->cache_age;
    int v2480 = v2479[v2500];
    int v2627 = v2480 + ((int)((unsigned int)(v2480 - v2476) >> 31));
    v2479[v2500] = v2627;
    int * v2482 = v2321->cache_age;
    v2482[v2595] = 0;
    v2485 = v2595;
  }
  int * v2486 = v2321->cache_vals;
  int v2630 = (v2485 * 2) + (((int)((unsigned int)(v2325 + 4) >> 2)) & 1);
  v2486[v2630] = v2326;
  int * v2488 = v2321->cache_dirty;
  v2488[v2485] = 1;
  struct StateT * v2490 = slot_21(v2321);
  return v2490;
}

struct StateT * slot_61(struct StateT * v6688) {
  int v6689 = v6688->timer;
  int v6699 = v6689 + 1;
  v6688->timer = v6699;
  int * v6691 = v6688->regs;
  int v6692 = v6691[12];
  bool v6702 = !(v6692 == 0);
  struct StateT * v6697;
  if (v6702) {
    struct StateT * v6693 = slot_64(v6688);
    v6697 = v6693;
  } else {
    struct StateT * v6695 = slot_62(v6688);
    v6697 = v6695;
  }
  return v6697;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_41(struct StateT * v4434) {
  int v4435 = v4434->timer;
  int v4545 = v4435 + 1;
  v4434->timer = v4545;
  int * v4437 = v4434->regs;
  int v4438 = v4437[13];
  int * v4439 = v4434->cache_tags;
  int v4549 = (((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1)) & 1) * 2;
  int v4440 = v4439[v4549];
  int v4550 = ((((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1)) & 1) * 2) + 1;
  int v4441 = v4439[v4550];
  int v4551 = 4 + ((((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1)) & 3) * 2);
  int v4442 = v4439[v4551];
  int v4552 = (4 + ((((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4443 = v4439[v4552];
  int v4444 = v4434->timer;
  int v4553 = v4444 + ((100 ^ (((~(((v4442 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))) | (-(v4442 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))))) >> 31)) | (~(((v4443 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))) | (-(v4443 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4440 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))) | (-(v4440 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))))) >> 31)) | (~(((v4441 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))) | (-(v4441 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4442 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))) | (-(v4442 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))))) >> 31)) | (~(((v4443 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))) | (-(v4443 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))))) >> 31))) & 104)))));
  v4434->timer = v4553;
  int * v4446 = v4434->cache_vals;
  bool v4554 = !(((~(((v4440 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))) | (-(v4440 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))))) >> 31)) | (~(((v4441 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))) | (-(v4441 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))))) >> 31))) == 0);
  int v4539;
  if (v4554) {
    int * v4447 = v4434->cache_age;
    int v4556 = ((((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1)) & 1) * 2) + ((~(((v4441 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))) | (-(v4441 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))))) >> 31)) & 1);
    int v4448 = v4447[v4556];
    int v4449 = v4447[v4549];
    int v4557 = v4449 + ((int)((unsigned int)(v4449 - v4448) >> 31));
    v4447[v4549] = v4557;
    int * v4451 = v4434->cache_age;
    int v4452 = v4451[v4550];
    int v4559 = v4452 + ((int)((unsigned int)(v4452 - v4448) >> 31));
    v4451[v4550] = v4559;
    int * v4454 = v4434->cache_age;
    v4454[v4556] = 0;
    v4539 = v4556;
  } else {
    int * v4457 = v4434->cache_age;
    int v4563 = (((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1)) & 1) * 2;
    int v4458 = v4457[v4563];
    int * v4459 = v4434->cache_tags;
    int v4460 = v4459[v4563];
    int v4461 = v4457[v4550];
    int v4462 = v4459[v4550];
    bool v4565 = !(((~(((v4442 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))) | (-(v4442 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))))) >> 31)) | (~(((v4443 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))) | (-(v4443 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))))) >> 31))) == 0);
    int v4516;
    if (v4565) {
      int * v4463 = v4434->cache_age;
      int v4567 = (4 + ((((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1)) & 3) * 2)) + ((~(((v4443 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))) | (-(v4443 ^ ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1))))) >> 31)) & 1);
      int v4464 = v4463[v4567];
      int v4465 = v4463[v4551];
      int v4568 = v4465 + ((int)((unsigned int)(v4465 - v4464) >> 31));
      v4463[v4551] = v4568;
      int * v4467 = v4434->cache_age;
      int v4468 = v4467[v4552];
      int v4570 = v4468 + ((int)((unsigned int)(v4468 - v4464) >> 31));
      v4467[v4552] = v4570;
      int * v4470 = v4434->cache_age;
      v4470[v4567] = 0;
      v4516 = v4567;
    } else {
      int * v4473 = v4434->cache_age;
      int v4574 = 4 + ((((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1)) & 3) * 2);
      int v4474 = v4473[v4574];
      int * v4475 = v4434->cache_tags;
      int v4476 = v4475[v4574];
      int v4477 = v4473[v4552];
      int v4478 = v4475[v4552];
      int * v4479 = v4434->cache_dirty;
      int v4577 = (4 + ((((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1)) & 3) * 2)) + ((((v4474 + ((~(((v4476 ^ -1) | (-(v4476 ^ -1))) >> 31)) & 2)) - (v4477 + ((~(((v4478 ^ -1) | (-(v4478 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4480 = v4479[v4577];
      bool v4578 = !(v4480 == 0);
      if (v4578) {
        int * v4481 = v4434->cache_tags;
        int v4482 = v4481[v4577];
        int * v4483 = v4434->cache_vals;
        int v4581 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1)) & 3) * 2)) + ((((v4474 + ((~(((v4476 ^ -1) | (-(v4476 ^ -1))) >> 31)) & 2)) - (v4477 + ((~(((v4478 ^ -1) | (-(v4478 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4484 = v4483[v4581];
        int v4582 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1)) & 3) * 2)) + ((((v4474 + ((~(((v4476 ^ -1) | (-(v4476 ^ -1))) >> 31)) & 2)) - (v4477 + ((~(((v4478 ^ -1) | (-(v4478 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4485 = v4483[v4582];
        int * v4486 = v4434->mem;
        int v4584 = v4482 * 2;
        v4486[v4584] = v4484;
        int * v4488 = v4434->mem;
        int v4587 = (v4482 * 2) + 1;
        v4488[v4587] = v4485;
        ;
      } else {
        ;
      }
      int * v4493 = v4434->mem;
      int v4592 = ((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1)) * 2;
      int v4494 = v4493[v4592];
      int v4593 = (((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1)) * 2) + 1;
      int v4495 = v4493[v4593];
      int * v4496 = v4434->cache_vals;
      int v4595 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1)) & 3) * 2)) + ((((v4474 + ((~(((v4476 ^ -1) | (-(v4476 ^ -1))) >> 31)) & 2)) - (v4477 + ((~(((v4478 ^ -1) | (-(v4478 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4496[v4595] = v4494;
      int * v4498 = v4434->cache_vals;
      int v4598 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1)) & 3) * 2)) + ((((v4474 + ((~(((v4476 ^ -1) | (-(v4476 ^ -1))) >> 31)) & 2)) - (v4477 + ((~(((v4478 ^ -1) | (-(v4478 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4498[v4598] = v4495;
      int * v4500 = v4434->cache_tags;
      int v4601 = (int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1);
      v4500[v4577] = v4601;
      int * v4502 = v4434->cache_dirty;
      v4502[v4577] = 0;
      int * v4504 = v4434->cache_age;
      v4504[v4577] = 1;
      int * v4506 = v4434->cache_age;
      int v4507 = v4506[v4577];
      int v4508 = v4506[v4551];
      int v4607 = v4508 + ((int)((unsigned int)(v4508 - v4507) >> 31));
      v4506[v4551] = v4607;
      int * v4510 = v4434->cache_age;
      int v4511 = v4510[v4552];
      int v4609 = v4511 + ((int)((unsigned int)(v4511 - v4507) >> 31));
      v4510[v4552] = v4609;
      int * v4513 = v4434->cache_age;
      v4513[v4577] = 0;
      v4516 = v4577;
    }
    int * v4517 = v4434->cache_vals;
    int v4612 = v4516 * 2;
    int v4518 = v4517[v4612];
    int v4613 = (v4516 * 2) + 1;
    int v4519 = v4517[v4613];
    int v4614 = (((((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1)) & 1) * 2) + ((((v4458 + ((~(((v4460 ^ -1) | (-(v4460 ^ -1))) >> 31)) & 2)) - (v4461 + ((~(((v4462 ^ -1) | (-(v4462 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4517[v4614] = v4518;
    int * v4521 = v4434->cache_vals;
    int v4617 = ((((((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1)) & 1) * 2) + ((((v4458 + ((~(((v4460 ^ -1) | (-(v4460 ^ -1))) >> 31)) & 2)) - (v4461 + ((~(((v4462 ^ -1) | (-(v4462 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4521[v4617] = v4519;
    int * v4523 = v4434->cache_tags;
    int v4620 = ((((int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1)) & 1) * 2) + ((((v4458 + ((~(((v4460 ^ -1) | (-(v4460 ^ -1))) >> 31)) & 2)) - (v4461 + ((~(((v4462 ^ -1) | (-(v4462 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4621 = (int)((unsigned int)((int)((unsigned int)v4438 >> 2)) >> 1);
    v4523[v4620] = v4621;
    int * v4525 = v4434->cache_dirty;
    v4525[v4620] = 0;
    int * v4527 = v4434->cache_age;
    v4527[v4620] = 1;
    int * v4529 = v4434->cache_age;
    int v4530 = v4529[v4620];
    int v4531 = v4529[v4549];
    int v4627 = v4531 + ((int)((unsigned int)(v4531 - v4530) >> 31));
    v4529[v4549] = v4627;
    int * v4533 = v4434->cache_age;
    int v4534 = v4533[v4550];
    int v4629 = v4534 + ((int)((unsigned int)(v4534 - v4530) >> 31));
    v4533[v4550] = v4629;
    int * v4536 = v4434->cache_age;
    v4536[v4620] = 0;
    v4539 = v4620;
  }
  int v4632 = (v4539 * 2) + (((int)((unsigned int)v4438 >> 2)) & 1);
  int v4540 = v4446[v4632];
  int * v4541 = v4434->regs;
  v4541[13] = v4540;
  struct StateT * v4543 = slot_42(v4434);
  return v4543;
}

struct StateT * slot_39(struct StateT * v4637) {
  int v4638 = v4637->timer;
  int v4642 = v4638 + 1;
  v4637->timer = v4642;
  struct StateT * v4640 = slot_41(v4637);
  return v4640;
}

struct StateT * slot_8(struct StateT * v892) {
  int v893 = v892->timer;
  int v901 = v893 + 1;
  v892->timer = v901;
  int * v895 = v892->regs;
  int v896 = v895[12];
  int v897 = v895[13];
  int v905 = v896 & v897;
  v895[12] = v905;
  struct StateT * v899 = slot_9(v892);
  return v899;
}

struct StateT * slot_30(struct StateT * v3493) {
  int v3494 = v3493->timer;
  int v3664 = v3494 + 1;
  v3493->timer = v3664;
  int * v3496 = v3493->regs;
  int v3497 = v3496[10];
  int v3498 = v3496[13];
  int * v3499 = v3493->cache_tags;
  int v3669 = (((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1)) & 1) * 2;
  int v3500 = v3499[v3669];
  int v3670 = ((((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v3501 = v3499[v3670];
  int v3671 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1)) & 3) * 2);
  int v3502 = v3499[v3671];
  int v3672 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3503 = v3499[v3672];
  int v3504 = v3493->timer;
  int v3673 = v3504 + ((100 ^ (((~(((v3502 ^ ((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1))) | (-(v3502 ^ ((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v3503 ^ ((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1))) | (-(v3503 ^ ((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3500 ^ ((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1))) | (-(v3500 ^ ((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v3501 ^ ((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1))) | (-(v3501 ^ ((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3502 ^ ((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1))) | (-(v3502 ^ ((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v3503 ^ ((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1))) | (-(v3503 ^ ((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v3493->timer = v3673;
  bool v3674 = !(((~(((v3500 ^ ((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1))) | (-(v3500 ^ ((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v3501 ^ ((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1))) | (-(v3501 ^ ((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v3598;
  if (v3674) {
    int * v3506 = v3493->cache_age;
    int v3676 = ((((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v3501 ^ ((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1))) | (-(v3501 ^ ((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v3507 = v3506[v3676];
    int v3508 = v3506[v3669];
    int v3677 = v3508 + ((int)((unsigned int)(v3508 - v3507) >> 31));
    v3506[v3669] = v3677;
    int * v3510 = v3493->cache_age;
    int v3511 = v3510[v3670];
    int v3679 = v3511 + ((int)((unsigned int)(v3511 - v3507) >> 31));
    v3510[v3670] = v3679;
    int * v3513 = v3493->cache_age;
    v3513[v3676] = 0;
    v3598 = v3676;
  } else {
    int * v3516 = v3493->cache_age;
    int v3683 = (((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1)) & 1) * 2;
    int v3517 = v3516[v3683];
    int * v3518 = v3493->cache_tags;
    int v3519 = v3518[v3683];
    int v3520 = v3516[v3670];
    int v3521 = v3518[v3670];
    bool v3685 = !(((~(((v3502 ^ ((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1))) | (-(v3502 ^ ((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v3503 ^ ((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1))) | (-(v3503 ^ ((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v3575;
    if (v3685) {
      int * v3522 = v3493->cache_age;
      int v3687 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3503 ^ ((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1))) | (-(v3503 ^ ((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v3523 = v3522[v3687];
      int v3524 = v3522[v3671];
      int v3688 = v3524 + ((int)((unsigned int)(v3524 - v3523) >> 31));
      v3522[v3671] = v3688;
      int * v3526 = v3493->cache_age;
      int v3527 = v3526[v3672];
      int v3690 = v3527 + ((int)((unsigned int)(v3527 - v3523) >> 31));
      v3526[v3672] = v3690;
      int * v3529 = v3493->cache_age;
      v3529[v3687] = 0;
      v3575 = v3687;
    } else {
      int * v3532 = v3493->cache_age;
      int v3694 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1)) & 3) * 2);
      int v3533 = v3532[v3694];
      int * v3534 = v3493->cache_tags;
      int v3535 = v3534[v3694];
      int v3536 = v3532[v3672];
      int v3537 = v3534[v3672];
      int * v3538 = v3493->cache_dirty;
      int v3697 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3533 + ((~(((v3535 ^ -1) | (-(v3535 ^ -1))) >> 31)) & 2)) - (v3536 + ((~(((v3537 ^ -1) | (-(v3537 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3539 = v3538[v3697];
      bool v3698 = !(v3539 == 0);
      if (v3698) {
        int * v3540 = v3493->cache_tags;
        int v3541 = v3540[v3697];
        int * v3542 = v3493->cache_vals;
        int v3701 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3533 + ((~(((v3535 ^ -1) | (-(v3535 ^ -1))) >> 31)) & 2)) - (v3536 + ((~(((v3537 ^ -1) | (-(v3537 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3543 = v3542[v3701];
        int v3702 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3533 + ((~(((v3535 ^ -1) | (-(v3535 ^ -1))) >> 31)) & 2)) - (v3536 + ((~(((v3537 ^ -1) | (-(v3537 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3544 = v3542[v3702];
        int * v3545 = v3493->mem;
        int v3704 = v3541 * 2;
        v3545[v3704] = v3543;
        int * v3547 = v3493->mem;
        int v3707 = (v3541 * 2) + 1;
        v3547[v3707] = v3544;
        ;
      } else {
        ;
      }
      int * v3552 = v3493->mem;
      int v3712 = ((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1)) * 2;
      int v3553 = v3552[v3712];
      int v3713 = (((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1)) * 2) + 1;
      int v3554 = v3552[v3713];
      int * v3555 = v3493->cache_vals;
      int v3715 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3533 + ((~(((v3535 ^ -1) | (-(v3535 ^ -1))) >> 31)) & 2)) - (v3536 + ((~(((v3537 ^ -1) | (-(v3537 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3555[v3715] = v3553;
      int * v3557 = v3493->cache_vals;
      int v3718 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3533 + ((~(((v3535 ^ -1) | (-(v3535 ^ -1))) >> 31)) & 2)) - (v3536 + ((~(((v3537 ^ -1) | (-(v3537 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3557[v3718] = v3554;
      int * v3559 = v3493->cache_tags;
      int v3721 = (int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1);
      v3559[v3697] = v3721;
      int * v3561 = v3493->cache_dirty;
      v3561[v3697] = 0;
      int * v3563 = v3493->cache_age;
      v3563[v3697] = 1;
      int * v3565 = v3493->cache_age;
      int v3566 = v3565[v3697];
      int v3567 = v3565[v3671];
      int v3727 = v3567 + ((int)((unsigned int)(v3567 - v3566) >> 31));
      v3565[v3671] = v3727;
      int * v3569 = v3493->cache_age;
      int v3570 = v3569[v3672];
      int v3729 = v3570 + ((int)((unsigned int)(v3570 - v3566) >> 31));
      v3569[v3672] = v3729;
      int * v3572 = v3493->cache_age;
      v3572[v3697] = 0;
      v3575 = v3697;
    }
    int * v3576 = v3493->cache_vals;
    int v3732 = v3575 * 2;
    int v3577 = v3576[v3732];
    int v3733 = (v3575 * 2) + 1;
    int v3578 = v3576[v3733];
    int v3734 = (((((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v3517 + ((~(((v3519 ^ -1) | (-(v3519 ^ -1))) >> 31)) & 2)) - (v3520 + ((~(((v3521 ^ -1) | (-(v3521 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3576[v3734] = v3577;
    int * v3580 = v3493->cache_vals;
    int v3737 = ((((((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v3517 + ((~(((v3519 ^ -1) | (-(v3519 ^ -1))) >> 31)) & 2)) - (v3520 + ((~(((v3521 ^ -1) | (-(v3521 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3580[v3737] = v3578;
    int * v3582 = v3493->cache_tags;
    int v3740 = ((((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v3517 + ((~(((v3519 ^ -1) | (-(v3519 ^ -1))) >> 31)) & 2)) - (v3520 + ((~(((v3521 ^ -1) | (-(v3521 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3741 = (int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1);
    v3582[v3740] = v3741;
    int * v3584 = v3493->cache_dirty;
    v3584[v3740] = 0;
    int * v3586 = v3493->cache_age;
    v3586[v3740] = 1;
    int * v3588 = v3493->cache_age;
    int v3589 = v3588[v3740];
    int v3590 = v3588[v3669];
    int v3747 = v3590 + ((int)((unsigned int)(v3590 - v3589) >> 31));
    v3588[v3669] = v3747;
    int * v3592 = v3493->cache_age;
    int v3593 = v3592[v3670];
    int v3749 = v3593 + ((int)((unsigned int)(v3593 - v3589) >> 31));
    v3592[v3670] = v3749;
    int * v3595 = v3493->cache_age;
    v3595[v3740] = 0;
    v3598 = v3740;
  }
  int * v3599 = v3493->cache_vals;
  int v3752 = (v3598 * 2) + (((int)((unsigned int)(v3497 + 12) >> 2)) & 1);
  v3599[v3752] = v3498;
  int * v3601 = v3493->cache_tags;
  int v3602 = v3601[v3671];
  int v3603 = v3601[v3672];
  bool v3755 = !(((~(((v3602 ^ ((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1))) | (-(v3602 ^ ((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v3603 ^ ((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1))) | (-(v3603 ^ ((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v3657;
  if (v3755) {
    int * v3604 = v3493->cache_age;
    int v3757 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3603 ^ ((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1))) | (-(v3603 ^ ((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v3605 = v3604[v3757];
    int v3606 = v3604[v3671];
    int v3758 = v3606 + ((int)((unsigned int)(v3606 - v3605) >> 31));
    v3604[v3671] = v3758;
    int * v3608 = v3493->cache_age;
    int v3609 = v3608[v3672];
    int v3760 = v3609 + ((int)((unsigned int)(v3609 - v3605) >> 31));
    v3608[v3672] = v3760;
    int * v3611 = v3493->cache_age;
    v3611[v3757] = 0;
    v3657 = v3757;
  } else {
    int * v3614 = v3493->cache_age;
    int v3764 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1)) & 3) * 2);
    int v3615 = v3614[v3764];
    int * v3616 = v3493->cache_tags;
    int v3617 = v3616[v3764];
    int v3618 = v3614[v3672];
    int v3619 = v3616[v3672];
    int * v3620 = v3493->cache_dirty;
    int v3767 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3615 + ((~(((v3617 ^ -1) | (-(v3617 ^ -1))) >> 31)) & 2)) - (v3618 + ((~(((v3619 ^ -1) | (-(v3619 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3621 = v3620[v3767];
    bool v3768 = !(v3621 == 0);
    if (v3768) {
      int * v3622 = v3493->cache_tags;
      int v3623 = v3622[v3767];
      int * v3624 = v3493->cache_vals;
      int v3771 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3615 + ((~(((v3617 ^ -1) | (-(v3617 ^ -1))) >> 31)) & 2)) - (v3618 + ((~(((v3619 ^ -1) | (-(v3619 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v3625 = v3624[v3771];
      int v3772 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3615 + ((~(((v3617 ^ -1) | (-(v3617 ^ -1))) >> 31)) & 2)) - (v3618 + ((~(((v3619 ^ -1) | (-(v3619 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v3626 = v3624[v3772];
      int * v3627 = v3493->mem;
      int v3774 = v3623 * 2;
      v3627[v3774] = v3625;
      int * v3629 = v3493->mem;
      int v3777 = (v3623 * 2) + 1;
      v3629[v3777] = v3626;
      ;
    } else {
      ;
    }
    int * v3634 = v3493->mem;
    int v3782 = ((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1)) * 2;
    int v3635 = v3634[v3782];
    int v3783 = (((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1)) * 2) + 1;
    int v3636 = v3634[v3783];
    int * v3637 = v3493->cache_vals;
    int v3785 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3615 + ((~(((v3617 ^ -1) | (-(v3617 ^ -1))) >> 31)) & 2)) - (v3618 + ((~(((v3619 ^ -1) | (-(v3619 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3637[v3785] = v3635;
    int * v3639 = v3493->cache_vals;
    int v3788 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3615 + ((~(((v3617 ^ -1) | (-(v3617 ^ -1))) >> 31)) & 2)) - (v3618 + ((~(((v3619 ^ -1) | (-(v3619 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3639[v3788] = v3636;
    int * v3641 = v3493->cache_tags;
    int v3791 = (int)((unsigned int)((int)((unsigned int)(v3497 + 12) >> 2)) >> 1);
    v3641[v3767] = v3791;
    int * v3643 = v3493->cache_dirty;
    v3643[v3767] = 0;
    int * v3645 = v3493->cache_age;
    v3645[v3767] = 1;
    int * v3647 = v3493->cache_age;
    int v3648 = v3647[v3767];
    int v3649 = v3647[v3671];
    int v3797 = v3649 + ((int)((unsigned int)(v3649 - v3648) >> 31));
    v3647[v3671] = v3797;
    int * v3651 = v3493->cache_age;
    int v3652 = v3651[v3672];
    int v3799 = v3652 + ((int)((unsigned int)(v3652 - v3648) >> 31));
    v3651[v3672] = v3799;
    int * v3654 = v3493->cache_age;
    v3654[v3767] = 0;
    v3657 = v3767;
  }
  int * v3658 = v3493->cache_vals;
  int v3802 = (v3657 * 2) + (((int)((unsigned int)(v3497 + 12) >> 2)) & 1);
  v3658[v3802] = v3498;
  int * v3660 = v3493->cache_dirty;
  v3660[v3657] = 1;
  struct StateT * v3662 = slot_31(v3493);
  return v3662;
}

struct StateT * slot_60(struct StateT * v6373) {
  int v6374 = v6373->timer;
  int v6544 = v6374 + 1;
  v6373->timer = v6544;
  int * v6376 = v6373->regs;
  int v6377 = v6376[10];
  int v6378 = v6376[13];
  int * v6379 = v6373->cache_tags;
  int v6549 = (((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1)) & 1) * 2;
  int v6380 = v6379[v6549];
  int v6550 = ((((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1)) & 1) * 2) + 1;
  int v6381 = v6379[v6550];
  int v6551 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1)) & 3) * 2);
  int v6382 = v6379[v6551];
  int v6552 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v6383 = v6379[v6552];
  int v6384 = v6373->timer;
  int v6553 = v6384 + ((100 ^ (((~(((v6382 ^ ((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1))) | (-(v6382 ^ ((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v6383 ^ ((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1))) | (-(v6383 ^ ((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v6380 ^ ((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1))) | (-(v6380 ^ ((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v6381 ^ ((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1))) | (-(v6381 ^ ((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v6382 ^ ((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1))) | (-(v6382 ^ ((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v6383 ^ ((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1))) | (-(v6383 ^ ((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1))))) >> 31))) & 104)))));
  v6373->timer = v6553;
  bool v6554 = !(((~(((v6380 ^ ((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1))) | (-(v6380 ^ ((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v6381 ^ ((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1))) | (-(v6381 ^ ((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v6478;
  if (v6554) {
    int * v6386 = v6373->cache_age;
    int v6556 = ((((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1)) & 1) * 2) + ((~(((v6381 ^ ((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1))) | (-(v6381 ^ ((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1))))) >> 31)) & 1);
    int v6387 = v6386[v6556];
    int v6388 = v6386[v6549];
    int v6557 = v6388 + ((int)((unsigned int)(v6388 - v6387) >> 31));
    v6386[v6549] = v6557;
    int * v6390 = v6373->cache_age;
    int v6391 = v6390[v6550];
    int v6559 = v6391 + ((int)((unsigned int)(v6391 - v6387) >> 31));
    v6390[v6550] = v6559;
    int * v6393 = v6373->cache_age;
    v6393[v6556] = 0;
    v6478 = v6556;
  } else {
    int * v6396 = v6373->cache_age;
    int v6563 = (((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1)) & 1) * 2;
    int v6397 = v6396[v6563];
    int * v6398 = v6373->cache_tags;
    int v6399 = v6398[v6563];
    int v6400 = v6396[v6550];
    int v6401 = v6398[v6550];
    bool v6565 = !(((~(((v6382 ^ ((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1))) | (-(v6382 ^ ((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v6383 ^ ((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1))) | (-(v6383 ^ ((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1))))) >> 31))) == 0);
    int v6455;
    if (v6565) {
      int * v6402 = v6373->cache_age;
      int v6567 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v6383 ^ ((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1))) | (-(v6383 ^ ((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1))))) >> 31)) & 1);
      int v6403 = v6402[v6567];
      int v6404 = v6402[v6551];
      int v6568 = v6404 + ((int)((unsigned int)(v6404 - v6403) >> 31));
      v6402[v6551] = v6568;
      int * v6406 = v6373->cache_age;
      int v6407 = v6406[v6552];
      int v6570 = v6407 + ((int)((unsigned int)(v6407 - v6403) >> 31));
      v6406[v6552] = v6570;
      int * v6409 = v6373->cache_age;
      v6409[v6567] = 0;
      v6455 = v6567;
    } else {
      int * v6412 = v6373->cache_age;
      int v6574 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1)) & 3) * 2);
      int v6413 = v6412[v6574];
      int * v6414 = v6373->cache_tags;
      int v6415 = v6414[v6574];
      int v6416 = v6412[v6552];
      int v6417 = v6414[v6552];
      int * v6418 = v6373->cache_dirty;
      int v6577 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v6413 + ((~(((v6415 ^ -1) | (-(v6415 ^ -1))) >> 31)) & 2)) - (v6416 + ((~(((v6417 ^ -1) | (-(v6417 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v6419 = v6418[v6577];
      bool v6578 = !(v6419 == 0);
      if (v6578) {
        int * v6420 = v6373->cache_tags;
        int v6421 = v6420[v6577];
        int * v6422 = v6373->cache_vals;
        int v6581 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v6413 + ((~(((v6415 ^ -1) | (-(v6415 ^ -1))) >> 31)) & 2)) - (v6416 + ((~(((v6417 ^ -1) | (-(v6417 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v6423 = v6422[v6581];
        int v6582 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v6413 + ((~(((v6415 ^ -1) | (-(v6415 ^ -1))) >> 31)) & 2)) - (v6416 + ((~(((v6417 ^ -1) | (-(v6417 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v6424 = v6422[v6582];
        int * v6425 = v6373->mem;
        int v6584 = v6421 * 2;
        v6425[v6584] = v6423;
        int * v6427 = v6373->mem;
        int v6587 = (v6421 * 2) + 1;
        v6427[v6587] = v6424;
        ;
      } else {
        ;
      }
      int * v6432 = v6373->mem;
      int v6592 = ((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1)) * 2;
      int v6433 = v6432[v6592];
      int v6593 = (((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1)) * 2) + 1;
      int v6434 = v6432[v6593];
      int * v6435 = v6373->cache_vals;
      int v6595 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v6413 + ((~(((v6415 ^ -1) | (-(v6415 ^ -1))) >> 31)) & 2)) - (v6416 + ((~(((v6417 ^ -1) | (-(v6417 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v6435[v6595] = v6433;
      int * v6437 = v6373->cache_vals;
      int v6598 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v6413 + ((~(((v6415 ^ -1) | (-(v6415 ^ -1))) >> 31)) & 2)) - (v6416 + ((~(((v6417 ^ -1) | (-(v6417 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v6437[v6598] = v6434;
      int * v6439 = v6373->cache_tags;
      int v6601 = (int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1);
      v6439[v6577] = v6601;
      int * v6441 = v6373->cache_dirty;
      v6441[v6577] = 0;
      int * v6443 = v6373->cache_age;
      v6443[v6577] = 1;
      int * v6445 = v6373->cache_age;
      int v6446 = v6445[v6577];
      int v6447 = v6445[v6551];
      int v6607 = v6447 + ((int)((unsigned int)(v6447 - v6446) >> 31));
      v6445[v6551] = v6607;
      int * v6449 = v6373->cache_age;
      int v6450 = v6449[v6552];
      int v6609 = v6450 + ((int)((unsigned int)(v6450 - v6446) >> 31));
      v6449[v6552] = v6609;
      int * v6452 = v6373->cache_age;
      v6452[v6577] = 0;
      v6455 = v6577;
    }
    int * v6456 = v6373->cache_vals;
    int v6612 = v6455 * 2;
    int v6457 = v6456[v6612];
    int v6613 = (v6455 * 2) + 1;
    int v6458 = v6456[v6613];
    int v6614 = (((((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v6397 + ((~(((v6399 ^ -1) | (-(v6399 ^ -1))) >> 31)) & 2)) - (v6400 + ((~(((v6401 ^ -1) | (-(v6401 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6456[v6614] = v6457;
    int * v6460 = v6373->cache_vals;
    int v6617 = ((((((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v6397 + ((~(((v6399 ^ -1) | (-(v6399 ^ -1))) >> 31)) & 2)) - (v6400 + ((~(((v6401 ^ -1) | (-(v6401 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6460[v6617] = v6458;
    int * v6462 = v6373->cache_tags;
    int v6620 = ((((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v6397 + ((~(((v6399 ^ -1) | (-(v6399 ^ -1))) >> 31)) & 2)) - (v6400 + ((~(((v6401 ^ -1) | (-(v6401 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6621 = (int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1);
    v6462[v6620] = v6621;
    int * v6464 = v6373->cache_dirty;
    v6464[v6620] = 0;
    int * v6466 = v6373->cache_age;
    v6466[v6620] = 1;
    int * v6468 = v6373->cache_age;
    int v6469 = v6468[v6620];
    int v6470 = v6468[v6549];
    int v6627 = v6470 + ((int)((unsigned int)(v6470 - v6469) >> 31));
    v6468[v6549] = v6627;
    int * v6472 = v6373->cache_age;
    int v6473 = v6472[v6550];
    int v6629 = v6473 + ((int)((unsigned int)(v6473 - v6469) >> 31));
    v6472[v6550] = v6629;
    int * v6475 = v6373->cache_age;
    v6475[v6620] = 0;
    v6478 = v6620;
  }
  int * v6479 = v6373->cache_vals;
  int v6632 = (v6478 * 2) + (((int)((unsigned int)(v6377 + 32) >> 2)) & 1);
  v6479[v6632] = v6378;
  int * v6481 = v6373->cache_tags;
  int v6482 = v6481[v6551];
  int v6483 = v6481[v6552];
  bool v6635 = !(((~(((v6482 ^ ((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1))) | (-(v6482 ^ ((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v6483 ^ ((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1))) | (-(v6483 ^ ((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v6537;
  if (v6635) {
    int * v6484 = v6373->cache_age;
    int v6637 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v6483 ^ ((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1))) | (-(v6483 ^ ((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1))))) >> 31)) & 1);
    int v6485 = v6484[v6637];
    int v6486 = v6484[v6551];
    int v6638 = v6486 + ((int)((unsigned int)(v6486 - v6485) >> 31));
    v6484[v6551] = v6638;
    int * v6488 = v6373->cache_age;
    int v6489 = v6488[v6552];
    int v6640 = v6489 + ((int)((unsigned int)(v6489 - v6485) >> 31));
    v6488[v6552] = v6640;
    int * v6491 = v6373->cache_age;
    v6491[v6637] = 0;
    v6537 = v6637;
  } else {
    int * v6494 = v6373->cache_age;
    int v6644 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1)) & 3) * 2);
    int v6495 = v6494[v6644];
    int * v6496 = v6373->cache_tags;
    int v6497 = v6496[v6644];
    int v6498 = v6494[v6552];
    int v6499 = v6496[v6552];
    int * v6500 = v6373->cache_dirty;
    int v6647 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v6495 + ((~(((v6497 ^ -1) | (-(v6497 ^ -1))) >> 31)) & 2)) - (v6498 + ((~(((v6499 ^ -1) | (-(v6499 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6501 = v6500[v6647];
    bool v6648 = !(v6501 == 0);
    if (v6648) {
      int * v6502 = v6373->cache_tags;
      int v6503 = v6502[v6647];
      int * v6504 = v6373->cache_vals;
      int v6651 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v6495 + ((~(((v6497 ^ -1) | (-(v6497 ^ -1))) >> 31)) & 2)) - (v6498 + ((~(((v6499 ^ -1) | (-(v6499 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v6505 = v6504[v6651];
      int v6652 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v6495 + ((~(((v6497 ^ -1) | (-(v6497 ^ -1))) >> 31)) & 2)) - (v6498 + ((~(((v6499 ^ -1) | (-(v6499 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v6506 = v6504[v6652];
      int * v6507 = v6373->mem;
      int v6654 = v6503 * 2;
      v6507[v6654] = v6505;
      int * v6509 = v6373->mem;
      int v6657 = (v6503 * 2) + 1;
      v6509[v6657] = v6506;
      ;
    } else {
      ;
    }
    int * v6514 = v6373->mem;
    int v6662 = ((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1)) * 2;
    int v6515 = v6514[v6662];
    int v6663 = (((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1)) * 2) + 1;
    int v6516 = v6514[v6663];
    int * v6517 = v6373->cache_vals;
    int v6665 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v6495 + ((~(((v6497 ^ -1) | (-(v6497 ^ -1))) >> 31)) & 2)) - (v6498 + ((~(((v6499 ^ -1) | (-(v6499 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6517[v6665] = v6515;
    int * v6519 = v6373->cache_vals;
    int v6668 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v6495 + ((~(((v6497 ^ -1) | (-(v6497 ^ -1))) >> 31)) & 2)) - (v6498 + ((~(((v6499 ^ -1) | (-(v6499 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6519[v6668] = v6516;
    int * v6521 = v6373->cache_tags;
    int v6671 = (int)((unsigned int)((int)((unsigned int)(v6377 + 32) >> 2)) >> 1);
    v6521[v6647] = v6671;
    int * v6523 = v6373->cache_dirty;
    v6523[v6647] = 0;
    int * v6525 = v6373->cache_age;
    v6525[v6647] = 1;
    int * v6527 = v6373->cache_age;
    int v6528 = v6527[v6647];
    int v6529 = v6527[v6551];
    int v6677 = v6529 + ((int)((unsigned int)(v6529 - v6528) >> 31));
    v6527[v6551] = v6677;
    int * v6531 = v6373->cache_age;
    int v6532 = v6531[v6552];
    int v6679 = v6532 + ((int)((unsigned int)(v6532 - v6528) >> 31));
    v6531[v6552] = v6679;
    int * v6534 = v6373->cache_age;
    v6534[v6647] = 0;
    v6537 = v6647;
  }
  int * v6538 = v6373->cache_vals;
  int v6682 = (v6537 * 2) + (((int)((unsigned int)(v6377 + 32) >> 2)) & 1);
  v6538[v6682] = v6378;
  int * v6540 = v6373->cache_dirty;
  v6540[v6537] = 1;
  struct StateT * v6542 = slot_61(v6373);
  return v6542;
}

struct StateT * slot_4(struct StateT * v816) {
  int v817 = v816->timer;
  int v825 = v817 + 1;
  v816->timer = v825;
  int * v819 = v816->regs;
  int v820 = v819[15];
  int v821 = v819[12];
  int v829 = v820 ^ v821;
  v819[12] = v829;
  struct StateT * v823 = slot_5(v816);
  return v823;
}

struct StateT * slot_18(struct StateT * v1782) {
  int v1783 = v1782->timer;
  int v1793 = v1783 + 1;
  v1782->timer = v1793;
  int * v1785 = v1782->regs;
  int v1786 = v1785[12];
  bool v1796 = v1786 == 0;
  struct StateT * v1791;
  if (v1796) {
    struct StateT * v1787 = slot_12(v1782);
    v1791 = v1787;
  } else {
    struct StateT * v1789 = slot_19(v1782);
    v1791 = v1789;
  }
  return v1791;
}

struct StateT * slot_9(struct StateT * v908) {
  int v909 = v908->timer;
  int v919 = v909 + 1;
  v908->timer = v919;
  int * v911 = v908->regs;
  int v912 = v911[12];
  bool v922 = !(v912 == 0);
  struct StateT * v917;
  if (v922) {
    struct StateT * v913 = slot_16(v908);
    v917 = v913;
  } else {
    struct StateT * v915 = slot_10(v908);
    v917 = v915;
  }
  return v917;
}

struct StateT * slot_11(struct StateT * v1762) {
  int v1763 = v1762->timer;
  int v1773 = v1763 + 1;
  v1762->timer = v1773;
  int * v1765 = v1762->regs;
  int v1766 = v1765[12];
  bool v1776 = !(v1766 == 0);
  struct StateT * v1771;
  if (v1776) {
    struct StateT * v1767 = slot_19(v1762);
    v1771 = v1767;
  } else {
    struct StateT * v1769 = slot_12(v1762);
    v1771 = v1769;
  }
  return v1771;
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
  
  // a10, 10 words: the address is public
  s1.regs[10] = 0;
  s2.regs[10] = 0;
  // a11, 10 words: the address is public
  s1.regs[11] = 40;
  s2.regs[11] = 40;
  // a12, 10 words: the address is public
  s1.regs[12] = 80;
  s2.regs[12] = 80;
  // a13, 10 words: the address is public
  s1.regs[13] = 120;
  s2.regs[13] = 120;
  // its contents, public: the same draw in both states
  for (int i=0; i<10; i++) {
    int v = bounded(0, 1);
    s1.mem[20 + i] = v;
    s2.mem[20 + i] = v;
  }
  // its contents, public: the same draw in both states
  for (int i=0; i<10; i++) {
    int v = bounded(0, 1);
    s1.mem[30 + i] = v;
    s2.mem[30 + i] = v;
  }
  
  // a10's contents, secret: a different draw in each state. f[0] and
  // f[1] are what the comparisons read, so they draw against
  // 1 and the rest against 20.
  s1.mem[0] = secret(0, 1);
  s2.mem[0] = secret(0, 1);
  s1.mem[1] = secret(0, 1);
  s2.mem[1] = secret(0, 1);
  for (int i=2; i<10; i++) {
    s1.mem[0 + i] = secret(0, 20);
    s2.mem[0 + i] = secret(0, 20);
  }
  // a11's contents, secret: the value copied in, drawn separately
  for (int i=0; i<10; i++) {
    s1.mem[10 + i] = secret(0, 20);
    s2.mem[10 + i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}