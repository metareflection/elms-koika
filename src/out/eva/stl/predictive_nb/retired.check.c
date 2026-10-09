// verify: leak widened (the program is clean; Eva cannot prove it) [unroll 65]
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
struct StateT * slot_8(struct StateT * v599);
struct StateT * slot_6(struct StateT * v383);
struct StateT * slot_5(struct StateT * v375);
struct StateT * slot_4(struct StateT * v367);
struct StateT * slot_2(struct StateT * v45);
struct StateT * slot_7(struct StateT * v391);
struct StateT * slot_3(struct StateT * v359);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v804 = v1->timer;
  int * v805 = v1->reg_ready;
  int v806 = v805[0];
  int v937 = v806 + ((v804 - v806) & (~((v804 - v806) >> 31)));
  v1->timer = v937;
  int v808 = v1->timer;
  int * v809 = v1->reg_ready;
  int v810 = v809[1];
  int v940 = v810 + ((v808 - v810) & (~((v808 - v810) >> 31)));
  v1->timer = v940;
  int v812 = v1->timer;
  int * v813 = v1->reg_ready;
  int v814 = v813[2];
  int v943 = v814 + ((v812 - v814) & (~((v812 - v814) >> 31)));
  v1->timer = v943;
  int v816 = v1->timer;
  int * v817 = v1->reg_ready;
  int v818 = v817[3];
  int v946 = v818 + ((v816 - v818) & (~((v816 - v818) >> 31)));
  v1->timer = v946;
  int v820 = v1->timer;
  int * v821 = v1->reg_ready;
  int v822 = v821[4];
  int v949 = v822 + ((v820 - v822) & (~((v820 - v822) >> 31)));
  v1->timer = v949;
  int v824 = v1->timer;
  int * v825 = v1->reg_ready;
  int v826 = v825[5];
  int v952 = v826 + ((v824 - v826) & (~((v824 - v826) >> 31)));
  v1->timer = v952;
  int v828 = v1->timer;
  int * v829 = v1->reg_ready;
  int v830 = v829[6];
  int v955 = v830 + ((v828 - v830) & (~((v828 - v830) >> 31)));
  v1->timer = v955;
  int v832 = v1->timer;
  int * v833 = v1->reg_ready;
  int v834 = v833[7];
  int v958 = v834 + ((v832 - v834) & (~((v832 - v834) >> 31)));
  v1->timer = v958;
  int v836 = v1->timer;
  int * v837 = v1->reg_ready;
  int v838 = v837[8];
  int v961 = v838 + ((v836 - v838) & (~((v836 - v838) >> 31)));
  v1->timer = v961;
  int v840 = v1->timer;
  int * v841 = v1->reg_ready;
  int v842 = v841[9];
  int v964 = v842 + ((v840 - v842) & (~((v840 - v842) >> 31)));
  v1->timer = v964;
  int v844 = v1->timer;
  int * v845 = v1->reg_ready;
  int v846 = v845[10];
  int v967 = v846 + ((v844 - v846) & (~((v844 - v846) >> 31)));
  v1->timer = v967;
  int v848 = v1->timer;
  int * v849 = v1->reg_ready;
  int v850 = v849[11];
  int v970 = v850 + ((v848 - v850) & (~((v848 - v850) >> 31)));
  v1->timer = v970;
  int v852 = v1->timer;
  int * v853 = v1->reg_ready;
  int v854 = v853[12];
  int v973 = v854 + ((v852 - v854) & (~((v852 - v854) >> 31)));
  v1->timer = v973;
  int v856 = v1->timer;
  int * v857 = v1->reg_ready;
  int v858 = v857[13];
  int v976 = v858 + ((v856 - v858) & (~((v856 - v858) >> 31)));
  v1->timer = v976;
  int v860 = v1->timer;
  int * v861 = v1->reg_ready;
  int v862 = v861[14];
  int v979 = v862 + ((v860 - v862) & (~((v860 - v862) >> 31)));
  v1->timer = v979;
  int v864 = v1->timer;
  int * v865 = v1->reg_ready;
  int v866 = v865[15];
  int v982 = v866 + ((v864 - v866) & (~((v864 - v866) >> 31)));
  v1->timer = v982;
  int v868 = v1->timer;
  int * v869 = v1->reg_ready;
  int v870 = v869[16];
  int v985 = v870 + ((v868 - v870) & (~((v868 - v870) >> 31)));
  v1->timer = v985;
  int v872 = v1->timer;
  int * v873 = v1->reg_ready;
  int v874 = v873[17];
  int v988 = v874 + ((v872 - v874) & (~((v872 - v874) >> 31)));
  v1->timer = v988;
  int v876 = v1->timer;
  int * v877 = v1->reg_ready;
  int v878 = v877[18];
  int v991 = v878 + ((v876 - v878) & (~((v876 - v878) >> 31)));
  v1->timer = v991;
  int v880 = v1->timer;
  int * v881 = v1->reg_ready;
  int v882 = v881[19];
  int v994 = v882 + ((v880 - v882) & (~((v880 - v882) >> 31)));
  v1->timer = v994;
  int v884 = v1->timer;
  int * v885 = v1->reg_ready;
  int v886 = v885[20];
  int v997 = v886 + ((v884 - v886) & (~((v884 - v886) >> 31)));
  v1->timer = v997;
  int v888 = v1->timer;
  int * v889 = v1->reg_ready;
  int v890 = v889[21];
  int v1000 = v890 + ((v888 - v890) & (~((v888 - v890) >> 31)));
  v1->timer = v1000;
  int v892 = v1->timer;
  int * v893 = v1->reg_ready;
  int v894 = v893[22];
  int v1003 = v894 + ((v892 - v894) & (~((v892 - v894) >> 31)));
  v1->timer = v1003;
  int v896 = v1->timer;
  int * v897 = v1->reg_ready;
  int v898 = v897[23];
  int v1006 = v898 + ((v896 - v898) & (~((v896 - v898) >> 31)));
  v1->timer = v1006;
  int v900 = v1->timer;
  int * v901 = v1->reg_ready;
  int v902 = v901[24];
  int v1009 = v902 + ((v900 - v902) & (~((v900 - v902) >> 31)));
  v1->timer = v1009;
  int v904 = v1->timer;
  int * v905 = v1->reg_ready;
  int v906 = v905[25];
  int v1012 = v906 + ((v904 - v906) & (~((v904 - v906) >> 31)));
  v1->timer = v1012;
  int v908 = v1->timer;
  int * v909 = v1->reg_ready;
  int v910 = v909[26];
  int v1015 = v910 + ((v908 - v910) & (~((v908 - v910) >> 31)));
  v1->timer = v1015;
  int v912 = v1->timer;
  int * v913 = v1->reg_ready;
  int v914 = v913[27];
  int v1018 = v914 + ((v912 - v914) & (~((v912 - v914) >> 31)));
  v1->timer = v1018;
  int v916 = v1->timer;
  int * v917 = v1->reg_ready;
  int v918 = v917[28];
  int v1021 = v918 + ((v916 - v918) & (~((v916 - v918) >> 31)));
  v1->timer = v1021;
  int v920 = v1->timer;
  int * v921 = v1->reg_ready;
  int v922 = v921[29];
  int v1024 = v922 + ((v920 - v922) & (~((v920 - v922) >> 31)));
  v1->timer = v1024;
  int v924 = v1->timer;
  int * v925 = v1->reg_ready;
  int v926 = v925[30];
  int v1027 = v926 + ((v924 - v926) & (~((v924 - v926) >> 31)));
  v1->timer = v1027;
  int v928 = v1->timer;
  int * v929 = v1->reg_ready;
  int v930 = v929[31];
  int v1030 = v930 + ((v928 - v930) & (~((v928 - v930) >> 31)));
  v1->timer = v1030;
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

