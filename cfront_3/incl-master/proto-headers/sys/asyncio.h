/*ident	"@(#)cls4:incl-master/proto-headers/sys/asyncio.h	1.1" */
#usedby svr4

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
#ifndef __SYS_ASYNCIO_H
#define __SYS_ASYNCIO_H

#hide __aread
#hide __awrite
#hide __asyncio
#hide __acancel

#expand sys/asyncio.h

extern "C" {
	int __aread(const int, const int, char *, const uint, ecb_t *);
	int __awrite(const int, const int, char *, const uint, ecb_t *);
	int __asyncio(const int, aioop_t *, const int);
	int __acancel(const int, const long *const, const int);
}

#endif
