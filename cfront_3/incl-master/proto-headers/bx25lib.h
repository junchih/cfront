/*ident	"@(#)cls4:incl-master/proto-headers/bx25lib.h	1.1" */
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
#usedby hpux2.0 hpux hpux8.0
#ifndef __BX25LIB_H
#define __BX25LIB_H

#expand bx25lib.h

extern "C" {
extern int sattach(const char *, unsigned, unsigned,
	int (*)(int, int, struct u_params *, struct u_data *));
extern int sdetach(const char *);
extern int sconnect(const char *, const char *, unsigned, unsigned,
	unsigned, unsigned, const char *, unsigned);    
extern int saccept(int, unsigned, unsigned, const char *, unsigned);
extern int srefuse(int, unsigned, const char *, unsigned);
extern int ssend(int, unsigned, const char *, unsigned);
extern int sxsend(int, unsigned *);
extern int sselect(int *, int *, unsigned);
extern int srecv(int, unsigned *, char *, unsigned);
extern int sdisc(int, const char *, unsigned);
extern int sdaccept(int, const char *, unsigned);
extern int sdrefuse(int, const char *, unsigned);
extern int sabort(int, const char *, unsigned);
extern int pdisc(int, unsigned, const char *, unsigned);
extern int x25perror(const char *);
};

#endif
