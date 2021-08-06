/*ident	"@(#)cls4:incl-master/proto-headers/stdlib.h	1.1" */
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
#ifndef __STDLIB_H
#define __STDLIB_H

#ifndef __STDDEF_H
#include <stddef.h>
#endif

#ifndef __PWD_H
#include <pwd.h>
#endif

#os sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts
#ifndef __RAND48_H
#include <rand48.h>
#endif

#ifndef __REGCMP_H
#include <regcmp.h>
#endif
#endos

#ifndef __ERRNO_H
#include <errno.h>
#endif

#os hpux8.0
#hide access
#endos

#os svr4 sgi-svr4 solaris hpux8.0
#hide grantpt
#hide ptsname
#hide unlockpt
#hide calloc
#hide malloc
#hide realloc
#hide valloc
#hide memalign
#hide atexit
#hide bsearch
#hide abs
#hide div
#hide labs
#hide ldiv
#hide mbtowc
#hide mblen
#hide wctomb
#hide mbstowcs
#hide wcstombs
#hide dup2
#hide getlogin
#hide getopt
#hide getsubopt
#hide putenv
#hide realpath
#hide ttyslot
#hide drand48
#hide erand48
#hide lrand48
#hide lcong48
#hide jrand48
#hide mrand48
#hide nrand48
#hide seed48
#hide srand48
#hide atof
#hide atoi
#hide atol
#hide exit
#hide fcvt
#hide ecvt
#hide getpass
#hide gcvt
#hide getenv
#hide getpw
#hide isatty
#hide mktemp
#hide qsort
#hide swab
#hide system
#hide ttyname
#hide a64l
#hide getcwd
#hide l3tol
#hide l64a
#hide ltol3
#hide strtod
#hide strtol
#hide abort
#hide strtoul
#hide rand
#hide srand
#hide free

#expand stdlib.h
#endos

