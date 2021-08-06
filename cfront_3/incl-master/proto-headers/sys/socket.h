/*ident	"@(#)cls4:incl-master/proto-headers/sys/socket.h	1.1" */
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
#ifndef __SOCKET_H
#define __SOCKET_H

#hide accept
#hide bind
#hide connect
#hide getpeername
#hide getsockname
#hide getsockopt
#hide listen
#hide recv
#hide recvfrom
#hide send
#hide sendto
#hide setsockopt
#hide socket

#os svr4 sgi-svr4 solaris
#hide gethostent
#hide gethostbyaddr
#hide gethostbyname
#hide recvmsg
#hide sendmsg
#hide shutdown
#hide socketpair
#endos

#os bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant
#hide recvmsg
#hide sendmsg
#hide socketpair
#endos

#expand sys/socket.h

extern "C" {
	int accept(int, struct sockaddr *, int *);
	int bind(int, const struct sockaddr *, int);
	int connect(int, const struct sockaddr *, int);
	int getpeername(int, struct sockaddr *, int *);
	int getsockname(int, struct sockaddr *, int *);
	int getsockopt(int, int, int, char *, int *);
	int listen(int, int);
	int recv(int, char *, int, int);
	int recvfrom(int, char *, int, int, struct sockaddr *, int *);
	int send(int, const char *, int, int);
	int sendto(int, const char *, int, int, const struct sockaddr *, int);
	int setsockopt(int, int, int, const char *, int);
	int socket(int, int, int);
#os svr4 solaris
        struct hostent*        gethostbyname(char*);
        struct hostent*        gethostbyaddr(char*, int, int);
#endos
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant hpux2.0 hpux hpux8.0
        struct hostent*        gethostbyname(const char*);
        struct hostent*        gethostbyaddr(const char*, int, int);
#endos

#os svr4 sgi-svr4 solaris
	struct hostent * gethostent();
	int recvmsg(int, struct msghdr*, int);
	int sendmsg(int, struct msghdr*, int);
	int shutdown(int, int);
	int socketpair(int, int, int, int[]);
#endos
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant
	int recvmsg(int, struct msghdr *, int);
	int sendmsg(int, struct msghdr *, int);
	int socketpair(int, int, int, int *);
#endos
}

#endif
