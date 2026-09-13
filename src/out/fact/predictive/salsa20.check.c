// verify: clean (CBMC should report VERIFICATION SUCCESSFUL)

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

struct StateT * v10989(struct StateT * v10990);
struct StateT * v9279(struct StateT * v9280);
struct StateT * v2211(struct StateT * v2212);
struct StateT * v9715(struct StateT * v9716);
struct StateT * v11874(struct StateT * v11875);
struct StateT * v2359(struct StateT * v2360);
struct StateT * v4575(struct StateT * v4576);
struct StateT * v11471(struct StateT * v11472);
struct StateT * v8207(struct StateT * v8208);
struct StateT * v9057(struct StateT * v9058);
struct StateT * v8787(struct StateT * v8788);
struct StateT * v9443(struct StateT * v9444);
struct StateT * v14062(struct StateT * v14063);
struct StateT * v9549(struct StateT * v9550);
struct StateT * v11357(struct StateT * v11358);
struct StateT * v10877(struct StateT * v10878);
struct StateT * v2617(struct StateT * v2618);
struct StateT * v8655(struct StateT * v8656);
struct StateT * v8213(struct StateT * v8214);
struct StateT * v10349(struct StateT * v10350);
struct StateT * v2677(struct StateT * v2678);
struct StateT * v9591(struct StateT * v9592);
struct StateT * v63(struct StateT * v64);
struct StateT * v2265(struct StateT * v2266);
struct StateT * v9627(struct StateT * v9628);
struct StateT * v9557(struct StateT * v9558);
struct StateT * v2225(struct StateT * v2226);
struct StateT * v4131(struct StateT * v4132);
struct StateT * v3447(struct StateT * v3448);
struct StateT * v9085(struct StateT * v9086);
struct StateT * v9031(struct StateT * v9032);
struct StateT * v3167(struct StateT * v3168);
struct StateT * v11137(struct StateT * v11138);
struct StateT * v13366(struct StateT * v13367);
struct StateT * v9767(struct StateT * v9768);
struct StateT * v2797(struct StateT * v2798);
struct StateT * v2183(struct StateT * v2184);
struct StateT * v891(struct StateT * v892);
struct StateT * v2473(struct StateT * v2474);
struct StateT * v11497(struct StateT * v11498);
struct StateT * v9145(struct StateT * v9146);
struct StateT * v9741(struct StateT * v9742);
struct StateT * v9417(struct StateT * v9418);
struct StateT * v10771(struct StateT * v10772);
struct StateT * v4121(struct StateT * v4122);
struct StateT * v1065(struct StateT * v1066);
struct StateT * v12552(struct StateT * v12553);
struct StateT * v657(struct StateT * v658);
struct StateT * v11393(struct StateT * v11394);
struct StateT * v2369(struct StateT * v2370);
struct StateT * v12498(struct StateT * v12499);
struct StateT * v1907(struct StateT * v1908);
struct StateT * v2737(struct StateT * v2738);
struct StateT * v10201(struct StateT * v10202);
struct StateT * v5335(struct StateT * v5336);
struct StateT * v9319(struct StateT * v9320);
struct StateT * v5857(struct StateT * v5858);
struct StateT * v3271(struct StateT * v3272);
struct StateT * v8079(struct StateT * v8080);
struct StateT * v9801(struct StateT * v9802);
struct StateT * v9539(struct StateT * v9540);
struct StateT * v9163(struct StateT * v9164);
struct StateT * v9733(struct StateT * v9734);
struct StateT * v9925(struct StateT * v9926);
struct StateT * v9095(struct StateT * v9096);
struct StateT * v3131(struct StateT * v3132);
struct StateT * v11279(struct StateT * v11280);
struct StateT * v13540(struct StateT * v13541);
struct StateT * v3305(struct StateT * v3306);
struct StateT * v11453(struct StateT * v11454);
struct StateT * v10649(struct StateT * v10650);
struct StateT * v9407(struct StateT * v9408);
struct StateT * v3139(struct StateT * v3140);
struct StateT * v2929(struct StateT * v2930);
struct StateT * v5567(struct StateT * v5568);
struct StateT * v4057(struct StateT * v4058);
struct StateT * v1425(struct StateT * v1426);
struct StateT * v1637(struct StateT * v1638);
struct StateT * v10971(struct StateT * v10972);
struct StateT * v13146(struct StateT * v13147);
struct StateT * v9785(struct StateT * v9786);
struct StateT * v9309(struct StateT * v9310);
struct StateT * v9637(struct StateT * v9638);
struct StateT * v10005(struct StateT * v10006);
struct StateT * v11025(struct StateT * v11026);
struct StateT * v2235(struct StateT * v2236);
struct StateT * v3341(struct StateT * v3342);
struct StateT * v6039(struct StateT * v6040);
struct StateT * v10141(struct StateT * v10142);
struct StateT * v12380(struct StateT * v12381);
struct StateT * v2763(struct StateT * v2764);
struct StateT * v9969(struct StateT * v9970);
struct StateT * v10815(struct StateT * v10816);
struct StateT * v8767(struct StateT * v8768);
struct StateT * v11287(struct StateT * v11288);
struct StateT * v2729(struct StateT * v2730);
struct StateT * v9503(struct StateT * v9504);
struct StateT * v10669(struct StateT * v10670);
struct StateT * v10763(struct StateT * v10764);
struct StateT * v11587(struct StateT * v11588);
struct StateT * v3437(struct StateT * v3438);
struct StateT * v1239(struct StateT * v1240);
struct StateT * v12768(struct StateT * v12769);
struct StateT * v3695(struct StateT * v3696);
struct StateT * v949(struct StateT * v950);
struct StateT * v2703(struct StateT * v2704);
struct StateT * v9433(struct StateT * v9434);
struct StateT * v9871(struct StateT * v9872);
struct StateT * v9483(struct StateT * v9484);
struct StateT * v2937(struct StateT * v2938);
struct StateT * v9647(struct StateT * v9648);
struct StateT * v9171(struct StateT * v9172);
struct StateT * v12372(struct StateT * v12373);
struct StateT * v8419(struct StateT * v8420);
struct StateT * v11313(struct StateT * v11314);
struct StateT * v2903(struct StateT * v2904);
struct StateT * v9215(struct StateT * v9216);
struct StateT * v1123(struct StateT * v1124);
struct StateT * v11065(struct StateT * v11066);
struct StateT * v1419(struct StateT * v1420);
struct StateT * v11147(struct StateT * v11148);
struct StateT * v10015(struct StateT * v10016);
struct StateT * v10115(struct StateT * v10116);
struct StateT * v2747(struct StateT * v2748);
struct StateT * v3297(struct StateT * v3298);
struct StateT * v3351(struct StateT * v3352);
struct StateT * v10323(struct StateT * v10324);
struct StateT * v717(struct StateT * v718);
struct StateT * v10075(struct StateT * v10076);
struct StateT * v2773(struct StateT * v2774);
struct StateT * v5973(struct StateT * v5974);
struct StateT * v775(struct StateT * v776);
struct StateT * v10287(struct StateT * v10288);
struct StateT * v9355(struct StateT * v9356);
struct StateT * v9881(struct StateT * v9882);
struct StateT * v2859(struct StateT * v2860);
struct StateT * v8505(struct StateT * v8506);
struct StateT * v3245(struct StateT * v3246);
struct StateT * v8979(struct StateT * v8980);
struct StateT * v9851(struct StateT * v9852);
struct StateT * v8681(struct StateT * v8682);
struct StateT * v9039(struct StateT * v9040);
struct StateT * v5683(struct StateT * v5684);
struct StateT * v12388(struct StateT * v12389);
struct StateT * v9917(struct StateT * v9918);
struct StateT * v11103(struct StateT * v11104);
struct StateT * v2383(struct StateT * v2384);
struct StateT * v11229(struct StateT * v11230);
struct StateT * v2307(struct StateT * v2308);
struct StateT * v9299(struct StateT * v9300);
struct StateT * v2445(struct StateT * v2446);
struct StateT * v4393(struct StateT * v4394);
struct StateT * v3331(struct StateT * v3332);
struct StateT * v11055(struct StateT * v11056);
struct StateT * v9583(struct StateT * v9584);
struct StateT * v2273(struct StateT * v2274);
struct StateT * v2411(struct StateT * v2412);
struct StateT * v3263(struct StateT * v3264);
struct StateT * v10297(struct StateT * v10298);
struct StateT * v9023(struct StateT * v9024);
struct StateT * v3515(struct StateT * v3516);
struct StateT * v10711(struct StateT * v10712);
struct StateT * v11607(struct StateT * v11608);
struct StateT * v1939(struct StateT * v1940);
struct StateT * v3391(struct StateT * v3392);
struct StateT * v10745(struct StateT * v10746);
struct StateT * v8951(struct StateT * v8952);
struct StateT * v10253(struct StateT * v10254);
struct StateT * v8873(struct StateT * v8874);
struct StateT * v3411(struct StateT * v3412);
struct StateT * v11163(struct StateT * v11164);
struct StateT * v9075(struct StateT * v9076);
struct StateT * v3177(struct StateT * v3178);
struct StateT * v9347(struct StateT * v9348);
struct StateT * v4383(struct StateT * v4384);
struct StateT * v10945(struct StateT * v10946);
struct StateT * v2877(struct StateT * v2878);
struct StateT * v8361(struct StateT * v8362);
struct StateT * v8697(struct StateT * v8698);
struct StateT * v13038(struct StateT * v13039);
struct StateT * v8829(struct StateT * v8830);
struct StateT * v4737(struct StateT * v4738);
struct StateT * v13598(struct StateT * v13599);
struct StateT * v2425(struct StateT * v2426);
struct StateT * v2499(struct StateT * v2500);
struct StateT * v10911(struct StateT * v10912);
struct StateT * v11035(struct StateT * v11036);
struct StateT * v9223(struct StateT * v9224);
struct StateT * v3043(struct StateT * v3044);
struct StateT * v9155(struct StateT * v9156);
struct StateT * v10193(struct StateT * v10194);
struct StateT * v6031(struct StateT * v6032);
struct StateT * v3147(struct StateT * v3148);
struct StateT * v10891(struct StateT * v10892);
struct StateT * v11259(struct StateT * v11260);
struct StateT * v3843(struct StateT * v3844);
struct StateT * v10089(struct StateT * v10090);
struct StateT * v833(struct StateT * v834);
struct StateT * v2351(struct StateT * v2352);
struct StateT * v3711(struct StateT * v3712);
struct StateT * v11549(struct StateT * v11550);
struct StateT * v11249(struct StateT * v11250);
struct StateT * v9259(struct StateT * v9260);
struct StateT * v8663(struct StateT * v8664);
struct StateT * v1745(struct StateT * v1746);
struct StateT * v549(struct StateT * v550);
struct StateT * v8987(struct StateT * v8988);
struct StateT * v1461(struct StateT * v1462);
struct StateT * v10601(struct StateT * v10602);
struct StateT * v9775(struct StateT * v9776);
struct StateT * v3455(struct StateT * v3456);
struct StateT * v11095(struct StateT * v11096);
struct StateT * v10697(struct StateT * v10698);
struct StateT * v8921(struct StateT * v8922);
struct StateT * v8971(struct StateT * v8972);
struct StateT * v3577(struct StateT * v3578);
struct StateT * v10043(struct StateT * v10044);
struct StateT * v9707(struct StateT * v9708);
struct StateT * v2245(struct StateT * v2246);
struct StateT * v10867(struct StateT * v10868);
struct StateT * v9289(struct StateT * v9290);
struct StateT * v12876(struct StateT * v12877);
struct StateT * v8117(struct StateT * v8118);
struct StateT * v10453(struct StateT * v10454);
struct StateT * v10575(struct StateT * v10576);
struct StateT * v13092(struct StateT * v13093);
struct StateT * v4629(struct StateT * v4630);
struct StateT * v4199(struct StateT * v4200);
struct StateT * v10549(struct StateT * v10550);
struct StateT * v3371(struct StateT * v3372);
struct StateT * v10359(struct StateT * v10360);
struct StateT * v12088(struct StateT * v12089);
struct StateT * v3157(struct StateT * v3158);
struct StateT * v2583(struct StateT * v2584);
struct StateT * v2655(struct StateT * v2656);
struct StateT * v2685(struct StateT * v2686);
struct StateT * v10149(struct StateT * v10150);
struct StateT * v10133(struct StateT * v10134);
struct StateT * v3361(struct StateT * v3362);
struct StateT * v8637(struct StateT * v8638);
struct StateT * v9513(struct StateT * v9514);
struct StateT * v2869(struct StateT * v2870);
struct StateT * v2885(struct StateT * v2886);
struct StateT * v9531(struct StateT * v9532);
struct StateT * v9135(struct StateT * v9136);
struct StateT * v3207(struct StateT * v3208);
struct StateT * v11423(struct StateT * v11424);
struct StateT * v3253(struct StateT * v3254);
struct StateT * v13308(struct StateT * v13309);
struct StateT * v603(struct StateT * v604);
struct StateT * v8757(struct StateT * v8758);
struct StateT * v2627(struct StateT * v2628);
struct StateT * v495(struct StateT * v496);
struct StateT * v9381(struct StateT * v9382);
struct StateT * v2091(struct StateT * v2092);
struct StateT * v11045(struct StateT * v11046);
struct StateT * v2973(struct StateT * v2974);
struct StateT * v1431(struct StateT * v1432);
struct StateT * v3565(struct StateT * v3566);
struct StateT * v8275(struct StateT * v8276);
struct StateT * v2465(struct StateT * v2466);
struct StateT * v11155(struct StateT * v11156);
struct StateT * v117(struct StateT * v118);
struct StateT * v13482(struct StateT * v13483);
struct StateT * v8931(struct StateT * v8932);
struct StateT * v11111(struct StateT * v11112);
struct StateT * v9(struct StateT * v10);
struct StateT * v11505(struct StateT * v11506);
struct StateT * v1007(struct StateT * v1008);
struct StateT * v4845(struct StateT * v4846);
struct StateT * v2721(struct StateT * v2722);
struct StateT * v1529(struct StateT * v1530);
struct StateT * v8717(struct StateT * v8718);
struct StateT * v9723(struct StateT * v9724);
struct StateT * v13888(struct StateT * v13889);
struct StateT * v14004(struct StateT * v14005);
struct StateT * v8961(struct StateT * v8962);
struct StateT * v2435(struct StateT * v2436);
struct StateT * v10727(struct StateT * v10728);
struct StateT * v2107(struct StateT * v2108);
struct StateT * v2143(struct StateT * v2144);
struct StateT * v2081(struct StateT * v2082);
struct StateT * v9453(struct StateT * v9454);
struct StateT * v3481(struct StateT * v3482);
struct StateT * v10211(struct StateT * v10212);
struct StateT * v3507(struct StateT * v3508);
struct StateT * v11121(struct StateT * v11122);
struct StateT * v11443(struct StateT * v11444);
struct StateT * v2835(struct StateT * v2836);
struct StateT * v9013(struct StateT * v9014);
struct StateT * v1455(struct StateT * v1456);
struct StateT * v2533(struct StateT * v2534);
struct StateT * v11433(struct StateT * v11434);
struct StateT * v8911(struct StateT * v8912);
struct StateT * v10523(struct StateT * v10524);
struct StateT * v279(struct StateT * v280);
struct StateT * v3187(struct StateT * v3188);
struct StateT * v10315(struct StateT * v10316);
struct StateT * v12010(struct StateT * v12011);
struct StateT * v9425(struct StateT * v9426);
struct StateT * v10829(struct StateT * v10830);
struct StateT * v9565(struct StateT * v9566);
struct StateT * v13656(struct StateT * v13657);
struct StateT * v711(struct StateT * v712);
struct StateT * v2117(struct StateT * v2118);
struct StateT * v8093(struct StateT * v8094);
struct StateT * v10625(struct StateT * v10626);
struct StateT * v2551(struct StateT * v2552);
struct StateT * v3853(struct StateT * v3854);
struct StateT * v3003(struct StateT * v3004);
struct StateT * v10123(struct StateT * v10124);
struct StateT * v4521(struct StateT * v4522);
struct StateT * v8289(struct StateT * v8290);
struct StateT * v9189(struct StateT * v9190);
struct StateT * v2151(struct StateT * v2152);
struct StateT * v10307(struct StateT * v10308);
struct StateT * v3069(struct StateT * v3070);
struct StateT * v9831(struct StateT * v9832);
struct StateT * v11952(struct StateT * v11953);
struct StateT * v11015(struct StateT * v11016);
struct StateT * v8433(struct StateT * v8434);
struct StateT * v2481(struct StateT * v2482);
struct StateT * v13830(struct StateT * v13831);
struct StateT * v11523(struct StateT * v11524);
struct StateT * v8511(struct StateT * v8512);
struct StateT * v3463(struct StateT * v3464);
struct StateT * v11531(struct StateT * v11532);
struct StateT * v12984(struct StateT * v12985);
struct StateT * v10719(struct StateT * v10720);
struct StateT * v5915(struct StateT * v5916);
struct StateT * v12152(struct StateT * v12153);
struct StateT * v9977(struct StateT * v9978);
struct StateT * v1355(struct StateT * v1356);
struct StateT * v12606(struct StateT * v12607);
struct StateT * v10541(struct StateT * v10542);
struct StateT * snippet(struct StateT * v0);
struct StateT * v3911(struct StateT * v3912);
struct StateT * v13714(struct StateT * v13715);
struct StateT * v2255(struct StateT * v2256);
struct StateT * v1(struct StateT * v2);
struct StateT * v11732(struct StateT * v11733);
struct StateT * v8795(struct StateT * v8796);
struct StateT * v3079(struct StateT * v3080);
struct StateT * v8347(struct StateT * v8348);
struct StateT * v5223(struct StateT * v5224);
struct StateT * v2333(struct StateT * v2334);
struct StateT * v11365(struct StateT * v11366);
struct StateT * v12930(struct StateT * v12931);
struct StateT * v8839(struct StateT * v8840);
struct StateT * v2455(struct StateT * v2456);
struct StateT * v5061(struct StateT * v5062);
struct StateT * v10853(struct StateT * v10854);
struct StateT * v3429(struct StateT * v3430);
struct StateT * v8707(struct StateT * v8708);
struct StateT * v8671(struct StateT * v8672);
struct StateT * v12444(struct StateT * v12445);
struct StateT * v9523(struct StateT * v9524);
struct StateT * v2325(struct StateT * v2326);
struct StateT * v3087(struct StateT * v3088);
struct StateT * v2507(struct StateT * v2508);
struct StateT * v9609(struct StateT * v9610);
struct StateT * v3785(struct StateT * v3786);
struct StateT * v10225(struct StateT * v10226);
struct StateT * v9907(struct StateT * v9908);
struct StateT * v2525(struct StateT * v2526);
struct StateT * v2895(struct StateT * v2896);
struct StateT * v3227(struct StateT * v3228);
struct StateT * v2755(struct StateT * v2756);
struct StateT * v3921(struct StateT * v3922);
struct StateT * v4791(struct StateT * v4792);
struct StateT * v8727(struct StateT * v8728);
struct StateT * v11339(struct StateT * v11340);
struct StateT * v4335(struct StateT * v4336);
struct StateT * v3535(struct StateT * v3536);
struct StateT * v5451(struct StateT * v5452);
struct StateT * v5169(struct StateT * v5170);
struct StateT * v10507(struct StateT * v10508);
struct StateT * v10333(struct StateT * v10334);
struct StateT * v12396(struct StateT * v12397);
struct StateT * v9005(struct StateT * v9006);
struct StateT * v10737(struct StateT * v10738);
struct StateT * v441(struct StateT * v442);
struct StateT * v9985(struct StateT * v9986);
struct StateT * v8881(struct StateT * v8882);
struct StateT * v12660(struct StateT * v12661);
struct StateT * v1469(struct StateT * v1470);
struct StateT * v5799(struct StateT * v5800);
struct StateT * v10953(struct StateT * v10954);
struct StateT * v9677(struct StateT * v9678);
struct StateT * v2397(struct StateT * v2398);
struct StateT * v4349(struct StateT * v4350);
struct StateT * v10277(struct StateT * v10278);
struct StateT * v9575(struct StateT * v9576);
struct StateT * v3061(struct StateT * v3062);
struct StateT * v10593(struct StateT * v10594);
struct StateT * v11373(struct StateT * v11374);
struct StateT * v4189(struct StateT * v4190);
struct StateT * v11716(struct StateT * v11717);
struct StateT * v14070(struct StateT * v14071);
struct StateT * v12414(struct StateT * v12415);
struct StateT * v5625(struct StateT * v5626);
struct StateT * v3421(struct StateT * v3422);
struct StateT * v9463(struct StateT * v9464);
struct StateT * v5509(struct StateT * v5510);
struct StateT * v8131(struct StateT * v8132);
struct StateT * v4357(struct StateT * v4358);
struct StateT * v3381(struct StateT * v3382);
struct StateT * v11489(struct StateT * v11490);
struct StateT * v1413(struct StateT * v1414);
struct StateT * v2001(struct StateT * v2002);
struct StateT * v11269(struct StateT * v11270);
struct StateT * v12162(struct StateT * v12163);
struct StateT * v12020(struct StateT * v12021);
struct StateT * v10375(struct StateT * v10376);
struct StateT * v2711(struct StateT * v2712);
struct StateT * v1993(struct StateT * v1994);
struct StateT * v9269(struct StateT * v9270);
struct StateT * v8629(struct StateT * v8630);
struct StateT * v11942(struct StateT * v11943);
struct StateT * v10439(struct StateT * v10440);
struct StateT * v2197(struct StateT * v2198);
struct StateT * v1475(struct StateT * v1476);
struct StateT * v9759(struct StateT * v9760);
struct StateT * v5741(struct StateT * v5742);
struct StateT * v9657(struct StateT * v9658);
struct StateT * v2019(struct StateT * v2020);
struct StateT * v10753(struct StateT * v10754);
struct StateT * v8603(struct StateT * v8604);
struct StateT * v3113(struct StateT * v3114);
struct StateT * v10683(struct StateT * v10684);
struct StateT * v8593(struct StateT * v8594);
struct StateT * v11347(struct StateT * v11348);
struct StateT * v10487(struct StateT * v10488);
struct StateT * v8573(struct StateT * v8574);
struct StateT * v4257(struct StateT * v4258);
struct StateT * v8821(struct StateT * v8822);
struct StateT * v11383(struct StateT * v11384);
struct StateT * v2299(struct StateT * v2300);
struct StateT * v10385(struct StateT * v10386);
struct StateT * v5277(struct StateT * v5278);
struct StateT * v12078(struct StateT * v12079);
struct StateT * v2921(struct StateT * v2922);
struct StateT * v10159(struct StateT * v10160);
struct StateT * v9687(struct StateT * v9688);
struct StateT * v2607(struct StateT * v2608);
struct StateT * v9617(struct StateT * v9618);
struct StateT * v3323(struct StateT * v3324);
struct StateT * v2955(struct StateT * v2956);
struct StateT * v8865(struct StateT * v8866);
struct StateT * v11189(struct StateT * v11190);
struct StateT * v11181(struct StateT * v11182);
struct StateT * v3769(struct StateT * v3770);
struct StateT * v2491(struct StateT * v2492);
struct StateT * v11209(struct StateT * v11210);
struct StateT * v11800(struct StateT * v11801);
struct StateT * v10341(struct StateT * v10342);
struct StateT * v11816(struct StateT * v11817);
struct StateT * v3545(struct StateT * v3546);
struct StateT * v11331(struct StateT * v11332);
struct StateT * v8891(struct StateT * v8892);
struct StateT * v10175(struct StateT * v10176);
struct StateT * v3489(struct StateT * v3490);
struct StateT * v10927(struct StateT * v10928);
struct StateT * v2849(struct StateT * v2850);
struct StateT * v333(struct StateT * v334);
struct StateT * v8689(struct StateT * v8690);
struct StateT * v9473(struct StateT * v9474);
struct StateT * v2005(struct StateT * v2006);
struct StateT * v9399(struct StateT * v9400);
struct StateT * v1447(struct StateT * v1448);
struct StateT * v11742(struct StateT * v11743);
struct StateT * v8107(struct StateT * v8108);
struct StateT * v10061(struct StateT * v10062);
struct StateT * v4403(struct StateT * v4404);
struct StateT * v2543(struct StateT * v2544);
struct StateT * v10797(struct StateT * v10798);
struct StateT * v12094(struct StateT * v12095);
struct StateT * v11305(struct StateT * v11306);
struct StateT * v8777(struct StateT * v8778);
struct StateT * v3779(struct StateT * v3780);
struct StateT * v11005(struct StateT * v11006);
struct StateT * v9861(struct StateT * v9862);
struct StateT * v8941(struct StateT * v8942);
struct StateT * v9373(struct StateT * v9374);
struct StateT * v225(struct StateT * v226);
struct StateT * v12434(struct StateT * v12435);
struct StateT * v2811(struct StateT * v2812);
struct StateT * v12298(struct StateT * v12299);
struct StateT * v1691(struct StateT * v1692);
struct StateT * v9793(struct StateT * v9794);
struct StateT * v11577(struct StateT * v11578);
struct StateT * v2911(struct StateT * v2912);
struct StateT * v2695(struct StateT * v2696);
struct StateT * v9995(struct StateT * v9996);
struct StateT * v9233(struct StateT * v9234);
struct StateT * v4899(struct StateT * v4900);
struct StateT * v9339(struct StateT * v9340);
struct StateT * v11129(struct StateT * v11130);
struct StateT * v2573(struct StateT * v2574);
struct StateT * v9811(struct StateT * v9812);
struct StateT * v9241(struct StateT * v9242);
struct StateT * v2047(struct StateT * v2048);
struct StateT * v11239(struct StateT * v11240);
struct StateT * v12822(struct StateT * v12823);
struct StateT * v11541(struct StateT * v11542);
struct StateT * v10659(struct StateT * v10660);
struct StateT * v9049(struct StateT * v9050);
struct StateT * v2963(struct StateT * v2964);
struct StateT * v8645(struct StateT * v8646);
struct StateT * v9391(struct StateT * v9392);
struct StateT * v2033(struct StateT * v2034);
struct StateT * v3105(struct StateT * v3106);
struct StateT * v5007(struct StateT * v5008);
struct StateT * v4467(struct StateT * v4468);
struct StateT * v2559(struct StateT * v2560);
struct StateT * v8747(struct StateT * v8748);
struct StateT * v10411(struct StateT * v10412);
struct StateT * v11413(struct StateT * v11414);
struct StateT * v11557(struct StateT * v11558);
struct StateT * v2669(struct StateT * v2670);
struct StateT * v8563(struct StateT * v8564);
struct StateT * v4325(struct StateT * v4326);
struct StateT * v3237(struct StateT * v3238);
struct StateT * v10267(struct StateT * v10268);
struct StateT * v10639(struct StateT * v10640);
struct StateT * v3555(struct StateT * v3556);
struct StateT * v12366(struct StateT * v12367);
struct StateT * v13772(struct StateT * v13773);
struct StateT * v10963(struct StateT * v10964);
struct StateT * v2133(struct StateT * v2134);
struct StateT * v11515(struct StateT * v11516);
struct StateT * v4365(struct StateT * v4366);
struct StateT * v8619(struct StateT * v8620);
struct StateT * v11173(struct StateT * v11174);
struct StateT * v2597(struct StateT * v2598);
struct StateT * v9115(struct StateT * v9116);
struct StateT * v8901(struct StateT * v8902);
struct StateT * v10393(struct StateT * v10394);
struct StateT * v3197(struct StateT * v3198);
struct StateT * v9821(struct StateT * v9822);
struct StateT * v9749(struct StateT * v9750);
struct StateT * v9065(struct StateT * v9066);
struct StateT * v11726(struct StateT * v11727);
struct StateT * v10919(struct StateT * v10920);
struct StateT * v10239(struct StateT * v10240);
struct StateT * v4267(struct StateT * v4268);
struct StateT * v3499(struct StateT * v3500);
struct StateT * v2169(struct StateT * v2170);
struct StateT * v4953(struct StateT * v4954);
struct StateT * v2061(struct StateT * v2062);
struct StateT * v10789(struct StateT * v10790);
struct StateT * v11199(struct StateT * v11200);
struct StateT * v10515(struct StateT * v10516);
struct StateT * v13200(struct StateT * v13201);
struct StateT * v10901(struct StateT * v10902);
struct StateT * v1297(struct StateT * v1298);
struct StateT * v3315(struct StateT * v3316);
struct StateT * v4063(struct StateT * v4064);
struct StateT * v10167(struct StateT * v10168);
struct StateT * v10025(struct StateT * v10026);
struct StateT * v4341(struct StateT * v4342);
struct StateT * v10367(struct StateT * v10368);
struct StateT * v2281(struct StateT * v2282);
struct StateT * v3033(struct StateT * v3034);
struct StateT * v3217(struct StateT * v3218);
struct StateT * v10425(struct StateT * v10426);
struct StateT * v8193(struct StateT * v8194);
struct StateT * v2125(struct StateT * v2126);
struct StateT * v11706(struct StateT * v11707);
struct StateT * v11403(struct StateT * v11404);
struct StateT * v12288(struct StateT * v12289);
struct StateT * v3023(struct StateT * v3024);
struct StateT * v10103(struct StateT * v10104);
struct StateT * v2517(struct StateT * v2518);
struct StateT * v12356(struct StateT * v12357);
struct StateT * v8997(struct StateT * v8998);
struct StateT * v2983(struct StateT * v2984);
struct StateT * v8803(struct StateT * v8804);
struct StateT * v2947(struct StateT * v2948);
struct StateT * v13254(struct StateT * v13255);
struct StateT * v2073(struct StateT * v2074);
struct StateT * v11085(struct StateT * v11086);
struct StateT * v10937(struct StateT * v10938);
struct StateT * v387(struct StateT * v388);
struct StateT * v171(struct StateT * v172);
struct StateT * v10047(struct StateT * v10048);
struct StateT * v12424(struct StateT * v12425);
struct StateT * v3095(struct StateT * v3096);
struct StateT * v10839(struct StateT * v10840);
struct StateT * v2825(struct StateT * v2826);
struct StateT * v1915(struct StateT * v1916);
struct StateT * v10979(struct StateT * v10980);
struct StateT * v13946(struct StateT * v13947);
struct StateT * v1439(struct StateT * v1440);
struct StateT * v3979(struct StateT * v3980);
struct StateT * v3685(struct StateT * v3686);
struct StateT * v9249(struct StateT * v9250);
struct StateT * v10615(struct StateT * v10616);
struct StateT * v11463(struct StateT * v11464);
struct StateT * v10467(struct StateT * v10468);
struct StateT * v2787(struct StateT * v2788);
struct StateT * v10559(struct StateT * v10560);
struct StateT * v2159(struct StateT * v2160);
struct StateT * v9329(struct StateT * v9330);
struct StateT * v10779(struct StateT * v10780);
struct StateT * v10185(struct StateT * v10186);
struct StateT * v9933(struct StateT * v9934);
struct StateT * v13424(struct StateT * v13425);
struct StateT * v9197(struct StateT * v9198);
struct StateT * v9207(struct StateT * v9208);
struct StateT * v10805(struct StateT * v10806);
struct StateT * v11479(struct StateT * v11480);
struct StateT * v9959(struct StateT * v9960);
struct StateT * v2317(struct StateT * v2318);
struct StateT * v8491(struct StateT * v8492);
struct StateT * v5115(struct StateT * v5116);
struct StateT * v12220(struct StateT * v12221);
struct StateT * v3289(struct StateT * v3290);
struct StateT * v9697(struct StateT * v9698);
struct StateT * v8813(struct StateT * v8814);
struct StateT * v12714(struct StateT * v12715);
struct StateT * v1799(struct StateT * v1800);
struct StateT * v3013(struct StateT * v3014);
struct StateT * v10035(struct StateT * v10036);
struct StateT * v3053(struct StateT * v3054);
struct StateT * v4373(struct StateT * v4374);
struct StateT * v9493(struct StateT * v9494);
struct StateT * v3525(struct StateT * v3526);
struct StateT * v11567(struct StateT * v11568);
struct StateT * v8075(struct StateT * v8076);
struct StateT * v4683(struct StateT * v4684);
struct StateT * v3989(struct StateT * v3990);
struct StateT * v11075(struct StateT * v11076);
struct StateT * v11295(struct StateT * v11296);
struct StateT * v2343(struct StateT * v2344);
struct StateT * v1181(struct StateT * v1182);
struct StateT * v9105(struct StateT * v9106);
struct StateT * v5393(struct StateT * v5394);
struct StateT * v3675(struct StateT * v3676);
struct StateT * v9181(struct StateT * v9182);
struct StateT * v2291(struct StateT * v2292);
struct StateT * v12230(struct StateT * v12231);
struct StateT * v2993(struct StateT * v2994);
struct StateT * v10533(struct StateT * v10534);
struct StateT * v10497(struct StateT * v10498);
struct StateT * v8611(struct StateT * v8612);
struct StateT * v9667(struct StateT * v9668);
struct StateT * v8847(struct StateT * v8848);
struct StateT * v10997(struct StateT * v10998);
struct StateT * v3279(struct StateT * v3280);
struct StateT * v11321(struct StateT * v11322);
struct StateT * v4047(struct StateT * v4048);
struct StateT * v11884(struct StateT * v11885);
struct StateT * v1853(struct StateT * v1854);
struct StateT * v3473(struct StateT * v3474);
struct StateT * v3701(struct StateT * v3702);
struct StateT * v10477(struct StateT * v10478);
struct StateT * v4413(struct StateT * v4414);
struct StateT * v10401(struct StateT * v10402);
struct StateT * v10585(struct StateT * v10586);
struct StateT * v9891(struct StateT * v9892);
struct StateT * v2641(struct StateT * v2642);
struct StateT * v11219(struct StateT * v11220);
struct StateT * v11597(struct StateT * v11598);
struct StateT * v8855(struct StateT * v8856);
struct StateT * v2099(struct StateT * v2100);
struct StateT * v9943(struct StateT * v9944);
struct StateT * v1923(struct StateT * v1924);
struct StateT * v1583(struct StateT * v1584);
struct StateT * v3121(struct StateT * v3122);
struct StateT * v9601(struct StateT * v9602);
struct StateT * v9841(struct StateT * v9842);
struct StateT * v8737(struct StateT * v8738);
struct StateT * v1931(struct StateT * v1932);
struct StateT * v9951(struct StateT * v9952);
struct StateT * v9899(struct StateT * v9900);
struct StateT * v9365(struct StateT * v9366);
struct StateT * v11810(struct StateT * v11811);
struct StateT * v12404(struct StateT * v12405);
struct StateT * v8583(struct StateT * v8584);
struct StateT * v9125(struct StateT * v9126);
struct StateT * v10567(struct StateT * v10568);
struct StateT * v3401(struct StateT * v3402);
struct StateT * v10989(struct StateT * v10990) {
  int v10991 = v10990->timer;
  int v16914 = v10991 + 1;
  v10990->timer = v16914;
  int * v10993 = v10990->regs;
  int v10994 = v10993[17];
  int * v10995 = v10990->regs;
  int v16919 = (int)((unsigned int)v10994 >> 25);
  v10995[5] = v16919;
  struct StateT * v16912 = v10997(v10990);
  return v16912;
}

struct StateT * v9279(struct StateT * v9280) {
  int v9281 = v9280->timer;
  int v18859 = v9281 + 1;
  v9280->timer = v18859;
  int * v9283 = v9280->regs;
  int v9284 = v9283[19];
  int * v9285 = v9280->regs;
  int v9286 = v9285[17];
  int * v9287 = v9280->regs;
  int v18865 = v9284 ^ v9286;
  v9287[19] = v18865;
  struct StateT * v18857 = v9289(v9280);
  return v18857;
}

struct StateT * v2211(struct StateT * v2212) {
  int * v2213 = v2212->saved_regs;
  int * v2214 = v2212->regs;
  int v2215 = v2214[14];
  v2213[14] = v2215;
  int v2217 = v2212->timer;
  int v21806 = v2217 + 1;
  v2212->timer = v21806;
  int * v2219 = v2212->regs;
  int v2220 = v2219[14];
  int * v2221 = v2212->regs;
  int v2222 = v2221[8];
  int * v2223 = v2212->regs;
  int v21811 = v2220 ^ v2222;
  v2223[14] = v21811;
  struct StateT * v21800 = v2225(v2212);
  return v21800;
}

struct StateT * v9715(struct StateT * v9716) {
  int v9717 = v9716->timer;
  int v18353 = v9717 + 1;
  v9716->timer = v18353;
  int * v9719 = v9716->regs;
  int v9720 = v9719[11];
  int * v9721 = v9716->regs;
  int v18357 = v9720 << 13;
  v9721[11] = v18357;
  struct StateT * v18351 = v9723(v9716);
  return v18351;
}

struct StateT * v11874(struct StateT * v11875) {
  int v11876 = v11875->timer;
  int v15939 = v11876 + 1;
  v11875->timer = v15939;
  int * v11878 = v11875->regs;
  int v11879 = v11878[5];
  int * v11880 = v11875->regs;
  int v11881 = v11880[7];
  int * v11882 = v11875->regs;
  int v15945 = v11879 + v11881;
  v11882[5] = v15945;
  struct StateT * v15937 = v11884(v11875);
  return v15937;
}

struct StateT * v2359(struct StateT * v2360) {
  int v2361 = v2360->timer;
  int v21634 = v2361 + 1;
  v2360->timer = v21634;
  int * v2363 = v2360->regs;
  int v2364 = v2363[18];
  int * v2365 = v2360->regs;
  int v2366 = v2365[20];
  int * v2367 = v2360->regs;
  int v21640 = v2364 | v2366;
  v2367[18] = v21640;
  struct StateT * v21632 = v2369(v2360);
  return v21632;
}

struct StateT * v4575(struct StateT * v4576) {
  int v4577 = v4576->timer;
  int v7219 = v4577 + 1;
  v4576->timer = v7219;
  int * v4579 = v4576->regs;
  int v4580 = v4579[10];
  int * v4581 = v4576->regs;
  int v4582 = v4581[14];
  int * v4583 = v4576->cache_keys;
  int v4584 = v4583[0];
  bool v7226 = v4584 == ((int)((unsigned int)(v4580 + 12) >> 2));
  int v4628;
  if (v7226) {
    int * v4585 = v4576->cache_vals;
    v4585[0] = v4582;
    v4628 = v4582;
  } else {
    int * v4588 = v4576->cache_keys;
    int v4589 = v4588[1];
    bool v7231 = v4589 == ((int)((unsigned int)(v4580 + 12) >> 2));
    int v4626;
    if (v7231) {
      int * v4590 = v4576->cache_keys;
      int * v4591 = v4576->cache_keys;
      int v4592 = v4591[0];
      v4590[1] = v4592;
      int * v4594 = v4576->cache_vals;
      int * v4595 = v4576->cache_vals;
      int v4596 = v4595[0];
      v4594[1] = v4596;
      int * v4598 = v4576->cache_keys;
      int v7239 = (int)((unsigned int)(v4580 + 12) >> 2);
      v4598[0] = v7239;
      int * v4600 = v4576->cache_vals;
      v4600[0] = v4582;
      int v4602 = v4576->timer;
      int v7242 = v4602 + 1;
      v4576->timer = v7242;
      v4626 = v4582;
    } else {
      int * v4605 = v4576->mem;
      int * v4606 = v4576->cache_keys;
      int v4607 = v4606[1];
      int * v4608 = v4576->cache_vals;
      int v4609 = v4608[1];
      v4605[v4607] = v4609;
      int * v4611 = v4576->cache_keys;
      int * v4612 = v4576->cache_keys;
      int v4613 = v4612[0];
      v4611[1] = v4613;
      int * v4615 = v4576->cache_vals;
      int * v4616 = v4576->cache_vals;
      int v4617 = v4616[0];
      v4615[1] = v4617;
      int * v4619 = v4576->cache_keys;
      int v7255 = (int)((unsigned int)(v4580 + 12) >> 2);
      v4619[0] = v7255;
      int * v4621 = v4576->cache_vals;
      v4621[0] = v4582;
      int v4623 = v4576->timer;
      int v7258 = v4623 + 100;
      v4576->timer = v7258;
      v4626 = v4582;
    }
    v4628 = v4626;
  }
  struct StateT * v7217 = v4629(v4576);
  return v7217;
}

struct StateT * v11471(struct StateT * v11472) {
  int v11473 = v11472->timer;
  int v16355 = v11473 + 1;
  v11472->timer = v16355;
  int * v11475 = v11472->regs;
  int v11476 = v11475[11];
  int * v11477 = v11472->regs;
  int v16359 = v11476 << 18;
  v11477[11] = v16359;
  struct StateT * v16353 = v11479(v11472);
  return v16353;
}

struct StateT * v8207(struct StateT * v8208) {
  int v8209 = v8208->timer;
  int v20021 = v8209 + 1;
  v8208->timer = v20021;
  int * v8211 = v8208->regs;
  v8211[6] = 857759744;
  struct StateT * v20019 = v8213(v8208);
  return v20019;
}

struct StateT * v9057(struct StateT * v9058) {
  int v9059 = v9058->timer;
  int v19120 = v9059 + 1;
  v9058->timer = v19120;
  int * v9061 = v9058->regs;
  int v9062 = v9061[18];
  int * v9063 = v9058->regs;
  int v19124 = v9062 << 13;
  v9063[18] = v19124;
  struct StateT * v19118 = v9065(v9058);
  return v19118;
}

struct StateT * v8787(struct StateT * v8788) {
  int v8789 = v8788->timer;
  int v19431 = v8789 + 1;
  v8788->timer = v19431;
  int * v8791 = v8788->regs;
  int v8792 = v8791[15];
  int * v8793 = v8788->regs;
  int v19436 = (int)((unsigned int)v8792 >> 23);
  v8793[20] = v19436;
  struct StateT * v19429 = v8795(v8788);
  return v19429;
}

struct StateT * v9443(struct StateT * v9444) {
  int v9445 = v9444->timer;
  int v18668 = v9445 + 1;
  v9444->timer = v18668;
  int * v9447 = v9444->regs;
  int v9448 = v9447[23];
  int * v9449 = v9444->regs;
  int v9450 = v9449[15];
  int * v9451 = v9444->regs;
  int v18674 = v9448 ^ v9450;
  v9451[23] = v18674;
  struct StateT * v18666 = v9453(v9444);
  return v18666;
}

struct StateT * v14062(struct StateT * v14063) {
  int v14064 = v14063->timer;
  int v14078 = v14064 + 1;
  v14063->timer = v14078;
  int * v14066 = v14063->regs;
  int v14067 = v14066[2];
  int * v14068 = v14063->regs;
  int v14082 = v14067 + 96;
  v14068[2] = v14082;
  struct StateT * v14076 = v14070(v14063);
  return v14076;
}

struct StateT * v9549(struct StateT * v9550) {
  int v9551 = v9550->timer;
  int v18544 = v9551 + 1;
  v9550->timer = v18544;
  int * v9553 = v9550->regs;
  int v9554 = v9553[15];
  int * v9555 = v9550->regs;
  int v18549 = (int)((unsigned int)v9554 >> 23);
  v9555[9] = v18549;
  struct StateT * v18542 = v9557(v9550);
  return v18542;
}

struct StateT * v11357(struct StateT * v11358) {
  int v11359 = v11358->timer;
  int v16486 = v11359 + 1;
  v11358->timer = v16486;
  int * v11361 = v11358->regs;
  int v11362 = v11361[8];
  int * v11363 = v11358->regs;
  int v16491 = (int)((unsigned int)v11362 >> 19);
  v11363[9] = v16491;
  struct StateT * v16484 = v11365(v11358);
  return v16484;
}

struct StateT * v10877(struct StateT * v10878) {
  int * v10879 = v10878->saved_regs;
  int * v10880 = v10878->regs;
  int v10881 = v10880[11];
  v10879[11] = v10881;
  int v10883 = v10878->timer;
  int v17042 = v10883 + 1;
  v10878->timer = v17042;
  int * v10885 = v10878->regs;
  int v10886 = v10885[20];
  int * v10887 = v10878->regs;
  int v10888 = v10887[12];
  int * v10889 = v10878->regs;
  int v17048 = v10886 + v10888;
  v10889[11] = v17048;
  struct StateT * v17036 = v10891(v10878);
  return v17036;
}

struct StateT * v2617(struct StateT * v2618) {
  int v2619 = v2618->timer;
  int v21344 = v2619 + 1;
  v2618->timer = v21344;
  int * v2621 = v2618->regs;
  int v2622 = v2621[9];
  int * v2623 = v2618->regs;
  int v2624 = v2623[26];
  int * v2625 = v2618->regs;
  int v21351 = v2622 + v2624;
  v2625[15] = v21351;
  struct StateT * v21342 = v2627(v2618);
  return v21342;
}

struct StateT * v8655(struct StateT * v8656) {
  int v8657 = v8656->timer;
  int v19583 = v8657 + 1;
  v8656->timer = v19583;
  int * v8659 = v8656->regs;
  int v8660 = v8659[18];
  int * v8661 = v8656->regs;
  int v19588 = (int)((unsigned int)v8660 >> 25);
  v8661[20] = v19588;
  struct StateT * v19581 = v8663(v8656);
  return v19581;
}

struct StateT * v8213(struct StateT * v8214) {
  int * v8215 = v8214->saved_regs;
  int * v8216 = v8214->regs;
  int v8217 = v8216[7];
  v8215[7] = v8217;
  int v8219 = v8214->timer;
  int v19974 = v8219 + 1;
  v8214->timer = v19974;
  int * v8221 = v8214->regs;
  int v8222 = v8221[2];
  int * v8223 = v8214->cache_keys;
  int v8224 = v8223[0];
  bool v19979 = v8224 == ((int)((unsigned int)(v8222 + 12) >> 2));
  int v8272;
  if (v19979) {
    int * v8225 = v8214->cache_vals;
    int v8226 = v8225[0];
    v8272 = v8226;
  } else {
    int * v8228 = v8214->cache_keys;
    int v8229 = v8228[1];
    bool v19984 = v8229 == ((int)((unsigned int)(v8222 + 12) >> 2));
    int v8270;
    if (v19984) {
      int * v8230 = v8214->cache_vals;
      int v8231 = v8230[1];
      int * v8232 = v8214->cache_keys;
      int * v8233 = v8214->cache_keys;
      int v8234 = v8233[0];
      v8232[1] = v8234;
      int * v8236 = v8214->cache_vals;
      int * v8237 = v8214->cache_vals;
      int v8238 = v8237[0];
      v8236[1] = v8238;
      int * v8240 = v8214->cache_keys;
      int v19993 = (int)((unsigned int)(v8222 + 12) >> 2);
      v8240[0] = v19993;
      int * v8242 = v8214->cache_vals;
      v8242[0] = v8231;
      int v8244 = v8214->timer;
      int v19996 = v8244 + 1;
      v8214->timer = v19996;
      v8270 = v8231;
    } else {
      int * v8247 = v8214->mem;
      int v19998 = (int)((unsigned int)(v8222 + 12) >> 2);
      int v8248 = v8247[v19998];
      int * v8249 = v8214->mem;
      int * v8250 = v8214->cache_keys;
      int v8251 = v8250[1];
      int * v8252 = v8214->cache_vals;
      int v8253 = v8252[1];
      v8249[v8251] = v8253;
      int * v8255 = v8214->cache_keys;
      int * v8256 = v8214->cache_keys;
      int v8257 = v8256[0];
      v8255[1] = v8257;
      int * v8259 = v8214->cache_vals;
      int * v8260 = v8214->cache_vals;
      int v8261 = v8260[0];
      v8259[1] = v8261;
      int * v8263 = v8214->cache_keys;
      v8263[0] = v19998;
      int * v8265 = v8214->cache_vals;
      v8265[0] = v8248;
      int v8267 = v8214->timer;
      int v20013 = v8267 + 100;
      v8214->timer = v20013;
      v8270 = v8248;
    }
    v8272 = v8270;
  }
  int * v8273 = v8214->regs;
  v8273[7] = v8272;
  struct StateT * v19968 = v8275(v8214);
  return v19968;
}

struct StateT * v10349(struct StateT * v10350) {
  int v10351 = v10350->timer;
  int v17634 = v10351 + 1;
  v10350->timer = v17634;
  int * v10353 = v10350->regs;
  int v10354 = v10353[8];
  int * v10355 = v10350->regs;
  int v10356 = v10355[20];
  int * v10357 = v10350->regs;
  int v17640 = v10354 | v10356;
  v10357[8] = v17640;
  struct StateT * v17632 = v10359(v10350);
  return v17632;
}

struct StateT * v2677(struct StateT * v2678) {
  int v2679 = v2678->timer;
  int v21280 = v2679 + 1;
  v2678->timer = v21280;
  int * v2681 = v2678->regs;
  int v2682 = v2681[15];
  int * v2683 = v2678->regs;
  int v21284 = v2682 << 18;
  v2683[15] = v21284;
  struct StateT * v21278 = v2685(v2678);
  return v21278;
}

struct StateT * v9591(struct StateT * v9592) {
  int v9593 = v9592->timer;
  int v18494 = v9593 + 1;
  v9592->timer = v18494;
  int * v9595 = v9592->regs;
  int v9596 = v9595[6];
  int * v9597 = v9592->regs;
  int v9598 = v9597[9];
  int * v9599 = v9592->regs;
  int v18500 = v9596 | v9598;
  v9599[6] = v18500;
  struct StateT * v18492 = v9601(v9592);
  return v18492;
}

struct StateT * v63(struct StateT * v64) {
  int v65 = v64->timer;
  int v23658 = v65 + 1;
  v64->timer = v23658;
  int * v67 = v64->regs;
  int v68 = v67[2];
  int * v69 = v64->regs;
  int v70 = v69[8];
  int * v71 = v64->cache_keys;
  int v72 = v71[0];
  bool v23665 = v72 == ((int)((unsigned int)(v68 + 88) >> 2));
  int v116;
  if (v23665) {
    int * v73 = v64->cache_vals;
    v73[0] = v70;
    v116 = v70;
  } else {
    int * v76 = v64->cache_keys;
    int v77 = v76[1];
    bool v23670 = v77 == ((int)((unsigned int)(v68 + 88) >> 2));
    int v114;
    if (v23670) {
      int * v78 = v64->cache_keys;
      int * v79 = v64->cache_keys;
      int v80 = v79[0];
      v78[1] = v80;
      int * v82 = v64->cache_vals;
      int * v83 = v64->cache_vals;
      int v84 = v83[0];
      v82[1] = v84;
      int * v86 = v64->cache_keys;
      int v23678 = (int)((unsigned int)(v68 + 88) >> 2);
      v86[0] = v23678;
      int * v88 = v64->cache_vals;
      v88[0] = v70;
      int v90 = v64->timer;
      int v23681 = v90 + 1;
      v64->timer = v23681;
      v114 = v70;
    } else {
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
      int v23694 = (int)((unsigned int)(v68 + 88) >> 2);
      v107[0] = v23694;
      int * v109 = v64->cache_vals;
      v109[0] = v70;
      int v111 = v64->timer;
      int v23697 = v111 + 100;
      v64->timer = v23697;
      v114 = v70;
    }
    v116 = v114;
  }
  struct StateT * v23656 = v117(v64);
  return v23656;
}

struct StateT * v2265(struct StateT * v2266) {
  int v2267 = v2266->timer;
  int v21744 = v2267 + 1;
  v2266->timer = v21744;
  int * v2269 = v2266->regs;
  int v2270 = v2269[15];
  int * v2271 = v2266->regs;
  int v21749 = (int)((unsigned int)v2270 >> 23);
  v2271[20] = v21749;
  struct StateT * v21742 = v2273(v2266);
  return v21742;
}

struct StateT * v9627(struct StateT * v9628) {
  int v9629 = v9628->timer;
  int v18453 = v9629 + 1;
  v9628->timer = v18453;
  int * v9631 = v9628->regs;
  int v9632 = v9631[27];
  int * v9633 = v9628->regs;
  int v9634 = v9633[11];
  int * v9635 = v9628->regs;
  int v18459 = v9632 ^ v9634;
  v9635[27] = v18459;
  struct StateT * v18451 = v9637(v9628);
  return v18451;
}

struct StateT * v9557(struct StateT * v9558) {
  int v9559 = v9558->timer;
  int v18535 = v9559 + 1;
  v9558->timer = v18535;
  int * v9561 = v9558->regs;
  int v9562 = v9561[15];
  int * v9563 = v9558->regs;
  int v18539 = v9562 << 9;
  v9563[15] = v18539;
  struct StateT * v18533 = v9565(v9558);
  return v18533;
}

struct StateT * v2225(struct StateT * v2226) {
  int v2227 = v2226->timer;
  int v21790 = v2227 + 1;
  v2226->timer = v21790;
  int * v2229 = v2226->regs;
  int v2230 = v2229[12];
  int * v2231 = v2226->regs;
  int v2232 = v2231[21];
  int * v2233 = v2226->regs;
  int v21797 = v2230 + v2232;
  v2233[15] = v21797;
  struct StateT * v21788 = v2235(v2226);
  return v21788;
}

struct StateT * v4131(struct StateT * v4132) {
  int v4133 = v4132->timer;
  int v7616 = v4133 + 1;
  v4132->timer = v7616;
  int * v4135 = v4132->regs;
  int v4136 = v4135[2];
  int * v4137 = v4132->cache_keys;
  int v4138 = v4137[0];
  bool v7621 = v4138 == ((int)((unsigned int)(v4136 + 32) >> 2));
  int v4186;
  if (v7621) {
    int * v4139 = v4132->cache_vals;
    int v4140 = v4139[0];
    v4186 = v4140;
  } else {
    int * v4142 = v4132->cache_keys;
    int v4143 = v4142[1];
    bool v7626 = v4143 == ((int)((unsigned int)(v4136 + 32) >> 2));
    int v4184;
    if (v7626) {
      int * v4144 = v4132->cache_vals;
      int v4145 = v4144[1];
      int * v4146 = v4132->cache_keys;
      int * v4147 = v4132->cache_keys;
      int v4148 = v4147[0];
      v4146[1] = v4148;
      int * v4150 = v4132->cache_vals;
      int * v4151 = v4132->cache_vals;
      int v4152 = v4151[0];
      v4150[1] = v4152;
      int * v4154 = v4132->cache_keys;
      int v7635 = (int)((unsigned int)(v4136 + 32) >> 2);
      v4154[0] = v7635;
      int * v4156 = v4132->cache_vals;
      v4156[0] = v4145;
      int v4158 = v4132->timer;
      int v7638 = v4158 + 1;
      v4132->timer = v7638;
      v4184 = v4145;
    } else {
      int * v4161 = v4132->mem;
      int v7640 = (int)((unsigned int)(v4136 + 32) >> 2);
      int v4162 = v4161[v7640];
      int * v4163 = v4132->mem;
      int * v4164 = v4132->cache_keys;
      int v4165 = v4164[1];
      int * v4166 = v4132->cache_vals;
      int v4167 = v4166[1];
      v4163[v4165] = v4167;
      int * v4169 = v4132->cache_keys;
      int * v4170 = v4132->cache_keys;
      int v4171 = v4170[0];
      v4169[1] = v4171;
      int * v4173 = v4132->cache_vals;
      int * v4174 = v4132->cache_vals;
      int v4175 = v4174[0];
      v4173[1] = v4175;
      int * v4177 = v4132->cache_keys;
      v4177[0] = v7640;
      int * v4179 = v4132->cache_vals;
      v4179[0] = v4162;
      int v4181 = v4132->timer;
      int v7655 = v4181 + 100;
      v4132->timer = v7655;
      v4184 = v4162;
    }
    v4186 = v4184;
  }
  int * v4187 = v4132->regs;
  v4187[30] = v4186;
  struct StateT * v7614 = v4189(v4132);
  return v7614;
}

struct StateT * v3447(struct StateT * v3448) {
  int v3449 = v3448->timer;
  int v20394 = v3449 + 1;
  v3448->timer = v20394;
  int * v3451 = v3448->regs;
  int v3452 = v3451[15];
  int * v3453 = v3448->regs;
  int v20399 = (int)((unsigned int)v3452 >> 14);
  v3453[9] = v20399;
  struct StateT * v20392 = v3455(v3448);
  return v20392;
}

struct StateT * v9085(struct StateT * v9086) {
  int v9087 = v9086->timer;
  int v19085 = v9087 + 1;
  v9086->timer = v19085;
  int * v9089 = v9086->regs;
  int v9090 = v9089[23];
  int * v9091 = v9086->regs;
  int v9092 = v9091[8];
  int * v9093 = v9086->regs;
  int v19091 = v9090 ^ v9092;
  v9093[23] = v19091;
  struct StateT * v19083 = v9095(v9086);
  return v19083;
}

struct StateT * v9031(struct StateT * v9032) {
  int v9033 = v9032->timer;
  int v19150 = v9033 + 1;
  v9032->timer = v19150;
  int * v9035 = v9032->regs;
  int v9036 = v9035[9];
  int * v9037 = v9032->regs;
  int v19154 = v9036 << 13;
  v9037[9] = v19154;
  struct StateT * v19148 = v9039(v9032);
  return v19148;
}

struct StateT * v3167(struct StateT * v3168) {
  int v3169 = v3168->timer;
  int v20716 = v3169 + 1;
  v3168->timer = v20716;
  int * v3171 = v3168->regs;
  int v3172 = v3171[25];
  int * v3173 = v3168->regs;
  int v3174 = v3173[15];
  int * v3175 = v3168->regs;
  int v20722 = v3172 ^ v3174;
  v3175[25] = v20722;
  struct StateT * v20714 = v3177(v3168);
  return v20714;
}

struct StateT * v11137(struct StateT * v11138) {
  int v11139 = v11138->timer;
  int v16738 = v11139 + 1;
  v11138->timer = v16738;
  int * v11141 = v11138->regs;
  int v11142 = v11141[15];
  int * v11143 = v11138->regs;
  int v11144 = v11143[9];
  int * v11145 = v11138->regs;
  int v16744 = v11142 | v11144;
  v11145[15] = v16744;
  struct StateT * v16736 = v11147(v11138);
  return v16736;
}

struct StateT * v13366(struct StateT * v13367) {
  int v13368 = v13367->timer;
  int v14615 = v13368 + 1;
  v13367->timer = v14615;
  int * v13370 = v13367->regs;
  int v13371 = v13370[2];
  int * v13372 = v13367->cache_keys;
  int v13373 = v13372[0];
  bool v14620 = v13373 == ((int)((unsigned int)(v13371 + 88) >> 2));
  int v13421;
  if (v14620) {
    int * v13374 = v13367->cache_vals;
    int v13375 = v13374[0];
    v13421 = v13375;
  } else {
    int * v13377 = v13367->cache_keys;
    int v13378 = v13377[1];
    bool v14625 = v13378 == ((int)((unsigned int)(v13371 + 88) >> 2));
    int v13419;
    if (v14625) {
      int * v13379 = v13367->cache_vals;
      int v13380 = v13379[1];
      int * v13381 = v13367->cache_keys;
      int * v13382 = v13367->cache_keys;
      int v13383 = v13382[0];
      v13381[1] = v13383;
      int * v13385 = v13367->cache_vals;
      int * v13386 = v13367->cache_vals;
      int v13387 = v13386[0];
      v13385[1] = v13387;
      int * v13389 = v13367->cache_keys;
      int v14634 = (int)((unsigned int)(v13371 + 88) >> 2);
      v13389[0] = v14634;
      int * v13391 = v13367->cache_vals;
      v13391[0] = v13380;
      int v13393 = v13367->timer;
      int v14637 = v13393 + 1;
      v13367->timer = v14637;
      v13419 = v13380;
    } else {
      int * v13396 = v13367->mem;
      int v14639 = (int)((unsigned int)(v13371 + 88) >> 2);
      int v13397 = v13396[v14639];
      int * v13398 = v13367->mem;
      int * v13399 = v13367->cache_keys;
      int v13400 = v13399[1];
      int * v13401 = v13367->cache_vals;
      int v13402 = v13401[1];
      v13398[v13400] = v13402;
      int * v13404 = v13367->cache_keys;
      int * v13405 = v13367->cache_keys;
      int v13406 = v13405[0];
      v13404[1] = v13406;
      int * v13408 = v13367->cache_vals;
      int * v13409 = v13367->cache_vals;
      int v13410 = v13409[0];
      v13408[1] = v13410;
      int * v13412 = v13367->cache_keys;
      v13412[0] = v14639;
      int * v13414 = v13367->cache_vals;
      v13414[0] = v13397;
      int v13416 = v13367->timer;
      int v14654 = v13416 + 100;
      v13367->timer = v14654;
      v13419 = v13397;
    }
    v13421 = v13419;
  }
  int * v13422 = v13367->regs;
  v13422[8] = v13421;
  struct StateT * v14613 = v13424(v13367);
  return v14613;
}

struct StateT * v9767(struct StateT * v9768) {
  int v9769 = v9768->timer;
  int v18293 = v9769 + 1;
  v9768->timer = v18293;
  int * v9771 = v9768->regs;
  int v9772 = v9771[6];
  int * v9773 = v9768->regs;
  int v18297 = v9772 << 13;
  v9773[6] = v18297;
  struct StateT * v18291 = v9775(v9768);
  return v18291;
}

struct StateT * v2797(struct StateT * v2798) {
  int * v2799 = v2798->saved_regs;
  int * v2800 = v2798->regs;
  int v2801 = v2800[19];
  v2799[19] = v2801;
  int v2803 = v2798->timer;
  int v21143 = v2803 + 1;
  v2798->timer = v21143;
  int * v2805 = v2798->regs;
  int v2806 = v2805[19];
  int * v2807 = v2798->regs;
  int v2808 = v2807[17];
  int * v2809 = v2798->regs;
  int v21148 = v2806 ^ v2808;
  v2809[19] = v21148;
  struct StateT * v21137 = v2811(v2798);
  return v21137;
}

struct StateT * v2183(struct StateT * v2184) {
  int * v2185 = v2184->saved_regs;
  int * v2186 = v2184->regs;
  int v2187 = v2186[13];
  v2185[13] = v2187;
  int v2189 = v2184->timer;
  int v21834 = v2189 + 1;
  v2184->timer = v21834;
  int * v2191 = v2184->regs;
  int v2192 = v2191[13];
  int * v2193 = v2184->regs;
  int v2194 = v2193[9];
  int * v2195 = v2184->regs;
  int v21839 = v2192 ^ v2194;
  v2195[13] = v21839;
  struct StateT * v21828 = v2197(v2184);
  return v21828;
}

struct StateT * v891(struct StateT * v892) {
  int v893 = v892->timer;
  int v22963 = v893 + 1;
  v892->timer = v22963;
  int * v895 = v892->regs;
  int v896 = v895[12];
  int * v897 = v892->cache_keys;
  int v898 = v897[0];
  bool v22968 = v898 == ((int)((unsigned int)(v896 + 12) >> 2));
  int v946;
  if (v22968) {
    int * v899 = v892->cache_vals;
    int v900 = v899[0];
    v946 = v900;
  } else {
    int * v902 = v892->cache_keys;
    int v903 = v902[1];
    bool v22973 = v903 == ((int)((unsigned int)(v896 + 12) >> 2));
    int v944;
    if (v22973) {
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
      int v22982 = (int)((unsigned int)(v896 + 12) >> 2);
      v914[0] = v22982;
      int * v916 = v892->cache_vals;
      v916[0] = v905;
      int v918 = v892->timer;
      int v22985 = v918 + 1;
      v892->timer = v22985;
      v944 = v905;
    } else {
      int * v921 = v892->mem;
      int v22987 = (int)((unsigned int)(v896 + 12) >> 2);
      int v922 = v921[v22987];
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
      v937[0] = v22987;
      int * v939 = v892->cache_vals;
      v939[0] = v922;
      int v941 = v892->timer;
      int v23002 = v941 + 100;
      v892->timer = v23002;
      v944 = v922;
    }
    v946 = v944;
  }
  int * v947 = v892->regs;
  v947[6] = v946;
  struct StateT * v22961 = v949(v892);
  return v22961;
}

struct StateT * v2473(struct StateT * v2474) {
  int v2475 = v2474->timer;
  int v21511 = v2475 + 1;
  v2474->timer = v21511;
  int * v2477 = v2474->regs;
  int v2478 = v2477[15];
  int * v2479 = v2474->regs;
  int v21515 = v2478 << 13;
  v2479[15] = v21515;
  struct StateT * v21509 = v2481(v2474);
  return v21509;
}

struct StateT * v11497(struct StateT * v11498) {
  int v11499 = v11498->timer;
  int v16325 = v11499 + 1;
  v11498->timer = v16325;
  int * v11501 = v11498->regs;
  int v11502 = v11501[15];
  int * v11503 = v11498->regs;
  int v16329 = v11502 << 18;
  v11503[15] = v16329;
  struct StateT * v16323 = v11505(v11498);
  return v16323;
}

struct StateT * v9145(struct StateT * v9146) {
  int v9147 = v9146->timer;
  int v19013 = v9147 + 1;
  v9146->timer = v19013;
  int * v9149 = v9146->regs;
  int v9150 = v9149[8];
  int * v9151 = v9146->regs;
  int v9152 = v9151[25];
  int * v9153 = v9146->regs;
  int v19020 = v9150 + v9152;
  v9153[5] = v19020;
  struct StateT * v19011 = v9155(v9146);
  return v19011;
}

struct StateT * v9741(struct StateT * v9742) {
  int v9743 = v9742->timer;
  int v18323 = v9743 + 1;
  v9742->timer = v18323;
  int * v9745 = v9742->regs;
  int v9746 = v9745[15];
  int * v9747 = v9742->regs;
  int v18327 = v9746 << 13;
  v9747[15] = v18327;
  struct StateT * v18321 = v9749(v9742);
  return v18321;
}

struct StateT * v9417(struct StateT * v9418) {
  int v9419 = v9418->timer;
  int v18700 = v9419 + 1;
  v9418->timer = v18700;
  int * v9421 = v9418->regs;
  int v9422 = v9421[17];
  int * v9423 = v9418->regs;
  int v18705 = (int)((unsigned int)v9422 >> 25);
  v9423[5] = v18705;
  struct StateT * v18698 = v9425(v9418);
  return v18698;
}

struct StateT * v10771(struct StateT * v10772) {
  int v10773 = v10772->timer;
  int v17160 = v10773 + 1;
  v10772->timer = v17160;
  int * v10775 = v10772->regs;
  int v10776 = v10775[17];
  int * v10777 = v10772->regs;
  int v17164 = v10776 << 18;
  v10777[17] = v17164;
  struct StateT * v17158 = v10779(v10772);
  return v17158;
}

struct StateT * v4121(struct StateT * v4122) {
  int v4123 = v4122->timer;
  int v7664 = v4123 + 1;
  v4122->timer = v7664;
  int * v4125 = v4122->regs;
  int v4126 = v4125[17];
  int * v4127 = v4122->regs;
  int v4128 = v4127[30];
  int * v4129 = v4122->regs;
  int v7670 = v4126 + v4128;
  v4129[17] = v7670;
  struct StateT * v7662 = v4131(v4122);
  return v7662;
}

struct StateT * v1065(struct StateT * v1066) {
  int v1067 = v1066->timer;
  int v22819 = v1067 + 1;
  v1066->timer = v22819;
  int * v1069 = v1066->regs;
  int v1070 = v1069[12];
  int * v1071 = v1066->cache_keys;
  int v1072 = v1071[0];
  bool v22824 = v1072 == ((int)((unsigned int)(v1070 + 24) >> 2));
  int v1120;
  if (v22824) {
    int * v1073 = v1066->cache_vals;
    int v1074 = v1073[0];
    v1120 = v1074;
  } else {
    int * v1076 = v1066->cache_keys;
    int v1077 = v1076[1];
    bool v22829 = v1077 == ((int)((unsigned int)(v1070 + 24) >> 2));
    int v1118;
    if (v22829) {
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
      int v22838 = (int)((unsigned int)(v1070 + 24) >> 2);
      v1088[0] = v22838;
      int * v1090 = v1066->cache_vals;
      v1090[0] = v1079;
      int v1092 = v1066->timer;
      int v22841 = v1092 + 1;
      v1066->timer = v22841;
      v1118 = v1079;
    } else {
      int * v1095 = v1066->mem;
      int v22843 = (int)((unsigned int)(v1070 + 24) >> 2);
      int v1096 = v1095[v22843];
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
      v1111[0] = v22843;
      int * v1113 = v1066->cache_vals;
      v1113[0] = v1096;
      int v1115 = v1066->timer;
      int v22858 = v1115 + 100;
      v1066->timer = v22858;
      v1118 = v1096;
    }
    v1120 = v1118;
  }
  int * v1121 = v1066->regs;
  v1121[24] = v1120;
  struct StateT * v22817 = v1123(v1066);
  return v22817;
}

struct StateT * v12552(struct StateT * v12553) {
  int v12554 = v12553->timer;
  int v15295 = v12554 + 1;
  v12553->timer = v15295;
  int * v12556 = v12553->regs;
  int v12557 = v12556[10];
  int * v12558 = v12553->regs;
  int v12559 = v12558[28];
  int * v12560 = v12553->cache_keys;
  int v12561 = v12560[0];
  bool v15302 = v12561 == ((int)((unsigned int)(v12557 + 8) >> 2));
  int v12605;
  if (v15302) {
    int * v12562 = v12553->cache_vals;
    v12562[0] = v12559;
    v12605 = v12559;
  } else {
    int * v12565 = v12553->cache_keys;
    int v12566 = v12565[1];
    bool v15307 = v12566 == ((int)((unsigned int)(v12557 + 8) >> 2));
    int v12603;
    if (v15307) {
      int * v12567 = v12553->cache_keys;
      int * v12568 = v12553->cache_keys;
      int v12569 = v12568[0];
      v12567[1] = v12569;
      int * v12571 = v12553->cache_vals;
      int * v12572 = v12553->cache_vals;
      int v12573 = v12572[0];
      v12571[1] = v12573;
      int * v12575 = v12553->cache_keys;
      int v15315 = (int)((unsigned int)(v12557 + 8) >> 2);
      v12575[0] = v15315;
      int * v12577 = v12553->cache_vals;
      v12577[0] = v12559;
      int v12579 = v12553->timer;
      int v15318 = v12579 + 1;
      v12553->timer = v15318;
      v12603 = v12559;
    } else {
      int * v12582 = v12553->mem;
      int * v12583 = v12553->cache_keys;
      int v12584 = v12583[1];
      int * v12585 = v12553->cache_vals;
      int v12586 = v12585[1];
      v12582[v12584] = v12586;
      int * v12588 = v12553->cache_keys;
      int * v12589 = v12553->cache_keys;
      int v12590 = v12589[0];
      v12588[1] = v12590;
      int * v12592 = v12553->cache_vals;
      int * v12593 = v12553->cache_vals;
      int v12594 = v12593[0];
      v12592[1] = v12594;
      int * v12596 = v12553->cache_keys;
      int v15331 = (int)((unsigned int)(v12557 + 8) >> 2);
      v12596[0] = v15331;
      int * v12598 = v12553->cache_vals;
      v12598[0] = v12559;
      int v12600 = v12553->timer;
      int v15334 = v12600 + 100;
      v12553->timer = v15334;
      v12603 = v12559;
    }
    v12605 = v12603;
  }
  struct StateT * v15293 = v12606(v12553);
  return v15293;
}

struct StateT * v657(struct StateT * v658) {
  int v659 = v658->timer;
  int v23163 = v659 + 1;
  v658->timer = v23163;
  int * v661 = v658->regs;
  int v662 = v661[2];
  int * v663 = v658->regs;
  int v664 = v663[27];
  int * v665 = v658->cache_keys;
  int v666 = v665[0];
  bool v23170 = v666 == ((int)((unsigned int)(v662 + 44) >> 2));
  int v710;
  if (v23170) {
    int * v667 = v658->cache_vals;
    v667[0] = v664;
    v710 = v664;
  } else {
    int * v670 = v658->cache_keys;
    int v671 = v670[1];
    bool v23175 = v671 == ((int)((unsigned int)(v662 + 44) >> 2));
    int v708;
    if (v23175) {
      int * v672 = v658->cache_keys;
      int * v673 = v658->cache_keys;
      int v674 = v673[0];
      v672[1] = v674;
      int * v676 = v658->cache_vals;
      int * v677 = v658->cache_vals;
      int v678 = v677[0];
      v676[1] = v678;
      int * v680 = v658->cache_keys;
      int v23183 = (int)((unsigned int)(v662 + 44) >> 2);
      v680[0] = v23183;
      int * v682 = v658->cache_vals;
      v682[0] = v664;
      int v684 = v658->timer;
      int v23186 = v684 + 1;
      v658->timer = v23186;
      v708 = v664;
    } else {
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
      int v23199 = (int)((unsigned int)(v662 + 44) >> 2);
      v701[0] = v23199;
      int * v703 = v658->cache_vals;
      v703[0] = v664;
      int v705 = v658->timer;
      int v23202 = v705 + 100;
      v658->timer = v23202;
      v708 = v664;
    }
    v710 = v708;
  }
  struct StateT * v23161 = v711(v658);
  return v23161;
}

struct StateT * v11393(struct StateT * v11394) {
  int v11395 = v11394->timer;
  int v16444 = v11395 + 1;
  v11394->timer = v16444;
  int * v11397 = v11394->regs;
  int v11398 = v11397[12];
  int * v11399 = v11394->regs;
  int v11400 = v11399[15];
  int * v11401 = v11394->regs;
  int v16450 = v11398 ^ v11400;
  v11401[12] = v16450;
  struct StateT * v16442 = v11403(v11394);
  return v16442;
}

struct StateT * v2369(struct StateT * v2370) {
  int * v2371 = v2370->saved_regs;
  int * v2372 = v2370->regs;
  int v2373 = v2372[26];
  v2371[26] = v2373;
  int v2375 = v2370->timer;
  int v21624 = v2375 + 1;
  v2370->timer = v21624;
  int * v2377 = v2370->regs;
  int v2378 = v2377[26];
  int * v2379 = v2370->regs;
  int v2380 = v2379[15];
  int * v2381 = v2370->regs;
  int v21629 = v2378 ^ v2380;
  v2381[26] = v21629;
  struct StateT * v21618 = v2383(v2370);
  return v21618;
}

struct StateT * v12498(struct StateT * v12499) {
  int v12500 = v12499->timer;
  int v15340 = v12500 + 1;
  v12499->timer = v15340;
  int * v12502 = v12499->regs;
  int v12503 = v12502[10];
  int * v12504 = v12499->regs;
  int v12505 = v12504[29];
  int * v12506 = v12499->cache_keys;
  int v12507 = v12506[0];
  bool v15347 = v12507 == ((int)((unsigned int)(v12503 + 4) >> 2));
  int v12551;
  if (v15347) {
    int * v12508 = v12499->cache_vals;
    v12508[0] = v12505;
    v12551 = v12505;
  } else {
    int * v12511 = v12499->cache_keys;
    int v12512 = v12511[1];
    bool v15352 = v12512 == ((int)((unsigned int)(v12503 + 4) >> 2));
    int v12549;
    if (v15352) {
      int * v12513 = v12499->cache_keys;
      int * v12514 = v12499->cache_keys;
      int v12515 = v12514[0];
      v12513[1] = v12515;
      int * v12517 = v12499->cache_vals;
      int * v12518 = v12499->cache_vals;
      int v12519 = v12518[0];
      v12517[1] = v12519;
      int * v12521 = v12499->cache_keys;
      int v15360 = (int)((unsigned int)(v12503 + 4) >> 2);
      v12521[0] = v15360;
      int * v12523 = v12499->cache_vals;
      v12523[0] = v12505;
      int v12525 = v12499->timer;
      int v15363 = v12525 + 1;
      v12499->timer = v15363;
      v12549 = v12505;
    } else {
      int * v12528 = v12499->mem;
      int * v12529 = v12499->cache_keys;
      int v12530 = v12529[1];
      int * v12531 = v12499->cache_vals;
      int v12532 = v12531[1];
      v12528[v12530] = v12532;
      int * v12534 = v12499->cache_keys;
      int * v12535 = v12499->cache_keys;
      int v12536 = v12535[0];
      v12534[1] = v12536;
      int * v12538 = v12499->cache_vals;
      int * v12539 = v12499->cache_vals;
      int v12540 = v12539[0];
      v12538[1] = v12540;
      int * v12542 = v12499->cache_keys;
      int v15376 = (int)((unsigned int)(v12503 + 4) >> 2);
      v12542[0] = v15376;
      int * v12544 = v12499->cache_vals;
      v12544[0] = v12505;
      int v12546 = v12499->timer;
      int v15379 = v12546 + 100;
      v12499->timer = v15379;
      v12549 = v12505;
    }
    v12551 = v12549;
  }
  struct StateT * v15338 = v12552(v12499);
  return v15338;
}

struct StateT * v1907(struct StateT * v1908) {
  int v1909 = v1908->timer;
  int v22131 = v1909 + 1;
  v1908->timer = v22131;
  int * v1911 = v1908->regs;
  int v1912 = v1911[6];
  int * v1913 = v1908->regs;
  v1913[12] = v1912;
  struct StateT * v22129 = v1915(v1908);
  return v22129;
}

struct StateT * v2737(struct StateT * v2738) {
  int v2739 = v2738->timer;
  int v21209 = v2739 + 1;
  v2738->timer = v21209;
  int * v2741 = v2738->regs;
  int v2742 = v2741[17];
  int * v2743 = v2738->regs;
  int v2744 = v2743[6];
  int * v2745 = v2738->regs;
  int v21215 = v2742 | v2744;
  v2745[17] = v21215;
  struct StateT * v21207 = v2747(v2738);
  return v21207;
}

struct StateT * v10201(struct StateT * v10202) {
  int v10203 = v10202->timer;
  int v17798 = v10203 + 1;
  v10202->timer = v17798;
  int * v10205 = v10202->regs;
  int v10206 = v10205[8];
  int * v10207 = v10202->regs;
  int v10208 = v10207[20];
  int * v10209 = v10202->regs;
  int v17804 = v10206 | v10208;
  v10209[8] = v17804;
  struct StateT * v17796 = v10211(v10202);
  return v17796;
}

struct StateT * v5335(struct StateT * v5336) {
  int v5337 = v5336->timer;
  int v6584 = v5337 + 1;
  v5336->timer = v6584;
  int * v5339 = v5336->regs;
  int v5340 = v5339[2];
  int * v5341 = v5336->cache_keys;
  int v5342 = v5341[0];
  bool v6589 = v5342 == ((int)((unsigned int)(v5340 + 88) >> 2));
  int v5390;
  if (v6589) {
    int * v5343 = v5336->cache_vals;
    int v5344 = v5343[0];
    v5390 = v5344;
  } else {
    int * v5346 = v5336->cache_keys;
    int v5347 = v5346[1];
    bool v6594 = v5347 == ((int)((unsigned int)(v5340 + 88) >> 2));
    int v5388;
    if (v6594) {
      int * v5348 = v5336->cache_vals;
      int v5349 = v5348[1];
      int * v5350 = v5336->cache_keys;
      int * v5351 = v5336->cache_keys;
      int v5352 = v5351[0];
      v5350[1] = v5352;
      int * v5354 = v5336->cache_vals;
      int * v5355 = v5336->cache_vals;
      int v5356 = v5355[0];
      v5354[1] = v5356;
      int * v5358 = v5336->cache_keys;
      int v6603 = (int)((unsigned int)(v5340 + 88) >> 2);
      v5358[0] = v6603;
      int * v5360 = v5336->cache_vals;
      v5360[0] = v5349;
      int v5362 = v5336->timer;
      int v6606 = v5362 + 1;
      v5336->timer = v6606;
      v5388 = v5349;
    } else {
      int * v5365 = v5336->mem;
      int v6608 = (int)((unsigned int)(v5340 + 88) >> 2);
      int v5366 = v5365[v6608];
      int * v5367 = v5336->mem;
      int * v5368 = v5336->cache_keys;
      int v5369 = v5368[1];
      int * v5370 = v5336->cache_vals;
      int v5371 = v5370[1];
      v5367[v5369] = v5371;
      int * v5373 = v5336->cache_keys;
      int * v5374 = v5336->cache_keys;
      int v5375 = v5374[0];
      v5373[1] = v5375;
      int * v5377 = v5336->cache_vals;
      int * v5378 = v5336->cache_vals;
      int v5379 = v5378[0];
      v5377[1] = v5379;
      int * v5381 = v5336->cache_keys;
      v5381[0] = v6608;
      int * v5383 = v5336->cache_vals;
      v5383[0] = v5366;
      int v5385 = v5336->timer;
      int v6623 = v5385 + 100;
      v5336->timer = v6623;
      v5388 = v5366;
    }
    v5390 = v5388;
  }
  int * v5391 = v5336->regs;
  v5391[8] = v5390;
  struct StateT * v6582 = v5393(v5336);
  return v6582;
}

struct StateT * v9319(struct StateT * v9320) {
  int v9321 = v9320->timer;
  int v18812 = v9321 + 1;
  v9320->timer = v18812;
  int * v9323 = v9320->regs;
  int v9324 = v9323[19];
  int * v9325 = v9320->regs;
  int v9326 = v9325[13];
  int * v9327 = v9320->regs;
  int v18819 = v9324 + v9326;
  v9327[16] = v18819;
  struct StateT * v18810 = v9329(v9320);
  return v18810;
}

struct StateT * v5857(struct StateT * v5858) {
  int v5859 = v5858->timer;
  int v6152 = v5859 + 1;
  v5858->timer = v6152;
  int * v5861 = v5858->regs;
  int v5862 = v5861[2];
  int * v5863 = v5858->cache_keys;
  int v5864 = v5863[0];
  bool v6157 = v5864 == ((int)((unsigned int)(v5862 + 52) >> 2));
  int v5912;
  if (v6157) {
    int * v5865 = v5858->cache_vals;
    int v5866 = v5865[0];
    v5912 = v5866;
  } else {
    int * v5868 = v5858->cache_keys;
    int v5869 = v5868[1];
    bool v6162 = v5869 == ((int)((unsigned int)(v5862 + 52) >> 2));
    int v5910;
    if (v6162) {
      int * v5870 = v5858->cache_vals;
      int v5871 = v5870[1];
      int * v5872 = v5858->cache_keys;
      int * v5873 = v5858->cache_keys;
      int v5874 = v5873[0];
      v5872[1] = v5874;
      int * v5876 = v5858->cache_vals;
      int * v5877 = v5858->cache_vals;
      int v5878 = v5877[0];
      v5876[1] = v5878;
      int * v5880 = v5858->cache_keys;
      int v6171 = (int)((unsigned int)(v5862 + 52) >> 2);
      v5880[0] = v6171;
      int * v5882 = v5858->cache_vals;
      v5882[0] = v5871;
      int v5884 = v5858->timer;
      int v6174 = v5884 + 1;
      v5858->timer = v6174;
      v5910 = v5871;
    } else {
      int * v5887 = v5858->mem;
      int v6176 = (int)((unsigned int)(v5862 + 52) >> 2);
      int v5888 = v5887[v6176];
      int * v5889 = v5858->mem;
      int * v5890 = v5858->cache_keys;
      int v5891 = v5890[1];
      int * v5892 = v5858->cache_vals;
      int v5893 = v5892[1];
      v5889[v5891] = v5893;
      int * v5895 = v5858->cache_keys;
      int * v5896 = v5858->cache_keys;
      int v5897 = v5896[0];
      v5895[1] = v5897;
      int * v5899 = v5858->cache_vals;
      int * v5900 = v5858->cache_vals;
      int v5901 = v5900[0];
      v5899[1] = v5901;
      int * v5903 = v5858->cache_keys;
      v5903[0] = v6176;
      int * v5905 = v5858->cache_vals;
      v5905[0] = v5888;
      int v5907 = v5858->timer;
      int v6191 = v5907 + 100;
      v5858->timer = v6191;
      v5910 = v5888;
    }
    v5912 = v5910;
  }
  int * v5913 = v5858->regs;
  v5913[25] = v5912;
  struct StateT * v6150 = v5915(v5858);
  return v6150;
}

struct StateT * v3271(struct StateT * v3272) {
  int v3273 = v3272->timer;
  int v20597 = v3273 + 1;
  v3272->timer = v20597;
  int * v3275 = v3272->regs;
  int v3276 = v3275[15];
  int * v3277 = v3272->regs;
  int v20601 = v3276 << 13;
  v3277[15] = v20601;
  struct StateT * v20595 = v3279(v3272);
  return v20595;
}

struct StateT * v8079(struct StateT * v8080) {
  int * v8081 = v8080->saved_regs;
  int * v8082 = v8080->regs;
  int v8083 = v8082[29];
  v8081[29] = v8083;
  int v8085 = v8080->timer;
  int v20137 = v8085 + 1;
  v8080->timer = v20137;
  int * v8087 = v8080->regs;
  int v8088 = v8087[23];
  int * v8089 = v8080->regs;
  int v8090 = v8089[29];
  int * v8091 = v8080->regs;
  int v20142 = v8088 + v8090;
  v8091[29] = v20142;
  struct StateT * v20131 = v8093(v8080);
  return v20131;
}

struct StateT * v9801(struct StateT * v9802) {
  int v9803 = v9802->timer;
  int v18252 = v9803 + 1;
  v9802->timer = v18252;
  int * v9805 = v9802->regs;
  int v9806 = v9805[8];
  int * v9807 = v9802->regs;
  int v9808 = v9807[9];
  int * v9809 = v9802->regs;
  int v18258 = v9806 | v9808;
  v9809[8] = v18258;
  struct StateT * v18250 = v9811(v9802);
  return v18250;
}

struct StateT * v9539(struct StateT * v9540) {
  int v9541 = v9540->timer;
  int v18554 = v9541 + 1;
  v9540->timer = v18554;
  int * v9543 = v9540->regs;
  int v9544 = v9543[11];
  int * v9545 = v9540->regs;
  int v9546 = v9545[9];
  int * v9547 = v9540->regs;
  int v18560 = v9544 | v9546;
  v9547[11] = v18560;
  struct StateT * v18552 = v9549(v9540);
  return v18552;
}

struct StateT * v9163(struct StateT * v9164) {
  int v9165 = v9164->timer;
  int v18994 = v9165 + 1;
  v9164->timer = v18994;
  int * v9167 = v9164->regs;
  int v9168 = v9167[15];
  int * v9169 = v9164->regs;
  int v18998 = v9168 << 18;
  v9169[15] = v18998;
  struct StateT * v18992 = v9171(v9164);
  return v18992;
}

struct StateT * v9733(struct StateT * v9734) {
  int v9735 = v9734->timer;
  int v18332 = v9735 + 1;
  v9734->timer = v18332;
  int * v9737 = v9734->regs;
  int v9738 = v9737[15];
  int * v9739 = v9734->regs;
  int v18337 = (int)((unsigned int)v9738 >> 19);
  v9739[9] = v18337;
  struct StateT * v18330 = v9741(v9734);
  return v18330;
}

struct StateT * v9925(struct StateT * v9926) {
  int v9927 = v9926->timer;
  int v18111 = v9927 + 1;
  v9926->timer = v18111;
  int * v9929 = v9926->regs;
  int v9930 = v9929[15];
  int * v9931 = v9926->regs;
  int v18115 = v9930 << 18;
  v9931[15] = v18115;
  struct StateT * v18109 = v9933(v9926);
  return v18109;
}

struct StateT * v9095(struct StateT * v9096) {
  int v9097 = v9096->timer;
  int v19073 = v9097 + 1;
  v9096->timer = v19073;
  int * v9099 = v9096->regs;
  int v9100 = v9099[5];
  int * v9101 = v9096->regs;
  int v9102 = v9101[20];
  int * v9103 = v9096->regs;
  int v19080 = v9100 ^ v9102;
  v9103[18] = v19080;
  struct StateT * v19071 = v9105(v9096);
  return v19071;
}

struct StateT * v3131(struct StateT * v3132) {
  int v3133 = v3132->timer;
  int v20758 = v3133 + 1;
  v3132->timer = v20758;
  int * v3135 = v3132->regs;
  int v3136 = v3135[8];
  int * v3137 = v3132->regs;
  int v20763 = (int)((unsigned int)v3136 >> 23);
  v3137[9] = v20763;
  struct StateT * v20756 = v3139(v3132);
  return v20756;
}

struct StateT * v11279(struct StateT * v11280) {
  int v11281 = v11280->timer;
  int v16576 = v11281 + 1;
  v11280->timer = v16576;
  int * v11283 = v11280->regs;
  int v11284 = v11283[11];
  int * v11285 = v11280->regs;
  int v16581 = (int)((unsigned int)v11284 >> 19);
  v11285[9] = v16581;
  struct StateT * v16574 = v11287(v11280);
  return v16574;
}

struct StateT * v13540(struct StateT * v13541) {
  int v13542 = v13541->timer;
  int v14471 = v13542 + 1;
  v13541->timer = v14471;
  int * v13544 = v13541->regs;
  int v13545 = v13544[2];
  int * v13546 = v13541->cache_keys;
  int v13547 = v13546[0];
  bool v14476 = v13547 == ((int)((unsigned int)(v13545 + 76) >> 2));
  int v13595;
  if (v14476) {
    int * v13548 = v13541->cache_vals;
    int v13549 = v13548[0];
    v13595 = v13549;
  } else {
    int * v13551 = v13541->cache_keys;
    int v13552 = v13551[1];
    bool v14481 = v13552 == ((int)((unsigned int)(v13545 + 76) >> 2));
    int v13593;
    if (v14481) {
      int * v13553 = v13541->cache_vals;
      int v13554 = v13553[1];
      int * v13555 = v13541->cache_keys;
      int * v13556 = v13541->cache_keys;
      int v13557 = v13556[0];
      v13555[1] = v13557;
      int * v13559 = v13541->cache_vals;
      int * v13560 = v13541->cache_vals;
      int v13561 = v13560[0];
      v13559[1] = v13561;
      int * v13563 = v13541->cache_keys;
      int v14490 = (int)((unsigned int)(v13545 + 76) >> 2);
      v13563[0] = v14490;
      int * v13565 = v13541->cache_vals;
      v13565[0] = v13554;
      int v13567 = v13541->timer;
      int v14493 = v13567 + 1;
      v13541->timer = v14493;
      v13593 = v13554;
    } else {
      int * v13570 = v13541->mem;
      int v14495 = (int)((unsigned int)(v13545 + 76) >> 2);
      int v13571 = v13570[v14495];
      int * v13572 = v13541->mem;
      int * v13573 = v13541->cache_keys;
      int v13574 = v13573[1];
      int * v13575 = v13541->cache_vals;
      int v13576 = v13575[1];
      v13572[v13574] = v13576;
      int * v13578 = v13541->cache_keys;
      int * v13579 = v13541->cache_keys;
      int v13580 = v13579[0];
      v13578[1] = v13580;
      int * v13582 = v13541->cache_vals;
      int * v13583 = v13541->cache_vals;
      int v13584 = v13583[0];
      v13582[1] = v13584;
      int * v13586 = v13541->cache_keys;
      v13586[0] = v14495;
      int * v13588 = v13541->cache_vals;
      v13588[0] = v13571;
      int v13590 = v13541->timer;
      int v14510 = v13590 + 100;
      v13541->timer = v14510;
      v13593 = v13571;
    }
    v13595 = v13593;
  }
  int * v13596 = v13541->regs;
  v13596[19] = v13595;
  struct StateT * v14469 = v13598(v13541);
  return v14469;
}

struct StateT * v3305(struct StateT * v3306) {
  int v3307 = v3306->timer;
  int v20556 = v3307 + 1;
  v3306->timer = v20556;
  int * v3309 = v3306->regs;
  int v3310 = v3309[6];
  int * v3311 = v3306->regs;
  int v3312 = v3311[9];
  int * v3313 = v3306->regs;
  int v20562 = v3310 | v3312;
  v3313[6] = v20562;
  struct StateT * v20554 = v3315(v3306);
  return v20554;
}

struct StateT * v11453(struct StateT * v11454) {
  int v11455 = v11454->timer;
  int v16374 = v11455 + 1;
  v11454->timer = v16374;
  int * v11457 = v11454->regs;
  int v11458 = v11457[1];
  int * v11459 = v11454->regs;
  int v11460 = v11459[24];
  int * v11461 = v11454->regs;
  int v16381 = v11458 + v11460;
  v11461[8] = v16381;
  struct StateT * v16372 = v11463(v11454);
  return v16372;
}

struct StateT * v10649(struct StateT * v10650) {
  int v10651 = v10650->timer;
  int v17296 = v10651 + 1;
  v10650->timer = v17296;
  int * v10653 = v10650->regs;
  int v10654 = v10653[17];
  int * v10655 = v10650->regs;
  int v10656 = v10655[6];
  int * v10657 = v10650->regs;
  int v17303 = v10654 ^ v10656;
  v10657[8] = v17303;
  struct StateT * v17294 = v10659(v10650);
  return v17294;
}

struct StateT * v9407(struct StateT * v9408) {
  int v9409 = v9408->timer;
  int v18710 = v9409 + 1;
  v9408->timer = v18710;
  int * v9411 = v9408->regs;
  int v9412 = v9411[16];
  int * v9413 = v9408->regs;
  int v9414 = v9413[5];
  int * v9415 = v9408->regs;
  int v18716 = v9412 | v9414;
  v9415[16] = v18716;
  struct StateT * v18708 = v9417(v9408);
  return v18708;
}

struct StateT * v3139(struct StateT * v3140) {
  int v3141 = v3140->timer;
  int v20749 = v3141 + 1;
  v3140->timer = v20749;
  int * v3143 = v3140->regs;
  int v3144 = v3143[8];
  int * v3145 = v3140->regs;
  int v20753 = v3144 << 9;
  v3145[8] = v20753;
  struct StateT * v20747 = v3147(v3140);
  return v20747;
}

struct StateT * v2929(struct StateT * v2930) {
  int v2931 = v2930->timer;
  int v20995 = v2931 + 1;
  v2930->timer = v20995;
  int * v2933 = v2930->regs;
  int v2934 = v2933[16];
  int * v2935 = v2930->regs;
  int v20999 = v2934 << 7;
  v2935[16] = v20999;
  struct StateT * v20993 = v2937(v2930);
  return v20993;
}

struct StateT * v5567(struct StateT * v5568) {
  int v5569 = v5568->timer;
  int v6392 = v5569 + 1;
  v5568->timer = v6392;
  int * v5571 = v5568->regs;
  int v5572 = v5571[2];
  int * v5573 = v5568->cache_keys;
  int v5574 = v5573[0];
  bool v6397 = v5574 == ((int)((unsigned int)(v5572 + 72) >> 2));
  int v5622;
  if (v6397) {
    int * v5575 = v5568->cache_vals;
    int v5576 = v5575[0];
    v5622 = v5576;
  } else {
    int * v5578 = v5568->cache_keys;
    int v5579 = v5578[1];
    bool v6402 = v5579 == ((int)((unsigned int)(v5572 + 72) >> 2));
    int v5620;
    if (v6402) {
      int * v5580 = v5568->cache_vals;
      int v5581 = v5580[1];
      int * v5582 = v5568->cache_keys;
      int * v5583 = v5568->cache_keys;
      int v5584 = v5583[0];
      v5582[1] = v5584;
      int * v5586 = v5568->cache_vals;
      int * v5587 = v5568->cache_vals;
      int v5588 = v5587[0];
      v5586[1] = v5588;
      int * v5590 = v5568->cache_keys;
      int v6411 = (int)((unsigned int)(v5572 + 72) >> 2);
      v5590[0] = v6411;
      int * v5592 = v5568->cache_vals;
      v5592[0] = v5581;
      int v5594 = v5568->timer;
      int v6414 = v5594 + 1;
      v5568->timer = v6414;
      v5620 = v5581;
    } else {
      int * v5597 = v5568->mem;
      int v6416 = (int)((unsigned int)(v5572 + 72) >> 2);
      int v5598 = v5597[v6416];
      int * v5599 = v5568->mem;
      int * v5600 = v5568->cache_keys;
      int v5601 = v5600[1];
      int * v5602 = v5568->cache_vals;
      int v5603 = v5602[1];
      v5599[v5601] = v5603;
      int * v5605 = v5568->cache_keys;
      int * v5606 = v5568->cache_keys;
      int v5607 = v5606[0];
      v5605[1] = v5607;
      int * v5609 = v5568->cache_vals;
      int * v5610 = v5568->cache_vals;
      int v5611 = v5610[0];
      v5609[1] = v5611;
      int * v5613 = v5568->cache_keys;
      v5613[0] = v6416;
      int * v5615 = v5568->cache_vals;
      v5615[0] = v5598;
      int v5617 = v5568->timer;
      int v6431 = v5617 + 100;
      v5568->timer = v6431;
      v5620 = v5598;
    }
    v5622 = v5620;
  }
  int * v5623 = v5568->regs;
  v5623[20] = v5622;
  struct StateT * v6390 = v5625(v5568);
  return v6390;
}

struct StateT * v4057(struct StateT * v4058) {
  int v4059 = v4058->timer;
  int v7723 = v4059 + 1;
  v4058->timer = v7723;
  int * v4061 = v4058->regs;
  v4061[7] = 2036477952;
  struct StateT * v7721 = v4063(v4058);
  return v7721;
}

struct StateT * v1425(struct StateT * v1426) {
  int v1427 = v1426->timer;
  int v22555 = v1427 + 1;
  v1426->timer = v22555;
  int * v1429 = v1426->regs;
  v1429[14] = 2036477952;
  struct StateT * v22553 = v1431(v1426);
  return v22553;
}

struct StateT * v1637(struct StateT * v1638) {
  int v1639 = v1638->timer;
  int v22321 = v1639 + 1;
  v1638->timer = v22321;
  int * v1641 = v1638->regs;
  int v1642 = v1641[2];
  int * v1643 = v1638->regs;
  int v1644 = v1643[1];
  int * v1645 = v1638->cache_keys;
  int v1646 = v1645[0];
  bool v22328 = v1646 == ((int)((unsigned int)(v1642 + 40) >> 2));
  int v1690;
  if (v22328) {
    int * v1647 = v1638->cache_vals;
    v1647[0] = v1644;
    v1690 = v1644;
  } else {
    int * v1650 = v1638->cache_keys;
    int v1651 = v1650[1];
    bool v22332 = v1651 == ((int)((unsigned int)(v1642 + 40) >> 2));
    int v1688;
    if (v22332) {
      int * v1652 = v1638->cache_keys;
      int * v1653 = v1638->cache_keys;
      int v1654 = v1653[0];
      v1652[1] = v1654;
      int * v1656 = v1638->cache_vals;
      int * v1657 = v1638->cache_vals;
      int v1658 = v1657[0];
      v1656[1] = v1658;
      int * v1660 = v1638->cache_keys;
      int v22340 = (int)((unsigned int)(v1642 + 40) >> 2);
      v1660[0] = v22340;
      int * v1662 = v1638->cache_vals;
      v1662[0] = v1644;
      int v1664 = v1638->timer;
      int v22343 = v1664 + 1;
      v1638->timer = v22343;
      v1688 = v1644;
    } else {
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
      int v22356 = (int)((unsigned int)(v1642 + 40) >> 2);
      v1681[0] = v22356;
      int * v1683 = v1638->cache_vals;
      v1683[0] = v1644;
      int v1685 = v1638->timer;
      int v22359 = v1685 + 100;
      v1638->timer = v22359;
      v1688 = v1644;
    }
    v1690 = v1688;
  }
  struct StateT * v22319 = v1691(v1638);
  return v22319;
}

struct StateT * v10971(struct StateT * v10972) {
  int v10973 = v10972->timer;
  int v16935 = v10973 + 1;
  v10972->timer = v16935;
  int * v10975 = v10972->regs;
  int v10976 = v10975[16];
  int * v10977 = v10972->regs;
  int v16939 = v10976 << 7;
  v10977[16] = v16939;
  struct StateT * v16933 = v10979(v10972);
  return v16933;
}

struct StateT * v13146(struct StateT * v13147) {
  int v13148 = v13147->timer;
  int v14800 = v13148 + 1;
  v13147->timer = v14800;
  int * v13150 = v13147->regs;
  int v13151 = v13150[10];
  int * v13152 = v13147->regs;
  int v13153 = v13152[24];
  int * v13154 = v13147->cache_keys;
  int v13155 = v13154[0];
  bool v14807 = v13155 == ((int)((unsigned int)(v13151 + 52) >> 2));
  int v13199;
  if (v14807) {
    int * v13156 = v13147->cache_vals;
    v13156[0] = v13153;
    v13199 = v13153;
  } else {
    int * v13159 = v13147->cache_keys;
    int v13160 = v13159[1];
    bool v14812 = v13160 == ((int)((unsigned int)(v13151 + 52) >> 2));
    int v13197;
    if (v14812) {
      int * v13161 = v13147->cache_keys;
      int * v13162 = v13147->cache_keys;
      int v13163 = v13162[0];
      v13161[1] = v13163;
      int * v13165 = v13147->cache_vals;
      int * v13166 = v13147->cache_vals;
      int v13167 = v13166[0];
      v13165[1] = v13167;
      int * v13169 = v13147->cache_keys;
      int v14820 = (int)((unsigned int)(v13151 + 52) >> 2);
      v13169[0] = v14820;
      int * v13171 = v13147->cache_vals;
      v13171[0] = v13153;
      int v13173 = v13147->timer;
      int v14823 = v13173 + 1;
      v13147->timer = v14823;
      v13197 = v13153;
    } else {
      int * v13176 = v13147->mem;
      int * v13177 = v13147->cache_keys;
      int v13178 = v13177[1];
      int * v13179 = v13147->cache_vals;
      int v13180 = v13179[1];
      v13176[v13178] = v13180;
      int * v13182 = v13147->cache_keys;
      int * v13183 = v13147->cache_keys;
      int v13184 = v13183[0];
      v13182[1] = v13184;
      int * v13186 = v13147->cache_vals;
      int * v13187 = v13147->cache_vals;
      int v13188 = v13187[0];
      v13186[1] = v13188;
      int * v13190 = v13147->cache_keys;
      int v14836 = (int)((unsigned int)(v13151 + 52) >> 2);
      v13190[0] = v14836;
      int * v13192 = v13147->cache_vals;
      v13192[0] = v13153;
      int v13194 = v13147->timer;
      int v14839 = v13194 + 100;
      v13147->timer = v14839;
      v13197 = v13153;
    }
    v13199 = v13197;
  }
  struct StateT * v14798 = v13200(v13147);
  return v14798;
}

struct StateT * v9785(struct StateT * v9786) {
  int v9787 = v9786->timer;
  int v18272 = v9787 + 1;
  v9786->timer = v18272;
  int * v9789 = v9786->regs;
  int v9790 = v9789[8];
  int * v9791 = v9786->regs;
  int v18277 = (int)((unsigned int)v9790 >> 19);
  v9791[9] = v18277;
  struct StateT * v18270 = v9793(v9786);
  return v18270;
}

struct StateT * v9309(struct StateT * v9310) {
  int v9311 = v9310->timer;
  int v18824 = v9311 + 1;
  v9310->timer = v18824;
  int * v9313 = v9310->regs;
  int v9314 = v9313[20];
  int * v9315 = v9310->regs;
  int v9316 = v9315[12];
  int * v9317 = v9310->regs;
  int v18831 = v9314 + v9316;
  v9317[11] = v18831;
  struct StateT * v18822 = v9319(v9310);
  return v18822;
}

struct StateT * v9637(struct StateT * v9638) {
  int v9639 = v9638->timer;
  int v18442 = v9639 + 1;
  v9638->timer = v18442;
  int * v9641 = v9638->regs;
  int v9642 = v9641[25];
  int * v9643 = v9638->regs;
  int v9644 = v9643[15];
  int * v9645 = v9638->regs;
  int v18448 = v9642 ^ v9644;
  v9645[25] = v18448;
  struct StateT * v18440 = v9647(v9638);
  return v18440;
}

struct StateT * v10005(struct StateT * v10006) {
  int v10007 = v10006->timer;
  int v18017 = v10007 + 1;
  v10006->timer = v18017;
  int * v10009 = v10006->regs;
  int v10010 = v10009[20];
  int * v10011 = v10006->regs;
  int v10012 = v10011[15];
  int * v10013 = v10006->regs;
  int v18024 = v10010 ^ v10012;
  v10013[11] = v18024;
  struct StateT * v18015 = v10015(v10006);
  return v18015;
}

struct StateT * v11025(struct StateT * v11026) {
  int v11027 = v11026->timer;
  int v16870 = v11027 + 1;
  v11026->timer = v16870;
  int * v11029 = v11026->regs;
  int v11030 = v11029[18];
  int * v11031 = v11026->regs;
  int v11032 = v11031[11];
  int * v11033 = v11026->regs;
  int v16877 = v11030 ^ v11032;
  v11033[5] = v16877;
  struct StateT * v16868 = v11035(v11026);
  return v16868;
}

struct StateT * v2235(struct StateT * v2236) {
  int v2237 = v2236->timer;
  int v21778 = v2237 + 1;
  v2236->timer = v21778;
  int * v2239 = v2236->regs;
  int v2240 = v2239[13];
  int * v2241 = v2236->regs;
  int v2242 = v2241[11];
  int * v2243 = v2236->regs;
  int v21785 = v2240 + v2242;
  v2243[8] = v21785;
  struct StateT * v21776 = v2245(v2236);
  return v21776;
}

struct StateT * v3341(struct StateT * v3342) {
  int v3343 = v3342->timer;
  int v20515 = v3343 + 1;
  v3342->timer = v20515;
  int * v3345 = v3342->regs;
  int v3346 = v3345[14];
  int * v3347 = v3342->regs;
  int v3348 = v3347[11];
  int * v3349 = v3342->regs;
  int v20521 = v3346 ^ v3348;
  v3349[14] = v20521;
  struct StateT * v20513 = v3351(v3342);
  return v20513;
}

struct StateT * v6039(struct StateT * v6040) {
  int v6041 = v6040->timer;
  int v6044 = v6041 + 1;
  v6040->timer = v6044;
  return v6040;
}

struct StateT * v10141(struct StateT * v10142) {
  int v10143 = v10142->timer;
  int v17869 = v10143 + 1;
  v10142->timer = v17869;
  int * v10145 = v10142->regs;
  int v10146 = v10145[20];
  int * v10147 = v10142->regs;
  int v17873 = v10146 << 7;
  v10147[20] = v17873;
  struct StateT * v17867 = v10149(v10142);
  return v17867;
}

struct StateT * v12380(struct StateT * v12381) {
  int v12382 = v12381->timer;
  int v15492 = v12382 + 1;
  v12381->timer = v15492;
  int * v12384 = v12381->regs;
  int v12385 = v12384[6];
  int * v12386 = v12381->regs;
  int v15496 = v12385 + 1134;
  v12386[6] = v15496;
  struct StateT * v15490 = v12388(v12381);
  return v15490;
}

struct StateT * v2763(struct StateT * v2764) {
  int v2765 = v2764->timer;
  int v21179 = v2765 + 1;
  v2764->timer = v21179;
  int * v2767 = v2764->regs;
  int v2768 = v2767[5];
  int * v2769 = v2764->regs;
  int v2770 = v2769[6];
  int * v2771 = v2764->regs;
  int v21185 = v2768 | v2770;
  v2771[5] = v21185;
  struct StateT * v21177 = v2773(v2764);
  return v21177;
}

struct StateT * v9969(struct StateT * v9970) {
  int v9971 = v9970->timer;
  int v18060 = v9971 + 1;
  v9970->timer = v18060;
  int * v9973 = v9970->regs;
  int v9974 = v9973[8];
  int * v9975 = v9970->regs;
  int v18065 = (int)((unsigned int)v9974 >> 14);
  v9975[9] = v18065;
  struct StateT * v18058 = v9977(v9970);
  return v18058;
}

struct StateT * v10815(struct StateT * v10816) {
  int * v10817 = v10816->saved_regs;
  int * v10818 = v10816->regs;
  int v10819 = v10818[21];
  v10817[21] = v10819;
  int v10821 = v10816->timer;
  int v17109 = v10821 + 1;
  v10816->timer = v17109;
  int * v10823 = v10816->regs;
  int v10824 = v10823[21];
  int * v10825 = v10816->regs;
  int v10826 = v10825[15];
  int * v10827 = v10816->regs;
  int v17114 = v10824 ^ v10826;
  v10827[21] = v17114;
  struct StateT * v17103 = v10829(v10816);
  return v17103;
}

struct StateT * v8767(struct StateT * v8768) {
  int v8769 = v8768->timer;
  int v19453 = v8769 + 1;
  v8768->timer = v19453;
  int * v8771 = v8768->regs;
  int v8772 = v8771[1];
  int * v8773 = v8768->regs;
  int v8774 = v8773[19];
  int * v8775 = v8768->regs;
  int v19460 = v8772 + v8774;
  v8775[9] = v19460;
  struct StateT * v19451 = v8777(v8768);
  return v19451;
}

struct StateT * v11287(struct StateT * v11288) {
  int v11289 = v11288->timer;
  int v16567 = v11289 + 1;
  v11288->timer = v16567;
  int * v11291 = v11288->regs;
  int v11292 = v11291[11];
  int * v11293 = v11288->regs;
  int v16571 = v11292 << 13;
  v11293[11] = v16571;
  struct StateT * v16565 = v11295(v11288);
  return v16565;
}

struct StateT * v2729(struct StateT * v2730) {
  int v2731 = v2730->timer;
  int v21220 = v2731 + 1;
  v2730->timer = v21220;
  int * v2733 = v2730->regs;
  int v2734 = v2733[17];
  int * v2735 = v2730->regs;
  int v21224 = v2734 << 18;
  v2735[17] = v21224;
  struct StateT * v21218 = v2737(v2730);
  return v21218;
}

struct StateT * v9503(struct StateT * v9504) {
  int v9505 = v9504->timer;
  int v18596 = v9505 + 1;
  v9504->timer = v18596;
  int * v9507 = v9504->regs;
  int v9508 = v9507[17];
  int * v9509 = v9504->regs;
  int v9510 = v9509[19];
  int * v9511 = v9504->regs;
  int v18603 = v9508 + v9510;
  v9511[6] = v18603;
  struct StateT * v18594 = v9513(v9504);
  return v18594;
}

struct StateT * v10669(struct StateT * v10670) {
  int * v10671 = v10670->saved_regs;
  int * v10672 = v10670->regs;
  int v10673 = v10672[16];
  v10671[16] = v10673;
  int v10675 = v10670->timer;
  int v17273 = v10675 + 1;
  v10670->timer = v17273;
  int * v10677 = v10670->regs;
  int v10678 = v10677[23];
  int * v10679 = v10670->regs;
  int v10680 = v10679[24];
  int * v10681 = v10670->regs;
  int v17279 = v10678 + v10680;
  v10681[16] = v17279;
  struct StateT * v17267 = v10683(v10670);
  return v17267;
}

struct StateT * v10763(struct StateT * v10764) {
  int v10765 = v10764->timer;
  int v17169 = v10765 + 1;
  v10764->timer = v17169;
  int * v10767 = v10764->regs;
  int v10768 = v10767[17];
  int * v10769 = v10764->regs;
  int v17174 = (int)((unsigned int)v10768 >> 14);
  v10769[6] = v17174;
  struct StateT * v17167 = v10771(v10764);
  return v17167;
}

struct StateT * v11587(struct StateT * v11588) {
  int v11589 = v11588->timer;
  int v16220 = v11589 + 1;
  v11588->timer = v16220;
  int * v11591 = v11588->regs;
  int v11592 = v11591[19];
  int * v11593 = v11588->regs;
  int v11594 = v11593[6];
  int * v11595 = v11588->regs;
  int v16226 = v11592 ^ v11594;
  v11595[19] = v16226;
  struct StateT * v16218 = v11597(v11588);
  return v16218;
}

struct StateT * v3437(struct StateT * v3438) {
  int v3439 = v3438->timer;
  int v20404 = v3439 + 1;
  v3438->timer = v20404;
  int * v3441 = v3438->regs;
  int v3442 = v3441[11];
  int * v3443 = v3438->regs;
  int v3444 = v3443[9];
  int * v3445 = v3438->regs;
  int v20410 = v3442 | v3444;
  v3445[11] = v20410;
  struct StateT * v20402 = v3447(v3438);
  return v20402;
}

struct StateT * v1239(struct StateT * v1240) {
  int v1241 = v1240->timer;
  int v22675 = v1241 + 1;
  v1240->timer = v22675;
  int * v1243 = v1240->regs;
  int v1244 = v1243[11];
  int * v1245 = v1240->cache_keys;
  int v1246 = v1245[0];
  bool v22680 = v1246 == ((int)((unsigned int)(v1244 + 4) >> 2));
  int v1294;
  if (v22680) {
    int * v1247 = v1240->cache_vals;
    int v1248 = v1247[0];
    v1294 = v1248;
  } else {
    int * v1250 = v1240->cache_keys;
    int v1251 = v1250[1];
    bool v22685 = v1251 == ((int)((unsigned int)(v1244 + 4) >> 2));
    int v1292;
    if (v22685) {
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
      int v22694 = (int)((unsigned int)(v1244 + 4) >> 2);
      v1262[0] = v22694;
      int * v1264 = v1240->cache_vals;
      v1264[0] = v1253;
      int v1266 = v1240->timer;
      int v22697 = v1266 + 1;
      v1240->timer = v22697;
      v1292 = v1253;
    } else {
      int * v1269 = v1240->mem;
      int v22699 = (int)((unsigned int)(v1244 + 4) >> 2);
      int v1270 = v1269[v22699];
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
      v1285[0] = v22699;
      int * v1287 = v1240->cache_vals;
      v1287[0] = v1270;
      int v1289 = v1240->timer;
      int v22714 = v1289 + 100;
      v1240->timer = v22714;
      v1292 = v1270;
    }
    v1294 = v1292;
  }
  int * v1295 = v1240->regs;
  v1295[25] = v1294;
  struct StateT * v22673 = v1297(v1240);
  return v22673;
}

struct StateT * v12768(struct StateT * v12769) {
  int v12770 = v12769->timer;
  int v15115 = v12770 + 1;
  v12769->timer = v15115;
  int * v12772 = v12769->regs;
  int v12773 = v12772[10];
  int * v12774 = v12769->regs;
  int v12775 = v12774[5];
  int * v12776 = v12769->cache_keys;
  int v12777 = v12776[0];
  bool v15122 = v12777 == ((int)((unsigned int)(v12773 + 24) >> 2));
  int v12821;
  if (v15122) {
    int * v12778 = v12769->cache_vals;
    v12778[0] = v12775;
    v12821 = v12775;
  } else {
    int * v12781 = v12769->cache_keys;
    int v12782 = v12781[1];
    bool v15127 = v12782 == ((int)((unsigned int)(v12773 + 24) >> 2));
    int v12819;
    if (v15127) {
      int * v12783 = v12769->cache_keys;
      int * v12784 = v12769->cache_keys;
      int v12785 = v12784[0];
      v12783[1] = v12785;
      int * v12787 = v12769->cache_vals;
      int * v12788 = v12769->cache_vals;
      int v12789 = v12788[0];
      v12787[1] = v12789;
      int * v12791 = v12769->cache_keys;
      int v15135 = (int)((unsigned int)(v12773 + 24) >> 2);
      v12791[0] = v15135;
      int * v12793 = v12769->cache_vals;
      v12793[0] = v12775;
      int v12795 = v12769->timer;
      int v15138 = v12795 + 1;
      v12769->timer = v15138;
      v12819 = v12775;
    } else {
      int * v12798 = v12769->mem;
      int * v12799 = v12769->cache_keys;
      int v12800 = v12799[1];
      int * v12801 = v12769->cache_vals;
      int v12802 = v12801[1];
      v12798[v12800] = v12802;
      int * v12804 = v12769->cache_keys;
      int * v12805 = v12769->cache_keys;
      int v12806 = v12805[0];
      v12804[1] = v12806;
      int * v12808 = v12769->cache_vals;
      int * v12809 = v12769->cache_vals;
      int v12810 = v12809[0];
      v12808[1] = v12810;
      int * v12812 = v12769->cache_keys;
      int v15151 = (int)((unsigned int)(v12773 + 24) >> 2);
      v12812[0] = v15151;
      int * v12814 = v12769->cache_vals;
      v12814[0] = v12775;
      int v12816 = v12769->timer;
      int v15154 = v12816 + 100;
      v12769->timer = v15154;
      v12819 = v12775;
    }
    v12821 = v12819;
  }
  struct StateT * v15113 = v12822(v12769);
  return v15113;
}

struct StateT * v3695(struct StateT * v3696) {
  int v3697 = v3696->timer;
  int v8045 = v3697 + 1;
  v3696->timer = v8045;
  int * v3699 = v3696->regs;
  v3699[15] = 1634762752;
  struct StateT * v8043 = v3701(v3696);
  return v8043;
}

struct StateT * v949(struct StateT * v950) {
  int v951 = v950->timer;
  int v22915 = v951 + 1;
  v950->timer = v22915;
  int * v953 = v950->regs;
  int v954 = v953[12];
  int * v955 = v950->cache_keys;
  int v956 = v955[0];
  bool v22920 = v956 == ((int)((unsigned int)(v954 + 16) >> 2));
  int v1004;
  if (v22920) {
    int * v957 = v950->cache_vals;
    int v958 = v957[0];
    v1004 = v958;
  } else {
    int * v960 = v950->cache_keys;
    int v961 = v960[1];
    bool v22925 = v961 == ((int)((unsigned int)(v954 + 16) >> 2));
    int v1002;
    if (v22925) {
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
      int v22934 = (int)((unsigned int)(v954 + 16) >> 2);
      v972[0] = v22934;
      int * v974 = v950->cache_vals;
      v974[0] = v963;
      int v976 = v950->timer;
      int v22937 = v976 + 1;
      v950->timer = v22937;
      v1002 = v963;
    } else {
      int * v979 = v950->mem;
      int v22939 = (int)((unsigned int)(v954 + 16) >> 2);
      int v980 = v979[v22939];
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
      v995[0] = v22939;
      int * v997 = v950->cache_vals;
      v997[0] = v980;
      int v999 = v950->timer;
      int v22954 = v999 + 100;
      v950->timer = v22954;
      v1002 = v980;
    }
    v1004 = v1002;
  }
  int * v1005 = v950->regs;
  v1005[17] = v1004;
  struct StateT * v22913 = v1007(v950);
  return v22913;
}

struct StateT * v2703(struct StateT * v2704) {
  int v2705 = v2704->timer;
  int v21250 = v2705 + 1;
  v2704->timer = v21250;
  int * v2707 = v2704->regs;
  int v2708 = v2707[16];
  int * v2709 = v2704->regs;
  int v21254 = v2708 << 18;
  v2709[16] = v21254;
  struct StateT * v21248 = v2711(v2704);
  return v21248;
}

struct StateT * v9433(struct StateT * v9434) {
  int v9435 = v9434->timer;
  int v18679 = v9435 + 1;
  v9434->timer = v18679;
  int * v9437 = v9434->regs;
  int v9438 = v9437[17];
  int * v9439 = v9434->regs;
  int v9440 = v9439[5];
  int * v9441 = v9434->regs;
  int v18686 = v9438 | v9440;
  v9441[6] = v18686;
  struct StateT * v18677 = v9443(v9434);
  return v18677;
}

struct StateT * v9871(struct StateT * v9872) {
  int v9873 = v9872->timer;
  int v18172 = v9873 + 1;
  v9872->timer = v18172;
  int * v9875 = v9872->regs;
  int v9876 = v9875[13];
  int * v9877 = v9872->regs;
  int v9878 = v9877[26];
  int * v9879 = v9872->regs;
  int v18179 = v9876 + v9878;
  v9879[6] = v18179;
  struct StateT * v18170 = v9881(v9872);
  return v18170;
}

struct StateT * v9483(struct StateT * v9484) {
  int v9485 = v9484->timer;
  int v18620 = v9485 + 1;
  v9484->timer = v18620;
  int * v9487 = v9484->regs;
  int v9488 = v9487[23];
  int * v9489 = v9484->regs;
  int v9490 = v9489[21];
  int * v9491 = v9484->regs;
  int v18627 = v9488 + v9490;
  v9491[11] = v18627;
  struct StateT * v18618 = v9493(v9484);
  return v18618;
}

struct StateT * v2937(struct StateT * v2938) {
  int v2939 = v2938->timer;
  int v20984 = v2939 + 1;
  v2938->timer = v20984;
  int * v2941 = v2938->regs;
  int v2942 = v2941[16];
  int * v2943 = v2938->regs;
  int v2944 = v2943[5];
  int * v2945 = v2938->regs;
  int v20990 = v2942 | v2944;
  v2945[16] = v20990;
  struct StateT * v20982 = v2947(v2938);
  return v20982;
}

struct StateT * v9647(struct StateT * v9648) {
  int v9649 = v9648->timer;
  int v18431 = v9649 + 1;
  v9648->timer = v18431;
  int * v9651 = v9648->regs;
  int v9652 = v9651[26];
  int * v9653 = v9648->regs;
  int v9654 = v9653[6];
  int * v9655 = v9648->regs;
  int v18437 = v9652 ^ v9654;
  v9655[26] = v18437;
  struct StateT * v18429 = v9657(v9648);
  return v18429;
}

struct StateT * v9171(struct StateT * v9172) {
  int v9173 = v9172->timer;
  int v18983 = v9173 + 1;
  v9172->timer = v18983;
  int * v9175 = v9172->regs;
  int v9176 = v9175[15];
  int * v9177 = v9172->regs;
  int v9178 = v9177[6];
  int * v9179 = v9172->regs;
  int v18989 = v9176 | v9178;
  v9179[15] = v18989;
  struct StateT * v18981 = v9181(v9172);
  return v18981;
}

struct StateT * v12372(struct StateT * v12373) {
  int v12374 = v12373->timer;
  int v15501 = v12374 + 1;
  v12373->timer = v15501;
  int * v12376 = v12373->regs;
  int v12377 = v12376[15];
  int * v12378 = v12373->regs;
  int v15505 = v12377 + -1947;
  v12378[15] = v15505;
  struct StateT * v15499 = v12380(v12373);
  return v15499;
}

struct StateT * v8419(struct StateT * v8420) {
  int * v8421 = v8420->saved_regs;
  int * v8422 = v8420->regs;
  int v8423 = v8422[26];
  v8421[26] = v8423;
  int v8425 = v8420->timer;
  int v19836 = v8425 + 1;
  v8420->timer = v19836;
  int * v8427 = v8420->regs;
  int v8428 = v8427[26];
  int * v8429 = v8420->regs;
  int v8430 = v8429[7];
  int * v8431 = v8420->regs;
  int v19841 = v8428 + v8430;
  v8431[26] = v19841;
  struct StateT * v19830 = v8433(v8420);
  return v19830;
}

struct StateT * v11313(struct StateT * v11314) {
  int v11315 = v11314->timer;
  int v16537 = v11315 + 1;
  v11314->timer = v16537;
  int * v11317 = v11314->regs;
  int v11318 = v11317[15];
  int * v11319 = v11314->regs;
  int v16541 = v11318 << 13;
  v11319[15] = v16541;
  struct StateT * v16535 = v11321(v11314);
  return v16535;
}

struct StateT * v2903(struct StateT * v2904) {
  int v2905 = v2904->timer;
  int v21025 = v2905 + 1;
  v2904->timer = v21025;
  int * v2907 = v2904->regs;
  int v2908 = v2907[11];
  int * v2909 = v2904->regs;
  int v21029 = v2908 << 7;
  v2909[11] = v21029;
  struct StateT * v21023 = v2911(v2904);
  return v21023;
}

struct StateT * v9215(struct StateT * v9216) {
  int v9217 = v9216->timer;
  int v18934 = v9217 + 1;
  v9216->timer = v18934;
  int * v9219 = v9216->regs;
  int v9220 = v9219[17];
  int * v9221 = v9216->regs;
  int v18938 = v9220 << 18;
  v9221[17] = v18938;
  struct StateT * v18932 = v9223(v9216);
  return v18932;
}

struct StateT * v1123(struct StateT * v1124) {
  int v1125 = v1124->timer;
  int v22771 = v1125 + 1;
  v1124->timer = v22771;
  int * v1127 = v1124->regs;
  int v1128 = v1127[12];
  int * v1129 = v1124->cache_keys;
  int v1130 = v1129[0];
  bool v22776 = v1130 == ((int)((unsigned int)(v1128 + 28) >> 2));
  int v1178;
  if (v22776) {
    int * v1131 = v1124->cache_vals;
    int v1132 = v1131[0];
    v1178 = v1132;
  } else {
    int * v1134 = v1124->cache_keys;
    int v1135 = v1134[1];
    bool v22781 = v1135 == ((int)((unsigned int)(v1128 + 28) >> 2));
    int v1176;
    if (v22781) {
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
      int v22790 = (int)((unsigned int)(v1128 + 28) >> 2);
      v1146[0] = v22790;
      int * v1148 = v1124->cache_vals;
      v1148[0] = v1137;
      int v1150 = v1124->timer;
      int v22793 = v1150 + 1;
      v1124->timer = v22793;
      v1176 = v1137;
    } else {
      int * v1153 = v1124->mem;
      int v22795 = (int)((unsigned int)(v1128 + 28) >> 2);
      int v1154 = v1153[v22795];
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
      v1169[0] = v22795;
      int * v1171 = v1124->cache_vals;
      v1171[0] = v1154;
      int v1173 = v1124->timer;
      int v22810 = v1173 + 100;
      v1124->timer = v22810;
      v1176 = v1154;
    }
    v1178 = v1176;
  }
  int * v1179 = v1124->regs;
  v1179[1] = v1178;
  struct StateT * v22769 = v1181(v1124);
  return v22769;
}

struct StateT * v11065(struct StateT * v11066) {
  int v11067 = v11066->timer;
  int v16822 = v11067 + 1;
  v11066->timer = v16822;
  int * v11069 = v11066->regs;
  int v11070 = v11069[5];
  int * v11071 = v11066->regs;
  int v11072 = v11071[20];
  int * v11073 = v11066->regs;
  int v16829 = v11070 + v11072;
  v11073[15] = v16829;
  struct StateT * v16820 = v11075(v11066);
  return v16820;
}

struct StateT * v1419(struct StateT * v1420) {
  int v1421 = v1420->timer;
  int v22563 = v1421 + 1;
  v1420->timer = v22563;
  int * v1423 = v1420->regs;
  v1423[13] = 857759744;
  struct StateT * v22561 = v1425(v1420);
  return v22561;
}

struct StateT * v11147(struct StateT * v11148) {
  int v11149 = v11148->timer;
  int v16728 = v11149 + 1;
  v11148->timer = v16728;
  int * v11151 = v11148->regs;
  int v11152 = v11151[6];
  int * v11153 = v11148->regs;
  int v16733 = (int)((unsigned int)v11152 >> 23);
  v11153[9] = v16733;
  struct StateT * v16726 = v11155(v11148);
  return v16726;
}

struct StateT * v10015(struct StateT * v10016) {
  int v10017 = v10016->timer;
  int v18006 = v10017 + 1;
  v10016->timer = v18006;
  int * v10019 = v10016->regs;
  int v10020 = v10019[19];
  int * v10021 = v10016->regs;
  int v10022 = v10021[6];
  int * v10023 = v10016->regs;
  int v18012 = v10020 ^ v10022;
  v10023[19] = v18012;
  struct StateT * v18004 = v10025(v10016);
  return v18004;
}

struct StateT * v10115(struct StateT * v10116) {
  int v10117 = v10116->timer;
  int v17899 = v10117 + 1;
  v10116->timer = v17899;
  int * v10119 = v10116->regs;
  int v10120 = v10119[15];
  int * v10121 = v10116->regs;
  int v17903 = v10120 << 7;
  v10121[15] = v17903;
  struct StateT * v17897 = v10123(v10116);
  return v17897;
}

struct StateT * v2747(struct StateT * v2748) {
  int v2749 = v2748->timer;
  int v21199 = v2749 + 1;
  v2748->timer = v21199;
  int * v2751 = v2748->regs;
  int v2752 = v2751[5];
  int * v2753 = v2748->regs;
  int v21204 = (int)((unsigned int)v2752 >> 14);
  v2753[6] = v21204;
  struct StateT * v21197 = v2755(v2748);
  return v21197;
}

struct StateT * v3297(struct StateT * v3298) {
  int v3299 = v3298->timer;
  int v20567 = v3299 + 1;
  v3298->timer = v20567;
  int * v3301 = v3298->regs;
  int v3302 = v3301[6];
  int * v3303 = v3298->regs;
  int v20571 = v3302 << 13;
  v3303[6] = v20571;
  struct StateT * v20565 = v3305(v3298);
  return v20565;
}

struct StateT * v3351(struct StateT * v3352) {
  int v3353 = v3352->timer;
  int v20504 = v3353 + 1;
  v3352->timer = v20504;
  int * v3355 = v3352->regs;
  int v3356 = v3355[12];
  int * v3357 = v3352->regs;
  int v3358 = v3357[15];
  int * v3359 = v3352->regs;
  int v20510 = v3356 ^ v3358;
  v3359[12] = v20510;
  struct StateT * v20502 = v3361(v3352);
  return v20502;
}

struct StateT * v10323(struct StateT * v10324) {
  int v10325 = v10324->timer;
  int v17664 = v10325 + 1;
  v10324->timer = v17664;
  int * v10327 = v10324->regs;
  int v10328 = v10327[15];
  int * v10329 = v10324->regs;
  int v10330 = v10329[20];
  int * v10331 = v10324->regs;
  int v17670 = v10328 | v10330;
  v10331[15] = v17670;
  struct StateT * v17662 = v10333(v10324);
  return v17662;
}

struct StateT * v717(struct StateT * v718) {
  int v719 = v718->timer;
  int v23107 = v719 + 1;
  v718->timer = v23107;
  int * v721 = v718->regs;
  int v722 = v721[12];
  int * v723 = v718->cache_keys;
  int v724 = v723[0];
  bool v23112 = v724 == ((int)((unsigned int)v722 >> 2));
  int v772;
  if (v23112) {
    int * v725 = v718->cache_vals;
    int v726 = v725[0];
    v772 = v726;
  } else {
    int * v728 = v718->cache_keys;
    int v729 = v728[1];
    bool v23117 = v729 == ((int)((unsigned int)v722 >> 2));
    int v770;
    if (v23117) {
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
      int v23126 = (int)((unsigned int)v722 >> 2);
      v740[0] = v23126;
      int * v742 = v718->cache_vals;
      v742[0] = v731;
      int v744 = v718->timer;
      int v23129 = v744 + 1;
      v718->timer = v23129;
      v770 = v731;
    } else {
      int * v747 = v718->mem;
      int v23131 = (int)((unsigned int)v722 >> 2);
      int v748 = v747[v23131];
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
      v763[0] = v23131;
      int * v765 = v718->cache_vals;
      v765[0] = v748;
      int v767 = v718->timer;
      int v23146 = v767 + 100;
      v718->timer = v23146;
      v770 = v748;
    }
    v772 = v770;
  }
  int * v773 = v718->regs;
  v773[29] = v772;
  struct StateT * v23105 = v775(v718);
  return v23105;
}

struct StateT * v10075(struct StateT * v10076) {
  int * v10077 = v10076->saved_regs;
  int * v10078 = v10076->regs;
  int v10079 = v10078[18];
  v10077[18] = v10079;
  int v10081 = v10076->timer;
  int v17940 = v10081 + 1;
  v10076->timer = v17940;
  int * v10083 = v10076->regs;
  int v10084 = v10083[19];
  int * v10085 = v10076->regs;
  int v10086 = v10085[5];
  int * v10087 = v10076->regs;
  int v17946 = v10084 + v10086;
  v10087[18] = v17946;
  struct StateT * v17934 = v10089(v10076);
  return v17934;
}

struct StateT * v2773(struct StateT * v2774) {
  int * v2775 = v2774->saved_regs;
  int * v2776 = v2774->regs;
  int v2777 = v2776[21];
  v2775[21] = v2777;
  int v2779 = v2774->timer;
  int v21169 = v2779 + 1;
  v2774->timer = v21169;
  int * v2781 = v2774->regs;
  int v2782 = v2781[21];
  int * v2783 = v2774->regs;
  int v2784 = v2783[15];
  int * v2785 = v2774->regs;
  int v21174 = v2782 ^ v2784;
  v2785[21] = v21174;
  struct StateT * v21163 = v2787(v2774);
  return v21163;
}

struct StateT * v5973(struct StateT * v5974) {
  int v5975 = v5974->timer;
  int v6056 = v5975 + 1;
  v5974->timer = v6056;
  int * v5977 = v5974->regs;
  int v5978 = v5977[2];
  int * v5979 = v5974->cache_keys;
  int v5980 = v5979[0];
  bool v6061 = v5980 == ((int)((unsigned int)(v5978 + 44) >> 2));
  int v6028;
  if (v6061) {
    int * v5981 = v5974->cache_vals;
    int v5982 = v5981[0];
    v6028 = v5982;
  } else {
    int * v5984 = v5974->cache_keys;
    int v5985 = v5984[1];
    bool v6066 = v5985 == ((int)((unsigned int)(v5978 + 44) >> 2));
    int v6026;
    if (v6066) {
      int * v5986 = v5974->cache_vals;
      int v5987 = v5986[1];
      int * v5988 = v5974->cache_keys;
      int * v5989 = v5974->cache_keys;
      int v5990 = v5989[0];
      v5988[1] = v5990;
      int * v5992 = v5974->cache_vals;
      int * v5993 = v5974->cache_vals;
      int v5994 = v5993[0];
      v5992[1] = v5994;
      int * v5996 = v5974->cache_keys;
      int v6075 = (int)((unsigned int)(v5978 + 44) >> 2);
      v5996[0] = v6075;
      int * v5998 = v5974->cache_vals;
      v5998[0] = v5987;
      int v6000 = v5974->timer;
      int v6078 = v6000 + 1;
      v5974->timer = v6078;
      v6026 = v5987;
    } else {
      int * v6003 = v5974->mem;
      int v6080 = (int)((unsigned int)(v5978 + 44) >> 2);
      int v6004 = v6003[v6080];
      int * v6005 = v5974->mem;
      int * v6006 = v5974->cache_keys;
      int v6007 = v6006[1];
      int * v6008 = v5974->cache_vals;
      int v6009 = v6008[1];
      v6005[v6007] = v6009;
      int * v6011 = v5974->cache_keys;
      int * v6012 = v5974->cache_keys;
      int v6013 = v6012[0];
      v6011[1] = v6013;
      int * v6015 = v5974->cache_vals;
      int * v6016 = v5974->cache_vals;
      int v6017 = v6016[0];
      v6015[1] = v6017;
      int * v6019 = v5974->cache_keys;
      v6019[0] = v6080;
      int * v6021 = v5974->cache_vals;
      v6021[0] = v6004;
      int v6023 = v5974->timer;
      int v6095 = v6023 + 100;
      v5974->timer = v6095;
      v6026 = v6004;
    }
    v6028 = v6026;
  }
  int * v6029 = v5974->regs;
  v6029[27] = v6028;
  struct StateT * v6054 = v6031(v5974);
  return v6054;
}

struct StateT * v775(struct StateT * v776) {
  int v777 = v776->timer;
  int v23059 = v777 + 1;
  v776->timer = v23059;
  int * v779 = v776->regs;
  int v780 = v779[12];
  int * v781 = v776->cache_keys;
  int v782 = v781[0];
  bool v23064 = v782 == ((int)((unsigned int)(v780 + 4) >> 2));
  int v830;
  if (v23064) {
    int * v783 = v776->cache_vals;
    int v784 = v783[0];
    v830 = v784;
  } else {
    int * v786 = v776->cache_keys;
    int v787 = v786[1];
    bool v23069 = v787 == ((int)((unsigned int)(v780 + 4) >> 2));
    int v828;
    if (v23069) {
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
      int v23078 = (int)((unsigned int)(v780 + 4) >> 2);
      v798[0] = v23078;
      int * v800 = v776->cache_vals;
      v800[0] = v789;
      int v802 = v776->timer;
      int v23081 = v802 + 1;
      v776->timer = v23081;
      v828 = v789;
    } else {
      int * v805 = v776->mem;
      int v23083 = (int)((unsigned int)(v780 + 4) >> 2);
      int v806 = v805[v23083];
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
      v821[0] = v23083;
      int * v823 = v776->cache_vals;
      v823[0] = v806;
      int v825 = v776->timer;
      int v23098 = v825 + 100;
      v776->timer = v23098;
      v828 = v806;
    }
    v830 = v828;
  }
  int * v831 = v776->regs;
  v831[28] = v830;
  struct StateT * v23057 = v833(v776);
  return v23057;
}

struct StateT * v10287(struct StateT * v10288) {
  int v10289 = v10288->timer;
  int v17706 = v10289 + 1;
  v10288->timer = v17706;
  int * v10291 = v10288->regs;
  int v10292 = v10291[1];
  int * v10293 = v10288->regs;
  int v10294 = v10293[19];
  int * v10295 = v10288->regs;
  int v17713 = v10292 + v10294;
  v10295[9] = v17713;
  struct StateT * v17704 = v10297(v10288);
  return v17704;
}

struct StateT * v9355(struct StateT * v9356) {
  int v9357 = v9356->timer;
  int v18770 = v9357 + 1;
  v9356->timer = v18770;
  int * v9359 = v9356->regs;
  int v9360 = v9359[15];
  int * v9361 = v9356->regs;
  int v9362 = v9361[5];
  int * v9363 = v9356->regs;
  int v18776 = v9360 | v9362;
  v9363[15] = v18776;
  struct StateT * v18768 = v9365(v9356);
  return v18768;
}

struct StateT * v9881(struct StateT * v9882) {
  int v9883 = v9882->timer;
  int v18160 = v9883 + 1;
  v9882->timer = v18160;
  int * v9885 = v9882->regs;
  int v9886 = v9885[1];
  int * v9887 = v9882->regs;
  int v9888 = v9887[24];
  int * v9889 = v9882->regs;
  int v18167 = v9886 + v9888;
  v9889[8] = v18167;
  struct StateT * v18158 = v9891(v9882);
  return v18158;
}

struct StateT * v2859(struct StateT * v2860) {
  int v2861 = v2860->timer;
  int v21074 = v2861 + 1;
  v2860->timer = v21074;
  int * v2863 = v2860->regs;
  int v2864 = v2863[22];
  int * v2865 = v2860->regs;
  int v2866 = v2865[1];
  int * v2867 = v2860->regs;
  int v21081 = v2864 + v2866;
  v2867[17] = v21081;
  struct StateT * v21072 = v2869(v2860);
  return v21072;
}

struct StateT * v8505(struct StateT * v8506) {
  int v8507 = v8506->timer;
  int v19762 = v8507 + 1;
  v8506->timer = v19762;
  int * v8509 = v8506->regs;
  v8509[7] = 2036477952;
  struct StateT * v19760 = v8511(v8506);
  return v19760;
}

struct StateT * v3245(struct StateT * v3246) {
  int v3247 = v3246->timer;
  int v20627 = v3247 + 1;
  v3246->timer = v20627;
  int * v3249 = v3246->regs;
  int v3250 = v3249[11];
  int * v3251 = v3246->regs;
  int v20631 = v3250 << 13;
  v3251[11] = v20631;
  struct StateT * v20625 = v3253(v3246);
  return v20625;
}

struct StateT * v8979(struct StateT * v8980) {
  int v8981 = v8980->timer;
  int v19210 = v8981 + 1;
  v8980->timer = v19210;
  int * v8983 = v8980->regs;
  int v8984 = v8983[15];
  int * v8985 = v8980->regs;
  int v19214 = v8984 << 13;
  v8985[15] = v19214;
  struct StateT * v19208 = v8987(v8980);
  return v19208;
}

struct StateT * v9851(struct StateT * v9852) {
  int v9853 = v9852->timer;
  int v18196 = v9853 + 1;
  v9852->timer = v18196;
  int * v9855 = v9852->regs;
  int v9856 = v9855[14];
  int * v9857 = v9852->regs;
  int v9858 = v9857[27];
  int * v9859 = v9852->regs;
  int v18203 = v9856 + v9858;
  v9859[11] = v18203;
  struct StateT * v18194 = v9861(v9852);
  return v18194;
}

struct StateT * v8681(struct StateT * v8682) {
  int v8683 = v8682->timer;
  int v19553 = v8683 + 1;
  v8682->timer = v19553;
  int * v8685 = v8682->regs;
  int v8686 = v8685[8];
  int * v8687 = v8682->regs;
  int v19558 = (int)((unsigned int)v8686 >> 25);
  v8687[20] = v19558;
  struct StateT * v19551 = v8689(v8682);
  return v19551;
}

struct StateT * v9039(struct StateT * v9040) {
  int v9041 = v9040->timer;
  int v19139 = v9041 + 1;
  v9040->timer = v19139;
  int * v9043 = v9040->regs;
  int v9044 = v9043[9];
  int * v9045 = v9040->regs;
  int v9046 = v9045[20];
  int * v9047 = v9040->regs;
  int v19145 = v9044 | v9046;
  v9047[20] = v19145;
  struct StateT * v19137 = v9049(v9040);
  return v19137;
}

struct StateT * v5683(struct StateT * v5684) {
  int v5685 = v5684->timer;
  int v6296 = v5685 + 1;
  v5684->timer = v6296;
  int * v5687 = v5684->regs;
  int v5688 = v5687[2];
  int * v5689 = v5684->cache_keys;
  int v5690 = v5689[0];
  bool v6301 = v5690 == ((int)((unsigned int)(v5688 + 64) >> 2));
  int v5738;
  if (v6301) {
    int * v5691 = v5684->cache_vals;
    int v5692 = v5691[0];
    v5738 = v5692;
  } else {
    int * v5694 = v5684->cache_keys;
    int v5695 = v5694[1];
    bool v6306 = v5695 == ((int)((unsigned int)(v5688 + 64) >> 2));
    int v5736;
    if (v6306) {
      int * v5696 = v5684->cache_vals;
      int v5697 = v5696[1];
      int * v5698 = v5684->cache_keys;
      int * v5699 = v5684->cache_keys;
      int v5700 = v5699[0];
      v5698[1] = v5700;
      int * v5702 = v5684->cache_vals;
      int * v5703 = v5684->cache_vals;
      int v5704 = v5703[0];
      v5702[1] = v5704;
      int * v5706 = v5684->cache_keys;
      int v6315 = (int)((unsigned int)(v5688 + 64) >> 2);
      v5706[0] = v6315;
      int * v5708 = v5684->cache_vals;
      v5708[0] = v5697;
      int v5710 = v5684->timer;
      int v6318 = v5710 + 1;
      v5684->timer = v6318;
      v5736 = v5697;
    } else {
      int * v5713 = v5684->mem;
      int v6320 = (int)((unsigned int)(v5688 + 64) >> 2);
      int v5714 = v5713[v6320];
      int * v5715 = v5684->mem;
      int * v5716 = v5684->cache_keys;
      int v5717 = v5716[1];
      int * v5718 = v5684->cache_vals;
      int v5719 = v5718[1];
      v5715[v5717] = v5719;
      int * v5721 = v5684->cache_keys;
      int * v5722 = v5684->cache_keys;
      int v5723 = v5722[0];
      v5721[1] = v5723;
      int * v5725 = v5684->cache_vals;
      int * v5726 = v5684->cache_vals;
      int v5727 = v5726[0];
      v5725[1] = v5727;
      int * v5729 = v5684->cache_keys;
      v5729[0] = v6320;
      int * v5731 = v5684->cache_vals;
      v5731[0] = v5714;
      int v5733 = v5684->timer;
      int v6335 = v5733 + 100;
      v5684->timer = v6335;
      v5736 = v5714;
    }
    v5738 = v5736;
  }
  int * v5739 = v5684->regs;
  v5739[22] = v5738;
  struct StateT * v6294 = v5741(v5684);
  return v6294;
}

struct StateT * v12388(struct StateT * v12389) {
  int v12390 = v12389->timer;
  int v15483 = v12390 + 1;
  v12389->timer = v15483;
  int * v12392 = v12389->regs;
  int v12393 = v12392[7];
  int * v12394 = v12389->regs;
  int v15487 = v12393 + -718;
  v12394[7] = v15487;
  struct StateT * v15481 = v12396(v12389);
  return v15481;
}

struct StateT * v9917(struct StateT * v9918) {
  int v9919 = v9918->timer;
  int v18120 = v9919 + 1;
  v9918->timer = v18120;
  int * v9921 = v9918->regs;
  int v9922 = v9921[15];
  int * v9923 = v9918->regs;
  int v18125 = (int)((unsigned int)v9922 >> 14);
  v9923[9] = v18125;
  struct StateT * v18118 = v9925(v9918);
  return v18118;
}

struct StateT * v11103(struct StateT * v11104) {
  int v11105 = v11104->timer;
  int v16779 = v11105 + 1;
  v11104->timer = v16779;
  int * v11107 = v11104->regs;
  int v11108 = v11107[11];
  int * v11109 = v11104->regs;
  int v16783 = v11108 << 9;
  v11109[11] = v16783;
  struct StateT * v16777 = v11111(v11104);
  return v16777;
}

struct StateT * v2383(struct StateT * v2384) {
  int * v2385 = v2384->saved_regs;
  int * v2386 = v2384->regs;
  int v2387 = v2386[24];
  v2385[24] = v2387;
  int v2389 = v2384->timer;
  int v21610 = v2389 + 1;
  v2384->timer = v21610;
  int * v2391 = v2384->regs;
  int v2392 = v2391[24];
  int * v2393 = v2384->regs;
  int v2394 = v2393[8];
  int * v2395 = v2384->regs;
  int v21615 = v2392 ^ v2394;
  v2395[24] = v21615;
  struct StateT * v21604 = v2397(v2384);
  return v21604;
}

struct StateT * v11229(struct StateT * v11230) {
  int v11231 = v11230->timer;
  int v16634 = v11231 + 1;
  v11230->timer = v16634;
  int * v11233 = v11230->regs;
  int v11234 = v11233[24];
  int * v11235 = v11230->regs;
  int v11236 = v11235[8];
  int * v11237 = v11230->regs;
  int v16640 = v11234 ^ v11236;
  v11237[24] = v16640;
  struct StateT * v16632 = v11239(v11230);
  return v16632;
}

struct StateT * v2307(struct StateT * v2308) {
  int v2309 = v2308->timer;
  int v21694 = v2309 + 1;
  v2308->timer = v21694;
  int * v2311 = v2308->regs;
  int v2312 = v2311[8];
  int * v2313 = v2308->regs;
  int v2314 = v2313[20];
  int * v2315 = v2308->regs;
  int v21700 = v2312 | v2314;
  v2315[8] = v21700;
  struct StateT * v21692 = v2317(v2308);
  return v21692;
}

struct StateT * v9299(struct StateT * v9300) {
  int v9301 = v9300->timer;
  int v18836 = v9301 + 1;
  v9300->timer = v18836;
  int * v9303 = v9300->regs;
  int v9304 = v9303[21];
  int * v9305 = v9300->regs;
  int v9306 = v9305[14];
  int * v9307 = v9300->regs;
  int v18843 = v9304 + v9306;
  v9307[15] = v18843;
  struct StateT * v18834 = v9309(v9300);
  return v18834;
}

struct StateT * v2445(struct StateT * v2446) {
  int v2447 = v2446->timer;
  int v21542 = v2447 + 1;
  v2446->timer = v21542;
  int * v2449 = v2446->regs;
  int v2450 = v2449[27];
  int * v2451 = v2446->regs;
  int v2452 = v2451[1];
  int * v2453 = v2446->regs;
  int v21549 = v2450 + v2452;
  v2453[9] = v21549;
  struct StateT * v21540 = v2455(v2446);
  return v21540;
}

struct StateT * v4393(struct StateT * v4394) {
  int v4395 = v4394->timer;
  int v7410 = v4395 + 1;
  v4394->timer = v7410;
  int * v4397 = v4394->regs;
  int v4398 = v4397[19];
  int * v4399 = v4394->regs;
  int v4400 = v4399[7];
  int * v4401 = v4394->regs;
  int v7416 = v4398 + v4400;
  v4401[7] = v7416;
  struct StateT * v7408 = v4403(v4394);
  return v7408;
}

struct StateT * v3331(struct StateT * v3332) {
  int v3333 = v3332->timer;
  int v20526 = v3333 + 1;
  v3332->timer = v20526;
  int * v3335 = v3332->regs;
  int v3336 = v3335[8];
  int * v3337 = v3332->regs;
  int v3338 = v3337[9];
  int * v3339 = v3332->regs;
  int v20532 = v3336 | v3338;
  v3339[8] = v20532;
  struct StateT * v20524 = v3341(v3332);
  return v20524;
}

struct StateT * v11055(struct StateT * v11056) {
  int v11057 = v11056->timer;
  int v16834 = v11057 + 1;
  v11056->timer = v16834;
  int * v11059 = v11056->regs;
  int v11060 = v11059[23];
  int * v11061 = v11056->regs;
  int v11062 = v11061[21];
  int * v11063 = v11056->regs;
  int v16841 = v11060 + v11062;
  v11063[11] = v16841;
  struct StateT * v16832 = v11065(v11056);
  return v16832;
}

struct StateT * v9583(struct StateT * v9584) {
  int v9585 = v9584->timer;
  int v18505 = v9585 + 1;
  v9584->timer = v18505;
  int * v9587 = v9584->regs;
  int v9588 = v9587[6];
  int * v9589 = v9584->regs;
  int v18509 = v9588 << 9;
  v9589[6] = v18509;
  struct StateT * v18503 = v9591(v9584);
  return v18503;
}

struct StateT * v2273(struct StateT * v2274) {
  int v2275 = v2274->timer;
  int v21735 = v2275 + 1;
  v2274->timer = v21735;
  int * v2277 = v2274->regs;
  int v2278 = v2277[15];
  int * v2279 = v2274->regs;
  int v21739 = v2278 << 9;
  v2279[15] = v21739;
  struct StateT * v21733 = v2281(v2274);
  return v21733;
}

struct StateT * v2411(struct StateT * v2412) {
  int * v2413 = v2412->saved_regs;
  int * v2414 = v2412->regs;
  int v2415 = v2414[25];
  v2413[25] = v2415;
  int v2417 = v2412->timer;
  int v21582 = v2417 + 1;
  v2412->timer = v21582;
  int * v2419 = v2412->regs;
  int v2420 = v2419[25];
  int * v2421 = v2412->regs;
  int v2422 = v2421[18];
  int * v2423 = v2412->regs;
  int v21587 = v2420 ^ v2422;
  v2423[25] = v21587;
  struct StateT * v21576 = v2425(v2412);
  return v21576;
}

struct StateT * v3263(struct StateT * v3264) {
  int v3265 = v3264->timer;
  int v20606 = v3265 + 1;
  v3264->timer = v20606;
  int * v3267 = v3264->regs;
  int v3268 = v3267[15];
  int * v3269 = v3264->regs;
  int v20611 = (int)((unsigned int)v3268 >> 19);
  v3269[9] = v20611;
  struct StateT * v20604 = v3271(v3264);
  return v20604;
}

struct StateT * v10297(struct StateT * v10298) {
  int v10299 = v10298->timer;
  int v17694 = v10299 + 1;
  v10298->timer = v17694;
  int * v10301 = v10298->regs;
  int v10302 = v10301[14];
  int * v10303 = v10298->regs;
  int v10304 = v10303[22];
  int * v10305 = v10298->regs;
  int v17701 = v10302 + v10304;
  v10305[18] = v17701;
  struct StateT * v17692 = v10307(v10298);
  return v17692;
}

struct StateT * v9023(struct StateT * v9024) {
  int v9025 = v9024->timer;
  int v19159 = v9025 + 1;
  v9024->timer = v19159;
  int * v9027 = v9024->regs;
  int v9028 = v9027[9];
  int * v9029 = v9024->regs;
  int v19164 = (int)((unsigned int)v9028 >> 19);
  v9029[20] = v19164;
  struct StateT * v19157 = v9031(v9024);
  return v19157;
}

struct StateT * v3515(struct StateT * v3516) {
  int v3517 = v3516->timer;
  int v20314 = v3517 + 1;
  v3516->timer = v20314;
  int * v3519 = v3516->regs;
  int v3520 = v3519[8];
  int * v3521 = v3516->regs;
  int v3522 = v3521[9];
  int * v3523 = v3516->regs;
  int v20320 = v3520 | v3522;
  v3523[8] = v20320;
  struct StateT * v20312 = v3525(v3516);
  return v20312;
}

struct StateT * v10711(struct StateT * v10712) {
  int v10713 = v10712->timer;
  int v17229 = v10713 + 1;
  v10712->timer = v17229;
  int * v10715 = v10712->regs;
  int v10716 = v10715[15];
  int * v10717 = v10712->regs;
  int v17234 = (int)((unsigned int)v10716 >> 14);
  v10717[6] = v17234;
  struct StateT * v17227 = v10719(v10712);
  return v17227;
}

struct StateT * v11607(struct StateT * v11608) {
  int * v11609 = v11608->regs;
  int v11610 = v11609[31];
  int * v11611 = v11608->regs;
  int v11612 = v11611[30];
  bool v16112 = (v11610 ^ -2147483648) >= (v11612 ^ -2147483648);
  struct StateT * v16106;
  if (v16112) {
    struct StateT * v11614 = v10035(v11608);
    v16106 = v11614;
  } else {
    int v11616 = v11608->timer;
    int v16115 = v11616 + 15;
    v11608->timer = v16115;
    int * v11618 = v11608->saved_regs;
    int v11619 = v11618[15];
    int * v11620 = v11608->regs;
    v11620[15] = v11619;
    int * v11622 = v11608->saved_regs;
    int v11623 = v11622[20];
    int * v11624 = v11608->regs;
    v11624[20] = v11623;
    int * v11626 = v11608->saved_regs;
    int v11627 = v11626[18];
    int * v11628 = v11608->regs;
    v11628[18] = v11627;
    int * v11630 = v11608->saved_regs;
    int v11631 = v11630[8];
    int * v11632 = v11608->regs;
    v11632[8] = v11631;
    int * v11634 = v11608->saved_regs;
    int v11635 = v11634[9];
    int * v11636 = v11608->regs;
    v11636[9] = v11635;
    int * v11638 = v11608->saved_regs;
    int v11639 = v11638[12];
    int * v11640 = v11608->regs;
    v11640[12] = v11639;
    int * v11642 = v11608->saved_regs;
    int v11643 = v11642[13];
    int * v11644 = v11608->regs;
    v11644[13] = v11643;
    int * v11646 = v11608->saved_regs;
    int v11647 = v11646[1];
    int * v11648 = v11608->regs;
    v11648[1] = v11647;
    int * v11650 = v11608->saved_regs;
    int v11651 = v11650[14];
    int * v11652 = v11608->regs;
    v11652[14] = v11651;
    int * v11654 = v11608->saved_regs;
    int v11655 = v11654[26];
    int * v11656 = v11608->regs;
    v11656[26] = v11655;
    int * v11658 = v11608->saved_regs;
    int v11659 = v11658[24];
    int * v11660 = v11608->regs;
    v11660[24] = v11659;
    int * v11662 = v11608->saved_regs;
    int v11663 = v11662[27];
    int * v11664 = v11608->regs;
    v11664[27] = v11663;
    int * v11666 = v11608->saved_regs;
    int v11667 = v11666[25];
    int * v11668 = v11608->regs;
    v11668[25] = v11667;
    int * v11670 = v11608->saved_regs;
    int v11671 = v11670[6];
    int * v11672 = v11608->regs;
    v11672[6] = v11671;
    int * v11674 = v11608->saved_regs;
    int v11675 = v11674[23];
    int * v11676 = v11608->regs;
    v11676[23] = v11675;
    int * v11678 = v11608->saved_regs;
    int v11679 = v11678[16];
    int * v11680 = v11608->regs;
    v11680[16] = v11679;
    int * v11682 = v11608->saved_regs;
    int v11683 = v11682[17];
    int * v11684 = v11608->regs;
    v11684[17] = v11683;
    int * v11686 = v11608->saved_regs;
    int v11687 = v11686[5];
    int * v11688 = v11608->regs;
    v11688[5] = v11687;
    int * v11690 = v11608->saved_regs;
    int v11691 = v11690[21];
    int * v11692 = v11608->regs;
    v11692[21] = v11691;
    int * v11694 = v11608->saved_regs;
    int v11695 = v11694[19];
    int * v11696 = v11608->regs;
    v11696[19] = v11695;
    int * v11698 = v11608->saved_regs;
    int v11699 = v11698[22];
    int * v11700 = v11608->regs;
    v11700[22] = v11699;
    int * v11702 = v11608->saved_regs;
    int v11703 = v11702[11];
    int * v11704 = v11608->regs;
    v11704[11] = v11703;
    struct StateT * v16104 = v11706(v11608);
    v16106 = v16104;
  }
  return v16106;
}

struct StateT * v1939(struct StateT * v1940) {
  int v1941 = v1940->timer;
  int v22056 = v1941 + 1;
  v1940->timer = v22056;
  int * v1943 = v1940->regs;
  int v1944 = v1943[2];
  int * v1945 = v1940->regs;
  int v1946 = v1945[15];
  int * v1947 = v1940->cache_keys;
  int v1948 = v1947[0];
  bool v22063 = v1948 == ((int)((unsigned int)(v1944 + 24) >> 2));
  int v1992;
  if (v22063) {
    int * v1949 = v1940->cache_vals;
    v1949[0] = v1946;
    v1992 = v1946;
  } else {
    int * v1952 = v1940->cache_keys;
    int v1953 = v1952[1];
    bool v22068 = v1953 == ((int)((unsigned int)(v1944 + 24) >> 2));
    int v1990;
    if (v22068) {
      int * v1954 = v1940->cache_keys;
      int * v1955 = v1940->cache_keys;
      int v1956 = v1955[0];
      v1954[1] = v1956;
      int * v1958 = v1940->cache_vals;
      int * v1959 = v1940->cache_vals;
      int v1960 = v1959[0];
      v1958[1] = v1960;
      int * v1962 = v1940->cache_keys;
      int v22076 = (int)((unsigned int)(v1944 + 24) >> 2);
      v1962[0] = v22076;
      int * v1964 = v1940->cache_vals;
      v1964[0] = v1946;
      int v1966 = v1940->timer;
      int v22079 = v1966 + 1;
      v1940->timer = v22079;
      v1990 = v1946;
    } else {
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
      int v22092 = (int)((unsigned int)(v1944 + 24) >> 2);
      v1983[0] = v22092;
      int * v1985 = v1940->cache_vals;
      v1985[0] = v1946;
      int v1987 = v1940->timer;
      int v22095 = v1987 + 100;
      v1940->timer = v22095;
      v1990 = v1946;
    }
    v1992 = v1990;
  }
  struct StateT * v22054 = v1993(v1940);
  return v22054;
}

struct StateT * v3391(struct StateT * v3392) {
  int v3393 = v3392->timer;
  int v20458 = v3393 + 1;
  v3392->timer = v20458;
  int * v3395 = v3392->regs;
  int v3396 = v3395[12];
  int * v3397 = v3392->regs;
  int v3398 = v3397[25];
  int * v3399 = v3392->regs;
  int v20465 = v3396 + v3398;
  v3399[15] = v20465;
  struct StateT * v20456 = v3401(v3392);
  return v20456;
}

struct StateT * v10745(struct StateT * v10746) {
  int v10747 = v10746->timer;
  int v17190 = v10747 + 1;
  v10746->timer = v17190;
  int * v10749 = v10746->regs;
  int v10750 = v10749[16];
  int * v10751 = v10746->regs;
  int v17194 = v10750 << 18;
  v10751[16] = v17194;
  struct StateT * v17188 = v10753(v10746);
  return v17188;
}

struct StateT * v8951(struct StateT * v8952) {
  int v8953 = v8952->timer;
  int v19241 = v8953 + 1;
  v8952->timer = v19241;
  int * v8955 = v8952->regs;
  int v8956 = v8955[27];
  int * v8957 = v8952->regs;
  int v8958 = v8957[1];
  int * v8959 = v8952->regs;
  int v19248 = v8956 + v8958;
  v8959[9] = v19248;
  struct StateT * v19239 = v8961(v8952);
  return v19239;
}

struct StateT * v10253(struct StateT * v10254) {
  int * v10255 = v10254->saved_regs;
  int * v10256 = v10254->regs;
  int v10257 = v10256[14];
  v10255[14] = v10257;
  int v10259 = v10254->timer;
  int v17746 = v10259 + 1;
  v10254->timer = v17746;
  int * v10261 = v10254->regs;
  int v10262 = v10261[14];
  int * v10263 = v10254->regs;
  int v10264 = v10263[8];
  int * v10265 = v10254->regs;
  int v17751 = v10262 ^ v10264;
  v10265[14] = v17751;
  struct StateT * v17740 = v10267(v10254);
  return v17740;
}

struct StateT * v8873(struct StateT * v8874) {
  int v8875 = v8874->timer;
  int v19332 = v8875 + 1;
  v8874->timer = v19332;
  int * v8877 = v8874->regs;
  int v8878 = v8877[18];
  int * v8879 = v8874->regs;
  int v19336 = v8878 << 9;
  v8879[18] = v19336;
  struct StateT * v19330 = v8881(v8874);
  return v19330;
}

struct StateT * v3411(struct StateT * v3412) {
  int v3413 = v3412->timer;
  int v20434 = v3413 + 1;
  v3412->timer = v20434;
  int * v3415 = v3412->regs;
  int v3416 = v3415[1];
  int * v3417 = v3412->regs;
  int v3418 = v3417[24];
  int * v3419 = v3412->regs;
  int v20441 = v3416 + v3418;
  v3419[8] = v20441;
  struct StateT * v20432 = v3421(v3412);
  return v20432;
}

struct StateT * v11163(struct StateT * v11164) {
  int v11165 = v11164->timer;
  int v16708 = v11165 + 1;
  v11164->timer = v16708;
  int * v11167 = v11164->regs;
  int v11168 = v11167[6];
  int * v11169 = v11164->regs;
  int v11170 = v11169[9];
  int * v11171 = v11164->regs;
  int v16714 = v11168 | v11170;
  v11171[6] = v16714;
  struct StateT * v16706 = v11173(v11164);
  return v16706;
}

struct StateT * v9075(struct StateT * v9076) {
  int v9077 = v9076->timer;
  int v19096 = v9077 + 1;
  v9076->timer = v19096;
  int * v9079 = v9076->regs;
  int v9080 = v9079[16];
  int * v9081 = v9076->regs;
  int v9082 = v9081[15];
  int * v9083 = v9076->regs;
  int v19103 = v9080 ^ v9082;
  v9083[9] = v19103;
  struct StateT * v19094 = v9085(v9076);
  return v19094;
}

struct StateT * v3177(struct StateT * v3178) {
  int v3179 = v3178->timer;
  int v20705 = v3179 + 1;
  v3178->timer = v20705;
  int * v3181 = v3178->regs;
  int v3182 = v3181[26];
  int * v3183 = v3178->regs;
  int v3184 = v3183[6];
  int * v3185 = v3178->regs;
  int v20711 = v3182 ^ v3184;
  v3185[26] = v20711;
  struct StateT * v20703 = v3187(v3178);
  return v20703;
}

struct StateT * v9347(struct StateT * v9348) {
  int v9349 = v9348->timer;
  int v18781 = v9349 + 1;
  v9348->timer = v18781;
  int * v9351 = v9348->regs;
  int v9352 = v9351[15];
  int * v9353 = v9348->regs;
  int v18785 = v9352 << 7;
  v9353[15] = v18785;
  struct StateT * v18779 = v9355(v9348);
  return v18779;
}

struct StateT * v4383(struct StateT * v4384) {
  int v4385 = v4384->timer;
  int v7421 = v4385 + 1;
  v4384->timer = v7421;
  int * v4387 = v4384->regs;
  int v4388 = v4387[11];
  int * v4389 = v4384->regs;
  int v4390 = v4389[6];
  int * v4391 = v4384->regs;
  int v7427 = v4388 + v4390;
  v4391[11] = v7427;
  struct StateT * v7419 = v4393(v4384);
  return v7419;
}

struct StateT * v10945(struct StateT * v10946) {
  int v10947 = v10946->timer;
  int v16965 = v10947 + 1;
  v10946->timer = v16965;
  int * v10949 = v10946->regs;
  int v10950 = v10949[11];
  int * v10951 = v10946->regs;
  int v16969 = v10950 << 7;
  v10951[11] = v16969;
  struct StateT * v16963 = v10953(v10946);
  return v16963;
}

struct StateT * v2877(struct StateT * v2878) {
  int v2879 = v2878->timer;
  int v21055 = v2879 + 1;
  v2878->timer = v21055;
  int * v2881 = v2878->regs;
  int v2882 = v2881[15];
  int * v2883 = v2878->regs;
  int v21059 = v2882 << 7;
  v2883[15] = v21059;
  struct StateT * v21053 = v2885(v2878);
  return v21053;
}

struct StateT * v8361(struct StateT * v8362) {
  int v8363 = v8362->timer;
  int v19846 = v8363 + 1;
  v8362->timer = v19846;
  int * v8365 = v8362->regs;
  int v8366 = v8365[2];
  int * v8367 = v8362->cache_keys;
  int v8368 = v8367[0];
  bool v19851 = v8368 == ((int)((unsigned int)(v8366 + 20) >> 2));
  int v8416;
  if (v19851) {
    int * v8369 = v8362->cache_vals;
    int v8370 = v8369[0];
    v8416 = v8370;
  } else {
    int * v8372 = v8362->cache_keys;
    int v8373 = v8372[1];
    bool v19856 = v8373 == ((int)((unsigned int)(v8366 + 20) >> 2));
    int v8414;
    if (v19856) {
      int * v8374 = v8362->cache_vals;
      int v8375 = v8374[1];
      int * v8376 = v8362->cache_keys;
      int * v8377 = v8362->cache_keys;
      int v8378 = v8377[0];
      v8376[1] = v8378;
      int * v8380 = v8362->cache_vals;
      int * v8381 = v8362->cache_vals;
      int v8382 = v8381[0];
      v8380[1] = v8382;
      int * v8384 = v8362->cache_keys;
      int v19865 = (int)((unsigned int)(v8366 + 20) >> 2);
      v8384[0] = v19865;
      int * v8386 = v8362->cache_vals;
      v8386[0] = v8375;
      int v8388 = v8362->timer;
      int v19868 = v8388 + 1;
      v8362->timer = v19868;
      v8414 = v8375;
    } else {
      int * v8391 = v8362->mem;
      int v19870 = (int)((unsigned int)(v8366 + 20) >> 2);
      int v8392 = v8391[v19870];
      int * v8393 = v8362->mem;
      int * v8394 = v8362->cache_keys;
      int v8395 = v8394[1];
      int * v8396 = v8362->cache_vals;
      int v8397 = v8396[1];
      v8393[v8395] = v8397;
      int * v8399 = v8362->cache_keys;
      int * v8400 = v8362->cache_keys;
      int v8401 = v8400[0];
      v8399[1] = v8401;
      int * v8403 = v8362->cache_vals;
      int * v8404 = v8362->cache_vals;
      int v8405 = v8404[0];
      v8403[1] = v8405;
      int * v8407 = v8362->cache_keys;
      v8407[0] = v19870;
      int * v8409 = v8362->cache_vals;
      v8409[0] = v8392;
      int v8411 = v8362->timer;
      int v19885 = v8411 + 100;
      v8362->timer = v19885;
      v8414 = v8392;
    }
    v8416 = v8414;
  }
  int * v8417 = v8362->regs;
  v8417[7] = v8416;
  struct StateT * v19844 = v8419(v8362);
  return v19844;
}

struct StateT * v8697(struct StateT * v8698) {
  int v8699 = v8698->timer;
  int v19533 = v8699 + 1;
  v8698->timer = v19533;
  int * v8701 = v8698->regs;
  int v8702 = v8701[8];
  int * v8703 = v8698->regs;
  int v8704 = v8703[20];
  int * v8705 = v8698->regs;
  int v19539 = v8702 | v8704;
  v8705[8] = v19539;
  struct StateT * v19531 = v8707(v8698);
  return v19531;
}

struct StateT * v13038(struct StateT * v13039) {
  int v13040 = v13039->timer;
  int v14890 = v13040 + 1;
  v13039->timer = v14890;
  int * v13042 = v13039->regs;
  int v13043 = v13042[10];
  int * v13044 = v13039->regs;
  int v13045 = v13044[17];
  int * v13046 = v13039->cache_keys;
  int v13047 = v13046[0];
  bool v14897 = v13047 == ((int)((unsigned int)(v13043 + 44) >> 2));
  int v13091;
  if (v14897) {
    int * v13048 = v13039->cache_vals;
    v13048[0] = v13045;
    v13091 = v13045;
  } else {
    int * v13051 = v13039->cache_keys;
    int v13052 = v13051[1];
    bool v14902 = v13052 == ((int)((unsigned int)(v13043 + 44) >> 2));
    int v13089;
    if (v14902) {
      int * v13053 = v13039->cache_keys;
      int * v13054 = v13039->cache_keys;
      int v13055 = v13054[0];
      v13053[1] = v13055;
      int * v13057 = v13039->cache_vals;
      int * v13058 = v13039->cache_vals;
      int v13059 = v13058[0];
      v13057[1] = v13059;
      int * v13061 = v13039->cache_keys;
      int v14910 = (int)((unsigned int)(v13043 + 44) >> 2);
      v13061[0] = v14910;
      int * v13063 = v13039->cache_vals;
      v13063[0] = v13045;
      int v13065 = v13039->timer;
      int v14913 = v13065 + 1;
      v13039->timer = v14913;
      v13089 = v13045;
    } else {
      int * v13068 = v13039->mem;
      int * v13069 = v13039->cache_keys;
      int v13070 = v13069[1];
      int * v13071 = v13039->cache_vals;
      int v13072 = v13071[1];
      v13068[v13070] = v13072;
      int * v13074 = v13039->cache_keys;
      int * v13075 = v13039->cache_keys;
      int v13076 = v13075[0];
      v13074[1] = v13076;
      int * v13078 = v13039->cache_vals;
      int * v13079 = v13039->cache_vals;
      int v13080 = v13079[0];
      v13078[1] = v13080;
      int * v13082 = v13039->cache_keys;
      int v14926 = (int)((unsigned int)(v13043 + 44) >> 2);
      v13082[0] = v14926;
      int * v13084 = v13039->cache_vals;
      v13084[0] = v13045;
      int v13086 = v13039->timer;
      int v14929 = v13086 + 100;
      v13039->timer = v14929;
      v13089 = v13045;
    }
    v13091 = v13089;
  }
  struct StateT * v14888 = v13092(v13039);
  return v14888;
}

struct StateT * v8829(struct StateT * v8830) {
  int v8831 = v8830->timer;
  int v19381 = v8831 + 1;
  v8830->timer = v19381;
  int * v8833 = v8830->regs;
  int v8834 = v8833[8];
  int * v8835 = v8830->regs;
  int v8836 = v8835[20];
  int * v8837 = v8830->regs;
  int v19387 = v8834 | v8836;
  v8837[8] = v19387;
  struct StateT * v19379 = v8839(v8830);
  return v19379;
}

struct StateT * v4737(struct StateT * v4738) {
  int v4739 = v4738->timer;
  int v7084 = v4739 + 1;
  v4738->timer = v7084;
  int * v4741 = v4738->regs;
  int v4742 = v4741[10];
  int * v4743 = v4738->regs;
  int v4744 = v4743[5];
  int * v4745 = v4738->cache_keys;
  int v4746 = v4745[0];
  bool v7091 = v4746 == ((int)((unsigned int)(v4742 + 24) >> 2));
  int v4790;
  if (v7091) {
    int * v4747 = v4738->cache_vals;
    v4747[0] = v4744;
    v4790 = v4744;
  } else {
    int * v4750 = v4738->cache_keys;
    int v4751 = v4750[1];
    bool v7096 = v4751 == ((int)((unsigned int)(v4742 + 24) >> 2));
    int v4788;
    if (v7096) {
      int * v4752 = v4738->cache_keys;
      int * v4753 = v4738->cache_keys;
      int v4754 = v4753[0];
      v4752[1] = v4754;
      int * v4756 = v4738->cache_vals;
      int * v4757 = v4738->cache_vals;
      int v4758 = v4757[0];
      v4756[1] = v4758;
      int * v4760 = v4738->cache_keys;
      int v7104 = (int)((unsigned int)(v4742 + 24) >> 2);
      v4760[0] = v7104;
      int * v4762 = v4738->cache_vals;
      v4762[0] = v4744;
      int v4764 = v4738->timer;
      int v7107 = v4764 + 1;
      v4738->timer = v7107;
      v4788 = v4744;
    } else {
      int * v4767 = v4738->mem;
      int * v4768 = v4738->cache_keys;
      int v4769 = v4768[1];
      int * v4770 = v4738->cache_vals;
      int v4771 = v4770[1];
      v4767[v4769] = v4771;
      int * v4773 = v4738->cache_keys;
      int * v4774 = v4738->cache_keys;
      int v4775 = v4774[0];
      v4773[1] = v4775;
      int * v4777 = v4738->cache_vals;
      int * v4778 = v4738->cache_vals;
      int v4779 = v4778[0];
      v4777[1] = v4779;
      int * v4781 = v4738->cache_keys;
      int v7120 = (int)((unsigned int)(v4742 + 24) >> 2);
      v4781[0] = v7120;
      int * v4783 = v4738->cache_vals;
      v4783[0] = v4744;
      int v4785 = v4738->timer;
      int v7123 = v4785 + 100;
      v4738->timer = v7123;
      v4788 = v4744;
    }
    v4790 = v4788;
  }
  struct StateT * v7082 = v4791(v4738);
  return v7082;
}

struct StateT * v13598(struct StateT * v13599) {
  int v13600 = v13599->timer;
  int v14423 = v13600 + 1;
  v13599->timer = v14423;
  int * v13602 = v13599->regs;
  int v13603 = v13602[2];
  int * v13604 = v13599->cache_keys;
  int v13605 = v13604[0];
  bool v14428 = v13605 == ((int)((unsigned int)(v13603 + 72) >> 2));
  int v13653;
  if (v14428) {
    int * v13606 = v13599->cache_vals;
    int v13607 = v13606[0];
    v13653 = v13607;
  } else {
    int * v13609 = v13599->cache_keys;
    int v13610 = v13609[1];
    bool v14433 = v13610 == ((int)((unsigned int)(v13603 + 72) >> 2));
    int v13651;
    if (v14433) {
      int * v13611 = v13599->cache_vals;
      int v13612 = v13611[1];
      int * v13613 = v13599->cache_keys;
      int * v13614 = v13599->cache_keys;
      int v13615 = v13614[0];
      v13613[1] = v13615;
      int * v13617 = v13599->cache_vals;
      int * v13618 = v13599->cache_vals;
      int v13619 = v13618[0];
      v13617[1] = v13619;
      int * v13621 = v13599->cache_keys;
      int v14442 = (int)((unsigned int)(v13603 + 72) >> 2);
      v13621[0] = v14442;
      int * v13623 = v13599->cache_vals;
      v13623[0] = v13612;
      int v13625 = v13599->timer;
      int v14445 = v13625 + 1;
      v13599->timer = v14445;
      v13651 = v13612;
    } else {
      int * v13628 = v13599->mem;
      int v14447 = (int)((unsigned int)(v13603 + 72) >> 2);
      int v13629 = v13628[v14447];
      int * v13630 = v13599->mem;
      int * v13631 = v13599->cache_keys;
      int v13632 = v13631[1];
      int * v13633 = v13599->cache_vals;
      int v13634 = v13633[1];
      v13630[v13632] = v13634;
      int * v13636 = v13599->cache_keys;
      int * v13637 = v13599->cache_keys;
      int v13638 = v13637[0];
      v13636[1] = v13638;
      int * v13640 = v13599->cache_vals;
      int * v13641 = v13599->cache_vals;
      int v13642 = v13641[0];
      v13640[1] = v13642;
      int * v13644 = v13599->cache_keys;
      v13644[0] = v14447;
      int * v13646 = v13599->cache_vals;
      v13646[0] = v13629;
      int v13648 = v13599->timer;
      int v14462 = v13648 + 100;
      v13599->timer = v14462;
      v13651 = v13629;
    }
    v13653 = v13651;
  }
  int * v13654 = v13599->regs;
  v13654[20] = v13653;
  struct StateT * v14421 = v13656(v13599);
  return v14421;
}

struct StateT * v2425(struct StateT * v2426) {
  int v2427 = v2426->timer;
  int v21566 = v2427 + 1;
  v2426->timer = v21566;
  int * v2429 = v2426->regs;
  int v2430 = v2429[26];
  int * v2431 = v2426->regs;
  int v2432 = v2431[12];
  int * v2433 = v2426->regs;
  int v21573 = v2430 + v2432;
  v2433[15] = v21573;
  struct StateT * v21564 = v2435(v2426);
  return v21564;
}

struct StateT * v2499(struct StateT * v2500) {
  int v2501 = v2500->timer;
  int v21481 = v2501 + 1;
  v2500->timer = v21481;
  int * v2503 = v2500->regs;
  int v2504 = v2503[8];
  int * v2505 = v2500->regs;
  int v21485 = v2504 << 13;
  v2505[8] = v21485;
  struct StateT * v21479 = v2507(v2500);
  return v21479;
}

struct StateT * v10911(struct StateT * v10912) {
  int v10913 = v10912->timer;
  int v17004 = v10913 + 1;
  v10912->timer = v17004;
  int * v10915 = v10912->regs;
  int v10916 = v10915[15];
  int * v10917 = v10912->regs;
  int v17009 = (int)((unsigned int)v10916 >> 25);
  v10917[5] = v17009;
  struct StateT * v17002 = v10919(v10912);
  return v17002;
}

struct StateT * v11035(struct StateT * v11036) {
  int v11037 = v11036->timer;
  int v16858 = v11037 + 1;
  v11036->timer = v16858;
  int * v11039 = v11036->regs;
  int v11040 = v11039[8];
  int * v11041 = v11036->regs;
  int v11042 = v11041[16];
  int * v11043 = v11036->regs;
  int v16865 = v11040 ^ v11042;
  v11043[17] = v16865;
  struct StateT * v16856 = v11045(v11036);
  return v16856;
}

struct StateT * v9223(struct StateT * v9224) {
  int v9225 = v9224->timer;
  int v18923 = v9225 + 1;
  v9224->timer = v18923;
  int * v9227 = v9224->regs;
  int v9228 = v9227[17];
  int * v9229 = v9224->regs;
  int v9230 = v9229[6];
  int * v9231 = v9224->regs;
  int v18929 = v9228 | v9230;
  v9231[17] = v18929;
  struct StateT * v18921 = v9233(v9224);
  return v18921;
}

struct StateT * v3043(struct StateT * v3044) {
  int v3045 = v3044->timer;
  int v20858 = v3045 + 1;
  v3044->timer = v20858;
  int * v3047 = v3044->regs;
  int v3048 = v3047[16];
  int * v3049 = v3044->regs;
  int v3050 = v3049[22];
  int * v3051 = v3044->regs;
  int v20865 = v3048 + v3050;
  v3051[8] = v20865;
  struct StateT * v20856 = v3053(v3044);
  return v20856;
}

struct StateT * v9155(struct StateT * v9156) {
  int v9157 = v9156->timer;
  int v19003 = v9157 + 1;
  v9156->timer = v19003;
  int * v9159 = v9156->regs;
  int v9160 = v9159[15];
  int * v9161 = v9156->regs;
  int v19008 = (int)((unsigned int)v9160 >> 14);
  v9161[6] = v19008;
  struct StateT * v19001 = v9163(v9156);
  return v19001;
}

struct StateT * v10193(struct StateT * v10194) {
  int v10195 = v10194->timer;
  int v17809 = v10195 + 1;
  v10194->timer = v17809;
  int * v10197 = v10194->regs;
  int v10198 = v10197[8];
  int * v10199 = v10194->regs;
  int v17813 = v10198 << 7;
  v10199[8] = v17813;
  struct StateT * v17807 = v10201(v10194);
  return v17807;
}

struct StateT * v6031(struct StateT * v6032) {
  int v6033 = v6032->timer;
  int v6047 = v6033 + 1;
  v6032->timer = v6047;
  int * v6035 = v6032->regs;
  int v6036 = v6035[2];
  int * v6037 = v6032->regs;
  int v6051 = v6036 + 96;
  v6037[2] = v6051;
  struct StateT * v6045 = v6039(v6032);
  return v6045;
}

struct StateT * v3147(struct StateT * v3148) {
  int v3149 = v3148->timer;
  int v20738 = v3149 + 1;
  v3148->timer = v20738;
  int * v3151 = v3148->regs;
  int v3152 = v3151[8];
  int * v3153 = v3148->regs;
  int v3154 = v3153[9];
  int * v3155 = v3148->regs;
  int v20744 = v3152 | v3154;
  v3155[8] = v20744;
  struct StateT * v20736 = v3157(v3148);
  return v20736;
}

struct StateT * v10891(struct StateT * v10892) {
  int v10893 = v10892->timer;
  int v17026 = v10893 + 1;
  v10892->timer = v17026;
  int * v10895 = v10892->regs;
  int v10896 = v10895[19];
  int * v10897 = v10892->regs;
  int v10898 = v10897[13];
  int * v10899 = v10892->regs;
  int v17033 = v10896 + v10898;
  v10899[16] = v17033;
  struct StateT * v17024 = v10901(v10892);
  return v17024;
}

struct StateT * v11259(struct StateT * v11260) {
  int v11261 = v11260->timer;
  int v16598 = v11261 + 1;
  v11260->timer = v16598;
  int * v11263 = v11260->regs;
  int v11264 = v11263[26];
  int * v11265 = v11260->regs;
  int v11266 = v11265[17];
  int * v11267 = v11260->regs;
  int v16605 = v11264 + v11266;
  v11267[6] = v16605;
  struct StateT * v16596 = v11269(v11260);
  return v16596;
}

struct StateT * v3843(struct StateT * v3844) {
  int v3845 = v3844->timer;
  int v7908 = v3845 + 1;
  v3844->timer = v7908;
  int * v3847 = v3844->regs;
  int v3848 = v3847[5];
  int * v3849 = v3844->regs;
  int v3850 = v3849[7];
  int * v3851 = v3844->regs;
  int v7914 = v3848 + v3850;
  v3851[5] = v7914;
  struct StateT * v7906 = v3853(v3844);
  return v7906;
}

struct StateT * v10089(struct StateT * v10090) {
  int * v10091 = v10090->saved_regs;
  int * v10092 = v10090->regs;
  int v10093 = v10092[8];
  v10091[8] = v10093;
  int v10095 = v10090->timer;
  int v17925 = v10095 + 1;
  v10090->timer = v17925;
  int * v10097 = v10090->regs;
  int v10098 = v10097[22];
  int * v10099 = v10090->regs;
  int v10100 = v10099[17];
  int * v10101 = v10090->regs;
  int v17931 = v10098 + v10100;
  v10101[8] = v17931;
  struct StateT * v17919 = v10103(v10090);
  return v17919;
}

struct StateT * v833(struct StateT * v834) {
  int v835 = v834->timer;
  int v23011 = v835 + 1;
  v834->timer = v23011;
  int * v837 = v834->regs;
  int v838 = v837[12];
  int * v839 = v834->cache_keys;
  int v840 = v839[0];
  bool v23016 = v840 == ((int)((unsigned int)(v838 + 8) >> 2));
  int v888;
  if (v23016) {
    int * v841 = v834->cache_vals;
    int v842 = v841[0];
    v888 = v842;
  } else {
    int * v844 = v834->cache_keys;
    int v845 = v844[1];
    bool v23021 = v845 == ((int)((unsigned int)(v838 + 8) >> 2));
    int v886;
    if (v23021) {
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
      int v23030 = (int)((unsigned int)(v838 + 8) >> 2);
      v856[0] = v23030;
      int * v858 = v834->cache_vals;
      v858[0] = v847;
      int v860 = v834->timer;
      int v23033 = v860 + 1;
      v834->timer = v23033;
      v886 = v847;
    } else {
      int * v863 = v834->mem;
      int v23035 = (int)((unsigned int)(v838 + 8) >> 2);
      int v864 = v863[v23035];
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
      v879[0] = v23035;
      int * v881 = v834->cache_vals;
      v881[0] = v864;
      int v883 = v834->timer;
      int v23050 = v883 + 100;
      v834->timer = v23050;
      v886 = v864;
    }
    v888 = v886;
  }
  int * v889 = v834->regs;
  v889[7] = v888;
  struct StateT * v23009 = v891(v834);
  return v23009;
}

struct StateT * v2351(struct StateT * v2352) {
  int v2353 = v2352->timer;
  int v21645 = v2353 + 1;
  v2352->timer = v21645;
  int * v2355 = v2352->regs;
  int v2356 = v2355[18];
  int * v2357 = v2352->regs;
  int v21649 = v2356 << 9;
  v2357[18] = v21649;
  struct StateT * v21643 = v2359(v2352);
  return v21643;
}

struct StateT * v3711(struct StateT * v3712) {
  int v3713 = v3712->timer;
  int v7986 = v3713 + 1;
  v3712->timer = v7986;
  int * v3715 = v3712->regs;
  int v3716 = v3715[2];
  int * v3717 = v3712->cache_keys;
  int v3718 = v3717[0];
  bool v7991 = v3718 == ((int)((unsigned int)(v3716 + 8) >> 2));
  int v3766;
  if (v7991) {
    int * v3719 = v3712->cache_vals;
    int v3720 = v3719[0];
    v3766 = v3720;
  } else {
    int * v3722 = v3712->cache_keys;
    int v3723 = v3722[1];
    bool v7996 = v3723 == ((int)((unsigned int)(v3716 + 8) >> 2));
    int v3764;
    if (v7996) {
      int * v3724 = v3712->cache_vals;
      int v3725 = v3724[1];
      int * v3726 = v3712->cache_keys;
      int * v3727 = v3712->cache_keys;
      int v3728 = v3727[0];
      v3726[1] = v3728;
      int * v3730 = v3712->cache_vals;
      int * v3731 = v3712->cache_vals;
      int v3732 = v3731[0];
      v3730[1] = v3732;
      int * v3734 = v3712->cache_keys;
      int v8005 = (int)((unsigned int)(v3716 + 8) >> 2);
      v3734[0] = v8005;
      int * v3736 = v3712->cache_vals;
      v3736[0] = v3725;
      int v3738 = v3712->timer;
      int v8008 = v3738 + 1;
      v3712->timer = v8008;
      v3764 = v3725;
    } else {
      int * v3741 = v3712->mem;
      int v8010 = (int)((unsigned int)(v3716 + 8) >> 2);
      int v3742 = v3741[v8010];
      int * v3743 = v3712->mem;
      int * v3744 = v3712->cache_keys;
      int v3745 = v3744[1];
      int * v3746 = v3712->cache_vals;
      int v3747 = v3746[1];
      v3743[v3745] = v3747;
      int * v3749 = v3712->cache_keys;
      int * v3750 = v3712->cache_keys;
      int v3751 = v3750[0];
      v3749[1] = v3751;
      int * v3753 = v3712->cache_vals;
      int * v3754 = v3712->cache_vals;
      int v3755 = v3754[0];
      v3753[1] = v3755;
      int * v3757 = v3712->cache_keys;
      v3757[0] = v8010;
      int * v3759 = v3712->cache_vals;
      v3759[0] = v3742;
      int v3761 = v3712->timer;
      int v8025 = v3761 + 100;
      v3712->timer = v8025;
      v3764 = v3742;
    }
    v3766 = v3764;
  }
  int * v3767 = v3712->regs;
  v3767[6] = v3766;
  struct StateT * v7984 = v3769(v3712);
  return v7984;
}

struct StateT * v11549(struct StateT * v11550) {
  int v11551 = v11550->timer;
  int v16265 = v11551 + 1;
  v11550->timer = v16265;
  int * v11553 = v11550->regs;
  int v11554 = v11553[8];
  int * v11555 = v11550->regs;
  int v16269 = v11554 << 18;
  v11555[8] = v16269;
  struct StateT * v16263 = v11557(v11550);
  return v16263;
}

struct StateT * v11249(struct StateT * v11250) {
  int v11251 = v11250->timer;
  int v16610 = v11251 + 1;
  v11250->timer = v16610;
  int * v11253 = v11250->regs;
  int v11254 = v11253[25];
  int * v11255 = v11250->regs;
  int v11256 = v11255[5];
  int * v11257 = v11250->regs;
  int v16617 = v11254 + v11256;
  v11257[15] = v16617;
  struct StateT * v16608 = v11259(v11250);
  return v16608;
}

struct StateT * v9259(struct StateT * v9260) {
  int v9261 = v9260->timer;
  int v18882 = v9261 + 1;
  v9260->timer = v18882;
  int * v9263 = v9260->regs;
  int v9264 = v9263[21];
  int * v9265 = v9260->regs;
  int v9266 = v9265[15];
  int * v9267 = v9260->regs;
  int v18888 = v9264 ^ v9266;
  v9267[21] = v18888;
  struct StateT * v18880 = v9269(v9260);
  return v18880;
}

struct StateT * v8663(struct StateT * v8664) {
  int v8665 = v8664->timer;
  int v19574 = v8665 + 1;
  v8664->timer = v19574;
  int * v8667 = v8664->regs;
  int v8668 = v8667[18];
  int * v8669 = v8664->regs;
  int v19578 = v8668 << 7;
  v8669[18] = v19578;
  struct StateT * v19572 = v8671(v8664);
  return v19572;
}

struct StateT * v1745(struct StateT * v1746) {
  int v1747 = v1746->timer;
  int v22231 = v1747 + 1;
  v1746->timer = v22231;
  int * v1749 = v1746->regs;
  int v1750 = v1749[2];
  int * v1751 = v1746->regs;
  int v1752 = v1751[16];
  int * v1753 = v1746->cache_keys;
  int v1754 = v1753[0];
  bool v22238 = v1754 == ((int)((unsigned int)(v1750 + 32) >> 2));
  int v1798;
  if (v22238) {
    int * v1755 = v1746->cache_vals;
    v1755[0] = v1752;
    v1798 = v1752;
  } else {
    int * v1758 = v1746->cache_keys;
    int v1759 = v1758[1];
    bool v22243 = v1759 == ((int)((unsigned int)(v1750 + 32) >> 2));
    int v1796;
    if (v22243) {
      int * v1760 = v1746->cache_keys;
      int * v1761 = v1746->cache_keys;
      int v1762 = v1761[0];
      v1760[1] = v1762;
      int * v1764 = v1746->cache_vals;
      int * v1765 = v1746->cache_vals;
      int v1766 = v1765[0];
      v1764[1] = v1766;
      int * v1768 = v1746->cache_keys;
      int v22251 = (int)((unsigned int)(v1750 + 32) >> 2);
      v1768[0] = v22251;
      int * v1770 = v1746->cache_vals;
      v1770[0] = v1752;
      int v1772 = v1746->timer;
      int v22254 = v1772 + 1;
      v1746->timer = v22254;
      v1796 = v1752;
    } else {
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
      int v22267 = (int)((unsigned int)(v1750 + 32) >> 2);
      v1789[0] = v22267;
      int * v1791 = v1746->cache_vals;
      v1791[0] = v1752;
      int v1793 = v1746->timer;
      int v22270 = v1793 + 100;
      v1746->timer = v22270;
      v1796 = v1752;
    }
    v1798 = v1796;
  }
  struct StateT * v22229 = v1799(v1746);
  return v22229;
}

struct StateT * v549(struct StateT * v550) {
  int v551 = v550->timer;
  int v23253 = v551 + 1;
  v550->timer = v23253;
  int * v553 = v550->regs;
  int v554 = v553[2];
  int * v555 = v550->regs;
  int v556 = v555[25];
  int * v557 = v550->cache_keys;
  int v558 = v557[0];
  bool v23260 = v558 == ((int)((unsigned int)(v554 + 52) >> 2));
  int v602;
  if (v23260) {
    int * v559 = v550->cache_vals;
    v559[0] = v556;
    v602 = v556;
  } else {
    int * v562 = v550->cache_keys;
    int v563 = v562[1];
    bool v23265 = v563 == ((int)((unsigned int)(v554 + 52) >> 2));
    int v600;
    if (v23265) {
      int * v564 = v550->cache_keys;
      int * v565 = v550->cache_keys;
      int v566 = v565[0];
      v564[1] = v566;
      int * v568 = v550->cache_vals;
      int * v569 = v550->cache_vals;
      int v570 = v569[0];
      v568[1] = v570;
      int * v572 = v550->cache_keys;
      int v23273 = (int)((unsigned int)(v554 + 52) >> 2);
      v572[0] = v23273;
      int * v574 = v550->cache_vals;
      v574[0] = v556;
      int v576 = v550->timer;
      int v23276 = v576 + 1;
      v550->timer = v23276;
      v600 = v556;
    } else {
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
      int v23289 = (int)((unsigned int)(v554 + 52) >> 2);
      v593[0] = v23289;
      int * v595 = v550->cache_vals;
      v595[0] = v556;
      int v597 = v550->timer;
      int v23292 = v597 + 100;
      v550->timer = v23292;
      v600 = v556;
    }
    v602 = v600;
  }
  struct StateT * v23251 = v603(v550);
  return v23251;
}

struct StateT * v8987(struct StateT * v8988) {
  int v8989 = v8988->timer;
  int v19199 = v8989 + 1;
  v8988->timer = v19199;
  int * v8991 = v8988->regs;
  int v8992 = v8991[15];
  int * v8993 = v8988->regs;
  int v8994 = v8993[20];
  int * v8995 = v8988->regs;
  int v19205 = v8992 | v8994;
  v8995[15] = v19205;
  struct StateT * v19197 = v8997(v8988);
  return v19197;
}

struct StateT * v1461(struct StateT * v1462) {
  int v1463 = v1462->timer;
  int v22508 = v1463 + 1;
  v1462->timer = v22508;
  int * v1465 = v1462->regs;
  int v1466 = v1465[22];
  int * v1467 = v1462->regs;
  int v22512 = v1466 + 1396;
  v1467[22] = v22512;
  struct StateT * v22506 = v1469(v1462);
  return v22506;
}

struct StateT * v10601(struct StateT * v10602) {
  int * v10603 = v10602->saved_regs;
  int * v10604 = v10602->regs;
  int v10605 = v10604[6];
  v10603[6] = v10605;
  int v10607 = v10602->timer;
  int v17350 = v10607 + 1;
  v10602->timer = v17350;
  int * v10609 = v10602->regs;
  int v10610 = v10609[18];
  int * v10611 = v10602->regs;
  int v10612 = v10611[9];
  int * v10613 = v10602->regs;
  int v17356 = v10610 | v10612;
  v10613[6] = v17356;
  struct StateT * v17344 = v10615(v10602);
  return v17344;
}

struct StateT * v9775(struct StateT * v9776) {
  int v9777 = v9776->timer;
  int v18282 = v9777 + 1;
  v9776->timer = v18282;
  int * v9779 = v9776->regs;
  int v9780 = v9779[6];
  int * v9781 = v9776->regs;
  int v9782 = v9781[9];
  int * v9783 = v9776->regs;
  int v18288 = v9780 | v9782;
  v9783[6] = v18288;
  struct StateT * v18280 = v9785(v9776);
  return v18280;
}

struct StateT * v3455(struct StateT * v3456) {
  int v3457 = v3456->timer;
  int v20385 = v3457 + 1;
  v3456->timer = v20385;
  int * v3459 = v3456->regs;
  int v3460 = v3459[15];
  int * v3461 = v3456->regs;
  int v20389 = v3460 << 18;
  v3461[15] = v20389;
  struct StateT * v20383 = v3463(v3456);
  return v20383;
}

struct StateT * v11095(struct StateT * v11096) {
  int v11097 = v11096->timer;
  int v16788 = v11097 + 1;
  v11096->timer = v16788;
  int * v11099 = v11096->regs;
  int v11100 = v11099[11];
  int * v11101 = v11096->regs;
  int v16793 = (int)((unsigned int)v11100 >> 23);
  v11101[9] = v16793;
  struct StateT * v16786 = v11103(v11096);
  return v16786;
}

struct StateT * v10697(struct StateT * v10698) {
  int * v10699 = v10698->saved_regs;
  int * v10700 = v10698->regs;
  int v10701 = v10700[5];
  v10699[5] = v10701;
  int v10703 = v10698->timer;
  int v17243 = v10703 + 1;
  v10698->timer = v17243;
  int * v10705 = v10698->regs;
  int v10706 = v10705[8];
  int * v10707 = v10698->regs;
  int v10708 = v10707[25];
  int * v10709 = v10698->regs;
  int v17249 = v10706 + v10708;
  v10709[5] = v17249;
  struct StateT * v17237 = v10711(v10698);
  return v17237;
}

struct StateT * v8921(struct StateT * v8922) {
  int v8923 = v8922->timer;
  int v19277 = v8923 + 1;
  v8922->timer = v19277;
  int * v8925 = v8922->regs;
  int v8926 = v8925[25];
  int * v8927 = v8922->regs;
  int v8928 = v8927[18];
  int * v8929 = v8922->regs;
  int v19283 = v8926 ^ v8928;
  v8929[25] = v19283;
  struct StateT * v19275 = v8931(v8922);
  return v19275;
}

struct StateT * v8971(struct StateT * v8972) {
  int v8973 = v8972->timer;
  int v19219 = v8973 + 1;
  v8972->timer = v19219;
  int * v8975 = v8972->regs;
  int v8976 = v8975[15];
  int * v8977 = v8972->regs;
  int v19224 = (int)((unsigned int)v8976 >> 19);
  v8977[20] = v19224;
  struct StateT * v19217 = v8979(v8972);
  return v19217;
}

struct StateT * v3577(struct StateT * v3578) {
  int * v3579 = v3578->regs;
  int v3580 = v3579[31];
  bool v20156 = (v3580 ^ -2147483648) < -2147483648;
  struct StateT * v20152;
  if (v20156) {
    int v3581 = v3578->timer;
    int v20157 = v3581 + 15;
    v3578->timer = v20157;
    int * v3583 = v3578->saved_regs;
    int v3584 = v3583[15];
    int * v3585 = v3578->regs;
    v3585[15] = v3584;
    int * v3587 = v3578->saved_regs;
    int v3588 = v3587[20];
    int * v3589 = v3578->regs;
    v3589[20] = v3588;
    int * v3591 = v3578->saved_regs;
    int v3592 = v3591[18];
    int * v3593 = v3578->regs;
    v3593[18] = v3592;
    int * v3595 = v3578->saved_regs;
    int v3596 = v3595[8];
    int * v3597 = v3578->regs;
    v3597[8] = v3596;
    int * v3599 = v3578->saved_regs;
    int v3600 = v3599[9];
    int * v3601 = v3578->regs;
    v3601[9] = v3600;
    int * v3603 = v3578->saved_regs;
    int v3604 = v3603[12];
    int * v3605 = v3578->regs;
    v3605[12] = v3604;
    int * v3607 = v3578->saved_regs;
    int v3608 = v3607[13];
    int * v3609 = v3578->regs;
    v3609[13] = v3608;
    int * v3611 = v3578->saved_regs;
    int v3612 = v3611[1];
    int * v3613 = v3578->regs;
    v3613[1] = v3612;
    int * v3615 = v3578->saved_regs;
    int v3616 = v3615[14];
    int * v3617 = v3578->regs;
    v3617[14] = v3616;
    int * v3619 = v3578->saved_regs;
    int v3620 = v3619[26];
    int * v3621 = v3578->regs;
    v3621[26] = v3620;
    int * v3623 = v3578->saved_regs;
    int v3624 = v3623[24];
    int * v3625 = v3578->regs;
    v3625[24] = v3624;
    int * v3627 = v3578->saved_regs;
    int v3628 = v3627[27];
    int * v3629 = v3578->regs;
    v3629[27] = v3628;
    int * v3631 = v3578->saved_regs;
    int v3632 = v3631[25];
    int * v3633 = v3578->regs;
    v3633[25] = v3632;
    int * v3635 = v3578->saved_regs;
    int v3636 = v3635[6];
    int * v3637 = v3578->regs;
    v3637[6] = v3636;
    int * v3639 = v3578->saved_regs;
    int v3640 = v3639[23];
    int * v3641 = v3578->regs;
    v3641[23] = v3640;
    int * v3643 = v3578->saved_regs;
    int v3644 = v3643[16];
    int * v3645 = v3578->regs;
    v3645[16] = v3644;
    int * v3647 = v3578->saved_regs;
    int v3648 = v3647[17];
    int * v3649 = v3578->regs;
    v3649[17] = v3648;
    int * v3651 = v3578->saved_regs;
    int v3652 = v3651[5];
    int * v3653 = v3578->regs;
    v3653[5] = v3652;
    int * v3655 = v3578->saved_regs;
    int v3656 = v3655[21];
    int * v3657 = v3578->regs;
    v3657[21] = v3656;
    int * v3659 = v3578->saved_regs;
    int v3660 = v3659[19];
    int * v3661 = v3578->regs;
    v3661[19] = v3660;
    int * v3663 = v3578->saved_regs;
    int v3664 = v3663[22];
    int * v3665 = v3578->regs;
    v3665[22] = v3664;
    int * v3667 = v3578->saved_regs;
    int v3668 = v3667[11];
    int * v3669 = v3578->regs;
    v3669[11] = v3668;
    int * v3671 = v3578->saved_regs;
    int v3672 = v3671[30];
    int * v3673 = v3578->regs;
    v3673[30] = v3672;
    struct StateT * v8073 = v3675(v3578);
    v20152 = v8073;
  } else {
    struct StateT * v20150 = v8075(v3578);
    v20152 = v20150;
  }
  return v20152;
}

struct StateT * v10043(struct StateT * v10044) {
  int v10045 = v10044->timer;
  int v17981 = v10045 + 1;
  v10044->timer = v17981;
  struct StateT * v17979 = v10047(v10044);
  return v17979;
}

struct StateT * v9707(struct StateT * v9708) {
  int v9709 = v9708->timer;
  int v18362 = v9709 + 1;
  v9708->timer = v18362;
  int * v9711 = v9708->regs;
  int v9712 = v9711[11];
  int * v9713 = v9708->regs;
  int v18367 = (int)((unsigned int)v9712 >> 19);
  v9713[9] = v18367;
  struct StateT * v18360 = v9715(v9708);
  return v18360;
}

struct StateT * v2245(struct StateT * v2246) {
  int v2247 = v2246->timer;
  int v21766 = v2247 + 1;
  v2246->timer = v21766;
  int * v2249 = v2246->regs;
  int v2250 = v2249[1];
  int * v2251 = v2246->regs;
  int v2252 = v2251[19];
  int * v2253 = v2246->regs;
  int v21773 = v2250 + v2252;
  v2253[9] = v21773;
  struct StateT * v21764 = v2255(v2246);
  return v21764;
}

struct StateT * v10867(struct StateT * v10868) {
  int v10869 = v10868->timer;
  int v17053 = v10869 + 1;
  v10868->timer = v17053;
  int * v10871 = v10868->regs;
  int v10872 = v10871[21];
  int * v10873 = v10868->regs;
  int v10874 = v10873[14];
  int * v10875 = v10868->regs;
  int v17060 = v10872 + v10874;
  v10875[15] = v17060;
  struct StateT * v17051 = v10877(v10868);
  return v17051;
}

struct StateT * v9289(struct StateT * v9290) {
  int v9291 = v9290->timer;
  int v18848 = v9291 + 1;
  v9290->timer = v18848;
  int * v9293 = v9290->regs;
  int v9294 = v9293[22];
  int * v9295 = v9290->regs;
  int v9296 = v9295[5];
  int * v9297 = v9290->regs;
  int v18854 = v9294 ^ v9296;
  v9297[22] = v18854;
  struct StateT * v18846 = v9299(v9290);
  return v18846;
}

struct StateT * v12876(struct StateT * v12877) {
  int v12878 = v12877->timer;
  int v15025 = v12878 + 1;
  v12877->timer = v15025;
  int * v12880 = v12877->regs;
  int v12881 = v12880[10];
  int * v12882 = v12877->regs;
  int v12883 = v12882[26];
  int * v12884 = v12877->cache_keys;
  int v12885 = v12884[0];
  bool v15032 = v12885 == ((int)((unsigned int)(v12881 + 32) >> 2));
  int v12929;
  if (v15032) {
    int * v12886 = v12877->cache_vals;
    v12886[0] = v12883;
    v12929 = v12883;
  } else {
    int * v12889 = v12877->cache_keys;
    int v12890 = v12889[1];
    bool v15037 = v12890 == ((int)((unsigned int)(v12881 + 32) >> 2));
    int v12927;
    if (v15037) {
      int * v12891 = v12877->cache_keys;
      int * v12892 = v12877->cache_keys;
      int v12893 = v12892[0];
      v12891[1] = v12893;
      int * v12895 = v12877->cache_vals;
      int * v12896 = v12877->cache_vals;
      int v12897 = v12896[0];
      v12895[1] = v12897;
      int * v12899 = v12877->cache_keys;
      int v15045 = (int)((unsigned int)(v12881 + 32) >> 2);
      v12899[0] = v15045;
      int * v12901 = v12877->cache_vals;
      v12901[0] = v12883;
      int v12903 = v12877->timer;
      int v15048 = v12903 + 1;
      v12877->timer = v15048;
      v12927 = v12883;
    } else {
      int * v12906 = v12877->mem;
      int * v12907 = v12877->cache_keys;
      int v12908 = v12907[1];
      int * v12909 = v12877->cache_vals;
      int v12910 = v12909[1];
      v12906[v12908] = v12910;
      int * v12912 = v12877->cache_keys;
      int * v12913 = v12877->cache_keys;
      int v12914 = v12913[0];
      v12912[1] = v12914;
      int * v12916 = v12877->cache_vals;
      int * v12917 = v12877->cache_vals;
      int v12918 = v12917[0];
      v12916[1] = v12918;
      int * v12920 = v12877->cache_keys;
      int v15061 = (int)((unsigned int)(v12881 + 32) >> 2);
      v12920[0] = v15061;
      int * v12922 = v12877->cache_vals;
      v12922[0] = v12883;
      int v12924 = v12877->timer;
      int v15064 = v12924 + 100;
      v12877->timer = v15064;
      v12927 = v12883;
    }
    v12929 = v12927;
  }
  struct StateT * v15023 = v12930(v12877);
  return v15023;
}

struct StateT * v8117(struct StateT * v8118) {
  int * v8119 = v8118->saved_regs;
  int * v8120 = v8118->regs;
  int v8121 = v8120[14];
  v8119[14] = v8121;
  int v8123 = v8118->timer;
  int v20098 = v8123 + 1;
  v8118->timer = v20098;
  int * v8125 = v8118->regs;
  int v8126 = v8125[14];
  int * v8127 = v8118->regs;
  int v8128 = v8127[7];
  int * v8129 = v8118->regs;
  int v20103 = v8126 + v8128;
  v8129[14] = v20103;
  struct StateT * v20092 = v8131(v8118);
  return v20092;
}

struct StateT * v10453(struct StateT * v10454) {
  int * v10455 = v10454->saved_regs;
  int * v10456 = v10454->regs;
  int v10457 = v10456[25];
  v10455[25] = v10457;
  int v10459 = v10454->timer;
  int v17522 = v10459 + 1;
  v10454->timer = v17522;
  int * v10461 = v10454->regs;
  int v10462 = v10461[25];
  int * v10463 = v10454->regs;
  int v10464 = v10463[18];
  int * v10465 = v10454->regs;
  int v17527 = v10462 ^ v10464;
  v10465[25] = v17527;
  struct StateT * v17516 = v10467(v10454);
  return v17516;
}

struct StateT * v10575(struct StateT * v10576) {
  int v10577 = v10576->timer;
  int v17380 = v10577 + 1;
  v10576->timer = v17380;
  int * v10579 = v10576->regs;
  int v10580 = v10579[9];
  int * v10581 = v10576->regs;
  int v10582 = v10581[20];
  int * v10583 = v10576->regs;
  int v17386 = v10580 | v10582;
  v10583[20] = v17386;
  struct StateT * v17378 = v10585(v10576);
  return v17378;
}

struct StateT * v13092(struct StateT * v13093) {
  int v13094 = v13093->timer;
  int v14845 = v13094 + 1;
  v13093->timer = v14845;
  int * v13096 = v13093->regs;
  int v13097 = v13096[10];
  int * v13098 = v13093->regs;
  int v13099 = v13098[16];
  int * v13100 = v13093->cache_keys;
  int v13101 = v13100[0];
  bool v14852 = v13101 == ((int)((unsigned int)(v13097 + 48) >> 2));
  int v13145;
  if (v14852) {
    int * v13102 = v13093->cache_vals;
    v13102[0] = v13099;
    v13145 = v13099;
  } else {
    int * v13105 = v13093->cache_keys;
    int v13106 = v13105[1];
    bool v14857 = v13106 == ((int)((unsigned int)(v13097 + 48) >> 2));
    int v13143;
    if (v14857) {
      int * v13107 = v13093->cache_keys;
      int * v13108 = v13093->cache_keys;
      int v13109 = v13108[0];
      v13107[1] = v13109;
      int * v13111 = v13093->cache_vals;
      int * v13112 = v13093->cache_vals;
      int v13113 = v13112[0];
      v13111[1] = v13113;
      int * v13115 = v13093->cache_keys;
      int v14865 = (int)((unsigned int)(v13097 + 48) >> 2);
      v13115[0] = v14865;
      int * v13117 = v13093->cache_vals;
      v13117[0] = v13099;
      int v13119 = v13093->timer;
      int v14868 = v13119 + 1;
      v13093->timer = v14868;
      v13143 = v13099;
    } else {
      int * v13122 = v13093->mem;
      int * v13123 = v13093->cache_keys;
      int v13124 = v13123[1];
      int * v13125 = v13093->cache_vals;
      int v13126 = v13125[1];
      v13122[v13124] = v13126;
      int * v13128 = v13093->cache_keys;
      int * v13129 = v13093->cache_keys;
      int v13130 = v13129[0];
      v13128[1] = v13130;
      int * v13132 = v13093->cache_vals;
      int * v13133 = v13093->cache_vals;
      int v13134 = v13133[0];
      v13132[1] = v13134;
      int * v13136 = v13093->cache_keys;
      int v14881 = (int)((unsigned int)(v13097 + 48) >> 2);
      v13136[0] = v14881;
      int * v13138 = v13093->cache_vals;
      v13138[0] = v13099;
      int v13140 = v13093->timer;
      int v14884 = v13140 + 100;
      v13093->timer = v14884;
      v13143 = v13099;
    }
    v13145 = v13143;
  }
  struct StateT * v14843 = v13146(v13093);
  return v14843;
}

struct StateT * v4629(struct StateT * v4630) {
  int v4631 = v4630->timer;
  int v7174 = v4631 + 1;
  v4630->timer = v7174;
  int * v4633 = v4630->regs;
  int v4634 = v4633[10];
  int * v4635 = v4630->regs;
  int v4636 = v4635[12];
  int * v4637 = v4630->cache_keys;
  int v4638 = v4637[0];
  bool v7181 = v4638 == ((int)((unsigned int)(v4634 + 16) >> 2));
  int v4682;
  if (v7181) {
    int * v4639 = v4630->cache_vals;
    v4639[0] = v4636;
    v4682 = v4636;
  } else {
    int * v4642 = v4630->cache_keys;
    int v4643 = v4642[1];
    bool v7186 = v4643 == ((int)((unsigned int)(v4634 + 16) >> 2));
    int v4680;
    if (v7186) {
      int * v4644 = v4630->cache_keys;
      int * v4645 = v4630->cache_keys;
      int v4646 = v4645[0];
      v4644[1] = v4646;
      int * v4648 = v4630->cache_vals;
      int * v4649 = v4630->cache_vals;
      int v4650 = v4649[0];
      v4648[1] = v4650;
      int * v4652 = v4630->cache_keys;
      int v7194 = (int)((unsigned int)(v4634 + 16) >> 2);
      v4652[0] = v7194;
      int * v4654 = v4630->cache_vals;
      v4654[0] = v4636;
      int v4656 = v4630->timer;
      int v7197 = v4656 + 1;
      v4630->timer = v7197;
      v4680 = v4636;
    } else {
      int * v4659 = v4630->mem;
      int * v4660 = v4630->cache_keys;
      int v4661 = v4660[1];
      int * v4662 = v4630->cache_vals;
      int v4663 = v4662[1];
      v4659[v4661] = v4663;
      int * v4665 = v4630->cache_keys;
      int * v4666 = v4630->cache_keys;
      int v4667 = v4666[0];
      v4665[1] = v4667;
      int * v4669 = v4630->cache_vals;
      int * v4670 = v4630->cache_vals;
      int v4671 = v4670[0];
      v4669[1] = v4671;
      int * v4673 = v4630->cache_keys;
      int v7210 = (int)((unsigned int)(v4634 + 16) >> 2);
      v4673[0] = v7210;
      int * v4675 = v4630->cache_vals;
      v4675[0] = v4636;
      int v4677 = v4630->timer;
      int v7213 = v4677 + 100;
      v4630->timer = v7213;
      v4680 = v4636;
    }
    v4682 = v4680;
  }
  struct StateT * v7172 = v4683(v4630);
  return v7172;
}

struct StateT * v4199(struct StateT * v4200) {
  int v4201 = v4200->timer;
  int v7557 = v4201 + 1;
  v4200->timer = v7557;
  int * v4203 = v4200->regs;
  int v4204 = v4203[2];
  int * v4205 = v4200->cache_keys;
  int v4206 = v4205[0];
  bool v7562 = v4206 == ((int)((unsigned int)(v4204 + 36) >> 2));
  int v4254;
  if (v7562) {
    int * v4207 = v4200->cache_vals;
    int v4208 = v4207[0];
    v4254 = v4208;
  } else {
    int * v4210 = v4200->cache_keys;
    int v4211 = v4210[1];
    bool v7567 = v4211 == ((int)((unsigned int)(v4204 + 36) >> 2));
    int v4252;
    if (v7567) {
      int * v4212 = v4200->cache_vals;
      int v4213 = v4212[1];
      int * v4214 = v4200->cache_keys;
      int * v4215 = v4200->cache_keys;
      int v4216 = v4215[0];
      v4214[1] = v4216;
      int * v4218 = v4200->cache_vals;
      int * v4219 = v4200->cache_vals;
      int v4220 = v4219[0];
      v4218[1] = v4220;
      int * v4222 = v4200->cache_keys;
      int v7576 = (int)((unsigned int)(v4204 + 36) >> 2);
      v4222[0] = v7576;
      int * v4224 = v4200->cache_vals;
      v4224[0] = v4213;
      int v4226 = v4200->timer;
      int v7579 = v4226 + 1;
      v4200->timer = v7579;
      v4252 = v4213;
    } else {
      int * v4229 = v4200->mem;
      int v7581 = (int)((unsigned int)(v4204 + 36) >> 2);
      int v4230 = v4229[v7581];
      int * v4231 = v4200->mem;
      int * v4232 = v4200->cache_keys;
      int v4233 = v4232[1];
      int * v4234 = v4200->cache_vals;
      int v4235 = v4234[1];
      v4231[v4233] = v4235;
      int * v4237 = v4200->cache_keys;
      int * v4238 = v4200->cache_keys;
      int v4239 = v4238[0];
      v4237[1] = v4239;
      int * v4241 = v4200->cache_vals;
      int * v4242 = v4200->cache_vals;
      int v4243 = v4242[0];
      v4241[1] = v4243;
      int * v4245 = v4200->cache_keys;
      v4245[0] = v7581;
      int * v4247 = v4200->cache_vals;
      v4247[0] = v4230;
      int v4249 = v4200->timer;
      int v7596 = v4249 + 100;
      v4200->timer = v7596;
      v4252 = v4230;
    }
    v4254 = v4252;
  }
  int * v4255 = v4200->regs;
  v4255[30] = v4254;
  struct StateT * v7555 = v4257(v4200);
  return v7555;
}

struct StateT * v10549(struct StateT * v10550) {
  int v10551 = v10550->timer;
  int v17410 = v10551 + 1;
  v10550->timer = v17410;
  int * v10553 = v10550->regs;
  int v10554 = v10553[8];
  int * v10555 = v10550->regs;
  int v10556 = v10555[20];
  int * v10557 = v10550->regs;
  int v17416 = v10554 | v10556;
  v10557[8] = v17416;
  struct StateT * v17408 = v10559(v10550);
  return v17408;
}

struct StateT * v3371(struct StateT * v3372) {
  int v3373 = v3372->timer;
  int v20482 = v3373 + 1;
  v3372->timer = v20482;
  int * v3375 = v3372->regs;
  int v3376 = v3375[1];
  int * v3377 = v3372->regs;
  int v3378 = v3377[8];
  int * v3379 = v3372->regs;
  int v20488 = v3376 ^ v3378;
  v3379[1] = v20488;
  struct StateT * v20480 = v3381(v3372);
  return v20480;
}

struct StateT * v10359(struct StateT * v10360) {
  int v10361 = v10360->timer;
  int v17624 = v10361 + 1;
  v10360->timer = v17624;
  int * v10363 = v10360->regs;
  int v10364 = v10363[9];
  int * v10365 = v10360->regs;
  int v17629 = (int)((unsigned int)v10364 >> 23);
  v10365[20] = v17629;
  struct StateT * v17622 = v10367(v10360);
  return v17622;
}

struct StateT * v12088(struct StateT * v12089) {
  int v12090 = v12089->timer;
  int v15754 = v12090 + 1;
  v12089->timer = v15754;
  int * v12092 = v12089->regs;
  v12092[7] = 2036477952;
  struct StateT * v15752 = v12094(v12089);
  return v15752;
}

struct StateT * v3157(struct StateT * v3158) {
  int v3159 = v3158->timer;
  int v20727 = v3159 + 1;
  v3158->timer = v20727;
  int * v3161 = v3158->regs;
  int v3162 = v3161[27];
  int * v3163 = v3158->regs;
  int v3164 = v3163[11];
  int * v3165 = v3158->regs;
  int v20733 = v3162 ^ v3164;
  v3165[27] = v20733;
  struct StateT * v20725 = v3167(v3158);
  return v20725;
}

struct StateT * v2583(struct StateT * v2584) {
  int * v2585 = v2584->saved_regs;
  int * v2586 = v2584->regs;
  int v2587 = v2586[23];
  v2585[23] = v2587;
  int v2589 = v2584->timer;
  int v21384 = v2589 + 1;
  v2584->timer = v21384;
  int * v2591 = v2584->regs;
  int v2592 = v2591[23];
  int * v2593 = v2584->regs;
  int v2594 = v2593[8];
  int * v2595 = v2584->regs;
  int v21389 = v2592 ^ v2594;
  v2595[23] = v21389;
  struct StateT * v21378 = v2597(v2584);
  return v21378;
}

struct StateT * v2655(struct StateT * v2656) {
  int * v2657 = v2656->saved_regs;
  int * v2658 = v2656->regs;
  int v2659 = v2658[5];
  v2657[5] = v2659;
  int v2661 = v2656->timer;
  int v21303 = v2661 + 1;
  v2656->timer = v21303;
  int * v2663 = v2656->regs;
  int v2664 = v2663[8];
  int * v2665 = v2656->regs;
  int v2666 = v2665[25];
  int * v2667 = v2656->regs;
  int v21309 = v2664 + v2666;
  v2667[5] = v21309;
  struct StateT * v21297 = v2669(v2656);
  return v21297;
}

struct StateT * v2685(struct StateT * v2686) {
  int v2687 = v2686->timer;
  int v21269 = v2687 + 1;
  v2686->timer = v21269;
  int * v2689 = v2686->regs;
  int v2690 = v2689[15];
  int * v2691 = v2686->regs;
  int v2692 = v2691[6];
  int * v2693 = v2686->regs;
  int v21275 = v2690 | v2692;
  v2693[15] = v21275;
  struct StateT * v21267 = v2695(v2686);
  return v21267;
}

struct StateT * v10149(struct StateT * v10150) {
  int v10151 = v10150->timer;
  int v17858 = v10151 + 1;
  v10150->timer = v17858;
  int * v10153 = v10150->regs;
  int v10154 = v10153[20];
  int * v10155 = v10150->regs;
  int v10156 = v10155[9];
  int * v10157 = v10150->regs;
  int v17864 = v10154 | v10156;
  v10157[9] = v17864;
  struct StateT * v17856 = v10159(v10150);
  return v17856;
}

struct StateT * v10133(struct StateT * v10134) {
  int v10135 = v10134->timer;
  int v17878 = v10135 + 1;
  v10134->timer = v17878;
  int * v10137 = v10134->regs;
  int v10138 = v10137[20];
  int * v10139 = v10134->regs;
  int v17883 = (int)((unsigned int)v10138 >> 25);
  v10139[9] = v17883;
  struct StateT * v17876 = v10141(v10134);
  return v17876;
}

struct StateT * v3361(struct StateT * v3362) {
  int v3363 = v3362->timer;
  int v20493 = v3363 + 1;
  v3362->timer = v20493;
  int * v3365 = v3362->regs;
  int v3366 = v3365[13];
  int * v3367 = v3362->regs;
  int v3368 = v3367[6];
  int * v3369 = v3362->regs;
  int v20499 = v3366 ^ v3368;
  v3369[13] = v20499;
  struct StateT * v20491 = v3371(v3362);
  return v20491;
}

struct StateT * v8637(struct StateT * v8638) {
  int v8639 = v8638->timer;
  int v19604 = v8639 + 1;
  v8638->timer = v19604;
  int * v8641 = v8638->regs;
  int v8642 = v8641[20];
  int * v8643 = v8638->regs;
  int v19608 = v8642 << 7;
  v8643[20] = v19608;
  struct StateT * v19602 = v8645(v8638);
  return v19602;
}

struct StateT * v9513(struct StateT * v9514) {
  int v9515 = v9514->timer;
  int v18584 = v9515 + 1;
  v9514->timer = v18584;
  int * v9517 = v9514->regs;
  int v9518 = v9517[16];
  int * v9519 = v9514->regs;
  int v9520 = v9519[22];
  int * v9521 = v9514->regs;
  int v18591 = v9518 + v9520;
  v9521[8] = v18591;
  struct StateT * v18582 = v9523(v9514);
  return v18582;
}

struct StateT * v2869(struct StateT * v2870) {
  int v2871 = v2870->timer;
  int v21064 = v2871 + 1;
  v2870->timer = v21064;
  int * v2873 = v2870->regs;
  int v2874 = v2873[15];
  int * v2875 = v2870->regs;
  int v21069 = (int)((unsigned int)v2874 >> 25);
  v2875[5] = v21069;
  struct StateT * v21062 = v2877(v2870);
  return v21062;
}

struct StateT * v2885(struct StateT * v2886) {
  int v2887 = v2886->timer;
  int v21044 = v2887 + 1;
  v2886->timer = v21044;
  int * v2889 = v2886->regs;
  int v2890 = v2889[15];
  int * v2891 = v2886->regs;
  int v2892 = v2891[5];
  int * v2893 = v2886->regs;
  int v21050 = v2890 | v2892;
  v2893[15] = v21050;
  struct StateT * v21042 = v2895(v2886);
  return v21042;
}

struct StateT * v9531(struct StateT * v9532) {
  int v9533 = v9532->timer;
  int v18565 = v9533 + 1;
  v9532->timer = v18565;
  int * v9535 = v9532->regs;
  int v9536 = v9535[11];
  int * v9537 = v9532->regs;
  int v18569 = v9536 << 9;
  v9537[11] = v18569;
  struct StateT * v18563 = v9539(v9532);
  return v18563;
}

struct StateT * v9135(struct StateT * v9136) {
  int v9137 = v9136->timer;
  int v19025 = v9137 + 1;
  v9136->timer = v19025;
  int * v9139 = v9136->regs;
  int v9140 = v9139[18];
  int * v9141 = v9136->regs;
  int v9142 = v9141[27];
  int * v9143 = v9136->regs;
  int v19032 = v9140 + v9142;
  v9143[17] = v19032;
  struct StateT * v19023 = v9145(v9136);
  return v19023;
}

struct StateT * v3207(struct StateT * v3208) {
  int v3209 = v3208->timer;
  int v20670 = v3209 + 1;
  v3208->timer = v20670;
  int * v3211 = v3208->regs;
  int v3212 = v3211[25];
  int * v3213 = v3208->regs;
  int v3214 = v3213[5];
  int * v3215 = v3208->regs;
  int v20677 = v3212 + v3214;
  v3215[15] = v20677;
  struct StateT * v20668 = v3217(v3208);
  return v20668;
}

struct StateT * v11423(struct StateT * v11424) {
  int v11425 = v11424->timer;
  int v16410 = v11425 + 1;
  v11424->timer = v16410;
  int * v11427 = v11424->regs;
  int v11428 = v11427[14];
  int * v11429 = v11424->regs;
  int v11430 = v11429[27];
  int * v11431 = v11424->regs;
  int v16417 = v11428 + v11430;
  v11431[11] = v16417;
  struct StateT * v16408 = v11433(v11424);
  return v16408;
}

struct StateT * v3253(struct StateT * v3254) {
  int v3255 = v3254->timer;
  int v20616 = v3255 + 1;
  v3254->timer = v20616;
  int * v3257 = v3254->regs;
  int v3258 = v3257[11];
  int * v3259 = v3254->regs;
  int v3260 = v3259[9];
  int * v3261 = v3254->regs;
  int v20622 = v3258 | v3260;
  v3261[11] = v20622;
  struct StateT * v20614 = v3263(v3254);
  return v20614;
}

struct StateT * v13308(struct StateT * v13309) {
  int v13310 = v13309->timer;
  int v14663 = v13310 + 1;
  v13309->timer = v14663;
  int * v13312 = v13309->regs;
  int v13313 = v13312[2];
  int * v13314 = v13309->cache_keys;
  int v13315 = v13314[0];
  bool v14668 = v13315 == ((int)((unsigned int)(v13313 + 92) >> 2));
  int v13363;
  if (v14668) {
    int * v13316 = v13309->cache_vals;
    int v13317 = v13316[0];
    v13363 = v13317;
  } else {
    int * v13319 = v13309->cache_keys;
    int v13320 = v13319[1];
    bool v14673 = v13320 == ((int)((unsigned int)(v13313 + 92) >> 2));
    int v13361;
    if (v14673) {
      int * v13321 = v13309->cache_vals;
      int v13322 = v13321[1];
      int * v13323 = v13309->cache_keys;
      int * v13324 = v13309->cache_keys;
      int v13325 = v13324[0];
      v13323[1] = v13325;
      int * v13327 = v13309->cache_vals;
      int * v13328 = v13309->cache_vals;
      int v13329 = v13328[0];
      v13327[1] = v13329;
      int * v13331 = v13309->cache_keys;
      int v14682 = (int)((unsigned int)(v13313 + 92) >> 2);
      v13331[0] = v14682;
      int * v13333 = v13309->cache_vals;
      v13333[0] = v13322;
      int v13335 = v13309->timer;
      int v14685 = v13335 + 1;
      v13309->timer = v14685;
      v13361 = v13322;
    } else {
      int * v13338 = v13309->mem;
      int v14687 = (int)((unsigned int)(v13313 + 92) >> 2);
      int v13339 = v13338[v14687];
      int * v13340 = v13309->mem;
      int * v13341 = v13309->cache_keys;
      int v13342 = v13341[1];
      int * v13343 = v13309->cache_vals;
      int v13344 = v13343[1];
      v13340[v13342] = v13344;
      int * v13346 = v13309->cache_keys;
      int * v13347 = v13309->cache_keys;
      int v13348 = v13347[0];
      v13346[1] = v13348;
      int * v13350 = v13309->cache_vals;
      int * v13351 = v13309->cache_vals;
      int v13352 = v13351[0];
      v13350[1] = v13352;
      int * v13354 = v13309->cache_keys;
      v13354[0] = v14687;
      int * v13356 = v13309->cache_vals;
      v13356[0] = v13339;
      int v13358 = v13309->timer;
      int v14702 = v13358 + 100;
      v13309->timer = v14702;
      v13361 = v13339;
    }
    v13363 = v13361;
  }
  int * v13364 = v13309->regs;
  v13364[1] = v13363;
  struct StateT * v14661 = v13366(v13309);
  return v14661;
}

struct StateT * v603(struct StateT * v604) {
  int v605 = v604->timer;
  int v23208 = v605 + 1;
  v604->timer = v23208;
  int * v607 = v604->regs;
  int v608 = v607[2];
  int * v609 = v604->regs;
  int v610 = v609[26];
  int * v611 = v604->cache_keys;
  int v612 = v611[0];
  bool v23215 = v612 == ((int)((unsigned int)(v608 + 48) >> 2));
  int v656;
  if (v23215) {
    int * v613 = v604->cache_vals;
    v613[0] = v610;
    v656 = v610;
  } else {
    int * v616 = v604->cache_keys;
    int v617 = v616[1];
    bool v23220 = v617 == ((int)((unsigned int)(v608 + 48) >> 2));
    int v654;
    if (v23220) {
      int * v618 = v604->cache_keys;
      int * v619 = v604->cache_keys;
      int v620 = v619[0];
      v618[1] = v620;
      int * v622 = v604->cache_vals;
      int * v623 = v604->cache_vals;
      int v624 = v623[0];
      v622[1] = v624;
      int * v626 = v604->cache_keys;
      int v23228 = (int)((unsigned int)(v608 + 48) >> 2);
      v626[0] = v23228;
      int * v628 = v604->cache_vals;
      v628[0] = v610;
      int v630 = v604->timer;
      int v23231 = v630 + 1;
      v604->timer = v23231;
      v654 = v610;
    } else {
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
      int v23244 = (int)((unsigned int)(v608 + 48) >> 2);
      v647[0] = v23244;
      int * v649 = v604->cache_vals;
      v649[0] = v610;
      int v651 = v604->timer;
      int v23247 = v651 + 100;
      v604->timer = v23247;
      v654 = v610;
    }
    v656 = v654;
  }
  struct StateT * v23206 = v657(v604);
  return v23206;
}

struct StateT * v8757(struct StateT * v8758) {
  int v8759 = v8758->timer;
  int v19465 = v8759 + 1;
  v8758->timer = v19465;
  int * v8761 = v8758->regs;
  int v8762 = v8761[13];
  int * v8763 = v8758->regs;
  int v8764 = v8763[11];
  int * v8765 = v8758->regs;
  int v19472 = v8762 + v8764;
  v8765[8] = v19472;
  struct StateT * v19463 = v8767(v8758);
  return v19463;
}

struct StateT * v2627(struct StateT * v2628) {
  int * v2629 = v2628->saved_regs;
  int * v2630 = v2628->regs;
  int v2631 = v2630[16];
  v2629[16] = v2631;
  int v2633 = v2628->timer;
  int v21333 = v2633 + 1;
  v2628->timer = v21333;
  int * v2635 = v2628->regs;
  int v2636 = v2635[23];
  int * v2637 = v2628->regs;
  int v2638 = v2637[24];
  int * v2639 = v2628->regs;
  int v21339 = v2636 + v2638;
  v2639[16] = v21339;
  struct StateT * v21327 = v2641(v2628);
  return v21327;
}

struct StateT * v495(struct StateT * v496) {
  int v497 = v496->timer;
  int v23298 = v497 + 1;
  v496->timer = v23298;
  int * v499 = v496->regs;
  int v500 = v499[2];
  int * v501 = v496->regs;
  int v502 = v501[24];
  int * v503 = v496->cache_keys;
  int v504 = v503[0];
  bool v23305 = v504 == ((int)((unsigned int)(v500 + 56) >> 2));
  int v548;
  if (v23305) {
    int * v505 = v496->cache_vals;
    v505[0] = v502;
    v548 = v502;
  } else {
    int * v508 = v496->cache_keys;
    int v509 = v508[1];
    bool v23310 = v509 == ((int)((unsigned int)(v500 + 56) >> 2));
    int v546;
    if (v23310) {
      int * v510 = v496->cache_keys;
      int * v511 = v496->cache_keys;
      int v512 = v511[0];
      v510[1] = v512;
      int * v514 = v496->cache_vals;
      int * v515 = v496->cache_vals;
      int v516 = v515[0];
      v514[1] = v516;
      int * v518 = v496->cache_keys;
      int v23318 = (int)((unsigned int)(v500 + 56) >> 2);
      v518[0] = v23318;
      int * v520 = v496->cache_vals;
      v520[0] = v502;
      int v522 = v496->timer;
      int v23321 = v522 + 1;
      v496->timer = v23321;
      v546 = v502;
    } else {
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
      int v23334 = (int)((unsigned int)(v500 + 56) >> 2);
      v539[0] = v23334;
      int * v541 = v496->cache_vals;
      v541[0] = v502;
      int v543 = v496->timer;
      int v23337 = v543 + 100;
      v496->timer = v23337;
      v546 = v502;
    }
    v548 = v546;
  }
  struct StateT * v23296 = v549(v496);
  return v23296;
}

struct StateT * v9381(struct StateT * v9382) {
  int v9383 = v9382->timer;
  int v18740 = v9383 + 1;
  v9382->timer = v18740;
  int * v9385 = v9382->regs;
  int v9386 = v9385[11];
  int * v9387 = v9382->regs;
  int v9388 = v9387[5];
  int * v9389 = v9382->regs;
  int v18746 = v9386 | v9388;
  v9389[11] = v18746;
  struct StateT * v18738 = v9391(v9382);
  return v18738;
}

struct StateT * v2091(struct StateT * v2092) {
  int v2093 = v2092->timer;
  int v21938 = v2093 + 1;
  v2092->timer = v21938;
  int * v2095 = v2092->regs;
  int v2096 = v2095[20];
  int * v2097 = v2092->regs;
  int v21943 = (int)((unsigned int)v2096 >> 25);
  v2097[9] = v21943;
  struct StateT * v21936 = v2099(v2092);
  return v21936;
}

struct StateT * v11045(struct StateT * v11046) {
  int v11047 = v11046->timer;
  int v16846 = v11047 + 1;
  v11046->timer = v16846;
  int * v11049 = v11046->regs;
  int v11050 = v11049[9];
  int * v11051 = v11046->regs;
  int v11052 = v11051[6];
  int * v11053 = v11046->regs;
  int v16853 = v11050 ^ v11052;
  v11053[16] = v16853;
  struct StateT * v16844 = v11055(v11046);
  return v16844;
}

struct StateT * v2973(struct StateT * v2974) {
  int v2975 = v2974->timer;
  int v20942 = v2975 + 1;
  v2974->timer = v20942;
  int * v2977 = v2974->regs;
  int v2978 = v2977[23];
  int * v2979 = v2974->regs;
  int v2980 = v2979[15];
  int * v2981 = v2974->regs;
  int v20948 = v2978 ^ v2980;
  v2981[23] = v20948;
  struct StateT * v20940 = v2983(v2974);
  return v20940;
}

struct StateT * v1431(struct StateT * v1432) {
  int v1433 = v1432->timer;
  int v22545 = v1433 + 1;
  v1432->timer = v22545;
  int * v1435 = v1432->regs;
  int v1436 = v1435[12];
  int * v1437 = v1432->regs;
  int v22550 = v1436 + -1947;
  v1437[21] = v22550;
  struct StateT * v22543 = v1439(v1432);
  return v22543;
}

struct StateT * v3565(struct StateT * v3566) {
  int * v3567 = v3566->saved_regs;
  int * v3568 = v3566->regs;
  int v3569 = v3568[30];
  v3567[30] = v3569;
  int v3571 = v3566->timer;
  int v20261 = v3571 + 1;
  v3566->timer = v20261;
  int * v3573 = v3566->regs;
  int v3574 = v3573[30];
  int * v3575 = v3566->regs;
  int v20264 = v3574 + 1;
  v3575[30] = v20264;
  struct StateT * v20255 = v3577(v3566);
  return v20255;
}

struct StateT * v8275(struct StateT * v8276) {
  int * v8277 = v8276->saved_regs;
  int * v8278 = v8276->regs;
  int v8279 = v8278[5];
  v8277[5] = v8279;
  int v8281 = v8276->timer;
  int v19960 = v8281 + 1;
  v8276->timer = v19960;
  int * v8283 = v8276->regs;
  int v8284 = v8283[5];
  int * v8285 = v8276->regs;
  int v8286 = v8285[7];
  int * v8287 = v8276->regs;
  int v19965 = v8284 + v8286;
  v8287[5] = v19965;
  struct StateT * v19954 = v8289(v8276);
  return v19954;
}

struct StateT * v2465(struct StateT * v2466) {
  int v2467 = v2466->timer;
  int v21520 = v2467 + 1;
  v2466->timer = v21520;
  int * v2469 = v2466->regs;
  int v2470 = v2469[15];
  int * v2471 = v2466->regs;
  int v21525 = (int)((unsigned int)v2470 >> 19);
  v2471[20] = v21525;
  struct StateT * v21518 = v2473(v2466);
  return v21518;
}

struct StateT * v11155(struct StateT * v11156) {
  int v11157 = v11156->timer;
  int v16719 = v11157 + 1;
  v11156->timer = v16719;
  int * v11159 = v11156->regs;
  int v11160 = v11159[6];
  int * v11161 = v11156->regs;
  int v16723 = v11160 << 9;
  v11161[6] = v16723;
  struct StateT * v16717 = v11163(v11156);
  return v16717;
}

struct StateT * v117(struct StateT * v118) {
  int v119 = v118->timer;
  int v23613 = v119 + 1;
  v118->timer = v23613;
  int * v121 = v118->regs;
  int v122 = v121[2];
  int * v123 = v118->regs;
  int v124 = v123[9];
  int * v125 = v118->cache_keys;
  int v126 = v125[0];
  bool v23620 = v126 == ((int)((unsigned int)(v122 + 84) >> 2));
  int v170;
  if (v23620) {
    int * v127 = v118->cache_vals;
    v127[0] = v124;
    v170 = v124;
  } else {
    int * v130 = v118->cache_keys;
    int v131 = v130[1];
    bool v23625 = v131 == ((int)((unsigned int)(v122 + 84) >> 2));
    int v168;
    if (v23625) {
      int * v132 = v118->cache_keys;
      int * v133 = v118->cache_keys;
      int v134 = v133[0];
      v132[1] = v134;
      int * v136 = v118->cache_vals;
      int * v137 = v118->cache_vals;
      int v138 = v137[0];
      v136[1] = v138;
      int * v140 = v118->cache_keys;
      int v23633 = (int)((unsigned int)(v122 + 84) >> 2);
      v140[0] = v23633;
      int * v142 = v118->cache_vals;
      v142[0] = v124;
      int v144 = v118->timer;
      int v23636 = v144 + 1;
      v118->timer = v23636;
      v168 = v124;
    } else {
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
      int v23649 = (int)((unsigned int)(v122 + 84) >> 2);
      v161[0] = v23649;
      int * v163 = v118->cache_vals;
      v163[0] = v124;
      int v165 = v118->timer;
      int v23652 = v165 + 100;
      v118->timer = v23652;
      v168 = v124;
    }
    v170 = v168;
  }
  struct StateT * v23611 = v171(v118);
  return v23611;
}

struct StateT * v13482(struct StateT * v13483) {
  int v13484 = v13483->timer;
  int v14519 = v13484 + 1;
  v13483->timer = v14519;
  int * v13486 = v13483->regs;
  int v13487 = v13486[2];
  int * v13488 = v13483->cache_keys;
  int v13489 = v13488[0];
  bool v14524 = v13489 == ((int)((unsigned int)(v13487 + 80) >> 2));
  int v13537;
  if (v14524) {
    int * v13490 = v13483->cache_vals;
    int v13491 = v13490[0];
    v13537 = v13491;
  } else {
    int * v13493 = v13483->cache_keys;
    int v13494 = v13493[1];
    bool v14529 = v13494 == ((int)((unsigned int)(v13487 + 80) >> 2));
    int v13535;
    if (v14529) {
      int * v13495 = v13483->cache_vals;
      int v13496 = v13495[1];
      int * v13497 = v13483->cache_keys;
      int * v13498 = v13483->cache_keys;
      int v13499 = v13498[0];
      v13497[1] = v13499;
      int * v13501 = v13483->cache_vals;
      int * v13502 = v13483->cache_vals;
      int v13503 = v13502[0];
      v13501[1] = v13503;
      int * v13505 = v13483->cache_keys;
      int v14538 = (int)((unsigned int)(v13487 + 80) >> 2);
      v13505[0] = v14538;
      int * v13507 = v13483->cache_vals;
      v13507[0] = v13496;
      int v13509 = v13483->timer;
      int v14541 = v13509 + 1;
      v13483->timer = v14541;
      v13535 = v13496;
    } else {
      int * v13512 = v13483->mem;
      int v14543 = (int)((unsigned int)(v13487 + 80) >> 2);
      int v13513 = v13512[v14543];
      int * v13514 = v13483->mem;
      int * v13515 = v13483->cache_keys;
      int v13516 = v13515[1];
      int * v13517 = v13483->cache_vals;
      int v13518 = v13517[1];
      v13514[v13516] = v13518;
      int * v13520 = v13483->cache_keys;
      int * v13521 = v13483->cache_keys;
      int v13522 = v13521[0];
      v13520[1] = v13522;
      int * v13524 = v13483->cache_vals;
      int * v13525 = v13483->cache_vals;
      int v13526 = v13525[0];
      v13524[1] = v13526;
      int * v13528 = v13483->cache_keys;
      v13528[0] = v14543;
      int * v13530 = v13483->cache_vals;
      v13530[0] = v13513;
      int v13532 = v13483->timer;
      int v14558 = v13532 + 100;
      v13483->timer = v14558;
      v13535 = v13513;
    }
    v13537 = v13535;
  }
  int * v13538 = v13483->regs;
  v13538[18] = v13537;
  struct StateT * v14517 = v13540(v13483);
  return v14517;
}

struct StateT * v8931(struct StateT * v8932) {
  int v8933 = v8932->timer;
  int v19265 = v8933 + 1;
  v8932->timer = v19265;
  int * v8935 = v8932->regs;
  int v8936 = v8935[26];
  int * v8937 = v8932->regs;
  int v8938 = v8937[12];
  int * v8939 = v8932->regs;
  int v19272 = v8936 + v8938;
  v8939[15] = v19272;
  struct StateT * v19263 = v8941(v8932);
  return v19263;
}

struct StateT * v11111(struct StateT * v11112) {
  int v11113 = v11112->timer;
  int v16768 = v11113 + 1;
  v11112->timer = v16768;
  int * v11115 = v11112->regs;
  int v11116 = v11115[11];
  int * v11117 = v11112->regs;
  int v11118 = v11117[9];
  int * v11119 = v11112->regs;
  int v16774 = v11116 | v11118;
  v11119[11] = v16774;
  struct StateT * v16766 = v11121(v11112);
  return v16766;
}

struct StateT * v9(struct StateT * v10) {
  int v11 = v10->timer;
  int v23703 = v11 + 1;
  v10->timer = v23703;
  int * v13 = v10->regs;
  int v14 = v13[2];
  int * v15 = v10->regs;
  int v16 = v15[1];
  int * v17 = v10->cache_keys;
  int v18 = v17[0];
  bool v23710 = v18 == ((int)((unsigned int)(v14 + 92) >> 2));
  int v62;
  if (v23710) {
    int * v19 = v10->cache_vals;
    v19[0] = v16;
    v62 = v16;
  } else {
    int * v22 = v10->cache_keys;
    int v23 = v22[1];
    bool v23714 = v23 == ((int)((unsigned int)(v14 + 92) >> 2));
    int v60;
    if (v23714) {
      int * v24 = v10->cache_keys;
      int * v25 = v10->cache_keys;
      int v26 = v25[0];
      v24[1] = v26;
      int * v28 = v10->cache_vals;
      int * v29 = v10->cache_vals;
      int v30 = v29[0];
      v28[1] = v30;
      int * v32 = v10->cache_keys;
      int v23722 = (int)((unsigned int)(v14 + 92) >> 2);
      v32[0] = v23722;
      int * v34 = v10->cache_vals;
      v34[0] = v16;
      int v36 = v10->timer;
      int v23725 = v36 + 1;
      v10->timer = v23725;
      v60 = v16;
    } else {
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
      int v23738 = (int)((unsigned int)(v14 + 92) >> 2);
      v53[0] = v23738;
      int * v55 = v10->cache_vals;
      v55[0] = v16;
      int v57 = v10->timer;
      int v23741 = v57 + 100;
      v10->timer = v23741;
      v60 = v16;
    }
    v62 = v60;
  }
  struct StateT * v23701 = v63(v10);
  return v23701;
}

struct StateT * v11505(struct StateT * v11506) {
  int v11507 = v11506->timer;
  int v16314 = v11507 + 1;
  v11506->timer = v16314;
  int * v11509 = v11506->regs;
  int v11510 = v11509[15];
  int * v11511 = v11506->regs;
  int v11512 = v11511[9];
  int * v11513 = v11506->regs;
  int v16320 = v11510 | v11512;
  v11513[15] = v16320;
  struct StateT * v16312 = v11515(v11506);
  return v16312;
}

struct StateT * v1007(struct StateT * v1008) {
  int v1009 = v1008->timer;
  int v22867 = v1009 + 1;
  v1008->timer = v22867;
  int * v1011 = v1008->regs;
  int v1012 = v1011[12];
  int * v1013 = v1008->cache_keys;
  int v1014 = v1013[0];
  bool v22872 = v1014 == ((int)((unsigned int)(v1012 + 20) >> 2));
  int v1062;
  if (v22872) {
    int * v1015 = v1008->cache_vals;
    int v1016 = v1015[0];
    v1062 = v1016;
  } else {
    int * v1018 = v1008->cache_keys;
    int v1019 = v1018[1];
    bool v22877 = v1019 == ((int)((unsigned int)(v1012 + 20) >> 2));
    int v1060;
    if (v22877) {
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
      int v22886 = (int)((unsigned int)(v1012 + 20) >> 2);
      v1030[0] = v22886;
      int * v1032 = v1008->cache_vals;
      v1032[0] = v1021;
      int v1034 = v1008->timer;
      int v22889 = v1034 + 1;
      v1008->timer = v22889;
      v1060 = v1021;
    } else {
      int * v1037 = v1008->mem;
      int v22891 = (int)((unsigned int)(v1012 + 20) >> 2);
      int v1038 = v1037[v22891];
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
      v1053[0] = v22891;
      int * v1055 = v1008->cache_vals;
      v1055[0] = v1038;
      int v1057 = v1008->timer;
      int v22906 = v1057 + 100;
      v1008->timer = v22906;
      v1060 = v1038;
    }
    v1062 = v1060;
  }
  int * v1063 = v1008->regs;
  v1063[16] = v1062;
  struct StateT * v22865 = v1065(v1008);
  return v22865;
}

struct StateT * v4845(struct StateT * v4846) {
  int v4847 = v4846->timer;
  int v6994 = v4847 + 1;
  v4846->timer = v6994;
  int * v4849 = v4846->regs;
  int v4850 = v4849[10];
  int * v4851 = v4846->regs;
  int v4852 = v4851[26];
  int * v4853 = v4846->cache_keys;
  int v4854 = v4853[0];
  bool v7001 = v4854 == ((int)((unsigned int)(v4850 + 32) >> 2));
  int v4898;
  if (v7001) {
    int * v4855 = v4846->cache_vals;
    v4855[0] = v4852;
    v4898 = v4852;
  } else {
    int * v4858 = v4846->cache_keys;
    int v4859 = v4858[1];
    bool v7006 = v4859 == ((int)((unsigned int)(v4850 + 32) >> 2));
    int v4896;
    if (v7006) {
      int * v4860 = v4846->cache_keys;
      int * v4861 = v4846->cache_keys;
      int v4862 = v4861[0];
      v4860[1] = v4862;
      int * v4864 = v4846->cache_vals;
      int * v4865 = v4846->cache_vals;
      int v4866 = v4865[0];
      v4864[1] = v4866;
      int * v4868 = v4846->cache_keys;
      int v7014 = (int)((unsigned int)(v4850 + 32) >> 2);
      v4868[0] = v7014;
      int * v4870 = v4846->cache_vals;
      v4870[0] = v4852;
      int v4872 = v4846->timer;
      int v7017 = v4872 + 1;
      v4846->timer = v7017;
      v4896 = v4852;
    } else {
      int * v4875 = v4846->mem;
      int * v4876 = v4846->cache_keys;
      int v4877 = v4876[1];
      int * v4878 = v4846->cache_vals;
      int v4879 = v4878[1];
      v4875[v4877] = v4879;
      int * v4881 = v4846->cache_keys;
      int * v4882 = v4846->cache_keys;
      int v4883 = v4882[0];
      v4881[1] = v4883;
      int * v4885 = v4846->cache_vals;
      int * v4886 = v4846->cache_vals;
      int v4887 = v4886[0];
      v4885[1] = v4887;
      int * v4889 = v4846->cache_keys;
      int v7030 = (int)((unsigned int)(v4850 + 32) >> 2);
      v4889[0] = v7030;
      int * v4891 = v4846->cache_vals;
      v4891[0] = v4852;
      int v4893 = v4846->timer;
      int v7033 = v4893 + 100;
      v4846->timer = v7033;
      v4896 = v4852;
    }
    v4898 = v4896;
  }
  struct StateT * v6992 = v4899(v4846);
  return v6992;
}

struct StateT * v2721(struct StateT * v2722) {
  int v2723 = v2722->timer;
  int v21229 = v2723 + 1;
  v2722->timer = v21229;
  int * v2725 = v2722->regs;
  int v2726 = v2725[17];
  int * v2727 = v2722->regs;
  int v21234 = (int)((unsigned int)v2726 >> 14);
  v2727[6] = v21234;
  struct StateT * v21227 = v2729(v2722);
  return v21227;
}

struct StateT * v1529(struct StateT * v1530) {
  int v1531 = v1530->timer;
  int v22410 = v1531 + 1;
  v1530->timer = v22410;
  int * v1533 = v1530->regs;
  int v1534 = v1533[2];
  int * v1535 = v1530->regs;
  int v1536 = v1535[25];
  int * v1537 = v1530->cache_keys;
  int v1538 = v1537[0];
  bool v22417 = v1538 == ((int)((unsigned int)(v1534 + 16) >> 2));
  int v1582;
  if (v22417) {
    int * v1539 = v1530->cache_vals;
    v1539[0] = v1536;
    v1582 = v1536;
  } else {
    int * v1542 = v1530->cache_keys;
    int v1543 = v1542[1];
    bool v22422 = v1543 == ((int)((unsigned int)(v1534 + 16) >> 2));
    int v1580;
    if (v22422) {
      int * v1544 = v1530->cache_keys;
      int * v1545 = v1530->cache_keys;
      int v1546 = v1545[0];
      v1544[1] = v1546;
      int * v1548 = v1530->cache_vals;
      int * v1549 = v1530->cache_vals;
      int v1550 = v1549[0];
      v1548[1] = v1550;
      int * v1552 = v1530->cache_keys;
      int v22430 = (int)((unsigned int)(v1534 + 16) >> 2);
      v1552[0] = v22430;
      int * v1554 = v1530->cache_vals;
      v1554[0] = v1536;
      int v1556 = v1530->timer;
      int v22433 = v1556 + 1;
      v1530->timer = v22433;
      v1580 = v1536;
    } else {
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
      int v22446 = (int)((unsigned int)(v1534 + 16) >> 2);
      v1573[0] = v22446;
      int * v1575 = v1530->cache_vals;
      v1575[0] = v1536;
      int v1577 = v1530->timer;
      int v22449 = v1577 + 100;
      v1530->timer = v22449;
      v1580 = v1536;
    }
    v1582 = v1580;
  }
  struct StateT * v22408 = v1583(v1530);
  return v22408;
}

struct StateT * v8717(struct StateT * v8718) {
  int v8719 = v8718->timer;
  int v19511 = v8719 + 1;
  v8718->timer = v19511;
  int * v8721 = v8718->regs;
  int v8722 = v8721[13];
  int * v8723 = v8718->regs;
  int v8724 = v8723[9];
  int * v8725 = v8718->regs;
  int v19517 = v8722 ^ v8724;
  v8725[13] = v19517;
  struct StateT * v19509 = v8727(v8718);
  return v19509;
}

struct StateT * v9723(struct StateT * v9724) {
  int v9725 = v9724->timer;
  int v18342 = v9725 + 1;
  v9724->timer = v18342;
  int * v9727 = v9724->regs;
  int v9728 = v9727[11];
  int * v9729 = v9724->regs;
  int v9730 = v9729[9];
  int * v9731 = v9724->regs;
  int v18348 = v9728 | v9730;
  v9731[11] = v18348;
  struct StateT * v18340 = v9733(v9724);
  return v18340;
}

struct StateT * v13888(struct StateT * v13889) {
  int v13890 = v13889->timer;
  int v14183 = v13890 + 1;
  v13889->timer = v14183;
  int * v13892 = v13889->regs;
  int v13893 = v13892[2];
  int * v13894 = v13889->cache_keys;
  int v13895 = v13894[0];
  bool v14188 = v13895 == ((int)((unsigned int)(v13893 + 52) >> 2));
  int v13943;
  if (v14188) {
    int * v13896 = v13889->cache_vals;
    int v13897 = v13896[0];
    v13943 = v13897;
  } else {
    int * v13899 = v13889->cache_keys;
    int v13900 = v13899[1];
    bool v14193 = v13900 == ((int)((unsigned int)(v13893 + 52) >> 2));
    int v13941;
    if (v14193) {
      int * v13901 = v13889->cache_vals;
      int v13902 = v13901[1];
      int * v13903 = v13889->cache_keys;
      int * v13904 = v13889->cache_keys;
      int v13905 = v13904[0];
      v13903[1] = v13905;
      int * v13907 = v13889->cache_vals;
      int * v13908 = v13889->cache_vals;
      int v13909 = v13908[0];
      v13907[1] = v13909;
      int * v13911 = v13889->cache_keys;
      int v14202 = (int)((unsigned int)(v13893 + 52) >> 2);
      v13911[0] = v14202;
      int * v13913 = v13889->cache_vals;
      v13913[0] = v13902;
      int v13915 = v13889->timer;
      int v14205 = v13915 + 1;
      v13889->timer = v14205;
      v13941 = v13902;
    } else {
      int * v13918 = v13889->mem;
      int v14207 = (int)((unsigned int)(v13893 + 52) >> 2);
      int v13919 = v13918[v14207];
      int * v13920 = v13889->mem;
      int * v13921 = v13889->cache_keys;
      int v13922 = v13921[1];
      int * v13923 = v13889->cache_vals;
      int v13924 = v13923[1];
      v13920[v13922] = v13924;
      int * v13926 = v13889->cache_keys;
      int * v13927 = v13889->cache_keys;
      int v13928 = v13927[0];
      v13926[1] = v13928;
      int * v13930 = v13889->cache_vals;
      int * v13931 = v13889->cache_vals;
      int v13932 = v13931[0];
      v13930[1] = v13932;
      int * v13934 = v13889->cache_keys;
      v13934[0] = v14207;
      int * v13936 = v13889->cache_vals;
      v13936[0] = v13919;
      int v13938 = v13889->timer;
      int v14222 = v13938 + 100;
      v13889->timer = v14222;
      v13941 = v13919;
    }
    v13943 = v13941;
  }
  int * v13944 = v13889->regs;
  v13944[25] = v13943;
  struct StateT * v14181 = v13946(v13889);
  return v14181;
}

struct StateT * v14004(struct StateT * v14005) {
  int v14006 = v14005->timer;
  int v14087 = v14006 + 1;
  v14005->timer = v14087;
  int * v14008 = v14005->regs;
  int v14009 = v14008[2];
  int * v14010 = v14005->cache_keys;
  int v14011 = v14010[0];
  bool v14092 = v14011 == ((int)((unsigned int)(v14009 + 44) >> 2));
  int v14059;
  if (v14092) {
    int * v14012 = v14005->cache_vals;
    int v14013 = v14012[0];
    v14059 = v14013;
  } else {
    int * v14015 = v14005->cache_keys;
    int v14016 = v14015[1];
    bool v14097 = v14016 == ((int)((unsigned int)(v14009 + 44) >> 2));
    int v14057;
    if (v14097) {
      int * v14017 = v14005->cache_vals;
      int v14018 = v14017[1];
      int * v14019 = v14005->cache_keys;
      int * v14020 = v14005->cache_keys;
      int v14021 = v14020[0];
      v14019[1] = v14021;
      int * v14023 = v14005->cache_vals;
      int * v14024 = v14005->cache_vals;
      int v14025 = v14024[0];
      v14023[1] = v14025;
      int * v14027 = v14005->cache_keys;
      int v14106 = (int)((unsigned int)(v14009 + 44) >> 2);
      v14027[0] = v14106;
      int * v14029 = v14005->cache_vals;
      v14029[0] = v14018;
      int v14031 = v14005->timer;
      int v14109 = v14031 + 1;
      v14005->timer = v14109;
      v14057 = v14018;
    } else {
      int * v14034 = v14005->mem;
      int v14111 = (int)((unsigned int)(v14009 + 44) >> 2);
      int v14035 = v14034[v14111];
      int * v14036 = v14005->mem;
      int * v14037 = v14005->cache_keys;
      int v14038 = v14037[1];
      int * v14039 = v14005->cache_vals;
      int v14040 = v14039[1];
      v14036[v14038] = v14040;
      int * v14042 = v14005->cache_keys;
      int * v14043 = v14005->cache_keys;
      int v14044 = v14043[0];
      v14042[1] = v14044;
      int * v14046 = v14005->cache_vals;
      int * v14047 = v14005->cache_vals;
      int v14048 = v14047[0];
      v14046[1] = v14048;
      int * v14050 = v14005->cache_keys;
      v14050[0] = v14111;
      int * v14052 = v14005->cache_vals;
      v14052[0] = v14035;
      int v14054 = v14005->timer;
      int v14126 = v14054 + 100;
      v14005->timer = v14126;
      v14057 = v14035;
    }
    v14059 = v14057;
  }
  int * v14060 = v14005->regs;
  v14060[27] = v14059;
  struct StateT * v14085 = v14062(v14005);
  return v14085;
}

struct StateT * v8961(struct StateT * v8962) {
  int v8963 = v8962->timer;
  int v19229 = v8963 + 1;
  v8962->timer = v19229;
  int * v8965 = v8962->regs;
  int v8966 = v8965[25];
  int * v8967 = v8962->regs;
  int v8968 = v8967[14];
  int * v8969 = v8962->regs;
  int v19236 = v8966 + v8968;
  v8969[18] = v19236;
  struct StateT * v19227 = v8971(v8962);
  return v19227;
}

struct StateT * v2435(struct StateT * v2436) {
  int v2437 = v2436->timer;
  int v21554 = v2437 + 1;
  v2436->timer = v21554;
  int * v2439 = v2436->regs;
  int v2440 = v2439[24];
  int * v2441 = v2436->regs;
  int v2442 = v2441[13];
  int * v2443 = v2436->regs;
  int v21561 = v2440 + v2442;
  v2443[8] = v21561;
  struct StateT * v21552 = v2445(v2436);
  return v21552;
}

struct StateT * v10727(struct StateT * v10728) {
  int v10729 = v10728->timer;
  int v17209 = v10729 + 1;
  v10728->timer = v17209;
  int * v10731 = v10728->regs;
  int v10732 = v10731[15];
  int * v10733 = v10728->regs;
  int v10734 = v10733[6];
  int * v10735 = v10728->regs;
  int v17215 = v10732 | v10734;
  v10735[15] = v17215;
  struct StateT * v17207 = v10737(v10728);
  return v17207;
}

struct StateT * v2107(struct StateT * v2108) {
  int v2109 = v2108->timer;
  int v21918 = v2109 + 1;
  v2108->timer = v21918;
  int * v2111 = v2108->regs;
  int v2112 = v2111[20];
  int * v2113 = v2108->regs;
  int v2114 = v2113[9];
  int * v2115 = v2108->regs;
  int v21924 = v2112 | v2114;
  v2115[9] = v21924;
  struct StateT * v21916 = v2117(v2108);
  return v21916;
}

struct StateT * v2143(struct StateT * v2144) {
  int v2145 = v2144->timer;
  int v21878 = v2145 + 1;
  v2144->timer = v21878;
  int * v2147 = v2144->regs;
  int v2148 = v2147[8];
  int * v2149 = v2144->regs;
  int v21883 = (int)((unsigned int)v2148 >> 25);
  v2149[20] = v21883;
  struct StateT * v21876 = v2151(v2144);
  return v21876;
}

struct StateT * v2081(struct StateT * v2082) {
  int v2083 = v2082->timer;
  int v21948 = v2083 + 1;
  v2082->timer = v21948;
  int * v2085 = v2082->regs;
  int v2086 = v2085[15];
  int * v2087 = v2082->regs;
  int v2088 = v2087[9];
  int * v2089 = v2082->regs;
  int v21954 = v2086 | v2088;
  v2089[15] = v21954;
  struct StateT * v21946 = v2091(v2082);
  return v21946;
}

struct StateT * v9453(struct StateT * v9454) {
  int v9455 = v9454->timer;
  int v18656 = v9455 + 1;
  v9454->timer = v18656;
  int * v9457 = v9454->regs;
  int v9458 = v9457[18];
  int * v9459 = v9454->regs;
  int v9460 = v9459[11];
  int * v9461 = v9454->regs;
  int v18663 = v9458 ^ v9460;
  v9461[5] = v18663;
  struct StateT * v18654 = v9463(v9454);
  return v18654;
}

struct StateT * v3481(struct StateT * v3482) {
  int v3483 = v3482->timer;
  int v20355 = v3483 + 1;
  v3482->timer = v20355;
  int * v3485 = v3482->regs;
  int v3486 = v3485[6];
  int * v3487 = v3482->regs;
  int v20359 = v3486 << 18;
  v3487[6] = v20359;
  struct StateT * v20353 = v3489(v3482);
  return v20353;
}

struct StateT * v10211(struct StateT * v10212) {
  int * v10213 = v10212->saved_regs;
  int * v10214 = v10212->regs;
  int v10215 = v10214[12];
  v10213[12] = v10215;
  int v10217 = v10212->timer;
  int v17788 = v10217 + 1;
  v10212->timer = v17788;
  int * v10219 = v10212->regs;
  int v10220 = v10219[12];
  int * v10221 = v10212->regs;
  int v10222 = v10221[15];
  int * v10223 = v10212->regs;
  int v17793 = v10220 ^ v10222;
  v10223[12] = v17793;
  struct StateT * v17782 = v10225(v10212);
  return v17782;
}

struct StateT * v3507(struct StateT * v3508) {
  int v3509 = v3508->timer;
  int v20325 = v3509 + 1;
  v3508->timer = v20325;
  int * v3511 = v3508->regs;
  int v3512 = v3511[8];
  int * v3513 = v3508->regs;
  int v20329 = v3512 << 18;
  v3513[8] = v20329;
  struct StateT * v20323 = v3515(v3508);
  return v20323;
}

struct StateT * v11121(struct StateT * v11122) {
  int v11123 = v11122->timer;
  int v16758 = v11123 + 1;
  v11122->timer = v16758;
  int * v11125 = v11122->regs;
  int v11126 = v11125[15];
  int * v11127 = v11122->regs;
  int v16763 = (int)((unsigned int)v11126 >> 23);
  v11127[9] = v16763;
  struct StateT * v16756 = v11129(v11122);
  return v16756;
}

struct StateT * v11443(struct StateT * v11444) {
  int v11445 = v11444->timer;
  int v16386 = v11445 + 1;
  v11444->timer = v16386;
  int * v11447 = v11444->regs;
  int v11448 = v11447[13];
  int * v11449 = v11444->regs;
  int v11450 = v11449[26];
  int * v11451 = v11444->regs;
  int v16393 = v11448 + v11450;
  v11451[6] = v16393;
  struct StateT * v16384 = v11453(v11444);
  return v16384;
}

struct StateT * v2835(struct StateT * v2836) {
  int * v2837 = v2836->saved_regs;
  int * v2838 = v2836->regs;
  int v2839 = v2838[11];
  v2837[11] = v2839;
  int v2841 = v2836->timer;
  int v21102 = v2841 + 1;
  v2836->timer = v21102;
  int * v2843 = v2836->regs;
  int v2844 = v2843[20];
  int * v2845 = v2836->regs;
  int v2846 = v2845[12];
  int * v2847 = v2836->regs;
  int v21108 = v2844 + v2846;
  v2847[11] = v21108;
  struct StateT * v21096 = v2849(v2836);
  return v21096;
}

struct StateT * v9013(struct StateT * v9014) {
  int v9015 = v9014->timer;
  int v19169 = v9015 + 1;
  v9014->timer = v19169;
  int * v9017 = v9014->regs;
  int v9018 = v9017[8];
  int * v9019 = v9014->regs;
  int v9020 = v9019[20];
  int * v9021 = v9014->regs;
  int v19175 = v9018 | v9020;
  v9021[8] = v19175;
  struct StateT * v19167 = v9023(v9014);
  return v19167;
}

struct StateT * v1455(struct StateT * v1456) {
  int v1457 = v1456->timer;
  int v22517 = v1457 + 1;
  v1456->timer = v22517;
  int * v1459 = v1456->regs;
  v1459[22] = 1797283840;
  struct StateT * v22515 = v1461(v1456);
  return v22515;
}

struct StateT * v2533(struct StateT * v2534) {
  int v2535 = v2534->timer;
  int v21440 = v2535 + 1;
  v2534->timer = v21440;
  int * v2537 = v2534->regs;
  int v2538 = v2537[9];
  int * v2539 = v2534->regs;
  int v2540 = v2539[20];
  int * v2541 = v2534->regs;
  int v21446 = v2538 | v2540;
  v2541[20] = v21446;
  struct StateT * v21438 = v2543(v2534);
  return v21438;
}

struct StateT * v11433(struct StateT * v11434) {
  int v11435 = v11434->timer;
  int v16398 = v11435 + 1;
  v11434->timer = v16398;
  int * v11437 = v11434->regs;
  int v11438 = v11437[12];
  int * v11439 = v11434->regs;
  int v11440 = v11439[25];
  int * v11441 = v11434->regs;
  int v16405 = v11438 + v11440;
  v11441[15] = v16405;
  struct StateT * v16396 = v11443(v11434);
  return v16396;
}

struct StateT * v8911(struct StateT * v8912) {
  int v8913 = v8912->timer;
  int v19288 = v8913 + 1;
  v8912->timer = v19288;
  int * v8915 = v8912->regs;
  int v8916 = v8915[27];
  int * v8917 = v8912->regs;
  int v8918 = v8917[9];
  int * v8919 = v8912->regs;
  int v19294 = v8916 ^ v8918;
  v8919[27] = v19294;
  struct StateT * v19286 = v8921(v8912);
  return v19286;
}

struct StateT * v10523(struct StateT * v10524) {
  int v10525 = v10524->timer;
  int v17440 = v10525 + 1;
  v10524->timer = v17440;
  int * v10527 = v10524->regs;
  int v10528 = v10527[15];
  int * v10529 = v10524->regs;
  int v10530 = v10529[20];
  int * v10531 = v10524->regs;
  int v17446 = v10528 | v10530;
  v10531[15] = v17446;
  struct StateT * v17438 = v10533(v10524);
  return v17438;
}

struct StateT * v279(struct StateT * v280) {
  int v281 = v280->timer;
  int v23478 = v281 + 1;
  v280->timer = v23478;
  int * v283 = v280->regs;
  int v284 = v283[2];
  int * v285 = v280->regs;
  int v286 = v285[20];
  int * v287 = v280->cache_keys;
  int v288 = v287[0];
  bool v23485 = v288 == ((int)((unsigned int)(v284 + 72) >> 2));
  int v332;
  if (v23485) {
    int * v289 = v280->cache_vals;
    v289[0] = v286;
    v332 = v286;
  } else {
    int * v292 = v280->cache_keys;
    int v293 = v292[1];
    bool v23490 = v293 == ((int)((unsigned int)(v284 + 72) >> 2));
    int v330;
    if (v23490) {
      int * v294 = v280->cache_keys;
      int * v295 = v280->cache_keys;
      int v296 = v295[0];
      v294[1] = v296;
      int * v298 = v280->cache_vals;
      int * v299 = v280->cache_vals;
      int v300 = v299[0];
      v298[1] = v300;
      int * v302 = v280->cache_keys;
      int v23498 = (int)((unsigned int)(v284 + 72) >> 2);
      v302[0] = v23498;
      int * v304 = v280->cache_vals;
      v304[0] = v286;
      int v306 = v280->timer;
      int v23501 = v306 + 1;
      v280->timer = v23501;
      v330 = v286;
    } else {
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
      int v23514 = (int)((unsigned int)(v284 + 72) >> 2);
      v323[0] = v23514;
      int * v325 = v280->cache_vals;
      v325[0] = v286;
      int v327 = v280->timer;
      int v23517 = v327 + 100;
      v280->timer = v23517;
      v330 = v286;
    }
    v332 = v330;
  }
  struct StateT * v23476 = v333(v280);
  return v23476;
}

struct StateT * v3187(struct StateT * v3188) {
  int v3189 = v3188->timer;
  int v20694 = v3189 + 1;
  v3188->timer = v20694;
  int * v3191 = v3188->regs;
  int v3192 = v3191[24];
  int * v3193 = v3188->regs;
  int v3194 = v3193[8];
  int * v3195 = v3188->regs;
  int v20700 = v3192 ^ v3194;
  v3195[24] = v20700;
  struct StateT * v20692 = v3197(v3188);
  return v20692;
}

struct StateT * v10315(struct StateT * v10316) {
  int v10317 = v10316->timer;
  int v17675 = v10317 + 1;
  v10316->timer = v17675;
  int * v10319 = v10316->regs;
  int v10320 = v10319[15];
  int * v10321 = v10316->regs;
  int v17679 = v10320 << 9;
  v10321[15] = v17679;
  struct StateT * v17673 = v10323(v10316);
  return v17673;
}

struct StateT * v12010(struct StateT * v12011) {
  int v12012 = v12011->timer;
  int v15821 = v12012 + 1;
  v12011->timer = v15821;
  int * v12014 = v12011->regs;
  int v12015 = v12014[26];
  int * v12016 = v12011->regs;
  int v12017 = v12016[7];
  int * v12018 = v12011->regs;
  int v15827 = v12015 + v12017;
  v12018[26] = v15827;
  struct StateT * v15819 = v12020(v12011);
  return v15819;
}

struct StateT * v9425(struct StateT * v9426) {
  int v9427 = v9426->timer;
  int v18691 = v9427 + 1;
  v9426->timer = v18691;
  int * v9429 = v9426->regs;
  int v9430 = v9429[17];
  int * v9431 = v9426->regs;
  int v18695 = v9430 << 7;
  v9431[17] = v18695;
  struct StateT * v18689 = v9433(v9426);
  return v18689;
}

struct StateT * v10829(struct StateT * v10830) {
  int v10831 = v10830->timer;
  int v17093 = v10831 + 1;
  v10830->timer = v17093;
  int * v10833 = v10830->regs;
  int v10834 = v10833[11];
  int * v10835 = v10830->regs;
  int v10836 = v10835[16];
  int * v10837 = v10830->regs;
  int v17100 = v10834 ^ v10836;
  v10837[20] = v17100;
  struct StateT * v17091 = v10839(v10830);
  return v17091;
}

struct StateT * v9565(struct StateT * v9566) {
  int v9567 = v9566->timer;
  int v18524 = v9567 + 1;
  v9566->timer = v18524;
  int * v9569 = v9566->regs;
  int v9570 = v9569[15];
  int * v9571 = v9566->regs;
  int v9572 = v9571[9];
  int * v9573 = v9566->regs;
  int v18530 = v9570 | v9572;
  v9573[15] = v18530;
  struct StateT * v18522 = v9575(v9566);
  return v18522;
}

struct StateT * v13656(struct StateT * v13657) {
  int v13658 = v13657->timer;
  int v14375 = v13658 + 1;
  v13657->timer = v14375;
  int * v13660 = v13657->regs;
  int v13661 = v13660[2];
  int * v13662 = v13657->cache_keys;
  int v13663 = v13662[0];
  bool v14380 = v13663 == ((int)((unsigned int)(v13661 + 68) >> 2));
  int v13711;
  if (v14380) {
    int * v13664 = v13657->cache_vals;
    int v13665 = v13664[0];
    v13711 = v13665;
  } else {
    int * v13667 = v13657->cache_keys;
    int v13668 = v13667[1];
    bool v14385 = v13668 == ((int)((unsigned int)(v13661 + 68) >> 2));
    int v13709;
    if (v14385) {
      int * v13669 = v13657->cache_vals;
      int v13670 = v13669[1];
      int * v13671 = v13657->cache_keys;
      int * v13672 = v13657->cache_keys;
      int v13673 = v13672[0];
      v13671[1] = v13673;
      int * v13675 = v13657->cache_vals;
      int * v13676 = v13657->cache_vals;
      int v13677 = v13676[0];
      v13675[1] = v13677;
      int * v13679 = v13657->cache_keys;
      int v14394 = (int)((unsigned int)(v13661 + 68) >> 2);
      v13679[0] = v14394;
      int * v13681 = v13657->cache_vals;
      v13681[0] = v13670;
      int v13683 = v13657->timer;
      int v14397 = v13683 + 1;
      v13657->timer = v14397;
      v13709 = v13670;
    } else {
      int * v13686 = v13657->mem;
      int v14399 = (int)((unsigned int)(v13661 + 68) >> 2);
      int v13687 = v13686[v14399];
      int * v13688 = v13657->mem;
      int * v13689 = v13657->cache_keys;
      int v13690 = v13689[1];
      int * v13691 = v13657->cache_vals;
      int v13692 = v13691[1];
      v13688[v13690] = v13692;
      int * v13694 = v13657->cache_keys;
      int * v13695 = v13657->cache_keys;
      int v13696 = v13695[0];
      v13694[1] = v13696;
      int * v13698 = v13657->cache_vals;
      int * v13699 = v13657->cache_vals;
      int v13700 = v13699[0];
      v13698[1] = v13700;
      int * v13702 = v13657->cache_keys;
      v13702[0] = v14399;
      int * v13704 = v13657->cache_vals;
      v13704[0] = v13687;
      int v13706 = v13657->timer;
      int v14414 = v13706 + 100;
      v13657->timer = v14414;
      v13709 = v13687;
    }
    v13711 = v13709;
  }
  int * v13712 = v13657->regs;
  v13712[21] = v13711;
  struct StateT * v14373 = v13714(v13657);
  return v14373;
}

struct StateT * v711(struct StateT * v712) {
  int v713 = v712->timer;
  int v23155 = v713 + 1;
  v712->timer = v23155;
  int * v715 = v712->regs;
  v715[30] = 0;
  struct StateT * v23153 = v717(v712);
  return v23153;
}

struct StateT * v2117(struct StateT * v2118) {
  int v2119 = v2118->timer;
  int v21908 = v2119 + 1;
  v2118->timer = v21908;
  int * v2121 = v2118->regs;
  int v2122 = v2121[18];
  int * v2123 = v2118->regs;
  int v21913 = (int)((unsigned int)v2122 >> 25);
  v2123[20] = v21913;
  struct StateT * v21906 = v2125(v2118);
  return v21906;
}

struct StateT * v8093(struct StateT * v8094) {
  int * v8095 = v8094->saved_regs;
  int * v8096 = v8094->regs;
  int v8097 = v8096[28];
  v8095[28] = v8097;
  int v8099 = v8094->timer;
  int v20123 = v8099 + 1;
  v8094->timer = v20123;
  int * v8101 = v8094->regs;
  int v8102 = v8101[27];
  int * v8103 = v8094->regs;
  int v8104 = v8103[28];
  int * v8105 = v8094->regs;
  int v20128 = v8102 + v8104;
  v8105[28] = v20128;
  struct StateT * v20117 = v8107(v8094);
  return v20117;
}

struct StateT * v10625(struct StateT * v10626) {
  int * v10627 = v10626->saved_regs;
  int * v10628 = v10626->regs;
  int v10629 = v10628[23];
  v10627[23] = v10629;
  int v10631 = v10626->timer;
  int v17324 = v10631 + 1;
  v10626->timer = v17324;
  int * v10633 = v10626->regs;
  int v10634 = v10633[23];
  int * v10635 = v10626->regs;
  int v10636 = v10635[8];
  int * v10637 = v10626->regs;
  int v17329 = v10634 ^ v10636;
  v10637[23] = v17329;
  struct StateT * v17318 = v10639(v10626);
  return v17318;
}

struct StateT * v2551(struct StateT * v2552) {
  int v2553 = v2552->timer;
  int v21421 = v2553 + 1;
  v2552->timer = v21421;
  int * v2555 = v2552->regs;
  int v2556 = v2555[18];
  int * v2557 = v2552->regs;
  int v21425 = v2556 << 13;
  v2557[18] = v21425;
  struct StateT * v21419 = v2559(v2552);
  return v21419;
}

struct StateT * v3853(struct StateT * v3854) {
  int v3855 = v3854->timer;
  int v7860 = v3855 + 1;
  v3854->timer = v7860;
  int * v3857 = v3854->regs;
  int v3858 = v3857[2];
  int * v3859 = v3854->cache_keys;
  int v3860 = v3859[0];
  bool v7865 = v3860 == ((int)((unsigned int)(v3858 + 16) >> 2));
  int v3908;
  if (v7865) {
    int * v3861 = v3854->cache_vals;
    int v3862 = v3861[0];
    v3908 = v3862;
  } else {
    int * v3864 = v3854->cache_keys;
    int v3865 = v3864[1];
    bool v7870 = v3865 == ((int)((unsigned int)(v3858 + 16) >> 2));
    int v3906;
    if (v7870) {
      int * v3866 = v3854->cache_vals;
      int v3867 = v3866[1];
      int * v3868 = v3854->cache_keys;
      int * v3869 = v3854->cache_keys;
      int v3870 = v3869[0];
      v3868[1] = v3870;
      int * v3872 = v3854->cache_vals;
      int * v3873 = v3854->cache_vals;
      int v3874 = v3873[0];
      v3872[1] = v3874;
      int * v3876 = v3854->cache_keys;
      int v7879 = (int)((unsigned int)(v3858 + 16) >> 2);
      v3876[0] = v7879;
      int * v3878 = v3854->cache_vals;
      v3878[0] = v3867;
      int v3880 = v3854->timer;
      int v7882 = v3880 + 1;
      v3854->timer = v7882;
      v3906 = v3867;
    } else {
      int * v3883 = v3854->mem;
      int v7884 = (int)((unsigned int)(v3858 + 16) >> 2);
      int v3884 = v3883[v7884];
      int * v3885 = v3854->mem;
      int * v3886 = v3854->cache_keys;
      int v3887 = v3886[1];
      int * v3888 = v3854->cache_vals;
      int v3889 = v3888[1];
      v3885[v3887] = v3889;
      int * v3891 = v3854->cache_keys;
      int * v3892 = v3854->cache_keys;
      int v3893 = v3892[0];
      v3891[1] = v3893;
      int * v3895 = v3854->cache_vals;
      int * v3896 = v3854->cache_vals;
      int v3897 = v3896[0];
      v3895[1] = v3897;
      int * v3899 = v3854->cache_keys;
      v3899[0] = v7884;
      int * v3901 = v3854->cache_vals;
      v3901[0] = v3884;
      int v3903 = v3854->timer;
      int v7899 = v3903 + 100;
      v3854->timer = v7899;
      v3906 = v3884;
    }
    v3908 = v3906;
  }
  int * v3909 = v3854->regs;
  v3909[7] = v3908;
  struct StateT * v7858 = v3911(v3854);
  return v7858;
}

struct StateT * v3003(struct StateT * v3004) {
  int v3005 = v3004->timer;
  int v20906 = v3005 + 1;
  v3004->timer = v20906;
  int * v3007 = v3004->regs;
  int v3008 = v3007[9];
  int * v3009 = v3004->regs;
  int v3010 = v3009[6];
  int * v3011 = v3004->regs;
  int v20913 = v3008 ^ v3010;
  v3011[16] = v20913;
  struct StateT * v20904 = v3013(v3004);
  return v20904;
}

struct StateT * v10123(struct StateT * v10124) {
  int v10125 = v10124->timer;
  int v17888 = v10125 + 1;
  v10124->timer = v17888;
  int * v10127 = v10124->regs;
  int v10128 = v10127[15];
  int * v10129 = v10124->regs;
  int v10130 = v10129[9];
  int * v10131 = v10124->regs;
  int v17894 = v10128 | v10130;
  v10131[15] = v17894;
  struct StateT * v17886 = v10133(v10124);
  return v17886;
}

struct StateT * v4521(struct StateT * v4522) {
  int v4523 = v4522->timer;
  int v7264 = v4523 + 1;
  v4522->timer = v7264;
  int * v4525 = v4522->regs;
  int v4526 = v4525[10];
  int * v4527 = v4522->regs;
  int v4528 = v4527[28];
  int * v4529 = v4522->cache_keys;
  int v4530 = v4529[0];
  bool v7271 = v4530 == ((int)((unsigned int)(v4526 + 8) >> 2));
  int v4574;
  if (v7271) {
    int * v4531 = v4522->cache_vals;
    v4531[0] = v4528;
    v4574 = v4528;
  } else {
    int * v4534 = v4522->cache_keys;
    int v4535 = v4534[1];
    bool v7276 = v4535 == ((int)((unsigned int)(v4526 + 8) >> 2));
    int v4572;
    if (v7276) {
      int * v4536 = v4522->cache_keys;
      int * v4537 = v4522->cache_keys;
      int v4538 = v4537[0];
      v4536[1] = v4538;
      int * v4540 = v4522->cache_vals;
      int * v4541 = v4522->cache_vals;
      int v4542 = v4541[0];
      v4540[1] = v4542;
      int * v4544 = v4522->cache_keys;
      int v7284 = (int)((unsigned int)(v4526 + 8) >> 2);
      v4544[0] = v7284;
      int * v4546 = v4522->cache_vals;
      v4546[0] = v4528;
      int v4548 = v4522->timer;
      int v7287 = v4548 + 1;
      v4522->timer = v7287;
      v4572 = v4528;
    } else {
      int * v4551 = v4522->mem;
      int * v4552 = v4522->cache_keys;
      int v4553 = v4552[1];
      int * v4554 = v4522->cache_vals;
      int v4555 = v4554[1];
      v4551[v4553] = v4555;
      int * v4557 = v4522->cache_keys;
      int * v4558 = v4522->cache_keys;
      int v4559 = v4558[0];
      v4557[1] = v4559;
      int * v4561 = v4522->cache_vals;
      int * v4562 = v4522->cache_vals;
      int v4563 = v4562[0];
      v4561[1] = v4563;
      int * v4565 = v4522->cache_keys;
      int v7300 = (int)((unsigned int)(v4526 + 8) >> 2);
      v4565[0] = v7300;
      int * v4567 = v4522->cache_vals;
      v4567[0] = v4528;
      int v4569 = v4522->timer;
      int v7303 = v4569 + 100;
      v4522->timer = v7303;
      v4572 = v4528;
    }
    v4574 = v4572;
  }
  struct StateT * v7262 = v4575(v4522);
  return v7262;
}

struct StateT * v8289(struct StateT * v8290) {
  int v8291 = v8290->timer;
  int v19908 = v8291 + 1;
  v8290->timer = v19908;
  int * v8293 = v8290->regs;
  int v8294 = v8293[2];
  int * v8295 = v8290->cache_keys;
  int v8296 = v8295[0];
  bool v19913 = v8296 == ((int)((unsigned int)(v8294 + 16) >> 2));
  int v8344;
  if (v19913) {
    int * v8297 = v8290->cache_vals;
    int v8298 = v8297[0];
    v8344 = v8298;
  } else {
    int * v8300 = v8290->cache_keys;
    int v8301 = v8300[1];
    bool v19918 = v8301 == ((int)((unsigned int)(v8294 + 16) >> 2));
    int v8342;
    if (v19918) {
      int * v8302 = v8290->cache_vals;
      int v8303 = v8302[1];
      int * v8304 = v8290->cache_keys;
      int * v8305 = v8290->cache_keys;
      int v8306 = v8305[0];
      v8304[1] = v8306;
      int * v8308 = v8290->cache_vals;
      int * v8309 = v8290->cache_vals;
      int v8310 = v8309[0];
      v8308[1] = v8310;
      int * v8312 = v8290->cache_keys;
      int v19927 = (int)((unsigned int)(v8294 + 16) >> 2);
      v8312[0] = v19927;
      int * v8314 = v8290->cache_vals;
      v8314[0] = v8303;
      int v8316 = v8290->timer;
      int v19930 = v8316 + 1;
      v8290->timer = v19930;
      v8342 = v8303;
    } else {
      int * v8319 = v8290->mem;
      int v19932 = (int)((unsigned int)(v8294 + 16) >> 2);
      int v8320 = v8319[v19932];
      int * v8321 = v8290->mem;
      int * v8322 = v8290->cache_keys;
      int v8323 = v8322[1];
      int * v8324 = v8290->cache_vals;
      int v8325 = v8324[1];
      v8321[v8323] = v8325;
      int * v8327 = v8290->cache_keys;
      int * v8328 = v8290->cache_keys;
      int v8329 = v8328[0];
      v8327[1] = v8329;
      int * v8331 = v8290->cache_vals;
      int * v8332 = v8290->cache_vals;
      int v8333 = v8332[0];
      v8331[1] = v8333;
      int * v8335 = v8290->cache_keys;
      v8335[0] = v19932;
      int * v8337 = v8290->cache_vals;
      v8337[0] = v8320;
      int v8339 = v8290->timer;
      int v19947 = v8339 + 100;
      v8290->timer = v19947;
      v8342 = v8320;
    }
    v8344 = v8342;
  }
  int * v8345 = v8290->regs;
  v8345[7] = v8344;
  struct StateT * v19906 = v8347(v8290);
  return v19906;
}

struct StateT * v9189(struct StateT * v9190) {
  int v9191 = v9190->timer;
  int v18964 = v9191 + 1;
  v9190->timer = v18964;
  int * v9193 = v9190->regs;
  int v9194 = v9193[16];
  int * v9195 = v9190->regs;
  int v18968 = v9194 << 18;
  v9195[16] = v18968;
  struct StateT * v18962 = v9197(v9190);
  return v18962;
}

struct StateT * v2151(struct StateT * v2152) {
  int v2153 = v2152->timer;
  int v21869 = v2153 + 1;
  v2152->timer = v21869;
  int * v2155 = v2152->regs;
  int v2156 = v2155[8];
  int * v2157 = v2152->regs;
  int v21873 = v2156 << 7;
  v2157[8] = v21873;
  struct StateT * v21867 = v2159(v2152);
  return v21867;
}

struct StateT * v10307(struct StateT * v10308) {
  int v10309 = v10308->timer;
  int v17684 = v10309 + 1;
  v10308->timer = v17684;
  int * v10311 = v10308->regs;
  int v10312 = v10311[15];
  int * v10313 = v10308->regs;
  int v17689 = (int)((unsigned int)v10312 >> 23);
  v10313[20] = v17689;
  struct StateT * v17682 = v10315(v10308);
  return v17682;
}

struct StateT * v3069(struct StateT * v3070) {
  int v3071 = v3070->timer;
  int v20828 = v3071 + 1;
  v3070->timer = v20828;
  int * v3073 = v3070->regs;
  int v3074 = v3073[11];
  int * v3075 = v3070->regs;
  int v3076 = v3075[9];
  int * v3077 = v3070->regs;
  int v20834 = v3074 | v3076;
  v3077[11] = v20834;
  struct StateT * v20826 = v3079(v3070);
  return v20826;
}

struct StateT * v9831(struct StateT * v9832) {
  int v9833 = v9832->timer;
  int v18219 = v9833 + 1;
  v9832->timer = v18219;
  int * v9835 = v9832->regs;
  int v9836 = v9835[13];
  int * v9837 = v9832->regs;
  int v9838 = v9837[6];
  int * v9839 = v9832->regs;
  int v18225 = v9836 ^ v9838;
  v9839[13] = v18225;
  struct StateT * v18217 = v9841(v9832);
  return v18217;
}

struct StateT * v11952(struct StateT * v11953) {
  int v11954 = v11953->timer;
  int v15832 = v11954 + 1;
  v11953->timer = v15832;
  int * v11956 = v11953->regs;
  int v11957 = v11956[2];
  int * v11958 = v11953->cache_keys;
  int v11959 = v11958[0];
  bool v15837 = v11959 == ((int)((unsigned int)(v11957 + 20) >> 2));
  int v12007;
  if (v15837) {
    int * v11960 = v11953->cache_vals;
    int v11961 = v11960[0];
    v12007 = v11961;
  } else {
    int * v11963 = v11953->cache_keys;
    int v11964 = v11963[1];
    bool v15842 = v11964 == ((int)((unsigned int)(v11957 + 20) >> 2));
    int v12005;
    if (v15842) {
      int * v11965 = v11953->cache_vals;
      int v11966 = v11965[1];
      int * v11967 = v11953->cache_keys;
      int * v11968 = v11953->cache_keys;
      int v11969 = v11968[0];
      v11967[1] = v11969;
      int * v11971 = v11953->cache_vals;
      int * v11972 = v11953->cache_vals;
      int v11973 = v11972[0];
      v11971[1] = v11973;
      int * v11975 = v11953->cache_keys;
      int v15851 = (int)((unsigned int)(v11957 + 20) >> 2);
      v11975[0] = v15851;
      int * v11977 = v11953->cache_vals;
      v11977[0] = v11966;
      int v11979 = v11953->timer;
      int v15854 = v11979 + 1;
      v11953->timer = v15854;
      v12005 = v11966;
    } else {
      int * v11982 = v11953->mem;
      int v15856 = (int)((unsigned int)(v11957 + 20) >> 2);
      int v11983 = v11982[v15856];
      int * v11984 = v11953->mem;
      int * v11985 = v11953->cache_keys;
      int v11986 = v11985[1];
      int * v11987 = v11953->cache_vals;
      int v11988 = v11987[1];
      v11984[v11986] = v11988;
      int * v11990 = v11953->cache_keys;
      int * v11991 = v11953->cache_keys;
      int v11992 = v11991[0];
      v11990[1] = v11992;
      int * v11994 = v11953->cache_vals;
      int * v11995 = v11953->cache_vals;
      int v11996 = v11995[0];
      v11994[1] = v11996;
      int * v11998 = v11953->cache_keys;
      v11998[0] = v15856;
      int * v12000 = v11953->cache_vals;
      v12000[0] = v11983;
      int v12002 = v11953->timer;
      int v15871 = v12002 + 100;
      v11953->timer = v15871;
      v12005 = v11983;
    }
    v12007 = v12005;
  }
  int * v12008 = v11953->regs;
  v12008[7] = v12007;
  struct StateT * v15830 = v12010(v11953);
  return v15830;
}

struct StateT * v11015(struct StateT * v11016) {
  int v11017 = v11016->timer;
  int v16882 = v11017 + 1;
  v11016->timer = v16882;
  int * v11019 = v11016->regs;
  int v11020 = v11019[23];
  int * v11021 = v11016->regs;
  int v11022 = v11021[15];
  int * v11023 = v11016->regs;
  int v16888 = v11020 ^ v11022;
  v11023[23] = v16888;
  struct StateT * v16880 = v11025(v11016);
  return v16880;
}

struct StateT * v8433(struct StateT * v8434) {
  int v8435 = v8434->timer;
  int v19784 = v8435 + 1;
  v8434->timer = v19784;
  int * v8437 = v8434->regs;
  int v8438 = v8437[2];
  int * v8439 = v8434->cache_keys;
  int v8440 = v8439[0];
  bool v19789 = v8440 == ((int)((unsigned int)(v8438 + 24) >> 2));
  int v8488;
  if (v19789) {
    int * v8441 = v8434->cache_vals;
    int v8442 = v8441[0];
    v8488 = v8442;
  } else {
    int * v8444 = v8434->cache_keys;
    int v8445 = v8444[1];
    bool v19794 = v8445 == ((int)((unsigned int)(v8438 + 24) >> 2));
    int v8486;
    if (v19794) {
      int * v8446 = v8434->cache_vals;
      int v8447 = v8446[1];
      int * v8448 = v8434->cache_keys;
      int * v8449 = v8434->cache_keys;
      int v8450 = v8449[0];
      v8448[1] = v8450;
      int * v8452 = v8434->cache_vals;
      int * v8453 = v8434->cache_vals;
      int v8454 = v8453[0];
      v8452[1] = v8454;
      int * v8456 = v8434->cache_keys;
      int v19803 = (int)((unsigned int)(v8438 + 24) >> 2);
      v8456[0] = v19803;
      int * v8458 = v8434->cache_vals;
      v8458[0] = v8447;
      int v8460 = v8434->timer;
      int v19806 = v8460 + 1;
      v8434->timer = v19806;
      v8486 = v8447;
    } else {
      int * v8463 = v8434->mem;
      int v19808 = (int)((unsigned int)(v8438 + 24) >> 2);
      int v8464 = v8463[v19808];
      int * v8465 = v8434->mem;
      int * v8466 = v8434->cache_keys;
      int v8467 = v8466[1];
      int * v8468 = v8434->cache_vals;
      int v8469 = v8468[1];
      v8465[v8467] = v8469;
      int * v8471 = v8434->cache_keys;
      int * v8472 = v8434->cache_keys;
      int v8473 = v8472[0];
      v8471[1] = v8473;
      int * v8475 = v8434->cache_vals;
      int * v8476 = v8434->cache_vals;
      int v8477 = v8476[0];
      v8475[1] = v8477;
      int * v8479 = v8434->cache_keys;
      v8479[0] = v19808;
      int * v8481 = v8434->cache_vals;
      v8481[0] = v8464;
      int v8483 = v8434->timer;
      int v19823 = v8483 + 100;
      v8434->timer = v19823;
      v8486 = v8464;
    }
    v8488 = v8486;
  }
  int * v8489 = v8434->regs;
  v8489[7] = v8488;
  struct StateT * v19782 = v8491(v8434);
  return v19782;
}

struct StateT * v2481(struct StateT * v2482) {
  int v2483 = v2482->timer;
  int v21500 = v2483 + 1;
  v2482->timer = v21500;
  int * v2485 = v2482->regs;
  int v2486 = v2485[15];
  int * v2487 = v2482->regs;
  int v2488 = v2487[20];
  int * v2489 = v2482->regs;
  int v21506 = v2486 | v2488;
  v2489[15] = v21506;
  struct StateT * v21498 = v2491(v2482);
  return v21498;
}

struct StateT * v13830(struct StateT * v13831) {
  int v13832 = v13831->timer;
  int v14231 = v13832 + 1;
  v13831->timer = v14231;
  int * v13834 = v13831->regs;
  int v13835 = v13834[2];
  int * v13836 = v13831->cache_keys;
  int v13837 = v13836[0];
  bool v14236 = v13837 == ((int)((unsigned int)(v13835 + 56) >> 2));
  int v13885;
  if (v14236) {
    int * v13838 = v13831->cache_vals;
    int v13839 = v13838[0];
    v13885 = v13839;
  } else {
    int * v13841 = v13831->cache_keys;
    int v13842 = v13841[1];
    bool v14241 = v13842 == ((int)((unsigned int)(v13835 + 56) >> 2));
    int v13883;
    if (v14241) {
      int * v13843 = v13831->cache_vals;
      int v13844 = v13843[1];
      int * v13845 = v13831->cache_keys;
      int * v13846 = v13831->cache_keys;
      int v13847 = v13846[0];
      v13845[1] = v13847;
      int * v13849 = v13831->cache_vals;
      int * v13850 = v13831->cache_vals;
      int v13851 = v13850[0];
      v13849[1] = v13851;
      int * v13853 = v13831->cache_keys;
      int v14250 = (int)((unsigned int)(v13835 + 56) >> 2);
      v13853[0] = v14250;
      int * v13855 = v13831->cache_vals;
      v13855[0] = v13844;
      int v13857 = v13831->timer;
      int v14253 = v13857 + 1;
      v13831->timer = v14253;
      v13883 = v13844;
    } else {
      int * v13860 = v13831->mem;
      int v14255 = (int)((unsigned int)(v13835 + 56) >> 2);
      int v13861 = v13860[v14255];
      int * v13862 = v13831->mem;
      int * v13863 = v13831->cache_keys;
      int v13864 = v13863[1];
      int * v13865 = v13831->cache_vals;
      int v13866 = v13865[1];
      v13862[v13864] = v13866;
      int * v13868 = v13831->cache_keys;
      int * v13869 = v13831->cache_keys;
      int v13870 = v13869[0];
      v13868[1] = v13870;
      int * v13872 = v13831->cache_vals;
      int * v13873 = v13831->cache_vals;
      int v13874 = v13873[0];
      v13872[1] = v13874;
      int * v13876 = v13831->cache_keys;
      v13876[0] = v14255;
      int * v13878 = v13831->cache_vals;
      v13878[0] = v13861;
      int v13880 = v13831->timer;
      int v14270 = v13880 + 100;
      v13831->timer = v14270;
      v13883 = v13861;
    }
    v13885 = v13883;
  }
  int * v13886 = v13831->regs;
  v13886[24] = v13885;
  struct StateT * v14229 = v13888(v13831);
  return v14229;
}

struct StateT * v11523(struct StateT * v11524) {
  int v11525 = v11524->timer;
  int v16295 = v11525 + 1;
  v11524->timer = v16295;
  int * v11527 = v11524->regs;
  int v11528 = v11527[6];
  int * v11529 = v11524->regs;
  int v16299 = v11528 << 18;
  v11529[6] = v16299;
  struct StateT * v16293 = v11531(v11524);
  return v16293;
}

struct StateT * v8511(struct StateT * v8512) {
  int * v8513 = v8512->regs;
  int v8514 = v8513[31];
  int * v8515 = v8512->regs;
  int v8516 = v8515[30];
  bool v19709 = (v8514 ^ -2147483648) >= (v8516 ^ -2147483648);
  struct StateT * v19703;
  if (v19709) {
    int v8517 = v8512->timer;
    int v19710 = v8517 + 15;
    v8512->timer = v19710;
    int * v8519 = v8512->saved_regs;
    int v8520 = v8519[29];
    int * v8521 = v8512->regs;
    v8521[29] = v8520;
    int * v8523 = v8512->saved_regs;
    int v8524 = v8523[28];
    int * v8525 = v8512->regs;
    v8525[28] = v8524;
    int * v8527 = v8512->saved_regs;
    int v8528 = v8527[15];
    int * v8529 = v8512->regs;
    v8529[15] = v8528;
    int * v8531 = v8512->saved_regs;
    int v8532 = v8531[14];
    int * v8533 = v8512->regs;
    v8533[14] = v8532;
    int * v8535 = v8512->saved_regs;
    int v8536 = v8535[6];
    int * v8537 = v8512->regs;
    v8537[6] = v8536;
    int * v8539 = v8512->saved_regs;
    int v8540 = v8539[12];
    int * v8541 = v8512->regs;
    v8541[12] = v8540;
    int * v8543 = v8512->saved_regs;
    int v8544 = v8543[7];
    int * v8545 = v8512->regs;
    v8545[7] = v8544;
    int * v8547 = v8512->saved_regs;
    int v8548 = v8547[5];
    int * v8549 = v8512->regs;
    v8549[5] = v8548;
    int * v8551 = v8512->saved_regs;
    int v8552 = v8551[25];
    int * v8553 = v8512->regs;
    v8553[25] = v8552;
    int * v8555 = v8512->saved_regs;
    int v8556 = v8555[26];
    int * v8557 = v8512->regs;
    v8557[26] = v8556;
    int * v8559 = v8512->saved_regs;
    int v8560 = v8559[13];
    int * v8561 = v8512->regs;
    v8561[13] = v8560;
    struct StateT * v19699 = v8563(v8512);
    v19703 = v19699;
  } else {
    struct StateT * v19701 = v12094(v8512);
    v19703 = v19701;
  }
  return v19703;
}

struct StateT * v3463(struct StateT * v3464) {
  int v3465 = v3464->timer;
  int v20374 = v3465 + 1;
  v3464->timer = v20374;
  int * v3467 = v3464->regs;
  int v3468 = v3467[15];
  int * v3469 = v3464->regs;
  int v3470 = v3469[9];
  int * v3471 = v3464->regs;
  int v20380 = v3468 | v3470;
  v3471[15] = v20380;
  struct StateT * v20372 = v3473(v3464);
  return v20372;
}

struct StateT * v11531(struct StateT * v11532) {
  int v11533 = v11532->timer;
  int v16284 = v11533 + 1;
  v11532->timer = v16284;
  int * v11535 = v11532->regs;
  int v11536 = v11535[6];
  int * v11537 = v11532->regs;
  int v11538 = v11537[9];
  int * v11539 = v11532->regs;
  int v16290 = v11536 | v11538;
  v11539[6] = v16290;
  struct StateT * v16282 = v11541(v11532);
  return v16282;
}

struct StateT * v12984(struct StateT * v12985) {
  int v12986 = v12985->timer;
  int v14935 = v12986 + 1;
  v12985->timer = v14935;
  int * v12988 = v12985->regs;
  int v12989 = v12988[10];
  int * v12990 = v12985->regs;
  int v12991 = v12990[7];
  int * v12992 = v12985->cache_keys;
  int v12993 = v12992[0];
  bool v14942 = v12993 == ((int)((unsigned int)(v12989 + 40) >> 2));
  int v13037;
  if (v14942) {
    int * v12994 = v12985->cache_vals;
    v12994[0] = v12991;
    v13037 = v12991;
  } else {
    int * v12997 = v12985->cache_keys;
    int v12998 = v12997[1];
    bool v14947 = v12998 == ((int)((unsigned int)(v12989 + 40) >> 2));
    int v13035;
    if (v14947) {
      int * v12999 = v12985->cache_keys;
      int * v13000 = v12985->cache_keys;
      int v13001 = v13000[0];
      v12999[1] = v13001;
      int * v13003 = v12985->cache_vals;
      int * v13004 = v12985->cache_vals;
      int v13005 = v13004[0];
      v13003[1] = v13005;
      int * v13007 = v12985->cache_keys;
      int v14955 = (int)((unsigned int)(v12989 + 40) >> 2);
      v13007[0] = v14955;
      int * v13009 = v12985->cache_vals;
      v13009[0] = v12991;
      int v13011 = v12985->timer;
      int v14958 = v13011 + 1;
      v12985->timer = v14958;
      v13035 = v12991;
    } else {
      int * v13014 = v12985->mem;
      int * v13015 = v12985->cache_keys;
      int v13016 = v13015[1];
      int * v13017 = v12985->cache_vals;
      int v13018 = v13017[1];
      v13014[v13016] = v13018;
      int * v13020 = v12985->cache_keys;
      int * v13021 = v12985->cache_keys;
      int v13022 = v13021[0];
      v13020[1] = v13022;
      int * v13024 = v12985->cache_vals;
      int * v13025 = v12985->cache_vals;
      int v13026 = v13025[0];
      v13024[1] = v13026;
      int * v13028 = v12985->cache_keys;
      int v14971 = (int)((unsigned int)(v12989 + 40) >> 2);
      v13028[0] = v14971;
      int * v13030 = v12985->cache_vals;
      v13030[0] = v12991;
      int v13032 = v12985->timer;
      int v14974 = v13032 + 100;
      v12985->timer = v14974;
      v13035 = v12991;
    }
    v13037 = v13035;
  }
  struct StateT * v14933 = v13038(v12985);
  return v14933;
}

struct StateT * v10719(struct StateT * v10720) {
  int v10721 = v10720->timer;
  int v17220 = v10721 + 1;
  v10720->timer = v17220;
  int * v10723 = v10720->regs;
  int v10724 = v10723[15];
  int * v10725 = v10720->regs;
  int v17224 = v10724 << 18;
  v10725[15] = v17224;
  struct StateT * v17218 = v10727(v10720);
  return v17218;
}

struct StateT * v5915(struct StateT * v5916) {
  int v5917 = v5916->timer;
  int v6104 = v5917 + 1;
  v5916->timer = v6104;
  int * v5919 = v5916->regs;
  int v5920 = v5919[2];
  int * v5921 = v5916->cache_keys;
  int v5922 = v5921[0];
  bool v6109 = v5922 == ((int)((unsigned int)(v5920 + 48) >> 2));
  int v5970;
  if (v6109) {
    int * v5923 = v5916->cache_vals;
    int v5924 = v5923[0];
    v5970 = v5924;
  } else {
    int * v5926 = v5916->cache_keys;
    int v5927 = v5926[1];
    bool v6114 = v5927 == ((int)((unsigned int)(v5920 + 48) >> 2));
    int v5968;
    if (v6114) {
      int * v5928 = v5916->cache_vals;
      int v5929 = v5928[1];
      int * v5930 = v5916->cache_keys;
      int * v5931 = v5916->cache_keys;
      int v5932 = v5931[0];
      v5930[1] = v5932;
      int * v5934 = v5916->cache_vals;
      int * v5935 = v5916->cache_vals;
      int v5936 = v5935[0];
      v5934[1] = v5936;
      int * v5938 = v5916->cache_keys;
      int v6123 = (int)((unsigned int)(v5920 + 48) >> 2);
      v5938[0] = v6123;
      int * v5940 = v5916->cache_vals;
      v5940[0] = v5929;
      int v5942 = v5916->timer;
      int v6126 = v5942 + 1;
      v5916->timer = v6126;
      v5968 = v5929;
    } else {
      int * v5945 = v5916->mem;
      int v6128 = (int)((unsigned int)(v5920 + 48) >> 2);
      int v5946 = v5945[v6128];
      int * v5947 = v5916->mem;
      int * v5948 = v5916->cache_keys;
      int v5949 = v5948[1];
      int * v5950 = v5916->cache_vals;
      int v5951 = v5950[1];
      v5947[v5949] = v5951;
      int * v5953 = v5916->cache_keys;
      int * v5954 = v5916->cache_keys;
      int v5955 = v5954[0];
      v5953[1] = v5955;
      int * v5957 = v5916->cache_vals;
      int * v5958 = v5916->cache_vals;
      int v5959 = v5958[0];
      v5957[1] = v5959;
      int * v5961 = v5916->cache_keys;
      v5961[0] = v6128;
      int * v5963 = v5916->cache_vals;
      v5963[0] = v5946;
      int v5965 = v5916->timer;
      int v6143 = v5965 + 100;
      v5916->timer = v6143;
      v5968 = v5946;
    }
    v5970 = v5968;
  }
  int * v5971 = v5916->regs;
  v5971[26] = v5970;
  struct StateT * v6102 = v5973(v5916);
  return v6102;
}

struct StateT * v12152(struct StateT * v12153) {
  int v12154 = v12153->timer;
  int v15695 = v12154 + 1;
  v12153->timer = v15695;
  int * v12156 = v12153->regs;
  int v12157 = v12156[17];
  int * v12158 = v12153->regs;
  int v12159 = v12158[30];
  int * v12160 = v12153->regs;
  int v15701 = v12157 + v12159;
  v12160[17] = v15701;
  struct StateT * v15693 = v12162(v12153);
  return v15693;
}

struct StateT * v9977(struct StateT * v9978) {
  int v9979 = v9978->timer;
  int v18051 = v9979 + 1;
  v9978->timer = v18051;
  int * v9981 = v9978->regs;
  int v9982 = v9981[8];
  int * v9983 = v9978->regs;
  int v18055 = v9982 << 18;
  v9983[8] = v18055;
  struct StateT * v18049 = v9985(v9978);
  return v18049;
}

struct StateT * v1355(struct StateT * v1356) {
  int v1357 = v1356->timer;
  int v22579 = v1357 + 1;
  v1356->timer = v22579;
  int * v1359 = v1356->regs;
  int v1360 = v1359[11];
  int * v1361 = v1356->cache_keys;
  int v1362 = v1361[0];
  bool v22584 = v1362 == ((int)((unsigned int)(v1360 + 12) >> 2));
  int v1410;
  if (v22584) {
    int * v1363 = v1356->cache_vals;
    int v1364 = v1363[0];
    v1410 = v1364;
  } else {
    int * v1366 = v1356->cache_keys;
    int v1367 = v1366[1];
    bool v22589 = v1367 == ((int)((unsigned int)(v1360 + 12) >> 2));
    int v1408;
    if (v22589) {
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
      int v22598 = (int)((unsigned int)(v1360 + 12) >> 2);
      v1378[0] = v22598;
      int * v1380 = v1356->cache_vals;
      v1380[0] = v1369;
      int v1382 = v1356->timer;
      int v22601 = v1382 + 1;
      v1356->timer = v22601;
      v1408 = v1369;
    } else {
      int * v1385 = v1356->mem;
      int v22603 = (int)((unsigned int)(v1360 + 12) >> 2);
      int v1386 = v1385[v22603];
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
      v1401[0] = v22603;
      int * v1403 = v1356->cache_vals;
      v1403[0] = v1386;
      int v1405 = v1356->timer;
      int v22618 = v1405 + 100;
      v1356->timer = v22618;
      v1408 = v1386;
    }
    v1410 = v1408;
  }
  int * v1411 = v1356->regs;
  v1411[15] = v1410;
  struct StateT * v22577 = v1413(v1356);
  return v22577;
}

struct StateT * v12606(struct StateT * v12607) {
  int v12608 = v12607->timer;
  int v15250 = v12608 + 1;
  v12607->timer = v15250;
  int * v12610 = v12607->regs;
  int v12611 = v12610[10];
  int * v12612 = v12607->regs;
  int v12613 = v12612[14];
  int * v12614 = v12607->cache_keys;
  int v12615 = v12614[0];
  bool v15257 = v12615 == ((int)((unsigned int)(v12611 + 12) >> 2));
  int v12659;
  if (v15257) {
    int * v12616 = v12607->cache_vals;
    v12616[0] = v12613;
    v12659 = v12613;
  } else {
    int * v12619 = v12607->cache_keys;
    int v12620 = v12619[1];
    bool v15262 = v12620 == ((int)((unsigned int)(v12611 + 12) >> 2));
    int v12657;
    if (v15262) {
      int * v12621 = v12607->cache_keys;
      int * v12622 = v12607->cache_keys;
      int v12623 = v12622[0];
      v12621[1] = v12623;
      int * v12625 = v12607->cache_vals;
      int * v12626 = v12607->cache_vals;
      int v12627 = v12626[0];
      v12625[1] = v12627;
      int * v12629 = v12607->cache_keys;
      int v15270 = (int)((unsigned int)(v12611 + 12) >> 2);
      v12629[0] = v15270;
      int * v12631 = v12607->cache_vals;
      v12631[0] = v12613;
      int v12633 = v12607->timer;
      int v15273 = v12633 + 1;
      v12607->timer = v15273;
      v12657 = v12613;
    } else {
      int * v12636 = v12607->mem;
      int * v12637 = v12607->cache_keys;
      int v12638 = v12637[1];
      int * v12639 = v12607->cache_vals;
      int v12640 = v12639[1];
      v12636[v12638] = v12640;
      int * v12642 = v12607->cache_keys;
      int * v12643 = v12607->cache_keys;
      int v12644 = v12643[0];
      v12642[1] = v12644;
      int * v12646 = v12607->cache_vals;
      int * v12647 = v12607->cache_vals;
      int v12648 = v12647[0];
      v12646[1] = v12648;
      int * v12650 = v12607->cache_keys;
      int v15286 = (int)((unsigned int)(v12611 + 12) >> 2);
      v12650[0] = v15286;
      int * v12652 = v12607->cache_vals;
      v12652[0] = v12613;
      int v12654 = v12607->timer;
      int v15289 = v12654 + 100;
      v12607->timer = v15289;
      v12657 = v12613;
    }
    v12659 = v12657;
  }
  struct StateT * v15248 = v12660(v12607);
  return v15248;
}

struct StateT * v10541(struct StateT * v10542) {
  int v10543 = v10542->timer;
  int v17421 = v10543 + 1;
  v10542->timer = v17421;
  int * v10545 = v10542->regs;
  int v10546 = v10545[8];
  int * v10547 = v10542->regs;
  int v17425 = v10546 << 13;
  v10547[8] = v17425;
  struct StateT * v17419 = v10549(v10542);
  return v17419;
}

struct StateT * snippet(struct StateT * v0) {
  struct StateT * v23754 = v1(v0);
  return v23754;
}

struct StateT * v3911(struct StateT * v3912) {
  int v3913 = v3912->timer;
  int v7849 = v3913 + 1;
  v3912->timer = v7849;
  int * v3915 = v3912->regs;
  int v3916 = v3915[25];
  int * v3917 = v3912->regs;
  int v3918 = v3917[7];
  int * v3919 = v3912->regs;
  int v7855 = v3916 + v3918;
  v3919[25] = v7855;
  struct StateT * v7847 = v3921(v3912);
  return v7847;
}

struct StateT * v13714(struct StateT * v13715) {
  int v13716 = v13715->timer;
  int v14327 = v13716 + 1;
  v13715->timer = v14327;
  int * v13718 = v13715->regs;
  int v13719 = v13718[2];
  int * v13720 = v13715->cache_keys;
  int v13721 = v13720[0];
  bool v14332 = v13721 == ((int)((unsigned int)(v13719 + 64) >> 2));
  int v13769;
  if (v14332) {
    int * v13722 = v13715->cache_vals;
    int v13723 = v13722[0];
    v13769 = v13723;
  } else {
    int * v13725 = v13715->cache_keys;
    int v13726 = v13725[1];
    bool v14337 = v13726 == ((int)((unsigned int)(v13719 + 64) >> 2));
    int v13767;
    if (v14337) {
      int * v13727 = v13715->cache_vals;
      int v13728 = v13727[1];
      int * v13729 = v13715->cache_keys;
      int * v13730 = v13715->cache_keys;
      int v13731 = v13730[0];
      v13729[1] = v13731;
      int * v13733 = v13715->cache_vals;
      int * v13734 = v13715->cache_vals;
      int v13735 = v13734[0];
      v13733[1] = v13735;
      int * v13737 = v13715->cache_keys;
      int v14346 = (int)((unsigned int)(v13719 + 64) >> 2);
      v13737[0] = v14346;
      int * v13739 = v13715->cache_vals;
      v13739[0] = v13728;
      int v13741 = v13715->timer;
      int v14349 = v13741 + 1;
      v13715->timer = v14349;
      v13767 = v13728;
    } else {
      int * v13744 = v13715->mem;
      int v14351 = (int)((unsigned int)(v13719 + 64) >> 2);
      int v13745 = v13744[v14351];
      int * v13746 = v13715->mem;
      int * v13747 = v13715->cache_keys;
      int v13748 = v13747[1];
      int * v13749 = v13715->cache_vals;
      int v13750 = v13749[1];
      v13746[v13748] = v13750;
      int * v13752 = v13715->cache_keys;
      int * v13753 = v13715->cache_keys;
      int v13754 = v13753[0];
      v13752[1] = v13754;
      int * v13756 = v13715->cache_vals;
      int * v13757 = v13715->cache_vals;
      int v13758 = v13757[0];
      v13756[1] = v13758;
      int * v13760 = v13715->cache_keys;
      v13760[0] = v14351;
      int * v13762 = v13715->cache_vals;
      v13762[0] = v13745;
      int v13764 = v13715->timer;
      int v14366 = v13764 + 100;
      v13715->timer = v14366;
      v13767 = v13745;
    }
    v13769 = v13767;
  }
  int * v13770 = v13715->regs;
  v13770[22] = v13769;
  struct StateT * v14325 = v13772(v13715);
  return v14325;
}

struct StateT * v2255(struct StateT * v2256) {
  int v2257 = v2256->timer;
  int v21754 = v2257 + 1;
  v2256->timer = v21754;
  int * v2259 = v2256->regs;
  int v2260 = v2259[14];
  int * v2261 = v2256->regs;
  int v2262 = v2261[22];
  int * v2263 = v2256->regs;
  int v21761 = v2260 + v2262;
  v2263[18] = v21761;
  struct StateT * v21752 = v2265(v2256);
  return v21752;
}

struct StateT * v1(struct StateT * v2) {
  int v3 = v2->timer;
  int v23747 = v3 + 1;
  v2->timer = v23747;
  int * v5 = v2->regs;
  int v6 = v5[2];
  int * v7 = v2->regs;
  int v23751 = v6 + -96;
  v7[2] = v23751;
  struct StateT * v23745 = v9(v2);
  return v23745;
}

struct StateT * v11732(struct StateT * v11733) {
  int v11734 = v11733->timer;
  int v16065 = v11734 + 1;
  v11733->timer = v16065;
  int * v11736 = v11733->regs;
  int v11737 = v11736[14];
  int * v11738 = v11733->regs;
  int v11739 = v11738[7];
  int * v11740 = v11733->regs;
  int v16071 = v11737 + v11739;
  v11740[14] = v16071;
  struct StateT * v16063 = v11742(v11733);
  return v16063;
}

struct StateT * v8795(struct StateT * v8796) {
  int v8797 = v8796->timer;
  int v19422 = v8797 + 1;
  v8796->timer = v19422;
  int * v8799 = v8796->regs;
  int v8800 = v8799[15];
  int * v8801 = v8796->regs;
  int v19426 = v8800 << 9;
  v8801[15] = v19426;
  struct StateT * v19420 = v8803(v8796);
  return v19420;
}

struct StateT * v3079(struct StateT * v3080) {
  int v3081 = v3080->timer;
  int v20818 = v3081 + 1;
  v3080->timer = v20818;
  int * v3083 = v3080->regs;
  int v3084 = v3083[15];
  int * v3085 = v3080->regs;
  int v20823 = (int)((unsigned int)v3084 >> 23);
  v3085[9] = v20823;
  struct StateT * v20816 = v3087(v3080);
  return v20816;
}

struct StateT * v8347(struct StateT * v8348) {
  int * v8349 = v8348->saved_regs;
  int * v8350 = v8348->regs;
  int v8351 = v8350[25];
  v8349[25] = v8351;
  int v8353 = v8348->timer;
  int v19898 = v8353 + 1;
  v8348->timer = v19898;
  int * v8355 = v8348->regs;
  int v8356 = v8355[25];
  int * v8357 = v8348->regs;
  int v8358 = v8357[7];
  int * v8359 = v8348->regs;
  int v19903 = v8356 + v8358;
  v8359[25] = v19903;
  struct StateT * v19892 = v8361(v8348);
  return v19892;
}

struct StateT * v5223(struct StateT * v5224) {
  int v5225 = v5224->timer;
  int v6680 = v5225 + 1;
  v5224->timer = v6680;
  int * v5227 = v5224->regs;
  int v5228 = v5227[10];
  int * v5229 = v5224->regs;
  int v5230 = v5229[30];
  int * v5231 = v5224->cache_keys;
  int v5232 = v5231[0];
  bool v6687 = v5232 == ((int)((unsigned int)(v5228 + 60) >> 2));
  int v5276;
  if (v6687) {
    int * v5233 = v5224->cache_vals;
    v5233[0] = v5230;
    v5276 = v5230;
  } else {
    int * v5236 = v5224->cache_keys;
    int v5237 = v5236[1];
    bool v6692 = v5237 == ((int)((unsigned int)(v5228 + 60) >> 2));
    int v5274;
    if (v6692) {
      int * v5238 = v5224->cache_keys;
      int * v5239 = v5224->cache_keys;
      int v5240 = v5239[0];
      v5238[1] = v5240;
      int * v5242 = v5224->cache_vals;
      int * v5243 = v5224->cache_vals;
      int v5244 = v5243[0];
      v5242[1] = v5244;
      int * v5246 = v5224->cache_keys;
      int v6700 = (int)((unsigned int)(v5228 + 60) >> 2);
      v5246[0] = v6700;
      int * v5248 = v5224->cache_vals;
      v5248[0] = v5230;
      int v5250 = v5224->timer;
      int v6703 = v5250 + 1;
      v5224->timer = v6703;
      v5274 = v5230;
    } else {
      int * v5253 = v5224->mem;
      int * v5254 = v5224->cache_keys;
      int v5255 = v5254[1];
      int * v5256 = v5224->cache_vals;
      int v5257 = v5256[1];
      v5253[v5255] = v5257;
      int * v5259 = v5224->cache_keys;
      int * v5260 = v5224->cache_keys;
      int v5261 = v5260[0];
      v5259[1] = v5261;
      int * v5263 = v5224->cache_vals;
      int * v5264 = v5224->cache_vals;
      int v5265 = v5264[0];
      v5263[1] = v5265;
      int * v5267 = v5224->cache_keys;
      int v6716 = (int)((unsigned int)(v5228 + 60) >> 2);
      v5267[0] = v6716;
      int * v5269 = v5224->cache_vals;
      v5269[0] = v5230;
      int v5271 = v5224->timer;
      int v6719 = v5271 + 100;
      v5224->timer = v6719;
      v5274 = v5230;
    }
    v5276 = v5274;
  }
  struct StateT * v6678 = v5277(v5224);
  return v6678;
}

struct StateT * v2333(struct StateT * v2334) {
  int v2335 = v2334->timer;
  int v21664 = v2335 + 1;
  v2334->timer = v21664;
  int * v2337 = v2334->regs;
  int v2338 = v2337[9];
  int * v2339 = v2334->regs;
  int v2340 = v2339[20];
  int * v2341 = v2334->regs;
  int v21670 = v2338 | v2340;
  v2341[9] = v21670;
  struct StateT * v21662 = v2343(v2334);
  return v21662;
}

struct StateT * v11365(struct StateT * v11366) {
  int v11367 = v11366->timer;
  int v16477 = v11367 + 1;
  v11366->timer = v16477;
  int * v11369 = v11366->regs;
  int v11370 = v11369[8];
  int * v11371 = v11366->regs;
  int v16481 = v11370 << 13;
  v11371[8] = v16481;
  struct StateT * v16475 = v11373(v11366);
  return v16475;
}

struct StateT * v12930(struct StateT * v12931) {
  int v12932 = v12931->timer;
  int v14980 = v12932 + 1;
  v12931->timer = v14980;
  int * v12934 = v12931->regs;
  int v12935 = v12934[10];
  int * v12936 = v12931->regs;
  int v12937 = v12936[13];
  int * v12938 = v12931->cache_keys;
  int v12939 = v12938[0];
  bool v14987 = v12939 == ((int)((unsigned int)(v12935 + 36) >> 2));
  int v12983;
  if (v14987) {
    int * v12940 = v12931->cache_vals;
    v12940[0] = v12937;
    v12983 = v12937;
  } else {
    int * v12943 = v12931->cache_keys;
    int v12944 = v12943[1];
    bool v14992 = v12944 == ((int)((unsigned int)(v12935 + 36) >> 2));
    int v12981;
    if (v14992) {
      int * v12945 = v12931->cache_keys;
      int * v12946 = v12931->cache_keys;
      int v12947 = v12946[0];
      v12945[1] = v12947;
      int * v12949 = v12931->cache_vals;
      int * v12950 = v12931->cache_vals;
      int v12951 = v12950[0];
      v12949[1] = v12951;
      int * v12953 = v12931->cache_keys;
      int v15000 = (int)((unsigned int)(v12935 + 36) >> 2);
      v12953[0] = v15000;
      int * v12955 = v12931->cache_vals;
      v12955[0] = v12937;
      int v12957 = v12931->timer;
      int v15003 = v12957 + 1;
      v12931->timer = v15003;
      v12981 = v12937;
    } else {
      int * v12960 = v12931->mem;
      int * v12961 = v12931->cache_keys;
      int v12962 = v12961[1];
      int * v12963 = v12931->cache_vals;
      int v12964 = v12963[1];
      v12960[v12962] = v12964;
      int * v12966 = v12931->cache_keys;
      int * v12967 = v12931->cache_keys;
      int v12968 = v12967[0];
      v12966[1] = v12968;
      int * v12970 = v12931->cache_vals;
      int * v12971 = v12931->cache_vals;
      int v12972 = v12971[0];
      v12970[1] = v12972;
      int * v12974 = v12931->cache_keys;
      int v15016 = (int)((unsigned int)(v12935 + 36) >> 2);
      v12974[0] = v15016;
      int * v12976 = v12931->cache_vals;
      v12976[0] = v12937;
      int v12978 = v12931->timer;
      int v15019 = v12978 + 100;
      v12931->timer = v15019;
      v12981 = v12937;
    }
    v12983 = v12981;
  }
  struct StateT * v14978 = v12984(v12931);
  return v14978;
}

struct StateT * v8839(struct StateT * v8840) {
  int v8841 = v8840->timer;
  int v19371 = v8841 + 1;
  v8840->timer = v19371;
  int * v8843 = v8840->regs;
  int v8844 = v8843[9];
  int * v8845 = v8840->regs;
  int v19376 = (int)((unsigned int)v8844 >> 23);
  v8845[20] = v19376;
  struct StateT * v19369 = v8847(v8840);
  return v19369;
}

struct StateT * v2455(struct StateT * v2456) {
  int v2457 = v2456->timer;
  int v21530 = v2457 + 1;
  v2456->timer = v21530;
  int * v2459 = v2456->regs;
  int v2460 = v2459[25];
  int * v2461 = v2456->regs;
  int v2462 = v2461[14];
  int * v2463 = v2456->regs;
  int v21537 = v2460 + v2462;
  v2463[18] = v21537;
  struct StateT * v21528 = v2465(v2456);
  return v21528;
}

struct StateT * v5061(struct StateT * v5062) {
  int v5063 = v5062->timer;
  int v6814 = v5063 + 1;
  v5062->timer = v6814;
  int * v5065 = v5062->regs;
  int v5066 = v5065[10];
  int * v5067 = v5062->regs;
  int v5068 = v5067[16];
  int * v5069 = v5062->cache_keys;
  int v5070 = v5069[0];
  bool v6821 = v5070 == ((int)((unsigned int)(v5066 + 48) >> 2));
  int v5114;
  if (v6821) {
    int * v5071 = v5062->cache_vals;
    v5071[0] = v5068;
    v5114 = v5068;
  } else {
    int * v5074 = v5062->cache_keys;
    int v5075 = v5074[1];
    bool v6826 = v5075 == ((int)((unsigned int)(v5066 + 48) >> 2));
    int v5112;
    if (v6826) {
      int * v5076 = v5062->cache_keys;
      int * v5077 = v5062->cache_keys;
      int v5078 = v5077[0];
      v5076[1] = v5078;
      int * v5080 = v5062->cache_vals;
      int * v5081 = v5062->cache_vals;
      int v5082 = v5081[0];
      v5080[1] = v5082;
      int * v5084 = v5062->cache_keys;
      int v6834 = (int)((unsigned int)(v5066 + 48) >> 2);
      v5084[0] = v6834;
      int * v5086 = v5062->cache_vals;
      v5086[0] = v5068;
      int v5088 = v5062->timer;
      int v6837 = v5088 + 1;
      v5062->timer = v6837;
      v5112 = v5068;
    } else {
      int * v5091 = v5062->mem;
      int * v5092 = v5062->cache_keys;
      int v5093 = v5092[1];
      int * v5094 = v5062->cache_vals;
      int v5095 = v5094[1];
      v5091[v5093] = v5095;
      int * v5097 = v5062->cache_keys;
      int * v5098 = v5062->cache_keys;
      int v5099 = v5098[0];
      v5097[1] = v5099;
      int * v5101 = v5062->cache_vals;
      int * v5102 = v5062->cache_vals;
      int v5103 = v5102[0];
      v5101[1] = v5103;
      int * v5105 = v5062->cache_keys;
      int v6850 = (int)((unsigned int)(v5066 + 48) >> 2);
      v5105[0] = v6850;
      int * v5107 = v5062->cache_vals;
      v5107[0] = v5068;
      int v5109 = v5062->timer;
      int v6853 = v5109 + 100;
      v5062->timer = v6853;
      v5112 = v5068;
    }
    v5114 = v5112;
  }
  struct StateT * v6812 = v5115(v5062);
  return v6812;
}

struct StateT * v10853(struct StateT * v10854) {
  int * v10855 = v10854->saved_regs;
  int * v10856 = v10854->regs;
  int v10857 = v10856[22];
  v10855[22] = v10857;
  int v10859 = v10854->timer;
  int v17069 = v10859 + 1;
  v10854->timer = v17069;
  int * v10861 = v10854->regs;
  int v10862 = v10861[22];
  int * v10863 = v10854->regs;
  int v10864 = v10863[5];
  int * v10865 = v10854->regs;
  int v17074 = v10862 ^ v10864;
  v10865[22] = v17074;
  struct StateT * v17063 = v10867(v10854);
  return v17063;
}

struct StateT * v3429(struct StateT * v3430) {
  int v3431 = v3430->timer;
  int v20415 = v3431 + 1;
  v3430->timer = v20415;
  int * v3433 = v3430->regs;
  int v3434 = v3433[11];
  int * v3435 = v3430->regs;
  int v20419 = v3434 << 18;
  v3435[11] = v20419;
  struct StateT * v20413 = v3437(v3430);
  return v20413;
}

struct StateT * v8707(struct StateT * v8708) {
  int v8709 = v8708->timer;
  int v19522 = v8709 + 1;
  v8708->timer = v19522;
  int * v8711 = v8708->regs;
  int v8712 = v8711[12];
  int * v8713 = v8708->regs;
  int v8714 = v8713[15];
  int * v8715 = v8708->regs;
  int v19528 = v8712 ^ v8714;
  v8715[12] = v19528;
  struct StateT * v19520 = v8717(v8708);
  return v19520;
}

struct StateT * v8671(struct StateT * v8672) {
  int v8673 = v8672->timer;
  int v19563 = v8673 + 1;
  v8672->timer = v19563;
  int * v8675 = v8672->regs;
  int v8676 = v8675[18];
  int * v8677 = v8672->regs;
  int v8678 = v8677[20];
  int * v8679 = v8672->regs;
  int v19569 = v8676 | v8678;
  v8679[18] = v19569;
  struct StateT * v19561 = v8681(v8672);
  return v19561;
}

struct StateT * v12444(struct StateT * v12445) {
  int v12446 = v12445->timer;
  int v15385 = v12446 + 1;
  v12445->timer = v15385;
  int * v12448 = v12445->regs;
  int v12449 = v12448[10];
  int * v12450 = v12445->regs;
  int v12451 = v12450[15];
  int * v12452 = v12445->cache_keys;
  int v12453 = v12452[0];
  bool v15392 = v12453 == ((int)((unsigned int)v12449 >> 2));
  int v12497;
  if (v15392) {
    int * v12454 = v12445->cache_vals;
    v12454[0] = v12451;
    v12497 = v12451;
  } else {
    int * v12457 = v12445->cache_keys;
    int v12458 = v12457[1];
    bool v15397 = v12458 == ((int)((unsigned int)v12449 >> 2));
    int v12495;
    if (v15397) {
      int * v12459 = v12445->cache_keys;
      int * v12460 = v12445->cache_keys;
      int v12461 = v12460[0];
      v12459[1] = v12461;
      int * v12463 = v12445->cache_vals;
      int * v12464 = v12445->cache_vals;
      int v12465 = v12464[0];
      v12463[1] = v12465;
      int * v12467 = v12445->cache_keys;
      int v15405 = (int)((unsigned int)v12449 >> 2);
      v12467[0] = v15405;
      int * v12469 = v12445->cache_vals;
      v12469[0] = v12451;
      int v12471 = v12445->timer;
      int v15408 = v12471 + 1;
      v12445->timer = v15408;
      v12495 = v12451;
    } else {
      int * v12474 = v12445->mem;
      int * v12475 = v12445->cache_keys;
      int v12476 = v12475[1];
      int * v12477 = v12445->cache_vals;
      int v12478 = v12477[1];
      v12474[v12476] = v12478;
      int * v12480 = v12445->cache_keys;
      int * v12481 = v12445->cache_keys;
      int v12482 = v12481[0];
      v12480[1] = v12482;
      int * v12484 = v12445->cache_vals;
      int * v12485 = v12445->cache_vals;
      int v12486 = v12485[0];
      v12484[1] = v12486;
      int * v12488 = v12445->cache_keys;
      int v15421 = (int)((unsigned int)v12449 >> 2);
      v12488[0] = v15421;
      int * v12490 = v12445->cache_vals;
      v12490[0] = v12451;
      int v12492 = v12445->timer;
      int v15424 = v12492 + 100;
      v12445->timer = v15424;
      v12495 = v12451;
    }
    v12497 = v12495;
  }
  struct StateT * v15383 = v12498(v12445);
  return v15383;
}

struct StateT * v9523(struct StateT * v9524) {
  int v9525 = v9524->timer;
  int v18574 = v9525 + 1;
  v9524->timer = v18574;
  int * v9527 = v9524->regs;
  int v9528 = v9527[11];
  int * v9529 = v9524->regs;
  int v18579 = (int)((unsigned int)v9528 >> 23);
  v9529[9] = v18579;
  struct StateT * v18572 = v9531(v9524);
  return v18572;
}

struct StateT * v2325(struct StateT * v2326) {
  int v2327 = v2326->timer;
  int v21675 = v2327 + 1;
  v2326->timer = v21675;
  int * v2329 = v2326->regs;
  int v2330 = v2329[9];
  int * v2331 = v2326->regs;
  int v21679 = v2330 << 9;
  v2331[9] = v21679;
  struct StateT * v21673 = v2333(v2326);
  return v21673;
}

struct StateT * v3087(struct StateT * v3088) {
  int v3089 = v3088->timer;
  int v20809 = v3089 + 1;
  v3088->timer = v20809;
  int * v3091 = v3088->regs;
  int v3092 = v3091[15];
  int * v3093 = v3088->regs;
  int v20813 = v3092 << 9;
  v3093[15] = v20813;
  struct StateT * v20807 = v3095(v3088);
  return v20807;
}

struct StateT * v2507(struct StateT * v2508) {
  int v2509 = v2508->timer;
  int v21470 = v2509 + 1;
  v2508->timer = v21470;
  int * v2511 = v2508->regs;
  int v2512 = v2511[8];
  int * v2513 = v2508->regs;
  int v2514 = v2513[20];
  int * v2515 = v2508->regs;
  int v21476 = v2512 | v2514;
  v2515[8] = v21476;
  struct StateT * v21468 = v2517(v2508);
  return v21468;
}

struct StateT * v9609(struct StateT * v9610) {
  int v9611 = v9610->timer;
  int v18475 = v9611 + 1;
  v9610->timer = v18475;
  int * v9613 = v9610->regs;
  int v9614 = v9613[8];
  int * v9615 = v9610->regs;
  int v18479 = v9614 << 9;
  v9615[8] = v18479;
  struct StateT * v18473 = v9617(v9610);
  return v18473;
}

struct StateT * v3785(struct StateT * v3786) {
  int v3787 = v3786->timer;
  int v7919 = v3787 + 1;
  v3786->timer = v7919;
  int * v3789 = v3786->regs;
  int v3790 = v3789[2];
  int * v3791 = v3786->cache_keys;
  int v3792 = v3791[0];
  bool v7924 = v3792 == ((int)((unsigned int)(v3790 + 12) >> 2));
  int v3840;
  if (v7924) {
    int * v3793 = v3786->cache_vals;
    int v3794 = v3793[0];
    v3840 = v3794;
  } else {
    int * v3796 = v3786->cache_keys;
    int v3797 = v3796[1];
    bool v7929 = v3797 == ((int)((unsigned int)(v3790 + 12) >> 2));
    int v3838;
    if (v7929) {
      int * v3798 = v3786->cache_vals;
      int v3799 = v3798[1];
      int * v3800 = v3786->cache_keys;
      int * v3801 = v3786->cache_keys;
      int v3802 = v3801[0];
      v3800[1] = v3802;
      int * v3804 = v3786->cache_vals;
      int * v3805 = v3786->cache_vals;
      int v3806 = v3805[0];
      v3804[1] = v3806;
      int * v3808 = v3786->cache_keys;
      int v7938 = (int)((unsigned int)(v3790 + 12) >> 2);
      v3808[0] = v7938;
      int * v3810 = v3786->cache_vals;
      v3810[0] = v3799;
      int v3812 = v3786->timer;
      int v7941 = v3812 + 1;
      v3786->timer = v7941;
      v3838 = v3799;
    } else {
      int * v3815 = v3786->mem;
      int v7943 = (int)((unsigned int)(v3790 + 12) >> 2);
      int v3816 = v3815[v7943];
      int * v3817 = v3786->mem;
      int * v3818 = v3786->cache_keys;
      int v3819 = v3818[1];
      int * v3820 = v3786->cache_vals;
      int v3821 = v3820[1];
      v3817[v3819] = v3821;
      int * v3823 = v3786->cache_keys;
      int * v3824 = v3786->cache_keys;
      int v3825 = v3824[0];
      v3823[1] = v3825;
      int * v3827 = v3786->cache_vals;
      int * v3828 = v3786->cache_vals;
      int v3829 = v3828[0];
      v3827[1] = v3829;
      int * v3831 = v3786->cache_keys;
      v3831[0] = v7943;
      int * v3833 = v3786->cache_vals;
      v3833[0] = v3816;
      int v3835 = v3786->timer;
      int v7958 = v3835 + 100;
      v3786->timer = v7958;
      v3838 = v3816;
    }
    v3840 = v3838;
  }
  int * v3841 = v3786->regs;
  v3841[7] = v3840;
  struct StateT * v7917 = v3843(v3786);
  return v7917;
}

struct StateT * v10225(struct StateT * v10226) {
  int * v10227 = v10226->saved_regs;
  int * v10228 = v10226->regs;
  int v10229 = v10228[13];
  v10227[13] = v10229;
  int v10231 = v10226->timer;
  int v17774 = v10231 + 1;
  v10226->timer = v17774;
  int * v10233 = v10226->regs;
  int v10234 = v10233[13];
  int * v10235 = v10226->regs;
  int v10236 = v10235[9];
  int * v10237 = v10226->regs;
  int v17779 = v10234 ^ v10236;
  v10237[13] = v17779;
  struct StateT * v17768 = v10239(v10226);
  return v17768;
}

struct StateT * v9907(struct StateT * v9908) {
  int v9909 = v9908->timer;
  int v18130 = v9909 + 1;
  v9908->timer = v18130;
  int * v9911 = v9908->regs;
  int v9912 = v9911[11];
  int * v9913 = v9908->regs;
  int v9914 = v9913[9];
  int * v9915 = v9908->regs;
  int v18136 = v9912 | v9914;
  v9915[11] = v18136;
  struct StateT * v18128 = v9917(v9908);
  return v18128;
}

struct StateT * v2525(struct StateT * v2526) {
  int v2527 = v2526->timer;
  int v21451 = v2527 + 1;
  v2526->timer = v21451;
  int * v2529 = v2526->regs;
  int v2530 = v2529[9];
  int * v2531 = v2526->regs;
  int v21455 = v2530 << 13;
  v2531[9] = v21455;
  struct StateT * v21449 = v2533(v2526);
  return v21449;
}

struct StateT * v2895(struct StateT * v2896) {
  int v2897 = v2896->timer;
  int v21034 = v2897 + 1;
  v2896->timer = v21034;
  int * v2899 = v2896->regs;
  int v2900 = v2899[11];
  int * v2901 = v2896->regs;
  int v21039 = (int)((unsigned int)v2900 >> 25);
  v2901[5] = v21039;
  struct StateT * v21032 = v2903(v2896);
  return v21032;
}

struct StateT * v3227(struct StateT * v3228) {
  int v3229 = v3228->timer;
  int v20646 = v3229 + 1;
  v3228->timer = v20646;
  int * v3231 = v3228->regs;
  int v3232 = v3231[24];
  int * v3233 = v3228->regs;
  int v3234 = v3233[16];
  int * v3235 = v3228->regs;
  int v20653 = v3232 + v3234;
  v3235[8] = v20653;
  struct StateT * v20644 = v3237(v3228);
  return v20644;
}

struct StateT * v2755(struct StateT * v2756) {
  int v2757 = v2756->timer;
  int v21190 = v2757 + 1;
  v2756->timer = v21190;
  int * v2759 = v2756->regs;
  int v2760 = v2759[5];
  int * v2761 = v2756->regs;
  int v21194 = v2760 << 18;
  v2761[5] = v21194;
  struct StateT * v21188 = v2763(v2756);
  return v21188;
}

struct StateT * v3921(struct StateT * v3922) {
  int v3923 = v3922->timer;
  int v7801 = v3923 + 1;
  v3922->timer = v7801;
  int * v3925 = v3922->regs;
  int v3926 = v3925[2];
  int * v3927 = v3922->cache_keys;
  int v3928 = v3927[0];
  bool v7806 = v3928 == ((int)((unsigned int)(v3926 + 20) >> 2));
  int v3976;
  if (v7806) {
    int * v3929 = v3922->cache_vals;
    int v3930 = v3929[0];
    v3976 = v3930;
  } else {
    int * v3932 = v3922->cache_keys;
    int v3933 = v3932[1];
    bool v7811 = v3933 == ((int)((unsigned int)(v3926 + 20) >> 2));
    int v3974;
    if (v7811) {
      int * v3934 = v3922->cache_vals;
      int v3935 = v3934[1];
      int * v3936 = v3922->cache_keys;
      int * v3937 = v3922->cache_keys;
      int v3938 = v3937[0];
      v3936[1] = v3938;
      int * v3940 = v3922->cache_vals;
      int * v3941 = v3922->cache_vals;
      int v3942 = v3941[0];
      v3940[1] = v3942;
      int * v3944 = v3922->cache_keys;
      int v7820 = (int)((unsigned int)(v3926 + 20) >> 2);
      v3944[0] = v7820;
      int * v3946 = v3922->cache_vals;
      v3946[0] = v3935;
      int v3948 = v3922->timer;
      int v7823 = v3948 + 1;
      v3922->timer = v7823;
      v3974 = v3935;
    } else {
      int * v3951 = v3922->mem;
      int v7825 = (int)((unsigned int)(v3926 + 20) >> 2);
      int v3952 = v3951[v7825];
      int * v3953 = v3922->mem;
      int * v3954 = v3922->cache_keys;
      int v3955 = v3954[1];
      int * v3956 = v3922->cache_vals;
      int v3957 = v3956[1];
      v3953[v3955] = v3957;
      int * v3959 = v3922->cache_keys;
      int * v3960 = v3922->cache_keys;
      int v3961 = v3960[0];
      v3959[1] = v3961;
      int * v3963 = v3922->cache_vals;
      int * v3964 = v3922->cache_vals;
      int v3965 = v3964[0];
      v3963[1] = v3965;
      int * v3967 = v3922->cache_keys;
      v3967[0] = v7825;
      int * v3969 = v3922->cache_vals;
      v3969[0] = v3952;
      int v3971 = v3922->timer;
      int v7840 = v3971 + 100;
      v3922->timer = v7840;
      v3974 = v3952;
    }
    v3976 = v3974;
  }
  int * v3977 = v3922->regs;
  v3977[7] = v3976;
  struct StateT * v7799 = v3979(v3922);
  return v7799;
}

struct StateT * v4791(struct StateT * v4792) {
  int v4793 = v4792->timer;
  int v7039 = v4793 + 1;
  v4792->timer = v7039;
  int * v4795 = v4792->regs;
  int v4796 = v4795[10];
  int * v4797 = v4792->regs;
  int v4798 = v4797[25];
  int * v4799 = v4792->cache_keys;
  int v4800 = v4799[0];
  bool v7046 = v4800 == ((int)((unsigned int)(v4796 + 28) >> 2));
  int v4844;
  if (v7046) {
    int * v4801 = v4792->cache_vals;
    v4801[0] = v4798;
    v4844 = v4798;
  } else {
    int * v4804 = v4792->cache_keys;
    int v4805 = v4804[1];
    bool v7051 = v4805 == ((int)((unsigned int)(v4796 + 28) >> 2));
    int v4842;
    if (v7051) {
      int * v4806 = v4792->cache_keys;
      int * v4807 = v4792->cache_keys;
      int v4808 = v4807[0];
      v4806[1] = v4808;
      int * v4810 = v4792->cache_vals;
      int * v4811 = v4792->cache_vals;
      int v4812 = v4811[0];
      v4810[1] = v4812;
      int * v4814 = v4792->cache_keys;
      int v7059 = (int)((unsigned int)(v4796 + 28) >> 2);
      v4814[0] = v7059;
      int * v4816 = v4792->cache_vals;
      v4816[0] = v4798;
      int v4818 = v4792->timer;
      int v7062 = v4818 + 1;
      v4792->timer = v7062;
      v4842 = v4798;
    } else {
      int * v4821 = v4792->mem;
      int * v4822 = v4792->cache_keys;
      int v4823 = v4822[1];
      int * v4824 = v4792->cache_vals;
      int v4825 = v4824[1];
      v4821[v4823] = v4825;
      int * v4827 = v4792->cache_keys;
      int * v4828 = v4792->cache_keys;
      int v4829 = v4828[0];
      v4827[1] = v4829;
      int * v4831 = v4792->cache_vals;
      int * v4832 = v4792->cache_vals;
      int v4833 = v4832[0];
      v4831[1] = v4833;
      int * v4835 = v4792->cache_keys;
      int v7075 = (int)((unsigned int)(v4796 + 28) >> 2);
      v4835[0] = v7075;
      int * v4837 = v4792->cache_vals;
      v4837[0] = v4798;
      int v4839 = v4792->timer;
      int v7078 = v4839 + 100;
      v4792->timer = v7078;
      v4842 = v4798;
    }
    v4844 = v4842;
  }
  struct StateT * v7037 = v4845(v4792);
  return v7037;
}

struct StateT * v8727(struct StateT * v8728) {
  int v8729 = v8728->timer;
  int v19500 = v8729 + 1;
  v8728->timer = v19500;
  int * v8731 = v8728->regs;
  int v8732 = v8731[1];
  int * v8733 = v8728->regs;
  int v8734 = v8733[18];
  int * v8735 = v8728->regs;
  int v19506 = v8732 ^ v8734;
  v8735[1] = v19506;
  struct StateT * v19498 = v8737(v8728);
  return v19498;
}

struct StateT * v11339(struct StateT * v11340) {
  int v11341 = v11340->timer;
  int v16507 = v11341 + 1;
  v11340->timer = v16507;
  int * v11343 = v11340->regs;
  int v11344 = v11343[6];
  int * v11345 = v11340->regs;
  int v16511 = v11344 << 13;
  v11345[6] = v16511;
  struct StateT * v16505 = v11347(v11340);
  return v16505;
}

struct StateT * v4335(struct StateT * v4336) {
  int v4337 = v4336->timer;
  int v7479 = v4337 + 1;
  v4336->timer = v7479;
  int * v4339 = v4336->regs;
  v4339[30] = 1797283840;
  struct StateT * v7477 = v4341(v4336);
  return v7477;
}

struct StateT * v3535(struct StateT * v3536) {
  int v3537 = v3536->timer;
  int v20291 = v3537 + 1;
  v3536->timer = v20291;
  int * v3539 = v3536->regs;
  int v3540 = v3539[20];
  int * v3541 = v3536->regs;
  int v3542 = v3541[15];
  int * v3543 = v3536->regs;
  int v20298 = v3540 ^ v3542;
  v3543[11] = v20298;
  struct StateT * v20289 = v3545(v3536);
  return v20289;
}

struct StateT * v5451(struct StateT * v5452) {
  int v5453 = v5452->timer;
  int v6488 = v5453 + 1;
  v5452->timer = v6488;
  int * v5455 = v5452->regs;
  int v5456 = v5455[2];
  int * v5457 = v5452->cache_keys;
  int v5458 = v5457[0];
  bool v6493 = v5458 == ((int)((unsigned int)(v5456 + 80) >> 2));
  int v5506;
  if (v6493) {
    int * v5459 = v5452->cache_vals;
    int v5460 = v5459[0];
    v5506 = v5460;
  } else {
    int * v5462 = v5452->cache_keys;
    int v5463 = v5462[1];
    bool v6498 = v5463 == ((int)((unsigned int)(v5456 + 80) >> 2));
    int v5504;
    if (v6498) {
      int * v5464 = v5452->cache_vals;
      int v5465 = v5464[1];
      int * v5466 = v5452->cache_keys;
      int * v5467 = v5452->cache_keys;
      int v5468 = v5467[0];
      v5466[1] = v5468;
      int * v5470 = v5452->cache_vals;
      int * v5471 = v5452->cache_vals;
      int v5472 = v5471[0];
      v5470[1] = v5472;
      int * v5474 = v5452->cache_keys;
      int v6507 = (int)((unsigned int)(v5456 + 80) >> 2);
      v5474[0] = v6507;
      int * v5476 = v5452->cache_vals;
      v5476[0] = v5465;
      int v5478 = v5452->timer;
      int v6510 = v5478 + 1;
      v5452->timer = v6510;
      v5504 = v5465;
    } else {
      int * v5481 = v5452->mem;
      int v6512 = (int)((unsigned int)(v5456 + 80) >> 2);
      int v5482 = v5481[v6512];
      int * v5483 = v5452->mem;
      int * v5484 = v5452->cache_keys;
      int v5485 = v5484[1];
      int * v5486 = v5452->cache_vals;
      int v5487 = v5486[1];
      v5483[v5485] = v5487;
      int * v5489 = v5452->cache_keys;
      int * v5490 = v5452->cache_keys;
      int v5491 = v5490[0];
      v5489[1] = v5491;
      int * v5493 = v5452->cache_vals;
      int * v5494 = v5452->cache_vals;
      int v5495 = v5494[0];
      v5493[1] = v5495;
      int * v5497 = v5452->cache_keys;
      v5497[0] = v6512;
      int * v5499 = v5452->cache_vals;
      v5499[0] = v5482;
      int v5501 = v5452->timer;
      int v6527 = v5501 + 100;
      v5452->timer = v6527;
      v5504 = v5482;
    }
    v5506 = v5504;
  }
  int * v5507 = v5452->regs;
  v5507[18] = v5506;
  struct StateT * v6486 = v5509(v5452);
  return v6486;
}

struct StateT * v5169(struct StateT * v5170) {
  int v5171 = v5170->timer;
  int v6725 = v5171 + 1;
  v5170->timer = v6725;
  int * v5173 = v5170->regs;
  int v5174 = v5173[10];
  int * v5175 = v5170->regs;
  int v5176 = v5175[1];
  int * v5177 = v5170->cache_keys;
  int v5178 = v5177[0];
  bool v6732 = v5178 == ((int)((unsigned int)(v5174 + 56) >> 2));
  int v5222;
  if (v6732) {
    int * v5179 = v5170->cache_vals;
    v5179[0] = v5176;
    v5222 = v5176;
  } else {
    int * v5182 = v5170->cache_keys;
    int v5183 = v5182[1];
    bool v6736 = v5183 == ((int)((unsigned int)(v5174 + 56) >> 2));
    int v5220;
    if (v6736) {
      int * v5184 = v5170->cache_keys;
      int * v5185 = v5170->cache_keys;
      int v5186 = v5185[0];
      v5184[1] = v5186;
      int * v5188 = v5170->cache_vals;
      int * v5189 = v5170->cache_vals;
      int v5190 = v5189[0];
      v5188[1] = v5190;
      int * v5192 = v5170->cache_keys;
      int v6744 = (int)((unsigned int)(v5174 + 56) >> 2);
      v5192[0] = v6744;
      int * v5194 = v5170->cache_vals;
      v5194[0] = v5176;
      int v5196 = v5170->timer;
      int v6747 = v5196 + 1;
      v5170->timer = v6747;
      v5220 = v5176;
    } else {
      int * v5199 = v5170->mem;
      int * v5200 = v5170->cache_keys;
      int v5201 = v5200[1];
      int * v5202 = v5170->cache_vals;
      int v5203 = v5202[1];
      v5199[v5201] = v5203;
      int * v5205 = v5170->cache_keys;
      int * v5206 = v5170->cache_keys;
      int v5207 = v5206[0];
      v5205[1] = v5207;
      int * v5209 = v5170->cache_vals;
      int * v5210 = v5170->cache_vals;
      int v5211 = v5210[0];
      v5209[1] = v5211;
      int * v5213 = v5170->cache_keys;
      int v6760 = (int)((unsigned int)(v5174 + 56) >> 2);
      v5213[0] = v6760;
      int * v5215 = v5170->cache_vals;
      v5215[0] = v5176;
      int v5217 = v5170->timer;
      int v6763 = v5217 + 100;
      v5170->timer = v6763;
      v5220 = v5176;
    }
    v5222 = v5220;
  }
  struct StateT * v6723 = v5223(v5170);
  return v6723;
}

struct StateT * v10507(struct StateT * v10508) {
  int v10509 = v10508->timer;
  int v17460 = v10509 + 1;
  v10508->timer = v17460;
  int * v10511 = v10508->regs;
  int v10512 = v10511[15];
  int * v10513 = v10508->regs;
  int v17465 = (int)((unsigned int)v10512 >> 19);
  v10513[20] = v17465;
  struct StateT * v17458 = v10515(v10508);
  return v17458;
}

struct StateT * v10333(struct StateT * v10334) {
  int v10335 = v10334->timer;
  int v17654 = v10335 + 1;
  v10334->timer = v17654;
  int * v10337 = v10334->regs;
  int v10338 = v10337[8];
  int * v10339 = v10334->regs;
  int v17659 = (int)((unsigned int)v10338 >> 23);
  v10339[20] = v17659;
  struct StateT * v17652 = v10341(v10334);
  return v17652;
}

struct StateT * v12396(struct StateT * v12397) {
  int v12398 = v12397->timer;
  int v15474 = v12398 + 1;
  v12397->timer = v15474;
  int * v12400 = v12397->regs;
  int v12401 = v12400[30];
  int * v12402 = v12397->regs;
  int v15478 = v12401 + 1396;
  v12402[30] = v15478;
  struct StateT * v15472 = v12404(v12397);
  return v15472;
}

struct StateT * v9005(struct StateT * v9006) {
  int v9007 = v9006->timer;
  int v19180 = v9007 + 1;
  v9006->timer = v19180;
  int * v9009 = v9006->regs;
  int v9010 = v9009[8];
  int * v9011 = v9006->regs;
  int v19184 = v9010 << 13;
  v9011[8] = v19184;
  struct StateT * v19178 = v9013(v9006);
  return v19178;
}

struct StateT * v10737(struct StateT * v10738) {
  int v10739 = v10738->timer;
  int v17199 = v10739 + 1;
  v10738->timer = v17199;
  int * v10741 = v10738->regs;
  int v10742 = v10741[16];
  int * v10743 = v10738->regs;
  int v17204 = (int)((unsigned int)v10742 >> 14);
  v10743[6] = v17204;
  struct StateT * v17197 = v10745(v10738);
  return v17197;
}

struct StateT * v441(struct StateT * v442) {
  int v443 = v442->timer;
  int v23343 = v443 + 1;
  v442->timer = v23343;
  int * v445 = v442->regs;
  int v446 = v445[2];
  int * v447 = v442->regs;
  int v448 = v447[23];
  int * v449 = v442->cache_keys;
  int v450 = v449[0];
  bool v23350 = v450 == ((int)((unsigned int)(v446 + 60) >> 2));
  int v494;
  if (v23350) {
    int * v451 = v442->cache_vals;
    v451[0] = v448;
    v494 = v448;
  } else {
    int * v454 = v442->cache_keys;
    int v455 = v454[1];
    bool v23355 = v455 == ((int)((unsigned int)(v446 + 60) >> 2));
    int v492;
    if (v23355) {
      int * v456 = v442->cache_keys;
      int * v457 = v442->cache_keys;
      int v458 = v457[0];
      v456[1] = v458;
      int * v460 = v442->cache_vals;
      int * v461 = v442->cache_vals;
      int v462 = v461[0];
      v460[1] = v462;
      int * v464 = v442->cache_keys;
      int v23363 = (int)((unsigned int)(v446 + 60) >> 2);
      v464[0] = v23363;
      int * v466 = v442->cache_vals;
      v466[0] = v448;
      int v468 = v442->timer;
      int v23366 = v468 + 1;
      v442->timer = v23366;
      v492 = v448;
    } else {
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
      int v23379 = (int)((unsigned int)(v446 + 60) >> 2);
      v485[0] = v23379;
      int * v487 = v442->cache_vals;
      v487[0] = v448;
      int v489 = v442->timer;
      int v23382 = v489 + 100;
      v442->timer = v23382;
      v492 = v448;
    }
    v494 = v492;
  }
  struct StateT * v23341 = v495(v442);
  return v23341;
}

struct StateT * v9985(struct StateT * v9986) {
  int v9987 = v9986->timer;
  int v18040 = v9987 + 1;
  v9986->timer = v18040;
  int * v9989 = v9986->regs;
  int v9990 = v9989[8];
  int * v9991 = v9986->regs;
  int v9992 = v9991[9];
  int * v9993 = v9986->regs;
  int v18046 = v9990 | v9992;
  v9993[8] = v18046;
  struct StateT * v18038 = v9995(v9986);
  return v18038;
}

struct StateT * v8881(struct StateT * v8882) {
  int v8883 = v8882->timer;
  int v19321 = v8883 + 1;
  v8882->timer = v19321;
  int * v8885 = v8882->regs;
  int v8886 = v8885[18];
  int * v8887 = v8882->regs;
  int v8888 = v8887[20];
  int * v8889 = v8882->regs;
  int v19327 = v8886 | v8888;
  v8889[18] = v19327;
  struct StateT * v19319 = v8891(v8882);
  return v19319;
}

struct StateT * v12660(struct StateT * v12661) {
  int v12662 = v12661->timer;
  int v15205 = v12662 + 1;
  v12661->timer = v15205;
  int * v12664 = v12661->regs;
  int v12665 = v12664[10];
  int * v12666 = v12661->regs;
  int v12667 = v12666[12];
  int * v12668 = v12661->cache_keys;
  int v12669 = v12668[0];
  bool v15212 = v12669 == ((int)((unsigned int)(v12665 + 16) >> 2));
  int v12713;
  if (v15212) {
    int * v12670 = v12661->cache_vals;
    v12670[0] = v12667;
    v12713 = v12667;
  } else {
    int * v12673 = v12661->cache_keys;
    int v12674 = v12673[1];
    bool v15217 = v12674 == ((int)((unsigned int)(v12665 + 16) >> 2));
    int v12711;
    if (v15217) {
      int * v12675 = v12661->cache_keys;
      int * v12676 = v12661->cache_keys;
      int v12677 = v12676[0];
      v12675[1] = v12677;
      int * v12679 = v12661->cache_vals;
      int * v12680 = v12661->cache_vals;
      int v12681 = v12680[0];
      v12679[1] = v12681;
      int * v12683 = v12661->cache_keys;
      int v15225 = (int)((unsigned int)(v12665 + 16) >> 2);
      v12683[0] = v15225;
      int * v12685 = v12661->cache_vals;
      v12685[0] = v12667;
      int v12687 = v12661->timer;
      int v15228 = v12687 + 1;
      v12661->timer = v15228;
      v12711 = v12667;
    } else {
      int * v12690 = v12661->mem;
      int * v12691 = v12661->cache_keys;
      int v12692 = v12691[1];
      int * v12693 = v12661->cache_vals;
      int v12694 = v12693[1];
      v12690[v12692] = v12694;
      int * v12696 = v12661->cache_keys;
      int * v12697 = v12661->cache_keys;
      int v12698 = v12697[0];
      v12696[1] = v12698;
      int * v12700 = v12661->cache_vals;
      int * v12701 = v12661->cache_vals;
      int v12702 = v12701[0];
      v12700[1] = v12702;
      int * v12704 = v12661->cache_keys;
      int v15241 = (int)((unsigned int)(v12665 + 16) >> 2);
      v12704[0] = v15241;
      int * v12706 = v12661->cache_vals;
      v12706[0] = v12667;
      int v12708 = v12661->timer;
      int v15244 = v12708 + 100;
      v12661->timer = v15244;
      v12711 = v12667;
    }
    v12713 = v12711;
  }
  struct StateT * v15203 = v12714(v12661);
  return v15203;
}

struct StateT * v1469(struct StateT * v1470) {
  int v1471 = v1470->timer;
  int v22500 = v1471 + 1;
  v1470->timer = v22500;
  int * v1473 = v1470->regs;
  v1473[31] = 9;
  struct StateT * v22498 = v1475(v1470);
  return v22498;
}

struct StateT * v5799(struct StateT * v5800) {
  int v5801 = v5800->timer;
  int v6200 = v5801 + 1;
  v5800->timer = v6200;
  int * v5803 = v5800->regs;
  int v5804 = v5803[2];
  int * v5805 = v5800->cache_keys;
  int v5806 = v5805[0];
  bool v6205 = v5806 == ((int)((unsigned int)(v5804 + 56) >> 2));
  int v5854;
  if (v6205) {
    int * v5807 = v5800->cache_vals;
    int v5808 = v5807[0];
    v5854 = v5808;
  } else {
    int * v5810 = v5800->cache_keys;
    int v5811 = v5810[1];
    bool v6210 = v5811 == ((int)((unsigned int)(v5804 + 56) >> 2));
    int v5852;
    if (v6210) {
      int * v5812 = v5800->cache_vals;
      int v5813 = v5812[1];
      int * v5814 = v5800->cache_keys;
      int * v5815 = v5800->cache_keys;
      int v5816 = v5815[0];
      v5814[1] = v5816;
      int * v5818 = v5800->cache_vals;
      int * v5819 = v5800->cache_vals;
      int v5820 = v5819[0];
      v5818[1] = v5820;
      int * v5822 = v5800->cache_keys;
      int v6219 = (int)((unsigned int)(v5804 + 56) >> 2);
      v5822[0] = v6219;
      int * v5824 = v5800->cache_vals;
      v5824[0] = v5813;
      int v5826 = v5800->timer;
      int v6222 = v5826 + 1;
      v5800->timer = v6222;
      v5852 = v5813;
    } else {
      int * v5829 = v5800->mem;
      int v6224 = (int)((unsigned int)(v5804 + 56) >> 2);
      int v5830 = v5829[v6224];
      int * v5831 = v5800->mem;
      int * v5832 = v5800->cache_keys;
      int v5833 = v5832[1];
      int * v5834 = v5800->cache_vals;
      int v5835 = v5834[1];
      v5831[v5833] = v5835;
      int * v5837 = v5800->cache_keys;
      int * v5838 = v5800->cache_keys;
      int v5839 = v5838[0];
      v5837[1] = v5839;
      int * v5841 = v5800->cache_vals;
      int * v5842 = v5800->cache_vals;
      int v5843 = v5842[0];
      v5841[1] = v5843;
      int * v5845 = v5800->cache_keys;
      v5845[0] = v6224;
      int * v5847 = v5800->cache_vals;
      v5847[0] = v5830;
      int v5849 = v5800->timer;
      int v6239 = v5849 + 100;
      v5800->timer = v6239;
      v5852 = v5830;
    }
    v5854 = v5852;
  }
  int * v5855 = v5800->regs;
  v5855[24] = v5854;
  struct StateT * v6198 = v5857(v5800);
  return v6198;
}

struct StateT * v10953(struct StateT * v10954) {
  int v10955 = v10954->timer;
  int v16954 = v10955 + 1;
  v10954->timer = v16954;
  int * v10957 = v10954->regs;
  int v10958 = v10957[11];
  int * v10959 = v10954->regs;
  int v10960 = v10959[5];
  int * v10961 = v10954->regs;
  int v16960 = v10958 | v10960;
  v10961[11] = v16960;
  struct StateT * v16952 = v10963(v10954);
  return v16952;
}

struct StateT * v9677(struct StateT * v9678) {
  int v9679 = v9678->timer;
  int v18396 = v9679 + 1;
  v9678->timer = v18396;
  int * v9681 = v9678->regs;
  int v9682 = v9681[25];
  int * v9683 = v9678->regs;
  int v9684 = v9683[5];
  int * v9685 = v9678->regs;
  int v18403 = v9682 + v9684;
  v9685[15] = v18403;
  struct StateT * v18394 = v9687(v9678);
  return v18394;
}

struct StateT * v2397(struct StateT * v2398) {
  int * v2399 = v2398->saved_regs;
  int * v2400 = v2398->regs;
  int v2401 = v2400[27];
  v2399[27] = v2401;
  int v2403 = v2398->timer;
  int v21596 = v2403 + 1;
  v2398->timer = v21596;
  int * v2405 = v2398->regs;
  int v2406 = v2405[27];
  int * v2407 = v2398->regs;
  int v2408 = v2407[9];
  int * v2409 = v2398->regs;
  int v21601 = v2406 ^ v2408;
  v2409[27] = v21601;
  struct StateT * v21590 = v2411(v2398);
  return v21590;
}

struct StateT * v4349(struct StateT * v4350) {
  int v4351 = v4350->timer;
  int v7461 = v4351 + 1;
  v4350->timer = v7461;
  int * v4353 = v4350->regs;
  int v4354 = v4353[6];
  int * v4355 = v4350->regs;
  int v7465 = v4354 + 1134;
  v4355[6] = v7465;
  struct StateT * v7459 = v4357(v4350);
  return v7459;
}

struct StateT * v10277(struct StateT * v10278) {
  int v10279 = v10278->timer;
  int v17718 = v10279 + 1;
  v10278->timer = v17718;
  int * v10281 = v10278->regs;
  int v10282 = v10281[13];
  int * v10283 = v10278->regs;
  int v10284 = v10283[11];
  int * v10285 = v10278->regs;
  int v17725 = v10282 + v10284;
  v10285[8] = v17725;
  struct StateT * v17716 = v10287(v10278);
  return v17716;
}

struct StateT * v9575(struct StateT * v9576) {
  int v9577 = v9576->timer;
  int v18514 = v9577 + 1;
  v9576->timer = v18514;
  int * v9579 = v9576->regs;
  int v9580 = v9579[6];
  int * v9581 = v9576->regs;
  int v18519 = (int)((unsigned int)v9580 >> 23);
  v9581[9] = v18519;
  struct StateT * v18512 = v9583(v9576);
  return v18512;
}

struct StateT * v3061(struct StateT * v3062) {
  int v3063 = v3062->timer;
  int v20839 = v3063 + 1;
  v3062->timer = v20839;
  int * v3065 = v3062->regs;
  int v3066 = v3065[11];
  int * v3067 = v3062->regs;
  int v20843 = v3066 << 9;
  v3067[11] = v20843;
  struct StateT * v20837 = v3069(v3062);
  return v20837;
}

struct StateT * v10593(struct StateT * v10594) {
  int v10595 = v10594->timer;
  int v17361 = v10595 + 1;
  v10594->timer = v17361;
  int * v10597 = v10594->regs;
  int v10598 = v10597[18];
  int * v10599 = v10594->regs;
  int v17365 = v10598 << 13;
  v10599[18] = v17365;
  struct StateT * v17359 = v10601(v10594);
  return v17359;
}

struct StateT * v11373(struct StateT * v11374) {
  int v11375 = v11374->timer;
  int v16466 = v11375 + 1;
  v11374->timer = v16466;
  int * v11377 = v11374->regs;
  int v11378 = v11377[8];
  int * v11379 = v11374->regs;
  int v11380 = v11379[9];
  int * v11381 = v11374->regs;
  int v16472 = v11378 | v11380;
  v11381[8] = v16472;
  struct StateT * v16464 = v11383(v11374);
  return v16464;
}

struct StateT * v4189(struct StateT * v4190) {
  int v4191 = v4190->timer;
  int v7605 = v4191 + 1;
  v4190->timer = v7605;
  int * v4193 = v4190->regs;
  int v4194 = v4193[16];
  int * v4195 = v4190->regs;
  int v4196 = v4195[30];
  int * v4197 = v4190->regs;
  int v7611 = v4194 + v4196;
  v4197[16] = v7611;
  struct StateT * v7603 = v4199(v4190);
  return v7603;
}

struct StateT * v11716(struct StateT * v11717) {
  int v11718 = v11717->timer;
  int v16084 = v11718 + 1;
  v11717->timer = v16084;
  int * v11720 = v11717->regs;
  int v11721 = v11720[27];
  int * v11722 = v11717->regs;
  int v11723 = v11722[28];
  int * v11724 = v11717->regs;
  int v16090 = v11721 + v11723;
  v11724[28] = v16090;
  struct StateT * v16082 = v11726(v11717);
  return v16082;
}

struct StateT * v14070(struct StateT * v14071) {
  int v14072 = v14071->timer;
  int v14075 = v14072 + 1;
  v14071->timer = v14075;
  return v14071;
}

struct StateT * v12414(struct StateT * v12415) {
  int v12416 = v12415->timer;
  int v15452 = v12416 + 1;
  v12415->timer = v15452;
  int * v12418 = v12415->regs;
  int v12419 = v12418[11];
  int * v12420 = v12415->regs;
  int v12421 = v12420[6];
  int * v12422 = v12415->regs;
  int v15458 = v12419 + v12421;
  v12422[11] = v15458;
  struct StateT * v15450 = v12424(v12415);
  return v15450;
}

struct StateT * v5625(struct StateT * v5626) {
  int v5627 = v5626->timer;
  int v6344 = v5627 + 1;
  v5626->timer = v6344;
  int * v5629 = v5626->regs;
  int v5630 = v5629[2];
  int * v5631 = v5626->cache_keys;
  int v5632 = v5631[0];
  bool v6349 = v5632 == ((int)((unsigned int)(v5630 + 68) >> 2));
  int v5680;
  if (v6349) {
    int * v5633 = v5626->cache_vals;
    int v5634 = v5633[0];
    v5680 = v5634;
  } else {
    int * v5636 = v5626->cache_keys;
    int v5637 = v5636[1];
    bool v6354 = v5637 == ((int)((unsigned int)(v5630 + 68) >> 2));
    int v5678;
    if (v6354) {
      int * v5638 = v5626->cache_vals;
      int v5639 = v5638[1];
      int * v5640 = v5626->cache_keys;
      int * v5641 = v5626->cache_keys;
      int v5642 = v5641[0];
      v5640[1] = v5642;
      int * v5644 = v5626->cache_vals;
      int * v5645 = v5626->cache_vals;
      int v5646 = v5645[0];
      v5644[1] = v5646;
      int * v5648 = v5626->cache_keys;
      int v6363 = (int)((unsigned int)(v5630 + 68) >> 2);
      v5648[0] = v6363;
      int * v5650 = v5626->cache_vals;
      v5650[0] = v5639;
      int v5652 = v5626->timer;
      int v6366 = v5652 + 1;
      v5626->timer = v6366;
      v5678 = v5639;
    } else {
      int * v5655 = v5626->mem;
      int v6368 = (int)((unsigned int)(v5630 + 68) >> 2);
      int v5656 = v5655[v6368];
      int * v5657 = v5626->mem;
      int * v5658 = v5626->cache_keys;
      int v5659 = v5658[1];
      int * v5660 = v5626->cache_vals;
      int v5661 = v5660[1];
      v5657[v5659] = v5661;
      int * v5663 = v5626->cache_keys;
      int * v5664 = v5626->cache_keys;
      int v5665 = v5664[0];
      v5663[1] = v5665;
      int * v5667 = v5626->cache_vals;
      int * v5668 = v5626->cache_vals;
      int v5669 = v5668[0];
      v5667[1] = v5669;
      int * v5671 = v5626->cache_keys;
      v5671[0] = v6368;
      int * v5673 = v5626->cache_vals;
      v5673[0] = v5656;
      int v5675 = v5626->timer;
      int v6383 = v5675 + 100;
      v5626->timer = v6383;
      v5678 = v5656;
    }
    v5680 = v5678;
  }
  int * v5681 = v5626->regs;
  v5681[21] = v5680;
  struct StateT * v6342 = v5683(v5626);
  return v6342;
}

struct StateT * v3421(struct StateT * v3422) {
  int v3423 = v3422->timer;
  int v20424 = v3423 + 1;
  v3422->timer = v20424;
  int * v3425 = v3422->regs;
  int v3426 = v3425[11];
  int * v3427 = v3422->regs;
  int v20429 = (int)((unsigned int)v3426 >> 14);
  v3427[9] = v20429;
  struct StateT * v20422 = v3429(v3422);
  return v20422;
}

struct StateT * v9463(struct StateT * v9464) {
  int v9465 = v9464->timer;
  int v18644 = v9465 + 1;
  v9464->timer = v18644;
  int * v9467 = v9464->regs;
  int v9468 = v9467[8];
  int * v9469 = v9464->regs;
  int v9470 = v9469[16];
  int * v9471 = v9464->regs;
  int v18651 = v9468 ^ v9470;
  v9471[17] = v18651;
  struct StateT * v18642 = v9473(v9464);
  return v18642;
}

struct StateT * v5509(struct StateT * v5510) {
  int v5511 = v5510->timer;
  int v6440 = v5511 + 1;
  v5510->timer = v6440;
  int * v5513 = v5510->regs;
  int v5514 = v5513[2];
  int * v5515 = v5510->cache_keys;
  int v5516 = v5515[0];
  bool v6445 = v5516 == ((int)((unsigned int)(v5514 + 76) >> 2));
  int v5564;
  if (v6445) {
    int * v5517 = v5510->cache_vals;
    int v5518 = v5517[0];
    v5564 = v5518;
  } else {
    int * v5520 = v5510->cache_keys;
    int v5521 = v5520[1];
    bool v6450 = v5521 == ((int)((unsigned int)(v5514 + 76) >> 2));
    int v5562;
    if (v6450) {
      int * v5522 = v5510->cache_vals;
      int v5523 = v5522[1];
      int * v5524 = v5510->cache_keys;
      int * v5525 = v5510->cache_keys;
      int v5526 = v5525[0];
      v5524[1] = v5526;
      int * v5528 = v5510->cache_vals;
      int * v5529 = v5510->cache_vals;
      int v5530 = v5529[0];
      v5528[1] = v5530;
      int * v5532 = v5510->cache_keys;
      int v6459 = (int)((unsigned int)(v5514 + 76) >> 2);
      v5532[0] = v6459;
      int * v5534 = v5510->cache_vals;
      v5534[0] = v5523;
      int v5536 = v5510->timer;
      int v6462 = v5536 + 1;
      v5510->timer = v6462;
      v5562 = v5523;
    } else {
      int * v5539 = v5510->mem;
      int v6464 = (int)((unsigned int)(v5514 + 76) >> 2);
      int v5540 = v5539[v6464];
      int * v5541 = v5510->mem;
      int * v5542 = v5510->cache_keys;
      int v5543 = v5542[1];
      int * v5544 = v5510->cache_vals;
      int v5545 = v5544[1];
      v5541[v5543] = v5545;
      int * v5547 = v5510->cache_keys;
      int * v5548 = v5510->cache_keys;
      int v5549 = v5548[0];
      v5547[1] = v5549;
      int * v5551 = v5510->cache_vals;
      int * v5552 = v5510->cache_vals;
      int v5553 = v5552[0];
      v5551[1] = v5553;
      int * v5555 = v5510->cache_keys;
      v5555[0] = v6464;
      int * v5557 = v5510->cache_vals;
      v5557[0] = v5540;
      int v5559 = v5510->timer;
      int v6479 = v5559 + 100;
      v5510->timer = v6479;
      v5562 = v5540;
    }
    v5564 = v5562;
  }
  int * v5565 = v5510->regs;
  v5565[19] = v5564;
  struct StateT * v6438 = v5567(v5510);
  return v6438;
}

struct StateT * v8131(struct StateT * v8132) {
  int * v8133 = v8132->saved_regs;
  int * v8134 = v8132->regs;
  int v8135 = v8134[6];
  v8133[6] = v8135;
  int v8137 = v8132->timer;
  int v20047 = v8137 + 1;
  v8132->timer = v20047;
  int * v8139 = v8132->regs;
  int v8140 = v8139[2];
  int * v8141 = v8132->cache_keys;
  int v8142 = v8141[0];
  bool v20052 = v8142 == ((int)((unsigned int)(v8140 + 8) >> 2));
  int v8190;
  if (v20052) {
    int * v8143 = v8132->cache_vals;
    int v8144 = v8143[0];
    v8190 = v8144;
  } else {
    int * v8146 = v8132->cache_keys;
    int v8147 = v8146[1];
    bool v20057 = v8147 == ((int)((unsigned int)(v8140 + 8) >> 2));
    int v8188;
    if (v20057) {
      int * v8148 = v8132->cache_vals;
      int v8149 = v8148[1];
      int * v8150 = v8132->cache_keys;
      int * v8151 = v8132->cache_keys;
      int v8152 = v8151[0];
      v8150[1] = v8152;
      int * v8154 = v8132->cache_vals;
      int * v8155 = v8132->cache_vals;
      int v8156 = v8155[0];
      v8154[1] = v8156;
      int * v8158 = v8132->cache_keys;
      int v20066 = (int)((unsigned int)(v8140 + 8) >> 2);
      v8158[0] = v20066;
      int * v8160 = v8132->cache_vals;
      v8160[0] = v8149;
      int v8162 = v8132->timer;
      int v20069 = v8162 + 1;
      v8132->timer = v20069;
      v8188 = v8149;
    } else {
      int * v8165 = v8132->mem;
      int v20071 = (int)((unsigned int)(v8140 + 8) >> 2);
      int v8166 = v8165[v20071];
      int * v8167 = v8132->mem;
      int * v8168 = v8132->cache_keys;
      int v8169 = v8168[1];
      int * v8170 = v8132->cache_vals;
      int v8171 = v8170[1];
      v8167[v8169] = v8171;
      int * v8173 = v8132->cache_keys;
      int * v8174 = v8132->cache_keys;
      int v8175 = v8174[0];
      v8173[1] = v8175;
      int * v8177 = v8132->cache_vals;
      int * v8178 = v8132->cache_vals;
      int v8179 = v8178[0];
      v8177[1] = v8179;
      int * v8181 = v8132->cache_keys;
      v8181[0] = v20071;
      int * v8183 = v8132->cache_vals;
      v8183[0] = v8166;
      int v8185 = v8132->timer;
      int v20086 = v8185 + 100;
      v8132->timer = v20086;
      v8188 = v8166;
    }
    v8190 = v8188;
  }
  int * v8191 = v8132->regs;
  v8191[6] = v8190;
  struct StateT * v20041 = v8193(v8132);
  return v20041;
}

struct StateT * v4357(struct StateT * v4358) {
  int v4359 = v4358->timer;
  int v7452 = v4359 + 1;
  v4358->timer = v7452;
  int * v4361 = v4358->regs;
  int v4362 = v4361[7];
  int * v4363 = v4358->regs;
  int v7456 = v4362 + -718;
  v4363[7] = v7456;
  struct StateT * v7450 = v4365(v4358);
  return v7450;
}

struct StateT * v3381(struct StateT * v3382) {
  int v3383 = v3382->timer;
  int v20470 = v3383 + 1;
  v3382->timer = v20470;
  int * v3385 = v3382->regs;
  int v3386 = v3385[14];
  int * v3387 = v3382->regs;
  int v3388 = v3387[27];
  int * v3389 = v3382->regs;
  int v20477 = v3386 + v3388;
  v3389[11] = v20477;
  struct StateT * v20468 = v3391(v3382);
  return v20468;
}

struct StateT * v11489(struct StateT * v11490) {
  int v11491 = v11490->timer;
  int v16334 = v11491 + 1;
  v11490->timer = v16334;
  int * v11493 = v11490->regs;
  int v11494 = v11493[15];
  int * v11495 = v11490->regs;
  int v16339 = (int)((unsigned int)v11494 >> 14);
  v11495[9] = v16339;
  struct StateT * v16332 = v11497(v11490);
  return v16332;
}

struct StateT * v1413(struct StateT * v1414) {
  int v1415 = v1414->timer;
  int v22571 = v1415 + 1;
  v1414->timer = v22571;
  int * v1417 = v1414->regs;
  v1417[12] = 1634762752;
  struct StateT * v22569 = v1419(v1414);
  return v22569;
}

struct StateT * v2001(struct StateT * v2002) {
  int v2003 = v2002->timer;
  int v22041 = v2003 + 1;
  v2002->timer = v22041;
  struct StateT * v22039 = v2005(v2002);
  return v22039;
}

struct StateT * v11269(struct StateT * v11270) {
  int v11271 = v11270->timer;
  int v16586 = v11271 + 1;
  v11270->timer = v16586;
  int * v11273 = v11270->regs;
  int v11274 = v11273[24];
  int * v11275 = v11270->regs;
  int v11276 = v11275[16];
  int * v11277 = v11270->regs;
  int v16593 = v11274 + v11276;
  v11277[8] = v16593;
  struct StateT * v16584 = v11279(v11270);
  return v16584;
}

struct StateT * v12162(struct StateT * v12163) {
  int v12164 = v12163->timer;
  int v15647 = v12164 + 1;
  v12163->timer = v15647;
  int * v12166 = v12163->regs;
  int v12167 = v12166[2];
  int * v12168 = v12163->cache_keys;
  int v12169 = v12168[0];
  bool v15652 = v12169 == ((int)((unsigned int)(v12167 + 32) >> 2));
  int v12217;
  if (v15652) {
    int * v12170 = v12163->cache_vals;
    int v12171 = v12170[0];
    v12217 = v12171;
  } else {
    int * v12173 = v12163->cache_keys;
    int v12174 = v12173[1];
    bool v15657 = v12174 == ((int)((unsigned int)(v12167 + 32) >> 2));
    int v12215;
    if (v15657) {
      int * v12175 = v12163->cache_vals;
      int v12176 = v12175[1];
      int * v12177 = v12163->cache_keys;
      int * v12178 = v12163->cache_keys;
      int v12179 = v12178[0];
      v12177[1] = v12179;
      int * v12181 = v12163->cache_vals;
      int * v12182 = v12163->cache_vals;
      int v12183 = v12182[0];
      v12181[1] = v12183;
      int * v12185 = v12163->cache_keys;
      int v15666 = (int)((unsigned int)(v12167 + 32) >> 2);
      v12185[0] = v15666;
      int * v12187 = v12163->cache_vals;
      v12187[0] = v12176;
      int v12189 = v12163->timer;
      int v15669 = v12189 + 1;
      v12163->timer = v15669;
      v12215 = v12176;
    } else {
      int * v12192 = v12163->mem;
      int v15671 = (int)((unsigned int)(v12167 + 32) >> 2);
      int v12193 = v12192[v15671];
      int * v12194 = v12163->mem;
      int * v12195 = v12163->cache_keys;
      int v12196 = v12195[1];
      int * v12197 = v12163->cache_vals;
      int v12198 = v12197[1];
      v12194[v12196] = v12198;
      int * v12200 = v12163->cache_keys;
      int * v12201 = v12163->cache_keys;
      int v12202 = v12201[0];
      v12200[1] = v12202;
      int * v12204 = v12163->cache_vals;
      int * v12205 = v12163->cache_vals;
      int v12206 = v12205[0];
      v12204[1] = v12206;
      int * v12208 = v12163->cache_keys;
      v12208[0] = v15671;
      int * v12210 = v12163->cache_vals;
      v12210[0] = v12193;
      int v12212 = v12163->timer;
      int v15686 = v12212 + 100;
      v12163->timer = v15686;
      v12215 = v12193;
    }
    v12217 = v12215;
  }
  int * v12218 = v12163->regs;
  v12218[30] = v12217;
  struct StateT * v15645 = v12220(v12163);
  return v15645;
}

struct StateT * v12020(struct StateT * v12021) {
  int v12022 = v12021->timer;
  int v15773 = v12022 + 1;
  v12021->timer = v15773;
  int * v12024 = v12021->regs;
  int v12025 = v12024[2];
  int * v12026 = v12021->cache_keys;
  int v12027 = v12026[0];
  bool v15778 = v12027 == ((int)((unsigned int)(v12025 + 24) >> 2));
  int v12075;
  if (v15778) {
    int * v12028 = v12021->cache_vals;
    int v12029 = v12028[0];
    v12075 = v12029;
  } else {
    int * v12031 = v12021->cache_keys;
    int v12032 = v12031[1];
    bool v15783 = v12032 == ((int)((unsigned int)(v12025 + 24) >> 2));
    int v12073;
    if (v15783) {
      int * v12033 = v12021->cache_vals;
      int v12034 = v12033[1];
      int * v12035 = v12021->cache_keys;
      int * v12036 = v12021->cache_keys;
      int v12037 = v12036[0];
      v12035[1] = v12037;
      int * v12039 = v12021->cache_vals;
      int * v12040 = v12021->cache_vals;
      int v12041 = v12040[0];
      v12039[1] = v12041;
      int * v12043 = v12021->cache_keys;
      int v15792 = (int)((unsigned int)(v12025 + 24) >> 2);
      v12043[0] = v15792;
      int * v12045 = v12021->cache_vals;
      v12045[0] = v12034;
      int v12047 = v12021->timer;
      int v15795 = v12047 + 1;
      v12021->timer = v15795;
      v12073 = v12034;
    } else {
      int * v12050 = v12021->mem;
      int v15797 = (int)((unsigned int)(v12025 + 24) >> 2);
      int v12051 = v12050[v15797];
      int * v12052 = v12021->mem;
      int * v12053 = v12021->cache_keys;
      int v12054 = v12053[1];
      int * v12055 = v12021->cache_vals;
      int v12056 = v12055[1];
      v12052[v12054] = v12056;
      int * v12058 = v12021->cache_keys;
      int * v12059 = v12021->cache_keys;
      int v12060 = v12059[0];
      v12058[1] = v12060;
      int * v12062 = v12021->cache_vals;
      int * v12063 = v12021->cache_vals;
      int v12064 = v12063[0];
      v12062[1] = v12064;
      int * v12066 = v12021->cache_keys;
      v12066[0] = v15797;
      int * v12068 = v12021->cache_vals;
      v12068[0] = v12051;
      int v12070 = v12021->timer;
      int v15812 = v12070 + 100;
      v12021->timer = v15812;
      v12073 = v12051;
    }
    v12075 = v12073;
  }
  int * v12076 = v12021->regs;
  v12076[7] = v12075;
  struct StateT * v15771 = v12078(v12021);
  return v15771;
}

struct StateT * v10375(struct StateT * v10376) {
  int v10377 = v10376->timer;
  int v17604 = v10377 + 1;
  v10376->timer = v17604;
  int * v10379 = v10376->regs;
  int v10380 = v10379[9];
  int * v10381 = v10376->regs;
  int v10382 = v10381[20];
  int * v10383 = v10376->regs;
  int v17610 = v10380 | v10382;
  v10383[9] = v17610;
  struct StateT * v17602 = v10385(v10376);
  return v17602;
}

struct StateT * v2711(struct StateT * v2712) {
  int v2713 = v2712->timer;
  int v21239 = v2713 + 1;
  v2712->timer = v21239;
  int * v2715 = v2712->regs;
  int v2716 = v2715[16];
  int * v2717 = v2712->regs;
  int v2718 = v2717[6];
  int * v2719 = v2712->regs;
  int v21245 = v2716 | v2718;
  v2719[16] = v21245;
  struct StateT * v21237 = v2721(v2712);
  return v21237;
}

struct StateT * v1993(struct StateT * v1994) {
  int v1995 = v1994->timer;
  int v22046 = v1995 + 1;
  v1994->timer = v22046;
  int * v1997 = v1994->regs;
  int v1998 = v1997[15];
  int * v1999 = v1994->regs;
  v1999[13] = v1998;
  struct StateT * v22044 = v2001(v1994);
  return v22044;
}

struct StateT * v9269(struct StateT * v9270) {
  int v9271 = v9270->timer;
  int v18870 = v9271 + 1;
  v9270->timer = v18870;
  int * v9273 = v9270->regs;
  int v9274 = v9273[11];
  int * v9275 = v9270->regs;
  int v9276 = v9275[16];
  int * v9277 = v9270->regs;
  int v18877 = v9274 ^ v9276;
  v9277[20] = v18877;
  struct StateT * v18868 = v9279(v9270);
  return v18868;
}

struct StateT * v8629(struct StateT * v8630) {
  int v8631 = v8630->timer;
  int v19613 = v8631 + 1;
  v8630->timer = v19613;
  int * v8633 = v8630->regs;
  int v8634 = v8633[20];
  int * v8635 = v8630->regs;
  int v19618 = (int)((unsigned int)v8634 >> 25);
  v8635[9] = v19618;
  struct StateT * v19611 = v8637(v8630);
  return v19611;
}

struct StateT * v11942(struct StateT * v11943) {
  int v11944 = v11943->timer;
  int v15880 = v11944 + 1;
  v11943->timer = v15880;
  int * v11946 = v11943->regs;
  int v11947 = v11946[25];
  int * v11948 = v11943->regs;
  int v11949 = v11948[7];
  int * v11950 = v11943->regs;
  int v15886 = v11947 + v11949;
  v11950[25] = v15886;
  struct StateT * v15878 = v11952(v11943);
  return v15878;
}

struct StateT * v10439(struct StateT * v10440) {
  int * v10441 = v10440->saved_regs;
  int * v10442 = v10440->regs;
  int v10443 = v10442[27];
  v10441[27] = v10443;
  int v10445 = v10440->timer;
  int v17536 = v10445 + 1;
  v10440->timer = v17536;
  int * v10447 = v10440->regs;
  int v10448 = v10447[27];
  int * v10449 = v10440->regs;
  int v10450 = v10449[9];
  int * v10451 = v10440->regs;
  int v17541 = v10448 ^ v10450;
  v10451[27] = v17541;
  struct StateT * v17530 = v10453(v10440);
  return v17530;
}

struct StateT * v2197(struct StateT * v2198) {
  int * v2199 = v2198->saved_regs;
  int * v2200 = v2198->regs;
  int v2201 = v2200[1];
  v2199[1] = v2201;
  int v2203 = v2198->timer;
  int v21820 = v2203 + 1;
  v2198->timer = v21820;
  int * v2205 = v2198->regs;
  int v2206 = v2205[1];
  int * v2207 = v2198->regs;
  int v2208 = v2207[18];
  int * v2209 = v2198->regs;
  int v21825 = v2206 ^ v2208;
  v2209[1] = v21825;
  struct StateT * v21814 = v2211(v2198);
  return v21814;
}

struct StateT * v1475(struct StateT * v1476) {
  int v1477 = v1476->timer;
  int v22455 = v1477 + 1;
  v1476->timer = v22455;
  int * v1479 = v1476->regs;
  int v1480 = v1479[2];
  int * v1481 = v1476->regs;
  int v1482 = v1481[26];
  int * v1483 = v1476->cache_keys;
  int v1484 = v1483[0];
  bool v22462 = v1484 == ((int)((unsigned int)(v1480 + 20) >> 2));
  int v1528;
  if (v22462) {
    int * v1485 = v1476->cache_vals;
    v1485[0] = v1482;
    v1528 = v1482;
  } else {
    int * v1488 = v1476->cache_keys;
    int v1489 = v1488[1];
    bool v22467 = v1489 == ((int)((unsigned int)(v1480 + 20) >> 2));
    int v1526;
    if (v22467) {
      int * v1490 = v1476->cache_keys;
      int * v1491 = v1476->cache_keys;
      int v1492 = v1491[0];
      v1490[1] = v1492;
      int * v1494 = v1476->cache_vals;
      int * v1495 = v1476->cache_vals;
      int v1496 = v1495[0];
      v1494[1] = v1496;
      int * v1498 = v1476->cache_keys;
      int v22475 = (int)((unsigned int)(v1480 + 20) >> 2);
      v1498[0] = v22475;
      int * v1500 = v1476->cache_vals;
      v1500[0] = v1482;
      int v1502 = v1476->timer;
      int v22478 = v1502 + 1;
      v1476->timer = v22478;
      v1526 = v1482;
    } else {
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
      int v22491 = (int)((unsigned int)(v1480 + 20) >> 2);
      v1519[0] = v22491;
      int * v1521 = v1476->cache_vals;
      v1521[0] = v1482;
      int v1523 = v1476->timer;
      int v22494 = v1523 + 100;
      v1476->timer = v22494;
      v1526 = v1482;
    }
    v1528 = v1526;
  }
  struct StateT * v22453 = v1529(v1476);
  return v22453;
}

struct StateT * v9759(struct StateT * v9760) {
  int v9761 = v9760->timer;
  int v18302 = v9761 + 1;
  v9760->timer = v18302;
  int * v9763 = v9760->regs;
  int v9764 = v9763[6];
  int * v9765 = v9760->regs;
  int v18307 = (int)((unsigned int)v9764 >> 19);
  v9765[9] = v18307;
  struct StateT * v18300 = v9767(v9760);
  return v18300;
}

struct StateT * v5741(struct StateT * v5742) {
  int v5743 = v5742->timer;
  int v6248 = v5743 + 1;
  v5742->timer = v6248;
  int * v5745 = v5742->regs;
  int v5746 = v5745[2];
  int * v5747 = v5742->cache_keys;
  int v5748 = v5747[0];
  bool v6253 = v5748 == ((int)((unsigned int)(v5746 + 60) >> 2));
  int v5796;
  if (v6253) {
    int * v5749 = v5742->cache_vals;
    int v5750 = v5749[0];
    v5796 = v5750;
  } else {
    int * v5752 = v5742->cache_keys;
    int v5753 = v5752[1];
    bool v6258 = v5753 == ((int)((unsigned int)(v5746 + 60) >> 2));
    int v5794;
    if (v6258) {
      int * v5754 = v5742->cache_vals;
      int v5755 = v5754[1];
      int * v5756 = v5742->cache_keys;
      int * v5757 = v5742->cache_keys;
      int v5758 = v5757[0];
      v5756[1] = v5758;
      int * v5760 = v5742->cache_vals;
      int * v5761 = v5742->cache_vals;
      int v5762 = v5761[0];
      v5760[1] = v5762;
      int * v5764 = v5742->cache_keys;
      int v6267 = (int)((unsigned int)(v5746 + 60) >> 2);
      v5764[0] = v6267;
      int * v5766 = v5742->cache_vals;
      v5766[0] = v5755;
      int v5768 = v5742->timer;
      int v6270 = v5768 + 1;
      v5742->timer = v6270;
      v5794 = v5755;
    } else {
      int * v5771 = v5742->mem;
      int v6272 = (int)((unsigned int)(v5746 + 60) >> 2);
      int v5772 = v5771[v6272];
      int * v5773 = v5742->mem;
      int * v5774 = v5742->cache_keys;
      int v5775 = v5774[1];
      int * v5776 = v5742->cache_vals;
      int v5777 = v5776[1];
      v5773[v5775] = v5777;
      int * v5779 = v5742->cache_keys;
      int * v5780 = v5742->cache_keys;
      int v5781 = v5780[0];
      v5779[1] = v5781;
      int * v5783 = v5742->cache_vals;
      int * v5784 = v5742->cache_vals;
      int v5785 = v5784[0];
      v5783[1] = v5785;
      int * v5787 = v5742->cache_keys;
      v5787[0] = v6272;
      int * v5789 = v5742->cache_vals;
      v5789[0] = v5772;
      int v5791 = v5742->timer;
      int v6287 = v5791 + 100;
      v5742->timer = v6287;
      v5794 = v5772;
    }
    v5796 = v5794;
  }
  int * v5797 = v5742->regs;
  v5797[23] = v5796;
  struct StateT * v6246 = v5799(v5742);
  return v6246;
}

struct StateT * v9657(struct StateT * v9658) {
  int v9659 = v9658->timer;
  int v18420 = v9659 + 1;
  v9658->timer = v18420;
  int * v9661 = v9658->regs;
  int v9662 = v9661[24];
  int * v9663 = v9658->regs;
  int v9664 = v9663[8];
  int * v9665 = v9658->regs;
  int v18426 = v9662 ^ v9664;
  v9665[24] = v18426;
  struct StateT * v18418 = v9667(v9658);
  return v18418;
}

struct StateT * v2019(struct StateT * v2020) {
  int * v2021 = v2020->saved_regs;
  int * v2022 = v2020->regs;
  int v2023 = v2022[20];
  v2021[20] = v2023;
  int v2025 = v2020->timer;
  int v22015 = v2025 + 1;
  v2020->timer = v22015;
  int * v2027 = v2020->regs;
  int v2028 = v2027[11];
  int * v2029 = v2020->regs;
  int v2030 = v2029[23];
  int * v2031 = v2020->regs;
  int v22021 = v2028 + v2030;
  v2031[20] = v22021;
  struct StateT * v22009 = v2033(v2020);
  return v22009;
}

struct StateT * v10753(struct StateT * v10754) {
  int v10755 = v10754->timer;
  int v17179 = v10755 + 1;
  v10754->timer = v17179;
  int * v10757 = v10754->regs;
  int v10758 = v10757[16];
  int * v10759 = v10754->regs;
  int v10760 = v10759[6];
  int * v10761 = v10754->regs;
  int v17185 = v10758 | v10760;
  v10761[16] = v17185;
  struct StateT * v17177 = v10763(v10754);
  return v17177;
}

struct StateT * v8603(struct StateT * v8604) {
  int v8605 = v8604->timer;
  int v19643 = v8605 + 1;
  v8604->timer = v19643;
  int * v8607 = v8604->regs;
  int v8608 = v8607[15];
  int * v8609 = v8604->regs;
  int v19648 = (int)((unsigned int)v8608 >> 25);
  v8609[9] = v19648;
  struct StateT * v19641 = v8611(v8604);
  return v19641;
}

struct StateT * v3113(struct StateT * v3114) {
  int v3115 = v3114->timer;
  int v20779 = v3115 + 1;
  v3114->timer = v20779;
  int * v3117 = v3114->regs;
  int v3118 = v3117[6];
  int * v3119 = v3114->regs;
  int v20783 = v3118 << 9;
  v3119[6] = v20783;
  struct StateT * v20777 = v3121(v3114);
  return v20777;
}

struct StateT * v10683(struct StateT * v10684) {
  int * v10685 = v10684->saved_regs;
  int * v10686 = v10684->regs;
  int v10687 = v10686[17];
  v10685[17] = v10687;
  int v10689 = v10684->timer;
  int v17258 = v10689 + 1;
  v10684->timer = v17258;
  int * v10691 = v10684->regs;
  int v10692 = v10691[18];
  int * v10693 = v10684->regs;
  int v10694 = v10693[27];
  int * v10695 = v10684->regs;
  int v17264 = v10692 + v10694;
  v10695[17] = v17264;
  struct StateT * v17252 = v10697(v10684);
  return v17252;
}

struct StateT * v8593(struct StateT * v8594) {
  int v8595 = v8594->timer;
  int v19653 = v8595 + 1;
  v8594->timer = v19653;
  int * v8597 = v8594->regs;
  int v8598 = v8597[22];
  int * v8599 = v8594->regs;
  int v8600 = v8599[17];
  int * v8601 = v8594->regs;
  int v19660 = v8598 + v8600;
  v8601[8] = v19660;
  struct StateT * v19651 = v8603(v8594);
  return v19651;
}

struct StateT * v11347(struct StateT * v11348) {
  int v11349 = v11348->timer;
  int v16496 = v11349 + 1;
  v11348->timer = v16496;
  int * v11351 = v11348->regs;
  int v11352 = v11351[6];
  int * v11353 = v11348->regs;
  int v11354 = v11353[9];
  int * v11355 = v11348->regs;
  int v16502 = v11352 | v11354;
  v11355[6] = v16502;
  struct StateT * v16494 = v11357(v11348);
  return v16494;
}

struct StateT * v10487(struct StateT * v10488) {
  int v10489 = v10488->timer;
  int v17482 = v10489 + 1;
  v10488->timer = v17482;
  int * v10491 = v10488->regs;
  int v10492 = v10491[27];
  int * v10493 = v10488->regs;
  int v10494 = v10493[1];
  int * v10495 = v10488->regs;
  int v17489 = v10492 + v10494;
  v10495[9] = v17489;
  struct StateT * v17480 = v10497(v10488);
  return v17480;
}

struct StateT * v8573(struct StateT * v8574) {
  int v8575 = v8574->timer;
  int v19677 = v8575 + 1;
  v8574->timer = v19677;
  int * v8577 = v8574->regs;
  int v8578 = v8577[11];
  int * v8579 = v8574->regs;
  int v8580 = v8579[23];
  int * v8581 = v8574->regs;
  int v19684 = v8578 + v8580;
  v8581[20] = v19684;
  struct StateT * v19675 = v8583(v8574);
  return v19675;
}

struct StateT * v4257(struct StateT * v4258) {
  int v4259 = v4258->timer;
  int v7546 = v4259 + 1;
  v4258->timer = v7546;
  int * v4261 = v4258->regs;
  int v4262 = v4261[24];
  int * v4263 = v4258->regs;
  int v4264 = v4263[30];
  int * v4265 = v4258->regs;
  int v7552 = v4262 + v4264;
  v4265[24] = v7552;
  struct StateT * v7544 = v4267(v4258);
  return v7544;
}

struct StateT * v8821(struct StateT * v8822) {
  int v8823 = v8822->timer;
  int v19392 = v8823 + 1;
  v8822->timer = v19392;
  int * v8825 = v8822->regs;
  int v8826 = v8825[8];
  int * v8827 = v8822->regs;
  int v19396 = v8826 << 9;
  v8827[8] = v19396;
  struct StateT * v19390 = v8829(v8822);
  return v19390;
}

struct StateT * v11383(struct StateT * v11384) {
  int v11385 = v11384->timer;
  int v16455 = v11385 + 1;
  v11384->timer = v16455;
  int * v11387 = v11384->regs;
  int v11388 = v11387[14];
  int * v11389 = v11384->regs;
  int v11390 = v11389[11];
  int * v11391 = v11384->regs;
  int v16461 = v11388 ^ v11390;
  v11391[14] = v16461;
  struct StateT * v16453 = v11393(v11384);
  return v16453;
}

struct StateT * v2299(struct StateT * v2300) {
  int v2301 = v2300->timer;
  int v21705 = v2301 + 1;
  v2300->timer = v21705;
  int * v2303 = v2300->regs;
  int v2304 = v2303[8];
  int * v2305 = v2300->regs;
  int v21709 = v2304 << 9;
  v2305[8] = v21709;
  struct StateT * v21703 = v2307(v2300);
  return v21703;
}

struct StateT * v10385(struct StateT * v10386) {
  int v10387 = v10386->timer;
  int v17594 = v10387 + 1;
  v10386->timer = v17594;
  int * v10389 = v10386->regs;
  int v10390 = v10389[18];
  int * v10391 = v10386->regs;
  int v17599 = (int)((unsigned int)v10390 >> 23);
  v10391[20] = v17599;
  struct StateT * v17592 = v10393(v10386);
  return v17592;
}

struct StateT * v5277(struct StateT * v5278) {
  int v5279 = v5278->timer;
  int v6632 = v5279 + 1;
  v5278->timer = v6632;
  int * v5281 = v5278->regs;
  int v5282 = v5281[2];
  int * v5283 = v5278->cache_keys;
  int v5284 = v5283[0];
  bool v6637 = v5284 == ((int)((unsigned int)(v5282 + 92) >> 2));
  int v5332;
  if (v6637) {
    int * v5285 = v5278->cache_vals;
    int v5286 = v5285[0];
    v5332 = v5286;
  } else {
    int * v5288 = v5278->cache_keys;
    int v5289 = v5288[1];
    bool v6642 = v5289 == ((int)((unsigned int)(v5282 + 92) >> 2));
    int v5330;
    if (v6642) {
      int * v5290 = v5278->cache_vals;
      int v5291 = v5290[1];
      int * v5292 = v5278->cache_keys;
      int * v5293 = v5278->cache_keys;
      int v5294 = v5293[0];
      v5292[1] = v5294;
      int * v5296 = v5278->cache_vals;
      int * v5297 = v5278->cache_vals;
      int v5298 = v5297[0];
      v5296[1] = v5298;
      int * v5300 = v5278->cache_keys;
      int v6651 = (int)((unsigned int)(v5282 + 92) >> 2);
      v5300[0] = v6651;
      int * v5302 = v5278->cache_vals;
      v5302[0] = v5291;
      int v5304 = v5278->timer;
      int v6654 = v5304 + 1;
      v5278->timer = v6654;
      v5330 = v5291;
    } else {
      int * v5307 = v5278->mem;
      int v6656 = (int)((unsigned int)(v5282 + 92) >> 2);
      int v5308 = v5307[v6656];
      int * v5309 = v5278->mem;
      int * v5310 = v5278->cache_keys;
      int v5311 = v5310[1];
      int * v5312 = v5278->cache_vals;
      int v5313 = v5312[1];
      v5309[v5311] = v5313;
      int * v5315 = v5278->cache_keys;
      int * v5316 = v5278->cache_keys;
      int v5317 = v5316[0];
      v5315[1] = v5317;
      int * v5319 = v5278->cache_vals;
      int * v5320 = v5278->cache_vals;
      int v5321 = v5320[0];
      v5319[1] = v5321;
      int * v5323 = v5278->cache_keys;
      v5323[0] = v6656;
      int * v5325 = v5278->cache_vals;
      v5325[0] = v5308;
      int v5327 = v5278->timer;
      int v6671 = v5327 + 100;
      v5278->timer = v6671;
      v5330 = v5308;
    }
    v5332 = v5330;
  }
  int * v5333 = v5278->regs;
  v5333[1] = v5332;
  struct StateT * v6630 = v5335(v5278);
  return v6630;
}

struct StateT * v12078(struct StateT * v12079) {
  int v12080 = v12079->timer;
  int v15762 = v12080 + 1;
  v12079->timer = v15762;
  int * v12082 = v12079->regs;
  int v12083 = v12082[13];
  int * v12084 = v12079->regs;
  int v12085 = v12084[7];
  int * v12086 = v12079->regs;
  int v15768 = v12083 + v12085;
  v12086[13] = v15768;
  struct StateT * v15760 = v12088(v12079);
  return v15760;
}

struct StateT * v2921(struct StateT * v2922) {
  int v2923 = v2922->timer;
  int v21004 = v2923 + 1;
  v2922->timer = v21004;
  int * v2925 = v2922->regs;
  int v2926 = v2925[16];
  int * v2927 = v2922->regs;
  int v21009 = (int)((unsigned int)v2926 >> 25);
  v2927[5] = v21009;
  struct StateT * v21002 = v2929(v2922);
  return v21002;
}

struct StateT * v10159(struct StateT * v10160) {
  int v10161 = v10160->timer;
  int v17848 = v10161 + 1;
  v10160->timer = v17848;
  int * v10163 = v10160->regs;
  int v10164 = v10163[18];
  int * v10165 = v10160->regs;
  int v17853 = (int)((unsigned int)v10164 >> 25);
  v10165[20] = v17853;
  struct StateT * v17846 = v10167(v10160);
  return v17846;
}

struct StateT * v9687(struct StateT * v9688) {
  int v9689 = v9688->timer;
  int v18384 = v9689 + 1;
  v9688->timer = v18384;
  int * v9691 = v9688->regs;
  int v9692 = v9691[26];
  int * v9693 = v9688->regs;
  int v9694 = v9693[17];
  int * v9695 = v9688->regs;
  int v18391 = v9692 + v9694;
  v9695[6] = v18391;
  struct StateT * v18382 = v9697(v9688);
  return v18382;
}

struct StateT * v2607(struct StateT * v2608) {
  int v2609 = v2608->timer;
  int v21356 = v2609 + 1;
  v2608->timer = v21356;
  int * v2611 = v2608->regs;
  int v2612 = v2611[17];
  int * v2613 = v2608->regs;
  int v2614 = v2613[6];
  int * v2615 = v2608->regs;
  int v21363 = v2612 ^ v2614;
  v2615[8] = v21363;
  struct StateT * v21354 = v2617(v2608);
  return v21354;
}

struct StateT * v9617(struct StateT * v9618) {
  int v9619 = v9618->timer;
  int v18464 = v9619 + 1;
  v9618->timer = v18464;
  int * v9621 = v9618->regs;
  int v9622 = v9621[8];
  int * v9623 = v9618->regs;
  int v9624 = v9623[9];
  int * v9625 = v9618->regs;
  int v18470 = v9622 | v9624;
  v9625[8] = v18470;
  struct StateT * v18462 = v9627(v9618);
  return v18462;
}

struct StateT * v3323(struct StateT * v3324) {
  int v3325 = v3324->timer;
  int v20537 = v3325 + 1;
  v3324->timer = v20537;
  int * v3327 = v3324->regs;
  int v3328 = v3327[8];
  int * v3329 = v3324->regs;
  int v20541 = v3328 << 13;
  v3329[8] = v20541;
  struct StateT * v20535 = v3331(v3324);
  return v20535;
}

struct StateT * v2955(struct StateT * v2956) {
  int v2957 = v2956->timer;
  int v20965 = v2957 + 1;
  v2956->timer = v20965;
  int * v2959 = v2956->regs;
  int v2960 = v2959[17];
  int * v2961 = v2956->regs;
  int v20969 = v2960 << 7;
  v2961[17] = v20969;
  struct StateT * v20963 = v2963(v2956);
  return v20963;
}

struct StateT * v8865(struct StateT * v8866) {
  int v8867 = v8866->timer;
  int v19341 = v8867 + 1;
  v8866->timer = v19341;
  int * v8869 = v8866->regs;
  int v8870 = v8869[18];
  int * v8871 = v8866->regs;
  int v19346 = (int)((unsigned int)v8870 >> 23);
  v8871[20] = v19346;
  struct StateT * v19339 = v8873(v8866);
  return v19339;
}

struct StateT * v11189(struct StateT * v11190) {
  int v11191 = v11190->timer;
  int v16678 = v11191 + 1;
  v11190->timer = v16678;
  int * v11193 = v11190->regs;
  int v11194 = v11193[8];
  int * v11195 = v11190->regs;
  int v11196 = v11195[9];
  int * v11197 = v11190->regs;
  int v16684 = v11194 | v11196;
  v11197[8] = v16684;
  struct StateT * v16676 = v11199(v11190);
  return v16676;
}

struct StateT * v11181(struct StateT * v11182) {
  int v11183 = v11182->timer;
  int v16689 = v11183 + 1;
  v11182->timer = v16689;
  int * v11185 = v11182->regs;
  int v11186 = v11185[8];
  int * v11187 = v11182->regs;
  int v16693 = v11186 << 9;
  v11187[8] = v16693;
  struct StateT * v16687 = v11189(v11182);
  return v16687;
}

struct StateT * v3769(struct StateT * v3770) {
  int v3771 = v3770->timer;
  int v7975 = v3771 + 1;
  v3770->timer = v7975;
  int * v3773 = v3770->regs;
  int v3774 = v3773[12];
  int * v3775 = v3770->regs;
  int v3776 = v3775[6];
  int * v3777 = v3770->regs;
  int v7981 = v3774 + v3776;
  v3777[12] = v7981;
  struct StateT * v7973 = v3779(v3770);
  return v7973;
}

struct StateT * v2491(struct StateT * v2492) {
  int v2493 = v2492->timer;
  int v21490 = v2493 + 1;
  v2492->timer = v21490;
  int * v2495 = v2492->regs;
  int v2496 = v2495[8];
  int * v2497 = v2492->regs;
  int v21495 = (int)((unsigned int)v2496 >> 19);
  v2497[20] = v21495;
  struct StateT * v21488 = v2499(v2492);
  return v21488;
}

struct StateT * v11209(struct StateT * v11210) {
  int v11211 = v11210->timer;
  int v16656 = v11211 + 1;
  v11210->timer = v16656;
  int * v11213 = v11210->regs;
  int v11214 = v11213[25];
  int * v11215 = v11210->regs;
  int v11216 = v11215[15];
  int * v11217 = v11210->regs;
  int v16662 = v11214 ^ v11216;
  v11217[25] = v16662;
  struct StateT * v16654 = v11219(v11210);
  return v16654;
}

struct StateT * v11800(struct StateT * v11801) {
  int v11802 = v11801->timer;
  int v16006 = v11802 + 1;
  v11801->timer = v16006;
  int * v11804 = v11801->regs;
  int v11805 = v11804[12];
  int * v11806 = v11801->regs;
  int v11807 = v11806[6];
  int * v11808 = v11801->regs;
  int v16012 = v11805 + v11807;
  v11808[12] = v16012;
  struct StateT * v16004 = v11810(v11801);
  return v16004;
}

struct StateT * v10341(struct StateT * v10342) {
  int v10343 = v10342->timer;
  int v17645 = v10343 + 1;
  v10342->timer = v17645;
  int * v10345 = v10342->regs;
  int v10346 = v10345[8];
  int * v10347 = v10342->regs;
  int v17649 = v10346 << 9;
  v10347[8] = v17649;
  struct StateT * v17643 = v10349(v10342);
  return v17643;
}

struct StateT * v11816(struct StateT * v11817) {
  int v11818 = v11817->timer;
  int v15950 = v11818 + 1;
  v11817->timer = v15950;
  int * v11820 = v11817->regs;
  int v11821 = v11820[2];
  int * v11822 = v11817->cache_keys;
  int v11823 = v11822[0];
  bool v15955 = v11823 == ((int)((unsigned int)(v11821 + 12) >> 2));
  int v11871;
  if (v15955) {
    int * v11824 = v11817->cache_vals;
    int v11825 = v11824[0];
    v11871 = v11825;
  } else {
    int * v11827 = v11817->cache_keys;
    int v11828 = v11827[1];
    bool v15960 = v11828 == ((int)((unsigned int)(v11821 + 12) >> 2));
    int v11869;
    if (v15960) {
      int * v11829 = v11817->cache_vals;
      int v11830 = v11829[1];
      int * v11831 = v11817->cache_keys;
      int * v11832 = v11817->cache_keys;
      int v11833 = v11832[0];
      v11831[1] = v11833;
      int * v11835 = v11817->cache_vals;
      int * v11836 = v11817->cache_vals;
      int v11837 = v11836[0];
      v11835[1] = v11837;
      int * v11839 = v11817->cache_keys;
      int v15969 = (int)((unsigned int)(v11821 + 12) >> 2);
      v11839[0] = v15969;
      int * v11841 = v11817->cache_vals;
      v11841[0] = v11830;
      int v11843 = v11817->timer;
      int v15972 = v11843 + 1;
      v11817->timer = v15972;
      v11869 = v11830;
    } else {
      int * v11846 = v11817->mem;
      int v15974 = (int)((unsigned int)(v11821 + 12) >> 2);
      int v11847 = v11846[v15974];
      int * v11848 = v11817->mem;
      int * v11849 = v11817->cache_keys;
      int v11850 = v11849[1];
      int * v11851 = v11817->cache_vals;
      int v11852 = v11851[1];
      v11848[v11850] = v11852;
      int * v11854 = v11817->cache_keys;
      int * v11855 = v11817->cache_keys;
      int v11856 = v11855[0];
      v11854[1] = v11856;
      int * v11858 = v11817->cache_vals;
      int * v11859 = v11817->cache_vals;
      int v11860 = v11859[0];
      v11858[1] = v11860;
      int * v11862 = v11817->cache_keys;
      v11862[0] = v15974;
      int * v11864 = v11817->cache_vals;
      v11864[0] = v11847;
      int v11866 = v11817->timer;
      int v15989 = v11866 + 100;
      v11817->timer = v15989;
      v11869 = v11847;
    }
    v11871 = v11869;
  }
  int * v11872 = v11817->regs;
  v11872[7] = v11871;
  struct StateT * v15948 = v11874(v11817);
  return v15948;
}

struct StateT * v3545(struct StateT * v3546) {
  int v3547 = v3546->timer;
  int v20280 = v3547 + 1;
  v3546->timer = v20280;
  int * v3549 = v3546->regs;
  int v3550 = v3549[19];
  int * v3551 = v3546->regs;
  int v3552 = v3551[6];
  int * v3553 = v3546->regs;
  int v20286 = v3550 ^ v3552;
  v3553[19] = v20286;
  struct StateT * v20278 = v3555(v3546);
  return v20278;
}

struct StateT * v11331(struct StateT * v11332) {
  int v11333 = v11332->timer;
  int v16516 = v11333 + 1;
  v11332->timer = v16516;
  int * v11335 = v11332->regs;
  int v11336 = v11335[6];
  int * v11337 = v11332->regs;
  int v16521 = (int)((unsigned int)v11336 >> 19);
  v11337[9] = v16521;
  struct StateT * v16514 = v11339(v11332);
  return v16514;
}

struct StateT * v8891(struct StateT * v8892) {
  int v8893 = v8892->timer;
  int v19310 = v8893 + 1;
  v8892->timer = v19310;
  int * v8895 = v8892->regs;
  int v8896 = v8895[26];
  int * v8897 = v8892->regs;
  int v8898 = v8897[15];
  int * v8899 = v8892->regs;
  int v19316 = v8896 ^ v8898;
  v8899[26] = v19316;
  struct StateT * v19308 = v8901(v8892);
  return v19308;
}

struct StateT * v10175(struct StateT * v10176) {
  int v10177 = v10176->timer;
  int v17828 = v10177 + 1;
  v10176->timer = v17828;
  int * v10179 = v10176->regs;
  int v10180 = v10179[18];
  int * v10181 = v10176->regs;
  int v10182 = v10181[20];
  int * v10183 = v10176->regs;
  int v17834 = v10180 | v10182;
  v10183[18] = v17834;
  struct StateT * v17826 = v10185(v10176);
  return v17826;
}

struct StateT * v3489(struct StateT * v3490) {
  int v3491 = v3490->timer;
  int v20344 = v3491 + 1;
  v3490->timer = v20344;
  int * v3493 = v3490->regs;
  int v3494 = v3493[6];
  int * v3495 = v3490->regs;
  int v3496 = v3495[9];
  int * v3497 = v3490->regs;
  int v20350 = v3494 | v3496;
  v3497[6] = v20350;
  struct StateT * v20342 = v3499(v3490);
  return v20342;
}

struct StateT * v10927(struct StateT * v10928) {
  int v10929 = v10928->timer;
  int v16984 = v10929 + 1;
  v10928->timer = v16984;
  int * v10931 = v10928->regs;
  int v10932 = v10931[15];
  int * v10933 = v10928->regs;
  int v10934 = v10933[5];
  int * v10935 = v10928->regs;
  int v16990 = v10932 | v10934;
  v10935[15] = v16990;
  struct StateT * v16982 = v10937(v10928);
  return v16982;
}

struct StateT * v2849(struct StateT * v2850) {
  int v2851 = v2850->timer;
  int v21086 = v2851 + 1;
  v2850->timer = v21086;
  int * v2853 = v2850->regs;
  int v2854 = v2853[19];
  int * v2855 = v2850->regs;
  int v2856 = v2855[13];
  int * v2857 = v2850->regs;
  int v21093 = v2854 + v2856;
  v2857[16] = v21093;
  struct StateT * v21084 = v2859(v2850);
  return v21084;
}

struct StateT * v333(struct StateT * v334) {
  int v335 = v334->timer;
  int v23433 = v335 + 1;
  v334->timer = v23433;
  int * v337 = v334->regs;
  int v338 = v337[2];
  int * v339 = v334->regs;
  int v340 = v339[21];
  int * v341 = v334->cache_keys;
  int v342 = v341[0];
  bool v23440 = v342 == ((int)((unsigned int)(v338 + 68) >> 2));
  int v386;
  if (v23440) {
    int * v343 = v334->cache_vals;
    v343[0] = v340;
    v386 = v340;
  } else {
    int * v346 = v334->cache_keys;
    int v347 = v346[1];
    bool v23445 = v347 == ((int)((unsigned int)(v338 + 68) >> 2));
    int v384;
    if (v23445) {
      int * v348 = v334->cache_keys;
      int * v349 = v334->cache_keys;
      int v350 = v349[0];
      v348[1] = v350;
      int * v352 = v334->cache_vals;
      int * v353 = v334->cache_vals;
      int v354 = v353[0];
      v352[1] = v354;
      int * v356 = v334->cache_keys;
      int v23453 = (int)((unsigned int)(v338 + 68) >> 2);
      v356[0] = v23453;
      int * v358 = v334->cache_vals;
      v358[0] = v340;
      int v360 = v334->timer;
      int v23456 = v360 + 1;
      v334->timer = v23456;
      v384 = v340;
    } else {
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
      int v23469 = (int)((unsigned int)(v338 + 68) >> 2);
      v377[0] = v23469;
      int * v379 = v334->cache_vals;
      v379[0] = v340;
      int v381 = v334->timer;
      int v23472 = v381 + 100;
      v334->timer = v23472;
      v384 = v340;
    }
    v386 = v384;
  }
  struct StateT * v23431 = v387(v334);
  return v23431;
}

struct StateT * v8689(struct StateT * v8690) {
  int v8691 = v8690->timer;
  int v19544 = v8691 + 1;
  v8690->timer = v19544;
  int * v8693 = v8690->regs;
  int v8694 = v8693[8];
  int * v8695 = v8690->regs;
  int v19548 = v8694 << 7;
  v8695[8] = v19548;
  struct StateT * v19542 = v8697(v8690);
  return v19542;
}

struct StateT * v9473(struct StateT * v9474) {
  int v9475 = v9474->timer;
  int v18632 = v9475 + 1;
  v9474->timer = v18632;
  int * v9477 = v9474->regs;
  int v9478 = v9477[9];
  int * v9479 = v9474->regs;
  int v9480 = v9479[6];
  int * v9481 = v9474->regs;
  int v18639 = v9478 ^ v9480;
  v9481[16] = v18639;
  struct StateT * v18630 = v9483(v9474);
  return v18630;
}

struct StateT * v2005(struct StateT * v2006) {
  int * v2007 = v2006->saved_regs;
  int * v2008 = v2006->regs;
  int v2009 = v2008[15];
  v2007[15] = v2009;
  int v2011 = v2006->timer;
  int v22030 = v2011 + 1;
  v2006->timer = v22030;
  int * v2013 = v2006->regs;
  int v2014 = v2013[21];
  int * v2015 = v2006->regs;
  int v2016 = v2015[16];
  int * v2017 = v2006->regs;
  int v22036 = v2014 + v2016;
  v2017[15] = v22036;
  struct StateT * v22024 = v2019(v2006);
  return v22024;
}

struct StateT * v9399(struct StateT * v9400) {
  int v9401 = v9400->timer;
  int v18721 = v9401 + 1;
  v9400->timer = v18721;
  int * v9403 = v9400->regs;
  int v9404 = v9403[16];
  int * v9405 = v9400->regs;
  int v18725 = v9404 << 7;
  v9405[16] = v18725;
  struct StateT * v18719 = v9407(v9400);
  return v18719;
}

struct StateT * v1447(struct StateT * v1448) {
  int v1449 = v1448->timer;
  int v22525 = v1449 + 1;
  v1448->timer = v22525;
  int * v1451 = v1448->regs;
  int v1452 = v1451[14];
  int * v1453 = v1448->regs;
  int v22530 = v1452 + -718;
  v1453[19] = v22530;
  struct StateT * v22523 = v1455(v1448);
  return v22523;
}

struct StateT * v11742(struct StateT * v11743) {
  int v11744 = v11743->timer;
  int v16017 = v11744 + 1;
  v11743->timer = v16017;
  int * v11746 = v11743->regs;
  int v11747 = v11746[2];
  int * v11748 = v11743->cache_keys;
  int v11749 = v11748[0];
  bool v16022 = v11749 == ((int)((unsigned int)(v11747 + 8) >> 2));
  int v11797;
  if (v16022) {
    int * v11750 = v11743->cache_vals;
    int v11751 = v11750[0];
    v11797 = v11751;
  } else {
    int * v11753 = v11743->cache_keys;
    int v11754 = v11753[1];
    bool v16027 = v11754 == ((int)((unsigned int)(v11747 + 8) >> 2));
    int v11795;
    if (v16027) {
      int * v11755 = v11743->cache_vals;
      int v11756 = v11755[1];
      int * v11757 = v11743->cache_keys;
      int * v11758 = v11743->cache_keys;
      int v11759 = v11758[0];
      v11757[1] = v11759;
      int * v11761 = v11743->cache_vals;
      int * v11762 = v11743->cache_vals;
      int v11763 = v11762[0];
      v11761[1] = v11763;
      int * v11765 = v11743->cache_keys;
      int v16036 = (int)((unsigned int)(v11747 + 8) >> 2);
      v11765[0] = v16036;
      int * v11767 = v11743->cache_vals;
      v11767[0] = v11756;
      int v11769 = v11743->timer;
      int v16039 = v11769 + 1;
      v11743->timer = v16039;
      v11795 = v11756;
    } else {
      int * v11772 = v11743->mem;
      int v16041 = (int)((unsigned int)(v11747 + 8) >> 2);
      int v11773 = v11772[v16041];
      int * v11774 = v11743->mem;
      int * v11775 = v11743->cache_keys;
      int v11776 = v11775[1];
      int * v11777 = v11743->cache_vals;
      int v11778 = v11777[1];
      v11774[v11776] = v11778;
      int * v11780 = v11743->cache_keys;
      int * v11781 = v11743->cache_keys;
      int v11782 = v11781[0];
      v11780[1] = v11782;
      int * v11784 = v11743->cache_vals;
      int * v11785 = v11743->cache_vals;
      int v11786 = v11785[0];
      v11784[1] = v11786;
      int * v11788 = v11743->cache_keys;
      v11788[0] = v16041;
      int * v11790 = v11743->cache_vals;
      v11790[0] = v11773;
      int v11792 = v11743->timer;
      int v16056 = v11792 + 100;
      v11743->timer = v16056;
      v11795 = v11773;
    }
    v11797 = v11795;
  }
  int * v11798 = v11743->regs;
  v11798[6] = v11797;
  struct StateT * v16015 = v11800(v11743);
  return v16015;
}

struct StateT * v8107(struct StateT * v8108) {
  int * v8109 = v8108->saved_regs;
  int * v8110 = v8108->regs;
  int v8111 = v8110[15];
  v8109[15] = v8111;
  int v8113 = v8108->timer;
  int v20112 = v8113 + 1;
  v8108->timer = v20112;
  int * v8115 = v8108->regs;
  v8115[15] = 1634762752;
  struct StateT * v20106 = v8117(v8108);
  return v20106;
}

struct StateT * v10061(struct StateT * v10062) {
  int * v10063 = v10062->saved_regs;
  int * v10064 = v10062->regs;
  int v10065 = v10064[20];
  v10063[20] = v10065;
  int v10067 = v10062->timer;
  int v17955 = v10067 + 1;
  v10062->timer = v17955;
  int * v10069 = v10062->regs;
  int v10070 = v10069[11];
  int * v10071 = v10062->regs;
  int v10072 = v10071[23];
  int * v10073 = v10062->regs;
  int v17961 = v10070 + v10072;
  v10073[20] = v17961;
  struct StateT * v17949 = v10075(v10062);
  return v17949;
}

struct StateT * v4403(struct StateT * v4404) {
  int v4405 = v4404->timer;
  int v7399 = v4405 + 1;
  v4404->timer = v7399;
  int * v4407 = v4404->regs;
  int v4408 = v4407[22];
  int * v4409 = v4404->regs;
  int v4410 = v4409[30];
  int * v4411 = v4404->regs;
  int v7405 = v4408 + v4410;
  v4411[30] = v7405;
  struct StateT * v7397 = v4413(v4404);
  return v7397;
}

struct StateT * v2543(struct StateT * v2544) {
  int v2545 = v2544->timer;
  int v21430 = v2545 + 1;
  v2544->timer = v21430;
  int * v2547 = v2544->regs;
  int v2548 = v2547[18];
  int * v2549 = v2544->regs;
  int v21435 = (int)((unsigned int)v2548 >> 19);
  v2549[9] = v21435;
  struct StateT * v21428 = v2551(v2544);
  return v21428;
}

struct StateT * v10797(struct StateT * v10798) {
  int v10799 = v10798->timer;
  int v17130 = v10799 + 1;
  v10798->timer = v17130;
  int * v10801 = v10798->regs;
  int v10802 = v10801[5];
  int * v10803 = v10798->regs;
  int v17134 = v10802 << 18;
  v10803[5] = v17134;
  struct StateT * v17128 = v10805(v10798);
  return v17128;
}

struct StateT * v12094(struct StateT * v12095) {
  int v12096 = v12095->timer;
  int v15706 = v12096 + 1;
  v12095->timer = v15706;
  int * v12098 = v12095->regs;
  int v12099 = v12098[2];
  int * v12100 = v12095->cache_keys;
  int v12101 = v12100[0];
  bool v15711 = v12101 == ((int)((unsigned int)(v12099 + 28) >> 2));
  int v12149;
  if (v15711) {
    int * v12102 = v12095->cache_vals;
    int v12103 = v12102[0];
    v12149 = v12103;
  } else {
    int * v12105 = v12095->cache_keys;
    int v12106 = v12105[1];
    bool v15716 = v12106 == ((int)((unsigned int)(v12099 + 28) >> 2));
    int v12147;
    if (v15716) {
      int * v12107 = v12095->cache_vals;
      int v12108 = v12107[1];
      int * v12109 = v12095->cache_keys;
      int * v12110 = v12095->cache_keys;
      int v12111 = v12110[0];
      v12109[1] = v12111;
      int * v12113 = v12095->cache_vals;
      int * v12114 = v12095->cache_vals;
      int v12115 = v12114[0];
      v12113[1] = v12115;
      int * v12117 = v12095->cache_keys;
      int v15725 = (int)((unsigned int)(v12099 + 28) >> 2);
      v12117[0] = v15725;
      int * v12119 = v12095->cache_vals;
      v12119[0] = v12108;
      int v12121 = v12095->timer;
      int v15728 = v12121 + 1;
      v12095->timer = v15728;
      v12147 = v12108;
    } else {
      int * v12124 = v12095->mem;
      int v15730 = (int)((unsigned int)(v12099 + 28) >> 2);
      int v12125 = v12124[v15730];
      int * v12126 = v12095->mem;
      int * v12127 = v12095->cache_keys;
      int v12128 = v12127[1];
      int * v12129 = v12095->cache_vals;
      int v12130 = v12129[1];
      v12126[v12128] = v12130;
      int * v12132 = v12095->cache_keys;
      int * v12133 = v12095->cache_keys;
      int v12134 = v12133[0];
      v12132[1] = v12134;
      int * v12136 = v12095->cache_vals;
      int * v12137 = v12095->cache_vals;
      int v12138 = v12137[0];
      v12136[1] = v12138;
      int * v12140 = v12095->cache_keys;
      v12140[0] = v15730;
      int * v12142 = v12095->cache_vals;
      v12142[0] = v12125;
      int v12144 = v12095->timer;
      int v15745 = v12144 + 100;
      v12095->timer = v15745;
      v12147 = v12125;
    }
    v12149 = v12147;
  }
  int * v12150 = v12095->regs;
  v12150[30] = v12149;
  struct StateT * v15704 = v12152(v12095);
  return v15704;
}

struct StateT * v11305(struct StateT * v11306) {
  int v11307 = v11306->timer;
  int v16546 = v11307 + 1;
  v11306->timer = v16546;
  int * v11309 = v11306->regs;
  int v11310 = v11309[15];
  int * v11311 = v11306->regs;
  int v16551 = (int)((unsigned int)v11310 >> 19);
  v11311[9] = v16551;
  struct StateT * v16544 = v11313(v11306);
  return v16544;
}

struct StateT * v8777(struct StateT * v8778) {
  int v8779 = v8778->timer;
  int v19441 = v8779 + 1;
  v8778->timer = v19441;
  int * v8781 = v8778->regs;
  int v8782 = v8781[14];
  int * v8783 = v8778->regs;
  int v8784 = v8783[22];
  int * v8785 = v8778->regs;
  int v19448 = v8782 + v8784;
  v8785[18] = v19448;
  struct StateT * v19439 = v8787(v8778);
  return v19439;
}

struct StateT * v3779(struct StateT * v3780) {
  int v3781 = v3780->timer;
  int v7967 = v3781 + 1;
  v3780->timer = v7967;
  int * v3783 = v3780->regs;
  v3783[6] = 857759744;
  struct StateT * v7965 = v3785(v3780);
  return v7965;
}

struct StateT * v11005(struct StateT * v11006) {
  int v11007 = v11006->timer;
  int v16893 = v11007 + 1;
  v11006->timer = v16893;
  int * v11009 = v11006->regs;
  int v11010 = v11009[17];
  int * v11011 = v11006->regs;
  int v11012 = v11011[5];
  int * v11013 = v11006->regs;
  int v16900 = v11010 | v11012;
  v11013[6] = v16900;
  struct StateT * v16891 = v11015(v11006);
  return v16891;
}

struct StateT * v9861(struct StateT * v9862) {
  int v9863 = v9862->timer;
  int v18184 = v9863 + 1;
  v9862->timer = v18184;
  int * v9865 = v9862->regs;
  int v9866 = v9865[12];
  int * v9867 = v9862->regs;
  int v9868 = v9867[25];
  int * v9869 = v9862->regs;
  int v18191 = v9866 + v9868;
  v9869[15] = v18191;
  struct StateT * v18182 = v9871(v9862);
  return v18182;
}

struct StateT * v8941(struct StateT * v8942) {
  int v8943 = v8942->timer;
  int v19253 = v8943 + 1;
  v8942->timer = v19253;
  int * v8945 = v8942->regs;
  int v8946 = v8945[24];
  int * v8947 = v8942->regs;
  int v8948 = v8947[13];
  int * v8949 = v8942->regs;
  int v19260 = v8946 + v8948;
  v8949[8] = v19260;
  struct StateT * v19251 = v8951(v8942);
  return v19251;
}

struct StateT * v9373(struct StateT * v9374) {
  int v9375 = v9374->timer;
  int v18751 = v9375 + 1;
  v9374->timer = v18751;
  int * v9377 = v9374->regs;
  int v9378 = v9377[11];
  int * v9379 = v9374->regs;
  int v18755 = v9378 << 7;
  v9379[11] = v18755;
  struct StateT * v18749 = v9381(v9374);
  return v18749;
}

struct StateT * v225(struct StateT * v226) {
  int v227 = v226->timer;
  int v23523 = v227 + 1;
  v226->timer = v23523;
  int * v229 = v226->regs;
  int v230 = v229[2];
  int * v231 = v226->regs;
  int v232 = v231[19];
  int * v233 = v226->cache_keys;
  int v234 = v233[0];
  bool v23530 = v234 == ((int)((unsigned int)(v230 + 76) >> 2));
  int v278;
  if (v23530) {
    int * v235 = v226->cache_vals;
    v235[0] = v232;
    v278 = v232;
  } else {
    int * v238 = v226->cache_keys;
    int v239 = v238[1];
    bool v23535 = v239 == ((int)((unsigned int)(v230 + 76) >> 2));
    int v276;
    if (v23535) {
      int * v240 = v226->cache_keys;
      int * v241 = v226->cache_keys;
      int v242 = v241[0];
      v240[1] = v242;
      int * v244 = v226->cache_vals;
      int * v245 = v226->cache_vals;
      int v246 = v245[0];
      v244[1] = v246;
      int * v248 = v226->cache_keys;
      int v23543 = (int)((unsigned int)(v230 + 76) >> 2);
      v248[0] = v23543;
      int * v250 = v226->cache_vals;
      v250[0] = v232;
      int v252 = v226->timer;
      int v23546 = v252 + 1;
      v226->timer = v23546;
      v276 = v232;
    } else {
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
      int v23559 = (int)((unsigned int)(v230 + 76) >> 2);
      v269[0] = v23559;
      int * v271 = v226->cache_vals;
      v271[0] = v232;
      int v273 = v226->timer;
      int v23562 = v273 + 100;
      v226->timer = v23562;
      v276 = v232;
    }
    v278 = v276;
  }
  struct StateT * v23521 = v279(v226);
  return v23521;
}

struct StateT * v12434(struct StateT * v12435) {
  int v12436 = v12435->timer;
  int v15430 = v12436 + 1;
  v12435->timer = v15430;
  int * v12438 = v12435->regs;
  int v12439 = v12438[22];
  int * v12440 = v12435->regs;
  int v12441 = v12440[30];
  int * v12442 = v12435->regs;
  int v15436 = v12439 + v12441;
  v12442[30] = v15436;
  struct StateT * v15428 = v12444(v12435);
  return v15428;
}

struct StateT * v2811(struct StateT * v2812) {
  int * v2813 = v2812->saved_regs;
  int * v2814 = v2812->regs;
  int v2815 = v2814[22];
  v2813[22] = v2815;
  int v2817 = v2812->timer;
  int v21129 = v2817 + 1;
  v2812->timer = v21129;
  int * v2819 = v2812->regs;
  int v2820 = v2819[22];
  int * v2821 = v2812->regs;
  int v2822 = v2821[5];
  int * v2823 = v2812->regs;
  int v21134 = v2820 ^ v2822;
  v2823[22] = v21134;
  struct StateT * v21123 = v2825(v2812);
  return v21123;
}

struct StateT * v12298(struct StateT * v12299) {
  int v12300 = v12299->timer;
  int v15529 = v12300 + 1;
  v12299->timer = v15529;
  int * v12302 = v12299->regs;
  int v12303 = v12302[2];
  int * v12304 = v12299->cache_keys;
  int v12305 = v12304[0];
  bool v15534 = v12305 == ((int)((unsigned int)(v12303 + 40) >> 2));
  int v12353;
  if (v15534) {
    int * v12306 = v12299->cache_vals;
    int v12307 = v12306[0];
    v12353 = v12307;
  } else {
    int * v12309 = v12299->cache_keys;
    int v12310 = v12309[1];
    bool v15539 = v12310 == ((int)((unsigned int)(v12303 + 40) >> 2));
    int v12351;
    if (v15539) {
      int * v12311 = v12299->cache_vals;
      int v12312 = v12311[1];
      int * v12313 = v12299->cache_keys;
      int * v12314 = v12299->cache_keys;
      int v12315 = v12314[0];
      v12313[1] = v12315;
      int * v12317 = v12299->cache_vals;
      int * v12318 = v12299->cache_vals;
      int v12319 = v12318[0];
      v12317[1] = v12319;
      int * v12321 = v12299->cache_keys;
      int v15548 = (int)((unsigned int)(v12303 + 40) >> 2);
      v12321[0] = v15548;
      int * v12323 = v12299->cache_vals;
      v12323[0] = v12312;
      int v12325 = v12299->timer;
      int v15551 = v12325 + 1;
      v12299->timer = v15551;
      v12351 = v12312;
    } else {
      int * v12328 = v12299->mem;
      int v15553 = (int)((unsigned int)(v12303 + 40) >> 2);
      int v12329 = v12328[v15553];
      int * v12330 = v12299->mem;
      int * v12331 = v12299->cache_keys;
      int v12332 = v12331[1];
      int * v12333 = v12299->cache_vals;
      int v12334 = v12333[1];
      v12330[v12332] = v12334;
      int * v12336 = v12299->cache_keys;
      int * v12337 = v12299->cache_keys;
      int v12338 = v12337[0];
      v12336[1] = v12338;
      int * v12340 = v12299->cache_vals;
      int * v12341 = v12299->cache_vals;
      int v12342 = v12341[0];
      v12340[1] = v12342;
      int * v12344 = v12299->cache_keys;
      v12344[0] = v15553;
      int * v12346 = v12299->cache_vals;
      v12346[0] = v12329;
      int v12348 = v12299->timer;
      int v15568 = v12348 + 100;
      v12299->timer = v15568;
      v12351 = v12329;
    }
    v12353 = v12351;
  }
  int * v12354 = v12299->regs;
  v12354[30] = v12353;
  struct StateT * v15527 = v12356(v12299);
  return v15527;
}

struct StateT * v1691(struct StateT * v1692) {
  int v1693 = v1692->timer;
  int v22276 = v1693 + 1;
  v1692->timer = v22276;
  int * v1695 = v1692->regs;
  int v1696 = v1695[2];
  int * v1697 = v1692->regs;
  int v1698 = v1697[24];
  int * v1699 = v1692->cache_keys;
  int v1700 = v1699[0];
  bool v22283 = v1700 == ((int)((unsigned int)(v1696 + 36) >> 2));
  int v1744;
  if (v22283) {
    int * v1701 = v1692->cache_vals;
    v1701[0] = v1698;
    v1744 = v1698;
  } else {
    int * v1704 = v1692->cache_keys;
    int v1705 = v1704[1];
    bool v22288 = v1705 == ((int)((unsigned int)(v1696 + 36) >> 2));
    int v1742;
    if (v22288) {
      int * v1706 = v1692->cache_keys;
      int * v1707 = v1692->cache_keys;
      int v1708 = v1707[0];
      v1706[1] = v1708;
      int * v1710 = v1692->cache_vals;
      int * v1711 = v1692->cache_vals;
      int v1712 = v1711[0];
      v1710[1] = v1712;
      int * v1714 = v1692->cache_keys;
      int v22296 = (int)((unsigned int)(v1696 + 36) >> 2);
      v1714[0] = v22296;
      int * v1716 = v1692->cache_vals;
      v1716[0] = v1698;
      int v1718 = v1692->timer;
      int v22299 = v1718 + 1;
      v1692->timer = v22299;
      v1742 = v1698;
    } else {
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
      int v22312 = (int)((unsigned int)(v1696 + 36) >> 2);
      v1735[0] = v22312;
      int * v1737 = v1692->cache_vals;
      v1737[0] = v1698;
      int v1739 = v1692->timer;
      int v22315 = v1739 + 100;
      v1692->timer = v22315;
      v1742 = v1698;
    }
    v1744 = v1742;
  }
  struct StateT * v22274 = v1745(v1692);
  return v22274;
}

struct StateT * v9793(struct StateT * v9794) {
  int v9795 = v9794->timer;
  int v18263 = v9795 + 1;
  v9794->timer = v18263;
  int * v9797 = v9794->regs;
  int v9798 = v9797[8];
  int * v9799 = v9794->regs;
  int v18267 = v9798 << 13;
  v9799[8] = v18267;
  struct StateT * v18261 = v9801(v9794);
  return v18261;
}

struct StateT * v11577(struct StateT * v11578) {
  int v11579 = v11578->timer;
  int v16231 = v11579 + 1;
  v11578->timer = v16231;
  int * v11581 = v11578->regs;
  int v11582 = v11581[20];
  int * v11583 = v11578->regs;
  int v11584 = v11583[15];
  int * v11585 = v11578->regs;
  int v16238 = v11582 ^ v11584;
  v11585[11] = v16238;
  struct StateT * v16229 = v11587(v11578);
  return v16229;
}

struct StateT * v2911(struct StateT * v2912) {
  int v2913 = v2912->timer;
  int v21014 = v2913 + 1;
  v2912->timer = v21014;
  int * v2915 = v2912->regs;
  int v2916 = v2915[11];
  int * v2917 = v2912->regs;
  int v2918 = v2917[5];
  int * v2919 = v2912->regs;
  int v21020 = v2916 | v2918;
  v2919[11] = v21020;
  struct StateT * v21012 = v2921(v2912);
  return v21012;
}

struct StateT * v2695(struct StateT * v2696) {
  int v2697 = v2696->timer;
  int v21259 = v2697 + 1;
  v2696->timer = v21259;
  int * v2699 = v2696->regs;
  int v2700 = v2699[16];
  int * v2701 = v2696->regs;
  int v21264 = (int)((unsigned int)v2700 >> 14);
  v2701[6] = v21264;
  struct StateT * v21257 = v2703(v2696);
  return v21257;
}

struct StateT * v9995(struct StateT * v9996) {
  int v9997 = v9996->timer;
  int v18029 = v9997 + 1;
  v9996->timer = v18029;
  int * v9999 = v9996->regs;
  int v10000 = v9999[21];
  int * v10001 = v9996->regs;
  int v10002 = v10001[11];
  int * v10003 = v9996->regs;
  int v18035 = v10000 ^ v10002;
  v10003[21] = v18035;
  struct StateT * v18027 = v10005(v9996);
  return v18027;
}

struct StateT * v9233(struct StateT * v9234) {
  int v9235 = v9234->timer;
  int v18913 = v9235 + 1;
  v9234->timer = v18913;
  int * v9237 = v9234->regs;
  int v9238 = v9237[5];
  int * v9239 = v9234->regs;
  int v18918 = (int)((unsigned int)v9238 >> 14);
  v9239[6] = v18918;
  struct StateT * v18911 = v9241(v9234);
  return v18911;
}

struct StateT * v4899(struct StateT * v4900) {
  int v4901 = v4900->timer;
  int v6949 = v4901 + 1;
  v4900->timer = v6949;
  int * v4903 = v4900->regs;
  int v4904 = v4903[10];
  int * v4905 = v4900->regs;
  int v4906 = v4905[13];
  int * v4907 = v4900->cache_keys;
  int v4908 = v4907[0];
  bool v6956 = v4908 == ((int)((unsigned int)(v4904 + 36) >> 2));
  int v4952;
  if (v6956) {
    int * v4909 = v4900->cache_vals;
    v4909[0] = v4906;
    v4952 = v4906;
  } else {
    int * v4912 = v4900->cache_keys;
    int v4913 = v4912[1];
    bool v6961 = v4913 == ((int)((unsigned int)(v4904 + 36) >> 2));
    int v4950;
    if (v6961) {
      int * v4914 = v4900->cache_keys;
      int * v4915 = v4900->cache_keys;
      int v4916 = v4915[0];
      v4914[1] = v4916;
      int * v4918 = v4900->cache_vals;
      int * v4919 = v4900->cache_vals;
      int v4920 = v4919[0];
      v4918[1] = v4920;
      int * v4922 = v4900->cache_keys;
      int v6969 = (int)((unsigned int)(v4904 + 36) >> 2);
      v4922[0] = v6969;
      int * v4924 = v4900->cache_vals;
      v4924[0] = v4906;
      int v4926 = v4900->timer;
      int v6972 = v4926 + 1;
      v4900->timer = v6972;
      v4950 = v4906;
    } else {
      int * v4929 = v4900->mem;
      int * v4930 = v4900->cache_keys;
      int v4931 = v4930[1];
      int * v4932 = v4900->cache_vals;
      int v4933 = v4932[1];
      v4929[v4931] = v4933;
      int * v4935 = v4900->cache_keys;
      int * v4936 = v4900->cache_keys;
      int v4937 = v4936[0];
      v4935[1] = v4937;
      int * v4939 = v4900->cache_vals;
      int * v4940 = v4900->cache_vals;
      int v4941 = v4940[0];
      v4939[1] = v4941;
      int * v4943 = v4900->cache_keys;
      int v6985 = (int)((unsigned int)(v4904 + 36) >> 2);
      v4943[0] = v6985;
      int * v4945 = v4900->cache_vals;
      v4945[0] = v4906;
      int v4947 = v4900->timer;
      int v6988 = v4947 + 100;
      v4900->timer = v6988;
      v4950 = v4906;
    }
    v4952 = v4950;
  }
  struct StateT * v6947 = v4953(v4900);
  return v6947;
}

struct StateT * v9339(struct StateT * v9340) {
  int v9341 = v9340->timer;
  int v18790 = v9341 + 1;
  v9340->timer = v18790;
  int * v9343 = v9340->regs;
  int v9344 = v9343[15];
  int * v9345 = v9340->regs;
  int v18795 = (int)((unsigned int)v9344 >> 25);
  v9345[5] = v18795;
  struct StateT * v18788 = v9347(v9340);
  return v18788;
}

struct StateT * v11129(struct StateT * v11130) {
  int v11131 = v11130->timer;
  int v16749 = v11131 + 1;
  v11130->timer = v16749;
  int * v11133 = v11130->regs;
  int v11134 = v11133[15];
  int * v11135 = v11130->regs;
  int v16753 = v11134 << 9;
  v11135[15] = v16753;
  struct StateT * v16747 = v11137(v11130);
  return v16747;
}

struct StateT * v2573(struct StateT * v2574) {
  int v2575 = v2574->timer;
  int v21394 = v2575 + 1;
  v2574->timer = v21394;
  int * v2577 = v2574->regs;
  int v2578 = v2577[16];
  int * v2579 = v2574->regs;
  int v2580 = v2579[15];
  int * v2581 = v2574->regs;
  int v21401 = v2578 ^ v2580;
  v2581[9] = v21401;
  struct StateT * v21392 = v2583(v2574);
  return v21392;
}

struct StateT * v9811(struct StateT * v9812) {
  int v9813 = v9812->timer;
  int v18241 = v9813 + 1;
  v9812->timer = v18241;
  int * v9815 = v9812->regs;
  int v9816 = v9815[14];
  int * v9817 = v9812->regs;
  int v9818 = v9817[11];
  int * v9819 = v9812->regs;
  int v18247 = v9816 ^ v9818;
  v9819[14] = v18247;
  struct StateT * v18239 = v9821(v9812);
  return v18239;
}

struct StateT * v9241(struct StateT * v9242) {
  int v9243 = v9242->timer;
  int v18904 = v9243 + 1;
  v9242->timer = v18904;
  int * v9245 = v9242->regs;
  int v9246 = v9245[5];
  int * v9247 = v9242->regs;
  int v18908 = v9246 << 18;
  v9247[5] = v18908;
  struct StateT * v18902 = v9249(v9242);
  return v18902;
}

struct StateT * v2047(struct StateT * v2048) {
  int * v2049 = v2048->saved_regs;
  int * v2050 = v2048->regs;
  int v2051 = v2050[8];
  v2049[8] = v2051;
  int v2053 = v2048->timer;
  int v21985 = v2053 + 1;
  v2048->timer = v21985;
  int * v2055 = v2048->regs;
  int v2056 = v2055[22];
  int * v2057 = v2048->regs;
  int v2058 = v2057[17];
  int * v2059 = v2048->regs;
  int v21991 = v2056 + v2058;
  v2059[8] = v21991;
  struct StateT * v21979 = v2061(v2048);
  return v21979;
}

struct StateT * v11239(struct StateT * v11240) {
  int v11241 = v11240->timer;
  int v16622 = v11241 + 1;
  v11240->timer = v16622;
  int * v11243 = v11240->regs;
  int v11244 = v11243[27];
  int * v11245 = v11240->regs;
  int v11246 = v11245[23];
  int * v11247 = v11240->regs;
  int v16629 = v11244 + v11246;
  v11247[11] = v16629;
  struct StateT * v16620 = v11249(v11240);
  return v16620;
}

struct StateT * v12822(struct StateT * v12823) {
  int v12824 = v12823->timer;
  int v15070 = v12824 + 1;
  v12823->timer = v15070;
  int * v12826 = v12823->regs;
  int v12827 = v12826[10];
  int * v12828 = v12823->regs;
  int v12829 = v12828[25];
  int * v12830 = v12823->cache_keys;
  int v12831 = v12830[0];
  bool v15077 = v12831 == ((int)((unsigned int)(v12827 + 28) >> 2));
  int v12875;
  if (v15077) {
    int * v12832 = v12823->cache_vals;
    v12832[0] = v12829;
    v12875 = v12829;
  } else {
    int * v12835 = v12823->cache_keys;
    int v12836 = v12835[1];
    bool v15082 = v12836 == ((int)((unsigned int)(v12827 + 28) >> 2));
    int v12873;
    if (v15082) {
      int * v12837 = v12823->cache_keys;
      int * v12838 = v12823->cache_keys;
      int v12839 = v12838[0];
      v12837[1] = v12839;
      int * v12841 = v12823->cache_vals;
      int * v12842 = v12823->cache_vals;
      int v12843 = v12842[0];
      v12841[1] = v12843;
      int * v12845 = v12823->cache_keys;
      int v15090 = (int)((unsigned int)(v12827 + 28) >> 2);
      v12845[0] = v15090;
      int * v12847 = v12823->cache_vals;
      v12847[0] = v12829;
      int v12849 = v12823->timer;
      int v15093 = v12849 + 1;
      v12823->timer = v15093;
      v12873 = v12829;
    } else {
      int * v12852 = v12823->mem;
      int * v12853 = v12823->cache_keys;
      int v12854 = v12853[1];
      int * v12855 = v12823->cache_vals;
      int v12856 = v12855[1];
      v12852[v12854] = v12856;
      int * v12858 = v12823->cache_keys;
      int * v12859 = v12823->cache_keys;
      int v12860 = v12859[0];
      v12858[1] = v12860;
      int * v12862 = v12823->cache_vals;
      int * v12863 = v12823->cache_vals;
      int v12864 = v12863[0];
      v12862[1] = v12864;
      int * v12866 = v12823->cache_keys;
      int v15106 = (int)((unsigned int)(v12827 + 28) >> 2);
      v12866[0] = v15106;
      int * v12868 = v12823->cache_vals;
      v12868[0] = v12829;
      int v12870 = v12823->timer;
      int v15109 = v12870 + 100;
      v12823->timer = v15109;
      v12873 = v12829;
    }
    v12875 = v12873;
  }
  struct StateT * v15068 = v12876(v12823);
  return v15068;
}

struct StateT * v11541(struct StateT * v11542) {
  int v11543 = v11542->timer;
  int v16274 = v11543 + 1;
  v11542->timer = v16274;
  int * v11545 = v11542->regs;
  int v11546 = v11545[8];
  int * v11547 = v11542->regs;
  int v16279 = (int)((unsigned int)v11546 >> 14);
  v11547[9] = v16279;
  struct StateT * v16272 = v11549(v11542);
  return v16272;
}

struct StateT * v10659(struct StateT * v10660) {
  int v10661 = v10660->timer;
  int v17284 = v10661 + 1;
  v10660->timer = v17284;
  int * v10663 = v10660->regs;
  int v10664 = v10663[9];
  int * v10665 = v10660->regs;
  int v10666 = v10665[26];
  int * v10667 = v10660->regs;
  int v17291 = v10664 + v10666;
  v10667[15] = v17291;
  struct StateT * v17282 = v10669(v10660);
  return v17282;
}

struct StateT * v9049(struct StateT * v9050) {
  int v9051 = v9050->timer;
  int v19129 = v9051 + 1;
  v9050->timer = v19129;
  int * v9053 = v9050->regs;
  int v9054 = v9053[18];
  int * v9055 = v9050->regs;
  int v19134 = (int)((unsigned int)v9054 >> 19);
  v9055[9] = v19134;
  struct StateT * v19127 = v9057(v9050);
  return v19127;
}

struct StateT * v2963(struct StateT * v2964) {
  int v2965 = v2964->timer;
  int v20953 = v2965 + 1;
  v2964->timer = v20953;
  int * v2967 = v2964->regs;
  int v2968 = v2967[17];
  int * v2969 = v2964->regs;
  int v2970 = v2969[5];
  int * v2971 = v2964->regs;
  int v20960 = v2968 | v2970;
  v2971[6] = v20960;
  struct StateT * v20951 = v2973(v2964);
  return v20951;
}

struct StateT * v8645(struct StateT * v8646) {
  int v8647 = v8646->timer;
  int v19593 = v8647 + 1;
  v8646->timer = v19593;
  int * v8649 = v8646->regs;
  int v8650 = v8649[20];
  int * v8651 = v8646->regs;
  int v8652 = v8651[9];
  int * v8653 = v8646->regs;
  int v19599 = v8650 | v8652;
  v8653[9] = v19599;
  struct StateT * v19591 = v8655(v8646);
  return v19591;
}

struct StateT * v9391(struct StateT * v9392) {
  int v9393 = v9392->timer;
  int v18730 = v9393 + 1;
  v9392->timer = v18730;
  int * v9395 = v9392->regs;
  int v9396 = v9395[16];
  int * v9397 = v9392->regs;
  int v18735 = (int)((unsigned int)v9396 >> 25);
  v9397[5] = v18735;
  struct StateT * v18728 = v9399(v9392);
  return v18728;
}

struct StateT * v2033(struct StateT * v2034) {
  int * v2035 = v2034->saved_regs;
  int * v2036 = v2034->regs;
  int v2037 = v2036[18];
  v2035[18] = v2037;
  int v2039 = v2034->timer;
  int v22000 = v2039 + 1;
  v2034->timer = v22000;
  int * v2041 = v2034->regs;
  int v2042 = v2041[19];
  int * v2043 = v2034->regs;
  int v2044 = v2043[5];
  int * v2045 = v2034->regs;
  int v22006 = v2042 + v2044;
  v2045[18] = v22006;
  struct StateT * v21994 = v2047(v2034);
  return v21994;
}

struct StateT * v3105(struct StateT * v3106) {
  int v3107 = v3106->timer;
  int v20788 = v3107 + 1;
  v3106->timer = v20788;
  int * v3109 = v3106->regs;
  int v3110 = v3109[6];
  int * v3111 = v3106->regs;
  int v20793 = (int)((unsigned int)v3110 >> 23);
  v3111[9] = v20793;
  struct StateT * v20786 = v3113(v3106);
  return v20786;
}

struct StateT * v5007(struct StateT * v5008) {
  int v5009 = v5008->timer;
  int v6859 = v5009 + 1;
  v5008->timer = v6859;
  int * v5011 = v5008->regs;
  int v5012 = v5011[10];
  int * v5013 = v5008->regs;
  int v5014 = v5013[17];
  int * v5015 = v5008->cache_keys;
  int v5016 = v5015[0];
  bool v6866 = v5016 == ((int)((unsigned int)(v5012 + 44) >> 2));
  int v5060;
  if (v6866) {
    int * v5017 = v5008->cache_vals;
    v5017[0] = v5014;
    v5060 = v5014;
  } else {
    int * v5020 = v5008->cache_keys;
    int v5021 = v5020[1];
    bool v6871 = v5021 == ((int)((unsigned int)(v5012 + 44) >> 2));
    int v5058;
    if (v6871) {
      int * v5022 = v5008->cache_keys;
      int * v5023 = v5008->cache_keys;
      int v5024 = v5023[0];
      v5022[1] = v5024;
      int * v5026 = v5008->cache_vals;
      int * v5027 = v5008->cache_vals;
      int v5028 = v5027[0];
      v5026[1] = v5028;
      int * v5030 = v5008->cache_keys;
      int v6879 = (int)((unsigned int)(v5012 + 44) >> 2);
      v5030[0] = v6879;
      int * v5032 = v5008->cache_vals;
      v5032[0] = v5014;
      int v5034 = v5008->timer;
      int v6882 = v5034 + 1;
      v5008->timer = v6882;
      v5058 = v5014;
    } else {
      int * v5037 = v5008->mem;
      int * v5038 = v5008->cache_keys;
      int v5039 = v5038[1];
      int * v5040 = v5008->cache_vals;
      int v5041 = v5040[1];
      v5037[v5039] = v5041;
      int * v5043 = v5008->cache_keys;
      int * v5044 = v5008->cache_keys;
      int v5045 = v5044[0];
      v5043[1] = v5045;
      int * v5047 = v5008->cache_vals;
      int * v5048 = v5008->cache_vals;
      int v5049 = v5048[0];
      v5047[1] = v5049;
      int * v5051 = v5008->cache_keys;
      int v6895 = (int)((unsigned int)(v5012 + 44) >> 2);
      v5051[0] = v6895;
      int * v5053 = v5008->cache_vals;
      v5053[0] = v5014;
      int v5055 = v5008->timer;
      int v6898 = v5055 + 100;
      v5008->timer = v6898;
      v5058 = v5014;
    }
    v5060 = v5058;
  }
  struct StateT * v6857 = v5061(v5008);
  return v6857;
}

struct StateT * v4467(struct StateT * v4468) {
  int v4469 = v4468->timer;
  int v7309 = v4469 + 1;
  v4468->timer = v7309;
  int * v4471 = v4468->regs;
  int v4472 = v4471[10];
  int * v4473 = v4468->regs;
  int v4474 = v4473[29];
  int * v4475 = v4468->cache_keys;
  int v4476 = v4475[0];
  bool v7316 = v4476 == ((int)((unsigned int)(v4472 + 4) >> 2));
  int v4520;
  if (v7316) {
    int * v4477 = v4468->cache_vals;
    v4477[0] = v4474;
    v4520 = v4474;
  } else {
    int * v4480 = v4468->cache_keys;
    int v4481 = v4480[1];
    bool v7321 = v4481 == ((int)((unsigned int)(v4472 + 4) >> 2));
    int v4518;
    if (v7321) {
      int * v4482 = v4468->cache_keys;
      int * v4483 = v4468->cache_keys;
      int v4484 = v4483[0];
      v4482[1] = v4484;
      int * v4486 = v4468->cache_vals;
      int * v4487 = v4468->cache_vals;
      int v4488 = v4487[0];
      v4486[1] = v4488;
      int * v4490 = v4468->cache_keys;
      int v7329 = (int)((unsigned int)(v4472 + 4) >> 2);
      v4490[0] = v7329;
      int * v4492 = v4468->cache_vals;
      v4492[0] = v4474;
      int v4494 = v4468->timer;
      int v7332 = v4494 + 1;
      v4468->timer = v7332;
      v4518 = v4474;
    } else {
      int * v4497 = v4468->mem;
      int * v4498 = v4468->cache_keys;
      int v4499 = v4498[1];
      int * v4500 = v4468->cache_vals;
      int v4501 = v4500[1];
      v4497[v4499] = v4501;
      int * v4503 = v4468->cache_keys;
      int * v4504 = v4468->cache_keys;
      int v4505 = v4504[0];
      v4503[1] = v4505;
      int * v4507 = v4468->cache_vals;
      int * v4508 = v4468->cache_vals;
      int v4509 = v4508[0];
      v4507[1] = v4509;
      int * v4511 = v4468->cache_keys;
      int v7345 = (int)((unsigned int)(v4472 + 4) >> 2);
      v4511[0] = v7345;
      int * v4513 = v4468->cache_vals;
      v4513[0] = v4474;
      int v4515 = v4468->timer;
      int v7348 = v4515 + 100;
      v4468->timer = v7348;
      v4518 = v4474;
    }
    v4520 = v4518;
  }
  struct StateT * v7307 = v4521(v4468);
  return v7307;
}

struct StateT * v2559(struct StateT * v2560) {
  int * v2561 = v2560->saved_regs;
  int * v2562 = v2560->regs;
  int v2563 = v2562[6];
  v2561[6] = v2563;
  int v2565 = v2560->timer;
  int v21410 = v2565 + 1;
  v2560->timer = v21410;
  int * v2567 = v2560->regs;
  int v2568 = v2567[18];
  int * v2569 = v2560->regs;
  int v2570 = v2569[9];
  int * v2571 = v2560->regs;
  int v21416 = v2568 | v2570;
  v2571[6] = v21416;
  struct StateT * v21404 = v2573(v2560);
  return v21404;
}

struct StateT * v8747(struct StateT * v8748) {
  int v8749 = v8748->timer;
  int v19477 = v8749 + 1;
  v8748->timer = v19477;
  int * v8751 = v8748->regs;
  int v8752 = v8751[12];
  int * v8753 = v8748->regs;
  int v8754 = v8753[21];
  int * v8755 = v8748->regs;
  int v19484 = v8752 + v8754;
  v8755[15] = v19484;
  struct StateT * v19475 = v8757(v8748);
  return v19475;
}

struct StateT * v10411(struct StateT * v10412) {
  int * v10413 = v10412->saved_regs;
  int * v10414 = v10412->regs;
  int v10415 = v10414[26];
  v10413[26] = v10415;
  int v10417 = v10412->timer;
  int v17564 = v10417 + 1;
  v10412->timer = v17564;
  int * v10419 = v10412->regs;
  int v10420 = v10419[26];
  int * v10421 = v10412->regs;
  int v10422 = v10421[15];
  int * v10423 = v10412->regs;
  int v17569 = v10420 ^ v10422;
  v10423[26] = v17569;
  struct StateT * v17558 = v10425(v10412);
  return v17558;
}

struct StateT * v11413(struct StateT * v11414) {
  int v11415 = v11414->timer;
  int v16422 = v11415 + 1;
  v11414->timer = v16422;
  int * v11417 = v11414->regs;
  int v11418 = v11417[1];
  int * v11419 = v11414->regs;
  int v11420 = v11419[8];
  int * v11421 = v11414->regs;
  int v16428 = v11418 ^ v11420;
  v11421[1] = v16428;
  struct StateT * v16420 = v11423(v11414);
  return v16420;
}

struct StateT * v11557(struct StateT * v11558) {
  int v11559 = v11558->timer;
  int v16254 = v11559 + 1;
  v11558->timer = v16254;
  int * v11561 = v11558->regs;
  int v11562 = v11561[8];
  int * v11563 = v11558->regs;
  int v11564 = v11563[9];
  int * v11565 = v11558->regs;
  int v16260 = v11562 | v11564;
  v11565[8] = v16260;
  struct StateT * v16252 = v11567(v11558);
  return v16252;
}

struct StateT * v2669(struct StateT * v2670) {
  int v2671 = v2670->timer;
  int v21289 = v2671 + 1;
  v2670->timer = v21289;
  int * v2673 = v2670->regs;
  int v2674 = v2673[15];
  int * v2675 = v2670->regs;
  int v21294 = (int)((unsigned int)v2674 >> 14);
  v2675[6] = v21294;
  struct StateT * v21287 = v2677(v2670);
  return v21287;
}

struct StateT * v8563(struct StateT * v8564) {
  int v8565 = v8564->timer;
  int v19689 = v8565 + 1;
  v8564->timer = v19689;
  int * v8567 = v8564->regs;
  int v8568 = v8567[21];
  int * v8569 = v8564->regs;
  int v8570 = v8569[16];
  int * v8571 = v8564->regs;
  int v19696 = v8568 + v8570;
  v8571[15] = v19696;
  struct StateT * v19687 = v8573(v8564);
  return v19687;
}

struct StateT * v4325(struct StateT * v4326) {
  int v4327 = v4326->timer;
  int v7487 = v4327 + 1;
  v4326->timer = v7487;
  int * v4329 = v4326->regs;
  int v4330 = v4329[1];
  int * v4331 = v4326->regs;
  int v4332 = v4331[30];
  int * v4333 = v4326->regs;
  int v7493 = v4330 + v4332;
  v4333[1] = v7493;
  struct StateT * v7485 = v4335(v4326);
  return v7485;
}

struct StateT * v3237(struct StateT * v3238) {
  int v3239 = v3238->timer;
  int v20636 = v3239 + 1;
  v3238->timer = v20636;
  int * v3241 = v3238->regs;
  int v3242 = v3241[11];
  int * v3243 = v3238->regs;
  int v20641 = (int)((unsigned int)v3242 >> 19);
  v3243[9] = v20641;
  struct StateT * v20634 = v3245(v3238);
  return v20634;
}

struct StateT * v10267(struct StateT * v10268) {
  int v10269 = v10268->timer;
  int v17730 = v10269 + 1;
  v10268->timer = v17730;
  int * v10271 = v10268->regs;
  int v10272 = v10271[12];
  int * v10273 = v10268->regs;
  int v10274 = v10273[21];
  int * v10275 = v10268->regs;
  int v17737 = v10272 + v10274;
  v10275[15] = v17737;
  struct StateT * v17728 = v10277(v10268);
  return v17728;
}

struct StateT * v10639(struct StateT * v10640) {
  int v10641 = v10640->timer;
  int v17308 = v10641 + 1;
  v10640->timer = v17308;
  int * v10643 = v10640->regs;
  int v10644 = v10643[5];
  int * v10645 = v10640->regs;
  int v10646 = v10645[20];
  int * v10647 = v10640->regs;
  int v17315 = v10644 ^ v10646;
  v10647[18] = v17315;
  struct StateT * v17306 = v10649(v10640);
  return v17306;
}

struct StateT * v3555(struct StateT * v3556) {
  int v3557 = v3556->timer;
  int v20269 = v3557 + 1;
  v3556->timer = v20269;
  int * v3559 = v3556->regs;
  int v3560 = v3559[22];
  int * v3561 = v3556->regs;
  int v3562 = v3561[8];
  int * v3563 = v3556->regs;
  int v20275 = v3560 ^ v3562;
  v3563[22] = v20275;
  struct StateT * v20267 = v3565(v3556);
  return v20267;
}

struct StateT * v12366(struct StateT * v12367) {
  int v12368 = v12367->timer;
  int v15510 = v12368 + 1;
  v12367->timer = v15510;
  int * v12370 = v12367->regs;
  v12370[30] = 1797283840;
  struct StateT * v15508 = v12372(v12367);
  return v15508;
}

struct StateT * v13772(struct StateT * v13773) {
  int v13774 = v13773->timer;
  int v14279 = v13774 + 1;
  v13773->timer = v14279;
  int * v13776 = v13773->regs;
  int v13777 = v13776[2];
  int * v13778 = v13773->cache_keys;
  int v13779 = v13778[0];
  bool v14284 = v13779 == ((int)((unsigned int)(v13777 + 60) >> 2));
  int v13827;
  if (v14284) {
    int * v13780 = v13773->cache_vals;
    int v13781 = v13780[0];
    v13827 = v13781;
  } else {
    int * v13783 = v13773->cache_keys;
    int v13784 = v13783[1];
    bool v14289 = v13784 == ((int)((unsigned int)(v13777 + 60) >> 2));
    int v13825;
    if (v14289) {
      int * v13785 = v13773->cache_vals;
      int v13786 = v13785[1];
      int * v13787 = v13773->cache_keys;
      int * v13788 = v13773->cache_keys;
      int v13789 = v13788[0];
      v13787[1] = v13789;
      int * v13791 = v13773->cache_vals;
      int * v13792 = v13773->cache_vals;
      int v13793 = v13792[0];
      v13791[1] = v13793;
      int * v13795 = v13773->cache_keys;
      int v14298 = (int)((unsigned int)(v13777 + 60) >> 2);
      v13795[0] = v14298;
      int * v13797 = v13773->cache_vals;
      v13797[0] = v13786;
      int v13799 = v13773->timer;
      int v14301 = v13799 + 1;
      v13773->timer = v14301;
      v13825 = v13786;
    } else {
      int * v13802 = v13773->mem;
      int v14303 = (int)((unsigned int)(v13777 + 60) >> 2);
      int v13803 = v13802[v14303];
      int * v13804 = v13773->mem;
      int * v13805 = v13773->cache_keys;
      int v13806 = v13805[1];
      int * v13807 = v13773->cache_vals;
      int v13808 = v13807[1];
      v13804[v13806] = v13808;
      int * v13810 = v13773->cache_keys;
      int * v13811 = v13773->cache_keys;
      int v13812 = v13811[0];
      v13810[1] = v13812;
      int * v13814 = v13773->cache_vals;
      int * v13815 = v13773->cache_vals;
      int v13816 = v13815[0];
      v13814[1] = v13816;
      int * v13818 = v13773->cache_keys;
      v13818[0] = v14303;
      int * v13820 = v13773->cache_vals;
      v13820[0] = v13803;
      int v13822 = v13773->timer;
      int v14318 = v13822 + 100;
      v13773->timer = v14318;
      v13825 = v13803;
    }
    v13827 = v13825;
  }
  int * v13828 = v13773->regs;
  v13828[23] = v13827;
  struct StateT * v14277 = v13830(v13773);
  return v14277;
}

struct StateT * v10963(struct StateT * v10964) {
  int v10965 = v10964->timer;
  int v16944 = v10965 + 1;
  v10964->timer = v16944;
  int * v10967 = v10964->regs;
  int v10968 = v10967[16];
  int * v10969 = v10964->regs;
  int v16949 = (int)((unsigned int)v10968 >> 25);
  v10969[5] = v16949;
  struct StateT * v16942 = v10971(v10964);
  return v16942;
}

struct StateT * v2133(struct StateT * v2134) {
  int v2135 = v2134->timer;
  int v21888 = v2135 + 1;
  v2134->timer = v21888;
  int * v2137 = v2134->regs;
  int v2138 = v2137[18];
  int * v2139 = v2134->regs;
  int v2140 = v2139[20];
  int * v2141 = v2134->regs;
  int v21894 = v2138 | v2140;
  v2141[18] = v21894;
  struct StateT * v21886 = v2143(v2134);
  return v21886;
}

struct StateT * v11515(struct StateT * v11516) {
  int v11517 = v11516->timer;
  int v16304 = v11517 + 1;
  v11516->timer = v16304;
  int * v11519 = v11516->regs;
  int v11520 = v11519[6];
  int * v11521 = v11516->regs;
  int v16309 = (int)((unsigned int)v11520 >> 14);
  v11521[9] = v16309;
  struct StateT * v16302 = v11523(v11516);
  return v16302;
}

struct StateT * v4365(struct StateT * v4366) {
  int v4367 = v4366->timer;
  int v7443 = v4367 + 1;
  v4366->timer = v7443;
  int * v4369 = v4366->regs;
  int v4370 = v4369[30];
  int * v4371 = v4366->regs;
  int v7447 = v4370 + 1396;
  v4371[30] = v7447;
  struct StateT * v7441 = v4373(v4366);
  return v7441;
}

struct StateT * v8619(struct StateT * v8620) {
  int v8621 = v8620->timer;
  int v19623 = v8621 + 1;
  v8620->timer = v19623;
  int * v8623 = v8620->regs;
  int v8624 = v8623[15];
  int * v8625 = v8620->regs;
  int v8626 = v8625[9];
  int * v8627 = v8620->regs;
  int v19629 = v8624 | v8626;
  v8627[15] = v19629;
  struct StateT * v19621 = v8629(v8620);
  return v19621;
}

struct StateT * v11173(struct StateT * v11174) {
  int v11175 = v11174->timer;
  int v16698 = v11175 + 1;
  v11174->timer = v16698;
  int * v11177 = v11174->regs;
  int v11178 = v11177[8];
  int * v11179 = v11174->regs;
  int v16703 = (int)((unsigned int)v11178 >> 23);
  v11179[9] = v16703;
  struct StateT * v16696 = v11181(v11174);
  return v16696;
}

struct StateT * v2597(struct StateT * v2598) {
  int v2599 = v2598->timer;
  int v21368 = v2599 + 1;
  v2598->timer = v21368;
  int * v2601 = v2598->regs;
  int v2602 = v2601[5];
  int * v2603 = v2598->regs;
  int v2604 = v2603[20];
  int * v2605 = v2598->regs;
  int v21375 = v2602 ^ v2604;
  v2605[18] = v21375;
  struct StateT * v21366 = v2607(v2598);
  return v21366;
}

struct StateT * v9115(struct StateT * v9116) {
  int v9117 = v9116->timer;
  int v19049 = v9117 + 1;
  v9116->timer = v19049;
  int * v9119 = v9116->regs;
  int v9120 = v9119[9];
  int * v9121 = v9116->regs;
  int v9122 = v9121[26];
  int * v9123 = v9116->regs;
  int v19056 = v9120 + v9122;
  v9123[15] = v19056;
  struct StateT * v19047 = v9125(v9116);
  return v19047;
}

struct StateT * v8901(struct StateT * v8902) {
  int v8903 = v8902->timer;
  int v19299 = v8903 + 1;
  v8902->timer = v19299;
  int * v8905 = v8902->regs;
  int v8906 = v8905[24];
  int * v8907 = v8902->regs;
  int v8908 = v8907[8];
  int * v8909 = v8902->regs;
  int v19305 = v8906 ^ v8908;
  v8909[24] = v19305;
  struct StateT * v19297 = v8911(v8902);
  return v19297;
}

struct StateT * v10393(struct StateT * v10394) {
  int v10395 = v10394->timer;
  int v17585 = v10395 + 1;
  v10394->timer = v17585;
  int * v10397 = v10394->regs;
  int v10398 = v10397[18];
  int * v10399 = v10394->regs;
  int v17589 = v10398 << 9;
  v10399[18] = v17589;
  struct StateT * v17583 = v10401(v10394);
  return v17583;
}

struct StateT * v3197(struct StateT * v3198) {
  int v3199 = v3198->timer;
  int v20682 = v3199 + 1;
  v3198->timer = v20682;
  int * v3201 = v3198->regs;
  int v3202 = v3201[27];
  int * v3203 = v3198->regs;
  int v3204 = v3203[23];
  int * v3205 = v3198->regs;
  int v20689 = v3202 + v3204;
  v3205[11] = v20689;
  struct StateT * v20680 = v3207(v3198);
  return v20680;
}

struct StateT * v9821(struct StateT * v9822) {
  int v9823 = v9822->timer;
  int v18230 = v9823 + 1;
  v9822->timer = v18230;
  int * v9825 = v9822->regs;
  int v9826 = v9825[12];
  int * v9827 = v9822->regs;
  int v9828 = v9827[15];
  int * v9829 = v9822->regs;
  int v18236 = v9826 ^ v9828;
  v9829[12] = v18236;
  struct StateT * v18228 = v9831(v9822);
  return v18228;
}

struct StateT * v9749(struct StateT * v9750) {
  int v9751 = v9750->timer;
  int v18312 = v9751 + 1;
  v9750->timer = v18312;
  int * v9753 = v9750->regs;
  int v9754 = v9753[15];
  int * v9755 = v9750->regs;
  int v9756 = v9755[9];
  int * v9757 = v9750->regs;
  int v18318 = v9754 | v9756;
  v9757[15] = v18318;
  struct StateT * v18310 = v9759(v9750);
  return v18310;
}

struct StateT * v9065(struct StateT * v9066) {
  int v9067 = v9066->timer;
  int v19108 = v9067 + 1;
  v9066->timer = v19108;
  int * v9069 = v9066->regs;
  int v9070 = v9069[18];
  int * v9071 = v9066->regs;
  int v9072 = v9071[9];
  int * v9073 = v9066->regs;
  int v19115 = v9070 | v9072;
  v9073[6] = v19115;
  struct StateT * v19106 = v9075(v9066);
  return v19106;
}

struct StateT * v11726(struct StateT * v11727) {
  int v11728 = v11727->timer;
  int v16076 = v11728 + 1;
  v11727->timer = v16076;
  int * v11730 = v11727->regs;
  v11730[15] = 1634762752;
  struct StateT * v16074 = v11732(v11727);
  return v16074;
}

struct StateT * v10919(struct StateT * v10920) {
  int v10921 = v10920->timer;
  int v16995 = v10921 + 1;
  v10920->timer = v16995;
  int * v10923 = v10920->regs;
  int v10924 = v10923[15];
  int * v10925 = v10920->regs;
  int v16999 = v10924 << 7;
  v10925[15] = v16999;
  struct StateT * v16993 = v10927(v10920);
  return v16993;
}

struct StateT * v10239(struct StateT * v10240) {
  int * v10241 = v10240->saved_regs;
  int * v10242 = v10240->regs;
  int v10243 = v10242[1];
  v10241[1] = v10243;
  int v10245 = v10240->timer;
  int v17760 = v10245 + 1;
  v10240->timer = v17760;
  int * v10247 = v10240->regs;
  int v10248 = v10247[1];
  int * v10249 = v10240->regs;
  int v10250 = v10249[18];
  int * v10251 = v10240->regs;
  int v17765 = v10248 ^ v10250;
  v10251[1] = v17765;
  struct StateT * v17754 = v10253(v10240);
  return v17754;
}

struct StateT * v4267(struct StateT * v4268) {
  int v4269 = v4268->timer;
  int v7498 = v4269 + 1;
  v4268->timer = v7498;
  int * v4271 = v4268->regs;
  int v4272 = v4271[2];
  int * v4273 = v4268->cache_keys;
  int v4274 = v4273[0];
  bool v7503 = v4274 == ((int)((unsigned int)(v4272 + 40) >> 2));
  int v4322;
  if (v7503) {
    int * v4275 = v4268->cache_vals;
    int v4276 = v4275[0];
    v4322 = v4276;
  } else {
    int * v4278 = v4268->cache_keys;
    int v4279 = v4278[1];
    bool v7508 = v4279 == ((int)((unsigned int)(v4272 + 40) >> 2));
    int v4320;
    if (v7508) {
      int * v4280 = v4268->cache_vals;
      int v4281 = v4280[1];
      int * v4282 = v4268->cache_keys;
      int * v4283 = v4268->cache_keys;
      int v4284 = v4283[0];
      v4282[1] = v4284;
      int * v4286 = v4268->cache_vals;
      int * v4287 = v4268->cache_vals;
      int v4288 = v4287[0];
      v4286[1] = v4288;
      int * v4290 = v4268->cache_keys;
      int v7517 = (int)((unsigned int)(v4272 + 40) >> 2);
      v4290[0] = v7517;
      int * v4292 = v4268->cache_vals;
      v4292[0] = v4281;
      int v4294 = v4268->timer;
      int v7520 = v4294 + 1;
      v4268->timer = v7520;
      v4320 = v4281;
    } else {
      int * v4297 = v4268->mem;
      int v7522 = (int)((unsigned int)(v4272 + 40) >> 2);
      int v4298 = v4297[v7522];
      int * v4299 = v4268->mem;
      int * v4300 = v4268->cache_keys;
      int v4301 = v4300[1];
      int * v4302 = v4268->cache_vals;
      int v4303 = v4302[1];
      v4299[v4301] = v4303;
      int * v4305 = v4268->cache_keys;
      int * v4306 = v4268->cache_keys;
      int v4307 = v4306[0];
      v4305[1] = v4307;
      int * v4309 = v4268->cache_vals;
      int * v4310 = v4268->cache_vals;
      int v4311 = v4310[0];
      v4309[1] = v4311;
      int * v4313 = v4268->cache_keys;
      v4313[0] = v7522;
      int * v4315 = v4268->cache_vals;
      v4315[0] = v4298;
      int v4317 = v4268->timer;
      int v7537 = v4317 + 100;
      v4268->timer = v7537;
      v4320 = v4298;
    }
    v4322 = v4320;
  }
  int * v4323 = v4268->regs;
  v4323[30] = v4322;
  struct StateT * v7496 = v4325(v4268);
  return v7496;
}

struct StateT * v3499(struct StateT * v3500) {
  int v3501 = v3500->timer;
  int v20334 = v3501 + 1;
  v3500->timer = v20334;
  int * v3503 = v3500->regs;
  int v3504 = v3503[8];
  int * v3505 = v3500->regs;
  int v20339 = (int)((unsigned int)v3504 >> 14);
  v3505[9] = v20339;
  struct StateT * v20332 = v3507(v3500);
  return v20332;
}

struct StateT * v2169(struct StateT * v2170) {
  int * v2171 = v2170->saved_regs;
  int * v2172 = v2170->regs;
  int v2173 = v2172[12];
  v2171[12] = v2173;
  int v2175 = v2170->timer;
  int v21848 = v2175 + 1;
  v2170->timer = v21848;
  int * v2177 = v2170->regs;
  int v2178 = v2177[12];
  int * v2179 = v2170->regs;
  int v2180 = v2179[15];
  int * v2181 = v2170->regs;
  int v21853 = v2178 ^ v2180;
  v2181[12] = v21853;
  struct StateT * v21842 = v2183(v2170);
  return v21842;
}

struct StateT * v4953(struct StateT * v4954) {
  int v4955 = v4954->timer;
  int v6904 = v4955 + 1;
  v4954->timer = v6904;
  int * v4957 = v4954->regs;
  int v4958 = v4957[10];
  int * v4959 = v4954->regs;
  int v4960 = v4959[7];
  int * v4961 = v4954->cache_keys;
  int v4962 = v4961[0];
  bool v6911 = v4962 == ((int)((unsigned int)(v4958 + 40) >> 2));
  int v5006;
  if (v6911) {
    int * v4963 = v4954->cache_vals;
    v4963[0] = v4960;
    v5006 = v4960;
  } else {
    int * v4966 = v4954->cache_keys;
    int v4967 = v4966[1];
    bool v6916 = v4967 == ((int)((unsigned int)(v4958 + 40) >> 2));
    int v5004;
    if (v6916) {
      int * v4968 = v4954->cache_keys;
      int * v4969 = v4954->cache_keys;
      int v4970 = v4969[0];
      v4968[1] = v4970;
      int * v4972 = v4954->cache_vals;
      int * v4973 = v4954->cache_vals;
      int v4974 = v4973[0];
      v4972[1] = v4974;
      int * v4976 = v4954->cache_keys;
      int v6924 = (int)((unsigned int)(v4958 + 40) >> 2);
      v4976[0] = v6924;
      int * v4978 = v4954->cache_vals;
      v4978[0] = v4960;
      int v4980 = v4954->timer;
      int v6927 = v4980 + 1;
      v4954->timer = v6927;
      v5004 = v4960;
    } else {
      int * v4983 = v4954->mem;
      int * v4984 = v4954->cache_keys;
      int v4985 = v4984[1];
      int * v4986 = v4954->cache_vals;
      int v4987 = v4986[1];
      v4983[v4985] = v4987;
      int * v4989 = v4954->cache_keys;
      int * v4990 = v4954->cache_keys;
      int v4991 = v4990[0];
      v4989[1] = v4991;
      int * v4993 = v4954->cache_vals;
      int * v4994 = v4954->cache_vals;
      int v4995 = v4994[0];
      v4993[1] = v4995;
      int * v4997 = v4954->cache_keys;
      int v6940 = (int)((unsigned int)(v4958 + 40) >> 2);
      v4997[0] = v6940;
      int * v4999 = v4954->cache_vals;
      v4999[0] = v4960;
      int v5001 = v4954->timer;
      int v6943 = v5001 + 100;
      v4954->timer = v6943;
      v5004 = v4960;
    }
    v5006 = v5004;
  }
  struct StateT * v6902 = v5007(v4954);
  return v6902;
}

struct StateT * v2061(struct StateT * v2062) {
  int * v2063 = v2062->saved_regs;
  int * v2064 = v2062->regs;
  int v2065 = v2064[9];
  v2063[9] = v2065;
  int v2067 = v2062->timer;
  int v21972 = v2067 + 1;
  v2062->timer = v21972;
  int * v2069 = v2062->regs;
  int v2070 = v2069[15];
  int * v2071 = v2062->regs;
  int v21976 = (int)((unsigned int)v2070 >> 25);
  v2071[9] = v21976;
  struct StateT * v21966 = v2073(v2062);
  return v21966;
}

struct StateT * v10789(struct StateT * v10790) {
  int v10791 = v10790->timer;
  int v17139 = v10791 + 1;
  v10790->timer = v17139;
  int * v10793 = v10790->regs;
  int v10794 = v10793[5];
  int * v10795 = v10790->regs;
  int v17144 = (int)((unsigned int)v10794 >> 14);
  v10795[6] = v17144;
  struct StateT * v17137 = v10797(v10790);
  return v17137;
}

struct StateT * v11199(struct StateT * v11200) {
  int v11201 = v11200->timer;
  int v16667 = v11201 + 1;
  v11200->timer = v16667;
  int * v11203 = v11200->regs;
  int v11204 = v11203[27];
  int * v11205 = v11200->regs;
  int v11206 = v11205[11];
  int * v11207 = v11200->regs;
  int v16673 = v11204 ^ v11206;
  v11207[27] = v16673;
  struct StateT * v16665 = v11209(v11200);
  return v16665;
}

struct StateT * v10515(struct StateT * v10516) {
  int v10517 = v10516->timer;
  int v17451 = v10517 + 1;
  v10516->timer = v17451;
  int * v10519 = v10516->regs;
  int v10520 = v10519[15];
  int * v10521 = v10516->regs;
  int v17455 = v10520 << 13;
  v10521[15] = v17455;
  struct StateT * v17449 = v10523(v10516);
  return v17449;
}

struct StateT * v13200(struct StateT * v13201) {
  int v13202 = v13201->timer;
  int v14756 = v13202 + 1;
  v13201->timer = v14756;
  int * v13204 = v13201->regs;
  int v13205 = v13204[10];
  int * v13206 = v13201->regs;
  int v13207 = v13206[1];
  int * v13208 = v13201->cache_keys;
  int v13209 = v13208[0];
  bool v14763 = v13209 == ((int)((unsigned int)(v13205 + 56) >> 2));
  int v13253;
  if (v14763) {
    int * v13210 = v13201->cache_vals;
    v13210[0] = v13207;
    v13253 = v13207;
  } else {
    int * v13213 = v13201->cache_keys;
    int v13214 = v13213[1];
    bool v14767 = v13214 == ((int)((unsigned int)(v13205 + 56) >> 2));
    int v13251;
    if (v14767) {
      int * v13215 = v13201->cache_keys;
      int * v13216 = v13201->cache_keys;
      int v13217 = v13216[0];
      v13215[1] = v13217;
      int * v13219 = v13201->cache_vals;
      int * v13220 = v13201->cache_vals;
      int v13221 = v13220[0];
      v13219[1] = v13221;
      int * v13223 = v13201->cache_keys;
      int v14775 = (int)((unsigned int)(v13205 + 56) >> 2);
      v13223[0] = v14775;
      int * v13225 = v13201->cache_vals;
      v13225[0] = v13207;
      int v13227 = v13201->timer;
      int v14778 = v13227 + 1;
      v13201->timer = v14778;
      v13251 = v13207;
    } else {
      int * v13230 = v13201->mem;
      int * v13231 = v13201->cache_keys;
      int v13232 = v13231[1];
      int * v13233 = v13201->cache_vals;
      int v13234 = v13233[1];
      v13230[v13232] = v13234;
      int * v13236 = v13201->cache_keys;
      int * v13237 = v13201->cache_keys;
      int v13238 = v13237[0];
      v13236[1] = v13238;
      int * v13240 = v13201->cache_vals;
      int * v13241 = v13201->cache_vals;
      int v13242 = v13241[0];
      v13240[1] = v13242;
      int * v13244 = v13201->cache_keys;
      int v14791 = (int)((unsigned int)(v13205 + 56) >> 2);
      v13244[0] = v14791;
      int * v13246 = v13201->cache_vals;
      v13246[0] = v13207;
      int v13248 = v13201->timer;
      int v14794 = v13248 + 100;
      v13201->timer = v14794;
      v13251 = v13207;
    }
    v13253 = v13251;
  }
  struct StateT * v14754 = v13254(v13201);
  return v14754;
}

struct StateT * v10901(struct StateT * v10902) {
  int v10903 = v10902->timer;
  int v17014 = v10903 + 1;
  v10902->timer = v17014;
  int * v10905 = v10902->regs;
  int v10906 = v10905[22];
  int * v10907 = v10902->regs;
  int v10908 = v10907[1];
  int * v10909 = v10902->regs;
  int v17021 = v10906 + v10908;
  v10909[17] = v17021;
  struct StateT * v17012 = v10911(v10902);
  return v17012;
}

struct StateT * v1297(struct StateT * v1298) {
  int v1299 = v1298->timer;
  int v22627 = v1299 + 1;
  v1298->timer = v22627;
  int * v1301 = v1298->regs;
  int v1302 = v1301[11];
  int * v1303 = v1298->cache_keys;
  int v1304 = v1303[0];
  bool v22632 = v1304 == ((int)((unsigned int)(v1302 + 8) >> 2));
  int v1352;
  if (v22632) {
    int * v1305 = v1298->cache_vals;
    int v1306 = v1305[0];
    v1352 = v1306;
  } else {
    int * v1308 = v1298->cache_keys;
    int v1309 = v1308[1];
    bool v22637 = v1309 == ((int)((unsigned int)(v1302 + 8) >> 2));
    int v1350;
    if (v22637) {
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
      int v22646 = (int)((unsigned int)(v1302 + 8) >> 2);
      v1320[0] = v22646;
      int * v1322 = v1298->cache_vals;
      v1322[0] = v1311;
      int v1324 = v1298->timer;
      int v22649 = v1324 + 1;
      v1298->timer = v22649;
      v1350 = v1311;
    } else {
      int * v1327 = v1298->mem;
      int v22651 = (int)((unsigned int)(v1302 + 8) >> 2);
      int v1328 = v1327[v22651];
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
      v1343[0] = v22651;
      int * v1345 = v1298->cache_vals;
      v1345[0] = v1328;
      int v1347 = v1298->timer;
      int v22666 = v1347 + 100;
      v1298->timer = v22666;
      v1350 = v1328;
    }
    v1352 = v1350;
  }
  int * v1353 = v1298->regs;
  v1353[26] = v1352;
  struct StateT * v22625 = v1355(v1298);
  return v22625;
}

struct StateT * v3315(struct StateT * v3316) {
  int v3317 = v3316->timer;
  int v20546 = v3317 + 1;
  v3316->timer = v20546;
  int * v3319 = v3316->regs;
  int v3320 = v3319[8];
  int * v3321 = v3316->regs;
  int v20551 = (int)((unsigned int)v3320 >> 19);
  v3321[9] = v20551;
  struct StateT * v20544 = v3323(v3316);
  return v20544;
}

struct StateT * v4063(struct StateT * v4064) {
  int v4065 = v4064->timer;
  int v7675 = v4065 + 1;
  v4064->timer = v7675;
  int * v4067 = v4064->regs;
  int v4068 = v4067[2];
  int * v4069 = v4064->cache_keys;
  int v4070 = v4069[0];
  bool v7680 = v4070 == ((int)((unsigned int)(v4068 + 28) >> 2));
  int v4118;
  if (v7680) {
    int * v4071 = v4064->cache_vals;
    int v4072 = v4071[0];
    v4118 = v4072;
  } else {
    int * v4074 = v4064->cache_keys;
    int v4075 = v4074[1];
    bool v7685 = v4075 == ((int)((unsigned int)(v4068 + 28) >> 2));
    int v4116;
    if (v7685) {
      int * v4076 = v4064->cache_vals;
      int v4077 = v4076[1];
      int * v4078 = v4064->cache_keys;
      int * v4079 = v4064->cache_keys;
      int v4080 = v4079[0];
      v4078[1] = v4080;
      int * v4082 = v4064->cache_vals;
      int * v4083 = v4064->cache_vals;
      int v4084 = v4083[0];
      v4082[1] = v4084;
      int * v4086 = v4064->cache_keys;
      int v7694 = (int)((unsigned int)(v4068 + 28) >> 2);
      v4086[0] = v7694;
      int * v4088 = v4064->cache_vals;
      v4088[0] = v4077;
      int v4090 = v4064->timer;
      int v7697 = v4090 + 1;
      v4064->timer = v7697;
      v4116 = v4077;
    } else {
      int * v4093 = v4064->mem;
      int v7699 = (int)((unsigned int)(v4068 + 28) >> 2);
      int v4094 = v4093[v7699];
      int * v4095 = v4064->mem;
      int * v4096 = v4064->cache_keys;
      int v4097 = v4096[1];
      int * v4098 = v4064->cache_vals;
      int v4099 = v4098[1];
      v4095[v4097] = v4099;
      int * v4101 = v4064->cache_keys;
      int * v4102 = v4064->cache_keys;
      int v4103 = v4102[0];
      v4101[1] = v4103;
      int * v4105 = v4064->cache_vals;
      int * v4106 = v4064->cache_vals;
      int v4107 = v4106[0];
      v4105[1] = v4107;
      int * v4109 = v4064->cache_keys;
      v4109[0] = v7699;
      int * v4111 = v4064->cache_vals;
      v4111[0] = v4094;
      int v4113 = v4064->timer;
      int v7714 = v4113 + 100;
      v4064->timer = v7714;
      v4116 = v4094;
    }
    v4118 = v4116;
  }
  int * v4119 = v4064->regs;
  v4119[30] = v4118;
  struct StateT * v7673 = v4121(v4064);
  return v7673;
}

struct StateT * v10167(struct StateT * v10168) {
  int v10169 = v10168->timer;
  int v17839 = v10169 + 1;
  v10168->timer = v17839;
  int * v10171 = v10168->regs;
  int v10172 = v10171[18];
  int * v10173 = v10168->regs;
  int v17843 = v10172 << 7;
  v10173[18] = v17843;
  struct StateT * v17837 = v10175(v10168);
  return v17837;
}

struct StateT * v10025(struct StateT * v10026) {
  int v10027 = v10026->timer;
  int v17995 = v10027 + 1;
  v10026->timer = v17995;
  int * v10029 = v10026->regs;
  int v10030 = v10029[22];
  int * v10031 = v10026->regs;
  int v10032 = v10031[8];
  int * v10033 = v10026->regs;
  int v18001 = v10030 ^ v10032;
  v10033[22] = v18001;
  struct StateT * v17993 = v10035(v10026);
  return v17993;
}

struct StateT * v4341(struct StateT * v4342) {
  int v4343 = v4342->timer;
  int v7470 = v4343 + 1;
  v4342->timer = v7470;
  int * v4345 = v4342->regs;
  int v4346 = v4345[15];
  int * v4347 = v4342->regs;
  int v7474 = v4346 + -1947;
  v4347[15] = v7474;
  struct StateT * v7468 = v4349(v4342);
  return v7468;
}

struct StateT * v10367(struct StateT * v10368) {
  int v10369 = v10368->timer;
  int v17615 = v10369 + 1;
  v10368->timer = v17615;
  int * v10371 = v10368->regs;
  int v10372 = v10371[9];
  int * v10373 = v10368->regs;
  int v17619 = v10372 << 9;
  v10373[9] = v17619;
  struct StateT * v17613 = v10375(v10368);
  return v17613;
}

struct StateT * v2281(struct StateT * v2282) {
  int v2283 = v2282->timer;
  int v21724 = v2283 + 1;
  v2282->timer = v21724;
  int * v2285 = v2282->regs;
  int v2286 = v2285[15];
  int * v2287 = v2282->regs;
  int v2288 = v2287[20];
  int * v2289 = v2282->regs;
  int v21730 = v2286 | v2288;
  v2289[15] = v21730;
  struct StateT * v21722 = v2291(v2282);
  return v21722;
}

struct StateT * v3033(struct StateT * v3034) {
  int v3035 = v3034->timer;
  int v20870 = v3035 + 1;
  v3034->timer = v20870;
  int * v3037 = v3034->regs;
  int v3038 = v3037[17];
  int * v3039 = v3034->regs;
  int v3040 = v3039[19];
  int * v3041 = v3034->regs;
  int v20877 = v3038 + v3040;
  v3041[6] = v20877;
  struct StateT * v20868 = v3043(v3034);
  return v20868;
}

struct StateT * v3217(struct StateT * v3218) {
  int v3219 = v3218->timer;
  int v20658 = v3219 + 1;
  v3218->timer = v20658;
  int * v3221 = v3218->regs;
  int v3222 = v3221[26];
  int * v3223 = v3218->regs;
  int v3224 = v3223[17];
  int * v3225 = v3218->regs;
  int v20665 = v3222 + v3224;
  v3225[6] = v20665;
  struct StateT * v20656 = v3227(v3218);
  return v20656;
}

struct StateT * v10425(struct StateT * v10426) {
  int * v10427 = v10426->saved_regs;
  int * v10428 = v10426->regs;
  int v10429 = v10428[24];
  v10427[24] = v10429;
  int v10431 = v10426->timer;
  int v17550 = v10431 + 1;
  v10426->timer = v17550;
  int * v10433 = v10426->regs;
  int v10434 = v10433[24];
  int * v10435 = v10426->regs;
  int v10436 = v10435[8];
  int * v10437 = v10426->regs;
  int v17555 = v10434 ^ v10436;
  v10437[24] = v17555;
  struct StateT * v17544 = v10439(v10426);
  return v17544;
}

struct StateT * v8193(struct StateT * v8194) {
  int * v8195 = v8194->saved_regs;
  int * v8196 = v8194->regs;
  int v8197 = v8196[12];
  v8195[12] = v8197;
  int v8199 = v8194->timer;
  int v20033 = v8199 + 1;
  v8194->timer = v20033;
  int * v8201 = v8194->regs;
  int v8202 = v8201[12];
  int * v8203 = v8194->regs;
  int v8204 = v8203[6];
  int * v8205 = v8194->regs;
  int v20038 = v8202 + v8204;
  v8205[12] = v20038;
  struct StateT * v20027 = v8207(v8194);
  return v20027;
}

struct StateT * v2125(struct StateT * v2126) {
  int v2127 = v2126->timer;
  int v21899 = v2127 + 1;
  v2126->timer = v21899;
  int * v2129 = v2126->regs;
  int v2130 = v2129[18];
  int * v2131 = v2126->regs;
  int v21903 = v2130 << 7;
  v2131[18] = v21903;
  struct StateT * v21897 = v2133(v2126);
  return v21897;
}

struct StateT * v11706(struct StateT * v11707) {
  int v11708 = v11707->timer;
  int v16095 = v11708 + 1;
  v11707->timer = v16095;
  int * v11710 = v11707->regs;
  int v11711 = v11710[23];
  int * v11712 = v11707->regs;
  int v11713 = v11712[29];
  int * v11714 = v11707->regs;
  int v16101 = v11711 + v11713;
  v11714[29] = v16101;
  struct StateT * v16093 = v11716(v11707);
  return v16093;
}

struct StateT * v11403(struct StateT * v11404) {
  int v11405 = v11404->timer;
  int v16433 = v11405 + 1;
  v11404->timer = v16433;
  int * v11407 = v11404->regs;
  int v11408 = v11407[13];
  int * v11409 = v11404->regs;
  int v11410 = v11409[6];
  int * v11411 = v11404->regs;
  int v16439 = v11408 ^ v11410;
  v11411[13] = v16439;
  struct StateT * v16431 = v11413(v11404);
  return v16431;
}

struct StateT * v12288(struct StateT * v12289) {
  int v12290 = v12289->timer;
  int v15577 = v12290 + 1;
  v12289->timer = v15577;
  int * v12292 = v12289->regs;
  int v12293 = v12292[24];
  int * v12294 = v12289->regs;
  int v12295 = v12294[30];
  int * v12296 = v12289->regs;
  int v15583 = v12293 + v12295;
  v12296[24] = v15583;
  struct StateT * v15575 = v12298(v12289);
  return v15575;
}

struct StateT * v3023(struct StateT * v3024) {
  int v3025 = v3024->timer;
  int v20882 = v3025 + 1;
  v3024->timer = v20882;
  int * v3027 = v3024->regs;
  int v3028 = v3027[5];
  int * v3029 = v3024->regs;
  int v3030 = v3029[20];
  int * v3031 = v3024->regs;
  int v20889 = v3028 + v3030;
  v3031[15] = v20889;
  struct StateT * v20880 = v3033(v3024);
  return v20880;
}

struct StateT * v10103(struct StateT * v10104) {
  int * v10105 = v10104->saved_regs;
  int * v10106 = v10104->regs;
  int v10107 = v10106[9];
  v10105[9] = v10107;
  int v10109 = v10104->timer;
  int v17912 = v10109 + 1;
  v10104->timer = v17912;
  int * v10111 = v10104->regs;
  int v10112 = v10111[15];
  int * v10113 = v10104->regs;
  int v17916 = (int)((unsigned int)v10112 >> 25);
  v10113[9] = v17916;
  struct StateT * v17906 = v10115(v10104);
  return v17906;
}

struct StateT * v2517(struct StateT * v2518) {
  int v2519 = v2518->timer;
  int v21460 = v2519 + 1;
  v2518->timer = v21460;
  int * v2521 = v2518->regs;
  int v2522 = v2521[9];
  int * v2523 = v2518->regs;
  int v21465 = (int)((unsigned int)v2522 >> 19);
  v2523[20] = v21465;
  struct StateT * v21458 = v2525(v2518);
  return v21458;
}

struct StateT * v12356(struct StateT * v12357) {
  int v12358 = v12357->timer;
  int v15518 = v12358 + 1;
  v12357->timer = v15518;
  int * v12360 = v12357->regs;
  int v12361 = v12360[1];
  int * v12362 = v12357->regs;
  int v12363 = v12362[30];
  int * v12364 = v12357->regs;
  int v15524 = v12361 + v12363;
  v12364[1] = v15524;
  struct StateT * v15516 = v12366(v12357);
  return v15516;
}

struct StateT * v8997(struct StateT * v8998) {
  int v8999 = v8998->timer;
  int v19189 = v8999 + 1;
  v8998->timer = v19189;
  int * v9001 = v8998->regs;
  int v9002 = v9001[8];
  int * v9003 = v8998->regs;
  int v19194 = (int)((unsigned int)v9002 >> 19);
  v9003[20] = v19194;
  struct StateT * v19187 = v9005(v8998);
  return v19187;
}

struct StateT * v2983(struct StateT * v2984) {
  int v2985 = v2984->timer;
  int v20930 = v2985 + 1;
  v2984->timer = v20930;
  int * v2987 = v2984->regs;
  int v2988 = v2987[18];
  int * v2989 = v2984->regs;
  int v2990 = v2989[11];
  int * v2991 = v2984->regs;
  int v20937 = v2988 ^ v2990;
  v2991[5] = v20937;
  struct StateT * v20928 = v2993(v2984);
  return v20928;
}

struct StateT * v8803(struct StateT * v8804) {
  int v8805 = v8804->timer;
  int v19411 = v8805 + 1;
  v8804->timer = v19411;
  int * v8807 = v8804->regs;
  int v8808 = v8807[15];
  int * v8809 = v8804->regs;
  int v8810 = v8809[20];
  int * v8811 = v8804->regs;
  int v19417 = v8808 | v8810;
  v8811[15] = v19417;
  struct StateT * v19409 = v8813(v8804);
  return v19409;
}

struct StateT * v2947(struct StateT * v2948) {
  int v2949 = v2948->timer;
  int v20974 = v2949 + 1;
  v2948->timer = v20974;
  int * v2951 = v2948->regs;
  int v2952 = v2951[17];
  int * v2953 = v2948->regs;
  int v20979 = (int)((unsigned int)v2952 >> 25);
  v2953[5] = v20979;
  struct StateT * v20972 = v2955(v2948);
  return v20972;
}

struct StateT * v13254(struct StateT * v13255) {
  int v13256 = v13255->timer;
  int v14711 = v13256 + 1;
  v13255->timer = v14711;
  int * v13258 = v13255->regs;
  int v13259 = v13258[10];
  int * v13260 = v13255->regs;
  int v13261 = v13260[30];
  int * v13262 = v13255->cache_keys;
  int v13263 = v13262[0];
  bool v14718 = v13263 == ((int)((unsigned int)(v13259 + 60) >> 2));
  int v13307;
  if (v14718) {
    int * v13264 = v13255->cache_vals;
    v13264[0] = v13261;
    v13307 = v13261;
  } else {
    int * v13267 = v13255->cache_keys;
    int v13268 = v13267[1];
    bool v14723 = v13268 == ((int)((unsigned int)(v13259 + 60) >> 2));
    int v13305;
    if (v14723) {
      int * v13269 = v13255->cache_keys;
      int * v13270 = v13255->cache_keys;
      int v13271 = v13270[0];
      v13269[1] = v13271;
      int * v13273 = v13255->cache_vals;
      int * v13274 = v13255->cache_vals;
      int v13275 = v13274[0];
      v13273[1] = v13275;
      int * v13277 = v13255->cache_keys;
      int v14731 = (int)((unsigned int)(v13259 + 60) >> 2);
      v13277[0] = v14731;
      int * v13279 = v13255->cache_vals;
      v13279[0] = v13261;
      int v13281 = v13255->timer;
      int v14734 = v13281 + 1;
      v13255->timer = v14734;
      v13305 = v13261;
    } else {
      int * v13284 = v13255->mem;
      int * v13285 = v13255->cache_keys;
      int v13286 = v13285[1];
      int * v13287 = v13255->cache_vals;
      int v13288 = v13287[1];
      v13284[v13286] = v13288;
      int * v13290 = v13255->cache_keys;
      int * v13291 = v13255->cache_keys;
      int v13292 = v13291[0];
      v13290[1] = v13292;
      int * v13294 = v13255->cache_vals;
      int * v13295 = v13255->cache_vals;
      int v13296 = v13295[0];
      v13294[1] = v13296;
      int * v13298 = v13255->cache_keys;
      int v14747 = (int)((unsigned int)(v13259 + 60) >> 2);
      v13298[0] = v14747;
      int * v13300 = v13255->cache_vals;
      v13300[0] = v13261;
      int v13302 = v13255->timer;
      int v14750 = v13302 + 100;
      v13255->timer = v14750;
      v13305 = v13261;
    }
    v13307 = v13305;
  }
  struct StateT * v14709 = v13308(v13255);
  return v14709;
}

struct StateT * v2073(struct StateT * v2074) {
  int v2075 = v2074->timer;
  int v21959 = v2075 + 1;
  v2074->timer = v21959;
  int * v2077 = v2074->regs;
  int v2078 = v2077[15];
  int * v2079 = v2074->regs;
  int v21963 = v2078 << 7;
  v2079[15] = v21963;
  struct StateT * v21957 = v2081(v2074);
  return v21957;
}

struct StateT * v11085(struct StateT * v11086) {
  int v11087 = v11086->timer;
  int v16798 = v11087 + 1;
  v11086->timer = v16798;
  int * v11089 = v11086->regs;
  int v11090 = v11089[16];
  int * v11091 = v11086->regs;
  int v11092 = v11091[22];
  int * v11093 = v11086->regs;
  int v16805 = v11090 + v11092;
  v11093[8] = v16805;
  struct StateT * v16796 = v11095(v11086);
  return v16796;
}

struct StateT * v10937(struct StateT * v10938) {
  int v10939 = v10938->timer;
  int v16974 = v10939 + 1;
  v10938->timer = v16974;
  int * v10941 = v10938->regs;
  int v10942 = v10941[11];
  int * v10943 = v10938->regs;
  int v16979 = (int)((unsigned int)v10942 >> 25);
  v10943[5] = v16979;
  struct StateT * v16972 = v10945(v10938);
  return v16972;
}

struct StateT * v387(struct StateT * v388) {
  int v389 = v388->timer;
  int v23388 = v389 + 1;
  v388->timer = v23388;
  int * v391 = v388->regs;
  int v392 = v391[2];
  int * v393 = v388->regs;
  int v394 = v393[22];
  int * v395 = v388->cache_keys;
  int v396 = v395[0];
  bool v23395 = v396 == ((int)((unsigned int)(v392 + 64) >> 2));
  int v440;
  if (v23395) {
    int * v397 = v388->cache_vals;
    v397[0] = v394;
    v440 = v394;
  } else {
    int * v400 = v388->cache_keys;
    int v401 = v400[1];
    bool v23400 = v401 == ((int)((unsigned int)(v392 + 64) >> 2));
    int v438;
    if (v23400) {
      int * v402 = v388->cache_keys;
      int * v403 = v388->cache_keys;
      int v404 = v403[0];
      v402[1] = v404;
      int * v406 = v388->cache_vals;
      int * v407 = v388->cache_vals;
      int v408 = v407[0];
      v406[1] = v408;
      int * v410 = v388->cache_keys;
      int v23408 = (int)((unsigned int)(v392 + 64) >> 2);
      v410[0] = v23408;
      int * v412 = v388->cache_vals;
      v412[0] = v394;
      int v414 = v388->timer;
      int v23411 = v414 + 1;
      v388->timer = v23411;
      v438 = v394;
    } else {
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
      int v23424 = (int)((unsigned int)(v392 + 64) >> 2);
      v431[0] = v23424;
      int * v433 = v388->cache_vals;
      v433[0] = v394;
      int v435 = v388->timer;
      int v23427 = v435 + 100;
      v388->timer = v23427;
      v438 = v394;
    }
    v440 = v438;
  }
  struct StateT * v23386 = v441(v388);
  return v23386;
}

struct StateT * v171(struct StateT * v172) {
  int v173 = v172->timer;
  int v23568 = v173 + 1;
  v172->timer = v23568;
  int * v175 = v172->regs;
  int v176 = v175[2];
  int * v177 = v172->regs;
  int v178 = v177[18];
  int * v179 = v172->cache_keys;
  int v180 = v179[0];
  bool v23575 = v180 == ((int)((unsigned int)(v176 + 80) >> 2));
  int v224;
  if (v23575) {
    int * v181 = v172->cache_vals;
    v181[0] = v178;
    v224 = v178;
  } else {
    int * v184 = v172->cache_keys;
    int v185 = v184[1];
    bool v23580 = v185 == ((int)((unsigned int)(v176 + 80) >> 2));
    int v222;
    if (v23580) {
      int * v186 = v172->cache_keys;
      int * v187 = v172->cache_keys;
      int v188 = v187[0];
      v186[1] = v188;
      int * v190 = v172->cache_vals;
      int * v191 = v172->cache_vals;
      int v192 = v191[0];
      v190[1] = v192;
      int * v194 = v172->cache_keys;
      int v23588 = (int)((unsigned int)(v176 + 80) >> 2);
      v194[0] = v23588;
      int * v196 = v172->cache_vals;
      v196[0] = v178;
      int v198 = v172->timer;
      int v23591 = v198 + 1;
      v172->timer = v23591;
      v222 = v178;
    } else {
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
      int v23604 = (int)((unsigned int)(v176 + 80) >> 2);
      v215[0] = v23604;
      int * v217 = v172->cache_vals;
      v217[0] = v178;
      int v219 = v172->timer;
      int v23607 = v219 + 100;
      v172->timer = v23607;
      v222 = v178;
    }
    v224 = v222;
  }
  struct StateT * v23566 = v225(v172);
  return v23566;
}

struct StateT * v10047(struct StateT * v10048) {
  int * v10049 = v10048->saved_regs;
  int * v10050 = v10048->regs;
  int v10051 = v10050[15];
  v10049[15] = v10051;
  int v10053 = v10048->timer;
  int v17970 = v10053 + 1;
  v10048->timer = v17970;
  int * v10055 = v10048->regs;
  int v10056 = v10055[21];
  int * v10057 = v10048->regs;
  int v10058 = v10057[16];
  int * v10059 = v10048->regs;
  int v17976 = v10056 + v10058;
  v10059[15] = v17976;
  struct StateT * v17964 = v10061(v10048);
  return v17964;
}

struct StateT * v12424(struct StateT * v12425) {
  int v12426 = v12425->timer;
  int v15441 = v12426 + 1;
  v12425->timer = v15441;
  int * v12428 = v12425->regs;
  int v12429 = v12428[19];
  int * v12430 = v12425->regs;
  int v12431 = v12430[7];
  int * v12432 = v12425->regs;
  int v15447 = v12429 + v12431;
  v12432[7] = v15447;
  struct StateT * v15439 = v12434(v12425);
  return v15439;
}

struct StateT * v3095(struct StateT * v3096) {
  int v3097 = v3096->timer;
  int v20798 = v3097 + 1;
  v3096->timer = v20798;
  int * v3099 = v3096->regs;
  int v3100 = v3099[15];
  int * v3101 = v3096->regs;
  int v3102 = v3101[9];
  int * v3103 = v3096->regs;
  int v20804 = v3100 | v3102;
  v3103[15] = v20804;
  struct StateT * v20796 = v3105(v3096);
  return v20796;
}

struct StateT * v10839(struct StateT * v10840) {
  int * v10841 = v10840->saved_regs;
  int * v10842 = v10840->regs;
  int v10843 = v10842[19];
  v10841[19] = v10843;
  int v10845 = v10840->timer;
  int v17083 = v10845 + 1;
  v10840->timer = v17083;
  int * v10847 = v10840->regs;
  int v10848 = v10847[19];
  int * v10849 = v10840->regs;
  int v10850 = v10849[17];
  int * v10851 = v10840->regs;
  int v17088 = v10848 ^ v10850;
  v10851[19] = v17088;
  struct StateT * v17077 = v10853(v10840);
  return v17077;
}

struct StateT * v2825(struct StateT * v2826) {
  int v2827 = v2826->timer;
  int v21113 = v2827 + 1;
  v2826->timer = v21113;
  int * v2829 = v2826->regs;
  int v2830 = v2829[21];
  int * v2831 = v2826->regs;
  int v2832 = v2831[14];
  int * v2833 = v2826->regs;
  int v21120 = v2830 + v2832;
  v2833[15] = v21120;
  struct StateT * v21111 = v2835(v2826);
  return v21111;
}

struct StateT * v1915(struct StateT * v1916) {
  int v1917 = v1916->timer;
  int v22121 = v1917 + 1;
  v1916->timer = v22121;
  int * v1919 = v1916->regs;
  int v1920 = v1919[7];
  int * v1921 = v1916->regs;
  v1921[14] = v1920;
  struct StateT * v22119 = v1923(v1916);
  return v22119;
}

struct StateT * v10979(struct StateT * v10980) {
  int v10981 = v10980->timer;
  int v16924 = v10981 + 1;
  v10980->timer = v16924;
  int * v10983 = v10980->regs;
  int v10984 = v10983[16];
  int * v10985 = v10980->regs;
  int v10986 = v10985[5];
  int * v10987 = v10980->regs;
  int v16930 = v10984 | v10986;
  v10987[16] = v16930;
  struct StateT * v16922 = v10989(v10980);
  return v16922;
}

struct StateT * v13946(struct StateT * v13947) {
  int v13948 = v13947->timer;
  int v14135 = v13948 + 1;
  v13947->timer = v14135;
  int * v13950 = v13947->regs;
  int v13951 = v13950[2];
  int * v13952 = v13947->cache_keys;
  int v13953 = v13952[0];
  bool v14140 = v13953 == ((int)((unsigned int)(v13951 + 48) >> 2));
  int v14001;
  if (v14140) {
    int * v13954 = v13947->cache_vals;
    int v13955 = v13954[0];
    v14001 = v13955;
  } else {
    int * v13957 = v13947->cache_keys;
    int v13958 = v13957[1];
    bool v14145 = v13958 == ((int)((unsigned int)(v13951 + 48) >> 2));
    int v13999;
    if (v14145) {
      int * v13959 = v13947->cache_vals;
      int v13960 = v13959[1];
      int * v13961 = v13947->cache_keys;
      int * v13962 = v13947->cache_keys;
      int v13963 = v13962[0];
      v13961[1] = v13963;
      int * v13965 = v13947->cache_vals;
      int * v13966 = v13947->cache_vals;
      int v13967 = v13966[0];
      v13965[1] = v13967;
      int * v13969 = v13947->cache_keys;
      int v14154 = (int)((unsigned int)(v13951 + 48) >> 2);
      v13969[0] = v14154;
      int * v13971 = v13947->cache_vals;
      v13971[0] = v13960;
      int v13973 = v13947->timer;
      int v14157 = v13973 + 1;
      v13947->timer = v14157;
      v13999 = v13960;
    } else {
      int * v13976 = v13947->mem;
      int v14159 = (int)((unsigned int)(v13951 + 48) >> 2);
      int v13977 = v13976[v14159];
      int * v13978 = v13947->mem;
      int * v13979 = v13947->cache_keys;
      int v13980 = v13979[1];
      int * v13981 = v13947->cache_vals;
      int v13982 = v13981[1];
      v13978[v13980] = v13982;
      int * v13984 = v13947->cache_keys;
      int * v13985 = v13947->cache_keys;
      int v13986 = v13985[0];
      v13984[1] = v13986;
      int * v13988 = v13947->cache_vals;
      int * v13989 = v13947->cache_vals;
      int v13990 = v13989[0];
      v13988[1] = v13990;
      int * v13992 = v13947->cache_keys;
      v13992[0] = v14159;
      int * v13994 = v13947->cache_vals;
      v13994[0] = v13977;
      int v13996 = v13947->timer;
      int v14174 = v13996 + 100;
      v13947->timer = v14174;
      v13999 = v13977;
    }
    v14001 = v13999;
  }
  int * v14002 = v13947->regs;
  v14002[26] = v14001;
  struct StateT * v14133 = v14004(v13947);
  return v14133;
}

struct StateT * v1439(struct StateT * v1440) {
  int v1441 = v1440->timer;
  int v22535 = v1441 + 1;
  v1440->timer = v22535;
  int * v1443 = v1440->regs;
  int v1444 = v1443[13];
  int * v1445 = v1440->regs;
  int v22540 = v1444 + 1134;
  v1445[11] = v22540;
  struct StateT * v22533 = v1447(v1440);
  return v22533;
}

struct StateT * v3979(struct StateT * v3980) {
  int v3981 = v3980->timer;
  int v7790 = v3981 + 1;
  v3980->timer = v7790;
  int * v3983 = v3980->regs;
  int v3984 = v3983[26];
  int * v3985 = v3980->regs;
  int v3986 = v3985[7];
  int * v3987 = v3980->regs;
  int v7796 = v3984 + v3986;
  v3987[26] = v7796;
  struct StateT * v7788 = v3989(v3980);
  return v7788;
}

struct StateT * v3685(struct StateT * v3686) {
  int v3687 = v3686->timer;
  int v8053 = v3687 + 1;
  v3686->timer = v8053;
  int * v3689 = v3686->regs;
  int v3690 = v3689[27];
  int * v3691 = v3686->regs;
  int v3692 = v3691[28];
  int * v3693 = v3686->regs;
  int v8059 = v3690 + v3692;
  v3693[28] = v8059;
  struct StateT * v8051 = v3695(v3686);
  return v8051;
}

struct StateT * v9249(struct StateT * v9250) {
  int v9251 = v9250->timer;
  int v18893 = v9251 + 1;
  v9250->timer = v18893;
  int * v9253 = v9250->regs;
  int v9254 = v9253[5];
  int * v9255 = v9250->regs;
  int v9256 = v9255[6];
  int * v9257 = v9250->regs;
  int v18899 = v9254 | v9256;
  v9257[5] = v18899;
  struct StateT * v18891 = v9259(v9250);
  return v18891;
}

struct StateT * v10615(struct StateT * v10616) {
  int v10617 = v10616->timer;
  int v17334 = v10617 + 1;
  v10616->timer = v17334;
  int * v10619 = v10616->regs;
  int v10620 = v10619[16];
  int * v10621 = v10616->regs;
  int v10622 = v10621[15];
  int * v10623 = v10616->regs;
  int v17341 = v10620 ^ v10622;
  v10623[9] = v17341;
  struct StateT * v17332 = v10625(v10616);
  return v17332;
}

struct StateT * v11463(struct StateT * v11464) {
  int v11465 = v11464->timer;
  int v16364 = v11465 + 1;
  v11464->timer = v16364;
  int * v11467 = v11464->regs;
  int v11468 = v11467[11];
  int * v11469 = v11464->regs;
  int v16369 = (int)((unsigned int)v11468 >> 14);
  v11469[9] = v16369;
  struct StateT * v16362 = v11471(v11464);
  return v16362;
}

struct StateT * v10467(struct StateT * v10468) {
  int v10469 = v10468->timer;
  int v17506 = v10469 + 1;
  v10468->timer = v17506;
  int * v10471 = v10468->regs;
  int v10472 = v10471[26];
  int * v10473 = v10468->regs;
  int v10474 = v10473[12];
  int * v10475 = v10468->regs;
  int v17513 = v10472 + v10474;
  v10475[15] = v17513;
  struct StateT * v17504 = v10477(v10468);
  return v17504;
}

struct StateT * v2787(struct StateT * v2788) {
  int v2789 = v2788->timer;
  int v21153 = v2789 + 1;
  v2788->timer = v21153;
  int * v2791 = v2788->regs;
  int v2792 = v2791[11];
  int * v2793 = v2788->regs;
  int v2794 = v2793[16];
  int * v2795 = v2788->regs;
  int v21160 = v2792 ^ v2794;
  v2795[20] = v21160;
  struct StateT * v21151 = v2797(v2788);
  return v21151;
}

struct StateT * v10559(struct StateT * v10560) {
  int v10561 = v10560->timer;
  int v17400 = v10561 + 1;
  v10560->timer = v17400;
  int * v10563 = v10560->regs;
  int v10564 = v10563[9];
  int * v10565 = v10560->regs;
  int v17405 = (int)((unsigned int)v10564 >> 19);
  v10565[20] = v17405;
  struct StateT * v17398 = v10567(v10560);
  return v17398;
}

struct StateT * v2159(struct StateT * v2160) {
  int v2161 = v2160->timer;
  int v21858 = v2161 + 1;
  v2160->timer = v21858;
  int * v2163 = v2160->regs;
  int v2164 = v2163[8];
  int * v2165 = v2160->regs;
  int v2166 = v2165[20];
  int * v2167 = v2160->regs;
  int v21864 = v2164 | v2166;
  v2167[8] = v21864;
  struct StateT * v21856 = v2169(v2160);
  return v21856;
}

struct StateT * v9329(struct StateT * v9330) {
  int v9331 = v9330->timer;
  int v18800 = v9331 + 1;
  v9330->timer = v18800;
  int * v9333 = v9330->regs;
  int v9334 = v9333[22];
  int * v9335 = v9330->regs;
  int v9336 = v9335[1];
  int * v9337 = v9330->regs;
  int v18807 = v9334 + v9336;
  v9337[17] = v18807;
  struct StateT * v18798 = v9339(v9330);
  return v18798;
}

struct StateT * v10779(struct StateT * v10780) {
  int v10781 = v10780->timer;
  int v17149 = v10781 + 1;
  v10780->timer = v17149;
  int * v10783 = v10780->regs;
  int v10784 = v10783[17];
  int * v10785 = v10780->regs;
  int v10786 = v10785[6];
  int * v10787 = v10780->regs;
  int v17155 = v10784 | v10786;
  v10787[17] = v17155;
  struct StateT * v17147 = v10789(v10780);
  return v17147;
}

struct StateT * v10185(struct StateT * v10186) {
  int v10187 = v10186->timer;
  int v17818 = v10187 + 1;
  v10186->timer = v17818;
  int * v10189 = v10186->regs;
  int v10190 = v10189[8];
  int * v10191 = v10186->regs;
  int v17823 = (int)((unsigned int)v10190 >> 25);
  v10191[20] = v17823;
  struct StateT * v17816 = v10193(v10186);
  return v17816;
}

struct StateT * v9933(struct StateT * v9934) {
  int v9935 = v9934->timer;
  int v18100 = v9935 + 1;
  v9934->timer = v18100;
  int * v9937 = v9934->regs;
  int v9938 = v9937[15];
  int * v9939 = v9934->regs;
  int v9940 = v9939[9];
  int * v9941 = v9934->regs;
  int v18106 = v9938 | v9940;
  v9941[15] = v18106;
  struct StateT * v18098 = v9943(v9934);
  return v18098;
}

struct StateT * v13424(struct StateT * v13425) {
  int v13426 = v13425->timer;
  int v14567 = v13426 + 1;
  v13425->timer = v14567;
  int * v13428 = v13425->regs;
  int v13429 = v13428[2];
  int * v13430 = v13425->cache_keys;
  int v13431 = v13430[0];
  bool v14572 = v13431 == ((int)((unsigned int)(v13429 + 84) >> 2));
  int v13479;
  if (v14572) {
    int * v13432 = v13425->cache_vals;
    int v13433 = v13432[0];
    v13479 = v13433;
  } else {
    int * v13435 = v13425->cache_keys;
    int v13436 = v13435[1];
    bool v14577 = v13436 == ((int)((unsigned int)(v13429 + 84) >> 2));
    int v13477;
    if (v14577) {
      int * v13437 = v13425->cache_vals;
      int v13438 = v13437[1];
      int * v13439 = v13425->cache_keys;
      int * v13440 = v13425->cache_keys;
      int v13441 = v13440[0];
      v13439[1] = v13441;
      int * v13443 = v13425->cache_vals;
      int * v13444 = v13425->cache_vals;
      int v13445 = v13444[0];
      v13443[1] = v13445;
      int * v13447 = v13425->cache_keys;
      int v14586 = (int)((unsigned int)(v13429 + 84) >> 2);
      v13447[0] = v14586;
      int * v13449 = v13425->cache_vals;
      v13449[0] = v13438;
      int v13451 = v13425->timer;
      int v14589 = v13451 + 1;
      v13425->timer = v14589;
      v13477 = v13438;
    } else {
      int * v13454 = v13425->mem;
      int v14591 = (int)((unsigned int)(v13429 + 84) >> 2);
      int v13455 = v13454[v14591];
      int * v13456 = v13425->mem;
      int * v13457 = v13425->cache_keys;
      int v13458 = v13457[1];
      int * v13459 = v13425->cache_vals;
      int v13460 = v13459[1];
      v13456[v13458] = v13460;
      int * v13462 = v13425->cache_keys;
      int * v13463 = v13425->cache_keys;
      int v13464 = v13463[0];
      v13462[1] = v13464;
      int * v13466 = v13425->cache_vals;
      int * v13467 = v13425->cache_vals;
      int v13468 = v13467[0];
      v13466[1] = v13468;
      int * v13470 = v13425->cache_keys;
      v13470[0] = v14591;
      int * v13472 = v13425->cache_vals;
      v13472[0] = v13455;
      int v13474 = v13425->timer;
      int v14606 = v13474 + 100;
      v13425->timer = v14606;
      v13477 = v13455;
    }
    v13479 = v13477;
  }
  int * v13480 = v13425->regs;
  v13480[9] = v13479;
  struct StateT * v14565 = v13482(v13425);
  return v14565;
}

struct StateT * v9197(struct StateT * v9198) {
  int v9199 = v9198->timer;
  int v18953 = v9199 + 1;
  v9198->timer = v18953;
  int * v9201 = v9198->regs;
  int v9202 = v9201[16];
  int * v9203 = v9198->regs;
  int v9204 = v9203[6];
  int * v9205 = v9198->regs;
  int v18959 = v9202 | v9204;
  v9205[16] = v18959;
  struct StateT * v18951 = v9207(v9198);
  return v18951;
}

struct StateT * v9207(struct StateT * v9208) {
  int v9209 = v9208->timer;
  int v18943 = v9209 + 1;
  v9208->timer = v18943;
  int * v9211 = v9208->regs;
  int v9212 = v9211[17];
  int * v9213 = v9208->regs;
  int v18948 = (int)((unsigned int)v9212 >> 14);
  v9213[6] = v18948;
  struct StateT * v18941 = v9215(v9208);
  return v18941;
}

struct StateT * v10805(struct StateT * v10806) {
  int v10807 = v10806->timer;
  int v17119 = v10807 + 1;
  v10806->timer = v17119;
  int * v10809 = v10806->regs;
  int v10810 = v10809[5];
  int * v10811 = v10806->regs;
  int v10812 = v10811[6];
  int * v10813 = v10806->regs;
  int v17125 = v10810 | v10812;
  v10813[5] = v17125;
  struct StateT * v17117 = v10815(v10806);
  return v17117;
}

struct StateT * v11479(struct StateT * v11480) {
  int v11481 = v11480->timer;
  int v16344 = v11481 + 1;
  v11480->timer = v16344;
  int * v11483 = v11480->regs;
  int v11484 = v11483[11];
  int * v11485 = v11480->regs;
  int v11486 = v11485[9];
  int * v11487 = v11480->regs;
  int v16350 = v11484 | v11486;
  v11487[11] = v16350;
  struct StateT * v16342 = v11489(v11480);
  return v16342;
}

struct StateT * v9959(struct StateT * v9960) {
  int v9961 = v9960->timer;
  int v18070 = v9961 + 1;
  v9960->timer = v18070;
  int * v9963 = v9960->regs;
  int v9964 = v9963[6];
  int * v9965 = v9960->regs;
  int v9966 = v9965[9];
  int * v9967 = v9960->regs;
  int v18076 = v9964 | v9966;
  v9967[6] = v18076;
  struct StateT * v18068 = v9969(v9960);
  return v18068;
}

struct StateT * v2317(struct StateT * v2318) {
  int v2319 = v2318->timer;
  int v21684 = v2319 + 1;
  v2318->timer = v21684;
  int * v2321 = v2318->regs;
  int v2322 = v2321[9];
  int * v2323 = v2318->regs;
  int v21689 = (int)((unsigned int)v2322 >> 23);
  v2323[20] = v21689;
  struct StateT * v21682 = v2325(v2318);
  return v21682;
}

struct StateT * v8491(struct StateT * v8492) {
  int * v8493 = v8492->saved_regs;
  int * v8494 = v8492->regs;
  int v8495 = v8494[13];
  v8493[13] = v8495;
  int v8497 = v8492->timer;
  int v19774 = v8497 + 1;
  v8492->timer = v19774;
  int * v8499 = v8492->regs;
  int v8500 = v8499[13];
  int * v8501 = v8492->regs;
  int v8502 = v8501[7];
  int * v8503 = v8492->regs;
  int v19779 = v8500 + v8502;
  v8503[13] = v19779;
  struct StateT * v19768 = v8505(v8492);
  return v19768;
}

struct StateT * v5115(struct StateT * v5116) {
  int v5117 = v5116->timer;
  int v6769 = v5117 + 1;
  v5116->timer = v6769;
  int * v5119 = v5116->regs;
  int v5120 = v5119[10];
  int * v5121 = v5116->regs;
  int v5122 = v5121[24];
  int * v5123 = v5116->cache_keys;
  int v5124 = v5123[0];
  bool v6776 = v5124 == ((int)((unsigned int)(v5120 + 52) >> 2));
  int v5168;
  if (v6776) {
    int * v5125 = v5116->cache_vals;
    v5125[0] = v5122;
    v5168 = v5122;
  } else {
    int * v5128 = v5116->cache_keys;
    int v5129 = v5128[1];
    bool v6781 = v5129 == ((int)((unsigned int)(v5120 + 52) >> 2));
    int v5166;
    if (v6781) {
      int * v5130 = v5116->cache_keys;
      int * v5131 = v5116->cache_keys;
      int v5132 = v5131[0];
      v5130[1] = v5132;
      int * v5134 = v5116->cache_vals;
      int * v5135 = v5116->cache_vals;
      int v5136 = v5135[0];
      v5134[1] = v5136;
      int * v5138 = v5116->cache_keys;
      int v6789 = (int)((unsigned int)(v5120 + 52) >> 2);
      v5138[0] = v6789;
      int * v5140 = v5116->cache_vals;
      v5140[0] = v5122;
      int v5142 = v5116->timer;
      int v6792 = v5142 + 1;
      v5116->timer = v6792;
      v5166 = v5122;
    } else {
      int * v5145 = v5116->mem;
      int * v5146 = v5116->cache_keys;
      int v5147 = v5146[1];
      int * v5148 = v5116->cache_vals;
      int v5149 = v5148[1];
      v5145[v5147] = v5149;
      int * v5151 = v5116->cache_keys;
      int * v5152 = v5116->cache_keys;
      int v5153 = v5152[0];
      v5151[1] = v5153;
      int * v5155 = v5116->cache_vals;
      int * v5156 = v5116->cache_vals;
      int v5157 = v5156[0];
      v5155[1] = v5157;
      int * v5159 = v5116->cache_keys;
      int v6805 = (int)((unsigned int)(v5120 + 52) >> 2);
      v5159[0] = v6805;
      int * v5161 = v5116->cache_vals;
      v5161[0] = v5122;
      int v5163 = v5116->timer;
      int v6808 = v5163 + 100;
      v5116->timer = v6808;
      v5166 = v5122;
    }
    v5168 = v5166;
  }
  struct StateT * v6767 = v5169(v5116);
  return v6767;
}

struct StateT * v12220(struct StateT * v12221) {
  int v12222 = v12221->timer;
  int v15636 = v12222 + 1;
  v12221->timer = v15636;
  int * v12224 = v12221->regs;
  int v12225 = v12224[16];
  int * v12226 = v12221->regs;
  int v12227 = v12226[30];
  int * v12228 = v12221->regs;
  int v15642 = v12225 + v12227;
  v12228[16] = v15642;
  struct StateT * v15634 = v12230(v12221);
  return v15634;
}

struct StateT * v3289(struct StateT * v3290) {
  int v3291 = v3290->timer;
  int v20576 = v3291 + 1;
  v3290->timer = v20576;
  int * v3293 = v3290->regs;
  int v3294 = v3293[6];
  int * v3295 = v3290->regs;
  int v20581 = (int)((unsigned int)v3294 >> 19);
  v3295[9] = v20581;
  struct StateT * v20574 = v3297(v3290);
  return v20574;
}

struct StateT * v9697(struct StateT * v9698) {
  int v9699 = v9698->timer;
  int v18372 = v9699 + 1;
  v9698->timer = v18372;
  int * v9701 = v9698->regs;
  int v9702 = v9701[24];
  int * v9703 = v9698->regs;
  int v9704 = v9703[16];
  int * v9705 = v9698->regs;
  int v18379 = v9702 + v9704;
  v9705[8] = v18379;
  struct StateT * v18370 = v9707(v9698);
  return v18370;
}

struct StateT * v8813(struct StateT * v8814) {
  int v8815 = v8814->timer;
  int v19401 = v8815 + 1;
  v8814->timer = v19401;
  int * v8817 = v8814->regs;
  int v8818 = v8817[8];
  int * v8819 = v8814->regs;
  int v19406 = (int)((unsigned int)v8818 >> 23);
  v8819[20] = v19406;
  struct StateT * v19399 = v8821(v8814);
  return v19399;
}

struct StateT * v12714(struct StateT * v12715) {
  int v12716 = v12715->timer;
  int v15160 = v12716 + 1;
  v12715->timer = v15160;
  int * v12718 = v12715->regs;
  int v12719 = v12718[10];
  int * v12720 = v12715->regs;
  int v12721 = v12720[11];
  int * v12722 = v12715->cache_keys;
  int v12723 = v12722[0];
  bool v15167 = v12723 == ((int)((unsigned int)(v12719 + 20) >> 2));
  int v12767;
  if (v15167) {
    int * v12724 = v12715->cache_vals;
    v12724[0] = v12721;
    v12767 = v12721;
  } else {
    int * v12727 = v12715->cache_keys;
    int v12728 = v12727[1];
    bool v15172 = v12728 == ((int)((unsigned int)(v12719 + 20) >> 2));
    int v12765;
    if (v15172) {
      int * v12729 = v12715->cache_keys;
      int * v12730 = v12715->cache_keys;
      int v12731 = v12730[0];
      v12729[1] = v12731;
      int * v12733 = v12715->cache_vals;
      int * v12734 = v12715->cache_vals;
      int v12735 = v12734[0];
      v12733[1] = v12735;
      int * v12737 = v12715->cache_keys;
      int v15180 = (int)((unsigned int)(v12719 + 20) >> 2);
      v12737[0] = v15180;
      int * v12739 = v12715->cache_vals;
      v12739[0] = v12721;
      int v12741 = v12715->timer;
      int v15183 = v12741 + 1;
      v12715->timer = v15183;
      v12765 = v12721;
    } else {
      int * v12744 = v12715->mem;
      int * v12745 = v12715->cache_keys;
      int v12746 = v12745[1];
      int * v12747 = v12715->cache_vals;
      int v12748 = v12747[1];
      v12744[v12746] = v12748;
      int * v12750 = v12715->cache_keys;
      int * v12751 = v12715->cache_keys;
      int v12752 = v12751[0];
      v12750[1] = v12752;
      int * v12754 = v12715->cache_vals;
      int * v12755 = v12715->cache_vals;
      int v12756 = v12755[0];
      v12754[1] = v12756;
      int * v12758 = v12715->cache_keys;
      int v15196 = (int)((unsigned int)(v12719 + 20) >> 2);
      v12758[0] = v15196;
      int * v12760 = v12715->cache_vals;
      v12760[0] = v12721;
      int v12762 = v12715->timer;
      int v15199 = v12762 + 100;
      v12715->timer = v15199;
      v12765 = v12721;
    }
    v12767 = v12765;
  }
  struct StateT * v15158 = v12768(v12715);
  return v15158;
}

struct StateT * v1799(struct StateT * v1800) {
  int v1801 = v1800->timer;
  int v22186 = v1801 + 1;
  v1800->timer = v22186;
  int * v1803 = v1800->regs;
  int v1804 = v1803[2];
  int * v1805 = v1800->regs;
  int v1806 = v1805[17];
  int * v1807 = v1800->cache_keys;
  int v1808 = v1807[0];
  bool v22193 = v1808 == ((int)((unsigned int)(v1804 + 28) >> 2));
  int v1852;
  if (v22193) {
    int * v1809 = v1800->cache_vals;
    v1809[0] = v1806;
    v1852 = v1806;
  } else {
    int * v1812 = v1800->cache_keys;
    int v1813 = v1812[1];
    bool v22198 = v1813 == ((int)((unsigned int)(v1804 + 28) >> 2));
    int v1850;
    if (v22198) {
      int * v1814 = v1800->cache_keys;
      int * v1815 = v1800->cache_keys;
      int v1816 = v1815[0];
      v1814[1] = v1816;
      int * v1818 = v1800->cache_vals;
      int * v1819 = v1800->cache_vals;
      int v1820 = v1819[0];
      v1818[1] = v1820;
      int * v1822 = v1800->cache_keys;
      int v22206 = (int)((unsigned int)(v1804 + 28) >> 2);
      v1822[0] = v22206;
      int * v1824 = v1800->cache_vals;
      v1824[0] = v1806;
      int v1826 = v1800->timer;
      int v22209 = v1826 + 1;
      v1800->timer = v22209;
      v1850 = v1806;
    } else {
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
      int v22222 = (int)((unsigned int)(v1804 + 28) >> 2);
      v1843[0] = v22222;
      int * v1845 = v1800->cache_vals;
      v1845[0] = v1806;
      int v1847 = v1800->timer;
      int v22225 = v1847 + 100;
      v1800->timer = v22225;
      v1850 = v1806;
    }
    v1852 = v1850;
  }
  struct StateT * v22184 = v1853(v1800);
  return v22184;
}

struct StateT * v3013(struct StateT * v3014) {
  int v3015 = v3014->timer;
  int v20894 = v3015 + 1;
  v3014->timer = v20894;
  int * v3017 = v3014->regs;
  int v3018 = v3017[23];
  int * v3019 = v3014->regs;
  int v3020 = v3019[21];
  int * v3021 = v3014->regs;
  int v20901 = v3018 + v3020;
  v3021[11] = v20901;
  struct StateT * v20892 = v3023(v3014);
  return v20892;
}

struct StateT * v10035(struct StateT * v10036) {
  int v10037 = v10036->timer;
  int v17986 = v10037 + 1;
  v10036->timer = v17986;
  int * v10039 = v10036->regs;
  int v10040 = v10039[30];
  int * v10041 = v10036->regs;
  int v17990 = v10040 + 1;
  v10041[30] = v17990;
  struct StateT * v17984 = v10043(v10036);
  return v17984;
}

struct StateT * v3053(struct StateT * v3054) {
  int v3055 = v3054->timer;
  int v20848 = v3055 + 1;
  v3054->timer = v20848;
  int * v3057 = v3054->regs;
  int v3058 = v3057[11];
  int * v3059 = v3054->regs;
  int v20853 = (int)((unsigned int)v3058 >> 23);
  v3059[9] = v20853;
  struct StateT * v20846 = v3061(v3054);
  return v20846;
}

struct StateT * v4373(struct StateT * v4374) {
  int v4375 = v4374->timer;
  int v7432 = v4375 + 1;
  v4374->timer = v7432;
  int * v4377 = v4374->regs;
  int v4378 = v4377[21];
  int * v4379 = v4374->regs;
  int v4380 = v4379[15];
  int * v4381 = v4374->regs;
  int v7438 = v4378 + v4380;
  v4381[15] = v7438;
  struct StateT * v7430 = v4383(v4374);
  return v7430;
}

struct StateT * v9493(struct StateT * v9494) {
  int v9495 = v9494->timer;
  int v18608 = v9495 + 1;
  v9494->timer = v18608;
  int * v9497 = v9494->regs;
  int v9498 = v9497[5];
  int * v9499 = v9494->regs;
  int v9500 = v9499[20];
  int * v9501 = v9494->regs;
  int v18615 = v9498 + v9500;
  v9501[15] = v18615;
  struct StateT * v18606 = v9503(v9494);
  return v18606;
}

struct StateT * v3525(struct StateT * v3526) {
  int v3527 = v3526->timer;
  int v20303 = v3527 + 1;
  v3526->timer = v20303;
  int * v3529 = v3526->regs;
  int v3530 = v3529[21];
  int * v3531 = v3526->regs;
  int v3532 = v3531[11];
  int * v3533 = v3526->regs;
  int v20309 = v3530 ^ v3532;
  v3533[21] = v20309;
  struct StateT * v20301 = v3535(v3526);
  return v20301;
}

struct StateT * v11567(struct StateT * v11568) {
  int v11569 = v11568->timer;
  int v16243 = v11569 + 1;
  v11568->timer = v16243;
  int * v11571 = v11568->regs;
  int v11572 = v11571[21];
  int * v11573 = v11568->regs;
  int v11574 = v11573[11];
  int * v11575 = v11568->regs;
  int v16249 = v11572 ^ v11574;
  v11575[21] = v16249;
  struct StateT * v16241 = v11577(v11568);
  return v16241;
}

struct StateT * v8075(struct StateT * v8076) {
  int v8077 = v8076->timer;
  int v20147 = v8077 + 1;
  v8076->timer = v20147;
  struct StateT * v20145 = v8079(v8076);
  return v20145;
}

struct StateT * v4683(struct StateT * v4684) {
  int v4685 = v4684->timer;
  int v7129 = v4685 + 1;
  v4684->timer = v7129;
  int * v4687 = v4684->regs;
  int v4688 = v4687[10];
  int * v4689 = v4684->regs;
  int v4690 = v4689[11];
  int * v4691 = v4684->cache_keys;
  int v4692 = v4691[0];
  bool v7136 = v4692 == ((int)((unsigned int)(v4688 + 20) >> 2));
  int v4736;
  if (v7136) {
    int * v4693 = v4684->cache_vals;
    v4693[0] = v4690;
    v4736 = v4690;
  } else {
    int * v4696 = v4684->cache_keys;
    int v4697 = v4696[1];
    bool v7141 = v4697 == ((int)((unsigned int)(v4688 + 20) >> 2));
    int v4734;
    if (v7141) {
      int * v4698 = v4684->cache_keys;
      int * v4699 = v4684->cache_keys;
      int v4700 = v4699[0];
      v4698[1] = v4700;
      int * v4702 = v4684->cache_vals;
      int * v4703 = v4684->cache_vals;
      int v4704 = v4703[0];
      v4702[1] = v4704;
      int * v4706 = v4684->cache_keys;
      int v7149 = (int)((unsigned int)(v4688 + 20) >> 2);
      v4706[0] = v7149;
      int * v4708 = v4684->cache_vals;
      v4708[0] = v4690;
      int v4710 = v4684->timer;
      int v7152 = v4710 + 1;
      v4684->timer = v7152;
      v4734 = v4690;
    } else {
      int * v4713 = v4684->mem;
      int * v4714 = v4684->cache_keys;
      int v4715 = v4714[1];
      int * v4716 = v4684->cache_vals;
      int v4717 = v4716[1];
      v4713[v4715] = v4717;
      int * v4719 = v4684->cache_keys;
      int * v4720 = v4684->cache_keys;
      int v4721 = v4720[0];
      v4719[1] = v4721;
      int * v4723 = v4684->cache_vals;
      int * v4724 = v4684->cache_vals;
      int v4725 = v4724[0];
      v4723[1] = v4725;
      int * v4727 = v4684->cache_keys;
      int v7165 = (int)((unsigned int)(v4688 + 20) >> 2);
      v4727[0] = v7165;
      int * v4729 = v4684->cache_vals;
      v4729[0] = v4690;
      int v4731 = v4684->timer;
      int v7168 = v4731 + 100;
      v4684->timer = v7168;
      v4734 = v4690;
    }
    v4736 = v4734;
  }
  struct StateT * v7127 = v4737(v4684);
  return v7127;
}

struct StateT * v3989(struct StateT * v3990) {
  int v3991 = v3990->timer;
  int v7742 = v3991 + 1;
  v3990->timer = v7742;
  int * v3993 = v3990->regs;
  int v3994 = v3993[2];
  int * v3995 = v3990->cache_keys;
  int v3996 = v3995[0];
  bool v7747 = v3996 == ((int)((unsigned int)(v3994 + 24) >> 2));
  int v4044;
  if (v7747) {
    int * v3997 = v3990->cache_vals;
    int v3998 = v3997[0];
    v4044 = v3998;
  } else {
    int * v4000 = v3990->cache_keys;
    int v4001 = v4000[1];
    bool v7752 = v4001 == ((int)((unsigned int)(v3994 + 24) >> 2));
    int v4042;
    if (v7752) {
      int * v4002 = v3990->cache_vals;
      int v4003 = v4002[1];
      int * v4004 = v3990->cache_keys;
      int * v4005 = v3990->cache_keys;
      int v4006 = v4005[0];
      v4004[1] = v4006;
      int * v4008 = v3990->cache_vals;
      int * v4009 = v3990->cache_vals;
      int v4010 = v4009[0];
      v4008[1] = v4010;
      int * v4012 = v3990->cache_keys;
      int v7761 = (int)((unsigned int)(v3994 + 24) >> 2);
      v4012[0] = v7761;
      int * v4014 = v3990->cache_vals;
      v4014[0] = v4003;
      int v4016 = v3990->timer;
      int v7764 = v4016 + 1;
      v3990->timer = v7764;
      v4042 = v4003;
    } else {
      int * v4019 = v3990->mem;
      int v7766 = (int)((unsigned int)(v3994 + 24) >> 2);
      int v4020 = v4019[v7766];
      int * v4021 = v3990->mem;
      int * v4022 = v3990->cache_keys;
      int v4023 = v4022[1];
      int * v4024 = v3990->cache_vals;
      int v4025 = v4024[1];
      v4021[v4023] = v4025;
      int * v4027 = v3990->cache_keys;
      int * v4028 = v3990->cache_keys;
      int v4029 = v4028[0];
      v4027[1] = v4029;
      int * v4031 = v3990->cache_vals;
      int * v4032 = v3990->cache_vals;
      int v4033 = v4032[0];
      v4031[1] = v4033;
      int * v4035 = v3990->cache_keys;
      v4035[0] = v7766;
      int * v4037 = v3990->cache_vals;
      v4037[0] = v4020;
      int v4039 = v3990->timer;
      int v7781 = v4039 + 100;
      v3990->timer = v7781;
      v4042 = v4020;
    }
    v4044 = v4042;
  }
  int * v4045 = v3990->regs;
  v4045[7] = v4044;
  struct StateT * v7740 = v4047(v3990);
  return v7740;
}

struct StateT * v11075(struct StateT * v11076) {
  int v11077 = v11076->timer;
  int v16810 = v11077 + 1;
  v11076->timer = v16810;
  int * v11079 = v11076->regs;
  int v11080 = v11079[17];
  int * v11081 = v11076->regs;
  int v11082 = v11081[19];
  int * v11083 = v11076->regs;
  int v16817 = v11080 + v11082;
  v11083[6] = v16817;
  struct StateT * v16808 = v11085(v11076);
  return v16808;
}

struct StateT * v11295(struct StateT * v11296) {
  int v11297 = v11296->timer;
  int v16556 = v11297 + 1;
  v11296->timer = v16556;
  int * v11299 = v11296->regs;
  int v11300 = v11299[11];
  int * v11301 = v11296->regs;
  int v11302 = v11301[9];
  int * v11303 = v11296->regs;
  int v16562 = v11300 | v11302;
  v11303[11] = v16562;
  struct StateT * v16554 = v11305(v11296);
  return v16554;
}

struct StateT * v2343(struct StateT * v2344) {
  int v2345 = v2344->timer;
  int v21654 = v2345 + 1;
  v2344->timer = v21654;
  int * v2347 = v2344->regs;
  int v2348 = v2347[18];
  int * v2349 = v2344->regs;
  int v21659 = (int)((unsigned int)v2348 >> 23);
  v2349[20] = v21659;
  struct StateT * v21652 = v2351(v2344);
  return v21652;
}

struct StateT * v1181(struct StateT * v1182) {
  int v1183 = v1182->timer;
  int v22723 = v1183 + 1;
  v1182->timer = v22723;
  int * v1185 = v1182->regs;
  int v1186 = v1185[11];
  int * v1187 = v1182->cache_keys;
  int v1188 = v1187[0];
  bool v22728 = v1188 == ((int)((unsigned int)v1186 >> 2));
  int v1236;
  if (v22728) {
    int * v1189 = v1182->cache_vals;
    int v1190 = v1189[0];
    v1236 = v1190;
  } else {
    int * v1192 = v1182->cache_keys;
    int v1193 = v1192[1];
    bool v22733 = v1193 == ((int)((unsigned int)v1186 >> 2));
    int v1234;
    if (v22733) {
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
      int v22742 = (int)((unsigned int)v1186 >> 2);
      v1204[0] = v22742;
      int * v1206 = v1182->cache_vals;
      v1206[0] = v1195;
      int v1208 = v1182->timer;
      int v22745 = v1208 + 1;
      v1182->timer = v22745;
      v1234 = v1195;
    } else {
      int * v1211 = v1182->mem;
      int v22747 = (int)((unsigned int)v1186 >> 2);
      int v1212 = v1211[v22747];
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
      v1227[0] = v22747;
      int * v1229 = v1182->cache_vals;
      v1229[0] = v1212;
      int v1231 = v1182->timer;
      int v22762 = v1231 + 100;
      v1182->timer = v22762;
      v1234 = v1212;
    }
    v1236 = v1234;
  }
  int * v1237 = v1182->regs;
  v1237[5] = v1236;
  struct StateT * v22721 = v1239(v1182);
  return v22721;
}

struct StateT * v9105(struct StateT * v9106) {
  int v9107 = v9106->timer;
  int v19061 = v9107 + 1;
  v9106->timer = v19061;
  int * v9109 = v9106->regs;
  int v9110 = v9109[17];
  int * v9111 = v9106->regs;
  int v9112 = v9111[6];
  int * v9113 = v9106->regs;
  int v19068 = v9110 ^ v9112;
  v9113[8] = v19068;
  struct StateT * v19059 = v9115(v9106);
  return v19059;
}

struct StateT * v5393(struct StateT * v5394) {
  int v5395 = v5394->timer;
  int v6536 = v5395 + 1;
  v5394->timer = v6536;
  int * v5397 = v5394->regs;
  int v5398 = v5397[2];
  int * v5399 = v5394->cache_keys;
  int v5400 = v5399[0];
  bool v6541 = v5400 == ((int)((unsigned int)(v5398 + 84) >> 2));
  int v5448;
  if (v6541) {
    int * v5401 = v5394->cache_vals;
    int v5402 = v5401[0];
    v5448 = v5402;
  } else {
    int * v5404 = v5394->cache_keys;
    int v5405 = v5404[1];
    bool v6546 = v5405 == ((int)((unsigned int)(v5398 + 84) >> 2));
    int v5446;
    if (v6546) {
      int * v5406 = v5394->cache_vals;
      int v5407 = v5406[1];
      int * v5408 = v5394->cache_keys;
      int * v5409 = v5394->cache_keys;
      int v5410 = v5409[0];
      v5408[1] = v5410;
      int * v5412 = v5394->cache_vals;
      int * v5413 = v5394->cache_vals;
      int v5414 = v5413[0];
      v5412[1] = v5414;
      int * v5416 = v5394->cache_keys;
      int v6555 = (int)((unsigned int)(v5398 + 84) >> 2);
      v5416[0] = v6555;
      int * v5418 = v5394->cache_vals;
      v5418[0] = v5407;
      int v5420 = v5394->timer;
      int v6558 = v5420 + 1;
      v5394->timer = v6558;
      v5446 = v5407;
    } else {
      int * v5423 = v5394->mem;
      int v6560 = (int)((unsigned int)(v5398 + 84) >> 2);
      int v5424 = v5423[v6560];
      int * v5425 = v5394->mem;
      int * v5426 = v5394->cache_keys;
      int v5427 = v5426[1];
      int * v5428 = v5394->cache_vals;
      int v5429 = v5428[1];
      v5425[v5427] = v5429;
      int * v5431 = v5394->cache_keys;
      int * v5432 = v5394->cache_keys;
      int v5433 = v5432[0];
      v5431[1] = v5433;
      int * v5435 = v5394->cache_vals;
      int * v5436 = v5394->cache_vals;
      int v5437 = v5436[0];
      v5435[1] = v5437;
      int * v5439 = v5394->cache_keys;
      v5439[0] = v6560;
      int * v5441 = v5394->cache_vals;
      v5441[0] = v5424;
      int v5443 = v5394->timer;
      int v6575 = v5443 + 100;
      v5394->timer = v6575;
      v5446 = v5424;
    }
    v5448 = v5446;
  }
  int * v5449 = v5394->regs;
  v5449[9] = v5448;
  struct StateT * v6534 = v5451(v5394);
  return v6534;
}

struct StateT * v3675(struct StateT * v3676) {
  int v3677 = v3676->timer;
  int v8064 = v3677 + 1;
  v3676->timer = v8064;
  int * v3679 = v3676->regs;
  int v3680 = v3679[23];
  int * v3681 = v3676->regs;
  int v3682 = v3681[29];
  int * v3683 = v3676->regs;
  int v8070 = v3680 + v3682;
  v3683[29] = v8070;
  struct StateT * v8062 = v3685(v3676);
  return v8062;
}

struct StateT * v9181(struct StateT * v9182) {
  int v9183 = v9182->timer;
  int v18973 = v9183 + 1;
  v9182->timer = v18973;
  int * v9185 = v9182->regs;
  int v9186 = v9185[16];
  int * v9187 = v9182->regs;
  int v18978 = (int)((unsigned int)v9186 >> 14);
  v9187[6] = v18978;
  struct StateT * v18971 = v9189(v9182);
  return v18971;
}

struct StateT * v2291(struct StateT * v2292) {
  int v2293 = v2292->timer;
  int v21714 = v2293 + 1;
  v2292->timer = v21714;
  int * v2295 = v2292->regs;
  int v2296 = v2295[8];
  int * v2297 = v2292->regs;
  int v21719 = (int)((unsigned int)v2296 >> 23);
  v2297[20] = v21719;
  struct StateT * v21712 = v2299(v2292);
  return v21712;
}

struct StateT * v12230(struct StateT * v12231) {
  int v12232 = v12231->timer;
  int v15588 = v12232 + 1;
  v12231->timer = v15588;
  int * v12234 = v12231->regs;
  int v12235 = v12234[2];
  int * v12236 = v12231->cache_keys;
  int v12237 = v12236[0];
  bool v15593 = v12237 == ((int)((unsigned int)(v12235 + 36) >> 2));
  int v12285;
  if (v15593) {
    int * v12238 = v12231->cache_vals;
    int v12239 = v12238[0];
    v12285 = v12239;
  } else {
    int * v12241 = v12231->cache_keys;
    int v12242 = v12241[1];
    bool v15598 = v12242 == ((int)((unsigned int)(v12235 + 36) >> 2));
    int v12283;
    if (v15598) {
      int * v12243 = v12231->cache_vals;
      int v12244 = v12243[1];
      int * v12245 = v12231->cache_keys;
      int * v12246 = v12231->cache_keys;
      int v12247 = v12246[0];
      v12245[1] = v12247;
      int * v12249 = v12231->cache_vals;
      int * v12250 = v12231->cache_vals;
      int v12251 = v12250[0];
      v12249[1] = v12251;
      int * v12253 = v12231->cache_keys;
      int v15607 = (int)((unsigned int)(v12235 + 36) >> 2);
      v12253[0] = v15607;
      int * v12255 = v12231->cache_vals;
      v12255[0] = v12244;
      int v12257 = v12231->timer;
      int v15610 = v12257 + 1;
      v12231->timer = v15610;
      v12283 = v12244;
    } else {
      int * v12260 = v12231->mem;
      int v15612 = (int)((unsigned int)(v12235 + 36) >> 2);
      int v12261 = v12260[v15612];
      int * v12262 = v12231->mem;
      int * v12263 = v12231->cache_keys;
      int v12264 = v12263[1];
      int * v12265 = v12231->cache_vals;
      int v12266 = v12265[1];
      v12262[v12264] = v12266;
      int * v12268 = v12231->cache_keys;
      int * v12269 = v12231->cache_keys;
      int v12270 = v12269[0];
      v12268[1] = v12270;
      int * v12272 = v12231->cache_vals;
      int * v12273 = v12231->cache_vals;
      int v12274 = v12273[0];
      v12272[1] = v12274;
      int * v12276 = v12231->cache_keys;
      v12276[0] = v15612;
      int * v12278 = v12231->cache_vals;
      v12278[0] = v12261;
      int v12280 = v12231->timer;
      int v15627 = v12280 + 100;
      v12231->timer = v15627;
      v12283 = v12261;
    }
    v12285 = v12283;
  }
  int * v12286 = v12231->regs;
  v12286[30] = v12285;
  struct StateT * v15586 = v12288(v12231);
  return v15586;
}

struct StateT * v2993(struct StateT * v2994) {
  int v2995 = v2994->timer;
  int v20918 = v2995 + 1;
  v2994->timer = v20918;
  int * v2997 = v2994->regs;
  int v2998 = v2997[8];
  int * v2999 = v2994->regs;
  int v3000 = v2999[16];
  int * v3001 = v2994->regs;
  int v20925 = v2998 ^ v3000;
  v3001[17] = v20925;
  struct StateT * v20916 = v3003(v2994);
  return v20916;
}

struct StateT * v10533(struct StateT * v10534) {
  int v10535 = v10534->timer;
  int v17430 = v10535 + 1;
  v10534->timer = v17430;
  int * v10537 = v10534->regs;
  int v10538 = v10537[8];
  int * v10539 = v10534->regs;
  int v17435 = (int)((unsigned int)v10538 >> 19);
  v10539[20] = v17435;
  struct StateT * v17428 = v10541(v10534);
  return v17428;
}

struct StateT * v10497(struct StateT * v10498) {
  int v10499 = v10498->timer;
  int v17470 = v10499 + 1;
  v10498->timer = v17470;
  int * v10501 = v10498->regs;
  int v10502 = v10501[25];
  int * v10503 = v10498->regs;
  int v10504 = v10503[14];
  int * v10505 = v10498->regs;
  int v17477 = v10502 + v10504;
  v10505[18] = v17477;
  struct StateT * v17468 = v10507(v10498);
  return v17468;
}

struct StateT * v8611(struct StateT * v8612) {
  int v8613 = v8612->timer;
  int v19634 = v8613 + 1;
  v8612->timer = v19634;
  int * v8615 = v8612->regs;
  int v8616 = v8615[15];
  int * v8617 = v8612->regs;
  int v19638 = v8616 << 7;
  v8617[15] = v19638;
  struct StateT * v19632 = v8619(v8612);
  return v19632;
}

struct StateT * v9667(struct StateT * v9668) {
  int v9669 = v9668->timer;
  int v18408 = v9669 + 1;
  v9668->timer = v18408;
  int * v9671 = v9668->regs;
  int v9672 = v9671[27];
  int * v9673 = v9668->regs;
  int v9674 = v9673[23];
  int * v9675 = v9668->regs;
  int v18415 = v9672 + v9674;
  v9675[11] = v18415;
  struct StateT * v18406 = v9677(v9668);
  return v18406;
}

struct StateT * v8847(struct StateT * v8848) {
  int v8849 = v8848->timer;
  int v19362 = v8849 + 1;
  v8848->timer = v19362;
  int * v8851 = v8848->regs;
  int v8852 = v8851[9];
  int * v8853 = v8848->regs;
  int v19366 = v8852 << 9;
  v8853[9] = v19366;
  struct StateT * v19360 = v8855(v8848);
  return v19360;
}

struct StateT * v10997(struct StateT * v10998) {
  int v10999 = v10998->timer;
  int v16905 = v10999 + 1;
  v10998->timer = v16905;
  int * v11001 = v10998->regs;
  int v11002 = v11001[17];
  int * v11003 = v10998->regs;
  int v16909 = v11002 << 7;
  v11003[17] = v16909;
  struct StateT * v16903 = v11005(v10998);
  return v16903;
}

struct StateT * v3279(struct StateT * v3280) {
  int v3281 = v3280->timer;
  int v20586 = v3281 + 1;
  v3280->timer = v20586;
  int * v3283 = v3280->regs;
  int v3284 = v3283[15];
  int * v3285 = v3280->regs;
  int v3286 = v3285[9];
  int * v3287 = v3280->regs;
  int v20592 = v3284 | v3286;
  v3287[15] = v20592;
  struct StateT * v20584 = v3289(v3280);
  return v20584;
}

struct StateT * v11321(struct StateT * v11322) {
  int v11323 = v11322->timer;
  int v16526 = v11323 + 1;
  v11322->timer = v16526;
  int * v11325 = v11322->regs;
  int v11326 = v11325[15];
  int * v11327 = v11322->regs;
  int v11328 = v11327[9];
  int * v11329 = v11322->regs;
  int v16532 = v11326 | v11328;
  v11329[15] = v16532;
  struct StateT * v16524 = v11331(v11322);
  return v16524;
}

struct StateT * v4047(struct StateT * v4048) {
  int v4049 = v4048->timer;
  int v7731 = v4049 + 1;
  v4048->timer = v7731;
  int * v4051 = v4048->regs;
  int v4052 = v4051[13];
  int * v4053 = v4048->regs;
  int v4054 = v4053[7];
  int * v4055 = v4048->regs;
  int v7737 = v4052 + v4054;
  v4055[13] = v7737;
  struct StateT * v7729 = v4057(v4048);
  return v7729;
}

struct StateT * v11884(struct StateT * v11885) {
  int v11886 = v11885->timer;
  int v15891 = v11886 + 1;
  v11885->timer = v15891;
  int * v11888 = v11885->regs;
  int v11889 = v11888[2];
  int * v11890 = v11885->cache_keys;
  int v11891 = v11890[0];
  bool v15896 = v11891 == ((int)((unsigned int)(v11889 + 16) >> 2));
  int v11939;
  if (v15896) {
    int * v11892 = v11885->cache_vals;
    int v11893 = v11892[0];
    v11939 = v11893;
  } else {
    int * v11895 = v11885->cache_keys;
    int v11896 = v11895[1];
    bool v15901 = v11896 == ((int)((unsigned int)(v11889 + 16) >> 2));
    int v11937;
    if (v15901) {
      int * v11897 = v11885->cache_vals;
      int v11898 = v11897[1];
      int * v11899 = v11885->cache_keys;
      int * v11900 = v11885->cache_keys;
      int v11901 = v11900[0];
      v11899[1] = v11901;
      int * v11903 = v11885->cache_vals;
      int * v11904 = v11885->cache_vals;
      int v11905 = v11904[0];
      v11903[1] = v11905;
      int * v11907 = v11885->cache_keys;
      int v15910 = (int)((unsigned int)(v11889 + 16) >> 2);
      v11907[0] = v15910;
      int * v11909 = v11885->cache_vals;
      v11909[0] = v11898;
      int v11911 = v11885->timer;
      int v15913 = v11911 + 1;
      v11885->timer = v15913;
      v11937 = v11898;
    } else {
      int * v11914 = v11885->mem;
      int v15915 = (int)((unsigned int)(v11889 + 16) >> 2);
      int v11915 = v11914[v15915];
      int * v11916 = v11885->mem;
      int * v11917 = v11885->cache_keys;
      int v11918 = v11917[1];
      int * v11919 = v11885->cache_vals;
      int v11920 = v11919[1];
      v11916[v11918] = v11920;
      int * v11922 = v11885->cache_keys;
      int * v11923 = v11885->cache_keys;
      int v11924 = v11923[0];
      v11922[1] = v11924;
      int * v11926 = v11885->cache_vals;
      int * v11927 = v11885->cache_vals;
      int v11928 = v11927[0];
      v11926[1] = v11928;
      int * v11930 = v11885->cache_keys;
      v11930[0] = v15915;
      int * v11932 = v11885->cache_vals;
      v11932[0] = v11915;
      int v11934 = v11885->timer;
      int v15930 = v11934 + 100;
      v11885->timer = v15930;
      v11937 = v11915;
    }
    v11939 = v11937;
  }
  int * v11940 = v11885->regs;
  v11940[7] = v11939;
  struct StateT * v15889 = v11942(v11885);
  return v15889;
}

struct StateT * v1853(struct StateT * v1854) {
  int v1855 = v1854->timer;
  int v22141 = v1855 + 1;
  v1854->timer = v22141;
  int * v1857 = v1854->regs;
  int v1858 = v1857[2];
  int * v1859 = v1854->regs;
  int v1860 = v1859[6];
  int * v1861 = v1854->cache_keys;
  int v1862 = v1861[0];
  bool v22148 = v1862 == ((int)((unsigned int)(v1858 + 8) >> 2));
  int v1906;
  if (v22148) {
    int * v1863 = v1854->cache_vals;
    v1863[0] = v1860;
    v1906 = v1860;
  } else {
    int * v1866 = v1854->cache_keys;
    int v1867 = v1866[1];
    bool v22153 = v1867 == ((int)((unsigned int)(v1858 + 8) >> 2));
    int v1904;
    if (v22153) {
      int * v1868 = v1854->cache_keys;
      int * v1869 = v1854->cache_keys;
      int v1870 = v1869[0];
      v1868[1] = v1870;
      int * v1872 = v1854->cache_vals;
      int * v1873 = v1854->cache_vals;
      int v1874 = v1873[0];
      v1872[1] = v1874;
      int * v1876 = v1854->cache_keys;
      int v22161 = (int)((unsigned int)(v1858 + 8) >> 2);
      v1876[0] = v22161;
      int * v1878 = v1854->cache_vals;
      v1878[0] = v1860;
      int v1880 = v1854->timer;
      int v22164 = v1880 + 1;
      v1854->timer = v22164;
      v1904 = v1860;
    } else {
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
      int v22177 = (int)((unsigned int)(v1858 + 8) >> 2);
      v1897[0] = v22177;
      int * v1899 = v1854->cache_vals;
      v1899[0] = v1860;
      int v1901 = v1854->timer;
      int v22180 = v1901 + 100;
      v1854->timer = v22180;
      v1904 = v1860;
    }
    v1906 = v1904;
  }
  struct StateT * v22139 = v1907(v1854);
  return v22139;
}

struct StateT * v3473(struct StateT * v3474) {
  int v3475 = v3474->timer;
  int v20364 = v3475 + 1;
  v3474->timer = v20364;
  int * v3477 = v3474->regs;
  int v3478 = v3477[6];
  int * v3479 = v3474->regs;
  int v20369 = (int)((unsigned int)v3478 >> 14);
  v3479[9] = v20369;
  struct StateT * v20362 = v3481(v3474);
  return v20362;
}

struct StateT * v3701(struct StateT * v3702) {
  int v3703 = v3702->timer;
  int v8034 = v3703 + 1;
  v3702->timer = v8034;
  int * v3705 = v3702->regs;
  int v3706 = v3705[14];
  int * v3707 = v3702->regs;
  int v3708 = v3707[7];
  int * v3709 = v3702->regs;
  int v8040 = v3706 + v3708;
  v3709[14] = v8040;
  struct StateT * v8032 = v3711(v3702);
  return v8032;
}

struct StateT * v10477(struct StateT * v10478) {
  int v10479 = v10478->timer;
  int v17494 = v10479 + 1;
  v10478->timer = v17494;
  int * v10481 = v10478->regs;
  int v10482 = v10481[24];
  int * v10483 = v10478->regs;
  int v10484 = v10483[13];
  int * v10485 = v10478->regs;
  int v17501 = v10482 + v10484;
  v10485[8] = v17501;
  struct StateT * v17492 = v10487(v10478);
  return v17492;
}

struct StateT * v4413(struct StateT * v4414) {
  int v4415 = v4414->timer;
  int v7354 = v4415 + 1;
  v4414->timer = v7354;
  int * v4417 = v4414->regs;
  int v4418 = v4417[10];
  int * v4419 = v4414->regs;
  int v4420 = v4419[15];
  int * v4421 = v4414->cache_keys;
  int v4422 = v4421[0];
  bool v7361 = v4422 == ((int)((unsigned int)v4418 >> 2));
  int v4466;
  if (v7361) {
    int * v4423 = v4414->cache_vals;
    v4423[0] = v4420;
    v4466 = v4420;
  } else {
    int * v4426 = v4414->cache_keys;
    int v4427 = v4426[1];
    bool v7366 = v4427 == ((int)((unsigned int)v4418 >> 2));
    int v4464;
    if (v7366) {
      int * v4428 = v4414->cache_keys;
      int * v4429 = v4414->cache_keys;
      int v4430 = v4429[0];
      v4428[1] = v4430;
      int * v4432 = v4414->cache_vals;
      int * v4433 = v4414->cache_vals;
      int v4434 = v4433[0];
      v4432[1] = v4434;
      int * v4436 = v4414->cache_keys;
      int v7374 = (int)((unsigned int)v4418 >> 2);
      v4436[0] = v7374;
      int * v4438 = v4414->cache_vals;
      v4438[0] = v4420;
      int v4440 = v4414->timer;
      int v7377 = v4440 + 1;
      v4414->timer = v7377;
      v4464 = v4420;
    } else {
      int * v4443 = v4414->mem;
      int * v4444 = v4414->cache_keys;
      int v4445 = v4444[1];
      int * v4446 = v4414->cache_vals;
      int v4447 = v4446[1];
      v4443[v4445] = v4447;
      int * v4449 = v4414->cache_keys;
      int * v4450 = v4414->cache_keys;
      int v4451 = v4450[0];
      v4449[1] = v4451;
      int * v4453 = v4414->cache_vals;
      int * v4454 = v4414->cache_vals;
      int v4455 = v4454[0];
      v4453[1] = v4455;
      int * v4457 = v4414->cache_keys;
      int v7390 = (int)((unsigned int)v4418 >> 2);
      v4457[0] = v7390;
      int * v4459 = v4414->cache_vals;
      v4459[0] = v4420;
      int v4461 = v4414->timer;
      int v7393 = v4461 + 100;
      v4414->timer = v7393;
      v4464 = v4420;
    }
    v4466 = v4464;
  }
  struct StateT * v7352 = v4467(v4414);
  return v7352;
}

struct StateT * v10401(struct StateT * v10402) {
  int v10403 = v10402->timer;
  int v17574 = v10403 + 1;
  v10402->timer = v17574;
  int * v10405 = v10402->regs;
  int v10406 = v10405[18];
  int * v10407 = v10402->regs;
  int v10408 = v10407[20];
  int * v10409 = v10402->regs;
  int v17580 = v10406 | v10408;
  v10409[18] = v17580;
  struct StateT * v17572 = v10411(v10402);
  return v17572;
}

struct StateT * v10585(struct StateT * v10586) {
  int v10587 = v10586->timer;
  int v17370 = v10587 + 1;
  v10586->timer = v17370;
  int * v10589 = v10586->regs;
  int v10590 = v10589[18];
  int * v10591 = v10586->regs;
  int v17375 = (int)((unsigned int)v10590 >> 19);
  v10591[9] = v17375;
  struct StateT * v17368 = v10593(v10586);
  return v17368;
}

struct StateT * v9891(struct StateT * v9892) {
  int v9893 = v9892->timer;
  int v18150 = v9893 + 1;
  v9892->timer = v18150;
  int * v9895 = v9892->regs;
  int v9896 = v9895[11];
  int * v9897 = v9892->regs;
  int v18155 = (int)((unsigned int)v9896 >> 14);
  v9897[9] = v18155;
  struct StateT * v18148 = v9899(v9892);
  return v18148;
}

struct StateT * v2641(struct StateT * v2642) {
  int * v2643 = v2642->saved_regs;
  int * v2644 = v2642->regs;
  int v2645 = v2644[17];
  v2643[17] = v2645;
  int v2647 = v2642->timer;
  int v21318 = v2647 + 1;
  v2642->timer = v21318;
  int * v2649 = v2642->regs;
  int v2650 = v2649[18];
  int * v2651 = v2642->regs;
  int v2652 = v2651[27];
  int * v2653 = v2642->regs;
  int v21324 = v2650 + v2652;
  v2653[17] = v21324;
  struct StateT * v21312 = v2655(v2642);
  return v21312;
}

struct StateT * v11219(struct StateT * v11220) {
  int v11221 = v11220->timer;
  int v16645 = v11221 + 1;
  v11220->timer = v16645;
  int * v11223 = v11220->regs;
  int v11224 = v11223[26];
  int * v11225 = v11220->regs;
  int v11226 = v11225[6];
  int * v11227 = v11220->regs;
  int v16651 = v11224 ^ v11226;
  v11227[26] = v16651;
  struct StateT * v16643 = v11229(v11220);
  return v16643;
}

struct StateT * v11597(struct StateT * v11598) {
  int v11599 = v11598->timer;
  int v16209 = v11599 + 1;
  v11598->timer = v16209;
  int * v11601 = v11598->regs;
  int v11602 = v11601[22];
  int * v11603 = v11598->regs;
  int v11604 = v11603[8];
  int * v11605 = v11598->regs;
  int v16215 = v11602 ^ v11604;
  v11605[22] = v16215;
  struct StateT * v16207 = v11607(v11598);
  return v16207;
}

struct StateT * v8855(struct StateT * v8856) {
  int v8857 = v8856->timer;
  int v19351 = v8857 + 1;
  v8856->timer = v19351;
  int * v8859 = v8856->regs;
  int v8860 = v8859[9];
  int * v8861 = v8856->regs;
  int v8862 = v8861[20];
  int * v8863 = v8856->regs;
  int v19357 = v8860 | v8862;
  v8863[9] = v19357;
  struct StateT * v19349 = v8865(v8856);
  return v19349;
}

struct StateT * v2099(struct StateT * v2100) {
  int v2101 = v2100->timer;
  int v21929 = v2101 + 1;
  v2100->timer = v21929;
  int * v2103 = v2100->regs;
  int v2104 = v2103[20];
  int * v2105 = v2100->regs;
  int v21933 = v2104 << 7;
  v2105[20] = v21933;
  struct StateT * v21927 = v2107(v2100);
  return v21927;
}

struct StateT * v9943(struct StateT * v9944) {
  int v9945 = v9944->timer;
  int v18090 = v9945 + 1;
  v9944->timer = v18090;
  int * v9947 = v9944->regs;
  int v9948 = v9947[6];
  int * v9949 = v9944->regs;
  int v18095 = (int)((unsigned int)v9948 >> 14);
  v9949[9] = v18095;
  struct StateT * v18088 = v9951(v9944);
  return v18088;
}

struct StateT * v1923(struct StateT * v1924) {
  int v1925 = v1924->timer;
  int v22111 = v1925 + 1;
  v1924->timer = v22111;
  int * v1927 = v1924->regs;
  int v1928 = v1927[28];
  int * v1929 = v1924->regs;
  v1929[27] = v1928;
  struct StateT * v22109 = v1931(v1924);
  return v22109;
}

struct StateT * v1583(struct StateT * v1584) {
  int v1585 = v1584->timer;
  int v22365 = v1585 + 1;
  v1584->timer = v22365;
  int * v1587 = v1584->regs;
  int v1588 = v1587[2];
  int * v1589 = v1584->regs;
  int v1590 = v1589[5];
  int * v1591 = v1584->cache_keys;
  int v1592 = v1591[0];
  bool v22372 = v1592 == ((int)((unsigned int)(v1588 + 12) >> 2));
  int v1636;
  if (v22372) {
    int * v1593 = v1584->cache_vals;
    v1593[0] = v1590;
    v1636 = v1590;
  } else {
    int * v1596 = v1584->cache_keys;
    int v1597 = v1596[1];
    bool v22377 = v1597 == ((int)((unsigned int)(v1588 + 12) >> 2));
    int v1634;
    if (v22377) {
      int * v1598 = v1584->cache_keys;
      int * v1599 = v1584->cache_keys;
      int v1600 = v1599[0];
      v1598[1] = v1600;
      int * v1602 = v1584->cache_vals;
      int * v1603 = v1584->cache_vals;
      int v1604 = v1603[0];
      v1602[1] = v1604;
      int * v1606 = v1584->cache_keys;
      int v22385 = (int)((unsigned int)(v1588 + 12) >> 2);
      v1606[0] = v22385;
      int * v1608 = v1584->cache_vals;
      v1608[0] = v1590;
      int v1610 = v1584->timer;
      int v22388 = v1610 + 1;
      v1584->timer = v22388;
      v1634 = v1590;
    } else {
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
      int v22401 = (int)((unsigned int)(v1588 + 12) >> 2);
      v1627[0] = v22401;
      int * v1629 = v1584->cache_vals;
      v1629[0] = v1590;
      int v1631 = v1584->timer;
      int v22404 = v1631 + 100;
      v1584->timer = v22404;
      v1634 = v1590;
    }
    v1636 = v1634;
  }
  struct StateT * v22363 = v1637(v1584);
  return v22363;
}

struct StateT * v3121(struct StateT * v3122) {
  int v3123 = v3122->timer;
  int v20768 = v3123 + 1;
  v3122->timer = v20768;
  int * v3125 = v3122->regs;
  int v3126 = v3125[6];
  int * v3127 = v3122->regs;
  int v3128 = v3127[9];
  int * v3129 = v3122->regs;
  int v20774 = v3126 | v3128;
  v3129[6] = v20774;
  struct StateT * v20766 = v3131(v3122);
  return v20766;
}

struct StateT * v9601(struct StateT * v9602) {
  int v9603 = v9602->timer;
  int v18484 = v9603 + 1;
  v9602->timer = v18484;
  int * v9605 = v9602->regs;
  int v9606 = v9605[8];
  int * v9607 = v9602->regs;
  int v18489 = (int)((unsigned int)v9606 >> 23);
  v9607[9] = v18489;
  struct StateT * v18482 = v9609(v9602);
  return v18482;
}

struct StateT * v9841(struct StateT * v9842) {
  int v9843 = v9842->timer;
  int v18208 = v9843 + 1;
  v9842->timer = v18208;
  int * v9845 = v9842->regs;
  int v9846 = v9845[1];
  int * v9847 = v9842->regs;
  int v9848 = v9847[8];
  int * v9849 = v9842->regs;
  int v18214 = v9846 ^ v9848;
  v9849[1] = v18214;
  struct StateT * v18206 = v9851(v9842);
  return v18206;
}

struct StateT * v8737(struct StateT * v8738) {
  int v8739 = v8738->timer;
  int v19489 = v8739 + 1;
  v8738->timer = v19489;
  int * v8741 = v8738->regs;
  int v8742 = v8741[14];
  int * v8743 = v8738->regs;
  int v8744 = v8743[8];
  int * v8745 = v8738->regs;
  int v19495 = v8742 ^ v8744;
  v8745[14] = v19495;
  struct StateT * v19487 = v8747(v8738);
  return v19487;
}

struct StateT * v1931(struct StateT * v1932) {
  int v1933 = v1932->timer;
  int v22101 = v1933 + 1;
  v1932->timer = v22101;
  int * v1935 = v1932->regs;
  int v1936 = v1935[29];
  int * v1937 = v1932->regs;
  v1937[23] = v1936;
  struct StateT * v22099 = v1939(v1932);
  return v22099;
}

struct StateT * v9951(struct StateT * v9952) {
  int v9953 = v9952->timer;
  int v18081 = v9953 + 1;
  v9952->timer = v18081;
  int * v9955 = v9952->regs;
  int v9956 = v9955[6];
  int * v9957 = v9952->regs;
  int v18085 = v9956 << 18;
  v9957[6] = v18085;
  struct StateT * v18079 = v9959(v9952);
  return v18079;
}

struct StateT * v9899(struct StateT * v9900) {
  int v9901 = v9900->timer;
  int v18141 = v9901 + 1;
  v9900->timer = v18141;
  int * v9903 = v9900->regs;
  int v9904 = v9903[11];
  int * v9905 = v9900->regs;
  int v18145 = v9904 << 18;
  v9905[11] = v18145;
  struct StateT * v18139 = v9907(v9900);
  return v18139;
}

struct StateT * v9365(struct StateT * v9366) {
  int v9367 = v9366->timer;
  int v18760 = v9367 + 1;
  v9366->timer = v18760;
  int * v9369 = v9366->regs;
  int v9370 = v9369[11];
  int * v9371 = v9366->regs;
  int v18765 = (int)((unsigned int)v9370 >> 25);
  v9371[5] = v18765;
  struct StateT * v18758 = v9373(v9366);
  return v18758;
}

struct StateT * v11810(struct StateT * v11811) {
  int v11812 = v11811->timer;
  int v15998 = v11812 + 1;
  v11811->timer = v15998;
  int * v11814 = v11811->regs;
  v11814[6] = 857759744;
  struct StateT * v15996 = v11816(v11811);
  return v15996;
}

struct StateT * v12404(struct StateT * v12405) {
  int v12406 = v12405->timer;
  int v15463 = v12406 + 1;
  v12405->timer = v15463;
  int * v12408 = v12405->regs;
  int v12409 = v12408[21];
  int * v12410 = v12405->regs;
  int v12411 = v12410[15];
  int * v12412 = v12405->regs;
  int v15469 = v12409 + v12411;
  v12412[15] = v15469;
  struct StateT * v15461 = v12414(v12405);
  return v15461;
}

struct StateT * v8583(struct StateT * v8584) {
  int v8585 = v8584->timer;
  int v19665 = v8585 + 1;
  v8584->timer = v19665;
  int * v8587 = v8584->regs;
  int v8588 = v8587[19];
  int * v8589 = v8584->regs;
  int v8590 = v8589[5];
  int * v8591 = v8584->regs;
  int v19672 = v8588 + v8590;
  v8591[18] = v19672;
  struct StateT * v19663 = v8593(v8584);
  return v19663;
}

struct StateT * v9125(struct StateT * v9126) {
  int v9127 = v9126->timer;
  int v19037 = v9127 + 1;
  v9126->timer = v19037;
  int * v9129 = v9126->regs;
  int v9130 = v9129[23];
  int * v9131 = v9126->regs;
  int v9132 = v9131[24];
  int * v9133 = v9126->regs;
  int v19044 = v9130 + v9132;
  v9133[16] = v19044;
  struct StateT * v19035 = v9135(v9126);
  return v19035;
}

struct StateT * v10567(struct StateT * v10568) {
  int v10569 = v10568->timer;
  int v17391 = v10569 + 1;
  v10568->timer = v17391;
  int * v10571 = v10568->regs;
  int v10572 = v10571[9];
  int * v10573 = v10568->regs;
  int v17395 = v10572 << 13;
  v10573[9] = v17395;
  struct StateT * v17389 = v10575(v10568);
  return v17389;
}

struct StateT * v3401(struct StateT * v3402) {
  int v3403 = v3402->timer;
  int v20446 = v3403 + 1;
  v3402->timer = v20446;
  int * v3405 = v3402->regs;
  int v3406 = v3405[13];
  int * v3407 = v3402->regs;
  int v3408 = v3407[26];
  int * v3409 = v3402->regs;
  int v20453 = v3406 + v3408;
  v3409[6] = v20453;
  struct StateT * v20444 = v3411(v3402);
  return v20444;
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