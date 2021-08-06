/*ident	"@(#)cls4:incl-master/proto-headers/arpa/inet.h	1.1" */
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
#usedby bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant solaris
#ifndef __INET_H
#define __INET_H

/*
 * External definitions for functions in inet(3N)
 */

extern "C" {
#os bsd2 alliant
        struct in_addr   inet_addr(const char*);
#endos
#os bsd3 sunos3 sunos4 sunos4.1 solaris
        unsigned long    inet_addr(const char*);
#endos
        char*            inet_ntoa(struct in_addr);
        struct in_addr   inet_makeaddr(int, int);
        unsigned long    inet_network(const char*);
        int              inet_lnaof(struct in_addr);
        int              inet_netof(struct in_addr);
}

#endif
