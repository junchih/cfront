/*ident	"@(#)cls4:incl-master/proto-headers/pwd.h	1.1" */
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
#ifndef __PWD_H
#define __PWD_H

#os sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts svr4 sgi-svr4 solaris
#ifndef __STDIO_H
#include <stdio.h>
#endif
#endos

#hide setpwent
#hide endpwent
#hide getpwent
#hide getpwuid
#hide getpwnam
#hide fgetpwent
#hide setpwfile
#os sgi-svr4
#hide lckpwdf
#hide ulckpwdf
#endos

#os svr4 sgi-svr4 solaris sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts
#hide putpwent
#endos

#os hpux hpux8.0
#hide getspwent
#hide getspwuid
#hide getspwaid
#hide getspwnam
#hide fgetspwent
#endos

#expand pwd.h

extern "C" {
	struct passwd *getpwent();
	struct passwd *getpwnam(const char *);
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant hpux2.0 svr2 svr3 sgi uts
	struct passwd *getpwuid(int);
#endos
#os hpux hpux8.0 svr4 sgi-svr4 solaris
	struct passwd *getpwuid(uid_t);
#endos
#os svr4 sgi-svr4 solaris
	struct passwd *fgetpwent(FILE *);
	int putpwent(const struct passwd *, FILE *);
#endos
#os sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts
	struct passwd *fgetpwent(FILE *);
	int putpwent(struct passwd *, FILE *);
#endos
	int setpwent();
	int endpwent();
#os bsd3 sunos3 sunos4 sunos4.1
	void setpwfile(const char *);
#endos
#os hpux hpux8.0
	struct s_passwd *getspwent(void);
	struct s_passwd *getspwuid(int);
	struct s_passwd *getspwaid(int);
	struct s_passwd *getspwnam(char *);
	struct s_passwd *fgetspwent(FILE *);
#endos
#os sgi-svr4
	int lckpwdf(void);
	int ulckpwdf(void);
#endos
}

#endif
