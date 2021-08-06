/*ident	"@(#)cls4:incl-master/proto-headers/alloca.h	1.1" */
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
#usedby sunos4 sunos4.1
#ifndef __ALLOCA_H
#define __ALLOCA_H

#expand alloca.h
extern "C" {
	char *__builtin_alloca(int);
}
#endif
