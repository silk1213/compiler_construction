	.file	"output.ll"
	.text
	.globl	plus
	.align	16, 0x90
	.type	plus,@function
plus:                                   # @plus
	.cfi_startproc
# BB#0:
	movl	%edi, -4(%rsp)
	movl	%esi, -8(%rsp)
	addl	-4(%rsp), %esi
	movl	%esi, %eax
	ret
.Ltmp0:
	.size	plus, .Ltmp0-plus
	.cfi_endproc

	.section	.rodata.cst8,"aM",@progbits,8
	.align	8
.LCPI1_0:
	.quad	4607182418800017408     # double 1
	.text
	.globl	asd
	.align	16, 0x90
	.type	asd,@function
asd:                                    # @asd
	.cfi_startproc
# BB#0:
	movsd	.LCPI1_0(%rip), %xmm0
	ret
.Ltmp1:
	.size	asd, .Ltmp1-asd
	.cfi_endproc

	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:                                 # %label55
	movb	$1, -26(%rsp)
	movb	$1, -25(%rsp)
	movl	$1, -8(%rsp)
	movl	$1, -4(%rsp)
	movabsq	$4607182418800017408, %rax # imm = 0x3FF0000000000000
	movq	%rax, -24(%rsp)
	movq	%rax, -16(%rsp)
	movl	$1, %eax
	ret
.Ltmp2:
	.size	main, .Ltmp2-main
	.cfi_endproc


	.section	".note.GNU-stack","",@progbits
