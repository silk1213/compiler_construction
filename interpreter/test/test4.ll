; ModuleID = './test4.bc'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: nounwind uwtable
define i32 @main() #0 {
  %1 = alloca i32, align 4
  %a = alloca i32, align 4
  store i32 0, i32* %1
  store i32 1, i32* %a, align 4
  %2 = load i32* %a, align 4
  %3 = icmp slt i32 %2, 1
  br i1 %3, label %4, label %7

; <label>:4                                       ; preds = %0
  %5 = load i32* %a, align 4
  %6 = add nsw i32 %5, 1
  store i32 %6, i32* %a, align 4
  br label %10

; <label>:7                                       ; preds = %0
  %8 = load i32* %a, align 4
  %9 = add nsw i32 %8, -1
  store i32 %9, i32* %a, align 4
  br label %10

; <label>:10                                      ; preds = %7, %4
  %11 = load i32* %a, align 4
  ret i32 %11
}

attributes #0 = { nounwind uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.6.1 (tags/RELEASE_361/final)"}
