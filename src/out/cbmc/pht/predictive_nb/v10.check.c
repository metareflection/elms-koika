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

struct StateT * slot_12(struct StateT * v775);
struct StateT * slot_14(struct StateT * v821);
struct StateT * slot_6(struct StateT * v305);
struct StateT * slot_16(struct StateT * v1243);
struct StateT * slot_5(struct StateT * v284);
struct StateT * slot_17(struct StateT * v1267);
struct StateT * slot_2(struct StateT * v225);
struct StateT * slot_7(struct StateT * v329);
struct StateT * slot_21(struct StateT * v1824);
struct StateT * slot_3(struct StateT * v233);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v767);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_8(struct StateT * v536);
struct StateT * slot_19(struct StateT * v1505);
struct StateT * slot_4(struct StateT * v261);
struct StateT * slot_13(struct StateT * v798);
struct StateT * slot_15(struct StateT * v1028);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v775) {
  int * v776 = v775->saved_regs;
  int * v777 = v775->regs;
  int v778 = v777[10];
  v776[10] = v778;
  int v780 = v775->timer;
  int v792 = v780 + 1;
  v775->timer = v792;
  int * v782 = v775->reg_ready;
  v782[10] = v792;
  int * v784 = v775->regs;
  v784[10] = 0;
  struct StateT * v786 = slot_13(v775);
  return v786;
}