extern "C" {
	double atof(const char*);
	int atoi(const char*);
	long atol(const char*);
	void exit(int);
	char *fcvt(double, int, int*, int*);
	double frexp(double, int*);
	char *ecvt(double, int, int*, int*);
	char *getpass(const char*);
	char *gcvt(double, int, char*);
	char *getenv(const char*);
	int getpw(int, char*);
	int isatty(int);
	char *mktemp(char*);
	void qsort(void*, size_t, size_t, int(*)(const void*, const void*));
	void swab(const char*, char*, int);
	int system(const char*);
	char *ttyname(int);
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 alliant sgi uts pyramid
	const char* crypt(const char*, const char*);
	void encrypt(char*, int);
	double fabs(double);
	char *getlogin();
	double ldexp(double, int);
	double modf(double, double*);
	void perror(const char*);
	void setkey(const char*);
	long time(long*);
	char *tmpnam(char*);
	int ttyslot();
#endos
#os sunos3 sunos4 sunos4.1 svr2 svr3 sgi uts hpux2.0 hpux hpux8.0
	char *ctermid(char*);
	char *cuserid(char*);
	char *tempnam(const char*, const char*);
	int putenv(const char*);
#endos
#os hpux8.0
	int getopt(int, char* const[], const char*);
	int access(const char*, int);
#endos
#os bsd3 sunos3 sunos4 sunos4.1 hpux2.0 hpux svr2 svr3 sgi uts
	int getopt(int, const char* const*, const char*);
#endos
#os sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts svr4 sgi-svr4
	char *getcwd(char*, int);
#endos
#os solaris
	char *getcwd(char*, size_t);
#endos
#os sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts svr4 sgi-svr4 solaris
	long a64l(const char*);
	void l3tol(long*, const char*, int);
	char *l64a(long);
	void ltol3(char*, const long*, int);
#endos
#os svr3 sgi
	int crypt_close(int[]);
	char *des_crypt(char *, char *);
	void des_encrypt(char *, int);
	void des_setkey(char *);
	int getmsg(int, struct strbuf *, struct strbuf *, int *);
	int putmsg(int, const struct strbuf *, const struct strbuf *, int);
	int run_crypt(long, char *, unsigned int, int *);
	int run_setkey(int *, char *) ;
#endos
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 uts
	long clock();
#endos
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant
	int abort(...); /* Args can be examined in dbx */
	unsigned alarm(unsigned);
	int bcmp(const void*, const void*, int);
	void bcopy(const void*, void*, int);
	void bzero(void*, int);
	int execl(const char*, const char* ...);
	int execle(const char*, const char* ...);
	int execlp(const char*, const char* ...);
	int execv(const char*, const char* argv[]);
	int execvp(const char*, const char* argv[]);
	int ffs(int);
	char *getwd(char*);
	char *initstate(unsigned, char*, int);
	int nice(int);
	int pause();
	long random();
	char *setstate(char*);
	int sleep(unsigned);
	void srandom(int);
#endos
#os sunos3 sunos4 sunos4.1
	int lockf(int, int, long);
	long ulimit(int, long);
	int usleep(unsigned);
#endos
#os svr2 svr3 sgi uts
	unsigned sleep(unsigned);
	void srand(unsigned);
#endos
#os hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts
	int abort();
	long sgetl(const char*);
	void sputl(long, char*);
#endos
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts alliant
	int rand();
#endos
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 alliant
	int srand(int);
#endos
#os sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts svr4 sgi-svr4 solaris
	double strtod(const char*, char**);
	long strtol(const char*, char**, int);
#endos
#os svr4 sgi-svr4 solaris
	int atexit(void (*)(void));
	char *getlogin(void);
	int getopt(int, char *const *, const char *);
	void abort(void);
	int rand(void);
	void srand(unsigned int);
	int ttyslot(void);
	long time(long*);
	int putenv(const char *);
#endos
#os svr4 sgi-svr4 solaris hpux8.0
	int grantpt(int);
	char *ptsname(int);
	int unlockpt(int);
	unsigned long strtoul(const char*, char**, int);
	void free(void *);
#if defined(__STDC__)
	void *calloc(size_t, size_t);
	void *malloc(size_t);
	void *realloc(void *, size_t);
	void *valloc(size_t);
	void * memalign(size_t, size_t);
#else
	char *calloc(size_t, size_t);
	char *malloc(size_t);
	char *realloc(void *, size_t);
	char *valloc(size_t);
	char *memalign(size_t, size_t);
#endif
	void *bsearch(const void *, const void *, size_t, size_t,
        		int (*)(const void *, const void *));
	int abs(int);
	div_t div(int, int);
	long int labs(long);
	ldiv_t ldiv(long, long);
	int mbtowc(wchar_t *, const char *, size_t);
	int mblen(const char *, size_t);
#define	mblen(s, n)	mbtowc((wchar_t *)0, s, n)
	int wctomb(char *, wchar_t);

	size_t mbstowcs(wchar_t *, const char *, size_t);
	size_t wcstombs(char *, const wchar_t *, size_t);

	int dup2(int, int);
	int getsubopt(char **, char *const *, char **);
	char *realpath(char *, char *);

	double drand48(void);
	double erand48(unsigned short *);
	long jrand48(unsigned short *);
	void lcong48(unsigned short *);
	long lrand48(void);
	long mrand48(void);
	long nrand48(unsigned short *);
	unsigned short *seed48(unsigned short *);
	void srand48(long);
#endos
#os sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 alliant
	void closelog();
	int endnetgrent();
	int getnetgrent(char**, char**, char**);
	int initgroups(char*, int);
	void openlog(const char*, int, int);
	int rnusers(const char*);
	int rresvport(int*);
	int ruserok(const char*, int, const char*, const char*);
	int setnetgrent(char*);
	void syslog(int, const char* ...);
#endos
#os sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0
	int rwall(const char*, const char*);
	int setlogmask(int);
#endos
#os hpux2.0 hpux hpux8.0 uts
	char *maphost(const char*, char, const char*, const char*, const char*);
	char *miscfield(char, char);
#endos
#os hpux2.0 hpux hpux8.0 alliant
	int rcmd(char**, unsigned short, const char*, const char*, const char*, int*);
	int rexec(char**, int, const char*, const char*, const char*, int*);
#endos
#os hpux2.0 hpux hpux8.0
	unsigned alarm(unsigned long);
	unsigned long sleep(unsigned long);
	int currlangid();
	char *gethcwd(char*, int);
	char *getmsg(int, int, int, char*, int);
	int langinit(char*);
	int langtoid(char*);
	double nl_atof(const char*, int);
	char *nl_gcvt(double, size_t, char*, int);
	int nl_init(char*);
	double nl_strtod(const char*, char**, int);
	int x25perror(const char*);
	int abs(int);
#endos
#os hpux
       int datalock(int, int);
#endos
#os hpux8.0
       int datalock(size_t, size_t);
#endos
#os hpux hpux8.0
	int atexit(void (*)());
#endos
}

#os bsd3 sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts sgi-svr4
extern char *optarg;
extern int optind, opterr;
#endos
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant
extern char **environ;
extern int end, etext, edata;
#endos

#ifndef __MALLOC_H
#include <malloc.h>
#endif

#endif
