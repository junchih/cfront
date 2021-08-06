/*ident	"@(#)cls4:Munch/_main.c	1.3" */
/*******************************************************************************
 
C++ source for the C++ Language System, Release 3.0.  This product
is a new release of the original cfront developed in the computer
science research center of AT&T Bell Laboratories.

Copyright (c) 1993  UNIX System Laboratories, Inc.
Copyright (c) 1991, 1992 AT&T and UNIX System Laboratories, Inc.
Copyright (c) 1984, 1989, 1990 AT&T.  All Rights Reserved.

THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE of AT&T and UNIX System
Laboratories, Inc.  The copyright notice above does not evidence
any actual or intended publication of such source code.

*******************************************************************************/
extern "C" {
extern void _main();
}

extern void _main()
{
	typedef void (*PFV)();
	extern PFV _ctors[];
	for (PFV* pf=_ctors; *pf; pf++) {
		(**pf)();
		*pf = 0; // permits main to be called recursively
	}
}
