/*ident	"@(#)cls4:incl-master/proto-headers/sys/dir.h	1.1" */
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
#ifndef __DIR_H
#define __DIR_H

#hide opendir
#hide readdir
#hide telldir
#hide seekdir
#hide closedir

#expand sys/dir.h

extern "C" {
	DIR* opendir(const char*);
	struct direct* readdir(DIR*);
	long telldir(const DIR*);
	void seekdir(DIR*, long);
#ifndef rewinddir
	void rewinddir(DIR*);
#endif
	void closedir(DIR*);
}

#endif

