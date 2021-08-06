/*ident	"@(#)cls4:incl-master/proto-headers/utmpx.h	1.1" */
#usedby svr4 solaris

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
#ifndef __UTMPX_H
#define __UTMPX_H

#hide endutxent
#hide getutxent
#hide getutxid
#hide getutxline
#hide pututxline
#hide setutxent
#hide utmpxname
#hide makeutx
#hide modutx
#hide getutmp
#hide getutmpx
#hide updwtmp
#hide updwtmpx

#expand utmpx.h

extern "C" {
	void endutxent(void);
	struct utmpx *getutxent(void);
	struct utmpx *getutxid(const struct utmpx *);
	struct utmpx *getutxline(const struct utmpx *);
	struct utmpx *pututxline(const struct utmpx *);
	void setutxent(void);
	int utmpxname(const char *);
	struct utmpx *makeutx(const struct utmpx *);
	struct utmpx *modutx(const struct utmpx *);
	void getutmp(const struct utmpx *, struct utmp *);
	void getutmpx(const struct utmp *, struct utmpx *);
	void updwtmp(const char *, struct utmp *);
	void updwtmpx(const char *, struct utmpx *);
}

#endif