struct StateT * slot_14(struct StateT * v821) {
  int v822 = v821->timer;
  int v934 = v822 + 1;
  v821->timer = v934;
  int * v824 = v821->reg_ready;
  int v825 = v824[10];
  int * v826 = v821->regs;
  int v827 = v826[10];
  int * v828 = v821->cache_tags;
  int v939 = (((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1)) & 1) * 2;
  int v829 = v828[v939];
  int v940 = ((((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v830 = v828[v940];
  int v941 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1)) & 3) * 2);
  int v831 = v828[v941];
  int v942 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v832 = v828[v942];
  int * v833 = v821->cache_vals;
  bool v943 = !(((~(((v829 ^ ((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1))) | (-(v829 ^ ((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v830 ^ ((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1))) | (-(v830 ^ ((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v926;
  if (v943) {
    int * v834 = v821->cache_age;
    int v945 = ((((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v830 ^ ((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1))) | (-(v830 ^ ((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v835 = v834[v945];
    int v836 = v834[v939];
    int v946 = v836 + ((int)((unsigned int)(v836 - v835) >> 31));
    v834[v939] = v946;
    int * v838 = v821->cache_age;
    int v839 = v838[v940];
    int v948 = v839 + ((int)((unsigned int)(v839 - v835) >> 31));
    v838[v940] = v948;
    int * v841 = v821->cache_age;
    v841[v945] = 0;
    v926 = v945;
  } else {
    int * v844 = v821->cache_age;
    int v952 = (((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1)) & 1) * 2;
    int v845 = v844[v952];
    int * v846 = v821->cache_tags;
    int v847 = v846[v952];
    int v848 = v844[v940];
    int v849 = v846[v940];
    bool v954 = !(((~(((v831 ^ ((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1))) | (-(v831 ^ ((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v832 ^ ((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1))) | (-(v832 ^ ((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v903;
    if (v954) {
      int * v850 = v821->cache_age;
      int v956 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v832 ^ ((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1))) | (-(v832 ^ ((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v851 = v850[v956];
      int v852 = v850[v941];
      int v957 = v852 + ((int)((unsigned int)(v852 - v851) >> 31));
      v850[v941] = v957;
      int * v854 = v821->cache_age;
      int v855 = v854[v942];
      int v959 = v855 + ((int)((unsigned int)(v855 - v851) >> 31));
      v854[v942] = v959;
      int * v857 = v821->cache_age;
      v857[v956] = 0;
      v903 = v956;
    } else {
      int * v860 = v821->cache_age;
      int v963 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1)) & 3) * 2);
      int v861 = v860[v963];
      int * v862 = v821->cache_tags;
      int v863 = v862[v963];
      int v864 = v860[v942];
      int v865 = v862[v942];
      int * v866 = v821->cache_dirty;
      int v966 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v861 + ((~(((v863 ^ -1) | (-(v863 ^ -1))) >> 31)) & 2)) - (v864 + ((~(((v865 ^ -1) | (-(v865 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v867 = v866[v966];
      bool v967 = !(v867 == 0);
      if (v967) {
        int * v868 = v821->cache_tags;
        int v869 = v868[v966];
        int * v870 = v821->cache_vals;
        int v970 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v861 + ((~(((v863 ^ -1) | (-(v863 ^ -1))) >> 31)) & 2)) - (v864 + ((~(((v865 ^ -1) | (-(v865 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v871 = v870[v970];
        int v971 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v861 + ((~(((v863 ^ -1) | (-(v863 ^ -1))) >> 31)) & 2)) - (v864 + ((~(((v865 ^ -1) | (-(v865 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v872 = v870[v971];
        int * v873 = v821->mem;
        int v973 = v869 * 2;
        v873[v973] = v871;
        int * v875 = v821->mem;
        int v976 = (v869 * 2) + 1;
        v875[v976] = v872;
        ;
      } else {
        ;
      }
      int * v880 = v821->mem;
      int v981 = ((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1)) * 2;
      int v881 = v880[v981];
      int v982 = (((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1)) * 2) + 1;
      int v882 = v880[v982];
      int * v883 = v821->cache_vals;
      int v984 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v861 + ((~(((v863 ^ -1) | (-(v863 ^ -1))) >> 31)) & 2)) - (v864 + ((~(((v865 ^ -1) | (-(v865 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v883[v984] = v881;
      int * v885 = v821->cache_vals;
      int v987 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v861 + ((~(((v863 ^ -1) | (-(v863 ^ -1))) >> 31)) & 2)) - (v864 + ((~(((v865 ^ -1) | (-(v865 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v885[v987] = v882;
      int * v887 = v821->cache_tags;
      int v990 = (int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1);
      v887[v966] = v990;
      int * v889 = v821->cache_dirty;
      v889[v966] = 0;
      int * v891 = v821->cache_age;
      v891[v966] = 1;
      int * v893 = v821->cache_age;
      int v894 = v893[v966];
      int v895 = v893[v941];
      int v996 = v895 + ((int)((unsigned int)(v895 - v894) >> 31));
      v893[v941] = v996;
      int * v897 = v821->cache_age;
      int v898 = v897[v942];
      int v998 = v898 + ((int)((unsigned int)(v898 - v894) >> 31));
      v897[v942] = v998;
      int * v900 = v821->cache_age;
      v900[v966] = 0;
      v903 = v966;
    }
    int * v904 = v821->cache_vals;
    int v1001 = v903 * 2;
    int v905 = v904[v1001];
    int v1002 = (v903 * 2) + 1;
    int v906 = v904[v1002];
    int v1003 = (((((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v845 + ((~(((v847 ^ -1) | (-(v847 ^ -1))) >> 31)) & 2)) - (v848 + ((~(((v849 ^ -1) | (-(v849 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v904[v1003] = v905;
    int * v908 = v821->cache_vals;
    int v1006 = ((((((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v845 + ((~(((v847 ^ -1) | (-(v847 ^ -1))) >> 31)) & 2)) - (v848 + ((~(((v849 ^ -1) | (-(v849 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v908[v1006] = v906;
    int * v910 = v821->cache_tags;
    int v1009 = ((((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v845 + ((~(((v847 ^ -1) | (-(v847 ^ -1))) >> 31)) & 2)) - (v848 + ((~(((v849 ^ -1) | (-(v849 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1010 = (int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1);
    v910[v1009] = v1010;
    int * v912 = v821->cache_dirty;
    v912[v1009] = 0;
    int * v914 = v821->cache_age;
    v914[v1009] = 1;
    int * v916 = v821->cache_age;
    int v917 = v916[v1009];
    int v918 = v916[v939];
    int v1016 = v918 + ((int)((unsigned int)(v918 - v917) >> 31));
    v916[v939] = v1016;
    int * v920 = v821->cache_age;
    int v921 = v920[v940];
    int v1018 = v921 + ((int)((unsigned int)(v921 - v917) >> 31));
    v920[v940] = v1018;
    int * v923 = v821->cache_age;
    v923[v1009] = 0;
    v926 = v1009;
  }
  int v1021 = (v926 * 2) + (((int)((unsigned int)(v827 + 4) >> 2)) & 1);
  int v927 = v833[v1021];
  int * v928 = v821->reg_ready;
  int v1023 = ((v825 + ((v822 - v825) & (~((v822 - v825) >> 31)))) + 1) + ((100 ^ (((~(((v831 ^ ((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1))) | (-(v831 ^ ((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v832 ^ ((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1))) | (-(v832 ^ ((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v829 ^ ((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1))) | (-(v829 ^ ((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v830 ^ ((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1))) | (-(v830 ^ ((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v831 ^ ((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1))) | (-(v831 ^ ((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v832 ^ ((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1))) | (-(v832 ^ ((int)((unsigned int)((int)((unsigned int)(v827 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v928[10] = v1023;
  int * v930 = v821->regs;
  v930[10] = v927;
  struct StateT * v932 = slot_15(v821);
  return v932;
}

struct StateT * slot_6(struct StateT * v305) {
  int v306 = v305->timer;
  int v319 = v306 + 1;
  v305->timer = v319;
  int * v308 = v305->reg_ready;
  int v309 = v308[12];
  int * v310 = v305->regs;
  int v311 = v310[12];
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

struct StateT * slot_16(struct StateT * v1243) {
  int v1244 = v1243->timer;
  int v1257 = v1244 + 1;
  v1243->timer = v1257;
  int * v1246 = v1243->reg_ready;
  int v1247 = v1246[12];
  int * v1248 = v1243->regs;
  int v1249 = v1248[12];
  int v1250 = v1246[10];
  int v1251 = v1248[10];
  int v1262 = (v1250 + (((v1247 + ((v1244 - v1247) & (~((v1244 - v1247) >> 31)))) - v1250) & (~(((v1247 + ((v1244 - v1247) & (~((v1244 - v1247) >> 31)))) - v1250) >> 31)))) + 1;
  v1246[10] = v1262;
  int * v1253 = v1243->regs;
  int v1264 = v1249 & v1251;
  v1253[10] = v1264;
  struct StateT * v1255 = slot_17(v1243);
  return v1255;
}

struct StateT * slot_5(struct StateT * v284) {
  int v285 = v284->timer;
  int v296 = v285 + 1;
  v284->timer = v296;
  int * v287 = v284->reg_ready;
  int v288 = v287[12];
  int * v289 = v284->regs;
  int v290 = v289[12];
  int v300 = (v288 + ((v285 - v288) & (~((v285 - v288) >> 31)))) + 1;
  v287[12] = v300;
  int * v292 = v284->regs;
  int v302 = v290 + 72;
  v292[12] = v302;
  struct StateT * v294 = slot_6(v284);
  return v294;
}

struct StateT * slot_17(struct StateT * v1267) {
  int * v1268 = v1267->saved_regs;
  int v1269 = v1268[10];
  int v1270 = v1268[11];
  bool v1390 = !(v1269 == v1270);
  struct StateT * v1385;
  if (v1390) {
    int v1271 = v1267->timer;
    int v1391 = v1271 + 15;
    v1267->timer = v1391;
    int * v1273 = v1267->saved_regs;
    int v1274 = v1273[10];
    int * v1275 = v1267->regs;
    v1275[10] = v1274;
    int * v1277 = v1267->saved_regs;
    int v1278 = v1277[11];
    int * v1279 = v1267->regs;
    v1279[11] = v1278;
    int * v1281 = v1267->saved_regs;
    int v1282 = v1281[12];
    int * v1283 = v1267->regs;
    v1283[12] = v1282;
    int * v1285 = v1267->reg_ready;
    int v1286 = v1267->timer;
    v1285[0] = v1286;
    int * v1288 = v1267->reg_ready;
    int v1289 = v1267->timer;
    v1288[1] = v1289;
    int * v1291 = v1267->reg_ready;
    int v1292 = v1267->timer;
    v1291[2] = v1292;
    int * v1294 = v1267->reg_ready;
    int v1295 = v1267->timer;
    v1294[3] = v1295;
    int * v1297 = v1267->reg_ready;
    int v1298 = v1267->timer;
    v1297[4] = v1298;
    int * v1300 = v1267->reg_ready;
    int v1301 = v1267->timer;
    v1300[5] = v1301;
    int * v1303 = v1267->reg_ready;
    int v1304 = v1267->timer;
    v1303[6] = v1304;
    int * v1306 = v1267->reg_ready;
    int v1307 = v1267->timer;
    v1306[7] = v1307;
    int * v1309 = v1267->reg_ready;
    int v1310 = v1267->timer;
    v1309[8] = v1310;
    int * v1312 = v1267->reg_ready;
    int v1313 = v1267->timer;
    v1312[9] = v1313;
    int * v1315 = v1267->reg_ready;
    int v1316 = v1267->timer;
    v1315[10] = v1316;
    int * v1318 = v1267->reg_ready;
    int v1319 = v1267->timer;
    v1318[11] = v1319;
    int * v1321 = v1267->reg_ready;
    int v1322 = v1267->timer;
    v1321[12] = v1322;
    int * v1324 = v1267->reg_ready;
    int v1325 = v1267->timer;
    v1324[13] = v1325;
    int * v1327 = v1267->reg_ready;
    int v1328 = v1267->timer;
    v1327[14] = v1328;
    int * v1330 = v1267->reg_ready;
    int v1331 = v1267->timer;
    v1330[15] = v1331;
    int * v1333 = v1267->reg_ready;
    int v1334 = v1267->timer;
    v1333[16] = v1334;
    int * v1336 = v1267->reg_ready;
    int v1337 = v1267->timer;
    v1336[17] = v1337;
    int * v1339 = v1267->reg_ready;
    int v1340 = v1267->timer;
    v1339[18] = v1340;
    int * v1342 = v1267->reg_ready;
    int v1343 = v1267->timer;
    v1342[19] = v1343;
    int * v1345 = v1267->reg_ready;
    int v1346 = v1267->timer;
    v1345[20] = v1346;
    int * v1348 = v1267->reg_ready;
    int v1349 = v1267->timer;
    v1348[21] = v1349;
    int * v1351 = v1267->reg_ready;
    int v1352 = v1267->timer;
    v1351[22] = v1352;
    int * v1354 = v1267->reg_ready;
    int v1355 = v1267->timer;
    v1354[23] = v1355;
    int * v1357 = v1267->reg_ready;
    int v1358 = v1267->timer;
    v1357[24] = v1358;
    int * v1360 = v1267->reg_ready;
    int v1361 = v1267->timer;
    v1360[25] = v1361;
    int * v1363 = v1267->reg_ready;
    int v1364 = v1267->timer;
    v1363[26] = v1364;
    int * v1366 = v1267->reg_ready;
    int v1367 = v1267->timer;
    v1366[27] = v1367;
    int * v1369 = v1267->reg_ready;
    int v1370 = v1267->timer;
    v1369[28] = v1370;
    int * v1372 = v1267->reg_ready;
    int v1373 = v1267->timer;
    v1372[29] = v1373;
    int * v1375 = v1267->reg_ready;
    int v1376 = v1267->timer;
    v1375[30] = v1376;
    int * v1378 = v1267->reg_ready;
    int v1379 = v1267->timer;
    v1378[31] = v1379;
    struct StateT * v1381 = slot_21(v1267);
    v1385 = v1381;
  } else {
    struct StateT * v1383 = slot_19(v1267);
    v1385 = v1383;
  }
  return v1385;
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

struct StateT * slot_21(struct StateT * v1824) {
  int v1825 = v1824->timer;
  int v1828 = v1825 + 1;
  v1824->timer = v1828;
  return v1824;
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

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v1829 = v1->timer;
  int * v1830 = v1->reg_ready;
  int v1831 = v1830[0];
  int v1962 = v1831 + ((v1829 - v1831) & (~((v1829 - v1831) >> 31)));
  v1->timer = v1962;
  int v1833 = v1->timer;
  int * v1834 = v1->reg_ready;
  int v1835 = v1834[1];
  int v1965 = v1835 + ((v1833 - v1835) & (~((v1833 - v1835) >> 31)));
  v1->timer = v1965;
  int v1837 = v1->timer;
  int * v1838 = v1->reg_ready;
  int v1839 = v1838[2];
  int v1968 = v1839 + ((v1837 - v1839) & (~((v1837 - v1839) >> 31)));
  v1->timer = v1968;
  int v1841 = v1->timer;
  int * v1842 = v1->reg_ready;
  int v1843 = v1842[3];
  int v1971 = v1843 + ((v1841 - v1843) & (~((v1841 - v1843) >> 31)));
  v1->timer = v1971;
  int v1845 = v1->timer;
  int * v1846 = v1->reg_ready;
  int v1847 = v1846[4];
  int v1974 = v1847 + ((v1845 - v1847) & (~((v1845 - v1847) >> 31)));
  v1->timer = v1974;
  int v1849 = v1->timer;
  int * v1850 = v1->reg_ready;
  int v1851 = v1850[5];
  int v1977 = v1851 + ((v1849 - v1851) & (~((v1849 - v1851) >> 31)));
  v1->timer = v1977;
  int v1853 = v1->timer;
  int * v1854 = v1->reg_ready;
  int v1855 = v1854[6];
  int v1980 = v1855 + ((v1853 - v1855) & (~((v1853 - v1855) >> 31)));
  v1->timer = v1980;
  int v1857 = v1->timer;
  int * v1858 = v1->reg_ready;
  int v1859 = v1858[7];
  int v1983 = v1859 + ((v1857 - v1859) & (~((v1857 - v1859) >> 31)));
  v1->timer = v1983;
  int v1861 = v1->timer;
  int * v1862 = v1->reg_ready;
  int v1863 = v1862[8];
  int v1986 = v1863 + ((v1861 - v1863) & (~((v1861 - v1863) >> 31)));
  v1->timer = v1986;
  int v1865 = v1->timer;
  int * v1866 = v1->reg_ready;
  int v1867 = v1866[9];
  int v1989 = v1867 + ((v1865 - v1867) & (~((v1865 - v1867) >> 31)));
  v1->timer = v1989;
  int v1869 = v1->timer;
  int * v1870 = v1->reg_ready;
  int v1871 = v1870[10];
  int v1992 = v1871 + ((v1869 - v1871) & (~((v1869 - v1871) >> 31)));
  v1->timer = v1992;
  int v1873 = v1->timer;
  int * v1874 = v1->reg_ready;
  int v1875 = v1874[11];
  int v1995 = v1875 + ((v1873 - v1875) & (~((v1873 - v1875) >> 31)));
  v1->timer = v1995;
  int v1877 = v1->timer;
  int * v1878 = v1->reg_ready;
  int v1879 = v1878[12];
  int v1998 = v1879 + ((v1877 - v1879) & (~((v1877 - v1879) >> 31)));
  v1->timer = v1998;
  int v1881 = v1->timer;
  int * v1882 = v1->reg_ready;
  int v1883 = v1882[13];
  int v2001 = v1883 + ((v1881 - v1883) & (~((v1881 - v1883) >> 31)));
  v1->timer = v2001;
  int v1885 = v1->timer;
  int * v1886 = v1->reg_ready;
  int v1887 = v1886[14];
  int v2004 = v1887 + ((v1885 - v1887) & (~((v1885 - v1887) >> 31)));
  v1->timer = v2004;
  int v1889 = v1->timer;
  int * v1890 = v1->reg_ready;
  int v1891 = v1890[15];
  int v2007 = v1891 + ((v1889 - v1891) & (~((v1889 - v1891) >> 31)));
  v1->timer = v2007;
  int v1893 = v1->timer;
  int * v1894 = v1->reg_ready;
  int v1895 = v1894[16];
  int v2010 = v1895 + ((v1893 - v1895) & (~((v1893 - v1895) >> 31)));
  v1->timer = v2010;
  int v1897 = v1->timer;
  int * v1898 = v1->reg_ready;
  int v1899 = v1898[17];
  int v2013 = v1899 + ((v1897 - v1899) & (~((v1897 - v1899) >> 31)));
  v1->timer = v2013;
  int v1901 = v1->timer;
  int * v1902 = v1->reg_ready;
  int v1903 = v1902[18];
  int v2016 = v1903 + ((v1901 - v1903) & (~((v1901 - v1903) >> 31)));
  v1->timer = v2016;
  int v1905 = v1->timer;
  int * v1906 = v1->reg_ready;
  int v1907 = v1906[19];
  int v2019 = v1907 + ((v1905 - v1907) & (~((v1905 - v1907) >> 31)));
  v1->timer = v2019;
  int v1909 = v1->timer;
  int * v1910 = v1->reg_ready;
  int v1911 = v1910[20];
  int v2022 = v1911 + ((v1909 - v1911) & (~((v1909 - v1911) >> 31)));
  v1->timer = v2022;
  int v1913 = v1->timer;
  int * v1914 = v1->reg_ready;
  int v1915 = v1914[21];
  int v2025 = v1915 + ((v1913 - v1915) & (~((v1913 - v1915) >> 31)));
  v1->timer = v2025;
  int v1917 = v1->timer;
  int * v1918 = v1->reg_ready;
  int v1919 = v1918[22];
  int v2028 = v1919 + ((v1917 - v1919) & (~((v1917 - v1919) >> 31)));
  v1->timer = v2028;
  int v1921 = v1->timer;
  int * v1922 = v1->reg_ready;
  int v1923 = v1922[23];
  int v2031 = v1923 + ((v1921 - v1923) & (~((v1921 - v1923) >> 31)));
  v1->timer = v2031;
  int v1925 = v1->timer;
  int * v1926 = v1->reg_ready;
  int v1927 = v1926[24];
  int v2034 = v1927 + ((v1925 - v1927) & (~((v1925 - v1927) >> 31)));
  v1->timer = v2034;
  int v1929 = v1->timer;
  int * v1930 = v1->reg_ready;
  int v1931 = v1930[25];
  int v2037 = v1931 + ((v1929 - v1931) & (~((v1929 - v1931) >> 31)));
  v1->timer = v2037;
  int v1933 = v1->timer;
  int * v1934 = v1->reg_ready;
  int v1935 = v1934[26];
  int v2040 = v1935 + ((v1933 - v1935) & (~((v1933 - v1935) >> 31)));
  v1->timer = v2040;
  int v1937 = v1->timer;
  int * v1938 = v1->reg_ready;
  int v1939 = v1938[27];
  int v2043 = v1939 + ((v1937 - v1939) & (~((v1937 - v1939) >> 31)));
  v1->timer = v2043;
  int v1941 = v1->timer;
  int * v1942 = v1->reg_ready;
  int v1943 = v1942[28];
  int v2046 = v1943 + ((v1941 - v1943) & (~((v1941 - v1943) >> 31)));
  v1->timer = v2046;
  int v1945 = v1->timer;
  int * v1946 = v1->reg_ready;
  int v1947 = v1946[29];
  int v2049 = v1947 + ((v1945 - v1947) & (~((v1945 - v1947) >> 31)));
  v1->timer = v2049;
  int v1949 = v1->timer;
  int * v1950 = v1->reg_ready;
  int v1951 = v1950[30];
  int v2052 = v1951 + ((v1949 - v1951) & (~((v1949 - v1951) >> 31)));
  v1->timer = v2052;
  int v1953 = v1->timer;
  int * v1954 = v1->reg_ready;
  int v1955 = v1954[31];
  int v2055 = v1955 + ((v1953 - v1955) & (~((v1953 - v1955) >> 31)));
  v1->timer = v2055;
  return v1;
}

struct StateT * slot_10(struct StateT * v767) {
  int v768 = v767->timer;
  int v772 = v768 + 1;
  v767->timer = v772;
  struct StateT * v770 = slot_12(v767);
  return v770;
}

struct StateT * slot_1(struct StateT * v18) {
  int v19 = v18->timer;
  int v131 = v19 + 1;
  v18->timer = v131;
  int * v21 = v18->reg_ready;
  int v22 = v21[12];
  int * v23 = v18->regs;
  int v24 = v23[12];
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
  v125[12] = v220;
  int * v127 = v18->regs;
  v127[12] = v124;
  struct StateT * v129 = slot_2(v18);
  return v129;
}

struct StateT * slot_8(struct StateT * v536) {
  int * v537 = v536->saved_regs;
  int v538 = v537[10];
  int v539 = v537[12];
  bool v655 = (v538 ^ -2147483648) >= (v539 ^ -2147483648);
  struct StateT * v650;
  if (v655) {
    int v540 = v536->timer;
    int v656 = v540 + 15;
    v536->timer = v656;
    int * v542 = v536->saved_regs;
    int v543 = v542[10];
    int * v544 = v536->regs;
    v544[10] = v543;
    int * v546 = v536->saved_regs;
    int v547 = v546[12];
    int * v548 = v536->regs;
    v548[12] = v547;
    int * v550 = v536->reg_ready;
    int v551 = v536->timer;
    v550[0] = v551;
    int * v553 = v536->reg_ready;
    int v554 = v536->timer;
    v553[1] = v554;
    int * v556 = v536->reg_ready;
    int v557 = v536->timer;
    v556[2] = v557;
    int * v559 = v536->reg_ready;
    int v560 = v536->timer;
    v559[3] = v560;
    int * v562 = v536->reg_ready;
    int v563 = v536->timer;
    v562[4] = v563;
    int * v565 = v536->reg_ready;
    int v566 = v536->timer;
    v565[5] = v566;
    int * v568 = v536->reg_ready;
    int v569 = v536->timer;
    v568[6] = v569;
    int * v571 = v536->reg_ready;
    int v572 = v536->timer;
    v571[7] = v572;
    int * v574 = v536->reg_ready;
    int v575 = v536->timer;
    v574[8] = v575;
    int * v577 = v536->reg_ready;
    int v578 = v536->timer;
    v577[9] = v578;
    int * v580 = v536->reg_ready;
    int v581 = v536->timer;
    v580[10] = v581;
    int * v583 = v536->reg_ready;
    int v584 = v536->timer;
    v583[11] = v584;
    int * v586 = v536->reg_ready;
    int v587 = v536->timer;
    v586[12] = v587;
    int * v589 = v536->reg_ready;
    int v590 = v536->timer;
    v589[13] = v590;
    int * v592 = v536->reg_ready;
    int v593 = v536->timer;
    v592[14] = v593;
    int * v595 = v536->reg_ready;
    int v596 = v536->timer;
    v595[15] = v596;
    int * v598 = v536->reg_ready;
    int v599 = v536->timer;
    v598[16] = v599;
    int * v601 = v536->reg_ready;
    int v602 = v536->timer;
    v601[17] = v602;
    int * v604 = v536->reg_ready;
    int v605 = v536->timer;
    v604[18] = v605;
    int * v607 = v536->reg_ready;
    int v608 = v536->timer;
    v607[19] = v608;
    int * v610 = v536->reg_ready;
    int v611 = v536->timer;
    v610[20] = v611;
    int * v613 = v536->reg_ready;
    int v614 = v536->timer;
    v613[21] = v614;
    int * v616 = v536->reg_ready;
    int v617 = v536->timer;
    v616[22] = v617;
    int * v619 = v536->reg_ready;
    int v620 = v536->timer;
    v619[23] = v620;
    int * v622 = v536->reg_ready;
    int v623 = v536->timer;
    v622[24] = v623;
    int * v625 = v536->reg_ready;
    int v626 = v536->timer;
    v625[25] = v626;
    int * v628 = v536->reg_ready;
    int v629 = v536->timer;
    v628[26] = v629;
    int * v631 = v536->reg_ready;
    int v632 = v536->timer;
    v631[27] = v632;
    int * v634 = v536->reg_ready;
    int v635 = v536->timer;
    v634[28] = v635;
    int * v637 = v536->reg_ready;
    int v638 = v536->timer;
    v637[29] = v638;
    int * v640 = v536->reg_ready;
    int v641 = v536->timer;
    v640[30] = v641;
    int * v643 = v536->reg_ready;
    int v644 = v536->timer;
    v643[31] = v644;
    struct StateT * v646 = slot_21(v536);
    v650 = v646;
  } else {
    struct StateT * v648 = slot_10(v536);
    v650 = v648;
  }
  return v650;
}

struct StateT * slot_19(struct StateT * v1505) {
  int v1506 = v1505->timer;
  int v1679 = v1506 + 1;
  v1505->timer = v1679;
  int * v1508 = v1505->reg_ready;
  int * v1510 = v1505->regs;
  int v1511 = v1510[11];
  int v1513 = v1510[10];
  int * v1514 = v1505->cache_tags;
  int v1685 = (((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1515 = v1514[v1685];
  int v1686 = ((((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1516 = v1514[v1686];
  int v1687 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1517 = v1514[v1687];
  int v1688 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1518 = v1514[v1688];
  int v1519 = v1505->timer;
  int v1689 = v1519 + ((100 ^ (((~(((v1517 ^ ((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1))) | (-(v1517 ^ ((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1518 ^ ((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1))) | (-(v1518 ^ ((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1515 ^ ((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1))) | (-(v1515 ^ ((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1516 ^ ((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1))) | (-(v1516 ^ ((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1517 ^ ((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1))) | (-(v1517 ^ ((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1518 ^ ((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1))) | (-(v1518 ^ ((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1505->timer = v1689;
  bool v1690 = !(((~(((v1515 ^ ((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1))) | (-(v1515 ^ ((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1516 ^ ((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1))) | (-(v1516 ^ ((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1613;
  if (v1690) {
    int * v1521 = v1505->cache_age;
    int v1692 = ((((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1516 ^ ((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1))) | (-(v1516 ^ ((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1522 = v1521[v1692];
    int v1523 = v1521[v1685];
    int v1693 = v1523 + ((int)((unsigned int)(v1523 - v1522) >> 31));
    v1521[v1685] = v1693;
    int * v1525 = v1505->cache_age;
    int v1526 = v1525[v1686];
    int v1695 = v1526 + ((int)((unsigned int)(v1526 - v1522) >> 31));
    v1525[v1686] = v1695;
    int * v1528 = v1505->cache_age;
    v1528[v1692] = 0;
    v1613 = v1692;
  } else {
    int * v1531 = v1505->cache_age;
    int v1699 = (((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1532 = v1531[v1699];
    int * v1533 = v1505->cache_tags;
    int v1534 = v1533[v1699];
    int v1535 = v1531[v1686];
    int v1536 = v1533[v1686];
    bool v1701 = !(((~(((v1517 ^ ((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1))) | (-(v1517 ^ ((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1518 ^ ((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1))) | (-(v1518 ^ ((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1590;
    if (v1701) {
      int * v1537 = v1505->cache_age;
      int v1703 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1518 ^ ((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1))) | (-(v1518 ^ ((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1538 = v1537[v1703];
      int v1539 = v1537[v1687];
      int v1704 = v1539 + ((int)((unsigned int)(v1539 - v1538) >> 31));
      v1537[v1687] = v1704;
      int * v1541 = v1505->cache_age;
      int v1542 = v1541[v1688];
      int v1706 = v1542 + ((int)((unsigned int)(v1542 - v1538) >> 31));
      v1541[v1688] = v1706;
      int * v1544 = v1505->cache_age;
      v1544[v1703] = 0;
      v1590 = v1703;
    } else {
      int * v1547 = v1505->cache_age;
      int v1710 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1548 = v1547[v1710];
      int * v1549 = v1505->cache_tags;
      int v1550 = v1549[v1710];
      int v1551 = v1547[v1688];
      int v1552 = v1549[v1688];
      int * v1553 = v1505->cache_dirty;
      int v1713 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1548 + ((~(((v1550 ^ -1) | (-(v1550 ^ -1))) >> 31)) & 2)) - (v1551 + ((~(((v1552 ^ -1) | (-(v1552 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1554 = v1553[v1713];
      bool v1714 = !(v1554 == 0);
      if (v1714) {
        int * v1555 = v1505->cache_tags;
        int v1556 = v1555[v1713];
        int * v1557 = v1505->cache_vals;
        int v1717 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1548 + ((~(((v1550 ^ -1) | (-(v1550 ^ -1))) >> 31)) & 2)) - (v1551 + ((~(((v1552 ^ -1) | (-(v1552 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1558 = v1557[v1717];
        int v1718 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1548 + ((~(((v1550 ^ -1) | (-(v1550 ^ -1))) >> 31)) & 2)) - (v1551 + ((~(((v1552 ^ -1) | (-(v1552 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1559 = v1557[v1718];
        int * v1560 = v1505->mem;
        int v1720 = v1556 * 2;
        v1560[v1720] = v1558;
        int * v1562 = v1505->mem;
        int v1723 = (v1556 * 2) + 1;
        v1562[v1723] = v1559;
        ;
      } else {
        ;
      }
      int * v1567 = v1505->mem;
      int v1728 = ((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1)) * 2;
      int v1568 = v1567[v1728];
      int v1729 = (((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1569 = v1567[v1729];
      int * v1570 = v1505->cache_vals;
      int v1731 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1548 + ((~(((v1550 ^ -1) | (-(v1550 ^ -1))) >> 31)) & 2)) - (v1551 + ((~(((v1552 ^ -1) | (-(v1552 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1570[v1731] = v1568;
      int * v1572 = v1505->cache_vals;
      int v1734 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1548 + ((~(((v1550 ^ -1) | (-(v1550 ^ -1))) >> 31)) & 2)) - (v1551 + ((~(((v1552 ^ -1) | (-(v1552 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1572[v1734] = v1569;
      int * v1574 = v1505->cache_tags;
      int v1737 = (int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1);
      v1574[v1713] = v1737;
      int * v1576 = v1505->cache_dirty;
      v1576[v1713] = 0;
      int * v1578 = v1505->cache_age;
      v1578[v1713] = 1;
      int * v1580 = v1505->cache_age;
      int v1581 = v1580[v1713];
      int v1582 = v1580[v1687];
      int v1743 = v1582 + ((int)((unsigned int)(v1582 - v1581) >> 31));
      v1580[v1687] = v1743;
      int * v1584 = v1505->cache_age;
      int v1585 = v1584[v1688];
      int v1745 = v1585 + ((int)((unsigned int)(v1585 - v1581) >> 31));
      v1584[v1688] = v1745;
      int * v1587 = v1505->cache_age;
      v1587[v1713] = 0;
      v1590 = v1713;
    }
    int * v1591 = v1505->cache_vals;
    int v1748 = v1590 * 2;
    int v1592 = v1591[v1748];
    int v1749 = (v1590 * 2) + 1;
    int v1593 = v1591[v1749];
    int v1750 = (((((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1532 + ((~(((v1534 ^ -1) | (-(v1534 ^ -1))) >> 31)) & 2)) - (v1535 + ((~(((v1536 ^ -1) | (-(v1536 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1591[v1750] = v1592;
    int * v1595 = v1505->cache_vals;
    int v1753 = ((((((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1532 + ((~(((v1534 ^ -1) | (-(v1534 ^ -1))) >> 31)) & 2)) - (v1535 + ((~(((v1536 ^ -1) | (-(v1536 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1595[v1753] = v1593;
    int * v1597 = v1505->cache_tags;
    int v1756 = ((((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1532 + ((~(((v1534 ^ -1) | (-(v1534 ^ -1))) >> 31)) & 2)) - (v1535 + ((~(((v1536 ^ -1) | (-(v1536 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1757 = (int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1);
    v1597[v1756] = v1757;
    int * v1599 = v1505->cache_dirty;
    v1599[v1756] = 0;
    int * v1601 = v1505->cache_age;
    v1601[v1756] = 1;
    int * v1603 = v1505->cache_age;
    int v1604 = v1603[v1756];
    int v1605 = v1603[v1685];
    int v1763 = v1605 + ((int)((unsigned int)(v1605 - v1604) >> 31));
    v1603[v1685] = v1763;
    int * v1607 = v1505->cache_age;
    int v1608 = v1607[v1686];
    int v1765 = v1608 + ((int)((unsigned int)(v1608 - v1604) >> 31));
    v1607[v1686] = v1765;
    int * v1610 = v1505->cache_age;
    v1610[v1756] = 0;
    v1613 = v1756;
  }
  int * v1614 = v1505->cache_vals;
  int v1768 = (v1613 * 2) + (((int)((unsigned int)(v1511 + 68) >> 2)) & 1);
  v1614[v1768] = v1513;
  int * v1616 = v1505->cache_tags;
  int v1617 = v1616[v1687];
  int v1618 = v1616[v1688];
  bool v1771 = !(((~(((v1617 ^ ((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1))) | (-(v1617 ^ ((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1618 ^ ((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1))) | (-(v1618 ^ ((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1672;
  if (v1771) {
    int * v1619 = v1505->cache_age;
    int v1773 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1618 ^ ((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1))) | (-(v1618 ^ ((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1620 = v1619[v1773];
    int v1621 = v1619[v1687];
    int v1774 = v1621 + ((int)((unsigned int)(v1621 - v1620) >> 31));
    v1619[v1687] = v1774;
    int * v1623 = v1505->cache_age;
    int v1624 = v1623[v1688];
    int v1776 = v1624 + ((int)((unsigned int)(v1624 - v1620) >> 31));
    v1623[v1688] = v1776;
    int * v1626 = v1505->cache_age;
    v1626[v1773] = 0;
    v1672 = v1773;
  } else {
    int * v1629 = v1505->cache_age;
    int v1780 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1630 = v1629[v1780];
    int * v1631 = v1505->cache_tags;
    int v1632 = v1631[v1780];
    int v1633 = v1629[v1688];
    int v1634 = v1631[v1688];
    int * v1635 = v1505->cache_dirty;
    int v1783 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1630 + ((~(((v1632 ^ -1) | (-(v1632 ^ -1))) >> 31)) & 2)) - (v1633 + ((~(((v1634 ^ -1) | (-(v1634 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1636 = v1635[v1783];
    bool v1784 = !(v1636 == 0);
    if (v1784) {
      int * v1637 = v1505->cache_tags;
      int v1638 = v1637[v1783];
      int * v1639 = v1505->cache_vals;
      int v1787 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1630 + ((~(((v1632 ^ -1) | (-(v1632 ^ -1))) >> 31)) & 2)) - (v1633 + ((~(((v1634 ^ -1) | (-(v1634 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1640 = v1639[v1787];
      int v1788 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1630 + ((~(((v1632 ^ -1) | (-(v1632 ^ -1))) >> 31)) & 2)) - (v1633 + ((~(((v1634 ^ -1) | (-(v1634 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1641 = v1639[v1788];
      int * v1642 = v1505->mem;
      int v1790 = v1638 * 2;
      v1642[v1790] = v1640;
      int * v1644 = v1505->mem;
      int v1793 = (v1638 * 2) + 1;
      v1644[v1793] = v1641;
      ;
    } else {
      ;
    }
    int * v1649 = v1505->mem;
    int v1798 = ((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1)) * 2;
    int v1650 = v1649[v1798];
    int v1799 = (((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1651 = v1649[v1799];
    int * v1652 = v1505->cache_vals;
    int v1801 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1630 + ((~(((v1632 ^ -1) | (-(v1632 ^ -1))) >> 31)) & 2)) - (v1633 + ((~(((v1634 ^ -1) | (-(v1634 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1652[v1801] = v1650;
    int * v1654 = v1505->cache_vals;
    int v1804 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1630 + ((~(((v1632 ^ -1) | (-(v1632 ^ -1))) >> 31)) & 2)) - (v1633 + ((~(((v1634 ^ -1) | (-(v1634 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1654[v1804] = v1651;
    int * v1656 = v1505->cache_tags;
    int v1807 = (int)((unsigned int)((int)((unsigned int)(v1511 + 68) >> 2)) >> 1);
    v1656[v1783] = v1807;
    int * v1658 = v1505->cache_dirty;
    v1658[v1783] = 0;
    int * v1660 = v1505->cache_age;
    v1660[v1783] = 1;
    int * v1662 = v1505->cache_age;
    int v1663 = v1662[v1783];
    int v1664 = v1662[v1687];
    int v1813 = v1664 + ((int)((unsigned int)(v1664 - v1663) >> 31));
    v1662[v1687] = v1813;
    int * v1666 = v1505->cache_age;
    int v1667 = v1666[v1688];
    int v1815 = v1667 + ((int)((unsigned int)(v1667 - v1663) >> 31));
    v1666[v1688] = v1815;
    int * v1669 = v1505->cache_age;
    v1669[v1783] = 0;
    v1672 = v1783;
  }
  int * v1673 = v1505->cache_vals;
  int v1818 = (v1672 * 2) + (((int)((unsigned int)(v1511 + 68) >> 2)) & 1);
  v1673[v1818] = v1513;
  int * v1675 = v1505->cache_dirty;
  v1675[v1672] = 1;
  struct StateT * v1677 = slot_21(v1505);
  return v1677;
}

struct StateT * slot_4(struct StateT * v261) {
  int * v262 = v261->saved_regs;
  int * v263 = v261->regs;
  int v264 = v263[12];
  v262[12] = v264;
  int v266 = v261->timer;
  int v278 = v266 + 1;
  v261->timer = v278;
  int * v268 = v261->reg_ready;
  v268[12] = v278;
  int * v270 = v261->regs;
  v270[12] = 0;
  struct StateT * v272 = slot_5(v261);
  return v272;
}

struct StateT * slot_13(struct StateT * v798) {
  int * v799 = v798->saved_regs;
  int * v800 = v798->regs;
  int v801 = v800[11];
  v799[11] = v801;
  int v803 = v798->timer;
  int v815 = v803 + 1;
  v798->timer = v815;
  int * v805 = v798->reg_ready;
  v805[11] = v815;
  int * v807 = v798->regs;
  v807[11] = 0;
  struct StateT * v809 = slot_14(v798);
  return v809;
}

struct StateT * slot_15(struct StateT * v1028) {
  int * v1029 = v1028->saved_regs;
  int * v1030 = v1028->regs;
  int v1031 = v1030[12];
  v1029[12] = v1031;
  int v1033 = v1028->timer;
  int v1149 = v1033 + 1;
  v1028->timer = v1149;
  int * v1035 = v1028->reg_ready;
  int v1036 = v1035[11];
  int * v1037 = v1028->regs;
  int v1038 = v1037[11];
  int * v1039 = v1028->cache_tags;
  int v1154 = (((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1040 = v1039[v1154];
  int v1155 = ((((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1041 = v1039[v1155];
  int v1156 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1042 = v1039[v1156];
  int v1157 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1043 = v1039[v1157];
  int * v1044 = v1028->cache_vals;
  bool v1158 = !(((~(((v1040 ^ ((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1))) | (-(v1040 ^ ((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1041 ^ ((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1))) | (-(v1041 ^ ((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1137;
  if (v1158) {
    int * v1045 = v1028->cache_age;
    int v1160 = ((((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1041 ^ ((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1))) | (-(v1041 ^ ((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1046 = v1045[v1160];
    int v1047 = v1045[v1154];
    int v1161 = v1047 + ((int)((unsigned int)(v1047 - v1046) >> 31));
    v1045[v1154] = v1161;
    int * v1049 = v1028->cache_age;
    int v1050 = v1049[v1155];
    int v1163 = v1050 + ((int)((unsigned int)(v1050 - v1046) >> 31));
    v1049[v1155] = v1163;
    int * v1052 = v1028->cache_age;
    v1052[v1160] = 0;
    v1137 = v1160;
  } else {
    int * v1055 = v1028->cache_age;
    int v1167 = (((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1056 = v1055[v1167];
    int * v1057 = v1028->cache_tags;
    int v1058 = v1057[v1167];
    int v1059 = v1055[v1155];
    int v1060 = v1057[v1155];
    bool v1169 = !(((~(((v1042 ^ ((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1))) | (-(v1042 ^ ((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1043 ^ ((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1))) | (-(v1043 ^ ((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1114;
    if (v1169) {
      int * v1061 = v1028->cache_age;
      int v1171 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1043 ^ ((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1))) | (-(v1043 ^ ((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1062 = v1061[v1171];
      int v1063 = v1061[v1156];
      int v1172 = v1063 + ((int)((unsigned int)(v1063 - v1062) >> 31));
      v1061[v1156] = v1172;
      int * v1065 = v1028->cache_age;
      int v1066 = v1065[v1157];
      int v1174 = v1066 + ((int)((unsigned int)(v1066 - v1062) >> 31));
      v1065[v1157] = v1174;
      int * v1068 = v1028->cache_age;
      v1068[v1171] = 0;
      v1114 = v1171;
    } else {
      int * v1071 = v1028->cache_age;
      int v1178 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1072 = v1071[v1178];
      int * v1073 = v1028->cache_tags;
      int v1074 = v1073[v1178];
      int v1075 = v1071[v1157];
      int v1076 = v1073[v1157];
      int * v1077 = v1028->cache_dirty;
      int v1181 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1072 + ((~(((v1074 ^ -1) | (-(v1074 ^ -1))) >> 31)) & 2)) - (v1075 + ((~(((v1076 ^ -1) | (-(v1076 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1078 = v1077[v1181];
      bool v1182 = !(v1078 == 0);
      if (v1182) {
        int * v1079 = v1028->cache_tags;
        int v1080 = v1079[v1181];
        int * v1081 = v1028->cache_vals;
        int v1185 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1072 + ((~(((v1074 ^ -1) | (-(v1074 ^ -1))) >> 31)) & 2)) - (v1075 + ((~(((v1076 ^ -1) | (-(v1076 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1082 = v1081[v1185];
        int v1186 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1072 + ((~(((v1074 ^ -1) | (-(v1074 ^ -1))) >> 31)) & 2)) - (v1075 + ((~(((v1076 ^ -1) | (-(v1076 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1083 = v1081[v1186];
        int * v1084 = v1028->mem;
        int v1188 = v1080 * 2;
        v1084[v1188] = v1082;
        int * v1086 = v1028->mem;
        int v1191 = (v1080 * 2) + 1;
        v1086[v1191] = v1083;
        ;
      } else {
        ;
      }
      int * v1091 = v1028->mem;
      int v1196 = ((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1)) * 2;
      int v1092 = v1091[v1196];
      int v1197 = (((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1093 = v1091[v1197];
      int * v1094 = v1028->cache_vals;
      int v1199 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1072 + ((~(((v1074 ^ -1) | (-(v1074 ^ -1))) >> 31)) & 2)) - (v1075 + ((~(((v1076 ^ -1) | (-(v1076 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1094[v1199] = v1092;
      int * v1096 = v1028->cache_vals;
      int v1202 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1072 + ((~(((v1074 ^ -1) | (-(v1074 ^ -1))) >> 31)) & 2)) - (v1075 + ((~(((v1076 ^ -1) | (-(v1076 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1096[v1202] = v1093;
      int * v1098 = v1028->cache_tags;
      int v1205 = (int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1);
      v1098[v1181] = v1205;
      int * v1100 = v1028->cache_dirty;
      v1100[v1181] = 0;
      int * v1102 = v1028->cache_age;
      v1102[v1181] = 1;
      int * v1104 = v1028->cache_age;
      int v1105 = v1104[v1181];
      int v1106 = v1104[v1156];
      int v1211 = v1106 + ((int)((unsigned int)(v1106 - v1105) >> 31));
      v1104[v1156] = v1211;
      int * v1108 = v1028->cache_age;
      int v1109 = v1108[v1157];
      int v1213 = v1109 + ((int)((unsigned int)(v1109 - v1105) >> 31));
      v1108[v1157] = v1213;
      int * v1111 = v1028->cache_age;
      v1111[v1181] = 0;
      v1114 = v1181;
    }
    int * v1115 = v1028->cache_vals;
    int v1216 = v1114 * 2;
    int v1116 = v1115[v1216];
    int v1217 = (v1114 * 2) + 1;
    int v1117 = v1115[v1217];
    int v1218 = (((((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1056 + ((~(((v1058 ^ -1) | (-(v1058 ^ -1))) >> 31)) & 2)) - (v1059 + ((~(((v1060 ^ -1) | (-(v1060 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1115[v1218] = v1116;
    int * v1119 = v1028->cache_vals;
    int v1221 = ((((((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1056 + ((~(((v1058 ^ -1) | (-(v1058 ^ -1))) >> 31)) & 2)) - (v1059 + ((~(((v1060 ^ -1) | (-(v1060 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1119[v1221] = v1117;
    int * v1121 = v1028->cache_tags;
    int v1224 = ((((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1056 + ((~(((v1058 ^ -1) | (-(v1058 ^ -1))) >> 31)) & 2)) - (v1059 + ((~(((v1060 ^ -1) | (-(v1060 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1225 = (int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1);
    v1121[v1224] = v1225;
    int * v1123 = v1028->cache_dirty;
    v1123[v1224] = 0;
    int * v1125 = v1028->cache_age;
    v1125[v1224] = 1;
    int * v1127 = v1028->cache_age;
    int v1128 = v1127[v1224];
    int v1129 = v1127[v1154];
    int v1231 = v1129 + ((int)((unsigned int)(v1129 - v1128) >> 31));
    v1127[v1154] = v1231;
    int * v1131 = v1028->cache_age;
    int v1132 = v1131[v1155];
    int v1233 = v1132 + ((int)((unsigned int)(v1132 - v1128) >> 31));
    v1131[v1155] = v1233;
    int * v1134 = v1028->cache_age;
    v1134[v1224] = 0;
    v1137 = v1224;
  }
  int v1236 = (v1137 * 2) + (((int)((unsigned int)(v1038 + 68) >> 2)) & 1);
  int v1138 = v1044[v1236];
  int * v1139 = v1028->reg_ready;
  int v1238 = ((v1036 + ((v1033 - v1036) & (~((v1033 - v1036) >> 31)))) + 1) + ((100 ^ (((~(((v1042 ^ ((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1))) | (-(v1042 ^ ((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1043 ^ ((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1))) | (-(v1043 ^ ((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1040 ^ ((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1))) | (-(v1040 ^ ((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1041 ^ ((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1))) | (-(v1041 ^ ((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1042 ^ ((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1))) | (-(v1042 ^ ((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1043 ^ ((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1))) | (-(v1043 ^ ((int)((unsigned int)((int)((unsigned int)(v1038 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1139[12] = v1238;
  int * v1141 = v1028->regs;
  v1141[12] = v1138;
  struct StateT * v1143 = slot_16(v1028);
  return v1143;
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
  int k = bounded(0, 20);
  s1.regs[11] = k;
  s2.regs[11] = k;
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