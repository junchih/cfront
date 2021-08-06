/*ident	"@(#)cls4:incl-master/proto-headers/sys/vfstab.h	1.1" */
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
#ifndef __SYS_VFSTAB_H
#define __SYS_VFSTAB_H

#hide getvfsent
#hide getvfsspec
#hide getvfsfile
#hide getvfsany

#expand sys/vfstab.h

extern "C" {
	int getvfsent(FILE *, struct vfstab *);
	int getvfsspec(FILE *, struct vfstab *, char *);
	int getvfsfile(FILE *, struct vfstab *, char *);
	int getvfsany(FILE *, struct vfstab *, struct vfstab *);
}

#endif
