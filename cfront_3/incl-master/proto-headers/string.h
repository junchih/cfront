/*ident	"@(#)cls4:incl-master/proto-headers/string.h	1.1" */
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
#ifndef __STRING_H
#define __STRING_H

#ifndef __MEMORY_H
#include <memory.h>
#endif

#hide strcpy
#hide strncpy
#hide strcat
#hide strncat
#hide strchr
#hide strrchr
#hide strpbrk
#hide strtok
#hide index
#hide rindex
#hide strdup
#hide strcmp
#hide strncmp
#hide strlen
#hide strspn
#hide strcspn

#os hpux hpux8.0
#hide nl_strcmp
#hide nl_strncmp
#endos

#os sunos4.1 solaris
#hide strcasecmp
#hide strncasecmp
#endos

#os sgi svr4 sgi-svr4 solaris
#hide memcpy
#hide memcmp
#hide memchr
#hide memset
#hide memccpy
#hide strstr
#hide strerror
#endos
#os svr4 sgi-svr4 solaris
#hide memmove
#hide ffs
#hide strcoll
#hide strxfrm
#endos

#os bsd2 alliant 
#expand strings.h
#endos
#os bsd3 sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts svr4 sgi-svr4 solaris
#expand string.h
#endos

extern "C" {
#os svr4 sgi-svr4 solaris
	void *memcpy(void*, const void*, size_t);
	void *memmove(void*, const void*, size_t);
	int memcmp(const void*, const void*, size_t);
	void *memchr(const void*, int, size_t);
	void *memset(void*, int, size_t);
	char *strncpy(char*, const char*, size_t);
	char *strncat(char*, const char*, size_t);
	int strncmp(const char*, const char*, size_t);
	size_t strspn(const char*, const char*);
	size_t strcspn(const char*, const char*);
	size_t strlen(const char*);
	void *memccpy(void *, const void *, int, size_t);
	int ffs(const int);
#endos
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts alliant pyramid
	char *strncpy(char*, const char*, int);
	char *strncat(char*, const char*, int);
	int strncmp(const char*, const char*, int);
	int strlen(const char*);
#endos
	char *strcpy(char*, const char*);
	char *strcat(char*, const char*);
	int strcmp(const char*, const char*);
#os bsd3 sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts svr4 sgi-svr4 solaris
	char *strchr(const char*, int);
	char *strpbrk(const char*, const char*);
	char *strrchr(const char*, int);
	char *strtok(char*, const char*);
#endos
#os bsd3 sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts
	int strspn(const char*, const char*);
	int strcspn(const char*, const char*);
#endos
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant
	char *index(const char*, char);
	char *rindex(const char*, char);
#endos
#os sunos3 sunos4 sunos4.1 svr3 sgi hpux hpux8.0 svr4 sgi-svr4 solaris
	char *strdup(const char*);
#endos
#os hpux2.0 hpux
	int nl_strcmp(const char *, const char *);
	int nl_strncmp(const char *, const char *, int);
#endos
#os hpux8.0
	int nl_strcmp(const char *, const char *);
	int nl_strncmp(const char *, const char *, size_t);
#endos
#os hpux hpux8.0 sunos4.1 svr4 sgi-svr4 solaris
	int strcoll(const char *, const char *);
	size_t strxfrm(char *, const char *, size_t);
#endos
#os hpux hpux8.0 svr4 sgi-svr4 solaris
	char *strerror(int);
#endos
#os sunos4.1 solaris
	int strcasecmp(const char *, const char *);
	int strncasecmp(const char *, const char *, int);
#endos
#os sunos4.1 sgi svr4 sgi-svr4 solaris
	char *strstr(const char *, const char *);
#endos
}

#endif
