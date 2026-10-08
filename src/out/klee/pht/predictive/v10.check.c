// verify: clean (KLEE should report no failing assertion) [budget 1200s]
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

struct StateT * slot_12(struct StateT * v521);
struct StateT * slot_14(struct StateT * v548);
struct StateT * slot_16(struct StateT * v561);
struct StateT * slot_5(struct StateT * v253);
struct StateT * slot_17(struct StateT * v574);
struct StateT * slot_20(struct StateT * v997);
struct StateT * slot_2(struct StateT * v218);
struct StateT * slot_7(struct StateT * v267);
struct StateT * slot_21(struct StateT * v1312);
struct StateT * slot_3(struct StateT * v226);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_10(struct StateT * v310);
struct StateT * slot_1(struct StateT * v15);
struct StateT * slot_8(struct StateT * v280);
struct StateT * slot_19(struct StateT * v981);
struct StateT * slot_18(struct StateT * v777);
struct StateT * slot_9(struct StateT * v294);
struct StateT * slot_11(struct StateT * v513);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_12(struct StateT * v521) {
  int * v522 = v521->regs;
  int v523 = v522[10];
  int v524 = v522[11];
  bool v536 = !(v523 == v524);
  struct StateT * v531;
  if (v536) {
    int v525 = v521->timer;
    int v537 = v525 + 15;
    v521->timer = v537;
    struct StateT * v527 = slot_21(v521);
    v531 = v527;
  } else {
    struct StateT * v529 = slot_14(v521);
    v531 = v529;
  }
  return v531;
}

struct StateT * slot_14(struct StateT * v548) {
  int v549 = v548->timer;
  int v555 = v549 + 1;
  v548->timer = v555;
  int * v551 = v548->regs;
  v551[10] = 0;
  struct StateT * v553 = slot_16(v548);
  return v553;
}

struct StateT * slot_16(struct StateT * v561) {
  int v562 = v561->timer;
  int v568 = v562 + 1;
  v561->timer = v568;
  int * v564 = v561->regs;
  v564[11] = 0;
  struct StateT * v566 = slot_17(v561);
  return v566;
}

struct StateT * slot_5(struct StateT * v253) {
  int v254 = v253->timer;
  int v261 = v254 + 1;
  v253->timer = v261;
  int * v256 = v253->regs;
  int v257 = v256[10];
  int v264 = v257 << 2;
  v256[10] = v264;
  struct StateT * v259 = slot_7(v253);
  return v259;
}

