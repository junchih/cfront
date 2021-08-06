/*ident	"@(#)cls4:incl-master/proto-headers/regexpr.h	1.1" */
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
#ifndef __REGEXPR_H
#define __REGEXPR_H

#hide step
#hide advance
#hide compile

#expand regexpr.h

extern "C" {
	int step(const char *string, const char *expbuf); 
	int advance(const char *string, const char *expbuf);
	char *compile(const char *instring, char *expbuf, char *endbuf);
}

#endif

