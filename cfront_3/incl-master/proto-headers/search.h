/*ident	"@(#)cls4:incl-master/proto-headers/search.h	1.1" */
#usedby sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts svr4 sgi-svr4 solaris

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
#ifndef __SEARCH_H
#define __SEARCH_H

#hide bsearch
#hide hcreate
#hide hdestroy
#hide hsearch
#hide lfind
#hide lsearch
#hide tdelete
#hide tfind
#hide tsearch
#hide twalk
#os svr4 sgi-svr4 solaris
#hide insque
#hide remque
#endos

#expand search.h

extern "C" {
    /* BSEARCH(3C) */
#os sunos3 sunos4 sunos4.1 hpux2.0 svr2 svr3 sgi uts
	void *bsearch(const void *, void *, unsigned, unsigned, int(*)(const void *, const void *));
#endos
#os hpux
	void *bsearch(const void *, void *, size_t, size_t, int(*)(const void *, const void *));
#endos
#os hpux8.0
	void *bsearch(const void *, const void *, size_t, size_t, int(*)(const void *, const void *));
#endos
#os svr4 sgi-svr4 solaris
	void *bsearch(const void *, const void *, size_t, size_t,
	    		int (*)(const void *, const void *));
	void insque(struct qelem *, struct qelem *);
	void remque(struct qelem *);
#endos

    /* HSEARCH(3C) */
	ENTRY *hsearch(ENTRY, ACTION);
#os sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts
	int hcreate(unsigned);
	void hdestroy();
#endos
#os svr4 sgi-svr4 solaris
	int hcreate(size_t);
	void hdestroy(void);
#endos

    /* TSEARCH(3C) */
	void *tsearch(const void*, void**, int(*)(const void *, const void *));
#os sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts
	void *tfind(const void*, void**, int(*)(const void *, const void *));
#endos
#os svr4 sgi-svr4 solaris
	void *tfind(const void *, void *const *, int (*)(const void *, const void *));
#endos
	void *tdelete(const void*, void**, int(*)(const void *, const void *));
	void twalk(void*,void (*)(void *, VISIT, int));

    /* LSEARCH(3C) */
#os sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts
	void *lsearch(const void *, void *, unsigned *, unsigned, int(*)(const void *, const void *));
	void *lfind(const void *, void *, unsigned *, unsigned, int(*)(const void *, const void *));
#endos
#os svr4 sgi-svr4 solaris
	void *lsearch(const void *, void *, size_t *, size_t, int(*)(const void *, const void *));
	void *lfind(const void *, const void *, size_t *, size_t, 
	    		int (*)(const void *, const void *));
#endos
}

#endif
