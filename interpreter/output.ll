define i32 @main() #0 {
  %a = alloca i32, align 4
  store i32 1, i32* %a, align 4
  %b = alloca i32, align 4
  store i32 0, i32* %b, align 4
  %g = alloca i1, align 1
  store i1 1, i1* %g, align 1
  br label %label0
   
  label0:
  %1 = load i1* %g , align 1
  br i1 %1, label %label1, label %label2
   
  label1:
  %2 = load i32* %a , align 4
  %3 = icmp sgt i32 %2, 7
  br i1 %3, label %label4, label %label5
   
  label4:
  %4 = load i1* %g , align 1
  store i1 0, i1* %g, align 1
  br label %label6
   
  label5:
  %5 = load i32* %a , align 4
  %6 = add nsw i32 %5, 1
  store i32 %6, i32* %a, align 4
  br label %label6
   
  label6:
  br label %label3
   
  label5:
  %7 = load i32* %a , align 4
  ret i32 %7 
}
