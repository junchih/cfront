/*ident	"@(#)cls4:incl-master/proto-headers/ucontext.h	1.1" */
#usedby svr4 solaris

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
#ifndef __UCONTEXT_H
#define __UCONTEXT_H

#hide getcontext
#hide setcontext
#hide swapcontext
#hide makecontext

#expand ucontext.h

extern "C" {
	int getcontext(ucontext_t *);
	int setcontext(ucontext_t *);
	int swapcontext(ucontext_t *, ucontext_t *);
	void makecontext(ucontext_t *, void(*)(), int, ...);
}

#endif
