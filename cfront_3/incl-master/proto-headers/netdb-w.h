/*ident	"@(#)cls4:incl-master/proto-headers/netdb.h	1.1" */
#usedby bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant hpux2.0 hpux hpux8.0 svr4 sgi-svr4 solaris
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
#ifndef __NETDB_H
#define __NETDB_H

/* this C++ header file includes the function prototypes for the
   Wollongong TCP/IP implementation -- this is standard on some
   (but not all) SVR4 systems.  All NCR machines seem to use the
   Wollongong TCP/IP stuff.
 */

#hide	getrpcent
#hide	gethostbyname
#hide	gethostbyaddr
#hide	gethostent
#hide	sethostent
#hide	endhostent
#hide	getnetbyname
#hide	getnetbyaddr
#hide	getnetent
#hide	setnetent
#hide	endnetent
#hide	getservbyname
#hide	getservbyport
#hide	getservent
#hide	setservent
#hide	endservent
#hide	getprotobyname
#hide	getprotobynumber
#hide	getprotoent
#hide	setprotoent
#hide	endprotoent

/* hide the extra functions declared in the Wollongong version
   of netdb.h */
#hide herror
#hide _gethtbyname
#hide _gethtbyaddr
#hide gethostid
#hide sethostid
#hide gethostname
#hide sethostname
#hide sethostfile
#hide ruserpass
#hide rexec
#hide ruserok
#hide t_rcmd
#hide rcmd
#hide strcasecmp
#hide strncasecmp
#hide tcp_connect
#hide tcp_conport
#hide streams_tty
#hide t_doopt
#os sunos3 sunos4 sunos4.1 alliant hpux2.0 hpux hpux8.0
#hide getrpcbyname
#hide getrpcbynumber
#endos

#expand netdb.h

extern "C" {
#os svr4 solaris
        hostent*        gethostbyname(char*);
        hostent*        gethostbyaddr(char*, int, int);
#endos
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant hpux2.0 hpux hpux8.0 sgi-svr4
        hostent*        gethostbyname(const char*);
        hostent*        gethostbyaddr(const char*, int, int);
#endos
	hostent*	gethostent();
	int		sethostent(int);
	int		endhostent();

	netent*		getnetbyname(const char*);
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant svr4 sgi-svr4 solaris
	netent*		getnetbyaddr(long, int);
#endos
#os hpux2.0 hpux hpux8.0
	netent*		getnetbyaddr(int, int);
#endos
	netent*		getnetent();
	int		setnetent(int);
	int		endnetent();

	servent*	getservbyname(const char*, const char*);
	servent*	getservbyport(int, const char*);
	servent*	getservent();
	int		setservent(int);
	int		endservent();

	protoent*	getprotobyname(const char*);
	protoent*	getprotobynumber(int);
	protoent*	getprotoent();
	int		setprotoent(int);
	int		endprotoent();
#os sunos3 sunos4 sunos4.1 alliant hpux2.0 hpux hpux8.0
	rpcent*		getrpcent();
	rpcent*		getrpcbyname(const char *);
	rpcent*		getrpcbynumber(int);
	int 		setrpcent(int);
	int 		endrpcent();
#endos

/* C++ function prototypes for the extra functions declared
   in the Wollongong version of netdb.h */
	void herror(char *);
	struct hostent *_gethtbyname(char *);
	struct hostent *_gethtbyaddr(char *, int, int);
	int gethostid();
	int sethostid(unsigned long);
	int gethostname(char *, int);
	int sethostname(const char *, int);
	int sethostfile(const char *);
	void ruserpass(char *, char **, char **);
	int rexec(char **, int, char *, char *, char *, int *);
	int ruserok(char *, int, char *, char *);
	int t_rcmd(char **, int, char *, char *, char *, int *);
	int rcmd(char **, int, char *, char *, char *, int *);
	int strcasecmp(unsigned char *, unsigned char *);
	int strncasecmp(unsigned char *, unsigned char *, int);
	int tcp_connect(char *, char *);
	int tcp_conport(char *, unsigned int);
	int streams_tty(int, char *, int);
	int t_doopt(int, int, int, char *, int);
}

#endif
