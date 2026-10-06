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
struct StateT * slot_1(struct StateT * v24);
struct StateT * slot_6(struct StateT * v609);
struct StateT * slot_5(struct StateT * v588);
struct StateT * slot_4(struct StateT * v380);
struct StateT * slot_2(struct StateT * v45);
struct StateT * slot_3(struct StateT * v61);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v814 = v1->timer;
  int * v815 = v1->reg_ready;
  int v816 = v815[0];
  int v947 = v816 + ((v814 - v816) & (~((v814 - v816) >> 31)));
  v1->timer = v947;
  int v818 = v1->timer;
  int * v819 = v1->reg_ready;
  int v820 = v819[1];
  int v950 = v820 + ((v818 - v820) & (~((v818 - v820) >> 31)));
  v1->timer = v950;
  int v822 = v1->timer;
  int * v823 = v1->reg_ready;
  int v824 = v823[2];
  int v953 = v824 + ((v822 - v824) & (~((v822 - v824) >> 31)));
  v1->timer = v953;
  int v826 = v1->timer;
  int * v827 = v1->reg_ready;
  int v828 = v827[3];
  int v956 = v828 + ((v826 - v828) & (~((v826 - v828) >> 31)));
  v1->timer = v956;
  int v830 = v1->timer;
  int * v831 = v1->reg_ready;
  int v832 = v831[4];
  int v959 = v832 + ((v830 - v832) & (~((v830 - v832) >> 31)));
  v1->timer = v959;
  int v834 = v1->timer;
  int * v835 = v1->reg_ready;
  int v836 = v835[5];
  int v962 = v836 + ((v834 - v836) & (~((v834 - v836) >> 31)));
  v1->timer = v962;
  int v838 = v1->timer;
  int * v839 = v1->reg_ready;
  int v840 = v839[6];
  int v965 = v840 + ((v838 - v840) & (~((v838 - v840) >> 31)));
  v1->timer = v965;
  int v842 = v1->timer;
  int * v843 = v1->reg_ready;
  int v844 = v843[7];
  int v968 = v844 + ((v842 - v844) & (~((v842 - v844) >> 31)));
  v1->timer = v968;
  int v846 = v1->timer;
  int * v847 = v1->reg_ready;
  int v848 = v847[8];
  int v971 = v848 + ((v846 - v848) & (~((v846 - v848) >> 31)));
  v1->timer = v971;
  int v850 = v1->timer;
  int * v851 = v1->reg_ready;
  int v852 = v851[9];
  int v974 = v852 + ((v850 - v852) & (~((v850 - v852) >> 31)));
  v1->timer = v974;
  int v854 = v1->timer;
  int * v855 = v1->reg_ready;
  int v856 = v855[10];
  int v977 = v856 + ((v854 - v856) & (~((v854 - v856) >> 31)));
  v1->timer = v977;
  int v858 = v1->timer;
  int * v859 = v1->reg_ready;
  int v860 = v859[11];
  int v980 = v860 + ((v858 - v860) & (~((v858 - v860) >> 31)));
  v1->timer = v980;
  int v862 = v1->timer;
  int * v863 = v1->reg_ready;
  int v864 = v863[12];
  int v983 = v864 + ((v862 - v864) & (~((v862 - v864) >> 31)));
  v1->timer = v983;
  int v866 = v1->timer;
  int * v867 = v1->reg_ready;
  int v868 = v867[13];
  int v986 = v868 + ((v866 - v868) & (~((v866 - v868) >> 31)));
  v1->timer = v986;
  int v870 = v1->timer;
  int * v871 = v1->reg_ready;
  int v872 = v871[14];
  int v989 = v872 + ((v870 - v872) & (~((v870 - v872) >> 31)));
  v1->timer = v989;
  int v874 = v1->timer;
  int * v875 = v1->reg_ready;
  int v876 = v875[15];
  int v992 = v876 + ((v874 - v876) & (~((v874 - v876) >> 31)));
  v1->timer = v992;
  int v878 = v1->timer;
  int * v879 = v1->reg_ready;
  int v880 = v879[16];
  int v995 = v880 + ((v878 - v880) & (~((v878 - v880) >> 31)));
  v1->timer = v995;
  int v882 = v1->timer;
  int * v883 = v1->reg_ready;
  int v884 = v883[17];
  int v998 = v884 + ((v882 - v884) & (~((v882 - v884) >> 31)));
  v1->timer = v998;
  int v886 = v1->timer;
  int * v887 = v1->reg_ready;
  int v888 = v887[18];
  int v1001 = v888 + ((v886 - v888) & (~((v886 - v888) >> 31)));
  v1->timer = v1001;
  int v890 = v1->timer;
  int * v891 = v1->reg_ready;
  int v892 = v891[19];
  int v1004 = v892 + ((v890 - v892) & (~((v890 - v892) >> 31)));
  v1->timer = v1004;
  int v894 = v1->timer;
  int * v895 = v1->reg_ready;
  int v896 = v895[20];
  int v1007 = v896 + ((v894 - v896) & (~((v894 - v896) >> 31)));
  v1->timer = v1007;
  int v898 = v1->timer;
  int * v899 = v1->reg_ready;
  int v900 = v899[21];
  int v1010 = v900 + ((v898 - v900) & (~((v898 - v900) >> 31)));
  v1->timer = v1010;
  int v902 = v1->timer;
  int * v903 = v1->reg_ready;
  int v904 = v903[22];
  int v1013 = v904 + ((v902 - v904) & (~((v902 - v904) >> 31)));
  v1->timer = v1013;
  int v906 = v1->timer;
  int * v907 = v1->reg_ready;
  int v908 = v907[23];
  int v1016 = v908 + ((v906 - v908) & (~((v906 - v908) >> 31)));
  v1->timer = v1016;
  int v910 = v1->timer;
  int * v911 = v1->reg_ready;
  int v912 = v911[24];
  int v1019 = v912 + ((v910 - v912) & (~((v910 - v912) >> 31)));
  v1->timer = v1019;
  int v914 = v1->timer;
  int * v915 = v1->reg_ready;
  int v916 = v915[25];
  int v1022 = v916 + ((v914 - v916) & (~((v914 - v916) >> 31)));
  v1->timer = v1022;
  int v918 = v1->timer;
  int * v919 = v1->reg_ready;
  int v920 = v919[26];
  int v1025 = v920 + ((v918 - v920) & (~((v918 - v920) >> 31)));
  v1->timer = v1025;
  int v922 = v1->timer;
  int * v923 = v1->reg_ready;
  int v924 = v923[27];
  int v1028 = v924 + ((v922 - v924) & (~((v922 - v924) >> 31)));
  v1->timer = v1028;
  int v926 = v1->timer;
  int * v927 = v1->reg_ready;
  int v928 = v927[28];
  int v1031 = v928 + ((v926 - v928) & (~((v926 - v928) >> 31)));
  v1->timer = v1031;
  int v930 = v1->timer;
  int * v931 = v1->reg_ready;
  int v932 = v931[29];
  int v1034 = v932 + ((v930 - v932) & (~((v930 - v932) >> 31)));
  v1->timer = v1034;
  int v934 = v1->timer;
  int * v935 = v1->reg_ready;
  int v936 = v935[30];
  int v1037 = v936 + ((v934 - v936) & (~((v934 - v936) >> 31)));
  v1->timer = v1037;
  int v938 = v1->timer;
  int * v939 = v1->reg_ready;
  int v940 = v939[31];
  int v1040 = v940 + ((v938 - v940) & (~((v938 - v940) >> 31)));
  v1->timer = v1040;
  return v1;
}

