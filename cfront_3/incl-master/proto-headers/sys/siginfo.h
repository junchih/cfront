/*ident	"@(#)cls4:incl-master/proto-headers/sys/siginfo.h	1.1" */
#usedby svr4 sgi-svr4 solaris

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
#ifndef __SYS_SIGINFO_H
#define __SYS_SIGINFO_H

#hide sigdeq
#hide sigdelq
#hide sigaddq
#hide sigdupq
#hide sigappend
#hide sigprepend
#hide winfo

#expand sys/siginfo.h

extern "C" {
#if defined(_KERNEL)
	void sigdeq(proc_t *, int, sigqueue_t **);
	void sigdelq(proc_t *, int);
	void sigaddq(proc_t *, k_siginfo_t *, int);
	void sigdupq(proc_t *, proc_t *);
	sigqueue_t *sigappend(k_sigset_t *, sigqueue_t *, k_sigset_t *, sigqueue_t *);
	sigqueue_t *sigprepend(k_sigset_t *, sigqueue_t *, k_sigset_t *, sigqueue_t *);
	void winfo(proc_t *, k_siginfo_t *, int);
#endif
}

#endif
