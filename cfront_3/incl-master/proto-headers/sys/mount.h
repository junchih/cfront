/*ident	"@(#)cls4:incl-master/proto-headers/sys/mount.h	1.1" */
#usedby hpux2.0 hpux hpux8.0 svr4 sgi-svr4 solaris

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
#ifndef __MOUNT_H
#define __MOUNT_H

#ifndef __TYPES_H
#include <sys/types.h>
#endif
#os svr4 sgi-svr4 solaris
#hide mount
#hide umount
#endos

#expand sys/mount.h

extern "C" {
#os hpux hpux8.0 hpux2.1
	int vfsmount(int, char *, int, caddr_t);
#endos
#os svr4 sgi-svr4 solaris
	int mount(const char*, const char *, int, ...);
	int umount(const char*);
#endos
}
#endif
