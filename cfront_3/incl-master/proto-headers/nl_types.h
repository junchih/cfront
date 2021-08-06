/*ident	"@(#)cls4:incl-master/proto-headers/nl_types.h	1.1" */
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

#ifndef __NL_TYPES_H
#define __NL_TYPES_H

#hide catclose
#hide catgets
#hide catopen
#hide gettxt

#expand nl_types.h

extern "C" {
	int catclose(nl_catd);
	char *catgets(nl_catd, int, int, char *);
	nl_catd catopen(const char *, int);
	char *gettxt(const char *, const char *);
}

#endif /* __NL_TYPES_H */
