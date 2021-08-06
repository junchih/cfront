/*ident	"@(#)cls4:incl-master/proto-headers/ldfcn.h	1.1" */
#usedby svr2 svr3 sgi uts svr4 sgi-svr4

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
#ifndef __LDFCN_H
#define __LDFCN_H

#hide ftell
#hide fgets
#hide ldopen
#hide ldaopen
#hide ldaclose
#hide ldahread
#hide ldclose
#hide ldfhread
#hide ldlinit
#hide ldlitem
#hide ldlread
#hide ldlseek
#hide ldnlseek
#hide ldnrseek
#hide ldnshread
#hide ldnsseek
#hide ldohseek
#hide ldrseek
#hide ldshread
#hide ldsseek
#hide ldtbread
#hide ldtbseek
#hide ldtbindex
#hide ldgetname
#hide sgetl
#hide sputl

#ifndef FILHDR
#       include <filehdr.h>
#endif
#ifndef __STDIO_H
#       include <stdio.h>
#endif

#expand ldfcn.h

#ifndef SYMENT
#	include <syms.h>
#endif
#ifndef LINENO
#	include <linenum.h>
#endif
#ifndef SCNHDR
#	include <scnhdr.h>
#endif

extern "C" {
	LDFILE *ldaopen(const char*, LDFILE*);
	long ldtbindex(LDFILE*);
	long sgetl(const char*);
	void sputl(long, char*);
#os svr4 sgi-svr4 solaris
	char* ldgetname(LDFILE*, const SYMENT*);
	LDFILE *ldopen(const char*, LDFILE*);
#if defined(__STDC__)
	int ldahread(LDFILE*, ARCHDR*);
	int ldclose(LDFILE*);
	int ldaclose(LDFILE*);
        int ldfhread(LDFILE*, FILHDR*);
	int ldlitem(LDFILE*, unsigned int, LINENO*);
	int ldlread(LDFILE*, long, unsigned int, LINENO*);
	int ldlseek(LDFILE*,unsigned int);
	int ldrseek(LDFILE*, unsigned int);
	int ldshread(LDFILE*, unsigned int, SCNHDR*);
	int ldsseek(LDFILE*, unsigned int);
	int ldlinit(LDFILE*, long);
	int ldnlseek(LDFILE*, const char*);
	int ldohseek(LDFILE*);
	int ldnrseek(LDFILE*, const char*);
	int ldnshread(LDFILE*, const char*, SCNHDR*);
	int ldnsseek(LDFILE*, const char*);
	int ldtbread(LDFILE*, long, SYMENT*);
	int ldtbseek(LDFILE*);
#endif
#endos
#os svr2 svr3 sgi uts
	int ldahread(LDFILE*, ARCHDR*);
	int ldclose(LDFILE*);
	int ldaclose(LDFILE*);
        int ldfhread(LDFILE*, FILHDR*);
	char* ldgetname(LDFILE*, SYMENT*);
	int ldlitem(LDFILE*, unsigned short, LINENO*);
	int ldlread(LDFILE*, long, unsigned short, LINENO*);
	int ldlseek(LDFILE*,unsigned short);
	LDFILE *ldopen(char*, LDFILE*);
	int ldrseek(LDFILE*, unsigned short);
	int ldshread(LDFILE*, unsigned short, SCNHDR*);
	int ldsseek(LDFILE*, unsigned short);
	int ldlinit(LDFILE*, long);
	int ldnlseek(LDFILE*, const char*);
	int ldohseek(LDFILE*);
	int ldnrseek(LDFILE*, const char*);
	int ldnshread(LDFILE*, const char*, SCNHDR*);
	int ldnsseek(LDFILE*, const char*);
	int ldtbread(LDFILE*, long, SYMENT*);
	int ldtbseek(LDFILE*);
#endos
}

#endif
