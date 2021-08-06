/*ident	"@(#)cls4:incl-master/proto-headers/sys/msg.h	1.1" */
#usedby sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts svr4 sgi-svr4 solaris

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
#ifndef __MSG_H
#define __MSG_H

#ifndef __TYPES_H
#include <sys/types.h>
#endif

#hide msgctl
#hide msgget
#hide msgrcv
#hide msgsnd

#expand sys/msg.h

extern "C" {
	int msgget(key_t, int);
#os sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts
	int msgctl(int, int, struct msqid_ds *);
#endos
#os sunos3 sunos4 sunos4.1 hpux2.0 hpux svr2 svr3 sgi uts
	int msgrcv(int, struct msgbuf *, int, long, int);
	int msgsnd(int, struct msgbuf *, int, int);
#endos
#os svr4 sgi-svr4 solaris
	int msgctl(int, int, ...);
#endos
#os svr4 sgi-svr4 solaris hpux8.0
	int msgrcv(int, void *, size_t, long, int);
	int msgsnd(int, const void *, size_t, int);
#endos
}
#endif
