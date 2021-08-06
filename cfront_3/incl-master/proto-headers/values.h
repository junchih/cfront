/*ident	"@(#)cls4:incl-master/proto-headers/values.h	1.1" */
#usedby bsd2 bsd3 sunos3 sunos4 alliant pyramid svr4 sgi-svr4 solaris

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
#ifndef __VALUES_H
#define __VALUES_H

#os sunos3 sunos4 pyramid svr4 sgi-svr4 solaris
#undef BITSPERBYTE
#expand values.h
#endos

#os bsd2 bsd3 alliant
#define BITSPERBYTE	8
#define BITS(type)	(BITSPERBYTE * (int)sizeof(type))
/* short, regular and long ints with only the high-order bit turned on */
#define HIBITS	((short)(1 << BITS(short) - 1))
#define HIBITI	(1 << BITS(int) - 1)
#define HIBITL	(1L << BITS(long) - 1)
/* largest short, regular and long int */
#define MAXSHORT	((short)~HIBITS)
#define MAXINT	(~HIBITI)
#define MAXLONG	(~HIBITL)
#endos
#os bsd2 bsd3
#if pdp11 || vax || tahoe
#define MAXDOUBLE	1.701411834604692293e+38
#define MAXFLOAT	((float)1.701411733192644299e+38)
/* The following is kludged because the PDP-11 compilers botch the simple form.
   The kludge causes the constant to be computed at run-time on the PDP-11,
   even though it is still "folded" at compile-time on the VAX. */
#define MINDOUBLE	(0.01 * 2.938735877055718770e-37)
#define MINFLOAT	((float)MINDOUBLE)
#define _IEEE		0
#define _DEXPLEN	8
#define _HIDDENBIT      1
#define DMINEXP	(-DMAXEXP)
#define FMINEXP	(-FMAXEXP)
#endif
#endos
#os alliant
#define MAXDOUBLE	  1.79769313486231470e+308
#define MAXFLOAT        ((float)3.40282346638528860e+38)
#define MINDOUBLE       4.94065645841246544e-324
#define MINFLOAT        ((float)1.40129846432481707e-45)
#define _IEEE           1
#define _DEXPLEN        11
#define _HIDDENBIT      1
#define DMINEXP (-(DMAXEXP + DSIGNIF - _HIDDENBIT - 3))
#define FMINEXP (-(FMAXEXP + FSIGNIF - _HIDDENBIT - 3))
#endos
#os bsd2 bsd3 alliant
#define _LENBASE	1
#define _EXPBASE	(1 << _LENBASE)
#define _FEXPLEN	8
#define DSIGNIF	(BITS(double) - _DEXPLEN + _HIDDENBIT - 1)
#define FSIGNIF	(BITS(float)  - _FEXPLEN + _HIDDENBIT - 1)
#define DMAXPOWTWO	((double)(1L << BITS(long) - 2) * \
				(1L << DSIGNIF - BITS(long) + 1))
#define FMAXPOWTWO	((float)(1L << FSIGNIF - 1))
#define DMAXEXP	((1 << _DEXPLEN - 1) - 1 + _IEEE)
#define FMAXEXP	((1 << _FEXPLEN - 1) - 1 + _IEEE)
#define LN_MAXDOUBLE	(M_LN2 * DMAXEXP)
#define LN_MINDOUBLE	(M_LN2 * (DMINEXP - 1))
#define H_PREC	(DSIGNIF % 2 ? (1L << DSIGNIF/2) * M_SQRT2 : 1L << DSIGNIF/2)
#define X_EPS	(1.0/H_PREC)
#define X_PLOSS	((double)(long)(M_PI * H_PREC))
#define X_TLOSS	(M_PI * DMAXPOWTWO)
#define M_LN2	0.69314718055994530942
#define M_PI	3.14159265358979323846
#define M_SQRT2	1.41421356237309504880
#endos
  
#os pyramid
#if pyr
/* The values of the following constants are defined in
   the values.h header file with the "0d" format -- which
   isn't acceptable to cfront */
#undef MAXDOUBLE
#undef MAXFLOAT
#undef MINDOUBLE
#undef MINFLOAT
#define MAXDOUBLE       1.79769313486231470e+308
#define MAXFLOAT        ((float)3.40282346638528860e+38)
#define MINDOUBLE       4.94065645841246544e-324
#define MINFLOAT        ((float)1.40129846432481707e-45)
#endif
#endos
				
#endif
