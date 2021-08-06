/*ident	"@(#)cls4:incl-master/proto-headers/plot.h	1.1" */
#usedby svr2 svr3 sgi uts

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
#ifndef __PLOT_H
#define __PLOT_H

#os 
#hide arc
#hide circle
#hide closepl
#hide cont
#hide erase
#hide label
#hide line
#hide linemod
#hide move
#hide openpl
#hide point
#hide space

#expand plot.h
#endos

extern "C" {
	int openpl ();
	int erase ();
	int label (const char*);
	int line (int, int, int, int);
	int circle (int, int, int);
	int arc (int, int, int, int, int, int);
	int move (int, int);
	int cont (int, int);
	int point (int, int);
	int linemod (const char*);
	int space (int, int, int, int);
	int closepl ();
}

#endif
