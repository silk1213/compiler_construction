define i32 @plus(i32 %a, i32 %b) #0 {
  %1 = alloca i32, align 4
  store i32 %a, i32* %1, align 4
  %2 = alloca i32, align 4
  store i32 %b, i32* %2, align 4
  %3 = load i32* %1 , align 4
  %4 = load i32* %2 , align 4
  %5 = add nsw i32 %3, %4
  ret i32 %5 
}
define double @asd() #0 {
  ret double 1.0 
}
define i32 @main() #0 {
  %a = alloca i32, align 4
  %b = alloca i32, align 4
  %c = alloca double, align 8
  %d = alloca double, align 8
  %1 = load i32* %b , align 4
  store i32 1, i32* %b, align 4
  %2 = load i32* %a , align 4
  store i32 1, i32* %a, align 4
  %3 = load double* %d , align 8
  store double 1.0, double* %d, align 8
  %4 = load double* %c , align 8
  store double 1.0, double* %c, align 8
  %5 = load i32* %a , align 4
  %6 = load i32* %b , align 4
  %7 = sdiv i32 %5, %6
  %8 = load i32* %a , align 4
  %9 = load i32* %b , align 4
  %10 = mul nsw i32 %8, %9
  %11 = load i32* %a , align 4
  %12 = load i32* %b , align 4
  %13 = add nsw i32 %11, %12
  %14 = load i32* %a , align 4
  %15 = load i32* %b , align 4
  %16 = sub nsw i32 %14, %15
  %17 = load double* %c , align 8
  %18 = load double* %d , align 8
  %19 = fdiv double %17, %18
  %20 = load double* %c , align 8
  %21 = load double* %d , align 8
  %22 = fadd double %20, %21
  %23 = load double* %c , align 8
  %24 = load double* %d , align 8
  %25 = fmul double %23, %24
  %26 = load double* %c , align 8
  %27 = load double* %d , align 8
  %28 = fsub double %26, %27
  %29 = load i32* %a , align 4
  %30 = load i32* %b , align 4
  %31 = icmp eq i32 %29, %30
  br i1 %31, label %label1, label %label2
   
  label1:
  br label %label3
   
  label2:
  br label %label3
   
  label3:
  %32 = load i32* %a , align 4
  %33 = load i32* %b , align 4
  %34 = icmp ne i32 %32, %33
  br i1 %34, label %label5, label %label6
   
  label5:
  br label %label7
   
  label6:
  br label %label7
   
  label7:
  %35 = load i32* %a , align 4
  %36 = load i32* %b , align 4
  %37 = icmp sge i32 %35, %36
  br i1 %37, label %label9, label %label10
   
  label9:
  br label %label11
   
  label10:
  br label %label11
   
  label11:
  %38 = load i32* %a , align 4
  %39 = load i32* %b , align 4
  %40 = icmp sle i32 %38, %39
  br i1 %40, label %label13, label %label14
   
  label13:
  br label %label15
   
  label14:
  br label %label15
   
  label15:
  %41 = load i32* %a , align 4
  %42 = load i32* %b , align 4
  %43 = icmp slt i32 %41, %42
  br i1 %43, label %label17, label %label18
   
  label17:
  br label %label19
   
  label18:
  br label %label19
   
  label19:
  %44 = load i32* %a , align 4
  %45 = load i32* %b , align 4
  %46 = icmp sgt i32 %44, %45
  br i1 %46, label %label21, label %label22
   
  label21:
  br label %label23
   
  label22:
  br label %label23
   
  label23:
  %47 = load double* %c , align 8
  %48 = load double* %d , align 8
  %49 = fcmp oeq double %47, %48
  br i1 %49, label %label25, label %label26
   
  label25:
  br label %label27
   
  label26:
  br label %label27
   
  label27:
  %50 = load double* %c , align 8
  %51 = load double* %d , align 8
  %52 = fcmp une double %50, %51
  br i1 %52, label %label29, label %label30
   
  label29:
  br label %label31
   
  label30:
  br label %label31
   
  label31:
  %53 = load double* %c , align 8
  %54 = load double* %d , align 8
  %55 = fcmp oge double %53, %54
  br i1 %55, label %label33, label %label34
   
  label33:
  br label %label35
   
  label34:
  br label %label35
   
  label35:
  %56 = load double* %c , align 8
  %57 = load double* %d , align 8
  %58 = fcmp ole double %56, %57
  br i1 %58, label %label37, label %label38
   
  label37:
  br label %label39
   
  label38:
  br label %label39
   
  label39:
  %59 = load double* %c , align 8
  %60 = load double* %d , align 8
  %61 = fcmp olt double %59, %60
  br i1 %61, label %label41, label %label42
   
  label41:
  br label %label43
   
  label42:
  br label %label43
   
  label43:
  %62 = load double* %c , align 8
  %63 = load double* %d , align 8
  %64 = fcmp ogt double %62, %63
  br i1 %64, label %label45, label %label46
   
  label45:
  br label %label47
   
  label46:
  br label %label47
   
  label47:
  ret i32 1 
}
