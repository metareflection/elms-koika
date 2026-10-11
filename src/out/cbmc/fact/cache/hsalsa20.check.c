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

struct StateT * slot_12(struct StateT * v3068);
struct StateT * slot_143(struct StateT * v11549);
struct StateT * slot_120(struct StateT * v11192);
struct StateT * slot_167(struct StateT * v11921);
struct StateT * slot_152(struct StateT * v11687);
struct StateT * slot_199(struct StateT * v6784);
struct StateT * slot_92(struct StateT * v10751);
struct StateT * slot_31(struct StateT * v5423);
struct StateT * slot_160(struct StateT * v11816);
struct StateT * slot_65(struct StateT * v10330);
struct StateT * slot_10(struct StateT * v2851);
struct StateT * slot_150(struct StateT * v11655);
struct StateT * slot_74(struct StateT * v10472);
struct StateT * slot_107(struct StateT * v10985);
struct StateT * slot_136(struct StateT * v11442);
struct StateT * slot_84(struct StateT * v10628);
struct StateT * slot_28(struct StateT * v5381);
struct StateT * slot_155(struct StateT * v11737);
struct StateT * slot_177(struct StateT * v12083);
struct StateT * slot_17(struct StateT * v4088);
struct StateT * slot_181(struct StateT * v12143);
struct StateT * slot_197(struct StateT * v6120);
struct StateT * slot_207(struct StateT * v8979);
struct StateT * slot_156(struct StateT * v11754);
struct StateT * slot_154(struct StateT * v11720);
struct StateT * slot_68(struct StateT * v10375);
struct StateT * slot_105(struct StateT * v10954);
struct StateT * slot_27(struct StateT * v5366);
struct StateT * slot_164(struct StateT * v11876);
struct StateT * slot_15(struct StateT * v3680);
struct StateT * slot_133(struct StateT * v11391);
struct StateT * slot_56(struct StateT * v10194);
struct StateT * slot_34(struct StateT * v6103);
struct StateT * slot_171(struct StateT * v11983);
struct StateT * slot_162(struct StateT * v11845);
struct StateT * slot_21(struct StateT * v4904);
struct StateT * slot_118(struct StateT * v11162);
struct StateT * slot_121(struct StateT * v11207);
struct StateT * slot_144(struct StateT * v11564);
struct StateT * slot_201(struct StateT * v7443);
struct StateT * slot_94(struct StateT * v10784);
struct StateT * slot_63(struct StateT * v10301);
struct StateT * slot_146(struct StateT * v11594);
struct StateT * slot_24(struct StateT * v5325);
struct StateT * slot_0(struct StateT * v2);
struct StateT * slot_195(struct StateT * v5456);
struct StateT * slot_125(struct StateT * v11266);
struct StateT * slot_148(struct StateT * v11623);
struct StateT * slot_126(struct StateT * v11282);
struct StateT * slot_79(struct StateT * v10552);
struct StateT * slot_41(struct StateT * v8308);
struct StateT * slot_39(struct StateT * v7758);
struct StateT * slot_142(struct StateT * v11533);
struct StateT * slot_60(struct StateT * v10256);
struct StateT * slot_112(struct StateT * v11063);
struct StateT * slot_47(struct StateT * v9622);
struct StateT * slot_29(struct StateT * v5396);
struct StateT * slot_16(struct StateT * v3884);
struct StateT * slot_113(struct StateT * v11079);
struct StateT * slot_151(struct StateT * v11671);
struct StateT * slot_7(struct StateT * v1906);
struct StateT * slot_124(struct StateT * v11252);
struct StateT * slot_191(struct StateT * v12295);
struct StateT * slot_103(struct StateT * v10925);
struct StateT * slot_128(struct StateT * v11311);
struct StateT * slot_19(struct StateT * v4496);
struct StateT * slot_87(struct StateT * v10673);
struct StateT * slot_67(struct StateT * v10361);
struct StateT * slot_81(struct StateT * v10583);
struct StateT * slot_95(struct StateT * v10801);
struct StateT * slot_115(struct StateT * v11113);
struct StateT * slot_78(struct StateT * v10538);
struct StateT * slot_32(struct StateT * v5436);
struct StateT * slot_205(struct StateT * v8542);
struct StateT * slot_193(struct StateT * v12327);
struct StateT * slot_176(struct StateT * v12066);
struct StateT * slot_189(struct StateT * v12263);
struct StateT * slot_33(struct StateT * v5771);
struct StateT * slot_35(struct StateT * v6435);
struct StateT * slot_210(struct StateT * v9636);
struct StateT * slot_166(struct StateT * v11906);
struct StateT * slot_51(struct StateT * v10111);
struct StateT * slot_52(struct StateT * v10127);
struct StateT * slot_83(struct StateT * v10613);
struct StateT * slot_25(struct StateT * v5338);
struct StateT * slot_209(struct StateT * v9418);
struct StateT * slot_3(struct StateT * v646);
struct StateT * slot_123(struct StateT * v11237);
struct StateT * slot_73(struct StateT * v10455);
struct StateT * slot_198(struct StateT * v6452);
struct StateT * slot_1(struct StateT * v16);
struct StateT * slot_187(struct StateT * v12233);
struct StateT * slot_97(struct StateT * v10835);
struct StateT * slot_182(struct StateT * v12157);
struct StateT * slot_38(struct StateT * v7429);
struct StateT * slot_178(struct StateT * v12098);
struct StateT * slot_106(struct StateT * v10970);
struct StateT * slot_98(struct StateT * v10850);
struct StateT * slot_159(struct StateT * v11800);
struct StateT * slot_46(struct StateT * v9403);
struct StateT * slot_212(struct StateT * v10076);
struct StateT * slot_132(struct StateT * v11375);
struct StateT * slot_130(struct StateT * v11343);
struct StateT * slot_211(struct StateT * v9856);
struct StateT * slot_20(struct StateT * v4700);
struct StateT * slot_141(struct StateT * v11519);
struct StateT * slot_61(struct StateT * v10271);
struct StateT * slot_30(struct StateT * v5409);
struct StateT * slot_4(struct StateT * v961);
struct StateT * slot_18(struct StateT * v4292);
struct StateT * slot_9(struct StateT * v2536);
struct StateT * slot_183(struct StateT * v12173);
struct StateT * slot_43(struct StateT * v8746);
struct StateT * slot_70(struct StateT * v10407);
struct StateT * slot_168(struct StateT * v11935);
struct StateT * slot_76(struct StateT * v10506);
struct StateT * slot_6(struct StateT * v1591);
struct StateT * slot_55(struct StateT * v10177);
struct StateT * slot_213(struct StateT * v10106);
struct StateT * slot_82(struct StateT * v10597);
struct StateT * slot_161(struct StateT * v11831);
struct StateT * slot_185(struct StateT * v12202);
struct StateT * slot_91(struct StateT * v10735);
struct StateT * slot_58(struct StateT * v10226);
struct StateT * slot_89(struct StateT * v10703);
struct StateT * slot_66(struct StateT * v10346);
struct StateT * slot_140(struct StateT * v11504);
struct StateT * slot_49(struct StateT * v10060);
struct StateT * slot_50(struct StateT * v10090);
struct StateT * slot_37(struct StateT * v7099);
struct StateT * slot_114(struct StateT * v11096);
struct StateT * slot_135(struct StateT * v11425);
struct StateT * slot_59(struct StateT * v10240);
struct StateT * slot_192(struct StateT * v12311);
struct StateT * slot_40(struct StateT * v8089);
struct StateT * slot_48(struct StateT * v9840);
struct StateT * slot_77(struct StateT * v10523);
struct StateT * slot_85(struct StateT * v10642);
struct StateT * slot_75(struct StateT * v10489);
struct StateT * slot_72(struct StateT * v10439);
struct StateT * slot_119(struct StateT * v11176);
struct StateT * slot_71(struct StateT * v10423);
struct StateT * slot_101(struct StateT * v10895);
struct StateT * slot_108(struct StateT * v10999);
struct StateT * slot_116(struct StateT * v11130);
struct StateT * slot_93(struct StateT * v10767);
struct StateT * slot_88(struct StateT * v10687);
struct StateT * slot_96(struct StateT * v10818);
struct StateT * slot_45(struct StateT * v9183);
struct StateT * slot_134(struct StateT * v11408);
struct StateT * slot_175(struct StateT * v12049);
struct StateT * slot_69(struct StateT * v10391);
struct StateT * slot_202(struct StateT * v7774);
struct StateT * slot_188(struct StateT * v12247);
struct StateT * slot_138(struct StateT * v11474);
struct StateT * slot_186(struct StateT * v12218);
struct StateT * slot_102(struct StateT * v10909);
struct StateT * slot_145(struct StateT * v11578);
struct StateT * slot_110(struct StateT * v11031);
struct StateT * slot_196(struct StateT * v5788);
struct StateT * slot_208(struct StateT * v9199);
struct StateT * slot_172(struct StateT * v11999);
struct StateT * slot_131(struct StateT * v11359);
struct StateT * slot_8(struct StateT * v2221);
struct StateT * slot_180(struct StateT * v12128);
struct StateT * slot_203(struct StateT * v8104);
struct StateT * slot_190(struct StateT * v12279);
struct StateT * slot_157(struct StateT * v11771);
struct StateT * slot_200(struct StateT * v7114);
struct StateT * slot_173(struct StateT * v12015);
struct StateT * slot_149(struct StateT * v11639);
struct StateT * slot_5(struct StateT * v1276);
struct StateT * slot_104(struct StateT * v10940);
struct StateT * slot_54(struct StateT * v10160);
struct StateT * slot_26(struct StateT * v5351);
struct StateT * slot_206(struct StateT * v8761);
struct StateT * slot_169(struct StateT * v11951);
struct StateT * slot_64(struct StateT * v10316);
struct StateT * slot_170(struct StateT * v11967);
struct StateT * slot_14(struct StateT * v3476);
struct StateT * slot_53(struct StateT * v10143);
struct StateT * slot_80(struct StateT * v10568);
struct StateT * slot_44(struct StateT * v8965);
struct StateT * slot_137(struct StateT * v11459);
struct StateT * slot_122(struct StateT * v11221);
struct StateT * slot_99(struct StateT * v10864);
struct StateT * slot_179(struct StateT * v12112);
struct StateT * slot_36(struct StateT * v6767);
struct StateT * slot_57(struct StateT * v10211);
struct StateT * slot_62(struct StateT * v10285);
struct StateT * slot_22(struct StateT * v5108);
struct StateT * slot_139(struct StateT * v11488);
struct StateT * slot_23(struct StateT * v5312);
struct StateT * slot_153(struct StateT * v11703);
struct StateT * slot_2(struct StateT * v331);
struct StateT * slot_86(struct StateT * v10658);
struct StateT * slot_129(struct StateT * v11327);
struct StateT * slot_158(struct StateT * v11786);
struct StateT * slot_100(struct StateT * v10880);
struct StateT * slot_127(struct StateT * v11297);
struct StateT * slot_13(struct StateT * v3272);
struct StateT * slot_111(struct StateT * v11047);
struct StateT * slot_109(struct StateT * v11015);
struct StateT * slot_174(struct StateT * v12032);
struct StateT * slot_147(struct StateT * v11609);
struct StateT * slot_42(struct StateT * v8526);
struct StateT * slot_163(struct StateT * v11861);
struct StateT * slot_184(struct StateT * v12188);
struct StateT * slot_204(struct StateT * v8322);
struct StateT * slot_194(struct StateT * v12341);
struct StateT * slot_165(struct StateT * v11890);
struct StateT * snippet(struct StateT * v0);
struct StateT * slot_117(struct StateT * v11147);
struct StateT * slot_90(struct StateT * v10719);
struct StateT * slot_11(struct StateT * v2864);
struct StateT * slot_12(struct StateT * v3068) {
  int v3069 = v3068->timer;
  int v3179 = v3069 + 1;
  v3068->timer = v3179;
  int * v3071 = v3068->regs;
  int v3072 = v3071[12];
  int * v3073 = v3068->cache_tags;
  int v3183 = (((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1)) & 1) * 2;
  int v3074 = v3073[v3183];
  int v3184 = ((((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v3075 = v3073[v3184];
  int v3185 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1)) & 3) * 2);
  int v3076 = v3073[v3185];
  int v3186 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3077 = v3073[v3186];
  int v3078 = v3068->timer;
  int v3187 = v3078 + ((100 ^ (((~(((v3076 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))) | (-(v3076 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3077 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))) | (-(v3077 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3074 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))) | (-(v3074 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3075 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))) | (-(v3075 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3076 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))) | (-(v3076 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3077 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))) | (-(v3077 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v3068->timer = v3187;
  int * v3080 = v3068->cache_vals;
  bool v3188 = !(((~(((v3074 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))) | (-(v3074 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3075 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))) | (-(v3075 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v3173;
  if (v3188) {
    int * v3081 = v3068->cache_age;
    int v3190 = ((((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v3075 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))) | (-(v3075 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v3082 = v3081[v3190];
    int v3083 = v3081[v3183];
    int v3191 = v3083 + ((int)((unsigned int)(v3083 - v3082) >> 31));
    v3081[v3183] = v3191;
    int * v3085 = v3068->cache_age;
    int v3086 = v3085[v3184];
    int v3193 = v3086 + ((int)((unsigned int)(v3086 - v3082) >> 31));
    v3085[v3184] = v3193;
    int * v3088 = v3068->cache_age;
    v3088[v3190] = 0;
    v3173 = v3190;
  } else {
    int * v3091 = v3068->cache_age;
    int v3197 = (((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1)) & 1) * 2;
    int v3092 = v3091[v3197];
    int * v3093 = v3068->cache_tags;
    int v3094 = v3093[v3197];
    int v3095 = v3091[v3184];
    int v3096 = v3093[v3184];
    bool v3199 = !(((~(((v3076 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))) | (-(v3076 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v3077 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))) | (-(v3077 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v3150;
    if (v3199) {
      int * v3097 = v3068->cache_age;
      int v3201 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3077 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))) | (-(v3077 ^ ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v3098 = v3097[v3201];
      int v3099 = v3097[v3185];
      int v3202 = v3099 + ((int)((unsigned int)(v3099 - v3098) >> 31));
      v3097[v3185] = v3202;
      int * v3101 = v3068->cache_age;
      int v3102 = v3101[v3186];
      int v3204 = v3102 + ((int)((unsigned int)(v3102 - v3098) >> 31));
      v3101[v3186] = v3204;
      int * v3104 = v3068->cache_age;
      v3104[v3201] = 0;
      v3150 = v3201;
    } else {
      int * v3107 = v3068->cache_age;
      int v3208 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1)) & 3) * 2);
      int v3108 = v3107[v3208];
      int * v3109 = v3068->cache_tags;
      int v3110 = v3109[v3208];
      int v3111 = v3107[v3186];
      int v3112 = v3109[v3186];
      int * v3113 = v3068->cache_dirty;
      int v3211 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3108 + ((~(((v3110 ^ -1) | (-(v3110 ^ -1))) >> 31)) & 2)) - (v3111 + ((~(((v3112 ^ -1) | (-(v3112 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3114 = v3113[v3211];
      bool v3212 = !(v3114 == 0);
      if (v3212) {
        int * v3115 = v3068->cache_tags;
        int v3116 = v3115[v3211];
        int * v3117 = v3068->cache_vals;
        int v3215 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3108 + ((~(((v3110 ^ -1) | (-(v3110 ^ -1))) >> 31)) & 2)) - (v3111 + ((~(((v3112 ^ -1) | (-(v3112 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3118 = v3117[v3215];
        int v3216 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3108 + ((~(((v3110 ^ -1) | (-(v3110 ^ -1))) >> 31)) & 2)) - (v3111 + ((~(((v3112 ^ -1) | (-(v3112 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3119 = v3117[v3216];
        int * v3120 = v3068->mem;
        int v3218 = v3116 * 2;
        v3120[v3218] = v3118;
        int * v3122 = v3068->mem;
        int v3221 = (v3116 * 2) + 1;
        v3122[v3221] = v3119;
        ;
      } else {
        ;
      }
      int * v3127 = v3068->mem;
      int v3226 = ((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1)) * 2;
      int v3128 = v3127[v3226];
      int v3227 = (((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1)) * 2) + 1;
      int v3129 = v3127[v3227];
      int * v3130 = v3068->cache_vals;
      int v3229 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3108 + ((~(((v3110 ^ -1) | (-(v3110 ^ -1))) >> 31)) & 2)) - (v3111 + ((~(((v3112 ^ -1) | (-(v3112 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3130[v3229] = v3128;
      int * v3132 = v3068->cache_vals;
      int v3232 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v3108 + ((~(((v3110 ^ -1) | (-(v3110 ^ -1))) >> 31)) & 2)) - (v3111 + ((~(((v3112 ^ -1) | (-(v3112 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3132[v3232] = v3129;
      int * v3134 = v3068->cache_tags;
      int v3235 = (int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1);
      v3134[v3211] = v3235;
      int * v3136 = v3068->cache_dirty;
      v3136[v3211] = 0;
      int * v3138 = v3068->cache_age;
      v3138[v3211] = 1;
      int * v3140 = v3068->cache_age;
      int v3141 = v3140[v3211];
      int v3142 = v3140[v3185];
      int v3241 = v3142 + ((int)((unsigned int)(v3142 - v3141) >> 31));
      v3140[v3185] = v3241;
      int * v3144 = v3068->cache_age;
      int v3145 = v3144[v3186];
      int v3243 = v3145 + ((int)((unsigned int)(v3145 - v3141) >> 31));
      v3144[v3186] = v3243;
      int * v3147 = v3068->cache_age;
      v3147[v3211] = 0;
      v3150 = v3211;
    }
    int * v3151 = v3068->cache_vals;
    int v3246 = v3150 * 2;
    int v3152 = v3151[v3246];
    int v3247 = (v3150 * 2) + 1;
    int v3153 = v3151[v3247];
    int v3248 = (((((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v3092 + ((~(((v3094 ^ -1) | (-(v3094 ^ -1))) >> 31)) & 2)) - (v3095 + ((~(((v3096 ^ -1) | (-(v3096 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3151[v3248] = v3152;
    int * v3155 = v3068->cache_vals;
    int v3251 = ((((((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v3092 + ((~(((v3094 ^ -1) | (-(v3094 ^ -1))) >> 31)) & 2)) - (v3095 + ((~(((v3096 ^ -1) | (-(v3096 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3155[v3251] = v3153;
    int * v3157 = v3068->cache_tags;
    int v3254 = ((((int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v3092 + ((~(((v3094 ^ -1) | (-(v3094 ^ -1))) >> 31)) & 2)) - (v3095 + ((~(((v3096 ^ -1) | (-(v3096 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3255 = (int)((unsigned int)((int)((unsigned int)(v3072 + 4) >> 2)) >> 1);
    v3157[v3254] = v3255;
    int * v3159 = v3068->cache_dirty;
    v3159[v3254] = 0;
    int * v3161 = v3068->cache_age;
    v3161[v3254] = 1;
    int * v3163 = v3068->cache_age;
    int v3164 = v3163[v3254];
    int v3165 = v3163[v3183];
    int v3261 = v3165 + ((int)((unsigned int)(v3165 - v3164) >> 31));
    v3163[v3183] = v3261;
    int * v3167 = v3068->cache_age;
    int v3168 = v3167[v3184];
    int v3263 = v3168 + ((int)((unsigned int)(v3168 - v3164) >> 31));
    v3167[v3184] = v3263;
    int * v3170 = v3068->cache_age;
    v3170[v3254] = 0;
    v3173 = v3254;
  }
  int v3266 = (v3173 * 2) + (((int)((unsigned int)(v3072 + 4) >> 2)) & 1);
  int v3174 = v3080[v3266];
  int * v3175 = v3068->regs;
  v3175[17] = v3174;
  struct StateT * v3177 = slot_13(v3068);
  return v3177;
}

struct StateT * slot_143(struct StateT * v11549) {
  int v11550 = v11549->timer;
  int v11557 = v11550 + 1;
  v11549->timer = v11557;
  int * v11552 = v11549->regs;
  int v11553 = v11552[22];
  int v11561 = (int)((unsigned int)v11553 >> 23);
  v11552[24] = v11561;
  struct StateT * v11555 = slot_144(v11549);
  return v11555;
}

struct StateT * slot_120(struct StateT * v11192) {
  int v11193 = v11192->timer;
  int v11200 = v11193 + 1;
  v11192->timer = v11200;
  int * v11195 = v11192->regs;
  int v11196 = v11195[21];
  int v11204 = (int)((unsigned int)v11196 >> 25);
  v11195[24] = v11204;
  struct StateT * v11198 = slot_121(v11192);
  return v11198;
}

struct StateT * slot_167(struct StateT * v11921) {
  int v11922 = v11921->timer;
  int v11929 = v11922 + 1;
  v11921->timer = v11929;
  int * v11924 = v11921->regs;
  int v11925 = v11924[23];
  int v11932 = v11925 << 13;
  v11924[23] = v11932;
  struct StateT * v11927 = slot_168(v11921);
  return v11927;
}

struct StateT * slot_152(struct StateT * v11687) {
  int v11688 = v11687->timer;
  int v11696 = v11688 + 1;
  v11687->timer = v11696;
  int * v11690 = v11687->regs;
  int v11691 = v11690[7];
  int v11692 = v11690[23];
  int v11700 = v11691 ^ v11692;
  v11690[7] = v11700;
  struct StateT * v11694 = slot_153(v11687);
  return v11694;
}

struct StateT * slot_199(struct StateT * v6784) {
  int v6785 = v6784->timer;
  int v6955 = v6785 + 1;
  v6784->timer = v6955;
  int * v6787 = v6784->regs;
  int v6788 = v6787[10];
  int v6789 = v6787[12];
  int * v6790 = v6784->cache_tags;
  int v6960 = (((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1)) & 1) * 2;
  int v6791 = v6790[v6960];
  int v6961 = ((((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v6792 = v6790[v6961];
  int v6962 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1)) & 3) * 2);
  int v6793 = v6790[v6962];
  int v6963 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v6794 = v6790[v6963];
  int v6795 = v6784->timer;
  int v6964 = v6795 + ((100 ^ (((~(((v6793 ^ ((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1))) | (-(v6793 ^ ((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v6794 ^ ((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1))) | (-(v6794 ^ ((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v6791 ^ ((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1))) | (-(v6791 ^ ((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v6792 ^ ((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1))) | (-(v6792 ^ ((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v6793 ^ ((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1))) | (-(v6793 ^ ((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v6794 ^ ((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1))) | (-(v6794 ^ ((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v6784->timer = v6964;
  bool v6965 = !(((~(((v6791 ^ ((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1))) | (-(v6791 ^ ((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v6792 ^ ((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1))) | (-(v6792 ^ ((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v6889;
  if (v6965) {
    int * v6797 = v6784->cache_age;
    int v6967 = ((((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v6792 ^ ((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1))) | (-(v6792 ^ ((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v6798 = v6797[v6967];
    int v6799 = v6797[v6960];
    int v6968 = v6799 + ((int)((unsigned int)(v6799 - v6798) >> 31));
    v6797[v6960] = v6968;
    int * v6801 = v6784->cache_age;
    int v6802 = v6801[v6961];
    int v6970 = v6802 + ((int)((unsigned int)(v6802 - v6798) >> 31));
    v6801[v6961] = v6970;
    int * v6804 = v6784->cache_age;
    v6804[v6967] = 0;
    v6889 = v6967;
  } else {
    int * v6807 = v6784->cache_age;
    int v6974 = (((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1)) & 1) * 2;
    int v6808 = v6807[v6974];
    int * v6809 = v6784->cache_tags;
    int v6810 = v6809[v6974];
    int v6811 = v6807[v6961];
    int v6812 = v6809[v6961];
    bool v6976 = !(((~(((v6793 ^ ((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1))) | (-(v6793 ^ ((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v6794 ^ ((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1))) | (-(v6794 ^ ((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v6866;
    if (v6976) {
      int * v6813 = v6784->cache_age;
      int v6978 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v6794 ^ ((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1))) | (-(v6794 ^ ((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v6814 = v6813[v6978];
      int v6815 = v6813[v6962];
      int v6979 = v6815 + ((int)((unsigned int)(v6815 - v6814) >> 31));
      v6813[v6962] = v6979;
      int * v6817 = v6784->cache_age;
      int v6818 = v6817[v6963];
      int v6981 = v6818 + ((int)((unsigned int)(v6818 - v6814) >> 31));
      v6817[v6963] = v6981;
      int * v6820 = v6784->cache_age;
      v6820[v6978] = 0;
      v6866 = v6978;
    } else {
      int * v6823 = v6784->cache_age;
      int v6985 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1)) & 3) * 2);
      int v6824 = v6823[v6985];
      int * v6825 = v6784->cache_tags;
      int v6826 = v6825[v6985];
      int v6827 = v6823[v6963];
      int v6828 = v6825[v6963];
      int * v6829 = v6784->cache_dirty;
      int v6988 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v6824 + ((~(((v6826 ^ -1) | (-(v6826 ^ -1))) >> 31)) & 2)) - (v6827 + ((~(((v6828 ^ -1) | (-(v6828 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v6830 = v6829[v6988];
      bool v6989 = !(v6830 == 0);
      if (v6989) {
        int * v6831 = v6784->cache_tags;
        int v6832 = v6831[v6988];
        int * v6833 = v6784->cache_vals;
        int v6992 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v6824 + ((~(((v6826 ^ -1) | (-(v6826 ^ -1))) >> 31)) & 2)) - (v6827 + ((~(((v6828 ^ -1) | (-(v6828 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v6834 = v6833[v6992];
        int v6993 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v6824 + ((~(((v6826 ^ -1) | (-(v6826 ^ -1))) >> 31)) & 2)) - (v6827 + ((~(((v6828 ^ -1) | (-(v6828 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v6835 = v6833[v6993];
        int * v6836 = v6784->mem;
        int v6995 = v6832 * 2;
        v6836[v6995] = v6834;
        int * v6838 = v6784->mem;
        int v6998 = (v6832 * 2) + 1;
        v6838[v6998] = v6835;
        ;
      } else {
        ;
      }
      int * v6843 = v6784->mem;
      int v7003 = ((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1)) * 2;
      int v6844 = v6843[v7003];
      int v7004 = (((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1)) * 2) + 1;
      int v6845 = v6843[v7004];
      int * v6846 = v6784->cache_vals;
      int v7006 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v6824 + ((~(((v6826 ^ -1) | (-(v6826 ^ -1))) >> 31)) & 2)) - (v6827 + ((~(((v6828 ^ -1) | (-(v6828 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v6846[v7006] = v6844;
      int * v6848 = v6784->cache_vals;
      int v7009 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v6824 + ((~(((v6826 ^ -1) | (-(v6826 ^ -1))) >> 31)) & 2)) - (v6827 + ((~(((v6828 ^ -1) | (-(v6828 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v6848[v7009] = v6845;
      int * v6850 = v6784->cache_tags;
      int v7012 = (int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1);
      v6850[v6988] = v7012;
      int * v6852 = v6784->cache_dirty;
      v6852[v6988] = 0;
      int * v6854 = v6784->cache_age;
      v6854[v6988] = 1;
      int * v6856 = v6784->cache_age;
      int v6857 = v6856[v6988];
      int v6858 = v6856[v6962];
      int v7018 = v6858 + ((int)((unsigned int)(v6858 - v6857) >> 31));
      v6856[v6962] = v7018;
      int * v6860 = v6784->cache_age;
      int v6861 = v6860[v6963];
      int v7020 = v6861 + ((int)((unsigned int)(v6861 - v6857) >> 31));
      v6860[v6963] = v7020;
      int * v6863 = v6784->cache_age;
      v6863[v6988] = 0;
      v6866 = v6988;
    }
    int * v6867 = v6784->cache_vals;
    int v7023 = v6866 * 2;
    int v6868 = v6867[v7023];
    int v7024 = (v6866 * 2) + 1;
    int v6869 = v6867[v7024];
    int v7025 = (((((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v6808 + ((~(((v6810 ^ -1) | (-(v6810 ^ -1))) >> 31)) & 2)) - (v6811 + ((~(((v6812 ^ -1) | (-(v6812 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6867[v7025] = v6868;
    int * v6871 = v6784->cache_vals;
    int v7028 = ((((((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v6808 + ((~(((v6810 ^ -1) | (-(v6810 ^ -1))) >> 31)) & 2)) - (v6811 + ((~(((v6812 ^ -1) | (-(v6812 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6871[v7028] = v6869;
    int * v6873 = v6784->cache_tags;
    int v7031 = ((((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v6808 + ((~(((v6810 ^ -1) | (-(v6810 ^ -1))) >> 31)) & 2)) - (v6811 + ((~(((v6812 ^ -1) | (-(v6812 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7032 = (int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1);
    v6873[v7031] = v7032;
    int * v6875 = v6784->cache_dirty;
    v6875[v7031] = 0;
    int * v6877 = v6784->cache_age;
    v6877[v7031] = 1;
    int * v6879 = v6784->cache_age;
    int v6880 = v6879[v7031];
    int v6881 = v6879[v6960];
    int v7038 = v6881 + ((int)((unsigned int)(v6881 - v6880) >> 31));
    v6879[v6960] = v7038;
    int * v6883 = v6784->cache_age;
    int v6884 = v6883[v6961];
    int v7040 = v6884 + ((int)((unsigned int)(v6884 - v6880) >> 31));
    v6883[v6961] = v7040;
    int * v6886 = v6784->cache_age;
    v6886[v7031] = 0;
    v6889 = v7031;
  }
  int * v6890 = v6784->cache_vals;
  int v7043 = (v6889 * 2) + (((int)((unsigned int)(v6788 + 16) >> 2)) & 1);
  v6890[v7043] = v6789;
  int * v6892 = v6784->cache_tags;
  int v6893 = v6892[v6962];
  int v6894 = v6892[v6963];
  bool v7046 = !(((~(((v6893 ^ ((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1))) | (-(v6893 ^ ((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v6894 ^ ((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1))) | (-(v6894 ^ ((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v6948;
  if (v7046) {
    int * v6895 = v6784->cache_age;
    int v7048 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v6894 ^ ((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1))) | (-(v6894 ^ ((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v6896 = v6895[v7048];
    int v6897 = v6895[v6962];
    int v7049 = v6897 + ((int)((unsigned int)(v6897 - v6896) >> 31));
    v6895[v6962] = v7049;
    int * v6899 = v6784->cache_age;
    int v6900 = v6899[v6963];
    int v7051 = v6900 + ((int)((unsigned int)(v6900 - v6896) >> 31));
    v6899[v6963] = v7051;
    int * v6902 = v6784->cache_age;
    v6902[v7048] = 0;
    v6948 = v7048;
  } else {
    int * v6905 = v6784->cache_age;
    int v7055 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1)) & 3) * 2);
    int v6906 = v6905[v7055];
    int * v6907 = v6784->cache_tags;
    int v6908 = v6907[v7055];
    int v6909 = v6905[v6963];
    int v6910 = v6907[v6963];
    int * v6911 = v6784->cache_dirty;
    int v7058 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v6906 + ((~(((v6908 ^ -1) | (-(v6908 ^ -1))) >> 31)) & 2)) - (v6909 + ((~(((v6910 ^ -1) | (-(v6910 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6912 = v6911[v7058];
    bool v7059 = !(v6912 == 0);
    if (v7059) {
      int * v6913 = v6784->cache_tags;
      int v6914 = v6913[v7058];
      int * v6915 = v6784->cache_vals;
      int v7062 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v6906 + ((~(((v6908 ^ -1) | (-(v6908 ^ -1))) >> 31)) & 2)) - (v6909 + ((~(((v6910 ^ -1) | (-(v6910 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v6916 = v6915[v7062];
      int v7063 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v6906 + ((~(((v6908 ^ -1) | (-(v6908 ^ -1))) >> 31)) & 2)) - (v6909 + ((~(((v6910 ^ -1) | (-(v6910 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v6917 = v6915[v7063];
      int * v6918 = v6784->mem;
      int v7065 = v6914 * 2;
      v6918[v7065] = v6916;
      int * v6920 = v6784->mem;
      int v7068 = (v6914 * 2) + 1;
      v6920[v7068] = v6917;
      ;
    } else {
      ;
    }
    int * v6925 = v6784->mem;
    int v7073 = ((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1)) * 2;
    int v6926 = v6925[v7073];
    int v7074 = (((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1)) * 2) + 1;
    int v6927 = v6925[v7074];
    int * v6928 = v6784->cache_vals;
    int v7076 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v6906 + ((~(((v6908 ^ -1) | (-(v6908 ^ -1))) >> 31)) & 2)) - (v6909 + ((~(((v6910 ^ -1) | (-(v6910 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6928[v7076] = v6926;
    int * v6930 = v6784->cache_vals;
    int v7079 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v6906 + ((~(((v6908 ^ -1) | (-(v6908 ^ -1))) >> 31)) & 2)) - (v6909 + ((~(((v6910 ^ -1) | (-(v6910 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6930[v7079] = v6927;
    int * v6932 = v6784->cache_tags;
    int v7082 = (int)((unsigned int)((int)((unsigned int)(v6788 + 16) >> 2)) >> 1);
    v6932[v7058] = v7082;
    int * v6934 = v6784->cache_dirty;
    v6934[v7058] = 0;
    int * v6936 = v6784->cache_age;
    v6936[v7058] = 1;
    int * v6938 = v6784->cache_age;
    int v6939 = v6938[v7058];
    int v6940 = v6938[v6962];
    int v7088 = v6940 + ((int)((unsigned int)(v6940 - v6939) >> 31));
    v6938[v6962] = v7088;
    int * v6942 = v6784->cache_age;
    int v6943 = v6942[v6963];
    int v7090 = v6943 + ((int)((unsigned int)(v6943 - v6939) >> 31));
    v6942[v6963] = v7090;
    int * v6945 = v6784->cache_age;
    v6945[v7058] = 0;
    v6948 = v7058;
  }
  int * v6949 = v6784->cache_vals;
  int v7093 = (v6948 * 2) + (((int)((unsigned int)(v6788 + 16) >> 2)) & 1);
  v6949[v7093] = v6789;
  int * v6951 = v6784->cache_dirty;
  v6951[v6948] = 1;
  struct StateT * v6953 = slot_200(v6784);
  return v6953;
}

struct StateT * slot_92(struct StateT * v10751) {
  int v10752 = v10751->timer;
  int v10760 = v10752 + 1;
  v10751->timer = v10760;
  int * v10754 = v10751->regs;
  int v10755 = v10754[15];
  int v10756 = v10754[23];
  int v10764 = v10755 ^ v10756;
  v10754[15] = v10764;
  struct StateT * v10758 = slot_93(v10751);
  return v10758;
}

struct StateT * slot_31(struct StateT * v5423) {
  int v5424 = v5423->timer;
  int v5430 = v5424 + 1;
  v5423->timer = v5430;
  int * v5426 = v5423->regs;
  v5426[11] = 9;
  struct StateT * v5428 = slot_32(v5423);
  return v5428;
}

struct StateT * slot_160(struct StateT * v11816) {
  int v11817 = v11816->timer;
  int v11824 = v11817 + 1;
  v11816->timer = v11824;
  int * v11819 = v11816->regs;
  int v11820 = v11819[21];
  int v11828 = (int)((unsigned int)v11820 >> 19);
  v11819[24] = v11828;
  struct StateT * v11822 = slot_161(v11816);
  return v11822;
}

struct StateT * slot_65(struct StateT * v10330) {
  int v10331 = v10330->timer;
  int v10339 = v10331 + 1;
  v10330->timer = v10339;
  int * v10333 = v10330->regs;
  int v10334 = v10333[22];
  int v10335 = v10333[24];
  int v10343 = v10334 | v10335;
  v10333[22] = v10343;
  struct StateT * v10337 = slot_66(v10330);
  return v10337;
}

struct StateT * slot_10(struct StateT * v2851) {
  int v2852 = v2851->timer;
  int v2858 = v2852 + 1;
  v2851->timer = v2858;
  int * v2854 = v2851->regs;
  v2854[13] = 0;
  struct StateT * v2856 = slot_11(v2851);
  return v2856;
}

struct StateT * slot_150(struct StateT * v11655) {
  int v11656 = v11655->timer;
  int v11664 = v11656 + 1;
  v11655->timer = v11664;
  int * v11658 = v11655->regs;
  int v11659 = v11658[5];
  int v11660 = v11658[21];
  int v11668 = v11659 ^ v11660;
  v11658[5] = v11668;
  struct StateT * v11662 = slot_151(v11655);
  return v11662;
}

struct StateT * slot_74(struct StateT * v10472) {
  int v10473 = v10472->timer;
  int v10481 = v10473 + 1;
  v10472->timer = v10481;
  int * v10475 = v10472->regs;
  int v10476 = v10475[7];
  int v10477 = v10475[18];
  int v10486 = v10476 + v10477;
  v10475[21] = v10486;
  struct StateT * v10479 = slot_75(v10472);
  return v10479;
}

struct StateT * slot_107(struct StateT * v10985) {
  int v10986 = v10985->timer;
  int v10993 = v10986 + 1;
  v10985->timer = v10993;
  int * v10988 = v10985->regs;
  int v10989 = v10988[23];
  int v10996 = v10989 << 18;
  v10988[23] = v10996;
  struct StateT * v10991 = slot_108(v10985);
  return v10991;
}

struct StateT * slot_136(struct StateT * v11442) {
  int v11443 = v11442->timer;
  int v11451 = v11443 + 1;
  v11442->timer = v11451;
  int * v11445 = v11442->regs;
  int v11446 = v11445[16];
  int v11447 = v11445[31];
  int v11456 = v11446 + v11447;
  v11445[23] = v11456;
  struct StateT * v11449 = slot_137(v11442);
  return v11449;
}

struct StateT * slot_84(struct StateT * v10628) {
  int v10629 = v10628->timer;
  int v10636 = v10629 + 1;
  v10628->timer = v10636;
  int * v10631 = v10628->regs;
  int v10632 = v10631[22];
  int v10639 = v10632 << 13;
  v10631[22] = v10639;
  struct StateT * v10634 = slot_85(v10628);
  return v10634;
}

struct StateT * slot_28(struct StateT * v5381) {
  int v5382 = v5381->timer;
  int v5389 = v5382 + 1;
  v5381->timer = v5389;
  int * v5384 = v5381->regs;
  int v5385 = v5384[31];
  int v5393 = v5385 + -718;
  v5384[28] = v5393;
  struct StateT * v5387 = slot_29(v5381);
  return v5387;
}

struct StateT * slot_155(struct StateT * v11737) {
  int v11738 = v11737->timer;
  int v11746 = v11738 + 1;
  v11737->timer = v11746;
  int * v11740 = v11737->regs;
  int v11741 = v11740[6];
  int v11742 = v11740[15];
  int v11751 = v11741 + v11742;
  v11740[22] = v11751;
  struct StateT * v11744 = slot_156(v11737);
  return v11744;
}

struct StateT * slot_177(struct StateT * v12083) {
  int v12084 = v12083->timer;
  int v12091 = v12084 + 1;
  v12083->timer = v12091;
  int * v12086 = v12083->regs;
  int v12087 = v12086[20];
  int v12095 = (int)((unsigned int)v12087 >> 14);
  v12086[24] = v12095;
  struct StateT * v12089 = slot_178(v12083);
  return v12089;
}

struct StateT * slot_17(struct StateT * v4088) {
  int v4089 = v4088->timer;
  int v4199 = v4089 + 1;
  v4088->timer = v4199;
  int * v4091 = v4088->regs;
  int v4092 = v4091[12];
  int * v4093 = v4088->cache_tags;
  int v4203 = (((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1)) & 1) * 2;
  int v4094 = v4093[v4203];
  int v4204 = ((((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4095 = v4093[v4204];
  int v4205 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1)) & 3) * 2);
  int v4096 = v4093[v4205];
  int v4206 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4097 = v4093[v4206];
  int v4098 = v4088->timer;
  int v4207 = v4098 + ((100 ^ (((~(((v4096 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))) | (-(v4096 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v4097 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))) | (-(v4097 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4094 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))) | (-(v4094 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v4095 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))) | (-(v4095 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4096 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))) | (-(v4096 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v4097 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))) | (-(v4097 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4088->timer = v4207;
  int * v4100 = v4088->cache_vals;
  bool v4208 = !(((~(((v4094 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))) | (-(v4094 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v4095 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))) | (-(v4095 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v4193;
  if (v4208) {
    int * v4101 = v4088->cache_age;
    int v4210 = ((((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1)) & 1) * 2) + ((~(((v4095 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))) | (-(v4095 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v4102 = v4101[v4210];
    int v4103 = v4101[v4203];
    int v4211 = v4103 + ((int)((unsigned int)(v4103 - v4102) >> 31));
    v4101[v4203] = v4211;
    int * v4105 = v4088->cache_age;
    int v4106 = v4105[v4204];
    int v4213 = v4106 + ((int)((unsigned int)(v4106 - v4102) >> 31));
    v4105[v4204] = v4213;
    int * v4108 = v4088->cache_age;
    v4108[v4210] = 0;
    v4193 = v4210;
  } else {
    int * v4111 = v4088->cache_age;
    int v4217 = (((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1)) & 1) * 2;
    int v4112 = v4111[v4217];
    int * v4113 = v4088->cache_tags;
    int v4114 = v4113[v4217];
    int v4115 = v4111[v4204];
    int v4116 = v4113[v4204];
    bool v4219 = !(((~(((v4096 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))) | (-(v4096 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v4097 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))) | (-(v4097 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))))) >> 31))) == 0);
    int v4170;
    if (v4219) {
      int * v4117 = v4088->cache_age;
      int v4221 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4097 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))) | (-(v4097 ^ ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1))))) >> 31)) & 1);
      int v4118 = v4117[v4221];
      int v4119 = v4117[v4205];
      int v4222 = v4119 + ((int)((unsigned int)(v4119 - v4118) >> 31));
      v4117[v4205] = v4222;
      int * v4121 = v4088->cache_age;
      int v4122 = v4121[v4206];
      int v4224 = v4122 + ((int)((unsigned int)(v4122 - v4118) >> 31));
      v4121[v4206] = v4224;
      int * v4124 = v4088->cache_age;
      v4124[v4221] = 0;
      v4170 = v4221;
    } else {
      int * v4127 = v4088->cache_age;
      int v4228 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1)) & 3) * 2);
      int v4128 = v4127[v4228];
      int * v4129 = v4088->cache_tags;
      int v4130 = v4129[v4228];
      int v4131 = v4127[v4206];
      int v4132 = v4129[v4206];
      int * v4133 = v4088->cache_dirty;
      int v4231 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v4128 + ((~(((v4130 ^ -1) | (-(v4130 ^ -1))) >> 31)) & 2)) - (v4131 + ((~(((v4132 ^ -1) | (-(v4132 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4134 = v4133[v4231];
      bool v4232 = !(v4134 == 0);
      if (v4232) {
        int * v4135 = v4088->cache_tags;
        int v4136 = v4135[v4231];
        int * v4137 = v4088->cache_vals;
        int v4235 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v4128 + ((~(((v4130 ^ -1) | (-(v4130 ^ -1))) >> 31)) & 2)) - (v4131 + ((~(((v4132 ^ -1) | (-(v4132 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4138 = v4137[v4235];
        int v4236 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v4128 + ((~(((v4130 ^ -1) | (-(v4130 ^ -1))) >> 31)) & 2)) - (v4131 + ((~(((v4132 ^ -1) | (-(v4132 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4139 = v4137[v4236];
        int * v4140 = v4088->mem;
        int v4238 = v4136 * 2;
        v4140[v4238] = v4138;
        int * v4142 = v4088->mem;
        int v4241 = (v4136 * 2) + 1;
        v4142[v4241] = v4139;
        ;
      } else {
        ;
      }
      int * v4147 = v4088->mem;
      int v4246 = ((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1)) * 2;
      int v4148 = v4147[v4246];
      int v4247 = (((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1)) * 2) + 1;
      int v4149 = v4147[v4247];
      int * v4150 = v4088->cache_vals;
      int v4249 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v4128 + ((~(((v4130 ^ -1) | (-(v4130 ^ -1))) >> 31)) & 2)) - (v4131 + ((~(((v4132 ^ -1) | (-(v4132 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4150[v4249] = v4148;
      int * v4152 = v4088->cache_vals;
      int v4252 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v4128 + ((~(((v4130 ^ -1) | (-(v4130 ^ -1))) >> 31)) & 2)) - (v4131 + ((~(((v4132 ^ -1) | (-(v4132 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4152[v4252] = v4149;
      int * v4154 = v4088->cache_tags;
      int v4255 = (int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1);
      v4154[v4231] = v4255;
      int * v4156 = v4088->cache_dirty;
      v4156[v4231] = 0;
      int * v4158 = v4088->cache_age;
      v4158[v4231] = 1;
      int * v4160 = v4088->cache_age;
      int v4161 = v4160[v4231];
      int v4162 = v4160[v4205];
      int v4261 = v4162 + ((int)((unsigned int)(v4162 - v4161) >> 31));
      v4160[v4205] = v4261;
      int * v4164 = v4088->cache_age;
      int v4165 = v4164[v4206];
      int v4263 = v4165 + ((int)((unsigned int)(v4165 - v4161) >> 31));
      v4164[v4206] = v4263;
      int * v4167 = v4088->cache_age;
      v4167[v4231] = 0;
      v4170 = v4231;
    }
    int * v4171 = v4088->cache_vals;
    int v4266 = v4170 * 2;
    int v4172 = v4171[v4266];
    int v4267 = (v4170 * 2) + 1;
    int v4173 = v4171[v4267];
    int v4268 = (((((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v4112 + ((~(((v4114 ^ -1) | (-(v4114 ^ -1))) >> 31)) & 2)) - (v4115 + ((~(((v4116 ^ -1) | (-(v4116 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4171[v4268] = v4172;
    int * v4175 = v4088->cache_vals;
    int v4271 = ((((((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v4112 + ((~(((v4114 ^ -1) | (-(v4114 ^ -1))) >> 31)) & 2)) - (v4115 + ((~(((v4116 ^ -1) | (-(v4116 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4175[v4271] = v4173;
    int * v4177 = v4088->cache_tags;
    int v4274 = ((((int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v4112 + ((~(((v4114 ^ -1) | (-(v4114 ^ -1))) >> 31)) & 2)) - (v4115 + ((~(((v4116 ^ -1) | (-(v4116 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4275 = (int)((unsigned int)((int)((unsigned int)(v4092 + 24) >> 2)) >> 1);
    v4177[v4274] = v4275;
    int * v4179 = v4088->cache_dirty;
    v4179[v4274] = 0;
    int * v4181 = v4088->cache_age;
    v4181[v4274] = 1;
    int * v4183 = v4088->cache_age;
    int v4184 = v4183[v4274];
    int v4185 = v4183[v4203];
    int v4281 = v4185 + ((int)((unsigned int)(v4185 - v4184) >> 31));
    v4183[v4203] = v4281;
    int * v4187 = v4088->cache_age;
    int v4188 = v4187[v4204];
    int v4283 = v4188 + ((int)((unsigned int)(v4188 - v4184) >> 31));
    v4187[v4204] = v4283;
    int * v4190 = v4088->cache_age;
    v4190[v4274] = 0;
    v4193 = v4274;
  }
  int v4286 = (v4193 * 2) + (((int)((unsigned int)(v4092 + 24) >> 2)) & 1);
  int v4194 = v4100[v4286];
  int * v4195 = v4088->regs;
  v4195[7] = v4194;
  struct StateT * v4197 = slot_18(v4088);
  return v4197;
}

struct StateT * slot_181(struct StateT * v12143) {
  int v12144 = v12143->timer;
  int v12151 = v12144 + 1;
  v12143->timer = v12151;
  int * v12146 = v12143->regs;
  int v12147 = v12146[21];
  int v12154 = v12147 << 18;
  v12146[21] = v12154;
  struct StateT * v12149 = slot_182(v12143);
  return v12149;
}

struct StateT * slot_197(struct StateT * v6120) {
  int v6121 = v6120->timer;
  int v6291 = v6121 + 1;
  v6120->timer = v6291;
  int * v6123 = v6120->regs;
  int v6124 = v6123[10];
  int v6125 = v6123[28];
  int * v6126 = v6120->cache_tags;
  int v6296 = (((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1)) & 1) * 2;
  int v6127 = v6126[v6296];
  int v6297 = ((((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v6128 = v6126[v6297];
  int v6298 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1)) & 3) * 2);
  int v6129 = v6126[v6298];
  int v6299 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v6130 = v6126[v6299];
  int v6131 = v6120->timer;
  int v6300 = v6131 + ((100 ^ (((~(((v6129 ^ ((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1))) | (-(v6129 ^ ((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v6130 ^ ((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1))) | (-(v6130 ^ ((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v6127 ^ ((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1))) | (-(v6127 ^ ((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v6128 ^ ((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1))) | (-(v6128 ^ ((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v6129 ^ ((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1))) | (-(v6129 ^ ((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v6130 ^ ((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1))) | (-(v6130 ^ ((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v6120->timer = v6300;
  bool v6301 = !(((~(((v6127 ^ ((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1))) | (-(v6127 ^ ((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v6128 ^ ((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1))) | (-(v6128 ^ ((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v6225;
  if (v6301) {
    int * v6133 = v6120->cache_age;
    int v6303 = ((((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v6128 ^ ((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1))) | (-(v6128 ^ ((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v6134 = v6133[v6303];
    int v6135 = v6133[v6296];
    int v6304 = v6135 + ((int)((unsigned int)(v6135 - v6134) >> 31));
    v6133[v6296] = v6304;
    int * v6137 = v6120->cache_age;
    int v6138 = v6137[v6297];
    int v6306 = v6138 + ((int)((unsigned int)(v6138 - v6134) >> 31));
    v6137[v6297] = v6306;
    int * v6140 = v6120->cache_age;
    v6140[v6303] = 0;
    v6225 = v6303;
  } else {
    int * v6143 = v6120->cache_age;
    int v6310 = (((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1)) & 1) * 2;
    int v6144 = v6143[v6310];
    int * v6145 = v6120->cache_tags;
    int v6146 = v6145[v6310];
    int v6147 = v6143[v6297];
    int v6148 = v6145[v6297];
    bool v6312 = !(((~(((v6129 ^ ((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1))) | (-(v6129 ^ ((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v6130 ^ ((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1))) | (-(v6130 ^ ((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v6202;
    if (v6312) {
      int * v6149 = v6120->cache_age;
      int v6314 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v6130 ^ ((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1))) | (-(v6130 ^ ((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v6150 = v6149[v6314];
      int v6151 = v6149[v6298];
      int v6315 = v6151 + ((int)((unsigned int)(v6151 - v6150) >> 31));
      v6149[v6298] = v6315;
      int * v6153 = v6120->cache_age;
      int v6154 = v6153[v6299];
      int v6317 = v6154 + ((int)((unsigned int)(v6154 - v6150) >> 31));
      v6153[v6299] = v6317;
      int * v6156 = v6120->cache_age;
      v6156[v6314] = 0;
      v6202 = v6314;
    } else {
      int * v6159 = v6120->cache_age;
      int v6321 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1)) & 3) * 2);
      int v6160 = v6159[v6321];
      int * v6161 = v6120->cache_tags;
      int v6162 = v6161[v6321];
      int v6163 = v6159[v6299];
      int v6164 = v6161[v6299];
      int * v6165 = v6120->cache_dirty;
      int v6324 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v6160 + ((~(((v6162 ^ -1) | (-(v6162 ^ -1))) >> 31)) & 2)) - (v6163 + ((~(((v6164 ^ -1) | (-(v6164 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v6166 = v6165[v6324];
      bool v6325 = !(v6166 == 0);
      if (v6325) {
        int * v6167 = v6120->cache_tags;
        int v6168 = v6167[v6324];
        int * v6169 = v6120->cache_vals;
        int v6328 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v6160 + ((~(((v6162 ^ -1) | (-(v6162 ^ -1))) >> 31)) & 2)) - (v6163 + ((~(((v6164 ^ -1) | (-(v6164 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v6170 = v6169[v6328];
        int v6329 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v6160 + ((~(((v6162 ^ -1) | (-(v6162 ^ -1))) >> 31)) & 2)) - (v6163 + ((~(((v6164 ^ -1) | (-(v6164 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v6171 = v6169[v6329];
        int * v6172 = v6120->mem;
        int v6331 = v6168 * 2;
        v6172[v6331] = v6170;
        int * v6174 = v6120->mem;
        int v6334 = (v6168 * 2) + 1;
        v6174[v6334] = v6171;
        ;
      } else {
        ;
      }
      int * v6179 = v6120->mem;
      int v6339 = ((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1)) * 2;
      int v6180 = v6179[v6339];
      int v6340 = (((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1)) * 2) + 1;
      int v6181 = v6179[v6340];
      int * v6182 = v6120->cache_vals;
      int v6342 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v6160 + ((~(((v6162 ^ -1) | (-(v6162 ^ -1))) >> 31)) & 2)) - (v6163 + ((~(((v6164 ^ -1) | (-(v6164 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v6182[v6342] = v6180;
      int * v6184 = v6120->cache_vals;
      int v6345 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v6160 + ((~(((v6162 ^ -1) | (-(v6162 ^ -1))) >> 31)) & 2)) - (v6163 + ((~(((v6164 ^ -1) | (-(v6164 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v6184[v6345] = v6181;
      int * v6186 = v6120->cache_tags;
      int v6348 = (int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1);
      v6186[v6324] = v6348;
      int * v6188 = v6120->cache_dirty;
      v6188[v6324] = 0;
      int * v6190 = v6120->cache_age;
      v6190[v6324] = 1;
      int * v6192 = v6120->cache_age;
      int v6193 = v6192[v6324];
      int v6194 = v6192[v6298];
      int v6354 = v6194 + ((int)((unsigned int)(v6194 - v6193) >> 31));
      v6192[v6298] = v6354;
      int * v6196 = v6120->cache_age;
      int v6197 = v6196[v6299];
      int v6356 = v6197 + ((int)((unsigned int)(v6197 - v6193) >> 31));
      v6196[v6299] = v6356;
      int * v6199 = v6120->cache_age;
      v6199[v6324] = 0;
      v6202 = v6324;
    }
    int * v6203 = v6120->cache_vals;
    int v6359 = v6202 * 2;
    int v6204 = v6203[v6359];
    int v6360 = (v6202 * 2) + 1;
    int v6205 = v6203[v6360];
    int v6361 = (((((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v6144 + ((~(((v6146 ^ -1) | (-(v6146 ^ -1))) >> 31)) & 2)) - (v6147 + ((~(((v6148 ^ -1) | (-(v6148 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6203[v6361] = v6204;
    int * v6207 = v6120->cache_vals;
    int v6364 = ((((((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v6144 + ((~(((v6146 ^ -1) | (-(v6146 ^ -1))) >> 31)) & 2)) - (v6147 + ((~(((v6148 ^ -1) | (-(v6148 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6207[v6364] = v6205;
    int * v6209 = v6120->cache_tags;
    int v6367 = ((((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v6144 + ((~(((v6146 ^ -1) | (-(v6146 ^ -1))) >> 31)) & 2)) - (v6147 + ((~(((v6148 ^ -1) | (-(v6148 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6368 = (int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1);
    v6209[v6367] = v6368;
    int * v6211 = v6120->cache_dirty;
    v6211[v6367] = 0;
    int * v6213 = v6120->cache_age;
    v6213[v6367] = 1;
    int * v6215 = v6120->cache_age;
    int v6216 = v6215[v6367];
    int v6217 = v6215[v6296];
    int v6374 = v6217 + ((int)((unsigned int)(v6217 - v6216) >> 31));
    v6215[v6296] = v6374;
    int * v6219 = v6120->cache_age;
    int v6220 = v6219[v6297];
    int v6376 = v6220 + ((int)((unsigned int)(v6220 - v6216) >> 31));
    v6219[v6297] = v6376;
    int * v6222 = v6120->cache_age;
    v6222[v6367] = 0;
    v6225 = v6367;
  }
  int * v6226 = v6120->cache_vals;
  int v6379 = (v6225 * 2) + (((int)((unsigned int)(v6124 + 8) >> 2)) & 1);
  v6226[v6379] = v6125;
  int * v6228 = v6120->cache_tags;
  int v6229 = v6228[v6298];
  int v6230 = v6228[v6299];
  bool v6382 = !(((~(((v6229 ^ ((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1))) | (-(v6229 ^ ((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v6230 ^ ((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1))) | (-(v6230 ^ ((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v6284;
  if (v6382) {
    int * v6231 = v6120->cache_age;
    int v6384 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v6230 ^ ((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1))) | (-(v6230 ^ ((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v6232 = v6231[v6384];
    int v6233 = v6231[v6298];
    int v6385 = v6233 + ((int)((unsigned int)(v6233 - v6232) >> 31));
    v6231[v6298] = v6385;
    int * v6235 = v6120->cache_age;
    int v6236 = v6235[v6299];
    int v6387 = v6236 + ((int)((unsigned int)(v6236 - v6232) >> 31));
    v6235[v6299] = v6387;
    int * v6238 = v6120->cache_age;
    v6238[v6384] = 0;
    v6284 = v6384;
  } else {
    int * v6241 = v6120->cache_age;
    int v6391 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1)) & 3) * 2);
    int v6242 = v6241[v6391];
    int * v6243 = v6120->cache_tags;
    int v6244 = v6243[v6391];
    int v6245 = v6241[v6299];
    int v6246 = v6243[v6299];
    int * v6247 = v6120->cache_dirty;
    int v6394 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v6242 + ((~(((v6244 ^ -1) | (-(v6244 ^ -1))) >> 31)) & 2)) - (v6245 + ((~(((v6246 ^ -1) | (-(v6246 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6248 = v6247[v6394];
    bool v6395 = !(v6248 == 0);
    if (v6395) {
      int * v6249 = v6120->cache_tags;
      int v6250 = v6249[v6394];
      int * v6251 = v6120->cache_vals;
      int v6398 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v6242 + ((~(((v6244 ^ -1) | (-(v6244 ^ -1))) >> 31)) & 2)) - (v6245 + ((~(((v6246 ^ -1) | (-(v6246 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v6252 = v6251[v6398];
      int v6399 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v6242 + ((~(((v6244 ^ -1) | (-(v6244 ^ -1))) >> 31)) & 2)) - (v6245 + ((~(((v6246 ^ -1) | (-(v6246 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v6253 = v6251[v6399];
      int * v6254 = v6120->mem;
      int v6401 = v6250 * 2;
      v6254[v6401] = v6252;
      int * v6256 = v6120->mem;
      int v6404 = (v6250 * 2) + 1;
      v6256[v6404] = v6253;
      ;
    } else {
      ;
    }
    int * v6261 = v6120->mem;
    int v6409 = ((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1)) * 2;
    int v6262 = v6261[v6409];
    int v6410 = (((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1)) * 2) + 1;
    int v6263 = v6261[v6410];
    int * v6264 = v6120->cache_vals;
    int v6412 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v6242 + ((~(((v6244 ^ -1) | (-(v6244 ^ -1))) >> 31)) & 2)) - (v6245 + ((~(((v6246 ^ -1) | (-(v6246 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6264[v6412] = v6262;
    int * v6266 = v6120->cache_vals;
    int v6415 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v6242 + ((~(((v6244 ^ -1) | (-(v6244 ^ -1))) >> 31)) & 2)) - (v6245 + ((~(((v6246 ^ -1) | (-(v6246 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6266[v6415] = v6263;
    int * v6268 = v6120->cache_tags;
    int v6418 = (int)((unsigned int)((int)((unsigned int)(v6124 + 8) >> 2)) >> 1);
    v6268[v6394] = v6418;
    int * v6270 = v6120->cache_dirty;
    v6270[v6394] = 0;
    int * v6272 = v6120->cache_age;
    v6272[v6394] = 1;
    int * v6274 = v6120->cache_age;
    int v6275 = v6274[v6394];
    int v6276 = v6274[v6298];
    int v6424 = v6276 + ((int)((unsigned int)(v6276 - v6275) >> 31));
    v6274[v6298] = v6424;
    int * v6278 = v6120->cache_age;
    int v6279 = v6278[v6299];
    int v6426 = v6279 + ((int)((unsigned int)(v6279 - v6275) >> 31));
    v6278[v6299] = v6426;
    int * v6281 = v6120->cache_age;
    v6281[v6394] = 0;
    v6284 = v6394;
  }
  int * v6285 = v6120->cache_vals;
  int v6429 = (v6284 * 2) + (((int)((unsigned int)(v6124 + 8) >> 2)) & 1);
  v6285[v6429] = v6125;
  int * v6287 = v6120->cache_dirty;
  v6287[v6284] = 1;
  struct StateT * v6289 = slot_198(v6120);
  return v6289;
}

struct StateT * slot_207(struct StateT * v8979) {
  int v8980 = v8979->timer;
  int v9090 = v8980 + 1;
  v8979->timer = v9090;
  int * v8982 = v8979->regs;
  int v8983 = v8982[2];
  int * v8984 = v8979->cache_tags;
  int v9094 = (((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1)) & 1) * 2;
  int v8985 = v8984[v9094];
  int v9095 = ((((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1)) & 1) * 2) + 1;
  int v8986 = v8984[v9095];
  int v9096 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1)) & 3) * 2);
  int v8987 = v8984[v9096];
  int v9097 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v8988 = v8984[v9097];
  int v8989 = v8979->timer;
  int v9098 = v8989 + ((100 ^ (((~(((v8987 ^ ((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1))) | (-(v8987 ^ ((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v8988 ^ ((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1))) | (-(v8988 ^ ((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v8985 ^ ((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1))) | (-(v8985 ^ ((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v8986 ^ ((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1))) | (-(v8986 ^ ((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v8987 ^ ((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1))) | (-(v8987 ^ ((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v8988 ^ ((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1))) | (-(v8988 ^ ((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1))))) >> 31))) & 104)))));
  v8979->timer = v9098;
  int * v8991 = v8979->cache_vals;
  bool v9099 = !(((~(((v8985 ^ ((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1))) | (-(v8985 ^ ((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v8986 ^ ((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1))) | (-(v8986 ^ ((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v9084;
  if (v9099) {
    int * v8992 = v8979->cache_age;
    int v9101 = ((((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1)) & 1) * 2) + ((~(((v8986 ^ ((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1))) | (-(v8986 ^ ((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v8993 = v8992[v9101];
    int v8994 = v8992[v9094];
    int v9102 = v8994 + ((int)((unsigned int)(v8994 - v8993) >> 31));
    v8992[v9094] = v9102;
    int * v8996 = v8979->cache_age;
    int v8997 = v8996[v9095];
    int v9104 = v8997 + ((int)((unsigned int)(v8997 - v8993) >> 31));
    v8996[v9095] = v9104;
    int * v8999 = v8979->cache_age;
    v8999[v9101] = 0;
    v9084 = v9101;
  } else {
    int * v9002 = v8979->cache_age;
    int v9108 = (((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1)) & 1) * 2;
    int v9003 = v9002[v9108];
    int * v9004 = v8979->cache_tags;
    int v9005 = v9004[v9108];
    int v9006 = v9002[v9095];
    int v9007 = v9004[v9095];
    bool v9110 = !(((~(((v8987 ^ ((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1))) | (-(v8987 ^ ((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v8988 ^ ((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1))) | (-(v8988 ^ ((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1))))) >> 31))) == 0);
    int v9061;
    if (v9110) {
      int * v9008 = v8979->cache_age;
      int v9112 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v8988 ^ ((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1))) | (-(v8988 ^ ((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1))))) >> 31)) & 1);
      int v9009 = v9008[v9112];
      int v9010 = v9008[v9096];
      int v9113 = v9010 + ((int)((unsigned int)(v9010 - v9009) >> 31));
      v9008[v9096] = v9113;
      int * v9012 = v8979->cache_age;
      int v9013 = v9012[v9097];
      int v9115 = v9013 + ((int)((unsigned int)(v9013 - v9009) >> 31));
      v9012[v9097] = v9115;
      int * v9015 = v8979->cache_age;
      v9015[v9112] = 0;
      v9061 = v9112;
    } else {
      int * v9018 = v8979->cache_age;
      int v9119 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1)) & 3) * 2);
      int v9019 = v9018[v9119];
      int * v9020 = v8979->cache_tags;
      int v9021 = v9020[v9119];
      int v9022 = v9018[v9097];
      int v9023 = v9020[v9097];
      int * v9024 = v8979->cache_dirty;
      int v9122 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v9019 + ((~(((v9021 ^ -1) | (-(v9021 ^ -1))) >> 31)) & 2)) - (v9022 + ((~(((v9023 ^ -1) | (-(v9023 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v9025 = v9024[v9122];
      bool v9123 = !(v9025 == 0);
      if (v9123) {
        int * v9026 = v8979->cache_tags;
        int v9027 = v9026[v9122];
        int * v9028 = v8979->cache_vals;
        int v9126 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v9019 + ((~(((v9021 ^ -1) | (-(v9021 ^ -1))) >> 31)) & 2)) - (v9022 + ((~(((v9023 ^ -1) | (-(v9023 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v9029 = v9028[v9126];
        int v9127 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v9019 + ((~(((v9021 ^ -1) | (-(v9021 ^ -1))) >> 31)) & 2)) - (v9022 + ((~(((v9023 ^ -1) | (-(v9023 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v9030 = v9028[v9127];
        int * v9031 = v8979->mem;
        int v9129 = v9027 * 2;
        v9031[v9129] = v9029;
        int * v9033 = v8979->mem;
        int v9132 = (v9027 * 2) + 1;
        v9033[v9132] = v9030;
        ;
      } else {
        ;
      }
      int * v9038 = v8979->mem;
      int v9137 = ((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1)) * 2;
      int v9039 = v9038[v9137];
      int v9138 = (((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1)) * 2) + 1;
      int v9040 = v9038[v9138];
      int * v9041 = v8979->cache_vals;
      int v9140 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v9019 + ((~(((v9021 ^ -1) | (-(v9021 ^ -1))) >> 31)) & 2)) - (v9022 + ((~(((v9023 ^ -1) | (-(v9023 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v9041[v9140] = v9039;
      int * v9043 = v8979->cache_vals;
      int v9143 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v9019 + ((~(((v9021 ^ -1) | (-(v9021 ^ -1))) >> 31)) & 2)) - (v9022 + ((~(((v9023 ^ -1) | (-(v9023 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v9043[v9143] = v9040;
      int * v9045 = v8979->cache_tags;
      int v9146 = (int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1);
      v9045[v9122] = v9146;
      int * v9047 = v8979->cache_dirty;
      v9047[v9122] = 0;
      int * v9049 = v8979->cache_age;
      v9049[v9122] = 1;
      int * v9051 = v8979->cache_age;
      int v9052 = v9051[v9122];
      int v9053 = v9051[v9096];
      int v9152 = v9053 + ((int)((unsigned int)(v9053 - v9052) >> 31));
      v9051[v9096] = v9152;
      int * v9055 = v8979->cache_age;
      int v9056 = v9055[v9097];
      int v9154 = v9056 + ((int)((unsigned int)(v9056 - v9052) >> 31));
      v9055[v9097] = v9154;
      int * v9058 = v8979->cache_age;
      v9058[v9122] = 0;
      v9061 = v9122;
    }
    int * v9062 = v8979->cache_vals;
    int v9157 = v9061 * 2;
    int v9063 = v9062[v9157];
    int v9158 = (v9061 * 2) + 1;
    int v9064 = v9062[v9158];
    int v9159 = (((((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v9003 + ((~(((v9005 ^ -1) | (-(v9005 ^ -1))) >> 31)) & 2)) - (v9006 + ((~(((v9007 ^ -1) | (-(v9007 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9062[v9159] = v9063;
    int * v9066 = v8979->cache_vals;
    int v9162 = ((((((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v9003 + ((~(((v9005 ^ -1) | (-(v9005 ^ -1))) >> 31)) & 2)) - (v9006 + ((~(((v9007 ^ -1) | (-(v9007 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9066[v9162] = v9064;
    int * v9068 = v8979->cache_tags;
    int v9165 = ((((int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v9003 + ((~(((v9005 ^ -1) | (-(v9005 ^ -1))) >> 31)) & 2)) - (v9006 + ((~(((v9007 ^ -1) | (-(v9007 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9166 = (int)((unsigned int)((int)((unsigned int)(v8983 + 28) >> 2)) >> 1);
    v9068[v9165] = v9166;
    int * v9070 = v8979->cache_dirty;
    v9070[v9165] = 0;
    int * v9072 = v8979->cache_age;
    v9072[v9165] = 1;
    int * v9074 = v8979->cache_age;
    int v9075 = v9074[v9165];
    int v9076 = v9074[v9094];
    int v9172 = v9076 + ((int)((unsigned int)(v9076 - v9075) >> 31));
    v9074[v9094] = v9172;
    int * v9078 = v8979->cache_age;
    int v9079 = v9078[v9095];
    int v9174 = v9079 + ((int)((unsigned int)(v9079 - v9075) >> 31));
    v9078[v9095] = v9174;
    int * v9081 = v8979->cache_age;
    v9081[v9165] = 0;
    v9084 = v9165;
  }
  int v9177 = (v9084 * 2) + (((int)((unsigned int)(v8983 + 28) >> 2)) & 1);
  int v9085 = v8991[v9177];
  int * v9086 = v8979->regs;
  v9086[20] = v9085;
  struct StateT * v9088 = slot_208(v8979);
  return v9088;
}

struct StateT * slot_156(struct StateT * v11754) {
  int v11755 = v11754->timer;
  int v11763 = v11755 + 1;
  v11754->timer = v11763;
  int * v11757 = v11754->regs;
  int v11758 = v11757[7];
  int v11759 = v11757[16];
  int v11768 = v11758 + v11759;
  v11757[23] = v11768;
  struct StateT * v11761 = slot_157(v11754);
  return v11761;
}

struct StateT * slot_154(struct StateT * v11720) {
  int v11721 = v11720->timer;
  int v11729 = v11721 + 1;
  v11720->timer = v11729;
  int * v11723 = v11720->regs;
  int v11724 = v11723[5];
  int v11725 = v11723[12];
  int v11734 = v11724 + v11725;
  v11723[21] = v11734;
  struct StateT * v11727 = slot_155(v11720);
  return v11727;
}

struct StateT * slot_68(struct StateT * v10375) {
  int v10376 = v10375->timer;
  int v10384 = v10376 + 1;
  v10375->timer = v10384;
  int * v10378 = v10375->regs;
  int v10379 = v10378[23];
  int v10380 = v10378[24];
  int v10388 = v10379 | v10380;
  v10378[23] = v10388;
  struct StateT * v10382 = slot_69(v10375);
  return v10382;
}

struct StateT * slot_105(struct StateT * v10954) {
  int v10955 = v10954->timer;
  int v10963 = v10955 + 1;
  v10954->timer = v10963;
  int * v10957 = v10954->regs;
  int v10958 = v10957[22];
  int v10959 = v10957[24];
  int v10967 = v10958 | v10959;
  v10957[22] = v10967;
  struct StateT * v10961 = slot_106(v10954);
  return v10961;
}

struct StateT * slot_27(struct StateT * v5366) {
  int v5367 = v5366->timer;
  int v5374 = v5367 + 1;
  v5366->timer = v5374;
  int * v5369 = v5366->regs;
  int v5370 = v5369[28];
  int v5378 = v5370 + 1134;
  v5369[29] = v5378;
  struct StateT * v5372 = slot_28(v5366);
  return v5372;
}

struct StateT * slot_164(struct StateT * v11876) {
  int v11877 = v11876->timer;
  int v11884 = v11877 + 1;
  v11876->timer = v11884;
  int * v11879 = v11876->regs;
  int v11880 = v11879[22];
  int v11887 = v11880 << 13;
  v11879[22] = v11887;
  struct StateT * v11882 = slot_165(v11876);
  return v11882;
}

struct StateT * slot_15(struct StateT * v3680) {
  int v3681 = v3680->timer;
  int v3791 = v3681 + 1;
  v3680->timer = v3791;
  int * v3683 = v3680->regs;
  int v3684 = v3683[12];
  int * v3685 = v3680->cache_tags;
  int v3795 = (((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1)) & 1) * 2;
  int v3686 = v3685[v3795];
  int v3796 = ((((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v3687 = v3685[v3796];
  int v3797 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1)) & 3) * 2);
  int v3688 = v3685[v3797];
  int v3798 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3689 = v3685[v3798];
  int v3690 = v3680->timer;
  int v3799 = v3690 + ((100 ^ (((~(((v3688 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))) | (-(v3688 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v3689 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))) | (-(v3689 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3686 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))) | (-(v3686 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v3687 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))) | (-(v3687 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3688 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))) | (-(v3688 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v3689 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))) | (-(v3689 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v3680->timer = v3799;
  int * v3692 = v3680->cache_vals;
  bool v3800 = !(((~(((v3686 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))) | (-(v3686 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v3687 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))) | (-(v3687 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v3785;
  if (v3800) {
    int * v3693 = v3680->cache_age;
    int v3802 = ((((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v3687 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))) | (-(v3687 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v3694 = v3693[v3802];
    int v3695 = v3693[v3795];
    int v3803 = v3695 + ((int)((unsigned int)(v3695 - v3694) >> 31));
    v3693[v3795] = v3803;
    int * v3697 = v3680->cache_age;
    int v3698 = v3697[v3796];
    int v3805 = v3698 + ((int)((unsigned int)(v3698 - v3694) >> 31));
    v3697[v3796] = v3805;
    int * v3700 = v3680->cache_age;
    v3700[v3802] = 0;
    v3785 = v3802;
  } else {
    int * v3703 = v3680->cache_age;
    int v3809 = (((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1)) & 1) * 2;
    int v3704 = v3703[v3809];
    int * v3705 = v3680->cache_tags;
    int v3706 = v3705[v3809];
    int v3707 = v3703[v3796];
    int v3708 = v3705[v3796];
    bool v3811 = !(((~(((v3688 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))) | (-(v3688 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v3689 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))) | (-(v3689 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v3762;
    if (v3811) {
      int * v3709 = v3680->cache_age;
      int v3813 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3689 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))) | (-(v3689 ^ ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v3710 = v3709[v3813];
      int v3711 = v3709[v3797];
      int v3814 = v3711 + ((int)((unsigned int)(v3711 - v3710) >> 31));
      v3709[v3797] = v3814;
      int * v3713 = v3680->cache_age;
      int v3714 = v3713[v3798];
      int v3816 = v3714 + ((int)((unsigned int)(v3714 - v3710) >> 31));
      v3713[v3798] = v3816;
      int * v3716 = v3680->cache_age;
      v3716[v3813] = 0;
      v3762 = v3813;
    } else {
      int * v3719 = v3680->cache_age;
      int v3820 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1)) & 3) * 2);
      int v3720 = v3719[v3820];
      int * v3721 = v3680->cache_tags;
      int v3722 = v3721[v3820];
      int v3723 = v3719[v3798];
      int v3724 = v3721[v3798];
      int * v3725 = v3680->cache_dirty;
      int v3823 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v3720 + ((~(((v3722 ^ -1) | (-(v3722 ^ -1))) >> 31)) & 2)) - (v3723 + ((~(((v3724 ^ -1) | (-(v3724 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3726 = v3725[v3823];
      bool v3824 = !(v3726 == 0);
      if (v3824) {
        int * v3727 = v3680->cache_tags;
        int v3728 = v3727[v3823];
        int * v3729 = v3680->cache_vals;
        int v3827 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v3720 + ((~(((v3722 ^ -1) | (-(v3722 ^ -1))) >> 31)) & 2)) - (v3723 + ((~(((v3724 ^ -1) | (-(v3724 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3730 = v3729[v3827];
        int v3828 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v3720 + ((~(((v3722 ^ -1) | (-(v3722 ^ -1))) >> 31)) & 2)) - (v3723 + ((~(((v3724 ^ -1) | (-(v3724 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3731 = v3729[v3828];
        int * v3732 = v3680->mem;
        int v3830 = v3728 * 2;
        v3732[v3830] = v3730;
        int * v3734 = v3680->mem;
        int v3833 = (v3728 * 2) + 1;
        v3734[v3833] = v3731;
        ;
      } else {
        ;
      }
      int * v3739 = v3680->mem;
      int v3838 = ((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1)) * 2;
      int v3740 = v3739[v3838];
      int v3839 = (((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1)) * 2) + 1;
      int v3741 = v3739[v3839];
      int * v3742 = v3680->cache_vals;
      int v3841 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v3720 + ((~(((v3722 ^ -1) | (-(v3722 ^ -1))) >> 31)) & 2)) - (v3723 + ((~(((v3724 ^ -1) | (-(v3724 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3742[v3841] = v3740;
      int * v3744 = v3680->cache_vals;
      int v3844 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v3720 + ((~(((v3722 ^ -1) | (-(v3722 ^ -1))) >> 31)) & 2)) - (v3723 + ((~(((v3724 ^ -1) | (-(v3724 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3744[v3844] = v3741;
      int * v3746 = v3680->cache_tags;
      int v3847 = (int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1);
      v3746[v3823] = v3847;
      int * v3748 = v3680->cache_dirty;
      v3748[v3823] = 0;
      int * v3750 = v3680->cache_age;
      v3750[v3823] = 1;
      int * v3752 = v3680->cache_age;
      int v3753 = v3752[v3823];
      int v3754 = v3752[v3797];
      int v3853 = v3754 + ((int)((unsigned int)(v3754 - v3753) >> 31));
      v3752[v3797] = v3853;
      int * v3756 = v3680->cache_age;
      int v3757 = v3756[v3798];
      int v3855 = v3757 + ((int)((unsigned int)(v3757 - v3753) >> 31));
      v3756[v3798] = v3855;
      int * v3759 = v3680->cache_age;
      v3759[v3823] = 0;
      v3762 = v3823;
    }
    int * v3763 = v3680->cache_vals;
    int v3858 = v3762 * 2;
    int v3764 = v3763[v3858];
    int v3859 = (v3762 * 2) + 1;
    int v3765 = v3763[v3859];
    int v3860 = (((((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v3704 + ((~(((v3706 ^ -1) | (-(v3706 ^ -1))) >> 31)) & 2)) - (v3707 + ((~(((v3708 ^ -1) | (-(v3708 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3763[v3860] = v3764;
    int * v3767 = v3680->cache_vals;
    int v3863 = ((((((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v3704 + ((~(((v3706 ^ -1) | (-(v3706 ^ -1))) >> 31)) & 2)) - (v3707 + ((~(((v3708 ^ -1) | (-(v3708 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3767[v3863] = v3765;
    int * v3769 = v3680->cache_tags;
    int v3866 = ((((int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v3704 + ((~(((v3706 ^ -1) | (-(v3706 ^ -1))) >> 31)) & 2)) - (v3707 + ((~(((v3708 ^ -1) | (-(v3708 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3867 = (int)((unsigned int)((int)((unsigned int)(v3684 + 16) >> 2)) >> 1);
    v3769[v3866] = v3867;
    int * v3771 = v3680->cache_dirty;
    v3771[v3866] = 0;
    int * v3773 = v3680->cache_age;
    v3773[v3866] = 1;
    int * v3775 = v3680->cache_age;
    int v3776 = v3775[v3866];
    int v3777 = v3775[v3795];
    int v3873 = v3777 + ((int)((unsigned int)(v3777 - v3776) >> 31));
    v3775[v3795] = v3873;
    int * v3779 = v3680->cache_age;
    int v3780 = v3779[v3796];
    int v3875 = v3780 + ((int)((unsigned int)(v3780 - v3776) >> 31));
    v3779[v3796] = v3875;
    int * v3782 = v3680->cache_age;
    v3782[v3866] = 0;
    v3785 = v3866;
  }
  int v3878 = (v3785 * 2) + (((int)((unsigned int)(v3684 + 16) >> 2)) & 1);
  int v3786 = v3692[v3878];
  int * v3787 = v3680->regs;
  v3787[15] = v3786;
  struct StateT * v3789 = slot_16(v3680);
  return v3789;
}

struct StateT * slot_133(struct StateT * v11391) {
  int v11392 = v11391->timer;
  int v11400 = v11392 + 1;
  v11391->timer = v11400;
  int * v11394 = v11391->regs;
  int v11395 = v11394[14];
  int v11396 = v11394[30];
  int v11405 = v11395 + v11396;
  v11394[20] = v11405;
  struct StateT * v11398 = slot_134(v11391);
  return v11398;
}

struct StateT * slot_56(struct StateT * v10194) {
  int v10195 = v10194->timer;
  int v10203 = v10195 + 1;
  v10194->timer = v10203;
  int * v10197 = v10194->regs;
  int v10198 = v10197[8];
  int v10199 = v10197[31];
  int v10208 = v10198 + v10199;
  v10197[23] = v10208;
  struct StateT * v10201 = slot_57(v10194);
  return v10201;
}

struct StateT * slot_34(struct StateT * v6103) {
  int v6104 = v6103->timer;
  int v6112 = v6104 + 1;
  v6103->timer = v6112;
  int * v6106 = v6103->regs;
  int v6107 = v6106[29];
  int v6108 = v6106[14];
  int v6117 = v6107 + v6108;
  v6106[21] = v6117;
  struct StateT * v6110 = slot_35(v6103);
  return v6110;
}

struct StateT * slot_171(struct StateT * v11983) {
  int v11984 = v11983->timer;
  int v11992 = v11984 + 1;
  v11983->timer = v11992;
  int * v11986 = v11983->regs;
  int v11987 = v11986[18];
  int v11988 = v11986[22];
  int v11996 = v11987 ^ v11988;
  v11986[18] = v11996;
  struct StateT * v11990 = slot_172(v11983);
  return v11990;
}

struct StateT * slot_162(struct StateT * v11845) {
  int v11846 = v11845->timer;
  int v11854 = v11846 + 1;
  v11845->timer = v11854;
  int * v11848 = v11845->regs;
  int v11849 = v11848[21];
  int v11850 = v11848[24];
  int v11858 = v11849 | v11850;
  v11848[21] = v11858;
  struct StateT * v11852 = slot_163(v11845);
  return v11852;
}

struct StateT * slot_21(struct StateT * v4904) {
  int v4905 = v4904->timer;
  int v5015 = v4905 + 1;
  v4904->timer = v5015;
  int * v4907 = v4904->regs;
  int v4908 = v4907[11];
  int * v4909 = v4904->cache_tags;
  int v5019 = (((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1)) & 1) * 2;
  int v4910 = v4909[v5019];
  int v5020 = ((((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4911 = v4909[v5020];
  int v5021 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1)) & 3) * 2);
  int v4912 = v4909[v5021];
  int v5022 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4913 = v4909[v5022];
  int v4914 = v4904->timer;
  int v5023 = v4914 + ((100 ^ (((~(((v4912 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))) | (-(v4912 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v4913 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))) | (-(v4913 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4910 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))) | (-(v4910 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v4911 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))) | (-(v4911 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4912 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))) | (-(v4912 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v4913 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))) | (-(v4913 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4904->timer = v5023;
  int * v4916 = v4904->cache_vals;
  bool v5024 = !(((~(((v4910 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))) | (-(v4910 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v4911 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))) | (-(v4911 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v5009;
  if (v5024) {
    int * v4917 = v4904->cache_age;
    int v5026 = ((((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v4911 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))) | (-(v4911 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v4918 = v4917[v5026];
    int v4919 = v4917[v5019];
    int v5027 = v4919 + ((int)((unsigned int)(v4919 - v4918) >> 31));
    v4917[v5019] = v5027;
    int * v4921 = v4904->cache_age;
    int v4922 = v4921[v5020];
    int v5029 = v4922 + ((int)((unsigned int)(v4922 - v4918) >> 31));
    v4921[v5020] = v5029;
    int * v4924 = v4904->cache_age;
    v4924[v5026] = 0;
    v5009 = v5026;
  } else {
    int * v4927 = v4904->cache_age;
    int v5033 = (((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1)) & 1) * 2;
    int v4928 = v4927[v5033];
    int * v4929 = v4904->cache_tags;
    int v4930 = v4929[v5033];
    int v4931 = v4927[v5020];
    int v4932 = v4929[v5020];
    bool v5035 = !(((~(((v4912 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))) | (-(v4912 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v4913 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))) | (-(v4913 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v4986;
    if (v5035) {
      int * v4933 = v4904->cache_age;
      int v5037 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4913 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))) | (-(v4913 ^ ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v4934 = v4933[v5037];
      int v4935 = v4933[v5021];
      int v5038 = v4935 + ((int)((unsigned int)(v4935 - v4934) >> 31));
      v4933[v5021] = v5038;
      int * v4937 = v4904->cache_age;
      int v4938 = v4937[v5022];
      int v5040 = v4938 + ((int)((unsigned int)(v4938 - v4934) >> 31));
      v4937[v5022] = v5040;
      int * v4940 = v4904->cache_age;
      v4940[v5037] = 0;
      v4986 = v5037;
    } else {
      int * v4943 = v4904->cache_age;
      int v5044 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1)) & 3) * 2);
      int v4944 = v4943[v5044];
      int * v4945 = v4904->cache_tags;
      int v4946 = v4945[v5044];
      int v4947 = v4943[v5022];
      int v4948 = v4945[v5022];
      int * v4949 = v4904->cache_dirty;
      int v5047 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4944 + ((~(((v4946 ^ -1) | (-(v4946 ^ -1))) >> 31)) & 2)) - (v4947 + ((~(((v4948 ^ -1) | (-(v4948 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4950 = v4949[v5047];
      bool v5048 = !(v4950 == 0);
      if (v5048) {
        int * v4951 = v4904->cache_tags;
        int v4952 = v4951[v5047];
        int * v4953 = v4904->cache_vals;
        int v5051 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4944 + ((~(((v4946 ^ -1) | (-(v4946 ^ -1))) >> 31)) & 2)) - (v4947 + ((~(((v4948 ^ -1) | (-(v4948 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4954 = v4953[v5051];
        int v5052 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4944 + ((~(((v4946 ^ -1) | (-(v4946 ^ -1))) >> 31)) & 2)) - (v4947 + ((~(((v4948 ^ -1) | (-(v4948 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4955 = v4953[v5052];
        int * v4956 = v4904->mem;
        int v5054 = v4952 * 2;
        v4956[v5054] = v4954;
        int * v4958 = v4904->mem;
        int v5057 = (v4952 * 2) + 1;
        v4958[v5057] = v4955;
        ;
      } else {
        ;
      }
      int * v4963 = v4904->mem;
      int v5062 = ((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1)) * 2;
      int v4964 = v4963[v5062];
      int v5063 = (((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1)) * 2) + 1;
      int v4965 = v4963[v5063];
      int * v4966 = v4904->cache_vals;
      int v5065 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4944 + ((~(((v4946 ^ -1) | (-(v4946 ^ -1))) >> 31)) & 2)) - (v4947 + ((~(((v4948 ^ -1) | (-(v4948 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4966[v5065] = v4964;
      int * v4968 = v4904->cache_vals;
      int v5068 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v4944 + ((~(((v4946 ^ -1) | (-(v4946 ^ -1))) >> 31)) & 2)) - (v4947 + ((~(((v4948 ^ -1) | (-(v4948 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4968[v5068] = v4965;
      int * v4970 = v4904->cache_tags;
      int v5071 = (int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1);
      v4970[v5047] = v5071;
      int * v4972 = v4904->cache_dirty;
      v4972[v5047] = 0;
      int * v4974 = v4904->cache_age;
      v4974[v5047] = 1;
      int * v4976 = v4904->cache_age;
      int v4977 = v4976[v5047];
      int v4978 = v4976[v5021];
      int v5077 = v4978 + ((int)((unsigned int)(v4978 - v4977) >> 31));
      v4976[v5021] = v5077;
      int * v4980 = v4904->cache_age;
      int v4981 = v4980[v5022];
      int v5079 = v4981 + ((int)((unsigned int)(v4981 - v4977) >> 31));
      v4980[v5022] = v5079;
      int * v4983 = v4904->cache_age;
      v4983[v5047] = 0;
      v4986 = v5047;
    }
    int * v4987 = v4904->cache_vals;
    int v5082 = v4986 * 2;
    int v4988 = v4987[v5082];
    int v5083 = (v4986 * 2) + 1;
    int v4989 = v4987[v5083];
    int v5084 = (((((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v4928 + ((~(((v4930 ^ -1) | (-(v4930 ^ -1))) >> 31)) & 2)) - (v4931 + ((~(((v4932 ^ -1) | (-(v4932 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4987[v5084] = v4988;
    int * v4991 = v4904->cache_vals;
    int v5087 = ((((((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v4928 + ((~(((v4930 ^ -1) | (-(v4930 ^ -1))) >> 31)) & 2)) - (v4931 + ((~(((v4932 ^ -1) | (-(v4932 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4991[v5087] = v4989;
    int * v4993 = v4904->cache_tags;
    int v5090 = ((((int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v4928 + ((~(((v4930 ^ -1) | (-(v4930 ^ -1))) >> 31)) & 2)) - (v4931 + ((~(((v4932 ^ -1) | (-(v4932 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5091 = (int)((unsigned int)((int)((unsigned int)(v4908 + 8) >> 2)) >> 1);
    v4993[v5090] = v5091;
    int * v4995 = v4904->cache_dirty;
    v4995[v5090] = 0;
    int * v4997 = v4904->cache_age;
    v4997[v5090] = 1;
    int * v4999 = v4904->cache_age;
    int v5000 = v4999[v5090];
    int v5001 = v4999[v5019];
    int v5097 = v5001 + ((int)((unsigned int)(v5001 - v5000) >> 31));
    v4999[v5019] = v5097;
    int * v5003 = v4904->cache_age;
    int v5004 = v5003[v5020];
    int v5099 = v5004 + ((int)((unsigned int)(v5004 - v5000) >> 31));
    v5003[v5020] = v5099;
    int * v5006 = v4904->cache_age;
    v5006[v5090] = 0;
    v5009 = v5090;
  }
  int v5102 = (v5009 * 2) + (((int)((unsigned int)(v4908 + 8) >> 2)) & 1);
  int v5010 = v4916[v5102];
  int * v5011 = v4904->regs;
  v5011[6] = v5010;
  struct StateT * v5013 = slot_22(v4904);
  return v5013;
}

struct StateT * slot_118(struct StateT * v11162) {
  int v11163 = v11162->timer;
  int v11170 = v11163 + 1;
  v11162->timer = v11170;
  int * v11165 = v11162->regs;
  int v11166 = v11165[20];
  int v11173 = v11166 << 7;
  v11165[20] = v11173;
  struct StateT * v11168 = slot_119(v11162);
  return v11168;
}

struct StateT * slot_121(struct StateT * v11207) {
  int v11208 = v11207->timer;
  int v11215 = v11208 + 1;
  v11207->timer = v11215;
  int * v11210 = v11207->regs;
  int v11211 = v11210[21];
  int v11218 = v11211 << 7;
  v11210[21] = v11218;
  struct StateT * v11213 = slot_122(v11207);
  return v11213;
}

struct StateT * slot_144(struct StateT * v11564) {
  int v11565 = v11564->timer;
  int v11572 = v11565 + 1;
  v11564->timer = v11572;
  int * v11567 = v11564->regs;
  int v11568 = v11567[22];
  int v11575 = v11568 << 9;
  v11567[22] = v11575;
  struct StateT * v11570 = slot_145(v11564);
  return v11570;
}

struct StateT * slot_201(struct StateT * v7443) {
  int v7444 = v7443->timer;
  int v7614 = v7444 + 1;
  v7443->timer = v7614;
  int * v7446 = v7443->regs;
  int v7447 = v7446[10];
  int v7448 = v7446[6];
  int * v7449 = v7443->cache_tags;
  int v7619 = (((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1)) & 1) * 2;
  int v7450 = v7449[v7619];
  int v7620 = ((((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1)) & 1) * 2) + 1;
  int v7451 = v7449[v7620];
  int v7621 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1)) & 3) * 2);
  int v7452 = v7449[v7621];
  int v7622 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v7453 = v7449[v7622];
  int v7454 = v7443->timer;
  int v7623 = v7454 + ((100 ^ (((~(((v7452 ^ ((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1))) | (-(v7452 ^ ((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v7453 ^ ((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1))) | (-(v7453 ^ ((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v7450 ^ ((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1))) | (-(v7450 ^ ((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v7451 ^ ((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1))) | (-(v7451 ^ ((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v7452 ^ ((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1))) | (-(v7452 ^ ((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v7453 ^ ((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1))) | (-(v7453 ^ ((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1))))) >> 31))) & 104)))));
  v7443->timer = v7623;
  bool v7624 = !(((~(((v7450 ^ ((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1))) | (-(v7450 ^ ((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v7451 ^ ((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1))) | (-(v7451 ^ ((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v7548;
  if (v7624) {
    int * v7456 = v7443->cache_age;
    int v7626 = ((((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1)) & 1) * 2) + ((~(((v7451 ^ ((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1))) | (-(v7451 ^ ((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v7457 = v7456[v7626];
    int v7458 = v7456[v7619];
    int v7627 = v7458 + ((int)((unsigned int)(v7458 - v7457) >> 31));
    v7456[v7619] = v7627;
    int * v7460 = v7443->cache_age;
    int v7461 = v7460[v7620];
    int v7629 = v7461 + ((int)((unsigned int)(v7461 - v7457) >> 31));
    v7460[v7620] = v7629;
    int * v7463 = v7443->cache_age;
    v7463[v7626] = 0;
    v7548 = v7626;
  } else {
    int * v7466 = v7443->cache_age;
    int v7633 = (((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1)) & 1) * 2;
    int v7467 = v7466[v7633];
    int * v7468 = v7443->cache_tags;
    int v7469 = v7468[v7633];
    int v7470 = v7466[v7620];
    int v7471 = v7468[v7620];
    bool v7635 = !(((~(((v7452 ^ ((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1))) | (-(v7452 ^ ((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v7453 ^ ((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1))) | (-(v7453 ^ ((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1))))) >> 31))) == 0);
    int v7525;
    if (v7635) {
      int * v7472 = v7443->cache_age;
      int v7637 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7453 ^ ((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1))) | (-(v7453 ^ ((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1))))) >> 31)) & 1);
      int v7473 = v7472[v7637];
      int v7474 = v7472[v7621];
      int v7638 = v7474 + ((int)((unsigned int)(v7474 - v7473) >> 31));
      v7472[v7621] = v7638;
      int * v7476 = v7443->cache_age;
      int v7477 = v7476[v7622];
      int v7640 = v7477 + ((int)((unsigned int)(v7477 - v7473) >> 31));
      v7476[v7622] = v7640;
      int * v7479 = v7443->cache_age;
      v7479[v7637] = 0;
      v7525 = v7637;
    } else {
      int * v7482 = v7443->cache_age;
      int v7644 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1)) & 3) * 2);
      int v7483 = v7482[v7644];
      int * v7484 = v7443->cache_tags;
      int v7485 = v7484[v7644];
      int v7486 = v7482[v7622];
      int v7487 = v7484[v7622];
      int * v7488 = v7443->cache_dirty;
      int v7647 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v7483 + ((~(((v7485 ^ -1) | (-(v7485 ^ -1))) >> 31)) & 2)) - (v7486 + ((~(((v7487 ^ -1) | (-(v7487 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v7489 = v7488[v7647];
      bool v7648 = !(v7489 == 0);
      if (v7648) {
        int * v7490 = v7443->cache_tags;
        int v7491 = v7490[v7647];
        int * v7492 = v7443->cache_vals;
        int v7651 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v7483 + ((~(((v7485 ^ -1) | (-(v7485 ^ -1))) >> 31)) & 2)) - (v7486 + ((~(((v7487 ^ -1) | (-(v7487 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v7493 = v7492[v7651];
        int v7652 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v7483 + ((~(((v7485 ^ -1) | (-(v7485 ^ -1))) >> 31)) & 2)) - (v7486 + ((~(((v7487 ^ -1) | (-(v7487 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v7494 = v7492[v7652];
        int * v7495 = v7443->mem;
        int v7654 = v7491 * 2;
        v7495[v7654] = v7493;
        int * v7497 = v7443->mem;
        int v7657 = (v7491 * 2) + 1;
        v7497[v7657] = v7494;
        ;
      } else {
        ;
      }
      int * v7502 = v7443->mem;
      int v7662 = ((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1)) * 2;
      int v7503 = v7502[v7662];
      int v7663 = (((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1)) * 2) + 1;
      int v7504 = v7502[v7663];
      int * v7505 = v7443->cache_vals;
      int v7665 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v7483 + ((~(((v7485 ^ -1) | (-(v7485 ^ -1))) >> 31)) & 2)) - (v7486 + ((~(((v7487 ^ -1) | (-(v7487 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v7505[v7665] = v7503;
      int * v7507 = v7443->cache_vals;
      int v7668 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v7483 + ((~(((v7485 ^ -1) | (-(v7485 ^ -1))) >> 31)) & 2)) - (v7486 + ((~(((v7487 ^ -1) | (-(v7487 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v7507[v7668] = v7504;
      int * v7509 = v7443->cache_tags;
      int v7671 = (int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1);
      v7509[v7647] = v7671;
      int * v7511 = v7443->cache_dirty;
      v7511[v7647] = 0;
      int * v7513 = v7443->cache_age;
      v7513[v7647] = 1;
      int * v7515 = v7443->cache_age;
      int v7516 = v7515[v7647];
      int v7517 = v7515[v7621];
      int v7677 = v7517 + ((int)((unsigned int)(v7517 - v7516) >> 31));
      v7515[v7621] = v7677;
      int * v7519 = v7443->cache_age;
      int v7520 = v7519[v7622];
      int v7679 = v7520 + ((int)((unsigned int)(v7520 - v7516) >> 31));
      v7519[v7622] = v7679;
      int * v7522 = v7443->cache_age;
      v7522[v7647] = 0;
      v7525 = v7647;
    }
    int * v7526 = v7443->cache_vals;
    int v7682 = v7525 * 2;
    int v7527 = v7526[v7682];
    int v7683 = (v7525 * 2) + 1;
    int v7528 = v7526[v7683];
    int v7684 = (((((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v7467 + ((~(((v7469 ^ -1) | (-(v7469 ^ -1))) >> 31)) & 2)) - (v7470 + ((~(((v7471 ^ -1) | (-(v7471 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7526[v7684] = v7527;
    int * v7530 = v7443->cache_vals;
    int v7687 = ((((((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v7467 + ((~(((v7469 ^ -1) | (-(v7469 ^ -1))) >> 31)) & 2)) - (v7470 + ((~(((v7471 ^ -1) | (-(v7471 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7530[v7687] = v7528;
    int * v7532 = v7443->cache_tags;
    int v7690 = ((((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v7467 + ((~(((v7469 ^ -1) | (-(v7469 ^ -1))) >> 31)) & 2)) - (v7470 + ((~(((v7471 ^ -1) | (-(v7471 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7691 = (int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1);
    v7532[v7690] = v7691;
    int * v7534 = v7443->cache_dirty;
    v7534[v7690] = 0;
    int * v7536 = v7443->cache_age;
    v7536[v7690] = 1;
    int * v7538 = v7443->cache_age;
    int v7539 = v7538[v7690];
    int v7540 = v7538[v7619];
    int v7697 = v7540 + ((int)((unsigned int)(v7540 - v7539) >> 31));
    v7538[v7619] = v7697;
    int * v7542 = v7443->cache_age;
    int v7543 = v7542[v7620];
    int v7699 = v7543 + ((int)((unsigned int)(v7543 - v7539) >> 31));
    v7542[v7620] = v7699;
    int * v7545 = v7443->cache_age;
    v7545[v7690] = 0;
    v7548 = v7690;
  }
  int * v7549 = v7443->cache_vals;
  int v7702 = (v7548 * 2) + (((int)((unsigned int)(v7447 + 24) >> 2)) & 1);
  v7549[v7702] = v7448;
  int * v7551 = v7443->cache_tags;
  int v7552 = v7551[v7621];
  int v7553 = v7551[v7622];
  bool v7705 = !(((~(((v7552 ^ ((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1))) | (-(v7552 ^ ((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v7553 ^ ((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1))) | (-(v7553 ^ ((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v7607;
  if (v7705) {
    int * v7554 = v7443->cache_age;
    int v7707 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7553 ^ ((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1))) | (-(v7553 ^ ((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v7555 = v7554[v7707];
    int v7556 = v7554[v7621];
    int v7708 = v7556 + ((int)((unsigned int)(v7556 - v7555) >> 31));
    v7554[v7621] = v7708;
    int * v7558 = v7443->cache_age;
    int v7559 = v7558[v7622];
    int v7710 = v7559 + ((int)((unsigned int)(v7559 - v7555) >> 31));
    v7558[v7622] = v7710;
    int * v7561 = v7443->cache_age;
    v7561[v7707] = 0;
    v7607 = v7707;
  } else {
    int * v7564 = v7443->cache_age;
    int v7714 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1)) & 3) * 2);
    int v7565 = v7564[v7714];
    int * v7566 = v7443->cache_tags;
    int v7567 = v7566[v7714];
    int v7568 = v7564[v7622];
    int v7569 = v7566[v7622];
    int * v7570 = v7443->cache_dirty;
    int v7717 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v7565 + ((~(((v7567 ^ -1) | (-(v7567 ^ -1))) >> 31)) & 2)) - (v7568 + ((~(((v7569 ^ -1) | (-(v7569 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7571 = v7570[v7717];
    bool v7718 = !(v7571 == 0);
    if (v7718) {
      int * v7572 = v7443->cache_tags;
      int v7573 = v7572[v7717];
      int * v7574 = v7443->cache_vals;
      int v7721 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v7565 + ((~(((v7567 ^ -1) | (-(v7567 ^ -1))) >> 31)) & 2)) - (v7568 + ((~(((v7569 ^ -1) | (-(v7569 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v7575 = v7574[v7721];
      int v7722 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v7565 + ((~(((v7567 ^ -1) | (-(v7567 ^ -1))) >> 31)) & 2)) - (v7568 + ((~(((v7569 ^ -1) | (-(v7569 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v7576 = v7574[v7722];
      int * v7577 = v7443->mem;
      int v7724 = v7573 * 2;
      v7577[v7724] = v7575;
      int * v7579 = v7443->mem;
      int v7727 = (v7573 * 2) + 1;
      v7579[v7727] = v7576;
      ;
    } else {
      ;
    }
    int * v7584 = v7443->mem;
    int v7732 = ((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1)) * 2;
    int v7585 = v7584[v7732];
    int v7733 = (((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1)) * 2) + 1;
    int v7586 = v7584[v7733];
    int * v7587 = v7443->cache_vals;
    int v7735 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v7565 + ((~(((v7567 ^ -1) | (-(v7567 ^ -1))) >> 31)) & 2)) - (v7568 + ((~(((v7569 ^ -1) | (-(v7569 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7587[v7735] = v7585;
    int * v7589 = v7443->cache_vals;
    int v7738 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v7565 + ((~(((v7567 ^ -1) | (-(v7567 ^ -1))) >> 31)) & 2)) - (v7568 + ((~(((v7569 ^ -1) | (-(v7569 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7589[v7738] = v7586;
    int * v7591 = v7443->cache_tags;
    int v7741 = (int)((unsigned int)((int)((unsigned int)(v7447 + 24) >> 2)) >> 1);
    v7591[v7717] = v7741;
    int * v7593 = v7443->cache_dirty;
    v7593[v7717] = 0;
    int * v7595 = v7443->cache_age;
    v7595[v7717] = 1;
    int * v7597 = v7443->cache_age;
    int v7598 = v7597[v7717];
    int v7599 = v7597[v7621];
    int v7747 = v7599 + ((int)((unsigned int)(v7599 - v7598) >> 31));
    v7597[v7621] = v7747;
    int * v7601 = v7443->cache_age;
    int v7602 = v7601[v7622];
    int v7749 = v7602 + ((int)((unsigned int)(v7602 - v7598) >> 31));
    v7601[v7622] = v7749;
    int * v7604 = v7443->cache_age;
    v7604[v7717] = 0;
    v7607 = v7717;
  }
  int * v7608 = v7443->cache_vals;
  int v7752 = (v7607 * 2) + (((int)((unsigned int)(v7447 + 24) >> 2)) & 1);
  v7608[v7752] = v7448;
  int * v7610 = v7443->cache_dirty;
  v7610[v7607] = 1;
  struct StateT * v7612 = slot_202(v7443);
  return v7612;
}

struct StateT * slot_94(struct StateT * v10784) {
  int v10785 = v10784->timer;
  int v10793 = v10785 + 1;
  v10784->timer = v10793;
  int * v10787 = v10784->regs;
  int v10788 = v10787[14];
  int v10789 = v10787[7];
  int v10798 = v10788 + v10789;
  v10787[21] = v10798;
  struct StateT * v10791 = slot_95(v10784);
  return v10791;
}

struct StateT * slot_63(struct StateT * v10301) {
  int v10302 = v10301->timer;
  int v10309 = v10302 + 1;
  v10301->timer = v10309;
  int * v10304 = v10301->regs;
  int v10305 = v10304[22];
  int v10313 = (int)((unsigned int)v10305 >> 23);
  v10304[24] = v10313;
  struct StateT * v10307 = slot_64(v10301);
  return v10307;
}

struct StateT * slot_146(struct StateT * v11594) {
  int v11595 = v11594->timer;
  int v11602 = v11595 + 1;
  v11594->timer = v11602;
  int * v11597 = v11594->regs;
  int v11598 = v11597[23];
  int v11606 = (int)((unsigned int)v11598 >> 23);
  v11597[24] = v11606;
  struct StateT * v11600 = slot_147(v11594);
  return v11600;
}

struct StateT * slot_24(struct StateT * v5325) {
  int v5326 = v5325->timer;
  int v5332 = v5326 + 1;
  v5325->timer = v5332;
  int * v5328 = v5325->regs;
  v5328[28] = 857759744;
  struct StateT * v5330 = slot_25(v5325);
  return v5330;
}

struct StateT * slot_0(struct StateT * v2) {
  int v3 = v2->timer;
  int v10 = v3 + 1;
  v2->timer = v10;
  int * v5 = v2->regs;
  int v6 = v5[2];
  int v13 = v6 + -48;
  v5[2] = v13;
  struct StateT * v8 = slot_1(v2);
  return v8;
}

struct StateT * slot_195(struct StateT * v5456) {
  int v5457 = v5456->timer;
  int v5627 = v5457 + 1;
  v5456->timer = v5627;
  int * v5459 = v5456->regs;
  int v5460 = v5459[10];
  int v5461 = v5459[30];
  int * v5462 = v5456->cache_tags;
  int v5632 = (((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1)) & 1) * 2;
  int v5463 = v5462[v5632];
  int v5633 = ((((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1)) & 1) * 2) + 1;
  int v5464 = v5462[v5633];
  int v5634 = 4 + ((((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1)) & 3) * 2);
  int v5465 = v5462[v5634];
  int v5635 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5466 = v5462[v5635];
  int v5467 = v5456->timer;
  int v5636 = v5467 + ((100 ^ (((~(((v5465 ^ ((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1))) | (-(v5465 ^ ((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1))))) >> 31)) | (~(((v5466 ^ ((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1))) | (-(v5466 ^ ((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5463 ^ ((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1))) | (-(v5463 ^ ((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1))))) >> 31)) | (~(((v5464 ^ ((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1))) | (-(v5464 ^ ((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5465 ^ ((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1))) | (-(v5465 ^ ((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1))))) >> 31)) | (~(((v5466 ^ ((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1))) | (-(v5466 ^ ((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1))))) >> 31))) & 104)))));
  v5456->timer = v5636;
  bool v5637 = !(((~(((v5463 ^ ((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1))) | (-(v5463 ^ ((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1))))) >> 31)) | (~(((v5464 ^ ((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1))) | (-(v5464 ^ ((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1))))) >> 31))) == 0);
  int v5561;
  if (v5637) {
    int * v5469 = v5456->cache_age;
    int v5639 = ((((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1)) & 1) * 2) + ((~(((v5464 ^ ((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1))) | (-(v5464 ^ ((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1))))) >> 31)) & 1);
    int v5470 = v5469[v5639];
    int v5471 = v5469[v5632];
    int v5640 = v5471 + ((int)((unsigned int)(v5471 - v5470) >> 31));
    v5469[v5632] = v5640;
    int * v5473 = v5456->cache_age;
    int v5474 = v5473[v5633];
    int v5642 = v5474 + ((int)((unsigned int)(v5474 - v5470) >> 31));
    v5473[v5633] = v5642;
    int * v5476 = v5456->cache_age;
    v5476[v5639] = 0;
    v5561 = v5639;
  } else {
    int * v5479 = v5456->cache_age;
    int v5646 = (((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1)) & 1) * 2;
    int v5480 = v5479[v5646];
    int * v5481 = v5456->cache_tags;
    int v5482 = v5481[v5646];
    int v5483 = v5479[v5633];
    int v5484 = v5481[v5633];
    bool v5648 = !(((~(((v5465 ^ ((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1))) | (-(v5465 ^ ((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1))))) >> 31)) | (~(((v5466 ^ ((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1))) | (-(v5466 ^ ((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1))))) >> 31))) == 0);
    int v5538;
    if (v5648) {
      int * v5485 = v5456->cache_age;
      int v5650 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1)) & 3) * 2)) + ((~(((v5466 ^ ((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1))) | (-(v5466 ^ ((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1))))) >> 31)) & 1);
      int v5486 = v5485[v5650];
      int v5487 = v5485[v5634];
      int v5651 = v5487 + ((int)((unsigned int)(v5487 - v5486) >> 31));
      v5485[v5634] = v5651;
      int * v5489 = v5456->cache_age;
      int v5490 = v5489[v5635];
      int v5653 = v5490 + ((int)((unsigned int)(v5490 - v5486) >> 31));
      v5489[v5635] = v5653;
      int * v5492 = v5456->cache_age;
      v5492[v5650] = 0;
      v5538 = v5650;
    } else {
      int * v5495 = v5456->cache_age;
      int v5657 = 4 + ((((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1)) & 3) * 2);
      int v5496 = v5495[v5657];
      int * v5497 = v5456->cache_tags;
      int v5498 = v5497[v5657];
      int v5499 = v5495[v5635];
      int v5500 = v5497[v5635];
      int * v5501 = v5456->cache_dirty;
      int v5660 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1)) & 3) * 2)) + ((((v5496 + ((~(((v5498 ^ -1) | (-(v5498 ^ -1))) >> 31)) & 2)) - (v5499 + ((~(((v5500 ^ -1) | (-(v5500 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5502 = v5501[v5660];
      bool v5661 = !(v5502 == 0);
      if (v5661) {
        int * v5503 = v5456->cache_tags;
        int v5504 = v5503[v5660];
        int * v5505 = v5456->cache_vals;
        int v5664 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1)) & 3) * 2)) + ((((v5496 + ((~(((v5498 ^ -1) | (-(v5498 ^ -1))) >> 31)) & 2)) - (v5499 + ((~(((v5500 ^ -1) | (-(v5500 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5506 = v5505[v5664];
        int v5665 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1)) & 3) * 2)) + ((((v5496 + ((~(((v5498 ^ -1) | (-(v5498 ^ -1))) >> 31)) & 2)) - (v5499 + ((~(((v5500 ^ -1) | (-(v5500 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5507 = v5505[v5665];
        int * v5508 = v5456->mem;
        int v5667 = v5504 * 2;
        v5508[v5667] = v5506;
        int * v5510 = v5456->mem;
        int v5670 = (v5504 * 2) + 1;
        v5510[v5670] = v5507;
        ;
      } else {
        ;
      }
      int * v5515 = v5456->mem;
      int v5675 = ((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1)) * 2;
      int v5516 = v5515[v5675];
      int v5676 = (((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1)) * 2) + 1;
      int v5517 = v5515[v5676];
      int * v5518 = v5456->cache_vals;
      int v5678 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1)) & 3) * 2)) + ((((v5496 + ((~(((v5498 ^ -1) | (-(v5498 ^ -1))) >> 31)) & 2)) - (v5499 + ((~(((v5500 ^ -1) | (-(v5500 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5518[v5678] = v5516;
      int * v5520 = v5456->cache_vals;
      int v5681 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1)) & 3) * 2)) + ((((v5496 + ((~(((v5498 ^ -1) | (-(v5498 ^ -1))) >> 31)) & 2)) - (v5499 + ((~(((v5500 ^ -1) | (-(v5500 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5520[v5681] = v5517;
      int * v5522 = v5456->cache_tags;
      int v5684 = (int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1);
      v5522[v5660] = v5684;
      int * v5524 = v5456->cache_dirty;
      v5524[v5660] = 0;
      int * v5526 = v5456->cache_age;
      v5526[v5660] = 1;
      int * v5528 = v5456->cache_age;
      int v5529 = v5528[v5660];
      int v5530 = v5528[v5634];
      int v5690 = v5530 + ((int)((unsigned int)(v5530 - v5529) >> 31));
      v5528[v5634] = v5690;
      int * v5532 = v5456->cache_age;
      int v5533 = v5532[v5635];
      int v5692 = v5533 + ((int)((unsigned int)(v5533 - v5529) >> 31));
      v5532[v5635] = v5692;
      int * v5535 = v5456->cache_age;
      v5535[v5660] = 0;
      v5538 = v5660;
    }
    int * v5539 = v5456->cache_vals;
    int v5695 = v5538 * 2;
    int v5540 = v5539[v5695];
    int v5696 = (v5538 * 2) + 1;
    int v5541 = v5539[v5696];
    int v5697 = (((((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1)) & 1) * 2) + ((((v5480 + ((~(((v5482 ^ -1) | (-(v5482 ^ -1))) >> 31)) & 2)) - (v5483 + ((~(((v5484 ^ -1) | (-(v5484 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5539[v5697] = v5540;
    int * v5543 = v5456->cache_vals;
    int v5700 = ((((((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1)) & 1) * 2) + ((((v5480 + ((~(((v5482 ^ -1) | (-(v5482 ^ -1))) >> 31)) & 2)) - (v5483 + ((~(((v5484 ^ -1) | (-(v5484 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5543[v5700] = v5541;
    int * v5545 = v5456->cache_tags;
    int v5703 = ((((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1)) & 1) * 2) + ((((v5480 + ((~(((v5482 ^ -1) | (-(v5482 ^ -1))) >> 31)) & 2)) - (v5483 + ((~(((v5484 ^ -1) | (-(v5484 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5704 = (int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1);
    v5545[v5703] = v5704;
    int * v5547 = v5456->cache_dirty;
    v5547[v5703] = 0;
    int * v5549 = v5456->cache_age;
    v5549[v5703] = 1;
    int * v5551 = v5456->cache_age;
    int v5552 = v5551[v5703];
    int v5553 = v5551[v5632];
    int v5710 = v5553 + ((int)((unsigned int)(v5553 - v5552) >> 31));
    v5551[v5632] = v5710;
    int * v5555 = v5456->cache_age;
    int v5556 = v5555[v5633];
    int v5712 = v5556 + ((int)((unsigned int)(v5556 - v5552) >> 31));
    v5555[v5633] = v5712;
    int * v5558 = v5456->cache_age;
    v5558[v5703] = 0;
    v5561 = v5703;
  }
  int * v5562 = v5456->cache_vals;
  int v5715 = (v5561 * 2) + (((int)((unsigned int)v5460 >> 2)) & 1);
  v5562[v5715] = v5461;
  int * v5564 = v5456->cache_tags;
  int v5565 = v5564[v5634];
  int v5566 = v5564[v5635];
  bool v5718 = !(((~(((v5565 ^ ((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1))) | (-(v5565 ^ ((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1))))) >> 31)) | (~(((v5566 ^ ((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1))) | (-(v5566 ^ ((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1))))) >> 31))) == 0);
  int v5620;
  if (v5718) {
    int * v5567 = v5456->cache_age;
    int v5720 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1)) & 3) * 2)) + ((~(((v5566 ^ ((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1))) | (-(v5566 ^ ((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1))))) >> 31)) & 1);
    int v5568 = v5567[v5720];
    int v5569 = v5567[v5634];
    int v5721 = v5569 + ((int)((unsigned int)(v5569 - v5568) >> 31));
    v5567[v5634] = v5721;
    int * v5571 = v5456->cache_age;
    int v5572 = v5571[v5635];
    int v5723 = v5572 + ((int)((unsigned int)(v5572 - v5568) >> 31));
    v5571[v5635] = v5723;
    int * v5574 = v5456->cache_age;
    v5574[v5720] = 0;
    v5620 = v5720;
  } else {
    int * v5577 = v5456->cache_age;
    int v5727 = 4 + ((((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1)) & 3) * 2);
    int v5578 = v5577[v5727];
    int * v5579 = v5456->cache_tags;
    int v5580 = v5579[v5727];
    int v5581 = v5577[v5635];
    int v5582 = v5579[v5635];
    int * v5583 = v5456->cache_dirty;
    int v5730 = (4 + ((((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1)) & 3) * 2)) + ((((v5578 + ((~(((v5580 ^ -1) | (-(v5580 ^ -1))) >> 31)) & 2)) - (v5581 + ((~(((v5582 ^ -1) | (-(v5582 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5584 = v5583[v5730];
    bool v5731 = !(v5584 == 0);
    if (v5731) {
      int * v5585 = v5456->cache_tags;
      int v5586 = v5585[v5730];
      int * v5587 = v5456->cache_vals;
      int v5734 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1)) & 3) * 2)) + ((((v5578 + ((~(((v5580 ^ -1) | (-(v5580 ^ -1))) >> 31)) & 2)) - (v5581 + ((~(((v5582 ^ -1) | (-(v5582 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v5588 = v5587[v5734];
      int v5735 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1)) & 3) * 2)) + ((((v5578 + ((~(((v5580 ^ -1) | (-(v5580 ^ -1))) >> 31)) & 2)) - (v5581 + ((~(((v5582 ^ -1) | (-(v5582 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v5589 = v5587[v5735];
      int * v5590 = v5456->mem;
      int v5737 = v5586 * 2;
      v5590[v5737] = v5588;
      int * v5592 = v5456->mem;
      int v5740 = (v5586 * 2) + 1;
      v5592[v5740] = v5589;
      ;
    } else {
      ;
    }
    int * v5597 = v5456->mem;
    int v5745 = ((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1)) * 2;
    int v5598 = v5597[v5745];
    int v5746 = (((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1)) * 2) + 1;
    int v5599 = v5597[v5746];
    int * v5600 = v5456->cache_vals;
    int v5748 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1)) & 3) * 2)) + ((((v5578 + ((~(((v5580 ^ -1) | (-(v5580 ^ -1))) >> 31)) & 2)) - (v5581 + ((~(((v5582 ^ -1) | (-(v5582 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5600[v5748] = v5598;
    int * v5602 = v5456->cache_vals;
    int v5751 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1)) & 3) * 2)) + ((((v5578 + ((~(((v5580 ^ -1) | (-(v5580 ^ -1))) >> 31)) & 2)) - (v5581 + ((~(((v5582 ^ -1) | (-(v5582 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5602[v5751] = v5599;
    int * v5604 = v5456->cache_tags;
    int v5754 = (int)((unsigned int)((int)((unsigned int)v5460 >> 2)) >> 1);
    v5604[v5730] = v5754;
    int * v5606 = v5456->cache_dirty;
    v5606[v5730] = 0;
    int * v5608 = v5456->cache_age;
    v5608[v5730] = 1;
    int * v5610 = v5456->cache_age;
    int v5611 = v5610[v5730];
    int v5612 = v5610[v5634];
    int v5760 = v5612 + ((int)((unsigned int)(v5612 - v5611) >> 31));
    v5610[v5634] = v5760;
    int * v5614 = v5456->cache_age;
    int v5615 = v5614[v5635];
    int v5762 = v5615 + ((int)((unsigned int)(v5615 - v5611) >> 31));
    v5614[v5635] = v5762;
    int * v5617 = v5456->cache_age;
    v5617[v5730] = 0;
    v5620 = v5730;
  }
  int * v5621 = v5456->cache_vals;
  int v5765 = (v5620 * 2) + (((int)((unsigned int)v5460 >> 2)) & 1);
  v5621[v5765] = v5461;
  int * v5623 = v5456->cache_dirty;
  v5623[v5620] = 1;
  struct StateT * v5625 = slot_196(v5456);
  return v5625;
}

struct StateT * slot_125(struct StateT * v11266) {
  int v11267 = v11266->timer;
  int v11275 = v11267 + 1;
  v11266->timer = v11275;
  int * v11269 = v11266->regs;
  int v11270 = v11269[22];
  int v11271 = v11269[24];
  int v11279 = v11270 | v11271;
  v11269[22] = v11279;
  struct StateT * v11273 = slot_126(v11266);
  return v11273;
}

struct StateT * slot_148(struct StateT * v11623) {
  int v11624 = v11623->timer;
  int v11632 = v11624 + 1;
  v11623->timer = v11632;
  int * v11626 = v11623->regs;
  int v11627 = v11626[23];
  int v11628 = v11626[24];
  int v11636 = v11627 | v11628;
  v11626[23] = v11636;
  struct StateT * v11630 = slot_149(v11623);
  return v11630;
}

struct StateT * slot_126(struct StateT * v11282) {
  int v11283 = v11282->timer;
  int v11290 = v11283 + 1;
  v11282->timer = v11290;
  int * v11285 = v11282->regs;
  int v11286 = v11285[23];
  int v11294 = (int)((unsigned int)v11286 >> 25);
  v11285[24] = v11294;
  struct StateT * v11288 = slot_127(v11282);
  return v11288;
}

struct StateT * slot_79(struct StateT * v10552) {
  int v10553 = v10552->timer;
  int v10561 = v10553 + 1;
  v10552->timer = v10561;
  int * v10555 = v10552->regs;
  int v10556 = v10555[20];
  int v10557 = v10555[24];
  int v10565 = v10556 | v10557;
  v10555[20] = v10565;
  struct StateT * v10559 = slot_80(v10552);
  return v10559;
}

struct StateT * slot_41(struct StateT * v8308) {
  int v8309 = v8308->timer;
  int v8316 = v8309 + 1;
  v8308->timer = v8316;
  int * v8311 = v8308->regs;
  int v8312 = v8311[21];
  int v8319 = v8312 << 7;
  v8311[21] = v8319;
  struct StateT * v8314 = slot_42(v8308);
  return v8314;
}

struct StateT * slot_39(struct StateT * v7758) {
  int v7759 = v7758->timer;
  int v7767 = v7759 + 1;
  v7758->timer = v7767;
  int * v7761 = v7758->regs;
  int v7762 = v7761[20];
  int v7763 = v7761[24];
  int v7771 = v7762 | v7763;
  v7761[20] = v7771;
  struct StateT * v7765 = slot_40(v7758);
  return v7765;
}

struct StateT * slot_142(struct StateT * v11533) {
  int v11534 = v11533->timer;
  int v11542 = v11534 + 1;
  v11533->timer = v11542;
  int * v11536 = v11533->regs;
  int v11537 = v11536[21];
  int v11538 = v11536[24];
  int v11546 = v11537 | v11538;
  v11536[21] = v11546;
  struct StateT * v11540 = slot_143(v11533);
  return v11540;
}

struct StateT * slot_60(struct StateT * v10256) {
  int v10257 = v10256->timer;
  int v10264 = v10257 + 1;
  v10256->timer = v10264;
  int * v10259 = v10256->regs;
  int v10260 = v10259[21];
  int v10268 = (int)((unsigned int)v10260 >> 23);
  v10259[24] = v10268;
  struct StateT * v10262 = slot_61(v10256);
  return v10262;
}

struct StateT * slot_112(struct StateT * v11063) {
  int v11064 = v11063->timer;
  int v11072 = v11064 + 1;
  v11063->timer = v11072;
  int * v11066 = v11063->regs;
  int v11067 = v11066[31];
  int v11068 = v11066[23];
  int v11076 = v11067 ^ v11068;
  v11066[31] = v11076;
  struct StateT * v11070 = slot_113(v11063);
  return v11070;
}

struct StateT * slot_47(struct StateT * v9622) {
  int v9623 = v9622->timer;
  int v9630 = v9623 + 1;
  v9622->timer = v9630;
  int * v9625 = v9622->regs;
  int v9626 = v9625[23];
  int v9633 = v9626 << 7;
  v9625[23] = v9633;
  struct StateT * v9628 = slot_48(v9622);
  return v9628;
}

struct StateT * slot_29(struct StateT * v5396) {
  int v5397 = v5396->timer;
  int v5403 = v5397 + 1;
  v5396->timer = v5403;
  int * v5399 = v5396->regs;
  v5399[31] = 1797283840;
  struct StateT * v5401 = slot_30(v5396);
  return v5401;
}

struct StateT * slot_16(struct StateT * v3884) {
  int v3885 = v3884->timer;
  int v3995 = v3885 + 1;
  v3884->timer = v3995;
  int * v3887 = v3884->regs;
  int v3888 = v3887[12];
  int * v3889 = v3884->cache_tags;
  int v3999 = (((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1)) & 1) * 2;
  int v3890 = v3889[v3999];
  int v4000 = ((((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1)) & 1) * 2) + 1;
  int v3891 = v3889[v4000];
  int v4001 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1)) & 3) * 2);
  int v3892 = v3889[v4001];
  int v4002 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3893 = v3889[v4002];
  int v3894 = v3884->timer;
  int v4003 = v3894 + ((100 ^ (((~(((v3892 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))) | (-(v3892 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v3893 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))) | (-(v3893 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3890 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))) | (-(v3890 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v3891 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))) | (-(v3891 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3892 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))) | (-(v3892 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v3893 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))) | (-(v3893 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))))) >> 31))) & 104)))));
  v3884->timer = v4003;
  int * v3896 = v3884->cache_vals;
  bool v4004 = !(((~(((v3890 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))) | (-(v3890 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v3891 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))) | (-(v3891 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v3989;
  if (v4004) {
    int * v3897 = v3884->cache_age;
    int v4006 = ((((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1)) & 1) * 2) + ((~(((v3891 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))) | (-(v3891 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v3898 = v3897[v4006];
    int v3899 = v3897[v3999];
    int v4007 = v3899 + ((int)((unsigned int)(v3899 - v3898) >> 31));
    v3897[v3999] = v4007;
    int * v3901 = v3884->cache_age;
    int v3902 = v3901[v4000];
    int v4009 = v3902 + ((int)((unsigned int)(v3902 - v3898) >> 31));
    v3901[v4000] = v4009;
    int * v3904 = v3884->cache_age;
    v3904[v4006] = 0;
    v3989 = v4006;
  } else {
    int * v3907 = v3884->cache_age;
    int v4013 = (((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1)) & 1) * 2;
    int v3908 = v3907[v4013];
    int * v3909 = v3884->cache_tags;
    int v3910 = v3909[v4013];
    int v3911 = v3907[v4000];
    int v3912 = v3909[v4000];
    bool v4015 = !(((~(((v3892 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))) | (-(v3892 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v3893 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))) | (-(v3893 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))))) >> 31))) == 0);
    int v3966;
    if (v4015) {
      int * v3913 = v3884->cache_age;
      int v4017 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3893 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))) | (-(v3893 ^ ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1))))) >> 31)) & 1);
      int v3914 = v3913[v4017];
      int v3915 = v3913[v4001];
      int v4018 = v3915 + ((int)((unsigned int)(v3915 - v3914) >> 31));
      v3913[v4001] = v4018;
      int * v3917 = v3884->cache_age;
      int v3918 = v3917[v4002];
      int v4020 = v3918 + ((int)((unsigned int)(v3918 - v3914) >> 31));
      v3917[v4002] = v4020;
      int * v3920 = v3884->cache_age;
      v3920[v4017] = 0;
      v3966 = v4017;
    } else {
      int * v3923 = v3884->cache_age;
      int v4024 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1)) & 3) * 2);
      int v3924 = v3923[v4024];
      int * v3925 = v3884->cache_tags;
      int v3926 = v3925[v4024];
      int v3927 = v3923[v4002];
      int v3928 = v3925[v4002];
      int * v3929 = v3884->cache_dirty;
      int v4027 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v3924 + ((~(((v3926 ^ -1) | (-(v3926 ^ -1))) >> 31)) & 2)) - (v3927 + ((~(((v3928 ^ -1) | (-(v3928 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3930 = v3929[v4027];
      bool v4028 = !(v3930 == 0);
      if (v4028) {
        int * v3931 = v3884->cache_tags;
        int v3932 = v3931[v4027];
        int * v3933 = v3884->cache_vals;
        int v4031 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v3924 + ((~(((v3926 ^ -1) | (-(v3926 ^ -1))) >> 31)) & 2)) - (v3927 + ((~(((v3928 ^ -1) | (-(v3928 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3934 = v3933[v4031];
        int v4032 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v3924 + ((~(((v3926 ^ -1) | (-(v3926 ^ -1))) >> 31)) & 2)) - (v3927 + ((~(((v3928 ^ -1) | (-(v3928 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3935 = v3933[v4032];
        int * v3936 = v3884->mem;
        int v4034 = v3932 * 2;
        v3936[v4034] = v3934;
        int * v3938 = v3884->mem;
        int v4037 = (v3932 * 2) + 1;
        v3938[v4037] = v3935;
        ;
      } else {
        ;
      }
      int * v3943 = v3884->mem;
      int v4042 = ((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1)) * 2;
      int v3944 = v3943[v4042];
      int v4043 = (((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1)) * 2) + 1;
      int v3945 = v3943[v4043];
      int * v3946 = v3884->cache_vals;
      int v4045 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v3924 + ((~(((v3926 ^ -1) | (-(v3926 ^ -1))) >> 31)) & 2)) - (v3927 + ((~(((v3928 ^ -1) | (-(v3928 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3946[v4045] = v3944;
      int * v3948 = v3884->cache_vals;
      int v4048 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v3924 + ((~(((v3926 ^ -1) | (-(v3926 ^ -1))) >> 31)) & 2)) - (v3927 + ((~(((v3928 ^ -1) | (-(v3928 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3948[v4048] = v3945;
      int * v3950 = v3884->cache_tags;
      int v4051 = (int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1);
      v3950[v4027] = v4051;
      int * v3952 = v3884->cache_dirty;
      v3952[v4027] = 0;
      int * v3954 = v3884->cache_age;
      v3954[v4027] = 1;
      int * v3956 = v3884->cache_age;
      int v3957 = v3956[v4027];
      int v3958 = v3956[v4001];
      int v4057 = v3958 + ((int)((unsigned int)(v3958 - v3957) >> 31));
      v3956[v4001] = v4057;
      int * v3960 = v3884->cache_age;
      int v3961 = v3960[v4002];
      int v4059 = v3961 + ((int)((unsigned int)(v3961 - v3957) >> 31));
      v3960[v4002] = v4059;
      int * v3963 = v3884->cache_age;
      v3963[v4027] = 0;
      v3966 = v4027;
    }
    int * v3967 = v3884->cache_vals;
    int v4062 = v3966 * 2;
    int v3968 = v3967[v4062];
    int v4063 = (v3966 * 2) + 1;
    int v3969 = v3967[v4063];
    int v4064 = (((((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v3908 + ((~(((v3910 ^ -1) | (-(v3910 ^ -1))) >> 31)) & 2)) - (v3911 + ((~(((v3912 ^ -1) | (-(v3912 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3967[v4064] = v3968;
    int * v3971 = v3884->cache_vals;
    int v4067 = ((((((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v3908 + ((~(((v3910 ^ -1) | (-(v3910 ^ -1))) >> 31)) & 2)) - (v3911 + ((~(((v3912 ^ -1) | (-(v3912 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3971[v4067] = v3969;
    int * v3973 = v3884->cache_tags;
    int v4070 = ((((int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v3908 + ((~(((v3910 ^ -1) | (-(v3910 ^ -1))) >> 31)) & 2)) - (v3911 + ((~(((v3912 ^ -1) | (-(v3912 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4071 = (int)((unsigned int)((int)((unsigned int)(v3888 + 20) >> 2)) >> 1);
    v3973[v4070] = v4071;
    int * v3975 = v3884->cache_dirty;
    v3975[v4070] = 0;
    int * v3977 = v3884->cache_age;
    v3977[v4070] = 1;
    int * v3979 = v3884->cache_age;
    int v3980 = v3979[v4070];
    int v3981 = v3979[v3999];
    int v4077 = v3981 + ((int)((unsigned int)(v3981 - v3980) >> 31));
    v3979[v3999] = v4077;
    int * v3983 = v3884->cache_age;
    int v3984 = v3983[v4000];
    int v4079 = v3984 + ((int)((unsigned int)(v3984 - v3980) >> 31));
    v3983[v4000] = v4079;
    int * v3986 = v3884->cache_age;
    v3986[v4070] = 0;
    v3989 = v4070;
  }
  int v4082 = (v3989 * 2) + (((int)((unsigned int)(v3888 + 20) >> 2)) & 1);
  int v3990 = v3896[v4082];
  int * v3991 = v3884->regs;
  v3991[16] = v3990;
  struct StateT * v3993 = slot_17(v3884);
  return v3993;
}

struct StateT * slot_113(struct StateT * v11079) {
  int v11080 = v11079->timer;
  int v11088 = v11080 + 1;
  v11079->timer = v11088;
  int * v11082 = v11079->regs;
  int v11083 = v11082[30];
  int v11084 = v11082[8];
  int v11093 = v11083 + v11084;
  v11082[20] = v11093;
  struct StateT * v11086 = slot_114(v11079);
  return v11086;
}

struct StateT * slot_151(struct StateT * v11671) {
  int v11672 = v11671->timer;
  int v11680 = v11672 + 1;
  v11671->timer = v11680;
  int * v11674 = v11671->regs;
  int v11675 = v11674[6];
  int v11676 = v11674[22];
  int v11684 = v11675 ^ v11676;
  v11674[6] = v11684;
  struct StateT * v11678 = slot_152(v11671);
  return v11678;
}

struct StateT * slot_7(struct StateT * v1906) {
  int v1907 = v1906->timer;
  int v2077 = v1907 + 1;
  v1906->timer = v2077;
  int * v1909 = v1906->regs;
  int v1910 = v1909[2];
  int v1911 = v1909[22];
  int * v1912 = v1906->cache_tags;
  int v2082 = (((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 1) * 2;
  int v1913 = v1912[v2082];
  int v2083 = ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1914 = v1912[v2083];
  int v2084 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 3) * 2);
  int v1915 = v1912[v2084];
  int v2085 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1916 = v1912[v2085];
  int v1917 = v1906->timer;
  int v2086 = v1917 + ((100 ^ (((~(((v1915 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))) | (-(v1915 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v1916 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))) | (-(v1916 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1913 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))) | (-(v1913 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v1914 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))) | (-(v1914 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1915 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))) | (-(v1915 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v1916 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))) | (-(v1916 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1906->timer = v2086;
  bool v2087 = !(((~(((v1913 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))) | (-(v1913 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v1914 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))) | (-(v1914 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v2011;
  if (v2087) {
    int * v1919 = v1906->cache_age;
    int v2089 = ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 1) * 2) + ((~(((v1914 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))) | (-(v1914 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v1920 = v1919[v2089];
    int v1921 = v1919[v2082];
    int v2090 = v1921 + ((int)((unsigned int)(v1921 - v1920) >> 31));
    v1919[v2082] = v2090;
    int * v1923 = v1906->cache_age;
    int v1924 = v1923[v2083];
    int v2092 = v1924 + ((int)((unsigned int)(v1924 - v1920) >> 31));
    v1923[v2083] = v2092;
    int * v1926 = v1906->cache_age;
    v1926[v2089] = 0;
    v2011 = v2089;
  } else {
    int * v1929 = v1906->cache_age;
    int v2096 = (((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 1) * 2;
    int v1930 = v1929[v2096];
    int * v1931 = v1906->cache_tags;
    int v1932 = v1931[v2096];
    int v1933 = v1929[v2083];
    int v1934 = v1931[v2083];
    bool v2098 = !(((~(((v1915 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))) | (-(v1915 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v1916 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))) | (-(v1916 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))))) >> 31))) == 0);
    int v1988;
    if (v2098) {
      int * v1935 = v1906->cache_age;
      int v2100 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1916 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))) | (-(v1916 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))))) >> 31)) & 1);
      int v1936 = v1935[v2100];
      int v1937 = v1935[v2084];
      int v2101 = v1937 + ((int)((unsigned int)(v1937 - v1936) >> 31));
      v1935[v2084] = v2101;
      int * v1939 = v1906->cache_age;
      int v1940 = v1939[v2085];
      int v2103 = v1940 + ((int)((unsigned int)(v1940 - v1936) >> 31));
      v1939[v2085] = v2103;
      int * v1942 = v1906->cache_age;
      v1942[v2100] = 0;
      v1988 = v2100;
    } else {
      int * v1945 = v1906->cache_age;
      int v2107 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 3) * 2);
      int v1946 = v1945[v2107];
      int * v1947 = v1906->cache_tags;
      int v1948 = v1947[v2107];
      int v1949 = v1945[v2085];
      int v1950 = v1947[v2085];
      int * v1951 = v1906->cache_dirty;
      int v2110 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v1946 + ((~(((v1948 ^ -1) | (-(v1948 ^ -1))) >> 31)) & 2)) - (v1949 + ((~(((v1950 ^ -1) | (-(v1950 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1952 = v1951[v2110];
      bool v2111 = !(v1952 == 0);
      if (v2111) {
        int * v1953 = v1906->cache_tags;
        int v1954 = v1953[v2110];
        int * v1955 = v1906->cache_vals;
        int v2114 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v1946 + ((~(((v1948 ^ -1) | (-(v1948 ^ -1))) >> 31)) & 2)) - (v1949 + ((~(((v1950 ^ -1) | (-(v1950 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1956 = v1955[v2114];
        int v2115 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v1946 + ((~(((v1948 ^ -1) | (-(v1948 ^ -1))) >> 31)) & 2)) - (v1949 + ((~(((v1950 ^ -1) | (-(v1950 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1957 = v1955[v2115];
        int * v1958 = v1906->mem;
        int v2117 = v1954 * 2;
        v1958[v2117] = v1956;
        int * v1960 = v1906->mem;
        int v2120 = (v1954 * 2) + 1;
        v1960[v2120] = v1957;
        ;
      } else {
        ;
      }
      int * v1965 = v1906->mem;
      int v2125 = ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) * 2;
      int v1966 = v1965[v2125];
      int v2126 = (((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) * 2) + 1;
      int v1967 = v1965[v2126];
      int * v1968 = v1906->cache_vals;
      int v2128 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v1946 + ((~(((v1948 ^ -1) | (-(v1948 ^ -1))) >> 31)) & 2)) - (v1949 + ((~(((v1950 ^ -1) | (-(v1950 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1968[v2128] = v1966;
      int * v1970 = v1906->cache_vals;
      int v2131 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v1946 + ((~(((v1948 ^ -1) | (-(v1948 ^ -1))) >> 31)) & 2)) - (v1949 + ((~(((v1950 ^ -1) | (-(v1950 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1970[v2131] = v1967;
      int * v1972 = v1906->cache_tags;
      int v2134 = (int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1);
      v1972[v2110] = v2134;
      int * v1974 = v1906->cache_dirty;
      v1974[v2110] = 0;
      int * v1976 = v1906->cache_age;
      v1976[v2110] = 1;
      int * v1978 = v1906->cache_age;
      int v1979 = v1978[v2110];
      int v1980 = v1978[v2084];
      int v2140 = v1980 + ((int)((unsigned int)(v1980 - v1979) >> 31));
      v1978[v2084] = v2140;
      int * v1982 = v1906->cache_age;
      int v1983 = v1982[v2085];
      int v2142 = v1983 + ((int)((unsigned int)(v1983 - v1979) >> 31));
      v1982[v2085] = v2142;
      int * v1985 = v1906->cache_age;
      v1985[v2110] = 0;
      v1988 = v2110;
    }
    int * v1989 = v1906->cache_vals;
    int v2145 = v1988 * 2;
    int v1990 = v1989[v2145];
    int v2146 = (v1988 * 2) + 1;
    int v1991 = v1989[v2146];
    int v2147 = (((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v1930 + ((~(((v1932 ^ -1) | (-(v1932 ^ -1))) >> 31)) & 2)) - (v1933 + ((~(((v1934 ^ -1) | (-(v1934 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1989[v2147] = v1990;
    int * v1993 = v1906->cache_vals;
    int v2150 = ((((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v1930 + ((~(((v1932 ^ -1) | (-(v1932 ^ -1))) >> 31)) & 2)) - (v1933 + ((~(((v1934 ^ -1) | (-(v1934 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1993[v2150] = v1991;
    int * v1995 = v1906->cache_tags;
    int v2153 = ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v1930 + ((~(((v1932 ^ -1) | (-(v1932 ^ -1))) >> 31)) & 2)) - (v1933 + ((~(((v1934 ^ -1) | (-(v1934 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2154 = (int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1);
    v1995[v2153] = v2154;
    int * v1997 = v1906->cache_dirty;
    v1997[v2153] = 0;
    int * v1999 = v1906->cache_age;
    v1999[v2153] = 1;
    int * v2001 = v1906->cache_age;
    int v2002 = v2001[v2153];
    int v2003 = v2001[v2082];
    int v2160 = v2003 + ((int)((unsigned int)(v2003 - v2002) >> 31));
    v2001[v2082] = v2160;
    int * v2005 = v1906->cache_age;
    int v2006 = v2005[v2083];
    int v2162 = v2006 + ((int)((unsigned int)(v2006 - v2002) >> 31));
    v2005[v2083] = v2162;
    int * v2008 = v1906->cache_age;
    v2008[v2153] = 0;
    v2011 = v2153;
  }
  int * v2012 = v1906->cache_vals;
  int v2165 = (v2011 * 2) + (((int)((unsigned int)(v1910 + 20) >> 2)) & 1);
  v2012[v2165] = v1911;
  int * v2014 = v1906->cache_tags;
  int v2015 = v2014[v2084];
  int v2016 = v2014[v2085];
  bool v2168 = !(((~(((v2015 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))) | (-(v2015 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v2016 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))) | (-(v2016 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v2070;
  if (v2168) {
    int * v2017 = v1906->cache_age;
    int v2170 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2016 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))) | (-(v2016 ^ ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v2018 = v2017[v2170];
    int v2019 = v2017[v2084];
    int v2171 = v2019 + ((int)((unsigned int)(v2019 - v2018) >> 31));
    v2017[v2084] = v2171;
    int * v2021 = v1906->cache_age;
    int v2022 = v2021[v2085];
    int v2173 = v2022 + ((int)((unsigned int)(v2022 - v2018) >> 31));
    v2021[v2085] = v2173;
    int * v2024 = v1906->cache_age;
    v2024[v2170] = 0;
    v2070 = v2170;
  } else {
    int * v2027 = v1906->cache_age;
    int v2177 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 3) * 2);
    int v2028 = v2027[v2177];
    int * v2029 = v1906->cache_tags;
    int v2030 = v2029[v2177];
    int v2031 = v2027[v2085];
    int v2032 = v2029[v2085];
    int * v2033 = v1906->cache_dirty;
    int v2180 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v2028 + ((~(((v2030 ^ -1) | (-(v2030 ^ -1))) >> 31)) & 2)) - (v2031 + ((~(((v2032 ^ -1) | (-(v2032 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2034 = v2033[v2180];
    bool v2181 = !(v2034 == 0);
    if (v2181) {
      int * v2035 = v1906->cache_tags;
      int v2036 = v2035[v2180];
      int * v2037 = v1906->cache_vals;
      int v2184 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v2028 + ((~(((v2030 ^ -1) | (-(v2030 ^ -1))) >> 31)) & 2)) - (v2031 + ((~(((v2032 ^ -1) | (-(v2032 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v2038 = v2037[v2184];
      int v2185 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v2028 + ((~(((v2030 ^ -1) | (-(v2030 ^ -1))) >> 31)) & 2)) - (v2031 + ((~(((v2032 ^ -1) | (-(v2032 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v2039 = v2037[v2185];
      int * v2040 = v1906->mem;
      int v2187 = v2036 * 2;
      v2040[v2187] = v2038;
      int * v2042 = v1906->mem;
      int v2190 = (v2036 * 2) + 1;
      v2042[v2190] = v2039;
      ;
    } else {
      ;
    }
    int * v2047 = v1906->mem;
    int v2195 = ((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) * 2;
    int v2048 = v2047[v2195];
    int v2196 = (((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) * 2) + 1;
    int v2049 = v2047[v2196];
    int * v2050 = v1906->cache_vals;
    int v2198 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v2028 + ((~(((v2030 ^ -1) | (-(v2030 ^ -1))) >> 31)) & 2)) - (v2031 + ((~(((v2032 ^ -1) | (-(v2032 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2050[v2198] = v2048;
    int * v2052 = v1906->cache_vals;
    int v2201 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v2028 + ((~(((v2030 ^ -1) | (-(v2030 ^ -1))) >> 31)) & 2)) - (v2031 + ((~(((v2032 ^ -1) | (-(v2032 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2052[v2201] = v2049;
    int * v2054 = v1906->cache_tags;
    int v2204 = (int)((unsigned int)((int)((unsigned int)(v1910 + 20) >> 2)) >> 1);
    v2054[v2180] = v2204;
    int * v2056 = v1906->cache_dirty;
    v2056[v2180] = 0;
    int * v2058 = v1906->cache_age;
    v2058[v2180] = 1;
    int * v2060 = v1906->cache_age;
    int v2061 = v2060[v2180];
    int v2062 = v2060[v2084];
    int v2210 = v2062 + ((int)((unsigned int)(v2062 - v2061) >> 31));
    v2060[v2084] = v2210;
    int * v2064 = v1906->cache_age;
    int v2065 = v2064[v2085];
    int v2212 = v2065 + ((int)((unsigned int)(v2065 - v2061) >> 31));
    v2064[v2085] = v2212;
    int * v2067 = v1906->cache_age;
    v2067[v2180] = 0;
    v2070 = v2180;
  }
  int * v2071 = v1906->cache_vals;
  int v2215 = (v2070 * 2) + (((int)((unsigned int)(v1910 + 20) >> 2)) & 1);
  v2071[v2215] = v1911;
  int * v2073 = v1906->cache_dirty;
  v2073[v2070] = 1;
  struct StateT * v2075 = slot_8(v1906);
  return v2075;
}

struct StateT * slot_124(struct StateT * v11252) {
  int v11253 = v11252->timer;
  int v11260 = v11253 + 1;
  v11252->timer = v11260;
  int * v11255 = v11252->regs;
  int v11256 = v11255[22];
  int v11263 = v11256 << 7;
  v11255[22] = v11263;
  struct StateT * v11258 = slot_125(v11252);
  return v11258;
}

struct StateT * slot_191(struct StateT * v12295) {
  int v12296 = v12295->timer;
  int v12304 = v12296 + 1;
  v12295->timer = v12304;
  int * v12298 = v12295->regs;
  int v12299 = v12298[28];
  int v12300 = v12298[22];
  int v12308 = v12299 ^ v12300;
  v12298[28] = v12308;
  struct StateT * v12302 = slot_192(v12295);
  return v12302;
}

struct StateT * slot_103(struct StateT * v10925) {
  int v10926 = v10925->timer;
  int v10933 = v10926 + 1;
  v10925->timer = v10933;
  int * v10928 = v10925->regs;
  int v10929 = v10928[22];
  int v10937 = (int)((unsigned int)v10929 >> 14);
  v10928[24] = v10937;
  struct StateT * v10931 = slot_104(v10925);
  return v10931;
}

struct StateT * slot_128(struct StateT * v11311) {
  int v11312 = v11311->timer;
  int v11320 = v11312 + 1;
  v11311->timer = v11320;
  int * v11314 = v11311->regs;
  int v11315 = v11314[23];
  int v11316 = v11314[24];
  int v11324 = v11315 | v11316;
  v11314[23] = v11324;
  struct StateT * v11318 = slot_129(v11311);
  return v11318;
}

struct StateT * slot_19(struct StateT * v4496) {
  int v4497 = v4496->timer;
  int v4607 = v4497 + 1;
  v4496->timer = v4607;
  int * v4499 = v4496->regs;
  int v4500 = v4499[11];
  int * v4501 = v4496->cache_tags;
  int v4611 = (((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1)) & 1) * 2;
  int v4502 = v4501[v4611];
  int v4612 = ((((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1)) & 1) * 2) + 1;
  int v4503 = v4501[v4612];
  int v4613 = 4 + ((((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1)) & 3) * 2);
  int v4504 = v4501[v4613];
  int v4614 = (4 + ((((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4505 = v4501[v4614];
  int v4506 = v4496->timer;
  int v4615 = v4506 + ((100 ^ (((~(((v4504 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))) | (-(v4504 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))))) >> 31)) | (~(((v4505 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))) | (-(v4505 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4502 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))) | (-(v4502 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))))) >> 31)) | (~(((v4503 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))) | (-(v4503 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4504 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))) | (-(v4504 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))))) >> 31)) | (~(((v4505 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))) | (-(v4505 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))))) >> 31))) & 104)))));
  v4496->timer = v4615;
  int * v4508 = v4496->cache_vals;
  bool v4616 = !(((~(((v4502 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))) | (-(v4502 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))))) >> 31)) | (~(((v4503 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))) | (-(v4503 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))))) >> 31))) == 0);
  int v4601;
  if (v4616) {
    int * v4509 = v4496->cache_age;
    int v4618 = ((((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1)) & 1) * 2) + ((~(((v4503 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))) | (-(v4503 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))))) >> 31)) & 1);
    int v4510 = v4509[v4618];
    int v4511 = v4509[v4611];
    int v4619 = v4511 + ((int)((unsigned int)(v4511 - v4510) >> 31));
    v4509[v4611] = v4619;
    int * v4513 = v4496->cache_age;
    int v4514 = v4513[v4612];
    int v4621 = v4514 + ((int)((unsigned int)(v4514 - v4510) >> 31));
    v4513[v4612] = v4621;
    int * v4516 = v4496->cache_age;
    v4516[v4618] = 0;
    v4601 = v4618;
  } else {
    int * v4519 = v4496->cache_age;
    int v4625 = (((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1)) & 1) * 2;
    int v4520 = v4519[v4625];
    int * v4521 = v4496->cache_tags;
    int v4522 = v4521[v4625];
    int v4523 = v4519[v4612];
    int v4524 = v4521[v4612];
    bool v4627 = !(((~(((v4504 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))) | (-(v4504 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))))) >> 31)) | (~(((v4505 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))) | (-(v4505 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))))) >> 31))) == 0);
    int v4578;
    if (v4627) {
      int * v4525 = v4496->cache_age;
      int v4629 = (4 + ((((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1)) & 3) * 2)) + ((~(((v4505 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))) | (-(v4505 ^ ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1))))) >> 31)) & 1);
      int v4526 = v4525[v4629];
      int v4527 = v4525[v4613];
      int v4630 = v4527 + ((int)((unsigned int)(v4527 - v4526) >> 31));
      v4525[v4613] = v4630;
      int * v4529 = v4496->cache_age;
      int v4530 = v4529[v4614];
      int v4632 = v4530 + ((int)((unsigned int)(v4530 - v4526) >> 31));
      v4529[v4614] = v4632;
      int * v4532 = v4496->cache_age;
      v4532[v4629] = 0;
      v4578 = v4629;
    } else {
      int * v4535 = v4496->cache_age;
      int v4636 = 4 + ((((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1)) & 3) * 2);
      int v4536 = v4535[v4636];
      int * v4537 = v4496->cache_tags;
      int v4538 = v4537[v4636];
      int v4539 = v4535[v4614];
      int v4540 = v4537[v4614];
      int * v4541 = v4496->cache_dirty;
      int v4639 = (4 + ((((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1)) & 3) * 2)) + ((((v4536 + ((~(((v4538 ^ -1) | (-(v4538 ^ -1))) >> 31)) & 2)) - (v4539 + ((~(((v4540 ^ -1) | (-(v4540 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4542 = v4541[v4639];
      bool v4640 = !(v4542 == 0);
      if (v4640) {
        int * v4543 = v4496->cache_tags;
        int v4544 = v4543[v4639];
        int * v4545 = v4496->cache_vals;
        int v4643 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1)) & 3) * 2)) + ((((v4536 + ((~(((v4538 ^ -1) | (-(v4538 ^ -1))) >> 31)) & 2)) - (v4539 + ((~(((v4540 ^ -1) | (-(v4540 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4546 = v4545[v4643];
        int v4644 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1)) & 3) * 2)) + ((((v4536 + ((~(((v4538 ^ -1) | (-(v4538 ^ -1))) >> 31)) & 2)) - (v4539 + ((~(((v4540 ^ -1) | (-(v4540 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4547 = v4545[v4644];
        int * v4548 = v4496->mem;
        int v4646 = v4544 * 2;
        v4548[v4646] = v4546;
        int * v4550 = v4496->mem;
        int v4649 = (v4544 * 2) + 1;
        v4550[v4649] = v4547;
        ;
      } else {
        ;
      }
      int * v4555 = v4496->mem;
      int v4654 = ((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1)) * 2;
      int v4556 = v4555[v4654];
      int v4655 = (((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1)) * 2) + 1;
      int v4557 = v4555[v4655];
      int * v4558 = v4496->cache_vals;
      int v4657 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1)) & 3) * 2)) + ((((v4536 + ((~(((v4538 ^ -1) | (-(v4538 ^ -1))) >> 31)) & 2)) - (v4539 + ((~(((v4540 ^ -1) | (-(v4540 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4558[v4657] = v4556;
      int * v4560 = v4496->cache_vals;
      int v4660 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1)) & 3) * 2)) + ((((v4536 + ((~(((v4538 ^ -1) | (-(v4538 ^ -1))) >> 31)) & 2)) - (v4539 + ((~(((v4540 ^ -1) | (-(v4540 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4560[v4660] = v4557;
      int * v4562 = v4496->cache_tags;
      int v4663 = (int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1);
      v4562[v4639] = v4663;
      int * v4564 = v4496->cache_dirty;
      v4564[v4639] = 0;
      int * v4566 = v4496->cache_age;
      v4566[v4639] = 1;
      int * v4568 = v4496->cache_age;
      int v4569 = v4568[v4639];
      int v4570 = v4568[v4613];
      int v4669 = v4570 + ((int)((unsigned int)(v4570 - v4569) >> 31));
      v4568[v4613] = v4669;
      int * v4572 = v4496->cache_age;
      int v4573 = v4572[v4614];
      int v4671 = v4573 + ((int)((unsigned int)(v4573 - v4569) >> 31));
      v4572[v4614] = v4671;
      int * v4575 = v4496->cache_age;
      v4575[v4639] = 0;
      v4578 = v4639;
    }
    int * v4579 = v4496->cache_vals;
    int v4674 = v4578 * 2;
    int v4580 = v4579[v4674];
    int v4675 = (v4578 * 2) + 1;
    int v4581 = v4579[v4675];
    int v4676 = (((((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1)) & 1) * 2) + ((((v4520 + ((~(((v4522 ^ -1) | (-(v4522 ^ -1))) >> 31)) & 2)) - (v4523 + ((~(((v4524 ^ -1) | (-(v4524 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4579[v4676] = v4580;
    int * v4583 = v4496->cache_vals;
    int v4679 = ((((((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1)) & 1) * 2) + ((((v4520 + ((~(((v4522 ^ -1) | (-(v4522 ^ -1))) >> 31)) & 2)) - (v4523 + ((~(((v4524 ^ -1) | (-(v4524 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4583[v4679] = v4581;
    int * v4585 = v4496->cache_tags;
    int v4682 = ((((int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1)) & 1) * 2) + ((((v4520 + ((~(((v4522 ^ -1) | (-(v4522 ^ -1))) >> 31)) & 2)) - (v4523 + ((~(((v4524 ^ -1) | (-(v4524 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4683 = (int)((unsigned int)((int)((unsigned int)v4500 >> 2)) >> 1);
    v4585[v4682] = v4683;
    int * v4587 = v4496->cache_dirty;
    v4587[v4682] = 0;
    int * v4589 = v4496->cache_age;
    v4589[v4682] = 1;
    int * v4591 = v4496->cache_age;
    int v4592 = v4591[v4682];
    int v4593 = v4591[v4611];
    int v4689 = v4593 + ((int)((unsigned int)(v4593 - v4592) >> 31));
    v4591[v4611] = v4689;
    int * v4595 = v4496->cache_age;
    int v4596 = v4595[v4612];
    int v4691 = v4596 + ((int)((unsigned int)(v4596 - v4592) >> 31));
    v4595[v4612] = v4691;
    int * v4598 = v4496->cache_age;
    v4598[v4682] = 0;
    v4601 = v4682;
  }
  int v4694 = (v4601 * 2) + (((int)((unsigned int)v4500 >> 2)) & 1);
  int v4602 = v4508[v4694];
  int * v4603 = v4496->regs;
  v4603[12] = v4602;
  struct StateT * v4605 = slot_20(v4496);
  return v4605;
}

struct StateT * slot_87(struct StateT * v10673) {
  int v10674 = v10673->timer;
  int v10681 = v10674 + 1;
  v10673->timer = v10681;
  int * v10676 = v10673->regs;
  int v10677 = v10676[23];
  int v10684 = v10677 << 13;
  v10676[23] = v10684;
  struct StateT * v10679 = slot_88(v10673);
  return v10679;
}

struct StateT * slot_67(struct StateT * v10361) {
  int v10362 = v10361->timer;
  int v10369 = v10362 + 1;
  v10361->timer = v10369;
  int * v10364 = v10361->regs;
  int v10365 = v10364[23];
  int v10372 = v10365 << 9;
  v10364[23] = v10372;
  struct StateT * v10367 = slot_68(v10361);
  return v10367;
}

struct StateT * slot_81(struct StateT * v10583) {
  int v10584 = v10583->timer;
  int v10591 = v10584 + 1;
  v10583->timer = v10591;
  int * v10586 = v10583->regs;
  int v10587 = v10586[21];
  int v10594 = v10587 << 13;
  v10586[21] = v10594;
  struct StateT * v10589 = slot_82(v10583);
  return v10589;
}

struct StateT * slot_95(struct StateT * v10801) {
  int v10802 = v10801->timer;
  int v10810 = v10802 + 1;
  v10801->timer = v10810;
  int * v10804 = v10801->regs;
  int v10805 = v10804[12];
  int v10806 = v10804[17];
  int v10815 = v10805 + v10806;
  v10804[22] = v10815;
  struct StateT * v10808 = slot_96(v10801);
  return v10808;
}

struct StateT * slot_115(struct StateT * v11113) {
  int v11114 = v11113->timer;
  int v11122 = v11114 + 1;
  v11113->timer = v11122;
  int * v11116 = v11113->regs;
  int v11117 = v11116[28];
  int v11118 = v11116[18];
  int v11127 = v11117 + v11118;
  v11116[22] = v11127;
  struct StateT * v11120 = slot_116(v11113);
  return v11120;
}

struct StateT * slot_78(struct StateT * v10538) {
  int v10539 = v10538->timer;
  int v10546 = v10539 + 1;
  v10538->timer = v10546;
  int * v10541 = v10538->regs;
  int v10542 = v10541[20];
  int v10549 = v10542 << 13;
  v10541[20] = v10549;
  struct StateT * v10544 = slot_79(v10538);
  return v10544;
}

struct StateT * slot_32(struct StateT * v5436) {
  int v5437 = v5436->timer;
  int v5447 = v5437 + 1;
  v5436->timer = v5447;
  int * v5439 = v5436->regs;
  int v5440 = v5439[11];
  bool v5450 = (v5440 ^ -2147483648) < -2147483648;
  struct StateT * v5445;
  if (v5450) {
    struct StateT * v5441 = slot_195(v5436);
    v5445 = v5441;
  } else {
    struct StateT * v5443 = slot_33(v5436);
    v5445 = v5443;
  }
  return v5445;
}

struct StateT * slot_205(struct StateT * v8542) {
  int v8543 = v8542->timer;
  int v8653 = v8543 + 1;
  v8542->timer = v8653;
  int * v8545 = v8542->regs;
  int v8546 = v8545[2];
  int * v8547 = v8542->cache_tags;
  int v8657 = (((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1)) & 1) * 2;
  int v8548 = v8547[v8657];
  int v8658 = ((((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1)) & 1) * 2) + 1;
  int v8549 = v8547[v8658];
  int v8659 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1)) & 3) * 2);
  int v8550 = v8547[v8659];
  int v8660 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v8551 = v8547[v8660];
  int v8552 = v8542->timer;
  int v8661 = v8552 + ((100 ^ (((~(((v8550 ^ ((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1))) | (-(v8550 ^ ((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v8551 ^ ((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1))) | (-(v8551 ^ ((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v8548 ^ ((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1))) | (-(v8548 ^ ((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v8549 ^ ((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1))) | (-(v8549 ^ ((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v8550 ^ ((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1))) | (-(v8550 ^ ((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v8551 ^ ((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1))) | (-(v8551 ^ ((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1))))) >> 31))) & 104)))));
  v8542->timer = v8661;
  int * v8554 = v8542->cache_vals;
  bool v8662 = !(((~(((v8548 ^ ((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1))) | (-(v8548 ^ ((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v8549 ^ ((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1))) | (-(v8549 ^ ((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v8647;
  if (v8662) {
    int * v8555 = v8542->cache_age;
    int v8664 = ((((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1)) & 1) * 2) + ((~(((v8549 ^ ((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1))) | (-(v8549 ^ ((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1))))) >> 31)) & 1);
    int v8556 = v8555[v8664];
    int v8557 = v8555[v8657];
    int v8665 = v8557 + ((int)((unsigned int)(v8557 - v8556) >> 31));
    v8555[v8657] = v8665;
    int * v8559 = v8542->cache_age;
    int v8560 = v8559[v8658];
    int v8667 = v8560 + ((int)((unsigned int)(v8560 - v8556) >> 31));
    v8559[v8658] = v8667;
    int * v8562 = v8542->cache_age;
    v8562[v8664] = 0;
    v8647 = v8664;
  } else {
    int * v8565 = v8542->cache_age;
    int v8671 = (((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1)) & 1) * 2;
    int v8566 = v8565[v8671];
    int * v8567 = v8542->cache_tags;
    int v8568 = v8567[v8671];
    int v8569 = v8565[v8658];
    int v8570 = v8567[v8658];
    bool v8673 = !(((~(((v8550 ^ ((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1))) | (-(v8550 ^ ((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v8551 ^ ((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1))) | (-(v8551 ^ ((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1))))) >> 31))) == 0);
    int v8624;
    if (v8673) {
      int * v8571 = v8542->cache_age;
      int v8675 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v8551 ^ ((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1))) | (-(v8551 ^ ((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1))))) >> 31)) & 1);
      int v8572 = v8571[v8675];
      int v8573 = v8571[v8659];
      int v8676 = v8573 + ((int)((unsigned int)(v8573 - v8572) >> 31));
      v8571[v8659] = v8676;
      int * v8575 = v8542->cache_age;
      int v8576 = v8575[v8660];
      int v8678 = v8576 + ((int)((unsigned int)(v8576 - v8572) >> 31));
      v8575[v8660] = v8678;
      int * v8578 = v8542->cache_age;
      v8578[v8675] = 0;
      v8624 = v8675;
    } else {
      int * v8581 = v8542->cache_age;
      int v8682 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1)) & 3) * 2);
      int v8582 = v8581[v8682];
      int * v8583 = v8542->cache_tags;
      int v8584 = v8583[v8682];
      int v8585 = v8581[v8660];
      int v8586 = v8583[v8660];
      int * v8587 = v8542->cache_dirty;
      int v8685 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v8582 + ((~(((v8584 ^ -1) | (-(v8584 ^ -1))) >> 31)) & 2)) - (v8585 + ((~(((v8586 ^ -1) | (-(v8586 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v8588 = v8587[v8685];
      bool v8686 = !(v8588 == 0);
      if (v8686) {
        int * v8589 = v8542->cache_tags;
        int v8590 = v8589[v8685];
        int * v8591 = v8542->cache_vals;
        int v8689 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v8582 + ((~(((v8584 ^ -1) | (-(v8584 ^ -1))) >> 31)) & 2)) - (v8585 + ((~(((v8586 ^ -1) | (-(v8586 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v8592 = v8591[v8689];
        int v8690 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v8582 + ((~(((v8584 ^ -1) | (-(v8584 ^ -1))) >> 31)) & 2)) - (v8585 + ((~(((v8586 ^ -1) | (-(v8586 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v8593 = v8591[v8690];
        int * v8594 = v8542->mem;
        int v8692 = v8590 * 2;
        v8594[v8692] = v8592;
        int * v8596 = v8542->mem;
        int v8695 = (v8590 * 2) + 1;
        v8596[v8695] = v8593;
        ;
      } else {
        ;
      }
      int * v8601 = v8542->mem;
      int v8700 = ((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1)) * 2;
      int v8602 = v8601[v8700];
      int v8701 = (((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1)) * 2) + 1;
      int v8603 = v8601[v8701];
      int * v8604 = v8542->cache_vals;
      int v8703 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v8582 + ((~(((v8584 ^ -1) | (-(v8584 ^ -1))) >> 31)) & 2)) - (v8585 + ((~(((v8586 ^ -1) | (-(v8586 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v8604[v8703] = v8602;
      int * v8606 = v8542->cache_vals;
      int v8706 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v8582 + ((~(((v8584 ^ -1) | (-(v8584 ^ -1))) >> 31)) & 2)) - (v8585 + ((~(((v8586 ^ -1) | (-(v8586 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v8606[v8706] = v8603;
      int * v8608 = v8542->cache_tags;
      int v8709 = (int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1);
      v8608[v8685] = v8709;
      int * v8610 = v8542->cache_dirty;
      v8610[v8685] = 0;
      int * v8612 = v8542->cache_age;
      v8612[v8685] = 1;
      int * v8614 = v8542->cache_age;
      int v8615 = v8614[v8685];
      int v8616 = v8614[v8659];
      int v8715 = v8616 + ((int)((unsigned int)(v8616 - v8615) >> 31));
      v8614[v8659] = v8715;
      int * v8618 = v8542->cache_age;
      int v8619 = v8618[v8660];
      int v8717 = v8619 + ((int)((unsigned int)(v8619 - v8615) >> 31));
      v8618[v8660] = v8717;
      int * v8621 = v8542->cache_age;
      v8621[v8685] = 0;
      v8624 = v8685;
    }
    int * v8625 = v8542->cache_vals;
    int v8720 = v8624 * 2;
    int v8626 = v8625[v8720];
    int v8721 = (v8624 * 2) + 1;
    int v8627 = v8625[v8721];
    int v8722 = (((((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v8566 + ((~(((v8568 ^ -1) | (-(v8568 ^ -1))) >> 31)) & 2)) - (v8569 + ((~(((v8570 ^ -1) | (-(v8570 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v8625[v8722] = v8626;
    int * v8629 = v8542->cache_vals;
    int v8725 = ((((((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v8566 + ((~(((v8568 ^ -1) | (-(v8568 ^ -1))) >> 31)) & 2)) - (v8569 + ((~(((v8570 ^ -1) | (-(v8570 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v8629[v8725] = v8627;
    int * v8631 = v8542->cache_tags;
    int v8728 = ((((int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v8566 + ((~(((v8568 ^ -1) | (-(v8568 ^ -1))) >> 31)) & 2)) - (v8569 + ((~(((v8570 ^ -1) | (-(v8570 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v8729 = (int)((unsigned int)((int)((unsigned int)(v8546 + 36) >> 2)) >> 1);
    v8631[v8728] = v8729;
    int * v8633 = v8542->cache_dirty;
    v8633[v8728] = 0;
    int * v8635 = v8542->cache_age;
    v8635[v8728] = 1;
    int * v8637 = v8542->cache_age;
    int v8638 = v8637[v8728];
    int v8639 = v8637[v8657];
    int v8735 = v8639 + ((int)((unsigned int)(v8639 - v8638) >> 31));
    v8637[v8657] = v8735;
    int * v8641 = v8542->cache_age;
    int v8642 = v8641[v8658];
    int v8737 = v8642 + ((int)((unsigned int)(v8642 - v8638) >> 31));
    v8641[v8658] = v8737;
    int * v8644 = v8542->cache_age;
    v8644[v8728] = 0;
    v8647 = v8728;
  }
  int v8740 = (v8647 * 2) + (((int)((unsigned int)(v8546 + 36) >> 2)) & 1);
  int v8648 = v8554[v8740];
  int * v8649 = v8542->regs;
  v8649[18] = v8648;
  struct StateT * v8651 = slot_206(v8542);
  return v8651;
}

struct StateT * slot_193(struct StateT * v12327) {
  int v12328 = v12327->timer;
  int v12335 = v12328 + 1;
  v12327->timer = v12335;
  int * v12330 = v12327->regs;
  int v12331 = v12330[13];
  int v12338 = v12331 + 1;
  v12330[13] = v12338;
  struct StateT * v12333 = slot_194(v12327);
  return v12333;
}

struct StateT * slot_176(struct StateT * v12066) {
  int v12067 = v12066->timer;
  int v12075 = v12067 + 1;
  v12066->timer = v12075;
  int * v12069 = v12066->regs;
  int v12070 = v12069[19];
  int v12071 = v12069[7];
  int v12080 = v12070 + v12071;
  v12069[23] = v12080;
  struct StateT * v12073 = slot_177(v12066);
  return v12073;
}

struct StateT * slot_189(struct StateT * v12263) {
  int v12264 = v12263->timer;
  int v12272 = v12264 + 1;
  v12263->timer = v12272;
  int * v12266 = v12263->regs;
  int v12267 = v12266[30];
  int v12268 = v12266[20];
  int v12276 = v12267 ^ v12268;
  v12266[30] = v12276;
  struct StateT * v12270 = slot_190(v12263);
  return v12270;
}

struct StateT * slot_33(struct StateT * v5771) {
  int v5772 = v5771->timer;
  int v5780 = v5772 + 1;
  v5771->timer = v5780;
  int * v5774 = v5771->regs;
  int v5775 = v5774[30];
  int v5776 = v5774[16];
  int v5785 = v5775 + v5776;
  v5774[20] = v5785;
  struct StateT * v5778 = slot_34(v5771);
  return v5778;
}

struct StateT * slot_35(struct StateT * v6435) {
  int v6436 = v6435->timer;
  int v6444 = v6436 + 1;
  v6435->timer = v6444;
  int * v6438 = v6435->regs;
  int v6439 = v6438[28];
  int v6440 = v6438[12];
  int v6449 = v6439 + v6440;
  v6438[22] = v6449;
  struct StateT * v6442 = slot_36(v6435);
  return v6442;
}

struct StateT * slot_210(struct StateT * v9636) {
  int v9637 = v9636->timer;
  int v9747 = v9637 + 1;
  v9636->timer = v9747;
  int * v9639 = v9636->regs;
  int v9640 = v9639[2];
  int * v9641 = v9636->cache_tags;
  int v9751 = (((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1)) & 1) * 2;
  int v9642 = v9641[v9751];
  int v9752 = ((((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v9643 = v9641[v9752];
  int v9753 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1)) & 3) * 2);
  int v9644 = v9641[v9753];
  int v9754 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v9645 = v9641[v9754];
  int v9646 = v9636->timer;
  int v9755 = v9646 + ((100 ^ (((~(((v9644 ^ ((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1))) | (-(v9644 ^ ((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v9645 ^ ((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1))) | (-(v9645 ^ ((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v9642 ^ ((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1))) | (-(v9642 ^ ((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v9643 ^ ((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1))) | (-(v9643 ^ ((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v9644 ^ ((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1))) | (-(v9644 ^ ((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v9645 ^ ((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1))) | (-(v9645 ^ ((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v9636->timer = v9755;
  int * v9648 = v9636->cache_vals;
  bool v9756 = !(((~(((v9642 ^ ((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1))) | (-(v9642 ^ ((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v9643 ^ ((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1))) | (-(v9643 ^ ((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v9741;
  if (v9756) {
    int * v9649 = v9636->cache_age;
    int v9758 = ((((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v9643 ^ ((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1))) | (-(v9643 ^ ((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v9650 = v9649[v9758];
    int v9651 = v9649[v9751];
    int v9759 = v9651 + ((int)((unsigned int)(v9651 - v9650) >> 31));
    v9649[v9751] = v9759;
    int * v9653 = v9636->cache_age;
    int v9654 = v9653[v9752];
    int v9761 = v9654 + ((int)((unsigned int)(v9654 - v9650) >> 31));
    v9653[v9752] = v9761;
    int * v9656 = v9636->cache_age;
    v9656[v9758] = 0;
    v9741 = v9758;
  } else {
    int * v9659 = v9636->cache_age;
    int v9765 = (((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1)) & 1) * 2;
    int v9660 = v9659[v9765];
    int * v9661 = v9636->cache_tags;
    int v9662 = v9661[v9765];
    int v9663 = v9659[v9752];
    int v9664 = v9661[v9752];
    bool v9767 = !(((~(((v9644 ^ ((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1))) | (-(v9644 ^ ((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v9645 ^ ((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1))) | (-(v9645 ^ ((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v9718;
    if (v9767) {
      int * v9665 = v9636->cache_age;
      int v9769 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v9645 ^ ((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1))) | (-(v9645 ^ ((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v9666 = v9665[v9769];
      int v9667 = v9665[v9753];
      int v9770 = v9667 + ((int)((unsigned int)(v9667 - v9666) >> 31));
      v9665[v9753] = v9770;
      int * v9669 = v9636->cache_age;
      int v9670 = v9669[v9754];
      int v9772 = v9670 + ((int)((unsigned int)(v9670 - v9666) >> 31));
      v9669[v9754] = v9772;
      int * v9672 = v9636->cache_age;
      v9672[v9769] = 0;
      v9718 = v9769;
    } else {
      int * v9675 = v9636->cache_age;
      int v9776 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1)) & 3) * 2);
      int v9676 = v9675[v9776];
      int * v9677 = v9636->cache_tags;
      int v9678 = v9677[v9776];
      int v9679 = v9675[v9754];
      int v9680 = v9677[v9754];
      int * v9681 = v9636->cache_dirty;
      int v9779 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v9676 + ((~(((v9678 ^ -1) | (-(v9678 ^ -1))) >> 31)) & 2)) - (v9679 + ((~(((v9680 ^ -1) | (-(v9680 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v9682 = v9681[v9779];
      bool v9780 = !(v9682 == 0);
      if (v9780) {
        int * v9683 = v9636->cache_tags;
        int v9684 = v9683[v9779];
        int * v9685 = v9636->cache_vals;
        int v9783 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v9676 + ((~(((v9678 ^ -1) | (-(v9678 ^ -1))) >> 31)) & 2)) - (v9679 + ((~(((v9680 ^ -1) | (-(v9680 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v9686 = v9685[v9783];
        int v9784 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v9676 + ((~(((v9678 ^ -1) | (-(v9678 ^ -1))) >> 31)) & 2)) - (v9679 + ((~(((v9680 ^ -1) | (-(v9680 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v9687 = v9685[v9784];
        int * v9688 = v9636->mem;
        int v9786 = v9684 * 2;
        v9688[v9786] = v9686;
        int * v9690 = v9636->mem;
        int v9789 = (v9684 * 2) + 1;
        v9690[v9789] = v9687;
        ;
      } else {
        ;
      }
      int * v9695 = v9636->mem;
      int v9794 = ((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1)) * 2;
      int v9696 = v9695[v9794];
      int v9795 = (((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1)) * 2) + 1;
      int v9697 = v9695[v9795];
      int * v9698 = v9636->cache_vals;
      int v9797 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v9676 + ((~(((v9678 ^ -1) | (-(v9678 ^ -1))) >> 31)) & 2)) - (v9679 + ((~(((v9680 ^ -1) | (-(v9680 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v9698[v9797] = v9696;
      int * v9700 = v9636->cache_vals;
      int v9800 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v9676 + ((~(((v9678 ^ -1) | (-(v9678 ^ -1))) >> 31)) & 2)) - (v9679 + ((~(((v9680 ^ -1) | (-(v9680 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v9700[v9800] = v9697;
      int * v9702 = v9636->cache_tags;
      int v9803 = (int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1);
      v9702[v9779] = v9803;
      int * v9704 = v9636->cache_dirty;
      v9704[v9779] = 0;
      int * v9706 = v9636->cache_age;
      v9706[v9779] = 1;
      int * v9708 = v9636->cache_age;
      int v9709 = v9708[v9779];
      int v9710 = v9708[v9753];
      int v9809 = v9710 + ((int)((unsigned int)(v9710 - v9709) >> 31));
      v9708[v9753] = v9809;
      int * v9712 = v9636->cache_age;
      int v9713 = v9712[v9754];
      int v9811 = v9713 + ((int)((unsigned int)(v9713 - v9709) >> 31));
      v9712[v9754] = v9811;
      int * v9715 = v9636->cache_age;
      v9715[v9779] = 0;
      v9718 = v9779;
    }
    int * v9719 = v9636->cache_vals;
    int v9814 = v9718 * 2;
    int v9720 = v9719[v9814];
    int v9815 = (v9718 * 2) + 1;
    int v9721 = v9719[v9815];
    int v9816 = (((((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v9660 + ((~(((v9662 ^ -1) | (-(v9662 ^ -1))) >> 31)) & 2)) - (v9663 + ((~(((v9664 ^ -1) | (-(v9664 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9719[v9816] = v9720;
    int * v9723 = v9636->cache_vals;
    int v9819 = ((((((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v9660 + ((~(((v9662 ^ -1) | (-(v9662 ^ -1))) >> 31)) & 2)) - (v9663 + ((~(((v9664 ^ -1) | (-(v9664 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9723[v9819] = v9721;
    int * v9725 = v9636->cache_tags;
    int v9822 = ((((int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v9660 + ((~(((v9662 ^ -1) | (-(v9662 ^ -1))) >> 31)) & 2)) - (v9663 + ((~(((v9664 ^ -1) | (-(v9664 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9823 = (int)((unsigned int)((int)((unsigned int)(v9640 + 16) >> 2)) >> 1);
    v9725[v9822] = v9823;
    int * v9727 = v9636->cache_dirty;
    v9727[v9822] = 0;
    int * v9729 = v9636->cache_age;
    v9729[v9822] = 1;
    int * v9731 = v9636->cache_age;
    int v9732 = v9731[v9822];
    int v9733 = v9731[v9751];
    int v9829 = v9733 + ((int)((unsigned int)(v9733 - v9732) >> 31));
    v9731[v9751] = v9829;
    int * v9735 = v9636->cache_age;
    int v9736 = v9735[v9752];
    int v9831 = v9736 + ((int)((unsigned int)(v9736 - v9732) >> 31));
    v9735[v9752] = v9831;
    int * v9738 = v9636->cache_age;
    v9738[v9822] = 0;
    v9741 = v9822;
  }
  int v9834 = (v9741 * 2) + (((int)((unsigned int)(v9640 + 16) >> 2)) & 1);
  int v9742 = v9648[v9834];
  int * v9743 = v9636->regs;
  v9743[23] = v9742;
  struct StateT * v9745 = slot_211(v9636);
  return v9745;
}

struct StateT * slot_166(struct StateT * v11906) {
  int v11907 = v11906->timer;
  int v11914 = v11907 + 1;
  v11906->timer = v11914;
  int * v11909 = v11906->regs;
  int v11910 = v11909[23];
  int v11918 = (int)((unsigned int)v11910 >> 19);
  v11909[24] = v11918;
  struct StateT * v11912 = slot_167(v11906);
  return v11912;
}

struct StateT * slot_51(struct StateT * v10111) {
  int v10112 = v10111->timer;
  int v10120 = v10112 + 1;
  v10111->timer = v10120;
  int * v10114 = v10111->regs;
  int v10115 = v10114[19];
  int v10116 = v10114[22];
  int v10124 = v10115 ^ v10116;
  v10114[19] = v10124;
  struct StateT * v10118 = slot_52(v10111);
  return v10118;
}

struct StateT * slot_52(struct StateT * v10127) {
  int v10128 = v10127->timer;
  int v10136 = v10128 + 1;
  v10127->timer = v10136;
  int * v10130 = v10127->regs;
  int v10131 = v10130[8];
  int v10132 = v10130[23];
  int v10140 = v10131 ^ v10132;
  v10130[8] = v10140;
  struct StateT * v10134 = slot_53(v10127);
  return v10134;
}

struct StateT * slot_83(struct StateT * v10613) {
  int v10614 = v10613->timer;
  int v10621 = v10614 + 1;
  v10613->timer = v10621;
  int * v10616 = v10613->regs;
  int v10617 = v10616[22];
  int v10625 = (int)((unsigned int)v10617 >> 19);
  v10616[24] = v10625;
  struct StateT * v10619 = slot_84(v10613);
  return v10619;
}

struct StateT * slot_25(struct StateT * v5338) {
  int v5339 = v5338->timer;
  int v5345 = v5339 + 1;
  v5338->timer = v5345;
  int * v5341 = v5338->regs;
  v5341[31] = 2036477952;
  struct StateT * v5343 = slot_26(v5338);
  return v5343;
}

struct StateT * slot_209(struct StateT * v9418) {
  int v9419 = v9418->timer;
  int v9529 = v9419 + 1;
  v9418->timer = v9529;
  int * v9421 = v9418->regs;
  int v9422 = v9421[2];
  int * v9423 = v9418->cache_tags;
  int v9533 = (((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1)) & 1) * 2;
  int v9424 = v9423[v9533];
  int v9534 = ((((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1)) & 1) * 2) + 1;
  int v9425 = v9423[v9534];
  int v9535 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1)) & 3) * 2);
  int v9426 = v9423[v9535];
  int v9536 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v9427 = v9423[v9536];
  int v9428 = v9418->timer;
  int v9537 = v9428 + ((100 ^ (((~(((v9426 ^ ((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1))) | (-(v9426 ^ ((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v9427 ^ ((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1))) | (-(v9427 ^ ((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v9424 ^ ((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1))) | (-(v9424 ^ ((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v9425 ^ ((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1))) | (-(v9425 ^ ((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v9426 ^ ((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1))) | (-(v9426 ^ ((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v9427 ^ ((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1))) | (-(v9427 ^ ((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1))))) >> 31))) & 104)))));
  v9418->timer = v9537;
  int * v9430 = v9418->cache_vals;
  bool v9538 = !(((~(((v9424 ^ ((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1))) | (-(v9424 ^ ((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v9425 ^ ((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1))) | (-(v9425 ^ ((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v9523;
  if (v9538) {
    int * v9431 = v9418->cache_age;
    int v9540 = ((((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1)) & 1) * 2) + ((~(((v9425 ^ ((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1))) | (-(v9425 ^ ((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v9432 = v9431[v9540];
    int v9433 = v9431[v9533];
    int v9541 = v9433 + ((int)((unsigned int)(v9433 - v9432) >> 31));
    v9431[v9533] = v9541;
    int * v9435 = v9418->cache_age;
    int v9436 = v9435[v9534];
    int v9543 = v9436 + ((int)((unsigned int)(v9436 - v9432) >> 31));
    v9435[v9534] = v9543;
    int * v9438 = v9418->cache_age;
    v9438[v9540] = 0;
    v9523 = v9540;
  } else {
    int * v9441 = v9418->cache_age;
    int v9547 = (((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1)) & 1) * 2;
    int v9442 = v9441[v9547];
    int * v9443 = v9418->cache_tags;
    int v9444 = v9443[v9547];
    int v9445 = v9441[v9534];
    int v9446 = v9443[v9534];
    bool v9549 = !(((~(((v9426 ^ ((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1))) | (-(v9426 ^ ((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v9427 ^ ((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1))) | (-(v9427 ^ ((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1))))) >> 31))) == 0);
    int v9500;
    if (v9549) {
      int * v9447 = v9418->cache_age;
      int v9551 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v9427 ^ ((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1))) | (-(v9427 ^ ((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1))))) >> 31)) & 1);
      int v9448 = v9447[v9551];
      int v9449 = v9447[v9535];
      int v9552 = v9449 + ((int)((unsigned int)(v9449 - v9448) >> 31));
      v9447[v9535] = v9552;
      int * v9451 = v9418->cache_age;
      int v9452 = v9451[v9536];
      int v9554 = v9452 + ((int)((unsigned int)(v9452 - v9448) >> 31));
      v9451[v9536] = v9554;
      int * v9454 = v9418->cache_age;
      v9454[v9551] = 0;
      v9500 = v9551;
    } else {
      int * v9457 = v9418->cache_age;
      int v9558 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1)) & 3) * 2);
      int v9458 = v9457[v9558];
      int * v9459 = v9418->cache_tags;
      int v9460 = v9459[v9558];
      int v9461 = v9457[v9536];
      int v9462 = v9459[v9536];
      int * v9463 = v9418->cache_dirty;
      int v9561 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v9458 + ((~(((v9460 ^ -1) | (-(v9460 ^ -1))) >> 31)) & 2)) - (v9461 + ((~(((v9462 ^ -1) | (-(v9462 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v9464 = v9463[v9561];
      bool v9562 = !(v9464 == 0);
      if (v9562) {
        int * v9465 = v9418->cache_tags;
        int v9466 = v9465[v9561];
        int * v9467 = v9418->cache_vals;
        int v9565 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v9458 + ((~(((v9460 ^ -1) | (-(v9460 ^ -1))) >> 31)) & 2)) - (v9461 + ((~(((v9462 ^ -1) | (-(v9462 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v9468 = v9467[v9565];
        int v9566 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v9458 + ((~(((v9460 ^ -1) | (-(v9460 ^ -1))) >> 31)) & 2)) - (v9461 + ((~(((v9462 ^ -1) | (-(v9462 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v9469 = v9467[v9566];
        int * v9470 = v9418->mem;
        int v9568 = v9466 * 2;
        v9470[v9568] = v9468;
        int * v9472 = v9418->mem;
        int v9571 = (v9466 * 2) + 1;
        v9472[v9571] = v9469;
        ;
      } else {
        ;
      }
      int * v9477 = v9418->mem;
      int v9576 = ((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1)) * 2;
      int v9478 = v9477[v9576];
      int v9577 = (((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1)) * 2) + 1;
      int v9479 = v9477[v9577];
      int * v9480 = v9418->cache_vals;
      int v9579 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v9458 + ((~(((v9460 ^ -1) | (-(v9460 ^ -1))) >> 31)) & 2)) - (v9461 + ((~(((v9462 ^ -1) | (-(v9462 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v9480[v9579] = v9478;
      int * v9482 = v9418->cache_vals;
      int v9582 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v9458 + ((~(((v9460 ^ -1) | (-(v9460 ^ -1))) >> 31)) & 2)) - (v9461 + ((~(((v9462 ^ -1) | (-(v9462 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v9482[v9582] = v9479;
      int * v9484 = v9418->cache_tags;
      int v9585 = (int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1);
      v9484[v9561] = v9585;
      int * v9486 = v9418->cache_dirty;
      v9486[v9561] = 0;
      int * v9488 = v9418->cache_age;
      v9488[v9561] = 1;
      int * v9490 = v9418->cache_age;
      int v9491 = v9490[v9561];
      int v9492 = v9490[v9535];
      int v9591 = v9492 + ((int)((unsigned int)(v9492 - v9491) >> 31));
      v9490[v9535] = v9591;
      int * v9494 = v9418->cache_age;
      int v9495 = v9494[v9536];
      int v9593 = v9495 + ((int)((unsigned int)(v9495 - v9491) >> 31));
      v9494[v9536] = v9593;
      int * v9497 = v9418->cache_age;
      v9497[v9561] = 0;
      v9500 = v9561;
    }
    int * v9501 = v9418->cache_vals;
    int v9596 = v9500 * 2;
    int v9502 = v9501[v9596];
    int v9597 = (v9500 * 2) + 1;
    int v9503 = v9501[v9597];
    int v9598 = (((((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v9442 + ((~(((v9444 ^ -1) | (-(v9444 ^ -1))) >> 31)) & 2)) - (v9445 + ((~(((v9446 ^ -1) | (-(v9446 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9501[v9598] = v9502;
    int * v9505 = v9418->cache_vals;
    int v9601 = ((((((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v9442 + ((~(((v9444 ^ -1) | (-(v9444 ^ -1))) >> 31)) & 2)) - (v9445 + ((~(((v9446 ^ -1) | (-(v9446 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9505[v9601] = v9503;
    int * v9507 = v9418->cache_tags;
    int v9604 = ((((int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v9442 + ((~(((v9444 ^ -1) | (-(v9444 ^ -1))) >> 31)) & 2)) - (v9445 + ((~(((v9446 ^ -1) | (-(v9446 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9605 = (int)((unsigned int)((int)((unsigned int)(v9422 + 20) >> 2)) >> 1);
    v9507[v9604] = v9605;
    int * v9509 = v9418->cache_dirty;
    v9509[v9604] = 0;
    int * v9511 = v9418->cache_age;
    v9511[v9604] = 1;
    int * v9513 = v9418->cache_age;
    int v9514 = v9513[v9604];
    int v9515 = v9513[v9533];
    int v9611 = v9515 + ((int)((unsigned int)(v9515 - v9514) >> 31));
    v9513[v9533] = v9611;
    int * v9517 = v9418->cache_age;
    int v9518 = v9517[v9534];
    int v9613 = v9518 + ((int)((unsigned int)(v9518 - v9514) >> 31));
    v9517[v9534] = v9613;
    int * v9520 = v9418->cache_age;
    v9520[v9604] = 0;
    v9523 = v9604;
  }
  int v9616 = (v9523 * 2) + (((int)((unsigned int)(v9422 + 20) >> 2)) & 1);
  int v9524 = v9430[v9616];
  int * v9525 = v9418->regs;
  v9525[22] = v9524;
  struct StateT * v9527 = slot_210(v9418);
  return v9527;
}

struct StateT * slot_3(struct StateT * v646) {
  int v647 = v646->timer;
  int v817 = v647 + 1;
  v646->timer = v817;
  int * v649 = v646->regs;
  int v650 = v649[2];
  int v651 = v649[18];
  int * v652 = v646->cache_tags;
  int v822 = (((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 1) * 2;
  int v653 = v652[v822];
  int v823 = ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 1) * 2) + 1;
  int v654 = v652[v823];
  int v824 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 3) * 2);
  int v655 = v652[v824];
  int v825 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v656 = v652[v825];
  int v657 = v646->timer;
  int v826 = v657 + ((100 ^ (((~(((v655 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))) | (-(v655 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v656 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))) | (-(v656 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v653 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))) | (-(v653 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v654 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))) | (-(v654 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v655 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))) | (-(v655 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v656 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))) | (-(v656 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))))) >> 31))) & 104)))));
  v646->timer = v826;
  bool v827 = !(((~(((v653 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))) | (-(v653 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v654 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))) | (-(v654 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v751;
  if (v827) {
    int * v659 = v646->cache_age;
    int v829 = ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 1) * 2) + ((~(((v654 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))) | (-(v654 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))))) >> 31)) & 1);
    int v660 = v659[v829];
    int v661 = v659[v822];
    int v830 = v661 + ((int)((unsigned int)(v661 - v660) >> 31));
    v659[v822] = v830;
    int * v663 = v646->cache_age;
    int v664 = v663[v823];
    int v832 = v664 + ((int)((unsigned int)(v664 - v660) >> 31));
    v663[v823] = v832;
    int * v666 = v646->cache_age;
    v666[v829] = 0;
    v751 = v829;
  } else {
    int * v669 = v646->cache_age;
    int v836 = (((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 1) * 2;
    int v670 = v669[v836];
    int * v671 = v646->cache_tags;
    int v672 = v671[v836];
    int v673 = v669[v823];
    int v674 = v671[v823];
    bool v838 = !(((~(((v655 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))) | (-(v655 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v656 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))) | (-(v656 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))))) >> 31))) == 0);
    int v728;
    if (v838) {
      int * v675 = v646->cache_age;
      int v840 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v656 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))) | (-(v656 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))))) >> 31)) & 1);
      int v676 = v675[v840];
      int v677 = v675[v824];
      int v841 = v677 + ((int)((unsigned int)(v677 - v676) >> 31));
      v675[v824] = v841;
      int * v679 = v646->cache_age;
      int v680 = v679[v825];
      int v843 = v680 + ((int)((unsigned int)(v680 - v676) >> 31));
      v679[v825] = v843;
      int * v682 = v646->cache_age;
      v682[v840] = 0;
      v728 = v840;
    } else {
      int * v685 = v646->cache_age;
      int v847 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 3) * 2);
      int v686 = v685[v847];
      int * v687 = v646->cache_tags;
      int v688 = v687[v847];
      int v689 = v685[v825];
      int v690 = v687[v825];
      int * v691 = v646->cache_dirty;
      int v850 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v686 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2)) - (v689 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v692 = v691[v850];
      bool v851 = !(v692 == 0);
      if (v851) {
        int * v693 = v646->cache_tags;
        int v694 = v693[v850];
        int * v695 = v646->cache_vals;
        int v854 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v686 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2)) - (v689 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v696 = v695[v854];
        int v855 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v686 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2)) - (v689 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v697 = v695[v855];
        int * v698 = v646->mem;
        int v857 = v694 * 2;
        v698[v857] = v696;
        int * v700 = v646->mem;
        int v860 = (v694 * 2) + 1;
        v700[v860] = v697;
        ;
      } else {
        ;
      }
      int * v705 = v646->mem;
      int v865 = ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) * 2;
      int v706 = v705[v865];
      int v866 = (((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) * 2) + 1;
      int v707 = v705[v866];
      int * v708 = v646->cache_vals;
      int v868 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v686 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2)) - (v689 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v708[v868] = v706;
      int * v710 = v646->cache_vals;
      int v871 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v686 + ((~(((v688 ^ -1) | (-(v688 ^ -1))) >> 31)) & 2)) - (v689 + ((~(((v690 ^ -1) | (-(v690 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v710[v871] = v707;
      int * v712 = v646->cache_tags;
      int v874 = (int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1);
      v712[v850] = v874;
      int * v714 = v646->cache_dirty;
      v714[v850] = 0;
      int * v716 = v646->cache_age;
      v716[v850] = 1;
      int * v718 = v646->cache_age;
      int v719 = v718[v850];
      int v720 = v718[v824];
      int v880 = v720 + ((int)((unsigned int)(v720 - v719) >> 31));
      v718[v824] = v880;
      int * v722 = v646->cache_age;
      int v723 = v722[v825];
      int v882 = v723 + ((int)((unsigned int)(v723 - v719) >> 31));
      v722[v825] = v882;
      int * v725 = v646->cache_age;
      v725[v850] = 0;
      v728 = v850;
    }
    int * v729 = v646->cache_vals;
    int v885 = v728 * 2;
    int v730 = v729[v885];
    int v886 = (v728 * 2) + 1;
    int v731 = v729[v886];
    int v887 = (((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v670 + ((~(((v672 ^ -1) | (-(v672 ^ -1))) >> 31)) & 2)) - (v673 + ((~(((v674 ^ -1) | (-(v674 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v729[v887] = v730;
    int * v733 = v646->cache_vals;
    int v890 = ((((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v670 + ((~(((v672 ^ -1) | (-(v672 ^ -1))) >> 31)) & 2)) - (v673 + ((~(((v674 ^ -1) | (-(v674 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v733[v890] = v731;
    int * v735 = v646->cache_tags;
    int v893 = ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 1) * 2) + ((((v670 + ((~(((v672 ^ -1) | (-(v672 ^ -1))) >> 31)) & 2)) - (v673 + ((~(((v674 ^ -1) | (-(v674 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v894 = (int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1);
    v735[v893] = v894;
    int * v737 = v646->cache_dirty;
    v737[v893] = 0;
    int * v739 = v646->cache_age;
    v739[v893] = 1;
    int * v741 = v646->cache_age;
    int v742 = v741[v893];
    int v743 = v741[v822];
    int v900 = v743 + ((int)((unsigned int)(v743 - v742) >> 31));
    v741[v822] = v900;
    int * v745 = v646->cache_age;
    int v746 = v745[v823];
    int v902 = v746 + ((int)((unsigned int)(v746 - v742) >> 31));
    v745[v823] = v902;
    int * v748 = v646->cache_age;
    v748[v893] = 0;
    v751 = v893;
  }
  int * v752 = v646->cache_vals;
  int v905 = (v751 * 2) + (((int)((unsigned int)(v650 + 36) >> 2)) & 1);
  v752[v905] = v651;
  int * v754 = v646->cache_tags;
  int v755 = v754[v824];
  int v756 = v754[v825];
  bool v908 = !(((~(((v755 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))) | (-(v755 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))))) >> 31)) | (~(((v756 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))) | (-(v756 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))))) >> 31))) == 0);
  int v810;
  if (v908) {
    int * v757 = v646->cache_age;
    int v910 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 3) * 2)) + ((~(((v756 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))) | (-(v756 ^ ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1))))) >> 31)) & 1);
    int v758 = v757[v910];
    int v759 = v757[v824];
    int v911 = v759 + ((int)((unsigned int)(v759 - v758) >> 31));
    v757[v824] = v911;
    int * v761 = v646->cache_age;
    int v762 = v761[v825];
    int v913 = v762 + ((int)((unsigned int)(v762 - v758) >> 31));
    v761[v825] = v913;
    int * v764 = v646->cache_age;
    v764[v910] = 0;
    v810 = v910;
  } else {
    int * v767 = v646->cache_age;
    int v917 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 3) * 2);
    int v768 = v767[v917];
    int * v769 = v646->cache_tags;
    int v770 = v769[v917];
    int v771 = v767[v825];
    int v772 = v769[v825];
    int * v773 = v646->cache_dirty;
    int v920 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v768 + ((~(((v770 ^ -1) | (-(v770 ^ -1))) >> 31)) & 2)) - (v771 + ((~(((v772 ^ -1) | (-(v772 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v774 = v773[v920];
    bool v921 = !(v774 == 0);
    if (v921) {
      int * v775 = v646->cache_tags;
      int v776 = v775[v920];
      int * v777 = v646->cache_vals;
      int v924 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v768 + ((~(((v770 ^ -1) | (-(v770 ^ -1))) >> 31)) & 2)) - (v771 + ((~(((v772 ^ -1) | (-(v772 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v778 = v777[v924];
      int v925 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v768 + ((~(((v770 ^ -1) | (-(v770 ^ -1))) >> 31)) & 2)) - (v771 + ((~(((v772 ^ -1) | (-(v772 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v779 = v777[v925];
      int * v780 = v646->mem;
      int v927 = v776 * 2;
      v780[v927] = v778;
      int * v782 = v646->mem;
      int v930 = (v776 * 2) + 1;
      v782[v930] = v779;
      ;
    } else {
      ;
    }
    int * v787 = v646->mem;
    int v935 = ((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) * 2;
    int v788 = v787[v935];
    int v936 = (((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) * 2) + 1;
    int v789 = v787[v936];
    int * v790 = v646->cache_vals;
    int v938 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v768 + ((~(((v770 ^ -1) | (-(v770 ^ -1))) >> 31)) & 2)) - (v771 + ((~(((v772 ^ -1) | (-(v772 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v790[v938] = v788;
    int * v792 = v646->cache_vals;
    int v941 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1)) & 3) * 2)) + ((((v768 + ((~(((v770 ^ -1) | (-(v770 ^ -1))) >> 31)) & 2)) - (v771 + ((~(((v772 ^ -1) | (-(v772 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v792[v941] = v789;
    int * v794 = v646->cache_tags;
    int v944 = (int)((unsigned int)((int)((unsigned int)(v650 + 36) >> 2)) >> 1);
    v794[v920] = v944;
    int * v796 = v646->cache_dirty;
    v796[v920] = 0;
    int * v798 = v646->cache_age;
    v798[v920] = 1;
    int * v800 = v646->cache_age;
    int v801 = v800[v920];
    int v802 = v800[v824];
    int v950 = v802 + ((int)((unsigned int)(v802 - v801) >> 31));
    v800[v824] = v950;
    int * v804 = v646->cache_age;
    int v805 = v804[v825];
    int v952 = v805 + ((int)((unsigned int)(v805 - v801) >> 31));
    v804[v825] = v952;
    int * v807 = v646->cache_age;
    v807[v920] = 0;
    v810 = v920;
  }
  int * v811 = v646->cache_vals;
  int v955 = (v810 * 2) + (((int)((unsigned int)(v650 + 36) >> 2)) & 1);
  v811[v955] = v651;
  int * v813 = v646->cache_dirty;
  v813[v810] = 1;
  struct StateT * v815 = slot_4(v646);
  return v815;
}

struct StateT * slot_123(struct StateT * v11237) {
  int v11238 = v11237->timer;
  int v11245 = v11238 + 1;
  v11237->timer = v11245;
  int * v11240 = v11237->regs;
  int v11241 = v11240[22];
  int v11249 = (int)((unsigned int)v11241 >> 25);
  v11240[24] = v11249;
  struct StateT * v11243 = slot_124(v11237);
  return v11243;
}

struct StateT * slot_73(struct StateT * v10455) {
  int v10456 = v10455->timer;
  int v10464 = v10456 + 1;
  v10455->timer = v10464;
  int * v10458 = v10455->regs;
  int v10459 = v10458[6];
  int v10460 = v10458[9];
  int v10469 = v10459 + v10460;
  v10458[20] = v10469;
  struct StateT * v10462 = slot_74(v10455);
  return v10462;
}

struct StateT * slot_198(struct StateT * v6452) {
  int v6453 = v6452->timer;
  int v6623 = v6453 + 1;
  v6452->timer = v6623;
  int * v6455 = v6452->regs;
  int v6456 = v6455[10];
  int v6457 = v6455[31];
  int * v6458 = v6452->cache_tags;
  int v6628 = (((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1)) & 1) * 2;
  int v6459 = v6458[v6628];
  int v6629 = ((((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v6460 = v6458[v6629];
  int v6630 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1)) & 3) * 2);
  int v6461 = v6458[v6630];
  int v6631 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v6462 = v6458[v6631];
  int v6463 = v6452->timer;
  int v6632 = v6463 + ((100 ^ (((~(((v6461 ^ ((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1))) | (-(v6461 ^ ((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v6462 ^ ((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1))) | (-(v6462 ^ ((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v6459 ^ ((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1))) | (-(v6459 ^ ((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v6460 ^ ((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1))) | (-(v6460 ^ ((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v6461 ^ ((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1))) | (-(v6461 ^ ((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v6462 ^ ((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1))) | (-(v6462 ^ ((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v6452->timer = v6632;
  bool v6633 = !(((~(((v6459 ^ ((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1))) | (-(v6459 ^ ((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v6460 ^ ((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1))) | (-(v6460 ^ ((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v6557;
  if (v6633) {
    int * v6465 = v6452->cache_age;
    int v6635 = ((((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v6460 ^ ((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1))) | (-(v6460 ^ ((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v6466 = v6465[v6635];
    int v6467 = v6465[v6628];
    int v6636 = v6467 + ((int)((unsigned int)(v6467 - v6466) >> 31));
    v6465[v6628] = v6636;
    int * v6469 = v6452->cache_age;
    int v6470 = v6469[v6629];
    int v6638 = v6470 + ((int)((unsigned int)(v6470 - v6466) >> 31));
    v6469[v6629] = v6638;
    int * v6472 = v6452->cache_age;
    v6472[v6635] = 0;
    v6557 = v6635;
  } else {
    int * v6475 = v6452->cache_age;
    int v6642 = (((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1)) & 1) * 2;
    int v6476 = v6475[v6642];
    int * v6477 = v6452->cache_tags;
    int v6478 = v6477[v6642];
    int v6479 = v6475[v6629];
    int v6480 = v6477[v6629];
    bool v6644 = !(((~(((v6461 ^ ((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1))) | (-(v6461 ^ ((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v6462 ^ ((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1))) | (-(v6462 ^ ((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v6534;
    if (v6644) {
      int * v6481 = v6452->cache_age;
      int v6646 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v6462 ^ ((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1))) | (-(v6462 ^ ((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v6482 = v6481[v6646];
      int v6483 = v6481[v6630];
      int v6647 = v6483 + ((int)((unsigned int)(v6483 - v6482) >> 31));
      v6481[v6630] = v6647;
      int * v6485 = v6452->cache_age;
      int v6486 = v6485[v6631];
      int v6649 = v6486 + ((int)((unsigned int)(v6486 - v6482) >> 31));
      v6485[v6631] = v6649;
      int * v6488 = v6452->cache_age;
      v6488[v6646] = 0;
      v6534 = v6646;
    } else {
      int * v6491 = v6452->cache_age;
      int v6653 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1)) & 3) * 2);
      int v6492 = v6491[v6653];
      int * v6493 = v6452->cache_tags;
      int v6494 = v6493[v6653];
      int v6495 = v6491[v6631];
      int v6496 = v6493[v6631];
      int * v6497 = v6452->cache_dirty;
      int v6656 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v6492 + ((~(((v6494 ^ -1) | (-(v6494 ^ -1))) >> 31)) & 2)) - (v6495 + ((~(((v6496 ^ -1) | (-(v6496 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v6498 = v6497[v6656];
      bool v6657 = !(v6498 == 0);
      if (v6657) {
        int * v6499 = v6452->cache_tags;
        int v6500 = v6499[v6656];
        int * v6501 = v6452->cache_vals;
        int v6660 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v6492 + ((~(((v6494 ^ -1) | (-(v6494 ^ -1))) >> 31)) & 2)) - (v6495 + ((~(((v6496 ^ -1) | (-(v6496 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v6502 = v6501[v6660];
        int v6661 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v6492 + ((~(((v6494 ^ -1) | (-(v6494 ^ -1))) >> 31)) & 2)) - (v6495 + ((~(((v6496 ^ -1) | (-(v6496 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v6503 = v6501[v6661];
        int * v6504 = v6452->mem;
        int v6663 = v6500 * 2;
        v6504[v6663] = v6502;
        int * v6506 = v6452->mem;
        int v6666 = (v6500 * 2) + 1;
        v6506[v6666] = v6503;
        ;
      } else {
        ;
      }
      int * v6511 = v6452->mem;
      int v6671 = ((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1)) * 2;
      int v6512 = v6511[v6671];
      int v6672 = (((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1)) * 2) + 1;
      int v6513 = v6511[v6672];
      int * v6514 = v6452->cache_vals;
      int v6674 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v6492 + ((~(((v6494 ^ -1) | (-(v6494 ^ -1))) >> 31)) & 2)) - (v6495 + ((~(((v6496 ^ -1) | (-(v6496 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v6514[v6674] = v6512;
      int * v6516 = v6452->cache_vals;
      int v6677 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v6492 + ((~(((v6494 ^ -1) | (-(v6494 ^ -1))) >> 31)) & 2)) - (v6495 + ((~(((v6496 ^ -1) | (-(v6496 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v6516[v6677] = v6513;
      int * v6518 = v6452->cache_tags;
      int v6680 = (int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1);
      v6518[v6656] = v6680;
      int * v6520 = v6452->cache_dirty;
      v6520[v6656] = 0;
      int * v6522 = v6452->cache_age;
      v6522[v6656] = 1;
      int * v6524 = v6452->cache_age;
      int v6525 = v6524[v6656];
      int v6526 = v6524[v6630];
      int v6686 = v6526 + ((int)((unsigned int)(v6526 - v6525) >> 31));
      v6524[v6630] = v6686;
      int * v6528 = v6452->cache_age;
      int v6529 = v6528[v6631];
      int v6688 = v6529 + ((int)((unsigned int)(v6529 - v6525) >> 31));
      v6528[v6631] = v6688;
      int * v6531 = v6452->cache_age;
      v6531[v6656] = 0;
      v6534 = v6656;
    }
    int * v6535 = v6452->cache_vals;
    int v6691 = v6534 * 2;
    int v6536 = v6535[v6691];
    int v6692 = (v6534 * 2) + 1;
    int v6537 = v6535[v6692];
    int v6693 = (((((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v6476 + ((~(((v6478 ^ -1) | (-(v6478 ^ -1))) >> 31)) & 2)) - (v6479 + ((~(((v6480 ^ -1) | (-(v6480 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6535[v6693] = v6536;
    int * v6539 = v6452->cache_vals;
    int v6696 = ((((((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v6476 + ((~(((v6478 ^ -1) | (-(v6478 ^ -1))) >> 31)) & 2)) - (v6479 + ((~(((v6480 ^ -1) | (-(v6480 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6539[v6696] = v6537;
    int * v6541 = v6452->cache_tags;
    int v6699 = ((((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v6476 + ((~(((v6478 ^ -1) | (-(v6478 ^ -1))) >> 31)) & 2)) - (v6479 + ((~(((v6480 ^ -1) | (-(v6480 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6700 = (int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1);
    v6541[v6699] = v6700;
    int * v6543 = v6452->cache_dirty;
    v6543[v6699] = 0;
    int * v6545 = v6452->cache_age;
    v6545[v6699] = 1;
    int * v6547 = v6452->cache_age;
    int v6548 = v6547[v6699];
    int v6549 = v6547[v6628];
    int v6706 = v6549 + ((int)((unsigned int)(v6549 - v6548) >> 31));
    v6547[v6628] = v6706;
    int * v6551 = v6452->cache_age;
    int v6552 = v6551[v6629];
    int v6708 = v6552 + ((int)((unsigned int)(v6552 - v6548) >> 31));
    v6551[v6629] = v6708;
    int * v6554 = v6452->cache_age;
    v6554[v6699] = 0;
    v6557 = v6699;
  }
  int * v6558 = v6452->cache_vals;
  int v6711 = (v6557 * 2) + (((int)((unsigned int)(v6456 + 12) >> 2)) & 1);
  v6558[v6711] = v6457;
  int * v6560 = v6452->cache_tags;
  int v6561 = v6560[v6630];
  int v6562 = v6560[v6631];
  bool v6714 = !(((~(((v6561 ^ ((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1))) | (-(v6561 ^ ((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v6562 ^ ((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1))) | (-(v6562 ^ ((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v6616;
  if (v6714) {
    int * v6563 = v6452->cache_age;
    int v6716 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v6562 ^ ((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1))) | (-(v6562 ^ ((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v6564 = v6563[v6716];
    int v6565 = v6563[v6630];
    int v6717 = v6565 + ((int)((unsigned int)(v6565 - v6564) >> 31));
    v6563[v6630] = v6717;
    int * v6567 = v6452->cache_age;
    int v6568 = v6567[v6631];
    int v6719 = v6568 + ((int)((unsigned int)(v6568 - v6564) >> 31));
    v6567[v6631] = v6719;
    int * v6570 = v6452->cache_age;
    v6570[v6716] = 0;
    v6616 = v6716;
  } else {
    int * v6573 = v6452->cache_age;
    int v6723 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1)) & 3) * 2);
    int v6574 = v6573[v6723];
    int * v6575 = v6452->cache_tags;
    int v6576 = v6575[v6723];
    int v6577 = v6573[v6631];
    int v6578 = v6575[v6631];
    int * v6579 = v6452->cache_dirty;
    int v6726 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v6574 + ((~(((v6576 ^ -1) | (-(v6576 ^ -1))) >> 31)) & 2)) - (v6577 + ((~(((v6578 ^ -1) | (-(v6578 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6580 = v6579[v6726];
    bool v6727 = !(v6580 == 0);
    if (v6727) {
      int * v6581 = v6452->cache_tags;
      int v6582 = v6581[v6726];
      int * v6583 = v6452->cache_vals;
      int v6730 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v6574 + ((~(((v6576 ^ -1) | (-(v6576 ^ -1))) >> 31)) & 2)) - (v6577 + ((~(((v6578 ^ -1) | (-(v6578 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v6584 = v6583[v6730];
      int v6731 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v6574 + ((~(((v6576 ^ -1) | (-(v6576 ^ -1))) >> 31)) & 2)) - (v6577 + ((~(((v6578 ^ -1) | (-(v6578 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v6585 = v6583[v6731];
      int * v6586 = v6452->mem;
      int v6733 = v6582 * 2;
      v6586[v6733] = v6584;
      int * v6588 = v6452->mem;
      int v6736 = (v6582 * 2) + 1;
      v6588[v6736] = v6585;
      ;
    } else {
      ;
    }
    int * v6593 = v6452->mem;
    int v6741 = ((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1)) * 2;
    int v6594 = v6593[v6741];
    int v6742 = (((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1)) * 2) + 1;
    int v6595 = v6593[v6742];
    int * v6596 = v6452->cache_vals;
    int v6744 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v6574 + ((~(((v6576 ^ -1) | (-(v6576 ^ -1))) >> 31)) & 2)) - (v6577 + ((~(((v6578 ^ -1) | (-(v6578 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v6596[v6744] = v6594;
    int * v6598 = v6452->cache_vals;
    int v6747 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v6574 + ((~(((v6576 ^ -1) | (-(v6576 ^ -1))) >> 31)) & 2)) - (v6577 + ((~(((v6578 ^ -1) | (-(v6578 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v6598[v6747] = v6595;
    int * v6600 = v6452->cache_tags;
    int v6750 = (int)((unsigned int)((int)((unsigned int)(v6456 + 12) >> 2)) >> 1);
    v6600[v6726] = v6750;
    int * v6602 = v6452->cache_dirty;
    v6602[v6726] = 0;
    int * v6604 = v6452->cache_age;
    v6604[v6726] = 1;
    int * v6606 = v6452->cache_age;
    int v6607 = v6606[v6726];
    int v6608 = v6606[v6630];
    int v6756 = v6608 + ((int)((unsigned int)(v6608 - v6607) >> 31));
    v6606[v6630] = v6756;
    int * v6610 = v6452->cache_age;
    int v6611 = v6610[v6631];
    int v6758 = v6611 + ((int)((unsigned int)(v6611 - v6607) >> 31));
    v6610[v6631] = v6758;
    int * v6613 = v6452->cache_age;
    v6613[v6726] = 0;
    v6616 = v6726;
  }
  int * v6617 = v6452->cache_vals;
  int v6761 = (v6616 * 2) + (((int)((unsigned int)(v6456 + 12) >> 2)) & 1);
  v6617[v6761] = v6457;
  int * v6619 = v6452->cache_dirty;
  v6619[v6616] = 1;
  struct StateT * v6621 = slot_199(v6452);
  return v6621;
}

struct StateT * slot_1(struct StateT * v16) {
  int v17 = v16->timer;
  int v187 = v17 + 1;
  v16->timer = v187;
  int * v19 = v16->regs;
  int v20 = v19[2];
  int v21 = v19[8];
  int * v22 = v16->cache_tags;
  int v192 = (((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 1) * 2;
  int v23 = v22[v192];
  int v193 = ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 1) * 2) + 1;
  int v24 = v22[v193];
  int v194 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 3) * 2);
  int v25 = v22[v194];
  int v195 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v26 = v22[v195];
  int v27 = v16->timer;
  int v196 = v27 + ((100 ^ (((~(((v25 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))) | (-(v25 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v25 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))) | (-(v25 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))))) >> 31))) & 104)))));
  v16->timer = v196;
  bool v197 = !(((~(((v23 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))) | (-(v23 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))))) >> 31))) == 0);
  int v121;
  if (v197) {
    int * v29 = v16->cache_age;
    int v199 = ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 1) * 2) + ((~(((v24 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))) | (-(v24 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))))) >> 31)) & 1);
    int v30 = v29[v199];
    int v31 = v29[v192];
    int v200 = v31 + ((int)((unsigned int)(v31 - v30) >> 31));
    v29[v192] = v200;
    int * v33 = v16->cache_age;
    int v34 = v33[v193];
    int v202 = v34 + ((int)((unsigned int)(v34 - v30) >> 31));
    v33[v193] = v202;
    int * v36 = v16->cache_age;
    v36[v199] = 0;
    v121 = v199;
  } else {
    int * v39 = v16->cache_age;
    int v206 = (((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 1) * 2;
    int v40 = v39[v206];
    int * v41 = v16->cache_tags;
    int v42 = v41[v206];
    int v43 = v39[v193];
    int v44 = v41[v193];
    bool v208 = !(((~(((v25 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))) | (-(v25 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))))) >> 31))) == 0);
    int v98;
    if (v208) {
      int * v45 = v16->cache_age;
      int v210 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 3) * 2)) + ((~(((v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))) | (-(v26 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))))) >> 31)) & 1);
      int v46 = v45[v210];
      int v47 = v45[v194];
      int v211 = v47 + ((int)((unsigned int)(v47 - v46) >> 31));
      v45[v194] = v211;
      int * v49 = v16->cache_age;
      int v50 = v49[v195];
      int v213 = v50 + ((int)((unsigned int)(v50 - v46) >> 31));
      v49[v195] = v213;
      int * v52 = v16->cache_age;
      v52[v210] = 0;
      v98 = v210;
    } else {
      int * v55 = v16->cache_age;
      int v217 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 3) * 2);
      int v56 = v55[v217];
      int * v57 = v16->cache_tags;
      int v58 = v57[v217];
      int v59 = v55[v195];
      int v60 = v57[v195];
      int * v61 = v16->cache_dirty;
      int v220 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v56 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2)) - (v59 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v62 = v61[v220];
      bool v221 = !(v62 == 0);
      if (v221) {
        int * v63 = v16->cache_tags;
        int v64 = v63[v220];
        int * v65 = v16->cache_vals;
        int v224 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v56 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2)) - (v59 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v66 = v65[v224];
        int v225 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v56 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2)) - (v59 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v67 = v65[v225];
        int * v68 = v16->mem;
        int v227 = v64 * 2;
        v68[v227] = v66;
        int * v70 = v16->mem;
        int v230 = (v64 * 2) + 1;
        v70[v230] = v67;
        ;
      } else {
        ;
      }
      int * v75 = v16->mem;
      int v235 = ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) * 2;
      int v76 = v75[v235];
      int v236 = (((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) * 2) + 1;
      int v77 = v75[v236];
      int * v78 = v16->cache_vals;
      int v238 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v56 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2)) - (v59 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v78[v238] = v76;
      int * v80 = v16->cache_vals;
      int v241 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v56 + ((~(((v58 ^ -1) | (-(v58 ^ -1))) >> 31)) & 2)) - (v59 + ((~(((v60 ^ -1) | (-(v60 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v80[v241] = v77;
      int * v82 = v16->cache_tags;
      int v244 = (int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1);
      v82[v220] = v244;
      int * v84 = v16->cache_dirty;
      v84[v220] = 0;
      int * v86 = v16->cache_age;
      v86[v220] = 1;
      int * v88 = v16->cache_age;
      int v89 = v88[v220];
      int v90 = v88[v194];
      int v250 = v90 + ((int)((unsigned int)(v90 - v89) >> 31));
      v88[v194] = v250;
      int * v92 = v16->cache_age;
      int v93 = v92[v195];
      int v252 = v93 + ((int)((unsigned int)(v93 - v89) >> 31));
      v92[v195] = v252;
      int * v95 = v16->cache_age;
      v95[v220] = 0;
      v98 = v220;
    }
    int * v99 = v16->cache_vals;
    int v255 = v98 * 2;
    int v100 = v99[v255];
    int v256 = (v98 * 2) + 1;
    int v101 = v99[v256];
    int v257 = (((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 1) * 2) + ((((v40 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2)) - (v43 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v99[v257] = v100;
    int * v103 = v16->cache_vals;
    int v260 = ((((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 1) * 2) + ((((v40 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2)) - (v43 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v103[v260] = v101;
    int * v105 = v16->cache_tags;
    int v263 = ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 1) * 2) + ((((v40 + ((~(((v42 ^ -1) | (-(v42 ^ -1))) >> 31)) & 2)) - (v43 + ((~(((v44 ^ -1) | (-(v44 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v264 = (int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1);
    v105[v263] = v264;
    int * v107 = v16->cache_dirty;
    v107[v263] = 0;
    int * v109 = v16->cache_age;
    v109[v263] = 1;
    int * v111 = v16->cache_age;
    int v112 = v111[v263];
    int v113 = v111[v192];
    int v270 = v113 + ((int)((unsigned int)(v113 - v112) >> 31));
    v111[v192] = v270;
    int * v115 = v16->cache_age;
    int v116 = v115[v193];
    int v272 = v116 + ((int)((unsigned int)(v116 - v112) >> 31));
    v115[v193] = v272;
    int * v118 = v16->cache_age;
    v118[v263] = 0;
    v121 = v263;
  }
  int * v122 = v16->cache_vals;
  int v275 = (v121 * 2) + (((int)((unsigned int)(v20 + 44) >> 2)) & 1);
  v122[v275] = v21;
  int * v124 = v16->cache_tags;
  int v125 = v124[v194];
  int v126 = v124[v195];
  bool v278 = !(((~(((v125 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))) | (-(v125 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v126 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))) | (-(v126 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))))) >> 31))) == 0);
  int v180;
  if (v278) {
    int * v127 = v16->cache_age;
    int v280 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 3) * 2)) + ((~(((v126 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))) | (-(v126 ^ ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1))))) >> 31)) & 1);
    int v128 = v127[v280];
    int v129 = v127[v194];
    int v281 = v129 + ((int)((unsigned int)(v129 - v128) >> 31));
    v127[v194] = v281;
    int * v131 = v16->cache_age;
    int v132 = v131[v195];
    int v283 = v132 + ((int)((unsigned int)(v132 - v128) >> 31));
    v131[v195] = v283;
    int * v134 = v16->cache_age;
    v134[v280] = 0;
    v180 = v280;
  } else {
    int * v137 = v16->cache_age;
    int v287 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 3) * 2);
    int v138 = v137[v287];
    int * v139 = v16->cache_tags;
    int v140 = v139[v287];
    int v141 = v137[v195];
    int v142 = v139[v195];
    int * v143 = v16->cache_dirty;
    int v290 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v144 = v143[v290];
    bool v291 = !(v144 == 0);
    if (v291) {
      int * v145 = v16->cache_tags;
      int v146 = v145[v290];
      int * v147 = v16->cache_vals;
      int v294 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v148 = v147[v294];
      int v295 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v149 = v147[v295];
      int * v150 = v16->mem;
      int v297 = v146 * 2;
      v150[v297] = v148;
      int * v152 = v16->mem;
      int v300 = (v146 * 2) + 1;
      v152[v300] = v149;
      ;
    } else {
      ;
    }
    int * v157 = v16->mem;
    int v305 = ((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) * 2;
    int v158 = v157[v305];
    int v306 = (((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) * 2) + 1;
    int v159 = v157[v306];
    int * v160 = v16->cache_vals;
    int v308 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v160[v308] = v158;
    int * v162 = v16->cache_vals;
    int v311 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v138 + ((~(((v140 ^ -1) | (-(v140 ^ -1))) >> 31)) & 2)) - (v141 + ((~(((v142 ^ -1) | (-(v142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v162[v311] = v159;
    int * v164 = v16->cache_tags;
    int v314 = (int)((unsigned int)((int)((unsigned int)(v20 + 44) >> 2)) >> 1);
    v164[v290] = v314;
    int * v166 = v16->cache_dirty;
    v166[v290] = 0;
    int * v168 = v16->cache_age;
    v168[v290] = 1;
    int * v170 = v16->cache_age;
    int v171 = v170[v290];
    int v172 = v170[v194];
    int v320 = v172 + ((int)((unsigned int)(v172 - v171) >> 31));
    v170[v194] = v320;
    int * v174 = v16->cache_age;
    int v175 = v174[v195];
    int v322 = v175 + ((int)((unsigned int)(v175 - v171) >> 31));
    v174[v195] = v322;
    int * v177 = v16->cache_age;
    v177[v290] = 0;
    v180 = v290;
  }
  int * v181 = v16->cache_vals;
  int v325 = (v180 * 2) + (((int)((unsigned int)(v20 + 44) >> 2)) & 1);
  v181[v325] = v21;
  int * v183 = v16->cache_dirty;
  v183[v180] = 1;
  struct StateT * v185 = slot_2(v16);
  return v185;
}

struct StateT * slot_187(struct StateT * v12233) {
  int v12234 = v12233->timer;
  int v12241 = v12234 + 1;
  v12233->timer = v12241;
  int * v12236 = v12233->regs;
  int v12237 = v12236[23];
  int v12244 = v12237 << 18;
  v12236[23] = v12244;
  struct StateT * v12239 = slot_188(v12233);
  return v12239;
}

struct StateT * slot_97(struct StateT * v10835) {
  int v10836 = v10835->timer;
  int v10843 = v10836 + 1;
  v10835->timer = v10843;
  int * v10838 = v10835->regs;
  int v10839 = v10838[20];
  int v10847 = (int)((unsigned int)v10839 >> 14);
  v10838[24] = v10847;
  struct StateT * v10841 = slot_98(v10835);
  return v10841;
}

struct StateT * slot_182(struct StateT * v12157) {
  int v12158 = v12157->timer;
  int v12166 = v12158 + 1;
  v12157->timer = v12166;
  int * v12160 = v12157->regs;
  int v12161 = v12160[21];
  int v12162 = v12160[24];
  int v12170 = v12161 | v12162;
  v12160[21] = v12170;
  struct StateT * v12164 = slot_183(v12157);
  return v12164;
}

struct StateT * slot_38(struct StateT * v7429) {
  int v7430 = v7429->timer;
  int v7437 = v7430 + 1;
  v7429->timer = v7437;
  int * v7432 = v7429->regs;
  int v7433 = v7432[20];
  int v7440 = v7433 << 7;
  v7432[20] = v7440;
  struct StateT * v7435 = slot_39(v7429);
  return v7435;
}

struct StateT * slot_178(struct StateT * v12098) {
  int v12099 = v12098->timer;
  int v12106 = v12099 + 1;
  v12098->timer = v12106;
  int * v12101 = v12098->regs;
  int v12102 = v12101[20];
  int v12109 = v12102 << 18;
  v12101[20] = v12109;
  struct StateT * v12104 = slot_179(v12098);
  return v12104;
}

struct StateT * slot_106(struct StateT * v10970) {
  int v10971 = v10970->timer;
  int v10978 = v10971 + 1;
  v10970->timer = v10978;
  int * v10973 = v10970->regs;
  int v10974 = v10973[23];
  int v10982 = (int)((unsigned int)v10974 >> 14);
  v10973[24] = v10982;
  struct StateT * v10976 = slot_107(v10970);
  return v10976;
}

struct StateT * slot_98(struct StateT * v10850) {
  int v10851 = v10850->timer;
  int v10858 = v10851 + 1;
  v10850->timer = v10858;
  int * v10853 = v10850->regs;
  int v10854 = v10853[20];
  int v10861 = v10854 << 18;
  v10853[20] = v10861;
  struct StateT * v10856 = slot_99(v10850);
  return v10856;
}

struct StateT * slot_159(struct StateT * v11800) {
  int v11801 = v11800->timer;
  int v11809 = v11801 + 1;
  v11800->timer = v11809;
  int * v11803 = v11800->regs;
  int v11804 = v11803[20];
  int v11805 = v11803[24];
  int v11813 = v11804 | v11805;
  v11803[20] = v11813;
  struct StateT * v11807 = slot_160(v11800);
  return v11807;
}

struct StateT * slot_46(struct StateT * v9403) {
  int v9404 = v9403->timer;
  int v9411 = v9404 + 1;
  v9403->timer = v9411;
  int * v9406 = v9403->regs;
  int v9407 = v9406[23];
  int v9415 = (int)((unsigned int)v9407 >> 25);
  v9406[24] = v9415;
  struct StateT * v9409 = slot_47(v9403);
  return v9409;
}

struct StateT * slot_212(struct StateT * v10076) {
  int v10077 = v10076->timer;
  int v10084 = v10077 + 1;
  v10076->timer = v10084;
  int * v10079 = v10076->regs;
  int v10080 = v10079[2];
  int v10087 = v10080 + 48;
  v10079[2] = v10087;
  struct StateT * v10082 = slot_213(v10076);
  return v10082;
}

struct StateT * slot_132(struct StateT * v11375) {
  int v11376 = v11375->timer;
  int v11384 = v11376 + 1;
  v11375->timer = v11384;
  int * v11378 = v11375->regs;
  int v11379 = v11378[16];
  int v11380 = v11378[23];
  int v11388 = v11379 ^ v11380;
  v11378[16] = v11388;
  struct StateT * v11382 = slot_133(v11375);
  return v11382;
}

struct StateT * slot_130(struct StateT * v11343) {
  int v11344 = v11343->timer;
  int v11352 = v11344 + 1;
  v11343->timer = v11352;
  int * v11346 = v11343->regs;
  int v11347 = v11346[12];
  int v11348 = v11346[21];
  int v11356 = v11347 ^ v11348;
  v11346[12] = v11356;
  struct StateT * v11350 = slot_131(v11343);
  return v11350;
}

struct StateT * slot_211(struct StateT * v9856) {
  int v9857 = v9856->timer;
  int v9967 = v9857 + 1;
  v9856->timer = v9967;
  int * v9859 = v9856->regs;
  int v9860 = v9859[2];
  int * v9861 = v9856->cache_tags;
  int v9971 = (((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1)) & 1) * 2;
  int v9862 = v9861[v9971];
  int v9972 = ((((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v9863 = v9861[v9972];
  int v9973 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1)) & 3) * 2);
  int v9864 = v9861[v9973];
  int v9974 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v9865 = v9861[v9974];
  int v9866 = v9856->timer;
  int v9975 = v9866 + ((100 ^ (((~(((v9864 ^ ((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1))) | (-(v9864 ^ ((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v9865 ^ ((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1))) | (-(v9865 ^ ((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v9862 ^ ((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1))) | (-(v9862 ^ ((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v9863 ^ ((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1))) | (-(v9863 ^ ((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v9864 ^ ((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1))) | (-(v9864 ^ ((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v9865 ^ ((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1))) | (-(v9865 ^ ((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v9856->timer = v9975;
  int * v9868 = v9856->cache_vals;
  bool v9976 = !(((~(((v9862 ^ ((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1))) | (-(v9862 ^ ((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v9863 ^ ((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1))) | (-(v9863 ^ ((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v9961;
  if (v9976) {
    int * v9869 = v9856->cache_age;
    int v9978 = ((((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v9863 ^ ((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1))) | (-(v9863 ^ ((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v9870 = v9869[v9978];
    int v9871 = v9869[v9971];
    int v9979 = v9871 + ((int)((unsigned int)(v9871 - v9870) >> 31));
    v9869[v9971] = v9979;
    int * v9873 = v9856->cache_age;
    int v9874 = v9873[v9972];
    int v9981 = v9874 + ((int)((unsigned int)(v9874 - v9870) >> 31));
    v9873[v9972] = v9981;
    int * v9876 = v9856->cache_age;
    v9876[v9978] = 0;
    v9961 = v9978;
  } else {
    int * v9879 = v9856->cache_age;
    int v9985 = (((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1)) & 1) * 2;
    int v9880 = v9879[v9985];
    int * v9881 = v9856->cache_tags;
    int v9882 = v9881[v9985];
    int v9883 = v9879[v9972];
    int v9884 = v9881[v9972];
    bool v9987 = !(((~(((v9864 ^ ((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1))) | (-(v9864 ^ ((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v9865 ^ ((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1))) | (-(v9865 ^ ((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v9938;
    if (v9987) {
      int * v9885 = v9856->cache_age;
      int v9989 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v9865 ^ ((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1))) | (-(v9865 ^ ((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v9886 = v9885[v9989];
      int v9887 = v9885[v9973];
      int v9990 = v9887 + ((int)((unsigned int)(v9887 - v9886) >> 31));
      v9885[v9973] = v9990;
      int * v9889 = v9856->cache_age;
      int v9890 = v9889[v9974];
      int v9992 = v9890 + ((int)((unsigned int)(v9890 - v9886) >> 31));
      v9889[v9974] = v9992;
      int * v9892 = v9856->cache_age;
      v9892[v9989] = 0;
      v9938 = v9989;
    } else {
      int * v9895 = v9856->cache_age;
      int v9996 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1)) & 3) * 2);
      int v9896 = v9895[v9996];
      int * v9897 = v9856->cache_tags;
      int v9898 = v9897[v9996];
      int v9899 = v9895[v9974];
      int v9900 = v9897[v9974];
      int * v9901 = v9856->cache_dirty;
      int v9999 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v9896 + ((~(((v9898 ^ -1) | (-(v9898 ^ -1))) >> 31)) & 2)) - (v9899 + ((~(((v9900 ^ -1) | (-(v9900 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v9902 = v9901[v9999];
      bool v10000 = !(v9902 == 0);
      if (v10000) {
        int * v9903 = v9856->cache_tags;
        int v9904 = v9903[v9999];
        int * v9905 = v9856->cache_vals;
        int v10003 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v9896 + ((~(((v9898 ^ -1) | (-(v9898 ^ -1))) >> 31)) & 2)) - (v9899 + ((~(((v9900 ^ -1) | (-(v9900 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v9906 = v9905[v10003];
        int v10004 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v9896 + ((~(((v9898 ^ -1) | (-(v9898 ^ -1))) >> 31)) & 2)) - (v9899 + ((~(((v9900 ^ -1) | (-(v9900 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v9907 = v9905[v10004];
        int * v9908 = v9856->mem;
        int v10006 = v9904 * 2;
        v9908[v10006] = v9906;
        int * v9910 = v9856->mem;
        int v10009 = (v9904 * 2) + 1;
        v9910[v10009] = v9907;
        ;
      } else {
        ;
      }
      int * v9915 = v9856->mem;
      int v10014 = ((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1)) * 2;
      int v9916 = v9915[v10014];
      int v10015 = (((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1)) * 2) + 1;
      int v9917 = v9915[v10015];
      int * v9918 = v9856->cache_vals;
      int v10017 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v9896 + ((~(((v9898 ^ -1) | (-(v9898 ^ -1))) >> 31)) & 2)) - (v9899 + ((~(((v9900 ^ -1) | (-(v9900 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v9918[v10017] = v9916;
      int * v9920 = v9856->cache_vals;
      int v10020 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v9896 + ((~(((v9898 ^ -1) | (-(v9898 ^ -1))) >> 31)) & 2)) - (v9899 + ((~(((v9900 ^ -1) | (-(v9900 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v9920[v10020] = v9917;
      int * v9922 = v9856->cache_tags;
      int v10023 = (int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1);
      v9922[v9999] = v10023;
      int * v9924 = v9856->cache_dirty;
      v9924[v9999] = 0;
      int * v9926 = v9856->cache_age;
      v9926[v9999] = 1;
      int * v9928 = v9856->cache_age;
      int v9929 = v9928[v9999];
      int v9930 = v9928[v9973];
      int v10029 = v9930 + ((int)((unsigned int)(v9930 - v9929) >> 31));
      v9928[v9973] = v10029;
      int * v9932 = v9856->cache_age;
      int v9933 = v9932[v9974];
      int v10031 = v9933 + ((int)((unsigned int)(v9933 - v9929) >> 31));
      v9932[v9974] = v10031;
      int * v9935 = v9856->cache_age;
      v9935[v9999] = 0;
      v9938 = v9999;
    }
    int * v9939 = v9856->cache_vals;
    int v10034 = v9938 * 2;
    int v9940 = v9939[v10034];
    int v10035 = (v9938 * 2) + 1;
    int v9941 = v9939[v10035];
    int v10036 = (((((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v9880 + ((~(((v9882 ^ -1) | (-(v9882 ^ -1))) >> 31)) & 2)) - (v9883 + ((~(((v9884 ^ -1) | (-(v9884 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9939[v10036] = v9940;
    int * v9943 = v9856->cache_vals;
    int v10039 = ((((((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v9880 + ((~(((v9882 ^ -1) | (-(v9882 ^ -1))) >> 31)) & 2)) - (v9883 + ((~(((v9884 ^ -1) | (-(v9884 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9943[v10039] = v9941;
    int * v9945 = v9856->cache_tags;
    int v10042 = ((((int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v9880 + ((~(((v9882 ^ -1) | (-(v9882 ^ -1))) >> 31)) & 2)) - (v9883 + ((~(((v9884 ^ -1) | (-(v9884 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v10043 = (int)((unsigned int)((int)((unsigned int)(v9860 + 12) >> 2)) >> 1);
    v9945[v10042] = v10043;
    int * v9947 = v9856->cache_dirty;
    v9947[v10042] = 0;
    int * v9949 = v9856->cache_age;
    v9949[v10042] = 1;
    int * v9951 = v9856->cache_age;
    int v9952 = v9951[v10042];
    int v9953 = v9951[v9971];
    int v10049 = v9953 + ((int)((unsigned int)(v9953 - v9952) >> 31));
    v9951[v9971] = v10049;
    int * v9955 = v9856->cache_age;
    int v9956 = v9955[v9972];
    int v10051 = v9956 + ((int)((unsigned int)(v9956 - v9952) >> 31));
    v9955[v9972] = v10051;
    int * v9958 = v9856->cache_age;
    v9958[v10042] = 0;
    v9961 = v10042;
  }
  int v10054 = (v9961 * 2) + (((int)((unsigned int)(v9860 + 12) >> 2)) & 1);
  int v9962 = v9868[v10054];
  int * v9963 = v9856->regs;
  v9963[24] = v9962;
  struct StateT * v9965 = slot_212(v9856);
  return v9965;
}

struct StateT * slot_20(struct StateT * v4700) {
  int v4701 = v4700->timer;
  int v4811 = v4701 + 1;
  v4700->timer = v4811;
  int * v4703 = v4700->regs;
  int v4704 = v4703[11];
  int * v4705 = v4700->cache_tags;
  int v4815 = (((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1)) & 1) * 2;
  int v4706 = v4705[v4815];
  int v4816 = ((((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4707 = v4705[v4816];
  int v4817 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1)) & 3) * 2);
  int v4708 = v4705[v4817];
  int v4818 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4709 = v4705[v4818];
  int v4710 = v4700->timer;
  int v4819 = v4710 + ((100 ^ (((~(((v4708 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))) | (-(v4708 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4709 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))) | (-(v4709 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4706 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))) | (-(v4706 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4707 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))) | (-(v4707 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4708 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))) | (-(v4708 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4709 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))) | (-(v4709 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4700->timer = v4819;
  int * v4712 = v4700->cache_vals;
  bool v4820 = !(((~(((v4706 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))) | (-(v4706 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4707 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))) | (-(v4707 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v4805;
  if (v4820) {
    int * v4713 = v4700->cache_age;
    int v4822 = ((((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v4707 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))) | (-(v4707 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v4714 = v4713[v4822];
    int v4715 = v4713[v4815];
    int v4823 = v4715 + ((int)((unsigned int)(v4715 - v4714) >> 31));
    v4713[v4815] = v4823;
    int * v4717 = v4700->cache_age;
    int v4718 = v4717[v4816];
    int v4825 = v4718 + ((int)((unsigned int)(v4718 - v4714) >> 31));
    v4717[v4816] = v4825;
    int * v4720 = v4700->cache_age;
    v4720[v4822] = 0;
    v4805 = v4822;
  } else {
    int * v4723 = v4700->cache_age;
    int v4829 = (((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1)) & 1) * 2;
    int v4724 = v4723[v4829];
    int * v4725 = v4700->cache_tags;
    int v4726 = v4725[v4829];
    int v4727 = v4723[v4816];
    int v4728 = v4725[v4816];
    bool v4831 = !(((~(((v4708 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))) | (-(v4708 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v4709 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))) | (-(v4709 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v4782;
    if (v4831) {
      int * v4729 = v4700->cache_age;
      int v4833 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4709 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))) | (-(v4709 ^ ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v4730 = v4729[v4833];
      int v4731 = v4729[v4817];
      int v4834 = v4731 + ((int)((unsigned int)(v4731 - v4730) >> 31));
      v4729[v4817] = v4834;
      int * v4733 = v4700->cache_age;
      int v4734 = v4733[v4818];
      int v4836 = v4734 + ((int)((unsigned int)(v4734 - v4730) >> 31));
      v4733[v4818] = v4836;
      int * v4736 = v4700->cache_age;
      v4736[v4833] = 0;
      v4782 = v4833;
    } else {
      int * v4739 = v4700->cache_age;
      int v4840 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1)) & 3) * 2);
      int v4740 = v4739[v4840];
      int * v4741 = v4700->cache_tags;
      int v4742 = v4741[v4840];
      int v4743 = v4739[v4818];
      int v4744 = v4741[v4818];
      int * v4745 = v4700->cache_dirty;
      int v4843 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4740 + ((~(((v4742 ^ -1) | (-(v4742 ^ -1))) >> 31)) & 2)) - (v4743 + ((~(((v4744 ^ -1) | (-(v4744 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4746 = v4745[v4843];
      bool v4844 = !(v4746 == 0);
      if (v4844) {
        int * v4747 = v4700->cache_tags;
        int v4748 = v4747[v4843];
        int * v4749 = v4700->cache_vals;
        int v4847 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4740 + ((~(((v4742 ^ -1) | (-(v4742 ^ -1))) >> 31)) & 2)) - (v4743 + ((~(((v4744 ^ -1) | (-(v4744 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4750 = v4749[v4847];
        int v4848 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4740 + ((~(((v4742 ^ -1) | (-(v4742 ^ -1))) >> 31)) & 2)) - (v4743 + ((~(((v4744 ^ -1) | (-(v4744 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4751 = v4749[v4848];
        int * v4752 = v4700->mem;
        int v4850 = v4748 * 2;
        v4752[v4850] = v4750;
        int * v4754 = v4700->mem;
        int v4853 = (v4748 * 2) + 1;
        v4754[v4853] = v4751;
        ;
      } else {
        ;
      }
      int * v4759 = v4700->mem;
      int v4858 = ((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1)) * 2;
      int v4760 = v4759[v4858];
      int v4859 = (((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1)) * 2) + 1;
      int v4761 = v4759[v4859];
      int * v4762 = v4700->cache_vals;
      int v4861 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4740 + ((~(((v4742 ^ -1) | (-(v4742 ^ -1))) >> 31)) & 2)) - (v4743 + ((~(((v4744 ^ -1) | (-(v4744 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4762[v4861] = v4760;
      int * v4764 = v4700->cache_vals;
      int v4864 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v4740 + ((~(((v4742 ^ -1) | (-(v4742 ^ -1))) >> 31)) & 2)) - (v4743 + ((~(((v4744 ^ -1) | (-(v4744 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4764[v4864] = v4761;
      int * v4766 = v4700->cache_tags;
      int v4867 = (int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1);
      v4766[v4843] = v4867;
      int * v4768 = v4700->cache_dirty;
      v4768[v4843] = 0;
      int * v4770 = v4700->cache_age;
      v4770[v4843] = 1;
      int * v4772 = v4700->cache_age;
      int v4773 = v4772[v4843];
      int v4774 = v4772[v4817];
      int v4873 = v4774 + ((int)((unsigned int)(v4774 - v4773) >> 31));
      v4772[v4817] = v4873;
      int * v4776 = v4700->cache_age;
      int v4777 = v4776[v4818];
      int v4875 = v4777 + ((int)((unsigned int)(v4777 - v4773) >> 31));
      v4776[v4818] = v4875;
      int * v4779 = v4700->cache_age;
      v4779[v4843] = 0;
      v4782 = v4843;
    }
    int * v4783 = v4700->cache_vals;
    int v4878 = v4782 * 2;
    int v4784 = v4783[v4878];
    int v4879 = (v4782 * 2) + 1;
    int v4785 = v4783[v4879];
    int v4880 = (((((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v4724 + ((~(((v4726 ^ -1) | (-(v4726 ^ -1))) >> 31)) & 2)) - (v4727 + ((~(((v4728 ^ -1) | (-(v4728 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4783[v4880] = v4784;
    int * v4787 = v4700->cache_vals;
    int v4883 = ((((((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v4724 + ((~(((v4726 ^ -1) | (-(v4726 ^ -1))) >> 31)) & 2)) - (v4727 + ((~(((v4728 ^ -1) | (-(v4728 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4787[v4883] = v4785;
    int * v4789 = v4700->cache_tags;
    int v4886 = ((((int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v4724 + ((~(((v4726 ^ -1) | (-(v4726 ^ -1))) >> 31)) & 2)) - (v4727 + ((~(((v4728 ^ -1) | (-(v4728 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4887 = (int)((unsigned int)((int)((unsigned int)(v4704 + 4) >> 2)) >> 1);
    v4789[v4886] = v4887;
    int * v4791 = v4700->cache_dirty;
    v4791[v4886] = 0;
    int * v4793 = v4700->cache_age;
    v4793[v4886] = 1;
    int * v4795 = v4700->cache_age;
    int v4796 = v4795[v4886];
    int v4797 = v4795[v4815];
    int v4893 = v4797 + ((int)((unsigned int)(v4797 - v4796) >> 31));
    v4795[v4815] = v4893;
    int * v4799 = v4700->cache_age;
    int v4800 = v4799[v4816];
    int v4895 = v4800 + ((int)((unsigned int)(v4800 - v4796) >> 31));
    v4799[v4816] = v4895;
    int * v4802 = v4700->cache_age;
    v4802[v4886] = 0;
    v4805 = v4886;
  }
  int v4898 = (v4805 * 2) + (((int)((unsigned int)(v4704 + 4) >> 2)) & 1);
  int v4806 = v4712[v4898];
  int * v4807 = v4700->regs;
  v4807[5] = v4806;
  struct StateT * v4809 = slot_21(v4700);
  return v4809;
}

struct StateT * slot_141(struct StateT * v11519) {
  int v11520 = v11519->timer;
  int v11527 = v11520 + 1;
  v11519->timer = v11527;
  int * v11522 = v11519->regs;
  int v11523 = v11522[21];
  int v11530 = v11523 << 9;
  v11522[21] = v11530;
  struct StateT * v11525 = slot_142(v11519);
  return v11525;
}

struct StateT * slot_61(struct StateT * v10271) {
  int v10272 = v10271->timer;
  int v10279 = v10272 + 1;
  v10271->timer = v10279;
  int * v10274 = v10271->regs;
  int v10275 = v10274[21];
  int v10282 = v10275 << 9;
  v10274[21] = v10282;
  struct StateT * v10277 = slot_62(v10271);
  return v10277;
}

struct StateT * slot_30(struct StateT * v5409) {
  int v5410 = v5409->timer;
  int v5417 = v5410 + 1;
  v5409->timer = v5417;
  int * v5412 = v5409->regs;
  int v5413 = v5412[31];
  int v5420 = v5413 + 1396;
  v5412[31] = v5420;
  struct StateT * v5415 = slot_31(v5409);
  return v5415;
}

struct StateT * slot_4(struct StateT * v961) {
  int v962 = v961->timer;
  int v1132 = v962 + 1;
  v961->timer = v1132;
  int * v964 = v961->regs;
  int v965 = v964[2];
  int v966 = v964[19];
  int * v967 = v961->cache_tags;
  int v1137 = (((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 1) * 2;
  int v968 = v967[v1137];
  int v1138 = ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 1) * 2) + 1;
  int v969 = v967[v1138];
  int v1139 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 3) * 2);
  int v970 = v967[v1139];
  int v1140 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v971 = v967[v1140];
  int v972 = v961->timer;
  int v1141 = v972 + ((100 ^ (((~(((v970 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))) | (-(v970 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v971 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))) | (-(v971 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v968 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))) | (-(v968 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v969 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))) | (-(v969 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v970 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))) | (-(v970 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v971 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))) | (-(v971 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))))) >> 31))) & 104)))));
  v961->timer = v1141;
  bool v1142 = !(((~(((v968 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))) | (-(v968 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v969 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))) | (-(v969 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v1066;
  if (v1142) {
    int * v974 = v961->cache_age;
    int v1144 = ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 1) * 2) + ((~(((v969 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))) | (-(v969 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))))) >> 31)) & 1);
    int v975 = v974[v1144];
    int v976 = v974[v1137];
    int v1145 = v976 + ((int)((unsigned int)(v976 - v975) >> 31));
    v974[v1137] = v1145;
    int * v978 = v961->cache_age;
    int v979 = v978[v1138];
    int v1147 = v979 + ((int)((unsigned int)(v979 - v975) >> 31));
    v978[v1138] = v1147;
    int * v981 = v961->cache_age;
    v981[v1144] = 0;
    v1066 = v1144;
  } else {
    int * v984 = v961->cache_age;
    int v1151 = (((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 1) * 2;
    int v985 = v984[v1151];
    int * v986 = v961->cache_tags;
    int v987 = v986[v1151];
    int v988 = v984[v1138];
    int v989 = v986[v1138];
    bool v1153 = !(((~(((v970 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))) | (-(v970 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v971 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))) | (-(v971 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))))) >> 31))) == 0);
    int v1043;
    if (v1153) {
      int * v990 = v961->cache_age;
      int v1155 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v971 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))) | (-(v971 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))))) >> 31)) & 1);
      int v991 = v990[v1155];
      int v992 = v990[v1139];
      int v1156 = v992 + ((int)((unsigned int)(v992 - v991) >> 31));
      v990[v1139] = v1156;
      int * v994 = v961->cache_age;
      int v995 = v994[v1140];
      int v1158 = v995 + ((int)((unsigned int)(v995 - v991) >> 31));
      v994[v1140] = v1158;
      int * v997 = v961->cache_age;
      v997[v1155] = 0;
      v1043 = v1155;
    } else {
      int * v1000 = v961->cache_age;
      int v1162 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 3) * 2);
      int v1001 = v1000[v1162];
      int * v1002 = v961->cache_tags;
      int v1003 = v1002[v1162];
      int v1004 = v1000[v1140];
      int v1005 = v1002[v1140];
      int * v1006 = v961->cache_dirty;
      int v1165 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v1001 + ((~(((v1003 ^ -1) | (-(v1003 ^ -1))) >> 31)) & 2)) - (v1004 + ((~(((v1005 ^ -1) | (-(v1005 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1007 = v1006[v1165];
      bool v1166 = !(v1007 == 0);
      if (v1166) {
        int * v1008 = v961->cache_tags;
        int v1009 = v1008[v1165];
        int * v1010 = v961->cache_vals;
        int v1169 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v1001 + ((~(((v1003 ^ -1) | (-(v1003 ^ -1))) >> 31)) & 2)) - (v1004 + ((~(((v1005 ^ -1) | (-(v1005 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1011 = v1010[v1169];
        int v1170 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v1001 + ((~(((v1003 ^ -1) | (-(v1003 ^ -1))) >> 31)) & 2)) - (v1004 + ((~(((v1005 ^ -1) | (-(v1005 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1012 = v1010[v1170];
        int * v1013 = v961->mem;
        int v1172 = v1009 * 2;
        v1013[v1172] = v1011;
        int * v1015 = v961->mem;
        int v1175 = (v1009 * 2) + 1;
        v1015[v1175] = v1012;
        ;
      } else {
        ;
      }
      int * v1020 = v961->mem;
      int v1180 = ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) * 2;
      int v1021 = v1020[v1180];
      int v1181 = (((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) * 2) + 1;
      int v1022 = v1020[v1181];
      int * v1023 = v961->cache_vals;
      int v1183 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v1001 + ((~(((v1003 ^ -1) | (-(v1003 ^ -1))) >> 31)) & 2)) - (v1004 + ((~(((v1005 ^ -1) | (-(v1005 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1023[v1183] = v1021;
      int * v1025 = v961->cache_vals;
      int v1186 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v1001 + ((~(((v1003 ^ -1) | (-(v1003 ^ -1))) >> 31)) & 2)) - (v1004 + ((~(((v1005 ^ -1) | (-(v1005 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1025[v1186] = v1022;
      int * v1027 = v961->cache_tags;
      int v1189 = (int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1);
      v1027[v1165] = v1189;
      int * v1029 = v961->cache_dirty;
      v1029[v1165] = 0;
      int * v1031 = v961->cache_age;
      v1031[v1165] = 1;
      int * v1033 = v961->cache_age;
      int v1034 = v1033[v1165];
      int v1035 = v1033[v1139];
      int v1195 = v1035 + ((int)((unsigned int)(v1035 - v1034) >> 31));
      v1033[v1139] = v1195;
      int * v1037 = v961->cache_age;
      int v1038 = v1037[v1140];
      int v1197 = v1038 + ((int)((unsigned int)(v1038 - v1034) >> 31));
      v1037[v1140] = v1197;
      int * v1040 = v961->cache_age;
      v1040[v1165] = 0;
      v1043 = v1165;
    }
    int * v1044 = v961->cache_vals;
    int v1200 = v1043 * 2;
    int v1045 = v1044[v1200];
    int v1201 = (v1043 * 2) + 1;
    int v1046 = v1044[v1201];
    int v1202 = (((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v985 + ((~(((v987 ^ -1) | (-(v987 ^ -1))) >> 31)) & 2)) - (v988 + ((~(((v989 ^ -1) | (-(v989 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1044[v1202] = v1045;
    int * v1048 = v961->cache_vals;
    int v1205 = ((((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v985 + ((~(((v987 ^ -1) | (-(v987 ^ -1))) >> 31)) & 2)) - (v988 + ((~(((v989 ^ -1) | (-(v989 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1048[v1205] = v1046;
    int * v1050 = v961->cache_tags;
    int v1208 = ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v985 + ((~(((v987 ^ -1) | (-(v987 ^ -1))) >> 31)) & 2)) - (v988 + ((~(((v989 ^ -1) | (-(v989 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1209 = (int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1);
    v1050[v1208] = v1209;
    int * v1052 = v961->cache_dirty;
    v1052[v1208] = 0;
    int * v1054 = v961->cache_age;
    v1054[v1208] = 1;
    int * v1056 = v961->cache_age;
    int v1057 = v1056[v1208];
    int v1058 = v1056[v1137];
    int v1215 = v1058 + ((int)((unsigned int)(v1058 - v1057) >> 31));
    v1056[v1137] = v1215;
    int * v1060 = v961->cache_age;
    int v1061 = v1060[v1138];
    int v1217 = v1061 + ((int)((unsigned int)(v1061 - v1057) >> 31));
    v1060[v1138] = v1217;
    int * v1063 = v961->cache_age;
    v1063[v1208] = 0;
    v1066 = v1208;
  }
  int * v1067 = v961->cache_vals;
  int v1220 = (v1066 * 2) + (((int)((unsigned int)(v965 + 32) >> 2)) & 1);
  v1067[v1220] = v966;
  int * v1069 = v961->cache_tags;
  int v1070 = v1069[v1139];
  int v1071 = v1069[v1140];
  bool v1223 = !(((~(((v1070 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))) | (-(v1070 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v1071 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))) | (-(v1071 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v1125;
  if (v1223) {
    int * v1072 = v961->cache_age;
    int v1225 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1071 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))) | (-(v1071 ^ ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1))))) >> 31)) & 1);
    int v1073 = v1072[v1225];
    int v1074 = v1072[v1139];
    int v1226 = v1074 + ((int)((unsigned int)(v1074 - v1073) >> 31));
    v1072[v1139] = v1226;
    int * v1076 = v961->cache_age;
    int v1077 = v1076[v1140];
    int v1228 = v1077 + ((int)((unsigned int)(v1077 - v1073) >> 31));
    v1076[v1140] = v1228;
    int * v1079 = v961->cache_age;
    v1079[v1225] = 0;
    v1125 = v1225;
  } else {
    int * v1082 = v961->cache_age;
    int v1232 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 3) * 2);
    int v1083 = v1082[v1232];
    int * v1084 = v961->cache_tags;
    int v1085 = v1084[v1232];
    int v1086 = v1082[v1140];
    int v1087 = v1084[v1140];
    int * v1088 = v961->cache_dirty;
    int v1235 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v1083 + ((~(((v1085 ^ -1) | (-(v1085 ^ -1))) >> 31)) & 2)) - (v1086 + ((~(((v1087 ^ -1) | (-(v1087 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1089 = v1088[v1235];
    bool v1236 = !(v1089 == 0);
    if (v1236) {
      int * v1090 = v961->cache_tags;
      int v1091 = v1090[v1235];
      int * v1092 = v961->cache_vals;
      int v1239 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v1083 + ((~(((v1085 ^ -1) | (-(v1085 ^ -1))) >> 31)) & 2)) - (v1086 + ((~(((v1087 ^ -1) | (-(v1087 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1093 = v1092[v1239];
      int v1240 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v1083 + ((~(((v1085 ^ -1) | (-(v1085 ^ -1))) >> 31)) & 2)) - (v1086 + ((~(((v1087 ^ -1) | (-(v1087 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1094 = v1092[v1240];
      int * v1095 = v961->mem;
      int v1242 = v1091 * 2;
      v1095[v1242] = v1093;
      int * v1097 = v961->mem;
      int v1245 = (v1091 * 2) + 1;
      v1097[v1245] = v1094;
      ;
    } else {
      ;
    }
    int * v1102 = v961->mem;
    int v1250 = ((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) * 2;
    int v1103 = v1102[v1250];
    int v1251 = (((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) * 2) + 1;
    int v1104 = v1102[v1251];
    int * v1105 = v961->cache_vals;
    int v1253 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v1083 + ((~(((v1085 ^ -1) | (-(v1085 ^ -1))) >> 31)) & 2)) - (v1086 + ((~(((v1087 ^ -1) | (-(v1087 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1105[v1253] = v1103;
    int * v1107 = v961->cache_vals;
    int v1256 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v1083 + ((~(((v1085 ^ -1) | (-(v1085 ^ -1))) >> 31)) & 2)) - (v1086 + ((~(((v1087 ^ -1) | (-(v1087 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1107[v1256] = v1104;
    int * v1109 = v961->cache_tags;
    int v1259 = (int)((unsigned int)((int)((unsigned int)(v965 + 32) >> 2)) >> 1);
    v1109[v1235] = v1259;
    int * v1111 = v961->cache_dirty;
    v1111[v1235] = 0;
    int * v1113 = v961->cache_age;
    v1113[v1235] = 1;
    int * v1115 = v961->cache_age;
    int v1116 = v1115[v1235];
    int v1117 = v1115[v1139];
    int v1265 = v1117 + ((int)((unsigned int)(v1117 - v1116) >> 31));
    v1115[v1139] = v1265;
    int * v1119 = v961->cache_age;
    int v1120 = v1119[v1140];
    int v1267 = v1120 + ((int)((unsigned int)(v1120 - v1116) >> 31));
    v1119[v1140] = v1267;
    int * v1122 = v961->cache_age;
    v1122[v1235] = 0;
    v1125 = v1235;
  }
  int * v1126 = v961->cache_vals;
  int v1270 = (v1125 * 2) + (((int)((unsigned int)(v965 + 32) >> 2)) & 1);
  v1126[v1270] = v966;
  int * v1128 = v961->cache_dirty;
  v1128[v1125] = 1;
  struct StateT * v1130 = slot_5(v961);
  return v1130;
}

struct StateT * slot_18(struct StateT * v4292) {
  int v4293 = v4292->timer;
  int v4403 = v4293 + 1;
  v4292->timer = v4403;
  int * v4295 = v4292->regs;
  int v4296 = v4295[12];
  int * v4297 = v4292->cache_tags;
  int v4407 = (((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1)) & 1) * 2;
  int v4298 = v4297[v4407];
  int v4408 = ((((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1)) & 1) * 2) + 1;
  int v4299 = v4297[v4408];
  int v4409 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1)) & 3) * 2);
  int v4300 = v4297[v4409];
  int v4410 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v4301 = v4297[v4410];
  int v4302 = v4292->timer;
  int v4411 = v4302 + ((100 ^ (((~(((v4300 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))) | (-(v4300 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v4301 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))) | (-(v4301 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v4298 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))) | (-(v4298 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v4299 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))) | (-(v4299 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v4300 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))) | (-(v4300 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v4301 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))) | (-(v4301 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))))) >> 31))) & 104)))));
  v4292->timer = v4411;
  int * v4304 = v4292->cache_vals;
  bool v4412 = !(((~(((v4298 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))) | (-(v4298 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v4299 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))) | (-(v4299 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v4397;
  if (v4412) {
    int * v4305 = v4292->cache_age;
    int v4414 = ((((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1)) & 1) * 2) + ((~(((v4299 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))) | (-(v4299 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v4306 = v4305[v4414];
    int v4307 = v4305[v4407];
    int v4415 = v4307 + ((int)((unsigned int)(v4307 - v4306) >> 31));
    v4305[v4407] = v4415;
    int * v4309 = v4292->cache_age;
    int v4310 = v4309[v4408];
    int v4417 = v4310 + ((int)((unsigned int)(v4310 - v4306) >> 31));
    v4309[v4408] = v4417;
    int * v4312 = v4292->cache_age;
    v4312[v4414] = 0;
    v4397 = v4414;
  } else {
    int * v4315 = v4292->cache_age;
    int v4421 = (((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1)) & 1) * 2;
    int v4316 = v4315[v4421];
    int * v4317 = v4292->cache_tags;
    int v4318 = v4317[v4421];
    int v4319 = v4315[v4408];
    int v4320 = v4317[v4408];
    bool v4423 = !(((~(((v4300 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))) | (-(v4300 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v4301 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))) | (-(v4301 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))))) >> 31))) == 0);
    int v4374;
    if (v4423) {
      int * v4321 = v4292->cache_age;
      int v4425 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v4301 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))) | (-(v4301 ^ ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1))))) >> 31)) & 1);
      int v4322 = v4321[v4425];
      int v4323 = v4321[v4409];
      int v4426 = v4323 + ((int)((unsigned int)(v4323 - v4322) >> 31));
      v4321[v4409] = v4426;
      int * v4325 = v4292->cache_age;
      int v4326 = v4325[v4410];
      int v4428 = v4326 + ((int)((unsigned int)(v4326 - v4322) >> 31));
      v4325[v4410] = v4428;
      int * v4328 = v4292->cache_age;
      v4328[v4425] = 0;
      v4374 = v4425;
    } else {
      int * v4331 = v4292->cache_age;
      int v4432 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1)) & 3) * 2);
      int v4332 = v4331[v4432];
      int * v4333 = v4292->cache_tags;
      int v4334 = v4333[v4432];
      int v4335 = v4331[v4410];
      int v4336 = v4333[v4410];
      int * v4337 = v4292->cache_dirty;
      int v4435 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v4332 + ((~(((v4334 ^ -1) | (-(v4334 ^ -1))) >> 31)) & 2)) - (v4335 + ((~(((v4336 ^ -1) | (-(v4336 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v4338 = v4337[v4435];
      bool v4436 = !(v4338 == 0);
      if (v4436) {
        int * v4339 = v4292->cache_tags;
        int v4340 = v4339[v4435];
        int * v4341 = v4292->cache_vals;
        int v4439 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v4332 + ((~(((v4334 ^ -1) | (-(v4334 ^ -1))) >> 31)) & 2)) - (v4335 + ((~(((v4336 ^ -1) | (-(v4336 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v4342 = v4341[v4439];
        int v4440 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v4332 + ((~(((v4334 ^ -1) | (-(v4334 ^ -1))) >> 31)) & 2)) - (v4335 + ((~(((v4336 ^ -1) | (-(v4336 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v4343 = v4341[v4440];
        int * v4344 = v4292->mem;
        int v4442 = v4340 * 2;
        v4344[v4442] = v4342;
        int * v4346 = v4292->mem;
        int v4445 = (v4340 * 2) + 1;
        v4346[v4445] = v4343;
        ;
      } else {
        ;
      }
      int * v4351 = v4292->mem;
      int v4450 = ((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1)) * 2;
      int v4352 = v4351[v4450];
      int v4451 = (((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1)) * 2) + 1;
      int v4353 = v4351[v4451];
      int * v4354 = v4292->cache_vals;
      int v4453 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v4332 + ((~(((v4334 ^ -1) | (-(v4334 ^ -1))) >> 31)) & 2)) - (v4335 + ((~(((v4336 ^ -1) | (-(v4336 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v4354[v4453] = v4352;
      int * v4356 = v4292->cache_vals;
      int v4456 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v4332 + ((~(((v4334 ^ -1) | (-(v4334 ^ -1))) >> 31)) & 2)) - (v4335 + ((~(((v4336 ^ -1) | (-(v4336 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v4356[v4456] = v4353;
      int * v4358 = v4292->cache_tags;
      int v4459 = (int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1);
      v4358[v4435] = v4459;
      int * v4360 = v4292->cache_dirty;
      v4360[v4435] = 0;
      int * v4362 = v4292->cache_age;
      v4362[v4435] = 1;
      int * v4364 = v4292->cache_age;
      int v4365 = v4364[v4435];
      int v4366 = v4364[v4409];
      int v4465 = v4366 + ((int)((unsigned int)(v4366 - v4365) >> 31));
      v4364[v4409] = v4465;
      int * v4368 = v4292->cache_age;
      int v4369 = v4368[v4410];
      int v4467 = v4369 + ((int)((unsigned int)(v4369 - v4365) >> 31));
      v4368[v4410] = v4467;
      int * v4371 = v4292->cache_age;
      v4371[v4435] = 0;
      v4374 = v4435;
    }
    int * v4375 = v4292->cache_vals;
    int v4470 = v4374 * 2;
    int v4376 = v4375[v4470];
    int v4471 = (v4374 * 2) + 1;
    int v4377 = v4375[v4471];
    int v4472 = (((((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v4316 + ((~(((v4318 ^ -1) | (-(v4318 ^ -1))) >> 31)) & 2)) - (v4319 + ((~(((v4320 ^ -1) | (-(v4320 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v4375[v4472] = v4376;
    int * v4379 = v4292->cache_vals;
    int v4475 = ((((((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v4316 + ((~(((v4318 ^ -1) | (-(v4318 ^ -1))) >> 31)) & 2)) - (v4319 + ((~(((v4320 ^ -1) | (-(v4320 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v4379[v4475] = v4377;
    int * v4381 = v4292->cache_tags;
    int v4478 = ((((int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v4316 + ((~(((v4318 ^ -1) | (-(v4318 ^ -1))) >> 31)) & 2)) - (v4319 + ((~(((v4320 ^ -1) | (-(v4320 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v4479 = (int)((unsigned int)((int)((unsigned int)(v4296 + 28) >> 2)) >> 1);
    v4381[v4478] = v4479;
    int * v4383 = v4292->cache_dirty;
    v4383[v4478] = 0;
    int * v4385 = v4292->cache_age;
    v4385[v4478] = 1;
    int * v4387 = v4292->cache_age;
    int v4388 = v4387[v4478];
    int v4389 = v4387[v4407];
    int v4485 = v4389 + ((int)((unsigned int)(v4389 - v4388) >> 31));
    v4387[v4407] = v4485;
    int * v4391 = v4292->cache_age;
    int v4392 = v4391[v4408];
    int v4487 = v4392 + ((int)((unsigned int)(v4392 - v4388) >> 31));
    v4391[v4408] = v4487;
    int * v4394 = v4292->cache_age;
    v4394[v4478] = 0;
    v4397 = v4478;
  }
  int v4490 = (v4397 * 2) + (((int)((unsigned int)(v4296 + 28) >> 2)) & 1);
  int v4398 = v4304[v4490];
  int * v4399 = v4292->regs;
  v4399[19] = v4398;
  struct StateT * v4401 = slot_19(v4292);
  return v4401;
}

struct StateT * slot_9(struct StateT * v2536) {
  int v2537 = v2536->timer;
  int v2707 = v2537 + 1;
  v2536->timer = v2707;
  int * v2539 = v2536->regs;
  int v2540 = v2539[2];
  int v2541 = v2539[24];
  int * v2542 = v2536->cache_tags;
  int v2712 = (((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 1) * 2;
  int v2543 = v2542[v2712];
  int v2713 = ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2544 = v2542[v2713];
  int v2714 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2);
  int v2545 = v2542[v2714];
  int v2715 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2546 = v2542[v2715];
  int v2547 = v2536->timer;
  int v2716 = v2547 + ((100 ^ (((~(((v2545 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2545 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2546 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2546 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2543 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2543 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2544 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2544 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2545 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2545 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2546 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2546 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2536->timer = v2716;
  bool v2717 = !(((~(((v2543 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2543 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2544 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2544 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v2641;
  if (v2717) {
    int * v2549 = v2536->cache_age;
    int v2719 = ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v2544 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2544 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v2550 = v2549[v2719];
    int v2551 = v2549[v2712];
    int v2720 = v2551 + ((int)((unsigned int)(v2551 - v2550) >> 31));
    v2549[v2712] = v2720;
    int * v2553 = v2536->cache_age;
    int v2554 = v2553[v2713];
    int v2722 = v2554 + ((int)((unsigned int)(v2554 - v2550) >> 31));
    v2553[v2713] = v2722;
    int * v2556 = v2536->cache_age;
    v2556[v2719] = 0;
    v2641 = v2719;
  } else {
    int * v2559 = v2536->cache_age;
    int v2726 = (((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 1) * 2;
    int v2560 = v2559[v2726];
    int * v2561 = v2536->cache_tags;
    int v2562 = v2561[v2726];
    int v2563 = v2559[v2713];
    int v2564 = v2561[v2713];
    bool v2728 = !(((~(((v2545 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2545 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2546 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2546 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v2618;
    if (v2728) {
      int * v2565 = v2536->cache_age;
      int v2730 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2546 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2546 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v2566 = v2565[v2730];
      int v2567 = v2565[v2714];
      int v2731 = v2567 + ((int)((unsigned int)(v2567 - v2566) >> 31));
      v2565[v2714] = v2731;
      int * v2569 = v2536->cache_age;
      int v2570 = v2569[v2715];
      int v2733 = v2570 + ((int)((unsigned int)(v2570 - v2566) >> 31));
      v2569[v2715] = v2733;
      int * v2572 = v2536->cache_age;
      v2572[v2730] = 0;
      v2618 = v2730;
    } else {
      int * v2575 = v2536->cache_age;
      int v2737 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2);
      int v2576 = v2575[v2737];
      int * v2577 = v2536->cache_tags;
      int v2578 = v2577[v2737];
      int v2579 = v2575[v2715];
      int v2580 = v2577[v2715];
      int * v2581 = v2536->cache_dirty;
      int v2740 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2576 + ((~(((v2578 ^ -1) | (-(v2578 ^ -1))) >> 31)) & 2)) - (v2579 + ((~(((v2580 ^ -1) | (-(v2580 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2582 = v2581[v2740];
      bool v2741 = !(v2582 == 0);
      if (v2741) {
        int * v2583 = v2536->cache_tags;
        int v2584 = v2583[v2740];
        int * v2585 = v2536->cache_vals;
        int v2744 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2576 + ((~(((v2578 ^ -1) | (-(v2578 ^ -1))) >> 31)) & 2)) - (v2579 + ((~(((v2580 ^ -1) | (-(v2580 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2586 = v2585[v2744];
        int v2745 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2576 + ((~(((v2578 ^ -1) | (-(v2578 ^ -1))) >> 31)) & 2)) - (v2579 + ((~(((v2580 ^ -1) | (-(v2580 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2587 = v2585[v2745];
        int * v2588 = v2536->mem;
        int v2747 = v2584 * 2;
        v2588[v2747] = v2586;
        int * v2590 = v2536->mem;
        int v2750 = (v2584 * 2) + 1;
        v2590[v2750] = v2587;
        ;
      } else {
        ;
      }
      int * v2595 = v2536->mem;
      int v2755 = ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) * 2;
      int v2596 = v2595[v2755];
      int v2756 = (((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) * 2) + 1;
      int v2597 = v2595[v2756];
      int * v2598 = v2536->cache_vals;
      int v2758 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2576 + ((~(((v2578 ^ -1) | (-(v2578 ^ -1))) >> 31)) & 2)) - (v2579 + ((~(((v2580 ^ -1) | (-(v2580 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2598[v2758] = v2596;
      int * v2600 = v2536->cache_vals;
      int v2761 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2576 + ((~(((v2578 ^ -1) | (-(v2578 ^ -1))) >> 31)) & 2)) - (v2579 + ((~(((v2580 ^ -1) | (-(v2580 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2600[v2761] = v2597;
      int * v2602 = v2536->cache_tags;
      int v2764 = (int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1);
      v2602[v2740] = v2764;
      int * v2604 = v2536->cache_dirty;
      v2604[v2740] = 0;
      int * v2606 = v2536->cache_age;
      v2606[v2740] = 1;
      int * v2608 = v2536->cache_age;
      int v2609 = v2608[v2740];
      int v2610 = v2608[v2714];
      int v2770 = v2610 + ((int)((unsigned int)(v2610 - v2609) >> 31));
      v2608[v2714] = v2770;
      int * v2612 = v2536->cache_age;
      int v2613 = v2612[v2715];
      int v2772 = v2613 + ((int)((unsigned int)(v2613 - v2609) >> 31));
      v2612[v2715] = v2772;
      int * v2615 = v2536->cache_age;
      v2615[v2740] = 0;
      v2618 = v2740;
    }
    int * v2619 = v2536->cache_vals;
    int v2775 = v2618 * 2;
    int v2620 = v2619[v2775];
    int v2776 = (v2618 * 2) + 1;
    int v2621 = v2619[v2776];
    int v2777 = (((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v2560 + ((~(((v2562 ^ -1) | (-(v2562 ^ -1))) >> 31)) & 2)) - (v2563 + ((~(((v2564 ^ -1) | (-(v2564 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2619[v2777] = v2620;
    int * v2623 = v2536->cache_vals;
    int v2780 = ((((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v2560 + ((~(((v2562 ^ -1) | (-(v2562 ^ -1))) >> 31)) & 2)) - (v2563 + ((~(((v2564 ^ -1) | (-(v2564 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2623[v2780] = v2621;
    int * v2625 = v2536->cache_tags;
    int v2783 = ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v2560 + ((~(((v2562 ^ -1) | (-(v2562 ^ -1))) >> 31)) & 2)) - (v2563 + ((~(((v2564 ^ -1) | (-(v2564 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2784 = (int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1);
    v2625[v2783] = v2784;
    int * v2627 = v2536->cache_dirty;
    v2627[v2783] = 0;
    int * v2629 = v2536->cache_age;
    v2629[v2783] = 1;
    int * v2631 = v2536->cache_age;
    int v2632 = v2631[v2783];
    int v2633 = v2631[v2712];
    int v2790 = v2633 + ((int)((unsigned int)(v2633 - v2632) >> 31));
    v2631[v2712] = v2790;
    int * v2635 = v2536->cache_age;
    int v2636 = v2635[v2713];
    int v2792 = v2636 + ((int)((unsigned int)(v2636 - v2632) >> 31));
    v2635[v2713] = v2792;
    int * v2638 = v2536->cache_age;
    v2638[v2783] = 0;
    v2641 = v2783;
  }
  int * v2642 = v2536->cache_vals;
  int v2795 = (v2641 * 2) + (((int)((unsigned int)(v2540 + 12) >> 2)) & 1);
  v2642[v2795] = v2541;
  int * v2644 = v2536->cache_tags;
  int v2645 = v2644[v2714];
  int v2646 = v2644[v2715];
  bool v2798 = !(((~(((v2645 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2645 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v2646 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2646 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v2700;
  if (v2798) {
    int * v2647 = v2536->cache_age;
    int v2800 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2646 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))) | (-(v2646 ^ ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v2648 = v2647[v2800];
    int v2649 = v2647[v2714];
    int v2801 = v2649 + ((int)((unsigned int)(v2649 - v2648) >> 31));
    v2647[v2714] = v2801;
    int * v2651 = v2536->cache_age;
    int v2652 = v2651[v2715];
    int v2803 = v2652 + ((int)((unsigned int)(v2652 - v2648) >> 31));
    v2651[v2715] = v2803;
    int * v2654 = v2536->cache_age;
    v2654[v2800] = 0;
    v2700 = v2800;
  } else {
    int * v2657 = v2536->cache_age;
    int v2807 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2);
    int v2658 = v2657[v2807];
    int * v2659 = v2536->cache_tags;
    int v2660 = v2659[v2807];
    int v2661 = v2657[v2715];
    int v2662 = v2659[v2715];
    int * v2663 = v2536->cache_dirty;
    int v2810 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2658 + ((~(((v2660 ^ -1) | (-(v2660 ^ -1))) >> 31)) & 2)) - (v2661 + ((~(((v2662 ^ -1) | (-(v2662 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2664 = v2663[v2810];
    bool v2811 = !(v2664 == 0);
    if (v2811) {
      int * v2665 = v2536->cache_tags;
      int v2666 = v2665[v2810];
      int * v2667 = v2536->cache_vals;
      int v2814 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2658 + ((~(((v2660 ^ -1) | (-(v2660 ^ -1))) >> 31)) & 2)) - (v2661 + ((~(((v2662 ^ -1) | (-(v2662 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v2668 = v2667[v2814];
      int v2815 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2658 + ((~(((v2660 ^ -1) | (-(v2660 ^ -1))) >> 31)) & 2)) - (v2661 + ((~(((v2662 ^ -1) | (-(v2662 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v2669 = v2667[v2815];
      int * v2670 = v2536->mem;
      int v2817 = v2666 * 2;
      v2670[v2817] = v2668;
      int * v2672 = v2536->mem;
      int v2820 = (v2666 * 2) + 1;
      v2672[v2820] = v2669;
      ;
    } else {
      ;
    }
    int * v2677 = v2536->mem;
    int v2825 = ((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) * 2;
    int v2678 = v2677[v2825];
    int v2826 = (((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) * 2) + 1;
    int v2679 = v2677[v2826];
    int * v2680 = v2536->cache_vals;
    int v2828 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2658 + ((~(((v2660 ^ -1) | (-(v2660 ^ -1))) >> 31)) & 2)) - (v2661 + ((~(((v2662 ^ -1) | (-(v2662 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2680[v2828] = v2678;
    int * v2682 = v2536->cache_vals;
    int v2831 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v2658 + ((~(((v2660 ^ -1) | (-(v2660 ^ -1))) >> 31)) & 2)) - (v2661 + ((~(((v2662 ^ -1) | (-(v2662 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2682[v2831] = v2679;
    int * v2684 = v2536->cache_tags;
    int v2834 = (int)((unsigned int)((int)((unsigned int)(v2540 + 12) >> 2)) >> 1);
    v2684[v2810] = v2834;
    int * v2686 = v2536->cache_dirty;
    v2686[v2810] = 0;
    int * v2688 = v2536->cache_age;
    v2688[v2810] = 1;
    int * v2690 = v2536->cache_age;
    int v2691 = v2690[v2810];
    int v2692 = v2690[v2714];
    int v2840 = v2692 + ((int)((unsigned int)(v2692 - v2691) >> 31));
    v2690[v2714] = v2840;
    int * v2694 = v2536->cache_age;
    int v2695 = v2694[v2715];
    int v2842 = v2695 + ((int)((unsigned int)(v2695 - v2691) >> 31));
    v2694[v2715] = v2842;
    int * v2697 = v2536->cache_age;
    v2697[v2810] = 0;
    v2700 = v2810;
  }
  int * v2701 = v2536->cache_vals;
  int v2845 = (v2700 * 2) + (((int)((unsigned int)(v2540 + 12) >> 2)) & 1);
  v2701[v2845] = v2541;
  int * v2703 = v2536->cache_dirty;
  v2703[v2700] = 1;
  struct StateT * v2705 = slot_10(v2536);
  return v2705;
}

struct StateT * slot_183(struct StateT * v12173) {
  int v12174 = v12173->timer;
  int v12181 = v12174 + 1;
  v12173->timer = v12181;
  int * v12176 = v12173->regs;
  int v12177 = v12176[22];
  int v12185 = (int)((unsigned int)v12177 >> 14);
  v12176[24] = v12185;
  struct StateT * v12179 = slot_184(v12173);
  return v12179;
}

struct StateT * slot_43(struct StateT * v8746) {
  int v8747 = v8746->timer;
  int v8754 = v8747 + 1;
  v8746->timer = v8754;
  int * v8749 = v8746->regs;
  int v8750 = v8749[22];
  int v8758 = (int)((unsigned int)v8750 >> 25);
  v8749[24] = v8758;
  struct StateT * v8752 = slot_44(v8746);
  return v8752;
}

struct StateT * slot_70(struct StateT * v10407) {
  int v10408 = v10407->timer;
  int v10416 = v10408 + 1;
  v10407->timer = v10416;
  int * v10410 = v10407->regs;
  int v10411 = v10410[7];
  int v10412 = v10410[21];
  int v10420 = v10411 ^ v10412;
  v10410[7] = v10420;
  struct StateT * v10414 = slot_71(v10407);
  return v10414;
}

struct StateT * slot_168(struct StateT * v11935) {
  int v11936 = v11935->timer;
  int v11944 = v11936 + 1;
  v11935->timer = v11944;
  int * v11938 = v11935->regs;
  int v11939 = v11938[23];
  int v11940 = v11938[24];
  int v11948 = v11939 | v11940;
  v11938[23] = v11948;
  struct StateT * v11942 = slot_169(v11935);
  return v11942;
}

struct StateT * slot_76(struct StateT * v10506) {
  int v10507 = v10506->timer;
  int v10515 = v10507 + 1;
  v10506->timer = v10515;
  int * v10509 = v10506->regs;
  int v10510 = v10509[5];
  int v10511 = v10509[8];
  int v10520 = v10510 + v10511;
  v10509[23] = v10520;
  struct StateT * v10513 = slot_77(v10506);
  return v10513;
}

struct StateT * slot_6(struct StateT * v1591) {
  int v1592 = v1591->timer;
  int v1762 = v1592 + 1;
  v1591->timer = v1762;
  int * v1594 = v1591->regs;
  int v1595 = v1594[2];
  int v1596 = v1594[21];
  int * v1597 = v1591->cache_tags;
  int v1767 = (((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 1) * 2;
  int v1598 = v1597[v1767];
  int v1768 = ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1599 = v1597[v1768];
  int v1769 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 3) * 2);
  int v1600 = v1597[v1769];
  int v1770 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1601 = v1597[v1770];
  int v1602 = v1591->timer;
  int v1771 = v1602 + ((100 ^ (((~(((v1600 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))) | (-(v1600 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v1601 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))) | (-(v1601 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1598 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))) | (-(v1598 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v1599 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))) | (-(v1599 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1600 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))) | (-(v1600 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v1601 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))) | (-(v1601 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1591->timer = v1771;
  bool v1772 = !(((~(((v1598 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))) | (-(v1598 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v1599 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))) | (-(v1599 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v1696;
  if (v1772) {
    int * v1604 = v1591->cache_age;
    int v1774 = ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 1) * 2) + ((~(((v1599 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))) | (-(v1599 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v1605 = v1604[v1774];
    int v1606 = v1604[v1767];
    int v1775 = v1606 + ((int)((unsigned int)(v1606 - v1605) >> 31));
    v1604[v1767] = v1775;
    int * v1608 = v1591->cache_age;
    int v1609 = v1608[v1768];
    int v1777 = v1609 + ((int)((unsigned int)(v1609 - v1605) >> 31));
    v1608[v1768] = v1777;
    int * v1611 = v1591->cache_age;
    v1611[v1774] = 0;
    v1696 = v1774;
  } else {
    int * v1614 = v1591->cache_age;
    int v1781 = (((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 1) * 2;
    int v1615 = v1614[v1781];
    int * v1616 = v1591->cache_tags;
    int v1617 = v1616[v1781];
    int v1618 = v1614[v1768];
    int v1619 = v1616[v1768];
    bool v1783 = !(((~(((v1600 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))) | (-(v1600 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v1601 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))) | (-(v1601 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))))) >> 31))) == 0);
    int v1673;
    if (v1783) {
      int * v1620 = v1591->cache_age;
      int v1785 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1601 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))) | (-(v1601 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))))) >> 31)) & 1);
      int v1621 = v1620[v1785];
      int v1622 = v1620[v1769];
      int v1786 = v1622 + ((int)((unsigned int)(v1622 - v1621) >> 31));
      v1620[v1769] = v1786;
      int * v1624 = v1591->cache_age;
      int v1625 = v1624[v1770];
      int v1788 = v1625 + ((int)((unsigned int)(v1625 - v1621) >> 31));
      v1624[v1770] = v1788;
      int * v1627 = v1591->cache_age;
      v1627[v1785] = 0;
      v1673 = v1785;
    } else {
      int * v1630 = v1591->cache_age;
      int v1792 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 3) * 2);
      int v1631 = v1630[v1792];
      int * v1632 = v1591->cache_tags;
      int v1633 = v1632[v1792];
      int v1634 = v1630[v1770];
      int v1635 = v1632[v1770];
      int * v1636 = v1591->cache_dirty;
      int v1795 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v1631 + ((~(((v1633 ^ -1) | (-(v1633 ^ -1))) >> 31)) & 2)) - (v1634 + ((~(((v1635 ^ -1) | (-(v1635 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1637 = v1636[v1795];
      bool v1796 = !(v1637 == 0);
      if (v1796) {
        int * v1638 = v1591->cache_tags;
        int v1639 = v1638[v1795];
        int * v1640 = v1591->cache_vals;
        int v1799 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v1631 + ((~(((v1633 ^ -1) | (-(v1633 ^ -1))) >> 31)) & 2)) - (v1634 + ((~(((v1635 ^ -1) | (-(v1635 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1641 = v1640[v1799];
        int v1800 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v1631 + ((~(((v1633 ^ -1) | (-(v1633 ^ -1))) >> 31)) & 2)) - (v1634 + ((~(((v1635 ^ -1) | (-(v1635 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1642 = v1640[v1800];
        int * v1643 = v1591->mem;
        int v1802 = v1639 * 2;
        v1643[v1802] = v1641;
        int * v1645 = v1591->mem;
        int v1805 = (v1639 * 2) + 1;
        v1645[v1805] = v1642;
        ;
      } else {
        ;
      }
      int * v1650 = v1591->mem;
      int v1810 = ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) * 2;
      int v1651 = v1650[v1810];
      int v1811 = (((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) * 2) + 1;
      int v1652 = v1650[v1811];
      int * v1653 = v1591->cache_vals;
      int v1813 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v1631 + ((~(((v1633 ^ -1) | (-(v1633 ^ -1))) >> 31)) & 2)) - (v1634 + ((~(((v1635 ^ -1) | (-(v1635 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1653[v1813] = v1651;
      int * v1655 = v1591->cache_vals;
      int v1816 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v1631 + ((~(((v1633 ^ -1) | (-(v1633 ^ -1))) >> 31)) & 2)) - (v1634 + ((~(((v1635 ^ -1) | (-(v1635 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1655[v1816] = v1652;
      int * v1657 = v1591->cache_tags;
      int v1819 = (int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1);
      v1657[v1795] = v1819;
      int * v1659 = v1591->cache_dirty;
      v1659[v1795] = 0;
      int * v1661 = v1591->cache_age;
      v1661[v1795] = 1;
      int * v1663 = v1591->cache_age;
      int v1664 = v1663[v1795];
      int v1665 = v1663[v1769];
      int v1825 = v1665 + ((int)((unsigned int)(v1665 - v1664) >> 31));
      v1663[v1769] = v1825;
      int * v1667 = v1591->cache_age;
      int v1668 = v1667[v1770];
      int v1827 = v1668 + ((int)((unsigned int)(v1668 - v1664) >> 31));
      v1667[v1770] = v1827;
      int * v1670 = v1591->cache_age;
      v1670[v1795] = 0;
      v1673 = v1795;
    }
    int * v1674 = v1591->cache_vals;
    int v1830 = v1673 * 2;
    int v1675 = v1674[v1830];
    int v1831 = (v1673 * 2) + 1;
    int v1676 = v1674[v1831];
    int v1832 = (((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v1615 + ((~(((v1617 ^ -1) | (-(v1617 ^ -1))) >> 31)) & 2)) - (v1618 + ((~(((v1619 ^ -1) | (-(v1619 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1674[v1832] = v1675;
    int * v1678 = v1591->cache_vals;
    int v1835 = ((((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v1615 + ((~(((v1617 ^ -1) | (-(v1617 ^ -1))) >> 31)) & 2)) - (v1618 + ((~(((v1619 ^ -1) | (-(v1619 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1678[v1835] = v1676;
    int * v1680 = v1591->cache_tags;
    int v1838 = ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v1615 + ((~(((v1617 ^ -1) | (-(v1617 ^ -1))) >> 31)) & 2)) - (v1618 + ((~(((v1619 ^ -1) | (-(v1619 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1839 = (int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1);
    v1680[v1838] = v1839;
    int * v1682 = v1591->cache_dirty;
    v1682[v1838] = 0;
    int * v1684 = v1591->cache_age;
    v1684[v1838] = 1;
    int * v1686 = v1591->cache_age;
    int v1687 = v1686[v1838];
    int v1688 = v1686[v1767];
    int v1845 = v1688 + ((int)((unsigned int)(v1688 - v1687) >> 31));
    v1686[v1767] = v1845;
    int * v1690 = v1591->cache_age;
    int v1691 = v1690[v1768];
    int v1847 = v1691 + ((int)((unsigned int)(v1691 - v1687) >> 31));
    v1690[v1768] = v1847;
    int * v1693 = v1591->cache_age;
    v1693[v1838] = 0;
    v1696 = v1838;
  }
  int * v1697 = v1591->cache_vals;
  int v1850 = (v1696 * 2) + (((int)((unsigned int)(v1595 + 24) >> 2)) & 1);
  v1697[v1850] = v1596;
  int * v1699 = v1591->cache_tags;
  int v1700 = v1699[v1769];
  int v1701 = v1699[v1770];
  bool v1853 = !(((~(((v1700 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))) | (-(v1700 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v1701 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))) | (-(v1701 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v1755;
  if (v1853) {
    int * v1702 = v1591->cache_age;
    int v1855 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1701 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))) | (-(v1701 ^ ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v1703 = v1702[v1855];
    int v1704 = v1702[v1769];
    int v1856 = v1704 + ((int)((unsigned int)(v1704 - v1703) >> 31));
    v1702[v1769] = v1856;
    int * v1706 = v1591->cache_age;
    int v1707 = v1706[v1770];
    int v1858 = v1707 + ((int)((unsigned int)(v1707 - v1703) >> 31));
    v1706[v1770] = v1858;
    int * v1709 = v1591->cache_age;
    v1709[v1855] = 0;
    v1755 = v1855;
  } else {
    int * v1712 = v1591->cache_age;
    int v1862 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 3) * 2);
    int v1713 = v1712[v1862];
    int * v1714 = v1591->cache_tags;
    int v1715 = v1714[v1862];
    int v1716 = v1712[v1770];
    int v1717 = v1714[v1770];
    int * v1718 = v1591->cache_dirty;
    int v1865 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v1713 + ((~(((v1715 ^ -1) | (-(v1715 ^ -1))) >> 31)) & 2)) - (v1716 + ((~(((v1717 ^ -1) | (-(v1717 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1719 = v1718[v1865];
    bool v1866 = !(v1719 == 0);
    if (v1866) {
      int * v1720 = v1591->cache_tags;
      int v1721 = v1720[v1865];
      int * v1722 = v1591->cache_vals;
      int v1869 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v1713 + ((~(((v1715 ^ -1) | (-(v1715 ^ -1))) >> 31)) & 2)) - (v1716 + ((~(((v1717 ^ -1) | (-(v1717 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1723 = v1722[v1869];
      int v1870 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v1713 + ((~(((v1715 ^ -1) | (-(v1715 ^ -1))) >> 31)) & 2)) - (v1716 + ((~(((v1717 ^ -1) | (-(v1717 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1724 = v1722[v1870];
      int * v1725 = v1591->mem;
      int v1872 = v1721 * 2;
      v1725[v1872] = v1723;
      int * v1727 = v1591->mem;
      int v1875 = (v1721 * 2) + 1;
      v1727[v1875] = v1724;
      ;
    } else {
      ;
    }
    int * v1732 = v1591->mem;
    int v1880 = ((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) * 2;
    int v1733 = v1732[v1880];
    int v1881 = (((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) * 2) + 1;
    int v1734 = v1732[v1881];
    int * v1735 = v1591->cache_vals;
    int v1883 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v1713 + ((~(((v1715 ^ -1) | (-(v1715 ^ -1))) >> 31)) & 2)) - (v1716 + ((~(((v1717 ^ -1) | (-(v1717 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1735[v1883] = v1733;
    int * v1737 = v1591->cache_vals;
    int v1886 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v1713 + ((~(((v1715 ^ -1) | (-(v1715 ^ -1))) >> 31)) & 2)) - (v1716 + ((~(((v1717 ^ -1) | (-(v1717 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1737[v1886] = v1734;
    int * v1739 = v1591->cache_tags;
    int v1889 = (int)((unsigned int)((int)((unsigned int)(v1595 + 24) >> 2)) >> 1);
    v1739[v1865] = v1889;
    int * v1741 = v1591->cache_dirty;
    v1741[v1865] = 0;
    int * v1743 = v1591->cache_age;
    v1743[v1865] = 1;
    int * v1745 = v1591->cache_age;
    int v1746 = v1745[v1865];
    int v1747 = v1745[v1769];
    int v1895 = v1747 + ((int)((unsigned int)(v1747 - v1746) >> 31));
    v1745[v1769] = v1895;
    int * v1749 = v1591->cache_age;
    int v1750 = v1749[v1770];
    int v1897 = v1750 + ((int)((unsigned int)(v1750 - v1746) >> 31));
    v1749[v1770] = v1897;
    int * v1752 = v1591->cache_age;
    v1752[v1865] = 0;
    v1755 = v1865;
  }
  int * v1756 = v1591->cache_vals;
  int v1900 = (v1755 * 2) + (((int)((unsigned int)(v1595 + 24) >> 2)) & 1);
  v1756[v1900] = v1596;
  int * v1758 = v1591->cache_dirty;
  v1758[v1755] = 1;
  struct StateT * v1760 = slot_7(v1591);
  return v1760;
}

struct StateT * slot_55(struct StateT * v10177) {
  int v10178 = v10177->timer;
  int v10186 = v10178 + 1;
  v10177->timer = v10186;
  int * v10180 = v10177->regs;
  int v10181 = v10180[19];
  int v10182 = v10180[28];
  int v10191 = v10181 + v10182;
  v10180[22] = v10191;
  struct StateT * v10184 = slot_56(v10177);
  return v10184;
}

struct StateT * slot_213(struct StateT * v10106) {
  int v10107 = v10106->timer;
  int v10110 = v10107 + 1;
  v10106->timer = v10110;
  return v10106;
}

struct StateT * slot_82(struct StateT * v10597) {
  int v10598 = v10597->timer;
  int v10606 = v10598 + 1;
  v10597->timer = v10606;
  int * v10600 = v10597->regs;
  int v10601 = v10600[21];
  int v10602 = v10600[24];
  int v10610 = v10601 | v10602;
  v10600[21] = v10610;
  struct StateT * v10604 = slot_83(v10597);
  return v10604;
}

struct StateT * slot_161(struct StateT * v11831) {
  int v11832 = v11831->timer;
  int v11839 = v11832 + 1;
  v11831->timer = v11839;
  int * v11834 = v11831->regs;
  int v11835 = v11834[21];
  int v11842 = v11835 << 13;
  v11834[21] = v11842;
  struct StateT * v11837 = slot_162(v11831);
  return v11837;
}

struct StateT * slot_185(struct StateT * v12202) {
  int v12203 = v12202->timer;
  int v12211 = v12203 + 1;
  v12202->timer = v12211;
  int * v12205 = v12202->regs;
  int v12206 = v12205[22];
  int v12207 = v12205[24];
  int v12215 = v12206 | v12207;
  v12205[22] = v12215;
  struct StateT * v12209 = slot_186(v12202);
  return v12209;
}

struct StateT * slot_91(struct StateT * v10735) {
  int v10736 = v10735->timer;
  int v10744 = v10736 + 1;
  v10735->timer = v10744;
  int * v10738 = v10735->regs;
  int v10739 = v10738[12];
  int v10740 = v10738[22];
  int v10748 = v10739 ^ v10740;
  v10738[12] = v10748;
  struct StateT * v10742 = slot_92(v10735);
  return v10742;
}

struct StateT * slot_58(struct StateT * v10226) {
  int v10227 = v10226->timer;
  int v10234 = v10227 + 1;
  v10226->timer = v10234;
  int * v10229 = v10226->regs;
  int v10230 = v10229[20];
  int v10237 = v10230 << 9;
  v10229[20] = v10237;
  struct StateT * v10232 = slot_59(v10226);
  return v10232;
}

struct StateT * slot_89(struct StateT * v10703) {
  int v10704 = v10703->timer;
  int v10712 = v10704 + 1;
  v10703->timer = v10712;
  int * v10706 = v10703->regs;
  int v10707 = v10706[16];
  int v10708 = v10706[20];
  int v10716 = v10707 ^ v10708;
  v10706[16] = v10716;
  struct StateT * v10710 = slot_90(v10703);
  return v10710;
}

struct StateT * slot_66(struct StateT * v10346) {
  int v10347 = v10346->timer;
  int v10354 = v10347 + 1;
  v10346->timer = v10354;
  int * v10349 = v10346->regs;
  int v10350 = v10349[23];
  int v10358 = (int)((unsigned int)v10350 >> 23);
  v10349[24] = v10358;
  struct StateT * v10352 = slot_67(v10346);
  return v10352;
}

struct StateT * slot_140(struct StateT * v11504) {
  int v11505 = v11504->timer;
  int v11512 = v11505 + 1;
  v11504->timer = v11512;
  int * v11507 = v11504->regs;
  int v11508 = v11507[21];
  int v11516 = (int)((unsigned int)v11508 >> 23);
  v11507[24] = v11516;
  struct StateT * v11510 = slot_141(v11504);
  return v11510;
}

struct StateT * slot_49(struct StateT * v10060) {
  int v10061 = v10060->timer;
  int v10069 = v10061 + 1;
  v10060->timer = v10069;
  int * v10063 = v10060->regs;
  int v10064 = v10063[9];
  int v10065 = v10063[20];
  int v10073 = v10064 ^ v10065;
  v10063[9] = v10073;
  struct StateT * v10067 = slot_50(v10060);
  return v10067;
}

struct StateT * slot_50(struct StateT * v10090) {
  int v10091 = v10090->timer;
  int v10099 = v10091 + 1;
  v10090->timer = v10099;
  int * v10093 = v10090->regs;
  int v10094 = v10093[18];
  int v10095 = v10093[21];
  int v10103 = v10094 ^ v10095;
  v10093[18] = v10103;
  struct StateT * v10097 = slot_51(v10090);
  return v10097;
}

struct StateT * slot_37(struct StateT * v7099) {
  int v7100 = v7099->timer;
  int v7107 = v7100 + 1;
  v7099->timer = v7107;
  int * v7102 = v7099->regs;
  int v7103 = v7102[20];
  int v7111 = (int)((unsigned int)v7103 >> 25);
  v7102[24] = v7111;
  struct StateT * v7105 = slot_38(v7099);
  return v7105;
}

struct StateT * slot_114(struct StateT * v11096) {
  int v11097 = v11096->timer;
  int v11105 = v11097 + 1;
  v11096->timer = v11105;
  int * v11099 = v11096->regs;
  int v11100 = v11099[29];
  int v11101 = v11099[9];
  int v11110 = v11100 + v11101;
  v11099[21] = v11110;
  struct StateT * v11103 = slot_115(v11096);
  return v11103;
}

struct StateT * slot_135(struct StateT * v11425) {
  int v11426 = v11425->timer;
  int v11434 = v11426 + 1;
  v11425->timer = v11434;
  int * v11428 = v11425->regs;
  int v11429 = v11428[15];
  int v11430 = v11428[28];
  int v11439 = v11429 + v11430;
  v11428[22] = v11439;
  struct StateT * v11432 = slot_136(v11425);
  return v11432;
}

struct StateT * slot_59(struct StateT * v10240) {
  int v10241 = v10240->timer;
  int v10249 = v10241 + 1;
  v10240->timer = v10249;
  int * v10243 = v10240->regs;
  int v10244 = v10243[20];
  int v10245 = v10243[24];
  int v10253 = v10244 | v10245;
  v10243[20] = v10253;
  struct StateT * v10247 = slot_60(v10240);
  return v10247;
}

struct StateT * slot_192(struct StateT * v12311) {
  int v12312 = v12311->timer;
  int v12320 = v12312 + 1;
  v12311->timer = v12320;
  int * v12314 = v12311->regs;
  int v12315 = v12314[31];
  int v12316 = v12314[23];
  int v12324 = v12315 ^ v12316;
  v12314[31] = v12324;
  struct StateT * v12318 = slot_193(v12311);
  return v12318;
}

struct StateT * slot_40(struct StateT * v8089) {
  int v8090 = v8089->timer;
  int v8097 = v8090 + 1;
  v8089->timer = v8097;
  int * v8092 = v8089->regs;
  int v8093 = v8092[21];
  int v8101 = (int)((unsigned int)v8093 >> 25);
  v8092[24] = v8101;
  struct StateT * v8095 = slot_41(v8089);
  return v8095;
}

struct StateT * slot_48(struct StateT * v9840) {
  int v9841 = v9840->timer;
  int v9849 = v9841 + 1;
  v9840->timer = v9849;
  int * v9843 = v9840->regs;
  int v9844 = v9843[23];
  int v9845 = v9843[24];
  int v9853 = v9844 | v9845;
  v9843[23] = v9853;
  struct StateT * v9847 = slot_49(v9840);
  return v9847;
}

struct StateT * slot_77(struct StateT * v10523) {
  int v10524 = v10523->timer;
  int v10531 = v10524 + 1;
  v10523->timer = v10531;
  int * v10526 = v10523->regs;
  int v10527 = v10526[20];
  int v10535 = (int)((unsigned int)v10527 >> 19);
  v10526[24] = v10535;
  struct StateT * v10529 = slot_78(v10523);
  return v10529;
}

struct StateT * slot_85(struct StateT * v10642) {
  int v10643 = v10642->timer;
  int v10651 = v10643 + 1;
  v10642->timer = v10651;
  int * v10645 = v10642->regs;
  int v10646 = v10645[22];
  int v10647 = v10645[24];
  int v10655 = v10646 | v10647;
  v10645[22] = v10655;
  struct StateT * v10649 = slot_86(v10642);
  return v10649;
}

struct StateT * slot_75(struct StateT * v10489) {
  int v10490 = v10489->timer;
  int v10498 = v10490 + 1;
  v10489->timer = v10498;
  int * v10492 = v10489->regs;
  int v10493 = v10492[17];
  int v10494 = v10492[19];
  int v10503 = v10493 + v10494;
  v10492[22] = v10503;
  struct StateT * v10496 = slot_76(v10489);
  return v10496;
}

struct StateT * slot_72(struct StateT * v10439) {
  int v10440 = v10439->timer;
  int v10448 = v10440 + 1;
  v10439->timer = v10448;
  int * v10442 = v10439->regs;
  int v10443 = v10442[5];
  int v10444 = v10442[23];
  int v10452 = v10443 ^ v10444;
  v10442[5] = v10452;
  struct StateT * v10446 = slot_73(v10439);
  return v10446;
}

struct StateT * slot_119(struct StateT * v11176) {
  int v11177 = v11176->timer;
  int v11185 = v11177 + 1;
  v11176->timer = v11185;
  int * v11179 = v11176->regs;
  int v11180 = v11179[20];
  int v11181 = v11179[24];
  int v11189 = v11180 | v11181;
  v11179[20] = v11189;
  struct StateT * v11183 = slot_120(v11176);
  return v11183;
}

struct StateT * slot_71(struct StateT * v10423) {
  int v10424 = v10423->timer;
  int v10432 = v10424 + 1;
  v10423->timer = v10432;
  int * v10426 = v10423->regs;
  int v10427 = v10426[17];
  int v10428 = v10426[22];
  int v10436 = v10427 ^ v10428;
  v10426[17] = v10436;
  struct StateT * v10430 = slot_72(v10423);
  return v10430;
}

struct StateT * slot_101(struct StateT * v10895) {
  int v10896 = v10895->timer;
  int v10903 = v10896 + 1;
  v10895->timer = v10903;
  int * v10898 = v10895->regs;
  int v10899 = v10898[21];
  int v10906 = v10899 << 18;
  v10898[21] = v10906;
  struct StateT * v10901 = slot_102(v10895);
  return v10901;
}

struct StateT * slot_108(struct StateT * v10999) {
  int v11000 = v10999->timer;
  int v11008 = v11000 + 1;
  v10999->timer = v11008;
  int * v11002 = v10999->regs;
  int v11003 = v11002[23];
  int v11004 = v11002[24];
  int v11012 = v11003 | v11004;
  v11002[23] = v11012;
  struct StateT * v11006 = slot_109(v10999);
  return v11006;
}

struct StateT * slot_116(struct StateT * v11130) {
  int v11131 = v11130->timer;
  int v11139 = v11131 + 1;
  v11130->timer = v11139;
  int * v11133 = v11130->regs;
  int v11134 = v11133[31];
  int v11135 = v11133[19];
  int v11144 = v11134 + v11135;
  v11133[23] = v11144;
  struct StateT * v11137 = slot_117(v11130);
  return v11137;
}

struct StateT * slot_93(struct StateT * v10767) {
  int v10768 = v10767->timer;
  int v10776 = v10768 + 1;
  v10767->timer = v10776;
  int * v10770 = v10767->regs;
  int v10771 = v10770[16];
  int v10772 = v10770[6];
  int v10781 = v10771 + v10772;
  v10770[20] = v10781;
  struct StateT * v10774 = slot_94(v10767);
  return v10774;
}

struct StateT * slot_88(struct StateT * v10687) {
  int v10688 = v10687->timer;
  int v10696 = v10688 + 1;
  v10687->timer = v10696;
  int * v10690 = v10687->regs;
  int v10691 = v10690[23];
  int v10692 = v10690[24];
  int v10700 = v10691 | v10692;
  v10690[23] = v10700;
  struct StateT * v10694 = slot_89(v10687);
  return v10694;
}

struct StateT * slot_96(struct StateT * v10818) {
  int v10819 = v10818->timer;
  int v10827 = v10819 + 1;
  v10818->timer = v10827;
  int * v10821 = v10818->regs;
  int v10822 = v10821[15];
  int v10823 = v10821[5];
  int v10832 = v10822 + v10823;
  v10821[23] = v10832;
  struct StateT * v10825 = slot_97(v10818);
  return v10825;
}

struct StateT * slot_45(struct StateT * v9183) {
  int v9184 = v9183->timer;
  int v9192 = v9184 + 1;
  v9183->timer = v9192;
  int * v9186 = v9183->regs;
  int v9187 = v9186[22];
  int v9188 = v9186[24];
  int v9196 = v9187 | v9188;
  v9186[22] = v9196;
  struct StateT * v9190 = slot_46(v9183);
  return v9190;
}

struct StateT * slot_134(struct StateT * v11408) {
  int v11409 = v11408->timer;
  int v11417 = v11409 + 1;
  v11408->timer = v11417;
  int * v11411 = v11408->regs;
  int v11412 = v11411[12];
  int v11413 = v11411[29];
  int v11422 = v11412 + v11413;
  v11411[21] = v11422;
  struct StateT * v11415 = slot_135(v11408);
  return v11415;
}

struct StateT * slot_175(struct StateT * v12049) {
  int v12050 = v12049->timer;
  int v12058 = v12050 + 1;
  v12049->timer = v12058;
  int * v12052 = v12049->regs;
  int v12053 = v12052[18];
  int v12054 = v12052[6];
  int v12063 = v12053 + v12054;
  v12052[22] = v12063;
  struct StateT * v12056 = slot_176(v12049);
  return v12056;
}

struct StateT * slot_69(struct StateT * v10391) {
  int v10392 = v10391->timer;
  int v10400 = v10392 + 1;
  v10391->timer = v10400;
  int * v10394 = v10391->regs;
  int v10395 = v10394[6];
  int v10396 = v10394[20];
  int v10404 = v10395 ^ v10396;
  v10394[6] = v10404;
  struct StateT * v10398 = slot_70(v10391);
  return v10398;
}

struct StateT * slot_202(struct StateT * v7774) {
  int v7775 = v7774->timer;
  int v7945 = v7775 + 1;
  v7774->timer = v7945;
  int * v7777 = v7774->regs;
  int v7778 = v7777[10];
  int v7779 = v7777[18];
  int * v7780 = v7774->cache_tags;
  int v7950 = (((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1)) & 1) * 2;
  int v7781 = v7780[v7950];
  int v7951 = ((((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1)) & 1) * 2) + 1;
  int v7782 = v7780[v7951];
  int v7952 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1)) & 3) * 2);
  int v7783 = v7780[v7952];
  int v7953 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v7784 = v7780[v7953];
  int v7785 = v7774->timer;
  int v7954 = v7785 + ((100 ^ (((~(((v7783 ^ ((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1))) | (-(v7783 ^ ((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v7784 ^ ((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1))) | (-(v7784 ^ ((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v7781 ^ ((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1))) | (-(v7781 ^ ((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v7782 ^ ((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1))) | (-(v7782 ^ ((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v7783 ^ ((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1))) | (-(v7783 ^ ((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v7784 ^ ((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1))) | (-(v7784 ^ ((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1))))) >> 31))) & 104)))));
  v7774->timer = v7954;
  bool v7955 = !(((~(((v7781 ^ ((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1))) | (-(v7781 ^ ((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v7782 ^ ((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1))) | (-(v7782 ^ ((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v7879;
  if (v7955) {
    int * v7787 = v7774->cache_age;
    int v7957 = ((((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1)) & 1) * 2) + ((~(((v7782 ^ ((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1))) | (-(v7782 ^ ((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v7788 = v7787[v7957];
    int v7789 = v7787[v7950];
    int v7958 = v7789 + ((int)((unsigned int)(v7789 - v7788) >> 31));
    v7787[v7950] = v7958;
    int * v7791 = v7774->cache_age;
    int v7792 = v7791[v7951];
    int v7960 = v7792 + ((int)((unsigned int)(v7792 - v7788) >> 31));
    v7791[v7951] = v7960;
    int * v7794 = v7774->cache_age;
    v7794[v7957] = 0;
    v7879 = v7957;
  } else {
    int * v7797 = v7774->cache_age;
    int v7964 = (((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1)) & 1) * 2;
    int v7798 = v7797[v7964];
    int * v7799 = v7774->cache_tags;
    int v7800 = v7799[v7964];
    int v7801 = v7797[v7951];
    int v7802 = v7799[v7951];
    bool v7966 = !(((~(((v7783 ^ ((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1))) | (-(v7783 ^ ((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v7784 ^ ((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1))) | (-(v7784 ^ ((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1))))) >> 31))) == 0);
    int v7856;
    if (v7966) {
      int * v7803 = v7774->cache_age;
      int v7968 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7784 ^ ((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1))) | (-(v7784 ^ ((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1))))) >> 31)) & 1);
      int v7804 = v7803[v7968];
      int v7805 = v7803[v7952];
      int v7969 = v7805 + ((int)((unsigned int)(v7805 - v7804) >> 31));
      v7803[v7952] = v7969;
      int * v7807 = v7774->cache_age;
      int v7808 = v7807[v7953];
      int v7971 = v7808 + ((int)((unsigned int)(v7808 - v7804) >> 31));
      v7807[v7953] = v7971;
      int * v7810 = v7774->cache_age;
      v7810[v7968] = 0;
      v7856 = v7968;
    } else {
      int * v7813 = v7774->cache_age;
      int v7975 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1)) & 3) * 2);
      int v7814 = v7813[v7975];
      int * v7815 = v7774->cache_tags;
      int v7816 = v7815[v7975];
      int v7817 = v7813[v7953];
      int v7818 = v7815[v7953];
      int * v7819 = v7774->cache_dirty;
      int v7978 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v7814 + ((~(((v7816 ^ -1) | (-(v7816 ^ -1))) >> 31)) & 2)) - (v7817 + ((~(((v7818 ^ -1) | (-(v7818 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v7820 = v7819[v7978];
      bool v7979 = !(v7820 == 0);
      if (v7979) {
        int * v7821 = v7774->cache_tags;
        int v7822 = v7821[v7978];
        int * v7823 = v7774->cache_vals;
        int v7982 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v7814 + ((~(((v7816 ^ -1) | (-(v7816 ^ -1))) >> 31)) & 2)) - (v7817 + ((~(((v7818 ^ -1) | (-(v7818 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v7824 = v7823[v7982];
        int v7983 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v7814 + ((~(((v7816 ^ -1) | (-(v7816 ^ -1))) >> 31)) & 2)) - (v7817 + ((~(((v7818 ^ -1) | (-(v7818 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v7825 = v7823[v7983];
        int * v7826 = v7774->mem;
        int v7985 = v7822 * 2;
        v7826[v7985] = v7824;
        int * v7828 = v7774->mem;
        int v7988 = (v7822 * 2) + 1;
        v7828[v7988] = v7825;
        ;
      } else {
        ;
      }
      int * v7833 = v7774->mem;
      int v7993 = ((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1)) * 2;
      int v7834 = v7833[v7993];
      int v7994 = (((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1)) * 2) + 1;
      int v7835 = v7833[v7994];
      int * v7836 = v7774->cache_vals;
      int v7996 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v7814 + ((~(((v7816 ^ -1) | (-(v7816 ^ -1))) >> 31)) & 2)) - (v7817 + ((~(((v7818 ^ -1) | (-(v7818 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v7836[v7996] = v7834;
      int * v7838 = v7774->cache_vals;
      int v7999 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v7814 + ((~(((v7816 ^ -1) | (-(v7816 ^ -1))) >> 31)) & 2)) - (v7817 + ((~(((v7818 ^ -1) | (-(v7818 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v7838[v7999] = v7835;
      int * v7840 = v7774->cache_tags;
      int v8002 = (int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1);
      v7840[v7978] = v8002;
      int * v7842 = v7774->cache_dirty;
      v7842[v7978] = 0;
      int * v7844 = v7774->cache_age;
      v7844[v7978] = 1;
      int * v7846 = v7774->cache_age;
      int v7847 = v7846[v7978];
      int v7848 = v7846[v7952];
      int v8008 = v7848 + ((int)((unsigned int)(v7848 - v7847) >> 31));
      v7846[v7952] = v8008;
      int * v7850 = v7774->cache_age;
      int v7851 = v7850[v7953];
      int v8010 = v7851 + ((int)((unsigned int)(v7851 - v7847) >> 31));
      v7850[v7953] = v8010;
      int * v7853 = v7774->cache_age;
      v7853[v7978] = 0;
      v7856 = v7978;
    }
    int * v7857 = v7774->cache_vals;
    int v8013 = v7856 * 2;
    int v7858 = v7857[v8013];
    int v8014 = (v7856 * 2) + 1;
    int v7859 = v7857[v8014];
    int v8015 = (((((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v7798 + ((~(((v7800 ^ -1) | (-(v7800 ^ -1))) >> 31)) & 2)) - (v7801 + ((~(((v7802 ^ -1) | (-(v7802 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7857[v8015] = v7858;
    int * v7861 = v7774->cache_vals;
    int v8018 = ((((((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v7798 + ((~(((v7800 ^ -1) | (-(v7800 ^ -1))) >> 31)) & 2)) - (v7801 + ((~(((v7802 ^ -1) | (-(v7802 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7861[v8018] = v7859;
    int * v7863 = v7774->cache_tags;
    int v8021 = ((((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v7798 + ((~(((v7800 ^ -1) | (-(v7800 ^ -1))) >> 31)) & 2)) - (v7801 + ((~(((v7802 ^ -1) | (-(v7802 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v8022 = (int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1);
    v7863[v8021] = v8022;
    int * v7865 = v7774->cache_dirty;
    v7865[v8021] = 0;
    int * v7867 = v7774->cache_age;
    v7867[v8021] = 1;
    int * v7869 = v7774->cache_age;
    int v7870 = v7869[v8021];
    int v7871 = v7869[v7950];
    int v8028 = v7871 + ((int)((unsigned int)(v7871 - v7870) >> 31));
    v7869[v7950] = v8028;
    int * v7873 = v7774->cache_age;
    int v7874 = v7873[v7951];
    int v8030 = v7874 + ((int)((unsigned int)(v7874 - v7870) >> 31));
    v7873[v7951] = v8030;
    int * v7876 = v7774->cache_age;
    v7876[v8021] = 0;
    v7879 = v8021;
  }
  int * v7880 = v7774->cache_vals;
  int v8033 = (v7879 * 2) + (((int)((unsigned int)(v7778 + 28) >> 2)) & 1);
  v7880[v8033] = v7779;
  int * v7882 = v7774->cache_tags;
  int v7883 = v7882[v7952];
  int v7884 = v7882[v7953];
  bool v8036 = !(((~(((v7883 ^ ((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1))) | (-(v7883 ^ ((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v7884 ^ ((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1))) | (-(v7884 ^ ((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v7938;
  if (v8036) {
    int * v7885 = v7774->cache_age;
    int v8038 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7884 ^ ((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1))) | (-(v7884 ^ ((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v7886 = v7885[v8038];
    int v7887 = v7885[v7952];
    int v8039 = v7887 + ((int)((unsigned int)(v7887 - v7886) >> 31));
    v7885[v7952] = v8039;
    int * v7889 = v7774->cache_age;
    int v7890 = v7889[v7953];
    int v8041 = v7890 + ((int)((unsigned int)(v7890 - v7886) >> 31));
    v7889[v7953] = v8041;
    int * v7892 = v7774->cache_age;
    v7892[v8038] = 0;
    v7938 = v8038;
  } else {
    int * v7895 = v7774->cache_age;
    int v8045 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1)) & 3) * 2);
    int v7896 = v7895[v8045];
    int * v7897 = v7774->cache_tags;
    int v7898 = v7897[v8045];
    int v7899 = v7895[v7953];
    int v7900 = v7897[v7953];
    int * v7901 = v7774->cache_dirty;
    int v8048 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v7896 + ((~(((v7898 ^ -1) | (-(v7898 ^ -1))) >> 31)) & 2)) - (v7899 + ((~(((v7900 ^ -1) | (-(v7900 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7902 = v7901[v8048];
    bool v8049 = !(v7902 == 0);
    if (v8049) {
      int * v7903 = v7774->cache_tags;
      int v7904 = v7903[v8048];
      int * v7905 = v7774->cache_vals;
      int v8052 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v7896 + ((~(((v7898 ^ -1) | (-(v7898 ^ -1))) >> 31)) & 2)) - (v7899 + ((~(((v7900 ^ -1) | (-(v7900 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v7906 = v7905[v8052];
      int v8053 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v7896 + ((~(((v7898 ^ -1) | (-(v7898 ^ -1))) >> 31)) & 2)) - (v7899 + ((~(((v7900 ^ -1) | (-(v7900 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v7907 = v7905[v8053];
      int * v7908 = v7774->mem;
      int v8055 = v7904 * 2;
      v7908[v8055] = v7906;
      int * v7910 = v7774->mem;
      int v8058 = (v7904 * 2) + 1;
      v7910[v8058] = v7907;
      ;
    } else {
      ;
    }
    int * v7915 = v7774->mem;
    int v8063 = ((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1)) * 2;
    int v7916 = v7915[v8063];
    int v8064 = (((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1)) * 2) + 1;
    int v7917 = v7915[v8064];
    int * v7918 = v7774->cache_vals;
    int v8066 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v7896 + ((~(((v7898 ^ -1) | (-(v7898 ^ -1))) >> 31)) & 2)) - (v7899 + ((~(((v7900 ^ -1) | (-(v7900 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7918[v8066] = v7916;
    int * v7920 = v7774->cache_vals;
    int v8069 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v7896 + ((~(((v7898 ^ -1) | (-(v7898 ^ -1))) >> 31)) & 2)) - (v7899 + ((~(((v7900 ^ -1) | (-(v7900 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7920[v8069] = v7917;
    int * v7922 = v7774->cache_tags;
    int v8072 = (int)((unsigned int)((int)((unsigned int)(v7778 + 28) >> 2)) >> 1);
    v7922[v8048] = v8072;
    int * v7924 = v7774->cache_dirty;
    v7924[v8048] = 0;
    int * v7926 = v7774->cache_age;
    v7926[v8048] = 1;
    int * v7928 = v7774->cache_age;
    int v7929 = v7928[v8048];
    int v7930 = v7928[v7952];
    int v8078 = v7930 + ((int)((unsigned int)(v7930 - v7929) >> 31));
    v7928[v7952] = v8078;
    int * v7932 = v7774->cache_age;
    int v7933 = v7932[v7953];
    int v8080 = v7933 + ((int)((unsigned int)(v7933 - v7929) >> 31));
    v7932[v7953] = v8080;
    int * v7935 = v7774->cache_age;
    v7935[v8048] = 0;
    v7938 = v8048;
  }
  int * v7939 = v7774->cache_vals;
  int v8083 = (v7938 * 2) + (((int)((unsigned int)(v7778 + 28) >> 2)) & 1);
  v7939[v8083] = v7779;
  int * v7941 = v7774->cache_dirty;
  v7941[v7938] = 1;
  struct StateT * v7943 = slot_203(v7774);
  return v7943;
}

struct StateT * slot_188(struct StateT * v12247) {
  int v12248 = v12247->timer;
  int v12256 = v12248 + 1;
  v12247->timer = v12256;
  int * v12250 = v12247->regs;
  int v12251 = v12250[23];
  int v12252 = v12250[24];
  int v12260 = v12251 | v12252;
  v12250[23] = v12260;
  struct StateT * v12254 = slot_189(v12247);
  return v12254;
}

struct StateT * slot_138(struct StateT * v11474) {
  int v11475 = v11474->timer;
  int v11482 = v11475 + 1;
  v11474->timer = v11482;
  int * v11477 = v11474->regs;
  int v11478 = v11477[20];
  int v11485 = v11478 << 9;
  v11477[20] = v11485;
  struct StateT * v11480 = slot_139(v11474);
  return v11480;
}

struct StateT * slot_186(struct StateT * v12218) {
  int v12219 = v12218->timer;
  int v12226 = v12219 + 1;
  v12218->timer = v12226;
  int * v12221 = v12218->regs;
  int v12222 = v12221[23];
  int v12230 = (int)((unsigned int)v12222 >> 14);
  v12221[24] = v12230;
  struct StateT * v12224 = slot_187(v12218);
  return v12224;
}

struct StateT * slot_102(struct StateT * v10909) {
  int v10910 = v10909->timer;
  int v10918 = v10910 + 1;
  v10909->timer = v10918;
  int * v10912 = v10909->regs;
  int v10913 = v10912[21];
  int v10914 = v10912[24];
  int v10922 = v10913 | v10914;
  v10912[21] = v10922;
  struct StateT * v10916 = slot_103(v10909);
  return v10916;
}

struct StateT * slot_145(struct StateT * v11578) {
  int v11579 = v11578->timer;
  int v11587 = v11579 + 1;
  v11578->timer = v11587;
  int * v11581 = v11578->regs;
  int v11582 = v11581[22];
  int v11583 = v11581[24];
  int v11591 = v11582 | v11583;
  v11581[22] = v11591;
  struct StateT * v11585 = slot_146(v11578);
  return v11585;
}

struct StateT * slot_110(struct StateT * v11031) {
  int v11032 = v11031->timer;
  int v11040 = v11032 + 1;
  v11031->timer = v11040;
  int * v11034 = v11031->regs;
  int v11035 = v11034[29];
  int v11036 = v11034[21];
  int v11044 = v11035 ^ v11036;
  v11034[29] = v11044;
  struct StateT * v11038 = slot_111(v11031);
  return v11038;
}

struct StateT * slot_196(struct StateT * v5788) {
  int v5789 = v5788->timer;
  int v5959 = v5789 + 1;
  v5788->timer = v5959;
  int * v5791 = v5788->regs;
  int v5792 = v5791[10];
  int v5793 = v5791[29];
  int * v5794 = v5788->cache_tags;
  int v5964 = (((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1)) & 1) * 2;
  int v5795 = v5794[v5964];
  int v5965 = ((((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1)) & 1) * 2) + 1;
  int v5796 = v5794[v5965];
  int v5966 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1)) & 3) * 2);
  int v5797 = v5794[v5966];
  int v5967 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5798 = v5794[v5967];
  int v5799 = v5788->timer;
  int v5968 = v5799 + ((100 ^ (((~(((v5797 ^ ((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1))) | (-(v5797 ^ ((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v5798 ^ ((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1))) | (-(v5798 ^ ((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5795 ^ ((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1))) | (-(v5795 ^ ((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v5796 ^ ((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1))) | (-(v5796 ^ ((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5797 ^ ((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1))) | (-(v5797 ^ ((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v5798 ^ ((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1))) | (-(v5798 ^ ((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1))))) >> 31))) & 104)))));
  v5788->timer = v5968;
  bool v5969 = !(((~(((v5795 ^ ((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1))) | (-(v5795 ^ ((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v5796 ^ ((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1))) | (-(v5796 ^ ((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v5893;
  if (v5969) {
    int * v5801 = v5788->cache_age;
    int v5971 = ((((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1)) & 1) * 2) + ((~(((v5796 ^ ((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1))) | (-(v5796 ^ ((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v5802 = v5801[v5971];
    int v5803 = v5801[v5964];
    int v5972 = v5803 + ((int)((unsigned int)(v5803 - v5802) >> 31));
    v5801[v5964] = v5972;
    int * v5805 = v5788->cache_age;
    int v5806 = v5805[v5965];
    int v5974 = v5806 + ((int)((unsigned int)(v5806 - v5802) >> 31));
    v5805[v5965] = v5974;
    int * v5808 = v5788->cache_age;
    v5808[v5971] = 0;
    v5893 = v5971;
  } else {
    int * v5811 = v5788->cache_age;
    int v5978 = (((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1)) & 1) * 2;
    int v5812 = v5811[v5978];
    int * v5813 = v5788->cache_tags;
    int v5814 = v5813[v5978];
    int v5815 = v5811[v5965];
    int v5816 = v5813[v5965];
    bool v5980 = !(((~(((v5797 ^ ((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1))) | (-(v5797 ^ ((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v5798 ^ ((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1))) | (-(v5798 ^ ((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1))))) >> 31))) == 0);
    int v5870;
    if (v5980) {
      int * v5817 = v5788->cache_age;
      int v5982 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5798 ^ ((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1))) | (-(v5798 ^ ((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1))))) >> 31)) & 1);
      int v5818 = v5817[v5982];
      int v5819 = v5817[v5966];
      int v5983 = v5819 + ((int)((unsigned int)(v5819 - v5818) >> 31));
      v5817[v5966] = v5983;
      int * v5821 = v5788->cache_age;
      int v5822 = v5821[v5967];
      int v5985 = v5822 + ((int)((unsigned int)(v5822 - v5818) >> 31));
      v5821[v5967] = v5985;
      int * v5824 = v5788->cache_age;
      v5824[v5982] = 0;
      v5870 = v5982;
    } else {
      int * v5827 = v5788->cache_age;
      int v5989 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1)) & 3) * 2);
      int v5828 = v5827[v5989];
      int * v5829 = v5788->cache_tags;
      int v5830 = v5829[v5989];
      int v5831 = v5827[v5967];
      int v5832 = v5829[v5967];
      int * v5833 = v5788->cache_dirty;
      int v5992 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5828 + ((~(((v5830 ^ -1) | (-(v5830 ^ -1))) >> 31)) & 2)) - (v5831 + ((~(((v5832 ^ -1) | (-(v5832 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5834 = v5833[v5992];
      bool v5993 = !(v5834 == 0);
      if (v5993) {
        int * v5835 = v5788->cache_tags;
        int v5836 = v5835[v5992];
        int * v5837 = v5788->cache_vals;
        int v5996 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5828 + ((~(((v5830 ^ -1) | (-(v5830 ^ -1))) >> 31)) & 2)) - (v5831 + ((~(((v5832 ^ -1) | (-(v5832 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5838 = v5837[v5996];
        int v5997 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5828 + ((~(((v5830 ^ -1) | (-(v5830 ^ -1))) >> 31)) & 2)) - (v5831 + ((~(((v5832 ^ -1) | (-(v5832 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5839 = v5837[v5997];
        int * v5840 = v5788->mem;
        int v5999 = v5836 * 2;
        v5840[v5999] = v5838;
        int * v5842 = v5788->mem;
        int v6002 = (v5836 * 2) + 1;
        v5842[v6002] = v5839;
        ;
      } else {
        ;
      }
      int * v5847 = v5788->mem;
      int v6007 = ((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1)) * 2;
      int v5848 = v5847[v6007];
      int v6008 = (((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1)) * 2) + 1;
      int v5849 = v5847[v6008];
      int * v5850 = v5788->cache_vals;
      int v6010 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5828 + ((~(((v5830 ^ -1) | (-(v5830 ^ -1))) >> 31)) & 2)) - (v5831 + ((~(((v5832 ^ -1) | (-(v5832 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5850[v6010] = v5848;
      int * v5852 = v5788->cache_vals;
      int v6013 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5828 + ((~(((v5830 ^ -1) | (-(v5830 ^ -1))) >> 31)) & 2)) - (v5831 + ((~(((v5832 ^ -1) | (-(v5832 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5852[v6013] = v5849;
      int * v5854 = v5788->cache_tags;
      int v6016 = (int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1);
      v5854[v5992] = v6016;
      int * v5856 = v5788->cache_dirty;
      v5856[v5992] = 0;
      int * v5858 = v5788->cache_age;
      v5858[v5992] = 1;
      int * v5860 = v5788->cache_age;
      int v5861 = v5860[v5992];
      int v5862 = v5860[v5966];
      int v6022 = v5862 + ((int)((unsigned int)(v5862 - v5861) >> 31));
      v5860[v5966] = v6022;
      int * v5864 = v5788->cache_age;
      int v5865 = v5864[v5967];
      int v6024 = v5865 + ((int)((unsigned int)(v5865 - v5861) >> 31));
      v5864[v5967] = v6024;
      int * v5867 = v5788->cache_age;
      v5867[v5992] = 0;
      v5870 = v5992;
    }
    int * v5871 = v5788->cache_vals;
    int v6027 = v5870 * 2;
    int v5872 = v5871[v6027];
    int v6028 = (v5870 * 2) + 1;
    int v5873 = v5871[v6028];
    int v6029 = (((((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v5812 + ((~(((v5814 ^ -1) | (-(v5814 ^ -1))) >> 31)) & 2)) - (v5815 + ((~(((v5816 ^ -1) | (-(v5816 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5871[v6029] = v5872;
    int * v5875 = v5788->cache_vals;
    int v6032 = ((((((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v5812 + ((~(((v5814 ^ -1) | (-(v5814 ^ -1))) >> 31)) & 2)) - (v5815 + ((~(((v5816 ^ -1) | (-(v5816 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5875[v6032] = v5873;
    int * v5877 = v5788->cache_tags;
    int v6035 = ((((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1)) & 1) * 2) + ((((v5812 + ((~(((v5814 ^ -1) | (-(v5814 ^ -1))) >> 31)) & 2)) - (v5815 + ((~(((v5816 ^ -1) | (-(v5816 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v6036 = (int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1);
    v5877[v6035] = v6036;
    int * v5879 = v5788->cache_dirty;
    v5879[v6035] = 0;
    int * v5881 = v5788->cache_age;
    v5881[v6035] = 1;
    int * v5883 = v5788->cache_age;
    int v5884 = v5883[v6035];
    int v5885 = v5883[v5964];
    int v6042 = v5885 + ((int)((unsigned int)(v5885 - v5884) >> 31));
    v5883[v5964] = v6042;
    int * v5887 = v5788->cache_age;
    int v5888 = v5887[v5965];
    int v6044 = v5888 + ((int)((unsigned int)(v5888 - v5884) >> 31));
    v5887[v5965] = v6044;
    int * v5890 = v5788->cache_age;
    v5890[v6035] = 0;
    v5893 = v6035;
  }
  int * v5894 = v5788->cache_vals;
  int v6047 = (v5893 * 2) + (((int)((unsigned int)(v5792 + 4) >> 2)) & 1);
  v5894[v6047] = v5793;
  int * v5896 = v5788->cache_tags;
  int v5897 = v5896[v5966];
  int v5898 = v5896[v5967];
  bool v6050 = !(((~(((v5897 ^ ((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1))) | (-(v5897 ^ ((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1))))) >> 31)) | (~(((v5898 ^ ((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1))) | (-(v5898 ^ ((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1))))) >> 31))) == 0);
  int v5952;
  if (v6050) {
    int * v5899 = v5788->cache_age;
    int v6052 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5898 ^ ((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1))) | (-(v5898 ^ ((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1))))) >> 31)) & 1);
    int v5900 = v5899[v6052];
    int v5901 = v5899[v5966];
    int v6053 = v5901 + ((int)((unsigned int)(v5901 - v5900) >> 31));
    v5899[v5966] = v6053;
    int * v5903 = v5788->cache_age;
    int v5904 = v5903[v5967];
    int v6055 = v5904 + ((int)((unsigned int)(v5904 - v5900) >> 31));
    v5903[v5967] = v6055;
    int * v5906 = v5788->cache_age;
    v5906[v6052] = 0;
    v5952 = v6052;
  } else {
    int * v5909 = v5788->cache_age;
    int v6059 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1)) & 3) * 2);
    int v5910 = v5909[v6059];
    int * v5911 = v5788->cache_tags;
    int v5912 = v5911[v6059];
    int v5913 = v5909[v5967];
    int v5914 = v5911[v5967];
    int * v5915 = v5788->cache_dirty;
    int v6062 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5910 + ((~(((v5912 ^ -1) | (-(v5912 ^ -1))) >> 31)) & 2)) - (v5913 + ((~(((v5914 ^ -1) | (-(v5914 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5916 = v5915[v6062];
    bool v6063 = !(v5916 == 0);
    if (v6063) {
      int * v5917 = v5788->cache_tags;
      int v5918 = v5917[v6062];
      int * v5919 = v5788->cache_vals;
      int v6066 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5910 + ((~(((v5912 ^ -1) | (-(v5912 ^ -1))) >> 31)) & 2)) - (v5913 + ((~(((v5914 ^ -1) | (-(v5914 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v5920 = v5919[v6066];
      int v6067 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5910 + ((~(((v5912 ^ -1) | (-(v5912 ^ -1))) >> 31)) & 2)) - (v5913 + ((~(((v5914 ^ -1) | (-(v5914 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v5921 = v5919[v6067];
      int * v5922 = v5788->mem;
      int v6069 = v5918 * 2;
      v5922[v6069] = v5920;
      int * v5924 = v5788->mem;
      int v6072 = (v5918 * 2) + 1;
      v5924[v6072] = v5921;
      ;
    } else {
      ;
    }
    int * v5929 = v5788->mem;
    int v6077 = ((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1)) * 2;
    int v5930 = v5929[v6077];
    int v6078 = (((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1)) * 2) + 1;
    int v5931 = v5929[v6078];
    int * v5932 = v5788->cache_vals;
    int v6080 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5910 + ((~(((v5912 ^ -1) | (-(v5912 ^ -1))) >> 31)) & 2)) - (v5913 + ((~(((v5914 ^ -1) | (-(v5914 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5932[v6080] = v5930;
    int * v5934 = v5788->cache_vals;
    int v6083 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1)) & 3) * 2)) + ((((v5910 + ((~(((v5912 ^ -1) | (-(v5912 ^ -1))) >> 31)) & 2)) - (v5913 + ((~(((v5914 ^ -1) | (-(v5914 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5934[v6083] = v5931;
    int * v5936 = v5788->cache_tags;
    int v6086 = (int)((unsigned int)((int)((unsigned int)(v5792 + 4) >> 2)) >> 1);
    v5936[v6062] = v6086;
    int * v5938 = v5788->cache_dirty;
    v5938[v6062] = 0;
    int * v5940 = v5788->cache_age;
    v5940[v6062] = 1;
    int * v5942 = v5788->cache_age;
    int v5943 = v5942[v6062];
    int v5944 = v5942[v5966];
    int v6092 = v5944 + ((int)((unsigned int)(v5944 - v5943) >> 31));
    v5942[v5966] = v6092;
    int * v5946 = v5788->cache_age;
    int v5947 = v5946[v5967];
    int v6094 = v5947 + ((int)((unsigned int)(v5947 - v5943) >> 31));
    v5946[v5967] = v6094;
    int * v5949 = v5788->cache_age;
    v5949[v6062] = 0;
    v5952 = v6062;
  }
  int * v5953 = v5788->cache_vals;
  int v6097 = (v5952 * 2) + (((int)((unsigned int)(v5792 + 4) >> 2)) & 1);
  v5953[v6097] = v5793;
  int * v5955 = v5788->cache_dirty;
  v5955[v5952] = 1;
  struct StateT * v5957 = slot_197(v5788);
  return v5957;
}

struct StateT * slot_208(struct StateT * v9199) {
  int v9200 = v9199->timer;
  int v9310 = v9200 + 1;
  v9199->timer = v9310;
  int * v9202 = v9199->regs;
  int v9203 = v9202[2];
  int * v9204 = v9199->cache_tags;
  int v9314 = (((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1)) & 1) * 2;
  int v9205 = v9204[v9314];
  int v9315 = ((((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1)) & 1) * 2) + 1;
  int v9206 = v9204[v9315];
  int v9316 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1)) & 3) * 2);
  int v9207 = v9204[v9316];
  int v9317 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v9208 = v9204[v9317];
  int v9209 = v9199->timer;
  int v9318 = v9209 + ((100 ^ (((~(((v9207 ^ ((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1))) | (-(v9207 ^ ((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v9208 ^ ((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1))) | (-(v9208 ^ ((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v9205 ^ ((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1))) | (-(v9205 ^ ((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v9206 ^ ((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1))) | (-(v9206 ^ ((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v9207 ^ ((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1))) | (-(v9207 ^ ((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v9208 ^ ((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1))) | (-(v9208 ^ ((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1))))) >> 31))) & 104)))));
  v9199->timer = v9318;
  int * v9211 = v9199->cache_vals;
  bool v9319 = !(((~(((v9205 ^ ((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1))) | (-(v9205 ^ ((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v9206 ^ ((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1))) | (-(v9206 ^ ((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1))))) >> 31))) == 0);
  int v9304;
  if (v9319) {
    int * v9212 = v9199->cache_age;
    int v9321 = ((((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1)) & 1) * 2) + ((~(((v9206 ^ ((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1))) | (-(v9206 ^ ((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1))))) >> 31)) & 1);
    int v9213 = v9212[v9321];
    int v9214 = v9212[v9314];
    int v9322 = v9214 + ((int)((unsigned int)(v9214 - v9213) >> 31));
    v9212[v9314] = v9322;
    int * v9216 = v9199->cache_age;
    int v9217 = v9216[v9315];
    int v9324 = v9217 + ((int)((unsigned int)(v9217 - v9213) >> 31));
    v9216[v9315] = v9324;
    int * v9219 = v9199->cache_age;
    v9219[v9321] = 0;
    v9304 = v9321;
  } else {
    int * v9222 = v9199->cache_age;
    int v9328 = (((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1)) & 1) * 2;
    int v9223 = v9222[v9328];
    int * v9224 = v9199->cache_tags;
    int v9225 = v9224[v9328];
    int v9226 = v9222[v9315];
    int v9227 = v9224[v9315];
    bool v9330 = !(((~(((v9207 ^ ((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1))) | (-(v9207 ^ ((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1))))) >> 31)) | (~(((v9208 ^ ((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1))) | (-(v9208 ^ ((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1))))) >> 31))) == 0);
    int v9281;
    if (v9330) {
      int * v9228 = v9199->cache_age;
      int v9332 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1)) & 3) * 2)) + ((~(((v9208 ^ ((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1))) | (-(v9208 ^ ((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1))))) >> 31)) & 1);
      int v9229 = v9228[v9332];
      int v9230 = v9228[v9316];
      int v9333 = v9230 + ((int)((unsigned int)(v9230 - v9229) >> 31));
      v9228[v9316] = v9333;
      int * v9232 = v9199->cache_age;
      int v9233 = v9232[v9317];
      int v9335 = v9233 + ((int)((unsigned int)(v9233 - v9229) >> 31));
      v9232[v9317] = v9335;
      int * v9235 = v9199->cache_age;
      v9235[v9332] = 0;
      v9281 = v9332;
    } else {
      int * v9238 = v9199->cache_age;
      int v9339 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1)) & 3) * 2);
      int v9239 = v9238[v9339];
      int * v9240 = v9199->cache_tags;
      int v9241 = v9240[v9339];
      int v9242 = v9238[v9317];
      int v9243 = v9240[v9317];
      int * v9244 = v9199->cache_dirty;
      int v9342 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v9239 + ((~(((v9241 ^ -1) | (-(v9241 ^ -1))) >> 31)) & 2)) - (v9242 + ((~(((v9243 ^ -1) | (-(v9243 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v9245 = v9244[v9342];
      bool v9343 = !(v9245 == 0);
      if (v9343) {
        int * v9246 = v9199->cache_tags;
        int v9247 = v9246[v9342];
        int * v9248 = v9199->cache_vals;
        int v9346 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v9239 + ((~(((v9241 ^ -1) | (-(v9241 ^ -1))) >> 31)) & 2)) - (v9242 + ((~(((v9243 ^ -1) | (-(v9243 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v9249 = v9248[v9346];
        int v9347 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v9239 + ((~(((v9241 ^ -1) | (-(v9241 ^ -1))) >> 31)) & 2)) - (v9242 + ((~(((v9243 ^ -1) | (-(v9243 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v9250 = v9248[v9347];
        int * v9251 = v9199->mem;
        int v9349 = v9247 * 2;
        v9251[v9349] = v9249;
        int * v9253 = v9199->mem;
        int v9352 = (v9247 * 2) + 1;
        v9253[v9352] = v9250;
        ;
      } else {
        ;
      }
      int * v9258 = v9199->mem;
      int v9357 = ((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1)) * 2;
      int v9259 = v9258[v9357];
      int v9358 = (((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1)) * 2) + 1;
      int v9260 = v9258[v9358];
      int * v9261 = v9199->cache_vals;
      int v9360 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v9239 + ((~(((v9241 ^ -1) | (-(v9241 ^ -1))) >> 31)) & 2)) - (v9242 + ((~(((v9243 ^ -1) | (-(v9243 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v9261[v9360] = v9259;
      int * v9263 = v9199->cache_vals;
      int v9363 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1)) & 3) * 2)) + ((((v9239 + ((~(((v9241 ^ -1) | (-(v9241 ^ -1))) >> 31)) & 2)) - (v9242 + ((~(((v9243 ^ -1) | (-(v9243 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v9263[v9363] = v9260;
      int * v9265 = v9199->cache_tags;
      int v9366 = (int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1);
      v9265[v9342] = v9366;
      int * v9267 = v9199->cache_dirty;
      v9267[v9342] = 0;
      int * v9269 = v9199->cache_age;
      v9269[v9342] = 1;
      int * v9271 = v9199->cache_age;
      int v9272 = v9271[v9342];
      int v9273 = v9271[v9316];
      int v9372 = v9273 + ((int)((unsigned int)(v9273 - v9272) >> 31));
      v9271[v9316] = v9372;
      int * v9275 = v9199->cache_age;
      int v9276 = v9275[v9317];
      int v9374 = v9276 + ((int)((unsigned int)(v9276 - v9272) >> 31));
      v9275[v9317] = v9374;
      int * v9278 = v9199->cache_age;
      v9278[v9342] = 0;
      v9281 = v9342;
    }
    int * v9282 = v9199->cache_vals;
    int v9377 = v9281 * 2;
    int v9283 = v9282[v9377];
    int v9378 = (v9281 * 2) + 1;
    int v9284 = v9282[v9378];
    int v9379 = (((((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v9223 + ((~(((v9225 ^ -1) | (-(v9225 ^ -1))) >> 31)) & 2)) - (v9226 + ((~(((v9227 ^ -1) | (-(v9227 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v9282[v9379] = v9283;
    int * v9286 = v9199->cache_vals;
    int v9382 = ((((((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v9223 + ((~(((v9225 ^ -1) | (-(v9225 ^ -1))) >> 31)) & 2)) - (v9226 + ((~(((v9227 ^ -1) | (-(v9227 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v9286[v9382] = v9284;
    int * v9288 = v9199->cache_tags;
    int v9385 = ((((int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1)) & 1) * 2) + ((((v9223 + ((~(((v9225 ^ -1) | (-(v9225 ^ -1))) >> 31)) & 2)) - (v9226 + ((~(((v9227 ^ -1) | (-(v9227 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v9386 = (int)((unsigned int)((int)((unsigned int)(v9203 + 24) >> 2)) >> 1);
    v9288[v9385] = v9386;
    int * v9290 = v9199->cache_dirty;
    v9290[v9385] = 0;
    int * v9292 = v9199->cache_age;
    v9292[v9385] = 1;
    int * v9294 = v9199->cache_age;
    int v9295 = v9294[v9385];
    int v9296 = v9294[v9314];
    int v9392 = v9296 + ((int)((unsigned int)(v9296 - v9295) >> 31));
    v9294[v9314] = v9392;
    int * v9298 = v9199->cache_age;
    int v9299 = v9298[v9315];
    int v9394 = v9299 + ((int)((unsigned int)(v9299 - v9295) >> 31));
    v9298[v9315] = v9394;
    int * v9301 = v9199->cache_age;
    v9301[v9385] = 0;
    v9304 = v9385;
  }
  int v9397 = (v9304 * 2) + (((int)((unsigned int)(v9203 + 24) >> 2)) & 1);
  int v9305 = v9211[v9397];
  int * v9306 = v9199->regs;
  v9306[21] = v9305;
  struct StateT * v9308 = slot_209(v9199);
  return v9308;
}

struct StateT * slot_172(struct StateT * v11999) {
  int v12000 = v11999->timer;
  int v12008 = v12000 + 1;
  v11999->timer = v12008;
  int * v12002 = v11999->regs;
  int v12003 = v12002[19];
  int v12004 = v12002[23];
  int v12012 = v12003 ^ v12004;
  v12002[19] = v12012;
  struct StateT * v12006 = slot_173(v11999);
  return v12006;
}

struct StateT * slot_131(struct StateT * v11359) {
  int v11360 = v11359->timer;
  int v11368 = v11360 + 1;
  v11359->timer = v11368;
  int * v11362 = v11359->regs;
  int v11363 = v11362[15];
  int v11364 = v11362[22];
  int v11372 = v11363 ^ v11364;
  v11362[15] = v11372;
  struct StateT * v11366 = slot_132(v11359);
  return v11366;
}

struct StateT * slot_8(struct StateT * v2221) {
  int v2222 = v2221->timer;
  int v2392 = v2222 + 1;
  v2221->timer = v2392;
  int * v2224 = v2221->regs;
  int v2225 = v2224[2];
  int v2226 = v2224[23];
  int * v2227 = v2221->cache_tags;
  int v2397 = (((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 1) * 2;
  int v2228 = v2227[v2397];
  int v2398 = ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 1) * 2) + 1;
  int v2229 = v2227[v2398];
  int v2399 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 3) * 2);
  int v2230 = v2227[v2399];
  int v2400 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2231 = v2227[v2400];
  int v2232 = v2221->timer;
  int v2401 = v2232 + ((100 ^ (((~(((v2230 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))) | (-(v2230 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v2231 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))) | (-(v2231 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2228 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))) | (-(v2228 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v2229 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))) | (-(v2229 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2230 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))) | (-(v2230 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v2231 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))) | (-(v2231 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))))) >> 31))) & 104)))));
  v2221->timer = v2401;
  bool v2402 = !(((~(((v2228 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))) | (-(v2228 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v2229 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))) | (-(v2229 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v2326;
  if (v2402) {
    int * v2234 = v2221->cache_age;
    int v2404 = ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 1) * 2) + ((~(((v2229 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))) | (-(v2229 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v2235 = v2234[v2404];
    int v2236 = v2234[v2397];
    int v2405 = v2236 + ((int)((unsigned int)(v2236 - v2235) >> 31));
    v2234[v2397] = v2405;
    int * v2238 = v2221->cache_age;
    int v2239 = v2238[v2398];
    int v2407 = v2239 + ((int)((unsigned int)(v2239 - v2235) >> 31));
    v2238[v2398] = v2407;
    int * v2241 = v2221->cache_age;
    v2241[v2404] = 0;
    v2326 = v2404;
  } else {
    int * v2244 = v2221->cache_age;
    int v2411 = (((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 1) * 2;
    int v2245 = v2244[v2411];
    int * v2246 = v2221->cache_tags;
    int v2247 = v2246[v2411];
    int v2248 = v2244[v2398];
    int v2249 = v2246[v2398];
    bool v2413 = !(((~(((v2230 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))) | (-(v2230 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v2231 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))) | (-(v2231 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))))) >> 31))) == 0);
    int v2303;
    if (v2413) {
      int * v2250 = v2221->cache_age;
      int v2415 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2231 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))) | (-(v2231 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))))) >> 31)) & 1);
      int v2251 = v2250[v2415];
      int v2252 = v2250[v2399];
      int v2416 = v2252 + ((int)((unsigned int)(v2252 - v2251) >> 31));
      v2250[v2399] = v2416;
      int * v2254 = v2221->cache_age;
      int v2255 = v2254[v2400];
      int v2418 = v2255 + ((int)((unsigned int)(v2255 - v2251) >> 31));
      v2254[v2400] = v2418;
      int * v2257 = v2221->cache_age;
      v2257[v2415] = 0;
      v2303 = v2415;
    } else {
      int * v2260 = v2221->cache_age;
      int v2422 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 3) * 2);
      int v2261 = v2260[v2422];
      int * v2262 = v2221->cache_tags;
      int v2263 = v2262[v2422];
      int v2264 = v2260[v2400];
      int v2265 = v2262[v2400];
      int * v2266 = v2221->cache_dirty;
      int v2425 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v2261 + ((~(((v2263 ^ -1) | (-(v2263 ^ -1))) >> 31)) & 2)) - (v2264 + ((~(((v2265 ^ -1) | (-(v2265 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2267 = v2266[v2425];
      bool v2426 = !(v2267 == 0);
      if (v2426) {
        int * v2268 = v2221->cache_tags;
        int v2269 = v2268[v2425];
        int * v2270 = v2221->cache_vals;
        int v2429 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v2261 + ((~(((v2263 ^ -1) | (-(v2263 ^ -1))) >> 31)) & 2)) - (v2264 + ((~(((v2265 ^ -1) | (-(v2265 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2271 = v2270[v2429];
        int v2430 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v2261 + ((~(((v2263 ^ -1) | (-(v2263 ^ -1))) >> 31)) & 2)) - (v2264 + ((~(((v2265 ^ -1) | (-(v2265 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2272 = v2270[v2430];
        int * v2273 = v2221->mem;
        int v2432 = v2269 * 2;
        v2273[v2432] = v2271;
        int * v2275 = v2221->mem;
        int v2435 = (v2269 * 2) + 1;
        v2275[v2435] = v2272;
        ;
      } else {
        ;
      }
      int * v2280 = v2221->mem;
      int v2440 = ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) * 2;
      int v2281 = v2280[v2440];
      int v2441 = (((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) * 2) + 1;
      int v2282 = v2280[v2441];
      int * v2283 = v2221->cache_vals;
      int v2443 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v2261 + ((~(((v2263 ^ -1) | (-(v2263 ^ -1))) >> 31)) & 2)) - (v2264 + ((~(((v2265 ^ -1) | (-(v2265 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2283[v2443] = v2281;
      int * v2285 = v2221->cache_vals;
      int v2446 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v2261 + ((~(((v2263 ^ -1) | (-(v2263 ^ -1))) >> 31)) & 2)) - (v2264 + ((~(((v2265 ^ -1) | (-(v2265 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2285[v2446] = v2282;
      int * v2287 = v2221->cache_tags;
      int v2449 = (int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1);
      v2287[v2425] = v2449;
      int * v2289 = v2221->cache_dirty;
      v2289[v2425] = 0;
      int * v2291 = v2221->cache_age;
      v2291[v2425] = 1;
      int * v2293 = v2221->cache_age;
      int v2294 = v2293[v2425];
      int v2295 = v2293[v2399];
      int v2455 = v2295 + ((int)((unsigned int)(v2295 - v2294) >> 31));
      v2293[v2399] = v2455;
      int * v2297 = v2221->cache_age;
      int v2298 = v2297[v2400];
      int v2457 = v2298 + ((int)((unsigned int)(v2298 - v2294) >> 31));
      v2297[v2400] = v2457;
      int * v2300 = v2221->cache_age;
      v2300[v2425] = 0;
      v2303 = v2425;
    }
    int * v2304 = v2221->cache_vals;
    int v2460 = v2303 * 2;
    int v2305 = v2304[v2460];
    int v2461 = (v2303 * 2) + 1;
    int v2306 = v2304[v2461];
    int v2462 = (((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v2245 + ((~(((v2247 ^ -1) | (-(v2247 ^ -1))) >> 31)) & 2)) - (v2248 + ((~(((v2249 ^ -1) | (-(v2249 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2304[v2462] = v2305;
    int * v2308 = v2221->cache_vals;
    int v2465 = ((((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v2245 + ((~(((v2247 ^ -1) | (-(v2247 ^ -1))) >> 31)) & 2)) - (v2248 + ((~(((v2249 ^ -1) | (-(v2249 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2308[v2465] = v2306;
    int * v2310 = v2221->cache_tags;
    int v2468 = ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 1) * 2) + ((((v2245 + ((~(((v2247 ^ -1) | (-(v2247 ^ -1))) >> 31)) & 2)) - (v2248 + ((~(((v2249 ^ -1) | (-(v2249 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2469 = (int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1);
    v2310[v2468] = v2469;
    int * v2312 = v2221->cache_dirty;
    v2312[v2468] = 0;
    int * v2314 = v2221->cache_age;
    v2314[v2468] = 1;
    int * v2316 = v2221->cache_age;
    int v2317 = v2316[v2468];
    int v2318 = v2316[v2397];
    int v2475 = v2318 + ((int)((unsigned int)(v2318 - v2317) >> 31));
    v2316[v2397] = v2475;
    int * v2320 = v2221->cache_age;
    int v2321 = v2320[v2398];
    int v2477 = v2321 + ((int)((unsigned int)(v2321 - v2317) >> 31));
    v2320[v2398] = v2477;
    int * v2323 = v2221->cache_age;
    v2323[v2468] = 0;
    v2326 = v2468;
  }
  int * v2327 = v2221->cache_vals;
  int v2480 = (v2326 * 2) + (((int)((unsigned int)(v2225 + 16) >> 2)) & 1);
  v2327[v2480] = v2226;
  int * v2329 = v2221->cache_tags;
  int v2330 = v2329[v2399];
  int v2331 = v2329[v2400];
  bool v2483 = !(((~(((v2330 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))) | (-(v2330 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))))) >> 31)) | (~(((v2331 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))) | (-(v2331 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))))) >> 31))) == 0);
  int v2385;
  if (v2483) {
    int * v2332 = v2221->cache_age;
    int v2485 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 3) * 2)) + ((~(((v2331 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))) | (-(v2331 ^ ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1))))) >> 31)) & 1);
    int v2333 = v2332[v2485];
    int v2334 = v2332[v2399];
    int v2486 = v2334 + ((int)((unsigned int)(v2334 - v2333) >> 31));
    v2332[v2399] = v2486;
    int * v2336 = v2221->cache_age;
    int v2337 = v2336[v2400];
    int v2488 = v2337 + ((int)((unsigned int)(v2337 - v2333) >> 31));
    v2336[v2400] = v2488;
    int * v2339 = v2221->cache_age;
    v2339[v2485] = 0;
    v2385 = v2485;
  } else {
    int * v2342 = v2221->cache_age;
    int v2492 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 3) * 2);
    int v2343 = v2342[v2492];
    int * v2344 = v2221->cache_tags;
    int v2345 = v2344[v2492];
    int v2346 = v2342[v2400];
    int v2347 = v2344[v2400];
    int * v2348 = v2221->cache_dirty;
    int v2495 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v2343 + ((~(((v2345 ^ -1) | (-(v2345 ^ -1))) >> 31)) & 2)) - (v2346 + ((~(((v2347 ^ -1) | (-(v2347 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v2349 = v2348[v2495];
    bool v2496 = !(v2349 == 0);
    if (v2496) {
      int * v2350 = v2221->cache_tags;
      int v2351 = v2350[v2495];
      int * v2352 = v2221->cache_vals;
      int v2499 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v2343 + ((~(((v2345 ^ -1) | (-(v2345 ^ -1))) >> 31)) & 2)) - (v2346 + ((~(((v2347 ^ -1) | (-(v2347 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v2353 = v2352[v2499];
      int v2500 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v2343 + ((~(((v2345 ^ -1) | (-(v2345 ^ -1))) >> 31)) & 2)) - (v2346 + ((~(((v2347 ^ -1) | (-(v2347 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v2354 = v2352[v2500];
      int * v2355 = v2221->mem;
      int v2502 = v2351 * 2;
      v2355[v2502] = v2353;
      int * v2357 = v2221->mem;
      int v2505 = (v2351 * 2) + 1;
      v2357[v2505] = v2354;
      ;
    } else {
      ;
    }
    int * v2362 = v2221->mem;
    int v2510 = ((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) * 2;
    int v2363 = v2362[v2510];
    int v2511 = (((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) * 2) + 1;
    int v2364 = v2362[v2511];
    int * v2365 = v2221->cache_vals;
    int v2513 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v2343 + ((~(((v2345 ^ -1) | (-(v2345 ^ -1))) >> 31)) & 2)) - (v2346 + ((~(((v2347 ^ -1) | (-(v2347 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2365[v2513] = v2363;
    int * v2367 = v2221->cache_vals;
    int v2516 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1)) & 3) * 2)) + ((((v2343 + ((~(((v2345 ^ -1) | (-(v2345 ^ -1))) >> 31)) & 2)) - (v2346 + ((~(((v2347 ^ -1) | (-(v2347 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2367[v2516] = v2364;
    int * v2369 = v2221->cache_tags;
    int v2519 = (int)((unsigned int)((int)((unsigned int)(v2225 + 16) >> 2)) >> 1);
    v2369[v2495] = v2519;
    int * v2371 = v2221->cache_dirty;
    v2371[v2495] = 0;
    int * v2373 = v2221->cache_age;
    v2373[v2495] = 1;
    int * v2375 = v2221->cache_age;
    int v2376 = v2375[v2495];
    int v2377 = v2375[v2399];
    int v2525 = v2377 + ((int)((unsigned int)(v2377 - v2376) >> 31));
    v2375[v2399] = v2525;
    int * v2379 = v2221->cache_age;
    int v2380 = v2379[v2400];
    int v2527 = v2380 + ((int)((unsigned int)(v2380 - v2376) >> 31));
    v2379[v2400] = v2527;
    int * v2382 = v2221->cache_age;
    v2382[v2495] = 0;
    v2385 = v2495;
  }
  int * v2386 = v2221->cache_vals;
  int v2530 = (v2385 * 2) + (((int)((unsigned int)(v2225 + 16) >> 2)) & 1);
  v2386[v2530] = v2226;
  int * v2388 = v2221->cache_dirty;
  v2388[v2385] = 1;
  struct StateT * v2390 = slot_9(v2221);
  return v2390;
}

struct StateT * slot_180(struct StateT * v12128) {
  int v12129 = v12128->timer;
  int v12136 = v12129 + 1;
  v12128->timer = v12136;
  int * v12131 = v12128->regs;
  int v12132 = v12131[21];
  int v12140 = (int)((unsigned int)v12132 >> 14);
  v12131[24] = v12140;
  struct StateT * v12134 = slot_181(v12128);
  return v12134;
}

struct StateT * slot_203(struct StateT * v8104) {
  int v8105 = v8104->timer;
  int v8215 = v8105 + 1;
  v8104->timer = v8215;
  int * v8107 = v8104->regs;
  int v8108 = v8107[2];
  int * v8109 = v8104->cache_tags;
  int v8219 = (((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1)) & 1) * 2;
  int v8110 = v8109[v8219];
  int v8220 = ((((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1)) & 1) * 2) + 1;
  int v8111 = v8109[v8220];
  int v8221 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1)) & 3) * 2);
  int v8112 = v8109[v8221];
  int v8222 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v8113 = v8109[v8222];
  int v8114 = v8104->timer;
  int v8223 = v8114 + ((100 ^ (((~(((v8112 ^ ((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1))) | (-(v8112 ^ ((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v8113 ^ ((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1))) | (-(v8113 ^ ((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v8110 ^ ((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1))) | (-(v8110 ^ ((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v8111 ^ ((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1))) | (-(v8111 ^ ((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v8112 ^ ((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1))) | (-(v8112 ^ ((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v8113 ^ ((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1))) | (-(v8113 ^ ((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1))))) >> 31))) & 104)))));
  v8104->timer = v8223;
  int * v8116 = v8104->cache_vals;
  bool v8224 = !(((~(((v8110 ^ ((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1))) | (-(v8110 ^ ((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v8111 ^ ((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1))) | (-(v8111 ^ ((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1))))) >> 31))) == 0);
  int v8209;
  if (v8224) {
    int * v8117 = v8104->cache_age;
    int v8226 = ((((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1)) & 1) * 2) + ((~(((v8111 ^ ((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1))) | (-(v8111 ^ ((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1))))) >> 31)) & 1);
    int v8118 = v8117[v8226];
    int v8119 = v8117[v8219];
    int v8227 = v8119 + ((int)((unsigned int)(v8119 - v8118) >> 31));
    v8117[v8219] = v8227;
    int * v8121 = v8104->cache_age;
    int v8122 = v8121[v8220];
    int v8229 = v8122 + ((int)((unsigned int)(v8122 - v8118) >> 31));
    v8121[v8220] = v8229;
    int * v8124 = v8104->cache_age;
    v8124[v8226] = 0;
    v8209 = v8226;
  } else {
    int * v8127 = v8104->cache_age;
    int v8233 = (((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1)) & 1) * 2;
    int v8128 = v8127[v8233];
    int * v8129 = v8104->cache_tags;
    int v8130 = v8129[v8233];
    int v8131 = v8127[v8220];
    int v8132 = v8129[v8220];
    bool v8235 = !(((~(((v8112 ^ ((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1))) | (-(v8112 ^ ((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1))))) >> 31)) | (~(((v8113 ^ ((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1))) | (-(v8113 ^ ((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1))))) >> 31))) == 0);
    int v8186;
    if (v8235) {
      int * v8133 = v8104->cache_age;
      int v8237 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1)) & 3) * 2)) + ((~(((v8113 ^ ((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1))) | (-(v8113 ^ ((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1))))) >> 31)) & 1);
      int v8134 = v8133[v8237];
      int v8135 = v8133[v8221];
      int v8238 = v8135 + ((int)((unsigned int)(v8135 - v8134) >> 31));
      v8133[v8221] = v8238;
      int * v8137 = v8104->cache_age;
      int v8138 = v8137[v8222];
      int v8240 = v8138 + ((int)((unsigned int)(v8138 - v8134) >> 31));
      v8137[v8222] = v8240;
      int * v8140 = v8104->cache_age;
      v8140[v8237] = 0;
      v8186 = v8237;
    } else {
      int * v8143 = v8104->cache_age;
      int v8244 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1)) & 3) * 2);
      int v8144 = v8143[v8244];
      int * v8145 = v8104->cache_tags;
      int v8146 = v8145[v8244];
      int v8147 = v8143[v8222];
      int v8148 = v8145[v8222];
      int * v8149 = v8104->cache_dirty;
      int v8247 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v8144 + ((~(((v8146 ^ -1) | (-(v8146 ^ -1))) >> 31)) & 2)) - (v8147 + ((~(((v8148 ^ -1) | (-(v8148 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v8150 = v8149[v8247];
      bool v8248 = !(v8150 == 0);
      if (v8248) {
        int * v8151 = v8104->cache_tags;
        int v8152 = v8151[v8247];
        int * v8153 = v8104->cache_vals;
        int v8251 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v8144 + ((~(((v8146 ^ -1) | (-(v8146 ^ -1))) >> 31)) & 2)) - (v8147 + ((~(((v8148 ^ -1) | (-(v8148 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v8154 = v8153[v8251];
        int v8252 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v8144 + ((~(((v8146 ^ -1) | (-(v8146 ^ -1))) >> 31)) & 2)) - (v8147 + ((~(((v8148 ^ -1) | (-(v8148 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v8155 = v8153[v8252];
        int * v8156 = v8104->mem;
        int v8254 = v8152 * 2;
        v8156[v8254] = v8154;
        int * v8158 = v8104->mem;
        int v8257 = (v8152 * 2) + 1;
        v8158[v8257] = v8155;
        ;
      } else {
        ;
      }
      int * v8163 = v8104->mem;
      int v8262 = ((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1)) * 2;
      int v8164 = v8163[v8262];
      int v8263 = (((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1)) * 2) + 1;
      int v8165 = v8163[v8263];
      int * v8166 = v8104->cache_vals;
      int v8265 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v8144 + ((~(((v8146 ^ -1) | (-(v8146 ^ -1))) >> 31)) & 2)) - (v8147 + ((~(((v8148 ^ -1) | (-(v8148 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v8166[v8265] = v8164;
      int * v8168 = v8104->cache_vals;
      int v8268 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1)) & 3) * 2)) + ((((v8144 + ((~(((v8146 ^ -1) | (-(v8146 ^ -1))) >> 31)) & 2)) - (v8147 + ((~(((v8148 ^ -1) | (-(v8148 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v8168[v8268] = v8165;
      int * v8170 = v8104->cache_tags;
      int v8271 = (int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1);
      v8170[v8247] = v8271;
      int * v8172 = v8104->cache_dirty;
      v8172[v8247] = 0;
      int * v8174 = v8104->cache_age;
      v8174[v8247] = 1;
      int * v8176 = v8104->cache_age;
      int v8177 = v8176[v8247];
      int v8178 = v8176[v8221];
      int v8277 = v8178 + ((int)((unsigned int)(v8178 - v8177) >> 31));
      v8176[v8221] = v8277;
      int * v8180 = v8104->cache_age;
      int v8181 = v8180[v8222];
      int v8279 = v8181 + ((int)((unsigned int)(v8181 - v8177) >> 31));
      v8180[v8222] = v8279;
      int * v8183 = v8104->cache_age;
      v8183[v8247] = 0;
      v8186 = v8247;
    }
    int * v8187 = v8104->cache_vals;
    int v8282 = v8186 * 2;
    int v8188 = v8187[v8282];
    int v8283 = (v8186 * 2) + 1;
    int v8189 = v8187[v8283];
    int v8284 = (((((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1)) & 1) * 2) + ((((v8128 + ((~(((v8130 ^ -1) | (-(v8130 ^ -1))) >> 31)) & 2)) - (v8131 + ((~(((v8132 ^ -1) | (-(v8132 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v8187[v8284] = v8188;
    int * v8191 = v8104->cache_vals;
    int v8287 = ((((((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1)) & 1) * 2) + ((((v8128 + ((~(((v8130 ^ -1) | (-(v8130 ^ -1))) >> 31)) & 2)) - (v8131 + ((~(((v8132 ^ -1) | (-(v8132 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v8191[v8287] = v8189;
    int * v8193 = v8104->cache_tags;
    int v8290 = ((((int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1)) & 1) * 2) + ((((v8128 + ((~(((v8130 ^ -1) | (-(v8130 ^ -1))) >> 31)) & 2)) - (v8131 + ((~(((v8132 ^ -1) | (-(v8132 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v8291 = (int)((unsigned int)((int)((unsigned int)(v8108 + 44) >> 2)) >> 1);
    v8193[v8290] = v8291;
    int * v8195 = v8104->cache_dirty;
    v8195[v8290] = 0;
    int * v8197 = v8104->cache_age;
    v8197[v8290] = 1;
    int * v8199 = v8104->cache_age;
    int v8200 = v8199[v8290];
    int v8201 = v8199[v8219];
    int v8297 = v8201 + ((int)((unsigned int)(v8201 - v8200) >> 31));
    v8199[v8219] = v8297;
    int * v8203 = v8104->cache_age;
    int v8204 = v8203[v8220];
    int v8299 = v8204 + ((int)((unsigned int)(v8204 - v8200) >> 31));
    v8203[v8220] = v8299;
    int * v8206 = v8104->cache_age;
    v8206[v8290] = 0;
    v8209 = v8290;
  }
  int v8302 = (v8209 * 2) + (((int)((unsigned int)(v8108 + 44) >> 2)) & 1);
  int v8210 = v8116[v8302];
  int * v8211 = v8104->regs;
  v8211[8] = v8210;
  struct StateT * v8213 = slot_204(v8104);
  return v8213;
}

struct StateT * slot_190(struct StateT * v12279) {
  int v12280 = v12279->timer;
  int v12288 = v12280 + 1;
  v12279->timer = v12288;
  int * v12282 = v12279->regs;
  int v12283 = v12282[29];
  int v12284 = v12282[21];
  int v12292 = v12283 ^ v12284;
  v12282[29] = v12292;
  struct StateT * v12286 = slot_191(v12279);
  return v12286;
}

struct StateT * slot_157(struct StateT * v11771) {
  int v11772 = v11771->timer;
  int v11779 = v11772 + 1;
  v11771->timer = v11779;
  int * v11774 = v11771->regs;
  int v11775 = v11774[20];
  int v11783 = (int)((unsigned int)v11775 >> 19);
  v11774[24] = v11783;
  struct StateT * v11777 = slot_158(v11771);
  return v11777;
}

struct StateT * slot_200(struct StateT * v7114) {
  int v7115 = v7114->timer;
  int v7285 = v7115 + 1;
  v7114->timer = v7285;
  int * v7117 = v7114->regs;
  int v7118 = v7117[10];
  int v7119 = v7117[5];
  int * v7120 = v7114->cache_tags;
  int v7290 = (((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1)) & 1) * 2;
  int v7121 = v7120[v7290];
  int v7291 = ((((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1)) & 1) * 2) + 1;
  int v7122 = v7120[v7291];
  int v7292 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1)) & 3) * 2);
  int v7123 = v7120[v7292];
  int v7293 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v7124 = v7120[v7293];
  int v7125 = v7114->timer;
  int v7294 = v7125 + ((100 ^ (((~(((v7123 ^ ((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1))) | (-(v7123 ^ ((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v7124 ^ ((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1))) | (-(v7124 ^ ((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v7121 ^ ((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1))) | (-(v7121 ^ ((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v7122 ^ ((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1))) | (-(v7122 ^ ((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v7123 ^ ((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1))) | (-(v7123 ^ ((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v7124 ^ ((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1))) | (-(v7124 ^ ((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1))))) >> 31))) & 104)))));
  v7114->timer = v7294;
  bool v7295 = !(((~(((v7121 ^ ((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1))) | (-(v7121 ^ ((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v7122 ^ ((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1))) | (-(v7122 ^ ((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v7219;
  if (v7295) {
    int * v7127 = v7114->cache_age;
    int v7297 = ((((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1)) & 1) * 2) + ((~(((v7122 ^ ((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1))) | (-(v7122 ^ ((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v7128 = v7127[v7297];
    int v7129 = v7127[v7290];
    int v7298 = v7129 + ((int)((unsigned int)(v7129 - v7128) >> 31));
    v7127[v7290] = v7298;
    int * v7131 = v7114->cache_age;
    int v7132 = v7131[v7291];
    int v7300 = v7132 + ((int)((unsigned int)(v7132 - v7128) >> 31));
    v7131[v7291] = v7300;
    int * v7134 = v7114->cache_age;
    v7134[v7297] = 0;
    v7219 = v7297;
  } else {
    int * v7137 = v7114->cache_age;
    int v7304 = (((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1)) & 1) * 2;
    int v7138 = v7137[v7304];
    int * v7139 = v7114->cache_tags;
    int v7140 = v7139[v7304];
    int v7141 = v7137[v7291];
    int v7142 = v7139[v7291];
    bool v7306 = !(((~(((v7123 ^ ((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1))) | (-(v7123 ^ ((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v7124 ^ ((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1))) | (-(v7124 ^ ((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1))))) >> 31))) == 0);
    int v7196;
    if (v7306) {
      int * v7143 = v7114->cache_age;
      int v7308 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7124 ^ ((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1))) | (-(v7124 ^ ((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1))))) >> 31)) & 1);
      int v7144 = v7143[v7308];
      int v7145 = v7143[v7292];
      int v7309 = v7145 + ((int)((unsigned int)(v7145 - v7144) >> 31));
      v7143[v7292] = v7309;
      int * v7147 = v7114->cache_age;
      int v7148 = v7147[v7293];
      int v7311 = v7148 + ((int)((unsigned int)(v7148 - v7144) >> 31));
      v7147[v7293] = v7311;
      int * v7150 = v7114->cache_age;
      v7150[v7308] = 0;
      v7196 = v7308;
    } else {
      int * v7153 = v7114->cache_age;
      int v7315 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1)) & 3) * 2);
      int v7154 = v7153[v7315];
      int * v7155 = v7114->cache_tags;
      int v7156 = v7155[v7315];
      int v7157 = v7153[v7293];
      int v7158 = v7155[v7293];
      int * v7159 = v7114->cache_dirty;
      int v7318 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v7154 + ((~(((v7156 ^ -1) | (-(v7156 ^ -1))) >> 31)) & 2)) - (v7157 + ((~(((v7158 ^ -1) | (-(v7158 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v7160 = v7159[v7318];
      bool v7319 = !(v7160 == 0);
      if (v7319) {
        int * v7161 = v7114->cache_tags;
        int v7162 = v7161[v7318];
        int * v7163 = v7114->cache_vals;
        int v7322 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v7154 + ((~(((v7156 ^ -1) | (-(v7156 ^ -1))) >> 31)) & 2)) - (v7157 + ((~(((v7158 ^ -1) | (-(v7158 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v7164 = v7163[v7322];
        int v7323 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v7154 + ((~(((v7156 ^ -1) | (-(v7156 ^ -1))) >> 31)) & 2)) - (v7157 + ((~(((v7158 ^ -1) | (-(v7158 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v7165 = v7163[v7323];
        int * v7166 = v7114->mem;
        int v7325 = v7162 * 2;
        v7166[v7325] = v7164;
        int * v7168 = v7114->mem;
        int v7328 = (v7162 * 2) + 1;
        v7168[v7328] = v7165;
        ;
      } else {
        ;
      }
      int * v7173 = v7114->mem;
      int v7333 = ((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1)) * 2;
      int v7174 = v7173[v7333];
      int v7334 = (((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1)) * 2) + 1;
      int v7175 = v7173[v7334];
      int * v7176 = v7114->cache_vals;
      int v7336 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v7154 + ((~(((v7156 ^ -1) | (-(v7156 ^ -1))) >> 31)) & 2)) - (v7157 + ((~(((v7158 ^ -1) | (-(v7158 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v7176[v7336] = v7174;
      int * v7178 = v7114->cache_vals;
      int v7339 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v7154 + ((~(((v7156 ^ -1) | (-(v7156 ^ -1))) >> 31)) & 2)) - (v7157 + ((~(((v7158 ^ -1) | (-(v7158 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v7178[v7339] = v7175;
      int * v7180 = v7114->cache_tags;
      int v7342 = (int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1);
      v7180[v7318] = v7342;
      int * v7182 = v7114->cache_dirty;
      v7182[v7318] = 0;
      int * v7184 = v7114->cache_age;
      v7184[v7318] = 1;
      int * v7186 = v7114->cache_age;
      int v7187 = v7186[v7318];
      int v7188 = v7186[v7292];
      int v7348 = v7188 + ((int)((unsigned int)(v7188 - v7187) >> 31));
      v7186[v7292] = v7348;
      int * v7190 = v7114->cache_age;
      int v7191 = v7190[v7293];
      int v7350 = v7191 + ((int)((unsigned int)(v7191 - v7187) >> 31));
      v7190[v7293] = v7350;
      int * v7193 = v7114->cache_age;
      v7193[v7318] = 0;
      v7196 = v7318;
    }
    int * v7197 = v7114->cache_vals;
    int v7353 = v7196 * 2;
    int v7198 = v7197[v7353];
    int v7354 = (v7196 * 2) + 1;
    int v7199 = v7197[v7354];
    int v7355 = (((((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v7138 + ((~(((v7140 ^ -1) | (-(v7140 ^ -1))) >> 31)) & 2)) - (v7141 + ((~(((v7142 ^ -1) | (-(v7142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7197[v7355] = v7198;
    int * v7201 = v7114->cache_vals;
    int v7358 = ((((((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v7138 + ((~(((v7140 ^ -1) | (-(v7140 ^ -1))) >> 31)) & 2)) - (v7141 + ((~(((v7142 ^ -1) | (-(v7142 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7201[v7358] = v7199;
    int * v7203 = v7114->cache_tags;
    int v7361 = ((((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1)) & 1) * 2) + ((((v7138 + ((~(((v7140 ^ -1) | (-(v7140 ^ -1))) >> 31)) & 2)) - (v7141 + ((~(((v7142 ^ -1) | (-(v7142 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7362 = (int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1);
    v7203[v7361] = v7362;
    int * v7205 = v7114->cache_dirty;
    v7205[v7361] = 0;
    int * v7207 = v7114->cache_age;
    v7207[v7361] = 1;
    int * v7209 = v7114->cache_age;
    int v7210 = v7209[v7361];
    int v7211 = v7209[v7290];
    int v7368 = v7211 + ((int)((unsigned int)(v7211 - v7210) >> 31));
    v7209[v7290] = v7368;
    int * v7213 = v7114->cache_age;
    int v7214 = v7213[v7291];
    int v7370 = v7214 + ((int)((unsigned int)(v7214 - v7210) >> 31));
    v7213[v7291] = v7370;
    int * v7216 = v7114->cache_age;
    v7216[v7361] = 0;
    v7219 = v7361;
  }
  int * v7220 = v7114->cache_vals;
  int v7373 = (v7219 * 2) + (((int)((unsigned int)(v7118 + 20) >> 2)) & 1);
  v7220[v7373] = v7119;
  int * v7222 = v7114->cache_tags;
  int v7223 = v7222[v7292];
  int v7224 = v7222[v7293];
  bool v7376 = !(((~(((v7223 ^ ((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1))) | (-(v7223 ^ ((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1))))) >> 31)) | (~(((v7224 ^ ((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1))) | (-(v7224 ^ ((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1))))) >> 31))) == 0);
  int v7278;
  if (v7376) {
    int * v7225 = v7114->cache_age;
    int v7378 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1)) & 3) * 2)) + ((~(((v7224 ^ ((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1))) | (-(v7224 ^ ((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1))))) >> 31)) & 1);
    int v7226 = v7225[v7378];
    int v7227 = v7225[v7292];
    int v7379 = v7227 + ((int)((unsigned int)(v7227 - v7226) >> 31));
    v7225[v7292] = v7379;
    int * v7229 = v7114->cache_age;
    int v7230 = v7229[v7293];
    int v7381 = v7230 + ((int)((unsigned int)(v7230 - v7226) >> 31));
    v7229[v7293] = v7381;
    int * v7232 = v7114->cache_age;
    v7232[v7378] = 0;
    v7278 = v7378;
  } else {
    int * v7235 = v7114->cache_age;
    int v7385 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1)) & 3) * 2);
    int v7236 = v7235[v7385];
    int * v7237 = v7114->cache_tags;
    int v7238 = v7237[v7385];
    int v7239 = v7235[v7293];
    int v7240 = v7237[v7293];
    int * v7241 = v7114->cache_dirty;
    int v7388 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v7236 + ((~(((v7238 ^ -1) | (-(v7238 ^ -1))) >> 31)) & 2)) - (v7239 + ((~(((v7240 ^ -1) | (-(v7240 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v7242 = v7241[v7388];
    bool v7389 = !(v7242 == 0);
    if (v7389) {
      int * v7243 = v7114->cache_tags;
      int v7244 = v7243[v7388];
      int * v7245 = v7114->cache_vals;
      int v7392 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v7236 + ((~(((v7238 ^ -1) | (-(v7238 ^ -1))) >> 31)) & 2)) - (v7239 + ((~(((v7240 ^ -1) | (-(v7240 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v7246 = v7245[v7392];
      int v7393 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v7236 + ((~(((v7238 ^ -1) | (-(v7238 ^ -1))) >> 31)) & 2)) - (v7239 + ((~(((v7240 ^ -1) | (-(v7240 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v7247 = v7245[v7393];
      int * v7248 = v7114->mem;
      int v7395 = v7244 * 2;
      v7248[v7395] = v7246;
      int * v7250 = v7114->mem;
      int v7398 = (v7244 * 2) + 1;
      v7250[v7398] = v7247;
      ;
    } else {
      ;
    }
    int * v7255 = v7114->mem;
    int v7403 = ((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1)) * 2;
    int v7256 = v7255[v7403];
    int v7404 = (((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1)) * 2) + 1;
    int v7257 = v7255[v7404];
    int * v7258 = v7114->cache_vals;
    int v7406 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v7236 + ((~(((v7238 ^ -1) | (-(v7238 ^ -1))) >> 31)) & 2)) - (v7239 + ((~(((v7240 ^ -1) | (-(v7240 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v7258[v7406] = v7256;
    int * v7260 = v7114->cache_vals;
    int v7409 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1)) & 3) * 2)) + ((((v7236 + ((~(((v7238 ^ -1) | (-(v7238 ^ -1))) >> 31)) & 2)) - (v7239 + ((~(((v7240 ^ -1) | (-(v7240 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v7260[v7409] = v7257;
    int * v7262 = v7114->cache_tags;
    int v7412 = (int)((unsigned int)((int)((unsigned int)(v7118 + 20) >> 2)) >> 1);
    v7262[v7388] = v7412;
    int * v7264 = v7114->cache_dirty;
    v7264[v7388] = 0;
    int * v7266 = v7114->cache_age;
    v7266[v7388] = 1;
    int * v7268 = v7114->cache_age;
    int v7269 = v7268[v7388];
    int v7270 = v7268[v7292];
    int v7418 = v7270 + ((int)((unsigned int)(v7270 - v7269) >> 31));
    v7268[v7292] = v7418;
    int * v7272 = v7114->cache_age;
    int v7273 = v7272[v7293];
    int v7420 = v7273 + ((int)((unsigned int)(v7273 - v7269) >> 31));
    v7272[v7293] = v7420;
    int * v7275 = v7114->cache_age;
    v7275[v7388] = 0;
    v7278 = v7388;
  }
  int * v7279 = v7114->cache_vals;
  int v7423 = (v7278 * 2) + (((int)((unsigned int)(v7118 + 20) >> 2)) & 1);
  v7279[v7423] = v7119;
  int * v7281 = v7114->cache_dirty;
  v7281[v7278] = 1;
  struct StateT * v7283 = slot_201(v7114);
  return v7283;
}

struct StateT * slot_173(struct StateT * v12015) {
  int v12016 = v12015->timer;
  int v12024 = v12016 + 1;
  v12015->timer = v12024;
  int * v12018 = v12015->regs;
  int v12019 = v12018[8];
  int v12020 = v12018[17];
  int v12029 = v12019 + v12020;
  v12018[20] = v12029;
  struct StateT * v12022 = slot_174(v12015);
  return v12022;
}

struct StateT * slot_149(struct StateT * v11639) {
  int v11640 = v11639->timer;
  int v11648 = v11640 + 1;
  v11639->timer = v11648;
  int * v11642 = v11639->regs;
  int v11643 = v11642[17];
  int v11644 = v11642[20];
  int v11652 = v11643 ^ v11644;
  v11642[17] = v11652;
  struct StateT * v11646 = slot_150(v11639);
  return v11646;
}

struct StateT * slot_5(struct StateT * v1276) {
  int v1277 = v1276->timer;
  int v1447 = v1277 + 1;
  v1276->timer = v1447;
  int * v1279 = v1276->regs;
  int v1280 = v1279[2];
  int v1281 = v1279[20];
  int * v1282 = v1276->cache_tags;
  int v1452 = (((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 1) * 2;
  int v1283 = v1282[v1452];
  int v1453 = ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 1) * 2) + 1;
  int v1284 = v1282[v1453];
  int v1454 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 3) * 2);
  int v1285 = v1282[v1454];
  int v1455 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v1286 = v1282[v1455];
  int v1287 = v1276->timer;
  int v1456 = v1287 + ((100 ^ (((~(((v1285 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))) | (-(v1285 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v1286 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))) | (-(v1286 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v1283 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))) | (-(v1283 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v1284 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))) | (-(v1284 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v1285 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))) | (-(v1285 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v1286 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))) | (-(v1286 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))))) >> 31))) & 104)))));
  v1276->timer = v1456;
  bool v1457 = !(((~(((v1283 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))) | (-(v1283 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v1284 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))) | (-(v1284 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v1381;
  if (v1457) {
    int * v1289 = v1276->cache_age;
    int v1459 = ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 1) * 2) + ((~(((v1284 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))) | (-(v1284 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v1290 = v1289[v1459];
    int v1291 = v1289[v1452];
    int v1460 = v1291 + ((int)((unsigned int)(v1291 - v1290) >> 31));
    v1289[v1452] = v1460;
    int * v1293 = v1276->cache_age;
    int v1294 = v1293[v1453];
    int v1462 = v1294 + ((int)((unsigned int)(v1294 - v1290) >> 31));
    v1293[v1453] = v1462;
    int * v1296 = v1276->cache_age;
    v1296[v1459] = 0;
    v1381 = v1459;
  } else {
    int * v1299 = v1276->cache_age;
    int v1466 = (((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 1) * 2;
    int v1300 = v1299[v1466];
    int * v1301 = v1276->cache_tags;
    int v1302 = v1301[v1466];
    int v1303 = v1299[v1453];
    int v1304 = v1301[v1453];
    bool v1468 = !(((~(((v1285 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))) | (-(v1285 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v1286 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))) | (-(v1286 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))))) >> 31))) == 0);
    int v1358;
    if (v1468) {
      int * v1305 = v1276->cache_age;
      int v1470 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1286 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))) | (-(v1286 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))))) >> 31)) & 1);
      int v1306 = v1305[v1470];
      int v1307 = v1305[v1454];
      int v1471 = v1307 + ((int)((unsigned int)(v1307 - v1306) >> 31));
      v1305[v1454] = v1471;
      int * v1309 = v1276->cache_age;
      int v1310 = v1309[v1455];
      int v1473 = v1310 + ((int)((unsigned int)(v1310 - v1306) >> 31));
      v1309[v1455] = v1473;
      int * v1312 = v1276->cache_age;
      v1312[v1470] = 0;
      v1358 = v1470;
    } else {
      int * v1315 = v1276->cache_age;
      int v1477 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 3) * 2);
      int v1316 = v1315[v1477];
      int * v1317 = v1276->cache_tags;
      int v1318 = v1317[v1477];
      int v1319 = v1315[v1455];
      int v1320 = v1317[v1455];
      int * v1321 = v1276->cache_dirty;
      int v1480 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v1316 + ((~(((v1318 ^ -1) | (-(v1318 ^ -1))) >> 31)) & 2)) - (v1319 + ((~(((v1320 ^ -1) | (-(v1320 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v1322 = v1321[v1480];
      bool v1481 = !(v1322 == 0);
      if (v1481) {
        int * v1323 = v1276->cache_tags;
        int v1324 = v1323[v1480];
        int * v1325 = v1276->cache_vals;
        int v1484 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v1316 + ((~(((v1318 ^ -1) | (-(v1318 ^ -1))) >> 31)) & 2)) - (v1319 + ((~(((v1320 ^ -1) | (-(v1320 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v1326 = v1325[v1484];
        int v1485 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v1316 + ((~(((v1318 ^ -1) | (-(v1318 ^ -1))) >> 31)) & 2)) - (v1319 + ((~(((v1320 ^ -1) | (-(v1320 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v1327 = v1325[v1485];
        int * v1328 = v1276->mem;
        int v1487 = v1324 * 2;
        v1328[v1487] = v1326;
        int * v1330 = v1276->mem;
        int v1490 = (v1324 * 2) + 1;
        v1330[v1490] = v1327;
        ;
      } else {
        ;
      }
      int * v1335 = v1276->mem;
      int v1495 = ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) * 2;
      int v1336 = v1335[v1495];
      int v1496 = (((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) * 2) + 1;
      int v1337 = v1335[v1496];
      int * v1338 = v1276->cache_vals;
      int v1498 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v1316 + ((~(((v1318 ^ -1) | (-(v1318 ^ -1))) >> 31)) & 2)) - (v1319 + ((~(((v1320 ^ -1) | (-(v1320 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v1338[v1498] = v1336;
      int * v1340 = v1276->cache_vals;
      int v1501 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v1316 + ((~(((v1318 ^ -1) | (-(v1318 ^ -1))) >> 31)) & 2)) - (v1319 + ((~(((v1320 ^ -1) | (-(v1320 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v1340[v1501] = v1337;
      int * v1342 = v1276->cache_tags;
      int v1504 = (int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1);
      v1342[v1480] = v1504;
      int * v1344 = v1276->cache_dirty;
      v1344[v1480] = 0;
      int * v1346 = v1276->cache_age;
      v1346[v1480] = 1;
      int * v1348 = v1276->cache_age;
      int v1349 = v1348[v1480];
      int v1350 = v1348[v1454];
      int v1510 = v1350 + ((int)((unsigned int)(v1350 - v1349) >> 31));
      v1348[v1454] = v1510;
      int * v1352 = v1276->cache_age;
      int v1353 = v1352[v1455];
      int v1512 = v1353 + ((int)((unsigned int)(v1353 - v1349) >> 31));
      v1352[v1455] = v1512;
      int * v1355 = v1276->cache_age;
      v1355[v1480] = 0;
      v1358 = v1480;
    }
    int * v1359 = v1276->cache_vals;
    int v1515 = v1358 * 2;
    int v1360 = v1359[v1515];
    int v1516 = (v1358 * 2) + 1;
    int v1361 = v1359[v1516];
    int v1517 = (((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v1300 + ((~(((v1302 ^ -1) | (-(v1302 ^ -1))) >> 31)) & 2)) - (v1303 + ((~(((v1304 ^ -1) | (-(v1304 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1359[v1517] = v1360;
    int * v1363 = v1276->cache_vals;
    int v1520 = ((((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v1300 + ((~(((v1302 ^ -1) | (-(v1302 ^ -1))) >> 31)) & 2)) - (v1303 + ((~(((v1304 ^ -1) | (-(v1304 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1363[v1520] = v1361;
    int * v1365 = v1276->cache_tags;
    int v1523 = ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 1) * 2) + ((((v1300 + ((~(((v1302 ^ -1) | (-(v1302 ^ -1))) >> 31)) & 2)) - (v1303 + ((~(((v1304 ^ -1) | (-(v1304 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1524 = (int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1);
    v1365[v1523] = v1524;
    int * v1367 = v1276->cache_dirty;
    v1367[v1523] = 0;
    int * v1369 = v1276->cache_age;
    v1369[v1523] = 1;
    int * v1371 = v1276->cache_age;
    int v1372 = v1371[v1523];
    int v1373 = v1371[v1452];
    int v1530 = v1373 + ((int)((unsigned int)(v1373 - v1372) >> 31));
    v1371[v1452] = v1530;
    int * v1375 = v1276->cache_age;
    int v1376 = v1375[v1453];
    int v1532 = v1376 + ((int)((unsigned int)(v1376 - v1372) >> 31));
    v1375[v1453] = v1532;
    int * v1378 = v1276->cache_age;
    v1378[v1523] = 0;
    v1381 = v1523;
  }
  int * v1382 = v1276->cache_vals;
  int v1535 = (v1381 * 2) + (((int)((unsigned int)(v1280 + 28) >> 2)) & 1);
  v1382[v1535] = v1281;
  int * v1384 = v1276->cache_tags;
  int v1385 = v1384[v1454];
  int v1386 = v1384[v1455];
  bool v1538 = !(((~(((v1385 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))) | (-(v1385 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))))) >> 31)) | (~(((v1386 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))) | (-(v1386 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))))) >> 31))) == 0);
  int v1440;
  if (v1538) {
    int * v1387 = v1276->cache_age;
    int v1540 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 3) * 2)) + ((~(((v1386 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))) | (-(v1386 ^ ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1))))) >> 31)) & 1);
    int v1388 = v1387[v1540];
    int v1389 = v1387[v1454];
    int v1541 = v1389 + ((int)((unsigned int)(v1389 - v1388) >> 31));
    v1387[v1454] = v1541;
    int * v1391 = v1276->cache_age;
    int v1392 = v1391[v1455];
    int v1543 = v1392 + ((int)((unsigned int)(v1392 - v1388) >> 31));
    v1391[v1455] = v1543;
    int * v1394 = v1276->cache_age;
    v1394[v1540] = 0;
    v1440 = v1540;
  } else {
    int * v1397 = v1276->cache_age;
    int v1547 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 3) * 2);
    int v1398 = v1397[v1547];
    int * v1399 = v1276->cache_tags;
    int v1400 = v1399[v1547];
    int v1401 = v1397[v1455];
    int v1402 = v1399[v1455];
    int * v1403 = v1276->cache_dirty;
    int v1550 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v1398 + ((~(((v1400 ^ -1) | (-(v1400 ^ -1))) >> 31)) & 2)) - (v1401 + ((~(((v1402 ^ -1) | (-(v1402 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v1404 = v1403[v1550];
    bool v1551 = !(v1404 == 0);
    if (v1551) {
      int * v1405 = v1276->cache_tags;
      int v1406 = v1405[v1550];
      int * v1407 = v1276->cache_vals;
      int v1554 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v1398 + ((~(((v1400 ^ -1) | (-(v1400 ^ -1))) >> 31)) & 2)) - (v1401 + ((~(((v1402 ^ -1) | (-(v1402 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v1408 = v1407[v1554];
      int v1555 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v1398 + ((~(((v1400 ^ -1) | (-(v1400 ^ -1))) >> 31)) & 2)) - (v1401 + ((~(((v1402 ^ -1) | (-(v1402 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v1409 = v1407[v1555];
      int * v1410 = v1276->mem;
      int v1557 = v1406 * 2;
      v1410[v1557] = v1408;
      int * v1412 = v1276->mem;
      int v1560 = (v1406 * 2) + 1;
      v1412[v1560] = v1409;
      ;
    } else {
      ;
    }
    int * v1417 = v1276->mem;
    int v1565 = ((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) * 2;
    int v1418 = v1417[v1565];
    int v1566 = (((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) * 2) + 1;
    int v1419 = v1417[v1566];
    int * v1420 = v1276->cache_vals;
    int v1568 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v1398 + ((~(((v1400 ^ -1) | (-(v1400 ^ -1))) >> 31)) & 2)) - (v1401 + ((~(((v1402 ^ -1) | (-(v1402 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v1420[v1568] = v1418;
    int * v1422 = v1276->cache_vals;
    int v1571 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1)) & 3) * 2)) + ((((v1398 + ((~(((v1400 ^ -1) | (-(v1400 ^ -1))) >> 31)) & 2)) - (v1401 + ((~(((v1402 ^ -1) | (-(v1402 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v1422[v1571] = v1419;
    int * v1424 = v1276->cache_tags;
    int v1574 = (int)((unsigned int)((int)((unsigned int)(v1280 + 28) >> 2)) >> 1);
    v1424[v1550] = v1574;
    int * v1426 = v1276->cache_dirty;
    v1426[v1550] = 0;
    int * v1428 = v1276->cache_age;
    v1428[v1550] = 1;
    int * v1430 = v1276->cache_age;
    int v1431 = v1430[v1550];
    int v1432 = v1430[v1454];
    int v1580 = v1432 + ((int)((unsigned int)(v1432 - v1431) >> 31));
    v1430[v1454] = v1580;
    int * v1434 = v1276->cache_age;
    int v1435 = v1434[v1455];
    int v1582 = v1435 + ((int)((unsigned int)(v1435 - v1431) >> 31));
    v1434[v1455] = v1582;
    int * v1437 = v1276->cache_age;
    v1437[v1550] = 0;
    v1440 = v1550;
  }
  int * v1441 = v1276->cache_vals;
  int v1585 = (v1440 * 2) + (((int)((unsigned int)(v1280 + 28) >> 2)) & 1);
  v1441[v1585] = v1281;
  int * v1443 = v1276->cache_dirty;
  v1443[v1440] = 1;
  struct StateT * v1445 = slot_6(v1276);
  return v1445;
}

struct StateT * slot_104(struct StateT * v10940) {
  int v10941 = v10940->timer;
  int v10948 = v10941 + 1;
  v10940->timer = v10948;
  int * v10943 = v10940->regs;
  int v10944 = v10943[22];
  int v10951 = v10944 << 18;
  v10943[22] = v10951;
  struct StateT * v10946 = slot_105(v10940);
  return v10946;
}

struct StateT * slot_54(struct StateT * v10160) {
  int v10161 = v10160->timer;
  int v10169 = v10161 + 1;
  v10160->timer = v10169;
  int * v10163 = v10160->regs;
  int v10164 = v10163[18];
  int v10165 = v10163[29];
  int v10174 = v10164 + v10165;
  v10163[21] = v10174;
  struct StateT * v10167 = slot_55(v10160);
  return v10167;
}

struct StateT * slot_26(struct StateT * v5351) {
  int v5352 = v5351->timer;
  int v5359 = v5352 + 1;
  v5351->timer = v5359;
  int * v5354 = v5351->regs;
  int v5355 = v5354[11];
  int v5363 = v5355 + -1947;
  v5354[30] = v5363;
  struct StateT * v5357 = slot_27(v5351);
  return v5357;
}

struct StateT * slot_206(struct StateT * v8761) {
  int v8762 = v8761->timer;
  int v8872 = v8762 + 1;
  v8761->timer = v8872;
  int * v8764 = v8761->regs;
  int v8765 = v8764[2];
  int * v8766 = v8761->cache_tags;
  int v8876 = (((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1)) & 1) * 2;
  int v8767 = v8766[v8876];
  int v8877 = ((((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1)) & 1) * 2) + 1;
  int v8768 = v8766[v8877];
  int v8878 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1)) & 3) * 2);
  int v8769 = v8766[v8878];
  int v8879 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v8770 = v8766[v8879];
  int v8771 = v8761->timer;
  int v8880 = v8771 + ((100 ^ (((~(((v8769 ^ ((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1))) | (-(v8769 ^ ((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v8770 ^ ((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1))) | (-(v8770 ^ ((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v8767 ^ ((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1))) | (-(v8767 ^ ((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v8768 ^ ((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1))) | (-(v8768 ^ ((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v8769 ^ ((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1))) | (-(v8769 ^ ((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v8770 ^ ((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1))) | (-(v8770 ^ ((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1))))) >> 31))) & 104)))));
  v8761->timer = v8880;
  int * v8773 = v8761->cache_vals;
  bool v8881 = !(((~(((v8767 ^ ((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1))) | (-(v8767 ^ ((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v8768 ^ ((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1))) | (-(v8768 ^ ((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1))))) >> 31))) == 0);
  int v8866;
  if (v8881) {
    int * v8774 = v8761->cache_age;
    int v8883 = ((((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1)) & 1) * 2) + ((~(((v8768 ^ ((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1))) | (-(v8768 ^ ((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1))))) >> 31)) & 1);
    int v8775 = v8774[v8883];
    int v8776 = v8774[v8876];
    int v8884 = v8776 + ((int)((unsigned int)(v8776 - v8775) >> 31));
    v8774[v8876] = v8884;
    int * v8778 = v8761->cache_age;
    int v8779 = v8778[v8877];
    int v8886 = v8779 + ((int)((unsigned int)(v8779 - v8775) >> 31));
    v8778[v8877] = v8886;
    int * v8781 = v8761->cache_age;
    v8781[v8883] = 0;
    v8866 = v8883;
  } else {
    int * v8784 = v8761->cache_age;
    int v8890 = (((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1)) & 1) * 2;
    int v8785 = v8784[v8890];
    int * v8786 = v8761->cache_tags;
    int v8787 = v8786[v8890];
    int v8788 = v8784[v8877];
    int v8789 = v8786[v8877];
    bool v8892 = !(((~(((v8769 ^ ((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1))) | (-(v8769 ^ ((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1))))) >> 31)) | (~(((v8770 ^ ((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1))) | (-(v8770 ^ ((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1))))) >> 31))) == 0);
    int v8843;
    if (v8892) {
      int * v8790 = v8761->cache_age;
      int v8894 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1)) & 3) * 2)) + ((~(((v8770 ^ ((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1))) | (-(v8770 ^ ((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1))))) >> 31)) & 1);
      int v8791 = v8790[v8894];
      int v8792 = v8790[v8878];
      int v8895 = v8792 + ((int)((unsigned int)(v8792 - v8791) >> 31));
      v8790[v8878] = v8895;
      int * v8794 = v8761->cache_age;
      int v8795 = v8794[v8879];
      int v8897 = v8795 + ((int)((unsigned int)(v8795 - v8791) >> 31));
      v8794[v8879] = v8897;
      int * v8797 = v8761->cache_age;
      v8797[v8894] = 0;
      v8843 = v8894;
    } else {
      int * v8800 = v8761->cache_age;
      int v8901 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1)) & 3) * 2);
      int v8801 = v8800[v8901];
      int * v8802 = v8761->cache_tags;
      int v8803 = v8802[v8901];
      int v8804 = v8800[v8879];
      int v8805 = v8802[v8879];
      int * v8806 = v8761->cache_dirty;
      int v8904 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v8801 + ((~(((v8803 ^ -1) | (-(v8803 ^ -1))) >> 31)) & 2)) - (v8804 + ((~(((v8805 ^ -1) | (-(v8805 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v8807 = v8806[v8904];
      bool v8905 = !(v8807 == 0);
      if (v8905) {
        int * v8808 = v8761->cache_tags;
        int v8809 = v8808[v8904];
        int * v8810 = v8761->cache_vals;
        int v8908 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v8801 + ((~(((v8803 ^ -1) | (-(v8803 ^ -1))) >> 31)) & 2)) - (v8804 + ((~(((v8805 ^ -1) | (-(v8805 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v8811 = v8810[v8908];
        int v8909 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v8801 + ((~(((v8803 ^ -1) | (-(v8803 ^ -1))) >> 31)) & 2)) - (v8804 + ((~(((v8805 ^ -1) | (-(v8805 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v8812 = v8810[v8909];
        int * v8813 = v8761->mem;
        int v8911 = v8809 * 2;
        v8813[v8911] = v8811;
        int * v8815 = v8761->mem;
        int v8914 = (v8809 * 2) + 1;
        v8815[v8914] = v8812;
        ;
      } else {
        ;
      }
      int * v8820 = v8761->mem;
      int v8919 = ((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1)) * 2;
      int v8821 = v8820[v8919];
      int v8920 = (((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1)) * 2) + 1;
      int v8822 = v8820[v8920];
      int * v8823 = v8761->cache_vals;
      int v8922 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v8801 + ((~(((v8803 ^ -1) | (-(v8803 ^ -1))) >> 31)) & 2)) - (v8804 + ((~(((v8805 ^ -1) | (-(v8805 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v8823[v8922] = v8821;
      int * v8825 = v8761->cache_vals;
      int v8925 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1)) & 3) * 2)) + ((((v8801 + ((~(((v8803 ^ -1) | (-(v8803 ^ -1))) >> 31)) & 2)) - (v8804 + ((~(((v8805 ^ -1) | (-(v8805 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v8825[v8925] = v8822;
      int * v8827 = v8761->cache_tags;
      int v8928 = (int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1);
      v8827[v8904] = v8928;
      int * v8829 = v8761->cache_dirty;
      v8829[v8904] = 0;
      int * v8831 = v8761->cache_age;
      v8831[v8904] = 1;
      int * v8833 = v8761->cache_age;
      int v8834 = v8833[v8904];
      int v8835 = v8833[v8878];
      int v8934 = v8835 + ((int)((unsigned int)(v8835 - v8834) >> 31));
      v8833[v8878] = v8934;
      int * v8837 = v8761->cache_age;
      int v8838 = v8837[v8879];
      int v8936 = v8838 + ((int)((unsigned int)(v8838 - v8834) >> 31));
      v8837[v8879] = v8936;
      int * v8840 = v8761->cache_age;
      v8840[v8904] = 0;
      v8843 = v8904;
    }
    int * v8844 = v8761->cache_vals;
    int v8939 = v8843 * 2;
    int v8845 = v8844[v8939];
    int v8940 = (v8843 * 2) + 1;
    int v8846 = v8844[v8940];
    int v8941 = (((((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v8785 + ((~(((v8787 ^ -1) | (-(v8787 ^ -1))) >> 31)) & 2)) - (v8788 + ((~(((v8789 ^ -1) | (-(v8789 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v8844[v8941] = v8845;
    int * v8848 = v8761->cache_vals;
    int v8944 = ((((((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v8785 + ((~(((v8787 ^ -1) | (-(v8787 ^ -1))) >> 31)) & 2)) - (v8788 + ((~(((v8789 ^ -1) | (-(v8789 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v8848[v8944] = v8846;
    int * v8850 = v8761->cache_tags;
    int v8947 = ((((int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1)) & 1) * 2) + ((((v8785 + ((~(((v8787 ^ -1) | (-(v8787 ^ -1))) >> 31)) & 2)) - (v8788 + ((~(((v8789 ^ -1) | (-(v8789 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v8948 = (int)((unsigned int)((int)((unsigned int)(v8765 + 32) >> 2)) >> 1);
    v8850[v8947] = v8948;
    int * v8852 = v8761->cache_dirty;
    v8852[v8947] = 0;
    int * v8854 = v8761->cache_age;
    v8854[v8947] = 1;
    int * v8856 = v8761->cache_age;
    int v8857 = v8856[v8947];
    int v8858 = v8856[v8876];
    int v8954 = v8858 + ((int)((unsigned int)(v8858 - v8857) >> 31));
    v8856[v8876] = v8954;
    int * v8860 = v8761->cache_age;
    int v8861 = v8860[v8877];
    int v8956 = v8861 + ((int)((unsigned int)(v8861 - v8857) >> 31));
    v8860[v8877] = v8956;
    int * v8863 = v8761->cache_age;
    v8863[v8947] = 0;
    v8866 = v8947;
  }
  int v8959 = (v8866 * 2) + (((int)((unsigned int)(v8765 + 32) >> 2)) & 1);
  int v8867 = v8773[v8959];
  int * v8868 = v8761->regs;
  v8868[19] = v8867;
  struct StateT * v8870 = slot_207(v8761);
  return v8870;
}

struct StateT * slot_169(struct StateT * v11951) {
  int v11952 = v11951->timer;
  int v11960 = v11952 + 1;
  v11951->timer = v11960;
  int * v11954 = v11951->regs;
  int v11955 = v11954[8];
  int v11956 = v11954[20];
  int v11964 = v11955 ^ v11956;
  v11954[8] = v11964;
  struct StateT * v11958 = slot_170(v11951);
  return v11958;
}

struct StateT * slot_64(struct StateT * v10316) {
  int v10317 = v10316->timer;
  int v10324 = v10317 + 1;
  v10316->timer = v10324;
  int * v10319 = v10316->regs;
  int v10320 = v10319[22];
  int v10327 = v10320 << 9;
  v10319[22] = v10327;
  struct StateT * v10322 = slot_65(v10316);
  return v10322;
}

struct StateT * slot_170(struct StateT * v11967) {
  int v11968 = v11967->timer;
  int v11976 = v11968 + 1;
  v11967->timer = v11976;
  int * v11970 = v11967->regs;
  int v11971 = v11970[9];
  int v11972 = v11970[21];
  int v11980 = v11971 ^ v11972;
  v11970[9] = v11980;
  struct StateT * v11974 = slot_171(v11967);
  return v11974;
}

struct StateT * slot_14(struct StateT * v3476) {
  int v3477 = v3476->timer;
  int v3587 = v3477 + 1;
  v3476->timer = v3587;
  int * v3479 = v3476->regs;
  int v3480 = v3479[12];
  int * v3481 = v3476->cache_tags;
  int v3591 = (((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1)) & 1) * 2;
  int v3482 = v3481[v3591];
  int v3592 = ((((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v3483 = v3481[v3592];
  int v3593 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1)) & 3) * 2);
  int v3484 = v3481[v3593];
  int v3594 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3485 = v3481[v3594];
  int v3486 = v3476->timer;
  int v3595 = v3486 + ((100 ^ (((~(((v3484 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))) | (-(v3484 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v3485 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))) | (-(v3485 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3482 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))) | (-(v3482 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v3483 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))) | (-(v3483 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3484 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))) | (-(v3484 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v3485 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))) | (-(v3485 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v3476->timer = v3595;
  int * v3488 = v3476->cache_vals;
  bool v3596 = !(((~(((v3482 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))) | (-(v3482 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v3483 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))) | (-(v3483 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v3581;
  if (v3596) {
    int * v3489 = v3476->cache_age;
    int v3598 = ((((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v3483 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))) | (-(v3483 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v3490 = v3489[v3598];
    int v3491 = v3489[v3591];
    int v3599 = v3491 + ((int)((unsigned int)(v3491 - v3490) >> 31));
    v3489[v3591] = v3599;
    int * v3493 = v3476->cache_age;
    int v3494 = v3493[v3592];
    int v3601 = v3494 + ((int)((unsigned int)(v3494 - v3490) >> 31));
    v3493[v3592] = v3601;
    int * v3496 = v3476->cache_age;
    v3496[v3598] = 0;
    v3581 = v3598;
  } else {
    int * v3499 = v3476->cache_age;
    int v3605 = (((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1)) & 1) * 2;
    int v3500 = v3499[v3605];
    int * v3501 = v3476->cache_tags;
    int v3502 = v3501[v3605];
    int v3503 = v3499[v3592];
    int v3504 = v3501[v3592];
    bool v3607 = !(((~(((v3484 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))) | (-(v3484 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v3485 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))) | (-(v3485 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v3558;
    if (v3607) {
      int * v3505 = v3476->cache_age;
      int v3609 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3485 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))) | (-(v3485 ^ ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v3506 = v3505[v3609];
      int v3507 = v3505[v3593];
      int v3610 = v3507 + ((int)((unsigned int)(v3507 - v3506) >> 31));
      v3505[v3593] = v3610;
      int * v3509 = v3476->cache_age;
      int v3510 = v3509[v3594];
      int v3612 = v3510 + ((int)((unsigned int)(v3510 - v3506) >> 31));
      v3509[v3594] = v3612;
      int * v3512 = v3476->cache_age;
      v3512[v3609] = 0;
      v3558 = v3609;
    } else {
      int * v3515 = v3476->cache_age;
      int v3616 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1)) & 3) * 2);
      int v3516 = v3515[v3616];
      int * v3517 = v3476->cache_tags;
      int v3518 = v3517[v3616];
      int v3519 = v3515[v3594];
      int v3520 = v3517[v3594];
      int * v3521 = v3476->cache_dirty;
      int v3619 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3516 + ((~(((v3518 ^ -1) | (-(v3518 ^ -1))) >> 31)) & 2)) - (v3519 + ((~(((v3520 ^ -1) | (-(v3520 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3522 = v3521[v3619];
      bool v3620 = !(v3522 == 0);
      if (v3620) {
        int * v3523 = v3476->cache_tags;
        int v3524 = v3523[v3619];
        int * v3525 = v3476->cache_vals;
        int v3623 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3516 + ((~(((v3518 ^ -1) | (-(v3518 ^ -1))) >> 31)) & 2)) - (v3519 + ((~(((v3520 ^ -1) | (-(v3520 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3526 = v3525[v3623];
        int v3624 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3516 + ((~(((v3518 ^ -1) | (-(v3518 ^ -1))) >> 31)) & 2)) - (v3519 + ((~(((v3520 ^ -1) | (-(v3520 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3527 = v3525[v3624];
        int * v3528 = v3476->mem;
        int v3626 = v3524 * 2;
        v3528[v3626] = v3526;
        int * v3530 = v3476->mem;
        int v3629 = (v3524 * 2) + 1;
        v3530[v3629] = v3527;
        ;
      } else {
        ;
      }
      int * v3535 = v3476->mem;
      int v3634 = ((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1)) * 2;
      int v3536 = v3535[v3634];
      int v3635 = (((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1)) * 2) + 1;
      int v3537 = v3535[v3635];
      int * v3538 = v3476->cache_vals;
      int v3637 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3516 + ((~(((v3518 ^ -1) | (-(v3518 ^ -1))) >> 31)) & 2)) - (v3519 + ((~(((v3520 ^ -1) | (-(v3520 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3538[v3637] = v3536;
      int * v3540 = v3476->cache_vals;
      int v3640 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v3516 + ((~(((v3518 ^ -1) | (-(v3518 ^ -1))) >> 31)) & 2)) - (v3519 + ((~(((v3520 ^ -1) | (-(v3520 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3540[v3640] = v3537;
      int * v3542 = v3476->cache_tags;
      int v3643 = (int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1);
      v3542[v3619] = v3643;
      int * v3544 = v3476->cache_dirty;
      v3544[v3619] = 0;
      int * v3546 = v3476->cache_age;
      v3546[v3619] = 1;
      int * v3548 = v3476->cache_age;
      int v3549 = v3548[v3619];
      int v3550 = v3548[v3593];
      int v3649 = v3550 + ((int)((unsigned int)(v3550 - v3549) >> 31));
      v3548[v3593] = v3649;
      int * v3552 = v3476->cache_age;
      int v3553 = v3552[v3594];
      int v3651 = v3553 + ((int)((unsigned int)(v3553 - v3549) >> 31));
      v3552[v3594] = v3651;
      int * v3555 = v3476->cache_age;
      v3555[v3619] = 0;
      v3558 = v3619;
    }
    int * v3559 = v3476->cache_vals;
    int v3654 = v3558 * 2;
    int v3560 = v3559[v3654];
    int v3655 = (v3558 * 2) + 1;
    int v3561 = v3559[v3655];
    int v3656 = (((((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v3500 + ((~(((v3502 ^ -1) | (-(v3502 ^ -1))) >> 31)) & 2)) - (v3503 + ((~(((v3504 ^ -1) | (-(v3504 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3559[v3656] = v3560;
    int * v3563 = v3476->cache_vals;
    int v3659 = ((((((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v3500 + ((~(((v3502 ^ -1) | (-(v3502 ^ -1))) >> 31)) & 2)) - (v3503 + ((~(((v3504 ^ -1) | (-(v3504 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3563[v3659] = v3561;
    int * v3565 = v3476->cache_tags;
    int v3662 = ((((int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v3500 + ((~(((v3502 ^ -1) | (-(v3502 ^ -1))) >> 31)) & 2)) - (v3503 + ((~(((v3504 ^ -1) | (-(v3504 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3663 = (int)((unsigned int)((int)((unsigned int)(v3480 + 12) >> 2)) >> 1);
    v3565[v3662] = v3663;
    int * v3567 = v3476->cache_dirty;
    v3567[v3662] = 0;
    int * v3569 = v3476->cache_age;
    v3569[v3662] = 1;
    int * v3571 = v3476->cache_age;
    int v3572 = v3571[v3662];
    int v3573 = v3571[v3591];
    int v3669 = v3573 + ((int)((unsigned int)(v3573 - v3572) >> 31));
    v3571[v3591] = v3669;
    int * v3575 = v3476->cache_age;
    int v3576 = v3575[v3592];
    int v3671 = v3576 + ((int)((unsigned int)(v3576 - v3572) >> 31));
    v3575[v3592] = v3671;
    int * v3578 = v3476->cache_age;
    v3578[v3662] = 0;
    v3581 = v3662;
  }
  int v3674 = (v3581 * 2) + (((int)((unsigned int)(v3480 + 12) >> 2)) & 1);
  int v3582 = v3488[v3674];
  int * v3583 = v3476->regs;
  v3583[9] = v3582;
  struct StateT * v3585 = slot_15(v3476);
  return v3585;
}

struct StateT * slot_53(struct StateT * v10143) {
  int v10144 = v10143->timer;
  int v10152 = v10144 + 1;
  v10143->timer = v10152;
  int * v10146 = v10143->regs;
  int v10147 = v10146[9];
  int v10148 = v10146[30];
  int v10157 = v10147 + v10148;
  v10146[20] = v10157;
  struct StateT * v10150 = slot_54(v10143);
  return v10150;
}

struct StateT * slot_80(struct StateT * v10568) {
  int v10569 = v10568->timer;
  int v10576 = v10569 + 1;
  v10568->timer = v10576;
  int * v10571 = v10568->regs;
  int v10572 = v10571[21];
  int v10580 = (int)((unsigned int)v10572 >> 19);
  v10571[24] = v10580;
  struct StateT * v10574 = slot_81(v10568);
  return v10574;
}

struct StateT * slot_44(struct StateT * v8965) {
  int v8966 = v8965->timer;
  int v8973 = v8966 + 1;
  v8965->timer = v8973;
  int * v8968 = v8965->regs;
  int v8969 = v8968[22];
  int v8976 = v8969 << 7;
  v8968[22] = v8976;
  struct StateT * v8971 = slot_45(v8965);
  return v8971;
}

struct StateT * slot_137(struct StateT * v11459) {
  int v11460 = v11459->timer;
  int v11467 = v11460 + 1;
  v11459->timer = v11467;
  int * v11462 = v11459->regs;
  int v11463 = v11462[20];
  int v11471 = (int)((unsigned int)v11463 >> 23);
  v11462[24] = v11471;
  struct StateT * v11465 = slot_138(v11459);
  return v11465;
}

struct StateT * slot_122(struct StateT * v11221) {
  int v11222 = v11221->timer;
  int v11230 = v11222 + 1;
  v11221->timer = v11230;
  int * v11224 = v11221->regs;
  int v11225 = v11224[21];
  int v11226 = v11224[24];
  int v11234 = v11225 | v11226;
  v11224[21] = v11234;
  struct StateT * v11228 = slot_123(v11221);
  return v11228;
}

struct StateT * slot_99(struct StateT * v10864) {
  int v10865 = v10864->timer;
  int v10873 = v10865 + 1;
  v10864->timer = v10873;
  int * v10867 = v10864->regs;
  int v10868 = v10867[20];
  int v10869 = v10867[24];
  int v10877 = v10868 | v10869;
  v10867[20] = v10877;
  struct StateT * v10871 = slot_100(v10864);
  return v10871;
}

struct StateT * slot_179(struct StateT * v12112) {
  int v12113 = v12112->timer;
  int v12121 = v12113 + 1;
  v12112->timer = v12121;
  int * v12115 = v12112->regs;
  int v12116 = v12115[20];
  int v12117 = v12115[24];
  int v12125 = v12116 | v12117;
  v12115[20] = v12125;
  struct StateT * v12119 = slot_180(v12112);
  return v12119;
}

struct StateT * slot_36(struct StateT * v6767) {
  int v6768 = v6767->timer;
  int v6776 = v6768 + 1;
  v6767->timer = v6776;
  int * v6770 = v6767->regs;
  int v6771 = v6770[31];
  int v6772 = v6770[15];
  int v6781 = v6771 + v6772;
  v6770[23] = v6781;
  struct StateT * v6774 = slot_37(v6767);
  return v6774;
}

struct StateT * slot_57(struct StateT * v10211) {
  int v10212 = v10211->timer;
  int v10219 = v10212 + 1;
  v10211->timer = v10219;
  int * v10214 = v10211->regs;
  int v10215 = v10214[20];
  int v10223 = (int)((unsigned int)v10215 >> 23);
  v10214[24] = v10223;
  struct StateT * v10217 = slot_58(v10211);
  return v10217;
}

struct StateT * slot_62(struct StateT * v10285) {
  int v10286 = v10285->timer;
  int v10294 = v10286 + 1;
  v10285->timer = v10294;
  int * v10288 = v10285->regs;
  int v10289 = v10288[21];
  int v10290 = v10288[24];
  int v10298 = v10289 | v10290;
  v10288[21] = v10298;
  struct StateT * v10292 = slot_63(v10285);
  return v10292;
}

struct StateT * slot_22(struct StateT * v5108) {
  int v5109 = v5108->timer;
  int v5219 = v5109 + 1;
  v5108->timer = v5219;
  int * v5111 = v5108->regs;
  int v5112 = v5111[11];
  int * v5113 = v5108->cache_tags;
  int v5223 = (((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1)) & 1) * 2;
  int v5114 = v5113[v5223];
  int v5224 = ((((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1)) & 1) * 2) + 1;
  int v5115 = v5113[v5224];
  int v5225 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1)) & 3) * 2);
  int v5116 = v5113[v5225];
  int v5226 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v5117 = v5113[v5226];
  int v5118 = v5108->timer;
  int v5227 = v5118 + ((100 ^ (((~(((v5116 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))) | (-(v5116 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v5117 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))) | (-(v5117 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v5114 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))) | (-(v5114 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v5115 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))) | (-(v5115 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v5116 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))) | (-(v5116 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v5117 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))) | (-(v5117 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))))) >> 31))) & 104)))));
  v5108->timer = v5227;
  int * v5120 = v5108->cache_vals;
  bool v5228 = !(((~(((v5114 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))) | (-(v5114 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v5115 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))) | (-(v5115 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))))) >> 31))) == 0);
  int v5213;
  if (v5228) {
    int * v5121 = v5108->cache_age;
    int v5230 = ((((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1)) & 1) * 2) + ((~(((v5115 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))) | (-(v5115 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))))) >> 31)) & 1);
    int v5122 = v5121[v5230];
    int v5123 = v5121[v5223];
    int v5231 = v5123 + ((int)((unsigned int)(v5123 - v5122) >> 31));
    v5121[v5223] = v5231;
    int * v5125 = v5108->cache_age;
    int v5126 = v5125[v5224];
    int v5233 = v5126 + ((int)((unsigned int)(v5126 - v5122) >> 31));
    v5125[v5224] = v5233;
    int * v5128 = v5108->cache_age;
    v5128[v5230] = 0;
    v5213 = v5230;
  } else {
    int * v5131 = v5108->cache_age;
    int v5237 = (((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1)) & 1) * 2;
    int v5132 = v5131[v5237];
    int * v5133 = v5108->cache_tags;
    int v5134 = v5133[v5237];
    int v5135 = v5131[v5224];
    int v5136 = v5133[v5224];
    bool v5239 = !(((~(((v5116 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))) | (-(v5116 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))))) >> 31)) | (~(((v5117 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))) | (-(v5117 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))))) >> 31))) == 0);
    int v5190;
    if (v5239) {
      int * v5137 = v5108->cache_age;
      int v5241 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1)) & 3) * 2)) + ((~(((v5117 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))) | (-(v5117 ^ ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1))))) >> 31)) & 1);
      int v5138 = v5137[v5241];
      int v5139 = v5137[v5225];
      int v5242 = v5139 + ((int)((unsigned int)(v5139 - v5138) >> 31));
      v5137[v5225] = v5242;
      int * v5141 = v5108->cache_age;
      int v5142 = v5141[v5226];
      int v5244 = v5142 + ((int)((unsigned int)(v5142 - v5138) >> 31));
      v5141[v5226] = v5244;
      int * v5144 = v5108->cache_age;
      v5144[v5241] = 0;
      v5190 = v5241;
    } else {
      int * v5147 = v5108->cache_age;
      int v5248 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1)) & 3) * 2);
      int v5148 = v5147[v5248];
      int * v5149 = v5108->cache_tags;
      int v5150 = v5149[v5248];
      int v5151 = v5147[v5226];
      int v5152 = v5149[v5226];
      int * v5153 = v5108->cache_dirty;
      int v5251 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v5148 + ((~(((v5150 ^ -1) | (-(v5150 ^ -1))) >> 31)) & 2)) - (v5151 + ((~(((v5152 ^ -1) | (-(v5152 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v5154 = v5153[v5251];
      bool v5252 = !(v5154 == 0);
      if (v5252) {
        int * v5155 = v5108->cache_tags;
        int v5156 = v5155[v5251];
        int * v5157 = v5108->cache_vals;
        int v5255 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v5148 + ((~(((v5150 ^ -1) | (-(v5150 ^ -1))) >> 31)) & 2)) - (v5151 + ((~(((v5152 ^ -1) | (-(v5152 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v5158 = v5157[v5255];
        int v5256 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v5148 + ((~(((v5150 ^ -1) | (-(v5150 ^ -1))) >> 31)) & 2)) - (v5151 + ((~(((v5152 ^ -1) | (-(v5152 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v5159 = v5157[v5256];
        int * v5160 = v5108->mem;
        int v5258 = v5156 * 2;
        v5160[v5258] = v5158;
        int * v5162 = v5108->mem;
        int v5261 = (v5156 * 2) + 1;
        v5162[v5261] = v5159;
        ;
      } else {
        ;
      }
      int * v5167 = v5108->mem;
      int v5266 = ((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1)) * 2;
      int v5168 = v5167[v5266];
      int v5267 = (((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1)) * 2) + 1;
      int v5169 = v5167[v5267];
      int * v5170 = v5108->cache_vals;
      int v5269 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v5148 + ((~(((v5150 ^ -1) | (-(v5150 ^ -1))) >> 31)) & 2)) - (v5151 + ((~(((v5152 ^ -1) | (-(v5152 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v5170[v5269] = v5168;
      int * v5172 = v5108->cache_vals;
      int v5272 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1)) & 3) * 2)) + ((((v5148 + ((~(((v5150 ^ -1) | (-(v5150 ^ -1))) >> 31)) & 2)) - (v5151 + ((~(((v5152 ^ -1) | (-(v5152 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v5172[v5272] = v5169;
      int * v5174 = v5108->cache_tags;
      int v5275 = (int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1);
      v5174[v5251] = v5275;
      int * v5176 = v5108->cache_dirty;
      v5176[v5251] = 0;
      int * v5178 = v5108->cache_age;
      v5178[v5251] = 1;
      int * v5180 = v5108->cache_age;
      int v5181 = v5180[v5251];
      int v5182 = v5180[v5225];
      int v5281 = v5182 + ((int)((unsigned int)(v5182 - v5181) >> 31));
      v5180[v5225] = v5281;
      int * v5184 = v5108->cache_age;
      int v5185 = v5184[v5226];
      int v5283 = v5185 + ((int)((unsigned int)(v5185 - v5181) >> 31));
      v5184[v5226] = v5283;
      int * v5187 = v5108->cache_age;
      v5187[v5251] = 0;
      v5190 = v5251;
    }
    int * v5191 = v5108->cache_vals;
    int v5286 = v5190 * 2;
    int v5192 = v5191[v5286];
    int v5287 = (v5190 * 2) + 1;
    int v5193 = v5191[v5287];
    int v5288 = (((((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v5132 + ((~(((v5134 ^ -1) | (-(v5134 ^ -1))) >> 31)) & 2)) - (v5135 + ((~(((v5136 ^ -1) | (-(v5136 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v5191[v5288] = v5192;
    int * v5195 = v5108->cache_vals;
    int v5291 = ((((((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v5132 + ((~(((v5134 ^ -1) | (-(v5134 ^ -1))) >> 31)) & 2)) - (v5135 + ((~(((v5136 ^ -1) | (-(v5136 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v5195[v5291] = v5193;
    int * v5197 = v5108->cache_tags;
    int v5294 = ((((int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1)) & 1) * 2) + ((((v5132 + ((~(((v5134 ^ -1) | (-(v5134 ^ -1))) >> 31)) & 2)) - (v5135 + ((~(((v5136 ^ -1) | (-(v5136 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v5295 = (int)((unsigned int)((int)((unsigned int)(v5112 + 12) >> 2)) >> 1);
    v5197[v5294] = v5295;
    int * v5199 = v5108->cache_dirty;
    v5199[v5294] = 0;
    int * v5201 = v5108->cache_age;
    v5201[v5294] = 1;
    int * v5203 = v5108->cache_age;
    int v5204 = v5203[v5294];
    int v5205 = v5203[v5223];
    int v5301 = v5205 + ((int)((unsigned int)(v5205 - v5204) >> 31));
    v5203[v5223] = v5301;
    int * v5207 = v5108->cache_age;
    int v5208 = v5207[v5224];
    int v5303 = v5208 + ((int)((unsigned int)(v5208 - v5204) >> 31));
    v5207[v5224] = v5303;
    int * v5210 = v5108->cache_age;
    v5210[v5294] = 0;
    v5213 = v5294;
  }
  int v5306 = (v5213 * 2) + (((int)((unsigned int)(v5112 + 12) >> 2)) & 1);
  int v5214 = v5120[v5306];
  int * v5215 = v5108->regs;
  v5215[18] = v5214;
  struct StateT * v5217 = slot_23(v5108);
  return v5217;
}

struct StateT * slot_139(struct StateT * v11488) {
  int v11489 = v11488->timer;
  int v11497 = v11489 + 1;
  v11488->timer = v11497;
  int * v11491 = v11488->regs;
  int v11492 = v11491[20];
  int v11493 = v11491[24];
  int v11501 = v11492 | v11493;
  v11491[20] = v11501;
  struct StateT * v11495 = slot_140(v11488);
  return v11495;
}

struct StateT * slot_23(struct StateT * v5312) {
  int v5313 = v5312->timer;
  int v5319 = v5313 + 1;
  v5312->timer = v5319;
  int * v5315 = v5312->regs;
  v5315[11] = 1634762752;
  struct StateT * v5317 = slot_24(v5312);
  return v5317;
}

struct StateT * slot_153(struct StateT * v11703) {
  int v11704 = v11703->timer;
  int v11712 = v11704 + 1;
  v11703->timer = v11712;
  int * v11706 = v11703->regs;
  int v11707 = v11706[17];
  int v11708 = v11706[14];
  int v11717 = v11707 + v11708;
  v11706[20] = v11717;
  struct StateT * v11710 = slot_154(v11703);
  return v11710;
}

struct StateT * slot_2(struct StateT * v331) {
  int v332 = v331->timer;
  int v502 = v332 + 1;
  v331->timer = v502;
  int * v334 = v331->regs;
  int v335 = v334[2];
  int v336 = v334[9];
  int * v337 = v331->cache_tags;
  int v507 = (((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 1) * 2;
  int v338 = v337[v507];
  int v508 = ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 1) * 2) + 1;
  int v339 = v337[v508];
  int v509 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 3) * 2);
  int v340 = v337[v509];
  int v510 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v341 = v337[v510];
  int v342 = v331->timer;
  int v511 = v342 + ((100 ^ (((~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v338 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))) | (-(v338 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))))) >> 31))) & 104)))));
  v331->timer = v511;
  bool v512 = !(((~(((v338 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))) | (-(v338 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))))) >> 31))) == 0);
  int v436;
  if (v512) {
    int * v344 = v331->cache_age;
    int v514 = ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 1) * 2) + ((~(((v339 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))) | (-(v339 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))))) >> 31)) & 1);
    int v345 = v344[v514];
    int v346 = v344[v507];
    int v515 = v346 + ((int)((unsigned int)(v346 - v345) >> 31));
    v344[v507] = v515;
    int * v348 = v331->cache_age;
    int v349 = v348[v508];
    int v517 = v349 + ((int)((unsigned int)(v349 - v345) >> 31));
    v348[v508] = v517;
    int * v351 = v331->cache_age;
    v351[v514] = 0;
    v436 = v514;
  } else {
    int * v354 = v331->cache_age;
    int v521 = (((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 1) * 2;
    int v355 = v354[v521];
    int * v356 = v331->cache_tags;
    int v357 = v356[v521];
    int v358 = v354[v508];
    int v359 = v356[v508];
    bool v523 = !(((~(((v340 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))) | (-(v340 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))))) >> 31))) == 0);
    int v413;
    if (v523) {
      int * v360 = v331->cache_age;
      int v525 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 3) * 2)) + ((~(((v341 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))) | (-(v341 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))))) >> 31)) & 1);
      int v361 = v360[v525];
      int v362 = v360[v509];
      int v526 = v362 + ((int)((unsigned int)(v362 - v361) >> 31));
      v360[v509] = v526;
      int * v364 = v331->cache_age;
      int v365 = v364[v510];
      int v528 = v365 + ((int)((unsigned int)(v365 - v361) >> 31));
      v364[v510] = v528;
      int * v367 = v331->cache_age;
      v367[v525] = 0;
      v413 = v525;
    } else {
      int * v370 = v331->cache_age;
      int v532 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 3) * 2);
      int v371 = v370[v532];
      int * v372 = v331->cache_tags;
      int v373 = v372[v532];
      int v374 = v370[v510];
      int v375 = v372[v510];
      int * v376 = v331->cache_dirty;
      int v535 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v371 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2)) - (v374 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v377 = v376[v535];
      bool v536 = !(v377 == 0);
      if (v536) {
        int * v378 = v331->cache_tags;
        int v379 = v378[v535];
        int * v380 = v331->cache_vals;
        int v539 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v371 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2)) - (v374 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v381 = v380[v539];
        int v540 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v371 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2)) - (v374 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v382 = v380[v540];
        int * v383 = v331->mem;
        int v542 = v379 * 2;
        v383[v542] = v381;
        int * v385 = v331->mem;
        int v545 = (v379 * 2) + 1;
        v385[v545] = v382;
        ;
      } else {
        ;
      }
      int * v390 = v331->mem;
      int v550 = ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) * 2;
      int v391 = v390[v550];
      int v551 = (((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) * 2) + 1;
      int v392 = v390[v551];
      int * v393 = v331->cache_vals;
      int v553 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v371 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2)) - (v374 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v393[v553] = v391;
      int * v395 = v331->cache_vals;
      int v556 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v371 + ((~(((v373 ^ -1) | (-(v373 ^ -1))) >> 31)) & 2)) - (v374 + ((~(((v375 ^ -1) | (-(v375 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v395[v556] = v392;
      int * v397 = v331->cache_tags;
      int v559 = (int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1);
      v397[v535] = v559;
      int * v399 = v331->cache_dirty;
      v399[v535] = 0;
      int * v401 = v331->cache_age;
      v401[v535] = 1;
      int * v403 = v331->cache_age;
      int v404 = v403[v535];
      int v405 = v403[v509];
      int v565 = v405 + ((int)((unsigned int)(v405 - v404) >> 31));
      v403[v509] = v565;
      int * v407 = v331->cache_age;
      int v408 = v407[v510];
      int v567 = v408 + ((int)((unsigned int)(v408 - v404) >> 31));
      v407[v510] = v567;
      int * v410 = v331->cache_age;
      v410[v535] = 0;
      v413 = v535;
    }
    int * v414 = v331->cache_vals;
    int v570 = v413 * 2;
    int v415 = v414[v570];
    int v571 = (v413 * 2) + 1;
    int v416 = v414[v571];
    int v572 = (((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v355 + ((~(((v357 ^ -1) | (-(v357 ^ -1))) >> 31)) & 2)) - (v358 + ((~(((v359 ^ -1) | (-(v359 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v414[v572] = v415;
    int * v418 = v331->cache_vals;
    int v575 = ((((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v355 + ((~(((v357 ^ -1) | (-(v357 ^ -1))) >> 31)) & 2)) - (v358 + ((~(((v359 ^ -1) | (-(v359 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v418[v575] = v416;
    int * v420 = v331->cache_tags;
    int v578 = ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v355 + ((~(((v357 ^ -1) | (-(v357 ^ -1))) >> 31)) & 2)) - (v358 + ((~(((v359 ^ -1) | (-(v359 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v579 = (int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1);
    v420[v578] = v579;
    int * v422 = v331->cache_dirty;
    v422[v578] = 0;
    int * v424 = v331->cache_age;
    v424[v578] = 1;
    int * v426 = v331->cache_age;
    int v427 = v426[v578];
    int v428 = v426[v507];
    int v585 = v428 + ((int)((unsigned int)(v428 - v427) >> 31));
    v426[v507] = v585;
    int * v430 = v331->cache_age;
    int v431 = v430[v508];
    int v587 = v431 + ((int)((unsigned int)(v431 - v427) >> 31));
    v430[v508] = v587;
    int * v433 = v331->cache_age;
    v433[v578] = 0;
    v436 = v578;
  }
  int * v437 = v331->cache_vals;
  int v590 = (v436 * 2) + (((int)((unsigned int)(v335 + 40) >> 2)) & 1);
  v437[v590] = v336;
  int * v439 = v331->cache_tags;
  int v440 = v439[v509];
  int v441 = v439[v510];
  bool v593 = !(((~(((v440 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))) | (-(v440 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v441 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))) | (-(v441 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))))) >> 31))) == 0);
  int v495;
  if (v593) {
    int * v442 = v331->cache_age;
    int v595 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 3) * 2)) + ((~(((v441 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))) | (-(v441 ^ ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1))))) >> 31)) & 1);
    int v443 = v442[v595];
    int v444 = v442[v509];
    int v596 = v444 + ((int)((unsigned int)(v444 - v443) >> 31));
    v442[v509] = v596;
    int * v446 = v331->cache_age;
    int v447 = v446[v510];
    int v598 = v447 + ((int)((unsigned int)(v447 - v443) >> 31));
    v446[v510] = v598;
    int * v449 = v331->cache_age;
    v449[v595] = 0;
    v495 = v595;
  } else {
    int * v452 = v331->cache_age;
    int v602 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 3) * 2);
    int v453 = v452[v602];
    int * v454 = v331->cache_tags;
    int v455 = v454[v602];
    int v456 = v452[v510];
    int v457 = v454[v510];
    int * v458 = v331->cache_dirty;
    int v605 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v453 + ((~(((v455 ^ -1) | (-(v455 ^ -1))) >> 31)) & 2)) - (v456 + ((~(((v457 ^ -1) | (-(v457 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v459 = v458[v605];
    bool v606 = !(v459 == 0);
    if (v606) {
      int * v460 = v331->cache_tags;
      int v461 = v460[v605];
      int * v462 = v331->cache_vals;
      int v609 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v453 + ((~(((v455 ^ -1) | (-(v455 ^ -1))) >> 31)) & 2)) - (v456 + ((~(((v457 ^ -1) | (-(v457 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      int v463 = v462[v609];
      int v610 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v453 + ((~(((v455 ^ -1) | (-(v455 ^ -1))) >> 31)) & 2)) - (v456 + ((~(((v457 ^ -1) | (-(v457 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      int v464 = v462[v610];
      int * v465 = v331->mem;
      int v612 = v461 * 2;
      v465[v612] = v463;
      int * v467 = v331->mem;
      int v615 = (v461 * 2) + 1;
      v467[v615] = v464;
      ;
    } else {
      ;
    }
    int * v472 = v331->mem;
    int v620 = ((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) * 2;
    int v473 = v472[v620];
    int v621 = (((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) * 2) + 1;
    int v474 = v472[v621];
    int * v475 = v331->cache_vals;
    int v623 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v453 + ((~(((v455 ^ -1) | (-(v455 ^ -1))) >> 31)) & 2)) - (v456 + ((~(((v457 ^ -1) | (-(v457 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v475[v623] = v473;
    int * v477 = v331->cache_vals;
    int v626 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v453 + ((~(((v455 ^ -1) | (-(v455 ^ -1))) >> 31)) & 2)) - (v456 + ((~(((v457 ^ -1) | (-(v457 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v477[v626] = v474;
    int * v479 = v331->cache_tags;
    int v629 = (int)((unsigned int)((int)((unsigned int)(v335 + 40) >> 2)) >> 1);
    v479[v605] = v629;
    int * v481 = v331->cache_dirty;
    v481[v605] = 0;
    int * v483 = v331->cache_age;
    v483[v605] = 1;
    int * v485 = v331->cache_age;
    int v486 = v485[v605];
    int v487 = v485[v509];
    int v635 = v487 + ((int)((unsigned int)(v487 - v486) >> 31));
    v485[v509] = v635;
    int * v489 = v331->cache_age;
    int v490 = v489[v510];
    int v637 = v490 + ((int)((unsigned int)(v490 - v486) >> 31));
    v489[v510] = v637;
    int * v492 = v331->cache_age;
    v492[v605] = 0;
    v495 = v605;
  }
  int * v496 = v331->cache_vals;
  int v640 = (v495 * 2) + (((int)((unsigned int)(v335 + 40) >> 2)) & 1);
  v496[v640] = v336;
  int * v498 = v331->cache_dirty;
  v498[v495] = 1;
  struct StateT * v500 = slot_3(v331);
  return v500;
}

struct StateT * slot_86(struct StateT * v10658) {
  int v10659 = v10658->timer;
  int v10666 = v10659 + 1;
  v10658->timer = v10666;
  int * v10661 = v10658->regs;
  int v10662 = v10661[23];
  int v10670 = (int)((unsigned int)v10662 >> 19);
  v10661[24] = v10670;
  struct StateT * v10664 = slot_87(v10658);
  return v10664;
}

struct StateT * slot_129(struct StateT * v11327) {
  int v11328 = v11327->timer;
  int v11336 = v11328 + 1;
  v11327->timer = v11336;
  int * v11330 = v11327->regs;
  int v11331 = v11330[14];
  int v11332 = v11330[20];
  int v11340 = v11331 ^ v11332;
  v11330[14] = v11340;
  struct StateT * v11334 = slot_130(v11327);
  return v11334;
}

struct StateT * slot_158(struct StateT * v11786) {
  int v11787 = v11786->timer;
  int v11794 = v11787 + 1;
  v11786->timer = v11794;
  int * v11789 = v11786->regs;
  int v11790 = v11789[20];
  int v11797 = v11790 << 13;
  v11789[20] = v11797;
  struct StateT * v11792 = slot_159(v11786);
  return v11792;
}

struct StateT * slot_100(struct StateT * v10880) {
  int v10881 = v10880->timer;
  int v10888 = v10881 + 1;
  v10880->timer = v10888;
  int * v10883 = v10880->regs;
  int v10884 = v10883[21];
  int v10892 = (int)((unsigned int)v10884 >> 14);
  v10883[24] = v10892;
  struct StateT * v10886 = slot_101(v10880);
  return v10886;
}

struct StateT * slot_127(struct StateT * v11297) {
  int v11298 = v11297->timer;
  int v11305 = v11298 + 1;
  v11297->timer = v11305;
  int * v11300 = v11297->regs;
  int v11301 = v11300[23];
  int v11308 = v11301 << 7;
  v11300[23] = v11308;
  struct StateT * v11303 = slot_128(v11297);
  return v11303;
}

struct StateT * slot_13(struct StateT * v3272) {
  int v3273 = v3272->timer;
  int v3383 = v3273 + 1;
  v3272->timer = v3383;
  int * v3275 = v3272->regs;
  int v3276 = v3275[12];
  int * v3277 = v3272->cache_tags;
  int v3387 = (((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1)) & 1) * 2;
  int v3278 = v3277[v3387];
  int v3388 = ((((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1)) & 1) * 2) + 1;
  int v3279 = v3277[v3388];
  int v3389 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1)) & 3) * 2);
  int v3280 = v3277[v3389];
  int v3390 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v3281 = v3277[v3390];
  int v3282 = v3272->timer;
  int v3391 = v3282 + ((100 ^ (((~(((v3280 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))) | (-(v3280 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3281 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))) | (-(v3281 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v3278 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))) | (-(v3278 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3279 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))) | (-(v3279 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v3280 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))) | (-(v3280 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3281 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))) | (-(v3281 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))))) >> 31))) & 104)))));
  v3272->timer = v3391;
  int * v3284 = v3272->cache_vals;
  bool v3392 = !(((~(((v3278 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))) | (-(v3278 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3279 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))) | (-(v3279 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))))) >> 31))) == 0);
  int v3377;
  if (v3392) {
    int * v3285 = v3272->cache_age;
    int v3394 = ((((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1)) & 1) * 2) + ((~(((v3279 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))) | (-(v3279 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))))) >> 31)) & 1);
    int v3286 = v3285[v3394];
    int v3287 = v3285[v3387];
    int v3395 = v3287 + ((int)((unsigned int)(v3287 - v3286) >> 31));
    v3285[v3387] = v3395;
    int * v3289 = v3272->cache_age;
    int v3290 = v3289[v3388];
    int v3397 = v3290 + ((int)((unsigned int)(v3290 - v3286) >> 31));
    v3289[v3388] = v3397;
    int * v3292 = v3272->cache_age;
    v3292[v3394] = 0;
    v3377 = v3394;
  } else {
    int * v3295 = v3272->cache_age;
    int v3401 = (((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1)) & 1) * 2;
    int v3296 = v3295[v3401];
    int * v3297 = v3272->cache_tags;
    int v3298 = v3297[v3401];
    int v3299 = v3295[v3388];
    int v3300 = v3297[v3388];
    bool v3403 = !(((~(((v3280 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))) | (-(v3280 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))))) >> 31)) | (~(((v3281 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))) | (-(v3281 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))))) >> 31))) == 0);
    int v3354;
    if (v3403) {
      int * v3301 = v3272->cache_age;
      int v3405 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1)) & 3) * 2)) + ((~(((v3281 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))) | (-(v3281 ^ ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1))))) >> 31)) & 1);
      int v3302 = v3301[v3405];
      int v3303 = v3301[v3389];
      int v3406 = v3303 + ((int)((unsigned int)(v3303 - v3302) >> 31));
      v3301[v3389] = v3406;
      int * v3305 = v3272->cache_age;
      int v3306 = v3305[v3390];
      int v3408 = v3306 + ((int)((unsigned int)(v3306 - v3302) >> 31));
      v3305[v3390] = v3408;
      int * v3308 = v3272->cache_age;
      v3308[v3405] = 0;
      v3354 = v3405;
    } else {
      int * v3311 = v3272->cache_age;
      int v3412 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1)) & 3) * 2);
      int v3312 = v3311[v3412];
      int * v3313 = v3272->cache_tags;
      int v3314 = v3313[v3412];
      int v3315 = v3311[v3390];
      int v3316 = v3313[v3390];
      int * v3317 = v3272->cache_dirty;
      int v3415 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3312 + ((~(((v3314 ^ -1) | (-(v3314 ^ -1))) >> 31)) & 2)) - (v3315 + ((~(((v3316 ^ -1) | (-(v3316 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v3318 = v3317[v3415];
      bool v3416 = !(v3318 == 0);
      if (v3416) {
        int * v3319 = v3272->cache_tags;
        int v3320 = v3319[v3415];
        int * v3321 = v3272->cache_vals;
        int v3419 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3312 + ((~(((v3314 ^ -1) | (-(v3314 ^ -1))) >> 31)) & 2)) - (v3315 + ((~(((v3316 ^ -1) | (-(v3316 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v3322 = v3321[v3419];
        int v3420 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3312 + ((~(((v3314 ^ -1) | (-(v3314 ^ -1))) >> 31)) & 2)) - (v3315 + ((~(((v3316 ^ -1) | (-(v3316 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v3323 = v3321[v3420];
        int * v3324 = v3272->mem;
        int v3422 = v3320 * 2;
        v3324[v3422] = v3322;
        int * v3326 = v3272->mem;
        int v3425 = (v3320 * 2) + 1;
        v3326[v3425] = v3323;
        ;
      } else {
        ;
      }
      int * v3331 = v3272->mem;
      int v3430 = ((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1)) * 2;
      int v3332 = v3331[v3430];
      int v3431 = (((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1)) * 2) + 1;
      int v3333 = v3331[v3431];
      int * v3334 = v3272->cache_vals;
      int v3433 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3312 + ((~(((v3314 ^ -1) | (-(v3314 ^ -1))) >> 31)) & 2)) - (v3315 + ((~(((v3316 ^ -1) | (-(v3316 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v3334[v3433] = v3332;
      int * v3336 = v3272->cache_vals;
      int v3436 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1)) & 3) * 2)) + ((((v3312 + ((~(((v3314 ^ -1) | (-(v3314 ^ -1))) >> 31)) & 2)) - (v3315 + ((~(((v3316 ^ -1) | (-(v3316 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v3336[v3436] = v3333;
      int * v3338 = v3272->cache_tags;
      int v3439 = (int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1);
      v3338[v3415] = v3439;
      int * v3340 = v3272->cache_dirty;
      v3340[v3415] = 0;
      int * v3342 = v3272->cache_age;
      v3342[v3415] = 1;
      int * v3344 = v3272->cache_age;
      int v3345 = v3344[v3415];
      int v3346 = v3344[v3389];
      int v3445 = v3346 + ((int)((unsigned int)(v3346 - v3345) >> 31));
      v3344[v3389] = v3445;
      int * v3348 = v3272->cache_age;
      int v3349 = v3348[v3390];
      int v3447 = v3349 + ((int)((unsigned int)(v3349 - v3345) >> 31));
      v3348[v3390] = v3447;
      int * v3351 = v3272->cache_age;
      v3351[v3415] = 0;
      v3354 = v3415;
    }
    int * v3355 = v3272->cache_vals;
    int v3450 = v3354 * 2;
    int v3356 = v3355[v3450];
    int v3451 = (v3354 * 2) + 1;
    int v3357 = v3355[v3451];
    int v3452 = (((((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v3296 + ((~(((v3298 ^ -1) | (-(v3298 ^ -1))) >> 31)) & 2)) - (v3299 + ((~(((v3300 ^ -1) | (-(v3300 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v3355[v3452] = v3356;
    int * v3359 = v3272->cache_vals;
    int v3455 = ((((((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v3296 + ((~(((v3298 ^ -1) | (-(v3298 ^ -1))) >> 31)) & 2)) - (v3299 + ((~(((v3300 ^ -1) | (-(v3300 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v3359[v3455] = v3357;
    int * v3361 = v3272->cache_tags;
    int v3458 = ((((int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1)) & 1) * 2) + ((((v3296 + ((~(((v3298 ^ -1) | (-(v3298 ^ -1))) >> 31)) & 2)) - (v3299 + ((~(((v3300 ^ -1) | (-(v3300 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3459 = (int)((unsigned int)((int)((unsigned int)(v3276 + 8) >> 2)) >> 1);
    v3361[v3458] = v3459;
    int * v3363 = v3272->cache_dirty;
    v3363[v3458] = 0;
    int * v3365 = v3272->cache_age;
    v3365[v3458] = 1;
    int * v3367 = v3272->cache_age;
    int v3368 = v3367[v3458];
    int v3369 = v3367[v3387];
    int v3465 = v3369 + ((int)((unsigned int)(v3369 - v3368) >> 31));
    v3367[v3387] = v3465;
    int * v3371 = v3272->cache_age;
    int v3372 = v3371[v3388];
    int v3467 = v3372 + ((int)((unsigned int)(v3372 - v3368) >> 31));
    v3371[v3388] = v3467;
    int * v3374 = v3272->cache_age;
    v3374[v3458] = 0;
    v3377 = v3458;
  }
  int v3470 = (v3377 * 2) + (((int)((unsigned int)(v3276 + 8) >> 2)) & 1);
  int v3378 = v3284[v3470];
  int * v3379 = v3272->regs;
  v3379[8] = v3378;
  struct StateT * v3381 = slot_14(v3272);
  return v3381;
}

struct StateT * slot_111(struct StateT * v11047) {
  int v11048 = v11047->timer;
  int v11056 = v11048 + 1;
  v11047->timer = v11056;
  int * v11050 = v11047->regs;
  int v11051 = v11050[28];
  int v11052 = v11050[22];
  int v11060 = v11051 ^ v11052;
  v11050[28] = v11060;
  struct StateT * v11054 = slot_112(v11047);
  return v11054;
}

struct StateT * slot_109(struct StateT * v11015) {
  int v11016 = v11015->timer;
  int v11024 = v11016 + 1;
  v11015->timer = v11024;
  int * v11018 = v11015->regs;
  int v11019 = v11018[30];
  int v11020 = v11018[20];
  int v11028 = v11019 ^ v11020;
  v11018[30] = v11028;
  struct StateT * v11022 = slot_110(v11015);
  return v11022;
}

struct StateT * slot_174(struct StateT * v12032) {
  int v12033 = v12032->timer;
  int v12041 = v12033 + 1;
  v12032->timer = v12041;
  int * v12035 = v12032->regs;
  int v12036 = v12035[9];
  int v12037 = v12035[5];
  int v12046 = v12036 + v12037;
  v12035[21] = v12046;
  struct StateT * v12039 = slot_175(v12032);
  return v12039;
}

struct StateT * slot_147(struct StateT * v11609) {
  int v11610 = v11609->timer;
  int v11617 = v11610 + 1;
  v11609->timer = v11617;
  int * v11612 = v11609->regs;
  int v11613 = v11612[23];
  int v11620 = v11613 << 9;
  v11612[23] = v11620;
  struct StateT * v11615 = slot_148(v11609);
  return v11615;
}

struct StateT * slot_42(struct StateT * v8526) {
  int v8527 = v8526->timer;
  int v8535 = v8527 + 1;
  v8526->timer = v8535;
  int * v8529 = v8526->regs;
  int v8530 = v8529[21];
  int v8531 = v8529[24];
  int v8539 = v8530 | v8531;
  v8529[21] = v8539;
  struct StateT * v8533 = slot_43(v8526);
  return v8533;
}

struct StateT * slot_163(struct StateT * v11861) {
  int v11862 = v11861->timer;
  int v11869 = v11862 + 1;
  v11861->timer = v11869;
  int * v11864 = v11861->regs;
  int v11865 = v11864[22];
  int v11873 = (int)((unsigned int)v11865 >> 19);
  v11864[24] = v11873;
  struct StateT * v11867 = slot_164(v11861);
  return v11867;
}

struct StateT * slot_184(struct StateT * v12188) {
  int v12189 = v12188->timer;
  int v12196 = v12189 + 1;
  v12188->timer = v12196;
  int * v12191 = v12188->regs;
  int v12192 = v12191[22];
  int v12199 = v12192 << 18;
  v12191[22] = v12199;
  struct StateT * v12194 = slot_185(v12188);
  return v12194;
}

struct StateT * slot_204(struct StateT * v8322) {
  int v8323 = v8322->timer;
  int v8433 = v8323 + 1;
  v8322->timer = v8433;
  int * v8325 = v8322->regs;
  int v8326 = v8325[2];
  int * v8327 = v8322->cache_tags;
  int v8437 = (((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1)) & 1) * 2;
  int v8328 = v8327[v8437];
  int v8438 = ((((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1)) & 1) * 2) + 1;
  int v8329 = v8327[v8438];
  int v8439 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1)) & 3) * 2);
  int v8330 = v8327[v8439];
  int v8440 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1)) & 3) * 2)) + 1;
  int v8331 = v8327[v8440];
  int v8332 = v8322->timer;
  int v8441 = v8332 + ((100 ^ (((~(((v8330 ^ ((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1))) | (-(v8330 ^ ((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v8331 ^ ((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1))) | (-(v8331 ^ ((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v8328 ^ ((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1))) | (-(v8328 ^ ((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v8329 ^ ((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1))) | (-(v8329 ^ ((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v8330 ^ ((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1))) | (-(v8330 ^ ((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v8331 ^ ((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1))) | (-(v8331 ^ ((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1))))) >> 31))) & 104)))));
  v8322->timer = v8441;
  int * v8334 = v8322->cache_vals;
  bool v8442 = !(((~(((v8328 ^ ((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1))) | (-(v8328 ^ ((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v8329 ^ ((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1))) | (-(v8329 ^ ((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1))))) >> 31))) == 0);
  int v8427;
  if (v8442) {
    int * v8335 = v8322->cache_age;
    int v8444 = ((((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1)) & 1) * 2) + ((~(((v8329 ^ ((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1))) | (-(v8329 ^ ((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1))))) >> 31)) & 1);
    int v8336 = v8335[v8444];
    int v8337 = v8335[v8437];
    int v8445 = v8337 + ((int)((unsigned int)(v8337 - v8336) >> 31));
    v8335[v8437] = v8445;
    int * v8339 = v8322->cache_age;
    int v8340 = v8339[v8438];
    int v8447 = v8340 + ((int)((unsigned int)(v8340 - v8336) >> 31));
    v8339[v8438] = v8447;
    int * v8342 = v8322->cache_age;
    v8342[v8444] = 0;
    v8427 = v8444;
  } else {
    int * v8345 = v8322->cache_age;
    int v8451 = (((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1)) & 1) * 2;
    int v8346 = v8345[v8451];
    int * v8347 = v8322->cache_tags;
    int v8348 = v8347[v8451];
    int v8349 = v8345[v8438];
    int v8350 = v8347[v8438];
    bool v8453 = !(((~(((v8330 ^ ((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1))) | (-(v8330 ^ ((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1))))) >> 31)) | (~(((v8331 ^ ((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1))) | (-(v8331 ^ ((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1))))) >> 31))) == 0);
    int v8404;
    if (v8453) {
      int * v8351 = v8322->cache_age;
      int v8455 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1)) & 3) * 2)) + ((~(((v8331 ^ ((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1))) | (-(v8331 ^ ((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1))))) >> 31)) & 1);
      int v8352 = v8351[v8455];
      int v8353 = v8351[v8439];
      int v8456 = v8353 + ((int)((unsigned int)(v8353 - v8352) >> 31));
      v8351[v8439] = v8456;
      int * v8355 = v8322->cache_age;
      int v8356 = v8355[v8440];
      int v8458 = v8356 + ((int)((unsigned int)(v8356 - v8352) >> 31));
      v8355[v8440] = v8458;
      int * v8358 = v8322->cache_age;
      v8358[v8455] = 0;
      v8404 = v8455;
    } else {
      int * v8361 = v8322->cache_age;
      int v8462 = 4 + ((((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1)) & 3) * 2);
      int v8362 = v8361[v8462];
      int * v8363 = v8322->cache_tags;
      int v8364 = v8363[v8462];
      int v8365 = v8361[v8440];
      int v8366 = v8363[v8440];
      int * v8367 = v8322->cache_dirty;
      int v8465 = (4 + ((((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v8362 + ((~(((v8364 ^ -1) | (-(v8364 ^ -1))) >> 31)) & 2)) - (v8365 + ((~(((v8366 ^ -1) | (-(v8366 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v8368 = v8367[v8465];
      bool v8466 = !(v8368 == 0);
      if (v8466) {
        int * v8369 = v8322->cache_tags;
        int v8370 = v8369[v8465];
        int * v8371 = v8322->cache_vals;
        int v8469 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v8362 + ((~(((v8364 ^ -1) | (-(v8364 ^ -1))) >> 31)) & 2)) - (v8365 + ((~(((v8366 ^ -1) | (-(v8366 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v8372 = v8371[v8469];
        int v8470 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v8362 + ((~(((v8364 ^ -1) | (-(v8364 ^ -1))) >> 31)) & 2)) - (v8365 + ((~(((v8366 ^ -1) | (-(v8366 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v8373 = v8371[v8470];
        int * v8374 = v8322->mem;
        int v8472 = v8370 * 2;
        v8374[v8472] = v8372;
        int * v8376 = v8322->mem;
        int v8475 = (v8370 * 2) + 1;
        v8376[v8475] = v8373;
        ;
      } else {
        ;
      }
      int * v8381 = v8322->mem;
      int v8480 = ((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1)) * 2;
      int v8382 = v8381[v8480];
      int v8481 = (((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1)) * 2) + 1;
      int v8383 = v8381[v8481];
      int * v8384 = v8322->cache_vals;
      int v8483 = ((4 + ((((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v8362 + ((~(((v8364 ^ -1) | (-(v8364 ^ -1))) >> 31)) & 2)) - (v8365 + ((~(((v8366 ^ -1) | (-(v8366 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v8384[v8483] = v8382;
      int * v8386 = v8322->cache_vals;
      int v8486 = (((4 + ((((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1)) & 3) * 2)) + ((((v8362 + ((~(((v8364 ^ -1) | (-(v8364 ^ -1))) >> 31)) & 2)) - (v8365 + ((~(((v8366 ^ -1) | (-(v8366 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v8386[v8486] = v8383;
      int * v8388 = v8322->cache_tags;
      int v8489 = (int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1);
      v8388[v8465] = v8489;
      int * v8390 = v8322->cache_dirty;
      v8390[v8465] = 0;
      int * v8392 = v8322->cache_age;
      v8392[v8465] = 1;
      int * v8394 = v8322->cache_age;
      int v8395 = v8394[v8465];
      int v8396 = v8394[v8439];
      int v8495 = v8396 + ((int)((unsigned int)(v8396 - v8395) >> 31));
      v8394[v8439] = v8495;
      int * v8398 = v8322->cache_age;
      int v8399 = v8398[v8440];
      int v8497 = v8399 + ((int)((unsigned int)(v8399 - v8395) >> 31));
      v8398[v8440] = v8497;
      int * v8401 = v8322->cache_age;
      v8401[v8465] = 0;
      v8404 = v8465;
    }
    int * v8405 = v8322->cache_vals;
    int v8500 = v8404 * 2;
    int v8406 = v8405[v8500];
    int v8501 = (v8404 * 2) + 1;
    int v8407 = v8405[v8501];
    int v8502 = (((((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v8346 + ((~(((v8348 ^ -1) | (-(v8348 ^ -1))) >> 31)) & 2)) - (v8349 + ((~(((v8350 ^ -1) | (-(v8350 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v8405[v8502] = v8406;
    int * v8409 = v8322->cache_vals;
    int v8505 = ((((((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v8346 + ((~(((v8348 ^ -1) | (-(v8348 ^ -1))) >> 31)) & 2)) - (v8349 + ((~(((v8350 ^ -1) | (-(v8350 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v8409[v8505] = v8407;
    int * v8411 = v8322->cache_tags;
    int v8508 = ((((int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1)) & 1) * 2) + ((((v8346 + ((~(((v8348 ^ -1) | (-(v8348 ^ -1))) >> 31)) & 2)) - (v8349 + ((~(((v8350 ^ -1) | (-(v8350 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v8509 = (int)((unsigned int)((int)((unsigned int)(v8326 + 40) >> 2)) >> 1);
    v8411[v8508] = v8509;
    int * v8413 = v8322->cache_dirty;
    v8413[v8508] = 0;
    int * v8415 = v8322->cache_age;
    v8415[v8508] = 1;
    int * v8417 = v8322->cache_age;
    int v8418 = v8417[v8508];
    int v8419 = v8417[v8437];
    int v8515 = v8419 + ((int)((unsigned int)(v8419 - v8418) >> 31));
    v8417[v8437] = v8515;
    int * v8421 = v8322->cache_age;
    int v8422 = v8421[v8438];
    int v8517 = v8422 + ((int)((unsigned int)(v8422 - v8418) >> 31));
    v8421[v8438] = v8517;
    int * v8424 = v8322->cache_age;
    v8424[v8508] = 0;
    v8427 = v8508;
  }
  int v8520 = (v8427 * 2) + (((int)((unsigned int)(v8326 + 40) >> 2)) & 1);
  int v8428 = v8334[v8520];
  int * v8429 = v8322->regs;
  v8429[9] = v8428;
  struct StateT * v8431 = slot_205(v8322);
  return v8431;
}

struct StateT * slot_194(struct StateT * v12341) {
  int v12342 = v12341->timer;
  int v12353 = v12342 + 1;
  v12341->timer = v12353;
  int * v12344 = v12341->regs;
  int v12345 = v12344[11];
  int v12346 = v12344[13];
  bool v12357 = (v12345 ^ -2147483648) >= (v12346 ^ -2147483648);
  struct StateT * v12351;
  if (v12357) {
    struct StateT * v12347 = slot_33(v12341);
    v12351 = v12347;
  } else {
    struct StateT * v12349 = slot_195(v12341);
    v12351 = v12349;
  }
  return v12351;
}

struct StateT * slot_165(struct StateT * v11890) {
  int v11891 = v11890->timer;
  int v11899 = v11891 + 1;
  v11890->timer = v11899;
  int * v11893 = v11890->regs;
  int v11894 = v11893[22];
  int v11895 = v11893[24];
  int v11903 = v11894 | v11895;
  v11893[22] = v11903;
  struct StateT * v11897 = slot_166(v11890);
  return v11897;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v1 = slot_0(v0);
  return v1;
}

struct StateT * slot_117(struct StateT * v11147) {
  int v11148 = v11147->timer;
  int v11155 = v11148 + 1;
  v11147->timer = v11155;
  int * v11150 = v11147->regs;
  int v11151 = v11150[20];
  int v11159 = (int)((unsigned int)v11151 >> 25);
  v11150[24] = v11159;
  struct StateT * v11153 = slot_118(v11147);
  return v11153;
}

struct StateT * slot_90(struct StateT * v10719) {
  int v10720 = v10719->timer;
  int v10728 = v10720 + 1;
  v10719->timer = v10728;
  int * v10722 = v10719->regs;
  int v10723 = v10722[14];
  int v10724 = v10722[21];
  int v10732 = v10723 ^ v10724;
  v10722[14] = v10732;
  struct StateT * v10726 = slot_91(v10719);
  return v10726;
}

struct StateT * slot_11(struct StateT * v2864) {
  int v2865 = v2864->timer;
  int v2975 = v2865 + 1;
  v2864->timer = v2975;
  int * v2867 = v2864->regs;
  int v2868 = v2867[12];
  int * v2869 = v2864->cache_tags;
  int v2979 = (((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1)) & 1) * 2;
  int v2870 = v2869[v2979];
  int v2980 = ((((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1)) & 1) * 2) + 1;
  int v2871 = v2869[v2980];
  int v2981 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1)) & 3) * 2);
  int v2872 = v2869[v2981];
  int v2982 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1)) & 3) * 2)) + 1;
  int v2873 = v2869[v2982];
  int v2874 = v2864->timer;
  int v2983 = v2874 + ((100 ^ (((~(((v2872 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))) | (-(v2872 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))))) >> 31)) | (~(((v2873 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))) | (-(v2873 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))))) >> 31))) & 104)) ^ (((~(((v2870 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))) | (-(v2870 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))))) >> 31)) | (~(((v2871 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))) | (-(v2871 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))))) >> 31))) & (1 ^ (100 ^ (((~(((v2872 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))) | (-(v2872 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))))) >> 31)) | (~(((v2873 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))) | (-(v2873 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))))) >> 31))) & 104)))));
  v2864->timer = v2983;
  int * v2876 = v2864->cache_vals;
  bool v2984 = !(((~(((v2870 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))) | (-(v2870 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))))) >> 31)) | (~(((v2871 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))) | (-(v2871 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))))) >> 31))) == 0);
  int v2969;
  if (v2984) {
    int * v2877 = v2864->cache_age;
    int v2986 = ((((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1)) & 1) * 2) + ((~(((v2871 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))) | (-(v2871 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))))) >> 31)) & 1);
    int v2878 = v2877[v2986];
    int v2879 = v2877[v2979];
    int v2987 = v2879 + ((int)((unsigned int)(v2879 - v2878) >> 31));
    v2877[v2979] = v2987;
    int * v2881 = v2864->cache_age;
    int v2882 = v2881[v2980];
    int v2989 = v2882 + ((int)((unsigned int)(v2882 - v2878) >> 31));
    v2881[v2980] = v2989;
    int * v2884 = v2864->cache_age;
    v2884[v2986] = 0;
    v2969 = v2986;
  } else {
    int * v2887 = v2864->cache_age;
    int v2993 = (((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1)) & 1) * 2;
    int v2888 = v2887[v2993];
    int * v2889 = v2864->cache_tags;
    int v2890 = v2889[v2993];
    int v2891 = v2887[v2980];
    int v2892 = v2889[v2980];
    bool v2995 = !(((~(((v2872 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))) | (-(v2872 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))))) >> 31)) | (~(((v2873 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))) | (-(v2873 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))))) >> 31))) == 0);
    int v2946;
    if (v2995) {
      int * v2893 = v2864->cache_age;
      int v2997 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1)) & 3) * 2)) + ((~(((v2873 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))) | (-(v2873 ^ ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1))))) >> 31)) & 1);
      int v2894 = v2893[v2997];
      int v2895 = v2893[v2981];
      int v2998 = v2895 + ((int)((unsigned int)(v2895 - v2894) >> 31));
      v2893[v2981] = v2998;
      int * v2897 = v2864->cache_age;
      int v2898 = v2897[v2982];
      int v3000 = v2898 + ((int)((unsigned int)(v2898 - v2894) >> 31));
      v2897[v2982] = v3000;
      int * v2900 = v2864->cache_age;
      v2900[v2997] = 0;
      v2946 = v2997;
    } else {
      int * v2903 = v2864->cache_age;
      int v3004 = 4 + ((((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1)) & 3) * 2);
      int v2904 = v2903[v3004];
      int * v2905 = v2864->cache_tags;
      int v2906 = v2905[v3004];
      int v2907 = v2903[v2982];
      int v2908 = v2905[v2982];
      int * v2909 = v2864->cache_dirty;
      int v3007 = (4 + ((((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1)) & 3) * 2)) + ((((v2904 + ((~(((v2906 ^ -1) | (-(v2906 ^ -1))) >> 31)) & 2)) - (v2907 + ((~(((v2908 ^ -1) | (-(v2908 ^ -1))) >> 31)) & 2))) >> 31) & 1);
      int v2910 = v2909[v3007];
      bool v3008 = !(v2910 == 0);
      if (v3008) {
        int * v2911 = v2864->cache_tags;
        int v2912 = v2911[v3007];
        int * v2913 = v2864->cache_vals;
        int v3011 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1)) & 3) * 2)) + ((((v2904 + ((~(((v2906 ^ -1) | (-(v2906 ^ -1))) >> 31)) & 2)) - (v2907 + ((~(((v2908 ^ -1) | (-(v2908 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
        int v2914 = v2913[v3011];
        int v3012 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1)) & 3) * 2)) + ((((v2904 + ((~(((v2906 ^ -1) | (-(v2906 ^ -1))) >> 31)) & 2)) - (v2907 + ((~(((v2908 ^ -1) | (-(v2908 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
        int v2915 = v2913[v3012];
        int * v2916 = v2864->mem;
        int v3014 = v2912 * 2;
        v2916[v3014] = v2914;
        int * v2918 = v2864->mem;
        int v3017 = (v2912 * 2) + 1;
        v2918[v3017] = v2915;
        ;
      } else {
        ;
      }
      int * v2923 = v2864->mem;
      int v3022 = ((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1)) * 2;
      int v2924 = v2923[v3022];
      int v3023 = (((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1)) * 2) + 1;
      int v2925 = v2923[v3023];
      int * v2926 = v2864->cache_vals;
      int v3025 = ((4 + ((((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1)) & 3) * 2)) + ((((v2904 + ((~(((v2906 ^ -1) | (-(v2906 ^ -1))) >> 31)) & 2)) - (v2907 + ((~(((v2908 ^ -1) | (-(v2908 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
      v2926[v3025] = v2924;
      int * v2928 = v2864->cache_vals;
      int v3028 = (((4 + ((((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1)) & 3) * 2)) + ((((v2904 + ((~(((v2906 ^ -1) | (-(v2906 ^ -1))) >> 31)) & 2)) - (v2907 + ((~(((v2908 ^ -1) | (-(v2908 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
      v2928[v3028] = v2925;
      int * v2930 = v2864->cache_tags;
      int v3031 = (int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1);
      v2930[v3007] = v3031;
      int * v2932 = v2864->cache_dirty;
      v2932[v3007] = 0;
      int * v2934 = v2864->cache_age;
      v2934[v3007] = 1;
      int * v2936 = v2864->cache_age;
      int v2937 = v2936[v3007];
      int v2938 = v2936[v2981];
      int v3037 = v2938 + ((int)((unsigned int)(v2938 - v2937) >> 31));
      v2936[v2981] = v3037;
      int * v2940 = v2864->cache_age;
      int v2941 = v2940[v2982];
      int v3039 = v2941 + ((int)((unsigned int)(v2941 - v2937) >> 31));
      v2940[v2982] = v3039;
      int * v2943 = v2864->cache_age;
      v2943[v3007] = 0;
      v2946 = v3007;
    }
    int * v2947 = v2864->cache_vals;
    int v3042 = v2946 * 2;
    int v2948 = v2947[v3042];
    int v3043 = (v2946 * 2) + 1;
    int v2949 = v2947[v3043];
    int v3044 = (((((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1)) & 1) * 2) + ((((v2888 + ((~(((v2890 ^ -1) | (-(v2890 ^ -1))) >> 31)) & 2)) - (v2891 + ((~(((v2892 ^ -1) | (-(v2892 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2;
    v2947[v3044] = v2948;
    int * v2951 = v2864->cache_vals;
    int v3047 = ((((((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1)) & 1) * 2) + ((((v2888 + ((~(((v2890 ^ -1) | (-(v2890 ^ -1))) >> 31)) & 2)) - (v2891 + ((~(((v2892 ^ -1) | (-(v2892 ^ -1))) >> 31)) & 2))) >> 31) & 1)) * 2) + 1;
    v2951[v3047] = v2949;
    int * v2953 = v2864->cache_tags;
    int v3050 = ((((int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1)) & 1) * 2) + ((((v2888 + ((~(((v2890 ^ -1) | (-(v2890 ^ -1))) >> 31)) & 2)) - (v2891 + ((~(((v2892 ^ -1) | (-(v2892 ^ -1))) >> 31)) & 2))) >> 31) & 1);
    int v3051 = (int)((unsigned int)((int)((unsigned int)v2868 >> 2)) >> 1);
    v2953[v3050] = v3051;
    int * v2955 = v2864->cache_dirty;
    v2955[v3050] = 0;
    int * v2957 = v2864->cache_age;
    v2957[v3050] = 1;
    int * v2959 = v2864->cache_age;
    int v2960 = v2959[v3050];
    int v2961 = v2959[v2979];
    int v3057 = v2961 + ((int)((unsigned int)(v2961 - v2960) >> 31));
    v2959[v2979] = v3057;
    int * v2963 = v2864->cache_age;
    int v2964 = v2963[v2980];
    int v3059 = v2964 + ((int)((unsigned int)(v2964 - v2960) >> 31));
    v2963[v2980] = v3059;
    int * v2966 = v2864->cache_age;
    v2966[v3050] = 0;
    v2969 = v3050;
  }
  int v3062 = (v2969 * 2) + (((int)((unsigned int)v2868 >> 2)) & 1);
  int v2970 = v2876[v3062];
  int * v2971 = v2864->regs;
  v2971[14] = v2970;
  struct StateT * v2973 = slot_12(v2864);
  return v2973;
}



/*****************************************
End of C Generated Code
*******************************************/

void init(struct StateT *s) {
  for (int i=0; i<NUM_REGS; i++) {
    s->regs[i] = 0;
  }
  s->regs[2] = 4 * MEM_SIZE;
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
  
  // a10, 8 words written by the callee: the address is public
  s1.regs[10] = 0;
  s2.regs[10] = 0;
  // a11, 4 words read by the callee: the address is public
  s1.regs[11] = 32;
  s2.regs[11] = 32;
  // a12, 8 words read by the callee: the address is public
  s1.regs[12] = 48;
  s2.regs[12] = 48;
  
  // a11's contents, secret: a different draw in each state
  for (int i=0; i<4; i++) {
    s1.mem[8 + i] = secret(0, 20);
    s2.mem[8 + i] = secret(0, 20);
  }
  // a12's contents, secret: a different draw in each state
  for (int i=0; i<8; i++) {
    s1.mem[12 + i] = secret(0, 20);
    s2.mem[12 + i] = secret(0, 20);
  }
  struct StateT *s1_ = snippet(&s1);
  struct StateT *s2_ = snippet(&s2);
  //@ assert untainted_timer: !\tainted(s1_->timer==s2_->timer);
  koika_assert(s1_->timer==s2_->timer, "timing leak");
  return 0;
}