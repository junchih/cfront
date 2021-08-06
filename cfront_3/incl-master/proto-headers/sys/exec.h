/*ident	"@(#)cls4:incl-master/proto-headers/sys/exec.h	1.1" */
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
#ifndef __SYS_EXEC_H
#define __SYS_EXEC_H

#hide exhd_getmap
#hide exhd_release
#hide remove_proc
#hide execmap
#hide setexecenv
#hide setregs
#hide core_seg
#hide gexec
#hide execstk_addr
#hide execpermissions

#expand sys/exec.h

extern "C" {
	int exhd_getmap(exhda_t *, off_t, int, int, char *);
	void exhd_release(exhda_t *);
	int remove_proc(struct uarg *);
	int execmap(vnode_t *, caddr_t, size_t, size_t, off_t, int);
	void setexecenv(struct execenv *);
	int setregs(struct uarg *);
	int core_seg(proc_t *, vnode_t *, off_t, caddr_t, size_t, rlim_t, cred_t *);
	int gexec(vnode_t **, struct uarg *, int, long *);
	caddr_t execstk_addr(int, u_int *);
	int execpermissions(struct vnode *, struct vattr *, exhda_t *, struct uarg *);
}

#endif
