/*ident	"@(#)cls4:incl-master/proto-headers/form.h	1.1" */
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
#ifndef __FORM_H
#define __FORM_H

#include <curses.h>
#include <eti.h>

	/**************
	*  FIELDTYPE  *
	**************/

typedef struct typenode {

	int			status;		/* flags		*/
	int			ref;		/* reference count	*/
	struct typenode *	left;		/* ptr to operand for |	*/
	struct typenode *	right;		/* ptr to operand for |	*/
	PTF_charP		makearg;	/* make fieldtype arg	*/
	PTF_charP		copyarg;	/* copy fieldtype arg	*/
	PTF_void		freearg;	/* free fieldtype arg	*/
	PTF_int			fcheck;		/* field validation	*/
	PTF_int			ccheck;		/* character validation	*/
	PTF_int			next;		/* enumerate next value	*/
	PTF_int			prev;		/* enumerate prev value	*/
}
	FIELDTYPE;

	/**********
	*  _PAGE  *
	**********/

typedef struct {

	int			pmin;		/* first field on page	*/
	int			pmax;		/* last field on page	*/
	int			smin;		/* top leftmost field	*/
	int			smax;		/* bottom rightmost	*/
}
	_PAGE;

	/**********
	*  FIELD  *
	**********/

typedef struct fieldnode {

	int			status;		/* flags		*/
	int			rows;		/* size in rows		*/
	int			cols;		/* size in cols		*/
	int			frow;		/* first row		*/
	int			fcol;		/* first col		*/
	int			drows;		/* dynamic rows		*/
	int			dcols;		/* dynamic cols		*/
	int			maxgrow;	/* maximum field growth */
	int			nrow;		/* offscreen rows	*/
	int			nbuf;		/* additional buffers	*/
	int			just;		/* justification	*/
	int			page;		/* page on form		*/
	int			index;		/* into form -> field	*/
	int			pad;		/* pad character	*/
	chtype			fore;		/* foreground attribute	*/
	chtype			back;		/* background attribute	*/
	OPTIONS			opts;		/* options		*/
	struct fieldnode *	snext;		/* sorted order pointer	*/
	struct fieldnode *	sprev;		/* sorted order pointer	*/
	struct fieldnode *	link;		/* linked field chain	*/
	struct formnode *	form;		/* containing form	*/
	FIELDTYPE *		type;		/* field type		*/
	char *			arg;		/* argument for type	*/
	char *			buf;		/* field buffers	*/
	char *			usrptr;		/* user pointer		*/
}
	FIELD;

	/*********
	*  FORM  *
	*********/

typedef struct formnode {

	int			status;		/* flags		*/
	int			rows;		/* size in rows		*/
	int			cols;		/* size in cols		*/
	int			currow;		/* current row		*/
	int			curcol;		/* current col		*/
	int			toprow;		/* in vertically scrollable field	*/
	int			begincol;	/* in horizontally scrollable field	*/
	int			maxfield;	/* number of fields	*/
	int			maxpage;	/* number of pages	*/
	int			curpage;	/* index into page	*/
	OPTIONS			opts;		/* options		*/
	WINDOW *		win;		/* window		*/
	WINDOW *		sub;		/* subwindow		*/
	WINDOW *		w;		/* window		*/
	FIELD **		field;		/* field [maxfield]	*/
	FIELD *			current;	/* current field	*/
	_PAGE *			page;		/* page [maxpage]	*/
	char *			usrptr;		/* user pointer		*/
	PTF_void		forminit;	/* user function	*/
	PTF_void		formterm;	/* user function	*/
	PTF_void		fieldinit;	/* user function	*/
	PTF_void		fieldterm;	/* user function	*/
}
	FORM;

	/***************************
	*  miscellaneous #defines  *
	***************************/
/*
	field justification
*/
#define NO_JUSTIFICATION	0
#define JUSTIFY_LEFT		1
#define JUSTIFY_CENTER		2
#define JUSTIFY_RIGHT		3
/*
	field options
*/
#define O_VISIBLE		0x0001
#define O_ACTIVE		0x0002
#define O_PUBLIC		0x0004
#define O_EDIT			0x0008
#define O_WRAP			0x0010
#define O_BLANK			0x0020
#define O_AUTOSKIP		0x0040
#define O_NULLOK		0x0080
#define O_PASSOK		0x0100
#define O_STATIC		0x0200
/*
	form options
*/
#define O_NL_OVERLOAD		0x0001
#define O_BS_OVERLOAD		0x0002
/*
	form driver commands
*/
#define REQ_NEXT_PAGE		(KEY_MAX + 1)	/* move to next page		*/
#define REQ_PREV_PAGE		(KEY_MAX + 2)	/* move to previous page	*/
#define REQ_FIRST_PAGE		(KEY_MAX + 3)	/* move to first page		*/
#define REQ_LAST_PAGE		(KEY_MAX + 4)	/* move to last page		*/

