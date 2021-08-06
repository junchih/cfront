/*ident	"@(#)cls4:incl-master/proto-headers/sys/types.h	1.1" */
#usedby all

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
#ifndef __TYPES_H
#define __TYPES_H

#os alliant
typedef long time_t;	/* Native include makes this int */
#hide time_t
#endos

#os uts
#ifdef LONGLONG
#undef LONGLONG
#endif
#endos

#os svr2 svr3 sgi bsd2 bsd3 hpux2.0 uts sunos3 sunos4 sunos4.1 alliant pyramid
/* For C++, size_t is defined in stddef.h
*/
#old_hide size_t	
#endos

#expand sys/types.h

#os sunos4 sunos4.1
extern "C" {
	void bzero(void*, int);
}
#endos

#os svr4 sgi-svr4 solaris
#ifdef const
#undef const
#endif

#ifdef volatile
#undef volatile
#endif
#endos

#endif

