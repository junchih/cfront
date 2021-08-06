/*ident	"@(#)cls4:incl-master/proto-headers/libw.h	1.1" */
#usedby svr4 solaris

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

#ifndef __LIBW_H
#define __LIBW_H

#hide getwidth
#hide mbftowc
#hide scrwidth
#hide wisprint

#expand libw.h

extern "C" {
	void getwidth(eucwidth_t *);
	int mbftowc(char *, wchar_t *, int (*)(), int *);
	int scrwidth(wchar_t);
	int wisprint(wchar_t);
}

#endif /* __LIBW_H */
