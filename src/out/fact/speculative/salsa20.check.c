// verify: clean (CBMC should report VERIFICATION SUCCESSFUL) [unwind 65]

#define NUM_REGS 32
#define MEM_SIZE 64
#define SECRET_SIZE 10
#define SECRET_OFFSET 20
#define CACHE_LRU_SIZE 10
#ifndef CBMC
#define __CPROVER_assert(b,s) 0
#define nondet_uint() 0
#else
int nondet_uint();
#endif
int bounded(int low, int high) {
  int x = nondet_uint();
  __CPROVER_assume(low <= x && x <= high);
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
  int cache_keys[10];
  int cache_vals[10];
  int timer;
};

struct StateT * slot_12(struct StateT * v1095);
struct StateT * slot_228(struct StateT * v6929);
struct StateT * slot_143(struct StateT * v12008);
struct StateT * slot_120(struct StateT * v11578);
struct StateT * slot_226(struct StateT * v6771);
struct StateT * slot_167(struct StateT * v12461);
struct StateT * slot_268(struct StateT * v10548);
struct StateT * slot_152(struct StateT * v12186);
struct StateT * slot_231(struct StateT * v7127);
struct StateT * slot_199(struct StateT * v13071);
struct StateT * slot_252(struct StateT * v8643);
struct StateT * slot_92(struct StateT * v8978);
struct StateT * slot_232(struct StateT * v7252);
struct StateT * slot_269(struct StateT * v10674);
struct StateT * slot_31(struct StateT * v2620);
struct StateT * slot_236(struct StateT * v7585);
struct StateT * slot_241(struct StateT * v7757);
struct StateT * slot_160(struct StateT * v12335);
struct StateT * slot_251(struct StateT * v8525);
struct StateT * slot_65(struct StateT * v6913);
struct StateT * slot_10(struct StateT * v899);
struct StateT * slot_150(struct StateT * v12144);
struct StateT * slot_74(struct StateT * v7605);
struct StateT * slot_262(struct StateT * v9812);
struct StateT * slot_107(struct StateT * v10779);
struct StateT * slot_136(struct StateT * v11886);
struct StateT * slot_84(struct StateT * v8040);
struct StateT * slot_28(struct StateT * v2577);
struct StateT * slot_155(struct StateT * v12249);
struct StateT * slot_177(struct StateT * v12658);
struct StateT * slot_229(struct StateT * v6962);
struct StateT * slot_17(struct StateT * v1514);
struct StateT * slot_181(struct StateT * v12731);
struct StateT * slot_197(struct StateT * v13034);
struct StateT * slot_207(struct StateT * v13213);
struct StateT * slot_156(struct StateT * v12266);
struct StateT * slot_154(struct StateT * v12228);
struct StateT * slot_68(struct StateT * v7107);
struct StateT * slot_260(struct StateT * v9584);
struct StateT * slot_105(struct StateT * v10532);
struct StateT * slot_27(struct StateT * v2564);
struct StateT * slot_164(struct StateT * v12408);
struct StateT * slot_15(struct StateT * v1304);
struct StateT * slot_133(struct StateT * v11827);
struct StateT * slot_56(struct StateT * v6241);
struct StateT * slot_244(struct StateT * v7866);
struct StateT * slot_222(struct StateT * v6448);
struct StateT * slot_34(struct StateT * v2667);
struct StateT * slot_171(struct StateT * v12541);
struct StateT * slot_162(struct StateT * v12372);
struct StateT * slot_21(struct StateT * v1934);
struct StateT * slot_239(struct StateT * v7688);
struct StateT * slot_118(struct StateT * v11545);
struct StateT * slot_121(struct StateT * v11598);
struct StateT * slot_144(struct StateT * v12028);
struct StateT * slot_267(struct StateT * v10427);
struct StateT * slot_201(struct StateT * v13107);
struct StateT * slot_94(struct StateT * v9216);
struct StateT * slot_63(struct StateT * v6751);
struct StateT * slot_146(struct StateT * v12061);
struct StateT * slot_24(struct StateT * v2249);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_195(struct StateT * v13001);
struct StateT * slot_125(struct StateT * v11668);
struct StateT * slot_254(struct StateT * v8880);
struct StateT * slot_148(struct StateT * v12102);
struct StateT * slot_126(struct StateT * v11684);
struct StateT * slot_223(struct StateT * v6573);
struct StateT * slot_79(struct StateT * v7773);
struct StateT * slot_237(struct StateT * v7626);
struct StateT * slot_41(struct StateT * v3185);
struct StateT * slot_39(struct StateT * v2990);
struct StateT * slot_142(struct StateT * v11992);
struct StateT * slot_60(struct StateT * v6553);
struct StateT * slot_238(struct StateT * v7656);
struct StateT * slot_112(struct StateT * v11408);
struct StateT * slot_256(struct StateT * v9118);
struct StateT * slot_272(struct StateT * v11051);
struct StateT * slot_47(struct StateT * v3530);
struct StateT * slot_214(struct StateT * v5983);
struct StateT * slot_29(struct StateT * v2590);
struct StateT * slot_16(struct StateT * v1409);
struct StateT * slot_245(struct StateT * v7902);
struct StateT * slot_113(struct StateT * v11445);
struct StateT * slot_151(struct StateT * v12165);
struct StateT * slot_7(struct StateT * v605);
struct StateT * slot_124(struct StateT * v11651);
struct StateT * slot_191(struct StateT * v12917);
struct StateT * slot_103(struct StateT * v10285);
struct StateT * slot_128(struct StateT * v11724);
struct StateT * slot_19(struct StateT * v1724);
struct StateT * slot_87(struct StateT * v8387);
struct StateT * slot_67(struct StateT * v7067);
struct StateT * slot_81(struct StateT * v7849);
struct StateT * slot_95(struct StateT * v9335);
struct StateT * slot_115(struct StateT * v11492);
struct StateT * slot_78(struct StateT * v7740);
struct StateT * slot_32(struct StateT * v2637);
struct StateT * slot_205(struct StateT * v13177);
struct StateT * slot_193(struct StateT * v12959);
struct StateT * slot_233(struct StateT * v7292);
struct StateT * slot_176(struct StateT * v12642);
struct StateT * slot_189(struct StateT * v12877);
struct StateT * slot_33(struct StateT * v2654);
struct StateT * slot_35(struct StateT * v2683);
struct StateT * slot_258(struct StateT * v9352);
struct StateT * slot_246(struct StateT * v7942);
struct StateT * slot_210(struct StateT * v13274);
struct StateT * slot_166(struct StateT * v12441);
struct StateT * slot_51(struct StateT * v5962);
struct StateT * slot_52(struct StateT * v6003);
struct StateT * slot_83(struct StateT * v7922);
struct StateT * slot_25(struct StateT * v2354);
struct StateT * slot_209(struct StateT * v13254);
struct StateT * slot_3(struct StateT * v213);
struct StateT * slot_264(struct StateT * v10059);
struct StateT * slot_123(struct StateT * v11631);
struct StateT * slot_73(struct StateT * v7564);
struct StateT * slot_270(struct StateT * v10800);
struct StateT * slot_198(struct StateT * v13054);
struct StateT * slot_1(struct StateT * v18);
struct StateT * slot_187(struct StateT * v12837);
struct StateT * slot_97(struct StateT * v9564);
struct StateT * slot_182(struct StateT * v12748);
struct StateT * slot_38(struct StateT * v2892);
struct StateT * slot_178(struct StateT * v12678);
struct StateT * slot_106(struct StateT * v10653);
struct StateT * slot_98(struct StateT * v9681);
struct StateT * slot_159(struct StateT * v12319);
struct StateT * slot_46(struct StateT * v3513);
struct StateT * slot_212(struct StateT * v13310);
struct StateT * slot_132(struct StateT * v11806);
struct StateT * slot_130(struct StateT * v11765);
struct StateT * slot_211(struct StateT * v13294);
struct StateT * slot_20(struct StateT * v1829);
struct StateT * slot_141(struct StateT * v11975);
struct StateT * slot_61(struct StateT * v6593);
struct StateT * slot_30(struct StateT * v2603);
struct StateT * slot_4(struct StateT * v311);
struct StateT * slot_18(struct StateT * v1619);
struct StateT * slot_9(struct StateT * v801);
struct StateT * slot_183(struct StateT * v12764);
struct StateT * slot_240(struct StateT * v7724);
struct StateT * slot_247(struct StateT * v8057);
struct StateT * slot_43(struct StateT * v3381);
struct StateT * slot_70(struct StateT * v7272);
struct StateT * slot_168(struct StateT * v12481);
struct StateT * slot_76(struct StateT * v7672);
struct StateT * slot_6(struct StateT * v507);
struct StateT * slot_225(struct StateT * v6731);
struct StateT * slot_55(struct StateT * v6204);
struct StateT * slot_213(struct StateT * v5942);
struct StateT * slot_82(struct StateT * v7886);
struct StateT * slot_274(struct StateT * v11303);
struct StateT * slot_263(struct StateT * v9937);
struct StateT * slot_161(struct StateT * v12355);
struct StateT * slot_185(struct StateT * v12801);
struct StateT * slot_91(struct StateT * v8859);
struct StateT * slot_58(struct StateT * v6395);
struct StateT * slot_89(struct StateT * v8623);
struct StateT * slot_255(struct StateT * v8999);
struct StateT * slot_66(struct StateT * v6942);
struct StateT * slot_140(struct StateT * v11955);
struct StateT * slot_265(struct StateT * v10180);
struct StateT * slot_49(struct StateT * v3645);
struct StateT * slot_216(struct StateT * v6058);
struct StateT * slot_50(struct StateT * v3662);
struct StateT * slot_37(struct StateT * v2794);
struct StateT * slot_114(struct StateT * v11471);
struct StateT * slot_135(struct StateT * v11869);
struct StateT * slot_248(struct StateT * v8171);
struct StateT * slot_257(struct StateT * v9237);
struct StateT * slot_59(struct StateT * v6432);
struct StateT * slot_192(struct StateT * v12938);
struct StateT * slot_40(struct StateT * v3087);
struct StateT * slot_48(struct StateT * v3547);
struct StateT * slot_77(struct StateT * v7704);
struct StateT * slot_85(struct StateT * v8155);
struct StateT * slot_75(struct StateT * v7639);
struct StateT * slot_72(struct StateT * v7438);
struct StateT * slot_119(struct StateT * v11562);
struct StateT * slot_71(struct StateT * v7397);
struct StateT * slot_101(struct StateT * v10042);
struct StateT * slot_276(struct StateT * v11466);
struct StateT * slot_108(struct StateT * v10905);
struct StateT * slot_116(struct StateT * v11509);
struct StateT * slot_93(struct StateT * v9097);
struct StateT * slot_266(struct StateT * v10305);
struct StateT * slot_88(struct StateT * v8505);
struct StateT * slot_96(struct StateT * v9450);
struct StateT * slot_215(struct StateT * v6024);
struct StateT * slot_234(struct StateT * v7418);
struct StateT * slot_45(struct StateT * v3496);
struct StateT * slot_218(struct StateT * v6221);
struct StateT * slot_220(struct StateT * v6290);
struct StateT * slot_134(struct StateT * v11848);
struct StateT * slot_175(struct StateT * v12625);
struct StateT * slot_273(struct StateT * v11177);
struct StateT * slot_69(struct StateT * v7232);
struct StateT * slot_202(struct StateT * v13124);
struct StateT * slot_230(struct StateT * v7087);
struct StateT * slot_188(struct StateT * v12857);
struct StateT * slot_138(struct StateT * v11922);
struct StateT * slot_186(struct StateT * v12817);
struct StateT * slot_102(struct StateT * v10164);
struct StateT * slot_145(struct StateT * v12045);
struct StateT * slot_110(struct StateT * v11156);
struct StateT * slot_196(struct StateT * v13018);
struct StateT * slot_208(struct StateT * v13233);
struct StateT * slot_172(struct StateT * v12562);
struct StateT * slot_131(struct StateT * v11785);
struct StateT * slot_8(struct StateT * v703);
struct StateT * slot_180(struct StateT * v12711);
struct StateT * slot_203(struct StateT * v13140);
struct StateT * slot_190(struct StateT * v12897);
struct StateT * slot_157(struct StateT * v12282);
struct StateT * slot_242(struct StateT * v7789);
struct StateT * slot_200(struct StateT * v13087);
struct StateT * slot_243(struct StateT * v7829);
struct StateT * slot_173(struct StateT * v12583);
struct StateT * slot_149(struct StateT * v12123);
struct StateT * slot_5(struct StateT * v409);
struct StateT * slot_104(struct StateT * v10410);
struct StateT * slot_235(struct StateT * v7459);
struct StateT * slot_275(struct StateT * v11429);
struct StateT * slot_54(struct StateT * v6078);
struct StateT * slot_26(struct StateT * v2459);
struct StateT * slot_206(struct StateT * v13193);
struct StateT * slot_227(struct StateT * v6893);
struct StateT * slot_169(struct StateT * v12501);
struct StateT * slot_253(struct StateT * v8761);
struct StateT * slot_64(struct StateT * v6876);
struct StateT * slot_170(struct StateT * v12521);
struct StateT * slot_14(struct StateT * v1291);
struct StateT * slot_53(struct StateT * v6037);
struct StateT * slot_80(struct StateT * v7809);
struct StateT * slot_44(struct StateT * v3479);
struct StateT * slot_261(struct StateT * v9698);
struct StateT * slot_137(struct StateT * v11902);
struct StateT * slot_122(struct StateT * v11615);
struct StateT * slot_99(struct StateT * v9796);
struct StateT * slot_179(struct StateT * v12695);
struct StateT * slot_219(struct StateT * v6257);
struct StateT * slot_36(struct StateT * v2696);
struct StateT * slot_57(struct StateT * v6270);
struct StateT * slot_62(struct StateT * v6715);
struct StateT * slot_22(struct StateT * v2039);
struct StateT * slot_139(struct StateT * v11939);
struct StateT * slot_221(struct StateT * v6412);
struct StateT * slot_23(struct StateT * v2144);
struct StateT * slot_153(struct StateT * v12207);
struct StateT * slot_2(struct StateT * v115);
struct StateT * slot_86(struct StateT * v8269);
struct StateT * slot_129(struct StateT * v11745);
struct StateT * slot_158(struct StateT * v12302);
struct StateT * slot_100(struct StateT * v9917);
struct StateT * slot_271(struct StateT * v10925);
struct StateT * slot_127(struct StateT * v11704);
struct StateT * slot_217(struct StateT * v6099);
struct StateT * slot_13(struct StateT * v1193);
struct StateT * slot_111(struct StateT * v11282);
struct StateT * slot_109(struct StateT * v11030);
struct StateT * slot_174(struct StateT * v12604);
struct StateT * slot_147(struct StateT * v12082);
struct StateT * slot_42(struct StateT * v3283);
struct StateT * slot_224(struct StateT * v6610);
struct StateT * slot_163(struct StateT * v12388);
struct StateT * slot_184(struct StateT * v12784);
struct StateT * slot_204(struct StateT * v13160);
struct StateT * slot_194(struct StateT * v12980);
struct StateT * slot_165(struct StateT * v12425);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_250(struct StateT * v8407);
struct StateT * slot_259(struct StateT * v9466);
struct StateT * slot_117(struct StateT * v11525);
struct StateT * slot_249(struct StateT * v8289);
struct StateT * slot_90(struct StateT * v8741);
struct StateT * slot_11(struct StateT * v997);
struct StateT * slot_12(struct StateT * v1095) {
  int v1096 = v1095->timer;
  int v1150 = v1096 + 1;
  v1095->timer = v1150;
  int * v1098 = v1095->regs;
  int v1099 = v1098[2];
  int * v1100 = v1095->regs;
  int v1101 = v1100[26];
  int * v1102 = v1095->cache_keys;
  int v1103 = v1102[0];
  bool v1157 = v1103 == ((int)((unsigned int)(v1099 + 48) >> 2));
  int v1147;
  if (v1157) {
    int * v1104 = v1095->cache_vals;
    v1104[0] = v1101;
    v1147 = v1101;
  } else {
    int * v1107 = v1095->cache_keys;
    int v1108 = v1107[1];
    bool v1162 = v1108 == ((int)((unsigned int)(v1099 + 48) >> 2));
    int v1145;
    if (v1162) {
      int * v1109 = v1095->cache_keys;
      int * v1110 = v1095->cache_keys;
      int v1111 = v1110[0];
      v1109[1] = v1111;
      int * v1113 = v1095->cache_vals;
      int * v1114 = v1095->cache_vals;
      int v1115 = v1114[0];
      v1113[1] = v1115;
      int * v1117 = v1095->cache_keys;
      int v1170 = (int)((unsigned int)(v1099 + 48) >> 2);
      v1117[0] = v1170;
      int * v1119 = v1095->cache_vals;
      v1119[0] = v1101;
      int v1121 = v1095->timer;
      int v1173 = v1121 + 1;
      v1095->timer = v1173;
      v1145 = v1101;
    } else {
      int * v1124 = v1095->mem;
      int * v1125 = v1095->cache_keys;
      int v1126 = v1125[1];
      int * v1127 = v1095->cache_vals;
      int v1128 = v1127[1];
      v1124[v1126] = v1128;
      int * v1130 = v1095->cache_keys;
      int * v1131 = v1095->cache_keys;
      int v1132 = v1131[0];
      v1130[1] = v1132;
      int * v1134 = v1095->cache_vals;
      int * v1135 = v1095->cache_vals;
      int v1136 = v1135[0];
      v1134[1] = v1136;
      int * v1138 = v1095->cache_keys;
      int v1186 = (int)((unsigned int)(v1099 + 48) >> 2);
      v1138[0] = v1186;
      int * v1140 = v1095->cache_vals;
      v1140[0] = v1101;
      int v1142 = v1095->timer;
      int v1189 = v1142 + 100;
      v1095->timer = v1189;
      v1145 = v1101;
    }
    v1147 = v1145;
  }
  struct StateT * v1148 = slot_13(v1095);
  return v1148;
}

struct StateT * slot_228(struct StateT * v6929) {
  int v6930 = v6929->timer;
  int v6936 = v6930 + 1;
  v6929->timer = v6936;
  int * v6932 = v6929->regs;
  v6932[7] = 2036477952;
  struct StateT * v6934 = slot_229(v6929);
  return v6934;
}

struct StateT * slot_143(struct StateT * v12008) {
  int v12009 = v12008->timer;
  int v12019 = v12009 + 1;
  v12008->timer = v12019;
  int * v12011 = v12008->regs;
  int v12012 = v12011[16];
  int * v12013 = v12008->regs;
  int v12014 = v12013[5];
  int * v12015 = v12008->regs;
  int v12025 = v12012 | v12014;
  v12015[16] = v12025;
  struct StateT * v12017 = slot_144(v12008);
  return v12017;
}

struct StateT * slot_120(struct StateT * v11578) {
  int v11579 = v11578->timer;
  int v11589 = v11579 + 1;
  v11578->timer = v11589;
  int * v11581 = v11578->regs;
  int v11582 = v11581[16];
  int * v11583 = v11578->regs;
  int v11584 = v11583[6];
  int * v11585 = v11578->regs;
  int v11595 = v11582 | v11584;
  v11585[16] = v11595;
  struct StateT * v11587 = slot_121(v11578);
  return v11587;
}

struct StateT * slot_226(struct StateT * v6771) {
  int v6772 = v6771->timer;
  int v6830 = v6772 + 1;
  v6771->timer = v6830;
  int * v6774 = v6771->regs;
  int v6775 = v6774[2];
  int * v6776 = v6771->cache_keys;
  int v6777 = v6776[0];
  bool v6835 = v6777 == ((int)((unsigned int)(v6775 + 24) >> 2));
  int v6825;
  if (v6835) {
    int * v6778 = v6771->cache_vals;
    int v6779 = v6778[0];
    v6825 = v6779;
  } else {
    int * v6781 = v6771->cache_keys;
    int v6782 = v6781[1];
    bool v6840 = v6782 == ((int)((unsigned int)(v6775 + 24) >> 2));
    int v6823;
    if (v6840) {
      int * v6783 = v6771->cache_vals;
      int v6784 = v6783[1];
      int * v6785 = v6771->cache_keys;
      int * v6786 = v6771->cache_keys;
      int v6787 = v6786[0];
      v6785[1] = v6787;
      int * v6789 = v6771->cache_vals;
      int * v6790 = v6771->cache_vals;
      int v6791 = v6790[0];
      v6789[1] = v6791;
      int * v6793 = v6771->cache_keys;
      int v6849 = (int)((unsigned int)(v6775 + 24) >> 2);
      v6793[0] = v6849;
      int * v6795 = v6771->cache_vals;
      v6795[0] = v6784;
      int v6797 = v6771->timer;
      int v6852 = v6797 + 1;
      v6771->timer = v6852;
      v6823 = v6784;
    } else {
      int * v6800 = v6771->mem;
      int v6854 = (int)((unsigned int)(v6775 + 24) >> 2);
      int v6801 = v6800[v6854];
      int * v6802 = v6771->mem;
      int * v6803 = v6771->cache_keys;
      int v6804 = v6803[1];
      int * v6805 = v6771->cache_vals;
      int v6806 = v6805[1];
      v6802[v6804] = v6806;
      int * v6808 = v6771->cache_keys;
      int * v6809 = v6771->cache_keys;
      int v6810 = v6809[0];
      v6808[1] = v6810;
      int * v6812 = v6771->cache_vals;
      int * v6813 = v6771->cache_vals;
      int v6814 = v6813[0];
      v6812[1] = v6814;
      int * v6816 = v6771->cache_keys;
      v6816[0] = v6854;
      int * v6818 = v6771->cache_vals;
      v6818[0] = v6801;
      int v6820 = v6771->timer;
      int v6869 = v6820 + 100;
      v6771->timer = v6869;
      v6823 = v6801;
    }
    v6825 = v6823;
  }
  int * v6826 = v6771->regs;
  v6826[7] = v6825;
  struct StateT * v6828 = slot_227(v6771);
  return v6828;
}

struct StateT * slot_167(struct StateT * v12461) {
  int v12462 = v12461->timer;
  int v12472 = v12462 + 1;
  v12461->timer = v12472;
  int * v12464 = v12461->regs;
  int v12465 = v12464[27];
  int * v12466 = v12461->regs;
  int v12467 = v12466[11];
  int * v12468 = v12461->regs;
  int v12478 = v12465 ^ v12467;
  v12468[27] = v12478;
  struct StateT * v12470 = slot_168(v12461);
  return v12470;
}

struct StateT * slot_268(struct StateT * v10548) {
  int v10549 = v10548->timer;
  int v10607 = v10549 + 1;
  v10548->timer = v10607;
  int * v10551 = v10548->regs;
  int v10552 = v10551[2];
  int * v10553 = v10548->cache_keys;
  int v10554 = v10553[0];
  bool v10612 = v10554 == ((int)((unsigned int)(v10552 + 68) >> 2));
  int v10602;
  if (v10612) {
    int * v10555 = v10548->cache_vals;
    int v10556 = v10555[0];
    v10602 = v10556;
  } else {
    int * v10558 = v10548->cache_keys;
    int v10559 = v10558[1];
    bool v10617 = v10559 == ((int)((unsigned int)(v10552 + 68) >> 2));
    int v10600;
    if (v10617) {
      int * v10560 = v10548->cache_vals;
      int v10561 = v10560[1];
      int * v10562 = v10548->cache_keys;
      int * v10563 = v10548->cache_keys;
      int v10564 = v10563[0];
      v10562[1] = v10564;
      int * v10566 = v10548->cache_vals;
      int * v10567 = v10548->cache_vals;
      int v10568 = v10567[0];
      v10566[1] = v10568;
      int * v10570 = v10548->cache_keys;
      int v10626 = (int)((unsigned int)(v10552 + 68) >> 2);
      v10570[0] = v10626;
      int * v10572 = v10548->cache_vals;
      v10572[0] = v10561;
      int v10574 = v10548->timer;
      int v10629 = v10574 + 1;
      v10548->timer = v10629;
      v10600 = v10561;
    } else {
      int * v10577 = v10548->mem;
      int v10631 = (int)((unsigned int)(v10552 + 68) >> 2);
      int v10578 = v10577[v10631];
      int * v10579 = v10548->mem;
      int * v10580 = v10548->cache_keys;
      int v10581 = v10580[1];
      int * v10582 = v10548->cache_vals;
      int v10583 = v10582[1];
      v10579[v10581] = v10583;
      int * v10585 = v10548->cache_keys;
      int * v10586 = v10548->cache_keys;
      int v10587 = v10586[0];
      v10585[1] = v10587;
      int * v10589 = v10548->cache_vals;
      int * v10590 = v10548->cache_vals;
      int v10591 = v10590[0];
      v10589[1] = v10591;
      int * v10593 = v10548->cache_keys;
      v10593[0] = v10631;
      int * v10595 = v10548->cache_vals;
      v10595[0] = v10578;
      int v10597 = v10548->timer;
      int v10646 = v10597 + 100;
      v10548->timer = v10646;
      v10600 = v10578;
    }
    v10602 = v10600;
  }
  int * v10603 = v10548->regs;
  v10603[21] = v10602;
  struct StateT * v10605 = slot_269(v10548);
  return v10605;
}

struct StateT * slot_152(struct StateT * v12186) {
  int v12187 = v12186->timer;
  int v12197 = v12187 + 1;
  v12186->timer = v12197;
  int * v12189 = v12186->regs;
  int v12190 = v12189[5];
  int * v12191 = v12186->regs;
  int v12192 = v12191[20];
  int * v12193 = v12186->regs;
  int v12204 = v12190 + v12192;
  v12193[15] = v12204;
  struct StateT * v12195 = slot_153(v12186);
  return v12195;
}

struct StateT * slot_231(struct StateT * v7127) {
  int v7128 = v7127->timer;
  int v7186 = v7128 + 1;
  v7127->timer = v7186;
  int * v7130 = v7127->regs;
  int v7131 = v7130[2];
  int * v7132 = v7127->cache_keys;
  int v7133 = v7132[0];
  bool v7191 = v7133 == ((int)((unsigned int)(v7131 + 32) >> 2));
  int v7181;
  if (v7191) {
    int * v7134 = v7127->cache_vals;
    int v7135 = v7134[0];
    v7181 = v7135;
  } else {
    int * v7137 = v7127->cache_keys;
    int v7138 = v7137[1];
    bool v7196 = v7138 == ((int)((unsigned int)(v7131 + 32) >> 2));
    int v7179;
    if (v7196) {
      int * v7139 = v7127->cache_vals;
      int v7140 = v7139[1];
      int * v7141 = v7127->cache_keys;
      int * v7142 = v7127->cache_keys;
      int v7143 = v7142[0];
      v7141[1] = v7143;
      int * v7145 = v7127->cache_vals;
      int * v7146 = v7127->cache_vals;
      int v7147 = v7146[0];
      v7145[1] = v7147;
      int * v7149 = v7127->cache_keys;
      int v7205 = (int)((unsigned int)(v7131 + 32) >> 2);
      v7149[0] = v7205;
      int * v7151 = v7127->cache_vals;
      v7151[0] = v7140;
      int v7153 = v7127->timer;
      int v7208 = v7153 + 1;
      v7127->timer = v7208;
      v7179 = v7140;
    } else {
      int * v7156 = v7127->mem;
      int v7210 = (int)((unsigned int)(v7131 + 32) >> 2);
      int v7157 = v7156[v7210];
      int * v7158 = v7127->mem;
      int * v7159 = v7127->cache_keys;
      int v7160 = v7159[1];
      int * v7161 = v7127->cache_vals;
      int v7162 = v7161[1];
      v7158[v7160] = v7162;
      int * v7164 = v7127->cache_keys;
      int * v7165 = v7127->cache_keys;
      int v7166 = v7165[0];
      v7164[1] = v7166;
      int * v7168 = v7127->cache_vals;
      int * v7169 = v7127->cache_vals;
      int v7170 = v7169[0];
      v7168[1] = v7170;
      int * v7172 = v7127->cache_keys;
      v7172[0] = v7210;
      int * v7174 = v7127->cache_vals;
      v7174[0] = v7157;
      int v7176 = v7127->timer;
      int v7225 = v7176 + 100;
      v7127->timer = v7225;
      v7179 = v7157;
    }
    v7181 = v7179;
  }
  int * v7182 = v7127->regs;
  v7182[30] = v7181;
  struct StateT * v7184 = slot_232(v7127);
  return v7184;
}

struct StateT * slot_199(struct StateT * v13071) {
  int v13072 = v13071->timer;
  int v13080 = v13072 + 1;
  v13071->timer = v13080;
  int * v13074 = v13071->regs;
  int v13075 = v13074[15];
  int * v13076 = v13071->regs;
  int v13084 = v13075 << 18;
  v13076[15] = v13084;
  struct StateT * v13078 = slot_200(v13071);
  return v13078;
}

struct StateT * slot_252(struct StateT * v8643) {
  int v8644 = v8643->timer;
  int v8698 = v8644 + 1;
  v8643->timer = v8698;
  int * v8646 = v8643->regs;
  int v8647 = v8646[10];
  int * v8648 = v8643->regs;
  int v8649 = v8648[5];
  int * v8650 = v8643->cache_keys;
  int v8651 = v8650[0];
  bool v8705 = v8651 == ((int)((unsigned int)(v8647 + 24) >> 2));
  int v8695;
  if (v8705) {
    int * v8652 = v8643->cache_vals;
    v8652[0] = v8649;
    v8695 = v8649;
  } else {
    int * v8655 = v8643->cache_keys;
    int v8656 = v8655[1];
    bool v8710 = v8656 == ((int)((unsigned int)(v8647 + 24) >> 2));
    int v8693;
    if (v8710) {
      int * v8657 = v8643->cache_keys;
      int * v8658 = v8643->cache_keys;
      int v8659 = v8658[0];
      v8657[1] = v8659;
      int * v8661 = v8643->cache_vals;
      int * v8662 = v8643->cache_vals;
      int v8663 = v8662[0];
      v8661[1] = v8663;
      int * v8665 = v8643->cache_keys;
      int v8718 = (int)((unsigned int)(v8647 + 24) >> 2);
      v8665[0] = v8718;
      int * v8667 = v8643->cache_vals;
      v8667[0] = v8649;
      int v8669 = v8643->timer;
      int v8721 = v8669 + 1;
      v8643->timer = v8721;
      v8693 = v8649;
    } else {
      int * v8672 = v8643->mem;
      int * v8673 = v8643->cache_keys;
      int v8674 = v8673[1];
      int * v8675 = v8643->cache_vals;
      int v8676 = v8675[1];
      v8672[v8674] = v8676;
      int * v8678 = v8643->cache_keys;
      int * v8679 = v8643->cache_keys;
      int v8680 = v8679[0];
      v8678[1] = v8680;
      int * v8682 = v8643->cache_vals;
      int * v8683 = v8643->cache_vals;
      int v8684 = v8683[0];
      v8682[1] = v8684;
      int * v8686 = v8643->cache_keys;
      int v8734 = (int)((unsigned int)(v8647 + 24) >> 2);
      v8686[0] = v8734;
      int * v8688 = v8643->cache_vals;
      v8688[0] = v8649;
      int v8690 = v8643->timer;
      int v8737 = v8690 + 100;
      v8643->timer = v8737;
      v8693 = v8649;
    }
    v8695 = v8693;
  }
  struct StateT * v8696 = slot_253(v8643);
  return v8696;
}

struct StateT * slot_92(struct StateT * v8978) {
  int v8979 = v8978->timer;
  int v8989 = v8979 + 1;
  v8978->timer = v8989;
  int * v8981 = v8978->regs;
  int v8982 = v8981[24];
  int * v8983 = v8978->regs;
  int v8984 = v8983[13];
  int * v8985 = v8978->regs;
  int v8996 = v8982 + v8984;
  v8985[8] = v8996;
  struct StateT * v8987 = slot_93(v8978);
  return v8987;
}

struct StateT * slot_232(struct StateT * v7252) {
  int v7253 = v7252->timer;
  int v7263 = v7253 + 1;
  v7252->timer = v7263;
  int * v7255 = v7252->regs;
  int v7256 = v7255[16];
  int * v7257 = v7252->regs;
  int v7258 = v7257[30];
  int * v7259 = v7252->regs;
  int v7269 = v7256 + v7258;
  v7259[16] = v7269;
  struct StateT * v7261 = slot_233(v7252);
  return v7261;
}

struct StateT * slot_269(struct StateT * v10674) {
  int v10675 = v10674->timer;
  int v10733 = v10675 + 1;
  v10674->timer = v10733;
  int * v10677 = v10674->regs;
  int v10678 = v10677[2];
  int * v10679 = v10674->cache_keys;
  int v10680 = v10679[0];
  bool v10738 = v10680 == ((int)((unsigned int)(v10678 + 64) >> 2));
  int v10728;
  if (v10738) {
    int * v10681 = v10674->cache_vals;
    int v10682 = v10681[0];
    v10728 = v10682;
  } else {
    int * v10684 = v10674->cache_keys;
    int v10685 = v10684[1];
    bool v10743 = v10685 == ((int)((unsigned int)(v10678 + 64) >> 2));
    int v10726;
    if (v10743) {
      int * v10686 = v10674->cache_vals;
      int v10687 = v10686[1];
      int * v10688 = v10674->cache_keys;
      int * v10689 = v10674->cache_keys;
      int v10690 = v10689[0];
      v10688[1] = v10690;
      int * v10692 = v10674->cache_vals;
      int * v10693 = v10674->cache_vals;
      int v10694 = v10693[0];
      v10692[1] = v10694;
      int * v10696 = v10674->cache_keys;
      int v10752 = (int)((unsigned int)(v10678 + 64) >> 2);
      v10696[0] = v10752;
      int * v10698 = v10674->cache_vals;
      v10698[0] = v10687;
      int v10700 = v10674->timer;
      int v10755 = v10700 + 1;
      v10674->timer = v10755;
      v10726 = v10687;
    } else {
      int * v10703 = v10674->mem;
      int v10757 = (int)((unsigned int)(v10678 + 64) >> 2);
      int v10704 = v10703[v10757];
      int * v10705 = v10674->mem;
      int * v10706 = v10674->cache_keys;
      int v10707 = v10706[1];
      int * v10708 = v10674->cache_vals;
      int v10709 = v10708[1];
      v10705[v10707] = v10709;
      int * v10711 = v10674->cache_keys;
      int * v10712 = v10674->cache_keys;
      int v10713 = v10712[0];
      v10711[1] = v10713;
      int * v10715 = v10674->cache_vals;
      int * v10716 = v10674->cache_vals;
      int v10717 = v10716[0];
      v10715[1] = v10717;
      int * v10719 = v10674->cache_keys;
      v10719[0] = v10757;
      int * v10721 = v10674->cache_vals;
      v10721[0] = v10704;
      int v10723 = v10674->timer;
      int v10772 = v10723 + 100;
      v10674->timer = v10772;
      v10726 = v10704;
    }
    v10728 = v10726;
  }
  int * v10729 = v10674->regs;
  v10729[22] = v10728;
  struct StateT * v10731 = slot_270(v10674);
  return v10731;
}

struct StateT * slot_31(struct StateT * v2620) {
  int v2621 = v2620->timer;
  int v2629 = v2621 + 1;
  v2620->timer = v2629;
  int * v2623 = v2620->regs;
  int v2624 = v2623[13];
  int * v2625 = v2620->regs;
  int v2634 = v2624 + 1134;
  v2625[11] = v2634;
  struct StateT * v2627 = slot_32(v2620);
  return v2627;
}

struct StateT * slot_236(struct StateT * v7585) {
  int v7586 = v7585->timer;
  int v7596 = v7586 + 1;
  v7585->timer = v7596;
  int * v7588 = v7585->regs;
  int v7589 = v7588[1];
  int * v7590 = v7585->regs;
  int v7591 = v7590[30];
  int * v7592 = v7585->regs;
  int v7602 = v7589 + v7591;
  v7592[1] = v7602;
  struct StateT * v7594 = slot_237(v7585);
  return v7594;
}

struct StateT * slot_241(struct StateT * v7757) {
  int v7758 = v7757->timer;
  int v7766 = v7758 + 1;
  v7757->timer = v7766;
  int * v7760 = v7757->regs;
  int v7761 = v7760[30];
  int * v7762 = v7757->regs;
  int v7770 = v7761 + 1396;
  v7762[30] = v7770;
  struct StateT * v7764 = slot_242(v7757);
  return v7764;
}

struct StateT * slot_160(struct StateT * v12335) {
  int v12336 = v12335->timer;
  int v12346 = v12336 + 1;
  v12335->timer = v12346;
  int * v12338 = v12335->regs;
  int v12339 = v12338[15];
  int * v12340 = v12335->regs;
  int v12341 = v12340[9];
  int * v12342 = v12335->regs;
  int v12352 = v12339 | v12341;
  v12342[15] = v12352;
  struct StateT * v12344 = slot_161(v12335);
  return v12344;
}

struct StateT * slot_251(struct StateT * v8525) {
  int v8526 = v8525->timer;
  int v8580 = v8526 + 1;
  v8525->timer = v8580;
  int * v8528 = v8525->regs;
  int v8529 = v8528[10];
  int * v8530 = v8525->regs;
  int v8531 = v8530[11];
  int * v8532 = v8525->cache_keys;
  int v8533 = v8532[0];
  bool v8587 = v8533 == ((int)((unsigned int)(v8529 + 20) >> 2));
  int v8577;
  if (v8587) {
    int * v8534 = v8525->cache_vals;
    v8534[0] = v8531;
    v8577 = v8531;
  } else {
    int * v8537 = v8525->cache_keys;
    int v8538 = v8537[1];
    bool v8592 = v8538 == ((int)((unsigned int)(v8529 + 20) >> 2));
    int v8575;
    if (v8592) {
      int * v8539 = v8525->cache_keys;
      int * v8540 = v8525->cache_keys;
      int v8541 = v8540[0];
      v8539[1] = v8541;
      int * v8543 = v8525->cache_vals;
      int * v8544 = v8525->cache_vals;
      int v8545 = v8544[0];
      v8543[1] = v8545;
      int * v8547 = v8525->cache_keys;
      int v8600 = (int)((unsigned int)(v8529 + 20) >> 2);
      v8547[0] = v8600;
      int * v8549 = v8525->cache_vals;
      v8549[0] = v8531;
      int v8551 = v8525->timer;
      int v8603 = v8551 + 1;
      v8525->timer = v8603;
      v8575 = v8531;
    } else {
      int * v8554 = v8525->mem;
      int * v8555 = v8525->cache_keys;
      int v8556 = v8555[1];
      int * v8557 = v8525->cache_vals;
      int v8558 = v8557[1];
      v8554[v8556] = v8558;
      int * v8560 = v8525->cache_keys;
      int * v8561 = v8525->cache_keys;
      int v8562 = v8561[0];
      v8560[1] = v8562;
      int * v8564 = v8525->cache_vals;
      int * v8565 = v8525->cache_vals;
      int v8566 = v8565[0];
      v8564[1] = v8566;
      int * v8568 = v8525->cache_keys;
      int v8616 = (int)((unsigned int)(v8529 + 20) >> 2);
      v8568[0] = v8616;
      int * v8570 = v8525->cache_vals;
      v8570[0] = v8531;
      int v8572 = v8525->timer;
      int v8619 = v8572 + 100;
      v8525->timer = v8619;
      v8575 = v8531;
    }
    v8577 = v8575;
  }
  struct StateT * v8578 = slot_252(v8525);
  return v8578;
}

struct StateT * slot_65(struct StateT * v6913) {
  int v6914 = v6913->timer;
  int v6922 = v6914 + 1;
  v6913->timer = v6922;
  int * v6916 = v6913->regs;
  int v6917 = v6916[8];
  int * v6918 = v6913->regs;
  int v6926 = v6917 << 7;
  v6918[8] = v6926;
  struct StateT * v6920 = slot_66(v6913);
  return v6920;
}

struct StateT * slot_10(struct StateT * v899) {
  int v900 = v899->timer;
  int v954 = v900 + 1;
  v899->timer = v954;
  int * v902 = v899->regs;
  int v903 = v902[2];
  int * v904 = v899->regs;
  int v905 = v904[24];
  int * v906 = v899->cache_keys;
  int v907 = v906[0];
  bool v961 = v907 == ((int)((unsigned int)(v903 + 56) >> 2));
  int v951;
  if (v961) {
    int * v908 = v899->cache_vals;
    v908[0] = v905;
    v951 = v905;
  } else {
    int * v911 = v899->cache_keys;
    int v912 = v911[1];
    bool v966 = v912 == ((int)((unsigned int)(v903 + 56) >> 2));
    int v949;
    if (v966) {
      int * v913 = v899->cache_keys;
      int * v914 = v899->cache_keys;
      int v915 = v914[0];
      v913[1] = v915;
      int * v917 = v899->cache_vals;
      int * v918 = v899->cache_vals;
      int v919 = v918[0];
      v917[1] = v919;
      int * v921 = v899->cache_keys;
      int v974 = (int)((unsigned int)(v903 + 56) >> 2);
      v921[0] = v974;
      int * v923 = v899->cache_vals;
      v923[0] = v905;
      int v925 = v899->timer;
      int v977 = v925 + 1;
      v899->timer = v977;
      v949 = v905;
    } else {
      int * v928 = v899->mem;
      int * v929 = v899->cache_keys;
      int v930 = v929[1];
      int * v931 = v899->cache_vals;
      int v932 = v931[1];
      v928[v930] = v932;
      int * v934 = v899->cache_keys;
      int * v935 = v899->cache_keys;
      int v936 = v935[0];
      v934[1] = v936;
      int * v938 = v899->cache_vals;
      int * v939 = v899->cache_vals;
      int v940 = v939[0];
      v938[1] = v940;
      int * v942 = v899->cache_keys;
      int v990 = (int)((unsigned int)(v903 + 56) >> 2);
      v942[0] = v990;
      int * v944 = v899->cache_vals;
      v944[0] = v905;
      int v946 = v899->timer;
      int v993 = v946 + 100;
      v899->timer = v993;
      v949 = v905;
    }
    v951 = v949;
  }
  struct StateT * v952 = slot_11(v899);
  return v952;
}

struct StateT * slot_150(struct StateT * v12144) {
  int v12145 = v12144->timer;
  int v12155 = v12145 + 1;
  v12144->timer = v12155;
  int * v12147 = v12144->regs;
  int v12148 = v12147[9];
  int * v12149 = v12144->regs;
  int v12150 = v12149[6];
  int * v12151 = v12144->regs;
  int v12162 = v12148 ^ v12150;
  v12151[16] = v12162;
  struct StateT * v12153 = slot_151(v12144);
  return v12153;
}

struct StateT * slot_74(struct StateT * v7605) {
  int v7606 = v7605->timer;
  int v7616 = v7606 + 1;
  v7605->timer = v7616;
  int * v7608 = v7605->regs;
  int v7609 = v7608[14];
  int * v7610 = v7605->regs;
  int v7611 = v7610[22];
  int * v7612 = v7605->regs;
  int v7623 = v7609 + v7611;
  v7612[18] = v7623;
  struct StateT * v7614 = slot_75(v7605);
  return v7614;
}

struct StateT * slot_262(struct StateT * v9812) {
  int v9813 = v9812->timer;
  int v9871 = v9813 + 1;
  v9812->timer = v9871;
  int * v9815 = v9812->regs;
  int v9816 = v9815[2];
  int * v9817 = v9812->cache_keys;
  int v9818 = v9817[0];
  bool v9876 = v9818 == ((int)((unsigned int)(v9816 + 92) >> 2));
  int v9866;
  if (v9876) {
    int * v9819 = v9812->cache_vals;
    int v9820 = v9819[0];
    v9866 = v9820;
  } else {
    int * v9822 = v9812->cache_keys;
    int v9823 = v9822[1];
    bool v9881 = v9823 == ((int)((unsigned int)(v9816 + 92) >> 2));
    int v9864;
    if (v9881) {
      int * v9824 = v9812->cache_vals;
      int v9825 = v9824[1];
      int * v9826 = v9812->cache_keys;
      int * v9827 = v9812->cache_keys;
      int v9828 = v9827[0];
      v9826[1] = v9828;
      int * v9830 = v9812->cache_vals;
      int * v9831 = v9812->cache_vals;
      int v9832 = v9831[0];
      v9830[1] = v9832;
      int * v9834 = v9812->cache_keys;
      int v9890 = (int)((unsigned int)(v9816 + 92) >> 2);
      v9834[0] = v9890;
      int * v9836 = v9812->cache_vals;
      v9836[0] = v9825;
      int v9838 = v9812->timer;
      int v9893 = v9838 + 1;
      v9812->timer = v9893;
      v9864 = v9825;
    } else {
      int * v9841 = v9812->mem;
      int v9895 = (int)((unsigned int)(v9816 + 92) >> 2);
      int v9842 = v9841[v9895];
      int * v9843 = v9812->mem;
      int * v9844 = v9812->cache_keys;
      int v9845 = v9844[1];
      int * v9846 = v9812->cache_vals;
      int v9847 = v9846[1];
      v9843[v9845] = v9847;
      int * v9849 = v9812->cache_keys;
      int * v9850 = v9812->cache_keys;
      int v9851 = v9850[0];
      v9849[1] = v9851;
      int * v9853 = v9812->cache_vals;
      int * v9854 = v9812->cache_vals;
      int v9855 = v9854[0];
      v9853[1] = v9855;
      int * v9857 = v9812->cache_keys;
      v9857[0] = v9895;
      int * v9859 = v9812->cache_vals;
      v9859[0] = v9842;
      int v9861 = v9812->timer;
      int v9910 = v9861 + 100;
      v9812->timer = v9910;
      v9864 = v9842;
    }
    v9866 = v9864;
  }
  int * v9867 = v9812->regs;
  v9867[1] = v9866;
  struct StateT * v9869 = slot_263(v9812);
  return v9869;
}

struct StateT * slot_107(struct StateT * v10779) {
  int v10780 = v10779->timer;
  int v10790 = v10780 + 1;
  v10779->timer = v10790;
  int * v10782 = v10779->regs;
  int v10783 = v10782[16];
  int * v10784 = v10779->regs;
  int v10785 = v10784[15];
  int * v10786 = v10779->regs;
  int v10797 = v10783 ^ v10785;
  v10786[9] = v10797;
  struct StateT * v10788 = slot_108(v10779);
  return v10788;
}

struct StateT * slot_136(struct StateT * v11886) {
  int v11887 = v11886->timer;
  int v11895 = v11887 + 1;
  v11886->timer = v11895;
  int * v11889 = v11886->regs;
  int v11890 = v11889[15];
  int * v11891 = v11886->regs;
  int v11899 = v11890 << 7;
  v11891[15] = v11899;
  struct StateT * v11893 = slot_137(v11886);
  return v11893;
}

struct StateT * slot_84(struct StateT * v8040) {
  int v8041 = v8040->timer;
  int v8049 = v8041 + 1;
  v8040->timer = v8049;
  int * v8043 = v8040->regs;
  int v8044 = v8043[18];
  int * v8045 = v8040->regs;
  int v8054 = (int)((unsigned int)v8044 >> 23);
  v8045[20] = v8054;
  struct StateT * v8047 = slot_85(v8040);
  return v8047;
}

struct StateT * slot_28(struct StateT * v2577) {
  int v2578 = v2577->timer;
  int v2584 = v2578 + 1;
  v2577->timer = v2584;
  int * v2580 = v2577->regs;
  v2580[13] = 857759744;
  struct StateT * v2582 = slot_29(v2577);
  return v2582;
}

struct StateT * slot_155(struct StateT * v12249) {
  int v12250 = v12249->timer;
  int v12258 = v12250 + 1;
  v12249->timer = v12258;
  int * v12252 = v12249->regs;
  int v12253 = v12252[11];
  int * v12254 = v12249->regs;
  int v12263 = (int)((unsigned int)v12253 >> 23);
  v12254[9] = v12263;
  struct StateT * v12256 = slot_156(v12249);
  return v12256;
}

struct StateT * slot_177(struct StateT * v12658) {
  int v12659 = v12658->timer;
  int v12669 = v12659 + 1;
  v12658->timer = v12669;
  int * v12661 = v12658->regs;
  int v12662 = v12661[11];
  int * v12663 = v12658->regs;
  int v12664 = v12663[9];
  int * v12665 = v12658->regs;
  int v12675 = v12662 | v12664;
  v12665[11] = v12675;
  struct StateT * v12667 = slot_178(v12658);
  return v12667;
}

struct StateT * slot_229(struct StateT * v6962) {
  int v6963 = v6962->timer;
  int v7021 = v6963 + 1;
  v6962->timer = v7021;
  int * v6965 = v6962->regs;
  int v6966 = v6965[2];
  int * v6967 = v6962->cache_keys;
  int v6968 = v6967[0];
  bool v7026 = v6968 == ((int)((unsigned int)(v6966 + 28) >> 2));
  int v7016;
  if (v7026) {
    int * v6969 = v6962->cache_vals;
    int v6970 = v6969[0];
    v7016 = v6970;
  } else {
    int * v6972 = v6962->cache_keys;
    int v6973 = v6972[1];
    bool v7031 = v6973 == ((int)((unsigned int)(v6966 + 28) >> 2));
    int v7014;
    if (v7031) {
      int * v6974 = v6962->cache_vals;
      int v6975 = v6974[1];
      int * v6976 = v6962->cache_keys;
      int * v6977 = v6962->cache_keys;
      int v6978 = v6977[0];
      v6976[1] = v6978;
      int * v6980 = v6962->cache_vals;
      int * v6981 = v6962->cache_vals;
      int v6982 = v6981[0];
      v6980[1] = v6982;
      int * v6984 = v6962->cache_keys;
      int v7040 = (int)((unsigned int)(v6966 + 28) >> 2);
      v6984[0] = v7040;
      int * v6986 = v6962->cache_vals;
      v6986[0] = v6975;
      int v6988 = v6962->timer;
      int v7043 = v6988 + 1;
      v6962->timer = v7043;
      v7014 = v6975;
    } else {
      int * v6991 = v6962->mem;
      int v7045 = (int)((unsigned int)(v6966 + 28) >> 2);
      int v6992 = v6991[v7045];
      int * v6993 = v6962->mem;
      int * v6994 = v6962->cache_keys;
      int v6995 = v6994[1];
      int * v6996 = v6962->cache_vals;
      int v6997 = v6996[1];
      v6993[v6995] = v6997;
      int * v6999 = v6962->cache_keys;
      int * v7000 = v6962->cache_keys;
      int v7001 = v7000[0];
      v6999[1] = v7001;
      int * v7003 = v6962->cache_vals;
      int * v7004 = v6962->cache_vals;
      int v7005 = v7004[0];
      v7003[1] = v7005;
      int * v7007 = v6962->cache_keys;
      v7007[0] = v7045;
      int * v7009 = v6962->cache_vals;
      v7009[0] = v6992;
      int v7011 = v6962->timer;
      int v7060 = v7011 + 100;
      v6962->timer = v7060;
      v7014 = v6992;
    }
    v7016 = v7014;
  }
  int * v7017 = v6962->regs;
  v7017[30] = v7016;
  struct StateT * v7019 = slot_230(v6962);
  return v7019;
}

struct StateT * slot_17(struct StateT * v1514) {
  int v1515 = v1514->timer;
  int v1573 = v1515 + 1;
  v1514->timer = v1573;
  int * v1517 = v1514->regs;
  int v1518 = v1517[12];
  int * v1519 = v1514->cache_keys;
  int v1520 = v1519[0];
  bool v1578 = v1520 == ((int)((unsigned int)(v1518 + 8) >> 2));
  int v1568;
  if (v1578) {
    int * v1521 = v1514->cache_vals;
    int v1522 = v1521[0];
    v1568 = v1522;
  } else {
    int * v1524 = v1514->cache_keys;
    int v1525 = v1524[1];
    bool v1583 = v1525 == ((int)((unsigned int)(v1518 + 8) >> 2));
    int v1566;
    if (v1583) {
      int * v1526 = v1514->cache_vals;
      int v1527 = v1526[1];
      int * v1528 = v1514->cache_keys;
      int * v1529 = v1514->cache_keys;
      int v1530 = v1529[0];
      v1528[1] = v1530;
      int * v1532 = v1514->cache_vals;
      int * v1533 = v1514->cache_vals;
      int v1534 = v1533[0];
      v1532[1] = v1534;
      int * v1536 = v1514->cache_keys;
      int v1592 = (int)((unsigned int)(v1518 + 8) >> 2);
      v1536[0] = v1592;
      int * v1538 = v1514->cache_vals;
      v1538[0] = v1527;
      int v1540 = v1514->timer;
      int v1595 = v1540 + 1;
      v1514->timer = v1595;
      v1566 = v1527;
    } else {
      int * v1543 = v1514->mem;
      int v1597 = (int)((unsigned int)(v1518 + 8) >> 2);
      int v1544 = v1543[v1597];
      int * v1545 = v1514->mem;
      int * v1546 = v1514->cache_keys;
      int v1547 = v1546[1];
      int * v1548 = v1514->cache_vals;
      int v1549 = v1548[1];
      v1545[v1547] = v1549;
      int * v1551 = v1514->cache_keys;
      int * v1552 = v1514->cache_keys;
      int v1553 = v1552[0];
      v1551[1] = v1553;
      int * v1555 = v1514->cache_vals;
      int * v1556 = v1514->cache_vals;
      int v1557 = v1556[0];
      v1555[1] = v1557;
      int * v1559 = v1514->cache_keys;
      v1559[0] = v1597;
      int * v1561 = v1514->cache_vals;
      v1561[0] = v1544;
      int v1563 = v1514->timer;
      int v1612 = v1563 + 100;
      v1514->timer = v1612;
      v1566 = v1544;
    }
    v1568 = v1566;
  }
  int * v1569 = v1514->regs;
  v1569[7] = v1568;
  struct StateT * v1571 = slot_18(v1514);
  return v1571;
}

struct StateT * slot_181(struct StateT * v12731) {
  int v12732 = v12731->timer;
  int v12740 = v12732 + 1;
  v12731->timer = v12740;
  int * v12734 = v12731->regs;
  int v12735 = v12734[6];
  int * v12736 = v12731->regs;
  int v12745 = (int)((unsigned int)v12735 >> 19);
  v12736[9] = v12745;
  struct StateT * v12738 = slot_182(v12731);
  return v12738;
}

struct StateT * slot_197(struct StateT * v13034) {
  int v13035 = v13034->timer;
  int v13045 = v13035 + 1;
  v13034->timer = v13045;
  int * v13037 = v13034->regs;
  int v13038 = v13037[11];
  int * v13039 = v13034->regs;
  int v13040 = v13039[9];
  int * v13041 = v13034->regs;
  int v13051 = v13038 | v13040;
  v13041[11] = v13051;
  struct StateT * v13043 = slot_198(v13034);
  return v13043;
}

struct StateT * slot_207(struct StateT * v13213) {
  int v13214 = v13213->timer;
  int v13224 = v13214 + 1;
  v13213->timer = v13224;
  int * v13216 = v13213->regs;
  int v13217 = v13216[21];
  int * v13218 = v13213->regs;
  int v13219 = v13218[11];
  int * v13220 = v13213->regs;
  int v13230 = v13217 ^ v13219;
  v13220[21] = v13230;
  struct StateT * v13222 = slot_208(v13213);
  return v13222;
}

struct StateT * slot_156(struct StateT * v12266) {
  int v12267 = v12266->timer;
  int v12275 = v12267 + 1;
  v12266->timer = v12275;
  int * v12269 = v12266->regs;
  int v12270 = v12269[11];
  int * v12271 = v12266->regs;
  int v12279 = v12270 << 9;
  v12271[11] = v12279;
  struct StateT * v12273 = slot_157(v12266);
  return v12273;
}

struct StateT * slot_154(struct StateT * v12228) {
  int v12229 = v12228->timer;
  int v12239 = v12229 + 1;
  v12228->timer = v12239;
  int * v12231 = v12228->regs;
  int v12232 = v12231[16];
  int * v12233 = v12228->regs;
  int v12234 = v12233[22];
  int * v12235 = v12228->regs;
  int v12246 = v12232 + v12234;
  v12235[8] = v12246;
  struct StateT * v12237 = slot_155(v12228);
  return v12237;
}

struct StateT * slot_68(struct StateT * v7107) {
  int v7108 = v7107->timer;
  int v7118 = v7108 + 1;
  v7107->timer = v7118;
  int * v7110 = v7107->regs;
  int v7111 = v7110[13];
  int * v7112 = v7107->regs;
  int v7113 = v7112[9];
  int * v7114 = v7107->regs;
  int v7124 = v7111 ^ v7113;
  v7114[13] = v7124;
  struct StateT * v7116 = slot_69(v7107);
  return v7116;
}

struct StateT * slot_260(struct StateT * v9584) {
  int v9585 = v9584->timer;
  int v9639 = v9585 + 1;
  v9584->timer = v9639;
  int * v9587 = v9584->regs;
  int v9588 = v9587[10];
  int * v9589 = v9584->regs;
  int v9590 = v9589[1];
  int * v9591 = v9584->cache_keys;
  int v9592 = v9591[0];
  bool v9646 = v9592 == ((int)((unsigned int)(v9588 + 56) >> 2));
  int v9636;
  if (v9646) {
    int * v9593 = v9584->cache_vals;
    v9593[0] = v9590;
    v9636 = v9590;
  } else {
    int * v9596 = v9584->cache_keys;
    int v9597 = v9596[1];
    bool v9650 = v9597 == ((int)((unsigned int)(v9588 + 56) >> 2));
    int v9634;
    if (v9650) {
      int * v9598 = v9584->cache_keys;
      int * v9599 = v9584->cache_keys;
      int v9600 = v9599[0];
      v9598[1] = v9600;
      int * v9602 = v9584->cache_vals;
      int * v9603 = v9584->cache_vals;
      int v9604 = v9603[0];
      v9602[1] = v9604;
      int * v9606 = v9584->cache_keys;
      int v9658 = (int)((unsigned int)(v9588 + 56) >> 2);
      v9606[0] = v9658;
      int * v9608 = v9584->cache_vals;
      v9608[0] = v9590;
      int v9610 = v9584->timer;
      int v9661 = v9610 + 1;
      v9584->timer = v9661;
      v9634 = v9590;
    } else {
      int * v9613 = v9584->mem;
      int * v9614 = v9584->cache_keys;
      int v9615 = v9614[1];
      int * v9616 = v9584->cache_vals;
      int v9617 = v9616[1];
      v9613[v9615] = v9617;
      int * v9619 = v9584->cache_keys;
      int * v9620 = v9584->cache_keys;
      int v9621 = v9620[0];
      v9619[1] = v9621;
      int * v9623 = v9584->cache_vals;
      int * v9624 = v9584->cache_vals;
      int v9625 = v9624[0];
      v9623[1] = v9625;
      int * v9627 = v9584->cache_keys;
      int v9674 = (int)((unsigned int)(v9588 + 56) >> 2);
      v9627[0] = v9674;
      int * v9629 = v9584->cache_vals;
      v9629[0] = v9590;
      int v9631 = v9584->timer;
      int v9677 = v9631 + 100;
      v9584->timer = v9677;
      v9634 = v9590;
    }
    v9636 = v9634;
  }
  struct StateT * v9637 = slot_261(v9584);
  return v9637;
}

struct StateT * slot_105(struct StateT * v10532) {
  int v10533 = v10532->timer;
  int v10541 = v10533 + 1;
  v10532->timer = v10541;
  int * v10535 = v10532->regs;
  int v10536 = v10535[18];
  int * v10537 = v10532->regs;
  int v10545 = v10536 << 13;
  v10537[18] = v10545;
  struct StateT * v10539 = slot_106(v10532);
  return v10539;
}

struct StateT * slot_27(struct StateT * v2564) {
  int v2565 = v2564->timer;
  int v2571 = v2565 + 1;
  v2564->timer = v2571;
  int * v2567 = v2564->regs;
  v2567[12] = 1634762752;
  struct StateT * v2569 = slot_28(v2564);
  return v2569;
}

struct StateT * slot_164(struct StateT * v12408) {
  int v12409 = v12408->timer;
  int v12417 = v12409 + 1;
  v12408->timer = v12417;
  int * v12411 = v12408->regs;
  int v12412 = v12411[8];
  int * v12413 = v12408->regs;
  int v12422 = (int)((unsigned int)v12412 >> 23);
  v12413[9] = v12422;
  struct StateT * v12415 = slot_165(v12408);
  return v12415;
}

struct StateT * slot_15(struct StateT * v1304) {
  int v1305 = v1304->timer;
  int v1363 = v1305 + 1;
  v1304->timer = v1363;
  int * v1307 = v1304->regs;
  int v1308 = v1307[12];
  int * v1309 = v1304->cache_keys;
  int v1310 = v1309[0];
  bool v1368 = v1310 == ((int)((unsigned int)v1308 >> 2));
  int v1358;
  if (v1368) {
    int * v1311 = v1304->cache_vals;
    int v1312 = v1311[0];
    v1358 = v1312;
  } else {
    int * v1314 = v1304->cache_keys;
    int v1315 = v1314[1];
    bool v1373 = v1315 == ((int)((unsigned int)v1308 >> 2));
    int v1356;
    if (v1373) {
      int * v1316 = v1304->cache_vals;
      int v1317 = v1316[1];
      int * v1318 = v1304->cache_keys;
      int * v1319 = v1304->cache_keys;
      int v1320 = v1319[0];
      v1318[1] = v1320;
      int * v1322 = v1304->cache_vals;
      int * v1323 = v1304->cache_vals;
      int v1324 = v1323[0];
      v1322[1] = v1324;
      int * v1326 = v1304->cache_keys;
      int v1382 = (int)((unsigned int)v1308 >> 2);
      v1326[0] = v1382;
      int * v1328 = v1304->cache_vals;
      v1328[0] = v1317;
      int v1330 = v1304->timer;
      int v1385 = v1330 + 1;
      v1304->timer = v1385;
      v1356 = v1317;
    } else {
      int * v1333 = v1304->mem;
      int v1387 = (int)((unsigned int)v1308 >> 2);
      int v1334 = v1333[v1387];
      int * v1335 = v1304->mem;
      int * v1336 = v1304->cache_keys;
      int v1337 = v1336[1];
      int * v1338 = v1304->cache_vals;
      int v1339 = v1338[1];
      v1335[v1337] = v1339;
      int * v1341 = v1304->cache_keys;
      int * v1342 = v1304->cache_keys;
      int v1343 = v1342[0];
      v1341[1] = v1343;
      int * v1345 = v1304->cache_vals;
      int * v1346 = v1304->cache_vals;
      int v1347 = v1346[0];
      v1345[1] = v1347;
      int * v1349 = v1304->cache_keys;
      v1349[0] = v1387;
      int * v1351 = v1304->cache_vals;
      v1351[0] = v1334;
      int v1353 = v1304->timer;
      int v1402 = v1353 + 100;
      v1304->timer = v1402;
      v1356 = v1334;
    }
    v1358 = v1356;
  }
  int * v1359 = v1304->regs;
  v1359[29] = v1358;
  struct StateT * v1361 = slot_16(v1304);
  return v1361;
}

struct StateT * slot_133(struct StateT * v11827) {
  int v11828 = v11827->timer;
  int v11838 = v11828 + 1;
  v11827->timer = v11838;
  int * v11830 = v11827->regs;
  int v11831 = v11830[19];
  int * v11832 = v11827->regs;
  int v11833 = v11832[13];
  int * v11834 = v11827->regs;
  int v11845 = v11831 + v11833;
  v11834[16] = v11845;
  struct StateT * v11836 = slot_134(v11827);
  return v11836;
}

struct StateT * slot_56(struct StateT * v6241) {
  int v6242 = v6241->timer;
  int v6250 = v6242 + 1;
  v6241->timer = v6250;
  int * v6244 = v6241->regs;
  int v6245 = v6244[15];
  int * v6246 = v6241->regs;
  int v6254 = v6245 << 7;
  v6246[15] = v6254;
  struct StateT * v6248 = slot_57(v6241);
  return v6248;
}

struct StateT * slot_244(struct StateT * v7866) {
  int v7867 = v7866->timer;
  int v7877 = v7867 + 1;
  v7866->timer = v7877;
  int * v7869 = v7866->regs;
  int v7870 = v7869[19];
  int * v7871 = v7866->regs;
  int v7872 = v7871[7];
  int * v7873 = v7866->regs;
  int v7883 = v7870 + v7872;
  v7873[7] = v7883;
  struct StateT * v7875 = slot_245(v7866);
  return v7875;
}

struct StateT * slot_222(struct StateT * v6448) {
  int v6449 = v6448->timer;
  int v6507 = v6449 + 1;
  v6448->timer = v6507;
  int * v6451 = v6448->regs;
  int v6452 = v6451[2];
  int * v6453 = v6448->cache_keys;
  int v6454 = v6453[0];
  bool v6512 = v6454 == ((int)((unsigned int)(v6452 + 16) >> 2));
  int v6502;
  if (v6512) {
    int * v6455 = v6448->cache_vals;
    int v6456 = v6455[0];
    v6502 = v6456;
  } else {
    int * v6458 = v6448->cache_keys;
    int v6459 = v6458[1];
    bool v6517 = v6459 == ((int)((unsigned int)(v6452 + 16) >> 2));
    int v6500;
    if (v6517) {
      int * v6460 = v6448->cache_vals;
      int v6461 = v6460[1];
      int * v6462 = v6448->cache_keys;
      int * v6463 = v6448->cache_keys;
      int v6464 = v6463[0];
      v6462[1] = v6464;
      int * v6466 = v6448->cache_vals;
      int * v6467 = v6448->cache_vals;
      int v6468 = v6467[0];
      v6466[1] = v6468;
      int * v6470 = v6448->cache_keys;
      int v6526 = (int)((unsigned int)(v6452 + 16) >> 2);
      v6470[0] = v6526;
      int * v6472 = v6448->cache_vals;
      v6472[0] = v6461;
      int v6474 = v6448->timer;
      int v6529 = v6474 + 1;
      v6448->timer = v6529;
      v6500 = v6461;
    } else {
      int * v6477 = v6448->mem;
      int v6531 = (int)((unsigned int)(v6452 + 16) >> 2);
      int v6478 = v6477[v6531];
      int * v6479 = v6448->mem;
      int * v6480 = v6448->cache_keys;
      int v6481 = v6480[1];
      int * v6482 = v6448->cache_vals;
      int v6483 = v6482[1];
      v6479[v6481] = v6483;
      int * v6485 = v6448->cache_keys;
      int * v6486 = v6448->cache_keys;
      int v6487 = v6486[0];
      v6485[1] = v6487;
      int * v6489 = v6448->cache_vals;
      int * v6490 = v6448->cache_vals;
      int v6491 = v6490[0];
      v6489[1] = v6491;
      int * v6493 = v6448->cache_keys;
      v6493[0] = v6531;
      int * v6495 = v6448->cache_vals;
      v6495[0] = v6478;
      int v6497 = v6448->timer;
      int v6546 = v6497 + 100;
      v6448->timer = v6546;
      v6500 = v6478;
    }
    v6502 = v6500;
  }
  int * v6503 = v6448->regs;
  v6503[7] = v6502;
  struct StateT * v6505 = slot_223(v6448);
  return v6505;
}

struct StateT * slot_34(struct StateT * v2667) {
  int v2668 = v2667->timer;
  int v2676 = v2668 + 1;
  v2667->timer = v2676;
  int * v2670 = v2667->regs;
  int v2671 = v2670[22];
  int * v2672 = v2667->regs;
  int v2680 = v2671 + 1396;
  v2672[22] = v2680;
  struct StateT * v2674 = slot_35(v2667);
  return v2674;
}

struct StateT * slot_171(struct StateT * v12541) {
  int v12542 = v12541->timer;
  int v12552 = v12542 + 1;
  v12541->timer = v12552;
  int * v12544 = v12541->regs;
  int v12545 = v12544[27];
  int * v12546 = v12541->regs;
  int v12547 = v12546[23];
  int * v12548 = v12541->regs;
  int v12559 = v12545 + v12547;
  v12548[11] = v12559;
  struct StateT * v12550 = slot_172(v12541);
  return v12550;
}

struct StateT * slot_162(struct StateT * v12372) {
  int v12373 = v12372->timer;
  int v12381 = v12373 + 1;
  v12372->timer = v12381;
  int * v12375 = v12372->regs;
  int v12376 = v12375[6];
  int * v12377 = v12372->regs;
  int v12385 = v12376 << 9;
  v12377[6] = v12385;
  struct StateT * v12379 = slot_163(v12372);
  return v12379;
}

struct StateT * slot_21(struct StateT * v1934) {
  int v1935 = v1934->timer;
  int v1993 = v1935 + 1;
  v1934->timer = v1993;
  int * v1937 = v1934->regs;
  int v1938 = v1937[12];
  int * v1939 = v1934->cache_keys;
  int v1940 = v1939[0];
  bool v1998 = v1940 == ((int)((unsigned int)(v1938 + 24) >> 2));
  int v1988;
  if (v1998) {
    int * v1941 = v1934->cache_vals;
    int v1942 = v1941[0];
    v1988 = v1942;
  } else {
    int * v1944 = v1934->cache_keys;
    int v1945 = v1944[1];
    bool v2003 = v1945 == ((int)((unsigned int)(v1938 + 24) >> 2));
    int v1986;
    if (v2003) {
      int * v1946 = v1934->cache_vals;
      int v1947 = v1946[1];
      int * v1948 = v1934->cache_keys;
      int * v1949 = v1934->cache_keys;
      int v1950 = v1949[0];
      v1948[1] = v1950;
      int * v1952 = v1934->cache_vals;
      int * v1953 = v1934->cache_vals;
      int v1954 = v1953[0];
      v1952[1] = v1954;
      int * v1956 = v1934->cache_keys;
      int v2012 = (int)((unsigned int)(v1938 + 24) >> 2);
      v1956[0] = v2012;
      int * v1958 = v1934->cache_vals;
      v1958[0] = v1947;
      int v1960 = v1934->timer;
      int v2015 = v1960 + 1;
      v1934->timer = v2015;
      v1986 = v1947;
    } else {
      int * v1963 = v1934->mem;
      int v2017 = (int)((unsigned int)(v1938 + 24) >> 2);
      int v1964 = v1963[v2017];
      int * v1965 = v1934->mem;
      int * v1966 = v1934->cache_keys;
      int v1967 = v1966[1];
      int * v1968 = v1934->cache_vals;
      int v1969 = v1968[1];
      v1965[v1967] = v1969;
      int * v1971 = v1934->cache_keys;
      int * v1972 = v1934->cache_keys;
      int v1973 = v1972[0];
      v1971[1] = v1973;
      int * v1975 = v1934->cache_vals;
      int * v1976 = v1934->cache_vals;
      int v1977 = v1976[0];
      v1975[1] = v1977;
      int * v1979 = v1934->cache_keys;
      v1979[0] = v2017;
      int * v1981 = v1934->cache_vals;
      v1981[0] = v1964;
      int v1983 = v1934->timer;
      int v2032 = v1983 + 100;
      v1934->timer = v2032;
      v1986 = v1964;
    }
    v1988 = v1986;
  }
  int * v1989 = v1934->regs;
  v1989[24] = v1988;
  struct StateT * v1991 = slot_22(v1934);
  return v1991;
}

struct StateT * slot_239(struct StateT * v7688) {
  int v7689 = v7688->timer;
  int v7697 = v7689 + 1;
  v7688->timer = v7697;
  int * v7691 = v7688->regs;
  int v7692 = v7691[6];
  int * v7693 = v7688->regs;
  int v7701 = v7692 + 1134;
  v7693[6] = v7701;
  struct StateT * v7695 = slot_240(v7688);
  return v7695;
}

struct StateT * slot_118(struct StateT * v11545) {
  int v11546 = v11545->timer;
  int v11554 = v11546 + 1;
  v11545->timer = v11554;
  int * v11548 = v11545->regs;
  int v11549 = v11548[16];
  int * v11550 = v11545->regs;
  int v11559 = (int)((unsigned int)v11549 >> 14);
  v11550[6] = v11559;
  struct StateT * v11552 = slot_119(v11545);
  return v11552;
}

struct StateT * slot_121(struct StateT * v11598) {
  int v11599 = v11598->timer;
  int v11607 = v11599 + 1;
  v11598->timer = v11607;
  int * v11601 = v11598->regs;
  int v11602 = v11601[17];
  int * v11603 = v11598->regs;
  int v11612 = (int)((unsigned int)v11602 >> 14);
  v11603[6] = v11612;
  struct StateT * v11605 = slot_122(v11598);
  return v11605;
}

struct StateT * slot_144(struct StateT * v12028) {
  int v12029 = v12028->timer;
  int v12037 = v12029 + 1;
  v12028->timer = v12037;
  int * v12031 = v12028->regs;
  int v12032 = v12031[17];
  int * v12033 = v12028->regs;
  int v12042 = (int)((unsigned int)v12032 >> 25);
  v12033[5] = v12042;
  struct StateT * v12035 = slot_145(v12028);
  return v12035;
}

struct StateT * slot_267(struct StateT * v10427) {
  int v10428 = v10427->timer;
  int v10486 = v10428 + 1;
  v10427->timer = v10486;
  int * v10430 = v10427->regs;
  int v10431 = v10430[2];
  int * v10432 = v10427->cache_keys;
  int v10433 = v10432[0];
  bool v10491 = v10433 == ((int)((unsigned int)(v10431 + 72) >> 2));
  int v10481;
  if (v10491) {
    int * v10434 = v10427->cache_vals;
    int v10435 = v10434[0];
    v10481 = v10435;
  } else {
    int * v10437 = v10427->cache_keys;
    int v10438 = v10437[1];
    bool v10496 = v10438 == ((int)((unsigned int)(v10431 + 72) >> 2));
    int v10479;
    if (v10496) {
      int * v10439 = v10427->cache_vals;
      int v10440 = v10439[1];
      int * v10441 = v10427->cache_keys;
      int * v10442 = v10427->cache_keys;
      int v10443 = v10442[0];
      v10441[1] = v10443;
      int * v10445 = v10427->cache_vals;
      int * v10446 = v10427->cache_vals;
      int v10447 = v10446[0];
      v10445[1] = v10447;
      int * v10449 = v10427->cache_keys;
      int v10505 = (int)((unsigned int)(v10431 + 72) >> 2);
      v10449[0] = v10505;
      int * v10451 = v10427->cache_vals;
      v10451[0] = v10440;
      int v10453 = v10427->timer;
      int v10508 = v10453 + 1;
      v10427->timer = v10508;
      v10479 = v10440;
    } else {
      int * v10456 = v10427->mem;
      int v10510 = (int)((unsigned int)(v10431 + 72) >> 2);
      int v10457 = v10456[v10510];
      int * v10458 = v10427->mem;
      int * v10459 = v10427->cache_keys;
      int v10460 = v10459[1];
      int * v10461 = v10427->cache_vals;
      int v10462 = v10461[1];
      v10458[v10460] = v10462;
      int * v10464 = v10427->cache_keys;
      int * v10465 = v10427->cache_keys;
      int v10466 = v10465[0];
      v10464[1] = v10466;
      int * v10468 = v10427->cache_vals;
      int * v10469 = v10427->cache_vals;
      int v10470 = v10469[0];
      v10468[1] = v10470;
      int * v10472 = v10427->cache_keys;
      v10472[0] = v10510;
      int * v10474 = v10427->cache_vals;
      v10474[0] = v10457;
      int v10476 = v10427->timer;
      int v10525 = v10476 + 100;
      v10427->timer = v10525;
      v10479 = v10457;
    }
    v10481 = v10479;
  }
  int * v10482 = v10427->regs;
  v10482[20] = v10481;
  struct StateT * v10484 = slot_268(v10427);
  return v10484;
}

struct StateT * slot_201(struct StateT * v13107) {
  int v13108 = v13107->timer;
  int v13116 = v13108 + 1;
  v13107->timer = v13116;
  int * v13110 = v13107->regs;
  int v13111 = v13110[6];
  int * v13112 = v13107->regs;
  int v13121 = (int)((unsigned int)v13111 >> 14);
  v13112[9] = v13121;
  struct StateT * v13114 = slot_202(v13107);
  return v13114;
}

struct StateT * slot_94(struct StateT * v9216) {
  int v9217 = v9216->timer;
  int v9227 = v9217 + 1;
  v9216->timer = v9227;
  int * v9219 = v9216->regs;
  int v9220 = v9219[25];
  int * v9221 = v9216->regs;
  int v9222 = v9221[14];
  int * v9223 = v9216->regs;
  int v9234 = v9220 + v9222;
  v9223[18] = v9234;
  struct StateT * v9225 = slot_95(v9216);
  return v9225;
}

struct StateT * slot_63(struct StateT * v6751) {
  int v6752 = v6751->timer;
  int v6762 = v6752 + 1;
  v6751->timer = v6762;
  int * v6754 = v6751->regs;
  int v6755 = v6754[18];
  int * v6756 = v6751->regs;
  int v6757 = v6756[20];
  int * v6758 = v6751->regs;
  int v6768 = v6755 | v6757;
  v6758[18] = v6768;
  struct StateT * v6760 = slot_64(v6751);
  return v6760;
}

struct StateT * slot_146(struct StateT * v12061) {
  int v12062 = v12061->timer;
  int v12072 = v12062 + 1;
  v12061->timer = v12072;
  int * v12064 = v12061->regs;
  int v12065 = v12064[17];
  int * v12066 = v12061->regs;
  int v12067 = v12066[5];
  int * v12068 = v12061->regs;
  int v12079 = v12065 | v12067;
  v12068[6] = v12079;
  struct StateT * v12070 = slot_147(v12061);
  return v12070;
}

struct StateT * slot_24(struct StateT * v2249) {
  int v2250 = v2249->timer;
  int v2308 = v2250 + 1;
  v2249->timer = v2308;
  int * v2252 = v2249->regs;
  int v2253 = v2252[11];
  int * v2254 = v2249->cache_keys;
  int v2255 = v2254[0];
  bool v2313 = v2255 == ((int)((unsigned int)(v2253 + 4) >> 2));
  int v2303;
  if (v2313) {
    int * v2256 = v2249->cache_vals;
    int v2257 = v2256[0];
    v2303 = v2257;
  } else {
    int * v2259 = v2249->cache_keys;
    int v2260 = v2259[1];
    bool v2318 = v2260 == ((int)((unsigned int)(v2253 + 4) >> 2));
    int v2301;
    if (v2318) {
      int * v2261 = v2249->cache_vals;
      int v2262 = v2261[1];
      int * v2263 = v2249->cache_keys;
      int * v2264 = v2249->cache_keys;
      int v2265 = v2264[0];
      v2263[1] = v2265;
      int * v2267 = v2249->cache_vals;
      int * v2268 = v2249->cache_vals;
      int v2269 = v2268[0];
      v2267[1] = v2269;
      int * v2271 = v2249->cache_keys;
      int v2327 = (int)((unsigned int)(v2253 + 4) >> 2);
      v2271[0] = v2327;
      int * v2273 = v2249->cache_vals;
      v2273[0] = v2262;
      int v2275 = v2249->timer;
      int v2330 = v2275 + 1;
      v2249->timer = v2330;
      v2301 = v2262;
    } else {
      int * v2278 = v2249->mem;
      int v2332 = (int)((unsigned int)(v2253 + 4) >> 2);
      int v2279 = v2278[v2332];
      int * v2280 = v2249->mem;
      int * v2281 = v2249->cache_keys;
      int v2282 = v2281[1];
      int * v2283 = v2249->cache_vals;
      int v2284 = v2283[1];
      v2280[v2282] = v2284;
      int * v2286 = v2249->cache_keys;
      int * v2287 = v2249->cache_keys;
      int v2288 = v2287[0];
      v2286[1] = v2288;
      int * v2290 = v2249->cache_vals;
      int * v2291 = v2249->cache_vals;
      int v2292 = v2291[0];
      v2290[1] = v2292;
      int * v2294 = v2249->cache_keys;
      v2294[0] = v2332;
      int * v2296 = v2249->cache_vals;
      v2296[0] = v2279;
      int v2298 = v2249->timer;
      int v2347 = v2298 + 100;
      v2249->timer = v2347;
      v2301 = v2279;
    }
    v2303 = v2301;
  }
  int * v2304 = v2249->regs;
  v2304[25] = v2303;
  struct StateT * v2306 = slot_25(v2249);
  return v2306;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v11 = v3 + 1;
  v2->timer = v11;
  int * v5 = v2->regs;
  int v6 = v5[2];
  int * v7 = v2->regs;
  int v15 = v6 + -96;
  v7[2] = v15;
  struct StateT * v9 = slot_1(v2);
  return v9;
}

struct StateT * slot_195(struct StateT * v13001) {
  int v13002 = v13001->timer;
  int v13010 = v13002 + 1;
  v13001->timer = v13010;
  int * v13004 = v13001->regs;
  int v13005 = v13004[11];
  int * v13006 = v13001->regs;
  int v13015 = (int)((unsigned int)v13005 >> 14);
  v13006[9] = v13015;
  struct StateT * v13008 = slot_196(v13001);
  return v13008;
}

struct StateT * slot_125(struct StateT * v11668) {
  int v11669 = v11668->timer;
  int v11677 = v11669 + 1;
  v11668->timer = v11677;
  int * v11671 = v11668->regs;
  int v11672 = v11671[5];
  int * v11673 = v11668->regs;
  int v11681 = v11672 << 18;
  v11673[5] = v11681;
  struct StateT * v11675 = slot_126(v11668);
  return v11675;
}

struct StateT * slot_254(struct StateT * v8880) {
  int v8881 = v8880->timer;
  int v8935 = v8881 + 1;
  v8880->timer = v8935;
  int * v8883 = v8880->regs;
  int v8884 = v8883[10];
  int * v8885 = v8880->regs;
  int v8886 = v8885[26];
  int * v8887 = v8880->cache_keys;
  int v8888 = v8887[0];
  bool v8942 = v8888 == ((int)((unsigned int)(v8884 + 32) >> 2));
  int v8932;
  if (v8942) {
    int * v8889 = v8880->cache_vals;
    v8889[0] = v8886;
    v8932 = v8886;
  } else {
    int * v8892 = v8880->cache_keys;
    int v8893 = v8892[1];
    bool v8947 = v8893 == ((int)((unsigned int)(v8884 + 32) >> 2));
    int v8930;
    if (v8947) {
      int * v8894 = v8880->cache_keys;
      int * v8895 = v8880->cache_keys;
      int v8896 = v8895[0];
      v8894[1] = v8896;
      int * v8898 = v8880->cache_vals;
      int * v8899 = v8880->cache_vals;
      int v8900 = v8899[0];
      v8898[1] = v8900;
      int * v8902 = v8880->cache_keys;
      int v8955 = (int)((unsigned int)(v8884 + 32) >> 2);
      v8902[0] = v8955;
      int * v8904 = v8880->cache_vals;
      v8904[0] = v8886;
      int v8906 = v8880->timer;
      int v8958 = v8906 + 1;
      v8880->timer = v8958;
      v8930 = v8886;
    } else {
      int * v8909 = v8880->mem;
      int * v8910 = v8880->cache_keys;
      int v8911 = v8910[1];
      int * v8912 = v8880->cache_vals;
      int v8913 = v8912[1];
      v8909[v8911] = v8913;
      int * v8915 = v8880->cache_keys;
      int * v8916 = v8880->cache_keys;
      int v8917 = v8916[0];
      v8915[1] = v8917;
      int * v8919 = v8880->cache_vals;
      int * v8920 = v8880->cache_vals;
      int v8921 = v8920[0];
      v8919[1] = v8921;
      int * v8923 = v8880->cache_keys;
      int v8971 = (int)((unsigned int)(v8884 + 32) >> 2);
      v8923[0] = v8971;
      int * v8925 = v8880->cache_vals;
      v8925[0] = v8886;
      int v8927 = v8880->timer;
      int v8974 = v8927 + 100;
      v8880->timer = v8974;
      v8930 = v8886;
    }
    v8932 = v8930;
  }
  struct StateT * v8933 = slot_255(v8880);
  return v8933;
}

struct StateT * slot_148(struct StateT * v12102) {
  int v12103 = v12102->timer;
  int v12113 = v12103 + 1;
  v12102->timer = v12113;
  int * v12105 = v12102->regs;
  int v12106 = v12105[18];
  int * v12107 = v12102->regs;
  int v12108 = v12107[11];
  int * v12109 = v12102->regs;
  int v12120 = v12106 ^ v12108;
  v12109[5] = v12120;
  struct StateT * v12111 = slot_149(v12102);
  return v12111;
}

struct StateT * slot_126(struct StateT * v11684) {
  int v11685 = v11684->timer;
  int v11695 = v11685 + 1;
  v11684->timer = v11695;
  int * v11687 = v11684->regs;
  int v11688 = v11687[5];
  int * v11689 = v11684->regs;
  int v11690 = v11689[6];
  int * v11691 = v11684->regs;
  int v11701 = v11688 | v11690;
  v11691[5] = v11701;
  struct StateT * v11693 = slot_127(v11684);
  return v11693;
}

struct StateT * slot_223(struct StateT * v6573) {
  int v6574 = v6573->timer;
  int v6584 = v6574 + 1;
  v6573->timer = v6584;
  int * v6576 = v6573->regs;
  int v6577 = v6576[25];
  int * v6578 = v6573->regs;
  int v6579 = v6578[7];
  int * v6580 = v6573->regs;
  int v6590 = v6577 + v6579;
  v6580[25] = v6590;
  struct StateT * v6582 = slot_224(v6573);
  return v6582;
}

struct StateT * slot_79(struct StateT * v7773) {
  int v7774 = v7773->timer;
  int v7782 = v7774 + 1;
  v7773->timer = v7782;
  int * v7776 = v7773->regs;
  int v7777 = v7776[8];
  int * v7778 = v7773->regs;
  int v7786 = v7777 << 9;
  v7778[8] = v7786;
  struct StateT * v7780 = slot_80(v7773);
  return v7780;
}

struct StateT * slot_237(struct StateT * v7626) {
  int v7627 = v7626->timer;
  int v7633 = v7627 + 1;
  v7626->timer = v7633;
  int * v7629 = v7626->regs;
  v7629[30] = 1797283840;
  struct StateT * v7631 = slot_238(v7626);
  return v7631;
}

struct StateT * slot_41(struct StateT * v3185) {
  int v3186 = v3185->timer;
  int v3240 = v3186 + 1;
  v3185->timer = v3240;
  int * v3188 = v3185->regs;
  int v3189 = v3188[2];
  int * v3190 = v3185->regs;
  int v3191 = v3190[16];
  int * v3192 = v3185->cache_keys;
  int v3193 = v3192[0];
  bool v3247 = v3193 == ((int)((unsigned int)(v3189 + 32) >> 2));
  int v3237;
  if (v3247) {
    int * v3194 = v3185->cache_vals;
    v3194[0] = v3191;
    v3237 = v3191;
  } else {
    int * v3197 = v3185->cache_keys;
    int v3198 = v3197[1];
    bool v3252 = v3198 == ((int)((unsigned int)(v3189 + 32) >> 2));
    int v3235;
    if (v3252) {
      int * v3199 = v3185->cache_keys;
      int * v3200 = v3185->cache_keys;
      int v3201 = v3200[0];
      v3199[1] = v3201;
      int * v3203 = v3185->cache_vals;
      int * v3204 = v3185->cache_vals;
      int v3205 = v3204[0];
      v3203[1] = v3205;
      int * v3207 = v3185->cache_keys;
      int v3260 = (int)((unsigned int)(v3189 + 32) >> 2);
      v3207[0] = v3260;
      int * v3209 = v3185->cache_vals;
      v3209[0] = v3191;
      int v3211 = v3185->timer;
      int v3263 = v3211 + 1;
      v3185->timer = v3263;
      v3235 = v3191;
    } else {
      int * v3214 = v3185->mem;
      int * v3215 = v3185->cache_keys;
      int v3216 = v3215[1];
      int * v3217 = v3185->cache_vals;
      int v3218 = v3217[1];
      v3214[v3216] = v3218;
      int * v3220 = v3185->cache_keys;
      int * v3221 = v3185->cache_keys;
      int v3222 = v3221[0];
      v3220[1] = v3222;
      int * v3224 = v3185->cache_vals;
      int * v3225 = v3185->cache_vals;
      int v3226 = v3225[0];
      v3224[1] = v3226;
      int * v3228 = v3185->cache_keys;
      int v3276 = (int)((unsigned int)(v3189 + 32) >> 2);
      v3228[0] = v3276;
      int * v3230 = v3185->cache_vals;
      v3230[0] = v3191;
      int v3232 = v3185->timer;
      int v3279 = v3232 + 100;
      v3185->timer = v3279;
      v3235 = v3191;
    }
    v3237 = v3235;
  }
  struct StateT * v3238 = slot_42(v3185);
  return v3238;
}

struct StateT * slot_39(struct StateT * v2990) {
  int v2991 = v2990->timer;
  int v3045 = v2991 + 1;
  v2990->timer = v3045;
  int * v2993 = v2990->regs;
  int v2994 = v2993[2];
  int * v2995 = v2990->regs;
  int v2996 = v2995[1];
  int * v2997 = v2990->cache_keys;
  int v2998 = v2997[0];
  bool v3052 = v2998 == ((int)((unsigned int)(v2994 + 40) >> 2));
  int v3042;
  if (v3052) {
    int * v2999 = v2990->cache_vals;
    v2999[0] = v2996;
    v3042 = v2996;
  } else {
    int * v3002 = v2990->cache_keys;
    int v3003 = v3002[1];
    bool v3056 = v3003 == ((int)((unsigned int)(v2994 + 40) >> 2));
    int v3040;
    if (v3056) {
      int * v3004 = v2990->cache_keys;
      int * v3005 = v2990->cache_keys;
      int v3006 = v3005[0];
      v3004[1] = v3006;
      int * v3008 = v2990->cache_vals;
      int * v3009 = v2990->cache_vals;
      int v3010 = v3009[0];
      v3008[1] = v3010;
      int * v3012 = v2990->cache_keys;
      int v3064 = (int)((unsigned int)(v2994 + 40) >> 2);
      v3012[0] = v3064;
      int * v3014 = v2990->cache_vals;
      v3014[0] = v2996;
      int v3016 = v2990->timer;
      int v3067 = v3016 + 1;
      v2990->timer = v3067;
      v3040 = v2996;
    } else {
      int * v3019 = v2990->mem;
      int * v3020 = v2990->cache_keys;
      int v3021 = v3020[1];
      int * v3022 = v2990->cache_vals;
      int v3023 = v3022[1];
      v3019[v3021] = v3023;
      int * v3025 = v2990->cache_keys;
      int * v3026 = v2990->cache_keys;
      int v3027 = v3026[0];
      v3025[1] = v3027;
      int * v3029 = v2990->cache_vals;
      int * v3030 = v2990->cache_vals;
      int v3031 = v3030[0];
      v3029[1] = v3031;
      int * v3033 = v2990->cache_keys;
      int v3080 = (int)((unsigned int)(v2994 + 40) >> 2);
      v3033[0] = v3080;
      int * v3035 = v2990->cache_vals;
      v3035[0] = v2996;
      int v3037 = v2990->timer;
      int v3083 = v3037 + 100;
      v2990->timer = v3083;
      v3040 = v2996;
    }
    v3042 = v3040;
  }
  struct StateT * v3043 = slot_40(v2990);
  return v3043;
}

struct StateT * slot_142(struct StateT * v11992) {
  int v11993 = v11992->timer;
  int v12001 = v11993 + 1;
  v11992->timer = v12001;
  int * v11995 = v11992->regs;
  int v11996 = v11995[16];
  int * v11997 = v11992->regs;
  int v12005 = v11996 << 7;
  v11997[16] = v12005;
  struct StateT * v11999 = slot_143(v11992);
  return v11999;
}

struct StateT * slot_60(struct StateT * v6553) {
  int v6554 = v6553->timer;
  int v6564 = v6554 + 1;
  v6553->timer = v6564;
  int * v6556 = v6553->regs;
  int v6557 = v6556[20];
  int * v6558 = v6553->regs;
  int v6559 = v6558[9];
  int * v6560 = v6553->regs;
  int v6570 = v6557 | v6559;
  v6560[9] = v6570;
  struct StateT * v6562 = slot_61(v6553);
  return v6562;
}

struct StateT * slot_238(struct StateT * v7656) {
  int v7657 = v7656->timer;
  int v7665 = v7657 + 1;
  v7656->timer = v7665;
  int * v7659 = v7656->regs;
  int v7660 = v7659[15];
  int * v7661 = v7656->regs;
  int v7669 = v7660 + -1947;
  v7661[15] = v7669;
  struct StateT * v7663 = slot_239(v7656);
  return v7663;
}

struct StateT * slot_112(struct StateT * v11408) {
  int v11409 = v11408->timer;
  int v11419 = v11409 + 1;
  v11408->timer = v11419;
  int * v11411 = v11408->regs;
  int v11412 = v11411[23];
  int * v11413 = v11408->regs;
  int v11414 = v11413[24];
  int * v11415 = v11408->regs;
  int v11426 = v11412 + v11414;
  v11415[16] = v11426;
  struct StateT * v11417 = slot_113(v11408);
  return v11417;
}

struct StateT * slot_256(struct StateT * v9118) {
  int v9119 = v9118->timer;
  int v9173 = v9119 + 1;
  v9118->timer = v9173;
  int * v9121 = v9118->regs;
  int v9122 = v9121[10];
  int * v9123 = v9118->regs;
  int v9124 = v9123[7];
  int * v9125 = v9118->cache_keys;
  int v9126 = v9125[0];
  bool v9180 = v9126 == ((int)((unsigned int)(v9122 + 40) >> 2));
  int v9170;
  if (v9180) {
    int * v9127 = v9118->cache_vals;
    v9127[0] = v9124;
    v9170 = v9124;
  } else {
    int * v9130 = v9118->cache_keys;
    int v9131 = v9130[1];
    bool v9185 = v9131 == ((int)((unsigned int)(v9122 + 40) >> 2));
    int v9168;
    if (v9185) {
      int * v9132 = v9118->cache_keys;
      int * v9133 = v9118->cache_keys;
      int v9134 = v9133[0];
      v9132[1] = v9134;
      int * v9136 = v9118->cache_vals;
      int * v9137 = v9118->cache_vals;
      int v9138 = v9137[0];
      v9136[1] = v9138;
      int * v9140 = v9118->cache_keys;
      int v9193 = (int)((unsigned int)(v9122 + 40) >> 2);
      v9140[0] = v9193;
      int * v9142 = v9118->cache_vals;
      v9142[0] = v9124;
      int v9144 = v9118->timer;
      int v9196 = v9144 + 1;
      v9118->timer = v9196;
      v9168 = v9124;
    } else {
      int * v9147 = v9118->mem;
      int * v9148 = v9118->cache_keys;
      int v9149 = v9148[1];
      int * v9150 = v9118->cache_vals;
      int v9151 = v9150[1];
      v9147[v9149] = v9151;
      int * v9153 = v9118->cache_keys;
      int * v9154 = v9118->cache_keys;
      int v9155 = v9154[0];
      v9153[1] = v9155;
      int * v9157 = v9118->cache_vals;
      int * v9158 = v9118->cache_vals;
      int v9159 = v9158[0];
      v9157[1] = v9159;
      int * v9161 = v9118->cache_keys;
      int v9209 = (int)((unsigned int)(v9122 + 40) >> 2);
      v9161[0] = v9209;
      int * v9163 = v9118->cache_vals;
      v9163[0] = v9124;
      int v9165 = v9118->timer;
      int v9212 = v9165 + 100;
      v9118->timer = v9212;
      v9168 = v9124;
    }
    v9170 = v9168;
  }
  struct StateT * v9171 = slot_257(v9118);
  return v9171;
}

struct StateT * slot_272(struct StateT * v11051) {
  int v11052 = v11051->timer;
  int v11110 = v11052 + 1;
  v11051->timer = v11110;
  int * v11054 = v11051->regs;
  int v11055 = v11054[2];
  int * v11056 = v11051->cache_keys;
  int v11057 = v11056[0];
  bool v11115 = v11057 == ((int)((unsigned int)(v11055 + 52) >> 2));
  int v11105;
  if (v11115) {
    int * v11058 = v11051->cache_vals;
    int v11059 = v11058[0];
    v11105 = v11059;
  } else {
    int * v11061 = v11051->cache_keys;
    int v11062 = v11061[1];
    bool v11120 = v11062 == ((int)((unsigned int)(v11055 + 52) >> 2));
    int v11103;
    if (v11120) {
      int * v11063 = v11051->cache_vals;
      int v11064 = v11063[1];
      int * v11065 = v11051->cache_keys;
      int * v11066 = v11051->cache_keys;
      int v11067 = v11066[0];
      v11065[1] = v11067;
      int * v11069 = v11051->cache_vals;
      int * v11070 = v11051->cache_vals;
      int v11071 = v11070[0];
      v11069[1] = v11071;
      int * v11073 = v11051->cache_keys;
      int v11129 = (int)((unsigned int)(v11055 + 52) >> 2);
      v11073[0] = v11129;
      int * v11075 = v11051->cache_vals;
      v11075[0] = v11064;
      int v11077 = v11051->timer;
      int v11132 = v11077 + 1;
      v11051->timer = v11132;
      v11103 = v11064;
    } else {
      int * v11080 = v11051->mem;
      int v11134 = (int)((unsigned int)(v11055 + 52) >> 2);
      int v11081 = v11080[v11134];
      int * v11082 = v11051->mem;
      int * v11083 = v11051->cache_keys;
      int v11084 = v11083[1];
      int * v11085 = v11051->cache_vals;
      int v11086 = v11085[1];
      v11082[v11084] = v11086;
      int * v11088 = v11051->cache_keys;
      int * v11089 = v11051->cache_keys;
      int v11090 = v11089[0];
      v11088[1] = v11090;
      int * v11092 = v11051->cache_vals;
      int * v11093 = v11051->cache_vals;
      int v11094 = v11093[0];
      v11092[1] = v11094;
      int * v11096 = v11051->cache_keys;
      v11096[0] = v11134;
      int * v11098 = v11051->cache_vals;
      v11098[0] = v11081;
      int v11100 = v11051->timer;
      int v11149 = v11100 + 100;
      v11051->timer = v11149;
      v11103 = v11081;
    }
    v11105 = v11103;
  }
  int * v11106 = v11051->regs;
  v11106[25] = v11105;
  struct StateT * v11108 = slot_273(v11051);
  return v11108;
}

struct StateT * slot_47(struct StateT * v3530) {
  int v3531 = v3530->timer;
  int v3539 = v3531 + 1;
  v3530->timer = v3539;
  int * v3533 = v3530->regs;
  int v3534 = v3533[29];
  int * v3535 = v3530->regs;
  v3535[23] = v3534;
  struct StateT * v3537 = slot_48(v3530);
  return v3537;
}

struct StateT * slot_214(struct StateT * v5983) {
  int v5984 = v5983->timer;
  int v5994 = v5984 + 1;
  v5983->timer = v5994;
  int * v5986 = v5983->regs;
  int v5987 = v5986[27];
  int * v5988 = v5983->regs;
  int v5989 = v5988[28];
  int * v5990 = v5983->regs;
  int v6000 = v5987 + v5989;
  v5990[28] = v6000;
  struct StateT * v5992 = slot_215(v5983);
  return v5992;
}

struct StateT * slot_29(struct StateT * v2590) {
  int v2591 = v2590->timer;
  int v2597 = v2591 + 1;
  v2590->timer = v2597;
  int * v2593 = v2590->regs;
  v2593[14] = 2036477952;
  struct StateT * v2595 = slot_30(v2590);
  return v2595;
}

struct StateT * slot_16(struct StateT * v1409) {
  int v1410 = v1409->timer;
  int v1468 = v1410 + 1;
  v1409->timer = v1468;
  int * v1412 = v1409->regs;
  int v1413 = v1412[12];
  int * v1414 = v1409->cache_keys;
  int v1415 = v1414[0];
  bool v1473 = v1415 == ((int)((unsigned int)(v1413 + 4) >> 2));
  int v1463;
  if (v1473) {
    int * v1416 = v1409->cache_vals;
    int v1417 = v1416[0];
    v1463 = v1417;
  } else {
    int * v1419 = v1409->cache_keys;
    int v1420 = v1419[1];
    bool v1478 = v1420 == ((int)((unsigned int)(v1413 + 4) >> 2));
    int v1461;
    if (v1478) {
      int * v1421 = v1409->cache_vals;
      int v1422 = v1421[1];
      int * v1423 = v1409->cache_keys;
      int * v1424 = v1409->cache_keys;
      int v1425 = v1424[0];
      v1423[1] = v1425;
      int * v1427 = v1409->cache_vals;
      int * v1428 = v1409->cache_vals;
      int v1429 = v1428[0];
      v1427[1] = v1429;
      int * v1431 = v1409->cache_keys;
      int v1487 = (int)((unsigned int)(v1413 + 4) >> 2);
      v1431[0] = v1487;
      int * v1433 = v1409->cache_vals;
      v1433[0] = v1422;
      int v1435 = v1409->timer;
      int v1490 = v1435 + 1;
      v1409->timer = v1490;
      v1461 = v1422;
    } else {
      int * v1438 = v1409->mem;
      int v1492 = (int)((unsigned int)(v1413 + 4) >> 2);
      int v1439 = v1438[v1492];
      int * v1440 = v1409->mem;
      int * v1441 = v1409->cache_keys;
      int v1442 = v1441[1];
      int * v1443 = v1409->cache_vals;
      int v1444 = v1443[1];
      v1440[v1442] = v1444;
      int * v1446 = v1409->cache_keys;
      int * v1447 = v1409->cache_keys;
      int v1448 = v1447[0];
      v1446[1] = v1448;
      int * v1450 = v1409->cache_vals;
      int * v1451 = v1409->cache_vals;
      int v1452 = v1451[0];
      v1450[1] = v1452;
      int * v1454 = v1409->cache_keys;
      v1454[0] = v1492;
      int * v1456 = v1409->cache_vals;
      v1456[0] = v1439;
      int v1458 = v1409->timer;
      int v1507 = v1458 + 100;
      v1409->timer = v1507;
      v1461 = v1439;
    }
    v1463 = v1461;
  }
  int * v1464 = v1409->regs;
  v1464[28] = v1463;
  struct StateT * v1466 = slot_17(v1409);
  return v1466;
}

struct StateT * slot_245(struct StateT * v7902) {
  int v7903 = v7902->timer;
  int v7913 = v7903 + 1;
  v7902->timer = v7913;
  int * v7905 = v7902->regs;
  int v7906 = v7905[22];
  int * v7907 = v7902->regs;
  int v7908 = v7907[30];
  int * v7909 = v7902->regs;
  int v7919 = v7906 + v7908;
  v7909[30] = v7919;
  struct StateT * v7911 = slot_246(v7902);
  return v7911;
}

struct StateT * slot_113(struct StateT * v11445) {
  int v11446 = v11445->timer;
  int v11456 = v11446 + 1;
  v11445->timer = v11456;
  int * v11448 = v11445->regs;
  int v11449 = v11448[18];
  int * v11450 = v11445->regs;
  int v11451 = v11450[27];
  int * v11452 = v11445->regs;
  int v11463 = v11449 + v11451;
  v11452[17] = v11463;
  struct StateT * v11454 = slot_114(v11445);
  return v11454;
}

struct StateT * slot_151(struct StateT * v12165) {
  int v12166 = v12165->timer;
  int v12176 = v12166 + 1;
  v12165->timer = v12176;
  int * v12168 = v12165->regs;
  int v12169 = v12168[23];
  int * v12170 = v12165->regs;
  int v12171 = v12170[21];
  int * v12172 = v12165->regs;
  int v12183 = v12169 + v12171;
  v12172[11] = v12183;
  struct StateT * v12174 = slot_152(v12165);
  return v12174;
}

struct StateT * slot_7(struct StateT * v605) {
  int v606 = v605->timer;
  int v660 = v606 + 1;
  v605->timer = v660;
  int * v608 = v605->regs;
  int v609 = v608[2];
  int * v610 = v605->regs;
  int v611 = v610[21];
  int * v612 = v605->cache_keys;
  int v613 = v612[0];
  bool v667 = v613 == ((int)((unsigned int)(v609 + 68) >> 2));
  int v657;
  if (v667) {
    int * v614 = v605->cache_vals;
    v614[0] = v611;
    v657 = v611;
  } else {
    int * v617 = v605->cache_keys;
    int v618 = v617[1];
    bool v672 = v618 == ((int)((unsigned int)(v609 + 68) >> 2));
    int v655;
    if (v672) {
      int * v619 = v605->cache_keys;
      int * v620 = v605->cache_keys;
      int v621 = v620[0];
      v619[1] = v621;
      int * v623 = v605->cache_vals;
      int * v624 = v605->cache_vals;
      int v625 = v624[0];
      v623[1] = v625;
      int * v627 = v605->cache_keys;
      int v680 = (int)((unsigned int)(v609 + 68) >> 2);
      v627[0] = v680;
      int * v629 = v605->cache_vals;
      v629[0] = v611;
      int v631 = v605->timer;
      int v683 = v631 + 1;
      v605->timer = v683;
      v655 = v611;
    } else {
      int * v634 = v605->mem;
      int * v635 = v605->cache_keys;
      int v636 = v635[1];
      int * v637 = v605->cache_vals;
      int v638 = v637[1];
      v634[v636] = v638;
      int * v640 = v605->cache_keys;
      int * v641 = v605->cache_keys;
      int v642 = v641[0];
      v640[1] = v642;
      int * v644 = v605->cache_vals;
      int * v645 = v605->cache_vals;
      int v646 = v645[0];
      v644[1] = v646;
      int * v648 = v605->cache_keys;
      int v696 = (int)((unsigned int)(v609 + 68) >> 2);
      v648[0] = v696;
      int * v650 = v605->cache_vals;
      v650[0] = v611;
      int v652 = v605->timer;
      int v699 = v652 + 100;
      v605->timer = v699;
      v655 = v611;
    }
    v657 = v655;
  }
  struct StateT * v658 = slot_8(v605);
  return v658;
}

struct StateT * slot_124(struct StateT * v11651) {
  int v11652 = v11651->timer;
  int v11660 = v11652 + 1;
  v11651->timer = v11660;
  int * v11654 = v11651->regs;
  int v11655 = v11654[5];
  int * v11656 = v11651->regs;
  int v11665 = (int)((unsigned int)v11655 >> 14);
  v11656[6] = v11665;
  struct StateT * v11658 = slot_125(v11651);
  return v11658;
}

struct StateT * slot_191(struct StateT * v12917) {
  int v12918 = v12917->timer;
  int v12928 = v12918 + 1;
  v12917->timer = v12928;
  int * v12920 = v12917->regs;
  int v12921 = v12920[14];
  int * v12922 = v12917->regs;
  int v12923 = v12922[27];
  int * v12924 = v12917->regs;
  int v12935 = v12921 + v12923;
  v12924[11] = v12935;
  struct StateT * v12926 = slot_192(v12917);
  return v12926;
}

struct StateT * slot_103(struct StateT * v10285) {
  int v10286 = v10285->timer;
  int v10296 = v10286 + 1;
  v10285->timer = v10296;
  int * v10288 = v10285->regs;
  int v10289 = v10288[9];
  int * v10290 = v10285->regs;
  int v10291 = v10290[20];
  int * v10292 = v10285->regs;
  int v10302 = v10289 | v10291;
  v10292[20] = v10302;
  struct StateT * v10294 = slot_104(v10285);
  return v10294;
}

struct StateT * slot_128(struct StateT * v11724) {
  int v11725 = v11724->timer;
  int v11735 = v11725 + 1;
  v11724->timer = v11735;
  int * v11727 = v11724->regs;
  int v11728 = v11727[11];
  int * v11729 = v11724->regs;
  int v11730 = v11729[16];
  int * v11731 = v11724->regs;
  int v11742 = v11728 ^ v11730;
  v11731[20] = v11742;
  struct StateT * v11733 = slot_129(v11724);
  return v11733;
}

struct StateT * slot_19(struct StateT * v1724) {
  int v1725 = v1724->timer;
  int v1783 = v1725 + 1;
  v1724->timer = v1783;
  int * v1727 = v1724->regs;
  int v1728 = v1727[12];
  int * v1729 = v1724->cache_keys;
  int v1730 = v1729[0];
  bool v1788 = v1730 == ((int)((unsigned int)(v1728 + 16) >> 2));
  int v1778;
  if (v1788) {
    int * v1731 = v1724->cache_vals;
    int v1732 = v1731[0];
    v1778 = v1732;
  } else {
    int * v1734 = v1724->cache_keys;
    int v1735 = v1734[1];
    bool v1793 = v1735 == ((int)((unsigned int)(v1728 + 16) >> 2));
    int v1776;
    if (v1793) {
      int * v1736 = v1724->cache_vals;
      int v1737 = v1736[1];
      int * v1738 = v1724->cache_keys;
      int * v1739 = v1724->cache_keys;
      int v1740 = v1739[0];
      v1738[1] = v1740;
      int * v1742 = v1724->cache_vals;
      int * v1743 = v1724->cache_vals;
      int v1744 = v1743[0];
      v1742[1] = v1744;
      int * v1746 = v1724->cache_keys;
      int v1802 = (int)((unsigned int)(v1728 + 16) >> 2);
      v1746[0] = v1802;
      int * v1748 = v1724->cache_vals;
      v1748[0] = v1737;
      int v1750 = v1724->timer;
      int v1805 = v1750 + 1;
      v1724->timer = v1805;
      v1776 = v1737;
    } else {
      int * v1753 = v1724->mem;
      int v1807 = (int)((unsigned int)(v1728 + 16) >> 2);
      int v1754 = v1753[v1807];
      int * v1755 = v1724->mem;
      int * v1756 = v1724->cache_keys;
      int v1757 = v1756[1];
      int * v1758 = v1724->cache_vals;
      int v1759 = v1758[1];
      v1755[v1757] = v1759;
      int * v1761 = v1724->cache_keys;
      int * v1762 = v1724->cache_keys;
      int v1763 = v1762[0];
      v1761[1] = v1763;
      int * v1765 = v1724->cache_vals;
      int * v1766 = v1724->cache_vals;
      int v1767 = v1766[0];
      v1765[1] = v1767;
      int * v1769 = v1724->cache_keys;
      v1769[0] = v1807;
      int * v1771 = v1724->cache_vals;
      v1771[0] = v1754;
      int v1773 = v1724->timer;
      int v1822 = v1773 + 100;
      v1724->timer = v1822;
      v1776 = v1754;
    }
    v1778 = v1776;
  }
  int * v1779 = v1724->regs;
  v1779[17] = v1778;
  struct StateT * v1781 = slot_20(v1724);
  return v1781;
}

struct StateT * slot_87(struct StateT * v8387) {
  int v8388 = v8387->timer;
  int v8398 = v8388 + 1;
  v8387->timer = v8398;
  int * v8390 = v8387->regs;
  int v8391 = v8390[26];
  int * v8392 = v8387->regs;
  int v8393 = v8392[15];
  int * v8394 = v8387->regs;
  int v8404 = v8391 ^ v8393;
  v8394[26] = v8404;
  struct StateT * v8396 = slot_88(v8387);
  return v8396;
}

struct StateT * slot_67(struct StateT * v7067) {
  int v7068 = v7067->timer;
  int v7078 = v7068 + 1;
  v7067->timer = v7078;
  int * v7070 = v7067->regs;
  int v7071 = v7070[12];
  int * v7072 = v7067->regs;
  int v7073 = v7072[15];
  int * v7074 = v7067->regs;
  int v7084 = v7071 ^ v7073;
  v7074[12] = v7084;
  struct StateT * v7076 = slot_68(v7067);
  return v7076;
}

struct StateT * slot_81(struct StateT * v7849) {
  int v7850 = v7849->timer;
  int v7858 = v7850 + 1;
  v7849->timer = v7858;
  int * v7852 = v7849->regs;
  int v7853 = v7852[9];
  int * v7854 = v7849->regs;
  int v7863 = (int)((unsigned int)v7853 >> 23);
  v7854[20] = v7863;
  struct StateT * v7856 = slot_82(v7849);
  return v7856;
}

struct StateT * slot_95(struct StateT * v9335) {
  int v9336 = v9335->timer;
  int v9344 = v9336 + 1;
  v9335->timer = v9344;
  int * v9338 = v9335->regs;
  int v9339 = v9338[15];
  int * v9340 = v9335->regs;
  int v9349 = (int)((unsigned int)v9339 >> 19);
  v9340[20] = v9349;
  struct StateT * v9342 = slot_96(v9335);
  return v9342;
}

struct StateT * slot_115(struct StateT * v11492) {
  int v11493 = v11492->timer;
  int v11501 = v11493 + 1;
  v11492->timer = v11501;
  int * v11495 = v11492->regs;
  int v11496 = v11495[15];
  int * v11497 = v11492->regs;
  int v11506 = (int)((unsigned int)v11496 >> 14);
  v11497[6] = v11506;
  struct StateT * v11499 = slot_116(v11492);
  return v11499;
}

struct StateT * slot_78(struct StateT * v7740) {
  int v7741 = v7740->timer;
  int v7749 = v7741 + 1;
  v7740->timer = v7749;
  int * v7743 = v7740->regs;
  int v7744 = v7743[8];
  int * v7745 = v7740->regs;
  int v7754 = (int)((unsigned int)v7744 >> 23);
  v7745[20] = v7754;
  struct StateT * v7747 = slot_79(v7740);
  return v7747;
}

struct StateT * slot_32(struct StateT * v2637) {
  int v2638 = v2637->timer;
  int v2646 = v2638 + 1;
  v2637->timer = v2646;
  int * v2640 = v2637->regs;
  int v2641 = v2640[14];
  int * v2642 = v2637->regs;
  int v2651 = v2641 + -718;
  v2642[19] = v2651;
  struct StateT * v2644 = slot_33(v2637);
  return v2644;
}

struct StateT * slot_205(struct StateT * v13177) {
  int v13178 = v13177->timer;
  int v13186 = v13178 + 1;
  v13177->timer = v13186;
  int * v13180 = v13177->regs;
  int v13181 = v13180[8];
  int * v13182 = v13177->regs;
  int v13190 = v13181 << 18;
  v13182[8] = v13190;
  struct StateT * v13184 = slot_206(v13177);
  return v13184;
}

struct StateT * slot_193(struct StateT * v12959) {
  int v12960 = v12959->timer;
  int v12970 = v12960 + 1;
  v12959->timer = v12970;
  int * v12962 = v12959->regs;
  int v12963 = v12962[13];
  int * v12964 = v12959->regs;
  int v12965 = v12964[26];
  int * v12966 = v12959->regs;
  int v12977 = v12963 + v12965;
  v12966[6] = v12977;
  struct StateT * v12968 = slot_194(v12959);
  return v12968;
}

struct StateT * slot_233(struct StateT * v7292) {
  int v7293 = v7292->timer;
  int v7351 = v7293 + 1;
  v7292->timer = v7351;
  int * v7295 = v7292->regs;
  int v7296 = v7295[2];
  int * v7297 = v7292->cache_keys;
  int v7298 = v7297[0];
  bool v7356 = v7298 == ((int)((unsigned int)(v7296 + 36) >> 2));
  int v7346;
  if (v7356) {
    int * v7299 = v7292->cache_vals;
    int v7300 = v7299[0];
    v7346 = v7300;
  } else {
    int * v7302 = v7292->cache_keys;
    int v7303 = v7302[1];
    bool v7361 = v7303 == ((int)((unsigned int)(v7296 + 36) >> 2));
    int v7344;
    if (v7361) {
      int * v7304 = v7292->cache_vals;
      int v7305 = v7304[1];
      int * v7306 = v7292->cache_keys;
      int * v7307 = v7292->cache_keys;
      int v7308 = v7307[0];
      v7306[1] = v7308;
      int * v7310 = v7292->cache_vals;
      int * v7311 = v7292->cache_vals;
      int v7312 = v7311[0];
      v7310[1] = v7312;
      int * v7314 = v7292->cache_keys;
      int v7370 = (int)((unsigned int)(v7296 + 36) >> 2);
      v7314[0] = v7370;
      int * v7316 = v7292->cache_vals;
      v7316[0] = v7305;
      int v7318 = v7292->timer;
      int v7373 = v7318 + 1;
      v7292->timer = v7373;
      v7344 = v7305;
    } else {
      int * v7321 = v7292->mem;
      int v7375 = (int)((unsigned int)(v7296 + 36) >> 2);
      int v7322 = v7321[v7375];
      int * v7323 = v7292->mem;
      int * v7324 = v7292->cache_keys;
      int v7325 = v7324[1];
      int * v7326 = v7292->cache_vals;
      int v7327 = v7326[1];
      v7323[v7325] = v7327;
      int * v7329 = v7292->cache_keys;
      int * v7330 = v7292->cache_keys;
      int v7331 = v7330[0];
      v7329[1] = v7331;
      int * v7333 = v7292->cache_vals;
      int * v7334 = v7292->cache_vals;
      int v7335 = v7334[0];
      v7333[1] = v7335;
      int * v7337 = v7292->cache_keys;
      v7337[0] = v7375;
      int * v7339 = v7292->cache_vals;
      v7339[0] = v7322;
      int v7341 = v7292->timer;
      int v7390 = v7341 + 100;
      v7292->timer = v7390;
      v7344 = v7322;
    }
    v7346 = v7344;
  }
  int * v7347 = v7292->regs;
  v7347[30] = v7346;
  struct StateT * v7349 = slot_234(v7292);
  return v7349;
}

struct StateT * slot_176(struct StateT * v12642) {
  int v12643 = v12642->timer;
  int v12651 = v12643 + 1;
  v12642->timer = v12651;
  int * v12645 = v12642->regs;
  int v12646 = v12645[11];
  int * v12647 = v12642->regs;
  int v12655 = v12646 << 13;
  v12647[11] = v12655;
  struct StateT * v12649 = slot_177(v12642);
  return v12649;
}

struct StateT * slot_189(struct StateT * v12877) {
  int v12878 = v12877->timer;
  int v12888 = v12878 + 1;
  v12877->timer = v12888;
  int * v12880 = v12877->regs;
  int v12881 = v12880[13];
  int * v12882 = v12877->regs;
  int v12883 = v12882[6];
  int * v12884 = v12877->regs;
  int v12894 = v12881 ^ v12883;
  v12884[13] = v12894;
  struct StateT * v12886 = slot_190(v12877);
  return v12886;
}

struct StateT * slot_33(struct StateT * v2654) {
  int v2655 = v2654->timer;
  int v2661 = v2655 + 1;
  v2654->timer = v2661;
  int * v2657 = v2654->regs;
  v2657[22] = 1797283840;
  struct StateT * v2659 = slot_34(v2654);
  return v2659;
}

struct StateT * slot_35(struct StateT * v2683) {
  int v2684 = v2683->timer;
  int v2690 = v2684 + 1;
  v2683->timer = v2690;
  int * v2686 = v2683->regs;
  v2686[31] = 9;
  struct StateT * v2688 = slot_36(v2683);
  return v2688;
}

struct StateT * slot_258(struct StateT * v9352) {
  int v9353 = v9352->timer;
  int v9407 = v9353 + 1;
  v9352->timer = v9407;
  int * v9355 = v9352->regs;
  int v9356 = v9355[10];
  int * v9357 = v9352->regs;
  int v9358 = v9357[16];
  int * v9359 = v9352->cache_keys;
  int v9360 = v9359[0];
  bool v9414 = v9360 == ((int)((unsigned int)(v9356 + 48) >> 2));
  int v9404;
  if (v9414) {
    int * v9361 = v9352->cache_vals;
    v9361[0] = v9358;
    v9404 = v9358;
  } else {
    int * v9364 = v9352->cache_keys;
    int v9365 = v9364[1];
    bool v9419 = v9365 == ((int)((unsigned int)(v9356 + 48) >> 2));
    int v9402;
    if (v9419) {
      int * v9366 = v9352->cache_keys;
      int * v9367 = v9352->cache_keys;
      int v9368 = v9367[0];
      v9366[1] = v9368;
      int * v9370 = v9352->cache_vals;
      int * v9371 = v9352->cache_vals;
      int v9372 = v9371[0];
      v9370[1] = v9372;
      int * v9374 = v9352->cache_keys;
      int v9427 = (int)((unsigned int)(v9356 + 48) >> 2);
      v9374[0] = v9427;
      int * v9376 = v9352->cache_vals;
      v9376[0] = v9358;
      int v9378 = v9352->timer;
      int v9430 = v9378 + 1;
      v9352->timer = v9430;
      v9402 = v9358;
    } else {
      int * v9381 = v9352->mem;
      int * v9382 = v9352->cache_keys;
      int v9383 = v9382[1];
      int * v9384 = v9352->cache_vals;
      int v9385 = v9384[1];
      v9381[v9383] = v9385;
      int * v9387 = v9352->cache_keys;
      int * v9388 = v9352->cache_keys;
      int v9389 = v9388[0];
      v9387[1] = v9389;
      int * v9391 = v9352->cache_vals;
      int * v9392 = v9352->cache_vals;
      int v9393 = v9392[0];
      v9391[1] = v9393;
      int * v9395 = v9352->cache_keys;
      int v9443 = (int)((unsigned int)(v9356 + 48) >> 2);
      v9395[0] = v9443;
      int * v9397 = v9352->cache_vals;
      v9397[0] = v9358;
      int v9399 = v9352->timer;
      int v9446 = v9399 + 100;
      v9352->timer = v9446;
      v9402 = v9358;
    }
    v9404 = v9402;
  }
  struct StateT * v9405 = slot_259(v9352);
  return v9405;
}

struct StateT * slot_246(struct StateT * v7942) {
  int v7943 = v7942->timer;
  int v7997 = v7943 + 1;
  v7942->timer = v7997;
  int * v7945 = v7942->regs;
  int v7946 = v7945[10];
  int * v7947 = v7942->regs;
  int v7948 = v7947[15];
  int * v7949 = v7942->cache_keys;
  int v7950 = v7949[0];
  bool v8004 = v7950 == ((int)((unsigned int)v7946 >> 2));
  int v7994;
  if (v8004) {
    int * v7951 = v7942->cache_vals;
    v7951[0] = v7948;
    v7994 = v7948;
  } else {
    int * v7954 = v7942->cache_keys;
    int v7955 = v7954[1];
    bool v8009 = v7955 == ((int)((unsigned int)v7946 >> 2));
    int v7992;
    if (v8009) {
      int * v7956 = v7942->cache_keys;
      int * v7957 = v7942->cache_keys;
      int v7958 = v7957[0];
      v7956[1] = v7958;
      int * v7960 = v7942->cache_vals;
      int * v7961 = v7942->cache_vals;
      int v7962 = v7961[0];
      v7960[1] = v7962;
      int * v7964 = v7942->cache_keys;
      int v8017 = (int)((unsigned int)v7946 >> 2);
      v7964[0] = v8017;
      int * v7966 = v7942->cache_vals;
      v7966[0] = v7948;
      int v7968 = v7942->timer;
      int v8020 = v7968 + 1;
      v7942->timer = v8020;
      v7992 = v7948;
    } else {
      int * v7971 = v7942->mem;
      int * v7972 = v7942->cache_keys;
      int v7973 = v7972[1];
      int * v7974 = v7942->cache_vals;
      int v7975 = v7974[1];
      v7971[v7973] = v7975;
      int * v7977 = v7942->cache_keys;
      int * v7978 = v7942->cache_keys;
      int v7979 = v7978[0];
      v7977[1] = v7979;
      int * v7981 = v7942->cache_vals;
      int * v7982 = v7942->cache_vals;
      int v7983 = v7982[0];
      v7981[1] = v7983;
      int * v7985 = v7942->cache_keys;
      int v8033 = (int)((unsigned int)v7946 >> 2);
      v7985[0] = v8033;
      int * v7987 = v7942->cache_vals;
      v7987[0] = v7948;
      int v7989 = v7942->timer;
      int v8036 = v7989 + 100;
      v7942->timer = v8036;
      v7992 = v7948;
    }
    v7994 = v7992;
  }
  struct StateT * v7995 = slot_247(v7942);
  return v7995;
}

struct StateT * slot_210(struct StateT * v13274) {
  int v13275 = v13274->timer;
  int v13285 = v13275 + 1;
  v13274->timer = v13285;
  int * v13277 = v13274->regs;
  int v13278 = v13277[22];
  int * v13279 = v13274->regs;
  int v13280 = v13279[8];
  int * v13281 = v13274->regs;
  int v13291 = v13278 ^ v13280;
  v13281[22] = v13291;
  struct StateT * v13283 = slot_211(v13274);
  return v13283;
}

struct StateT * slot_166(struct StateT * v12441) {
  int v12442 = v12441->timer;
  int v12452 = v12442 + 1;
  v12441->timer = v12452;
  int * v12444 = v12441->regs;
  int v12445 = v12444[8];
  int * v12446 = v12441->regs;
  int v12447 = v12446[9];
  int * v12448 = v12441->regs;
  int v12458 = v12445 | v12447;
  v12448[8] = v12458;
  struct StateT * v12450 = slot_167(v12441);
  return v12450;
}

struct StateT * slot_51(struct StateT * v5962) {
  int v5963 = v5962->timer;
  int v5973 = v5963 + 1;
  v5962->timer = v5973;
  int * v5965 = v5962->regs;
  int v5966 = v5965[21];
  int * v5967 = v5962->regs;
  int v5968 = v5967[16];
  int * v5969 = v5962->regs;
  int v5980 = v5966 + v5968;
  v5969[15] = v5980;
  struct StateT * v5971 = slot_52(v5962);
  return v5971;
}

struct StateT * slot_52(struct StateT * v6003) {
  int v6004 = v6003->timer;
  int v6014 = v6004 + 1;
  v6003->timer = v6014;
  int * v6006 = v6003->regs;
  int v6007 = v6006[11];
  int * v6008 = v6003->regs;
  int v6009 = v6008[23];
  int * v6010 = v6003->regs;
  int v6021 = v6007 + v6009;
  v6010[20] = v6021;
  struct StateT * v6012 = slot_53(v6003);
  return v6012;
}

struct StateT * slot_83(struct StateT * v7922) {
  int v7923 = v7922->timer;
  int v7933 = v7923 + 1;
  v7922->timer = v7933;
  int * v7925 = v7922->regs;
  int v7926 = v7925[9];
  int * v7927 = v7922->regs;
  int v7928 = v7927[20];
  int * v7929 = v7922->regs;
  int v7939 = v7926 | v7928;
  v7929[9] = v7939;
  struct StateT * v7931 = slot_84(v7922);
  return v7931;
}

struct StateT * slot_25(struct StateT * v2354) {
  int v2355 = v2354->timer;
  int v2413 = v2355 + 1;
  v2354->timer = v2413;
  int * v2357 = v2354->regs;
  int v2358 = v2357[11];
  int * v2359 = v2354->cache_keys;
  int v2360 = v2359[0];
  bool v2418 = v2360 == ((int)((unsigned int)(v2358 + 8) >> 2));
  int v2408;
  if (v2418) {
    int * v2361 = v2354->cache_vals;
    int v2362 = v2361[0];
    v2408 = v2362;
  } else {
    int * v2364 = v2354->cache_keys;
    int v2365 = v2364[1];
    bool v2423 = v2365 == ((int)((unsigned int)(v2358 + 8) >> 2));
    int v2406;
    if (v2423) {
      int * v2366 = v2354->cache_vals;
      int v2367 = v2366[1];
      int * v2368 = v2354->cache_keys;
      int * v2369 = v2354->cache_keys;
      int v2370 = v2369[0];
      v2368[1] = v2370;
      int * v2372 = v2354->cache_vals;
      int * v2373 = v2354->cache_vals;
      int v2374 = v2373[0];
      v2372[1] = v2374;
      int * v2376 = v2354->cache_keys;
      int v2432 = (int)((unsigned int)(v2358 + 8) >> 2);
      v2376[0] = v2432;
      int * v2378 = v2354->cache_vals;
      v2378[0] = v2367;
      int v2380 = v2354->timer;
      int v2435 = v2380 + 1;
      v2354->timer = v2435;
      v2406 = v2367;
    } else {
      int * v2383 = v2354->mem;
      int v2437 = (int)((unsigned int)(v2358 + 8) >> 2);
      int v2384 = v2383[v2437];
      int * v2385 = v2354->mem;
      int * v2386 = v2354->cache_keys;
      int v2387 = v2386[1];
      int * v2388 = v2354->cache_vals;
      int v2389 = v2388[1];
      v2385[v2387] = v2389;
      int * v2391 = v2354->cache_keys;
      int * v2392 = v2354->cache_keys;
      int v2393 = v2392[0];
      v2391[1] = v2393;
      int * v2395 = v2354->cache_vals;
      int * v2396 = v2354->cache_vals;
      int v2397 = v2396[0];
      v2395[1] = v2397;
      int * v2399 = v2354->cache_keys;
      v2399[0] = v2437;
      int * v2401 = v2354->cache_vals;
      v2401[0] = v2384;
      int v2403 = v2354->timer;
      int v2452 = v2403 + 100;
      v2354->timer = v2452;
      v2406 = v2384;
    }
    v2408 = v2406;
  }
  int * v2409 = v2354->regs;
  v2409[26] = v2408;
  struct StateT * v2411 = slot_26(v2354);
  return v2411;
}

struct StateT * slot_209(struct StateT * v13254) {
  int v13255 = v13254->timer;
  int v13265 = v13255 + 1;
  v13254->timer = v13265;
  int * v13257 = v13254->regs;
  int v13258 = v13257[19];
  int * v13259 = v13254->regs;
  int v13260 = v13259[6];
  int * v13261 = v13254->regs;
  int v13271 = v13258 ^ v13260;
  v13261[19] = v13271;
  struct StateT * v13263 = slot_210(v13254);
  return v13263;
}

struct StateT * slot_3(struct StateT * v213) {
  int v214 = v213->timer;
  int v268 = v214 + 1;
  v213->timer = v268;
  int * v216 = v213->regs;
  int v217 = v216[2];
  int * v218 = v213->regs;
  int v219 = v218[9];
  int * v220 = v213->cache_keys;
  int v221 = v220[0];
  bool v275 = v221 == ((int)((unsigned int)(v217 + 84) >> 2));
  int v265;
  if (v275) {
    int * v222 = v213->cache_vals;
    v222[0] = v219;
    v265 = v219;
  } else {
    int * v225 = v213->cache_keys;
    int v226 = v225[1];
    bool v280 = v226 == ((int)((unsigned int)(v217 + 84) >> 2));
    int v263;
    if (v280) {
      int * v227 = v213->cache_keys;
      int * v228 = v213->cache_keys;
      int v229 = v228[0];
      v227[1] = v229;
      int * v231 = v213->cache_vals;
      int * v232 = v213->cache_vals;
      int v233 = v232[0];
      v231[1] = v233;
      int * v235 = v213->cache_keys;
      int v288 = (int)((unsigned int)(v217 + 84) >> 2);
      v235[0] = v288;
      int * v237 = v213->cache_vals;
      v237[0] = v219;
      int v239 = v213->timer;
      int v291 = v239 + 1;
      v213->timer = v291;
      v263 = v219;
    } else {
      int * v242 = v213->mem;
      int * v243 = v213->cache_keys;
      int v244 = v243[1];
      int * v245 = v213->cache_vals;
      int v246 = v245[1];
      v242[v244] = v246;
      int * v248 = v213->cache_keys;
      int * v249 = v213->cache_keys;
      int v250 = v249[0];
      v248[1] = v250;
      int * v252 = v213->cache_vals;
      int * v253 = v213->cache_vals;
      int v254 = v253[0];
      v252[1] = v254;
      int * v256 = v213->cache_keys;
      int v304 = (int)((unsigned int)(v217 + 84) >> 2);
      v256[0] = v304;
      int * v258 = v213->cache_vals;
      v258[0] = v219;
      int v260 = v213->timer;
      int v307 = v260 + 100;
      v213->timer = v307;
      v263 = v219;
    }
    v265 = v263;
  }
  struct StateT * v266 = slot_4(v213);
  return v266;
}

struct StateT * slot_264(struct StateT * v10059) {
  int v10060 = v10059->timer;
  int v10118 = v10060 + 1;
  v10059->timer = v10118;
  int * v10062 = v10059->regs;
  int v10063 = v10062[2];
  int * v10064 = v10059->cache_keys;
  int v10065 = v10064[0];
  bool v10123 = v10065 == ((int)((unsigned int)(v10063 + 84) >> 2));
  int v10113;
  if (v10123) {
    int * v10066 = v10059->cache_vals;
    int v10067 = v10066[0];
    v10113 = v10067;
  } else {
    int * v10069 = v10059->cache_keys;
    int v10070 = v10069[1];
    bool v10128 = v10070 == ((int)((unsigned int)(v10063 + 84) >> 2));
    int v10111;
    if (v10128) {
      int * v10071 = v10059->cache_vals;
      int v10072 = v10071[1];
      int * v10073 = v10059->cache_keys;
      int * v10074 = v10059->cache_keys;
      int v10075 = v10074[0];
      v10073[1] = v10075;
      int * v10077 = v10059->cache_vals;
      int * v10078 = v10059->cache_vals;
      int v10079 = v10078[0];
      v10077[1] = v10079;
      int * v10081 = v10059->cache_keys;
      int v10137 = (int)((unsigned int)(v10063 + 84) >> 2);
      v10081[0] = v10137;
      int * v10083 = v10059->cache_vals;
      v10083[0] = v10072;
      int v10085 = v10059->timer;
      int v10140 = v10085 + 1;
      v10059->timer = v10140;
      v10111 = v10072;
    } else {
      int * v10088 = v10059->mem;
      int v10142 = (int)((unsigned int)(v10063 + 84) >> 2);
      int v10089 = v10088[v10142];
      int * v10090 = v10059->mem;
      int * v10091 = v10059->cache_keys;
      int v10092 = v10091[1];
      int * v10093 = v10059->cache_vals;
      int v10094 = v10093[1];
      v10090[v10092] = v10094;
      int * v10096 = v10059->cache_keys;
      int * v10097 = v10059->cache_keys;
      int v10098 = v10097[0];
      v10096[1] = v10098;
      int * v10100 = v10059->cache_vals;
      int * v10101 = v10059->cache_vals;
      int v10102 = v10101[0];
      v10100[1] = v10102;
      int * v10104 = v10059->cache_keys;
      v10104[0] = v10142;
      int * v10106 = v10059->cache_vals;
      v10106[0] = v10089;
      int v10108 = v10059->timer;
      int v10157 = v10108 + 100;
      v10059->timer = v10157;
      v10111 = v10089;
    }
    v10113 = v10111;
  }
  int * v10114 = v10059->regs;
  v10114[9] = v10113;
  struct StateT * v10116 = slot_265(v10059);
  return v10116;
}

struct StateT * slot_123(struct StateT * v11631) {
  int v11632 = v11631->timer;
  int v11642 = v11632 + 1;
  v11631->timer = v11642;
  int * v11634 = v11631->regs;
  int v11635 = v11634[17];
  int * v11636 = v11631->regs;
  int v11637 = v11636[6];
  int * v11638 = v11631->regs;
  int v11648 = v11635 | v11637;
  v11638[17] = v11648;
  struct StateT * v11640 = slot_124(v11631);
  return v11640;
}

struct StateT * slot_73(struct StateT * v7564) {
  int v7565 = v7564->timer;
  int v7575 = v7565 + 1;
  v7564->timer = v7575;
  int * v7567 = v7564->regs;
  int v7568 = v7567[1];
  int * v7569 = v7564->regs;
  int v7570 = v7569[19];
  int * v7571 = v7564->regs;
  int v7582 = v7568 + v7570;
  v7571[9] = v7582;
  struct StateT * v7573 = slot_74(v7564);
  return v7573;
}

struct StateT * slot_270(struct StateT * v10800) {
  int v10801 = v10800->timer;
  int v10859 = v10801 + 1;
  v10800->timer = v10859;
  int * v10803 = v10800->regs;
  int v10804 = v10803[2];
  int * v10805 = v10800->cache_keys;
  int v10806 = v10805[0];
  bool v10864 = v10806 == ((int)((unsigned int)(v10804 + 60) >> 2));
  int v10854;
  if (v10864) {
    int * v10807 = v10800->cache_vals;
    int v10808 = v10807[0];
    v10854 = v10808;
  } else {
    int * v10810 = v10800->cache_keys;
    int v10811 = v10810[1];
    bool v10869 = v10811 == ((int)((unsigned int)(v10804 + 60) >> 2));
    int v10852;
    if (v10869) {
      int * v10812 = v10800->cache_vals;
      int v10813 = v10812[1];
      int * v10814 = v10800->cache_keys;
      int * v10815 = v10800->cache_keys;
      int v10816 = v10815[0];
      v10814[1] = v10816;
      int * v10818 = v10800->cache_vals;
      int * v10819 = v10800->cache_vals;
      int v10820 = v10819[0];
      v10818[1] = v10820;
      int * v10822 = v10800->cache_keys;
      int v10878 = (int)((unsigned int)(v10804 + 60) >> 2);
      v10822[0] = v10878;
      int * v10824 = v10800->cache_vals;
      v10824[0] = v10813;
      int v10826 = v10800->timer;
      int v10881 = v10826 + 1;
      v10800->timer = v10881;
      v10852 = v10813;
    } else {
      int * v10829 = v10800->mem;
      int v10883 = (int)((unsigned int)(v10804 + 60) >> 2);
      int v10830 = v10829[v10883];
      int * v10831 = v10800->mem;
      int * v10832 = v10800->cache_keys;
      int v10833 = v10832[1];
      int * v10834 = v10800->cache_vals;
      int v10835 = v10834[1];
      v10831[v10833] = v10835;
      int * v10837 = v10800->cache_keys;
      int * v10838 = v10800->cache_keys;
      int v10839 = v10838[0];
      v10837[1] = v10839;
      int * v10841 = v10800->cache_vals;
      int * v10842 = v10800->cache_vals;
      int v10843 = v10842[0];
      v10841[1] = v10843;
      int * v10845 = v10800->cache_keys;
      v10845[0] = v10883;
      int * v10847 = v10800->cache_vals;
      v10847[0] = v10830;
      int v10849 = v10800->timer;
      int v10898 = v10849 + 100;
      v10800->timer = v10898;
      v10852 = v10830;
    }
    v10854 = v10852;
  }
  int * v10855 = v10800->regs;
  v10855[23] = v10854;
  struct StateT * v10857 = slot_271(v10800);
  return v10857;
}

struct StateT * slot_198(struct StateT * v13054) {
  int v13055 = v13054->timer;
  int v13063 = v13055 + 1;
  v13054->timer = v13063;
  int * v13057 = v13054->regs;
  int v13058 = v13057[15];
  int * v13059 = v13054->regs;
  int v13068 = (int)((unsigned int)v13058 >> 14);
  v13059[9] = v13068;
  struct StateT * v13061 = slot_199(v13054);
  return v13061;
}

struct StateT * slot_1(struct StateT * v18) {
  int v19 = v18->timer;
  int v73 = v19 + 1;
  v18->timer = v73;
  int * v21 = v18->regs;
  int v22 = v21[2];
  int * v23 = v18->regs;
  int v24 = v23[1];
  int * v25 = v18->cache_keys;
  int v26 = v25[0];
  bool v80 = v26 == ((int)((unsigned int)(v22 + 92) >> 2));
  int v70;
  if (v80) {
    int * v27 = v18->cache_vals;
    v27[0] = v24;
    v70 = v24;
  } else {
    int * v30 = v18->cache_keys;
    int v31 = v30[1];
    bool v84 = v31 == ((int)((unsigned int)(v22 + 92) >> 2));
    int v68;
    if (v84) {
      int * v32 = v18->cache_keys;
      int * v33 = v18->cache_keys;
      int v34 = v33[0];
      v32[1] = v34;
      int * v36 = v18->cache_vals;
      int * v37 = v18->cache_vals;
      int v38 = v37[0];
      v36[1] = v38;
      int * v40 = v18->cache_keys;
      int v92 = (int)((unsigned int)(v22 + 92) >> 2);
      v40[0] = v92;
      int * v42 = v18->cache_vals;
      v42[0] = v24;
      int v44 = v18->timer;
      int v95 = v44 + 1;
      v18->timer = v95;
      v68 = v24;
    } else {
      int * v47 = v18->mem;
      int * v48 = v18->cache_keys;
      int v49 = v48[1];
      int * v50 = v18->cache_vals;
      int v51 = v50[1];
      v47[v49] = v51;
      int * v53 = v18->cache_keys;
      int * v54 = v18->cache_keys;
      int v55 = v54[0];
      v53[1] = v55;
      int * v57 = v18->cache_vals;
      int * v58 = v18->cache_vals;
      int v59 = v58[0];
      v57[1] = v59;
      int * v61 = v18->cache_keys;
      int v108 = (int)((unsigned int)(v22 + 92) >> 2);
      v61[0] = v108;
      int * v63 = v18->cache_vals;
      v63[0] = v24;
      int v65 = v18->timer;
      int v111 = v65 + 100;
      v18->timer = v111;
      v68 = v24;
    }
    v70 = v68;
  }
  struct StateT * v71 = slot_2(v18);
  return v71;
}

struct StateT * slot_187(struct StateT * v12837) {
  int v12838 = v12837->timer;
  int v12848 = v12838 + 1;
  v12837->timer = v12848;
  int * v12840 = v12837->regs;
  int v12841 = v12840[14];
  int * v12842 = v12837->regs;
  int v12843 = v12842[11];
  int * v12844 = v12837->regs;
  int v12854 = v12841 ^ v12843;
  v12844[14] = v12854;
  struct StateT * v12846 = slot_188(v12837);
  return v12846;
}

struct StateT * slot_97(struct StateT * v9564) {
  int v9565 = v9564->timer;
  int v9575 = v9565 + 1;
  v9564->timer = v9575;
  int * v9567 = v9564->regs;
  int v9568 = v9567[15];
  int * v9569 = v9564->regs;
  int v9570 = v9569[20];
  int * v9571 = v9564->regs;
  int v9581 = v9568 | v9570;
  v9571[15] = v9581;
  struct StateT * v9573 = slot_98(v9564);
  return v9573;
}

struct StateT * slot_182(struct StateT * v12748) {
  int v12749 = v12748->timer;
  int v12757 = v12749 + 1;
  v12748->timer = v12757;
  int * v12751 = v12748->regs;
  int v12752 = v12751[6];
  int * v12753 = v12748->regs;
  int v12761 = v12752 << 13;
  v12753[6] = v12761;
  struct StateT * v12755 = slot_183(v12748);
  return v12755;
}

struct StateT * slot_38(struct StateT * v2892) {
  int v2893 = v2892->timer;
  int v2947 = v2893 + 1;
  v2892->timer = v2947;
  int * v2895 = v2892->regs;
  int v2896 = v2895[2];
  int * v2897 = v2892->regs;
  int v2898 = v2897[5];
  int * v2899 = v2892->cache_keys;
  int v2900 = v2899[0];
  bool v2954 = v2900 == ((int)((unsigned int)(v2896 + 12) >> 2));
  int v2944;
  if (v2954) {
    int * v2901 = v2892->cache_vals;
    v2901[0] = v2898;
    v2944 = v2898;
  } else {
    int * v2904 = v2892->cache_keys;
    int v2905 = v2904[1];
    bool v2959 = v2905 == ((int)((unsigned int)(v2896 + 12) >> 2));
    int v2942;
    if (v2959) {
      int * v2906 = v2892->cache_keys;
      int * v2907 = v2892->cache_keys;
      int v2908 = v2907[0];
      v2906[1] = v2908;
      int * v2910 = v2892->cache_vals;
      int * v2911 = v2892->cache_vals;
      int v2912 = v2911[0];
      v2910[1] = v2912;
      int * v2914 = v2892->cache_keys;
      int v2967 = (int)((unsigned int)(v2896 + 12) >> 2);
      v2914[0] = v2967;
      int * v2916 = v2892->cache_vals;
      v2916[0] = v2898;
      int v2918 = v2892->timer;
      int v2970 = v2918 + 1;
      v2892->timer = v2970;
      v2942 = v2898;
    } else {
      int * v2921 = v2892->mem;
      int * v2922 = v2892->cache_keys;
      int v2923 = v2922[1];
      int * v2924 = v2892->cache_vals;
      int v2925 = v2924[1];
      v2921[v2923] = v2925;
      int * v2927 = v2892->cache_keys;
      int * v2928 = v2892->cache_keys;
      int v2929 = v2928[0];
      v2927[1] = v2929;
      int * v2931 = v2892->cache_vals;
      int * v2932 = v2892->cache_vals;
      int v2933 = v2932[0];
      v2931[1] = v2933;
      int * v2935 = v2892->cache_keys;
      int v2983 = (int)((unsigned int)(v2896 + 12) >> 2);
      v2935[0] = v2983;
      int * v2937 = v2892->cache_vals;
      v2937[0] = v2898;
      int v2939 = v2892->timer;
      int v2986 = v2939 + 100;
      v2892->timer = v2986;
      v2942 = v2898;
    }
    v2944 = v2942;
  }
  struct StateT * v2945 = slot_39(v2892);
  return v2945;
}

struct StateT * slot_178(struct StateT * v12678) {
  int v12679 = v12678->timer;
  int v12687 = v12679 + 1;
  v12678->timer = v12687;
  int * v12681 = v12678->regs;
  int v12682 = v12681[15];
  int * v12683 = v12678->regs;
  int v12692 = (int)((unsigned int)v12682 >> 19);
  v12683[9] = v12692;
  struct StateT * v12685 = slot_179(v12678);
  return v12685;
}

struct StateT * slot_106(struct StateT * v10653) {
  int v10654 = v10653->timer;
  int v10664 = v10654 + 1;
  v10653->timer = v10664;
  int * v10656 = v10653->regs;
  int v10657 = v10656[18];
  int * v10658 = v10653->regs;
  int v10659 = v10658[9];
  int * v10660 = v10653->regs;
  int v10671 = v10657 | v10659;
  v10660[6] = v10671;
  struct StateT * v10662 = slot_107(v10653);
  return v10662;
}

struct StateT * slot_98(struct StateT * v9681) {
  int v9682 = v9681->timer;
  int v9690 = v9682 + 1;
  v9681->timer = v9690;
  int * v9684 = v9681->regs;
  int v9685 = v9684[8];
  int * v9686 = v9681->regs;
  int v9695 = (int)((unsigned int)v9685 >> 19);
  v9686[20] = v9695;
  struct StateT * v9688 = slot_99(v9681);
  return v9688;
}

struct StateT * slot_159(struct StateT * v12319) {
  int v12320 = v12319->timer;
  int v12328 = v12320 + 1;
  v12319->timer = v12328;
  int * v12322 = v12319->regs;
  int v12323 = v12322[15];
  int * v12324 = v12319->regs;
  int v12332 = v12323 << 9;
  v12324[15] = v12332;
  struct StateT * v12326 = slot_160(v12319);
  return v12326;
}

struct StateT * slot_46(struct StateT * v3513) {
  int v3514 = v3513->timer;
  int v3522 = v3514 + 1;
  v3513->timer = v3522;
  int * v3516 = v3513->regs;
  int v3517 = v3516[28];
  int * v3518 = v3513->regs;
  v3518[27] = v3517;
  struct StateT * v3520 = slot_47(v3513);
  return v3520;
}

struct StateT * slot_212(struct StateT * v13310) {
  int v13311 = v13310->timer;
  int v13323 = v13311 + 1;
  v13310->timer = v13323;
  int * v13313 = v13310->regs;
  int v13314 = v13313[31];
  int * v13315 = v13310->regs;
  int v13316 = v13315[30];
  bool v13328 = (v13314 ^ -2147483648) >= (v13316 ^ -2147483648);
  struct StateT * v13321;
  if (v13328) {
    struct StateT * v13317 = slot_51(v13310);
    v13321 = v13317;
  } else {
    struct StateT * v13319 = slot_213(v13310);
    v13321 = v13319;
  }
  return v13321;
}

struct StateT * slot_132(struct StateT * v11806) {
  int v11807 = v11806->timer;
  int v11817 = v11807 + 1;
  v11806->timer = v11817;
  int * v11809 = v11806->regs;
  int v11810 = v11809[20];
  int * v11811 = v11806->regs;
  int v11812 = v11811[12];
  int * v11813 = v11806->regs;
  int v11824 = v11810 + v11812;
  v11813[11] = v11824;
  struct StateT * v11815 = slot_133(v11806);
  return v11815;
}

struct StateT * slot_130(struct StateT * v11765) {
  int v11766 = v11765->timer;
  int v11776 = v11766 + 1;
  v11765->timer = v11776;
  int * v11768 = v11765->regs;
  int v11769 = v11768[22];
  int * v11770 = v11765->regs;
  int v11771 = v11770[5];
  int * v11772 = v11765->regs;
  int v11782 = v11769 ^ v11771;
  v11772[22] = v11782;
  struct StateT * v11774 = slot_131(v11765);
  return v11774;
}

struct StateT * slot_211(struct StateT * v13294) {
  int v13295 = v13294->timer;
  int v13303 = v13295 + 1;
  v13294->timer = v13303;
  int * v13297 = v13294->regs;
  int v13298 = v13297[30];
  int * v13299 = v13294->regs;
  int v13307 = v13298 + 1;
  v13299[30] = v13307;
  struct StateT * v13301 = slot_212(v13294);
  return v13301;
}

struct StateT * slot_20(struct StateT * v1829) {
  int v1830 = v1829->timer;
  int v1888 = v1830 + 1;
  v1829->timer = v1888;
  int * v1832 = v1829->regs;
  int v1833 = v1832[12];
  int * v1834 = v1829->cache_keys;
  int v1835 = v1834[0];
  bool v1893 = v1835 == ((int)((unsigned int)(v1833 + 20) >> 2));
  int v1883;
  if (v1893) {
    int * v1836 = v1829->cache_vals;
    int v1837 = v1836[0];
    v1883 = v1837;
  } else {
    int * v1839 = v1829->cache_keys;
    int v1840 = v1839[1];
    bool v1898 = v1840 == ((int)((unsigned int)(v1833 + 20) >> 2));
    int v1881;
    if (v1898) {
      int * v1841 = v1829->cache_vals;
      int v1842 = v1841[1];
      int * v1843 = v1829->cache_keys;
      int * v1844 = v1829->cache_keys;
      int v1845 = v1844[0];
      v1843[1] = v1845;
      int * v1847 = v1829->cache_vals;
      int * v1848 = v1829->cache_vals;
      int v1849 = v1848[0];
      v1847[1] = v1849;
      int * v1851 = v1829->cache_keys;
      int v1907 = (int)((unsigned int)(v1833 + 20) >> 2);
      v1851[0] = v1907;
      int * v1853 = v1829->cache_vals;
      v1853[0] = v1842;
      int v1855 = v1829->timer;
      int v1910 = v1855 + 1;
      v1829->timer = v1910;
      v1881 = v1842;
    } else {
      int * v1858 = v1829->mem;
      int v1912 = (int)((unsigned int)(v1833 + 20) >> 2);
      int v1859 = v1858[v1912];
      int * v1860 = v1829->mem;
      int * v1861 = v1829->cache_keys;
      int v1862 = v1861[1];
      int * v1863 = v1829->cache_vals;
      int v1864 = v1863[1];
      v1860[v1862] = v1864;
      int * v1866 = v1829->cache_keys;
      int * v1867 = v1829->cache_keys;
      int v1868 = v1867[0];
      v1866[1] = v1868;
      int * v1870 = v1829->cache_vals;
      int * v1871 = v1829->cache_vals;
      int v1872 = v1871[0];
      v1870[1] = v1872;
      int * v1874 = v1829->cache_keys;
      v1874[0] = v1912;
      int * v1876 = v1829->cache_vals;
      v1876[0] = v1859;
      int v1878 = v1829->timer;
      int v1927 = v1878 + 100;
      v1829->timer = v1927;
      v1881 = v1859;
    }
    v1883 = v1881;
  }
  int * v1884 = v1829->regs;
  v1884[16] = v1883;
  struct StateT * v1886 = slot_21(v1829);
  return v1886;
}

struct StateT * slot_141(struct StateT * v11975) {
  int v11976 = v11975->timer;
  int v11984 = v11976 + 1;
  v11975->timer = v11984;
  int * v11978 = v11975->regs;
  int v11979 = v11978[16];
  int * v11980 = v11975->regs;
  int v11989 = (int)((unsigned int)v11979 >> 25);
  v11980[5] = v11989;
  struct StateT * v11982 = slot_142(v11975);
  return v11982;
}

struct StateT * slot_61(struct StateT * v6593) {
  int v6594 = v6593->timer;
  int v6602 = v6594 + 1;
  v6593->timer = v6602;
  int * v6596 = v6593->regs;
  int v6597 = v6596[18];
  int * v6598 = v6593->regs;
  int v6607 = (int)((unsigned int)v6597 >> 25);
  v6598[20] = v6607;
  struct StateT * v6600 = slot_62(v6593);
  return v6600;
}

struct StateT * slot_30(struct StateT * v2603) {
  int v2604 = v2603->timer;
  int v2612 = v2604 + 1;
  v2603->timer = v2612;
  int * v2606 = v2603->regs;
  int v2607 = v2606[12];
  int * v2608 = v2603->regs;
  int v2617 = v2607 + -1947;
  v2608[21] = v2617;
  struct StateT * v2610 = slot_31(v2603);
  return v2610;
}

struct StateT * slot_4(struct StateT * v311) {
  int v312 = v311->timer;
  int v366 = v312 + 1;
  v311->timer = v366;
  int * v314 = v311->regs;
  int v315 = v314[2];
  int * v316 = v311->regs;
  int v317 = v316[18];
  int * v318 = v311->cache_keys;
  int v319 = v318[0];
  bool v373 = v319 == ((int)((unsigned int)(v315 + 80) >> 2));
  int v363;
  if (v373) {
    int * v320 = v311->cache_vals;
    v320[0] = v317;
    v363 = v317;
  } else {
    int * v323 = v311->cache_keys;
    int v324 = v323[1];
    bool v378 = v324 == ((int)((unsigned int)(v315 + 80) >> 2));
    int v361;
    if (v378) {
      int * v325 = v311->cache_keys;
      int * v326 = v311->cache_keys;
      int v327 = v326[0];
      v325[1] = v327;
      int * v329 = v311->cache_vals;
      int * v330 = v311->cache_vals;
      int v331 = v330[0];
      v329[1] = v331;
      int * v333 = v311->cache_keys;
      int v386 = (int)((unsigned int)(v315 + 80) >> 2);
      v333[0] = v386;
      int * v335 = v311->cache_vals;
      v335[0] = v317;
      int v337 = v311->timer;
      int v389 = v337 + 1;
      v311->timer = v389;
      v361 = v317;
    } else {
      int * v340 = v311->mem;
      int * v341 = v311->cache_keys;
      int v342 = v341[1];
      int * v343 = v311->cache_vals;
      int v344 = v343[1];
      v340[v342] = v344;
      int * v346 = v311->cache_keys;
      int * v347 = v311->cache_keys;
      int v348 = v347[0];
      v346[1] = v348;
      int * v350 = v311->cache_vals;
      int * v351 = v311->cache_vals;
      int v352 = v351[0];
      v350[1] = v352;
      int * v354 = v311->cache_keys;
      int v402 = (int)((unsigned int)(v315 + 80) >> 2);
      v354[0] = v402;
      int * v356 = v311->cache_vals;
      v356[0] = v317;
      int v358 = v311->timer;
      int v405 = v358 + 100;
      v311->timer = v405;
      v361 = v317;
    }
    v363 = v361;
  }
  struct StateT * v364 = slot_5(v311);
  return v364;
}

struct StateT * slot_18(struct StateT * v1619) {
  int v1620 = v1619->timer;
  int v1678 = v1620 + 1;
  v1619->timer = v1678;
  int * v1622 = v1619->regs;
  int v1623 = v1622[12];
  int * v1624 = v1619->cache_keys;
  int v1625 = v1624[0];
  bool v1683 = v1625 == ((int)((unsigned int)(v1623 + 12) >> 2));
  int v1673;
  if (v1683) {
    int * v1626 = v1619->cache_vals;
    int v1627 = v1626[0];
    v1673 = v1627;
  } else {
    int * v1629 = v1619->cache_keys;
    int v1630 = v1629[1];
    bool v1688 = v1630 == ((int)((unsigned int)(v1623 + 12) >> 2));
    int v1671;
    if (v1688) {
      int * v1631 = v1619->cache_vals;
      int v1632 = v1631[1];
      int * v1633 = v1619->cache_keys;
      int * v1634 = v1619->cache_keys;
      int v1635 = v1634[0];
      v1633[1] = v1635;
      int * v1637 = v1619->cache_vals;
      int * v1638 = v1619->cache_vals;
      int v1639 = v1638[0];
      v1637[1] = v1639;
      int * v1641 = v1619->cache_keys;
      int v1697 = (int)((unsigned int)(v1623 + 12) >> 2);
      v1641[0] = v1697;
      int * v1643 = v1619->cache_vals;
      v1643[0] = v1632;
      int v1645 = v1619->timer;
      int v1700 = v1645 + 1;
      v1619->timer = v1700;
      v1671 = v1632;
    } else {
      int * v1648 = v1619->mem;
      int v1702 = (int)((unsigned int)(v1623 + 12) >> 2);
      int v1649 = v1648[v1702];
      int * v1650 = v1619->mem;
      int * v1651 = v1619->cache_keys;
      int v1652 = v1651[1];
      int * v1653 = v1619->cache_vals;
      int v1654 = v1653[1];
      v1650[v1652] = v1654;
      int * v1656 = v1619->cache_keys;
      int * v1657 = v1619->cache_keys;
      int v1658 = v1657[0];
      v1656[1] = v1658;
      int * v1660 = v1619->cache_vals;
      int * v1661 = v1619->cache_vals;
      int v1662 = v1661[0];
      v1660[1] = v1662;
      int * v1664 = v1619->cache_keys;
      v1664[0] = v1702;
      int * v1666 = v1619->cache_vals;
      v1666[0] = v1649;
      int v1668 = v1619->timer;
      int v1717 = v1668 + 100;
      v1619->timer = v1717;
      v1671 = v1649;
    }
    v1673 = v1671;
  }
  int * v1674 = v1619->regs;
  v1674[6] = v1673;
  struct StateT * v1676 = slot_19(v1619);
  return v1676;
}

struct StateT * slot_9(struct StateT * v801) {
  int v802 = v801->timer;
  int v856 = v802 + 1;
  v801->timer = v856;
  int * v804 = v801->regs;
  int v805 = v804[2];
  int * v806 = v801->regs;
  int v807 = v806[23];
  int * v808 = v801->cache_keys;
  int v809 = v808[0];
  bool v863 = v809 == ((int)((unsigned int)(v805 + 60) >> 2));
  int v853;
  if (v863) {
    int * v810 = v801->cache_vals;
    v810[0] = v807;
    v853 = v807;
  } else {
    int * v813 = v801->cache_keys;
    int v814 = v813[1];
    bool v868 = v814 == ((int)((unsigned int)(v805 + 60) >> 2));
    int v851;
    if (v868) {
      int * v815 = v801->cache_keys;
      int * v816 = v801->cache_keys;
      int v817 = v816[0];
      v815[1] = v817;
      int * v819 = v801->cache_vals;
      int * v820 = v801->cache_vals;
      int v821 = v820[0];
      v819[1] = v821;
      int * v823 = v801->cache_keys;
      int v876 = (int)((unsigned int)(v805 + 60) >> 2);
      v823[0] = v876;
      int * v825 = v801->cache_vals;
      v825[0] = v807;
      int v827 = v801->timer;
      int v879 = v827 + 1;
      v801->timer = v879;
      v851 = v807;
    } else {
      int * v830 = v801->mem;
      int * v831 = v801->cache_keys;
      int v832 = v831[1];
      int * v833 = v801->cache_vals;
      int v834 = v833[1];
      v830[v832] = v834;
      int * v836 = v801->cache_keys;
      int * v837 = v801->cache_keys;
      int v838 = v837[0];
      v836[1] = v838;
      int * v840 = v801->cache_vals;
      int * v841 = v801->cache_vals;
      int v842 = v841[0];
      v840[1] = v842;
      int * v844 = v801->cache_keys;
      int v892 = (int)((unsigned int)(v805 + 60) >> 2);
      v844[0] = v892;
      int * v846 = v801->cache_vals;
      v846[0] = v807;
      int v848 = v801->timer;
      int v895 = v848 + 100;
      v801->timer = v895;
      v851 = v807;
    }
    v853 = v851;
  }
  struct StateT * v854 = slot_10(v801);
  return v854;
}

struct StateT * slot_183(struct StateT * v12764) {
  int v12765 = v12764->timer;
  int v12775 = v12765 + 1;
  v12764->timer = v12775;
  int * v12767 = v12764->regs;
  int v12768 = v12767[6];
  int * v12769 = v12764->regs;
  int v12770 = v12769[9];
  int * v12771 = v12764->regs;
  int v12781 = v12768 | v12770;
  v12771[6] = v12781;
  struct StateT * v12773 = slot_184(v12764);
  return v12773;
}

struct StateT * slot_240(struct StateT * v7724) {
  int v7725 = v7724->timer;
  int v7733 = v7725 + 1;
  v7724->timer = v7733;
  int * v7727 = v7724->regs;
  int v7728 = v7727[7];
  int * v7729 = v7724->regs;
  int v7737 = v7728 + -718;
  v7729[7] = v7737;
  struct StateT * v7731 = slot_241(v7724);
  return v7731;
}

struct StateT * slot_247(struct StateT * v8057) {
  int v8058 = v8057->timer;
  int v8112 = v8058 + 1;
  v8057->timer = v8112;
  int * v8060 = v8057->regs;
  int v8061 = v8060[10];
  int * v8062 = v8057->regs;
  int v8063 = v8062[29];
  int * v8064 = v8057->cache_keys;
  int v8065 = v8064[0];
  bool v8119 = v8065 == ((int)((unsigned int)(v8061 + 4) >> 2));
  int v8109;
  if (v8119) {
    int * v8066 = v8057->cache_vals;
    v8066[0] = v8063;
    v8109 = v8063;
  } else {
    int * v8069 = v8057->cache_keys;
    int v8070 = v8069[1];
    bool v8124 = v8070 == ((int)((unsigned int)(v8061 + 4) >> 2));
    int v8107;
    if (v8124) {
      int * v8071 = v8057->cache_keys;
      int * v8072 = v8057->cache_keys;
      int v8073 = v8072[0];
      v8071[1] = v8073;
      int * v8075 = v8057->cache_vals;
      int * v8076 = v8057->cache_vals;
      int v8077 = v8076[0];
      v8075[1] = v8077;
      int * v8079 = v8057->cache_keys;
      int v8132 = (int)((unsigned int)(v8061 + 4) >> 2);
      v8079[0] = v8132;
      int * v8081 = v8057->cache_vals;
      v8081[0] = v8063;
      int v8083 = v8057->timer;
      int v8135 = v8083 + 1;
      v8057->timer = v8135;
      v8107 = v8063;
    } else {
      int * v8086 = v8057->mem;
      int * v8087 = v8057->cache_keys;
      int v8088 = v8087[1];
      int * v8089 = v8057->cache_vals;
      int v8090 = v8089[1];
      v8086[v8088] = v8090;
      int * v8092 = v8057->cache_keys;
      int * v8093 = v8057->cache_keys;
      int v8094 = v8093[0];
      v8092[1] = v8094;
      int * v8096 = v8057->cache_vals;
      int * v8097 = v8057->cache_vals;
      int v8098 = v8097[0];
      v8096[1] = v8098;
      int * v8100 = v8057->cache_keys;
      int v8148 = (int)((unsigned int)(v8061 + 4) >> 2);
      v8100[0] = v8148;
      int * v8102 = v8057->cache_vals;
      v8102[0] = v8063;
      int v8104 = v8057->timer;
      int v8151 = v8104 + 100;
      v8057->timer = v8151;
      v8107 = v8063;
    }
    v8109 = v8107;
  }
  struct StateT * v8110 = slot_248(v8057);
  return v8110;
}

struct StateT * slot_43(struct StateT * v3381) {
  int v3382 = v3381->timer;
  int v3436 = v3382 + 1;
  v3381->timer = v3436;
  int * v3384 = v3381->regs;
  int v3385 = v3384[2];
  int * v3386 = v3381->regs;
  int v3387 = v3386[6];
  int * v3388 = v3381->cache_keys;
  int v3389 = v3388[0];
  bool v3443 = v3389 == ((int)((unsigned int)(v3385 + 8) >> 2));
  int v3433;
  if (v3443) {
    int * v3390 = v3381->cache_vals;
    v3390[0] = v3387;
    v3433 = v3387;
  } else {
    int * v3393 = v3381->cache_keys;
    int v3394 = v3393[1];
    bool v3448 = v3394 == ((int)((unsigned int)(v3385 + 8) >> 2));
    int v3431;
    if (v3448) {
      int * v3395 = v3381->cache_keys;
      int * v3396 = v3381->cache_keys;
      int v3397 = v3396[0];
      v3395[1] = v3397;
      int * v3399 = v3381->cache_vals;
      int * v3400 = v3381->cache_vals;
      int v3401 = v3400[0];
      v3399[1] = v3401;
      int * v3403 = v3381->cache_keys;
      int v3456 = (int)((unsigned int)(v3385 + 8) >> 2);
      v3403[0] = v3456;
      int * v3405 = v3381->cache_vals;
      v3405[0] = v3387;
      int v3407 = v3381->timer;
      int v3459 = v3407 + 1;
      v3381->timer = v3459;
      v3431 = v3387;
    } else {
      int * v3410 = v3381->mem;
      int * v3411 = v3381->cache_keys;
      int v3412 = v3411[1];
      int * v3413 = v3381->cache_vals;
      int v3414 = v3413[1];
      v3410[v3412] = v3414;
      int * v3416 = v3381->cache_keys;
      int * v3417 = v3381->cache_keys;
      int v3418 = v3417[0];
      v3416[1] = v3418;
      int * v3420 = v3381->cache_vals;
      int * v3421 = v3381->cache_vals;
      int v3422 = v3421[0];
      v3420[1] = v3422;
      int * v3424 = v3381->cache_keys;
      int v3472 = (int)((unsigned int)(v3385 + 8) >> 2);
      v3424[0] = v3472;
      int * v3426 = v3381->cache_vals;
      v3426[0] = v3387;
      int v3428 = v3381->timer;
      int v3475 = v3428 + 100;
      v3381->timer = v3475;
      v3431 = v3387;
    }
    v3433 = v3431;
  }
  struct StateT * v3434 = slot_44(v3381);
  return v3434;
}

struct StateT * slot_70(struct StateT * v7272) {
  int v7273 = v7272->timer;
  int v7283 = v7273 + 1;
  v7272->timer = v7283;
  int * v7275 = v7272->regs;
  int v7276 = v7275[14];
  int * v7277 = v7272->regs;
  int v7278 = v7277[8];
  int * v7279 = v7272->regs;
  int v7289 = v7276 ^ v7278;
  v7279[14] = v7289;
  struct StateT * v7281 = slot_71(v7272);
  return v7281;
}

struct StateT * slot_168(struct StateT * v12481) {
  int v12482 = v12481->timer;
  int v12492 = v12482 + 1;
  v12481->timer = v12492;
  int * v12484 = v12481->regs;
  int v12485 = v12484[25];
  int * v12486 = v12481->regs;
  int v12487 = v12486[15];
  int * v12488 = v12481->regs;
  int v12498 = v12485 ^ v12487;
  v12488[25] = v12498;
  struct StateT * v12490 = slot_169(v12481);
  return v12490;
}

struct StateT * slot_76(struct StateT * v7672) {
  int v7673 = v7672->timer;
  int v7681 = v7673 + 1;
  v7672->timer = v7681;
  int * v7675 = v7672->regs;
  int v7676 = v7675[15];
  int * v7677 = v7672->regs;
  int v7685 = v7676 << 9;
  v7677[15] = v7685;
  struct StateT * v7679 = slot_77(v7672);
  return v7679;
}

struct StateT * slot_6(struct StateT * v507) {
  int v508 = v507->timer;
  int v562 = v508 + 1;
  v507->timer = v562;
  int * v510 = v507->regs;
  int v511 = v510[2];
  int * v512 = v507->regs;
  int v513 = v512[20];
  int * v514 = v507->cache_keys;
  int v515 = v514[0];
  bool v569 = v515 == ((int)((unsigned int)(v511 + 72) >> 2));
  int v559;
  if (v569) {
    int * v516 = v507->cache_vals;
    v516[0] = v513;
    v559 = v513;
  } else {
    int * v519 = v507->cache_keys;
    int v520 = v519[1];
    bool v574 = v520 == ((int)((unsigned int)(v511 + 72) >> 2));
    int v557;
    if (v574) {
      int * v521 = v507->cache_keys;
      int * v522 = v507->cache_keys;
      int v523 = v522[0];
      v521[1] = v523;
      int * v525 = v507->cache_vals;
      int * v526 = v507->cache_vals;
      int v527 = v526[0];
      v525[1] = v527;
      int * v529 = v507->cache_keys;
      int v582 = (int)((unsigned int)(v511 + 72) >> 2);
      v529[0] = v582;
      int * v531 = v507->cache_vals;
      v531[0] = v513;
      int v533 = v507->timer;
      int v585 = v533 + 1;
      v507->timer = v585;
      v557 = v513;
    } else {
      int * v536 = v507->mem;
      int * v537 = v507->cache_keys;
      int v538 = v537[1];
      int * v539 = v507->cache_vals;
      int v540 = v539[1];
      v536[v538] = v540;
      int * v542 = v507->cache_keys;
      int * v543 = v507->cache_keys;
      int v544 = v543[0];
      v542[1] = v544;
      int * v546 = v507->cache_vals;
      int * v547 = v507->cache_vals;
      int v548 = v547[0];
      v546[1] = v548;
      int * v550 = v507->cache_keys;
      int v598 = (int)((unsigned int)(v511 + 72) >> 2);
      v550[0] = v598;
      int * v552 = v507->cache_vals;
      v552[0] = v513;
      int v554 = v507->timer;
      int v601 = v554 + 100;
      v507->timer = v601;
      v557 = v513;
    }
    v559 = v557;
  }
  struct StateT * v560 = slot_7(v507);
  return v560;
}

struct StateT * slot_225(struct StateT * v6731) {
  int v6732 = v6731->timer;
  int v6742 = v6732 + 1;
  v6731->timer = v6742;
  int * v6734 = v6731->regs;
  int v6735 = v6734[26];
  int * v6736 = v6731->regs;
  int v6737 = v6736[7];
  int * v6738 = v6731->regs;
  int v6748 = v6735 + v6737;
  v6738[26] = v6748;
  struct StateT * v6740 = slot_226(v6731);
  return v6740;
}

struct StateT * slot_55(struct StateT * v6204) {
  int v6205 = v6204->timer;
  int v6213 = v6205 + 1;
  v6204->timer = v6213;
  int * v6207 = v6204->regs;
  int v6208 = v6207[15];
  int * v6209 = v6204->regs;
  int v6218 = (int)((unsigned int)v6208 >> 25);
  v6209[9] = v6218;
  struct StateT * v6211 = slot_56(v6204);
  return v6211;
}

struct StateT * slot_213(struct StateT * v5942) {
  int v5943 = v5942->timer;
  int v5953 = v5943 + 1;
  v5942->timer = v5953;
  int * v5945 = v5942->regs;
  int v5946 = v5945[23];
  int * v5947 = v5942->regs;
  int v5948 = v5947[29];
  int * v5949 = v5942->regs;
  int v5959 = v5946 + v5948;
  v5949[29] = v5959;
  struct StateT * v5951 = slot_214(v5942);
  return v5951;
}

struct StateT * slot_82(struct StateT * v7886) {
  int v7887 = v7886->timer;
  int v7895 = v7887 + 1;
  v7886->timer = v7895;
  int * v7889 = v7886->regs;
  int v7890 = v7889[9];
  int * v7891 = v7886->regs;
  int v7899 = v7890 << 9;
  v7891[9] = v7899;
  struct StateT * v7893 = slot_83(v7886);
  return v7893;
}

struct StateT * slot_274(struct StateT * v11303) {
  int v11304 = v11303->timer;
  int v11362 = v11304 + 1;
  v11303->timer = v11362;
  int * v11306 = v11303->regs;
  int v11307 = v11306[2];
  int * v11308 = v11303->cache_keys;
  int v11309 = v11308[0];
  bool v11367 = v11309 == ((int)((unsigned int)(v11307 + 44) >> 2));
  int v11357;
  if (v11367) {
    int * v11310 = v11303->cache_vals;
    int v11311 = v11310[0];
    v11357 = v11311;
  } else {
    int * v11313 = v11303->cache_keys;
    int v11314 = v11313[1];
    bool v11372 = v11314 == ((int)((unsigned int)(v11307 + 44) >> 2));
    int v11355;
    if (v11372) {
      int * v11315 = v11303->cache_vals;
      int v11316 = v11315[1];
      int * v11317 = v11303->cache_keys;
      int * v11318 = v11303->cache_keys;
      int v11319 = v11318[0];
      v11317[1] = v11319;
      int * v11321 = v11303->cache_vals;
      int * v11322 = v11303->cache_vals;
      int v11323 = v11322[0];
      v11321[1] = v11323;
      int * v11325 = v11303->cache_keys;
      int v11381 = (int)((unsigned int)(v11307 + 44) >> 2);
      v11325[0] = v11381;
      int * v11327 = v11303->cache_vals;
      v11327[0] = v11316;
      int v11329 = v11303->timer;
      int v11384 = v11329 + 1;
      v11303->timer = v11384;
      v11355 = v11316;
    } else {
      int * v11332 = v11303->mem;
      int v11386 = (int)((unsigned int)(v11307 + 44) >> 2);
      int v11333 = v11332[v11386];
      int * v11334 = v11303->mem;
      int * v11335 = v11303->cache_keys;
      int v11336 = v11335[1];
      int * v11337 = v11303->cache_vals;
      int v11338 = v11337[1];
      v11334[v11336] = v11338;
      int * v11340 = v11303->cache_keys;
      int * v11341 = v11303->cache_keys;
      int v11342 = v11341[0];
      v11340[1] = v11342;
      int * v11344 = v11303->cache_vals;
      int * v11345 = v11303->cache_vals;
      int v11346 = v11345[0];
      v11344[1] = v11346;
      int * v11348 = v11303->cache_keys;
      v11348[0] = v11386;
      int * v11350 = v11303->cache_vals;
      v11350[0] = v11333;
      int v11352 = v11303->timer;
      int v11401 = v11352 + 100;
      v11303->timer = v11401;
      v11355 = v11333;
    }
    v11357 = v11355;
  }
  int * v11358 = v11303->regs;
  v11358[27] = v11357;
  struct StateT * v11360 = slot_275(v11303);
  return v11360;
}

struct StateT * slot_263(struct StateT * v9937) {
  int v9938 = v9937->timer;
  int v9996 = v9938 + 1;
  v9937->timer = v9996;
  int * v9940 = v9937->regs;
  int v9941 = v9940[2];
  int * v9942 = v9937->cache_keys;
  int v9943 = v9942[0];
  bool v10001 = v9943 == ((int)((unsigned int)(v9941 + 88) >> 2));
  int v9991;
  if (v10001) {
    int * v9944 = v9937->cache_vals;
    int v9945 = v9944[0];
    v9991 = v9945;
  } else {
    int * v9947 = v9937->cache_keys;
    int v9948 = v9947[1];
    bool v10006 = v9948 == ((int)((unsigned int)(v9941 + 88) >> 2));
    int v9989;
    if (v10006) {
      int * v9949 = v9937->cache_vals;
      int v9950 = v9949[1];
      int * v9951 = v9937->cache_keys;
      int * v9952 = v9937->cache_keys;
      int v9953 = v9952[0];
      v9951[1] = v9953;
      int * v9955 = v9937->cache_vals;
      int * v9956 = v9937->cache_vals;
      int v9957 = v9956[0];
      v9955[1] = v9957;
      int * v9959 = v9937->cache_keys;
      int v10015 = (int)((unsigned int)(v9941 + 88) >> 2);
      v9959[0] = v10015;
      int * v9961 = v9937->cache_vals;
      v9961[0] = v9950;
      int v9963 = v9937->timer;
      int v10018 = v9963 + 1;
      v9937->timer = v10018;
      v9989 = v9950;
    } else {
      int * v9966 = v9937->mem;
      int v10020 = (int)((unsigned int)(v9941 + 88) >> 2);
      int v9967 = v9966[v10020];
      int * v9968 = v9937->mem;
      int * v9969 = v9937->cache_keys;
      int v9970 = v9969[1];
      int * v9971 = v9937->cache_vals;
      int v9972 = v9971[1];
      v9968[v9970] = v9972;
      int * v9974 = v9937->cache_keys;
      int * v9975 = v9937->cache_keys;
      int v9976 = v9975[0];
      v9974[1] = v9976;
      int * v9978 = v9937->cache_vals;
      int * v9979 = v9937->cache_vals;
      int v9980 = v9979[0];
      v9978[1] = v9980;
      int * v9982 = v9937->cache_keys;
      v9982[0] = v10020;
      int * v9984 = v9937->cache_vals;
      v9984[0] = v9967;
      int v9986 = v9937->timer;
      int v10035 = v9986 + 100;
      v9937->timer = v10035;
      v9989 = v9967;
    }
    v9991 = v9989;
  }
  int * v9992 = v9937->regs;
  v9992[8] = v9991;
  struct StateT * v9994 = slot_264(v9937);
  return v9994;
}

struct StateT * slot_161(struct StateT * v12355) {
  int v12356 = v12355->timer;
  int v12364 = v12356 + 1;
  v12355->timer = v12364;
  int * v12358 = v12355->regs;
  int v12359 = v12358[6];
  int * v12360 = v12355->regs;
  int v12369 = (int)((unsigned int)v12359 >> 23);
  v12360[9] = v12369;
  struct StateT * v12362 = slot_162(v12355);
  return v12362;
}

struct StateT * slot_185(struct StateT * v12801) {
  int v12802 = v12801->timer;
  int v12810 = v12802 + 1;
  v12801->timer = v12810;
  int * v12804 = v12801->regs;
  int v12805 = v12804[8];
  int * v12806 = v12801->regs;
  int v12814 = v12805 << 13;
  v12806[8] = v12814;
  struct StateT * v12808 = slot_186(v12801);
  return v12808;
}

struct StateT * slot_91(struct StateT * v8859) {
  int v8860 = v8859->timer;
  int v8870 = v8860 + 1;
  v8859->timer = v8870;
  int * v8862 = v8859->regs;
  int v8863 = v8862[26];
  int * v8864 = v8859->regs;
  int v8865 = v8864[12];
  int * v8866 = v8859->regs;
  int v8877 = v8863 + v8865;
  v8866[15] = v8877;
  struct StateT * v8868 = slot_92(v8859);
  return v8868;
}

struct StateT * slot_58(struct StateT * v6395) {
  int v6396 = v6395->timer;
  int v6404 = v6396 + 1;
  v6395->timer = v6404;
  int * v6398 = v6395->regs;
  int v6399 = v6398[20];
  int * v6400 = v6395->regs;
  int v6409 = (int)((unsigned int)v6399 >> 25);
  v6400[9] = v6409;
  struct StateT * v6402 = slot_59(v6395);
  return v6402;
}

struct StateT * slot_89(struct StateT * v8623) {
  int v8624 = v8623->timer;
  int v8634 = v8624 + 1;
  v8623->timer = v8634;
  int * v8626 = v8623->regs;
  int v8627 = v8626[27];
  int * v8628 = v8623->regs;
  int v8629 = v8628[9];
  int * v8630 = v8623->regs;
  int v8640 = v8627 ^ v8629;
  v8630[27] = v8640;
  struct StateT * v8632 = slot_90(v8623);
  return v8632;
}

struct StateT * slot_255(struct StateT * v8999) {
  int v9000 = v8999->timer;
  int v9054 = v9000 + 1;
  v8999->timer = v9054;
  int * v9002 = v8999->regs;
  int v9003 = v9002[10];
  int * v9004 = v8999->regs;
  int v9005 = v9004[13];
  int * v9006 = v8999->cache_keys;
  int v9007 = v9006[0];
  bool v9061 = v9007 == ((int)((unsigned int)(v9003 + 36) >> 2));
  int v9051;
  if (v9061) {
    int * v9008 = v8999->cache_vals;
    v9008[0] = v9005;
    v9051 = v9005;
  } else {
    int * v9011 = v8999->cache_keys;
    int v9012 = v9011[1];
    bool v9066 = v9012 == ((int)((unsigned int)(v9003 + 36) >> 2));
    int v9049;
    if (v9066) {
      int * v9013 = v8999->cache_keys;
      int * v9014 = v8999->cache_keys;
      int v9015 = v9014[0];
      v9013[1] = v9015;
      int * v9017 = v8999->cache_vals;
      int * v9018 = v8999->cache_vals;
      int v9019 = v9018[0];
      v9017[1] = v9019;
      int * v9021 = v8999->cache_keys;
      int v9074 = (int)((unsigned int)(v9003 + 36) >> 2);
      v9021[0] = v9074;
      int * v9023 = v8999->cache_vals;
      v9023[0] = v9005;
      int v9025 = v8999->timer;
      int v9077 = v9025 + 1;
      v8999->timer = v9077;
      v9049 = v9005;
    } else {
      int * v9028 = v8999->mem;
      int * v9029 = v8999->cache_keys;
      int v9030 = v9029[1];
      int * v9031 = v8999->cache_vals;
      int v9032 = v9031[1];
      v9028[v9030] = v9032;
      int * v9034 = v8999->cache_keys;
      int * v9035 = v8999->cache_keys;
      int v9036 = v9035[0];
      v9034[1] = v9036;
      int * v9038 = v8999->cache_vals;
      int * v9039 = v8999->cache_vals;
      int v9040 = v9039[0];
      v9038[1] = v9040;
      int * v9042 = v8999->cache_keys;
      int v9090 = (int)((unsigned int)(v9003 + 36) >> 2);
      v9042[0] = v9090;
      int * v9044 = v8999->cache_vals;
      v9044[0] = v9005;
      int v9046 = v8999->timer;
      int v9093 = v9046 + 100;
      v8999->timer = v9093;
      v9049 = v9005;
    }
    v9051 = v9049;
  }
  struct StateT * v9052 = slot_256(v8999);
  return v9052;
}

struct StateT * slot_66(struct StateT * v6942) {
  int v6943 = v6942->timer;
  int v6953 = v6943 + 1;
  v6942->timer = v6953;
  int * v6945 = v6942->regs;
  int v6946 = v6945[8];
  int * v6947 = v6942->regs;
  int v6948 = v6947[20];
  int * v6949 = v6942->regs;
  int v6959 = v6946 | v6948;
  v6949[8] = v6959;
  struct StateT * v6951 = slot_67(v6942);
  return v6951;
}

struct StateT * slot_140(struct StateT * v11955) {
  int v11956 = v11955->timer;
  int v11966 = v11956 + 1;
  v11955->timer = v11966;
  int * v11958 = v11955->regs;
  int v11959 = v11958[11];
  int * v11960 = v11955->regs;
  int v11961 = v11960[5];
  int * v11962 = v11955->regs;
  int v11972 = v11959 | v11961;
  v11962[11] = v11972;
  struct StateT * v11964 = slot_141(v11955);
  return v11964;
}

struct StateT * slot_265(struct StateT * v10180) {
  int v10181 = v10180->timer;
  int v10239 = v10181 + 1;
  v10180->timer = v10239;
  int * v10183 = v10180->regs;
  int v10184 = v10183[2];
  int * v10185 = v10180->cache_keys;
  int v10186 = v10185[0];
  bool v10244 = v10186 == ((int)((unsigned int)(v10184 + 80) >> 2));
  int v10234;
  if (v10244) {
    int * v10187 = v10180->cache_vals;
    int v10188 = v10187[0];
    v10234 = v10188;
  } else {
    int * v10190 = v10180->cache_keys;
    int v10191 = v10190[1];
    bool v10249 = v10191 == ((int)((unsigned int)(v10184 + 80) >> 2));
    int v10232;
    if (v10249) {
      int * v10192 = v10180->cache_vals;
      int v10193 = v10192[1];
      int * v10194 = v10180->cache_keys;
      int * v10195 = v10180->cache_keys;
      int v10196 = v10195[0];
      v10194[1] = v10196;
      int * v10198 = v10180->cache_vals;
      int * v10199 = v10180->cache_vals;
      int v10200 = v10199[0];
      v10198[1] = v10200;
      int * v10202 = v10180->cache_keys;
      int v10258 = (int)((unsigned int)(v10184 + 80) >> 2);
      v10202[0] = v10258;
      int * v10204 = v10180->cache_vals;
      v10204[0] = v10193;
      int v10206 = v10180->timer;
      int v10261 = v10206 + 1;
      v10180->timer = v10261;
      v10232 = v10193;
    } else {
      int * v10209 = v10180->mem;
      int v10263 = (int)((unsigned int)(v10184 + 80) >> 2);
      int v10210 = v10209[v10263];
      int * v10211 = v10180->mem;
      int * v10212 = v10180->cache_keys;
      int v10213 = v10212[1];
      int * v10214 = v10180->cache_vals;
      int v10215 = v10214[1];
      v10211[v10213] = v10215;
      int * v10217 = v10180->cache_keys;
      int * v10218 = v10180->cache_keys;
      int v10219 = v10218[0];
      v10217[1] = v10219;
      int * v10221 = v10180->cache_vals;
      int * v10222 = v10180->cache_vals;
      int v10223 = v10222[0];
      v10221[1] = v10223;
      int * v10225 = v10180->cache_keys;
      v10225[0] = v10263;
      int * v10227 = v10180->cache_vals;
      v10227[0] = v10210;
      int v10229 = v10180->timer;
      int v10278 = v10229 + 100;
      v10180->timer = v10278;
      v10232 = v10210;
    }
    v10234 = v10232;
  }
  int * v10235 = v10180->regs;
  v10235[18] = v10234;
  struct StateT * v10237 = slot_266(v10180);
  return v10237;
}

struct StateT * slot_49(struct StateT * v3645) {
  int v3646 = v3645->timer;
  int v3654 = v3646 + 1;
  v3645->timer = v3654;
  int * v3648 = v3645->regs;
  int v3649 = v3648[15];
  int * v3650 = v3645->regs;
  v3650[13] = v3649;
  struct StateT * v3652 = slot_50(v3645);
  return v3652;
}

struct StateT * slot_216(struct StateT * v6058) {
  int v6059 = v6058->timer;
  int v6069 = v6059 + 1;
  v6058->timer = v6069;
  int * v6061 = v6058->regs;
  int v6062 = v6061[14];
  int * v6063 = v6058->regs;
  int v6064 = v6063[7];
  int * v6065 = v6058->regs;
  int v6075 = v6062 + v6064;
  v6065[14] = v6075;
  struct StateT * v6067 = slot_217(v6058);
  return v6067;
}

struct StateT * slot_50(struct StateT * v3662) {
  int * v3663 = v3662->saved_regs;
  int * v3664 = v3662->regs;
  int v3665 = v3664[15];
  v3663[15] = v3665;
  int v3667 = v3662->timer;
  int v5029 = v3667 + 1;
  v3662->timer = v5029;
  int * v3669 = v3662->regs;
  int v3670 = v3669[21];
  int * v3671 = v3662->regs;
  int v3672 = v3671[16];
  int * v3673 = v3662->regs;
  int v5035 = v3670 + v3672;
  v3673[15] = v5035;
  int * v3675 = v3662->saved_regs;
  int * v3676 = v3662->regs;
  int v3677 = v3676[20];
  v3675[20] = v3677;
  int v3679 = v3662->timer;
  int v5040 = v3679 + 1;
  v3662->timer = v5040;
  int * v3681 = v3662->regs;
  int v3682 = v3681[11];
  int * v3683 = v3662->regs;
  int v3684 = v3683[23];
  int * v3685 = v3662->regs;
  int v5046 = v3682 + v3684;
  v3685[20] = v5046;
  int * v3687 = v3662->saved_regs;
  int * v3688 = v3662->regs;
  int v3689 = v3688[18];
  v3687[18] = v3689;
  int v3691 = v3662->timer;
  int v5051 = v3691 + 1;
  v3662->timer = v5051;
  int * v3693 = v3662->regs;
  int v3694 = v3693[19];
  int * v3695 = v3662->regs;
  int v3696 = v3695[5];
  int * v3697 = v3662->regs;
  int v5057 = v3694 + v3696;
  v3697[18] = v5057;
  int * v3699 = v3662->saved_regs;
  int * v3700 = v3662->regs;
  int v3701 = v3700[8];
  v3699[8] = v3701;
  int v3703 = v3662->timer;
  int v5062 = v3703 + 1;
  v3662->timer = v5062;
  int * v3705 = v3662->regs;
  int v3706 = v3705[22];
  int * v3707 = v3662->regs;
  int v3708 = v3707[17];
  int * v3709 = v3662->regs;
  int v5068 = v3706 + v3708;
  v3709[8] = v5068;
  int * v3711 = v3662->saved_regs;
  int * v3712 = v3662->regs;
  int v3713 = v3712[9];
  v3711[9] = v3713;
  int v3715 = v3662->timer;
  int v5073 = v3715 + 1;
  v3662->timer = v5073;
  int * v3717 = v3662->regs;
  int v3718 = v3717[15];
  int * v3719 = v3662->regs;
  int v5076 = (int)((unsigned int)v3718 >> 25);
  v3719[9] = v5076;
  int v3721 = v3662->timer;
  int v5077 = v3721 + 1;
  v3662->timer = v5077;
  int * v3723 = v3662->regs;
  int v3724 = v3723[15];
  int * v3725 = v3662->regs;
  int v5080 = v3724 << 7;
  v3725[15] = v5080;
  int v3727 = v3662->timer;
  int v5081 = v3727 + 1;
  v3662->timer = v5081;
  int * v3729 = v3662->regs;
  int v3730 = v3729[15];
  int * v3731 = v3662->regs;
  int v3732 = v3731[9];
  int * v3733 = v3662->regs;
  int v5085 = v3730 | v3732;
  v3733[15] = v5085;
  int v3735 = v3662->timer;
  int v5086 = v3735 + 1;
  v3662->timer = v5086;
  int * v3737 = v3662->regs;
  int v3738 = v3737[20];
  int * v3739 = v3662->regs;
  int v5089 = (int)((unsigned int)v3738 >> 25);
  v3739[9] = v5089;
  int v3741 = v3662->timer;
  int v5090 = v3741 + 1;
  v3662->timer = v5090;
  int * v3743 = v3662->regs;
  int v3744 = v3743[20];
  int * v3745 = v3662->regs;
  int v5093 = v3744 << 7;
  v3745[20] = v5093;
  int v3747 = v3662->timer;
  int v5094 = v3747 + 1;
  v3662->timer = v5094;
  int * v3749 = v3662->regs;
  int v3750 = v3749[20];
  int * v3751 = v3662->regs;
  int v3752 = v3751[9];
  int * v3753 = v3662->regs;
  int v5098 = v3750 | v3752;
  v3753[9] = v5098;
  int v3755 = v3662->timer;
  int v5099 = v3755 + 1;
  v3662->timer = v5099;
  int * v3757 = v3662->regs;
  int v3758 = v3757[18];
  int * v3759 = v3662->regs;
  int v5102 = (int)((unsigned int)v3758 >> 25);
  v3759[20] = v5102;
  int v3761 = v3662->timer;
  int v5103 = v3761 + 1;
  v3662->timer = v5103;
  int * v3763 = v3662->regs;
  int v3764 = v3763[18];
  int * v3765 = v3662->regs;
  int v5106 = v3764 << 7;
  v3765[18] = v5106;
  int v3767 = v3662->timer;
  int v5107 = v3767 + 1;
  v3662->timer = v5107;
  int * v3769 = v3662->regs;
  int v3770 = v3769[18];
  int * v3771 = v3662->regs;
  int v3772 = v3771[20];
  int * v3773 = v3662->regs;
  int v5111 = v3770 | v3772;
  v3773[18] = v5111;
  int v3775 = v3662->timer;
  int v5112 = v3775 + 1;
  v3662->timer = v5112;
  int * v3777 = v3662->regs;
  int v3778 = v3777[8];
  int * v3779 = v3662->regs;
  int v5115 = (int)((unsigned int)v3778 >> 25);
  v3779[20] = v5115;
  int v3781 = v3662->timer;
  int v5116 = v3781 + 1;
  v3662->timer = v5116;
  int * v3783 = v3662->regs;
  int v3784 = v3783[8];
  int * v3785 = v3662->regs;
  int v5119 = v3784 << 7;
  v3785[8] = v5119;
  int v3787 = v3662->timer;
  int v5120 = v3787 + 1;
  v3662->timer = v5120;
  int * v3789 = v3662->regs;
  int v3790 = v3789[8];
  int * v3791 = v3662->regs;
  int v3792 = v3791[20];
  int * v3793 = v3662->regs;
  int v5124 = v3790 | v3792;
  v3793[8] = v5124;
  int * v3795 = v3662->saved_regs;
  int * v3796 = v3662->regs;
  int v3797 = v3796[12];
  v3795[12] = v3797;
  int v3799 = v3662->timer;
  int v5129 = v3799 + 1;
  v3662->timer = v5129;
  int * v3801 = v3662->regs;
  int v3802 = v3801[12];
  int * v3803 = v3662->regs;
  int v3804 = v3803[15];
  int * v3805 = v3662->regs;
  int v5133 = v3802 ^ v3804;
  v3805[12] = v5133;
  int * v3807 = v3662->saved_regs;
  int * v3808 = v3662->regs;
  int v3809 = v3808[13];
  v3807[13] = v3809;
  int v3811 = v3662->timer;
  int v5138 = v3811 + 1;
  v3662->timer = v5138;
  int * v3813 = v3662->regs;
  int v3814 = v3813[13];
  int * v3815 = v3662->regs;
  int v3816 = v3815[9];
  int * v3817 = v3662->regs;
  int v5142 = v3814 ^ v3816;
  v3817[13] = v5142;
  int * v3819 = v3662->saved_regs;
  int * v3820 = v3662->regs;
  int v3821 = v3820[1];
  v3819[1] = v3821;
  int v3823 = v3662->timer;
  int v5147 = v3823 + 1;
  v3662->timer = v5147;
  int * v3825 = v3662->regs;
  int v3826 = v3825[1];
  int * v3827 = v3662->regs;
  int v3828 = v3827[18];
  int * v3829 = v3662->regs;
  int v5151 = v3826 ^ v3828;
  v3829[1] = v5151;
  int * v3831 = v3662->saved_regs;
  int * v3832 = v3662->regs;
  int v3833 = v3832[14];
  v3831[14] = v3833;
  int v3835 = v3662->timer;
  int v5156 = v3835 + 1;
  v3662->timer = v5156;
  int * v3837 = v3662->regs;
  int v3838 = v3837[14];
  int * v3839 = v3662->regs;
  int v3840 = v3839[8];
  int * v3841 = v3662->regs;
  int v5160 = v3838 ^ v3840;
  v3841[14] = v5160;
  int v3843 = v3662->timer;
  int v5161 = v3843 + 1;
  v3662->timer = v5161;
  int * v3845 = v3662->regs;
  int v3846 = v3845[12];
  int * v3847 = v3662->regs;
  int v3848 = v3847[21];
  int * v3849 = v3662->regs;
  int v5165 = v3846 + v3848;
  v3849[15] = v5165;
  int v3851 = v3662->timer;
  int v5166 = v3851 + 1;
  v3662->timer = v5166;
  int * v3853 = v3662->regs;
  int v3854 = v3853[13];
  int * v3855 = v3662->regs;
  int v3856 = v3855[11];
  int * v3857 = v3662->regs;
  int v5170 = v3854 + v3856;
  v3857[8] = v5170;
  int v3859 = v3662->timer;
  int v5171 = v3859 + 1;
  v3662->timer = v5171;
  int * v3861 = v3662->regs;
  int v3862 = v3861[1];
  int * v3863 = v3662->regs;
  int v3864 = v3863[19];
  int * v3865 = v3662->regs;
  int v5175 = v3862 + v3864;
  v3865[9] = v5175;
  int v3867 = v3662->timer;
  int v5176 = v3867 + 1;
  v3662->timer = v5176;
  int * v3869 = v3662->regs;
  int v3870 = v3869[14];
  int * v3871 = v3662->regs;
  int v3872 = v3871[22];
  int * v3873 = v3662->regs;
  int v5180 = v3870 + v3872;
  v3873[18] = v5180;
  int v3875 = v3662->timer;
  int v5181 = v3875 + 1;
  v3662->timer = v5181;
  int * v3877 = v3662->regs;
  int v3878 = v3877[15];
  int * v3879 = v3662->regs;
  int v5184 = (int)((unsigned int)v3878 >> 23);
  v3879[20] = v5184;
  int v3881 = v3662->timer;
  int v5185 = v3881 + 1;
  v3662->timer = v5185;
  int * v3883 = v3662->regs;
  int v3884 = v3883[15];
  int * v3885 = v3662->regs;
  int v5188 = v3884 << 9;
  v3885[15] = v5188;
  int v3887 = v3662->timer;
  int v5189 = v3887 + 1;
  v3662->timer = v5189;
  int * v3889 = v3662->regs;
  int v3890 = v3889[15];
  int * v3891 = v3662->regs;
  int v3892 = v3891[20];
  int * v3893 = v3662->regs;
  int v5193 = v3890 | v3892;
  v3893[15] = v5193;
  int v3895 = v3662->timer;
  int v5194 = v3895 + 1;
  v3662->timer = v5194;
  int * v3897 = v3662->regs;
  int v3898 = v3897[8];
  int * v3899 = v3662->regs;
  int v5197 = (int)((unsigned int)v3898 >> 23);
  v3899[20] = v5197;
  int v3901 = v3662->timer;
  int v5198 = v3901 + 1;
  v3662->timer = v5198;
  int * v3903 = v3662->regs;
  int v3904 = v3903[8];
  int * v3905 = v3662->regs;
  int v5201 = v3904 << 9;
  v3905[8] = v5201;
  int v3907 = v3662->timer;
  int v5202 = v3907 + 1;
  v3662->timer = v5202;
  int * v3909 = v3662->regs;
  int v3910 = v3909[8];
  int * v3911 = v3662->regs;
  int v3912 = v3911[20];
  int * v3913 = v3662->regs;
  int v5206 = v3910 | v3912;
  v3913[8] = v5206;
  int v3915 = v3662->timer;
  int v5207 = v3915 + 1;
  v3662->timer = v5207;
  int * v3917 = v3662->regs;
  int v3918 = v3917[9];
  int * v3919 = v3662->regs;
  int v5210 = (int)((unsigned int)v3918 >> 23);
  v3919[20] = v5210;
  int v3921 = v3662->timer;
  int v5211 = v3921 + 1;
  v3662->timer = v5211;
  int * v3923 = v3662->regs;
  int v3924 = v3923[9];
  int * v3925 = v3662->regs;
  int v5214 = v3924 << 9;
  v3925[9] = v5214;
  int v3927 = v3662->timer;
  int v5215 = v3927 + 1;
  v3662->timer = v5215;
  int * v3929 = v3662->regs;
  int v3930 = v3929[9];
  int * v3931 = v3662->regs;
  int v3932 = v3931[20];
  int * v3933 = v3662->regs;
  int v5219 = v3930 | v3932;
  v3933[9] = v5219;
  int v3935 = v3662->timer;
  int v5220 = v3935 + 1;
  v3662->timer = v5220;
  int * v3937 = v3662->regs;
  int v3938 = v3937[18];
  int * v3939 = v3662->regs;
  int v5223 = (int)((unsigned int)v3938 >> 23);
  v3939[20] = v5223;
  int v3941 = v3662->timer;
  int v5224 = v3941 + 1;
  v3662->timer = v5224;
  int * v3943 = v3662->regs;
  int v3944 = v3943[18];
  int * v3945 = v3662->regs;
  int v5227 = v3944 << 9;
  v3945[18] = v5227;
  int v3947 = v3662->timer;
  int v5228 = v3947 + 1;
  v3662->timer = v5228;
  int * v3949 = v3662->regs;
  int v3950 = v3949[18];
  int * v3951 = v3662->regs;
  int v3952 = v3951[20];
  int * v3953 = v3662->regs;
  int v5232 = v3950 | v3952;
  v3953[18] = v5232;
  int * v3955 = v3662->saved_regs;
  int * v3956 = v3662->regs;
  int v3957 = v3956[26];
  v3955[26] = v3957;
  int v3959 = v3662->timer;
  int v5237 = v3959 + 1;
  v3662->timer = v5237;
  int * v3961 = v3662->regs;
  int v3962 = v3961[26];
  int * v3963 = v3662->regs;
  int v3964 = v3963[15];
  int * v3965 = v3662->regs;
  int v5241 = v3962 ^ v3964;
  v3965[26] = v5241;
  int * v3967 = v3662->saved_regs;
  int * v3968 = v3662->regs;
  int v3969 = v3968[24];
  v3967[24] = v3969;
  int v3971 = v3662->timer;
  int v5246 = v3971 + 1;
  v3662->timer = v5246;
  int * v3973 = v3662->regs;
  int v3974 = v3973[24];
  int * v3975 = v3662->regs;
  int v3976 = v3975[8];
  int * v3977 = v3662->regs;
  int v5250 = v3974 ^ v3976;
  v3977[24] = v5250;
  int * v3979 = v3662->saved_regs;
  int * v3980 = v3662->regs;
  int v3981 = v3980[27];
  v3979[27] = v3981;
  int v3983 = v3662->timer;
  int v5255 = v3983 + 1;
  v3662->timer = v5255;
  int * v3985 = v3662->regs;
  int v3986 = v3985[27];
  int * v3987 = v3662->regs;
  int v3988 = v3987[9];
  int * v3989 = v3662->regs;
  int v5259 = v3986 ^ v3988;
  v3989[27] = v5259;
  int * v3991 = v3662->saved_regs;
  int * v3992 = v3662->regs;
  int v3993 = v3992[25];
  v3991[25] = v3993;
  int v3995 = v3662->timer;
  int v5264 = v3995 + 1;
  v3662->timer = v5264;
  int * v3997 = v3662->regs;
  int v3998 = v3997[25];
  int * v3999 = v3662->regs;
  int v4000 = v3999[18];
  int * v4001 = v3662->regs;
  int v5268 = v3998 ^ v4000;
  v4001[25] = v5268;
  int v4003 = v3662->timer;
  int v5269 = v4003 + 1;
  v3662->timer = v5269;
  int * v4005 = v3662->regs;
  int v4006 = v4005[26];
  int * v4007 = v3662->regs;
  int v4008 = v4007[12];
  int * v4009 = v3662->regs;
  int v5273 = v4006 + v4008;
  v4009[15] = v5273;
  int v4011 = v3662->timer;
  int v5274 = v4011 + 1;
  v3662->timer = v5274;
  int * v4013 = v3662->regs;
  int v4014 = v4013[24];
  int * v4015 = v3662->regs;
  int v4016 = v4015[13];
  int * v4017 = v3662->regs;
  int v5278 = v4014 + v4016;
  v4017[8] = v5278;
  int v4019 = v3662->timer;
  int v5279 = v4019 + 1;
  v3662->timer = v5279;
  int * v4021 = v3662->regs;
  int v4022 = v4021[27];
  int * v4023 = v3662->regs;
  int v4024 = v4023[1];
  int * v4025 = v3662->regs;
  int v5283 = v4022 + v4024;
  v4025[9] = v5283;
  int v4027 = v3662->timer;
  int v5284 = v4027 + 1;
  v3662->timer = v5284;
  int * v4029 = v3662->regs;
  int v4030 = v4029[25];
  int * v4031 = v3662->regs;
  int v4032 = v4031[14];
  int * v4033 = v3662->regs;
  int v5288 = v4030 + v4032;
  v4033[18] = v5288;
  int v4035 = v3662->timer;
  int v5289 = v4035 + 1;
  v3662->timer = v5289;
  int * v4037 = v3662->regs;
  int v4038 = v4037[15];
  int * v4039 = v3662->regs;
  int v5292 = (int)((unsigned int)v4038 >> 19);
  v4039[20] = v5292;
  int v4041 = v3662->timer;
  int v5293 = v4041 + 1;
  v3662->timer = v5293;
  int * v4043 = v3662->regs;
  int v4044 = v4043[15];
  int * v4045 = v3662->regs;
  int v5296 = v4044 << 13;
  v4045[15] = v5296;
  int v4047 = v3662->timer;
  int v5297 = v4047 + 1;
  v3662->timer = v5297;
  int * v4049 = v3662->regs;
  int v4050 = v4049[15];
  int * v4051 = v3662->regs;
  int v4052 = v4051[20];
  int * v4053 = v3662->regs;
  int v5301 = v4050 | v4052;
  v4053[15] = v5301;
  int v4055 = v3662->timer;
  int v5302 = v4055 + 1;
  v3662->timer = v5302;
  int * v4057 = v3662->regs;
  int v4058 = v4057[8];
  int * v4059 = v3662->regs;
  int v5305 = (int)((unsigned int)v4058 >> 19);
  v4059[20] = v5305;
  int v4061 = v3662->timer;
  int v5306 = v4061 + 1;
  v3662->timer = v5306;
  int * v4063 = v3662->regs;
  int v4064 = v4063[8];
  int * v4065 = v3662->regs;
  int v5309 = v4064 << 13;
  v4065[8] = v5309;
  int v4067 = v3662->timer;
  int v5310 = v4067 + 1;
  v3662->timer = v5310;
  int * v4069 = v3662->regs;
  int v4070 = v4069[8];
  int * v4071 = v3662->regs;
  int v4072 = v4071[20];
  int * v4073 = v3662->regs;
  int v5314 = v4070 | v4072;
  v4073[8] = v5314;
  int v4075 = v3662->timer;
  int v5315 = v4075 + 1;
  v3662->timer = v5315;
  int * v4077 = v3662->regs;
  int v4078 = v4077[9];
  int * v4079 = v3662->regs;
  int v5318 = (int)((unsigned int)v4078 >> 19);
  v4079[20] = v5318;
  int v4081 = v3662->timer;
  int v5319 = v4081 + 1;
  v3662->timer = v5319;
  int * v4083 = v3662->regs;
  int v4084 = v4083[9];
  int * v4085 = v3662->regs;
  int v5322 = v4084 << 13;
  v4085[9] = v5322;
  int v4087 = v3662->timer;
  int v5323 = v4087 + 1;
  v3662->timer = v5323;
  int * v4089 = v3662->regs;
  int v4090 = v4089[9];
  int * v4091 = v3662->regs;
  int v4092 = v4091[20];
  int * v4093 = v3662->regs;
  int v5327 = v4090 | v4092;
  v4093[20] = v5327;
  int v4095 = v3662->timer;
  int v5328 = v4095 + 1;
  v3662->timer = v5328;
  int * v4097 = v3662->regs;
  int v4098 = v4097[18];
  int * v4099 = v3662->regs;
  int v5331 = (int)((unsigned int)v4098 >> 19);
  v4099[9] = v5331;
  int v4101 = v3662->timer;
  int v5332 = v4101 + 1;
  v3662->timer = v5332;
  int * v4103 = v3662->regs;
  int v4104 = v4103[18];
  int * v4105 = v3662->regs;
  int v5335 = v4104 << 13;
  v4105[18] = v5335;
  int * v4107 = v3662->saved_regs;
  int * v4108 = v3662->regs;
  int v4109 = v4108[6];
  v4107[6] = v4109;
  int v4111 = v3662->timer;
  int v5340 = v4111 + 1;
  v3662->timer = v5340;
  int * v4113 = v3662->regs;
  int v4114 = v4113[18];
  int * v4115 = v3662->regs;
  int v4116 = v4115[9];
  int * v4117 = v3662->regs;
  int v5344 = v4114 | v4116;
  v4117[6] = v5344;
  int v4119 = v3662->timer;
  int v5345 = v4119 + 1;
  v3662->timer = v5345;
  int * v4121 = v3662->regs;
  int v4122 = v4121[16];
  int * v4123 = v3662->regs;
  int v4124 = v4123[15];
  int * v4125 = v3662->regs;
  int v5349 = v4122 ^ v4124;
  v4125[9] = v5349;
  int * v4127 = v3662->saved_regs;
  int * v4128 = v3662->regs;
  int v4129 = v4128[23];
  v4127[23] = v4129;
  int v4131 = v3662->timer;
  int v5353 = v4131 + 1;
  v3662->timer = v5353;
  int * v4133 = v3662->regs;
  int v4134 = v4133[23];
  int * v4135 = v3662->regs;
  int v4136 = v4135[8];
  int * v4137 = v3662->regs;
  int v5357 = v4134 ^ v4136;
  v4137[23] = v5357;
  int v4139 = v3662->timer;
  int v5358 = v4139 + 1;
  v3662->timer = v5358;
  int * v4141 = v3662->regs;
  int v4142 = v4141[5];
  int * v4143 = v3662->regs;
  int v4144 = v4143[20];
  int * v4145 = v3662->regs;
  int v5362 = v4142 ^ v4144;
  v4145[18] = v5362;
  int v4147 = v3662->timer;
  int v5363 = v4147 + 1;
  v3662->timer = v5363;
  int * v4149 = v3662->regs;
  int v4150 = v4149[17];
  int * v4151 = v3662->regs;
  int v4152 = v4151[6];
  int * v4153 = v3662->regs;
  int v5367 = v4150 ^ v4152;
  v4153[8] = v5367;
  int v4155 = v3662->timer;
  int v5368 = v4155 + 1;
  v3662->timer = v5368;
  int * v4157 = v3662->regs;
  int v4158 = v4157[9];
  int * v4159 = v3662->regs;
  int v4160 = v4159[26];
  int * v4161 = v3662->regs;
  int v5372 = v4158 + v4160;
  v4161[15] = v5372;
  int * v4163 = v3662->saved_regs;
  int * v4164 = v3662->regs;
  int v4165 = v4164[16];
  v4163[16] = v4165;
  int v4167 = v3662->timer;
  int v5376 = v4167 + 1;
  v3662->timer = v5376;
  int * v4169 = v3662->regs;
  int v4170 = v4169[23];
  int * v4171 = v3662->regs;
  int v4172 = v4171[24];
  int * v4173 = v3662->regs;
  int v5380 = v4170 + v4172;
  v4173[16] = v5380;
  int * v4175 = v3662->saved_regs;
  int * v4176 = v3662->regs;
  int v4177 = v4176[17];
  v4175[17] = v4177;
  int v4179 = v3662->timer;
  int v5384 = v4179 + 1;
  v3662->timer = v5384;
  int * v4181 = v3662->regs;
  int v4182 = v4181[18];
  int * v4183 = v3662->regs;
  int v4184 = v4183[27];
  int * v4185 = v3662->regs;
  int v5388 = v4182 + v4184;
  v4185[17] = v5388;
  int * v4187 = v3662->saved_regs;
  int * v4188 = v3662->regs;
  int v4189 = v4188[5];
  v4187[5] = v4189;
  int v4191 = v3662->timer;
  int v5392 = v4191 + 1;
  v3662->timer = v5392;
  int * v4193 = v3662->regs;
  int v4194 = v4193[8];
  int * v4195 = v3662->regs;
  int v4196 = v4195[25];
  int * v4197 = v3662->regs;
  int v5396 = v4194 + v4196;
  v4197[5] = v5396;
  int v4199 = v3662->timer;
  int v5397 = v4199 + 1;
  v3662->timer = v5397;
  int * v4201 = v3662->regs;
  int v4202 = v4201[15];
  int * v4203 = v3662->regs;
  int v5400 = (int)((unsigned int)v4202 >> 14);
  v4203[6] = v5400;
  int v4205 = v3662->timer;
  int v5401 = v4205 + 1;
  v3662->timer = v5401;
  int * v4207 = v3662->regs;
  int v4208 = v4207[15];
  int * v4209 = v3662->regs;
  int v5404 = v4208 << 18;
  v4209[15] = v5404;
  int v4211 = v3662->timer;
  int v5405 = v4211 + 1;
  v3662->timer = v5405;
  int * v4213 = v3662->regs;
  int v4214 = v4213[15];
  int * v4215 = v3662->regs;
  int v4216 = v4215[6];
  int * v4217 = v3662->regs;
  int v5409 = v4214 | v4216;
  v4217[15] = v5409;
  int v4219 = v3662->timer;
  int v5410 = v4219 + 1;
  v3662->timer = v5410;
  int * v4221 = v3662->regs;
  int v4222 = v4221[16];
  int * v4223 = v3662->regs;
  int v5413 = (int)((unsigned int)v4222 >> 14);
  v4223[6] = v5413;
  int v4225 = v3662->timer;
  int v5414 = v4225 + 1;
  v3662->timer = v5414;
  int * v4227 = v3662->regs;
  int v4228 = v4227[16];
  int * v4229 = v3662->regs;
  int v5417 = v4228 << 18;
  v4229[16] = v5417;
  int v4231 = v3662->timer;
  int v5418 = v4231 + 1;
  v3662->timer = v5418;
  int * v4233 = v3662->regs;
  int v4234 = v4233[16];
  int * v4235 = v3662->regs;
  int v4236 = v4235[6];
  int * v4237 = v3662->regs;
  int v5422 = v4234 | v4236;
  v4237[16] = v5422;
  int v4239 = v3662->timer;
  int v5423 = v4239 + 1;
  v3662->timer = v5423;
  int * v4241 = v3662->regs;
  int v4242 = v4241[17];
  int * v4243 = v3662->regs;
  int v5426 = (int)((unsigned int)v4242 >> 14);
  v4243[6] = v5426;
  int v4245 = v3662->timer;
  int v5427 = v4245 + 1;
  v3662->timer = v5427;
  int * v4247 = v3662->regs;
  int v4248 = v4247[17];
  int * v4249 = v3662->regs;
  int v5430 = v4248 << 18;
  v4249[17] = v5430;
  int v4251 = v3662->timer;
  int v5431 = v4251 + 1;
  v3662->timer = v5431;
  int * v4253 = v3662->regs;
  int v4254 = v4253[17];
  int * v4255 = v3662->regs;
  int v4256 = v4255[6];
  int * v4257 = v3662->regs;
  int v5435 = v4254 | v4256;
  v4257[17] = v5435;
  int v4259 = v3662->timer;
  int v5436 = v4259 + 1;
  v3662->timer = v5436;
  int * v4261 = v3662->regs;
  int v4262 = v4261[5];
  int * v4263 = v3662->regs;
  int v5439 = (int)((unsigned int)v4262 >> 14);
  v4263[6] = v5439;
  int v4265 = v3662->timer;
  int v5440 = v4265 + 1;
  v3662->timer = v5440;
  int * v4267 = v3662->regs;
  int v4268 = v4267[5];
  int * v4269 = v3662->regs;
  int v5443 = v4268 << 18;
  v4269[5] = v5443;
  int v4271 = v3662->timer;
  int v5444 = v4271 + 1;
  v3662->timer = v5444;
  int * v4273 = v3662->regs;
  int v4274 = v4273[5];
  int * v4275 = v3662->regs;
  int v4276 = v4275[6];
  int * v4277 = v3662->regs;
  int v5448 = v4274 | v4276;
  v4277[5] = v5448;
  int * v4279 = v3662->saved_regs;
  int * v4280 = v3662->regs;
  int v4281 = v4280[21];
  v4279[21] = v4281;
  int v4283 = v3662->timer;
  int v5452 = v4283 + 1;
  v3662->timer = v5452;
  int * v4285 = v3662->regs;
  int v4286 = v4285[21];
  int * v4287 = v3662->regs;
  int v4288 = v4287[15];
  int * v4289 = v3662->regs;
  int v5456 = v4286 ^ v4288;
  v4289[21] = v5456;
  int v4291 = v3662->timer;
  int v5457 = v4291 + 1;
  v3662->timer = v5457;
  int * v4293 = v3662->regs;
  int v4294 = v4293[11];
  int * v4295 = v3662->regs;
  int v4296 = v4295[16];
  int * v4297 = v3662->regs;
  int v5461 = v4294 ^ v4296;
  v4297[20] = v5461;
  int * v4299 = v3662->saved_regs;
  int * v4300 = v3662->regs;
  int v4301 = v4300[19];
  v4299[19] = v4301;
  int v4303 = v3662->timer;
  int v5465 = v4303 + 1;
  v3662->timer = v5465;
  int * v4305 = v3662->regs;
  int v4306 = v4305[19];
  int * v4307 = v3662->regs;
  int v4308 = v4307[17];
  int * v4309 = v3662->regs;
  int v5469 = v4306 ^ v4308;
  v4309[19] = v5469;
  int * v4311 = v3662->saved_regs;
  int * v4312 = v3662->regs;
  int v4313 = v4312[22];
  v4311[22] = v4313;
  int v4315 = v3662->timer;
  int v5473 = v4315 + 1;
  v3662->timer = v5473;
  int * v4317 = v3662->regs;
  int v4318 = v4317[22];
  int * v4319 = v3662->regs;
  int v4320 = v4319[5];
  int * v4321 = v3662->regs;
  int v5477 = v4318 ^ v4320;
  v4321[22] = v5477;
  int v4323 = v3662->timer;
  int v5478 = v4323 + 1;
  v3662->timer = v5478;
  int * v4325 = v3662->regs;
  int v4326 = v4325[21];
  int * v4327 = v3662->regs;
  int v4328 = v4327[14];
  int * v4329 = v3662->regs;
  int v5482 = v4326 + v4328;
  v4329[15] = v5482;
  int * v4331 = v3662->saved_regs;
  int * v4332 = v3662->regs;
  int v4333 = v4332[11];
  v4331[11] = v4333;
  int v4335 = v3662->timer;
  int v5486 = v4335 + 1;
  v3662->timer = v5486;
  int * v4337 = v3662->regs;
  int v4338 = v4337[20];
  int * v4339 = v3662->regs;
  int v4340 = v4339[12];
  int * v4341 = v3662->regs;
  int v5490 = v4338 + v4340;
  v4341[11] = v5490;
  int v4343 = v3662->timer;
  int v5491 = v4343 + 1;
  v3662->timer = v5491;
  int * v4345 = v3662->regs;
  int v4346 = v4345[19];
  int * v4347 = v3662->regs;
  int v4348 = v4347[13];
  int * v4349 = v3662->regs;
  int v5495 = v4346 + v4348;
  v4349[16] = v5495;
  int v4351 = v3662->timer;
  int v5496 = v4351 + 1;
  v3662->timer = v5496;
  int * v4353 = v3662->regs;
  int v4354 = v4353[22];
  int * v4355 = v3662->regs;
  int v4356 = v4355[1];
  int * v4357 = v3662->regs;
  int v5500 = v4354 + v4356;
  v4357[17] = v5500;
  int v4359 = v3662->timer;
  int v5501 = v4359 + 1;
  v3662->timer = v5501;
  int * v4361 = v3662->regs;
  int v4362 = v4361[15];
  int * v4363 = v3662->regs;
  int v5504 = (int)((unsigned int)v4362 >> 25);
  v4363[5] = v5504;
  int v4365 = v3662->timer;
  int v5505 = v4365 + 1;
  v3662->timer = v5505;
  int * v4367 = v3662->regs;
  int v4368 = v4367[15];
  int * v4369 = v3662->regs;
  int v5508 = v4368 << 7;
  v4369[15] = v5508;
  int v4371 = v3662->timer;
  int v5509 = v4371 + 1;
  v3662->timer = v5509;
  int * v4373 = v3662->regs;
  int v4374 = v4373[15];
  int * v4375 = v3662->regs;
  int v4376 = v4375[5];
  int * v4377 = v3662->regs;
  int v5513 = v4374 | v4376;
  v4377[15] = v5513;
  int v4379 = v3662->timer;
  int v5514 = v4379 + 1;
  v3662->timer = v5514;
  int * v4381 = v3662->regs;
  int v4382 = v4381[11];
  int * v4383 = v3662->regs;
  int v5517 = (int)((unsigned int)v4382 >> 25);
  v4383[5] = v5517;
  int v4385 = v3662->timer;
  int v5518 = v4385 + 1;
  v3662->timer = v5518;
  int * v4387 = v3662->regs;
  int v4388 = v4387[11];
  int * v4389 = v3662->regs;
  int v5521 = v4388 << 7;
  v4389[11] = v5521;
  int v4391 = v3662->timer;
  int v5522 = v4391 + 1;
  v3662->timer = v5522;
  int * v4393 = v3662->regs;
  int v4394 = v4393[11];
  int * v4395 = v3662->regs;
  int v4396 = v4395[5];
  int * v4397 = v3662->regs;
  int v5526 = v4394 | v4396;
  v4397[11] = v5526;
  int v4399 = v3662->timer;
  int v5527 = v4399 + 1;
  v3662->timer = v5527;
  int * v4401 = v3662->regs;
  int v4402 = v4401[16];
  int * v4403 = v3662->regs;
  int v5530 = (int)((unsigned int)v4402 >> 25);
  v4403[5] = v5530;
  int v4405 = v3662->timer;
  int v5531 = v4405 + 1;
  v3662->timer = v5531;
  int * v4407 = v3662->regs;
  int v4408 = v4407[16];
  int * v4409 = v3662->regs;
  int v5534 = v4408 << 7;
  v4409[16] = v5534;
  int v4411 = v3662->timer;
  int v5535 = v4411 + 1;
  v3662->timer = v5535;
  int * v4413 = v3662->regs;
  int v4414 = v4413[16];
  int * v4415 = v3662->regs;
  int v4416 = v4415[5];
  int * v4417 = v3662->regs;
  int v5539 = v4414 | v4416;
  v4417[16] = v5539;
  int v4419 = v3662->timer;
  int v5540 = v4419 + 1;
  v3662->timer = v5540;
  int * v4421 = v3662->regs;
  int v4422 = v4421[17];
  int * v4423 = v3662->regs;
  int v5543 = (int)((unsigned int)v4422 >> 25);
  v4423[5] = v5543;
  int v4425 = v3662->timer;
  int v5544 = v4425 + 1;
  v3662->timer = v5544;
  int * v4427 = v3662->regs;
  int v4428 = v4427[17];
  int * v4429 = v3662->regs;
  int v5547 = v4428 << 7;
  v4429[17] = v5547;
  int v4431 = v3662->timer;
  int v5548 = v4431 + 1;
  v3662->timer = v5548;
  int * v4433 = v3662->regs;
  int v4434 = v4433[17];
  int * v4435 = v3662->regs;
  int v4436 = v4435[5];
  int * v4437 = v3662->regs;
  int v5552 = v4434 | v4436;
  v4437[6] = v5552;
  int v4439 = v3662->timer;
  int v5553 = v4439 + 1;
  v3662->timer = v5553;
  int * v4441 = v3662->regs;
  int v4442 = v4441[23];
  int * v4443 = v3662->regs;
  int v4444 = v4443[15];
  int * v4445 = v3662->regs;
  int v5557 = v4442 ^ v4444;
  v4445[23] = v5557;
  int v4447 = v3662->timer;
  int v5558 = v4447 + 1;
  v3662->timer = v5558;
  int * v4449 = v3662->regs;
  int v4450 = v4449[18];
  int * v4451 = v3662->regs;
  int v4452 = v4451[11];
  int * v4453 = v3662->regs;
  int v5562 = v4450 ^ v4452;
  v4453[5] = v5562;
  int v4455 = v3662->timer;
  int v5563 = v4455 + 1;
  v3662->timer = v5563;
  int * v4457 = v3662->regs;
  int v4458 = v4457[8];
  int * v4459 = v3662->regs;
  int v4460 = v4459[16];
  int * v4461 = v3662->regs;
  int v5567 = v4458 ^ v4460;
  v4461[17] = v5567;
  int v4463 = v3662->timer;
  int v5568 = v4463 + 1;
  v3662->timer = v5568;
  int * v4465 = v3662->regs;
  int v4466 = v4465[9];
  int * v4467 = v3662->regs;
  int v4468 = v4467[6];
  int * v4469 = v3662->regs;
  int v5572 = v4466 ^ v4468;
  v4469[16] = v5572;
  int v4471 = v3662->timer;
  int v5573 = v4471 + 1;
  v3662->timer = v5573;
  int * v4473 = v3662->regs;
  int v4474 = v4473[23];
  int * v4475 = v3662->regs;
  int v4476 = v4475[21];
  int * v4477 = v3662->regs;
  int v5577 = v4474 + v4476;
  v4477[11] = v5577;
  int v4479 = v3662->timer;
  int v5578 = v4479 + 1;
  v3662->timer = v5578;
  int * v4481 = v3662->regs;
  int v4482 = v4481[5];
  int * v4483 = v3662->regs;
  int v4484 = v4483[20];
  int * v4485 = v3662->regs;
  int v5582 = v4482 + v4484;
  v4485[15] = v5582;
  int v4487 = v3662->timer;
  int v5583 = v4487 + 1;
  v3662->timer = v5583;
  int * v4489 = v3662->regs;
  int v4490 = v4489[17];
  int * v4491 = v3662->regs;
  int v4492 = v4491[19];
  int * v4493 = v3662->regs;
  int v5587 = v4490 + v4492;
  v4493[6] = v5587;
  int v4495 = v3662->timer;
  int v5588 = v4495 + 1;
  v3662->timer = v5588;
  int * v4497 = v3662->regs;
  int v4498 = v4497[16];
  int * v4499 = v3662->regs;
  int v4500 = v4499[22];
  int * v4501 = v3662->regs;
  int v5592 = v4498 + v4500;
  v4501[8] = v5592;
  int v4503 = v3662->timer;
  int v5593 = v4503 + 1;
  v3662->timer = v5593;
  int * v4505 = v3662->regs;
  int v4506 = v4505[11];
  int * v4507 = v3662->regs;
  int v5596 = (int)((unsigned int)v4506 >> 23);
  v4507[9] = v5596;
  int v4509 = v3662->timer;
  int v5597 = v4509 + 1;
  v3662->timer = v5597;
  int * v4511 = v3662->regs;
  int v4512 = v4511[11];
  int * v4513 = v3662->regs;
  int v5600 = v4512 << 9;
  v4513[11] = v5600;
  int v4515 = v3662->timer;
  int v5601 = v4515 + 1;
  v3662->timer = v5601;
  int * v4517 = v3662->regs;
  int v4518 = v4517[11];
  int * v4519 = v3662->regs;
  int v4520 = v4519[9];
  int * v4521 = v3662->regs;
  int v5605 = v4518 | v4520;
  v4521[11] = v5605;
  int v4523 = v3662->timer;
  int v5606 = v4523 + 1;
  v3662->timer = v5606;
  int * v4525 = v3662->regs;
  int v4526 = v4525[15];
  int * v4527 = v3662->regs;
  int v5609 = (int)((unsigned int)v4526 >> 23);
  v4527[9] = v5609;
  int v4529 = v3662->timer;
  int v5610 = v4529 + 1;
  v3662->timer = v5610;
  int * v4531 = v3662->regs;
  int v4532 = v4531[15];
  int * v4533 = v3662->regs;
  int v5613 = v4532 << 9;
  v4533[15] = v5613;
  int v4535 = v3662->timer;
  int v5614 = v4535 + 1;
  v3662->timer = v5614;
  int * v4537 = v3662->regs;
  int v4538 = v4537[15];
  int * v4539 = v3662->regs;
  int v4540 = v4539[9];
  int * v4541 = v3662->regs;
  int v5618 = v4538 | v4540;
  v4541[15] = v5618;
  int v4543 = v3662->timer;
  int v5619 = v4543 + 1;
  v3662->timer = v5619;
  int * v4545 = v3662->regs;
  int v4546 = v4545[6];
  int * v4547 = v3662->regs;
  int v5622 = (int)((unsigned int)v4546 >> 23);
  v4547[9] = v5622;
  int v4549 = v3662->timer;
  int v5623 = v4549 + 1;
  v3662->timer = v5623;
  int * v4551 = v3662->regs;
  int v4552 = v4551[6];
  int * v4553 = v3662->regs;
  int v5626 = v4552 << 9;
  v4553[6] = v5626;
  int v4555 = v3662->timer;
  int v5627 = v4555 + 1;
  v3662->timer = v5627;
  int * v4557 = v3662->regs;
  int v4558 = v4557[6];
  int * v4559 = v3662->regs;
  int v4560 = v4559[9];
  int * v4561 = v3662->regs;
  int v5631 = v4558 | v4560;
  v4561[6] = v5631;
  int v4563 = v3662->timer;
  int v5632 = v4563 + 1;
  v3662->timer = v5632;
  int * v4565 = v3662->regs;
  int v4566 = v4565[8];
  int * v4567 = v3662->regs;
  int v5635 = (int)((unsigned int)v4566 >> 23);
  v4567[9] = v5635;
  int v4569 = v3662->timer;
  int v5636 = v4569 + 1;
  v3662->timer = v5636;
  int * v4571 = v3662->regs;
  int v4572 = v4571[8];
  int * v4573 = v3662->regs;
  int v5639 = v4572 << 9;
  v4573[8] = v5639;
  int v4575 = v3662->timer;
  int v5640 = v4575 + 1;
  v3662->timer = v5640;
  int * v4577 = v3662->regs;
  int v4578 = v4577[8];
  int * v4579 = v3662->regs;
  int v4580 = v4579[9];
  int * v4581 = v3662->regs;
  int v5644 = v4578 | v4580;
  v4581[8] = v5644;
  int v4583 = v3662->timer;
  int v5645 = v4583 + 1;
  v3662->timer = v5645;
  int * v4585 = v3662->regs;
  int v4586 = v4585[27];
  int * v4587 = v3662->regs;
  int v4588 = v4587[11];
  int * v4589 = v3662->regs;
  int v5649 = v4586 ^ v4588;
  v4589[27] = v5649;
  int v4591 = v3662->timer;
  int v5650 = v4591 + 1;
  v3662->timer = v5650;
  int * v4593 = v3662->regs;
  int v4594 = v4593[25];
  int * v4595 = v3662->regs;
  int v4596 = v4595[15];
  int * v4597 = v3662->regs;
  int v5654 = v4594 ^ v4596;
  v4597[25] = v5654;
  int v4599 = v3662->timer;
  int v5655 = v4599 + 1;
  v3662->timer = v5655;
  int * v4601 = v3662->regs;
  int v4602 = v4601[26];
  int * v4603 = v3662->regs;
  int v4604 = v4603[6];
  int * v4605 = v3662->regs;
  int v5659 = v4602 ^ v4604;
  v4605[26] = v5659;
  int v4607 = v3662->timer;
  int v5660 = v4607 + 1;
  v3662->timer = v5660;
  int * v4609 = v3662->regs;
  int v4610 = v4609[24];
  int * v4611 = v3662->regs;
  int v4612 = v4611[8];
  int * v4613 = v3662->regs;
  int v5664 = v4610 ^ v4612;
  v4613[24] = v5664;
  int v4615 = v3662->timer;
  int v5665 = v4615 + 1;
  v3662->timer = v5665;
  int * v4617 = v3662->regs;
  int v4618 = v4617[27];
  int * v4619 = v3662->regs;
  int v4620 = v4619[23];
  int * v4621 = v3662->regs;
  int v5669 = v4618 + v4620;
  v4621[11] = v5669;
  int v4623 = v3662->timer;
  int v5670 = v4623 + 1;
  v3662->timer = v5670;
  int * v4625 = v3662->regs;
  int v4626 = v4625[25];
  int * v4627 = v3662->regs;
  int v4628 = v4627[5];
  int * v4629 = v3662->regs;
  int v5674 = v4626 + v4628;
  v4629[15] = v5674;
  int v4631 = v3662->timer;
  int v5675 = v4631 + 1;
  v3662->timer = v5675;
  int * v4633 = v3662->regs;
  int v4634 = v4633[26];
  int * v4635 = v3662->regs;
  int v4636 = v4635[17];
  int * v4637 = v3662->regs;
  int v5679 = v4634 + v4636;
  v4637[6] = v5679;
  int v4639 = v3662->timer;
  int v5680 = v4639 + 1;
  v3662->timer = v5680;
  int * v4641 = v3662->regs;
  int v4642 = v4641[24];
  int * v4643 = v3662->regs;
  int v4644 = v4643[16];
  int * v4645 = v3662->regs;
  int v5684 = v4642 + v4644;
  v4645[8] = v5684;
  int v4647 = v3662->timer;
  int v5685 = v4647 + 1;
  v3662->timer = v5685;
  int * v4649 = v3662->regs;
  int v4650 = v4649[11];
  int * v4651 = v3662->regs;
  int v5688 = (int)((unsigned int)v4650 >> 19);
  v4651[9] = v5688;
  int v4653 = v3662->timer;
  int v5689 = v4653 + 1;
  v3662->timer = v5689;
  int * v4655 = v3662->regs;
  int v4656 = v4655[11];
  int * v4657 = v3662->regs;
  int v5692 = v4656 << 13;
  v4657[11] = v5692;
  int v4659 = v3662->timer;
  int v5693 = v4659 + 1;
  v3662->timer = v5693;
  int * v4661 = v3662->regs;
  int v4662 = v4661[11];
  int * v4663 = v3662->regs;
  int v4664 = v4663[9];
  int * v4665 = v3662->regs;
  int v5697 = v4662 | v4664;
  v4665[11] = v5697;
  int v4667 = v3662->timer;
  int v5698 = v4667 + 1;
  v3662->timer = v5698;
  int * v4669 = v3662->regs;
  int v4670 = v4669[15];
  int * v4671 = v3662->regs;
  int v5701 = (int)((unsigned int)v4670 >> 19);
  v4671[9] = v5701;
  int v4673 = v3662->timer;
  int v5702 = v4673 + 1;
  v3662->timer = v5702;
  int * v4675 = v3662->regs;
  int v4676 = v4675[15];
  int * v4677 = v3662->regs;
  int v5705 = v4676 << 13;
  v4677[15] = v5705;
  int v4679 = v3662->timer;
  int v5706 = v4679 + 1;
  v3662->timer = v5706;
  int * v4681 = v3662->regs;
  int v4682 = v4681[15];
  int * v4683 = v3662->regs;
  int v4684 = v4683[9];
  int * v4685 = v3662->regs;
  int v5710 = v4682 | v4684;
  v4685[15] = v5710;
  int v4687 = v3662->timer;
  int v5711 = v4687 + 1;
  v3662->timer = v5711;
  int * v4689 = v3662->regs;
  int v4690 = v4689[6];
  int * v4691 = v3662->regs;
  int v5714 = (int)((unsigned int)v4690 >> 19);
  v4691[9] = v5714;
  int v4693 = v3662->timer;
  int v5715 = v4693 + 1;
  v3662->timer = v5715;
  int * v4695 = v3662->regs;
  int v4696 = v4695[6];
  int * v4697 = v3662->regs;
  int v5718 = v4696 << 13;
  v4697[6] = v5718;
  int v4699 = v3662->timer;
  int v5719 = v4699 + 1;
  v3662->timer = v5719;
  int * v4701 = v3662->regs;
  int v4702 = v4701[6];
  int * v4703 = v3662->regs;
  int v4704 = v4703[9];
  int * v4705 = v3662->regs;
  int v5723 = v4702 | v4704;
  v4705[6] = v5723;
  int v4707 = v3662->timer;
  int v5724 = v4707 + 1;
  v3662->timer = v5724;
  int * v4709 = v3662->regs;
  int v4710 = v4709[8];
  int * v4711 = v3662->regs;
  int v5727 = (int)((unsigned int)v4710 >> 19);
  v4711[9] = v5727;
  int v4713 = v3662->timer;
  int v5728 = v4713 + 1;
  v3662->timer = v5728;
  int * v4715 = v3662->regs;
  int v4716 = v4715[8];
  int * v4717 = v3662->regs;
  int v5731 = v4716 << 13;
  v4717[8] = v5731;
  int v4719 = v3662->timer;
  int v5732 = v4719 + 1;
  v3662->timer = v5732;
  int * v4721 = v3662->regs;
  int v4722 = v4721[8];
  int * v4723 = v3662->regs;
  int v4724 = v4723[9];
  int * v4725 = v3662->regs;
  int v5736 = v4722 | v4724;
  v4725[8] = v5736;
  int v4727 = v3662->timer;
  int v5737 = v4727 + 1;
  v3662->timer = v5737;
  int * v4729 = v3662->regs;
  int v4730 = v4729[14];
  int * v4731 = v3662->regs;
  int v4732 = v4731[11];
  int * v4733 = v3662->regs;
  int v5741 = v4730 ^ v4732;
  v4733[14] = v5741;
  int v4735 = v3662->timer;
  int v5742 = v4735 + 1;
  v3662->timer = v5742;
  int * v4737 = v3662->regs;
  int v4738 = v4737[12];
  int * v4739 = v3662->regs;
  int v4740 = v4739[15];
  int * v4741 = v3662->regs;
  int v5746 = v4738 ^ v4740;
  v4741[12] = v5746;
  int v4743 = v3662->timer;
  int v5747 = v4743 + 1;
  v3662->timer = v5747;
  int * v4745 = v3662->regs;
  int v4746 = v4745[13];
  int * v4747 = v3662->regs;
  int v4748 = v4747[6];
  int * v4749 = v3662->regs;
  int v5751 = v4746 ^ v4748;
  v4749[13] = v5751;
  int v4751 = v3662->timer;
  int v5752 = v4751 + 1;
  v3662->timer = v5752;
  int * v4753 = v3662->regs;
  int v4754 = v4753[1];
  int * v4755 = v3662->regs;
  int v4756 = v4755[8];
  int * v4757 = v3662->regs;
  int v5756 = v4754 ^ v4756;
  v4757[1] = v5756;
  int v4759 = v3662->timer;
  int v5757 = v4759 + 1;
  v3662->timer = v5757;
  int * v4761 = v3662->regs;
  int v4762 = v4761[14];
  int * v4763 = v3662->regs;
  int v4764 = v4763[27];
  int * v4765 = v3662->regs;
  int v5761 = v4762 + v4764;
  v4765[11] = v5761;
  int v4767 = v3662->timer;
  int v5762 = v4767 + 1;
  v3662->timer = v5762;
  int * v4769 = v3662->regs;
  int v4770 = v4769[12];
  int * v4771 = v3662->regs;
  int v4772 = v4771[25];
  int * v4773 = v3662->regs;
  int v5766 = v4770 + v4772;
  v4773[15] = v5766;
  int v4775 = v3662->timer;
  int v5767 = v4775 + 1;
  v3662->timer = v5767;
  int * v4777 = v3662->regs;
  int v4778 = v4777[13];
  int * v4779 = v3662->regs;
  int v4780 = v4779[26];
  int * v4781 = v3662->regs;
  int v5771 = v4778 + v4780;
  v4781[6] = v5771;
  int v4783 = v3662->timer;
  int v5772 = v4783 + 1;
  v3662->timer = v5772;
  int * v4785 = v3662->regs;
  int v4786 = v4785[1];
  int * v4787 = v3662->regs;
  int v4788 = v4787[24];
  int * v4789 = v3662->regs;
  int v5776 = v4786 + v4788;
  v4789[8] = v5776;
  int v4791 = v3662->timer;
  int v5777 = v4791 + 1;
  v3662->timer = v5777;
  int * v4793 = v3662->regs;
  int v4794 = v4793[11];
  int * v4795 = v3662->regs;
  int v5780 = (int)((unsigned int)v4794 >> 14);
  v4795[9] = v5780;
  int v4797 = v3662->timer;
  int v5781 = v4797 + 1;
  v3662->timer = v5781;
  int * v4799 = v3662->regs;
  int v4800 = v4799[11];
  int * v4801 = v3662->regs;
  int v5784 = v4800 << 18;
  v4801[11] = v5784;
  int v4803 = v3662->timer;
  int v5785 = v4803 + 1;
  v3662->timer = v5785;
  int * v4805 = v3662->regs;
  int v4806 = v4805[11];
  int * v4807 = v3662->regs;
  int v4808 = v4807[9];
  int * v4809 = v3662->regs;
  int v5789 = v4806 | v4808;
  v4809[11] = v5789;
  int v4811 = v3662->timer;
  int v5790 = v4811 + 1;
  v3662->timer = v5790;
  int * v4813 = v3662->regs;
  int v4814 = v4813[15];
  int * v4815 = v3662->regs;
  int v5793 = (int)((unsigned int)v4814 >> 14);
  v4815[9] = v5793;
  int v4817 = v3662->timer;
  int v5794 = v4817 + 1;
  v3662->timer = v5794;
  int * v4819 = v3662->regs;
  int v4820 = v4819[15];
  int * v4821 = v3662->regs;
  int v5797 = v4820 << 18;
  v4821[15] = v5797;
  int v4823 = v3662->timer;
  int v5798 = v4823 + 1;
  v3662->timer = v5798;
  int * v4825 = v3662->regs;
  int v4826 = v4825[15];
  int * v4827 = v3662->regs;
  int v4828 = v4827[9];
  int * v4829 = v3662->regs;
  int v5802 = v4826 | v4828;
  v4829[15] = v5802;
  int v4831 = v3662->timer;
  int v5803 = v4831 + 1;
  v3662->timer = v5803;
  int * v4833 = v3662->regs;
  int v4834 = v4833[6];
  int * v4835 = v3662->regs;
  int v5806 = (int)((unsigned int)v4834 >> 14);
  v4835[9] = v5806;
  int v4837 = v3662->timer;
  int v5807 = v4837 + 1;
  v3662->timer = v5807;
  int * v4839 = v3662->regs;
  int v4840 = v4839[6];
  int * v4841 = v3662->regs;
  int v5810 = v4840 << 18;
  v4841[6] = v5810;
  int v4843 = v3662->timer;
  int v5811 = v4843 + 1;
  v3662->timer = v5811;
  int * v4845 = v3662->regs;
  int v4846 = v4845[6];
  int * v4847 = v3662->regs;
  int v4848 = v4847[9];
  int * v4849 = v3662->regs;
  int v5815 = v4846 | v4848;
  v4849[6] = v5815;
  int v4851 = v3662->timer;
  int v5816 = v4851 + 1;
  v3662->timer = v5816;
  int * v4853 = v3662->regs;
  int v4854 = v4853[8];
  int * v4855 = v3662->regs;
  int v5819 = (int)((unsigned int)v4854 >> 14);
  v4855[9] = v5819;
  int v4857 = v3662->timer;
  int v5820 = v4857 + 1;
  v3662->timer = v5820;
  int * v4859 = v3662->regs;
  int v4860 = v4859[8];
  int * v4861 = v3662->regs;
  int v5823 = v4860 << 18;
  v4861[8] = v5823;
  int v4863 = v3662->timer;
  int v5824 = v4863 + 1;
  v3662->timer = v5824;
  int * v4865 = v3662->regs;
  int v4866 = v4865[8];
  int * v4867 = v3662->regs;
  int v4868 = v4867[9];
  int * v4869 = v3662->regs;
  int v5828 = v4866 | v4868;
  v4869[8] = v5828;
  int v4871 = v3662->timer;
  int v5829 = v4871 + 1;
  v3662->timer = v5829;
  int * v4873 = v3662->regs;
  int v4874 = v4873[21];
  int * v4875 = v3662->regs;
  int v4876 = v4875[11];
  int * v4877 = v3662->regs;
  int v5833 = v4874 ^ v4876;
  v4877[21] = v5833;
  int v4879 = v3662->timer;
  int v5834 = v4879 + 1;
  v3662->timer = v5834;
  int * v4881 = v3662->regs;
  int v4882 = v4881[20];
  int * v4883 = v3662->regs;
  int v4884 = v4883[15];
  int * v4885 = v3662->regs;
  int v5838 = v4882 ^ v4884;
  v4885[11] = v5838;
  int v4887 = v3662->timer;
  int v5839 = v4887 + 1;
  v3662->timer = v5839;
  int * v4889 = v3662->regs;
  int v4890 = v4889[19];
  int * v4891 = v3662->regs;
  int v4892 = v4891[6];
  int * v4893 = v3662->regs;
  int v5843 = v4890 ^ v4892;
  v4893[19] = v5843;
  int v4895 = v3662->timer;
  int v5844 = v4895 + 1;
  v3662->timer = v5844;
  int * v4897 = v3662->regs;
  int v4898 = v4897[22];
  int * v4899 = v3662->regs;
  int v4900 = v4899[8];
  int * v4901 = v3662->regs;
  int v5848 = v4898 ^ v4900;
  v4901[22] = v5848;
  int * v4903 = v3662->saved_regs;
  int * v4904 = v3662->regs;
  int v4905 = v4904[30];
  v4903[30] = v4905;
  int v4907 = v3662->timer;
  int v5853 = v4907 + 1;
  v3662->timer = v5853;
  int * v4909 = v3662->regs;
  int v4910 = v4909[30];
  int * v4911 = v3662->regs;
  int v5856 = v4910 + 1;
  v4911[30] = v5856;
  int * v4913 = v3662->regs;
  int v4914 = v4913[31];
  bool v5859 = (v4914 ^ -2147483648) < -2147483648;
  struct StateT * v5023;
  if (v5859) {
    int v4915 = v3662->timer;
    int v5860 = v4915 + 15;
    v3662->timer = v5860;
    int * v4917 = v3662->saved_regs;
    int v4918 = v4917[15];
    int * v4919 = v3662->regs;
    v4919[15] = v4918;
    int * v4921 = v3662->saved_regs;
    int v4922 = v4921[20];
    int * v4923 = v3662->regs;
    v4923[20] = v4922;
    int * v4925 = v3662->saved_regs;
    int v4926 = v4925[18];
    int * v4927 = v3662->regs;
    v4927[18] = v4926;
    int * v4929 = v3662->saved_regs;
    int v4930 = v4929[8];
    int * v4931 = v3662->regs;
    v4931[8] = v4930;
    int * v4933 = v3662->saved_regs;
    int v4934 = v4933[9];
    int * v4935 = v3662->regs;
    v4935[9] = v4934;
    int * v4937 = v3662->saved_regs;
    int v4938 = v4937[12];
    int * v4939 = v3662->regs;
    v4939[12] = v4938;
    int * v4941 = v3662->saved_regs;
    int v4942 = v4941[13];
    int * v4943 = v3662->regs;
    v4943[13] = v4942;
    int * v4945 = v3662->saved_regs;
    int v4946 = v4945[1];
    int * v4947 = v3662->regs;
    v4947[1] = v4946;
    int * v4949 = v3662->saved_regs;
    int v4950 = v4949[14];
    int * v4951 = v3662->regs;
    v4951[14] = v4950;
    int * v4953 = v3662->saved_regs;
    int v4954 = v4953[26];
    int * v4955 = v3662->regs;
    v4955[26] = v4954;
    int * v4957 = v3662->saved_regs;
    int v4958 = v4957[24];
    int * v4959 = v3662->regs;
    v4959[24] = v4958;
    int * v4961 = v3662->saved_regs;
    int v4962 = v4961[27];
    int * v4963 = v3662->regs;
    v4963[27] = v4962;
    int * v4965 = v3662->saved_regs;
    int v4966 = v4965[25];
    int * v4967 = v3662->regs;
    v4967[25] = v4966;
    int * v4969 = v3662->saved_regs;
    int v4970 = v4969[6];
    int * v4971 = v3662->regs;
    v4971[6] = v4970;
    int * v4973 = v3662->saved_regs;
    int v4974 = v4973[23];
    int * v4975 = v3662->regs;
    v4975[23] = v4974;
    int * v4977 = v3662->saved_regs;
    int v4978 = v4977[16];
    int * v4979 = v3662->regs;
    v4979[16] = v4978;
    int * v4981 = v3662->saved_regs;
    int v4982 = v4981[17];
    int * v4983 = v3662->regs;
    v4983[17] = v4982;
    int * v4985 = v3662->saved_regs;
    int v4986 = v4985[5];
    int * v4987 = v3662->regs;
    v4987[5] = v4986;
    int * v4989 = v3662->saved_regs;
    int v4990 = v4989[21];
    int * v4991 = v3662->regs;
    v4991[21] = v4990;
    int * v4993 = v3662->saved_regs;
    int v4994 = v4993[19];
    int * v4995 = v3662->regs;
    v4995[19] = v4994;
    int * v4997 = v3662->saved_regs;
    int v4998 = v4997[22];
    int * v4999 = v3662->regs;
    v4999[22] = v4998;
    int * v5001 = v3662->saved_regs;
    int v5002 = v5001[11];
    int * v5003 = v3662->regs;
    v5003[11] = v5002;
    int * v5005 = v3662->saved_regs;
    int v5006 = v5005[30];
    int * v5007 = v3662->regs;
    v5007[30] = v5006;
    struct StateT * v5009 = slot_213(v3662);
    v5023 = v5009;
  } else {
    int v5011 = v3662->timer;
    int v5932 = v5011 + 1;
    v3662->timer = v5932;
    int * v5013 = v3662->regs;
    int v5014 = v5013[31];
    int * v5015 = v3662->regs;
    int v5016 = v5015[30];
    bool v5935 = (v5014 ^ -2147483648) >= (v5016 ^ -2147483648);
    struct StateT * v5021;
    if (v5935) {
      struct StateT * v5017 = slot_51(v3662);
      v5021 = v5017;
    } else {
      struct StateT * v5019 = slot_213(v3662);
      v5021 = v5019;
    }
    v5023 = v5021;
  }
  return v5023;
}

struct StateT * slot_37(struct StateT * v2794) {
  int v2795 = v2794->timer;
  int v2849 = v2795 + 1;
  v2794->timer = v2849;
  int * v2797 = v2794->regs;
  int v2798 = v2797[2];
  int * v2799 = v2794->regs;
  int v2800 = v2799[25];
  int * v2801 = v2794->cache_keys;
  int v2802 = v2801[0];
  bool v2856 = v2802 == ((int)((unsigned int)(v2798 + 16) >> 2));
  int v2846;
  if (v2856) {
    int * v2803 = v2794->cache_vals;
    v2803[0] = v2800;
    v2846 = v2800;
  } else {
    int * v2806 = v2794->cache_keys;
    int v2807 = v2806[1];
    bool v2861 = v2807 == ((int)((unsigned int)(v2798 + 16) >> 2));
    int v2844;
    if (v2861) {
      int * v2808 = v2794->cache_keys;
      int * v2809 = v2794->cache_keys;
      int v2810 = v2809[0];
      v2808[1] = v2810;
      int * v2812 = v2794->cache_vals;
      int * v2813 = v2794->cache_vals;
      int v2814 = v2813[0];
      v2812[1] = v2814;
      int * v2816 = v2794->cache_keys;
      int v2869 = (int)((unsigned int)(v2798 + 16) >> 2);
      v2816[0] = v2869;
      int * v2818 = v2794->cache_vals;
      v2818[0] = v2800;
      int v2820 = v2794->timer;
      int v2872 = v2820 + 1;
      v2794->timer = v2872;
      v2844 = v2800;
    } else {
      int * v2823 = v2794->mem;
      int * v2824 = v2794->cache_keys;
      int v2825 = v2824[1];
      int * v2826 = v2794->cache_vals;
      int v2827 = v2826[1];
      v2823[v2825] = v2827;
      int * v2829 = v2794->cache_keys;
      int * v2830 = v2794->cache_keys;
      int v2831 = v2830[0];
      v2829[1] = v2831;
      int * v2833 = v2794->cache_vals;
      int * v2834 = v2794->cache_vals;
      int v2835 = v2834[0];
      v2833[1] = v2835;
      int * v2837 = v2794->cache_keys;
      int v2885 = (int)((unsigned int)(v2798 + 16) >> 2);
      v2837[0] = v2885;
      int * v2839 = v2794->cache_vals;
      v2839[0] = v2800;
      int v2841 = v2794->timer;
      int v2888 = v2841 + 100;
      v2794->timer = v2888;
      v2844 = v2800;
    }
    v2846 = v2844;
  }
  struct StateT * v2847 = slot_38(v2794);
  return v2847;
}

struct StateT * slot_114(struct StateT * v11471) {
  int v11472 = v11471->timer;
  int v11482 = v11472 + 1;
  v11471->timer = v11482;
  int * v11474 = v11471->regs;
  int v11475 = v11474[8];
  int * v11476 = v11471->regs;
  int v11477 = v11476[25];
  int * v11478 = v11471->regs;
  int v11489 = v11475 + v11477;
  v11478[5] = v11489;
  struct StateT * v11480 = slot_115(v11471);
  return v11480;
}

struct StateT * slot_135(struct StateT * v11869) {
  int v11870 = v11869->timer;
  int v11878 = v11870 + 1;
  v11869->timer = v11878;
  int * v11872 = v11869->regs;
  int v11873 = v11872[15];
  int * v11874 = v11869->regs;
  int v11883 = (int)((unsigned int)v11873 >> 25);
  v11874[5] = v11883;
  struct StateT * v11876 = slot_136(v11869);
  return v11876;
}

struct StateT * slot_248(struct StateT * v8171) {
  int v8172 = v8171->timer;
  int v8226 = v8172 + 1;
  v8171->timer = v8226;
  int * v8174 = v8171->regs;
  int v8175 = v8174[10];
  int * v8176 = v8171->regs;
  int v8177 = v8176[28];
  int * v8178 = v8171->cache_keys;
  int v8179 = v8178[0];
  bool v8233 = v8179 == ((int)((unsigned int)(v8175 + 8) >> 2));
  int v8223;
  if (v8233) {
    int * v8180 = v8171->cache_vals;
    v8180[0] = v8177;
    v8223 = v8177;
  } else {
    int * v8183 = v8171->cache_keys;
    int v8184 = v8183[1];
    bool v8238 = v8184 == ((int)((unsigned int)(v8175 + 8) >> 2));
    int v8221;
    if (v8238) {
      int * v8185 = v8171->cache_keys;
      int * v8186 = v8171->cache_keys;
      int v8187 = v8186[0];
      v8185[1] = v8187;
      int * v8189 = v8171->cache_vals;
      int * v8190 = v8171->cache_vals;
      int v8191 = v8190[0];
      v8189[1] = v8191;
      int * v8193 = v8171->cache_keys;
      int v8246 = (int)((unsigned int)(v8175 + 8) >> 2);
      v8193[0] = v8246;
      int * v8195 = v8171->cache_vals;
      v8195[0] = v8177;
      int v8197 = v8171->timer;
      int v8249 = v8197 + 1;
      v8171->timer = v8249;
      v8221 = v8177;
    } else {
      int * v8200 = v8171->mem;
      int * v8201 = v8171->cache_keys;
      int v8202 = v8201[1];
      int * v8203 = v8171->cache_vals;
      int v8204 = v8203[1];
      v8200[v8202] = v8204;
      int * v8206 = v8171->cache_keys;
      int * v8207 = v8171->cache_keys;
      int v8208 = v8207[0];
      v8206[1] = v8208;
      int * v8210 = v8171->cache_vals;
      int * v8211 = v8171->cache_vals;
      int v8212 = v8211[0];
      v8210[1] = v8212;
      int * v8214 = v8171->cache_keys;
      int v8262 = (int)((unsigned int)(v8175 + 8) >> 2);
      v8214[0] = v8262;
      int * v8216 = v8171->cache_vals;
      v8216[0] = v8177;
      int v8218 = v8171->timer;
      int v8265 = v8218 + 100;
      v8171->timer = v8265;
      v8221 = v8177;
    }
    v8223 = v8221;
  }
  struct StateT * v8224 = slot_249(v8171);
  return v8224;
}

struct StateT * slot_257(struct StateT * v9237) {
  int v9238 = v9237->timer;
  int v9292 = v9238 + 1;
  v9237->timer = v9292;
  int * v9240 = v9237->regs;
  int v9241 = v9240[10];
  int * v9242 = v9237->regs;
  int v9243 = v9242[17];
  int * v9244 = v9237->cache_keys;
  int v9245 = v9244[0];
  bool v9299 = v9245 == ((int)((unsigned int)(v9241 + 44) >> 2));
  int v9289;
  if (v9299) {
    int * v9246 = v9237->cache_vals;
    v9246[0] = v9243;
    v9289 = v9243;
  } else {
    int * v9249 = v9237->cache_keys;
    int v9250 = v9249[1];
    bool v9304 = v9250 == ((int)((unsigned int)(v9241 + 44) >> 2));
    int v9287;
    if (v9304) {
      int * v9251 = v9237->cache_keys;
      int * v9252 = v9237->cache_keys;
      int v9253 = v9252[0];
      v9251[1] = v9253;
      int * v9255 = v9237->cache_vals;
      int * v9256 = v9237->cache_vals;
      int v9257 = v9256[0];
      v9255[1] = v9257;
      int * v9259 = v9237->cache_keys;
      int v9312 = (int)((unsigned int)(v9241 + 44) >> 2);
      v9259[0] = v9312;
      int * v9261 = v9237->cache_vals;
      v9261[0] = v9243;
      int v9263 = v9237->timer;
      int v9315 = v9263 + 1;
      v9237->timer = v9315;
      v9287 = v9243;
    } else {
      int * v9266 = v9237->mem;
      int * v9267 = v9237->cache_keys;
      int v9268 = v9267[1];
      int * v9269 = v9237->cache_vals;
      int v9270 = v9269[1];
      v9266[v9268] = v9270;
      int * v9272 = v9237->cache_keys;
      int * v9273 = v9237->cache_keys;
      int v9274 = v9273[0];
      v9272[1] = v9274;
      int * v9276 = v9237->cache_vals;
      int * v9277 = v9237->cache_vals;
      int v9278 = v9277[0];
      v9276[1] = v9278;
      int * v9280 = v9237->cache_keys;
      int v9328 = (int)((unsigned int)(v9241 + 44) >> 2);
      v9280[0] = v9328;
      int * v9282 = v9237->cache_vals;
      v9282[0] = v9243;
      int v9284 = v9237->timer;
      int v9331 = v9284 + 100;
      v9237->timer = v9331;
      v9287 = v9243;
    }
    v9289 = v9287;
  }
  struct StateT * v9290 = slot_258(v9237);
  return v9290;
}

struct StateT * slot_59(struct StateT * v6432) {
  int v6433 = v6432->timer;
  int v6441 = v6433 + 1;
  v6432->timer = v6441;
  int * v6435 = v6432->regs;
  int v6436 = v6435[20];
  int * v6437 = v6432->regs;
  int v6445 = v6436 << 7;
  v6437[20] = v6445;
  struct StateT * v6439 = slot_60(v6432);
  return v6439;
}

struct StateT * slot_192(struct StateT * v12938) {
  int v12939 = v12938->timer;
  int v12949 = v12939 + 1;
  v12938->timer = v12949;
  int * v12941 = v12938->regs;
  int v12942 = v12941[12];
  int * v12943 = v12938->regs;
  int v12944 = v12943[25];
  int * v12945 = v12938->regs;
  int v12956 = v12942 + v12944;
  v12945[15] = v12956;
  struct StateT * v12947 = slot_193(v12938);
  return v12947;
}

struct StateT * slot_40(struct StateT * v3087) {
  int v3088 = v3087->timer;
  int v3142 = v3088 + 1;
  v3087->timer = v3142;
  int * v3090 = v3087->regs;
  int v3091 = v3090[2];
  int * v3092 = v3087->regs;
  int v3093 = v3092[24];
  int * v3094 = v3087->cache_keys;
  int v3095 = v3094[0];
  bool v3149 = v3095 == ((int)((unsigned int)(v3091 + 36) >> 2));
  int v3139;
  if (v3149) {
    int * v3096 = v3087->cache_vals;
    v3096[0] = v3093;
    v3139 = v3093;
  } else {
    int * v3099 = v3087->cache_keys;
    int v3100 = v3099[1];
    bool v3154 = v3100 == ((int)((unsigned int)(v3091 + 36) >> 2));
    int v3137;
    if (v3154) {
      int * v3101 = v3087->cache_keys;
      int * v3102 = v3087->cache_keys;
      int v3103 = v3102[0];
      v3101[1] = v3103;
      int * v3105 = v3087->cache_vals;
      int * v3106 = v3087->cache_vals;
      int v3107 = v3106[0];
      v3105[1] = v3107;
      int * v3109 = v3087->cache_keys;
      int v3162 = (int)((unsigned int)(v3091 + 36) >> 2);
      v3109[0] = v3162;
      int * v3111 = v3087->cache_vals;
      v3111[0] = v3093;
      int v3113 = v3087->timer;
      int v3165 = v3113 + 1;
      v3087->timer = v3165;
      v3137 = v3093;
    } else {
      int * v3116 = v3087->mem;
      int * v3117 = v3087->cache_keys;
      int v3118 = v3117[1];
      int * v3119 = v3087->cache_vals;
      int v3120 = v3119[1];
      v3116[v3118] = v3120;
      int * v3122 = v3087->cache_keys;
      int * v3123 = v3087->cache_keys;
      int v3124 = v3123[0];
      v3122[1] = v3124;
      int * v3126 = v3087->cache_vals;
      int * v3127 = v3087->cache_vals;
      int v3128 = v3127[0];
      v3126[1] = v3128;
      int * v3130 = v3087->cache_keys;
      int v3178 = (int)((unsigned int)(v3091 + 36) >> 2);
      v3130[0] = v3178;
      int * v3132 = v3087->cache_vals;
      v3132[0] = v3093;
      int v3134 = v3087->timer;
      int v3181 = v3134 + 100;
      v3087->timer = v3181;
      v3137 = v3093;
    }
    v3139 = v3137;
  }
  struct StateT * v3140 = slot_41(v3087);
  return v3140;
}

struct StateT * slot_48(struct StateT * v3547) {
  int v3548 = v3547->timer;
  int v3602 = v3548 + 1;
  v3547->timer = v3602;
  int * v3550 = v3547->regs;
  int v3551 = v3550[2];
  int * v3552 = v3547->regs;
  int v3553 = v3552[15];
  int * v3554 = v3547->cache_keys;
  int v3555 = v3554[0];
  bool v3609 = v3555 == ((int)((unsigned int)(v3551 + 24) >> 2));
  int v3599;
  if (v3609) {
    int * v3556 = v3547->cache_vals;
    v3556[0] = v3553;
    v3599 = v3553;
  } else {
    int * v3559 = v3547->cache_keys;
    int v3560 = v3559[1];
    bool v3614 = v3560 == ((int)((unsigned int)(v3551 + 24) >> 2));
    int v3597;
    if (v3614) {
      int * v3561 = v3547->cache_keys;
      int * v3562 = v3547->cache_keys;
      int v3563 = v3562[0];
      v3561[1] = v3563;
      int * v3565 = v3547->cache_vals;
      int * v3566 = v3547->cache_vals;
      int v3567 = v3566[0];
      v3565[1] = v3567;
      int * v3569 = v3547->cache_keys;
      int v3622 = (int)((unsigned int)(v3551 + 24) >> 2);
      v3569[0] = v3622;
      int * v3571 = v3547->cache_vals;
      v3571[0] = v3553;
      int v3573 = v3547->timer;
      int v3625 = v3573 + 1;
      v3547->timer = v3625;
      v3597 = v3553;
    } else {
      int * v3576 = v3547->mem;
      int * v3577 = v3547->cache_keys;
      int v3578 = v3577[1];
      int * v3579 = v3547->cache_vals;
      int v3580 = v3579[1];
      v3576[v3578] = v3580;
      int * v3582 = v3547->cache_keys;
      int * v3583 = v3547->cache_keys;
      int v3584 = v3583[0];
      v3582[1] = v3584;
      int * v3586 = v3547->cache_vals;
      int * v3587 = v3547->cache_vals;
      int v3588 = v3587[0];
      v3586[1] = v3588;
      int * v3590 = v3547->cache_keys;
      int v3638 = (int)((unsigned int)(v3551 + 24) >> 2);
      v3590[0] = v3638;
      int * v3592 = v3547->cache_vals;
      v3592[0] = v3553;
      int v3594 = v3547->timer;
      int v3641 = v3594 + 100;
      v3547->timer = v3641;
      v3597 = v3553;
    }
    v3599 = v3597;
  }
  struct StateT * v3600 = slot_49(v3547);
  return v3600;
}

struct StateT * slot_77(struct StateT * v7704) {
  int v7705 = v7704->timer;
  int v7715 = v7705 + 1;
  v7704->timer = v7715;
  int * v7707 = v7704->regs;
  int v7708 = v7707[15];
  int * v7709 = v7704->regs;
  int v7710 = v7709[20];
  int * v7711 = v7704->regs;
  int v7721 = v7708 | v7710;
  v7711[15] = v7721;
  struct StateT * v7713 = slot_78(v7704);
  return v7713;
}

struct StateT * slot_85(struct StateT * v8155) {
  int v8156 = v8155->timer;
  int v8164 = v8156 + 1;
  v8155->timer = v8164;
  int * v8158 = v8155->regs;
  int v8159 = v8158[18];
  int * v8160 = v8155->regs;
  int v8168 = v8159 << 9;
  v8160[18] = v8168;
  struct StateT * v8162 = slot_86(v8155);
  return v8162;
}

struct StateT * slot_75(struct StateT * v7639) {
  int v7640 = v7639->timer;
  int v7648 = v7640 + 1;
  v7639->timer = v7648;
  int * v7642 = v7639->regs;
  int v7643 = v7642[15];
  int * v7644 = v7639->regs;
  int v7653 = (int)((unsigned int)v7643 >> 23);
  v7644[20] = v7653;
  struct StateT * v7646 = slot_76(v7639);
  return v7646;
}

struct StateT * slot_72(struct StateT * v7438) {
  int v7439 = v7438->timer;
  int v7449 = v7439 + 1;
  v7438->timer = v7449;
  int * v7441 = v7438->regs;
  int v7442 = v7441[13];
  int * v7443 = v7438->regs;
  int v7444 = v7443[11];
  int * v7445 = v7438->regs;
  int v7456 = v7442 + v7444;
  v7445[8] = v7456;
  struct StateT * v7447 = slot_73(v7438);
  return v7447;
}

struct StateT * slot_119(struct StateT * v11562) {
  int v11563 = v11562->timer;
  int v11571 = v11563 + 1;
  v11562->timer = v11571;
  int * v11565 = v11562->regs;
  int v11566 = v11565[16];
  int * v11567 = v11562->regs;
  int v11575 = v11566 << 18;
  v11567[16] = v11575;
  struct StateT * v11569 = slot_120(v11562);
  return v11569;
}

struct StateT * slot_71(struct StateT * v7397) {
  int v7398 = v7397->timer;
  int v7408 = v7398 + 1;
  v7397->timer = v7408;
  int * v7400 = v7397->regs;
  int v7401 = v7400[12];
  int * v7402 = v7397->regs;
  int v7403 = v7402[21];
  int * v7404 = v7397->regs;
  int v7415 = v7401 + v7403;
  v7404[15] = v7415;
  struct StateT * v7406 = slot_72(v7397);
  return v7406;
}

struct StateT * slot_101(struct StateT * v10042) {
  int v10043 = v10042->timer;
  int v10051 = v10043 + 1;
  v10042->timer = v10051;
  int * v10045 = v10042->regs;
  int v10046 = v10045[9];
  int * v10047 = v10042->regs;
  int v10056 = (int)((unsigned int)v10046 >> 19);
  v10047[20] = v10056;
  struct StateT * v10049 = slot_102(v10042);
  return v10049;
}

struct StateT * slot_276(struct StateT * v11466) {
  int v11467 = v11466->timer;
  int v11470 = v11467 + 1;
  v11466->timer = v11470;
  return v11466;
}

struct StateT * slot_108(struct StateT * v10905) {
  int v10906 = v10905->timer;
  int v10916 = v10906 + 1;
  v10905->timer = v10916;
  int * v10908 = v10905->regs;
  int v10909 = v10908[23];
  int * v10910 = v10905->regs;
  int v10911 = v10910[8];
  int * v10912 = v10905->regs;
  int v10922 = v10909 ^ v10911;
  v10912[23] = v10922;
  struct StateT * v10914 = slot_109(v10905);
  return v10914;
}

struct StateT * slot_116(struct StateT * v11509) {
  int v11510 = v11509->timer;
  int v11518 = v11510 + 1;
  v11509->timer = v11518;
  int * v11512 = v11509->regs;
  int v11513 = v11512[15];
  int * v11514 = v11509->regs;
  int v11522 = v11513 << 18;
  v11514[15] = v11522;
  struct StateT * v11516 = slot_117(v11509);
  return v11516;
}

struct StateT * slot_93(struct StateT * v9097) {
  int v9098 = v9097->timer;
  int v9108 = v9098 + 1;
  v9097->timer = v9108;
  int * v9100 = v9097->regs;
  int v9101 = v9100[27];
  int * v9102 = v9097->regs;
  int v9103 = v9102[1];
  int * v9104 = v9097->regs;
  int v9115 = v9101 + v9103;
  v9104[9] = v9115;
  struct StateT * v9106 = slot_94(v9097);
  return v9106;
}

struct StateT * slot_266(struct StateT * v10305) {
  int v10306 = v10305->timer;
  int v10364 = v10306 + 1;
  v10305->timer = v10364;
  int * v10308 = v10305->regs;
  int v10309 = v10308[2];
  int * v10310 = v10305->cache_keys;
  int v10311 = v10310[0];
  bool v10369 = v10311 == ((int)((unsigned int)(v10309 + 76) >> 2));
  int v10359;
  if (v10369) {
    int * v10312 = v10305->cache_vals;
    int v10313 = v10312[0];
    v10359 = v10313;
  } else {
    int * v10315 = v10305->cache_keys;
    int v10316 = v10315[1];
    bool v10374 = v10316 == ((int)((unsigned int)(v10309 + 76) >> 2));
    int v10357;
    if (v10374) {
      int * v10317 = v10305->cache_vals;
      int v10318 = v10317[1];
      int * v10319 = v10305->cache_keys;
      int * v10320 = v10305->cache_keys;
      int v10321 = v10320[0];
      v10319[1] = v10321;
      int * v10323 = v10305->cache_vals;
      int * v10324 = v10305->cache_vals;
      int v10325 = v10324[0];
      v10323[1] = v10325;
      int * v10327 = v10305->cache_keys;
      int v10383 = (int)((unsigned int)(v10309 + 76) >> 2);
      v10327[0] = v10383;
      int * v10329 = v10305->cache_vals;
      v10329[0] = v10318;
      int v10331 = v10305->timer;
      int v10386 = v10331 + 1;
      v10305->timer = v10386;
      v10357 = v10318;
    } else {
      int * v10334 = v10305->mem;
      int v10388 = (int)((unsigned int)(v10309 + 76) >> 2);
      int v10335 = v10334[v10388];
      int * v10336 = v10305->mem;
      int * v10337 = v10305->cache_keys;
      int v10338 = v10337[1];
      int * v10339 = v10305->cache_vals;
      int v10340 = v10339[1];
      v10336[v10338] = v10340;
      int * v10342 = v10305->cache_keys;
      int * v10343 = v10305->cache_keys;
      int v10344 = v10343[0];
      v10342[1] = v10344;
      int * v10346 = v10305->cache_vals;
      int * v10347 = v10305->cache_vals;
      int v10348 = v10347[0];
      v10346[1] = v10348;
      int * v10350 = v10305->cache_keys;
      v10350[0] = v10388;
      int * v10352 = v10305->cache_vals;
      v10352[0] = v10335;
      int v10354 = v10305->timer;
      int v10403 = v10354 + 100;
      v10305->timer = v10403;
      v10357 = v10335;
    }
    v10359 = v10357;
  }
  int * v10360 = v10305->regs;
  v10360[19] = v10359;
  struct StateT * v10362 = slot_267(v10305);
  return v10362;
}

struct StateT * slot_88(struct StateT * v8505) {
  int v8506 = v8505->timer;
  int v8516 = v8506 + 1;
  v8505->timer = v8516;
  int * v8508 = v8505->regs;
  int v8509 = v8508[24];
  int * v8510 = v8505->regs;
  int v8511 = v8510[8];
  int * v8512 = v8505->regs;
  int v8522 = v8509 ^ v8511;
  v8512[24] = v8522;
  struct StateT * v8514 = slot_89(v8505);
  return v8514;
}

struct StateT * slot_96(struct StateT * v9450) {
  int v9451 = v9450->timer;
  int v9459 = v9451 + 1;
  v9450->timer = v9459;
  int * v9453 = v9450->regs;
  int v9454 = v9453[15];
  int * v9455 = v9450->regs;
  int v9463 = v9454 << 13;
  v9455[15] = v9463;
  struct StateT * v9457 = slot_97(v9450);
  return v9457;
}

struct StateT * slot_215(struct StateT * v6024) {
  int v6025 = v6024->timer;
  int v6031 = v6025 + 1;
  v6024->timer = v6031;
  int * v6027 = v6024->regs;
  v6027[15] = 1634762752;
  struct StateT * v6029 = slot_216(v6024);
  return v6029;
}

struct StateT * slot_234(struct StateT * v7418) {
  int v7419 = v7418->timer;
  int v7429 = v7419 + 1;
  v7418->timer = v7429;
  int * v7421 = v7418->regs;
  int v7422 = v7421[24];
  int * v7423 = v7418->regs;
  int v7424 = v7423[30];
  int * v7425 = v7418->regs;
  int v7435 = v7422 + v7424;
  v7425[24] = v7435;
  struct StateT * v7427 = slot_235(v7418);
  return v7427;
}

struct StateT * slot_45(struct StateT * v3496) {
  int v3497 = v3496->timer;
  int v3505 = v3497 + 1;
  v3496->timer = v3505;
  int * v3499 = v3496->regs;
  int v3500 = v3499[7];
  int * v3501 = v3496->regs;
  v3501[14] = v3500;
  struct StateT * v3503 = slot_46(v3496);
  return v3503;
}

struct StateT * slot_218(struct StateT * v6221) {
  int v6222 = v6221->timer;
  int v6232 = v6222 + 1;
  v6221->timer = v6232;
  int * v6224 = v6221->regs;
  int v6225 = v6224[12];
  int * v6226 = v6221->regs;
  int v6227 = v6226[6];
  int * v6228 = v6221->regs;
  int v6238 = v6225 + v6227;
  v6228[12] = v6238;
  struct StateT * v6230 = slot_219(v6221);
  return v6230;
}

struct StateT * slot_220(struct StateT * v6290) {
  int v6291 = v6290->timer;
  int v6349 = v6291 + 1;
  v6290->timer = v6349;
  int * v6293 = v6290->regs;
  int v6294 = v6293[2];
  int * v6295 = v6290->cache_keys;
  int v6296 = v6295[0];
  bool v6354 = v6296 == ((int)((unsigned int)(v6294 + 12) >> 2));
  int v6344;
  if (v6354) {
    int * v6297 = v6290->cache_vals;
    int v6298 = v6297[0];
    v6344 = v6298;
  } else {
    int * v6300 = v6290->cache_keys;
    int v6301 = v6300[1];
    bool v6359 = v6301 == ((int)((unsigned int)(v6294 + 12) >> 2));
    int v6342;
    if (v6359) {
      int * v6302 = v6290->cache_vals;
      int v6303 = v6302[1];
      int * v6304 = v6290->cache_keys;
      int * v6305 = v6290->cache_keys;
      int v6306 = v6305[0];
      v6304[1] = v6306;
      int * v6308 = v6290->cache_vals;
      int * v6309 = v6290->cache_vals;
      int v6310 = v6309[0];
      v6308[1] = v6310;
      int * v6312 = v6290->cache_keys;
      int v6368 = (int)((unsigned int)(v6294 + 12) >> 2);
      v6312[0] = v6368;
      int * v6314 = v6290->cache_vals;
      v6314[0] = v6303;
      int v6316 = v6290->timer;
      int v6371 = v6316 + 1;
      v6290->timer = v6371;
      v6342 = v6303;
    } else {
      int * v6319 = v6290->mem;
      int v6373 = (int)((unsigned int)(v6294 + 12) >> 2);
      int v6320 = v6319[v6373];
      int * v6321 = v6290->mem;
      int * v6322 = v6290->cache_keys;
      int v6323 = v6322[1];
      int * v6324 = v6290->cache_vals;
      int v6325 = v6324[1];
      v6321[v6323] = v6325;
      int * v6327 = v6290->cache_keys;
      int * v6328 = v6290->cache_keys;
      int v6329 = v6328[0];
      v6327[1] = v6329;
      int * v6331 = v6290->cache_vals;
      int * v6332 = v6290->cache_vals;
      int v6333 = v6332[0];
      v6331[1] = v6333;
      int * v6335 = v6290->cache_keys;
      v6335[0] = v6373;
      int * v6337 = v6290->cache_vals;
      v6337[0] = v6320;
      int v6339 = v6290->timer;
      int v6388 = v6339 + 100;
      v6290->timer = v6388;
      v6342 = v6320;
    }
    v6344 = v6342;
  }
  int * v6345 = v6290->regs;
  v6345[7] = v6344;
  struct StateT * v6347 = slot_221(v6290);
  return v6347;
}

struct StateT * slot_134(struct StateT * v11848) {
  int v11849 = v11848->timer;
  int v11859 = v11849 + 1;
  v11848->timer = v11859;
  int * v11851 = v11848->regs;
  int v11852 = v11851[22];
  int * v11853 = v11848->regs;
  int v11854 = v11853[1];
  int * v11855 = v11848->regs;
  int v11866 = v11852 + v11854;
  v11855[17] = v11866;
  struct StateT * v11857 = slot_135(v11848);
  return v11857;
}

struct StateT * slot_175(struct StateT * v12625) {
  int v12626 = v12625->timer;
  int v12634 = v12626 + 1;
  v12625->timer = v12634;
  int * v12628 = v12625->regs;
  int v12629 = v12628[11];
  int * v12630 = v12625->regs;
  int v12639 = (int)((unsigned int)v12629 >> 19);
  v12630[9] = v12639;
  struct StateT * v12632 = slot_176(v12625);
  return v12632;
}

struct StateT * slot_273(struct StateT * v11177) {
  int v11178 = v11177->timer;
  int v11236 = v11178 + 1;
  v11177->timer = v11236;
  int * v11180 = v11177->regs;
  int v11181 = v11180[2];
  int * v11182 = v11177->cache_keys;
  int v11183 = v11182[0];
  bool v11241 = v11183 == ((int)((unsigned int)(v11181 + 48) >> 2));
  int v11231;
  if (v11241) {
    int * v11184 = v11177->cache_vals;
    int v11185 = v11184[0];
    v11231 = v11185;
  } else {
    int * v11187 = v11177->cache_keys;
    int v11188 = v11187[1];
    bool v11246 = v11188 == ((int)((unsigned int)(v11181 + 48) >> 2));
    int v11229;
    if (v11246) {
      int * v11189 = v11177->cache_vals;
      int v11190 = v11189[1];
      int * v11191 = v11177->cache_keys;
      int * v11192 = v11177->cache_keys;
      int v11193 = v11192[0];
      v11191[1] = v11193;
      int * v11195 = v11177->cache_vals;
      int * v11196 = v11177->cache_vals;
      int v11197 = v11196[0];
      v11195[1] = v11197;
      int * v11199 = v11177->cache_keys;
      int v11255 = (int)((unsigned int)(v11181 + 48) >> 2);
      v11199[0] = v11255;
      int * v11201 = v11177->cache_vals;
      v11201[0] = v11190;
      int v11203 = v11177->timer;
      int v11258 = v11203 + 1;
      v11177->timer = v11258;
      v11229 = v11190;
    } else {
      int * v11206 = v11177->mem;
      int v11260 = (int)((unsigned int)(v11181 + 48) >> 2);
      int v11207 = v11206[v11260];
      int * v11208 = v11177->mem;
      int * v11209 = v11177->cache_keys;
      int v11210 = v11209[1];
      int * v11211 = v11177->cache_vals;
      int v11212 = v11211[1];
      v11208[v11210] = v11212;
      int * v11214 = v11177->cache_keys;
      int * v11215 = v11177->cache_keys;
      int v11216 = v11215[0];
      v11214[1] = v11216;
      int * v11218 = v11177->cache_vals;
      int * v11219 = v11177->cache_vals;
      int v11220 = v11219[0];
      v11218[1] = v11220;
      int * v11222 = v11177->cache_keys;
      v11222[0] = v11260;
      int * v11224 = v11177->cache_vals;
      v11224[0] = v11207;
      int v11226 = v11177->timer;
      int v11275 = v11226 + 100;
      v11177->timer = v11275;
      v11229 = v11207;
    }
    v11231 = v11229;
  }
  int * v11232 = v11177->regs;
  v11232[26] = v11231;
  struct StateT * v11234 = slot_274(v11177);
  return v11234;
}

struct StateT * slot_69(struct StateT * v7232) {
  int v7233 = v7232->timer;
  int v7243 = v7233 + 1;
  v7232->timer = v7243;
  int * v7235 = v7232->regs;
  int v7236 = v7235[1];
  int * v7237 = v7232->regs;
  int v7238 = v7237[18];
  int * v7239 = v7232->regs;
  int v7249 = v7236 ^ v7238;
  v7239[1] = v7249;
  struct StateT * v7241 = slot_70(v7232);
  return v7241;
}

struct StateT * slot_202(struct StateT * v13124) {
  int v13125 = v13124->timer;
  int v13133 = v13125 + 1;
  v13124->timer = v13133;
  int * v13127 = v13124->regs;
  int v13128 = v13127[6];
  int * v13129 = v13124->regs;
  int v13137 = v13128 << 18;
  v13129[6] = v13137;
  struct StateT * v13131 = slot_203(v13124);
  return v13131;
}

struct StateT * slot_230(struct StateT * v7087) {
  int v7088 = v7087->timer;
  int v7098 = v7088 + 1;
  v7087->timer = v7098;
  int * v7090 = v7087->regs;
  int v7091 = v7090[17];
  int * v7092 = v7087->regs;
  int v7093 = v7092[30];
  int * v7094 = v7087->regs;
  int v7104 = v7091 + v7093;
  v7094[17] = v7104;
  struct StateT * v7096 = slot_231(v7087);
  return v7096;
}

struct StateT * slot_188(struct StateT * v12857) {
  int v12858 = v12857->timer;
  int v12868 = v12858 + 1;
  v12857->timer = v12868;
  int * v12860 = v12857->regs;
  int v12861 = v12860[12];
  int * v12862 = v12857->regs;
  int v12863 = v12862[15];
  int * v12864 = v12857->regs;
  int v12874 = v12861 ^ v12863;
  v12864[12] = v12874;
  struct StateT * v12866 = slot_189(v12857);
  return v12866;
}

struct StateT * slot_138(struct StateT * v11922) {
  int v11923 = v11922->timer;
  int v11931 = v11923 + 1;
  v11922->timer = v11931;
  int * v11925 = v11922->regs;
  int v11926 = v11925[11];
  int * v11927 = v11922->regs;
  int v11936 = (int)((unsigned int)v11926 >> 25);
  v11927[5] = v11936;
  struct StateT * v11929 = slot_139(v11922);
  return v11929;
}

struct StateT * slot_186(struct StateT * v12817) {
  int v12818 = v12817->timer;
  int v12828 = v12818 + 1;
  v12817->timer = v12828;
  int * v12820 = v12817->regs;
  int v12821 = v12820[8];
  int * v12822 = v12817->regs;
  int v12823 = v12822[9];
  int * v12824 = v12817->regs;
  int v12834 = v12821 | v12823;
  v12824[8] = v12834;
  struct StateT * v12826 = slot_187(v12817);
  return v12826;
}

struct StateT * slot_102(struct StateT * v10164) {
  int v10165 = v10164->timer;
  int v10173 = v10165 + 1;
  v10164->timer = v10173;
  int * v10167 = v10164->regs;
  int v10168 = v10167[9];
  int * v10169 = v10164->regs;
  int v10177 = v10168 << 13;
  v10169[9] = v10177;
  struct StateT * v10171 = slot_103(v10164);
  return v10171;
}

struct StateT * slot_145(struct StateT * v12045) {
  int v12046 = v12045->timer;
  int v12054 = v12046 + 1;
  v12045->timer = v12054;
  int * v12048 = v12045->regs;
  int v12049 = v12048[17];
  int * v12050 = v12045->regs;
  int v12058 = v12049 << 7;
  v12050[17] = v12058;
  struct StateT * v12052 = slot_146(v12045);
  return v12052;
}

struct StateT * slot_110(struct StateT * v11156) {
  int v11157 = v11156->timer;
  int v11167 = v11157 + 1;
  v11156->timer = v11167;
  int * v11159 = v11156->regs;
  int v11160 = v11159[17];
  int * v11161 = v11156->regs;
  int v11162 = v11161[6];
  int * v11163 = v11156->regs;
  int v11174 = v11160 ^ v11162;
  v11163[8] = v11174;
  struct StateT * v11165 = slot_111(v11156);
  return v11165;
}

struct StateT * slot_196(struct StateT * v13018) {
  int v13019 = v13018->timer;
  int v13027 = v13019 + 1;
  v13018->timer = v13027;
  int * v13021 = v13018->regs;
  int v13022 = v13021[11];
  int * v13023 = v13018->regs;
  int v13031 = v13022 << 18;
  v13023[11] = v13031;
  struct StateT * v13025 = slot_197(v13018);
  return v13025;
}

struct StateT * slot_208(struct StateT * v13233) {
  int v13234 = v13233->timer;
  int v13244 = v13234 + 1;
  v13233->timer = v13244;
  int * v13236 = v13233->regs;
  int v13237 = v13236[20];
  int * v13238 = v13233->regs;
  int v13239 = v13238[15];
  int * v13240 = v13233->regs;
  int v13251 = v13237 ^ v13239;
  v13240[11] = v13251;
  struct StateT * v13242 = slot_209(v13233);
  return v13242;
}

struct StateT * slot_172(struct StateT * v12562) {
  int v12563 = v12562->timer;
  int v12573 = v12563 + 1;
  v12562->timer = v12573;
  int * v12565 = v12562->regs;
  int v12566 = v12565[25];
  int * v12567 = v12562->regs;
  int v12568 = v12567[5];
  int * v12569 = v12562->regs;
  int v12580 = v12566 + v12568;
  v12569[15] = v12580;
  struct StateT * v12571 = slot_173(v12562);
  return v12571;
}

struct StateT * slot_131(struct StateT * v11785) {
  int v11786 = v11785->timer;
  int v11796 = v11786 + 1;
  v11785->timer = v11796;
  int * v11788 = v11785->regs;
  int v11789 = v11788[21];
  int * v11790 = v11785->regs;
  int v11791 = v11790[14];
  int * v11792 = v11785->regs;
  int v11803 = v11789 + v11791;
  v11792[15] = v11803;
  struct StateT * v11794 = slot_132(v11785);
  return v11794;
}

struct StateT * slot_8(struct StateT * v703) {
  int v704 = v703->timer;
  int v758 = v704 + 1;
  v703->timer = v758;
  int * v706 = v703->regs;
  int v707 = v706[2];
  int * v708 = v703->regs;
  int v709 = v708[22];
  int * v710 = v703->cache_keys;
  int v711 = v710[0];
  bool v765 = v711 == ((int)((unsigned int)(v707 + 64) >> 2));
  int v755;
  if (v765) {
    int * v712 = v703->cache_vals;
    v712[0] = v709;
    v755 = v709;
  } else {
    int * v715 = v703->cache_keys;
    int v716 = v715[1];
    bool v770 = v716 == ((int)((unsigned int)(v707 + 64) >> 2));
    int v753;
    if (v770) {
      int * v717 = v703->cache_keys;
      int * v718 = v703->cache_keys;
      int v719 = v718[0];
      v717[1] = v719;
      int * v721 = v703->cache_vals;
      int * v722 = v703->cache_vals;
      int v723 = v722[0];
      v721[1] = v723;
      int * v725 = v703->cache_keys;
      int v778 = (int)((unsigned int)(v707 + 64) >> 2);
      v725[0] = v778;
      int * v727 = v703->cache_vals;
      v727[0] = v709;
      int v729 = v703->timer;
      int v781 = v729 + 1;
      v703->timer = v781;
      v753 = v709;
    } else {
      int * v732 = v703->mem;
      int * v733 = v703->cache_keys;
      int v734 = v733[1];
      int * v735 = v703->cache_vals;
      int v736 = v735[1];
      v732[v734] = v736;
      int * v738 = v703->cache_keys;
      int * v739 = v703->cache_keys;
      int v740 = v739[0];
      v738[1] = v740;
      int * v742 = v703->cache_vals;
      int * v743 = v703->cache_vals;
      int v744 = v743[0];
      v742[1] = v744;
      int * v746 = v703->cache_keys;
      int v794 = (int)((unsigned int)(v707 + 64) >> 2);
      v746[0] = v794;
      int * v748 = v703->cache_vals;
      v748[0] = v709;
      int v750 = v703->timer;
      int v797 = v750 + 100;
      v703->timer = v797;
      v753 = v709;
    }
    v755 = v753;
  }
  struct StateT * v756 = slot_9(v703);
  return v756;
}

struct StateT * slot_180(struct StateT * v12711) {
  int v12712 = v12711->timer;
  int v12722 = v12712 + 1;
  v12711->timer = v12722;
  int * v12714 = v12711->regs;
  int v12715 = v12714[15];
  int * v12716 = v12711->regs;
  int v12717 = v12716[9];
  int * v12718 = v12711->regs;
  int v12728 = v12715 | v12717;
  v12718[15] = v12728;
  struct StateT * v12720 = slot_181(v12711);
  return v12720;
}

struct StateT * slot_203(struct StateT * v13140) {
  int v13141 = v13140->timer;
  int v13151 = v13141 + 1;
  v13140->timer = v13151;
  int * v13143 = v13140->regs;
  int v13144 = v13143[6];
  int * v13145 = v13140->regs;
  int v13146 = v13145[9];
  int * v13147 = v13140->regs;
  int v13157 = v13144 | v13146;
  v13147[6] = v13157;
  struct StateT * v13149 = slot_204(v13140);
  return v13149;
}

struct StateT * slot_190(struct StateT * v12897) {
  int v12898 = v12897->timer;
  int v12908 = v12898 + 1;
  v12897->timer = v12908;
  int * v12900 = v12897->regs;
  int v12901 = v12900[1];
  int * v12902 = v12897->regs;
  int v12903 = v12902[8];
  int * v12904 = v12897->regs;
  int v12914 = v12901 ^ v12903;
  v12904[1] = v12914;
  struct StateT * v12906 = slot_191(v12897);
  return v12906;
}

struct StateT * slot_157(struct StateT * v12282) {
  int v12283 = v12282->timer;
  int v12293 = v12283 + 1;
  v12282->timer = v12293;
  int * v12285 = v12282->regs;
  int v12286 = v12285[11];
  int * v12287 = v12282->regs;
  int v12288 = v12287[9];
  int * v12289 = v12282->regs;
  int v12299 = v12286 | v12288;
  v12289[11] = v12299;
  struct StateT * v12291 = slot_158(v12282);
  return v12291;
}

struct StateT * slot_242(struct StateT * v7789) {
  int v7790 = v7789->timer;
  int v7800 = v7790 + 1;
  v7789->timer = v7800;
  int * v7792 = v7789->regs;
  int v7793 = v7792[21];
  int * v7794 = v7789->regs;
  int v7795 = v7794[15];
  int * v7796 = v7789->regs;
  int v7806 = v7793 + v7795;
  v7796[15] = v7806;
  struct StateT * v7798 = slot_243(v7789);
  return v7798;
}

struct StateT * slot_200(struct StateT * v13087) {
  int v13088 = v13087->timer;
  int v13098 = v13088 + 1;
  v13087->timer = v13098;
  int * v13090 = v13087->regs;
  int v13091 = v13090[15];
  int * v13092 = v13087->regs;
  int v13093 = v13092[9];
  int * v13094 = v13087->regs;
  int v13104 = v13091 | v13093;
  v13094[15] = v13104;
  struct StateT * v13096 = slot_201(v13087);
  return v13096;
}

struct StateT * slot_243(struct StateT * v7829) {
  int v7830 = v7829->timer;
  int v7840 = v7830 + 1;
  v7829->timer = v7840;
  int * v7832 = v7829->regs;
  int v7833 = v7832[11];
  int * v7834 = v7829->regs;
  int v7835 = v7834[6];
  int * v7836 = v7829->regs;
  int v7846 = v7833 + v7835;
  v7836[11] = v7846;
  struct StateT * v7838 = slot_244(v7829);
  return v7838;
}

struct StateT * slot_173(struct StateT * v12583) {
  int v12584 = v12583->timer;
  int v12594 = v12584 + 1;
  v12583->timer = v12594;
  int * v12586 = v12583->regs;
  int v12587 = v12586[26];
  int * v12588 = v12583->regs;
  int v12589 = v12588[17];
  int * v12590 = v12583->regs;
  int v12601 = v12587 + v12589;
  v12590[6] = v12601;
  struct StateT * v12592 = slot_174(v12583);
  return v12592;
}

struct StateT * slot_149(struct StateT * v12123) {
  int v12124 = v12123->timer;
  int v12134 = v12124 + 1;
  v12123->timer = v12134;
  int * v12126 = v12123->regs;
  int v12127 = v12126[8];
  int * v12128 = v12123->regs;
  int v12129 = v12128[16];
  int * v12130 = v12123->regs;
  int v12141 = v12127 ^ v12129;
  v12130[17] = v12141;
  struct StateT * v12132 = slot_150(v12123);
  return v12132;
}

struct StateT * slot_5(struct StateT * v409) {
  int v410 = v409->timer;
  int v464 = v410 + 1;
  v409->timer = v464;
  int * v412 = v409->regs;
  int v413 = v412[2];
  int * v414 = v409->regs;
  int v415 = v414[19];
  int * v416 = v409->cache_keys;
  int v417 = v416[0];
  bool v471 = v417 == ((int)((unsigned int)(v413 + 76) >> 2));
  int v461;
  if (v471) {
    int * v418 = v409->cache_vals;
    v418[0] = v415;
    v461 = v415;
  } else {
    int * v421 = v409->cache_keys;
    int v422 = v421[1];
    bool v476 = v422 == ((int)((unsigned int)(v413 + 76) >> 2));
    int v459;
    if (v476) {
      int * v423 = v409->cache_keys;
      int * v424 = v409->cache_keys;
      int v425 = v424[0];
      v423[1] = v425;
      int * v427 = v409->cache_vals;
      int * v428 = v409->cache_vals;
      int v429 = v428[0];
      v427[1] = v429;
      int * v431 = v409->cache_keys;
      int v484 = (int)((unsigned int)(v413 + 76) >> 2);
      v431[0] = v484;
      int * v433 = v409->cache_vals;
      v433[0] = v415;
      int v435 = v409->timer;
      int v487 = v435 + 1;
      v409->timer = v487;
      v459 = v415;
    } else {
      int * v438 = v409->mem;
      int * v439 = v409->cache_keys;
      int v440 = v439[1];
      int * v441 = v409->cache_vals;
      int v442 = v441[1];
      v438[v440] = v442;
      int * v444 = v409->cache_keys;
      int * v445 = v409->cache_keys;
      int v446 = v445[0];
      v444[1] = v446;
      int * v448 = v409->cache_vals;
      int * v449 = v409->cache_vals;
      int v450 = v449[0];
      v448[1] = v450;
      int * v452 = v409->cache_keys;
      int v500 = (int)((unsigned int)(v413 + 76) >> 2);
      v452[0] = v500;
      int * v454 = v409->cache_vals;
      v454[0] = v415;
      int v456 = v409->timer;
      int v503 = v456 + 100;
      v409->timer = v503;
      v459 = v415;
    }
    v461 = v459;
  }
  struct StateT * v462 = slot_6(v409);
  return v462;
}

struct StateT * slot_104(struct StateT * v10410) {
  int v10411 = v10410->timer;
  int v10419 = v10411 + 1;
  v10410->timer = v10419;
  int * v10413 = v10410->regs;
  int v10414 = v10413[18];
  int * v10415 = v10410->regs;
  int v10424 = (int)((unsigned int)v10414 >> 19);
  v10415[9] = v10424;
  struct StateT * v10417 = slot_105(v10410);
  return v10417;
}

struct StateT * slot_235(struct StateT * v7459) {
  int v7460 = v7459->timer;
  int v7518 = v7460 + 1;
  v7459->timer = v7518;
  int * v7462 = v7459->regs;
  int v7463 = v7462[2];
  int * v7464 = v7459->cache_keys;
  int v7465 = v7464[0];
  bool v7523 = v7465 == ((int)((unsigned int)(v7463 + 40) >> 2));
  int v7513;
  if (v7523) {
    int * v7466 = v7459->cache_vals;
    int v7467 = v7466[0];
    v7513 = v7467;
  } else {
    int * v7469 = v7459->cache_keys;
    int v7470 = v7469[1];
    bool v7528 = v7470 == ((int)((unsigned int)(v7463 + 40) >> 2));
    int v7511;
    if (v7528) {
      int * v7471 = v7459->cache_vals;
      int v7472 = v7471[1];
      int * v7473 = v7459->cache_keys;
      int * v7474 = v7459->cache_keys;
      int v7475 = v7474[0];
      v7473[1] = v7475;
      int * v7477 = v7459->cache_vals;
      int * v7478 = v7459->cache_vals;
      int v7479 = v7478[0];
      v7477[1] = v7479;
      int * v7481 = v7459->cache_keys;
      int v7537 = (int)((unsigned int)(v7463 + 40) >> 2);
      v7481[0] = v7537;
      int * v7483 = v7459->cache_vals;
      v7483[0] = v7472;
      int v7485 = v7459->timer;
      int v7540 = v7485 + 1;
      v7459->timer = v7540;
      v7511 = v7472;
    } else {
      int * v7488 = v7459->mem;
      int v7542 = (int)((unsigned int)(v7463 + 40) >> 2);
      int v7489 = v7488[v7542];
      int * v7490 = v7459->mem;
      int * v7491 = v7459->cache_keys;
      int v7492 = v7491[1];
      int * v7493 = v7459->cache_vals;
      int v7494 = v7493[1];
      v7490[v7492] = v7494;
      int * v7496 = v7459->cache_keys;
      int * v7497 = v7459->cache_keys;
      int v7498 = v7497[0];
      v7496[1] = v7498;
      int * v7500 = v7459->cache_vals;
      int * v7501 = v7459->cache_vals;
      int v7502 = v7501[0];
      v7500[1] = v7502;
      int * v7504 = v7459->cache_keys;
      v7504[0] = v7542;
      int * v7506 = v7459->cache_vals;
      v7506[0] = v7489;
      int v7508 = v7459->timer;
      int v7557 = v7508 + 100;
      v7459->timer = v7557;
      v7511 = v7489;
    }
    v7513 = v7511;
  }
  int * v7514 = v7459->regs;
  v7514[30] = v7513;
  struct StateT * v7516 = slot_236(v7459);
  return v7516;
}

struct StateT * slot_275(struct StateT * v11429) {
  int v11430 = v11429->timer;
  int v11438 = v11430 + 1;
  v11429->timer = v11438;
  int * v11432 = v11429->regs;
  int v11433 = v11432[2];
  int * v11434 = v11429->regs;
  int v11442 = v11433 + 96;
  v11434[2] = v11442;
  struct StateT * v11436 = slot_276(v11429);
  return v11436;
}

struct StateT * slot_54(struct StateT * v6078) {
  int v6079 = v6078->timer;
  int v6089 = v6079 + 1;
  v6078->timer = v6089;
  int * v6081 = v6078->regs;
  int v6082 = v6081[22];
  int * v6083 = v6078->regs;
  int v6084 = v6083[17];
  int * v6085 = v6078->regs;
  int v6096 = v6082 + v6084;
  v6085[8] = v6096;
  struct StateT * v6087 = slot_55(v6078);
  return v6087;
}

struct StateT * slot_26(struct StateT * v2459) {
  int v2460 = v2459->timer;
  int v2518 = v2460 + 1;
  v2459->timer = v2518;
  int * v2462 = v2459->regs;
  int v2463 = v2462[11];
  int * v2464 = v2459->cache_keys;
  int v2465 = v2464[0];
  bool v2523 = v2465 == ((int)((unsigned int)(v2463 + 12) >> 2));
  int v2513;
  if (v2523) {
    int * v2466 = v2459->cache_vals;
    int v2467 = v2466[0];
    v2513 = v2467;
  } else {
    int * v2469 = v2459->cache_keys;
    int v2470 = v2469[1];
    bool v2528 = v2470 == ((int)((unsigned int)(v2463 + 12) >> 2));
    int v2511;
    if (v2528) {
      int * v2471 = v2459->cache_vals;
      int v2472 = v2471[1];
      int * v2473 = v2459->cache_keys;
      int * v2474 = v2459->cache_keys;
      int v2475 = v2474[0];
      v2473[1] = v2475;
      int * v2477 = v2459->cache_vals;
      int * v2478 = v2459->cache_vals;
      int v2479 = v2478[0];
      v2477[1] = v2479;
      int * v2481 = v2459->cache_keys;
      int v2537 = (int)((unsigned int)(v2463 + 12) >> 2);
      v2481[0] = v2537;
      int * v2483 = v2459->cache_vals;
      v2483[0] = v2472;
      int v2485 = v2459->timer;
      int v2540 = v2485 + 1;
      v2459->timer = v2540;
      v2511 = v2472;
    } else {
      int * v2488 = v2459->mem;
      int v2542 = (int)((unsigned int)(v2463 + 12) >> 2);
      int v2489 = v2488[v2542];
      int * v2490 = v2459->mem;
      int * v2491 = v2459->cache_keys;
      int v2492 = v2491[1];
      int * v2493 = v2459->cache_vals;
      int v2494 = v2493[1];
      v2490[v2492] = v2494;
      int * v2496 = v2459->cache_keys;
      int * v2497 = v2459->cache_keys;
      int v2498 = v2497[0];
      v2496[1] = v2498;
      int * v2500 = v2459->cache_vals;
      int * v2501 = v2459->cache_vals;
      int v2502 = v2501[0];
      v2500[1] = v2502;
      int * v2504 = v2459->cache_keys;
      v2504[0] = v2542;
      int * v2506 = v2459->cache_vals;
      v2506[0] = v2489;
      int v2508 = v2459->timer;
      int v2557 = v2508 + 100;
      v2459->timer = v2557;
      v2511 = v2489;
    }
    v2513 = v2511;
  }
  int * v2514 = v2459->regs;
  v2514[15] = v2513;
  struct StateT * v2516 = slot_27(v2459);
  return v2516;
}

struct StateT * slot_206(struct StateT * v13193) {
  int v13194 = v13193->timer;
  int v13204 = v13194 + 1;
  v13193->timer = v13204;
  int * v13196 = v13193->regs;
  int v13197 = v13196[8];
  int * v13198 = v13193->regs;
  int v13199 = v13198[9];
  int * v13200 = v13193->regs;
  int v13210 = v13197 | v13199;
  v13200[8] = v13210;
  struct StateT * v13202 = slot_207(v13193);
  return v13202;
}

struct StateT * slot_227(struct StateT * v6893) {
  int v6894 = v6893->timer;
  int v6904 = v6894 + 1;
  v6893->timer = v6904;
  int * v6896 = v6893->regs;
  int v6897 = v6896[13];
  int * v6898 = v6893->regs;
  int v6899 = v6898[7];
  int * v6900 = v6893->regs;
  int v6910 = v6897 + v6899;
  v6900[13] = v6910;
  struct StateT * v6902 = slot_228(v6893);
  return v6902;
}

struct StateT * slot_169(struct StateT * v12501) {
  int v12502 = v12501->timer;
  int v12512 = v12502 + 1;
  v12501->timer = v12512;
  int * v12504 = v12501->regs;
  int v12505 = v12504[26];
  int * v12506 = v12501->regs;
  int v12507 = v12506[6];
  int * v12508 = v12501->regs;
  int v12518 = v12505 ^ v12507;
  v12508[26] = v12518;
  struct StateT * v12510 = slot_170(v12501);
  return v12510;
}

struct StateT * slot_253(struct StateT * v8761) {
  int v8762 = v8761->timer;
  int v8816 = v8762 + 1;
  v8761->timer = v8816;
  int * v8764 = v8761->regs;
  int v8765 = v8764[10];
  int * v8766 = v8761->regs;
  int v8767 = v8766[25];
  int * v8768 = v8761->cache_keys;
  int v8769 = v8768[0];
  bool v8823 = v8769 == ((int)((unsigned int)(v8765 + 28) >> 2));
  int v8813;
  if (v8823) {
    int * v8770 = v8761->cache_vals;
    v8770[0] = v8767;
    v8813 = v8767;
  } else {
    int * v8773 = v8761->cache_keys;
    int v8774 = v8773[1];
    bool v8828 = v8774 == ((int)((unsigned int)(v8765 + 28) >> 2));
    int v8811;
    if (v8828) {
      int * v8775 = v8761->cache_keys;
      int * v8776 = v8761->cache_keys;
      int v8777 = v8776[0];
      v8775[1] = v8777;
      int * v8779 = v8761->cache_vals;
      int * v8780 = v8761->cache_vals;
      int v8781 = v8780[0];
      v8779[1] = v8781;
      int * v8783 = v8761->cache_keys;
      int v8836 = (int)((unsigned int)(v8765 + 28) >> 2);
      v8783[0] = v8836;
      int * v8785 = v8761->cache_vals;
      v8785[0] = v8767;
      int v8787 = v8761->timer;
      int v8839 = v8787 + 1;
      v8761->timer = v8839;
      v8811 = v8767;
    } else {
      int * v8790 = v8761->mem;
      int * v8791 = v8761->cache_keys;
      int v8792 = v8791[1];
      int * v8793 = v8761->cache_vals;
      int v8794 = v8793[1];
      v8790[v8792] = v8794;
      int * v8796 = v8761->cache_keys;
      int * v8797 = v8761->cache_keys;
      int v8798 = v8797[0];
      v8796[1] = v8798;
      int * v8800 = v8761->cache_vals;
      int * v8801 = v8761->cache_vals;
      int v8802 = v8801[0];
      v8800[1] = v8802;
      int * v8804 = v8761->cache_keys;
      int v8852 = (int)((unsigned int)(v8765 + 28) >> 2);
      v8804[0] = v8852;
      int * v8806 = v8761->cache_vals;
      v8806[0] = v8767;
      int v8808 = v8761->timer;
      int v8855 = v8808 + 100;
      v8761->timer = v8855;
      v8811 = v8767;
    }
    v8813 = v8811;
  }
  struct StateT * v8814 = slot_254(v8761);
  return v8814;
}

struct StateT * slot_64(struct StateT * v6876) {
  int v6877 = v6876->timer;
  int v6885 = v6877 + 1;
  v6876->timer = v6885;
  int * v6879 = v6876->regs;
  int v6880 = v6879[8];
  int * v6881 = v6876->regs;
  int v6890 = (int)((unsigned int)v6880 >> 25);
  v6881[20] = v6890;
  struct StateT * v6883 = slot_65(v6876);
  return v6883;
}

struct StateT * slot_170(struct StateT * v12521) {
  int v12522 = v12521->timer;
  int v12532 = v12522 + 1;
  v12521->timer = v12532;
  int * v12524 = v12521->regs;
  int v12525 = v12524[24];
  int * v12526 = v12521->regs;
  int v12527 = v12526[8];
  int * v12528 = v12521->regs;
  int v12538 = v12525 ^ v12527;
  v12528[24] = v12538;
  struct StateT * v12530 = slot_171(v12521);
  return v12530;
}

struct StateT * slot_14(struct StateT * v1291) {
  int v1292 = v1291->timer;
  int v1298 = v1292 + 1;
  v1291->timer = v1298;
  int * v1294 = v1291->regs;
  v1294[30] = 0;
  struct StateT * v1296 = slot_15(v1291);
  return v1296;
}

struct StateT * slot_53(struct StateT * v6037) {
  int v6038 = v6037->timer;
  int v6048 = v6038 + 1;
  v6037->timer = v6048;
  int * v6040 = v6037->regs;
  int v6041 = v6040[19];
  int * v6042 = v6037->regs;
  int v6043 = v6042[5];
  int * v6044 = v6037->regs;
  int v6055 = v6041 + v6043;
  v6044[18] = v6055;
  struct StateT * v6046 = slot_54(v6037);
  return v6046;
}

struct StateT * slot_80(struct StateT * v7809) {
  int v7810 = v7809->timer;
  int v7820 = v7810 + 1;
  v7809->timer = v7820;
  int * v7812 = v7809->regs;
  int v7813 = v7812[8];
  int * v7814 = v7809->regs;
  int v7815 = v7814[20];
  int * v7816 = v7809->regs;
  int v7826 = v7813 | v7815;
  v7816[8] = v7826;
  struct StateT * v7818 = slot_81(v7809);
  return v7818;
}

struct StateT * slot_44(struct StateT * v3479) {
  int v3480 = v3479->timer;
  int v3488 = v3480 + 1;
  v3479->timer = v3488;
  int * v3482 = v3479->regs;
  int v3483 = v3482[6];
  int * v3484 = v3479->regs;
  v3484[12] = v3483;
  struct StateT * v3486 = slot_45(v3479);
  return v3486;
}

struct StateT * slot_261(struct StateT * v9698) {
  int v9699 = v9698->timer;
  int v9753 = v9699 + 1;
  v9698->timer = v9753;
  int * v9701 = v9698->regs;
  int v9702 = v9701[10];
  int * v9703 = v9698->regs;
  int v9704 = v9703[30];
  int * v9705 = v9698->cache_keys;
  int v9706 = v9705[0];
  bool v9760 = v9706 == ((int)((unsigned int)(v9702 + 60) >> 2));
  int v9750;
  if (v9760) {
    int * v9707 = v9698->cache_vals;
    v9707[0] = v9704;
    v9750 = v9704;
  } else {
    int * v9710 = v9698->cache_keys;
    int v9711 = v9710[1];
    bool v9765 = v9711 == ((int)((unsigned int)(v9702 + 60) >> 2));
    int v9748;
    if (v9765) {
      int * v9712 = v9698->cache_keys;
      int * v9713 = v9698->cache_keys;
      int v9714 = v9713[0];
      v9712[1] = v9714;
      int * v9716 = v9698->cache_vals;
      int * v9717 = v9698->cache_vals;
      int v9718 = v9717[0];
      v9716[1] = v9718;
      int * v9720 = v9698->cache_keys;
      int v9773 = (int)((unsigned int)(v9702 + 60) >> 2);
      v9720[0] = v9773;
      int * v9722 = v9698->cache_vals;
      v9722[0] = v9704;
      int v9724 = v9698->timer;
      int v9776 = v9724 + 1;
      v9698->timer = v9776;
      v9748 = v9704;
    } else {
      int * v9727 = v9698->mem;
      int * v9728 = v9698->cache_keys;
      int v9729 = v9728[1];
      int * v9730 = v9698->cache_vals;
      int v9731 = v9730[1];
      v9727[v9729] = v9731;
      int * v9733 = v9698->cache_keys;
      int * v9734 = v9698->cache_keys;
      int v9735 = v9734[0];
      v9733[1] = v9735;
      int * v9737 = v9698->cache_vals;
      int * v9738 = v9698->cache_vals;
      int v9739 = v9738[0];
      v9737[1] = v9739;
      int * v9741 = v9698->cache_keys;
      int v9789 = (int)((unsigned int)(v9702 + 60) >> 2);
      v9741[0] = v9789;
      int * v9743 = v9698->cache_vals;
      v9743[0] = v9704;
      int v9745 = v9698->timer;
      int v9792 = v9745 + 100;
      v9698->timer = v9792;
      v9748 = v9704;
    }
    v9750 = v9748;
  }
  struct StateT * v9751 = slot_262(v9698);
  return v9751;
}

struct StateT * slot_137(struct StateT * v11902) {
  int v11903 = v11902->timer;
  int v11913 = v11903 + 1;
  v11902->timer = v11913;
  int * v11905 = v11902->regs;
  int v11906 = v11905[15];
  int * v11907 = v11902->regs;
  int v11908 = v11907[5];
  int * v11909 = v11902->regs;
  int v11919 = v11906 | v11908;
  v11909[15] = v11919;
  struct StateT * v11911 = slot_138(v11902);
  return v11911;
}

struct StateT * slot_122(struct StateT * v11615) {
  int v11616 = v11615->timer;
  int v11624 = v11616 + 1;
  v11615->timer = v11624;
  int * v11618 = v11615->regs;
  int v11619 = v11618[17];
  int * v11620 = v11615->regs;
  int v11628 = v11619 << 18;
  v11620[17] = v11628;
  struct StateT * v11622 = slot_123(v11615);
  return v11622;
}

struct StateT * slot_99(struct StateT * v9796) {
  int v9797 = v9796->timer;
  int v9805 = v9797 + 1;
  v9796->timer = v9805;
  int * v9799 = v9796->regs;
  int v9800 = v9799[8];
  int * v9801 = v9796->regs;
  int v9809 = v9800 << 13;
  v9801[8] = v9809;
  struct StateT * v9803 = slot_100(v9796);
  return v9803;
}

struct StateT * slot_179(struct StateT * v12695) {
  int v12696 = v12695->timer;
  int v12704 = v12696 + 1;
  v12695->timer = v12704;
  int * v12698 = v12695->regs;
  int v12699 = v12698[15];
  int * v12700 = v12695->regs;
  int v12708 = v12699 << 13;
  v12700[15] = v12708;
  struct StateT * v12702 = slot_180(v12695);
  return v12702;
}

struct StateT * slot_219(struct StateT * v6257) {
  int v6258 = v6257->timer;
  int v6264 = v6258 + 1;
  v6257->timer = v6264;
  int * v6260 = v6257->regs;
  v6260[6] = 857759744;
  struct StateT * v6262 = slot_220(v6257);
  return v6262;
}

struct StateT * slot_36(struct StateT * v2696) {
  int v2697 = v2696->timer;
  int v2751 = v2697 + 1;
  v2696->timer = v2751;
  int * v2699 = v2696->regs;
  int v2700 = v2699[2];
  int * v2701 = v2696->regs;
  int v2702 = v2701[26];
  int * v2703 = v2696->cache_keys;
  int v2704 = v2703[0];
  bool v2758 = v2704 == ((int)((unsigned int)(v2700 + 20) >> 2));
  int v2748;
  if (v2758) {
    int * v2705 = v2696->cache_vals;
    v2705[0] = v2702;
    v2748 = v2702;
  } else {
    int * v2708 = v2696->cache_keys;
    int v2709 = v2708[1];
    bool v2763 = v2709 == ((int)((unsigned int)(v2700 + 20) >> 2));
    int v2746;
    if (v2763) {
      int * v2710 = v2696->cache_keys;
      int * v2711 = v2696->cache_keys;
      int v2712 = v2711[0];
      v2710[1] = v2712;
      int * v2714 = v2696->cache_vals;
      int * v2715 = v2696->cache_vals;
      int v2716 = v2715[0];
      v2714[1] = v2716;
      int * v2718 = v2696->cache_keys;
      int v2771 = (int)((unsigned int)(v2700 + 20) >> 2);
      v2718[0] = v2771;
      int * v2720 = v2696->cache_vals;
      v2720[0] = v2702;
      int v2722 = v2696->timer;
      int v2774 = v2722 + 1;
      v2696->timer = v2774;
      v2746 = v2702;
    } else {
      int * v2725 = v2696->mem;
      int * v2726 = v2696->cache_keys;
      int v2727 = v2726[1];
      int * v2728 = v2696->cache_vals;
      int v2729 = v2728[1];
      v2725[v2727] = v2729;
      int * v2731 = v2696->cache_keys;
      int * v2732 = v2696->cache_keys;
      int v2733 = v2732[0];
      v2731[1] = v2733;
      int * v2735 = v2696->cache_vals;
      int * v2736 = v2696->cache_vals;
      int v2737 = v2736[0];
      v2735[1] = v2737;
      int * v2739 = v2696->cache_keys;
      int v2787 = (int)((unsigned int)(v2700 + 20) >> 2);
      v2739[0] = v2787;
      int * v2741 = v2696->cache_vals;
      v2741[0] = v2702;
      int v2743 = v2696->timer;
      int v2790 = v2743 + 100;
      v2696->timer = v2790;
      v2746 = v2702;
    }
    v2748 = v2746;
  }
  struct StateT * v2749 = slot_37(v2696);
  return v2749;
}

struct StateT * slot_57(struct StateT * v6270) {
  int v6271 = v6270->timer;
  int v6281 = v6271 + 1;
  v6270->timer = v6281;
  int * v6273 = v6270->regs;
  int v6274 = v6273[15];
  int * v6275 = v6270->regs;
  int v6276 = v6275[9];
  int * v6277 = v6270->regs;
  int v6287 = v6274 | v6276;
  v6277[15] = v6287;
  struct StateT * v6279 = slot_58(v6270);
  return v6279;
}

struct StateT * slot_62(struct StateT * v6715) {
  int v6716 = v6715->timer;
  int v6724 = v6716 + 1;
  v6715->timer = v6724;
  int * v6718 = v6715->regs;
  int v6719 = v6718[18];
  int * v6720 = v6715->regs;
  int v6728 = v6719 << 7;
  v6720[18] = v6728;
  struct StateT * v6722 = slot_63(v6715);
  return v6722;
}

struct StateT * slot_22(struct StateT * v2039) {
  int v2040 = v2039->timer;
  int v2098 = v2040 + 1;
  v2039->timer = v2098;
  int * v2042 = v2039->regs;
  int v2043 = v2042[12];
  int * v2044 = v2039->cache_keys;
  int v2045 = v2044[0];
  bool v2103 = v2045 == ((int)((unsigned int)(v2043 + 28) >> 2));
  int v2093;
  if (v2103) {
    int * v2046 = v2039->cache_vals;
    int v2047 = v2046[0];
    v2093 = v2047;
  } else {
    int * v2049 = v2039->cache_keys;
    int v2050 = v2049[1];
    bool v2108 = v2050 == ((int)((unsigned int)(v2043 + 28) >> 2));
    int v2091;
    if (v2108) {
      int * v2051 = v2039->cache_vals;
      int v2052 = v2051[1];
      int * v2053 = v2039->cache_keys;
      int * v2054 = v2039->cache_keys;
      int v2055 = v2054[0];
      v2053[1] = v2055;
      int * v2057 = v2039->cache_vals;
      int * v2058 = v2039->cache_vals;
      int v2059 = v2058[0];
      v2057[1] = v2059;
      int * v2061 = v2039->cache_keys;
      int v2117 = (int)((unsigned int)(v2043 + 28) >> 2);
      v2061[0] = v2117;
      int * v2063 = v2039->cache_vals;
      v2063[0] = v2052;
      int v2065 = v2039->timer;
      int v2120 = v2065 + 1;
      v2039->timer = v2120;
      v2091 = v2052;
    } else {
      int * v2068 = v2039->mem;
      int v2122 = (int)((unsigned int)(v2043 + 28) >> 2);
      int v2069 = v2068[v2122];
      int * v2070 = v2039->mem;
      int * v2071 = v2039->cache_keys;
      int v2072 = v2071[1];
      int * v2073 = v2039->cache_vals;
      int v2074 = v2073[1];
      v2070[v2072] = v2074;
      int * v2076 = v2039->cache_keys;
      int * v2077 = v2039->cache_keys;
      int v2078 = v2077[0];
      v2076[1] = v2078;
      int * v2080 = v2039->cache_vals;
      int * v2081 = v2039->cache_vals;
      int v2082 = v2081[0];
      v2080[1] = v2082;
      int * v2084 = v2039->cache_keys;
      v2084[0] = v2122;
      int * v2086 = v2039->cache_vals;
      v2086[0] = v2069;
      int v2088 = v2039->timer;
      int v2137 = v2088 + 100;
      v2039->timer = v2137;
      v2091 = v2069;
    }
    v2093 = v2091;
  }
  int * v2094 = v2039->regs;
  v2094[1] = v2093;
  struct StateT * v2096 = slot_23(v2039);
  return v2096;
}

struct StateT * slot_139(struct StateT * v11939) {
  int v11940 = v11939->timer;
  int v11948 = v11940 + 1;
  v11939->timer = v11948;
  int * v11942 = v11939->regs;
  int v11943 = v11942[11];
  int * v11944 = v11939->regs;
  int v11952 = v11943 << 7;
  v11944[11] = v11952;
  struct StateT * v11946 = slot_140(v11939);
  return v11946;
}

struct StateT * slot_221(struct StateT * v6412) {
  int v6413 = v6412->timer;
  int v6423 = v6413 + 1;
  v6412->timer = v6423;
  int * v6415 = v6412->regs;
  int v6416 = v6415[5];
  int * v6417 = v6412->regs;
  int v6418 = v6417[7];
  int * v6419 = v6412->regs;
  int v6429 = v6416 + v6418;
  v6419[5] = v6429;
  struct StateT * v6421 = slot_222(v6412);
  return v6421;
}

struct StateT * slot_23(struct StateT * v2144) {
  int v2145 = v2144->timer;
  int v2203 = v2145 + 1;
  v2144->timer = v2203;
  int * v2147 = v2144->regs;
  int v2148 = v2147[11];
  int * v2149 = v2144->cache_keys;
  int v2150 = v2149[0];
  bool v2208 = v2150 == ((int)((unsigned int)v2148 >> 2));
  int v2198;
  if (v2208) {
    int * v2151 = v2144->cache_vals;
    int v2152 = v2151[0];
    v2198 = v2152;
  } else {
    int * v2154 = v2144->cache_keys;
    int v2155 = v2154[1];
    bool v2213 = v2155 == ((int)((unsigned int)v2148 >> 2));
    int v2196;
    if (v2213) {
      int * v2156 = v2144->cache_vals;
      int v2157 = v2156[1];
      int * v2158 = v2144->cache_keys;
      int * v2159 = v2144->cache_keys;
      int v2160 = v2159[0];
      v2158[1] = v2160;
      int * v2162 = v2144->cache_vals;
      int * v2163 = v2144->cache_vals;
      int v2164 = v2163[0];
      v2162[1] = v2164;
      int * v2166 = v2144->cache_keys;
      int v2222 = (int)((unsigned int)v2148 >> 2);
      v2166[0] = v2222;
      int * v2168 = v2144->cache_vals;
      v2168[0] = v2157;
      int v2170 = v2144->timer;
      int v2225 = v2170 + 1;
      v2144->timer = v2225;
      v2196 = v2157;
    } else {
      int * v2173 = v2144->mem;
      int v2227 = (int)((unsigned int)v2148 >> 2);
      int v2174 = v2173[v2227];
      int * v2175 = v2144->mem;
      int * v2176 = v2144->cache_keys;
      int v2177 = v2176[1];
      int * v2178 = v2144->cache_vals;
      int v2179 = v2178[1];
      v2175[v2177] = v2179;
      int * v2181 = v2144->cache_keys;
      int * v2182 = v2144->cache_keys;
      int v2183 = v2182[0];
      v2181[1] = v2183;
      int * v2185 = v2144->cache_vals;
      int * v2186 = v2144->cache_vals;
      int v2187 = v2186[0];
      v2185[1] = v2187;
      int * v2189 = v2144->cache_keys;
      v2189[0] = v2227;
      int * v2191 = v2144->cache_vals;
      v2191[0] = v2174;
      int v2193 = v2144->timer;
      int v2242 = v2193 + 100;
      v2144->timer = v2242;
      v2196 = v2174;
    }
    v2198 = v2196;
  }
  int * v2199 = v2144->regs;
  v2199[5] = v2198;
  struct StateT * v2201 = slot_24(v2144);
  return v2201;
}

struct StateT * slot_153(struct StateT * v12207) {
  int v12208 = v12207->timer;
  int v12218 = v12208 + 1;
  v12207->timer = v12218;
  int * v12210 = v12207->regs;
  int v12211 = v12210[17];
  int * v12212 = v12207->regs;
  int v12213 = v12212[19];
  int * v12214 = v12207->regs;
  int v12225 = v12211 + v12213;
  v12214[6] = v12225;
  struct StateT * v12216 = slot_154(v12207);
  return v12216;
}

struct StateT * slot_2(struct StateT * v115) {
  int v116 = v115->timer;
  int v170 = v116 + 1;
  v115->timer = v170;
  int * v118 = v115->regs;
  int v119 = v118[2];
  int * v120 = v115->regs;
  int v121 = v120[8];
  int * v122 = v115->cache_keys;
  int v123 = v122[0];
  bool v177 = v123 == ((int)((unsigned int)(v119 + 88) >> 2));
  int v167;
  if (v177) {
    int * v124 = v115->cache_vals;
    v124[0] = v121;
    v167 = v121;
  } else {
    int * v127 = v115->cache_keys;
    int v128 = v127[1];
    bool v182 = v128 == ((int)((unsigned int)(v119 + 88) >> 2));
    int v165;
    if (v182) {
      int * v129 = v115->cache_keys;
      int * v130 = v115->cache_keys;
      int v131 = v130[0];
      v129[1] = v131;
      int * v133 = v115->cache_vals;
      int * v134 = v115->cache_vals;
      int v135 = v134[0];
      v133[1] = v135;
      int * v137 = v115->cache_keys;
      int v190 = (int)((unsigned int)(v119 + 88) >> 2);
      v137[0] = v190;
      int * v139 = v115->cache_vals;
      v139[0] = v121;
      int v141 = v115->timer;
      int v193 = v141 + 1;
      v115->timer = v193;
      v165 = v121;
    } else {
      int * v144 = v115->mem;
      int * v145 = v115->cache_keys;
      int v146 = v145[1];
      int * v147 = v115->cache_vals;
      int v148 = v147[1];
      v144[v146] = v148;
      int * v150 = v115->cache_keys;
      int * v151 = v115->cache_keys;
      int v152 = v151[0];
      v150[1] = v152;
      int * v154 = v115->cache_vals;
      int * v155 = v115->cache_vals;
      int v156 = v155[0];
      v154[1] = v156;
      int * v158 = v115->cache_keys;
      int v206 = (int)((unsigned int)(v119 + 88) >> 2);
      v158[0] = v206;
      int * v160 = v115->cache_vals;
      v160[0] = v121;
      int v162 = v115->timer;
      int v209 = v162 + 100;
      v115->timer = v209;
      v165 = v121;
    }
    v167 = v165;
  }
  struct StateT * v168 = slot_3(v115);
  return v168;
}

struct StateT * slot_86(struct StateT * v8269) {
  int v8270 = v8269->timer;
  int v8280 = v8270 + 1;
  v8269->timer = v8280;
  int * v8272 = v8269->regs;
  int v8273 = v8272[18];
  int * v8274 = v8269->regs;
  int v8275 = v8274[20];
  int * v8276 = v8269->regs;
  int v8286 = v8273 | v8275;
  v8276[18] = v8286;
  struct StateT * v8278 = slot_87(v8269);
  return v8278;
}

struct StateT * slot_129(struct StateT * v11745) {
  int v11746 = v11745->timer;
  int v11756 = v11746 + 1;
  v11745->timer = v11756;
  int * v11748 = v11745->regs;
  int v11749 = v11748[19];
  int * v11750 = v11745->regs;
  int v11751 = v11750[17];
  int * v11752 = v11745->regs;
  int v11762 = v11749 ^ v11751;
  v11752[19] = v11762;
  struct StateT * v11754 = slot_130(v11745);
  return v11754;
}

struct StateT * slot_158(struct StateT * v12302) {
  int v12303 = v12302->timer;
  int v12311 = v12303 + 1;
  v12302->timer = v12311;
  int * v12305 = v12302->regs;
  int v12306 = v12305[15];
  int * v12307 = v12302->regs;
  int v12316 = (int)((unsigned int)v12306 >> 23);
  v12307[9] = v12316;
  struct StateT * v12309 = slot_159(v12302);
  return v12309;
}

struct StateT * slot_100(struct StateT * v9917) {
  int v9918 = v9917->timer;
  int v9928 = v9918 + 1;
  v9917->timer = v9928;
  int * v9920 = v9917->regs;
  int v9921 = v9920[8];
  int * v9922 = v9917->regs;
  int v9923 = v9922[20];
  int * v9924 = v9917->regs;
  int v9934 = v9921 | v9923;
  v9924[8] = v9934;
  struct StateT * v9926 = slot_101(v9917);
  return v9926;
}

struct StateT * slot_271(struct StateT * v10925) {
  int v10926 = v10925->timer;
  int v10984 = v10926 + 1;
  v10925->timer = v10984;
  int * v10928 = v10925->regs;
  int v10929 = v10928[2];
  int * v10930 = v10925->cache_keys;
  int v10931 = v10930[0];
  bool v10989 = v10931 == ((int)((unsigned int)(v10929 + 56) >> 2));
  int v10979;
  if (v10989) {
    int * v10932 = v10925->cache_vals;
    int v10933 = v10932[0];
    v10979 = v10933;
  } else {
    int * v10935 = v10925->cache_keys;
    int v10936 = v10935[1];
    bool v10994 = v10936 == ((int)((unsigned int)(v10929 + 56) >> 2));
    int v10977;
    if (v10994) {
      int * v10937 = v10925->cache_vals;
      int v10938 = v10937[1];
      int * v10939 = v10925->cache_keys;
      int * v10940 = v10925->cache_keys;
      int v10941 = v10940[0];
      v10939[1] = v10941;
      int * v10943 = v10925->cache_vals;
      int * v10944 = v10925->cache_vals;
      int v10945 = v10944[0];
      v10943[1] = v10945;
      int * v10947 = v10925->cache_keys;
      int v11003 = (int)((unsigned int)(v10929 + 56) >> 2);
      v10947[0] = v11003;
      int * v10949 = v10925->cache_vals;
      v10949[0] = v10938;
      int v10951 = v10925->timer;
      int v11006 = v10951 + 1;
      v10925->timer = v11006;
      v10977 = v10938;
    } else {
      int * v10954 = v10925->mem;
      int v11008 = (int)((unsigned int)(v10929 + 56) >> 2);
      int v10955 = v10954[v11008];
      int * v10956 = v10925->mem;
      int * v10957 = v10925->cache_keys;
      int v10958 = v10957[1];
      int * v10959 = v10925->cache_vals;
      int v10960 = v10959[1];
      v10956[v10958] = v10960;
      int * v10962 = v10925->cache_keys;
      int * v10963 = v10925->cache_keys;
      int v10964 = v10963[0];
      v10962[1] = v10964;
      int * v10966 = v10925->cache_vals;
      int * v10967 = v10925->cache_vals;
      int v10968 = v10967[0];
      v10966[1] = v10968;
      int * v10970 = v10925->cache_keys;
      v10970[0] = v11008;
      int * v10972 = v10925->cache_vals;
      v10972[0] = v10955;
      int v10974 = v10925->timer;
      int v11023 = v10974 + 100;
      v10925->timer = v11023;
      v10977 = v10955;
    }
    v10979 = v10977;
  }
  int * v10980 = v10925->regs;
  v10980[24] = v10979;
  struct StateT * v10982 = slot_272(v10925);
  return v10982;
}

struct StateT * slot_127(struct StateT * v11704) {
  int v11705 = v11704->timer;
  int v11715 = v11705 + 1;
  v11704->timer = v11715;
  int * v11707 = v11704->regs;
  int v11708 = v11707[21];
  int * v11709 = v11704->regs;
  int v11710 = v11709[15];
  int * v11711 = v11704->regs;
  int v11721 = v11708 ^ v11710;
  v11711[21] = v11721;
  struct StateT * v11713 = slot_128(v11704);
  return v11713;
}

struct StateT * slot_217(struct StateT * v6099) {
  int v6100 = v6099->timer;
  int v6158 = v6100 + 1;
  v6099->timer = v6158;
  int * v6102 = v6099->regs;
  int v6103 = v6102[2];
  int * v6104 = v6099->cache_keys;
  int v6105 = v6104[0];
  bool v6163 = v6105 == ((int)((unsigned int)(v6103 + 8) >> 2));
  int v6153;
  if (v6163) {
    int * v6106 = v6099->cache_vals;
    int v6107 = v6106[0];
    v6153 = v6107;
  } else {
    int * v6109 = v6099->cache_keys;
    int v6110 = v6109[1];
    bool v6168 = v6110 == ((int)((unsigned int)(v6103 + 8) >> 2));
    int v6151;
    if (v6168) {
      int * v6111 = v6099->cache_vals;
      int v6112 = v6111[1];
      int * v6113 = v6099->cache_keys;
      int * v6114 = v6099->cache_keys;
      int v6115 = v6114[0];
      v6113[1] = v6115;
      int * v6117 = v6099->cache_vals;
      int * v6118 = v6099->cache_vals;
      int v6119 = v6118[0];
      v6117[1] = v6119;
      int * v6121 = v6099->cache_keys;
      int v6177 = (int)((unsigned int)(v6103 + 8) >> 2);
      v6121[0] = v6177;
      int * v6123 = v6099->cache_vals;
      v6123[0] = v6112;
      int v6125 = v6099->timer;
      int v6180 = v6125 + 1;
      v6099->timer = v6180;
      v6151 = v6112;
    } else {
      int * v6128 = v6099->mem;
      int v6182 = (int)((unsigned int)(v6103 + 8) >> 2);
      int v6129 = v6128[v6182];
      int * v6130 = v6099->mem;
      int * v6131 = v6099->cache_keys;
      int v6132 = v6131[1];
      int * v6133 = v6099->cache_vals;
      int v6134 = v6133[1];
      v6130[v6132] = v6134;
      int * v6136 = v6099->cache_keys;
      int * v6137 = v6099->cache_keys;
      int v6138 = v6137[0];
      v6136[1] = v6138;
      int * v6140 = v6099->cache_vals;
      int * v6141 = v6099->cache_vals;
      int v6142 = v6141[0];
      v6140[1] = v6142;
      int * v6144 = v6099->cache_keys;
      v6144[0] = v6182;
      int * v6146 = v6099->cache_vals;
      v6146[0] = v6129;
      int v6148 = v6099->timer;
      int v6197 = v6148 + 100;
      v6099->timer = v6197;
      v6151 = v6129;
    }
    v6153 = v6151;
  }
  int * v6154 = v6099->regs;
  v6154[6] = v6153;
  struct StateT * v6156 = slot_218(v6099);
  return v6156;
}

struct StateT * slot_13(struct StateT * v1193) {
  int v1194 = v1193->timer;
  int v1248 = v1194 + 1;
  v1193->timer = v1248;
  int * v1196 = v1193->regs;
  int v1197 = v1196[2];
  int * v1198 = v1193->regs;
  int v1199 = v1198[27];
  int * v1200 = v1193->cache_keys;
  int v1201 = v1200[0];
  bool v1255 = v1201 == ((int)((unsigned int)(v1197 + 44) >> 2));
  int v1245;
  if (v1255) {
    int * v1202 = v1193->cache_vals;
    v1202[0] = v1199;
    v1245 = v1199;
  } else {
    int * v1205 = v1193->cache_keys;
    int v1206 = v1205[1];
    bool v1260 = v1206 == ((int)((unsigned int)(v1197 + 44) >> 2));
    int v1243;
    if (v1260) {
      int * v1207 = v1193->cache_keys;
      int * v1208 = v1193->cache_keys;
      int v1209 = v1208[0];
      v1207[1] = v1209;
      int * v1211 = v1193->cache_vals;
      int * v1212 = v1193->cache_vals;
      int v1213 = v1212[0];
      v1211[1] = v1213;
      int * v1215 = v1193->cache_keys;
      int v1268 = (int)((unsigned int)(v1197 + 44) >> 2);
      v1215[0] = v1268;
      int * v1217 = v1193->cache_vals;
      v1217[0] = v1199;
      int v1219 = v1193->timer;
      int v1271 = v1219 + 1;
      v1193->timer = v1271;
      v1243 = v1199;
    } else {
      int * v1222 = v1193->mem;
      int * v1223 = v1193->cache_keys;
      int v1224 = v1223[1];
      int * v1225 = v1193->cache_vals;
      int v1226 = v1225[1];
      v1222[v1224] = v1226;
      int * v1228 = v1193->cache_keys;
      int * v1229 = v1193->cache_keys;
      int v1230 = v1229[0];
      v1228[1] = v1230;
      int * v1232 = v1193->cache_vals;
      int * v1233 = v1193->cache_vals;
      int v1234 = v1233[0];
      v1232[1] = v1234;
      int * v1236 = v1193->cache_keys;
      int v1284 = (int)((unsigned int)(v1197 + 44) >> 2);
      v1236[0] = v1284;
      int * v1238 = v1193->cache_vals;
      v1238[0] = v1199;
      int v1240 = v1193->timer;
      int v1287 = v1240 + 100;
      v1193->timer = v1287;
      v1243 = v1199;
    }
    v1245 = v1243;
  }
  struct StateT * v1246 = slot_14(v1193);
  return v1246;
}

struct StateT * slot_111(struct StateT * v11282) {
  int v11283 = v11282->timer;
  int v11293 = v11283 + 1;
  v11282->timer = v11293;
  int * v11285 = v11282->regs;
  int v11286 = v11285[9];
  int * v11287 = v11282->regs;
  int v11288 = v11287[26];
  int * v11289 = v11282->regs;
  int v11300 = v11286 + v11288;
  v11289[15] = v11300;
  struct StateT * v11291 = slot_112(v11282);
  return v11291;
}

struct StateT * slot_109(struct StateT * v11030) {
  int v11031 = v11030->timer;
  int v11041 = v11031 + 1;
  v11030->timer = v11041;
  int * v11033 = v11030->regs;
  int v11034 = v11033[5];
  int * v11035 = v11030->regs;
  int v11036 = v11035[20];
  int * v11037 = v11030->regs;
  int v11048 = v11034 ^ v11036;
  v11037[18] = v11048;
  struct StateT * v11039 = slot_110(v11030);
  return v11039;
}

struct StateT * slot_174(struct StateT * v12604) {
  int v12605 = v12604->timer;
  int v12615 = v12605 + 1;
  v12604->timer = v12615;
  int * v12607 = v12604->regs;
  int v12608 = v12607[24];
  int * v12609 = v12604->regs;
  int v12610 = v12609[16];
  int * v12611 = v12604->regs;
  int v12622 = v12608 + v12610;
  v12611[8] = v12622;
  struct StateT * v12613 = slot_175(v12604);
  return v12613;
}

struct StateT * slot_147(struct StateT * v12082) {
  int v12083 = v12082->timer;
  int v12093 = v12083 + 1;
  v12082->timer = v12093;
  int * v12085 = v12082->regs;
  int v12086 = v12085[23];
  int * v12087 = v12082->regs;
  int v12088 = v12087[15];
  int * v12089 = v12082->regs;
  int v12099 = v12086 ^ v12088;
  v12089[23] = v12099;
  struct StateT * v12091 = slot_148(v12082);
  return v12091;
}

struct StateT * slot_42(struct StateT * v3283) {
  int v3284 = v3283->timer;
  int v3338 = v3284 + 1;
  v3283->timer = v3338;
  int * v3286 = v3283->regs;
  int v3287 = v3286[2];
  int * v3288 = v3283->regs;
  int v3289 = v3288[17];
  int * v3290 = v3283->cache_keys;
  int v3291 = v3290[0];
  bool v3345 = v3291 == ((int)((unsigned int)(v3287 + 28) >> 2));
  int v3335;
  if (v3345) {
    int * v3292 = v3283->cache_vals;
    v3292[0] = v3289;
    v3335 = v3289;
  } else {
    int * v3295 = v3283->cache_keys;
    int v3296 = v3295[1];
    bool v3350 = v3296 == ((int)((unsigned int)(v3287 + 28) >> 2));
    int v3333;
    if (v3350) {
      int * v3297 = v3283->cache_keys;
      int * v3298 = v3283->cache_keys;
      int v3299 = v3298[0];
      v3297[1] = v3299;
      int * v3301 = v3283->cache_vals;
      int * v3302 = v3283->cache_vals;
      int v3303 = v3302[0];
      v3301[1] = v3303;
      int * v3305 = v3283->cache_keys;
      int v3358 = (int)((unsigned int)(v3287 + 28) >> 2);
      v3305[0] = v3358;
      int * v3307 = v3283->cache_vals;
      v3307[0] = v3289;
      int v3309 = v3283->timer;
      int v3361 = v3309 + 1;
      v3283->timer = v3361;
      v3333 = v3289;
    } else {
      int * v3312 = v3283->mem;
      int * v3313 = v3283->cache_keys;
      int v3314 = v3313[1];
      int * v3315 = v3283->cache_vals;
      int v3316 = v3315[1];
      v3312[v3314] = v3316;
      int * v3318 = v3283->cache_keys;
      int * v3319 = v3283->cache_keys;
      int v3320 = v3319[0];
      v3318[1] = v3320;
      int * v3322 = v3283->cache_vals;
      int * v3323 = v3283->cache_vals;
      int v3324 = v3323[0];
      v3322[1] = v3324;
      int * v3326 = v3283->cache_keys;
      int v3374 = (int)((unsigned int)(v3287 + 28) >> 2);
      v3326[0] = v3374;
      int * v3328 = v3283->cache_vals;
      v3328[0] = v3289;
      int v3330 = v3283->timer;
      int v3377 = v3330 + 100;
      v3283->timer = v3377;
      v3333 = v3289;
    }
    v3335 = v3333;
  }
  struct StateT * v3336 = slot_43(v3283);
  return v3336;
}

struct StateT * slot_224(struct StateT * v6610) {
  int v6611 = v6610->timer;
  int v6669 = v6611 + 1;
  v6610->timer = v6669;
  int * v6613 = v6610->regs;
  int v6614 = v6613[2];
  int * v6615 = v6610->cache_keys;
  int v6616 = v6615[0];
  bool v6674 = v6616 == ((int)((unsigned int)(v6614 + 20) >> 2));
  int v6664;
  if (v6674) {
    int * v6617 = v6610->cache_vals;
    int v6618 = v6617[0];
    v6664 = v6618;
  } else {
    int * v6620 = v6610->cache_keys;
    int v6621 = v6620[1];
    bool v6679 = v6621 == ((int)((unsigned int)(v6614 + 20) >> 2));
    int v6662;
    if (v6679) {
      int * v6622 = v6610->cache_vals;
      int v6623 = v6622[1];
      int * v6624 = v6610->cache_keys;
      int * v6625 = v6610->cache_keys;
      int v6626 = v6625[0];
      v6624[1] = v6626;
      int * v6628 = v6610->cache_vals;
      int * v6629 = v6610->cache_vals;
      int v6630 = v6629[0];
      v6628[1] = v6630;
      int * v6632 = v6610->cache_keys;
      int v6688 = (int)((unsigned int)(v6614 + 20) >> 2);
      v6632[0] = v6688;
      int * v6634 = v6610->cache_vals;
      v6634[0] = v6623;
      int v6636 = v6610->timer;
      int v6691 = v6636 + 1;
      v6610->timer = v6691;
      v6662 = v6623;
    } else {
      int * v6639 = v6610->mem;
      int v6693 = (int)((unsigned int)(v6614 + 20) >> 2);
      int v6640 = v6639[v6693];
      int * v6641 = v6610->mem;
      int * v6642 = v6610->cache_keys;
      int v6643 = v6642[1];
      int * v6644 = v6610->cache_vals;
      int v6645 = v6644[1];
      v6641[v6643] = v6645;
      int * v6647 = v6610->cache_keys;
      int * v6648 = v6610->cache_keys;
      int v6649 = v6648[0];
      v6647[1] = v6649;
      int * v6651 = v6610->cache_vals;
      int * v6652 = v6610->cache_vals;
      int v6653 = v6652[0];
      v6651[1] = v6653;
      int * v6655 = v6610->cache_keys;
      v6655[0] = v6693;
      int * v6657 = v6610->cache_vals;
      v6657[0] = v6640;
      int v6659 = v6610->timer;
      int v6708 = v6659 + 100;
      v6610->timer = v6708;
      v6662 = v6640;
    }
    v6664 = v6662;
  }
  int * v6665 = v6610->regs;
  v6665[7] = v6664;
  struct StateT * v6667 = slot_225(v6610);
  return v6667;
}

struct StateT * slot_163(struct StateT * v12388) {
  int v12389 = v12388->timer;
  int v12399 = v12389 + 1;
  v12388->timer = v12399;
  int * v12391 = v12388->regs;
  int v12392 = v12391[6];
  int * v12393 = v12388->regs;
  int v12394 = v12393[9];
  int * v12395 = v12388->regs;
  int v12405 = v12392 | v12394;
  v12395[6] = v12405;
  struct StateT * v12397 = slot_164(v12388);
  return v12397;
}

struct StateT * slot_184(struct StateT * v12784) {
  int v12785 = v12784->timer;
  int v12793 = v12785 + 1;
  v12784->timer = v12793;
  int * v12787 = v12784->regs;
  int v12788 = v12787[8];
  int * v12789 = v12784->regs;
  int v12798 = (int)((unsigned int)v12788 >> 19);
  v12789[9] = v12798;
  struct StateT * v12791 = slot_185(v12784);
  return v12791;
}

struct StateT * slot_204(struct StateT * v13160) {
  int v13161 = v13160->timer;
  int v13169 = v13161 + 1;
  v13160->timer = v13169;
  int * v13163 = v13160->regs;
  int v13164 = v13163[8];
  int * v13165 = v13160->regs;
  int v13174 = (int)((unsigned int)v13164 >> 14);
  v13165[9] = v13174;
  struct StateT * v13167 = slot_205(v13160);
  return v13167;
}

struct StateT * slot_194(struct StateT * v12980) {
  int v12981 = v12980->timer;
  int v12991 = v12981 + 1;
  v12980->timer = v12991;
  int * v12983 = v12980->regs;
  int v12984 = v12983[1];
  int * v12985 = v12980->regs;
  int v12986 = v12985[24];
  int * v12987 = v12980->regs;
  int v12998 = v12984 + v12986;
  v12987[8] = v12998;
  struct StateT * v12989 = slot_195(v12980);
  return v12989;
}

struct StateT * slot_165(struct StateT * v12425) {
  int v12426 = v12425->timer;
  int v12434 = v12426 + 1;
  v12425->timer = v12434;
  int * v12428 = v12425->regs;
  int v12429 = v12428[8];
  int * v12430 = v12425->regs;
  int v12438 = v12429 << 9;
  v12430[8] = v12438;
  struct StateT * v12432 = slot_166(v12425);
  return v12432;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_250(struct StateT * v8407) {
  int v8408 = v8407->timer;
  int v8462 = v8408 + 1;
  v8407->timer = v8462;
  int * v8410 = v8407->regs;
  int v8411 = v8410[10];
  int * v8412 = v8407->regs;
  int v8413 = v8412[12];
  int * v8414 = v8407->cache_keys;
  int v8415 = v8414[0];
  bool v8469 = v8415 == ((int)((unsigned int)(v8411 + 16) >> 2));
  int v8459;
  if (v8469) {
    int * v8416 = v8407->cache_vals;
    v8416[0] = v8413;
    v8459 = v8413;
  } else {
    int * v8419 = v8407->cache_keys;
    int v8420 = v8419[1];
    bool v8474 = v8420 == ((int)((unsigned int)(v8411 + 16) >> 2));
    int v8457;
    if (v8474) {
      int * v8421 = v8407->cache_keys;
      int * v8422 = v8407->cache_keys;
      int v8423 = v8422[0];
      v8421[1] = v8423;
      int * v8425 = v8407->cache_vals;
      int * v8426 = v8407->cache_vals;
      int v8427 = v8426[0];
      v8425[1] = v8427;
      int * v8429 = v8407->cache_keys;
      int v8482 = (int)((unsigned int)(v8411 + 16) >> 2);
      v8429[0] = v8482;
      int * v8431 = v8407->cache_vals;
      v8431[0] = v8413;
      int v8433 = v8407->timer;
      int v8485 = v8433 + 1;
      v8407->timer = v8485;
      v8457 = v8413;
    } else {
      int * v8436 = v8407->mem;
      int * v8437 = v8407->cache_keys;
      int v8438 = v8437[1];
      int * v8439 = v8407->cache_vals;
      int v8440 = v8439[1];
      v8436[v8438] = v8440;
      int * v8442 = v8407->cache_keys;
      int * v8443 = v8407->cache_keys;
      int v8444 = v8443[0];
      v8442[1] = v8444;
      int * v8446 = v8407->cache_vals;
      int * v8447 = v8407->cache_vals;
      int v8448 = v8447[0];
      v8446[1] = v8448;
      int * v8450 = v8407->cache_keys;
      int v8498 = (int)((unsigned int)(v8411 + 16) >> 2);
      v8450[0] = v8498;
      int * v8452 = v8407->cache_vals;
      v8452[0] = v8413;
      int v8454 = v8407->timer;
      int v8501 = v8454 + 100;
      v8407->timer = v8501;
      v8457 = v8413;
    }
    v8459 = v8457;
  }
  struct StateT * v8460 = slot_251(v8407);
  return v8460;
}

struct StateT * slot_259(struct StateT * v9466) {
  int v9467 = v9466->timer;
  int v9521 = v9467 + 1;
  v9466->timer = v9521;
  int * v9469 = v9466->regs;
  int v9470 = v9469[10];
  int * v9471 = v9466->regs;
  int v9472 = v9471[24];
  int * v9473 = v9466->cache_keys;
  int v9474 = v9473[0];
  bool v9528 = v9474 == ((int)((unsigned int)(v9470 + 52) >> 2));
  int v9518;
  if (v9528) {
    int * v9475 = v9466->cache_vals;
    v9475[0] = v9472;
    v9518 = v9472;
  } else {
    int * v9478 = v9466->cache_keys;
    int v9479 = v9478[1];
    bool v9533 = v9479 == ((int)((unsigned int)(v9470 + 52) >> 2));
    int v9516;
    if (v9533) {
      int * v9480 = v9466->cache_keys;
      int * v9481 = v9466->cache_keys;
      int v9482 = v9481[0];
      v9480[1] = v9482;
      int * v9484 = v9466->cache_vals;
      int * v9485 = v9466->cache_vals;
      int v9486 = v9485[0];
      v9484[1] = v9486;
      int * v9488 = v9466->cache_keys;
      int v9541 = (int)((unsigned int)(v9470 + 52) >> 2);
      v9488[0] = v9541;
      int * v9490 = v9466->cache_vals;
      v9490[0] = v9472;
      int v9492 = v9466->timer;
      int v9544 = v9492 + 1;
      v9466->timer = v9544;
      v9516 = v9472;
    } else {
      int * v9495 = v9466->mem;
      int * v9496 = v9466->cache_keys;
      int v9497 = v9496[1];
      int * v9498 = v9466->cache_vals;
      int v9499 = v9498[1];
      v9495[v9497] = v9499;
      int * v9501 = v9466->cache_keys;
      int * v9502 = v9466->cache_keys;
      int v9503 = v9502[0];
      v9501[1] = v9503;
      int * v9505 = v9466->cache_vals;
      int * v9506 = v9466->cache_vals;
      int v9507 = v9506[0];
      v9505[1] = v9507;
      int * v9509 = v9466->cache_keys;
      int v9557 = (int)((unsigned int)(v9470 + 52) >> 2);
      v9509[0] = v9557;
      int * v9511 = v9466->cache_vals;
      v9511[0] = v9472;
      int v9513 = v9466->timer;
      int v9560 = v9513 + 100;
      v9466->timer = v9560;
      v9516 = v9472;
    }
    v9518 = v9516;
  }
  struct StateT * v9519 = slot_260(v9466);
  return v9519;
}

struct StateT * slot_117(struct StateT * v11525) {
  int v11526 = v11525->timer;
  int v11536 = v11526 + 1;
  v11525->timer = v11536;
  int * v11528 = v11525->regs;
  int v11529 = v11528[15];
  int * v11530 = v11525->regs;
  int v11531 = v11530[6];
  int * v11532 = v11525->regs;
  int v11542 = v11529 | v11531;
  v11532[15] = v11542;
  struct StateT * v11534 = slot_118(v11525);
  return v11534;
}

struct StateT * slot_249(struct StateT * v8289) {
  int v8290 = v8289->timer;
  int v8344 = v8290 + 1;
  v8289->timer = v8344;
  int * v8292 = v8289->regs;
  int v8293 = v8292[10];
  int * v8294 = v8289->regs;
  int v8295 = v8294[14];
  int * v8296 = v8289->cache_keys;
  int v8297 = v8296[0];
  bool v8351 = v8297 == ((int)((unsigned int)(v8293 + 12) >> 2));
  int v8341;
  if (v8351) {
    int * v8298 = v8289->cache_vals;
    v8298[0] = v8295;
    v8341 = v8295;
  } else {
    int * v8301 = v8289->cache_keys;
    int v8302 = v8301[1];
    bool v8356 = v8302 == ((int)((unsigned int)(v8293 + 12) >> 2));
    int v8339;
    if (v8356) {
      int * v8303 = v8289->cache_keys;
      int * v8304 = v8289->cache_keys;
      int v8305 = v8304[0];
      v8303[1] = v8305;
      int * v8307 = v8289->cache_vals;
      int * v8308 = v8289->cache_vals;
      int v8309 = v8308[0];
      v8307[1] = v8309;
      int * v8311 = v8289->cache_keys;
      int v8364 = (int)((unsigned int)(v8293 + 12) >> 2);
      v8311[0] = v8364;
      int * v8313 = v8289->cache_vals;
      v8313[0] = v8295;
      int v8315 = v8289->timer;
      int v8367 = v8315 + 1;
      v8289->timer = v8367;
      v8339 = v8295;
    } else {
      int * v8318 = v8289->mem;
      int * v8319 = v8289->cache_keys;
      int v8320 = v8319[1];
      int * v8321 = v8289->cache_vals;
      int v8322 = v8321[1];
      v8318[v8320] = v8322;
      int * v8324 = v8289->cache_keys;
      int * v8325 = v8289->cache_keys;
      int v8326 = v8325[0];
      v8324[1] = v8326;
      int * v8328 = v8289->cache_vals;
      int * v8329 = v8289->cache_vals;
      int v8330 = v8329[0];
      v8328[1] = v8330;
      int * v8332 = v8289->cache_keys;
      int v8380 = (int)((unsigned int)(v8293 + 12) >> 2);
      v8332[0] = v8380;
      int * v8334 = v8289->cache_vals;
      v8334[0] = v8295;
      int v8336 = v8289->timer;
      int v8383 = v8336 + 100;
      v8289->timer = v8383;
      v8339 = v8295;
    }
    v8341 = v8339;
  }
  struct StateT * v8342 = slot_250(v8289);
  return v8342;
}

struct StateT * slot_90(struct StateT * v8741) {
  int v8742 = v8741->timer;
  int v8752 = v8742 + 1;
  v8741->timer = v8752;
  int * v8744 = v8741->regs;
  int v8745 = v8744[25];
  int * v8746 = v8741->regs;
  int v8747 = v8746[18];
  int * v8748 = v8741->regs;
  int v8758 = v8745 ^ v8747;
  v8748[25] = v8758;
  struct StateT * v8750 = slot_91(v8741);
  return v8750;
}

struct StateT * slot_11(struct StateT * v997) {
  int v998 = v997->timer;
  int v1052 = v998 + 1;
  v997->timer = v1052;
  int * v1000 = v997->regs;
  int v1001 = v1000[2];
  int * v1002 = v997->regs;
  int v1003 = v1002[25];
  int * v1004 = v997->cache_keys;
  int v1005 = v1004[0];
  bool v1059 = v1005 == ((int)((unsigned int)(v1001 + 52) >> 2));
  int v1049;
  if (v1059) {
    int * v1006 = v997->cache_vals;
    v1006[0] = v1003;
    v1049 = v1003;
  } else {
    int * v1009 = v997->cache_keys;
    int v1010 = v1009[1];
    bool v1064 = v1010 == ((int)((unsigned int)(v1001 + 52) >> 2));
    int v1047;
    if (v1064) {
      int * v1011 = v997->cache_keys;
      int * v1012 = v997->cache_keys;
      int v1013 = v1012[0];
      v1011[1] = v1013;
      int * v1015 = v997->cache_vals;
      int * v1016 = v997->cache_vals;
      int v1017 = v1016[0];
      v1015[1] = v1017;
      int * v1019 = v997->cache_keys;
      int v1072 = (int)((unsigned int)(v1001 + 52) >> 2);
      v1019[0] = v1072;
      int * v1021 = v997->cache_vals;
      v1021[0] = v1003;
      int v1023 = v997->timer;
      int v1075 = v1023 + 1;
      v997->timer = v1075;
      v1047 = v1003;
    } else {
      int * v1026 = v997->mem;
      int * v1027 = v997->cache_keys;
      int v1028 = v1027[1];
      int * v1029 = v997->cache_vals;
      int v1030 = v1029[1];
      v1026[v1028] = v1030;
      int * v1032 = v997->cache_keys;
      int * v1033 = v997->cache_keys;
      int v1034 = v1033[0];
      v1032[1] = v1034;
      int * v1036 = v997->cache_vals;
      int * v1037 = v997->cache_vals;
      int v1038 = v1037[0];
      v1036[1] = v1038;
      int * v1040 = v997->cache_keys;
      int v1088 = (int)((unsigned int)(v1001 + 52) >> 2);
      v1040[0] = v1088;
      int * v1042 = v997->cache_vals;
      v1042[0] = v1003;
      int v1044 = v997->timer;
      int v1091 = v1044 + 100;
      v997->timer = v1091;
      v1047 = v1003;
    }
    v1049 = v1047;
  }
  struct StateT * v1050 = slot_12(v997);
  return v1050;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
    s->saved_regs[i] = 0;
  }
  s->regs[2] = 4 * MEM_SIZE;
  s->timer = 0;
  for (int i=0; i<MEM_SIZE; i++) {
    s->mem[i] = 0;
  }
  for (int i=0; i<CACHE_LRU_SIZE; i++) {
    s->cache_keys[i] = -1;
    s->cache_vals[i] = -1;
  }
}

int main(int argc, char* argv[]) {
  struct StateT s1, s2;
  init(&s1);
  init(&s2);
  
  // a10, 16 words written by the callee: the address is public
  s1.regs[10] = 0;
  s2.regs[10] = 0;
  // a11, 4 words read by the callee: the address is public
  s1.regs[11] = 64;
  s2.regs[11] = 64;
  // a12, 8 words read by the callee: the address is public
  s1.regs[12] = 80;
  s2.regs[12] = 80;
  
  // a11's contents, secret: a different draw in each state
  for (int i=0; i<4; i++) {
    s1.mem[16 + i] = bounded(0, 20);
    s2.mem[16 + i] = bounded(0, 20);
  }
  // a12's contents, secret: a different draw in each state
  for (int i=0; i<8; i++) {
    s1.mem[20 + i] = bounded(0, 20);
    s2.mem[20 + i] = bounded(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  __CPROVER_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}