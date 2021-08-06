/*ident	"@(#)cls4:incl-master/proto-headers/shadow.h	1.1" */
#usedby svr4 solaris sgi-svr4

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
#ifndef __SHADOW_H
#define __SHADOW_H

#hide setspent
#hide endspent
#hide getspent
#hide fgetspent
#hide getspnam
#hide putspent
#hide lckpwdf
#hide ulckpwdf

#expand shadow.h


extern "C" {
	void	    setspent(void),
	    	    endspent(void);
	struct spwd *getspent(void),
		    *fgetspent(FILE *),
		    *getspnam(const char *);
	int	    putspent(const struct spwd *, FILE *),
	   	    lckpwdf(void),
	   	    ulckpwdf(void);
}

#endif
