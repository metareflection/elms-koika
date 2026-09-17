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
#else
#define koika_assert(b, s) 0
#define koika_assume(b) 0
#define koika_draw(x) ((x) = 0)
#endif
int bounded(int low, int high) {
  int x;
  koika_draw(x);
  koika_assume(low <= x && x <= high);
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
  int reg_ready[32];
  int cache_tags[12];
  int cache_dirty[12];
  int cache_age[12];
  int cache_vals[24];
  int timer;
};

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v242);
struct StateT * slot_6(struct StateT * v790);
struct StateT * slot_5(struct StateT * v551);
struct StateT * slot_4(struct StateT * v315);
struct StateT * slot_2(struct StateT * v267);
struct StateT * slot_7(struct StateT * v1045);
struct StateT * slot_3(struct StateT * v291);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v1278 = v1->timer;
  int * v1279 = v1->reg_ready;
  int v1280 = v1279[0];
  int v1411 = v1280 + ((v1278 - v1280) & (~((v1278 - v1280) >> 31)));
  v1->timer = v1411;
  int v1282 = v1->timer;
  int * v1283 = v1->reg_ready;
  int v1284 = v1283[1];
  int v1414 = v1284 + ((v1282 - v1284) & (~((v1282 - v1284) >> 31)));
  v1->timer = v1414;
  int v1286 = v1->timer;
  int * v1287 = v1->reg_ready;
  int v1288 = v1287[2];
  int v1417 = v1288 + ((v1286 - v1288) & (~((v1286 - v1288) >> 31)));
  v1->timer = v1417;
  int v1290 = v1->timer;
  int * v1291 = v1->reg_ready;
  int v1292 = v1291[3];
  int v1420 = v1292 + ((v1290 - v1292) & (~((v1290 - v1292) >> 31)));
  v1->timer = v1420;
  int v1294 = v1->timer;
  int * v1295 = v1->reg_ready;
  int v1296 = v1295[4];
  int v1423 = v1296 + ((v1294 - v1296) & (~((v1294 - v1296) >> 31)));
  v1->timer = v1423;
  int v1298 = v1->timer;
  int * v1299 = v1->reg_ready;
  int v1300 = v1299[5];
  int v1426 = v1300 + ((v1298 - v1300) & (~((v1298 - v1300) >> 31)));
  v1->timer = v1426;
  int v1302 = v1->timer;
  int * v1303 = v1->reg_ready;
  int v1304 = v1303[6];
  int v1429 = v1304 + ((v1302 - v1304) & (~((v1302 - v1304) >> 31)));
  v1->timer = v1429;
  int v1306 = v1->timer;
  int * v1307 = v1->reg_ready;
  int v1308 = v1307[7];
  int v1432 = v1308 + ((v1306 - v1308) & (~((v1306 - v1308) >> 31)));
  v1->timer = v1432;
  int v1310 = v1->timer;
  int * v1311 = v1->reg_ready;
  int v1312 = v1311[8];
  int v1435 = v1312 + ((v1310 - v1312) & (~((v1310 - v1312) >> 31)));
  v1->timer = v1435;
  int v1314 = v1->timer;
  int * v1315 = v1->reg_ready;
  int v1316 = v1315[9];
  int v1438 = v1316 + ((v1314 - v1316) & (~((v1314 - v1316) >> 31)));
  v1->timer = v1438;
  int v1318 = v1->timer;
  int * v1319 = v1->reg_ready;
  int v1320 = v1319[10];
  int v1441 = v1320 + ((v1318 - v1320) & (~((v1318 - v1320) >> 31)));
  v1->timer = v1441;
  int v1322 = v1->timer;
  int * v1323 = v1->reg_ready;
  int v1324 = v1323[11];
  int v1444 = v1324 + ((v1322 - v1324) & (~((v1322 - v1324) >> 31)));
  v1->timer = v1444;
  int v1326 = v1->timer;
  int * v1327 = v1->reg_ready;
  int v1328 = v1327[12];
  int v1447 = v1328 + ((v1326 - v1328) & (~((v1326 - v1328) >> 31)));
  v1->timer = v1447;
  int v1330 = v1->timer;
  int * v1331 = v1->reg_ready;
  int v1332 = v1331[13];
  int v1450 = v1332 + ((v1330 - v1332) & (~((v1330 - v1332) >> 31)));
  v1->timer = v1450;
  int v1334 = v1->timer;
  int * v1335 = v1->reg_ready;
  int v1336 = v1335[14];
  int v1453 = v1336 + ((v1334 - v1336) & (~((v1334 - v1336) >> 31)));
  v1->timer = v1453;
  int v1338 = v1->timer;
  int * v1339 = v1->reg_ready;
  int v1340 = v1339[15];
  int v1456 = v1340 + ((v1338 - v1340) & (~((v1338 - v1340) >> 31)));
  v1->timer = v1456;
  int v1342 = v1->timer;
  int * v1343 = v1->reg_ready;
  int v1344 = v1343[16];
  int v1459 = v1344 + ((v1342 - v1344) & (~((v1342 - v1344) >> 31)));
  v1->timer = v1459;
  int v1346 = v1->timer;
  int * v1347 = v1->reg_ready;
  int v1348 = v1347[17];
  int v1462 = v1348 + ((v1346 - v1348) & (~((v1346 - v1348) >> 31)));
  v1->timer = v1462;
  int v1350 = v1->timer;
  int * v1351 = v1->reg_ready;
  int v1352 = v1351[18];
  int v1465 = v1352 + ((v1350 - v1352) & (~((v1350 - v1352) >> 31)));
  v1->timer = v1465;
  int v1354 = v1->timer;
  int * v1355 = v1->reg_ready;
  int v1356 = v1355[19];
  int v1468 = v1356 + ((v1354 - v1356) & (~((v1354 - v1356) >> 31)));
  v1->timer = v1468;
  int v1358 = v1->timer;
  int * v1359 = v1->reg_ready;
  int v1360 = v1359[20];
  int v1471 = v1360 + ((v1358 - v1360) & (~((v1358 - v1360) >> 31)));
  v1->timer = v1471;
  int v1362 = v1->timer;
  int * v1363 = v1->reg_ready;
  int v1364 = v1363[21];
  int v1474 = v1364 + ((v1362 - v1364) & (~((v1362 - v1364) >> 31)));
  v1->timer = v1474;
  int v1366 = v1->timer;
  int * v1367 = v1->reg_ready;
  int v1368 = v1367[22];
  int v1477 = v1368 + ((v1366 - v1368) & (~((v1366 - v1368) >> 31)));
  v1->timer = v1477;
  int v1370 = v1->timer;
  int * v1371 = v1->reg_ready;
  int v1372 = v1371[23];
  int v1480 = v1372 + ((v1370 - v1372) & (~((v1370 - v1372) >> 31)));
  v1->timer = v1480;
  int v1374 = v1->timer;
  int * v1375 = v1->reg_ready;
  int v1376 = v1375[24];
  int v1483 = v1376 + ((v1374 - v1376) & (~((v1374 - v1376) >> 31)));
  v1->timer = v1483;
  int v1378 = v1->timer;
  int * v1379 = v1->reg_ready;
  int v1380 = v1379[25];
  int v1486 = v1380 + ((v1378 - v1380) & (~((v1378 - v1380) >> 31)));
  v1->timer = v1486;
  int v1382 = v1->timer;
  int * v1383 = v1->reg_ready;
  int v1384 = v1383[26];
  int v1489 = v1384 + ((v1382 - v1384) & (~((v1382 - v1384) >> 31)));
  v1->timer = v1489;
  int v1386 = v1->timer;
  int * v1387 = v1->reg_ready;
  int v1388 = v1387[27];
  int v1492 = v1388 + ((v1386 - v1388) & (~((v1386 - v1388) >> 31)));
  v1->timer = v1492;
  int v1390 = v1->timer;
  int * v1391 = v1->reg_ready;
  int v1392 = v1391[28];
  int v1495 = v1392 + ((v1390 - v1392) & (~((v1390 - v1392) >> 31)));
  v1->timer = v1495;
  int v1394 = v1->timer;
  int * v1395 = v1->reg_ready;
  int v1396 = v1395[29];
  int v1498 = v1396 + ((v1394 - v1396) & (~((v1394 - v1396) >> 31)));
  v1->timer = v1498;
  int v1398 = v1->timer;
  int * v1399 = v1->reg_ready;
  int v1400 = v1399[30];
  int v1501 = v1400 + ((v1398 - v1400) & (~((v1398 - v1400) >> 31)));
  v1->timer = v1501;
  int v1402 = v1->timer;
  int * v1403 = v1->reg_ready;
  int v1404 = v1403[31];
  int v1504 = v1404 + ((v1402 - v1404) & (~((v1402 - v1404) >> 31)));
  v1->timer = v1504;
  return v1;
}

