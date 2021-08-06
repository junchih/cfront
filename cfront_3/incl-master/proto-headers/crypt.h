/*ident	"@(#)cls4:incl-master/proto-headers/crypt.h	1.1" */
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
#usedby svr4 sgi-svr4 solaris
#ifndef __CRYPT_H
#define __CRYPT_H

extern "C" {
	char	*crypt(const char *, const char *);
	int	crypt_close(int *);
	char	*des_crypt(const char *, const char *);
	void	des_encrypt(char *, int);
	void	des_setkey(const char *);
	void	encrypt(char *, int);
	int	run_crypt(long, char *, unsigned, int *);
	int	run_setkey(int *, const char *);
	void	setkey(const char *);
}

#endif
