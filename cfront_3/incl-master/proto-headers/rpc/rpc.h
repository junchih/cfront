/*ident	"@(#)cls4:incl-master/proto-headers/rpc/rpc.h	1.1" */
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
#ifndef __RPC_H
#define __RPC_H

#hide authdes_create
#hide authnone_create
#hide authdes_getucred
#hide callrpc
#hide clnt_broadcast
#hide eachresult
#hide clnt_create
#hide clnt_pcreateerror
#hide clnt_perrno
#hide clnt_perror
#hide clnt_spcreateerror
#hide clnt_sperrno
#hide clnt_sperror
#hide clntraw_create
#hide clnttcp_create
#hide clntudp_bufcreate
#hide clntudp_create
#hide get_myaddress
#hide getnetname
#hide host2netname
#hide key_decryptsession
#hide key_encryptsession
#hide key_gendes
#hide key_setsecret
#hide netname2host
#hide netname2user
#hide pmap_getmaps
#hide pmap_getport
#hide pmap_rmtcall
#hide pmap_set
#hide pmap_unset
#hide registerrpc
#hide svc_getreq
#hide svc_getreqset
#hide svc_register
#hide svc_sendreply
#hide svc_unregister
#hide svcerr_auth
#hide svcerr_decode
#hide svcerr_noproc
#hide svcerr_noprog
#hide svcerr_progvers 
#hide svcerr_systemerr
#hide svcerr_weakauth
#hide svcfd_create
#hide svcraw_create
#hide svctcp_create
#hide user2netname
#hide xdr_accepted_reply
#hide xdr_callhdr
#hide xdr_callmsg
#hide xdr_opaque_auth
#hide xdr_pmap
#hide xdr_pmaplist
#hide xdr_rejected_reply
#hide xdr_replymsg
#hide xprt_register
#hide xprt_unregister

#expand rpc/rpc.h

extern "C" {
     AUTH * authdes_create(char *name, unsigned window, 
	struct sockaddr_in *syncaddr, des_block ckey);
     AUTH * authnone_create();
     int authdes_getucred(struct authdes_cred *adc, short uid, short gid,
	 short grouplen, int groups);
     int callrpc(char *host, u_long prognum, u_long versnum, u_long procnum, 
	xdrproc_t inproc, char *in, xdrproc_t outproc, char *out);
     clnt_broadcast(u_long prognum, u_long versnum, u_long procnum, 
	xdrproc_t inproc, char *in, xdrproc_t outproc, char *out, ...);
     eachresult(char *out, struct sockaddr_in addr);
     CLIENT * clnt_create(const char *host,const u_long prog, const u_long vers,
	 const char *proto);
     void clnt_pcreateerror(const char *s);
     void clnt_perrno(const enum clnt_stat stat);
     clnt_perror(const CLIENT clnt, const char *s);
     char *clnt_spcreateerror(const char *s);
     char *clnt_sperrno(const enum clnt_stat stat);
     char *clnt_sperror(const CLIENT *rpch, const char *s);
     CLIENT *clntraw_create(const u_long prognum, const u_long versnum);
     CLIENT * clnttcp_create(struct sockaddr_in *addr, u_long prognum, u_long 
	versnum, int *sockp, u_int sendsz, u_int recvsz);
     CLIENT * clntudp_bufcreate(struct sockaddr_in *addr, u_long prognum, u_long
	versnum, struct timeval wait, int *sockp, unsigned int sendsize, 
	unsigned int recosize);
     CLIENT *clntudp_create(struct sockaddr_in *addr, u_long prognum, u_long 
	versnum, struct timeval wait, int *sockp);
     void get_myaddress(struct sockaddr_in *addr);
     void getnetname(char *name);
     host2netname(char *name, char *host, char *domain);
     key_decryptsession(char *remotename, des_block *deskey);
     key_encryptsession(char *remotename, des_block *deskey);
     int key_gendes(des_block *deskey);
     int key_setsecret(char *key);
     int netname2host(char *name, char *host, int hostlen);
     int netname2user(char *name, int *uidp, int *gidp, int *gidlenp, 
	int *gidlist);
     struct pmaplist *pmap_getmaps(struct sockaddr_in *addr);
     u_short pmap_getport(struct sockaddr_in *addr, u_long prognum, u_long 
	versnum, u_long protocol);
     enum clnt_stat pmap_rmtcall(struct sockaddr_in *addr, u_long prognum, 
	u_long versnum, u_long procnum, xdrproc_t inproc, char *in, 
	xdrproc_t outproc, char *out, struct timeval tout, u_long *portp);
     int pmap_set(u_long prognum, u_long versnum, int protocol, u_short port);
     int pmap_unset(u_long prognum, u_long versnum);
     int registerrpc(u_long prognum, u_long versnum, u_long procnum, 
	void *(*procname)(void*), xdrproc_t inproc, xdrproc_t outproc);
     void svc_getreq(int rdfds);
     void svc_getreqset(fd_set *rdfds);
     int svc_register(const SVCXPRT *xprt, const u_long prognum, const 
	u_long versnum, const void (*dispatch), const u_long protocol);
     int svc_sendreply(const SVCXPRT *xprt, const xdrproc_t outproc, 
	const char *out);
     void svc_unregister(const u_long prognum, const u_long versnum);
     void svcerr_auth(const SVCXPRT *xprt, const enum auth_stat why);
     void svcerr_decode(const SVCXPRT *xprt);
     void svcerr_noproc(const SVCXPRT *xprt);
     void svcerr_noprog(const SVCXPRT *xprt);
     void svcerr_progvers(const SVCXPRT *xprt);
     void svcerr_systemerr(const SVCXPRT *xprt);
     void svcerr_weakauth(const SVCXPRT *xprt);
     SVCXPRT *svcfd_create(const int fd, const u_int sendsize, const u_int recvsize);
     SVCXPRT * svcraw_create();
     SVCXPRT * svctcp_create(int sock, u_int send_buf_size, u_int recv_buf_size);
     user2netname(char *name, int uid, char *domain);
     bool_t xdr_accepted_reply(XDR *xdrs, const struct accepted_reply *ar);
     void xdr_callhdr(XDR *xdrs, const struct rpc_msg chdr);
     bool_t xdr_callmsg(XDR *xdrs, const struct rpc_msg *cmsg);
     bool_t xdr_opaque_auth(XDR *xdrs, const struct opaque_auth *ap);
     bool_t xdr_pmap(XDR *xdrs, struct pmap *regs);
     bool_t xdr_pmaplist(XDR *xdrs, struct pmaplist **rp);
     xdr_rejected_reply(XDR *xdrs, struct rejected_reply *rr);
     xdr_replymsg(XDR *xdrs, struct rpc_msg *rmsg);
     void xprt_register(SVCXPRT *xprt);
     void xprt_unregister(SVCXPRT *xprt);
}

#endif
