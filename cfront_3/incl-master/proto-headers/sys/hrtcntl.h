/*ident	"@(#)cls4:incl-master/proto-headers/sys/hrtcntl.h	1.1" */
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
#ifndef __SYS_HRTCNTL_H
#define __SYS_HRTCNTL_H

#hide hrtcntl
#hide hrtalarm
#hide hrtsleep
#hide hrtcancel

#expand sys/hrtcntl.h

extern "C" {
	int hrtcntl(int, int, interval_t *, hrtime_t *);
	int hrtalarm(hrtcmd_t *, int);
	int hrtsleep(hrtcmd_t *);
	int hrtcancel(const long *, int);
}

#endif
