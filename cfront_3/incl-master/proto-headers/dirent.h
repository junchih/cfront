/*ident	"@(#)cls4:incl-master/proto-headers/dirent.h	1.1" */
#usedby sunos4 sunos4.1 svr3 sgi uts hpux hpux8.0 svr4 sgi-svr4 solaris

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
#ifndef __DIRENT_H
#define __DIRENT_H

#hide opendir
#hide readdir
#hide telldir
#hide seekdir
#os svr4 sgi-svr4 solaris
#hide rewinddir
#endos
#hide closedir

#expand dirent.h

extern "C" {
	DIR *opendir(const char*);
	struct dirent *readdir(DIR*);
#os svr4 sgi-svr4 solaris
	long telldir(const DIR*);
	void seekdir(DIR*, long);
	void rewinddir(DIR*);
#endos
	void closedir(DIR*);
#os sunos4 sunos4.1 svr3 sgi uts hpux hpux8.0
	long telldir(const DIR*);
	void seekdir(DIR*, long);
#ifndef rewinddir
	void rewinddir(DIR*);
#endif
#endos
}

#endif
