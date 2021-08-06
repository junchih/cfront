/*ident	"@(#)cls4:incl-master/proto-headers/sys/file.h	1.1" */
#usedby bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant svr4 sgi-svr4 solaris

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
#ifndef __FILE_H
#define __FILE_H

#ifndef __TYPES_H
#include <sys/types.h>
#endif

#os bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant svr4 sgi-svr4 solaris
#hide flock
#hide access
#hide lseek
#endos
#os svr4 sgi-svr4 solaris
#hide getf
#hide closeall
#hide closef
#hide ufalloc
#hide falloc
#hide finit
#hide unfalloc
#hide setf
#hide getpof
#hide setpof
#hide filesearch
#hide fassign
#endos

#expand sys/file.h

extern "C" {
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant
	int flock(int fd, int operation);
	int access(const char*, int);
#endos
#os bsd2 sunos3
	long lseek(int fd, long offset, int whence);
#endos
#os bsd3 sunos4 sunos4.1 alliant
	off_t lseek(int fd, off_t offset, int whence);
#endos
#os sgi-svr4
        struct file *getf(unsigned);
        void closef(struct file *);
        struct file *falloc(struct inode*, int);
        void unfalloc(struct file *);
        void setf(int, struct file *);
#endos
#os svr4 solaris
	int getf(int, file_t **);
	int closef(file_t *);
	int falloc(struct vnode *, int, file_t **, int *);
	void unfalloc(file_t *);
	void setf(int, file_t *);
#endos
#os svr4 sgi-svr4 solaris
	void closeall(int);
	int ufalloc(int, int *);
	void finit(void);
	char getpof(int);
	void setpof(int, char);
	int filesearch(struct vnode *);
	int fassign(struct vnode **, int, int*);
#endos
}

#endif
