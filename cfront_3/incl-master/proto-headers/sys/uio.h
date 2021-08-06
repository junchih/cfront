/*ident	"@(#)cls4:incl-master/proto-headers/sys/uio.h	1.1" */
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
#ifndef __UIO_H
#define __UIO_H

#os svr4 sgi-svr4 solaris
#hide uiomove
#hide ureadc
#hide uwritec
#hide uiomvuio
#hide uioskip
#endos
#hide readv
#hide writev

#expand sys/uio.h

extern "C" {
	int writev(int, const struct iovec *, int);
#os svr4 sgi-svr4 solaris
	int readv(int, struct iovec *, int);
#endos
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant hpux2.0 hpux hpux8.0
	int readv(int, const struct iovec *, int);
#endos
}
#endif
