/*ident	"@(#)cls4:incl-master/proto-headers/sys/prsystm.h	1.1" */
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
#ifndef __SYS_PRSYSTM_H
#define __SYS_PRSYSTM_H

#hide prawake
#hide prinvalidate
#hide prgetpsinfo
#hide prgetfpregs
#hide prnsegs
#hide prexit
#hide prgetstatus

#expand sys/prsystm.h

extern "C" {
	void prawake(proc_t *);
	void prinvalidate(struct user *);
	void prgetpsinfo(proc_t *, struct prpsinfo *);
	void prgetfpregs(proc_t *, fpregset_t *);
	int prnsegs(proc_t *);
	void prexit(proc_t *);
	void prgetstatus(proc_t *, prstatus_t *);
}

#endif
