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

struct StateT * snippet(struct StateT * v0);
struct StateT * slot_1(struct StateT * v24);
struct StateT * slot_4(struct StateT * v567);
struct StateT * slot_2(struct StateT * v45);
struct StateT * slot_3(struct StateT * v359);
struct StateT * slot_0(struct StateT * v2);
struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  int v772 = v1->timer;
  int * v773 = v1->reg_ready;
  int v774 = v773[0];
  int v905 = v774 + ((v772 - v774) & (~((v772 - v774) >> 31)));
  v1->timer = v905;
  int v776 = v1->timer;
  int * v777 = v1->reg_ready;
  int v778 = v777[1];
  int v908 = v778 + ((v776 - v778) & (~((v776 - v778) >> 31)));
  v1->timer = v908;
  int v780 = v1->timer;
  int * v781 = v1->reg_ready;
  int v782 = v781[2];
  int v911 = v782 + ((v780 - v782) & (~((v780 - v782) >> 31)));
  v1->timer = v911;
  int v784 = v1->timer;
  int * v785 = v1->reg_ready;
  int v786 = v785[3];
  int v914 = v786 + ((v784 - v786) & (~((v784 - v786) >> 31)));
  v1->timer = v914;
  int v788 = v1->timer;
  int * v789 = v1->reg_ready;
  int v790 = v789[4];
  int v917 = v790 + ((v788 - v790) & (~((v788 - v790) >> 31)));
  v1->timer = v917;
  int v792 = v1->timer;
  int * v793 = v1->reg_ready;
  int v794 = v793[5];
  int v920 = v794 + ((v792 - v794) & (~((v792 - v794) >> 31)));
  v1->timer = v920;
  int v796 = v1->timer;
  int * v797 = v1->reg_ready;
  int v798 = v797[6];
  int v923 = v798 + ((v796 - v798) & (~((v796 - v798) >> 31)));
  v1->timer = v923;
  int v800 = v1->timer;
  int * v801 = v1->reg_ready;
  int v802 = v801[7];
  int v926 = v802 + ((v800 - v802) & (~((v800 - v802) >> 31)));
  v1->timer = v926;
  int v804 = v1->timer;
  int * v805 = v1->reg_ready;
  int v806 = v805[8];
  int v929 = v806 + ((v804 - v806) & (~((v804 - v806) >> 31)));
  v1->timer = v929;
  int v808 = v1->timer;
  int * v809 = v1->reg_ready;
  int v810 = v809[9];
  int v932 = v810 + ((v808 - v810) & (~((v808 - v810) >> 31)));
  v1->timer = v932;
  int v812 = v1->timer;
  int * v813 = v1->reg_ready;
  int v814 = v813[10];
  int v935 = v814 + ((v812 - v814) & (~((v812 - v814) >> 31)));
  v1->timer = v935;
  int v816 = v1->timer;
  int * v817 = v1->reg_ready;
  int v818 = v817[11];
  int v938 = v818 + ((v816 - v818) & (~((v816 - v818) >> 31)));
  v1->timer = v938;
  int v820 = v1->timer;
  int * v821 = v1->reg_ready;
  int v822 = v821[12];
  int v941 = v822 + ((v820 - v822) & (~((v820 - v822) >> 31)));
  v1->timer = v941;
  int v824 = v1->timer;
  int * v825 = v1->reg_ready;
  int v826 = v825[13];
  int v944 = v826 + ((v824 - v826) & (~((v824 - v826) >> 31)));
  v1->timer = v944;
  int v828 = v1->timer;
  int * v829 = v1->reg_ready;
  int v830 = v829[14];
  int v947 = v830 + ((v828 - v830) & (~((v828 - v830) >> 31)));
  v1->timer = v947;
  int v832 = v1->timer;
  int * v833 = v1->reg_ready;
  int v834 = v833[15];
  int v950 = v834 + ((v832 - v834) & (~((v832 - v834) >> 31)));
  v1->timer = v950;
  int v836 = v1->timer;
  int * v837 = v1->reg_ready;
  int v838 = v837[16];
  int v953 = v838 + ((v836 - v838) & (~((v836 - v838) >> 31)));
  v1->timer = v953;
  int v840 = v1->timer;
  int * v841 = v1->reg_ready;
  int v842 = v841[17];
  int v956 = v842 + ((v840 - v842) & (~((v840 - v842) >> 31)));
  v1->timer = v956;
  int v844 = v1->timer;
  int * v845 = v1->reg_ready;
  int v846 = v845[18];
  int v959 = v846 + ((v844 - v846) & (~((v844 - v846) >> 31)));
  v1->timer = v959;
  int v848 = v1->timer;
  int * v849 = v1->reg_ready;
  int v850 = v849[19];
  int v962 = v850 + ((v848 - v850) & (~((v848 - v850) >> 31)));
  v1->timer = v962;
  int v852 = v1->timer;
  int * v853 = v1->reg_ready;
  int v854 = v853[20];
  int v965 = v854 + ((v852 - v854) & (~((v852 - v854) >> 31)));
  v1->timer = v965;
  int v856 = v1->timer;
  int * v857 = v1->reg_ready;
  int v858 = v857[21];
  int v968 = v858 + ((v856 - v858) & (~((v856 - v858) >> 31)));
  v1->timer = v968;
  int v860 = v1->timer;
  int * v861 = v1->reg_ready;
  int v862 = v861[22];
  int v971 = v862 + ((v860 - v862) & (~((v860 - v862) >> 31)));
  v1->timer = v971;
  int v864 = v1->timer;
  int * v865 = v1->reg_ready;
  int v866 = v865[23];
  int v974 = v866 + ((v864 - v866) & (~((v864 - v866) >> 31)));
  v1->timer = v974;
  int v868 = v1->timer;
  int * v869 = v1->reg_ready;
  int v870 = v869[24];
  int v977 = v870 + ((v868 - v870) & (~((v868 - v870) >> 31)));
  v1->timer = v977;
  int v872 = v1->timer;
  int * v873 = v1->reg_ready;
  int v874 = v873[25];
  int v980 = v874 + ((v872 - v874) & (~((v872 - v874) >> 31)));
  v1->timer = v980;
  int v876 = v1->timer;
  int * v877 = v1->reg_ready;
  int v878 = v877[26];
  int v983 = v878 + ((v876 - v878) & (~((v876 - v878) >> 31)));
  v1->timer = v983;
  int v880 = v1->timer;
  int * v881 = v1->reg_ready;
  int v882 = v881[27];
  int v986 = v882 + ((v880 - v882) & (~((v880 - v882) >> 31)));
  v1->timer = v986;
  int v884 = v1->timer;
  int * v885 = v1->reg_ready;
  int v886 = v885[28];
  int v989 = v886 + ((v884 - v886) & (~((v884 - v886) >> 31)));
  v1->timer = v989;
  int v888 = v1->timer;
  int * v889 = v1->reg_ready;
  int v890 = v889[29];
  int v992 = v890 + ((v888 - v890) & (~((v888 - v890) >> 31)));
  v1->timer = v992;
  int v892 = v1->timer;
  int * v893 = v1->reg_ready;
  int v894 = v893[30];
  int v995 = v894 + ((v892 - v894) & (~((v892 - v894) >> 31)));
  v1->timer = v995;
  int v896 = v1->timer;
  int * v897 = v1->reg_ready;
  int v898 = v897[31];
  int v998 = v898 + ((v896 - v898) & (~((v896 - v898) >> 31)));
  v1->timer = v998;
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

