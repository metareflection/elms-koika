; ModuleID = './choose.bc'
source_filename = "Module"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

define i32 @choose(i1 %__m1, i32 %__v2_a, i32 %__v3_b) {
entry:
  %__rval = alloca i32
  store i32 0, i32* %__rval
  %__rctx = alloca i1
  store i1 true, i1* %__rctx
  %__v4_output = alloca i32
  store i32 %__v2_a, i32* %__v4_output
  %0 = and i1 true, %__m1
  %1 = load i32, i32* %__v4_output
  %2 = sext i1 %0 to i32
  %3 = xor i32 %__v3_b, %1
  %4 = and i32 %2, %3
  %5 = xor i32 %1, %4
  store i32 %5, i32* %__v4_output
  %__m2 = xor i1 %__m1, true
  %6 = load i32, i32* %__v4_output
  ret i32 %6
}
