/*ident	"@(#)cls4:incl-master/proto-headers/ftw.h	1.1" */
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
#ifndef __FTW_H
#define __FTW_H

#hide ftw
#hide _xftw
#hide nftw

#expand ftw.h

extern "C" {
#os sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts
	int ftw(const char *, int (*)(char *, struct stat *, int), int);
#endos
#os svr4 sgi-svr4 solaris
	int _xftw(const int, const char *, int (*)(const char *, const struct stat *, int), int);
#endos
#os hpux2.0 hpux hpux8.0
	int ftwh(const char *, int (*)(char *, struct stat *, int), int);
#endos
}

#os svr4 sgi-svr4 solaris
#if   !defined(_STYPES)

#ifndef XFTWVER
#define XFTWVER	2	/* version of file tree walk */
#endif

static int ftw( const char *path,
	int (*fn)(const char*, const struct stat*, int),
	int depth)
{
	return(_xftw(XFTWVER, path,
	 (int(*)(const char*, const struct stat*, int))fn,
	 depth));
}
extern "C" {
	int nftw(const char *, int (*)(const char *, const struct stat *, int, struct FTW *), int, int);
}
#endif

/* nftw not available to non-EFT applications */

#if   defined(_STYPES)
#include <errno.h>

static int nftw( const char *path,
	int (*fn)(const char*, const struct stat*, int, struct FTW*),
	int depth, int flags)
{
	return(EINVAL);
}
extern "C" {
	int ftw(const char *, int (*)(char *, struct stat *, int), int);
}
#endif
#endos

#endif
