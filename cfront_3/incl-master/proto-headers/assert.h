/*ident	"@(#)cls4:incl-master/proto-headers/assert.h	1.1" */
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
#usedby all
/* This header file intentionally has no wrapper, since the user
*  may want to re-include it to turn off/on assertions for only
*  a portion of the source file.
*/


#ifdef assert
#undef assert
#endif
#ifdef _assert
#undef _assert
#endif

#ifdef NDEBUG

#define assert(e) ((void)0)

#else

#ifndef __STDIO_H
#include <stdio.h>
#endif

#ifndef __STDLIB_H
#include <stdlib.h>
#endif

#if defined(__STDC__)
#define assert(EX) (void)((EX) || (fprintf(stderr,"Assertion failed: " # EX ", file \"%s\", line %d\n", __FILE__, __LINE__), abort(), 0))
#else
#define assert(EX) (void)((EX) || (fprintf(stderr,"Assertion failed: EX file \"%s\", line %d\n", __FILE__, __LINE__), abort(), 0))
#endif
#endif

#define _assert(e) assert(e)

