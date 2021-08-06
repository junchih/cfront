/*ident	"@(#)cls4:incl-master/expand.c	1.1" */
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

/*************************************************************************
* This C program copies stdin to stdout, but replaces every occurrence of 
*
*		#expand filename
*
* with the actual contents of the standard C include file which goes by
* the name "filename".  The shell script stdcat assists in this job.
*
* This cannot be implemented in old awk, unfortunately.
**************************************************************************/

#include <stdio.h>
#include <ctype.h>

static int c;
#define ch()	(c = getchar())

static char cmd[300];
static int fromHere;

static int parse();
static int id();

main()
{
	strcpy(cmd, "stdcat ");
	fromHere = strlen(cmd);	
	parse();
}


static parse()
{
	ch();
	while (c != EOF)
		if (c == '#')
			if (ch() == 'e')
				if (ch() == 'x')
					if (ch() == 'p')
						if (ch() == 'a')
							if (ch() == 'n')
								if (ch() == 'd')
									if (ch(), isspace(c))	id();
									else			fputs("#expand", stdout);
								else	fputs("#expan", stdout);
							else	fputs("#expa", stdout);
						else	fputs("#exp", stdout);
					else	fputs("#ex", stdout);
				else	fputs("#e", stdout);
			else	fputs("#", stdout);
		else	{putchar(c); ch();}
}



static id()
{
	int i = fromHere;
	while (isspace(c)) ch();
	while (!isspace(c))
	{
		cmd[i++] = c;
		ch();
	}
	cmd[i] = NULL;
	fflush(stdout);
	system(cmd);
}	
