	.file	"Sales_item\345\257\271\350\261\241\347\232\204\345\212\240\346\263\225.cpp"
	.text
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.section	.text._ZNK10Sales_item4isbnB5cxx11Ev,"axG",@progbits,_ZNK10Sales_item4isbnB5cxx11Ev,comdat
	.align 2
	.weak	_ZNK10Sales_item4isbnB5cxx11Ev
	.type	_ZNK10Sales_item4isbnB5cxx11Ev, @function
_ZNK10Sales_item4isbnB5cxx11Ev:
.LFB1738:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_@PLT
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1738:
	.size	_ZNK10Sales_item4isbnB5cxx11Ev, .-_ZNK10Sales_item4isbnB5cxx11Ev
	.text
	.align 2
	.globl	_ZN10Sales_itempLERKS_
	.type	_ZN10Sales_itempLERKS_, @function
_ZN10Sales_itempLERKS_:
.LFB1742:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movl	32(%rax), %edx
	movq	-16(%rbp), %rax
	movl	32(%rax), %eax
	addl	%eax, %edx
	movq	-8(%rbp), %rax
	movl	%edx, 32(%rax)
	movq	-8(%rbp), %rax
	movsd	40(%rax), %xmm1
	movq	-16(%rbp), %rax
	movsd	40(%rax), %xmm0
	addsd	%xmm1, %xmm0
	movq	-8(%rbp), %rax
	movsd	%xmm0, 40(%rax)
	movq	-8(%rbp), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1742:
	.size	_ZN10Sales_itempLERKS_, .-_ZN10Sales_itempLERKS_
	.section	.text._ZN10Sales_itemC2ERKS_,"axG",@progbits,_ZN10Sales_itemC5ERKS_,comdat
	.align 2
	.weak	_ZN10Sales_itemC2ERKS_
	.type	_ZN10Sales_itemC2ERKS_, @function
