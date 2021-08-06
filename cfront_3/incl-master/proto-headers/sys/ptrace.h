/*ident	"@(#)cls4:incl-master/proto-headers/sys/ptrace.h	1.1" */
#usedby bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant

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
#ifndef __PTRACE_H
#define __PTRACE_H

#hide ptrace

#expand sys/ptrace.h

extern "C" {
#os bsd2 bsd3 alliant
	int ptrace(int, int, int*, int);
#endos
#os sunos3 sunos4 sunos4.1
	int ptrace(enum ptracereq, int, char*, int, char *addr=0);
#endos
}

#endif
