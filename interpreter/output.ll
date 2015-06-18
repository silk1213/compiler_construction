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
define i32 @main() #0 {
  %h = alloca i32, align 4
  store i32 0, i32* %h, align 4
  %a = alloca i32, align 4
  %1 = load i32* %h , align 4
  %2 = call i32 @plus(i32 %1, i32 1)
  %3 = add nsw i32 %2, 1
  %4 = load i32* %a , align 4
  store i32 %3, i32* %a, align 4
  %5 = load i32* %a , align 4
  %6 = add nsw i32 %5, 1
  store i32 %6, i32* %a, align 4
  %7 = load i32* %h , align 4
  %8 = load i32* %a , align 4
  %9 = sdiv nsw i32 %7, %8
  %c = alloca i32, align 4
  store i32 %9, i32* %c, align 4
  %10 = load i32* %h , align 4
  ret i32 %10 
}