struct StateT * slot_1(struct StateT * v24) {
  int v25 = v24->timer;
  int v36 = v25 + 1;
  v24->timer = v36;
  int * v27 = v24->reg_ready;
  int v28 = v27[6];
  int * v29 = v24->regs;
  int v30 = v29[6];
  int v40 = (v28 + ((v25 - v28) & (~((v25 - v28) >> 31)))) + 1;
  v27[6] = v40;
  int * v32 = v24->regs;
  int v42 = v30 + 80;
  v32[6] = v42;
  struct StateT * v34 = slot_2(v24);
  return v34;
}

struct StateT * slot_6(struct StateT * v609) {
  int v610 = v609->timer;
  int v721 = v610 + 1;
  v609->timer = v721;
  int * v612 = v609->reg_ready;
  int v613 = v612[6];
  int * v614 = v609->regs;
  int v615 = v614[6];
  int * v616 = v609->cache_tags;
  int v726 = (((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1)) & 1) * 2;
  int v617 = v616[v726];
  int v727 = ((((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1)) & 1) * 2) + 1;
  int v618 = v616[v727];
  int v728 = 4 + ((((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1)) & 3) * 2);
  int v619 = v616[v728];
  int v729 = (4 + ((((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v620 = v616[v729];
  int * v621 = v609->cache_vals;
  bool v730 = !(((~(((v617 ^ ((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1))) | (-(v617 ^ ((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1))))) >> 31)) | (~(((v618 ^ ((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1))) | (-(v618 ^ ((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1))))) >> 31))) == 0);
  int v714;
  if (v730) {
    int * v622 = v609->cache_age;
    int v732 = ((((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1)) & 1) * 2) + ((~(((v618 ^ ((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1))) | (-(v618 ^ ((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1))))) >> 31)) & 1);
    int v623 = v622[v732];
    int v624 = v622[v726];
    int v733 = v624 + ((int)((unsigned int)(v624 - v623) >> 31));
    v622[v726] = v733;
    int * v626 = v609->cache_age;
    int v627 = v626[v727];
    int v735 = v627 + ((int)((unsigned int)(v627 - v623) >> 31));
    v626[v727] = v735;
    int * v629 = v609->cache_age;
    v629[v732] = 0;
    v714 = v732;
  } else {
    int * v632 = v609->cache_age;
    int v739 = (((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1)) & 1) * 2;
    int v633 = v632[v739];
    int * v634 = v609->cache_tags;
    int v635 = v634[v739];
    int v636 = v632[v727];
    int v637 = v634[v727];
    bool v741 = !(((~(((v619 ^ ((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1))) | (-(v619 ^ ((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1))))) >> 31)) | (~(((v620 ^ ((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1))) | (-(v620 ^ ((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1))))) >> 31))) == 0);
    int v691;
    if (v741) {
      int * v638 = v609->cache_age;
      int v743 = (4 + ((((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1)) & 3) * 2)) + ((~(((v620 ^ ((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1))) | (-(v620 ^ ((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1))))) >> 31)) & 1);
      int v639 = v638[v743];
      int v640 = v638[v728];
      int v744 = v640 + ((int)((unsigned int)(v640 - v639) >> 31));
      v638[v728] = v744;
      int * v642 = v609->cache_age;
      int v643 = v642[v729];
      int v746 = v643 + ((int)((unsigned int)(v643 - v639) >> 31));
      v642[v729] = v746;
      int * v645 = v609->cache_age;
      v645[v743] = 0;
      v691 = v743;
    } else {
      int * v648 = v609->cache_age;
      int v750 = 4 + ((((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1)) & 3) * 2);
      int v649 = v648[v750];
      int * v650 = v609->cache_tags;
      int v651 = v650[v750];
      int v652 = v648[v729];
      int v653 = v650[v729];
      int * v654 = v609->cache_dirty;
      int v753 = (4 + ((((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1)) & 3) * 2)) + ((((v649 + ((~(((v651 ^ -1) | (-(v651 ^ -1))) >> 31)) & 2)) - (v652 + ((~(((v653 ^ -1) | (-(v653 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v655 = v654[v753];
      bool v754 = !(v655 == 0);
      if (v754) {
        int * v656 = v609->cache_tags;
        int v657 = v656[v753];
        int * v658 = v609->cache_vals;
        int v757 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1)) & 3) * 2)) + ((((v649 + ((~(((v651 ^ -1) | (-(v651 ^ -1))) >> 31)) & 2)) - (v652 + ((~(((v653 ^ -1) | (-(v653 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v659 = v658[v757];
        int v758 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1)) & 3) * 2)) + ((((v649 + ((~(((v651 ^ -1) | (-(v651 ^ -1))) >> 31)) & 2)) - (v652 + ((~(((v653 ^ -1) | (-(v653 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v660 = v658[v758];
        int * v661 = v609->mem;
        int v760 = v657 * 2;
        v661[v760] = v659;
        int * v663 = v609->mem;
        int v763 = (v657 * 2) + 1;
        v663[v763] = v660;
        ;
      } else {
        ;
      }
      int * v668 = v609->mem;
      int v768 = ((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1)) * 2;
      int v669 = v668[v768];
      int v769 = (((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1)) * 2) + 1;
      int v670 = v668[v769];
      int * v671 = v609->cache_vals;
      int v771 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1)) & 3) * 2)) + ((((v649 + ((~(((v651 ^ -1) | (-(v651 ^ -1))) >> 31)) & 2)) - (v652 + ((~(((v653 ^ -1) | (-(v653 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v671[v771] = v669;
      int * v673 = v609->cache_vals;
      int v774 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1)) & 3) * 2)) + ((((v649 + ((~(((v651 ^ -1) | (-(v651 ^ -1))) >> 31)) & 2)) - (v652 + ((~(((v653 ^ -1) | (-(v653 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v673[v774] = v670;
      int * v675 = v609->cache_tags;
      int v777 = (int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1);
      v675[v753] = v777;
      int * v677 = v609->cache_dirty;
      v677[v753] = 0;
      int * v679 = v609->cache_age;
      v679[v753] = 1;
      int * v681 = v609->cache_age;
      int v682 = v681[v753];
      int v683 = v681[v728];
      int v783 = v683 + ((int)((unsigned int)(v683 - v682) >> 31));
      v681[v728] = v783;
      int * v685 = v609->cache_age;
      int v686 = v685[v729];
      int v785 = v686 + ((int)((unsigned int)(v686 - v682) >> 31));
      v685[v729] = v785;
      int * v688 = v609->cache_age;
      v688[v753] = 0;
      v691 = v753;
    }
    int * v692 = v609->cache_vals;
    int v788 = v691 * 2;
    int v693 = v692[v788];
    int v789 = (v691 * 2) + 1;
    int v694 = v692[v789];
    int v790 = (((((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1)) & 1) * 2) + ((((v633 + ((~(((v635 ^ -1) | (-(v635 ^ -1))) >> 31)) & 2)) - (v636 + ((~(((v637 ^ -1) | (-(v637 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v692[v790] = v693;
    int * v696 = v609->cache_vals;
    int v793 = ((((((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1)) & 1) * 2) + ((((v633 + ((~(((v635 ^ -1) | (-(v635 ^ -1))) >> 31)) & 2)) - (v636 + ((~(((v637 ^ -1) | (-(v637 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v696[v793] = v694;
    int * v698 = v609->cache_tags;
    int v796 = ((((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1)) & 1) * 2) + ((((v633 + ((~(((v635 ^ -1) | (-(v635 ^ -1))) >> 31)) & 2)) - (v636 + ((~(((v637 ^ -1) | (-(v637 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v797 = (int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1);
    v698[v796] = v797;
    int * v700 = v609->cache_dirty;
    v700[v796] = 0;
    int * v702 = v609->cache_age;
    v702[v796] = 1;
    int * v704 = v609->cache_age;
    int v705 = v704[v796];
    int v706 = v704[v726];
    int v803 = v706 + ((int)((unsigned int)(v706 - v705) >> 31));
    v704[v726] = v803;
    int * v708 = v609->cache_age;
    int v709 = v708[v727];
    int v805 = v709 + ((int)((unsigned int)(v709 - v705) >> 31));
    v708[v727] = v805;
    int * v711 = v609->cache_age;
    v711[v796] = 0;
    v714 = v796;
  }
  int v808 = (v714 * 2) + (((int)((unsigned int)v615 >> 2)) & 1);
  int v715 = v621[v808];
  int * v716 = v609->reg_ready;
  int v811 = ((v613 + ((v610 - v613) & (~((v610 - v613) >> 31)))) + 1) + ((100 ^ (((~(((v619 ^ ((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1))) | (-(v619 ^ ((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1))))) >> 31)) | (~(((v620 ^ ((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1))) | (-(v620 ^ ((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v617 ^ ((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1))) | (-(v617 ^ ((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1))))) >> 31)) | (~(((v618 ^ ((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1))) | (-(v618 ^ ((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v619 ^ ((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1))) | (-(v619 ^ ((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1))))) >> 31)) | (~(((v620 ^ ((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1))) | (-(v620 ^ ((int)((unsigned int)((int)((unsigned int)v615 >> 2)) >> 1))))) >> 31))) & 104)))));
  v716[12] = v811;
  int * v718 = v609->regs;
  v718[12] = v715;
  return v609;
}

struct StateT * slot_5(struct StateT * v588) {
  int v589 = v588->timer;
  int v600 = v589 + 1;
  v588->timer = v600;
  int * v591 = v588->reg_ready;
  int v592 = v591[11];
  int * v593 = v588->regs;
  int v594 = v593[11];
  int v604 = (v592 + ((v589 - v592) & (~((v589 - v592) >> 31)))) + 1;
  v591[11] = v604;
  int * v596 = v588->regs;
  int v606 = v594 << 2;
  v596[11] = v606;
  struct StateT * v598 = slot_6(v588);
  return v598;
}

struct StateT * slot_4(struct StateT * v380) {
  int v381 = v380->timer;
  int v493 = v381 + 1;
  v380->timer = v493;
  int * v383 = v380->reg_ready;
  int v384 = v383[6];
  int * v385 = v380->regs;
  int v386 = v385[6];
  int * v387 = v380->cache_tags;
  int v498 = (((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1)) & 1) * 2;
  int v388 = v387[v498];
  int v499 = ((((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1)) & 1) * 2) + 1;
  int v389 = v387[v499];
  int v500 = 4 + ((((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1)) & 3) * 2);
  int v390 = v387[v500];
  int v501 = (4 + ((((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v391 = v387[v501];
  int * v392 = v380->cache_vals;
  bool v502 = !(((~(((v388 ^ ((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1))) | (-(v388 ^ ((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1))))) >> 31)) | (~(((v389 ^ ((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1))) | (-(v389 ^ ((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1))))) >> 31))) == 0);
  int v485;
  if (v502) {
    int * v393 = v380->cache_age;
    int v504 = ((((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1)) & 1) * 2) + ((~(((v389 ^ ((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1))) | (-(v389 ^ ((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1))))) >> 31)) & 1);
    int v394 = v393[v504];
    int v395 = v393[v498];
    int v505 = v395 + ((int)((unsigned int)(v395 - v394) >> 31));
    v393[v498] = v505;
    int * v397 = v380->cache_age;
    int v398 = v397[v499];
    int v507 = v398 + ((int)((unsigned int)(v398 - v394) >> 31));
    v397[v499] = v507;
    int * v400 = v380->cache_age;
    v400[v504] = 0;
    v485 = v504;
  } else {
    int * v403 = v380->cache_age;
    int v511 = (((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1)) & 1) * 2;
    int v404 = v403[v511];
    int * v405 = v380->cache_tags;
    int v406 = v405[v511];
    int v407 = v403[v499];
    int v408 = v405[v499];
    bool v513 = !(((~(((v390 ^ ((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1))) | (-(v390 ^ ((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1))))) >> 31)) | (~(((v391 ^ ((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1))) | (-(v391 ^ ((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1))))) >> 31))) == 0);
    int v462;
    if (v513) {
      int * v409 = v380->cache_age;
      int v515 = (4 + ((((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1)) & 3) * 2)) + ((~(((v391 ^ ((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1))) | (-(v391 ^ ((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1))))) >> 31)) & 1);
      int v410 = v409[v515];
      int v411 = v409[v500];
      int v516 = v411 + ((int)((unsigned int)(v411 - v410) >> 31));
      v409[v500] = v516;
      int * v413 = v380->cache_age;
      int v414 = v413[v501];
      int v518 = v414 + ((int)((unsigned int)(v414 - v410) >> 31));
      v413[v501] = v518;
      int * v416 = v380->cache_age;
      v416[v515] = 0;
      v462 = v515;
    } else {
      int * v419 = v380->cache_age;
      int v522 = 4 + ((((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1)) & 3) * 2);
      int v420 = v419[v522];
      int * v421 = v380->cache_tags;
      int v422 = v421[v522];
      int v423 = v419[v501];
      int v424 = v421[v501];
      int * v425 = v380->cache_dirty;
      int v525 = (4 + ((((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1)) & 3) * 2)) + ((((v420 + ((~(((v422 ^ -1) | (-(v422 ^ -1))) >> 31)) & 2)) - (v423 + ((~(((v424 ^ -1) | (-(v424 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v426 = v425[v525];
      bool v526 = !(v426 == 0);
      if (v526) {
        int * v427 = v380->cache_tags;
        int v428 = v427[v525];
        int * v429 = v380->cache_vals;
        int v529 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1)) & 3) * 2)) + ((((v420 + ((~(((v422 ^ -1) | (-(v422 ^ -1))) >> 31)) & 2)) - (v423 + ((~(((v424 ^ -1) | (-(v424 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v430 = v429[v529];
        int v530 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1)) & 3) * 2)) + ((((v420 + ((~(((v422 ^ -1) | (-(v422 ^ -1))) >> 31)) & 2)) - (v423 + ((~(((v424 ^ -1) | (-(v424 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v431 = v429[v530];
        int * v432 = v380->mem;
        int v532 = v428 * 2;
        v432[v532] = v430;
        int * v434 = v380->mem;
        int v535 = (v428 * 2) + 1;
        v434[v535] = v431;
        ;
      } else {
        ;
      }
      int * v439 = v380->mem;
      int v540 = ((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1)) * 2;
      int v440 = v439[v540];
      int v541 = (((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1)) * 2) + 1;
      int v441 = v439[v541];
      int * v442 = v380->cache_vals;
      int v543 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1)) & 3) * 2)) + ((((v420 + ((~(((v422 ^ -1) | (-(v422 ^ -1))) >> 31)) & 2)) - (v423 + ((~(((v424 ^ -1) | (-(v424 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v442[v543] = v440;
      int * v444 = v380->cache_vals;
      int v546 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1)) & 3) * 2)) + ((((v420 + ((~(((v422 ^ -1) | (-(v422 ^ -1))) >> 31)) & 2)) - (v423 + ((~(((v424 ^ -1) | (-(v424 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v444[v546] = v441;
      int * v446 = v380->cache_tags;
      int v549 = (int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1);
      v446[v525] = v549;
      int * v448 = v380->cache_dirty;
      v448[v525] = 0;
      int * v450 = v380->cache_age;
      v450[v525] = 1;
      int * v452 = v380->cache_age;
      int v453 = v452[v525];
      int v454 = v452[v500];
      int v555 = v454 + ((int)((unsigned int)(v454 - v453) >> 31));
      v452[v500] = v555;
      int * v456 = v380->cache_age;
      int v457 = v456[v501];
      int v557 = v457 + ((int)((unsigned int)(v457 - v453) >> 31));
      v456[v501] = v557;
      int * v459 = v380->cache_age;
      v459[v525] = 0;
      v462 = v525;
    }
    int * v463 = v380->cache_vals;
    int v560 = v462 * 2;
    int v464 = v463[v560];
    int v561 = (v462 * 2) + 1;
    int v465 = v463[v561];
    int v562 = (((((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1)) & 1) * 2) + ((((v404 + ((~(((v406 ^ -1) | (-(v406 ^ -1))) >> 31)) & 2)) - (v407 + ((~(((v408 ^ -1) | (-(v408 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v463[v562] = v464;
    int * v467 = v380->cache_vals;
    int v565 = ((((((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1)) & 1) * 2) + ((((v404 + ((~(((v406 ^ -1) | (-(v406 ^ -1))) >> 31)) & 2)) - (v407 + ((~(((v408 ^ -1) | (-(v408 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v467[v565] = v465;
    int * v469 = v380->cache_tags;
    int v568 = ((((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1)) & 1) * 2) + ((((v404 + ((~(((v406 ^ -1) | (-(v406 ^ -1))) >> 31)) & 2)) - (v407 + ((~(((v408 ^ -1) | (-(v408 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v569 = (int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1);
    v469[v568] = v569;
    int * v471 = v380->cache_dirty;
    v471[v568] = 0;
    int * v473 = v380->cache_age;
    v473[v568] = 1;
    int * v475 = v380->cache_age;
    int v476 = v475[v568];
    int v477 = v475[v498];
    int v575 = v477 + ((int)((unsigned int)(v477 - v476) >> 31));
    v475[v498] = v575;
    int * v479 = v380->cache_age;
    int v480 = v479[v499];
    int v577 = v480 + ((int)((unsigned int)(v480 - v476) >> 31));
    v479[v499] = v577;
    int * v482 = v380->cache_age;
    v482[v568] = 0;
    v485 = v568;
  }
  int v580 = (v485 * 2) + (((int)((unsigned int)v386 >> 2)) & 1);
  int v486 = v392[v580];
  int * v487 = v380->reg_ready;
  int v583 = ((v384 + ((v381 - v384) & (~((v381 - v384) >> 31)))) + 1) + ((100 ^ (((~(((v390 ^ ((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1))) | (-(v390 ^ ((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1))))) >> 31)) | (~(((v391 ^ ((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1))) | (-(v391 ^ ((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v388 ^ ((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1))) | (-(v388 ^ ((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1))))) >> 31)) | (~(((v389 ^ ((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1))) | (-(v389 ^ ((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v390 ^ ((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1))) | (-(v390 ^ ((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1))))) >> 31)) | (~(((v391 ^ ((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1))) | (-(v391 ^ ((int)((unsigned int)((int)((unsigned int)v386 >> 2)) >> 1))))) >> 31))) & 104)))));
  v487[11] = v583;
  int * v489 = v380->regs;
  v489[11] = v486;
  struct StateT * v491 = slot_5(v380);
  return v491;
}

struct StateT * slot_2(struct StateT * v45) {
  int v46 = v45->timer;
  int v54 = v46 + 1;
  v45->timer = v54;
  int * v48 = v45->reg_ready;
  v48[7] = v54;
  int * v50 = v45->regs;
  v50[7] = 0;
  struct StateT * v52 = slot_3(v45);
  return v52;
}

struct StateT * slot_3(struct StateT * v61) {
  int v62 = v61->timer;
  int v235 = v62 + 1;
  v61->timer = v235;
  int * v64 = v61->reg_ready;
  int * v66 = v61->regs;
  int v67 = v66[6];
  int v69 = v66[7];
  int * v70 = v61->cache_tags;
  int v241 = (((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 1) * 2;
  int v71 = v70[v241];
  int v242 = ((((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 1) * 2) + 1;
  int v72 = v70[v242];
  int v243 = 4 + ((((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 3) * 2);
  int v73 = v70[v243];
  int v244 = (4 + ((((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v74 = v70[v244];
  int v75 = v61->timer;
  int v245 = v75 + ((100 ^ (((~(((v73 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))) | (-(v73 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))))) >> 31)) | (~(((v74 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))) | (-(v74 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v71 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))) | (-(v71 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))))) >> 31)) | (~(((v72 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))) | (-(v72 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v73 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))) | (-(v73 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))))) >> 31)) | (~(((v74 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))) | (-(v74 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))))) >> 31))) & 104)))));
  v61->timer = v245;
  bool v246 = !(((~(((v71 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))) | (-(v71 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))))) >> 31)) | (~(((v72 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))) | (-(v72 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))))) >> 31))) == 0);
  int v169;
  if (v246) {
    int * v77 = v61->cache_age;
    int v248 = ((((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 1) * 2) + ((~(((v72 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))) | (-(v72 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))))) >> 31)) & 1);
    int v78 = v77[v248];
    int v79 = v77[v241];
    int v249 = v79 + ((int)((unsigned int)(v79 - v78) >> 31));
    v77[v241] = v249;
    int * v81 = v61->cache_age;
    int v82 = v81[v242];
    int v251 = v82 + ((int)((unsigned int)(v82 - v78) >> 31));
    v81[v242] = v251;
    int * v84 = v61->cache_age;
    v84[v248] = 0;
    v169 = v248;
  } else {
    int * v87 = v61->cache_age;
    int v255 = (((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 1) * 2;
    int v88 = v87[v255];
    int * v89 = v61->cache_tags;
    int v90 = v89[v255];
    int v91 = v87[v242];
    int v92 = v89[v242];
    bool v257 = !(((~(((v73 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))) | (-(v73 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))))) >> 31)) | (~(((v74 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))) | (-(v74 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))))) >> 31))) == 0);
    int v146;
    if (v257) {
      int * v93 = v61->cache_age;
      int v259 = (4 + ((((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 3) * 2)) + ((~(((v74 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))) | (-(v74 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))))) >> 31)) & 1);
      int v94 = v93[v259];
      int v95 = v93[v243];
      int v260 = v95 + ((int)((unsigned int)(v95 - v94) >> 31));
      v93[v243] = v260;
      int * v97 = v61->cache_age;
      int v98 = v97[v244];
      int v262 = v98 + ((int)((unsigned int)(v98 - v94) >> 31));
      v97[v244] = v262;
      int * v100 = v61->cache_age;
      v100[v259] = 0;
      v146 = v259;
    } else {
      int * v103 = v61->cache_age;
      int v266 = 4 + ((((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 3) * 2);
      int v104 = v103[v266];
      int * v105 = v61->cache_tags;
      int v106 = v105[v266];
      int v107 = v103[v244];
      int v108 = v105[v244];
      int * v109 = v61->cache_dirty;
      int v269 = (4 + ((((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 3) * 2)) + ((((v104 + ((~(((v106 ^ -1) | (-(v106 ^ -1))) >> 31)) & 2)) - (v107 + ((~(((v108 ^ -1) | (-(v108 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v110 = v109[v269];
      bool v270 = !(v110 == 0);
      if (v270) {
        int * v111 = v61->cache_tags;
        int v112 = v111[v269];
        int * v113 = v61->cache_vals;
        int v273 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 3) * 2)) + ((((v104 + ((~(((v106 ^ -1) | (-(v106 ^ -1))) >> 31)) & 2)) - (v107 + ((~(((v108 ^ -1) | (-(v108 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v114 = v113[v273];
        int v274 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 3) * 2)) + ((((v104 + ((~(((v106 ^ -1) | (-(v106 ^ -1))) >> 31)) & 2)) - (v107 + ((~(((v108 ^ -1) | (-(v108 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v115 = v113[v274];
        int * v116 = v61->mem;
        int v276 = v112 * 2;
        v116[v276] = v114;
        int * v118 = v61->mem;
        int v279 = (v112 * 2) + 1;
        v118[v279] = v115;
        ;
      } else {
        ;
      }
      int * v123 = v61->mem;
      int v284 = ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) * 2;
      int v124 = v123[v284];
      int v285 = (((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) * 2) + 1;
      int v125 = v123[v285];
      int * v126 = v61->cache_vals;
      int v287 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 3) * 2)) + ((((v104 + ((~(((v106 ^ -1) | (-(v106 ^ -1))) >> 31)) & 2)) - (v107 + ((~(((v108 ^ -1) | (-(v108 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v126[v287] = v124;
      int * v128 = v61->cache_vals;
      int v290 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 3) * 2)) + ((((v104 + ((~(((v106 ^ -1) | (-(v106 ^ -1))) >> 31)) & 2)) - (v107 + ((~(((v108 ^ -1) | (-(v108 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v128[v290] = v125;
      int * v130 = v61->cache_tags;
      int v293 = (int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1);
      v130[v269] = v293;
      int * v132 = v61->cache_dirty;
      v132[v269] = 0;
      int * v134 = v61->cache_age;
      v134[v269] = 1;
      int * v136 = v61->cache_age;
      int v137 = v136[v269];
      int v138 = v136[v243];
      int v299 = v138 + ((int)((unsigned int)(v138 - v137) >> 31));
      v136[v243] = v299;
      int * v140 = v61->cache_age;
      int v141 = v140[v244];
      int v301 = v141 + ((int)((unsigned int)(v141 - v137) >> 31));
      v140[v244] = v301;
      int * v143 = v61->cache_age;
      v143[v269] = 0;
      v146 = v269;
    }
    int * v147 = v61->cache_vals;
    int v304 = v146 * 2;
    int v148 = v147[v304];
    int v305 = (v146 * 2) + 1;
    int v149 = v147[v305];
    int v306 = (((((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 1) * 2) + ((((v88 + ((~(((v90 ^ -1) | (-(v90 ^ -1))) >> 31)) & 2)) - (v91 + ((~(((v92 ^ -1) | (-(v92 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v147[v306] = v148;
    int * v151 = v61->cache_vals;
    int v309 = ((((((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 1) * 2) + ((((v88 + ((~(((v90 ^ -1) | (-(v90 ^ -1))) >> 31)) & 2)) - (v91 + ((~(((v92 ^ -1) | (-(v92 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v151[v309] = v149;
    int * v153 = v61->cache_tags;
    int v312 = ((((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 1) * 2) + ((((v88 + ((~(((v90 ^ -1) | (-(v90 ^ -1))) >> 31)) & 2)) - (v91 + ((~(((v92 ^ -1) | (-(v92 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v313 = (int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1);
    v153[v312] = v313;
    int * v155 = v61->cache_dirty;
    v155[v312] = 0;
    int * v157 = v61->cache_age;
    v157[v312] = 1;
    int * v159 = v61->cache_age;
    int v160 = v159[v312];
    int v161 = v159[v241];
    int v319 = v161 + ((int)((unsigned int)(v161 - v160) >> 31));
    v159[v241] = v319;
    int * v163 = v61->cache_age;
    int v164 = v163[v242];
    int v321 = v164 + ((int)((unsigned int)(v164 - v160) >> 31));
    v163[v242] = v321;
    int * v166 = v61->cache_age;
    v166[v312] = 0;
    v169 = v312;
  }
  int * v170 = v61->cache_vals;
  int v324 = (v169 * 2) + (((int)((unsigned int)v67 >> 2)) & 1);
  v170[v324] = v69;
  int * v172 = v61->cache_tags;
  int v173 = v172[v243];
  int v174 = v172[v244];
  bool v327 = !(((~(((v173 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))) | (-(v173 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))))) >> 31)) | (~(((v174 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))) | (-(v174 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))))) >> 31))) == 0);
  int v228;
  if (v327) {
    int * v175 = v61->cache_age;
    int v329 = (4 + ((((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 3) * 2)) + ((~(((v174 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))) | (-(v174 ^ ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1))))) >> 31)) & 1);
    int v176 = v175[v329];
    int v177 = v175[v243];
    int v330 = v177 + ((int)((unsigned int)(v177 - v176) >> 31));
    v175[v243] = v330;
    int * v179 = v61->cache_age;
    int v180 = v179[v244];
    int v332 = v180 + ((int)((unsigned int)(v180 - v176) >> 31));
    v179[v244] = v332;
    int * v182 = v61->cache_age;
    v182[v329] = 0;
    v228 = v329;
  } else {
    int * v185 = v61->cache_age;
    int v336 = 4 + ((((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 3) * 2);
    int v186 = v185[v336];
    int * v187 = v61->cache_tags;
    int v188 = v187[v336];
    int v189 = v185[v244];
    int v190 = v187[v244];
    int * v191 = v61->cache_dirty;
    int v339 = (4 + ((((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 3) * 2)) + ((((v186 + ((~(((v188 ^ -1) | (-(v188 ^ -1))) >> 31)) & 2)) - (v189 + ((~(((v190 ^ -1) | (-(v190 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v192 = v191[v339];
    bool v340 = !(v192 == 0);
    if (v340) {
      int * v193 = v61->cache_tags;
      int v194 = v193[v339];
      int * v195 = v61->cache_vals;
      int v343 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 3) * 2)) + ((((v186 + ((~(((v188 ^ -1) | (-(v188 ^ -1))) >> 31)) & 2)) - (v189 + ((~(((v190 ^ -1) | (-(v190 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v196 = v195[v343];
      int v344 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 3) * 2)) + ((((v186 + ((~(((v188 ^ -1) | (-(v188 ^ -1))) >> 31)) & 2)) - (v189 + ((~(((v190 ^ -1) | (-(v190 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v197 = v195[v344];
      int * v198 = v61->mem;
      int v346 = v194 * 2;
      v198[v346] = v196;
      int * v200 = v61->mem;
      int v349 = (v194 * 2) + 1;
      v200[v349] = v197;
      ;
    } else {
      ;
    }
    int * v205 = v61->mem;
    int v354 = ((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) * 2;
    int v206 = v205[v354];
    int v355 = (((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) * 2) + 1;
    int v207 = v205[v355];
    int * v208 = v61->cache_vals;
    int v357 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 3) * 2)) + ((((v186 + ((~(((v188 ^ -1) | (-(v188 ^ -1))) >> 31)) & 2)) - (v189 + ((~(((v190 ^ -1) | (-(v190 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v208[v357] = v206;
    int * v210 = v61->cache_vals;
    int v360 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1)) & 3) * 2)) + ((((v186 + ((~(((v188 ^ -1) | (-(v188 ^ -1))) >> 31)) & 2)) - (v189 + ((~(((v190 ^ -1) | (-(v190 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v210[v360] = v207;
    int * v212 = v61->cache_tags;
    int v363 = (int)((unsigned int)((int)((unsigned int)v67 >> 2)) >> 1);
    v212[v339] = v363;
    int * v214 = v61->cache_dirty;
    v214[v339] = 0;
    int * v216 = v61->cache_age;
    v216[v339] = 1;
    int * v218 = v61->cache_age;
    int v219 = v218[v339];
    int v220 = v218[v243];
    int v369 = v220 + ((int)((unsigned int)(v220 - v219) >> 31));
    v218[v243] = v369;
    int * v222 = v61->cache_age;
    int v223 = v222[v244];
    int v371 = v223 + ((int)((unsigned int)(v223 - v219) >> 31));
    v222[v244] = v371;
    int * v225 = v61->cache_age;
    v225[v339] = 0;
    v228 = v339;
  }
  int * v229 = v61->cache_vals;
  int v374 = (v228 * 2) + (((int)((unsigned int)v67 >> 2)) & 1);
  v229[v374] = v69;
  int * v231 = v61->cache_dirty;
  v231[v228] = 1;
  struct StateT * v233 = slot_4(v61);
  return v233;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v14 = v3 + 1;
  v2->timer = v14;
  int * v5 = v2->reg_ready;
  int v6 = v5[10];
  int * v7 = v2->regs;
  int v8 = v7[10];
  int v19 = (v6 + ((v3 - v6) & (~((v3 - v6) >> 31)))) + 1;
  v5[6] = v19;
  int * v10 = v2->regs;
  int v21 = v8 & 28;
  v10[6] = v21;
  struct StateT * v12 = slot_1(v2);
  return v12;
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