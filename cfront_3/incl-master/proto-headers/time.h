/*ident	"@(#)cls4:incl-master/proto-headers/time.h	1.1" */
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
#ifndef __TIME_H
#define __TIME_H

#hide gmtime
#hide localtime
#hide asctime
#hide ctime
#os svr3 sgi svr4 sgi-svr4 solaris
#hide cftime
#hide ascftime
#endos
#hide tzset
#hide tzsetwall
#hide time
#os sunos4.1
#hide dysize
#hide strftime
#hide strptime
#hide timelocal
#hide timegm
#endos
#os sgi hpux hpux8.0 svr4 sgi-svr4 solaris
#hide clock
#hide mktime
#hide strftime
#hide difftime
#endos
#os svr4 sgi-svr4 solaris
#hide getdate
#endos
#os solaris
#hide _sysconf
#endos

#expand time.h

extern "C" {
	/*const*/ char *asctime(const struct tm*);
	/*const*/ char *ctime(const long*);
	/*const*/ struct tm *gmtime(const long*);
	/*const*/ struct tm *localtime(const long*);
	long time(long*);
#os svr3 sgi
	int ascftime(char *, const char *, const struct tm*);
	int cftime(char*, const char*, const long*);
#endos
#os sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts
	void tzset();
#endos
#os hpux2.0 hpux hpux8.0
	char *nl_asctime(struct tm *, char *, int);
	char *nl_ascxtime(struct tm *, char *);
	char *nl_ctime(long *, char *, int);
	char *nl_cxtime(long *, char *);

#endos
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant
	/*const*/ char *timezone(int, int);
	int dysize(int);
#endos
#os sunos3 sunos4 sunos4.1
	void tzsetwall();
#endos
#os hpux hpux8.0 svr4 sgi-svr4 solaris
	double difftime(time_t, time_t);
	time_t mktime(struct tm *);
	size_t strftime(char *, size_t, const char *, const struct tm *);
	extern clock_t clock(void);
#endos
#os svr4 sgi-svr4 solaris
	void tzset(void);
	int cftime(char *, char *, const time_t *);
	int ascftime(char *, const char *, const struct tm *);
	struct tm *getdate(const char *);
#endos
#os sunos4.1
	time_t timelocal(const struct tm *);
	time_t timegm(const struct tm *);
	int strftime(char *, int, const char *, const struct tm *);
	char *strptime(const char *, const char *, struct tm *);
#endos
#os solaris
	long _sysconf(int);
#endos
}

#endif
