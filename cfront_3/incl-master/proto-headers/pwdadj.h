/*ident	"@(#)cls4:incl-master/proto-headers/pwdadj.h	1.1" */
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
#ifndef __PWDADJ_H
#define __PWDADJ_H

#ifndef __STDIO_H
#include <stdio.h>
#endif

#hide getpwaent
#hide getpwanam
#hide getpwauid
#hide fgetpwaent
#hide setpwaent
#hide endpwaent

#expand pwdadj.h

extern "C" {
	struct passwd_adjunct *getpwaent();
	struct passwd_adjunct *getpwanam(char *);
	struct passwd_adjunct *fgetpwaent(FILE *);
	struct passwd_adjunct *getpwauid(int);
	void setpwaent();
	void endpwaent();

#os
	struct passwd *getpwent();
	struct passwd *fgetpwent();
	struct passwd *getpwuid(int);
	struct passwd *getpwnam(char *);
	void setpwfile(char *);
	int setpwent();
	int endpwent();
#endos

}

#endif



