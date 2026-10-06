// verify: clean (Eva should report untainted_timer: Valid) [unroll 65]
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

struct StateT2 {
  struct StateT * a;
  struct StateT * b;
};

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

void squared_assert(bool);
void squared_assume(bool);

struct StateT2 * slot_12(struct StateT2 * v1584);
struct StateT2 * slot_6(struct StateT2 * v588);
struct StateT2 * slot_16(struct StateT2 * v1744);
struct StateT2 * slot_5(struct StateT2 * v549);
struct StateT2 * slot_2(struct StateT2 * v428);
struct StateT2 * slot_7(struct StateT2 * v1006);
struct StateT2 * slot_21(struct StateT2 * v2322);
struct StateT2 * slot_3(struct StateT2 * v470);
struct StateT2 * slot_10(struct StateT2 * v1127);
struct StateT2 * slot_1(struct StateT2 * v38);
struct StateT2 * slot_19(struct StateT2 * v2244);
struct StateT2 * slot_13(struct StateT2 * v1626);
struct StateT2 * slot_0(struct StateT2 * v2);
struct StateT2 * slot_14(struct StateT2 * v1666);
struct StateT2 * slot_17(struct StateT2 * v2162);
struct StateT2 * slot_20(struct StateT2 * v2283);
struct StateT2 * snippet(struct StateT2 * v0);
struct StateT2 * slot_8(struct StateT2 * v1048);
struct StateT2 * slot_4(struct StateT2 * v510);
struct StateT2 * slot_15(struct StateT2 * v1705);
struct StateT2 * slot_18(struct StateT2 * v2204);
struct StateT2 * slot_9(struct StateT2 * v1088);
struct StateT2 * slot_22(struct StateT2 * v2740);
struct StateT2 * slot_11(struct StateT2 * v1166);
struct StateT2 * slot_12(struct StateT2 * v1584) {
  struct StateT * v1585 = v1584->a;
  int v1586 = v1585->timer;
  struct StateT * v1587 = v1584->b;
  int v1588 = v1587->timer;
  bool v1611 = v1586 == v1588;
  squared_assert(v1611);
  squared_assume(v1611);
  struct StateT * v1591 = v1584->a;
  int v1592 = v1591->timer;
  int v1613 = v1592 + 1;
  v1591->timer = v1613;
  struct StateT * v1594 = v1584->b;
  int v1595 = v1594->timer;
  int v1615 = v1595 + 1;
  v1594->timer = v1615;
  struct StateT * v1597 = v1584->a;
  int * v1598 = v1597->regs;
  int v1599 = v1598[5];
  int v1600 = v1598[7];
  int v1620 = v1599 ^ v1600;
  v1598[5] = v1620;
  struct StateT * v1602 = v1584->b;
  int * v1603 = v1602->regs;
  int v1604 = v1603[5];
  int v1605 = v1603[7];
  int v1623 = v1604 ^ v1605;
  v1603[5] = v1623;
  struct StateT2 * v1607 = slot_13(v1584);
  return v1607;
}

