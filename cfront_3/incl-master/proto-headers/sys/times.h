/*ident	"@(#)cls4:incl-master/proto-headers/sys/times.h	1.1" */
#usedby bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts svr4 sgi-svr4 solaris

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
#ifndef __TIMES_H
#define __TIMES_H

#hide times
#hide utime

#expand sys/times.h

extern "C" {
	long times(struct tms *);
#os svr4 sgi-svr4 solaris
	int utime(const char *, const struct utimbuf *);
#endos
#os svr2 svr3 sgi
	int utime(const char *, struct utimbuf *);
#endos
}
#endif
