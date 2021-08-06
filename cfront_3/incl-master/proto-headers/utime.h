/*ident	"@(#)cls4:incl-master/proto-headers/utime.h	1.1" */
#usedby svr2 svr3 sgi uts sunos4.1 svr4 sgi-svr4 solaris

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
#ifndef __UTIME_H
#define __UTIME_H

#os svr4 sgi-svr4 solaris sunos4.1
#hide utime

#expand utime.h
#endos

#os svr2 svr3 sgi
struct utimbuf {
	long actime;
	long modtime;
};
#endos

extern "C" {
#os svr2 svr3 sgi uts sunos4.1
	int utime (const char*, struct utimbuf*);
#endos
#os svr4 sgi-svr4 solaris
	int utime (const char*, const struct utimbuf*);
#endos
}

#endif
