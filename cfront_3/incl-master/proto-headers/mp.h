/*ident	"@(#)cls4:incl-master/proto-headers/mp.h	1.1" */
#usedby sunos3 sunos4 sunos4.1 alliant

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
#ifndef __MP_H
#define __MP_H

#hide itom
#hide xtom
#hide mtox
#hide xalloc
#hide mfree

#expand mp.h


extern "C" {
	int 	madd(MINT*, MINT*, MINT*),
		msub(MINT*, MINT*, MINT*),	
		mult(MINT*, MINT*, MINT*),
		mdiv(MINT*, MINT*, MINT*, MINT*),
		min(MINT*),
		mout(MINT*),
		pow(MINT*, MINT*, MINT*, MINT*),
		gcd(MINT*, MINT*, MINT*),
		rpow(MINT*, short, MINT*),
		msqrt(MINT*, MINT*, MINT*),
		sdiv(MINT*, short, MINT*, short*);
	MINT	*itom(short);
#os sunos3 sunos4 sunos4.1
	void	mfree(MINT*);				
	char	*mtox(MINT*);
	MINT	*xtom(char*);
#endos

	/* Can't find the prototype for xalloc.  Sorry. 
	*/
}

#endif
