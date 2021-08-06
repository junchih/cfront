/*ident	"@(#)cls4:incl-master/proto-headers/syslog.h	1.1" */
#usedby bsd3 sunos3 sunos4 sunos4.1 svr4 sgi-svr4 solaris

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
#os bsd3 sunos4 sunos4.1 svr4 sgi-svr4
/* The real definition is in <sys/syslog.h> */
#endos
#os solaris
#hide openlog
#hide syslog
#hide vsyslog
#hide closelog
#hide setlogmask
#expand syslog.h
#endos
#os sunos3
#expand syslog.h
#endos

#ifndef __SYSLOG_H
#include <sys/syslog.h>
#endif
#os solaris
extern "C" {
void openlog(const char *, int, int);
void syslog(int, const char *, ...);
void vsyslog(int, const char*, va_list);
void closelog(void);
int setlogmask(int);
}
#endos
