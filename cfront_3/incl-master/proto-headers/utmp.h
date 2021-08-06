/*ident	"@(#)cls4:incl-master/proto-headers/utmp.h	1.1" */
#usedby sunos3 sunos4 sunos4.1 alliant hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts svr4 sgi-svr4 solaris

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
#ifndef __UTMP_H
#define __UTMP_H

#hide endutent
#hide getutent
#hide getutid
#hide getutline
#hide pututline
#hide setutent
#hide utmpname

#os svr4 sgi-svr4 solaris
struct exit_status {		/* in the SVR4 /usr/include/utmp.h,
				   this is nested within the definition
				   of struct utmp -- must declare it
				   outside for C++ 3.0 */
    short e_termination;
    short e_exit;
};
#endos

#expand utmp.h

extern "C" {
#os hpux2.0 hpux hpux8.0 svr2 svr3 sgi uts
	struct utmp *getutent();
	struct utmp *getutid(struct utmp *);
	struct utmp *getutline(struct utmp *);
	void pututline(struct utmp *);
	void utmpname(const char *);
	void setutent();
	void endutent();
#endos
#os svr4 sgi-svr4 solaris
	struct utmp *getutent(void);
	struct utmp *getutid(const struct utmp *);
	struct utmp *getutline(const struct utmp *);
	void pututline(const struct utmp *);
	int utmpname(const char *);
	void setutent(void);
	void endutent(void);
#endos
}

#endif
