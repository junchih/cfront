/*ident	"@(#)cls4:incl-master/proto-headers/sys/dnlc.h	1.1" */
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
#ifndef __SYS_DNLC_H
#define __SYS_DNLC_H

#hide dnlc_init
#hide dnlc_enter
#hide dnlc_lookup
#hide dnlc_purge
#hide dnlc_purge1
#hide dnlc_purge_vp
#hide dnlc_purge_vfsp
#hide dnlc_remove

#expand sys/dnlc.h

extern "C" {
	void    dnlc_init(void);
	void    dnlc_enter(vnode_t *, char *, vnode_t *, cred_t *);
	vnode_t *dnlc_lookup(vnode_t *, char *, cred_t *);
	void    dnlc_purge(void);
	int     dnlc_purge1(void);
	void    dnlc_purge_vp(vnode_t *);
	int     dnlc_purge_vfsp(vfs_t *, int);
	void    dnlc_remove(vnode_t *, char *);
}

#endif
