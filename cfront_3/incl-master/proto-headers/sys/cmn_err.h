/*ident	"@(#)cls4:incl-master/proto-headers/sys/cmn_err.h	1.1" */
#usedby svr4 sgi-svr4 solaris

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
#ifndef __SYS_CMNERR_H
#define __SYS_CMNERR_H

#hide cmn_err
#hide printf
#hide panic
#hide nomemmsg

#expand sys/cmn_err.h

extern "C" {
	void cmn_err(int, char *, ...);
	void printf(char *, ...);
	void panic(char *, ...);
	void nomemmsg(char *, int, int, int);
}

#endif
