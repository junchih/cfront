/*ident	"@(#)cls4:incl-master/proto-headers/sys/session.h	1.1" */
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
#ifndef __SYS_SESSION_H
#define __SYS_SESSION_H

#hide sess_rele
#hide sess_create
#hide freectty
#hide alloctty
#hide realloctty
#hide cttydev
#hide hascttyperm

#expand sys/session.h

extern "C" {
	int sess_rele(sess_t *);
	void sess_create(void);
	void freectty(sess_t *);
	void alloctty(proc_t *, vnode_t *);
	int realloctty(proc_t *, pid_t);
	dev_t cttydev(proc_t *);
	int hascttyperm(sess_t *, cred_t *, mode_t);
}

#endif
