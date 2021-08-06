/*ident	"@(#)cls4:incl-master/proto-headers/fstab.h	1.1" */
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
#ifndef __FSTAB_H
#define __FSTAB_H

#hide getfsent
#hide getfsspec
#hide getfsfile
#hide getfstype
#hide endfsent
#hide setfsent

#expand fstab.h

extern "C" {
	struct  fstab *getfsent();
	struct  fstab *getfsspec(const char*);
	struct  fstab *getfsfile(const char*);
	struct  fstab *getfstype(const char*);
	int     setfsent(), endfsent();
}

#endif
