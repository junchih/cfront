/*ident	"@(#)cls4:incl-master/proto-headers/termcap.h	1.1" */
#usedby sunos3 sunos4 sunos4.1 alliant

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
#ifndef __TERMCAP_H
#define __TERMCAP_H

extern char PC,*BC,*UP;
extern short ospeed;

extern "C" {
    int tgetent(char *, const char *);
    int tgetnum(const char *id);
    int tgetflag(const char *id);
    char *tgetstr(const char *id, char **area);
    char *tgoto(const char *cm, int destcol, int destline);
    int tputs(const char *cp, int affcnt, int (*outc)(int));
}

#endif
