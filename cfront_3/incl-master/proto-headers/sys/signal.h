/*ident	"@(#)cls4:incl-master/proto-headers/sys/signal.h	1.1" */
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
#ifndef __SIGNAL_H
#define __SIGNAL_H

#hide signal
#hide sigset
#hide ssignal
#hide gsignal
#hide kill

#os solaris
#hide _sysconf
#endos

#os sgi sgi-svr4 hpux8.0
#hide sighold
#hide sigrelse
#hide sigignore
#hide sigpause
#endos

#os hpux2.0 hpux hpux8.0
#hide sigspace
#endos

#expand sys/signal.h

typedef void SIG_FUNC_TYP(int);
typedef SIG_FUNC_TYP *SIG_TYP;
#define SIG_PF SIG_TYP

#os bsd2 bsd3 sunos3
typedef void COMPLETE_SIG_FUNC_TYP(int, int, struct sigcontext*);
#endos
#os sunos4 sunos4.1 alliant
typedef void COMPLETE_SIG_FUNC_TYP(int, int, struct sigcontext*, char*);
#endos
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant
typedef COMPLETE_SIG_FUNC_TYP *COMPLETE_SIG_TYP;
#define COMPLETE_SIG_PF COMPLETE_SIG_TYP
#endos

extern "C" {
	SIG_TYP signal(int, SIG_TYP);
#os svr2 svr3 bsd2 bsd3 sunos3 sunos4 sunos4.1 hpux2.0 alliant uts sgi pyramid
	int kill(int, int);
#endos
#os hpux hpux8.0
	int kill(pid_t, int);
	size_t sigspace(size_t);
#endos
#os hpux2.0
	long sigspace(long);
#endos
#os hpux2.0 hpux hpux8.0
	long sigblock(long);
	long sigpause(long);
	long sigsetmask(long);
#endos
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant uts svr3 sgi
	int sigpause(int);
#endos
#os bsd3 sunos3 sunos4 sunos4.1 alliant
	int sigblock(int);
	int sigsetmask(int);
#endos
#os svr2 svr3 sgi sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 uts
	SIG_TYP ssignal(int, SIG_TYP);
	int gsignal(int);
#endos
#os svr3 sgi sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 uts
	SIG_TYP sigset(int, SIG_TYP);
#endos
#os bsd3 sunos3 sunos4 sunos4.1 alliant hpux2.0 hpux hpux8.0
	int sigstack(const struct sigstack*, struct sigstack*);
	int sigvec(int, const struct sigvec*, struct sigvec*);
#endos
#os bsd3 sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0
	int sigreturn(struct sigcontext*);
#ifndef sigmask
	int sigmask(int);
#endif
#endos
#os svr3 sgi uts sgi-svr4 hpux8.0
	int sighold(int);
	int sigrelse(int);
	int sigignore(int);
#endos
#os hpux2.0 hpux
	int sigvector(int, struct sigvec *, struct sigvec *);
#endos
#os hpux8.0
	int sigvector(int, const struct sigvec *, struct sigvec *);
#endos

#os solaris
	long _sysconf(int);
#endos
}

#os sunos3 sunos4 sunos4.1 alliant
inline COMPLETE_SIG_TYP signal(int s, COMPLETE_SIG_TYP f)
{
	return (COMPLETE_SIG_TYP)signal(s, (SIG_TYP)f);
}
#endos
#os sunos3 sunos4 sunos4.1
inline COMPLETE_SIG_TYP ssignal(int s, COMPLETE_SIG_TYP f)
{
	return (COMPLETE_SIG_TYP)ssignal(s, (SIG_TYP)f);
}
inline COMPLETE_SIG_TYP sigset(int s, COMPLETE_SIG_TYP f)
{
	return (COMPLETE_SIG_TYP)sigset(s, (SIG_TYP)f);
}
#endos

/* The type of these defines are wrong in the native header.
*/

#os
svr2 has dfl ign
svr3 sgi has dfl ign hold 2
sunos3 has dfl ign kernel<catch 2 hold 3>
sunos4 has err dfl ign kernel<catch 2> hold 3
sunos4.1 has err dfl ign kernel<catch 2> hold 3
hpux hpux8.0 has dfl ign kernel<catch 2 hold 3>
uts has err dfl ign hold 2
#endos

#ifdef SIG_ERR
#undef SIG_ERR
#define SIG_ERR (SIG_PF)-1
#endif

#ifdef BADSIG
#undef BADSIG
#define BADSIG SIG_ERR
#endif

#ifdef SIG_DFL
#undef SIG_DFL
#define SIG_DFL (SIG_PF)0
#endif

#ifdef SIG_IGN
#undef SIG_IGN
#define SIG_IGN (SIG_PF)1
#endif

#os sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0
#ifdef KERNEL
#endos

#ifdef SIG_CATCH
#undef SIG_CATCH
#define SIG_CATCH (SIG_PF)2
#endif

#os sunos4 sunos4.1
#endif
#endos

#ifdef SIG_HOLD
#       undef SIG_HOLD
#os sunos3 sunos4 solaris bsd2 bsd3 hpux hpux8.0 svr2 svr3 uts sgi pyramid svr4 svr4FT 3b2mips
#       ifdef SIG_CATCH
#               define SIG_HOLD (SIG_PF)3
#       else
#               define SIG_HOLD (SIG_PF)2
#       endif
#endos
#os sunos4.1
#       define SIG_HOLD (SIG_PF)3
#endos
#endif

#os sunos3 hpux2.0 hpux hpux8.0
#endif
#endos

#endif
