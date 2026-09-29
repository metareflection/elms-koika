// verify: leak widened (the program is clean; Eva cannot prove it) [unroll 65]
#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_ENTRIES 12
#define CACHE_WORDS 24

#ifdef EVA
#include "__fc_builtin.h"
/*@ requires untainted: !\tainted(b);
    assigns \nothing; */
void koika_check(int b);
/*@ assigns *p \from \nothing;
    taints *p; */
void koika_mark(int *p);
#define koika_assert(b, s) koika_check(b)
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
struct StateT * slot_8(struct StateT * v649);
struct StateT * slot_6(struct StateT * v420);
struct StateT * slot_5(struct StateT * v101);
struct StateT * slot_4(struct StateT * v85);
struct StateT * slot_2(struct StateT * v40);
struct StateT * slot_7(struct StateT * v628);
struct StateT * slot_3(struct StateT * v63);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v854 = v1->timer;
  int * v855 = v1->reg_ready;
  int v856 = v855[0];
  int v987 = v856 + ((v854 - v856) & (~((v854 - v856) >> 31)));
  v1->timer = v987;
  int v858 = v1->timer;
  int * v859 = v1->reg_ready;
  int v860 = v859[1];
  int v990 = v860 + ((v858 - v860) & (~((v858 - v860) >> 31)));
  v1->timer = v990;
  int v862 = v1->timer;
  int * v863 = v1->reg_ready;
  int v864 = v863[2];
  int v993 = v864 + ((v862 - v864) & (~((v862 - v864) >> 31)));
  v1->timer = v993;
  int v866 = v1->timer;
  int * v867 = v1->reg_ready;
  int v868 = v867[3];
  int v996 = v868 + ((v866 - v868) & (~((v866 - v868) >> 31)));
  v1->timer = v996;
  int v870 = v1->timer;
  int * v871 = v1->reg_ready;
  int v872 = v871[4];
  int v999 = v872 + ((v870 - v872) & (~((v870 - v872) >> 31)));
  v1->timer = v999;
  int v874 = v1->timer;
  int * v875 = v1->reg_ready;
  int v876 = v875[5];
  int v1002 = v876 + ((v874 - v876) & (~((v874 - v876) >> 31)));
  v1->timer = v1002;
  int v878 = v1->timer;
  int * v879 = v1->reg_ready;
  int v880 = v879[6];
  int v1005 = v880 + ((v878 - v880) & (~((v878 - v880) >> 31)));
  v1->timer = v1005;
  int v882 = v1->timer;
  int * v883 = v1->reg_ready;
  int v884 = v883[7];
  int v1008 = v884 + ((v882 - v884) & (~((v882 - v884) >> 31)));
  v1->timer = v1008;
  int v886 = v1->timer;
  int * v887 = v1->reg_ready;
  int v888 = v887[8];
  int v1011 = v888 + ((v886 - v888) & (~((v886 - v888) >> 31)));
  v1->timer = v1011;
  int v890 = v1->timer;
  int * v891 = v1->reg_ready;
  int v892 = v891[9];
  int v1014 = v892 + ((v890 - v892) & (~((v890 - v892) >> 31)));
  v1->timer = v1014;
  int v894 = v1->timer;
  int * v895 = v1->reg_ready;
  int v896 = v895[10];
  int v1017 = v896 + ((v894 - v896) & (~((v894 - v896) >> 31)));
  v1->timer = v1017;
  int v898 = v1->timer;
  int * v899 = v1->reg_ready;
  int v900 = v899[11];
  int v1020 = v900 + ((v898 - v900) & (~((v898 - v900) >> 31)));
  v1->timer = v1020;
  int v902 = v1->timer;
  int * v903 = v1->reg_ready;
  int v904 = v903[12];
  int v1023 = v904 + ((v902 - v904) & (~((v902 - v904) >> 31)));
  v1->timer = v1023;
  int v906 = v1->timer;
  int * v907 = v1->reg_ready;
  int v908 = v907[13];
  int v1026 = v908 + ((v906 - v908) & (~((v906 - v908) >> 31)));
  v1->timer = v1026;
  int v910 = v1->timer;
  int * v911 = v1->reg_ready;
  int v912 = v911[14];
  int v1029 = v912 + ((v910 - v912) & (~((v910 - v912) >> 31)));
  v1->timer = v1029;
  int v914 = v1->timer;
  int * v915 = v1->reg_ready;
  int v916 = v915[15];
  int v1032 = v916 + ((v914 - v916) & (~((v914 - v916) >> 31)));
  v1->timer = v1032;
  int v918 = v1->timer;
  int * v919 = v1->reg_ready;
  int v920 = v919[16];
  int v1035 = v920 + ((v918 - v920) & (~((v918 - v920) >> 31)));
  v1->timer = v1035;
  int v922 = v1->timer;
  int * v923 = v1->reg_ready;
  int v924 = v923[17];
  int v1038 = v924 + ((v922 - v924) & (~((v922 - v924) >> 31)));
  v1->timer = v1038;
  int v926 = v1->timer;
  int * v927 = v1->reg_ready;
  int v928 = v927[18];
  int v1041 = v928 + ((v926 - v928) & (~((v926 - v928) >> 31)));
  v1->timer = v1041;
  int v930 = v1->timer;
  int * v931 = v1->reg_ready;
  int v932 = v931[19];
  int v1044 = v932 + ((v930 - v932) & (~((v930 - v932) >> 31)));
  v1->timer = v1044;
  int v934 = v1->timer;
  int * v935 = v1->reg_ready;
  int v936 = v935[20];
  int v1047 = v936 + ((v934 - v936) & (~((v934 - v936) >> 31)));
  v1->timer = v1047;
  int v938 = v1->timer;
  int * v939 = v1->reg_ready;
  int v940 = v939[21];
  int v1050 = v940 + ((v938 - v940) & (~((v938 - v940) >> 31)));
  v1->timer = v1050;
  int v942 = v1->timer;
  int * v943 = v1->reg_ready;
  int v944 = v943[22];
  int v1053 = v944 + ((v942 - v944) & (~((v942 - v944) >> 31)));
  v1->timer = v1053;
  int v946 = v1->timer;
  int * v947 = v1->reg_ready;
  int v948 = v947[23];
  int v1056 = v948 + ((v946 - v948) & (~((v946 - v948) >> 31)));
  v1->timer = v1056;
  int v950 = v1->timer;
  int * v951 = v1->reg_ready;
  int v952 = v951[24];
  int v1059 = v952 + ((v950 - v952) & (~((v950 - v952) >> 31)));
  v1->timer = v1059;
  int v954 = v1->timer;
  int * v955 = v1->reg_ready;
  int v956 = v955[25];
  int v1062 = v956 + ((v954 - v956) & (~((v954 - v956) >> 31)));
  v1->timer = v1062;
  int v958 = v1->timer;
  int * v959 = v1->reg_ready;
  int v960 = v959[26];
  int v1065 = v960 + ((v958 - v960) & (~((v958 - v960) >> 31)));
  v1->timer = v1065;
  int v962 = v1->timer;
  int * v963 = v1->reg_ready;
  int v964 = v963[27];
  int v1068 = v964 + ((v962 - v964) & (~((v962 - v964) >> 31)));
  v1->timer = v1068;
  int v966 = v1->timer;
  int * v967 = v1->reg_ready;
  int v968 = v967[28];
  int v1071 = v968 + ((v966 - v968) & (~((v966 - v968) >> 31)));
  v1->timer = v1071;
  int v970 = v1->timer;
  int * v971 = v1->reg_ready;
  int v972 = v971[29];
  int v1074 = v972 + ((v970 - v972) & (~((v970 - v972) >> 31)));
  v1->timer = v1074;
  int v974 = v1->timer;
  int * v975 = v1->reg_ready;
  int v976 = v975[30];
  int v1077 = v976 + ((v974 - v976) & (~((v974 - v976) >> 31)));
  v1->timer = v1077;
  int v978 = v1->timer;
  int * v979 = v1->reg_ready;
  int v980 = v979[31];
  int v1080 = v980 + ((v978 - v980) & (~((v978 - v980) >> 31)));
  v1->timer = v1080;
  return v1;
}

