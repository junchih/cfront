/*ident	"@(#)cls4:incl-master/stddef2.c	1.1"*/
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

/* From the ANSI specs, Section 4.1.5:
*
*	ptrdiff_t ... is the signed integral type of the result of subtracting two pointers.
*	size_t    ... is the unsigned integral type of the result of the sizeof operator.
*/

#include <stdio.h>

static int do_ptrdiff = 0;
static int do_size = 0;

main(argc, argv)
int argc;
char **argv;
{
	int ptrdiff_size = sizeof((char*)0 - (char*)0);
	int short_size = sizeof(short);
	int int_size = sizeof(int);
	int long_size = sizeof(long);
	int sizeof_size = sizeof(sizeof(char));  /* the type there doesn't matter */
	int xit = 0;
	int errflg = 0;
	int c;
	while ((c=getopt(argc, argv, "ps")) != EOF)
	{
		switch (c)
		{
			case 'p':
				do_ptrdiff = 1;
				break;
			case 's':
				do_size = 1;
				break;
			case '?':
				errflg++;
				break;
		}
	}
	if (errflg)
	{
		fprintf(stderr, "usage: stddef2 [-ps]\n");
		exit(2);
	}

	if (do_ptrdiff)
	{
		if (ptrdiff_size == int_size)
			printf("typedef int ptrdiff_t;\n");
		else if (ptrdiff_size == short_size)
			printf("typedef short ptrdiff_t;\n");
		else if (ptrdiff_size == long_size)
			printf("typedef long ptrdiff_t;\n");
		else
		{
			fprintf(stderr, "Can't determine ptrdiff_t!\n");
			xit = 1;
		}
	}
	if (do_size)
	{
		if (sizeof_size == int_size)
			printf("typedef unsigned int size_t;\n");
		else if (sizeof_size == short_size)
			printf("typedef unsigned short size_t;\n");
		else if (sizeof_size == long_size)
			printf("typedef unsigned long size_t;\n");
		else
		{
			fprintf(stderr, "Can't determine size_t!\n");
			xit = 1;
		}
	}
	exit(xit);
}
