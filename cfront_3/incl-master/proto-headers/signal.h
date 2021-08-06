/*ident	"@(#)cls4:incl-master/proto-headers/signal.h	1.1" */
#usedby all

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
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant svr2 svr3 hpux2.0 hpux hpux8.0 uts sgi pyramid svr4 sgi-svr4 solaris
#ifndef __SIGNAL_H
#include <sys/signal.h>
#endif
#endos

#ifndef __TYPES_H
#include <sys/types.h>
#endif

#os svr4 solaris
#ifndef _SYS_PROCSET_H
#include <sys/procset.h>
#endif
#endos
#os svr4 sgi-svr4 solaris
#ifndef __SVR4_SIGNAL_H
#define __SVR4_SIGNAL_H


#hide signal
#hide raise
#hide kill
#hide sigaction
#hide sigaddset
#hide sigdelset
#hide sigemptyset
#hide sigfillset
#hide sigismember
#hide sigpending
#hide sigprocmask
#hide sigsuspend
#hide gsignal
#hide ssignal
#hide sighold
#hide sigrelse
#hide sigignore
#hide sigset
#hide sigaltstack
#endos
#os svr4 solaris
#hide sigsend
#hide sigsendset
#hide sigpause
#endos

#os svr4 solaris sgi-svr4
#expand signal.h

extern "C" {
	void (*signal(int, void (*)(int)))(int);
	int raise(int);
	int kill(pid_t, int);
	int sigaction(int, const struct sigaction *, struct sigaction *);
	int sigaddset(sigset_t *, int);
	int sigdelset(sigset_t *, int);
	int sigemptyset(sigset_t *);
	int sigfillset(sigset_t *);
	int sigismember(const sigset_t *, int);
	int sigpending(sigset_t *);
	int sigprocmask(int, const sigset_t *, sigset_t *);
	int sigsuspend(sigset_t *);
	int gsignal(int);
	void (*sigset(int, void (*)(int)))(int);
	int sighold(int);
	int sigrelse(int);
	int sigignore(int);
	int (*ssignal(int, int (*)(int)))(int);
	int sigaltstack(const stack_t *, stack_t *);
#endos
#os svr4 solaris
	int sigsend(idtype_t, id_t, int);
	int sigsendset(const procset_t *, int);
	int sigpause(int);
#endos
#os svr4 solaris sgi-svr4
}

#endif
#endos
