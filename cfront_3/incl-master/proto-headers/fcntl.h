/*ident	"@(#)cls4:incl-master/proto-headers/fcntl.h	1.1" */
#usedby sunos3 sunos4 sunos4.1 bsd2 bsd3 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts alliant svr4 sgi-svr4 solaris

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
#ifndef __FCNTL_H
#define __FCNTL_H

#hide fcntl

#os sgi svr4 sgi-svr4 solaris sunos4.1 sunos4 hpux hpux8.0
#hide creat
#hide open
#endos

#expand fcntl.h

extern "C" {
#os sunos3 bsd2 bsd3 hpux2.0 svr2 svr3 uts alliant sunos4 sunos4.1
	int fcntl(int, int, int);
#endos
#os sgi svr4 sgi-svr4 solaris hpux hpux8.0
	int fcntl(int, int, ...);
	int open(const char*, int, ...);
	int creat(const char*, mode_t);
#endos
#os sunos4.1 sunos4 
	int creat(const char*, int);
	int open(const char*, int, ...);
#endos
}
#endif

