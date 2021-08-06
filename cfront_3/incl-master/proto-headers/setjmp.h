/*ident	"@(#)cls4:incl-master/proto-headers/setjmp.h	1.1" */
#usedby bsd2 bsd3 sunos3 alliant hpux hpux8.0 svr2 svr3 sgi uts svr4 sgi-svr4 

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
#ifndef __SETJMP_H
#define __SETJMP_H

#os bsd2 bsd3 sunos3 alliant hpux hpux8.0 svr2 svr3 sgi uts svr4
#hide sigsetjmp
#endos
#hide setjmp
#hide _setjmp
#hide siglongjmp
#hide longjmp
#hide _longjmp

#expand setjmp.h

#os sgi-svr4 
#ifdef sigsetjmp
#undef sigsetjmp
#else
#hide sigsetjmp
#endif
#endos

extern "C" {
	int setjmp(jmp_buf);
	void longjmp(jmp_buf, int);
#os bsd2 bsd3 sunos3 hpux hpux8.0 alliant
	int _setjmp(jmp_buf);
	void _longjmp(jmp_buf, int);
#endos
#os svr4 sgi-svr4 
	int sigsetjmp(sigjmp_buf, int);
	void siglongjmp(sigjmp_buf, int);
#endos
}

#endif
