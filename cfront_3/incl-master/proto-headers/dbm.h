/*ident	"@(#)cls4:incl-master/proto-headers/dbm.h	1.1" */
#usedby bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant

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
#ifndef __DBM_H
#define __DBM_H

#hide fetch
#hide makdatum
#hide firstkey
#hide nextkey
#hide firsthash
#hide calchash
#hide hashinc

#expand dbm.h


extern "C" {
	datum	firstkey();
	datum	nextkey(datum);
	datum	fetch(datum);
	datum	makdatum();
	datum	firsthash();
	long	calchash();
	long	hashinc();
#os bsd2 sunos3 sunos4 sunos4.1 alliant
        int     dbmclose();
#endos
        int     dbminit(char*);
        int     store(datum, datum);

/* "delete" is a C++ keyword, so the following function can't be called
* from within C++.
* 		delete(datum);
*/
}

#endif
