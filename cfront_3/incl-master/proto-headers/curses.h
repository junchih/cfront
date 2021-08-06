/*ident	"@(#)cls4:incl-master/proto-headers/curses.h	1.1" */
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
#usedby bsd2 bsd3 sunos3 sunos4 sunos4.1 alliant uts
#ifndef __CURSES_H
#define __CURSES_H


#os bsd2 bsd3 sunos3 sunos4 sunos4.1
#hide initscr
#endos
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 uts
#hide werase
#hide cuserid
#endos

#hide set_term
#hide keypad
#hide nodelay
#hide intrflush
#hide meta
#hide typeahead
#hide doupdate
#hide wnoutrefresh
#hide wclear
#hide wclrtobot
#hide wclrtoeol
#hide newpad
#hide idlok
#hide wattrset
#hide beep
#hide def_prog_mode
#hide def_shell_mode
#hide delay_output
#hide fixterm
#hide flash
#hide flushinp
#hide has_ic
#hide has_il
#hide m_addch
#hide m_addstr
#hide m_clear
#hide m_erase
#hide m_initscr
#hide m_move
#hide m_refresh
#hide mvprintw
#hide mvscanw
#hide mvwprintw
#hide mvwscanw
#hide pnoutrefresh
#hide prefresh
#hide putp
#hide reset_prog_mode
#hide reset_shell_mode
#hide resetterm
#hide saveterm
#hide setupterm
#hide tgetent
#hide tgetflag
#hide tgetnum
#hide tgetstr
#hide tgoto
#hide tparm
#hide tputs
#hide traceoff
#hide traceon
#hide vidattr
#hide vidputs
#hide wattroff
#hide wattron
#hide wrefresh
#hide endwin
#hide longname
#hide waddch
#hide waddstr
#hide box
#hide wdelch
#hide wdeleteln
#hide winsch
#hide winsertln
#hide wmove
#hide overlay
#hide overwrite
#hide printw
#hide wprintw
#hide wstandout
#hide wstandend
#hide wgetch
#hide wgetstr
#hide scanw
#hide wscanw
#hide delwin
#hide mvwin
#hide touchwin
#hide gettmode
#hide mvcur
#hide scroll
#hide setterm
#hide tstp
#hide newwin
#hide subwin

#expand curses.h

extern "C" {
	int set_term(WINDOW*);
	int keypad(WINDOW*, char);
	int nodelay(WINDOW*, char);
	int intrflush(WINDOW*, char);
	int meta(WINDOW*, char);
	int typeahead(int);
	int doupdate();
	int wnoutrefresh(WINDOW*);
	int wclear(WINDOW*);
	int wclrtobot(WINDOW*);
	int wclrtoeol(WINDOW*);
	WINDOW *newpad(int, int);
	void idlok(WINDOW*, char);
	void wattrset(WINDOW*, int);
	int beep();
	int def_prog_mode();
	int def_shell_mode();
	int delay_output(int);
	int fixterm();
	int flash();
	int flushinp();
	int has_ic();
	int has_il();
	int m_addch(char);
	int m_addstr(char *);
	int m_clear();
	int m_erase();
	WINDOW *m_initscr();
	int m_move(int, int);
	int m_refresh();
	int mvprintw(int, int, char* ...);
	int mvscanw(int, int, char* ...);
	int mvwprintw(WINDOW*, int, int, char* ...);
	int mvwscanw(WINDOW*, int, int, char* ...);
	int pnoutrefresh(WINDOW*, int, int, int, int, int, int);
	int prefresh(WINDOW*, int, int, int, int, int, int);
	int putp(char*);
	int reset_prog_mode();
	int reset_shell_mode();
	int resetterm();
	int saveterm();
	int setupterm(char*, int, int*);
	int tgetent(char*, const char*);
	int tgetflag(const char*);
	int tgetnum(const char*);
	char *tgetstr(const char*, char**);
	char *tgoto(const char*, int, int);
	char *tparm(char*, int ...);
	int tputs(const char*, int, int(*)(int));
	int traceoff();
	int traceon();
	int vidattr(int);
	int vidputs(int, int(*)(int));
	int wattroff(WINDOW*, int);
	int wattron(WINDOW*, int);
	void wrefresh(WINDOW*);
	void endwin();
	char *longname(char*, char*);
	int waddch(WINDOW*, char);
	int waddstr(WINDOW*, char*);
	int box(WINDOW*, char, char);
	int wdelch(WINDOW*);
	int wdeleteln(WINDOW*);
	int winsch(WINDOW*, char);
	int winsertln(WINDOW*);
	int wmove(WINDOW*, int, int);
	int overlay(WINDOW*, WINDOW*);
	int overwrite(WINDOW*, WINDOW*);
	int printw(char* ...);
	int wprintw(WINDOW*, char* ...);
	int wstandout(WINDOW*);
	int wstandend(WINDOW*);
	int wgetch(WINDOW*);
	int wgetstr(WINDOW*, char*);
	int scanw(char* ...);
	int wscanw(WINDOW*, char* ...);
	int delwin(WINDOW*);
	int mvwin(WINDOW*, int, int);
	int touchwin(WINDOW*);
	int gettmode();
	int mvcur(int, int, int, int);
	int scroll(WINDOW*);
	int setterm(char*);
	int tstp();
	WINDOW *newwin(int, int, int, int);
	WINDOW *subwin(WINDOW*, int, int, int, int);
#os bsd2 bsd3 sunos3 sunos4 sunos4.1
	WINDOW *initscr();
#endos
#os bsd2 bsd3 sunos3 sunos4 sunos4.1 uts
	int werase(WINDOW*);
	char *cuserid(char*);
#endos
}

#endif
