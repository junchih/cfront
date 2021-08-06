/*ident	"@(#)cls4:incl-master/proto-headers/sys/mman.h	1.1" */
#usedby sunos3 sunos4 sunos4.1 svr4 sgi-svr4 solaris

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
#ifndef __MMAN_H
#define __MMAN_H

#ifndef __TYPES_H
#include <sys/types.h>
#endif

#hide mmap
#hide munmap

#os svr4 sgi-svr4 solaris
#hide memcntl
#hide mprotect
#hide msync
#hide mlockall
#hide munlockall
#endos

#expand sys/mman.h

extern "C" {
#os sunos3 sunos4 sunos4.1
	caddr_t mmap(caddr_t addr, int len, int prot, int share, int fd, off_t off);
	int munmap(caddr_t addr, int len);
#endos
#os svr4 sgi-svr4 solaris
	caddr_t mmap(caddr_t, size_t, int, int, int, off_t);
	int munmap(caddr_t, size_t);
	int memcntl(caddr_t, size_t, int, caddr_t, int, int);
	int mlockall(int);
	int munlockall();
	int mprotect(caddr_t, size_t, int);
	int msync(caddr_t, size_t, int);
#endos
}

#endif
