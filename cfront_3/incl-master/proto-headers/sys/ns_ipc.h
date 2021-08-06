/*ident	"@(#)cls4:incl-master/proto-headers/sys/ns_ipc.h	1.1" */
#usedby hpux2.0 hpux hpux8.0

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
#ifndef __NS_IPC_H
#define __NS_IPC_H

#ifndef __TYPES_H
#include <sys/types.h>
#endif

#expand sys/ns_ipc.h

extern "C" {
	void addopt(short *, short, short, short, short *, short *);
	void initopt(short *, short, short *);
	void ipcconnect(ns_int_t, ns_int_t, ns_int_t *, short *, ns_int_t *, ns_int_t *);
	int ipccontrol(ns_int_t, ns_int_t, char *, ns_int_t, char *, ns_int_t *, ns_int_t *, ns_int_t *);
	void ipccreate(ns_int_t, ns_int_t, ns_int_t *, short *, ns_int_t *, ns_int_t *);
	void ipcdest(ns_int_t, char *, ns_int_t, ns_int_t, short *, ns_int_t, ns_int_t *, short *, ns_int_t *, ns_int_t *);
	void ipclookup(char *, ns_int_t, char *, ns_int_t, ns_int_t *, ns_int_t *, ns_int_t *, ns_int_t *, ns_int_t *);
	void ipcname(ns_int_t, char *, ns_int_t, ns_int_t *);
	void ipcnamerase(char *, ns_int_t, ns_int_t *);
	void ipcrecv(ns_int_t, char *, ns_int_t *, ns_int_t *, short *, ns_int_t *);
	void ipcrecvcn(ns_int_t, ns_int_t *, ns_int_t *, short *, ns_int_t *);
	void ipcselect(ns_int_t *, int *, int *, int *, ns_int_t, ns_int_t *);
	void ipcsend(ns_int_t, char *, ns_int_t, ns_int_t *, short *, ns_int_t *);
	void ipcshutdown(ns_int_t, ns_int_t *, short *, ns_int_t *);
	int optoverhead(short, short *);
	void readopt(short *, ns_int_t, short *, short *, short *, short *);
}

#endif
