/*ident	"@(#)cls4:incl-master/proto-headers/locale.h	1.1" */
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

#ifndef __LOCALE_H
#define __LOCALE_H

#hide setlocale
#hide localeconv

#expand locale.h

extern "C" {
	char *setlocale(int, const char *);
	struct lconv *localeconv(void);
}

#endif
