/*ident	"@(#)cls4:incl-master/proto-headers/ieeefp.h	1.1" */
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
#ifndef __IEEEFP_H
#define __IEEEFP_H

#hide fpclass
#hide finite
#hide unordered
#hide fpsetround
#hide fpgetround
#hide fpsetmask
#hide fpgetmask
#hide fpsetsticky
#hide fpgetsticky
#hide isnanf
#hide isnand
#hide _getflthw
#hide _getfltsw
#hide _s2dec
#hide _d2dec
#hide _dec2s
#hide _dec2d

#expand ieeefp.h

extern "C" {
	fpclass_t fpclass(double);        /* get class of double value */
#if defined(__STDC__)
	int       finite( double );
	int       unordered( double, double );
	int isnanf(float);
#endif
	fp_rnd    fpsetround(fp_rnd);     /* set rounding mode, return previous */
	fp_rnd    fpgetround(void);       /* return current rounding mode */
	fp_except fpgetmask(void);        /* current exception mask */
	fp_except fpsetmask(fp_except);   /* set mask, return previous */
	fp_except fpgetsticky(void);      /* return logged exceptions */
	fp_except fpsetsticky(fp_except); /* change logged exceptions */
	int isnand(double);

	void     _getflthw(int *, int (*)());
	fp_union _getfltsw(fp_ftype,fp_op,char *,fp_union *,fp_union *,fp_union *
);
	*_p754_1 = _getflthw;
	*_p754_2 = _getfltsw;

	void _s2dec(float *, decimal *, int);
	void _d2dec(double *, decimal *, int);
	void _dec2s(decimal *, float *, int);
	void _dec2d(decimal *, double *, int);
}

#endif
