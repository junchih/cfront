/*ident	"@(#)cls4:incl-master/proto-headers/tiuser.h	1.1" */
#usedby uts svr3 sgi svr4 solaris

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
#ifndef __TIUSER_H
#define __TIUSER_H

#hide t_accept
#hide t_alloc
#hide t_bind
#hide t_close
#hide t_connect
#hide t_error
#hide t_free
#hide t_getinfo
#hide t_getstate
#hide t_listen
#hide t_look
#hide t_open
#hide t_optmgmt
#hide t_rcv
#hide t_rcvconnect
#hide t_rcvdis
#hide t_rcvrel
#hide t_rcvudata
#hide t_rcvuderr
#hide t_snd
#hide t_snddis
#hide t_sndrel
#hide t_sndudata
#hide t_sync
#hide t_unbind

#expand tiuser.h

extern "C" {
	int t_accept(int, int, struct t_call *);
	char *t_alloc(int, int, int);
	int t_bind(int, struct t_bind *, struct t_bind *);
	int t_close(int);
	int t_connect(int, struct t_call *, struct t_call *);
	void t_error(char *);
	int t_free(char *, int);
	int t_getinfo(int, struct t_info *);
	int t_getstate(int);
	int t_listen(int, struct t_call *);
	int t_look(int);
	int t_open(char *, int, struct t_info *);
	int t_optmgmt(int, struct t_optmgmt *, struct t_optmgmt *);
	int t_rcv(int, char *, unsigned, int *);
	int t_rcvconnect(int, struct t_call *);
	int t_rcvdis(int, struct t_discon *);
	int t_rcvrel(int);
	int t_rcvudata(int, struct t_unitdata *, int *);
	int t_rcvuderr(int, struct t_uderr *);
	int t_snd(int, char *, unsigned, int);
	int t_snddis(int, struct t_call *);
	int t_sndrel(int);
	int t_sndudata(int, struct t_unitdata *);
	int t_sync(int);
	int t_unbind(int);
}

#endif
