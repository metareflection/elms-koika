; @fsum, by src/test/fact/extract. The body is verbatim apart from
; the `internal` that kept it inside its module.
;
; donna/ll/curve25519-c64.ll of PLSysSec/fact-eval@888bc6c6,
; rebuilt in place by `./factc --eval`, so with -no-inline-asm.
; ModuleID = './curve25519-c64.bc'
source_filename = "Module"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

define void @fsum(i64* %__v83_output, i64* %__v84_input) {
entry:
  %__rctx = alloca i1
  store i1 true, i1* %__rctx
  %0 = getelementptr i64, i64* %__v83_output, i64 0
  %1 = getelementptr i64, i64* %__v83_output, i64 0
  %2 = load i64, i64* %1
  %3 = getelementptr i64, i64* %__v84_input, i64 0
  %4 = load i64, i64* %3
  %5 = add i64 %2, %4
  store i64 %5, i64* %0
  %6 = getelementptr i64, i64* %__v83_output, i64 1
  %7 = getelementptr i64, i64* %__v83_output, i64 1
  %8 = load i64, i64* %7
  %9 = getelementptr i64, i64* %__v84_input, i64 1
  %10 = load i64, i64* %9
  %11 = add i64 %8, %10
  store i64 %11, i64* %6
  %12 = getelementptr i64, i64* %__v83_output, i64 2
  %13 = getelementptr i64, i64* %__v83_output, i64 2
  %14 = load i64, i64* %13
  %15 = getelementptr i64, i64* %__v84_input, i64 2
  %16 = load i64, i64* %15
  %17 = add i64 %14, %16
  store i64 %17, i64* %12
  %18 = getelementptr i64, i64* %__v83_output, i64 3
  %19 = getelementptr i64, i64* %__v83_output, i64 3
  %20 = load i64, i64* %19
  %21 = getelementptr i64, i64* %__v84_input, i64 3
  %22 = load i64, i64* %21
  %23 = add i64 %20, %22
  store i64 %23, i64* %18
  %24 = getelementptr i64, i64* %__v83_output, i64 4
  %25 = getelementptr i64, i64* %__v83_output, i64 4
  %26 = load i64, i64* %25
  %27 = getelementptr i64, i64* %__v84_input, i64 4
  %28 = load i64, i64* %27
  %29 = add i64 %26, %28
  store i64 %29, i64* %24
  ret void
}
attributes #0 = { argmemonly nounwind }
