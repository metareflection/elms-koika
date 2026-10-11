; @fdifference_backwards, by src/test/fact/extract. The body is verbatim apart from
; the `internal` that kept it inside its module.
;
; donna/ll/curve25519-c64.ll of PLSysSec/fact-eval@888bc6c6,
; rebuilt in place by `./factc --eval`, so with -no-inline-asm.
; ModuleID = './curve25519-c64.bc'
source_filename = "Module"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

define void @fdifference_backwards(i64* %__v75_out, i64* %__v76_input) {
entry:
  %__rctx = alloca i1
  store i1 true, i1* %__rctx
  %0 = getelementptr i64, i64* %__v75_out, i64 0
  %1 = getelementptr i64, i64* %__v76_input, i64 0
  %2 = load i64, i64* %1
  %3 = add i64 %2, 18014398509481832
  %4 = getelementptr i64, i64* %__v75_out, i64 0
  %5 = load i64, i64* %4
  %6 = sub i64 %3, %5
  store i64 %6, i64* %0
  %7 = getelementptr i64, i64* %__v75_out, i64 1
  %8 = getelementptr i64, i64* %__v76_input, i64 1
  %9 = load i64, i64* %8
  %10 = add i64 %9, 18014398509481976
  %11 = getelementptr i64, i64* %__v75_out, i64 1
  %12 = load i64, i64* %11
  %13 = sub i64 %10, %12
  store i64 %13, i64* %7
  %14 = getelementptr i64, i64* %__v75_out, i64 2
  %15 = getelementptr i64, i64* %__v76_input, i64 2
  %16 = load i64, i64* %15
  %17 = add i64 %16, 18014398509481976
  %18 = getelementptr i64, i64* %__v75_out, i64 2
  %19 = load i64, i64* %18
  %20 = sub i64 %17, %19
  store i64 %20, i64* %14
  %21 = getelementptr i64, i64* %__v75_out, i64 3
  %22 = getelementptr i64, i64* %__v76_input, i64 3
  %23 = load i64, i64* %22
  %24 = add i64 %23, 18014398509481976
  %25 = getelementptr i64, i64* %__v75_out, i64 3
  %26 = load i64, i64* %25
  %27 = sub i64 %24, %26
  store i64 %27, i64* %21
  %28 = getelementptr i64, i64* %__v75_out, i64 4
  %29 = getelementptr i64, i64* %__v76_input, i64 4
  %30 = load i64, i64* %29
  %31 = add i64 %30, 18014398509481976
  %32 = getelementptr i64, i64* %__v75_out, i64 4
  %33 = load i64, i64* %32
  %34 = sub i64 %31, %33
  store i64 %34, i64* %28
  ret void
}
attributes #0 = { argmemonly nounwind }
