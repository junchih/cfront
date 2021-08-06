/*ident	"@(#)cls4:incl-master/proto-headers/mntent.h	1.1" */
#usedby sunos3 sunos4 sunos4.1 alliant hpux2.0 hpux hpux8.0

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
#ifndef __MNTENT_H
#define __MNTENT_H

#ifndef __STDIO_H
#include <stdio.h>
#endif

#hide setmntent
#hide getmntent
#hide addmntent
#hide hasmntopt
#hide endmntent

#expand mntent.h


extern "C" {
FILE *setmntent(char *, char *);
struct mntent *getmntent(FILE *);
int addmntent(FILE *, struct mntent *);
char *hasmntopt(struct mntent *, char *);
int endmntent(FILE *);
}

#endif
