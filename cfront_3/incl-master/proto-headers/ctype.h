/*ident	"@(#)cls4:incl-master/proto-headers/ctype.h	1.1" */
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
#ifndef __CTYPE_H
#define __CTYPE_H

#os svr2 svr3 sgi
#hide tolower
#hide toupper
#endos

#os svr4 sgi-svr4 solaris
#ifdef __STDC__
extern "C" {
#endif
#endos

#expand ctype.h

#os svr4 sgi-svr4 solaris
#ifdef __STDC__
}
#endif
#endos

#os hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts sunos4.1 svr4 sgi-svr4 solaris
extern "C" {
#endos
#os hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts sunos4.1
	int toupper(int);
	int tolower(int);
#endos
#os hpux2.0 hpux hpux8.0
	int nl_toupper(int, int);
	int nl_tolower(int, int);
#endos
#os svr4 sgi-svr4 solaris
#ifndef isalnum
	 int isalnum(int);
#endif
#ifndef isalpha
	 int isalpha(int);
#endif
#ifndef iscntrl
	 int iscntrl(int);
#endif
#ifndef isdigit
	 int isdigit(int);
#endif
#ifndef isgraph
	 int isgraph(int);
#endif
#ifndef islower
	 int islower(int);
#endif
#ifndef isprint
	 int isprint(int);
#endif
#ifndef ispunct
	 int ispunct(int);
#endif
#ifndef isspace
	 int isspace(int);
#endif
#ifndef isupper
	 int isupper(int);
#endif
#ifndef isxdigit
	 int isxdigit(int);
#endif
#ifndef tolower
	 int tolower(int);
#endif
#ifndef toupper
	 int toupper(int);
#endif
#ifndef isascii
	 int isascii(int);
#endif
#ifndef toascii
	 int toascii(int);
#endif
#ifndef _tolower
	 int _tolower(int);
#endif
#ifndef	 _toupper
	int _toupper(int);
#endif
#endos
#os hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts sunos4.1 svr4 sgi-svr4 solaris
}
#endos

#endif
