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
struct StateT * slot_1(struct StateT * v19);
struct StateT * slot_8(struct StateT * v738);
struct StateT * slot_6(struct StateT * v472);
struct StateT * slot_2(struct StateT * v32);
struct StateT * slot_7(struct StateT * v722);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_1(struct StateT * v19) {
  int v20 = v19->timer;
  int v26 = v20 + 1;
  v19->timer = v26;
  int * v22 = v19->regs;
  v22[9] = 32;
  struct StateT * v24 = slot_2(v19);
  return v24;
}

struct StateT * slot_8(struct StateT * v738) {
  int v739 = v738->timer;
  int v871 = v739 + 1;
  v738->timer = v871;
  int * v741 = v738->regs;
  int v742 = v741[11];
  int * v743 = v738->cache_tags;
  int v875 = (((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1)) & 1) * 2;
  int v744 = v743[v875];
  int * v745 = v738->cache_tags;
  int v877 = ((((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1)) & 1) * 2) + 1;
  int v746 = v745[v877];
  int * v747 = v738->cache_tags;
  int v879 = 4 + ((((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1)) & 3) * 2);
  int v748 = v747[v879];
  int * v749 = v738->cache_tags;
  int v881 = (4 + ((((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v750 = v749[v881];
  int v751 = v738->timer;
  int v882 = v751 + ((100 ^ (((~(((v748 ^ ((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1))) | (-(v748 ^ ((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1))))) >> 31)) | (~(((v750 ^ ((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1))) | (-(v750 ^ ((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v744 ^ ((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1))) | (-(v744 ^ ((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1))))) >> 31)) | (~(((v746 ^ ((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1))) | (-(v746 ^ ((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v748 ^ ((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1))) | (-(v748 ^ ((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1))))) >> 31)) | (~(((v750 ^ ((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1))) | (-(v750 ^ ((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1))))) >> 31))) & 104)))));
  v738->timer = v882;
  int * v753 = v738->cache_vals;
  bool v883 = !(((~(((v744 ^ ((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1))) | (-(v744 ^ ((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1))))) >> 31)) | (~(((v746 ^ ((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1))) | (-(v746 ^ ((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1))))) >> 31))) == 0);
  int v866;
  if (v883) {
    int * v754 = v738->cache_age;
    int v885 = ((((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1)) & 1) * 2) + ((~(((v746 ^ ((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1))) | (-(v746 ^ ((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1))))) >> 31)) & 1);
    int v755 = v754[v885];
    int * v756 = v738->cache_age;
    int v757 = v756[v875];
    int * v758 = v738->cache_age;
    int v888 = v757 + ((int)((unsigned int)(v757 - v755) >> 31));
    v758[v875] = v888;
    int * v760 = v738->cache_age;
    int v761 = v760[v877];
    int * v762 = v738->cache_age;
    int v891 = v761 + ((int)((unsigned int)(v761 - v755) >> 31));
    v762[v877] = v891;
    int * v764 = v738->cache_age;
    v764[v885] = 0;
    v866 = v885;
  } else {
    int * v767 = v738->cache_age;
    int v895 = (((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1)) & 1) * 2;
    int v768 = v767[v895];
    int * v769 = v738->cache_tags;
    int v770 = v769[v895];
    int * v771 = v738->cache_age;
    int v772 = v771[v877];
    int * v773 = v738->cache_tags;
    int v774 = v773[v877];
    bool v899 = !(((~(((v748 ^ ((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1))) | (-(v748 ^ ((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1))))) >> 31)) | (~(((v750 ^ ((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1))) | (-(v750 ^ ((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1))))) >> 31))) == 0);
    int v838;
    if (v899) {
      int * v775 = v738->cache_age;
      int v901 = (4 + ((((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1)) & 3) * 2)) + ((~(((v750 ^ ((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1))) | (-(v750 ^ ((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1))))) >> 31)) & 1);
      int v776 = v775[v901];
      int * v777 = v738->cache_age;
      int v778 = v777[v879];
      int * v779 = v738->cache_age;
      int v904 = v778 + ((int)((unsigned int)(v778 - v776) >> 31));
      v779[v879] = v904;
      int * v781 = v738->cache_age;
      int v782 = v781[v881];
      int * v783 = v738->cache_age;
      int v907 = v782 + ((int)((unsigned int)(v782 - v776) >> 31));
      v783[v881] = v907;
      int * v785 = v738->cache_age;
      v785[v901] = 0;
      v838 = v901;
    } else {
      int * v788 = v738->cache_age;
      int v911 = 4 + ((((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1)) & 3) * 2);
      int v789 = v788[v911];
      int * v790 = v738->cache_tags;
      int v791 = v790[v911];
      int * v792 = v738->cache_age;
      int v793 = v792[v881];
      int * v794 = v738->cache_tags;
      int v795 = v794[v881];
      int * v796 = v738->cache_dirty;
      int v916 = (4 + ((((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1)) & 3) * 2)) + ((((v789 + ((~(((v791 ^ -1) | (-(v791 ^ -1))) >> 31)) & 2)) - (v793 + ((~(((v795 ^ -1) | (-(v795 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v797 = v796[v916];
      bool v917 = !(v797 == 0);
      if (v917) {
        int * v798 = v738->cache_tags;
        int v799 = v798[v916];
        int * v800 = v738->cache_vals;
        int v920 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1)) & 3) * 2)) + ((((v789 + ((~(((v791 ^ -1) | (-(v791 ^ -1))) >> 31)) & 2)) - (v793 + ((~(((v795 ^ -1) | (-(v795 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v801 = v800[v920];
        int * v802 = v738->cache_vals;
        int v922 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1)) & 3) * 2)) + ((((v789 + ((~(((v791 ^ -1) | (-(v791 ^ -1))) >> 31)) & 2)) - (v793 + ((~(((v795 ^ -1) | (-(v795 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v803 = v802[v922];
        int * v804 = v738->mem;
        int v924 = v799 * 2;
        v804[v924] = v801;
        int * v806 = v738->mem;
        int v927 = (v799 * 2) + 1;
        v806[v927] = v803;
        ;
      } else {
        ;
      }
      int * v811 = v738->mem;
      int v932 = ((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1)) * 2;
      int v812 = v811[v932];
      int * v813 = v738->mem;
      int v934 = (((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1)) * 2) + 1;
      int v814 = v813[v934];
      int * v815 = v738->cache_vals;
      int v936 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1)) & 3) * 2)) + ((((v789 + ((~(((v791 ^ -1) | (-(v791 ^ -1))) >> 31)) & 2)) - (v793 + ((~(((v795 ^ -1) | (-(v795 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v815[v936] = v812;
      int * v817 = v738->cache_vals;
      int v939 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1)) & 3) * 2)) + ((((v789 + ((~(((v791 ^ -1) | (-(v791 ^ -1))) >> 31)) & 2)) - (v793 + ((~(((v795 ^ -1) | (-(v795 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v817[v939] = v814;
      int * v819 = v738->cache_tags;
      int v942 = (int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1);
      v819[v916] = v942;
      int * v821 = v738->cache_dirty;
      v821[v916] = 0;
      int * v823 = v738->cache_age;
      v823[v916] = 1;
      int * v825 = v738->cache_age;
      int v826 = v825[v916];
      int * v827 = v738->cache_age;
      int v828 = v827[v879];
      int * v829 = v738->cache_age;
      int v950 = v828 + ((int)((unsigned int)(v828 - v826) >> 31));
      v829[v879] = v950;
      int * v831 = v738->cache_age;
      int v832 = v831[v881];
      int * v833 = v738->cache_age;
      int v953 = v832 + ((int)((unsigned int)(v832 - v826) >> 31));
      v833[v881] = v953;
      int * v835 = v738->cache_age;
      v835[v916] = 0;
      v838 = v916;
    }
    int * v839 = v738->cache_vals;
    int v956 = v838 * 2;
    int v840 = v839[v956];
    int * v841 = v738->cache_vals;
    int v958 = (v838 * 2) + 1;
    int v842 = v841[v958];
    int * v843 = v738->cache_vals;
    int v960 = (((((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1)) & 1) * 2) + ((((v768 + ((~(((v770 ^ -1) | (-(v770 ^ -1))) >> 31)) & 2)) - (v772 + ((~(((v774 ^ -1) | (-(v774 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v843[v960] = v840;
    int * v845 = v738->cache_vals;
    int v963 = ((((((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1)) & 1) * 2) + ((((v768 + ((~(((v770 ^ -1) | (-(v770 ^ -1))) >> 31)) & 2)) - (v772 + ((~(((v774 ^ -1) | (-(v774 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v845[v963] = v842;
    int * v847 = v738->cache_tags;
    int v966 = ((((int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1)) & 1) * 2) + ((((v768 + ((~(((v770 ^ -1) | (-(v770 ^ -1))) >> 31)) & 2)) - (v772 + ((~(((v774 ^ -1) | (-(v774 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v967 = (int)((unsigned int)((int)((unsigned int)v742 >> 2)) >> 1);
    v847[v966] = v967;
    int * v849 = v738->cache_dirty;
    v849[v966] = 0;
    int * v851 = v738->cache_age;
    v851[v966] = 1;
    int * v853 = v738->cache_age;
    int v854 = v853[v966];
    int * v855 = v738->cache_age;
    int v856 = v855[v875];
    int * v857 = v738->cache_age;
    int v975 = v856 + ((int)((unsigned int)(v856 - v854) >> 31));
    v857[v875] = v975;
    int * v859 = v738->cache_age;
    int v860 = v859[v877];
    int * v861 = v738->cache_age;
    int v978 = v860 + ((int)((unsigned int)(v860 - v854) >> 31));
    v861[v877] = v978;
    int * v863 = v738->cache_age;
    v863[v966] = 0;
    v866 = v966;
  }
  int v981 = (v866 * 2) + (((int)((unsigned int)v742 >> 2)) & 1);
  int v867 = v753[v981];
  int * v868 = v738->regs;
  v868[12] = v867;
  return v738;
}

struct StateT * slot_6(struct StateT * v472) {
  int v473 = v472->timer;
  int v606 = v473 + 1;
  v472->timer = v606;
  int * v475 = v472->regs;
  int v476 = v475[6];
  int * v477 = v472->cache_tags;
  int v610 = (((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1)) & 1) * 2;
  int v478 = v477[v610];
  int * v479 = v472->cache_tags;
  int v612 = ((((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1)) & 1) * 2) + 1;
  int v480 = v479[v612];
  int * v481 = v472->cache_tags;
  int v614 = 4 + ((((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1)) & 3) * 2);
  int v482 = v481[v614];
  int * v483 = v472->cache_tags;
  int v616 = (4 + ((((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v484 = v483[v616];
  int v485 = v472->timer;
  int v617 = v485 + ((100 ^ (((~(((v482 ^ ((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1))) | (-(v482 ^ ((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1))))) >> 31)) | (~(((v484 ^ ((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1))) | (-(v484 ^ ((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v478 ^ ((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1))) | (-(v478 ^ ((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1))))) >> 31)) | (~(((v480 ^ ((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1))) | (-(v480 ^ ((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v482 ^ ((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1))) | (-(v482 ^ ((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1))))) >> 31)) | (~(((v484 ^ ((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1))) | (-(v484 ^ ((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1))))) >> 31))) & 104)))));
  v472->timer = v617;
  int * v487 = v472->cache_vals;
  bool v618 = !(((~(((v478 ^ ((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1))) | (-(v478 ^ ((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1))))) >> 31)) | (~(((v480 ^ ((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1))) | (-(v480 ^ ((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1))))) >> 31))) == 0);
  int v600;
  if (v618) {
    int * v488 = v472->cache_age;
    int v620 = ((((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1)) & 1) * 2) + ((~(((v480 ^ ((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1))) | (-(v480 ^ ((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1))))) >> 31)) & 1);
    int v489 = v488[v620];
    int * v490 = v472->cache_age;
    int v491 = v490[v610];
    int * v492 = v472->cache_age;
    int v623 = v491 + ((int)((unsigned int)(v491 - v489) >> 31));
    v492[v610] = v623;
    int * v494 = v472->cache_age;
    int v495 = v494[v612];
    int * v496 = v472->cache_age;
    int v626 = v495 + ((int)((unsigned int)(v495 - v489) >> 31));
    v496[v612] = v626;
    int * v498 = v472->cache_age;
    v498[v620] = 0;
    v600 = v620;
  } else {
    int * v501 = v472->cache_age;
    int v630 = (((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1)) & 1) * 2;
    int v502 = v501[v630];
    int * v503 = v472->cache_tags;
    int v504 = v503[v630];
    int * v505 = v472->cache_age;
    int v506 = v505[v612];
    int * v507 = v472->cache_tags;
    int v508 = v507[v612];
    bool v634 = !(((~(((v482 ^ ((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1))) | (-(v482 ^ ((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1))))) >> 31)) | (~(((v484 ^ ((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1))) | (-(v484 ^ ((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1))))) >> 31))) == 0);
    int v572;
    if (v634) {
      int * v509 = v472->cache_age;
      int v636 = (4 + ((((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1)) & 3) * 2)) + ((~(((v484 ^ ((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1))) | (-(v484 ^ ((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1))))) >> 31)) & 1);
      int v510 = v509[v636];
      int * v511 = v472->cache_age;
      int v512 = v511[v614];
      int * v513 = v472->cache_age;
      int v639 = v512 + ((int)((unsigned int)(v512 - v510) >> 31));
      v513[v614] = v639;
      int * v515 = v472->cache_age;
      int v516 = v515[v616];
      int * v517 = v472->cache_age;
      int v642 = v516 + ((int)((unsigned int)(v516 - v510) >> 31));
      v517[v616] = v642;
      int * v519 = v472->cache_age;
      v519[v636] = 0;
      v572 = v636;
    } else {
      int * v522 = v472->cache_age;
      int v646 = 4 + ((((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1)) & 3) * 2);
      int v523 = v522[v646];
      int * v524 = v472->cache_tags;
      int v525 = v524[v646];
      int * v526 = v472->cache_age;
      int v527 = v526[v616];
      int * v528 = v472->cache_tags;
      int v529 = v528[v616];
      int * v530 = v472->cache_dirty;
      int v651 = (4 + ((((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1)) & 3) * 2)) + ((((v523 + ((~(((v525 ^ -1) | (-(v525 ^ -1))) >> 31)) & 2)) - (v527 + ((~(((v529 ^ -1) | (-(v529 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v531 = v530[v651];
      bool v652 = !(v531 == 0);
      if (v652) {
        int * v532 = v472->cache_tags;
        int v533 = v532[v651];
        int * v534 = v472->cache_vals;
        int v655 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1)) & 3) * 2)) + ((((v523 + ((~(((v525 ^ -1) | (-(v525 ^ -1))) >> 31)) & 2)) - (v527 + ((~(((v529 ^ -1) | (-(v529 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v535 = v534[v655];
        int * v536 = v472->cache_vals;
        int v657 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1)) & 3) * 2)) + ((((v523 + ((~(((v525 ^ -1) | (-(v525 ^ -1))) >> 31)) & 2)) - (v527 + ((~(((v529 ^ -1) | (-(v529 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v537 = v536[v657];
        int * v538 = v472->mem;
        int v659 = v533 * 2;
        v538[v659] = v535;
        int * v540 = v472->mem;
        int v662 = (v533 * 2) + 1;
        v540[v662] = v537;
        ;
      } else {
        ;
      }
      int * v545 = v472->mem;
      int v667 = ((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1)) * 2;
      int v546 = v545[v667];
      int * v547 = v472->mem;
      int v669 = (((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1)) * 2) + 1;
      int v548 = v547[v669];
      int * v549 = v472->cache_vals;
      int v671 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1)) & 3) * 2)) + ((((v523 + ((~(((v525 ^ -1) | (-(v525 ^ -1))) >> 31)) & 2)) - (v527 + ((~(((v529 ^ -1) | (-(v529 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v549[v671] = v546;
      int * v551 = v472->cache_vals;
      int v674 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1)) & 3) * 2)) + ((((v523 + ((~(((v525 ^ -1) | (-(v525 ^ -1))) >> 31)) & 2)) - (v527 + ((~(((v529 ^ -1) | (-(v529 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v551[v674] = v548;
      int * v553 = v472->cache_tags;
      int v677 = (int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1);
      v553[v651] = v677;
      int * v555 = v472->cache_dirty;
      v555[v651] = 0;
      int * v557 = v472->cache_age;
      v557[v651] = 1;
      int * v559 = v472->cache_age;
      int v560 = v559[v651];
      int * v561 = v472->cache_age;
      int v562 = v561[v614];
      int * v563 = v472->cache_age;
      int v685 = v562 + ((int)((unsigned int)(v562 - v560) >> 31));
      v563[v614] = v685;
      int * v565 = v472->cache_age;
      int v566 = v565[v616];
      int * v567 = v472->cache_age;
      int v688 = v566 + ((int)((unsigned int)(v566 - v560) >> 31));
      v567[v616] = v688;
      int * v569 = v472->cache_age;
      v569[v651] = 0;
      v572 = v651;
    }
    int * v573 = v472->cache_vals;
    int v691 = v572 * 2;
    int v574 = v573[v691];
    int * v575 = v472->cache_vals;
    int v693 = (v572 * 2) + 1;
    int v576 = v575[v693];
    int * v577 = v472->cache_vals;
    int v695 = (((((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1)) & 1) * 2) + ((((v502 + ((~(((v504 ^ -1) | (-(v504 ^ -1))) >> 31)) & 2)) - (v506 + ((~(((v508 ^ -1) | (-(v508 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v577[v695] = v574;
    int * v579 = v472->cache_vals;
    int v698 = ((((((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1)) & 1) * 2) + ((((v502 + ((~(((v504 ^ -1) | (-(v504 ^ -1))) >> 31)) & 2)) - (v506 + ((~(((v508 ^ -1) | (-(v508 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v579[v698] = v576;
    int * v581 = v472->cache_tags;
    int v701 = ((((int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1)) & 1) * 2) + ((((v502 + ((~(((v504 ^ -1) | (-(v504 ^ -1))) >> 31)) & 2)) - (v506 + ((~(((v508 ^ -1) | (-(v508 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v702 = (int)((unsigned int)((int)((unsigned int)v476 >> 2)) >> 1);
    v581[v701] = v702;
    int * v583 = v472->cache_dirty;
    v583[v701] = 0;
    int * v585 = v472->cache_age;
    v585[v701] = 1;
    int * v587 = v472->cache_age;
    int v588 = v587[v701];
    int * v589 = v472->cache_age;
    int v590 = v589[v610];
    int * v591 = v472->cache_age;
    int v710 = v590 + ((int)((unsigned int)(v590 - v588) >> 31));
    v591[v610] = v710;
    int * v593 = v472->cache_age;
    int v594 = v593[v612];
    int * v595 = v472->cache_age;
    int v713 = v594 + ((int)((unsigned int)(v594 - v588) >> 31));
    v595[v612] = v713;
    int * v597 = v472->cache_age;
    v597[v701] = 0;
    v600 = v701;
  }
  int v716 = (v600 * 2) + (((int)((unsigned int)v476 >> 2)) & 1);
  int v601 = v487[v716];
  int * v602 = v472->regs;
  v602[11] = v601;
  struct StateT * v604 = slot_7(v472);
  return v604;
}

struct StateT * slot_2(struct StateT * v32) {
  int * v33 = v32->saved_regs;
  int * v34 = v32->regs;
  int v35 = v34[6];
  v33[6] = v35;
  int v37 = v32->timer;
  int v277 = v37 + 1;
  v32->timer = v277;
  int * v39 = v32->regs;
  int v40 = v39[5];
  int * v41 = v32->regs;
  int v281 = v40 + 80;
  v41[6] = v281;
  int * v43 = v32->saved_regs;
  int * v44 = v32->regs;
  int v45 = v44[7];
  v43[7] = v45;
  int v47 = v32->timer;
  int v286 = v47 + 1;
  v32->timer = v286;
  int * v49 = v32->regs;
  v49[7] = 0;
  int * v51 = v32->regs;
  int v52 = v51[5];
  int * v53 = v32->regs;
  int v54 = v53[9];
  bool v292 = v52 >= v54;
  struct StateT * v271;
  if (v292) {
    int v55 = v32->timer;
    int v293 = v55 + 15;
    v32->timer = v293;
    int * v57 = v32->saved_regs;
    int v58 = v57[6];
    int * v59 = v32->regs;
    v59[6] = v58;
    int * v61 = v32->saved_regs;
    int v62 = v61[7];
    int * v63 = v32->regs;
    v63[7] = v62;
    v271 = v32;
  } else {
    int v66 = v32->timer;
    int v300 = v66 + 1;
    v32->timer = v300;
    int * v68 = v32->regs;
    int v69 = v68[6];
    int * v70 = v32->regs;
    int v71 = v70[7];
    int * v72 = v32->cache_tags;
    int v304 = (((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 1) * 2;
    int v73 = v72[v304];
    int * v74 = v32->cache_tags;
    int v306 = ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 1) * 2) + 1;
    int v75 = v74[v306];
    int * v76 = v32->cache_tags;
    int v308 = 4 + ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 3) * 2);
    int v77 = v76[v308];
    int * v78 = v32->cache_tags;
    int v310 = (4 + ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 3) * 2)) + 1;
    int v79 = v78[v310];
    int v80 = v32->timer;
    int v311 = v80 + ((100 ^ (((~(((v77 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))) | (-(v77 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))))) >> 31)) | (~(((v79 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))) | (-(v79 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v73 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))) | (-(v73 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))))) >> 31)) | (~(((v75 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))) | (-(v75 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v77 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))) | (-(v77 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))))) >> 31)) | (~(((v79 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))) | (-(v79 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))))) >> 31))) & 104)))));
    v32->timer = v311;
    bool v312 = !(((~(((v73 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))) | (-(v73 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))))) >> 31)) | (~(((v75 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))) | (-(v75 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))))) >> 31))) == 0);
    int v194;
    if (v312) {
      int * v82 = v32->cache_age;
      int v314 = ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 1) * 2) + ((~(((v75 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))) | (-(v75 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))))) >> 31)) & 1);
      int v83 = v82[v314];
      int * v84 = v32->cache_age;
      int v85 = v84[v304];
      int * v86 = v32->cache_age;
      int v317 = v85 + ((int)((unsigned int)(v85 - v83) >> 31));
      v86[v304] = v317;
      int * v88 = v32->cache_age;
      int v89 = v88[v306];
      int * v90 = v32->cache_age;
      int v320 = v89 + ((int)((unsigned int)(v89 - v83) >> 31));
      v90[v306] = v320;
      int * v92 = v32->cache_age;
      v92[v314] = 0;
      v194 = v314;
    } else {
      int * v95 = v32->cache_age;
      int v323 = (((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 1) * 2;
      int v96 = v95[v323];
      int * v97 = v32->cache_tags;
      int v98 = v97[v323];
      int * v99 = v32->cache_age;
      int v100 = v99[v306];
      int * v101 = v32->cache_tags;
      int v102 = v101[v306];
      bool v327 = !(((~(((v77 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))) | (-(v77 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))))) >> 31)) | (~(((v79 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))) | (-(v79 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))))) >> 31))) == 0);
      int v166;
      if (v327) {
        int * v103 = v32->cache_age;
        int v329 = (4 + ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 3) * 2)) + ((~(((v79 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))) | (-(v79 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))))) >> 31)) & 1);
        int v104 = v103[v329];
        int * v105 = v32->cache_age;
        int v106 = v105[v308];
        int * v107 = v32->cache_age;
        int v332 = v106 + ((int)((unsigned int)(v106 - v104) >> 31));
        v107[v308] = v332;
        int * v109 = v32->cache_age;
        int v110 = v109[v310];
        int * v111 = v32->cache_age;
        int v335 = v110 + ((int)((unsigned int)(v110 - v104) >> 31));
        v111[v310] = v335;
        int * v113 = v32->cache_age;
        v113[v329] = 0;
        v166 = v329;
      } else {
        int * v116 = v32->cache_age;
        int v338 = 4 + ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 3) * 2);
        int v117 = v116[v338];
        int * v118 = v32->cache_tags;
        int v119 = v118[v338];
        int * v120 = v32->cache_age;
        int v121 = v120[v310];
        int * v122 = v32->cache_tags;
        int v123 = v122[v310];
        int * v124 = v32->cache_dirty;
        int v343 = (4 + ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 3) * 2)) + ((((v117 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2)) - (v121 + ((~(((v123 ^ -1) | (-(v123 ^ -1))) >> 31)) & 2))) >> 31) & 1);
        int v125 = v124[v343];
        bool v344 = !(v125 == 0);
        if (v344) {
          int * v126 = v32->cache_tags;
          int v127 = v126[v343];
          int * v128 = v32->cache_vals;
          int v347 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 3) * 2)) + ((((v117 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2)) - (v121 + ((~(((v123 ^ -1) | (-(v123 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
          int v129 = v128[v347];
          int * v130 = v32->cache_vals;
          int v349 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 3) * 2)) + ((((v117 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2)) - (v121 + ((~(((v123 ^ -1) | (-(v123 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
          int v131 = v130[v349];
          int * v132 = v32->mem;
          int v351 = v127 * 2;
          v132[v351] = v129;
          int * v134 = v32->mem;
          int v354 = (v127 * 2) + 1;
          v134[v354] = v131;
          ;
        } else {
          ;
        }
        int * v139 = v32->mem;
        int v359 = ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) * 2;
        int v140 = v139[v359];
        int * v141 = v32->mem;
        int v361 = (((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) * 2) + 1;
        int v142 = v141[v361];
        int * v143 = v32->cache_vals;
        int v363 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 3) * 2)) + ((((v117 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2)) - (v121 + ((~(((v123 ^ -1) | (-(v123 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        v143[v363] = v140;
        int * v145 = v32->cache_vals;
        int v366 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 3) * 2)) + ((((v117 + ((~(((v119 ^ -1) | (-(v119 ^ -1))) >> 31)) & 2)) - (v121 + ((~(((v123 ^ -1) | (-(v123 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        v145[v366] = v142;
        int * v147 = v32->cache_tags;
        int v369 = (int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1);
        v147[v343] = v369;
        int * v149 = v32->cache_dirty;
        v149[v343] = 0;
        int * v151 = v32->cache_age;
        v151[v343] = 1;
        int * v153 = v32->cache_age;
        int v154 = v153[v343];
        int * v155 = v32->cache_age;
        int v156 = v155[v308];
        int * v157 = v32->cache_age;
        int v376 = v156 + ((int)((unsigned int)(v156 - v154) >> 31));
        v157[v308] = v376;
        int * v159 = v32->cache_age;
        int v160 = v159[v310];
        int * v161 = v32->cache_age;
        int v379 = v160 + ((int)((unsigned int)(v160 - v154) >> 31));
        v161[v310] = v379;
        int * v163 = v32->cache_age;
        v163[v343] = 0;
        v166 = v343;
      }
      int * v167 = v32->cache_vals;
      int v382 = v166 * 2;
      int v168 = v167[v382];
      int * v169 = v32->cache_vals;
      int v384 = (v166 * 2) + 1;
      int v170 = v169[v384];
      int * v171 = v32->cache_vals;
      int v386 = (((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 1) * 2) + ((((v96 + ((~(((v98 ^ -1) | (-(v98 ^ -1))) >> 31)) & 2)) - (v100 + ((~(((v102 ^ -1) | (-(v102 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v171[v386] = v168;
      int * v173 = v32->cache_vals;
      int v389 = ((((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 1) * 2) + ((((v96 + ((~(((v98 ^ -1) | (-(v98 ^ -1))) >> 31)) & 2)) - (v100 + ((~(((v102 ^ -1) | (-(v102 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v173[v389] = v170;
      int * v175 = v32->cache_tags;
      int v392 = ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 1) * 2) + ((((v96 + ((~(((v98 ^ -1) | (-(v98 ^ -1))) >> 31)) & 2)) - (v100 + ((~(((v102 ^ -1) | (-(v102 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v393 = (int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1);
      v175[v392] = v393;
      int * v177 = v32->cache_dirty;
      v177[v392] = 0;
      int * v179 = v32->cache_age;
      v179[v392] = 1;
      int * v181 = v32->cache_age;
      int v182 = v181[v392];
      int * v183 = v32->cache_age;
      int v184 = v183[v304];
      int * v185 = v32->cache_age;
      int v400 = v184 + ((int)((unsigned int)(v184 - v182) >> 31));
      v185[v304] = v400;
      int * v187 = v32->cache_age;
      int v188 = v187[v306];
      int * v189 = v32->cache_age;
      int v403 = v188 + ((int)((unsigned int)(v188 - v182) >> 31));
      v189[v306] = v403;
      int * v191 = v32->cache_age;
      v191[v392] = 0;
      v194 = v392;
    }
    int * v195 = v32->cache_vals;
    int v406 = (v194 * 2) + (((int)((unsigned int)v69 >> 2)) & 1);
    v195[v406] = v71;
    int * v197 = v32->cache_tags;
    int v198 = v197[v308];
    int * v199 = v32->cache_tags;
    int v200 = v199[v310];
    bool v410 = !(((~(((v198 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))) | (-(v198 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))))) >> 31)) | (~(((v200 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))) | (-(v200 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))))) >> 31))) == 0);
    int v264;
    if (v410) {
      int * v201 = v32->cache_age;
      int v412 = (4 + ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 3) * 2)) + ((~(((v200 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))) | (-(v200 ^ ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1))))) >> 31)) & 1);
      int v202 = v201[v412];
      int * v203 = v32->cache_age;
      int v204 = v203[v308];
      int * v205 = v32->cache_age;
      int v415 = v204 + ((int)((unsigned int)(v204 - v202) >> 31));
      v205[v308] = v415;
      int * v207 = v32->cache_age;
      int v208 = v207[v310];
      int * v209 = v32->cache_age;
      int v418 = v208 + ((int)((unsigned int)(v208 - v202) >> 31));
      v209[v310] = v418;
      int * v211 = v32->cache_age;
      v211[v412] = 0;
      v264 = v412;
    } else {
      int * v214 = v32->cache_age;
      int v421 = 4 + ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 3) * 2);
      int v215 = v214[v421];
      int * v216 = v32->cache_tags;
      int v217 = v216[v421];
      int * v218 = v32->cache_age;
      int v219 = v218[v310];
      int * v220 = v32->cache_tags;
      int v221 = v220[v310];
      int * v222 = v32->cache_dirty;
      int v426 = (4 + ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 3) * 2)) + ((((v215 + ((~(((v217 ^ -1) | (-(v217 ^ -1))) >> 31)) & 2)) - (v219 + ((~(((v221 ^ -1) | (-(v221 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v223 = v222[v426];
      bool v427 = !(v223 == 0);
      if (v427) {
        int * v224 = v32->cache_tags;
        int v225 = v224[v426];
        int * v226 = v32->cache_vals;
        int v430 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 3) * 2)) + ((((v215 + ((~(((v217 ^ -1) | (-(v217 ^ -1))) >> 31)) & 2)) - (v219 + ((~(((v221 ^ -1) | (-(v221 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v227 = v226[v430];
        int * v228 = v32->cache_vals;
        int v432 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 3) * 2)) + ((((v215 + ((~(((v217 ^ -1) | (-(v217 ^ -1))) >> 31)) & 2)) - (v219 + ((~(((v221 ^ -1) | (-(v221 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v229 = v228[v432];
        int * v230 = v32->mem;
        int v434 = v225 * 2;
        v230[v434] = v227;
        int * v232 = v32->mem;
        int v437 = (v225 * 2) + 1;
        v232[v437] = v229;
        ;
      } else {
        ;
      }
      int * v237 = v32->mem;
      int v442 = ((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) * 2;
      int v238 = v237[v442];
      int * v239 = v32->mem;
      int v444 = (((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) * 2) + 1;
      int v240 = v239[v444];
      int * v241 = v32->cache_vals;
      int v446 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 3) * 2)) + ((((v215 + ((~(((v217 ^ -1) | (-(v217 ^ -1))) >> 31)) & 2)) - (v219 + ((~(((v221 ^ -1) | (-(v221 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v241[v446] = v238;
      int * v243 = v32->cache_vals;
      int v449 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1)) & 3) * 2)) + ((((v215 + ((~(((v217 ^ -1) | (-(v217 ^ -1))) >> 31)) & 2)) - (v219 + ((~(((v221 ^ -1) | (-(v221 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v243[v449] = v240;
      int * v245 = v32->cache_tags;
      int v452 = (int)((unsigned int)((int)((unsigned int)v69 >> 2)) >> 1);
      v245[v426] = v452;
      int * v247 = v32->cache_dirty;
      v247[v426] = 0;
      int * v249 = v32->cache_age;
      v249[v426] = 1;
      int * v251 = v32->cache_age;
      int v252 = v251[v426];
      int * v253 = v32->cache_age;
      int v254 = v253[v308];
      int * v255 = v32->cache_age;
      int v459 = v254 + ((int)((unsigned int)(v254 - v252) >> 31));
      v255[v308] = v459;
      int * v257 = v32->cache_age;
      int v258 = v257[v310];
      int * v259 = v32->cache_age;
      int v462 = v258 + ((int)((unsigned int)(v258 - v252) >> 31));
      v259[v310] = v462;
      int * v261 = v32->cache_age;
      v261[v426] = 0;
      v264 = v426;
    }
    int * v265 = v32->cache_vals;
    int v465 = (v264 * 2) + (((int)((unsigned int)v69 >> 2)) & 1);
    v265[v465] = v71;
    int * v267 = v32->cache_dirty;
    v267[v264] = 1;
    struct StateT * v269 = slot_6(v32);
    v271 = v269;
  }
  return v271;
}

struct StateT * slot_7(struct StateT * v722) {
  int v723 = v722->timer;
  int v731 = v723 + 1;
  v722->timer = v731;
  int * v725 = v722->regs;
  int v726 = v725[11];
  int * v727 = v722->regs;
  int v735 = v726 << 2;
  v727[11] = v735;
  struct StateT * v729 = slot_8(v722);
  return v729;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->regs;
  int v6 = v5[10];
  int * v7 = v2->regs;
  int v16 = v6 & 28;
  v7[5] = v16;
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