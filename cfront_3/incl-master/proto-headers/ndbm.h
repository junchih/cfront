/*ident	"@(#)cls4:incl-master/proto-headers/ndbm.h	1.1" */
#usedby bsd3 sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0

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
#ifndef __NDBM_H
#define __NDBM_H

#hide dbm_open
#hide dbm_close
#hide dbm_fetch
#hide dbm_firstkey
#hide dbm_nextkey
#hide dbm_forder
#hide dbm_delete
#hide dbm_store

#expand ndbm.h

extern "C" {
	DBM	*dbm_open(const char*, int, int);
	long	dbm_forder(DBM*, datum);
	int	dbm_store(DBM*, datum, datum, int);
	int	dbm_delete(DBM*, datum);
	int	dbm_close(DBM*);
	datum	dbm_firstkey(DBM*);
	datum	dbm_nextkey(DBM*);
	datum	dbm_fetch(DBM*, datum);
#os hpux hpux8.0
	int	dbm_clearerr(DBM*);
	int	dbm_error(DBM*);
#endos
}

#endif
