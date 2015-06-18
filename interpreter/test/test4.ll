; ModuleID = 'test4.bc'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: nounwind uwtable
define i32 @main() #0 {
  %1 = alloca i32, align 4
  %a = alloca i32, align 4
  %b = alloca i32, align 4
  %g = alloca i32, align 4
  store i32 0, i32* %1
  store i32 1, i32* %a, align 4
  store i32 0, i32* %b, align 4
  store i32 1, i32* %g, align 4
  br label %2

; <label>:2                                       ; preds = %13, %0
  %3 = load i32* %g, align 4
  %4 = icmp eq i32 %3, 1
  br i1 %4, label %5, label %11

; <label>:5                                       ; preds = %2
  %6 = load i32* %b, align 4
  %7 = icmp eq i32 %6, 0
  br i1 %7, label %8, label %11

; <label>:8                                       ; preds = %5
  %9 = load i32* %a, align 4
  %10 = icmp eq i32 %9, 1
  br label %11

; <label>:11                                      ; preds = %8, %5, %2
  %12 = phi i1 [ false, %5 ], [ false, %2 ], [ %10, %8 ]
  br i1 %12, label %13, label %16

; <label>:13                                      ; preds = %11
  %14 = load i32* %a, align 4
  %15 = add nsw i32 %14, 1
  store i32 %15, i32* %a, align 4
  br label %2

; <label>:16                                      ; preds = %11
  %17 = load i32* %a, align 4
  ret i32 %17
}

attributes #0 = { nounwind uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = metadata !{metadata !"Ubuntu clang version 3.4-1ubuntu3 (tags/RELEASE_34/final) (based on LLVM 3.4)"}
