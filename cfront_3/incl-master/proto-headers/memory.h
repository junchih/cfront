/*ident	"@(#)cls4:incl-master/proto-headers/memory.h	1.1" */
#usedby bsd3 sunos3 sunos4 sunos4.1 alliant hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts svr4 sgi-svr4 solaris

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
#os bsd3 sunos3 sunos4 sunos4.1 alliant hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts
#ifndef __MEMORY_H
#define __MEMORY_H
#endos
#os svr4 sgi-svr4 solaris
#ifndef ___MEMORY_H
#define ___MEMORY_H
#endos

#os bsd3 sunos3 sunos4 sunos4.1 hpux2.0 svr2 svr3 sgi uts svr4 sgi-svr4 solaris

#hide memccpy
#hide memchr
#hide memcpy
#hide memset
#hide memcmp

#expand memory.h
#endos

#os bsd3 sunos3 sunos4 sunos4.1 hpux2.0 svr2 svr3 sgi uts
extern "C" {
    void* memcpy(void*, const void*, int);
    void* memccpy(void*, const void*, int, int);
    void* memchr(const void*, int, int);
    int   memcmp(const void*, const void*, int);
    void* memset(void*, int, int);
}

#endos
#os svr4 sgi-svr4 solaris
extern "C" {
    void* memcpy(void*, const void*, size_t);
    void* memccpy(void*, const void*, int, size_t);
    void* memchr(const void*, int, size_t);
    void* memset(void*, int, size_t);
    int   memcmp(const void*, const void*, size_t);
}

#endos

#os hpux hpux8.0

#hide memccpy
#hide memchr
#hide memcpy
#hide memset
#hide memcmp

#include <stddef.h>
#expand memory.h

extern "C" {
    void* memcpy(void*, const void*, size_t);
    void* memccpy(void*, const void*, int, size_t);
    void* memchr(const void*, int, size_t);
    int   memcmp(const void*, const void*, size_t);
    void* memmove(void*, const void*, size_t);
    void* memset(void*, int, size_t);
}

#endos

#os alliant


extern "C" {
    void bcopy(const void* from, void* to, int length);
    /* These are NOT in libc, however they are in libx.a */
    int   memcmp(const void* s1, const void* s2, int n);
    void* memset(void* s, int c, int n);
}

/* BUG in 6.1 prevents this */
/*
inline void* memcpy(void* to, const void* from, int n)
    { bcopy(from,to,n); return to; }
*/
#define memcpy(t,f,n) bcopy(f,t,n)

#endos


#endif


