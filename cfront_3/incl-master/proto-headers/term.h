/*ident	"@(#)cls4:incl-master/proto-headers/term.h	1.1" */
#usedby svr4 sgi-svr4 solaris

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
#ifndef __TERM_H
#define __TERM_H

#hide set_curterm
#hide del_curterm
#hide setcurterm
#hide tparm
#hide tgetstr
#hide tigetstr
#hide termname
#hide tgetent
#hide tgetflag
#hide tgetnum
#hide tputs
#hide putp
#hide vidputs
#hide vidattr
#hide resetterm
#hide fixterm
#hide saveterm
#hide restartterm
#hide delterm
#hide termerr
#hide tinputfd

#expand term.h

extern "C" {
	TERMINAL	*set_curterm(TERMINAL *);
	int             del_curterm(TERMINAL *);

	TERMINAL        *setcurterm(TERMINAL *);
	char    	*tparm(),
                	*tgetstr(char *, char **),
                	*tigetstr(char *),
                	*termname(void);
	int		tgetent(char *, char *),
			tgetflag(char *),
			tgetnum(char *),
                	tputs(char *, int, int (*)(char)),
			putp(char *),
                	vidputs(chtype, int (*)(char)),
			vidattr(chtype);

	int		resetterm(void),
			fixterm(void),
			saveterm(void),
                	restartterm(char *, int, int *),
			delterm(TERMINAL *);

	void		termerr(void),
			tinputfd(int);
}

#endif
