
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
struct StateT {
  int regs[NUM_REGS];
  int mem[MEM_SIZE];
  int saved_regs[NUM_REGS];
  int cache_keys[CACHE_LRU_SIZE];
  int cache_vals[CACHE_LRU_SIZE];
  int timer;
};

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

/*****************************************
Emitting C Generated Code
*******************************************/

#include <stdbool.h>
#include <stdlib.h>

struct StateT * v7811(struct StateT * v7812);
struct StateT * v8839(struct StateT * v8840);
struct StateT * v9063(struct StateT * v9064);
struct StateT * v9033(struct StateT * v9034);
struct StateT * v8985(struct StateT * v8986);
struct StateT * v4843(struct StateT * v4844);
struct StateT * v3595(struct StateT * v3596);
struct StateT * v3737(struct StateT * v3738);
struct StateT * v4465(struct StateT * v4466);
struct StateT * v4627(struct StateT * v4628);
struct StateT * v8655(struct StateT * v8656);
struct StateT * v8407(struct StateT * v8408);
struct StateT * v9043(struct StateT * v9044);
struct StateT * v8565(struct StateT * v8566);
struct StateT * v8415(struct StateT * v8416);
struct StateT * v3721(struct StateT * v3722);
struct StateT * v8967(struct StateT * v8968);
struct StateT * v63(struct StateT * v64);
struct StateT * v9117(struct StateT * v9118);
struct StateT * v441(struct StateT * v442);
struct StateT * v9099(struct StateT * v9100);
struct StateT * v4195(struct StateT * v4196);
struct StateT * v5183(struct StateT * v5184);
struct StateT * v8073(struct StateT * v8074);
struct StateT * v8547(struct StateT * v8548);
struct StateT * v1469(struct StateT * v1470);
struct StateT * v8539(struct StateT * v8540);
struct StateT * v8399(struct StateT * v8400);
struct StateT * v8215(struct StateT * v8216);
struct StateT * v8705(struct StateT * v8706);
struct StateT * v891(struct StateT * v892);
struct StateT * v8915(struct StateT * v8916);
struct StateT * v7803(struct StateT * v7804);
struct StateT * v4411(struct StateT * v4412);
struct StateT * v1065(struct StateT * v1066);
struct StateT * v5125(struct StateT * v5126);
struct StateT * v4573(struct StateT * v4574);
struct StateT * v657(struct StateT * v658);
struct StateT * v5473(struct StateT * v5474);
struct StateT * v8859(struct StateT * v8860);
struct StateT * v8317(struct StateT * v8318);
struct StateT * v1907(struct StateT * v1908);
struct StateT * v4357(struct StateT * v4358);
struct StateT * v1413(struct StateT * v1414);
struct StateT * v2001(struct StateT * v2002);
struct StateT * v8179(struct StateT * v8180);
struct StateT * v8171(struct StateT * v8172);
struct StateT * v8695(struct StateT * v8696);
struct StateT * v1993(struct StateT * v1994);
struct StateT * v8959(struct StateT * v8960);
struct StateT * v8591(struct StateT * v8592);
struct StateT * v8197(struct StateT * v8198);
struct StateT * v3453(struct StateT * v3454);
struct StateT * v1475(struct StateT * v1476);
struct StateT * v8065(struct StateT * v8066);
struct StateT * v8573(struct StateT * v8574);
struct StateT * v3941(struct StateT * v3942);
struct StateT * v3795(struct StateT * v3796);
struct StateT * v8327(struct StateT * v8328);
struct StateT * v4057(struct StateT * v4058);
struct StateT * v1425(struct StateT * v1426);
struct StateT * v1637(struct StateT * v1638);
struct StateT * v3999(struct StateT * v4000);
struct StateT * v9177(struct StateT * v9178);
struct StateT * v8005(struct StateT * v8006);
struct StateT * v4067(struct StateT * v4068);
struct StateT * v7959(struct StateT * v7960);
struct StateT * v7873(struct StateT * v7874);
struct StateT * v8869(struct StateT * v8870);
struct StateT * v8767(struct StateT * v8768);
struct StateT * v7795(struct StateT * v7796);
struct StateT * v8021(struct StateT * v8022);
struct StateT * v4031(struct StateT * v4032);
struct StateT * v1239(struct StateT * v1240);
struct StateT * v3873(struct StateT * v3874);
struct StateT * v8039(struct StateT * v8040);
struct StateT * v8819(struct StateT * v8820);
struct StateT * v333(struct StateT * v334);
struct StateT * v7829(struct StateT * v7830);
struct StateT * v8665(struct StateT * v8666);
struct StateT * v949(struct StateT * v950);
struct StateT * v8925(struct StateT * v8926);
struct StateT * v1447(struct StateT * v1448);
struct StateT * v8083(struct StateT * v8084);
struct StateT * v8879(struct StateT * v8880);
struct StateT * v8809(struct StateT * v8810);
struct StateT * v1123(struct StateT * v1124);
struct StateT * v1419(struct StateT * v1420);
struct StateT * v8941(struct StateT * v8942);
struct StateT * v225(struct StateT * v226);
struct StateT * v3517(struct StateT * v3518);
struct StateT * v1691(struct StateT * v1692);
struct StateT * v7949(struct StateT * v7950);
struct StateT * v5705(struct StateT * v5706);
struct StateT * v717(struct StateT * v718);
struct StateT * v4077(struct StateT * v4078);
struct StateT * v8977(struct StateT * v8978);
struct StateT * v775(struct StateT * v776);
struct StateT * v7979(struct StateT * v7980);
struct StateT * v4015(struct StateT * v4016);
struct StateT * v8599(struct StateT * v8600);
struct StateT * v3805(struct StateT * v3806);
struct StateT * v9161(struct StateT * v9162);
struct StateT * v9053(struct StateT * v9054);
struct StateT * v8645(struct StateT * v8646);
struct StateT * v5241(struct StateT * v5242);
struct StateT * v9003(struct StateT * v9004);
struct StateT * v4141(struct StateT * v4142);
struct StateT * v4023(struct StateT * v4024);
struct StateT * v9023(struct StateT * v9024);
struct StateT * v8163(struct StateT * v8164);
struct StateT * v3585(struct StateT * v3586);
struct StateT * v5589(struct StateT * v5590);
struct StateT * v8143(struct StateT * v8144);
struct StateT * v1939(struct StateT * v1940);
struct StateT * v8635(struct StateT * v8636);
struct StateT * v8277(struct StateT * v8278);
struct StateT * v8471(struct StateT * v8472);
struct StateT * v8741(struct StateT * v8742);
struct StateT * v8951(struct StateT * v8952);
struct StateT * v7863(struct StateT * v7864);
struct StateT * v8373(struct StateT * v8374);
struct StateT * v8609(struct StateT * v8610);
struct StateT * v7837(struct StateT * v7838);
struct StateT * v8223(struct StateT * v8224);
struct StateT * v5415(struct StateT * v5416);
struct StateT * v9227(struct StateT * v9228);
struct StateT * v7889(struct StateT * v7890);
struct StateT * v8267(struct StateT * v8268);
struct StateT * v4009(struct StateT * v4010);
struct StateT * v8557(struct StateT * v8558);
struct StateT * v9143(struct StateT * v9144);
struct StateT * v8801(struct StateT * v8802);
struct StateT * v4789(struct StateT * v4790);
struct StateT * v5009(struct StateT * v5010);
struct StateT * v8521(struct StateT * v8522);
struct StateT * v8389(struct StateT * v8390);
struct StateT * v8231(struct StateT * v8232);
struct StateT * v8829(struct StateT * v8830);
struct StateT * v4735(struct StateT * v4736);
struct StateT * v8933(struct StateT * v8934);
struct StateT * v1297(struct StateT * v1298);
struct StateT * v8731(struct StateT * v8732);
struct StateT * v8775(struct StateT * v8776);
struct StateT * v8241(struct StateT * v8242);
struct StateT * v3443(struct StateT * v3444);
struct StateT * v8205(struct StateT * v8206);
struct StateT * v3931(struct StateT * v3932);
struct StateT * v7785(struct StateT * v7786);
struct StateT * v8297(struct StateT * v8298);
struct StateT * v8257(struct StateT * v8258);
struct StateT * v5067(struct StateT * v5068);
struct StateT * v8899(struct StateT * v8900);
struct StateT * v833(struct StateT * v834);
struct StateT * v8337(struct StateT * v8338);
struct StateT * v7765(struct StateT * v7766);
struct StateT * v1745(struct StateT * v1746);
struct StateT * v549(struct StateT * v550);
struct StateT * v9091(struct StateT * v9092);
struct StateT * v8685(struct StateT * v8686);
struct StateT * v4681(struct StateT * v4682);
struct StateT * v387(struct StateT * v388);
struct StateT * v4087(struct StateT * v4088);
struct StateT * v1461(struct StateT * v1462);
struct StateT * v171(struct StateT * v172);
struct StateT * v3359(struct StateT * v3360);
struct StateT * v8363(struct StateT * v8364);
struct StateT * v9187(struct StateT * v9188);
struct StateT * v8531(struct StateT * v8532);
struct StateT * v3459(struct StateT * v3460);
struct StateT * v7855(struct StateT * v7856);
struct StateT * v1915(struct StateT * v1916);
struct StateT * v8723(struct StateT * v8724);
struct StateT * v1439(struct StateT * v1440);
struct StateT * v7899(struct StateT * v7900);
struct StateT * v9073(struct StateT * v9074);
struct StateT * v9151(struct StateT * v9152);
struct StateT * v7909(struct StateT * v7910);
struct StateT * v8625(struct StateT * v8626);
struct StateT * v8749(struct StateT * v8750);
struct StateT * v3385(struct StateT * v3386);
struct StateT * v8103(struct StateT * v8104);
struct StateT * v9135(struct StateT * v9136);
struct StateT * v9197(struct StateT * v9198);
struct StateT * v9207(struct StateT * v9208);
struct StateT * v8113(struct StateT * v8114);
struct StateT * v5357(struct StateT * v5358);
struct StateT * v8425(struct StateT * v8426);
struct StateT * v4249(struct StateT * v4250);
struct StateT * v603(struct StateT * v604);
struct StateT * v8757(struct StateT * v8758);
struct StateT * v4519(struct StateT * v4520);
struct StateT * v8047(struct StateT * v8048);
struct StateT * v8461(struct StateT * v8462);
struct StateT * v495(struct StateT * v496);
struct StateT * v8491(struct StateT * v8492);
struct StateT * v1431(struct StateT * v1432);
struct StateT * v8307(struct StateT * v8308);
struct StateT * v5531(struct StateT * v5532);
struct StateT * v3663(struct StateT * v3664);
struct StateT * v1799(struct StateT * v1800);
struct StateT * v9109(struct StateT * v9110);
struct StateT * v117(struct StateT * v118);
struct StateT * v5713(struct StateT * v5714);
struct StateT * v9083(struct StateT * v9084);
struct StateT * v9(struct StateT * v10);
struct StateT * v3349(struct StateT * v3350);
struct StateT * v1007(struct StateT * v1008);
struct StateT * v8993(struct StateT * v8994);
struct StateT * v5647(struct StateT * v5648);
struct StateT * v8783(struct StateT * v8784);
struct StateT * v9169(struct StateT * v9170);
struct StateT * v8907(struct StateT * v8908);
struct StateT * v7821(struct StateT * v7822);
struct StateT * v1529(struct StateT * v1530);
struct StateT * v8133(struct StateT * v8134);
struct StateT * v1181(struct StateT * v1182);
struct StateT * v8031(struct StateT * v8032);
struct StateT * v8013(struct StateT * v8014);
struct StateT * v7919(struct StateT * v7920);
struct StateT * v8675(struct StateT * v8676);
struct StateT * v8057(struct StateT * v8058);
struct StateT * v7775(struct StateT * v7776);
struct StateT * v7847(struct StateT * v7848);
struct StateT * v4897(struct StateT * v4898);
struct StateT * v9235(struct StateT * v9236);
struct StateT * v3863(struct StateT * v3864);
struct StateT * v9013(struct StateT * v9014);
struct StateT * v8153(struct StateT * v8154);
struct StateT * v4047(struct StateT * v4048);
struct StateT * v1455(struct StateT * v1456);
struct StateT * v1853(struct StateT * v1854);
struct StateT * v279(struct StateT * v280);
struct StateT * v8287(struct StateT * v8288);
struct StateT * v8617(struct StateT * v8618);
struct StateT * v8123(struct StateT * v8124);
struct StateT * v8501(struct StateT * v8502);
struct StateT * v8481(struct StateT * v8482);
struct StateT * v7969(struct StateT * v7970);
struct StateT * v711(struct StateT * v712);
struct StateT * v8093(struct StateT * v8094);
struct StateT * v8793(struct StateT * v8794);
struct StateT * v7939(struct StateT * v7940);
struct StateT * v8441(struct StateT * v8442);
struct StateT * v4039(struct StateT * v4040);
struct StateT * v8381(struct StateT * v8382);
struct StateT * v7881(struct StateT * v7882);
struct StateT * v1923(struct StateT * v1924);
struct StateT * v8433(struct StateT * v8434);
struct StateT * v8889(struct StateT * v8890);
struct StateT * v7929(struct StateT * v7930);
struct StateT * v1583(struct StateT * v1584);
struct StateT * v8511(struct StateT * v8512);
struct StateT * v5299(struct StateT * v5300);
struct StateT * v1931(struct StateT * v1932);
struct StateT * v3731(struct StateT * v3732);
struct StateT * v3653(struct StateT * v3654);
struct StateT * v3527(struct StateT * v3528);
struct StateT * v8189(struct StateT * v8190);
struct StateT * v7755(struct StateT * v7756);
struct StateT * v3369(struct StateT * v3370);
struct StateT * v9217(struct StateT * v9218);
struct StateT * v8355(struct StateT * v8356);
struct StateT * v8715(struct StateT * v8716);
struct StateT * v1355(struct StateT * v1356);
struct StateT * v4951(struct StateT * v4952);
struct StateT * v3375(struct StateT * v3376);
struct StateT * v8583(struct StateT * v8584);
struct StateT * snippet(struct StateT * v0);
struct StateT * v1(struct StateT * v2);
struct StateT * v7995(struct StateT * v7996);
struct StateT * v9125(struct StateT * v9126);
struct StateT * v7987(struct StateT * v7988);
struct StateT * v8849(struct StateT * v8850);
struct StateT * v8451(struct StateT * v8452);
struct StateT * v8347(struct StateT * v8348);
struct StateT * v4303(struct StateT * v4304);
struct StateT * v8249(struct StateT * v8250);
struct StateT * v7811(struct StateT * v7812) {
  int v7813 = v7812->timer;
  int v10900 = v7813 + 1;
  v7812->timer = v10900;int * v7815 = v7812->regs;
  int v7816 = v7815[15];
  int * v7817 = v7812->regs;
  int v7818 = v7817[9];
  int * v7819 = v7812->regs;
  int v10906 = v7816 | v7818;
  v7819[15] = v10906;
  struct StateT * v10898 = v7821(v7812);
  return v10898;
}

struct StateT * v8839(struct StateT * v8840) {
  int v8841 = v8840->timer;
  int v9708 = v8841 + 1;
  v8840->timer = v9708;int * v8843 = v8840->regs;
  int v8844 = v8843[26];
  int * v8845 = v8840->regs;
  int v8846 = v8845[6];
  int * v8847 = v8840->regs;
  int v9714 = v8844 ^ v8846;
  v8847[26] = v9714;
  struct StateT * v9706 = v8849(v8840);
  return v9706;
}

struct StateT * v9063(struct StateT * v9064) {
  int v9065 = v9064->timer;
  int v9449 = v9065 + 1;
  v9064->timer = v9449;int * v9067 = v9064->regs;
  int v9068 = v9067[13];
  int * v9069 = v9064->regs;
  int v9070 = v9069[26];
  int * v9071 = v9064->regs;
  int v9456 = v9068 + v9070;
  v9071[6] = v9456;
  struct StateT * v9447 = v9073(v9064);
  return v9447;
}

struct StateT * v9033(struct StateT * v9034) {
  int v9035 = v9034->timer;
  int v9485 = v9035 + 1;
  v9034->timer = v9485;int * v9037 = v9034->regs;
  int v9038 = v9037[1];
  int * v9039 = v9034->regs;
  int v9040 = v9039[8];
  int * v9041 = v9034->regs;
  int v9491 = v9038 ^ v9040;
  v9041[1] = v9491;
  struct StateT * v9483 = v9043(v9034);
  return v9483;
}

struct StateT * v8985(struct StateT * v8986) {
  int v8987 = v8986->timer;
  int v9540 = v8987 + 1;
  v8986->timer = v9540;int * v8989 = v8986->regs;
  int v8990 = v8989[8];
  int * v8991 = v8986->regs;
  int v9544 = v8990 << 13;
  v8991[8] = v9544;
  struct StateT * v9538 = v8993(v8986);
  return v9538;
}

struct StateT * v4843(struct StateT * v4844) {
  int v4845 = v4844->timer;
  int v6399 = v4845 + 1;
  v4844->timer = v6399;int * v4847 = v4844->regs;
  int v4848 = v4847[10];
  int * v4849 = v4844->regs;
  int v4850 = v4849[1];
  int * v4851 = v4844->cache_keys;
  int v4852 = v4851[0];
  bool v6406 = v4852 == ((int)((unsigned int)(v4848 + 56) >> 2));
  int v4896 = (v6406 ? ({
    int * v4853 = v4844->cache_vals;
    v4853[0] = v4850;
    v4850;
  }) : ({
    int * v4856 = v4844->cache_keys;
    int v4857 = v4856[1];
    bool v6410 = v4857 == ((int)((unsigned int)(v4848 + 56) >> 2));
    int v4894 = (v6410 ? ({
      int * v4858 = v4844->cache_keys;
      int * v4859 = v4844->cache_keys;
      int v4860 = v4859[0];
      v4858[1] = v4860;
      int * v4862 = v4844->cache_vals;
      int * v4863 = v4844->cache_vals;
      int v4864 = v4863[0];
      v4862[1] = v4864;
      int * v4866 = v4844->cache_keys;
      int v6418 = (int)((unsigned int)(v4848 + 56) >> 2);
      v4866[0] = v6418;
      int * v4868 = v4844->cache_vals;
      v4868[0] = v4850;
      int v4870 = v4844->timer;
      int v6421 = v4870 + 1;
      v4844->timer = v6421;v4850;
    }) : ({
      int * v4873 = v4844->mem;
      int * v4874 = v4844->cache_keys;
      int v4875 = v4874[1];
      int * v4876 = v4844->cache_vals;
      int v4877 = v4876[1];
      v4873[v4875] = v4877;
      int * v4879 = v4844->cache_keys;
      int * v4880 = v4844->cache_keys;
      int v4881 = v4880[0];
      v4879[1] = v4881;
      int * v4883 = v4844->cache_vals;
      int * v4884 = v4844->cache_vals;
      int v4885 = v4884[0];
      v4883[1] = v4885;
      int * v4887 = v4844->cache_keys;
      int v6434 = (int)((unsigned int)(v4848 + 56) >> 2);
      v4887[0] = v6434;
      int * v4889 = v4844->cache_vals;
      v4889[0] = v4850;
      int v4891 = v4844->timer;
      int v6437 = v4891 + 100;
      v4844->timer = v6437;v4850;
    }));
    v4894;
  }));
  struct StateT * v6397 = v4897(v4844);
  return v6397;
}

struct StateT * v3595(struct StateT * v3596) {
  int v3597 = v3596->timer;
  int v7475 = v3597 + 1;
  v3596->timer = v7475;int * v3599 = v3596->regs;
  int v3600 = v3599[2];
  int * v3601 = v3596->cache_keys;
  int v3602 = v3601[0];
  bool v7480 = v3602 == ((int)((unsigned int)(v3600 + 20) >> 2));
  int v3650 = (v7480 ? ({
    int * v3603 = v3596->cache_vals;
    int v3604 = v3603[0];
    v3604;
  }) : ({
    int * v3606 = v3596->cache_keys;
    int v3607 = v3606[1];
    bool v7485 = v3607 == ((int)((unsigned int)(v3600 + 20) >> 2));
    int v3648 = (v7485 ? ({
      int * v3608 = v3596->cache_vals;
      int v3609 = v3608[1];
      int * v3610 = v3596->cache_keys;
      int * v3611 = v3596->cache_keys;
      int v3612 = v3611[0];
      v3610[1] = v3612;
      int * v3614 = v3596->cache_vals;
      int * v3615 = v3596->cache_vals;
      int v3616 = v3615[0];
      v3614[1] = v3616;
      int * v3618 = v3596->cache_keys;
      int v7494 = (int)((unsigned int)(v3600 + 20) >> 2);
      v3618[0] = v7494;
      int * v3620 = v3596->cache_vals;
      v3620[0] = v3609;
      int v3622 = v3596->timer;
      int v7497 = v3622 + 1;
      v3596->timer = v7497;v3609;
    }) : ({
      int * v3625 = v3596->mem;
      int v7499 = (int)((unsigned int)(v3600 + 20) >> 2);
      int v3626 = v3625[v7499];
      int * v3627 = v3596->mem;
      int * v3628 = v3596->cache_keys;
      int v3629 = v3628[1];
      int * v3630 = v3596->cache_vals;
      int v3631 = v3630[1];
      v3627[v3629] = v3631;
      int * v3633 = v3596->cache_keys;
      int * v3634 = v3596->cache_keys;
      int v3635 = v3634[0];
      v3633[1] = v3635;
      int * v3637 = v3596->cache_vals;
      int * v3638 = v3596->cache_vals;
      int v3639 = v3638[0];
      v3637[1] = v3639;
      int * v3641 = v3596->cache_keys;
      v3641[0] = v7499;
      int * v3643 = v3596->cache_vals;
      v3643[0] = v3626;
      int v3645 = v3596->timer;
      int v7514 = v3645 + 100;
      v3596->timer = v7514;v3626;
    }));
    v3648;
  }));
  int * v3651 = v3596->regs;
  v3651[7] = v3650;
  struct StateT * v7473 = v3653(v3596);
  return v7473;
}

struct StateT * v3737(struct StateT * v3738) {
  int v3739 = v3738->timer;
  int v7349 = v3739 + 1;
  v3738->timer = v7349;int * v3741 = v3738->regs;
  int v3742 = v3741[2];
  int * v3743 = v3738->cache_keys;
  int v3744 = v3743[0];
  bool v7354 = v3744 == ((int)((unsigned int)(v3742 + 28) >> 2));
  int v3792 = (v7354 ? ({
    int * v3745 = v3738->cache_vals;
    int v3746 = v3745[0];
    v3746;
  }) : ({
    int * v3748 = v3738->cache_keys;
    int v3749 = v3748[1];
    bool v7359 = v3749 == ((int)((unsigned int)(v3742 + 28) >> 2));
    int v3790 = (v7359 ? ({
      int * v3750 = v3738->cache_vals;
      int v3751 = v3750[1];
      int * v3752 = v3738->cache_keys;
      int * v3753 = v3738->cache_keys;
      int v3754 = v3753[0];
      v3752[1] = v3754;
      int * v3756 = v3738->cache_vals;
      int * v3757 = v3738->cache_vals;
      int v3758 = v3757[0];
      v3756[1] = v3758;
      int * v3760 = v3738->cache_keys;
      int v7368 = (int)((unsigned int)(v3742 + 28) >> 2);
      v3760[0] = v7368;
      int * v3762 = v3738->cache_vals;
      v3762[0] = v3751;
      int v3764 = v3738->timer;
      int v7371 = v3764 + 1;
      v3738->timer = v7371;v3751;
    }) : ({
      int * v3767 = v3738->mem;
      int v7373 = (int)((unsigned int)(v3742 + 28) >> 2);
      int v3768 = v3767[v7373];
      int * v3769 = v3738->mem;
      int * v3770 = v3738->cache_keys;
      int v3771 = v3770[1];
      int * v3772 = v3738->cache_vals;
      int v3773 = v3772[1];
      v3769[v3771] = v3773;
      int * v3775 = v3738->cache_keys;
      int * v3776 = v3738->cache_keys;
      int v3777 = v3776[0];
      v3775[1] = v3777;
      int * v3779 = v3738->cache_vals;
      int * v3780 = v3738->cache_vals;
      int v3781 = v3780[0];
      v3779[1] = v3781;
      int * v3783 = v3738->cache_keys;
      v3783[0] = v7373;
      int * v3785 = v3738->cache_vals;
      v3785[0] = v3768;
      int v3787 = v3738->timer;
      int v7388 = v3787 + 100;
      v3738->timer = v7388;v3768;
    }));
    v3790;
  }));
  int * v3793 = v3738->regs;
  v3793[30] = v3792;
  struct StateT * v7347 = v3795(v3738);
  return v7347;
}

struct StateT * v4465(struct StateT * v4466) {
  int v4467 = v4466->timer;
  int v6713 = v4467 + 1;
  v4466->timer = v6713;int * v4469 = v4466->regs;
  int v4470 = v4469[10];
  int * v4471 = v4466->regs;
  int v4472 = v4471[25];
  int * v4473 = v4466->cache_keys;
  int v4474 = v4473[0];
  bool v6720 = v4474 == ((int)((unsigned int)(v4470 + 28) >> 2));
  int v4518 = (v6720 ? ({
    int * v4475 = v4466->cache_vals;
    v4475[0] = v4472;
    v4472;
  }) : ({
    int * v4478 = v4466->cache_keys;
    int v4479 = v4478[1];
    bool v6725 = v4479 == ((int)((unsigned int)(v4470 + 28) >> 2));
    int v4516 = (v6725 ? ({
      int * v4480 = v4466->cache_keys;
      int * v4481 = v4466->cache_keys;
      int v4482 = v4481[0];
      v4480[1] = v4482;
      int * v4484 = v4466->cache_vals;
      int * v4485 = v4466->cache_vals;
      int v4486 = v4485[0];
      v4484[1] = v4486;
      int * v4488 = v4466->cache_keys;
      int v6733 = (int)((unsigned int)(v4470 + 28) >> 2);
      v4488[0] = v6733;
      int * v4490 = v4466->cache_vals;
      v4490[0] = v4472;
      int v4492 = v4466->timer;
      int v6736 = v4492 + 1;
      v4466->timer = v6736;v4472;
    }) : ({
      int * v4495 = v4466->mem;
      int * v4496 = v4466->cache_keys;
      int v4497 = v4496[1];
      int * v4498 = v4466->cache_vals;
      int v4499 = v4498[1];
      v4495[v4497] = v4499;
      int * v4501 = v4466->cache_keys;
      int * v4502 = v4466->cache_keys;
      int v4503 = v4502[0];
      v4501[1] = v4503;
      int * v4505 = v4466->cache_vals;
      int * v4506 = v4466->cache_vals;
      int v4507 = v4506[0];
      v4505[1] = v4507;
      int * v4509 = v4466->cache_keys;
      int v6749 = (int)((unsigned int)(v4470 + 28) >> 2);
      v4509[0] = v6749;
      int * v4511 = v4466->cache_vals;
      v4511[0] = v4472;
      int v4513 = v4466->timer;
      int v6752 = v4513 + 100;
      v4466->timer = v6752;v4472;
    }));
    v4516;
  }));
  struct StateT * v6711 = v4519(v4466);
  return v6711;
}

struct StateT * v4627(struct StateT * v4628) {
  int v4629 = v4628->timer;
  int v6578 = v4629 + 1;
  v4628->timer = v6578;int * v4631 = v4628->regs;
  int v4632 = v4631[10];
  int * v4633 = v4628->regs;
  int v4634 = v4633[7];
  int * v4635 = v4628->cache_keys;
  int v4636 = v4635[0];
  bool v6585 = v4636 == ((int)((unsigned int)(v4632 + 40) >> 2));
  int v4680 = (v6585 ? ({
    int * v4637 = v4628->cache_vals;
    v4637[0] = v4634;
    v4634;
  }) : ({
    int * v4640 = v4628->cache_keys;
    int v4641 = v4640[1];
    bool v6590 = v4641 == ((int)((unsigned int)(v4632 + 40) >> 2));
    int v4678 = (v6590 ? ({
      int * v4642 = v4628->cache_keys;
      int * v4643 = v4628->cache_keys;
      int v4644 = v4643[0];
      v4642[1] = v4644;
      int * v4646 = v4628->cache_vals;
      int * v4647 = v4628->cache_vals;
      int v4648 = v4647[0];
      v4646[1] = v4648;
      int * v4650 = v4628->cache_keys;
      int v6598 = (int)((unsigned int)(v4632 + 40) >> 2);
      v4650[0] = v6598;
      int * v4652 = v4628->cache_vals;
      v4652[0] = v4634;
      int v4654 = v4628->timer;
      int v6601 = v4654 + 1;
      v4628->timer = v6601;v4634;
    }) : ({
      int * v4657 = v4628->mem;
      int * v4658 = v4628->cache_keys;
      int v4659 = v4658[1];
      int * v4660 = v4628->cache_vals;
      int v4661 = v4660[1];
      v4657[v4659] = v4661;
      int * v4663 = v4628->cache_keys;
      int * v4664 = v4628->cache_keys;
      int v4665 = v4664[0];
      v4663[1] = v4665;
      int * v4667 = v4628->cache_vals;
      int * v4668 = v4628->cache_vals;
      int v4669 = v4668[0];
      v4667[1] = v4669;
      int * v4671 = v4628->cache_keys;
      int v6614 = (int)((unsigned int)(v4632 + 40) >> 2);
      v4671[0] = v6614;
      int * v4673 = v4628->cache_vals;
      v4673[0] = v4634;
      int v4675 = v4628->timer;
      int v6617 = v4675 + 100;
      v4628->timer = v6617;v4634;
    }));
    v4678;
  }));
  struct StateT * v6576 = v4681(v4628);
  return v6576;
}

struct StateT * v8655(struct StateT * v8656) {
  int v8657 = v8656->timer;
  int v9921 = v8657 + 1;
  v8656->timer = v9921;int * v8659 = v8656->regs;
  int v8660 = v8659[8];
  int * v8661 = v8656->regs;
  int v8662 = v8661[16];
  int * v8663 = v8656->regs;
  int v9928 = v8660 ^ v8662;
  v8663[17] = v9928;
  struct StateT * v9919 = v8665(v8656);
  return v9919;
}

struct StateT * v8407(struct StateT * v8408) {
  int v8409 = v8408->timer;
  int v10211 = v8409 + 1;
  v8408->timer = v10211;int * v8411 = v8408->regs;
  int v8412 = v8411[17];
  int * v8413 = v8408->regs;
  int v10215 = v8412 << 18;
  v8413[17] = v10215;
  struct StateT * v10209 = v8415(v8408);
  return v10209;
}

struct StateT * v9043(struct StateT * v9044) {
  int v9045 = v9044->timer;
  int v9473 = v9045 + 1;
  v9044->timer = v9473;int * v9047 = v9044->regs;
  int v9048 = v9047[14];
  int * v9049 = v9044->regs;
  int v9050 = v9049[27];
  int * v9051 = v9044->regs;
  int v9480 = v9048 + v9050;
  v9051[11] = v9480;
  struct StateT * v9471 = v9053(v9044);
  return v9471;
}

struct StateT * v8565(struct StateT * v8566) {
  int v8567 = v8566->timer;
  int v10028 = v8567 + 1;
  v8566->timer = v10028;int * v8569 = v8566->regs;
  int v8570 = v8569[11];
  int * v8571 = v8566->regs;
  int v10032 = v8570 << 7;
  v8571[11] = v10032;
  struct StateT * v10026 = v8573(v8566);
  return v10026;
}

struct StateT * v8415(struct StateT * v8416) {
  int v8417 = v8416->timer;
  int v10200 = v8417 + 1;
  v8416->timer = v10200;int * v8419 = v8416->regs;
  int v8420 = v8419[17];
  int * v8421 = v8416->regs;
  int v8422 = v8421[6];
  int * v8423 = v8416->regs;
  int v10206 = v8420 | v8422;
  v8423[17] = v10206;
  struct StateT * v10198 = v8425(v8416);
  return v10198;
}

struct StateT * v3721(struct StateT * v3722) {
  int v3723 = v3722->timer;
  int v7405 = v3723 + 1;
  v3722->timer = v7405;int * v3725 = v3722->regs;
  int v3726 = v3725[13];
  int * v3727 = v3722->regs;
  int v3728 = v3727[7];
  int * v3729 = v3722->regs;
  int v7411 = v3726 + v3728;
  v3729[13] = v7411;
  struct StateT * v7403 = v3731(v3722);
  return v7403;
}

struct StateT * v8967(struct StateT * v8968) {
  int v8969 = v8968->timer;
  int v9559 = v8969 + 1;
  v8968->timer = v9559;int * v8971 = v8968->regs;
  int v8972 = v8971[6];
  int * v8973 = v8968->regs;
  int v8974 = v8973[9];
  int * v8975 = v8968->regs;
  int v9565 = v8972 | v8974;
  v8975[6] = v9565;
  struct StateT * v9557 = v8977(v8968);
  return v9557;
}

struct StateT * v63(struct StateT * v64) {
  int v65 = v64->timer;
  int v13515 = v65 + 1;
  v64->timer = v13515;int * v67 = v64->regs;
  int v68 = v67[2];
  int * v69 = v64->regs;
  int v70 = v69[8];
  int * v71 = v64->cache_keys;
  int v72 = v71[0];
  bool v13522 = v72 == ((int)((unsigned int)(v68 + 88) >> 2));
  int v116 = (v13522 ? ({
    int * v73 = v64->cache_vals;
    v73[0] = v70;
    v70;
  }) : ({
    int * v76 = v64->cache_keys;
    int v77 = v76[1];
    bool v13527 = v77 == ((int)((unsigned int)(v68 + 88) >> 2));
    int v114 = (v13527 ? ({
      int * v78 = v64->cache_keys;
      int * v79 = v64->cache_keys;
      int v80 = v79[0];
      v78[1] = v80;
      int * v82 = v64->cache_vals;
      int * v83 = v64->cache_vals;
      int v84 = v83[0];
      v82[1] = v84;
      int * v86 = v64->cache_keys;
      int v13535 = (int)((unsigned int)(v68 + 88) >> 2);
      v86[0] = v13535;
      int * v88 = v64->cache_vals;
      v88[0] = v70;
      int v90 = v64->timer;
      int v13538 = v90 + 1;
      v64->timer = v13538;v70;
    }) : ({
      int * v93 = v64->mem;
      int * v94 = v64->cache_keys;
      int v95 = v94[1];
      int * v96 = v64->cache_vals;
      int v97 = v96[1];
      v93[v95] = v97;
      int * v99 = v64->cache_keys;
      int * v100 = v64->cache_keys;
      int v101 = v100[0];
      v99[1] = v101;
      int * v103 = v64->cache_vals;
      int * v104 = v64->cache_vals;
      int v105 = v104[0];
      v103[1] = v105;
      int * v107 = v64->cache_keys;
      int v13551 = (int)((unsigned int)(v68 + 88) >> 2);
      v107[0] = v13551;
      int * v109 = v64->cache_vals;
      v109[0] = v70;
      int v111 = v64->timer;
      int v13554 = v111 + 100;
      v64->timer = v13554;v70;
    }));
    v114;
  }));
  struct StateT * v13513 = v117(v64);
  return v13513;
}

struct StateT * v9117(struct StateT * v9118) {
  int v9119 = v9118->timer;
  int v9388 = v9119 + 1;
  v9118->timer = v9388;int * v9121 = v9118->regs;
  int v9122 = v9121[15];
  int * v9123 = v9118->regs;
  int v9392 = v9122 << 18;
  v9123[15] = v9392;
  struct StateT * v9386 = v9125(v9118);
  return v9386;
}

struct StateT * v441(struct StateT * v442) {
  int v443 = v442->timer;
  int v13200 = v443 + 1;
  v442->timer = v13200;int * v445 = v442->regs;
  int v446 = v445[2];
  int * v447 = v442->regs;
  int v448 = v447[23];
  int * v449 = v442->cache_keys;
  int v450 = v449[0];
  bool v13207 = v450 == ((int)((unsigned int)(v446 + 60) >> 2));
  int v494 = (v13207 ? ({
    int * v451 = v442->cache_vals;
    v451[0] = v448;
    v448;
  }) : ({
    int * v454 = v442->cache_keys;
    int v455 = v454[1];
    bool v13212 = v455 == ((int)((unsigned int)(v446 + 60) >> 2));
    int v492 = (v13212 ? ({
      int * v456 = v442->cache_keys;
      int * v457 = v442->cache_keys;
      int v458 = v457[0];
      v456[1] = v458;
      int * v460 = v442->cache_vals;
      int * v461 = v442->cache_vals;
      int v462 = v461[0];
      v460[1] = v462;
      int * v464 = v442->cache_keys;
      int v13220 = (int)((unsigned int)(v446 + 60) >> 2);
      v464[0] = v13220;
      int * v466 = v442->cache_vals;
      v466[0] = v448;
      int v468 = v442->timer;
      int v13223 = v468 + 1;
      v442->timer = v13223;v448;
    }) : ({
      int * v471 = v442->mem;
      int * v472 = v442->cache_keys;
      int v473 = v472[1];
      int * v474 = v442->cache_vals;
      int v475 = v474[1];
      v471[v473] = v475;
      int * v477 = v442->cache_keys;
      int * v478 = v442->cache_keys;
      int v479 = v478[0];
      v477[1] = v479;
      int * v481 = v442->cache_vals;
      int * v482 = v442->cache_vals;
      int v483 = v482[0];
      v481[1] = v483;
      int * v485 = v442->cache_keys;
      int v13236 = (int)((unsigned int)(v446 + 60) >> 2);
      v485[0] = v13236;
      int * v487 = v442->cache_vals;
      v487[0] = v448;
      int v489 = v442->timer;
      int v13239 = v489 + 100;
      v442->timer = v13239;v448;
    }));
    v492;
  }));
  struct StateT * v13198 = v495(v442);
  return v13198;
}

struct StateT * v9099(struct StateT * v9100) {
  int v9101 = v9100->timer;
  int v9407 = v9101 + 1;
  v9100->timer = v9407;int * v9103 = v9100->regs;
  int v9104 = v9103[11];
  int * v9105 = v9100->regs;
  int v9106 = v9105[9];
  int * v9107 = v9100->regs;
  int v9413 = v9104 | v9106;
  v9107[11] = v9413;
  struct StateT * v9405 = v9109(v9100);
  return v9405;
}

struct StateT * v4195(struct StateT * v4196) {
  int v4197 = v4196->timer;
  int v6938 = v4197 + 1;
  v4196->timer = v6938;int * v4199 = v4196->regs;
  int v4200 = v4199[10];
  int * v4201 = v4196->regs;
  int v4202 = v4201[28];
  int * v4203 = v4196->cache_keys;
  int v4204 = v4203[0];
  bool v6945 = v4204 == ((int)((unsigned int)(v4200 + 8) >> 2));
  int v4248 = (v6945 ? ({
    int * v4205 = v4196->cache_vals;
    v4205[0] = v4202;
    v4202;
  }) : ({
    int * v4208 = v4196->cache_keys;
    int v4209 = v4208[1];
    bool v6950 = v4209 == ((int)((unsigned int)(v4200 + 8) >> 2));
    int v4246 = (v6950 ? ({
      int * v4210 = v4196->cache_keys;
      int * v4211 = v4196->cache_keys;
      int v4212 = v4211[0];
      v4210[1] = v4212;
      int * v4214 = v4196->cache_vals;
      int * v4215 = v4196->cache_vals;
      int v4216 = v4215[0];
      v4214[1] = v4216;
      int * v4218 = v4196->cache_keys;
      int v6958 = (int)((unsigned int)(v4200 + 8) >> 2);
      v4218[0] = v6958;
      int * v4220 = v4196->cache_vals;
      v4220[0] = v4202;
      int v4222 = v4196->timer;
      int v6961 = v4222 + 1;
      v4196->timer = v6961;v4202;
    }) : ({
      int * v4225 = v4196->mem;
      int * v4226 = v4196->cache_keys;
      int v4227 = v4226[1];
      int * v4228 = v4196->cache_vals;
      int v4229 = v4228[1];
      v4225[v4227] = v4229;
      int * v4231 = v4196->cache_keys;
      int * v4232 = v4196->cache_keys;
      int v4233 = v4232[0];
      v4231[1] = v4233;
      int * v4235 = v4196->cache_vals;
      int * v4236 = v4196->cache_vals;
      int v4237 = v4236[0];
      v4235[1] = v4237;
      int * v4239 = v4196->cache_keys;
      int v6974 = (int)((unsigned int)(v4200 + 8) >> 2);
      v4239[0] = v6974;
      int * v4241 = v4196->cache_vals;
      v4241[0] = v4202;
      int v4243 = v4196->timer;
      int v6977 = v4243 + 100;
      v4196->timer = v6977;v4202;
    }));
    v4246;
  }));
  struct StateT * v6936 = v4249(v4196);
  return v6936;
}

struct StateT * v5183(struct StateT * v5184) {
  int v5185 = v5184->timer;
  int v6114 = v5185 + 1;
  v5184->timer = v6114;int * v5187 = v5184->regs;
  int v5188 = v5187[2];
  int * v5189 = v5184->cache_keys;
  int v5190 = v5189[0];
  bool v6119 = v5190 == ((int)((unsigned int)(v5188 + 76) >> 2));
  int v5238 = (v6119 ? ({
    int * v5191 = v5184->cache_vals;
    int v5192 = v5191[0];
    v5192;
  }) : ({
    int * v5194 = v5184->cache_keys;
    int v5195 = v5194[1];
    bool v6124 = v5195 == ((int)((unsigned int)(v5188 + 76) >> 2));
    int v5236 = (v6124 ? ({
      int * v5196 = v5184->cache_vals;
      int v5197 = v5196[1];
      int * v5198 = v5184->cache_keys;
      int * v5199 = v5184->cache_keys;
      int v5200 = v5199[0];
      v5198[1] = v5200;
      int * v5202 = v5184->cache_vals;
      int * v5203 = v5184->cache_vals;
      int v5204 = v5203[0];
      v5202[1] = v5204;
      int * v5206 = v5184->cache_keys;
      int v6133 = (int)((unsigned int)(v5188 + 76) >> 2);
      v5206[0] = v6133;
      int * v5208 = v5184->cache_vals;
      v5208[0] = v5197;
      int v5210 = v5184->timer;
      int v6136 = v5210 + 1;
      v5184->timer = v6136;v5197;
    }) : ({
      int * v5213 = v5184->mem;
      int v6138 = (int)((unsigned int)(v5188 + 76) >> 2);
      int v5214 = v5213[v6138];
      int * v5215 = v5184->mem;
      int * v5216 = v5184->cache_keys;
      int v5217 = v5216[1];
      int * v5218 = v5184->cache_vals;
      int v5219 = v5218[1];
      v5215[v5217] = v5219;
      int * v5221 = v5184->cache_keys;
      int * v5222 = v5184->cache_keys;
      int v5223 = v5222[0];
      v5221[1] = v5223;
      int * v5225 = v5184->cache_vals;
      int * v5226 = v5184->cache_vals;
      int v5227 = v5226[0];
      v5225[1] = v5227;
      int * v5229 = v5184->cache_keys;
      v5229[0] = v6138;
      int * v5231 = v5184->cache_vals;
      v5231[0] = v5214;
      int v5233 = v5184->timer;
      int v6153 = v5233 + 100;
      v5184->timer = v6153;v5214;
    }));
    v5236;
  }));
  int * v5239 = v5184->regs;
  v5239[19] = v5238;
  struct StateT * v6112 = v5241(v5184);
  return v6112;
}

struct StateT * v8073(struct StateT * v8074) {
  int v8075 = v8074->timer;
  int v10598 = v8075 + 1;
  v8074->timer = v10598;int * v8077 = v8074->regs;
  int v8078 = v8077[18];
  int * v8079 = v8074->regs;
  int v8080 = v8079[20];
  int * v8081 = v8074->regs;
  int v10604 = v8078 | v8080;
  v8081[18] = v10604;
  struct StateT * v10596 = v8083(v8074);
  return v10596;
}

struct StateT * v8547(struct StateT * v8548) {
  int v8549 = v8548->timer;
  int v10047 = v8549 + 1;
  v8548->timer = v10047;int * v8551 = v8548->regs;
  int v8552 = v8551[15];
  int * v8553 = v8548->regs;
  int v8554 = v8553[5];
  int * v8555 = v8548->regs;
  int v10053 = v8552 | v8554;
  v8555[15] = v10053;
  struct StateT * v10045 = v8557(v8548);
  return v10045;
}

struct StateT * v1469(struct StateT * v1470) {
  int v1471 = v1470->timer;
  int v12357 = v1471 + 1;
  v1470->timer = v12357;int * v1473 = v1470->regs;
  v1473[31] = 9;
  struct StateT * v12355 = v1475(v1470);
  return v12355;
}

struct StateT * v8539(struct StateT * v8540) {
  int v8541 = v8540->timer;
  int v10058 = v8541 + 1;
  v8540->timer = v10058;int * v8543 = v8540->regs;
  int v8544 = v8543[15];
  int * v8545 = v8540->regs;
  int v10062 = v8544 << 7;
  v8545[15] = v10062;
  struct StateT * v10056 = v8547(v8540);
  return v10056;
}

struct StateT * v8399(struct StateT * v8400) {
  int v8401 = v8400->timer;
  int v10220 = v8401 + 1;
  v8400->timer = v10220;int * v8403 = v8400->regs;
  int v8404 = v8403[17];
  int * v8405 = v8400->regs;
  int v10225 = (int)((unsigned int)v8404 >> 14);
  v8405[6] = v10225;
  struct StateT * v10218 = v8407(v8400);
  return v10218;
}

struct StateT * v8215(struct StateT * v8216) {
  int v8217 = v8216->timer;
  int v10436 = v8217 + 1;
  v8216->timer = v10436;int * v8219 = v8216->regs;
  int v8220 = v8219[9];
  int * v8221 = v8216->regs;
  int v10441 = (int)((unsigned int)v8220 >> 19);
  v8221[20] = v10441;
  struct StateT * v10434 = v8223(v8216);
  return v10434;
}

struct StateT * v8705(struct StateT * v8706) {
  int v8707 = v8706->timer;
  int v9861 = v8707 + 1;
  v8706->timer = v9861;int * v8709 = v8706->regs;
  int v8710 = v8709[16];
  int * v8711 = v8706->regs;
  int v8712 = v8711[22];
  int * v8713 = v8706->regs;
  int v9868 = v8710 + v8712;
  v8713[8] = v9868;
  struct StateT * v9859 = v8715(v8706);
  return v9859;
}

struct StateT * v891(struct StateT * v892) {
  int v893 = v892->timer;
  int v12820 = v893 + 1;
  v892->timer = v12820;int * v895 = v892->regs;
  int v896 = v895[12];
  int * v897 = v892->cache_keys;
  int v898 = v897[0];
  bool v12825 = v898 == ((int)((unsigned int)(v896 + 12) >> 2));
  int v946 = (v12825 ? ({
    int * v899 = v892->cache_vals;
    int v900 = v899[0];
    v900;
  }) : ({
    int * v902 = v892->cache_keys;
    int v903 = v902[1];
    bool v12830 = v903 == ((int)((unsigned int)(v896 + 12) >> 2));
    int v944 = (v12830 ? ({
      int * v904 = v892->cache_vals;
      int v905 = v904[1];
      int * v906 = v892->cache_keys;
      int * v907 = v892->cache_keys;
      int v908 = v907[0];
      v906[1] = v908;
      int * v910 = v892->cache_vals;
      int * v911 = v892->cache_vals;
      int v912 = v911[0];
      v910[1] = v912;
      int * v914 = v892->cache_keys;
      int v12839 = (int)((unsigned int)(v896 + 12) >> 2);
      v914[0] = v12839;
      int * v916 = v892->cache_vals;
      v916[0] = v905;
      int v918 = v892->timer;
      int v12842 = v918 + 1;
      v892->timer = v12842;v905;
    }) : ({
      int * v921 = v892->mem;
      int v12844 = (int)((unsigned int)(v896 + 12) >> 2);
      int v922 = v921[v12844];
      int * v923 = v892->mem;
      int * v924 = v892->cache_keys;
      int v925 = v924[1];
      int * v926 = v892->cache_vals;
      int v927 = v926[1];
      v923[v925] = v927;
      int * v929 = v892->cache_keys;
      int * v930 = v892->cache_keys;
      int v931 = v930[0];
      v929[1] = v931;
      int * v933 = v892->cache_vals;
      int * v934 = v892->cache_vals;
      int v935 = v934[0];
      v933[1] = v935;
      int * v937 = v892->cache_keys;
      v937[0] = v12844;
      int * v939 = v892->cache_vals;
      v939[0] = v922;
      int v941 = v892->timer;
      int v12859 = v941 + 100;
      v892->timer = v12859;v922;
    }));
    v944;
  }));
  int * v947 = v892->regs;
  v947[6] = v946;
  struct StateT * v12818 = v949(v892);
  return v12818;
}

struct StateT * v8915(struct StateT * v8916) {
  int v8917 = v8916->timer;
  int v9619 = v8917 + 1;
  v8916->timer = v9619;int * v8919 = v8916->regs;
  int v8920 = v8919[11];
  int * v8921 = v8916->regs;
  int v8922 = v8921[9];
  int * v8923 = v8916->regs;
  int v9625 = v8920 | v8922;
  v8923[11] = v9625;
  struct StateT * v9617 = v8925(v8916);
  return v9617;
}

struct StateT * v7803(struct StateT * v7804) {
  int v7805 = v7804->timer;
  int v10911 = v7805 + 1;
  v7804->timer = v10911;int * v7807 = v7804->regs;
  int v7808 = v7807[15];
  int * v7809 = v7804->regs;
  int v10915 = v7808 << 7;
  v7809[15] = v10915;
  struct StateT * v10909 = v7811(v7804);
  return v10909;
}

struct StateT * v4411(struct StateT * v4412) {
  int v4413 = v4412->timer;
  int v6758 = v4413 + 1;
  v4412->timer = v6758;int * v4415 = v4412->regs;
  int v4416 = v4415[10];
  int * v4417 = v4412->regs;
  int v4418 = v4417[5];
  int * v4419 = v4412->cache_keys;
  int v4420 = v4419[0];
  bool v6765 = v4420 == ((int)((unsigned int)(v4416 + 24) >> 2));
  int v4464 = (v6765 ? ({
    int * v4421 = v4412->cache_vals;
    v4421[0] = v4418;
    v4418;
  }) : ({
    int * v4424 = v4412->cache_keys;
    int v4425 = v4424[1];
    bool v6770 = v4425 == ((int)((unsigned int)(v4416 + 24) >> 2));
    int v4462 = (v6770 ? ({
      int * v4426 = v4412->cache_keys;
      int * v4427 = v4412->cache_keys;
      int v4428 = v4427[0];
      v4426[1] = v4428;
      int * v4430 = v4412->cache_vals;
      int * v4431 = v4412->cache_vals;
      int v4432 = v4431[0];
      v4430[1] = v4432;
      int * v4434 = v4412->cache_keys;
      int v6778 = (int)((unsigned int)(v4416 + 24) >> 2);
      v4434[0] = v6778;
      int * v4436 = v4412->cache_vals;
      v4436[0] = v4418;
      int v4438 = v4412->timer;
      int v6781 = v4438 + 1;
      v4412->timer = v6781;v4418;
    }) : ({
      int * v4441 = v4412->mem;
      int * v4442 = v4412->cache_keys;
      int v4443 = v4442[1];
      int * v4444 = v4412->cache_vals;
      int v4445 = v4444[1];
      v4441[v4443] = v4445;
      int * v4447 = v4412->cache_keys;
      int * v4448 = v4412->cache_keys;
      int v4449 = v4448[0];
      v4447[1] = v4449;
      int * v4451 = v4412->cache_vals;
      int * v4452 = v4412->cache_vals;
      int v4453 = v4452[0];
      v4451[1] = v4453;
      int * v4455 = v4412->cache_keys;
      int v6794 = (int)((unsigned int)(v4416 + 24) >> 2);
      v4455[0] = v6794;
      int * v4457 = v4412->cache_vals;
      v4457[0] = v4418;
      int v4459 = v4412->timer;
      int v6797 = v4459 + 100;
      v4412->timer = v6797;v4418;
    }));
    v4462;
  }));
  struct StateT * v6756 = v4465(v4412);
  return v6756;
}

struct StateT * v1065(struct StateT * v1066) {
  int v1067 = v1066->timer;
  int v12676 = v1067 + 1;
  v1066->timer = v12676;int * v1069 = v1066->regs;
  int v1070 = v1069[12];
  int * v1071 = v1066->cache_keys;
  int v1072 = v1071[0];
  bool v12681 = v1072 == ((int)((unsigned int)(v1070 + 24) >> 2));
  int v1120 = (v12681 ? ({
    int * v1073 = v1066->cache_vals;
    int v1074 = v1073[0];
    v1074;
  }) : ({
    int * v1076 = v1066->cache_keys;
    int v1077 = v1076[1];
    bool v12686 = v1077 == ((int)((unsigned int)(v1070 + 24) >> 2));
    int v1118 = (v12686 ? ({
      int * v1078 = v1066->cache_vals;
      int v1079 = v1078[1];
      int * v1080 = v1066->cache_keys;
      int * v1081 = v1066->cache_keys;
      int v1082 = v1081[0];
      v1080[1] = v1082;
      int * v1084 = v1066->cache_vals;
      int * v1085 = v1066->cache_vals;
      int v1086 = v1085[0];
      v1084[1] = v1086;
      int * v1088 = v1066->cache_keys;
      int v12695 = (int)((unsigned int)(v1070 + 24) >> 2);
      v1088[0] = v12695;
      int * v1090 = v1066->cache_vals;
      v1090[0] = v1079;
      int v1092 = v1066->timer;
      int v12698 = v1092 + 1;
      v1066->timer = v12698;v1079;
    }) : ({
      int * v1095 = v1066->mem;
      int v12700 = (int)((unsigned int)(v1070 + 24) >> 2);
      int v1096 = v1095[v12700];
      int * v1097 = v1066->mem;
      int * v1098 = v1066->cache_keys;
      int v1099 = v1098[1];
      int * v1100 = v1066->cache_vals;
      int v1101 = v1100[1];
      v1097[v1099] = v1101;
      int * v1103 = v1066->cache_keys;
      int * v1104 = v1066->cache_keys;
      int v1105 = v1104[0];
      v1103[1] = v1105;
      int * v1107 = v1066->cache_vals;
      int * v1108 = v1066->cache_vals;
      int v1109 = v1108[0];
      v1107[1] = v1109;
      int * v1111 = v1066->cache_keys;
      v1111[0] = v12700;
      int * v1113 = v1066->cache_vals;
      v1113[0] = v1096;
      int v1115 = v1066->timer;
      int v12715 = v1115 + 100;
      v1066->timer = v12715;v1096;
    }));
    v1118;
  }));
  int * v1121 = v1066->regs;
  v1121[24] = v1120;
  struct StateT * v12674 = v1123(v1066);
  return v12674;
}

struct StateT * v5125(struct StateT * v5126) {
  int v5127 = v5126->timer;
  int v6162 = v5127 + 1;
  v5126->timer = v6162;int * v5129 = v5126->regs;
  int v5130 = v5129[2];
  int * v5131 = v5126->cache_keys;
  int v5132 = v5131[0];
  bool v6167 = v5132 == ((int)((unsigned int)(v5130 + 80) >> 2));
  int v5180 = (v6167 ? ({
    int * v5133 = v5126->cache_vals;
    int v5134 = v5133[0];
    v5134;
  }) : ({
    int * v5136 = v5126->cache_keys;
    int v5137 = v5136[1];
    bool v6172 = v5137 == ((int)((unsigned int)(v5130 + 80) >> 2));
    int v5178 = (v6172 ? ({
      int * v5138 = v5126->cache_vals;
      int v5139 = v5138[1];
      int * v5140 = v5126->cache_keys;
      int * v5141 = v5126->cache_keys;
      int v5142 = v5141[0];
      v5140[1] = v5142;
      int * v5144 = v5126->cache_vals;
      int * v5145 = v5126->cache_vals;
      int v5146 = v5145[0];
      v5144[1] = v5146;
      int * v5148 = v5126->cache_keys;
      int v6181 = (int)((unsigned int)(v5130 + 80) >> 2);
      v5148[0] = v6181;
      int * v5150 = v5126->cache_vals;
      v5150[0] = v5139;
      int v5152 = v5126->timer;
      int v6184 = v5152 + 1;
      v5126->timer = v6184;v5139;
    }) : ({
      int * v5155 = v5126->mem;
      int v6186 = (int)((unsigned int)(v5130 + 80) >> 2);
      int v5156 = v5155[v6186];
      int * v5157 = v5126->mem;
      int * v5158 = v5126->cache_keys;
      int v5159 = v5158[1];
      int * v5160 = v5126->cache_vals;
      int v5161 = v5160[1];
      v5157[v5159] = v5161;
      int * v5163 = v5126->cache_keys;
      int * v5164 = v5126->cache_keys;
      int v5165 = v5164[0];
      v5163[1] = v5165;
      int * v5167 = v5126->cache_vals;
      int * v5168 = v5126->cache_vals;
      int v5169 = v5168[0];
      v5167[1] = v5169;
      int * v5171 = v5126->cache_keys;
      v5171[0] = v6186;
      int * v5173 = v5126->cache_vals;
      v5173[0] = v5156;
      int v5175 = v5126->timer;
      int v6201 = v5175 + 100;
      v5126->timer = v6201;v5156;
    }));
    v5178;
  }));
  int * v5181 = v5126->regs;
  v5181[18] = v5180;
  struct StateT * v6160 = v5183(v5126);
  return v6160;
}

struct StateT * v4573(struct StateT * v4574) {
  int v4575 = v4574->timer;
  int v6623 = v4575 + 1;
  v4574->timer = v6623;int * v4577 = v4574->regs;
  int v4578 = v4577[10];
  int * v4579 = v4574->regs;
  int v4580 = v4579[13];
  int * v4581 = v4574->cache_keys;
  int v4582 = v4581[0];
  bool v6630 = v4582 == ((int)((unsigned int)(v4578 + 36) >> 2));
  int v4626 = (v6630 ? ({
    int * v4583 = v4574->cache_vals;
    v4583[0] = v4580;
    v4580;
  }) : ({
    int * v4586 = v4574->cache_keys;
    int v4587 = v4586[1];
    bool v6635 = v4587 == ((int)((unsigned int)(v4578 + 36) >> 2));
    int v4624 = (v6635 ? ({
      int * v4588 = v4574->cache_keys;
      int * v4589 = v4574->cache_keys;
      int v4590 = v4589[0];
      v4588[1] = v4590;
      int * v4592 = v4574->cache_vals;
      int * v4593 = v4574->cache_vals;
      int v4594 = v4593[0];
      v4592[1] = v4594;
      int * v4596 = v4574->cache_keys;
      int v6643 = (int)((unsigned int)(v4578 + 36) >> 2);
      v4596[0] = v6643;
      int * v4598 = v4574->cache_vals;
      v4598[0] = v4580;
      int v4600 = v4574->timer;
      int v6646 = v4600 + 1;
      v4574->timer = v6646;v4580;
    }) : ({
      int * v4603 = v4574->mem;
      int * v4604 = v4574->cache_keys;
      int v4605 = v4604[1];
      int * v4606 = v4574->cache_vals;
      int v4607 = v4606[1];
      v4603[v4605] = v4607;
      int * v4609 = v4574->cache_keys;
      int * v4610 = v4574->cache_keys;
      int v4611 = v4610[0];
      v4609[1] = v4611;
      int * v4613 = v4574->cache_vals;
      int * v4614 = v4574->cache_vals;
      int v4615 = v4614[0];
      v4613[1] = v4615;
      int * v4617 = v4574->cache_keys;
      int v6659 = (int)((unsigned int)(v4578 + 36) >> 2);
      v4617[0] = v6659;
      int * v4619 = v4574->cache_vals;
      v4619[0] = v4580;
      int v4621 = v4574->timer;
      int v6662 = v4621 + 100;
      v4574->timer = v6662;v4580;
    }));
    v4624;
  }));
  struct StateT * v6621 = v4627(v4574);
  return v6621;
}

struct StateT * v657(struct StateT * v658) {
  int v659 = v658->timer;
  int v13020 = v659 + 1;
  v658->timer = v13020;int * v661 = v658->regs;
  int v662 = v661[2];
  int * v663 = v658->regs;
  int v664 = v663[27];
  int * v665 = v658->cache_keys;
  int v666 = v665[0];
  bool v13027 = v666 == ((int)((unsigned int)(v662 + 44) >> 2));
  int v710 = (v13027 ? ({
    int * v667 = v658->cache_vals;
    v667[0] = v664;
    v664;
  }) : ({
    int * v670 = v658->cache_keys;
    int v671 = v670[1];
    bool v13032 = v671 == ((int)((unsigned int)(v662 + 44) >> 2));
    int v708 = (v13032 ? ({
      int * v672 = v658->cache_keys;
      int * v673 = v658->cache_keys;
      int v674 = v673[0];
      v672[1] = v674;
      int * v676 = v658->cache_vals;
      int * v677 = v658->cache_vals;
      int v678 = v677[0];
      v676[1] = v678;
      int * v680 = v658->cache_keys;
      int v13040 = (int)((unsigned int)(v662 + 44) >> 2);
      v680[0] = v13040;
      int * v682 = v658->cache_vals;
      v682[0] = v664;
      int v684 = v658->timer;
      int v13043 = v684 + 1;
      v658->timer = v13043;v664;
    }) : ({
      int * v687 = v658->mem;
      int * v688 = v658->cache_keys;
      int v689 = v688[1];
      int * v690 = v658->cache_vals;
      int v691 = v690[1];
      v687[v689] = v691;
      int * v693 = v658->cache_keys;
      int * v694 = v658->cache_keys;
      int v695 = v694[0];
      v693[1] = v695;
      int * v697 = v658->cache_vals;
      int * v698 = v658->cache_vals;
      int v699 = v698[0];
      v697[1] = v699;
      int * v701 = v658->cache_keys;
      int v13056 = (int)((unsigned int)(v662 + 44) >> 2);
      v701[0] = v13056;
      int * v703 = v658->cache_vals;
      v703[0] = v664;
      int v705 = v658->timer;
      int v13059 = v705 + 100;
      v658->timer = v13059;v664;
    }));
    v708;
  }));
  struct StateT * v13018 = v711(v658);
  return v13018;
}

struct StateT * v5473(struct StateT * v5474) {
  int v5475 = v5474->timer;
  int v5874 = v5475 + 1;
  v5474->timer = v5874;int * v5477 = v5474->regs;
  int v5478 = v5477[2];
  int * v5479 = v5474->cache_keys;
  int v5480 = v5479[0];
  bool v5879 = v5480 == ((int)((unsigned int)(v5478 + 56) >> 2));
  int v5528 = (v5879 ? ({
    int * v5481 = v5474->cache_vals;
    int v5482 = v5481[0];
    v5482;
  }) : ({
    int * v5484 = v5474->cache_keys;
    int v5485 = v5484[1];
    bool v5884 = v5485 == ((int)((unsigned int)(v5478 + 56) >> 2));
    int v5526 = (v5884 ? ({
      int * v5486 = v5474->cache_vals;
      int v5487 = v5486[1];
      int * v5488 = v5474->cache_keys;
      int * v5489 = v5474->cache_keys;
      int v5490 = v5489[0];
      v5488[1] = v5490;
      int * v5492 = v5474->cache_vals;
      int * v5493 = v5474->cache_vals;
      int v5494 = v5493[0];
      v5492[1] = v5494;
      int * v5496 = v5474->cache_keys;
      int v5893 = (int)((unsigned int)(v5478 + 56) >> 2);
      v5496[0] = v5893;
      int * v5498 = v5474->cache_vals;
      v5498[0] = v5487;
      int v5500 = v5474->timer;
      int v5896 = v5500 + 1;
      v5474->timer = v5896;v5487;
    }) : ({
      int * v5503 = v5474->mem;
      int v5898 = (int)((unsigned int)(v5478 + 56) >> 2);
      int v5504 = v5503[v5898];
      int * v5505 = v5474->mem;
      int * v5506 = v5474->cache_keys;
      int v5507 = v5506[1];
      int * v5508 = v5474->cache_vals;
      int v5509 = v5508[1];
      v5505[v5507] = v5509;
      int * v5511 = v5474->cache_keys;
      int * v5512 = v5474->cache_keys;
      int v5513 = v5512[0];
      v5511[1] = v5513;
      int * v5515 = v5474->cache_vals;
      int * v5516 = v5474->cache_vals;
      int v5517 = v5516[0];
      v5515[1] = v5517;
      int * v5519 = v5474->cache_keys;
      v5519[0] = v5898;
      int * v5521 = v5474->cache_vals;
      v5521[0] = v5504;
      int v5523 = v5474->timer;
      int v5913 = v5523 + 100;
      v5474->timer = v5913;v5504;
    }));
    v5526;
  }));
  int * v5529 = v5474->regs;
  v5529[24] = v5528;
  struct StateT * v5872 = v5531(v5474);
  return v5872;
}

struct StateT * v8859(struct StateT * v8860) {
  int v8861 = v8860->timer;
  int v9685 = v8861 + 1;
  v8860->timer = v9685;int * v8863 = v8860->regs;
  int v8864 = v8863[27];
  int * v8865 = v8860->regs;
  int v8866 = v8865[23];
  int * v8867 = v8860->regs;
  int v9692 = v8864 + v8866;
  v8867[11] = v9692;
  struct StateT * v9683 = v8869(v8860);
  return v9683;
}

struct StateT * v8317(struct StateT * v8318) {
  int v8319 = v8318->timer;
  int v10314 = v8319 + 1;
  v8318->timer = v10314;int * v8321 = v8318->regs;
  int v8322 = v8321[23];
  int * v8323 = v8318->regs;
  int v8324 = v8323[24];
  int * v8325 = v8318->regs;
  int v10321 = v8322 + v8324;
  v8325[16] = v10321;
  struct StateT * v10312 = v8327(v8318);
  return v10312;
}

struct StateT * v1907(struct StateT * v1908) {
  int v1909 = v1908->timer;
  int v11988 = v1909 + 1;
  v1908->timer = v11988;int * v1911 = v1908->regs;
  int v1912 = v1911[6];
  int * v1913 = v1908->regs;
  v1913[12] = v1912;
  struct StateT * v11986 = v1915(v1908);
  return v11986;
}

struct StateT * v4357(struct StateT * v4358) {
  int v4359 = v4358->timer;
  int v6803 = v4359 + 1;
  v4358->timer = v6803;int * v4361 = v4358->regs;
  int v4362 = v4361[10];
  int * v4363 = v4358->regs;
  int v4364 = v4363[11];
  int * v4365 = v4358->cache_keys;
  int v4366 = v4365[0];
  bool v6810 = v4366 == ((int)((unsigned int)(v4362 + 20) >> 2));
  int v4410 = (v6810 ? ({
    int * v4367 = v4358->cache_vals;
    v4367[0] = v4364;
    v4364;
  }) : ({
    int * v4370 = v4358->cache_keys;
    int v4371 = v4370[1];
    bool v6815 = v4371 == ((int)((unsigned int)(v4362 + 20) >> 2));
    int v4408 = (v6815 ? ({
      int * v4372 = v4358->cache_keys;
      int * v4373 = v4358->cache_keys;
      int v4374 = v4373[0];
      v4372[1] = v4374;
      int * v4376 = v4358->cache_vals;
      int * v4377 = v4358->cache_vals;
      int v4378 = v4377[0];
      v4376[1] = v4378;
      int * v4380 = v4358->cache_keys;
      int v6823 = (int)((unsigned int)(v4362 + 20) >> 2);
      v4380[0] = v6823;
      int * v4382 = v4358->cache_vals;
      v4382[0] = v4364;
      int v4384 = v4358->timer;
      int v6826 = v4384 + 1;
      v4358->timer = v6826;v4364;
    }) : ({
      int * v4387 = v4358->mem;
      int * v4388 = v4358->cache_keys;
      int v4389 = v4388[1];
      int * v4390 = v4358->cache_vals;
      int v4391 = v4390[1];
      v4387[v4389] = v4391;
      int * v4393 = v4358->cache_keys;
      int * v4394 = v4358->cache_keys;
      int v4395 = v4394[0];
      v4393[1] = v4395;
      int * v4397 = v4358->cache_vals;
      int * v4398 = v4358->cache_vals;
      int v4399 = v4398[0];
      v4397[1] = v4399;
      int * v4401 = v4358->cache_keys;
      int v6839 = (int)((unsigned int)(v4362 + 20) >> 2);
      v4401[0] = v6839;
      int * v4403 = v4358->cache_vals;
      v4403[0] = v4364;
      int v4405 = v4358->timer;
      int v6842 = v4405 + 100;
      v4358->timer = v6842;v4364;
    }));
    v4408;
  }));
  struct StateT * v6801 = v4411(v4358);
  return v6801;
}

struct StateT * v1413(struct StateT * v1414) {
  int v1415 = v1414->timer;
  int v12428 = v1415 + 1;
  v1414->timer = v12428;int * v1417 = v1414->regs;
  v1417[12] = 1634762752;
  struct StateT * v12426 = v1419(v1414);
  return v12426;
}

struct StateT * v2001(struct StateT * v2002) {
  int * v2003 = v2002->saved_regs;
  int * v2004 = v2002->regs;
  int v2005 = v2004[15];
  v2003[15] = v2005;
  int v2007 = v2002->timer;
  int v10988 = v2007 + 1;
  v2002->timer = v10988;int * v2009 = v2002->regs;
  int v2010 = v2009[21];
  int * v2011 = v2002->regs;
  int v2012 = v2011[16];
  int * v2013 = v2002->regs;
  int v10994 = v2010 + v2012;
  v2013[15] = v10994;
  int * v2015 = v2002->saved_regs;
  int * v2016 = v2002->regs;
  int v2017 = v2016[20];
  v2015[20] = v2017;
  int v2019 = v2002->timer;
  int v10999 = v2019 + 1;
  v2002->timer = v10999;int * v2021 = v2002->regs;
  int v2022 = v2021[11];
  int * v2023 = v2002->regs;
  int v2024 = v2023[23];
  int * v2025 = v2002->regs;
  int v11005 = v2022 + v2024;
  v2025[20] = v11005;
  int * v2027 = v2002->saved_regs;
  int * v2028 = v2002->regs;
  int v2029 = v2028[18];
  v2027[18] = v2029;
  int v2031 = v2002->timer;
  int v11010 = v2031 + 1;
  v2002->timer = v11010;int * v2033 = v2002->regs;
  int v2034 = v2033[19];
  int * v2035 = v2002->regs;
  int v2036 = v2035[5];
  int * v2037 = v2002->regs;
  int v11016 = v2034 + v2036;
  v2037[18] = v11016;
  int * v2039 = v2002->saved_regs;
  int * v2040 = v2002->regs;
  int v2041 = v2040[8];
  v2039[8] = v2041;
  int v2043 = v2002->timer;
  int v11021 = v2043 + 1;
  v2002->timer = v11021;int * v2045 = v2002->regs;
  int v2046 = v2045[22];
  int * v2047 = v2002->regs;
  int v2048 = v2047[17];
  int * v2049 = v2002->regs;
  int v11027 = v2046 + v2048;
  v2049[8] = v11027;
  int * v2051 = v2002->saved_regs;
  int * v2052 = v2002->regs;
  int v2053 = v2052[9];
  v2051[9] = v2053;
  int v2055 = v2002->timer;
  int v11032 = v2055 + 1;
  v2002->timer = v11032;int * v2057 = v2002->regs;
  int v2058 = v2057[15];
  int * v2059 = v2002->regs;
  int v11035 = (int)((unsigned int)v2058 >> 25);
  v2059[9] = v11035;
  int v2061 = v2002->timer;
  int v11036 = v2061 + 1;
  v2002->timer = v11036;int * v2063 = v2002->regs;
  int v2064 = v2063[15];
  int * v2065 = v2002->regs;
  int v11039 = v2064 << 7;
  v2065[15] = v11039;
  int v2067 = v2002->timer;
  int v11040 = v2067 + 1;
  v2002->timer = v11040;int * v2069 = v2002->regs;
  int v2070 = v2069[15];
  int * v2071 = v2002->regs;
  int v2072 = v2071[9];
  int * v2073 = v2002->regs;
  int v11044 = v2070 | v2072;
  v2073[15] = v11044;
  int v2075 = v2002->timer;
  int v11045 = v2075 + 1;
  v2002->timer = v11045;int * v2077 = v2002->regs;
  int v2078 = v2077[20];
  int * v2079 = v2002->regs;
  int v11048 = (int)((unsigned int)v2078 >> 25);
  v2079[9] = v11048;
  int v2081 = v2002->timer;
  int v11049 = v2081 + 1;
  v2002->timer = v11049;int * v2083 = v2002->regs;
  int v2084 = v2083[20];
  int * v2085 = v2002->regs;
  int v11052 = v2084 << 7;
  v2085[20] = v11052;
  int v2087 = v2002->timer;
  int v11053 = v2087 + 1;
  v2002->timer = v11053;int * v2089 = v2002->regs;
  int v2090 = v2089[20];
  int * v2091 = v2002->regs;
  int v2092 = v2091[9];
  int * v2093 = v2002->regs;
  int v11057 = v2090 | v2092;
  v2093[9] = v11057;
  int v2095 = v2002->timer;
  int v11058 = v2095 + 1;
  v2002->timer = v11058;int * v2097 = v2002->regs;
  int v2098 = v2097[18];
  int * v2099 = v2002->regs;
  int v11061 = (int)((unsigned int)v2098 >> 25);
  v2099[20] = v11061;
  int v2101 = v2002->timer;
  int v11062 = v2101 + 1;
  v2002->timer = v11062;int * v2103 = v2002->regs;
  int v2104 = v2103[18];
  int * v2105 = v2002->regs;
  int v11065 = v2104 << 7;
  v2105[18] = v11065;
  int v2107 = v2002->timer;
  int v11066 = v2107 + 1;
  v2002->timer = v11066;int * v2109 = v2002->regs;
  int v2110 = v2109[18];
  int * v2111 = v2002->regs;
  int v2112 = v2111[20];
  int * v2113 = v2002->regs;
  int v11070 = v2110 | v2112;
  v2113[18] = v11070;
  int v2115 = v2002->timer;
  int v11071 = v2115 + 1;
  v2002->timer = v11071;int * v2117 = v2002->regs;
  int v2118 = v2117[8];
  int * v2119 = v2002->regs;
  int v11074 = (int)((unsigned int)v2118 >> 25);
  v2119[20] = v11074;
  int v2121 = v2002->timer;
  int v11075 = v2121 + 1;
  v2002->timer = v11075;int * v2123 = v2002->regs;
  int v2124 = v2123[8];
  int * v2125 = v2002->regs;
  int v11078 = v2124 << 7;
  v2125[8] = v11078;
  int v2127 = v2002->timer;
  int v11079 = v2127 + 1;
  v2002->timer = v11079;int * v2129 = v2002->regs;
  int v2130 = v2129[8];
  int * v2131 = v2002->regs;
  int v2132 = v2131[20];
  int * v2133 = v2002->regs;
  int v11083 = v2130 | v2132;
  v2133[8] = v11083;
  int * v2135 = v2002->saved_regs;
  int * v2136 = v2002->regs;
  int v2137 = v2136[12];
  v2135[12] = v2137;
  int v2139 = v2002->timer;
  int v11088 = v2139 + 1;
  v2002->timer = v11088;int * v2141 = v2002->regs;
  int v2142 = v2141[12];
  int * v2143 = v2002->regs;
  int v2144 = v2143[15];
  int * v2145 = v2002->regs;
  int v11092 = v2142 ^ v2144;
  v2145[12] = v11092;
  int * v2147 = v2002->saved_regs;
  int * v2148 = v2002->regs;
  int v2149 = v2148[13];
  v2147[13] = v2149;
  int v2151 = v2002->timer;
  int v11097 = v2151 + 1;
  v2002->timer = v11097;int * v2153 = v2002->regs;
  int v2154 = v2153[13];
  int * v2155 = v2002->regs;
  int v2156 = v2155[9];
  int * v2157 = v2002->regs;
  int v11101 = v2154 ^ v2156;
  v2157[13] = v11101;
  int * v2159 = v2002->saved_regs;
  int * v2160 = v2002->regs;
  int v2161 = v2160[1];
  v2159[1] = v2161;
  int v2163 = v2002->timer;
  int v11106 = v2163 + 1;
  v2002->timer = v11106;int * v2165 = v2002->regs;
  int v2166 = v2165[1];
  int * v2167 = v2002->regs;
  int v2168 = v2167[18];
  int * v2169 = v2002->regs;
  int v11110 = v2166 ^ v2168;
  v2169[1] = v11110;
  int * v2171 = v2002->saved_regs;
  int * v2172 = v2002->regs;
  int v2173 = v2172[14];
  v2171[14] = v2173;
  int v2175 = v2002->timer;
  int v11115 = v2175 + 1;
  v2002->timer = v11115;int * v2177 = v2002->regs;
  int v2178 = v2177[14];
  int * v2179 = v2002->regs;
  int v2180 = v2179[8];
  int * v2181 = v2002->regs;
  int v11119 = v2178 ^ v2180;
  v2181[14] = v11119;
  int v2183 = v2002->timer;
  int v11120 = v2183 + 1;
  v2002->timer = v11120;int * v2185 = v2002->regs;
  int v2186 = v2185[12];
  int * v2187 = v2002->regs;
  int v2188 = v2187[21];
  int * v2189 = v2002->regs;
  int v11124 = v2186 + v2188;
  v2189[15] = v11124;
  int v2191 = v2002->timer;
  int v11125 = v2191 + 1;
  v2002->timer = v11125;int * v2193 = v2002->regs;
  int v2194 = v2193[13];
  int * v2195 = v2002->regs;
  int v2196 = v2195[11];
  int * v2197 = v2002->regs;
  int v11129 = v2194 + v2196;
  v2197[8] = v11129;
  int v2199 = v2002->timer;
  int v11130 = v2199 + 1;
  v2002->timer = v11130;int * v2201 = v2002->regs;
  int v2202 = v2201[1];
  int * v2203 = v2002->regs;
  int v2204 = v2203[19];
  int * v2205 = v2002->regs;
  int v11134 = v2202 + v2204;
  v2205[9] = v11134;
  int v2207 = v2002->timer;
  int v11135 = v2207 + 1;
  v2002->timer = v11135;int * v2209 = v2002->regs;
  int v2210 = v2209[14];
  int * v2211 = v2002->regs;
  int v2212 = v2211[22];
  int * v2213 = v2002->regs;
  int v11139 = v2210 + v2212;
  v2213[18] = v11139;
  int v2215 = v2002->timer;
  int v11140 = v2215 + 1;
  v2002->timer = v11140;int * v2217 = v2002->regs;
  int v2218 = v2217[15];
  int * v2219 = v2002->regs;
  int v11143 = (int)((unsigned int)v2218 >> 23);
  v2219[20] = v11143;
  int v2221 = v2002->timer;
  int v11144 = v2221 + 1;
  v2002->timer = v11144;int * v2223 = v2002->regs;
  int v2224 = v2223[15];
  int * v2225 = v2002->regs;
  int v11147 = v2224 << 9;
  v2225[15] = v11147;
  int v2227 = v2002->timer;
  int v11148 = v2227 + 1;
  v2002->timer = v11148;int * v2229 = v2002->regs;
  int v2230 = v2229[15];
  int * v2231 = v2002->regs;
  int v2232 = v2231[20];
  int * v2233 = v2002->regs;
  int v11152 = v2230 | v2232;
  v2233[15] = v11152;
  int v2235 = v2002->timer;
  int v11153 = v2235 + 1;
  v2002->timer = v11153;int * v2237 = v2002->regs;
  int v2238 = v2237[8];
  int * v2239 = v2002->regs;
  int v11156 = (int)((unsigned int)v2238 >> 23);
  v2239[20] = v11156;
  int v2241 = v2002->timer;
  int v11157 = v2241 + 1;
  v2002->timer = v11157;int * v2243 = v2002->regs;
  int v2244 = v2243[8];
  int * v2245 = v2002->regs;
  int v11160 = v2244 << 9;
  v2245[8] = v11160;
  int v2247 = v2002->timer;
  int v11161 = v2247 + 1;
  v2002->timer = v11161;int * v2249 = v2002->regs;
  int v2250 = v2249[8];
  int * v2251 = v2002->regs;
  int v2252 = v2251[20];
  int * v2253 = v2002->regs;
  int v11165 = v2250 | v2252;
  v2253[8] = v11165;
  int v2255 = v2002->timer;
  int v11166 = v2255 + 1;
  v2002->timer = v11166;int * v2257 = v2002->regs;
  int v2258 = v2257[9];
  int * v2259 = v2002->regs;
  int v11169 = (int)((unsigned int)v2258 >> 23);
  v2259[20] = v11169;
  int v2261 = v2002->timer;
  int v11170 = v2261 + 1;
  v2002->timer = v11170;int * v2263 = v2002->regs;
  int v2264 = v2263[9];
  int * v2265 = v2002->regs;
  int v11173 = v2264 << 9;
  v2265[9] = v11173;
  int v2267 = v2002->timer;
  int v11174 = v2267 + 1;
  v2002->timer = v11174;int * v2269 = v2002->regs;
  int v2270 = v2269[9];
  int * v2271 = v2002->regs;
  int v2272 = v2271[20];
  int * v2273 = v2002->regs;
  int v11178 = v2270 | v2272;
  v2273[9] = v11178;
  int v2275 = v2002->timer;
  int v11179 = v2275 + 1;
  v2002->timer = v11179;int * v2277 = v2002->regs;
  int v2278 = v2277[18];
  int * v2279 = v2002->regs;
  int v11182 = (int)((unsigned int)v2278 >> 23);
  v2279[20] = v11182;
  int v2281 = v2002->timer;
  int v11183 = v2281 + 1;
  v2002->timer = v11183;int * v2283 = v2002->regs;
  int v2284 = v2283[18];
  int * v2285 = v2002->regs;
  int v11186 = v2284 << 9;
  v2285[18] = v11186;
  int v2287 = v2002->timer;
  int v11187 = v2287 + 1;
  v2002->timer = v11187;int * v2289 = v2002->regs;
  int v2290 = v2289[18];
  int * v2291 = v2002->regs;
  int v2292 = v2291[20];
  int * v2293 = v2002->regs;
  int v11191 = v2290 | v2292;
  v2293[18] = v11191;
  int * v2295 = v2002->saved_regs;
  int * v2296 = v2002->regs;
  int v2297 = v2296[26];
  v2295[26] = v2297;
  int v2299 = v2002->timer;
  int v11196 = v2299 + 1;
  v2002->timer = v11196;int * v2301 = v2002->regs;
  int v2302 = v2301[26];
  int * v2303 = v2002->regs;
  int v2304 = v2303[15];
  int * v2305 = v2002->regs;
  int v11200 = v2302 ^ v2304;
  v2305[26] = v11200;
  int * v2307 = v2002->saved_regs;
  int * v2308 = v2002->regs;
  int v2309 = v2308[24];
  v2307[24] = v2309;
  int v2311 = v2002->timer;
  int v11205 = v2311 + 1;
  v2002->timer = v11205;int * v2313 = v2002->regs;
  int v2314 = v2313[24];
  int * v2315 = v2002->regs;
  int v2316 = v2315[8];
  int * v2317 = v2002->regs;
  int v11209 = v2314 ^ v2316;
  v2317[24] = v11209;
  int * v2319 = v2002->saved_regs;
  int * v2320 = v2002->regs;
  int v2321 = v2320[27];
  v2319[27] = v2321;
  int v2323 = v2002->timer;
  int v11214 = v2323 + 1;
  v2002->timer = v11214;int * v2325 = v2002->regs;
  int v2326 = v2325[27];
  int * v2327 = v2002->regs;
  int v2328 = v2327[9];
  int * v2329 = v2002->regs;
  int v11218 = v2326 ^ v2328;
  v2329[27] = v11218;
  int * v2331 = v2002->saved_regs;
  int * v2332 = v2002->regs;
  int v2333 = v2332[25];
  v2331[25] = v2333;
  int v2335 = v2002->timer;
  int v11223 = v2335 + 1;
  v2002->timer = v11223;int * v2337 = v2002->regs;
  int v2338 = v2337[25];
  int * v2339 = v2002->regs;
  int v2340 = v2339[18];
  int * v2341 = v2002->regs;
  int v11227 = v2338 ^ v2340;
  v2341[25] = v11227;
  int v2343 = v2002->timer;
  int v11228 = v2343 + 1;
  v2002->timer = v11228;int * v2345 = v2002->regs;
  int v2346 = v2345[26];
  int * v2347 = v2002->regs;
  int v2348 = v2347[12];
  int * v2349 = v2002->regs;
  int v11232 = v2346 + v2348;
  v2349[15] = v11232;
  int v2351 = v2002->timer;
  int v11233 = v2351 + 1;
  v2002->timer = v11233;int * v2353 = v2002->regs;
  int v2354 = v2353[24];
  int * v2355 = v2002->regs;
  int v2356 = v2355[13];
  int * v2357 = v2002->regs;
  int v11237 = v2354 + v2356;
  v2357[8] = v11237;
  int v2359 = v2002->timer;
  int v11238 = v2359 + 1;
  v2002->timer = v11238;int * v2361 = v2002->regs;
  int v2362 = v2361[27];
  int * v2363 = v2002->regs;
  int v2364 = v2363[1];
  int * v2365 = v2002->regs;
  int v11242 = v2362 + v2364;
  v2365[9] = v11242;
  int v2367 = v2002->timer;
  int v11243 = v2367 + 1;
  v2002->timer = v11243;int * v2369 = v2002->regs;
  int v2370 = v2369[25];
  int * v2371 = v2002->regs;
  int v2372 = v2371[14];
  int * v2373 = v2002->regs;
  int v11247 = v2370 + v2372;
  v2373[18] = v11247;
  int v2375 = v2002->timer;
  int v11248 = v2375 + 1;
  v2002->timer = v11248;int * v2377 = v2002->regs;
  int v2378 = v2377[15];
  int * v2379 = v2002->regs;
  int v11251 = (int)((unsigned int)v2378 >> 19);
  v2379[20] = v11251;
  int v2381 = v2002->timer;
  int v11252 = v2381 + 1;
  v2002->timer = v11252;int * v2383 = v2002->regs;
  int v2384 = v2383[15];
  int * v2385 = v2002->regs;
  int v11255 = v2384 << 13;
  v2385[15] = v11255;
  int v2387 = v2002->timer;
  int v11256 = v2387 + 1;
  v2002->timer = v11256;int * v2389 = v2002->regs;
  int v2390 = v2389[15];
  int * v2391 = v2002->regs;
  int v2392 = v2391[20];
  int * v2393 = v2002->regs;
  int v11260 = v2390 | v2392;
  v2393[15] = v11260;
  int v2395 = v2002->timer;
  int v11261 = v2395 + 1;
  v2002->timer = v11261;int * v2397 = v2002->regs;
  int v2398 = v2397[8];
  int * v2399 = v2002->regs;
  int v11264 = (int)((unsigned int)v2398 >> 19);
  v2399[20] = v11264;
  int v2401 = v2002->timer;
  int v11265 = v2401 + 1;
  v2002->timer = v11265;int * v2403 = v2002->regs;
  int v2404 = v2403[8];
  int * v2405 = v2002->regs;
  int v11268 = v2404 << 13;
  v2405[8] = v11268;
  int v2407 = v2002->timer;
  int v11269 = v2407 + 1;
  v2002->timer = v11269;int * v2409 = v2002->regs;
  int v2410 = v2409[8];
  int * v2411 = v2002->regs;
  int v2412 = v2411[20];
  int * v2413 = v2002->regs;
  int v11273 = v2410 | v2412;
  v2413[8] = v11273;
  int v2415 = v2002->timer;
  int v11274 = v2415 + 1;
  v2002->timer = v11274;int * v2417 = v2002->regs;
  int v2418 = v2417[9];
  int * v2419 = v2002->regs;
  int v11277 = (int)((unsigned int)v2418 >> 19);
  v2419[20] = v11277;
  int v2421 = v2002->timer;
  int v11278 = v2421 + 1;
  v2002->timer = v11278;int * v2423 = v2002->regs;
  int v2424 = v2423[9];
  int * v2425 = v2002->regs;
  int v11281 = v2424 << 13;
  v2425[9] = v11281;
  int v2427 = v2002->timer;
  int v11282 = v2427 + 1;
  v2002->timer = v11282;int * v2429 = v2002->regs;
  int v2430 = v2429[9];
  int * v2431 = v2002->regs;
  int v2432 = v2431[20];
  int * v2433 = v2002->regs;
  int v11286 = v2430 | v2432;
  v2433[20] = v11286;
  int v2435 = v2002->timer;
  int v11287 = v2435 + 1;
  v2002->timer = v11287;int * v2437 = v2002->regs;
  int v2438 = v2437[18];
  int * v2439 = v2002->regs;
  int v11290 = (int)((unsigned int)v2438 >> 19);
  v2439[9] = v11290;
  int v2441 = v2002->timer;
  int v11291 = v2441 + 1;
  v2002->timer = v11291;int * v2443 = v2002->regs;
  int v2444 = v2443[18];
  int * v2445 = v2002->regs;
  int v11294 = v2444 << 13;
  v2445[18] = v11294;
  int * v2447 = v2002->saved_regs;
  int * v2448 = v2002->regs;
  int v2449 = v2448[6];
  v2447[6] = v2449;
  int v2451 = v2002->timer;
  int v11299 = v2451 + 1;
  v2002->timer = v11299;int * v2453 = v2002->regs;
  int v2454 = v2453[18];
  int * v2455 = v2002->regs;
  int v2456 = v2455[9];
  int * v2457 = v2002->regs;
  int v11303 = v2454 | v2456;
  v2457[6] = v11303;
  int v2459 = v2002->timer;
  int v11304 = v2459 + 1;
  v2002->timer = v11304;int * v2461 = v2002->regs;
  int v2462 = v2461[16];
  int * v2463 = v2002->regs;
  int v2464 = v2463[15];
  int * v2465 = v2002->regs;
  int v11308 = v2462 ^ v2464;
  v2465[9] = v11308;
  int * v2467 = v2002->saved_regs;
  int * v2468 = v2002->regs;
  int v2469 = v2468[23];
  v2467[23] = v2469;
  int v2471 = v2002->timer;
  int v11312 = v2471 + 1;
  v2002->timer = v11312;int * v2473 = v2002->regs;
  int v2474 = v2473[23];
  int * v2475 = v2002->regs;
  int v2476 = v2475[8];
  int * v2477 = v2002->regs;
  int v11316 = v2474 ^ v2476;
  v2477[23] = v11316;
  int v2479 = v2002->timer;
  int v11317 = v2479 + 1;
  v2002->timer = v11317;int * v2481 = v2002->regs;
  int v2482 = v2481[5];
  int * v2483 = v2002->regs;
  int v2484 = v2483[20];
  int * v2485 = v2002->regs;
  int v11321 = v2482 ^ v2484;
  v2485[18] = v11321;
  int v2487 = v2002->timer;
  int v11322 = v2487 + 1;
  v2002->timer = v11322;int * v2489 = v2002->regs;
  int v2490 = v2489[17];
  int * v2491 = v2002->regs;
  int v2492 = v2491[6];
  int * v2493 = v2002->regs;
  int v11326 = v2490 ^ v2492;
  v2493[8] = v11326;
  int v2495 = v2002->timer;
  int v11327 = v2495 + 1;
  v2002->timer = v11327;int * v2497 = v2002->regs;
  int v2498 = v2497[9];
  int * v2499 = v2002->regs;
  int v2500 = v2499[26];
  int * v2501 = v2002->regs;
  int v11331 = v2498 + v2500;
  v2501[15] = v11331;
  int * v2503 = v2002->saved_regs;
  int * v2504 = v2002->regs;
  int v2505 = v2504[16];
  v2503[16] = v2505;
  int v2507 = v2002->timer;
  int v11335 = v2507 + 1;
  v2002->timer = v11335;int * v2509 = v2002->regs;
  int v2510 = v2509[23];
  int * v2511 = v2002->regs;
  int v2512 = v2511[24];
  int * v2513 = v2002->regs;
  int v11339 = v2510 + v2512;
  v2513[16] = v11339;
  int * v2515 = v2002->saved_regs;
  int * v2516 = v2002->regs;
  int v2517 = v2516[17];
  v2515[17] = v2517;
  int v2519 = v2002->timer;
  int v11343 = v2519 + 1;
  v2002->timer = v11343;int * v2521 = v2002->regs;
  int v2522 = v2521[18];
  int * v2523 = v2002->regs;
  int v2524 = v2523[27];
  int * v2525 = v2002->regs;
  int v11347 = v2522 + v2524;
  v2525[17] = v11347;
  int * v2527 = v2002->saved_regs;
  int * v2528 = v2002->regs;
  int v2529 = v2528[5];
  v2527[5] = v2529;
  int v2531 = v2002->timer;
  int v11351 = v2531 + 1;
  v2002->timer = v11351;int * v2533 = v2002->regs;
  int v2534 = v2533[8];
  int * v2535 = v2002->regs;
  int v2536 = v2535[25];
  int * v2537 = v2002->regs;
  int v11355 = v2534 + v2536;
  v2537[5] = v11355;
  int v2539 = v2002->timer;
  int v11356 = v2539 + 1;
  v2002->timer = v11356;int * v2541 = v2002->regs;
  int v2542 = v2541[15];
  int * v2543 = v2002->regs;
  int v11359 = (int)((unsigned int)v2542 >> 14);
  v2543[6] = v11359;
  int v2545 = v2002->timer;
  int v11360 = v2545 + 1;
  v2002->timer = v11360;int * v2547 = v2002->regs;
  int v2548 = v2547[15];
  int * v2549 = v2002->regs;
  int v11363 = v2548 << 18;
  v2549[15] = v11363;
  int v2551 = v2002->timer;
  int v11364 = v2551 + 1;
  v2002->timer = v11364;int * v2553 = v2002->regs;
  int v2554 = v2553[15];
  int * v2555 = v2002->regs;
  int v2556 = v2555[6];
  int * v2557 = v2002->regs;
  int v11368 = v2554 | v2556;
  v2557[15] = v11368;
  int v2559 = v2002->timer;
  int v11369 = v2559 + 1;
  v2002->timer = v11369;int * v2561 = v2002->regs;
  int v2562 = v2561[16];
  int * v2563 = v2002->regs;
  int v11372 = (int)((unsigned int)v2562 >> 14);
  v2563[6] = v11372;
  int v2565 = v2002->timer;
  int v11373 = v2565 + 1;
  v2002->timer = v11373;int * v2567 = v2002->regs;
  int v2568 = v2567[16];
  int * v2569 = v2002->regs;
  int v11376 = v2568 << 18;
  v2569[16] = v11376;
  int v2571 = v2002->timer;
  int v11377 = v2571 + 1;
  v2002->timer = v11377;int * v2573 = v2002->regs;
  int v2574 = v2573[16];
  int * v2575 = v2002->regs;
  int v2576 = v2575[6];
  int * v2577 = v2002->regs;
  int v11381 = v2574 | v2576;
  v2577[16] = v11381;
  int v2579 = v2002->timer;
  int v11382 = v2579 + 1;
  v2002->timer = v11382;int * v2581 = v2002->regs;
  int v2582 = v2581[17];
  int * v2583 = v2002->regs;
  int v11385 = (int)((unsigned int)v2582 >> 14);
  v2583[6] = v11385;
  int v2585 = v2002->timer;
  int v11386 = v2585 + 1;
  v2002->timer = v11386;int * v2587 = v2002->regs;
  int v2588 = v2587[17];
  int * v2589 = v2002->regs;
  int v11389 = v2588 << 18;
  v2589[17] = v11389;
  int v2591 = v2002->timer;
  int v11390 = v2591 + 1;
  v2002->timer = v11390;int * v2593 = v2002->regs;
  int v2594 = v2593[17];
  int * v2595 = v2002->regs;
  int v2596 = v2595[6];
  int * v2597 = v2002->regs;
  int v11394 = v2594 | v2596;
  v2597[17] = v11394;
  int v2599 = v2002->timer;
  int v11395 = v2599 + 1;
  v2002->timer = v11395;int * v2601 = v2002->regs;
  int v2602 = v2601[5];
  int * v2603 = v2002->regs;
  int v11398 = (int)((unsigned int)v2602 >> 14);
  v2603[6] = v11398;
  int v2605 = v2002->timer;
  int v11399 = v2605 + 1;
  v2002->timer = v11399;int * v2607 = v2002->regs;
  int v2608 = v2607[5];
  int * v2609 = v2002->regs;
  int v11402 = v2608 << 18;
  v2609[5] = v11402;
  int v2611 = v2002->timer;
  int v11403 = v2611 + 1;
  v2002->timer = v11403;int * v2613 = v2002->regs;
  int v2614 = v2613[5];
  int * v2615 = v2002->regs;
  int v2616 = v2615[6];
  int * v2617 = v2002->regs;
  int v11407 = v2614 | v2616;
  v2617[5] = v11407;
  int * v2619 = v2002->saved_regs;
  int * v2620 = v2002->regs;
  int v2621 = v2620[21];
  v2619[21] = v2621;
  int v2623 = v2002->timer;
  int v11411 = v2623 + 1;
  v2002->timer = v11411;int * v2625 = v2002->regs;
  int v2626 = v2625[21];
  int * v2627 = v2002->regs;
  int v2628 = v2627[15];
  int * v2629 = v2002->regs;
  int v11415 = v2626 ^ v2628;
  v2629[21] = v11415;
  int v2631 = v2002->timer;
  int v11416 = v2631 + 1;
  v2002->timer = v11416;int * v2633 = v2002->regs;
  int v2634 = v2633[11];
  int * v2635 = v2002->regs;
  int v2636 = v2635[16];
  int * v2637 = v2002->regs;
  int v11420 = v2634 ^ v2636;
  v2637[20] = v11420;
  int * v2639 = v2002->saved_regs;
  int * v2640 = v2002->regs;
  int v2641 = v2640[19];
  v2639[19] = v2641;
  int v2643 = v2002->timer;
  int v11424 = v2643 + 1;
  v2002->timer = v11424;int * v2645 = v2002->regs;
  int v2646 = v2645[19];
  int * v2647 = v2002->regs;
  int v2648 = v2647[17];
  int * v2649 = v2002->regs;
  int v11428 = v2646 ^ v2648;
  v2649[19] = v11428;
  int * v2651 = v2002->saved_regs;
  int * v2652 = v2002->regs;
  int v2653 = v2652[22];
  v2651[22] = v2653;
  int v2655 = v2002->timer;
  int v11432 = v2655 + 1;
  v2002->timer = v11432;int * v2657 = v2002->regs;
  int v2658 = v2657[22];
  int * v2659 = v2002->regs;
  int v2660 = v2659[5];
  int * v2661 = v2002->regs;
  int v11436 = v2658 ^ v2660;
  v2661[22] = v11436;
  int v2663 = v2002->timer;
  int v11437 = v2663 + 1;
  v2002->timer = v11437;int * v2665 = v2002->regs;
  int v2666 = v2665[21];
  int * v2667 = v2002->regs;
  int v2668 = v2667[14];
  int * v2669 = v2002->regs;
  int v11441 = v2666 + v2668;
  v2669[15] = v11441;
  int * v2671 = v2002->saved_regs;
  int * v2672 = v2002->regs;
  int v2673 = v2672[11];
  v2671[11] = v2673;
  int v2675 = v2002->timer;
  int v11445 = v2675 + 1;
  v2002->timer = v11445;int * v2677 = v2002->regs;
  int v2678 = v2677[20];
  int * v2679 = v2002->regs;
  int v2680 = v2679[12];
  int * v2681 = v2002->regs;
  int v11449 = v2678 + v2680;
  v2681[11] = v11449;
  int v2683 = v2002->timer;
  int v11450 = v2683 + 1;
  v2002->timer = v11450;int * v2685 = v2002->regs;
  int v2686 = v2685[19];
  int * v2687 = v2002->regs;
  int v2688 = v2687[13];
  int * v2689 = v2002->regs;
  int v11454 = v2686 + v2688;
  v2689[16] = v11454;
  int v2691 = v2002->timer;
  int v11455 = v2691 + 1;
  v2002->timer = v11455;int * v2693 = v2002->regs;
  int v2694 = v2693[22];
  int * v2695 = v2002->regs;
  int v2696 = v2695[1];
  int * v2697 = v2002->regs;
  int v11459 = v2694 + v2696;
  v2697[17] = v11459;
  int v2699 = v2002->timer;
  int v11460 = v2699 + 1;
  v2002->timer = v11460;int * v2701 = v2002->regs;
  int v2702 = v2701[15];
  int * v2703 = v2002->regs;
  int v11463 = (int)((unsigned int)v2702 >> 25);
  v2703[5] = v11463;
  int v2705 = v2002->timer;
  int v11464 = v2705 + 1;
  v2002->timer = v11464;int * v2707 = v2002->regs;
  int v2708 = v2707[15];
  int * v2709 = v2002->regs;
  int v11467 = v2708 << 7;
  v2709[15] = v11467;
  int v2711 = v2002->timer;
  int v11468 = v2711 + 1;
  v2002->timer = v11468;int * v2713 = v2002->regs;
  int v2714 = v2713[15];
  int * v2715 = v2002->regs;
  int v2716 = v2715[5];
  int * v2717 = v2002->regs;
  int v11472 = v2714 | v2716;
  v2717[15] = v11472;
  int v2719 = v2002->timer;
  int v11473 = v2719 + 1;
  v2002->timer = v11473;int * v2721 = v2002->regs;
  int v2722 = v2721[11];
  int * v2723 = v2002->regs;
  int v11476 = (int)((unsigned int)v2722 >> 25);
  v2723[5] = v11476;
  int v2725 = v2002->timer;
  int v11477 = v2725 + 1;
  v2002->timer = v11477;int * v2727 = v2002->regs;
  int v2728 = v2727[11];
  int * v2729 = v2002->regs;
  int v11480 = v2728 << 7;
  v2729[11] = v11480;
  int v2731 = v2002->timer;
  int v11481 = v2731 + 1;
  v2002->timer = v11481;int * v2733 = v2002->regs;
  int v2734 = v2733[11];
  int * v2735 = v2002->regs;
  int v2736 = v2735[5];
  int * v2737 = v2002->regs;
  int v11485 = v2734 | v2736;
  v2737[11] = v11485;
  int v2739 = v2002->timer;
  int v11486 = v2739 + 1;
  v2002->timer = v11486;int * v2741 = v2002->regs;
  int v2742 = v2741[16];
  int * v2743 = v2002->regs;
  int v11489 = (int)((unsigned int)v2742 >> 25);
  v2743[5] = v11489;
  int v2745 = v2002->timer;
  int v11490 = v2745 + 1;
  v2002->timer = v11490;int * v2747 = v2002->regs;
  int v2748 = v2747[16];
  int * v2749 = v2002->regs;
  int v11493 = v2748 << 7;
  v2749[16] = v11493;
  int v2751 = v2002->timer;
  int v11494 = v2751 + 1;
  v2002->timer = v11494;int * v2753 = v2002->regs;
  int v2754 = v2753[16];
  int * v2755 = v2002->regs;
  int v2756 = v2755[5];
  int * v2757 = v2002->regs;
  int v11498 = v2754 | v2756;
  v2757[16] = v11498;
  int v2759 = v2002->timer;
  int v11499 = v2759 + 1;
  v2002->timer = v11499;int * v2761 = v2002->regs;
  int v2762 = v2761[17];
  int * v2763 = v2002->regs;
  int v11502 = (int)((unsigned int)v2762 >> 25);
  v2763[5] = v11502;
  int v2765 = v2002->timer;
  int v11503 = v2765 + 1;
  v2002->timer = v11503;int * v2767 = v2002->regs;
  int v2768 = v2767[17];
  int * v2769 = v2002->regs;
  int v11506 = v2768 << 7;
  v2769[17] = v11506;
  int v2771 = v2002->timer;
  int v11507 = v2771 + 1;
  v2002->timer = v11507;int * v2773 = v2002->regs;
  int v2774 = v2773[17];
  int * v2775 = v2002->regs;
  int v2776 = v2775[5];
  int * v2777 = v2002->regs;
  int v11511 = v2774 | v2776;
  v2777[6] = v11511;
  int v2779 = v2002->timer;
  int v11512 = v2779 + 1;
  v2002->timer = v11512;int * v2781 = v2002->regs;
  int v2782 = v2781[23];
  int * v2783 = v2002->regs;
  int v2784 = v2783[15];
  int * v2785 = v2002->regs;
  int v11516 = v2782 ^ v2784;
  v2785[23] = v11516;
  int v2787 = v2002->timer;
  int v11517 = v2787 + 1;
  v2002->timer = v11517;int * v2789 = v2002->regs;
  int v2790 = v2789[18];
  int * v2791 = v2002->regs;
  int v2792 = v2791[11];
  int * v2793 = v2002->regs;
  int v11521 = v2790 ^ v2792;
  v2793[5] = v11521;
  int v2795 = v2002->timer;
  int v11522 = v2795 + 1;
  v2002->timer = v11522;int * v2797 = v2002->regs;
  int v2798 = v2797[8];
  int * v2799 = v2002->regs;
  int v2800 = v2799[16];
  int * v2801 = v2002->regs;
  int v11526 = v2798 ^ v2800;
  v2801[17] = v11526;
  int v2803 = v2002->timer;
  int v11527 = v2803 + 1;
  v2002->timer = v11527;int * v2805 = v2002->regs;
  int v2806 = v2805[9];
  int * v2807 = v2002->regs;
  int v2808 = v2807[6];
  int * v2809 = v2002->regs;
  int v11531 = v2806 ^ v2808;
  v2809[16] = v11531;
  int v2811 = v2002->timer;
  int v11532 = v2811 + 1;
  v2002->timer = v11532;int * v2813 = v2002->regs;
  int v2814 = v2813[23];
  int * v2815 = v2002->regs;
  int v2816 = v2815[21];
  int * v2817 = v2002->regs;
  int v11536 = v2814 + v2816;
  v2817[11] = v11536;
  int v2819 = v2002->timer;
  int v11537 = v2819 + 1;
  v2002->timer = v11537;int * v2821 = v2002->regs;
  int v2822 = v2821[5];
  int * v2823 = v2002->regs;
  int v2824 = v2823[20];
  int * v2825 = v2002->regs;
  int v11541 = v2822 + v2824;
  v2825[15] = v11541;
  int v2827 = v2002->timer;
  int v11542 = v2827 + 1;
  v2002->timer = v11542;int * v2829 = v2002->regs;
  int v2830 = v2829[17];
  int * v2831 = v2002->regs;
  int v2832 = v2831[19];
  int * v2833 = v2002->regs;
  int v11546 = v2830 + v2832;
  v2833[6] = v11546;
  int v2835 = v2002->timer;
  int v11547 = v2835 + 1;
  v2002->timer = v11547;int * v2837 = v2002->regs;
  int v2838 = v2837[16];
  int * v2839 = v2002->regs;
  int v2840 = v2839[22];
  int * v2841 = v2002->regs;
  int v11551 = v2838 + v2840;
  v2841[8] = v11551;
  int v2843 = v2002->timer;
  int v11552 = v2843 + 1;
  v2002->timer = v11552;int * v2845 = v2002->regs;
  int v2846 = v2845[11];
  int * v2847 = v2002->regs;
  int v11555 = (int)((unsigned int)v2846 >> 23);
  v2847[9] = v11555;
  int v2849 = v2002->timer;
  int v11556 = v2849 + 1;
  v2002->timer = v11556;int * v2851 = v2002->regs;
  int v2852 = v2851[11];
  int * v2853 = v2002->regs;
  int v11559 = v2852 << 9;
  v2853[11] = v11559;
  int v2855 = v2002->timer;
  int v11560 = v2855 + 1;
  v2002->timer = v11560;int * v2857 = v2002->regs;
  int v2858 = v2857[11];
  int * v2859 = v2002->regs;
  int v2860 = v2859[9];
  int * v2861 = v2002->regs;
  int v11564 = v2858 | v2860;
  v2861[11] = v11564;
  int v2863 = v2002->timer;
  int v11565 = v2863 + 1;
  v2002->timer = v11565;int * v2865 = v2002->regs;
  int v2866 = v2865[15];
  int * v2867 = v2002->regs;
  int v11568 = (int)((unsigned int)v2866 >> 23);
  v2867[9] = v11568;
  int v2869 = v2002->timer;
  int v11569 = v2869 + 1;
  v2002->timer = v11569;int * v2871 = v2002->regs;
  int v2872 = v2871[15];
  int * v2873 = v2002->regs;
  int v11572 = v2872 << 9;
  v2873[15] = v11572;
  int v2875 = v2002->timer;
  int v11573 = v2875 + 1;
  v2002->timer = v11573;int * v2877 = v2002->regs;
  int v2878 = v2877[15];
  int * v2879 = v2002->regs;
  int v2880 = v2879[9];
  int * v2881 = v2002->regs;
  int v11577 = v2878 | v2880;
  v2881[15] = v11577;
  int v2883 = v2002->timer;
  int v11578 = v2883 + 1;
  v2002->timer = v11578;int * v2885 = v2002->regs;
  int v2886 = v2885[6];
  int * v2887 = v2002->regs;
  int v11581 = (int)((unsigned int)v2886 >> 23);
  v2887[9] = v11581;
  int v2889 = v2002->timer;
  int v11582 = v2889 + 1;
  v2002->timer = v11582;int * v2891 = v2002->regs;
  int v2892 = v2891[6];
  int * v2893 = v2002->regs;
  int v11585 = v2892 << 9;
  v2893[6] = v11585;
  int v2895 = v2002->timer;
  int v11586 = v2895 + 1;
  v2002->timer = v11586;int * v2897 = v2002->regs;
  int v2898 = v2897[6];
  int * v2899 = v2002->regs;
  int v2900 = v2899[9];
  int * v2901 = v2002->regs;
  int v11590 = v2898 | v2900;
  v2901[6] = v11590;
  int v2903 = v2002->timer;
  int v11591 = v2903 + 1;
  v2002->timer = v11591;int * v2905 = v2002->regs;
  int v2906 = v2905[8];
  int * v2907 = v2002->regs;
  int v11594 = (int)((unsigned int)v2906 >> 23);
  v2907[9] = v11594;
  int v2909 = v2002->timer;
  int v11595 = v2909 + 1;
  v2002->timer = v11595;int * v2911 = v2002->regs;
  int v2912 = v2911[8];
  int * v2913 = v2002->regs;
  int v11598 = v2912 << 9;
  v2913[8] = v11598;
  int v2915 = v2002->timer;
  int v11599 = v2915 + 1;
  v2002->timer = v11599;int * v2917 = v2002->regs;
  int v2918 = v2917[8];
  int * v2919 = v2002->regs;
  int v2920 = v2919[9];
  int * v2921 = v2002->regs;
  int v11603 = v2918 | v2920;
  v2921[8] = v11603;
  int v2923 = v2002->timer;
  int v11604 = v2923 + 1;
  v2002->timer = v11604;int * v2925 = v2002->regs;
  int v2926 = v2925[27];
  int * v2927 = v2002->regs;
  int v2928 = v2927[11];
  int * v2929 = v2002->regs;
  int v11608 = v2926 ^ v2928;
  v2929[27] = v11608;
  int v2931 = v2002->timer;
  int v11609 = v2931 + 1;
  v2002->timer = v11609;int * v2933 = v2002->regs;
  int v2934 = v2933[25];
  int * v2935 = v2002->regs;
  int v2936 = v2935[15];
  int * v2937 = v2002->regs;
  int v11613 = v2934 ^ v2936;
  v2937[25] = v11613;
  int v2939 = v2002->timer;
  int v11614 = v2939 + 1;
  v2002->timer = v11614;int * v2941 = v2002->regs;
  int v2942 = v2941[26];
  int * v2943 = v2002->regs;
  int v2944 = v2943[6];
  int * v2945 = v2002->regs;
  int v11618 = v2942 ^ v2944;
  v2945[26] = v11618;
  int v2947 = v2002->timer;
  int v11619 = v2947 + 1;
  v2002->timer = v11619;int * v2949 = v2002->regs;
  int v2950 = v2949[24];
  int * v2951 = v2002->regs;
  int v2952 = v2951[8];
  int * v2953 = v2002->regs;
  int v11623 = v2950 ^ v2952;
  v2953[24] = v11623;
  int v2955 = v2002->timer;
  int v11624 = v2955 + 1;
  v2002->timer = v11624;int * v2957 = v2002->regs;
  int v2958 = v2957[27];
  int * v2959 = v2002->regs;
  int v2960 = v2959[23];
  int * v2961 = v2002->regs;
  int v11628 = v2958 + v2960;
  v2961[11] = v11628;
  int v2963 = v2002->timer;
  int v11629 = v2963 + 1;
  v2002->timer = v11629;int * v2965 = v2002->regs;
  int v2966 = v2965[25];
  int * v2967 = v2002->regs;
  int v2968 = v2967[5];
  int * v2969 = v2002->regs;
  int v11633 = v2966 + v2968;
  v2969[15] = v11633;
  int v2971 = v2002->timer;
  int v11634 = v2971 + 1;
  v2002->timer = v11634;int * v2973 = v2002->regs;
  int v2974 = v2973[26];
  int * v2975 = v2002->regs;
  int v2976 = v2975[17];
  int * v2977 = v2002->regs;
  int v11638 = v2974 + v2976;
  v2977[6] = v11638;
  int v2979 = v2002->timer;
  int v11639 = v2979 + 1;
  v2002->timer = v11639;int * v2981 = v2002->regs;
  int v2982 = v2981[24];
  int * v2983 = v2002->regs;
  int v2984 = v2983[16];
  int * v2985 = v2002->regs;
  int v11643 = v2982 + v2984;
  v2985[8] = v11643;
  int v2987 = v2002->timer;
  int v11644 = v2987 + 1;
  v2002->timer = v11644;int * v2989 = v2002->regs;
  int v2990 = v2989[11];
  int * v2991 = v2002->regs;
  int v11647 = (int)((unsigned int)v2990 >> 19);
  v2991[9] = v11647;
  int v2993 = v2002->timer;
  int v11648 = v2993 + 1;
  v2002->timer = v11648;int * v2995 = v2002->regs;
  int v2996 = v2995[11];
  int * v2997 = v2002->regs;
  int v11651 = v2996 << 13;
  v2997[11] = v11651;
  int v2999 = v2002->timer;
  int v11652 = v2999 + 1;
  v2002->timer = v11652;int * v3001 = v2002->regs;
  int v3002 = v3001[11];
  int * v3003 = v2002->regs;
  int v3004 = v3003[9];
  int * v3005 = v2002->regs;
  int v11656 = v3002 | v3004;
  v3005[11] = v11656;
  int v3007 = v2002->timer;
  int v11657 = v3007 + 1;
  v2002->timer = v11657;int * v3009 = v2002->regs;
  int v3010 = v3009[15];
  int * v3011 = v2002->regs;
  int v11660 = (int)((unsigned int)v3010 >> 19);
  v3011[9] = v11660;
  int v3013 = v2002->timer;
  int v11661 = v3013 + 1;
  v2002->timer = v11661;int * v3015 = v2002->regs;
  int v3016 = v3015[15];
  int * v3017 = v2002->regs;
  int v11664 = v3016 << 13;
  v3017[15] = v11664;
  int v3019 = v2002->timer;
  int v11665 = v3019 + 1;
  v2002->timer = v11665;int * v3021 = v2002->regs;
  int v3022 = v3021[15];
  int * v3023 = v2002->regs;
  int v3024 = v3023[9];
  int * v3025 = v2002->regs;
  int v11669 = v3022 | v3024;
  v3025[15] = v11669;
  int v3027 = v2002->timer;
  int v11670 = v3027 + 1;
  v2002->timer = v11670;int * v3029 = v2002->regs;
  int v3030 = v3029[6];
  int * v3031 = v2002->regs;
  int v11673 = (int)((unsigned int)v3030 >> 19);
  v3031[9] = v11673;
  int v3033 = v2002->timer;
  int v11674 = v3033 + 1;
  v2002->timer = v11674;int * v3035 = v2002->regs;
  int v3036 = v3035[6];
  int * v3037 = v2002->regs;
  int v11677 = v3036 << 13;
  v3037[6] = v11677;
  int v3039 = v2002->timer;
  int v11678 = v3039 + 1;
  v2002->timer = v11678;int * v3041 = v2002->regs;
  int v3042 = v3041[6];
  int * v3043 = v2002->regs;
  int v3044 = v3043[9];
  int * v3045 = v2002->regs;
  int v11682 = v3042 | v3044;
  v3045[6] = v11682;
  int v3047 = v2002->timer;
  int v11683 = v3047 + 1;
  v2002->timer = v11683;int * v3049 = v2002->regs;
  int v3050 = v3049[8];
  int * v3051 = v2002->regs;
  int v11686 = (int)((unsigned int)v3050 >> 19);
  v3051[9] = v11686;
  int v3053 = v2002->timer;
  int v11687 = v3053 + 1;
  v2002->timer = v11687;int * v3055 = v2002->regs;
  int v3056 = v3055[8];
  int * v3057 = v2002->regs;
  int v11690 = v3056 << 13;
  v3057[8] = v11690;
  int v3059 = v2002->timer;
  int v11691 = v3059 + 1;
  v2002->timer = v11691;int * v3061 = v2002->regs;
  int v3062 = v3061[8];
  int * v3063 = v2002->regs;
  int v3064 = v3063[9];
  int * v3065 = v2002->regs;
  int v11695 = v3062 | v3064;
  v3065[8] = v11695;
  int v3067 = v2002->timer;
  int v11696 = v3067 + 1;
  v2002->timer = v11696;int * v3069 = v2002->regs;
  int v3070 = v3069[14];
  int * v3071 = v2002->regs;
  int v3072 = v3071[11];
  int * v3073 = v2002->regs;
  int v11700 = v3070 ^ v3072;
  v3073[14] = v11700;
  int v3075 = v2002->timer;
  int v11701 = v3075 + 1;
  v2002->timer = v11701;int * v3077 = v2002->regs;
  int v3078 = v3077[12];
  int * v3079 = v2002->regs;
  int v3080 = v3079[15];
  int * v3081 = v2002->regs;
  int v11705 = v3078 ^ v3080;
  v3081[12] = v11705;
  int v3083 = v2002->timer;
  int v11706 = v3083 + 1;
  v2002->timer = v11706;int * v3085 = v2002->regs;
  int v3086 = v3085[13];
  int * v3087 = v2002->regs;
  int v3088 = v3087[6];
  int * v3089 = v2002->regs;
  int v11710 = v3086 ^ v3088;
  v3089[13] = v11710;
  int v3091 = v2002->timer;
  int v11711 = v3091 + 1;
  v2002->timer = v11711;int * v3093 = v2002->regs;
  int v3094 = v3093[1];
  int * v3095 = v2002->regs;
  int v3096 = v3095[8];
  int * v3097 = v2002->regs;
  int v11715 = v3094 ^ v3096;
  v3097[1] = v11715;
  int v3099 = v2002->timer;
  int v11716 = v3099 + 1;
  v2002->timer = v11716;int * v3101 = v2002->regs;
  int v3102 = v3101[14];
  int * v3103 = v2002->regs;
  int v3104 = v3103[27];
  int * v3105 = v2002->regs;
  int v11720 = v3102 + v3104;
  v3105[11] = v11720;
  int v3107 = v2002->timer;
  int v11721 = v3107 + 1;
  v2002->timer = v11721;int * v3109 = v2002->regs;
  int v3110 = v3109[12];
  int * v3111 = v2002->regs;
  int v3112 = v3111[25];
  int * v3113 = v2002->regs;
  int v11725 = v3110 + v3112;
  v3113[15] = v11725;
  int v3115 = v2002->timer;
  int v11726 = v3115 + 1;
  v2002->timer = v11726;int * v3117 = v2002->regs;
  int v3118 = v3117[13];
  int * v3119 = v2002->regs;
  int v3120 = v3119[26];
  int * v3121 = v2002->regs;
  int v11730 = v3118 + v3120;
  v3121[6] = v11730;
  int v3123 = v2002->timer;
  int v11731 = v3123 + 1;
  v2002->timer = v11731;int * v3125 = v2002->regs;
  int v3126 = v3125[1];
  int * v3127 = v2002->regs;
  int v3128 = v3127[24];
  int * v3129 = v2002->regs;
  int v11735 = v3126 + v3128;
  v3129[8] = v11735;
  int v3131 = v2002->timer;
  int v11736 = v3131 + 1;
  v2002->timer = v11736;int * v3133 = v2002->regs;
  int v3134 = v3133[11];
  int * v3135 = v2002->regs;
  int v11739 = (int)((unsigned int)v3134 >> 14);
  v3135[9] = v11739;
  int v3137 = v2002->timer;
  int v11740 = v3137 + 1;
  v2002->timer = v11740;int * v3139 = v2002->regs;
  int v3140 = v3139[11];
  int * v3141 = v2002->regs;
  int v11743 = v3140 << 18;
  v3141[11] = v11743;
  int v3143 = v2002->timer;
  int v11744 = v3143 + 1;
  v2002->timer = v11744;int * v3145 = v2002->regs;
  int v3146 = v3145[11];
  int * v3147 = v2002->regs;
  int v3148 = v3147[9];
  int * v3149 = v2002->regs;
  int v11748 = v3146 | v3148;
  v3149[11] = v11748;
  int v3151 = v2002->timer;
  int v11749 = v3151 + 1;
  v2002->timer = v11749;int * v3153 = v2002->regs;
  int v3154 = v3153[15];
  int * v3155 = v2002->regs;
  int v11752 = (int)((unsigned int)v3154 >> 14);
  v3155[9] = v11752;
  int v3157 = v2002->timer;
  int v11753 = v3157 + 1;
  v2002->timer = v11753;int * v3159 = v2002->regs;
  int v3160 = v3159[15];
  int * v3161 = v2002->regs;
  int v11756 = v3160 << 18;
  v3161[15] = v11756;
  int v3163 = v2002->timer;
  int v11757 = v3163 + 1;
  v2002->timer = v11757;int * v3165 = v2002->regs;
  int v3166 = v3165[15];
  int * v3167 = v2002->regs;
  int v3168 = v3167[9];
  int * v3169 = v2002->regs;
  int v11761 = v3166 | v3168;
  v3169[15] = v11761;
  int v3171 = v2002->timer;
  int v11762 = v3171 + 1;
  v2002->timer = v11762;int * v3173 = v2002->regs;
  int v3174 = v3173[6];
  int * v3175 = v2002->regs;
  int v11765 = (int)((unsigned int)v3174 >> 14);
  v3175[9] = v11765;
  int v3177 = v2002->timer;
  int v11766 = v3177 + 1;
  v2002->timer = v11766;int * v3179 = v2002->regs;
  int v3180 = v3179[6];
  int * v3181 = v2002->regs;
  int v11769 = v3180 << 18;
  v3181[6] = v11769;
  int v3183 = v2002->timer;
  int v11770 = v3183 + 1;
  v2002->timer = v11770;int * v3185 = v2002->regs;
  int v3186 = v3185[6];
  int * v3187 = v2002->regs;
  int v3188 = v3187[9];
  int * v3189 = v2002->regs;
  int v11774 = v3186 | v3188;
  v3189[6] = v11774;
  int v3191 = v2002->timer;
  int v11775 = v3191 + 1;
  v2002->timer = v11775;int * v3193 = v2002->regs;
  int v3194 = v3193[8];
  int * v3195 = v2002->regs;
  int v11778 = (int)((unsigned int)v3194 >> 14);
  v3195[9] = v11778;
  int v3197 = v2002->timer;
  int v11779 = v3197 + 1;
  v2002->timer = v11779;int * v3199 = v2002->regs;
  int v3200 = v3199[8];
  int * v3201 = v2002->regs;
  int v11782 = v3200 << 18;
  v3201[8] = v11782;
  int v3203 = v2002->timer;
  int v11783 = v3203 + 1;
  v2002->timer = v11783;int * v3205 = v2002->regs;
  int v3206 = v3205[8];
  int * v3207 = v2002->regs;
  int v3208 = v3207[9];
  int * v3209 = v2002->regs;
  int v11787 = v3206 | v3208;
  v3209[8] = v11787;
  int v3211 = v2002->timer;
  int v11788 = v3211 + 1;
  v2002->timer = v11788;int * v3213 = v2002->regs;
  int v3214 = v3213[21];
  int * v3215 = v2002->regs;
  int v3216 = v3215[11];
  int * v3217 = v2002->regs;
  int v11792 = v3214 ^ v3216;
  v3217[21] = v11792;
  int v3219 = v2002->timer;
  int v11793 = v3219 + 1;
  v2002->timer = v11793;int * v3221 = v2002->regs;
  int v3222 = v3221[20];
  int * v3223 = v2002->regs;
  int v3224 = v3223[15];
  int * v3225 = v2002->regs;
  int v11797 = v3222 ^ v3224;
  v3225[11] = v11797;
  int v3227 = v2002->timer;
  int v11798 = v3227 + 1;
  v2002->timer = v11798;int * v3229 = v2002->regs;
  int v3230 = v3229[19];
  int * v3231 = v2002->regs;
  int v3232 = v3231[6];
  int * v3233 = v2002->regs;
  int v11802 = v3230 ^ v3232;
  v3233[19] = v11802;
  int v3235 = v2002->timer;
  int v11803 = v3235 + 1;
  v2002->timer = v11803;int * v3237 = v2002->regs;
  int v3238 = v3237[22];
  int * v3239 = v2002->regs;
  int v3240 = v3239[8];
  int * v3241 = v2002->regs;
  int v11807 = v3238 ^ v3240;
  v3241[22] = v11807;
  int * v3243 = v2002->saved_regs;
  int * v3244 = v2002->regs;
  int v3245 = v3244[30];
  v3243[30] = v3245;
  int v3247 = v2002->timer;
  int v11812 = v3247 + 1;
  v2002->timer = v11812;int * v3249 = v2002->regs;
  int v3250 = v3249[30];
  int * v3251 = v2002->regs;
  int v11815 = v3250 + 1;
  v3251[30] = v11815;
  int * v3253 = v2002->regs;
  int v3254 = v3253[31];
  bool v11818 = (v3254 ^ -2147483648) < -2147483648;
  struct StateT * v10982 = (v11818 ? ({
    int v3255 = v2002->timer;
    int v11819 = v3255 + 15;
    v2002->timer = v11819;int * v3257 = v2002->saved_regs;
    int v3258 = v3257[15];
    int * v3259 = v2002->regs;
    v3259[15] = v3258;
    int * v3261 = v2002->saved_regs;
    int v3262 = v3261[20];
    int * v3263 = v2002->regs;
    v3263[20] = v3262;
    int * v3265 = v2002->saved_regs;
    int v3266 = v3265[18];
    int * v3267 = v2002->regs;
    v3267[18] = v3266;
    int * v3269 = v2002->saved_regs;
    int v3270 = v3269[8];
    int * v3271 = v2002->regs;
    v3271[8] = v3270;
    int * v3273 = v2002->saved_regs;
    int v3274 = v3273[9];
    int * v3275 = v2002->regs;
    v3275[9] = v3274;
    int * v3277 = v2002->saved_regs;
    int v3278 = v3277[12];
    int * v3279 = v2002->regs;
    v3279[12] = v3278;
    int * v3281 = v2002->saved_regs;
    int v3282 = v3281[13];
    int * v3283 = v2002->regs;
    v3283[13] = v3282;
    int * v3285 = v2002->saved_regs;
    int v3286 = v3285[1];
    int * v3287 = v2002->regs;
    v3287[1] = v3286;
    int * v3289 = v2002->saved_regs;
    int v3290 = v3289[14];
    int * v3291 = v2002->regs;
    v3291[14] = v3290;
    int * v3293 = v2002->saved_regs;
    int v3294 = v3293[26];
    int * v3295 = v2002->regs;
    v3295[26] = v3294;
    int * v3297 = v2002->saved_regs;
    int v3298 = v3297[24];
    int * v3299 = v2002->regs;
    v3299[24] = v3298;
    int * v3301 = v2002->saved_regs;
    int v3302 = v3301[27];
    int * v3303 = v2002->regs;
    v3303[27] = v3302;
    int * v3305 = v2002->saved_regs;
    int v3306 = v3305[25];
    int * v3307 = v2002->regs;
    v3307[25] = v3306;
    int * v3309 = v2002->saved_regs;
    int v3310 = v3309[6];
    int * v3311 = v2002->regs;
    v3311[6] = v3310;
    int * v3313 = v2002->saved_regs;
    int v3314 = v3313[23];
    int * v3315 = v2002->regs;
    v3315[23] = v3314;
    int * v3317 = v2002->saved_regs;
    int v3318 = v3317[16];
    int * v3319 = v2002->regs;
    v3319[16] = v3318;
    int * v3321 = v2002->saved_regs;
    int v3322 = v3321[17];
    int * v3323 = v2002->regs;
    v3323[17] = v3322;
    int * v3325 = v2002->saved_regs;
    int v3326 = v3325[5];
    int * v3327 = v2002->regs;
    v3327[5] = v3326;
    int * v3329 = v2002->saved_regs;
    int v3330 = v3329[21];
    int * v3331 = v2002->regs;
    v3331[21] = v3330;
    int * v3333 = v2002->saved_regs;
    int v3334 = v3333[19];
    int * v3335 = v2002->regs;
    v3335[19] = v3334;
    int * v3337 = v2002->saved_regs;
    int v3338 = v3337[22];
    int * v3339 = v2002->regs;
    v3339[22] = v3338;
    int * v3341 = v2002->saved_regs;
    int v3342 = v3341[11];
    int * v3343 = v2002->regs;
    v3343[11] = v3342;
    int * v3345 = v2002->saved_regs;
    int v3346 = v3345[30];
    int * v3347 = v2002->regs;
    v3347[30] = v3346;
    struct StateT * v7747 = v3349(v2002);
    v7747;
  }) : ({
    int v7749 = v2002->timer;
    int v11891 = v7749 + 1;
    v2002->timer = v11891;int * v7751 = v2002->regs;
    int v7752 = v7751[31];
    int * v7753 = v2002->regs;
    int v7754 = v7753[30];
    bool v11894 = (v7752 ^ -2147483648) >= (v7754 ^ -2147483648);
    struct StateT * v10980 = (v11894 ? ({
      struct StateT * v10976 = v7755(v2002);
      v10976;
    }) : ({
      struct StateT * v10978 = v3349(v2002);
      v10978;
    }));
    v10980;
  }));
  return v10982;
}

struct StateT * v8179(struct StateT * v8180) {
  int v8181 = v8180->timer;
  int v10476 = v8181 + 1;
  v8180->timer = v10476;int * v8183 = v8180->regs;
  int v8184 = v8183[15];
  int * v8185 = v8180->regs;
  int v8186 = v8185[20];
  int * v8187 = v8180->regs;
  int v10482 = v8184 | v8186;
  v8187[15] = v10482;
  struct StateT * v10474 = v8189(v8180);
  return v10474;
}

struct StateT * v8171(struct StateT * v8172) {
  int v8173 = v8172->timer;
  int v10487 = v8173 + 1;
  v8172->timer = v10487;int * v8175 = v8172->regs;
  int v8176 = v8175[15];
  int * v8177 = v8172->regs;
  int v10491 = v8176 << 13;
  v8177[15] = v10491;
  struct StateT * v10485 = v8179(v8172);
  return v10485;
}

struct StateT * v8695(struct StateT * v8696) {
  int v8697 = v8696->timer;
  int v9873 = v8697 + 1;
  v8696->timer = v9873;int * v8699 = v8696->regs;
  int v8700 = v8699[17];
  int * v8701 = v8696->regs;
  int v8702 = v8701[19];
  int * v8703 = v8696->regs;
  int v9880 = v8700 + v8702;
  v8703[6] = v9880;
  struct StateT * v9871 = v8705(v8696);
  return v9871;
}

struct StateT * v1993(struct StateT * v1994) {
  int v1995 = v1994->timer;
  int v11903 = v1995 + 1;
  v1994->timer = v11903;int * v1997 = v1994->regs;
  int v1998 = v1997[15];
  int * v1999 = v1994->regs;
  v1999[13] = v1998;
  struct StateT * v11901 = v2001(v1994);
  return v11901;
}

struct StateT * v8959(struct StateT * v8960) {
  int v8961 = v8960->timer;
  int v9570 = v8961 + 1;
  v8960->timer = v9570;int * v8963 = v8960->regs;
  int v8964 = v8963[6];
  int * v8965 = v8960->regs;
  int v9574 = v8964 << 13;
  v8965[6] = v9574;
  struct StateT * v9568 = v8967(v8960);
  return v9568;
}

struct StateT * v8591(struct StateT * v8592) {
  int v8593 = v8592->timer;
  int v9998 = v8593 + 1;
  v8592->timer = v9998;int * v8595 = v8592->regs;
  int v8596 = v8595[16];
  int * v8597 = v8592->regs;
  int v10002 = v8596 << 7;
  v8597[16] = v10002;
  struct StateT * v9996 = v8599(v8592);
  return v9996;
}

struct StateT * v8197(struct StateT * v8198) {
  int v8199 = v8198->timer;
  int v10457 = v8199 + 1;
  v8198->timer = v10457;int * v8201 = v8198->regs;
  int v8202 = v8201[8];
  int * v8203 = v8198->regs;
  int v10461 = v8202 << 13;
  v8203[8] = v10461;
  struct StateT * v10455 = v8205(v8198);
  return v10455;
}

struct StateT * v3453(struct StateT * v3454) {
  int v3455 = v3454->timer;
  int v7641 = v3455 + 1;
  v3454->timer = v7641;int * v3457 = v3454->regs;
  v3457[6] = 857759744;
  struct StateT * v7639 = v3459(v3454);
  return v7639;
}

struct StateT * v1475(struct StateT * v1476) {
  int v1477 = v1476->timer;
  int v12312 = v1477 + 1;
  v1476->timer = v12312;int * v1479 = v1476->regs;
  int v1480 = v1479[2];
  int * v1481 = v1476->regs;
  int v1482 = v1481[26];
  int * v1483 = v1476->cache_keys;
  int v1484 = v1483[0];
  bool v12319 = v1484 == ((int)((unsigned int)(v1480 + 20) >> 2));
  int v1528 = (v12319 ? ({
    int * v1485 = v1476->cache_vals;
    v1485[0] = v1482;
    v1482;
  }) : ({
    int * v1488 = v1476->cache_keys;
    int v1489 = v1488[1];
    bool v12324 = v1489 == ((int)((unsigned int)(v1480 + 20) >> 2));
    int v1526 = (v12324 ? ({
      int * v1490 = v1476->cache_keys;
      int * v1491 = v1476->cache_keys;
      int v1492 = v1491[0];
      v1490[1] = v1492;
      int * v1494 = v1476->cache_vals;
      int * v1495 = v1476->cache_vals;
      int v1496 = v1495[0];
      v1494[1] = v1496;
      int * v1498 = v1476->cache_keys;
      int v12332 = (int)((unsigned int)(v1480 + 20) >> 2);
      v1498[0] = v12332;
      int * v1500 = v1476->cache_vals;
      v1500[0] = v1482;
      int v1502 = v1476->timer;
      int v12335 = v1502 + 1;
      v1476->timer = v12335;v1482;
    }) : ({
      int * v1505 = v1476->mem;
      int * v1506 = v1476->cache_keys;
      int v1507 = v1506[1];
      int * v1508 = v1476->cache_vals;
      int v1509 = v1508[1];
      v1505[v1507] = v1509;
      int * v1511 = v1476->cache_keys;
      int * v1512 = v1476->cache_keys;
      int v1513 = v1512[0];
      v1511[1] = v1513;
      int * v1515 = v1476->cache_vals;
      int * v1516 = v1476->cache_vals;
      int v1517 = v1516[0];
      v1515[1] = v1517;
      int * v1519 = v1476->cache_keys;
      int v12348 = (int)((unsigned int)(v1480 + 20) >> 2);
      v1519[0] = v12348;
      int * v1521 = v1476->cache_vals;
      v1521[0] = v1482;
      int v1523 = v1476->timer;
      int v12351 = v1523 + 100;
      v1476->timer = v12351;v1482;
    }));
    v1526;
  }));
  struct StateT * v12310 = v1529(v1476);
  return v12310;
}

struct StateT * v8065(struct StateT * v8066) {
  int v8067 = v8066->timer;
  int v10609 = v8067 + 1;
  v8066->timer = v10609;int * v8069 = v8066->regs;
  int v8070 = v8069[18];
  int * v8071 = v8066->regs;
  int v10613 = v8070 << 9;
  v8071[18] = v10613;
  struct StateT * v10607 = v8073(v8066);
  return v10607;
}

struct StateT * v8573(struct StateT * v8574) {
  int v8575 = v8574->timer;
  int v10017 = v8575 + 1;
  v8574->timer = v10017;int * v8577 = v8574->regs;
  int v8578 = v8577[11];
  int * v8579 = v8574->regs;
  int v8580 = v8579[5];
  int * v8581 = v8574->regs;
  int v10023 = v8578 | v8580;
  v8581[11] = v10023;
  struct StateT * v10015 = v8583(v8574);
  return v10015;
}

struct StateT * v3941(struct StateT * v3942) {
  int v3943 = v3942->timer;
  int v7172 = v3943 + 1;
  v3942->timer = v7172;int * v3945 = v3942->regs;
  int v3946 = v3945[2];
  int * v3947 = v3942->cache_keys;
  int v3948 = v3947[0];
  bool v7177 = v3948 == ((int)((unsigned int)(v3946 + 40) >> 2));
  int v3996 = (v7177 ? ({
    int * v3949 = v3942->cache_vals;
    int v3950 = v3949[0];
    v3950;
  }) : ({
    int * v3952 = v3942->cache_keys;
    int v3953 = v3952[1];
    bool v7182 = v3953 == ((int)((unsigned int)(v3946 + 40) >> 2));
    int v3994 = (v7182 ? ({
      int * v3954 = v3942->cache_vals;
      int v3955 = v3954[1];
      int * v3956 = v3942->cache_keys;
      int * v3957 = v3942->cache_keys;
      int v3958 = v3957[0];
      v3956[1] = v3958;
      int * v3960 = v3942->cache_vals;
      int * v3961 = v3942->cache_vals;
      int v3962 = v3961[0];
      v3960[1] = v3962;
      int * v3964 = v3942->cache_keys;
      int v7191 = (int)((unsigned int)(v3946 + 40) >> 2);
      v3964[0] = v7191;
      int * v3966 = v3942->cache_vals;
      v3966[0] = v3955;
      int v3968 = v3942->timer;
      int v7194 = v3968 + 1;
      v3942->timer = v7194;v3955;
    }) : ({
      int * v3971 = v3942->mem;
      int v7196 = (int)((unsigned int)(v3946 + 40) >> 2);
      int v3972 = v3971[v7196];
      int * v3973 = v3942->mem;
      int * v3974 = v3942->cache_keys;
      int v3975 = v3974[1];
      int * v3976 = v3942->cache_vals;
      int v3977 = v3976[1];
      v3973[v3975] = v3977;
      int * v3979 = v3942->cache_keys;
      int * v3980 = v3942->cache_keys;
      int v3981 = v3980[0];
      v3979[1] = v3981;
      int * v3983 = v3942->cache_vals;
      int * v3984 = v3942->cache_vals;
      int v3985 = v3984[0];
      v3983[1] = v3985;
      int * v3987 = v3942->cache_keys;
      v3987[0] = v7196;
      int * v3989 = v3942->cache_vals;
      v3989[0] = v3972;
      int v3991 = v3942->timer;
      int v7211 = v3991 + 100;
      v3942->timer = v7211;v3972;
    }));
    v3994;
  }));
  int * v3997 = v3942->regs;
  v3997[30] = v3996;
  struct StateT * v7170 = v3999(v3942);
  return v7170;
}

struct StateT * v3795(struct StateT * v3796) {
  int v3797 = v3796->timer;
  int v7338 = v3797 + 1;
  v3796->timer = v7338;int * v3799 = v3796->regs;
  int v3800 = v3799[17];
  int * v3801 = v3796->regs;
  int v3802 = v3801[30];
  int * v3803 = v3796->regs;
  int v7344 = v3800 + v3802;
  v3803[17] = v7344;
  struct StateT * v7336 = v3805(v3796);
  return v7336;
}

struct StateT * v8327(struct StateT * v8328) {
  int v8329 = v8328->timer;
  int v10302 = v8329 + 1;
  v8328->timer = v10302;int * v8331 = v8328->regs;
  int v8332 = v8331[18];
  int * v8333 = v8328->regs;
  int v8334 = v8333[27];
  int * v8335 = v8328->regs;
  int v10309 = v8332 + v8334;
  v8335[17] = v10309;
  struct StateT * v10300 = v8337(v8328);
  return v10300;
}

struct StateT * v4057(struct StateT * v4058) {
  int v4059 = v4058->timer;
  int v7095 = v4059 + 1;
  v4058->timer = v7095;int * v4061 = v4058->regs;
  int v4062 = v4061[11];
  int * v4063 = v4058->regs;
  int v4064 = v4063[6];
  int * v4065 = v4058->regs;
  int v7101 = v4062 + v4064;
  v4065[11] = v7101;
  struct StateT * v7093 = v4067(v4058);
  return v7093;
}

struct StateT * v1425(struct StateT * v1426) {
  int v1427 = v1426->timer;
  int v12412 = v1427 + 1;
  v1426->timer = v12412;int * v1429 = v1426->regs;
  v1429[14] = 2036477952;
  struct StateT * v12410 = v1431(v1426);
  return v12410;
}

struct StateT * v1637(struct StateT * v1638) {
  int v1639 = v1638->timer;
  int v12178 = v1639 + 1;
  v1638->timer = v12178;int * v1641 = v1638->regs;
  int v1642 = v1641[2];
  int * v1643 = v1638->regs;
  int v1644 = v1643[1];
  int * v1645 = v1638->cache_keys;
  int v1646 = v1645[0];
  bool v12185 = v1646 == ((int)((unsigned int)(v1642 + 40) >> 2));
  int v1690 = (v12185 ? ({
    int * v1647 = v1638->cache_vals;
    v1647[0] = v1644;
    v1644;
  }) : ({
    int * v1650 = v1638->cache_keys;
    int v1651 = v1650[1];
    bool v12189 = v1651 == ((int)((unsigned int)(v1642 + 40) >> 2));
    int v1688 = (v12189 ? ({
      int * v1652 = v1638->cache_keys;
      int * v1653 = v1638->cache_keys;
      int v1654 = v1653[0];
      v1652[1] = v1654;
      int * v1656 = v1638->cache_vals;
      int * v1657 = v1638->cache_vals;
      int v1658 = v1657[0];
      v1656[1] = v1658;
      int * v1660 = v1638->cache_keys;
      int v12197 = (int)((unsigned int)(v1642 + 40) >> 2);
      v1660[0] = v12197;
      int * v1662 = v1638->cache_vals;
      v1662[0] = v1644;
      int v1664 = v1638->timer;
      int v12200 = v1664 + 1;
      v1638->timer = v12200;v1644;
    }) : ({
      int * v1667 = v1638->mem;
      int * v1668 = v1638->cache_keys;
      int v1669 = v1668[1];
      int * v1670 = v1638->cache_vals;
      int v1671 = v1670[1];
      v1667[v1669] = v1671;
      int * v1673 = v1638->cache_keys;
      int * v1674 = v1638->cache_keys;
      int v1675 = v1674[0];
      v1673[1] = v1675;
      int * v1677 = v1638->cache_vals;
      int * v1678 = v1638->cache_vals;
      int v1679 = v1678[0];
      v1677[1] = v1679;
      int * v1681 = v1638->cache_keys;
      int v12213 = (int)((unsigned int)(v1642 + 40) >> 2);
      v1681[0] = v12213;
      int * v1683 = v1638->cache_vals;
      v1683[0] = v1644;
      int v1685 = v1638->timer;
      int v12216 = v1685 + 100;
      v1638->timer = v12216;v1644;
    }));
    v1688;
  }));
  struct StateT * v12176 = v1691(v1638);
  return v12176;
}

struct StateT * v3999(struct StateT * v4000) {
  int v4001 = v4000->timer;
  int v7161 = v4001 + 1;
  v4000->timer = v7161;int * v4003 = v4000->regs;
  int v4004 = v4003[1];
  int * v4005 = v4000->regs;
  int v4006 = v4005[30];
  int * v4007 = v4000->regs;
  int v7167 = v4004 + v4006;
  v4007[1] = v7167;
  struct StateT * v7159 = v4009(v4000);
  return v7159;
}

struct StateT * v9177(struct StateT * v9178) {
  int v9179 = v9178->timer;
  int v9317 = v9179 + 1;
  v9178->timer = v9317;int * v9181 = v9178->regs;
  int v9182 = v9181[8];
  int * v9183 = v9178->regs;
  int v9184 = v9183[9];
  int * v9185 = v9178->regs;
  int v9323 = v9182 | v9184;
  v9185[8] = v9323;
  struct StateT * v9315 = v9187(v9178);
  return v9315;
}

struct StateT * v8005(struct StateT * v8006) {
  int v8007 = v8006->timer;
  int v10678 = v8007 + 1;
  v8006->timer = v10678;int * v8009 = v8006->regs;
  int v8010 = v8009[8];
  int * v8011 = v8006->regs;
  int v10683 = (int)((unsigned int)v8010 >> 23);
  v8011[20] = v10683;
  struct StateT * v10676 = v8013(v8006);
  return v10676;
}

struct StateT * v4067(struct StateT * v4068) {
  int v4069 = v4068->timer;
  int v7084 = v4069 + 1;
  v4068->timer = v7084;int * v4071 = v4068->regs;
  int v4072 = v4071[19];
  int * v4073 = v4068->regs;
  int v4074 = v4073[7];
  int * v4075 = v4068->regs;
  int v7090 = v4072 + v4074;
  v4075[7] = v7090;
  struct StateT * v7082 = v4077(v4068);
  return v7082;
}

struct StateT * v7959(struct StateT * v7960) {
  int v7961 = v7960->timer;
  int v10730 = v7961 + 1;
  v7960->timer = v10730;int * v7963 = v7960->regs;
  int v7964 = v7963[1];
  int * v7965 = v7960->regs;
  int v7966 = v7965[19];
  int * v7967 = v7960->regs;
  int v10737 = v7964 + v7966;
  v7967[9] = v10737;
  struct StateT * v10728 = v7969(v7960);
  return v10728;
}

struct StateT * v7873(struct StateT * v7874) {
  int v7875 = v7874->timer;
  int v10830 = v7875 + 1;
  v7874->timer = v10830;int * v7877 = v7874->regs;
  int v7878 = v7877[8];
  int * v7879 = v7874->regs;
  int v10835 = (int)((unsigned int)v7878 >> 25);
  v7879[20] = v10835;
  struct StateT * v10828 = v7881(v7874);
  return v10828;
}

struct StateT * v8869(struct StateT * v8870) {
  int v8871 = v8870->timer;
  int v9673 = v8871 + 1;
  v8870->timer = v9673;int * v8873 = v8870->regs;
  int v8874 = v8873[25];
  int * v8875 = v8870->regs;
  int v8876 = v8875[5];
  int * v8877 = v8870->regs;
  int v9680 = v8874 + v8876;
  v8877[15] = v9680;
  struct StateT * v9671 = v8879(v8870);
  return v9671;
}

struct StateT * v8767(struct StateT * v8768) {
  int v8769 = v8768->timer;
  int v9791 = v8769 + 1;
  v8768->timer = v9791;int * v8771 = v8768->regs;
  int v8772 = v8771[6];
  int * v8773 = v8768->regs;
  int v9796 = (int)((unsigned int)v8772 >> 23);
  v8773[9] = v9796;
  struct StateT * v9789 = v8775(v8768);
  return v9789;
}

struct StateT * v7795(struct StateT * v7796) {
  int v7797 = v7796->timer;
  int v10920 = v7797 + 1;
  v7796->timer = v10920;int * v7799 = v7796->regs;
  int v7800 = v7799[15];
  int * v7801 = v7796->regs;
  int v10925 = (int)((unsigned int)v7800 >> 25);
  v7801[9] = v10925;
  struct StateT * v10918 = v7803(v7796);
  return v10918;
}

struct StateT * v8021(struct StateT * v8022) {
  int v8023 = v8022->timer;
  int v10658 = v8023 + 1;
  v8022->timer = v10658;int * v8025 = v8022->regs;
  int v8026 = v8025[8];
  int * v8027 = v8022->regs;
  int v8028 = v8027[20];
  int * v8029 = v8022->regs;
  int v10664 = v8026 | v8028;
  v8029[8] = v10664;
  struct StateT * v10656 = v8031(v8022);
  return v10656;
}

struct StateT * v4031(struct StateT * v4032) {
  int v4033 = v4032->timer;
  int v7126 = v4033 + 1;
  v4032->timer = v7126;int * v4035 = v4032->regs;
  int v4036 = v4035[7];
  int * v4037 = v4032->regs;
  int v7130 = v4036 + -718;
  v4037[7] = v7130;
  struct StateT * v7124 = v4039(v4032);
  return v7124;
}

struct StateT * v1239(struct StateT * v1240) {
  int v1241 = v1240->timer;
  int v12532 = v1241 + 1;
  v1240->timer = v12532;int * v1243 = v1240->regs;
  int v1244 = v1243[11];
  int * v1245 = v1240->cache_keys;
  int v1246 = v1245[0];
  bool v12537 = v1246 == ((int)((unsigned int)(v1244 + 4) >> 2));
  int v1294 = (v12537 ? ({
    int * v1247 = v1240->cache_vals;
    int v1248 = v1247[0];
    v1248;
  }) : ({
    int * v1250 = v1240->cache_keys;
    int v1251 = v1250[1];
    bool v12542 = v1251 == ((int)((unsigned int)(v1244 + 4) >> 2));
    int v1292 = (v12542 ? ({
      int * v1252 = v1240->cache_vals;
      int v1253 = v1252[1];
      int * v1254 = v1240->cache_keys;
      int * v1255 = v1240->cache_keys;
      int v1256 = v1255[0];
      v1254[1] = v1256;
      int * v1258 = v1240->cache_vals;
      int * v1259 = v1240->cache_vals;
      int v1260 = v1259[0];
      v1258[1] = v1260;
      int * v1262 = v1240->cache_keys;
      int v12551 = (int)((unsigned int)(v1244 + 4) >> 2);
      v1262[0] = v12551;
      int * v1264 = v1240->cache_vals;
      v1264[0] = v1253;
      int v1266 = v1240->timer;
      int v12554 = v1266 + 1;
      v1240->timer = v12554;v1253;
    }) : ({
      int * v1269 = v1240->mem;
      int v12556 = (int)((unsigned int)(v1244 + 4) >> 2);
      int v1270 = v1269[v12556];
      int * v1271 = v1240->mem;
      int * v1272 = v1240->cache_keys;
      int v1273 = v1272[1];
      int * v1274 = v1240->cache_vals;
      int v1275 = v1274[1];
      v1271[v1273] = v1275;
      int * v1277 = v1240->cache_keys;
      int * v1278 = v1240->cache_keys;
      int v1279 = v1278[0];
      v1277[1] = v1279;
      int * v1281 = v1240->cache_vals;
      int * v1282 = v1240->cache_vals;
      int v1283 = v1282[0];
      v1281[1] = v1283;
      int * v1285 = v1240->cache_keys;
      v1285[0] = v12556;
      int * v1287 = v1240->cache_vals;
      v1287[0] = v1270;
      int v1289 = v1240->timer;
      int v12571 = v1289 + 100;
      v1240->timer = v12571;v1270;
    }));
    v1292;
  }));
  int * v1295 = v1240->regs;
  v1295[25] = v1294;
  struct StateT * v12530 = v1297(v1240);
  return v12530;
}

struct StateT * v3873(struct StateT * v3874) {
  int v3875 = v3874->timer;
  int v7231 = v3875 + 1;
  v3874->timer = v7231;int * v3877 = v3874->regs;
  int v3878 = v3877[2];
  int * v3879 = v3874->cache_keys;
  int v3880 = v3879[0];
  bool v7236 = v3880 == ((int)((unsigned int)(v3878 + 36) >> 2));
  int v3928 = (v7236 ? ({
    int * v3881 = v3874->cache_vals;
    int v3882 = v3881[0];
    v3882;
  }) : ({
    int * v3884 = v3874->cache_keys;
    int v3885 = v3884[1];
    bool v7241 = v3885 == ((int)((unsigned int)(v3878 + 36) >> 2));
    int v3926 = (v7241 ? ({
      int * v3886 = v3874->cache_vals;
      int v3887 = v3886[1];
      int * v3888 = v3874->cache_keys;
      int * v3889 = v3874->cache_keys;
      int v3890 = v3889[0];
      v3888[1] = v3890;
      int * v3892 = v3874->cache_vals;
      int * v3893 = v3874->cache_vals;
      int v3894 = v3893[0];
      v3892[1] = v3894;
      int * v3896 = v3874->cache_keys;
      int v7250 = (int)((unsigned int)(v3878 + 36) >> 2);
      v3896[0] = v7250;
      int * v3898 = v3874->cache_vals;
      v3898[0] = v3887;
      int v3900 = v3874->timer;
      int v7253 = v3900 + 1;
      v3874->timer = v7253;v3887;
    }) : ({
      int * v3903 = v3874->mem;
      int v7255 = (int)((unsigned int)(v3878 + 36) >> 2);
      int v3904 = v3903[v7255];
      int * v3905 = v3874->mem;
      int * v3906 = v3874->cache_keys;
      int v3907 = v3906[1];
      int * v3908 = v3874->cache_vals;
      int v3909 = v3908[1];
      v3905[v3907] = v3909;
      int * v3911 = v3874->cache_keys;
      int * v3912 = v3874->cache_keys;
      int v3913 = v3912[0];
      v3911[1] = v3913;
      int * v3915 = v3874->cache_vals;
      int * v3916 = v3874->cache_vals;
      int v3917 = v3916[0];
      v3915[1] = v3917;
      int * v3919 = v3874->cache_keys;
      v3919[0] = v7255;
      int * v3921 = v3874->cache_vals;
      v3921[0] = v3904;
      int v3923 = v3874->timer;
      int v7270 = v3923 + 100;
      v3874->timer = v7270;v3904;
    }));
    v3926;
  }));
  int * v3929 = v3874->regs;
  v3929[30] = v3928;
  struct StateT * v7229 = v3931(v3874);
  return v7229;
}

struct StateT * v8039(struct StateT * v8040) {
  int v8041 = v8040->timer;
  int v10639 = v8041 + 1;
  v8040->timer = v10639;int * v8043 = v8040->regs;
  int v8044 = v8043[9];
  int * v8045 = v8040->regs;
  int v10643 = v8044 << 9;
  v8045[9] = v10643;
  struct StateT * v10637 = v8047(v8040);
  return v10637;
}

struct StateT * v8819(struct StateT * v8820) {
  int v8821 = v8820->timer;
  int v9730 = v8821 + 1;
  v8820->timer = v9730;int * v8823 = v8820->regs;
  int v8824 = v8823[27];
  int * v8825 = v8820->regs;
  int v8826 = v8825[11];
  int * v8827 = v8820->regs;
  int v9736 = v8824 ^ v8826;
  v8827[27] = v9736;
  struct StateT * v9728 = v8829(v8820);
  return v9728;
}

struct StateT * v333(struct StateT * v334) {
  int v335 = v334->timer;
  int v13290 = v335 + 1;
  v334->timer = v13290;int * v337 = v334->regs;
  int v338 = v337[2];
  int * v339 = v334->regs;
  int v340 = v339[21];
  int * v341 = v334->cache_keys;
  int v342 = v341[0];
  bool v13297 = v342 == ((int)((unsigned int)(v338 + 68) >> 2));
  int v386 = (v13297 ? ({
    int * v343 = v334->cache_vals;
    v343[0] = v340;
    v340;
  }) : ({
    int * v346 = v334->cache_keys;
    int v347 = v346[1];
    bool v13302 = v347 == ((int)((unsigned int)(v338 + 68) >> 2));
    int v384 = (v13302 ? ({
      int * v348 = v334->cache_keys;
      int * v349 = v334->cache_keys;
      int v350 = v349[0];
      v348[1] = v350;
      int * v352 = v334->cache_vals;
      int * v353 = v334->cache_vals;
      int v354 = v353[0];
      v352[1] = v354;
      int * v356 = v334->cache_keys;
      int v13310 = (int)((unsigned int)(v338 + 68) >> 2);
      v356[0] = v13310;
      int * v358 = v334->cache_vals;
      v358[0] = v340;
      int v360 = v334->timer;
      int v13313 = v360 + 1;
      v334->timer = v13313;v340;
    }) : ({
      int * v363 = v334->mem;
      int * v364 = v334->cache_keys;
      int v365 = v364[1];
      int * v366 = v334->cache_vals;
      int v367 = v366[1];
      v363[v365] = v367;
      int * v369 = v334->cache_keys;
      int * v370 = v334->cache_keys;
      int v371 = v370[0];
      v369[1] = v371;
      int * v373 = v334->cache_vals;
      int * v374 = v334->cache_vals;
      int v375 = v374[0];
      v373[1] = v375;
      int * v377 = v334->cache_keys;
      int v13326 = (int)((unsigned int)(v338 + 68) >> 2);
      v377[0] = v13326;
      int * v379 = v334->cache_vals;
      v379[0] = v340;
      int v381 = v334->timer;
      int v13329 = v381 + 100;
      v334->timer = v13329;v340;
    }));
    v384;
  }));
  struct StateT * v13288 = v387(v334);
  return v13288;
}

struct StateT * v7829(struct StateT * v7830) {
  int v7831 = v7830->timer;
  int v10881 = v7831 + 1;
  v7830->timer = v10881;int * v7833 = v7830->regs;
  int v7834 = v7833[20];
  int * v7835 = v7830->regs;
  int v10885 = v7834 << 7;
  v7835[20] = v10885;
  struct StateT * v10879 = v7837(v7830);
  return v10879;
}

struct StateT * v8665(struct StateT * v8666) {
  int v8667 = v8666->timer;
  int v9909 = v8667 + 1;
  v8666->timer = v9909;int * v8669 = v8666->regs;
  int v8670 = v8669[9];
  int * v8671 = v8666->regs;
  int v8672 = v8671[6];
  int * v8673 = v8666->regs;
  int v9916 = v8670 ^ v8672;
  v8673[16] = v9916;
  struct StateT * v9907 = v8675(v8666);
  return v9907;
}

struct StateT * v949(struct StateT * v950) {
  int v951 = v950->timer;
  int v12772 = v951 + 1;
  v950->timer = v12772;int * v953 = v950->regs;
  int v954 = v953[12];
  int * v955 = v950->cache_keys;
  int v956 = v955[0];
  bool v12777 = v956 == ((int)((unsigned int)(v954 + 16) >> 2));
  int v1004 = (v12777 ? ({
    int * v957 = v950->cache_vals;
    int v958 = v957[0];
    v958;
  }) : ({
    int * v960 = v950->cache_keys;
    int v961 = v960[1];
    bool v12782 = v961 == ((int)((unsigned int)(v954 + 16) >> 2));
    int v1002 = (v12782 ? ({
      int * v962 = v950->cache_vals;
      int v963 = v962[1];
      int * v964 = v950->cache_keys;
      int * v965 = v950->cache_keys;
      int v966 = v965[0];
      v964[1] = v966;
      int * v968 = v950->cache_vals;
      int * v969 = v950->cache_vals;
      int v970 = v969[0];
      v968[1] = v970;
      int * v972 = v950->cache_keys;
      int v12791 = (int)((unsigned int)(v954 + 16) >> 2);
      v972[0] = v12791;
      int * v974 = v950->cache_vals;
      v974[0] = v963;
      int v976 = v950->timer;
      int v12794 = v976 + 1;
      v950->timer = v12794;v963;
    }) : ({
      int * v979 = v950->mem;
      int v12796 = (int)((unsigned int)(v954 + 16) >> 2);
      int v980 = v979[v12796];
      int * v981 = v950->mem;
      int * v982 = v950->cache_keys;
      int v983 = v982[1];
      int * v984 = v950->cache_vals;
      int v985 = v984[1];
      v981[v983] = v985;
      int * v987 = v950->cache_keys;
      int * v988 = v950->cache_keys;
      int v989 = v988[0];
      v987[1] = v989;
      int * v991 = v950->cache_vals;
      int * v992 = v950->cache_vals;
      int v993 = v992[0];
      v991[1] = v993;
      int * v995 = v950->cache_keys;
      v995[0] = v12796;
      int * v997 = v950->cache_vals;
      v997[0] = v980;
      int v999 = v950->timer;
      int v12811 = v999 + 100;
      v950->timer = v12811;v980;
    }));
    v1002;
  }));
  int * v1005 = v950->regs;
  v1005[17] = v1004;
  struct StateT * v12770 = v1007(v950);
  return v12770;
}

struct StateT * v8925(struct StateT * v8926) {
  int v8927 = v8926->timer;
  int v9609 = v8927 + 1;
  v8926->timer = v9609;int * v8929 = v8926->regs;
  int v8930 = v8929[15];
  int * v8931 = v8926->regs;
  int v9614 = (int)((unsigned int)v8930 >> 19);
  v8931[9] = v9614;
  struct StateT * v9607 = v8933(v8926);
  return v9607;
}

struct StateT * v1447(struct StateT * v1448) {
  int v1449 = v1448->timer;
  int v12382 = v1449 + 1;
  v1448->timer = v12382;int * v1451 = v1448->regs;
  int v1452 = v1451[14];
  int * v1453 = v1448->regs;
  int v12387 = v1452 + -718;
  v1453[19] = v12387;
  struct StateT * v12380 = v1455(v1448);
  return v12380;
}

struct StateT * v8083(struct StateT * v8084) {
  int v8085 = v8084->timer;
  int v10587 = v8085 + 1;
  v8084->timer = v10587;int * v8087 = v8084->regs;
  int v8088 = v8087[26];
  int * v8089 = v8084->regs;
  int v8090 = v8089[15];
  int * v8091 = v8084->regs;
  int v10593 = v8088 ^ v8090;
  v8091[26] = v10593;
  struct StateT * v10585 = v8093(v8084);
  return v10585;
}

struct StateT * v8879(struct StateT * v8880) {
  int v8881 = v8880->timer;
  int v9661 = v8881 + 1;
  v8880->timer = v9661;int * v8883 = v8880->regs;
  int v8884 = v8883[26];
  int * v8885 = v8880->regs;
  int v8886 = v8885[17];
  int * v8887 = v8880->regs;
  int v9668 = v8884 + v8886;
  v8887[6] = v9668;
  struct StateT * v9659 = v8889(v8880);
  return v9659;
}

struct StateT * v8809(struct StateT * v8810) {
  int v8811 = v8810->timer;
  int v9741 = v8811 + 1;
  v8810->timer = v9741;int * v8813 = v8810->regs;
  int v8814 = v8813[8];
  int * v8815 = v8810->regs;
  int v8816 = v8815[9];
  int * v8817 = v8810->regs;
  int v9747 = v8814 | v8816;
  v8817[8] = v9747;
  struct StateT * v9739 = v8819(v8810);
  return v9739;
}

struct StateT * v1123(struct StateT * v1124) {
  int v1125 = v1124->timer;
  int v12628 = v1125 + 1;
  v1124->timer = v12628;int * v1127 = v1124->regs;
  int v1128 = v1127[12];
  int * v1129 = v1124->cache_keys;
  int v1130 = v1129[0];
  bool v12633 = v1130 == ((int)((unsigned int)(v1128 + 28) >> 2));
  int v1178 = (v12633 ? ({
    int * v1131 = v1124->cache_vals;
    int v1132 = v1131[0];
    v1132;
  }) : ({
    int * v1134 = v1124->cache_keys;
    int v1135 = v1134[1];
    bool v12638 = v1135 == ((int)((unsigned int)(v1128 + 28) >> 2));
    int v1176 = (v12638 ? ({
      int * v1136 = v1124->cache_vals;
      int v1137 = v1136[1];
      int * v1138 = v1124->cache_keys;
      int * v1139 = v1124->cache_keys;
      int v1140 = v1139[0];
      v1138[1] = v1140;
      int * v1142 = v1124->cache_vals;
      int * v1143 = v1124->cache_vals;
      int v1144 = v1143[0];
      v1142[1] = v1144;
      int * v1146 = v1124->cache_keys;
      int v12647 = (int)((unsigned int)(v1128 + 28) >> 2);
      v1146[0] = v12647;
      int * v1148 = v1124->cache_vals;
      v1148[0] = v1137;
      int v1150 = v1124->timer;
      int v12650 = v1150 + 1;
      v1124->timer = v12650;v1137;
    }) : ({
      int * v1153 = v1124->mem;
      int v12652 = (int)((unsigned int)(v1128 + 28) >> 2);
      int v1154 = v1153[v12652];
      int * v1155 = v1124->mem;
      int * v1156 = v1124->cache_keys;
      int v1157 = v1156[1];
      int * v1158 = v1124->cache_vals;
      int v1159 = v1158[1];
      v1155[v1157] = v1159;
      int * v1161 = v1124->cache_keys;
      int * v1162 = v1124->cache_keys;
      int v1163 = v1162[0];
      v1161[1] = v1163;
      int * v1165 = v1124->cache_vals;
      int * v1166 = v1124->cache_vals;
      int v1167 = v1166[0];
      v1165[1] = v1167;
      int * v1169 = v1124->cache_keys;
      v1169[0] = v12652;
      int * v1171 = v1124->cache_vals;
      v1171[0] = v1154;
      int v1173 = v1124->timer;
      int v12667 = v1173 + 100;
      v1124->timer = v12667;v1154;
    }));
    v1176;
  }));
  int * v1179 = v1124->regs;
  v1179[1] = v1178;
  struct StateT * v12626 = v1181(v1124);
  return v12626;
}

struct StateT * v1419(struct StateT * v1420) {
  int v1421 = v1420->timer;
  int v12420 = v1421 + 1;
  v1420->timer = v12420;int * v1423 = v1420->regs;
  v1423[13] = 857759744;
  struct StateT * v12418 = v1425(v1420);
  return v12418;
}

struct StateT * v8941(struct StateT * v8942) {
  int v8943 = v8942->timer;
  int v9589 = v8943 + 1;
  v8942->timer = v9589;int * v8945 = v8942->regs;
  int v8946 = v8945[15];
  int * v8947 = v8942->regs;
  int v8948 = v8947[9];
  int * v8949 = v8942->regs;
  int v9595 = v8946 | v8948;
  v8949[15] = v9595;
  struct StateT * v9587 = v8951(v8942);
  return v9587;
}

struct StateT * v225(struct StateT * v226) {
  int v227 = v226->timer;
  int v13380 = v227 + 1;
  v226->timer = v13380;int * v229 = v226->regs;
  int v230 = v229[2];
  int * v231 = v226->regs;
  int v232 = v231[19];
  int * v233 = v226->cache_keys;
  int v234 = v233[0];
  bool v13387 = v234 == ((int)((unsigned int)(v230 + 76) >> 2));
  int v278 = (v13387 ? ({
    int * v235 = v226->cache_vals;
    v235[0] = v232;
    v232;
  }) : ({
    int * v238 = v226->cache_keys;
    int v239 = v238[1];
    bool v13392 = v239 == ((int)((unsigned int)(v230 + 76) >> 2));
    int v276 = (v13392 ? ({
      int * v240 = v226->cache_keys;
      int * v241 = v226->cache_keys;
      int v242 = v241[0];
      v240[1] = v242;
      int * v244 = v226->cache_vals;
      int * v245 = v226->cache_vals;
      int v246 = v245[0];
      v244[1] = v246;
      int * v248 = v226->cache_keys;
      int v13400 = (int)((unsigned int)(v230 + 76) >> 2);
      v248[0] = v13400;
      int * v250 = v226->cache_vals;
      v250[0] = v232;
      int v252 = v226->timer;
      int v13403 = v252 + 1;
      v226->timer = v13403;v232;
    }) : ({
      int * v255 = v226->mem;
      int * v256 = v226->cache_keys;
      int v257 = v256[1];
      int * v258 = v226->cache_vals;
      int v259 = v258[1];
      v255[v257] = v259;
      int * v261 = v226->cache_keys;
      int * v262 = v226->cache_keys;
      int v263 = v262[0];
      v261[1] = v263;
      int * v265 = v226->cache_vals;
      int * v266 = v226->cache_vals;
      int v267 = v266[0];
      v265[1] = v267;
      int * v269 = v226->cache_keys;
      int v13416 = (int)((unsigned int)(v230 + 76) >> 2);
      v269[0] = v13416;
      int * v271 = v226->cache_vals;
      v271[0] = v232;
      int v273 = v226->timer;
      int v13419 = v273 + 100;
      v226->timer = v13419;v232;
    }));
    v276;
  }));
  struct StateT * v13378 = v279(v226);
  return v13378;
}

struct StateT * v3517(struct StateT * v3518) {
  int v3519 = v3518->timer;
  int v7582 = v3519 + 1;
  v3518->timer = v7582;int * v3521 = v3518->regs;
  int v3522 = v3521[5];
  int * v3523 = v3518->regs;
  int v3524 = v3523[7];
  int * v3525 = v3518->regs;
  int v7588 = v3522 + v3524;
  v3525[5] = v7588;
  struct StateT * v7580 = v3527(v3518);
  return v7580;
}

struct StateT * v1691(struct StateT * v1692) {
  int v1693 = v1692->timer;
  int v12133 = v1693 + 1;
  v1692->timer = v12133;int * v1695 = v1692->regs;
  int v1696 = v1695[2];
  int * v1697 = v1692->regs;
  int v1698 = v1697[24];
  int * v1699 = v1692->cache_keys;
  int v1700 = v1699[0];
  bool v12140 = v1700 == ((int)((unsigned int)(v1696 + 36) >> 2));
  int v1744 = (v12140 ? ({
    int * v1701 = v1692->cache_vals;
    v1701[0] = v1698;
    v1698;
  }) : ({
    int * v1704 = v1692->cache_keys;
    int v1705 = v1704[1];
    bool v12145 = v1705 == ((int)((unsigned int)(v1696 + 36) >> 2));
    int v1742 = (v12145 ? ({
      int * v1706 = v1692->cache_keys;
      int * v1707 = v1692->cache_keys;
      int v1708 = v1707[0];
      v1706[1] = v1708;
      int * v1710 = v1692->cache_vals;
      int * v1711 = v1692->cache_vals;
      int v1712 = v1711[0];
      v1710[1] = v1712;
      int * v1714 = v1692->cache_keys;
      int v12153 = (int)((unsigned int)(v1696 + 36) >> 2);
      v1714[0] = v12153;
      int * v1716 = v1692->cache_vals;
      v1716[0] = v1698;
      int v1718 = v1692->timer;
      int v12156 = v1718 + 1;
      v1692->timer = v12156;v1698;
    }) : ({
      int * v1721 = v1692->mem;
      int * v1722 = v1692->cache_keys;
      int v1723 = v1722[1];
      int * v1724 = v1692->cache_vals;
      int v1725 = v1724[1];
      v1721[v1723] = v1725;
      int * v1727 = v1692->cache_keys;
      int * v1728 = v1692->cache_keys;
      int v1729 = v1728[0];
      v1727[1] = v1729;
      int * v1731 = v1692->cache_vals;
      int * v1732 = v1692->cache_vals;
      int v1733 = v1732[0];
      v1731[1] = v1733;
      int * v1735 = v1692->cache_keys;
      int v12169 = (int)((unsigned int)(v1696 + 36) >> 2);
      v1735[0] = v12169;
      int * v1737 = v1692->cache_vals;
      v1737[0] = v1698;
      int v1739 = v1692->timer;
      int v12172 = v1739 + 100;
      v1692->timer = v12172;v1698;
    }));
    v1742;
  }));
  struct StateT * v12131 = v1745(v1692);
  return v12131;
}

struct StateT * v7949(struct StateT * v7950) {
  int v7951 = v7950->timer;
  int v10742 = v7951 + 1;
  v7950->timer = v10742;int * v7953 = v7950->regs;
  int v7954 = v7953[13];
  int * v7955 = v7950->regs;
  int v7956 = v7955[11];
  int * v7957 = v7950->regs;
  int v10749 = v7954 + v7956;
  v7957[8] = v10749;
  struct StateT * v10740 = v7959(v7950);
  return v10740;
}

struct StateT * v5705(struct StateT * v5706) {
  int v5707 = v5706->timer;
  int v5721 = v5707 + 1;
  v5706->timer = v5721;int * v5709 = v5706->regs;
  int v5710 = v5709[2];
  int * v5711 = v5706->regs;
  int v5725 = v5710 + 96;
  v5711[2] = v5725;
  struct StateT * v5719 = v5713(v5706);
  return v5719;
}

struct StateT * v717(struct StateT * v718) {
  int v719 = v718->timer;
  int v12964 = v719 + 1;
  v718->timer = v12964;int * v721 = v718->regs;
  int v722 = v721[12];
  int * v723 = v718->cache_keys;
  int v724 = v723[0];
  bool v12969 = v724 == ((int)((unsigned int)v722 >> 2));
  int v772 = (v12969 ? ({
    int * v725 = v718->cache_vals;
    int v726 = v725[0];
    v726;
  }) : ({
    int * v728 = v718->cache_keys;
    int v729 = v728[1];
    bool v12974 = v729 == ((int)((unsigned int)v722 >> 2));
    int v770 = (v12974 ? ({
      int * v730 = v718->cache_vals;
      int v731 = v730[1];
      int * v732 = v718->cache_keys;
      int * v733 = v718->cache_keys;
      int v734 = v733[0];
      v732[1] = v734;
      int * v736 = v718->cache_vals;
      int * v737 = v718->cache_vals;
      int v738 = v737[0];
      v736[1] = v738;
      int * v740 = v718->cache_keys;
      int v12983 = (int)((unsigned int)v722 >> 2);
      v740[0] = v12983;
      int * v742 = v718->cache_vals;
      v742[0] = v731;
      int v744 = v718->timer;
      int v12986 = v744 + 1;
      v718->timer = v12986;v731;
    }) : ({
      int * v747 = v718->mem;
      int v12988 = (int)((unsigned int)v722 >> 2);
      int v748 = v747[v12988];
      int * v749 = v718->mem;
      int * v750 = v718->cache_keys;
      int v751 = v750[1];
      int * v752 = v718->cache_vals;
      int v753 = v752[1];
      v749[v751] = v753;
      int * v755 = v718->cache_keys;
      int * v756 = v718->cache_keys;
      int v757 = v756[0];
      v755[1] = v757;
      int * v759 = v718->cache_vals;
      int * v760 = v718->cache_vals;
      int v761 = v760[0];
      v759[1] = v761;
      int * v763 = v718->cache_keys;
      v763[0] = v12988;
      int * v765 = v718->cache_vals;
      v765[0] = v748;
      int v767 = v718->timer;
      int v13003 = v767 + 100;
      v718->timer = v13003;v748;
    }));
    v770;
  }));
  int * v773 = v718->regs;
  v773[29] = v772;
  struct StateT * v12962 = v775(v718);
  return v12962;
}

struct StateT * v4077(struct StateT * v4078) {
  int v4079 = v4078->timer;
  int v7073 = v4079 + 1;
  v4078->timer = v7073;int * v4081 = v4078->regs;
  int v4082 = v4081[22];
  int * v4083 = v4078->regs;
  int v4084 = v4083[30];
  int * v4085 = v4078->regs;
  int v7079 = v4082 + v4084;
  v4085[30] = v7079;
  struct StateT * v7071 = v4087(v4078);
  return v7071;
}

struct StateT * v8977(struct StateT * v8978) {
  int v8979 = v8978->timer;
  int v9549 = v8979 + 1;
  v8978->timer = v9549;int * v8981 = v8978->regs;
  int v8982 = v8981[8];
  int * v8983 = v8978->regs;
  int v9554 = (int)((unsigned int)v8982 >> 19);
  v8983[9] = v9554;
  struct StateT * v9547 = v8985(v8978);
  return v9547;
}

struct StateT * v775(struct StateT * v776) {
  int v777 = v776->timer;
  int v12916 = v777 + 1;
  v776->timer = v12916;int * v779 = v776->regs;
  int v780 = v779[12];
  int * v781 = v776->cache_keys;
  int v782 = v781[0];
  bool v12921 = v782 == ((int)((unsigned int)(v780 + 4) >> 2));
  int v830 = (v12921 ? ({
    int * v783 = v776->cache_vals;
    int v784 = v783[0];
    v784;
  }) : ({
    int * v786 = v776->cache_keys;
    int v787 = v786[1];
    bool v12926 = v787 == ((int)((unsigned int)(v780 + 4) >> 2));
    int v828 = (v12926 ? ({
      int * v788 = v776->cache_vals;
      int v789 = v788[1];
      int * v790 = v776->cache_keys;
      int * v791 = v776->cache_keys;
      int v792 = v791[0];
      v790[1] = v792;
      int * v794 = v776->cache_vals;
      int * v795 = v776->cache_vals;
      int v796 = v795[0];
      v794[1] = v796;
      int * v798 = v776->cache_keys;
      int v12935 = (int)((unsigned int)(v780 + 4) >> 2);
      v798[0] = v12935;
      int * v800 = v776->cache_vals;
      v800[0] = v789;
      int v802 = v776->timer;
      int v12938 = v802 + 1;
      v776->timer = v12938;v789;
    }) : ({
      int * v805 = v776->mem;
      int v12940 = (int)((unsigned int)(v780 + 4) >> 2);
      int v806 = v805[v12940];
      int * v807 = v776->mem;
      int * v808 = v776->cache_keys;
      int v809 = v808[1];
      int * v810 = v776->cache_vals;
      int v811 = v810[1];
      v807[v809] = v811;
      int * v813 = v776->cache_keys;
      int * v814 = v776->cache_keys;
      int v815 = v814[0];
      v813[1] = v815;
      int * v817 = v776->cache_vals;
      int * v818 = v776->cache_vals;
      int v819 = v818[0];
      v817[1] = v819;
      int * v821 = v776->cache_keys;
      v821[0] = v12940;
      int * v823 = v776->cache_vals;
      v823[0] = v806;
      int v825 = v776->timer;
      int v12955 = v825 + 100;
      v776->timer = v12955;v806;
    }));
    v828;
  }));
  int * v831 = v776->regs;
  v831[28] = v830;
  struct StateT * v12914 = v833(v776);
  return v12914;
}

struct StateT * v7979(struct StateT * v7980) {
  int v7981 = v7980->timer;
  int v10708 = v7981 + 1;
  v7980->timer = v10708;int * v7983 = v7980->regs;
  int v7984 = v7983[15];
  int * v7985 = v7980->regs;
  int v10713 = (int)((unsigned int)v7984 >> 23);
  v7985[20] = v10713;
  struct StateT * v10706 = v7987(v7980);
  return v10706;
}

struct StateT * v4015(struct StateT * v4016) {
  int v4017 = v4016->timer;
  int v7144 = v4017 + 1;
  v4016->timer = v7144;int * v4019 = v4016->regs;
  int v4020 = v4019[15];
  int * v4021 = v4016->regs;
  int v7148 = v4020 + -1947;
  v4021[15] = v7148;
  struct StateT * v7142 = v4023(v4016);
  return v7142;
}

struct StateT * v8599(struct StateT * v8600) {
  int v8601 = v8600->timer;
  int v9987 = v8601 + 1;
  v8600->timer = v9987;int * v8603 = v8600->regs;
  int v8604 = v8603[16];
  int * v8605 = v8600->regs;
  int v8606 = v8605[5];
  int * v8607 = v8600->regs;
  int v9993 = v8604 | v8606;
  v8607[16] = v9993;
  struct StateT * v9985 = v8609(v8600);
  return v9985;
}

struct StateT * v3805(struct StateT * v3806) {
  int v3807 = v3806->timer;
  int v7290 = v3807 + 1;
  v3806->timer = v7290;int * v3809 = v3806->regs;
  int v3810 = v3809[2];
  int * v3811 = v3806->cache_keys;
  int v3812 = v3811[0];
  bool v7295 = v3812 == ((int)((unsigned int)(v3810 + 32) >> 2));
  int v3860 = (v7295 ? ({
    int * v3813 = v3806->cache_vals;
    int v3814 = v3813[0];
    v3814;
  }) : ({
    int * v3816 = v3806->cache_keys;
    int v3817 = v3816[1];
    bool v7300 = v3817 == ((int)((unsigned int)(v3810 + 32) >> 2));
    int v3858 = (v7300 ? ({
      int * v3818 = v3806->cache_vals;
      int v3819 = v3818[1];
      int * v3820 = v3806->cache_keys;
      int * v3821 = v3806->cache_keys;
      int v3822 = v3821[0];
      v3820[1] = v3822;
      int * v3824 = v3806->cache_vals;
      int * v3825 = v3806->cache_vals;
      int v3826 = v3825[0];
      v3824[1] = v3826;
      int * v3828 = v3806->cache_keys;
      int v7309 = (int)((unsigned int)(v3810 + 32) >> 2);
      v3828[0] = v7309;
      int * v3830 = v3806->cache_vals;
      v3830[0] = v3819;
      int v3832 = v3806->timer;
      int v7312 = v3832 + 1;
      v3806->timer = v7312;v3819;
    }) : ({
      int * v3835 = v3806->mem;
      int v7314 = (int)((unsigned int)(v3810 + 32) >> 2);
      int v3836 = v3835[v7314];
      int * v3837 = v3806->mem;
      int * v3838 = v3806->cache_keys;
      int v3839 = v3838[1];
      int * v3840 = v3806->cache_vals;
      int v3841 = v3840[1];
      v3837[v3839] = v3841;
      int * v3843 = v3806->cache_keys;
      int * v3844 = v3806->cache_keys;
      int v3845 = v3844[0];
      v3843[1] = v3845;
      int * v3847 = v3806->cache_vals;
      int * v3848 = v3806->cache_vals;
      int v3849 = v3848[0];
      v3847[1] = v3849;
      int * v3851 = v3806->cache_keys;
      v3851[0] = v7314;
      int * v3853 = v3806->cache_vals;
      v3853[0] = v3836;
      int v3855 = v3806->timer;
      int v7329 = v3855 + 100;
      v3806->timer = v7329;v3836;
    }));
    v3858;
  }));
  int * v3861 = v3806->regs;
  v3861[30] = v3860;
  struct StateT * v7288 = v3863(v3806);
  return v7288;
}

struct StateT * v9161(struct StateT * v9162) {
  int v9163 = v9162->timer;
  int v9337 = v9163 + 1;
  v9162->timer = v9337;int * v9165 = v9162->regs;
  int v9166 = v9165[8];
  int * v9167 = v9162->regs;
  int v9342 = (int)((unsigned int)v9166 >> 14);
  v9167[9] = v9342;
  struct StateT * v9335 = v9169(v9162);
  return v9335;
}

struct StateT * v9053(struct StateT * v9054) {
  int v9055 = v9054->timer;
  int v9461 = v9055 + 1;
  v9054->timer = v9461;int * v9057 = v9054->regs;
  int v9058 = v9057[12];
  int * v9059 = v9054->regs;
  int v9060 = v9059[25];
  int * v9061 = v9054->regs;
  int v9468 = v9058 + v9060;
  v9061[15] = v9468;
  struct StateT * v9459 = v9063(v9054);
  return v9459;
}

struct StateT * v8645(struct StateT * v8646) {
  int v8647 = v8646->timer;
  int v9933 = v8647 + 1;
  v8646->timer = v9933;int * v8649 = v8646->regs;
  int v8650 = v8649[18];
  int * v8651 = v8646->regs;
  int v8652 = v8651[11];
  int * v8653 = v8646->regs;
  int v9940 = v8650 ^ v8652;
  v8653[5] = v9940;
  struct StateT * v9931 = v8655(v8646);
  return v9931;
}

struct StateT * v5241(struct StateT * v5242) {
  int v5243 = v5242->timer;
  int v6066 = v5243 + 1;
  v5242->timer = v6066;int * v5245 = v5242->regs;
  int v5246 = v5245[2];
  int * v5247 = v5242->cache_keys;
  int v5248 = v5247[0];
  bool v6071 = v5248 == ((int)((unsigned int)(v5246 + 72) >> 2));
  int v5296 = (v6071 ? ({
    int * v5249 = v5242->cache_vals;
    int v5250 = v5249[0];
    v5250;
  }) : ({
    int * v5252 = v5242->cache_keys;
    int v5253 = v5252[1];
    bool v6076 = v5253 == ((int)((unsigned int)(v5246 + 72) >> 2));
    int v5294 = (v6076 ? ({
      int * v5254 = v5242->cache_vals;
      int v5255 = v5254[1];
      int * v5256 = v5242->cache_keys;
      int * v5257 = v5242->cache_keys;
      int v5258 = v5257[0];
      v5256[1] = v5258;
      int * v5260 = v5242->cache_vals;
      int * v5261 = v5242->cache_vals;
      int v5262 = v5261[0];
      v5260[1] = v5262;
      int * v5264 = v5242->cache_keys;
      int v6085 = (int)((unsigned int)(v5246 + 72) >> 2);
      v5264[0] = v6085;
      int * v5266 = v5242->cache_vals;
      v5266[0] = v5255;
      int v5268 = v5242->timer;
      int v6088 = v5268 + 1;
      v5242->timer = v6088;v5255;
    }) : ({
      int * v5271 = v5242->mem;
      int v6090 = (int)((unsigned int)(v5246 + 72) >> 2);
      int v5272 = v5271[v6090];
      int * v5273 = v5242->mem;
      int * v5274 = v5242->cache_keys;
      int v5275 = v5274[1];
      int * v5276 = v5242->cache_vals;
      int v5277 = v5276[1];
      v5273[v5275] = v5277;
      int * v5279 = v5242->cache_keys;
      int * v5280 = v5242->cache_keys;
      int v5281 = v5280[0];
      v5279[1] = v5281;
      int * v5283 = v5242->cache_vals;
      int * v5284 = v5242->cache_vals;
      int v5285 = v5284[0];
      v5283[1] = v5285;
      int * v5287 = v5242->cache_keys;
      v5287[0] = v6090;
      int * v5289 = v5242->cache_vals;
      v5289[0] = v5272;
      int v5291 = v5242->timer;
      int v6105 = v5291 + 100;
      v5242->timer = v6105;v5272;
    }));
    v5294;
  }));
  int * v5297 = v5242->regs;
  v5297[20] = v5296;
  struct StateT * v6064 = v5299(v5242);
  return v6064;
}

struct StateT * v9003(struct StateT * v9004) {
  int v9005 = v9004->timer;
  int v9518 = v9005 + 1;
  v9004->timer = v9518;int * v9007 = v9004->regs;
  int v9008 = v9007[14];
  int * v9009 = v9004->regs;
  int v9010 = v9009[11];
  int * v9011 = v9004->regs;
  int v9524 = v9008 ^ v9010;
  v9011[14] = v9524;
  struct StateT * v9516 = v9013(v9004);
  return v9516;
}

struct StateT * v4141(struct StateT * v4142) {
  int v4143 = v4142->timer;
  int v6983 = v4143 + 1;
  v4142->timer = v6983;int * v4145 = v4142->regs;
  int v4146 = v4145[10];
  int * v4147 = v4142->regs;
  int v4148 = v4147[29];
  int * v4149 = v4142->cache_keys;
  int v4150 = v4149[0];
  bool v6990 = v4150 == ((int)((unsigned int)(v4146 + 4) >> 2));
  int v4194 = (v6990 ? ({
    int * v4151 = v4142->cache_vals;
    v4151[0] = v4148;
    v4148;
  }) : ({
    int * v4154 = v4142->cache_keys;
    int v4155 = v4154[1];
    bool v6995 = v4155 == ((int)((unsigned int)(v4146 + 4) >> 2));
    int v4192 = (v6995 ? ({
      int * v4156 = v4142->cache_keys;
      int * v4157 = v4142->cache_keys;
      int v4158 = v4157[0];
      v4156[1] = v4158;
      int * v4160 = v4142->cache_vals;
      int * v4161 = v4142->cache_vals;
      int v4162 = v4161[0];
      v4160[1] = v4162;
      int * v4164 = v4142->cache_keys;
      int v7003 = (int)((unsigned int)(v4146 + 4) >> 2);
      v4164[0] = v7003;
      int * v4166 = v4142->cache_vals;
      v4166[0] = v4148;
      int v4168 = v4142->timer;
      int v7006 = v4168 + 1;
      v4142->timer = v7006;v4148;
    }) : ({
      int * v4171 = v4142->mem;
      int * v4172 = v4142->cache_keys;
      int v4173 = v4172[1];
      int * v4174 = v4142->cache_vals;
      int v4175 = v4174[1];
      v4171[v4173] = v4175;
      int * v4177 = v4142->cache_keys;
      int * v4178 = v4142->cache_keys;
      int v4179 = v4178[0];
      v4177[1] = v4179;
      int * v4181 = v4142->cache_vals;
      int * v4182 = v4142->cache_vals;
      int v4183 = v4182[0];
      v4181[1] = v4183;
      int * v4185 = v4142->cache_keys;
      int v7019 = (int)((unsigned int)(v4146 + 4) >> 2);
      v4185[0] = v7019;
      int * v4187 = v4142->cache_vals;
      v4187[0] = v4148;
      int v4189 = v4142->timer;
      int v7022 = v4189 + 100;
      v4142->timer = v7022;v4148;
    }));
    v4192;
  }));
  struct StateT * v6981 = v4195(v4142);
  return v6981;
}

struct StateT * v4023(struct StateT * v4024) {
  int v4025 = v4024->timer;
  int v7135 = v4025 + 1;
  v4024->timer = v7135;int * v4027 = v4024->regs;
  int v4028 = v4027[6];
  int * v4029 = v4024->regs;
  int v7139 = v4028 + 1134;
  v4029[6] = v7139;
  struct StateT * v7133 = v4031(v4024);
  return v7133;
}

struct StateT * v9023(struct StateT * v9024) {
  int v9025 = v9024->timer;
  int v9496 = v9025 + 1;
  v9024->timer = v9496;int * v9027 = v9024->regs;
  int v9028 = v9027[13];
  int * v9029 = v9024->regs;
  int v9030 = v9029[6];
  int * v9031 = v9024->regs;
  int v9502 = v9028 ^ v9030;
  v9031[13] = v9502;
  struct StateT * v9494 = v9033(v9024);
  return v9494;
}

struct StateT * v8163(struct StateT * v8164) {
  int v8165 = v8164->timer;
  int v10496 = v8165 + 1;
  v8164->timer = v10496;int * v8167 = v8164->regs;
  int v8168 = v8167[15];
  int * v8169 = v8164->regs;
  int v10501 = (int)((unsigned int)v8168 >> 19);
  v8169[20] = v10501;
  struct StateT * v10494 = v8171(v8164);
  return v10494;
}

struct StateT * v3585(struct StateT * v3586) {
  int v3587 = v3586->timer;
  int v7523 = v3587 + 1;
  v3586->timer = v7523;int * v3589 = v3586->regs;
  int v3590 = v3589[25];
  int * v3591 = v3586->regs;
  int v3592 = v3591[7];
  int * v3593 = v3586->regs;
  int v7529 = v3590 + v3592;
  v3593[25] = v7529;
  struct StateT * v7521 = v3595(v3586);
  return v7521;
}

struct StateT * v5589(struct StateT * v5590) {
  int v5591 = v5590->timer;
  int v5778 = v5591 + 1;
  v5590->timer = v5778;int * v5593 = v5590->regs;
  int v5594 = v5593[2];
  int * v5595 = v5590->cache_keys;
  int v5596 = v5595[0];
  bool v5783 = v5596 == ((int)((unsigned int)(v5594 + 48) >> 2));
  int v5644 = (v5783 ? ({
    int * v5597 = v5590->cache_vals;
    int v5598 = v5597[0];
    v5598;
  }) : ({
    int * v5600 = v5590->cache_keys;
    int v5601 = v5600[1];
    bool v5788 = v5601 == ((int)((unsigned int)(v5594 + 48) >> 2));
    int v5642 = (v5788 ? ({
      int * v5602 = v5590->cache_vals;
      int v5603 = v5602[1];
      int * v5604 = v5590->cache_keys;
      int * v5605 = v5590->cache_keys;
      int v5606 = v5605[0];
      v5604[1] = v5606;
      int * v5608 = v5590->cache_vals;
      int * v5609 = v5590->cache_vals;
      int v5610 = v5609[0];
      v5608[1] = v5610;
      int * v5612 = v5590->cache_keys;
      int v5797 = (int)((unsigned int)(v5594 + 48) >> 2);
      v5612[0] = v5797;
      int * v5614 = v5590->cache_vals;
      v5614[0] = v5603;
      int v5616 = v5590->timer;
      int v5800 = v5616 + 1;
      v5590->timer = v5800;v5603;
    }) : ({
      int * v5619 = v5590->mem;
      int v5802 = (int)((unsigned int)(v5594 + 48) >> 2);
      int v5620 = v5619[v5802];
      int * v5621 = v5590->mem;
      int * v5622 = v5590->cache_keys;
      int v5623 = v5622[1];
      int * v5624 = v5590->cache_vals;
      int v5625 = v5624[1];
      v5621[v5623] = v5625;
      int * v5627 = v5590->cache_keys;
      int * v5628 = v5590->cache_keys;
      int v5629 = v5628[0];
      v5627[1] = v5629;
      int * v5631 = v5590->cache_vals;
      int * v5632 = v5590->cache_vals;
      int v5633 = v5632[0];
      v5631[1] = v5633;
      int * v5635 = v5590->cache_keys;
      v5635[0] = v5802;
      int * v5637 = v5590->cache_vals;
      v5637[0] = v5620;
      int v5639 = v5590->timer;
      int v5817 = v5639 + 100;
      v5590->timer = v5817;v5620;
    }));
    v5642;
  }));
  int * v5645 = v5590->regs;
  v5645[26] = v5644;
  struct StateT * v5776 = v5647(v5590);
  return v5776;
}

struct StateT * v8143(struct StateT * v8144) {
  int v8145 = v8144->timer;
  int v10518 = v8145 + 1;
  v8144->timer = v10518;int * v8147 = v8144->regs;
  int v8148 = v8147[27];
  int * v8149 = v8144->regs;
  int v8150 = v8149[1];
  int * v8151 = v8144->regs;
  int v10525 = v8148 + v8150;
  v8151[9] = v10525;
  struct StateT * v10516 = v8153(v8144);
  return v10516;
}

struct StateT * v1939(struct StateT * v1940) {
  int v1941 = v1940->timer;
  int v11913 = v1941 + 1;
  v1940->timer = v11913;int * v1943 = v1940->regs;
  int v1944 = v1943[2];
  int * v1945 = v1940->regs;
  int v1946 = v1945[15];
  int * v1947 = v1940->cache_keys;
  int v1948 = v1947[0];
  bool v11920 = v1948 == ((int)((unsigned int)(v1944 + 24) >> 2));
  int v1992 = (v11920 ? ({
    int * v1949 = v1940->cache_vals;
    v1949[0] = v1946;
    v1946;
  }) : ({
    int * v1952 = v1940->cache_keys;
    int v1953 = v1952[1];
    bool v11925 = v1953 == ((int)((unsigned int)(v1944 + 24) >> 2));
    int v1990 = (v11925 ? ({
      int * v1954 = v1940->cache_keys;
      int * v1955 = v1940->cache_keys;
      int v1956 = v1955[0];
      v1954[1] = v1956;
      int * v1958 = v1940->cache_vals;
      int * v1959 = v1940->cache_vals;
      int v1960 = v1959[0];
      v1958[1] = v1960;
      int * v1962 = v1940->cache_keys;
      int v11933 = (int)((unsigned int)(v1944 + 24) >> 2);
      v1962[0] = v11933;
      int * v1964 = v1940->cache_vals;
      v1964[0] = v1946;
      int v1966 = v1940->timer;
      int v11936 = v1966 + 1;
      v1940->timer = v11936;v1946;
    }) : ({
      int * v1969 = v1940->mem;
      int * v1970 = v1940->cache_keys;
      int v1971 = v1970[1];
      int * v1972 = v1940->cache_vals;
      int v1973 = v1972[1];
      v1969[v1971] = v1973;
      int * v1975 = v1940->cache_keys;
      int * v1976 = v1940->cache_keys;
      int v1977 = v1976[0];
      v1975[1] = v1977;
      int * v1979 = v1940->cache_vals;
      int * v1980 = v1940->cache_vals;
      int v1981 = v1980[0];
      v1979[1] = v1981;
      int * v1983 = v1940->cache_keys;
      int v11949 = (int)((unsigned int)(v1944 + 24) >> 2);
      v1983[0] = v11949;
      int * v1985 = v1940->cache_vals;
      v1985[0] = v1946;
      int v1987 = v1940->timer;
      int v11952 = v1987 + 100;
      v1940->timer = v11952;v1946;
    }));
    v1990;
  }));
  struct StateT * v11911 = v1993(v1940);
  return v11911;
}

struct StateT * v8635(struct StateT * v8636) {
  int v8637 = v8636->timer;
  int v9945 = v8637 + 1;
  v8636->timer = v9945;int * v8639 = v8636->regs;
  int v8640 = v8639[23];
  int * v8641 = v8636->regs;
  int v8642 = v8641[15];
  int * v8643 = v8636->regs;
  int v9951 = v8640 ^ v8642;
  v8643[23] = v9951;
  struct StateT * v9943 = v8645(v8636);
  return v9943;
}

struct StateT * v8277(struct StateT * v8278) {
  int v8279 = v8278->timer;
  int v10362 = v8279 + 1;
  v8278->timer = v10362;int * v8281 = v8278->regs;
  int v8282 = v8281[23];
  int * v8283 = v8278->regs;
  int v8284 = v8283[8];
  int * v8285 = v8278->regs;
  int v10368 = v8282 ^ v8284;
  v8285[23] = v10368;
  struct StateT * v10360 = v8287(v8278);
  return v10360;
}

struct StateT * v8471(struct StateT * v8472) {
  int v8473 = v8472->timer;
  int v10136 = v8473 + 1;
  v8472->timer = v10136;int * v8475 = v8472->regs;
  int v8476 = v8475[19];
  int * v8477 = v8472->regs;
  int v8478 = v8477[17];
  int * v8479 = v8472->regs;
  int v10142 = v8476 ^ v8478;
  v8479[19] = v10142;
  struct StateT * v10134 = v8481(v8472);
  return v10134;
}

struct StateT * v8741(struct StateT * v8742) {
  int v8743 = v8742->timer;
  int v9821 = v8743 + 1;
  v8742->timer = v9821;int * v8745 = v8742->regs;
  int v8746 = v8745[15];
  int * v8747 = v8742->regs;
  int v9826 = (int)((unsigned int)v8746 >> 23);
  v8747[9] = v9826;
  struct StateT * v9819 = v8749(v8742);
  return v9819;
}

struct StateT * v8951(struct StateT * v8952) {
  int v8953 = v8952->timer;
  int v9579 = v8953 + 1;
  v8952->timer = v9579;int * v8955 = v8952->regs;
  int v8956 = v8955[6];
  int * v8957 = v8952->regs;
  int v9584 = (int)((unsigned int)v8956 >> 19);
  v8957[9] = v9584;
  struct StateT * v9577 = v8959(v8952);
  return v9577;
}

struct StateT * v7863(struct StateT * v7864) {
  int v7865 = v7864->timer;
  int v10840 = v7865 + 1;
  v7864->timer = v10840;int * v7867 = v7864->regs;
  int v7868 = v7867[18];
  int * v7869 = v7864->regs;
  int v7870 = v7869[20];
  int * v7871 = v7864->regs;
  int v10846 = v7868 | v7870;
  v7871[18] = v10846;
  struct StateT * v10838 = v7873(v7864);
  return v10838;
}

struct StateT * v8373(struct StateT * v8374) {
  int v8375 = v8374->timer;
  int v10250 = v8375 + 1;
  v8374->timer = v10250;int * v8377 = v8374->regs;
  int v8378 = v8377[16];
  int * v8379 = v8374->regs;
  int v10255 = (int)((unsigned int)v8378 >> 14);
  v8379[6] = v10255;
  struct StateT * v10248 = v8381(v8374);
  return v10248;
}

struct StateT * v8609(struct StateT * v8610) {
  int v8611 = v8610->timer;
  int v9977 = v8611 + 1;
  v8610->timer = v9977;int * v8613 = v8610->regs;
  int v8614 = v8613[17];
  int * v8615 = v8610->regs;
  int v9982 = (int)((unsigned int)v8614 >> 25);
  v8615[5] = v9982;
  struct StateT * v9975 = v8617(v8610);
  return v9975;
}

struct StateT * v7837(struct StateT * v7838) {
  int v7839 = v7838->timer;
  int v10870 = v7839 + 1;
  v7838->timer = v10870;int * v7841 = v7838->regs;
  int v7842 = v7841[20];
  int * v7843 = v7838->regs;
  int v7844 = v7843[9];
  int * v7845 = v7838->regs;
  int v10876 = v7842 | v7844;
  v7845[9] = v10876;
  struct StateT * v10868 = v7847(v7838);
  return v10868;
}

struct StateT * v8223(struct StateT * v8224) {
  int v8225 = v8224->timer;
  int v10427 = v8225 + 1;
  v8224->timer = v10427;int * v8227 = v8224->regs;
  int v8228 = v8227[9];
  int * v8229 = v8224->regs;
  int v10431 = v8228 << 13;
  v8229[9] = v10431;
  struct StateT * v10425 = v8231(v8224);
  return v10425;
}

struct StateT * v5415(struct StateT * v5416) {
  int v5417 = v5416->timer;
  int v5922 = v5417 + 1;
  v5416->timer = v5922;int * v5419 = v5416->regs;
  int v5420 = v5419[2];
  int * v5421 = v5416->cache_keys;
  int v5422 = v5421[0];
  bool v5927 = v5422 == ((int)((unsigned int)(v5420 + 60) >> 2));
  int v5470 = (v5927 ? ({
    int * v5423 = v5416->cache_vals;
    int v5424 = v5423[0];
    v5424;
  }) : ({
    int * v5426 = v5416->cache_keys;
    int v5427 = v5426[1];
    bool v5932 = v5427 == ((int)((unsigned int)(v5420 + 60) >> 2));
    int v5468 = (v5932 ? ({
      int * v5428 = v5416->cache_vals;
      int v5429 = v5428[1];
      int * v5430 = v5416->cache_keys;
      int * v5431 = v5416->cache_keys;
      int v5432 = v5431[0];
      v5430[1] = v5432;
      int * v5434 = v5416->cache_vals;
      int * v5435 = v5416->cache_vals;
      int v5436 = v5435[0];
      v5434[1] = v5436;
      int * v5438 = v5416->cache_keys;
      int v5941 = (int)((unsigned int)(v5420 + 60) >> 2);
      v5438[0] = v5941;
      int * v5440 = v5416->cache_vals;
      v5440[0] = v5429;
      int v5442 = v5416->timer;
      int v5944 = v5442 + 1;
      v5416->timer = v5944;v5429;
    }) : ({
      int * v5445 = v5416->mem;
      int v5946 = (int)((unsigned int)(v5420 + 60) >> 2);
      int v5446 = v5445[v5946];
      int * v5447 = v5416->mem;
      int * v5448 = v5416->cache_keys;
      int v5449 = v5448[1];
      int * v5450 = v5416->cache_vals;
      int v5451 = v5450[1];
      v5447[v5449] = v5451;
      int * v5453 = v5416->cache_keys;
      int * v5454 = v5416->cache_keys;
      int v5455 = v5454[0];
      v5453[1] = v5455;
      int * v5457 = v5416->cache_vals;
      int * v5458 = v5416->cache_vals;
      int v5459 = v5458[0];
      v5457[1] = v5459;
      int * v5461 = v5416->cache_keys;
      v5461[0] = v5946;
      int * v5463 = v5416->cache_vals;
      v5463[0] = v5446;
      int v5465 = v5416->timer;
      int v5961 = v5465 + 100;
      v5416->timer = v5961;v5446;
    }));
    v5468;
  }));
  int * v5471 = v5416->regs;
  v5471[23] = v5470;
  struct StateT * v5920 = v5473(v5416);
  return v5920;
}

struct StateT * v9227(struct StateT * v9228) {
  int v9229 = v9228->timer;
  int v9263 = v9229 + 1;
  v9228->timer = v9263;int * v9231 = v9228->regs;
  int v9232 = v9231[30];
  int * v9233 = v9228->regs;
  int v9267 = v9232 + 1;
  v9233[30] = v9267;
  struct StateT * v9261 = v9235(v9228);
  return v9261;
}

struct StateT * v7889(struct StateT * v7890) {
  int v7891 = v7890->timer;
  int v10810 = v7891 + 1;
  v7890->timer = v10810;int * v7893 = v7890->regs;
  int v7894 = v7893[8];
  int * v7895 = v7890->regs;
  int v7896 = v7895[20];
  int * v7897 = v7890->regs;
  int v10816 = v7894 | v7896;
  v7897[8] = v10816;
  struct StateT * v10808 = v7899(v7890);
  return v10808;
}

struct StateT * v8267(struct StateT * v8268) {
  int v8269 = v8268->timer;
  int v10373 = v8269 + 1;
  v8268->timer = v10373;int * v8271 = v8268->regs;
  int v8272 = v8271[16];
  int * v8273 = v8268->regs;
  int v8274 = v8273[15];
  int * v8275 = v8268->regs;
  int v10380 = v8272 ^ v8274;
  v8275[9] = v10380;
  struct StateT * v10371 = v8277(v8268);
  return v10371;
}

struct StateT * v4009(struct StateT * v4010) {
  int v4011 = v4010->timer;
  int v7153 = v4011 + 1;
  v4010->timer = v7153;int * v4013 = v4010->regs;
  v4013[30] = 1797283840;
  struct StateT * v7151 = v4015(v4010);
  return v7151;
}

struct StateT * v8557(struct StateT * v8558) {
  int v8559 = v8558->timer;
  int v10037 = v8559 + 1;
  v8558->timer = v10037;int * v8561 = v8558->regs;
  int v8562 = v8561[11];
  int * v8563 = v8558->regs;
  int v10042 = (int)((unsigned int)v8562 >> 25);
  v8563[5] = v10042;
  struct StateT * v10035 = v8565(v8558);
  return v10035;
}

struct StateT * v9143(struct StateT * v9144) {
  int v9145 = v9144->timer;
  int v9358 = v9145 + 1;
  v9144->timer = v9358;int * v9147 = v9144->regs;
  int v9148 = v9147[6];
  int * v9149 = v9144->regs;
  int v9362 = v9148 << 18;
  v9149[6] = v9362;
  struct StateT * v9356 = v9151(v9144);
  return v9356;
}

struct StateT * v8801(struct StateT * v8802) {
  int v8803 = v8802->timer;
  int v9752 = v8803 + 1;
  v8802->timer = v9752;int * v8805 = v8802->regs;
  int v8806 = v8805[8];
  int * v8807 = v8802->regs;
  int v9756 = v8806 << 9;
  v8807[8] = v9756;
  struct StateT * v9750 = v8809(v8802);
  return v9750;
}

struct StateT * v4789(struct StateT * v4790) {
  int v4791 = v4790->timer;
  int v6443 = v4791 + 1;
  v4790->timer = v6443;int * v4793 = v4790->regs;
  int v4794 = v4793[10];
  int * v4795 = v4790->regs;
  int v4796 = v4795[24];
  int * v4797 = v4790->cache_keys;
  int v4798 = v4797[0];
  bool v6450 = v4798 == ((int)((unsigned int)(v4794 + 52) >> 2));
  int v4842 = (v6450 ? ({
    int * v4799 = v4790->cache_vals;
    v4799[0] = v4796;
    v4796;
  }) : ({
    int * v4802 = v4790->cache_keys;
    int v4803 = v4802[1];
    bool v6455 = v4803 == ((int)((unsigned int)(v4794 + 52) >> 2));
    int v4840 = (v6455 ? ({
      int * v4804 = v4790->cache_keys;
      int * v4805 = v4790->cache_keys;
      int v4806 = v4805[0];
      v4804[1] = v4806;
      int * v4808 = v4790->cache_vals;
      int * v4809 = v4790->cache_vals;
      int v4810 = v4809[0];
      v4808[1] = v4810;
      int * v4812 = v4790->cache_keys;
      int v6463 = (int)((unsigned int)(v4794 + 52) >> 2);
      v4812[0] = v6463;
      int * v4814 = v4790->cache_vals;
      v4814[0] = v4796;
      int v4816 = v4790->timer;
      int v6466 = v4816 + 1;
      v4790->timer = v6466;v4796;
    }) : ({
      int * v4819 = v4790->mem;
      int * v4820 = v4790->cache_keys;
      int v4821 = v4820[1];
      int * v4822 = v4790->cache_vals;
      int v4823 = v4822[1];
      v4819[v4821] = v4823;
      int * v4825 = v4790->cache_keys;
      int * v4826 = v4790->cache_keys;
      int v4827 = v4826[0];
      v4825[1] = v4827;
      int * v4829 = v4790->cache_vals;
      int * v4830 = v4790->cache_vals;
      int v4831 = v4830[0];
      v4829[1] = v4831;
      int * v4833 = v4790->cache_keys;
      int v6479 = (int)((unsigned int)(v4794 + 52) >> 2);
      v4833[0] = v6479;
      int * v4835 = v4790->cache_vals;
      v4835[0] = v4796;
      int v4837 = v4790->timer;
      int v6482 = v4837 + 100;
      v4790->timer = v6482;v4796;
    }));
    v4840;
  }));
  struct StateT * v6441 = v4843(v4790);
  return v6441;
}

struct StateT * v5009(struct StateT * v5010) {
  int v5011 = v5010->timer;
  int v6258 = v5011 + 1;
  v5010->timer = v6258;int * v5013 = v5010->regs;
  int v5014 = v5013[2];
  int * v5015 = v5010->cache_keys;
  int v5016 = v5015[0];
  bool v6263 = v5016 == ((int)((unsigned int)(v5014 + 88) >> 2));
  int v5064 = (v6263 ? ({
    int * v5017 = v5010->cache_vals;
    int v5018 = v5017[0];
    v5018;
  }) : ({
    int * v5020 = v5010->cache_keys;
    int v5021 = v5020[1];
    bool v6268 = v5021 == ((int)((unsigned int)(v5014 + 88) >> 2));
    int v5062 = (v6268 ? ({
      int * v5022 = v5010->cache_vals;
      int v5023 = v5022[1];
      int * v5024 = v5010->cache_keys;
      int * v5025 = v5010->cache_keys;
      int v5026 = v5025[0];
      v5024[1] = v5026;
      int * v5028 = v5010->cache_vals;
      int * v5029 = v5010->cache_vals;
      int v5030 = v5029[0];
      v5028[1] = v5030;
      int * v5032 = v5010->cache_keys;
      int v6277 = (int)((unsigned int)(v5014 + 88) >> 2);
      v5032[0] = v6277;
      int * v5034 = v5010->cache_vals;
      v5034[0] = v5023;
      int v5036 = v5010->timer;
      int v6280 = v5036 + 1;
      v5010->timer = v6280;v5023;
    }) : ({
      int * v5039 = v5010->mem;
      int v6282 = (int)((unsigned int)(v5014 + 88) >> 2);
      int v5040 = v5039[v6282];
      int * v5041 = v5010->mem;
      int * v5042 = v5010->cache_keys;
      int v5043 = v5042[1];
      int * v5044 = v5010->cache_vals;
      int v5045 = v5044[1];
      v5041[v5043] = v5045;
      int * v5047 = v5010->cache_keys;
      int * v5048 = v5010->cache_keys;
      int v5049 = v5048[0];
      v5047[1] = v5049;
      int * v5051 = v5010->cache_vals;
      int * v5052 = v5010->cache_vals;
      int v5053 = v5052[0];
      v5051[1] = v5053;
      int * v5055 = v5010->cache_keys;
      v5055[0] = v6282;
      int * v5057 = v5010->cache_vals;
      v5057[0] = v5040;
      int v5059 = v5010->timer;
      int v6297 = v5059 + 100;
      v5010->timer = v6297;v5040;
    }));
    v5062;
  }));
  int * v5065 = v5010->regs;
  v5065[8] = v5064;
  struct StateT * v6256 = v5067(v5010);
  return v6256;
}

struct StateT * v8521(struct StateT * v8522) {
  int v8523 = v8522->timer;
  int v10077 = v8523 + 1;
  v8522->timer = v10077;int * v8525 = v8522->regs;
  int v8526 = v8525[22];
  int * v8527 = v8522->regs;
  int v8528 = v8527[1];
  int * v8529 = v8522->regs;
  int v10084 = v8526 + v8528;
  v8529[17] = v10084;
  struct StateT * v10075 = v8531(v8522);
  return v10075;
}

struct StateT * v8389(struct StateT * v8390) {
  int v8391 = v8390->timer;
  int v10230 = v8391 + 1;
  v8390->timer = v10230;int * v8393 = v8390->regs;
  int v8394 = v8393[16];
  int * v8395 = v8390->regs;
  int v8396 = v8395[6];
  int * v8397 = v8390->regs;
  int v10236 = v8394 | v8396;
  v8397[16] = v10236;
  struct StateT * v10228 = v8399(v8390);
  return v10228;
}

struct StateT * v8231(struct StateT * v8232) {
  int v8233 = v8232->timer;
  int v10416 = v8233 + 1;
  v8232->timer = v10416;int * v8235 = v8232->regs;
  int v8236 = v8235[9];
  int * v8237 = v8232->regs;
  int v8238 = v8237[20];
  int * v8239 = v8232->regs;
  int v10422 = v8236 | v8238;
  v8239[20] = v10422;
  struct StateT * v10414 = v8241(v8232);
  return v10414;
}

struct StateT * v8829(struct StateT * v8830) {
  int v8831 = v8830->timer;
  int v9719 = v8831 + 1;
  v8830->timer = v9719;int * v8833 = v8830->regs;
  int v8834 = v8833[25];
  int * v8835 = v8830->regs;
  int v8836 = v8835[15];
  int * v8837 = v8830->regs;
  int v9725 = v8834 ^ v8836;
  v8837[25] = v9725;
  struct StateT * v9717 = v8839(v8830);
  return v9717;
}

struct StateT * v4735(struct StateT * v4736) {
  int v4737 = v4736->timer;
  int v6488 = v4737 + 1;
  v4736->timer = v6488;int * v4739 = v4736->regs;
  int v4740 = v4739[10];
  int * v4741 = v4736->regs;
  int v4742 = v4741[16];
  int * v4743 = v4736->cache_keys;
  int v4744 = v4743[0];
  bool v6495 = v4744 == ((int)((unsigned int)(v4740 + 48) >> 2));
  int v4788 = (v6495 ? ({
    int * v4745 = v4736->cache_vals;
    v4745[0] = v4742;
    v4742;
  }) : ({
    int * v4748 = v4736->cache_keys;
    int v4749 = v4748[1];
    bool v6500 = v4749 == ((int)((unsigned int)(v4740 + 48) >> 2));
    int v4786 = (v6500 ? ({
      int * v4750 = v4736->cache_keys;
      int * v4751 = v4736->cache_keys;
      int v4752 = v4751[0];
      v4750[1] = v4752;
      int * v4754 = v4736->cache_vals;
      int * v4755 = v4736->cache_vals;
      int v4756 = v4755[0];
      v4754[1] = v4756;
      int * v4758 = v4736->cache_keys;
      int v6508 = (int)((unsigned int)(v4740 + 48) >> 2);
      v4758[0] = v6508;
      int * v4760 = v4736->cache_vals;
      v4760[0] = v4742;
      int v4762 = v4736->timer;
      int v6511 = v4762 + 1;
      v4736->timer = v6511;v4742;
    }) : ({
      int * v4765 = v4736->mem;
      int * v4766 = v4736->cache_keys;
      int v4767 = v4766[1];
      int * v4768 = v4736->cache_vals;
      int v4769 = v4768[1];
      v4765[v4767] = v4769;
      int * v4771 = v4736->cache_keys;
      int * v4772 = v4736->cache_keys;
      int v4773 = v4772[0];
      v4771[1] = v4773;
      int * v4775 = v4736->cache_vals;
      int * v4776 = v4736->cache_vals;
      int v4777 = v4776[0];
      v4775[1] = v4777;
      int * v4779 = v4736->cache_keys;
      int v6524 = (int)((unsigned int)(v4740 + 48) >> 2);
      v4779[0] = v6524;
      int * v4781 = v4736->cache_vals;
      v4781[0] = v4742;
      int v4783 = v4736->timer;
      int v6527 = v4783 + 100;
      v4736->timer = v6527;v4742;
    }));
    v4786;
  }));
  struct StateT * v6486 = v4789(v4736);
  return v6486;
}

struct StateT * v8933(struct StateT * v8934) {
  int v8935 = v8934->timer;
  int v9600 = v8935 + 1;
  v8934->timer = v9600;int * v8937 = v8934->regs;
  int v8938 = v8937[15];
  int * v8939 = v8934->regs;
  int v9604 = v8938 << 13;
  v8939[15] = v9604;
  struct StateT * v9598 = v8941(v8934);
  return v9598;
}

struct StateT * v1297(struct StateT * v1298) {
  int v1299 = v1298->timer;
  int v12484 = v1299 + 1;
  v1298->timer = v12484;int * v1301 = v1298->regs;
  int v1302 = v1301[11];
  int * v1303 = v1298->cache_keys;
  int v1304 = v1303[0];
  bool v12489 = v1304 == ((int)((unsigned int)(v1302 + 8) >> 2));
  int v1352 = (v12489 ? ({
    int * v1305 = v1298->cache_vals;
    int v1306 = v1305[0];
    v1306;
  }) : ({
    int * v1308 = v1298->cache_keys;
    int v1309 = v1308[1];
    bool v12494 = v1309 == ((int)((unsigned int)(v1302 + 8) >> 2));
    int v1350 = (v12494 ? ({
      int * v1310 = v1298->cache_vals;
      int v1311 = v1310[1];
      int * v1312 = v1298->cache_keys;
      int * v1313 = v1298->cache_keys;
      int v1314 = v1313[0];
      v1312[1] = v1314;
      int * v1316 = v1298->cache_vals;
      int * v1317 = v1298->cache_vals;
      int v1318 = v1317[0];
      v1316[1] = v1318;
      int * v1320 = v1298->cache_keys;
      int v12503 = (int)((unsigned int)(v1302 + 8) >> 2);
      v1320[0] = v12503;
      int * v1322 = v1298->cache_vals;
      v1322[0] = v1311;
      int v1324 = v1298->timer;
      int v12506 = v1324 + 1;
      v1298->timer = v12506;v1311;
    }) : ({
      int * v1327 = v1298->mem;
      int v12508 = (int)((unsigned int)(v1302 + 8) >> 2);
      int v1328 = v1327[v12508];
      int * v1329 = v1298->mem;
      int * v1330 = v1298->cache_keys;
      int v1331 = v1330[1];
      int * v1332 = v1298->cache_vals;
      int v1333 = v1332[1];
      v1329[v1331] = v1333;
      int * v1335 = v1298->cache_keys;
      int * v1336 = v1298->cache_keys;
      int v1337 = v1336[0];
      v1335[1] = v1337;
      int * v1339 = v1298->cache_vals;
      int * v1340 = v1298->cache_vals;
      int v1341 = v1340[0];
      v1339[1] = v1341;
      int * v1343 = v1298->cache_keys;
      v1343[0] = v12508;
      int * v1345 = v1298->cache_vals;
      v1345[0] = v1328;
      int v1347 = v1298->timer;
      int v12523 = v1347 + 100;
      v1298->timer = v12523;v1328;
    }));
    v1350;
  }));
  int * v1353 = v1298->regs;
  v1353[26] = v1352;
  struct StateT * v12482 = v1355(v1298);
  return v12482;
}

struct StateT * v8731(struct StateT * v8732) {
  int v8733 = v8732->timer;
  int v9831 = v8733 + 1;
  v8732->timer = v9831;int * v8735 = v8732->regs;
  int v8736 = v8735[11];
  int * v8737 = v8732->regs;
  int v8738 = v8737[9];
  int * v8739 = v8732->regs;
  int v9837 = v8736 | v8738;
  v8739[11] = v9837;
  struct StateT * v9829 = v8741(v8732);
  return v9829;
}

struct StateT * v8775(struct StateT * v8776) {
  int v8777 = v8776->timer;
  int v9782 = v8777 + 1;
  v8776->timer = v9782;int * v8779 = v8776->regs;
  int v8780 = v8779[6];
  int * v8781 = v8776->regs;
  int v9786 = v8780 << 9;
  v8781[6] = v9786;
  struct StateT * v9780 = v8783(v8776);
  return v9780;
}

struct StateT * v8241(struct StateT * v8242) {
  int v8243 = v8242->timer;
  int v10406 = v8243 + 1;
  v8242->timer = v10406;int * v8245 = v8242->regs;
  int v8246 = v8245[18];
  int * v8247 = v8242->regs;
  int v10411 = (int)((unsigned int)v8246 >> 19);
  v8247[9] = v10411;
  struct StateT * v10404 = v8249(v8242);
  return v10404;
}

struct StateT * v3443(struct StateT * v3444) {
  int v3445 = v3444->timer;
  int v7649 = v3445 + 1;
  v3444->timer = v7649;int * v3447 = v3444->regs;
  int v3448 = v3447[12];
  int * v3449 = v3444->regs;
  int v3450 = v3449[6];
  int * v3451 = v3444->regs;
  int v7655 = v3448 + v3450;
  v3451[12] = v7655;
  struct StateT * v7647 = v3453(v3444);
  return v7647;
}

struct StateT * v8205(struct StateT * v8206) {
  int v8207 = v8206->timer;
  int v10446 = v8207 + 1;
  v8206->timer = v10446;int * v8209 = v8206->regs;
  int v8210 = v8209[8];
  int * v8211 = v8206->regs;
  int v8212 = v8211[20];
  int * v8213 = v8206->regs;
  int v10452 = v8210 | v8212;
  v8213[8] = v10452;
  struct StateT * v10444 = v8215(v8206);
  return v10444;
}

struct StateT * v3931(struct StateT * v3932) {
  int v3933 = v3932->timer;
  int v7220 = v3933 + 1;
  v3932->timer = v7220;int * v3935 = v3932->regs;
  int v3936 = v3935[24];
  int * v3937 = v3932->regs;
  int v3938 = v3937[30];
  int * v3939 = v3932->regs;
  int v7226 = v3936 + v3938;
  v3939[24] = v7226;
  struct StateT * v7218 = v3941(v3932);
  return v7218;
}

struct StateT * v7785(struct StateT * v7786) {
  int v7787 = v7786->timer;
  int v10930 = v7787 + 1;
  v7786->timer = v10930;int * v7789 = v7786->regs;
  int v7790 = v7789[22];
  int * v7791 = v7786->regs;
  int v7792 = v7791[17];
  int * v7793 = v7786->regs;
  int v10937 = v7790 + v7792;
  v7793[8] = v10937;
  struct StateT * v10928 = v7795(v7786);
  return v10928;
}

struct StateT * v8297(struct StateT * v8298) {
  int v8299 = v8298->timer;
  int v10338 = v8299 + 1;
  v8298->timer = v10338;int * v8301 = v8298->regs;
  int v8302 = v8301[17];
  int * v8303 = v8298->regs;
  int v8304 = v8303[6];
  int * v8305 = v8298->regs;
  int v10345 = v8302 ^ v8304;
  v8305[8] = v10345;
  struct StateT * v10336 = v8307(v8298);
  return v10336;
}

struct StateT * v8257(struct StateT * v8258) {
  int v8259 = v8258->timer;
  int v10385 = v8259 + 1;
  v8258->timer = v10385;int * v8261 = v8258->regs;
  int v8262 = v8261[18];
  int * v8263 = v8258->regs;
  int v8264 = v8263[9];
  int * v8265 = v8258->regs;
  int v10392 = v8262 | v8264;
  v8265[6] = v10392;
  struct StateT * v10383 = v8267(v8258);
  return v10383;
}

struct StateT * v5067(struct StateT * v5068) {
  int v5069 = v5068->timer;
  int v6210 = v5069 + 1;
  v5068->timer = v6210;int * v5071 = v5068->regs;
  int v5072 = v5071[2];
  int * v5073 = v5068->cache_keys;
  int v5074 = v5073[0];
  bool v6215 = v5074 == ((int)((unsigned int)(v5072 + 84) >> 2));
  int v5122 = (v6215 ? ({
    int * v5075 = v5068->cache_vals;
    int v5076 = v5075[0];
    v5076;
  }) : ({
    int * v5078 = v5068->cache_keys;
    int v5079 = v5078[1];
    bool v6220 = v5079 == ((int)((unsigned int)(v5072 + 84) >> 2));
    int v5120 = (v6220 ? ({
      int * v5080 = v5068->cache_vals;
      int v5081 = v5080[1];
      int * v5082 = v5068->cache_keys;
      int * v5083 = v5068->cache_keys;
      int v5084 = v5083[0];
      v5082[1] = v5084;
      int * v5086 = v5068->cache_vals;
      int * v5087 = v5068->cache_vals;
      int v5088 = v5087[0];
      v5086[1] = v5088;
      int * v5090 = v5068->cache_keys;
      int v6229 = (int)((unsigned int)(v5072 + 84) >> 2);
      v5090[0] = v6229;
      int * v5092 = v5068->cache_vals;
      v5092[0] = v5081;
      int v5094 = v5068->timer;
      int v6232 = v5094 + 1;
      v5068->timer = v6232;v5081;
    }) : ({
      int * v5097 = v5068->mem;
      int v6234 = (int)((unsigned int)(v5072 + 84) >> 2);
      int v5098 = v5097[v6234];
      int * v5099 = v5068->mem;
      int * v5100 = v5068->cache_keys;
      int v5101 = v5100[1];
      int * v5102 = v5068->cache_vals;
      int v5103 = v5102[1];
      v5099[v5101] = v5103;
      int * v5105 = v5068->cache_keys;
      int * v5106 = v5068->cache_keys;
      int v5107 = v5106[0];
      v5105[1] = v5107;
      int * v5109 = v5068->cache_vals;
      int * v5110 = v5068->cache_vals;
      int v5111 = v5110[0];
      v5109[1] = v5111;
      int * v5113 = v5068->cache_keys;
      v5113[0] = v6234;
      int * v5115 = v5068->cache_vals;
      v5115[0] = v5098;
      int v5117 = v5068->timer;
      int v6249 = v5117 + 100;
      v5068->timer = v6249;v5098;
    }));
    v5120;
  }));
  int * v5123 = v5068->regs;
  v5123[9] = v5122;
  struct StateT * v6208 = v5125(v5068);
  return v6208;
}

struct StateT * v8899(struct StateT * v8900) {
  int v8901 = v8900->timer;
  int v9639 = v8901 + 1;
  v8900->timer = v9639;int * v8903 = v8900->regs;
  int v8904 = v8903[11];
  int * v8905 = v8900->regs;
  int v9644 = (int)((unsigned int)v8904 >> 19);
  v8905[9] = v9644;
  struct StateT * v9637 = v8907(v8900);
  return v9637;
}

struct StateT * v833(struct StateT * v834) {
  int v835 = v834->timer;
  int v12868 = v835 + 1;
  v834->timer = v12868;int * v837 = v834->regs;
  int v838 = v837[12];
  int * v839 = v834->cache_keys;
  int v840 = v839[0];
  bool v12873 = v840 == ((int)((unsigned int)(v838 + 8) >> 2));
  int v888 = (v12873 ? ({
    int * v841 = v834->cache_vals;
    int v842 = v841[0];
    v842;
  }) : ({
    int * v844 = v834->cache_keys;
    int v845 = v844[1];
    bool v12878 = v845 == ((int)((unsigned int)(v838 + 8) >> 2));
    int v886 = (v12878 ? ({
      int * v846 = v834->cache_vals;
      int v847 = v846[1];
      int * v848 = v834->cache_keys;
      int * v849 = v834->cache_keys;
      int v850 = v849[0];
      v848[1] = v850;
      int * v852 = v834->cache_vals;
      int * v853 = v834->cache_vals;
      int v854 = v853[0];
      v852[1] = v854;
      int * v856 = v834->cache_keys;
      int v12887 = (int)((unsigned int)(v838 + 8) >> 2);
      v856[0] = v12887;
      int * v858 = v834->cache_vals;
      v858[0] = v847;
      int v860 = v834->timer;
      int v12890 = v860 + 1;
      v834->timer = v12890;v847;
    }) : ({
      int * v863 = v834->mem;
      int v12892 = (int)((unsigned int)(v838 + 8) >> 2);
      int v864 = v863[v12892];
      int * v865 = v834->mem;
      int * v866 = v834->cache_keys;
      int v867 = v866[1];
      int * v868 = v834->cache_vals;
      int v869 = v868[1];
      v865[v867] = v869;
      int * v871 = v834->cache_keys;
      int * v872 = v834->cache_keys;
      int v873 = v872[0];
      v871[1] = v873;
      int * v875 = v834->cache_vals;
      int * v876 = v834->cache_vals;
      int v877 = v876[0];
      v875[1] = v877;
      int * v879 = v834->cache_keys;
      v879[0] = v12892;
      int * v881 = v834->cache_vals;
      v881[0] = v864;
      int v883 = v834->timer;
      int v12907 = v883 + 100;
      v834->timer = v12907;v864;
    }));
    v886;
  }));
  int * v889 = v834->regs;
  v889[7] = v888;
  struct StateT * v12866 = v891(v834);
  return v12866;
}

struct StateT * v8337(struct StateT * v8338) {
  int v8339 = v8338->timer;
  int v10290 = v8339 + 1;
  v8338->timer = v10290;int * v8341 = v8338->regs;
  int v8342 = v8341[8];
  int * v8343 = v8338->regs;
  int v8344 = v8343[25];
  int * v8345 = v8338->regs;
  int v10297 = v8342 + v8344;
  v8345[5] = v10297;
  struct StateT * v10288 = v8347(v8338);
  return v10288;
}

struct StateT * v7765(struct StateT * v7766) {
  int v7767 = v7766->timer;
  int v10954 = v7767 + 1;
  v7766->timer = v10954;int * v7769 = v7766->regs;
  int v7770 = v7769[11];
  int * v7771 = v7766->regs;
  int v7772 = v7771[23];
  int * v7773 = v7766->regs;
  int v10961 = v7770 + v7772;
  v7773[20] = v10961;
  struct StateT * v10952 = v7775(v7766);
  return v10952;
}

struct StateT * v1745(struct StateT * v1746) {
  int v1747 = v1746->timer;
  int v12088 = v1747 + 1;
  v1746->timer = v12088;int * v1749 = v1746->regs;
  int v1750 = v1749[2];
  int * v1751 = v1746->regs;
  int v1752 = v1751[16];
  int * v1753 = v1746->cache_keys;
  int v1754 = v1753[0];
  bool v12095 = v1754 == ((int)((unsigned int)(v1750 + 32) >> 2));
  int v1798 = (v12095 ? ({
    int * v1755 = v1746->cache_vals;
    v1755[0] = v1752;
    v1752;
  }) : ({
    int * v1758 = v1746->cache_keys;
    int v1759 = v1758[1];
    bool v12100 = v1759 == ((int)((unsigned int)(v1750 + 32) >> 2));
    int v1796 = (v12100 ? ({
      int * v1760 = v1746->cache_keys;
      int * v1761 = v1746->cache_keys;
      int v1762 = v1761[0];
      v1760[1] = v1762;
      int * v1764 = v1746->cache_vals;
      int * v1765 = v1746->cache_vals;
      int v1766 = v1765[0];
      v1764[1] = v1766;
      int * v1768 = v1746->cache_keys;
      int v12108 = (int)((unsigned int)(v1750 + 32) >> 2);
      v1768[0] = v12108;
      int * v1770 = v1746->cache_vals;
      v1770[0] = v1752;
      int v1772 = v1746->timer;
      int v12111 = v1772 + 1;
      v1746->timer = v12111;v1752;
    }) : ({
      int * v1775 = v1746->mem;
      int * v1776 = v1746->cache_keys;
      int v1777 = v1776[1];
      int * v1778 = v1746->cache_vals;
      int v1779 = v1778[1];
      v1775[v1777] = v1779;
      int * v1781 = v1746->cache_keys;
      int * v1782 = v1746->cache_keys;
      int v1783 = v1782[0];
      v1781[1] = v1783;
      int * v1785 = v1746->cache_vals;
      int * v1786 = v1746->cache_vals;
      int v1787 = v1786[0];
      v1785[1] = v1787;
      int * v1789 = v1746->cache_keys;
      int v12124 = (int)((unsigned int)(v1750 + 32) >> 2);
      v1789[0] = v12124;
      int * v1791 = v1746->cache_vals;
      v1791[0] = v1752;
      int v1793 = v1746->timer;
      int v12127 = v1793 + 100;
      v1746->timer = v12127;v1752;
    }));
    v1796;
  }));
  struct StateT * v12086 = v1799(v1746);
  return v12086;
}

struct StateT * v549(struct StateT * v550) {
  int v551 = v550->timer;
  int v13110 = v551 + 1;
  v550->timer = v13110;int * v553 = v550->regs;
  int v554 = v553[2];
  int * v555 = v550->regs;
  int v556 = v555[25];
  int * v557 = v550->cache_keys;
  int v558 = v557[0];
  bool v13117 = v558 == ((int)((unsigned int)(v554 + 52) >> 2));
  int v602 = (v13117 ? ({
    int * v559 = v550->cache_vals;
    v559[0] = v556;
    v556;
  }) : ({
    int * v562 = v550->cache_keys;
    int v563 = v562[1];
    bool v13122 = v563 == ((int)((unsigned int)(v554 + 52) >> 2));
    int v600 = (v13122 ? ({
      int * v564 = v550->cache_keys;
      int * v565 = v550->cache_keys;
      int v566 = v565[0];
      v564[1] = v566;
      int * v568 = v550->cache_vals;
      int * v569 = v550->cache_vals;
      int v570 = v569[0];
      v568[1] = v570;
      int * v572 = v550->cache_keys;
      int v13130 = (int)((unsigned int)(v554 + 52) >> 2);
      v572[0] = v13130;
      int * v574 = v550->cache_vals;
      v574[0] = v556;
      int v576 = v550->timer;
      int v13133 = v576 + 1;
      v550->timer = v13133;v556;
    }) : ({
      int * v579 = v550->mem;
      int * v580 = v550->cache_keys;
      int v581 = v580[1];
      int * v582 = v550->cache_vals;
      int v583 = v582[1];
      v579[v581] = v583;
      int * v585 = v550->cache_keys;
      int * v586 = v550->cache_keys;
      int v587 = v586[0];
      v585[1] = v587;
      int * v589 = v550->cache_vals;
      int * v590 = v550->cache_vals;
      int v591 = v590[0];
      v589[1] = v591;
      int * v593 = v550->cache_keys;
      int v13146 = (int)((unsigned int)(v554 + 52) >> 2);
      v593[0] = v13146;
      int * v595 = v550->cache_vals;
      v595[0] = v556;
      int v597 = v550->timer;
      int v13149 = v597 + 100;
      v550->timer = v13149;v556;
    }));
    v600;
  }));
  struct StateT * v13108 = v603(v550);
  return v13108;
}

struct StateT * v9091(struct StateT * v9092) {
  int v9093 = v9092->timer;
  int v9418 = v9093 + 1;
  v9092->timer = v9418;int * v9095 = v9092->regs;
  int v9096 = v9095[11];
  int * v9097 = v9092->regs;
  int v9422 = v9096 << 18;
  v9097[11] = v9422;
  struct StateT * v9416 = v9099(v9092);
  return v9416;
}

struct StateT * v8685(struct StateT * v8686) {
  int v8687 = v8686->timer;
  int v9885 = v8687 + 1;
  v8686->timer = v9885;int * v8689 = v8686->regs;
  int v8690 = v8689[5];
  int * v8691 = v8686->regs;
  int v8692 = v8691[20];
  int * v8693 = v8686->regs;
  int v9892 = v8690 + v8692;
  v8693[15] = v9892;
  struct StateT * v9883 = v8695(v8686);
  return v9883;
}

struct StateT * v4681(struct StateT * v4682) {
  int v4683 = v4682->timer;
  int v6533 = v4683 + 1;
  v4682->timer = v6533;int * v4685 = v4682->regs;
  int v4686 = v4685[10];
  int * v4687 = v4682->regs;
  int v4688 = v4687[17];
  int * v4689 = v4682->cache_keys;
  int v4690 = v4689[0];
  bool v6540 = v4690 == ((int)((unsigned int)(v4686 + 44) >> 2));
  int v4734 = (v6540 ? ({
    int * v4691 = v4682->cache_vals;
    v4691[0] = v4688;
    v4688;
  }) : ({
    int * v4694 = v4682->cache_keys;
    int v4695 = v4694[1];
    bool v6545 = v4695 == ((int)((unsigned int)(v4686 + 44) >> 2));
    int v4732 = (v6545 ? ({
      int * v4696 = v4682->cache_keys;
      int * v4697 = v4682->cache_keys;
      int v4698 = v4697[0];
      v4696[1] = v4698;
      int * v4700 = v4682->cache_vals;
      int * v4701 = v4682->cache_vals;
      int v4702 = v4701[0];
      v4700[1] = v4702;
      int * v4704 = v4682->cache_keys;
      int v6553 = (int)((unsigned int)(v4686 + 44) >> 2);
      v4704[0] = v6553;
      int * v4706 = v4682->cache_vals;
      v4706[0] = v4688;
      int v4708 = v4682->timer;
      int v6556 = v4708 + 1;
      v4682->timer = v6556;v4688;
    }) : ({
      int * v4711 = v4682->mem;
      int * v4712 = v4682->cache_keys;
      int v4713 = v4712[1];
      int * v4714 = v4682->cache_vals;
      int v4715 = v4714[1];
      v4711[v4713] = v4715;
      int * v4717 = v4682->cache_keys;
      int * v4718 = v4682->cache_keys;
      int v4719 = v4718[0];
      v4717[1] = v4719;
      int * v4721 = v4682->cache_vals;
      int * v4722 = v4682->cache_vals;
      int v4723 = v4722[0];
      v4721[1] = v4723;
      int * v4725 = v4682->cache_keys;
      int v6569 = (int)((unsigned int)(v4686 + 44) >> 2);
      v4725[0] = v6569;
      int * v4727 = v4682->cache_vals;
      v4727[0] = v4688;
      int v4729 = v4682->timer;
      int v6572 = v4729 + 100;
      v4682->timer = v6572;v4688;
    }));
    v4732;
  }));
  struct StateT * v6531 = v4735(v4682);
  return v6531;
}

struct StateT * v387(struct StateT * v388) {
  int v389 = v388->timer;
  int v13245 = v389 + 1;
  v388->timer = v13245;int * v391 = v388->regs;
  int v392 = v391[2];
  int * v393 = v388->regs;
  int v394 = v393[22];
  int * v395 = v388->cache_keys;
  int v396 = v395[0];
  bool v13252 = v396 == ((int)((unsigned int)(v392 + 64) >> 2));
  int v440 = (v13252 ? ({
    int * v397 = v388->cache_vals;
    v397[0] = v394;
    v394;
  }) : ({
    int * v400 = v388->cache_keys;
    int v401 = v400[1];
    bool v13257 = v401 == ((int)((unsigned int)(v392 + 64) >> 2));
    int v438 = (v13257 ? ({
      int * v402 = v388->cache_keys;
      int * v403 = v388->cache_keys;
      int v404 = v403[0];
      v402[1] = v404;
      int * v406 = v388->cache_vals;
      int * v407 = v388->cache_vals;
      int v408 = v407[0];
      v406[1] = v408;
      int * v410 = v388->cache_keys;
      int v13265 = (int)((unsigned int)(v392 + 64) >> 2);
      v410[0] = v13265;
      int * v412 = v388->cache_vals;
      v412[0] = v394;
      int v414 = v388->timer;
      int v13268 = v414 + 1;
      v388->timer = v13268;v394;
    }) : ({
      int * v417 = v388->mem;
      int * v418 = v388->cache_keys;
      int v419 = v418[1];
      int * v420 = v388->cache_vals;
      int v421 = v420[1];
      v417[v419] = v421;
      int * v423 = v388->cache_keys;
      int * v424 = v388->cache_keys;
      int v425 = v424[0];
      v423[1] = v425;
      int * v427 = v388->cache_vals;
      int * v428 = v388->cache_vals;
      int v429 = v428[0];
      v427[1] = v429;
      int * v431 = v388->cache_keys;
      int v13281 = (int)((unsigned int)(v392 + 64) >> 2);
      v431[0] = v13281;
      int * v433 = v388->cache_vals;
      v433[0] = v394;
      int v435 = v388->timer;
      int v13284 = v435 + 100;
      v388->timer = v13284;v394;
    }));
    v438;
  }));
  struct StateT * v13243 = v441(v388);
  return v13243;
}

struct StateT * v4087(struct StateT * v4088) {
  int v4089 = v4088->timer;
  int v7028 = v4089 + 1;
  v4088->timer = v7028;int * v4091 = v4088->regs;
  int v4092 = v4091[10];
  int * v4093 = v4088->regs;
  int v4094 = v4093[15];
  int * v4095 = v4088->cache_keys;
  int v4096 = v4095[0];
  bool v7035 = v4096 == ((int)((unsigned int)v4092 >> 2));
  int v4140 = (v7035 ? ({
    int * v4097 = v4088->cache_vals;
    v4097[0] = v4094;
    v4094;
  }) : ({
    int * v4100 = v4088->cache_keys;
    int v4101 = v4100[1];
    bool v7040 = v4101 == ((int)((unsigned int)v4092 >> 2));
    int v4138 = (v7040 ? ({
      int * v4102 = v4088->cache_keys;
      int * v4103 = v4088->cache_keys;
      int v4104 = v4103[0];
      v4102[1] = v4104;
      int * v4106 = v4088->cache_vals;
      int * v4107 = v4088->cache_vals;
      int v4108 = v4107[0];
      v4106[1] = v4108;
      int * v4110 = v4088->cache_keys;
      int v7048 = (int)((unsigned int)v4092 >> 2);
      v4110[0] = v7048;
      int * v4112 = v4088->cache_vals;
      v4112[0] = v4094;
      int v4114 = v4088->timer;
      int v7051 = v4114 + 1;
      v4088->timer = v7051;v4094;
    }) : ({
      int * v4117 = v4088->mem;
      int * v4118 = v4088->cache_keys;
      int v4119 = v4118[1];
      int * v4120 = v4088->cache_vals;
      int v4121 = v4120[1];
      v4117[v4119] = v4121;
      int * v4123 = v4088->cache_keys;
      int * v4124 = v4088->cache_keys;
      int v4125 = v4124[0];
      v4123[1] = v4125;
      int * v4127 = v4088->cache_vals;
      int * v4128 = v4088->cache_vals;
      int v4129 = v4128[0];
      v4127[1] = v4129;
      int * v4131 = v4088->cache_keys;
      int v7064 = (int)((unsigned int)v4092 >> 2);
      v4131[0] = v7064;
      int * v4133 = v4088->cache_vals;
      v4133[0] = v4094;
      int v4135 = v4088->timer;
      int v7067 = v4135 + 100;
      v4088->timer = v7067;v4094;
    }));
    v4138;
  }));
  struct StateT * v7026 = v4141(v4088);
  return v7026;
}

struct StateT * v1461(struct StateT * v1462) {
  int v1463 = v1462->timer;
  int v12365 = v1463 + 1;
  v1462->timer = v12365;int * v1465 = v1462->regs;
  int v1466 = v1465[22];
  int * v1467 = v1462->regs;
  int v12369 = v1466 + 1396;
  v1467[22] = v12369;
  struct StateT * v12363 = v1469(v1462);
  return v12363;
}

struct StateT * v171(struct StateT * v172) {
  int v173 = v172->timer;
  int v13425 = v173 + 1;
  v172->timer = v13425;int * v175 = v172->regs;
  int v176 = v175[2];
  int * v177 = v172->regs;
  int v178 = v177[18];
  int * v179 = v172->cache_keys;
  int v180 = v179[0];
  bool v13432 = v180 == ((int)((unsigned int)(v176 + 80) >> 2));
  int v224 = (v13432 ? ({
    int * v181 = v172->cache_vals;
    v181[0] = v178;
    v178;
  }) : ({
    int * v184 = v172->cache_keys;
    int v185 = v184[1];
    bool v13437 = v185 == ((int)((unsigned int)(v176 + 80) >> 2));
    int v222 = (v13437 ? ({
      int * v186 = v172->cache_keys;
      int * v187 = v172->cache_keys;
      int v188 = v187[0];
      v186[1] = v188;
      int * v190 = v172->cache_vals;
      int * v191 = v172->cache_vals;
      int v192 = v191[0];
      v190[1] = v192;
      int * v194 = v172->cache_keys;
      int v13445 = (int)((unsigned int)(v176 + 80) >> 2);
      v194[0] = v13445;
      int * v196 = v172->cache_vals;
      v196[0] = v178;
      int v198 = v172->timer;
      int v13448 = v198 + 1;
      v172->timer = v13448;v178;
    }) : ({
      int * v201 = v172->mem;
      int * v202 = v172->cache_keys;
      int v203 = v202[1];
      int * v204 = v172->cache_vals;
      int v205 = v204[1];
      v201[v203] = v205;
      int * v207 = v172->cache_keys;
      int * v208 = v172->cache_keys;
      int v209 = v208[0];
      v207[1] = v209;
      int * v211 = v172->cache_vals;
      int * v212 = v172->cache_vals;
      int v213 = v212[0];
      v211[1] = v213;
      int * v215 = v172->cache_keys;
      int v13461 = (int)((unsigned int)(v176 + 80) >> 2);
      v215[0] = v13461;
      int * v217 = v172->cache_vals;
      v217[0] = v178;
      int v219 = v172->timer;
      int v13464 = v219 + 100;
      v172->timer = v13464;v178;
    }));
    v222;
  }));
  struct StateT * v13423 = v225(v172);
  return v13423;
}

struct StateT * v3359(struct StateT * v3360) {
  int v3361 = v3360->timer;
  int v7727 = v3361 + 1;
  v3360->timer = v7727;int * v3363 = v3360->regs;
  int v3364 = v3363[27];
  int * v3365 = v3360->regs;
  int v3366 = v3365[28];
  int * v3367 = v3360->regs;
  int v7733 = v3364 + v3366;
  v3367[28] = v7733;
  struct StateT * v7725 = v3369(v3360);
  return v7725;
}

struct StateT * v8363(struct StateT * v8364) {
  int v8365 = v8364->timer;
  int v10260 = v8365 + 1;
  v8364->timer = v10260;int * v8367 = v8364->regs;
  int v8368 = v8367[15];
  int * v8369 = v8364->regs;
  int v8370 = v8369[6];
  int * v8371 = v8364->regs;
  int v10266 = v8368 | v8370;
  v8371[15] = v10266;
  struct StateT * v10258 = v8373(v8364);
  return v10258;
}

struct StateT * v9187(struct StateT * v9188) {
  int v9189 = v9188->timer;
  int v9306 = v9189 + 1;
  v9188->timer = v9306;int * v9191 = v9188->regs;
  int v9192 = v9191[21];
  int * v9193 = v9188->regs;
  int v9194 = v9193[11];
  int * v9195 = v9188->regs;
  int v9312 = v9192 ^ v9194;
  v9195[21] = v9312;
  struct StateT * v9304 = v9197(v9188);
  return v9304;
}

struct StateT * v8531(struct StateT * v8532) {
  int v8533 = v8532->timer;
  int v10067 = v8533 + 1;
  v8532->timer = v10067;int * v8535 = v8532->regs;
  int v8536 = v8535[15];
  int * v8537 = v8532->regs;
  int v10072 = (int)((unsigned int)v8536 >> 25);
  v8537[5] = v10072;
  struct StateT * v10065 = v8539(v8532);
  return v10065;
}

struct StateT * v3459(struct StateT * v3460) {
  int v3461 = v3460->timer;
  int v7593 = v3461 + 1;
  v3460->timer = v7593;int * v3463 = v3460->regs;
  int v3464 = v3463[2];
  int * v3465 = v3460->cache_keys;
  int v3466 = v3465[0];
  bool v7598 = v3466 == ((int)((unsigned int)(v3464 + 12) >> 2));
  int v3514 = (v7598 ? ({
    int * v3467 = v3460->cache_vals;
    int v3468 = v3467[0];
    v3468;
  }) : ({
    int * v3470 = v3460->cache_keys;
    int v3471 = v3470[1];
    bool v7603 = v3471 == ((int)((unsigned int)(v3464 + 12) >> 2));
    int v3512 = (v7603 ? ({
      int * v3472 = v3460->cache_vals;
      int v3473 = v3472[1];
      int * v3474 = v3460->cache_keys;
      int * v3475 = v3460->cache_keys;
      int v3476 = v3475[0];
      v3474[1] = v3476;
      int * v3478 = v3460->cache_vals;
      int * v3479 = v3460->cache_vals;
      int v3480 = v3479[0];
      v3478[1] = v3480;
      int * v3482 = v3460->cache_keys;
      int v7612 = (int)((unsigned int)(v3464 + 12) >> 2);
      v3482[0] = v7612;
      int * v3484 = v3460->cache_vals;
      v3484[0] = v3473;
      int v3486 = v3460->timer;
      int v7615 = v3486 + 1;
      v3460->timer = v7615;v3473;
    }) : ({
      int * v3489 = v3460->mem;
      int v7617 = (int)((unsigned int)(v3464 + 12) >> 2);
      int v3490 = v3489[v7617];
      int * v3491 = v3460->mem;
      int * v3492 = v3460->cache_keys;
      int v3493 = v3492[1];
      int * v3494 = v3460->cache_vals;
      int v3495 = v3494[1];
      v3491[v3493] = v3495;
      int * v3497 = v3460->cache_keys;
      int * v3498 = v3460->cache_keys;
      int v3499 = v3498[0];
      v3497[1] = v3499;
      int * v3501 = v3460->cache_vals;
      int * v3502 = v3460->cache_vals;
      int v3503 = v3502[0];
      v3501[1] = v3503;
      int * v3505 = v3460->cache_keys;
      v3505[0] = v7617;
      int * v3507 = v3460->cache_vals;
      v3507[0] = v3490;
      int v3509 = v3460->timer;
      int v7632 = v3509 + 100;
      v3460->timer = v7632;v3490;
    }));
    v3512;
  }));
  int * v3515 = v3460->regs;
  v3515[7] = v3514;
  struct StateT * v7591 = v3517(v3460);
  return v7591;
}

struct StateT * v7855(struct StateT * v7856) {
  int v7857 = v7856->timer;
  int v10851 = v7857 + 1;
  v7856->timer = v10851;int * v7859 = v7856->regs;
  int v7860 = v7859[18];
  int * v7861 = v7856->regs;
  int v10855 = v7860 << 7;
  v7861[18] = v10855;
  struct StateT * v10849 = v7863(v7856);
  return v10849;
}

struct StateT * v1915(struct StateT * v1916) {
  int v1917 = v1916->timer;
  int v11978 = v1917 + 1;
  v1916->timer = v11978;int * v1919 = v1916->regs;
  int v1920 = v1919[7];
  int * v1921 = v1916->regs;
  v1921[14] = v1920;
  struct StateT * v11976 = v1923(v1916);
  return v11976;
}

struct StateT * v8723(struct StateT * v8724) {
  int v8725 = v8724->timer;
  int v9842 = v8725 + 1;
  v8724->timer = v9842;int * v8727 = v8724->regs;
  int v8728 = v8727[11];
  int * v8729 = v8724->regs;
  int v9846 = v8728 << 9;
  v8729[11] = v9846;
  struct StateT * v9840 = v8731(v8724);
  return v9840;
}

struct StateT * v1439(struct StateT * v1440) {
  int v1441 = v1440->timer;
  int v12392 = v1441 + 1;
  v1440->timer = v12392;int * v1443 = v1440->regs;
  int v1444 = v1443[13];
  int * v1445 = v1440->regs;
  int v12397 = v1444 + 1134;
  v1445[11] = v12397;
  struct StateT * v12390 = v1447(v1440);
  return v12390;
}

struct StateT * v7899(struct StateT * v7900) {
  int v7901 = v7900->timer;
  int v10799 = v7901 + 1;
  v7900->timer = v10799;int * v7903 = v7900->regs;
  int v7904 = v7903[12];
  int * v7905 = v7900->regs;
  int v7906 = v7905[15];
  int * v7907 = v7900->regs;
  int v10805 = v7904 ^ v7906;
  v7907[12] = v10805;
  struct StateT * v10797 = v7909(v7900);
  return v10797;
}

struct StateT * v9073(struct StateT * v9074) {
  int v9075 = v9074->timer;
  int v9437 = v9075 + 1;
  v9074->timer = v9437;int * v9077 = v9074->regs;
  int v9078 = v9077[1];
  int * v9079 = v9074->regs;
  int v9080 = v9079[24];
  int * v9081 = v9074->regs;
  int v9444 = v9078 + v9080;
  v9081[8] = v9444;
  struct StateT * v9435 = v9083(v9074);
  return v9435;
}

struct StateT * v9151(struct StateT * v9152) {
  int v9153 = v9152->timer;
  int v9347 = v9153 + 1;
  v9152->timer = v9347;int * v9155 = v9152->regs;
  int v9156 = v9155[6];
  int * v9157 = v9152->regs;
  int v9158 = v9157[9];
  int * v9159 = v9152->regs;
  int v9353 = v9156 | v9158;
  v9159[6] = v9353;
  struct StateT * v9345 = v9161(v9152);
  return v9345;
}

struct StateT * v7909(struct StateT * v7910) {
  int v7911 = v7910->timer;
  int v10788 = v7911 + 1;
  v7910->timer = v10788;int * v7913 = v7910->regs;
  int v7914 = v7913[13];
  int * v7915 = v7910->regs;
  int v7916 = v7915[9];
  int * v7917 = v7910->regs;
  int v10794 = v7914 ^ v7916;
  v7917[13] = v10794;
  struct StateT * v10786 = v7919(v7910);
  return v10786;
}

struct StateT * v8625(struct StateT * v8626) {
  int v8627 = v8626->timer;
  int v9956 = v8627 + 1;
  v8626->timer = v9956;int * v8629 = v8626->regs;
  int v8630 = v8629[17];
  int * v8631 = v8626->regs;
  int v8632 = v8631[5];
  int * v8633 = v8626->regs;
  int v9963 = v8630 | v8632;
  v8633[6] = v9963;
  struct StateT * v9954 = v8635(v8626);
  return v9954;
}

struct StateT * v8749(struct StateT * v8750) {
  int v8751 = v8750->timer;
  int v9812 = v8751 + 1;
  v8750->timer = v9812;int * v8753 = v8750->regs;
  int v8754 = v8753[15];
  int * v8755 = v8750->regs;
  int v9816 = v8754 << 9;
  v8755[15] = v9816;
  struct StateT * v9810 = v8757(v8750);
  return v9810;
}

struct StateT * v3385(struct StateT * v3386) {
  int v3387 = v3386->timer;
  int v7660 = v3387 + 1;
  v3386->timer = v7660;int * v3389 = v3386->regs;
  int v3390 = v3389[2];
  int * v3391 = v3386->cache_keys;
  int v3392 = v3391[0];
  bool v7665 = v3392 == ((int)((unsigned int)(v3390 + 8) >> 2));
  int v3440 = (v7665 ? ({
    int * v3393 = v3386->cache_vals;
    int v3394 = v3393[0];
    v3394;
  }) : ({
    int * v3396 = v3386->cache_keys;
    int v3397 = v3396[1];
    bool v7670 = v3397 == ((int)((unsigned int)(v3390 + 8) >> 2));
    int v3438 = (v7670 ? ({
      int * v3398 = v3386->cache_vals;
      int v3399 = v3398[1];
      int * v3400 = v3386->cache_keys;
      int * v3401 = v3386->cache_keys;
      int v3402 = v3401[0];
      v3400[1] = v3402;
      int * v3404 = v3386->cache_vals;
      int * v3405 = v3386->cache_vals;
      int v3406 = v3405[0];
      v3404[1] = v3406;
      int * v3408 = v3386->cache_keys;
      int v7679 = (int)((unsigned int)(v3390 + 8) >> 2);
      v3408[0] = v7679;
      int * v3410 = v3386->cache_vals;
      v3410[0] = v3399;
      int v3412 = v3386->timer;
      int v7682 = v3412 + 1;
      v3386->timer = v7682;v3399;
    }) : ({
      int * v3415 = v3386->mem;
      int v7684 = (int)((unsigned int)(v3390 + 8) >> 2);
      int v3416 = v3415[v7684];
      int * v3417 = v3386->mem;
      int * v3418 = v3386->cache_keys;
      int v3419 = v3418[1];
      int * v3420 = v3386->cache_vals;
      int v3421 = v3420[1];
      v3417[v3419] = v3421;
      int * v3423 = v3386->cache_keys;
      int * v3424 = v3386->cache_keys;
      int v3425 = v3424[0];
      v3423[1] = v3425;
      int * v3427 = v3386->cache_vals;
      int * v3428 = v3386->cache_vals;
      int v3429 = v3428[0];
      v3427[1] = v3429;
      int * v3431 = v3386->cache_keys;
      v3431[0] = v7684;
      int * v3433 = v3386->cache_vals;
      v3433[0] = v3416;
      int v3435 = v3386->timer;
      int v7699 = v3435 + 100;
      v3386->timer = v7699;v3416;
    }));
    v3438;
  }));
  int * v3441 = v3386->regs;
  v3441[6] = v3440;
  struct StateT * v7658 = v3443(v3386);
  return v7658;
}

struct StateT * v8103(struct StateT * v8104) {
  int v8105 = v8104->timer;
  int v10565 = v8105 + 1;
  v8104->timer = v10565;int * v8107 = v8104->regs;
  int v8108 = v8107[27];
  int * v8109 = v8104->regs;
  int v8110 = v8109[9];
  int * v8111 = v8104->regs;
  int v10571 = v8108 ^ v8110;
  v8111[27] = v10571;
  struct StateT * v10563 = v8113(v8104);
  return v10563;
}

struct StateT * v9135(struct StateT * v9136) {
  int v9137 = v9136->timer;
  int v9367 = v9137 + 1;
  v9136->timer = v9367;int * v9139 = v9136->regs;
  int v9140 = v9139[6];
  int * v9141 = v9136->regs;
  int v9372 = (int)((unsigned int)v9140 >> 14);
  v9141[9] = v9372;
  struct StateT * v9365 = v9143(v9136);
  return v9365;
}

struct StateT * v9197(struct StateT * v9198) {
  int v9199 = v9198->timer;
  int v9294 = v9199 + 1;
  v9198->timer = v9294;int * v9201 = v9198->regs;
  int v9202 = v9201[20];
  int * v9203 = v9198->regs;
  int v9204 = v9203[15];
  int * v9205 = v9198->regs;
  int v9301 = v9202 ^ v9204;
  v9205[11] = v9301;
  struct StateT * v9292 = v9207(v9198);
  return v9292;
}

struct StateT * v9207(struct StateT * v9208) {
  int v9209 = v9208->timer;
  int v9283 = v9209 + 1;
  v9208->timer = v9283;int * v9211 = v9208->regs;
  int v9212 = v9211[19];
  int * v9213 = v9208->regs;
  int v9214 = v9213[6];
  int * v9215 = v9208->regs;
  int v9289 = v9212 ^ v9214;
  v9215[19] = v9289;
  struct StateT * v9281 = v9217(v9208);
  return v9281;
}

struct StateT * v8113(struct StateT * v8114) {
  int v8115 = v8114->timer;
  int v10554 = v8115 + 1;
  v8114->timer = v10554;int * v8117 = v8114->regs;
  int v8118 = v8117[25];
  int * v8119 = v8114->regs;
  int v8120 = v8119[18];
  int * v8121 = v8114->regs;
  int v10560 = v8118 ^ v8120;
  v8121[25] = v10560;
  struct StateT * v10552 = v8123(v8114);
  return v10552;
}

struct StateT * v5357(struct StateT * v5358) {
  int v5359 = v5358->timer;
  int v5970 = v5359 + 1;
  v5358->timer = v5970;int * v5361 = v5358->regs;
  int v5362 = v5361[2];
  int * v5363 = v5358->cache_keys;
  int v5364 = v5363[0];
  bool v5975 = v5364 == ((int)((unsigned int)(v5362 + 64) >> 2));
  int v5412 = (v5975 ? ({
    int * v5365 = v5358->cache_vals;
    int v5366 = v5365[0];
    v5366;
  }) : ({
    int * v5368 = v5358->cache_keys;
    int v5369 = v5368[1];
    bool v5980 = v5369 == ((int)((unsigned int)(v5362 + 64) >> 2));
    int v5410 = (v5980 ? ({
      int * v5370 = v5358->cache_vals;
      int v5371 = v5370[1];
      int * v5372 = v5358->cache_keys;
      int * v5373 = v5358->cache_keys;
      int v5374 = v5373[0];
      v5372[1] = v5374;
      int * v5376 = v5358->cache_vals;
      int * v5377 = v5358->cache_vals;
      int v5378 = v5377[0];
      v5376[1] = v5378;
      int * v5380 = v5358->cache_keys;
      int v5989 = (int)((unsigned int)(v5362 + 64) >> 2);
      v5380[0] = v5989;
      int * v5382 = v5358->cache_vals;
      v5382[0] = v5371;
      int v5384 = v5358->timer;
      int v5992 = v5384 + 1;
      v5358->timer = v5992;v5371;
    }) : ({
      int * v5387 = v5358->mem;
      int v5994 = (int)((unsigned int)(v5362 + 64) >> 2);
      int v5388 = v5387[v5994];
      int * v5389 = v5358->mem;
      int * v5390 = v5358->cache_keys;
      int v5391 = v5390[1];
      int * v5392 = v5358->cache_vals;
      int v5393 = v5392[1];
      v5389[v5391] = v5393;
      int * v5395 = v5358->cache_keys;
      int * v5396 = v5358->cache_keys;
      int v5397 = v5396[0];
      v5395[1] = v5397;
      int * v5399 = v5358->cache_vals;
      int * v5400 = v5358->cache_vals;
      int v5401 = v5400[0];
      v5399[1] = v5401;
      int * v5403 = v5358->cache_keys;
      v5403[0] = v5994;
      int * v5405 = v5358->cache_vals;
      v5405[0] = v5388;
      int v5407 = v5358->timer;
      int v6009 = v5407 + 100;
      v5358->timer = v6009;v5388;
    }));
    v5410;
  }));
  int * v5413 = v5358->regs;
  v5413[22] = v5412;
  struct StateT * v5968 = v5415(v5358);
  return v5968;
}

struct StateT * v8425(struct StateT * v8426) {
  int v8427 = v8426->timer;
  int v10190 = v8427 + 1;
  v8426->timer = v10190;int * v8429 = v8426->regs;
  int v8430 = v8429[5];
  int * v8431 = v8426->regs;
  int v10195 = (int)((unsigned int)v8430 >> 14);
  v8431[6] = v10195;
  struct StateT * v10188 = v8433(v8426);
  return v10188;
}

struct StateT * v4249(struct StateT * v4250) {
  int v4251 = v4250->timer;
  int v6893 = v4251 + 1;
  v4250->timer = v6893;int * v4253 = v4250->regs;
  int v4254 = v4253[10];
  int * v4255 = v4250->regs;
  int v4256 = v4255[14];
  int * v4257 = v4250->cache_keys;
  int v4258 = v4257[0];
  bool v6900 = v4258 == ((int)((unsigned int)(v4254 + 12) >> 2));
  int v4302 = (v6900 ? ({
    int * v4259 = v4250->cache_vals;
    v4259[0] = v4256;
    v4256;
  }) : ({
    int * v4262 = v4250->cache_keys;
    int v4263 = v4262[1];
    bool v6905 = v4263 == ((int)((unsigned int)(v4254 + 12) >> 2));
    int v4300 = (v6905 ? ({
      int * v4264 = v4250->cache_keys;
      int * v4265 = v4250->cache_keys;
      int v4266 = v4265[0];
      v4264[1] = v4266;
      int * v4268 = v4250->cache_vals;
      int * v4269 = v4250->cache_vals;
      int v4270 = v4269[0];
      v4268[1] = v4270;
      int * v4272 = v4250->cache_keys;
      int v6913 = (int)((unsigned int)(v4254 + 12) >> 2);
      v4272[0] = v6913;
      int * v4274 = v4250->cache_vals;
      v4274[0] = v4256;
      int v4276 = v4250->timer;
      int v6916 = v4276 + 1;
      v4250->timer = v6916;v4256;
    }) : ({
      int * v4279 = v4250->mem;
      int * v4280 = v4250->cache_keys;
      int v4281 = v4280[1];
      int * v4282 = v4250->cache_vals;
      int v4283 = v4282[1];
      v4279[v4281] = v4283;
      int * v4285 = v4250->cache_keys;
      int * v4286 = v4250->cache_keys;
      int v4287 = v4286[0];
      v4285[1] = v4287;
      int * v4289 = v4250->cache_vals;
      int * v4290 = v4250->cache_vals;
      int v4291 = v4290[0];
      v4289[1] = v4291;
      int * v4293 = v4250->cache_keys;
      int v6929 = (int)((unsigned int)(v4254 + 12) >> 2);
      v4293[0] = v6929;
      int * v4295 = v4250->cache_vals;
      v4295[0] = v4256;
      int v4297 = v4250->timer;
      int v6932 = v4297 + 100;
      v4250->timer = v6932;v4256;
    }));
    v4300;
  }));
  struct StateT * v6891 = v4303(v4250);
  return v6891;
}

struct StateT * v603(struct StateT * v604) {
  int v605 = v604->timer;
  int v13065 = v605 + 1;
  v604->timer = v13065;int * v607 = v604->regs;
  int v608 = v607[2];
  int * v609 = v604->regs;
  int v610 = v609[26];
  int * v611 = v604->cache_keys;
  int v612 = v611[0];
  bool v13072 = v612 == ((int)((unsigned int)(v608 + 48) >> 2));
  int v656 = (v13072 ? ({
    int * v613 = v604->cache_vals;
    v613[0] = v610;
    v610;
  }) : ({
    int * v616 = v604->cache_keys;
    int v617 = v616[1];
    bool v13077 = v617 == ((int)((unsigned int)(v608 + 48) >> 2));
    int v654 = (v13077 ? ({
      int * v618 = v604->cache_keys;
      int * v619 = v604->cache_keys;
      int v620 = v619[0];
      v618[1] = v620;
      int * v622 = v604->cache_vals;
      int * v623 = v604->cache_vals;
      int v624 = v623[0];
      v622[1] = v624;
      int * v626 = v604->cache_keys;
      int v13085 = (int)((unsigned int)(v608 + 48) >> 2);
      v626[0] = v13085;
      int * v628 = v604->cache_vals;
      v628[0] = v610;
      int v630 = v604->timer;
      int v13088 = v630 + 1;
      v604->timer = v13088;v610;
    }) : ({
      int * v633 = v604->mem;
      int * v634 = v604->cache_keys;
      int v635 = v634[1];
      int * v636 = v604->cache_vals;
      int v637 = v636[1];
      v633[v635] = v637;
      int * v639 = v604->cache_keys;
      int * v640 = v604->cache_keys;
      int v641 = v640[0];
      v639[1] = v641;
      int * v643 = v604->cache_vals;
      int * v644 = v604->cache_vals;
      int v645 = v644[0];
      v643[1] = v645;
      int * v647 = v604->cache_keys;
      int v13101 = (int)((unsigned int)(v608 + 48) >> 2);
      v647[0] = v13101;
      int * v649 = v604->cache_vals;
      v649[0] = v610;
      int v651 = v604->timer;
      int v13104 = v651 + 100;
      v604->timer = v13104;v610;
    }));
    v654;
  }));
  struct StateT * v13063 = v657(v604);
  return v13063;
}

struct StateT * v8757(struct StateT * v8758) {
  int v8759 = v8758->timer;
  int v9801 = v8759 + 1;
  v8758->timer = v9801;int * v8761 = v8758->regs;
  int v8762 = v8761[15];
  int * v8763 = v8758->regs;
  int v8764 = v8763[9];
  int * v8765 = v8758->regs;
  int v9807 = v8762 | v8764;
  v8765[15] = v9807;
  struct StateT * v9799 = v8767(v8758);
  return v9799;
}

struct StateT * v4519(struct StateT * v4520) {
  int v4521 = v4520->timer;
  int v6668 = v4521 + 1;
  v4520->timer = v6668;int * v4523 = v4520->regs;
  int v4524 = v4523[10];
  int * v4525 = v4520->regs;
  int v4526 = v4525[26];
  int * v4527 = v4520->cache_keys;
  int v4528 = v4527[0];
  bool v6675 = v4528 == ((int)((unsigned int)(v4524 + 32) >> 2));
  int v4572 = (v6675 ? ({
    int * v4529 = v4520->cache_vals;
    v4529[0] = v4526;
    v4526;
  }) : ({
    int * v4532 = v4520->cache_keys;
    int v4533 = v4532[1];
    bool v6680 = v4533 == ((int)((unsigned int)(v4524 + 32) >> 2));
    int v4570 = (v6680 ? ({
      int * v4534 = v4520->cache_keys;
      int * v4535 = v4520->cache_keys;
      int v4536 = v4535[0];
      v4534[1] = v4536;
      int * v4538 = v4520->cache_vals;
      int * v4539 = v4520->cache_vals;
      int v4540 = v4539[0];
      v4538[1] = v4540;
      int * v4542 = v4520->cache_keys;
      int v6688 = (int)((unsigned int)(v4524 + 32) >> 2);
      v4542[0] = v6688;
      int * v4544 = v4520->cache_vals;
      v4544[0] = v4526;
      int v4546 = v4520->timer;
      int v6691 = v4546 + 1;
      v4520->timer = v6691;v4526;
    }) : ({
      int * v4549 = v4520->mem;
      int * v4550 = v4520->cache_keys;
      int v4551 = v4550[1];
      int * v4552 = v4520->cache_vals;
      int v4553 = v4552[1];
      v4549[v4551] = v4553;
      int * v4555 = v4520->cache_keys;
      int * v4556 = v4520->cache_keys;
      int v4557 = v4556[0];
      v4555[1] = v4557;
      int * v4559 = v4520->cache_vals;
      int * v4560 = v4520->cache_vals;
      int v4561 = v4560[0];
      v4559[1] = v4561;
      int * v4563 = v4520->cache_keys;
      int v6704 = (int)((unsigned int)(v4524 + 32) >> 2);
      v4563[0] = v6704;
      int * v4565 = v4520->cache_vals;
      v4565[0] = v4526;
      int v4567 = v4520->timer;
      int v6707 = v4567 + 100;
      v4520->timer = v6707;v4526;
    }));
    v4570;
  }));
  struct StateT * v6666 = v4573(v4520);
  return v6666;
}

struct StateT * v8047(struct StateT * v8048) {
  int v8049 = v8048->timer;
  int v10628 = v8049 + 1;
  v8048->timer = v10628;int * v8051 = v8048->regs;
  int v8052 = v8051[9];
  int * v8053 = v8048->regs;
  int v8054 = v8053[20];
  int * v8055 = v8048->regs;
  int v10634 = v8052 | v8054;
  v8055[9] = v10634;
  struct StateT * v10626 = v8057(v8048);
  return v10626;
}

struct StateT * v8461(struct StateT * v8462) {
  int v8463 = v8462->timer;
  int v10147 = v8463 + 1;
  v8462->timer = v10147;int * v8465 = v8462->regs;
  int v8466 = v8465[11];
  int * v8467 = v8462->regs;
  int v8468 = v8467[16];
  int * v8469 = v8462->regs;
  int v10154 = v8466 ^ v8468;
  v8469[20] = v10154;
  struct StateT * v10145 = v8471(v8462);
  return v10145;
}

struct StateT * v495(struct StateT * v496) {
  int v497 = v496->timer;
  int v13155 = v497 + 1;
  v496->timer = v13155;int * v499 = v496->regs;
  int v500 = v499[2];
  int * v501 = v496->regs;
  int v502 = v501[24];
  int * v503 = v496->cache_keys;
  int v504 = v503[0];
  bool v13162 = v504 == ((int)((unsigned int)(v500 + 56) >> 2));
  int v548 = (v13162 ? ({
    int * v505 = v496->cache_vals;
    v505[0] = v502;
    v502;
  }) : ({
    int * v508 = v496->cache_keys;
    int v509 = v508[1];
    bool v13167 = v509 == ((int)((unsigned int)(v500 + 56) >> 2));
    int v546 = (v13167 ? ({
      int * v510 = v496->cache_keys;
      int * v511 = v496->cache_keys;
      int v512 = v511[0];
      v510[1] = v512;
      int * v514 = v496->cache_vals;
      int * v515 = v496->cache_vals;
      int v516 = v515[0];
      v514[1] = v516;
      int * v518 = v496->cache_keys;
      int v13175 = (int)((unsigned int)(v500 + 56) >> 2);
      v518[0] = v13175;
      int * v520 = v496->cache_vals;
      v520[0] = v502;
      int v522 = v496->timer;
      int v13178 = v522 + 1;
      v496->timer = v13178;v502;
    }) : ({
      int * v525 = v496->mem;
      int * v526 = v496->cache_keys;
      int v527 = v526[1];
      int * v528 = v496->cache_vals;
      int v529 = v528[1];
      v525[v527] = v529;
      int * v531 = v496->cache_keys;
      int * v532 = v496->cache_keys;
      int v533 = v532[0];
      v531[1] = v533;
      int * v535 = v496->cache_vals;
      int * v536 = v496->cache_vals;
      int v537 = v536[0];
      v535[1] = v537;
      int * v539 = v496->cache_keys;
      int v13191 = (int)((unsigned int)(v500 + 56) >> 2);
      v539[0] = v13191;
      int * v541 = v496->cache_vals;
      v541[0] = v502;
      int v543 = v496->timer;
      int v13194 = v543 + 100;
      v496->timer = v13194;v502;
    }));
    v546;
  }));
  struct StateT * v13153 = v549(v496);
  return v13153;
}

struct StateT * v8491(struct StateT * v8492) {
  int v8493 = v8492->timer;
  int v10113 = v8493 + 1;
  v8492->timer = v10113;int * v8495 = v8492->regs;
  int v8496 = v8495[21];
  int * v8497 = v8492->regs;
  int v8498 = v8497[14];
  int * v8499 = v8492->regs;
  int v10120 = v8496 + v8498;
  v8499[15] = v10120;
  struct StateT * v10111 = v8501(v8492);
  return v10111;
}

struct StateT * v1431(struct StateT * v1432) {
  int v1433 = v1432->timer;
  int v12402 = v1433 + 1;
  v1432->timer = v12402;int * v1435 = v1432->regs;
  int v1436 = v1435[12];
  int * v1437 = v1432->regs;
  int v12407 = v1436 + -1947;
  v1437[21] = v12407;
  struct StateT * v12400 = v1439(v1432);
  return v12400;
}

struct StateT * v8307(struct StateT * v8308) {
  int v8309 = v8308->timer;
  int v10326 = v8309 + 1;
  v8308->timer = v10326;int * v8311 = v8308->regs;
  int v8312 = v8311[9];
  int * v8313 = v8308->regs;
  int v8314 = v8313[26];
  int * v8315 = v8308->regs;
  int v10333 = v8312 + v8314;
  v8315[15] = v10333;
  struct StateT * v10324 = v8317(v8308);
  return v10324;
}

struct StateT * v5531(struct StateT * v5532) {
  int v5533 = v5532->timer;
  int v5826 = v5533 + 1;
  v5532->timer = v5826;int * v5535 = v5532->regs;
  int v5536 = v5535[2];
  int * v5537 = v5532->cache_keys;
  int v5538 = v5537[0];
  bool v5831 = v5538 == ((int)((unsigned int)(v5536 + 52) >> 2));
  int v5586 = (v5831 ? ({
    int * v5539 = v5532->cache_vals;
    int v5540 = v5539[0];
    v5540;
  }) : ({
    int * v5542 = v5532->cache_keys;
    int v5543 = v5542[1];
    bool v5836 = v5543 == ((int)((unsigned int)(v5536 + 52) >> 2));
    int v5584 = (v5836 ? ({
      int * v5544 = v5532->cache_vals;
      int v5545 = v5544[1];
      int * v5546 = v5532->cache_keys;
      int * v5547 = v5532->cache_keys;
      int v5548 = v5547[0];
      v5546[1] = v5548;
      int * v5550 = v5532->cache_vals;
      int * v5551 = v5532->cache_vals;
      int v5552 = v5551[0];
      v5550[1] = v5552;
      int * v5554 = v5532->cache_keys;
      int v5845 = (int)((unsigned int)(v5536 + 52) >> 2);
      v5554[0] = v5845;
      int * v5556 = v5532->cache_vals;
      v5556[0] = v5545;
      int v5558 = v5532->timer;
      int v5848 = v5558 + 1;
      v5532->timer = v5848;v5545;
    }) : ({
      int * v5561 = v5532->mem;
      int v5850 = (int)((unsigned int)(v5536 + 52) >> 2);
      int v5562 = v5561[v5850];
      int * v5563 = v5532->mem;
      int * v5564 = v5532->cache_keys;
      int v5565 = v5564[1];
      int * v5566 = v5532->cache_vals;
      int v5567 = v5566[1];
      v5563[v5565] = v5567;
      int * v5569 = v5532->cache_keys;
      int * v5570 = v5532->cache_keys;
      int v5571 = v5570[0];
      v5569[1] = v5571;
      int * v5573 = v5532->cache_vals;
      int * v5574 = v5532->cache_vals;
      int v5575 = v5574[0];
      v5573[1] = v5575;
      int * v5577 = v5532->cache_keys;
      v5577[0] = v5850;
      int * v5579 = v5532->cache_vals;
      v5579[0] = v5562;
      int v5581 = v5532->timer;
      int v5865 = v5581 + 100;
      v5532->timer = v5865;v5562;
    }));
    v5584;
  }));
  int * v5587 = v5532->regs;
  v5587[25] = v5586;
  struct StateT * v5824 = v5589(v5532);
  return v5824;
}

struct StateT * v3663(struct StateT * v3664) {
  int v3665 = v3664->timer;
  int v7416 = v3665 + 1;
  v3664->timer = v7416;int * v3667 = v3664->regs;
  int v3668 = v3667[2];
  int * v3669 = v3664->cache_keys;
  int v3670 = v3669[0];
  bool v7421 = v3670 == ((int)((unsigned int)(v3668 + 24) >> 2));
  int v3718 = (v7421 ? ({
    int * v3671 = v3664->cache_vals;
    int v3672 = v3671[0];
    v3672;
  }) : ({
    int * v3674 = v3664->cache_keys;
    int v3675 = v3674[1];
    bool v7426 = v3675 == ((int)((unsigned int)(v3668 + 24) >> 2));
    int v3716 = (v7426 ? ({
      int * v3676 = v3664->cache_vals;
      int v3677 = v3676[1];
      int * v3678 = v3664->cache_keys;
      int * v3679 = v3664->cache_keys;
      int v3680 = v3679[0];
      v3678[1] = v3680;
      int * v3682 = v3664->cache_vals;
      int * v3683 = v3664->cache_vals;
      int v3684 = v3683[0];
      v3682[1] = v3684;
      int * v3686 = v3664->cache_keys;
      int v7435 = (int)((unsigned int)(v3668 + 24) >> 2);
      v3686[0] = v7435;
      int * v3688 = v3664->cache_vals;
      v3688[0] = v3677;
      int v3690 = v3664->timer;
      int v7438 = v3690 + 1;
      v3664->timer = v7438;v3677;
    }) : ({
      int * v3693 = v3664->mem;
      int v7440 = (int)((unsigned int)(v3668 + 24) >> 2);
      int v3694 = v3693[v7440];
      int * v3695 = v3664->mem;
      int * v3696 = v3664->cache_keys;
      int v3697 = v3696[1];
      int * v3698 = v3664->cache_vals;
      int v3699 = v3698[1];
      v3695[v3697] = v3699;
      int * v3701 = v3664->cache_keys;
      int * v3702 = v3664->cache_keys;
      int v3703 = v3702[0];
      v3701[1] = v3703;
      int * v3705 = v3664->cache_vals;
      int * v3706 = v3664->cache_vals;
      int v3707 = v3706[0];
      v3705[1] = v3707;
      int * v3709 = v3664->cache_keys;
      v3709[0] = v7440;
      int * v3711 = v3664->cache_vals;
      v3711[0] = v3694;
      int v3713 = v3664->timer;
      int v7455 = v3713 + 100;
      v3664->timer = v7455;v3694;
    }));
    v3716;
  }));
  int * v3719 = v3664->regs;
  v3719[7] = v3718;
  struct StateT * v7414 = v3721(v3664);
  return v7414;
}

struct StateT * v1799(struct StateT * v1800) {
  int v1801 = v1800->timer;
  int v12043 = v1801 + 1;
  v1800->timer = v12043;int * v1803 = v1800->regs;
  int v1804 = v1803[2];
  int * v1805 = v1800->regs;
  int v1806 = v1805[17];
  int * v1807 = v1800->cache_keys;
  int v1808 = v1807[0];
  bool v12050 = v1808 == ((int)((unsigned int)(v1804 + 28) >> 2));
  int v1852 = (v12050 ? ({
    int * v1809 = v1800->cache_vals;
    v1809[0] = v1806;
    v1806;
  }) : ({
    int * v1812 = v1800->cache_keys;
    int v1813 = v1812[1];
    bool v12055 = v1813 == ((int)((unsigned int)(v1804 + 28) >> 2));
    int v1850 = (v12055 ? ({
      int * v1814 = v1800->cache_keys;
      int * v1815 = v1800->cache_keys;
      int v1816 = v1815[0];
      v1814[1] = v1816;
      int * v1818 = v1800->cache_vals;
      int * v1819 = v1800->cache_vals;
      int v1820 = v1819[0];
      v1818[1] = v1820;
      int * v1822 = v1800->cache_keys;
      int v12063 = (int)((unsigned int)(v1804 + 28) >> 2);
      v1822[0] = v12063;
      int * v1824 = v1800->cache_vals;
      v1824[0] = v1806;
      int v1826 = v1800->timer;
      int v12066 = v1826 + 1;
      v1800->timer = v12066;v1806;
    }) : ({
      int * v1829 = v1800->mem;
      int * v1830 = v1800->cache_keys;
      int v1831 = v1830[1];
      int * v1832 = v1800->cache_vals;
      int v1833 = v1832[1];
      v1829[v1831] = v1833;
      int * v1835 = v1800->cache_keys;
      int * v1836 = v1800->cache_keys;
      int v1837 = v1836[0];
      v1835[1] = v1837;
      int * v1839 = v1800->cache_vals;
      int * v1840 = v1800->cache_vals;
      int v1841 = v1840[0];
      v1839[1] = v1841;
      int * v1843 = v1800->cache_keys;
      int v12079 = (int)((unsigned int)(v1804 + 28) >> 2);
      v1843[0] = v12079;
      int * v1845 = v1800->cache_vals;
      v1845[0] = v1806;
      int v1847 = v1800->timer;
      int v12082 = v1847 + 100;
      v1800->timer = v12082;v1806;
    }));
    v1850;
  }));
  struct StateT * v12041 = v1853(v1800);
  return v12041;
}

struct StateT * v9109(struct StateT * v9110) {
  int v9111 = v9110->timer;
  int v9397 = v9111 + 1;
  v9110->timer = v9397;int * v9113 = v9110->regs;
  int v9114 = v9113[15];
  int * v9115 = v9110->regs;
  int v9402 = (int)((unsigned int)v9114 >> 14);
  v9115[9] = v9402;
  struct StateT * v9395 = v9117(v9110);
  return v9395;
}

struct StateT * v117(struct StateT * v118) {
  int v119 = v118->timer;
  int v13470 = v119 + 1;
  v118->timer = v13470;int * v121 = v118->regs;
  int v122 = v121[2];
  int * v123 = v118->regs;
  int v124 = v123[9];
  int * v125 = v118->cache_keys;
  int v126 = v125[0];
  bool v13477 = v126 == ((int)((unsigned int)(v122 + 84) >> 2));
  int v170 = (v13477 ? ({
    int * v127 = v118->cache_vals;
    v127[0] = v124;
    v124;
  }) : ({
    int * v130 = v118->cache_keys;
    int v131 = v130[1];
    bool v13482 = v131 == ((int)((unsigned int)(v122 + 84) >> 2));
    int v168 = (v13482 ? ({
      int * v132 = v118->cache_keys;
      int * v133 = v118->cache_keys;
      int v134 = v133[0];
      v132[1] = v134;
      int * v136 = v118->cache_vals;
      int * v137 = v118->cache_vals;
      int v138 = v137[0];
      v136[1] = v138;
      int * v140 = v118->cache_keys;
      int v13490 = (int)((unsigned int)(v122 + 84) >> 2);
      v140[0] = v13490;
      int * v142 = v118->cache_vals;
      v142[0] = v124;
      int v144 = v118->timer;
      int v13493 = v144 + 1;
      v118->timer = v13493;v124;
    }) : ({
      int * v147 = v118->mem;
      int * v148 = v118->cache_keys;
      int v149 = v148[1];
      int * v150 = v118->cache_vals;
      int v151 = v150[1];
      v147[v149] = v151;
      int * v153 = v118->cache_keys;
      int * v154 = v118->cache_keys;
      int v155 = v154[0];
      v153[1] = v155;
      int * v157 = v118->cache_vals;
      int * v158 = v118->cache_vals;
      int v159 = v158[0];
      v157[1] = v159;
      int * v161 = v118->cache_keys;
      int v13506 = (int)((unsigned int)(v122 + 84) >> 2);
      v161[0] = v13506;
      int * v163 = v118->cache_vals;
      v163[0] = v124;
      int v165 = v118->timer;
      int v13509 = v165 + 100;
      v118->timer = v13509;v124;
    }));
    v168;
  }));
  struct StateT * v13468 = v171(v118);
  return v13468;
}

struct StateT * v5713(struct StateT * v5714) {
  int v5715 = v5714->timer;
  int v5718 = v5715 + 1;
  v5714->timer = v5718;return v5714;
}

struct StateT * v9083(struct StateT * v9084) {
  int v9085 = v9084->timer;
  int v9427 = v9085 + 1;
  v9084->timer = v9427;int * v9087 = v9084->regs;
  int v9088 = v9087[11];
  int * v9089 = v9084->regs;
  int v9432 = (int)((unsigned int)v9088 >> 14);
  v9089[9] = v9432;
  struct StateT * v9425 = v9091(v9084);
  return v9425;
}

struct StateT * v9(struct StateT * v10) {
  int v11 = v10->timer;
  int v13560 = v11 + 1;
  v10->timer = v13560;int * v13 = v10->regs;
  int v14 = v13[2];
  int * v15 = v10->regs;
  int v16 = v15[1];
  int * v17 = v10->cache_keys;
  int v18 = v17[0];
  bool v13567 = v18 == ((int)((unsigned int)(v14 + 92) >> 2));
  int v62 = (v13567 ? ({
    int * v19 = v10->cache_vals;
    v19[0] = v16;
    v16;
  }) : ({
    int * v22 = v10->cache_keys;
    int v23 = v22[1];
    bool v13571 = v23 == ((int)((unsigned int)(v14 + 92) >> 2));
    int v60 = (v13571 ? ({
      int * v24 = v10->cache_keys;
      int * v25 = v10->cache_keys;
      int v26 = v25[0];
      v24[1] = v26;
      int * v28 = v10->cache_vals;
      int * v29 = v10->cache_vals;
      int v30 = v29[0];
      v28[1] = v30;
      int * v32 = v10->cache_keys;
      int v13579 = (int)((unsigned int)(v14 + 92) >> 2);
      v32[0] = v13579;
      int * v34 = v10->cache_vals;
      v34[0] = v16;
      int v36 = v10->timer;
      int v13582 = v36 + 1;
      v10->timer = v13582;v16;
    }) : ({
      int * v39 = v10->mem;
      int * v40 = v10->cache_keys;
      int v41 = v40[1];
      int * v42 = v10->cache_vals;
      int v43 = v42[1];
      v39[v41] = v43;
      int * v45 = v10->cache_keys;
      int * v46 = v10->cache_keys;
      int v47 = v46[0];
      v45[1] = v47;
      int * v49 = v10->cache_vals;
      int * v50 = v10->cache_vals;
      int v51 = v50[0];
      v49[1] = v51;
      int * v53 = v10->cache_keys;
      int v13595 = (int)((unsigned int)(v14 + 92) >> 2);
      v53[0] = v13595;
      int * v55 = v10->cache_vals;
      v55[0] = v16;
      int v57 = v10->timer;
      int v13598 = v57 + 100;
      v10->timer = v13598;v16;
    }));
    v60;
  }));
  struct StateT * v13558 = v63(v10);
  return v13558;
}

struct StateT * v3349(struct StateT * v3350) {
  int v3351 = v3350->timer;
  int v7738 = v3351 + 1;
  v3350->timer = v7738;int * v3353 = v3350->regs;
  int v3354 = v3353[23];
  int * v3355 = v3350->regs;
  int v3356 = v3355[29];
  int * v3357 = v3350->regs;
  int v7744 = v3354 + v3356;
  v3357[29] = v7744;
  struct StateT * v7736 = v3359(v3350);
  return v7736;
}

struct StateT * v1007(struct StateT * v1008) {
  int v1009 = v1008->timer;
  int v12724 = v1009 + 1;
  v1008->timer = v12724;int * v1011 = v1008->regs;
  int v1012 = v1011[12];
  int * v1013 = v1008->cache_keys;
  int v1014 = v1013[0];
  bool v12729 = v1014 == ((int)((unsigned int)(v1012 + 20) >> 2));
  int v1062 = (v12729 ? ({
    int * v1015 = v1008->cache_vals;
    int v1016 = v1015[0];
    v1016;
  }) : ({
    int * v1018 = v1008->cache_keys;
    int v1019 = v1018[1];
    bool v12734 = v1019 == ((int)((unsigned int)(v1012 + 20) >> 2));
    int v1060 = (v12734 ? ({
      int * v1020 = v1008->cache_vals;
      int v1021 = v1020[1];
      int * v1022 = v1008->cache_keys;
      int * v1023 = v1008->cache_keys;
      int v1024 = v1023[0];
      v1022[1] = v1024;
      int * v1026 = v1008->cache_vals;
      int * v1027 = v1008->cache_vals;
      int v1028 = v1027[0];
      v1026[1] = v1028;
      int * v1030 = v1008->cache_keys;
      int v12743 = (int)((unsigned int)(v1012 + 20) >> 2);
      v1030[0] = v12743;
      int * v1032 = v1008->cache_vals;
      v1032[0] = v1021;
      int v1034 = v1008->timer;
      int v12746 = v1034 + 1;
      v1008->timer = v12746;v1021;
    }) : ({
      int * v1037 = v1008->mem;
      int v12748 = (int)((unsigned int)(v1012 + 20) >> 2);
      int v1038 = v1037[v12748];
      int * v1039 = v1008->mem;
      int * v1040 = v1008->cache_keys;
      int v1041 = v1040[1];
      int * v1042 = v1008->cache_vals;
      int v1043 = v1042[1];
      v1039[v1041] = v1043;
      int * v1045 = v1008->cache_keys;
      int * v1046 = v1008->cache_keys;
      int v1047 = v1046[0];
      v1045[1] = v1047;
      int * v1049 = v1008->cache_vals;
      int * v1050 = v1008->cache_vals;
      int v1051 = v1050[0];
      v1049[1] = v1051;
      int * v1053 = v1008->cache_keys;
      v1053[0] = v12748;
      int * v1055 = v1008->cache_vals;
      v1055[0] = v1038;
      int v1057 = v1008->timer;
      int v12763 = v1057 + 100;
      v1008->timer = v12763;v1038;
    }));
    v1060;
  }));
  int * v1063 = v1008->regs;
  v1063[16] = v1062;
  struct StateT * v12722 = v1065(v1008);
  return v12722;
}

struct StateT * v8993(struct StateT * v8994) {
  int v8995 = v8994->timer;
  int v9529 = v8995 + 1;
  v8994->timer = v9529;int * v8997 = v8994->regs;
  int v8998 = v8997[8];
  int * v8999 = v8994->regs;
  int v9000 = v8999[9];
  int * v9001 = v8994->regs;
  int v9535 = v8998 | v9000;
  v9001[8] = v9535;
  struct StateT * v9527 = v9003(v8994);
  return v9527;
}

struct StateT * v5647(struct StateT * v5648) {
  int v5649 = v5648->timer;
  int v5730 = v5649 + 1;
  v5648->timer = v5730;int * v5651 = v5648->regs;
  int v5652 = v5651[2];
  int * v5653 = v5648->cache_keys;
  int v5654 = v5653[0];
  bool v5735 = v5654 == ((int)((unsigned int)(v5652 + 44) >> 2));
  int v5702 = (v5735 ? ({
    int * v5655 = v5648->cache_vals;
    int v5656 = v5655[0];
    v5656;
  }) : ({
    int * v5658 = v5648->cache_keys;
    int v5659 = v5658[1];
    bool v5740 = v5659 == ((int)((unsigned int)(v5652 + 44) >> 2));
    int v5700 = (v5740 ? ({
      int * v5660 = v5648->cache_vals;
      int v5661 = v5660[1];
      int * v5662 = v5648->cache_keys;
      int * v5663 = v5648->cache_keys;
      int v5664 = v5663[0];
      v5662[1] = v5664;
      int * v5666 = v5648->cache_vals;
      int * v5667 = v5648->cache_vals;
      int v5668 = v5667[0];
      v5666[1] = v5668;
      int * v5670 = v5648->cache_keys;
      int v5749 = (int)((unsigned int)(v5652 + 44) >> 2);
      v5670[0] = v5749;
      int * v5672 = v5648->cache_vals;
      v5672[0] = v5661;
      int v5674 = v5648->timer;
      int v5752 = v5674 + 1;
      v5648->timer = v5752;v5661;
    }) : ({
      int * v5677 = v5648->mem;
      int v5754 = (int)((unsigned int)(v5652 + 44) >> 2);
      int v5678 = v5677[v5754];
      int * v5679 = v5648->mem;
      int * v5680 = v5648->cache_keys;
      int v5681 = v5680[1];
      int * v5682 = v5648->cache_vals;
      int v5683 = v5682[1];
      v5679[v5681] = v5683;
      int * v5685 = v5648->cache_keys;
      int * v5686 = v5648->cache_keys;
      int v5687 = v5686[0];
      v5685[1] = v5687;
      int * v5689 = v5648->cache_vals;
      int * v5690 = v5648->cache_vals;
      int v5691 = v5690[0];
      v5689[1] = v5691;
      int * v5693 = v5648->cache_keys;
      v5693[0] = v5754;
      int * v5695 = v5648->cache_vals;
      v5695[0] = v5678;
      int v5697 = v5648->timer;
      int v5769 = v5697 + 100;
      v5648->timer = v5769;v5678;
    }));
    v5700;
  }));
  int * v5703 = v5648->regs;
  v5703[27] = v5702;
  struct StateT * v5728 = v5705(v5648);
  return v5728;
}

struct StateT * v8783(struct StateT * v8784) {
  int v8785 = v8784->timer;
  int v9771 = v8785 + 1;
  v8784->timer = v9771;int * v8787 = v8784->regs;
  int v8788 = v8787[6];
  int * v8789 = v8784->regs;
  int v8790 = v8789[9];
  int * v8791 = v8784->regs;
  int v9777 = v8788 | v8790;
  v8791[6] = v9777;
  struct StateT * v9769 = v8793(v8784);
  return v9769;
}

struct StateT * v9169(struct StateT * v9170) {
  int v9171 = v9170->timer;
  int v9328 = v9171 + 1;
  v9170->timer = v9328;int * v9173 = v9170->regs;
  int v9174 = v9173[8];
  int * v9175 = v9170->regs;
  int v9332 = v9174 << 18;
  v9175[8] = v9332;
  struct StateT * v9326 = v9177(v9170);
  return v9326;
}

struct StateT * v8907(struct StateT * v8908) {
  int v8909 = v8908->timer;
  int v9630 = v8909 + 1;
  v8908->timer = v9630;int * v8911 = v8908->regs;
  int v8912 = v8911[11];
  int * v8913 = v8908->regs;
  int v9634 = v8912 << 13;
  v8913[11] = v9634;
  struct StateT * v9628 = v8915(v8908);
  return v9628;
}

struct StateT * v7821(struct StateT * v7822) {
  int v7823 = v7822->timer;
  int v10890 = v7823 + 1;
  v7822->timer = v10890;int * v7825 = v7822->regs;
  int v7826 = v7825[20];
  int * v7827 = v7822->regs;
  int v10895 = (int)((unsigned int)v7826 >> 25);
  v7827[9] = v10895;
  struct StateT * v10888 = v7829(v7822);
  return v10888;
}

struct StateT * v1529(struct StateT * v1530) {
  int v1531 = v1530->timer;
  int v12267 = v1531 + 1;
  v1530->timer = v12267;int * v1533 = v1530->regs;
  int v1534 = v1533[2];
  int * v1535 = v1530->regs;
  int v1536 = v1535[25];
  int * v1537 = v1530->cache_keys;
  int v1538 = v1537[0];
  bool v12274 = v1538 == ((int)((unsigned int)(v1534 + 16) >> 2));
  int v1582 = (v12274 ? ({
    int * v1539 = v1530->cache_vals;
    v1539[0] = v1536;
    v1536;
  }) : ({
    int * v1542 = v1530->cache_keys;
    int v1543 = v1542[1];
    bool v12279 = v1543 == ((int)((unsigned int)(v1534 + 16) >> 2));
    int v1580 = (v12279 ? ({
      int * v1544 = v1530->cache_keys;
      int * v1545 = v1530->cache_keys;
      int v1546 = v1545[0];
      v1544[1] = v1546;
      int * v1548 = v1530->cache_vals;
      int * v1549 = v1530->cache_vals;
      int v1550 = v1549[0];
      v1548[1] = v1550;
      int * v1552 = v1530->cache_keys;
      int v12287 = (int)((unsigned int)(v1534 + 16) >> 2);
      v1552[0] = v12287;
      int * v1554 = v1530->cache_vals;
      v1554[0] = v1536;
      int v1556 = v1530->timer;
      int v12290 = v1556 + 1;
      v1530->timer = v12290;v1536;
    }) : ({
      int * v1559 = v1530->mem;
      int * v1560 = v1530->cache_keys;
      int v1561 = v1560[1];
      int * v1562 = v1530->cache_vals;
      int v1563 = v1562[1];
      v1559[v1561] = v1563;
      int * v1565 = v1530->cache_keys;
      int * v1566 = v1530->cache_keys;
      int v1567 = v1566[0];
      v1565[1] = v1567;
      int * v1569 = v1530->cache_vals;
      int * v1570 = v1530->cache_vals;
      int v1571 = v1570[0];
      v1569[1] = v1571;
      int * v1573 = v1530->cache_keys;
      int v12303 = (int)((unsigned int)(v1534 + 16) >> 2);
      v1573[0] = v12303;
      int * v1575 = v1530->cache_vals;
      v1575[0] = v1536;
      int v1577 = v1530->timer;
      int v12306 = v1577 + 100;
      v1530->timer = v12306;v1536;
    }));
    v1580;
  }));
  struct StateT * v12265 = v1583(v1530);
  return v12265;
}

struct StateT * v8133(struct StateT * v8134) {
  int v8135 = v8134->timer;
  int v10530 = v8135 + 1;
  v8134->timer = v10530;int * v8137 = v8134->regs;
  int v8138 = v8137[24];
  int * v8139 = v8134->regs;
  int v8140 = v8139[13];
  int * v8141 = v8134->regs;
  int v10537 = v8138 + v8140;
  v8141[8] = v10537;
  struct StateT * v10528 = v8143(v8134);
  return v10528;
}

struct StateT * v1181(struct StateT * v1182) {
  int v1183 = v1182->timer;
  int v12580 = v1183 + 1;
  v1182->timer = v12580;int * v1185 = v1182->regs;
  int v1186 = v1185[11];
  int * v1187 = v1182->cache_keys;
  int v1188 = v1187[0];
  bool v12585 = v1188 == ((int)((unsigned int)v1186 >> 2));
  int v1236 = (v12585 ? ({
    int * v1189 = v1182->cache_vals;
    int v1190 = v1189[0];
    v1190;
  }) : ({
    int * v1192 = v1182->cache_keys;
    int v1193 = v1192[1];
    bool v12590 = v1193 == ((int)((unsigned int)v1186 >> 2));
    int v1234 = (v12590 ? ({
      int * v1194 = v1182->cache_vals;
      int v1195 = v1194[1];
      int * v1196 = v1182->cache_keys;
      int * v1197 = v1182->cache_keys;
      int v1198 = v1197[0];
      v1196[1] = v1198;
      int * v1200 = v1182->cache_vals;
      int * v1201 = v1182->cache_vals;
      int v1202 = v1201[0];
      v1200[1] = v1202;
      int * v1204 = v1182->cache_keys;
      int v12599 = (int)((unsigned int)v1186 >> 2);
      v1204[0] = v12599;
      int * v1206 = v1182->cache_vals;
      v1206[0] = v1195;
      int v1208 = v1182->timer;
      int v12602 = v1208 + 1;
      v1182->timer = v12602;v1195;
    }) : ({
      int * v1211 = v1182->mem;
      int v12604 = (int)((unsigned int)v1186 >> 2);
      int v1212 = v1211[v12604];
      int * v1213 = v1182->mem;
      int * v1214 = v1182->cache_keys;
      int v1215 = v1214[1];
      int * v1216 = v1182->cache_vals;
      int v1217 = v1216[1];
      v1213[v1215] = v1217;
      int * v1219 = v1182->cache_keys;
      int * v1220 = v1182->cache_keys;
      int v1221 = v1220[0];
      v1219[1] = v1221;
      int * v1223 = v1182->cache_vals;
      int * v1224 = v1182->cache_vals;
      int v1225 = v1224[0];
      v1223[1] = v1225;
      int * v1227 = v1182->cache_keys;
      v1227[0] = v12604;
      int * v1229 = v1182->cache_vals;
      v1229[0] = v1212;
      int v1231 = v1182->timer;
      int v12619 = v1231 + 100;
      v1182->timer = v12619;v1212;
    }));
    v1234;
  }));
  int * v1237 = v1182->regs;
  v1237[5] = v1236;
  struct StateT * v12578 = v1239(v1182);
  return v12578;
}

struct StateT * v8031(struct StateT * v8032) {
  int v8033 = v8032->timer;
  int v10648 = v8033 + 1;
  v8032->timer = v10648;int * v8035 = v8032->regs;
  int v8036 = v8035[9];
  int * v8037 = v8032->regs;
  int v10653 = (int)((unsigned int)v8036 >> 23);
  v8037[20] = v10653;
  struct StateT * v10646 = v8039(v8032);
  return v10646;
}

struct StateT * v8013(struct StateT * v8014) {
  int v8015 = v8014->timer;
  int v10669 = v8015 + 1;
  v8014->timer = v10669;int * v8017 = v8014->regs;
  int v8018 = v8017[8];
  int * v8019 = v8014->regs;
  int v10673 = v8018 << 9;
  v8019[8] = v10673;
  struct StateT * v10667 = v8021(v8014);
  return v10667;
}

struct StateT * v7919(struct StateT * v7920) {
  int v7921 = v7920->timer;
  int v10777 = v7921 + 1;
  v7920->timer = v10777;int * v7923 = v7920->regs;
  int v7924 = v7923[1];
  int * v7925 = v7920->regs;
  int v7926 = v7925[18];
  int * v7927 = v7920->regs;
  int v10783 = v7924 ^ v7926;
  v7927[1] = v10783;
  struct StateT * v10775 = v7929(v7920);
  return v10775;
}

struct StateT * v8675(struct StateT * v8676) {
  int v8677 = v8676->timer;
  int v9897 = v8677 + 1;
  v8676->timer = v9897;int * v8679 = v8676->regs;
  int v8680 = v8679[23];
  int * v8681 = v8676->regs;
  int v8682 = v8681[21];
  int * v8683 = v8676->regs;
  int v9904 = v8680 + v8682;
  v8683[11] = v9904;
  struct StateT * v9895 = v8685(v8676);
  return v9895;
}

struct StateT * v8057(struct StateT * v8058) {
  int v8059 = v8058->timer;
  int v10618 = v8059 + 1;
  v8058->timer = v10618;int * v8061 = v8058->regs;
  int v8062 = v8061[18];
  int * v8063 = v8058->regs;
  int v10623 = (int)((unsigned int)v8062 >> 23);
  v8063[20] = v10623;
  struct StateT * v10616 = v8065(v8058);
  return v10616;
}

struct StateT * v7775(struct StateT * v7776) {
  int v7777 = v7776->timer;
  int v10942 = v7777 + 1;
  v7776->timer = v10942;int * v7779 = v7776->regs;
  int v7780 = v7779[19];
  int * v7781 = v7776->regs;
  int v7782 = v7781[5];
  int * v7783 = v7776->regs;
  int v10949 = v7780 + v7782;
  v7783[18] = v10949;
  struct StateT * v10940 = v7785(v7776);
  return v10940;
}

struct StateT * v7847(struct StateT * v7848) {
  int v7849 = v7848->timer;
  int v10860 = v7849 + 1;
  v7848->timer = v10860;int * v7851 = v7848->regs;
  int v7852 = v7851[18];
  int * v7853 = v7848->regs;
  int v10865 = (int)((unsigned int)v7852 >> 25);
  v7853[20] = v10865;
  struct StateT * v10858 = v7855(v7848);
  return v10858;
}

struct StateT * v4897(struct StateT * v4898) {
  int v4899 = v4898->timer;
  int v6354 = v4899 + 1;
  v4898->timer = v6354;int * v4901 = v4898->regs;
  int v4902 = v4901[10];
  int * v4903 = v4898->regs;
  int v4904 = v4903[30];
  int * v4905 = v4898->cache_keys;
  int v4906 = v4905[0];
  bool v6361 = v4906 == ((int)((unsigned int)(v4902 + 60) >> 2));
  int v4950 = (v6361 ? ({
    int * v4907 = v4898->cache_vals;
    v4907[0] = v4904;
    v4904;
  }) : ({
    int * v4910 = v4898->cache_keys;
    int v4911 = v4910[1];
    bool v6366 = v4911 == ((int)((unsigned int)(v4902 + 60) >> 2));
    int v4948 = (v6366 ? ({
      int * v4912 = v4898->cache_keys;
      int * v4913 = v4898->cache_keys;
      int v4914 = v4913[0];
      v4912[1] = v4914;
      int * v4916 = v4898->cache_vals;
      int * v4917 = v4898->cache_vals;
      int v4918 = v4917[0];
      v4916[1] = v4918;
      int * v4920 = v4898->cache_keys;
      int v6374 = (int)((unsigned int)(v4902 + 60) >> 2);
      v4920[0] = v6374;
      int * v4922 = v4898->cache_vals;
      v4922[0] = v4904;
      int v4924 = v4898->timer;
      int v6377 = v4924 + 1;
      v4898->timer = v6377;v4904;
    }) : ({
      int * v4927 = v4898->mem;
      int * v4928 = v4898->cache_keys;
      int v4929 = v4928[1];
      int * v4930 = v4898->cache_vals;
      int v4931 = v4930[1];
      v4927[v4929] = v4931;
      int * v4933 = v4898->cache_keys;
      int * v4934 = v4898->cache_keys;
      int v4935 = v4934[0];
      v4933[1] = v4935;
      int * v4937 = v4898->cache_vals;
      int * v4938 = v4898->cache_vals;
      int v4939 = v4938[0];
      v4937[1] = v4939;
      int * v4941 = v4898->cache_keys;
      int v6390 = (int)((unsigned int)(v4902 + 60) >> 2);
      v4941[0] = v6390;
      int * v4943 = v4898->cache_vals;
      v4943[0] = v4904;
      int v4945 = v4898->timer;
      int v6393 = v4945 + 100;
      v4898->timer = v6393;v4904;
    }));
    v4948;
  }));
  struct StateT * v6352 = v4951(v4898);
  return v6352;
}

struct StateT * v9235(struct StateT * v9236) {
  int v9237 = v9236->timer;
  int v9250 = v9237 + 1;
  v9236->timer = v9250;int * v9239 = v9236->regs;
  int v9240 = v9239[31];
  int * v9241 = v9236->regs;
  int v9242 = v9241[30];
  bool v9255 = (v9240 ^ -2147483648) >= (v9242 ^ -2147483648);
  struct StateT * v9248 = (v9255 ? ({
    struct StateT * v9244 = v7755(v9236);
    v9244;
  }) : ({
    struct StateT * v9246 = v3349(v9236);
    v9246;
  }));
  return v9248;
}

struct StateT * v3863(struct StateT * v3864) {
  int v3865 = v3864->timer;
  int v7279 = v3865 + 1;
  v3864->timer = v7279;int * v3867 = v3864->regs;
  int v3868 = v3867[16];
  int * v3869 = v3864->regs;
  int v3870 = v3869[30];
  int * v3871 = v3864->regs;
  int v7285 = v3868 + v3870;
  v3871[16] = v7285;
  struct StateT * v7277 = v3873(v3864);
  return v7277;
}

struct StateT * v9013(struct StateT * v9014) {
  int v9015 = v9014->timer;
  int v9507 = v9015 + 1;
  v9014->timer = v9507;int * v9017 = v9014->regs;
  int v9018 = v9017[12];
  int * v9019 = v9014->regs;
  int v9020 = v9019[15];
  int * v9021 = v9014->regs;
  int v9513 = v9018 ^ v9020;
  v9021[12] = v9513;
  struct StateT * v9505 = v9023(v9014);
  return v9505;
}

struct StateT * v8153(struct StateT * v8154) {
  int v8155 = v8154->timer;
  int v10506 = v8155 + 1;
  v8154->timer = v10506;int * v8157 = v8154->regs;
  int v8158 = v8157[25];
  int * v8159 = v8154->regs;
  int v8160 = v8159[14];
  int * v8161 = v8154->regs;
  int v10513 = v8158 + v8160;
  v8161[18] = v10513;
  struct StateT * v10504 = v8163(v8154);
  return v10504;
}

struct StateT * v4047(struct StateT * v4048) {
  int v4049 = v4048->timer;
  int v7106 = v4049 + 1;
  v4048->timer = v7106;int * v4051 = v4048->regs;
  int v4052 = v4051[21];
  int * v4053 = v4048->regs;
  int v4054 = v4053[15];
  int * v4055 = v4048->regs;
  int v7112 = v4052 + v4054;
  v4055[15] = v7112;
  struct StateT * v7104 = v4057(v4048);
  return v7104;
}

struct StateT * v1455(struct StateT * v1456) {
  int v1457 = v1456->timer;
  int v12374 = v1457 + 1;
  v1456->timer = v12374;int * v1459 = v1456->regs;
  v1459[22] = 1797283840;
  struct StateT * v12372 = v1461(v1456);
  return v12372;
}

struct StateT * v1853(struct StateT * v1854) {
  int v1855 = v1854->timer;
  int v11998 = v1855 + 1;
  v1854->timer = v11998;int * v1857 = v1854->regs;
  int v1858 = v1857[2];
  int * v1859 = v1854->regs;
  int v1860 = v1859[6];
  int * v1861 = v1854->cache_keys;
  int v1862 = v1861[0];
  bool v12005 = v1862 == ((int)((unsigned int)(v1858 + 8) >> 2));
  int v1906 = (v12005 ? ({
    int * v1863 = v1854->cache_vals;
    v1863[0] = v1860;
    v1860;
  }) : ({
    int * v1866 = v1854->cache_keys;
    int v1867 = v1866[1];
    bool v12010 = v1867 == ((int)((unsigned int)(v1858 + 8) >> 2));
    int v1904 = (v12010 ? ({
      int * v1868 = v1854->cache_keys;
      int * v1869 = v1854->cache_keys;
      int v1870 = v1869[0];
      v1868[1] = v1870;
      int * v1872 = v1854->cache_vals;
      int * v1873 = v1854->cache_vals;
      int v1874 = v1873[0];
      v1872[1] = v1874;
      int * v1876 = v1854->cache_keys;
      int v12018 = (int)((unsigned int)(v1858 + 8) >> 2);
      v1876[0] = v12018;
      int * v1878 = v1854->cache_vals;
      v1878[0] = v1860;
      int v1880 = v1854->timer;
      int v12021 = v1880 + 1;
      v1854->timer = v12021;v1860;
    }) : ({
      int * v1883 = v1854->mem;
      int * v1884 = v1854->cache_keys;
      int v1885 = v1884[1];
      int * v1886 = v1854->cache_vals;
      int v1887 = v1886[1];
      v1883[v1885] = v1887;
      int * v1889 = v1854->cache_keys;
      int * v1890 = v1854->cache_keys;
      int v1891 = v1890[0];
      v1889[1] = v1891;
      int * v1893 = v1854->cache_vals;
      int * v1894 = v1854->cache_vals;
      int v1895 = v1894[0];
      v1893[1] = v1895;
      int * v1897 = v1854->cache_keys;
      int v12034 = (int)((unsigned int)(v1858 + 8) >> 2);
      v1897[0] = v12034;
      int * v1899 = v1854->cache_vals;
      v1899[0] = v1860;
      int v1901 = v1854->timer;
      int v12037 = v1901 + 100;
      v1854->timer = v12037;v1860;
    }));
    v1904;
  }));
  struct StateT * v11996 = v1907(v1854);
  return v11996;
}

struct StateT * v279(struct StateT * v280) {
  int v281 = v280->timer;
  int v13335 = v281 + 1;
  v280->timer = v13335;int * v283 = v280->regs;
  int v284 = v283[2];
  int * v285 = v280->regs;
  int v286 = v285[20];
  int * v287 = v280->cache_keys;
  int v288 = v287[0];
  bool v13342 = v288 == ((int)((unsigned int)(v284 + 72) >> 2));
  int v332 = (v13342 ? ({
    int * v289 = v280->cache_vals;
    v289[0] = v286;
    v286;
  }) : ({
    int * v292 = v280->cache_keys;
    int v293 = v292[1];
    bool v13347 = v293 == ((int)((unsigned int)(v284 + 72) >> 2));
    int v330 = (v13347 ? ({
      int * v294 = v280->cache_keys;
      int * v295 = v280->cache_keys;
      int v296 = v295[0];
      v294[1] = v296;
      int * v298 = v280->cache_vals;
      int * v299 = v280->cache_vals;
      int v300 = v299[0];
      v298[1] = v300;
      int * v302 = v280->cache_keys;
      int v13355 = (int)((unsigned int)(v284 + 72) >> 2);
      v302[0] = v13355;
      int * v304 = v280->cache_vals;
      v304[0] = v286;
      int v306 = v280->timer;
      int v13358 = v306 + 1;
      v280->timer = v13358;v286;
    }) : ({
      int * v309 = v280->mem;
      int * v310 = v280->cache_keys;
      int v311 = v310[1];
      int * v312 = v280->cache_vals;
      int v313 = v312[1];
      v309[v311] = v313;
      int * v315 = v280->cache_keys;
      int * v316 = v280->cache_keys;
      int v317 = v316[0];
      v315[1] = v317;
      int * v319 = v280->cache_vals;
      int * v320 = v280->cache_vals;
      int v321 = v320[0];
      v319[1] = v321;
      int * v323 = v280->cache_keys;
      int v13371 = (int)((unsigned int)(v284 + 72) >> 2);
      v323[0] = v13371;
      int * v325 = v280->cache_vals;
      v325[0] = v286;
      int v327 = v280->timer;
      int v13374 = v327 + 100;
      v280->timer = v13374;v286;
    }));
    v330;
  }));
  struct StateT * v13333 = v333(v280);
  return v13333;
}

struct StateT * v8287(struct StateT * v8288) {
  int v8289 = v8288->timer;
  int v10350 = v8289 + 1;
  v8288->timer = v10350;int * v8291 = v8288->regs;
  int v8292 = v8291[5];
  int * v8293 = v8288->regs;
  int v8294 = v8293[20];
  int * v8295 = v8288->regs;
  int v10357 = v8292 ^ v8294;
  v8295[18] = v10357;
  struct StateT * v10348 = v8297(v8288);
  return v10348;
}

struct StateT * v8617(struct StateT * v8618) {
  int v8619 = v8618->timer;
  int v9968 = v8619 + 1;
  v8618->timer = v9968;int * v8621 = v8618->regs;
  int v8622 = v8621[17];
  int * v8623 = v8618->regs;
  int v9972 = v8622 << 7;
  v8623[17] = v9972;
  struct StateT * v9966 = v8625(v8618);
  return v9966;
}

struct StateT * v8123(struct StateT * v8124) {
  int v8125 = v8124->timer;
  int v10542 = v8125 + 1;
  v8124->timer = v10542;int * v8127 = v8124->regs;
  int v8128 = v8127[26];
  int * v8129 = v8124->regs;
  int v8130 = v8129[12];
  int * v8131 = v8124->regs;
  int v10549 = v8128 + v8130;
  v8131[15] = v10549;
  struct StateT * v10540 = v8133(v8124);
  return v10540;
}

struct StateT * v8501(struct StateT * v8502) {
  int v8503 = v8502->timer;
  int v10101 = v8503 + 1;
  v8502->timer = v10101;int * v8505 = v8502->regs;
  int v8506 = v8505[20];
  int * v8507 = v8502->regs;
  int v8508 = v8507[12];
  int * v8509 = v8502->regs;
  int v10108 = v8506 + v8508;
  v8509[11] = v10108;
  struct StateT * v10099 = v8511(v8502);
  return v10099;
}

struct StateT * v8481(struct StateT * v8482) {
  int v8483 = v8482->timer;
  int v10125 = v8483 + 1;
  v8482->timer = v10125;int * v8485 = v8482->regs;
  int v8486 = v8485[22];
  int * v8487 = v8482->regs;
  int v8488 = v8487[5];
  int * v8489 = v8482->regs;
  int v10131 = v8486 ^ v8488;
  v8489[22] = v10131;
  struct StateT * v10123 = v8491(v8482);
  return v10123;
}

struct StateT * v7969(struct StateT * v7970) {
  int v7971 = v7970->timer;
  int v10718 = v7971 + 1;
  v7970->timer = v10718;int * v7973 = v7970->regs;
  int v7974 = v7973[14];
  int * v7975 = v7970->regs;
  int v7976 = v7975[22];
  int * v7977 = v7970->regs;
  int v10725 = v7974 + v7976;
  v7977[18] = v10725;
  struct StateT * v10716 = v7979(v7970);
  return v10716;
}

struct StateT * v711(struct StateT * v712) {
  int v713 = v712->timer;
  int v13012 = v713 + 1;
  v712->timer = v13012;int * v715 = v712->regs;
  v715[30] = 0;
  struct StateT * v13010 = v717(v712);
  return v13010;
}

struct StateT * v8093(struct StateT * v8094) {
  int v8095 = v8094->timer;
  int v10576 = v8095 + 1;
  v8094->timer = v10576;int * v8097 = v8094->regs;
  int v8098 = v8097[24];
  int * v8099 = v8094->regs;
  int v8100 = v8099[8];
  int * v8101 = v8094->regs;
  int v10582 = v8098 ^ v8100;
  v8101[24] = v10582;
  struct StateT * v10574 = v8103(v8094);
  return v10574;
}

struct StateT * v8793(struct StateT * v8794) {
  int v8795 = v8794->timer;
  int v9761 = v8795 + 1;
  v8794->timer = v9761;int * v8797 = v8794->regs;
  int v8798 = v8797[8];
  int * v8799 = v8794->regs;
  int v9766 = (int)((unsigned int)v8798 >> 23);
  v8799[9] = v9766;
  struct StateT * v9759 = v8801(v8794);
  return v9759;
}

struct StateT * v7939(struct StateT * v7940) {
  int v7941 = v7940->timer;
  int v10754 = v7941 + 1;
  v7940->timer = v10754;int * v7943 = v7940->regs;
  int v7944 = v7943[12];
  int * v7945 = v7940->regs;
  int v7946 = v7945[21];
  int * v7947 = v7940->regs;
  int v10761 = v7944 + v7946;
  v7947[15] = v10761;
  struct StateT * v10752 = v7949(v7940);
  return v10752;
}

struct StateT * v8441(struct StateT * v8442) {
  int v8443 = v8442->timer;
  int v10170 = v8443 + 1;
  v8442->timer = v10170;int * v8445 = v8442->regs;
  int v8446 = v8445[5];
  int * v8447 = v8442->regs;
  int v8448 = v8447[6];
  int * v8449 = v8442->regs;
  int v10176 = v8446 | v8448;
  v8449[5] = v10176;
  struct StateT * v10168 = v8451(v8442);
  return v10168;
}

struct StateT * v4039(struct StateT * v4040) {
  int v4041 = v4040->timer;
  int v7117 = v4041 + 1;
  v4040->timer = v7117;int * v4043 = v4040->regs;
  int v4044 = v4043[30];
  int * v4045 = v4040->regs;
  int v7121 = v4044 + 1396;
  v4045[30] = v7121;
  struct StateT * v7115 = v4047(v4040);
  return v7115;
}

struct StateT * v8381(struct StateT * v8382) {
  int v8383 = v8382->timer;
  int v10241 = v8383 + 1;
  v8382->timer = v10241;int * v8385 = v8382->regs;
  int v8386 = v8385[16];
  int * v8387 = v8382->regs;
  int v10245 = v8386 << 18;
  v8387[16] = v10245;
  struct StateT * v10239 = v8389(v8382);
  return v10239;
}

struct StateT * v7881(struct StateT * v7882) {
  int v7883 = v7882->timer;
  int v10821 = v7883 + 1;
  v7882->timer = v10821;int * v7885 = v7882->regs;
  int v7886 = v7885[8];
  int * v7887 = v7882->regs;
  int v10825 = v7886 << 7;
  v7887[8] = v10825;
  struct StateT * v10819 = v7889(v7882);
  return v10819;
}

struct StateT * v1923(struct StateT * v1924) {
  int v1925 = v1924->timer;
  int v11968 = v1925 + 1;
  v1924->timer = v11968;int * v1927 = v1924->regs;
  int v1928 = v1927[28];
  int * v1929 = v1924->regs;
  v1929[27] = v1928;
  struct StateT * v11966 = v1931(v1924);
  return v11966;
}

struct StateT * v8433(struct StateT * v8434) {
  int v8435 = v8434->timer;
  int v10181 = v8435 + 1;
  v8434->timer = v10181;int * v8437 = v8434->regs;
  int v8438 = v8437[5];
  int * v8439 = v8434->regs;
  int v10185 = v8438 << 18;
  v8439[5] = v10185;
  struct StateT * v10179 = v8441(v8434);
  return v10179;
}

struct StateT * v8889(struct StateT * v8890) {
  int v8891 = v8890->timer;
  int v9649 = v8891 + 1;
  v8890->timer = v9649;int * v8893 = v8890->regs;
  int v8894 = v8893[24];
  int * v8895 = v8890->regs;
  int v8896 = v8895[16];
  int * v8897 = v8890->regs;
  int v9656 = v8894 + v8896;
  v8897[8] = v9656;
  struct StateT * v9647 = v8899(v8890);
  return v9647;
}

struct StateT * v7929(struct StateT * v7930) {
  int v7931 = v7930->timer;
  int v10766 = v7931 + 1;
  v7930->timer = v10766;int * v7933 = v7930->regs;
  int v7934 = v7933[14];
  int * v7935 = v7930->regs;
  int v7936 = v7935[8];
  int * v7937 = v7930->regs;
  int v10772 = v7934 ^ v7936;
  v7937[14] = v10772;
  struct StateT * v10764 = v7939(v7930);
  return v10764;
}

struct StateT * v1583(struct StateT * v1584) {
  int v1585 = v1584->timer;
  int v12222 = v1585 + 1;
  v1584->timer = v12222;int * v1587 = v1584->regs;
  int v1588 = v1587[2];
  int * v1589 = v1584->regs;
  int v1590 = v1589[5];
  int * v1591 = v1584->cache_keys;
  int v1592 = v1591[0];
  bool v12229 = v1592 == ((int)((unsigned int)(v1588 + 12) >> 2));
  int v1636 = (v12229 ? ({
    int * v1593 = v1584->cache_vals;
    v1593[0] = v1590;
    v1590;
  }) : ({
    int * v1596 = v1584->cache_keys;
    int v1597 = v1596[1];
    bool v12234 = v1597 == ((int)((unsigned int)(v1588 + 12) >> 2));
    int v1634 = (v12234 ? ({
      int * v1598 = v1584->cache_keys;
      int * v1599 = v1584->cache_keys;
      int v1600 = v1599[0];
      v1598[1] = v1600;
      int * v1602 = v1584->cache_vals;
      int * v1603 = v1584->cache_vals;
      int v1604 = v1603[0];
      v1602[1] = v1604;
      int * v1606 = v1584->cache_keys;
      int v12242 = (int)((unsigned int)(v1588 + 12) >> 2);
      v1606[0] = v12242;
      int * v1608 = v1584->cache_vals;
      v1608[0] = v1590;
      int v1610 = v1584->timer;
      int v12245 = v1610 + 1;
      v1584->timer = v12245;v1590;
    }) : ({
      int * v1613 = v1584->mem;
      int * v1614 = v1584->cache_keys;
      int v1615 = v1614[1];
      int * v1616 = v1584->cache_vals;
      int v1617 = v1616[1];
      v1613[v1615] = v1617;
      int * v1619 = v1584->cache_keys;
      int * v1620 = v1584->cache_keys;
      int v1621 = v1620[0];
      v1619[1] = v1621;
      int * v1623 = v1584->cache_vals;
      int * v1624 = v1584->cache_vals;
      int v1625 = v1624[0];
      v1623[1] = v1625;
      int * v1627 = v1584->cache_keys;
      int v12258 = (int)((unsigned int)(v1588 + 12) >> 2);
      v1627[0] = v12258;
      int * v1629 = v1584->cache_vals;
      v1629[0] = v1590;
      int v1631 = v1584->timer;
      int v12261 = v1631 + 100;
      v1584->timer = v12261;v1590;
    }));
    v1634;
  }));
  struct StateT * v12220 = v1637(v1584);
  return v12220;
}

struct StateT * v8511(struct StateT * v8512) {
  int v8513 = v8512->timer;
  int v10089 = v8513 + 1;
  v8512->timer = v10089;int * v8515 = v8512->regs;
  int v8516 = v8515[19];
  int * v8517 = v8512->regs;
  int v8518 = v8517[13];
  int * v8519 = v8512->regs;
  int v10096 = v8516 + v8518;
  v8519[16] = v10096;
  struct StateT * v10087 = v8521(v8512);
  return v10087;
}

struct StateT * v5299(struct StateT * v5300) {
  int v5301 = v5300->timer;
  int v6018 = v5301 + 1;
  v5300->timer = v6018;int * v5303 = v5300->regs;
  int v5304 = v5303[2];
  int * v5305 = v5300->cache_keys;
  int v5306 = v5305[0];
  bool v6023 = v5306 == ((int)((unsigned int)(v5304 + 68) >> 2));
  int v5354 = (v6023 ? ({
    int * v5307 = v5300->cache_vals;
    int v5308 = v5307[0];
    v5308;
  }) : ({
    int * v5310 = v5300->cache_keys;
    int v5311 = v5310[1];
    bool v6028 = v5311 == ((int)((unsigned int)(v5304 + 68) >> 2));
    int v5352 = (v6028 ? ({
      int * v5312 = v5300->cache_vals;
      int v5313 = v5312[1];
      int * v5314 = v5300->cache_keys;
      int * v5315 = v5300->cache_keys;
      int v5316 = v5315[0];
      v5314[1] = v5316;
      int * v5318 = v5300->cache_vals;
      int * v5319 = v5300->cache_vals;
      int v5320 = v5319[0];
      v5318[1] = v5320;
      int * v5322 = v5300->cache_keys;
      int v6037 = (int)((unsigned int)(v5304 + 68) >> 2);
      v5322[0] = v6037;
      int * v5324 = v5300->cache_vals;
      v5324[0] = v5313;
      int v5326 = v5300->timer;
      int v6040 = v5326 + 1;
      v5300->timer = v6040;v5313;
    }) : ({
      int * v5329 = v5300->mem;
      int v6042 = (int)((unsigned int)(v5304 + 68) >> 2);
      int v5330 = v5329[v6042];
      int * v5331 = v5300->mem;
      int * v5332 = v5300->cache_keys;
      int v5333 = v5332[1];
      int * v5334 = v5300->cache_vals;
      int v5335 = v5334[1];
      v5331[v5333] = v5335;
      int * v5337 = v5300->cache_keys;
      int * v5338 = v5300->cache_keys;
      int v5339 = v5338[0];
      v5337[1] = v5339;
      int * v5341 = v5300->cache_vals;
      int * v5342 = v5300->cache_vals;
      int v5343 = v5342[0];
      v5341[1] = v5343;
      int * v5345 = v5300->cache_keys;
      v5345[0] = v6042;
      int * v5347 = v5300->cache_vals;
      v5347[0] = v5330;
      int v5349 = v5300->timer;
      int v6057 = v5349 + 100;
      v5300->timer = v6057;v5330;
    }));
    v5352;
  }));
  int * v5355 = v5300->regs;
  v5355[21] = v5354;
  struct StateT * v6016 = v5357(v5300);
  return v6016;
}

struct StateT * v1931(struct StateT * v1932) {
  int v1933 = v1932->timer;
  int v11958 = v1933 + 1;
  v1932->timer = v11958;int * v1935 = v1932->regs;
  int v1936 = v1935[29];
  int * v1937 = v1932->regs;
  v1937[23] = v1936;
  struct StateT * v11956 = v1939(v1932);
  return v11956;
}

struct StateT * v3731(struct StateT * v3732) {
  int v3733 = v3732->timer;
  int v7397 = v3733 + 1;
  v3732->timer = v7397;int * v3735 = v3732->regs;
  v3735[7] = 2036477952;
  struct StateT * v7395 = v3737(v3732);
  return v7395;
}

struct StateT * v3653(struct StateT * v3654) {
  int v3655 = v3654->timer;
  int v7464 = v3655 + 1;
  v3654->timer = v7464;int * v3657 = v3654->regs;
  int v3658 = v3657[26];
  int * v3659 = v3654->regs;
  int v3660 = v3659[7];
  int * v3661 = v3654->regs;
  int v7470 = v3658 + v3660;
  v3661[26] = v7470;
  struct StateT * v7462 = v3663(v3654);
  return v7462;
}

struct StateT * v3527(struct StateT * v3528) {
  int v3529 = v3528->timer;
  int v7534 = v3529 + 1;
  v3528->timer = v7534;int * v3531 = v3528->regs;
  int v3532 = v3531[2];
  int * v3533 = v3528->cache_keys;
  int v3534 = v3533[0];
  bool v7539 = v3534 == ((int)((unsigned int)(v3532 + 16) >> 2));
  int v3582 = (v7539 ? ({
    int * v3535 = v3528->cache_vals;
    int v3536 = v3535[0];
    v3536;
  }) : ({
    int * v3538 = v3528->cache_keys;
    int v3539 = v3538[1];
    bool v7544 = v3539 == ((int)((unsigned int)(v3532 + 16) >> 2));
    int v3580 = (v7544 ? ({
      int * v3540 = v3528->cache_vals;
      int v3541 = v3540[1];
      int * v3542 = v3528->cache_keys;
      int * v3543 = v3528->cache_keys;
      int v3544 = v3543[0];
      v3542[1] = v3544;
      int * v3546 = v3528->cache_vals;
      int * v3547 = v3528->cache_vals;
      int v3548 = v3547[0];
      v3546[1] = v3548;
      int * v3550 = v3528->cache_keys;
      int v7553 = (int)((unsigned int)(v3532 + 16) >> 2);
      v3550[0] = v7553;
      int * v3552 = v3528->cache_vals;
      v3552[0] = v3541;
      int v3554 = v3528->timer;
      int v7556 = v3554 + 1;
      v3528->timer = v7556;v3541;
    }) : ({
      int * v3557 = v3528->mem;
      int v7558 = (int)((unsigned int)(v3532 + 16) >> 2);
      int v3558 = v3557[v7558];
      int * v3559 = v3528->mem;
      int * v3560 = v3528->cache_keys;
      int v3561 = v3560[1];
      int * v3562 = v3528->cache_vals;
      int v3563 = v3562[1];
      v3559[v3561] = v3563;
      int * v3565 = v3528->cache_keys;
      int * v3566 = v3528->cache_keys;
      int v3567 = v3566[0];
      v3565[1] = v3567;
      int * v3569 = v3528->cache_vals;
      int * v3570 = v3528->cache_vals;
      int v3571 = v3570[0];
      v3569[1] = v3571;
      int * v3573 = v3528->cache_keys;
      v3573[0] = v7558;
      int * v3575 = v3528->cache_vals;
      v3575[0] = v3558;
      int v3577 = v3528->timer;
      int v7573 = v3577 + 100;
      v3528->timer = v7573;v3558;
    }));
    v3580;
  }));
  int * v3583 = v3528->regs;
  v3583[7] = v3582;
  struct StateT * v7532 = v3585(v3528);
  return v7532;
}

struct StateT * v8189(struct StateT * v8190) {
  int v8191 = v8190->timer;
  int v10466 = v8191 + 1;
  v8190->timer = v10466;int * v8193 = v8190->regs;
  int v8194 = v8193[8];
  int * v8195 = v8190->regs;
  int v10471 = (int)((unsigned int)v8194 >> 19);
  v8195[20] = v10471;
  struct StateT * v10464 = v8197(v8190);
  return v10464;
}

struct StateT * v7755(struct StateT * v7756) {
  int v7757 = v7756->timer;
  int v10966 = v7757 + 1;
  v7756->timer = v10966;int * v7759 = v7756->regs;
  int v7760 = v7759[21];
  int * v7761 = v7756->regs;
  int v7762 = v7761[16];
  int * v7763 = v7756->regs;
  int v10973 = v7760 + v7762;
  v7763[15] = v10973;
  struct StateT * v10964 = v7765(v7756);
  return v10964;
}

struct StateT * v3369(struct StateT * v3370) {
  int v3371 = v3370->timer;
  int v7719 = v3371 + 1;
  v3370->timer = v7719;int * v3373 = v3370->regs;
  v3373[15] = 1634762752;
  struct StateT * v7717 = v3375(v3370);
  return v7717;
}

struct StateT * v9217(struct StateT * v9218) {
  int v9219 = v9218->timer;
  int v9272 = v9219 + 1;
  v9218->timer = v9272;int * v9221 = v9218->regs;
  int v9222 = v9221[22];
  int * v9223 = v9218->regs;
  int v9224 = v9223[8];
  int * v9225 = v9218->regs;
  int v9278 = v9222 ^ v9224;
  v9225[22] = v9278;
  struct StateT * v9270 = v9227(v9218);
  return v9270;
}

struct StateT * v8355(struct StateT * v8356) {
  int v8357 = v8356->timer;
  int v10271 = v8357 + 1;
  v8356->timer = v10271;int * v8359 = v8356->regs;
  int v8360 = v8359[15];
  int * v8361 = v8356->regs;
  int v10275 = v8360 << 18;
  v8361[15] = v10275;
  struct StateT * v10269 = v8363(v8356);
  return v10269;
}

struct StateT * v8715(struct StateT * v8716) {
  int v8717 = v8716->timer;
  int v9851 = v8717 + 1;
  v8716->timer = v9851;int * v8719 = v8716->regs;
  int v8720 = v8719[11];
  int * v8721 = v8716->regs;
  int v9856 = (int)((unsigned int)v8720 >> 23);
  v8721[9] = v9856;
  struct StateT * v9849 = v8723(v8716);
  return v9849;
}

struct StateT * v1355(struct StateT * v1356) {
  int v1357 = v1356->timer;
  int v12436 = v1357 + 1;
  v1356->timer = v12436;int * v1359 = v1356->regs;
  int v1360 = v1359[11];
  int * v1361 = v1356->cache_keys;
  int v1362 = v1361[0];
  bool v12441 = v1362 == ((int)((unsigned int)(v1360 + 12) >> 2));
  int v1410 = (v12441 ? ({
    int * v1363 = v1356->cache_vals;
    int v1364 = v1363[0];
    v1364;
  }) : ({
    int * v1366 = v1356->cache_keys;
    int v1367 = v1366[1];
    bool v12446 = v1367 == ((int)((unsigned int)(v1360 + 12) >> 2));
    int v1408 = (v12446 ? ({
      int * v1368 = v1356->cache_vals;
      int v1369 = v1368[1];
      int * v1370 = v1356->cache_keys;
      int * v1371 = v1356->cache_keys;
      int v1372 = v1371[0];
      v1370[1] = v1372;
      int * v1374 = v1356->cache_vals;
      int * v1375 = v1356->cache_vals;
      int v1376 = v1375[0];
      v1374[1] = v1376;
      int * v1378 = v1356->cache_keys;
      int v12455 = (int)((unsigned int)(v1360 + 12) >> 2);
      v1378[0] = v12455;
      int * v1380 = v1356->cache_vals;
      v1380[0] = v1369;
      int v1382 = v1356->timer;
      int v12458 = v1382 + 1;
      v1356->timer = v12458;v1369;
    }) : ({
      int * v1385 = v1356->mem;
      int v12460 = (int)((unsigned int)(v1360 + 12) >> 2);
      int v1386 = v1385[v12460];
      int * v1387 = v1356->mem;
      int * v1388 = v1356->cache_keys;
      int v1389 = v1388[1];
      int * v1390 = v1356->cache_vals;
      int v1391 = v1390[1];
      v1387[v1389] = v1391;
      int * v1393 = v1356->cache_keys;
      int * v1394 = v1356->cache_keys;
      int v1395 = v1394[0];
      v1393[1] = v1395;
      int * v1397 = v1356->cache_vals;
      int * v1398 = v1356->cache_vals;
      int v1399 = v1398[0];
      v1397[1] = v1399;
      int * v1401 = v1356->cache_keys;
      v1401[0] = v12460;
      int * v1403 = v1356->cache_vals;
      v1403[0] = v1386;
      int v1405 = v1356->timer;
      int v12475 = v1405 + 100;
      v1356->timer = v12475;v1386;
    }));
    v1408;
  }));
  int * v1411 = v1356->regs;
  v1411[15] = v1410;
  struct StateT * v12434 = v1413(v1356);
  return v12434;
}

struct StateT * v4951(struct StateT * v4952) {
  int v4953 = v4952->timer;
  int v6306 = v4953 + 1;
  v4952->timer = v6306;int * v4955 = v4952->regs;
  int v4956 = v4955[2];
  int * v4957 = v4952->cache_keys;
  int v4958 = v4957[0];
  bool v6311 = v4958 == ((int)((unsigned int)(v4956 + 92) >> 2));
  int v5006 = (v6311 ? ({
    int * v4959 = v4952->cache_vals;
    int v4960 = v4959[0];
    v4960;
  }) : ({
    int * v4962 = v4952->cache_keys;
    int v4963 = v4962[1];
    bool v6316 = v4963 == ((int)((unsigned int)(v4956 + 92) >> 2));
    int v5004 = (v6316 ? ({
      int * v4964 = v4952->cache_vals;
      int v4965 = v4964[1];
      int * v4966 = v4952->cache_keys;
      int * v4967 = v4952->cache_keys;
      int v4968 = v4967[0];
      v4966[1] = v4968;
      int * v4970 = v4952->cache_vals;
      int * v4971 = v4952->cache_vals;
      int v4972 = v4971[0];
      v4970[1] = v4972;
      int * v4974 = v4952->cache_keys;
      int v6325 = (int)((unsigned int)(v4956 + 92) >> 2);
      v4974[0] = v6325;
      int * v4976 = v4952->cache_vals;
      v4976[0] = v4965;
      int v4978 = v4952->timer;
      int v6328 = v4978 + 1;
      v4952->timer = v6328;v4965;
    }) : ({
      int * v4981 = v4952->mem;
      int v6330 = (int)((unsigned int)(v4956 + 92) >> 2);
      int v4982 = v4981[v6330];
      int * v4983 = v4952->mem;
      int * v4984 = v4952->cache_keys;
      int v4985 = v4984[1];
      int * v4986 = v4952->cache_vals;
      int v4987 = v4986[1];
      v4983[v4985] = v4987;
      int * v4989 = v4952->cache_keys;
      int * v4990 = v4952->cache_keys;
      int v4991 = v4990[0];
      v4989[1] = v4991;
      int * v4993 = v4952->cache_vals;
      int * v4994 = v4952->cache_vals;
      int v4995 = v4994[0];
      v4993[1] = v4995;
      int * v4997 = v4952->cache_keys;
      v4997[0] = v6330;
      int * v4999 = v4952->cache_vals;
      v4999[0] = v4982;
      int v5001 = v4952->timer;
      int v6345 = v5001 + 100;
      v4952->timer = v6345;v4982;
    }));
    v5004;
  }));
  int * v5007 = v4952->regs;
  v5007[1] = v5006;
  struct StateT * v6304 = v5009(v4952);
  return v6304;
}

struct StateT * v3375(struct StateT * v3376) {
  int v3377 = v3376->timer;
  int v7708 = v3377 + 1;
  v3376->timer = v7708;int * v3379 = v3376->regs;
  int v3380 = v3379[14];
  int * v3381 = v3376->regs;
  int v3382 = v3381[7];
  int * v3383 = v3376->regs;
  int v7714 = v3380 + v3382;
  v3383[14] = v7714;
  struct StateT * v7706 = v3385(v3376);
  return v7706;
}

struct StateT * v8583(struct StateT * v8584) {
  int v8585 = v8584->timer;
  int v10007 = v8585 + 1;
  v8584->timer = v10007;int * v8587 = v8584->regs;
  int v8588 = v8587[16];
  int * v8589 = v8584->regs;
  int v10012 = (int)((unsigned int)v8588 >> 25);
  v8589[5] = v10012;
  struct StateT * v10005 = v8591(v8584);
  return v10005;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v13611 = v1(v0);
  return v13611;
}

struct StateT * v1(struct StateT * v2) {
  int v3 = v2->timer;
  int v13604 = v3 + 1;
  v2->timer = v13604;int * v5 = v2->regs;
  int v6 = v5[2];
  int * v7 = v2->regs;
  int v13608 = v6 + -96;
  v7[2] = v13608;
  struct StateT * v13602 = v9(v2);
  return v13602;
}

struct StateT * v7995(struct StateT * v7996) {
  int v7997 = v7996->timer;
  int v10688 = v7997 + 1;
  v7996->timer = v10688;int * v7999 = v7996->regs;
  int v8000 = v7999[15];
  int * v8001 = v7996->regs;
  int v8002 = v8001[20];
  int * v8003 = v7996->regs;
  int v10694 = v8000 | v8002;
  v8003[15] = v10694;
  struct StateT * v10686 = v8005(v7996);
  return v10686;
}

struct StateT * v9125(struct StateT * v9126) {
  int v9127 = v9126->timer;
  int v9377 = v9127 + 1;
  v9126->timer = v9377;int * v9129 = v9126->regs;
  int v9130 = v9129[15];
  int * v9131 = v9126->regs;
  int v9132 = v9131[9];
  int * v9133 = v9126->regs;
  int v9383 = v9130 | v9132;
  v9133[15] = v9383;
  struct StateT * v9375 = v9135(v9126);
  return v9375;
}

struct StateT * v7987(struct StateT * v7988) {
  int v7989 = v7988->timer;
  int v10699 = v7989 + 1;
  v7988->timer = v10699;int * v7991 = v7988->regs;
  int v7992 = v7991[15];
  int * v7993 = v7988->regs;
  int v10703 = v7992 << 9;
  v7993[15] = v10703;
  struct StateT * v10697 = v7995(v7988);
  return v10697;
}

struct StateT * v8849(struct StateT * v8850) {
  int v8851 = v8850->timer;
  int v9697 = v8851 + 1;
  v8850->timer = v9697;int * v8853 = v8850->regs;
  int v8854 = v8853[24];
  int * v8855 = v8850->regs;
  int v8856 = v8855[8];
  int * v8857 = v8850->regs;
  int v9703 = v8854 ^ v8856;
  v8857[24] = v9703;
  struct StateT * v9695 = v8859(v8850);
  return v9695;
}

struct StateT * v8451(struct StateT * v8452) {
  int v8453 = v8452->timer;
  int v10159 = v8453 + 1;
  v8452->timer = v10159;int * v8455 = v8452->regs;
  int v8456 = v8455[21];
  int * v8457 = v8452->regs;
  int v8458 = v8457[15];
  int * v8459 = v8452->regs;
  int v10165 = v8456 ^ v8458;
  v8459[21] = v10165;
  struct StateT * v10157 = v8461(v8452);
  return v10157;
}

struct StateT * v8347(struct StateT * v8348) {
  int v8349 = v8348->timer;
  int v10280 = v8349 + 1;
  v8348->timer = v10280;int * v8351 = v8348->regs;
  int v8352 = v8351[15];
  int * v8353 = v8348->regs;
  int v10285 = (int)((unsigned int)v8352 >> 14);
  v8353[6] = v10285;
  struct StateT * v10278 = v8355(v8348);
  return v10278;
}

struct StateT * v4303(struct StateT * v4304) {
  int v4305 = v4304->timer;
  int v6848 = v4305 + 1;
  v4304->timer = v6848;int * v4307 = v4304->regs;
  int v4308 = v4307[10];
  int * v4309 = v4304->regs;
  int v4310 = v4309[12];
  int * v4311 = v4304->cache_keys;
  int v4312 = v4311[0];
  bool v6855 = v4312 == ((int)((unsigned int)(v4308 + 16) >> 2));
  int v4356 = (v6855 ? ({
    int * v4313 = v4304->cache_vals;
    v4313[0] = v4310;
    v4310;
  }) : ({
    int * v4316 = v4304->cache_keys;
    int v4317 = v4316[1];
    bool v6860 = v4317 == ((int)((unsigned int)(v4308 + 16) >> 2));
    int v4354 = (v6860 ? ({
      int * v4318 = v4304->cache_keys;
      int * v4319 = v4304->cache_keys;
      int v4320 = v4319[0];
      v4318[1] = v4320;
      int * v4322 = v4304->cache_vals;
      int * v4323 = v4304->cache_vals;
      int v4324 = v4323[0];
      v4322[1] = v4324;
      int * v4326 = v4304->cache_keys;
      int v6868 = (int)((unsigned int)(v4308 + 16) >> 2);
      v4326[0] = v6868;
      int * v4328 = v4304->cache_vals;
      v4328[0] = v4310;
      int v4330 = v4304->timer;
      int v6871 = v4330 + 1;
      v4304->timer = v6871;v4310;
    }) : ({
      int * v4333 = v4304->mem;
      int * v4334 = v4304->cache_keys;
      int v4335 = v4334[1];
      int * v4336 = v4304->cache_vals;
      int v4337 = v4336[1];
      v4333[v4335] = v4337;
      int * v4339 = v4304->cache_keys;
      int * v4340 = v4304->cache_keys;
      int v4341 = v4340[0];
      v4339[1] = v4341;
      int * v4343 = v4304->cache_vals;
      int * v4344 = v4304->cache_vals;
      int v4345 = v4344[0];
      v4343[1] = v4345;
      int * v4347 = v4304->cache_keys;
      int v6884 = (int)((unsigned int)(v4308 + 16) >> 2);
      v4347[0] = v6884;
      int * v4349 = v4304->cache_vals;
      v4349[0] = v4310;
      int v4351 = v4304->timer;
      int v6887 = v4351 + 100;
      v4304->timer = v6887;v4310;
    }));
    v4354;
  }));
  struct StateT * v6846 = v4357(v4304);
  return v6846;
}

struct StateT * v8249(struct StateT * v8250) {
  int v8251 = v8250->timer;
  int v10397 = v8251 + 1;
  v8250->timer = v10397;int * v8253 = v8250->regs;
  int v8254 = v8253[18];
  int * v8255 = v8250->regs;
  int v10401 = v8254 << 13;
  v8255[18] = v10401;
  struct StateT * v10395 = v8257(v8250);
  return v10395;
}



/*****************************************
End of C Generated Code
*******************************************/

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