struct StateT * slot_8(struct StateT * v599) {
  int v600 = v599->timer;
  int v711 = v600 + 1;
  v599->timer = v711;
  int * v602 = v599->reg_ready;
  int v603 = v602[11];
  int * v604 = v599->regs;
  int v605 = v604[11];
  int * v606 = v599->cache_tags;
  int v716 = (((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1)) & 1) * 2;
  int v607 = v606[v716];
  int v717 = ((((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1)) & 1) * 2) + 1;
  int v608 = v606[v717];
  int v718 = 4 + ((((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1)) & 3) * 2);
  int v609 = v606[v718];
  int v719 = (4 + ((((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v610 = v606[v719];
  int * v611 = v599->cache_vals;
  bool v720 = !(((~(((v607 ^ ((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1))) | (-(v607 ^ ((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1))))) >> 31)) | (~(((v608 ^ ((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1))) | (-(v608 ^ ((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1))))) >> 31))) == 0);
  int v704;
  if (v720) {
    int * v612 = v599->cache_age;
    int v722 = ((((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1)) & 1) * 2) + ((~(((v608 ^ ((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1))) | (-(v608 ^ ((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1))))) >> 31)) & 1);
    int v613 = v612[v722];
    int v614 = v612[v716];
    int v723 = v614 + ((int)((unsigned int)(v614 - v613) >> 31));
    v612[v716] = v723;
    int * v616 = v599->cache_age;
    int v617 = v616[v717];
    int v725 = v617 + ((int)((unsigned int)(v617 - v613) >> 31));
    v616[v717] = v725;
    int * v619 = v599->cache_age;
    v619[v722] = 0;
    v704 = v722;
  } else {
    int * v622 = v599->cache_age;
    int v729 = (((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1)) & 1) * 2;
    int v623 = v622[v729];
    int * v624 = v599->cache_tags;
    int v625 = v624[v729];
    int v626 = v622[v717];
    int v627 = v624[v717];
    bool v731 = !(((~(((v609 ^ ((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1))) | (-(v609 ^ ((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1))))) >> 31)) | (~(((v610 ^ ((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1))) | (-(v610 ^ ((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1))))) >> 31))) == 0);
    int v681;
    if (v731) {
      int * v628 = v599->cache_age;
      int v733 = (4 + ((((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1)) & 3) * 2)) + ((~(((v610 ^ ((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1))) | (-(v610 ^ ((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1))))) >> 31)) & 1);
      int v629 = v628[v733];
      int v630 = v628[v718];
      int v734 = v630 + ((int)((unsigned int)(v630 - v629) >> 31));
      v628[v718] = v734;
      int * v632 = v599->cache_age;
      int v633 = v632[v719];
      int v736 = v633 + ((int)((unsigned int)(v633 - v629) >> 31));
      v632[v719] = v736;
      int * v635 = v599->cache_age;
      v635[v733] = 0;
      v681 = v733;
    } else {
      int * v638 = v599->cache_age;
      int v740 = 4 + ((((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1)) & 3) * 2);
      int v639 = v638[v740];
      int * v640 = v599->cache_tags;
      int v641 = v640[v740];
      int v642 = v638[v719];
      int v643 = v640[v719];
      int * v644 = v599->cache_dirty;
      int v743 = (4 + ((((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1)) & 3) * 2)) + ((((v639 + ((~(((v641 ^ -1) | (-(v641 ^ -1))) >> 31)) & 2)) - (v642 + ((~(((v643 ^ -1) | (-(v643 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v645 = v644[v743];
      bool v744 = !(v645 == 0);
      if (v744) {
        int * v646 = v599->cache_tags;
        int v647 = v646[v743];
        int * v648 = v599->cache_vals;
        int v747 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1)) & 3) * 2)) + ((((v639 + ((~(((v641 ^ -1) | (-(v641 ^ -1))) >> 31)) & 2)) - (v642 + ((~(((v643 ^ -1) | (-(v643 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v649 = v648[v747];
        int v748 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1)) & 3) * 2)) + ((((v639 + ((~(((v641 ^ -1) | (-(v641 ^ -1))) >> 31)) & 2)) - (v642 + ((~(((v643 ^ -1) | (-(v643 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v650 = v648[v748];
        int * v651 = v599->mem;
        int v750 = v647 * 2;
        v651[v750] = v649;
        int * v653 = v599->mem;
        int v753 = (v647 * 2) + 1;
        v653[v753] = v650;
        ;
      } else {
        ;
      }
      int * v658 = v599->mem;
      int v758 = ((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1)) * 2;
      int v659 = v658[v758];
      int v759 = (((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1)) * 2) + 1;
      int v660 = v658[v759];
      int * v661 = v599->cache_vals;
      int v761 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1)) & 3) * 2)) + ((((v639 + ((~(((v641 ^ -1) | (-(v641 ^ -1))) >> 31)) & 2)) - (v642 + ((~(((v643 ^ -1) | (-(v643 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v661[v761] = v659;
      int * v663 = v599->cache_vals;
      int v764 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1)) & 3) * 2)) + ((((v639 + ((~(((v641 ^ -1) | (-(v641 ^ -1))) >> 31)) & 2)) - (v642 + ((~(((v643 ^ -1) | (-(v643 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v663[v764] = v660;
      int * v665 = v599->cache_tags;
      int v767 = (int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1);
      v665[v743] = v767;
      int * v667 = v599->cache_dirty;
      v667[v743] = 0;
      int * v669 = v599->cache_age;
      v669[v743] = 1;
      int * v671 = v599->cache_age;
      int v672 = v671[v743];
      int v673 = v671[v718];
      int v773 = v673 + ((int)((unsigned int)(v673 - v672) >> 31));
      v671[v718] = v773;
      int * v675 = v599->cache_age;
      int v676 = v675[v719];
      int v775 = v676 + ((int)((unsigned int)(v676 - v672) >> 31));
      v675[v719] = v775;
      int * v678 = v599->cache_age;
      v678[v743] = 0;
      v681 = v743;
    }
    int * v682 = v599->cache_vals;
    int v778 = v681 * 2;
    int v683 = v682[v778];
    int v779 = (v681 * 2) + 1;
    int v684 = v682[v779];
    int v780 = (((((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1)) & 1) * 2) + ((((v623 + ((~(((v625 ^ -1) | (-(v625 ^ -1))) >> 31)) & 2)) - (v626 + ((~(((v627 ^ -1) | (-(v627 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v682[v780] = v683;
    int * v686 = v599->cache_vals;
    int v783 = ((((((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1)) & 1) * 2) + ((((v623 + ((~(((v625 ^ -1) | (-(v625 ^ -1))) >> 31)) & 2)) - (v626 + ((~(((v627 ^ -1) | (-(v627 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v686[v783] = v684;
    int * v688 = v599->cache_tags;
    int v786 = ((((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1)) & 1) * 2) + ((((v623 + ((~(((v625 ^ -1) | (-(v625 ^ -1))) >> 31)) & 2)) - (v626 + ((~(((v627 ^ -1) | (-(v627 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v787 = (int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1);
    v688[v786] = v787;
    int * v690 = v599->cache_dirty;
    v690[v786] = 0;
    int * v692 = v599->cache_age;
    v692[v786] = 1;
    int * v694 = v599->cache_age;
    int v695 = v694[v786];
    int v696 = v694[v716];
    int v793 = v696 + ((int)((unsigned int)(v696 - v695) >> 31));
    v694[v716] = v793;
    int * v698 = v599->cache_age;
    int v699 = v698[v717];
    int v795 = v699 + ((int)((unsigned int)(v699 - v695) >> 31));
    v698[v717] = v795;
    int * v701 = v599->cache_age;
    v701[v786] = 0;
    v704 = v786;
  }
  int v798 = (v704 * 2) + (((int)((unsigned int)v605 >> 2)) & 1);
  int v705 = v611[v798];
  int * v706 = v599->reg_ready;
  int v801 = ((v603 + ((v600 - v603) & (~((v600 - v603) >> 31)))) + 1) + ((100 ^ (((~(((v609 ^ ((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1))) | (-(v609 ^ ((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1))))) >> 31)) | (~(((v610 ^ ((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1))) | (-(v610 ^ ((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v607 ^ ((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1))) | (-(v607 ^ ((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1))))) >> 31)) | (~(((v608 ^ ((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1))) | (-(v608 ^ ((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v609 ^ ((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1))) | (-(v609 ^ ((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1))))) >> 31)) | (~(((v610 ^ ((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1))) | (-(v610 ^ ((int)((unsigned int)((int)((unsigned int)v605 >> 2)) >> 1))))) >> 31))) & 104)))));
  v706[12] = v801;
  int * v708 = v599->regs;
  v708[12] = v705;
  return v599;
}

struct StateT * slot_6(struct StateT * v383) {
  int v384 = v383->timer;
  int v388 = v384 + 1;
  v383->timer = v388;
  struct StateT * v386 = slot_7(v383);
  return v386;
}

struct StateT * slot_5(struct StateT * v375) {
  int v376 = v375->timer;
  int v380 = v376 + 1;
  v375->timer = v380;
  struct StateT * v378 = slot_6(v375);
  return v378;
}

struct StateT * slot_4(struct StateT * v367) {
  int v368 = v367->timer;
  int v372 = v368 + 1;
  v367->timer = v372;
  struct StateT * v370 = slot_5(v367);
  return v370;
}

struct StateT * slot_2(struct StateT * v45) {
  int v46 = v45->timer;
  int v217 = v46 + 1;
  v45->timer = v217;
  int * v48 = v45->reg_ready;
  int * v50 = v45->regs;
  int v51 = v50[6];
  int * v52 = v45->cache_tags;
  int v222 = (((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 1) * 2;
  int v53 = v52[v222];
  int v223 = ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 1) * 2) + 1;
  int v54 = v52[v223];
  int v224 = 4 + ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 3) * 2);
  int v55 = v52[v224];
  int v225 = (4 + ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v56 = v52[v225];
  int v57 = v45->timer;
  int v226 = v57 + ((100 ^ (((~(((v55 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v55 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31)) | (~(((v56 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v56 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v53 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v53 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31)) | (~(((v54 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v54 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v55 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v55 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31)) | (~(((v56 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v56 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31))) & 104)))));
  v45->timer = v226;
  bool v227 = !(((~(((v53 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v53 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31)) | (~(((v54 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v54 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31))) == 0);
  int v151;
  if (v227) {
    int * v59 = v45->cache_age;
    int v229 = ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 1) * 2) + ((~(((v54 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v54 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31)) & 1);
    int v60 = v59[v229];
    int v61 = v59[v222];
    int v230 = v61 + ((int)((unsigned int)(v61 - v60) >> 31));
    v59[v222] = v230;
    int * v63 = v45->cache_age;
    int v64 = v63[v223];
    int v232 = v64 + ((int)((unsigned int)(v64 - v60) >> 31));
    v63[v223] = v232;
    int * v66 = v45->cache_age;
    v66[v229] = 0;
    v151 = v229;
  } else {
    int * v69 = v45->cache_age;
    int v236 = (((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 1) * 2;
    int v70 = v69[v236];
    int * v71 = v45->cache_tags;
    int v72 = v71[v236];
    int v73 = v69[v223];
    int v74 = v71[v223];
    bool v238 = !(((~(((v55 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v55 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31)) | (~(((v56 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v56 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31))) == 0);
    int v128;
    if (v238) {
      int * v75 = v45->cache_age;
      int v240 = (4 + ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 3) * 2)) + ((~(((v56 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v56 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31)) & 1);
      int v76 = v75[v240];
      int v77 = v75[v224];
      int v241 = v77 + ((int)((unsigned int)(v77 - v76) >> 31));
      v75[v224] = v241;
      int * v79 = v45->cache_age;
      int v80 = v79[v225];
      int v243 = v80 + ((int)((unsigned int)(v80 - v76) >> 31));
      v79[v225] = v243;
      int * v82 = v45->cache_age;
      v82[v240] = 0;
      v128 = v240;
    } else {
      int * v85 = v45->cache_age;
      int v247 = 4 + ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 3) * 2);
      int v86 = v85[v247];
      int * v87 = v45->cache_tags;
      int v88 = v87[v247];
      int v89 = v85[v225];
      int v90 = v87[v225];
      int * v91 = v45->cache_dirty;
      int v250 = (4 + ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 3) * 2)) + ((((v86 + ((~(((v88 ^ -1) | (-(v88 ^ -1))) >> 31)) & 2)) - (v89 + ((~(((v90 ^ -1) | (-(v90 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v92 = v91[v250];
      bool v251 = !(v92 == 0);
      if (v251) {
        int * v93 = v45->cache_tags;
        int v94 = v93[v250];
        int * v95 = v45->cache_vals;
        int v254 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 3) * 2)) + ((((v86 + ((~(((v88 ^ -1) | (-(v88 ^ -1))) >> 31)) & 2)) - (v89 + ((~(((v90 ^ -1) | (-(v90 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v96 = v95[v254];
        int v255 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 3) * 2)) + ((((v86 + ((~(((v88 ^ -1) | (-(v88 ^ -1))) >> 31)) & 2)) - (v89 + ((~(((v90 ^ -1) | (-(v90 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v97 = v95[v255];
        int * v98 = v45->mem;
        int v257 = v94 * 2;
        v98[v257] = v96;
        int * v100 = v45->mem;
        int v260 = (v94 * 2) + 1;
        v100[v260] = v97;
        ;
      } else {
        ;
      }
      int * v105 = v45->mem;
      int v265 = ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) * 2;
      int v106 = v105[v265];
      int v266 = (((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) * 2) + 1;
      int v107 = v105[v266];
      int * v108 = v45->cache_vals;
      int v268 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 3) * 2)) + ((((v86 + ((~(((v88 ^ -1) | (-(v88 ^ -1))) >> 31)) & 2)) - (v89 + ((~(((v90 ^ -1) | (-(v90 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v108[v268] = v106;
      int * v110 = v45->cache_vals;
      int v271 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 3) * 2)) + ((((v86 + ((~(((v88 ^ -1) | (-(v88 ^ -1))) >> 31)) & 2)) - (v89 + ((~(((v90 ^ -1) | (-(v90 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v110[v271] = v107;
      int * v112 = v45->cache_tags;
      int v274 = (int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1);
      v112[v250] = v274;
      int * v114 = v45->cache_dirty;
      v114[v250] = 0;
      int * v116 = v45->cache_age;
      v116[v250] = 1;
      int * v118 = v45->cache_age;
      int v119 = v118[v250];
      int v120 = v118[v224];
      int v280 = v120 + ((int)((unsigned int)(v120 - v119) >> 31));
      v118[v224] = v280;
      int * v122 = v45->cache_age;
      int v123 = v122[v225];
      int v282 = v123 + ((int)((unsigned int)(v123 - v119) >> 31));
      v122[v225] = v282;
      int * v125 = v45->cache_age;
      v125[v250] = 0;
      v128 = v250;
    }
    int * v129 = v45->cache_vals;
    int v285 = v128 * 2;
    int v130 = v129[v285];
    int v286 = (v128 * 2) + 1;
    int v131 = v129[v286];
    int v287 = (((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 1) * 2) + ((((v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2)) - (v73 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v129[v287] = v130;
    int * v133 = v45->cache_vals;
    int v290 = ((((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 1) * 2) + ((((v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2)) - (v73 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v133[v290] = v131;
    int * v135 = v45->cache_tags;
    int v293 = ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 1) * 2) + ((((v70 + ((~(((v72 ^ -1) | (-(v72 ^ -1))) >> 31)) & 2)) - (v73 + ((~(((v74 ^ -1) | (-(v74 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v294 = (int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1);
    v135[v293] = v294;
    int * v137 = v45->cache_dirty;
    v137[v293] = 0;
    int * v139 = v45->cache_age;
    v139[v293] = 1;
    int * v141 = v45->cache_age;
    int v142 = v141[v293];
    int v143 = v141[v222];
    int v300 = v143 + ((int)((unsigned int)(v143 - v142) >> 31));
    v141[v222] = v300;
    int * v145 = v45->cache_age;
    int v146 = v145[v223];
    int v302 = v146 + ((int)((unsigned int)(v146 - v142) >> 31));
    v145[v223] = v302;
    int * v148 = v45->cache_age;
    v148[v293] = 0;
    v151 = v293;
  }
  int * v152 = v45->cache_vals;
  int v305 = (v151 * 2) + (((int)((unsigned int)v51 >> 2)) & 1);
  v152[v305] = 0;
  int * v154 = v45->cache_tags;
  int v155 = v154[v224];
  int v156 = v154[v225];
  bool v308 = !(((~(((v155 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v155 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31)) | (~(((v156 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v156 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31))) == 0);
  int v210;
  if (v308) {
    int * v157 = v45->cache_age;
    int v310 = (4 + ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 3) * 2)) + ((~(((v156 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))) | (-(v156 ^ ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1))))) >> 31)) & 1);
    int v158 = v157[v310];
    int v159 = v157[v224];
    int v311 = v159 + ((int)((unsigned int)(v159 - v158) >> 31));
    v157[v224] = v311;
    int * v161 = v45->cache_age;
    int v162 = v161[v225];
    int v313 = v162 + ((int)((unsigned int)(v162 - v158) >> 31));
    v161[v225] = v313;
    int * v164 = v45->cache_age;
    v164[v310] = 0;
    v210 = v310;
  } else {
    int * v167 = v45->cache_age;
    int v316 = 4 + ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 3) * 2);
    int v168 = v167[v316];
    int * v169 = v45->cache_tags;
    int v170 = v169[v316];
    int v171 = v167[v225];
    int v172 = v169[v225];
    int * v173 = v45->cache_dirty;
    int v319 = (4 + ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 3) * 2)) + ((((v168 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2)) - (v171 + ((~(((v172 ^ -1) | (-(v172 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v174 = v173[v319];
    bool v320 = !(v174 == 0);
    if (v320) {
      int * v175 = v45->cache_tags;
      int v176 = v175[v319];
      int * v177 = v45->cache_vals;
      int v323 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 3) * 2)) + ((((v168 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2)) - (v171 + ((~(((v172 ^ -1) | (-(v172 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v178 = v177[v323];
      int v324 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 3) * 2)) + ((((v168 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2)) - (v171 + ((~(((v172 ^ -1) | (-(v172 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v179 = v177[v324];
      int * v180 = v45->mem;
      int v326 = v176 * 2;
      v180[v326] = v178;
      int * v182 = v45->mem;
      int v329 = (v176 * 2) + 1;
      v182[v329] = v179;
      ;
    } else {
      ;
    }
    int * v187 = v45->mem;
    int v334 = ((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) * 2;
    int v188 = v187[v334];
    int v335 = (((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) * 2) + 1;
    int v189 = v187[v335];
    int * v190 = v45->cache_vals;
    int v337 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 3) * 2)) + ((((v168 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2)) - (v171 + ((~(((v172 ^ -1) | (-(v172 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v190[v337] = v188;
    int * v192 = v45->cache_vals;
    int v340 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1)) & 3) * 2)) + ((((v168 + ((~(((v170 ^ -1) | (-(v170 ^ -1))) >> 31)) & 2)) - (v171 + ((~(((v172 ^ -1) | (-(v172 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v192[v340] = v189;
    int * v194 = v45->cache_tags;
    int v343 = (int)((unsigned int)((int)((unsigned int)v51 >> 2)) >> 1);
    v194[v319] = v343;
    int * v196 = v45->cache_dirty;
    v196[v319] = 0;
    int * v198 = v45->cache_age;
    v198[v319] = 1;
    int * v200 = v45->cache_age;
    int v201 = v200[v319];
    int v202 = v200[v224];
    int v348 = v202 + ((int)((unsigned int)(v202 - v201) >> 31));
    v200[v224] = v348;
    int * v204 = v45->cache_age;
    int v205 = v204[v225];
    int v350 = v205 + ((int)((unsigned int)(v205 - v201) >> 31));
    v204[v225] = v350;
    int * v207 = v45->cache_age;
    v207[v319] = 0;
    v210 = v319;
  }
  int * v211 = v45->cache_vals;
  int v353 = (v210 * 2) + (((int)((unsigned int)v51 >> 2)) & 1);
  v211[v353] = 0;
  int * v213 = v45->cache_dirty;
  v213[v210] = 1;
  struct StateT * v215 = slot_3(v45);
  return v215;
}

struct StateT * slot_7(struct StateT * v391) {
  int v392 = v391->timer;
  int v504 = v392 + 1;
  v391->timer = v504;
  int * v394 = v391->reg_ready;
  int v395 = v394[6];
  int * v396 = v391->regs;
  int v397 = v396[6];
  int * v398 = v391->cache_tags;
  int v509 = (((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1)) & 1) * 2;
  int v399 = v398[v509];
  int v510 = ((((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1)) & 1) * 2) + 1;
  int v400 = v398[v510];
  int v511 = 4 + ((((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1)) & 3) * 2);
  int v401 = v398[v511];
  int v512 = (4 + ((((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v402 = v398[v512];
  int * v403 = v391->cache_vals;
  bool v513 = !(((~(((v399 ^ ((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1))) | (-(v399 ^ ((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1))))) >> 31)) | (~(((v400 ^ ((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1))) | (-(v400 ^ ((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1))))) >> 31))) == 0);
  int v496;
  if (v513) {
    int * v404 = v391->cache_age;
    int v515 = ((((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1)) & 1) * 2) + ((~(((v400 ^ ((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1))) | (-(v400 ^ ((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1))))) >> 31)) & 1);
    int v405 = v404[v515];
    int v406 = v404[v509];
    int v516 = v406 + ((int)((unsigned int)(v406 - v405) >> 31));
    v404[v509] = v516;
    int * v408 = v391->cache_age;
    int v409 = v408[v510];
    int v518 = v409 + ((int)((unsigned int)(v409 - v405) >> 31));
    v408[v510] = v518;
    int * v411 = v391->cache_age;
    v411[v515] = 0;
    v496 = v515;
  } else {
    int * v414 = v391->cache_age;
    int v522 = (((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1)) & 1) * 2;
    int v415 = v414[v522];
    int * v416 = v391->cache_tags;
    int v417 = v416[v522];
    int v418 = v414[v510];
    int v419 = v416[v510];
    bool v524 = !(((~(((v401 ^ ((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1))) | (-(v401 ^ ((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1))))) >> 31)) | (~(((v402 ^ ((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1))) | (-(v402 ^ ((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1))))) >> 31))) == 0);
    int v473;
    if (v524) {
      int * v420 = v391->cache_age;
      int v526 = (4 + ((((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1)) & 3) * 2)) + ((~(((v402 ^ ((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1))) | (-(v402 ^ ((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1))))) >> 31)) & 1);
      int v421 = v420[v526];
      int v422 = v420[v511];
      int v527 = v422 + ((int)((unsigned int)(v422 - v421) >> 31));
      v420[v511] = v527;
      int * v424 = v391->cache_age;
      int v425 = v424[v512];
      int v529 = v425 + ((int)((unsigned int)(v425 - v421) >> 31));
      v424[v512] = v529;
      int * v427 = v391->cache_age;
      v427[v526] = 0;
      v473 = v526;
    } else {
      int * v430 = v391->cache_age;
      int v533 = 4 + ((((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1)) & 3) * 2);
      int v431 = v430[v533];
      int * v432 = v391->cache_tags;
      int v433 = v432[v533];
      int v434 = v430[v512];
      int v435 = v432[v512];
      int * v436 = v391->cache_dirty;
      int v536 = (4 + ((((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1)) & 3) * 2)) + ((((v431 + ((~(((v433 ^ -1) | (-(v433 ^ -1))) >> 31)) & 2)) - (v434 + ((~(((v435 ^ -1) | (-(v435 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v437 = v436[v536];
      bool v537 = !(v437 == 0);
      if (v537) {
        int * v438 = v391->cache_tags;
        int v439 = v438[v536];
        int * v440 = v391->cache_vals;
        int v540 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1)) & 3) * 2)) + ((((v431 + ((~(((v433 ^ -1) | (-(v433 ^ -1))) >> 31)) & 2)) - (v434 + ((~(((v435 ^ -1) | (-(v435 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v441 = v440[v540];
        int v541 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1)) & 3) * 2)) + ((((v431 + ((~(((v433 ^ -1) | (-(v433 ^ -1))) >> 31)) & 2)) - (v434 + ((~(((v435 ^ -1) | (-(v435 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v442 = v440[v541];
        int * v443 = v391->mem;
        int v543 = v439 * 2;
        v443[v543] = v441;
        int * v445 = v391->mem;
        int v546 = (v439 * 2) + 1;
        v445[v546] = v442;
        ;
      } else {
        ;
      }
      int * v450 = v391->mem;
      int v551 = ((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1)) * 2;
      int v451 = v450[v551];
      int v552 = (((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1)) * 2) + 1;
      int v452 = v450[v552];
      int * v453 = v391->cache_vals;
      int v554 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1)) & 3) * 2)) + ((((v431 + ((~(((v433 ^ -1) | (-(v433 ^ -1))) >> 31)) & 2)) - (v434 + ((~(((v435 ^ -1) | (-(v435 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v453[v554] = v451;
      int * v455 = v391->cache_vals;
      int v557 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1)) & 3) * 2)) + ((((v431 + ((~(((v433 ^ -1) | (-(v433 ^ -1))) >> 31)) & 2)) - (v434 + ((~(((v435 ^ -1) | (-(v435 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v455[v557] = v452;
      int * v457 = v391->cache_tags;
      int v560 = (int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1);
      v457[v536] = v560;
      int * v459 = v391->cache_dirty;
      v459[v536] = 0;
      int * v461 = v391->cache_age;
      v461[v536] = 1;
      int * v463 = v391->cache_age;
      int v464 = v463[v536];
      int v465 = v463[v511];
      int v566 = v465 + ((int)((unsigned int)(v465 - v464) >> 31));
      v463[v511] = v566;
      int * v467 = v391->cache_age;
      int v468 = v467[v512];
      int v568 = v468 + ((int)((unsigned int)(v468 - v464) >> 31));
      v467[v512] = v568;
      int * v470 = v391->cache_age;
      v470[v536] = 0;
      v473 = v536;
    }
    int * v474 = v391->cache_vals;
    int v571 = v473 * 2;
    int v475 = v474[v571];
    int v572 = (v473 * 2) + 1;
    int v476 = v474[v572];
    int v573 = (((((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1)) & 1) * 2) + ((((v415 + ((~(((v417 ^ -1) | (-(v417 ^ -1))) >> 31)) & 2)) - (v418 + ((~(((v419 ^ -1) | (-(v419 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v474[v573] = v475;
    int * v478 = v391->cache_vals;
    int v576 = ((((((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1)) & 1) * 2) + ((((v415 + ((~(((v417 ^ -1) | (-(v417 ^ -1))) >> 31)) & 2)) - (v418 + ((~(((v419 ^ -1) | (-(v419 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v478[v576] = v476;
    int * v480 = v391->cache_tags;
    int v579 = ((((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1)) & 1) * 2) + ((((v415 + ((~(((v417 ^ -1) | (-(v417 ^ -1))) >> 31)) & 2)) - (v418 + ((~(((v419 ^ -1) | (-(v419 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v580 = (int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1);
    v480[v579] = v580;
    int * v482 = v391->cache_dirty;
    v482[v579] = 0;
    int * v484 = v391->cache_age;
    v484[v579] = 1;
    int * v486 = v391->cache_age;
    int v487 = v486[v579];
    int v488 = v486[v509];
    int v586 = v488 + ((int)((unsigned int)(v488 - v487) >> 31));
    v486[v509] = v586;
    int * v490 = v391->cache_age;
    int v491 = v490[v510];
    int v588 = v491 + ((int)((unsigned int)(v491 - v487) >> 31));
    v490[v510] = v588;
    int * v493 = v391->cache_age;
    v493[v579] = 0;
    v496 = v579;
  }
  int v591 = (v496 * 2) + (((int)((unsigned int)v397 >> 2)) & 1);
  int v497 = v403[v591];
  int * v498 = v391->reg_ready;
  int v594 = ((v395 + ((v392 - v395) & (~((v392 - v395) >> 31)))) + 1) + ((100 ^ (((~(((v401 ^ ((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1))) | (-(v401 ^ ((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1))))) >> 31)) | (~(((v402 ^ ((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1))) | (-(v402 ^ ((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v399 ^ ((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1))) | (-(v399 ^ ((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1))))) >> 31)) | (~(((v400 ^ ((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1))) | (-(v400 ^ ((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v401 ^ ((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1))) | (-(v401 ^ ((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1))))) >> 31)) | (~(((v402 ^ ((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1))) | (-(v402 ^ ((int)((unsigned int)((int)((unsigned int)v397 >> 2)) >> 1))))) >> 31))) & 104)))));
  v498[11] = v594;
  int * v500 = v391->regs;
  v500[11] = v497;
  struct StateT * v502 = slot_8(v391);
  return v502;
}

struct StateT * slot_3(struct StateT * v359) {
  int v360 = v359->timer;
  int v364 = v360 + 1;
  v359->timer = v364;
  struct StateT * v362 = slot_4(v359);
  return v362;
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