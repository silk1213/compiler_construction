; ModuleID = 'test.bc'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: nounwind uwtable
define i32 @square(i32 %a) #0 {
  %1 = alloca i32, align 4
  %y = alloca double, align 8
  %b = alloca i32, align 4
  store i32 %a, i32* %1, align 4
  %2 = load i32* %1, align 4
  %3 = icmp eq i32 %2, 0
  br i1 %3, label %4, label %7

; <label>:4                                       ; preds = %0
  %5 = load i32* %1, align 4
  %6 = add nsw i32 %5, 1
  store i32 %6, i32* %1, align 4
  br label %10

; <label>:7                                       ; preds = %0
  %8 = load i32* %1, align 4
  %9 = add nsw i32 %8, -1
  store i32 %9, i32* %1, align 4
  br label %10

; <label>:10                                      ; preds = %7, %4
  store double 1.000000e-01, double* %y, align 8
  store i32 0, i32* %b, align 4
  %11 = load i32* %1, align 4
  %12 = load i32* %b, align 4
  %13 = sub nsw i32 %11, %12
  store i32 %13, i32* %b, align 4
  %14 = load i32* %1, align 4
  %15 = load i32* %b, align 4
  %16 = mul nsw i32 %14, %15
  ret i32 %16
}

; Function Attrs: nounwind uwtable
define void @test(i32 %a, i32 %b) #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  store i32 %a, i32* %1, align 4
  store i32 %b, i32* %2, align 4
  %3 = load i32* %1, align 4
  %4 = add nsw i32 %3, 1
  store i32 %4, i32* %1, align 4
  ret void
}

; Function Attrs: nounwind uwtable
define i32 @main() #0 {
  %1 = alloca i32, align 4
  %a = alloca i32, align 4
  %b = alloca i32, align 4
  %a1 = alloca i32, align 4
  %c = alloca i32, align 4
  %a12 = alloca i32, align 4
  %b3 = alloca i32, align 4
  %c4 = alloca i32, align 4
  store i32 0, i32* %1
  store i32 1, i32* %a, align 4
  store i32 2, i32* %b, align 4
  %2 = load i32* %a1, align 4
  %3 = add nsw i32 %2, 1
  store i32 %3, i32* %a1, align 4
  %4 = load i32* %a1, align 4
  %5 = load i32* %b, align 4
  call void @test(i32 %4, i32 %5)
  %6 = load i32* %a, align 4
  %7 = add nsw i32 %6, 1
  store i32 %7, i32* %a, align 4
  %8 = load i32* %a, align 4
  ret i32 %8
}

attributes #0 = { nounwind uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = metadata !{metadata !"Ubuntu clang version 3.4-1ubuntu3 (tags/RELEASE_34/final) (based on LLVM 3.4)"}
