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

struct StateT * slot_6(struct StateT * v371);
struct StateT * slot_5(struct StateT * v116);
struct StateT * slot_2(struct StateT * v38);
struct StateT * slot_7(struct StateT * v763);
struct StateT * slot_3(struct StateT * v56);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v20);
struct StateT * slot_8(struct StateT * v1018);
struct StateT * slot_4(struct StateT * v84);
struct StateT * slot_9(struct StateT * v1042);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_6(struct StateT * v371) {
  int v372 = v371->timer;
  int v373 = v371->timer;
  int v582 = v373 + 1;
  v371->timer = v582;
  int * v375 = v371->reg_ready;
  int v376 = v375[6];
  int * v377 = v371->regs;
  int v378 = v377[6];
  int * v379 = v371->reg_ready;
  int v380 = v379[5];
  int * v381 = v371->regs;
  int v382 = v381[5];
  int * v383 = v371->cache_tags;
  int v590 = (((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 1) * 2;
  int v384 = v383[v590];
  int * v385 = v371->cache_tags;
  int v592 = ((((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 1) * 2) + 1;
  int v386 = v385[v592];
  int * v387 = v371->cache_tags;
  int v594 = 4 + ((((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 3) * 2);
  int v388 = v387[v594];
  int * v389 = v371->cache_tags;
  int v596 = (4 + ((((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v390 = v389[v596];
  int v391 = v371->timer;
  int v597 = v391 + ((100 ^ (((~(((v388 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))) | (-(v388 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))))) >> 31)) | (~(((v390 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))) | (-(v390 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v384 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))) | (-(v384 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))))) >> 31)) | (~(((v386 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))) | (-(v386 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v388 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))) | (-(v388 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))))) >> 31)) | (~(((v390 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))) | (-(v390 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))))) >> 31))) & 104)))));
  v371->timer = v597;
  bool v598 = !(((~(((v384 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))) | (-(v384 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))))) >> 31)) | (~(((v386 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))) | (-(v386 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))))) >> 31))) == 0);
  int v505;
  if (v598) {
    int * v393 = v371->cache_age;
    int v600 = ((((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 1) * 2) + ((~(((v386 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))) | (-(v386 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))))) >> 31)) & 1);
    int v394 = v393[v600];
    int * v395 = v371->cache_age;
    int v396 = v395[v590];
    int * v397 = v371->cache_age;
    int v603 = v396 + ((int)((unsigned int)(v396 - v394) >> 31));
    v397[v590] = v603;
    int * v399 = v371->cache_age;
    int v400 = v399[v592];
    int * v401 = v371->cache_age;
    int v606 = v400 + ((int)((unsigned int)(v400 - v394) >> 31));
    v401[v592] = v606;
    int * v403 = v371->cache_age;
    v403[v600] = 0;
    v505 = v600;
  } else {
    int * v406 = v371->cache_age;
    int v610 = (((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 1) * 2;
    int v407 = v406[v610];
    int * v408 = v371->cache_tags;
    int v409 = v408[v610];
    int * v410 = v371->cache_age;
    int v411 = v410[v592];
    int * v412 = v371->cache_tags;
    int v413 = v412[v592];
    bool v614 = !(((~(((v388 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))) | (-(v388 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))))) >> 31)) | (~(((v390 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))) | (-(v390 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))))) >> 31))) == 0);
    int v477;
    if (v614) {
      int * v414 = v371->cache_age;
      int v616 = (4 + ((((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 3) * 2)) + ((~(((v390 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))) | (-(v390 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))))) >> 31)) & 1);
      int v415 = v414[v616];
      int * v416 = v371->cache_age;
      int v417 = v416[v594];
      int * v418 = v371->cache_age;
      int v619 = v417 + ((int)((unsigned int)(v417 - v415) >> 31));
      v418[v594] = v619;
      int * v420 = v371->cache_age;
      int v421 = v420[v596];
      int * v422 = v371->cache_age;
      int v622 = v421 + ((int)((unsigned int)(v421 - v415) >> 31));
      v422[v596] = v622;
      int * v424 = v371->cache_age;
      v424[v616] = 0;
      v477 = v616;
    } else {
      int * v427 = v371->cache_age;
      int v626 = 4 + ((((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 3) * 2);
      int v428 = v427[v626];
      int * v429 = v371->cache_tags;
      int v430 = v429[v626];
      int * v431 = v371->cache_age;
      int v432 = v431[v596];
      int * v433 = v371->cache_tags;
      int v434 = v433[v596];
      int * v435 = v371->cache_dirty;
      int v631 = (4 + ((((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 3) * 2)) + ((((v428 + ((~(((v430 ^ -1) | (-(v430 ^ -1))) >> 31)) & 2)) - (v432 + ((~(((v434 ^ -1) | (-(v434 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v436 = v435[v631];
      bool v632 = !(v436 == 0);
      if (v632) {
        int * v437 = v371->cache_tags;
        int v438 = v437[v631];
        int * v439 = v371->cache_vals;
        int v635 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 3) * 2)) + ((((v428 + ((~(((v430 ^ -1) | (-(v430 ^ -1))) >> 31)) & 2)) - (v432 + ((~(((v434 ^ -1) | (-(v434 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v440 = v439[v635];
        int * v441 = v371->cache_vals;
        int v637 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 3) * 2)) + ((((v428 + ((~(((v430 ^ -1) | (-(v430 ^ -1))) >> 31)) & 2)) - (v432 + ((~(((v434 ^ -1) | (-(v434 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v442 = v441[v637];
        int * v443 = v371->mem;
        int v639 = v438 * 2;
        v443[v639] = v440;
        int * v445 = v371->mem;
        int v642 = (v438 * 2) + 1;
        v445[v642] = v442;
        ;
      } else {
        ;
      }
      int * v450 = v371->mem;
      int v647 = ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) * 2;
      int v451 = v450[v647];
      int * v452 = v371->mem;
      int v649 = (((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) * 2) + 1;
      int v453 = v452[v649];
      int * v454 = v371->cache_vals;
      int v651 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 3) * 2)) + ((((v428 + ((~(((v430 ^ -1) | (-(v430 ^ -1))) >> 31)) & 2)) - (v432 + ((~(((v434 ^ -1) | (-(v434 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v454[v651] = v451;
      int * v456 = v371->cache_vals;
      int v654 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 3) * 2)) + ((((v428 + ((~(((v430 ^ -1) | (-(v430 ^ -1))) >> 31)) & 2)) - (v432 + ((~(((v434 ^ -1) | (-(v434 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v456[v654] = v453;
      int * v458 = v371->cache_tags;
      int v657 = (int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1);
      v458[v631] = v657;
      int * v460 = v371->cache_dirty;
      v460[v631] = 0;
      int * v462 = v371->cache_age;
      v462[v631] = 1;
      int * v464 = v371->cache_age;
      int v465 = v464[v631];
      int * v466 = v371->cache_age;
      int v467 = v466[v594];
      int * v468 = v371->cache_age;
      int v665 = v467 + ((int)((unsigned int)(v467 - v465) >> 31));
      v468[v594] = v665;
      int * v470 = v371->cache_age;
      int v471 = v470[v596];
      int * v472 = v371->cache_age;
      int v668 = v471 + ((int)((unsigned int)(v471 - v465) >> 31));
      v472[v596] = v668;
      int * v474 = v371->cache_age;
      v474[v631] = 0;
      v477 = v631;
    }
    int * v478 = v371->cache_vals;
    int v671 = v477 * 2;
    int v479 = v478[v671];
    int * v480 = v371->cache_vals;
    int v673 = (v477 * 2) + 1;
    int v481 = v480[v673];
    int * v482 = v371->cache_vals;
    int v675 = (((((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 1) * 2) + ((((v407 + ((~(((v409 ^ -1) | (-(v409 ^ -1))) >> 31)) & 2)) - (v411 + ((~(((v413 ^ -1) | (-(v413 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v482[v675] = v479;
    int * v484 = v371->cache_vals;
    int v678 = ((((((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 1) * 2) + ((((v407 + ((~(((v409 ^ -1) | (-(v409 ^ -1))) >> 31)) & 2)) - (v411 + ((~(((v413 ^ -1) | (-(v413 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v484[v678] = v481;
    int * v486 = v371->cache_tags;
    int v681 = ((((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 1) * 2) + ((((v407 + ((~(((v409 ^ -1) | (-(v409 ^ -1))) >> 31)) & 2)) - (v411 + ((~(((v413 ^ -1) | (-(v413 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v682 = (int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1);
    v486[v681] = v682;
    int * v488 = v371->cache_dirty;
    v488[v681] = 0;
    int * v490 = v371->cache_age;
    v490[v681] = 1;
    int * v492 = v371->cache_age;
    int v493 = v492[v681];
    int * v494 = v371->cache_age;
    int v495 = v494[v590];
    int * v496 = v371->cache_age;
    int v690 = v495 + ((int)((unsigned int)(v495 - v493) >> 31));
    v496[v590] = v690;
    int * v498 = v371->cache_age;
    int v499 = v498[v592];
    int * v500 = v371->cache_age;
    int v693 = v499 + ((int)((unsigned int)(v499 - v493) >> 31));
    v500[v592] = v693;
    int * v502 = v371->cache_age;
    v502[v681] = 0;
    v505 = v681;
  }
  int * v506 = v371->cache_vals;
  int v696 = (v505 * 2) + (((int)((unsigned int)v378 >> 2)) & 1);
  v506[v696] = v382;
  int * v508 = v371->cache_tags;
  int v509 = v508[v594];
  int * v510 = v371->cache_tags;
  int v511 = v510[v596];
  bool v700 = !(((~(((v509 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))) | (-(v509 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))))) >> 31)) | (~(((v511 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))) | (-(v511 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))))) >> 31))) == 0);
  int v575;
  if (v700) {
    int * v512 = v371->cache_age;
    int v702 = (4 + ((((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 3) * 2)) + ((~(((v511 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))) | (-(v511 ^ ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1))))) >> 31)) & 1);
    int v513 = v512[v702];
    int * v514 = v371->cache_age;
    int v515 = v514[v594];
    int * v516 = v371->cache_age;
    int v705 = v515 + ((int)((unsigned int)(v515 - v513) >> 31));
    v516[v594] = v705;
    int * v518 = v371->cache_age;
    int v519 = v518[v596];
    int * v520 = v371->cache_age;
    int v708 = v519 + ((int)((unsigned int)(v519 - v513) >> 31));
    v520[v596] = v708;
    int * v522 = v371->cache_age;
    v522[v702] = 0;
    v575 = v702;
  } else {
    int * v525 = v371->cache_age;
    int v712 = 4 + ((((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 3) * 2);
    int v526 = v525[v712];
    int * v527 = v371->cache_tags;
    int v528 = v527[v712];
    int * v529 = v371->cache_age;
    int v530 = v529[v596];
    int * v531 = v371->cache_tags;
    int v532 = v531[v596];
    int * v533 = v371->cache_dirty;
    int v717 = (4 + ((((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 3) * 2)) + ((((v526 + ((~(((v528 ^ -1) | (-(v528 ^ -1))) >> 31)) & 2)) - (v530 + ((~(((v532 ^ -1) | (-(v532 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v534 = v533[v717];
    bool v718 = !(v534 == 0);
    if (v718) {
      int * v535 = v371->cache_tags;
      int v536 = v535[v717];
      int * v537 = v371->cache_vals;
      int v721 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 3) * 2)) + ((((v526 + ((~(((v528 ^ -1) | (-(v528 ^ -1))) >> 31)) & 2)) - (v530 + ((~(((v532 ^ -1) | (-(v532 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v538 = v537[v721];
      int * v539 = v371->cache_vals;
      int v723 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 3) * 2)) + ((((v526 + ((~(((v528 ^ -1) | (-(v528 ^ -1))) >> 31)) & 2)) - (v530 + ((~(((v532 ^ -1) | (-(v532 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v540 = v539[v723];
      int * v541 = v371->mem;
      int v725 = v536 * 2;
      v541[v725] = v538;
      int * v543 = v371->mem;
      int v728 = (v536 * 2) + 1;
      v543[v728] = v540;
      ;
    } else {
      ;
    }
    int * v548 = v371->mem;
    int v733 = ((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) * 2;
    int v549 = v548[v733];
    int * v550 = v371->mem;
    int v735 = (((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) * 2) + 1;
    int v551 = v550[v735];
    int * v552 = v371->cache_vals;
    int v737 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 3) * 2)) + ((((v526 + ((~(((v528 ^ -1) | (-(v528 ^ -1))) >> 31)) & 2)) - (v530 + ((~(((v532 ^ -1) | (-(v532 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v552[v737] = v549;
    int * v554 = v371->cache_vals;
    int v740 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1)) & 3) * 2)) + ((((v526 + ((~(((v528 ^ -1) | (-(v528 ^ -1))) >> 31)) & 2)) - (v530 + ((~(((v532 ^ -1) | (-(v532 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v554[v740] = v551;
    int * v556 = v371->cache_tags;
    int v743 = (int)((unsigned int)((int)((unsigned int)v378 >> 2)) >> 1);
    v556[v717] = v743;
    int * v558 = v371->cache_dirty;
    v558[v717] = 0;
    int * v560 = v371->cache_age;
    v560[v717] = 1;
    int * v562 = v371->cache_age;
    int v563 = v562[v717];
    int * v564 = v371->cache_age;
    int v565 = v564[v594];
    int * v566 = v371->cache_age;
    int v751 = v565 + ((int)((unsigned int)(v565 - v563) >> 31));
    v566[v594] = v751;
    int * v568 = v371->cache_age;
    int v569 = v568[v596];
    int * v570 = v371->cache_age;
    int v754 = v569 + ((int)((unsigned int)(v569 - v563) >> 31));
    v570[v596] = v754;
    int * v572 = v371->cache_age;
    v572[v717] = 0;
    v575 = v717;
  }
  int * v576 = v371->cache_vals;
  int v757 = (v575 * 2) + (((int)((unsigned int)v378 >> 2)) & 1);
  v576[v757] = v382;
  int * v578 = v371->cache_dirty;
  v578[v575] = 1;
  struct StateT * v580 = slot_7(v371);
  return v580;
}

struct StateT * slot_5(struct StateT * v116) {
  int v117 = v116->timer;
  int v118 = v116->timer;
  int v253 = v118 + 1;
  v116->timer = v253;
  int * v120 = v116->reg_ready;
  int v121 = v120[8];
  int * v122 = v116->regs;
  int v123 = v122[8];
  int * v124 = v116->cache_tags;
  int v258 = (((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 1) * 2;
  int v125 = v124[v258];
  int * v126 = v116->cache_tags;
  int v260 = ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 1) * 2) + 1;
  int v127 = v126[v260];
  int * v128 = v116->cache_tags;
  int v262 = 4 + ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 3) * 2);
  int v129 = v128[v262];
  int * v130 = v116->cache_tags;
  int v264 = (4 + ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v131 = v130[v264];
  int * v132 = v116->cache_vals;
  bool v265 = !(((~(((v125 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v125 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31)) | (~(((v127 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v127 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31))) == 0);
  int v245;
  if (v265) {
    int * v133 = v116->cache_age;
    int v267 = ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 1) * 2) + ((~(((v127 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v127 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31)) & 1);
    int v134 = v133[v267];
    int * v135 = v116->cache_age;
    int v136 = v135[v258];
    int * v137 = v116->cache_age;
    int v270 = v136 + ((int)((unsigned int)(v136 - v134) >> 31));
    v137[v258] = v270;
    int * v139 = v116->cache_age;
    int v140 = v139[v260];
    int * v141 = v116->cache_age;
    int v273 = v140 + ((int)((unsigned int)(v140 - v134) >> 31));
    v141[v260] = v273;
    int * v143 = v116->cache_age;
    v143[v267] = 0;
    v245 = v267;
  } else {
    int * v146 = v116->cache_age;
    int v277 = (((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 1) * 2;
    int v147 = v146[v277];
    int * v148 = v116->cache_tags;
    int v149 = v148[v277];
    int * v150 = v116->cache_age;
    int v151 = v150[v260];
    int * v152 = v116->cache_tags;
    int v153 = v152[v260];
    bool v281 = !(((~(((v129 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v129 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31)) | (~(((v131 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v131 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31))) == 0);
    int v217;
    if (v281) {
      int * v154 = v116->cache_age;
      int v283 = (4 + ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 3) * 2)) + ((~(((v131 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v131 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31)) & 1);
      int v155 = v154[v283];
      int * v156 = v116->cache_age;
      int v157 = v156[v262];
      int * v158 = v116->cache_age;
      int v286 = v157 + ((int)((unsigned int)(v157 - v155) >> 31));
      v158[v262] = v286;
      int * v160 = v116->cache_age;
      int v161 = v160[v264];
      int * v162 = v116->cache_age;
      int v289 = v161 + ((int)((unsigned int)(v161 - v155) >> 31));
      v162[v264] = v289;
      int * v164 = v116->cache_age;
      v164[v283] = 0;
      v217 = v283;
    } else {
      int * v167 = v116->cache_age;
      int v293 = 4 + ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 3) * 2);
      int v168 = v167[v293];
      int * v169 = v116->cache_tags;
      int v170 = v169[v293];
      int * v171 = v116->cache_age;
      int v172 = v171[v264];
      int * v173 = v116->cache_tags;
      int v174 = v173[v264];
      int * v175 = v116->cache_dirty;
      int v298 = (4 + ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 3) * 2)) + ((((v168 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2)) - (v172 + ((~(((v174 ^ -1) | (-(v174 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v176 = v175[v298];
      bool v299 = !(v176 == 0);
      if (v299) {
        int * v177 = v116->cache_tags;
        int v178 = v177[v298];
        int * v179 = v116->cache_vals;
        int v302 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 3) * 2)) + ((((v168 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2)) - (v172 + ((~(((v174 ^ -1) | (-(v174 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v180 = v179[v302];
        int * v181 = v116->cache_vals;
        int v304 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 3) * 2)) + ((((v168 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2)) - (v172 + ((~(((v174 ^ -1) | (-(v174 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v182 = v181[v304];
        int * v183 = v116->mem;
        int v306 = v178 * 2;
        v183[v306] = v180;
        int * v185 = v116->mem;
        int v309 = (v178 * 2) + 1;
        v185[v309] = v182;
        ;
      } else {
        ;
      }
      int * v190 = v116->mem;
      int v314 = ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) * 2;
      int v191 = v190[v314];
      int * v192 = v116->mem;
      int v316 = (((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) * 2) + 1;
      int v193 = v192[v316];
      int * v194 = v116->cache_vals;
      int v318 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 3) * 2)) + ((((v168 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2)) - (v172 + ((~(((v174 ^ -1) | (-(v174 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v194[v318] = v191;
      int * v196 = v116->cache_vals;
      int v321 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 3) * 2)) + ((((v168 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2)) - (v172 + ((~(((v174 ^ -1) | (-(v174 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v196[v321] = v193;
      int * v198 = v116->cache_tags;
      int v324 = (int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1);
      v198[v298] = v324;
      int * v200 = v116->cache_dirty;
      v200[v298] = 0;
      int * v202 = v116->cache_age;
      v202[v298] = 1;
      int * v204 = v116->cache_age;
      int v205 = v204[v298];
      int * v206 = v116->cache_age;
      int v207 = v206[v262];
      int * v208 = v116->cache_age;
      int v332 = v207 + ((int)((unsigned int)(v207 - v205) >> 31));
      v208[v262] = v332;
      int * v210 = v116->cache_age;
      int v211 = v210[v264];
      int * v212 = v116->cache_age;
      int v335 = v211 + ((int)((unsigned int)(v211 - v205) >> 31));
      v212[v264] = v335;
      int * v214 = v116->cache_age;
      v214[v298] = 0;
      v217 = v298;
    }
    int * v218 = v116->cache_vals;
    int v338 = v217 * 2;
    int v219 = v218[v338];
    int * v220 = v116->cache_vals;
    int v340 = (v217 * 2) + 1;
    int v221 = v220[v340];
    int * v222 = v116->cache_vals;
    int v342 = (((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 1) * 2) + ((((v147 + ((~(((v149 ^ -1) | (-(v149 ^ -1))) >> 31)) & 2)) - (v151 + ((~(((v153 ^ -1) | (-(v153 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v222[v342] = v219;
    int * v224 = v116->cache_vals;
    int v345 = ((((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 1) * 2) + ((((v147 + ((~(((v149 ^ -1) | (-(v149 ^ -1))) >> 31)) & 2)) - (v151 + ((~(((v153 ^ -1) | (-(v153 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v224[v345] = v221;
    int * v226 = v116->cache_tags;
    int v348 = ((((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1)) & 1) * 2) + ((((v147 + ((~(((v149 ^ -1) | (-(v149 ^ -1))) >> 31)) & 2)) - (v151 + ((~(((v153 ^ -1) | (-(v153 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v349 = (int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1);
    v226[v348] = v349;
    int * v228 = v116->cache_dirty;
    v228[v348] = 0;
    int * v230 = v116->cache_age;
    v230[v348] = 1;
    int * v232 = v116->cache_age;
    int v233 = v232[v348];
    int * v234 = v116->cache_age;
    int v235 = v234[v258];
    int * v236 = v116->cache_age;
    int v357 = v235 + ((int)((unsigned int)(v235 - v233) >> 31));
    v236[v258] = v357;
    int * v238 = v116->cache_age;
    int v239 = v238[v260];
    int * v240 = v116->cache_age;
    int v360 = v239 + ((int)((unsigned int)(v239 - v233) >> 31));
    v240[v260] = v360;
    int * v242 = v116->cache_age;
    v242[v348] = 0;
    v245 = v348;
  }
  int v363 = (v245 * 2) + (((int)((unsigned int)v123 >> 2)) & 1);
  int v246 = v132[v363];
  int * v247 = v116->reg_ready;
  int v366 = ((v121 + ((v117 - v121) & (~((v117 - v121) >> 31)))) + 1) + ((100 ^ (((~(((v129 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v129 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31)) | (~(((v131 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v131 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v125 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v125 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31)) | (~(((v127 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v127 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v129 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v129 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31)) | (~(((v131 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))) | (-(v131 ^ ((int)((unsigned int)((int)((unsigned int)v123 >> 2)) >> 1))))) >> 31))) & 104)))));
  v247[5] = v366;
  int * v249 = v116->regs;
  v249[5] = v246;
  struct StateT * v251 = slot_6(v116);
  return v251;
}

struct StateT * slot_2(struct StateT * v38) {
  int v39 = v38->timer;
  int v40 = v38->timer;
  int v48 = v40 + 1;
  v38->timer = v48;
  int * v42 = v38->reg_ready;
  int v51 = v39 + 1;
  v42[9] = v51;
  int * v44 = v38->regs;
  v44[9] = 80;
  struct StateT * v46 = slot_3(v38);
  return v46;
}

struct StateT * slot_7(struct StateT * v763) {
  int v764 = v763->timer;
  int v765 = v763->timer;
  int v900 = v765 + 1;
  v763->timer = v900;
  int * v767 = v763->reg_ready;
  int v768 = v767[6];
  int * v769 = v763->regs;
  int v770 = v769[6];
  int * v771 = v763->cache_tags;
  int v905 = (((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1)) & 1) * 2;
  int v772 = v771[v905];
  int * v773 = v763->cache_tags;
  int v907 = ((((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1)) & 1) * 2) + 1;
  int v774 = v773[v907];
  int * v775 = v763->cache_tags;
  int v909 = 4 + ((((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1)) & 3) * 2);
  int v776 = v775[v909];
  int * v777 = v763->cache_tags;
  int v911 = (4 + ((((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v778 = v777[v911];
  int * v779 = v763->cache_vals;
  bool v912 = !(((~(((v772 ^ ((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1))) | (-(v772 ^ ((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1))))) >> 31)) | (~(((v774 ^ ((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1))) | (-(v774 ^ ((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1))))) >> 31))) == 0);
  int v892;
  if (v912) {
    int * v780 = v763->cache_age;
    int v914 = ((((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1)) & 1) * 2) + ((~(((v774 ^ ((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1))) | (-(v774 ^ ((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1))))) >> 31)) & 1);
    int v781 = v780[v914];
    int * v782 = v763->cache_age;
    int v783 = v782[v905];
    int * v784 = v763->cache_age;
    int v917 = v783 + ((int)((unsigned int)(v783 - v781) >> 31));
    v784[v905] = v917;
    int * v786 = v763->cache_age;
    int v787 = v786[v907];
    int * v788 = v763->cache_age;
    int v920 = v787 + ((int)((unsigned int)(v787 - v781) >> 31));
    v788[v907] = v920;
    int * v790 = v763->cache_age;
    v790[v914] = 0;
    v892 = v914;
  } else {
    int * v793 = v763->cache_age;
    int v924 = (((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1)) & 1) * 2;
    int v794 = v793[v924];
    int * v795 = v763->cache_tags;
    int v796 = v795[v924];
    int * v797 = v763->cache_age;
    int v798 = v797[v907];
    int * v799 = v763->cache_tags;
    int v800 = v799[v907];
    bool v928 = !(((~(((v776 ^ ((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1))) | (-(v776 ^ ((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1))))) >> 31)) | (~(((v778 ^ ((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1))) | (-(v778 ^ ((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1))))) >> 31))) == 0);
    int v864;
    if (v928) {
      int * v801 = v763->cache_age;
      int v930 = (4 + ((((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1)) & 3) * 2)) + ((~(((v778 ^ ((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1))) | (-(v778 ^ ((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1))))) >> 31)) & 1);
      int v802 = v801[v930];
      int * v803 = v763->cache_age;
      int v804 = v803[v909];
      int * v805 = v763->cache_age;
      int v933 = v804 + ((int)((unsigned int)(v804 - v802) >> 31));
      v805[v909] = v933;
      int * v807 = v763->cache_age;
      int v808 = v807[v911];
      int * v809 = v763->cache_age;
      int v936 = v808 + ((int)((unsigned int)(v808 - v802) >> 31));
      v809[v911] = v936;
      int * v811 = v763->cache_age;
      v811[v930] = 0;
      v864 = v930;
    } else {
      int * v814 = v763->cache_age;
      int v940 = 4 + ((((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1)) & 3) * 2);
      int v815 = v814[v940];
      int * v816 = v763->cache_tags;
      int v817 = v816[v940];
      int * v818 = v763->cache_age;
      int v819 = v818[v911];
      int * v820 = v763->cache_tags;
      int v821 = v820[v911];
      int * v822 = v763->cache_dirty;
      int v945 = (4 + ((((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1)) & 3) * 2)) + ((((v815 + ((~(((v817 ^ -1) | (-(v817 ^ -1))) >> 31)) & 2)) - (v819 + ((~(((v821 ^ -1) | (-(v821 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v823 = v822[v945];
      bool v946 = !(v823 == 0);
      if (v946) {
        int * v824 = v763->cache_tags;
        int v825 = v824[v945];
        int * v826 = v763->cache_vals;
        int v949 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1)) & 3) * 2)) + ((((v815 + ((~(((v817 ^ -1) | (-(v817 ^ -1))) >> 31)) & 2)) - (v819 + ((~(((v821 ^ -1) | (-(v821 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v827 = v826[v949];
        int * v828 = v763->cache_vals;
        int v951 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1)) & 3) * 2)) + ((((v815 + ((~(((v817 ^ -1) | (-(v817 ^ -1))) >> 31)) & 2)) - (v819 + ((~(((v821 ^ -1) | (-(v821 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v829 = v828[v951];
        int * v830 = v763->mem;
        int v953 = v825 * 2;
        v830[v953] = v827;
        int * v832 = v763->mem;
        int v956 = (v825 * 2) + 1;
        v832[v956] = v829;
        ;
      } else {
        ;
      }
      int * v837 = v763->mem;
      int v961 = ((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1)) * 2;
      int v838 = v837[v961];
      int * v839 = v763->mem;
      int v963 = (((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1)) * 2) + 1;
      int v840 = v839[v963];
      int * v841 = v763->cache_vals;
      int v965 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1)) & 3) * 2)) + ((((v815 + ((~(((v817 ^ -1) | (-(v817 ^ -1))) >> 31)) & 2)) - (v819 + ((~(((v821 ^ -1) | (-(v821 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v841[v965] = v838;
      int * v843 = v763->cache_vals;
      int v968 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1)) & 3) * 2)) + ((((v815 + ((~(((v817 ^ -1) | (-(v817 ^ -1))) >> 31)) & 2)) - (v819 + ((~(((v821 ^ -1) | (-(v821 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v843[v968] = v840;
      int * v845 = v763->cache_tags;
      int v971 = (int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1);
      v845[v945] = v971;
      int * v847 = v763->cache_dirty;
      v847[v945] = 0;
      int * v849 = v763->cache_age;
      v849[v945] = 1;
      int * v851 = v763->cache_age;
      int v852 = v851[v945];
      int * v853 = v763->cache_age;
      int v854 = v853[v909];
      int * v855 = v763->cache_age;
      int v979 = v854 + ((int)((unsigned int)(v854 - v852) >> 31));
      v855[v909] = v979;
      int * v857 = v763->cache_age;
      int v858 = v857[v911];
      int * v859 = v763->cache_age;
      int v982 = v858 + ((int)((unsigned int)(v858 - v852) >> 31));
      v859[v911] = v982;
      int * v861 = v763->cache_age;
      v861[v945] = 0;
      v864 = v945;
    }
    int * v865 = v763->cache_vals;
    int v985 = v864 * 2;
    int v866 = v865[v985];
    int * v867 = v763->cache_vals;
    int v987 = (v864 * 2) + 1;
    int v868 = v867[v987];
    int * v869 = v763->cache_vals;
    int v989 = (((((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1)) & 1) * 2) + ((((v794 + ((~(((v796 ^ -1) | (-(v796 ^ -1))) >> 31)) & 2)) - (v798 + ((~(((v800 ^ -1) | (-(v800 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v869[v989] = v866;
    int * v871 = v763->cache_vals;
    int v992 = ((((((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1)) & 1) * 2) + ((((v794 + ((~(((v796 ^ -1) | (-(v796 ^ -1))) >> 31)) & 2)) - (v798 + ((~(((v800 ^ -1) | (-(v800 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v871[v992] = v868;
    int * v873 = v763->cache_tags;
    int v995 = ((((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1)) & 1) * 2) + ((((v794 + ((~(((v796 ^ -1) | (-(v796 ^ -1))) >> 31)) & 2)) - (v798 + ((~(((v800 ^ -1) | (-(v800 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v996 = (int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1);
    v873[v995] = v996;
    int * v875 = v763->cache_dirty;
    v875[v995] = 0;
    int * v877 = v763->cache_age;
    v877[v995] = 1;
    int * v879 = v763->cache_age;
    int v880 = v879[v995];
    int * v881 = v763->cache_age;
    int v882 = v881[v905];
    int * v883 = v763->cache_age;
    int v1004 = v882 + ((int)((unsigned int)(v882 - v880) >> 31));
    v883[v905] = v1004;
    int * v885 = v763->cache_age;
    int v886 = v885[v907];
    int * v887 = v763->cache_age;
    int v1007 = v886 + ((int)((unsigned int)(v886 - v880) >> 31));
    v887[v907] = v1007;
    int * v889 = v763->cache_age;
    v889[v995] = 0;
    v892 = v995;
  }
  int v1010 = (v892 * 2) + (((int)((unsigned int)v770 >> 2)) & 1);
  int v893 = v779[v1010];
  int * v894 = v763->reg_ready;
  int v1013 = ((v768 + ((v764 - v768) & (~((v764 - v768) >> 31)))) + 1) + ((100 ^ (((~(((v776 ^ ((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1))) | (-(v776 ^ ((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1))))) >> 31)) | (~(((v778 ^ ((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1))) | (-(v778 ^ ((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v772 ^ ((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1))) | (-(v772 ^ ((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1))))) >> 31)) | (~(((v774 ^ ((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1))) | (-(v774 ^ ((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v776 ^ ((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1))) | (-(v776 ^ ((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1))))) >> 31)) | (~(((v778 ^ ((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1))) | (-(v778 ^ ((int)((unsigned int)((int)((unsigned int)v770 >> 2)) >> 1))))) >> 31))) & 104)))));
  v894[11] = v1013;
  int * v896 = v763->regs;
  v896[11] = v893;
  struct StateT * v898 = slot_8(v763);
  return v898;
}

struct StateT * slot_3(struct StateT * v56) {
  int v57 = v56->timer;
  int v58 = v56->timer;
  int v73 = v58 + 1;
  v56->timer = v73;
  int * v60 = v56->reg_ready;
  int v61 = v60[6];
  int * v62 = v56->regs;
  int v63 = v62[6];
  int * v64 = v56->reg_ready;
  int v65 = v64[7];
  int * v66 = v56->regs;
  int v67 = v66[7];
  bool v80 = v63 >= v67;
  struct StateT * v71;
  if (v80) {
    v71 = v56;
  } else {
    struct StateT * v69 = slot_4(v56);
    v71 = v69;
  }
  return v71;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v1051 = v1->timer;
  int * v1052 = v1->reg_ready;
  int v1053 = v1052[0];
  int v1184 = v1053 + ((v1051 - v1053) & (~((v1051 - v1053) >> 31)));
  v1->timer = v1184;
  int v1055 = v1->timer;
  int * v1056 = v1->reg_ready;
  int v1057 = v1056[1];
  int v1187 = v1057 + ((v1055 - v1057) & (~((v1055 - v1057) >> 31)));
  v1->timer = v1187;
  int v1059 = v1->timer;
  int * v1060 = v1->reg_ready;
  int v1061 = v1060[2];
  int v1190 = v1061 + ((v1059 - v1061) & (~((v1059 - v1061) >> 31)));
  v1->timer = v1190;
  int v1063 = v1->timer;
  int * v1064 = v1->reg_ready;
  int v1065 = v1064[3];
  int v1193 = v1065 + ((v1063 - v1065) & (~((v1063 - v1065) >> 31)));
  v1->timer = v1193;
  int v1067 = v1->timer;
  int * v1068 = v1->reg_ready;
  int v1069 = v1068[4];
  int v1196 = v1069 + ((v1067 - v1069) & (~((v1067 - v1069) >> 31)));
  v1->timer = v1196;
  int v1071 = v1->timer;
  int * v1072 = v1->reg_ready;
  int v1073 = v1072[5];
  int v1199 = v1073 + ((v1071 - v1073) & (~((v1071 - v1073) >> 31)));
  v1->timer = v1199;
  int v1075 = v1->timer;
  int * v1076 = v1->reg_ready;
  int v1077 = v1076[6];
  int v1202 = v1077 + ((v1075 - v1077) & (~((v1075 - v1077) >> 31)));
  v1->timer = v1202;
  int v1079 = v1->timer;
  int * v1080 = v1->reg_ready;
  int v1081 = v1080[7];
  int v1205 = v1081 + ((v1079 - v1081) & (~((v1079 - v1081) >> 31)));
  v1->timer = v1205;
  int v1083 = v1->timer;
  int * v1084 = v1->reg_ready;
  int v1085 = v1084[8];
  int v1208 = v1085 + ((v1083 - v1085) & (~((v1083 - v1085) >> 31)));
  v1->timer = v1208;
  int v1087 = v1->timer;
  int * v1088 = v1->reg_ready;
  int v1089 = v1088[9];
  int v1211 = v1089 + ((v1087 - v1089) & (~((v1087 - v1089) >> 31)));
  v1->timer = v1211;
  int v1091 = v1->timer;
  int * v1092 = v1->reg_ready;
  int v1093 = v1092[10];
  int v1214 = v1093 + ((v1091 - v1093) & (~((v1091 - v1093) >> 31)));
  v1->timer = v1214;
  int v1095 = v1->timer;
  int * v1096 = v1->reg_ready;
  int v1097 = v1096[11];
  int v1217 = v1097 + ((v1095 - v1097) & (~((v1095 - v1097) >> 31)));
  v1->timer = v1217;
  int v1099 = v1->timer;
  int * v1100 = v1->reg_ready;
  int v1101 = v1100[12];
  int v1220 = v1101 + ((v1099 - v1101) & (~((v1099 - v1101) >> 31)));
  v1->timer = v1220;
  int v1103 = v1->timer;
  int * v1104 = v1->reg_ready;
  int v1105 = v1104[13];
  int v1223 = v1105 + ((v1103 - v1105) & (~((v1103 - v1105) >> 31)));
  v1->timer = v1223;
  int v1107 = v1->timer;
  int * v1108 = v1->reg_ready;
  int v1109 = v1108[14];
  int v1226 = v1109 + ((v1107 - v1109) & (~((v1107 - v1109) >> 31)));
  v1->timer = v1226;
  int v1111 = v1->timer;
  int * v1112 = v1->reg_ready;
  int v1113 = v1112[15];
  int v1229 = v1113 + ((v1111 - v1113) & (~((v1111 - v1113) >> 31)));
  v1->timer = v1229;
  int v1115 = v1->timer;
  int * v1116 = v1->reg_ready;
  int v1117 = v1116[16];
  int v1232 = v1117 + ((v1115 - v1117) & (~((v1115 - v1117) >> 31)));
  v1->timer = v1232;
  int v1119 = v1->timer;
  int * v1120 = v1->reg_ready;
  int v1121 = v1120[17];
  int v1235 = v1121 + ((v1119 - v1121) & (~((v1119 - v1121) >> 31)));
  v1->timer = v1235;
  int v1123 = v1->timer;
  int * v1124 = v1->reg_ready;
  int v1125 = v1124[18];
  int v1238 = v1125 + ((v1123 - v1125) & (~((v1123 - v1125) >> 31)));
  v1->timer = v1238;
  int v1127 = v1->timer;
  int * v1128 = v1->reg_ready;
  int v1129 = v1128[19];
  int v1241 = v1129 + ((v1127 - v1129) & (~((v1127 - v1129) >> 31)));
  v1->timer = v1241;
  int v1131 = v1->timer;
  int * v1132 = v1->reg_ready;
  int v1133 = v1132[20];
  int v1244 = v1133 + ((v1131 - v1133) & (~((v1131 - v1133) >> 31)));
  v1->timer = v1244;
  int v1135 = v1->timer;
  int * v1136 = v1->reg_ready;
  int v1137 = v1136[21];
  int v1247 = v1137 + ((v1135 - v1137) & (~((v1135 - v1137) >> 31)));
  v1->timer = v1247;
  int v1139 = v1->timer;
  int * v1140 = v1->reg_ready;
  int v1141 = v1140[22];
  int v1250 = v1141 + ((v1139 - v1141) & (~((v1139 - v1141) >> 31)));
  v1->timer = v1250;
  int v1143 = v1->timer;
  int * v1144 = v1->reg_ready;
  int v1145 = v1144[23];
  int v1253 = v1145 + ((v1143 - v1145) & (~((v1143 - v1145) >> 31)));
  v1->timer = v1253;
  int v1147 = v1->timer;
  int * v1148 = v1->reg_ready;
  int v1149 = v1148[24];
  int v1256 = v1149 + ((v1147 - v1149) & (~((v1147 - v1149) >> 31)));
  v1->timer = v1256;
  int v1151 = v1->timer;
  int * v1152 = v1->reg_ready;
  int v1153 = v1152[25];
  int v1259 = v1153 + ((v1151 - v1153) & (~((v1151 - v1153) >> 31)));
  v1->timer = v1259;
  int v1155 = v1->timer;
  int * v1156 = v1->reg_ready;
  int v1157 = v1156[26];
  int v1262 = v1157 + ((v1155 - v1157) & (~((v1155 - v1157) >> 31)));
  v1->timer = v1262;
  int v1159 = v1->timer;
  int * v1160 = v1->reg_ready;
  int v1161 = v1160[27];
  int v1265 = v1161 + ((v1159 - v1161) & (~((v1159 - v1161) >> 31)));
  v1->timer = v1265;
  int v1163 = v1->timer;
  int * v1164 = v1->reg_ready;
  int v1165 = v1164[28];
  int v1268 = v1165 + ((v1163 - v1165) & (~((v1163 - v1165) >> 31)));
  v1->timer = v1268;
  int v1167 = v1->timer;
  int * v1168 = v1->reg_ready;
  int v1169 = v1168[29];
  int v1271 = v1169 + ((v1167 - v1169) & (~((v1167 - v1169) >> 31)));
  v1->timer = v1271;
  int v1171 = v1->timer;
  int * v1172 = v1->reg_ready;
  int v1173 = v1172[30];
  int v1274 = v1173 + ((v1171 - v1173) & (~((v1171 - v1173) >> 31)));
  v1->timer = v1274;
  int v1175 = v1->timer;
  int * v1176 = v1->reg_ready;
  int v1177 = v1176[31];
  int v1277 = v1177 + ((v1175 - v1177) & (~((v1175 - v1177) >> 31)));
  v1->timer = v1277;
  return v1;
}

struct StateT * slot_1(struct StateT * v20) {
  int v21 = v20->timer;
  int v22 = v20->timer;
  int v30 = v22 + 1;
  v20->timer = v30;
  int * v24 = v20->reg_ready;
  int v33 = v21 + 1;
  v24[7] = v33;
  int * v26 = v20->regs;
  v26[7] = 16;
  struct StateT * v28 = slot_2(v20);
  return v28;
}

struct StateT * slot_8(struct StateT * v1018) {
  int v1019 = v1018->timer;
  int v1020 = v1018->timer;
  int v1032 = v1020 + 1;
  v1018->timer = v1032;
  int * v1022 = v1018->reg_ready;
  int v1023 = v1022[6];
  int * v1024 = v1018->regs;
  int v1025 = v1024[6];
  int * v1026 = v1018->reg_ready;
  int v1037 = (v1023 + ((v1019 - v1023) & (~((v1019 - v1023) >> 31)))) + 1;
  v1026[6] = v1037;
  int * v1028 = v1018->regs;
  int v1039 = v1025 + 4;
  v1028[6] = v1039;
  struct StateT * v1030 = slot_9(v1018);
  return v1030;
}

struct StateT * slot_4(struct StateT * v84) {
  int v85 = v84->timer;
  int v86 = v84->timer;
  int v102 = v86 + 1;
  v84->timer = v102;
  int * v88 = v84->reg_ready;
  int v89 = v88[9];
  int * v90 = v84->regs;
  int v91 = v90[9];
  int * v92 = v84->reg_ready;
  int v93 = v92[6];
  int * v94 = v84->regs;
  int v95 = v94[6];
  int * v96 = v84->reg_ready;
  int v111 = (v93 + (((v89 + ((v85 - v89) & (~((v85 - v89) >> 31)))) - v93) & (~(((v89 + ((v85 - v89) & (~((v85 - v89) >> 31)))) - v93) >> 31)))) + 1;
  v96[8] = v111;
  int * v98 = v84->regs;
  int v113 = v91 + v95;
  v98[8] = v113;
  struct StateT * v100 = slot_5(v84);
  return v100;
}

struct StateT * slot_9(struct StateT * v1042) {
  int v1043 = v1042->timer;
  int v1044 = v1042->timer;
  int v1048 = v1044 + 1;
  v1042->timer = v1048;
  struct StateT * v1046 = slot_3(v1042);
  return v1046;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v4 = v2->timer;
  int v12 = v4 + 1;
  v2->timer = v12;
  int * v6 = v2->reg_ready;
  int v15 = v3 + 1;
  v6[6] = v15;
  int * v8 = v2->regs;
  v8[6] = 0;
  struct StateT * v10 = slot_1(v2);
  return v10;
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