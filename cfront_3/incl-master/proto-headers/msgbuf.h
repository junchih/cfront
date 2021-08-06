/*ident	"@(#)cls4:incl-master/proto-headers/msgbuf.h	1.1" */
#usedby hpux2.0 hpux hpux8.0

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
#ifndef __MSGBUF_H
#define __MSGBUF_H

#hide catgetmsg
#hide catgets
#hide catopen
#hide catclose
#hide catread

#expand msgbuf.h


extern "C" {
extern char *catgetmsg(nl_catd, int, int, char *, int);
extern char *catgets(nl_catd, int, int, char *);
extern nl_catd catopen(char *, int);
extern int catclose(nl_catd);
extern int catread(int, int, int, char *, int ...);
};

#endif
