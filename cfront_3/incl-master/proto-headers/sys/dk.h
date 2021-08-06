/*ident	"@(#)cls4:incl-master/proto-headers/sys/dk.h	1.1" */
#usedby sunos3 sunos4 sunos4.1

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
#ifndef __DK_H
#define __DK_H

#hide dkdial
#hide dkndial
#hide dkerr
#hide dkmgr
#hide dknmgr
#hide dkmgrack
#hide dkmgrnak
#hide dkminor
#hide dknamer
#hide dtnamer
#hide dxnamer
#hide dksplice
#hide dksplwait
#hide dkxenviron
#hide dkxlwrite
#hide dkxwrite
#hide dkxpwrite
#hide maphost
#hide miscfield

#expand sys/dk.h

extern "C" {
	int dkdial(const char *);
	int dkndial(const char *, int);
	char *dkerr(int);
	struct mgrmsg *dkmgr(const char *);
	struct mgrmsg *dknmgr(const char *, int);
	int dkmgrack(int);
	int dkmgrnak(int, int);
	int dkminor(int);
	char *dknamer(int);
	char *dtnamer(int);
	char *dxnamer(int);
	int dksplice(int, int);
	int dksplwait(int);
	int dkxenviron(int);
	int dkxlwrite(int, const char *, short);
	int dkxwrite(int, const char *, short);
	int dkxpwrite(int, short);
	char *maphost(const char *, char, const char *, const char *, const char *);
	char *miscfield(char, char);
};

#endif