struct StateT2 * slot_6(struct StateT2 * v588) {
  struct StateT * v589 = v588->a;
  int v590 = v589->timer;
  struct StateT * v591 = v588->b;
  int v592 = v591->timer;
  bool v819 = v590 == v592;
  squared_assert(v819);
  squared_assume(v819);
  struct StateT * v595 = v588->a;
  int v596 = v595->timer;
  int v821 = v596 + 1;
  v595->timer = v821;
  struct StateT * v598 = v588->b;
  int v599 = v598->timer;
  int v823 = v599 + 1;
  v598->timer = v823;
  struct StateT * v601 = v588->a;
  int * v602 = v601->regs;
  int v603 = v602[6];
  int * v604 = v601->cache_tags;
  int v828 = (((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1)) & 1) * 2;
  int v605 = v604[v828];
  int v829 = ((((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1)) & 1) * 2) + 1;
  int v606 = v604[v829];
  int v830 = 4 + ((((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1)) & 3) * 2);
  int v607 = v604[v830];
  int v831 = (4 + ((((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v608 = v604[v831];
  int v609 = v601->timer;
  int v832 = v609 + ((100 ^ (((~(((v607 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))) | (-(v607 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))))) >> 31)) | (~(((v608 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))) | (-(v608 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v605 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))) | (-(v605 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))))) >> 31)) | (~(((v606 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))) | (-(v606 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v607 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))) | (-(v607 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))))) >> 31)) | (~(((v608 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))) | (-(v608 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))))) >> 31))) & 104)))));
  v601->timer = v832;
  int * v611 = v601->cache_vals;
  bool v833 = !(((~(((v605 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))) | (-(v605 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))))) >> 31)) | (~(((v606 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))) | (-(v606 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))))) >> 31))) == 0);
  int v704;
  if (v833) {
    int * v612 = v601->cache_age;
    int v835 = ((((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1)) & 1) * 2) + ((~(((v606 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))) | (-(v606 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))))) >> 31)) & 1);
    int v613 = v612[v835];
    int v614 = v612[v828];
    int v836 = v614 + ((int)((unsigned int)(v614 - v613) >> 31));
    v612[v828] = v836;
    int * v616 = v601->cache_age;
    int v617 = v616[v829];
    int v838 = v617 + ((int)((unsigned int)(v617 - v613) >> 31));
    v616[v829] = v838;
    int * v619 = v601->cache_age;
    v619[v835] = 0;
    v704 = v835;
  } else {
    int * v622 = v601->cache_age;
    int v842 = (((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1)) & 1) * 2;
    int v623 = v622[v842];
    int * v624 = v601->cache_tags;
    int v625 = v624[v842];
    int v626 = v622[v829];
    int v627 = v624[v829];
    bool v844 = !(((~(((v607 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))) | (-(v607 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))))) >> 31)) | (~(((v608 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))) | (-(v608 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))))) >> 31))) == 0);
    int v681;
    if (v844) {
      int * v628 = v601->cache_age;
      int v846 = (4 + ((((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1)) & 3) * 2)) + ((~(((v608 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))) | (-(v608 ^ ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1))))) >> 31)) & 1);
      int v629 = v628[v846];
      int v630 = v628[v830];
      int v847 = v630 + ((int)((unsigned int)(v630 - v629) >> 31));
      v628[v830] = v847;
      int * v632 = v601->cache_age;
      int v633 = v632[v831];
      int v849 = v633 + ((int)((unsigned int)(v633 - v629) >> 31));
      v632[v831] = v849;
      int * v635 = v601->cache_age;
      v635[v846] = 0;
      v681 = v846;
    } else {
      int * v638 = v601->cache_age;
      int v853 = 4 + ((((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1)) & 3) * 2);
      int v639 = v638[v853];
      int * v640 = v601->cache_tags;
      int v641 = v640[v853];
      int v642 = v638[v831];
      int v643 = v640[v831];
      int * v644 = v601->cache_dirty;
      int v856 = (4 + ((((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1)) & 3) * 2)) + ((((v639 + ((~(((v641 ^ -1) | (-(v641 ^ -1))) >> 31)) & 2)) - (v642 + ((~(((v643 ^ -1) | (-(v643 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v645 = v644[v856];
      bool v857 = !(v645 == 0);
      if (v857) {
        int * v646 = v601->cache_tags;
        int v647 = v646[v856];
        int * v648 = v601->cache_vals;
        int v860 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1)) & 3) * 2)) + ((((v639 + ((~(((v641 ^ -1) | (-(v641 ^ -1))) >> 31)) & 2)) - (v642 + ((~(((v643 ^ -1) | (-(v643 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v649 = v648[v860];
        int v861 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1)) & 3) * 2)) + ((((v639 + ((~(((v641 ^ -1) | (-(v641 ^ -1))) >> 31)) & 2)) - (v642 + ((~(((v643 ^ -1) | (-(v643 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v650 = v648[v861];
        int * v651 = v601->mem;
        int v863 = v647 * 2;
        v651[v863] = v649;
        int * v653 = v601->mem;
        int v866 = (v647 * 2) + 1;
        v653[v866] = v650;
        ;
      } else {
        ;
      }
      int * v658 = v601->mem;
      int v871 = ((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1)) * 2;
      int v659 = v658[v871];
      int v872 = (((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1)) * 2) + 1;
      int v660 = v658[v872];
      int * v661 = v601->cache_vals;
      int v874 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1)) & 3) * 2)) + ((((v639 + ((~(((v641 ^ -1) | (-(v641 ^ -1))) >> 31)) & 2)) - (v642 + ((~(((v643 ^ -1) | (-(v643 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v661[v874] = v659;
      int * v663 = v601->cache_vals;
      int v877 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1)) & 3) * 2)) + ((((v639 + ((~(((v641 ^ -1) | (-(v641 ^ -1))) >> 31)) & 2)) - (v642 + ((~(((v643 ^ -1) | (-(v643 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v663[v877] = v660;
      int * v665 = v601->cache_tags;
      int v880 = (int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1);
      v665[v856] = v880;
      int * v667 = v601->cache_dirty;
      v667[v856] = 0;
      int * v669 = v601->cache_age;
      v669[v856] = 1;
      int * v671 = v601->cache_age;
      int v672 = v671[v856];
      int v673 = v671[v830];
      int v886 = v673 + ((int)((unsigned int)(v673 - v672) >> 31));
      v671[v830] = v886;
      int * v675 = v601->cache_age;
      int v676 = v675[v831];
      int v888 = v676 + ((int)((unsigned int)(v676 - v672) >> 31));
      v675[v831] = v888;
      int * v678 = v601->cache_age;
      v678[v856] = 0;
      v681 = v856;
    }
    int * v682 = v601->cache_vals;
    int v891 = v681 * 2;
    int v683 = v682[v891];
    int v892 = (v681 * 2) + 1;
    int v684 = v682[v892];
    int v893 = (((((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1)) & 1) * 2) + ((((v623 + ((~(((v625 ^ -1) | (-(v625 ^ -1))) >> 31)) & 2)) - (v626 + ((~(((v627 ^ -1) | (-(v627 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v682[v893] = v683;
    int * v686 = v601->cache_vals;
    int v896 = ((((((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1)) & 1) * 2) + ((((v623 + ((~(((v625 ^ -1) | (-(v625 ^ -1))) >> 31)) & 2)) - (v626 + ((~(((v627 ^ -1) | (-(v627 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v686[v896] = v684;
    int * v688 = v601->cache_tags;
    int v899 = ((((int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1)) & 1) * 2) + ((((v623 + ((~(((v625 ^ -1) | (-(v625 ^ -1))) >> 31)) & 2)) - (v626 + ((~(((v627 ^ -1) | (-(v627 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v900 = (int)((unsigned int)((int)((unsigned int)v603 >> 2)) >> 1);
    v688[v899] = v900;
    int * v690 = v601->cache_dirty;
    v690[v899] = 0;
    int * v692 = v601->cache_age;
    v692[v899] = 1;
    int * v694 = v601->cache_age;
    int v695 = v694[v899];
    int v696 = v694[v828];
    int v906 = v696 + ((int)((unsigned int)(v696 - v695) >> 31));
    v694[v828] = v906;
    int * v698 = v601->cache_age;
    int v699 = v698[v829];
    int v908 = v699 + ((int)((unsigned int)(v699 - v695) >> 31));
    v698[v829] = v908;
    int * v701 = v601->cache_age;
    v701[v899] = 0;
    v704 = v899;
  }
  int v911 = (v704 * 2) + (((int)((unsigned int)v603 >> 2)) & 1);
  int v705 = v611[v911];
  int * v706 = v601->regs;
  v706[7] = v705;
  struct StateT * v708 = v588->b;
  int * v709 = v708->regs;
  int v710 = v709[6];
  int * v711 = v708->cache_tags;
  int v918 = (((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 1) * 2;
  int v712 = v711[v918];
  int v919 = ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 1) * 2) + 1;
  int v713 = v711[v919];
  int v920 = 4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2);
  int v714 = v711[v920];
  int v921 = (4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v715 = v711[v921];
  int v716 = v708->timer;
  int v922 = v716 + ((100 ^ (((~(((v714 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v714 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31)) | (~(((v715 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v715 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v712 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v712 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31)) | (~(((v713 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v713 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v714 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v714 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31)) | (~(((v715 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v715 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31))) & 104)))));
  v708->timer = v922;
  int * v718 = v708->cache_vals;
  bool v923 = !(((~(((v712 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v712 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31)) | (~(((v713 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v713 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31))) == 0);
  int v811;
  if (v923) {
    int * v719 = v708->cache_age;
    int v925 = ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 1) * 2) + ((~(((v713 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v713 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31)) & 1);
    int v720 = v719[v925];
    int v721 = v719[v918];
    int v926 = v721 + ((int)((unsigned int)(v721 - v720) >> 31));
    v719[v918] = v926;
    int * v723 = v708->cache_age;
    int v724 = v723[v919];
    int v928 = v724 + ((int)((unsigned int)(v724 - v720) >> 31));
    v723[v919] = v928;
    int * v726 = v708->cache_age;
    v726[v925] = 0;
    v811 = v925;
  } else {
    int * v729 = v708->cache_age;
    int v932 = (((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 1) * 2;
    int v730 = v729[v932];
    int * v731 = v708->cache_tags;
    int v732 = v731[v932];
    int v733 = v729[v919];
    int v734 = v731[v919];
    bool v934 = !(((~(((v714 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v714 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31)) | (~(((v715 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v715 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31))) == 0);
    int v788;
    if (v934) {
      int * v735 = v708->cache_age;
      int v936 = (4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2)) + ((~(((v715 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))) | (-(v715 ^ ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1))))) >> 31)) & 1);
      int v736 = v735[v936];
      int v737 = v735[v920];
      int v937 = v737 + ((int)((unsigned int)(v737 - v736) >> 31));
      v735[v920] = v937;
      int * v739 = v708->cache_age;
      int v740 = v739[v921];
      int v939 = v740 + ((int)((unsigned int)(v740 - v736) >> 31));
      v739[v921] = v939;
      int * v742 = v708->cache_age;
      v742[v936] = 0;
      v788 = v936;
    } else {
      int * v745 = v708->cache_age;
      int v943 = 4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2);
      int v746 = v745[v943];
      int * v747 = v708->cache_tags;
      int v748 = v747[v943];
      int v749 = v745[v921];
      int v750 = v747[v921];
      int * v751 = v708->cache_dirty;
      int v946 = (4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2)) + ((((v746 + ((~(((v748 ^ -1) | (-(v748 ^ -1))) >> 31)) & 2)) - (v749 + ((~(((v750 ^ -1) | (-(v750 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v752 = v751[v946];
      bool v947 = !(v752 == 0);
      if (v947) {
        int * v753 = v708->cache_tags;
        int v754 = v753[v946];
        int * v755 = v708->cache_vals;
        int v950 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2)) + ((((v746 + ((~(((v748 ^ -1) | (-(v748 ^ -1))) >> 31)) & 2)) - (v749 + ((~(((v750 ^ -1) | (-(v750 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v756 = v755[v950];
        int v951 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2)) + ((((v746 + ((~(((v748 ^ -1) | (-(v748 ^ -1))) >> 31)) & 2)) - (v749 + ((~(((v750 ^ -1) | (-(v750 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v757 = v755[v951];
        int * v758 = v708->mem;
        int v953 = v754 * 2;
        v758[v953] = v756;
        int * v760 = v708->mem;
        int v956 = (v754 * 2) + 1;
        v760[v956] = v757;
        ;
      } else {
        ;
      }
      int * v765 = v708->mem;
      int v961 = ((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) * 2;
      int v766 = v765[v961];
      int v962 = (((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) * 2) + 1;
      int v767 = v765[v962];
      int * v768 = v708->cache_vals;
      int v964 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2)) + ((((v746 + ((~(((v748 ^ -1) | (-(v748 ^ -1))) >> 31)) & 2)) - (v749 + ((~(((v750 ^ -1) | (-(v750 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v768[v964] = v766;
      int * v770 = v708->cache_vals;
      int v967 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 3) * 2)) + ((((v746 + ((~(((v748 ^ -1) | (-(v748 ^ -1))) >> 31)) & 2)) - (v749 + ((~(((v750 ^ -1) | (-(v750 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v770[v967] = v767;
      int * v772 = v708->cache_tags;
      int v970 = (int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1);
      v772[v946] = v970;
      int * v774 = v708->cache_dirty;
      v774[v946] = 0;
      int * v776 = v708->cache_age;
      v776[v946] = 1;
      int * v778 = v708->cache_age;
      int v779 = v778[v946];
      int v780 = v778[v920];
      int v976 = v780 + ((int)((unsigned int)(v780 - v779) >> 31));
      v778[v920] = v976;
      int * v782 = v708->cache_age;
      int v783 = v782[v921];
      int v978 = v783 + ((int)((unsigned int)(v783 - v779) >> 31));
      v782[v921] = v978;
      int * v785 = v708->cache_age;
      v785[v946] = 0;
      v788 = v946;
    }
    int * v789 = v708->cache_vals;
    int v981 = v788 * 2;
    int v790 = v789[v981];
    int v982 = (v788 * 2) + 1;
    int v791 = v789[v982];
    int v983 = (((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 1) * 2) + ((((v730 + ((~(((v732 ^ -1) | (-(v732 ^ -1))) >> 31)) & 2)) - (v733 + ((~(((v734 ^ -1) | (-(v734 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v789[v983] = v790;
    int * v793 = v708->cache_vals;
    int v986 = ((((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 1) * 2) + ((((v730 + ((~(((v732 ^ -1) | (-(v732 ^ -1))) >> 31)) & 2)) - (v733 + ((~(((v734 ^ -1) | (-(v734 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v793[v986] = v791;
    int * v795 = v708->cache_tags;
    int v989 = ((((int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1)) & 1) * 2) + ((((v730 + ((~(((v732 ^ -1) | (-(v732 ^ -1))) >> 31)) & 2)) - (v733 + ((~(((v734 ^ -1) | (-(v734 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v990 = (int)((unsigned int)((int)((unsigned int)v710 >> 2)) >> 1);
    v795[v989] = v990;
    int * v797 = v708->cache_dirty;
    v797[v989] = 0;
    int * v799 = v708->cache_age;
    v799[v989] = 1;
    int * v801 = v708->cache_age;
    int v802 = v801[v989];
    int v803 = v801[v918];
    int v996 = v803 + ((int)((unsigned int)(v803 - v802) >> 31));
    v801[v918] = v996;
    int * v805 = v708->cache_age;
    int v806 = v805[v919];
    int v998 = v806 + ((int)((unsigned int)(v806 - v802) >> 31));
    v805[v919] = v998;
    int * v808 = v708->cache_age;
    v808[v989] = 0;
    v811 = v989;
  }
  int v1001 = (v811 * 2) + (((int)((unsigned int)v710 >> 2)) & 1);
  int v812 = v718[v1001];
  int * v813 = v708->regs;
  v813[7] = v812;
  struct StateT2 * v815 = slot_7(v588);
  return v815;
}

struct StateT2 * slot_16(struct StateT2 * v1744) {
  struct StateT * v1745 = v1744->a;
  int v1746 = v1745->timer;
  struct StateT * v1747 = v1744->b;
  int v1748 = v1747->timer;
  bool v1975 = v1746 == v1748;
  squared_assert(v1975);
  squared_assume(v1975);
  struct StateT * v1751 = v1744->a;
  int v1752 = v1751->timer;
  int v1977 = v1752 + 1;
  v1751->timer = v1977;
  struct StateT * v1754 = v1744->b;
  int v1755 = v1754->timer;
  int v1979 = v1755 + 1;
  v1754->timer = v1979;
  struct StateT * v1757 = v1744->a;
  int * v1758 = v1757->regs;
  int v1759 = v1758[6];
  int * v1760 = v1757->cache_tags;
  int v1984 = (((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1)) & 1) * 2;
  int v1761 = v1760[v1984];
  int v1985 = ((((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1762 = v1760[v1985];
  int v1986 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1)) & 3) * 2);
  int v1763 = v1760[v1986];
  int v1987 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1764 = v1760[v1987];
  int v1765 = v1757->timer;
  int v1988 = v1765 + ((100 ^ (((~(((v1763 ^ ((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1))) | (-(v1763 ^ ((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1))))) >> 31)) | (~(((v1764 ^ ((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1))) | (-(v1764 ^ ((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1761 ^ ((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1))) | (-(v1761 ^ ((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1))))) >> 31)) | (~(((v1762 ^ ((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1))) | (-(v1762 ^ ((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1763 ^ ((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1))) | (-(v1763 ^ ((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1))))) >> 31)) | (~(((v1764 ^ ((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1))) | (-(v1764 ^ ((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1757->timer = v1988;
  int * v1767 = v1757->cache_vals;
  bool v1989 = !(((~(((v1761 ^ ((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1))) | (-(v1761 ^ ((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1))))) >> 31)) | (~(((v1762 ^ ((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1))) | (-(v1762 ^ ((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1))))) >> 31))) == 0);
  int v1860;
  if (v1989) {
    int * v1768 = v1757->cache_age;
    int v1991 = ((((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1)) & 1) * 2) + ((~(((v1762 ^ ((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1))) | (-(v1762 ^ ((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1))))) >> 31)) & 1);
    int v1769 = v1768[v1991];
    int v1770 = v1768[v1984];
    int v1992 = v1770 + ((int)((unsigned int)(v1770 - v1769) >> 31));
    v1768[v1984] = v1992;
    int * v1772 = v1757->cache_age;
    int v1773 = v1772[v1985];
    int v1994 = v1773 + ((int)((unsigned int)(v1773 - v1769) >> 31));
    v1772[v1985] = v1994;
    int * v1775 = v1757->cache_age;
    v1775[v1991] = 0;
    v1860 = v1991;
  } else {
    int * v1778 = v1757->cache_age;
    int v1998 = (((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1)) & 1) * 2;
    int v1779 = v1778[v1998];
    int * v1780 = v1757->cache_tags;
    int v1781 = v1780[v1998];
    int v1782 = v1778[v1985];
    int v1783 = v1780[v1985];
    bool v2000 = !(((~(((v1763 ^ ((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1))) | (-(v1763 ^ ((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1))))) >> 31)) | (~(((v1764 ^ ((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1))) | (-(v1764 ^ ((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1))))) >> 31))) == 0);
    int v1837;
    if (v2000) {
      int * v1784 = v1757->cache_age;
      int v2002 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1764 ^ ((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1))) | (-(v1764 ^ ((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1))))) >> 31)) & 1);
      int v1785 = v1784[v2002];
      int v1786 = v1784[v1986];
      int v2003 = v1786 + ((int)((unsigned int)(v1786 - v1785) >> 31));
      v1784[v1986] = v2003;
      int * v1788 = v1757->cache_age;
      int v1789 = v1788[v1987];
      int v2005 = v1789 + ((int)((unsigned int)(v1789 - v1785) >> 31));
      v1788[v1987] = v2005;
      int * v1791 = v1757->cache_age;
      v1791[v2002] = 0;
      v1837 = v2002;
    } else {
      int * v1794 = v1757->cache_age;
      int v2009 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1)) & 3) * 2);
      int v1795 = v1794[v2009];
      int * v1796 = v1757->cache_tags;
      int v1797 = v1796[v2009];
      int v1798 = v1794[v1987];
      int v1799 = v1796[v1987];
      int * v1800 = v1757->cache_dirty;
      int v2012 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1)) & 3) * 2)) + ((((v1795 + ((~(((v1797 ^ -1) | (-(v1797 ^ -1))) >> 31)) & 2)) - (v1798 + ((~(((v1799 ^ -1) | (-(v1799 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1801 = v1800[v2012];
      bool v2013 = !(v1801 == 0);
      if (v2013) {
        int * v1802 = v1757->cache_tags;
        int v1803 = v1802[v2012];
        int * v1804 = v1757->cache_vals;
        int v2016 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1)) & 3) * 2)) + ((((v1795 + ((~(((v1797 ^ -1) | (-(v1797 ^ -1))) >> 31)) & 2)) - (v1798 + ((~(((v1799 ^ -1) | (-(v1799 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1805 = v1804[v2016];
        int v2017 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1)) & 3) * 2)) + ((((v1795 + ((~(((v1797 ^ -1) | (-(v1797 ^ -1))) >> 31)) & 2)) - (v1798 + ((~(((v1799 ^ -1) | (-(v1799 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1806 = v1804[v2017];
        int * v1807 = v1757->mem;
        int v2019 = v1803 * 2;
        v1807[v2019] = v1805;
        int * v1809 = v1757->mem;
        int v2022 = (v1803 * 2) + 1;
        v1809[v2022] = v1806;
        ;
      } else {
        ;
      }
      int * v1814 = v1757->mem;
      int v2027 = ((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1)) * 2;
      int v1815 = v1814[v2027];
      int v2028 = (((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1)) * 2) + 1;
      int v1816 = v1814[v2028];
      int * v1817 = v1757->cache_vals;
      int v2030 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1)) & 3) * 2)) + ((((v1795 + ((~(((v1797 ^ -1) | (-(v1797 ^ -1))) >> 31)) & 2)) - (v1798 + ((~(((v1799 ^ -1) | (-(v1799 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1817[v2030] = v1815;
      int * v1819 = v1757->cache_vals;
      int v2033 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1)) & 3) * 2)) + ((((v1795 + ((~(((v1797 ^ -1) | (-(v1797 ^ -1))) >> 31)) & 2)) - (v1798 + ((~(((v1799 ^ -1) | (-(v1799 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1819[v2033] = v1816;
      int * v1821 = v1757->cache_tags;
      int v2036 = (int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1);
      v1821[v2012] = v2036;
      int * v1823 = v1757->cache_dirty;
      v1823[v2012] = 0;
      int * v1825 = v1757->cache_age;
      v1825[v2012] = 1;
      int * v1827 = v1757->cache_age;
      int v1828 = v1827[v2012];
      int v1829 = v1827[v1986];
      int v2042 = v1829 + ((int)((unsigned int)(v1829 - v1828) >> 31));
      v1827[v1986] = v2042;
      int * v1831 = v1757->cache_age;
      int v1832 = v1831[v1987];
      int v2044 = v1832 + ((int)((unsigned int)(v1832 - v1828) >> 31));
      v1831[v1987] = v2044;
      int * v1834 = v1757->cache_age;
      v1834[v2012] = 0;
      v1837 = v2012;
    }
    int * v1838 = v1757->cache_vals;
    int v2047 = v1837 * 2;
    int v1839 = v1838[v2047];
    int v2048 = (v1837 * 2) + 1;
    int v1840 = v1838[v2048];
    int v2049 = (((((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1)) & 1) * 2) + ((((v1779 + ((~(((v1781 ^ -1) | (-(v1781 ^ -1))) >> 31)) & 2)) - (v1782 + ((~(((v1783 ^ -1) | (-(v1783 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1838[v2049] = v1839;
    int * v1842 = v1757->cache_vals;
    int v2052 = ((((((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1)) & 1) * 2) + ((((v1779 + ((~(((v1781 ^ -1) | (-(v1781 ^ -1))) >> 31)) & 2)) - (v1782 + ((~(((v1783 ^ -1) | (-(v1783 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1842[v2052] = v1840;
    int * v1844 = v1757->cache_tags;
    int v2055 = ((((int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1)) & 1) * 2) + ((((v1779 + ((~(((v1781 ^ -1) | (-(v1781 ^ -1))) >> 31)) & 2)) - (v1782 + ((~(((v1783 ^ -1) | (-(v1783 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2056 = (int)((unsigned int)((int)((unsigned int)v1759 >> 2)) >> 1);
    v1844[v2055] = v2056;
    int * v1846 = v1757->cache_dirty;
    v1846[v2055] = 0;
    int * v1848 = v1757->cache_age;
    v1848[v2055] = 1;
    int * v1850 = v1757->cache_age;
    int v1851 = v1850[v2055];
    int v1852 = v1850[v1984];
    int v2062 = v1852 + ((int)((unsigned int)(v1852 - v1851) >> 31));
    v1850[v1984] = v2062;
    int * v1854 = v1757->cache_age;
    int v1855 = v1854[v1985];
    int v2064 = v1855 + ((int)((unsigned int)(v1855 - v1851) >> 31));
    v1854[v1985] = v2064;
    int * v1857 = v1757->cache_age;
    v1857[v2055] = 0;
    v1860 = v2055;
  }
  int v2067 = (v1860 * 2) + (((int)((unsigned int)v1759 >> 2)) & 1);
  int v1861 = v1767[v2067];
  int * v1862 = v1757->regs;
  v1862[7] = v1861;
  struct StateT * v1864 = v1744->b;
  int * v1865 = v1864->regs;
  int v1866 = v1865[6];
  int * v1867 = v1864->cache_tags;
  int v2074 = (((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1)) & 1) * 2;
  int v1868 = v1867[v2074];
  int v2075 = ((((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1869 = v1867[v2075];
  int v2076 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1)) & 3) * 2);
  int v1870 = v1867[v2076];
  int v2077 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1871 = v1867[v2077];
  int v1872 = v1864->timer;
  int v2078 = v1872 + ((100 ^ (((~(((v1870 ^ ((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1))) | (-(v1870 ^ ((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1))))) >> 31)) | (~(((v1871 ^ ((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1))) | (-(v1871 ^ ((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1868 ^ ((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1))) | (-(v1868 ^ ((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1))))) >> 31)) | (~(((v1869 ^ ((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1))) | (-(v1869 ^ ((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1870 ^ ((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1))) | (-(v1870 ^ ((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1))))) >> 31)) | (~(((v1871 ^ ((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1))) | (-(v1871 ^ ((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1864->timer = v2078;
  int * v1874 = v1864->cache_vals;
  bool v2079 = !(((~(((v1868 ^ ((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1))) | (-(v1868 ^ ((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1))))) >> 31)) | (~(((v1869 ^ ((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1))) | (-(v1869 ^ ((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1))))) >> 31))) == 0);
  int v1967;
  if (v2079) {
    int * v1875 = v1864->cache_age;
    int v2081 = ((((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1)) & 1) * 2) + ((~(((v1869 ^ ((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1))) | (-(v1869 ^ ((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1))))) >> 31)) & 1);
    int v1876 = v1875[v2081];
    int v1877 = v1875[v2074];
    int v2082 = v1877 + ((int)((unsigned int)(v1877 - v1876) >> 31));
    v1875[v2074] = v2082;
    int * v1879 = v1864->cache_age;
    int v1880 = v1879[v2075];
    int v2084 = v1880 + ((int)((unsigned int)(v1880 - v1876) >> 31));
    v1879[v2075] = v2084;
    int * v1882 = v1864->cache_age;
    v1882[v2081] = 0;
    v1967 = v2081;
  } else {
    int * v1885 = v1864->cache_age;
    int v2088 = (((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1)) & 1) * 2;
    int v1886 = v1885[v2088];
    int * v1887 = v1864->cache_tags;
    int v1888 = v1887[v2088];
    int v1889 = v1885[v2075];
    int v1890 = v1887[v2075];
    bool v2090 = !(((~(((v1870 ^ ((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1))) | (-(v1870 ^ ((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1))))) >> 31)) | (~(((v1871 ^ ((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1))) | (-(v1871 ^ ((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1))))) >> 31))) == 0);
    int v1944;
    if (v2090) {
      int * v1891 = v1864->cache_age;
      int v2092 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1871 ^ ((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1))) | (-(v1871 ^ ((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1))))) >> 31)) & 1);
      int v1892 = v1891[v2092];
      int v1893 = v1891[v2076];
      int v2093 = v1893 + ((int)((unsigned int)(v1893 - v1892) >> 31));
      v1891[v2076] = v2093;
      int * v1895 = v1864->cache_age;
      int v1896 = v1895[v2077];
      int v2095 = v1896 + ((int)((unsigned int)(v1896 - v1892) >> 31));
      v1895[v2077] = v2095;
      int * v1898 = v1864->cache_age;
      v1898[v2092] = 0;
      v1944 = v2092;
    } else {
      int * v1901 = v1864->cache_age;
      int v2099 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1)) & 3) * 2);
      int v1902 = v1901[v2099];
      int * v1903 = v1864->cache_tags;
      int v1904 = v1903[v2099];
      int v1905 = v1901[v2077];
      int v1906 = v1903[v2077];
      int * v1907 = v1864->cache_dirty;
      int v2102 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1)) & 3) * 2)) + ((((v1902 + ((~(((v1904 ^ -1) | (-(v1904 ^ -1))) >> 31)) & 2)) - (v1905 + ((~(((v1906 ^ -1) | (-(v1906 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1908 = v1907[v2102];
      bool v2103 = !(v1908 == 0);
      if (v2103) {
        int * v1909 = v1864->cache_tags;
        int v1910 = v1909[v2102];
        int * v1911 = v1864->cache_vals;
        int v2106 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1)) & 3) * 2)) + ((((v1902 + ((~(((v1904 ^ -1) | (-(v1904 ^ -1))) >> 31)) & 2)) - (v1905 + ((~(((v1906 ^ -1) | (-(v1906 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1912 = v1911[v2106];
        int v2107 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1)) & 3) * 2)) + ((((v1902 + ((~(((v1904 ^ -1) | (-(v1904 ^ -1))) >> 31)) & 2)) - (v1905 + ((~(((v1906 ^ -1) | (-(v1906 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1913 = v1911[v2107];
        int * v1914 = v1864->mem;
        int v2109 = v1910 * 2;
        v1914[v2109] = v1912;
        int * v1916 = v1864->mem;
        int v2112 = (v1910 * 2) + 1;
        v1916[v2112] = v1913;
        ;
      } else {
        ;
      }
      int * v1921 = v1864->mem;
      int v2117 = ((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1)) * 2;
      int v1922 = v1921[v2117];
      int v2118 = (((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1)) * 2) + 1;
      int v1923 = v1921[v2118];
      int * v1924 = v1864->cache_vals;
      int v2120 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1)) & 3) * 2)) + ((((v1902 + ((~(((v1904 ^ -1) | (-(v1904 ^ -1))) >> 31)) & 2)) - (v1905 + ((~(((v1906 ^ -1) | (-(v1906 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1924[v2120] = v1922;
      int * v1926 = v1864->cache_vals;
      int v2123 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1)) & 3) * 2)) + ((((v1902 + ((~(((v1904 ^ -1) | (-(v1904 ^ -1))) >> 31)) & 2)) - (v1905 + ((~(((v1906 ^ -1) | (-(v1906 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1926[v2123] = v1923;
      int * v1928 = v1864->cache_tags;
      int v2126 = (int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1);
      v1928[v2102] = v2126;
      int * v1930 = v1864->cache_dirty;
      v1930[v2102] = 0;
      int * v1932 = v1864->cache_age;
      v1932[v2102] = 1;
      int * v1934 = v1864->cache_age;
      int v1935 = v1934[v2102];
      int v1936 = v1934[v2076];
      int v2132 = v1936 + ((int)((unsigned int)(v1936 - v1935) >> 31));
      v1934[v2076] = v2132;
      int * v1938 = v1864->cache_age;
      int v1939 = v1938[v2077];
      int v2134 = v1939 + ((int)((unsigned int)(v1939 - v1935) >> 31));
      v1938[v2077] = v2134;
      int * v1941 = v1864->cache_age;
      v1941[v2102] = 0;
      v1944 = v2102;
    }
    int * v1945 = v1864->cache_vals;
    int v2137 = v1944 * 2;
    int v1946 = v1945[v2137];
    int v2138 = (v1944 * 2) + 1;
    int v1947 = v1945[v2138];
    int v2139 = (((((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1)) & 1) * 2) + ((((v1886 + ((~(((v1888 ^ -1) | (-(v1888 ^ -1))) >> 31)) & 2)) - (v1889 + ((~(((v1890 ^ -1) | (-(v1890 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1945[v2139] = v1946;
    int * v1949 = v1864->cache_vals;
    int v2142 = ((((((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1)) & 1) * 2) + ((((v1886 + ((~(((v1888 ^ -1) | (-(v1888 ^ -1))) >> 31)) & 2)) - (v1889 + ((~(((v1890 ^ -1) | (-(v1890 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1949[v2142] = v1947;
    int * v1951 = v1864->cache_tags;
    int v2145 = ((((int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1)) & 1) * 2) + ((((v1886 + ((~(((v1888 ^ -1) | (-(v1888 ^ -1))) >> 31)) & 2)) - (v1889 + ((~(((v1890 ^ -1) | (-(v1890 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2146 = (int)((unsigned int)((int)((unsigned int)v1866 >> 2)) >> 1);
    v1951[v2145] = v2146;
    int * v1953 = v1864->cache_dirty;
    v1953[v2145] = 0;
    int * v1955 = v1864->cache_age;
    v1955[v2145] = 1;
    int * v1957 = v1864->cache_age;
    int v1958 = v1957[v2145];
    int v1959 = v1957[v2074];
    int v2152 = v1959 + ((int)((unsigned int)(v1959 - v1958) >> 31));
    v1957[v2074] = v2152;
    int * v1961 = v1864->cache_age;
    int v1962 = v1961[v2075];
    int v2154 = v1962 + ((int)((unsigned int)(v1962 - v1958) >> 31));
    v1961[v2075] = v2154;
    int * v1964 = v1864->cache_age;
    v1964[v2145] = 0;
    v1967 = v2145;
  }
  int v2157 = (v1967 * 2) + (((int)((unsigned int)v1866 >> 2)) & 1);
  int v1968 = v1874[v2157];
  int * v1969 = v1864->regs;
  v1969[7] = v1968;
  struct StateT2 * v1971 = slot_17(v1744);
  return v1971;
}

struct StateT2 * slot_5(struct StateT2 * v549) {
  struct StateT * v550 = v549->a;
  int v551 = v550->timer;
  struct StateT * v552 = v549->b;
  int v553 = v552->timer;
  bool v574 = v551 == v553;
  squared_assert(v574);
  squared_assume(v574);
  struct StateT * v556 = v549->a;
  int v557 = v556->timer;
  int v576 = v557 + 1;
  v556->timer = v576;
  struct StateT * v559 = v549->b;
  int v560 = v559->timer;
  int v578 = v560 + 1;
  v559->timer = v578;
  struct StateT * v562 = v549->a;
  int * v563 = v562->regs;
  int v564 = v563[6];
  int v582 = v564 << 2;
  v563[6] = v582;
  struct StateT * v566 = v549->b;
  int * v567 = v566->regs;
  int v568 = v567[6];
  int v585 = v568 << 2;
  v567[6] = v585;
  struct StateT2 * v570 = slot_6(v549);
  return v570;
}

struct StateT2 * slot_2(struct StateT2 * v428) {
  struct StateT * v429 = v428->a;
  int v430 = v429->timer;
  struct StateT * v431 = v428->b;
  int v432 = v431->timer;
  bool v455 = v430 == v432;
  squared_assert(v455);
  squared_assume(v455);
  struct StateT * v435 = v428->a;
  int v436 = v435->timer;
  int v457 = v436 + 1;
  v435->timer = v457;
  struct StateT * v438 = v428->b;
  int v439 = v438->timer;
  int v459 = v439 + 1;
  v438->timer = v459;
  struct StateT * v441 = v428->a;
  int * v442 = v441->regs;
  int v443 = v442[5];
  int v444 = v442[9];
  int v464 = v443 ^ v444;
  v442[5] = v464;
  struct StateT * v446 = v428->b;
  int * v447 = v446->regs;
  int v448 = v447[5];
  int v449 = v447[9];
  int v467 = v448 ^ v449;
  v447[5] = v467;
  struct StateT2 * v451 = slot_3(v428);
  return v451;
}

struct StateT2 * slot_7(struct StateT2 * v1006) {
  struct StateT * v1007 = v1006->a;
  int v1008 = v1007->timer;
  struct StateT * v1009 = v1006->b;
  int v1010 = v1009->timer;
  bool v1033 = v1008 == v1010;
  squared_assert(v1033);
  squared_assume(v1033);
  struct StateT * v1013 = v1006->a;
  int v1014 = v1013->timer;
  int v1035 = v1014 + 1;
  v1013->timer = v1035;
  struct StateT * v1016 = v1006->b;
  int v1017 = v1016->timer;
  int v1037 = v1017 + 1;
  v1016->timer = v1037;
  struct StateT * v1019 = v1006->a;
  int * v1020 = v1019->regs;
  int v1021 = v1020[5];
  int v1022 = v1020[7];
  int v1042 = v1021 ^ v1022;
  v1020[5] = v1042;
  struct StateT * v1024 = v1006->b;
  int * v1025 = v1024->regs;
  int v1026 = v1025[5];
  int v1027 = v1025[7];
  int v1045 = v1026 ^ v1027;
  v1025[5] = v1045;
  struct StateT2 * v1029 = slot_8(v1006);
  return v1029;
}

struct StateT2 * slot_21(struct StateT2 * v2322) {
  struct StateT * v2323 = v2322->a;
  int v2324 = v2323->timer;
  struct StateT * v2325 = v2322->b;
  int v2326 = v2325->timer;
  bool v2553 = v2324 == v2326;
  squared_assert(v2553);
  squared_assume(v2553);
  struct StateT * v2329 = v2322->a;
  int v2330 = v2329->timer;
  int v2555 = v2330 + 1;
  v2329->timer = v2555;
  struct StateT * v2332 = v2322->b;
  int v2333 = v2332->timer;
  int v2557 = v2333 + 1;
  v2332->timer = v2557;
  struct StateT * v2335 = v2322->a;
  int * v2336 = v2335->regs;
  int v2337 = v2336[6];
  int * v2338 = v2335->cache_tags;
  int v2562 = (((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1)) & 1) * 2;
  int v2339 = v2338[v2562];
  int v2563 = ((((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1)) & 1) * 2) + 1;
  int v2340 = v2338[v2563];
  int v2564 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1)) & 3) * 2);
  int v2341 = v2338[v2564];
  int v2565 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2342 = v2338[v2565];
  int v2343 = v2335->timer;
  int v2566 = v2343 + ((100 ^ (((~(((v2341 ^ ((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1))) | (-(v2341 ^ ((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1))))) >> 31)) | (~(((v2342 ^ ((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1))) | (-(v2342 ^ ((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2339 ^ ((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1))) | (-(v2339 ^ ((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1))))) >> 31)) | (~(((v2340 ^ ((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1))) | (-(v2340 ^ ((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2341 ^ ((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1))) | (-(v2341 ^ ((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1))))) >> 31)) | (~(((v2342 ^ ((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1))) | (-(v2342 ^ ((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2335->timer = v2566;
  int * v2345 = v2335->cache_vals;
  bool v2567 = !(((~(((v2339 ^ ((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1))) | (-(v2339 ^ ((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1))))) >> 31)) | (~(((v2340 ^ ((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1))) | (-(v2340 ^ ((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1))))) >> 31))) == 0);
  int v2438;
  if (v2567) {
    int * v2346 = v2335->cache_age;
    int v2569 = ((((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1)) & 1) * 2) + ((~(((v2340 ^ ((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1))) | (-(v2340 ^ ((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1))))) >> 31)) & 1);
    int v2347 = v2346[v2569];
    int v2348 = v2346[v2562];
    int v2570 = v2348 + ((int)((unsigned int)(v2348 - v2347) >> 31));
    v2346[v2562] = v2570;
    int * v2350 = v2335->cache_age;
    int v2351 = v2350[v2563];
    int v2572 = v2351 + ((int)((unsigned int)(v2351 - v2347) >> 31));
    v2350[v2563] = v2572;
    int * v2353 = v2335->cache_age;
    v2353[v2569] = 0;
    v2438 = v2569;
  } else {
    int * v2356 = v2335->cache_age;
    int v2576 = (((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1)) & 1) * 2;
    int v2357 = v2356[v2576];
    int * v2358 = v2335->cache_tags;
    int v2359 = v2358[v2576];
    int v2360 = v2356[v2563];
    int v2361 = v2358[v2563];
    bool v2578 = !(((~(((v2341 ^ ((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1))) | (-(v2341 ^ ((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1))))) >> 31)) | (~(((v2342 ^ ((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1))) | (-(v2342 ^ ((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1))))) >> 31))) == 0);
    int v2415;
    if (v2578) {
      int * v2362 = v2335->cache_age;
      int v2580 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2342 ^ ((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1))) | (-(v2342 ^ ((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1))))) >> 31)) & 1);
      int v2363 = v2362[v2580];
      int v2364 = v2362[v2564];
      int v2581 = v2364 + ((int)((unsigned int)(v2364 - v2363) >> 31));
      v2362[v2564] = v2581;
      int * v2366 = v2335->cache_age;
      int v2367 = v2366[v2565];
      int v2583 = v2367 + ((int)((unsigned int)(v2367 - v2363) >> 31));
      v2366[v2565] = v2583;
      int * v2369 = v2335->cache_age;
      v2369[v2580] = 0;
      v2415 = v2580;
    } else {
      int * v2372 = v2335->cache_age;
      int v2587 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1)) & 3) * 2);
      int v2373 = v2372[v2587];
      int * v2374 = v2335->cache_tags;
      int v2375 = v2374[v2587];
      int v2376 = v2372[v2565];
      int v2377 = v2374[v2565];
      int * v2378 = v2335->cache_dirty;
      int v2590 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1)) & 3) * 2)) + ((((v2373 + ((~(((v2375 ^ -1) | (-(v2375 ^ -1))) >> 31)) & 2)) - (v2376 + ((~(((v2377 ^ -1) | (-(v2377 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2379 = v2378[v2590];
      bool v2591 = !(v2379 == 0);
      if (v2591) {
        int * v2380 = v2335->cache_tags;
        int v2381 = v2380[v2590];
        int * v2382 = v2335->cache_vals;
        int v2594 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1)) & 3) * 2)) + ((((v2373 + ((~(((v2375 ^ -1) | (-(v2375 ^ -1))) >> 31)) & 2)) - (v2376 + ((~(((v2377 ^ -1) | (-(v2377 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2383 = v2382[v2594];
        int v2595 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1)) & 3) * 2)) + ((((v2373 + ((~(((v2375 ^ -1) | (-(v2375 ^ -1))) >> 31)) & 2)) - (v2376 + ((~(((v2377 ^ -1) | (-(v2377 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2384 = v2382[v2595];
        int * v2385 = v2335->mem;
        int v2597 = v2381 * 2;
        v2385[v2597] = v2383;
        int * v2387 = v2335->mem;
        int v2600 = (v2381 * 2) + 1;
        v2387[v2600] = v2384;
        ;
      } else {
        ;
      }
      int * v2392 = v2335->mem;
      int v2605 = ((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1)) * 2;
      int v2393 = v2392[v2605];
      int v2606 = (((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1)) * 2) + 1;
      int v2394 = v2392[v2606];
      int * v2395 = v2335->cache_vals;
      int v2608 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1)) & 3) * 2)) + ((((v2373 + ((~(((v2375 ^ -1) | (-(v2375 ^ -1))) >> 31)) & 2)) - (v2376 + ((~(((v2377 ^ -1) | (-(v2377 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2395[v2608] = v2393;
      int * v2397 = v2335->cache_vals;
      int v2611 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1)) & 3) * 2)) + ((((v2373 + ((~(((v2375 ^ -1) | (-(v2375 ^ -1))) >> 31)) & 2)) - (v2376 + ((~(((v2377 ^ -1) | (-(v2377 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2397[v2611] = v2394;
      int * v2399 = v2335->cache_tags;
      int v2614 = (int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1);
      v2399[v2590] = v2614;
      int * v2401 = v2335->cache_dirty;
      v2401[v2590] = 0;
      int * v2403 = v2335->cache_age;
      v2403[v2590] = 1;
      int * v2405 = v2335->cache_age;
      int v2406 = v2405[v2590];
      int v2407 = v2405[v2564];
      int v2620 = v2407 + ((int)((unsigned int)(v2407 - v2406) >> 31));
      v2405[v2564] = v2620;
      int * v2409 = v2335->cache_age;
      int v2410 = v2409[v2565];
      int v2622 = v2410 + ((int)((unsigned int)(v2410 - v2406) >> 31));
      v2409[v2565] = v2622;
      int * v2412 = v2335->cache_age;
      v2412[v2590] = 0;
      v2415 = v2590;
    }
    int * v2416 = v2335->cache_vals;
    int v2625 = v2415 * 2;
    int v2417 = v2416[v2625];
    int v2626 = (v2415 * 2) + 1;
    int v2418 = v2416[v2626];
    int v2627 = (((((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1)) & 1) * 2) + ((((v2357 + ((~(((v2359 ^ -1) | (-(v2359 ^ -1))) >> 31)) & 2)) - (v2360 + ((~(((v2361 ^ -1) | (-(v2361 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2416[v2627] = v2417;
    int * v2420 = v2335->cache_vals;
    int v2630 = ((((((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1)) & 1) * 2) + ((((v2357 + ((~(((v2359 ^ -1) | (-(v2359 ^ -1))) >> 31)) & 2)) - (v2360 + ((~(((v2361 ^ -1) | (-(v2361 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2420[v2630] = v2418;
    int * v2422 = v2335->cache_tags;
    int v2633 = ((((int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1)) & 1) * 2) + ((((v2357 + ((~(((v2359 ^ -1) | (-(v2359 ^ -1))) >> 31)) & 2)) - (v2360 + ((~(((v2361 ^ -1) | (-(v2361 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2634 = (int)((unsigned int)((int)((unsigned int)v2337 >> 2)) >> 1);
    v2422[v2633] = v2634;
    int * v2424 = v2335->cache_dirty;
    v2424[v2633] = 0;
    int * v2426 = v2335->cache_age;
    v2426[v2633] = 1;
    int * v2428 = v2335->cache_age;
    int v2429 = v2428[v2633];
    int v2430 = v2428[v2562];
    int v2640 = v2430 + ((int)((unsigned int)(v2430 - v2429) >> 31));
    v2428[v2562] = v2640;
    int * v2432 = v2335->cache_age;
    int v2433 = v2432[v2563];
    int v2642 = v2433 + ((int)((unsigned int)(v2433 - v2429) >> 31));
    v2432[v2563] = v2642;
    int * v2435 = v2335->cache_age;
    v2435[v2633] = 0;
    v2438 = v2633;
  }
  int v2645 = (v2438 * 2) + (((int)((unsigned int)v2337 >> 2)) & 1);
  int v2439 = v2345[v2645];
  int * v2440 = v2335->regs;
  v2440[7] = v2439;
  struct StateT * v2442 = v2322->b;
  int * v2443 = v2442->regs;
  int v2444 = v2443[6];
  int * v2445 = v2442->cache_tags;
  int v2652 = (((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1)) & 1) * 2;
  int v2446 = v2445[v2652];
  int v2653 = ((((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1)) & 1) * 2) + 1;
  int v2447 = v2445[v2653];
  int v2654 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1)) & 3) * 2);
  int v2448 = v2445[v2654];
  int v2655 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2449 = v2445[v2655];
  int v2450 = v2442->timer;
  int v2656 = v2450 + ((100 ^ (((~(((v2448 ^ ((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1))) | (-(v2448 ^ ((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1))))) >> 31)) | (~(((v2449 ^ ((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1))) | (-(v2449 ^ ((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2446 ^ ((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1))) | (-(v2446 ^ ((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1))))) >> 31)) | (~(((v2447 ^ ((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1))) | (-(v2447 ^ ((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2448 ^ ((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1))) | (-(v2448 ^ ((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1))))) >> 31)) | (~(((v2449 ^ ((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1))) | (-(v2449 ^ ((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2442->timer = v2656;
  int * v2452 = v2442->cache_vals;
  bool v2657 = !(((~(((v2446 ^ ((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1))) | (-(v2446 ^ ((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1))))) >> 31)) | (~(((v2447 ^ ((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1))) | (-(v2447 ^ ((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1))))) >> 31))) == 0);
  int v2545;
  if (v2657) {
    int * v2453 = v2442->cache_age;
    int v2659 = ((((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1)) & 1) * 2) + ((~(((v2447 ^ ((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1))) | (-(v2447 ^ ((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1))))) >> 31)) & 1);
    int v2454 = v2453[v2659];
    int v2455 = v2453[v2652];
    int v2660 = v2455 + ((int)((unsigned int)(v2455 - v2454) >> 31));
    v2453[v2652] = v2660;
    int * v2457 = v2442->cache_age;
    int v2458 = v2457[v2653];
    int v2662 = v2458 + ((int)((unsigned int)(v2458 - v2454) >> 31));
    v2457[v2653] = v2662;
    int * v2460 = v2442->cache_age;
    v2460[v2659] = 0;
    v2545 = v2659;
  } else {
    int * v2463 = v2442->cache_age;
    int v2666 = (((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1)) & 1) * 2;
    int v2464 = v2463[v2666];
    int * v2465 = v2442->cache_tags;
    int v2466 = v2465[v2666];
    int v2467 = v2463[v2653];
    int v2468 = v2465[v2653];
    bool v2668 = !(((~(((v2448 ^ ((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1))) | (-(v2448 ^ ((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1))))) >> 31)) | (~(((v2449 ^ ((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1))) | (-(v2449 ^ ((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1))))) >> 31))) == 0);
    int v2522;
    if (v2668) {
      int * v2469 = v2442->cache_age;
      int v2670 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2449 ^ ((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1))) | (-(v2449 ^ ((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1))))) >> 31)) & 1);
      int v2470 = v2469[v2670];
      int v2471 = v2469[v2654];
      int v2671 = v2471 + ((int)((unsigned int)(v2471 - v2470) >> 31));
      v2469[v2654] = v2671;
      int * v2473 = v2442->cache_age;
      int v2474 = v2473[v2655];
      int v2673 = v2474 + ((int)((unsigned int)(v2474 - v2470) >> 31));
      v2473[v2655] = v2673;
      int * v2476 = v2442->cache_age;
      v2476[v2670] = 0;
      v2522 = v2670;
    } else {
      int * v2479 = v2442->cache_age;
      int v2677 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1)) & 3) * 2);
      int v2480 = v2479[v2677];
      int * v2481 = v2442->cache_tags;
      int v2482 = v2481[v2677];
      int v2483 = v2479[v2655];
      int v2484 = v2481[v2655];
      int * v2485 = v2442->cache_dirty;
      int v2680 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1)) & 3) * 2)) + ((((v2480 + ((~(((v2482 ^ -1) | (-(v2482 ^ -1))) >> 31)) & 2)) - (v2483 + ((~(((v2484 ^ -1) | (-(v2484 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2486 = v2485[v2680];
      bool v2681 = !(v2486 == 0);
      if (v2681) {
        int * v2487 = v2442->cache_tags;
        int v2488 = v2487[v2680];
        int * v2489 = v2442->cache_vals;
        int v2684 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1)) & 3) * 2)) + ((((v2480 + ((~(((v2482 ^ -1) | (-(v2482 ^ -1))) >> 31)) & 2)) - (v2483 + ((~(((v2484 ^ -1) | (-(v2484 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2490 = v2489[v2684];
        int v2685 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1)) & 3) * 2)) + ((((v2480 + ((~(((v2482 ^ -1) | (-(v2482 ^ -1))) >> 31)) & 2)) - (v2483 + ((~(((v2484 ^ -1) | (-(v2484 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2491 = v2489[v2685];
        int * v2492 = v2442->mem;
        int v2687 = v2488 * 2;
        v2492[v2687] = v2490;
        int * v2494 = v2442->mem;
        int v2690 = (v2488 * 2) + 1;
        v2494[v2690] = v2491;
        ;
      } else {
        ;
      }
      int * v2499 = v2442->mem;
      int v2695 = ((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1)) * 2;
      int v2500 = v2499[v2695];
      int v2696 = (((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1)) * 2) + 1;
      int v2501 = v2499[v2696];
      int * v2502 = v2442->cache_vals;
      int v2698 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1)) & 3) * 2)) + ((((v2480 + ((~(((v2482 ^ -1) | (-(v2482 ^ -1))) >> 31)) & 2)) - (v2483 + ((~(((v2484 ^ -1) | (-(v2484 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2502[v2698] = v2500;
      int * v2504 = v2442->cache_vals;
      int v2701 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1)) & 3) * 2)) + ((((v2480 + ((~(((v2482 ^ -1) | (-(v2482 ^ -1))) >> 31)) & 2)) - (v2483 + ((~(((v2484 ^ -1) | (-(v2484 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2504[v2701] = v2501;
      int * v2506 = v2442->cache_tags;
      int v2704 = (int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1);
      v2506[v2680] = v2704;
      int * v2508 = v2442->cache_dirty;
      v2508[v2680] = 0;
      int * v2510 = v2442->cache_age;
      v2510[v2680] = 1;
      int * v2512 = v2442->cache_age;
      int v2513 = v2512[v2680];
      int v2514 = v2512[v2654];
      int v2710 = v2514 + ((int)((unsigned int)(v2514 - v2513) >> 31));
      v2512[v2654] = v2710;
      int * v2516 = v2442->cache_age;
      int v2517 = v2516[v2655];
      int v2712 = v2517 + ((int)((unsigned int)(v2517 - v2513) >> 31));
      v2516[v2655] = v2712;
      int * v2519 = v2442->cache_age;
      v2519[v2680] = 0;
      v2522 = v2680;
    }
    int * v2523 = v2442->cache_vals;
    int v2715 = v2522 * 2;
    int v2524 = v2523[v2715];
    int v2716 = (v2522 * 2) + 1;
    int v2525 = v2523[v2716];
    int v2717 = (((((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1)) & 1) * 2) + ((((v2464 + ((~(((v2466 ^ -1) | (-(v2466 ^ -1))) >> 31)) & 2)) - (v2467 + ((~(((v2468 ^ -1) | (-(v2468 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2523[v2717] = v2524;
    int * v2527 = v2442->cache_vals;
    int v2720 = ((((((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1)) & 1) * 2) + ((((v2464 + ((~(((v2466 ^ -1) | (-(v2466 ^ -1))) >> 31)) & 2)) - (v2467 + ((~(((v2468 ^ -1) | (-(v2468 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2527[v2720] = v2525;
    int * v2529 = v2442->cache_tags;
    int v2723 = ((((int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1)) & 1) * 2) + ((((v2464 + ((~(((v2466 ^ -1) | (-(v2466 ^ -1))) >> 31)) & 2)) - (v2467 + ((~(((v2468 ^ -1) | (-(v2468 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2724 = (int)((unsigned int)((int)((unsigned int)v2444 >> 2)) >> 1);
    v2529[v2723] = v2724;
    int * v2531 = v2442->cache_dirty;
    v2531[v2723] = 0;
    int * v2533 = v2442->cache_age;
    v2533[v2723] = 1;
    int * v2535 = v2442->cache_age;
    int v2536 = v2535[v2723];
    int v2537 = v2535[v2652];
    int v2730 = v2537 + ((int)((unsigned int)(v2537 - v2536) >> 31));
    v2535[v2652] = v2730;
    int * v2539 = v2442->cache_age;
    int v2540 = v2539[v2653];
    int v2732 = v2540 + ((int)((unsigned int)(v2540 - v2536) >> 31));
    v2539[v2653] = v2732;
    int * v2542 = v2442->cache_age;
    v2542[v2723] = 0;
    v2545 = v2723;
  }
  int v2735 = (v2545 * 2) + (((int)((unsigned int)v2444 >> 2)) & 1);
  int v2546 = v2452[v2735];
  int * v2547 = v2442->regs;
  v2547[7] = v2546;
  struct StateT2 * v2549 = slot_22(v2322);
  return v2549;
}

struct StateT2 * slot_3(struct StateT2 * v470) {
  struct StateT * v471 = v470->a;
  int v472 = v471->timer;
  struct StateT * v473 = v470->b;
  int v474 = v473->timer;
  bool v495 = v472 == v474;
  squared_assert(v495);
  squared_assume(v495);
  struct StateT * v477 = v470->a;
  int v478 = v477->timer;
  int v497 = v478 + 1;
  v477->timer = v497;
  struct StateT * v480 = v470->b;
  int v481 = v480->timer;
  int v499 = v481 + 1;
  v480->timer = v499;
  struct StateT * v483 = v470->a;
  int * v484 = v483->regs;
  int v485 = v484[10];
  v484[6] = v485;
  struct StateT * v487 = v470->b;
  int * v488 = v487->regs;
  int v489 = v488[10];
  v488[6] = v489;
  struct StateT2 * v491 = slot_4(v470);
  return v491;
}

struct StateT2 * slot_10(struct StateT2 * v1127) {
  struct StateT * v1128 = v1127->a;
  int v1129 = v1128->timer;
  struct StateT * v1130 = v1127->b;
  int v1131 = v1130->timer;
  bool v1152 = v1129 == v1131;
  squared_assert(v1152);
  squared_assume(v1152);
  struct StateT * v1134 = v1127->a;
  int v1135 = v1134->timer;
  int v1154 = v1135 + 1;
  v1134->timer = v1154;
  struct StateT * v1137 = v1127->b;
  int v1138 = v1137->timer;
  int v1156 = v1138 + 1;
  v1137->timer = v1156;
  struct StateT * v1140 = v1127->a;
  int * v1141 = v1140->regs;
  int v1142 = v1141[6];
  int v1160 = v1142 << 2;
  v1141[6] = v1160;
  struct StateT * v1144 = v1127->b;
  int * v1145 = v1144->regs;
  int v1146 = v1145[6];
  int v1163 = v1146 << 2;
  v1145[6] = v1163;
  struct StateT2 * v1148 = slot_11(v1127);
  return v1148;
}

struct StateT2 * slot_1(struct StateT2 * v38) {
  struct StateT * v39 = v38->a;
  int v40 = v39->timer;
  struct StateT * v41 = v38->b;
  int v42 = v41->timer;
  bool v265 = v40 == v42;
  squared_assert(v265);
  squared_assume(v265);
  struct StateT * v45 = v38->a;
  int v46 = v45->timer;
  int v267 = v46 + 1;
  v45->timer = v267;
  struct StateT * v48 = v38->b;
  int v49 = v48->timer;
  int v269 = v49 + 1;
  v48->timer = v269;
  struct StateT * v51 = v38->a;
  int * v52 = v51->cache_tags;
  int v53 = v52[0];
  int v54 = v52[1];
  int v55 = v52[8];
  int v56 = v52[9];
  int v57 = v51->timer;
  int v276 = v57 + ((100 ^ (((~(((v55 ^ 10) | (-(v55 ^ 10))) >> 31)) | (~(((v56 ^ 10) | (-(v56 ^ 10))) >> 31))) & 104)) ^ (((~(((v53 ^ 10) | (-(v53 ^ 10))) >> 31)) | (~(((v54 ^ 10) | (-(v54 ^ 10))) >> 31))) & (1 ^ (100 ^ (((~(((v55 ^ 10) | (-(v55 ^ 10))) >> 31)) | (~(((v56 ^ 10) | (-(v56 ^ 10))) >> 31))) & 104)))));
  v51->timer = v276;
  int * v59 = v51->cache_vals;
  bool v277 = !(((~(((v53 ^ 10) | (-(v53 ^ 10))) >> 31)) | (~(((v54 ^ 10) | (-(v54 ^ 10))) >> 31))) == 0);
  int v152;
  if (v277) {
    int * v60 = v51->cache_age;
    int v279 = (~(((v54 ^ 10) | (-(v54 ^ 10))) >> 31)) & 1;
    int v61 = v60[v279];
    int v62 = v60[0];
    int v280 = v62 + ((int)((unsigned int)(v62 - v61) >> 31));
    v60[0] = v280;
    int * v64 = v51->cache_age;
    int v65 = v64[1];
    int v282 = v65 + ((int)((unsigned int)(v65 - v61) >> 31));
    v64[1] = v282;
    int * v67 = v51->cache_age;
    v67[v279] = 0;
    v152 = v279;
  } else {
    int * v70 = v51->cache_age;
    int v71 = v70[0];
    int * v72 = v51->cache_tags;
    int v73 = v72[0];
    int v74 = v70[1];
    int v75 = v72[1];
    bool v286 = !(((~(((v55 ^ 10) | (-(v55 ^ 10))) >> 31)) | (~(((v56 ^ 10) | (-(v56 ^ 10))) >> 31))) == 0);
    int v129;
    if (v286) {
      int * v76 = v51->cache_age;
      int v288 = 8 + ((~(((v56 ^ 10) | (-(v56 ^ 10))) >> 31)) & 1);
      int v77 = v76[v288];
      int v78 = v76[8];
      int v289 = v78 + ((int)((unsigned int)(v78 - v77) >> 31));
      v76[8] = v289;
      int * v80 = v51->cache_age;
      int v81 = v80[9];
      int v291 = v81 + ((int)((unsigned int)(v81 - v77) >> 31));
      v80[9] = v291;
      int * v83 = v51->cache_age;
      v83[v288] = 0;
      v129 = v288;
    } else {
      int * v86 = v51->cache_age;
      int v87 = v86[8];
      int * v88 = v51->cache_tags;
      int v89 = v88[8];
      int v90 = v86[9];
      int v91 = v88[9];
      int * v92 = v51->cache_dirty;
      int v296 = 8 + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v90 + ((~(((v91 ^ -1) | (-(v91 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v93 = v92[v296];
      bool v297 = !(v93 == 0);
      if (v297) {
        int * v94 = v51->cache_tags;
        int v95 = v94[v296];
        int * v96 = v51->cache_vals;
        int v300 = (8 + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v90 + ((~(((v91 ^ -1) | (-(v91 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v97 = v96[v300];
        int v301 = ((8 + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v90 + ((~(((v91 ^ -1) | (-(v91 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v98 = v96[v301];
        int * v99 = v51->mem;
        int v303 = v95 * 2;
        v99[v303] = v97;
        int * v101 = v51->mem;
        int v306 = (v95 * 2) + 1;
        v101[v306] = v98;
        ;
      } else {
        ;
      }
      int * v106 = v51->mem;
      int v107 = v106[20];
      int v108 = v106[21];
      int * v109 = v51->cache_vals;
      int v314 = (8 + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v90 + ((~(((v91 ^ -1) | (-(v91 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v109[v314] = v107;
      int * v111 = v51->cache_vals;
      int v317 = ((8 + ((((v87 + ((~(((v89 ^ -1) | (-(v89 ^ -1))) >> 31)) & 2)) - (v90 + ((~(((v91 ^ -1) | (-(v91 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v111[v317] = v108;
      int * v113 = v51->cache_tags;
      v113[v296] = 10;
      int * v115 = v51->cache_dirty;
      v115[v296] = 0;
      int * v117 = v51->cache_age;
      v117[v296] = 1;
      int * v119 = v51->cache_age;
      int v120 = v119[v296];
      int v121 = v119[8];
      int v324 = v121 + ((int)((unsigned int)(v121 - v120) >> 31));
      v119[8] = v324;
      int * v123 = v51->cache_age;
      int v124 = v123[9];
      int v326 = v124 + ((int)((unsigned int)(v124 - v120) >> 31));
      v123[9] = v326;
      int * v126 = v51->cache_age;
      v126[v296] = 0;
      v129 = v296;
    }
    int * v130 = v51->cache_vals;
    int v329 = v129 * 2;
    int v131 = v130[v329];
    int v330 = (v129 * 2) + 1;
    int v132 = v130[v330];
    int v331 = ((((v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v130[v331] = v131;
    int * v134 = v51->cache_vals;
    int v334 = (((((v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v134[v334] = v132;
    int * v136 = v51->cache_tags;
    int v337 = (((v71 + ((~(((v73 ^ -1) | (-(v73 ^ -1))) >> 31)) & 2)) - (v74 + ((~(((v75 ^ -1) | (-(v75 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v136[v337] = 10;
    int * v138 = v51->cache_dirty;
    v138[v337] = 0;
    int * v140 = v51->cache_age;
    v140[v337] = 1;
    int * v142 = v51->cache_age;
    int v143 = v142[v337];
    int v144 = v142[0];
    int v342 = v144 + ((int)((unsigned int)(v144 - v143) >> 31));
    v142[0] = v342;
    int * v146 = v51->cache_age;
    int v147 = v146[1];
    int v344 = v147 + ((int)((unsigned int)(v147 - v143) >> 31));
    v146[1] = v344;
    int * v149 = v51->cache_age;
    v149[v337] = 0;
    v152 = v337;
  }
  int v347 = v152 * 2;
  int v153 = v59[v347];
  int * v154 = v51->regs;
  v154[9] = v153;
  struct StateT * v156 = v38->b;
  int * v157 = v156->cache_tags;
  int v158 = v157[0];
  int v159 = v157[1];
  int v160 = v157[8];
  int v161 = v157[9];
  int v162 = v156->timer;
  int v352 = v162 + ((100 ^ (((~(((v160 ^ 10) | (-(v160 ^ 10))) >> 31)) | (~(((v161 ^ 10) | (-(v161 ^ 10))) >> 31))) & 104)) ^ (((~(((v158 ^ 10) | (-(v158 ^ 10))) >> 31)) | (~(((v159 ^ 10) | (-(v159 ^ 10))) >> 31))) & (1 ^ (100 ^ (((~(((v160 ^ 10) | (-(v160 ^ 10))) >> 31)) | (~(((v161 ^ 10) | (-(v161 ^ 10))) >> 31))) & 104)))));
  v156->timer = v352;
  int * v164 = v156->cache_vals;
  bool v353 = !(((~(((v158 ^ 10) | (-(v158 ^ 10))) >> 31)) | (~(((v159 ^ 10) | (-(v159 ^ 10))) >> 31))) == 0);
  int v257;
  if (v353) {
    int * v165 = v156->cache_age;
    int v355 = (~(((v159 ^ 10) | (-(v159 ^ 10))) >> 31)) & 1;
    int v166 = v165[v355];
    int v167 = v165[0];
    int v356 = v167 + ((int)((unsigned int)(v167 - v166) >> 31));
    v165[0] = v356;
    int * v169 = v156->cache_age;
    int v170 = v169[1];
    int v358 = v170 + ((int)((unsigned int)(v170 - v166) >> 31));
    v169[1] = v358;
    int * v172 = v156->cache_age;
    v172[v355] = 0;
    v257 = v355;
  } else {
    int * v175 = v156->cache_age;
    int v176 = v175[0];
    int * v177 = v156->cache_tags;
    int v178 = v177[0];
    int v179 = v175[1];
    int v180 = v177[1];
    bool v362 = !(((~(((v160 ^ 10) | (-(v160 ^ 10))) >> 31)) | (~(((v161 ^ 10) | (-(v161 ^ 10))) >> 31))) == 0);
    int v234;
    if (v362) {
      int * v181 = v156->cache_age;
      int v364 = 8 + ((~(((v161 ^ 10) | (-(v161 ^ 10))) >> 31)) & 1);
      int v182 = v181[v364];
      int v183 = v181[8];
      int v365 = v183 + ((int)((unsigned int)(v183 - v182) >> 31));
      v181[8] = v365;
      int * v185 = v156->cache_age;
      int v186 = v185[9];
      int v367 = v186 + ((int)((unsigned int)(v186 - v182) >> 31));
      v185[9] = v367;
      int * v188 = v156->cache_age;
      v188[v364] = 0;
      v234 = v364;
    } else {
      int * v191 = v156->cache_age;
      int v192 = v191[8];
      int * v193 = v156->cache_tags;
      int v194 = v193[8];
      int v195 = v191[9];
      int v196 = v193[9];
      int * v197 = v156->cache_dirty;
      int v372 = 8 + ((((v192 + ((~(((v194 ^ -1) | (-(v194 ^ -1))) >> 31)) & 2)) - (v195 + ((~(((v196 ^ -1) | (-(v196 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v198 = v197[v372];
      bool v373 = !(v198 == 0);
      if (v373) {
        int * v199 = v156->cache_tags;
        int v200 = v199[v372];
        int * v201 = v156->cache_vals;
        int v376 = (8 + ((((v192 + ((~(((v194 ^ -1) | (-(v194 ^ -1))) >> 31)) & 2)) - (v195 + ((~(((v196 ^ -1) | (-(v196 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v202 = v201[v376];
        int v377 = ((8 + ((((v192 + ((~(((v194 ^ -1) | (-(v194 ^ -1))) >> 31)) & 2)) - (v195 + ((~(((v196 ^ -1) | (-(v196 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v203 = v201[v377];
        int * v204 = v156->mem;
        int v379 = v200 * 2;
        v204[v379] = v202;
        int * v206 = v156->mem;
        int v382 = (v200 * 2) + 1;
        v206[v382] = v203;
        ;
      } else {
        ;
      }
      int * v211 = v156->mem;
      int v212 = v211[20];
      int v213 = v211[21];
      int * v214 = v156->cache_vals;
      int v390 = (8 + ((((v192 + ((~(((v194 ^ -1) | (-(v194 ^ -1))) >> 31)) & 2)) - (v195 + ((~(((v196 ^ -1) | (-(v196 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v214[v390] = v212;
      int * v216 = v156->cache_vals;
      int v393 = ((8 + ((((v192 + ((~(((v194 ^ -1) | (-(v194 ^ -1))) >> 31)) & 2)) - (v195 + ((~(((v196 ^ -1) | (-(v196 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v216[v393] = v213;
      int * v218 = v156->cache_tags;
      v218[v372] = 10;
      int * v220 = v156->cache_dirty;
      v220[v372] = 0;
      int * v222 = v156->cache_age;
      v222[v372] = 1;
      int * v224 = v156->cache_age;
      int v225 = v224[v372];
      int v226 = v224[8];
      int v400 = v226 + ((int)((unsigned int)(v226 - v225) >> 31));
      v224[8] = v400;
      int * v228 = v156->cache_age;
      int v229 = v228[9];
      int v402 = v229 + ((int)((unsigned int)(v229 - v225) >> 31));
      v228[9] = v402;
      int * v231 = v156->cache_age;
      v231[v372] = 0;
      v234 = v372;
    }
    int * v235 = v156->cache_vals;
    int v405 = v234 * 2;
    int v236 = v235[v405];
    int v406 = (v234 * 2) + 1;
    int v237 = v235[v406];
    int v407 = ((((v176 + ((~(((v178 ^ -1) | (-(v178 ^ -1))) >> 31)) & 2)) - (v179 + ((~(((v180 ^ -1) | (-(v180 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2;
    v235[v407] = v236;
    int * v239 = v156->cache_vals;
    int v410 = (((((v176 + ((~(((v178 ^ -1) | (-(v178 ^ -1))) >> 31)) & 2)) - (v179 + ((~(((v180 ^ -1) | (-(v180 ^ -1))) >> 31)) & 2))) >> 31) & 1) * 2) + 1;
    v239[v410] = v237;
    int * v241 = v156->cache_tags;
    int v413 = (((v176 + ((~(((v178 ^ -1) | (-(v178 ^ -1))) >> 31)) & 2)) - (v179 + ((~(((v180 ^ -1) | (-(v180 ^ -1))) >> 31)) & 2))) >> 31) & 1;
    v241[v413] = 10;
    int * v243 = v156->cache_dirty;
    v243[v413] = 0;
    int * v245 = v156->cache_age;
    v245[v413] = 1;
    int * v247 = v156->cache_age;
    int v248 = v247[v413];
    int v249 = v247[0];
    int v418 = v249 + ((int)((unsigned int)(v249 - v248) >> 31));
    v247[0] = v418;
    int * v251 = v156->cache_age;
    int v252 = v251[1];
    int v420 = v252 + ((int)((unsigned int)(v252 - v248) >> 31));
    v251[1] = v420;
    int * v254 = v156->cache_age;
    v254[v413] = 0;
    v257 = v413;
  }
  int v423 = v257 * 2;
  int v258 = v164[v423];
  int * v259 = v156->regs;
  v259[9] = v258;
  struct StateT2 * v261 = slot_2(v38);
  return v261;
}

struct StateT2 * slot_19(struct StateT2 * v2244) {
  struct StateT * v2245 = v2244->a;
  int v2246 = v2245->timer;
  struct StateT * v2247 = v2244->b;
  int v2248 = v2247->timer;
  bool v2269 = v2246 == v2248;
  squared_assert(v2269);
  squared_assume(v2269);
  struct StateT * v2251 = v2244->a;
  int v2252 = v2251->timer;
  int v2271 = v2252 + 1;
  v2251->timer = v2271;
  struct StateT * v2254 = v2244->b;
  int v2255 = v2254->timer;
  int v2273 = v2255 + 1;
  v2254->timer = v2273;
  struct StateT * v2257 = v2244->a;
  int * v2258 = v2257->regs;
  int v2259 = v2258[6];
  int v2277 = v2259 & 63;
  v2258[6] = v2277;
  struct StateT * v2261 = v2244->b;
  int * v2262 = v2261->regs;
  int v2263 = v2262[6];
  int v2280 = v2263 & 63;
  v2262[6] = v2280;
  struct StateT2 * v2265 = slot_20(v2244);
  return v2265;
}

struct StateT2 * slot_13(struct StateT2 * v1626) {
  struct StateT * v1627 = v1626->a;
  int v1628 = v1627->timer;
  struct StateT * v1629 = v1626->b;
  int v1630 = v1629->timer;
  bool v1651 = v1628 == v1630;
  squared_assert(v1651);
  squared_assume(v1651);
  struct StateT * v1633 = v1626->a;
  int v1634 = v1633->timer;
  int v1653 = v1634 + 1;
  v1633->timer = v1653;
  struct StateT * v1636 = v1626->b;
  int v1637 = v1636->timer;
  int v1655 = v1637 + 1;
  v1636->timer = v1655;
  struct StateT * v1639 = v1626->a;
  int * v1640 = v1639->regs;
  int v1641 = v1640[10];
  int v1660 = (int)((unsigned int)v1641 >> 16);
  v1640[6] = v1660;
  struct StateT * v1643 = v1626->b;
  int * v1644 = v1643->regs;
  int v1645 = v1644[10];
  int v1663 = (int)((unsigned int)v1645 >> 16);
  v1644[6] = v1663;
  struct StateT2 * v1647 = slot_14(v1626);
  return v1647;
}

struct StateT2 * slot_0(struct StateT2 * v2) {
  struct StateT * v3 = v2->a;
  int v4 = v3->timer;
  struct StateT * v5 = v2->b;
  int v6 = v5->timer;
  bool v25 = v4 == v6;
  squared_assert(v25);
  squared_assume(v25);
  struct StateT * v9 = v2->a;
  int v10 = v9->timer;
  int v27 = v10 + 1;
  v9->timer = v27;
  struct StateT * v12 = v2->b;
  int v13 = v12->timer;
  int v29 = v13 + 1;
  v12->timer = v29;
  struct StateT * v15 = v2->a;
  int * v16 = v15->regs;
  v16[5] = 0;
  struct StateT * v18 = v2->b;
  int * v19 = v18->regs;
  v19[5] = 0;
  struct StateT2 * v21 = slot_1(v2);
  return v21;
}

struct StateT2 * slot_14(struct StateT2 * v1666) {
  struct StateT * v1667 = v1666->a;
  int v1668 = v1667->timer;
  struct StateT * v1669 = v1666->b;
  int v1670 = v1669->timer;
  bool v1691 = v1668 == v1670;
  squared_assert(v1691);
  squared_assume(v1691);
  struct StateT * v1673 = v1666->a;
  int v1674 = v1673->timer;
  int v1693 = v1674 + 1;
  v1673->timer = v1693;
  struct StateT * v1676 = v1666->b;
  int v1677 = v1676->timer;
  int v1695 = v1677 + 1;
  v1676->timer = v1695;
  struct StateT * v1679 = v1666->a;
  int * v1680 = v1679->regs;
  int v1681 = v1680[6];
  int v1699 = v1681 & 63;
  v1680[6] = v1699;
  struct StateT * v1683 = v1666->b;
  int * v1684 = v1683->regs;
  int v1685 = v1684[6];
  int v1702 = v1685 & 63;
  v1684[6] = v1702;
  struct StateT2 * v1687 = slot_15(v1666);
  return v1687;
}

struct StateT2 * slot_17(struct StateT2 * v2162) {
  struct StateT * v2163 = v2162->a;
  int v2164 = v2163->timer;
  struct StateT * v2165 = v2162->b;
  int v2166 = v2165->timer;
  bool v2189 = v2164 == v2166;
  squared_assert(v2189);
  squared_assume(v2189);
  struct StateT * v2169 = v2162->a;
  int v2170 = v2169->timer;
  int v2191 = v2170 + 1;
  v2169->timer = v2191;
  struct StateT * v2172 = v2162->b;
  int v2173 = v2172->timer;
  int v2193 = v2173 + 1;
  v2172->timer = v2193;
  struct StateT * v2175 = v2162->a;
  int * v2176 = v2175->regs;
  int v2177 = v2176[5];
  int v2178 = v2176[7];
  int v2198 = v2177 ^ v2178;
  v2176[5] = v2198;
  struct StateT * v2180 = v2162->b;
  int * v2181 = v2180->regs;
  int v2182 = v2181[5];
  int v2183 = v2181[7];
  int v2201 = v2182 ^ v2183;
  v2181[5] = v2201;
  struct StateT2 * v2185 = slot_18(v2162);
  return v2185;
}

struct StateT2 * slot_20(struct StateT2 * v2283) {
  struct StateT * v2284 = v2283->a;
  int v2285 = v2284->timer;
  struct StateT * v2286 = v2283->b;
  int v2287 = v2286->timer;
  bool v2308 = v2285 == v2287;
  squared_assert(v2308);
  squared_assume(v2308);
  struct StateT * v2290 = v2283->a;
  int v2291 = v2290->timer;
  int v2310 = v2291 + 1;
  v2290->timer = v2310;
  struct StateT * v2293 = v2283->b;
  int v2294 = v2293->timer;
  int v2312 = v2294 + 1;
  v2293->timer = v2312;
  struct StateT * v2296 = v2283->a;
  int * v2297 = v2296->regs;
  int v2298 = v2297[6];
  int v2316 = v2298 << 2;
  v2297[6] = v2316;
  struct StateT * v2300 = v2283->b;
  int * v2301 = v2300->regs;
  int v2302 = v2301[6];
  int v2319 = v2302 << 2;
  v2301[6] = v2319;
  struct StateT2 * v2304 = slot_21(v2283);
  return v2304;
}

struct StateT2 * snippet(struct StateT2 * v0) {
  struct StateT2 * v1 = slot_0(v0);
  return v1;
}

struct StateT2 * slot_8(struct StateT2 * v1048) {
  struct StateT * v1049 = v1048->a;
  int v1050 = v1049->timer;
  struct StateT * v1051 = v1048->b;
  int v1052 = v1051->timer;
  bool v1073 = v1050 == v1052;
  squared_assert(v1073);
  squared_assume(v1073);
  struct StateT * v1055 = v1048->a;
  int v1056 = v1055->timer;
  int v1075 = v1056 + 1;
  v1055->timer = v1075;
  struct StateT * v1058 = v1048->b;
  int v1059 = v1058->timer;
  int v1077 = v1059 + 1;
  v1058->timer = v1077;
  struct StateT * v1061 = v1048->a;
  int * v1062 = v1061->regs;
  int v1063 = v1062[10];
  int v1082 = (int)((unsigned int)v1063 >> 8);
  v1062[6] = v1082;
  struct StateT * v1065 = v1048->b;
  int * v1066 = v1065->regs;
  int v1067 = v1066[10];
  int v1085 = (int)((unsigned int)v1067 >> 8);
  v1066[6] = v1085;
  struct StateT2 * v1069 = slot_9(v1048);
  return v1069;
}

struct StateT2 * slot_4(struct StateT2 * v510) {
  struct StateT * v511 = v510->a;
  int v512 = v511->timer;
  struct StateT * v513 = v510->b;
  int v514 = v513->timer;
  bool v535 = v512 == v514;
  squared_assert(v535);
  squared_assume(v535);
  struct StateT * v517 = v510->a;
  int v518 = v517->timer;
  int v537 = v518 + 1;
  v517->timer = v537;
  struct StateT * v520 = v510->b;
  int v521 = v520->timer;
  int v539 = v521 + 1;
  v520->timer = v539;
  struct StateT * v523 = v510->a;
  int * v524 = v523->regs;
  int v525 = v524[6];
  int v543 = v525 & 63;
  v524[6] = v543;
  struct StateT * v527 = v510->b;
  int * v528 = v527->regs;
  int v529 = v528[6];
  int v546 = v529 & 63;
  v528[6] = v546;
  struct StateT2 * v531 = slot_5(v510);
  return v531;
}

struct StateT2 * slot_15(struct StateT2 * v1705) {
  struct StateT * v1706 = v1705->a;
  int v1707 = v1706->timer;
  struct StateT * v1708 = v1705->b;
  int v1709 = v1708->timer;
  bool v1730 = v1707 == v1709;
  squared_assert(v1730);
  squared_assume(v1730);
  struct StateT * v1712 = v1705->a;
  int v1713 = v1712->timer;
  int v1732 = v1713 + 1;
  v1712->timer = v1732;
  struct StateT * v1715 = v1705->b;
  int v1716 = v1715->timer;
  int v1734 = v1716 + 1;
  v1715->timer = v1734;
  struct StateT * v1718 = v1705->a;
  int * v1719 = v1718->regs;
  int v1720 = v1719[6];
  int v1738 = v1720 << 2;
  v1719[6] = v1738;
  struct StateT * v1722 = v1705->b;
  int * v1723 = v1722->regs;
  int v1724 = v1723[6];
  int v1741 = v1724 << 2;
  v1723[6] = v1741;
  struct StateT2 * v1726 = slot_16(v1705);
  return v1726;
}

struct StateT2 * slot_18(struct StateT2 * v2204) {
  struct StateT * v2205 = v2204->a;
  int v2206 = v2205->timer;
  struct StateT * v2207 = v2204->b;
  int v2208 = v2207->timer;
  bool v2229 = v2206 == v2208;
  squared_assert(v2229);
  squared_assume(v2229);
  struct StateT * v2211 = v2204->a;
  int v2212 = v2211->timer;
  int v2231 = v2212 + 1;
  v2211->timer = v2231;
  struct StateT * v2214 = v2204->b;
  int v2215 = v2214->timer;
  int v2233 = v2215 + 1;
  v2214->timer = v2233;
  struct StateT * v2217 = v2204->a;
  int * v2218 = v2217->regs;
  int v2219 = v2218[10];
  int v2238 = (int)((unsigned int)v2219 >> 24);
  v2218[6] = v2238;
  struct StateT * v2221 = v2204->b;
  int * v2222 = v2221->regs;
  int v2223 = v2222[10];
  int v2241 = (int)((unsigned int)v2223 >> 24);
  v2222[6] = v2241;
  struct StateT2 * v2225 = slot_19(v2204);
  return v2225;
}

struct StateT2 * slot_9(struct StateT2 * v1088) {
  struct StateT * v1089 = v1088->a;
  int v1090 = v1089->timer;
  struct StateT * v1091 = v1088->b;
  int v1092 = v1091->timer;
  bool v1113 = v1090 == v1092;
  squared_assert(v1113);
  squared_assume(v1113);
  struct StateT * v1095 = v1088->a;
  int v1096 = v1095->timer;
  int v1115 = v1096 + 1;
  v1095->timer = v1115;
  struct StateT * v1098 = v1088->b;
  int v1099 = v1098->timer;
  int v1117 = v1099 + 1;
  v1098->timer = v1117;
  struct StateT * v1101 = v1088->a;
  int * v1102 = v1101->regs;
  int v1103 = v1102[6];
  int v1121 = v1103 & 63;
  v1102[6] = v1121;
  struct StateT * v1105 = v1088->b;
  int * v1106 = v1105->regs;
  int v1107 = v1106[6];
  int v1124 = v1107 & 63;
  v1106[6] = v1124;
  struct StateT2 * v1109 = slot_10(v1088);
  return v1109;
}

struct StateT2 * slot_22(struct StateT2 * v2740) {
  struct StateT * v2741 = v2740->a;
  int v2742 = v2741->timer;
  struct StateT * v2743 = v2740->b;
  int v2744 = v2743->timer;
  bool v2766 = v2742 == v2744;
  squared_assert(v2766);
  squared_assume(v2766);
  struct StateT * v2747 = v2740->a;
  int v2748 = v2747->timer;
  int v2768 = v2748 + 1;
  v2747->timer = v2768;
  struct StateT * v2750 = v2740->b;
  int v2751 = v2750->timer;
  int v2770 = v2751 + 1;
  v2750->timer = v2770;
  struct StateT * v2753 = v2740->a;
  int * v2754 = v2753->regs;
  int v2755 = v2754[5];
  int v2756 = v2754[7];
  int v2775 = v2755 ^ v2756;
  v2754[5] = v2775;
  struct StateT * v2758 = v2740->b;
  int * v2759 = v2758->regs;
  int v2760 = v2759[5];
  int v2761 = v2759[7];
  int v2778 = v2760 ^ v2761;
  v2759[5] = v2778;
  return v2740;
}

struct StateT2 * slot_11(struct StateT2 * v1166) {
  struct StateT * v1167 = v1166->a;
  int v1168 = v1167->timer;
  struct StateT * v1169 = v1166->b;
  int v1170 = v1169->timer;
  bool v1397 = v1168 == v1170;
  squared_assert(v1397);
  squared_assume(v1397);
  struct StateT * v1173 = v1166->a;
  int v1174 = v1173->timer;
  int v1399 = v1174 + 1;
  v1173->timer = v1399;
  struct StateT * v1176 = v1166->b;
  int v1177 = v1176->timer;
  int v1401 = v1177 + 1;
  v1176->timer = v1401;
  struct StateT * v1179 = v1166->a;
  int * v1180 = v1179->regs;
  int v1181 = v1180[6];
  int * v1182 = v1179->cache_tags;
  int v1406 = (((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 1) * 2;
  int v1183 = v1182[v1406];
  int v1407 = ((((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1184 = v1182[v1407];
  int v1408 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 3) * 2);
  int v1185 = v1182[v1408];
  int v1409 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1186 = v1182[v1409];
  int v1187 = v1179->timer;
  int v1410 = v1187 + ((100 ^ (((~(((v1185 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))) | (-(v1185 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))))) >> 31)) | (~(((v1186 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))) | (-(v1186 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1183 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))) | (-(v1183 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))))) >> 31)) | (~(((v1184 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))) | (-(v1184 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1185 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))) | (-(v1185 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))))) >> 31)) | (~(((v1186 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))) | (-(v1186 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1179->timer = v1410;
  int * v1189 = v1179->cache_vals;
  bool v1411 = !(((~(((v1183 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))) | (-(v1183 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))))) >> 31)) | (~(((v1184 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))) | (-(v1184 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))))) >> 31))) == 0);
  int v1282;
  if (v1411) {
    int * v1190 = v1179->cache_age;
    int v1413 = ((((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 1) * 2) + ((~(((v1184 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))) | (-(v1184 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))))) >> 31)) & 1);
    int v1191 = v1190[v1413];
    int v1192 = v1190[v1406];
    int v1414 = v1192 + ((int)((unsigned int)(v1192 - v1191) >> 31));
    v1190[v1406] = v1414;
    int * v1194 = v1179->cache_age;
    int v1195 = v1194[v1407];
    int v1416 = v1195 + ((int)((unsigned int)(v1195 - v1191) >> 31));
    v1194[v1407] = v1416;
    int * v1197 = v1179->cache_age;
    v1197[v1413] = 0;
    v1282 = v1413;
  } else {
    int * v1200 = v1179->cache_age;
    int v1420 = (((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 1) * 2;
    int v1201 = v1200[v1420];
    int * v1202 = v1179->cache_tags;
    int v1203 = v1202[v1420];
    int v1204 = v1200[v1407];
    int v1205 = v1202[v1407];
    bool v1422 = !(((~(((v1185 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))) | (-(v1185 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))))) >> 31)) | (~(((v1186 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))) | (-(v1186 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))))) >> 31))) == 0);
    int v1259;
    if (v1422) {
      int * v1206 = v1179->cache_age;
      int v1424 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1186 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))) | (-(v1186 ^ ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1))))) >> 31)) & 1);
      int v1207 = v1206[v1424];
      int v1208 = v1206[v1408];
      int v1425 = v1208 + ((int)((unsigned int)(v1208 - v1207) >> 31));
      v1206[v1408] = v1425;
      int * v1210 = v1179->cache_age;
      int v1211 = v1210[v1409];
      int v1427 = v1211 + ((int)((unsigned int)(v1211 - v1207) >> 31));
      v1210[v1409] = v1427;
      int * v1213 = v1179->cache_age;
      v1213[v1424] = 0;
      v1259 = v1424;
    } else {
      int * v1216 = v1179->cache_age;
      int v1431 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 3) * 2);
      int v1217 = v1216[v1431];
      int * v1218 = v1179->cache_tags;
      int v1219 = v1218[v1431];
      int v1220 = v1216[v1409];
      int v1221 = v1218[v1409];
      int * v1222 = v1179->cache_dirty;
      int v1434 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 3) * 2)) + ((((v1217 + ((~(((v1219 ^ -1) | (-(v1219 ^ -1))) >> 31)) & 2)) - (v1220 + ((~(((v1221 ^ -1) | (-(v1221 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1223 = v1222[v1434];
      bool v1435 = !(v1223 == 0);
      if (v1435) {
        int * v1224 = v1179->cache_tags;
        int v1225 = v1224[v1434];
        int * v1226 = v1179->cache_vals;
        int v1438 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 3) * 2)) + ((((v1217 + ((~(((v1219 ^ -1) | (-(v1219 ^ -1))) >> 31)) & 2)) - (v1220 + ((~(((v1221 ^ -1) | (-(v1221 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1227 = v1226[v1438];
        int v1439 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 3) * 2)) + ((((v1217 + ((~(((v1219 ^ -1) | (-(v1219 ^ -1))) >> 31)) & 2)) - (v1220 + ((~(((v1221 ^ -1) | (-(v1221 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1228 = v1226[v1439];
        int * v1229 = v1179->mem;
        int v1441 = v1225 * 2;
        v1229[v1441] = v1227;
        int * v1231 = v1179->mem;
        int v1444 = (v1225 * 2) + 1;
        v1231[v1444] = v1228;
        ;
      } else {
        ;
      }
      int * v1236 = v1179->mem;
      int v1449 = ((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) * 2;
      int v1237 = v1236[v1449];
      int v1450 = (((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) * 2) + 1;
      int v1238 = v1236[v1450];
      int * v1239 = v1179->cache_vals;
      int v1452 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 3) * 2)) + ((((v1217 + ((~(((v1219 ^ -1) | (-(v1219 ^ -1))) >> 31)) & 2)) - (v1220 + ((~(((v1221 ^ -1) | (-(v1221 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1239[v1452] = v1237;
      int * v1241 = v1179->cache_vals;
      int v1455 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 3) * 2)) + ((((v1217 + ((~(((v1219 ^ -1) | (-(v1219 ^ -1))) >> 31)) & 2)) - (v1220 + ((~(((v1221 ^ -1) | (-(v1221 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1241[v1455] = v1238;
      int * v1243 = v1179->cache_tags;
      int v1458 = (int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1);
      v1243[v1434] = v1458;
      int * v1245 = v1179->cache_dirty;
      v1245[v1434] = 0;
      int * v1247 = v1179->cache_age;
      v1247[v1434] = 1;
      int * v1249 = v1179->cache_age;
      int v1250 = v1249[v1434];
      int v1251 = v1249[v1408];
      int v1464 = v1251 + ((int)((unsigned int)(v1251 - v1250) >> 31));
      v1249[v1408] = v1464;
      int * v1253 = v1179->cache_age;
      int v1254 = v1253[v1409];
      int v1466 = v1254 + ((int)((unsigned int)(v1254 - v1250) >> 31));
      v1253[v1409] = v1466;
      int * v1256 = v1179->cache_age;
      v1256[v1434] = 0;
      v1259 = v1434;
    }
    int * v1260 = v1179->cache_vals;
    int v1469 = v1259 * 2;
    int v1261 = v1260[v1469];
    int v1470 = (v1259 * 2) + 1;
    int v1262 = v1260[v1470];
    int v1471 = (((((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 1) * 2) + ((((v1201 + ((~(((v1203 ^ -1) | (-(v1203 ^ -1))) >> 31)) & 2)) - (v1204 + ((~(((v1205 ^ -1) | (-(v1205 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1260[v1471] = v1261;
    int * v1264 = v1179->cache_vals;
    int v1474 = ((((((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 1) * 2) + ((((v1201 + ((~(((v1203 ^ -1) | (-(v1203 ^ -1))) >> 31)) & 2)) - (v1204 + ((~(((v1205 ^ -1) | (-(v1205 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1264[v1474] = v1262;
    int * v1266 = v1179->cache_tags;
    int v1477 = ((((int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1)) & 1) * 2) + ((((v1201 + ((~(((v1203 ^ -1) | (-(v1203 ^ -1))) >> 31)) & 2)) - (v1204 + ((~(((v1205 ^ -1) | (-(v1205 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1478 = (int)((unsigned int)((int)((unsigned int)v1181 >> 2)) >> 1);
    v1266[v1477] = v1478;
    int * v1268 = v1179->cache_dirty;
    v1268[v1477] = 0;
    int * v1270 = v1179->cache_age;
    v1270[v1477] = 1;
    int * v1272 = v1179->cache_age;
    int v1273 = v1272[v1477];
    int v1274 = v1272[v1406];
    int v1484 = v1274 + ((int)((unsigned int)(v1274 - v1273) >> 31));
    v1272[v1406] = v1484;
    int * v1276 = v1179->cache_age;
    int v1277 = v1276[v1407];
    int v1486 = v1277 + ((int)((unsigned int)(v1277 - v1273) >> 31));
    v1276[v1407] = v1486;
    int * v1279 = v1179->cache_age;
    v1279[v1477] = 0;
    v1282 = v1477;
  }
  int v1489 = (v1282 * 2) + (((int)((unsigned int)v1181 >> 2)) & 1);
  int v1283 = v1189[v1489];
  int * v1284 = v1179->regs;
  v1284[7] = v1283;
  struct StateT * v1286 = v1166->b;
  int * v1287 = v1286->regs;
  int v1288 = v1287[6];
  int * v1289 = v1286->cache_tags;
  int v1496 = (((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1)) & 1) * 2;
  int v1290 = v1289[v1496];
  int v1497 = ((((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1)) & 1) * 2) + 1;
  int v1291 = v1289[v1497];
  int v1498 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1)) & 3) * 2);
  int v1292 = v1289[v1498];
  int v1499 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1293 = v1289[v1499];
  int v1294 = v1286->timer;
  int v1500 = v1294 + ((100 ^ (((~(((v1292 ^ ((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1))) | (-(v1292 ^ ((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1))))) >> 31)) | (~(((v1293 ^ ((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1))) | (-(v1293 ^ ((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1290 ^ ((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1))) | (-(v1290 ^ ((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1))))) >> 31)) | (~(((v1291 ^ ((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1))) | (-(v1291 ^ ((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1292 ^ ((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1))) | (-(v1292 ^ ((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1))))) >> 31)) | (~(((v1293 ^ ((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1))) | (-(v1293 ^ ((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1))))) >> 31))) & 104)))));
  v1286->timer = v1500;
  int * v1296 = v1286->cache_vals;
  bool v1501 = !(((~(((v1290 ^ ((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1))) | (-(v1290 ^ ((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1))))) >> 31)) | (~(((v1291 ^ ((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1))) | (-(v1291 ^ ((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1))))) >> 31))) == 0);
  int v1389;
  if (v1501) {
    int * v1297 = v1286->cache_age;
    int v1503 = ((((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1)) & 1) * 2) + ((~(((v1291 ^ ((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1))) | (-(v1291 ^ ((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1))))) >> 31)) & 1);
    int v1298 = v1297[v1503];
    int v1299 = v1297[v1496];
    int v1504 = v1299 + ((int)((unsigned int)(v1299 - v1298) >> 31));
    v1297[v1496] = v1504;
    int * v1301 = v1286->cache_age;
    int v1302 = v1301[v1497];
    int v1506 = v1302 + ((int)((unsigned int)(v1302 - v1298) >> 31));
    v1301[v1497] = v1506;
    int * v1304 = v1286->cache_age;
    v1304[v1503] = 0;
    v1389 = v1503;
  } else {
    int * v1307 = v1286->cache_age;
    int v1510 = (((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1)) & 1) * 2;
    int v1308 = v1307[v1510];
    int * v1309 = v1286->cache_tags;
    int v1310 = v1309[v1510];
    int v1311 = v1307[v1497];
    int v1312 = v1309[v1497];
    bool v1512 = !(((~(((v1292 ^ ((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1))) | (-(v1292 ^ ((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1))))) >> 31)) | (~(((v1293 ^ ((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1))) | (-(v1293 ^ ((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1))))) >> 31))) == 0);
    int v1366;
    if (v1512) {
      int * v1313 = v1286->cache_age;
      int v1514 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1)) & 3) * 2)) + ((~(((v1293 ^ ((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1))) | (-(v1293 ^ ((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1))))) >> 31)) & 1);
      int v1314 = v1313[v1514];
      int v1315 = v1313[v1498];
      int v1515 = v1315 + ((int)((unsigned int)(v1315 - v1314) >> 31));
      v1313[v1498] = v1515;
      int * v1317 = v1286->cache_age;
      int v1318 = v1317[v1499];
      int v1517 = v1318 + ((int)((unsigned int)(v1318 - v1314) >> 31));
      v1317[v1499] = v1517;
      int * v1320 = v1286->cache_age;
      v1320[v1514] = 0;
      v1366 = v1514;
    } else {
      int * v1323 = v1286->cache_age;
      int v1521 = 4 + ((((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1)) & 3) * 2);
      int v1324 = v1323[v1521];
      int * v1325 = v1286->cache_tags;
      int v1326 = v1325[v1521];
      int v1327 = v1323[v1499];
      int v1328 = v1325[v1499];
      int * v1329 = v1286->cache_dirty;
      int v1524 = (4 + ((((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1)) & 3) * 2)) + ((((v1324 + ((~(((v1326 ^ -1) | (-(v1326 ^ -1))) >> 31)) & 2)) - (v1327 + ((~(((v1328 ^ -1) | (-(v1328 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1330 = v1329[v1524];
      bool v1525 = !(v1330 == 0);
      if (v1525) {
        int * v1331 = v1286->cache_tags;
        int v1332 = v1331[v1524];
        int * v1333 = v1286->cache_vals;
        int v1528 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1)) & 3) * 2)) + ((((v1324 + ((~(((v1326 ^ -1) | (-(v1326 ^ -1))) >> 31)) & 2)) - (v1327 + ((~(((v1328 ^ -1) | (-(v1328 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1334 = v1333[v1528];
        int v1529 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1)) & 3) * 2)) + ((((v1324 + ((~(((v1326 ^ -1) | (-(v1326 ^ -1))) >> 31)) & 2)) - (v1327 + ((~(((v1328 ^ -1) | (-(v1328 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1335 = v1333[v1529];
        int * v1336 = v1286->mem;
        int v1531 = v1332 * 2;
        v1336[v1531] = v1334;
        int * v1338 = v1286->mem;
        int v1534 = (v1332 * 2) + 1;
        v1338[v1534] = v1335;
        ;
      } else {
        ;
      }
      int * v1343 = v1286->mem;
      int v1539 = ((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1)) * 2;
      int v1344 = v1343[v1539];
      int v1540 = (((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1)) * 2) + 1;
      int v1345 = v1343[v1540];
      int * v1346 = v1286->cache_vals;
      int v1542 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1)) & 3) * 2)) + ((((v1324 + ((~(((v1326 ^ -1) | (-(v1326 ^ -1))) >> 31)) & 2)) - (v1327 + ((~(((v1328 ^ -1) | (-(v1328 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1346[v1542] = v1344;
      int * v1348 = v1286->cache_vals;
      int v1545 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1)) & 3) * 2)) + ((((v1324 + ((~(((v1326 ^ -1) | (-(v1326 ^ -1))) >> 31)) & 2)) - (v1327 + ((~(((v1328 ^ -1) | (-(v1328 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1348[v1545] = v1345;
      int * v1350 = v1286->cache_tags;
      int v1548 = (int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1);
      v1350[v1524] = v1548;
      int * v1352 = v1286->cache_dirty;
      v1352[v1524] = 0;
      int * v1354 = v1286->cache_age;
      v1354[v1524] = 1;
      int * v1356 = v1286->cache_age;
      int v1357 = v1356[v1524];
      int v1358 = v1356[v1498];
      int v1554 = v1358 + ((int)((unsigned int)(v1358 - v1357) >> 31));
      v1356[v1498] = v1554;
      int * v1360 = v1286->cache_age;
      int v1361 = v1360[v1499];
      int v1556 = v1361 + ((int)((unsigned int)(v1361 - v1357) >> 31));
      v1360[v1499] = v1556;
      int * v1363 = v1286->cache_age;
      v1363[v1524] = 0;
      v1366 = v1524;
    }
    int * v1367 = v1286->cache_vals;
    int v1559 = v1366 * 2;
    int v1368 = v1367[v1559];
    int v1560 = (v1366 * 2) + 1;
    int v1369 = v1367[v1560];
    int v1561 = (((((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1)) & 1) * 2) + ((((v1308 + ((~(((v1310 ^ -1) | (-(v1310 ^ -1))) >> 31)) & 2)) - (v1311 + ((~(((v1312 ^ -1) | (-(v1312 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1367[v1561] = v1368;
    int * v1371 = v1286->cache_vals;
    int v1564 = ((((((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1)) & 1) * 2) + ((((v1308 + ((~(((v1310 ^ -1) | (-(v1310 ^ -1))) >> 31)) & 2)) - (v1311 + ((~(((v1312 ^ -1) | (-(v1312 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1371[v1564] = v1369;
    int * v1373 = v1286->cache_tags;
    int v1567 = ((((int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1)) & 1) * 2) + ((((v1308 + ((~(((v1310 ^ -1) | (-(v1310 ^ -1))) >> 31)) & 2)) - (v1311 + ((~(((v1312 ^ -1) | (-(v1312 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1568 = (int)((unsigned int)((int)((unsigned int)v1288 >> 2)) >> 1);
    v1373[v1567] = v1568;
    int * v1375 = v1286->cache_dirty;
    v1375[v1567] = 0;
    int * v1377 = v1286->cache_age;
    v1377[v1567] = 1;
    int * v1379 = v1286->cache_age;
    int v1380 = v1379[v1567];
    int v1381 = v1379[v1496];
    int v1574 = v1381 + ((int)((unsigned int)(v1381 - v1380) >> 31));
    v1379[v1496] = v1574;
    int * v1383 = v1286->cache_age;
    int v1384 = v1383[v1497];
    int v1576 = v1384 + ((int)((unsigned int)(v1384 - v1380) >> 31));
    v1383[v1497] = v1576;
    int * v1386 = v1286->cache_age;
    v1386[v1567] = 0;
    v1389 = v1567;
  }
  int v1579 = (v1389 * 2) + (((int)((unsigned int)v1288 >> 2)) & 1);
  int v1390 = v1296[v1579];
  int * v1391 = v1286->regs;
  v1391[7] = v1390;
  struct StateT2 * v1393 = slot_12(v1166);
  return v1393;
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

void squared_assert(bool c) { koika_assert(c, "timer drift"); }
void squared_diverged(bool c) { koika_assert(c, "control flow diverged"); }
void squared_assume(bool c) { koika_assume(c); }

int main(int argc, char* argv[]) {
  struct StateT s1, s2;
  init(&s1);
  init(&s2);
  
  // the indices, public: one draw into both states
  int i10 = bounded(0, 1073741823);
  s1.regs[10] = i10;
  s2.regs[10] = i10;
  
  // initialize secret
  for (int i=0; i<SECRET_SIZE; i++) {
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateT2 p = { .a = &s1, .b = &s2 };
  struct StateT2 *p_ = snippet(&p);
  //@ assert untainted_timer: !\tainted(p_->a->timer==p_->b->timer);
  koika_assert(p_->a->timer==p_->b->timer, "timing leak");
  return 0;
}