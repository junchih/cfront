/*ident	"@(#)cls4:incl-master/proto-headers/dk.h	1.1" */
#usedby hpux2.0 hpux hpux8.0 uts

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

#hide maphost
#hide miscfield
#hide dkerr
#hide dkfcanon
#hide dkimgr
#hide dknamer
#hide dktcanon
#hide dsnamer
#hide dtnamer
#hide dkdial
#hide dkndial
#hide dkmgr
#hide dknmgr
#hide dkmgrack
#hide dkmgrnak
#hide dkminor
#hide dxnamer
#hide dksplice
#hide dksplwait
#hide dkxenviron
#hide dkxlwrite
#hide dkxwrite
#hide dkxpwrite

#expand dk.h

extern "C" {
	int dkdial(const char *);
	char *dkerr(int);
	struct mgrmsg *dkmgr(const char *);
	int dkmgrack(int);
	struct mgrmsg *dknmgr(const char *, int);
	int dkmgrnak(int, int);
	int dkminor(int);
	char *dknamer(int);
	int dksplice(int, int);
	int dksplwait(int);
	int dkxlwrite(int, const char *, short);
	int dkxpwrite(int, short);
	int dkxwrite(int, const char *, short);
	char *dtnamer(int);
	char *dxnamer(int);
#os hpux2.0 hpux hpux8.0
	int dkndial(const char *, int);
	int dkxenviron(int);
	char *maphost(const char *, char, const char *,	const char *, const char *);
	char *miscfield(char, char);
#endos
#os uts
	int dkbreak(int);
	int dkenviron(int, char);
	int dkeof(int);
	int dkerrmap(int);
	struct mgrmsg *dkimgr(int, char *);
	int dkmgrnack(int, int);
	int dkxstdio(int);
	int isdkeof(int);
	int ppremote(int, char *, int);
	int push(int, char **, char *, int (*)(), char *);
	int pull(int, char **, char *, int (*)(), char *);
#endos
};

#endif
