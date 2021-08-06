/*ident	"@(#)cls4:incl-master/proto-headers/netdir.h	1.1" */
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

#ifndef __NETDIR_H
#define __NETDIR_H

#hide netdir_options
#hide netdir_getbyname
#hide netdir_getbyaddr
#hide netdir_mergeaddr
#hide netdir_free
#hide uaddr2taddr
#hide netdir_perror
#hide netdir_sperror
#hide taddr2uaddr
#hide _netdir_getbyname
#hide _netdir_getbyaddr
#hide _netdir_mergeaddr
#hide _uaddr2taddr
#hide _taddr2uaddr

#expand netdir.h

extern "C" {
	int netdir_options(struct netconfig *, int, int, char *);
	int netdir_getbyname(struct netconfig *, struct nd_hostserv *, struct nd_addrlist **);
	int netdir_getbyaddr(struct netconfig *, struct nd_hostservlist **, struct netbuf *);
	void netdir_free(char *, int);
	struct netbuf *uaddr2taddr(struct netconfig *, char *);
	char *taddr2uaddr(struct netconfig *, struct netbuf *);
	void netdir_perror(char *);
	char *netdir_sperror();
	struct nd_addrlist *_netdir_getbyname(struct netconfig *, struct nd_hostserv *);
	struct nd_hostservlist *_netdir_getbyaddr(struct netconfig *, struct netbuf *);
	struct netbuf *_uaddr2taddr(struct netconfig *, char *);
	char *_taddr2uaddr(struct netconfig *, struct netbuf *);
}

#endif /* __NETDIR_H */
