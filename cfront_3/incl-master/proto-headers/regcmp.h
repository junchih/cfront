/*ident	"@(#)cls4:incl-master/proto-headers/regcmp.h	1.1" */
#usedby hpux2.0 hpux hpux8.0 svr2 svr3 sgi sunos3 sunos4 sunos4.1 uts

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
#ifndef __REGCMP_H
#define __REGCMP_H

extern "C" {
	char *logname();
#os sunos3 sunos4 sunos4.1
	char *re_comp(const char *);
	int re_exec(const char *);
#endos
#os hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts
	char *regcmp(const char * ...); 
	char *regex(const char *, const char * ...);
#endos
}

#endif
