/*ident	"@(#)cls4:incl-master/proto-headers/menu.h	1.1" */
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

#ifndef __MENU_H
#define __MENU_H

#hide menu_items
#hide current_item
#hide new_item
#hide new_menu
#hide item_opts
#hide menu_opts
#hide item_init
#hide item_term
#hide menu_init
#hide menu_term
#hide menu_sub
#hide menu_win
#hide item_description
#hide item_name
#hide item_userptr
#hide menu_mark
#hide menu_pattern
#hide menu_userptr
#hide menu_back
#hide menu_fore
#hide menu_grey
#hide free_item
#hide free_menu
#hide item_count
#hide item_index
#hide item_opts_off
#hide item_opts_on
#hide item_value
#hide item_visible
#hide menu_driver
#hide menu_opts_off
#hide menu_opts_on
#hide menu_pad
#hide pos_menu_cursor
#hide post_menu
#hide scale_menu
#hide set_current_item
#hide set_item_init
#hide set_item_opts
#hide set_item_term
#hide set_item_userptr
#hide set_item_value
#hide set_menu_back
#hide set_menu_fore
#hide set_menu_format
#hide set_menu_grey
#hide set_menu_init
#hide set_menu_items
#hide set_menu_mark
#hide set_menu_opts
#hide set_menu_pad
#hide set_menu_pattern
#hide set_menu_sub
#hide set_menu_term
#hide set_menu_userptr
#hide set_menu_win
#hide set_top_row
#hide top_row
#hide unpost_menu
#hide menu_format

#expand menu.h

extern "C" {
	ITEM	**menu_items ( MENU * ),
		*current_item ( MENU * ),
		*new_item ( char *, char * );
	MENU	*new_menu ( ITEM ** );
	OPTIONS	item_opts ( ITEM * ),
		menu_opts ( MENU * );
	PTF_void	item_init ( MENU * ),
		item_term ( MENU * ),
		menu_init ( MENU * ),
		menu_term ( MENU * );
	WINDOW	*menu_sub ( MENU * ),
		*menu_win ( MENU * );
	char	*item_description ( ITEM * ),
		*item_name ( ITEM * ),
		*item_userptr ( ITEM * ),
		*menu_mark ( MENU * ),
		*menu_pattern ( MENU * ),
		*menu_userptr ( MENU * );
	chtype	menu_back ( MENU * ),
		menu_fore ( MENU * ),
		menu_grey ( MENU * );
	int	free_item ( ITEM * ),
		free_menu ( MENU * ),
		item_count ( MENU * ),
		item_index ( ITEM * ),
		item_opts_off ( ITEM *, OPTIONS ),
		item_opts_on ( ITEM *, OPTIONS ),
		item_value ( ITEM * ),
		item_visible ( ITEM * ),
		menu_driver ( MENU *, int ),
		menu_opts_off ( MENU *, OPTIONS ),
		menu_opts_on ( MENU *, OPTIONS ),
		menu_pad ( MENU * ),
		pos_menu_cursor ( MENU * ),
		post_menu ( MENU * ),
		scale_menu ( MENU *, int *, int * ),
		set_current_item ( MENU *, ITEM * ),
		set_item_init ( MENU *, PTF_void ),
		set_item_opts ( ITEM *, OPTIONS ),
		set_item_term ( MENU *, PTF_void ),
		set_item_userptr ( ITEM *, char * ),
		set_item_value ( ITEM *, int ),
		set_menu_back ( MENU *, chtype  ),
		set_menu_fore ( MENU *, chtype  ),
		set_menu_format ( MENU *, int, int ),
		set_menu_grey ( MENU *, chtype  ),
		set_menu_init ( MENU *, PTF_void ),
		set_menu_items ( MENU *, ITEM ** ),
		set_menu_mark ( MENU *, char * ),
		set_menu_opts ( MENU *, OPTIONS ),
		set_menu_pad ( MENU *, int ),
		set_menu_pattern ( MENU *, char * ),
		set_menu_sub ( MENU *, WINDOW * ),
		set_menu_term ( MENU *, PTF_void ),
		set_menu_userptr ( MENU *, char * ),
		set_menu_win ( MENU *, WINDOW * ),
		set_top_row ( MENU *, int ),
		top_row ( MENU * ),
		unpost_menu ( MENU * );
	void	menu_format ( MENU *, int *, int * );
}

#endif /* __MENU_H */
