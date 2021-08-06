/*ident	"@(#)cls4:incl-master/proto-headers/sys/shm.h	1.1" */
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
#ifndef __SHM_H
#define __SHM_H

#ifndef __TYPES_H
#include <sys/types.h>
#endif

#hide shmat
#hide shmctl
#hide shmdt
#hide shmget

#os solaris
#hide _sysconf
#endos

#expand sys/shm.h

extern "C" {
#os sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts svr4 sgi-svr4 solaris
	int shmget(key_t, int, int);
#endos
#os sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts
	char *shmat(int, void*, int);
	int shmctl(int, int, struct shmid_ds *);
	int shmdt(const void*);
#endos
#os svr4 sgi-svr4 solaris
	void *shmat(int, void*, int);
	int shmctl(int, int, ...);
	int shmdt(void*);
#endos
#os solaris
	long _sysconf(int);
#endos
}
#endif
