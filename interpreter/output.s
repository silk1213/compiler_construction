	.file	"output.ll"
	.text
	.globl	test
	.align	16, 0x90
	.type	test,@function
test:                                   # @test
	.cfi_startproc
# BB#0:
	movl	%edi, -4(%rsp)
	imull	%edi, %edi
	movl	%edi, -8(%rsp)
	movl	%edi, %eax
	ret
.Ltmp0:
	.size	test, .Ltmp0-test
	.cfi_endproc

	.globl	test2
	.align	16, 0x90
	.type	test2,@function
test2:                                  # @test2
	.cfi_startproc
# BB#0:
	movl	%edi, -4(%rsp)
	ret
.Ltmp1:
	.size	test2, .Ltmp1-test2
	.cfi_endproc

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	pushq	%rbp
.Ltmp4:
	.cfi_def_cfa_offset 16
.Ltmp5:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
.Ltmp6:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$2, -4(%rbp)
	movl	$2, %edi
	callq	test
	movl	%eax, -8(%rbp)
	movl	-4(%rbp), %edi
	callq	test2
	movq	$0, -16(%rbp)
	movq	$0, -16(%rbp)
	cvtsi2sdl	-4(%rbp), %xmm0
	xorps	%xmm1, %xmm1
	addsd	%xmm0, %xmm1
	movsd	%xmm1, -24(%rbp)
	movb	$1, -25(%rbp)
	jmp	.LBB2_1
	.align	16, 0x90
.LBB2_2:                                # %label1
                                        #   in Loop: Header=BB2_1 Depth=1
	movl	-4(%rbp), %edi
	callq	test
	movl	-4(%rbp), %eax
	decl	%eax
	movl	%eax, -4(%rbp)
	movq	%rsp, %rcx
	leaq	-16(%rcx), %rdx
	movq	%rdx, %rsp
	movl	%eax, -16(%rcx)
	movl	%eax, -16(%rcx)
.LBB2_1:                                # %label0
                                        # =>This Inner Loop Header: Depth=1
	cmpl	$0, -4(%rbp)
	jg	.LBB2_2
	.align	16, 0x90
.LBB2_3:                                # %label3
                                        # =>This Inner Loop Header: Depth=1
	movb	-25(%rbp), %al
	testb	%al, %al
	jne	.LBB2_3
# BB#4:                                 # %label5
	movl	-8(%rbp), %eax
	movq	%rbp, %rsp
	popq	%rbp
	ret
.Ltmp7:
	.size	main, .Ltmp7-main
	.cfi_endproc


	.section	".note.GNU-stack","",@progbits
