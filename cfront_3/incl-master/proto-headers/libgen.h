/*ident	"@(#)cls4:incl-master/proto-headers/libgen.h	1.1" */
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

#ifndef __LIBGEN_H
#define __LIBGEN_H

#include <sys/types.h>
#include <stdio.h>

#ifndef __TIME_H
#include	<time.h>
#endif

extern "C" {
	char * basename(char *);
	char * bgets(char *, size_t, FILE *, char *);
	size_t bufsplit(char *, size_t, char **);
	char * copylist(const char *, off_t *);
	char * dirname(char *);
	int eaccess(const char *, int);
	int gmatch(const char *, const char *);
	int isencrypt(const char *, size_t);
	int mkdirp(const char *, mode_t);
	int p2open(const char *, FILE *[2]);
	int p2close(FILE *[2]);
	char * pathfind(const char *, const char *, const char *);
	char * regcmp(const char *, ...);
	char * regex(const char *, const char *, ...);
	int rmdirp(char *, char *);
	char * strcadd(char *, const char *);
	char * strccpy(char *, const char *);
	char * streadd(char *, const char *, const char *);
	char * strecpy(char *, const char *, const char *);
	int strfind(const char *, const char *);
	char * strrspn(const char *, const char *);
	char * strtrns(const char *, const char *, const char *, char *);
}

#endif