#define REQ_NEXT_FIELD		(KEY_MAX + 5)	/* move to next field		*/
#define REQ_PREV_FIELD		(KEY_MAX + 6)	/* move to previous field	*/
#define REQ_FIRST_FIELD		(KEY_MAX + 7)	/* move to first field		*/
#define REQ_LAST_FIELD		(KEY_MAX + 8)	/* move to last field		*/
#define REQ_SNEXT_FIELD		(KEY_MAX + 9)	/* move to sorted next field	*/
#define REQ_SPREV_FIELD		(KEY_MAX + 10)	/* move to sorted prev field	*/
#define REQ_SFIRST_FIELD	(KEY_MAX + 11)	/* move to sorted first field	*/
#define REQ_SLAST_FIELD		(KEY_MAX + 12)	/* move to sorted last field	*/
#define REQ_LEFT_FIELD		(KEY_MAX + 13)	/* move to left to field	*/
#define REQ_RIGHT_FIELD		(KEY_MAX + 14)	/* move to right to field	*/
#define REQ_UP_FIELD		(KEY_MAX + 15)	/* move to up to field		*/
#define REQ_DOWN_FIELD		(KEY_MAX + 16)	/* move to down to field	*/

#define REQ_NEXT_CHAR		(KEY_MAX + 17)	/* move to next char in field	*/
#define REQ_PREV_CHAR		(KEY_MAX + 18)	/* move to prev char in field	*/
#define REQ_NEXT_LINE		(KEY_MAX + 19)	/* move to next line in field	*/
#define REQ_PREV_LINE		(KEY_MAX + 20)	/* move to prev line in field	*/
#define REQ_NEXT_WORD		(KEY_MAX + 21)	/* move to next word in field	*/
#define REQ_PREV_WORD		(KEY_MAX + 22)	/* move to prev word in field	*/
#define REQ_BEG_FIELD		(KEY_MAX + 23)	/* move to first char in field	*/
#define REQ_END_FIELD		(KEY_MAX + 24)	/* move after last char in fld	*/
#define REQ_BEG_LINE		(KEY_MAX + 25)	/* move to beginning of line	*/
#define REQ_END_LINE		(KEY_MAX + 26)	/* move after last char in line	*/
#define REQ_LEFT_CHAR		(KEY_MAX + 27)	/* move left in field		*/
#define REQ_RIGHT_CHAR		(KEY_MAX + 28)	/* move right in field		*/
#define REQ_UP_CHAR		(KEY_MAX + 29)	/* move up in field		*/
#define REQ_DOWN_CHAR		(KEY_MAX + 30)	/* move down in field		*/

#define REQ_NEW_LINE		(KEY_MAX + 31)	/* insert/overlay new line	*/
#define REQ_INS_CHAR		(KEY_MAX + 32)	/* insert blank char at cursor	*/
#define REQ_INS_LINE		(KEY_MAX + 33)	/* insert blank line at cursor	*/
#define REQ_DEL_CHAR		(KEY_MAX + 34)	/* delete char at cursor	*/
#define REQ_DEL_PREV		(KEY_MAX + 35)	/* delete char before cursor	*/
#define REQ_DEL_LINE		(KEY_MAX + 36)	/* delete line at cursor	*/
#define REQ_DEL_WORD		(KEY_MAX + 37)	/* delete line at cursor	*/
#define REQ_CLR_EOL		(KEY_MAX + 38)	/* clear to end of line		*/
#define REQ_CLR_EOF		(KEY_MAX + 39)	/* clear to end of field	*/
#define REQ_CLR_FIELD		(KEY_MAX + 40)	/* clear entire field		*/
#define REQ_OVL_MODE		(KEY_MAX + 41)	/* begin overlay mode		*/
#define REQ_INS_MODE		(KEY_MAX + 42)	/* begin insert mode		*/

#define REQ_SCR_FLINE		(KEY_MAX + 43)	/* scroll field forward a line	*/
#define REQ_SCR_BLINE		(KEY_MAX + 44)	/* scroll field backward a line	*/
#define REQ_SCR_FPAGE		(KEY_MAX + 45)	/* scroll field forward a page	*/
#define REQ_SCR_BPAGE		(KEY_MAX + 46)	/* scroll field backward a page	*/
#define REQ_SCR_FHPAGE		(KEY_MAX + 47)	/* scroll field forward half page */
#define REQ_SCR_BHPAGE		(KEY_MAX + 48)	/* scroll field backward half page */

#define	REQ_SCR_FCHAR		(KEY_MAX + 49)	/* horizontal scroll char */
#define	REQ_SCR_BCHAR		(KEY_MAX + 50)	/* horizontal scroll char */
#define	REQ_SCR_HFLINE		(KEY_MAX + 51)	/* horizontal scroll line */
#define	REQ_SCR_HBLINE		(KEY_MAX + 52)	/* horizontal scroll line */
#define	REQ_SCR_HFHALF		(KEY_MAX + 53)	/* horizontal scroll half line */
#define	REQ_SCR_HBHALF		(KEY_MAX + 54)	/* horizontal scroll half line */

