/*ident	"@(#)cls4:incl-master/proto-headers/sys/kmem.h	1.1" */
#usedby svr4 sgi-svr4 solaris

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
#ifndef __SYS_KMEM_H
#define __SYS_KMEM_H

#hide kmem_init
#hide kmem_alloc
#hide kmem_zalloc
#hide kmem_fast_alloc
#hide kmem_fast_zalloc
#hide kmem_free
#hide kmem_fast_free

#expand sys/kmem.h

extern "C" {
	void kmem_init(void);
	_VOID * kmem_alloc(size_t, int);
	_VOID * kmem_zalloc(size_t, int);
	_VOID * kmem_fast_alloc(caddr_t *, size_t, int, int);
	_VOID * kmem_fast_zalloc(caddr_t *, size_t, int, int);
	void kmem_free(_VOID *, size_t);
	void kmem_fast_free(caddr_t *, caddr_t);
}

#endif
