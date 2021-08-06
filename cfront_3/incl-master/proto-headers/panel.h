/*ident	"@(#)cls4:incl-master/proto-headers/panel.h	1.1" */
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
#ifndef __PANEL_H
#define __PANEL_H

#hide new_panel
#hide del_panel
#hide hide_panel
#hide show_panel
#hide move_panel
#hide replace_panel
#hide top_panel
#hide bottom_panel
#hide update_panels
#hide panel_window
#hide set_panel_userptr
#hide panel_userptr
#hide panel_above
#hide panel_below

#expand panel.h

extern "C" {
	PANEL *new_panel ( WINDOW * );
	int del_panel ( PANEL * );
	int hide_panel ( PANEL * );
	int show_panel ( PANEL * );
	int move_panel ( PANEL *, int, int );
	int replace_panel ( PANEL *, WINDOW * );
	int top_panel ( PANEL * );
	int bottom_panel ( PANEL * );
	void update_panels ( void );
	WINDOW *panel_window ( PANEL * );
	int set_panel_userptr ( PANEL *, char * );
	char *panel_userptr ( PANEL * );
	PANEL *panel_above ( PANEL * );
	PANEL *panel_below ( PANEL * );
}

#endif /* __PANEL_H */
