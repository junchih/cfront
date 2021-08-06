/*ident	"@(#)cls4:incl-master/proto-headers/sys/inline.h	1.1" */
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
#ifndef __SYS_INLINE_H
#define __SYS_INLINE_H

#hide flushtlb
#hide _cr0
#hide _cr2
#hide _cr3
#hide _wdr0
#hide _wdr1
#hide _wdr2
#hide _wdr3
#hide _wdr6
#hide _wdr7
#hide _dr0
#hide _dr1
#hide _dr2
#hide _dr3
#hide _dr6
#hide _dr7
#hide loadtr
#hide outl
#hide outw
#hide outb
#hide inl
#hide inw
#hide inb
#hide intr_disable
#hide intr_restore
#hide intr_enable
#hide struct_zero

#expand sys/inline.h

extern "C" {
	void flushtlb(void);
	int _cr0(void);
	int _cr2(void);
	int _cr3(void);
	void _wdr0(ulong);
	void _wdr1(ulong);
	void _wdr2(ulong);
	void _wdr3(ulong);
	void _wdr6(ulong);
	void _wdr7(ulong);
	int _dr0(void);
	int _dr1(void);
	int _dr2(void);
	int _dr3(void);
	int _dr6(void);
	int _dr7(void);
	void loadtr(ulong);
	void outl(unsigned, ulong);
	void outw(unsigned,ulong);
	void outb(unsigned,ulong);
	int inl(unsigned);
	int inw(unsigned);
	int inb(unsigned);
	void intr_disable();
	void intr_restore();
	void intr_enable();
	int struct_zero(caddr_t, int);
}

#endif