struct StateT * slot_1(struct StateT * v24) {
  int v25 = v24->timer;
  int v33 = v25 + 1;
  v24->timer = v33;
  int * v27 = v24->reg_ready;
  v27[9] = v33;
  int * v29 = v24->regs;
  v29[9] = 32;
  struct StateT * v31 = slot_2(v24);
  return v31;
}

struct StateT * slot_8(struct StateT * v649) {
  int v650 = v649->timer;
  int v761 = v650 + 1;
  v649->timer = v761;
  int * v652 = v649->reg_ready;
  int v653 = v652[11];
  int * v654 = v649->regs;
  int v655 = v654[11];
  int * v656 = v649->cache_tags;
  int v766 = (((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1)) & 1) * 2;
  int v657 = v656[v766];
  int v767 = ((((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1)) & 1) * 2) + 1;
  int v658 = v656[v767];
  int v768 = 4 + ((((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1)) & 3) * 2);
  int v659 = v656[v768];
  int v769 = (4 + ((((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v660 = v656[v769];
  int * v661 = v649->cache_vals;
  bool v770 = !(((~(((v657 ^ ((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1))) | (-(v657 ^ ((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1))))) >> 31)) | (~(((v658 ^ ((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1))) | (-(v658 ^ ((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1))))) >> 31))) == 0);
  int v754;
  if (v770) {
    int * v662 = v649->cache_age;
    int v772 = ((((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1)) & 1) * 2) + ((~(((v658 ^ ((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1))) | (-(v658 ^ ((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1))))) >> 31)) & 1);
    int v663 = v662[v772];
    int v664 = v662[v766];
    int v773 = v664 + ((int)((unsigned int)(v664 - v663) >> 31));
    v662[v766] = v773;
    int * v666 = v649->cache_age;
    int v667 = v666[v767];
    int v775 = v667 + ((int)((unsigned int)(v667 - v663) >> 31));
    v666[v767] = v775;
    int * v669 = v649->cache_age;
    v669[v772] = 0;
    v754 = v772;
  } else {
    int * v672 = v649->cache_age;
    int v779 = (((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1)) & 1) * 2;
    int v673 = v672[v779];
    int * v674 = v649->cache_tags;
    int v675 = v674[v779];
    int v676 = v672[v767];
    int v677 = v674[v767];
    bool v781 = !(((~(((v659 ^ ((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1))) | (-(v659 ^ ((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1))))) >> 31)) | (~(((v660 ^ ((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1))) | (-(v660 ^ ((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1))))) >> 31))) == 0);
    int v731;
    if (v781) {
      int * v678 = v649->cache_age;
      int v783 = (4 + ((((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1)) & 3) * 2)) + ((~(((v660 ^ ((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1))) | (-(v660 ^ ((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1))))) >> 31)) & 1);
      int v679 = v678[v783];
      int v680 = v678[v768];
      int v784 = v680 + ((int)((unsigned int)(v680 - v679) >> 31));
      v678[v768] = v784;
      int * v682 = v649->cache_age;
      int v683 = v682[v769];
      int v786 = v683 + ((int)((unsigned int)(v683 - v679) >> 31));
      v682[v769] = v786;
      int * v685 = v649->cache_age;
      v685[v783] = 0;
      v731 = v783;
    } else {
      int * v688 = v649->cache_age;
      int v790 = 4 + ((((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1)) & 3) * 2);
      int v689 = v688[v790];
      int * v690 = v649->cache_tags;
      int v691 = v690[v790];
      int v692 = v688[v769];
      int v693 = v690[v769];
      int * v694 = v649->cache_dirty;
      int v793 = (4 + ((((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1)) & 3) * 2)) + ((((v689 + ((~(((v691 ^ -1) | (-(v691 ^ -1))) >> 31)) & 2)) - (v692 + ((~(((v693 ^ -1) | (-(v693 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v695 = v694[v793];
      bool v794 = !(v695 == 0);
      if (v794) {
        int * v696 = v649->cache_tags;
        int v697 = v696[v793];
        int * v698 = v649->cache_vals;
        int v797 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1)) & 3) * 2)) + ((((v689 + ((~(((v691 ^ -1) | (-(v691 ^ -1))) >> 31)) & 2)) - (v692 + ((~(((v693 ^ -1) | (-(v693 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v699 = v698[v797];
        int v798 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1)) & 3) * 2)) + ((((v689 + ((~(((v691 ^ -1) | (-(v691 ^ -1))) >> 31)) & 2)) - (v692 + ((~(((v693 ^ -1) | (-(v693 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v700 = v698[v798];
        int * v701 = v649->mem;
        int v800 = v697 * 2;
        v701[v800] = v699;
        int * v703 = v649->mem;
        int v803 = (v697 * 2) + 1;
        v703[v803] = v700;
        ;
      } else {
        ;
      }
      int * v708 = v649->mem;
      int v808 = ((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1)) * 2;
      int v709 = v708[v808];
      int v809 = (((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1)) * 2) + 1;
      int v710 = v708[v809];
      int * v711 = v649->cache_vals;
      int v811 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1)) & 3) * 2)) + ((((v689 + ((~(((v691 ^ -1) | (-(v691 ^ -1))) >> 31)) & 2)) - (v692 + ((~(((v693 ^ -1) | (-(v693 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v711[v811] = v709;
      int * v713 = v649->cache_vals;
      int v814 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1)) & 3) * 2)) + ((((v689 + ((~(((v691 ^ -1) | (-(v691 ^ -1))) >> 31)) & 2)) - (v692 + ((~(((v693 ^ -1) | (-(v693 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v713[v814] = v710;
      int * v715 = v649->cache_tags;
      int v817 = (int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1);
      v715[v793] = v817;
      int * v717 = v649->cache_dirty;
      v717[v793] = 0;
      int * v719 = v649->cache_age;
      v719[v793] = 1;
      int * v721 = v649->cache_age;
      int v722 = v721[v793];
      int v723 = v721[v768];
      int v823 = v723 + ((int)((unsigned int)(v723 - v722) >> 31));
      v721[v768] = v823;
      int * v725 = v649->cache_age;
      int v726 = v725[v769];
      int v825 = v726 + ((int)((unsigned int)(v726 - v722) >> 31));
      v725[v769] = v825;
      int * v728 = v649->cache_age;
      v728[v793] = 0;
      v731 = v793;
    }
    int * v732 = v649->cache_vals;
    int v828 = v731 * 2;
    int v733 = v732[v828];
    int v829 = (v731 * 2) + 1;
    int v734 = v732[v829];
    int v830 = (((((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1)) & 1) * 2) + ((((v673 + ((~(((v675 ^ -1) | (-(v675 ^ -1))) >> 31)) & 2)) - (v676 + ((~(((v677 ^ -1) | (-(v677 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v732[v830] = v733;
    int * v736 = v649->cache_vals;
    int v833 = ((((((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1)) & 1) * 2) + ((((v673 + ((~(((v675 ^ -1) | (-(v675 ^ -1))) >> 31)) & 2)) - (v676 + ((~(((v677 ^ -1) | (-(v677 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v736[v833] = v734;
    int * v738 = v649->cache_tags;
    int v836 = ((((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1)) & 1) * 2) + ((((v673 + ((~(((v675 ^ -1) | (-(v675 ^ -1))) >> 31)) & 2)) - (v676 + ((~(((v677 ^ -1) | (-(v677 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v837 = (int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1);
    v738[v836] = v837;
    int * v740 = v649->cache_dirty;
    v740[v836] = 0;
    int * v742 = v649->cache_age;
    v742[v836] = 1;
    int * v744 = v649->cache_age;
    int v745 = v744[v836];
    int v746 = v744[v766];
    int v843 = v746 + ((int)((unsigned int)(v746 - v745) >> 31));
    v744[v766] = v843;
    int * v748 = v649->cache_age;
    int v749 = v748[v767];
    int v845 = v749 + ((int)((unsigned int)(v749 - v745) >> 31));
    v748[v767] = v845;
    int * v751 = v649->cache_age;
    v751[v836] = 0;
    v754 = v836;
  }
  int v848 = (v754 * 2) + (((int)((unsigned int)v655 >> 2)) & 1);
  int v755 = v661[v848];
  int * v756 = v649->reg_ready;
  int v851 = ((v653 + ((v650 - v653) & (~((v650 - v653) >> 31)))) + 1) + ((100 ^ (((~(((v659 ^ ((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1))) | (-(v659 ^ ((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1))))) >> 31)) | (~(((v660 ^ ((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1))) | (-(v660 ^ ((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v657 ^ ((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1))) | (-(v657 ^ ((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1))))) >> 31)) | (~(((v658 ^ ((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1))) | (-(v658 ^ ((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v659 ^ ((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1))) | (-(v659 ^ ((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1))))) >> 31)) | (~(((v660 ^ ((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1))) | (-(v660 ^ ((int)((unsigned int)((int)((unsigned int)v655 >> 2)) >> 1))))) >> 31))) & 104)))));
  v756[12] = v851;
  int * v758 = v649->regs;
  v758[12] = v755;
  return v649;
}

struct StateT * slot_6(struct StateT * v420) {
  int v421 = v420->timer;
  int v533 = v421 + 1;
  v420->timer = v533;
  int * v423 = v420->reg_ready;
  int v424 = v423[6];
  int * v425 = v420->regs;
  int v426 = v425[6];
  int * v427 = v420->cache_tags;
  int v538 = (((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1)) & 1) * 2;
  int v428 = v427[v538];
  int v539 = ((((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1)) & 1) * 2) + 1;
  int v429 = v427[v539];
  int v540 = 4 + ((((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1)) & 3) * 2);
  int v430 = v427[v540];
  int v541 = (4 + ((((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v431 = v427[v541];
  int * v432 = v420->cache_vals;
  bool v542 = !(((~(((v428 ^ ((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1))) | (-(v428 ^ ((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1))))) >> 31)) | (~(((v429 ^ ((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1))) | (-(v429 ^ ((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1))))) >> 31))) == 0);
  int v525;
  if (v542) {
    int * v433 = v420->cache_age;
    int v544 = ((((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1)) & 1) * 2) + ((~(((v429 ^ ((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1))) | (-(v429 ^ ((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1))))) >> 31)) & 1);
    int v434 = v433[v544];
    int v435 = v433[v538];
    int v545 = v435 + ((int)((unsigned int)(v435 - v434) >> 31));
    v433[v538] = v545;
    int * v437 = v420->cache_age;
    int v438 = v437[v539];
    int v547 = v438 + ((int)((unsigned int)(v438 - v434) >> 31));
    v437[v539] = v547;
    int * v440 = v420->cache_age;
    v440[v544] = 0;
    v525 = v544;
  } else {
    int * v443 = v420->cache_age;
    int v551 = (((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1)) & 1) * 2;
    int v444 = v443[v551];
    int * v445 = v420->cache_tags;
    int v446 = v445[v551];
    int v447 = v443[v539];
    int v448 = v445[v539];
    bool v553 = !(((~(((v430 ^ ((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1))) | (-(v430 ^ ((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1))))) >> 31)) | (~(((v431 ^ ((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1))) | (-(v431 ^ ((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1))))) >> 31))) == 0);
    int v502;
    if (v553) {
      int * v449 = v420->cache_age;
      int v555 = (4 + ((((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1)) & 3) * 2)) + ((~(((v431 ^ ((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1))) | (-(v431 ^ ((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1))))) >> 31)) & 1);
      int v450 = v449[v555];
      int v451 = v449[v540];
      int v556 = v451 + ((int)((unsigned int)(v451 - v450) >> 31));
      v449[v540] = v556;
      int * v453 = v420->cache_age;
      int v454 = v453[v541];
      int v558 = v454 + ((int)((unsigned int)(v454 - v450) >> 31));
      v453[v541] = v558;
      int * v456 = v420->cache_age;
      v456[v555] = 0;
      v502 = v555;
    } else {
      int * v459 = v420->cache_age;
      int v562 = 4 + ((((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1)) & 3) * 2);
      int v460 = v459[v562];
      int * v461 = v420->cache_tags;
      int v462 = v461[v562];
      int v463 = v459[v541];
      int v464 = v461[v541];
      int * v465 = v420->cache_dirty;
      int v565 = (4 + ((((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1)) & 3) * 2)) + ((((v460 + ((~(((v462 ^ -1) | (-(v462 ^ -1))) >> 31)) & 2)) - (v463 + ((~(((v464 ^ -1) | (-(v464 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v466 = v465[v565];
      bool v566 = !(v466 == 0);
      if (v566) {
        int * v467 = v420->cache_tags;
        int v468 = v467[v565];
        int * v469 = v420->cache_vals;
        int v569 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1)) & 3) * 2)) + ((((v460 + ((~(((v462 ^ -1) | (-(v462 ^ -1))) >> 31)) & 2)) - (v463 + ((~(((v464 ^ -1) | (-(v464 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v470 = v469[v569];
        int v570 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1)) & 3) * 2)) + ((((v460 + ((~(((v462 ^ -1) | (-(v462 ^ -1))) >> 31)) & 2)) - (v463 + ((~(((v464 ^ -1) | (-(v464 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v471 = v469[v570];
        int * v472 = v420->mem;
        int v572 = v468 * 2;
        v472[v572] = v470;
        int * v474 = v420->mem;
        int v575 = (v468 * 2) + 1;
        v474[v575] = v471;
        ;
      } else {
        ;
      }
      int * v479 = v420->mem;
      int v580 = ((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1)) * 2;
      int v480 = v479[v580];
      int v581 = (((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1)) * 2) + 1;
      int v481 = v479[v581];
      int * v482 = v420->cache_vals;
      int v583 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1)) & 3) * 2)) + ((((v460 + ((~(((v462 ^ -1) | (-(v462 ^ -1))) >> 31)) & 2)) - (v463 + ((~(((v464 ^ -1) | (-(v464 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v482[v583] = v480;
      int * v484 = v420->cache_vals;
      int v586 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1)) & 3) * 2)) + ((((v460 + ((~(((v462 ^ -1) | (-(v462 ^ -1))) >> 31)) & 2)) - (v463 + ((~(((v464 ^ -1) | (-(v464 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v484[v586] = v481;
      int * v486 = v420->cache_tags;
      int v589 = (int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1);
      v486[v565] = v589;
      int * v488 = v420->cache_dirty;
      v488[v565] = 0;
      int * v490 = v420->cache_age;
      v490[v565] = 1;
      int * v492 = v420->cache_age;
      int v493 = v492[v565];
      int v494 = v492[v540];
      int v595 = v494 + ((int)((unsigned int)(v494 - v493) >> 31));
      v492[v540] = v595;
      int * v496 = v420->cache_age;
      int v497 = v496[v541];
      int v597 = v497 + ((int)((unsigned int)(v497 - v493) >> 31));
      v496[v541] = v597;
      int * v499 = v420->cache_age;
      v499[v565] = 0;
      v502 = v565;
    }
    int * v503 = v420->cache_vals;
    int v600 = v502 * 2;
    int v504 = v503[v600];
    int v601 = (v502 * 2) + 1;
    int v505 = v503[v601];
    int v602 = (((((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1)) & 1) * 2) + ((((v444 + ((~(((v446 ^ -1) | (-(v446 ^ -1))) >> 31)) & 2)) - (v447 + ((~(((v448 ^ -1) | (-(v448 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v503[v602] = v504;
    int * v507 = v420->cache_vals;
    int v605 = ((((((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1)) & 1) * 2) + ((((v444 + ((~(((v446 ^ -1) | (-(v446 ^ -1))) >> 31)) & 2)) - (v447 + ((~(((v448 ^ -1) | (-(v448 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v507[v605] = v505;
    int * v509 = v420->cache_tags;
    int v608 = ((((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1)) & 1) * 2) + ((((v444 + ((~(((v446 ^ -1) | (-(v446 ^ -1))) >> 31)) & 2)) - (v447 + ((~(((v448 ^ -1) | (-(v448 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v609 = (int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1);
    v509[v608] = v609;
    int * v511 = v420->cache_dirty;
    v511[v608] = 0;
    int * v513 = v420->cache_age;
    v513[v608] = 1;
    int * v515 = v420->cache_age;
    int v516 = v515[v608];
    int v517 = v515[v538];
    int v615 = v517 + ((int)((unsigned int)(v517 - v516) >> 31));
    v515[v538] = v615;
    int * v519 = v420->cache_age;
    int v520 = v519[v539];
    int v617 = v520 + ((int)((unsigned int)(v520 - v516) >> 31));
    v519[v539] = v617;
    int * v522 = v420->cache_age;
    v522[v608] = 0;
    v525 = v608;
  }
  int v620 = (v525 * 2) + (((int)((unsigned int)v426 >> 2)) & 1);
  int v526 = v432[v620];
  int * v527 = v420->reg_ready;
  int v623 = ((v424 + ((v421 - v424) & (~((v421 - v424) >> 31)))) + 1) + ((100 ^ (((~(((v430 ^ ((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1))) | (-(v430 ^ ((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1))))) >> 31)) | (~(((v431 ^ ((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1))) | (-(v431 ^ ((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v428 ^ ((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1))) | (-(v428 ^ ((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1))))) >> 31)) | (~(((v429 ^ ((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1))) | (-(v429 ^ ((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v430 ^ ((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1))) | (-(v430 ^ ((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1))))) >> 31)) | (~(((v431 ^ ((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1))) | (-(v431 ^ ((int)((unsigned int)((int)((unsigned int)v426 >> 2)) >> 1))))) >> 31))) & 104)))));
  v527[11] = v623;
  int * v529 = v420->regs;
  v529[11] = v526;
  struct StateT * v531 = slot_7(v420);
  return v531;
}

struct StateT * slot_5(struct StateT * v101) {
  int v102 = v101->timer;
  int v275 = v102 + 1;
  v101->timer = v275;
  int * v104 = v101->reg_ready;
  int * v106 = v101->regs;
  int v107 = v106[6];
  int v109 = v106[7];
  int * v110 = v101->cache_tags;
  int v281 = (((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 1) * 2;
  int v111 = v110[v281];
  int v282 = ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 1) * 2) + 1;
  int v112 = v110[v282];
  int v283 = 4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2);
  int v113 = v110[v283];
  int v284 = (4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v114 = v110[v284];
  int v115 = v101->timer;
  int v285 = v115 + ((100 ^ (((~(((v113 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v113 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) | (~(((v114 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v114 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v111 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v111 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) | (~(((v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v113 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v113 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) | (~(((v114 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v114 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31))) & 104)))));
  v101->timer = v285;
  bool v286 = !(((~(((v111 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v111 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) | (~(((v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31))) == 0);
  int v209;
  if (v286) {
    int * v117 = v101->cache_age;
    int v288 = ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 1) * 2) + ((~(((v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v112 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) & 1);
    int v118 = v117[v288];
    int v119 = v117[v281];
    int v289 = v119 + ((int)((unsigned int)(v119 - v118) >> 31));
    v117[v281] = v289;
    int * v121 = v101->cache_age;
    int v122 = v121[v282];
    int v291 = v122 + ((int)((unsigned int)(v122 - v118) >> 31));
    v121[v282] = v291;
    int * v124 = v101->cache_age;
    v124[v288] = 0;
    v209 = v288;
  } else {
    int * v127 = v101->cache_age;
    int v295 = (((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 1) * 2;
    int v128 = v127[v295];
    int * v129 = v101->cache_tags;
    int v130 = v129[v295];
    int v131 = v127[v282];
    int v132 = v129[v282];
    bool v297 = !(((~(((v113 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v113 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) | (~(((v114 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v114 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31))) == 0);
    int v186;
    if (v297) {
      int * v133 = v101->cache_age;
      int v299 = (4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + ((~(((v114 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v114 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) & 1);
      int v134 = v133[v299];
      int v135 = v133[v283];
      int v300 = v135 + ((int)((unsigned int)(v135 - v134) >> 31));
      v133[v283] = v300;
      int * v137 = v101->cache_age;
      int v138 = v137[v284];
      int v302 = v138 + ((int)((unsigned int)(v138 - v134) >> 31));
      v137[v284] = v302;
      int * v140 = v101->cache_age;
      v140[v299] = 0;
      v186 = v299;
    } else {
      int * v143 = v101->cache_age;
      int v306 = 4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2);
      int v144 = v143[v306];
      int * v145 = v101->cache_tags;
      int v146 = v145[v306];
      int v147 = v143[v284];
      int v148 = v145[v284];
      int * v149 = v101->cache_dirty;
      int v309 = (4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + ((((v144 + ((~(((v146 ^ -1) | (-(v146 ^ -1))) >> 31)) & 2)) - (v147 + ((~(((v148 ^ -1) | (-(v148 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v150 = v149[v309];
      bool v310 = !(v150 == 0);
      if (v310) {
        int * v151 = v101->cache_tags;
        int v152 = v151[v309];
        int * v153 = v101->cache_vals;
        int v313 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + ((((v144 + ((~(((v146 ^ -1) | (-(v146 ^ -1))) >> 31)) & 2)) - (v147 + ((~(((v148 ^ -1) | (-(v148 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v154 = v153[v313];
        int v314 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + ((((v144 + ((~(((v146 ^ -1) | (-(v146 ^ -1))) >> 31)) & 2)) - (v147 + ((~(((v148 ^ -1) | (-(v148 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v155 = v153[v314];
        int * v156 = v101->mem;
        int v316 = v152 * 2;
        v156[v316] = v154;
        int * v158 = v101->mem;
        int v319 = (v152 * 2) + 1;
        v158[v319] = v155;
        ;
      } else {
        ;
      }
      int * v163 = v101->mem;
      int v324 = ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) * 2;
      int v164 = v163[v324];
      int v325 = (((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) * 2) + 1;
      int v165 = v163[v325];
      int * v166 = v101->cache_vals;
      int v327 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + ((((v144 + ((~(((v146 ^ -1) | (-(v146 ^ -1))) >> 31)) & 2)) - (v147 + ((~(((v148 ^ -1) | (-(v148 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v166[v327] = v164;
      int * v168 = v101->cache_vals;
      int v330 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + ((((v144 + ((~(((v146 ^ -1) | (-(v146 ^ -1))) >> 31)) & 2)) - (v147 + ((~(((v148 ^ -1) | (-(v148 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v168[v330] = v165;
      int * v170 = v101->cache_tags;
      int v333 = (int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1);
      v170[v309] = v333;
      int * v172 = v101->cache_dirty;
      v172[v309] = 0;
      int * v174 = v101->cache_age;
      v174[v309] = 1;
      int * v176 = v101->cache_age;
      int v177 = v176[v309];
      int v178 = v176[v283];
      int v339 = v178 + ((int)((unsigned int)(v178 - v177) >> 31));
      v176[v283] = v339;
      int * v180 = v101->cache_age;
      int v181 = v180[v284];
      int v341 = v181 + ((int)((unsigned int)(v181 - v177) >> 31));
      v180[v284] = v341;
      int * v183 = v101->cache_age;
      v183[v309] = 0;
      v186 = v309;
    }
    int * v187 = v101->cache_vals;
    int v344 = v186 * 2;
    int v188 = v187[v344];
    int v345 = (v186 * 2) + 1;
    int v189 = v187[v345];
    int v346 = (((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 1) * 2) + ((((v128 + ((~(((v130 ^ -1) | (-(v130 ^ -1))) >> 31)) & 2)) - (v131 + ((~(((v132 ^ -1) | (-(v132 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v187[v346] = v188;
    int * v191 = v101->cache_vals;
    int v349 = ((((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 1) * 2) + ((((v128 + ((~(((v130 ^ -1) | (-(v130 ^ -1))) >> 31)) & 2)) - (v131 + ((~(((v132 ^ -1) | (-(v132 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v191[v349] = v189;
    int * v193 = v101->cache_tags;
    int v352 = ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 1) * 2) + ((((v128 + ((~(((v130 ^ -1) | (-(v130 ^ -1))) >> 31)) & 2)) - (v131 + ((~(((v132 ^ -1) | (-(v132 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v353 = (int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1);
    v193[v352] = v353;
    int * v195 = v101->cache_dirty;
    v195[v352] = 0;
    int * v197 = v101->cache_age;
    v197[v352] = 1;
    int * v199 = v101->cache_age;
    int v200 = v199[v352];
    int v201 = v199[v281];
    int v359 = v201 + ((int)((unsigned int)(v201 - v200) >> 31));
    v199[v281] = v359;
    int * v203 = v101->cache_age;
    int v204 = v203[v282];
    int v361 = v204 + ((int)((unsigned int)(v204 - v200) >> 31));
    v203[v282] = v361;
    int * v206 = v101->cache_age;
    v206[v352] = 0;
    v209 = v352;
  }
  int * v210 = v101->cache_vals;
  int v364 = (v209 * 2) + (((int)((unsigned int)v107 >> 2)) & 1);
  v210[v364] = v109;
  int * v212 = v101->cache_tags;
  int v213 = v212[v283];
  int v214 = v212[v284];
  bool v367 = !(((~(((v213 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v213 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) | (~(((v214 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v214 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31))) == 0);
  int v268;
  if (v367) {
    int * v215 = v101->cache_age;
    int v369 = (4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + ((~(((v214 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))) | (-(v214 ^ ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1))))) >> 31)) & 1);
    int v216 = v215[v369];
    int v217 = v215[v283];
    int v370 = v217 + ((int)((unsigned int)(v217 - v216) >> 31));
    v215[v283] = v370;
    int * v219 = v101->cache_age;
    int v220 = v219[v284];
    int v372 = v220 + ((int)((unsigned int)(v220 - v216) >> 31));
    v219[v284] = v372;
    int * v222 = v101->cache_age;
    v222[v369] = 0;
    v268 = v369;
  } else {
    int * v225 = v101->cache_age;
    int v376 = 4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2);
    int v226 = v225[v376];
    int * v227 = v101->cache_tags;
    int v228 = v227[v376];
    int v229 = v225[v284];
    int v230 = v227[v284];
    int * v231 = v101->cache_dirty;
    int v379 = (4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + ((((v226 + ((~(((v228 ^ -1) | (-(v228 ^ -1))) >> 31)) & 2)) - (v229 + ((~(((v230 ^ -1) | (-(v230 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v232 = v231[v379];
    bool v380 = !(v232 == 0);
    if (v380) {
      int * v233 = v101->cache_tags;
      int v234 = v233[v379];
      int * v235 = v101->cache_vals;
      int v383 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + ((((v226 + ((~(((v228 ^ -1) | (-(v228 ^ -1))) >> 31)) & 2)) - (v229 + ((~(((v230 ^ -1) | (-(v230 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v236 = v235[v383];
      int v384 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + ((((v226 + ((~(((v228 ^ -1) | (-(v228 ^ -1))) >> 31)) & 2)) - (v229 + ((~(((v230 ^ -1) | (-(v230 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v237 = v235[v384];
      int * v238 = v101->mem;
      int v386 = v234 * 2;
      v238[v386] = v236;
      int * v240 = v101->mem;
      int v389 = (v234 * 2) + 1;
      v240[v389] = v237;
      ;
    } else {
      ;
    }
    int * v245 = v101->mem;
    int v394 = ((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) * 2;
    int v246 = v245[v394];
    int v395 = (((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) * 2) + 1;
    int v247 = v245[v395];
    int * v248 = v101->cache_vals;
    int v397 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + ((((v226 + ((~(((v228 ^ -1) | (-(v228 ^ -1))) >> 31)) & 2)) - (v229 + ((~(((v230 ^ -1) | (-(v230 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v248[v397] = v246;
    int * v250 = v101->cache_vals;
    int v400 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1)) & 3) * 2)) + ((((v226 + ((~(((v228 ^ -1) | (-(v228 ^ -1))) >> 31)) & 2)) - (v229 + ((~(((v230 ^ -1) | (-(v230 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v250[v400] = v247;
    int * v252 = v101->cache_tags;
    int v403 = (int)((unsigned int)((int)((unsigned int)v107 >> 2)) >> 1);
    v252[v379] = v403;
    int * v254 = v101->cache_dirty;
    v254[v379] = 0;
    int * v256 = v101->cache_age;
    v256[v379] = 1;
    int * v258 = v101->cache_age;
    int v259 = v258[v379];
    int v260 = v258[v283];
    int v409 = v260 + ((int)((unsigned int)(v260 - v259) >> 31));
    v258[v283] = v409;
    int * v262 = v101->cache_age;
    int v263 = v262[v284];
    int v411 = v263 + ((int)((unsigned int)(v263 - v259) >> 31));
    v262[v284] = v411;
    int * v265 = v101->cache_age;
    v265[v379] = 0;
    v268 = v379;
  }
  int * v269 = v101->cache_vals;
  int v414 = (v268 * 2) + (((int)((unsigned int)v107 >> 2)) & 1);
  v269[v414] = v109;
  int * v271 = v101->cache_dirty;
  v271[v268] = 1;
  struct StateT * v273 = slot_6(v101);
  return v273;
}

struct StateT * slot_4(struct StateT * v85) {
  int v86 = v85->timer;
  int v94 = v86 + 1;
  v85->timer = v94;
  int * v88 = v85->reg_ready;
  v88[7] = v94;
  int * v90 = v85->regs;
  v90[7] = 0;
  struct StateT * v92 = slot_5(v85);
  return v92;
}

struct StateT * slot_2(struct StateT * v40) {
  int v41 = v40->timer;
  int v54 = v41 + 1;
  v40->timer = v54;
  int * v43 = v40->reg_ready;
  int * v45 = v40->regs;
  int v46 = v45[5];
  int v48 = v45[9];
  bool v59 = v46 >= v48;
  struct StateT * v52;
  if (v59) {
    v52 = v40;
  } else {
    struct StateT * v50 = slot_3(v40);
    v52 = v50;
  }
  return v52;
}

struct StateT * slot_7(struct StateT * v628) {
  int v629 = v628->timer;
  int v640 = v629 + 1;
  v628->timer = v640;
  int * v631 = v628->reg_ready;
  int v632 = v631[11];
  int * v633 = v628->regs;
  int v634 = v633[11];
  int v644 = (v632 + ((v629 - v632) & (~((v629 - v632) >> 31)))) + 1;
  v631[11] = v644;
  int * v636 = v628->regs;
  int v646 = v634 << 2;
  v636[11] = v646;
  struct StateT * v638 = slot_8(v628);
  return v638;
}

struct StateT * slot_3(struct StateT * v63) {
  int v64 = v63->timer;
  int v75 = v64 + 1;
  v63->timer = v75;
  int * v66 = v63->reg_ready;
  int v67 = v66[5];
  int * v68 = v63->regs;
  int v69 = v68[5];
  int v80 = (v67 + ((v64 - v67) & (~((v64 - v67) >> 31)))) + 1;
  v66[6] = v80;
  int * v71 = v63->regs;
  int v82 = v69 + 80;
  v71[6] = v82;
  struct StateT * v73 = slot_4(v63);
  return v73;
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
  v5[5] = v19;
  int * v10 = v2->regs;
  int v21 = v8 & 28;
  v10[5] = v21;
  struct StateT * v12 = slot_1(v2);
  return v12;
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
    s1.mem[SECRET_OFFSET+i] = secret(0, 20);
    s2.mem[SECRET_OFFSET+i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}