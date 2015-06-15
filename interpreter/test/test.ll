; ModuleID = 'test.bc'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: nounwind uwtable
define i32 @square(i32 %a) #0 {
  %1 = alloca i32, align 4
  %y = alloca double, align 8
  %b = alloca i32, align 4
  store i32 %a, i32* %1, align 4
  store double 1.000000e-01, double* %y, align 8
  store i32 0, i32* %b, align 4
  %2 = load i32* %1, align 4
  %3 = load i32* %b, align 4
  %4 = mul nsw i32 %2, %3
  ret i32 %4
}

; Function Attrs: nounwind uwtable
define void @test(i32 %a, i32 %b) #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %c = alloca i32, align 4
  %x = alloca i32, align 4
  store i32 %a, i32* %1, align 4
  store i32 %b, i32* %2, align 4
  %3 = load i32* %1, align 4
  store i32 %3, i32* %c, align 4
  store i32 1, i32* %x, align 4
  br label %4

; <label>:4                                       ; preds = %8, %0
  %5 = load i32* %x, align 4
  %6 = load i32* %c, align 4
  %7 = icmp eq i32 %5, %6
  br i1 %7, label %8, label %11

; <label>:8                                       ; preds = %4
  %9 = load i32* %c, align 4
  %10 = add nsw i32 %9, 1
  store i32 %10, i32* %c, align 4
  br label %4

; <label>:11                                      ; preds = %4
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
  %2 = load i32* %a1, align 4
  %3 = add nsw i32 %2, 1
  store i32 %3, i32* %a1, align 4
  %4 = load i32* %a, align 4
  %5 = add nsw i32 %4, 1
  store i32 %5, i32* %a, align 4
  ret i32 0
}

attributes #0 = { nounwind uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = metadata !{metadata !"clang version 3.4.2 (tags/RELEASE_34/dot2-final)"}
