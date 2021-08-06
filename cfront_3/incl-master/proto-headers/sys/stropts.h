/*ident	"@(#)cls4:incl-master/proto-headers/sys/stropts.h	1.1" */
#usedby uts svr3 sgi

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
#ifndef __STROPTS_H
#define __STROPTS_H

#hide putmsg

#expand sys/stropts.h

extern "C" {
	int getmsg(int, struct strbuf *, struct strbuf *, int *);
	int putmsg(int, const struct strbuf *, const struct strbuf *, int);
#os svr3 sgi
	int getpmsg(int, struct strbuf *, struct strbuf *, int *, int *);
	int putpmsg(int, const struct strbuf *, const struct strbuf *, int, int);
#endos
}

#endif