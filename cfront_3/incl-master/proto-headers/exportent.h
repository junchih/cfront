/*ident "@(#)cls4:incl-master/proto-headers/exportent.h 1.1" */
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

*******************************************************************************/#ifndef __EXPORTENT_H
#define __EXPORTENT_H

#ifndef __STDIO_H
#include <stdio.h>
#endif

#hide setexportent
#hide getexportent
#hide endexportent
#hide addexportent
#hide remexportent
#hide getexportopt

#expand exportent.h

extern "C" {
	FILE *setexportent();
	struct exportent *getexportent(FILE*);
	extern void endexportent();
	int addexportent(FILE*, char*, char*);
	int remexportent(FILE*, char*);
	char *getexportopt(FILE*);
	}
#endif
