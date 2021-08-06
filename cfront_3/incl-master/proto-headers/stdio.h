/*ident	"@(#)cls4:incl-master/proto-headers/stdio.h	1.1" */
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
#ifndef __STDIO_H
#define __STDIO_H

#ifndef __ERRNO_H
#include <errno.h>
#endif

#os svr3 sgi
#hide putspent
#hide fgetspent
#endos

#hide ctermid
#hide cuserid
#hide fdopen
#hide fopen
#hide freopen
#hide fgets
#hide ftell
#hide gets
#hide popen
#hide rewind
#hide setbuf
#hide setlinebuf
#hide tempnam
#hide tmpfile
#hide tmpnam
#hide sprintf
#hide fclose
#hide fflush
#hide fgetc
#hide fprintf
#hide fputc
#hide fputs
#hide fread
#hide fscanf
#hide fseek
#hide fwrite
#hide getw
#hide pclose
#hide printf
#hide puts
#hide putw
#hide scanf
#hide setvbuf
#hide sscanf
#hide system
#hide ungetc
#hide utmpname
#hide vfprintf
#hide vprintf
#hide vsprintf

#os sgi svr4 sgi-svr4 solaris
#hide perror
#hide remove
#hide rename
#endos

#os hpux hpux8.0 svr4 sgi-svr4 solaris
#hide __flsbuf
#hide __filbuf
#endos

#os svr4 sgi-svr4 solaris
#hide fgetpos
#hide fsetpos
#hide _flsbuf
#endos

#os sgi-svr4
#hide _filbuf
#hide mktemp
#hide exit
#hide atof
#endos

#os sgi
#hide _flsbuf
#hide _filbuf
#hide mktemp
#hide mkstemp
#endos

#os solaris
#hide getopt
#hide getsubopt
#endos

#os sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts svr4 sgi-svr4 solaris
/* need stddef.h for size_t */
#ifndef __STDDEF_H
#include <stddef.h>
#endif
#endos

#ifdef NULL
#undef NULL
#endif

#expand stdio.h

extern "C" {
	int _filbuf(FILE *);
	int fclose(FILE *);
	FILE *fdopen(int, const char *);
	int fflush(FILE *);
	int fgetc(FILE *);
	char *fgets(char *, int, FILE *);
	FILE *fopen(const char *, const char *);
	int fprintf(FILE *, const char * ...);
	int fputc(int, FILE *);
	int fputs(const char *, FILE *);
	FILE *freopen(const char *, const char *, FILE *);
	int fscanf(FILE *, const char * ...);
	int fseek(FILE *, long, int);
	char *gets(char *);
	int getw(FILE *);
	int pclose(FILE *);
	FILE *popen(const char *, const char *);
	int printf(const char * ...);
	int puts(const char *);
	int putw(int, FILE *);
	void rewind(FILE *);
	int scanf(const char * ...);
	void setbuf(FILE *, char *);
	int sscanf(const char *, const char * ...);
	int ungetc(int, FILE *);
#os svr4 sgi-svr4 solaris
	int remove(const char *);
	int rename(const char *, const char *);
	long ftell(FILE *);
	FILE *tmpfile(void);
#ifndef getc
	int getc(FILE *);
#endif
#ifndef getchar
	int getchar(void);
#endif
#ifndef putc
	int putc(int, FILE *);
#endif
#ifndef putchar
	int putchar(int);
#endif
	int fgetpos(FILE *, fpos_t *);
	int fsetpos(FILE *, const fpos_t *);
        size_t fread(void *, size_t, size_t, FILE *);
        size_t fwrite(const void *, size_t, size_t, FILE *);
	void perror(const char *);
#ifndef ferror
	int ferror(FILE *);
#endif
#ifndef feof
	int feof(FILE *);
#endif
#ifndef fileno
	int fileno(FILE *);
#endif
#ifndef clearerr
	void clearerr(FILE *);
#endif
	char *ctermid(char *);
	char *cuserid(char *);
	char *tempnam(const char *, const char *);
#endos
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 hpux hpux8.0 hpux2.1 svr2 svr3 alliant sgi uts pyramid
	long ftell(const FILE *);
#endos
#os sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts svr4 sgi-svr4 solaris
	int setvbuf(FILE *, char *, int, size_t);
#endos
#os sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts
	FILE *tmpfile();
#endos
#os svr3 sgi
	int putspent(struct spwd *, FILE*);
	struct spwd *fgetspent(FILE *);
#endos
#os svr2 svr3 sgi uts
	int _flsbuf(unsigned, FILE *);
#endos
#os bsd2 sunos3 sunos4 sunos4.1 alliant svr2 svr3 sgi
        int fread(void *, int, int, FILE *);
        int fwrite(const void *, int, int, FILE *);
#endos
#os hpux2.0 hpux hpux8.0 uts
        int fread(void *, unsigned, int, FILE *);
        int fwrite(const void *, unsigned, int, FILE *);
#endos
#os bsd3
        int fread(void *, unsigned, unsigned, FILE *);
        int fwrite(const void *, unsigned, unsigned, FILE *);
#endos
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 alliant
	int _flsbuf(unsigned char, FILE *);
#ifndef ferror
	int ferror(FILE *);
#endif
#ifndef feof
	int feof(FILE *);
#endif
#ifndef fileno
	int fileno(FILE *);
#endif
#ifndef clearerr
	void clearerr(FILE *);
#endif
#endos
#os hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts svr4 sgi-svr4 solaris
	int sprintf(char *, const char * ...);
#endos
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant
 	char *sprintf(char *, const char * ...);
	int setbuffer(FILE *, char *, int);
	int setlinebuf(FILE *);
#endos
#os hpux2.0 hpux hpux8.0
	int nl_fprintf(FILE *, const char * ...);
	int nl_fscanf(FILE *, const char * ...);
	int nl_printf(const char * ...);
	int nl_scanf(const char * ...);
	int nl_sprintf(char *, const char * ...);
	int nl_sscanf(const char *, const char * ...);
#endos
#os hpux hpux8.0 svr4 sgi-svr4 solaris
	int __filbuf(FILE *);
#endos
#os hpux hpux8.0
	int __flsbuf(unsigned, FILE *);
#endos
#os svr4 sgi-svr4 solaris
	int __flsbuf(int, FILE *);
	int _flsbuf(unsigned, FILE *);
#endos
#os alliant
	void _doprnt(const char * fmt, /* va_list */ char *args, FILE * stream);
#endos
#os sgi sgi-svr4
	int _semgetc(FILE *);
	int _semputc(int, FILE *);
	int setlinebuf(FILE *);
#endos
#os solaris
	int getsubopt(char **, char *const *, char **);
	int getopt(int, char *const *, const char *);
#endos
}

/* ANSI C says tmpnam belongs in stdio.h. It is also declared in stdlib.h */

extern "C" {
	char *tmpnam(char*);  
}

#endif
