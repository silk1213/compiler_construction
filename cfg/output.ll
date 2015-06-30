define i32 @main() #0 {
  %a = alloca i32, align 4
  store i32 0, i32* %a, align 4
  %b = alloca i32, align 4
  store i32 1, i32* %b, align 4
  %f = alloca double, align 8
  store double 1.1, double* %f, align 8
  %k = alloca double, align 8
  store double 5.8, double* %k, align 8
  br label %label0
   
  label0:
  %1 = load i32* %a , align 4
  %2 = load i32* %b , align 4
  %3 = icmp ne i32 %1, %2
  br i1 %3, label %label3, label %label2
   
  label3:
  %4 = load double* %f , align 8
  %5 = load double* %k , align 8
  %6 = fcmp une double %4, %5
  br i1 %6, label %label1, label %label2
   
  label1:
  %x = alloca i32, align 4
  br label %label0
   
  label2:
  br label %label4
   
  label4:
  %7 = load i32* %a , align 4
  %8 = load i32* %b , align 4
  %9 = icmp ne i32 %7, %8
  br i1 %9, label %label5, label %label6
   
  label5:
  %z = alloca i32, align 4
  br label %label4
   
  label6:
  %10 = load i32* %a , align 4
  %11 = add nsw i32 %10, 1
  store i32 %11, i32* %a, align 4
  ret i32 %11 
}
