define i32 @main() #0 {
  %a = alloca i32, align 4
  store i32 1, i32* %a, align 4
  %b = alloca i32, align 4
  store i32 0, i32* %b, align 4
  %g = alloca i1, align 1
  store i1 1, i1* %g, align 1
  %1 = load i1* %g , align 1
  br i1 %1, label %label1, label %label2
   
  label1:
  %2 = load i32* %a , align 4
  store i32 7, i32* %a, align 4
  %3 = load i1* %g , align 1
  store i1 0, i1* %g  br label %label3
   
  label2:
  br label %label3
   
  label3:
  %4 = load i32* %a , align 4
  %5 = icmp slt i32 %4, 1
  br i1 %5, label %label8, label %label6
   
  label8:
  %6 = load i32* %b , align 4
  %7 = icmp eq i32 %6, 0
  br i1 %7, label %label5, label %label6
   
  label5:
  %8 = load i32* %a , align 4
  %9 = add nsw i32 %8, 1
  store i32 %9, i32* %a, align 4
  br label %label7
   
  label6:
  %10 = load i32* %a , align 4
  %11 = add nsw i32 %10, -1
  store i32 %11, i32* %a, align 4
  br label %label7
   
  label7:
  %12 = load i32* %a , align 4
  ret i32 %12 
}
