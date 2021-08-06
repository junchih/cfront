/*ident	"@(#)cls4:incl-master/proto-headers/sys/events.h	1.1" */
#usedby svr4 

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
#ifndef __SYS_EVENTS_H
#define __SYS_EVENTS_H

#hide __evpost
#hide __evpoll
#hide __evpollmore
#hide __evtrap
#hide __evtrapcancel
#hide __evcntl
#hide __evqcntl
#hide __evexit
#hide __evexitset
#hide __evsig

#expand sys/events.h

extern "C" {
	int     __evpost(const evver_t, event_t *const, const int, const int);
	int     __evpoll(const evver_t, const evpollcmds_t, event_t *const,
                         const int, const hrtime_t *const);
	int     __evpollmore(const evver_t, event_t *const, const int);
	int     __evtrap(const evver_t, const evpollcmds_t, event_t *const,
                         const int, const long,
                         void (*const)(event_t *, int, long, evcontext_t *),
                         const evta_t *const);
	int     __evtrapcancel(const evver_t, long *const, const int);
	int     __evcntl(const evver_t, const evcntlcmds_t, const long,
                         const long);
	int     __evqcntl(const evver_t, const eqd, const evqcntlcmds_t,
                         const long);
	int     __evexit(const evver_t, const idtype_t, const id_t,
                         const ecb_t *const);
	int     __evexitset(const evver_t, const procset_t *const,
                         const hostid_t hostid, const ecb_t *const);
	int     __evsig(const evver_t, const sigset_t *const,
                         const ecb_t *const, evsiginfo_t *const, const int);
}

#endif
