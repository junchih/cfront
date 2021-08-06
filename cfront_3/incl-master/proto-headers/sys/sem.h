/*ident	"@(#)cls4:incl-master/proto-headers/sys/sem.h	1.1" */
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
#ifndef __SEM_H
#define __SEM_H

#ifndef __TYPES_H
#include <sys/types.h>
#endif

#hide semctl
#hide semget
#hide semop

#expand sys/sem.h

#os svr2 svr3 uts svr4 solaris hpux8.0
union semun {
	int val;
	struct semid_ds *buf;
	ushort *array;
}; 
#endos

extern "C" {
#os sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts svr4 sgi-svr4 solaris
	int semget(key_t, int, int);
#endos
#os sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts
	int semctl(int, int, int, union semun);
	int semop(int, struct sembuf *, int);
#endos
#os svr4 sgi-svr4 solaris
	int semctl(int, int, int, ...);
	int semop(int, struct sembuf *, unsigned);
#endos
}
#endif
