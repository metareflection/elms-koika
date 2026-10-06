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

struct StateT * slot_6(struct StateT * v106);
struct StateT * slot_29(struct StateT * v1896);
struct StateT * slot_25(struct StateT * v1847);
struct StateT * slot_16(struct StateT * v1092);
struct StateT * slot_23(struct StateT * v1392);
struct StateT * slot_5(struct StateT * v74);
struct StateT * slot_2(struct StateT * v34);
struct StateT * slot_7(struct StateT * v321);
struct StateT * slot_3(struct StateT * v50);
struct StateT * slot_26(struct StateT * v1860);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_13(struct StateT * v829);
struct StateT * slot_24(struct StateT * v1607);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_17(struct StateT * v1100);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_4(struct StateT * v66);
struct StateT * slot_15(struct StateT * v1076);
struct StateT * slot_6(struct StateT * v106) {
  int * v107 = v106->saved_regs;
  int * v108 = v106->regs;
  int v109 = v108[10];
  v107[10] = v109;
  int v111 = v106->timer;
  int v227 = v111 + 1;
  v106->timer = v227;
  int * v113 = v106->reg_ready;
  int v114 = v113[5];
  int * v115 = v106->regs;
  int v116 = v115[5];
  int * v117 = v106->cache_tags;
  int v232 = (((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1)) & 1) * 2;
  int v118 = v117[v232];
  int v233 = ((((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1)) & 1) * 2) + 1;
  int v119 = v117[v233];
  int v234 = 4 + ((((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1)) & 3) * 2);
  int v120 = v117[v234];
  int v235 = (4 + ((((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v121 = v117[v235];
  int * v122 = v106->cache_vals;
  bool v236 = !(((~(((v118 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))) | (-(v118 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))))) >> 31)) | (~(((v119 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))) | (-(v119 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))))) >> 31))) == 0);
  int v215;
  if (v236) {
    int * v123 = v106->cache_age;
    int v238 = ((((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1)) & 1) * 2) + ((~(((v119 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))) | (-(v119 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))))) >> 31)) & 1);
    int v124 = v123[v238];
    int v125 = v123[v232];
    int v239 = v125 + ((int)((unsigned int)(v125 - v124) >> 31));
    v123[v232] = v239;
    int * v127 = v106->cache_age;
    int v128 = v127[v233];
    int v241 = v128 + ((int)((unsigned int)(v128 - v124) >> 31));
    v127[v233] = v241;
    int * v130 = v106->cache_age;
    v130[v238] = 0;
    v215 = v238;
  } else {
    int * v133 = v106->cache_age;
    int v245 = (((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1)) & 1) * 2;
    int v134 = v133[v245];
    int * v135 = v106->cache_tags;
    int v136 = v135[v245];
    int v137 = v133[v233];
    int v138 = v135[v233];
    bool v247 = !(((~(((v120 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))) | (-(v120 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))))) >> 31)) | (~(((v121 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))) | (-(v121 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))))) >> 31))) == 0);
    int v192;
    if (v247) {
      int * v139 = v106->cache_age;
      int v249 = (4 + ((((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1)) & 3) * 2)) + ((~(((v121 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))) | (-(v121 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))))) >> 31)) & 1);
      int v140 = v139[v249];
      int v141 = v139[v234];
      int v250 = v141 + ((int)((unsigned int)(v141 - v140) >> 31));
      v139[v234] = v250;
      int * v143 = v106->cache_age;
      int v144 = v143[v235];
      int v252 = v144 + ((int)((unsigned int)(v144 - v140) >> 31));
      v143[v235] = v252;
      int * v146 = v106->cache_age;
      v146[v249] = 0;
      v192 = v249;
    } else {
      int * v149 = v106->cache_age;
      int v256 = 4 + ((((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1)) & 3) * 2);
      int v150 = v149[v256];
      int * v151 = v106->cache_tags;
      int v152 = v151[v256];
      int v153 = v149[v235];
      int v154 = v151[v235];
      int * v155 = v106->cache_dirty;
      int v259 = (4 + ((((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1)) & 3) * 2)) + ((((v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2)) - (v153 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v156 = v155[v259];
      bool v260 = !(v156 == 0);
      if (v260) {
        int * v157 = v106->cache_tags;
        int v158 = v157[v259];
        int * v159 = v106->cache_vals;
        int v263 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1)) & 3) * 2)) + ((((v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2)) - (v153 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v160 = v159[v263];
        int v264 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1)) & 3) * 2)) + ((((v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2)) - (v153 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v161 = v159[v264];
        int * v162 = v106->mem;
        int v266 = v158 * 2;
        v162[v266] = v160;
        int * v164 = v106->mem;
        int v269 = (v158 * 2) + 1;
        v164[v269] = v161;
        ;
      } else {
        ;
      }
      int * v169 = v106->mem;
      int v274 = ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1)) * 2;
      int v170 = v169[v274];
      int v275 = (((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1)) * 2) + 1;
      int v171 = v169[v275];
      int * v172 = v106->cache_vals;
      int v277 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1)) & 3) * 2)) + ((((v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2)) - (v153 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v172[v277] = v170;
      int * v174 = v106->cache_vals;
      int v280 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1)) & 3) * 2)) + ((((v150 + ((~(((v152 ^ -1) | (-(v152 ^ -1))) >> 31)) & 2)) - (v153 + ((~(((v154 ^ -1) | (-(v154 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v174[v280] = v171;
      int * v176 = v106->cache_tags;
      int v283 = (int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1);
      v176[v259] = v283;
      int * v178 = v106->cache_dirty;
      v178[v259] = 0;
      int * v180 = v106->cache_age;
      v180[v259] = 1;
      int * v182 = v106->cache_age;
      int v183 = v182[v259];
      int v184 = v182[v234];
      int v289 = v184 + ((int)((unsigned int)(v184 - v183) >> 31));
      v182[v234] = v289;
      int * v186 = v106->cache_age;
      int v187 = v186[v235];
      int v291 = v187 + ((int)((unsigned int)(v187 - v183) >> 31));
      v186[v235] = v291;
      int * v189 = v106->cache_age;
      v189[v259] = 0;
      v192 = v259;
    }
    int * v193 = v106->cache_vals;
    int v294 = v192 * 2;
    int v194 = v193[v294];
    int v295 = (v192 * 2) + 1;
    int v195 = v193[v295];
    int v296 = (((((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1)) & 1) * 2) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v137 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v193[v296] = v194;
    int * v197 = v106->cache_vals;
    int v299 = ((((((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1)) & 1) * 2) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v137 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v197[v299] = v195;
    int * v199 = v106->cache_tags;
    int v302 = ((((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1)) & 1) * 2) + ((((v134 + ((~(((v136 ^ -1) | (-(v136 ^ -1))) >> 31)) & 2)) - (v137 + ((~(((v138 ^ -1) | (-(v138 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v303 = (int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1);
    v199[v302] = v303;
    int * v201 = v106->cache_dirty;
    v201[v302] = 0;
    int * v203 = v106->cache_age;
    v203[v302] = 1;
    int * v205 = v106->cache_age;
    int v206 = v205[v302];
    int v207 = v205[v232];
    int v309 = v207 + ((int)((unsigned int)(v207 - v206) >> 31));
    v205[v232] = v309;
    int * v209 = v106->cache_age;
    int v210 = v209[v233];
    int v311 = v210 + ((int)((unsigned int)(v210 - v206) >> 31));
    v209[v233] = v311;
    int * v212 = v106->cache_age;
    v212[v302] = 0;
    v215 = v302;
  }
  int v314 = (v215 * 2) + (((int)((unsigned int)v116 >> 2)) & 1);
  int v216 = v122[v314];
  int * v217 = v106->reg_ready;
  int v316 = ((v114 + ((v111 - v114) & (~((v111 - v114) >> 31)))) + 1) + ((100 ^ (((~(((v120 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))) | (-(v120 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))))) >> 31)) | (~(((v121 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))) | (-(v121 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v118 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))) | (-(v118 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))))) >> 31)) | (~(((v119 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))) | (-(v119 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v120 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))) | (-(v120 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))))) >> 31)) | (~(((v121 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))) | (-(v121 ^ ((int)((unsigned int)((int)((unsigned int)v116 >> 2)) >> 1))))) >> 31))) & 104)))));
  v217[10] = v316;
  int * v219 = v106->regs;
  v219[10] = v216;
  struct StateT * v221 = slot_7(v106);
  return v221;
}

struct StateT * slot_29(struct StateT * v1896) {
  int * v1897 = v1896->regs;
  int v1898 = v1897[10];
  int v1899 = v1897[11];
  bool v2011 = !(v1898 == v1899);
  struct StateT * v2006;
  if (v2011) {
    int v1900 = v1896->timer;
    int v2012 = v1900 + 15;
    v1896->timer = v2012;
    int * v1902 = v1896->saved_regs;
    int v1903 = v1902[14];
    int * v1904 = v1896->regs;
    v1904[14] = v1903;
    int * v1906 = v1896->reg_ready;
    int v1907 = v1896->timer;
    v1906[0] = v1907;
    int * v1909 = v1896->reg_ready;
    int v1910 = v1896->timer;
    v1909[1] = v1910;
    int * v1912 = v1896->reg_ready;
    int v1913 = v1896->timer;
    v1912[2] = v1913;
    int * v1915 = v1896->reg_ready;
    int v1916 = v1896->timer;
    v1915[3] = v1916;
    int * v1918 = v1896->reg_ready;
    int v1919 = v1896->timer;
    v1918[4] = v1919;
    int * v1921 = v1896->reg_ready;
    int v1922 = v1896->timer;
    v1921[5] = v1922;
    int * v1924 = v1896->reg_ready;
    int v1925 = v1896->timer;
    v1924[6] = v1925;
    int * v1927 = v1896->reg_ready;
    int v1928 = v1896->timer;
    v1927[7] = v1928;
    int * v1930 = v1896->reg_ready;
    int v1931 = v1896->timer;
    v1930[8] = v1931;
    int * v1933 = v1896->reg_ready;
    int v1934 = v1896->timer;
    v1933[9] = v1934;
    int * v1936 = v1896->reg_ready;
    int v1937 = v1896->timer;
    v1936[10] = v1937;
    int * v1939 = v1896->reg_ready;
    int v1940 = v1896->timer;
    v1939[11] = v1940;
    int * v1942 = v1896->reg_ready;
    int v1943 = v1896->timer;
    v1942[12] = v1943;
    int * v1945 = v1896->reg_ready;
    int v1946 = v1896->timer;
    v1945[13] = v1946;
    int * v1948 = v1896->reg_ready;
    int v1949 = v1896->timer;
    v1948[14] = v1949;
    int * v1951 = v1896->reg_ready;
    int v1952 = v1896->timer;
    v1951[15] = v1952;
    int * v1954 = v1896->reg_ready;
    int v1955 = v1896->timer;
    v1954[16] = v1955;
    int * v1957 = v1896->reg_ready;
    int v1958 = v1896->timer;
    v1957[17] = v1958;
    int * v1960 = v1896->reg_ready;
    int v1961 = v1896->timer;
    v1960[18] = v1961;
    int * v1963 = v1896->reg_ready;
    int v1964 = v1896->timer;
    v1963[19] = v1964;
    int * v1966 = v1896->reg_ready;
    int v1967 = v1896->timer;
    v1966[20] = v1967;
    int * v1969 = v1896->reg_ready;
    int v1970 = v1896->timer;
    v1969[21] = v1970;
    int * v1972 = v1896->reg_ready;
    int v1973 = v1896->timer;
    v1972[22] = v1973;
    int * v1975 = v1896->reg_ready;
    int v1976 = v1896->timer;
    v1975[23] = v1976;
    int * v1978 = v1896->reg_ready;
    int v1979 = v1896->timer;
    v1978[24] = v1979;
    int * v1981 = v1896->reg_ready;
    int v1982 = v1896->timer;
    v1981[25] = v1982;
    int * v1984 = v1896->reg_ready;
    int v1985 = v1896->timer;
    v1984[26] = v1985;
    int * v1987 = v1896->reg_ready;
    int v1988 = v1896->timer;
    v1987[27] = v1988;
    int * v1990 = v1896->reg_ready;
    int v1991 = v1896->timer;
    v1990[28] = v1991;
    int * v1993 = v1896->reg_ready;
    int v1994 = v1896->timer;
    v1993[29] = v1994;
    int * v1996 = v1896->reg_ready;
    int v1997 = v1896->timer;
    v1996[30] = v1997;
    int * v1999 = v1896->reg_ready;
    int v2000 = v1896->timer;
    v1999[31] = v2000;
    struct StateT * v2002 = slot_15(v1896);
    v2006 = v2002;
  } else {
    struct StateT * v2004 = slot_16(v1896);
    v2006 = v2004;
  }
  return v2006;
}

struct StateT * slot_25(struct StateT * v1847) {
  int v1848 = v1847->timer;
  int v1855 = v1848 + 1;
  v1847->timer = v1855;
  int * v1850 = v1847->reg_ready;
  v1850[10] = v1855;
  int * v1852 = v1847->regs;
  v1852[10] = 1;
  return v1847;
}

struct StateT * slot_16(struct StateT * v1092) {
  int v1093 = v1092->timer;
  int v1097 = v1093 + 1;
  v1092->timer = v1097;
  struct StateT * v1095 = slot_4(v1092);
  return v1095;
}

struct StateT * slot_23(struct StateT * v1392) {
  int * v1393 = v1392->saved_regs;
  int * v1394 = v1392->regs;
  int v1395 = v1394[11];
  v1393[11] = v1395;
  int v1397 = v1392->timer;
  int v1513 = v1397 + 1;
  v1392->timer = v1513;
  int * v1399 = v1392->reg_ready;
  int v1400 = v1399[6];
  int * v1401 = v1392->regs;
  int v1402 = v1401[6];
  int * v1403 = v1392->cache_tags;
  int v1518 = (((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1)) & 1) * 2;
  int v1404 = v1403[v1518];
  int v1519 = ((((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1405 = v1403[v1519];
  int v1520 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1)) & 3) * 2);
  int v1406 = v1403[v1520];
  int v1521 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1407 = v1403[v1521];
  int * v1408 = v1392->cache_vals;
  bool v1522 = !(((~(((v1404 ^ ((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1))) | (-(v1404 ^ ((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1))))) >> 31)) | (~(((v1405 ^ ((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1))) | (-(v1405 ^ ((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1))))) >> 31))) == 0);
  int v1501;
  if (v1522) {
    int * v1409 = v1392->cache_age;
    int v1524 = ((((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1)) & 1) * 2) + ((~(((v1405 ^ ((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1))) | (-(v1405 ^ ((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1))))) >> 31)) & 1);
    int v1410 = v1409[v1524];
    int v1411 = v1409[v1518];
    int v1525 = v1411 + ((int)((unsigned int)(v1411 - v1410) >> 31));
    v1409[v1518] = v1525;
    int * v1413 = v1392->cache_age;
    int v1414 = v1413[v1519];
    int v1527 = v1414 + ((int)((unsigned int)(v1414 - v1410) >> 31));
    v1413[v1519] = v1527;
    int * v1416 = v1392->cache_age;
    v1416[v1524] = 0;
    v1501 = v1524;
  } else {
    int * v1419 = v1392->cache_age;
    int v1531 = (((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1)) & 1) * 2;
    int v1420 = v1419[v1531];
    int * v1421 = v1392->cache_tags;
    int v1422 = v1421[v1531];
    int v1423 = v1419[v1519];
    int v1424 = v1421[v1519];
    bool v1533 = !(((~(((v1406 ^ ((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1))) | (-(v1406 ^ ((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1))))) >> 31)) | (~(((v1407 ^ ((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1))) | (-(v1407 ^ ((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1))))) >> 31))) == 0);
    int v1478;
    if (v1533) {
      int * v1425 = v1392->cache_age;
      int v1535 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1407 ^ ((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1))) | (-(v1407 ^ ((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1))))) >> 31)) & 1);
      int v1426 = v1425[v1535];
      int v1427 = v1425[v1520];
      int v1536 = v1427 + ((int)((unsigned int)(v1427 - v1426) >> 31));
      v1425[v1520] = v1536;
      int * v1429 = v1392->cache_age;
      int v1430 = v1429[v1521];
      int v1538 = v1430 + ((int)((unsigned int)(v1430 - v1426) >> 31));
      v1429[v1521] = v1538;
      int * v1432 = v1392->cache_age;
      v1432[v1535] = 0;
      v1478 = v1535;
    } else {
      int * v1435 = v1392->cache_age;
      int v1542 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1)) & 3) * 2);
      int v1436 = v1435[v1542];
      int * v1437 = v1392->cache_tags;
      int v1438 = v1437[v1542];
      int v1439 = v1435[v1521];
      int v1440 = v1437[v1521];
      int * v1441 = v1392->cache_dirty;
      int v1545 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1)) & 3) * 2)) + ((((v1436 + ((~(((v1438 ^ -1) | (-(v1438 ^ -1))) >> 31)) & 2)) - (v1439 + ((~(((v1440 ^ -1) | (-(v1440 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1442 = v1441[v1545];
      bool v1546 = !(v1442 == 0);
      if (v1546) {
        int * v1443 = v1392->cache_tags;
        int v1444 = v1443[v1545];
        int * v1445 = v1392->cache_vals;
        int v1549 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1)) & 3) * 2)) + ((((v1436 + ((~(((v1438 ^ -1) | (-(v1438 ^ -1))) >> 31)) & 2)) - (v1439 + ((~(((v1440 ^ -1) | (-(v1440 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1446 = v1445[v1549];
        int v1550 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1)) & 3) * 2)) + ((((v1436 + ((~(((v1438 ^ -1) | (-(v1438 ^ -1))) >> 31)) & 2)) - (v1439 + ((~(((v1440 ^ -1) | (-(v1440 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1447 = v1445[v1550];
        int * v1448 = v1392->mem;
        int v1552 = v1444 * 2;
        v1448[v1552] = v1446;
        int * v1450 = v1392->mem;
        int v1555 = (v1444 * 2) + 1;
        v1450[v1555] = v1447;
        ;
      } else {
        ;
      }
      int * v1455 = v1392->mem;
      int v1560 = ((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1)) * 2;
      int v1456 = v1455[v1560];
      int v1561 = (((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1)) * 2) + 1;
      int v1457 = v1455[v1561];
      int * v1458 = v1392->cache_vals;
      int v1563 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1)) & 3) * 2)) + ((((v1436 + ((~(((v1438 ^ -1) | (-(v1438 ^ -1))) >> 31)) & 2)) - (v1439 + ((~(((v1440 ^ -1) | (-(v1440 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1458[v1563] = v1456;
      int * v1460 = v1392->cache_vals;
      int v1566 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1)) & 3) * 2)) + ((((v1436 + ((~(((v1438 ^ -1) | (-(v1438 ^ -1))) >> 31)) & 2)) - (v1439 + ((~(((v1440 ^ -1) | (-(v1440 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1460[v1566] = v1457;
      int * v1462 = v1392->cache_tags;
      int v1569 = (int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1);
      v1462[v1545] = v1569;
      int * v1464 = v1392->cache_dirty;
      v1464[v1545] = 0;
      int * v1466 = v1392->cache_age;
      v1466[v1545] = 1;
      int * v1468 = v1392->cache_age;
      int v1469 = v1468[v1545];
      int v1470 = v1468[v1520];
      int v1575 = v1470 + ((int)((unsigned int)(v1470 - v1469) >> 31));
      v1468[v1520] = v1575;
      int * v1472 = v1392->cache_age;
      int v1473 = v1472[v1521];
      int v1577 = v1473 + ((int)((unsigned int)(v1473 - v1469) >> 31));
      v1472[v1521] = v1577;
      int * v1475 = v1392->cache_age;
      v1475[v1545] = 0;
      v1478 = v1545;
    }
    int * v1479 = v1392->cache_vals;
    int v1580 = v1478 * 2;
    int v1480 = v1479[v1580];
    int v1581 = (v1478 * 2) + 1;
    int v1481 = v1479[v1581];
    int v1582 = (((((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1)) & 1) * 2) + ((((v1420 + ((~(((v1422 ^ -1) | (-(v1422 ^ -1))) >> 31)) & 2)) - (v1423 + ((~(((v1424 ^ -1) | (-(v1424 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1479[v1582] = v1480;
    int * v1483 = v1392->cache_vals;
    int v1585 = ((((((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1)) & 1) * 2) + ((((v1420 + ((~(((v1422 ^ -1) | (-(v1422 ^ -1))) >> 31)) & 2)) - (v1423 + ((~(((v1424 ^ -1) | (-(v1424 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1483[v1585] = v1481;
    int * v1485 = v1392->cache_tags;
    int v1588 = ((((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1)) & 1) * 2) + ((((v1420 + ((~(((v1422 ^ -1) | (-(v1422 ^ -1))) >> 31)) & 2)) - (v1423 + ((~(((v1424 ^ -1) | (-(v1424 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1589 = (int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1);
    v1485[v1588] = v1589;
    int * v1487 = v1392->cache_dirty;
    v1487[v1588] = 0;
    int * v1489 = v1392->cache_age;
    v1489[v1588] = 1;
    int * v1491 = v1392->cache_age;
    int v1492 = v1491[v1588];
    int v1493 = v1491[v1518];
    int v1595 = v1493 + ((int)((unsigned int)(v1493 - v1492) >> 31));
    v1491[v1518] = v1595;
    int * v1495 = v1392->cache_age;
    int v1496 = v1495[v1519];
    int v1597 = v1496 + ((int)((unsigned int)(v1496 - v1492) >> 31));
    v1495[v1519] = v1597;
    int * v1498 = v1392->cache_age;
    v1498[v1588] = 0;
    v1501 = v1588;
  }
  int v1600 = (v1501 * 2) + (((int)((unsigned int)v1402 >> 2)) & 1);
  int v1502 = v1408[v1600];
  int * v1503 = v1392->reg_ready;
  int v1602 = ((v1400 + ((v1397 - v1400) & (~((v1397 - v1400) >> 31)))) + 1) + ((100 ^ (((~(((v1406 ^ ((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1))) | (-(v1406 ^ ((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1))))) >> 31)) | (~(((v1407 ^ ((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1))) | (-(v1407 ^ ((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1404 ^ ((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1))) | (-(v1404 ^ ((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1))))) >> 31)) | (~(((v1405 ^ ((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1))) | (-(v1405 ^ ((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1406 ^ ((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1))) | (-(v1406 ^ ((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1))))) >> 31)) | (~(((v1407 ^ ((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1))) | (-(v1407 ^ ((int)((unsigned int)((int)((unsigned int)v1402 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1503[11] = v1602;
  int * v1505 = v1392->regs;
  v1505[11] = v1502;
  struct StateT * v1507 = slot_24(v1392);
  return v1507;
}

struct StateT * slot_5(struct StateT * v74) {
  int * v75 = v74->saved_regs;
  int * v76 = v74->regs;
  int v77 = v76[5];
  v75[5] = v77;
  int v79 = v74->timer;
  int v96 = v79 + 1;
  v74->timer = v96;
  int * v81 = v74->reg_ready;
  int v82 = v81[12];
  int * v83 = v74->regs;
  int v84 = v83[12];
  int v85 = v81[14];
  int v86 = v83[14];
  int v101 = (v85 + (((v82 + ((v79 - v82) & (~((v79 - v82) >> 31)))) - v85) & (~(((v82 + ((v79 - v82) & (~((v79 - v82) >> 31)))) - v85) >> 31)))) + 1;
  v81[5] = v101;
  int * v88 = v74->regs;
  int v103 = v84 + v86;
  v88[5] = v103;
  struct StateT * v90 = slot_6(v74);
  return v90;
}

struct StateT * slot_2(struct StateT * v34) {
  int v35 = v34->timer;
  int v43 = v35 + 1;
  v34->timer = v43;
  int * v37 = v34->reg_ready;
  v37[14] = v43;
  int * v39 = v34->regs;
  v39[14] = 0;
  struct StateT * v41 = slot_3(v34);
  return v41;
}

struct StateT * slot_7(struct StateT * v321) {
  int * v322 = v321->saved_regs;
  int * v323 = v321->regs;
  int v324 = v323[6];
  v322[6] = v324;
  int v326 = v321->timer;
  int v343 = v326 + 1;
  v321->timer = v343;
  int * v328 = v321->reg_ready;
  int v329 = v328[13];
  int * v330 = v321->regs;
  int v331 = v330[13];
  int v332 = v328[14];
  int v333 = v330[14];
  int v348 = (v332 + (((v329 + ((v326 - v329) & (~((v326 - v329) >> 31)))) - v332) & (~(((v329 + ((v326 - v329) & (~((v326 - v329) >> 31)))) - v332) >> 31)))) + 1;
  v328[6] = v348;
  int * v335 = v321->regs;
  int v350 = v331 + v333;
  v335[6] = v350;
  struct StateT * v337 = slot_23(v321);
  return v337;
}

struct StateT * slot_3(struct StateT * v50) {
  int v51 = v50->timer;
  int v59 = v51 + 1;
  v50->timer = v59;
  int * v53 = v50->reg_ready;
  v53[15] = v59;
  int * v55 = v50->regs;
  v55[15] = 16;
  struct StateT * v57 = slot_4(v50);
  return v57;
}

struct StateT * slot_26(struct StateT * v1860) {
  int v1861 = v1860->timer;
  int v1865 = v1861 + 1;
  v1860->timer = v1865;
  struct StateT * v1863 = slot_13(v1860);
  return v1863;
}

struct StateT * slot_1(struct StateT * v18) {
  int v19 = v18->timer;
  int v27 = v19 + 1;
  v18->timer = v27;
  int * v21 = v18->reg_ready;
  v21[13] = v27;
  int * v23 = v18->regs;
  v23[13] = 80;
  struct StateT * v25 = slot_2(v18);
  return v25;
}

struct StateT * slot_13(struct StateT * v829) {
  int * v830 = v829->saved_regs;
  int * v831 = v829->regs;
  int v832 = v831[14];
  v830[14] = v832;
  int v834 = v829->timer;
  int v849 = v834 + 1;
  v829->timer = v849;
  int * v836 = v829->reg_ready;
  int v837 = v836[14];
  int * v838 = v829->regs;
  int v839 = v838[14];
  int v852 = (v837 + ((v834 - v837) & (~((v834 - v837) >> 31)))) + 1;
  v836[14] = v852;
  int * v841 = v829->regs;
  int v854 = v839 + 4;
  v841[14] = v854;
  struct StateT * v843 = slot_29(v829);
  return v843;
}

struct StateT * slot_24(struct StateT * v1607) {
  int * v1608 = v1607->regs;
  int v1609 = v1608[14];
  int v1610 = v1608[15];
  bool v1734 = v1609 >= v1610;
  struct StateT * v1729;
  if (v1734) {
    int v1611 = v1607->timer;
    int v1735 = v1611 + 15;
    v1607->timer = v1735;
    int * v1613 = v1607->saved_regs;
    int v1614 = v1613[5];
    int * v1615 = v1607->regs;
    v1615[5] = v1614;
    int * v1617 = v1607->saved_regs;
    int v1618 = v1617[10];
    int * v1619 = v1607->regs;
    v1619[10] = v1618;
    int * v1621 = v1607->saved_regs;
    int v1622 = v1621[6];
    int * v1623 = v1607->regs;
    v1623[6] = v1622;
    int * v1625 = v1607->saved_regs;
    int v1626 = v1625[11];
    int * v1627 = v1607->regs;
    v1627[11] = v1626;
    int * v1629 = v1607->reg_ready;
    int v1630 = v1607->timer;
    v1629[0] = v1630;
    int * v1632 = v1607->reg_ready;
    int v1633 = v1607->timer;
    v1632[1] = v1633;
    int * v1635 = v1607->reg_ready;
    int v1636 = v1607->timer;
    v1635[2] = v1636;
    int * v1638 = v1607->reg_ready;
    int v1639 = v1607->timer;
    v1638[3] = v1639;
    int * v1641 = v1607->reg_ready;
    int v1642 = v1607->timer;
    v1641[4] = v1642;
    int * v1644 = v1607->reg_ready;
    int v1645 = v1607->timer;
    v1644[5] = v1645;
    int * v1647 = v1607->reg_ready;
    int v1648 = v1607->timer;
    v1647[6] = v1648;
    int * v1650 = v1607->reg_ready;
    int v1651 = v1607->timer;
    v1650[7] = v1651;
    int * v1653 = v1607->reg_ready;
    int v1654 = v1607->timer;
    v1653[8] = v1654;
    int * v1656 = v1607->reg_ready;
    int v1657 = v1607->timer;
    v1656[9] = v1657;
    int * v1659 = v1607->reg_ready;
    int v1660 = v1607->timer;
    v1659[10] = v1660;
    int * v1662 = v1607->reg_ready;
    int v1663 = v1607->timer;
    v1662[11] = v1663;
    int * v1665 = v1607->reg_ready;
    int v1666 = v1607->timer;
    v1665[12] = v1666;
    int * v1668 = v1607->reg_ready;
    int v1669 = v1607->timer;
    v1668[13] = v1669;
    int * v1671 = v1607->reg_ready;
    int v1672 = v1607->timer;
    v1671[14] = v1672;
    int * v1674 = v1607->reg_ready;
    int v1675 = v1607->timer;
    v1674[15] = v1675;
    int * v1677 = v1607->reg_ready;
    int v1678 = v1607->timer;
    v1677[16] = v1678;
    int * v1680 = v1607->reg_ready;
    int v1681 = v1607->timer;
    v1680[17] = v1681;
    int * v1683 = v1607->reg_ready;
    int v1684 = v1607->timer;
    v1683[18] = v1684;
    int * v1686 = v1607->reg_ready;
    int v1687 = v1607->timer;
    v1686[19] = v1687;
    int * v1689 = v1607->reg_ready;
    int v1690 = v1607->timer;
    v1689[20] = v1690;
    int * v1692 = v1607->reg_ready;
    int v1693 = v1607->timer;
    v1692[21] = v1693;
    int * v1695 = v1607->reg_ready;
    int v1696 = v1607->timer;
    v1695[22] = v1696;
    int * v1698 = v1607->reg_ready;
    int v1699 = v1607->timer;
    v1698[23] = v1699;
    int * v1701 = v1607->reg_ready;
    int v1702 = v1607->timer;
    v1701[24] = v1702;
    int * v1704 = v1607->reg_ready;
    int v1705 = v1607->timer;
    v1704[25] = v1705;
    int * v1707 = v1607->reg_ready;
    int v1708 = v1607->timer;
    v1707[26] = v1708;
    int * v1710 = v1607->reg_ready;
    int v1711 = v1607->timer;
    v1710[27] = v1711;
    int * v1713 = v1607->reg_ready;
    int v1714 = v1607->timer;
    v1713[28] = v1714;
    int * v1716 = v1607->reg_ready;
    int v1717 = v1607->timer;
    v1716[29] = v1717;
    int * v1719 = v1607->reg_ready;
    int v1720 = v1607->timer;
    v1719[30] = v1720;
    int * v1722 = v1607->reg_ready;
    int v1723 = v1607->timer;
    v1722[31] = v1723;
    struct StateT * v1725 = slot_25(v1607);
    v1729 = v1725;
  } else {
    struct StateT * v1727 = slot_26(v1607);
    v1729 = v1727;
  }
  return v1729;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->reg_ready;
  v5[12] = v11;
  int * v7 = v2->regs;
  v7[12] = 0;
  struct StateT * v9 = slot_1(v2);
  return v9;
}

struct StateT * slot_17(struct StateT * v1100) {
  int v1101 = v1100->timer;
  int v1104 = v1101 + 1;
  v1100->timer = v1104;
  return v1100;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v2115 = v1->timer;
  int * v2116 = v1->reg_ready;
  int v2117 = v2116[0];
  int v2248 = v2117 + ((v2115 - v2117) & (~((v2115 - v2117) >> 31)));
  v1->timer = v2248;
  int v2119 = v1->timer;
  int * v2120 = v1->reg_ready;
  int v2121 = v2120[1];
  int v2251 = v2121 + ((v2119 - v2121) & (~((v2119 - v2121) >> 31)));
  v1->timer = v2251;
  int v2123 = v1->timer;
  int * v2124 = v1->reg_ready;
  int v2125 = v2124[2];
  int v2254 = v2125 + ((v2123 - v2125) & (~((v2123 - v2125) >> 31)));
  v1->timer = v2254;
  int v2127 = v1->timer;
  int * v2128 = v1->reg_ready;
  int v2129 = v2128[3];
  int v2257 = v2129 + ((v2127 - v2129) & (~((v2127 - v2129) >> 31)));
  v1->timer = v2257;
  int v2131 = v1->timer;
  int * v2132 = v1->reg_ready;
  int v2133 = v2132[4];
  int v2260 = v2133 + ((v2131 - v2133) & (~((v2131 - v2133) >> 31)));
  v1->timer = v2260;
  int v2135 = v1->timer;
  int * v2136 = v1->reg_ready;
  int v2137 = v2136[5];
  int v2263 = v2137 + ((v2135 - v2137) & (~((v2135 - v2137) >> 31)));
  v1->timer = v2263;
  int v2139 = v1->timer;
  int * v2140 = v1->reg_ready;
  int v2141 = v2140[6];
  int v2266 = v2141 + ((v2139 - v2141) & (~((v2139 - v2141) >> 31)));
  v1->timer = v2266;
  int v2143 = v1->timer;
  int * v2144 = v1->reg_ready;
  int v2145 = v2144[7];
  int v2269 = v2145 + ((v2143 - v2145) & (~((v2143 - v2145) >> 31)));
  v1->timer = v2269;
  int v2147 = v1->timer;
  int * v2148 = v1->reg_ready;
  int v2149 = v2148[8];
  int v2272 = v2149 + ((v2147 - v2149) & (~((v2147 - v2149) >> 31)));
  v1->timer = v2272;
  int v2151 = v1->timer;
  int * v2152 = v1->reg_ready;
  int v2153 = v2152[9];
  int v2275 = v2153 + ((v2151 - v2153) & (~((v2151 - v2153) >> 31)));
  v1->timer = v2275;
  int v2155 = v1->timer;
  int * v2156 = v1->reg_ready;
  int v2157 = v2156[10];
  int v2278 = v2157 + ((v2155 - v2157) & (~((v2155 - v2157) >> 31)));
  v1->timer = v2278;
  int v2159 = v1->timer;
  int * v2160 = v1->reg_ready;
  int v2161 = v2160[11];
  int v2281 = v2161 + ((v2159 - v2161) & (~((v2159 - v2161) >> 31)));
  v1->timer = v2281;
  int v2163 = v1->timer;
  int * v2164 = v1->reg_ready;
  int v2165 = v2164[12];
  int v2284 = v2165 + ((v2163 - v2165) & (~((v2163 - v2165) >> 31)));
  v1->timer = v2284;
  int v2167 = v1->timer;
  int * v2168 = v1->reg_ready;
  int v2169 = v2168[13];
  int v2287 = v2169 + ((v2167 - v2169) & (~((v2167 - v2169) >> 31)));
  v1->timer = v2287;
  int v2171 = v1->timer;
  int * v2172 = v1->reg_ready;
  int v2173 = v2172[14];
  int v2290 = v2173 + ((v2171 - v2173) & (~((v2171 - v2173) >> 31)));
  v1->timer = v2290;
  int v2175 = v1->timer;
  int * v2176 = v1->reg_ready;
  int v2177 = v2176[15];
  int v2293 = v2177 + ((v2175 - v2177) & (~((v2175 - v2177) >> 31)));
  v1->timer = v2293;
  int v2179 = v1->timer;
  int * v2180 = v1->reg_ready;
  int v2181 = v2180[16];
  int v2296 = v2181 + ((v2179 - v2181) & (~((v2179 - v2181) >> 31)));
  v1->timer = v2296;
  int v2183 = v1->timer;
  int * v2184 = v1->reg_ready;
  int v2185 = v2184[17];
  int v2299 = v2185 + ((v2183 - v2185) & (~((v2183 - v2185) >> 31)));
  v1->timer = v2299;
  int v2187 = v1->timer;
  int * v2188 = v1->reg_ready;
  int v2189 = v2188[18];
  int v2302 = v2189 + ((v2187 - v2189) & (~((v2187 - v2189) >> 31)));
  v1->timer = v2302;
  int v2191 = v1->timer;
  int * v2192 = v1->reg_ready;
  int v2193 = v2192[19];
  int v2305 = v2193 + ((v2191 - v2193) & (~((v2191 - v2193) >> 31)));
  v1->timer = v2305;
  int v2195 = v1->timer;
  int * v2196 = v1->reg_ready;
  int v2197 = v2196[20];
  int v2308 = v2197 + ((v2195 - v2197) & (~((v2195 - v2197) >> 31)));
  v1->timer = v2308;
  int v2199 = v1->timer;
  int * v2200 = v1->reg_ready;
  int v2201 = v2200[21];
  int v2311 = v2201 + ((v2199 - v2201) & (~((v2199 - v2201) >> 31)));
  v1->timer = v2311;
  int v2203 = v1->timer;
  int * v2204 = v1->reg_ready;
  int v2205 = v2204[22];
  int v2314 = v2205 + ((v2203 - v2205) & (~((v2203 - v2205) >> 31)));
  v1->timer = v2314;
  int v2207 = v1->timer;
  int * v2208 = v1->reg_ready;
  int v2209 = v2208[23];
  int v2317 = v2209 + ((v2207 - v2209) & (~((v2207 - v2209) >> 31)));
  v1->timer = v2317;
  int v2211 = v1->timer;
  int * v2212 = v1->reg_ready;
  int v2213 = v2212[24];
  int v2320 = v2213 + ((v2211 - v2213) & (~((v2211 - v2213) >> 31)));
  v1->timer = v2320;
  int v2215 = v1->timer;
  int * v2216 = v1->reg_ready;
  int v2217 = v2216[25];
  int v2323 = v2217 + ((v2215 - v2217) & (~((v2215 - v2217) >> 31)));
  v1->timer = v2323;
  int v2219 = v1->timer;
  int * v2220 = v1->reg_ready;
  int v2221 = v2220[26];
  int v2326 = v2221 + ((v2219 - v2221) & (~((v2219 - v2221) >> 31)));
  v1->timer = v2326;
  int v2223 = v1->timer;
  int * v2224 = v1->reg_ready;
  int v2225 = v2224[27];
  int v2329 = v2225 + ((v2223 - v2225) & (~((v2223 - v2225) >> 31)));
  v1->timer = v2329;
  int v2227 = v1->timer;
  int * v2228 = v1->reg_ready;
  int v2229 = v2228[28];
  int v2332 = v2229 + ((v2227 - v2229) & (~((v2227 - v2229) >> 31)));
  v1->timer = v2332;
  int v2231 = v1->timer;
  int * v2232 = v1->reg_ready;
  int v2233 = v2232[29];
  int v2335 = v2233 + ((v2231 - v2233) & (~((v2231 - v2233) >> 31)));
  v1->timer = v2335;
  int v2235 = v1->timer;
  int * v2236 = v1->reg_ready;
  int v2237 = v2236[30];
  int v2338 = v2237 + ((v2235 - v2237) & (~((v2235 - v2237) >> 31)));
  v1->timer = v2338;
  int v2239 = v1->timer;
  int * v2240 = v1->reg_ready;
  int v2241 = v2240[31];
  int v2341 = v2241 + ((v2239 - v2241) & (~((v2239 - v2241) >> 31)));
  v1->timer = v2341;
  return v1;
}

struct StateT * slot_4(struct StateT * v66) {
  int v67 = v66->timer;
  int v71 = v67 + 1;
  v66->timer = v71;
  struct StateT * v69 = slot_5(v66);
  return v69;
}

struct StateT * slot_15(struct StateT * v1076) {
  int v1077 = v1076->timer;
  int v1085 = v1077 + 1;
  v1076->timer = v1085;
  int * v1079 = v1076->reg_ready;
  v1079[10] = v1085;
  int * v1081 = v1076->regs;
  v1081[10] = 0;
  struct StateT * v1083 = slot_17(v1076);
  return v1083;
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