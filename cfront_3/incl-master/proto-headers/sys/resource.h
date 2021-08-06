/*ident	"@(#)cls4:incl-master/proto-headers/sys/resource.h	1.1" */
#usedby bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant svr4 sgi-svr4 solaris

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
#ifndef __RESOURCE_H
#define __RESOURCE_H

#os bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant
#ifndef __SYS_TIME_H
#include <sys/time.h>
#endif

#hide getpriority
#hide setpriority
#hide getrlimit
#hide setrlimit
#hide getrusage
#endos

#os svr4 sgi-svr4 solaris
#hide getrlimit
#hide setrlimit
#endos

#expand sys/resource.h

extern "C" {
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant
	int getpriority(int which, int who);
	int setpriority(int which, int who, int prio);
	int getrlimit(int resource, rlimit* rlp);
	int setrlimit(int resource, const rlimit* rlp);
	int getrusage(int, rusage*);
#endos
#os svr4 solaris
	int rlimit(int, rlim_t, rlim_t);
#endos
#os svr4 sgi-svr4 solaris
	int getrlimit(int, struct rlimit*);
	int setrlimit(int, const struct rlimit*);
#endos
}

#endif
