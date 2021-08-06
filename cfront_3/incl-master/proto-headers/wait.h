/*ident	"@(#)cls4:incl-master/proto-headers/wait.h	1.1" */
#usedby svr4 solaris

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
#ifndef __WAIT_H
#define __WAIT_H

#hide wait
#hide waitpid
#hide waitid

#expand wait.h

extern "C" {
	pid_t wait(int *);
	pid_t waitpid(pid_t, int *, int);
	int waitid(idtype_t, id_t, siginfo_t *, int);
}

#endif
