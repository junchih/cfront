/*ident	"@(#)cls4:incl-master/proto-headers/ufs/quota.h	1.1" */
#usedby sunos3 sunos4 sunos4.1

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
#ifndef __QUOTA_H
#define __QUOTA_H

#ifndef __TYPES_H
#include <sys/types.h>
#endif

#expand ufs/quota.h

extern "C" {
	int quotactl(int cmd, char *special, int uid, caddr_t addr);
}

#endif
