/*ident	"@(#)cls4:incl-master/proto-headers/sys/wait.h	1.1" */
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
#ifndef __WAIT_H
#define __WAIT_H

#os bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant
#ifndef __RESOURCE_H
#include <sys/resource.h>
#endif
#endos

#os hpux hpux8.0 sunos4.1 svr4 solaris sgi-svr4
#hide waitpid
#endos
#os svr4 solaris
#hide wait
#endos
#os svr4 solaris sgi-svr4
#hide waitid
#hide wait3
#endos

#os bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant hpux2.0 hpux hpux8.0 svr4 sgi-svr4 solaris
#expand sys/wait.h
#endos

extern "C" {
#os hpux2.0 svr2 svr3 sgi uts
 	int wait(int*);
#endos
#os hpux2.0
	int wait3(int*, int, int*);
#endos
#os sgi-svr4
        int wait3(union wait*, int, struct rusage*);
#endos
#os hpux hpux8.0 svr4 solaris sgi-svr4
 	pid_t wait(int*);
	pid_t waitpid(pid_t, int*, int);
#endos
#os hpux hpux8.0
	pid_t wait3(int*, int, int*);
#endos
#os svr4 solaris sgi-svr4
	int waitid(idtype_t, id_t, siginfo_t *, int);
#endos
#os bsd2 bsd3 sunos3 sunos4 alliant
        int wait(union wait*);
        int wait3(union wait*, int, struct rusage*);
#endos
#os sunos4 
        int wait4(int, union wait*, int, struct rusage*);
#endos
#os sunos4.1
	int wait(int*);
	int wait3(int*, int, struct rusage*);
	int wait4(int, int*, int, struct rusage*);
	int waitpid(int, int*, int);
#endos
}

#os 
inline int wait(int *stat) { return wait((union wait*)stat); }
inline int wait(int stat) { return wait((union wait*)stat); }
#endos

#endif
