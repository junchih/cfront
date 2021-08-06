/*ident	"@(#)cls4:incl-master/proto-headers/sys/stat.h	1.1" */
#usedby bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts svr4 sgi-svr4 solaris

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
#ifndef __STAT_H
#define __STAT_H

#ifndef __TYPES_H
#include <sys/types.h>
#endif

#hide fstat
#hide ustat
#hide wait
#hide lstat
#hide fstatfs

#os svr4 solaris
#hide stat
#hide mknod
#endos
#os svr4
#hide _fxstat
#hide _xstat
#hide _lxstat
#hide _xmknod
#endos
#os hpux8.0
#hide mknod
#hide chmod
#endos
#os sgi sgi-svr4 svr4 solaris
#hide umask
#hide mkdir
#hide mkfifo
#hide chmod
#endos
#os hpux8.0 sgi-svr4 solaris
#hide fchmod
#endos

#expand sys/stat.h

#os svr4 solaris
/* maps to kernel struct xstat */
struct	stat {
	dev_t	st_dev;
	long	st_pad1[3];	/* reserved for network id */
	ino_t	st_ino;
	mode_t	st_mode;
	nlink_t st_nlink;
	uid_t 	st_uid;
	gid_t 	st_gid;
	dev_t	st_rdev;
	long	st_pad2[2];
	off_t	st_size;
	long	st_pad3;	/* future off_t expansion */
	timestruc_t st_atim;	
	timestruc_t st_mtim;	
	timestruc_t st_ctim;	
	long	st_blksize;
	long	st_blocks;
	char	st_fstype[_ST_FSTYPSZ];
	long	st_pad4[8];	/* expansion area */
};
#endos

extern "C" {
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts sgi-svr4
	int fstat(int, struct stat *);
	int stat(const char*, struct stat *);
#endos
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 alliant sgi-svr4
	int lstat(const char *, struct stat *);
#endos
#os svr4
	int _xstat(const int, const char *, struct stat *);
	int _xmknod(const int, const char *, mode_t, dev_t);
	int _fxstat(const int, int, struct stat *);
	int _lxstat(const int, const char *, struct stat *);
#endos
#os solaris
        int stat(const char *, struct stat *);
        int mknod(const char *, mode_t, dev_t);
        int fstat(int, struct stat *);
        int lstat(const char *, struct stat *);
#endos
#os svr4 solaris sgi-svr4
	int chmod(const char *, mode_t);
	int mkdir(const char *, mode_t);
	int mkfifo(const char *, mode_t);
	mode_t umask(mode_t);
#endos
#os svr3 sgi
	int statfs(const char *, struct statfs *, int, int);
	int fstatfs(int, struct statfs *, int, int);
	int ustat(dev_t, struct ustat *);
#endos
#os hpux8.0
	int mknod(const char*, mode_t, int);
	int chmod(const char *, mode_t);
#endos
#os hpux8.0 sgi-svr4 solaris
	int fchmod(int, mode_t);
#endos
#os svr2
	int ustat(int, struct ustat *) ;
#endos
#os
svr2 svr3 sgi
	int wait(int *) ;
#endos
}

#os svr4
static inline int
stat( const char *path, struct stat *buf )
{
	return _xstat(_STAT_VER, path, buf);
}

static inline int
lstat( const char *path, struct stat *buf )
{
	return _lxstat(_STAT_VER, path, buf);
}

static inline int
fstat( int fd, struct stat *buf )
{
	return _fxstat(_STAT_VER, fd, buf);
}

#ifndef _SVR4_MKNOD_FUNC
#define _SVR4_MKNOD_FUNC
static inline int
mknod( const char *path, mode_t mode, dev_t dev )
{
        return _xmknod(_MKNOD_VER, path, mode, dev);
}
#endif
#endos
#endif
