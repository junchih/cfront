/*ident	"@(#)cls4:incl-master/proto-headers/sys/reboot.h	1.1" */
#usedby bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant hpux2.0 hpux hpux8.0

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
#ifndef __REBOOT_H
#define __REBOOT_H

#hide reboot

#expand sys/reboot.h

extern "C" {
#os bsd2 bsd3 sunos3 alliant
	int reboot(int);
#endos
#os sunos4 sunos4.1
	int reboot(int, const char *bootargs=0);
#endos
}

#endif
