/*ident	"@(#)cls4:incl-master/proto-headers/sys/ipc.h	1.1" */
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
#ifndef __IPC_H
#define __IPC_H

#ifndef __TYPES_H
#include <sys/types.h>
#endif

#os sunos3 sunos4 sunos4.1 hpux2.0 hpux svr2 svr3 sgi uts
#hide msgget
#hide semget
#hide shmget
#endos
#hide ftok

#expand sys/ipc.h

extern "C" {
#os sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts
	key_t ftok(const char *, char);
#endos
#os svr4 sgi-svr4 solaris
	key_t ftok(const char *, int);
#endos
#os svr2 svr3 sgi
	int msgget (key_t,int) ;
	int semget (key_t,int,int) ;
	int shmget (key_t,int,int) ;
#endos
}

#endif
