/*ident	"@(#)cls4:incl-master/proto-headers/ustat.h	1.1" */
#usedby hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts svr4 sgi-svr4 solaris

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
#ifndef __USTAT_H
#define __USTAT_H

#expand ustat.h

extern "C" {
#os hpux2.0 hpux hpux8.0 svr3 sgi svr4 sgi-svr4 solaris
	int ustat(dev_t, struct ustat *);
#endos
#os svr2 uts
	int ustat(int, struct ustat *);
#endos
}

#endif
