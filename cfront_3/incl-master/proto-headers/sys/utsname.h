/*ident	"@(#)cls4:incl-master/proto-headers/sys/utsname.h	1.1" */
#usedby hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts svr4 sgi-svr4 solaris

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
#ifndef __UTSNAME_H
#define __UTSNAME_H

#os svr4
extern "C" {
	int nuname(struct utsname *);
}
#endos

#os hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts solaris sgi-svr4
#hide uname
#endos

#expand sys/utsname.h

#os hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts solaris sgi-svr4
extern "C" {
	int uname(struct utsname *);
}
#endos
#os svr4
static inline int uname (struct utsname *buf)
{
        int ret;
         
        ret = nuname(buf);
        return ret;
} 
#endos
#endif
