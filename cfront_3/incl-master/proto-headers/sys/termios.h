/*ident	"@(#)cls4:incl-master/proto-headers/sys/termios.h	1.1" */
#usedby svr4 solaris

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
#ifndef __SYS_TERMIOS_H
#define __SYS_TERMIOS_H

#hide cfgetospeed
#hide cfsetospeed
#hide cfgetispeed
#hide cfsetispeed
#hide tcgetattr
#hide tcsetattr 
#hide tcsendbreak 
#hide tcdrain
#hide tcflush
#hide tcflow

#expand sys/termios.h

extern "C" {
	speed_t cfgetospeed (const struct termios *);
	int cfsetospeed (struct termios *, speed_t);
	speed_t cfgetispeed (const struct termios *);
	int cfsetispeed (struct termios *, speed_t);
	int tcgetattr (int, struct termios *);
	int tcsetattr (int, int, const struct termios *);
	int tcsendbreak (int, int);
	int tcdrain (int);
	int tcflush (int, int);
	int tcflow (int, int);
}

#endif

