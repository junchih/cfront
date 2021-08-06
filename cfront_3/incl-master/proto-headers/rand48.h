/*ident	"@(#)cls4:incl-master/proto-headers/rand48.h	1.1" */
#usedby bsd3 sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts svr4 sgi-svr4 solaris

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
#ifndef __RAND48_H
#define __RAND48_H

#os 
#hide drand48
#hide erand48
#hide jrand48
#hide lcong48
#hide lrand48
#hide mrand48
#hide nrand48
#hide seed48
#hide srand48

#expand rand48.h
#endos

extern "C" {
	double drand48();
	double erand48(unsigned short *);
	long jrand48(unsigned short *);
	long lrand48();
	long mrand48();
	long nrand48(unsigned short *);
	void srand48(long);
	void lcong48(unsigned short *);
	unsigned short *seed48(unsigned short *);
}

#endif
