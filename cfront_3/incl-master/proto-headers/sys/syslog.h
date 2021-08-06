/*ident	"@(#)cls4:incl-master/proto-headers/sys/syslog.h	1.1" */
#usedby bsd3 sunos3 sunos4 sunos4.1

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
#ifndef __SYSLOG_H
#define __SYSLOG_H

#os bsd3 sunos4 sunos4.1
#hide openlog
#hide syslog
#hide setlogmask
#hide closelog

#expand sys/syslog.h
#endos

extern "C" {
    extern void openlog(const char *ident, int logstat, int facility=LOG_USER);
    extern void syslog(int priority, const char *fmt ... );
    extern int setlogmask(int maskpri);
    extern void closelog();
}

#endif
