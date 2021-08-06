/*ident	"@(#)cls4:incl-master/proto-headers/mon.h	1.1" */
#usedby sunos3 sunos4 sunos4.1 hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts svr4 sgi-svr4 solaris

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
#ifndef __MON_H
#define __MON_H

#os hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts svr4 sgi-svr4 solaris
#hide monitor
#expand mon.h
#endos

extern "C" {
#os hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts svr4 sgi-svr4 solaris
	void monitor(int (*)(), int(*)(), WORD *, int, int);
#endos
#os sunos3 sunos4 sunos4.1 alliant
	void monitor(int (*)(), int(*)(), short *, int, int);
	void monstartup(int (*)(), int (*)());
	void moncontrol(int);
#endos
}
#endif
