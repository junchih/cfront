/*ident	"@(#)cls4:incl-master/proto-headers/malloc.h	1.1" */
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
#ifndef __MALLOC_H
#define __MALLOC_H

/* This macro is introduced for the sole purpose of making it possible to 
*  build cfront 2.0b6.1 and later versions with earlier versions of cfront.
*/
#ifndef __HAVE_SIZE_T
#define __HAVE_SIZE_T
#endif

#ifndef __STDDEF_H
#include <stddef.h>
#endif

#os sunos3 sunos4 sunos4.1 hpux2.0 svr2 svr3 sgi uts svr4 sgi-svr4 solaris
#hide calloc
#hide realloc
#hide malloc
#hide mallopt
#hide free
#hide cfree

#expand malloc.h
#endos

#os hpux hpux8.0
#hide calloc
#hide realloc
#hide malloc
#hide mallopt
#hide free
#hide cfree

extern "C" {
#expand malloc.h
}
#endos

extern "C" {
#os svr4 sgi-svr4 solaris
#if !defined(__STDC__)
#endos
	char *malloc(size_t);
	void free(void*);
	char *realloc(void*, size_t);
	char *calloc(unsigned, size_t);
#os svr4 sgi-svr4 solaris
#else
	void *malloc(size_t);
	void free(void*);
	void *realloc(void *, size_t);
	void *calloc(size_t, size_t);
#endif
#endos
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 hpux hpux8.0 hpux2.0 svr2 svr3 sgi alliant uts pyramid
	void cfree(void*);
#endos
#os sunos3 sunos4 sunos4.1 hpux2.0 svr2 svr3 sgi uts
	int mallopt(int, int);
	struct mallinfo mallinfo(int);
#endos
#os svr4 sgi-svr4 solaris
	int mallopt(int, int);
#endos
#os hpux hpux8.0 svr4 sgi-svr4 solaris
	struct mallinfo mallinfo();
#endos
#os sunos3 sunos4 sunos4.1
	char *memalign(unsigned, size_t);
	char *valloc(size_t);
	int malloc_debug(int);
	int malloc_verify();
#endos
#os bsd2 bsd3 sunos3 alliant
	char *alloca(int);
#endos
}

#endif