struct StateT * slot_1(struct StateT * v242) {
  int v243 = v242->timer;
  int v244 = v242->timer;
  int v256 = v244 + 1;
  v242->timer = v256;
  int * v246 = v242->reg_ready;
  int v247 = v246[5];
  int * v248 = v242->regs;
  int v249 = v248[5];
  int * v250 = v242->reg_ready;
  int v262 = (v247 + ((v243 - v247) & (~((v243 - v247) >> 31)))) + 1;
  v250[6] = v262;
  int * v252 = v242->regs;
  int v264 = v249 & 1;
  v252[6] = v264;
  struct StateT * v254 = slot_2(v242);
  return v254;
}

struct StateT * slot_6(struct StateT * v790) {
  int v791 = v790->timer;
  int v792 = v790->timer;
  int v927 = v792 + 1;
  v790->timer = v927;
  int * v794 = v790->reg_ready;
  int v795 = v794[6];
  int * v796 = v790->regs;
  int v797 = v796[6];
  int * v798 = v790->cache_tags;
  int v932 = (((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1)) & 1) * 2;
  int v799 = v798[v932];
  int * v800 = v790->cache_tags;
  int v934 = ((((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1)) & 1) * 2) + 1;
  int v801 = v800[v934];
  int * v802 = v790->cache_tags;
  int v936 = 4 + ((((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1)) & 3) * 2);
  int v803 = v802[v936];
  int * v804 = v790->cache_tags;
  int v938 = (4 + ((((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v805 = v804[v938];
  int * v806 = v790->cache_vals;
  bool v939 = !(((~(((v799 ^ ((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1))) | (-(v799 ^ ((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1))))) >> 31)) | (~(((v801 ^ ((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1))) | (-(v801 ^ ((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1))))) >> 31))) == 0);
  int v919;
  if (v939) {
    int * v807 = v790->cache_age;
    int v941 = ((((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1)) & 1) * 2) + ((~(((v801 ^ ((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1))) | (-(v801 ^ ((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1))))) >> 31)) & 1);
    int v808 = v807[v941];
    int * v809 = v790->cache_age;
    int v810 = v809[v932];
    int * v811 = v790->cache_age;
    int v944 = v810 + ((int)((unsigned int)(v810 - v808) >> 31));
    v811[v932] = v944;
    int * v813 = v790->cache_age;
    int v814 = v813[v934];
    int * v815 = v790->cache_age;
    int v947 = v814 + ((int)((unsigned int)(v814 - v808) >> 31));
    v815[v934] = v947;
    int * v817 = v790->cache_age;
    v817[v941] = 0;
    v919 = v941;
  } else {
    int * v820 = v790->cache_age;
    int v951 = (((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1)) & 1) * 2;
    int v821 = v820[v951];
    int * v822 = v790->cache_tags;
    int v823 = v822[v951];
    int * v824 = v790->cache_age;
    int v825 = v824[v934];
    int * v826 = v790->cache_tags;
    int v827 = v826[v934];
    bool v955 = !(((~(((v803 ^ ((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1))) | (-(v803 ^ ((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1))))) >> 31)) | (~(((v805 ^ ((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1))) | (-(v805 ^ ((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1))))) >> 31))) == 0);
    int v891;
    if (v955) {
      int * v828 = v790->cache_age;
      int v957 = (4 + ((((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1)) & 3) * 2)) + ((~(((v805 ^ ((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1))) | (-(v805 ^ ((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1))))) >> 31)) & 1);
      int v829 = v828[v957];
      int * v830 = v790->cache_age;
      int v831 = v830[v936];
      int * v832 = v790->cache_age;
      int v960 = v831 + ((int)((unsigned int)(v831 - v829) >> 31));
      v832[v936] = v960;
      int * v834 = v790->cache_age;
      int v835 = v834[v938];
      int * v836 = v790->cache_age;
      int v963 = v835 + ((int)((unsigned int)(v835 - v829) >> 31));
      v836[v938] = v963;
      int * v838 = v790->cache_age;
      v838[v957] = 0;
      v891 = v957;
    } else {
      int * v841 = v790->cache_age;
      int v967 = 4 + ((((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1)) & 3) * 2);
      int v842 = v841[v967];
      int * v843 = v790->cache_tags;
      int v844 = v843[v967];
      int * v845 = v790->cache_age;
      int v846 = v845[v938];
      int * v847 = v790->cache_tags;
      int v848 = v847[v938];
      int * v849 = v790->cache_dirty;
      int v972 = (4 + ((((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1)) & 3) * 2)) + ((((v842 + ((~(((v844 ^ -1) | (-(v844 ^ -1))) >> 31)) & 2)) - (v846 + ((~(((v848 ^ -1) | (-(v848 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v850 = v849[v972];
      bool v973 = !(v850 == 0);
      if (v973) {
        int * v851 = v790->cache_tags;
        int v852 = v851[v972];
        int * v853 = v790->cache_vals;
        int v976 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1)) & 3) * 2)) + ((((v842 + ((~(((v844 ^ -1) | (-(v844 ^ -1))) >> 31)) & 2)) - (v846 + ((~(((v848 ^ -1) | (-(v848 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v854 = v853[v976];
        int * v855 = v790->cache_vals;
        int v978 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1)) & 3) * 2)) + ((((v842 + ((~(((v844 ^ -1) | (-(v844 ^ -1))) >> 31)) & 2)) - (v846 + ((~(((v848 ^ -1) | (-(v848 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v856 = v855[v978];
        int * v857 = v790->mem;
        int v980 = v852 * 2;
        v857[v980] = v854;
        int * v859 = v790->mem;
        int v983 = (v852 * 2) + 1;
        v859[v983] = v856;
        ;
      } else {
        ;
      }
      int * v864 = v790->mem;
      int v988 = ((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1)) * 2;
      int v865 = v864[v988];
      int * v866 = v790->mem;
      int v990 = (((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1)) * 2) + 1;
      int v867 = v866[v990];
      int * v868 = v790->cache_vals;
      int v992 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1)) & 3) * 2)) + ((((v842 + ((~(((v844 ^ -1) | (-(v844 ^ -1))) >> 31)) & 2)) - (v846 + ((~(((v848 ^ -1) | (-(v848 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v868[v992] = v865;
      int * v870 = v790->cache_vals;
      int v995 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1)) & 3) * 2)) + ((((v842 + ((~(((v844 ^ -1) | (-(v844 ^ -1))) >> 31)) & 2)) - (v846 + ((~(((v848 ^ -1) | (-(v848 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v870[v995] = v867;
      int * v872 = v790->cache_tags;
      int v998 = (int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1);
      v872[v972] = v998;
      int * v874 = v790->cache_dirty;
      v874[v972] = 0;
      int * v876 = v790->cache_age;
      v876[v972] = 1;
      int * v878 = v790->cache_age;
      int v879 = v878[v972];
      int * v880 = v790->cache_age;
      int v881 = v880[v936];
      int * v882 = v790->cache_age;
      int v1006 = v881 + ((int)((unsigned int)(v881 - v879) >> 31));
      v882[v936] = v1006;
      int * v884 = v790->cache_age;
      int v885 = v884[v938];
      int * v886 = v790->cache_age;
      int v1009 = v885 + ((int)((unsigned int)(v885 - v879) >> 31));
      v886[v938] = v1009;
      int * v888 = v790->cache_age;
      v888[v972] = 0;
      v891 = v972;
    }
    int * v892 = v790->cache_vals;
    int v1012 = v891 * 2;
    int v893 = v892[v1012];
    int * v894 = v790->cache_vals;
    int v1014 = (v891 * 2) + 1;
    int v895 = v894[v1014];
    int * v896 = v790->cache_vals;
    int v1016 = (((((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1)) & 1) * 2) + ((((v821 + ((~(((v823 ^ -1) | (-(v823 ^ -1))) >> 31)) & 2)) - (v825 + ((~(((v827 ^ -1) | (-(v827 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v896[v1016] = v893;
    int * v898 = v790->cache_vals;
    int v1019 = ((((((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1)) & 1) * 2) + ((((v821 + ((~(((v823 ^ -1) | (-(v823 ^ -1))) >> 31)) & 2)) - (v825 + ((~(((v827 ^ -1) | (-(v827 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v898[v1019] = v895;
    int * v900 = v790->cache_tags;
    int v1022 = ((((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1)) & 1) * 2) + ((((v821 + ((~(((v823 ^ -1) | (-(v823 ^ -1))) >> 31)) & 2)) - (v825 + ((~(((v827 ^ -1) | (-(v827 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1023 = (int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1);
    v900[v1022] = v1023;
    int * v902 = v790->cache_dirty;
    v902[v1022] = 0;
    int * v904 = v790->cache_age;
    v904[v1022] = 1;
    int * v906 = v790->cache_age;
    int v907 = v906[v1022];
    int * v908 = v790->cache_age;
    int v909 = v908[v932];
    int * v910 = v790->cache_age;
    int v1031 = v909 + ((int)((unsigned int)(v909 - v907) >> 31));
    v910[v932] = v1031;
    int * v912 = v790->cache_age;
    int v913 = v912[v934];
    int * v914 = v790->cache_age;
    int v1034 = v913 + ((int)((unsigned int)(v913 - v907) >> 31));
    v914[v934] = v1034;
    int * v916 = v790->cache_age;
    v916[v1022] = 0;
    v919 = v1022;
  }
  int v1037 = (v919 * 2) + (((int)((unsigned int)v797 >> 2)) & 1);
  int v920 = v806[v1037];
  int * v921 = v790->reg_ready;
  int v1040 = ((v795 + ((v791 - v795) & (~((v791 - v795) >> 31)))) + 1) + ((100 ^ (((~(((v803 ^ ((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1))) | (-(v803 ^ ((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1))))) >> 31)) | (~(((v805 ^ ((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1))) | (-(v805 ^ ((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v799 ^ ((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1))) | (-(v799 ^ ((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1))))) >> 31)) | (~(((v801 ^ ((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1))) | (-(v801 ^ ((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v803 ^ ((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1))) | (-(v803 ^ ((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1))))) >> 31)) | (~(((v805 ^ ((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1))) | (-(v805 ^ ((int)((unsigned int)((int)((unsigned int)v797 >> 2)) >> 1))))) >> 31))) & 104)))));
  v921[9] = v1040;
  int * v923 = v790->regs;
  v923[9] = v920;
  struct StateT * v925 = slot_7(v790);
  return v925;
}

struct StateT * slot_5(struct StateT * v551) {
  int v552 = v551->timer;
  int v553 = v551->timer;
  int v684 = v553 + 1;
  v551->timer = v684;
  int * v555 = v551->cache_tags;
  int v556 = v555[0];
  int * v557 = v551->cache_tags;
  int v558 = v557[1];
  int * v559 = v551->cache_tags;
  int v560 = v559[8];
  int * v561 = v551->cache_tags;
  int v562 = v561[9];
  int * v563 = v551->cache_vals;
  bool v693 = !(((~(((v556 ^ 2) | (-(v556 ^ 2))) >> 31)) | (~(((v558 ^ 2) | (-(v558 ^ 2))) >> 31))) == 0);
  int v676;
  if (v693) {
    int * v564 = v551->cache_age;
    int v695 = (~(((v558 ^ 2) | (-(v558 ^ 2))) >> 31)) & 1;
    int v565 = v564[v695];
    int * v566 = v551->cache_age;
    int v567 = v566[0];
    int * v568 = v551->cache_age;
    int v698 = v567 + ((int)((unsigned int)(v567 - v565) >> 31));
    v568[0] = v698;
    int * v570 = v551->cache_age;
    int v571 = v570[1];
    int * v572 = v551->cache_age;
    int v701 = v571 + ((int)((unsigned int)(v571 - v565) >> 31));
    v572[1] = v701;
    int * v574 = v551->cache_age;
    v574[v695] = 0;
    v676 = v695;
  } else {
    int * v577 = v551->cache_age;
    int v578 = v577[0];
    int * v579 = v551->cache_tags;
    int v580 = v579[0];
    int * v581 = v551->cache_age;
    int v582 = v581[1];
    int * v583 = v551->cache_tags;
    int v584 = v583[1];
    bool v707 = !(((~(((v560 ^ 2) | (-(v560 ^ 2))) >> 31)) | (~(((v562 ^ 2) | (-(v562 ^ 2))) >> 31))) == 0);
    int v648;
    if (v707) {
      int * v585 = v551->cache_age;
      int v709 = 8 + ((~(((v562 ^ 2) | (-(v562 ^ 2))) >> 31)) & 1);
      int v586 = v585[v709];
      int * v587 = v551->cache_age;
      int v588 = v587[8];
      int * v589 = v551->cache_age;
      int v712 = v588 + ((int)((unsigned int)(v588 - v586) >> 31));
      v589[8] = v712;
      int * v591 = v551->cache_age;
      int v592 = v591[9];
      int * v593 = v551->cache_age;
      int v715 = v592 + ((int)((unsigned int)(v592 - v586) >> 31));
      v593[9] = v715;
      int * v595 = v551->cache_age;
      v595[v709] = 0;
      v648 = v709;
    } else {
      int * v598 = v551->cache_age;
      int v599 = v598[8];
      int * v600 = v551->cache_tags;
      int v601 = v600[8];
      int * v602 = v551->cache_age;
      int v603 = v602[9];
      int * v604 = v551->cache_tags;
      int v605 = v604[9];
      int * v606 = v551->cache_dirty;
      int v722 = 8 + ((((v599 + ((~(((v601 ^ -1) | (-(v601 ^ -1))) >> 31)) & 2)) - (v603 + ((~(((v605 ^ -1) | (-(v605 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v607 = v606[v722];
      bool v723 = !(v607 == 0);
      if (v723) {
        int * v608 = v551->cache_tags;
        int v609 = v608[v722];
        int * v610 = v551->cache_vals;
        int v726 = (8 + ((((v599 + ((~(((v601 ^ -1) | (-(v601 ^ -1))) >> 31)) & 2)) - (v603 + ((~(((v605 ^ -1) | (-(v605 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v611 = v610[v726];
        int * v612 = v551->cache_vals;
        int v728 = ((8 + ((((v599 + ((~(((v601 ^ -1) | (-(v601 ^ -1))) >> 31)) & 2)) - (v603 + ((~(((v605 ^ -1) | (-(v605 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v613 = v612[v728];
        int * v614 = v551->mem;
        int v730 = v609 * 2;
        v614[v730] = v611;
        int * v616 = v551->mem;
        int v733 = (v609 * 2) + 1;
        v616[v733] = v613;
        ;
      } else {
        ;
      }
      int * v621 = v551->mem;
      int v622 = v621[4];
      int * v623 = v551->mem;
      int v624 = v623[5];
      int * v625 = v551->cache_vals;
      int v742 = (8 + ((((v599 + ((~(((v601 ^ -1) | (-(v601 ^ -1))) >> 31)) & 2)) - (v603 + ((~(((v605 ^ -1) | (-(v605 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v625[v742] = v622;
      int * v627 = v551->cache_vals;
      int v745 = ((8 + ((((v599 + ((~(((v601 ^ -1) | (-(v601 ^ -1))) >> 31)) & 2)) - (v603 + ((~(((v605 ^ -1) | (-(v605 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v627[v745] = v624;
      int * v629 = v551->cache_tags;
      v629[v722] = 2;
      int * v631 = v551->cache_dirty;
      v631[v722] = 0;
      int * v633 = v551->cache_age;
      v633[v722] = 1;
      int * v635 = v551->cache_age;
      int v636 = v635[v722];
      int * v637 = v551->cache_age;
      int v638 = v637[8];
      int * v639 = v551->cache_age;
      int v754 = v638 + ((int)((unsigned int)(v638 - v636) >> 31));
      v639[8] = v754;
      int * v641 = v551->cache_age;
      int v642 = v641[9];
      int * v643 = v551->cache_age;
      int v757 = v642 + ((int)((unsigned int)(v642 - v636) >> 31));
      v643[9] = v757;
      int * v645 = v551->cache_age;
      v645[v722] = 0;
      v648 = v722;
    }
    int * v649 = v551->cache_vals;
    int v760 = v648 * 2;
    int v650 = v649[v760];
    int * v651 = v551->cache_vals;
    int v762 = (v648 * 2) + 1;
    int v652 = v651[v762];
    int * v653 = v551->cache_vals;
    int v764 = ((((v578 + ((~(((v580 ^ -1) | (-(v580 ^ -1))) >> 31)) & 2)) - (v582 + ((~(((v584 ^ -1) | (-(v584 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v653[v764] = v650;
    int * v655 = v551->cache_vals;
    int v767 = (((((v578 + ((~(((v580 ^ -1) | (-(v580 ^ -1))) >> 31)) & 2)) - (v582 + ((~(((v584 ^ -1) | (-(v584 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v655[v767] = v652;
    int * v657 = v551->cache_tags;
    int v770 = (((v578 + ((~(((v580 ^ -1) | (-(v580 ^ -1))) >> 31)) & 2)) - (v582 + ((~(((v584 ^ -1) | (-(v584 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v657[v770] = 2;
    int * v659 = v551->cache_dirty;
    v659[v770] = 0;
    int * v661 = v551->cache_age;
    v661[v770] = 1;
    int * v663 = v551->cache_age;
    int v664 = v663[v770];
    int * v665 = v551->cache_age;
    int v666 = v665[0];
    int * v667 = v551->cache_age;
    int v777 = v666 + ((int)((unsigned int)(v666 - v664) >> 31));
    v667[0] = v777;
    int * v669 = v551->cache_age;
    int v670 = v669[1];
    int * v671 = v551->cache_age;
    int v780 = v670 + ((int)((unsigned int)(v670 - v664) >> 31));
    v671[1] = v780;
    int * v673 = v551->cache_age;
    v673[v770] = 0;
    v676 = v770;
  }
  int v783 = v676 * 2;
  int v677 = v563[v783];
  int * v678 = v551->reg_ready;
  int v785 = (v552 + 1) + ((100 ^ (((~(((v560 ^ 2) | (-(v560 ^ 2))) >> 31)) | (~(((v562 ^ 2) | (-(v562 ^ 2))) >> 31))) & 104)) ^ (((~(((v556 ^ 2) | (-(v556 ^ 2))) >> 31)) | (~(((v558 ^ 2) | (-(v558 ^ 2))) >> 31))) & (1 ^ (100 ^ (((~(((v560 ^ 2) | (-(v560 ^ 2))) >> 31)) | (~(((v562 ^ 2) | (-(v562 ^ 2))) >> 31))) & 104)))));
  v678[8] = v785;
  int * v680 = v551->regs;
  v680[8] = v677;
  struct StateT * v682 = slot_6(v551);
  return v682;
}

struct StateT * slot_4(struct StateT * v315) {
  int v316 = v315->timer;
  int v317 = v315->timer;
  int v448 = v317 + 1;
  v315->timer = v448;
  int * v319 = v315->cache_tags;
  int v320 = v319[0];
  int * v321 = v315->cache_tags;
  int v322 = v321[1];
  int * v323 = v315->cache_tags;
  int v324 = v323[4];
  int * v325 = v315->cache_tags;
  int v326 = v325[5];
  int * v327 = v315->cache_vals;
  bool v457 = !(((~((v320 | (-v320)) >> 31)) | (~((v322 | (-v322)) >> 31))) == 0);
  int v440;
  if (v457) {
    int * v328 = v315->cache_age;
    int v459 = (~((v322 | (-v322)) >> 31)) & 1;
    int v329 = v328[v459];
    int * v330 = v315->cache_age;
    int v331 = v330[0];
    int * v332 = v315->cache_age;
    int v462 = v331 + ((int)((unsigned int)(v331 - v329) >> 31));
    v332[0] = v462;
    int * v334 = v315->cache_age;
    int v335 = v334[1];
    int * v336 = v315->cache_age;
    int v465 = v335 + ((int)((unsigned int)(v335 - v329) >> 31));
    v336[1] = v465;
    int * v338 = v315->cache_age;
    v338[v459] = 0;
    v440 = v459;
  } else {
    int * v341 = v315->cache_age;
    int v342 = v341[0];
    int * v343 = v315->cache_tags;
    int v344 = v343[0];
    int * v345 = v315->cache_age;
    int v346 = v345[1];
    int * v347 = v315->cache_tags;
    int v348 = v347[1];
    bool v471 = !(((~((v324 | (-v324)) >> 31)) | (~((v326 | (-v326)) >> 31))) == 0);
    int v412;
    if (v471) {
      int * v349 = v315->cache_age;
      int v473 = 4 + ((~((v326 | (-v326)) >> 31)) & 1);
      int v350 = v349[v473];
      int * v351 = v315->cache_age;
      int v352 = v351[4];
      int * v353 = v315->cache_age;
      int v476 = v352 + ((int)((unsigned int)(v352 - v350) >> 31));
      v353[4] = v476;
      int * v355 = v315->cache_age;
      int v356 = v355[5];
      int * v357 = v315->cache_age;
      int v479 = v356 + ((int)((unsigned int)(v356 - v350) >> 31));
      v357[5] = v479;
      int * v359 = v315->cache_age;
      v359[v473] = 0;
      v412 = v473;
    } else {
      int * v362 = v315->cache_age;
      int v363 = v362[4];
      int * v364 = v315->cache_tags;
      int v365 = v364[4];
      int * v366 = v315->cache_age;
      int v367 = v366[5];
      int * v368 = v315->cache_tags;
      int v369 = v368[5];
      int * v370 = v315->cache_dirty;
      int v486 = 4 + ((((v363 + ((~(((v365 ^ -1) | (-(v365 ^ -1))) >> 31)) & 2)) - (v367 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v371 = v370[v486];
      bool v487 = !(v371 == 0);
      if (v487) {
        int * v372 = v315->cache_tags;
        int v373 = v372[v486];
        int * v374 = v315->cache_vals;
        int v490 = (4 + ((((v363 + ((~(((v365 ^ -1) | (-(v365 ^ -1))) >> 31)) & 2)) - (v367 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v375 = v374[v490];
        int * v376 = v315->cache_vals;
        int v492 = ((4 + ((((v363 + ((~(((v365 ^ -1) | (-(v365 ^ -1))) >> 31)) & 2)) - (v367 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v377 = v376[v492];
        int * v378 = v315->mem;
        int v494 = v373 * 2;
        v378[v494] = v375;
        int * v380 = v315->mem;
        int v497 = (v373 * 2) + 1;
        v380[v497] = v377;
        ;
      } else {
        ;
      }
      int * v385 = v315->mem;
      int v386 = v385[0];
      int * v387 = v315->mem;
      int v388 = v387[1];
      int * v389 = v315->cache_vals;
      int v504 = (4 + ((((v363 + ((~(((v365 ^ -1) | (-(v365 ^ -1))) >> 31)) & 2)) - (v367 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v389[v504] = v386;
      int * v391 = v315->cache_vals;
      int v507 = ((4 + ((((v363 + ((~(((v365 ^ -1) | (-(v365 ^ -1))) >> 31)) & 2)) - (v367 + ((~(((v369 ^ -1) | (-(v369 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v391[v507] = v388;
      int * v393 = v315->cache_tags;
      v393[v486] = 0;
      int * v395 = v315->cache_dirty;
      v395[v486] = 0;
      int * v397 = v315->cache_age;
      v397[v486] = 1;
      int * v399 = v315->cache_age;
      int v400 = v399[v486];
      int * v401 = v315->cache_age;
      int v402 = v401[4];
      int * v403 = v315->cache_age;
      int v515 = v402 + ((int)((unsigned int)(v402 - v400) >> 31));
      v403[4] = v515;
      int * v405 = v315->cache_age;
      int v406 = v405[5];
      int * v407 = v315->cache_age;
      int v518 = v406 + ((int)((unsigned int)(v406 - v400) >> 31));
      v407[5] = v518;
      int * v409 = v315->cache_age;
      v409[v486] = 0;
      v412 = v486;
    }
    int * v413 = v315->cache_vals;
    int v521 = v412 * 2;
    int v414 = v413[v521];
    int * v415 = v315->cache_vals;
    int v523 = (v412 * 2) + 1;
    int v416 = v415[v523];
    int * v417 = v315->cache_vals;
    int v525 = ((((v342 + ((~(((v344 ^ -1) | (-(v344 ^ -1))) >> 31)) & 2)) - (v346 + ((~(((v348 ^ -1) | (-(v348 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v417[v525] = v414;
    int * v419 = v315->cache_vals;
    int v528 = (((((v342 + ((~(((v344 ^ -1) | (-(v344 ^ -1))) >> 31)) & 2)) - (v346 + ((~(((v348 ^ -1) | (-(v348 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v419[v528] = v416;
    int * v421 = v315->cache_tags;
    int v531 = (((v342 + ((~(((v344 ^ -1) | (-(v344 ^ -1))) >> 31)) & 2)) - (v346 + ((~(((v348 ^ -1) | (-(v348 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v421[v531] = 0;
    int * v423 = v315->cache_dirty;
    v423[v531] = 0;
    int * v425 = v315->cache_age;
    v425[v531] = 1;
    int * v427 = v315->cache_age;
    int v428 = v427[v531];
    int * v429 = v315->cache_age;
    int v430 = v429[0];
    int * v431 = v315->cache_age;
    int v537 = v430 + ((int)((unsigned int)(v430 - v428) >> 31));
    v431[0] = v537;
    int * v433 = v315->cache_age;
    int v434 = v433[1];
    int * v435 = v315->cache_age;
    int v540 = v434 + ((int)((unsigned int)(v434 - v428) >> 31));
    v435[1] = v540;
    int * v437 = v315->cache_age;
    v437[v531] = 0;
    v440 = v531;
  }
  int v543 = v440 * 2;
  int v441 = v327[v543];
  int * v442 = v315->reg_ready;
  int v546 = (v316 + 1) + ((100 ^ (((~((v324 | (-v324)) >> 31)) | (~((v326 | (-v326)) >> 31))) & 104)) ^ (((~((v320 | (-v320)) >> 31)) | (~((v322 | (-v322)) >> 31))) & (1 ^ (100 ^ (((~((v324 | (-v324)) >> 31)) | (~((v326 | (-v326)) >> 31))) & 104)))));
  v442[7] = v546;
  int * v444 = v315->regs;
  v444[7] = v441;
  struct StateT * v446 = slot_5(v315);
  return v446;
}

struct StateT * slot_2(struct StateT * v267) {
  int v268 = v267->timer;
  int v269 = v267->timer;
  int v281 = v269 + 1;
  v267->timer = v281;
  int * v271 = v267->reg_ready;
  int v272 = v271[6];
  int * v273 = v267->regs;
  int v274 = v273[6];
  int * v275 = v267->reg_ready;
  int v286 = (v272 + ((v268 - v272) & (~((v268 - v272) >> 31)))) + 1;
  v275[6] = v286;
  int * v277 = v267->regs;
  int v288 = v274 << 3;
  v277[6] = v288;
  struct StateT * v279 = slot_3(v267);
  return v279;
}

struct StateT * slot_7(struct StateT * v1045) {
  int v1046 = v1045->timer;
  int v1047 = v1045->timer;
  int v1177 = v1047 + 1;
  v1045->timer = v1177;
  int * v1049 = v1045->cache_tags;
  int v1050 = v1049[0];
  int * v1051 = v1045->cache_tags;
  int v1052 = v1051[1];
  int * v1053 = v1045->cache_tags;
  int v1054 = v1053[4];
  int * v1055 = v1045->cache_tags;
  int v1056 = v1055[5];
  int * v1057 = v1045->cache_vals;
  bool v1186 = !(((~((v1050 | (-v1050)) >> 31)) | (~((v1052 | (-v1052)) >> 31))) == 0);
  int v1170;
  if (v1186) {
    int * v1058 = v1045->cache_age;
    int v1188 = (~((v1052 | (-v1052)) >> 31)) & 1;
    int v1059 = v1058[v1188];
    int * v1060 = v1045->cache_age;
    int v1061 = v1060[0];
    int * v1062 = v1045->cache_age;
    int v1191 = v1061 + ((int)((unsigned int)(v1061 - v1059) >> 31));
    v1062[0] = v1191;
    int * v1064 = v1045->cache_age;
    int v1065 = v1064[1];
    int * v1066 = v1045->cache_age;
    int v1194 = v1065 + ((int)((unsigned int)(v1065 - v1059) >> 31));
    v1066[1] = v1194;
    int * v1068 = v1045->cache_age;
    v1068[v1188] = 0;
    v1170 = v1188;
  } else {
    int * v1071 = v1045->cache_age;
    int v1072 = v1071[0];
    int * v1073 = v1045->cache_tags;
    int v1074 = v1073[0];
    int * v1075 = v1045->cache_age;
    int v1076 = v1075[1];
    int * v1077 = v1045->cache_tags;
    int v1078 = v1077[1];
    bool v1200 = !(((~((v1054 | (-v1054)) >> 31)) | (~((v1056 | (-v1056)) >> 31))) == 0);
    int v1142;
    if (v1200) {
      int * v1079 = v1045->cache_age;
      int v1202 = 4 + ((~((v1056 | (-v1056)) >> 31)) & 1);
      int v1080 = v1079[v1202];
      int * v1081 = v1045->cache_age;
      int v1082 = v1081[4];
      int * v1083 = v1045->cache_age;
      int v1205 = v1082 + ((int)((unsigned int)(v1082 - v1080) >> 31));
      v1083[4] = v1205;
      int * v1085 = v1045->cache_age;
      int v1086 = v1085[5];
      int * v1087 = v1045->cache_age;
      int v1208 = v1086 + ((int)((unsigned int)(v1086 - v1080) >> 31));
      v1087[5] = v1208;
      int * v1089 = v1045->cache_age;
      v1089[v1202] = 0;
      v1142 = v1202;
    } else {
      int * v1092 = v1045->cache_age;
      int v1093 = v1092[4];
      int * v1094 = v1045->cache_tags;
      int v1095 = v1094[4];
      int * v1096 = v1045->cache_age;
      int v1097 = v1096[5];
      int * v1098 = v1045->cache_tags;
      int v1099 = v1098[5];
      int * v1100 = v1045->cache_dirty;
      int v1215 = 4 + ((((v1093 + ((~(((v1095 ^ -1) | (-(v1095 ^ -1))) >> 31)) & 2)) - (v1097 + ((~(((v1099 ^ -1) | (-(v1099 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1101 = v1100[v1215];
      bool v1216 = !(v1101 == 0);
      if (v1216) {
        int * v1102 = v1045->cache_tags;
        int v1103 = v1102[v1215];
        int * v1104 = v1045->cache_vals;
        int v1219 = (4 + ((((v1093 + ((~(((v1095 ^ -1) | (-(v1095 ^ -1))) >> 31)) & 2)) - (v1097 + ((~(((v1099 ^ -1) | (-(v1099 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1105 = v1104[v1219];
        int * v1106 = v1045->cache_vals;
        int v1221 = ((4 + ((((v1093 + ((~(((v1095 ^ -1) | (-(v1095 ^ -1))) >> 31)) & 2)) - (v1097 + ((~(((v1099 ^ -1) | (-(v1099 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1107 = v1106[v1221];
        int * v1108 = v1045->mem;
        int v1223 = v1103 * 2;
        v1108[v1223] = v1105;
        int * v1110 = v1045->mem;
        int v1226 = (v1103 * 2) + 1;
        v1110[v1226] = v1107;
        ;
      } else {
        ;
      }
      int * v1115 = v1045->mem;
      int v1116 = v1115[0];
      int * v1117 = v1045->mem;
      int v1118 = v1117[1];
      int * v1119 = v1045->cache_vals;
      int v1233 = (4 + ((((v1093 + ((~(((v1095 ^ -1) | (-(v1095 ^ -1))) >> 31)) & 2)) - (v1097 + ((~(((v1099 ^ -1) | (-(v1099 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1119[v1233] = v1116;
      int * v1121 = v1045->cache_vals;
      int v1236 = ((4 + ((((v1093 + ((~(((v1095 ^ -1) | (-(v1095 ^ -1))) >> 31)) & 2)) - (v1097 + ((~(((v1099 ^ -1) | (-(v1099 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1121[v1236] = v1118;
      int * v1123 = v1045->cache_tags;
      v1123[v1215] = 0;
      int * v1125 = v1045->cache_dirty;
      v1125[v1215] = 0;
      int * v1127 = v1045->cache_age;
      v1127[v1215] = 1;
      int * v1129 = v1045->cache_age;
      int v1130 = v1129[v1215];
      int * v1131 = v1045->cache_age;
      int v1132 = v1131[4];
      int * v1133 = v1045->cache_age;
      int v1244 = v1132 + ((int)((unsigned int)(v1132 - v1130) >> 31));
      v1133[4] = v1244;
      int * v1135 = v1045->cache_age;
      int v1136 = v1135[5];
      int * v1137 = v1045->cache_age;
      int v1247 = v1136 + ((int)((unsigned int)(v1136 - v1130) >> 31));
      v1137[5] = v1247;
      int * v1139 = v1045->cache_age;
      v1139[v1215] = 0;
      v1142 = v1215;
    }
    int * v1143 = v1045->cache_vals;
    int v1250 = v1142 * 2;
    int v1144 = v1143[v1250];
    int * v1145 = v1045->cache_vals;
    int v1252 = (v1142 * 2) + 1;
    int v1146 = v1145[v1252];
    int * v1147 = v1045->cache_vals;
    int v1254 = ((((v1072 + ((~(((v1074 ^ -1) | (-(v1074 ^ -1))) >> 31)) & 2)) - (v1076 + ((~(((v1078 ^ -1) | (-(v1078 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v1147[v1254] = v1144;
    int * v1149 = v1045->cache_vals;
    int v1257 = (((((v1072 + ((~(((v1074 ^ -1) | (-(v1074 ^ -1))) >> 31)) & 2)) - (v1076 + ((~(((v1078 ^ -1) | (-(v1078 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v1149[v1257] = v1146;
    int * v1151 = v1045->cache_tags;
    int v1260 = (((v1072 + ((~(((v1074 ^ -1) | (-(v1074 ^ -1))) >> 31)) & 2)) - (v1076 + ((~(((v1078 ^ -1) | (-(v1078 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v1151[v1260] = 0;
    int * v1153 = v1045->cache_dirty;
    v1153[v1260] = 0;
    int * v1155 = v1045->cache_age;
    v1155[v1260] = 1;
    int * v1157 = v1045->cache_age;
    int v1158 = v1157[v1260];
    int * v1159 = v1045->cache_age;
    int v1160 = v1159[0];
    int * v1161 = v1045->cache_age;
    int v1266 = v1160 + ((int)((unsigned int)(v1160 - v1158) >> 31));
    v1161[0] = v1266;
    int * v1163 = v1045->cache_age;
    int v1164 = v1163[1];
    int * v1165 = v1045->cache_age;
    int v1269 = v1164 + ((int)((unsigned int)(v1164 - v1158) >> 31));
    v1165[1] = v1269;
    int * v1167 = v1045->cache_age;
    v1167[v1260] = 0;
    v1170 = v1260;
  }
  int v1272 = v1170 * 2;
  int v1171 = v1057[v1272];
  int * v1172 = v1045->reg_ready;
  int v1275 = (v1046 + 1) + ((100 ^ (((~((v1054 | (-v1054)) >> 31)) | (~((v1056 | (-v1056)) >> 31))) & 104)) ^ (((~((v1050 | (-v1050)) >> 31)) | (~((v1052 | (-v1052)) >> 31))) & (1 ^ (100 ^ (((~((v1054 | (-v1054)) >> 31)) | (~((v1056 | (-v1056)) >> 31))) & 104)))));
  v1172[11] = v1275;
  int * v1174 = v1045->regs;
  v1174[11] = v1171;
  return v1045;
}

struct StateT * slot_3(struct StateT * v291) {
  int v292 = v291->timer;
  int v293 = v291->timer;
  int v305 = v293 + 1;
  v291->timer = v305;
  int * v295 = v291->reg_ready;
  int v296 = v295[6];
  int * v297 = v291->regs;
  int v298 = v297[6];
  int * v299 = v291->reg_ready;
  int v310 = (v296 + ((v292 - v296) & (~((v292 - v296) >> 31)))) + 1;
  v299[6] = v310;
  int * v301 = v291->regs;
  int v312 = v298 + 32;
  v301[6] = v312;
  struct StateT * v303 = slot_4(v291);
  return v303;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v4 = v2->timer;
  int v135 = v4 + 1;
  v2->timer = v135;
  int * v6 = v2->cache_tags;
  int v7 = v6[0];
  int * v8 = v2->cache_tags;
  int v9 = v8[1];
  int * v10 = v2->cache_tags;
  int v11 = v10[8];
  int * v12 = v2->cache_tags;
  int v13 = v12[9];
  int * v14 = v2->cache_vals;
  bool v144 = !(((~(((v7 ^ 10) | (-(v7 ^ 10))) >> 31)) | (~(((v9 ^ 10) | (-(v9 ^ 10))) >> 31))) == 0);
  int v127;
  if (v144) {
    int * v15 = v2->cache_age;
    int v146 = (~(((v9 ^ 10) | (-(v9 ^ 10))) >> 31)) & 1;
    int v16 = v15[v146];
    int * v17 = v2->cache_age;
    int v18 = v17[0];
    int * v19 = v2->cache_age;
    int v149 = v18 + ((int)((unsigned int)(v18 - v16) >> 31));
    v19[0] = v149;
    int * v21 = v2->cache_age;
    int v22 = v21[1];
    int * v23 = v2->cache_age;
    int v152 = v22 + ((int)((unsigned int)(v22 - v16) >> 31));
    v23[1] = v152;
    int * v25 = v2->cache_age;
    v25[v146] = 0;
    v127 = v146;
  } else {
    int * v28 = v2->cache_age;
    int v29 = v28[0];
    int * v30 = v2->cache_tags;
    int v31 = v30[0];
    int * v32 = v2->cache_age;
    int v33 = v32[1];
    int * v34 = v2->cache_tags;
    int v35 = v34[1];
    bool v158 = !(((~(((v11 ^ 10) | (-(v11 ^ 10))) >> 31)) | (~(((v13 ^ 10) | (-(v13 ^ 10))) >> 31))) == 0);
    int v99;
    if (v158) {
      int * v36 = v2->cache_age;
      int v160 = 8 + ((~(((v13 ^ 10) | (-(v13 ^ 10))) >> 31)) & 1);
      int v37 = v36[v160];
      int * v38 = v2->cache_age;
      int v39 = v38[8];
      int * v40 = v2->cache_age;
      int v163 = v39 + ((int)((unsigned int)(v39 - v37) >> 31));
      v40[8] = v163;
      int * v42 = v2->cache_age;
      int v43 = v42[9];
      int * v44 = v2->cache_age;
      int v166 = v43 + ((int)((unsigned int)(v43 - v37) >> 31));
      v44[9] = v166;
      int * v46 = v2->cache_age;
      v46[v160] = 0;
      v99 = v160;
    } else {
      int * v49 = v2->cache_age;
      int v50 = v49[8];
      int * v51 = v2->cache_tags;
      int v52 = v51[8];
      int * v53 = v2->cache_age;
      int v54 = v53[9];
      int * v55 = v2->cache_tags;
      int v56 = v55[9];
      int * v57 = v2->cache_dirty;
      int v173 = 8 + ((((v50 + ((~(((v52 ^ -1) | (-(v52 ^ -1))) >> 31)) & 2)) - (v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v58 = v57[v173];
      bool v174 = !(v58 == 0);
      if (v174) {
        int * v59 = v2->cache_tags;
        int v60 = v59[v173];
        int * v61 = v2->cache_vals;
        int v177 = (8 + ((((v50 + ((~(((v52 ^ -1) | (-(v52 ^ -1))) >> 31)) & 2)) - (v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v62 = v61[v177];
        int * v63 = v2->cache_vals;
        int v179 = ((8 + ((((v50 + ((~(((v52 ^ -1) | (-(v52 ^ -1))) >> 31)) & 2)) - (v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v64 = v63[v179];
        int * v65 = v2->mem;
        int v181 = v60 * 2;
        v65[v181] = v62;
        int * v67 = v2->mem;
        int v184 = (v60 * 2) + 1;
        v67[v184] = v64;
        ;
      } else {
        ;
      }
      int * v72 = v2->mem;
      int v73 = v72[20];
      int * v74 = v2->mem;
      int v75 = v74[21];
      int * v76 = v2->cache_vals;
      int v193 = (8 + ((((v50 + ((~(((v52 ^ -1) | (-(v52 ^ -1))) >> 31)) & 2)) - (v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v76[v193] = v73;
      int * v78 = v2->cache_vals;
      int v196 = ((8 + ((((v50 + ((~(((v52 ^ -1) | (-(v52 ^ -1))) >> 31)) & 2)) - (v54 + ((~(((v56 ^ -1) | (-(v56 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v78[v196] = v75;
      int * v80 = v2->cache_tags;
      v80[v173] = 10;
      int * v82 = v2->cache_dirty;
      v82[v173] = 0;
      int * v84 = v2->cache_age;
      v84[v173] = 1;
      int * v86 = v2->cache_age;
      int v87 = v86[v173];
      int * v88 = v2->cache_age;
      int v89 = v88[8];
      int * v90 = v2->cache_age;
      int v205 = v89 + ((int)((unsigned int)(v89 - v87) >> 31));
      v90[8] = v205;
      int * v92 = v2->cache_age;
      int v93 = v92[9];
      int * v94 = v2->cache_age;
      int v208 = v93 + ((int)((unsigned int)(v93 - v87) >> 31));
      v94[9] = v208;
      int * v96 = v2->cache_age;
      v96[v173] = 0;
      v99 = v173;
    }
    int * v100 = v2->cache_vals;
    int v211 = v99 * 2;
    int v101 = v100[v211];
    int * v102 = v2->cache_vals;
    int v213 = (v99 * 2) + 1;
    int v103 = v102[v213];
    int * v104 = v2->cache_vals;
    int v215 = ((((v29 + ((~(((v31 ^ -1) | (-(v31 ^ -1))) >> 31)) & 2)) - (v33 + ((~(((v35 ^ -1) | (-(v35 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v104[v215] = v101;
    int * v106 = v2->cache_vals;
    int v218 = (((((v29 + ((~(((v31 ^ -1) | (-(v31 ^ -1))) >> 31)) & 2)) - (v33 + ((~(((v35 ^ -1) | (-(v35 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v106[v218] = v103;
    int * v108 = v2->cache_tags;
    int v221 = (((v29 + ((~(((v31 ^ -1) | (-(v31 ^ -1))) >> 31)) & 2)) - (v33 + ((~(((v35 ^ -1) | (-(v35 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v108[v221] = 10;
    int * v110 = v2->cache_dirty;
    v110[v221] = 0;
    int * v112 = v2->cache_age;
    v112[v221] = 1;
    int * v114 = v2->cache_age;
    int v115 = v114[v221];
    int * v116 = v2->cache_age;
    int v117 = v116[0];
    int * v118 = v2->cache_age;
    int v228 = v117 + ((int)((unsigned int)(v117 - v115) >> 31));
    v118[0] = v228;
    int * v120 = v2->cache_age;
    int v121 = v120[1];
    int * v122 = v2->cache_age;
    int v231 = v121 + ((int)((unsigned int)(v121 - v115) >> 31));
    v122[1] = v231;
    int * v124 = v2->cache_age;
    v124[v221] = 0;
    v127 = v221;
  }
  int v234 = v127 * 2;
  int v128 = v14[v234];
  int * v129 = v2->reg_ready;
  int v237 = (v3 + 1) + ((100 ^ (((~(((v11 ^ 10) | (-(v11 ^ 10))) >> 31)) | (~(((v13 ^ 10) | (-(v13 ^ 10))) >> 31))) & 104)) ^ (((~(((v7 ^ 10) | (-(v7 ^ 10))) >> 31)) | (~(((v9 ^ 10) | (-(v9 ^ 10))) >> 31))) & (1 ^ (100 ^ (((~(((v11 ^ 10) | (-(v11 ^ 10))) >> 31)) | (~(((v13 ^ 10) | (-(v13 ^ 10))) >> 31))) & 104)))));
  v129[5] = v237;
  int * v131 = v2->regs;
  v131[5] = v128;
  struct StateT * v133 = slot_1(v2);
  return v133;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
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
    s1.mem[SECRET_OFFSET+i] = bounded(0, 20);
    s2.mem[SECRET_OFFSET+i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}