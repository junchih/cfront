/*ident	"@(#)cls4:incl-master/proto-headers/grp.h	1.1" */
#usedby bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts svr4 sgi-svr4 solaris

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
#ifndef __GRP_H
#define __GRP_H

#os sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts
#ifndef __STDIO_H
#include <stdio.h>
#endif
#endos

#hide endgrent
#hide setgrent
#hide fgetgrent
#hide getgrent
#hide getgrgid
#hide getgrnam
#hide initgroups

#expand grp.h

extern "C" {
#os svr4 sgi-svr4 solaris
	void endgrent(void);
	struct group *fgetgrent(FILE *);
	struct group *getgrent(void);
	void setgrent(void);
	int initgroups(const char *, gid_t);
	struct group *getgrgid(gid_t);
	struct group *getgrnam(const char *);
#endos
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts
	void endgrent();
	void setgrent();
	struct group *getgrent();
	struct group *getgrgid(int);
	struct group *getgrnam(const char *);
#endos
#os sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts
	struct group *fgetgrent(FILE *);
#endos
}

#endif