struct StateT * slot_17(struct StateT * v574) {
  int v575 = v574->timer;
  int v685 = v575 + 1;
  v574->timer = v685;
  int * v577 = v574->regs;
  int v578 = v577[10];
  int * v579 = v574->cache_tags;
  int v689 = (((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1)) & 1) * 2;
  int v580 = v579[v689];
  int v690 = ((((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v581 = v579[v690];
  int v691 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1)) & 3) * 2);
  int v582 = v579[v691];
  int v692 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v583 = v579[v692];
  int v584 = v574->timer;
  int v693 = v584 + ((100 ^ (((~(((v582 ^ ((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1))) | (-(v582 ^ ((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v583 ^ ((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1))) | (-(v583 ^ ((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v580 ^ ((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1))) | (-(v580 ^ ((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v581 ^ ((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1))) | (-(v581 ^ ((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v582 ^ ((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1))) | (-(v582 ^ ((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v583 ^ ((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1))) | (-(v583 ^ ((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v574->timer = v693;
  int * v586 = v574->cache_vals;
  bool v694 = !(((~(((v580 ^ ((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1))) | (-(v580 ^ ((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v581 ^ ((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1))) | (-(v581 ^ ((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v679;
  if (v694) {
    int * v587 = v574->cache_age;
    int v696 = ((((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v581 ^ ((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1))) | (-(v581 ^ ((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v588 = v587[v696];
    int v589 = v587[v689];
    int v697 = v589 + ((int)((unsigned int)(v589 - v588) >> 31));
    v587[v689] = v697;
    int * v591 = v574->cache_age;
    int v592 = v591[v690];
    int v699 = v592 + ((int)((unsigned int)(v592 - v588) >> 31));
    v591[v690] = v699;
    int * v594 = v574->cache_age;
    v594[v696] = 0;
    v679 = v696;
  } else {
    int * v597 = v574->cache_age;
    int v703 = (((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1)) & 1) * 2;
    int v598 = v597[v703];
    int * v599 = v574->cache_tags;
    int v600 = v599[v703];
    int v601 = v597[v690];
    int v602 = v599[v690];
    bool v705 = !(((~(((v582 ^ ((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1))) | (-(v582 ^ ((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v583 ^ ((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1))) | (-(v583 ^ ((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v656;
    if (v705) {
      int * v603 = v574->cache_age;
      int v707 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v583 ^ ((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1))) | (-(v583 ^ ((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v604 = v603[v707];
      int v605 = v603[v691];
      int v708 = v605 + ((int)((unsigned int)(v605 - v604) >> 31));
      v603[v691] = v708;
      int * v607 = v574->cache_age;
      int v608 = v607[v692];
      int v710 = v608 + ((int)((unsigned int)(v608 - v604) >> 31));
      v607[v692] = v710;
      int * v610 = v574->cache_age;
      v610[v707] = 0;
      v656 = v707;
    } else {
      int * v613 = v574->cache_age;
      int v714 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1)) & 3) * 2);
      int v614 = v613[v714];
      int * v615 = v574->cache_tags;
      int v616 = v615[v714];
      int v617 = v613[v692];
      int v618 = v615[v692];
      int * v619 = v574->cache_dirty;
      int v717 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v614 + ((~(((v616 ^ -1) | (-(v616 ^ -1))) >> 31)) & 2)) - (v617 + ((~(((v618 ^ -1) | (-(v618 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v620 = v619[v717];
      bool v718 = !(v620 == 0);
      if (v718) {
        int * v621 = v574->cache_tags;
        int v622 = v621[v717];
        int * v623 = v574->cache_vals;
        int v721 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v614 + ((~(((v616 ^ -1) | (-(v616 ^ -1))) >> 31)) & 2)) - (v617 + ((~(((v618 ^ -1) | (-(v618 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v624 = v623[v721];
        int v722 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v614 + ((~(((v616 ^ -1) | (-(v616 ^ -1))) >> 31)) & 2)) - (v617 + ((~(((v618 ^ -1) | (-(v618 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v625 = v623[v722];
        int * v626 = v574->mem;
        int v724 = v622 * 2;
        v626[v724] = v624;
        int * v628 = v574->mem;
        int v727 = (v622 * 2) + 1;
        v628[v727] = v625;
        ;
      } else {
        ;
      }
      int * v633 = v574->mem;
      int v732 = ((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1)) * 2;
      int v634 = v633[v732];
      int v733 = (((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1)) * 2) + 1;
      int v635 = v633[v733];
      int * v636 = v574->cache_vals;
      int v735 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v614 + ((~(((v616 ^ -1) | (-(v616 ^ -1))) >> 31)) & 2)) - (v617 + ((~(((v618 ^ -1) | (-(v618 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v636[v735] = v634;
      int * v638 = v574->cache_vals;
      int v738 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v614 + ((~(((v616 ^ -1) | (-(v616 ^ -1))) >> 31)) & 2)) - (v617 + ((~(((v618 ^ -1) | (-(v618 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v638[v738] = v635;
      int * v640 = v574->cache_tags;
      int v741 = (int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1);
      v640[v717] = v741;
      int * v642 = v574->cache_dirty;
      v642[v717] = 0;
      int * v644 = v574->cache_age;
      v644[v717] = 1;
      int * v646 = v574->cache_age;
      int v647 = v646[v717];
      int v648 = v646[v691];
      int v747 = v648 + ((int)((unsigned int)(v648 - v647) >> 31));
      v646[v691] = v747;
      int * v650 = v574->cache_age;
      int v651 = v650[v692];
      int v749 = v651 + ((int)((unsigned int)(v651 - v647) >> 31));
      v650[v692] = v749;
      int * v653 = v574->cache_age;
      v653[v717] = 0;
      v656 = v717;
    }
    int * v657 = v574->cache_vals;
    int v752 = v656 * 2;
    int v658 = v657[v752];
    int v753 = (v656 * 2) + 1;
    int v659 = v657[v753];
    int v754 = (((((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v598 + ((~(((v600 ^ -1) | (-(v600 ^ -1))) >> 31)) & 2)) - (v601 + ((~(((v602 ^ -1) | (-(v602 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v657[v754] = v658;
    int * v661 = v574->cache_vals;
    int v757 = ((((((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v598 + ((~(((v600 ^ -1) | (-(v600 ^ -1))) >> 31)) & 2)) - (v601 + ((~(((v602 ^ -1) | (-(v602 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v661[v757] = v659;
    int * v663 = v574->cache_tags;
    int v760 = ((((int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v598 + ((~(((v600 ^ -1) | (-(v600 ^ -1))) >> 31)) & 2)) - (v601 + ((~(((v602 ^ -1) | (-(v602 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v761 = (int)((unsigned int)((int)((unsigned int)(v578 + 4) >> 2)) >> 1);
    v663[v760] = v761;
    int * v665 = v574->cache_dirty;
    v665[v760] = 0;
    int * v667 = v574->cache_age;
    v667[v760] = 1;
    int * v669 = v574->cache_age;
    int v670 = v669[v760];
    int v671 = v669[v689];
    int v767 = v671 + ((int)((unsigned int)(v671 - v670) >> 31));
    v669[v689] = v767;
    int * v673 = v574->cache_age;
    int v674 = v673[v690];
    int v769 = v674 + ((int)((unsigned int)(v674 - v670) >> 31));
    v673[v690] = v769;
    int * v676 = v574->cache_age;
    v676[v760] = 0;
    v679 = v760;
  }
  int v772 = (v679 * 2) + (((int)((unsigned int)(v578 + 4) >> 2)) & 1);
  int v680 = v586[v772];
  int * v681 = v574->regs;
  v681[10] = v680;
  struct StateT * v683 = slot_18(v574);
  return v683;
}

struct StateT * slot_20(struct StateT * v997) {
  int v998 = v997->timer;
  int v1168 = v998 + 1;
  v997->timer = v1168;
  int * v1000 = v997->regs;
  int v1001 = v1000[11];
  int v1002 = v1000[10];
  int * v1003 = v997->cache_tags;
  int v1173 = (((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1)) & 1) * 2;
  int v1004 = v1003[v1173];
  int v1174 = ((((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1005 = v1003[v1174];
  int v1175 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1)) & 3) * 2);
  int v1006 = v1003[v1175];
  int v1176 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1007 = v1003[v1176];
  int v1008 = v997->timer;
  int v1177 = v1008 + ((100 ^ (((~(((v1006 ^ ((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1))) | (-(v1006 ^ ((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1007 ^ ((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1))) | (-(v1007 ^ ((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1004 ^ ((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1))) | (-(v1004 ^ ((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1005 ^ ((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1))) | (-(v1005 ^ ((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1006 ^ ((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1))) | (-(v1006 ^ ((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1007 ^ ((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1))) | (-(v1007 ^ ((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v997->timer = v1177;
  bool v1178 = !(((~(((v1004 ^ ((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1))) | (-(v1004 ^ ((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1005 ^ ((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1))) | (-(v1005 ^ ((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1102;
  if (v1178) {
    int * v1010 = v997->cache_age;
    int v1180 = ((((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v1005 ^ ((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1))) | (-(v1005 ^ ((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1011 = v1010[v1180];
    int v1012 = v1010[v1173];
    int v1181 = v1012 + ((int)((unsigned int)(v1012 - v1011) >> 31));
    v1010[v1173] = v1181;
    int * v1014 = v997->cache_age;
    int v1015 = v1014[v1174];
    int v1183 = v1015 + ((int)((unsigned int)(v1015 - v1011) >> 31));
    v1014[v1174] = v1183;
    int * v1017 = v997->cache_age;
    v1017[v1180] = 0;
    v1102 = v1180;
  } else {
    int * v1020 = v997->cache_age;
    int v1187 = (((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1)) & 1) * 2;
    int v1021 = v1020[v1187];
    int * v1022 = v997->cache_tags;
    int v1023 = v1022[v1187];
    int v1024 = v1020[v1174];
    int v1025 = v1022[v1174];
    bool v1189 = !(((~(((v1006 ^ ((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1))) | (-(v1006 ^ ((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1007 ^ ((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1))) | (-(v1007 ^ ((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v1079;
    if (v1189) {
      int * v1026 = v997->cache_age;
      int v1191 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1007 ^ ((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1))) | (-(v1007 ^ ((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v1027 = v1026[v1191];
      int v1028 = v1026[v1175];
      int v1192 = v1028 + ((int)((unsigned int)(v1028 - v1027) >> 31));
      v1026[v1175] = v1192;
      int * v1030 = v997->cache_age;
      int v1031 = v1030[v1176];
      int v1194 = v1031 + ((int)((unsigned int)(v1031 - v1027) >> 31));
      v1030[v1176] = v1194;
      int * v1033 = v997->cache_age;
      v1033[v1191] = 0;
      v1079 = v1191;
    } else {
      int * v1036 = v997->cache_age;
      int v1198 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1)) & 3) * 2);
      int v1037 = v1036[v1198];
      int * v1038 = v997->cache_tags;
      int v1039 = v1038[v1198];
      int v1040 = v1036[v1176];
      int v1041 = v1038[v1176];
      int * v1042 = v997->cache_dirty;
      int v1201 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1037 + ((~(((v1039 ^ -1) | (-(v1039 ^ -1))) >> 31)) & 2)) - (v1040 + ((~(((v1041 ^ -1) | (-(v1041 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1043 = v1042[v1201];
      bool v1202 = !(v1043 == 0);
      if (v1202) {
        int * v1044 = v997->cache_tags;
        int v1045 = v1044[v1201];
        int * v1046 = v997->cache_vals;
        int v1205 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1037 + ((~(((v1039 ^ -1) | (-(v1039 ^ -1))) >> 31)) & 2)) - (v1040 + ((~(((v1041 ^ -1) | (-(v1041 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1047 = v1046[v1205];
        int v1206 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1037 + ((~(((v1039 ^ -1) | (-(v1039 ^ -1))) >> 31)) & 2)) - (v1040 + ((~(((v1041 ^ -1) | (-(v1041 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1048 = v1046[v1206];
        int * v1049 = v997->mem;
        int v1208 = v1045 * 2;
        v1049[v1208] = v1047;
        int * v1051 = v997->mem;
        int v1211 = (v1045 * 2) + 1;
        v1051[v1211] = v1048;
        ;
      } else {
        ;
      }
      int * v1056 = v997->mem;
      int v1216 = ((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1)) * 2;
      int v1057 = v1056[v1216];
      int v1217 = (((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1)) * 2) + 1;
      int v1058 = v1056[v1217];
      int * v1059 = v997->cache_vals;
      int v1219 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1037 + ((~(((v1039 ^ -1) | (-(v1039 ^ -1))) >> 31)) & 2)) - (v1040 + ((~(((v1041 ^ -1) | (-(v1041 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1059[v1219] = v1057;
      int * v1061 = v997->cache_vals;
      int v1222 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1037 + ((~(((v1039 ^ -1) | (-(v1039 ^ -1))) >> 31)) & 2)) - (v1040 + ((~(((v1041 ^ -1) | (-(v1041 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1061[v1222] = v1058;
      int * v1063 = v997->cache_tags;
      int v1225 = (int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1);
      v1063[v1201] = v1225;
      int * v1065 = v997->cache_dirty;
      v1065[v1201] = 0;
      int * v1067 = v997->cache_age;
      v1067[v1201] = 1;
      int * v1069 = v997->cache_age;
      int v1070 = v1069[v1201];
      int v1071 = v1069[v1175];
      int v1231 = v1071 + ((int)((unsigned int)(v1071 - v1070) >> 31));
      v1069[v1175] = v1231;
      int * v1073 = v997->cache_age;
      int v1074 = v1073[v1176];
      int v1233 = v1074 + ((int)((unsigned int)(v1074 - v1070) >> 31));
      v1073[v1176] = v1233;
      int * v1076 = v997->cache_age;
      v1076[v1201] = 0;
      v1079 = v1201;
    }
    int * v1080 = v997->cache_vals;
    int v1236 = v1079 * 2;
    int v1081 = v1080[v1236];
    int v1237 = (v1079 * 2) + 1;
    int v1082 = v1080[v1237];
    int v1238 = (((((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1021 + ((~(((v1023 ^ -1) | (-(v1023 ^ -1))) >> 31)) & 2)) - (v1024 + ((~(((v1025 ^ -1) | (-(v1025 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1080[v1238] = v1081;
    int * v1084 = v997->cache_vals;
    int v1241 = ((((((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1021 + ((~(((v1023 ^ -1) | (-(v1023 ^ -1))) >> 31)) & 2)) - (v1024 + ((~(((v1025 ^ -1) | (-(v1025 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1084[v1241] = v1082;
    int * v1086 = v997->cache_tags;
    int v1244 = ((((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v1021 + ((~(((v1023 ^ -1) | (-(v1023 ^ -1))) >> 31)) & 2)) - (v1024 + ((~(((v1025 ^ -1) | (-(v1025 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1245 = (int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1);
    v1086[v1244] = v1245;
    int * v1088 = v997->cache_dirty;
    v1088[v1244] = 0;
    int * v1090 = v997->cache_age;
    v1090[v1244] = 1;
    int * v1092 = v997->cache_age;
    int v1093 = v1092[v1244];
    int v1094 = v1092[v1173];
    int v1251 = v1094 + ((int)((unsigned int)(v1094 - v1093) >> 31));
    v1092[v1173] = v1251;
    int * v1096 = v997->cache_age;
    int v1097 = v1096[v1174];
    int v1253 = v1097 + ((int)((unsigned int)(v1097 - v1093) >> 31));
    v1096[v1174] = v1253;
    int * v1099 = v997->cache_age;
    v1099[v1244] = 0;
    v1102 = v1244;
  }
  int * v1103 = v997->cache_vals;
  int v1256 = (v1102 * 2) + (((int)((unsigned int)(v1001 + 68) >> 2)) & 1);
  v1103[v1256] = v1002;
  int * v1105 = v997->cache_tags;
  int v1106 = v1105[v1175];
  int v1107 = v1105[v1176];
  bool v1259 = !(((~(((v1106 ^ ((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1))) | (-(v1106 ^ ((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v1107 ^ ((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1))) | (-(v1107 ^ ((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v1161;
  if (v1259) {
    int * v1108 = v997->cache_age;
    int v1261 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1107 ^ ((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1))) | (-(v1107 ^ ((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v1109 = v1108[v1261];
    int v1110 = v1108[v1175];
    int v1262 = v1110 + ((int)((unsigned int)(v1110 - v1109) >> 31));
    v1108[v1175] = v1262;
    int * v1112 = v997->cache_age;
    int v1113 = v1112[v1176];
    int v1264 = v1113 + ((int)((unsigned int)(v1113 - v1109) >> 31));
    v1112[v1176] = v1264;
    int * v1115 = v997->cache_age;
    v1115[v1261] = 0;
    v1161 = v1261;
  } else {
    int * v1118 = v997->cache_age;
    int v1268 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1)) & 3) * 2);
    int v1119 = v1118[v1268];
    int * v1120 = v997->cache_tags;
    int v1121 = v1120[v1268];
    int v1122 = v1118[v1176];
    int v1123 = v1120[v1176];
    int * v1124 = v997->cache_dirty;
    int v1271 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1119 + ((~(((v1121 ^ -1) | (-(v1121 ^ -1))) >> 31)) & 2)) - (v1122 + ((~(((v1123 ^ -1) | (-(v1123 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1125 = v1124[v1271];
    bool v1272 = !(v1125 == 0);
    if (v1272) {
      int * v1126 = v997->cache_tags;
      int v1127 = v1126[v1271];
      int * v1128 = v997->cache_vals;
      int v1275 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1119 + ((~(((v1121 ^ -1) | (-(v1121 ^ -1))) >> 31)) & 2)) - (v1122 + ((~(((v1123 ^ -1) | (-(v1123 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1129 = v1128[v1275];
      int v1276 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1119 + ((~(((v1121 ^ -1) | (-(v1121 ^ -1))) >> 31)) & 2)) - (v1122 + ((~(((v1123 ^ -1) | (-(v1123 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1130 = v1128[v1276];
      int * v1131 = v997->mem;
      int v1278 = v1127 * 2;
      v1131[v1278] = v1129;
      int * v1133 = v997->mem;
      int v1281 = (v1127 * 2) + 1;
      v1133[v1281] = v1130;
      ;
    } else {
      ;
    }
    int * v1138 = v997->mem;
    int v1286 = ((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1)) * 2;
    int v1139 = v1138[v1286];
    int v1287 = (((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1)) * 2) + 1;
    int v1140 = v1138[v1287];
    int * v1141 = v997->cache_vals;
    int v1289 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1119 + ((~(((v1121 ^ -1) | (-(v1121 ^ -1))) >> 31)) & 2)) - (v1122 + ((~(((v1123 ^ -1) | (-(v1123 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1141[v1289] = v1139;
    int * v1143 = v997->cache_vals;
    int v1292 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v1119 + ((~(((v1121 ^ -1) | (-(v1121 ^ -1))) >> 31)) & 2)) - (v1122 + ((~(((v1123 ^ -1) | (-(v1123 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1143[v1292] = v1140;
    int * v1145 = v997->cache_tags;
    int v1295 = (int)((unsigned int)((int)((unsigned int)(v1001 + 68) >> 2)) >> 1);
    v1145[v1271] = v1295;
    int * v1147 = v997->cache_dirty;
    v1147[v1271] = 0;
    int * v1149 = v997->cache_age;
    v1149[v1271] = 1;
    int * v1151 = v997->cache_age;
    int v1152 = v1151[v1271];
    int v1153 = v1151[v1175];
    int v1301 = v1153 + ((int)((unsigned int)(v1153 - v1152) >> 31));
    v1151[v1175] = v1301;
    int * v1155 = v997->cache_age;
    int v1156 = v1155[v1176];
    int v1303 = v1156 + ((int)((unsigned int)(v1156 - v1152) >> 31));
    v1155[v1176] = v1303;
    int * v1158 = v997->cache_age;
    v1158[v1271] = 0;
    v1161 = v1271;
  }
  int * v1162 = v997->cache_vals;
  int v1306 = (v1161 * 2) + (((int)((unsigned int)(v1001 + 68) >> 2)) & 1);
  v1162[v1306] = v1002;
  int * v1164 = v997->cache_dirty;
  v1164[v1161] = 1;
  struct StateT * v1166 = slot_21(v997);
  return v1166;
}

struct StateT * slot_2(struct StateT * v218) {
  int v219 = v218->timer;
  int v223 = v219 + 1;
  v218->timer = v223;
  struct StateT * v221 = slot_3(v218);
  return v221;
}

struct StateT * slot_7(struct StateT * v267) {
  int v268 = v267->timer;
  int v274 = v268 + 1;
  v267->timer = v274;
  int * v270 = v267->regs;
  v270[12] = 0;
  struct StateT * v272 = slot_8(v267);
  return v272;
}

struct StateT * slot_21(struct StateT * v1312) {
  int v1313 = v1312->timer;
  int v1316 = v1313 + 1;
  v1312->timer = v1316;
  return v1312;
}

struct StateT * slot_3(struct StateT * v226) {
  int * v227 = v226->regs;
  int v228 = v227[10];
  int v229 = v227[12];
  bool v241 = (v228 ^ -2147483648) >= (v229 ^ -2147483648);
  struct StateT * v236;
  if (v241) {
    int v230 = v226->timer;
    int v242 = v230 + 15;
    v226->timer = v242;
    struct StateT * v232 = slot_21(v226);
    v236 = v232;
  } else {
    struct StateT * v234 = slot_5(v226);
    v236 = v234;
  }
  return v236;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_10(struct StateT * v310) {
  int v311 = v310->timer;
  int v421 = v311 + 1;
  v310->timer = v421;
  int * v313 = v310->regs;
  int v314 = v313[10];
  int * v315 = v310->cache_tags;
  int v425 = (((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 1) * 2;
  int v316 = v315[v425];
  int v426 = ((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 1) * 2) + 1;
  int v317 = v315[v426];
  int v427 = 4 + ((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 3) * 2);
  int v318 = v315[v427];
  int v428 = (4 + ((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v319 = v315[v428];
  int v320 = v310->timer;
  int v429 = v320 + ((100 ^ (((~(((v318 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))) | (-(v318 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))))) >> 31)) | (~(((v319 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))) | (-(v319 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v316 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))) | (-(v316 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))))) >> 31)) | (~(((v317 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))) | (-(v317 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v318 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))) | (-(v318 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))))) >> 31)) | (~(((v319 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))) | (-(v319 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))))) >> 31))) & 104)))));
  v310->timer = v429;
  int * v322 = v310->cache_vals;
  bool v430 = !(((~(((v316 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))) | (-(v316 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))))) >> 31)) | (~(((v317 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))) | (-(v317 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))))) >> 31))) == 0);
  int v415;
  if (v430) {
    int * v323 = v310->cache_age;
    int v432 = ((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 1) * 2) + ((~(((v317 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))) | (-(v317 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))))) >> 31)) & 1);
    int v324 = v323[v432];
    int v325 = v323[v425];
    int v433 = v325 + ((int)((unsigned int)(v325 - v324) >> 31));
    v323[v425] = v433;
    int * v327 = v310->cache_age;
    int v328 = v327[v426];
    int v435 = v328 + ((int)((unsigned int)(v328 - v324) >> 31));
    v327[v426] = v435;
    int * v330 = v310->cache_age;
    v330[v432] = 0;
    v415 = v432;
  } else {
    int * v333 = v310->cache_age;
    int v439 = (((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 1) * 2;
    int v334 = v333[v439];
    int * v335 = v310->cache_tags;
    int v336 = v335[v439];
    int v337 = v333[v426];
    int v338 = v335[v426];
    bool v441 = !(((~(((v318 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))) | (-(v318 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))))) >> 31)) | (~(((v319 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))) | (-(v319 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))))) >> 31))) == 0);
    int v392;
    if (v441) {
      int * v339 = v310->cache_age;
      int v443 = (4 + ((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 3) * 2)) + ((~(((v319 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))) | (-(v319 ^ ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1))))) >> 31)) & 1);
      int v340 = v339[v443];
      int v341 = v339[v427];
      int v444 = v341 + ((int)((unsigned int)(v341 - v340) >> 31));
      v339[v427] = v444;
      int * v343 = v310->cache_age;
      int v344 = v343[v428];
      int v446 = v344 + ((int)((unsigned int)(v344 - v340) >> 31));
      v343[v428] = v446;
      int * v346 = v310->cache_age;
      v346[v443] = 0;
      v392 = v443;
    } else {
      int * v349 = v310->cache_age;
      int v450 = 4 + ((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 3) * 2);
      int v350 = v349[v450];
      int * v351 = v310->cache_tags;
      int v352 = v351[v450];
      int v353 = v349[v428];
      int v354 = v351[v428];
      int * v355 = v310->cache_dirty;
      int v453 = (4 + ((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 3) * 2)) + ((((v350 + ((~(((v352 ^ -1) | (-(v352 ^ -1))) >> 31)) & 2)) - (v353 + ((~(((v354 ^ -1) | (-(v354 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v356 = v355[v453];
      bool v454 = !(v356 == 0);
      if (v454) {
        int * v357 = v310->cache_tags;
        int v358 = v357[v453];
        int * v359 = v310->cache_vals;
        int v457 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 3) * 2)) + ((((v350 + ((~(((v352 ^ -1) | (-(v352 ^ -1))) >> 31)) & 2)) - (v353 + ((~(((v354 ^ -1) | (-(v354 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v360 = v359[v457];
        int v458 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 3) * 2)) + ((((v350 + ((~(((v352 ^ -1) | (-(v352 ^ -1))) >> 31)) & 2)) - (v353 + ((~(((v354 ^ -1) | (-(v354 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v361 = v359[v458];
        int * v362 = v310->mem;
        int v460 = v358 * 2;
        v362[v460] = v360;
        int * v364 = v310->mem;
        int v463 = (v358 * 2) + 1;
        v364[v463] = v361;
        ;
      } else {
        ;
      }
      int * v369 = v310->mem;
      int v468 = ((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) * 2;
      int v370 = v369[v468];
      int v469 = (((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) * 2) + 1;
      int v371 = v369[v469];
      int * v372 = v310->cache_vals;
      int v471 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 3) * 2)) + ((((v350 + ((~(((v352 ^ -1) | (-(v352 ^ -1))) >> 31)) & 2)) - (v353 + ((~(((v354 ^ -1) | (-(v354 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v372[v471] = v370;
      int * v374 = v310->cache_vals;
      int v474 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 3) * 2)) + ((((v350 + ((~(((v352 ^ -1) | (-(v352 ^ -1))) >> 31)) & 2)) - (v353 + ((~(((v354 ^ -1) | (-(v354 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v374[v474] = v371;
      int * v376 = v310->cache_tags;
      int v477 = (int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1);
      v376[v453] = v477;
      int * v378 = v310->cache_dirty;
      v378[v453] = 0;
      int * v380 = v310->cache_age;
      v380[v453] = 1;
      int * v382 = v310->cache_age;
      int v383 = v382[v453];
      int v384 = v382[v427];
      int v483 = v384 + ((int)((unsigned int)(v384 - v383) >> 31));
      v382[v427] = v483;
      int * v386 = v310->cache_age;
      int v387 = v386[v428];
      int v485 = v387 + ((int)((unsigned int)(v387 - v383) >> 31));
      v386[v428] = v485;
      int * v389 = v310->cache_age;
      v389[v453] = 0;
      v392 = v453;
    }
    int * v393 = v310->cache_vals;
    int v488 = v392 * 2;
    int v394 = v393[v488];
    int v489 = (v392 * 2) + 1;
    int v395 = v393[v489];
    int v490 = (((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 1) * 2) + ((((v334 + ((~(((v336 ^ -1) | (-(v336 ^ -1))) >> 31)) & 2)) - (v337 + ((~(((v338 ^ -1) | (-(v338 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v393[v490] = v394;
    int * v397 = v310->cache_vals;
    int v493 = ((((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 1) * 2) + ((((v334 + ((~(((v336 ^ -1) | (-(v336 ^ -1))) >> 31)) & 2)) - (v337 + ((~(((v338 ^ -1) | (-(v338 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v397[v493] = v395;
    int * v399 = v310->cache_tags;
    int v496 = ((((int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1)) & 1) * 2) + ((((v334 + ((~(((v336 ^ -1) | (-(v336 ^ -1))) >> 31)) & 2)) - (v337 + ((~(((v338 ^ -1) | (-(v338 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v497 = (int)((unsigned int)((int)((unsigned int)v314 >> 2)) >> 1);
    v399[v496] = v497;
    int * v401 = v310->cache_dirty;
    v401[v496] = 0;
    int * v403 = v310->cache_age;
    v403[v496] = 1;
    int * v405 = v310->cache_age;
    int v406 = v405[v496];
    int v407 = v405[v425];
    int v503 = v407 + ((int)((unsigned int)(v407 - v406) >> 31));
    v405[v425] = v503;
    int * v409 = v310->cache_age;
    int v410 = v409[v426];
    int v505 = v410 + ((int)((unsigned int)(v410 - v406) >> 31));
    v409[v426] = v505;
    int * v412 = v310->cache_age;
    v412[v496] = 0;
    v415 = v496;
  }
  int v508 = (v415 * 2) + (((int)((unsigned int)v314 >> 2)) & 1);
  int v416 = v322[v508];
  int * v417 = v310->regs;
  v417[10] = v416;
  struct StateT * v419 = slot_11(v310);
  return v419;
}

struct StateT * slot_1(struct StateT * v15) {
  int v16 = v15->timer;
  int v126 = v16 + 1;
  v15->timer = v126;
  int * v18 = v15->regs;
  int v19 = v18[12];
  int * v20 = v15->cache_tags;
  int v130 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2;
  int v21 = v20[v130];
  int v131 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + 1;
  int v22 = v20[v131];
  int v132 = 4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2);
  int v23 = v20[v132];
  int v133 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v24 = v20[v133];
  int v25 = v15->timer;
  int v134 = v25 + ((100 ^ (((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) & 104)))));
  v15->timer = v134;
  int * v27 = v15->cache_vals;
  bool v135 = !(((~(((v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v21 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) == 0);
  int v120;
  if (v135) {
    int * v28 = v15->cache_age;
    int v137 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((~(((v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v22 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) & 1);
    int v29 = v28[v137];
    int v30 = v28[v130];
    int v138 = v30 + ((int)((unsigned int)(v30 - v29) >> 31));
    v28[v130] = v138;
    int * v32 = v15->cache_age;
    int v33 = v32[v131];
    int v140 = v33 + ((int)((unsigned int)(v33 - v29) >> 31));
    v32[v131] = v140;
    int * v35 = v15->cache_age;
    v35[v137] = 0;
    v120 = v137;
  } else {
    int * v38 = v15->cache_age;
    int v144 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2;
    int v39 = v38[v144];
    int * v40 = v15->cache_tags;
    int v41 = v40[v144];
    int v42 = v38[v131];
    int v43 = v40[v131];
    bool v146 = !(((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31))) == 0);
    int v97;
    if (v146) {
      int * v44 = v15->cache_age;
      int v148 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1))))) >> 31)) & 1);
      int v45 = v44[v148];
      int v46 = v44[v132];
      int v149 = v46 + ((int)((unsigned int)(v46 - v45) >> 31));
      v44[v132] = v149;
      int * v48 = v15->cache_age;
      int v49 = v48[v133];
      int v151 = v49 + ((int)((unsigned int)(v49 - v45) >> 31));
      v48[v133] = v151;
      int * v51 = v15->cache_age;
      v51[v148] = 0;
      v97 = v148;
    } else {
      int * v54 = v15->cache_age;
      int v155 = 4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2);
      int v55 = v54[v155];
      int * v56 = v15->cache_tags;
      int v57 = v56[v155];
      int v58 = v54[v133];
      int v59 = v56[v133];
      int * v60 = v15->cache_dirty;
      int v158 = (4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v61 = v60[v158];
      bool v159 = !(v61 == 0);
      if (v159) {
        int * v62 = v15->cache_tags;
        int v63 = v62[v158];
        int * v64 = v15->cache_vals;
        int v162 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v65 = v64[v162];
        int v163 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v66 = v64[v163];
        int * v67 = v15->mem;
        int v165 = v63 * 2;
        v67[v165] = v65;
        int * v69 = v15->mem;
        int v168 = (v63 * 2) + 1;
        v69[v168] = v66;
        ;
      } else {
        ;
      }
      int * v74 = v15->mem;
      int v173 = ((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) * 2;
      int v75 = v74[v173];
      int v174 = (((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) * 2) + 1;
      int v76 = v74[v174];
      int * v77 = v15->cache_vals;
      int v176 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v77[v176] = v75;
      int * v79 = v15->cache_vals;
      int v179 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 3) * 2)) + ((((v55 + ((~(((v57 ^ -1) | (-(v57 ^ -1))) >> 31)) & 2)) - (v58 + ((~(((v59 ^ -1) | (-(v59 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v79[v179] = v76;
      int * v81 = v15->cache_tags;
      int v182 = (int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1);
      v81[v158] = v182;
      int * v83 = v15->cache_dirty;
      v83[v158] = 0;
      int * v85 = v15->cache_age;
      v85[v158] = 1;
      int * v87 = v15->cache_age;
      int v88 = v87[v158];
      int v89 = v87[v132];
      int v188 = v89 + ((int)((unsigned int)(v89 - v88) >> 31));
      v87[v132] = v188;
      int * v91 = v15->cache_age;
      int v92 = v91[v133];
      int v190 = v92 + ((int)((unsigned int)(v92 - v88) >> 31));
      v91[v133] = v190;
      int * v94 = v15->cache_age;
      v94[v158] = 0;
      v97 = v158;
    }
    int * v98 = v15->cache_vals;
    int v193 = v97 * 2;
    int v99 = v98[v193];
    int v194 = (v97 * 2) + 1;
    int v100 = v98[v194];
    int v195 = (((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v39 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2)) - (v42 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v98[v195] = v99;
    int * v102 = v15->cache_vals;
    int v198 = ((((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v39 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2)) - (v42 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v102[v198] = v100;
    int * v104 = v15->cache_tags;
    int v201 = ((((int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1)) & 1) * 2) + ((((v39 + ((~(((v41 ^ -1) | (-(v41 ^ -1))) >> 31)) & 2)) - (v42 + ((~(((v43 ^ -1) | (-(v43 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v202 = (int)((unsigned int)((int)((unsigned int)v19 >> 2)) >> 1);
    v104[v201] = v202;
    int * v106 = v15->cache_dirty;
    v106[v201] = 0;
    int * v108 = v15->cache_age;
    v108[v201] = 1;
    int * v110 = v15->cache_age;
    int v111 = v110[v201];
    int v112 = v110[v130];
    int v208 = v112 + ((int)((unsigned int)(v112 - v111) >> 31));
    v110[v130] = v208;
    int * v114 = v15->cache_age;
    int v115 = v114[v131];
    int v210 = v115 + ((int)((unsigned int)(v115 - v111) >> 31));
    v114[v131] = v210;
    int * v117 = v15->cache_age;
    v117[v201] = 0;
    v120 = v201;
  }
  int v213 = (v120 * 2) + (((int)((unsigned int)v19 >> 2)) & 1);
  int v121 = v27[v213];
  int * v122 = v15->regs;
  v122[12] = v121;
  struct StateT * v124 = slot_2(v15);
  return v124;
}

struct StateT * slot_8(struct StateT * v280) {
  int v281 = v280->timer;
  int v288 = v281 + 1;
  v280->timer = v288;
  int * v283 = v280->regs;
  int v284 = v283[12];
  int v291 = v284 + 72;
  v283[12] = v291;
  struct StateT * v286 = slot_9(v280);
  return v286;
}

struct StateT * slot_19(struct StateT * v981) {
  int v982 = v981->timer;
  int v990 = v982 + 1;
  v981->timer = v990;
  int * v984 = v981->regs;
  int v985 = v984[12];
  int v986 = v984[10];
  int v994 = v985 & v986;
  v984[10] = v994;
  struct StateT * v988 = slot_20(v981);
  return v988;
}

struct StateT * slot_18(struct StateT * v777) {
  int v778 = v777->timer;
  int v888 = v778 + 1;
  v777->timer = v888;
  int * v780 = v777->regs;
  int v781 = v780[11];
  int * v782 = v777->cache_tags;
  int v892 = (((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1)) & 1) * 2;
  int v783 = v782[v892];
  int v893 = ((((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1)) & 1) * 2) + 1;
  int v784 = v782[v893];
  int v894 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1)) & 3) * 2);
  int v785 = v782[v894];
  int v895 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v786 = v782[v895];
  int v787 = v777->timer;
  int v896 = v787 + ((100 ^ (((~(((v785 ^ ((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1))) | (-(v785 ^ ((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v786 ^ ((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1))) | (-(v786 ^ ((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v783 ^ ((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1))) | (-(v783 ^ ((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v784 ^ ((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1))) | (-(v784 ^ ((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v785 ^ ((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1))) | (-(v785 ^ ((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v786 ^ ((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1))) | (-(v786 ^ ((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1))))) >> 31))) & 104)))));
  v777->timer = v896;
  int * v789 = v777->cache_vals;
  bool v897 = !(((~(((v783 ^ ((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1))) | (-(v783 ^ ((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v784 ^ ((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1))) | (-(v784 ^ ((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1))))) >> 31))) == 0);
  int v882;
  if (v897) {
    int * v790 = v777->cache_age;
    int v899 = ((((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1)) & 1) * 2) + ((~(((v784 ^ ((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1))) | (-(v784 ^ ((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1))))) >> 31)) & 1);
    int v791 = v790[v899];
    int v792 = v790[v892];
    int v900 = v792 + ((int)((unsigned int)(v792 - v791) >> 31));
    v790[v892] = v900;
    int * v794 = v777->cache_age;
    int v795 = v794[v893];
    int v902 = v795 + ((int)((unsigned int)(v795 - v791) >> 31));
    v794[v893] = v902;
    int * v797 = v777->cache_age;
    v797[v899] = 0;
    v882 = v899;
  } else {
    int * v800 = v777->cache_age;
    int v906 = (((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1)) & 1) * 2;
    int v801 = v800[v906];
    int * v802 = v777->cache_tags;
    int v803 = v802[v906];
    int v804 = v800[v893];
    int v805 = v802[v893];
    bool v908 = !(((~(((v785 ^ ((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1))) | (-(v785 ^ ((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1))))) >> 31)) | (~(((v786 ^ ((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1))) | (-(v786 ^ ((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1))))) >> 31))) == 0);
    int v859;
    if (v908) {
      int * v806 = v777->cache_age;
      int v910 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1)) & 3) * 2)) + ((~(((v786 ^ ((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1))) | (-(v786 ^ ((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1))))) >> 31)) & 1);
      int v807 = v806[v910];
      int v808 = v806[v894];
      int v911 = v808 + ((int)((unsigned int)(v808 - v807) >> 31));
      v806[v894] = v911;
      int * v810 = v777->cache_age;
      int v811 = v810[v895];
      int v913 = v811 + ((int)((unsigned int)(v811 - v807) >> 31));
      v810[v895] = v913;
      int * v813 = v777->cache_age;
      v813[v910] = 0;
      v859 = v910;
    } else {
      int * v816 = v777->cache_age;
      int v917 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1)) & 3) * 2);
      int v817 = v816[v917];
      int * v818 = v777->cache_tags;
      int v819 = v818[v917];
      int v820 = v816[v895];
      int v821 = v818[v895];
      int * v822 = v777->cache_dirty;
      int v920 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v817 + ((~(((v819 ^ -1) | (-(v819 ^ -1))) >> 31)) & 2)) - (v820 + ((~(((v821 ^ -1) | (-(v821 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v823 = v822[v920];
      bool v921 = !(v823 == 0);
      if (v921) {
        int * v824 = v777->cache_tags;
        int v825 = v824[v920];
        int * v826 = v777->cache_vals;
        int v924 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v817 + ((~(((v819 ^ -1) | (-(v819 ^ -1))) >> 31)) & 2)) - (v820 + ((~(((v821 ^ -1) | (-(v821 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v827 = v826[v924];
        int v925 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v817 + ((~(((v819 ^ -1) | (-(v819 ^ -1))) >> 31)) & 2)) - (v820 + ((~(((v821 ^ -1) | (-(v821 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v828 = v826[v925];
        int * v829 = v777->mem;
        int v927 = v825 * 2;
        v829[v927] = v827;
        int * v831 = v777->mem;
        int v930 = (v825 * 2) + 1;
        v831[v930] = v828;
        ;
      } else {
        ;
      }
      int * v836 = v777->mem;
      int v935 = ((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1)) * 2;
      int v837 = v836[v935];
      int v936 = (((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1)) * 2) + 1;
      int v838 = v836[v936];
      int * v839 = v777->cache_vals;
      int v938 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v817 + ((~(((v819 ^ -1) | (-(v819 ^ -1))) >> 31)) & 2)) - (v820 + ((~(((v821 ^ -1) | (-(v821 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v839[v938] = v837;
      int * v841 = v777->cache_vals;
      int v941 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1)) & 3) * 2)) + ((((v817 + ((~(((v819 ^ -1) | (-(v819 ^ -1))) >> 31)) & 2)) - (v820 + ((~(((v821 ^ -1) | (-(v821 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v841[v941] = v838;
      int * v843 = v777->cache_tags;
      int v944 = (int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1);
      v843[v920] = v944;
      int * v845 = v777->cache_dirty;
      v845[v920] = 0;
      int * v847 = v777->cache_age;
      v847[v920] = 1;
      int * v849 = v777->cache_age;
      int v850 = v849[v920];
      int v851 = v849[v894];
      int v950 = v851 + ((int)((unsigned int)(v851 - v850) >> 31));
      v849[v894] = v950;
      int * v853 = v777->cache_age;
      int v854 = v853[v895];
      int v952 = v854 + ((int)((unsigned int)(v854 - v850) >> 31));
      v853[v895] = v952;
      int * v856 = v777->cache_age;
      v856[v920] = 0;
      v859 = v920;
    }
    int * v860 = v777->cache_vals;
    int v955 = v859 * 2;
    int v861 = v860[v955];
    int v956 = (v859 * 2) + 1;
    int v862 = v860[v956];
    int v957 = (((((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v801 + ((~(((v803 ^ -1) | (-(v803 ^ -1))) >> 31)) & 2)) - (v804 + ((~(((v805 ^ -1) | (-(v805 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v860[v957] = v861;
    int * v864 = v777->cache_vals;
    int v960 = ((((((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v801 + ((~(((v803 ^ -1) | (-(v803 ^ -1))) >> 31)) & 2)) - (v804 + ((~(((v805 ^ -1) | (-(v805 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v864[v960] = v862;
    int * v866 = v777->cache_tags;
    int v963 = ((((int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1)) & 1) * 2) + ((((v801 + ((~(((v803 ^ -1) | (-(v803 ^ -1))) >> 31)) & 2)) - (v804 + ((~(((v805 ^ -1) | (-(v805 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v964 = (int)((unsigned int)((int)((unsigned int)(v781 + 68) >> 2)) >> 1);
    v866[v963] = v964;
    int * v868 = v777->cache_dirty;
    v868[v963] = 0;
    int * v870 = v777->cache_age;
    v870[v963] = 1;
    int * v872 = v777->cache_age;
    int v873 = v872[v963];
    int v874 = v872[v892];
    int v970 = v874 + ((int)((unsigned int)(v874 - v873) >> 31));
    v872[v892] = v970;
    int * v876 = v777->cache_age;
    int v877 = v876[v893];
    int v972 = v877 + ((int)((unsigned int)(v877 - v873) >> 31));
    v876[v893] = v972;
    int * v879 = v777->cache_age;
    v879[v963] = 0;
    v882 = v963;
  }
  int v975 = (v882 * 2) + (((int)((unsigned int)(v781 + 68) >> 2)) & 1);
  int v883 = v789[v975];
  int * v884 = v777->regs;
  v884[12] = v883;
  struct StateT * v886 = slot_19(v777);
  return v886;
}

struct StateT * slot_9(struct StateT * v294) {
  int v295 = v294->timer;
  int v303 = v295 + 1;
  v294->timer = v303;
  int * v297 = v294->regs;
  int v298 = v297[12];
  int v299 = v297[10];
  int v307 = v298 + v299;
  v297[10] = v307;
  struct StateT * v301 = slot_10(v294);
  return v301;
}

struct StateT * slot_11(struct StateT * v513) {
  int v514 = v513->timer;
  int v518 = v514 + 1;
  v513->timer = v518;
  struct StateT * v516 = slot_12(v513);
  return v516;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v9 = v3 + 1;
  v2->timer = v9;
  int * v5 = v2->regs;
  v5[12] = 0;
  struct StateT * v7 = slot_1(v2);
  return v7;
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