_ZN10Sales_itemC2ERKS_:
.LFB1745:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	-16(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1ERKS4_@PLT
	movq	-16(%rbp), %rax
	movl	32(%rax), %edx
	movq	-8(%rbp), %rax
	movl	%edx, 32(%rax)
	movq	-16(%rbp), %rax
	movsd	40(%rax), %xmm0
	movq	-8(%rbp), %rax
	movsd	%xmm0, 40(%rax)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1745:
	.size	_ZN10Sales_itemC2ERKS_, .-_ZN10Sales_itemC2ERKS_
	.weak	_ZN10Sales_itemC1ERKS_
	.set	_ZN10Sales_itemC1ERKS_,_ZN10Sales_itemC2ERKS_
	.section	.text._ZN10Sales_itemD2Ev,"axG",@progbits,_ZN10Sales_itemD5Ev,comdat
	.align 2
	.weak	_ZN10Sales_itemD2Ev
	.type	_ZN10Sales_itemD2Ev, @function
_ZN10Sales_itemD2Ev:
.LFB1748:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1748:
	.size	_ZN10Sales_itemD2Ev, .-_ZN10Sales_itemD2Ev
	.weak	_ZN10Sales_itemD1Ev
	.set	_ZN10Sales_itemD1Ev,_ZN10Sales_itemD2Ev
	.text
	.globl	_ZplRK10Sales_itemS1_
	.type	_ZplRK10Sales_itemS1_, @function
_ZplRK10Sales_itemS1_:
.LFB1743:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	%rdx, -24(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN10Sales_itemC1ERKS_
	movq	-24(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN10Sales_itempLERKS_
	nop
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1743:
	.size	_ZplRK10Sales_itemS1_, .-_ZplRK10Sales_itemS1_
	.section	.text._ZN10Sales_itemC2Ev,"axG",@progbits,_ZN10Sales_itemC5Ev,comdat
	.align 2
	.weak	_ZN10Sales_itemC2Ev
	.type	_ZN10Sales_itemC2Ev, @function
_ZN10Sales_itemC2Ev:
.LFB1755:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev@PLT
	movq	-8(%rbp), %rax
	movl	$0, 32(%rax)
	movq	-8(%rbp), %rax
	pxor	%xmm0, %xmm0
	movsd	%xmm0, 40(%rax)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1755:
	.size	_ZN10Sales_itemC2Ev, .-_ZN10Sales_itemC2Ev
	.weak	_ZN10Sales_itemC1Ev
	.set	_ZN10Sales_itemC1Ev,_ZN10Sales_itemC2Ev
	.section	.text._ZN10Sales_itemaSEOS_,"axG",@progbits,_ZN10Sales_itemaSEOS_,comdat
	.align 2
	.weak	_ZN10Sales_itemaSEOS_
	.type	_ZN10Sales_itemaSEOS_, @function
_ZN10Sales_itemaSEOS_:
.LFB1760:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEaSEOS4_@PLT
	movq	-16(%rbp), %rax
	movl	32(%rax), %edx
	movq	-8(%rbp), %rax
	movl	%edx, 32(%rax)
	movq	-16(%rbp), %rax
	movsd	40(%rax), %xmm0
	movq	-8(%rbp), %rax
	movsd	%xmm0, 40(%rax)
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1760:
	.size	_ZN10Sales_itemaSEOS_, .-_ZN10Sales_itemaSEOS_
	.text
	.globl	_ZrsRSiR10Sales_item
	.type	_ZrsRSiR10Sales_item, @function
_ZrsRSiR10Sales_item:
.LFB1753:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$96, %rsp
	movq	%rdi, -88(%rbp)
	movq	%rsi, -96(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movq	-96(%rbp), %rdx
	movq	-88(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZStrsIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE@PLT
	movq	%rax, %rdx
	movq	-96(%rbp), %rax
	addq	$32, %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSirsERj@PLT
	movq	%rax, %rdx
	leaq	-72(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZNSirsERd@PLT
	movq	-88(%rbp), %rax
	movq	(%rax), %rax
	subq	$24, %rax
	movq	(%rax), %rax
	movq	%rax, %rdx
	movq	-88(%rbp), %rax
	addq	%rdx, %rax
	movq	%rax, %rdi
	call	_ZNKSt9basic_iosIcSt11char_traitsIcEEcvbEv@PLT
	testb	%al, %al
	je	.L13
	movq	-96(%rbp), %rax
	movl	32(%rax), %eax
	movl	%eax, %eax
	testq	%rax, %rax
	js	.L14
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rax, %xmm0
	jmp	.L15
.L14:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
.L15:
	movsd	-72(%rbp), %xmm1
	mulsd	%xmm1, %xmm0
	movq	-96(%rbp), %rax
	movsd	%xmm0, 40(%rax)
	jmp	.L16
.L13:
	movq	$0, -64(%rbp)
	movq	$0, -56(%rbp)
	movq	$0, -48(%rbp)
	movq	$0, -40(%rbp)
	movq	$0, -32(%rbp)
	movq	$0, -24(%rbp)
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN10Sales_itemC1Ev
	leaq	-64(%rbp), %rdx
	movq	-96(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZN10Sales_itemaSEOS_
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN10Sales_itemD1Ev
.L16:
	movq	-88(%rbp), %rax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L18
	call	__stack_chk_fail@PLT
.L18:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1753:
	.size	_ZrsRSiR10Sales_item, .-_ZrsRSiR10Sales_item
	.section	.rodata
.LC1:
	.string	" "
	.text
	.globl	_ZlsRSoRK10Sales_item
	.type	_ZlsRSoRK10Sales_item, @function
_ZlsRSoRK10Sales_item:
.LFB1761:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1761
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$72, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -72(%rbp)
	movq	%rsi, -80(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	leaq	-64(%rbp), %rax
	movq	-80(%rbp), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB0:
	call	_ZNK10Sales_item4isbnB5cxx11Ev
.LEHE0:
	leaq	-64(%rbp), %rdx
	movq	-72(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB1:
	call	_ZStlsIcSt11char_traitsIcESaIcEERSt13basic_ostreamIT_T0_ES7_RKNSt7__cxx1112basic_stringIS4_S5_T1_EE@PLT
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-80(%rbp), %rax
	movl	32(%rax), %eax
	movl	%eax, %esi
	movq	%rdx, %rdi
	call	_ZNSolsEj@PLT
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rdx
	movq	-80(%rbp), %rax
	movq	40(%rax), %rax
	movq	%rax, %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEd@PLT
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@PLT
	movq	%rax, %rbx
	movq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNK10Sales_item9avg_priceEv
	movq	%xmm0, %rax
	movq	%rax, %xmm0
	movq	%rbx, %rdi
	call	_ZNSolsEd@PLT
.LEHE1:
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	movq	-72(%rbp), %rax
	movq	-24(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L22
	jmp	.L24
.L23:
	endbr64
	movq	%rax, %rbx
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev@PLT
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB2:
	call	_Unwind_Resume@PLT
.LEHE2:
.L24:
	call	__stack_chk_fail@PLT
.L22:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1761:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA1761:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1761-.LLSDACSB1761
.LLSDACSB1761:
	.uleb128 .LEHB0-.LFB1761
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB1761
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L23-.LFB1761
	.uleb128 0
	.uleb128 .LEHB2-.LFB1761
	.uleb128 .LEHE2-.LEHB2
	.uleb128 0
	.uleb128 0
.LLSDACSE1761:
	.text
	.size	_ZlsRSoRK10Sales_item, .-_ZlsRSoRK10Sales_item
	.align 2
	.globl	_ZNK10Sales_item9avg_priceEv
	.type	_ZNK10Sales_item9avg_priceEv, @function
_ZNK10Sales_item9avg_priceEv:
.LFB1762:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	32(%rax), %eax
	testl	%eax, %eax
	je	.L26
	movq	-8(%rbp), %rax
	movsd	40(%rax), %xmm1
	movq	-8(%rbp), %rax
	movl	32(%rax), %eax
	movl	%eax, %eax
	testq	%rax, %rax
	js	.L27
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rax, %xmm0
	jmp	.L28
.L27:
	movq	%rax, %rdx
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	pxor	%xmm0, %xmm0
	cvtsi2sdq	%rdx, %xmm0
	addsd	%xmm0, %xmm0
.L28:
	divsd	%xmm0, %xmm1
	jmp	.L29
.L26:
	pxor	%xmm1, %xmm1
.L29:
	movq	%xmm1, %rax
	movq	%rax, %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1762:
	.size	_ZNK10Sales_item9avg_priceEv, .-_ZNK10Sales_item9avg_priceEv
	.globl	main
	.type	main, @function
main:
.LFB1763:
	.cfi_startproc
	.cfi_personality 0x9b,DW.ref.__gxx_personality_v0
	.cfi_lsda 0x1b,.LLSDA1763
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$168, %rsp
	.cfi_offset 3, -24
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	leaq	-176(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN10Sales_itemC1Ev
	leaq	-128(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN10Sales_itemC1Ev
	leaq	-176(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt3cin(%rip), %rax
	movq	%rax, %rdi
.LEHB3:
	call	_ZrsRSiR10Sales_item
	movq	%rax, %rdx
	leaq	-128(%rbp), %rax
	movq	%rax, %rsi
	movq	%rdx, %rdi
	call	_ZrsRSiR10Sales_item
	leaq	-80(%rbp), %rax
	leaq	-128(%rbp), %rdx
	leaq	-176(%rbp), %rcx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZplRK10Sales_itemS1_
.LEHE3:
	leaq	-80(%rbp), %rax
	movq	%rax, %rsi
	leaq	_ZSt4cout(%rip), %rax
	movq	%rax, %rdi
.LEHB4:
	call	_ZlsRSoRK10Sales_item
	movq	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_@GOTPCREL(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E@PLT
.LEHE4:
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN10Sales_itemD1Ev
	movl	$0, %ebx
	leaq	-128(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN10Sales_itemD1Ev
	leaq	-176(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN10Sales_itemD1Ev
	movl	%ebx, %eax
	movq	-24(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L34
	jmp	.L37
.L36:
	endbr64
	movq	%rax, %rbx
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN10Sales_itemD1Ev
	jmp	.L33
.L35:
	endbr64
	movq	%rax, %rbx
.L33:
	leaq	-128(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN10Sales_itemD1Ev
	leaq	-176(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN10Sales_itemD1Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB5:
	call	_Unwind_Resume@PLT
.LEHE5:
.L37:
	call	__stack_chk_fail@PLT
.L34:
	movq	-8(%rbp), %rbx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1763:
	.section	.gcc_except_table
.LLSDA1763:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1763-.LLSDACSB1763
.LLSDACSB1763:
	.uleb128 .LEHB3-.LFB1763
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L35-.LFB1763
	.uleb128 0
	.uleb128 .LEHB4-.LFB1763
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L36-.LFB1763
	.uleb128 0
	.uleb128 .LEHB5-.LFB1763
	.uleb128 .LEHE5-.LEHB5
	.uleb128 0
	.uleb128 0
.LLSDACSE1763:
	.text
	.size	main, .-main
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB2288:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L40
	cmpl	$65535, -8(%rbp)
	jne	.L40
	leaq	_ZStL8__ioinit(%rip), %rax
	movq	%rax, %rdi
	call	_ZNSt8ios_base4InitC1Ev@PLT
	leaq	__dso_handle(%rip), %rax
	movq	%rax, %rdx
	leaq	_ZStL8__ioinit(%rip), %rax
	movq	%rax, %rsi
	movq	_ZNSt8ios_base4InitD1Ev@GOTPCREL(%rip), %rax
	movq	%rax, %rdi
	call	__cxa_atexit@PLT
.L40:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2288:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I__ZN10Sales_itempLERKS_, @function
_GLOBAL__sub_I__ZN10Sales_itempLERKS_:
.LFB2289:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2289:
	.size	_GLOBAL__sub_I__ZN10Sales_itempLERKS_, .-_GLOBAL__sub_I__ZN10Sales_itempLERKS_
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__ZN10Sales_itempLERKS_
	.hidden	DW.ref.__gxx_personality_v0
	.weak	DW.ref.__gxx_personality_v0
	.section	.data.rel.local.DW.ref.__gxx_personality_v0,"awG",@progbits,DW.ref.__gxx_personality_v0,comdat
	.align 8
	.type	DW.ref.__gxx_personality_v0, @object
	.size	DW.ref.__gxx_personality_v0, 8
DW.ref.__gxx_personality_v0:
	.quad	__gxx_personality_v0
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
