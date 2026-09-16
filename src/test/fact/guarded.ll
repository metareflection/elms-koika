; ModuleID = './guarded.bc'
source_filename = "Module"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

define void @guarded_lookup(i32 %__v1_idx, i32* %__v2_table, i32* %__v3_key, i32* %__v4_out) {
entry:
  %__rctx = alloca i1
  store i1 true, i1* %__rctx
  %0 = getelementptr i32, i32* %__v3_key, i64 0
  %1 = load i32, i32* %0
  %2 = getelementptr i32, i32* %__v2_table, i64 3
  %3 = load i32, i32* %2
  %4 = xor i32 %1, %3
  %__v5_acc = alloca i32
  store i32 %4, i32* %__v5_acc
  %5 = icmp ult i32 %__v1_idx, 16
  br i1 %5, label %6, label %13

; <label>:6:                                      ; preds = %entry
  %__v7_lexpr = zext i32 %__v1_idx to i64
  %7 = getelementptr i32, i32* %__v2_table, i64 %__v7_lexpr
  %__v6_t = load i32, i32* %7
  %8 = and i32 %__v6_t, 15
  %__v8_lexpr = zext i32 %8 to i64
  %9 = load i32, i32* %__v5_acc
  %10 = getelementptr i32, i32* %__v2_table, i64 %__v8_lexpr
  %11 = load i32, i32* %10
  %12 = add i32 %9, %11
  store i32 %12, i32* %__v5_acc
  br label %14

; <label>:13:                                     ; preds = %entry
  br label %14

; <label>:14:                                     ; preds = %13, %6
  %15 = and i32 %__v1_idx, 7
  %__v9_lexpr = zext i32 %15 to i64
  %16 = getelementptr i32, i32* %__v4_out, i64 %__v9_lexpr
  %17 = load i32, i32* %__v5_acc
  store i32 %17, i32* %16
  ret void
}
