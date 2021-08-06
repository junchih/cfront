/*ident	"@(#)cls4:incl-master/proto-headers/sys/netconfig.h	1.1" */
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
#ifndef __SYS_NETCONFIG_H
#define __SYS_NETCONFIG_H

#hide setnetconfig
#hide endnetconfig
#hide getnetconfig
#hide getnetconfigent
#hide freenetconfigent
#hide setnetpath
#hide endnetpath
#hide getnetpath

#expand sys/netconfig.h

extern "C" {
	void              *setnetconfig(void);
	int                endnetconfig(void *);
	struct netconfig  *getnetconfig(void *);
	struct netconfig  *getnetconfigent(char *);
	void               freenetconfigent(struct netconfig *);
	void              *setnetpath(void);
	int                endnetpath(void *);
	struct netconfig  *getnetpath(void *);
}

#endif
