/*ident	"@(#)cls4:incl-master/proto-headers/sys/sd.h	1.1" */
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
#ifndef __SYS_SD_H
#define __SYS_SD_H

#hide sdget
#hide sdenter
#hide sdleave
#hide sdfree
#hide sdgetv
#hide sdwaitv

#expand sys/sd.h

extern "C" {
	char *sdget(char *path, int flags, ...);
	int sdenter(char *addr, int flags);
	int sdleave(char *addr);
	int sdfree(char *addr);
	int sdgetv(char *addr);
	int sdwaitv(char *addr, int vnum);
}

#endif