#define REQ_VALIDATION		(KEY_MAX + 55)	/* validate field		*/
#define REQ_NEXT_CHOICE		(KEY_MAX + 56)	/* display next field choice	*/
#define REQ_PREV_CHOICE		(KEY_MAX + 57)	/* display prev field choice	*/

#define MIN_FORM_COMMAND	(KEY_MAX + 1)	/* used by form_driver		*/
#define MAX_FORM_COMMAND	(KEY_MAX + 57)	/* used by form_driver		*/

	/*************************
	*  standard field types  *
	*************************/

extern FIELDTYPE *	TYPE_ALPHA;
extern FIELDTYPE *	TYPE_ALNUM;
extern FIELDTYPE *	TYPE_ENUM;
extern FIELDTYPE *	TYPE_INTEGER;
extern FIELDTYPE *	TYPE_NUMERIC;
extern FIELDTYPE *	TYPE_REGEXP;

	/********************
	*  default objects  *
	********************/

extern FORM *		_DEFAULT_FORM;
extern FIELD *		_DEFAULT_FIELD;

extern "C" {

	/***********************
	*  FIELDTYPE routines  *
	***********************/

	FIELDTYPE *	new_fieldtype ( PTF_int, PTF_int );
	FIELDTYPE *	link_fieldtype ( FIELDTYPE *, FIELDTYPE * );
	int		free_fieldtype ( FIELDTYPE * );
	int		set_fieldtype_arg ( FIELDTYPE *, PTF_charP,
					    PTF_charP, PTF_void );
	int		set_fieldtype_choice ( FIELDTYPE *, PTF_int, PTF_int );

	/*******************
	*  FIELD routines  *
	*******************/

	FIELD *		new_field ( int, int, int, int, int, int );
	FIELD *		dup_field ( FIELD *, int, int );
	FIELD *		link_field ( FIELD *, int, int );
	int		free_field ( FIELD * );
	int		field_info ( FIELD *, int *, int *,
				     int *,int *, int *, int * );
	int		dynamic_field_info ( FIELD *, int *, int *, int * );
	int		set_max_field ( FIELD *, int );
	int		move_field ( FIELD *, int, int );
	int		set_field_type ( FIELD *, FIELDTYPE *, ... );
	FIELDTYPE *	field_type ( FIELD * );
	char *		field_arg ( FIELD * );
	int		set_new_page ( FIELD *, int );
	int		new_page ( FIELD * );
	int		set_field_just ( FIELD *, int );
	int		field_just ( FIELD * );
	int		set_field_fore ( FIELD *, chtype );
	chtype		field_fore ( FIELD * );
	int		set_field_back ( FIELD *, chtype );
	chtype		field_back ( FIELD * );
	int		set_field_pad ( FIELD *, int );
	int		field_pad ( FIELD * );
	int		set_field_buffer ( FIELD *, int, char * );
	char *		field_buffer ( FIELD *, int );
	int		set_field_status ( FIELD *, int );
	int		field_status ( FIELD * );
	int		set_field_userptr ( FIELD *, char * );
	char *		field_userptr ( FIELD * );
	int		set_field_opts ( FIELD *, OPTIONS );
	OPTIONS		field_opts ( FIELD * );
	int		field_opts_on ( FIELD *, OPTIONS );
	int		field_opts_off ( FIELD *, OPTIONS );
	int		field_index ( FIELD * );

	/******************
	*  FORM routines  *
	******************/

	FORM *		new_form ( FIELD ** );
	int		free_form ( FORM * );
	int		set_form_fields ( FORM *, FIELD ** );
	FIELD **	form_fields ( FORM * );
	int		field_count ( FORM * );
	int		set_form_win ( FORM *, WINDOW * );
	WINDOW *	form_win ( FORM * );
	int		set_form_sub ( FORM *, WINDOW * );
	WINDOW *	form_sub ( FORM * );
	int		set_current_field ( FORM *, FIELD * );
	FIELD *		current_field ( FORM * );
	int		set_form_page ( FORM *, int );
	int		form_page ( FORM * );
	int		scale_form ( FORM *, int *, int * );
	int		set_form_init ( FORM *, PTF_void );
	PTF_void	form_init ( FORM * );
	int		set_form_term ( FORM *, PTF_void );
	PTF_void	form_term ( FORM * );
	int		set_field_init ( FORM *, PTF_void );
	PTF_void	field_init ( FORM * );
	int		set_field_term ( FORM *, PTF_void );
	PTF_void	field_term ( FORM * );
	int		post_form ( FORM * );
	int		unpost_form ( FORM * );
	int		pos_form_cursor ( FORM * );
	int		form_driver ( FORM *, int );
	int		set_form_userptr ( FORM *, char * );
	char *		form_userptr ( FORM * );
	int		set_form_opts ( FORM *, OPTIONS );
	OPTIONS		form_opts ( FORM * );
	int		form_opts_on ( FORM * , OPTIONS );
	int		form_opts_off ( FORM * , OPTIONS );
	int		data_ahead ( FORM * );
	int		data_behind ( FORM * );
}

#endif	/* __FORM_H */
