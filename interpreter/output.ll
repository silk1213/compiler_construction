define i32 @main() #0 {
  %a = alloca i1, align 1
  %b = alloca i1, align 1
  %c = alloca i1, align 1
  %d = alloca i1, align 1
  %e = alloca i1, align 1
  %f = alloca i1, align 1
  %1 = load i1* %f , align 1
  store i1 1, i1* %f, align 1
  %2 = load i1* %e , align 1
  store i1 1, i1* %e, align 1
  %3 = load i1* %d , align 1
  store i1 1, i1* %d, align 1
  %4 = load i1* %c , align 1
  store i1 1, i1* %c, align 1
  %5 = load i1* %b , align 1
  store i1 1, i1* %b, align 1
  %6 = load i1* %a , align 1
  store i1 1, i1* %a, align 1
  %h = alloca i32, align 4
  store i32 0, i32* %h, align 4
  br label %label0
   
  label0:
  %7 = load i1* %a , align 1
  br i1 %7, label %label7, label %label4
   
  label7:
  %8 = load i1* %b , align 1
  br i1 %8, label %label6, label %label4
   
  label6:
  %9 = load i1* %c , align 1
  br i1 %9, label %label5, label %label4
   
  label5:
  %10 = load i1* %d , align 1
  br i1 %10, label %label1, label %label4
   
  label4:
  %11 = load i1* %e , align 1
  br i1 %11, label %label1, label %label3
   
  label3:
  %12 = load i1* %f , align 1
  br i1 %12, label %label1, label %label2
   
  label1:
  %13 = load i32* %h , align 4
  %14 = add nsw i32 %13, 1
  store i32 %14, i32* %h, align 4
  br label %label0
   
  label2:
  %15 = load i32* %h , align 4
  ret i32 %15 
}
