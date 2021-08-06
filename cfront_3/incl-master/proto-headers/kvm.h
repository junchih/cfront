/*ident	"@(#)cls4:incl-master/proto-headers/kvm.h	1.1" */
#usedby sunos4 sunos4.1

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
#ifndef __KVM_H
#define __KVM_H

#hide kvm_open
#hide kvm_close
#hide kvm_nlist
#hide kvm_read
#hide kvm_write
#hide kvm_getproc
#hide kvm_nextproc
#hide kvm_setproc
#hide kvm_getu
#hide kvm_getcmd

#expand kvm.h

extern "C" {
	kvm_t            *kvm_open(char*, char*, char*, int, char*);
	int               kvm_close(kvm_t*);
	int               kvm_nlist(kvm_t*, struct nlist*);
	int               kvm_read(kvm_t*, unsigned long, char*, unsigned);
	int               kvm_write(kvm_t*, unsigned long, char*, unsigned);
	struct proc      *kvm_getproc(kvm_t*, int);
	struct proc      *kvm_nextproc(kvm_t*);
	int               kvm_setproc(kvm_t*);
	struct user      *kvm_getu(kvm_t*, struct proc*);
	int               kvm_getcmd(kvm_t*, struct proc*, struct user*, char***, char***);
}

#endif
