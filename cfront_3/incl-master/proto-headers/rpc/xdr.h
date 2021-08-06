/*ident	"@(#)cls4:incl-master/proto-headers/rpc/xdr.h	1.1" */
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
#ifndef __XDR_H
#define __XDR_H

#hide xdr_bool
#hide xdr_char
#hide xdr_double
#hide xdr_enum
#hide xdr_float
#hide xdr_free
#hide xdr_int
#hide xdr_long
#hide xdr_short
#hide xdr_u_char
#hide xdr_u_int
#hide xdr_u_long
#hide xdr_u_short
#hide xdr_void
#hide xdrrec_endofrecord
#hide xdrrec_eof
#hide xdrrec_readbytes
#hide xdrrec_skiprecord
#hide xdr_array
#hide xdr_bytes
#hide xdr_opaque
#hide xdr_pointer
#hide xdr_reference
#hide xdr_string
#hide xdr_union
#hide xdr_vector
#hide xdr_wrapstring
#hide xdrmem_create
#hide xdrrec_create
#hide xdrstdio_create

#expand rpc/xdr.h

extern "C" {
	bool_t xdr_bool(XDR *, bool_t*);
	bool_t xdr_char(XDR *, char *);
	bool_t xdr_double(XDR *, double *);
	bool_t xdr_enum(XDR *, enum_t *);
	bool_t xdr_float(XDR *, float *);
	void xdr_free(xdrproc_t, char *);
	bool_t xdr_int(XDR *, int *);
	bool_t xdr_long(XDR *, long *);
	bool_t xdr_short(XDR *, short *);
	bool_t xdr_u_char(XDR *, unsigned char *);
	bool_t xdr_u_int(XDR *, unsigned *);
	bool_t xdr_u_long(XDR *, unsigned long *);
	bool_t xdr_u_short(XDR *, unsigned short *);
	bool_t xdr_void();
	bool_t xdrrec_endofrecord(XDR *, int);
	bool_t xdrrec_eof(XDR *);
	int xdrrec_readbytes(XDR *, caddr_t, unsigned int);
	bool_t xdrrec_skiprecord(XDR *);
	bool_t xdr_array(XDR *, char **, unsigned *, unsigned, unsigned, xdrproc_t);
	bool_t xdr_bytes(XDR *, char **, unsigned *, unsigned);
	bool_t xdr_opaque(XDR *, char *, unsigned);
	bool_t xdr_pointer(XDR *, char **, unsigned, xdrproc_t);
	bool_t xdr_reference(XDR *, char **, unsigned, xdrproc_t);
	bool_t xdr_string(XDR *, char **, unsigned);
	bool_t xdr_union(XDR *, int *, char *, xdr_discrim, bool_t (*)());
	bool_t xdr_vector(XDR *, char *, unsigned, unsigned, xdrproc_t);
	bool_t xdr_wrapstring(XDR *, char **);
	void xdrmem_create(XDR *, char *, unsigned, enum xdr_op);
	void xdrrec_create(XDR *, unsigned, unsigned, char *, int (*)(char *, char *, int), int (*)(char *, char *, int));
	void xdrstdio_create(XDR *, FILE *, enum xdr_op);
}
#endif
