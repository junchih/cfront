| ident	"@(#)cfront:lib/task/sun_swap.s	1.1"

| TFRAME is the displacement of t_frame in the task class.
TFRAME = 20

| TH is the displacement of th in the task class.
TH = 24

	.data
	.comm	_rr4,4
	.comm	_rr3,4
	.comm	_rr2,4

	.text
	.globl	_swap
_swap:
	movl	sp@(4),a0		| a0 = this
	movl	a0@(TFRAME),a6		| a6 (fp) = this -> t_framep
	movl	a0@(TH),d0		| return this -> th
	rts

	.globl	_sswap
_sswap:
	link	a6,#0
	movl	_rr4,a0			| a0 = t_savearea
	movl	_rr2,a1			| a1 = t_basep
	movl	_rr3,d0			| d0 = sz, test if zero
	beqs	L2

	subql	#1,d0			| for dbra
L1:
	movl	a0@+,a1@+
	dbra	d0,L1

L2:
	movl	a6@(8),a0		| a0 = this
	movl	a0@(TFRAME),a6@		| a6 (fp) AFTER unlk = this -> t_framep
	movl	a0@(TH),d0		| return this -> th
	unlk	a6
	rts



