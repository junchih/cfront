/*ident	"@(#)cls4:incl-master/proto-headers/grpadj.h	1.1" */
#usedby sunos4 sunos4.1

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
#ifndef __GRPADJ_H
#define __GRPADJ_H

#ifndef __STDIO_H
#include <stdio.h>
#endif

#hide getgraent
#hide getgragid
#hide getgranam

#expand grpadj.h


extern "C" {
	struct group_adjunct 	*getgraent(), 
				*getgragid(int), 
				*getgranam(char*),
				*fgetgraent(FILE*);
	void setgraent(), endgraent();
}

#endif
