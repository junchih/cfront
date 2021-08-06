/*ident	"@(#)cls4:incl-master/proto-headers/sys/user.h	1.1" */
#usedby sunos3 sunos4 sunos4.1 alliant svr4 sgi-svr4 solaris

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
#ifndef __USER_H
#define __USER_H

#os svr4 sgi-svr4 solaris
#hide addupc
#endos

#expand sys/user.h

#os svr4 sgi-svr4 solaris
extern "C" {
	void addupc(void(*)(), struct prof *, int);
}
#endos

#endif
