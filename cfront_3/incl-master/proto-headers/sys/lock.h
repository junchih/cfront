/*ident	"@(#)cls4:incl-master/proto-headers/sys/lock.h	1.1" */
#usedby hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts sunos4.1 svr4 sgi-svr4 solaris

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
#ifndef __LOCK_H
#define __LOCK_H

#hide plock
#os svr4 sgi-svr4 solaris
#hide punlock
#endos

#expand sys/lock.h

extern "C" {
	int plock(int);
#os svr4 sgi-svr4 solaris
	int punlock(void);
#endos
}

#endif
