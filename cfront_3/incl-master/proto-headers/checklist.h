/*ident	"@(#)cls4:incl-master/proto-headers/checklist.h	1.1" */
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
#usedby hpux2.0 hpux hpux8.0
#ifndef __CHECKLIST_H
#define __CHECKLIST_H

#hide getfsent
#hide getfsspec
#hide getfsfile
#hide getfstype
#hide setfsent
#hide endfsent

#expand checklist.h


extern "C" {
struct checklist *getfsent();
struct checklist *getfsspec(char *);
struct checklist *getfsfile(char *);
struct checklist *getfstype(char *);
int setfsent();
int endfsent();
}
#endif