struct StateT * slot_4(struct StateT * v567) {
  int v568 = v567->timer;
  int v679 = v568 + 1;
  v567->timer = v679;
  int * v570 = v567->reg_ready;
  int v571 = v570[11];
  int * v572 = v567->regs;
  int v573 = v572[11];
  int * v574 = v567->cache_tags;
  int v684 = (((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1)) & 1) * 2;
  int v575 = v574[v684];
  int v685 = ((((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1)) & 1) * 2) + 1;
  int v576 = v574[v685];
  int v686 = 4 + ((((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1)) & 3) * 2);
  int v577 = v574[v686];
  int v687 = (4 + ((((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v578 = v574[v687];
  int * v579 = v567->cache_vals;
  bool v688 = !(((~(((v575 ^ ((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1))) | (-(v575 ^ ((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1))))) >> 31)) | (~(((v576 ^ ((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1))) | (-(v576 ^ ((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1))))) >> 31))) == 0);
  int v672;
  if (v688) {
    int * v580 = v567->cache_age;
    int v690 = ((((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1)) & 1) * 2) + ((~(((v576 ^ ((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1))) | (-(v576 ^ ((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1))))) >> 31)) & 1);
    int v581 = v580[v690];
    int v582 = v580[v684];
    int v691 = v582 + ((int)((unsigned int)(v582 - v581) >> 31));
    v580[v684] = v691;
    int * v584 = v567->cache_age;
    int v585 = v584[v685];
    int v693 = v585 + ((int)((unsigned int)(v585 - v581) >> 31));
    v584[v685] = v693;
    int * v587 = v567->cache_age;
    v587[v690] = 0;
    v672 = v690;
  } else {
    int * v590 = v567->cache_age;
    int v697 = (((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1)) & 1) * 2;
    int v591 = v590[v697];
    int * v592 = v567->cache_tags;
    int v593 = v592[v697];
    int v594 = v590[v685];
    int v595 = v592[v685];
    bool v699 = !(((~(((v577 ^ ((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1))) | (-(v577 ^ ((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1))))) >> 31)) | (~(((v578 ^ ((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1))) | (-(v578 ^ ((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1))))) >> 31))) == 0);
    int v649;
    if (v699) {
      int * v596 = v567->cache_age;
      int v701 = (4 + ((((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1)) & 3) * 2)) + ((~(((v578 ^ ((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1))) | (-(v578 ^ ((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1))))) >> 31)) & 1);
      int v597 = v596[v701];
      int v598 = v596[v686];
      int v702 = v598 + ((int)((unsigned int)(v598 - v597) >> 31));
      v596[v686] = v702;
      int * v600 = v567->cache_age;
      int v601 = v600[v687];
      int v704 = v601 + ((int)((unsigned int)(v601 - v597) >> 31));
      v600[v687] = v704;
      int * v603 = v567->cache_age;
      v603[v701] = 0;
      v649 = v701;
    } else {
      int * v606 = v567->cache_age;
      int v708 = 4 + ((((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1)) & 3) * 2);
      int v607 = v606[v708];
      int * v608 = v567->cache_tags;
      int v609 = v608[v708];
      int v610 = v606[v687];
      int v611 = v608[v687];
      int * v612 = v567->cache_dirty;
      int v711 = (4 + ((((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1)) & 3) * 2)) + ((((v607 + ((~(((v609 ^ -1) | (-(v609 ^ -1))) >> 31)) & 2)) - (v610 + ((~(((v611 ^ -1) | (-(v611 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v613 = v612[v711];
      bool v712 = !(v613 == 0);
      if (v712) {
        int * v614 = v567->cache_tags;
        int v615 = v614[v711];
        int * v616 = v567->cache_vals;
        int v715 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1)) & 3) * 2)) + ((((v607 + ((~(((v609 ^ -1) | (-(v609 ^ -1))) >> 31)) & 2)) - (v610 + ((~(((v611 ^ -1) | (-(v611 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v617 = v616[v715];
        int v716 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1)) & 3) * 2)) + ((((v607 + ((~(((v609 ^ -1) | (-(v609 ^ -1))) >> 31)) & 2)) - (v610 + ((~(((v611 ^ -1) | (-(v611 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v618 = v616[v716];
        int * v619 = v567->mem;
        int v718 = v615 * 2;
        v619[v718] = v617;
        int * v621 = v567->mem;
        int v721 = (v615 * 2) + 1;
        v621[v721] = v618;
        ;
      } else {
        ;
      }
      int * v626 = v567->mem;
      int v726 = ((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1)) * 2;
      int v627 = v626[v726];
      int v727 = (((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1)) * 2) + 1;
      int v628 = v626[v727];
      int * v629 = v567->cache_vals;
      int v729 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1)) & 3) * 2)) + ((((v607 + ((~(((v609 ^ -1) | (-(v609 ^ -1))) >> 31)) & 2)) - (v610 + ((~(((v611 ^ -1) | (-(v611 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v629[v729] = v627;
      int * v631 = v567->cache_vals;
      int v732 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1)) & 3) * 2)) + ((((v607 + ((~(((v609 ^ -1) | (-(v609 ^ -1))) >> 31)) & 2)) - (v610 + ((~(((v611 ^ -1) | (-(v611 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v631[v732] = v628;
      int * v633 = v567->cache_tags;
      int v735 = (int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1);
      v633[v711] = v735;
      int * v635 = v567->cache_dirty;
      v635[v711] = 0;
      int * v637 = v567->cache_age;
      v637[v711] = 1;
      int * v639 = v567->cache_age;
      int v640 = v639[v711];
      int v641 = v639[v686];
      int v741 = v641 + ((int)((unsigned int)(v641 - v640) >> 31));
      v639[v686] = v741;
      int * v643 = v567->cache_age;
      int v644 = v643[v687];
      int v743 = v644 + ((int)((unsigned int)(v644 - v640) >> 31));
      v643[v687] = v743;
      int * v646 = v567->cache_age;
      v646[v711] = 0;
      v649 = v711;
    }
    int * v650 = v567->cache_vals;
    int v746 = v649 * 2;
    int v651 = v650[v746];
    int v747 = (v649 * 2) + 1;
    int v652 = v650[v747];
    int v748 = (((((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1)) & 1) * 2) + ((((v591 + ((~(((v593 ^ -1) | (-(v593 ^ -1))) >> 31)) & 2)) - (v594 + ((~(((v595 ^ -1) | (-(v595 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v650[v748] = v651;
    int * v654 = v567->cache_vals;
    int v751 = ((((((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1)) & 1) * 2) + ((((v591 + ((~(((v593 ^ -1) | (-(v593 ^ -1))) >> 31)) & 2)) - (v594 + ((~(((v595 ^ -1) | (-(v595 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v654[v751] = v652;
    int * v656 = v567->cache_tags;
    int v754 = ((((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1)) & 1) * 2) + ((((v591 + ((~(((v593 ^ -1) | (-(v593 ^ -1))) >> 31)) & 2)) - (v594 + ((~(((v595 ^ -1) | (-(v595 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v755 = (int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1);
    v656[v754] = v755;
    int * v658 = v567->cache_dirty;
    v658[v754] = 0;
    int * v660 = v567->cache_age;
    v660[v754] = 1;
    int * v662 = v567->cache_age;
    int v663 = v662[v754];
    int v664 = v662[v684];
    int v761 = v664 + ((int)((unsigned int)(v664 - v663) >> 31));
    v662[v684] = v761;
    int * v666 = v567->cache_age;
    int v667 = v666[v685];
    int v763 = v667 + ((int)((unsigned int)(v667 - v663) >> 31));
    v666[v685] = v763;
    int * v669 = v567->cache_age;
    v669[v754] = 0;
    v672 = v754;
  }
  int v766 = (v672 * 2) + (((int)((unsigned int)v573 >> 2)) & 1);
  int v673 = v579[v766];
  int * v674 = v567->reg_ready;
  int v769 = ((v571 + ((v568 - v571) & (~((v568 - v571) >> 31)))) + 1) + ((100 ^ (((~(((v577 ^ ((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1))) | (-(v577 ^ ((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1))))) >> 31)) | (~(((v578 ^ ((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1))) | (-(v578 ^ ((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v575 ^ ((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1))) | (-(v575 ^ ((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1))))) >> 31)) | (~(((v576 ^ ((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1))) | (-(v576 ^ ((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v577 ^ ((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1))) | (-(v577 ^ ((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1))))) >> 31)) | (~(((v578 ^ ((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1))) | (-(v578 ^ ((int)((unsigned int)((int)((unsigned int)v573 >> 2)) >> 1))))) >> 31))) & 104)))));
  v674[12] = v769;
  int * v676 = v567->regs;
  v676[12] = v673;
  return v567;
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

struct StateT * slot_3(struct StateT * v359) {
  int v360 = v359->timer;
  int v472 = v360 + 1;
  v359->timer = v472;
  int * v362 = v359->reg_ready;
  int v363 = v362[6];
  int * v364 = v359->regs;
  int v365 = v364[6];
  int * v366 = v359->cache_tags;
  int v477 = (((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1)) & 1) * 2;
  int v367 = v366[v477];
  int v478 = ((((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1)) & 1) * 2) + 1;
  int v368 = v366[v478];
  int v479 = 4 + ((((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1)) & 3) * 2);
  int v369 = v366[v479];
  int v480 = (4 + ((((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v370 = v366[v480];
  int * v371 = v359->cache_vals;
  bool v481 = !(((~(((v367 ^ ((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1))) | (-(v367 ^ ((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1))))) >> 31)) | (~(((v368 ^ ((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1))) | (-(v368 ^ ((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1))))) >> 31))) == 0);
  int v464;
  if (v481) {
    int * v372 = v359->cache_age;
    int v483 = ((((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1)) & 1) * 2) + ((~(((v368 ^ ((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1))) | (-(v368 ^ ((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1))))) >> 31)) & 1);
    int v373 = v372[v483];
    int v374 = v372[v477];
    int v484 = v374 + ((int)((unsigned int)(v374 - v373) >> 31));
    v372[v477] = v484;
    int * v376 = v359->cache_age;
    int v377 = v376[v478];
    int v486 = v377 + ((int)((unsigned int)(v377 - v373) >> 31));
    v376[v478] = v486;
    int * v379 = v359->cache_age;
    v379[v483] = 0;
    v464 = v483;
  } else {
    int * v382 = v359->cache_age;
    int v490 = (((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1)) & 1) * 2;
    int v383 = v382[v490];
    int * v384 = v359->cache_tags;
    int v385 = v384[v490];
    int v386 = v382[v478];
    int v387 = v384[v478];
    bool v492 = !(((~(((v369 ^ ((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1))) | (-(v369 ^ ((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1))))) >> 31)) | (~(((v370 ^ ((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1))) | (-(v370 ^ ((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1))))) >> 31))) == 0);
    int v441;
    if (v492) {
      int * v388 = v359->cache_age;
      int v494 = (4 + ((((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1)) & 3) * 2)) + ((~(((v370 ^ ((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1))) | (-(v370 ^ ((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1))))) >> 31)) & 1);
      int v389 = v388[v494];
      int v390 = v388[v479];
      int v495 = v390 + ((int)((unsigned int)(v390 - v389) >> 31));
      v388[v479] = v495;
      int * v392 = v359->cache_age;
      int v393 = v392[v480];
      int v497 = v393 + ((int)((unsigned int)(v393 - v389) >> 31));
      v392[v480] = v497;
      int * v395 = v359->cache_age;
      v395[v494] = 0;
      v441 = v494;
    } else {
      int * v398 = v359->cache_age;
      int v501 = 4 + ((((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1)) & 3) * 2);
      int v399 = v398[v501];
      int * v400 = v359->cache_tags;
      int v401 = v400[v501];
      int v402 = v398[v480];
      int v403 = v400[v480];
      int * v404 = v359->cache_dirty;
      int v504 = (4 + ((((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1)) & 3) * 2)) + ((((v399 + ((~(((v401 ^ -1) | (-(v401 ^ -1))) >> 31)) & 2)) - (v402 + ((~(((v403 ^ -1) | (-(v403 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v405 = v404[v504];
      bool v505 = !(v405 == 0);
      if (v505) {
        int * v406 = v359->cache_tags;
        int v407 = v406[v504];
        int * v408 = v359->cache_vals;
        int v508 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1)) & 3) * 2)) + ((((v399 + ((~(((v401 ^ -1) | (-(v401 ^ -1))) >> 31)) & 2)) - (v402 + ((~(((v403 ^ -1) | (-(v403 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v409 = v408[v508];
        int v509 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1)) & 3) * 2)) + ((((v399 + ((~(((v401 ^ -1) | (-(v401 ^ -1))) >> 31)) & 2)) - (v402 + ((~(((v403 ^ -1) | (-(v403 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v410 = v408[v509];
        int * v411 = v359->mem;
        int v511 = v407 * 2;
        v411[v511] = v409;
        int * v413 = v359->mem;
        int v514 = (v407 * 2) + 1;
        v413[v514] = v410;
        ;
      } else {
        ;
      }
      int * v418 = v359->mem;
      int v519 = ((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1)) * 2;
      int v419 = v418[v519];
      int v520 = (((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1)) * 2) + 1;
      int v420 = v418[v520];
      int * v421 = v359->cache_vals;
      int v522 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1)) & 3) * 2)) + ((((v399 + ((~(((v401 ^ -1) | (-(v401 ^ -1))) >> 31)) & 2)) - (v402 + ((~(((v403 ^ -1) | (-(v403 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v421[v522] = v419;
      int * v423 = v359->cache_vals;
      int v525 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1)) & 3) * 2)) + ((((v399 + ((~(((v401 ^ -1) | (-(v401 ^ -1))) >> 31)) & 2)) - (v402 + ((~(((v403 ^ -1) | (-(v403 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v423[v525] = v420;
      int * v425 = v359->cache_tags;
      int v528 = (int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1);
      v425[v504] = v528;
      int * v427 = v359->cache_dirty;
      v427[v504] = 0;
      int * v429 = v359->cache_age;
      v429[v504] = 1;
      int * v431 = v359->cache_age;
      int v432 = v431[v504];
      int v433 = v431[v479];
      int v534 = v433 + ((int)((unsigned int)(v433 - v432) >> 31));
      v431[v479] = v534;
      int * v435 = v359->cache_age;
      int v436 = v435[v480];
      int v536 = v436 + ((int)((unsigned int)(v436 - v432) >> 31));
      v435[v480] = v536;
      int * v438 = v359->cache_age;
      v438[v504] = 0;
      v441 = v504;
    }
    int * v442 = v359->cache_vals;
    int v539 = v441 * 2;
    int v443 = v442[v539];
    int v540 = (v441 * 2) + 1;
    int v444 = v442[v540];
    int v541 = (((((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1)) & 1) * 2) + ((((v383 + ((~(((v385 ^ -1) | (-(v385 ^ -1))) >> 31)) & 2)) - (v386 + ((~(((v387 ^ -1) | (-(v387 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v442[v541] = v443;
    int * v446 = v359->cache_vals;
    int v544 = ((((((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1)) & 1) * 2) + ((((v383 + ((~(((v385 ^ -1) | (-(v385 ^ -1))) >> 31)) & 2)) - (v386 + ((~(((v387 ^ -1) | (-(v387 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v446[v544] = v444;
    int * v448 = v359->cache_tags;
    int v547 = ((((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1)) & 1) * 2) + ((((v383 + ((~(((v385 ^ -1) | (-(v385 ^ -1))) >> 31)) & 2)) - (v386 + ((~(((v387 ^ -1) | (-(v387 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v548 = (int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1);
    v448[v547] = v548;
    int * v450 = v359->cache_dirty;
    v450[v547] = 0;
    int * v452 = v359->cache_age;
    v452[v547] = 1;
    int * v454 = v359->cache_age;
    int v455 = v454[v547];
    int v456 = v454[v477];
    int v554 = v456 + ((int)((unsigned int)(v456 - v455) >> 31));
    v454[v477] = v554;
    int * v458 = v359->cache_age;
    int v459 = v458[v478];
    int v556 = v459 + ((int)((unsigned int)(v459 - v455) >> 31));
    v458[v478] = v556;
    int * v461 = v359->cache_age;
    v461[v547] = 0;
    v464 = v547;
  }
  int v559 = (v464 * 2) + (((int)((unsigned int)v365 >> 2)) & 1);
  int v465 = v371[v559];
  int * v466 = v359->reg_ready;
  int v562 = ((v363 + ((v360 - v363) & (~((v360 - v363) >> 31)))) + 1) + ((100 ^ (((~(((v369 ^ ((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1))) | (-(v369 ^ ((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1))))) >> 31)) | (~(((v370 ^ ((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1))) | (-(v370 ^ ((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v367 ^ ((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1))) | (-(v367 ^ ((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1))))) >> 31)) | (~(((v368 ^ ((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1))) | (-(v368 ^ ((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v369 ^ ((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1))) | (-(v369 ^ ((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1))))) >> 31)) | (~(((v370 ^ ((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1))) | (-(v370 ^ ((int)((unsigned int)((int)((unsigned int)v365 >> 2)) >> 1))))) >> 31))) & 104)))));
  v466[11] = v562;
  int * v468 = v359->regs;
  v468[11] = v465;
  struct StateT * v470 = slot_4(v359);
  return v470;
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