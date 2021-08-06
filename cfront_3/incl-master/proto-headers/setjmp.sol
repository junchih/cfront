/*******************************************************************************
 
C++ source for the C++ Language System, Release 3.0.  This product
is a new release of the original cfront developed in the computer
science research center of AT&T Bell Laboratories.

Copyright (c) 1991 AT&T and UNIX System Laboratories, Inc.
Copyright (c) 1984, 1989, 1990 AT&T.  All Rights Reserved.

THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE of AT&T and UNIX System
Laboratories, Inc.  The copyright notice above does not evidence
any actual or intended publication of such source code.

*******************************************************************************/
/*
 *	This is a handmade version of setjmp.h
 *	for SunOS 5.x (Solaris 2.x).
 */

/*	Copyright (c) 1988 AT&T	*/
/*	  All Rights Reserved  	*/

/*	THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T	*/
/*	The copyright notice above does not evidence any   	*/
/*	actual or intended publication of such source code.	*/

#ifndef _SETJMP_H
#define	_SETJMP_H

#define sigsetjmp ______sigsetjmp
#define setjmp ______setjmp
#define _setjmp _______setjmp
#define siglongjmp ______siglongjmp
#define longjmp ______longjmp
#define _longjmp _______longjmp

#ifndef _JBLEN

#pragma ident	"@(#)setjmp.h	1.2	90/04/29 SMI"	/* SVr4.0 1.9.2.9 */

#if defined(__STDC__)

#if #machine(i386)
#define	_SIGJBLEN 128	/* (sizeof(ucontext_t) / sizeof (int)) */
#elif #machine(sparc)
#define	_SIGJBLEN 19	/* ABI value */
#else
#define	_SIGJBLEN 64	/* (sizeof(ucontext_t) / sizeof (int)) */
#endif

#if #machine(pdp11)
#define	_JBLEN  3
#elif #machine(sparc)
#define	_JBLEN  12	/* ABI value */
#elif #machine(u370)
#define	_JBLEN  4
#elif #machine(u3b)
#define	_JBLEN  11
#else
#define	_JBLEN  10
#endif	/* #machine */

#else

#if i386
#define	_SIGJBLEN 128	/* (sizeof(ucontext_t) / sizeof (int)) */
#elif sparc
#define	_SIGJBLEN 19	/* ABI value */
#else
#define	_SIGJBLEN 64	/* (sizeof(ucontext_t) / sizeof (int)) */
#endif

#if pdp11
#define	_JBLEN  3
#elif sparc
#define	_JBLEN  12	/* ABI value */
#elif u370
#define	_JBLEN  4
#elif u3b
#define	_JBLEN  11
#else
#define	_JBLEN  10
#endif

#endif	/* __STDC__ */

typedef int jmp_buf[_JBLEN];

#if defined(__STDC__)
extern int setjmp(jmp_buf);
extern void longjmp(jmp_buf, int);

#if __STDC__ == 0 || defined(_POSIX_SOURCE) || defined(_XOPEN_SOURCE)
/* non-ANSI standard compilation */

typedef int sigjmp_buf[_SIGJBLEN];

extern int sigsetjmp(sigjmp_buf, int);
extern void siglongjmp(sigjmp_buf, int);
#endif

#if __STDC__ != 0
#define	setjmp(env)	setjmp(env)
#endif

#else
typedef int sigjmp_buf[_SIGJBLEN];

extern int setjmp();
extern void longjmp();
extern int sigsetjmp();
extern void siglongjmp();

#endif  /* __STDC__ */

#undef _longjmp
#undef _setjmp
#undef longjmp
#undef setjmp
#undef siglongjmp
#undef sigsetjmp

extern "C" {
	int setjmp(jmp_buf);
	void longjmp(jmp_buf, int);
	int sigsetjmp(sigjmp_buf, int);
	void siglongjmp(sigjmp_buf, int);
}

static void setjmp_dummy() {
	sigjmp_buf sbuf;
	jmp_buf jbuf;

	/*
	 * The following functions are called in order to
	 * keep cfront from deleting the definitions of these
	 * functions.  This keeps the C compiler happy about
	 * the following #pragma.
	 */
	sigsetjmp(sbuf, 0);
	setjmp(jbuf);
	setjmp_dummy();
}

#pragma unknown_control_flow(setjmp)
#pragma unknown_control_flow(sigsetjmp)

#endif  /* _JBLEN */

#endif  /* _SETJMP_H */
