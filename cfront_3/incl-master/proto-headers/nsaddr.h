/*ident	"@(#)cls4:incl-master/proto-headers/nsaddr.h	1.1" */
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

#ifndef __NSADDR_H
#define __NSADDR_H

#hide stoa
#hide atos
#hide astoa
#hide aatos

#expand nsaddr.h

extern "C" {
	struct netbuf   *stoa(char *, struct netbuf *);
	char            *atos(char *, struct netbuf *, int);
	struct address  *astoa(char *, struct address *);
	char            *aatos(char *, struct address *, int);
}

#endif /* __NSADDR_H */
