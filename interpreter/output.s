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
	pushq	%rax
.Ltmp3:
	.cfi_def_cfa_offset 16
	movl	$2, 4(%rsp)
	movl	$2, %edi
	callq	test
	movl	%eax, (%rsp)
	movl	4(%rsp), %edi
	callq	test2
	movl	(%rsp), %eax
	popq	%rdx
	ret
.Ltmp4:
	.size	main, .Ltmp4-main
	.cfi_endproc


	.section	".note.GNU-stack","",@progbits
