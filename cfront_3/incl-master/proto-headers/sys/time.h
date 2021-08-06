/*ident	"@(#)cls4:incl-master/proto-headers/sys/time.h	1.1" */
#usedby bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant hpux2.0 hpux hpux8.0 svr4 sgi-svr4 solaris

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
#ifndef __SYS_TIME_H
#define __SYS_TIME_H

#ifndef __TYPES_H
#include <sys/types.h>
#endif

#hide adjtime
#hide getitimer
#hide setitimer
#hide gettimeofday
#hide settimeofday
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant hpux2.0 hpux hpux8.0
#hide select
#endos
#hide utimes

#expand sys/time.h

extern "C" {
#os svr4 sgi-svr4 solaris
	int adjtime(struct timeval *, struct timeval *);
	int getitimer(int, struct itimerval *);
	int setitimer(int, struct itimerval *, struct itimerval *);
#endos
#os svr4 solaris
	int gettimeofday(struct timeval*);
	int settimeofday(struct timeval*);
#endos
#os sgi-svr4
	int gettimeofday(timeval*, struct timezone*);
	int settimeofday(const timeval*, const struct timezone*);
#endos
#os bsd3 sunos3 sunos4 sunos4.1
	int adjtime(const timeval*, timeval*);
#endos
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant hpux2.0 hpux hpux8.0
	int getitimer(int, itimerval*);
	int setitimer(int, const itimerval*, itimerval*);
	int gettimeofday(timeval*, struct timezone*);
	int settimeofday(const timeval*, const struct timezone*);
#endos
	int utimes(const char*, timeval tvp[2]);
#os hpux2.0 hpux hpux8.0
	int select(int, int*, int*, int*, const struct timeval*);
	int selectitimer(int, struct itimerval *, struct itimerval *);
#endos
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant
	int select(int, fd_set*, fd_set*, fd_set*, const timeval*);
#endos
}

#endif
