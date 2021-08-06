/*ident	"@(#)cls4:incl-master/proto-headers/nl_ctype.h	1.1" */
#usedby hpux2.0 hpux hpux8.0

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
#ifndef __NL_CTYPE_H
#define __NL_CTYPE_H

#hide idtolang
#hide firstof2
#hide secof2
#hide byte_status

#expand nl_ctype.h

extern "C" {
	char *idtolang(int);
	int firstof2(int);
	int secof2(int);
	int byte_status(int, int);
}

#endif
